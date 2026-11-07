// staging/blk_00c20000_o2.cpp: NiPSysParticle, NiPSysBoxEmitter, Host, NiPSysBoxEmitterWrapper and more (45 functions)

#include <windows.h>
// src/staging/blk_00c20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BSFadeNode.h"
#include "../../include/NiLODData.h"
#include "../../include/NiPSysBoxEmitter.h"
#include "../../include/NiPSysModifier.h"
#include "../../include/NiPSysPositionModifier.h"

extern int DAT_010be35c;

// @fnv 0x00c25820
// src: EXE 0x00c25820
BSFadeNode* __cdecl BSStripParticleSystem_CreateObject()
{
    BSFadeNode* node = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x110));
    if (node)
    {
        node->NiParticleSystem_00c1b5c0();
        *reinterpret_cast<void**>(node) = reinterpret_cast<void*>(&DAT_010be35c);
        return node;
    }
    return 0;
}

namespace fnv_00c28b20 {
extern "C" void* DAT_010bea54;

// Allocates a NiPSysPositionModifier, runs its constructor, sets its vtable, and returns it (or null on allocation failure).
// @fnv 0x00c28b20
// src: EXE 0x00c28b20
NiPSysPositionModifier* NiPSysPositionModifier_CreateObject()
{
    NiPSysPositionModifier* p = (NiPSysPositionModifier*)BSFadeNode::operator new(0x18);
    if (p)
    {
        p->NiPSysPositionModifier::NiPSysPositionModifier();
        *reinterpret_cast<void**>(p) = &DAT_010bea54;
        return p;
    }
    return 0;
}
}  // namespace fnv_00c28b20

namespace fnv_00c29d00 {
void* __fastcall NiPSysModifierBoolCtlr_NiPSysModifierBoolCtlr(void* self);
extern int DAT_010bebbc;

// @fnv 0x00c29d00
// src: EXE 0x00c29d00
void* __cdecl NiPSysModifierActiveCtlr_CreateObject()
{
    void* p = BSFadeNode::operator new(0x40);
    if (p)
    {
        NiPSysModifierBoolCtlr_NiPSysModifierBoolCtlr(p);
        *reinterpret_cast<void**>(p) = &DAT_010bebbc;
        return p;
    }
    return 0;
}
}  // namespace fnv_00c29d00

namespace fnv_00c2a050 {
extern int DAT_010beebc;

// @fnv 0x00c2a050
// src: EXE 0x00c2a050
BSFadeNode* __cdecl NiPSysInitialRotAngleVarCtlr_CreateObject()
{
    void* p = BSFadeNode::operator new(0x40);
    if (p)
    {
        BSFadeNode* q = reinterpret_cast<BSFadeNode*>(p);
        q->FUN_00c32d80();
        *reinterpret_cast<int**>(p) = &DAT_010beebc;
        return q;
    }
    return 0;
}
}  // namespace fnv_00c2a050

namespace fnv_00c2a870 {
extern int DAT_010bf1ac;

// @fnv 0x00c2a870
// src: EXE 0x00c2a870
void* __cdecl NiPSysGravityStrengthCtlr_CreateObject()
{
    void* p = BSFadeNode::operator new(0x40);
    if (p)
    {
        reinterpret_cast<BSFadeNode*>(p)->FUN_00c32d80();
        *reinterpret_cast<void**>(p) = &DAT_010bf1ac;
        return p;
    }
    return 0;
}
}  // namespace fnv_00c2a870

namespace fnv_00c2b110 {
extern int DAT_010bf454;

// Allocates a 0x40-byte BSFadeNode, constructs it, sets its vtable to DAT_010bf454, and returns the pointer or 0 on allocation failure.
// @fnv 0x00c2b110
// src: EXE 0x00c2b110
void* __cdecl NiPSysFieldMagnitudeCtlr_CreateObject()
{
    void* p = BSFadeNode::operator new(0x40);
    if (p)
    {
        ((BSFadeNode*)p)->FUN_00c32d80();
        *reinterpret_cast<void**>(p) = &DAT_010bf454;
        return p;
    }
    return 0;
}
}  // namespace fnv_00c2b110

