
// src/fallout_shared/distant terrain system/bgsterrainchunk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsterrainchunk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BGSTerrainChunkLoadTask.h"
#include "../../../include/BSMultiBound.h"
#include "../../../include/GO.h"
#include "../../../include/IOManager.h"
#include "../../../include/IOTask.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiGeometryData.h"
#include "../../../include/NiProperty.h"
#include "../../../include/NiRenderer.h"
#include "../../../include/NiTPointerMap.h"
#include "../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../../include/QueuedFile.h"
#include "../../../include/QueuedFileEntry.h"

struct FUN_006fa840_shell
{
    unsigned char GetByteAt5D();
};

// @fnv 0x006fa840
unsigned char FUN_006fa840_shell::GetByteAt5D()
{
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x5d);
}

struct FUN_006fb150_shell
{
    unsigned char GetByteAtOffset5C();
};

// @fnv 0x006fb150
unsigned char FUN_006fb150_shell::GetByteAtOffset5C()
{
    return ((unsigned char*)this)[0x5c];
}

struct Flt
{
    operator unsigned int() const;
};

struct FUN_006fb6e0_shell
{
    void SetAllAppCulled();
};

// For each of the three pointers at offsets 4, 8 and 12, if non-null, calls SetAppCulled(true) on it.
// @fnv 0x006fb6e0
void FUN_006fb6e0_shell::SetAllAppCulled()
{
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 4)->operator unsigned int())
        reinterpret_cast<NiAVObject*>(
            reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 4)->operator unsigned int())
            ->SetAppCulled(true);
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 8)->operator unsigned int())
        reinterpret_cast<NiAVObject*>(
            reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 8)->operator unsigned int())
            ->SetAppCulled(true);
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 12)->operator unsigned int())
        reinterpret_cast<NiAVObject*>(
            reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 12)->operator unsigned int())
            ->SetAppCulled(true);
}

// This terrain property operation is not declared on the shared NiProperty base.
// Keep its declaration here without duplicating any shared class layout.
struct TerrainChunkProperty : NiProperty
{
    void BSShaderPPLightingProperty_SetLODTexParams(float a, float b, float c);
};

// Stores the three float arguments at offsets 0xf0, 0xf4 and 0xf8 of this object.
// @fnv 0x006fb940
// src: COMMUNITY 0x006fb940
void TerrainChunkProperty::BSShaderPPLightingProperty_SetLODTexParams(float a, float b, float c)
{
    *(float*)((char*)this + 0xf0) = a;
    *(float*)((char*)this + 0xf4) = b;
    *(float*)((char*)this + 0xf8) = c;
}

extern int _sprintf_s(char*, unsigned int, const char*, ...);

// Formats the chunk's X, Y and level into apDescription using _sprintf_s and returns true.
// @fnv 0x006fc400
// src: XBOX_PDB 0x006fc400
bool BGSTerrainChunkLoadTask::GetDescription_006fc400(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "Terrain LOD Task for chunk ( %i, %i ) at level ( %i )", this->iX, this->iY,
               this->iLevel);
    return true;
}

extern "C" void __cdecl UpdateListItems();

// @fnv 0x006fd1a0
// src: COMMUNITY 0x006fd1a0
void __cdecl BGSTerrainManager_ShowMinimumDetail()
{
    UpdateListItems();
}

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
// @fnv 0x006faad0
void BuildLodMeshPath(char* pcBuffer, FakeWorld006faad0* a2, int iLevel, short sX, short sY)
{
    _sprintf_s(pcBuffer, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\%s.Level%i.X%i.Y%i.NIF", a2->GetStr(), a2->GetStr(),
               iLevel, sX, sY);
}

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
// Formats a landscape LOD normal-map .dds path from a2's string, level a3 and coordinates a4/a5 into buffer a1.
// @fnv 0x006fab70
void __cdecl BuildLodNormalTexturePath(char* pBuffer, FakeFab* pNameSource, int iLevel, short iX, short iY)
{
    _sprintf(pBuffer, "Data\\Textures\\Landscape\\LOD\\%s\\Normals\\%s.n.Level%i.X%i.Y%i.dds", pNameSource->GetStr(),
             pNameSource->GetStr(), iLevel, iX, iY);
}

