
// src/staging/blk_00b60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

#include "../../include/NiTPointerAllocator.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTListBase.h"
#include "../../include/NiTPointerListBase.h"

#include "../../include/NiTexturingProperty.h"

#include "../../include/BSBatchRenderer.h"
#include "../../include/BSFogProperty.h"
// BSRenderStateManager_blk_00b60000_o2: local type (was include/BSRenderStateManager.h, which had no evidence of one real class); its methods are 0x00b97fa0 BSRenderState::SetAlphaBlendEnable, 0x00b98380 BSRenderState::SetColorWriteEnable
#include "../../include/BSRENDERSTATE_LOCK.h"

class BSRenderStateManager_blk_00b60000_o2
{
public:
    static void __cdecl SetDepthBufferEnabled(bool, BSRENDERSTATE_LOCK);
    static void __cdecl SetDepthBufferEnabled(bool, int);
    static void __cdecl SetColorWriteMask(unsigned int, BSRENDERSTATE_LOCK);
    static void __cdecl SetColorWriteMask(unsigned int, unsigned int);
};
#include "../../include/BSShaderAccumulator.h"
#include "../../include/BSStream.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/NiAccumulator.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiGPUProgram.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiNode.h"
#include "../../include/NiObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiQuaternion.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiRenderer.h"
#include "../../include/NiTexture.h"
#include "../../include/NiSourceTexture.h"
#include "../../include/NiTransform.h"
#include "../../include/NiMatrix3.h"
#include "../../include/V4.h"
#include "../../include/NiPoint3.h"
#include "../../include/Vec4.h"
#include "../../include/BSShaderManager.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiStream.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMap.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/RecursiveSpinLock.h"
#include "../../include/StrArr.h"


extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
inline V4::V4() {}
inline V4::V4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
inline void V4::operator=(const V4& other)
{
    memcpy(this, &other, sizeof(V4));
}
static __forceinline void SetShaderVector(V4& dest, float a, float b, float c, float d)
{
    float components[4] = {a, b, c, d};
    memcpy(&dest, components, sizeof(V4));
}
inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& b) const
{
    NiPoint3 r(x + b.x, y + b.y, z + b.z);
    return r;
}
inline NiPoint3 NiPoint3::operator*(float b) const
{
    NiPoint3 r = *this;
    r.x *= b; r.y *= b; r.z *= b;
    return r;
}
inline NiQuaternion::NiQuaternion() {}
inline NiTransform::NiTransform() {}
inline NiRefObject::NiRefObject() : m_uiRefCount(0)
{
    InterlockedIncrement((volatile long*)&ms_lObjectCount);
}
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiSourceTexture::DecRefCount()
{
    NiRefObject::DecRefCount();
}
inline void NiNode::DecRefCount()
{
    NiRefObject::DecRefCount();
}
inline void NiD3DPixelShader::DecRefCount()
{
    NiRefObject::DecRefCount();
}
inline void NiGPUProgram::IncRefCount() throw()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiGPUProgram::DecRefCount() throw()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

// These operations are absent from the shared accumulator API. Extend the
// checked layout locally; the two additional virtuals occupy slots 42 and 43.
class ShaderAccumulatorLocal : public BSShaderAccumulator
{
public:
    virtual void PreparePasses();
    virtual void FinishPasses();
    void BSShaderAccumulator_FinishAccumulatingPostResolveDepth();
    void ApplyRenderMode();
    void BSShaderAccumulator_ClearBloodSplatter();
    void BSShaderAccumulator_ClearGroupPasses(unsigned int index);
    void BSShaderAccumulator_ClearSharedMap();
    void BSShaderAccumulator_FinishAccumulating();
    int SumItemSubValues();
};

struct FUN_00b6f4a0_class
{
    float f0x00;
    float f0x04;
    float f0x08;
    float f0x0c;
    float f0x10;
    float f0x14;
    float f0x18;
    float f0x1c;
    float f0x20;
    float f0x24;
    float f0x28;
    float f0x2c;
    float f0x30;
    float f0x34;
    float f0x38;
    float f0x3c;
    float f0x40;
    float f0x44;
    float f0x48;
    float f0x4c;
    float f0x50;
    float f0x54;
    float f0x58;
    float f0x5c;
    float f0x60;
    float f0x64;
    float f0x68;
    float f0x6c;
    float f0x70;
    float f0x74;
    float f0x78;
    float f0x7c;
    void CopySourceValues(const float* src);
};

// Copies four floats from src into f0x70..f0x7c, skipping any field that currently equals -1.0f.
// @fnv 0x00b6f4a0
void FUN_00b6f4a0_class::CopySourceValues(const float* afSource)
{
    if (f0x70 != -1.0f)
        f0x70 = afSource[0];
    if (f0x74 != -1.0f)
        f0x74 = afSource[1];
    if (f0x78 != -1.0f)
        f0x78 = afSource[2];
    if (f0x7c != -1.0f)
        f0x7c = afSource[3];
}

extern float DAT_011f9ee0;
extern float DAT_011f9ee4;
extern float DAT_011f9ee8;
extern float DAT_011f9eec;

// Stores a and c into two globals and their differences b-a and d-c into two more globals.
// @fnv 0x00b60120
// src: COMMUNITY 0x00b60120
void TallGrassShaderProperty_SetFadeParameters(float a, float b, float c, float d)
{
    DAT_011f9ee0 = a;
    DAT_011f9ee4 = b - a;
    DAT_011f9ee8 = c;
    DAT_011f9eec = d - c;
}

class OwnerBucket;
class B61Entry;
class ShaderBufferRecord;
typedef NiTMapBase<DFALL<NiTMapItem<unsigned int, OwnerBucket*> >, unsigned int, OwnerBucket*> OwnerMapBase;
typedef NiTMap<unsigned int, OwnerBucket*> OwnerMap;
typedef NiTMapBase<DFALL<NiTMapItem<const char*, NiPointer<B61Entry> > >, const char*, NiPointer<B61Entry> > CachedGeometryMapBase;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, NiAVObject*, bool> RoomMapBase;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, ShaderBufferRecord*> ShaderBufferMapBase;

void __cdecl NiFreeAlias(void*);

// @fnv 0x00b603e0
template <> OwnerMapBase::~NiTMapBase()
{
    RemoveAll();
    NiFreeAlias(m_ppkHashTable);
}

// @fnv 0x00b60400
template <> CachedGeometryMapBase::~NiTMapBase()
{
    RemoveAll();
    NiFreeAlias(m_ppkHashTable);
}

extern MemoryManager g_memoryManager;
struct FUN_00b60420_class
{
    void FUN_00b60420();
    void* FUN_00b60620(int flags);
};
// @fnv 0x00b60620
void* FUN_00b60420_class::FUN_00b60620(int flags)
{
    FUN_00b60420();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

// @fnv 0x00b60c70
OwnerMap* __fastcall DestroyOwnerMap(OwnerMap* self, void*, bool dealloc)
{
    self->OwnerMap::~NiTMap();
    if (dealloc & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

void __cdecl FUN_00b60d80(void);
extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00b61220_class
{
    void* DestroyIfFlagged(int flag);
};

// Calls FUN_00b60d80, deletes this with size 0x98 when flag has bit 0 set, and returns this.
// @fnv 0x00b61220
void* FUN_00b61220_class::DestroyIfFlagged(int aiFlags)
{
    FUN_00b60d80();
    if (aiFlags & 1)
        operator delete(this, 0x98);
    return this;
}

// @fnv 0x00b63bd0
// src: GUESS 0x00b63bd0 (confidence: low)
void __stdcall Object_UpdateState_00b63bd0(void* apObject, int aiValue, char c)
{
    *(int*)((char*)apObject + 4) = aiValue;
    *(char*)((char*)apObject + 8) = c;
}

// @fnv 0x00b63d60
template <> RoomMapBase::~NiTMapBase()
{
    RemoveAll();
    NiFreeAlias(m_ppkHashTable);
}

void __cdecl FUN_00b656e0();
extern "C" void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00b664f0_class
{
    void* FUN_00b664f0(unsigned int flags);
};

// Calls FUN_00b656e0, then deletes this with size 0x280 if flags has bit 0 set, and returns this.
// @fnv 0x00b664f0
void* FUN_00b664f0_class::FUN_00b664f0(unsigned int flags)
{
    FUN_00b656e0();
    if (flags & 1)
        operator delete(this, 0x280);
    return this;
}

void __cdecl BSShaderAccumulator_FinishAccumulating_Standard_PostResolveDepth(void*);

// @fnv 0x00b66570
// src: XBOX_PDB 0x00b66570
void ShaderAccumulatorLocal::BSShaderAccumulator_FinishAccumulatingPostResolveDepth()
{
    if (!*(int*)((char*)this + 0x19c))
        BSShaderAccumulator_FinishAccumulating_Standard_PostResolveDepth(this);
    *(int*)((char*)NiRenderer::ms_pRenderer + 0xc) = 0;
    ((NiAccumulator*)this)->ClearCamera();
}

// @fnv 0x00b66760
// src: GUESS 0x00b66760 (confidence: low)
int __cdecl Object_ComputeValue_00b66760(int a)
{
    if (a != 252 && a != 258)
        return 0;
    return 1;
}

void __cdecl FUN_00b6a520();

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00b6adb0_class
{
    void* FUN_00b6adb0(int flags);
};

// Calls FUN_00b6a520, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00b6adb0
void* FUN_00b6adb0_class::FUN_00b6adb0(int flags)
{
    FUN_00b6a520();
    if (flags & 1)
        operator delete(this, 336);
    return this;
}

void __cdecl FUN_00b6aef0();
void __cdecl operator delete(void* p, unsigned int) throw();

struct FUN_00b6b160_class
{
    FUN_00b6b160_class* __thiscall FUN_00b6b160(int flags);
};

// Calls FUN_00b6aef0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00b6b160
FUN_00b6b160_class* __thiscall FUN_00b6b160_class::FUN_00b6b160(int flags)
{
    FUN_00b6aef0();
    if (flags & 1)
        operator delete(this, 0x40);
    return this;
}

void BSShaderProperty_SetFlagRecurse(void* dst, int size, const void* src);

// @fnv 0x00b6b910
void __cdecl CopyBlock48(void* dst, const void* src)
{
    BSShaderProperty_SetFlagRecurse(dst, 0x30, src);
}

extern double DAT_010ae8b0;
extern double DAT_010ae8b8;
extern double DAT_010ae8c0;

class ShaderWeightedVector : public NiPoint3
{
public:
    float ComputeWeightedSum();
};

// Returns f1*DAT_010ae8c0 + f0*DAT_010ae8b8 + f2*DAT_010ae8b0, a weighted sum of the three floats.
// @fnv 0x00b719e0
float ShaderWeightedVector::ComputeWeightedSum()
{
    return y * DAT_010ae8c0 + x * DAT_010ae8b8 + z * DAT_010ae8b0;
}

struct StageReturn
{
    int m_iObjectReferenceCount;
    void ReturnToPool();
};

struct FUN_00b71b70_class
{
    StageReturn* m_stage;
    void ReleaseStage();
};

// @fnv 0x00b71b70
void FUN_00b71b70_class::ReleaseStage()
{
    StageReturn* stage = m_stage;
    if (stage)
    {
        if (--(*(int*)((char*)stage + 0x60)) == 0)
            stage->ReturnToPool();
    }
}

extern int DAT_0126f74c;
extern int DAT_011f95e4;

// @fnv 0x00b7c150
void __stdcall SetEntryField(int aiIndex)
{
    int* base = (int*)DAT_0126f74c;
    int* p = (int*)base[0x24 / 4];
    *(int*)((char*)p[aiIndex] + 8) = DAT_011f95e4;
}

void __cdecl UpdateFogShaderConstants();

struct FUN_00b7deb0_class
{
    void UpdateSpawnedObjectFlags();
    void ShadowLightShader_SetupPassOpt_AmbientLight();
    void ShadowLightShader_SetupPassOpt_LightColor();
    void ShadowLightShader_SetupPass_ADT4_Opt();
};

// @fnv 0x00b7deb0
// src: COMMUNITY 0x00b7deb0
void __thiscall FUN_00b7deb0_class::ShadowLightShader_SetupPass_ADT4_Opt()
{
    UpdateFogShaderConstants();
    UpdateSpawnedObjectFlags();
    ShadowLightShader_SetupPassOpt_AmbientLight();
    ShadowLightShader_SetupPassOpt_LightColor();
}

struct NiObjectNET_stub
{
    void NiObjectNET_PostLinkObject(int);
};
struct FUN_00b6f4f0_class
{
    int m_0x64;
    NiTexture* m_tex;
    void SetTextureByName(int a);
};
// Calls FUN_00a5c6a0 with a, then if the name at offset 0x64 is set, looks up that texture via BSShaderManager::GetTexture into the pointer at 0x60.
// @fnv 0x00b6f4f0
void FUN_00b6f4f0_class::SetTextureByName(int a)
{
    ((NiObjectNET_stub*)this)->NiObjectNET_PostLinkObject(a);
    if (*(int*)((char*)this + 0x64))
        BSShaderManager::GetTexture((const char*)*(int*)((char*)this + 0x64), true, *(NiTexture**)((char*)this + 0x60),
                                    false, false);
}

extern unsigned char DAT_011f9427;
extern unsigned char DAT_011f91d8;
extern int DAT_011f95e4;
extern int _fnv_particle_shader_renderer_level;

// Returns 1 when DAT_011f9427 is 0, DAT_011f95e4 is nonzero, DAT_011f91d8 has bit 0x20 set, and _fnv_particle_shader_renderer_level is at least 2; otherwise 0.
// @fnv 0x00b60330
int __cdecl IsParticleShaderRendererEnabled()
{
    if (DAT_011f9427 == 0 && DAT_011f95e4 != 0 && (DAT_011f91d8 & 0x20) && _fnv_particle_shader_renderer_level >= 2)
        return 1;
    return 0;
}

// @fnv 0x00b603d0
// src: GUESS 0x00b603d0 (confidence: low)
void* __cdecl Runtime_ForwardCall_00b603d0()
{
    return g_memoryManager.Allocate(0xc);
}

struct NiFreeAliasStub
{
    void NiFree(void*);
};
// @fnv 0x00b605a0
OwnerMapBase* __fastcall DestroyOwnerMapBase(OwnerMapBase* self, void*, int flags)
{
    self->OwnerMapBase::~NiTMapBase();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

// @fnv 0x00b60d70
// src: COMMUNITY 0x00b60d70
void __fastcall TallGrassShaderProperty_SetClampNI(void* self, int, int value)
{
    *(int*)((char*)self + 0x90) = value;
}

extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
struct NiTAbstractPoolAllocator_unsigned_int
{
    struct LinkedListEntry
    {
        void* m_pkNext;
        void* m_pkPrev;
        int m_uiSize;
    };
    static LinkedListEntry* ms_pFreeList;
};
// @fnv 0x00b63df0
void __stdcall FreePoolNode(void* p)
{
    NiTAbstractPoolAllocator_unsigned_int::LinkedListEntry* n = (NiTAbstractPoolAllocator_unsigned_int::LinkedListEntry*)p;
    *(unsigned char*)((char*)n + 8) = 0;
    g_011c5f80.Lock(0);
    n->m_pkPrev = 0;
    n->m_pkNext = NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList;
    --DAT_011c5f84;
    NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList = n;
    if (!DAT_011c5f84)
        *(unsigned int*)&g_011c5f80 = 0;
}

extern int DAT_011ff9f0;
struct AccumWIP
{
    void __thiscall RenderPassGroup(int a, int b, bool c, int d);
};
// @fnv 0x00b64530
// src: COMMUNITY 0x00b64530
void __cdecl BSShaderAccumulator_FinishAccumulating_WaterDepth(AccumWIP* self)
{
    if (reinterpret_cast<int*>(self)[2])
    {
        BSRenderStateManager_blk_00b60000_o2::SetDepthBufferEnabled(false, 1);
        self->RenderPassGroup(0x2d8, 0x2ef, false, -1);
        --DAT_011ff9f0;
        BSRenderStateManager_blk_00b60000_o2::SetDepthBufferEnabled(false, 0);
    }
}

extern void(__cdecl* DAT_011f9f40[])(void*);
void __cdecl BSShaderAccumulator_FinishAccumulating_Standard_PreResolveDepth(void*);

// @fnv 0x00b66520
void ShaderAccumulatorLocal::ApplyRenderMode()
{
    BSShaderManager::SetRenderMode(eRenderMode);
    if (!*(int*)((char*)this + 0x19c))
    {
        BSShaderAccumulator_FinishAccumulating_Standard_PreResolveDepth(this);
        return;
    }
    if (DAT_011f9f40[*(unsigned int*)((char*)this + 0x19c)])
    {
        DAT_011f9f40[*(unsigned int*)((char*)this + 0x19c)](this);
        return;
    }
    DAT_011f9f40[0](this);
}

bool __stdcall BSShaderLightingProperty_IsEqual(void*);
// @fnv 0x00b665c0
// src: XBOX_PDB 0x00b665c0
char __stdcall BSShaderPPLightingProperty_IsEqual(int a)
{
    BSShaderLightingProperty_IsEqual((void*)a);
    return 0;
}

struct FUN_00b6f460_class
{
    void BSShaderLightingProperty_LinkObject(NiStream* s);
    void LoadAndSetAdditional(NiStream* kStream);
};
// @fnv 0x00b66780
void FUN_00b6f460_class::LoadAndSetAdditional(NiStream* kStream)
{
    BSShaderLightingProperty_LinkObject(kStream);
    NiObject* pkAdditional = (NiObject*)kStream->GetLoadedObject();
    NiObject* old = *(NiObject**)((char*)this + 0xa4);
    if (old != pkAdditional)
    {
        if (old)
        {
            if (InterlockedDecrement((volatile long*)((char*)old + 4)) == 0)
                old->DeleteThis();
        }
        *(NiObject**)((char*)this + 0xa4) = pkAdditional;
        if (pkAdditional)
            InterlockedIncrement((volatile long*)((char*)pkAdditional + 4));
    }
}

extern "C" void* __cdecl memmove(void* dst, const void* src, unsigned int n);
struct FUN_00b71ad0_class
{
    void CopySourceData(const void* src);
};
// Copies 0x60 bytes from src into this+0x1a8 and sets the flag at this+0x208 to 1, or clears that flag when src is null.
// @fnv 0x00b71ad0
void __thiscall FUN_00b71ad0_class::CopySourceData(const void* src)
{
    if (src)
    {
        memmove((char*)this + 0x1a8, src, 0x60);
        ((char*)this)[0x208] = 1;
    }
    else
        ((char*)this)[0x208] = 0;
}

struct FUN_00b7b930_Matrix
{
    float m[4][4];
};


struct FUN_00b7b930_Entry
{
    int pad0;
    int pad4;
    bool bEnabled;
};
struct FUN_00b7b930_Target
{
    char pad[0x1c];
    int iIndex;
};
struct FUN_00b7b930_Arg
{
    char pad[0xc];
    FUN_00b7b930_Target* pTarget;
};
struct FUN_00b7b930_Ctx
{
    char pad[0x194];
    int iValue;
};

FUN_00b7b930_Ctx* __cdecl BSShaderManager_GetAccumulator();
extern FUN_00b7b930_Entry* DAT_011febe4;
extern NiPoint3 DAT_011f474c;
extern FUN_00b7b930_Matrix DAT_011fd968;

// If the entry is enabled, the target is valid and the context value is nonzero, writes a world or identity-offset matrix into DAT_011fd968.
// @fnv 0x00b7b930
void __stdcall UpdateWorldMatrix(FUN_00b7b930_Arg* pkArg, int iIdentity, const NiTransform* pkWorld)
{
    if (!DAT_011febe4->bEnabled)
        return;
    if (!pkArg->pTarget || pkArg->pTarget->iIndex == -1)
        return;
    if (!BSShaderManager_GetAccumulator()->iValue)
        return;
    FUN_00b7b930_Matrix kMat;
    if (!iIdentity)
    {
        kMat.m[0][0] = pkWorld->m_Rotate.m_pEntry[0][0];
        kMat.m[0][1] = pkWorld->m_Rotate.m_pEntry[0][1];
        kMat.m[0][2] = pkWorld->m_Rotate.m_pEntry[0][2];
        kMat.m[0][3] = pkWorld->m_Translate.x;
        kMat.m[1][0] = pkWorld->m_Rotate.m_pEntry[1][0];
        kMat.m[1][1] = pkWorld->m_Rotate.m_pEntry[1][1];
        kMat.m[1][2] = pkWorld->m_Rotate.m_pEntry[1][2];
        kMat.m[1][3] = pkWorld->m_Translate.y;
        kMat.m[2][0] = pkWorld->m_Rotate.m_pEntry[2][0];
        kMat.m[2][1] = pkWorld->m_Rotate.m_pEntry[2][1];
        kMat.m[2][2] = pkWorld->m_Rotate.m_pEntry[2][2];
        kMat.m[2][3] = pkWorld->m_Translate.z;
        kMat.m[3][0] = 0.0f;
        kMat.m[3][1] = 0.0f;
        kMat.m[3][2] = 0.0f;
        kMat.m[3][3] = pkWorld->m_fScale;
        DAT_011fd968 = kMat;
    }
    else
    {
        NiPoint3 kAdjust;
        memcpy(&kAdjust, &DAT_011f474c, sizeof(kAdjust));
        kMat.m[0][0] = 1.0f;
        kMat.m[0][1] = 0.0f;
        kMat.m[0][2] = 0.0f;
        kMat.m[0][3] = kAdjust.x;
        kMat.m[1][0] = 0.0f;
        kMat.m[1][1] = 1.0f;
        kMat.m[1][2] = 0.0f;
        kMat.m[1][3] = kAdjust.y;
        kMat.m[2][0] = 0.0f;
        kMat.m[2][1] = 0.0f;
        kMat.m[2][2] = 1.0f;
        kMat.m[2][3] = kAdjust.z;
        kMat.m[3][0] = 0.0f;
        kMat.m[3][1] = 0.0f;
        kMat.m[3][2] = 0.0f;
        kMat.m[3][3] = 1.0f;
        DAT_011fd968 = kMat;
    }
}

struct _Base_00441d20
{
    ~_Base_00441d20();
};
struct FUN_00b606f0_class : _Base_00441d20
{
    char _00[0x31 - sizeof(_Base_00441d20)];
    BSStream _30;
    ~FUN_00b606f0_class();
};
// Destroys the embedded BSStream member and the base object.
// @fnv 0x00b606f0
FUN_00b606f0_class::~FUN_00b606f0_class()
{}

// Iterates the shader entries at this+0x174 up to the count at this+0x18c, calling HasListedItemInRange on each until one returns true.
// @fnv 0x00b63120
// src: COMMUNITY 0x00b63120
void BSShaderAccumulator::GetWaterRefractionPassWithinRange(unsigned int auiArg, int aiArg)
{
    unsigned int i = 0;
    bool cVar1 = false;
    if (*(unsigned int*)((char*)this + 0x18c) > i)
    {
        BSShaderAccumulator** ppEntry = (BSShaderAccumulator**)((char*)this + 0x174);
        do
        {
            if (cVar1)
                break;
            cVar1 = (*ppEntry)->HasListedItemInRange(auiArg, aiArg);
            ++i;
            ++ppEntry;
        } while (i < *(unsigned int*)((char*)this + 0x18c));
    }
}

struct GraphicsRenderer
{
    bool __thiscall BeginUsingRenderTargetGroup(void* pGroup, unsigned int a);
};

extern int DAT_011fa020;
void __cdecl BSRenderedTexture_Pop();
int __cdecl GetCurrentItem();

// @fnv 0x00b6b840
// src: COMMUNITY 0x00b6b840
void BSRenderedTexture_End()
{
    if (DAT_011fa020 != 0)
    {
        NiRenderer::ms_pRenderer->TryUnlock();
        BSRenderedTexture_Pop();
        int r = GetCurrentItem();
        if (r == 0)
        {
            NiRenderer* p = NiRenderer::ms_pRenderer;
            r = (*(int(__thiscall**)(NiRenderer*))(*(int*)p + 0xc8))(p);
        }
        ((GraphicsRenderer*)NiRenderer::ms_pRenderer)->BeginUsingRenderTargetGroup((void*)r, 0);
    }
}

// @fnv 0x00b605e0
CachedGeometryMapBase* __fastcall DestroyCachedGeometryMapBase(CachedGeometryMapBase* self, void*, int flags)
{
    self->CachedGeometryMapBase::~NiTMapBase();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

extern MemoryManager g_memoryManager;
struct FUN_00b60c90_class : FUN_00b606f0_class
{
    FUN_00b60c90_class* __thiscall FUN_00b60c90(int flags);
};
// Runs the base class destructor, frees this via g_memoryManager when flags has bit 0 set, and returns this.
// @fnv 0x00b60c90
FUN_00b60c90_class* FUN_00b60c90_class::FUN_00b60c90(int flags)
{
    this->FUN_00b606f0_class::~FUN_00b606f0_class();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

void __cdecl FUN_00b60b50();
struct FUN_00b60f30_class
{
    FUN_00b60f30_class* __thiscall FUN_00b60f30(int flags);
};
// Calls FUN_00b60b50, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00b60f30
FUN_00b60f30_class* __thiscall FUN_00b60f30_class::FUN_00b60f30(int flags)
{
    FUN_00b60b50();
    if (flags & 1)
        operator delete(this, 0x38);
    return this;
}


// Iterates the renderer pointers stored at this+0x174 up to the count at this+0x18c and calls ClearAllGroups(0) on each.
// @fnv 0x00b630c0
// src: COMMUNITY 0x00b630c0
void ShaderAccumulatorLocal::BSShaderAccumulator_ClearBloodSplatter()
{
    unsigned int i;
    for (i = 0; i < *(unsigned int*)((char*)this + 0x18c); i++)
    {
        ((BSBatchRenderer*)*(void**)((char*)this + 0x174 + i * 4))->ClearAllGroups(0);
    }
}

// @fnv 0x00b63b90
// src: COMMUNITY 0x00b63b90
void ShaderAccumulatorLocal::BSShaderAccumulator_ClearGroupPasses(unsigned int uiGeometryGroupIndex)
{
    for (unsigned int i = 0; i < uiBatchRendererCount; ++i)
        ((BSBatchRenderer::PassTextureSlots*)pBatchRenderer[i]->pGeometryGroupsA[uiGeometryGroupIndex])->ClearPassTextureSlots();
}


// @fnv 0x00b63e70
NiTPointerMap<NiAVObject*, bool>* __fastcall DestroyRoomMap(NiTPointerMap<NiAVObject*, bool>* self, void*, bool bDelete)
{
    self->NiTPointerMap<NiAVObject*, bool>::~NiTPointerMap();
    if ((unsigned char)bDelete & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

void __cdecl ProcessCommands(void* a, void* b, void* c, void* d, void* e);

// @fnv 0x00b64490
// src: COMMUNITY 0x00b64490
bool __cdecl BSShaderAccumulator_RegisterObject_ConstAlpha(void* a, void* b, void* c, void* d, void* e)
{
    if (*(int*)((char*)e + 0x68) == 0x16)
        return true;
    ProcessCommands(a, b, c, d, e);
}

extern int DAT_010ae0c0;
extern long volatile DAT_011f4400;
extern MemoryManager _g_memoryManager;
extern int vftable_NiRefObject;
extern void(__stdcall* DAT_00fdf1c4)(void*);

struct FUN_00b66850_class
{
    void ReleaseStorage_00b66850();
};

// @fnv 0x00b66850
// src: GUESS 0x00b66850 (confidence: low)
void FUN_00b66850_class::ReleaseStorage_00b66850()
{
    char* p = (char*)this;
    *(int*)p = (int)&DAT_010ae0c0;
    if (p[8] && *(void**)(p + 0xc))
        _g_memoryManager.Deallocate(*(void**)(p + 0xc));
    *(void**)(p + 0xc) = 0;
    if (p[8] && *(void**)(p + 0x10))
        _g_memoryManager.Deallocate(*(void**)(p + 0x10));
    *(void**)(p + 0x10) = 0;
    *(int*)p = (int)&vftable_NiRefObject;
    DAT_00fdf1c4((void*)&DAT_011f4400);
}


extern void* g_011fa018;

char* _FUN_00a7d330(void* p);

void __stdcall WriteToSettingArray(StrArr* arr);

// Appends the string returned by _FUN_00a7d330(g_011fa018) to arr, growing arr to idx plus the growth value when idx reaches capacity.
// @fnv 0x00b6a670
// src: XBOX_PDB 0x00b6a670
void __stdcall WaterShaderProperty_GetViewerStrings(StrArr* pStrArr)
{
    WriteToSettingArray(pStrArr);
    char* p = _FUN_00a7d330(g_011fa018);
    unsigned int idx = *(unsigned short*)((char*)pStrArr + 0xa);
    unsigned int uiCapacity = *(unsigned short*)((char*)pStrArr + 8);
    if (idx >= uiCapacity)
    {
        unsigned int grow = *(unsigned short*)((char*)pStrArr + 0xe);
        pStrArr->SetSize(grow + idx);
    }
    pStrArr->SetAt(idx, p);
}

extern int DAT_011fa020;
extern int* DAT_011fa024[10];

// @fnv 0x00b6b050
void PushRefCountedSlot(int* pObject)
{
    if ((unsigned int)DAT_011fa020 < 10)
    {
        int** slot = &DAT_011fa024[DAT_011fa020];
        int* old = *slot;
        if (old != pObject)
        {
            if (old != 0)
            {
                if (InterlockedDecrement((long*)old + 1) == 0)
                {
                    (*(void(__thiscall**)(int*))(*(int*)old + 4))(old);
                }
            }
            *slot = pObject;
            if (pObject != 0)
            {
                InterlockedIncrement((long*)pObject + 1);
            }
        }
        DAT_011fa020++;
    }
}

struct FUN_00b6f520_class
{
    char pad_00[0x60];
    int m_0x60;

    void BSShaderNoLightingProperty_PrecacheTextures();
};

// @fnv 0x00b6f520
// src: XBOX_PDB 0x00b6f520
void FUN_00b6f520_class::BSShaderNoLightingProperty_PrecacheTextures()
{
    int value = m_0x60;
    if (value != 0)
    {
        typedef void (__thiscall* SetState)(NiRenderer*, int, int, int);
        NiRenderer* renderer = NiRenderer::ms_pRenderer;
        ((SetState*)*(void**)renderer)[0x38](renderer, value, 0, 0);
    }
}

extern void* g_011fa05c;
// @fnv 0x00b6fd00
// src: XBOX_PDB 0x00b6fd00
void* __cdecl BSShaderNoLightingProperty_GetRTTI()
{
    return &g_011fa05c;
}

// Slot 56 is consumed as a full-width render state in these call sites.
// The shared IsShaderValid declaration returns bool, so preserve the ABI here.
static __forceinline unsigned int GetShaderStageState(NiD3DShader* shader)
{
    typedef unsigned int (__thiscall* Getter)(NiD3DShader*);
    return ((Getter*)*(void**)shader)[56](shader);
}

struct BeamStage
{
    void ApplyPairToState(unsigned int);
};


// If both textureStage and shader are non-null, passes the shader's V56() result to textureStage->ApplyPairToState.
// @fnv 0x00b71b10
// src: COMMUNITY 0x00b71b10
void __stdcall ShadowLightShader_SetClampMode(BeamStage* textureStage, NiD3DShader* shader)
{
    if (textureStage != 0 && shader != 0)
    {
        textureStage->ApplyPairToState(GetShaderStageState(shader));
    }
}

struct FUN_00b7ce60_class
{
    void FUN_00b79de0();
    FUN_00b7ce60_class* FUN_00b7ce60(int a);
};
// Calls FUN_00b79de0, frees this with operator delete when bit 0 of a is set, and returns this.
// @fnv 0x00b7ce60
FUN_00b7ce60_class* FUN_00b7ce60_class::FUN_00b7ce60(int aiFlags)
{
    FUN_00b79de0();
    if (aiFlags & 1)
        operator delete(this, 0x8c);
    return this;
}

// variant G: real constructor
struct FUN_00b600e0_cls
{
    int m_i0;
    int m_i4;
    float m_f8;
    float m_fC;
    float m_f10;
    float m_f14;
    float m_f18;
    FUN_00b600e0_cls();
};

// @fnv 0x00b600e0
FUN_00b600e0_cls::FUN_00b600e0_cls()
{
    m_f8 = 0.0f;
    m_i0 = 0;
    m_fC = 0.0f;
    m_f10 = 0.0f;
    m_f14 = 0.0f;
    m_f18 = 1.0f;
}

struct FUN_00b60100_cls
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
    int m_90;
    void TallGrassShaderProperty_SetClampD3D(int value);
};

// @fnv 0x00b60100
// src: COMMUNITY 0x00b60100
void FUN_00b60100_cls::TallGrassShaderProperty_SetClampD3D(int value)
{
    m_90 = (value != 3) ? 3 : 0;
}

extern float DAT_011fd890;

// Returns the float value stored at DAT_011fd890 converted to an unsigned int.
// @fnv 0x00b60170
unsigned int __cdecl GetGlobalFloatAsUInt()
{
    return (unsigned int)DAT_011fd890;
}

// Reconstruction of FUN_00b60280.
//
// `this` owns a single pointer at offset 0.  Replacing it releases the old
// object first: the reference counter that lives at +8 of the old object is
// decremented and, when it drops to zero, the old object is destroyed - the
// deleting destructor is reached through vtable slot 0 with the deleting flag
// 1 pushed.  Afterwards the new pointer is stored at +0 and, when it is not
// null, its own counter at +8 is incremented.
//
// The two null tests on the old pointer are not redundant in the source: the
// outer one tests the member, the inner one is the null check that the delete
// operator performs on the pointer it is given.  The inner check survives
// because the pointer handed to `delete` is a second, independent copy of the
// member taken inside the guarded block, so the compiler does not carry the
// "known non-null" fact of the member test over to it.

struct FnvB60280Ref
{
    virtual ~FnvB60280Ref();
    int m_iWordAt04;
    long m_ref;
};


// Releases the current reference if different, then stores pNew and increments its ref count.
// @fnv 0x00b60280
// This reference target has its count at +8 and releases via virtual delete.
// 0x00b60280 therefore specialises the shared pointer's assignment operation.
template <> NiPointer<FnvB60280Ref>& NiPointer<FnvB60280Ref>::operator=(FnvB60280Ref* pNew)
{
    if (m_pObject == pNew)
        return *this;
    if (m_pObject)
    {
        FnvB60280Ref* q = m_pObject;
        if (InterlockedDecrement(&q->m_ref) == 0)
            delete q;
    }
    m_pObject = pNew;
    if (pNew)
        InterlockedIncrement(&pNew->m_ref);
    return *this;
}

extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
void* __cdecl _NiMalloc_00aa1070(unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);


struct AssignedString
{
    int unk00;
    char* text;
    NiPointer<NiRefObject> object;
};

struct FUN_00b604b0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool copyText;
    void AssignString(AssignedString* out, const char* input, NiPointer<NiRefObject> ref);
};

// Copies or aliases input into out->text depending on copyText, then assigns ref to out->object.
// @fnv 0x00b604b0
void FUN_00b604b0_class::AssignString(AssignedString* out, const char* input, NiPointer<NiRefObject> ref)
{
    if (copyText)
    {
        unsigned int length = strlen(input) + 1;
        char* buffer = static_cast<char*>(_NiMalloc_00aa1070(length));
        out->text = buffer;
        strcpy_s(buffer, length, input);
    }
    else
    {
        out->text = const_cast<char*>(input);
    }
    out->object = ref;
}

// FUN_00b60750 - a __thiscall member that hands a block over to its caller
// and releases it again.
//
// The original reads two members of the object:
//   this+0x250 : a pointer to a pointer - the block that is handed out
//   this+0x258 : a flag - when it is clear, nothing is handed out
//
// and then does, in this exact order:
//   push ecx                                   ; frame slot for the scratch flag
//   cmp dword ptr [ecx+0x258], 0
//   mov dword ptr [esp], 0                     ; scratch flag = 0
//   je  <null>
//   mov eax, dword ptr [ecx+0x250]
//   mov eax, dword ptr [eax]
//   jmp <join>
// <null>: xor eax, eax
// <join>: push esi / mov esi,[esp+0xc]         ; the out parameter
//   mov dword ptr [esi], eax                   ; publish the block
//   test eax, eax / je <done>
//   add eax, 4 / push eax
//   call dword ptr [0x00fdf1c0]                ; the engine's deallocator
// <done>: mov eax, esi / pop esi / pop ecx / ret 4
//
// The deallocator is the global function pointer DAT_00fdf1c0 - a __stdcall
// pointer with one void* argument - so the block is released as (block + 4).
//
// The scratch flag is a volatile int that the original only ever reads in a
// branch that is never taken, so the store of its zero value survives while
// the read itself disappears.  Writing it as an unreachable use keeps that
// shape: the local is referenced (so the compiler keeps the frame slot) but
// the reference is in code the optimiser deletes (so no load is emitted).

struct FUN_00b60750_owner
{
    char padding[0x250];
    void* unk250;  // +0x250
    char pad254[4];
    int unk258;  // +0x258
    void* GrassLoadTask_GetObject(void* pOut);
};

extern void(__stdcall* DAT_00fdf1c0)(void*);

// Stores the block pointer from unk250 (or null if unk258 is zero) into pOut and calls DAT_00fdf1c0 on block+4 when non-null.
// @fnv 0x00b60750
// src: COMMUNITY 0x00b60750
void* FUN_00b60750_owner::GrassLoadTask_GetObject(void* pOut)
{
    volatile int unused = 0;
    if (0)
    {
        if (unused)
        {
        }
    }

    void* block;
    if (unk258)
    {
        block = *(void**)unk250;
    }
    else
    {
        block = 0;
    }

    *(void**)pOut = block;
    if (block)
    {
        DAT_00fdf1c0((char*)block + 4);
    }
    return pOut;
}

struct B60A50CloningProcess;

class B60A50Base
{
  public:
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
    int m_iFlags;

    void CopyMemberData(B60A50Base* pkDest, B60A50CloningProcess& kCloning);
};

class B60A50Effect : public B60A50Base
{
  public:
    NiPointer<NiRefObject> m_spTexture;
    NiPointer<NiRefObject> m_spPalette;
    int unk88;
    int unk8C;
    int m_iTextureClamp;
    int m_iTextureFilter;

    void CloneTo(B60A50Effect* pkDest, B60A50CloningProcess& kCloning);
};

// @fnv 0x00b60a50
void B60A50Effect::CloneTo(B60A50Effect* pkDest, B60A50CloningProcess& kCloning)
{
    B60A50Base::CopyMemberData(pkDest, kCloning);
    pkDest->m_spTexture = m_spTexture;
    pkDest->m_spPalette = m_spPalette;
    pkDest->m_iTextureClamp = m_iTextureClamp;
    pkDest->m_iTextureFilter = m_iTextureFilter;
    pkDest->m_iFlags = m_iFlags;
}

extern int g_unk011f9f00;

// @fnv 0x00b60d60
// src: COMMUNITY 0x00b60d60
int* __cdecl TallGrassShaderProperty_GetRTTI()
{
    return &g_unk011f9f00;
}

// @fnv 0x00b63070
// src: XBOX_PDB 0x00b63070
void ShaderAccumulatorLocal::BSShaderAccumulator_FinishAccumulating()
{
    PreparePasses();
    FinishPasses();
}

// SumItemSubValues: sums a 16-bit value over the array elements at this+0x174.
// Count at +0x18c. Pairs (even, odd) are summed separately; an odd tail element
// is added last.


class FUN_00b63a90_Sub
{
  public:
    unsigned short unk00;
    unsigned short m_usValue;
};

// Sums m_usValue of each item's m_pSub over m_items[0..m_uiCount-1] and returns the total.
// @fnv 0x00b63a90
int ShaderAccumulatorLocal::SumItemSubValues()
{
    int count = (int)uiBatchRendererCount;
    unsigned int tail = 0;
    unsigned int sumA = 0;
    unsigned int sumB = 0;
    unsigned int idx = 0;
    if (count >= 2)
    {
        unsigned int n = ((unsigned int)count - 2) / 2 + 1;
        BSBatchRenderer** p = &pBatchRenderer[1];
        idx = n * 2;
        do
        {
            sumA += ((FUN_00b63a90_Sub*)(*(p - 1))->pGeometryGroupsA[6])->m_usValue;
            sumB += ((FUN_00b63a90_Sub*)(*p)->pGeometryGroupsA[6])->m_usValue;
            p += 2;
        } while (--n != 0);
    }
    if (idx < (unsigned int)count)
    {
        tail = ((FUN_00b63a90_Sub*)pBatchRenderer[idx]->pGeometryGroupsA[6])->m_usValue;
    }
    return (int)(sumB + sumA + tail);
}

struct PoolAllocator_b8522
{
    void* Game_DoHeapAlloc(unsigned int size);
};
extern char DAT_011f6238;

struct FUN_00b63bf0_cls
{
    unsigned short item;
    FUN_00b63bf0_cls* next;
    void AppendItem(const unsigned short* src);
};

// Walks to the last node of the list and appends a new node holding *src, or sets the last node's item if it is empty; returns early when *src is 0.
// @fnv 0x00b63bf0
void FUN_00b63bf0_cls::AppendItem(const unsigned short* src)
{
    unsigned short value = *src;
    if (value == 0)
        return;

    FUN_00b63bf0_cls* cur = this;
    if (this->next != 0)
    {
        FUN_00b63bf0_cls** ppLink = &this->next;
        do
        {
            cur = *ppLink;
            ppLink = &cur->next;
        } while (cur->next != 0);
    }

    if (cur->item != 0)
    {
        FUN_00b63bf0_cls* n = (FUN_00b63bf0_cls*)reinterpret_cast<PoolAllocator_b8522*>(&DAT_011f6238)->Game_DoHeapAlloc(8);
        if (n != 0)
        {
            n->item = *src;
            n->next = 0;
        }
        else
        {
            n = 0;
        }
        cur->next = n;
        return;
    }
    cur->item = value;
}

// @fnv 0x00b63e30
RoomMapBase* __fastcall DestroyRoomMapBase(RoomMapBase* self, void*, unsigned int flags)
{
    self->RoomMapBase::~NiTMapBase();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

struct B666D0Target
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void SetEntry(unsigned int uiIndex, void* pvEntry);
};

class B666D0Source
{
  public:
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
    void* m_apvEntries[6];

    void CopyEntriesToTarget(B666D0Target* pkTarget);
};

// Copies the six entries of m_apvEntries into the target via SetEntry.
// @fnv 0x00b666d0
void B666D0Source::CopyEntriesToTarget(B666D0Target* pkTarget)
{
    for (unsigned int i = 0; i < 6; i++)
        pkTarget->SetEntry(i, m_apvEntries[i]);
}

// Decompilation of CheckAndNotify (0x00b667e0, 48 bytes)
//
// bool CheckAndNotify(int a)
//   if (!FUN_00bc3770(a)) return false;
//   if (this->m_pFlagTarget) this->m_pFlagTarget->v21(a);
//   return true;

struct DecompTarget
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
    virtual void v21(int a);
};

struct DecompOwner
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
    DecompTarget* m_pFlagTarget;
    bool CheckAndNotify(int a);
};

bool __stdcall BSShaderLightingProperty_RegisterStreamables(int a);

// Calls FUN_00bc3770(a); if it succeeds, invokes v21(a) on the stored target pointer when non-null and returns true, otherwise false.
// @fnv 0x00b667e0
bool DecompOwner::CheckAndNotify(int aiValue)
{
    if (!BSShaderLightingProperty_RegisterStreamables(aiValue))
        return false;
    DecompTarget* pTarget = this->m_pFlagTarget;
    if (pTarget != 0)
        pTarget->v21(aiValue);
    return true;
}

extern volatile long DAT_011f4400;

struct S_00b669f0_Base
{
    virtual void v0();
    int unk04;
    ~S_00b669f0_Base()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
};

struct FUN_00b669f0 : S_00b669f0_Base
{
    NiPointer<NiRefObject> m_08;
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
    NiPointer<NiRefObject> m_6c;
    ~FUN_00b669f0();
};

// Destructor that clears the two NiPointer reference holders m_08 and m_6c, releasing their references.
// @fnv 0x00b669f0
FUN_00b669f0::~FUN_00b669f0()
{
    m_08 = 0;
    m_6c = 0;
}

class RenderPassB66
{
  public:
    RenderPassB66(void* pvOwner, int iType, ...);

    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }

    int unk00, unk04, unk08, unk0C;
};

class ShaderPropertyB66
{
  public:
    RenderPassB66* GetOrCreateRenderPass(void* pvOwner);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int m_uiValue1;
    int unk024, unk028, unk02C, unk030, unk034, unk038, unk03C, unk040;
    int unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060;
    int unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080;
    int unk084, unk088, unk08C, unk090, unk094, unk098, unk09C, unk0A0;
    int unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0;
    int unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0;
    int unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    RenderPassB66* m_pRenderPass;
};

// @fnv 0x00b66e20
RenderPassB66* ShaderPropertyB66::GetOrCreateRenderPass(void* pvOwner)
{
    if (!m_pRenderPass)
    {
        if ((m_uiValue1 & 2) > 0)
            m_pRenderPass = new RenderPassB66(pvOwner, 0x1e8, 1, 0, 0);
        else if ((m_uiValue1 & 0x1000) > 0)
            m_pRenderPass = new RenderPassB66(pvOwner, 0x1e9, 1, 0, 0);
        else
            m_pRenderPass = new RenderPassB66(pvOwner, 0x1e7, 1, 0, 0);
    }
    return m_pRenderPass;
}


extern NiRTTI DAT_011f444c;
extern NiRTTI DAT_011f4ac4;

inline bool IsObjectKindOf(const NiRTTI* pkRTTI, NiObject* pkObj)
{
    if (!pkObj)
        return false;
    for (const NiRTTI* p = pkObj->GetRTTI(); p; p = p->m_pBaseRTTI)
    {
        if (p == pkRTTI)
            return true;
    }
    return false;
}

struct TextureReceiver
{
    NiObject* BSRenderedTexture_GetTexture(int a);
};

typedef void(__cdecl* ObjectVisitFn)(NiObject* pkObj, int iUnk, void* pvData);

struct VisitOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    NiObject* m_pkObj;
    TextureReceiver* m_pkRecv0;
    TextureReceiver* m_pkRecv1;
    TextureReceiver* m_pkRecv2;
    TextureReceiver* m_pkRecv3;
    void VisitObjects(ObjectVisitFn pfnVisit, void* pvData);
};

// Calls pfnVisit on m_pkObj and on the object returned by FUN_004bc320(0) for each of m_pkRecv0..m_pkRecv3 when present.
// @fnv 0x00b69e10
void VisitOwner::VisitObjects(ObjectVisitFn pfnVisit, void* pvData)
{
    if (m_pkObj)
    {
        if (!IsObjectKindOf(&DAT_011f444c, m_pkObj))
            IsObjectKindOf(&DAT_011f4ac4, m_pkObj);
        pfnVisit(m_pkObj, 0, pvData);
    }
    if (m_pkRecv0 && m_pkRecv0->BSRenderedTexture_GetTexture(0))
    {
        NiObject* p = m_pkRecv0->BSRenderedTexture_GetTexture(0);
        pfnVisit(p, 0, pvData);
    }
    if (m_pkRecv1 && m_pkRecv1->BSRenderedTexture_GetTexture(0))
    {
        NiObject* p = m_pkRecv1->BSRenderedTexture_GetTexture(0);
        pfnVisit(p, 0, pvData);
    }
    if (m_pkRecv2 && m_pkRecv2->BSRenderedTexture_GetTexture(0))
    {
        NiObject* p = m_pkRecv2->BSRenderedTexture_GetTexture(0);
        pfnVisit(p, 0, pvData);
    }
    if (m_pkRecv3 && m_pkRecv3->BSRenderedTexture_GetTexture(0))
    {
        NiObject* p = m_pkRecv3->BSRenderedTexture_GetTexture(0);
        pfnVisit(p, 0, pvData);
    }
}

extern unsigned char DAT_011ad86e;
extern bool DAT_011ff104;
extern unsigned char DAT_011ff101;

extern __declspec(thread) int g_tlsMemContext;

struct TlsGuard
{
    int saved;
    TlsGuard()
    {
        saved = g_tlsMemContext;
        g_tlsMemContext = 0x1d;
    }
    ~TlsGuard()
    {
        g_tlsMemContext = saved;
    }
};

struct FlagSlot
{
    char unk00[3];
    unsigned char flag;
};

struct Obj3c
{
    char unk00[0x10];
    int m_10;
    void FUN_00ba9ee0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

struct ArgQ
{
    char unk00[0x28];
    int m_28;
};
struct ArgP
{
    char unk00[0xb8];
    ArgQ* m_b8;
};

struct Ret30
{
    int m_iWordAt00;
    unsigned short m_iWordAt04;
};

struct ThisCls
{
    char unk00[0x3c];
    Obj3c* m_3c;
    char unk40[0x60 - 0x40];
    unsigned char m_60;
    unsigned char m_61;
    char unk62;
    unsigned char m_63;
    char unk64[0x7e - 0x64];
    unsigned char m_7e;
    char unk7f;
    unsigned char m_80;
    unsigned char m_81;
    char unk82;
    unsigned char m_83;
    char unk84[0x130 - 0x84];
    int m_130;
    void FUN_00ba95e0(int a);
    Ret30* WaterShaderProperty_GetWaterPass(ArgP* p);
    Obj3c* WaterShaderProperty_GetRenderPasses(ArgP* p, int a2, int a3, int a4, int a5, int a6);
};

// @fnv 0x00b69ff0
// src: XBOX_PDB 0x00b69ff0
Obj3c* ThisCls::WaterShaderProperty_GetRenderPasses(ArgP* p, int a2, int a3, int a4, int a5, int a6)
{
    TlsGuard guard;
    FlagSlot flagSlot;
    if (DAT_011ad86e == 0)
    {
        return 0;
    }
    flagSlot.flag = 0;
    if (p->m_b8->m_28 != 0)
        flagSlot.flag = 1;
    if ((unsigned char)DAT_011ff104 != m_7e)
    {
        if (m_3c)
        {
            m_3c->m_10 = 0;
        }
        m_7e = DAT_011ff104;
    }
    FUN_00ba95e0(-1);
    if (m_3c->m_10 == 0)
    {
        int code;
        if (m_7e != 0)
        {
            code = 0x2bd;
        }
        else if (flagSlot.flag)
        {
            if (m_60 != 0)
            {
                if (DAT_011ff101 != 0)
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2a6 : 0x2aa;
                        else
                            code = m_63 ? 0x2a4 : 0x2a8;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2a5 : 0x2a9;
                        else
                            code = m_63 ? 0x2a3 : 0x2a7;
                    }
                }
                else
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x29e : 0x2a2;
                        else
                            code = m_63 ? 0x29c : 0x2a0;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x29d : 0x2a1;
                        else
                            code = m_63 ? 0x29b : 0x29f;
                    }
                }
            }
            else if (m_61 != 0)
            {
                code = m_80 ? 0x23f : 0x240;
            }
            else
            {
                if (DAT_011ff101 != 0)
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2c3 : 0x2cb;
                        else
                            code = m_63 ? 0x2c5 : 0x2cd;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2c4 : 0x2cc;
                        else
                            code = m_63 ? 0x2c2 : 0x2ca;
                    }
                }
                else
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2bf : 0x2c9;
                        else
                            code = m_63 ? 0x2c1 : 0x2c7;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2c0 : 0x2c8;
                        else
                            code = m_63 ? 0x2be : 0x2c6;
                    }
                }
            }
        }
        else
        {
            if (m_60 != 0)
            {
                if (DAT_011ff101 != 0)
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x293 : 0x297;
                        else
                            code = m_63 ? 0x295 : 0x299;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x294 : 0x298;
                        else
                            code = m_63 ? 0x292 : 0x296;
                    }
                }
                else
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x28b : 0x28f;
                        else
                            code = m_63 ? 0x28d : 0x291;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x28c : 0x290;
                        else
                            code = m_63 ? 0x28a : 0x28e;
                    }
                }
            }
            else if (m_61 != 0)
            {
                code = m_80 ? 0x23f : 0x240;
            }
            else
            {
                if (DAT_011ff101 != 0)
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2b1 : 0x2b9;
                        else
                            code = m_63 ? 0x2b3 : 0x2bb;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2b2 : 0x2ba;
                        else
                            code = m_63 ? 0x2b0 : 0x2b8;
                    }
                }
                else
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2ad : 0x2b7;
                        else
                            code = m_63 ? 0x2af : 0x2b5;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2ae : 0x2b6;
                        else
                            code = m_63 ? 0x2ac : 0x2b4;
                    }
                }
            }
        }
        m_3c->FUN_00ba9ee0((int)p, code, 1, 0, 0, 0, 0, 0);
        if (m_60 == 0 && m_61 == 0)
        {
            Ret30* r = WaterShaderProperty_GetWaterPass(p);
            m_3c->FUN_00ba9ee0(r->m_iWordAt00, r->m_iWordAt04, 1, 0, 0, 0, 0, 0);
        }
        if (m_83 != 0 && m_130 != 0)
        {
            if (m_60 != 0)
            {
                if (flagSlot.flag)
                {
                    m_3c->FUN_00ba9ee0((int)p, 0x2ab, 1, 0, 0, 0, 0, 0);
                }
                else
                {
                    m_3c->FUN_00ba9ee0((int)p, 0x29a, 1, 0, 0, 0, 0, 0);
                }
            }
            else
            {
                if (flagSlot.flag)
                {
                    m_3c->FUN_00ba9ee0((int)p, 0x2ce, 1, 0, 0, 0, 0, 0);
                }
                else
                {
                    m_3c->FUN_00ba9ee0((int)p, 0x2bc, 1, 0, 0, 0, 0, 0);
                }
            }
        }
    }
    return m_3c;
}