namespace fnv_00c2b200 {
extern int DAT_010bf554;

// Allocates a 0x40-byte BSFadeNode, calls Init on it, sets its vtbl to DAT_010bf554 and returns it, or returns 0 on allocation failure.
// @fnv 0x00c2b200
// src: EXE 0x00c2b200
void* NiPSysFieldAttenuationCtlr_CreateObject()
{
    BSFadeNode* node = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x40));
    if (node)
    {
        BSFadeNode* obj = reinterpret_cast<BSFadeNode*>(node);
        obj->FUN_00c32d80();
        *reinterpret_cast<void**>(node) = &DAT_010bf554;
        return node;
    }
    return 0;
}
}  // namespace fnv_00c2b200

namespace fnv_00c2b620 {
extern "C" void* DAT_010bf954;

// Allocates a 0x40-byte BSFadeNode, calls Init on it, sets its vtable to DAT_010bf954 and returns it, or returns null if allocation fails.
// @fnv 0x00c2b620
// src: EXE 0x00c2b620
void* __cdecl NiPSysEmitterLifeSpanCtlr_CreateObject()
{
    void* p = BSFadeNode::operator new(0x40);
    if (p)
    {
        BSFadeNode* q = (BSFadeNode*)p;
        q->FUN_00c32d80();
        *(void**)q = &DAT_010bf954;
        return q;
    }
    return 0;
}
}  // namespace fnv_00c2b620

namespace fnv_00c2b720 {
// @fnv 0x00c2b720
// src: EXE 0x00c2b720
void* __cdecl NiPSysEmitterInitialRadiusCtlr_CreateObject()
{
    BSFadeNode* node = (BSFadeNode*)BSFadeNode::operator new(0x40);
    if (node)
    {
        BSFadeNode* obj = (BSFadeNode*)node;
        obj->FUN_00c32d80();
        *reinterpret_cast<void**>(node) = (void*)0x010bfa54;
        return node;
    }
    return 0;
}
}  // namespace fnv_00c2b720

namespace fnv_00c2b870 {
extern const void* DAT_010bfb54;

// @fnv 0x00c2b870
// src: EXE 0x00c2b870
BSFadeNode* __cdecl NiPSysEmitterDeclinationVarCtlr_CreateObject()
{
    BSFadeNode* p = (BSFadeNode*)BSFadeNode::operator new(0x40);
    if (p)
    {
        p->FUN_00c32d80();
        *reinterpret_cast<const void**>(p) = &DAT_010bfb54;
        return p;
    }
    return 0;
}
}  // namespace fnv_00c2b870

namespace fnv_00c30600 {
extern void* DAT_010c05e4;

// @fnv 0x00c30600
// src: EXE 0x00c30600
void* __cdecl NiPSysAirFieldInheritVelocityCtlr_CreateObject()
{
    void* p = BSFadeNode::operator new(0x40);
    if (p)
    {
        reinterpret_cast<BSFadeNode*>(p)->FUN_00c32d80();
        *reinterpret_cast<void**>(p) = &DAT_010c05e4;
        return p;
    }
    return 0;
}
}  // namespace fnv_00c30600

void __fastcall FUN_00a6d220(void*);
extern int DAT_010be6b4;

// @fnv 0x00c270f0
// src: EXE 0x00c270f0
BSFadeNode* __cdecl NiPSysUpdateCtlr_CreateObject()
{
    BSFadeNode* node = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x34));
    if (node)
    {
        FUN_00a6d220(node);
        *(float*)((char*)node + 0x18) = 0.0f;
        *(int**)((char*)node + 0) = &DAT_010be6b4;
        *(float*)((char*)node + 0x14) = 0.0f;
        return node;
    }
    return 0;
}

extern float _DAT_01015f5c;
extern int DAT_010be8e4;
void __fastcall FUN_00a6d220(void*);

// @fnv 0x00c283b0
// src: EXE 0x00c283b0
BSFadeNode* __cdecl NiPSysResetOnLoopCtlr_CreateObject()
{
    BSFadeNode* p = (BSFadeNode*)BSFadeNode::operator new(0x38);
    if (p)
    {
        FUN_00a6d220(p);
        *(float*)((char*)p + 0x34) = _DAT_01015f5c;
        *(int*)p = (int)&DAT_010be8e4;
        return p;
    }
    return 0;
}

extern int DAT_010bfd54;
// @fnv 0x00c2ba60
// src: EXE 0x00c2ba60
BSFadeNode* __cdecl NiPSysEmitterCtlrData_CreateObject()
{
    BSFadeNode* p = (BSFadeNode*)BSFadeNode::operator new(0x28);
    if (p)
    {
        NiLODData* pLodData = (NiLODData*)p;
        pLodData->NiLODData::NiLODData();
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 12) = 0;
        *(int*)((char*)p + 16) = 0;
        *(int*)((char*)p + 24) = 0;
        *(int*)((char*)p + 28) = 0;
        *(int*)((char*)p + 32) = 0;
        *(int*)p = (int)&DAT_010bfd54;
    }
    else
    {
        p = 0;
    }
    return p;
}