struct FUN_006fb760_shell
{
    void BGSTerrainChunk_Show();
};
// For each of the three object pointers at offsets 4, 8 and 12, if non-null, calls SetAppCulled(false) on it.
// @fnv 0x006fb760
// src: COMMUNITY 0x006fb760
void FUN_006fb760_shell::BGSTerrainChunk_Show()
{
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 4)->operator unsigned int())
        reinterpret_cast<NiAVObject*>(
            reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 4)->operator unsigned int())
            ->SetAppCulled(false);
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 8)->operator unsigned int())
        reinterpret_cast<NiAVObject*>(
            reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 8)->operator unsigned int())
            ->SetAppCulled(false);
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 12)->operator unsigned int())
        reinterpret_cast<NiAVObject*>(
            reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 12)->operator unsigned int())
            ->SetAppCulled(false);
}

struct FUN_006fbcd0_shell
{
    void QueuedFile_Cancel(int a, int b);
    void SetFlagAndCall(int a, int b);
};
// Sets the bool at offset 0x58 to true, then forwards both arguments to FUN_00c3cb70.
// @fnv 0x006fbcd0
void FUN_006fbcd0_shell::SetFlagAndCall(int aiArg1, int aiArg2)
{
    *(bool*)((char*)this + 0x58) = true;
    QueuedFile_Cancel(aiArg1, aiArg2);
}

struct FUN_006fbfe0_shell
{
    unsigned int GetFlagOrValue();
};
// Returns 1 if the byte at offset 0xcd is set, otherwise returns the unsigned int at offset 0xc8.
// @fnv 0x006fbfe0
unsigned int FUN_006fbfe0_shell::GetFlagOrValue()
{
    return ((unsigned char*)this)[0xcd] ? 1 : *(unsigned int*)((char*)this + 0xc8);
}

class BSSoundHandle;
extern IOManager* DAT_01202d98;
struct FUN_006f7140_shell : IOTask
{
    char _pad[0x30 - sizeof(IOTask)];
    bool b30;
    void ProcessTask();
};
// If FUN_0043caa0 succeeds and b30 is set, calls vfn_48 on DAT_01202d98 when the map is empty, otherwise calls NotifyParents.
// @fnv 0x006f7140
void FUN_006f7140_shell::ProcessTask()
{
    if (QueuedFile_GetAllChildrenFinished())
    {
        if (b30)
        {
            if (reinterpret_cast<NiTPointerMap<unsigned int, BSSoundHandle*>*>(this)->IsEmpty())
                DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(this));
            else
                NotifyParents();
        }
    }
}

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
// Formats a landscape LOD diffuse texture path from the object's string, level, and X/Y coordinates into buf.
// @fnv 0x006fab20
void __cdecl BuildLODDiffuseTexturePath(char* pBuffer, FakeObj* obj, int level, short x, short y)
{
    _sprintf(pBuffer, "Data\\Textures\\Landscape\\LOD\\%s\\Diffuse\\%s.n.Level%i.X%i.Y%i.dds", obj->GetStr(),
             obj->GetStr(), level, x, y);
}

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

// Walks the sound list view, and for each entry calls SetAllAppCulled if its checks pass, otherwise FUN_006fb760.
// @fnv 0x006fb640
void UpdateSoundListItems()
{
    SoundListView* current = &g_011d8624;
    {
        GO* go;
        while (current != 0 && !current->_ref_008256d0())
        {
            go = current->_ref_006815c0()[0];
            if (((FUN_006fb150_shell*)static_cast<const GO*>(go)->operator unsigned int())->GetByteAtOffset5C() &&
                ((FUN_006fa840_shell*)static_cast<const GO*>(go)->operator unsigned int())->GetByteAt5D() && static_cast<FUN_006fea10_Class*>(go->m_pObject)->BGSTerrainNode_CheckMeshSolidUnderMe(false))
            {
                ((FUN_006fb6e0_shell*)go)->SetAllAppCulled();
            }
            else
            {
                ((FUN_006fb760_shell*)go)->BGSTerrainChunk_Show();
            }
            current = current->_ref_00726070();
        }
    }
}

struct ModelLoader
{
    void QueueModelFilePath(const char*, int, QueuedFile*);
};

// Operations absent from the shared task interface; no additional object layout.
struct TerrainChunkTaskOperations : BGSTerrainChunkLoadTask
{
    void LoadTerrainChunkTextures();
    void UpdateTerrainLODNames();
};

