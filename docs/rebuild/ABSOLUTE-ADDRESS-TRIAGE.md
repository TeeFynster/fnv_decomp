# Absolute-address source triage

The 88 missing COFF fields in 59 selected functions/47 units are genuine
source-level migration concerns. The bounded review found real address-valued
expressions in every case, including three fields in inlined constructors.
One minimal **proposal**, using the existing `DAT_010a2304` symbol, is supported
for a separate source-overlay experiment. No overlay, source edit, object change,
new relocation, provider definition or native execution was performed.

## Evidence and attribution limits

The input is exactly the reviewed `relocation-audit-native-v1` detail: aggregate
SHA-256 `5f667f1bb8e4471ff4111b6a2faf00d04fb35db4e362c3d30520f9c156d3a33a`,
compressed detail `8d5cb3673ae6553ff188cbabedab82490acc716d14846f5a046fe3b309a34348`.
Every row below identifies an actual original PE HIGHLOW field and the exact
selected checked COFF section/field. Its four-byte retained value was rechecked
against the owned image's corresponding operand. The 47 known source hashes
and retained objects were checked against the approved manifest. Only named
source/function/field neighborhoods were inspected; no archive search or wider
address-literal census was performed. An `@fnv` marker located the known function
for reading; neither that marker nor a matching value in a comment was accepted
as an expression. All listed statements are executable source expressions.

Private `build/rebuild/absolute-triage-evidence-v1.json` SHA-256
`4e06af226997152e1a7097e93f3b96d92804b229f97139dd21c89e249c6f5a28`
retains all 88 field identities, source lines, exact target values/PE sections,
per-unit target-name metadata where present, object/source hashes and the one
pilot. It contains metadata and source statements, no original instruction
bytes or disassembly. The earlier private `absolute-triage-raw-v1.json` is a
recoverable intermediate snapshot; three missing direct-function literal hits
were subsequently attributed to their actual inlined constructor statements.

There is no compiler debug-line proof here. The strongest cases have one real
target-valued expression in the checked function, the exact field value and
matching original relocation intent. Two AI fields share the same literal in
two call-site expressions; exact source-occurrence mapping remains unresolved.
The three constructor-inlining cases retain their outer call and inline origin.
No group assignment proves a complete target extent, storage type, provider,
ABI, initialization or lifetime. In particular, a read-only target does not by
itself establish a vtable.

## Complete bounded grouping

Roles describe what the actual expression does. “Dispatch-header candidate”
means a pointer/word installed at an object's dispatch-shaped header, **not** a
validated target table or class ABI. Function counts overlap because the single
AI thread function contains both settings reads and stored code addresses;
the union remains 59 functions. Field counts are disjoint and sum to 88.

| Actual expression role | Fields | Functions | Remaining uncertainty |
|---|---:|---:|---|
| code-address storage | 14 | 6 | Stores/casts executable-target addresses; call ABI, callback lifetime and selected function providers remain open. |
| settings-object dereference | 5 | 2 | Raw setting-object casts; complete setting type, live storage and initialization remain open. |
| object dispatch-header candidate | 41 | 33 | 41 fields include constructor, destructor/reset and allocation paths; exact table extents/slots and object ABI remain open. |
| typed constant/string address | 3 | 1 | Reads const double/float and passes const char pointer; extent/value/string identity and ownership remain open. |
| static indexed table access | 12 | 5 | Indexed reads or dispatch-table writes; array extents, index bounds, element types and initialization remain open. |
| address-shaped base/index arithmetic | 4 | 4 | Adds image-sized constants to runtime pointer/index inputs; may encode questionable recovered base/offset semantics. No symbolic rewrite is selected. |
| lock object receiver | 2 | 2 | Calls Lock through a raw receiver; lock storage, synchronization ABI and initialization remain open. |
| integer-return address | 1 | 1 | Returns an address-shaped integer; intended pointer ABI and target role remain unresolved. |
| opaque descriptor pointer/header | 2 | 2 | Initializes a stack descriptor with a read-only target; exact descriptor/table semantics remain open. |
| opaque leading-word assignment | 2 | 2 | Writes an address-shaped integer into an opaque leading word; vtable semantics remain unproved. |
| throw metadata pointer | 1 | 1 | Passes an address as _ThrowInfo; EH graph, toolchain contract and provider are unresolved. |
| byte storage initialization | 1 | 1 | Clears bytes through an absolute indexed base; range, ownership and initialization ordering remain open. |

