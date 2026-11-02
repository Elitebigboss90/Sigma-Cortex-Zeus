Two downloadable ZIPs from the research snapshot:

- **windows-detection-check-1.1.8.zip**: unchanged supplied stock Sigma 1.1.8 updater, detection-only instructions and hashes. This is the package for checking normal/Bootload detection on Windows without clicking Update.
- **zeus-dev3.zip**: experimental Sigma **1.1.8 BETA-based** Zeus/MagLink Pro Xtend candidate, build artifacts, manifests and verification evidence. The modified updater retains its `.exe.disabled` suffix.

The experimental candidate has passed offline CPU/report checks. Bootloader acceptance, installation, recovery after a failed image and PS5 operation remain untested. This prerelease packages existing artifacts; it does not claim a working or safe-to-flash firmware release. No device was flashed to create it.

SHA-256:

```text
461b72e580b84bafe5611ff5277dd6506c906e1e5ec5a3dbf285250316fa9123  windows-detection-check-1.1.8.zip
ad02c399e8df2318738cf1691d6fd7261786d2b7e6d70cf3920717b70a261b80  zeus-dev3.zip
```
