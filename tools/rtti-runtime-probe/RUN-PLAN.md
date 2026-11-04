# Run plan for the synthetic RTTI runtime probe (for later review)

**Status: `NOT_RUN`.** Nothing in this plan has been compiled, linked or run.
The machine-readable plan is `run-plan.json`. Check it with:

```
python -I tools/rtti-runtime-probe/rtti_probe_check.py check-plan tools/rtti-runtime-probe/run-plan.json
```

The check confirms the following, and runs nothing:

- the plan is the reviewed one;
- every result is `NOT_RUN`;
- each `command_sha256` matches its argv.

The tests also compare each `sha256_lf` source hash with the files in the
checkout.

## What it would do

It would make one normal x86 build with Visual C++ 2008 SP1, using
`/GR /EHsc /W4 /Od /MT`, in a single module:

1. Compile the fixture producer.
2. Compile the fixture consumer.
3. Compile the driver.
4. Link the three objects into a console program.
5. Run the program once with one cycle, and once with three cycles.
6. Check each report with `rtti_probe_check.py`, including `--metadata`.

The fixture files are used unchanged.

## Placeholders

Every path is a placeholder. The coordinator substitutes explicit values from
the caller or from an existing private doctor report. No compiler, SDK or
Python is discovered, installed or trusted before review.

| Placeholder | Meaning |
|---|---|
| `<CALLER_SUPPLIED_CL_EXE>`, `<CALLER_SUPPLIED_LINK_EXE>` | The x86 compiler and linker of the selected VC++ 2008 SP1 |
| `<CALLER_SUPPLIED_VC_INCLUDE>`, `<CALLER_SUPPLIED_VC_LIB>` | Its `include` and x86 `lib` directories |
| `<CALLER_SUPPLIED_SDK_LIB>` | The x86 library directory of the matching Windows SDK (for `kernel32.lib`) |
| `<CALLER_SUPPLIED_TOOL_PATH>` | The directories the compiler needs on `PATH`, including the one holding its PDB support DLL |
| `<CALLER_SUPPLIED_PYTHON_EXE>` | A reviewed Python 3.10 or newer |
| `<CALLER_SUPPLIED_SYSTEMROOT>` | The Windows directory |
| `<PRIVATE_OUT_DIR>`, `<PRIVATE_TEMP_DIR>` | Empty private directories outside the checkout |
| `<REVIEWED_CHECKOUT_ROOT>` | The root of the reviewed scratch checkout; every step's working directory except the runs |

## Exact commands (before substitution)

```
<CALLER_SUPPLIED_CL_EXE> /nologo /c /TP /X /I<CALLER_SUPPLIED_VC_INCLUDE> /GR /EHsc /W4 /Od /MT /Fo<PRIVATE_OUT_DIR>/od_mt/obj/rtti_producer.obj tools/rtti-abi/fixture/rtti_producer.cpp
<CALLER_SUPPLIED_CL_EXE> /nologo /c /TP /X /I<CALLER_SUPPLIED_VC_INCLUDE> /GR /EHsc /W4 /Od /MT /Fo<PRIVATE_OUT_DIR>/od_mt/obj/rtti_consumer.obj tools/rtti-abi/fixture/rtti_consumer.cpp
<CALLER_SUPPLIED_CL_EXE> /nologo /c /TP /X /I<CALLER_SUPPLIED_VC_INCLUDE> /Itools/rtti-abi/fixture /GR /EHsc /W4 /Od /MT /Fo<PRIVATE_OUT_DIR>/od_mt/obj/rtti_probe_main.obj tools/rtti-runtime-probe/driver/rtti_probe_main.cpp
<CALLER_SUPPLIED_LINK_EXE> /NOLOGO /MACHINE:X86 /SUBSYSTEM:CONSOLE /INCREMENTAL:NO /MANIFEST:NO /OUT:<PRIVATE_OUT_DIR>/od_mt/bin/rtti_probe.exe /LIBPATH:<CALLER_SUPPLIED_VC_LIB> /LIBPATH:<CALLER_SUPPLIED_SDK_LIB> <PRIVATE_OUT_DIR>/od_mt/obj/rtti_producer.obj <PRIVATE_OUT_DIR>/od_mt/obj/rtti_consumer.obj <PRIVATE_OUT_DIR>/od_mt/obj/rtti_probe_main.obj
<PRIVATE_OUT_DIR>/od_mt/bin/rtti_probe.exe --cycles 1
<CALLER_SUPPLIED_PYTHON_EXE> -I tools/rtti-runtime-probe/rtti_probe_check.py check <PRIVATE_OUT_DIR>/od_mt/run-1/stdout.json --metadata tools/rtti-abi/fixture/fixture-metadata.json
<PRIVATE_OUT_DIR>/od_mt/bin/rtti_probe.exe --cycles 3
<CALLER_SUPPLIED_PYTHON_EXE> -I tools/rtti-runtime-probe/rtti_probe_check.py check <PRIVATE_OUT_DIR>/od_mt/run-3/stdout.json --metadata tools/rtti-abi/fixture/fixture-metadata.json
```

