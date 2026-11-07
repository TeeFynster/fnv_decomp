#include "../../../../include/NiTListItem.h"
#include "../../../../include/NiTPointerListBase.h"

// src/gamebryo2.2/corelibs/niparticle/niparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/niparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPointer.h"
#include "../../../../include/NiTListItem.h"
#include "../../../../include/NiTPointerListBase.h"
#include "../../../../include/NiTPointerAllocator.h"
#include "../../../../include/BSMultiBoundNode.h"
#include "../../../../include/NiParticleSystem.h"
#include "../../../../include/Bound.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysUpdateTask.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPSysModifierCtlr.h"
#include "../../../../include/NiRTTI.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (!InterlockedDecrement((long volatile*)&m_uiRefCount))
        DeleteThis();
}
inline void NiRefObject::AcquireReference()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}
inline void NiRefObject::DecRef()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

// @fnv 0x00c1b020
void __thiscall NiParticleSystem::SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms,
                                                          bool& bRigid)
{
    bSelectiveUpdate = true;
    bRigid = false;
    unsigned int& flags = m_uFlags;
    if (bSelectiveUpdate)
        flags |= 2;
    else
        flags &= ~2;
    flags |= 0xc;
    if (bRigid)
        flags |= 0x10;
    else
        flags &= ~0x10;
}

// Calls FUN_00a74780, reads a modifier count from the stream, then loads that many modifiers via InsertSorted.
// @fnv 0x00c1b810
void __thiscall NiParticleSystem::LoadModifiers(NiStream* kStream)
{
    NiLines_LinkObject(kStream);
    unsigned int uiNumModifiers = kStream->GetLinkID();
    if (uiNumModifiers > 0)
    {
        for (unsigned int uiRemaining = uiNumModifiers; uiRemaining > 0; --uiRemaining)
            InsertSorted((NiPSysModifier*)kStream->GetLoadedObject());
    }
}

extern char const* const g_01202538_arg1;

// @fnv 0x00c1b5b0
// src: COMMUNITY 0x00c1b5b0
char const* const* __cdecl NiParticleSystem_GetRTTI()
{
    return &g_01202538_arg1;
}

struct ParticleListCleanup
{
    void __thiscall RemoveAll();
};
struct S_00a80580
{
    void __thiscall UpdateFields_00a80580();
};
void __cdecl _delete(void*, unsigned int);

// Clears the list at offset 0xC8, calls FUN_00a80580, and if f has bit 0 set, deletes this with size 0x110; returns this.
// @fnv 0x00c1b9b0
void* __fastcall DestroyParticleSystem(NiParticleSystem* system, void*, unsigned int auiFlags)
{
    ((ParticleListCleanup*)((char*)system + 0xC8))->RemoveAll();
    ((S_00a80580*)system)->UpdateFields_00a80580();
    if (auiFlags & 1)
        _delete(system, 0x110);
    return system;
}

struct S_00c1b060_Cloning;
struct S_00c1b060_Map
{
    bool GetAt(NiObject* key, NiObject*& val);
};
struct S_00c1b060_Cloning
{
    S_00c1b060_Map* m_pCloneMap;
};

struct S_00c1b060_Base
{
    void FUN_00a80a10(S_00c1b060_Cloning* k);
};

// Calls the base clone handler, looks up this object in the cloning map, then calls ProcessClone on each item in the unkC8 list and on unkB8.
// @fnv 0x00c1b060
// src: XBOX_PDB 0x00c1b060
void NiParticleSystem::ProcessClone_00c1b060(CloningProcess& cloning)
{
    S_00c1b060_Cloning* pkCloning = (S_00c1b060_Cloning*)&cloning;
    ((S_00c1b060_Base*)this)->FUN_00a80a10(pkCloning);
    NiObject* pkClone;
    pkCloning->m_pCloneMap->GetAt((NiObject*)this, pkClone);
    NiTListItem<NiObject*>* pos = (NiTListItem<NiObject*>*)m_kModifiers.m_pkHead;
    while (pos)
    {
        NiObject*& pkElement = pos->m_element;
        pos = pos->m_pkNext;
        pkElement->ProcessClone(*(CloningProcess*)pkCloning);
    }
    ((NiObject*)m_spModelData.m_pObject)->ProcessClone(*(CloningProcess*)pkCloning);
}

