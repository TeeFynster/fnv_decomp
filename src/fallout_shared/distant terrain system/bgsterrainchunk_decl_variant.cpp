#include "../../../include/BSMultiBound.h"
#include "../../../include/BGSTerrainChunkLoadTask.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiGeometryData.h"
#include "../../../include/QueuedFile.h"
#include "../../../include/QueuedFileEntry.h"
#include "../../../include/GO.h"
#include "../../../include/IOManager.h"
#include "../../../include/IOTask.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiProperty.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiTPointerMap.h"
#include "../../../include/NiRenderer.h"

// src/fallout_shared/distant terrain system/bgsterrainchunk_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006fb980: the skeleton of src/fallout_shared/distant terrain system/bgsterrainchunk.cpp
// Shared declarations now supply the corrected polymorphic bases; no private base definition remains.

// src/fallout_shared/distant terrain system/bgsterrainchunk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsterrainchunk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_006fa840_shell
{
    unsigned char GetByteAt5D();
};
struct FUN_006fb150_shell
{
    unsigned char GetByteAtOffset5C();
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_006fb6e0_shell
{
    void SetAllAppCulled();
};
struct FUN_006fb940_shell
{
    void BSShaderPPLightingProperty_SetLODTexParams(float a, float b, float c);
};
extern int _sprintf_s(char*, unsigned int, const char*, ...);
extern "C" void __cdecl UpdateListItems();
void __cdecl BGSTerrainManager_ShowMinimumDetail();
struct FakeWorld006faad0
{
    virtual const char* f0();
    virtual const char* f1();
    virtual const char* f2();
    virtual const char* f3();
    virtual const char* f4();
    virtual const char* f5();
    virtual const char* f6();
    virtual const char* f7();
    virtual const char* f8();
    virtual const char* f9();
    virtual const char* f10();
    virtual const char* f11();
    virtual const char* f12();
    virtual const char* f13();
    virtual const char* f14();
    virtual const char* f15();
    virtual const char* f16();
    virtual const char* f17();
    virtual const char* f18();
    virtual const char* f19();
    virtual const char* f20();
    virtual const char* f21();
    virtual const char* f22();
    virtual const char* f23();
    virtual const char* f24();
    virtual const char* f25();
    virtual const char* f26();
    virtual const char* f27();
    virtual const char* f28();
    virtual const char* f29();
    virtual const char* f30();
    virtual const char* f31();
    virtual const char* f32();
    virtual const char* f33();
    virtual const char* f34();
    virtual const char* f35();
    virtual const char* f36();
    virtual const char* f37();
    virtual const char* f38();
    virtual const char* f39();
    virtual const char* f40();
    virtual const char* f41();
    virtual const char* f42();
    virtual const char* f43();
    virtual const char* f44();
    virtual const char* f45();
    virtual const char* f46();
    virtual const char* f47();
    virtual const char* f48();
    virtual const char* f49();
    virtual const char* f50();
    virtual const char* f51();
    virtual const char* f52();
    virtual const char* f53();
    virtual const char* f54();
    virtual const char* f55();
    virtual const char* f56();
    virtual const char* f57();
    virtual const char* f58();
    virtual const char* f59();
    virtual const char* f60();
    virtual const char* f61();
    virtual const char* f62();
    virtual const char* f63();
    virtual const char* f64();
    virtual const char* f65();
    virtual const char* f66();
    virtual const char* f67();
    virtual const char* f68();
    virtual const char* f69();
    virtual const char* f70();
    virtual const char* f71();
    virtual const char* f72();
    virtual const char* f73();
    virtual const char* f74();
    virtual const char* f75();
    virtual const char* GetStr();
};
void BuildLodMeshPath(char* a1, FakeWorld006faad0* a2, int a3, short a4, short a5);
int __cdecl _sprintf(char*, const char*, ...);
struct FakeFab
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual const char* GetStr();
};
void __cdecl BuildLodNormalTexturePath(char* a1, FakeFab* a2, int a3, short a4, short a5);
struct FUN_006fb760_shell
{
    void BGSTerrainChunk_Show();
};
void __cdecl _Deallocate(void*);
struct FUN_006fbfe0_shell
{
    unsigned int GetFlagOrValue();
};
class BSSoundHandle;
extern IOManager* DAT_01202d98;
struct FakeObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetStr();
};
int __cdecl _sprintf(char*, const char*, ...);
void __cdecl BuildLODDiffuseTexturePath(char* buf, FakeObj* obj, int level, short x, short y);
struct GO;
struct FUN_006fea10_Class
{
    unsigned char BGSTerrainNode_CheckMeshSolidUnderMe(bool);
};
struct SoundListView
{
    bool _ref_008256d0();
    GO** _ref_006815c0();
    SoundListView* _ref_00726070();
};
extern SoundListView g_011d8624;
void UpdateSoundListItems();
struct ModelLoader
{
    void QueueModelFilePath(const char*, int, QueuedFile*);
};
struct FUN_0043cc60_shell
{
    int IOTask_GetIOTaskPriority();
};
extern ModelLoader* g_modelLoader;
void __cdecl BuildLODDiffuseTexturePath(char*, FakeObj*, int, short, short);
extern "C" char DAT_011d85ec;
// NiPoint3: FUN_00439680 at 0x00439680 takes const NiPoint3& in Bound and bgsautowater.
struct FUN_0043d410
{
    int a, b, c;
    FUN_0043d410(float, bool, bool);
};
struct TESObjectDoorController
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct Obj006fac;
struct Ref006fac
{
    Obj006fac* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void*);
    int data;
};
struct Obj006fac
{
    Obj006fac* Modelloader_GetReferencedThis();
    Obj006fac* BGSTerrainManager_GetLODLandRoot();
    Obj006fac* FUN_006629f0();
    Obj006fac* NiObjectNET_GetControllers();
    NiPoint3& GetOffsetC();
    NiPoint3& FUN_00500940();
    float GetFieldCC();
    void FUN_00439920(void*);
    void UpdateProperties();
    void NiAVObject_Update(const FUN_0043d410&);
    unsigned char GetByteAtOffset5C();
    unsigned char GetByteAt5D();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void attach(Obj006fac*, int);
};
struct FUN_00c37ec0 : TESObjectDoorController
{
    int pad[8];
    FUN_00c37ec0();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void position(const NiPoint3&);
    void BSMultiBound_SetHalfExtents(const NiPoint3&);
};
struct FUN_00c46970 : TESObjectDoorController
{
    int pad[45];
    FUN_00c46970();
};
struct Target006fac
{
    Obj006fac* root;
    Ref006fac r4, r8, rc, r10, r14, r18;
    int p1c, p20, p24;
    unsigned char enabled, done;
    void BGSTerrainChunk_Attach();
    Obj006fac* Modelloader_GetReferencedThis();
    void UpdateWaterReferences(int);
    void BGSTerrainChunk_InitializeShaderProperty();
    void AddSelfToList();
    void SetAllAppCulled();
};
struct B5D0Status
{
    unsigned char GetByteAtOffset5C();
};
struct B5D0Item
{
    B5D0Status* Modelloader_GetReferencedThis();
    void BGSTerrainChunk_Show();
    void SetAllAppCulled();
};
struct B5D0List
{
    bool FUN_008256d0();
    B5D0Item** FUN_006815c0();
    B5D0List* FUN_00726070();
};
void __cdecl UpdateListItems();
struct PropState
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void* v70(NiGeometry*, NiProperty*);
};
int NiShadeProperty_GetType();
void __cdecl FUN_00b57e30(NiGeometry*, int, int);
NiRenderer* NiXenonRenderer_GetRenderer();
class TerrainChunk
{
  public:
    int unk00;
    NiPointer<NiGeometry> m_spGeom;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    short unk28;
    bool m_bFlag;
    char unk2B;
    NiPointer<NiNode> m_spProperty;

    void BGSTerrainChunk_InitializeShaderProperty();
};
struct LoadedNode
{
    void AssignFixedString(const NiFixedString&);
};
struct NodeRef
{
    LoadedNode* m_ptr;
    LoadedNode* Get() const;
    NodeRef& operator=(void*);
};
struct FinalObject
{
    void BGSTerrainChunk_OnLoadFinished();
};

void BuildLodMeshPath(char*, TESWorldSpace*, int, short, short);
// @fnv 0x006fb980
BGSTerrainChunkLoadTask::BGSTerrainChunkLoadTask(void* block, TESWorldSpace* space, int x, int y, int level)
    : QueuedFileEntry(3), unk30(false), iX(x), iY(y), iLevel(level), owner(block), world(space), unk48(0), unk4c(0),
      unk50(0), unk54(0), unk58(false)
{
    char fileName[260];
    BuildLodMeshPath(fileName, world, level, (short)x, (short)y);
    SetFileName_00c3cee0(fileName + 5);
    LookupFileEntryByArchive(0);
}
