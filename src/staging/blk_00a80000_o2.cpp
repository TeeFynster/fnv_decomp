
// src/staging/blk_00a80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <stddef.h>
#include "../../include/NiPoint3.h"
#include "../../include/Ni2DBuffer.h"
#include "../../include/NiDepthStencilBuffer.h"
#include "../../include/NiPointer.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
#include "../../include/MemoryManager.h"
#include "../../include/NiPixelFormat.h"
#include "../../include/NiTFixedStringMap_NiAVObject___.h"
#include "../../include/BSFadeNode.h"
#include "../../include/NiAlphaAccumulator.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiBound.h"
#include "../../include/NiCollisionObject.h"
#include "../../include/NiCullingProperty.h"
#include "../../include/NiDirectionalLight.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiLODData.h"
#include "../../include/NiParticleMeshes.h"
#include "../../include/NiProperty.h"
#include "../../include/NiRefObject.h"
// NiStreamLinkIDSet_blk_00a80000_o2: local type (was include/NiStreamLinkIDSet.h, which had no evidence of one real class); its methods are 0x00a311e0 NiTSet<NiScreenGeometryData::ScreenElement *,NiTMallocInterface<NiScreenGeometryData::ScreenElement *> >::Add, 0x00a543b0 NiTSet::Ptr::Add
class Item;
class NiGeomMorpherUpdateTask;
class D3DRenderStateGroup;

class NiStreamLinkIDSet_blk_00a80000_o2
{
public:
    void* m_kPointA;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void Realloc(unsigned int);
    void ProcessEntries_00a56e60(unsigned int ItemUpdateArray);
    unsigned int Find(Item* item);
    int Find(unsigned int value);
    void Add(Item* item);
    void Add(NiGeomMorpherUpdateTask* pkTask);
    void Add(D3DRenderStateGroup* p);
    void AddUnique(Item* item);
};
#include "../../include/NiTransform.h"
#include "../../include/Pair.h"
#include "../../include/NiMatrix3.h"


extern "C" void __cdecl _Call_a5d3a0();
extern const void* NiCollisionObject_vftable;

// @fnv 0x00a80fa0
NiCollisionObject* NiCollisionObject::Construct()
{
    _Call_a5d3a0();
    *(void**)this = (void*)&NiCollisionObject_vftable;
    m_pkSceneObject = 0;
    return this;
}

extern unsigned char* DAT_011f5b04;
void __cdecl NiParallelUpdateTaskManager_WaitRenderSema(int);

// @fnv 0x00a81a20
// src: COMMUNITY 0x00a81a20
void __cdecl NiParallelUpdateTaskManager_BeginUpdate()
{
    if (DAT_011f5b04)
    {
        DAT_011f5b04[0x1b0] = 1;
        NiParallelUpdateTaskManager_WaitRenderSema(-1);
    }
}

// @fnv 0x00a81b80
// src: GAMEBRYO_LIB 0x00a81b80
int __cdecl NiSkinData_BoneVertData_Compare(const unsigned short* ausLeft, const unsigned short* ausRight)
{
    if (*ausLeft < *ausRight)
        return -1;
    return *ausLeft > *ausRight;
}

extern const void* DAT_0109e984;
// Allocates a 0xc4-byte BSFadeNode, runs Init on it, sets its vtbl to DAT_0109e984 and returns it, or returns 0 on allocation failure.
// @fnv 0x00a877a0
// src: EXE 0x00a877a0
BSFadeNode* NiScreenElements_CreateObject()
{
    BSFadeNode* node = static_cast<BSFadeNode*>(BSFadeNode::operator new(0xc4));
    if (node) {
        node->FUN_00a744a0();
        *(const void**)node = &DAT_0109e984;
        return node;
    }
    return 0;
}

struct FUN_00a87900_class {
    void NiScreenElementsData_UpdateBound();
};

// @fnv 0x00a87900
// src: XBOX_PDB 0x00a87900
void FUN_00a87900_class::NiScreenElementsData_UpdateBound()
{
    *(unsigned char*)((char*)this + 0x6e) = 0;
    if (*(unsigned short*)((char*)this + 8) > 0) {
        ((NiBound*)((char*)this + 0x10))->ComputeFromPoints(*(unsigned short*)((char*)this + 8), *(const NiPoint3**)((char*)this + 0x20));
    }
}

extern int DAT_011f5b84;
void __cdecl InitializeGameSystems();
void __cdecl NiMainSDM_Shutdown();
void __cdecl NiStaticDataManager_SetRootLibrary(void*, void*);
struct FUN_00a8a5f0_class {
    void* UpdateState_00a8a5f0();
};
// @fnv 0x00a8a5f0
// src: GUESS 0x00a8a5f0 (confidence: low)
void* FUN_00a8a5f0_class::UpdateState_00a8a5f0()
{
    void* old = (void*)DAT_011f5b84;
    ++DAT_011f5b84;
    if (!old)
        NiStaticDataManager_SetRootLibrary((void*)&InitializeGameSystems, (void*)&NiMainSDM_Shutdown);
    return this;
}

struct FUN_00a8f060_class {
    void NiPixelData_FreeData();
};

extern "C" void NiFreeAlias(void*);

// @fnv 0x00a8f060
// src: GAMEBRYO_LIB 0x00a8f060
void FUN_00a8f060_class::NiPixelData_FreeData()
{
    NiFreeAlias(*(void**)((char*)this + 0x50));
    *(int*)((char*)this + 0x5C) = 0;
    *(int*)((char*)this + 0x58) = 0;
    *(int*)((char*)this + 0x54) = 0;
    *(int*)((char*)this + 0x50) = 0;
}

// The shared header has no dimension setter; preserve its thiscall ABI with an unused EDX parameter.
// @fnv 0x00a8f080
void __fastcall SetBufferDimensions(Ni2DBuffer* self, int, unsigned int width, unsigned int height)
{
    self->m_uiImageWidth = width;
    self->m_uiImageHeight = height;
}

struct SdmBase;
extern SdmBase* DAT_011f5e34;

struct FUN_00a8f730 {
    void __thiscall Release();
};

// @fnv 0x00a8f730
void __thiscall FUN_00a8f730::Release()
{
    if (DAT_011f5e34)
        reinterpret_cast<void(__thiscall*)(void*, int)>(reinterpret_cast<void***>(DAT_011f5e34)[0][0])(DAT_011f5e34, 1);
    DAT_011f5e34 = 0;
}

extern char DAT_011f5d30;

// @fnv 0x00a8f750
int __cdecl GetGlobalDataPtr()
{
    return DAT_011f5d30 ? (int)&DAT_011f5d30 : 0;
}

extern int DAT_011f5e44;
extern int DAT_011f5e4c;

// @fnv 0x00a8ff30
void ResetStreamLinkIDSet()
{
    DAT_011f5e4c = 0;
    ((NiStreamLinkIDSet_blk_00a80000_o2*)&DAT_011f5e44)->Realloc(0);
}

extern int DAT_0109f814;

struct FUN_00a8ff50 {
    int m_p;
    short m_s1;
    short m_s2;
    int m_i1;
    int m_i2;
    int m_i3;
    FUN_00a8ff50();
};

// @fnv 0x00a8ff50
FUN_00a8ff50::FUN_00a8ff50()
{
    m_p = (int)&DAT_0109f814;
    m_s1 = 0;
    m_s2 = 0;
    m_i1 = 0;
    m_i2 = 0;
    m_i3 = 0;
}

void __cdecl NiFreeAlias(void*);

struct FUN_00a96440_class {
    char m_auiShapeKeys[0x4c];
    void* m_pField;
    void SetField(void* pNew);
};

// @fnv 0x00a96440
void FUN_00a96440_class::SetField(void* pNew)
{
    NiFreeAlias(m_pField);
    m_pField = pNew;
}

void NiFree(void*);
struct FUN_00a96460_class {
    char pad[0x54];
    void* m_0x54;
    void NiParticlesData_ReplaceSizes(void* p);
};
// @fnv 0x00a96460
// src: COMMUNITY 0x00a96460
void FUN_00a96460_class::NiParticlesData_ReplaceSizes(void* apPointer)
{
    NiFree(m_0x54);
    m_0x54 = apPointer;
}

void NiFreeAlias(void*);

struct FUN_00a96480_Class {
    void* m_5c;
    void NiParticlesData_ReplaceRotationAngles(void* p);
};

// @fnv 0x00a96480
// src: COMMUNITY 0x00a96480
void FUN_00a96480_Class::NiParticlesData_ReplaceRotationAngles(void* p)
{
    NiFreeAlias(*(void**)((char*)this + 0x5c));
    *(void**)((char*)this + 0x5c) = p;
}

extern "C" void __cdecl NiFreeAlias(void*);

struct FUN_00a964a0_Class {
    void* m_p;
    void NiParticlesData_ReplaceTextureIndices(void* p);
};

// @fnv 0x00a964a0
// src: COMMUNITY 0x00a964a0
void FUN_00a964a0_Class::NiParticlesData_ReplaceTextureIndices(void* apValue) {
    NiFreeAlias(*(void**)((char*)this + 0x64));
    *(void**)((char*)this + 0x64) = apValue;
}

namespace fnv_00a982d0 {
// @fnv 0x00a982d0
// src: EXE 0x00a982d0
void* NiPersistentSrcTextureRendererData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x94);
    if (p)
        return ((BSFadeNode*)p)->FUN_00a981d0();
    return 0;
}
}  // namespace fnv_00a982d0

struct CloningProcess;
struct NiBinaryExtraData;
struct NiFloatsExtraData;
struct FUN_00a99c40_shell : public NiExtraData {
    void NiIntegerExtraData_CopyMembers(NiBinaryExtraData* dst, CloningProcess* cp);
};
// @fnv 0x00a99c40
// src: GAMEBRYO_LIB 0x00a99c40
void FUN_00a99c40_shell::NiIntegerExtraData_CopyMembers(NiBinaryExtraData* dst, CloningProcess* cp)
{
    CopyMembers_00a7b330(dst, cp);
    *(void**)((char*)dst + 0xc) = *(void**)((char*)this + 0xc);
}


extern const void* DAT_0109e47c;
// @fnv 0x00a81fb0
// src: EXE 0x00a81fb0
BSFadeNode* NiSkinPartition_CreateObject()
{
    BSFadeNode* p = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x10));
    if (p) {
        new (static_cast<void*>(p)) NiLODData;
        *(const void**)p = &DAT_0109e47c;
        *(int*)((char*)p + 0xc) = 0;
        return p;
    }
    return 0;
}

// @fnv 0x00a88ac0
// src: GAMEBRYO_LIB 0x00a88ac0
unsigned int __cdecl NiString_GetBestBufferSize(unsigned int auiValue)
{
    if (auiValue < 32)
        return 32;
    if (auiValue < 64)
        return 64;
    if (auiValue < 128)
        return 128;
    if (auiValue < 255)
        return 255;
    if (auiValue < 512)
        return 512;
    if (auiValue < 1024)
        return 1024;
    return auiValue + 1;
}

extern int DAT_0109fb94;
// @fnv 0x00a91fe0
// src: EXE 0x00a91fe0
void* __cdecl NiVectorExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x1c);
    if (p) {
        ((NiExtraData*)p)->FUN_00a7b2e0();
        *(float*)((char*)p + 0x18) = 0.0f;
        *(int*)p = (int)&DAT_0109fb94;
        *(float*)((char*)p + 0x14) = 0.0f;
        *(float*)((char*)p + 0x10) = 0.0f;
        *(float*)((char*)p + 0xc) = 0.0f;
        return p;
    }
    return 0;
}

extern int DAT_010a02e4;
// Allocates a 0x1c-byte NiProperty, constructs it, sets m_18 to 0 and its vtbl to DAT_010a02e4, returning the object or null on allocation failure.
// @fnv 0x00a95160
// src: EXE 0x00a95160
NiProperty* __cdecl NiSpecularProperty_CreateObject()
{
    NiProperty* p = 0;
    if (void* mem = BSFadeNode::operator new(0x1c))
    {
        p = (NiProperty*)mem;
        p->NiProperty::NiProperty();
        ((NiCullingProperty*)p)->m_usFlags = 0;
        *(const void**)p = &DAT_010a02e4;
    }
    else
        return 0;
    return p;
}

extern const void* DAT_010a0a6c;
// Allocates a 0xcc-byte NiParticleMeshes, calls Init, sets its vtable and m_flag to 1, and returns it (or null on allocation failure).
// @fnv 0x00a98e70
// src: EXE 0x00a98e70
NiParticleMeshes* __cdecl NiParticleMeshes_CreateObject() {
    NiParticleMeshes* p = (NiParticleMeshes*)BSFadeNode::operator new(0xcc);
    if (p) {
        p->Init();
        *(const void**)p = &DAT_010a0a6c;
        *(char*)((char*)p + 0xc8) = 1;
        return p;
    }
    return 0;
}

