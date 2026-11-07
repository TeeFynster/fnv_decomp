#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiMeshPSysData.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiParticleSystem.h"
#include "../../../../include/NiParticleMeshes.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/StrArr.h"

// The shared mesh-data header does not yet declare the mesh-node extension.
static inline NiNode* MeshNode(const NiMeshPSysData* data)
{
    return *reinterpret_cast<NiNode* const*>(reinterpret_cast<const char*>(data) + 0x7C);
}

inline const NiRTTI* NiObject::QueryRTTI()
{
    return GetRTTI();
}
inline void NiObject::Update(unsigned int value)
{
    reinterpret_cast<NiAVObject*>(this)->PurgeRendererData(reinterpret_cast<NiRenderer*>(value));
}
inline unsigned short NiObject::MeshChildCount() const
{
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 0x60);
}
inline unsigned short NiObject::ChildCount() const
{
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 0x22);
}
inline NiObject** NiObject::MeshChildren() const
{
    return *reinterpret_cast<NiObject** const*>(reinterpret_cast<const char*>(this) + 0x58);
}
inline NiObject** NiObject::Children() const
{
    return *reinterpret_cast<NiObject** const*>(reinterpret_cast<const char*>(this) + 0x1C);
}

// src/gamebryo2.2/corelibs/niparticle/nimeshparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nimeshparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202538;

// @fnv 0x00c21e10
// src: COMMUNITY 0x00c21e10
void* __cdecl NiMeshParticleSystem_GetRTTI()
{
    return &g_01202538;
}

extern int DAT_010bdd84;
// @fnv 0x00c21e90
// src: XBOX_PDB 0x00c21e90
void* __cdecl NiMeshParticleSystem_CreateObject()
{
    void* p = NiParticleSystem::operator new(0x118);
    if (p)
    {
        static_cast<NiParticleSystem*>(p)->NiParticleSystem_00c1b5c0();
        *(float*)((char*)p + 0x110) = 0.0f;
        *(void**)((char*)p + 0) = &DAT_010bdd84;
        *(char*)((char*)p + 0x114) = 1;
        return p;
    }
    return 0;
}

struct NiMeshParticleSystem : NiParticleSystem
{
    float m_f110;
    void __thiscall UpdateRigidDownwardPass_00c21910(NiUpdateData&, unsigned int);
};
// @fnv 0x00c21910
// src: XBOX_PDB 0x00c21910
void __thiscall NiMeshParticleSystem::UpdateRigidDownwardPass_00c21910(NiUpdateData& UpdateData, unsigned int uFlags)
{
    if (UpdateData.pad2)
    {
        UpdateData.pad3 = true;
        return;
    }
    UpdateParticleSystem(UpdateData, uFlags);
    m_f110 = UpdateData.fTime;
}

namespace fnv_00c21b60 {
class NiMeshParticleSystem : public NiGeometry
{
  public:
    void __thiscall UpdatePropertiesDownward(NiPropertyState* pkParentState);
};
// @fnv 0x00c21b60
// src: XBOX_PDB 0x00c21b60
void __thiscall NiMeshParticleSystem::UpdatePropertiesDownward(NiPropertyState* pkParentState)
{
    NiGeometry::UpdatePropertiesDownwardPass(pkParentState);
    MeshNode(static_cast<NiMeshPSysData*>(m_spModelData.m_pObject))->UpdatePropertiesDownwardPass(&m_PropertyState);
}
}  // namespace fnv_00c21b60

namespace fnv_00c21bb0 {
struct NiMeshParticleSystem : NiParticleSystem
{
    void __thiscall UpdateSelective(bool&, bool, bool&);
};
// @fnv 0x00c21bb0
void __thiscall NiMeshParticleSystem::UpdateSelective(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms,
                                                      bool& bRigid)
{
    NiParticleSystem::SetSelectiveUpdateFlags(bSelectiveUpdate, true, bRigid);
    NiMeshPSysData* pkData = static_cast<NiMeshPSysData*>(m_spModelData.m_pObject);
    MeshNode(pkData)->SetSelectiveUpdateFlags(bSelectiveUpdate, true, bRigid);
    bRigid = false;
    MeshNode(pkData)->m_uFlags &= ~0x10;
}
}  // namespace fnv_00c21bb0

