#!/usr/bin/env python3
"""Summarize a completed read-only Zeus JSONL recording without device access.

Refuses a capture without a final end record. Timing is host callback timing,
not USB bus timing. Physical labels and transport-mode conclusions are not inferred.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import statistics

from zeus_report_decode import decode

ROOT = Path(__file__).resolve().parents[1]

def sha(data): return hashlib.sha256(data).hexdigest()

def display_path(path):
    try: return str(path.resolve().relative_to(ROOT))
    except ValueError: return str(path.resolve())

def timing(times):
    deltas = [b-a for a,b in zip(times,times[1:])]
    return {'samples':len(times),'first_elapsed_ns':times[0] if times else None,
            'last_elapsed_ns':times[-1] if times else None,
            'interval_count':len(deltas),
            'interval_ns_min':min(deltas) if deltas else None,
            'interval_ns_median':statistics.median(deltas) if deltas else None,
            'interval_ns_max':max(deltas) if deltas else None,
            'interpretation':'Host callback arrival intervals; not measured USB transactions.'}

def descriptor_comparison(hid_path, static_path):
    raw = hid_path.read_bytes(); observation=json.loads(raw)
    static=static_path.read_bytes(); matches=[]
    for device in observation['devices']:
        if (device.get('VendorID'),device.get('ProductID')) != (0x3670,0x0804): continue
        live=bytes.fromhex(device.get('report_descriptor_hex',''))
        digest=sha(live)
        declared=device.get('report_descriptor_sha256')
        if declared and declared != digest: raise ValueError('Live descriptor hash mismatch')
        matches.append({'vid':0x3670,'pid':0x0804,'transport':device.get('Transport'),
                        'product':device.get('Product'),'bcd_device':device.get('VersionNumber'),
                        'bcd_device_hex':f"0x{device.get('VersionNumber',0):04X}",
                        'descriptor_size':len(live),'descriptor_sha256':digest,
                        'equals_static_descriptor':live==static})
    return {'observation':display_path(hid_path),'observation_sha256':sha(raw),
            'observed_utc':observation.get('observed_utc'),
            'static_descriptor':display_path(static_path),'static_descriptor_sha256':sha(static),
            'devices':matches,
            'limit':'Descriptor observation and input recording are separate artifacts; no hardware serial identity is inferred.'}

def analyze(capture, hid_path, static_path):
    before=capture.stat(); raw=capture.read_bytes(); after=capture.stat()
    if (before.st_size,before.st_mtime_ns)!=(after.st_size,after.st_mtime_ns):
        raise ValueError('Capture changed during read')
    lines=raw.splitlines(keepends=True)
    if not lines or not lines[-1].endswith(b'\n'):
        raise ValueError('Capture is incomplete: missing completed final line')
    final=json.loads(lines[-1])
    if final.get('event')!='end': raise ValueError('Capture is incomplete: no final end record')
    start=json.loads(lines[0])
    if start.get('event')!='start': raise ValueError('Missing start record')
    if (start.get('vid'),start.get('pid'))!=(0x3670,0x0804): raise ValueError('Unexpected device identity')

    counts=Counter(); results=Counter(); times=defaultdict(list); variants=defaultdict(Counter)
    report1=[]; failures=[]; offset=len(lines[0]); prior_time=-1
    for number,line in enumerate(lines[1:-1],2):
        row=json.loads(line)
        if 'event' in row: raise ValueError(f'Unexpected event inside capture at line {number}')
        value=bytes.fromhex(row['hex']); elapsed=row['elapsed_ns']
        if elapsed<prior_time: raise ValueError('Callback times are not monotonic')
        prior_time=elapsed
        if len(value)!=row['length']: raise ValueError(f'Length mismatch at line {number}')
        key=f"id_0x{row['report_id']:02X}_length_{row['length']}_type_{row['type']}"
        counts[key]+=1;results[str(row['result'])]+=1;times[key].append(elapsed);variants[key][row['hex']]+=1
        if row['report_id']==1:
            if row['result']!=0 or row['type']!=0:
                failures.append({'line':number,'file_offset':offset,'reason':'Non-success or non-input callback'})
            else:
                try: decoded=decode(value)
                except ValueError as error:
                    failures.append({'line':number,'file_offset':offset,'reason':str(error)})
                else:
                    report1.append({'line':number,'file_offset':offset,'elapsed_ns':elapsed,
                                    'hex':row['hex'],'control_key':value[1:18].hex(),'decoded':decoded})
        offset+=len(line)
    total=sum(counts.values())
    if final.get('reports')!=total: raise ValueError('End-record count differs from parsed callback count')

    runs=[];changes=[];seen_usages=set();axes={name:[] for name in ('rx','ry')}
    control_variants=Counter();vendor_variants=Counter()
    for item in report1:
        decoded=item['decoded'];control_variants[item['control_key']]+=1
        vendor_variants[decoded['vendor_bits_hex']+f"{decoded['vendor_byte']:02x}"]+=1
        seen_usages.update(decoded['pressed_button_usages'])
        for name in axes: axes[name].append(decoded[name])
        state={'rx':decoded['rx'],'ry':decoded['ry'],
               'pressed_button_usages':decoded['pressed_button_usages']}
        if runs and runs[-1]['control_key']==item['control_key']:
            runs[-1]['last_elapsed_ns']=item['elapsed_ns'];runs[-1]['reports']+=1
            runs[-1]['last_line']=item['line']
        else:
            if runs:
                runs[-1]['next_change_elapsed_ns']=item['elapsed_ns']
                changes.append({'elapsed_ns':item['elapsed_ns'],'line':item['line'],
                                'file_offset':item['file_offset'],'state':state})
            runs.append({'first_elapsed_ns':item['elapsed_ns'],'last_elapsed_ns':item['elapsed_ns'],
                         'first_line':item['line'],'last_line':item['line'],'first_file_offset':item['file_offset'],
                         'reports':1,'control_key':item['control_key'],'state':state,
                         'zero_axes_and_no_pressed_usages':not(state['rx'] or state['ry'] or state['pressed_button_usages'])})
    baseline=runs[0]['control_key'] if runs else None
    nonbaseline=[run for run in runs if run['control_key']!=baseline]
    result={'capture':display_path(capture),'capture_sha256':sha(raw),'size':len(raw),'complete':True,
            'start':start,'end':final,'callback_count':total,'callback_result_counts':dict(results),
            'report_groups':[{ 'group':key,'count':counts[key],'timing':timing(times[key]),
                              'unique_raw_reports':len(variants[key]),
                              'variants':[{'hex':value,'count':count} for value,count in variants[key].most_common()]}
                             for key in sorted(counts)],
            'descriptors':descriptor_comparison(hid_path,static_path),
            'report_1':{'valid_reports':len(report1),'invalid_reports':failures,
                        'axis_ranges':{key:{'min':min(values) if values else None,'max':max(values) if values else None} for key,values in axes.items()},
                        'observed_pressed_usages':sorted(seen_usages),'unique_control_states':len(control_variants),
                        'unique_vendor_tails':[{'hex':value,'count':count} for value,count in vendor_variants.most_common()],
                        'initial_control_state':runs[0]['state'] if runs else None,
                        'control_changes':changes,'nonbaseline_segments':nonbaseline,
                        'zero_control_reports':sum(run['reports'] for run in runs if run['zero_axes_and_no_pressed_usages'])},
            'limits':['No device commands are sent by this analysis.',
                      'Initial control state is a numerical baseline, not confirmed physical idle.',
                      'No control changes cannot distinguish inactivity from alternate routing without confirmed user actions.',
                      'Report 0x02 and other vendor payloads are inventoried as opaque bytes; no version/status fields are asserted.',
                      'Callback intervals include operating-system and KVM scheduling effects.']}
    return result

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capture',type=Path)
    parser.add_argument('--output',type=Path)
    parser.add_argument('--hid-observation',type=Path,default=ROOT/'reports/zeus-live-hid-kvm.json')
    parser.add_argument('--static-descriptor',type=Path,default=ROOT/'work/simagic/zeus-hid_report.bin')
    args=parser.parse_args()
    try: result=analyze(args.capture,args.hid_observation,args.static_descriptor)
    except (ValueError,KeyError,OSError) as error: parser.exit(2,f'{error}\n')
    output=args.output or args.capture.with_suffix('.analysis.json')
    text=json.dumps(result,indent=2)+'\n'
    if output.exists() and output.read_text()!=text: parser.exit(2,'Output differs; choose a new output filename\n')
    output.write_text(text)
    print(json.dumps({'output':display_path(output),'capture_sha256':result['capture_sha256'],
                      'callbacks':result['callback_count'],'report1':result['report_1']['valid_reports'],
                      'control_states':result['report_1']['unique_control_states'],
                      'control_changes':len(result['report_1']['control_changes']),
                      'pressed_usages':result['report_1']['observed_pressed_usages']}))

if __name__=='__main__':main()