extern int DAT_010bff2c;
extern int _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;

struct FUN_00c31ff0
{
    void* vtbl;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    void Init();
};

// Allocates a 0x40-byte FUN_00c31ff0, calls Init, sets its vtbl and initializes m_30, m_34, m_38 and m_3c; returns null on allocation failure.
// @fnv 0x00c2c7b0
// src: EXE 0x00c2c7b0
FUN_00c31ff0* __cdecl NiPSysDragFieldModifier_CreateObject()
{
    FUN_00c31ff0* p = (FUN_00c31ff0*)BSFadeNode::operator new(0x40);
    if (p)
    {
        p->Init();
        p->vtbl = (void*)&DAT_010bff2c;
        *(char*)&p->m_30 = 0;
        p->m_34 = _NiPoint3_ZERO;
        p->m_38 = _DAT_011f4270;
        p->m_3c = _DAT_011f4274;
    }
    else
    {
        p = 0;
    }
    return p;
}

struct CloningProcess;
struct NiPSysParticle
{
    char m_auiShapeKeys[0x18];
    NiPSysModifier* m_pSys;
    float m_fXValue;
    float m_fLife;
    unsigned char m_ucSpawnGeneration;
    float m_fMass;
    float m_pfTreeSize;
    void NiPSysFieldModifier_CopyMembers(NiPSysParticle* dst, CloningProcess* proc);
};
// @fnv 0x00c32020
// src: XBOX_PDB 0x00c32020
void NiPSysParticle::NiPSysFieldModifier_CopyMembers(NiPSysParticle* dst, CloningProcess* proc)
{
    ((NiPSysModifier*)this)->CopyMemberData((NiPSysModifier*)dst, *proc);
    dst->m_pSys = m_pSys;
    dst->m_fXValue = m_fXValue;
    dst->m_fLife = m_fLife;
    dst->m_ucSpawnGeneration = m_ucSpawnGeneration;
    dst->m_fMass = m_fMass;
    dst->m_pfTreeSize = m_pfTreeSize;
}

extern int DAT_010c01ec;
extern int DAT_011a946c;
extern int DAT_011a9470;
extern int DAT_011a9474;

// Allocates a 0x38-byte NiPSysPositionModifier, runs its constructor, sets the vtable and initializes fields from globals and zero, returning the object or null.
// @fnv 0x00c2e4c0
// src: EXE 0x00c2e4c0
NiPSysPositionModifier* NiPSysBombModifier_CreateObject()
{
    NiPSysPositionModifier* p = static_cast<NiPSysPositionModifier*>(BSFadeNode::operator new(0x38));
    if (p)
    {
        p->NiPSysPositionModifier::NiPSysPositionModifier();
        *reinterpret_cast<void**>(p) = &DAT_010c01ec;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x18) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x1c) = DAT_011a946c;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x20) = DAT_011a9470;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x24) = DAT_011a9474;
        *reinterpret_cast<float*>(reinterpret_cast<char*>(p) + 0x28) = 0.0f;
        *reinterpret_cast<float*>(reinterpret_cast<char*>(p) + 0x2c) = 0.0f;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x30) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x34) = 0;
        return p;
    }
    return 0;
}

struct FUN_00c31ff0_ctor_helper
{
    void FUN_00c31ff0();
};

extern int DAT_010be604;

// Allocates a 0x3c-byte object, runs its constructor, sets its vtable and initializes three fields at offsets 0x30-0x38, returning the object or null.
// @fnv 0x00c26790
// src: EXE 0x00c26790
FUN_00c31ff0* __cdecl NiPSysVortexFieldModifier_CreateObject()
{
    FUN_00c31ff0* p = (FUN_00c31ff0*)BSFadeNode::operator new(0x3c);
    if (p)
    {
        ((FUN_00c31ff0_ctor_helper*)p)->FUN_00c31ff0();
        p->vtbl = (void*)&DAT_010be604;
        *(int*)((char*)p + 0x30) = _NiPoint3_ZERO;
        *(int*)((char*)p + 0x34) = _DAT_011f4270;
        *(int*)((char*)p + 0x38) = _DAT_011f4274;
        return p;
    }
    return 0;
}