struct B6Base
{
    virtual ~B6Base();
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
};

struct B6List
{
    void* head;
    void* tail;
    unsigned count;
    void FUN_004ed900() throw();
    ~B6List() throw()
    {
        FUN_004ed900();
    }
};
struct FUN_00b6a520 : B6Base
{
    B6List list;
    NiPointer<NiRefObject> p134, p138, p13c, p140, p144;
    NiRefObject* p148;
    virtual ~FUN_00b6a520();
};
// @fnv 0x00b6a520
FUN_00b6a520::~FUN_00b6a520()
{
    list.FUN_004ed900();
    NiRefObject* p = p148;
    if (p && !InterlockedDecrement((volatile long*)&p->m_uiRefCount))
        p->DeleteThis();
}

extern int DAT_011fa018;

// @fnv 0x00b6a660
// src: XBOX_PDB 0x00b6a660
int* __cdecl WaterShaderProperty_GetRTTI()
{
    return &DAT_011fa018;
}

// @fnv 0x00b6aed0
// Emit the original out-of-line constructor from the shared Gamebryo body.
template NiPointer<NiRefObject>::NiPointer(NiRefObject* pObject);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

class FUN_00b6aef0 : public NiRefObject
{
  public:
    NiPointer<NiD3DPixelShader> m_spPixelShaders[6];
    NiPointer<NiSourceTexture> m_spTex20;
    NiPointer<NiSourceTexture> m_spTex24;
    NiPointer<NiSourceTexture> m_spTex28;
    int unk2c;
    NiPointer<NiNode> m_vshaders[4];
    virtual ~FUN_00b6aef0();
};

// @fnv 0x00b6aef0
FUN_00b6aef0::~FUN_00b6aef0()
{
    unsigned int i;
    for (i = 0; i < 6; i++)
        m_spPixelShaders[i] = 0;
    for (i = 0; i < 4; i++)
        m_vshaders[i] = 0;
}

struct B6B100Stack
{
    int m_iArrayLength;
    NiPointer<NiRefObject> m_aspItems[16];
};

extern B6B100Stack g_kB6B100Stack;

class B6B100Manager
{
  public:
    static NiRefObject* GetCurrentItem();
};

// Returns the item at the top of g_kB6B100Stack, or null when the stack is empty.
// @fnv 0x00b6b100
NiRefObject* B6B100Manager::GetCurrentItem()
{
    return g_kB6B100Stack.m_iArrayLength ? g_kB6B100Stack.m_aspItems[g_kB6B100Stack.m_iArrayLength - 1]
                                   : NiPointer<NiRefObject>(0);
}

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* pkSection);

struct B6B330CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

// Returns false if the object is not locked or cannot be unlocked; otherwise leaves m_kLock, clears m_ucLocked and returns true.
// @fnv 0x00b6b330
__declspec(noinline) bool __fastcall TryUnlockRenderer(NiRenderer* renderer, void*)
{
    if (!((renderer->m_eFrameState == 1 || renderer->m_eFrameState == 2) && renderer->m_bRenderTargetGroupActive == 1))
        return false;
    typedef bool (__thiscall* CanUnlock)(NiRenderer*);
    if (!((CanUnlock*)*(void**)renderer)[0x66](renderer))
        return false;
    LeaveCriticalSection((B6B330CriticalSection*)renderer->m_kRendererLock);
    renderer->m_bRenderTargetGroupActive = 0;
    return true;
}


extern "C" NiRenderer* DAT_011f4748;
void __cdecl BSRenderedTexture_Begin(int a, int b);
// If the flag at DAT_011f4748+0x200 is unset, sets it when CheckFeature succeeds, then calls FUN_00b6b7d0 with b and a swapped.
// @fnv 0x00b6b890
// src: COMMUNITY 0x00b6b890
void __cdecl BSRenderedTexture_Start(int a, int b)
{
    int* initialized = reinterpret_cast<int*>(reinterpret_cast<char*>(DAT_011f4748) + 0x200);
    if (*initialized == 0)
    {
        typedef bool (__thiscall* CheckFeature)(NiRenderer*);
        NiRenderer* renderer = DAT_011f4748;
        if (((CheckFeature*)*(void**)renderer)[95](renderer))
        {
            *initialized = 1;
        }
    }
    BSRenderedTexture_Begin(b, a);
}

struct FUN_00b6b930_Object
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
};

// @fnv 0x00b6b930
// src: COMMUNITY 0x00b6b930
void __cdecl BSShaderUtil_RenderScenePostResolveDepth(unsigned int unused, FUN_00b6b930_Object* obj)
{
    obj->vfAC();
}

class FUN_00b6c1a0_obj
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual FUN_00b6c1a0_obj* vf44(int a);
    unsigned int m_04;
    FUN_00b6c1a0_obj* m_08;
};
class FUN_00b6c1a0_cls
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual FUN_00b6c1a0_obj* vf50();
    FUN_00b6c1a0_obj* NiDX9Renderer_GetScreenWidth();
};

// Calls vf50 to get an object, then vf44(0) on it, and returns that result's m_08 pointer, or null if either step fails.
// @fnv 0x00b6c1a0
// src: COMMUNITY 0x00b6c1a0
FUN_00b6c1a0_obj* FUN_00b6c1a0_cls::NiDX9Renderer_GetScreenWidth()
{
    FUN_00b6c1a0_obj* p = vf50();
    if (p == 0)
        return 0;
    FUN_00b6c1a0_obj* q = p->vf44(0);
    if (q == 0)
        return 0;
    return q->m_08;
}

struct FUN_00b6c1d0_Class
{
    virtual void VF00();
    virtual void VF04();
    virtual void VF08();
    virtual void VF0C();
    virtual void VF10();
    virtual void VF14();
    virtual void VF18();
    virtual void VF1C();
    virtual void VF20();
    virtual void VF24();
    virtual void VF28();
    virtual void VF2C();
    virtual void VF30();
    virtual void VF34();
    virtual void VF38();
    virtual void VF3C();
    virtual void VF40();
    virtual void VF44();
    virtual void VF48();
    virtual void VF4C();
    virtual void VF50();
    virtual void VF54();
    virtual void VF58();
    virtual void VF5C();
    virtual void VF60();
    virtual void VF64();
    virtual void VF68();
    virtual void VF6C();
    virtual void VF70();
    virtual void VF74();
    virtual void VF78();
    virtual void VF7C();
    virtual void VF80();
    virtual void VF84();
    virtual void VF88();
    virtual void VF8C();
    virtual void VF90();
    virtual void VF94();
    virtual void VF98();
    virtual void VF9C();
    virtual void VFA0();
    virtual void VFA4();
    virtual void VFA8();
    virtual void VFAC();
    virtual void VFB0();
    virtual void VFB4();
    virtual void VFB8();
    virtual void VFBC();
    virtual void VFC0();
    virtual void VFC4();
    virtual int* __thiscall VF50_Call();
    int __thiscall NiDX9Renderer_GetScreenHeight();
};

struct FUN_00b6c1d0_SubClass
{
    virtual void VF00();
    virtual void VF04();
    virtual void VF08();
    virtual void VF0C();
    virtual void VF10();
    virtual void VF14();
    virtual void VF18();
    virtual void VF1C();
    virtual void VF20();
    virtual void VF24();
    virtual void VF28();
    virtual void VF2C();
    virtual void VF30();
    virtual void VF34();
    virtual void VF38();
    virtual void VF3C();
    virtual void VF40();
    virtual void VF44();
    virtual void VF48();
    virtual void VF4C();
    virtual void VF50();
    virtual void VF54();
    virtual void VF58();
    virtual void VF5C();
    virtual void VF60();
    virtual void VF64();
    virtual void VF68();
    virtual void VF6C();
    virtual void VF70();
    virtual void VF74();
    virtual void VF78();
    virtual void VF7C();
    virtual void VF80();
    virtual void VF84();
    virtual void VF88();
    virtual void VF8C();
    virtual void VF90();
    virtual void VF94();
    virtual void VF98();
    virtual void VF9C();
    virtual void VFA0();
    virtual void VFA4();
    virtual void VFA8();
    virtual void VFAC();
    virtual int* __thiscall VF44_Call(int a);
};

// @fnv 0x00b6c1d0
// src: COMMUNITY 0x00b6c1d0
int FUN_00b6c1d0_Class::NiDX9Renderer_GetScreenHeight()
{
    int* piVar1 = this->VF50_Call();
    if (piVar1 == 0)
    {
        return 0;
    }

    int* iVar2 = reinterpret_cast<FUN_00b6c1d0_SubClass*>(piVar1)->VF44_Call(0);
    if (iVar2 == 0)
    {
        return 0;
    }

    return *(iVar2 + 3);
}

struct CpuObject
{
    unsigned int unk00;
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    int value;
    int BSTextureManager_GetShadowDepthBuffer();
};
// @fnv 0x00b6d120
// src: COMMUNITY 0x00b6d120
int CpuObject::BSTextureManager_GetShadowDepthBuffer()
{
    return value;
}

struct FUN_00b6d130_cls
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
    NiRefObject* m_pCounted;

    void ReleaseCounted();
};

// Decrements the reference count of m_pCounted and calls Release when it reaches zero, then clears m_pCounted.
// @fnv 0x00b6d130
void FUN_00b6d130_cls::ReleaseCounted()
{
    NiRefObject* pCounted = m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->m_uiRefCount) == 0)
        {
            pCounted->DeleteThis();
        }
        m_pCounted = 0;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);


struct TexPrefs_b6d170
{
    int m_pixelLayout;
    int m_alphaFmt;
    int m_mipMapped;
};

extern NiRenderer* DAT_011f9508;
extern bool DAT_011f9183;
extern bool DAT_011f4ac0;
extern int DAT_011ab3c8;
extern bool DAT_011ab3c4;
extern int DAT_011bf400;

void* __cdecl Create_00ee8330(unsigned int size, NiRenderer* renderer, TexPrefs_b6d170& prefs);

struct RenderTarget_b6d170
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
    static void* operator new(unsigned int size);
    RenderTarget_b6d170(void* tex, int a, void* depth);
    static RenderTarget_b6d170* __cdecl CreateWrapperFromGeometry(const NiFixedString& name, unsigned int w,
                                                                  unsigned int h, TexPrefs_b6d170* prefs, int msaa,
                                                                  bool b, void* depth, int a9, int a10);
};

struct RTManager_b6d170
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
    void* unkA8;
    RenderTarget_b6d170* CreateRenderTarget(int a1, unsigned int width, unsigned int height, int a4, int a5,
                                            unsigned int flags, int a7, int msaaType, int a9, int a10);
};

// @fnv 0x00b6d170
RenderTarget_b6d170* RTManager_b6d170::CreateRenderTarget(int aiUnused, unsigned int width, unsigned int height, int a4,
                                                          int aiUnused2, unsigned int flags, int aiUnused3,
                                                          int msaaType, int a9, int a10)
{
    void* depth = 0;
    int msaa = 0;
    RenderTarget_b6d170* result = 0;
    TexPrefs_b6d170 prefs;
    prefs.m_mipMapped = 2;
    unsigned int w;
    unsigned int h;
    if (DAT_011f9183)
    {
        w = width;
        h = height;
    }
    else
    {
        unsigned int m = width > height ? width : height;
        unsigned int p = 1;
        while (p < m)
            p += p;
        h = p;
        w = p;
    }
    prefs.m_pixelLayout = 2;
    prefs.m_alphaFmt = 2;

    if (a4)
    {
        DAT_011f4ac0 = true;
        DAT_011ab3c8 = a4;
    }
    unsigned int uiFlag8 = flags & 8;
    if (uiFlag8)
        DAT_011ab3c4 = false;
    unsigned int uiFlag80 = flags & 0x80;
    if (uiFlag80)
        DAT_011bf400 = 0;
    if (!(flags & 0x100))
        depth = unkA8;
    if (flags & 0x40)
    {
        switch (msaaType)
        {
        case 2:
            msaa = 1;
            break;
        case 4:
            msaa = 2;
            break;
        case 8:
            msaa = 3;
            break;
        default:
            msaa = 0;
            break;
        }
    }
    bool b = !((flags >> 2) & 1);
    if (flags & 0x10)
    {
        void* tex = Create_00ee8330(w, DAT_011f9508, prefs);
        if (tex)
            result = new RenderTarget_b6d170(tex, 1, depth);
    }
    else
    {
        result =
            RenderTarget_b6d170::CreateWrapperFromGeometry(NiFixedString(""), w, h, &prefs, msaa, b, depth, a9, a10);
    }
    if (a4)
        DAT_011f4ac0 = false;
    if (uiFlag8)
        DAT_011ab3c4 = true;
    if (uiFlag80)
        DAT_011bf400 = 1;
    return result;
}

class FUN_00b6d370_cls
{
  public:
    void GetRenderTargetDesc(int iA, int iB, int* piOut0, int* piOut1, int* piOut2, int* piOut3, int* piOut4,
                             int* piOut5);
    void CreateRenderTarget(int iA, int i0, int i1, int i2, int i3, int i4, int iB, int i5, int iC, int iD);
    void BSTextureManager_CreateRenderedTexture_0(int iA, int iB, int iC, int iD);
};

