#!/usr/bin/env python3
"""Offline decoder for Zeus Formula HID report 1, as declared by A1.1.15.

No device I/O. Physical button/encoder/paddle names require capture correlation.
Input includes the report ID; endpoint padding is not silently accepted.
"""
import argparse, json

def decode(data):
    if len(data)!=23:
        raise ValueError(f'Expected exactly 23 bytes including Report ID, got {len(data)}')
    if data[0]!=1:
        raise ValueError('Expected input report ID 0x01')
    buttons=int.from_bytes(data[3:18],'little')
    return {'report_id':1,'rx':data[1],'ry':data[2],
            'pressed_button_usages':[i+1 for i in range(120) if buttons>>i&1],
            'vendor_bits_hex':data[18:22].hex(),'vendor_byte':data[22],
            'physical_mapping':'unresolved; HID usage numbers only'}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('hex_report',help='23 bytes in hex, including leading 01')
    a=ap.parse_args()
    print(json.dumps(decode(bytes.fromhex(a.hex_report)),indent=2))

if __name__=='__main__':main()
