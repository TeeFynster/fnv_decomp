# Native retained-object build

The additive tools in `tools/rebuild/` compile the existing recipe without changing
`tools/msvc.py`, the matcher, source files, flags or function mappings. Successful
object compilation does not establish byte matching, linkage or a playable game.

Use Python 3.10 or newer on Windows. Set the existing private compiler environment
variables to folders containing `VC/bin`, `VC/include`, `VC/lib`, and `SDK/Include`
and `SDK/Lib`:

| Recipe compiler | Environment variable | Required cl version |
|---|---|---|
| `sp1` | `FNV_MSVC9_ROOT` | 15.00.30729.01 |
| `rtm` | `FNV_MSVC9_RTM_ROOT` | 15.00.21022.08 |
| `vc8` | `FNV_MSVC8_ROOT` | 14.00.50727.762 |

Each command also accepts `--sp1-root`, `--rtm-root` and `--vc8-root`. The native
tools accept `VC/PlatformSDK` when `SDK` is absent. They put the compiler's CRT
directories on the subprocess path and remove implicit `CL`/`_CL_` options.
The existing matcher still requires its documented `SDK` layout and environment.
Keep compiler files, game inputs and generated artifacts private. The default
`build/rebuild/` directory is ignored; an explicit external `--output` is also
supported. Reports contain local paths and compiler logs.

Microsoft compiler download URLs, SHA-256 checks and extraction steps are already
recorded in `.github/ci/compilers.sh` and the root README. Verify the download's
expected SHA-256 before extraction. Do not substitute a different compiler
version. These tools do not download software, run installers or accept licences.

```powershell
python tools/rebuild/toolchain.py --out build/rebuild/doctor.json
python tools/rebuild/build_objects.py --jobs 2 --output build/rebuild
```

The doctor checks each exact compiler banner and executable hashes, then compiles
and links a small independent x86 probe with no default libraries. It never runs
the probe. This tests compiler and linker execution; it does not test CRT startup
or resolve game dependencies. Missing compilers and failed probes produce JSON
diagnostics and exit status 1. No compiler is silently substituted.

The builder retains a distinct object and log for every recipe, including recipes
with the same source path. `--only TEXT` filters by source substring and
`--limit N` selects a smoke subset; neither proves full recipe coverage. `--jobs`
is bounded to 1 through 16 and defaults to 2. Each invocation uses a unique run
directory and compiles anew. Cache reuse is deliberately disabled: a complete
transitive dependency key, including SDK and compiler components, has not yet
been implemented. A source hash alone is insufficient for safe reuse.

`objects.json` is the latest report. `objects-<run-id>.json` preserves each run,
with checkpoint reports every 100 completed recipes. Objects and logs live under
`objects/<run-id>/<recipe-id>/`. Reports are atomically replaced. Both report
locations resolve object/log paths relative to their parent directory.

The report schema is version 1 with `kind: "fnv-retained-objects"`:

- `selection` records total and selected recipe counts, filters, and whether the
  selection covers the entire manifest.
- `toolchains` records readiness, expected/observed versions, executable hashes,
  private roots, and compile/link probe results.
- `units` preserves manifest order. Each row includes zero-based `recipe_index`,
  a unique `recipe_id`, the full original `recipe`, source SHA-256, compiler,
  command and relative log path. `compiled` rows include relative `object`,
  `object_sha256` and size. Failed rows have an explicit status and error.
- `summary.statuses` counts `compiled`, `compile-failed` and
  `toolchain-unavailable`. The command exits 0 only when all selected recipes
  compile; a filtered build can therefore exit 0 without covering all recipes.
- `cache.reuse` and each row's `reusable` remain false. The report explicitly
  identifies its verification level as compilation only.

Run the independent original comparison using the setup in the root README:

```powershell
python tools/build_and_match.py --image $env:FNV_IMAGE --jobs 2 --out build/rebuild/baseline-match.json
python -m unittest discover -s tests/rebuild -p "test_*.py"
```

The matcher deletes its own temporary objects; retained objects are separate.
Retained objects are not authorised uploads or replacements for the original
hash-bound comparison gates. A later link step needs explicit runtime, imported
API, data, startup and cross-variant symbol decisions; no link-ready manifest or
replacement executable is established by this phase.

## Recorded validation

On November 2, 2026, native doctor probes passed for all three exact compiler
versions. A full retained build compiled all 2,988 recipes with two compiler jobs
and no failures; all recipe variants were retained. Five builder tests passed.
The unchanged full reference comparison also exited 0: all 2,988 units passed,
all 68,667 recipe function entries matched (11,458,254 bytes), and all 1,954 EH
tails matched (138,526 bytes). Recipe entries include repeated functions across
variants; this is not a new count of distinct game functions. The EH result used
1,001 inferred names for 525 tails with zero conflicts, as reported by the
existing oracle. This proves the existing reference recipe, not runtime linkage
or playability. Private reports and objects are retained locally and are excluded
from version control.
