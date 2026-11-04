# Compile-only plan: MSVC 2008 SP1, x86

**Status: `NOT_RUN`. This is a plan, not an executed operation.** Nothing in
this delivery has run a compiler or a linker, or executed the fixture. Running
any part of this plan needs the coordinator's separate review and
authorization of the exact command, compiler and environment.

The machine-readable form is `compile-plan.json`. `rtti_abi.py check-plan`
checks that it is still this bounded plan: placeholders instead of paths, the
exact reviewed command lines, no link or run step, and every result `NOT_RUN`.
The check never runs anything.

## Scope

- Two compile-only steps, one per translation unit, in one variant (`od_mt`).
- Inputs: the two `.cpp` files and the shared header in `fixture/`.
- Outputs: two object files in a private output directory.

The plan never:

- discovers a compiler automatically, or trusts one found on `PATH` or in the
  registry;
- installs or repairs a toolchain;
- links, or produces an executable or library;
- runs the fixture;
- extracts RTTI or anything else from a binary, including the objects it
  produces;
- selects game aliases or changes runtime providers.

These are also listed as `forbidden_operations` in the JSON.

## Inputs the caller supplies

Each placeholder is replaced only in a private copy of the command, never in a
file in the repository.

| Placeholder | What it is | Source |
|---|---|---|
| `<CALLER_SUPPLIED_CL_EXE>` | Full path of the Visual C++ 2008 SP1 x86 `cl.exe`. | An explicit path from the caller, or one taken from an existing private doctor report. Never discovered. |
| `<CALLER_SUPPLIED_VC_INCLUDE>` | The matching Visual C++ 2008 `include` directory. The fixture needs only `<new>` and `<typeinfo>` and what they include. | Same as above. |
| `<CALLER_SUPPLIED_TOOL_PATH>` | The `PATH` value the compiler needs to find its own DLLs. | Same as above. |
| `<CALLER_SUPPLIED_SYSTEMROOT>` | The Windows `SystemRoot` value. | The caller. |
| `<PRIVATE_TEMP_DIR>` | An empty temporary directory for the compiler (`TMP` and `TEMP`). | The caller; outside the checkout. |
| `<PRIVATE_OUT_DIR>` | An empty output directory, independent of every other build output. Outside the checkout, or under the ignored `build/rebuild/` directory. | The caller. |
| `<CHECKOUT_ROOT>` | Working directory: the root of a disposable checkout that contains these sources. | The caller. |

## Commands

Each command is an argument vector. It is passed to the process directly, with
no shell. The working directory is `<CHECKOUT_ROOT>`.

Producer:

```
<CALLER_SUPPLIED_CL_EXE> /nologo /c /TP /X /I<CALLER_SUPPLIED_VC_INCLUDE> /GR /EHsc /W4 /Od /MT /Fo<PRIVATE_OUT_DIR>/od_mt/rtti_producer.obj tools/rtti-abi/fixture/rtti_producer.cpp
```

Consumer:

```
<CALLER_SUPPLIED_CL_EXE> /nologo /c /TP /X /I<CALLER_SUPPLIED_VC_INCLUDE> /GR /EHsc /W4 /Od /MT /Fo<PRIVATE_OUT_DIR>/od_mt/rtti_consumer.obj tools/rtti-abi/fixture/rtti_consumer.cpp
```

| Flag | Why |
|---|---|
| `/nologo` | Keep the output to diagnostics. The banner is recorded separately (see Identity). |
| `/c` | Compile only. No link step. |
| `/TP` | Compile as C++. |
| `/X` with one `/I` | Ignore the `INCLUDE` environment variable and use only the one explicit include directory. The fixture header is found next to each source. |
| `/GR` | Generate RTTI. This is the default for this compiler, but stated explicitly. |
| `/EHsc` | Synchronous C++ exceptions, needed for the `std::bad_cast` and `std::bad_alloc` handlers. |
| `/W4` | High warning level, so warnings can be reviewed. Warnings are not errors. |
| `/Od` | No optimization, so every cast and handler is expected to stay visible to a later, separately authorized inspection. |
| `/MT` | Static C runtime. This fixes which form the C runtime references take. |
| `/Fo...` | A separate object path per step under the private output root. |

**Not used, on purpose:**

- `/Zi`, `/Z7`, `/Fd` and `/FR`: debug and browse information embeds paths.
- `/Fa` and `/FA`: listings are generated code, which is private output and
  not wanted here.
- `/D`: no defines.
- `/link`, `/Fe`, `/LD`, `/MD` and response files (`@file`).

`check-plan` rejects all of these.

## Environment

The environment is closed. Nothing is inherited.

- **Set:** `PATH`, `TMP`, `TEMP` and `SystemRoot`, each from its placeholder.
- **Absent:** `CL`, `_CL_`, `INCLUDE`, `LIB` and `LIBPATH`. `CL` and `_CL_`
  would silently add flags.

## Identity record

A later authorized run would fill in these items. Today every value is
`NOT_RUN`. Each hash would cover the file's bytes as found at run time.

| Item | What |
|---|---|
| `compiler_sha256` | SHA-256 of `cl.exe`. |
| `compiler_version_banner` | The version banner, from the doctor report or from the reviewed command's own output. Version 15.00.30729.01 is the expected SP1 banner, but it is not assumed. |
| `front_end_sha256`, `back_end_sha256`, `pdb_support_dll_sha256` | SHA-256 of the compiler's front-end, back-end and PDB support DLLs. |
| `include_dir_listing_sha256` | SHA-256 of a sorted listing of names and hashes of the include directory's files. |
| `source_sha256_at_run` | SHA-256 of the three sources as compiled. |
| `object_sha256` | SHA-256 of each object file. |
| `stdout_sha256`, `stderr_sha256`, `exit_code` | The captured output and the exit status of each step. |

`compile-plan.json` also lists `sha256_lf` for each source: the SHA-256 of the
file as delivered, with LF line endings. The tests check that these still match
the files. If a checkout converts line endings, the bytes compiled differ, but
`sha256_lf` still identifies the reviewed text.

## Review by the coordinator

Before authorizing a run, the coordinator:

1. Runs `python tools/rtti-abi/rtti_abi.py check-plan tools/rtti-abi/compile-plan.json`
   and confirms it is valid.
2. Confirms the source hashes by running the tests in `tests/rtti-abi/`.
3. Chooses the compiler path and include directory explicitly. They come from
   the caller or an existing private doctor report, never from discovery. The
   coordinator records the compiler's identity before trusting it.
4. Makes a private copy of each argument vector with the placeholders replaced.
   That copy is reviewed exactly as it will be run.
5. Confirms the output and temporary directories are empty, private and used by
   nothing else.

After an authorized run:

- The identity items and outputs stay private.
- The object files are not committed, and are not inspected as part of this
  plan.
- Results in this delivery stay `NOT_RUN`. A separate, reviewed record would
  hold any new result.
- A failure is recorded as it happened. No flag is changed to make the compile
  pass.
