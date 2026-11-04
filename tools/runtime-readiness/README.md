# Runtime readiness checker and manual smoke-test template

**There is no runnable rebuilt game.** Nothing here launches anything, and no
result in this directory means "ready". The checker only reports which inputs
for a *later, separately approved* private test are present, missing or still
unknown. The smoke-test template is a manual checklist whose every result is
`not-run`.

| File | What it is |
|---|---|
| `readiness_check.py` | Read-only checker (Python 3.10+, stdlib only). |
| `observed-inventory.json` | Names from the [runtime environment inventory](../../docs/rebuild/GAME-RUNTIME-ENVIRONMENT.md): one observed installation plus the original's 17 imports. Evidence only, never requirements. |
| `examples/manifest.example.json` | Declarative manifest with placeholders. |
| `examples/requirements.example.json` | Format for user-supplied requirements and attestations, with provenance. |
| `SMOKE-TEST-TEMPLATE.md`, `smoke-test-template.json` | Manual, unexecuted smoke-test record. |
| `smoke_template.py` | Read-only validator for that record. |

Tests are in `tests/runtime-readiness/` and use only synthetic fixtures.

## What the checker does and does not do

It does:

- read paths you supply on the command line or in a manifest: the owned
  installation, a prospective private rebuilt executable, the intended working
  directory, an isolated config/save location and DLL provider directories;
- check each named entry and its ancestors using `lstat`, at most two levels below a supplied root
  (for example `Data/FalloutNV.esm`), and count the top-level entries of the
  isolated profile (capped at 1,000). Each intermediate level is checked too,
  so a link at `Data` is never followed. Ancestor checks add bounded metadata reads proportional to path depth;
- read only the small JSON files you hand it (manifest, requirements,
  toolchain report; each capped at 1 MiB).