The two run steps use `<PRIVATE_OUT_DIR>/od_mt/run-1` and `run-3` as their
working directories. Their stdout is captured to `stdout.json` and their stderr
to `stderr.txt` there. Their stdin is the null device.

### Flags

- **`/GR` and `/EHsc`.** RTTI, and synchronous C++ exceptions, as the fixture
  requires.
- **`/Od /MT`.** Unoptimised code with the static runtime. This matches the
  fixture's earlier compile-only variant, so approved objects from that step
  could be reused (see below).
- **`/X` with explicit `/I`.** Ignore `INCLUDE` and the standard locations.
- **`/MANIFEST:NO`.** Write no side-by-side manifest file next to the program.
- **`/INCREMENTAL:NO`.** No incremental-link state.

The check rejects any of these:

- in a compile step: `/link`, `/Fe`, `/Zi`, `/GR-`, `/EHa`, `/MD`, `/D`, `@file`,
  or a listing or browse option;
- in the link step: `/DEBUG`, `/MAP`, `/PDB`, `/DLL`, `/ENTRY`, `/NODEFAULTLIB`,
  `/INCLUDE:`, `@file`, and the like.

## Environment, bounds and outputs

**Environment**

- **Build steps.** `inherit: false`. Only `PATH`, `TMP`, `TEMP` and
  `SystemRoot` are set, from placeholders. `CL`, `_CL_`, `LINK`, `_LINK_`,
  `INCLUDE`, `LIB` and `LIBPATH` are unset, so no hidden option can be added.
- **Run steps.** `inherit: false`, with only `SystemRoot` set. The program uses
  the static runtime and needs no runtime DLL. The plan changes no DLL search
  path.
- **Check steps.** `inherit: false`, with only `SystemRoot` set. Python runs
  with `-I`.

**Bounds**

- Timeouts: 120 s for each build step, 30 s for each run and check step.
- stdout limit: 64 KiB, the same as the checker's input limit.
- stderr limit: 16 KiB.

A capture that reaches its limit, or a step that times out, is a failure. It is
never reported as a truncated success.

**Outputs**

- Every output path is distinct and lies under `<PRIVATE_OUT_DIR>`.
- Nothing is written into the checkout.
- Objects, the program and captures are never committed.

**Identities.** Before trusting a result, the coordinator records these,
privately:

- hashes of the compiler, front end, back end, linker, PDB support DLL, static
  runtime library and SDK `kernel32.lib`;
- the version banners;
- listings of the include and library directories;
- the source hashes at run time;
- the object and program hashes;
- the hash of each substituted command;
- the Python version.

## The native run record is kept apart

A future native result belongs in `<PRIVATE_OUT_DIR>/native-run-record.json`.
It is kept outside the repository, and apart from both this plan and the
synthetic samples in `tests/rtti-runtime-probe/samples/`.

For each step, it records:

- the step id;
- the substituted command's hash;
- whether the step started;
- the exit code;
- whether it timed out;
- the wall time;
- the stdout and stderr byte counts, hashes and truncation flags.

The plan defines its fields only. Its status is `NOT_RUN`.

## Acceptance (for a later, authorized run)

1. Every build step exits 0 within its timeout and output limits.
2. Each run step finishes within its timeout, and neither stdout nor stderr is
   truncated.
3. The run step's exit code equals the report's `driver_exit_code`.
4. The check step prints `PASS` with `--metadata`, without the synthetic tag.

Even then, a `PASS` covers only this synthetic fixture with this compiler,
these flags and this static runtime. It is not evidence of any of the
following:

- retained game RTTI;
- object ownership;
- exception frames;
- cross-module behaviour;
- playable readiness.

The separate local COFF metadata measurement is outside this plan.

## Object reuse (optional, needs approval)

The default is to compile all three sources from scratch. The coordinator may
instead approve reusing the producer and consumer objects from the earlier
compile-only step. All of these conditions must hold:

- the same compiler identity;
- the same flags;
- matching source hashes;
- object hashes recorded before and after copying.

## Review by the coordinator

1. Run `check-plan`, and read `run-plan.json`.
2. Choose the toolchain explicitly, and substitute every placeholder.
3. Compare each substituted argv with the lines above. Record its hash.
4. Create the empty private output, temporary and run directories.
5. Authorize each step separately: compile, link, then run.
6. Keep every output and the native run record private.