extern const NiRTTI DAT_012027c8;
static const float DAT_01015f5c = -3.402823466e+38F;

inline bool S_00c1b120_IsKindOf(const NiRTTI* pkRTTI, const NiObject* pkObject)
{
    if (!pkObject)
        return false;
    const NiRTTI* pkTmp = pkObject->GetRTTI();
    while (pkTmp)
    {
        if (pkTmp == pkRTTI)
            return true;
        pkTmp = pkTmp->m_pBaseRTTI;
    }
    return false;
}
inline NiObject* S_00c1b120_DynamicCast(const NiRTTI* pkRTTI, const NiObject* pkObject)
{
    return S_00c1b120_IsKindOf(pkRTTI, pkObject) ? (NiObject*)pkObject : 0;
}

struct S_00c1b120_Data : NiObject
{
    virtual void vfn_8c(bool value);
    int unk8;
    int unkC;
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
    unsigned short unk78;
    unsigned short unk7A;
};

// @fnv 0x00c1b120
// src: XBOX_PDB 0x00c1b120
void NiParticleSystem::PerformSystemReset()
{
    S_00c1b120_Data* pkData = (S_00c1b120_Data*)m_spModelData.m_pObject;
    pkData->vfn_8c(false);
    pkData->unk78 = 0;
    pkData->unk7A = 0;
    m_fLastTime = DAT_01015f5c;

    void* kPos = m_kModifiers.m_pkHead;
    while (kPos)
    {
        NiPSysModifier* pkMod = ((const NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPSysModifier*>*)&m_kModifiers)->GetNext(kPos);
        pkMod->HandleReset();
    }

    for (NiTimeController* pkCtlr = m_spControllers; pkCtlr; pkCtlr = pkCtlr->m_spNextController.m_pObject)
    {
        NiObject* pkCast = S_00c1b120_DynamicCast(&DAT_012027c8, pkCtlr);
        if (pkCast)
            ((NiPSysModifierCtlr*)pkCast)->vf59();
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int);
// @fnv 0x00c1b7f0
// src: EXE 0x00c1b7f0
NiParticleSystem* __cdecl NiParticleSystem_CreateObject()
{
    NiParticleSystem* p = (NiParticleSystem*)Object_DispatchCommandFour(0x110);
    if (p)
        return p->NiParticleSystem_00c1b5c0();
    return 0;
}

// @fnv 0x00c1b9e0
NiObject* NiParticleSystem::MakeClone(CloningProcess& cloning)
{
    void* memory = NiParticleSystem::operator new(0x110);
    NiParticleSystem* node;
    if (memory)
        node = ((NiParticleSystem*)memory)->NiParticleSystem_00c1b5c0();
    else
        node = 0;
    CopyMembers_00c1b6f0(node, cloning);
    return node;
}

extern "C" int DAT_011f426c;
extern "C" int DAT_011f4270;
extern "C" int DAT_011f4274;

struct Block9
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
};

extern "C" const Block9 DAT_011a9448;

struct ParticleWorldDataBase
{
    void FUN_00a68c60(NiUpdateData& data);
};

// Preserve the world transform before applying the world-space particle transform.
// @fnv 0x00c1add0
void NiParticleSystem::UpdateWorldData(NiUpdateData& data)
{
    ((ParticleWorldDataBase*)this)->FUN_00a68c60(data);
    m_kUnmodifiedWorld = m_kWorld;
    if (m_bFlag != 0)
    {
        *(int*)&m_kWorld.m_Translate.x = DAT_011f426c;
        *(int*)&m_kWorld.m_Translate.y = DAT_011f4270;
        *(int*)&m_kWorld.m_Translate.z = DAT_011f4274;
        m_kWorld.m_Rotate = *(const NiMatrix3*)&DAT_011a9448;
    }
}