namespace fnv_00c21dc0 {
char* __cdecl _FUN_00a7d330(void*);
struct NiMeshParticleSystem : NiParticleSystem
{
    void __thiscall AppendString(StrArr*);
};
// Calls the base particle system handler, then appends the string returned by _FUN_00a7d330 to pkStrings, growing it if full.
// @fnv 0x00c21dc0
void __thiscall NiMeshParticleSystem::AppendString(StrArr* pkStrings)
{
    NiParticleSystem::WriteParticleSystemInfo(pkStrings);
    char* pcString = _FUN_00a7d330(g_01202538);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pcString);
}
}  // namespace fnv_00c21dc0

namespace fnv_00c21ed0 {
// Unit-local view of NiTPointerListBase for 0x00c21ed0 (namespace fnv_00c21ed0): built on the shared NiTPointerListBase, that code does not compile or does not match.
struct NiTPointerListBase_00c21ed0
{
    void __thiscall RemoveAll();
};
void __cdecl _delete(void*, unsigned int);
struct NiMeshParticleSystem
{
    char _pad[0xC8];
    NiTPointerListBase_00c21ed0 m_kNode;
    void __thiscall UpdateFields_00a80580();
    void* __thiscall Destroy(unsigned int);
};
// @fnv 0x00c21ed0
void* __thiscall NiMeshParticleSystem::Destroy(unsigned int flags)
{
    m_kNode.RemoveAll();
    this->UpdateFields_00a80580();
    if (flags & 1)
        _delete(this, 0x118);
    return this;
}
}  // namespace fnv_00c21ed0

namespace fnv_00c26350 {
extern NiColorA DAT_011a9be0;
struct NiMeshParticleSystem
{
    NiColorA* __thiscall GetParticleColor(unsigned short, unsigned short);
};
// @fnv 0x00c26350
NiColorA* __thiscall NiMeshParticleSystem::GetParticleColor(unsigned short ausBlockIndex, unsigned short ausColorIndex)
{
    if (*(int*)((char*)this + 0x28))
    {
        unsigned int v1 = ausBlockIndex;
        unsigned int v2 = ausColorIndex;
        char* base = *(char**)((char*)this + 0x7c);
        v1 <<= 5;
        v2 *= 0x84;
        char* ptr = *(char**)(v1 + base);
        return (NiColorA*)(ptr + v2 + 0x6c);
    }
    return &DAT_011a9be0;
}
}  // namespace fnv_00c26350

struct NiMeshParticleSystemClone : NiMeshParticleSystem
{
    NiMeshParticleSystemClone* __thiscall NiMeshParticleSystem_CreateClone(CloningProcess&);
    char _pad114[4];
};
// Allocates and constructs a NiMeshParticleSystemClone, copies m_f110 and the byte at offset 0x114 from this, and returns it.
// @fnv 0x00c21e20
// src: XBOX_PDB 0x00c21e20
NiMeshParticleSystemClone* __thiscall NiMeshParticleSystemClone::NiMeshParticleSystem_CreateClone(CloningProcess& process)
{
    NiMeshParticleSystemClone* result = static_cast<NiMeshParticleSystemClone*>(operator new(sizeof(NiMeshParticleSystemClone)));
    if (result)
    {
        result->NiParticleSystem::NiParticleSystem_00c1b5c0();
        result->m_f110 = 0.0f;
        *(unsigned int*)result = (unsigned int)&DAT_010bdd84;
        *(unsigned char*)((char*)result + 0x114) = 1;
    }
    else
        result = 0;
    CopyMembers_00c1b6f0(result, process);
    result->m_f110 = m_f110;
    *(unsigned char*)((char*)result + 0x114) = *(unsigned char*)((char*)this + 0x114);
    return result;
}


