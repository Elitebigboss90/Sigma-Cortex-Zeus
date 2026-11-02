#!/usr/bin/env python3
"""Recover Sigma initialized RAM using the image's actual scatter-load routine.

This is a transcription of Thumb at 080201D4..0802022C, not a generic
decompression guess. No device I/O and no modification of supplied files.
"""
from pathlib import Path
import hashlib
import json
import struct

ROOT = Path(__file__).resolve().parents[1]
EXPECTED = {
    '1.1.5': '03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622',
    '1.0.20': '3fc925cb7d12f3179a27248b2d86868d0556d7f36be33092b39bcced254c9e20',
}
BASE = 0x08020000


def digest(b):
    return hashlib.sha256(b).hexdigest()


def unpack(data, start, output_length):
    pos = start
    out = bytearray()
    while len(out) < output_length:
        flags = data[pos]
        pos += 1
        literals, run = flags & 7, flags >> 4
        if literals == 0:
            literals = data[pos]
            pos += 1
        if run == 0:
            run = data[pos]
            pos += 1
        if literals == 0:
            raise ValueError('Invalid literal count would underflow original loop')
        out.extend(data[pos:pos + literals - 1])
        pos += literals - 1
        if flags & 8:
            distance = data[pos]
            pos += 1
            if not 0 < distance <= len(out):
                raise ValueError('Invalid backward-copy distance')
            for _ in range(run + 2):
                out.append(out[-distance])
        else:
            out.extend(bytes(run))
        if len(out) > output_length:
            raise ValueError('Scatter destination overrun')
    return bytes(out), pos


def main():
    folder = ROOT / 'work/sigma/integrity'
    folder.mkdir(parents=True, exist_ok=True)
    results = []
    for version, expected in EXPECTED.items():
        source = ROOT / f'work/sigma/{version}/sigma-decoded.bin'
        raw = source.read_bytes()
        assert digest(raw) == expected, source
        first, last = struct.unpack_from('<II', raw, 0x1cc)
        first += 0x1cc
        last += 0x1cc
        assert last - first == 32
        records = [struct.unpack_from('<4I', raw, off) for off in range(first, last, 16)]
        assert records[0][3] == BASE + 0x1d4
        assert records[1][3] == BASE + 0x230
        data, consumed_end = unpack(raw, records[0][0] - BASE, records[0][2])
        output = folder / f'sigma-{version}-initialized-ram.bin'
        if output.exists():
            assert output.read_bytes() == data, 'Refusing changed output'
        else:
            output.write_bytes(data)
        nominal_end = records[1][0] - BASE
        carrier = ROOT / f'work/sigma/{version}/resources/resource_TEXTFILE_IDR_APP_FILE_1033.bin'
        ciphertext = carrier.read_bytes()
        opaque = raw[nominal_end:]
        previous_32_suffix = ciphertext[-32-len(opaque):-32] if opaque else b''
        result = {
            'version': version, 'source': str(source.relative_to(ROOT)),
            'source_sha256': expected, 'source_size': len(raw),
            'scatter_table': {'offset': first, 'length': last - first,
                              'bytes': raw[first:last].hex(),
                              'records': [{'source_va': r[0], 'destination_va': r[1],
                                           'destination_length': r[2], 'handler_va': r[3]}
                                          for r in records]},
            'decompressor': {'offset': 0x1d4, 'length': 0x5a,
                             'bytes': raw[0x1d4:0x22e].hex()},
            'operation': 'Transcribed scatter decompression: literals, zero runs, backward byte copies',
            'input_range': {'offset': records[0][0] - BASE,
                            'length': consumed_end - (records[0][0] - BASE),
                            'sha256': digest(raw[records[0][0] - BASE:consumed_end])},
            'output': str(output.relative_to(ROOT)), 'output_sha256': digest(data),
            'output_size': len(data), 'destination_va': records[0][1],
            'consumed_end_offset': consumed_end,
            'nominal_image_end_from_zero_fill_source': nominal_end,
            'alignment_bytes': raw[consumed_end:nominal_end].hex(),
            'bytes_after_nominal_end': opaque.hex(),
            'encoded_source': str(carrier.relative_to(ROOT)),
            'encoded_source_sha256': digest(ciphertext),
            'opaque_tail_equals_preceding_ciphertext_suffix': bool(opaque) and opaque == previous_32_suffix,
            'preceding_32byte_packet_suffix_offset': len(ciphertext) - 32 - len(opaque) if opaque else None,
            'limits': ['The zero-fill routine does not read its source address.',
                       'A linker nominal endpoint is not bootloader acceptance evidence.',
                       'Initialized RAM reconstruction does not establish physical RAM capacity.']
        }
        results.append(result)
        print(version, 'compressed range', hex(result['input_range']['offset']), hex(consumed_end),
              'RAM bytes', len(data), 'nominal endpoint', hex(nominal_end))
    (folder / 'scatter-evidence.json').write_text(json.dumps(results, indent=2) + '\n')


if __name__ == '__main__':
    main()