struct NiparticlesystemListNodeView;
struct ListItemBase
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36(void* a, unsigned int b)
    {}
};
// Exe 0x00c1aee0: unit-local ListNode view; declarations and layout are preserved.
struct NiparticlesystemListNodeView
{
    NiparticlesystemListNodeView* next;
    unsigned int unk04;
    ListItemBase* m_08;
};

// Walks the linked list at m_c8 and calls v36 on each node's m_08 item, passing m_b8 and arg.
// @fnv 0x00c1aee0
// src: XBOX_PDB 0x00c1aee0
void NiParticleSystem::InitializeNewParticle(unsigned int arg)
{
    void* first = m_spModelData.m_pObject;
    NiparticlesystemListNodeView* node = (NiparticlesystemListNodeView*)m_kModifiers.m_pkHead;
    if (node != 0)
    {
        do
        {
            ListItemBase** pp = &node->m_08;
            node = node->next;
            (*pp)->v36(first, arg);
        } while (node != 0);
    }
}

struct Vec4Obj
{
    float x;
    float y;
    float z;
    float w;
    void __thiscall FUN_00a7fdd0(Vec4Obj const* src, void* p);
};

struct S_00a80710
{
    void __thiscall FUN_00a80710();
};

struct Vec3Tmp
{
    float x;
    float y;
    float z;
};

struct Holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Vec4Obj m_vec10;
};

// @fnv 0x00c1af60
void NiParticleSystem::UpdateWorldBound()
{
    ((S_00a80710*)this)->FUN_00a80710();
    if (m_bC4 == 0)
    {
        return;
    }
    Vec4Obj* dst = ((Vec4Obj*)m_kWorldBound);
    if (m_bD9 != 0)
    {
        Vec4Obj* src = &((Holder*)m_spModelData.m_pObject)->m_vec10;
        unsigned int* d = (unsigned int*)dst;
        const unsigned int* q = (const unsigned int*)src;
        unsigned int xv = q[0];
        float w0 = src->w;
        d[0] = xv;
        unsigned int yv = q[1];
        d[1] = yv;
        unsigned int zv = q[2];
        dst->w = w0;
        d[2] = zv;
        float s = m_kWorld.m_fScale;
        Vec4Obj* p = ((Vec4Obj*)m_kWorldBound);
        Vec3Tmp t;
        t.x = p->x * s;
        t.y = p->y * s;
        t.z = p->z * s;
        float w = p->w * m_kWorld.m_fScale;
        *(Vec3Tmp*)p = t;
        p->w = w;
        return;
    }
    NiTransform const& xf = *(NiTransform const*)((char const*)this + 0xdc);
    ((NiBound*)dst)->Update((void*)&((Holder*)m_spModelData.m_pObject)->m_vec10, (void*)&xf);
}

struct ModifierLookupItem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};
struct ModifierLookupNode
{
    ModifierLookupNode* m_00;
    unsigned int unk04;
    ModifierLookupItem* m_08;
};

inline ModifierLookupItem* const& GetNext(ModifierLookupNode*& pos)
{
    ModifierLookupItem* const& element = pos->m_08;
    pos = pos->m_00;
    return element;
}

// Walks the linked list at m_c8 and returns the first item whose m_08 equals *key, or null if none matches.
// @fnv 0x00c1b0f0
NiPSysModifier* NiParticleSystem::GetModifier(const NiFixedString& name)
{
    const unsigned int* puiKey = (const unsigned int*)&name;
    ModifierLookupNode* pos = (ModifierLookupNode*)m_kModifiers.m_pkHead;
    while (pos != 0)
    {
        ModifierLookupItem* item = GetNext(pos);
        if (item != 0 && item->m_08 == *puiKey)
        {
            return (NiPSysModifier*)item;
        }
    }
    return 0;
}

struct S_00c1b260_Data
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_uiItemCount;
    void FUN_00a67090(int flags);
};

struct S_00c1b260_Mod
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void update(float fTime, S_00c1b260_Data* pkData);
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual bool vA0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool m_bModifierActive;
};