## One proposed pilot: address-only DAT_010a2304

The selected constructor is `??0NiBackToFrontAccumulator@@QAE@XZ`, recipe
`1401-50cd6090ff456b83`, source
`src/gamebryo2.2/corelibs/nimain/nibacktofrontaccumulator.cpp:8`.
Its verified span is original symbolic address `0x00aa0fc0`, size 25, native
section 3/value 0; symbol index 8 is an EXTERNAL function definition. The actual
source statement is `*(volatile unsigned int*)this = 0x010a2304;`. Its unique
literal maps to the retained four-byte field section 3/+10, original
`0x00aa0fca`, an actual PE HIGHLOW site. Both fields contain target `0x010a2304`.
The constructor section has only the existing REL32 relocation at +4, for the
implicit base constructor; no COFF relocation covers +10.

This is more than an annotation/value coincidence: the same unit declares
`extern int DAT_010a2304;` at line 373, its recipe explicitly binds the resulting
undefined EXTERNAL `?DAT_010a2304@@3HA` (symbol index 128) to the exact target,
and a lifecycle helper already stores `(unsigned int)&DAT_010a2304` at line 422.
That helper's body was inspected for this target relationship only; its complete
behavior was not separately revalidated or approved for execution.

The owned image places the target in read-only, nonexecuting `.rdata`. A bounded
check of the target's preceding RTTI pointer and first five slots found actual
HIGHLOW entries for each. The preceding pointer identifies Complete Object
Locator `0x01127c58`, with signature/offset/cdOffset all zero, type descriptor
`0x011abf5c`, class descriptor `0x0112795c` and observed type name
`.?AVNiAccumulator@@`. The first five table-slot targets are executable.
This supports a concrete table identity, but notably **NiAccumulator** differs
from the recovered constructor class name. The source header's `novtable`
polymorphic declarations and approximate inheritance are not proof of the full
original hierarchy or slot ABI. No additional pilot was explored.

A future separately authorized overlay could include the unchanged class header,
place the existing `extern int DAT_010a2304;` declaration before this constructor,
and replace only the literal RHS with
`reinterpret_cast<unsigned int>(&DAT_010a2304)`. The volatile unsigned store,
implicit NiObject base construction and `m_pkAccumulationCamera = 0` must remain
as authored. The `int` declaration is an **address carrier**, already used by the
source, not a claim that the table is one writable int. It emits an undefined
symbol reference; it supplies no storage or table provider. No new provider or
native runtime link is proposed here.

Pinned source SHA-256 is
`36a0fde7e9010dca9552434cc5730d82657b2b37036ab57649ee523f842264e6`;
class-header SHA-256
`623ec38f6cc3c7f25952ba20191ecccc0f9b8dad17b9b66d9e6d122c82b037ec`;
retained-object SHA-256
`92507eef126a952346cccf5452fe5c204a97b18e02e7583249e41b4daa9d9570`.
The unchanged approved owned image identity remains
`df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7`.
These hashes were observed, not inferred from a function annotation.

### Minimal acceptance contract for a separately authorized experiment

1. Keep original source/header, authoritative recipes, retained objects and all
   reviewed tools/receipts immutable. Create a separate readable constructor
   overlay and a new private object; select neither for runtime by default.
