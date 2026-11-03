"""Decode saved Windows input captures; no hardware access or writes."""
import argparse
from collections import Counter
import json
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('capture', type=Path)
args = parser.parse_args()
capture = json.loads(args.capture.read_bytes())
statuses = Counter()
matched = 0
for row in capture.get('frames', []):
    data = bytes.fromhex(row['Hex'])
    if len(data) != 64 or data[0] != 1 or data[56] != 0x5a or data[57] & 0xf0 != 0x50:
        continue
    matched += 1
    statuses[tuple(data[58:63])] += 1
summary = dict(captured_frames=len(capture.get('frames', [])), diagnostic_frames=matched,
               interpretation='Diagnostic marker observed' if matched else
               'No diagnostic marker observed; an empty input capture does not establish the installed firmware',
               statuses=[dict(usb_address=key[0], polling_enabled=key[1],
                              last_init_return=f'0x{key[2]:02x}',
                              last_input_length=key[3], last_report_id=f'0x{key[4]:02x}',
                              observations=count) for key, count in statuses.items()])
print(json.dumps(summary, indent=2))