// Computes six values from iA and iB via GetRenderTargetDesc, then passes them with iA, iB, iC and iD to CreateRenderTarget.
// @fnv 0x00b6d370
// src: COMMUNITY 0x00b6d370
void FUN_00b6d370_cls::BSTextureManager_CreateRenderedTexture_0(int iA, int iB, int iC, int iD)
{
    int i0, i1, i2, i3, i4, i5;
    GetRenderTargetDesc(iA, iB, &i0, &i1, &i2, &i3, &i4, &i5);
    CreateRenderTarget(iA, i0, i1, i2, i3, i4, iB, i5, iC, iD);
}

struct FUN_00b6f480_cls
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
    int m_i6c;
    void BSShaderNoLightingProperty_SetClampD3D(int a);
};

// Stores 3 when the incoming value differs from 3, otherwise 0.
// @fnv 0x00b6f480
// src: XBOX_PDB 0x00b6f480
void FUN_00b6f480_cls::BSShaderNoLightingProperty_SetClampD3D(int a)
{
    m_i6c = (a != 3) ? 3 : 0;
}

namespace fnv_00b6f8d0 {
struct S_00b6f8d0_Node
{
    int unk00;
    S_00b6f8d0_Node* unk04;
};

struct S_00b6f8d0_Object
{
    void** vtable;
};

typedef S_00b6f8d0_Node*(__thiscall* S_00b6f8d0_GetNext)(S_00b6f8d0_Object*);

extern int DAT_011f444c;
extern int DAT_011f4ac4;

struct FUN_00b6f8d0_class
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
    S_00b6f8d0_Object* unk60;

    void __thiscall BSShaderNoLightingProperty_GetTextureUse(void(__cdecl* callback)(void*, int, int), int value);
};

// Walks the linked list returned by unk60's vtable[2] looking for DAT_011f444c or DAT_011f4ac4, then calls callback with unk60, 0 and value.
// @fnv 0x00b6f8d0
// src: XBOX_PDB 0x00b6f8d0
void __thiscall FUN_00b6f8d0_class::BSShaderNoLightingProperty_GetTextureUse(void(__cdecl* callback)(void*, int, int), int value)
{
    S_00b6f8d0_Object* object = this->unk60;

    if (object)
    {
        S_00b6f8d0_Node* node = ((S_00b6f8d0_GetNext)object->vtable[2])(object);

        if (node)
        {
            while (node)
            {
                if (node == (S_00b6f8d0_Node*)&DAT_011f444c)
                    goto call_callback;

                node = node->unk04;
            }
        }

        object = this->unk60;

        if (object)
        {
            node = ((S_00b6f8d0_GetNext)object->vtable[2])(object);

            if (node)
            {
                while (node)
                {
                    if (node == (S_00b6f8d0_Node*)&DAT_011f4ac4)
                        goto call_callback;

                    node = node->unk04;
                }
            }
        }

    call_callback:
        callback(this->unk60, 0, value);
    }
}
}  // namespace fnv_00b6f8d0


typedef unsigned int(__cdecl* StreamReadFn)(NiStream* stream, void* buf, unsigned int size, unsigned int* io,
                                            unsigned int count);

class Sub64
{
  public:
    void FUN_004037f0(void* value, unsigned int zero);
};

class ObjOwner
{
  public:
    void FUN_00a64ce0(void** out);

  public:
    unsigned int unk00;
    unsigned int m_04;
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
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    NiStream* m_24c;
};

void __cdecl _NiFree_00aa10f0(void* apMemory);

static unsigned int ReadRaw(NiStream* stream, void* buf, unsigned int size)
{
    unsigned int io = size;
    unsigned int r = (*(StreamReadFn*)((char*)stream + 8))(stream, buf, size, &io, 1);
    *(unsigned int*)((char*)stream + 4) += r;
    return r;
}

class FUN_00b6fb20_cls
{
  public:
    void BSShaderProperty_LoadBinary(ObjOwner* p);
    void LoadFromStream(ObjOwner* p);

  public:
    unsigned int unk00;
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
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    Sub64 m_64;
    unsigned int m_68;
    unsigned int m_6C;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7C;
};

// Calls FUN_00ba92c0, reads m_6C from the stream, stores a value from FUN_00a64ce0 into m_64, and reads m_70..m_7C when p->m_04 is at least 0x1f.
// @fnv 0x00b6fb20
void FUN_00b6fb20_cls::LoadFromStream(ObjOwner* p)
{
    BSShaderProperty_LoadBinary(p);
    ReadRaw(p->m_24c, &m_6C, 4);
    void* v = 0;
    p->FUN_00a64ce0(&v);
    m_64.FUN_004037f0(v, 0);
    _NiFree_00aa10f0(v);
    if (p->m_04 >= 0x1f)
    {
        ReadRaw(p->m_24c, &m_70, 4);
        ReadRaw(p->m_24c, &m_74, 4);
        ReadRaw(p->m_24c, &m_78, 4);
        ReadRaw(p->m_24c, &m_7C, 4);
    }
}

// SetValue: thiscall setter, stores its single stack argument at this+0x6c.
struct FUN_00b6fd10_cls
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
    int m_6c;
    void SetValue(int value);
};

// @fnv 0x00b6fd10
void FUN_00b6fd10_cls::SetValue(int value)
{
    m_6c = value;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct Blob60_cls
{
    int m_00;
    int m_04;
    int m_08;
    void FUN_00b71300();
};

class BlobBase_cls
{
  public:
    BlobBase_cls();
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int m_1c;
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

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

class BlobObj_cls : public BlobBase_cls
{
  public:
    virtual void unk60();
    Blob60_cls m_60;
    float m_6c;
    int m_70;
    unsigned char m_74;
    int m_78;
    BlobObj_cls()
    {
        Blob60_cls* sub = &m_60;
        sub->m_08 = 0;
        sub->m_00 = 0;
        sub->m_04 = 0;
        sub->FUN_00b71300();
        m_6c = 1.0f;
        m_70 = 0;
        m_74 = 0;
        m_1c = 1;
        m_78 = 0;
    }
};

// Allocates and constructs a BlobObj_cls via its constructor, returning the new object.
// @fnv 0x00b71920
BlobObj_cls* CreateBlobObj()
{
    return new BlobObj_cls();
}

// @fnv 0x00b719c0
// src: HAVOK_LIB 0x00b719c0
double __hkMinD(double dA, double dB)
{
    return dA < dB ? dA : dB;
}

struct Vector3Words
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
struct FUN_00b71b40_shell
{
    Vector3Words ShadowSceneNode_GetLightingOffset() const;
};
// Returns the Vector3Words stored at offset 0x1e4 of this object.
// @fnv 0x00b71b40
// src: COMMUNITY 0x00b71b40
Vector3Words FUN_00b71b40_shell::ShadowSceneNode_GetLightingOffset() const
{
    const Vector3Words& position =
        *reinterpret_cast<const Vector3Words*>(reinterpret_cast<const unsigned char*>(this) + 0x1e4);
    return position;
}

struct FUN_00b71b90_VirtualObject
{
    void** vtable;
};

typedef void(__thiscall* FUN_00b71b90_VirtualFunction)(FUN_00b71b90_VirtualObject*);

extern FUN_00b71b90_VirtualObject* DAT_011fdd88[0x270 / sizeof(void*)];
extern FUN_00b71b90_VirtualObject* DAT_011fda48[0x340 / sizeof(void*)];

struct FUN_00b71b90_class
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

    void ShadowLightShader_RecreateRendererData();
    void FUN_00e814b0();
};

// @fnv 0x00b71b90
// src: COMMUNITY 0x00b71b90
void FUN_00b71b90_class::ShadowLightShader_RecreateRendererData()
{
    if (unk28 != 0)
    {
        unsigned int i;
        for (i = 0; i < 0x270 / sizeof(void*); ++i)
        {
            FUN_00b71b90_VirtualObject* object = DAT_011fdd88[i];
            if (object != 0)
            {
                FUN_00b71b90_VirtualFunction function =
                    reinterpret_cast<FUN_00b71b90_VirtualFunction>(object->vtable[0xa0 / sizeof(void*)]);
                function(object);
            }
        }
    }

    unsigned int i;
    for (i = 0; i < 0x340 / sizeof(void*); ++i)
    {
        FUN_00b71b90_VirtualObject* object = DAT_011fda48[i];
        if (object != 0)
        {
            FUN_00b71b90_VirtualFunction function =
                reinterpret_cast<FUN_00b71b90_VirtualFunction>(object->vtable[0x88 / sizeof(void*)]);
            function(object);
        }
    }

    this->FUN_00e814b0();
}

struct S_00b7ac20_Node
{
    int unk00;
    int unk04;
    unsigned char unk08;
};

extern S_00b7ac20_Node* DAT_011febdc[];
extern S_00b7ac20_Node* DAT_011fec34[];
extern S_00b7ac20_Node* DAT_011fec8c[];

extern int DAT_011fb4c0[];
extern int DAT_011fa8e0[];

struct S_00b7ac20_Callable
{
    // Empty virtual no-op body; does nothing.
// @fnv 0x00b7ac20
    virtual void FUN_00b7ac20_v00()
    {}
    virtual void FUN_00b7ac20_v04()
    {}
    virtual void FUN_00b7ac20_v08()
    {}
    virtual void FUN_00b7ac20_v0c()
    {}
    virtual void FUN_00b7ac20_v10()
    {}
    virtual void FUN_00b7ac20_v14()
    {}
    virtual void FUN_00b7ac20_v18()
    {}
    virtual void FUN_00b7ac20_v1c()
    {}
    virtual void FUN_00b7ac20_v20()
    {}
    virtual void FUN_00b7ac20_v24()
    {}
};

struct S_00b7ac20_Class
{
    unsigned int unk00;
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
    S_00b7ac20_Callable* unk30;
    S_00b7ac20_Callable* unk34;

    void __thiscall ShadowLightShader_DisableNonVolatileConstantsForPass(int index);
};

// src: COMMUNITY 0x00b7ac20
void __thiscall S_00b7ac20_Class::ShadowLightShader_DisableNonVolatileConstantsForPass(int index)
{
    if (DAT_011fb4c0[index] != 0)
    {
        unsigned int eax = 1;
        S_00b7ac20_Node** esi = DAT_011febdc;

        do
        {
            S_00b7ac20_Node* node = esi[-1];
            if (node != 0)
            {
                if (node->unk08 != 0)
                {
                    unsigned int mask = (eax << 1) | (eax >> 31);
                    node->unk08 = (DAT_011fb4c0[index] & mask) == 0;
                }
            }

            eax = (eax << 1) | (eax >> 31);

            node = esi[0];
            if (node != 0)
            {
                if (node->unk08 != 0)
                {
                    unsigned int mask = (eax << 1) | (eax >> 31);
                    node->unk08 = (DAT_011fb4c0[index] & mask) == 0;
                }
            }

            esi += 2;
            eax = (eax << 1) | (eax >> 31);
        } while ((int)esi < (int)DAT_011fec34);

        unk34->FUN_00b7ac20_v24();
    }

    if (DAT_011fa8e0[index] != 0)
    {
        int* selected = &DAT_011fa8e0[index];
        unsigned int eax = 1;
        S_00b7ac20_Node** esi = DAT_011fec34;

        do
        {
            S_00b7ac20_Node* node = esi[-1];
            if (node != 0)
            {
                if (node->unk08 != 0)
                {
                    unsigned int mask = (eax << 1) | (eax >> 31);
                    node->unk08 = (*selected & mask) == 0;
                }
            }

            eax = (eax << 1) | (eax >> 31);

            node = esi[0];
            if (node != 0)
            {
                if (node->unk08 != 0)
                {
                    unsigned int mask = (eax << 1) | (eax >> 31);
                    node->unk08 = (*selected & mask) == 0;
                }
            }

            esi += 2;
            eax = (eax << 1) | (eax >> 31);
        } while ((int)esi < (int)DAT_011fec8c);

        unk30->FUN_00b7ac20_v24();
    }
}

struct V3
{
    float x, y, z;
};
// Preserve the four-byte packing of the game light payload.
#pragma pack(push, 4)
struct LightData
{
    int unk00, unk04, unk08;
    unsigned char first[sizeof(V4)], second[sizeof(V4)];
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    float x, y, z;
};

#pragma pack(pop)
struct Context
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
    LightData* light;
};
extern unsigned char DAT_011f91c4;
BSFogProperty* BSShaderManager_GetFogProperty(int);
extern V4 DAT_011fd8f4;
extern V4 DAT_011fd904;
extern float DAT_011fd85c;
extern float DAT_011fd860;
extern float DAT_011fd914;
extern float DAT_011fd918;
extern V4 DAT_011fd924;
extern V4 DAT_011fd934;
// Copies the context's light data into global light vectors and, when enabled, stores fog color and depth/density into global fog vectors.
// @fnv 0x00b7ad80
void __stdcall UpdateLightAndFogGlobals(int enabled, Context* context)
{
    if (context)
    {
        LightData* data = context->light;
        if (data)
        {
            DAT_011fd8f4 = *(const V4*)data->first;
            DAT_011fd904 = *(const V4*)data->second;
            DAT_011fd85c = data->x;
            DAT_011fd860 = data->y;
            DAT_011fd914 = data->z;
            DAT_011fd918 = 1.0f;
        }
        SetShaderVector(DAT_011fd924, 0, 0, 0, 0);
        SetShaderVector(DAT_011fd934, 0, 0, 0, 0);
        if (enabled)
        {
            BSFogProperty* fog = BSShaderManager_GetFogProperty(DAT_011f91c4);
            if (fog)
            {
                float nearDepth = fog->nearDepth;
                float farDepth = fog->farDepth;
                float density = fog->density;
                if (farDepth != 0 || nearDepth != 0)
                {
                    NiColor color = fog->color;
                    SetShaderVector(DAT_011fd934, farDepth, farDepth - nearDepth, density, 0);
                    SetShaderVector(DAT_011fd924, color.r, color.g, color.b, 0);
                }
            }
        }
    }
}

struct TexStageStub
{
    int unk00;
    int unk04;
    unsigned int m_08;
    void ApplyPairToState(unsigned int v);
};
struct StageMgrStub
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
    TexStageStub** m_pElems;
};
struct ShaderFieldsStub
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
    unsigned int* m_pArr;
};

// Stores shader's m_pArr[j] into stage i's m_08 and calls the stage's ApplyPairToState with GetShaderStageState(shader).
// @fnv 0x00b7c0a0
// src: COMMUNITY 0x00b7c0a0
void __stdcall ShadowLightShader_SetDiffuseMap(NiD3DShader* shader, unsigned int uiStageIndex, unsigned int j)
{
    StageMgrStub* pStageMgr = reinterpret_cast<StageMgrStub*>(DAT_0126f74c);
    TexStageStub* stage = pStageMgr->m_pElems[uiStageIndex];
    ShaderFieldsStub* sh = reinterpret_cast<ShaderFieldsStub*>(shader);
    stage->m_08 = sh->m_pArr[j];
    stage->ApplyPairToState(GetShaderStageState(shader));
}

struct S_00b7c120_Target
{
    int unk00;
    int unk04;
    void* unk08;
};

struct S_00b7c120_Global1
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
    S_00b7c120_Target** unk24;
};

struct S_00b7c120_Callback
{
    void* BSRenderedTexture_GetTexture(int value);
};

struct S_00b7c120_Inner
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    S_00b7c120_Callback* unk10c;
};

struct S_00b7c120_Outer
{
    S_00b7c120_Inner* unk00;
};

struct S_00b7c120_Global2
{
    int unk00;
    int unk04;
    int unk08;
    S_00b7c120_Outer* unk0c;
};

extern S_00b7c120_Global2* DAT_011f91e0;

// Looks up targets[index] and stores the result of callback->FUN_004bc320(0) into its unk08 field.
// @fnv 0x00b7c120
// src: COMMUNITY 0x00b7c120
void __stdcall ShadowLightShader_SetShadowMap(int index)
{
    S_00b7c120_Global1* global1 = reinterpret_cast<S_00b7c120_Global1*>(DAT_0126f74c);
    S_00b7c120_Target** targets = global1->unk24;
    S_00b7c120_Global2* global2 = DAT_011f91e0;
    S_00b7c120_Target* target = targets[index];
    S_00b7c120_Outer* outer = global2->unk0c;
    S_00b7c120_Inner* inner = outer->unk00;
    S_00b7c120_Callback* callback = inner->unk10c;

    target->unk08 = callback->BSRenderedTexture_GetTexture(0);
}

struct FUN_00b7c170_Entry
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00b7c170_Container
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
    FUN_00b7c170_Entry** unk24;
};

extern int DAT_0126f74c;
extern int DAT_011f95e8;

// @fnv 0x00b7c170
// src: COMMUNITY 0x00b7c170
void __stdcall ShadowLightShader_SetProjectedShadowMaskMap(int index)
{
    FUN_00b7c170_Container* container = reinterpret_cast<FUN_00b7c170_Container*>(DAT_0126f74c);
    container->unk24[index]->unk08 = DAT_011f95e8;
}


struct B7C1F0Stage
{
    int unk00;
    int unk04;
    NiTexture* m_pkTexture;
};

struct B7C1F0Pass
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
    B7C1F0Stage** m_ppkStages;
};

struct B7C1F0Property
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
    NiTexture** m_ppkTextures;
};

extern B7C1F0Pass* g_pkB7C1F0Pass;
extern NiTexture* g_pkB7C1F0DefaultTexture;

// Assigns the property's texture at uiTexture to the pass stage at uiStage, falling back to the default texture or null when none is set.
// @fnv 0x00b7c1f0
// src: COMMUNITY 0x00b7c1f0
void __stdcall ShadowLightShader_SetGlowMap(B7C1F0Property* pkProperty, unsigned int uiStage, unsigned int uiTexture, bool bUseDefault)
{
    B7C1F0Stage* pkStage = g_pkB7C1F0Pass->m_ppkStages[uiStage];
    NiTexture* pkTexture = pkProperty->m_ppkTextures[uiTexture];
    if (pkTexture)
        pkStage->m_pkTexture = pkTexture;
    else
        pkStage->m_pkTexture = bUseDefault ? g_pkB7C1F0DefaultTexture : 0;
}

extern int DAT_0126f74c;
extern int DAT_011f951c;

typedef int(__thiscall* FUN_00b7c230_VFn)(void* self, int a, int b);

// @fnv 0x00b7c230
// src: COMMUNITY 0x00b7c230
void __stdcall ShadowLightShader_SetParallaxTexture(char* self, unsigned int uiIndex, int a3, unsigned char ucFlag)
{
    char* g = (char*)DAT_0126f74c;
    int* table = *(int**)(g + 0x24);
    char* e = (char*)table[uiIndex];
    if (((FUN_00b7c230_VFn) * (void**)(*(char**)self + 0xf4))(self, 3, a3))
    {
        *(int*)(e + 8) = ((FUN_00b7c230_VFn) * (void**)(*(char**)self + 0xf4))(self, 3, a3);
        return;
    }
    *(int*)(e + 8) = ucFlag ? DAT_011f951c : 0;
}

struct SlotObject
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
    virtual int GetValue(int a, int b);
};
struct SlotElem
{
    int unk00;
    int unk04;
    int m_08;
};
struct SlotGlobal
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
    SlotElem** m_24;
};
extern int DAT_0126f74c;
extern int DAT_011f9514;

// Looks up the slot element at index and stores obj->GetValue(5, arg) into its m_08, or DAT_011f9514 when that returns 0.
// @fnv 0x00b7c2c0
void __stdcall SetSlotValue(SlotObject* obj, int index, int arg)
{
    SlotGlobal* g = (SlotGlobal*)DAT_0126f74c;
    SlotElem* elem = g->m_24[index];
    if (obj->GetValue(5, arg) != 0)
    {
        elem->m_08 = obj->GetValue(5, arg);
    }
    else
    {
        elem->m_08 = DAT_011f9514;
    }
}

extern unsigned int DAT_011f91e4;
extern int DAT_011ff9dc;
extern int DAT_011ffa18;
void __cdecl BSRenderState_SetZFunc(int mode, int unused);
void __cdecl UpdateRendererStateCount(int mode, int unused);
void __cdecl BSRenderState_SetZWriteEnable(int mode, int unused);
void __cdecl FUN_00b98380(int mode, int unused);

struct RenderFlagInfo
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int flags18;
};
struct RenderState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int flags20;
};
struct RenderArguments
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    RenderState* state;
    RenderFlagInfo* info;
};

// @fnv 0x00b7c320
void __stdcall ApplyRenderModeState(RenderArguments* args)
{
    const unsigned int mode = DAT_011f91e4;
    if (mode == 0x250 || mode == 0x251)
    {
        BSRenderState_SetZFunc(3, 0);
    }

    RenderFlagInfo* info = args->info;
    if (info && (info->flags18 & 1u))
    {
        UpdateRendererStateCount(0, 0);
    }

    RenderState* state = args->state;
    if ((mode == 6 || mode == 8) && (state->flags20 & 0x40000u) > 0)
    {
        --DAT_011ff9dc;
        BSRenderState_SetZWriteEnable(1, 0);
        --DAT_011ffa18;
        FUN_00b98380(7, 0);
    }
}

namespace fnv_00b7c510 {
struct SpawnedObject
{
    int m_00;
    int m_04;
    unsigned char m_flag;
};

extern int DAT_011f91e4;
extern unsigned int DAT_011fc0a0[];
extern SpawnedObject* DAT_011fec30[];

struct FlagTarget
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
};

static unsigned int RotL1(unsigned int x)
{
    return (x << 1) | (x >> 31);
}

struct FUN_00b7c510_cls
{
    int m_00;
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
    FlagTarget* m_30;
    void UpdateSpawnedObjectFlags();
};

// @fnv 0x00b7c510
void FUN_00b7c510_cls::UpdateSpawnedObjectFlags()
{
    unsigned int rot = 1;
    SpawnedObject** p = &DAT_011fec30[1];
    do
    {
        SpawnedObject* a = p[-1];
        if (a != 0)
        {
            a->m_flag = (DAT_011fc0a0[DAT_011f91e4] & RotL1(rot)) != 0;
        }
        rot = RotL1(rot);
        SpawnedObject* b = *p;
        if (b != 0)
        {
            b->m_flag = (DAT_011fc0a0[DAT_011f91e4] & RotL1(rot)) != 0;
        }
        rot = RotL1(rot);
        p += 2;
    } while ((int)p < (int)&DAT_011fec30[23]);
    m_30->v09();
}
}  // namespace fnv_00b7c510

namespace fnv_00b7ce90 {
struct RenderState;

struct TexStage
{
    int unk00;
    int unk04;
    NiTexture* m_texture;
    void SetUV(unsigned int);
};

struct StageList
{
    TexStage* m_pHeadNode;
    TexStage* m_iSecondInteger;
};

struct ShaderPass
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
    StageList* m_kTextureStages;
    RenderState* GetRenderState();
};

struct RenderState
{
    virtual void r00();
    virtual void r01();
    virtual void r02();
    virtual void r03();
    virtual void r04();
    virtual void r05();
    virtual void r06();
    virtual void r07();
    virtual void r08();
    virtual void r09();
    virtual void r0a();
    virtual void r0b();
    virtual void r0c();
    virtual void r0d();
    virtual void r0e();
    virtual void r0f();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void SetBlend(int, int, int, int);
    virtual void q18();
    virtual void q19();
    virtual void SetRS(int, int, int, int);
};

struct PassKey
{
    int unk00;
    unsigned short m_type;
};

struct ShaderProps
{
    int unk00;
    int unk04;
    NiTexture* m_texture;
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
    int m_srcBlend;
    int m_dstBlend;
    int m_alphaTestRef;
    int m_zFunc;
};

struct Geometry
{
    virtual void g00();
    virtual void g01();
    virtual void g02();
    virtual void g03();
    virtual void g04();
    virtual void g05();
    virtual void g06();
    virtual void g07();
    virtual void g08();
    virtual void g09();
    virtual void g0a();
    virtual void g0b();
    virtual void g0c();
    virtual void g0d();
    virtual void g0e();
    virtual void g0f();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g1a();
    virtual void g1b();
    virtual void g1c();
    virtual void g1d();
    virtual void g1e();
    virtual void g1f();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g2a();
    virtual void g2b();
    virtual void g2c();
    virtual void g2d();
    virtual void g2e();
    virtual void g2f();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual unsigned int GetUVSet();
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
    ShaderProps* m_props;
};

extern ShaderPass* g_passTable[];
extern ShaderPass* g_currentPass;
extern NiTexture* g_defaultTexture;

struct FUN_00b7ce90_class
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual void s1d();
    virtual void s1e();
    virtual void s1f();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s2a();
    virtual void s2b();
    virtual void s2c();
    virtual void s2d();
    virtual void s2e();
    virtual void s2f();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s3a();
    virtual void s3b();
    virtual void s3c();
    virtual void s3d();
    virtual void s3e();
    virtual void s3f();
    virtual void s40();
    virtual void s41();
    virtual void Finish();
    NiTexture* GetTexture(Geometry* geom, int a);
    void SetupGeometry(void* a, Geometry* geom);
    void SetupPass(void* a, Geometry* geom, PassKey* key);
};

// Selects the shader pass for the key's type, assigns textures and UV sets to its stages, sets blend and render states, then makes it the current pass.
// @fnv 0x00b7ce90
void FUN_00b7ce90_class::SetupPass(void* a, Geometry* geom, PassKey* key)
{
    if (!key)
        return;
    ShaderPass* pass = g_passTable[key->m_type];
    ShaderProps* props = geom->m_props;
    if (!props)
        return;
    TexStage* stage = pass->m_kTextureStages->m_pHeadNode;
    stage->m_texture = GetTexture(geom, 0);
    stage->SetUV(geom->GetUVSet());
    stage = pass->m_kTextureStages->m_iSecondInteger;
    if (props->m_texture)
        stage->m_texture = props->m_texture;
    else
        stage->m_texture = g_defaultTexture;
    stage->SetUV(geom->GetUVSet());
    g_currentPass->GetRenderState()->SetBlend(props->m_srcBlend, props->m_dstBlend, 0, 0);
    g_currentPass->GetRenderState()->SetRS(0xab, props->m_alphaTestRef, 0, 0);
    g_currentPass->GetRenderState()->SetRS(0x17, props->m_zFunc, 0, 0);
    SetupGeometry(a, geom);
    Finish();
    g_currentPass = pass;
}
}  // namespace fnv_00b7ce90

struct RenderContext
{
    void FUN_00e7eb00(int mode);
};
struct RenderNode
{
    int unk00, unk04, unk08, unk0c, unk10;
    RenderContext* unk14;
};
struct RenderGlobals
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    RenderNode* unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    void* unk44;
};
extern int DAT_0126f74c;
struct FeatureFlags
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int active20;
};
extern FeatureFlags* DAT_011febf0;
extern FeatureFlags* DAT_011fec38;
struct RenderOutput
{
    NiQuaternion orientation;
    NiTransform transform;
};
struct Callback;
typedef void(__thiscall* RenderCallback)(Callback*, void*, int, int, int, int, int, int, NiTransform*, NiQuaternion*,
                                         int, int);
struct Callback
{
    RenderCallback* vtable;
};
struct Renderer
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Callback* target30;
    void UpdateFogShaderConstants();
    void UpdateSpawnedObjectFlags();
    void ShadowLightShader_SetupPassOpt_AmbientLight();
    void ShadowLightShader_SetupPassOpt_LightColor();
    void ShadowLightShader_SetupPass_ADT_Opt();
};
// @fnv 0x00b7dd50
// src: COMMUNITY 0x00b7dd50
void Renderer::ShadowLightShader_SetupPass_ADT_Opt()
{
    RenderOutput renderOutput;
    reinterpret_cast<RenderGlobals*>(DAT_0126f74c)->unk24->unk14->FUN_00e7eb00(0);
    UpdateFogShaderConstants();
    DAT_011febf0->active20 = 1;
    DAT_011fec38->active20 = 1;
    UpdateSpawnedObjectFlags();
    ShadowLightShader_SetupPassOpt_AmbientLight();
    ShadowLightShader_SetupPassOpt_LightColor();
    Callback* callback = target30;
    if (callback && reinterpret_cast<RenderGlobals*>(DAT_0126f74c)->unk44)
        callback->vtable[30](callback, reinterpret_cast<RenderGlobals*>(DAT_0126f74c)->unk44, 0, 0, 0, 0, 0, 0,
                             &renderOutput.transform, &renderOutput.orientation, 0, 1);
}

namespace fnv_00b7e300 {
// Destructor of a pooled object: releases the element array held at +4 and
// restores the class vtable pointer stored at +0.
struct FUN_00b7e300_cls
{
    void* m_pVTable;
    int** m_pData;
    void DestroyDataArray();
};

// Global memory manager that takes back a released block.
struct FUN_00b7e300_pool
{
    void __thiscall MemoryManager_Deallocate(void* pBlock);
};

extern char DAT_010ef53c;
extern FUN_00b7e300_pool DAT_011f6238;
extern void __stdcall FUN_00ec5fce(void* pData, int stride, int count, void(__cdecl* fnDestroy)(void*));
extern void __cdecl FUN_0045cec0(void* pElement);

// Sets the vtable, then frees the m_pData array with its element destructor and releases the block.
// @fnv 0x00b7e300
void FUN_00b7e300_cls::DestroyDataArray()
{
    int** pData = m_pData;
    m_pVTable = &DAT_010ef53c;
    if (pData != 0)
    {
        int count = ((int*)pData)[-1];  // element count stored in the block header
        FUN_00ec5fce(pData, 4, count, FUN_0045cec0);
        DAT_011f6238.MemoryManager_Deallocate(pData - 1);
    }
}
}  // namespace fnv_00b7e300

// @fnv 0x00b7fd00
NiTPointerMap<const char*, ShaderBufferRecord*>* __fastcall DestroyShaderBufferMap(
    NiTPointerMap<const char*, ShaderBufferRecord*>* self, void*, unsigned int flags)
{
    self->NiTPointerMap<const char*, ShaderBufferRecord*>::~NiTPointerMap();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

// @fnv 0x00b60360
template <> OwnerMap::~NiTMap()
{
    RemoveAll();
}

namespace fnv_00b60b50 {

class DeleteObjectRef
{
  public:
    virtual ~DeleteObjectRef();
    int unk04;
    long references;
    void DecRefCount()
    {
        if (InterlockedDecrement(&references) == 0)
            delete this;
    }
};
// This embedded object's original destructor is inlined. Keep that lifetime
// operation local while taking its size and reference-count type from the header.
template <class T> struct InPlaceStorage
{
    unsigned char bytes[sizeof(T)];
    InPlaceStorage() {}
    explicit InPlaceStorage(void* object);
    ~InPlaceStorage();
};
extern void* NiRefObjectVTable[];
template <> inline InPlaceStorage<NiRefObject>::~InPlaceStorage()
{
    *(void**)bytes = NiRefObjectVTable;
    InterlockedDecrement((volatile long*)&NiRefObject::ms_lObjectCount);
}
struct FUN_00b60b50
{
    InPlaceStorage<NiRefObject> baseObject;
    NiPointer<NiRefObject> member08;
    int unk0c, unk10;
    NiPointer<NiRefObject> member14;
    NiPointer<NiRefObject> member18;
    NiPointer<NiRefObject> member1c;
    NiPointer<NiRefObject> member20;
    NiPointer<DeleteObjectRef> member24;
    ~FUN_00b60b50();
};
// Destructor of a struct holding reference-counted pointers; the member destructors release them.
// @fnv 0x00b60b50
FUN_00b60b50::~FUN_00b60b50()
{}
}  // namespace fnv_00b60b50


class BaseObj_b60
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    BaseObj_b60();
    virtual ~BaseObj_b60();
};
class FUN_00b60cb0 : public BaseObj_b60
{
  public:
    unsigned int m_1c;
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
    unsigned int m_7c;
    NiPointer<NiRefObject> m_80;
    NiPointer<NiRefObject> m_84;
    NiPointer<NiRefObject> m_88;
    unsigned short m_8c;
    unsigned short m_8e;
    FUN_00b60cb0();
    virtual ~FUN_00b60cb0();
};
// Initializes the object: clears m_88.m_pObject, m_8c, m_8e, m_80, m_7c and sets m_1c to 4.
// @fnv 0x00b60cb0
FUN_00b60cb0::FUN_00b60cb0()
{
    m_88.m_pObject = 0;
    m_8c = 0;
    m_8e = 0;
    m_80 = (NiRefObject*)0;
    m_7c = 0;
    m_1c = 4;
}

extern MemoryManager g_memoryManager;

// 0x00b61250/0x00b61350 clear the released slot only on the non-null path.
static inline void ReleaseAndClearReference(NiPointer<NiRefObject>& ref)
{
    if (ref.m_pObject)
    {
        ref.m_pObject->DecRefCount();
        ref.m_pObject = 0;
    }
}