struct S_00c1b260_Parent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void* v10();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00c1b260_Parent* m_pParentNode;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    unsigned int m_uiObjectFlags;
};

extern double DAT_010241b0;

// @fnv 0x00c1b260
// src: XBOX_PDB 0x00c1b260
void NiParticleSystem::Do_UpdateSystem(float fTime)
{
    S_00c1b260_Data* pkData = (S_00c1b260_Data*)m_spModelData.m_pObject;
    bool bWasEmpty = false;
    if (pkData->m_uiItemCount == 0)
        bWasEmpty = true;
    pkData->vAC();
    if (m_bHasAccumulation || m_fLastTime > fTime)
    {
        PerformSystemReset();
        m_bHasAccumulation = false;
    }
    if (m_fLastTime == DAT_010241b0)
        m_fLastTime = fTime;

    S_00c1b260_Mod* pkLast = 0;
    NiTListItem<S_00c1b260_Mod*>* pkNode = (NiTListItem<S_00c1b260_Mod*>*)m_kModifiers.m_pkHead;
    while (pkNode)
    {
        S_00c1b260_Mod*& pkE = pkNode->m_element;
        pkNode = pkNode->m_pkNext;
        S_00c1b260_Mod* pkMod = pkE;
        if (pkMod->vA0())
            pkLast = pkMod;
        else if (pkMod->m_bModifierActive)
            pkMod->update(fTime, pkData);
    }
    if (pkLast && pkLast->m_bModifierActive)
        pkLast->update(fTime, pkData);

    pkData->FUN_00a67090(7);
    m_fLastTime = fTime;
    if (bWasEmpty && pkData->m_uiItemCount != 0)
    {
        S_00c1b260_Parent* p = (S_00c1b260_Parent*)m_pkParent;
        while (p)
        {
            if (p->v10())
            {
                p->m_uiObjectFlags |= 0x400000;
                break;
            }
            p = p->m_pParentNode;
        }
    }
}

// Stand-in model for the objects touched by FUN_00c1b3a0.
// The "sub" object is the per-object callback holder; the callback at +8 is
// invoked with (self, &outFlag, 1, &outCount, 1) and returns a byte count.

struct ParticleLoadBase
{
    void NiLines_LoadBinary(NiStream* stream);
};

struct Sub_c1b3a0
{
    int unk00;
    int m_04;
    int(__cdecl* m_08)(Sub_c1b3a0* self, void* pFlag, int nOne, void* pCount, int nTwo);
};

struct Obj_c1b3a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    Sub_c1b3a0* m_24c;
    void __thiscall NiStream_ReadMultipleLinkIDs();
};

// @fnv 0x00c1b3a0
void NiParticleSystem::LoadBinary(NiStream& stream)
{
    Obj_c1b3a0* pObj = (Obj_c1b3a0*)&stream;
    ((ParticleLoadBase*)this)->NiLines_LoadBinary(&stream);
    Sub_c1b3a0* pSub = pObj->m_24c;
    bool bFlag;
    int nResult;
    {
        int nCount = 1;
        nResult = pSub->m_08(pSub, &bFlag, 1, &nCount, 1);
    }
    pSub->m_04 += nResult;
    m_c4 = (bFlag != 0);
    pObj->NiStream_ReadMultipleLinkIDs();
}

struct FUN_00a59fd0_shell
{
    void __thiscall UpdateDownwardPassIfSelective(void*, unsigned int);
};
struct FUN_00c1af20_upd
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    bool flag05;
    bool flag06;
};

// If a.flag05 is set, marks a.flag06 and returns; otherwise, when bit 2 of flags30 is set, calls the virtual at offset 0xb8, then calls UpdateDownwardPassIfSelective with a and b.
// @fnv 0x00c1af20
void NiParticleSystem::UpdateParticleSystem(NiUpdateData& data, unsigned int b)
{
    FUN_00c1af20_upd& aUpd = *(FUN_00c1af20_upd*)&data;
    if (aUpd.flag05)
    {
        aUpd.flag06 = true;
        return;
    }
    unsigned int flags = m_uFlags;
    bool on = ((flags >> 2) & 1) != 0;
    if (on)
    {
        UpdateWorldData(data);
    }
    FUN_00a59fd0_shell* s = reinterpret_cast<FUN_00a59fd0_shell*>(this);
    s->UpdateDownwardPassIfSelective(&aUpd, b);
}

