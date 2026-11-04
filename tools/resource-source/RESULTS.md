# Resource source: delivery results (2026-11-03)

This delivery adds only `tools/resource-source/` and `tests/resource-source/`.
It was built from the source-only handoff packet in a standalone folder, not
inside a checkout of the active branch.

Nothing in this work:

- read or created a game installation, executable, PE, `.res`, icon, XML
  manifest or other resource asset;
- ran a resource compiler, a linker or any other external program;
- used the network.

## Attribution

All of it was done by Claude Opus 5.5 (`claude-opus-5-5`) in Claude Code (the
desktop app), using file read/write/edit and shell tools: the design, the tool,
the examples, the README and the tests. No subagents were used.

## Test results

```
python -m unittest discover -s tests/resource-source -p "test_*.py" -v
```

On Python 3.12.10 under Windows 11, the result was `Ran 84 tests ... OK`. The
suite was not run on Linux or macOS.

The tests cover:

- **Positive cases.** The acceptance example, including its full output byte
  for byte. An empty list does not gain icon 101. Icons with an explicit and a
  neutral language, `default_language`, an explicit manifest reference, full
  and minimal VERSIONINFO, and both supported codepages.
- **Boundaries.** IDs, languages, version parts, flags, the resource count,
  path length and segments, and string length.
- **Determinism.** 25 random key and resource permutations, whitespace and
  type-case changes, repeatability, CRLF/ASCII/no BOM, sort order and the
  digest.
- **Rejections.**
  - Unknown and missing keys, wrong types, bool, float and string IDs, and
    non-ASCII case-folding (`Ä±con`).
  - Duplicates: exact, case-folded, unspecified versus specified language,
    collisions caused by `default_language`, two VERSIONINFO, and duplicate
    JSON keys.
  - Path escapes: `../`, `C:/`, `/`, `//`, backslash, `:`, device names and
    extensions.
  - Quote, newline, directive and expression injection in paths and strings.
  - Malformed JSON, NaN/Infinity, huge integers, BOM and non-UTF-8, oversized
    input and deep nesting.
  - VERSIONINFO conflicts.
- **CLI and files.** Exit codes. The `--out` rules: no overwrite without
  `--overwrite`, no links, directories, manifest, non-`.rc`, missing directory,
  UNC or device paths. UNC and device manifest paths are refused before any
  file access. Argument errors and diagnostics never contain the temporary
  path or the rejected value.
- **Isolation.**
  - During `render --out` and `validate`, wrappers on `open`, `os.stat`,
    `os.lstat`, `os.listdir`, `os.scandir`, `os.path.exists`, `os.path.isfile`,
    `os.path.isdir` and related calls show that no referenced path is ever
    touched.
  - The temporary folder holds only the manifest and the output afterwards.
  - The tool's imports are limited to 8 stdlib modules (`errno`, `hashlib`,
    `json`, `os`, `re`, `stat`, `sys`, `argparse`), and it has no
    process-starting, deletion or eval calls.
  - No asset files ship with the tool.
- **Documentation.** The README example matches the real output.

As a check that the tests can fail, two deliberately broken copies of the tool
were run against them:

- one that checks whether a referenced file exists;
- one that adds icon 101 to an empty list.

Each failed the matching test.

## Limitations and unresolved assumptions

1. **No resource compiler was run.** The handoff forbids it, so it is not known
   whether `rc.exe` (or another resource compiler) accepts the output.
   Specifically unverified:
   - forward slashes in file paths;
   - `LANGUAGE` with hex operands;
   - an empty `VERSIONINFO` `BEGIN`/`END` body;
   - VERSIONINFO string values without an explicit `\0`.
2. **Generating source proves nothing about the files or the program.** It
   does not show that a referenced file exists or is a valid icon or manifest,
   that icon 101 resolves at run time, or that any startup, runtime, ABI or
   provider obligation is met. No readiness result is reported.
3. **The schema is my own design.** The field names, the three supported types
   and the VERSIONINFO subset follow the handoff but are not an existing
   project format. Not supported:
   - string resource names;
   - other resource types (BITMAP, RCDATA, STRINGTABLE, DIALOG, ...);
   - multiple VERSIONINFO resources;
   - string tables in more than one language;
   - codepages other than 1200 and 1252.
4. **Strict choices that may be stricter than needed:**
   - manifest IDs are limited to 1 to 16;
   - an ICON must end in `.ico`, and a manifest in `.manifest` or `.xml`;
   - `..` is rejected anywhere in a segment;
   - spaces are rejected in paths;
   - a string `FileVersion`/`ProductVersion` must equal the numeric version as
     `a.b.c.d`;
   - `//` is rejected in string values;
   - a missing language collides with every language of the same type and id.

   Relax these only if the coordinator decides to.
5. **Language without a declaration.** A resource with no effective language
   takes whatever default the resource compiler is invoked with. The tool marks
   this in a comment and does not choose one.
6. **Output path checks are lexical where not observed.** The tool checks
   whether the `--out` file itself is a link, but not whether its parent
   directories are, and it compares the output with the manifest by path and by
   `lstat` identity. Link handling is tested with a mocked `lstat`.
7. **Platforms.** Tested only on Windows 11 with Python 3.12.10.
8. **Not done.** Integration into the branch, a ledger entry, docs links and
   any build use of the generated `.rc` file. The coordinator does these.

## Coordinator integration review

Codex added ancestor link/reparse checks for input and output paths, rejected reserved devices in every component, and changed overwrite to an exclusive sibling temporary file followed by atomic replacement, preserving hardlink peers. These checks are not atomic against concurrent replacement; use a trusted stable local directory. The historical test count above describes the submitted archive, not the coordinator post-fix run. Resource compiler acceptance and runtime behavior remain unverified.