struct B61250Item
{
    void Shutdown();
    ~B61250Item()
    {
        Shutdown();
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

struct B61250Node
{
    B61250Node* next;
    B61250Node* prev;
    B61250Item* data;
};

struct B61250List
{
    B61250Node* head;
    B61250Node* tail;
    int count;
    void RemoveAll() throw();
    B61250Item*& GetNext(B61250Node*& pos)
    {
        B61250Item*& r = pos->data;
        pos = pos->next;
        return r;
    }
    ~B61250List()
    {
        RemoveAll();
    }
};

struct FUN_00b61250
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    B61250List m_kNode;
    NiPointer<NiRefObject> m_ptr;
    NiTMap<const char*, B61250Item*> m_map;
    ~FUN_00b61250();
};

// @fnv 0x00b61250
FUN_00b61250::~FUN_00b61250()
{
    ReleaseAndClearReference(m_ptr);
    m_map.RemoveAll();
    for (B61250Node* node = m_kNode.head; node;)
    {
        B61250Item* p = m_kNode.GetNext(node);
        delete p;
    }
    m_kNode.RemoveAll();
    ReleaseAndClearReference(m_ptr);
    m_map.RemoveAll();
}

// @fnv 0x00b63d80
template <> NiTPointerMap<NiAVObject*, bool>::~NiTPointerMap()
{
    RemoveAll();
}

// Feed every entry of the owner's list for this key into the current thread's accumulator.

extern __declspec(thread) unsigned int g_uiB644B0ThreadSlot;

struct B644B0Entry
{
    int unk00;
    unsigned short m_usIndex;
};

struct B644B0EntryList
{
    int unk00;
    B644B0Entry** m_ppkEntries;
    int unk08;
    int unk0C;
    unsigned int m_uiCount;
};

class B644B0Owner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual B644B0EntryList* GetEntries(void* pvKey);
};

struct B644B0Shape
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    char unk164;
    bool m_bEnableState;
    char unk166;
    char unk167;
    int unk168;
    int unk16C;
    int unk170;
    BSBatchRenderer* m_apkAccumulators[4];
};

// If the shape's flag is set, fetches the entry list for pvKey and adds each entry to the thread's accumulator, returning true.
// @fnv 0x00b644b0
bool __cdecl AddEntriesToAccumulator(B644B0Shape* pkShape, void* pvKey, int iUnused, B644B0Owner* pkOwner)
{
    if (pkShape->m_bEnableState)
    {
        B644B0EntryList* pkList = pkOwner->GetEntries(pvKey);
        if (pkList)
        {
            for (unsigned int i = 0; i < pkList->m_uiCount; i++)
            {
                B644B0Entry* pkEntry = pkList->m_ppkEntries[i];
                BSBatchRenderer* renderer = pkShape->m_apkAccumulators[g_uiB644B0ThreadSlot];
                typedef void (__thiscall* Submit)(BSBatchRenderer*, B644B0Entry*, unsigned int);
                ((Submit*)*(void**)renderer)[0x23](renderer, pkEntry, pkEntry->m_usIndex);
            }
        }
    }
    return true;
}

namespace fnv_00b66810 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

extern long DAT_011f4400;

struct FUN_00b66810 : NiRefObject
{
    bool m_08;
    int m_0c;
    int m_10;

    FUN_00b66810(bool flag);
    virtual ~FUN_00b66810();
};

// Initializes the object with the given flag and zeroes the two integer members m_0c and m_10.
// @fnv 0x00b66810
FUN_00b66810::FUN_00b66810(bool flag)
{
    m_08 = flag;
    m_0c = 0;
    m_10 = 0;
}
}  // namespace fnv_00b66810

struct ZeroQuad
{
    float a, b, c, d;
    ZeroQuad() : a(0.0f), b(0.0f), c(0.0f), d(0.0f)
    {}
};

class FUN_00b668b0 : public NiRefObject
{
  public:
    FUN_00b668b0();
    virtual ~FUN_00b668b0();

    NiPointer<NiRefObject> m_pReferencedObject;
    ZeroQuad m_akRows[4];
    float m_afExtra[4];
    int m_iMode;
    int m_iScaleA;
    int m_iScaleB;
    int m_iType;
    NiPointer<NiRefObject> m_spOther;
    int m_iFlags;
};

// @fnv 0x00b668b0
FUN_00b668b0::FUN_00b668b0()
{
    m_pReferencedObject = 0;
    for (int i = 0; i < 4; i++)
    {
        m_akRows[i].a = 0.0f;
        m_akRows[i].b = 0.0f;
        m_akRows[i].c = 0.0f;
        m_akRows[i].d = 0.0f;
    }
    m_afExtra[0] = 0.0f;
    m_afExtra[1] = 0.0f;
    m_afExtra[2] = 0.0f;
    m_afExtra[3] = 0.0f;
    m_iMode = 2;
    m_iScaleA = 1;
    m_iScaleB = 1;
    m_iType = 3;
    m_spOther = 0;
    m_iFlags = 0;
}

struct TargetGroup
{
    virtual void Virtual00();
    virtual void Virtual01();
    virtual void Virtual02();
    virtual void Virtual03();
    virtual void Virtual04();
    virtual void Virtual05();
    virtual void Virtual06();
    virtual void Virtual07();
    virtual void Virtual08();
    virtual void Virtual09();
    virtual void Virtual10();
    virtual void Virtual11();
    virtual void Virtual12();
    virtual void Virtual13();
    virtual void Virtual14();
    virtual void Virtual15();
    virtual void Virtual16();
    virtual void Virtual17();
    virtual void Virtual18();
    virtual void Virtual19();
    virtual void Virtual20();
    virtual void Virtual21();
    virtual void Virtual22();
    virtual void Virtual23();
    virtual void Virtual24();
    virtual void Virtual25();
    virtual void Virtual26();
    virtual void Virtual27();
    virtual void Virtual28();
    virtual void Virtual29();
    virtual void Virtual30();
    virtual void Virtual31();
    virtual void Virtual32();
    virtual void Virtual33();
    virtual void Virtual34();
    virtual unsigned int Width(unsigned int);
    virtual unsigned int Height(unsigned int);
};
struct RenderConfigSurface
{
    virtual void Virtual00();
    virtual void Virtual01();
    virtual void Virtual02();
    virtual void Virtual03();
    virtual void Virtual04();
    virtual void Virtual05();
    virtual void Virtual06();
    virtual void Virtual07();
    virtual void Virtual08();
    virtual void Virtual09();
    virtual void Virtual10();
    virtual void Virtual11();
    virtual void Virtual12();
    virtual void Virtual13();
    virtual void Virtual14();
    virtual void Virtual15();
    virtual void Virtual16();
    virtual void Virtual17();
    virtual void Virtual18();
    virtual void Virtual19();
    virtual void Virtual20();
    virtual void Virtual21();
    virtual void Virtual22();
    virtual void Virtual23();
    virtual void Virtual24();
    virtual void Virtual25();
    virtual void Virtual26();
    virtual void Virtual27();
    virtual void Virtual28();
    virtual void Virtual29();
    virtual void Virtual30();
    virtual void Virtual31();
    virtual void Virtual32();
    virtual void Virtual33();
    virtual void Virtual34();
    virtual void Virtual35();
    virtual void Virtual36();
    virtual void Virtual37();
    virtual void Virtual38();
    virtual void Virtual39();
    virtual void Virtual40();
    virtual void Virtual41();
    virtual void Virtual42();
    virtual void Virtual43();
    virtual void Virtual44();
    virtual void Virtual45();
    virtual void Virtual46();
    virtual void Virtual47();
    virtual void Virtual48();
    virtual void Virtual49();
    virtual TargetGroup* Group();
    unsigned int NiDX9Renderer_GetScreenWidth();
    unsigned int NiDX9Renderer_GetScreenHeight();
};
struct GroupDispatch
{
    void* slot00;
    void* slot01;
    void* slot02;
    void* slot03;
    void* slot04;
    void* slot05;
    void* slot06;
    void* slot07;
    void* slot08;
    void* slot09;
    void* slot10;
    void* slot11;
    void* slot12;
    void* slot13;
    void* slot14;
    void* slot15;
    void* slot16;
    void* slot17;
    void* slot18;
    void* slot19;
    void* slot20;
    void* slot21;
    void* slot22;
    void* slot23;
    void* slot24;
    void* slot25;
    void* slot26;
    void* slot27;
    void* slot28;
    void* slot29;
    void* slot30;
    void* slot31;
    void* slot32;
    void* slot33;
    void* slot34;
    void* slot35;
    void* slot36;
    void* slot37;
    void* slot38;
    void* slot39;
    void* slot40;
    void* slot41;
    void* slot42;
    void* slot43;
    void* slot44;
    void* slot45;
    void* slot46;
    void* slot47;
    void* slot48;
    void* slot49;
    TargetGroup*(__fastcall* group)(RenderConfigSurface*, GroupDispatch*);
};
struct GroupReceiver
{
    GroupDispatch* dispatch;
};
int __cdecl NiDX9Renderer_GetMultiSampleType(int);
extern int DAT_011f9490;
extern bool DAT_011f9426;
extern int DAT_011f9430, DAT_011f9434;
extern bool DAT_011f941e;
extern unsigned int DAT_01200054;
extern unsigned int DAT_011ad81c, DAT_011ad820;
extern unsigned int DAT_011ad814, DAT_011ad818, DAT_011ad810;
extern unsigned int DAT_011adbc8;
extern bool DAT_011ad80e;
extern unsigned short DAT_011ad830;
extern unsigned int DAT_011ad870;
extern bool DAT_012004fc;
// @fnv 0x00b6c2c0
void __stdcall GetRenderTargetDesc(RenderConfigSurface* renderer, unsigned int type, unsigned int* width,
                                   unsigned int* height, unsigned int* format, unsigned int* unused,
                                   unsigned int* flags, unsigned int* samples)
{
    *unused = 0;
    *samples = NiDX9Renderer_GetMultiSampleType(DAT_011f9490);
    switch (type)
    {
        {
        case 0:
            *flags = 0x26;
            if (renderer->Group()->Width(0) > 0x500)
            {
                *width = DAT_011f9426 ? DAT_011f9430 / 4 : renderer->Group()->Width(0) / 4;
                *height = DAT_011f9426 ? DAT_011f9434 / 4 : renderer->Group()->Height(0) / 4;
            }
            else
            {
                *height = 0x100;
                *width = 0x100;
            }
            *format = 0x71;
            break;
        }
        {
        case 1:
            *flags = 0x26;
            unsigned int size = (unsigned int)((float)renderer->NiDX9Renderer_GetScreenWidth() * 0.5);
            if (size < 0x100)
                size = 0x100;
            *width = size;
            *height = 0x100;
            *format = 0x71;
            break;
        }
        {
        case 2:
            *flags = 0x26;
            if (renderer->Group()->Width(0) > 0x500)
            {
                *width = DAT_011f9426 ? DAT_011f9430 / 4 : renderer->Group()->Width(0) / 4;
                *height = DAT_011f9426 ? DAT_011f9434 / 4 : renderer->Group()->Height(0) / 4;
            }
            else
            {
                *height = 0x100;
                *width = 0x100;
            }
            *format = 0x71;
            break;
        }
        {
        case 3:
            if (!DAT_011f9426)
            {
                *width = renderer->NiDX9Renderer_GetScreenWidth();
                *height = renderer->NiDX9Renderer_GetScreenHeight();
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x26;
            *format = 0;
            break;
        }
        {
        case 4:
            if (!DAT_011f9426)
            {
                *width = renderer->NiDX9Renderer_GetScreenWidth();
                *height = renderer->NiDX9Renderer_GetScreenHeight();
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = NiDX9Renderer_GetMultiSampleType(DAT_011f9490) > 0 ? 0x62 : 0x22;
            *format = DAT_011f941e ? 0x71 : 0;
            break;
        }
        {
        case 6:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0);
                *height = renderer->Group()->Height(0);
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 6;
            *format = 0;
            break;
        }
        {
        case 7:
            *height = DAT_01200054;
            *width = DAT_01200054;
            *flags = 6;
            *format = 0x74;
            break;
        }
        {
        case 13:
            *width = DAT_01200054;
            *height = 1;
            *flags = 0xc;
            *format = 0x51;
            break;
        }
        {
        case 14:
            *width = DAT_01200054;
            *height = 0x10;
            *flags = 0xc;
            *format = 0x74;
            break;
        }
        {
        case 15:
            *height = DAT_01200054;
            *width = DAT_01200054;
            *flags = 0xc;
            *format = 0x72;
            break;
        }
        {
        case 17:
            *width = 0x200;
            *height = 0x200;
            *flags = 0x122;
            *format = 0x15;
            break;
        }
        {
        case 18:
            *width = DAT_011ad81c;
            *height = DAT_011ad820;
            *flags = 0xc;
            *format = 0x15;
            break;
        }
        {
        case 19:
            *width = DAT_011ad81c;
            *height = DAT_011ad820;
            *flags = 4;
            *format = 0x15;
            *flags |= 0x20;
            break;
        }
        {
        case 20:
            *width = *height = 0x200;
            *flags = 6;
            *format = 0x71;
            break;
        }
        {
        case 16:
            *height = DAT_01200054;
            *width = DAT_01200054;
            *flags = 0xc;
            *format = 0x74;
            break;
        }
        {
        case 8:
            *width = *height = 0x200;
            *flags = 2;
            *format = 0x24;
            break;
        }
        {
        case 9:
            *width = DAT_011ad814;
            *height = DAT_011ad818;
            *flags = 0x40;
            *format = 0;
            *samples = DAT_011ad810;
            *flags |= 0x20;
            break;
        }
        {
        case 22:
            *width = DAT_011ad814;
            *height = DAT_011ad818;
            *flags = 0x40;
            *format = 0;
            *samples = DAT_011ad810;
            *flags |= 0x20;
            break;
        }
        {
        case 10:
            *width = *height = 0x200;
            *flags = 0x40;
            *format = 0;
            break;
        }
        {
        case 12:
            *width = *height = 0x80;
            *flags = 6;
            *format = 0x24;
            break;
        }
        {
        case 21:
            *height = DAT_01200054;
            *width = DAT_01200054;
            *flags = 4;
            *format = 0;
            break;
        }
        {
        case 23:
            *width = *height = 0x100;
            *flags = 6;
            *format = 0;
            break;
        }
        {
        case 24:
            if (!DAT_011f9426)
            {
                GroupDispatch* dispatch = reinterpret_cast<GroupReceiver*>(renderer)->dispatch;
                *width = (dispatch->group(renderer, dispatch))->Width(0) / 4;
                *height = renderer->Group()->Height(0) / 4;
            }
            else
            {
                *width = DAT_011f9430 / 4;
                *height = DAT_011f9434 / 4;
            }
            *flags = 6;
            *format = 0;
            break;
        }
        {
        case 26:
        case 27:
            *height = DAT_011adbc8;
            *width = DAT_011adbc8;
            *flags = 6;
            *format = 0;
            break;
        }
        {
        case 31:
            if (!DAT_011f9426)
            {
                *width = renderer->NiDX9Renderer_GetScreenWidth();
                *height = renderer->NiDX9Renderer_GetScreenHeight();
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 6;
            if (NiDX9Renderer_GetMultiSampleType(DAT_011f9490) > 0)
                *flags = 0x46;
            *format = 0;
            break;
        }
        {
        case 32:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0);
                *height = renderer->Group()->Height(0);
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x42;
            *format = DAT_011ad80e ? 0x71 : 0x15;
            break;
        }
        {
        case 33:
            if (!DAT_011f9426)
            {
                *width = renderer->NiDX9Renderer_GetScreenWidth();
                *height = renderer->NiDX9Renderer_GetScreenHeight();
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 2;
            *format = DAT_011ad80e ? 0x72 : 0x15;
            break;
        }
        {
        case 25:
        case 34:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0);
                *height = renderer->Group()->Height(0);
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x26;
            *format = 0;
            break;
        }
        {
        case 35:
        case 36:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0);
                *height = renderer->Group()->Height(0);
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x42;
            *format = 0x15;
            break;
        }
        {
        case 37:
        case 38:
        case 40:
            if (!DAT_011f9426)
            {
                *width = renderer->NiDX9Renderer_GetScreenWidth() / 4;
                *height = renderer->NiDX9Renderer_GetScreenHeight() / 4;
            }
            else
            {
                *width = DAT_011f9430 / 4;
                *height = DAT_011f9434 / 4;
            }
            *flags = 6;
            *format = 0x15;
            break;
        }
        {
        case 39:
            if (!DAT_011f9426)
            {
                *width = renderer->NiDX9Renderer_GetScreenWidth();
                *height = renderer->NiDX9Renderer_GetScreenHeight();
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 2;
            *format = 0x15;
            break;
        }
        {
        case 5:
            if (!DAT_011f9426)
            {
                *width = renderer->NiDX9Renderer_GetScreenWidth();
                *height = renderer->NiDX9Renderer_GetScreenHeight();
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x22;
            *format = 0x71;
            break;
        }
        {
        case 41:
            *width = *height = 0x100;
            *flags = 2;
            *format = 0;
            break;
        }
        {
        case 42:
            *width = *height = 0x200;
            *flags = 6;
            *format = 0x72;
            break;
        }
        {
        case 43:
            *width = *height = DAT_011ad830;
            *flags = 6;
            *format = DAT_011ad870;
            break;
        }
        {
        case 44:
            *width = *height = 0x100;
            *flags = 0x10;
            *format = 0;
            break;
        }
        {
        case 45:
        case 49:
            *width = 0x500;
            TargetGroup* pHeightGroup = renderer->Group();
            TargetGroup* pWidthGroup = renderer->Group();
            *height = (unsigned int)((float)pHeightGroup->Height(0) / (float)pWidthGroup->Width(0) * (float)*width);
            *flags = 4;
            *format = 0;
            break;
        }
        {
        case 46:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0) / 2;
                *height = renderer->Group()->Height(0) / 2;
            }
            else
            {
                *width = DAT_011f9430 / 2;
                *height = DAT_011f9434 / 2;
            }
            *flags = 4;
            *format = 0;
            break;
        }
        {
        case 47:
            if (!DAT_011f9426)
            {
                *width = renderer->NiDX9Renderer_GetScreenWidth();
                *height = renderer->NiDX9Renderer_GetScreenHeight();
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x40;
            *format = 0;
            break;
        }
        {
        case 48:
            *width = 0x500;
            TargetGroup* pHeightGroup = renderer->Group();
            TargetGroup* pWidthGroup = renderer->Group();
            *height = (unsigned int)((float)pHeightGroup->Height(0) / (float)pWidthGroup->Width(0) * (float)*width);
            *flags = 0x40;
            *format = 0;
            break;
        }
        {
        case 50:
            *width = *height = 0x100;
            *flags = 4;
            *format = 0;
            break;
        }
        {
        case 51:
            *width = *height = 8;
            *flags = 0;
            *format = 0;
            break;
        }
        {
        case 29:
        case 30:
            *width = *height = DAT_012004fc ? 0x200 : 0x80;
            *flags = 0;
            *format = 0x17;
            break;
        }
        {
        case 28:
            *width = *height = DAT_012004fc ? 0x200 : 0x80;
            *flags = 4;
            *format = 0x17;
            break;
        }
    }
    if (!(*flags & 0x40))
        *samples = 0;
}

struct B6F930Props
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_usFlags;
};

struct B6F930Geom
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
    B6F930Props* m_pkProps;
};

struct B6F930PassArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iArrayLength;
    void Add(B6F930Geom* pkGeom, int iPass, int a3, int a4, int a5, int a6, int a7, int a8);
};

struct B6F930Shader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m_uiFlags20;
    unsigned int m_uiFlags24;
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
    B6F930PassArray* m_pkPasses;
    void ClearPassTextureSlots(int a);
    B6F930PassArray* AddGeomPass(B6F930Geom* pkGeom);
};

// @fnv 0x00b6f930
B6F930PassArray* B6F930Shader::AddGeomPass(B6F930Geom* pkGeom)
{
    bool bPropsFlag = false;
    if (pkGeom->m_pkProps)
        bPropsFlag = (pkGeom->m_pkProps->m_usFlags >> 9) & 1;
    bool bAlt = (m_uiFlags24 & 0x20) > 0;
    ClearPassTextureSlots(1);
    if (m_pkPasses->m_iArrayLength == 0)
    {
        if (bAlt)
        {
            if (bPropsFlag)
            {
                if ((m_uiFlags20 & 2) > 0)
                    m_pkPasses->Add(pkGeom, 0x2ef, 0, 0, 0, 0, 0, 0);
                else
                    m_pkPasses->Add(pkGeom, 0x2ee, 0, 0, 0, 0, 0, 0);
            }
            else
            {
                if ((m_uiFlags20 & 2) > 0)
                    m_pkPasses->Add(pkGeom, 0x2e9, 0, 0, 0, 0, 0, 0);
                else
                    m_pkPasses->Add(pkGeom, 0x2e8, 0, 0, 0, 0, 0, 0);
            }
        }
        else
        {
            if (bPropsFlag)
            {
                if ((m_uiFlags20 & 2) > 0)
                    m_pkPasses->Add(pkGeom, 0x2e3, 0, 0, 0, 0, 0, 0);
                else
                    m_pkPasses->Add(pkGeom, 0x2e2, 0, 0, 0, 0, 0, 0);
            }
            else
            {
                if ((m_uiFlags20 & 2) > 0)
                    m_pkPasses->Add(pkGeom, 0x2dd, 0, 0, 0, 0, 0, 0);
                else
                    m_pkPasses->Add(pkGeom, 0x2dc, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    return m_pkPasses;
}

// 0x00b7af80 calls 0x00c663d0 for the default pair but inlines the
// special pair's assignment. This ABI adapter owns no pointer or class layout;
// it names only the original out-of-line operation on a shared NiPointer.
struct OutlinedShaderReferenceAssignment
{
    NiPointer<NiRefObject>& Assign(const NiPointer<NiRefObject>& other);
};


struct MyContext
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
    NiPointer<NiRefObject> unk30;
    NiPointer<NiRefObject> unk34;
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
    NiPointer<NiRefObject> unk7c;
    NiPointer<NiRefObject> unk80;
    NiPointer<NiRefObject> unk84;
    NiPointer<NiRefObject> unk88;
};

struct StagePropSub
{
    void SetNodeValue(int prop, int val, int flag);
};

extern "C" StagePropSub* __cdecl FUN_00e7f5d0();

struct StageMgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int unk18;
    int unk1c;
    int unk20;
    TexStageStub** m_pElems;
    int unk28;
    int unk2c;
    StagePropSub* unk30;

    void SetProperty(int prop, int val)
    {
        if (!unk30)
        {
            unk30 = FUN_00e7f5d0();
        }
        unk30->SetNodeValue(prop, val, 1);
    }

    void NiD3DPass_SetRenderState(int a, int b, int c);
};

MyContext* __cdecl BSShaderManager_GetShader(int id);
void __cdecl SetShaderConstantMapEntryFlags(int a1);
void __cdecl UpdateFlagHolders(int a1);

extern StageMgr* DAT_011fdff8[];
extern int DAT_011f91c0;
extern unsigned short DAT_011f941c;
extern unsigned int DAT_011f91b8;
extern unsigned int DAT_011f9534;
extern V4 DAT_011fa2f0;
extern V4 DAT_011ad850;

// Looks up contexts 1, 14, 15 and 13 and copies their unk7c/unk80 or unk84/unk88 into unk30/unk34 based on a1, then sets properties on DAT_011fdff8[a1].
// @fnv 0x00b7a870
// src: COMMUNITY 0x00b7a870
void __cdecl ShadowLightShader_EnableConstantsForPass(unsigned int uiStageId)
{
    MyContext* p1 = BSShaderManager_GetShader(1);
    MyContext* pContext14 = BSShaderManager_GetShader(14);
    MyContext* pContext15 = BSShaderManager_GetShader(15);
    MyContext* pContext13 = BSShaderManager_GetShader(13);

    if (uiStageId - 0x24e <= 3)
    {
        if (p1)
        {
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&p1->unk30)->Assign(p1->unk7c);
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&p1->unk34)->Assign(p1->unk80);
        }
        if (pContext14)
        {
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext14->unk30)->Assign(pContext14->unk7c);
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext14->unk34)->Assign(pContext14->unk80);
        }
        if (pContext15)
        {
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext15->unk30)->Assign(pContext15->unk7c);
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext15->unk34)->Assign(pContext15->unk80);
        }
        if (pContext13)
        {
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext13->unk30)->Assign(pContext13->unk7c);
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext13->unk34)->Assign(pContext13->unk80);
        }
    }
    else
    {
        if (p1)
        {
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&p1->unk30)->Assign(p1->unk84);
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&p1->unk34)->Assign(p1->unk88);
        }
        if (pContext14)
        {
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext14->unk30)->Assign(pContext14->unk84);
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext14->unk34)->Assign(pContext14->unk88);
        }
        if (pContext15)
        {
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext15->unk30)->Assign(pContext15->unk84);
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext15->unk34)->Assign(pContext15->unk88);
        }
        if (pContext13)
        {
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext13->unk30)->Assign(pContext13->unk84);
            reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pContext13->unk34)->Assign(pContext13->unk88);
        }

        if (DAT_011f91c0 >= 2)
        {
            SetShaderConstantMapEntryFlags(uiStageId);
        }
        else if (DAT_011f91c0 == 1)
        {
            UpdateFlagHolders(uiStageId);
        }
    }

    if (uiStageId < 0x2f7)
    {
        DAT_011fdff8[uiStageId]->SetProperty(0x1c, 0);

        if ((DAT_011f941c & 1) > 0)
        {
            DAT_011fdff8[uiStageId]->SetProperty(0xa8, 0);
        }
        else
        {
            if ((uiStageId >= 0x1e2 && uiStageId <= 0x1e6) || (uiStageId - 0x1ec) <= 2)
            {
                DAT_011fdff8[uiStageId]->NiD3DPass_SetRenderState(0xa8, 15, 0);
            }
            else if (uiStageId - 0x154 <= 0x23)
            {
                DAT_011fdff8[uiStageId]->NiD3DPass_SetRenderState(0xa8, 15, 0);
            }
            else if (uiStageId == 0x2d6 || uiStageId == 0x2d7 || uiStageId == 0x14 || uiStageId == 0x15)
            {
                DAT_011fdff8[uiStageId]->NiD3DPass_SetRenderState(0xa8, 8, 0);
            }
            else if (uiStageId - 1 <= 4)
            {
                DAT_011fdff8[uiStageId]->NiD3DPass_SetRenderState(0xa8, 0, 0);
            }
            else if (uiStageId - 6 <= 2)
            {
                DAT_011fdff8[uiStageId]->NiD3DPass_SetRenderState(0xa8, 15, 0);
            }
            else if (uiStageId == 9)
            {
                DAT_011fdff8[uiStageId]->NiD3DPass_SetRenderState(0xa8, 0, 0);
            }
            else
            {
                DAT_011fdff8[uiStageId]->NiD3DPass_SetRenderState(0xa8, 7, 0);
            }
        }

        if (DAT_011f91b8 == 6)
        {
            DAT_011fdff8[uiStageId]->SetProperty(0x34, 1);
            DAT_011fdff8[uiStageId]->SetProperty(0x38, 8);
            DAT_011fdff8[uiStageId]->SetProperty(0x37, 7);
            DAT_011fdff8[uiStageId]->SetProperty(0x35, 1);
            DAT_011fdff8[uiStageId]->SetProperty(0x36, 1);
        }

        if (uiStageId != 0x235)
        {
            for (unsigned int i = 0; i < DAT_011fdff8[uiStageId]->unk18; ++i)
            {
                TexStageStub* stage = DAT_011fdff8[uiStageId]->m_pElems[i];
                if (stage && stage->m_08 && stage->m_08 != DAT_011f9534 && i != 7)
                {
                    stage->ApplyPairToState(3);
                }
            }
        }
    }

    if (uiStageId == 0x235)
    {
        DAT_011fa2f0 = DAT_011ad850;
    }
}

namespace fnv_00b7af80 {
extern int DAT_011fdff8[];
struct ShaderSelector
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
    NiPointer<NiGPUProgram> program;
    int unk2c;
    NiPointer<NiRefObject> vertex;
    NiPointer<NiRefObject> pixel;
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
    NiGPUProgram* defaultProgram;
    NiGPUProgram* mainProgram;
    NiGPUProgram* specialProgram;
    NiGPUProgram* alternateProgram;
    NiPointer<NiRefObject> specialVertex;
    NiPointer<NiRefObject> specialPixel;
    NiPointer<NiRefObject> defaultVertex;
    NiPointer<NiRefObject> defaultPixel;
    void SelectShaderProgram(unsigned int mode);
};
// Looks up DAT_011fdff8[mode] into DAT_0126f74c, picks program/vertex/pixel shader pointers by mode, using special shaders for modes 592 and 593.
// @fnv 0x00b7af80
void ShaderSelector::SelectShaderProgram(unsigned int mode)
{
    DAT_0126f74c = DAT_011fdff8[mode];
    switch (mode)
    {
    case 97:
    case 254:
    case 267:
    case 489:
        program = specialProgram;
        break;
    case 3:
    case 5:
    case 8:
    case 18:
    case 19:
    case 21:
    case 92:
    case 93:
    case 94:
    case 95:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 125:
    case 137:
    case 138:
    case 139:
    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
    case 145:
    case 146:
    case 155:
    case 156:
    case 157:
    case 166:
    case 167:
    case 168:
    case 177:
    case 178:
    case 179:
    case 188:
    case 189:
    case 190:
    case 198:
    case 199:
    case 205:
    case 206:
    case 212:
    case 213:
    case 220:
    case 221:
    case 229:
    case 230:
    case 238:
    case 239:
    case 247:
    case 248:
    case 261:
    case 262:
    case 265:
    case 273:
    case 274:
    case 277:
    case 284:
    case 285:
    case 288:
    case 295:
    case 296:
    case 299:
    case 302:
    case 303:
    case 309:
    case 310:
    case 315:
    case 316:
    case 321:
    case 322:
    case 327:
    case 328:
    case 333:
    case 335:
    case 336:
    case 338:
    case 342:
    case 343:
    case 349:
    case 350:
    case 355:
    case 356:
    case 361:
    case 362:
    case 367:
    case 368:
    case 373:
    case 374:
    case 483:
    case 486:
    case 488:
    case 491:
    case 493:
    case 562:
    case 582:
    case 583:
    case 585:
    case 591:
    case 593:
    case 596:
    case 597:
    case 727:
    case 729:
    case 735:
    case 741:
    case 747:
        program = mainProgram;
        break;
    case 147:
    case 148:
    case 495:
    case 496:
    case 497:
    case 498:
    case 499:
    case 500:
    case 501:
    case 502:
    case 503:
    case 504:
    case 505:
    case 506:
    case 507:
    case 508:
    case 509:
    case 510:
    case 511:
    case 512:
    case 513:
    case 514:
    case 515:
    case 516:
    case 517:
    case 518:
    case 519:
    case 520:
    case 521:
    case 522:
    case 523:
    case 524:
    case 525:
    case 526:
    case 527:
    case 528:
    case 529:
    case 530:
    case 531:
    case 532:
    case 533:
    case 534:
    case 535:
    case 536:
    case 537:
    case 538:
    case 539:
    case 540:
    case 541:
    case 542:
    case 543:
    case 544:
    case 545:
    case 546:
    case 547:
    case 548:
    case 549:
    case 550:
    case 551:
    case 552:
    case 553:
    case 554:
    case 555:
    case 556:
    case 557:
    case 558:
    case 559:
    case 560:
    case 563:
        program = alternateProgram;
        break;
    default:
        program = defaultProgram;
        break;
    }
    if (mode == 592 || mode == 593)
    {
        vertex = specialVertex;
        pixel = specialPixel;
    }
    else
    {
        reinterpret_cast<OutlinedShaderReferenceAssignment*>(&vertex)->Assign(defaultVertex);
        reinterpret_cast<OutlinedShaderReferenceAssignment*>(&pixel)->Assign(defaultPixel);
    }
}
}  // namespace fnv_00b7af80

// Member function: looks up the texture stage for index a2 on the global renderer, assigns it the
// value computed by a sibling member called on this (keeps ecx live), then applies it.
struct ShaderStageSetter
{
    unsigned int ShadowLightShader_GetCubeMap(int a, int b);
    void ShadowLightShader_SetCubeMap(int a1, int a2, int a3);
};
// Looks up the texture stage at index a2, stores the result of FUN_00c02f30(a1, a3) in its m_08 field, then calls ApplyPairToState(0) on it.
// @fnv 0x00b7c290
// src: COMMUNITY 0x00b7c290
void ShaderStageSetter::ShadowLightShader_SetCubeMap(int a1, int aiStageIndex, int a3)
{
    TexStageStub* elem = (TexStageStub*)((SlotGlobal*)DAT_0126f74c)->m_24[aiStageIndex];
    elem->m_08 = ShadowLightShader_GetCubeMap(a1, a3);
    elem->ApplyPairToState(0);
}

template <> inline ShaderBufferMapBase::~NiTMapBase()
{
    RemoveAll();
    NiFreeAlias(m_ppkHashTable);
}

// @fnv 0x00b7fbe0
template <> NiTPointerMap<const char*, ShaderBufferRecord*>::~NiTPointerMap()
{
    RemoveAll();
}

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = g_tlsMemContext;
        g_tlsMemContext = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        g_tlsMemContext = m_iSaved;
    }
};

#include "../../include/NiMemObject.h"

class FUN_00b60cb0_Clone : public NiMemObject
{  // clone type, ctor at 0x00b60cb0
  public:
    FUN_00b60cb0_Clone();
    char unk00[0x98];
};

class CloneSource
{
  public:
    void CloneTo(FUN_00b60cb0_Clone* pkClone, void* pvCloningProcess);  // CopyMemberData
    FUN_00b60cb0_Clone* CloneObject(void* pvCloningProcess);
};