void __cdecl NiFree(void*);
void* __cdecl NiMalloc(unsigned int);
struct FUN_00a99800_shell {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    unsigned int m_iThirdValue;
    void* m_10;
    void AssignPointerArray(unsigned int count, const void* src);
};
// @fnv 0x00a99800
void FUN_00a99800_shell::AssignPointerArray(unsigned int count, const void* src)
{
    NiFree(m_10);
    if (!src || count <= 0) {
        m_iThirdValue = 0;
        m_10 = 0;
    } else {
        m_iThirdValue = count;
        m_10 = NiMalloc(count * 4);
        for (unsigned int i = 0; i < count; ++i)
            ((void**)m_10)[i] = (void*)((const void**)src)[i];
    }
}

extern const void* DAT_010a12cc;

void __fastcall FUN_00a71f60(void*);

// @fnv 0x00a9b330
// src: EXE 0x00a9b330
void* __cdecl NiAmbientLight_CreateObject()
{
    void* p = BSFadeNode::operator new(0xf0);
    if (p) {
        FUN_00a71f60(p);
        *(const void**)p = &DAT_010a12cc;
        ((unsigned char*)p)[0x9d] = 0;
        return p;
    }
    return 0;
}

extern unsigned int kVtbl_NiAlphaAccumulator;
// Allocates a 0x34-byte NiAlphaAccumulator, runs its constructor, sets the vtable and initializes bytes at offsets 0x30-0x32, returning the object or null.
// @fnv 0x00a9b4b0
NiAlphaAccumulator* CreateNiAlphaAccumulator()
{
    NiAlphaAccumulator* p = static_cast<NiAlphaAccumulator*>(BSFadeNode::operator new(0x34));
    if (p) {
        p->NiAlphaAccumulator::NiAlphaAccumulator();
        *(unsigned int*)p = (unsigned int)&kVtbl_NiAlphaAccumulator;
        p->m_bObserveNoSortHint = true;
        p->m_bSortByClosestPoint = false;
        p->m_bInterfaceSort = false;
        return p;
    }
    return 0;
}

struct FUN_00a9be80 {
    const void* m_vft;
    int m_ref;
    int m_data;
    FUN_00a9be80(int data);
};
extern volatile long DAT_011f4400;
extern const void* DAT_010a1478;
extern const void* vftable_NiRefObject;
// @fnv 0x00a9be80
FUN_00a9be80::FUN_00a9be80(int data) {
    m_vft = &vftable_NiRefObject;
    m_ref = 0;
    InterlockedIncrement(&DAT_011f4400);
    m_data = data;
    m_vft = &DAT_010a1478;
}

struct FUN_00a84c90_class {
    char pad[0x44];
    int field44;
    short field48;
    FUN_00a84c90_class* ResetFields();
};

// @fnv 0x00a84c90
FUN_00a84c90_class* FUN_00a84c90_class::ResetFields()
{
    field44 = 0;
    field48 = 0;
    return this;
}

extern unsigned char DAT_011f5fb4;
extern unsigned char DAT_011f5fb5;
extern unsigned char DAT_011f5fb6;
extern unsigned char DAT_011f5fb7;
extern unsigned char DAT_011f5fb8;
extern unsigned char DAT_011f5fb9;
extern unsigned char DAT_011f5fba;
extern unsigned char DAT_011f5fbb;
extern unsigned char DAT_011f5fbc;
extern unsigned char DAT_011f5fbd;
extern unsigned char DAT_011f5fbe;
extern unsigned char DAT_011f5fbf;
extern unsigned char DAT_011f5fc0;
extern unsigned char DAT_011f5fc1;
extern int DAT_011f5fc4;
extern int DAT_011f5fc8;
extern int DAT_011f5fcc;
extern int DAT_011f5fd0;
extern int DAT_011f5fd4;
extern int DAT_011f5fd8;
extern int DAT_011f5fdc;
extern int DAT_011f5fe0;
extern int DAT_011f5fe4;
extern int DAT_011f5fe8;
extern int DAT_011f5fec;
extern int DAT_011f5ff0;
extern int DAT_011f5ff4;
extern int DAT_011f5ff8;
extern unsigned char DAT_011f6000;

// @fnv 0x00a9b8b0
// src: COMMUNITY 0x00a9b8b0
void __cdecl NiShaderConstantMapEntry_InitializeAttribTable()
{
    int v = 1;
    int w = 12;
    int x = 13;
    DAT_011f5fc4 = 0;
    DAT_011f5fc8 = v;
    DAT_011f5fcc = 2;
    DAT_011f5fd0 = 3;
    DAT_011f5fd4 = 4;
    DAT_011f5fd8 = 5;
    DAT_011f5fdc = 6;
    DAT_011f5fe0 = 7;
    DAT_011f5fe4 = 8;
    DAT_011f5fe8 = 9;
    DAT_011f5fec = 10;
    DAT_011f5ff0 = 11;
    DAT_011f5ff4 = w;
    DAT_011f5ff8 = x;
    DAT_011f5fb4 = 0;
    DAT_011f5fb5 = v;
    DAT_011f5fb6 = 2;
    DAT_011f5fb7 = 3;
    DAT_011f5fb8 = 4;
    DAT_011f5fb9 = 5;
    DAT_011f5fba = 6;
    DAT_011f5fbb = 7;
    DAT_011f5fbc = 8;
    DAT_011f5fbd = 9;
    DAT_011f5fbe = 10;
    DAT_011f5fbf = 11;
    DAT_011f5fc0 = w;
    DAT_011f5fc1 = x;
    DAT_011f6000 = v;
}

extern const void* DAT_0109e834;
struct FUN_00a87140_class {
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
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
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    char m_cc;
    void FUN_00a87140_ctor();
};
// @fnv 0x00a87140
// src: EXE 0x00a87140
FUN_00a87140_class* BSSegmentedTriShape_CreateObject() {
    FUN_00a87140_class* p = (FUN_00a87140_class*)BSFadeNode::operator new(0xd0);
    if (p) {
        p->FUN_00a87140_ctor();
        p->vtbl = (void*)&DAT_0109e834;
        p->m_c4 = 0;
        p->m_c8 = 0;
        p->m_cc = 0;
    } else {
        p = 0;
    }
    return p;
}

// This compatibility entry point is absent from the shared light declaration.
extern "C" void __cdecl FUN_00a7d6a0();

struct FUN_00a94c00_shell {
    char m_iWordAt00[0xfc];
    int m_fc;
    int m_100;
    int m_104;
    float m_108;
    float m_10c;
    float m_110;
    void NiSpotLight_CopyMembers(NiDirectionalLight* dst, CloningProcess& cp);
};
// @fnv 0x00a94c00
// src: XBOX_PDB 0x00a94c00
void FUN_00a94c00_shell::NiSpotLight_CopyMembers(NiDirectionalLight* dst, CloningProcess& cp)
{
    reinterpret_cast<void (__thiscall*)(NiDirectionalLight*, NiDirectionalLight*, CloningProcess&)>(FUN_00a7d6a0)((NiDirectionalLight*)this, dst, cp);
    FUN_00a94c00_shell* d = (FUN_00a94c00_shell*)dst;
    d->m_fc = m_fc;
    d->m_100 = m_100;
    d->m_104 = m_104;
    d->m_108 = m_108;
    d->m_10c = m_10c;
    d->m_110 = m_110;
}

extern MemoryManager g_memoryManager;
extern char* DAT_010a05e4;
struct FUN_00a96800_shell {
    char m_auiShapeKeys[0x44];
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void ReleaseStorage_00a96800();
    void DestroyGeometryData();
};
// @fnv 0x00a96800
// src: GUESS 0x00a96800 (confidence: medium)
void FUN_00a96800_shell::ReleaseStorage_00a96800()
{
    void* pOld = m_4c;
    *(void**)this = &DAT_010a05e4;
    NiFree(pOld);
    NiFree(m_54);
    g_memoryManager.Deallocate(m_58);
    NiFree(m_5c);
    g_memoryManager.Deallocate(m_60);
    if (m_44) g_memoryManager.Deallocate(m_44);
    if (m_48) g_memoryManager.Deallocate(m_48);
    if (m_64) NiFree(m_64);
    if (m_68) NiFree(m_68);
    DestroyGeometryData();
}

extern int DAT_0109e470;
void NiFree(void*);

struct FUN_00a81bd0_class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void UpdateState_00a81bd0();
};

// @fnv 0x00a81bd0
// src: GUESS 0x00a81bd0 (confidence: low)
void FUN_00a81bd0_class::UpdateState_00a81bd0()
{
    m_iWordAt00 = &DAT_0109e470;
    NiFree(m_iWordAt04);
    NiFree(m_8);
    NiFree(m_iThirdValue);
    NiFree(m_10);
    NiFree(m_14);
    NiFree(m_18);
}

struct Stub {
    void NiTStringPointerMap_NiAVObject_RemoveAt(void* p);
};
extern int DAT_0109f73c;
extern void* _EmptyFS;
extern int (__stdcall* DAT_00fdf1c4)(void*);
extern const void* vftable_NiRefObject;

struct FUN_00a8f810_class {
    void SetVtableAndProcessState_00a8f810();
};

// @fnv 0x00a8f810
// src: GUESS 0x00a8f810 (confidence: low)
void FUN_00a8f810_class::SetVtableAndProcessState_00a8f810()
{
    *(const void**)this = &DAT_0109f73c;
    Stub* s = (Stub*)DAT_011f5e34;
    s->NiTStringPointerMap_NiAVObject_RemoveAt((char*)this + 8);
    void* p = *(void**)((char*)this + 8);
    int (__stdcall* fn)(void*) = DAT_00fdf1c4;
    if (p != _EmptyFS)
        fn((char*)p - 8);
    *(const void**)this = &vftable_NiRefObject;
    fn((void*)&DAT_011f4400);
}

struct CloningProcess;
// @fnv 0x00a81430
// src: XBOX_PDB 0x00a81430
void NiCullingProperty::NiShadeProperty_CopyMembers(void* dst, CloningProcess& proc)
{
    NiProperty_CopyMembers(dst, proc);
    static_cast<NiCullingProperty*>(dst)->m_usFlags = m_usFlags;
}

void __cdecl NiFree(void*);
struct FUN_00a8a670_shell {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void ForwardCall_00a8a670();
};
// @fnv 0x00a8a670
// src: GUESS 0x00a8a670 (confidence: low)
void FUN_00a8a670_shell::ForwardCall_00a8a670()
{
    NiFree(m_iWordAt04);
}

extern const void* vftable_SdmDerived;
extern const void* vftable_SdmBase;
void _NiFree(void*);
extern MemoryManager _g_memoryManager;

struct SdmDerived {
    void* m_vt;
    void* m_iWordAt04;
    void* m_8;
    void* FUN_00a8fa10(char flag);
};

// @fnv 0x00a8fa10
void* SdmDerived::FUN_00a8fa10(char flag)
{
    m_vt = (void*)&vftable_SdmDerived;
    ((NiTFixedStringMap_NiAVObject___*)this)->RemoveAll();
    m_vt = (void*)&vftable_SdmBase;
    ((NiTFixedStringMap_NiAVObject___*)this)->RemoveAll();
    _NiFree(m_8);
    if (flag & 1) {
        _g_memoryManager.Deallocate(this);
    }
    return this;
}

extern char DAT_0109f9a4[];
extern void __cdecl _NiFree(void*);
extern MemoryManager _g_memoryManager;

struct FUN_00a90260_class
{
    void* m_vft;
    void* m_iWordAt04;

    void* __thiscall FUN_00a90260(int flags);
};

// @fnv 0x00a90260
void* __thiscall FUN_00a90260_class::FUN_00a90260(int flags)
{
    void* p = m_iWordAt04;
    m_vft = DAT_0109f9a4;
    _NiFree(p);

    if (flags & 1)
        _g_memoryManager.Deallocate(this);

    return this;
}

struct FUN_00a5a390_shell {
    void DestroyFogProperty();
    FUN_00a5a390_shell* FUN_00a950f0(bool bDel);
};
void __cdecl operator delete(void* p, unsigned int);
// Calls DestroyFogProperty, then deletes this with size 0x1c if bDel is set, and returns this.
// @fnv 0x00a950f0
FUN_00a5a390_shell* FUN_00a5a390_shell::FUN_00a950f0(bool bDel)
{
    DestroyFogProperty();
    if (bDel & 1)
        operator delete(this, 0x1c);
    return this;
}

struct NiCullingData {
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};

// Copies this NiCullingProperty's m_18, m_1c and m_20 into the destination after calling FUN_00a5d7a0.
// @fnv 0x00a99e00
// src: GAMEBRYO_LIB 0x00a99e00
void NiCullingProperty::NiFogProperty_CopyMembers(
    void* destination, CloningProcess& cloningProcess)
{
    NiCullingProperty* dest = static_cast<NiCullingProperty*>(destination);

    NiProperty_CopyMembers(destination, cloningProcess);
    dest->m_usFlags = m_usFlags;
    *(float*)((char*)dest + 0x1c) = *(float*)((char*)this + 0x1c);
    *(NiCullingData*)((char*)dest + 0x20) = *(NiCullingData*)((char*)this + 0x20);
}

