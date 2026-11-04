# Standalone CRT/TLS probe

This is an original, small x86 Windows test program, independent of the game. It uses the selected VC9 SP1 compiler and ordinary CRT startup, static CRT linking and Win32 imports. A global constructor records startup, `main` and two concurrently alive Win32 threads exercise an initialized `__declspec(thread)` variable, and a global destructor emits the final JSON receipt during normal CRT exit. All three threads must observe their own initial value and preserve distinct writes. This does not establish game startup, linkage, runtime TLS layout, asset loading or playability.

Once a single compile/link slot is available under the shared build budget, run:

```powershell
python tools/rebuild/runtime_probe.py --sp1-root <private-vc9-sp1-root> --out <new-private-output-directory>
```

The tool requires an exact SP1 version and writes only into a new output directory; the default is ignored `build/rebuild/runtime-probe`. It refuses to overwrite an existing directory. Source, compiler, linker, static CRT and kernel32 import-library hashes, compile/link options, executable/object/map hashes, exit status and observed receipt are recorded. The linker map and build/execution logs are retained privately with the executable and object; these may contain private paths. The library hashes cover the named inputs, not a complete transitive dependency or installed SDK attestation. A failure, timeout, missing destructor receipt, nonzero exit, wrong architecture or inconsistent TLS observations is a failure, never a simulated success.

Unit tests do not invoke a compiler by default. With a free slot, set `FNV_RUNTIME_PROBE_TEST_ROOT` to the private SP1 root when running `python -m unittest discover -s tests/rebuild -p test_runtime_probe.py -v` to opt into a separate real native test. Do not publish its private artifacts. Preserve the original comparison recipes and gates; this test consumes no game image or assets.
