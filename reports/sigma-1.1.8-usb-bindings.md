# Sigma 1.1.8 USB-driver binding audit

November 2, 2026. This is static analysis plus finite CPU/RAM emulation; no device access or firmware installation was performed.

Source **N**: `work/sigma/1.1.8/sigma-decoded.bin`, 191,104 bytes, SHA-256 `6fdef1664030ea9daf965a3b8c0d75e747fd04f3d3572641999bfcc785bb4035`. Source **O**: `work/sigma/1.1.5/sigma-decoded.bin`, SHA-256 `03083142e185dbf9598b235281fff4608145f75628b8c7b51d2de642fad51622`. In both, VA = file offset + `08020000`. Bindings were identified by constructor/vtable structure, code behavior, call arguments and emulation, not one assumed offset delta.

## Constructor hook is now a tail branch

N runtime `08020758` iterates a self-relative initializer table. Its bounds resolve to `[0804E81C,0804E820)`; the sole word at file `0x2E81C`, **`05 5F FD FF`**, resolves to Thumb entry **`08024721`**. `08046DD0` performs FPU initialization and is not the constructor chain.

Constructor chain `08024720` initializes host and six classes in this order:

| Chain call VA | Target / eventual constructor | Object | Role established by code |
| --- | --- | --- | --- |
| `08024722` | `0802C4C0` → `0802B5AC` | `20004488` | USB host |
| `08024726` | `0802C4CC` → `0802BF94` | `20002734` | Hub |
| `0802472A` | `0802C4E0` → `08028434` | `200008E8` | Base, `0483:0522` |
| `0802472E` | `0802C4E4` → `08024A18` | `20003AB0` | Existing pedal class with expanded predicate |
| `08024732` | `0802C4E8` → `08029BFC` | `200025C0` | Handbrake |
| `08024736` | `0802C4EC` → `08029320` | `2000267C` | Existing shifter |
| `0802473E` | `0802C4F0` → `080295D4` | `20004128` | Additional input class; exact product label not inferred solely from its PID |

The final instruction at **`0802473E` / file `0x473E`**, bytes **`07 F0 D7 BE`**, is **`B.W 0802C4F0`**. The preceding instruction at `0802473A` restores `{r7,lr}`. An appended constructor hook must therefore replace this with another **tail B.W**, preserving the incoming LR, and call original Thumb entry **`0802C4F1`** before registering Zeus. Replacing it with BL would alter the return chain.

The new host registry remains 16 words at **host `20004488` + `0x78`**. Registrar **`0802AFA4`** inserts into the first empty slot. A direct emulation of the entire unmodified chain, with no hardware stubs, produced the six object pointers above in order and ten zero slots. Calling the generic constructor afterward adds Zeus to slot 6, the seventh object, and preserves all six existing entries.

## Generic constructor and vtable

Generic constructor **`0802910C`** (Thumb `0802910D`) calls `08028E90`, registers through `0802AFA4`, returns the supplied object pointer, and installs the generic vtable. Ghidra inferred `void`, but the recorded instructions and emulation establish r0 equals the object pointer at return. Use `(state, 20004488)`.

N's complete generic table is **`080471B0` / file `0x271B0`**, 80 bytes. Preserve its shape, and set object `+4` to the copied table's **`+0x4C`**. Raw table bytes, every word, instruction ranges and all old/new mappings are recorded in `work/sigma/1.1.8/bindings118/bindings-evidence.json`.

| Slot | N Thumb value | Role |
| --- | --- | --- |
| `00` | `080289AD` | Init `(self,u8 parent,u8 port,u8 low_speed)` |
| `04` | `08029C6D` | Preconfiguration, returns zero |
| `08` | `08028E51` | Release |
| `0C` | `08028FB1` | Poll |
| `10` | `08028471` | Current address at self+`0x0C` |
| `14` | `08029C51` | No-op |
| `18` | `08029CB5` | VID/PID predicate; generic returns zero |
| `1C` | `08029C35` | Class predicate, returns zero |
| `20` | `08029C5D` | Constant true |
| `24` | `080288B1` | Report-parser lookup |
| `28` | `08028925` | Report-parser registration |
| `2C` | `080289A1` | On-init; generic returns zero |
| `30` | `08028EFD` | Callback adapter |
| `34` | `08028E7D` | Poll-enabled flag |
| `38` | `08028F3D` | Endpoint-extraction wrapper |
| `3C` | `08028F9D` | Endpoint eligibility; generic returns one |
| `40` | `08028EE5` | Report callback; generic no-op |
| `44` | `FFFFFFFC` | Secondary-base adjustment, not code |
| `48` | `00000000` | Secondary-table metadata |
| `4C` | `0802C3E1` | Secondary thunk, subtracts 4 then forwards to `08028F3C` |