void __cdecl NiShaderConstantMapEntry_InitializeAttribTable();
void __cdecl NiShaderConstantMapEntry_SDMInit_NiShaderConstantMapEntry_InitializeObjectTable();
// @fnv 0x00a9ba80
// src: COMMUNITY 0x00a9ba80
void __cdecl NiShaderConstantMapEntry__SDMInit()
{
    NiShaderConstantMapEntry_InitializeAttribTable();
    NiShaderConstantMapEntry_SDMInit_NiShaderConstantMapEntry_InitializeObjectTable();
}

extern int DAT_0109e04c;

struct FUN_00a80580_sub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    void Cleanup();
};

struct FUN_00a80580_cls {
    void* m_vptr;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98;
    FUN_00a80580_sub m_sub9c;
    NiRefObject* m_b8;
    NiRefObject* m_bc;

    void BaseTeardown();
    void UpdateFields_00a80580();
};

// Releases the two NiRefObject members via reference counting, cleans up m_sub9c, then calls BaseTeardown.
// @fnv 0x00a80580
// src: GUESS 0x00a80580 (confidence: low)
void FUN_00a80580_cls::UpdateFields_00a80580()
{
    *(void* volatile*)&m_vptr = (void*)&DAT_0109e04c;
    NiRefObject* first = *(NiRefObject* volatile*)&m_b8;
    if (first != 0) {
        if (InterlockedDecrement((volatile long*)&first->m_uiRefCount) == 0) {
            first->DeleteThis();
        }
        m_b8 = 0;
    }
    NiRefObject* second = m_bc;
    if (second != 0) {
        if (InterlockedDecrement((volatile long*)&second->m_uiRefCount) == 0) {
            second->DeleteThis();
        }
    }
    NiRefObject* third = m_b8;
    if (third != 0) {
        if (InterlockedDecrement((volatile long*)&third->m_uiRefCount) == 0) {
            third->DeleteThis();
        }
    }
    m_sub9c.Cleanup();
    BaseTeardown();
}

extern const void* DAT_0109e174;

void FUN_00a5d3d0();

// @fnv 0x00a80fc0
void __fastcall DestroyNiCollisionObject(NiCollisionObject* object, void*) {
    *reinterpret_cast<void**>(object) = reinterpret_cast<void*>(&DAT_0109e174);
    FUN_00a5d3d0();
}

extern float DAT_011ab3f8;
static const float kPi = 3.1415927f;
extern "C" double __cdecl fabs(double);

// Computes the angle of the vector (x, y) using a polynomial approximation of atan, handling zero and quadrant cases.
// @fnv 0x00a811f0
// src: GAMEBRYO_LIB 0x00a811f0
float __cdecl NiFastATan2(float y, float x)
{
    if (x == 0.0f && y == 0.0f)
        return 0.0f;

    float k = 0.0f;
    float fRatio;
    if ((float)fabs(y) > (float)fabs(x)) {
        fRatio = x / y;
        if (fRatio > 0.0f)
            k = DAT_011ab3f8;
        else if (fRatio < 0.0f)
            k = -DAT_011ab3f8;
        else
            return y > 0.0f ? DAT_011ab3f8 : -DAT_011ab3f8;
    } else {
        fRatio = y / x;
        if (fRatio == 0.0f)
            return x > 0.0f ? 0.0f : kPi;
    }

    float s = fRatio * fRatio;
    float r = 0.0208351f * s;
    r = r - 0.085133f;
    r = r * s;
    r = r + 0.180141f;
    r = r * s;
    r = r - 0.3302995f;
    r = r * s;
    r = r + 0.999866f;
    r = r * fRatio;

    if (k != 0.0f)
        r = k - r;
    if (y < 0.0f && x < 0.0f)
        r -= 3.1415927f;
    if (y > 0.0f && x < 0.0f)
        r += 3.1415927f;
    return r;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_0109e32c;

struct FUN_00a81760_obj
{
    void* m_pVTable;
    char unk04[0x54];
    unsigned short m_58;
    unsigned short m_5a;

    void FUN_00a7b690();
};

// @fnv 0x00a81760
// src: EXE 0x00a81760
FUN_00a81760_obj* __cdecl NiTriShapeDynamicData_CreateObject()
{
    FUN_00a81760_obj* p = (FUN_00a81760_obj*)Object_DispatchCommandFour(0x5c);
    if (p != 0)
    {
        p->FUN_00a7b690();
        p->m_58 = 0;
        p->m_pVTable = (void*)&DAT_0109e32c;
        p->m_5a = 0;
    }
    else
    {
        p = 0;
    }
    return p;
}

struct S_a819e0_O {
virtual ~S_a819e0_O() {}
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
};
// @fnv 0x00a819e0
// src: COMMUNITY 0x00a819e0
void NiParallelUpdateTaskManager_Shutdown() {
    if (DAT_011f5b04) {
        ((S_a819e0_O*)DAT_011f5b04)->v39();
        if (DAT_011f5b04) delete (S_a819e0_O*)DAT_011f5b04;
        DAT_011f5b04 = 0;
    }
}

// FUN_00a81ba0 : constructor of a plain object whose first member is the
// class vtable pointer. Clears the dword fields at +4..+0x18, a word at +0x22
// and a dword at +0x28.

extern int DAT_0109e470;

struct FUN_00a81ba0_cls
{
    void* m_pVTable;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int unk1c;
    unsigned short unk20;
    volatile unsigned short m_22;
    unsigned int unk24;
    unsigned int m_28;

    FUN_00a81ba0_cls();
};

// @fnv 0x00a81ba0
FUN_00a81ba0_cls::FUN_00a81ba0_cls()
{
    m_pVTable = (void*)&DAT_0109e470;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_22 = 0;
    m_28 = 0;
}

struct FUN_00a84c60_cls
{
    unsigned short m_00;
    FUN_00a84c60_cls* ClearField00_00a84c60();
};

// @fnv 0x00a84c60
// src: GUESS 0x00a84c60 (confidence: low)
FUN_00a84c60_cls* FUN_00a84c60_cls::ClearField00_00a84c60()
{
    m_00 = 0;
    return this;
}

struct FUN_00a84ca0_entry {
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
    void* unk44;
    int unk48;
};



extern MemoryManager g_memoryManager;

struct FUN_00a84ca0_class {
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
    void* m_40;
    unsigned int m_44;

    void FreeEntryResources();
};

// Iterates m_44 entries in the array at m_40, deallocating each entry's unk44 pointer and clearing it.
// @fnv 0x00a84ca0
void FUN_00a84ca0_class::FreeEntryResources()
{
    if (m_40 != 0) {
        for (unsigned int i = 0; i < m_44; ++i) {
            g_memoryManager.Deallocate(
                reinterpret_cast<FUN_00a84ca0_entry*>(m_40)[i].unk44);
            reinterpret_cast<FUN_00a84ca0_entry*>(m_40)[i].unk44 = 0;
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

struct CloneObject {
    int unk00;
    int unk04;
    NiRefObject* first;
    NiRefObject* second;

    void CreateVertexBufferSet(CloneObject* destination, void* process);
    void CopyRefCountedPointers(CloneObject* destination, void* process);
};

// @fnv 0x00a86660
void CloneObject::CopyRefCountedPointers(CloneObject* destination, void* process)
{
    CreateVertexBufferSet(destination, process);

    NiRefObject* previous = destination->first;
    if (previous != first) {
        if (previous && InterlockedDecrement((volatile long*)&previous->m_uiRefCount) == 0) {
            previous->DeleteThis();
        }
        NiRefObject* replacement = first;
        destination->first = replacement;
        if (replacement) {
            InterlockedIncrement((volatile long*)&replacement->m_uiRefCount);
        }
    }

    previous = destination->second;
    if (previous != second) {
        if (previous && InterlockedDecrement((volatile long*)&previous->m_uiRefCount) == 0) {
            previous->DeleteThis();
        }
        NiRefObject* replacement = second;
        destination->second = replacement;
        if (replacement) {
            InterlockedIncrement((volatile long*)&replacement->m_uiRefCount);
        }
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int size) throw();
extern int DAT_01069b14;

struct SpawnedObject
{
    void* m_pVTable;
    int unk04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int unk2c;
    int m30;

    void InitBase() throw();
};

// Allocates a 0x34-byte SpawnedObject, runs InitBase, installs the vtable, zeroes most fields, sets m18 to -1, and returns it (or null).
// @fnv 0x00a866f0
// src: EXE 0x00a866f0
SpawnedObject* __cdecl NiSkinInstance_CreateObject() throw()
{
    SpawnedObject* p = (SpawnedObject*)Object_DispatchCommandFour(0x34);
    if (p != 0)
    {
        p->InitBase();
        *(int volatile*)&p->m_pVTable = (int)&DAT_01069b14;
        *(int volatile*)&p->m08 = 0;
        *(int volatile*)&p->m0c = 0;
        *(int volatile*)&p->m10 = 0;
        *(int volatile*)&p->m14 = 0;
        *(int volatile*)&p->m1c = 0;
        *(int volatile*)&p->m20 = 0;
        *(int volatile*)&p->m24 = 0;
        *(int volatile*)&p->m28 = 0;
        *(int volatile*)&p->m30 = 0;
        *(int volatile*)&p->m18 = -1;
        return p;
    }
    return 0;
}

// FUN_00a87790: thiscall, 10 bytes.
// Loads the vtable pointer of this, reads the function pointer stored in
// vtable slot 0xdc and tail-jumps to it, forwarding the single stack
// argument of this method.
struct FUN_00a87790_cls
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
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void Tail(int a);
    void NiScreenElements_Draw(int a);
};

// @fnv 0x00a87790
// src: COMMUNITY 0x00a87790
void FUN_00a87790_cls::NiScreenElements_Draw(int a)
{
    this->Tail(a);
}

struct FUN_00a88c60_Point2 {
    float unk00;
    float unk04;

    bool __thiscall ForwardCall_0051c330(const FUN_00a88c60_Point2* other);
};

struct FUN_00a88c60_Class {
    float unk00;
    float unk04;
    float unk08;
    FUN_00a88c60_Point2 unk0C;
    FUN_00a88c60_Point2 unk14;
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

    int __thiscall ProcessAndReturnValue_00a88c60(FUN_00a88c60_Class* other);
};

// @fnv 0x00a88c60
// src: GUESS 0x00a88c60 (confidence: low)
int __thiscall FUN_00a88c60_Class::ProcessAndReturnValue_00a88c60(FUN_00a88c60_Class* other) {
    if (unk08 == other->unk08 && unk00 == other->unk00 && unk04 == other->unk04) {
        if (!unk0C.ForwardCall_0051c330(&other->unk0C) && unk44 == other->unk44) {
            if (!unk14.ForwardCall_0051c330(&other->unk14)) {
                return 0;
            }
        }
    }

    return 1;
}

// @fnv 0x00a89650
// src: GAMEBRYO_LIB 0x00a89650
void NiCompUtility_DecompressFloatArray(const short* psCompressed, unsigned int uiUnused, float afBase, float fHalfRange, float* pfValues,
                  unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        pfValues[i] = (float)(psCompressed[i] / 32767.0 * fHalfRange + afBase);
}

struct FUN_00a89760_base {
    virtual ~FUN_00a89760_base();
};

struct FUN_00a89760_cls : FUN_00a89760_base {
    virtual ~FUN_00a89760_cls();
};

// @fnv 0x00a89760
FUN_00a89760_cls::~FUN_00a89760_cls()
{
}

struct BaseCls {
    void __thiscall FUN_00a67b20(int, int, int, int, int, int, int);
};

extern "C" void* __cdecl _NiMalloc_00aa1070(int);

extern int DAT_0109f23c;

struct FUN_00a8a680_cls {
    void* m_vft;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
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
    void* m_40;
    void* InitWithBuffer(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
};

// @fnv 0x00a8a680
void* FUN_00a8a680_cls::InitWithBuffer(int ausLength, int a1, int a2, int a3, int a4, int a5, int apBuffer)
{
    ((BaseCls*)this)->FUN_00a67b20(ausLength, a1, 0, a2, a3, a4, a5);
    m_vft = (void*)&DAT_0109f23c;
    if (apBuffer != 0) {
        m_40 = (void*)apBuffer;
    } else {
        unsigned short usLength = (unsigned short)ausLength;
        m_40 = _NiMalloc_00aa1070(usLength);
        for (unsigned short i = 0; i < usLength; i++) {
            ((unsigned char*)m_40)[i] = (unsigned char)((~i) & 1);
        }
    }
    return this;
}

struct DecodePair {unsigned char first,second;};
struct Decoder {
 unsigned int unk00,unk04;
 unsigned char* input;
 unsigned int unk0c;
 DecodePair table[256];
 void DecodeToOutput(unsigned int* output);
};
// Decodes 8 input bytes through the lookup table, writing each pair's two bytes into the output buffer.
// @fnv 0x00a8b4b0
void Decoder::DecodeToOutput(unsigned int* output) {
 for(unsigned int i=0;i<8;++i) {
  *(unsigned char*)output=table[*input].first;
  ++output;
  *(unsigned char*)output=table[*input].second;
  ++output;
  ++input;
 }
}

struct BlockColorDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;

    unsigned int ReadWord()
    {
        unsigned int value = (unsigned short)(cursor[1] * (unsigned short)256 + cursor[0]);
        cursor += 2;
        return value;
    }

    void DecodeBlockColors(unsigned char* output);
};

// Reads two 16-bit words into four RGB colors (two endpoints plus two interpolated), then writes 16 pixels selected by 2-bit indices from the cursor.
// @fnv 0x00a8b8c0
void BlockColorDecoder::DecodeBlockColors(unsigned char* output)
{
    unsigned int first = ReadWord();
    unsigned int second = ReadWord();
    unsigned char colors[4][3];
    colors[0][0] = (first >> 8) & 0xf8;
    colors[0][1] = (first >> 3) & 0xfe;
    colors[0][2] = first << 3;
    colors[1][0] = (second >> 8) & 0xf8;
    colors[1][1] = (second >> 3) & 0xfe;
    colors[1][2] = second << 3;
    colors[2][0] = (2u * colors[0][0] + colors[1][0]) / 3u;
    colors[2][1] = (2u * colors[0][1] + colors[1][1]) / 3u;
    colors[2][2] = (2u * colors[0][2] + colors[1][2]) / 3u;
    colors[3][0] = (colors[0][0] + 2u * colors[1][0]) / 3u;
    colors[3][1] = (colors[0][1] + 2u * colors[1][1]) / 3u;
    colors[3][2] = (colors[0][2] + 2u * colors[1][2]) / 3u;

    for (unsigned int row = 0; row < 4; ++row) {
        unsigned char indices = *cursor;
        for (unsigned int column = 0; column < 4; ++column) {
            unsigned char* color = colors[indices & 3];
            output[0] = *color++;
            output[1] = *color++;
            output[2] = *color;
            output += 4;
            indices >>= 2;
        }
        ++cursor;
    }
}

extern const double runtimeInitializationDouble5;

void DecodeBlockColors();

struct A8BD20Entry {
    unsigned char m_ucLow;
    unsigned char m_ucHigh;
};

class FUN_00a8bd20 {
public:
    int unk00;
    void (*m_pfnCallback)();
    int unk08;
    int unk0C;
    A8BD20Entry m_akTable[256];

    FUN_00a8bd20();
};

// Initializes the object's fields, sets the callback to DecodeBlockColors, and fills a 256-entry table with scaled low/high nibble values.
// @fnv 0x00a8bd20
FUN_00a8bd20::FUN_00a8bd20() {
    double dMax = runtimeInitializationDouble5;
    unk00 = 0;
    m_pfnCallback = DecodeBlockColors;
    unk08 = 0;
    unk0C = 0;
    for (unsigned int i = 0; i < 256; i++) {
        m_akTable[i].m_ucLow = (unsigned char)((float)(i & 0xf) / dMax * 255.0);
        m_akTable[i].m_ucHigh = (unsigned char)((float)((i >> 4) & 0xf) / dMax * 255.0);
    }
}

extern "C" void __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int size);

struct FUN_00a8bdf0_cls {
    void (__thiscall* m_00)(FUN_00a8bdf0_cls* self, unsigned char* out);
    void (__thiscall* m_04)(FUN_00a8bdf0_cls* self, unsigned char* out);
    int m_08;
    int m_0c;
    void CopyGeneratedRows(unsigned char* dst, unsigned int a2, unsigned int count);
};

// Fills a 0x40-byte buffer via m_00 and m_04, then copies a2*4 bytes from it into dst count times, advancing dst by m_0c and src by 0x10 each iteration.
// @fnv 0x00a8bdf0
// src: GUESS 0x00a8bdf0 (confidence: medium)
void FUN_00a8bdf0_cls::CopyGeneratedRows(unsigned char* dst, unsigned int a2, unsigned int count)
{
    
    unsigned char aucBuffer[0x40];
    unsigned char* src = aucBuffer;
    if (m_00 != 0) {
        m_00(this, &aucBuffer[3]);
    }
    m_04(this, aucBuffer);
    unsigned int size = a2 * 4;
    if (count > 0) {
        unsigned int n = count;
        do {
            FUN_00ec44d0(dst, src, size);
            dst += m_0c;
            src += 0x10;
        } while (--n != 0);
    }
}

inline void NiRefObject::IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
inline void NiRefObject::DecRefCount() { if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0) DeleteThis(); }

// Assigns the renderer data, releasing the previous reference and acquiring the new one.
// @fnv 0x00a8f140
void Ni2DBuffer::SetRendererData(RendererData* obj)
{
    NiRefObject* old = static_cast<RendererData*>(m_pRendererData);
    if (old != obj) {
        if (old != 0) {
            old->DecRefCount();
        }
        m_pRendererData = obj;
        if (obj != 0) {
            obj->IncRefCount();
        }
    }
}

extern const void* DAT_0109f4dc;

// Releases the renderer data and calls the shared base teardown at 0x00a5d3d0.
// @fnv 0x00a8f1c0
void __fastcall DestroyBufferMembers(Ni2DBuffer* self, int) {
    *(void* volatile*)self = (void*)&DAT_0109f4dc;
    NiRefObject* p = *(NiRefObject* volatile*)&self->m_pRendererData;
    if (p != 0) {
        if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0) {
            p->DeleteThis();
        }
    }
    self->NiObject::FUN_00a5d3d0();
}

// This unit calls the out-of-line smart-pointer assignment at 0x00a5f860.
template <> NiPointer<Ni2DBuffer::RendererData>&
NiPointer<Ni2DBuffer::RendererData>::operator=(Ni2DBuffer::RendererData*);

// Creates a buffer when the renderer data has a pixel format.
// @fnv 0x00a8f2c0
Ni2DBuffer* Ni2DBuffer::Create(unsigned int uiWidth, unsigned int uiHeight, RendererData* pkData) {
    if (pkData == 0) return 0;
    if (pkData->m_pkPixelFormat == 0) return 0;
    Ni2DBuffer* p = static_cast<Ni2DBuffer*>(Ni2DBuffer::operator new(sizeof(Ni2DBuffer)));
    if (p) {
        new (p) NiObject;
        *(const void**)p = &DAT_0109f4dc;
        p->m_uiImageWidth = 0;
        p->m_uiImageHeight = 0;
        p->m_pRendererData = 0;
    } else {
        p = 0;
    }
    p->m_uiImageWidth = uiWidth;
    p->m_uiImageHeight = uiHeight;
    reinterpret_cast<NiPointer<RendererData>&>(p->m_pRendererData) = pkData;
    p->SetRendererData(pkData);
    return p;
}

extern const void* DAT_0109f9bc;
void __cdecl ReleaseObjectArray(void*);
struct FUN_00a910f0_class {
    void* vft;
    void* buffer;
    FUN_00a910f0_class* FUN_00a910f0(unsigned char flags);
};
struct FUN_00aa4060_class {
    void MemoryManager_Deallocate(void* object);
};
extern FUN_00aa4060_class DAT_011f6238;
// @fnv 0x00a910f0
FUN_00a910f0_class* FUN_00a910f0_class::FUN_00a910f0(unsigned char flags) {
    vft = &DAT_0109f9bc;
    ReleaseObjectArray(buffer);
    if (flags & 1) DAT_011f6238.MemoryManager_Deallocate(this);
    return this;
}

namespace fnv_00a91120 {
struct S_a91120_Alloc { void* Game_DoHeapAlloc(unsigned int size); };
extern S_a91120_Alloc DAT_011f6238;
void* __cdecl Runtime_GetIndexedValue_00a90290(unsigned int count);
struct S_a91120_Blk {
    unsigned char* unk00;
    unsigned int unk04;
    S_a91120_Blk* unk08;
    static void* operator new(unsigned int size) { return DAT_011f6238.Game_DoHeapAlloc(size); }
    S_a91120_Blk(unsigned int n) throw() {
        unk04 = n;
        unk08 = 0;
        if (n > 0) unk00 = (unsigned char*)Runtime_GetIndexedValue_00a90290(n);
        else unk00 = 0;
    }
    unsigned char* GetAt(unsigned int i) {
        if (i >= unk04) return 0;
        return unk00 + i * 0x14;
    }
};
struct S_a91120 {
    void** unk00;
    unsigned int unk04;
    unsigned int unk08;
    S_a91120_Blk* unk0c;
    void NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(unsigned int n);
    void AppendItems(unsigned int n);
};
// Allocates a block of n items, appends each item pointer to unk00, growing via FUN_00a311e0 when full, then links the block into unk0c.
// @fnv 0x00a91120
void S_a91120::AppendItems(unsigned int n) {
    S_a91120_Blk* pBlock = new S_a91120_Blk(n);
    for (unsigned int i = 0; i < n; i++) {
        unsigned char* item = pBlock->GetAt(i);
        if (unk08 == unk04)
            NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(unk04 > 0 ? unk04 * 2 : 1);
        unk00[unk08] = item;
        unk08++;
    }
    pBlock->unk08 = unk0c;
    unk0c = pBlock;
}
}  // namespace fnv_00a91120

namespace fnv_00a98240 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" const void* DAT_010a08ac;
extern "C" const void* DAT_010a080c;
void __cdecl NiFree(void*);
struct NiObjectShell {
    void* volatile vtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    void* allocation;
    unsigned int capacity;
    unsigned int length;
    unsigned int increment;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    NiRefObject* volatile reference;
    void FUN_00a5d3d0();
    void UpdateFields_00a98240();
};
// @fnv 0x00a98240
// src: GUESS 0x00a98240 (confidence: low)
void NiObjectShell::UpdateFields_00a98240() {
    vtable = (void*)&DAT_010a08ac;
    NiRefObject* oldReference = reference;
    if (oldReference) {
        if (InterlockedDecrement((volatile long*)&oldReference->m_uiRefCount) == 0)
            oldReference->DeleteThis();
        reference = 0;
    }
    if (allocation) {
        NiFree(allocation);
        increment = 0;
        length = 0;
        capacity = 0;
        allocation = 0;
    }
    NiRefObject* lastReference = reference;
    if (lastReference) {
        if (InterlockedDecrement((volatile long*)&lastReference->m_uiRefCount) == 0)
            lastReference->DeleteThis();
    }
    vtable = (void*)&DAT_010a080c;
    FUN_00a5d3d0();
}
}  // namespace fnv_00a98240