extern ModelLoader* g_modelLoader;

void __cdecl BuildLODDiffuseTexturePath(char*, FakeObj*, int, short, short);

// Builds diffuse and normal texture file names from the chunk's level and coordinates, queues both with g_modelLoader, sets a flag at offset 0x30 and calls f10.
// @fnv 0x006fbbd0
void TerrainChunkTaskOperations::LoadTerrainChunkTextures()
{
    char pdiffuseTextureFileName[260];
    char pnormalTextureFileName[260];

    BuildLODDiffuseTexturePath(
        pdiffuseTextureFileName,
        reinterpret_cast<FakeObj*>(world), iLevel,
        static_cast<unsigned short>(iX), static_cast<unsigned short>(iY));

    g_modelLoader->QueueModelFilePath(pdiffuseTextureFileName,
                                      reinterpret_cast<IOTask*>(this)->IOTask_GetIOTaskPriority(),
                                      reinterpret_cast<QueuedFile*>(this));

    BuildLodNormalTexturePath(
        pnormalTextureFileName,
        reinterpret_cast<FakeFab*>(world), iLevel,
        static_cast<unsigned short>(iX), static_cast<unsigned short>(iY));

    g_modelLoader->QueueModelFilePath(pnormalTextureFileName,
                                      reinterpret_cast<IOTask*>(this)->IOTask_GetIOTaskPriority(),
                                      reinterpret_cast<QueuedFile*>(this));

    unk30 = true;

    OnChildCompletion();
}

// The shared ChunkPtr has no reset operation; retain only that operation's view.
struct TerrainChunkNodeReference
{
    void Reset(int aiValue);
};

// @fnv 0x006fbb10
BGSTerrainChunkLoadTask::~BGSTerrainChunkLoadTask()
{
    reinterpret_cast<TerrainChunkNodeReference*>(&unk48)->Reset(0);
    reinterpret_cast<TerrainChunkNodeReference*>(&unk4c)->Reset(0);
    reinterpret_cast<TerrainChunkNodeReference*>(&unk50)->Reset(0);
}

extern "C" char DAT_011d85ec;
struct FUN_0043d410
{
    int a, b, c;
    FUN_0043d410(float, bool, bool);
};
struct TESObjectDoorController
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
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
// @fnv 0x006facb0
// src: COMMUNITY 0x006facb0
void Target006fac::BGSTerrainChunk_Attach()
{
    if (enabled && !done)
    {
        FUN_00c37ec0* p = 0;
        ++*(int*)&DAT_011d85ec;
        if (r10.Modelloader_GetReferencedThis())
        {
            Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->BGSTerrainManager_GetLODLandRoot()->attach(r10.Modelloader_GetReferencedThis(), 1);
            Obj006fac* i = r10.Modelloader_GetReferencedThis()->FUN_006629f0()->NiObjectNET_GetControllers();
            NiPoint3 s = i->GetOffsetC();
            NiPoint3 eb = i->FUN_00500940();
            BSMultiBound* f;
            p = new FUN_00c37ec0;
            s.z = root->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->GetFieldCC();
            eb.z = 0.0f;
            p->position(s);
            p->BSMultiBound_SetHalfExtents(eb);
            r14.FUN_0066b0d0(new FUN_00c46970);
            f = new BSMultiBound;
            f->BSMultiBound_SetShape(p);
            r14.Modelloader_GetReferencedThis()->FUN_00439920(f);
            p = new FUN_00c37ec0;
            s.z = root->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->GetFieldCC();
            eb.z = 0.0f;
            p->position(s);
            p->BSMultiBound_SetHalfExtents(eb);
            r18.FUN_0066b0d0(new FUN_00c46970);
            f = new BSMultiBound;
            f->BSMultiBound_SetShape(p);
            r18.Modelloader_GetReferencedThis()->FUN_00439920(f);
        }
        else
        {
            Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->BGSTerrainManager_GetLODLandRoot()->attach(r4.Modelloader_GetReferencedThis(), 1);
        }
        r4.Modelloader_GetReferencedThis()->UpdateProperties();
        FUN_0043d410 a(0.0f, false, false);
        r4.Modelloader_GetReferencedThis()->NiAVObject_Update(a);
        UpdateWaterReferences(0);
        FUN_0043d410 h(0.0f, false, false);
        Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->BGSTerrainManager_GetLODLandRoot()->NiAVObject_Update(h);
        BGSTerrainChunk_InitializeShaderProperty();
        AddSelfToList();
        done = 1;
        if (root->GetByteAtOffset5C() && root->GetByteAt5D())
            SetAllAppCulled();
    }
}

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
// Walks the list from g_011d8624, and for each item calls FUN_006fb760 if its status check passes, otherwise SetAllAppCulled.
// @fnv 0x006fb5d0
void __cdecl UpdateListItems()
{
    B5D0List* node = reinterpret_cast<B5D0List*>(&g_011d8624);
    while (node && !node->FUN_008256d0())
    {
        B5D0Item* item = *node->FUN_006815c0();
        if (item->Modelloader_GetReferencedThis()->GetByteAtOffset5C())
        {
            item->BGSTerrainChunk_Show();
        }
        else
        {
            item->SetAllAppCulled();
        }
        node = node->FUN_00726070();
    }
}