int __cdecl _NiStricmp(const char* string1, const char* string2);
int __cdecl sprintf(char* buffer, const char* format, ...);
extern void(__cdecl* DAT_011ac2ac)(char* buffer, const char* message, int value);

struct FUN_00c21960_shell
{
    void __thiscall CheckUnsupportedMeshParticle(void* stream);
    void __thiscall FUN_00c1b3a0(void* stream);
};

// @fnv 0x00c21960
void __thiscall FUN_00c21960_shell::CheckUnsupportedMeshParticle(void* stream)
{
    const char* pname = reinterpret_cast<char*>(stream) + 0xE0;
    bool bWarn = true;
    char* pdude;
    char acMessage[260];

    if (pname)
    {
        if (_NiStricmp(pname, "Meshes\\Sky\\RainHeavy.NIF") == 0)
        {
            bWarn = false;
        }
        else if (_NiStricmp(pname, "Meshes\\Sky\\RainLight.NIF") == 0)
        {
            bWarn = false;
        }
    }

    if (bWarn)
    {
        pdude = reinterpret_cast<char*>(stream) + 8;
        if (!pdude[0])
        {
            pdude = "Please";
        }

        sprintf(acMessage, "File %s contains a mesh particle system! %s remove it.", pname, pdude);

        if (DAT_011ac2ac)
        {
            DAT_011ac2ac(acMessage, "Unsupported Object", 0);
        }
    }

    FUN_00c1b3a0(stream);
}


struct MeshGeometryGroup
{
    int unk00;
    NiGeometry** m_ppGeometries;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};


// Local method adapter for the mesh-data group operation missing from the shared header.
class MeshPSysDataGroups : public NiMeshPSysData
{
  public:
    void ApplyToAllObjects(void* pvArg);
};

// Iterates every group and its objects, calling Apply(pvArg) on each non-null object.
// @fnv 0x00c21a10
void MeshPSysDataGroups::ApplyToAllObjects(void* pvArg)
{
    unsigned int uiGroups = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x92);
    for (unsigned int i = 0; i < uiGroups; i++)
    {
        MeshGeometryGroup* pkGroup = (*reinterpret_cast<MeshGeometryGroup***>(reinterpret_cast<char*>(this) + 0x8C))[i];
        if (pkGroup)
        {
            unsigned int uiObjects = pkGroup->m_usSize;
            for (unsigned int j = 0; j < uiObjects; j++)
            {
                NiGeometry* pkObject = pkGroup->m_ppGeometries[j];
                if (pkObject)
                    pkObject->PurgeRendererData(static_cast<NiRenderer*>(pvArg));
            }
        }
    }
}



struct FUN_00c21b90_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    NiMeshPSysData* m_B8;
    void __thiscall TailViaMid(int a);
};

// @fnv 0x00c21b90
void FUN_00c21b90_cls::TailViaMid(int aiValue)
{
    MeshNode(m_B8)->OnVisible(*reinterpret_cast<NiCullingProcess*>(aiValue));
}

struct FUN_00c21c60_src
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    float m_0c;
};
extern FUN_00c21c60_src DAT_011f4288;
struct FUN_00c21c60_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    FUN_00c21c60_src* m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    NiMeshPSysData* m_b8;
    void Refresh();
    void CopySourceToOutput();
};
// Calls Refresh, then copies m_00, m_04, m_08 and m_0c from the source record (or DAT_011f4288 if null) into m_20.
// @fnv 0x00c21c60
void FUN_00c21c60_cls::CopySourceToOutput()
{
    Refresh();
    NiNode* y = MeshNode(m_b8);
    FUN_00c21c60_src* pSource = y->m_kWorldBound != 0 ? reinterpret_cast<FUN_00c21c60_src*>(y->m_kWorldBound) : &DAT_011f4288;
    unsigned int a = pSource->m_00;
    volatile float fValue = pSource->m_0c;
    FUN_00c21c60_src* pOutput = m_20;
    pOutput->m_00 = a;
    pOutput->m_04 = pSource->m_04;
    unsigned int uiData = pSource->m_08;
    pOutput->m_0c = fValue;
    pOutput->m_08 = uiData;
}