struct NiParticleBase {
    void* vtable;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    unsigned int unknown98;
    void __thiscall FUN_00a5ecb0(int);
};
struct NiParticleBuffer {
    void* data;
    unsigned int count;
    unsigned short capacity;
    unsigned short used;
    unsigned short growth;
    unsigned short flags;
    void __thiscall FUN_0060bef0(int);
};
struct NiParticleSubobject {
    void* first;
    void* second;
    void* third;
    void* fourth;
    void __thiscall FUN_00a69940();
};
struct NiParticleObject : NiParticleBase {
    NiParticleBuffer buffer;
    NiParticleSubobject firstMember;
    NiParticleSubobject secondMember;
};
extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern const char DAT_010a1024;
// @fnv 0x00a9aea0
NiParticleObject* __cdecl CreateNiParticleObject() {
    NiParticleObject* object =
        (NiParticleObject*)Object_DispatchCommandFour(0xcc);
    if (object) {
        object->FUN_00a5ecb0(0);
        object->vtable = (void*)&DAT_010a1024;
        object->firstMember.FUN_00a69940();
        object->secondMember.FUN_00a69940();
        object->buffer.FUN_0060bef0(2);
        object->buffer.flags = 0;
        return object;
    }
    return 0;
}

extern int DAT_010a13ac;

void __declspec(noreturn) FUN_00aa0dc0();

struct FUN_00a9b4a0_Class {
    void __thiscall UpdateFields_00a9b4a0();
};

// @fnv 0x00a9b4a0
// src: GUESS 0x00a9b4a0 (confidence: low)
void __thiscall FUN_00a9b4a0_Class::UpdateFields_00a9b4a0() {
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_010a13ac);
    FUN_00aa0dc0();
}

extern unsigned short DAT_011f5f7c;
extern unsigned short DAT_011f5f7e;
extern unsigned short DAT_011f5f80;
extern unsigned short DAT_011f5f82;
extern unsigned short DAT_011f5f84;
extern unsigned short DAT_011f5f86;
extern unsigned short DAT_011f5f88;
extern unsigned short DAT_011f5f8a;
extern unsigned short DAT_011f5f8c;
extern int DAT_011f5f90;
extern int DAT_011f5f94;
extern int DAT_011f5f98;
extern int DAT_011f5f9c;
extern int DAT_011f5fa0;
extern int DAT_011f5fa4;
extern int DAT_011f5fa8;
extern int DAT_011f5fac;
extern int DAT_011f5fb0;
extern unsigned char DAT_011f6001;

// @fnv 0x00a9b9b0
// src: COMMUNITY 0x00a9b9b0
void __cdecl NiShaderConstantMapEntry_SDMInit_NiShaderConstantMapEntry_InitializeObjectTable()
{
    DAT_011f5f90 = 0;
    DAT_011f5f94 = 1;
    DAT_011f5f7c = 0x0;
    DAT_011f5f7e = 0x100;
    DAT_011f5f80 = 0x200;
    DAT_011f5f82 = 0x300;
    DAT_011f5f84 = 0x400;
    DAT_011f5f86 = 0x500;
    DAT_011f5f88 = 0x600;
    DAT_011f5f98 = 2;
    DAT_011f5f9c = 3;
    DAT_011f5fa0 = 4;
    DAT_011f5fa4 = 5;
    DAT_011f5fa8 = 6;
    DAT_011f5fac = 7;
    DAT_011f5fb0 = 8;
    DAT_011f5f8a = 0x700;
    DAT_011f5f8c = 0x800;
    DAT_011f6001 = 1;
}

