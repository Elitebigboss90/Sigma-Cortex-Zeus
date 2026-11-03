# Zeus dev5 Windows diagnostic

This is an experimental diagnostic, not a confirmed compatibility fix. It has not been flashed or tested on Sigma hardware. Keep the updater disabled until the user explicitly chooses this new firmware write. Use this build with Windows for diagnosis; it overwrites vendor input bytes 56–63 and is not intended for PS5/game testing.

The user reports dev3's updater completed, Sigma/base still work, and Zeus inputs do not work through Sigma, including with the base/pedals disconnected. Direct-PC input works with SimPro closed. Windows presents Zeus as `3670:0804` and returns 64-byte ID1 buffers. Their first 23 bytes contain the expected controls; bytes afterward are not all zero. Windows HID buffering does not establish the actual USB transfer length reaching Sigma.

Dev5 retains dev3, adds periodic diagnostic input, records native callback length/report ID and initialization return status, and allows the original ID1 parser to read the known 23-byte prefix from either a 23- or 64-byte callback. Other lengths and report IDs remain rejected by the original parser. The wheel icon is unchanged. The image still occupies the original 94 application flash pages, which does not prove bootloader acceptance or recovery.

The updater SHA-256 is:

`96583ec2b8dcb73b7e69b117710a5f95ce9f8f3b9df380761c7d6c4afa0eb6bf`

Offline checks pass for four real initialization/host-enumeration models, initialization failure logging, periodic report scheduling and wraparound, native length/ID instrumentation, and 125 distinct captured control prefixes supplied as both 23- and 64-byte inputs. The first 56 output bytes match dev3 in those replay cases. USB controller behavior, actual transfer success, installed firmware bytes and hardware recovery are not verified. See the included manifests for exact bounds and hashes.

After an explicitly authorized installation, connect Sigma's console/PC port to Windows and connect Zeus/Xtend to Sigma with its usual external power. A read-only 10-second capture can be run from this directory:

```powershell
.\inspect_windows_hid.ps1 -CaptureDevice Sigma -CaptureSeconds 10 -SnapshotPath .\sigma-dev5-input.json
```

The command refuses to overwrite an existing output file. It sends no output or feature reports. Use a new filename for another capture. Return the capture for decoding; if Python is available, `python decode_sigma_diagnostic.py sigma-dev5-input.json` summarizes it.

For ID1 input, bytes 56–63 contain:

| Byte | Meaning |
| --- | --- |
| 56 | `5A` diagnostic marker |
| 57 | High nibble `5`, low nibble changing heartbeat |
| 58 | Wheel USB address, zero if unbound |
| 59 | Poll-enabled flag |
| 60 | Last Init return; `FF` means no Init attempt, `00` means success |
| 61 | Native length of the last input callback |
| 62 | First byte/report ID of that callback |
| 63 | Accepted ID1 counter modulo 256 |

A marker establishes that this diagnostic code executed. An address/poll flag shows binding; native length and report ID identify what the parser receives. No marker in an empty capture does not prove the image was rejected. If installation fails, stop and record the screen/updater behavior; no recovery guarantee is established.