// @fnv 0x00c21f60
void NiPSysBoxEmitter::CopyTo(NiPSysModifier* pkDest, CloningProcess& kProcess)
{
    CopyMemberData(pkDest, kProcess);
    float* pSrc = (float*)((char*)this + 0x18);
    float* pDst = (float*)((char*)pkDest + 0x18);
    pDst[0] = pSrc[0];
    pDst[1] = pSrc[1];
    pDst[2] = pSrc[2];
    pDst[3] = pSrc[3];
    pDst[4] = pSrc[4];
    pDst[5] = pSrc[5];
    *(int*)((char*)pkDest + 0x30) = *(int*)((char*)this + 0x30);
    *(int*)((char*)pkDest + 0x34) = *(int*)((char*)this + 0x34);
    *(int*)((char*)pkDest + 0x38) = *(int*)((char*)this + 0x38);
    *(int*)((char*)pkDest + 0x3c) = *(int*)((char*)this + 0x3c);
    *(float*)((char*)pkDest + 0x40) = *(float*)((char*)this + 0x40);
    *(float*)((char*)pkDest + 0x48) = *(float*)((char*)this + 0x48);
    *(float*)((char*)pkDest + 0x4c) = *(float*)((char*)this + 0x4c);
    *(float*)((char*)pkDest + 0x44) = *(float*)((char*)this + 0x44);
}

struct FUN_00c22ad0_object : BSFadeNode
{
    BSFadeNode* InitDefaults();
};

// @fnv 0x00c22ad0
// src: EXE 0x00c22ad0
BSFadeNode* NiPSysGravityModifier_CreateObject()
{
    FUN_00c22ad0_object* object = static_cast<FUN_00c22ad0_object*>(BSFadeNode::operator new(0x40));

    if (object)
        return object->InitDefaults();

    return 0;
}

struct FUN_00c24c90
{
    void* m_vtbl;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    FUN_00c24c90();
};
extern int DAT_010be514;
// Allocates a 0x90-byte FUN_00c24c90, runs its constructor, sets the vtable to DAT_010be514 and clears m_7c, returning the object or null.
// @fnv 0x00c25ca0
FUN_00c24c90* __cdecl CreateFUN_00c24c90()
{
    FUN_00c24c90* p = (FUN_00c24c90*)BSFadeNode::operator new(0x90);
    if (p)
    {
        p->FUN_00c24c90::FUN_00c24c90();
        p->m_vtbl = (void*)&DAT_010be514;
        p->m_7c = 0;
        return p;
    }
    return 0;
}

extern float DAT_01022958;
extern int DAT_010be774;

// Allocates a 0x3c-byte object, calls Init, sets fields at offsets 0x30/0x34/0x38 and the vtable pointer, then returns it (or null).
// @fnv 0x00c27350
// src: EXE 0x00c27350
FUN_00c31ff0* __cdecl NiPSysTurbulenceFieldModifier_CreateObject()
{
    FUN_00c31ff0* p = (FUN_00c31ff0*)BSFadeNode::operator new(0x3c);
    if (p)
    {
        p->Init();
        *(float*)((char*)p + 0x30) = 0.0f;
        *(int*)p = (int)&DAT_010be774;
        *(float*)((char*)p + 0x38) = _DAT_01015f5c;
        *(float*)((char*)p + 0x34) = DAT_01022958;
        return p;
    }
    return 0;
}

extern int DAT_010be99c;
// Allocates a 0x34-byte object, calls Init, sets a float at offset 0x30 to 0.0f and installs the vtable at DAT_010be99c, returning the object or null.
// @fnv 0x00c28570
// src: EXE 0x00c28570
FUN_00c31ff0* __cdecl NiPSysRadialFieldModifier_CreateObject()
{
    FUN_00c31ff0* p = (FUN_00c31ff0*)BSFadeNode::operator new(0x34);
    if (p)
    {
        p->Init();
        *(float*)((char*)p + 0x30) = 0.0f;
        p->vtbl = &DAT_010be99c;
        return p;
    }
    return 0;
}

struct Host
{
    void UpdateFields_00c312a0();
    Host* DestroyIfRequested(bool bFree);
    static void __cdecl operator delete(void*, unsigned int);
};
// Calls FUN_00c312a0, then deletes this (size 0x40) when bFree is set, and returns this.
// @fnv 0x00c2a090
Host* Host::DestroyIfRequested(bool bFree)
{
    UpdateFields_00c312a0();
    if (bFree & 1)
        operator delete(this, 0x40);
    return this;
}