class NiNode;

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

// If not yet flagged and m_spGeom is set, configures its property, geometry data and renderer state, stores the property in m_spProperty and sets m_bFlag.
// @fnv 0x006fb7e0
// src: COMMUNITY 0x006fb7e0
void TerrainChunk::BGSTerrainChunk_InitializeShaderProperty()
{
    if (!m_bFlag)
    {
        if (m_spGeom)
        {
            NiProperty* prop = ((NiGeometry*)m_spGeom)->GetProperty(static_cast<unsigned int>(NiShadeProperty_GetType()));
            prop->BSShaderProperty_SetFlag(0x21, 1);
            reinterpret_cast<TerrainChunkProperty*>(prop)->BSShaderPPLightingProperty_SetLODTexParams(0.0f, 0.0f, 1.0f);
            FUN_00b57e30(m_spGeom, 0, 0);
            m_spProperty = (NiNode*)prop;
            ((NiGeometry*)m_spGeom)->GetModelData()->SetByteAtOffset38(0);
            ((NiGeometry*)m_spGeom)->GetModelData()->FUN_00a67050(0x4000);
            ((NiGeometry*)m_spGeom)->GetModelData()->FUN_004410f0(1);
            NiXenonRenderer_GetRenderer()->PrecacheGeometry(m_spGeom, 0, 0, static_cast<NiD3DShaderDeclaration*>(reinterpret_cast<PropState*>(((NiGeometry*)m_spGeom)->GetGeometryShaderObject())->v70(m_spGeom, prop)));
            NiXenonRenderer_GetRenderer()->NiDX9Renderer_PerformPrecache();
            m_bFlag = true;
        }
    }
}

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
// @fnv 0x006fc020
void TerrainChunkTaskOperations::UpdateTerrainLODNames()
{
    if (reinterpret_cast<NodeRef*>(&unk48)->Get())
    {
        if (!unk58)
        {
            char szFile[260];
            _sprintf(szFile, (const char*)NiFixedString("Terrain LOD | Level %i | Cells (%i,%i)-(%i,%i)"), iLevel, iX,
                     iY, iX + iLevel - 1, iY + iLevel - 1);
            reinterpret_cast<NodeRef*>(&unk48)->Get()->AssignFixedString(NiFixedString(static_cast<const char*>(szFile)));
            if (reinterpret_cast<NodeRef*>(&unk4c)->Get())
            {
                _sprintf(szFile, (const char*)NiFixedString("Water LOD | Level %i | Cells (%i,%i)-(%i,%i)"), iLevel, iX,
                         iY, iX + iLevel - 1, iY + iLevel - 1);
                reinterpret_cast<NodeRef*>(&unk4c)->Get()->AssignFixedString(NiFixedString(static_cast<const char*>(szFile)));
            }
            if (reinterpret_cast<NodeRef*>(&unk50)->Get())
            {
                _sprintf(szFile, (const char*)NiFixedString("Water LOD w/ refl.) | Level %i | Cells (%i,%i)-(%i,%i)"),
                         iLevel, iX, iY, iX + iLevel - 1, iY + iLevel - 1);
                reinterpret_cast<NodeRef*>(&unk50)->Get()->AssignFixedString(NiFixedString(static_cast<const char*>(szFile)));
            }
            reinterpret_cast<FinalObject*>(owner)->BGSTerrainChunk_OnLoadFinished();
        }
        else if (unk58)
        {
            *reinterpret_cast<NodeRef*>(&unk48) = (void*)0;
            *reinterpret_cast<NodeRef*>(&unk4c) = (void*)0;
            *reinterpret_cast<NodeRef*>(&unk50) = (void*)0;
        }
    }
}