// IsEqual: base comparison, matching flags, and every bound in the list equals the bound with the same id in the other list.

inline NiPSysModifier* B1D0GetNext(NiTListItem<NiPSysModifier*>*& rpkPos)
{
    NiPSysModifier*& rpkElement = rpkPos->m_element;
    rpkPos = rpkPos->m_pkNext;
    return rpkElement;
}

inline NiPSysModifier* FindBound(NiTListItem<NiPSysModifier*>* pkPos, NiPSysModifier* pkBound)
{
    while (pkPos)
    {
        NiPSysModifier* pkCandidate = B1D0GetNext(pkPos);
        if (pkCandidate && pkCandidate->m_kName.m_kHandle == pkBound->m_kName.m_kHandle)
            return pkCandidate;
    }
    return 0;
}

class B1D0Base
{
  public:
    bool IsEqual(B1D0Base* pkObject);
};

// Compares base data, m_ucType and m_ucMode with pkOther, then checks each bound in m_pkBounds has an equal match in pkOther's bounds.
// @fnv 0x00c1b1d0
bool NiParticleSystem::IsEqual(NiObject* object) const
{
    NiParticleSystem* pkOther = (NiParticleSystem*)object;
    if (!((B1D0Base*)this)->IsEqual((B1D0Base*)pkOther))
        return false;
    if (m_c4 != pkOther->m_c4)
        return false;
    if (m_bD9 != pkOther->m_bD9)
        return false;

    NiTListItem<NiPSysModifier*>* pkPos = (NiTListItem<NiPSysModifier*>*)m_kModifiers.m_pkHead;
    while (pkPos)
    {
        NiPSysModifier* pkBound = B1D0GetNext(pkPos);
        NiPSysModifier* pkMatch = FindBound((NiTListItem<NiPSysModifier*>*)pkOther->m_kModifiers.m_pkHead, pkBound);
        if (!pkBound->IsEqual(pkMatch))
            return false;
    }
    return true;
}