// Allocates a FUN_00b60cb0_Clone, runs CloneTo on it with pvCloningProcess, and returns the clone.
// @fnv 0x00b60e80
FUN_00b60cb0_Clone* CloneSource::CloneObject(void* pvCloningProcess)
{
    MemContextGuard kGuard(0x1c);
    FUN_00b60cb0_Clone* pkClone = new FUN_00b60cb0_Clone;
    CloneTo(pkClone, pvCloningProcess);
    return pkClone;
}

struct CopyObject;

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct CopyBase
{
    void CopyBaseFields(CopyObject*, int);
};
struct CopyNode
{
    CopyNode* next;
    CopyNode* prev;
    void* data;
};
struct CopyList
{
    CopyNode* head;
    CopyNode* tail;
    unsigned count;
    void RemoveAll();
};
extern unsigned DAT_011c5f80;
extern unsigned DAT_011c5f84;
extern CopyNode* DAT_011c5f58;
void GrowPool();
struct CopyObject : CopyBase
{
    unsigned f000;
    unsigned f004;
    unsigned f008;
    unsigned f00c;
    unsigned f010;
    unsigned f014;
    unsigned f018;
    unsigned f01c;
    unsigned f020;
    unsigned f024;
    unsigned f028;
    unsigned f02c;
    unsigned f030;
    unsigned f034;
    unsigned f038;
    unsigned f03c;
    unsigned f040;
    unsigned f044;
    unsigned f048;
    unsigned f04c;
    unsigned f050;
    unsigned f054;
    unsigned f058;
    unsigned f05c;
    unsigned char f060;
    unsigned char f061;
    unsigned char f062;
    unsigned char f063;
    unsigned f064;
    unsigned f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    unsigned char f07c;
    unsigned char f07d;
    unsigned char f07e;
    unsigned char f07f;
    unsigned char f080;
    unsigned char f081;
    unsigned char f082;
    unsigned char f083;
    unsigned f084;
    unsigned f088;
    unsigned f08c;
    unsigned f090;
    unsigned f094;
    unsigned f098;
    unsigned f09c;
    unsigned f0a0;
    unsigned f0a4;
    unsigned f0a8;
    unsigned f0ac;
    unsigned f0b0;
    unsigned f0b4;
    unsigned f0b8;
    unsigned f0bc;
    unsigned f0c0;
    unsigned f0c4;
    unsigned f0c8;
    unsigned f0cc;
    unsigned f0d0;
    unsigned f0d4;
    unsigned f0d8;
    unsigned f0dc;
    unsigned f0e0;
    unsigned f0e4;
    unsigned f0e8;
    unsigned f0ec;
    unsigned f0f0;
    unsigned f0f4;
    unsigned f0f8;
    unsigned f0fc;
    unsigned f100;
    unsigned f104;
    unsigned f108;
    unsigned f10c;
    unsigned f110;
    unsigned f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    CopyList list;
    unsigned f134;
    NiRefObject* f138;
    NiRefObject* f13c;
    NiRefObject* f140;
    NiRefObject* f144;
    NiRefObject* f148;
    void WaterShaderProperty_CopyMembers(CopyObject* dst, int arg);
};
static __forceinline void AssignRef(NiRefObject*& dst, NiRefObject* const& src)
{
    NiRefObject* old = dst;
    if (old != src)
    {
        if (old && !InterlockedDecrement((volatile long*)&old->m_uiRefCount))
            old->DeleteThis();
        dst = src;
        if (dst)
            InterlockedIncrement((volatile long*)&dst->m_uiRefCount);
    }
}
static __forceinline void AppendCopy(CopyList* dest, void* const& value, unsigned count)
{
    void* data = value;
    g_011c5f80.Lock(0);
    NiTAbstractPoolAllocator_unsigned_int::LinkedListEntry* raw = NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList;
    if (!raw)
    {
        GrowPool();
        raw = NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList;
    }
    NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList =
        (NiTAbstractPoolAllocator_unsigned_int::LinkedListEntry*)raw->m_pkNext;
    raw->m_uiSize = 0;
    raw->m_pkNext = 0;
    raw->m_pkPrev = 0;
    if (!(DAT_011c5f84 -= count))
        DAT_011c5f80 = 0;
    CopyNode* item = (CopyNode*)raw;
    item->data = data;
    item->next = 0;
    item->prev = dest->tail;
    if (dest->tail)
    {
        dest->tail->next = item;
        dest->count += count;
    }
    else
    {
        dest->head = item;
        dest->count += count;
    }
    dest->tail = item;
}
// Copies base fields and a fixed set of member values into dst, reassigns the reference-counted pointers, and deep-copies the list into dst->list.
// @fnv 0x00b6a6c0
// src: XBOX_PDB 0x00b6a6c0
void CopyObject::WaterShaderProperty_CopyMembers(CopyObject* dst, int arg)
{
    CopyBaseFields(dst, arg);
    AssignRef(dst->f148, f148);
    dst->f061 = f061;
    dst->f062 = f062;
    dst->f063 = f063;
    dst->f064 = f064;
    dst->f068 = f068;
    dst->f06c = f06c;
    dst->f070 = f070;
    dst->f07d = f07d;
    dst->f07c = f07c;
    dst->f07f = f07f;
    dst->f080 = f080;
    dst->f081 = f081;
    dst->f088 = f088;
    dst->f08c = f08c;
    dst->f090 = f090;
    dst->f094 = f094;
    dst->f098 = f098;
    dst->f09c = f09c;
    dst->f0a0 = f0a0;
    dst->f0a4 = f0a4;
    dst->f0a8 = f0a8;
    dst->f0ac = f0ac;
    dst->f0b0 = f0b0;
    dst->f0b4 = f0b4;
    dst->f0b8 = f0b8;
    dst->f0bc = f0bc;
    dst->f0c0 = f0c0;
    dst->f0c4 = f0c4;
    dst->f0c8 = f0c8;
    dst->f0cc = f0cc;
    dst->f0d0 = f0d0;
    dst->f0d4 = f0d4;
    dst->f0d8 = f0d8;
    dst->f0dc = f0dc;
    dst->f0e0 = f0e0;
    dst->f0e4 = f0e4;
    dst->f0e8 = f0e8;
    dst->f0ec = f0ec;
    dst->f0f0 = f0f0;
    dst->f0f4 = f0f4;
    dst->f0f8 = f0f8;
    dst->f0fc = f0fc;
    dst->f100 = f100;
    dst->f104 = f104;
    dst->f108 = f108;
    dst->f10c = f10c;
    dst->f110 = f110;
    dst->f114 = f114;
    dst->f118 = f118;
    dst->f124 = f124;
    dst->f11c = f11c;
    dst->f120 = f120;
    dst->f074 = f074;
    dst->f078 = f078;
    dst->f082 = f082;
    AssignRef(dst->f13c, f13c);
    AssignRef(dst->f140, f140);
    AssignRef(dst->f138, f138);
    AssignRef(dst->f144, f144);
    dst->f084 = f084;
    dst->f083 = f083;
    CopyList* dest = &dst->list;
    dest->RemoveAll();
    CopyNode* pos = list.head;
    while (pos)
    {
        void*& data = pos->data;
        pos = pos->next;
        if (data)
        {
            AppendCopy(dest, data, 1);
        }
    }
}

struct B6AE60Obj
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
    B6AE60Obj();
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};
// Allocates and constructs a B6AE60Obj via its operator new and returns the new object.
// @fnv 0x00b6ae60
B6AE60Obj* __cdecl CreateB6AE60Obj()
{
    return new B6AE60Obj();
}

extern unsigned char DAT_011ad80c;
extern int DAT_011f953c;
extern int DAT_011f9540;
extern unsigned char DAT_011f9425;
extern int DAT_011f9428;
void __stdcall NiD3DTextureStage_SetFilterMode(int);
typedef void(__stdcall* FUN_00b7c190_VFn)(void*, int, int, int);

// @fnv 0x00b7c190
void __stdcall UpdateSlotFromGlobal(int index)
{
    SlotGlobal* global = (SlotGlobal*)DAT_0126f74c;
    SlotElem* element = global->m_24[index];
    int* source;

    if (DAT_011ad80c)
        source = &DAT_011f953c;
    else
        source = &DAT_011f9540;

    element->m_08 = *source;

    if (DAT_011f9425)
        NiD3DTextureStage_SetFilterMode(7);

    void* object = *(void**)((char*)DAT_011f4748 + 0x288);
    void** vtable = *(void***)object;
    ((FUN_00b7c190_VFn)vtable[69])(object, index, 8, DAT_011f9428);
}

struct FogVector
{
    float x, y, z, w;
    FogVector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
extern unsigned char DAT_011f91c4;
extern FogVector DAT_011fa280[2];
extern const FogVector DAT_011a9bd0;
struct FogDevice
{
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82();
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85();
    virtual void __stdcall slot86();
    virtual void __stdcall slot87();
    virtual void __stdcall slot88();
    virtual void __stdcall slot89();
    virtual void __stdcall slot90();
    virtual void __stdcall slot91();
    virtual void __stdcall slot92();
    virtual void __stdcall slot93();
    virtual long __stdcall SetVertexShaderConstantF(unsigned int, const float*, unsigned int);
};
struct FogRenderState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    FogDevice* device;
    void SetVertexConstants(unsigned int reg, const float* values, unsigned int count)
    {
        device->SetVertexShaderConstantF(reg, values, count);
    }
};
struct FogRenderOwner
{
    unsigned int unk00;
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
    FogRenderState* state;
};
// @fnv 0x00b7c3a0
void UpdateFogShaderConstants()
{
    BSFogProperty* fog = BSShaderManager_GetFogProperty(DAT_011f91c4);
    if (fog)
    {
        float fNearDepth = fog->nearDepth;
        float fFarDepth = fog->farDepth;
        float power = fog->density;
        if (fFarDepth == 0.0f && fNearDepth == 0.0f)
        {
            DAT_011fa280[0] = FogVector(500000.0f, 0.0f, 0.0f, 0.0f);
            DAT_011fa280[1] = DAT_011a9bd0;
        }
        else
        {
            NiColor color = fog->color;
            DAT_011fa280[0] = FogVector(fFarDepth, fFarDepth - fNearDepth, power, 0.0f);
            DAT_011fa280[1] = FogVector(color.r, color.g, color.b, 0.0f);
        }
    }
    FogRenderOwner* owner = reinterpret_cast<FogRenderOwner*>(DAT_0126f74c);
    owner->state->SetVertexConstants(14, &DAT_011fa280[0].x, 2);
}

struct FnvB60150Thunk : FUN_00b6f460_class
{
    void __thiscall TallGrassShaderProperty_LinkObject(NiStream* stream);
};

// @fnv 0x00b60150
// src: COMMUNITY 0x00b60150
void __thiscall FnvB60150Thunk::TallGrassShaderProperty_LinkObject(NiStream* stream)
{
    BSShaderLightingProperty_LinkObject(stream);
}

void __cdecl BSShaderLightingProperty_RegisterStreamables();

// @fnv 0x00b60160
// src: COMMUNITY 0x00b60160
void __cdecl TallGrassShaderProperty_RegisterStreamables()
{
    BSShaderLightingProperty_RegisterStreamables();
}

class FUN_00b60b10 : public NiRefObject
{
  public:
    FUN_00b60b10();
    virtual ~FUN_00b60b10();

    NiPointer<NiRefObject> m_i08;
    int unk0C;
    int unk10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
};
// Initializes the five integer members m_i14 through m_i24 to zero.
// @fnv 0x00b60b10
FUN_00b60b10::FUN_00b60b10()
{
    m_i14 = 0;
    m_i18 = 0;
    m_i1C = 0;
    m_i20 = 0;
    m_i24 = 0;
}

void FUN_004ed900() throw();

// @fnv 0x00b6a510
// src: COMMUNITY 0x00b6a510
void j_DList_Init()
{
    FUN_004ed900();
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct FUN_00b6abb0
{
    FUN_00b6abb0();
    static void* operator new(unsigned int size, unsigned int requestedSize)
    {
        return Object_DispatchCommandFour(requestedSize);
    }
    unsigned int m_type;
};
struct EntityManagerB6
{
    void WaterShaderProperty_CopyMembers(FUN_00b6abb0* object, int context);
    FUN_00b6abb0* CreateObject(int context);
};
// @fnv 0x00b6ade0
FUN_00b6abb0* EntityManagerB6::CreateObject(int context)
{
    FUN_00b6abb0* object = new (0x150) FUN_00b6abb0();
    WaterShaderProperty_CopyMembers(object, context);
    return object;
}

extern NiRTTI DAT_012708e4;

struct FUN_00b6b180_Fmt
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int unk10;
};

struct FUN_00b6b180_Tex
{
    int unk00;
    int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00b6b180_Fmt* unk10;
};

struct FUN_00b6b180_Obj : NiObject
{
    virtual void v8c();
    virtual void v90();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
    virtual void v9c();
    virtual void va0();
    virtual FUN_00b6b180_Tex* GetBuffer();
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
    FUN_00b6b180_Tex* unk4c;
};

FUN_00b6b180_Tex* __cdecl ProcessArgWithObj(FUN_00b6b180_Tex* apTex, NiRenderer* apRenderer);

// @fnv 0x00b6b180
// src: COMMUNITY 0x00b6b180
FUN_00b6b180_Tex* __cdecl BSRenderedTexture_GetDepthStencilBuffer(FUN_00b6b180_Obj* apObj, FUN_00b6b180_Tex* apOther)
{
    if (!IsObjectKindOf(&DAT_012708e4, apObj))
    {
        if (apOther)
        {
            unsigned int uiWidth = apOther->unk08;
            if (uiWidth >= apObj->GetWidth())
            {
                unsigned int uiHeight = apOther->unk0c;
                if (uiHeight >= apObj->GetHeight())
                {
                    unsigned int uiFormat = apOther->unk10 ? apOther->unk10->unk10 : 0;
                    FUN_00b6b180_Tex* pBuffer = apObj->GetBuffer();
                    unsigned int uiBufferFormat = pBuffer->unk10 ? pBuffer->unk10->unk10 : 0;
                    if (uiFormat == uiBufferFormat)
                        return apOther;
                }
            }
        }
        return ProcessArgWithObj(apObj->GetBuffer(), DAT_011f9508);
    }
    FUN_00b6b180_Tex* pTarget = apObj->unk4c;
    if (apOther && apOther->unk08 >= pTarget->unk08 && apOther->unk0c >= pTarget->unk0c)
        return apOther;
    return ProcessArgWithObj(pTarget, DAT_011f9508);
}

struct FUN_00b6fd20_cls
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
    int BSShaderNoLightingProperty_GetDiffuseTexture();
};
// @fnv 0x00b6fd20
// src: COMMUNITY 0x00b6fd20
int FUN_00b6fd20_cls::BSShaderNoLightingProperty_GetDiffuseTexture()
{
    return unk60;
}

extern "C" __declspec(thread) int tls_memContext;

struct MemoryContextGuard
{
    int m_iSaved;
    MemoryContextGuard(int aiMemoryContext)
    {
        m_iSaved = tls_memContext;
        tls_memContext = aiMemoryContext;
    }
    ~MemoryContextGuard()
    {
        tls_memContext = m_iSaved;
    }
};

extern unsigned int DAT_011f9ef4;

struct StringOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short unk10;
    unsigned short m_usNumStrings;
    int unk14;
    const char** m_ppcStrings;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    unsigned int m_uiKeyA;
    unsigned int m_uiKeyB;

    ~StringOwner();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
        --DAT_011f9ef4;
    }
};

template <class T> inline void NiTPointerAllocator<T>::Deallocate(void* pointer)
{
    g_011c5f80.Lock(0);
    typename NiTAbstractPoolAllocator<T>::AllocNode* pkDelNode =
        (typename NiTAbstractPoolAllocator<T>::AllocNode*)pointer;
    pkDelNode->m_pkData = 0;
    pkDelNode->m_pkNext = NiTAbstractPoolAllocator<T>::ms_pkFreeMem;
    NiTAbstractPoolAllocator<T>::ms_pkFreeMem = pkDelNode;
    if (--DAT_011c5f84 == 0)
        DAT_011c5f80 = 0;
}

template <class Allocator, class T> inline void NiTPointerListBase<Allocator, T>::DeleteItem(NiTListItem<T>* pkItem)
{
    pkItem->m_element = 0;
    Allocator allocator;
    allocator.Deallocate(pkItem);
}

template <class Allocator, class T> inline T NiTPointerListBase<Allocator, T>::RemoveHead()
{
    NiTListItem<T>* pkNode = this->m_pkHead;
    this->m_pkHead = this->m_pkHead->m_pkNext;
    if (this->m_pkHead)
        this->m_pkHead->m_pkPrev = 0;
    else
        this->m_pkTail = 0;
    T element = pkNode->m_element;
    DeleteItem(pkNode);
    this->m_kItemCount.m_uiCount--;
    return element;
}

template <class Allocator, class T> inline T NiTPointerListBase<Allocator, T>::RemovePos(void*& kPos)
{
    NiTListItem<T>* pkDelNode = (NiTListItem<T>*)kPos;
    if (pkDelNode == this->m_pkHead)
    {
        kPos = pkDelNode->m_pkNext;
        return RemoveHead();
    }
    if (pkDelNode == this->m_pkTail)
    {
        kPos = 0;
        return RemoveTail();
    }
    NiTListItem<T>* pkPrev = pkDelNode->m_pkPrev;
    NiTListItem<T>* pkNext = pkDelNode->m_pkNext;
    kPos = pkNext;
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;
    T element = pkDelNode->m_element;
    DeleteItem(pkDelNode);
    this->m_kItemCount.m_uiCount--;
    return element;
}

typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*> OwnerList;

struct OwnerListEx : OwnerList
{
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    char* GetNext(void*& kPos) const
    {
        char* const& element = ((NiTListItem<char*>*)kPos)->m_element;
        kPos = ((NiTListItem<char*>*)kPos)->m_pkNext;
        return element;
    }
};

struct OwnerBucket
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    OwnerListEx m_kList;
    int unk2c;
    NiTMap<const char*, B61250Item*> m_kStrings;
};

template <> inline unsigned int OwnerMapBase::GetCount() const
{
    return m_kItemCount.m_uiCount;
}
template <> inline void* OwnerMapBase::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; ++i)
    {
        if (m_ppkHashTable[i])
            return m_ppkHashTable[i];
    }
    return 0;
}

template <> __declspec(noalias) void OwnerMapBase::GetNext(void*&, unsigned int&, OwnerBucket*&) const;

extern OwnerMap* GetArrayHolder();

// Finds and removes the StringOwner with matching m_uiKeyA and m_uiKeyB from the owner map, removing its strings from the bucket's string map.
// @fnv 0x00b61570
// src: COMMUNITY 0x00b61570
void TallGrassShaderProperty_RemoveFromCell(unsigned int a, unsigned int b)
{
    MemoryContextGuard kGuard(0x1c);
    void* kFirst = GetArrayHolder()->GetFirstPos();
    void* kIter = kFirst;
    OwnerBucket* pkBucket = 0;
    if (GetArrayHolder()->GetCount() > 0 && kFirst)
    {
        do
        {
            unsigned int key;
            GetArrayHolder()->GetNext(kIter, key, pkBucket);
            if (pkBucket)
            {
                void* kPos = pkBucket->m_kList.GetHeadPos();
                while (kPos)
                {
                    void* kCur = kPos;
                    StringOwner* pkOwner = (StringOwner*)pkBucket->m_kList.GetNext(kPos);
                    if (pkOwner && a == pkOwner->m_uiKeyA && b == pkOwner->m_uiKeyB)
                    {
                        int m_iScrollPosition = pkOwner->m_usNumStrings;
                        const char** ppcStrings = pkOwner->m_ppcStrings;
                        for (int i = 0; i < m_iScrollPosition; i++)
                            pkBucket->m_kStrings.RemoveAt(ppcStrings[i]);
                        pkBucket->m_kList.RemovePos(kCur);
                        delete pkOwner;
                    }
                }
            }
        } while (kIter);
    }
}

void* __cdecl _NiMalloc_00aa1070(unsigned int);
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
template <> inline NiTMapBase<DFALL<NiTMapItem<const char*, B61250Item*> >, const char*, B61250Item*>::NiTMapBase(unsigned int hashSize)
{
    m_uiHashSize = hashSize;
    m_kItemCount.m_uiCount = 0;
    m_ppkHashTable = (EntryType**)_NiMalloc_00aa1070(hashSize * sizeof(EntryType*));
    FUN_00ec61c0(m_ppkHashTable, 0, m_uiHashSize * sizeof(EntryType*));
}
template <> inline NiTMap<const char*, B61250Item*>::NiTMap(unsigned int hashSize)
    : NiTMapBase<DFALL<NiTMapItem<const char*, B61250Item*> >, const char*, B61250Item*>(hashSize)
{
}
struct B617FloatPart
{
    int first, unused04;
    float x, y, z, w, scale, unused1c;
    B617FloatPart()
    {
        float zero = 0.0f;
        x = zero;
        first = 0;
        w = z = y = zero;
        scale = 1.0f;
    }
};
struct B617IntPart
{
    int index20, index24, index28;
    B617IntPart()
    {
        index28 = 0;
        index20 = 0;
        index24 = 0;
    }
};
struct B617Head
{
    B617FloatPart f;
    B617IntPart i;
    ~B617Head();
};
struct B617Holder
{
    int index2c;
    B617Holder() : index2c(0)
    {}
    ~B617Holder();
};
struct FUN_00b617f0 : B617Head, B617Holder
{
    NiTMap<const char*, B61250Item*> m_map;
    FUN_00b617f0();
};
// @fnv 0x00b617f0
FUN_00b617f0::FUN_00b617f0() : m_map(0x65)
{
}

class NiCamera;
extern NiCamera* DAT_011f917c;

namespace gfxB6BA {
extern NiRenderer* DAT_011f4748;
}

void __cdecl BSShaderManager_SetCurrentAccumulator(BSShaderAccumulator* acc);

// If the surface DAT_011f4748 and camera are set, calls SetFromCamera, sets DAT_011f917c, then FUN_00b54b10(acc), acc->vfn_8C(camera) and acc->vfn_A8().
// @fnv 0x00b6ba20
// src: COMMUNITY 0x00b6ba20
void __cdecl BSShaderUtil_RenderScenePreResolveDepth(NiCamera* camera, BSShaderAccumulator* acc)
{
    if (gfxB6BA::DAT_011f4748 && camera)
    {
        gfxB6BA::DAT_011f4748->SetCurrentCamera(camera);
        DAT_011f917c = camera;
        BSShaderManager_SetCurrentAccumulator(acc);
        acc->StartAccumulating(camera);
        typedef void (__thiscall* Finish)(BSShaderAccumulator*);
        ((Finish*)*(void**)acc)[0x2a](acc);
    }
}


class NiPassB7A
{
  public:
    int unk00;
    int unk04;
    NiTexture* m_texture;
    void ApplyPairToState(void* transform);
};

// Pass selector: 0x00b7ad00 reads a ushort at +0x04; NiProperty has its NiObjectNET base there.
struct ShaderPassSelector
{
    int unk00;
    unsigned short m_type;
};

// Projected-texture data: 0x00b7ad00 reads texture +0x6C and stage +0x70; NiMaterial only has its NiRefObject base.
struct ProjectedTextureData
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68;
    NiTexture* m_texture;
    int m_stage;
};

// Texture-effect property view: data +0xDC (BSShaderPPLightingProperty::spTexEffectData), virtual +0xE0; NiGeometry ends at +0xC4.
class TextureEffectPropertyView
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void* GetWorldTransform();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8;
    ProjectedTextureData* m_pTextureEffectData;
};

extern NiTexture* DAT_011f952c;

void BSRenderState_SetAlphaTestEnable(bool enable, int mode);
void BSRenderState_SetAlphaTestFuncRef(int stage, int value, int flags);

class FUN_00b7ad00_Class
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void RestoreState();

    void ShadowLightShader_UpdatePipelineZOnlyTexEffect(void* unused, TextureEffectPropertyView* geom, ShaderPassSelector* prop);
};

// Takes the DAT_011fdff8 entry for prop->m_type, sets its pass texture from geom's material or DAT_011f952c, applies the world transform, and calls RestoreState.
// @fnv 0x00b7ad00
// src: COMMUNITY 0x00b7ad00
void FUN_00b7ad00_Class::ShadowLightShader_UpdatePipelineZOnlyTexEffect(void* unused, TextureEffectPropertyView* geom, ShaderPassSelector* prop)
{
    if (!prop)
        return;
    StageMgr* shader = DAT_011fdff8[prop->m_type];
    ProjectedTextureData* material = geom->m_pTextureEffectData;
    if (!material)
        return;
    NiPassB7A* pass = reinterpret_cast<NiPassB7A*>(*shader->m_pElems);
    if (material->m_texture)
        pass->m_texture = material->m_texture;
    else
        pass->m_texture = DAT_011f952c;
    pass->ApplyPairToState(geom->GetWorldTransform());
    BSRenderState_SetAlphaTestEnable(true, 0);
    BSRenderState_SetAlphaTestFuncRef(4, material->m_stage, 0);
    RestoreState();
    DAT_0126f74c = reinterpret_cast<int>(shader);
}

// @fnv 0x00b606e0
// src: COMMUNITY 0x00b606e0
unsigned char __cdecl ThisCall_Ret1()
{
    return 1;
}


class TexturePool_b60d
{
  public:
    void MemoryManager_Deallocate(void* pvHandle);
};
extern TexturePool_b60d g_kTexturePoolB60D;

struct PooledTexture_b60d
{
    void* m_pvHandle;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
    ~PooledTexture_b60d()
    {
        if (m_pvHandle)
            g_kTexturePoolB60D.MemoryManager_Deallocate(m_pvHandle);
        m_pvHandle = 0;
        m_usSecondValue = 0;
        m_usFirstValue = 0;
    }
};

class ShaderBase_b60d
{
  public:
    virtual void v00();
    ~ShaderBase_b60d();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
};

class FUN_00b60d80 : public ShaderBase_b60d
{
  public:
    virtual void v00();
    ~FUN_00b60d80();
    int m_iTextureIndex;
    NiPointer<NiRefObject> m_spTexture0;
    NiPointer<NiRefObject> m_spTexture1;
    PooledTexture_b60d m_kPooled;
};

// Destructor that resets m_spTexture0 to null and m_iTextureIndex to zero.
// @fnv 0x00b60d80
FUN_00b60d80::~FUN_00b60d80()
{
    m_spTexture0 = 0;
    m_iTextureIndex = 0;
}

struct FUN_00b63320_Property
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_type;
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
    float m_vScale;
};

struct FUN_00b71360_water;

struct FUN_00b63320_Geometry
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37(NiRenderer* surface);

    FUN_00b63320_Property* FUN_00a59d30(unsigned int type);
};

struct FUN_00b63320_Pass
{
    FUN_00b63320_Geometry* m_pSourceGeometry;
    int unk04;
    unsigned char unk08;
    unsigned char m_numLights;
    unsigned short unk0a;
    FUN_00b71360_water** m_ppLights;
};

extern unsigned char DAT_011f94a6;
extern unsigned char DAT_011f91a7;
extern FogVector DAT_011fa0d0;
void __cdecl FUN_00bbb840();
void __cdecl ResetColorSlots(int);
void __cdecl BSShaderLightingProperty_SetLight(unsigned int index, FUN_00b71360_water* light, float scale);

// @fnv 0x00b63320
// src: COMMUNITY 0x00b63320
void __cdecl BSShaderAccumulator_RenderPassImmediately(FUN_00b63320_Pass* pass, unsigned int pixelShader)
{
    NiRenderer* surface = DAT_011f4748;
    DAT_011f91e4 = pixelShader;
    DAT_011f91e0 = (S_00b7c120_Global2*)pass;
    FUN_00b63320_Property* prop = pass->m_pSourceGeometry->FUN_00a59d30(3);
    if (prop)
    {
        switch (prop->m_type)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12: {
            float scale = prop->m_vScale;
            if (DAT_011f94a6)
                FUN_00bbb840();
            if ((pixelShader < 0x10 || pixelShader > 0x13) && pixelShader != 0x1c8 && pixelShader != 0x1ca &&
                pixelShader != 0x1c9 && pixelShader != 0x1cb)
                ResetColorSlots(0);
            for (unsigned char i = 0; i < pass->m_numLights; ++i)
                BSShaderLightingProperty_SetLight(i, pass->m_ppLights[i], scale);
            if (DAT_011f91a7)
                DAT_011fa0d0 = DAT_011a9bd0;
            break;
        }
        }
    }
    pass->m_pSourceGeometry->vf37(surface);
}

class BB63F90Shader;

struct BB63F90Pass
{

    int unk00;

    unsigned short m_usPassCount;
};

struct BB63F90PassArray
{

    int unk00;

    BB63F90Pass** m_ppkPasses;

    int unk08;

    int unk0C;

    unsigned int m_uiCount;
};

class BB63F90Geometry
{

  public:
    virtual void VFunc00();

    virtual void VFunc04();

    virtual void VFunc08();

    virtual void VFunc0C();

    virtual void VFunc10();

    virtual void VFunc14();

    virtual void VFunc18();

    virtual void VFunc1C();

    virtual void VFunc20();

    virtual void VFunc24();

    virtual void VFunc28();

    virtual void VFunc2C();

    virtual void VFunc30();

    virtual void VFunc34();

    virtual void VFunc38();

    virtual void VFunc3C();

    virtual void VFunc40();

    virtual void VFunc44();

    virtual void VFunc48();

    virtual void VFunc4C();

    virtual void VFunc50();

    virtual void VFunc54();

    virtual void VFunc58();

    virtual void VFunc5C();

    virtual void VFunc60();

    virtual void VFunc64();

    virtual void VFunc68();

    virtual void VFunc6C();

    virtual void VFunc70();

    virtual void VFunc74();

    virtual void VFunc78();

    virtual void VFunc7C();

    virtual void VFunc80();

    virtual void VFunc84();

    virtual void VFunc88();

    virtual void VFunc8C();

    virtual void VFunc90();

    virtual void VFunc94();

    virtual void VFunc98();

    virtual void VFunc9C();

    virtual BB63F90PassArray* CreateRenderPasses(int iArg, unsigned int uiFlags, unsigned int* puiCount, void* pvCamera,
                                                 BSShaderAccumulator* pkAccum, bool bFlag);
};

// include/ has the renderer layout, but does not yet declare its next
// virtual slot. Extend that API locally without repeating the renderer layout.
class BatchRendererSubmission : public BSBatchRenderer
{
public:
    virtual void SubmitPass(BB63F90Pass* pass, unsigned int count);
};
static __forceinline void* BatchCamera(const BSShaderAccumulator* accumulator)
{
    return *(void* const*)&accumulator->eRenderMode;
}

extern unsigned int g_uiB63F90PassFlags;

extern __declspec(thread) unsigned int DAT_012722bc;

// Creates render passes from pkGeometry and submits each pass with a nonzero pass count to the selected renderer.
// @fnv 0x00b63f90
bool __cdecl AccumulateRenderPasses(BSShaderAccumulator* pkAccum, int iArg, int iUnused, BB63F90Geometry* pkGeometry)

{

    unsigned int ItemUpdateArray = 0;

    BB63F90PassArray* pkPasses =
        pkGeometry->CreateRenderPasses(iArg, *(unsigned int*)&DAT_011f91d8, &ItemUpdateArray, BatchCamera(pkAccum), pkAccum, true);

    if (pkPasses && pkPasses->m_uiCount)
    {

        for (unsigned int i = 0; i < pkPasses->m_uiCount; i++)
        {

            BB63F90Pass* pkPass = pkPasses->m_ppkPasses[i];

            unsigned short usPassCount = pkPass->m_usPassCount;

            if (usPassCount)

                ((BatchRendererSubmission*)pkAccum->pBatchRenderer[DAT_012722bc])->SubmitPass(pkPass, usPassCount);
        }
    }

    return true;
}

struct RSCmdOwnerParam
{
    unsigned int unk00;
    unsigned int unk04;
    float m_fValue;
};
struct RSCmdOwner
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    RSCmdOwnerParam* m_pParam;
};
struct RSCommand
{
    RSCmdOwner* m_pSharedOwner;
    unsigned short m_usId;
    unsigned char m_ucType;
};
struct RSCommandList
{
    void* m_pVtbl;
    RSCommand** m_ppItems;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiCount;
};
struct RSGroup
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
    virtual void Submit(RSCommand* pCmd, unsigned int usId);
    void DispatchToSlot(RSCommand* pCmd, int iMode, int iFlag);
    void SetupStage(RSCommand* pCmd, int iFlag);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    int m_iArrayLength;
    bool m_bModifierActive;
    int IsActive()
    {
        return (m_iArrayLength > 0 && m_bModifierActive) ? 1 : 0;
    }
};
struct RSDirty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiCurrentValue;
};
struct RSPacket
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
    virtual RSCommandList* GetCommands(void* pRef, void* pGlobalForm, unsigned int* puiCount, void* pData, void* pSettings,
                                       int iFlag);
    virtual void vA4();
    virtual RSCommandList* GetExtraCommands();
    virtual RSCommand* GetCommand(void* pRef);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int m_uiValue1;
    unsigned int m_uiFlags2;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int m_uiStamp;
    RSDirty* m_pDirty;
    int GetBit(const unsigned int& ruiFlags, unsigned int uiMask)
    {
        return (ruiFlags & uiMask) > 0;
    }
    void SetBit(unsigned int& ruiFlags, unsigned int uiMask)
    {
        if (!(ruiFlags & uiMask))
            m_uiStamp = 0;
        ruiFlags |= uiMask;
    }
    void ClearBit(unsigned int& ruiFlags, unsigned int uiMask)
    {
        if (ruiFlags & uiMask)
            m_uiStamp = 0;
        ruiFlags &= ~uiMask;
    }
};
struct RSResponse
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    int m_iType;
};
struct RSNode
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
    virtual void Update();
};
struct RSEffect
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    RSNode* m_pNode30;
    RSNode* m_pNode34;
};
struct RSSettings
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned short unk38;
    bool m_bSubmitExtra;
    bool unk3B;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    bool m_bAlt;
    bool m_bExtra;
    bool unk86;
    bool unk87;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    bool m_bSkipShadow;
    bool unk165;
    bool m_bLodTest;
    bool unk167;
    int m_iLodLevel;
    bool m_bDecals;
    bool unk16D;
    bool unk16E;
    bool unk16F;
    unsigned int unk170;
    RSGroup* m_apGroups[6];
    unsigned int m_uiGroupCount;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    void* m_pData;
};
struct RSThreadData
{
    unsigned int unk00;
};
struct TLSData
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int m_uiThreadIndex;
};
extern __declspec(thread) TLSData g_tlsData;
extern RSCmdOwnerParam DAT_011f4288;
struct RSHelpers
{
    static RSEffect* __cdecl BSShaderManager_GetShader(int aiSoundId);
    static void __cdecl ShadowLightShader_EnableConstantsForPass(unsigned int uiId, int iFlag);
    static void __cdecl BSShaderAccumulator_RenderPassImmediately(RSCommand* pCmd, unsigned int uiId);
};

