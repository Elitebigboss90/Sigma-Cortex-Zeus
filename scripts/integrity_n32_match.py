#!/usr/bin/env python3
"""Retain offline Sigma/Nations startup comparison evidence; performs no device I/O."""
from pathlib import Path
import hashlib
import json

from capstone import Cs, CS_ARCH_ARM, CS_MODE_LITTLE_ENDIAN, CS_MODE_THUMB, CS_MODE_MCLASS

ROOT = Path(__file__).resolve().parents[1]
PACK = ROOT / "work/tools/nations/packs/NSING.N32G45x_DFP.1.0.7"
SIGMA = ROOT / "work/sigma/1.1.5/sigma-decoded.bin"
EXPECTED = {
    "firmware/CMSIS/device/system_n32g45x.c": "f061fca77483ceae6b941e1b4a1b821f7eea715c6af1ec4aee7684eb295f2b97",
    "firmware/CMSIS/device/n32g45x.h": "a1cdac4068ad11e26d8228a91778e88d389818d5e7dc226c5590cd0a74b180b4",
    "firmware/n32g45x_std_periph_driver/src/n32g45x_flash.c": "d927291f35f7a409a08db37abd916a7bbea4f6830aae2f755447866214ca1c26",
    "firmware/n32g45x_std_periph_driver/inc/n32g45x_flash.h": "76c8885945041c5e9da868bf1526f5c2e37e83f53c54a6da8543468e961f7295",
    "NSING.N32G45x_DFP.pdsc": "5c5b53eb65af741221ba212e80e719eac87b7e7d0674a0e1413a32c340aa4eb3",
    "svd/N32G455.svd": "048ec45f3ecd82c3bf208cc42fe9fd40a1caba1b41920415ba763aa70a6afc80",
}


def identity(path, expected):
    data = path.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    if digest != expected:
        raise ValueError(f"Source hash changed: {path}: {digest}")
    return {"path": str(path.relative_to(ROOT)), "size": len(data), "sha256": digest}


def main():
    result = {
        "operation": "Read and hash files, disassemble selected Thumb/M-class spans; manual semantic comparison, not compiled equivalence or hardware observation",
        "sigma": identity(SIGMA, "03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622"),
        "pack": identity(PACK.parent / (PACK.name + ".pack"), "b4eed0b822131d0563c848f332c914bf558a840b1b4d912d8029e0db148de60a"),
        "pack_sources": [identity(PACK / name, digest) for name, digest in EXPECTED.items()],
        "binary_spans": [],
    }
    data = SIGMA.read_bytes()
    disassembler = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_MCLASS | CS_MODE_LITTLE_ENDIAN)
    spans = [
        ("SystemInit including trim flag check", 0x7F8, 0x8E8),
        ("Clock initialization", 0x8E8, 0xA50),
        ("Backup-voltage trim", 0xA50, 0xAE8),
        ("Flash unlock, lock and page erase", 0x1344, 0x13E4),
        ("SysTick clock-dependent reload", 0x4F20, 0x4F68),
    ]
    for label, start, end in spans:
        result["binary_spans"].append({
            "label": label, "file_start": hex(start), "file_end_exclusive": hex(end),
            "virtual_start": hex(0x08020000 + start), "hex": data[start:end].hex(),
            "instructions": [{"va": hex(i.address), "file_offset": hex(i.address - 0x08020000),
                              "hex": i.bytes.hex(), "mnemonic": i.mnemonic, "operands": i.op_str}
                             for i in disassembler.disasm(data[start:end], 0x08020000 + start)]
        })
    out = ROOT / "work/tools/nations/sigma-source-match.json"
    out.write_text(json.dumps(result, indent=2) + "\n")
    print(f"Verified {len(EXPECTED) + 2} input hashes; retained {len(spans)} instruction spans in {out.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