class C1B400BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(C1B400BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(C1B400BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

template <class T>
inline void C1B400BinaryStreamSave(C1B400BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void C1B400SaveBinary(NiStream& kStream, const T& value)
{
    C1B400BinaryStreamSave(*reinterpret_cast<C1B400BinaryStream*&>(kStream.m_pkOstr), &value);
}

template <class T> inline T& NiTListGetNextC1B(NiTListItem<T>*& pkPos)
{
    T& element = pkPos->m_element;
    pkPos = pkPos->m_pkNext;
    return element;
}

class BaseC1B400
{
  public:
    void SaveBinary(NiStream& kStream);
};

// Saves the base data, the m_bFlag byte, the m_eValue enum, and the link IDs of each node in the m_pkHead list to kStream.
// @fnv 0x00c1b400
void NiParticleSystem::SaveBinary(NiStream& kStream)
{
    ((BaseC1B400*)this)->SaveBinary(kStream);
    unsigned char ucFlag = m_bFlag;
    C1B400SaveBinary(kStream, ucFlag);
    unsigned int uiValue = m_kModifiers.m_kItemCount.m_uiCount;
    C1B400SaveBinary(kStream, uiValue);
    NiTListItem<NiObject*>* pkPos = (NiTListItem<NiObject*>*)m_kModifiers.m_pkHead;
    while (pkPos)
    {
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(NiTListGetNextC1B(pkPos)));
    }
}

struct FUN_00c1b850_info
{
    unsigned int unk00;
    unsigned short m_04;
    unsigned short unk06;
    unsigned short m_08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
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
    unsigned short m_50;
    unsigned short unk52;
};
struct FUN_00c1b850_list
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
};
struct ParticleViewerBase
{
    void NiParticles_GetViewerStrings(FUN_00c1b850_list* strings);
};

struct C_0096ad30
{
    void __thiscall FUN_0096ad30(unsigned int n);
};
struct C_0096ae90
{
    void __thiscall FUN_0096ae90(unsigned int idx, unsigned int* p);
};

extern unsigned int g_012024e0;
unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
unsigned int __cdecl NiGetViewerString(const char* s, unsigned int v);
unsigned int __cdecl NiGetViewerString_00a7d510(const char* s, unsigned int v);
unsigned int __cdecl NiGetViewerString_00a7d490(const char* s, unsigned int v);

// Appends World Space, NumMods, NumParticles and MaxParticles entries to the list via FUN_00a9b2e0 and FUN_0096ae90, growing it when full.
// @fnv 0x00c1b850
void NiParticleSystem::WriteParticleSystemInfo(StrArr* strings)
{
    FUN_00c1b850_list* pList = (FUN_00c1b850_list*)strings;
    ((ParticleViewerBase*)this)->NiParticles_GetViewerStrings(pList);
    unsigned int v = NiViewerStrings_NiGetViewerString_Title(g_012024e0);
    unsigned int uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);

    v = NiGetViewerString("World Space", m_c4);
    uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);

    unsigned int uiNumMods = m_kModifiers.m_kItemCount.m_uiCount;
    v = NiGetViewerString_00a7d510("NumMods", uiNumMods);
    uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);

    unsigned int uiNumParticles = ((FUN_00c1b850_info*)m_spModelData.m_pObject)->m_50;
    v = NiGetViewerString_00a7d490("NumParticles", uiNumParticles);
    uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);

    unsigned int uiMaxParticles = ((FUN_00c1b850_info*)m_spModelData.m_pObject)->m_08;
    v = NiGetViewerString_00a7d490("MaxParticles", uiMaxParticles);
    uiIndex = pList->m_0a;
    if (uiIndex >= pList->m_08)
    {
        ((C_0096ad30*)pList)->FUN_0096ad30(uiIndex + pList->m_0e);
    }
    ((C_0096ae90*)pList)->FUN_0096ae90(uiIndex, &v);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct ModifierPointer
{
    NiPSysModifier* m_object;
};

struct Node
{
    Node* m_next;
    Node* m_pSecondNode;
    NiPSysModifier* m_data;
};

struct PointerList
{
    Node* m_pkHead;
    Node* m_pkTail;
    unsigned int m_uiCount;
    void __thiscall AddHead(ModifierPointer const* ptr);
    void __thiscall NiTPointerList_NiPSysModifierPtr_InsertBefore(Node* node, ModifierPointer const* ptr);
    void __thiscall FUN_00a5a310(ModifierPointer const* ptr);
};

// Inserts pkBound into m_kList ordered by m_uiUpdateOrder, ref-counting it around the list insert, then calls v9c(this) on it.
// @fnv 0x00c1b610
void NiParticleSystem::InsertSorted(NiPSysModifier* pkBound)
{
    NiPSysModifier* pBound = pkBound;
    PointerList* list = (PointerList*)&m_kModifiers;
    ModifierPointer temp;
    if (list->m_pkHead == 0)
    {
        temp.m_object = pBound;
        if (pBound != 0)
            InterlockedIncrement((long volatile*)&pBound->m_uiRefCount);
        list->AddHead(&temp);
        if (pBound != 0 && InterlockedDecrement((long volatile*)&pBound->m_uiRefCount) == 0)
            pBound->DeleteThis();
    }
    else
    {
        unsigned int key = pBound->m_uiUpdateOrder;
        Node* node = list->m_pkHead;
        bool bFound = false;
        while (node != 0)
        {
            if (node->m_data->m_uiUpdateOrder > key)
            {
                temp.m_object = pBound;
                InterlockedIncrement((long volatile*)&pBound->m_uiRefCount);
                list->NiTPointerList_NiPSysModifierPtr_InsertBefore(node, &temp);
                if (InterlockedDecrement((long volatile*)&pBound->m_uiRefCount) == 0)
                    pBound->DeleteThis();
                bFound = true;
                break;
            }
            node = node->m_next;
        }
        if (!bFound)
        {
            temp.m_object = pBound;
            InterlockedIncrement((long volatile*)&pBound->m_uiRefCount);
            list->FUN_00a5a310(&temp);
            if (InterlockedDecrement((long volatile*)&pBound->m_uiRefCount) == 0)
                pBound->DeleteThis();
        }
    }
    pBound->SetTargetSystem((::NiParticleSystem*)this);
}

