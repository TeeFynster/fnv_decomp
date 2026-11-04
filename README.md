# FNV decompilation

The decompilation of FNV, the Steam release for PC (version 1.4.0.525): C++ source code rebuilt function by function
from the game's executable. Built with the compilers the game was built with, every function listed in
`build/units.json` compiles to the same bytes as the original.

The project was spearheaded on [fnvdecomp.com](https://fnvdecomp.com), where a frozen version of the community
project stays online.

- **What it is for.** The modding community has kept working on FNV for more than a decade. This repository is meant
  for that community: for research, modding and game preservation, and only those purposes.
- **Source code only.** It contains no game files, no assets, no executables and nothing you can play, and nothing
  of the game is distributed here.
- **You need the game.** To use any of this you need to own the Steam version of FNV (1.4.0.525).
- **Trademarks** belong to their holders, listed under [Legal](#legal). This project is not affiliated with or
  endorsed by any of them.

## Contributing

Pull requests are welcome from anyone. Most of what is left is readability: many functions still have placeholder
names (`FUN_00xxxxxx`), vague names or no comment, and all of that can be improved without changing a single byte of
the output.

### The automatic check

Every pull request gets an automatic check, called `match`. It runs on GitHub's machines, involves no part of the
game, and has to pass before a pull request can be merged:

1. It finds the translation units your change can affect: the files you changed and every unit that includes them.
2. It builds each of those units twice, from `main` and with your change, with the Microsoft compilers the game was
   built with.
3. Every function has to come out identical: the same code bytes, and every call and data reference resolving to
   the same original address through `build/units.json`, exception-handling code included. `main` matches the game
   byte for byte, so a change that passes still does.

What to expect:

- **Passes:** renaming functions, parameters, variables, types and fields; adding or improving comments;
  reformatting. A change only to comments, spacing or blank lines passes without a build.
- **Fails:** anything that changes what a function compiles to. The check lists the functions that differ by
  address; see what differs with your own copy of the game:
  `python3 tools/build_and_match.py --image <your FalloutNV.exe> --only <unit>`.
- **Needs a maintainer:** changes outside `src/`, `include/`, the names in `build/units.json` and Markdown files
  (the tools, the rest of the build recipe, the workflow). The check fails on these; open an issue instead. Changes
  to the tools and the workflow are made by the repository owner and verified against the game.

### Review and merging

A pull request is merged when the check passes and two reviewers have approved it:

- Nobody can skip the check, the repository owner included.
- Two approvals are needed. An approval is dropped when new commits arrive, and the last push has to be approved by
  someone other than the person who made it.
- The pull request has to be up to date with `main`. If `main` moves first, use "Update branch" and the check runs
  again on the combined code.

After every change to `main`, the whole of `main` is also built against the game's executable on the project's own
machine. That build proves `main` still matches the game byte for byte, not only that it compiles the same as
before.

### Renaming a function

`build/units.json` lists every function by its original address and its decorated (mangled) name. When you rename a
function, put its new decorated name at the same address, in every unit that lists it; otherwise the check reports
the old name as unbound. Adding a declaration or a string literal can renumber the compiler's string labels
(`$SG...`) that `build/units.json` names; the check says so when that is the cause.

A unit may also give an address it refers to a further name, as long as `build/units.json` already has that address.
Identical code that the linker folded has one address and several names, for example one template instantiated for
several types. An address that `build/units.json` does not have yet needs a maintainer. Exception-handling code
resolves names through the whole of `build/units.json`, so when a pull request changes any names there, the check
also rebuilds every unit with exception-handling code. That adds a few minutes.

### Never include any part of the game

No executable, no bytes copied from it, no object files built from this code, no game data. A pull request that
contains any of it is closed.

### Running the check yourself

With the compilers set up (see "What you need"), commit your change, then compare it with `main`:

    git fetch origin
    git worktree add --detach ../fnv-main origin/main      # main, to compare against
    git worktree add --detach ../fnv-scratch HEAD          # a scratch checkout the check builds in
    python3 tools/compare_builds.py plan ../fnv-main . --out ../plan.json --max-shards 1
    python3 tools/compare_builds.py shard ../fnv-scratch "$(git rev-parse origin/main)" "$(git rev-parse HEAD)" \
        --plan ../plan.json --shard 0 --out ../result.json
    python3 tools/compare_builds.py report --plan ../plan.json ../result.json

When `plan` reports no units to build, skip `shard` and run `report` without `../result.json`.

## Status

- Functions in scope: 70,611 of 70,611 match byte for byte.
- Bytes in scope: 11,537,067 of 11,537,067.

"In scope" leaves out code the compiler and linker generate on their own (runtime stubs, thunks, padding) and a small
list of entries in the executable that are not functions.

## What this is, and what it is not

- It is a reference: readable C++ that shows how the game works, and that reproduces the original machine code.
- It is not a port, a source port or a replacement executable. Building it gives you object files to compare, not a
  game.
- It does not contain, and will not accept, tools or instructions for getting around the game's copy protection.
- It does not contain any part of the game's executable or data files. Addresses, function sizes and a few SHA-256
  fingerprints are the only facts about the executable in this repository.

## Names and comments

The function comments were written by machine: Qwen 27B proposed them from the matched code, and Codex Luna and
Claude Sonnet reviewed them. The text is kept as reviewed. Many function, parameter and variable names were proposed by
machine as well. Every such change was rebuilt and compared, so none of it changes a single byte of the output. The comments describe
what the code appears to do and can be wrong; the machine code is the authority. Corrections are welcome.

## What you need

1. **The game.** A legally owned copy of FNV for PC, version 1.4.0.525 (on Steam, app 22380, base game
   or Ultimate Edition).
2. **The plain executable of that version, from your own copy.** The comparison reads the original machine code. The
   Steam file as installed does not work: its code is encrypted on disk. This repository does not supply the
   executable, any part of it, or any way to produce it. Never share yours.
3. **Python 3.10 or newer.**
4. **Microsoft's compilers**, from Microsoft's own downloads (none are included here):
   - Visual C++ 2008 Express Edition with SP1 (cl 15.00.30729.01): almost every unit.
   - Visual C++ 2008 Express Edition, original release (cl 15.00.21022.08): the units `build/units.json` marks
     `"compiler": "rtm"` (the game itself was built with this one).
   - Visual C++ 2005 SP1 (cl 14.00.50727.762), from the Windows SDK for Windows Vista (February 2007 Update): the
     units marked `"compiler": "vc8"`.

   On Windows, install them. On Linux and macOS they run under Wine; see "Compilers without Windows" below.

## Build and compare

    export FNV_MSVC9_ROOT=/path/to/msvc9          # folder with VC/ and SDK/ (2008 SP1)
    export FNV_MSVC9_RTM_ROOT=/path/to/msvc9rtm   # 2008 original release
    export FNV_MSVC8_ROOT=/path/to/msvc8          # 2005 SP1
    export FNV_MSVC9_PREFIX=/path/to/wineprefix   # not needed on Windows

    python3 tools/build_and_match.py --image /path/to/your/FalloutNV.exe

The image is checked first against a few fingerprints; nothing runs on any other file. Every unit is then compiled
and every function compared, relocations included. The result is a count of matching functions and bytes, and a list
of anything that does not match. `--only <text>` builds the units whose path contains the text, `--jobs N` sets how
many compile at once, and `--out results.json` writes the per-unit results (addresses and counts only, never bytes of
your executable).

A full run compiles about 2,988 units; expect it to take a while.

## Layout

| Path | What it holds |
|---|---|
| `src/` | The game's code and the libraries linked into it, as C++ translation units. |
| `include/` | Shared headers. |
| `third_party/zlib-1.2.1/` | zlib 1.2.1 under its own licence, with the game's changes to `inflate.c`; see `third_party/README.md`. |
| `patches/` | The game's changes to `inflate.c` as a diff against the official zlib file. |
| `build/units.json` | The build recipe: for each unit its source, compiler, flags and the functions it must reproduce. |
| `build/image_check.json` | SHA-256 fingerprints of a few functions, used to recognise the right executable. |
| `tools/` | The compiler wrapper, the COFF/PE comparison, `build_and_match.py` and `compare_builds.py` (the pull request check, see [Contributing](#contributing)). |
| `.github/` | The automatic check on pull requests. |

Some units appear in more than one variant (for example `*_ob1_variant.cpp`): the original was built with different
optimisation settings in different places, and each variant reproduces the functions built with its settings.

## Compilers without Windows

The compilers run under Wine (tested on Ubuntu 24.04 with Wine 9). No installer is needed: unpack the Express ISO
with 7-Zip, cabextract and msitools, and point `FNV_MSVC9_ROOT` at a folder holding `VC/` and `SDK/`:

    ISO=VS2008ExpressWithSP1ENUX1504728.iso; R=$PWD/msvc9
    7z x -y -otc "$ISO" VCExpress
    cabextract -q -d tc/ixp tc/VCExpress/Ixpvc.exe && (cd tc/ixp && msiextract -C ../vcx vs_setup.msi >/dev/null)
    V="tc/vcx/Program Files/Microsoft Visual Studio 9.0"; mkdir -p "$R"
    cp -r "$V/VC:Vc7" "$R/VC"
    for f in mspdb80.dll msobj80.dll mspdbcore.dll mspdbsrv.exe; do find "$V/Common7" -iname "$f" -exec cp {} "$R/VC/bin/" \; ; done
    cabextract -q -d tc/sdkx tc/VCExpress/WCU/WinSDK/WinSDK_Build.exe
    (cd tc/sdkx && msiextract -C ../sdko VistaClientHeadersLibs-x86.msi >/dev/null)
    S="tc/sdko/SOURCEDIR/Program Files/Microsoft SDKs:./Windows:./v6.0A:."; mkdir -p "$R/SDK"
    cp -r "$S/Include" "$R/SDK/Include"; cp -r "$S/Lib" "$R/SDK/Lib"

The original-release ISO (`VS2008ExpressENUX1397868.iso`) unpacks the same way into its own folder; reuse the SP1
`SDK/` folder for it. For Visual C++ 2005 SP1, unpack the `WinSDKCompiler-x86.msi` of the Windows SDK for Windows Vista
(February 2007 Update) and copy its `Bin`, `INCLUDE` and `LIB` folders to `VC/bin`, `VC/include` and `VC/lib`, reuse
the SP1 `SDK/` folder, and put the VC 2005 runtime DLLs next to `cl.exe` as the private assembly it asks for.

## Credits

This was a community effort, coordinated on [fnvdecomp.com](https://fnvdecomp.com). Contributors who chose to be named are listed in
`CREDITS.md` and as co-authors of the first commit.

## Legal

Fallout, Fallout: New Vegas, Bethesda, Bethesda Softworks and
ZeniMax are trademarks or registered trademarks of ZeniMax Media Inc., a Microsoft company, in the U.S. and/or other
countries. The game was developed by Obsidian Entertainment and published by Bethesda Softworks. Steam is a trademark
of Valve Corporation. The libraries linked into the game belong to their owners: Gamebryo (Gamebase Co., Ltd.), Havok
(Microsoft), SpeedTree (Interactive Data Visualization, Inc., part of Unity) and FaceGen (Singular Inversions Inc.);
zlib is by Jean-loup Gailly and Mark Adler. All other trademarks belong to their respective holders. This project is
not affiliated with or endorsed by any of them.

You need your own legally obtained copy of the game, and you are responsible for following its licence terms and the
law where you live.

If you hold rights in this material and want something changed or removed, write to contact@fnvdecomp.com. We will
respond promptly and comply.

No licence is granted for this repository; see `LICENSE`. `third_party/` keeps its own licence.