2. Compile with exact existing VC9 SP1 and this recipe's unchanged `/MT /O2 /GS
   /EHsc /Gy` settings. Preserve i386 pointer/unsigned-int widths and the full
   implicit-base/member-initialization behavior; no integer byte emission,
   instruction patch, absolute-symbol definition or invented provider.
3. Require a fresh **plain original comparison** of the complete 25-byte function
   with the explicit existing target binding, using the unchanged baseline tool.
   An expected match must be observed, not assumed from this proposal.
4. Independently parse the new object. Require exactly one new DIR32 at native
   section 3/+10 (or the independently established equivalent section/value if
   object layout changes), symbol `?DAT_010a2304@@3HA` undefined EXTERNAL, zero
   addend. Preserve the original +4 REL32 target and verify all other function
   bytes/relocations and member/base effects. Fail on extra or shifted effects;
   do not edit bytes to force acceptance.
5. Hash-bind all inputs/new artifacts and have the reviewer inspect the actual
   symbolic relocation and complete comparison receipt before claiming success.
   Success proves a source-level relocation migration only. Storage extent,
   read-only protection/alignment, all vtable/RTTI pointers and slots, exact
   deleting-destructor/calling conventions, object layout, base-provider and
   initialization/lifetime/teardown closure remain unresolved. No game or
   constructor execution is allowed while those providers remain open.

## Field-by-field source ledger

The function column is the original symbolic ID used by the exact selected row;
the approved selection/proof supplies its decorated name. `S:V` identifies the
candidate section/value, and `+F` is the function-relative field offset, so the
physical COFF field is `S:(V+F)` and original HIGHLOW site is `function+F`.
Each target is the actual original/retained four-byte value, not a name guess.
Source line numbers point to actual statements; metadata/source-name bindings
alone have not been promoted to providers. Repeated settings occurrences remain
listed together rather than choosing a source occurrence by proximity.

### code-address storage

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x00afbfa0` | `6:0 +36` | `0x00afbf80` .text | `src/bssystem/archive.cpp:139` — `m_pfnRead = reinterpret_cast<void*>(0x00afbf80);` |
| `0x00afbfa0` | `6:0 +46` | `0x00aff9f0` .text | `src/bssystem/archive.cpp:140` — `m_pfnWrite = reinterpret_cast<void*>(0x00aff9f0);` |
| `0x00afc620` | `7:0 +36` | `0x00afc660` .text | `src/bssystem/archive.cpp:154` — `m_pfnRead = reinterpret_cast<void*>(0x00afc660);` |
| `0x00afc620` | `7:0 +46` | `0x00aff9f0` .text | `src/bssystem/archive.cpp:155` — `m_pfnWrite = reinterpret_cast<void*>(0x00aff9f0);` |
| `0x00aff990` | `22:0 +21` | `0x00affa10` .text | `src/bssystem/bsfile.cpp:50` — `readHandler = reinterpret_cast<void*>(0x00affa10);` |
| `0x00aff990` | `22:0 +31` | `0x00affa60` .text | `src/bssystem/bsfile.cpp:51` — `writeHandler = reinterpret_cast<void*>(0x00affa60);` |
| `0x00aff990` | `22:0 +43` | `0x00aff9d0` .text | `src/bssystem/bsfile.cpp:55` — `readHandler = reinterpret_cast<void*>(0x00aff9d0);` |
| `0x00aff990` | `22:0 +53` | `0x00aff9f0` .text | `src/bssystem/bsfile.cpp:56` — `writeHandler = reinterpret_cast<void*>(0x00aff9f0);` |
| `0x008c7290` | `6:0 +135` | `0x008c7da0` .text | `src/fallout/ai/ailineartaskthreadmanager.cpp:89` — `(AIThreadFunction)0x008c7da0, "AI Linear Task Thread 1", (BSThread::StackSize)0x10000);` |
| `0x008c7290` | `6:0 +173` | `0x008c7f50` .text | `src/fallout/ai/ailineartaskthreadmanager.cpp:91` — `(AIThreadFunction)0x008c7f50, "AI Linear Task Thread 2", (BSThread::StackSize)0x10000);` |
| `0x008c7290` | `6:0 +213` | `0x008c7bd0` .text | `src/fallout/ai/ailineartaskthreadmanager.cpp:96` — `(AIThreadFunction)0x008c7bd0, "AI Linear Task Thread", (BSThread::StackSize)0x10000);` |
| `0x00d2d9d0` | `3:0 +51` | `0x00d2d460` .text | `src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp:22` — `*(int*)((char*)pObject + 0x20) = 0xd2d460;` |
| `0x00d2d9d0` | `3:0 +65` | `0x00da6dc0` .text | `src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp:24` — `*(int*)((char*)pObject + 4) = 0xda6dc0;` |
| `0x00d21ce0` | `3:0 +10` | `0x00d21cc0` .text | `src/havok/physics/dynamics/constraint/atom/hkpconstraintatom.cpp:19` — `m_pBridge = (void*)0xd21cc0;` |

