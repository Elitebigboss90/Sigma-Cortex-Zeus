#!/usr/bin/env python3
"""Check dev2 placement against the reported N32G455REL7 geometry, offline only."""
import hashlib
import json
import argparse
import xml.etree.ElementTree as ET
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def checked(path, expected):
    data = (ROOT / path).read_bytes()
    assert hashlib.sha256(data).hexdigest() == expected, path
    return data


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--photo-evidence", action="store_true",
                        help="Bind the result to the user's subsequently supplied chip-marking photos")
    args = parser.parse_args()
    sources = {
        "originals/Nations-documentation/EN_DS_N32G455_Series_Datasheet_V2.6.0.pdf":
            "3a2cda0075958b47d5d815facbe5b37dc3cb2650e3377473cb01a8591eed92f8",
        "originals/Nations-documentation/EN_UM_N32G45x_Series_User_Manual_V3.5.0.pdf":
            "c345230a200209e522c7cde6c00970e26b1ac2076ae1a0949662aa2e01ce6e8f",
        "work/tools/nations/packs/NSING.N32G45x_DFP.1.0.7.pack":
            "b4eed0b822131d0563c848f332c914bf558a840b1b4d912d8029e0db148de60a",
    }
    for path, digest in sources.items():
        checked(path, digest)
    # Parse the exact device block directly from the pinned ZIP-format pack.
    import io
    import zipfile
    with zipfile.ZipFile(io.BytesIO((ROOT / list(sources)[2]).read_bytes())) as archive:
        pdsc = ET.fromstring(archive.read("NSING.N32G45x_DFP.pdsc"))
    device = pdsc.find(".//device[@Dname='N32G455REL7']")
    assert device is not None
    memories = {m.attrib["id"]: m.attrib for m in device.findall("memory")}
    flash_start = int(memories["IROM1"]["start"], 0)
    flash_end = flash_start + int(memories["IROM1"]["size"], 0)
    assert (flash_start, flash_end) == (0x08000000, 0x08080000)
    assert int(memories["IRAM1"]["start"], 0) == 0x20000000
    assert int(memories["IRAM1"]["size"], 0) == 0x24000
    # UM V3.5 pp.52,64–65: 2-KiB flash pages, 128-KiB main SRAM + 16-KiB retention.
    page_size, application_start, main_sram_end = 0x800, 0x08020000, 0x20020000
    inputs = {
        "work/sigma/1.1.5/sigma-decoded.bin":
            "03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622",
        "work/sigma/zeus-dev2/NOT_FOR_FLASHING-sigma-1.1.5-zeus-dev2.plaintext.bin":
            "0152f4f17e23f47f452d2290fe782afb7b70d65b7a854be5e357da36910ab4a8",
    }
    rows = []
    for path, digest in inputs.items():
        data = checked(path, digest)
        end = application_start + len(data)
        rounded_end = (end + page_size - 1) & ~(page_size - 1)
        assert application_start >= flash_start and rounded_end <= flash_end
        rows.append({"path": path, "sha256": digest, "size": len(data),
                     "start": hex(application_start), "end_exclusive": hex(end),
                     "last_page_start": hex((end - 1) & ~(page_size - 1)),
                     "page_rounded_end_exclusive": hex(rounded_end),
                     "application_pages": (rounded_end - application_start) // page_size,
                     "last_page_unused_bytes": rounded_end - end})
    assert rows[0]["application_pages"] == rows[1]["application_pages"] == 93
    assert 0x20000000 <= 0x20005490 < 0x20005590 <= main_sram_end
    result = {"status": "PASS_CONDITIONAL_ON_REPORTED_PART", "sources": sources,
              "device": "N32G455REL7", "physical_unit_identified": False,
              "flash_range": [hex(flash_start), hex(flash_end)], "page_bytes": page_size,
              "images": rows, "additional_flash_pages_for_dev2": 0,
              "ram_reservation": ["0x20005490", "0x20005590"],
              "ram_reservation_within_main_sram": True, "bootloader_acceptance_verified": False,
              "limitations": "Address containment does not establish allocation, partition permissions, integrity rules, recovery or installed silicon."}
    if args.photo_evidence:
        photos = {
            "originals/hardware-photos/IMG_0171.HEIC":
                "e1077adcd1b6787e0bd65593163c494b24a81ace1c7f2c73254642c7495497e9",
            "originals/hardware-photos/IMG_0173.HEIC":
                "28df6991db93974fc69259dfa6e76b03379b55ff55e30ffd93eb0dee591f119f",
        }
        for path, digest in photos.items():
            checked(path, digest)
        result.update({"status": "PASS_FOR_PHOTOGRAPHED_PART_MARKING",
                       "physical_unit_identified": True,
                       "identification_method": "Manual visual observation of N32G455 and REL7 on U1; not automatic image recognition or an electronic chip-ID read",
                       "electronic_chip_id_read": False,
                       "photo_sources": photos,
                       "photo_report": "reports/sigma-hardware-photos.md"})
        result["limitations"] = "Address containment and photographed marking do not establish partition permissions, integrity rules, recovery, electrical connectivity or protection state."
    filename = "geometry-verification-photos.json" if args.photo_evidence else "geometry-verification.json"
    output = ROOT / "work/sigma/n32" / filename
    output.parent.mkdir(parents=True, exist_ok=True)
    encoded = (json.dumps(result, indent=2) + "\n").encode()
    if output.exists():
        assert output.read_bytes() == encoded, "Refusing differing existing geometry record"
    else:
        output.write_bytes(encoded)
    print("PASS: both images occupy 93 pages; dev2 needs no additional flash page; reserved state fits main SRAM. Electronic identity, protection and bootloader acceptance remain unverified.")


if __name__ == "__main__":
    main()