extern "C" void* DAT_0109b220;

struct ReferenceHandle
{
    volatile long* value;
    void operator=(const ReferenceHandle& other)
    {
        volatile long* next = other.value;
        if (value != next) {
            if (next != DAT_0109b220)
                InterlockedIncrement(next - 2);
            if (value != DAT_0109b220)
                InterlockedDecrement(value - 2);
            value = next;
        }
    }
};

struct RefCountedPair
{
    unsigned int identifier;
    ReferenceHandle handle;
    RefCountedPair* Assign(const RefCountedPair* other);
};

// Copies the identifier and reference handle from another RefCountedPair into this one and returns this.
// @fnv 0x00a9be30
RefCountedPair* RefCountedPair::Assign(const RefCountedPair* other)
{
    identifier = other->identifier;
    handle = other->handle;
    return this;
}

namespace fnv_00a9fda0 {
struct FUN_00a9fda0_holder {
    void MemoryManager_Deallocate(void* p);
};

struct FUN_00a9fda0_pair {
    unsigned int m_key;
    unsigned int m_uiFilterValue;
};

extern FUN_00a9fda0_pair* DAT_011f602c;
extern FUN_00a9fda0_pair* DAT_011f6024;
extern unsigned int DAT_0109b220;
extern FUN_00a9fda0_holder DAT_011f6238;

// @fnv 0x00a9fda0
void DestroyPairArrays()
{
    FUN_00a9fda0_pair* arr = DAT_011f602c;
    int (__stdcall* fp)(void*) = DAT_00fdf1c4;
    if (arr != 0) {
        int i = ((int*)arr)[-1];
        FUN_00a9fda0_pair* p = arr + i;
        if (--i >= 0) {
            do {
                p--;
                unsigned int value = p->m_uiFilterValue;
                if (value != DAT_0109b220) {
                    fp((void*)(value - 8));
                }
            } while (--i >= 0);
        }
        DAT_011f6238.MemoryManager_Deallocate((void*)((char*)arr - 4));
    }
    FUN_00a9fda0_pair* arr2 = DAT_011f6024;
    DAT_011f602c = 0;
    if (arr2 != 0) {
        int i = ((int*)arr2)[-1];
        FUN_00a9fda0_pair* p = arr2 + i;
        if (--i >= 0) {
            do {
                p--;
                unsigned int value = p->m_uiFilterValue;
                if (value != DAT_0109b220) {
                    fp((void*)(value - 8));
                }
            } while (--i >= 0);
        }
        DAT_011f6238.MemoryManager_Deallocate((void*)((char*)arr2 - 4));
    }
    DAT_011f6024 = 0;
}
}  // namespace fnv_00a9fda0

struct FUN_00a9ff00_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
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
    virtual void v36();
    virtual int v37(int a, int b, int c);
};

// Uses the buffer format and sample preference to request a depth-stencil buffer.
// @fnv 0x00a9ff00
NiDepthStencilBuffer* __cdecl ProcessArgWithObj(Ni2DBuffer* a, FUN_00a9ff00_Obj* pObj)
{
    if (a == 0 || pObj == 0)
    {
        return 0;
    }
    Ni2DBuffer::RendererData* data = static_cast<Ni2DBuffer::RendererData*>(a->m_pRendererData);
    int x = data != 0 ? reinterpret_cast<int>(data->m_pkPixelFormat) : 0;
    int r = pObj->v37(x, 0x20, 8);
    data = static_cast<Ni2DBuffer::RendererData*>(a->m_pRendererData);
    int y = data != 0 ? static_cast<int>(data->m_eMSAAPref) : 0;
    int w = a->m_uiImageHeight;
    int u = a->m_uiImageWidth;
    return NiDepthStencilBuffer::Create(u, w, reinterpret_cast<NiRenderer*>(pObj),
        *reinterpret_cast<const NiPixelFormat*>(r), y);
}

extern unsigned char* DAT_011f5b04;
int __cdecl NiParallelUpdateTaskManager_SignalRenderSema();

struct FnvRing {
    unsigned int unk00;
    unsigned int m_pRayCursor;
    unsigned int m_pFirstNode;
    unsigned int m_pTail;

    unsigned int Count() const {
        if (m_pFirstNode == 0xffffffffu) {
            return 0;
        }
        if (m_pFirstNode >= m_pTail) {
            return m_pRayCursor - m_pFirstNode + m_pTail;
        }
        return m_pTail - m_pFirstNode;
    }
};

struct FnvQueueState {
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
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0(int a, void* p, int b, int c);
    int Probe(int kind);
    unsigned int unk04;
    FnvRing m_r0;
    FnvRing m_r1;
    FnvRing m_r2;
    FnvRing m_r3;
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
    void* m_19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned char m_1b0;
};

// @fnv 0x00a81a80
// src: COMMUNITY 0x00a81a80
void __cdecl NiParallelUpdateTaskManager_EndUpdate()
{
    FnvQueueState* s = (FnvQueueState*)DAT_011f5b04;
    if (s == 0) {
        return;
    }
    if (s->m_r0.Count() != 0 || s->m_r1.Count() != 0 ||
        s->Probe(2) != 0 || s->Probe(3) != 0) {
        s->va0(1, &s->m_19c, 0, 0);
    } else {
        NiParallelUpdateTaskManager_SignalRenderSema();
    }
    ((FnvQueueState*)DAT_011f5b04)->m_1b0 = 0;
}

class BA87920Base {
public:
    static void* operator new(unsigned int uiSize);

    BA87920Base() throw();
    virtual ~BA87920Base();

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
};

class BA87920Object : public BA87920Base {
public:
    __forceinline BA87920Object()
        : m_pkFirst(0), m_pkSecond(0), m_usA(0), m_usB(0), m_usC(0), m_usD(0), m_usE(0), m_usF(0), m_usG(0), m_bFlag(false)
    {
    }
    virtual ~BA87920Object();

    void* m_pkFirst;
    void* m_pkSecond;
    unsigned short m_usA;
    unsigned short m_usB;
    unsigned short m_usC;
    unsigned short m_usD;
    unsigned short m_usE;
    unsigned short m_usF;
    unsigned short m_usG;
    bool m_bFlag;
};

// Allocates and default-constructs a new BA87920Object, returning the pointer.
// @fnv 0x00a87920
BA87920Object* __cdecl CreateBA87920Object()
{
    return new BA87920Object;
}

extern float g_fRadiansPerRevolution;
extern float DAT_011f52e0[];
extern float DAT_011f4ae0[];

struct TexXformPoint2 {
    float x;
    float y;
};

inline void TexXformSinCos(float fRadians, float& fSin, float& fCos)
{
    int iIndex = (int)(512.0 / g_fRadiansPerRevolution * fRadians) & 0x1ff;
    fSin = DAT_011f52e0[iIndex];
    fCos = DAT_011f4ae0[iIndex];
}

struct TexXformMatrix3 {
    float m_afEntries[3][3];
    void SetCol(unsigned int uiCol, float f0, float f1, float f2)
    {
        m_afEntries[0][uiCol] = f0;
        m_afEntries[1][uiCol] = f1;
        m_afEntries[2][uiCol] = f2;
    }
};

struct TexXform {
    TexXformPoint2 m_kTranslate;
    float m_fRotation;
    TexXformPoint2 m_kScaleFactors;
    TexXformPoint2 m_kCenter;
    bool m_bTransform;
    TexXformMatrix3 m_kTransformMatrix;
    int m_eTransformMethod;

    void UpdateMatrix();
};

// @fnv 0x00a88cd0
void TexXform::UpdateMatrix()
{
    float fSin, fCos;
    TexXformSinCos(m_fRotation, fSin, fCos);

    switch (m_eTransformMethod)
    {
    case 0:
        m_kTransformMatrix.SetCol(0, fCos * m_kScaleFactors.x, fSin * m_kScaleFactors.x, 0.0f);
        m_kTransformMatrix.SetCol(1, -fSin * m_kScaleFactors.y, fCos * m_kScaleFactors.y, 0.0f);
        m_kTransformMatrix.SetCol(2,
            (fCos * (m_kTranslate.x - m_kCenter.x) + (-fSin) * (m_kTranslate.y - m_kCenter.y)) + m_kCenter.x,
            fSin * (m_kTranslate.x - m_kCenter.x) + fCos * (m_kTranslate.y - m_kCenter.y) + m_kCenter.y,
            1.0f);
        break;
    case 1:
        m_kTransformMatrix.SetCol(0, fCos * m_kScaleFactors.x, -fSin * m_kScaleFactors.y, 0.0f);
        m_kTransformMatrix.SetCol(1, fSin * m_kScaleFactors.x, fCos * m_kScaleFactors.y, 0.0f);
        m_kTransformMatrix.SetCol(2,
            (fSin * (m_kTranslate.y - m_kCenter.y) + fCos * (-m_kCenter.x - m_kTranslate.x)) * m_kScaleFactors.x + m_kCenter.x,
            (fCos * (m_kTranslate.y - m_kCenter.y) - fSin * (-m_kCenter.x - m_kTranslate.x)) * m_kScaleFactors.y + m_kCenter.y,
            1.0f);
        break;
    case 2:
        m_kTransformMatrix.SetCol(0, fCos * m_kScaleFactors.x, -fSin * m_kScaleFactors.x, 0.0f);
        m_kTransformMatrix.SetCol(1, -fSin * m_kScaleFactors.y, -fCos * m_kScaleFactors.y, 0.0f);
        m_kTransformMatrix.SetCol(2,
            fSin * (1.0f - (m_kTranslate.y + m_kCenter.y)) + fCos * (m_kTranslate.x - m_kCenter.x) + m_kCenter.x,
            fSin * (m_kCenter.x - m_kTranslate.x) + fCos * (1.0f - (m_kTranslate.y + m_kCenter.y)) + m_kCenter.y,
            1.0f);
        break;
    }
    m_bTransform = false;
}

extern int DAT_0109f23c;

struct NiPairHolder {
    void* m_vt;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
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
    void FUN_00a67c00();
};

// @fnv 0x00a8a700
NiPairHolder* __cdecl CreateNiPairHolder(void)
{
    NiPairHolder* obj = (NiPairHolder*)BSFadeNode::operator new(0x44);
    if (obj != 0) {
        obj->FUN_00a67c00();
        obj->m_vt = &DAT_0109f23c;
        obj->unk40 = 0;
        return obj;
    }
    return 0;
}

struct AlphaBlockDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;
    void DecodeAlphaBlock(unsigned char* output);
};

// @fnv 0x00a8b5e0
void AlphaBlockDecoder::DecodeAlphaBlock(unsigned char* output)
{
    unsigned char alphaTable[8];
    unsigned int first = alphaTable[0] = *cursor++;
    unsigned int second = alphaTable[1] = *cursor++;
    if (first > second) {
        alphaTable[2] = (unsigned char)((6 * first + second) / 7);
        alphaTable[3] = (unsigned char)((5 * first + 2 * second) / 7);
        alphaTable[4] = (unsigned char)((4 * first + 3 * second) / 7);
        alphaTable[5] = (unsigned char)((3 * first + 4 * second) / 7);
        alphaTable[6] = (unsigned char)((2 * first + 5 * second) / 7);
        alphaTable[7] = (unsigned char)((first + 6 * second) / 7);
    } else {
        alphaTable[2] = (unsigned char)((4 * first + second) / 5);
        alphaTable[3] = (unsigned char)((3 * first + 2 * second) / 5);
        alphaTable[4] = (unsigned char)((2 * first + 3 * second) / 5);
        alphaTable[5] = (unsigned char)((first + 4 * second) / 5);
        alphaTable[6] = 0;
        alphaTable[7] = 255;
    }
    for (unsigned int group = 0; group < 2; ++group) {
        *output = alphaTable[cursor[0] & 7]; output += 4;
        *output = alphaTable[(cursor[0] >> 3) & 7]; output += 4;
        *output = alphaTable[(cursor[0] >> 6) + ((cursor[1] & 1) << 2)]; output += 4;
        *output = alphaTable[(cursor[1] >> 1) & 7]; output += 4;
        *output = alphaTable[(cursor[1] >> 4) & 7]; output += 4;
        *output = alphaTable[(cursor[1] >> 7) + ((cursor[2] & 3) << 1)]; output += 4;
        *output = alphaTable[(cursor[2] >> 2) & 7]; output += 4;
        *output = alphaTable[cursor[2] >> 5]; output += 4;
        cursor += 3;
    }
}

struct HashNode_cls {
    HashNode_cls* m_pNext;
    unsigned int m_key;
    unsigned int m_uiFilterValue;
};

struct SdmBase {
    unsigned int m_unk00;
    unsigned int m_bucketCount;
    HashNode_cls** m_buckets;
};