// Dispatches RSCommands from pPacket to the current thread's RSGroup slot, applying LOD and settings filters, and handles extra commands when enabled.
// @fnv 0x00b64020
bool __cdecl ProcessCommands(RSSettings* pSettings, void* pRef, void* pUnused, RSPacket* pPacket, RSResponse* pResponse)
{
    if (pSettings->m_bSkipShadow && pResponse->m_iType == 13)
        return true;
    if (pSettings->m_bSubmitExtra)
    {
        RSCommand* pCmd = pPacket->GetCommand(pRef);
        if (pCmd)
        {
            if (pSettings->m_bExtra)
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 12, 0);
            else
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 11, 0);
        }
    }
    RSGroup* pGroup = pSettings->m_apGroups[g_tlsData.m_uiThreadIndex % pSettings->m_uiGroupCount];
    if (pGroup->IsActive() != pPacket->GetBit(pPacket->m_uiValue1, 0x200))
    {
        if (pGroup->IsActive())
            pPacket->SetBit(pPacket->m_uiValue1, 0x200);
        else
            pPacket->ClearBit(pPacket->m_uiValue1, 0x200);
        if (pPacket->m_pDirty)
            pPacket->m_pDirty->m_uiCurrentValue = 0;
    }
    unsigned int i;
    unsigned int ItemUpdateArray = 0;
    RSCommandList* pList =
        pPacket->GetCommands(pRef, *(void**)&DAT_011f91d8, &ItemUpdateArray, pSettings->m_pData, pSettings, 1);
    if (pSettings->m_bExtra)
        pPacket->SetBit(pPacket->m_uiFlags2, 0x40);
    else
        pPacket->ClearBit(pPacket->m_uiFlags2, 0x40);
    if (pList && pList->m_uiCount)
    {
        for (i = 0; i < pList->m_uiCount; ++i)
        {
            RSCommand* pCmd = pList->m_ppItems[i];
            unsigned short usId = pCmd->m_usId;
            if (!usId)
                continue;
            switch (pCmd->m_ucType)
            {
            case 1:
                if (pSettings->m_bLodTest)
                {
                    RSCmdOwner* pOwner = pCmd->m_pSharedOwner;
                    RSCmdOwnerParam* pParam = pOwner->m_pParam ? pOwner->m_pParam : &DAT_011f4288;
                    if (pParam->m_fValue < pSettings->m_iLodLevel)
                    {
                        pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->SetupStage(pCmd, 1);
                        break;
                    }
                }
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->SetupStage(pCmd, 0);
                break;
            case 2:
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 10, 0);
                break;
            case 3:
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 1, 0);
                break;
            case 4:
                if (pSettings->m_bDecals)
                    pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 2, 1);
                break;
            case 5:
                if (pSettings->m_bDecals)
                    pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 3, 0);
                break;
            case 6:
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 6, 0);
                break;
            case 7:
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 8, 0);
                break;
            case 8:
            case 9:
            case 11:
            case 12:
            case 13:
                break;
            case 10:
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 0, 0);
                break;
            case 14:
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->DispatchToSlot(pCmd, 9, 0);
                break;
            default:
                pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->Submit(pCmd, usId);
                break;
            }
        }
        if (pSettings->m_bExtra && pSettings->m_bAlt)
        {
            pList = pPacket->GetExtraCommands();
            if (pList)
            {
                for (i = 0; i < pList->m_uiCount; ++i)
                {
                    RSCommand* pCmd = pList->m_ppItems[i];
                    if (pSettings->m_bAlt)
                    {
                        pSettings->m_apGroups[g_tlsData.m_uiThreadIndex]->Submit(pCmd, 0);
                    }
                    else
                    {
                        RSEffect* pEffect = RSHelpers::BSShaderManager_GetShader(1);
                        RSHelpers::ShadowLightShader_EnableConstantsForPass(pCmd->m_usId, 0);
                        if (pEffect)
                        {
                            pEffect->m_pNode34->Update();
                            pEffect->m_pNode30->Update();
                        }
                        RSHelpers::BSShaderAccumulator_RenderPassImmediately(pCmd, pCmd->m_usId);
                    }
                }
            }
        }
    }
    return true;
}

extern double _gModifierZero;
struct FUN_00b66700_class
{
    char m_auiShapeKeys[0xe0];
    float m_fE0;
    void SetClamped(float f);
};
inline float Max0(float v)
{
    return (v < _gModifierZero) ? 0.0f : v;
}
inline float Min1(float v)
{
    return (v < 1.0f) ? v : 1.0f;
}
// Stores f clamped to the range [0, 1] into m_fE0.
// @fnv 0x00b66700
void FUN_00b66700_class::SetClamped(float afValue)
{
    m_fE0 = Min1(Max0(afValue));
}

struct Pool_b6c130
{
    void MemoryManager_Deallocate(void* p);
};
extern NiFixedString* DAT_011fa050;
extern NiFixedString* DAT_011fa054;
static inline void DeleteHolder(NiFixedString* p)
{
    if (p)
    {
        p->~NiFixedString();
        ((Pool_b6c130*)&DAT_011f6238)->MemoryManager_Deallocate(p);
    }
}
// Releases the two global string holders and nulls their pointers.
// @fnv 0x00b6c130
void __cdecl ReleaseStringHolders()
{
    DeleteHolder(DAT_011fa050);
    DeleteHolder(DAT_011fa054);
    DAT_011fa050 = 0;
    DAT_011fa054 = 0;
}

// Returns 1 if the high bit is set, otherwise returns the value if it is between 2 and 16, else 0.
// @fnv 0x00b6c200
// src: COMMUNITY 0x00b6c200
int __cdecl NiDX9Renderer_GetMultiSampleType(int aiValue)
{
    if (aiValue & 0x80000000)
        return 1;
    switch (aiValue)
    {
    case 0:
    case 1:
        return 0;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    case 10:
        return 10;
    case 11:
        return 11;
    case 12:
        return 12;
    case 13:
        return 13;
    case 14:
        return 14;
    case 15:
        return 15;
    case 16:
        return 16;
    }
    return 0;
}

struct PooledRenderTarget;

// 0x00b6e110 calls the /Od NiPointer bodies (0x00633c90/0x0045cec0).
// Specialisation declarations keep these operations out of line for this type.
template <> NiPointer<PooledRenderTarget>::NiPointer(PooledRenderTarget* object);
template <> NiPointer<PooledRenderTarget>::~NiPointer();

// Exe 0x00b6e110: unit-local ListNode view; declarations and layout are preserved.
struct BlkListNodeView
{
    BlkListNodeView* m_pkNext;
    BlkListNodeView* m_pkPrev;
    PooledRenderTarget* m_element;
};

struct RefList
{
    BlkListNodeView* m_pkHead;
    BlkListNodeView* m_pkTail;
    unsigned int m_uiCount;
    NiPointer<PooledRenderTarget> RemoveHead();
};

struct RefSet
{
    int unk00;
    int unk04;
    int unk08;
    void Add(const NiPointer<PooledRenderTarget>& p);
    __forceinline void Insert(PooledRenderTarget* obj)
    {
        Add(obj);
    }
};

struct Pool
{
    RefList m_list0;
    RefList m_list1;
    RefList m_list2;
    RefList m_list3;
    RefList m_list4;
    RefSet m_set0;
    RefSet m_set1;
    RefSet m_set2;
    RefSet m_set3;
    RefSet m_set4;

    __declspec(noalias) void Query(unsigned int a, unsigned int type, unsigned int* p0, unsigned int* p1,
                                   unsigned int* p2, unsigned int* p3, unsigned int* p4, unsigned int* p5);
    PooledRenderTarget* Create(unsigned int a, unsigned int p0, unsigned int p1, unsigned int flags, unsigned int p2,
                   unsigned int p3, unsigned int type, unsigned int p5, int zero, unsigned int e);
    __forceinline PooledRenderTarget* CreateNew(unsigned int a, unsigned int type, unsigned int flags, unsigned int e)
    {
        unsigned int p5;
        struct Properties
        {
            unsigned int unused, format, flags, height, width;
        } props;
        Query(a, type, &props.width, &props.height, &props.format, &props.unused, &props.flags, &p5);
        return Create(a, props.width, props.height, props.flags | flags, props.format, props.unused, type, p5, 0, e);
    }
    PooledRenderTarget* BSTextureManager_BorrowRenderedTexture(unsigned int a, unsigned int type, unsigned int flags, unsigned int noReuse, unsigned int e);
};

// With noReuse 0, returns the head of the type's list (adding it to its set) or else CreateNew's result; with noReuse nonzero, returns 0.
// @fnv 0x00b6e110
// src: COMMUNITY 0x00b6e110
PooledRenderTarget* Pool::BSTextureManager_BorrowRenderedTexture(unsigned int a, unsigned int type, unsigned int flags, unsigned int noReuse, unsigned int e)
{
    if (noReuse == 0)
    {
        switch (type)
        {
        case 43:
            if (m_list0.m_uiCount > 0)
            {
                PooledRenderTarget* obj = m_list0.m_pkHead->m_element;
                m_set0.Insert(obj);
                m_list0.RemoveHead();
                return obj;
            }
            break;
        case 17:
            if (m_list1.m_uiCount > 0)
            {
                PooledRenderTarget* obj = m_list1.m_pkHead->m_element;
                m_set1.Insert(obj);
                m_list1.RemoveHead();
                return obj;
            }
            break;
        case 9:
            if (m_list2.m_uiCount > 0)
            {
                PooledRenderTarget* obj = m_list2.m_pkHead->m_element;
                m_set2.Insert(obj);
                m_list2.RemoveHead();
                return obj;
            }
            break;
        case 22:
            if (m_list3.m_uiCount > 0)
            {
                PooledRenderTarget* obj = m_list3.m_pkHead->m_element;
                m_set3.Insert(obj);
                m_list3.RemoveHead();
                return obj;
            }
            break;
        case 19:
            if (m_list4.m_uiCount > 0)
            {
                PooledRenderTarget* obj = m_list4.m_pkHead->m_element;
                m_set4.Insert(obj);
                m_list4.RemoveHead();
                return obj;
            }
            break;
        }
    }
    if (noReuse != 0)
        return 0;
    {
        return CreateNew(a, type, flags, e);
    }
}

extern __declspec(thread) int g_tlsMemContext;
struct PoolGuard
{
    int saved;
    PoolGuard()
    {
        saved = g_tlsMemContext;
        g_tlsMemContext = 32;
    }
    ~PoolGuard()
    {
        g_tlsMemContext = saved;
    }
};
struct PoolGroup
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void Set(int);
};
struct PoolTexture
{
    virtual void slot0();
    virtual void Delete();
    long refs;
    PoolGroup* FUN_00b6b260();
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            Delete();
    }
};
// 0x00b6ee70 inlines releases of active-pool references.
template <> __forceinline NiPointer<PoolTexture>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
struct PoolList
{
    int head, tail;
    unsigned count;
    NiPointer<PoolTexture> PopBack();
    __declspec(noinline) void AddTail(const NiPointer<PoolTexture>& p)
    {
        if (p.m_pObject)
            head = (int)p.m_pObject;
    }
};
// 0x00b6ee70 uses /Od constructor 0x00633c90 and destructor 0x0045cec0
// for available-pool temporaries, while its active-pool references inline them.
// Keep only those ABI endpoints here; storage size comes from shared NiPointer.
struct OutlinedPoolReferenceOperations
{
    void Construct(PoolTexture* object);
    void Destroy();
};
namespace fnv_00b60b50 {
template <> inline InPlaceStorage<NiPointer<PoolTexture> >::InPlaceStorage(void* object)
{
    reinterpret_cast<OutlinedPoolReferenceOperations*>(bytes)->Construct(static_cast<PoolTexture*>(object));
}
template <> inline InPlaceStorage<NiPointer<PoolTexture> >::~InPlaceStorage()
{
    reinterpret_cast<OutlinedPoolReferenceOperations*>(bytes)->Destroy();
}
}
typedef fnv_00b60b50::InPlaceStorage<NiPointer<PoolTexture> > OutlinedPoolReferenceStorage;
struct AvailableNode
{
    AvailableNode* next;
    AvailableNode* prev;
    PoolTexture* element;
};
struct AvailableList
{
    AvailableNode* head;
    AvailableNode* tail;
    unsigned count;
    OutlinedPoolReferenceStorage PopFront();
};
struct PoolHolder
{
    void FUN_00c1b4a0(NiPointer<PoolTexture>*);
};
struct TexturePool
{
    AvailableList available;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    PoolHolder holder;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    PoolList active;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    void ResizeActivePool(int kind, unsigned count);
    void BSTextureManager_ReturnRenderedTexture(PoolTexture*);
    void GetRenderTargetDesc(int, int, int*, int*, int*, int*, int*, int*);
    PoolTexture* BSTextureManager_BorrowRenderedTexture_0(int, int, int, int, int, int, int, int, int, int);
};
// Adjusts the active texture pool to hold count+1 entries by popping surplus textures or allocating new ones from the available list or a new render target.
// @fnv 0x00b6ee70
void TexturePool::ResizeActivePool(int kind, unsigned count)
{
    PoolGuard guard;
    if (!unka4)
    {
        unsigned cur = active.count;
        unsigned wanted = count + 1;
        if (cur > wanted)
        {
            PoolList& list = active;
            unsigned remaining = cur - wanted;
            do
            {
                NiPointer<PoolTexture> texture = list.PopBack();
                texture.m_pObject->FUN_00b6b260()->Set(0);
                BSTextureManager_ReturnRenderedTexture(texture.m_pObject);
            } while (--remaining);
        }
        else if (cur < wanted)
        {
            PoolList& list = active;
            unsigned remaining = wanted - cur;
            do
            {
                PoolTexture* texture;
                if (available.count > 0)
                {
                    texture = available.head->element;
                    {
                        OutlinedPoolReferenceStorage key(texture);
                        holder.FUN_00c1b4a0(reinterpret_cast<NiPointer<PoolTexture>*>(key.bytes));
                    }
                    available.PopFront();
                    if (0)
                    {
                        holder.FUN_00c1b4a0(reinterpret_cast<NiPointer<PoolTexture>*>(&OutlinedPoolReferenceStorage(0)));
                        holder.FUN_00c1b4a0(reinterpret_cast<NiPointer<PoolTexture>*>(&OutlinedPoolReferenceStorage(0)));
                        holder.FUN_00c1b4a0(reinterpret_cast<NiPointer<PoolTexture>*>(&OutlinedPoolReferenceStorage(0)));
                        holder.FUN_00c1b4a0(reinterpret_cast<NiPointer<PoolTexture>*>(&OutlinedPoolReferenceStorage(0)));
                    }

                }
                else
                {
                    int a, b, c, d, e, f;
                    GetRenderTargetDesc(kind, 43, &a, &b, &c, &d, &e, &f);
                    texture = BSTextureManager_BorrowRenderedTexture_0(kind, a, b, e, c, d, 43, f, 0, 0);
                }
                NiPointer<PoolTexture> ptr(texture);
                PoolGroup* g = texture->FUN_00b6b260();
                int u = unka8;
                g->Set(u);
                list.AddTail(ptr);
            } while (--remaining);
        }
    }
}

struct ShaderStageManager
{
    unsigned int GetTextureByIndex(NiD3DShader* shader, unsigned int value);
    void ShadowLightShader_SetNormalMap(NiD3DShader* shader, unsigned int i, unsigned int j);
};

// Sets the texture for a stage by index and applies the stage's texture pair to the shader state if the shader is not null.
// @fnv 0x00b7c0e0
// src: COMMUNITY 0x00b7c0e0
void ShaderStageManager::ShadowLightShader_SetNormalMap(NiD3DShader* shader, unsigned int i, unsigned int j)
{
    TexStageStub* stage = ((StageMgr*)DAT_0126f74c)->m_pElems[i];
    stage->m_08 = GetTextureByIndex(shader, j);
    if (shader != 0)
        stage->ApplyPairToState(GetShaderStageState(shader));
}

struct Matrix
{
    float m[4][4];
};
NiPoint3* __stdcall D3DXVec3TransformCoord_00ee6df8(NiPoint3*, const NiPoint3*, const Matrix*);

struct IDirect3DDevice9
{
    virtual void dummy0() = 0;
    virtual void dummy1() = 0;
    virtual void dummy2() = 0;
    virtual void dummy3() = 0;
    virtual void dummy4() = 0;
    virtual void dummy5() = 0;
    virtual void dummy6() = 0;
    virtual void dummy7() = 0;
    virtual void dummy8() = 0;
    virtual void dummy9() = 0;
    virtual void dummy10() = 0;
    virtual void dummy11() = 0;
    virtual void dummy12() = 0;
    virtual void dummy13() = 0;
    virtual void dummy14() = 0;
    virtual void dummy15() = 0;
    virtual void dummy16() = 0;
    virtual void dummy17() = 0;
    virtual void dummy18() = 0;
    virtual void dummy19() = 0;
    virtual void dummy20() = 0;
    virtual void dummy21() = 0;
    virtual void dummy22() = 0;
    virtual void dummy23() = 0;
    virtual void dummy24() = 0;
    virtual void dummy25() = 0;
    virtual void dummy26() = 0;
    virtual void dummy27() = 0;
    virtual void dummy28() = 0;
    virtual void dummy29() = 0;
    virtual void dummy30() = 0;
    virtual void dummy31() = 0;
    virtual void dummy32() = 0;
    virtual void dummy33() = 0;
    virtual void dummy34() = 0;
    virtual void dummy35() = 0;
    virtual void dummy36() = 0;
    virtual void dummy37() = 0;
    virtual void dummy38() = 0;
    virtual void dummy39() = 0;
    virtual void dummy40() = 0;
    virtual void dummy41() = 0;
    virtual void dummy42() = 0;
    virtual void dummy43() = 0;
    virtual void dummy44() = 0;
    virtual void dummy45() = 0;
    virtual void dummy46() = 0;
    virtual void dummy47() = 0;
    virtual void dummy48() = 0;
    virtual void dummy49() = 0;
    virtual void dummy50() = 0;
    virtual void dummy51() = 0;
    virtual void dummy52() = 0;
    virtual void dummy53() = 0;
    virtual void dummy54() = 0;
    virtual void dummy55() = 0;
    virtual void dummy56() = 0;
    virtual void dummy57() = 0;
    virtual void dummy58() = 0;
    virtual void dummy59() = 0;
    virtual void dummy60() = 0;
    virtual void dummy61() = 0;
    virtual void dummy62() = 0;
    virtual void dummy63() = 0;
    virtual void dummy64() = 0;
    virtual void dummy65() = 0;
    virtual void dummy66() = 0;
    virtual void dummy67() = 0;
    virtual void dummy68() = 0;
    virtual void dummy69() = 0;
    virtual void dummy70() = 0;
    virtual void dummy71() = 0;
    virtual void dummy72() = 0;
    virtual void dummy73() = 0;
    virtual void dummy74() = 0;
    virtual void dummy75() = 0;
    virtual void dummy76() = 0;
    virtual void dummy77() = 0;
    virtual void dummy78() = 0;
    virtual void dummy79() = 0;
    virtual void dummy80() = 0;
    virtual void dummy81() = 0;
    virtual void dummy82() = 0;
    virtual void dummy83() = 0;
    virtual void dummy84() = 0;
    virtual void dummy85() = 0;
    virtual void dummy86() = 0;
    virtual void dummy87() = 0;
    virtual void dummy88() = 0;
    virtual void dummy89() = 0;
    virtual void dummy90() = 0;
    virtual void dummy91() = 0;
    virtual void dummy92() = 0;
    virtual void dummy93() = 0;
    virtual long __stdcall SetVertexShaderConstantF(unsigned int StartRegister, const float* pConstantData,
                                                    unsigned int Vector4fCount) = 0;
};

struct Light
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88;
    NiPoint3 position;
    int unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    int unkb8, unkbc, unkc0;
    float dimmer;
    int unkc8, unkcc, unkd0;
    NiPoint3 diffuse;
    float radius;
};

struct Geometry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    float alpha;
    float GetAlpha() const
    {
        return alpha;
    }
    int unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4;
    Light* light;
};

struct Collection
{
    int unk00, unk04;
    unsigned char unk08, count;
    unsigned short unk0a;
    Geometry** objects;
};

struct Camera
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0;
    NiPoint3 offset;
};
extern Camera* DAT_011f91c8;

struct FeatureEntry
{
    int unk00, unk04;
    bool enabled;
    char unk09;
    short unk0a;
    int unk0c, unk10, unk14, unk18, unk1c;
    int count;
};
extern FeatureEntry* DAT_011fec4c;

struct Manager
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    IDirect3DDevice9* device;
    void SetVertexShaderConstantF(unsigned int reg, const float* data, unsigned int count)
    {
        device->SetVertexShaderConstantF(reg, data, count);
    }
};

struct Shader
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    Manager* manager;
};

extern Vec4 DAT_011fd9a8[];
extern Vec4 _DAT_011FA0C0[];
extern bool DAT_011f941e;
extern double DAT_01012070;

// For lights 1 and up, uploads the transformed position and radius as vertex shader constants and stores the colour in _DAT_011FA0C0.
// @fnv 0x00b7c850
void __stdcall UpdateLightShaderConstants(const Matrix* matrix, float scale)
{
    Collection* collection = (Collection*)DAT_011f91e0;
    float count = (float)collection->count - 1.0f;
    Vec4 base;
    base.z = base.y = base.x = 9.0f;
    base.w = count;
    ((Shader*)DAT_0126f74c)->manager->SetVertexShaderConstantF(25, &base.x, 1);
    DAT_011fec38->active20 = collection->count - 1;
    if (DAT_011fec4c->enabled)
        DAT_011fec4c->count = collection->count - 1;
    float total = (float)collection->count - 1.0f;
    float colorStorage[4];
    Vec4& color4 = *(Vec4*)colorStorage;
    for (unsigned char i = 1; i < collection->count; ++i)
    {
        Geometry* geometry = collection->objects[i];
        Light* light = geometry->light;
        NiPoint3 pos = light->position;
        NiPoint3 offset = DAT_011f91c8->offset;
        pos.x += offset.x;
        pos.y += offset.y;
        pos.z += offset.z;
        float transformed[3];
        D3DXVec3TransformCoord_00ee6df8(reinterpret_cast<NiPoint3*>(transformed), &pos, matrix);
        float radius = light->radius / scale;
        DAT_011fd9a8[i].x = transformed[0];
        DAT_011fd9a8[i].y = transformed[1];
        DAT_011fd9a8[i].z = transformed[2];
        DAT_011fd9a8[i].w = radius;
        ((Shader*)DAT_0126f74c)->manager->SetVertexShaderConstantF(i + 25, &DAT_011fd9a8[i].x, 1);
        float intensity = light->dimmer;
        if (!DAT_011f941e && intensity > DAT_01012070)
            intensity = 1.0f;
        NiPoint3 color = light->diffuse * intensity * geometry->GetAlpha();
        color4.x = color.x;
        color4.y = color.y;
        color4.z = color.z;
        color4.w = total;
        _DAT_011FA0C0[i] = color4;
    }
}

namespace fnv_00b7cb00 {
struct LightVector
{
    float x, y, z;
    LightVector operator*(float b) const
    {
        LightVector r = *this;
        r.x *= b;
        r.y *= b;
        r.z *= b;
        return r;
    }
};
struct ShaderVector
{
    float x, y, z, w;
    ShaderVector()
    {}
    ShaderVector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct ShaderLightData
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
    NiPoint3 position;
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
    float dimmer;
    int unkc8;
    int unkcc;
    int unkd0;
    LightVector diffuse;
    float radius;
};
struct LightEntry
{
    float GetDimmer() const
    {
        return dimmer;
    }
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
    float dimmer;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    ShaderLightData* light;
};
struct LightProperty
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
    struct AlphaSource* alpha;
};
struct AlphaVTable
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
    float(__thiscall* GetAlpha)(struct AlphaSource*);
};
struct AlphaSource
{
    AlphaVTable* vtable;
};
struct LightSet
{
    LightProperty* property;
    int unk04;
    unsigned char unk08, count;
    LightEntry** entries;
};
struct ShaderDevice
{
    virtual void __stdcall slot00() = 0;
    virtual void __stdcall slot04() = 0;
    virtual void __stdcall slot08() = 0;
    virtual void __stdcall slot0c() = 0;
    virtual void __stdcall slot10() = 0;
    virtual void __stdcall slot14() = 0;
    virtual void __stdcall slot18() = 0;
    virtual void __stdcall slot1c() = 0;
    virtual void __stdcall slot20() = 0;
    virtual void __stdcall slot24() = 0;
    virtual void __stdcall slot28() = 0;
    virtual void __stdcall slot2c() = 0;
    virtual void __stdcall slot30() = 0;
    virtual void __stdcall slot34() = 0;
    virtual void __stdcall slot38() = 0;
    virtual void __stdcall slot3c() = 0;
    virtual void __stdcall slot40() = 0;
    virtual void __stdcall slot44() = 0;
    virtual void __stdcall slot48() = 0;
    virtual void __stdcall slot4c() = 0;
    virtual void __stdcall slot50() = 0;
    virtual void __stdcall slot54() = 0;
    virtual void __stdcall slot58() = 0;
    virtual void __stdcall slot5c() = 0;
    virtual void __stdcall slot60() = 0;
    virtual void __stdcall slot64() = 0;
    virtual void __stdcall slot68() = 0;
    virtual void __stdcall slot6c() = 0;
    virtual void __stdcall slot70() = 0;
    virtual void __stdcall slot74() = 0;
    virtual void __stdcall slot78() = 0;
    virtual void __stdcall slot7c() = 0;
    virtual void __stdcall slot80() = 0;
    virtual void __stdcall slot84() = 0;
    virtual void __stdcall slot88() = 0;
    virtual void __stdcall slot8c() = 0;
    virtual void __stdcall slot90() = 0;
    virtual void __stdcall slot94() = 0;
    virtual void __stdcall slot98() = 0;
    virtual void __stdcall slot9c() = 0;
    virtual void __stdcall slota0() = 0;
    virtual void __stdcall slota4() = 0;
    virtual void __stdcall slota8() = 0;
    virtual void __stdcall slotac() = 0;
    virtual void __stdcall slotb0() = 0;
    virtual void __stdcall slotb4() = 0;
    virtual void __stdcall slotb8() = 0;
    virtual void __stdcall slotbc() = 0;
    virtual void __stdcall slotc0() = 0;
    virtual void __stdcall slotc4() = 0;
    virtual void __stdcall slotc8() = 0;
    virtual void __stdcall slotcc() = 0;
    virtual void __stdcall slotd0() = 0;
    virtual void __stdcall slotd4() = 0;
    virtual void __stdcall slotd8() = 0;
    virtual void __stdcall slotdc() = 0;
    virtual void __stdcall slote0() = 0;
    virtual void __stdcall slote4() = 0;
    virtual void __stdcall slote8() = 0;
    virtual void __stdcall slotec() = 0;
    virtual void __stdcall slotf0() = 0;
    virtual void __stdcall slotf4() = 0;
    virtual void __stdcall slotf8() = 0;
    virtual void __stdcall slotfc() = 0;
    virtual void __stdcall slot100() = 0;
    virtual void __stdcall slot104() = 0;
    virtual void __stdcall slot108() = 0;
    virtual void __stdcall slot10c() = 0;
    virtual void __stdcall slot110() = 0;
    virtual void __stdcall slot114() = 0;
    virtual void __stdcall slot118() = 0;
    virtual void __stdcall slot11c() = 0;
    virtual void __stdcall slot120() = 0;
    virtual void __stdcall slot124() = 0;
    virtual void __stdcall slot128() = 0;
    virtual void __stdcall slot12c() = 0;
    virtual void __stdcall slot130() = 0;
    virtual void __stdcall slot134() = 0;
    virtual void __stdcall slot138() = 0;
    virtual void __stdcall slot13c() = 0;
    virtual void __stdcall slot140() = 0;
    virtual void __stdcall slot144() = 0;
    virtual void __stdcall slot148() = 0;
    virtual void __stdcall slot14c() = 0;
    virtual void __stdcall slot150() = 0;
    virtual void __stdcall slot154() = 0;
    virtual void __stdcall slot158() = 0;
    virtual void __stdcall slot15c() = 0;
    virtual void __stdcall slot160() = 0;
    virtual void __stdcall slot164() = 0;
    virtual void __stdcall slot168() = 0;
    virtual void __stdcall slot16c() = 0;
    virtual void __stdcall slot170() = 0;
    virtual void __stdcall slot174() = 0;
    virtual long __stdcall SetVertexShaderConstantF(unsigned int, const float*, unsigned int) = 0;
};
struct DeviceHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ShaderDevice* device;
    void SetVSConst(unsigned int r, const float* v, unsigned int n)
    {
        device->SetVertexShaderConstantF(r, v, n);
    }
};
struct ShaderManager
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
    DeviceHolder* holder;
};
struct ConstantEntry
{
    int unk00;
    int unk04;
    bool enabled;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int count;
};
struct SceneTranslation
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
    NiPoint3 translate;
};
struct ScaleSource
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
    float scale;
};
extern SceneTranslation* DAT_011f91c8;
extern ConstantEntry* DAT_011fec4c;
extern ShaderVector DAT_011fd9a8[];
extern ShaderVector _DAT_011FA0C0[];
extern bool DAT_011f941e;
struct LightMatrix;
NiPoint3* __stdcall D3DXVec3TransformCoord_00ee6df8(NiPoint3*, const NiPoint3*, const LightMatrix*);
// Fills shader constant arrays with transformed light positions, radii, and colors from the active light set.
// @fnv 0x00b7cb00
void __stdcall UpdateShaderLights(const LightMatrix* matrix, float radiusScale, ScaleSource* source)
{
    LightSet* lights = reinterpret_cast<LightSet*>(DAT_011f91e0);
    float alpha = lights->property->alpha->vtable->GetAlpha(lights->property->alpha);
    ShaderVector ambient(99.0f, 99.0f, 99.0f, alpha);
    reinterpret_cast<ShaderManager*>(DAT_0126f74c)->holder->SetVSConst(25, &ambient.x, 1);
    int count = (int)lights->count - 1;
    if (count < 2)
        count = 2;
    DAT_011fec38->active20 = count;
    if (DAT_011fec4c->enabled)
        DAT_011fec4c->count = (int)lights->count - 1;
    float lightCount;
    float scale = source ? source->scale : 30.0f;
    lightCount = (float)lights->count - 1.0;
    ShaderVector result;
    for (unsigned char i = 1; i < lights->count; ++i)
    {
        LightEntry* entry = lights->entries[i];
        ShaderLightData* light = entry->light;
        NiPoint3 position;
        memcpy(&position, &light->position, sizeof(position));
        NiPoint3 offset;
        memcpy(&offset, &DAT_011f91c8->translate, sizeof(offset));
        position.x += offset.x;
        position.y += offset.y;
        position.z += offset.z;
        NiPoint3 transformed;
        D3DXVec3TransformCoord_00ee6df8(&transformed, &position, matrix);
        float radius = light->radius / radiusScale;
        DAT_011fd9a8[i].x = transformed.x;
        DAT_011fd9a8[i].y = transformed.y;
        DAT_011fd9a8[i].z = transformed.z;
        DAT_011fd9a8[i].w = radius;
        reinterpret_cast<ShaderManager*>(DAT_0126f74c)->holder->SetVSConst(25 + i, &DAT_011fd9a8[i].x, 1);
        float dimmer = light->dimmer;
        if (!DAT_011f941e && 1.0 < dimmer)
            dimmer = 1.0f;
        LightVector color = light->diffuse * dimmer * entry->GetDimmer();
        result = ShaderVector(color.x, color.y, color.z, lightCount);
        _DAT_011FA0C0[i] = result;
        lightCount = scale;
    }
    if (lights->count == 2)
    {
        result = ShaderVector(0.0f, 0.0f, 0.0f, scale);
        _DAT_011FA0C0[2] = result;
    }
}
}  // namespace fnv_00b7cb00

