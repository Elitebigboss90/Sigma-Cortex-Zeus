# Local analysis environment

Verified 2026-10-27 (America/Los_Angeles) in `/Users/ethan/Devs/sigma-re`. This existing directory is the intended project. No VM or Rosetta installation was needed. Windows packages are inspected as data, never executed.

November 2 rebase: reused the same native Ghidra/JDK environment for separate projects `ghidra/sigma-118-firmware.gpr` and `ghidra/sigma-118-updater.gpr`. `work/sigma/zeus-dev3/build-manifest.json` records Homebrew clang/LLD 23.1.4 and OpenSSL 4.1.0, exact build commands and source hashes. [Current 1.1.8 build commands](firmware-candidate-dev3.md) use separate scripts, preserving the earlier 1.1.5 workflow. Offline Unicorn execution requires native JIT access outside the filesystem sandbox; it performs no hardware I/O.

## Verified tools

| Component | Initial state | Working analysis configuration |
| --- | --- | --- |
| macOS | 26.6.2, build 25G83 | Same |
| Host / shell architecture | `uname -m` and `arch`: arm64 | Native arm64; `sysctl.proc_translated=0`, `hw.optional.arm64=1` |
| Homebrew | 5.1.14 at `/opt/homebrew/bin/brew` | 7.0.11 after metadata/tool update |
| Node.js | nvm 22.15.0; below REA's declared minimum | Homebrew `node@24` 24.22.1 |
| npm | 10.9.2 paired with old nvm Node | 11.19.1 paired with Homebrew Node |
| Java | Zulu 17.0.19 arm64 | OpenJDK 21.0.11, full 64-bit JDK, `os.arch=aarch64` |
| Ghidra | Not found on PATH | Homebrew 12.1, `/opt/homebrew/opt/ghidra/libexec` |
| Native Ghidra decompiler | Not installed | `Ghidra/Features/Decompiler/os/mac_arm_64/decompile`, Mach-O arm64 |
| REA | Not found on PATH | Official `rea-agents` 6.8.0, `/opt/homebrew/bin/rea` |
| 7-Zip | Not found on PATH | Homebrew 26.01 arm64, `/opt/homebrew/bin/7zz` |
| ripgrep | VS Code-bundled 15.2.0 | Standalone Homebrew 15.1.0 at `/opt/homebrew/bin/rg` |
| Python | pyenv 3.12.3, Homebrew Python installations also present | Project venv `work/tools/python`: 3.12.3; scoped shell `python3` resolves Homebrew 3.14.5 |
| PE / instruction helpers | Not installed in initial interpreter | Project venv: pefile 2024.8.26, Capstone 5.0.9 |
| AES transform helper | Homebrew OpenSSL available | `/opt/homebrew/bin/openssl`, OpenSSL 4.1.0 (23 Oct 2026); exact transform tool recorded per output |

Evidence: [environment-verification.txt](environment-verification.txt), [REA scoped doctor](rea-doctor-configured.json), and installation logs under `work/tools/`. The `arch` utility prints without a newline in the raw transcript, so its `arm64` is immediately followed by the Rosetta check's `0`.

Ghidra's installed `Ghidra/application.properties` declares `application.version=12.1`, `application.java.min=21`, no maximum, and compiler Java 21. Its SHA-256 is `18720d66ef7f048f672e9d1a18ecd234c51d1166444dc98cf101b91fd463bf1c`. The native decompiler SHA-256 is `130ae0488bd7445c2c6f857bb82ff4a8adf19b9e4ee548c5f0a6184d0b63e4dd`. These checks establish the installed JDK and decompiler match the actual host; no x86 emulation workaround is used. REA identifies this Ghidra as compatible 12.1.x and names 12.1.4 as its upstream verified build.

## Setup performed and repeatable commands

REA's current [installation](https://github.com/morluto/rea/blob/main/docs/installation.md), [native investigation](https://github.com/morluto/rea/blob/main/docs/native-investigation.md), [firmware](https://github.com/morluto/rea/blob/main/docs/firmware-analysis.md), and [raw binary](https://github.com/morluto/rea/blob/main/docs/raw-binary.md) documentation was downloaded and read before choosing the setup. Local copies are in `work/tools/rea-docs/`; exact bytes, sizes, source URLs and SHA-256 hashes are in [rea-documentation-manifest.json](rea-documentation-manifest.json). The recorded GitHub `main` observation is commit `40b9c03f996270e944ff07cafb63be15ce903708`, timestamp `2026-10-27T23:51:03Z`; the files were fetched from `main`, not a commit-pinned URL.

The published REA 6.8.0 package declares Node `^22.23.4 || ^24.22.1 || >=26.12.1`. Homebrew's initially cached Node 24.16.0 was still too old. `brew update` followed by `brew upgrade node@24` supplied 24.22.1. Ghidra 12.1's own dependency supplied JDK 21, so the suggested JDK 25 installation was unnecessary.

Commands used, with paths scoped to this project shell:

```sh
brew install node@24 ghidra sevenzip ripgrep
brew update
brew upgrade node@24

source scripts/env.sh
npm install --global rea-agents@6.8.0
rea doctor --provider ghidra --json
rea setup --client codex --dry-run --json
rea setup --client codex --yes --json
rea doctor --client codex --provider ghidra --skill --json
```

The existing Python was used to create the project environment:

```sh
python3 -m venv work/tools/python
work/tools/python/bin/pip install pefile capstone
```

For all subsequent sessions:

```sh
cd /Users/ethan/Devs/sigma-re
source scripts/env.sh
rea doctor --client codex --provider ghidra --skill --json
work/tools/python/bin/python scripts/inventory_packages.py
```

`scripts/env.sh` selects Node 24 and the JDK's `bin` directory explicitly, sets `JAVA_HOME` and `GHIDRA_INSTALL_DIR`, and leaves shell startup files untouched. Use `work/tools/python/bin/python` for the package scripts, since `python3` in the scoped shell is a different interpreter.

The npm installation emitted a transitive `prebuild-install` deprecation and withheld Frida's optional install script under npm's current script policy. Neither blocks the verified static Ghidra workflow. Frida runtime instrumentation is outside this task and was not enabled.

The recovered AES-256-CTR transformation uses the installed OpenSSL command through `scripts/simagic_decode.py`; no Python cryptography dependency was added. Each transform manifest records its exact OpenSSL version, input range, output hash and round-trip check.

## Codex integration and restart

The reviewed setup configured only Codex and installed REA's matching skill at `/Users/ethan/.agents/skills/reverse-engineer-anything`. It preserved unrelated Codex configuration and saved `/Users/ethan/.codex/config.toml.rea.backup`. The reviewed plan is `work/tools/rea-setup-plan.json`; the applied result is [rea-setup.json](rea-setup.json), with status `ready`.

The MCP entry uses `/opt/homebrew/bin/rea mcp`, `startup_timeout_sec=30`, `tool_timeout_sec=450`, and explicit `GHIDRA_INSTALL_DIR` / `JAVA_HOME`. Its environment also pins PATH to `/opt/homebrew/opt/node@24/bin:/opt/homebrew/bin:/usr/bin:/bin:/usr/sbin:/sbin`, because the `rea` executable uses `#!/usr/bin/env node` and the original client shell preferred unsupported nvm Node 22.15.0. That narrow PATH addition has its own `config.toml.rea-node-path.backup`; parsed before/after configuration confirmed unrelated settings stayed identical.

The scoped doctor reports `healthy: true` for Codex, Ghidra and the installed skill. Its separate global `environment_healthy: false` reflects optional unconfigured providers/clients, not a failure of this selected toolchain.

To load the MCP server in this IDE client: save work, run VS Code's **Developer: Reload Window** command, then reopen the Codex chat in this project. A newly started Codex client/session should discover REA. This running session can use the REA CLI meanwhile; a healthy doctor does not establish that an already-running chat has loaded new MCP tools.

## Confirmed workflow limitations

- REA's integrated firmware inspection/extraction uses Binwalk/Unblob with Linux process controls and `prlimit`; this is not a supported native macOS extraction route. Native 7-Zip and Python parsing are used here instead. No VM is justified by package extraction alone.
- REA's generic raw `arm` target fixes `ARM:LE:32:v7`, treats the supplied entry as the mapping start, and explicitly excludes Thumb-only and Cortex-M variants. It must not be used to guess a processor or vector table. The native PE updaters were analyzed with REA/Ghidra. The decoded Sigma and Zeus applications are established Cortex-M images and were imported directly with `ARM:LE:32:Cortex`, explicit Thumb context, and their independently established maps and vector/reset seeds. Projects are retained in `ghidra/sigma-firmware.gpr`, `ghidra/sigma-1020-firmware.gpr`, and `ghidra/zeus-firmware.gpr`; analyst-created RAM blocks are hypotheses, not physical-memory measurements.
- The downloaded installation guide distinguishes Ghidra 12.1's Java 21 minimum from 12.2's Java 25 minimum. Installed metadata and executable architecture checks control this project's setup.

No devices were flashed, no original firmware bytes were modified, and no Windows updater was executed.

## Firmware development additions

The subsequent development pass installed Homebrew `lld` 23.1.4 with LLVM 23.1.4 and Z3 5.3.2. Apple Clang 21.0.0 was first verified to emit ARM EABI objects; the reproducible build explicitly selects `/opt/homebrew/opt/llvm/bin/clang` and `/opt/homebrew/bin/ld.lld`. It targets freestanding integer-only ARMv7-M Thumb, soft float, with no external runtime symbols. No Rosetta or VM is used.

The project Python environment additionally contains Unicorn 2.1.4 and pyelftools 0.33. The native Unicorn wheel crashes during JIT mapping inside the agent sandbox; a minimal two-instruction probe succeeds outside it. Offline tests therefore ran through approved unsandboxed execution, using only local image/RAM data. An explicit Cortex-M4 instruction model is a test vehicle, not an assertion of the exact chip.

```sh
brew install lld
work/tools/python/bin/pip install unicorn==2.1.4 pyelftools==0.33
work/tools/python/bin/python scripts/build_sigma_zeus.py
work/tools/python/bin/python -u scripts/verify_sigma_patch.py
work/tools/python/bin/python scripts/package_sigma_candidate.py
```

`scripts/capture_zeus_input.c` was compiled with Apple Clang and IOKit/CoreFoundation. It opens only `3670:0804`, non-exclusively, and registers an input callback. It contains no output/feature-report or updater command path. IORegistry/input capture also required access outside the agent sandbox. See [firmware-candidate.md](firmware-candidate.md) for artifacts and validation limits.
