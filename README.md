# Sigma Cortex / Zeus firmware work

Current result: [Sigma 1.1.8 BETA Zeus dev3](reports/firmware-candidate-dev3.md). The prior [1.1.5 dev2](reports/firmware-candidate-dev2.md) remains preserved.

The development firmware includes observed shift-paddle and seven-way mappings, analog input handling, a separate USB driver, and console-report merging. It passes 16 finite ARM emulator checks, replay of 99 measured input frames, and 56 supplemental comparisons with non-neutral base controls. Manual OK-button Bootload entry, a status read through the KVM, and return to normal operation are now observed. The candidate remains **unverified for installation**: image acceptance, integrity rules and restoration after a failed flash remain unresolved. No devices have been flashed.

- [Current candidate artifacts and build evidence](reports/firmware-candidate-dev3.md)
- [1.1.8 package analysis and semantic rebase](reports/sigma-1.1.8-analysis.md)
- [1.1.8 USB bindings](reports/sigma-1.1.8-usb-bindings.md), [memory](reports/sigma-1.1.8-memory.md), [updater](reports/sigma-1.1.8-updater.md)
- [Live wheel observations and control mappings](reports/zeus-live-observation.md)
- [Sigma normal-mode identification](reports/sigma-live-observation.md)
- [Bootloader/readback boundary](reports/sigma-readback.md)
- [Verified manual Bootload entry, status read and normal return](reports/sigma-bootload-observation.md)
- [Recovery options without a probe](reports/sigma-recovery-options.md), [stock updater preflight limits](reports/sigma-updater-preflight.md)
- [Nations N32G45x code match](reports/sigma-n32-code-match.md), [N32G455REL7 memory and recovery investigation](reports/sigma-n32-hardware.md)
- [Actual board photos: confirmed chip marking and candidate headers](reports/sigma-hardware-photos.md)
- [Environment](reports/environment.md), [original packages](reports/package-inventory.md)
- [Sigma analysis](reports/sigma-analysis.md), [Simagic analysis](reports/simagic-analysis.md)

```sh
source scripts/env.sh
work/tools/python/bin/python scripts/build_sigma118_zeus.py --build-id zeus-dev3
work/tools/python/bin/python -u scripts/verify_sigma118_patch.py --build-id zeus-dev3
work/tools/python/bin/python scripts/package_sigma118_candidate.py --build-id zeus-dev3
python3 scripts/finalize_sigma118_candidate.py
```

The build uses copies and preserves originals. New source/profile revisions require a new build ID. The disabled updater is an offline review artifact; no script here launches it or flashes hardware.

## Obtaining the complete project

Original packages, ZIPs, extracted firmware, candidate builds, captures and Ghidra projects are included. Large binary artifacts use Git LFS. Install Git LFS, then obtain the full contents with:

```sh
git clone https://github.com/Elitebigboss90/Sigma-Cortex-Zeus.git
cd Sigma-Cortex-Zeus
git lfs install --local
git lfs pull
```

The local Python environment, compiler caches, Python bytecode and macOS metadata are excluded; setup versions and commands are recorded in [the environment report](reports/environment.md). All other project artifacts, including ZIP files, retain their existing bytes. The repository does not grant a new license to third-party firmware or vendor packages.