The object fields used by the patch retain their semantic offsets: `+8` host; `+0C` address; `+30` interface count; `+31` endpoint count; `+34` deadline; `+38` interval; `+39` poll-enabled; `+6F` report-ID flag; `+70` PID; `+72` VID. A `0x78`-byte prefix remains sufficient before new private state. Init explicitly writes VID/PID from descriptor offsets 8/10 to object `+72/+70`; this is independent evidence for identity fields.

## Initialization, release and callback behavior

Init **`080289AC`** returns `D9` if the object already has an address. After reading descriptors and extracting endpoints, it returns `D1` if endpoint count is still below two. Its call to vtable OnInit `+2C` ignores the return value. The existing wrapper design—preserve an already-bound object and release a failed first allocation—therefore still applies.

Endpoint wrapper `08028F3C` calls extractor **`08028724`**. That extractor calls eligibility slot `+3C` with `(self, interface_number, protocol)` before recording an input endpoint. The Zeus wrapper must retain its identity/interface check here; a VID/PID gate alone is not a sufficient defense against host enumeration fallback.

Release **`08028E50`** frees the USB address, sets endpoint count to one, and clears address, deadline and poll-enabled state. The Zeus release wrapper should additionally clear private controls and mark the console report dirty.

Poll **`08028FB0`** uses a 64-byte raw buffer, calls low-level USB IN **`0802A36C`**, clamps the received length to 64, then calls vtable `+40` as:

```c
callback(self, self, has_report_ids & 1, (uint8_t)received_length, raw_buffer);
```

The fifth argument is passed on the stack. No leading report-ID byte is removed. Raw instruction/call evidence and decompilation are in `bindings118/usb.c`. Timer lookup is `08043C60`; the parent's console/timing audit separately establishes its backing RAM.

## Existing recognition and NeoX-related changes

The five instantiated non-hub classes retain or expand these gates:

| N predicate | Accepted VID:PID pairs |
| --- | --- |
| `080249A4` | `0483:0525`, `3670:0903`, `0483:0524` |
| `080281C0` | `0483:0522` |
| `080292A4` | `0483:0531` |
| `080294DC` | `0483:0526`, `0483:0525`, `3670:0A06` |
| `08029B44` | `0483:0530`, `3670:0A04` |

Every listed pair was accepted by direct execution of its native predicate, and **all five rejected Zeus `3670:0804`**. This is a bounded recognition finding; no real fallback enumeration was executed. The generic table is an additional table, not an additional instantiated device. Original registry order matters where accepted identifiers overlap and is preserved by the proposed final tail-branch hook.

Base callback **`08024B90`** still requires `0483:0522` and chooses one of two parsers using object `+157`. New **`08024C38`** requires 32-byte reports; **`08025114`** requires 39-byte reports. Both inspect `(self[0x158] & 0x3F)` and now include **type `0x0B`**, absent from the reviewed 1.1.5 0–6 switches. Type `0x0B` calls **`0802754C`**:

- 32-byte path: compare at `08024D7A`, bytes `0B 28`; call at `08024EC8`, bytes `02 F0 40 FB`.
- 39-byte path: compare at `0802529C`, bytes `0B 28`; call at `0802541C`, bytes `02 F0 96 F8`.

This is a semantic addition consistent with the supplied NeoX-support patch note. Identifying type `0x0B` physically as NeoX remains an inference without a corresponding base capture. It is a **base-to-converter** report change, whereas direct Zeus/Xtend USB needs a separate class. The rebase must leave these new original parsing paths intact.

## Reproduction and limits

- `scripts/bindings118_evidence.py` pins N, validates the complete vtable and constructor hook bytes, and emits bounded raw instruction/range evidence.
- `scripts/bindings118_emulate.py` runs the original constructors, checks all registry slots, verifies the generic constructor's return and secondary pointer, and exercises the original identity predicates. Result: `work/sigma/1.1.8/bindings118/constructor-emulation.json`, **PASS**, no hardware stubs.
- Initial-RAM fixture: `work/sigma/1.1.8/memory/initial-data.bin`, SHA-256 `56df6503e19c10d9687591be7124de7c849f2a33b2c8cdc4225988b3d40c0ce9`, supplied by the separately verified 1.1.8 scatter-loading analysis.
- Ghidra exports `usb.c`, `methods.c`, `claims.c`, `base-parsers.c` came from a private project copy with `ARM:LE:32:Cortex`; original project/artifact bytes were not edited. Their hashes are bound in `bindings-evidence.json`.

Confidence is high for table addresses, register/object fields, tested registry order and predicate behavior. No claim is made that all possible USB transitions, timing, integrity enforcement, hardware operation or PS5 behavior have been verified. The rebased patch must run its own integration/emulator tests against these new bindings.
