#!/usr/bin/env python3
"""Read selected USB registry metadata for Sigma/Simagic only; no USB requests.

Serial numbers and unrelated-device properties are not written to the output.
This is registry metadata, not a complete raw configuration-descriptor capture.
"""
import argparse,datetime,json,plistlib,subprocess
from pathlib import Path

KEYS=('USB Product Name','USB Vendor Name','idVendor','idProduct','bcdDevice',
      'bDeviceClass','bDeviceSubClass','bDeviceProtocol','bNumConfigurations',
      'bMaxPacketSize0','USBSpeed','locationID','kUSBCurrentConfiguration',
      'bConfigurationValue','bNumInterfaces','bInterfaceNumber','bAlternateSetting',
      'bInterfaceClass','bInterfaceSubClass','bInterfaceProtocol','bNumEndpoints',
      'bEndpointAddress','bmAttributes','wMaxPacketSize','bInterval')
def view(node):
    row={k:node[k] for k in KEYS if k in node and isinstance(node[k],(str,int,bool))}
    row['registry_class']=node.get('IOObjectClass')
    children=[view(x) for x in node.get('IORegistryEntryChildren',[]) if isinstance(x,dict)]
    children=[x for x in children if len(x)>1 or x.get('children')]
    if children:row['children']=children
    return row
def main():
    ap=argparse.ArgumentParser();ap.add_argument('output',type=Path);a=ap.parse_args()
    if a.output.exists():raise SystemExit('Output exists; use a new filename')
    raw=subprocess.run(['/usr/sbin/ioreg','-a','-r','-c','IOUSBHostDevice'],capture_output=True,check=True).stdout
    nodes=plistlib.loads(raw);result=[];seen=set()
    def walk(node):
        if isinstance(node,list):
            for child in node:walk(child)
        elif isinstance(node,dict):
            vid=node.get('idVendor');pid=node.get('idProduct');key=node.get('IORegistryEntryID')
            if (vid in (0x3670,0x0483,0x0eb7) or (vid==0x046d and pid==0xc260)) and key not in seen:
                seen.add(key);result.append(view(node))
            walk(node.get('IORegistryEntryChildren',[]))
    walk(nodes)
    report={'observed_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
            'operation':'IORegistry read only; no device opened or USB request issued',
            'devices':result,'limits':'Selected registry properties only; not a complete raw descriptor/traffic capture. Serial numbers omitted.'}
    a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({'matching_devices':len(result),'output':str(a.output)}))
if __name__=='__main__':main()