extern "C" NiRTTI DAT_01202500;
extern "C" NiRTTI DAT_01202530;
struct NiObjectNode
{
    NiObjectNode* next;
    NiObjectNode* previous;
    NiObject* object;
    static NiObject*& GetNext(NiObjectNode*& it)
    {
        NiObject*& result = it->object;
        it = it->next;
        return result;
    }
};
// @fnv 0x00c21cb0
// src: XBOX_PDB 0x00c21cb0
void __thiscall NiObject::NiMeshParticleSystem_PurgeRendererData(unsigned int value)
{
    FUN_00a809b0(value);
    NiObject* pLinkedObject = *(NiObject**)((char*)this + 0xb8);
    if (pLinkedObject)
    {
        NiObject* child = *(NiObject**)((char*)pLinkedObject + 0x7c);
        if (child)
            child->Update(value);
        pLinkedObject->ApplyToAllObjects(value);
    }
    for (NiObjectNode* node = *(NiObjectNode**)((char*)this + 0xc8); node;)
    {
        NiObject* object = NiObjectNode::GetNext(node);
        if (!object)
            continue;
        for (const NiRTTI* type = object->QueryRTTI(); type; type = type->m_pBaseRTTI)
        {
            if (type == &DAT_01202500)
            {
                unsigned int count = object->MeshChildCount();
                for (unsigned int i = 0; i < count; ++i)
                {
                    if (i < object->MeshChildCount())
                    {
                        NiObject* child = object->MeshChildren()[i];
                        if (child)
                            child->Update(value);
                    }
                }
                goto next_object;
            }
        }
        for (const NiRTTI* type = object->QueryRTTI(); type; type = type->m_pBaseRTTI)
        {
            if (type == &DAT_01202530)
            {
                unsigned int count = object->ChildCount();
                for (unsigned int i = 0; i < count; ++i)
                {
                    if (i < object->ChildCount())
                    {
                        NiObject* child = object->Children()[i];
                        if (child)
                            child->Update(value);
                    }
                }
                goto next_object;
            }
        }
    next_object:;
    }
}

// Particle system constructor: defaults with the last-update time marked invalid.

static const float NI_INFINITY = 3.402823466e+38f;
static const float INVALID_FLOAT = -NI_INFINITY;

extern const void* NiParticleSystemVtable;

// Construct the original particle base explicitly: the shared default constructor
// currently declares a different base-construction call.
// @fnv 0x00c1b5c0
// src: EXE 0x00c1b5c0
NiParticleSystem* NiParticleSystem::NiParticleSystem_00c1b5c0()
{
    // Keep the list and time writes in the original construction order.
    volatile NiParticleSystem* state = this;
    reinterpret_cast<NiParticleMeshes*>(this)->Init();
    *reinterpret_cast<const void**>(this) = &NiParticleSystemVtable;
    m_bFlag = true;
    state->m_kModifiers.m_kItemCount.m_uiCount = 0;
    state->m_kModifiers.m_pkHead = 0;
    state->m_kModifiers.m_pkTail = 0;
    state->m_fLastTime = INVALID_FLOAT;
    m_bHasAccumulation = false;
    m_bD9 = false;
    return this;
}