extern int DAT_010bf354;
// Allocates a 0x40-byte object, constructs it, sets its vtable to DAT_010bf354, and returns it (or null on allocation failure).
// @fnv 0x00c2b010
// src: EXE 0x00c2b010
BSFadeNode* __cdecl NiPSysFieldMaxDistanceCtlr_CreateObject()
{
    BSFadeNode* p = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x40));
    if (p)
    {
        p->FUN_00c32d80();
        *reinterpret_cast<void**>(p) = &DAT_010bf354;
        return p;
    }
    return 0;
}

extern int DAT_010c0304;

// Allocates a 0x20-byte NiPSysPositionModifier, constructs it, sets its vtable and clears fields at offsets 0x18 and 0x1c, returning the new object or null.
// @fnv 0x00c2ef20
// src: EXE 0x00c2ef20
NiPSysPositionModifier* NiPSysAgeDeathModifier_CreateObject()
{
    NiPSysPositionModifier* p = (NiPSysPositionModifier*)BSFadeNode::operator new(0x20);
    if (p)
    {
        p->NiPSysPositionModifier::NiPSysPositionModifier();
        *reinterpret_cast<void**>(p) = &DAT_010c0304;
        *(unsigned char*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x1c) = 0;
        return p;
    }
    return 0;
}

namespace fnv_00c30790 {
extern int DAT_010c06e4;

// @fnv 0x00c30790
// src: EXE 0x00c30790
void* NiPSysAirFieldAirFrictionCtlr_CreateObject(void)
{
    BSFadeNode* p = (BSFadeNode*)BSFadeNode::operator new(0x40);
    if (p)
    {
        p->FUN_00c32d80();
        *(int*)p = (int)&DAT_010c06e4;
        return p;
    }
    return 0;
}
}  // namespace fnv_00c30790

extern int DAT_010bdff4;
extern int DAT_011a946c;
extern int DAT_011a9470;
extern int DAT_011a9474;

struct FUN_00c22a80_cls : NiPSysPositionModifier
{
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    float m_28;
    float m_2c;
    int m_30;
    float m_34;
    float m_38;

    FUN_00c22a80_cls* InitDefaults();
};

// Calls InitBase, sets the vtable pointer and initialises the object's fields to zero, one and the DAT_011a946c/9470/9474 values, then returns this.
// @fnv 0x00c22a80
FUN_00c22a80_cls* FUN_00c22a80_cls::InitDefaults()
{
    this->NiPSysPositionModifier::NiPSysPositionModifier();
    m_18 = 0;
    *reinterpret_cast<int*>(this) = (int)&DAT_010bdff4;
    m_1c = DAT_011a946c;
    m_20 = DAT_011a9470;
    m_24 = DAT_011a9474;
    m_28 = 0.0f;
    m_2c = 1.0f;
    m_30 = 0;
    m_34 = 0.0f;
    m_38 = 1.0f;
    return this;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_010be124;

struct FUN_00c23b20_cls
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_18;
    unsigned short unk1a;
    float m_1c;
    unsigned short m_20;
    unsigned short m_22;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    void ctorBase();
};

// Allocates a 0x34-byte object, runs its base constructor, sets default float and ushort fields and the vtable, and returns it (or null on allocation failure).
// @fnv 0x00c23b20
// src: EXE 0x00c23b20
void* __cdecl NiPSysSpawnModifier_CreateObject()
{
    FUN_00c23b20_cls* p = (FUN_00c23b20_cls*)Object_DispatchCommandFour(0x34);
    if (p != 0)
    {
        p->ctorBase();
        p->m_1c = 1.0f;
        p->m_24 = 0.0f;
        p->m_28 = 0.0f;
        p->m_2c = 0.0f;
        p->m_18 = 1;
        p->m_30 = 0.0f;
        p->m_vtbl = (void*)&DAT_010be124;
        p->m_20 = 1;
        p->m_22 = 1;
        return p;
    }
    return 0;
}

class C29E50Base
{
  public:
    C29E50Base() throw();
    virtual ~C29E50Base();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

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
};

class C29E50Object : public C29E50Base
{
  public:
    C29E50Object() throw()
    {}
    virtual ~C29E50Object();
};