namespace fnv_00c1b520 {

struct Ptr
{
    NiRefObject* m;
    Ptr& operator=(const Ptr& rhs)
    {
        if (m != rhs.m)
        {
            if (m)
                m->DecRef();
            m = rhs.m;
            if (m)
                m->AcquireReference();
        }
        return *this;
    }
};

struct Node
{
    Node* unk00;
    Node* unk04;
    Ptr unk08;
};

struct Anchor
{
    Node* unk00;
    Node* unk04;
};

struct Pool
{
    int unk00;
    Node* __thiscall NiGeometry_AddProperty();
};

struct Self
{
    Node* unk00;
    int unk04;
    Pool unk08;
    Node* __thiscall NiTPointerList_NiPSysModifierPtr_InsertBefore(Anchor* anchor, Ptr& ref);
};

// @fnv 0x00c1b520
// src: COMMUNITY 0x00c1b520
Node* __thiscall Self::NiTPointerList_NiPSysModifierPtr_InsertBefore(Anchor* anchor, Ptr& ref)
{
    Node* node = unk08.NiGeometry_AddProperty();
    node->unk08 = ref;
    node->unk00 = (Node*)anchor;
    node->unk04 = anchor->unk04;
    if (anchor->unk04)
        anchor->unk04->unk00 = node;
    else
        unk00 = node;
    anchor->unk04 = node;
    ++unk08.unk00;
    return node;
}
}  // namespace fnv_00c1b520

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern bool DAT_012024d8;
extern unsigned long DAT_012024dc;
extern unsigned char* DAT_011f5b04;
extern unsigned int DAT_011ae6e0;

NiPSysUpdateTask* __cdecl PopNiPSysUpdateTask();
struct Host_00c258e0
{
    void AssignRefAndValue(NiParticleSystem*, float);
};
struct TaskManager
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual bool Queue(NiPSysUpdateTask*, unsigned int);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    volatile bool enabled;
};
struct BoundDataBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float time;
};

// When the task manager is enabled, data time is positive, and the current thread matches the stored ID, it tries to queue a task; otherwise it calls Update.
// @fnv 0x00c1ae40
// src: XBOX_PDB 0x00c1ae40
void NiParticleSystem::UpdateSystem(float time)
{
    if (DAT_012024d8 && DAT_011f5b04 && ((TaskManager*)DAT_011f5b04)->enabled && ((BoundDataBlock*)m_spModelData.m_pObject)->time > 0.0f &&
        GetCurrentThreadId() == DAT_012024dc)
    {
        NiPSysUpdateTask* task = PopNiPSysUpdateTask();
        if (task)
        {
            ((Host_00c258e0*)task)->AssignRefAndValue(this, time);
            if (((TaskManager*)DAT_011f5b04)->Queue(task, DAT_011ae6e0))
                return;
            // NiTask exposes the original virtual release slot as vf37.
            task->vf37();
        }
    }
    Update(time);
}

struct S_00c1b0b0_Base
{
    bool NiLines_RegisterStreamables(NiStream* kStream);
};