// Looks up pKey's value in the global hash table's bucket chain and returns the matching node's stored value, or 0 if not found.
// @fnv 0x00a8fe20
// src: GUESS 0x00a8fe20 (confidence: medium)
unsigned int __cdecl Object_FindGlobalHashValue(unsigned int* pKey)
{
    unsigned int key = *pKey;
    if (key == (unsigned int)DAT_0109b220) goto zero;
    unsigned int tag = *(unsigned int*)(key - 4);
    if (tag == 0) return tag;
    {
        unsigned int result = 0;
        unsigned int idx = key % DAT_011f5e34->m_bucketCount;
        HashNode_cls** buckets = DAT_011f5e34->m_buckets;
        HashNode_cls* node = buckets[idx];
        while (node != 0) {
            if (key == node->m_key) {
                result = node->m_uiFilterValue;
                break;
            }
            node = node->m_pNext;
        }
        return result;
    }
zero:
    return 0;
}

extern const void* DAT_0109f7f4;
extern unsigned int DAT_011f5e48;
struct FNVObj {
    const void* vft;
    unsigned int references;
    ReferenceHandle handle;
    FNVObj* NiMaterialLibrary_NiMaterialLibrary(const ReferenceHandle& src);
};
// Initializes the object's vtable and reference count, copies src into handle, and appends this to the global object array, growing it if full.
// @fnv 0x00a8fe70
// src: EXE 0x00a8fe70
FNVObj* FNVObj::NiMaterialLibrary_NiMaterialLibrary(const ReferenceHandle& src) {
    vft = &vftable_NiRefObject;
    references = 0;
    InterlockedIncrement(&DAT_011f4400);
    vft = &DAT_0109f7f4;
    handle.value = (volatile long*)DAT_0109b220;
    handle = src;
    unsigned int capacity = DAT_011f5e48;
    if (DAT_011f5e4c == capacity) {
        if (capacity > 0)
            capacity += capacity;
        else
            capacity = 1;
        ((NiStreamLinkIDSet_blk_00a80000_o2*)&DAT_011f5e44)->Realloc(capacity);
    }
    ((FNVObj**)DAT_011f5e44)[DAT_011f5e4c] = this;
    ++DAT_011f5e4c;
    return this;
}

extern "C" void* DAT_0109b220;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

struct HandleSlot
{
    volatile long* value;

    void operator=(const ReferenceHandle& other)
    {
        volatile long* next = other.value;
        if (value != next) {
            if (next != DAT_0109b220)
                InterlockedIncrement(next - 2);
            if (value != DAT_0109b220)
                InterlockedDecrement(value - 2);
            value = next;
        }
    }
};

struct FUN_00a9bda0
{
    unsigned int identifier;
    HandleSlot handle;

    FUN_00a9bda0(unsigned int id, const ReferenceHandle* src);
};

// Initializes the slot with a default handle, stores the identifier, then copies the handle from src.
// @fnv 0x00a9bda0
FUN_00a9bda0::FUN_00a9bda0(unsigned int id, const ReferenceHandle* src)
{
    *(void* volatile*)&handle.value = DAT_0109b220;
    identifier = id;
    handle = *src;
}

extern "C" void* DAT_0109b220;
extern int (__stdcall* DAT_00fdf1c4)(void*);
extern "C" void* __cdecl FUN_00a5b690(int);

