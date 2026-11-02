#!/usr/bin/env python3
"""Pinned, offline Sigma 1.1.8 startup/RAM evidence; optional native emulation.

No USB, device commands, flash programming, or modifications to originals.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from integrity_scatter import unpack

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'work/sigma/1.1.8/sigma-decoded.bin'
EXPECTED = '6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035'
OLD = ROOT / 'work/sigma/1.1.5/sigma-decoded.bin'
OLD_SHA = '03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622'
BASE = 0x08020000
OUT = ROOT / 'work/sigma/1.1.8/memory'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def write_same(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        assert path.read_bytes() == data, f'Refusing changed output: {path}'
    else:
        path.write_bytes(data)


def emulate(image, initialized):
    from unicorn import Uc, UC_ARCH_ARM, UC_MODE_THUMB, UC_MODE_MCLASS
    from unicorn.arm_const import (UC_CPU_ARM_CORTEX_M4, UC_ARM_REG_R0,
                                  UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3,
                                  UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC,
                                  UC_ARM_REG_XPSR)
    u = Uc(UC_ARCH_ARM, UC_MODE_THUMB | UC_MODE_MCLASS)
    u.ctl_set_cpu_model(UC_CPU_ARM_CORTEX_M4)
    u.mem_map(0x08000000, 0x80000)
    u.mem_write(BASE, image)
    u.mem_map(0x20000000, 0x24000)
    ret = 0x0807ff00
    registers = (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3)

    def call(address, args):
        for reg, value in zip(registers, args):
            u.reg_write(reg, value)
        u.reg_write(UC_ARM_REG_SP, 0x20006620)
        u.reg_write(UC_ARM_REG_LR, ret | 1)
        u.reg_write(UC_ARM_REG_XPSR, 0x01000000)
        u.emu_start(address | 1, ret, count=300000)
        assert u.reg_read(UC_ARM_REG_PC) == ret
        assert u.reg_read(UC_ARM_REG_SP) == 0x20006620
        return [u.reg_read(r) for r in registers]

    u.mem_write(0x20000000, b'\xa5' * 0x7b4)
    values = call(0x080201fc, (0x0804e820, 0x20000000, 0x7b0, 0))
    assert bytes(u.mem_read(0x20000000, 0x7b0)) == initialized
    assert bytes(u.mem_read(0x200007b0, 4)) == b'\xa5' * 4
    assert values[:2] == [0x0804ea74, 0x200007b0]
    u.mem_write(0x200007b0, b'\xa5' * (0x5ea0 + 4))
    call(0x0802025c, (0x0804ea78, 0x200007b0, 0x5ea0, 0))
    assert bytes(u.mem_read(0x200007b0, 0x5ea0)) == bytes(0x5ea0)
    assert bytes(u.mem_read(0x20006650, 4)) == b'\xa5' * 4
    heap = call(0x080202cc, (0, 0, 0, 0))
    assert heap == [0x20004650, 0x20006650, 0x20005650, 0x20005650]
    # Emulation-only edit, not a firmware artifact or hardware write.
    u.mem_write(BASE + 0x2e8, struct.pack('<I', 0x20005550))
    reserved = call(0x080202cc, (0, 0, 0, 0))
    assert reserved == [heap[0], heap[1], 0x20005550, heap[3]]
    return {'status': 'PASS', 'cpu_model': 'Unicorn ARM Cortex-M4 Thumb',
            'checks': ['original decompress routine matches transcribed RAM fixture and source endpoint',
                       'original zero-fill writes exactly the BSS extent and preserves end canary',
                       'original heap helper returns independently recovered four bounds',
                       'emulation-only heaplimit edit reserves 256 bytes without changing stack bounds'],
            'hardware_io': False, 'firmware_file_written_by_emulation': False}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--emulate', action='store_true')
    args = ap.parse_args()
    image = SOURCE.read_bytes()
    old = OLD.read_bytes()
    assert sha(image) == EXPECTED and len(image) == 191104
    assert sha(old) == OLD_SHA
    sp, reset = struct.unpack_from('<II', image)
    assert (sp, reset) == (0x20006650, 0x080202b1)
    first, last = struct.unpack_from('<II', image, 0x1f4)
    first += 0x1f4
    last += 0x1f4
    assert (first, last) == (0x2e7fc, 0x2e81c)
    records = [struct.unpack_from('<4I', image, p) for p in range(first, last, 16)]
    assert records == [(0x0804e820, 0x20000000, 0x7b0, 0x080201fc),
                       (0x0804ea78, 0x200007b0, 0x5ea0, 0x0802025c)]
    assert image[0x1fc:0x256] == old[0x1d4:0x22e]
    initial, end = unpack(image, records[0][0] - BASE, records[0][2])
    assert end == 0x2ea74
    assert sha(initial) == '56df6503e19c10d9687591be7124de7c849f2a33b2c8cdc4225988b3d40c0ce9'
    write_same(OUT / 'initial-data.bin', initial)
    heap = struct.unpack_from('<4I', image, 0x2e0)
    assert heap == (0x20004650, 0x20006650, 0x20005650, 0x20005650)
    carrier_path = ROOT / 'work/sigma/1.1.8/resources/resource_TEXTFILE_IDR_APP_FILE_1033.bin'
    carrier = carrier_path.read_bytes()
    assert sha(carrier) == '880479ed1cc596499f2eeef24cedcfa8a5b3239814c060cdf17d86fc1980fb35'
    nominal_end = records[1][0] - BASE
    tail = image[nominal_end:]
    assert tail == carrier[0x2ea58:0x2ea60]
    result = {
        'source': str(SOURCE.relative_to(ROOT)), 'source_sha256': EXPECTED,
        'source_size': len(image), 'base': hex(BASE), 'image_end': hex(BASE + len(image)),
        'architecture': {'endianness': 'little', 'code_mode': 'Thumb Cortex-M',
                         'initial_sp': hex(sp), 'reset_vector': hex(reset),
                         'system_init': '0x08023a20', 'scatter_entry': '0x08020198',
                         'main': '0x08043a60',
                         'main_vtor_write': {'va': '0x08043a76', 'file_offset': '0x23a76',
                                             'bytes': image[0x23a68:0x23a78].hex(),
                                             'value': '0x08020000'}},
        'scatter_table': {'offset': first, 'length': last - first, 'bytes': image[first:last].hex(),
                          'records': [{'source_va': r[0], 'destination_va': r[1],
                                       'destination_length': r[2], 'handler_va': r[3]} for r in records]},
        'decompressor': {'offset': 0x1fc, 'length': 0x5a, 'bytes': image[0x1fc:0x256].hex(),
                         'byte_identical_to_1_1_5_offset': 0x1d4, 'old_source_sha256': OLD_SHA},
        'initial_data': {'path': str((OUT / 'initial-data.bin').relative_to(ROOT)),
                         'size': len(initial), 'sha256': sha(initial), 'destination': '0x20000000',
                         'input_offset': 0x2e820, 'input_length': end - 0x2e820,
                         'input_sha256': sha(image[0x2e820:end]), 'consumed_end': hex(BASE + end),
                         'operation': 'Exact prior decompressor transcription justified by byte-identical handler'},
        'bss': {'start': '0x200007b0', 'length': 0x5ea0, 'end': '0x20006650',
                'zero_fill_handler': '0x0802025c'},
        'heap': {'helper': '0x080202cc', 'heap_base': hex(heap[0]), 'stack_top': hex(heap[1]),
                 'heap_limit': hex(heap[2]), 'stack_base': hex(heap[3]),
                 'literal_offsets': [0x2e0, 0x2e4, 0x2e8, 0x2ec],
                 'reservation_start': '0x20005550', 'reservation_size': 256,
                 'new_heap_limit': '0x20005550', 'edit_offset': 0x2e8,
                 'edit_original_bytes': '50560020', 'edit_new_bytes': '50550020',
                 'remaining_heap_bytes': 3840, 'stack_bytes': 4096},
        'tail': {'nominal_end_offset': nominal_end, 'alignment_bytes': image[end:nominal_end].hex(),
                 'opaque_offset': nominal_end, 'opaque_length': len(tail), 'opaque_bytes': tail.hex(),
                 'equals_encoded_range': {'offset': 0x2ea58, 'length': 8},
                 'carrier_sha256': sha(carrier),
                 'interpretation': 'Packaging-residue hypothesis; preserve bytes, not proof of absent integrity checking'},
        'geometry': {'page_size': 2048, 'stock_application_pages': (len(image) + 2047) // 2048,
                     'last_page_start': '0x0804e800', 'last_page_end': '0x0804f000',
                     'remaining_in_last_page': 0x0804f000 - BASE - len(image),
                     'bootloader_acceptance_verified': False},
        'hardware_io': False,
    }
    write_same(OUT / 'memory-manifest.json', (json.dumps(result, indent=2) + '\n').encode())
    if args.emulate:
        check = emulate(image, initial)
        check.update(source_sha256=EXPECTED, initial_data_sha256=sha(initial))
        write_same(OUT / 'emulation-verification.json', (json.dumps(check, indent=2) + '\n').encode())
    print(json.dumps({'fixture_sha256': sha(initial), 'fixture_size': len(initial),
                      'heaplimit_edit_offset': '0x2e8', 'state_start': '0x20005550',
                      'emulated': args.emulate}))


if __name__ == '__main__':
    main()