// Allocates and constructs a new C29E50Object and returns it.
// @fnv 0x00c29e50
C29E50Object* __cdecl CreateC29E50Object()
{
    return new C29E50Object;
}

extern int DAT_010bedbc;

// Allocates a ParticleFactoryObject, calls Initialize, sets its vtable to DAT_010bedbc, and returns it (or null on allocation failure).
// @fnv 0x00c29f50
BSFadeNode* CreateParticleFactoryObject()
{
    BSFadeNode* object =
        static_cast<BSFadeNode*>(BSFadeNode::operator new(0x40));
    if (object)
    {
        object->FUN_00c32d80();
        *reinterpret_cast<void**>(object) = &DAT_010bedbc;
        return object;
    }
    return 0;
}

extern int DAT_010befbc;

void* operator new(unsigned int, void* memory)
{
    return memory;
}

// Allocates a ParticleObjectFactoryType with BSFadeNode::operator new and constructs it in place, returning null if allocation fails.
// @fnv 0x00c2a160
BSFadeNode* CreateParticleObjectFactory()
{
    BSFadeNode* object = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x40));
    if (object)
    {
        object->FUN_00c32d80();
        *reinterpret_cast<void**>(object) = &DAT_010befbc;
        return object;
    }
    return 0;
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);

// @fnv 0x00c2a2b0
// src: EXE 0x00c2a2b0
void* __cdecl NiPSysGrowFadeModifier_CreateObject()
{
    void* pObject = Object_DispatchCommandFour(0x2c);
    if (pObject != NULL)
    {
        reinterpret_cast<NiPSysPositionModifier*>(pObject)->NiPSysPositionModifier::NiPSysPositionModifier();
        float zero = 0.0f;
        *(float*)((char*)pObject + 0x18) = zero;
        *(float*)((char*)pObject + 0x20) = zero;
        *(short*)((char*)pObject + 0x1c) = 0;
        *(float*)((char*)pObject + 0x28) = zero;
        *(int*)pObject = 0x10bf0bc;
        *(short*)((char*)pObject + 0x24) = 0;
        return pObject;
    }
    return NULL;
}

extern int DAT_010bf654;

// Allocates a ParticleEmitterAllocation, calls Initialize, sets its vtable to DAT_010bf654, and returns it (or null on allocation failure).
// @fnv 0x00c2b330
BSFadeNode* CreateParticleEmitterAllocation()
{
    BSFadeNode* emitter =
        static_cast<BSFadeNode*>(BSFadeNode::operator new(0x40));
    if (emitter)
    {
        emitter->FUN_00c32d80();
        *reinterpret_cast<void**>(emitter) = &DAT_010bf654;
        return emitter;
    }
    return 0;
}


class NiPSysModC2D : public NiPSysPositionModifier
{
  public:
    NiPSysModC2D() : m_usA(0), m_usB(0), m_uiC(0)
    {}
    virtual ~NiPSysModC2D();

    unsigned short m_usA;
    unsigned short m_usB;
    unsigned int m_uiC;
};

// Allocates and constructs a new NiPSysModC2D object, returning it as a NiPSysPositionModifier pointer.
// @fnv 0x00c2d690
NiPSysPositionModifier* CreateNiPSysModC2D()
{
    return new NiPSysModC2D;
}

struct FUN_00c2e550_StandIn
{
    unsigned int __thiscall FUN_00c2e550(unsigned char flags);
};

void __cdecl FUN_00c31750();
void __cdecl FUN_00aa1460(void* object, unsigned int size);

// @fnv 0x00c2e550
unsigned int __thiscall FUN_00c2e550_StandIn::FUN_00c2e550(unsigned char flags)
{
    FUN_00c31750();
    if ((flags & 1) != 0)
    {
        FUN_00aa1460(this, 0x38);
    }
    return reinterpret_cast<unsigned int>(this);
}

extern "C" char* DAT_0109b220;
extern "C" void* DAT_010c08ac;
extern "C" void(__stdcall* DAT_00fdf1c0)(void*);
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);

struct NiStringBaseHelper
{
    void FUN_00a38e00();
};

struct FUN_00c31440_cls
{
    void* vptr;
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
    char* m_38;
    int m_3c;

    FUN_00c31440_cls* AssignString(char** src);
};