extern "C" NiRTTI DAT_01202690;
struct FUN_00c21a80_obj;
struct FUN_00c21a80_node
{
    FUN_00c21a80_node* m_pNext;
    unsigned int unk04;
    FUN_00c21a80_obj* m_pInventoryEntryData;
};
struct FUN_00c21a80_obj
{
    virtual void v00();
    virtual void v01();
    virtual void* v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v36(NiUpdateData&);
    virtual void v37(NiUpdateData&);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46(NiUpdateData&);
    virtual void v47();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    FUN_00c21a80_obj* m_pNext30;
};
struct FUN_00c21a80_cls
{
    virtual void v00();
    virtual void v01();
    virtual void* v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v36(NiUpdateData&);
    virtual void v37(NiUpdateData&);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46(NiUpdateData&);
    virtual void v47();
    unsigned int unk04;
    unsigned int unk08;
    FUN_00c21a80_obj* m_pList0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    FUN_00c21a80_node* m_pList24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    float m_f110;
    char m_b114;
    void __thiscall NiMeshParticleSystem_UpdateDownwardPass(NiUpdateData&, unsigned int);
};
// Runs update callbacks over the node and object lists, defers the found object's v37, then stores the update time and flag.
// @fnv 0x00c21a80
// src: XBOX_PDB 0x00c21a80
void FUN_00c21a80_cls::NiMeshParticleSystem_UpdateDownwardPass(NiUpdateData& aUpdateData, unsigned int arg2)
{
    if (aUpdateData.pad2)
    {
        aUpdateData.pad3 = true;
        return;
    }
    FUN_00c21a80_obj* pDeferredObj = 0;
    if (aUpdateData.pad1 != 0)
    {
        FUN_00c21a80_node* node = m_pList24;
        while (node)
        {
            FUN_00c21a80_obj*& ref = node->m_pInventoryEntryData;
            node = node->m_pNext;
            if (ref && ref->m_0c != 0)
            {
                ref->v36(aUpdateData);
            }
        }
        FUN_00c21a80_obj* obj = (FUN_00c21a80_obj*)m_pList0C;
        while (obj)
        {
            const NiRTTI* pEntry = static_cast<const NiRTTI*>(obj->v02());
            if (pEntry)
            {
                do
                {
                    if ((void*)pEntry == (void*)&DAT_01202690)
                    {
                        pDeferredObj = obj;
                        goto next;
                    }
                    pEntry = pEntry->m_pBaseRTTI;
                } while (pEntry);
            }
            obj->v37(aUpdateData);
        next:
            obj = obj->m_pNext30;
        }
        v46(aUpdateData);
        if (pDeferredObj)
            pDeferredObj->v37(aUpdateData);
    }
    else
    {
        v46(aUpdateData);
    }
    v47();
    m_f110 = aUpdateData.fTime;
    m_b114 = aUpdateData.pad1;
}

extern "C" __declspec(noreturn) void __cdecl NiParticleSystem_SetModelData();

// @fnv 0x00c21900
// src: XBOX_PDB 0x00c21900
__declspec(noreturn) void __cdecl NiMeshParticleSystem_SetModelData()
{
    NiParticleSystem_SetModelData();
}

#include <math.h>
struct Xf36
{
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20;
};



struct Ps21Node
{
    char _pad00[0x68];
    Xf36 m_68;
    unsigned int m_8c;
    unsigned int m_90;
    unsigned int m_94;
    float m_98;
    char _pad9c[0x1c];
    NiMeshPSysData* m_b8;

    void FUN_00c1add0(unsigned int a1);
    void CopyFromNode(unsigned int a1);
};

// Copies several fields and the absolute value of m_98 to the owner's target, then calls its virtual method.
// @fnv 0x00c21bf0
void Ps21Node::CopyFromNode(unsigned int a1)
{
    FUN_00c1add0(a1);
    NiMeshPSysData* owner = m_b8;
    *reinterpret_cast<Xf36*>(&MeshNode(owner)->m_kLocal.m_Rotate) = m_68;
    NiNode* y = MeshNode(owner);
    unsigned int* p = reinterpret_cast<unsigned int*>(&y->m_kLocal.m_Translate);
    *p = m_8c;
    p[1] = m_90;
    p[2] = m_94;
    float fAbsValue = (float)fabs(m_98);
    NiNode* z = MeshNode(owner);
    z->m_kLocal.m_fScale = fAbsValue;
    z->UpdateWorldData(*reinterpret_cast<NiUpdateData*>(a1));
}