struct E14
{
    virtual void v0(), v1(), v2(), v3(), v4();
    virtual void* F14();
};
struct C43
{
    E14* FUN_0043b4a0();
};
struct Ec
{
    virtual void v0(), v1(), v2();
    virtual C43* Fc(int a);
};
struct E1d0
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(),
        v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(), v62(), v63(),
        v64(), v65(), v66(), v67(), v68(), v69(), v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(), v79(),
        v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88(), v89(), v90(), v91(), v92(), v93(), v94(), v95(),
        v96(), v97(), v98(), v99(), v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(), v109(),
        v110(), v111(), v112(), v113(), v114(), v115();
    virtual Ec* F1d0();
};
struct R4e
{
    E1d0* CreateWaterReference();
};
struct TaskX
{
    void ResetRecordSelection();
};
struct Q28
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9();
    virtual TaskX* F28();
};
struct PQ
{
    void* p;
    Q28* Modelloader_GetReferencedThis();
};
struct G3
{
};
struct G2
{
    G3* Modelloader_GetReferencedThis();
    int NiObjectNET_GetControllers();
};
struct G1
{
    G2* Modelloader_GetReferencedThis();
};
struct G0
{
    void* p;
    G1* Modelloader_GetReferencedThis();
};
struct PS
{
    void* p;
    void* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void* p);
};
struct MgrX
{
    R4e* DetailedActorPathHandler_GetCurrentNodeIndex(Q28* a, G3* b, int c, void* d, int e);
};
extern MgrX* g_pkMgr;
extern bool g_bFlag;
class SelfX
{
  public:
    G0 m0;
    int m4;
    PQ m8;
    PQ mc;
    int m10;
    PS m14;
    PS m18;
    E1d0* m1c;
    E1d0* m20;
    void UpdateWaterReferences(bool bForce);
};
// If g_bFlag or bForce is set, recreate m20 and m1c water references via g_pkMgr, update m18 and m14, and reset record selection on mc and m8.
// @fnv 0x006fb170
void SelfX::UpdateWaterReferences(bool bForce)
{
    if (g_bFlag || bForce)
    {
        if (mc.Modelloader_GetReferencedThis())
        {
            m20 = g_pkMgr
                      ->DetailedActorPathHandler_GetCurrentNodeIndex(mc.Modelloader_GetReferencedThis(), m0.Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis(),
                                     m0.Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->NiObjectNET_GetControllers(), m18.Modelloader_GetReferencedThis(), 1)
                      ->CreateWaterReference();
            m18.FUN_0066b0d0(0);
            if (m20)
                m18.FUN_0066b0d0(m20->F1d0()->Fc(0)->FUN_0043b4a0()->F14());
            if (mc.Modelloader_GetReferencedThis()->F28())
                mc.Modelloader_GetReferencedThis()->F28()->ResetRecordSelection();
        }
        if (m8.Modelloader_GetReferencedThis())
        {
            m1c = g_pkMgr
                      ->DetailedActorPathHandler_GetCurrentNodeIndex(m8.Modelloader_GetReferencedThis(), m0.Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis(),
                                     m0.Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->NiObjectNET_GetControllers(), m14.Modelloader_GetReferencedThis(), 0)
                      ->CreateWaterReference();
            m14.FUN_0066b0d0(0);
            if (m1c)
                m14.FUN_0066b0d0(m1c->F1d0()->Fc(0)->FUN_0043b4a0()->F14());
            if (m8.Modelloader_GetReferencedThis()->F28())
                m8.Modelloader_GetReferencedThis()->F28()->ResetRecordSelection();
        }
    }
}

struct ObjB
{
    short FUN_0047d3f0();
    short FUN_004a8ae0();
    int FUN_00726070();
};
struct ObjC
{
    int FUN_00441110();
    ObjC* FUN_00a59d30(int);
    int GetElement(int);
    int GetFltValue(int);
};
struct Sub4
{
    ObjC* Modelloader_GetReferencedThis();
};
struct Cls6fabc0
{
    ObjB* m_iWordAt00;
    Sub4 m_iWordAt04;
    int BGSTerrainChunk_GetTexture(int arg);
};