### settings-object dereference

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x008c7290` | `6:0 +110` | `0x011c3ea4` .data | `src/fallout/ai/ailineartaskthreadmanager.cpp:86` — `if (((SettingT_GameSettingCollection_*)0x011c3ea4)->Int()->value > 2)` |
| `0x008c7290` | `6:0 +140` | `0x011dfb34` .data | `src/fallout/ai/ailineartaskthreadmanager.cpp:88` — `LaunchWorkerThread(AI_THREAD_1, ((SettingT_GameSettingCollection_*)0x011dfb34)->Int()->value,`; `src/fallout/ai/ailineartaskthreadmanager.cpp:95` — `LaunchWorkerThread(AI_THREAD_1, ((SettingT_GameSettingCollection_*)0x011dfb34)->Int()->value,` |
| `0x008c7290` | `6:0 +178` | `0x011dfb18` .data | `src/fallout/ai/ailineartaskthreadmanager.cpp:90` — `LaunchWorkerThread(AI_THREAD_2, ((SettingT_GameSettingCollection_*)0x011dfb18)->Int()->value,` |
| `0x008c7290` | `6:0 +218` | `0x011dfb34` .data | `src/fallout/ai/ailineartaskthreadmanager.cpp:88` — `LaunchWorkerThread(AI_THREAD_1, ((SettingT_GameSettingCollection_*)0x011dfb34)->Int()->value,`; `src/fallout/ai/ailineartaskthreadmanager.cpp:95` — `LaunchWorkerThread(AI_THREAD_1, ((SettingT_GameSettingCollection_*)0x011dfb34)->Int()->value,` |
| `0x0084e020` | `9:0 +26` | `0x011de0a4` .data | `src/fallout/misc/saveload/bgssaveloadhistory.cpp:50` — `if (!*reinterpret_cast<unsigned char*>(reinterpret_cast<SettingT<INISettingCollection>*>(0x11de0a4)->Bool()))` |

### object dispatch-header candidate

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x009d6120` | `5:0 +12` | `0x01091a64` .rdata | `src/fallout/ai/combat/combatprocedurehidefromtarget.cpp:37` — `*reinterpret_cast<int*>(this) = 0x01091a64;` |
| `0x009e9e30` | `20:0 +12` | `0x0109297c` .rdata | `src/fallout/ai/movement/playermover.cpp:326` — `*reinterpret_cast<int*>(this) = 0x0109297c;` |
| `0x00845550` | `5:0 +25` | `0x0107ed68` .rdata | `src/fallout/misc/saveload/bgssaveloadchangesmap.cpp:10` — `*(void**)this = (void*)0x0107ED68;` |
| `0x00661d40` | `28:0 +12` | `0x01065f04` .rdata | `src/fallout_shared/facegen/bsfacegenmorphdata.cpp:400` — `*reinterpret_cast<int*>(this) = 0x01065f04;` |
| `0x006dd010` | `11:0 +12` | `0x0102583c` .rdata | `src/fallout_shared/pathfinding/navmesh.cpp:190` — `m_ppVirtualMethodTable = (void**)0x0102583c;` |
| `0x0069aee0` | `13:0 +12` | `0x0106b1a4` .rdata | `src/fallout_shared/pathfinding/navmeshinfo.cpp:247` — `vtable = (void**)0x0106b1a4;` |
| `0x0069af10` | `4:0 +12` | `0x0106b1a4` .rdata | `src/fallout_shared/pathfinding/navmeshinfo.cpp:115` — `vtable = (void**)0x0106b1a4;` |
| `0x004ff7e0` | `4:0 +12` | `0x0102583c` .rdata | `src/fallout_shared/pathfinding/pathinglocation.cpp:8` — `m_ppVirtualMethodTable = (void**)0x0102583c;` |
| `0x006dce10` | `5:0 +12` | `0x0102583c` .rdata | `src/fallout_shared/pathfinding/pathinglocation.cpp:15` — `m_ppVirtualMethodTable = (void**)0x0102583c;` |
| `0x0056e610` | `385:0 +58` | `0x0103093c` .rdata | `src/fallout_shared/tesobjectrefr.cpp:14978` — `*reinterpret_cast<void**>(this) = (void*)0x0103093c;` |
| `0x00a981a0` | `3:0 +5` | `0x010a080c` .rdata | `src/gamebryo2.2/corelibs/niconsolerenderer/niconsoletexturedata.cpp:20` — `*reinterpret_cast<void**>(pThis) = reinterpret_cast<void*>(0x010a080c);` |
| `0x00aa0fc0` | `3:0 +10` | `0x010a2304` .rdata | `src/gamebryo2.2/corelibs/nimain/nibacktofrontaccumulator.cpp:8` — `*(volatile unsigned int*)this = 0x010a2304;` |
| `0x00a89190` | `5:0 +26` | `0x0109ec0c` .rdata | `src/gamebryo2.2/corelibs/nimain/nifloatsextradata.cpp:31` — `*static_cast<void**>(p) = (void*)0x0109ec0c;` |
| `0x00a87830` | `5:0 +5` | `0x0109e984` .rdata | `src/gamebryo2.2/corelibs/nimain/niscreenelements_o2_variant.cpp:26` — `m_pVftable = (void*)0x0109e984;` |
| `0x00a60f30` | `7:0 +26` | `0x0109babc` .rdata | `src/gamebryo2.2/corelibs/nimain/nisourcecubemap.cpp:50` — `*(unsigned int*)(n) = 0x0109babc;` |
| `0x00c2d240` | `26:0 +31` | `0x010bffe4` .rdata | `src/gamebryo2.2/corelibs/niparticle/nipsyscolormodifier.cpp:229` — `*(void**)pObject = (void*)0x010bffe4;` |
| `0x00d34510` | `94:0 +147` | `0x010ceb94` .rdata | `src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp:1313` — `*(void**)agent = (void*)0x10ceb94;` |
| `0x00d34510` | `94:0 +206` | `0x010ce8b0` .rdata | `src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp:1304` — `*(void**)agent = (void*)0x10ce8b0;` |
| `0x00d34510` | `94:0 +353` | `0x010cec68` .rdata | `src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp:1278` — `*(void**)agent = (void*)0x10cec68;` |
| `0x00caa4a0` | `977:0 +146` | `0x010c5ce4` .rdata | `src/havok/physics/dynamics/world/hkpworld.cpp:14014` — `m_vtbl = (const void*)0x10c5ce4;` (inlined origin) |
| `0x00509a10` | `55:0 +73` | `0x0102814c` .rdata | `src/staging/blk_00500000_od.cpp:795` — `((void**)this)[0] = (void*)0x0102814c;` |
| `0x00509a10` | `55:0 +83` | `0x01028128` .rdata | `src/staging/blk_00500000_od.cpp:796` — `((void**)((char*)this + 0x30))[0] = (void*)0x01028128;` |
| `0x00844660` | `55:0 +12` | `0x0107ec88` .rdata | `src/staging/blk_00840000_od.cpp:748` — `m_vtbl = (int)0x0107ec88;` |
| `0x0084ba20` | `60:0 +12` | `0x0107f4e8` .rdata | `src/staging/blk_00840000_od.cpp:853` — `m_vft = (void*)0x0107f4e8;` |
| `0x009b3160` | `58:0 +63` | `0x0108f2f4` .rdata | `src/staging/blk_009a0000_od.cpp:1159` — `*(void**)((char*)this + 0) = (void*)0x0108f2f4;` |
| `0x009b3160` | `58:0 +73` | `0x0108f2e8` .rdata | `src/staging/blk_009a0000_od.cpp:1160` — `*(void**)((char*)this + 0x18) = (void*)0x0108f2e8;` |
| `0x00a409d0` | `5:0 +26` | `0x0109750c` .rdata | `src/staging/blk_00a40000_o2.cpp:37` — `*(void**)p = (void*)0x0109750c;` |
| `0x00aa8950` | `156:0 +45` | `0x010a2970` .rdata | `src/staging/blk_00aa0000_od_ob1_variant.cpp:2666` — `((int*)this)[0] = 0x010a2970;` |
| `0x00b8e020` | `42:0 +63` | `0x010b1340` .rdata | `src/staging/blk_00b80000_o2.cpp:339` — `m_vft = (void*)0x010b1340;` |
| `0x00b8e020` | `42:0 +70` | `0x010b1320` .rdata | `src/staging/blk_00b80000_o2.cpp:340` — `((int*)this)[0x1b] = (int)0x010b1320;` |
| `0x00b91680` | `112:0 +63` | `0x010b4c68` .rdata | `src/staging/blk_00b80000_o2.cpp:888` — `*(void**)((char*)this + 0x0) = (void*)0x010b4c68;` |
| `0x00b91680` | `112:0 +70` | `0x010b4c48` .rdata | `src/staging/blk_00b80000_o2.cpp:889` — `*(void**)((char*)this + 0x6c) = (void*)0x010b4c48;` |
| `0x00b93180` | `178:0 +63` | `0x010b6a40` .rdata | `src/staging/blk_00b80000_o2.cpp:1521` — `vtbl = (void*)0x010b6a40;` |
| `0x00b93180` | `178:0 +70` | `0x010b6a20` .rdata | `src/staging/blk_00b80000_o2.cpp:1522` — `((void**)((char*)this + 0x6c))[0] = (void*)0x010b6a20;` |
| `0x00c033c0` | `124:0 +12` | `0x010bc8a4` .rdata | `src/staging/blk_00c00000_o2.cpp:1469` — `*(int*)this = 0x10bc8a4;` |
| `0x00c2a2b0` | `87:0 +45` | `0x010bf0bc` .rdata | `src/staging/blk_00c20000_o2.cpp:926` — `*(int*)pObject = 0x10bf0bc;` |
| `0x00c2b720` | `19:0 +26` | `0x010bfa54` .rdata | `src/staging/blk_00c20000_o2.cpp:242` — `node->m_vftable = (void*)0x010bfa54;` |
| `0x00cb86f0` | `1612:0 +122` | `0x0102016c` .rdata | `src/staging/blk_00ca0000_o2.cpp:15949` — `vtable = (void*)0x102016c;` (inlined origin) |
| `0x00cb86f0` | `1612:0 +158` | `0x010c8914` .rdata | `src/staging/blk_00ca0000_o2.cpp:15955` — `vtable = (void*)0x10c8914;` (inlined origin) |
| `0x00d2acf0` | `385:0 +47` | `0x010ce504` .rdata | `src/staging/blk_00d20000_o2.cpp:2668` — `vtbl = (void**)0x10ce504;` |
| `0x00da0760` | `23:0 +18` | `0x010d460c` .rdata | `src/staging/blk_00da0000_o2.cpp:202` — `*(void**)((char*)pObject + 0) = (void*)0x010d460c;` |

### typed constant/string address

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x0058c550` | `7:0 +47` | `0x01032980` .rdata | `src/fallout_shared/bgscamerashot.cpp:27` — `if (Data.m_fTimeMultiplier < *reinterpret_cast<const double*>(0x01032980))` |
| `0x0058c550` | `7:0 +76` | `0x01032930` .rdata | `src/fallout_shared/bgscamerashot.cpp:29` — `Warning(reinterpret_cast<const char*>(0x01032930), GetName());` |
| `0x0058c550` | `7:0 +93` | `0x0101e2bc` .rdata | `src/fallout_shared/bgscamerashot.cpp:30` — `Data.m_fTimeMultiplier = *reinterpret_cast<const float*>(0x0101e2bc);` |

### static indexed table access

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x004a8fe0` | `23:0 +46` | `0x01188694` .data | `src/fallout_shared/bgssceneinfo.cpp:357` — `SettingT::GetCollection()->v05(*(unsigned int*)(0x01188694 + i * 0x14));` |
| `0x004a8fe0` | `23:0 +80` | `0x01188698` .data | `src/fallout_shared/bgssceneinfo.cpp:358` — `SettingT::GetCollection()->v05(*(unsigned int*)(0x01188698 + i * 0x14));` |
| `0x005f25d0` | `50:0 +36` | `0x011977e4` .data | `src/fallout_shared/tesanimgroup.cpp:428` — `return IsNine(*(int*)(GetType(ausType) * 0x24 + 0x11977e4));` |
| `0x004854e0` | `69:0 +60` | `0x01187008` .data | `src/fallout_shared/tesform.cpp:1143` — `if (apGroupFORM->flags == *(unsigned int*)(this->GetFormType() * 0xc + 0x1187008))` |
| `0x00485530` | `200:0 +56` | `0x01187008` .data | `src/fallout_shared/tesform.cpp:2609` — `apOutGroupFORM->flags = *(unsigned int*)(0x1187008 + GetFormType() * 12);` |
| `0x00a2baa0` | `43:0 +20` | `0x011f3d20` .data | `src/staging/blk_00a20000_o2.cpp:307` — `*(void**)(0x011f3d20 + idx) = (void*)FUN_00a2b6d0;` |
| `0x00a2baa0` | `43:0 +30` | `0x011f3c90` .data | `src/staging/blk_00a20000_o2.cpp:308` — `*(void**)(0x011f3c90 + idx) = (void*)FUN_00a2af70;` |
| `0x00a2baa0` | `43:0 +40` | `0x011f3c00` .data | `src/staging/blk_00a20000_o2.cpp:309` — `*(void**)(0x011f3c00 + idx) = (void*)ComputeInterpolatedPosition;` |
| `0x00a2baa0` | `43:0 +50` | `0x011f3b70` .data | `src/staging/blk_00a20000_o2.cpp:310` — `*(void**)(0x011f3b70 + idx) = (void*)FUN_00a2b130;` |
| `0x00a2baa0` | `43:0 +60` | `0x011f3ae0` .data | `src/staging/blk_00a20000_o2.cpp:311` — `*(void**)(0x011f3ae0 + idx) = (void*)IsLightEqual;` |
| `0x00a2baa0` | `43:0 +70` | `0x011f3780` .data | `src/staging/blk_00a20000_o2.cpp:312` — `*(void**)(0x011f3780 + idx) = (void*)FUN_00a2b410;` |
| `0x00a2baa0` | `43:0 +80` | `0x011f3810` .data | `src/staging/blk_00a20000_o2.cpp:313` — `*(void**)(0x011f3810 + idx) = (void*)InsertBezPosKey;` |

### address-shaped base/index arithmetic

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x00a4e0b0` | `25:0 +32` | `0x011f375e` .data | `src/gamebryo2.2/corelibs/nianimation/nitransformdata.cpp:284` — `*(char*)((char*)this + 0x1d) = a3[0x11f375e];` |
| `0x00a4e0f0` | `27:0 +32` | `0x011f3758` .data | `src/gamebryo2.2/corelibs/nianimation/nitransformdata.cpp:308` — `*(unsigned char*)((char*)this + 0x1e) = *(unsigned char*)((char*)pSource + 0x11f3758);` |
| `0x00aa4be0` | `50:0 +8` | `0x011f6370` .data | `src/staging/blk_00aa0000_od.cpp:598` — `return p[0x11f6370];` |
| `0x00aa4bf0` | `7:0 +11` | `0x011f6370` .data | `src/staging/blk_00aa0000_od.cpp:52` — `p[0x11f6370] = c;` |

### lock object receiver

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x00a80820` | `131:0 +23` | `0x011f42a0` .data | `src/gamebryo2.2/corelibs/nimain/nigeometry.cpp:67` — `((RecursiveSpinLock*)0x011f42a0)->Lock(0);` |
| `0x00a80a10` | `137:0 +261` | `0x011f42a0` .data | `src/gamebryo2.2/corelibs/nimain/nigeometry.cpp:176` — `((RecursiveSpinLock*)0x011f42a0)->Lock((const char*)shader);` |

### integer-return address

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x00cd4b50` | `11:0 +1` | `0x01268370` .data | `src/havok/common/base/math/matrix/hkmatrix3.cpp:47` — `return 0x1268370;` |

### opaque descriptor pointer/header

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x00d38ac0` | `53:0 +39` | `0x010ce81c` .rdata | `src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp:118` — `data.unk00 = 0x10ce81c;` |
| `0x00d43460` | `127:0 +39` | `0x010ce81c` .rdata | `src/havok/physics/collide/agent/miscagent/transform/hkptransformagent.cpp:1663` — `s.sectorPtrs = (void*)0x10ce81c;` |

### opaque leading-word assignment

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x00cd1eb0` | `309:0 +10` | `0x010cb1e4` .rdata | `src/havok/physics/utilities/visualdebugger/hkpphysicscontext.cpp:2007` — `unk00 = 0x010cb1e4;` |
| `0x00cbe880` | `687:0 +2` | `0x010c477c` .rdata | `src/staging/blk_00ca0000_o2.cpp:7162` — `this->m_iWordAt00 = 0x10c477c;` |

### throw metadata pointer

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x00ad5310` | `109:0 +61` | `0x01140ef8` .rdata | `src/staging/blk_00ac0000_od.cpp:3392` — `_CxxThrowException(&obj, (_ThrowInfo*)0x1140ef8);` |

### byte storage initialization

| Function | S:V +F | Raw target | Actual source statement |
|---|---|---|---|
| `0x00c3c0c0` | `35:0 +33` | `0x011f6370` .data | `src/staging/blk_00c20000_od.cpp:430` — `((unsigned char*)0x11f6370)[i] = 0;` |

## Review status

The one pilot's source/field/target and RTTI observations were independently
checked. Final review matched all 88 distinct field/function/target tuples to
the private evidence, reconciled grouping counts, checked actual hit lines and
found no standalone comment hits. It independently checked the complete raw
PE/COFF/source joins. The reviewer did not independently reconstruct every
producer-role label or inline-call provenance; those remain the explicitly
qualified source-level observations above. All runtime, provider and fixup
approval states remain false; the original 95 EH notes and absent optional
function index are preserved by the unchanged input receipts. No tests or
baseline comparisons were rerun for this read-only document task.