// Sets two global values into specific slots of DAT_0126f74c based on which pass identifier is supplied.
// @fnv 0x00b7cfb0
void __stdcall SetPassValues(unsigned int uiPass)
{
    switch (uiPass)
    {
    case 0xa0:
    case 0xa1:
    case 0xa2:
    case 0xa6:
    case 0xa7:
    case 0xa8:
    case 0xb6:
    case 0xb7:
    case 0xb8:
    case 0xbc:
    case 0xbd:
    case 0xbe:
    case 0x10a:
    case 0x10b:
    case 0x10c:
    case 0x110:
    case 0x111:
    case 0x112:
    case 0x115:
    case 0x121:
    case 0x122:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x12b:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[6]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[7]->unk08 = DAT_011f95e8;
        break;
    case 0xe0:
    case 0xe1:
    case 0xe5:
    case 0xe6:
    case 0xf2:
    case 0xf3:
    case 0xf7:
    case 0xf8:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[5]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[6]->unk08 = DAT_011f95e8;
        break;
    case 0x160:
    case 0x161:
    case 0x163:
    case 0x164:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[4]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[5]->unk08 = DAT_011f95e8;
        break;
    case 0x94:
    case 0x1f3:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[2]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[3]->unk08 = DAT_011f95e8;
        break;
    case 0x1f8:
    case 0x1fc:
    case 0x200:
    case 0x204:
    case 0x208:
    case 0x20c:
    case 0x210:
    case 0x214:
    case 0x218:
    case 0x21c:
    case 0x220:
    case 0x224:
    case 0x228:
    case 0x22c:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[14]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[15]->unk08 = DAT_011f95e8;
        break;
    }
}

extern bool DAT_011f94a4;
extern bool DAT_011f941f;

// Returns an index derived from DAT_011f91c0 and the DAT_011f94a4, DAT_011f941e, DAT_011f941f flags.
// @fnv 0x00b7faf0
// src: COMMUNITY 0x00b7faf0
int __cdecl ShaderBuffer_GetCurrentBufferType()
{
    int result = 0;
    switch (DAT_011f91c0)
    {
    case 1:
        result = 1;
        break;
    case 2:
        result = 2;
        break;
    case 3:
        result = 5;
        break;
    case 4:
        result = 8;
        break;
    case 5:
        if (DAT_011f94a4)
        {
            if (DAT_011f941e)
                result = DAT_011f941f ? 13 : 12;
            else
                result = 4;
        }
        else
        {
            if (DAT_011f941e)
                result = DAT_011f941f ? 11 : 10;
            else
                result = 3;
        }
        break;
    case 6:
        if (DAT_011f94a4)
        {
            if (DAT_011f941e)
                result = DAT_011f941f ? 17 : 16;
            else
                result = 7;
        }
        else
        {
            if (DAT_011f941e)
                result = DAT_011f941f ? 15 : 14;
            else
                result = 6;
        }
        break;
    case 7:
        if (DAT_011f941e)
            result = DAT_011f941f ? 19 : 18;
        else
            result = 9;
        break;
    }
    return result;
}

struct RendererCleanup
{
    void FUN_00b7fc50();
    RendererCleanup* FUN_00b7fd20(unsigned int flags);
};

// Calls FUN_00b7fc50, deallocates this via g_memoryManager when the low bit of flags is set, and returns this.
// @fnv 0x00b7fd20
RendererCleanup* RendererCleanup::FUN_00b7fd20(unsigned int flags)
{
    FUN_00b7fc50();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

// @fnv 0x00b7fd40
// src: GUESS 0x00b7fd40 (confidence: low)
void __cdecl Object_ProcessState_00b7fd40()
{
    extern void FUN_00b7fc50(void);
    FUN_00b7fc50();
}

struct SweepBucketNode
{
    SweepBucketNode* next;
    void* value;
};
void __cdecl _NiFree_00aa10f0(void*);
struct FUN_00b580a0_base
{
    virtual ~FUN_00b580a0_base();
};
struct FUN_00b60420 : FUN_00b580a0_base
{
    unsigned int numBuckets;
    SweepBucketNode** buckets;
    unsigned int unk0c;
    bool freeEntries;
    virtual ~FUN_00b60420();
};
// Destroys the sweep bucket table, freeing each entry value via FUN_00aa10f0 when freeEntries is set.
// @fnv 0x00b60420
FUN_00b60420::~FUN_00b60420()
{
    if (freeEntries)
    {
        for (unsigned int i = 0; i < numBuckets; ++i)
        {
            SweepBucketNode* node = buckets[i];
            while (node)
            {
                SweepBucketNode* current = node;
                node = node->next;
                _NiFree_00aa10f0(current->value);
            }
        }
    }
}

#include <string.h>

struct MorphGeomData
{
    int unk00, unk04;
    unsigned short vertexCount, unk0a, flags, unk0e;
    int unk10, unk14, unk18, unk1c;
    NiPoint3* data20;
    NiPoint3* vertices;
    void* data28;
    void* data2c;
    unsigned short GetNormalFlag() const
    {
        return flags & 1;
    }
    NiPoint3* GetVertices() const
    {
        return vertices;
    }
    void NiGeometryData_ReplaceData(unsigned short, NiPoint3*, void*, void*, void*, unsigned short, unsigned int);
};
struct ExtraGeometryData
{
    int unk00, unk04, unk08;
    void* data;
    int count;
};
struct ExtraDataOwner
{
    ExtraGeometryData* FUN_00a5bdd0(void*);
};
struct GeometryInput
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ExtraDataOwner* extraData;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4;
    MorphGeomData* geometry;
    ExtraGeometryData* FUN_00a5bdd0(void*);
    void DeleteExtraDataByKey(void*);
};
struct AuxiliaryVertices
{
    int unk00, unk04, unk08;
    NiPoint3* first;
    NiPoint3* second;
    NiPoint3* GetFirst() const
    {
        return first;
    }
    NiPoint3* GetSecond() const
    {
        return second;
    }
};
struct FUN_00537bf0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    FUN_00537bf0(unsigned int);
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
    void SetSize_Thunk(int);
    void NiAdditionalGeometryData_SetDataStreamCount(int);
    void NiAdditionalGeometryData_SetDataBlock(int, void*, unsigned int, int);
    void NiAdditionalGeometryData_SetDataStream(int, int, int, int, unsigned int, int, int);
};
extern void* DAT_011f94bc;
struct ShaderGeometryOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int flags;
    int unk24, unk28, unk2c, unk30, unk34;
    volatile int cached;
    int unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    AuxiliaryVertices* auxiliary;
    void* extraVertices;
    unsigned int HasExtraData() const
    {
        return flags & 0x4000;
    }
    void SetExtra()
    {
        if (!HasExtraData())
            cached = 0;
        flags |= 0x4000;
    }
    void ClearExtra()
    {
        if (HasExtraData())
            cached = 0;
        flags &= ~0x4000;
    }
    FUN_00537bf0* BuildShaderGeometry(GeometryInput* input);
};
inline void* __cdecl operator new[](unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
// Merges auxiliary vertex streams into geometry and allocates a vertex buffer from extra geometry data, returning it or null.
// @fnv 0x00b69be0
FUN_00537bf0* ShaderGeometryOwner::BuildShaderGeometry(GeometryInput* input)
{
    unsigned int count = input->geometry->vertexCount;
    MorphGeomData* geometry = input->geometry;
    if (auxiliary && auxiliary->first && auxiliary->second && !(geometry->flags & 0xf000))
    {
        NiPoint3* vertices = new NiPoint3[(unsigned short)count * 3];
        NiPoint3* original = geometry->GetVertices();
        NiPoint3* second = auxiliary->GetSecond();
        NiPoint3* first = auxiliary->GetFirst();
        memcpy(vertices, original, (unsigned short)count * sizeof(NiPoint3));
        memcpy(vertices + (unsigned short)count, second, (unsigned short)count * sizeof(NiPoint3));
        memcpy(vertices + (unsigned short)count * 2, first, (unsigned short)count * sizeof(NiPoint3));
        g_memoryManager.Deallocate(original);
        unsigned short normalFlag = geometry->flags;
        void* streamC = geometry->data2c;
        void* stream8 = geometry->data28;
        NiPoint3* stream0 = geometry->data20;
        normalFlag &= 1;
        geometry->NiGeometryData_ReplaceData(count, stream0, vertices, stream8, streamC, normalFlag, 0x1000);
    }
    if (input->extraData)
    {
        ExtraGeometryData* extra = input->extraData->FUN_00a5bdd0(DAT_011f94bc);
        if (extra)
        {
            void* pExtraVertices = extra->data;
            extraVertices = pExtraVertices;
            if (pExtraVertices)
                SetExtra();
            else
                ClearExtra();
            FUN_00537bf0* buffer = new FUN_00537bf0(count);
            buffer->SetSize_Thunk(2);
            buffer->NiAdditionalGeometryData_SetDataStreamCount(2);
            buffer->NiAdditionalGeometryData_SetDataBlock(1, extraVertices, (unsigned short)count * 32, 0);
            buffer->NiAdditionalGeometryData_SetDataStream(0, 1, 0, 4, count, 16, 32);
            buffer->NiAdditionalGeometryData_SetDataStream(1, 1, 16, 4, count, 16, 32);
            extra->count = 0;
            extra->data = 0;
            input->DeleteExtraDataByKey(DAT_011f94bc);
            return buffer;
        }
    }
    return 0;
}

struct TailTarget
{
    void Tail();
};

struct C_00b6f460
{
    void BSShaderLightingProperty_LinkObject();
};

// @fnv 0x00b6f460
// src: XBOX_PDB 0x00b6f460
void C_00b6f460::BSShaderLightingProperty_LinkObject()
{
    ((TailTarget*)this)->Tail();
}

namespace fnv_00b6b6c0 {
extern "C" void _ReadWriteBarrier();

extern NiRefObject* DAT_011fa024[10];

extern "C" NiRenderer* DAT_011f4748;

// src: COMMUNITY 0x00b6b0b0
void __cdecl BSRenderedTexture_Pop()
{
    if (DAT_011fa020)
    {
        NiRefObject*& slot = DAT_011fa024[--DAT_011fa020];
        NiRefObject* object = slot;
        if (object)
        {
            object->DecRefCount();
            slot = 0;
        }
    }
}

// Drains the DAT_011fa024 reference list via FUN_00b6b0b0, then unlocks DAT_011f4748 if m_ucLocked is set.
// @fnv 0x00b6b6c0
void __cdecl ClearAndUnlockRenderer()
{
    while (DAT_011fa020)
        BSRenderedTexture_Pop();
    NiRenderer* renderer = DAT_011f4748;
    if (renderer->m_bRenderTargetGroupActive)
        ((bool (__thiscall*)(NiRenderer*))TryUnlockRenderer)(renderer);
}
}  // namespace fnv_00b6b6c0

struct PixelData
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    int m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiRevID;
};

// For mipmap levels 1 and up, sets pixel bytes 0, 1 and/or 2 to 0xff according to the level (1 to 6), then increments m_uiRevID.
// @fnv 0x00b6b940
// src: COMMUNITY 0x00b6b940
void __cdecl BSShaderUtil_TintUncompressedPixelDataByMipMap(PixelData* pkData)
{
    if (pkData)
    {
        unsigned int uiLevels = pkData->m_uiMipmapLevels;
        for (unsigned int i = 1; i < uiLevels; i++)
        {
            unsigned int uiWidth = pkData->m_puiWidth[i];
            unsigned int uiHeight = pkData->m_puiHeight[i];
            unsigned char* pucPixels = pkData->m_pucPixels + pkData->m_puiOffsetInBytes[i];
            unsigned int stride = uiWidth * 4;
            for (unsigned int y = 0; y < uiHeight; y++)
            {
                unsigned int uiRowOffset = y * stride;
                for (unsigned int x = 0; x < uiWidth; x++)
                {
                    switch (i - 1)
                    {
                    case 0:
                        pucPixels[uiRowOffset + 0] = 0xff;
                        break;
                    case 1:
                        pucPixels[uiRowOffset + 1] = 0xff;
                        break;
                    case 2:
                        pucPixels[uiRowOffset + 2] = 0xff;
                        break;
                    case 3:
                        pucPixels[uiRowOffset + 1] = 0xff;
                        pucPixels[uiRowOffset + 0] = 0xff;
                        break;
                    case 4:
                        pucPixels[uiRowOffset + 1] = 0xff;
                        pucPixels[uiRowOffset + 2] = 0xff;
                        break;
                    case 5:
                        pucPixels[uiRowOffset + 2] = 0xff;
                        pucPixels[uiRowOffset + 0] = 0xff;
                        break;
                    }
                    uiRowOffset += 4;
                }
            }
        }
        pkData->m_uiRevID++;
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct Surface051
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
};
struct Target051
{
    virtual void Slot0();
    virtual void DeleteThis();
    long refs;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Surface051* surface;
    int unk28;
    int kind;
    NiPointer<Target051> texture;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
// 0x00b6e450 inlines destruction of the temporary target references.
// Force this specialisation inline as the original FencePtr/PopFront bodies did.
template <> __forceinline NiPointer<Target051>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
__forceinline Target051* TextureOf(Target051* p)
{
    return *(p ? &p->texture : &NiPointer<Target051>());
}
struct Node051
{
    Node051* next;
    Node051* prev;
    Target051* object;
};
struct Alloc051
{
    unsigned int count;
    Node051* NiGeometry_AddProperty();
};
struct FUN_00b9e7c0_list
{
    Node051* head;
    Node051* tail;
    union
    {
        unsigned int count;
        Alloc051 allocator;
    };
    __forceinline unsigned int Count() const
    {
        return count;
    }
    NiPointer<Target051> PopFront();
};
struct FUN_00c1b4a0_holder : FUN_00b9e7c0_list
{
    __declspec(noinline) void FUN_00c1b4a0(NiPointer<Target051>* p);
    __forceinline void Insert(Target051* obj)
    {
        FUN_00c1b4a0(&NiPointer<Target051>(obj));
    }
};
void FUN_00c1b4a0_holder::FUN_00c1b4a0(NiPointer<Target051>* p)
{
    Node051* node = allocator.NiGeometry_AddProperty();
    if (node->object != p->m_pObject)
    {
        if (node->object)
            node->object->DecRefCount();
        node->object = p->m_pObject;
        if (node->object)
            node->object->IncRefCount();
    }
    node->prev = 0;
    node->next = head;
    if (head)
        head->prev = node;
    else
        tail = node;
    head = node;
    ++count;
}
extern ImageSpaceManager* DAT_011f91ac;
extern bool DAT_011f941e, DAT_011f941f, DAT_011f9420;
struct Setup051
{
    union
    {
        struct
        {
            int unk00, unk04, unk08;
        };
        FUN_00c1b4a0_holder first;
    };
    FUN_00c1b4a0_holder active0, active1, active2, active3;
    FUN_00c1b4a0_holder spare;
    FUN_00c1b4a0_holder inactive0, inactive1, inactive2, inactive3;
    __declspec(noalias) void GetRenderTargetDesc(NiRenderer*, int, unsigned int*, unsigned int*, unsigned int*,
                                                 unsigned int*, unsigned int*, unsigned int*);
    Target051* BSTextureManager_BorrowRenderedTexture_0(NiRenderer*, int, int, int, int, int, int, int, int, int);
    void BSTextureManager_ReturnRenderedTexture(Target051*);
    __forceinline Target051* Create(NiRenderer* r, int kind)
    {
        unsigned int width, height, format, unused, flags, samples;
        GetRenderTargetDesc(r, kind, &width, &height, &format, &unused, &flags, &samples);
        return BSTextureManager_BorrowRenderedTexture_0(r, width, height, flags, format, unused, kind, samples, 0, 0);
    }
    __forceinline Target051* Acquire(NiRenderer* r, int kind, int flags = 0, int noReuse = 0, int e = 0)
    {
        if (noReuse == 0)
        {
            switch (kind)
            {
            case 43:
                if (unk08)
                {
                    Target051* p = first.head->object;
                    spare.Insert(p);
                    first.PopFront();
                    return p;
                }
                break;
            case 17:
                if (active0.Count() > 0)
                {
                    Target051* p = active0.head->object;
                    inactive0.Insert(p);
                    active0.PopFront();
                    return p;
                }
                break;
            case 9:
                if (active1.Count() > 0)
                {
                    Target051* p = active1.head->object;
                    inactive1.Insert(p);
                    active1.PopFront();
                    return p;
                }
                break;
            case 22:
                if (active2.Count() > 0)
                {
                    Target051* p = active2.head->object;
                    inactive2.Insert(p);
                    active2.PopFront();
                    return p;
                }
                break;
            case 19:
                if (active3.Count() > 0)
                {
                    Target051* p = active3.head->object;
                    inactive3.Insert(p);
                    active3.PopFront();
                    return p;
                }
                break;
            }
        }
        if (noReuse != 0)
            return 0;
        return Create(r, kind);
    }
    __forceinline Target051* GetTexture(NiRenderer* r, int kind)
    {
        if (kind == -1)
            return TextureOf((Target051*)DAT_011f91ac->pSwapTarget);
        NiPointer<Target051> held = Acquire(r, kind);
        return TextureOf(held);
    }
    void BSTextureManager_PrecreateTextures(NiRenderer* renderer);
};
// Acquires render targets and calls FUN_00b6da10 on them, then adds acquired kinds 17, 9, 22 and 19 to the active lists and calls Slot37 on their textures.
// @fnv 0x00b6e450
// src: COMMUNITY 0x00b6e450
void Setup051::BSTextureManager_PrecreateTextures(NiRenderer* renderer)
{
    Target051* targets[50];
    int count = 0;
    {
        if (DAT_011f941e)
        {
            targets[0] = BSTextureManager_BorrowRenderedTexture_0(DAT_011f9508, 1, 1, 36, 0x71, 0, -1, 0, 0, 0);
            targets[1] = BSTextureManager_BorrowRenderedTexture_0(DAT_011f9508, 1, 1, 36, 0x71, 0, -1, 0, 0, 0);
            targets[2] = BSTextureManager_BorrowRenderedTexture_0(DAT_011f9508, 1, 1, 36, 0x71, 0, -1, 0, 0, 0);
            targets[3] = BSTextureManager_BorrowRenderedTexture_0(DAT_011f9508, 4, 4, 38, 0x71, 0, -1, 0, 0, 0);
            targets[4] = BSTextureManager_BorrowRenderedTexture_0(DAT_011f9508, 16, 16, 38, 0x71, 0, -1, 0, 0, 0);
            targets[5] = BSTextureManager_BorrowRenderedTexture_0(DAT_011f9508, 64, 64, 38, 0x71, 0, -1, 0, 0, 0);
            targets[6] = Acquire(DAT_011f9508, 2);
            targets[7] = Acquire(DAT_011f9508, 0);
            targets[8] = Acquire(DAT_011f9508, 4);
            if (DAT_011f941f && DAT_011f9420)
            {
                targets[9] = Acquire(DAT_011f9508, 1);
            }
            else
                targets[9] = 0;
            count = 10;
        }
        targets[count++] = Acquire(DAT_011f9508, 3);
        targets[count++] = Acquire(DAT_011f9508, 6);
        targets[count++] = Acquire(DAT_011f9508, 6);
        for (int i = 0; i < count; ++i)
            if (targets[i])
                BSTextureManager_ReturnRenderedTexture(targets[i]);
    }
    GetTexture(renderer, -1)->surface->Slot37();
    Target051* target;
    target = Acquire(renderer, 17);
    if (target)
    {
        active0.Insert(target);
        target->kind = 17;
        TextureOf(target)->surface->Slot37();
    }
    target = Acquire(renderer, 9);
    if (target)
    {
        active1.Insert(target);
        target->kind = 9;
        TextureOf(target)->surface->Slot37();
    }
    target = Acquire(renderer, 22);
    if (target)
    {
        active2.Insert(target);
        target->kind = 22;
        TextureOf(target)->surface->Slot37();
    }
    target = Acquire(renderer, 19);
    if (target)
    {
        active3.Insert(target);
        target->kind = 19;
        TextureOf(target)->surface->Slot37();
    }
}

typedef NiRefObject B61Ref;

struct B61Bound
{
    float x, y, z, r;
};
struct B61Alloc
{
    static void* operator new[](unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete[](void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
};

// Allocate uninitialized point storage through the original array allocator.
// NiPoint3's constructor is not involved in these copied geometry streams.
template <class T> struct GeometryArrayStorage : B61Alloc
{
    unsigned char bytes[sizeof(T)];
};
struct B61UV : B61Alloc
{
    float u, v;
};
struct B61Float : B61Alloc
{
    float f;
};
struct B61Index : B61Alloc
{
    unsigned short us;
};
struct B61Color : B61Alloc
{
    float r, g, b, a;
    B61Color();
};
class B61Data : public B61Ref
{
  public:
    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    int unk0c;
    B61Bound m_kBound;
    NiPoint3* m_pkVertex;
    NiPoint3* m_pkNormal;
    B61Color* m_pkColor;
    B61UV* m_pkTexture;
    int unk30, unk34, unk38, unk3c, unk40;
    unsigned int m_uiTriListLength;
    unsigned short* m_pusStripLengths;
    unsigned short* FUN_00a7b850();
    unsigned short* FUN_00a75f10();
};
class B61Property : public B61Ref
{
  public:
    int unk08, unk0c, unk10, unk14;
    unsigned short m_usFlags;
    unsigned char m_ucTestRef;
    unsigned char unk1b;
};
class B61TexProp : public B61Property
{
  public:
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual B61Ref* GetGeometryShaderObject();
    int m_iType;
    int IsShaderType() const
    {
        int iType = m_iType;
        int b = (iType == 4);
        return b;
    }
};
extern unsigned char vftable_NiAlphaProperty[];
class B61PropBase
{
  public:
    void* m_pvVtbl;
    long m_lRefCount;
    int unk08, unk0c, unk10, unk14;
    unsigned short m_usFlags;
    unsigned char m_ucTestRef;
    unsigned char unk1b;
    static void* operator new(unsigned int uiSize)
    {
        return Object_DispatchCommandFour(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
    B61PropBase();
};
class B61AlphaProperty : public B61PropBase
{
  public:
    B61AlphaProperty()
    {
        m_pvVtbl = vftable_NiAlphaProperty;
        m_usFlags = 0xec;
        m_ucTestRef = 0;
    }
};
class B61AVObject : public B61Ref
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    virtual B61AVObject* GetAsNode();
    virtual void v04();
    virtual void v05();
    virtual B61AVObject* GetAsGeometry();
    virtual void v07();
    virtual int IsStrips();
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    int unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    B61AVObject** m_ppkChildren;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    int unka8, unkac, unkb0, unkb4;
    NiPointer<B61Data> m_pUserData;
    B61AVObject* FUN_00653290(const NiRTTI* pkRTTI);
    B61Property* FUN_00a59d30(int iType);
};
extern NiRTTI DAT_011f4280;
extern NiRTTI DAT_011f4aa0;
inline bool B61IsKindOf(const NiRTTI* pkRTTI, B61AVObject* pkObj)
{
    if (!pkObj)
        return false;
    const NiRTTI* pkType = pkObj->GetRTTI();
    while (pkType)
    {
        if (pkType == pkRTTI)
            return true;
        pkType = pkType->m_pBaseRTTI;
    }
    return false;
}
class B61TriShapeData : public B61Ref
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return Object_DispatchCommandFour(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    B61TriShapeData(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, B61Color* pkColor,
                    B61UV* pkTexture, unsigned short usNumTextureSets, int eNBTMethod, unsigned short usTriangles,
                    B61Index* pusTriList, unsigned short usActive, unsigned short usActiveTris);
};
class B61TriStripsData : public B61Ref
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        return Object_DispatchCommandFour(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    B61TriStripsData(unsigned short uiVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, B61Color* pkColor,
                     B61UV* pkTexture, unsigned short uiNumTextureSets, int eNBTMethod, unsigned short uiTriangles,
                     unsigned short uiStrips, unsigned short* pusStripLengths, B61Index* pusStripLists,
                     unsigned short usActive, unsigned short usActiveTris);
};
class B61Loaded : public FnvB60280Ref
{
  public:
    int m_iFadeIndex;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk24c;
    B61AVObject** m_ppkTop;
    unsigned int m_uiTopMax;
    unsigned int m_uiTopSize;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    void IncRefCount()
    {
        DAT_00fdf1c0((void*)&m_ref);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_ref) == 0)
            delete this;
    }
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
    B61Loaded(const char* pcName);
// src: COMMUNITY 0x00b60750
    NiPointer<B61AVObject> GrassLoadTask_GetObject()
    {
        return NiPointer<B61AVObject>(m_uiTopSize ? m_ppkTop[0] : 0);
    }
};
class B61Entry : public B61Ref
{
  public:
    NiPointer<B61Ref> m_spTransformData;
    B61Float* m_pkNumbers;
    int m_iWidth;
    NiPointer<B61Ref> m_pGeometryShader;
    NiPointer<B61Property> m_spAlpha;
    NiPointer<B61Property> m_spAlpha2;
    NiPointer<B61Property> m_spExtra;
    NiPointer<B61Loaded> m_spLoaded;
    float m_fBoundRadius;
    int m_iCopies;
    unsigned char m_ucStrips;
    unsigned char m_ucKind;
    unsigned char m_ucPending;
    unsigned short m_usGroup;
    static void* operator new(unsigned int uiSize)
    {
        return Object_DispatchCommandFour(uiSize);
    }
    static void operator delete(void* pvMem, void* pvPlace);
    B61Entry();
};
typedef NiTMap<const char*, NiPointer<B61Entry> > CachedGeometryMap;

template <> inline bool CachedGeometryMapBase::GetAt(const char* pcKey, NiPointer<B61Entry>& spVal) const
{
    unsigned int uiIndex = KeyToHashIndex(pcKey);
    for (EntryType* pkItem = m_ppkHashTable[uiIndex]; pkItem; pkItem = pkItem->m_pkNext)
    {
        if (IsKeysEqual(pcKey, pkItem->m_key))
        {
            spVal = pkItem->m_val;
            return true;
        }
    }
    return false;
}
CachedGeometryMap* __cdecl TallGrassShaderProperty_GetCachedGeometryMap();
struct B61IOManager
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
    virtual void QueueTask(B61Loaded* pkTask);
};
extern B61IOManager* DAT_01202d98;
extern unsigned char DAT_011ad86c;
extern void(__cdecl* DAT_011f91e8)(const char*);
void __cdecl BuildAssetPath(const char* pcName, char* pcPath, unsigned int uiSize);
void* __cdecl FUN_00ec44d0(void* pvDst, const void* pvSrc, unsigned int uiSize);


// BSStream's shared layout is four bytes larger than this game's stack object.
// Keep this layout until BSStream.h can represent the original 0x5CC-byte object.
class B61Stream
{
  public:
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    void* m_pvTopVtbl;
    B61AVObject** m_ppkTop;
    unsigned int m_uiTopMax;
    unsigned int m_uiTopSize;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    B61Stream();
    virtual ~B61Stream();
    bool BSStream_Load(const char* pcName, bool bFlag);
};


inline void B61Notify(const char* pcName)
{
    if (DAT_011f91e8)
        DAT_011f91e8(pcName);
}
__forceinline int B61Promote(const unsigned short& a)
{
    return a;
}
// Loads or creates a B61Entry for the given particle name, building duplicated vertex/index data and shader properties, then returns the entry.
// @fnv 0x00b61980
// src: COMMUNITY 0x00b61980
B61Entry* __cdecl TallGrassShaderProperty_GetCachedGeometry(const char** ppcName)
{
    unsigned short usVerts;
    (void)usVerts;
    MemContextGuard kGuard(0x1c);
    if (_fnv_particle_shader_renderer_level == 0)
        return 0;
    B61AVObject* pkGeom = 0;
    if (!*ppcName)
        return 0;
    NiPointer<B61Entry> spEntry;
    B61Entry* pkNew;
    if (!TallGrassShaderProperty_GetCachedGeometryMap()->GetAt(*ppcName, spEntry))
    {
        spEntry = new B61Entry;
        pkNew = spEntry;
        pkNew->m_ucPending = 1;
        pkNew->m_spLoaded = 0;
        TallGrassShaderProperty_GetCachedGeometryMap()->SetAt(*ppcName, pkNew);
        if (DAT_011ad86c)
        {
            pkNew->m_spLoaded = (new B61Loaded(*ppcName));
            DAT_01202d98->QueueTask(pkNew->m_spLoaded);
            return 0;
        }
    }
    else
        pkNew = spEntry;
    if (pkNew->m_ucPending)
    {
        NiPointer<B61AVObject> m_pRootNode;
        if (DAT_011ad86c && !spEntry->m_spLoaded)
        {
            spEntry->m_spLoaded = (new B61Loaded(*ppcName));
            DAT_01202d98->QueueTask(spEntry->m_spLoaded);
            return 0;
        }
        if (spEntry->m_spLoaded)
        {
            if (spEntry->m_spLoaded->m_iFadeIndex >= 4)
            {
                m_pRootNode = spEntry->m_spLoaded->GrassLoadTask_GetObject();
                spEntry->m_spLoaded = (0);
            }
        }
        else
        {
            char acPath[0x104];
            BuildAssetPath(*ppcName, acPath, 0x104);
            B61Stream kStream;
            kStream.BSStream_Load(acPath, false);
            if (kStream.m_uiTopSize)
            {
                B61AVObject* root = kStream.m_ppkTop[0];
                m_pRootNode = root;
            }
        }
        if (m_pRootNode)
        {
            spEntry->m_ucPending = 0;
            B61AVObject* kIter = m_pRootNode->FUN_00653290(&DAT_011f4280)->GetAsNode();
            do
            {
                if (!kIter)
                    break;
                for (unsigned int i = 0; i < kIter->m_usSize; i++)
                {
                    B61AVObject* pkChild = kIter->m_ppkChildren[i];
                    if (pkChild)
                    {
                        pkGeom = pkChild->GetAsGeometry();
                        if (pkGeom)
                            break;
                    }
                }
            } while (!pkGeom);
            long iStrips = pkGeom->IsStrips();
            unsigned short usCopies;
            if (2 <= _fnv_particle_shader_renderer_level)
                usCopies = 0xe4;
            else
                usCopies = 0x50;
            unsigned short usGroup;
            unsigned char ucStrips;
            B61Ref* pkNewData;
            B61Float* pkNumbers;

            if (!iStrips)
            {
                B61Data* pkData = pkGeom->m_pUserData;
                ucStrips = 0;
                usVerts = pkData->m_usVertices;
                NiPoint3* n = pkData->m_pkVertex;
                unsigned long uiTriListLength = pkData->m_uiTriListLength;
                unsigned short* pusTriList = pkData->FUN_00a7b850();
                unsigned short usMax = 0xffff / usVerts;
                if (usCopies >= usMax)
                    usCopies = usMax;
                unsigned short iListLen = (unsigned short)uiTriListLength;
                usMax = 0xffff / iListLen;
                if (usCopies >= usMax)
                    usCopies = usMax;
                unsigned int iTotalVertexCount = usCopies * usVerts;
                NiPoint3* pkVertex = (NiPoint3*)new GeometryArrayStorage<NiPoint3>[iTotalVertexCount];
                NiPoint3* pkNormal = (NiPoint3*)new GeometryArrayStorage<NiPoint3>[iTotalVertexCount];
                B61Color* pkColor = new B61Color[iTotalVertexCount];
                B61UV* pkTexture = new B61UV[iTotalVertexCount];
                pkNumbers = new B61Float[iTotalVertexCount];
                B61Index* v = new B61Index[B61Promote(iListLen) * usCopies];
                int pkSrcVertex = 0;
                NiPoint3* pkSrcNormal = pkData->m_pkNormal;
                B61Color* pkSrcColor = pkData->m_pkColor;
                B61UV* pkSrcTexture = pkData->m_pkTexture;
                for (int iRow = 0; iRow < usCopies; iRow++)
                {
                    unsigned int iBase = iRow * usVerts;
                    for (int i = 0; i < usVerts; i++)
                    {
                        long k = iBase + i;
                        pkVertex[k] = n[i];
                        pkNormal[k] = pkSrcNormal[i];
                        pkColor[k] = pkSrcColor[i];
                        pkTexture[k] = pkSrcTexture[i];
                        pkNumbers[k].f = (float)iRow;
                    }
                    for (int j = 0; j < iListLen; j++)
                    {
                        v[pkSrcVertex].us = pusTriList[j] + iBase;
                        pkSrcVertex++;
                    }
                }
                int iTris = iListLen / 3;
                usGroup = iTris;
                pkNewData = new B61TriShapeData(usCopies * usVerts, pkVertex, pkNormal, pkColor, pkTexture, 1, 0,
                                                iTris * usCopies, v, usCopies * usVerts, 0);
            }
            else
            {
                ucStrips = 1;
                B61Data* pkData = pkGeom->m_pUserData;
                usVerts = pkData->m_usVertices;
                unsigned short* pusLengths = pkData->m_pusStripLengths;
                NiPoint3* n = pkData->m_pkVertex;
                unsigned short* pusStrips = pkData->FUN_00a75f10();
                unsigned short usMax = 0xffff / usVerts;
                if (usCopies >= usMax)
                    usCopies = usMax;
                long iLen = *pusLengths;
                usMax = 0xffff / (iLen + (iLen % 2 ? 3 : 2));
                if (usCopies >= usMax)
                    usCopies = usMax;
                NiPoint3* pkVertex;
                pkVertex = (NiPoint3*)new GeometryArrayStorage<NiPoint3>[usCopies * usVerts];
                NiPoint3* pkNormal = (NiPoint3*)new GeometryArrayStorage<NiPoint3>[usCopies * usVerts];
                B61Color* pkColor = new B61Color[usCopies * usVerts];
                B61UV* pkTexture = new B61UV[usCopies * usVerts];
                pkNumbers = new B61Float[usCopies * usVerts];
                unsigned short usLen = *pusLengths;
                unsigned short usStride = usLen + (usLen % 2 ? 3 : 2);
                B61Index* v = new B61Index[(usCopies - 1) * usStride + usLen];
                int pkSrcVertex = 0;
                NiPoint3* pkSrcNormal = pkData->m_pkNormal;
                B61Color* pkSrcColor = pkData->m_pkColor;
                B61UV* pkSrcTexture = pkData->m_pkTexture;
                for (int iRow = 0; iRow < usCopies; iRow++)
                {
                    long pObj = iRow * usVerts;
                    FUN_00ec44d0(&pkVertex[pObj], n, usVerts * sizeof(NiPoint3));
                    FUN_00ec44d0(&pkNormal[pObj], pkSrcNormal, usVerts * sizeof(NiPoint3));
                    FUN_00ec44d0(&pkColor[pObj], pkSrcColor, usVerts * sizeof(B61Color));
                    FUN_00ec44d0(&pkTexture[pObj], pkSrcTexture, usVerts * sizeof(B61UV));
                    for (int i = 0; i < usVerts; i++)
                        pkNumbers[i + pObj].f = (float)iRow;
                    for (int j = 0; j < *pusLengths; j++)
                        v[pkSrcVertex++].us = pusStrips[j] + iRow * usVerts;
                    if (iRow < (int)usCopies - 1)
                    {
                        long usRow = iRow;
                        v[pkSrcVertex++].us = pusStrips[*pusLengths - 1] + usRow * usVerts;
                        v[pkSrcVertex++].us = pusStrips[0] + (usRow + 1) * usVerts;
                        if (*pusLengths % 2 == 1)
                            v[pkSrcVertex++].us = pusStrips[0] + (usRow + 1) * usVerts;
                    }
                }
                unsigned short* pusNewLengths = (unsigned short*)g_memoryManager.Allocate(2);
                pusNewLengths[0] = pkSrcVertex;
                int length = *pusLengths;
                if (length % 2 == 1)
                    usGroup = length + 3;
                else
                    usGroup = length + 2;
                pkNewData = new B61TriStripsData(usCopies * usVerts, pkVertex, pkNormal, pkColor, pkTexture, 1, 0,
                                                 pkSrcVertex - 2, 1, pusNewLengths, v, usCopies * usVerts, 0);
            }
            NiPointer<B61Ref> spShader;
            if (pkGeom->FUN_00a59d30(3) && ((B61TexProp*)pkGeom->FUN_00a59d30(3))->IsShaderType())
            {
                B61TexProp* pkTex = (B61TexProp*)pkGeom->FUN_00a59d30(3);
                if (pkTex)
                {
                    B61Ref* pkShader = pkTex->GetGeometryShaderObject();
                    spShader = pkShader;
                }
            }
            B61Property* resultAlpha = pkGeom->FUN_00a59d30(0);
            unsigned int uiTestRef = 0;
            B61Property* pkAlpha = resultAlpha;
            if (pkAlpha)
                uiTestRef = pkAlpha->m_ucTestRef;
            else
                pkAlpha = (B61Property*)new B61AlphaProperty;
            pkAlpha->m_ucTestRef = uiTestRef;
            pkAlpha->m_usFlags = (pkAlpha->m_usFlags & 0xf3ff) | 0x1201;
            B61Property* q = (B61Property*)new B61AlphaProperty;
            q->m_ucTestRef = uiTestRef;
            q->m_usFlags = (q->m_usFlags & 0xf3fe) | 0x1200;
            B61Property* pkExtra = pkGeom->FUN_00a59d30(4);
            B61Bound kBound = pkGeom->m_pUserData->m_kBound;
            spEntry->m_ucStrips = ucStrips;
            spEntry->m_spTransformData = pkNewData;
            spEntry->m_pkNumbers = pkNumbers;
            spEntry->m_iWidth = usVerts;
            spEntry->m_pGeometryShader = spShader;
            spEntry->m_spAlpha2 = q;
            spEntry->m_spAlpha = pkAlpha;
            spEntry->m_spExtra = pkExtra;
            spEntry->m_fBoundRadius = kBound.r;
            spEntry->m_iCopies = usCopies;
            spEntry->m_usGroup = usGroup;
            spEntry->m_ucKind = 0;
            if (kIter)
            {
                B61AVObject* pkKind = B61IsKindOf(&DAT_011f4aa0, kIter) ? kIter : 0;
                if (pkKind)
                    spEntry->m_ucKind = 1;
            }
            B61Notify(*ppcName);
        }
        else
            return 0;
    }
    return spEntry;
}

struct ShaderVector
{
    float x, y, z;
    float FUN_00457990();
    ShaderVector* ScaleTo(ShaderVector* result, float factor);
    float ComputeWeightedSum();
    float Luminance() const
    {
        return static_cast<float>(y * DAT_010ae8c0 + x * DAT_010ae8b8 + z * DAT_010ae8b0);
    }
};
struct ShaderColor
{
    float r, g, b, a;
    ShaderColor()
    {}
    ShaderColor(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha)
    {}
};
struct ShaderTransform
{
    int unk00;
    ShaderVector* SubtractIntoVector(ShaderVector* result, const ShaderVector* source);
};
struct RenderProperty
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual float GetOpacity();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int flags20, flags24;
    float alpha;
    void* BSShaderLightingProperty_GetFirstActiveNonShadowLight(unsigned int* index);
};
struct ShaderCameraBlock
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    ShaderVector* position;
    __forceinline ShaderVector*& PositionRef()
    {
        return position;
    }
};
struct ShaderType
{
    void* vtable;
    unsigned short type;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char count;
};
struct FadeConfig
{
    int unk00, unk04;
    bool enabled;
};
extern FadeConfig* DAT_011fec3c;
extern "C" ShaderColor DAT_011FA0C0;
extern float DAT_011fd95c;
extern float DAT_011fa27c;
extern unsigned int DAT_011f91e4;
double __cdecl BSMAX_0068b050(double minimum, float value);
double __cdecl __hkMinD(double maximum, double value);
struct SceneVectorData
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88;
    ShaderTransform transform;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC;
    int unkC0;
    float factor;
    int unkC8, unkCC, unkD0;
    ShaderVector color;
    float radius;
    ShaderVector GetColor() const
    {
        return color;
    }
};
struct ShaderLink
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC;
    ShaderLink* linkE0;
    int unkE4, unkE8, unkEC, unkF0, unkF4;
    SceneVectorData* scene;
};
struct ShaderSourceRecord
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    union
    {
        unsigned short flags;
        unsigned char flagsLo;
        struct
        {
            unsigned short low9 : 9;
            unsigned short m_bBit9 : 1;
        } bits;
    };
};
struct ShaderGeometry
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98;
    ShaderSourceRecord* property;
};
static inline double S00b7ba70_Max(double a, double b)
{
    return a > b ? a : b;
}
static inline double S00b7ba70_Inv(double c)
{
    return 1.0 - c;
}
static inline ShaderType* S00b7ba70_Index()
{
    return reinterpret_cast<ShaderType*>(DAT_011f91e0);
}
struct S00b7ba70_Updater
{
    void ApplySourceColor(void*);
    void AccumulateLightColor(void*);
    void ShadowLightShader_SetupGeometryConstants_AmbientEmittance(RenderProperty*, ShaderType*, ShaderGeometry*, void*);
};
// Updates global shader color and alpha based on property flags, light falloff, and shader type, then applies mode-specific overrides.
// @fnv 0x00b7ba70
// src: COMMUNITY 0x00b7ba70
void S00b7ba70_Updater::ShadowLightShader_SetupGeometryConstants_AmbientEmittance(RenderProperty* property, ShaderType* shader, ShaderGeometry* geometry,
                                     void* state)
{
    ShaderColor current = DAT_011FA0C0;
    DAT_011FA0C0 = ShaderColor(current.r, current.g, current.b, property->alpha);
    ShaderType* index = S00b7ba70_Index();
    if (DAT_011fec3c->enabled && (shader->type < 195 || shader->type > 214))
        ApplySourceColor(state);
    else
        AccumulateLightColor(state);
    if (shader->type >= 195 && shader->type <= 214)
    {
        DAT_011fd95c = static_cast<float>(shader->count);
        DAT_011fa27c = static_cast<float>(shader->count);
    }
    if (DAT_011f91a7)
        DAT_011FA0C0 = ShaderColor(1.0f, 1.0f, 1.0f, 1.0f);
    if ((property->flags24 & 0x8000) > 0 && (property->flags20 & 0x20000) <= 0 && index->type >= 580 &&
        index->type <= 587)
    {
        unsigned int alpha = 0;
        float x = 0.0f;
        ShaderLink* light = static_cast<ShaderLink*>(property->BSShaderLightingProperty_GetFirstActiveNonShadowLight(&alpha));
        ShaderVector falloff = reinterpret_cast<ShaderLink*>(DAT_011f91c8)->linkE0->scene->GetColor();
        float gp = falloff.Luminance();
        if (light)
        {
            ShaderLink* __restrict view = light;
            ShaderVector* source = (*reinterpret_cast<ShaderCameraBlock* volatile*>(DAT_011f91e0))->PositionRef();
            ShaderVector* position = source;
            if (position == 0)
                position = reinterpret_cast<ShaderVector*>(&DAT_011f4288);
            SceneVectorData* scene = view->scene;
            ShaderVector relative, scaled;
            scene->transform.SubtractIntoVector(&relative, position);
            SceneVectorData* colourScene = light->scene;
            colourScene->color.ScaleTo(&scaled, colourScene->factor);
            float distance = relative.FUN_00457990() / scene->radius;
            float color = static_cast<float>(__hkMinD(1.0, BSMAX_0068b050(0.0, distance)));
            volatile float inverse = static_cast<float>(S00b7ba70_Inv(color));
            x = inverse;
            x *= scaled.ComputeWeightedSum();
        }
        x = static_cast<float>(S00b7ba70_Max(x, gp));
        DAT_011FA0C0.a *= x;
    }
    unsigned int mode = DAT_011f91b8;
    if (mode == 8)
    {
        float active = (property->flags24 & 0x20000) > 0 ? 0.0f : 1.0f;
        ShaderSourceRecord* z = geometry->property;
        float blue = (!(z->flagsLo & 1) && !((unsigned char)(z->flags >> 9) & 1)) ? 1.0f : 0.0f;
        DAT_011FA0C0 = ShaderColor(0.0f, 0.0f, blue, active);
    }
    if (DAT_011f91e4 - 580 <= 7 && 10 != mode)
    {
        DAT_011FA0C0.a *= property->GetOpacity();
    }
}