// Calls the base routine, then invokes v21 on each linked element with kStream, and returns true if the base routine succeeds.
// @fnv 0x00c1b0b0
bool NiParticleSystem::RegisterStreamables(NiStream& stream)
{
    NiStream* kStream = &stream;
    if (!((S_00c1b0b0_Base*)this)->NiLines_RegisterStreamables(kStream))
        return false;

    for (NiTListItem<NiObject*>* pkPos = (NiTListItem<NiObject*>*)m_kModifiers.m_pkHead; pkPos;)
    {
        NiObject*& element = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        element->RegisterStreamables(*kStream);
    }

    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

template <class T> inline NiPointer<T>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::NiPointer(T* pObject)
{
    m_pObject = pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class TAlloc, class T> inline void* NiTListBase<TAlloc, T>::GetHeadPos() const
{
    return m_pkHead;
}

template <class TAlloc, class T> inline const T& NiTPointerListBase<TAlloc, T>::GetNext(void*& kPos) const
{
    const T& element = ((NiTListItem<T>*)kPos)->m_element;
    kPos = ((NiTListItem<T>*)kPos)->m_pkNext;
    return element;
}

template <class TAlloc, class T> __declspec(noinline) void NiTPointerListBase<TAlloc, T>::AddTail(const T& element) throw()
{
    NiTListItem<T>* pkNode = new NiTListItem<T>;
    pkNode->m_element = element;
    pkNode->m_pkNext = 0;
    pkNode->m_pkPrev = m_pkTail;
    if (m_pkTail)
        m_pkTail->m_pkNext = pkNode;
    else
        m_pkHead = pkNode;
    m_pkTail = pkNode;
    m_kItemCount.m_uiCount++;
}

struct ParticleCloneBase
{
    void NiParticleMeshes_CopyMembers(NiParticleSystem* destination, CloningProcess& process);
};

// Clone particle-system state, modifiers, and model data after the base clone routine.
// @fnv 0x00c1b6f0
// src: XBOX_PDB 0x00c1b6f0
void NiParticleSystem::CopyMembers_00c1b6f0(NiParticleSystem* pDest, CloningProcess& kCloning)
{
    ((ParticleCloneBase*)this)->NiParticleMeshes_CopyMembers(pDest, kCloning);

    pDest->m_bFlag = m_bFlag;

    typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiPSysModifier> > ModifierCloneList;
    ModifierCloneList& modifiers = *(ModifierCloneList*)&m_kModifiers;
    void* kPos = modifiers.GetHeadPos();
    while (kPos)
    {
        NiObject* modifier = static_cast<const ModifierCloneList&>(modifiers).GetNext(kPos);
        ((ModifierCloneList*)&pDest->m_kModifiers)->AddTail(static_cast<NiPSysModifier*>(modifier->MakeClone(kCloning)));
    }

    pDest->m_fLastTime = m_fLastTime;
    pDest->m_bD9 = m_bD9;
    *(NiPointer<NiObject>*)&pDest->m_spModelData = ((NiObject*)m_spModelData.m_pObject)->MakeClone(kCloning);
}

#include <windows.h>
namespace fnv_00c1b4a0 {

struct NiRefObjectPtr
{
    NiRefObject* m_pObject;

    NiRefObjectPtr& operator=(const NiRefObjectPtr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

typedef NiTListItem<NiRefObjectPtr> NiparticlesystemListNodeView;

struct NodePoolView
{

    void* AddHead();
};

typedef NiTPointerListBase<fnv_00c1b4a0::NodePoolView, fnv_00c1b4a0::NiRefObjectPtr > RefObjectList;


// @fnv 0x00c1b4a0
}
template <> void NiTPointerListBase<fnv_00c1b4a0::NodePoolView, fnv_00c1b4a0::NiRefObjectPtr >::AddHead(const fnv_00c1b4a0::NiRefObjectPtr& element)
{
    using namespace fnv_00c1b4a0;
    fnv_00c1b4a0::NiparticlesystemListNodeView* pkNode = (fnv_00c1b4a0::NiparticlesystemListNodeView*)m_kItemCount.AddHead();
    pkNode->m_element = element;
    pkNode->m_pkPrev = 0;
    pkNode->m_pkNext = m_pkHead;
    if (m_pkHead)
        m_pkHead->m_pkPrev = pkNode;
    else
        m_pkTail = pkNode;
    m_kItemCount.m_uiCount++;
    m_pkHead = pkNode;
}
namespace fnv_00c1b4a0 {
}  // namespace fnv_00c1b4a0
