#!/usr/bin/env python3
"""Read macOS IORegistry metadata only; no USB writes or firmware commands."""
import argparse, datetime, hashlib, json, plistlib, subprocess
from pathlib import Path

def main():
    ap=argparse.ArgumentParser();ap.add_argument('output',type=Path);a=ap.parse_args()
    raw=subprocess.run(['/usr/sbin/ioreg','-a','-r','-c','IOHIDDevice'],capture_output=True,check=True).stdout
    tree=plistlib.loads(raw);devices=[]
    def walk(node):
        if isinstance(node,list):
            for x in node:walk(x)
        elif isinstance(node,dict):
            vid=node.get('VendorID');pid=node.get('ProductID')
            if vid in (0x3670,0x0483,0x0eb7) or (vid==0x046d and pid==0xc260):
                row={k:node.get(k) for k in ['Product','Manufacturer','Transport','VendorID','ProductID','VersionNumber','PrimaryUsagePage','PrimaryUsage','MaxInputReportSize','MaxOutputReportSize','MaxFeatureReportSize']}
                desc=node.get('ReportDescriptor')
                if isinstance(desc,bytes):row.update(report_descriptor_hex=desc.hex(),report_descriptor_sha256=hashlib.sha256(desc).hexdigest())
                devices.append(row)
            for key,value in node.items():
                if key=='IORegistryEntryChildren':walk(value)
    walk(tree)
    report={'observed_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'operation':'IORegistry read only; no HID device opened',
            'devices':devices,'limitations':'Only presently enumerated matching IOHIDDevice objects; no USB traffic or input events recorded. Serial numbers omitted.'}
    if a.output.exists():raise SystemExit('Output already exists; choose a new capture filename')
    a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({'matching_devices':len(devices),'output':str(a.output)}))

if __name__=='__main__':main()