extern int NiShadeProperty_GetType();
extern "C" int DAT_0106e180;
int __cdecl Warning_005b5e40(void*, int, int, int);

// @fnv 0x006fabc0
// src: XBOX_PDB 0x006fabc0
int Cls6fabc0::BGSTerrainChunk_GetTexture(int abFloat)
{
    int result = 0;
    if (m_iWordAt04.Modelloader_GetReferencedThis())
    {
        ObjC* q = m_iWordAt04.Modelloader_GetReferencedThis()->FUN_00a59d30(NiShadeProperty_GetType());
        ObjC* p = (q == 0 ? 0 : (q->FUN_00441110() >= 8 && q->FUN_00441110() <= 0xc)) ? q : 0;
        if (p)
        {
            if (abFloat == 0)
            {
                result = p->GetElement(0);
            }
            else
            {
                result = p->GetFltValue(0);
            }
        }
        else
        {
            Warning_005b5e40(&DAT_0106e180, m_iWordAt00->FUN_00726070(), m_iWordAt00->FUN_004a8ae0(), m_iWordAt00->FUN_0047d3f0());
        }
    }
    return result;
}

namespace detach6fb {
struct D6Object
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ~D6Object();
};
struct D6Child
{
    int unk00;
};
struct D6Node
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void InsertChild(D6Child* child);
};
struct D6Root;
struct D6Ref
{
    D6Root* Modelloader_GetReferencedThis();
    D6Node* NiObjectNET_GetControllers();
};
struct D6Owner
{
    D6Ref* Modelloader_GetReferencedThis();
};
struct D6ChildPtr
{
    D6Child* p;
    D6Child* Modelloader_GetReferencedThis();
};
struct D6Queue
{
    void DetachRef(D6Object* object, D6Root* root, D6Node* node);
};
struct D6Manager
{
    D6Queue* DetailedActorPathHandler_GetCurrentNodeIndex();
};
struct D6Detacher
{
    D6Owner* pOwner;
    int unk04;
    D6ChildPtr kChildA;
    D6ChildPtr kChildB;
    int unk10;
    D6ChildPtr kAttachA;
    D6ChildPtr kAttachB;
    D6Object* pObjectA;
    D6Object* pObjectB;
    D6Owner* Modelloader_GetReferencedThis();
    void BGSTerrainChunk_RemoveWaterFromSystem(bool force);
};
}
using namespace detach6fb;
extern bool DAT_0119f154;
extern D6Manager* DAT_011dea10;

// Detaches and deletes pObjectA and pObjectB from the owner node, reattaching their children, when the global flag or force is set.
// @fnv 0x006fb3d0
// src: COMMUNITY 0x006fb3d0
void D6Detacher::BGSTerrainChunk_RemoveWaterFromSystem(bool force)
{
    if (DAT_0119f154 || force)
    {
        if (kChildA.Modelloader_GetReferencedThis() && pObjectA)
        {
            if (DAT_011dea10->DetailedActorPathHandler_GetCurrentNodeIndex())
            {
                DAT_011dea10->DetailedActorPathHandler_GetCurrentNodeIndex()->DetachRef(pObjectA, pOwner->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis(),
                                                        pOwner->Modelloader_GetReferencedThis()->NiObjectNET_GetControllers());
            }
            if (kAttachA.Modelloader_GetReferencedThis())
            {
                Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->NiObjectNET_GetControllers()->InsertChild(kAttachA.Modelloader_GetReferencedThis());
            }
            delete pObjectA;
            pObjectA = 0;
        }
        if (kChildB.Modelloader_GetReferencedThis() && pObjectB)
        {
            if (DAT_011dea10->DetailedActorPathHandler_GetCurrentNodeIndex())
            {
                DAT_011dea10->DetailedActorPathHandler_GetCurrentNodeIndex()->DetachRef(pObjectB, pOwner->Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis(),
                                                        pOwner->Modelloader_GetReferencedThis()->NiObjectNET_GetControllers());
            }
            if (kAttachB.Modelloader_GetReferencedThis())
            {
                Modelloader_GetReferencedThis()->Modelloader_GetReferencedThis()->NiObjectNET_GetControllers()->InsertChild(kAttachB.Modelloader_GetReferencedThis());
            }
            delete pObjectB;
            pObjectB = 0;
        }
    }
}