struct ScaleValue
{
    float value;
    ScaleValue(float x) : value(x)
    {}
    operator float() const
    {
        return value;
    }
};
inline float RoundScale(float x)
{
    const float& result = x;
    return result;
}
struct WorkerColor
{
    float r, g, b;
    WorkerColor& operator*=(float value)
    {
        r *= value;
        g *= value;
        b *= value;
        return *this;
    }
};
struct WorkerMaterial
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
    float intensity;
    int unkc8;
    int unkcc;
    int unkd0;
    WorkerColor color;
    WorkerColor GetColor() const
    {
        return color;
    }
};
struct ScaleObject
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
    float dimmer;
    float alpha;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    WorkerMaterial* material;
};
extern double DAT_01012070;
extern float DAT_011f9190;
// Computes a fog color from the material intensity, dimmer scale, and global flags, then stores it in DAT_011fa0d0.
// @fnv 0x00b7c600
// src: COMMUNITY 0x00b7c600
void FUN_00b7deb0_class::ShadowLightShader_SetupPassOpt_LightColor()
{
    ScaleObject*& object = (ScaleObject*&)DAT_011f91e0->unk0c->unk00;
    WorkerMaterial* material = object->material;
    float intensity = material->intensity;
    if (!DAT_011f941e && intensity > DAT_01012070)
        intensity = 1.0f;
    ScaleValue dimmer = RoundScale(object->dimmer);
    WorkerColor source = material->GetColor();
    source *= intensity;
    WorkerColor color = source;
    color *= dimmer;
    if (DAT_011f941e && !DAT_011f9427)
        color *= DAT_011f9190;
    DAT_011fa0d0 = FogVector(color.r, color.g, color.b, object->alpha);
}

namespace fnv_00b60790 {
#include <intrin.h>

struct ThreadState
{
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
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int context;
};
extern volatile unsigned int DAT_0126fd98;
struct MemScope
{
    ThreadState* state;
    unsigned int old;
    __forceinline MemScope()
    {
        unsigned int index = DAT_0126fd98;
        state = ((ThreadState**)__readfsdword(0x2c))[index];
        old = state->context;
        state->context = 0x1c;
    }
    __forceinline ~MemScope()
    {
        state->context = old;
    }
};
struct PassArray
{
    int unk00;
    void** passes;
    int unk08, unk0c;
    unsigned int count;
    void FUN_00ba9ee0(void* geometry, unsigned short pass, bool enabled, unsigned char lights, void* l0, void* l1,
                      void* l2, void* l3);
};
struct Light
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
    unsigned char active;
};
extern unsigned char DAT_011f9ef0, DAT_011f9427, DAT_011f941e;
extern int shaderFlags;
extern int DAT_011f95e4, DAT_011f91c0;
extern float DAT_011fd890;
void __cdecl BSShaderProperty_RenderPass_SetLights(void*, int, void*);
inline int ShadowFeatureEnabled()
{
    return (shaderFlags & 16) > 0;
}
struct ShaderPassBuilder
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int flags;
    int unk28, unk2c, unk30, unk34;
    unsigned int cached;
    NiPointer<PassArray> array;
    void FUN_00ba95e0(int);
    unsigned short BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
    void* BSShaderLightingProperty_GetFirstActiveNonShadowLight(void**);
    Light* FUN_00b70590(void**);
    Light* BSShaderLightingProperty_GetNextActiveLight(void**);
    PassArray* TallGrassShaderProperty_GetRenderPasses(void*, unsigned int, int, unsigned int, int, int);
};
// @fnv 0x00b60790
// src: XBOX_PDB 0x00b60790
PassArray* ShaderPassBuilder::TallGrassShaderProperty_GetRenderPasses(void* geometry, unsigned int mode, int unused, unsigned int variant,
                                           int unused2, int FlushUsageData)
{
    MemScope scope;
    if (cached != mode)
    {
        FUN_00ba95e0(2);
        array->count = 0;
        void* position = 0;
        unsigned short lightCount = DAT_011f9ef0 ? BSShaderLightingProperty_GetNumberofActiveNonShadowLights() : 0;
        bool special = (flags & 0x400) > 0;
        bool textured = (flags & 0x1000) > 0;
        bool alternate = (flags & 0x2000) > 0;
        bool extra = !DAT_011f9427 && DAT_011f95e4 && (shaderFlags & 0x20) && DAT_011f91c0 >= 2 &&
                     (unsigned int)DAT_011fd890 != 0;
        unsigned int pass = (DAT_011f941e ? 0x246 : 0);
        unsigned short noLights = 0;
        pass += lightCount > noLights ? 0x14 : 0;
        if (special)
        {
            if (textured)
            {
                if (!extra)
                    array->FUN_00ba9ee0(geometry, pass + 0x19, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00ba9ee0(geometry, pass + 0x21, true, 0, 0, 0, 0, 0);
            }
            else
            {
                if (!extra)
                    array->FUN_00ba9ee0(geometry, pass + 0x17, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00ba9ee0(geometry, pass + 0x1f, true, 0, 0, 0, 0, 0);
            }
        }
        else if (textured)
        {
            if (alternate)
                array->FUN_00ba9ee0(geometry, pass + 0x27, true, 0, 0, 0, 0, 0);
            else
            {
                if (!extra)
                    array->FUN_00ba9ee0(geometry, pass + 0x18, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00ba9ee0(geometry, pass + 0x20, true, 0, 0, 0, 0, 0);
            }
        }
        else
        {
            if (alternate)
                array->FUN_00ba9ee0(geometry, pass + 0x26, true, 0, 0, 0, 0, 0);
            else
            {
                if (!extra)
                    array->FUN_00ba9ee0(geometry, pass + 0x16, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00ba9ee0(geometry, pass + 0x1e, true, 0, 0, 0, 0, 0);
            }
        }
        if (lightCount > 0)
        {
            void* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&position);
            BSShaderProperty_RenderPass_SetLights(array->passes[array->count - 1], 1, light);
        }
        if (DAT_011f91c0 >= 3)
        {
            int enabled = ShadowFeatureEnabled();
            const bool& bShadow = *(bool*)&enabled;
            if (bShadow)
            {
                Light* light = FUN_00b70590(&position);
                while (light)
                {
                    if (light->active)
                    {
                        if (textured)
                        {
                            if (alternate)
                                array->FUN_00ba9ee0(geometry, 0x287, false, 1, light, 0, 0, 0);
                            else
                                array->FUN_00ba9ee0(geometry, 0x285, false, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            if (alternate)
                                array->FUN_00ba9ee0(geometry, 0x286, false, 1, light, 0, 0, 0);
                            else
                                array->FUN_00ba9ee0(geometry, 0x284, false, 1, light, 0, 0, 0);
                        }
                    }
                    light = BSShaderLightingProperty_GetNextActiveLight(&position);
                }
            }
        }
        cached = mode | (variant << 8);
    }
    return array;
}
}  // namespace fnv_00b60790

namespace fnv_00b6b0b0 {
#include <windows.h>


extern NiRefObject* DAT_011fa024[];
extern int DAT_011fa020;
// Pops the last entry from the pool reference array, decrements its reference count, and destroys the object if the count reaches zero.
// @fnv 0x00b6b0b0
// src: COMMUNITY 0x00b6b0b0
void __cdecl BSRenderedTexture_Pop()
{
    if (DAT_011fa020 == 0)
        return;
    --DAT_011fa020;
    NiRefObject** slot = &DAT_011fa024[DAT_011fa020];
    NiRefObject* obj = *slot;
    if (obj != 0)
    {
        if (InterlockedDecrement((volatile long*)&obj->m_uiRefCount) == 0)
            obj->DeleteThis();
        *slot = 0;
    }
}
}  // namespace fnv_00b6b0b0

namespace fnv_00b6b380 {
struct Rtti
{
    const char* name;
    Rtti* parent;
};
extern Rtti DAT_012708e4;
struct Ref
{
    virtual void Slot0();
    virtual void Destroy();
    virtual Rtti* GetRTTI();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void* GetTexture();
    long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
};
struct Base
{
    Base();
    virtual ~Base();
    int refs;
};
struct Pixel : Ref
{
};
struct Node : Ref
{
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
    void* faces[6];
};
int __cdecl BSRenderedTexture_GetDepthStencilBuffer(Node*, int);
Pixel* __cdecl NiRenderTargetGroup_Create_(void*, void*, int);
struct FUN_00b6b380 : Base
{
    NiPointer<Pixel> textures[6];
    NiPointer<Node> extra0, extra1, extra2;
    int state;
    NiPointer<Node> nodes[4];
    FUN_00b6b380(Node* source, bool option, int arg);
    virtual ~FUN_00b6b380();
};
inline Node* CastCube(Node* source)
{
    Rtti* type = source ? source->GetRTTI() : 0;
    while (type)
    {
        if (type == &DAT_012708e4)
            return source;
        type = type->parent;
    }
    return 0;
}
// Initializes textures from a Node's faces or texture, setting extra pointers to null and state to -1.
// @fnv 0x00b6b380
FUN_00b6b380::FUN_00b6b380(Node* source, bool option, int arg)
{
    nodes[0] = source;
    int mode = option ? BSRenderedTexture_GetDepthStencilBuffer(source, arg) : 0;
    Node* cube = CastCube(source);
    if (!cube)
    {
        textures[0] = NiRenderTargetGroup_Create_(source->GetTexture(), DAT_011f4748, mode);
        for (int index = 1; index < 6; ++index)
            textures[index] = 0;
    }
    else
    {
        for (int index = 0; index < 6; ++index)
        {
            void* surface = cube->faces[index];
            textures[index] = NiRenderTargetGroup_Create_(surface, DAT_011f4748, mode);
        }
    }
    extra0 = 0;
    extra1 = 0;
    extra2 = 0;
    state = -1;
}
}  // namespace fnv_00b6b380

struct Mode200
{
    int unk00;
    unsigned short id;
    unsigned short unk06;
    unsigned char unk08, unk09, unk0a, flag;
};

extern int DAT_011f951c;
struct Texture200
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
};
struct Shader200
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    Texture200* unkac;
    Texture200* unkb0;
    int* unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned unkcc;
    unsigned unkd0;
    unsigned unkd4;
    unsigned unkd8;
    Texture200* unkdc;
};
struct Arg200
{
    int unk00, unk04, unk08;
    Shader200* shader;
};
struct Stage200
{
    int unk00, unk04;
    int texture;
};
struct Stages200
{
    Stage200* unk00;
    Stage200* unk04;
    Stage200* unk08;
    Stage200* unk0c;
    Stage200* unk10;
    Stage200* unk14;
    Stage200* unk18;
    Stage200* unk1c;
    Stage200* unk20;
    Stage200* unk24;
    Stage200* unk28;
    Stage200* unk2c;
    Stage200* unk30;
    Stage200* unk34;
};
// Shader-pass owner: DAT_0126f74c receives StageMgr in 0x00b7ad00 and holds passes at +0x24, unlike NiRenderer.
struct ShaderPassArrayOwner
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
    Stages200* unk24;
};
struct Host200
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
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    void ShadowLightShader_SetDiffuseMap(Shader200*, int, int);
    void ShadowLightShader_SetNormalMap(Shader200*, int, int);
    void SetSlotValue(Shader200*, int, int);
    void ShadowLightShader_SetCubeMap(Shader200*, int, int);
    void UpdateSlotFromGlobal(int);
    void ShadowLightShader_SetShadowMap(int);
    void ShadowLightShader_SetClampMode(Stage200*, Shader200*);
    void ShadowLightShader_SetupGeometryTextures(Arg200*);
};
// Switches on the current mode id to call stage helpers and set renderer stage textures from the argument's shader or fallback textures, then calls v108.
// @fnv 0x00b7d200
// src: COMMUNITY 0x00b7d200
void Host200::ShadowLightShader_SetupGeometryTextures(Arg200* arg)
{
    unsigned mode = ((Mode200*)DAT_011f91e0)->id;
    Shader200* shader = arg->shader;
    ShaderPassArrayOwner* renderer = (ShaderPassArrayOwner*)DAT_0126f74c;
    bool enabled = true;
    if ((shader->unk24 & 0x100000) > 0)
        enabled = false;
    switch (mode)
    {
    case 196:
    case 199:
    case 203:
    case 206:
    case 255:
    case 262:
    case 268:
    case 274:
    case 279:
    case 285:
    case 290:
    case 296:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetNormalMap(shader, 1, false);
        {
            Stage200* stage = ((ShaderPassArrayOwner*)DAT_0126f74c)->unk24->unk10;
            int texture = *shader->unkb4;
            if (texture)
                stage->texture = texture;
            else
                stage->texture = DAT_011f951c;
        }
        break;
    case 216:
    case 221:
    case 225:
    case 230:
    case 234:
    case 239:
    case 243:
    case 248:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetNormalMap(shader, 1, false);
        {
            Stage200* stage = ((ShaderPassArrayOwner*)DAT_0126f74c)->unk24->unk0c;
            int texture = *shader->unkb4;
            if (texture)
                stage->texture = texture;
            else
                stage->texture = DAT_011f951c;
        }
        break;
    case 102:
    case 103:
    case 107:
    case 108:
    case 113:
    case 114:
    case 118:
    case 119:
    case 129:
    case 130:
    case 134:
    case 135:
    case 139:
    case 140:
    case 144:
    case 145: {
        Stage200* stage = ((ShaderPassArrayOwner*)DAT_0126f74c)->unk24->unk08;
        int texture = *shader->unkb4;
        if (texture)
            stage->texture = texture;
        else
            stage->texture = DAT_011f951c;
    }
    case 100:
    case 101:
    case 105:
    case 106:
    case 111:
    case 112:
    case 116:
    case 117:
    case 127:
    case 128:
    case 131:
    case 132:
    case 137:
    case 138:
    case 141:
    case 142:
    case 195:
    case 198:
    case 201:
    case 205:
    case 215:
    case 220:
    case 224:
    case 229:
    case 233:
    case 238:
    case 242:
    case 247:
    case 251:
    case 261:
    case 266:
    case 273:
    case 278:
    case 284:
    case 289:
    case 295:
    case 565:
        ShadowLightShader_SetNormalMap(shader, 1, false);
    case 2:
    case 6:
    case 7:
    case 8:
    case 17:
    case 19:
    case 88:
    case 90:
    case 92:
    case 94:
    case 98:
    case 99:
    case 330:
    case 333:
    case 334:
    case 335:
    case 595:
    case 597:
    case 734:
    case 735:
    case 746:
    case 747:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        break;
    case 150:
    case 156:
    case 161:
    case 167:
    case 172:
    case 178:
    case 183:
    case 189:
    case 210:
    case 213: {
        Stage200* stage = ((ShaderPassArrayOwner*)DAT_0126f74c)->unk24->unk10;
        int texture = *shader->unkb4;
        if (texture)
            stage->texture = texture;
        else
            stage->texture = DAT_011f951c;
    }
    case 149:
    case 155:
    case 160:
    case 166:
    case 171:
    case 177:
    case 182:
    case 188:
    case 208:
    case 212:
    case 267:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetNormalMap(shader, 1, false);
        break;
    case 584:
    case 585:
    case 586:
        SetSlotValue(shader, 3, false);
        ShadowLightShader_SetCubeMap(shader, 1, false);
    case 341:
    case 343:
    case 346:
    case 347:
    case 349:
    case 350:
    case 352:
    case 353:
    case 355:
    case 356:
    case 358:
    case 359:
    case 361:
    case 362:
    case 364:
    case 365:
    case 367:
    case 368:
    case 370:
    case 371:
    case 373:
    case 374:
    case 587:
        ShadowLightShader_SetNormalMap(shader, 0, false);
        break;
    case 580:
    case 581:
    case 582:
    case 583:
        SetSlotValue(shader, 2, false);
        ShadowLightShader_SetCubeMap(shader, 3, false);
    case 124:
    case 125:
    case 300:
    case 301:
    case 302:
    case 303:
    case 306:
    case 309:
    case 318:
    case 321:
    case 340:
    case 342:
    case 482:
    case 483:
    case 484:
        ShadowLightShader_SetNormalMap(shader, 0, false);
        break;
    case 89:
    case 91:
    case 93:
    case 95:
    case 497:
    case 500:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        {
            Stage200* stage = ((ShaderPassArrayOwner*)DAT_0126f74c)->unk24->unk04;
            int texture = *shader->unkb4;
            if (texture)
                stage->texture = texture;
            else
                stage->texture = DAT_011f951c;
        }
        break;
    case 726:
    case 727: {
        Stage200* stage = ((ShaderPassArrayOwner*)DAT_0126f74c)->unk24->unk00;
        int texture = *shader->unkb4;
        if (texture)
            stage->texture = texture;
        else
            stage->texture = DAT_011f951c;
    }
    break;
    case 331:
    case 336:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetDiffuseMap(shader, 1, true);
        ShadowLightShader_SetNormalMap(shader, 2, true);
        break;
    case 104:
    case 109:
    case 115:
    case 120:
    case 133:
    case 143:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetNormalMap(shader, 1, false);
        ShadowLightShader_SetDiffuseMap(shader, 2, true);
        ShadowLightShader_SetNormalMap(shader, 3, true);
        break;
    case 332:
    case 338:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetDiffuseMap(shader, 1, true);
        break;
    case 151:
    case 157:
    case 162:
    case 168:
    case 173:
    case 179:
    case 184:
    case 190:
    case 260:
    case 265:
    case 272:
    case 277:
    case 283:
    case 288:
    case 294:
    case 299:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetNormalMap(shader, 1, false);
        ShadowLightShader_SetDiffuseMap(shader, 4, true);
        break;
    case 254:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetNormalMap(shader, 1, false);
        ShadowLightShader_SetDiffuseMap(shader, 4, true);
        ShadowLightShader_SetNormalMap(shader, 6, true);
        UpdateSlotFromGlobal(7);
        break;
    case 561:
    case 562:
    case 563:
        ShadowLightShader_SetDiffuseMap(shader, 0, false);
        ShadowLightShader_SetShadowMap(6);
        break;
    case 147:
    case 148:
    case 495:
    case 496:
    case 498:
    case 499:
    case 501:
    case 502: {
        int flag = ((Mode200*)DAT_011f91e0)->flag;
        ShadowLightShader_SetDiffuseMap(shader, 0, flag);
        ShadowLightShader_SetNormalMap(shader, 1, flag);
    }
    break;
    case 560: {
        int flag = ((Mode200*)DAT_011f91e0)->flag;
        ShadowLightShader_SetDiffuseMap(shader, 0, flag);
        ShadowLightShader_SetNormalMap(shader, 1, flag);
        UpdateSlotFromGlobal(2);
    }
    break;
    case 551:
    case 552:
    case 553:
    case 554:
    case 555:
    case 556:
    case 557:
    case 558:
        renderer->unk24->unk18->texture = shader->unkac->unk18;
        if (enabled)
            renderer->unk24->unk34->texture = shader->unkb0->unk18;
    case 543:
    case 544:
    case 545:
    case 546:
    case 547:
    case 548:
    case 549:
    case 550:
        renderer->unk24->unk14->texture = shader->unkac->unk14;
        if (enabled)
            renderer->unk24->unk30->texture = shader->unkb0->unk14;
    case 535:
    case 536:
    case 537:
    case 538:
    case 539:
    case 540:
    case 541:
    case 542:
        renderer->unk24->unk10->texture = shader->unkac->unk10;
        if (enabled)
            renderer->unk24->unk2c->texture = shader->unkb0->unk10;
    case 527:
    case 528:
    case 529:
    case 530:
    case 531:
    case 532:
    case 533:
    case 534:
        renderer->unk24->unk0c->texture = shader->unkac->unk0c;
        if (enabled)
            renderer->unk24->unk28->texture = shader->unkb0->unk0c;
    case 519:
    case 520:
    case 521:
    case 522:
    case 523:
    case 524:
    case 525:
    case 526:
        renderer->unk24->unk08->texture = shader->unkac->unk08;
        if (enabled)
            renderer->unk24->unk24->texture = shader->unkb0->unk08;
    case 511:
    case 512:
    case 513:
    case 514:
    case 515:
    case 516:
    case 517:
    case 518:
        renderer->unk24->unk04->texture = shader->unkac->unk04;
        if (enabled)
            renderer->unk24->unk20->texture = shader->unkb0->unk04;
    case 503:
    case 504:
    case 505:
    case 506:
    case 507:
    case 508:
    case 509:
    case 510:
        renderer->unk24->unk00->texture = shader->unkac->unk00;
        if (enabled)
            renderer->unk24->unk1c->texture = shader->unkb0->unk00;
        break;
    case 4:
    case 5: {
        Stage200* stage = renderer->unk24->unk00;
        Texture200* texture = shader->unkdc;
        if (texture && texture->unk6c)
            stage->texture = texture->unk6c;
        else
            stage->texture = (int)DAT_011f952c;
        ShadowLightShader_SetClampMode(stage, shader);
    }
    break;
    default:
        return;
    }
    v108();
}

struct FNVColorRGB
{
    float red, green, blue;
};
struct FNVColorRGBA
{
    float red, green, blue, alpha;
};
extern float DAT_011fa0c0;

// Reads the current RGB color from the active renderer's state and stores it as an RGBA value with full opacity into DAT_011fa0c0.
// @fnv 0x00b7c580
// src: COMMUNITY 0x00b7c580
void FUN_00b7deb0_class::ShadowLightShader_SetupPassOpt_AmbientLight()
{
    char* manager = reinterpret_cast<char*>(DAT_011f91e0);
    char* slot = *reinterpret_cast<char**>(manager + 0x0c);
    char* renderer = *reinterpret_cast<char**>(slot);
    char* state = *reinterpret_cast<char**>(renderer + 0xf8);
    FNVColorRGB rgb = *reinterpret_cast<FNVColorRGB*>(state + 0xc8);
    FNVColorRGBA color = {rgb.red, rgb.green, rgb.blue, 1.0f};
    *reinterpret_cast<FNVColorRGBA*>(&DAT_011fa0c0) = color;
}

struct B64440Q
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float m_1c;
};

struct B64440A2
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
    B64440Q* m_b8;
};

// @fnv 0x00b64440
// src: GUESS 0x00b64440 (confidence: low)
bool __cdecl Object_ProcessAndReturnValue_00b64440(RSSettings* apSettings, B64440A2* a2, void* a3, RSPacket* apPacket, RSResponse* apResponse)
{
    if (a2->m_b8->m_1c < 50.0)
        return true;
    if (apResponse->m_iType == 0x16)
        return true;
    if ((apPacket->m_uiFlags2 & 0x40000) <= 0)
        return true;
    return ProcessCommands(apSettings, a2, a3, apPacket, apResponse);
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

// Clears the room-sharing map while holding its critical section.
// @fnv 0x00b63b60
// src: XBOX_PDB 0x00b63b60
void ShaderAccumulatorLocal::BSShaderAccumulator_ClearSharedMap()
{
    EnterCriticalSection(&BSCPSharedCrit);
    kRoomSharedMap.RemoveAll();
    LeaveCriticalSection(&BSCPSharedCrit);
}
