#!/usr/bin/env python3
"""Verify retained Bootload/normal observations offline; no hardware I/O."""
import hashlib
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
AUDIT = ROOT / 'work/sigma/recovery-audit-2026-11-02'
PINS = {
    'bootload-hid-001.json': '74b62b8a1c2a8eefecffccad68e54b64e004f9fa8957c1ea8e535735bd59a838',
    'bootload-usb-001.json': '98891519b32395e37bb4a033eec16d0204cbbb7685e0ca9e8d0aa6b3b57fe7b9',
    'bootload-status-001.json': '95766cf412d420c58b647feb7fda2dcfc32b17cee1940707ed40f615bff97a0f',
    'normal-after-bootload-hid-001.json': '889d5e0a370d5ec43852733ed283684b010ba0397ef9395f54e88dda2b3093f7',
    'normal-after-bootload-usb-001.json': '562e131b1fa02112bfca2332319cb4c1fcd5428bd904bbf5eb5d2875f5025dce',
}


def identity(path):
    b = path.read_bytes()
    return {'path': str(path.relative_to(ROOT)), 'size': len(b),
            'sha256': hashlib.sha256(b).hexdigest()}


def select(rows, vid, pid, usb=False):
    keys = ('idVendor', 'idProduct') if usb else ('VendorID', 'ProductID')
    found = [d for d in rows if d.get(keys[0]) == vid and d.get(keys[1]) == pid]
    assert len(found) == 1
    return found[0]


def main():
    inputs = {}
    sources = []
    for name, expected in PINS.items():
        p = AUDIT / name
        info = identity(p)
        assert info['sha256'] == expected, name
        sources.append(info)
        inputs[name] = json.loads(p.read_text())
    boot = select(inputs['bootload-hid-001.json']['devices'], 0x046d, 0xc260)
    normal = select(inputs['normal-after-bootload-hid-001.json']['devices'], 0x0eb7, 0x0e07)
    boot_usb = select(inputs['bootload-usb-001.json']['devices'], 0x046d, 0xc260, True)
    normal_usb = select(inputs['normal-after-bootload-usb-001.json']['devices'], 0x0eb7, 0x0e07, True)
    assert boot_usb['locationID'] == normal_usb['locationID']
    assert boot['report_descriptor_sha256'] == '8783c2c016de8d3c57d6e18bc21c2df0d6fa47b60da827dfa02e2658a2e3fc0e'
    assert normal['report_descriptor_sha256'] == '9c099ea4b1d5400969a3363d781f1b354efd25e2d382b81b56cf31c81b01cdee'
    descriptor = bytes.fromhex(boot['report_descriptor_hex'])
    assert hashlib.sha256(descriptor).hexdigest() == boot['report_descriptor_sha256']
    # This observed descriptor contains short items only and no global PUSH/POP.
    pos = size = count = report_id = 0
    items = []
    while pos < len(descriptor):
        offset = pos
        prefix = descriptor[pos]
        pos += 1
        assert prefix != 0xfe
        length = (0, 1, 2, 4)[prefix & 3]
        assert pos + length <= len(descriptor)
        value = int.from_bytes(descriptor[pos:pos + length], 'little')
        pos += length
        item_type, tag = (prefix >> 2) & 3, prefix >> 4
        if item_type == 1:
            assert tag not in (10, 11)
            if tag == 7: size = value
            elif tag == 8: report_id = value
            elif tag == 9: count = value
        elif item_type == 0 and tag in (8, 9, 11):
            items.append({'descriptor_offset': hex(offset),
                          'type': {8: 'Input', 9: 'Output', 11: 'Feature'}[tag],
                          'report_id': hex(report_id), 'size_bits': size,
                          'count': count, 'total_bits': size * count})
    status = inputs['bootload-status-001.json']
    assert status['get_feature_calls'] == 1 and status['set_or_output_report_calls'] == 0
    assert status['get_result'] == '0x00000000' and status['error'] is None
    response = bytes.fromhex(status['response_hex'])
    assert len(response) == status['reported_length'] == 16
    image = ROOT / 'work/sigma/1.1.5/sigma-decoded.bin'
    assert identity(image)['sha256'] == '03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622'
    result = {
        'status': 'BUTTON_BOOTLOAD_ENTRY_AND_NORMAL_RETURN_OBSERVED',
        'sources': sources,
        'user_observations': [
            'User reports Bootload mode after the OK-button power-on sequence, connected through KVM.',
            'User reports normal screen after disconnecting/reconnecting without pressing a button.'
        ],
        'boot_hid': boot, 'normal_hid': normal,
        'same_usb_location_id': boot_usb['locationID'],
        'boot_report_items': items,
        'status_response': {'hex': response.hex(), 'size': len(response),
                            'sha256': hashlib.sha256(response).hexdigest(),
                            'u32_le_by_byte_offset': {str(i): hex(struct.unpack_from('<I', response, i)[0]) for i in range(0, 16, 4)},
                            'leading_report_id_present': response[0] == 0xf1,
                            'interpretation': 'Status response, not a flash dump. No F1 prefix was returned; byte 8 equals 0x00010001. The stock updater version arithmetic yields 1.0.1 with no BL high-byte flag, but platform framing and full field semantics are not verified.'},
        'application_source': identity(image),
        'exact_boot_descriptor_occurrences_in_stock_app': image.read_bytes().count(descriptor),
        'helper_source': identity(ROOT / 'scripts/read_sigma_boot_status.c'),
        'helper_binary': identity(ROOT / 'work/tools/read_sigma_boot_status'),
        'firmware_dump_obtained': False,
        'agent_get_feature_requests': 1,
        'agent_set_or_output_report_requests': 0,
        'agent_flash_or_unlock_commands': 0,
        'limits': [
            'Manual entry and normal return are observed with the currently working application.',
            'The exact placement of the OK check and recovery with deliberately corrupted firmware remain untested.',
            'No supported arbitrary flash-read command was established.',
            'Registry/descriptor equality does not prove byte-for-byte preservation of device flash or identify the installed application version.',
            'Device-internal flash behavior on the button sequence was not measured.',
            'The direct-cable failure cause is unknown; the KVM path carried enumeration and the one status read successfully.'
        ]}
    output = AUDIT / 'bootload-observation.json'
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'status': result['status'], 'status_bytes': len(response),
                      'firmware_dump_obtained': False, 'output': str(output.relative_to(ROOT))}))


if __name__ == '__main__':
    main()