It never: launches or loads a program or DLL; runs compiler or linker probes
(it does not call `tools/rebuild/toolchain.py`, `recipe_audit.py` or
`build_and_match.py`); opens, hashes or copies an executable, DLL or asset;
lists a directory recursively; intentionally follows a symbolic link or junction (reported as
`unknown`, at any checked level); reads Steam, the registry or user configuration; uses
the network; or writes anywhere except the `--out` file you name. UNC and
device paths (`\\server\share`, `\\?\`, `\\.\`, `NUL`, `COM1`, ...) and paths
containing NUL are refused before any filesystem access. Overlap checks
between locations are lexical (no link resolution), and protected paths are
compared by name only: never opened, listed or stat'ed. Because overlap checks
are lexical, a link *inside* a supplied path could hide an overlap; supplied
roots that are themselves links are reported as `unknown`.

## Usage

Run from the repository root. All paths are yours and stay private.

```powershell
# Nothing supplied: every necessary item is unknown.
python tools/runtime-readiness/readiness_check.py

# Explicit paths.
python tools/runtime-readiness/readiness_check.py `
  --installation <owned-game-data> --executable <private-built-exe> `
  --working-dir <working-directory> --isolated-profile <isolated-config-and-saves> `
  --dll-provider <verified-dll-providers> --protected-path <existing-user-config-and-saves>

# Manifest (relative paths resolve against the manifest's directory), plus
# your own requirements and an existing toolchain doctor report read as data.
python tools/runtime-readiness/readiness_check.py --manifest <private>/manifest.json `
  --requirements <private>/requirements.json --toolchain-report build/rebuild/doctor.json `
  --format json --out <private>/readiness.json
```

Command-line paths override the manifest. `--out` refuses to overwrite an
existing file (`--overwrite` is disabled), refuses links, refuses
to replace the manifest, requirements file, toolchain report or the bundled
inventory, refuses a location inside the installation, isolated profile,
working directory, executable directory, any DLL provider, any protected path
or this tool directory, and does not create directories. It checks output parents for links and creates the file exclusively. Filesystem checks are not atomic against concurrent path replacement; use a trusted, stable local tree.
`--include-local-paths` requires `--out`: local paths go only into that file,
and stdout stays redacted.

### Exit codes

| Code | Verdict | Meaning |
|---|---|---|
| 1 | `unknown` | At least one necessary input or contract is unknown. This is the expected result today. |
| 2 | — | Unusable input (bad schema, oversized or deeply nested file, unsafe path or `--out`, bad arguments). Nothing is written. |
| 3 | `not-ready` | A necessary input is missing (for example a supplied executable that does not exist), or a safety rule is violated. |
| 4 | `attested-pending-review` | Every necessary item is present or **user-attested**. Not verified, and not a launch authorization. |

No verdict exits 0, and there is no `ready` or `pass` verdict: nothing this
tool can observe proves readiness. The report always carries
`launch_authorized: false`, and `overall.counts` separates items the checker
observed from user-supplied requirements and user-attested contracts. An
executable that was not supplied gives `unknown` (with
`executable_absent: true`); one that was supplied but does not exist gives
`not-ready`.

## Reading the report

Each item has `status` (`present`, `missing` or `unknown`), `necessary`,
`basis` and `reason`. The `basis` says where a claim comes from:

| Basis | Meaning |
|---|---|
| `checker-observed` | The checker saw the metadata itself. |
| `user-supplied` | A requirement from your requirements file, carrying its provenance. |
| `user-attested` | Your statement about a contract the checker cannot observe. |
| `observed-snapshot` | A name seen in one owned installation. `necessary: false`, `confirmed_requirement: false`; a missing name never fails the check. |
| `original-import-evidence` | A DLL imported (or dynamically tried) by the original executable. Always `unknown` for the rebuild, even if the filename is found in a provider directory. |
| `none` | No evidence. |

Necessary contracts that the checker cannot observe, and that stay `unknown`
until you attest them: build gates closed, x86 Windows GUI platform, the
rebuild's own dependency set, DLL versions and exports, transitive and dynamic
loads, loader search policy, resource identity (group icon 101 and
manifest/version), config and save paths, working directory and asset lookup,
Data/add-ons/localization, Steam and ownership integration. Filenames and source
symbols never establish them.

Safety findings: `block` (makes the verdict `not-ready`) when the executable is
the original `FalloutNV.exe` (same name or same file identity) or sits inside
the installation, when the isolated profile overlaps the installation or a
protected path, or when the working directory overlaps a protected path.
`warn` when no protected path was supplied (so overlap with existing user data
could not be checked), the profile already has entries or is not writable, a
DLL provider is inside the installation, a protected path or is the working
directory, the executable is inside a protected path or the profile, or the
working directory is inside the installation.

### Requirements and attestations

See `examples/requirements.example.json`. A top-level `provenance` with
`source` and `basis` is required. Each requirement names a `role`
(`installation`, `executable_directory`, `working_directory`,
`isolated_profile` or `dll_provider`), a relative `path` of at most two levels,
a `kind` (`file` or `directory`) and optionally `min_size_bytes` or
`expected_size_bytes`. Absolute paths, `.`/`..`, wildcards, deeper paths,
unknown fields (such as an invented `version`) and missing provenance are
rejected and reported as `unknown`. Attestations must name a known contract,
include a statement and carry provenance. Only attest what you checked.

### Privacy

By default every location is a role placeholder such as `<owned-game-data>/Data/FalloutNV.esm`,
anything that looks like an absolute path in launch arguments, requirement
notes, attestation statements or provenance becomes `<redacted-path>`, error
messages (including argument errors) never contain a path, text output is
ASCII-escaped, and a final guard refuses to emit a report that contains a
supplied absolute path. `--include-local-paths` adds a
`local_detail` section and marks the report PRIVATE; keep that file outside the
repository. Toolchain report roots and banners are never copied.

## Manual smoke-test template

See [SMOKE-TEST-TEMPLATE.md](SMOKE-TEST-TEMPLATE.md). Copy the JSON record to
a private location outside the repository, fill it only while actually
performing an approved test, and validate it:

```powershell
python tools/runtime-readiness/smoke_template.py validate tools/runtime-readiness/smoke-test-template.json --template
python tools/runtime-readiness/smoke_template.py validate <private>/smoke-record.json
```

**Status: every gameplay step is `not-run`.** No build exists and no launch is authorized.

## QA

```powershell
python -m unittest discover -s tests/runtime-readiness -p "test_*.py" -v
```

The tests build tiny placeholder trees in a temporary directory. They check
verdicts and exit codes, the separation of observed evidence from
requirements, rejection of unsafe or unproven inputs, safety blocks, that the
fixture tree is byte-for-byte unchanged after a run, that no recursive listing
or game/build/provider file read happens, that metadata reads stay bounded, that
the checker imports no process, network or loader modules, and that default
reports contain no local paths.

Path checks are best-effort and are not atomic against concurrent filesystem changes. Run only on a trusted, stable local tree. Free-text path redaction is heuristic; do not put secrets, relative private paths or unexpanded environment variables in manifests or attestations.