// @fnv 0x00c31440
FUN_00c31440_cls* FUN_00c31440_cls::AssignString(char** src)
{
    reinterpret_cast<NiStringBaseHelper*>(this)->FUN_00a38e00();
    vptr = (void*)&DAT_010c08ac;
    *(char* volatile*)&m_38 = DAT_0109b220;
    m_3c = 0;
    char* edi = *src;
    if (m_38 != edi)
    {
        if (edi != DAT_0109b220)
        {
            DAT_00fdf1c0(edi - 8);
        }
        if (m_38 != DAT_0109b220)
        {
            DAT_00fdf1c4(m_38 - 8);
        }
        m_38 = edi;
    }
    return this;
}

// Factory: allocates a 0x40-byte object, runs the FUN_00c32d80 base constructor and
// installs this type's vtable (same pattern as ParticleObjectFactoryType / CreateParticleObjectFactory).
extern int DAT_010bf754;
// Allocates and constructs a PSysFactoryObject, returning the new instance.
// @fnv 0x00c2b420
BSFadeNode* __cdecl CreatePSysFactoryObject()
{
    BSFadeNode* object = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x40));
    if (object)
    {
        object->FUN_00c32d80();
        *reinterpret_cast<void**>(object) = &DAT_010bf754;
        return object;
    }
    return 0;
}

extern int DAT_010bfc54;

// Allocates a 0x40-byte object, constructs a FUN_00c32d80 base in place, sets its vtable to DAT_010bfc54 and returns it, or returns 0 on allocation failure.
// @fnv 0x00c2b970
// src: EXE 0x00c2b970
BSFadeNode* NiPSysEmitterDeclinationCtlr_CreateObject()
{
    BSFadeNode* obj = (BSFadeNode*)Object_DispatchCommandFour(0x40);
    if (obj)
    {
        obj->FUN_00c32d80();
        *(int**)obj = &DAT_010bfc54;
        return obj;
    }
    return 0;
}

extern int DAT_010bf854;
// Allocates and constructs a new PSysFactoryObjectB52 and returns it.
// @fnv 0x00c2b520
BSFadeNode* __cdecl CreatePSysFactoryObjectB52()
{
    BSFadeNode* object = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x40));
    if (object)
    {
        object->FUN_00c32d80();
        *reinterpret_cast<void**>(object) = &DAT_010bf854;
        return object;
    }
    return 0;
}

extern bool __cdecl IsEquivalentTo(int param1, int param2);

// @fnv 0x00c32df0
// src: XBOX_PDB 0x00c32df0
bool __cdecl NiPSysModifierBoolCtlr_IsEqual(int param1, int param2)
{
    return IsEquivalentTo(param1, param2);
}

struct NiPSysBoxEmitterWrapper : NiPSysBoxEmitter
{
    void NiPSysVolumeEmitter_CopyMembers(NiPSysModifier* destination, CloningProcess& process);
};

// @fnv 0x00c31b10
// src: XBOX_PDB 0x00c31b10
void NiPSysBoxEmitterWrapper::NiPSysVolumeEmitter_CopyMembers(NiPSysModifier* destination, CloningProcess& process)
{
    CopyTo(destination, process);
}

