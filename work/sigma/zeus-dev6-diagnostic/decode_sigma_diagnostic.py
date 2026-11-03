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
discovery = Counter()
heartbeats = Counter()
accepted_counts = Counter()
ignored_counts = Counter()
versions = Counter()
matched = 0
for row in capture.get('frames', []):
    data = bytes.fromhex(row['Hex'])
    if len(data) != 64 or data[0] != 1 or data[56] != 0x5a or data[57] & 0xf0 not in (0x50, 0x60):
        continue
    matched += 1
    heartbeats[data[57] & 15] += 1
    version = data[57] >> 4
    versions[version] += 1
    if version == 6 and data[57] & 1:
        discovery[tuple(data[58:64])] += 1
    else:
        statuses[(version,) + tuple(data[58:63] if version == 5 else data[58:62])] += 1
        accepted_counts[data[63] if version == 5 else data[62]] += 1
        if version == 6:
            ignored_counts[data[63]] += 1
summary = dict(captured_frames=len(capture.get('frames', [])), diagnostic_frames=matched,
               observed_versions=sorted(versions),
               observed_heartbeats=sorted(heartbeats), observed_accepted_counts=sorted(accepted_counts),
               observed_ignored_counts=sorted(ignored_counts),
               interpretation='Diagnostic marker observed' if matched else
               'No diagnostic marker observed; an empty input capture does not establish the installed firmware',
               statuses=[dict(version=key[0], usb_address=key[1], polling_enabled=key[2],
                              last_init_return=f'0x{key[3]:02x}', last_input_length=key[4],
                              last_report_id=f'0x{key[5]:02x}' if key[0] == 5 else None,
                              observations=count) for key, count in statuses.items()],
               discovery=[dict(last_successful_descriptor_identity=f'{key[0] | key[1] << 8:04x}:{key[2] | key[3] << 8:04x}',
                               last_descriptor_return=f'0x{key[4]:02x}',
                               expected_registry_slot_matches=bool(key[5] & 1),
                               vtable_pointer_matches=bool(key[5] & 2), observations=count)
                          for key, count in discovery.items()],
               limitations='Descriptor identity is the last successful full read and may precede the last descriptor-return status')
print(json.dumps(summary, indent=2))
