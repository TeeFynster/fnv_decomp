# Game runtime environment: owned inputs and unresolved contracts

This is a metadata inventory and future preparation plan, not a runnable build. The whole-game link, application startup, menu and gameplay remain unproved. A future executable must be independently built from the selected source and its own reviewed providers; the original executable remains untouched and is not a runtime provider. No game files, resource contents or personal paths belong in this repository. The repository grants no licence; see [LICENSE](../../LICENSE).

## Observed installation and scope

On 2026-11-03 the owner-specified Steam installation was inspected without running it. The original `FalloutNV.exe` is 16,549,704 bytes and has SHA-256 `3a87f92f011e5dc9179ddf733cf08be2b39ea6e5b7a8a9e3a9a72dafcc1b104d`. This identifies the inspected file, not permission to redistribute it or evidence that it is a suitable plaintext comparison image. The existing private `import-plan-native-v3.json` has SHA-256 `e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f`. Its 17 DLLs and 280 import slots agree with this file's normal PE import metadata. No delay-import directory was observed. Neither list covers transitive or runtime-selected dependencies.

Top-level installation entries and file sizes, in bytes, were observed as follows; names alone do not prove runtime use:

| Entry | Size |
|---|---:|
| `Data/`, `Redists/` | directories |
| `atimgpud.dll` | 165,304 |
| `binkw32.dll` | 338,944 |
| `ExitData.mhd` | 0 |
| `Fallout_default.ini` | 19,959 |
| `FalloutNV.exe` | 16,549,704 |
| `FalloutNV.ico` | 168,879 |
| `FalloutNVLauncher.exe` | 2,074,440 |
| `GDFFalloutNV.dll` | 1,963,176 |
| `high.ini`, `low.ini`, `medium.ini`, `VeryHigh.ini` | 1,116; 1,107; 1,115; 1,134 respectively |
| `InstallScript.vdf` | 889 |
| `libvorbis.dll`, `libvorbisfile.dll` | 1,241,528; 120,248 respectively |
| `MainTitle.wav` | 6,158,306 |
| `Readme.txt` | 4,086 |
| `steam_api.dll` | 121,984 |

The `Data/` top level contains `Music/`, `Shaders/`, `Sound/`, `Video/`; `FalloutNV.esm`, `Fallout - Meshes.bsa`, `Fallout - Misc.bsa`, `Fallout - Sound.bsa`, `Fallout - Textures.bsa`, `Fallout - Textures2.bsa`, `Fallout - Voices1.bsa`, `Update.bsa`, `Credits.txt` and `CreditsWacky.txt`. It also contains `.esm` and `.nam` files for CaravanPack, ClassicPack, DeadMoney, GunRunnersArsenal, HonestHearts, LonesomeRoad, MercenaryPack, OldWorldBlues and TribalPack; each has a ` - Main.bsa`, and DeadMoney, GunRunnersArsenal, HonestHearts, LonesomeRoad and OldWorldBlues also have a ` - Sounds.bsa`. These are a snapshot of one owned installation, including add-ons; they are not a minimum-required list. Only top-level names were enumerated: no archives or nested directories were inspected or hashed.

## Imports and dynamic loading

The inspected normal import descriptors are `COMCTL32.dll` (3 slots), `d3d9.dll` (1), `XINPUT1_3.dll` (2), `KERNEL32.dll` (138), `USER32.dll` (37), `GDI32.dll` (1), `ADVAPI32.dll` (6), `SHELL32.dll` (3), `ole32.dll` (7), `steam_api.dll` (11), `WSOCK32.dll` (21), `d3dx9_38.dll` (25), `DINPUT8.dll` (1), `WINMM.dll` (8), `DSOUND.dll` (1), `binkw32.dll` (9) and `libvorbisfile.dll` (6). These are imports of the inspected original, not a proven final link list for the rebuilt executable. Windows components, DirectX-era components and game-local vendor libraries have different acquisition and deployment requirements; availability of a filename does not prove compatible x86 architecture, exports, version, licensing or transitive dependencies. In particular, the installed `libvorbis.dll` is not a direct descriptor in this inventory; whether it is needed by another module is unverified. Use normal supported Windows and vendor mechanisms, with a private, verified dependency search policy; do not download arbitrary DLLs or assume the installation contains system components.

The bounded source evidence in [runtime audit](RUNTIME-AUDIT.md) identifies an optional graphics capability path that attempts `atiadlxx.dll`, then `atiadlxy.dll`, and resolves ADL functions dynamically. Failure is handled by that path. The observed `atimgpud.dll` filename alone does not establish a relationship to it. Other dynamic loads and dependencies are not ruled out. The application root itself has 25 distinct IAT cells in four system DLLs; their signatures and pointer indirection still require review, as described in the [entry proposal](APPLICATION-ENTRY-LINK-PROPOSAL.md).

## Resources and the new instance

The selected application source passes its first argument to `LoadIconA` with integer resource ID `0x65` (101), and uses that instance for its window class and creation. The original PE resource directory has English-US language ID 1033 entries: group icon 101, icon images 1–12, bitmap 180, version 1, manifest 1 and named RCDATA `SPAFILE`. No dialog resource entry was observed. The directory metadata alone does not establish the content, purpose, licensing, or runtime necessity of the bitmap, version, manifest or RCDATA. A rebuilt executable's own `HINSTANCE` does not inherit the old PE's resources. Its eventual resource contract must explicitly supply and test a suitable group icon 101 and dependencies, or deliberately handle its absence; verify any additional source uses and manifest/version needs separately. Do not copy or extract proprietary resource payloads into the repository. The original manifest's mere existence does not prove its settings are appropriate to a new executable.

## Future private launch preparation

Only after the source link, CRT/TLS, ABI, resource and provider gates are independently closed should a private test be planned. The tester needs a personally owned compatible installation and must keep its original executable unchanged. Identify the actual required `Data` archives, add-ons and localization for the chosen test through bounded source and runtime evidence; this inventory cannot establish completeness or language coverage. Determine the game's expected working directory, relative asset lookups, default and per-user INI locations, writable save/config locations, and first-run behavior before choosing an isolated writable test profile. `Fallout_default.ini` and quality presets are observed inputs, not proof that a new host reads them. Do not overwrite existing user configuration or saves.

Specify a private source-built executable location and an owned-data access arrangement after verifying file and directory lookup behavior. Specify x86 DLL providers, exact compatible exports and normal Windows loader search behavior, including transitive and dynamically loaded modules, before an actual launch. Keep the application directory and working directory distinct in the test record and avoid adding untrusted directories to the DLL search path. Steam availability and any ownership or integration requirements remain to be established through supported mechanisms; no credential handling, ownership attestation, protection modification, Steam stub or bypass is authorized by this plan.

A future reviewed test record should name placeholders for `<private-built-exe>`, `<owned-game-data>`, `<isolated-config-and-saves>` and `<verified-dll-providers>`, document their resolved private locations outside public artifacts, and record launch arguments, working directory, expected reads/writes and rollback steps. First prove startup and clean exit, then a responsive menu and only later a separately documented gameplay route. No command is offered yet because a linkable executable and its input contracts do not exist. This inspection made no junctions, copies, launches, or changes to the game, Steam, user configuration or worker services.