struct TrailVector
{
    float x, y, z;
};
struct TrailColor
{
    float r, g, b, a;
};
struct TrailRecord
{
    TrailVector position;
    TrailVector direction;
    TrailVector axis0, axis1, axis2;
    TrailVector tangent, normal, binormal, auxiliary;
    TrailColor color;
    float size, scale;
    float Radius() const
    {
        return scale * size;
    }
};
struct TrailBuffer
{
    TrailRecord* records;
    unsigned short count, added;
    int remaining, unk0c;
    int capacity, first, next, unk1c;
};
struct TrailParticle
{
    float unk00, unk04, unk08, age, lifetime, unk14, unk18;
};
struct TrailFrame
{
    TrailVector* tangent;
    TrailVector* normal;
    TrailVector* binormal;
};
void __cdecl NiRenderer_PackParticleStripUtil_GetVerts(TrailFrame*, TrailRecord*, TrailVector*, float, TrailVector*, TrailVector*, TrailVector*);
struct TrailSystem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    TrailVector* positions;
    int unk24;
    TrailColor* colors;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    float* scales;
    int unk50;
    float* sizes;
    int unk58, unk5c, unk60, unk64, unk68, unk6c;
    TrailParticle* particles;
    int unk74, unk78;
    TrailBuffer* buffers;
    unsigned short maxCount;
    void AddTrailPoint(unsigned short index, float unused);
};
// Adds a new trail record at the particle's current position, updating the ring buffer's count, first, and next indices.
// @fnv 0x00c26120
void TrailSystem::AddTrailPoint(unsigned short index, float unused)
{
    if (particles[index].age > particles[index].lifetime)
        return;
    TrailBuffer* buffer = &buffers[index];
    TrailFrame frame = {0, 0, 0};
    int previous = (buffers[index].next - 1) % buffer->capacity;
    if (previous < 0)
        previous += buffer->capacity;
    if (buffer->count > 0)
    {
        if (buffer->count > 1)
        {
            int before = (previous - 1) % buffer->capacity;
            if (before < 0)
                before += buffer->capacity;
            frame.tangent = &buffer->records[before].tangent;
            frame.normal = &buffer->records[before].normal;
            frame.binormal = &buffer->records[before].binormal;
        }
        NiRenderer_PackParticleStripUtil_GetVerts(&frame, &buffer->records[previous], &positions[index], buffer->records[previous].Radius(),
                     &buffer->records[previous].direction, &buffer->records[previous].normal,
                     &buffer->records[previous].tangent);
    }
    else
    {
        buffer->first = 0;
    }
    int next = buffer->next;
    if (buffer->count > 0)
    {
        int before = (next - 1) % buffer->capacity;
        if (before < 0)
            before += buffer->capacity;
        frame.tangent = &buffer->records[before].tangent;
        frame.normal = &buffer->records[before].normal;
        frame.binormal = &buffer->records[before].binormal;
    }
    else
    {
        frame.tangent = 0;
        frame.normal = 0;
        frame.binormal = 0;
    }
    buffer->records[next].position = positions[index];
    buffer->records[next].size = sizes[index];
    buffer->records[next].scale = scales[index];
    if (colors)
        buffer->records[next].color = colors[index];
    NiRenderer_PackParticleStripUtil_GetVerts(&frame, &buffer->records[next], 0, buffer->records[next].Radius(), &buffer->records[next].direction,
                 &buffer->records[next].normal, &buffer->records[next].tangent);
    if (buffer->count < maxCount)
    {
        ++buffer->added;
        ++buffer->count;
        --buffer->remaining;
    }
    else
    {
        int first = (buffer->first + 1) % buffer->capacity;
        if (first < 0)
            first += buffer->capacity;
        buffer->first = first;
    }
    int newNext = (buffer->next + 1) % buffer->capacity;
    if (newNext < 0)
        newNext += buffer->capacity;
    buffer->next = newNext;
}

extern int DAT_010c09cc;
extern char* DAT_0109b220;
// Sets the vtable pointer, releases the name string, then destroys the NiObject base.
// Kept as an explicit helper to preserve the original destruction sequence.
// @fnv 0x00c31750
void __fastcall DestroyPositionModifier(NiPSysPositionModifier* self)
{
    *reinterpret_cast<void* volatile*>(self) = &DAT_010c09cc;
    char* value = *reinterpret_cast<char* volatile*>(&self->m_kName.m_kHandle);
    if (value != DAT_0109b220)
        InterlockedDecrement(reinterpret_cast<volatile LONG*>(value - 8));
    self->FUN_00a5d3d0();
}

typedef int(__stdcall* HostRefFn)(void*);

struct Host_refobj
{
    virtual void FUN_slot0();
    virtual void Destroy();
    int m_iObjectReferenceCount;
};

struct Host_base
{
    void FUN_00a6d290();
};

struct Host_data
{
    void* m_vptr;
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
    Host_refobj* m_pEntryObject;
    void* m_pData;
    void UpdateFields_00c312a0();
};

// Sets m_vptr, releases m_pData's header (unless DAT_0109b220), drops m_pEntryObject's refcount and destroys it at zero, then calls FUN_00a6d290.
// @fnv 0x00c312a0
// src: GUESS 0x00c312a0 (confidence: low)
void Host_data::UpdateFields_00c312a0()
{
    Host_data* self = this;
    HostRefFn release = (HostRefFn)DAT_00fdf1c4;
    *(void* volatile*)&self->m_vptr = &DAT_010c08ac;
    void* data = *(void* volatile*)&self->m_pData;
    if (data != DAT_0109b220)
    {
        release((char*)data - 8);
    }
    Host_refobj* obj = self->m_pEntryObject;
    if (obj != 0)
    {
        if (release((char*)obj + 4) == 0)
        {
            obj->Destroy();
        }
    }
    ((Host_base*)this)->FUN_00a6d290();
}
