# Standalone import-pointer alias probe

This original x86 Windows test investigates a narrow linker mechanism. Its C++ declarations use the SDK-compatible `LPWSTR WINAPI` and `DWORD WINAPI` return types, no arguments, and `__declspec(dllimport)`. The runner first inspects the object and requires the compiler's actual decorated undefined symbols and four DIR32 relocations to import-pointer names. An unmodified object is linked twice: the first link must fail on the two synthetic decorated pointers; the second uses exactly these explicit reviewed linker aliases:

| Undefined pointer in the object | Canonical SDK import pointer |
|---|---|
| `__imp_?FetchCommandLineW@@YGPA_WXZ` | `__imp__GetCommandLineW@0` |
| `__imp_?ReadCurrentProcessId@@YGKXZ` | `__imp__GetCurrentProcessId@0` |

Both sides denote import pointers. No IAT pointer is redirected to a function body. The runner verifies that the object hash stays unchanged, reads the resulting KERNEL32 import table, and runs the program. It checks the returned nonempty wide command line and process ID against calls to the corresponding direct SDK APIs. It records compiler/linker/dumper, selected libraries, source, object, executable and map hashes and keeps the map, detailed logs and executable private.

Run with an available compiler slot:

```powershell
python tools/rebuild/import_probe.py --sp1-root <private-vc9-sp1-root> --out <new-private-output-directory>
```

The default output is the ignored `build/rebuild/import-probe`; existing directories are never overwritten. Toolchain setup removes inherited `CL` and `_CL_`; this runner rejects nonempty inherited `LINK` and `_LINK_`. The recorded library hashes are not a full transitive dependency attestation. Offline tests run with `python -m unittest discover -s tests/rebuild -p test_import_probe.py -v`. A separate native test is opt-in with `FNV_RUNTIME_PROBE_TEST_ROOT`, and must use a free compiler slot.

This establishes the standalone mechanism, not a game startup or link claim. In particular, the game source's separately observed C++ declaration has a different apparent return type and needs its own ABI and call-site review before any mapping is used. No game source, comparison recipe or original image is changed or executed by this probe.