// @fnv 0x00a9bdf0
Pair::Pair() throw()
{
    *(void* volatile*)&b = DAT_0109b220;
    *(volatile unsigned int*)&a = 0;
    volatile void* old = *(void* volatile*)&b;
    if (old) {
        *(void* volatile*)&b = FUN_00a5b690(0);
        if (old != DAT_0109b220)
            DAT_00fdf1c4((void*)((char*)old - 8));
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject) {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

__forceinline NiDepthStencilBuffer::NiDepthStencilBuffer() throw() {}

// The shared header lacks the renderer-data factory overload; keep its implementation local.
// Allocates a NiDepthStencilBuffer and stores the width, height and renderer data.
// @fnv 0x00a9ff60
NiDepthStencilBuffer* CreateDepthStencilBuffer(unsigned int uiWidth, unsigned int uiHeight,
    Ni2DBuffer::RendererData* pkRendererData)
{
    NiDepthStencilBuffer* pkBuffer = new NiDepthStencilBuffer;
    pkBuffer->m_uiImageWidth = uiWidth;
    pkBuffer->m_uiImageHeight = uiHeight;
    reinterpret_cast<NiPointer<NiRefObject>&>(pkBuffer->m_pRendererData) = pkRendererData;
    return pkBuffer;
}

struct S{int a; float f;};
// Compares the f fields of two S objects, returning -1 if the first is greater, 1 if smaller, and 0 if equal.
// @fnv 0x00a81b30
int CompareFloatDescending(S* pA, S* pB){ float a=pA->f; float b=pB->f; if(a>b) return -1; if(a<b) return 1; return 0; }

struct CustomBlockDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;

    unsigned short ReadWord()
    {
        unsigned short value = (unsigned short)(cursor[1] * (unsigned short)256 + cursor[0]);
        cursor += 2;
        return value;
    }

    void DecodePaletteBlock(unsigned char* dst);
};

// Reads two 16-bit colors, builds a 16-entry RGBA palette with interpolated entries, then expands 16 two-bit indices from the cursor into dst.
// @fnv 0x00a8bab0
void CustomBlockDecoder::DecodePaletteBlock(unsigned char* pDest)
{
    unsigned char palette[16];
    unsigned short color0 = ReadWord();
    unsigned short color1 = ReadWord();

    palette[0] = (unsigned char)((color0 >> 8) & 0xf8);
    palette[1] = (unsigned char)((color0 >> 3) & 0xfe);
    palette[2] = (unsigned char)(color0 << 3);
    palette[3] = 0xff;

    palette[4] = (unsigned char)((color1 >> 8) & 0xf8);
    palette[5] = (unsigned char)((color1 >> 3) & 0xfe);
    palette[6] = (unsigned char)(color1 << 3);
    palette[7] = 0xff;

    palette[11] = 0xff;

    if (color0 > color1) {
        unsigned int red0 = palette[0];
        unsigned int green0 = palette[1];
        unsigned int red1 = palette[4];
        palette[8] = (unsigned char)((red1 + red0 * 2) / 3u);
        palette[9] = (unsigned char)((palette[5] + green0 * 2) / 3u);
        palette[10] = (unsigned char)((palette[6] + palette[2] * 2) / 3u);

        palette[12] = (unsigned char)((red0 + red1 * 2) / 3u);
        palette[13] = (unsigned char)((green0 + palette[5] * 2) / 3u);
        palette[14] = (unsigned char)((palette[2] + palette[6] * 2) / 3u);
        palette[15] = 0xff;
    } else {
        palette[8] = (unsigned char)((palette[0] + palette[4]) / 2u);
        palette[9] = (unsigned char)((palette[1] + palette[5]) / 2u);
        palette[10] = (unsigned char)((palette[2] + palette[6]) / 2u);

        palette[12] = palette[8];
        palette[13] = palette[9];
        palette[14] = palette[10];
        palette[15] = 0;
    }

    for (int row = 0; row < 4; ++row) {
        unsigned char b = *cursor;
        for (int k = 0; k < 4; ++k) {
            unsigned char* p = &palette[(b & 3) * 4];
            pDest[0] = *p++;
            pDest[1] = *p++;
            pDest[2] = *p++;
            pDest[3] = *p++;
            pDest += 4;
            b >>= 2;
        }
        cursor++;
    }
}

void __cdecl _memmove(void*,const void*,unsigned int);
// Transfer state used by the original stream implementation (offsets 4 and 8).
static inline unsigned int& StreamPosition(NiBinaryStream& stream) { return *(unsigned int*)((char*)&stream + 4); }
static inline NiBinaryStream::ReadFunction& StreamReadFunction(NiBinaryStream& stream) { return *(NiBinaryStream::ReadFunction*)((char*)&stream + 8); }
inline unsigned int NiBinaryStream::Read(void* data, unsigned int bytes) {
    unsigned int componentSize = 1;
    unsigned int transferred = StreamReadFunction(*this)(this, data, bytes, &componentSize, 1);
    StreamPosition(*this) += transferred;
    return transferred;
}

struct RleDecoder {
 unsigned int unk000;
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
 unsigned short unk10c,count;
 unsigned int unk110;
 unsigned char stride,unk115,unk116,unk117;
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
 unsigned int run;
 bool repeat;
 unsigned char value0,value1,value2;
 unsigned char value3;
 void Decode(NiBinaryStream& stream, unsigned char* dest,unsigned int unused);
};
// @fnv 0x00a8d8e0
void RleDecoder::Decode(NiBinaryStream& stream,unsigned char* dest,unsigned int unused) {
 unsigned int i=0, n;
 for(; i < count; i += n) {
  if(run==0) {
   unsigned char ucPacketHeader=0;
   stream.Read(&ucPacketHeader,1);
   repeat=(ucPacketHeader & 128)!=0;
   if(ucPacketHeader & 128) {
    run=(unsigned int)ucPacketHeader-127;
    repeat=true;
    stream.Read(&value0,stride);
   } else {
    repeat=false;
    run=(unsigned int)ucPacketHeader+1;
   }
  }
  n=count-i;
  if(run<n) n=run;
  if(repeat) {
   for(unsigned int j=0;j<n;++j) {
    _memmove(dest,&value0,stride);
    dest+=stride;
   }
  } else {
   stream.Read(dest,stride*n);
   dest+=stride*n;
  }
  run-=n;
 }
}

// 0x00a85510  ret 0x20
// @fnv 0x00a85510
// src: COMMUNITY 0x00a85510
void __stdcall nullsub_2(int, int, int, int, int, int, int, int) {
}

extern void __cdecl NiParticleMeshes_LoadBinary();
// @fnv 0x00a877d0
// src: XBOX_PDB 0x00a877d0
void __cdecl NiScreenElements_LoadBinary() {
    NiParticleMeshes_LoadBinary();
}

extern "C" void __cdecl NiParticleMeshes_SaveBinary();

// @fnv 0x00a877e0
// src: XBOX_PDB 0x00a877e0
void __cdecl NiScreenElements_SaveBinary()
{
    NiParticleMeshes_SaveBinary();
}

extern "C" void __cdecl ReadGroup();
// @fnv 0x00a88a40
// src: XBOX_PDB 0x00a88a40
void __cdecl BSTextureSet_LoadBinary()
{
    ReadGroup();
}

// 0x00a89af0  ret 4
// @fnv 0x00a89af0
// src: COMMUNITY 0x00a89af0
void __stdcall nullsub_3(int) {
}

struct S_00a8d8b0;
void __cdecl AdvancePosition(S_00a8d8b0*, void*, unsigned int);
struct FUN_00a5e3a0_Helper { void* Game_DoHeapAlloc(unsigned int); };
struct PixelRow4 {
    unsigned char rgba[4];
    PixelRow4() {}
    static void* operator new[](unsigned int size) {
        return ((FUN_00a5e3a0_Helper*)&DAT_011f6238)->Game_DoHeapAlloc(size);
    }
};
struct ImageConverter {
    unsigned int unknown000;
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned short unknown104;
    unsigned short pixelCount;
    unsigned char bitsPerPixel;
    unsigned char unknown109;
    unsigned short unknown10a;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int inputCapacity;
    unsigned char* inputBuffer;
    unsigned int outputCapacity;
    PixelRow4* outputBuffer;
    void ReadPixels(S_00a8d8b0* stream);
};
// Grows the output and input buffers to fit pixelCount, reads pixel data from the stream by bitsPerPixel, and expands it into RGBA rows in outputBuffer.
// @fnv 0x00a8da50
void ImageConverter::ReadPixels(S_00a8d8b0* stream)
{
    if (outputCapacity < pixelCount) {
        outputCapacity = pixelCount;
        g_memoryManager.Deallocate(outputBuffer);
        outputBuffer = new PixelRow4[outputCapacity];
    }
    if (inputCapacity < (unsigned int)pixelCount * 4) {
        inputCapacity = (unsigned int)pixelCount * 4;
        NiFree(inputBuffer);
        inputBuffer = (unsigned char*)_NiMalloc_00aa1070(inputCapacity);
    }
    unsigned char* out = (unsigned char*)outputBuffer;
    switch (bitsPerPixel) {
    case 8: {
        unsigned char* in = inputBuffer;
        AdvancePosition(stream, in, pixelCount);
        for (unsigned int i = 0; i < pixelCount; ++i) {
            out[0] = out[1] = out[2] = *in;
            out[3] = 255;
            out += 4;
            ++in;
        }
        break;
    }
    case 15:
    case 16: {
        unsigned char* in = inputBuffer;
        AdvancePosition(stream, in, pixelCount * 2);
        for (unsigned int i = 0; i < pixelCount; ++i) {
            out[0] = (in[1] & 0xfc) << 1;
            out[1] = ((in[0] >> 2) & 0x38) + (in[1] << 6);
            out[2] = in[0] << 3;
            out[3] = 255;
            out += 4;
            in += 2;
        }
        break;
    }
    case 24: {
        unsigned char* in = inputBuffer;
        AdvancePosition(stream, in, pixelCount * 3);
        for (unsigned int i = 0; i < pixelCount; ++i) {
            out[2] = *in++;
            out[1] = *in++;
            out[0] = *in++;
            out[3] = 255;
            out += 4;
        }
        break;
    }
    case 32: {
        unsigned char* in = inputBuffer;
        AdvancePosition(stream, in, pixelCount * 4);
        for (unsigned int i = 0; i < pixelCount; ++i) {
            out[2] = *in++;
            out[1] = *in++;
            out[0] = *in++;
            out[3] = *in++;
            out += 4;
        }
        break;
    }
    }
}

inline NiRefObject::~NiRefObject() {
    InterlockedDecrement(&DAT_011f4400);
}
struct StringHandle_a8f {
    volatile long* value;
    ~StringHandle_a8f() throw() {
        if (value != DAT_0109b220)
            InterlockedDecrement(value - 2);
    }
};
class FUN_00a8f490 : public NiRefObject {
public:
    virtual ~FUN_00a8f490();
    StringHandle_a8f m_08;
};
// Destructor of a NiRefObject-derived class holding a StringHandle_a8f member; the member's destructor releases the string reference.
// @fnv 0x00a8f490
FUN_00a8f490::~FUN_00a8f490() {
}

struct FUN_00a923a0_class {
    unsigned short __thiscall NiParticlesData_GetActiveVertexCount();
};

// @fnv 0x00a923a0
// src: XBOX_PDB 0x00a923a0
unsigned short __thiscall FUN_00a923a0_class::NiParticlesData_GetActiveVertexCount()
{
    return *reinterpret_cast<unsigned short*>(this + 0x50);
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#include <math.h>
extern "C" float epsilon;
struct FUN_00a88970_q { float w, x, y, z; void Set(float fW, float fX, float fY, float fZ); };
struct FUN_00a88970_v { void* m_pvVtbl; float x, y, z; };
// @fnv 0x00a88970
// src: GAMEBRYO_LIB 0x00a88970
FUN_00a88970_q NiQuaternion_Exp(const FUN_00a88970_v& v)
{
    float fScaleMultiplier = v.x * v.x + v.y * v.y + v.z * v.z;
    fScaleMultiplier = sqrt(fScaleMultiplier);
    float fAngleDifference = fScaleMultiplier;
    float fSin, fCos;
    fnv_SinCos(fAngleDifference, fSin, fCos);
    float fScale = fabs(fSin);
    if (fScale < epsilon) fScale = 1.0f; else fScale = fSin / fAngleDifference;
    FUN_00a88970_q q;
    q.Set(fCos, v.x * fScale, v.y * fScale, v.z * fScale);
    return q;
}

struct FUN_00a81a40_shell {
    int __thiscall NiTaskManager_GetNumTasks(int ai);
};

// Reads the 16-byte slot at this+8+ai*16; returns 0 if its +8 value is -1, otherwise a difference built from its +4, +8 and +12 values.
// @fnv 0x00a81a40
// src: GAMEBRYO_LIB 0x00a81a40
int __thiscall FUN_00a81a40_shell::NiTaskManager_GetNumTasks(int ai)
{
    char* pSlot = (char*)this + 8 + ai * 16;
    int value = *(int*)(pSlot + 8);
    return value == -1 ? 0
        : ((unsigned)value >= (unsigned)*(int*)(pSlot + 12)
        ? *(int*)(pSlot + 4) - value + *(int*)(pSlot + 12)
        : *(int*)(pSlot + 12) - value);
}

void* NiMalloc(unsigned int uiSize);

struct FUN_00a8a620 {
    unsigned int m_uiSize;
    void* m_pBuffer;
    void* m_pCursor;
    int m_iUsed;

    FUN_00a8a620(unsigned int uiSize);
};
// Initializes the buffer size, allocates m_pBuffer with NiMalloc if uiSize is non-zero, sets m_pCursor to m_pBuffer, and resets m_iUsed to 0.
// @fnv 0x00a8a620
FUN_00a8a620::FUN_00a8a620(unsigned int uiSize)
{
    m_uiSize = uiSize;
    if (uiSize)
        m_pBuffer = NiMalloc(uiSize);
    else
        m_pBuffer = 0;
    m_pCursor = m_pBuffer;
    m_iUsed = 0;
}

struct ByteDecoder {
    unsigned int unk000;
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
    unsigned char bias;
    unsigned char unk105;
    unsigned short unk106;
    unsigned int unk108;
    unsigned short unk10c;
    unsigned short count;

    void DecodeBytes(unsigned char* src, unsigned char* dst);
};

// Subtracts bias from each of count/2 source bytes and writes the results to dst.
// @fnv 0x00a8d460
void ByteDecoder::DecodeBytes(unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < (count >> 1); i++) {
        unsigned char b = *src++ - bias;
        *dst++ = b;
    }
}

#include <string.h>
// Returns 1 if a is null, -1 if b is null, otherwise returns the result of comparing the two strings pointed to by a and b.
// @fnv 0x00a86280
// src: COMMUNITY 0x00a86280
int __cdecl CompareBoneNames(const char** apStrA, const char** apStrB)
{
    if (apStrA == 0)
        return 1;

    if (apStrB == 0)
        return -1;

    return strcmp(*apStrA, *apStrB);
}

struct StaticKeyB5542 {
    StaticKeyB5542(int v) throw() { m_00 = v; }
    ~StaticKeyB5542() throw() {}
    unsigned int m_00;
};

extern unsigned int NiReferenceSlotKeyInitialized;
extern StaticKeyB5542 NiReferenceSlotKey;
extern void __cdecl DestroyNiReferenceSlotKey();
extern "C" int __cdecl atexit(void (__cdecl*)());

class FUN_00a9ba90_cls {
public:
    unsigned int unk00;
    NiRefObject** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void SetReferenceSlotAndUpdateCounts(unsigned int idx, NiRefObject** a2);
};

// Sets the NiRefStub at idx, updating m_0a/m_0c and swapping the reference with ref-counted destroy/increment.
// @fnv 0x00a9ba90
// src: GUESS 0x00a9ba90 (confidence: medium)
void FUN_00a9ba90_cls::SetReferenceSlotAndUpdateCounts(unsigned int idx, NiRefObject** apRefStub) {
    if (!(NiReferenceSlotKeyInitialized & 1)) {
        NiReferenceSlotKeyInitialized |= 1;
        NiReferenceSlotKey.m_00 = 0;
        atexit(DestroyNiReferenceSlotKey);
    }
    if (idx >= m_0a) {
        m_0a = (unsigned short)(idx + 1);
        if ((unsigned int)*apRefStub == NiReferenceSlotKey.m_00) {
        } else {
            m_0c++;
        }
    } else {
        if ((unsigned int)*apRefStub != NiReferenceSlotKey.m_00) {
            if ((unsigned int)m_04[idx] == NiReferenceSlotKey.m_00) {
                m_0c++;
            }
        } else {
            if ((unsigned int)m_04[idx] != NiReferenceSlotKey.m_00) {
                m_0c--;
            }
        }
    }
    NiRefObject** slot = &m_04[idx];
    NiRefObject* old = *slot;
    if (old != *apRefStub) {
        if (old != 0) {
            if (InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0) {
                old->DeleteThis();
            }
        }
        NiRefObject* pNew = *apRefStub;
        *slot = pNew;
        if (pNew != 0) {
            InterlockedIncrement((volatile long*)&pNew->m_uiRefCount);
        }
    }
}

struct BitmapStreamVtable {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void (__thiscall* seek)(NiBinaryStream*, int);
};
extern void (__stdcall* DAT_00fdf05c)(void*);
extern void (__stdcall* DAT_00fdf100)(void*);
extern const NiPixelFormat DAT_011aa210;
extern const NiPixelFormat DAT_011aa2e8;
extern const NiPixelFormat gNiPoint3StartupSrc;
struct BitmapReader {
    unsigned int unk000;
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
    unsigned int width;
    unsigned int height;
    NiPixelFormat format;
    unsigned short bitsPerPixel;
    unsigned short unk14e;
    unsigned int colorsUsed;
    unsigned int pixelOffset;
    bool bottomUp;
    bool ReadBitmapHeader(NiBinaryStream& stream, unsigned int& outWidth,
        unsigned int& outHeight, NiPixelFormat& outFormat, bool& outFlag, unsigned int& outMips);
};
template<class T> inline void ReadValue(NiBinaryStream& stream, T& value) {
    unsigned int componentSize = sizeof(T);
    StreamPosition(stream) += StreamReadFunction(stream)(&stream, &value, sizeof(T), &componentSize, 1);
}
// @fnv 0x00a8e4b0
bool BitmapReader::ReadBitmapHeader(NiBinaryStream& stream, unsigned int& outWidth,
    unsigned int& outHeight, NiPixelFormat& outFormat, bool& outFlag, unsigned int& outMips)
{
    ((BitmapStreamVtable*)*(void**)&stream)->seek(&stream, 0);
    outMips = 1;
    unsigned short signature;
    ReadValue(stream, signature);
    if (signature != 0x4d42)
        return false;
    DAT_00fdf05c(&unk080);
    unsigned int fileSize;
    ReadValue(stream, fileSize);
    ReadValue(stream, signature);
    ReadValue(stream, signature);
    ReadValue(stream, pixelOffset);
    unsigned int headerSize;
    int imageWidth, imageHeight;
    unsigned int compression;
    int resolution;
    ReadValue(stream, headerSize);
    ReadValue(stream, imageWidth);
    ReadValue(stream, imageHeight);
    ReadValue(stream, signature);
    ReadValue(stream, bitsPerPixel);
    ReadValue(stream, compression);
    ReadValue(stream, fileSize);
    ReadValue(stream, resolution);
    ReadValue(stream, resolution);
    ReadValue(stream, colorsUsed);
    ReadValue(stream, fileSize);
    if (headerSize == 4) {
        DAT_00fdf100(&unk080);
        return false;
    }
    switch (bitsPerPixel) {
    case 4:
    case 8: format = DAT_011aa210; break;
    case 24: format = DAT_011aa2e8; break;
    case 32: format = gNiPoint3StartupSrc; break;
    default:
        DAT_00fdf100(&unk080);
        return false;
    }
    if (compression == 2 || compression == 1) {
        DAT_00fdf100(&unk080);
        return false;
    }
    width = imageWidth;
    bottomUp = imageHeight >= 0;
    height = imageHeight > 0 ? imageHeight : -imageHeight;
    if (colorsUsed == 0 && bitsPerPixel != 24 && bitsPerPixel != 32)
        colorsUsed = 1 << bitsPerPixel;
    outWidth = width;
    outHeight = height;
    outFormat = format;
    outFlag = true;
    DAT_00fdf100(&unk080);
    return true;
}




    inline float NiMatrix3::GetEntry(unsigned int row, unsigned int col) const { return (&m_pEntry[0][0])[row * 3 + col]; }



// @fnv 0x00a85520

    inline NiMatrix3 NiMatrix3::operator*(float s) const {



        NiMatrix3 r;



        r.m_pEntry[0][0] = GetEntry(0,0) * s;



        r.m_pEntry[0][1] = GetEntry(0,1) * s;



        r.m_pEntry[0][2] = GetEntry(0,2) * s;



        r.m_pEntry[1][0] = GetEntry(1,0) * s;



        r.m_pEntry[1][1] = GetEntry(1,1) * s;



        r.m_pEntry[1][2] = GetEntry(1,2) * s;



        r.m_pEntry[2][0] = GetEntry(2,0) * s;



        r.m_pEntry[2][1] = GetEntry(2,1) * s;



        r.m_pEntry[2][2] = GetEntry(2,2) * s;



        return r;



    }




// Inline arithmetic used by the skinning routine.
inline float& NiPoint3::operator[](int i) { return (&x)[i]; }
inline const float& NiPoint3::operator[](int i) const { return (&x)[i]; }
inline float NiPoint3::Readx() const { return x; }
inline float NiPoint3::Ready() const { return y; }
inline NiPoint3::NiPoint3(float a, float b, float c) { x=a; y=b; z=c; }
inline NiPoint3 NiPoint3::operator*(float s) const {
    NiPoint3 p; p.x=s*x; p.y=s*y; p.z=s*z; return p;
}
inline void NiPoint3::AddByValue(NiPoint3 p) { x += p[0]; y += p[1]; z += p[2]; }

inline NiTransform::NiTransform() {}
// M * v: each output coordinate is one matrix row dotted with v (x, y, z terms in that order)
#define M3_ROW_DOT_V(i) m_pEntry[i][0] * kV.x + m_pEntry[i][1] * kV.y + m_pEntry[i][2] * kV.z
inline NiPoint3 NiMatrix3::operator*(const NiPoint3& kV) const
{
    return NiPoint3(M3_ROW_DOT_V(0), M3_ROW_DOT_V(1), M3_ROW_DOT_V(2));
}
#undef M3_ROW_DOT_V
// The skinning loops inline M*p+t in two parenthesisations (row sums kept apart differently).
struct NiMatrix3_SkinView : public NiMatrix3
{
    NiPoint3 MulAddFirst(const NiPoint3& p, const NiPoint3& t) const;
    NiPoint3 MulAddSecond(const NiPoint3& p, const NiPoint3& t) const;
};
inline NiPoint3 NiMatrix3_SkinView::MulAddFirst(const NiPoint3& p, const NiPoint3& t) const {
    return NiPoint3(
        GetEntry(0,0)*p.Readx() + GetEntry(0,1)*p.Ready() + GetEntry(0,2)*p.z + t.x,
        ((GetEntry(1,0)*p.Readx() + GetEntry(1,1)*p.Ready()) + GetEntry(1,2)*p.z + t.y),
        GetEntry(2,0)*p.Readx() + GetEntry(2,1)*p.Ready() + GetEntry(2,2)*p.z + t.z);
}
inline NiPoint3 NiMatrix3_SkinView::MulAddSecond(const NiPoint3& p, const NiPoint3& t) const {
    return NiPoint3(
        GetEntry(0,0)*p.Readx() + GetEntry(0,1)*p.Ready() + GetEntry(0,2)*p.z + t.x,
        GetEntry(1,0)*p.Readx() + (GetEntry(1,1)*p.Ready()) + GetEntry(1,2)*p.z + t.y,
        (GetEntry(2,0)*p.Readx() + GetEntry(2,1)*p.Ready()) + GetEntry(2,2)*p.z + t.z);
}

namespace skinning {
static __forceinline NiMatrix3 operator*(float s, const NiMatrix3& m) { return m*s; }
static __forceinline void XformZ(const NiMatrix3& m, const float& x, const float& y, const float& z, const NiPoint3& t, NiPoint3& r) {
        r.x = m.GetEntry(0,0)*x + m.GetEntry(0,1)*y + m.GetEntry(0,2)*z + t.x;
        r.y = m.GetEntry(1,0)*x + (m.GetEntry(1,1)*y) + m.GetEntry(1,2)*z + t.y;
        r.z = m.GetEntry(2,0)*x + (m.GetEntry(2,1)*y) + m.GetEntry(2,2)*z + t.z;
}
struct SkinObject {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64;
    NiTransform world;
    const NiTransform& GetWorld() const { return world; }
};
struct SkinData {
    struct Weight {
        unsigned short vertex;
        unsigned short unk02;
        float weight;
    };
    struct Bone {
        NiTransform skinToBone;
        NiPoint3 center;
        float radius;
        Weight* weights;
        unsigned short count;
        unsigned short unk4a;
    };
    void* vtable;
    unsigned int refs;
    void* partition;
    NiTransform rootToSkin;
    Bone* bones;
    unsigned int count;
    const NiTransform& GetRootToSkin() const { return rootToSkin; }
    const Bone* GetBones() const { return bones; }
    unsigned int GetCount() const { return count; }
};
template<class T> struct SkinPointer {
    T* ptr;
    T* operator->() const { return ptr; }
};
struct SkinInstance {
    void* vtable;
    unsigned int refs;
    SkinPointer<SkinData> data;
    void* partition;
    SkinObject* root;
    SkinObject** bones;
    void NiSkinInstance_Deform(const NiPoint3* positions, const NiPoint3* normals,
        unsigned int count, NiPoint3* dstPos, NiPoint3* dstNorm,
        NiPoint3* dstTan, NiPoint3* dstBin, unsigned int stride) const;
};
extern const NiPoint3 NiPoint3_ZERO;
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
void __cdecl NormalizePoints(NiPoint3*, unsigned int, unsigned int);
// Applies per-bone weighted transforms to positions, normals, tangents and binormals, accumulating results into the destination arrays.
// @fnv 0x00a855f0
// src: COMMUNITY 0x00a855f0
void SkinInstance::NiSkinInstance_Deform(const NiPoint3* positions, const NiPoint3* normals,
    unsigned int count, NiPoint3* dstPos, NiPoint3* dstNorm,
    NiPoint3* dstTan, NiPoint3* dstBin, unsigned int stride) const
{
    NiTransform rootTransform;
    root->GetWorld().FUN_004b4880(&rootTransform);
    rootTransform = data->GetRootToSkin() * rootTransform;
    const SkinData::Bone* boneData = data->GetBones();
    unsigned int boneCount = data->GetCount();
    unsigned int boneIndex;
    NiTransform boneTransform;
    NiMatrix3 scaledRotation;
    unsigned short vertexIndex;
    if (normals && dstNorm) {
        if (dstTan && dstBin) {
            const NiPoint3* tangents = normals + count;
            const NiPoint3* binormals = tangents + count;
            if (stride == sizeof(NiPoint3)) {
                _fnv_zlib_memset(dstPos, 0, count * sizeof(NiPoint3));
                _fnv_zlib_memset(dstNorm, 0, count * sizeof(NiPoint3));
                _fnv_zlib_memset(dstTan, 0, count * sizeof(NiPoint3));
                _fnv_zlib_memset(dstBin, 0, count * sizeof(NiPoint3));
            } else {
                NiPoint3* p = dstPos;
                NiPoint3* n = dstNorm;
                NiPoint3* t = dstTan;
                NiPoint3* b = dstBin;
                for (unsigned int i = 0; i < count; ++i) {
                    *p = NiPoint3_ZERO;
                    p = (NiPoint3*)((char*)p + stride);
                    *n = NiPoint3_ZERO;
                    n = (NiPoint3*)((char*)n + stride);
                    *t = NiPoint3_ZERO;
                    t = (NiPoint3*)((char*)t + stride);
                    *b = NiPoint3_ZERO;
                    b = (NiPoint3*)((char*)b + stride);
                }
            }
            for (boneIndex = 0; boneIndex < boneCount; ++boneIndex) {
                NiPoint3 p, n, t, b;
                const SkinData::Bone& bone = boneData[boneIndex];
                unsigned int vertexCount = bone.count;
                boneTransform = rootTransform * bones[boneIndex]->GetWorld() * bone.skinToBone;
                scaledRotation = boneTransform.m_fScale * boneTransform.m_Rotate;
                const SkinData::Weight* weights = bone.weights;
                for (unsigned int j = 0; j < vertexCount; ++j) {
                    const SkinData::Weight& w = weights[j];
                    vertexIndex = w.vertex;
                    float weight = w.weight;
                    unsigned int offset = vertexIndex * stride;
                    p = ((const NiMatrix3_SkinView&)scaledRotation).MulAddFirst(positions[vertexIndex], boneTransform.m_Translate);
                    {
                    n.x = boneTransform.m_Rotate.GetEntry(0, 0) * normals[vertexIndex].Readx() + boneTransform.m_Rotate.GetEntry(0, 1) * normals[vertexIndex].y + boneTransform.m_Rotate.GetEntry(0, 2) * normals[vertexIndex].z;
                    n.y = boneTransform.m_Rotate.GetEntry(1, 0) * normals[vertexIndex].x + boneTransform.m_Rotate.GetEntry(1, 1) * normals[vertexIndex].y + boneTransform.m_Rotate.GetEntry(1, 2) * normals[vertexIndex].z;
                    n.z = boneTransform.m_Rotate.GetEntry(2, 0) * normals[vertexIndex].x + boneTransform.m_Rotate.GetEntry(2, 1) * normals[vertexIndex].Ready() + boneTransform.m_Rotate.GetEntry(2, 2) * normals[vertexIndex].z;
                    }
                    t = boneTransform.m_Rotate * tangents[vertexIndex];
                    b = boneTransform.m_Rotate * binormals[vertexIndex];
                    *(NiPoint3*)((char*)dstPos + offset) += p * weight;
                    ((NiPoint3*)((char*)dstNorm + offset))->AddByValue(n * weight);
                    *(NiPoint3*)((char*)dstTan + offset) += t * weight;
                    *(NiPoint3*)((char*)dstBin + offset) += b * weight;
                }
            }
            NormalizePoints(dstNorm, count, stride);
            NormalizePoints(dstTan, count, stride);
            NormalizePoints(dstBin, count, stride);
            return;
        }
        if (stride == sizeof(NiPoint3)) {
            _fnv_zlib_memset(dstPos, 0, count * sizeof(NiPoint3));
            _fnv_zlib_memset(dstNorm, 0, count * sizeof(NiPoint3));
        } else {
            NiPoint3* p = dstPos;
            NiPoint3* n = dstNorm;
            for (unsigned int i = 0; i < count; ++i) {
                *p = NiPoint3_ZERO;
                p = (NiPoint3*)((char*)p + stride);
                *n = NiPoint3_ZERO;
                n = (NiPoint3*)((char*)n + stride);
            }
        }
        for (boneIndex = 0; boneIndex < boneCount; ++boneIndex) {
            NiPoint3 p, n;
            const SkinData::Bone& bone = boneData[boneIndex];
            unsigned int vertexCount = bone.count;
            boneTransform = rootTransform * bones[boneIndex]->GetWorld() * bone.skinToBone;
            scaledRotation = boneTransform.m_Rotate * boneTransform.m_fScale;
            const SkinData::Weight* weights = bone.weights;
            const NiPoint3& translate = boneTransform.m_Translate;
            for (unsigned int j = 0; j < vertexCount; ++j) {
                vertexIndex = weights[j].vertex;
                float weight = weights[j].weight;
                unsigned int offset = vertexIndex * stride;
                p = ((const NiMatrix3_SkinView&)scaledRotation).MulAddSecond(positions[vertexIndex], translate);
                    {
                    n.x = boneTransform.m_Rotate.GetEntry(0, 0) * normals[vertexIndex].x + boneTransform.m_Rotate.GetEntry(0, 1) * normals[vertexIndex].y + boneTransform.m_Rotate.GetEntry(0, 2) * normals[vertexIndex].z;
                    n.y = boneTransform.m_Rotate.GetEntry(1, 0) * normals[vertexIndex].x + boneTransform.m_Rotate.GetEntry(1, 1) * normals[vertexIndex].y + boneTransform.m_Rotate.GetEntry(1, 2) * normals[vertexIndex].z;
                    n.z = boneTransform.m_Rotate.GetEntry(2, 0) * normals[vertexIndex].x + boneTransform.m_Rotate.GetEntry(2, 1) * normals[vertexIndex].y + boneTransform.m_Rotate.GetEntry(2, 2) * normals[vertexIndex].z;
                    }
                *(NiPoint3*)((char*)dstPos + offset) += p * weight;
                ((NiPoint3*)((char*)dstNorm + offset))->AddByValue(n * weight);
            }
        }
        NormalizePoints(dstNorm, count, stride);
        return;
    }
    if (stride == sizeof(NiPoint3)) {
        _fnv_zlib_memset(dstPos, 0, count * sizeof(NiPoint3));
    } else {
        NiPoint3* p = dstPos;
        for (unsigned int i = 0; i < count; ++i) {
            *p = NiPoint3_ZERO;
            p = (NiPoint3*)((char*)p + stride);
        }
    }
    for (boneIndex = 0; boneIndex < boneCount; ++boneIndex) {
        NiPoint3 p;
        const SkinData::Bone& bone = boneData[boneIndex];
        unsigned int vertexCount = bone.count;
        boneTransform = rootTransform * bones[boneIndex]->GetWorld() * bone.skinToBone;
        scaledRotation = boneTransform.m_fScale * boneTransform.m_Rotate;
        const SkinData::Weight* weights = bone.weights;
        const NiPoint3& translate = boneTransform.m_Translate;
        for (unsigned int j = 0; j < vertexCount; ++j) {
            const SkinData::Weight& w = weights[j];
            unsigned short vertexIndex = w.vertex;
            float weight = w.weight;
            unsigned int offset = vertexIndex * stride;
            NiPoint3* out = (NiPoint3*)((char*)dstPos + offset);
            const float* point = &p.x;
            XformZ(scaledRotation, positions[vertexIndex].x, positions[vertexIndex].y, positions[vertexIndex].z, translate, p);
            fnv_AddWeightedPoint(out, point, weight);
        }
    }
}

} // namespace skinning

extern int DAT_011f5e44;
extern int DAT_011f5e4c;
extern int (__stdcall* DAT_00fdf1c4)(void*);
extern const void* vftable_NiRefObject;


struct MaterialLibraryView {
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    void ProcessEntries_00a8fdb0();
};

// Swap-removes this from the pointer array at DAT_011f5e44, releases m_8 via DAT_00fdf1c4 unless it is _EmptyFS, and sets the NiRefObject vtable.
// @fnv 0x00a8fdb0
// src: GUESS 0x00a8fdb0 (confidence: low)
void MaterialLibraryView::ProcessEntries_00a8fdb0()
{
    vtbl = &DAT_0109f7f4;
    unsigned int count = DAT_011f5e4c;
    unsigned int i = 0;
    if (count > 0) {
        int* arr = (int*)DAT_011f5e44;
        do {
            if (arr[i] == (int)this) {
                if ((int)i >= 0) {
                    count--;
                    DAT_011f5e4c = count;
                    arr[i] = arr[count];
                }
                break;
            }
            i++;
        } while (i < count);
    }
    int h = m_8;
    int (__stdcall* fn)(void*) = DAT_00fdf1c4;
    if (h != (int)_EmptyFS) {
        fn((void*)(h - 8));
    }
    vtbl = (void*)&vftable_NiRefObject;
    fn((void*)&DAT_011f4400);
}
