
// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp
// NiGeomMorpherController: morph-target interpolator management.
#include "nigeommorphercontroller.h"

// Searches the morph targets for one whose name handle matches kID and returns its index, or INVALID_INDEX if none match.
// @fnv 0x00a3aeb0
unsigned short NiGeomMorpherController::GetTargetIndex(const NiFixedString& kID) const
{
    for (unsigned short us = 0; us < GetNumTargets(); us++)
    {
        NiMorphData::MorphTarget* pkTarget = m_spMorphTargetData.m_pObject->GetTarget(us);
        if (pkTarget->GetName().m_kHandle == kID.m_kHandle)
            return us;
    }

    return INVALID_INDEX;
}

// @fnv 0x00a3add0
unsigned short NiGeomMorpherController::GetTargetIndex(const char* pcName) const
{
    if (!pcName)
        return INVALID_INDEX;

    for (unsigned short us = 0; us < GetNumTargets(); us++)
    {
        NiMorphData::MorphTarget* pkTarget = m_spMorphTargetData.m_pObject->GetTarget(us);
        if (NiStricmp(pkTarget->GetName().m_kHandle, pcName) == 0)
            return us;
    }

    return INVALID_INDEX;
}

// @fnv 0x00a3bbf0
AnimationKey::KeyContent NiColorInterpolator::GetColorKeyContent(unsigned short) const
{
    return AnimationKey::COLORKEY;
}

// @fnv 0x00a3bc00
unsigned int NiColorInterpolator::GetColorKeyCount(unsigned short) const
{
    if (!m_spColorData.m_pObject)
        return 0;

    return m_spColorData.m_pObject->m_uiNumKeys;
}

// @fnv 0x00a3bc10
AnimationKey::KeyType NiColorInterpolator::GetColorKeyType(unsigned short) const
{
    if (!m_spColorData.m_pObject)
        return AnimationKey::NOINTERP;

    return m_spColorData.m_pObject->m_eRequestType;
}

// @fnv 0x00a3bc20
unsigned char NiColorInterpolator::GetColorKeySize(unsigned short) const
{
    if (!m_spColorData.m_pObject)
        return 0;

    return m_spColorData.m_pObject->m_ucKeyDataSize;
}

// @fnv 0x00a3bc40
bool NiColorInterpolator::IsColorConstant(unsigned short) const
{
    if (m_spColorData.m_pObject)
        return false;

    return m_kColorValue.FUN_004a4cc0(DAT_011a9430) ? false : true;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a3ba70_shell : public NiGeomMorpherController
{
    void FUN_00a3ba70(NiGeomMorpherController*, CloningProcess*);
};

extern bool DAT_011f3724;

// Copies interpolator pointers and weights from this controller into pkDest, cloning each interpolator and updating reference counts.
// @fnv 0x00a3ba70
void FUN_00a3ba70_shell::FUN_00a3ba70(NiGeomMorpherController* pkDest, CloningProcess* kCloning)
{
    NiInterpController::CopyMemberData(pkDest, *kCloning);
    pkDest->m_uiObjectFlags = m_uiObjectFlags;
    if (m_spMorphTargetData.m_pObject)
    {
        pkDest->SetMorphData(m_spMorphTargetData.m_pObject, pkDest->m_pkTarget != 0);
    }

    if (DAT_011f3724)
    {
        m_bNeedsUpdate = true;
        pkDest->m_bNeedsUpdate = true;
    }

    for (unsigned short us = 0; us < GetNumTargets(); us++)
    {
        InterpItem& kInterpItem = m_pInterpolatorItems[us];
        if (kInterpItem.m_spControllerInterpolator.m_pObject)
        {
            NiInterpolator* pkNew = kInterpItem.m_spControllerInterpolator.m_pObject->FUN_00a5d3f0(*kCloning);
            NiPointer<NiInterpolator>& spDest = pkDest->m_pInterpolatorItems[us].m_spControllerInterpolator;
            if (spDest.m_pObject != pkNew)
            {
                if (spDest.m_pObject)
                    spDest.m_pObject->DecRefCount();
                spDest.m_pObject = pkNew;
                if (pkNew)
                    pkNew->IncRefCount();
            }
        }
        pkDest->m_pInterpolatorItems[us].m_fWeight = kInterpItem.m_fWeight;
    }
}

// Returns the name handle of the morph target at index us from the controller's NiMorphData.
// @fnv 0x00a3a870
char* __fastcall GetMorphTargetName(NiGeomMorpherController* self, int, unsigned short ausIndex)
{
    NiMorphData* md = *reinterpret_cast<NiMorphData**>(&self->m_spMorphTargetData);
    return md->GetTarget(ausIndex)->GetName().m_kHandle;
}

struct Item8
{
    void* p;
    int q;
};
struct FUN_00a3a8a0_t
{
    char pad[0x3c];
    Item8* items;
};
// @fnv 0x00a3a8a0
void* __fastcall FUN_00a3a8a0(FUN_00a3a8a0_t* self, int unused, unsigned short idx)
{
    return self->items[idx].p;
}

// Stores pkInterpolator into the morph controller's interpolator slot at usIndex, releasing the old interpolator and incrementing the new one's ref count.
// @fnv 0x00a3a8b0
void __fastcall FUN_00a3a8b0(NiGeomMorpherController* self, int, NiInterpolator* pkInterpolator, unsigned short usIndex)
{
    NiInterpolator** slot = reinterpret_cast<NiInterpolator**>(&self->m_pInterpolatorItems[usIndex]);
    NiInterpolator* pOldInterpolator = *slot;
    if (pOldInterpolator != pkInterpolator)
    {
        if (pOldInterpolator)
            pOldInterpolator->DecRefCount();
        *slot = pkInterpolator;
        if (pkInterpolator)
            pkInterpolator->IncRefCount();
    }
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiFloatInterpolator
{
    NiFloatInterpolator* FUN_00a3c390(float);
};
// Reads the morph weight at usIndex from the controller's weight array (or 0.0f) and allocates a NiFloatInterpolator initialized with that value.
// @fnv 0x00a3a900
NiInterpolator* __fastcall CreateMorphWeightInterpolator(NiGeomMorpherController* self, int, unsigned short usIndex)
{
    float fValue = 0.0f;
    if (self->m_pInterpolatorItems)
        fValue = self->m_pInterpolatorItems[usIndex].m_fWeight;
    NiFloatInterpolator* p = static_cast<NiFloatInterpolator*>(BSFadeNode::operator new(0x18));
    if (p)
        return reinterpret_cast<NiInterpolator*>(p->FUN_00a3c390(fValue));
    return 0;
}

struct FUN_00a3a940_t
{
    int a;
    float b;
};
// @fnv 0x00a3a940
FUN_00a3a940_t* __fastcall FUN_00a3a940(FUN_00a3a940_t* self, int)
{
    self->a = 0;
    self->b = 0.0f;
    return self;
}

struct GeomData
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
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
    virtual void s40();
    void SetDirtyFlags(unsigned int);
    int pad[8];
    int f24;
};
struct GeomT
{
    char pad[0xb8];
    GeomData* data;
};
struct FUN_00a3aba0_t
{
    char p0[0x2c];
    GeomT* tgt;
    int nxt;
    unsigned short flags;
    char p1[10];
    bool need;
};
// @fnv 0x00a3aba0
void __fastcall FUN_00a3aba0(FUN_00a3aba0_t* self, int)
{
    if (self->tgt && self->need)
    {
        GeomData* pData = self->tgt->data;
        pData->SetDirtyFlags(1);
        if ((self->flags & 1) && pData->f24)
            pData->s40();
        self->need = false;
    }
}

struct FUN_00a3adc0_md
{
    char pad[8];
    unsigned short count;
};
struct FUN_00a3adc0_t
{
    char pad[0x38];
    FUN_00a3adc0_md* md;
};
// @fnv 0x00a3adc0
unsigned short __fastcall FUN_00a3adc0(FUN_00a3adc0_t* self, int)
{
    if (self->md)
        return self->md->count;
    return 0;
}

struct CloningProcess;
struct NiFloatData;
struct NiFloatInterpolator;
struct TimedAnimationKey;
struct NiStream;
struct FUN_00a3ae50_shell : public NiGeomMorpherController
{
    void FUN_00a3ae50(NiInterpolator*, unsigned short);
};

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f3738;
struct PoseInterpStub
{
    void SetFloatValue(float);
};
struct DynCastHelper
{
    DynCastHelper* DynamicCast(const GlobalObjectO2_00a7b610*);
};
// Reads a float from the morph data array at usIndex and passes it to the interpolator's SetFloatValue after a dynamic cast.
// @fnv 0x00a3ae50
void FUN_00a3ae50_shell::FUN_00a3ae50(NiInterpolator* pkInterp, unsigned short usMorphIndex)
{
    float fValue = 0.0f;
    char* data = *(char**)((char*)this + 0x3c);
    if (data)
        fValue = *(float*)(data + usMorphIndex * 8 + 4);
    PoseInterpStub* pkPoseInterp;
    if (!pkInterp)
        pkPoseInterp = 0;
    else
        pkPoseInterp = (PoseInterpStub*)((DynCastHelper*)pkInterp)->DynamicCast(&g_011f3738);
    pkPoseInterp->SetFloatValue(fValue);
}

namespace fnv_00a3afd0 {
struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_011f3728;
// @fnv 0x00a3afd0
GlobalObjectO2_00a7b610* __cdecl FUN_00a3afd0()
{
    return &g_011f3728;
}
}  // namespace fnv_00a3afd0

struct FUN_00a3afe0_rtti
{
    const char* name;
    const FUN_00a3afe0_rtti* base;
};
extern FUN_00a3afe0_rtti g_011f4a48_arg1;
struct FUN_00a3afe0_tgt
{
    virtual void v0();
    virtual void v1();
    virtual const FUN_00a3afe0_rtti* GetRTTI();
};
struct FUN_00a3afe0_t
{
    char pad[0x2c];
    FUN_00a3afe0_tgt* tgt;
};
// Walks the RTTI base chain of self->tgt and returns true if it reaches g_011f4a48_arg1, otherwise false.
// @fnv 0x00a3afe0
bool __fastcall IsRTTIDerivedFrom(FUN_00a3afe0_t* self, int)
{
    FUN_00a3afe0_tgt* pTgt = self->tgt;
    if (pTgt)
    {
        for (const FUN_00a3afe0_rtti* p = pTgt->GetRTTI(); p; p = p->base)
        {
            if (p == &g_011f4a48_arg1)
                return true;
        }
    }
    return false;
}

struct P03MM
{
    void* Allocate(unsigned int uiSize);
};
extern P03MM g_memoryManager;

struct MorphPoint3
{
    float x, y, z;
    static void* operator new[](unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
};

struct MorphGeomData
{
    void FUN_00a66bb0(unsigned short usVerts, MorphPoint3* pkDest, void* pvA, void* pvB, void* pvC,
                      unsigned int uiFlagA, unsigned int uiFlagB);
    unsigned short GetVertexCount() const
    {
        return *(const unsigned short*)((const char*)this + 8);
    }
    unsigned short GetFlags() const
    {
        return *(const unsigned short*)((const char*)this + 0xc);
    }
    MorphPoint3* GetCached() const
    {
        return *(MorphPoint3* const*)((const char*)this + 0x20);
    }
    void* GetA() const
    {
        return *(void* const*)((const char*)this + 0x24);
    }
    void* GetB() const
    {
        return *(void* const*)((const char*)this + 0x28);
    }
    void* GetC() const
    {
        return *(void* const*)((const char*)this + 0x2c);
    }
};

struct MorphGeom
{
    MorphGeomData* GetModelData() const
    {
        return *(MorphGeomData* const*)((const char*)this + 0xb8);
    }
};

struct FUN_00a3b010_shell : public NiGeomMorpherController
{
    MorphPoint3* GetMorphVertices();
};

// @fnv 0x00a3b010
MorphPoint3* FUN_00a3b010_shell::GetMorphVertices()
{
    MorphGeom* pkGeom = (MorphGeom*)m_pkTarget;
    if (!pkGeom)
        return 0;

    MorphPoint3* pkVerts = pkGeom->GetModelData()->GetCached();
    if (pkVerts)
        return pkVerts;

    unsigned short usVerts = pkGeom->GetModelData()->GetVertexCount();
    MorphPoint3* pkNew = new MorphPoint3[usVerts];
    MorphGeomData* pkData = pkGeom->GetModelData();
    pkData->FUN_00a66bb0(usVerts, pkNew, pkData->GetA(), pkData->GetB(), pkData->GetC(), pkData->GetFlags() & 1,
                         pkData->GetFlags() & 0xf000);
    return pkNew;
}

extern float DAT_011a854c[5];
extern float DAT_011a8538[5];

struct FUN_00a3e680_shell
{
    float SampleLength(int iA, int iB, float fT);
    float FUN_00a3e680(int iA, int iB, float fT);
};

// Samples SampleLength at five scaled points from DAT_011a854c, weights each by DAT_011a8538, sums them and multiplies by fT.
// @fnv 0x00a3e680
float FUN_00a3e680_shell::FUN_00a3e680(int iA, int iB, float fT)
{
    float fWeightedSum = 0.0f;
    for (int i = 0; i < 5; i++)
    {
        float fSampleTime = DAT_011a854c[i] * fT;
        fWeightedSum += SampleLength(iA, iB, fSampleTime) * DAT_011a8538[i];
    }
    return fWeightedSum * fT;
}

namespace fnv_00a3aa10 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FUN_00a3aa10_shell : public NiGeomMorpherController
{
    void UpdateMorphWeights(float);
};

struct InterpV
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
    virtual bool Update(float, void*, float&);
};
struct GMV
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
    virtual InterpV* GetInterp(unsigned int);
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual NiPoint3* GetVerts();
};
struct TgtV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int IsVis();
};
struct GeomData
{
    void SetDirtyFlags(unsigned int);
};
struct GMItem
{
    int a;
    float m_fWeight;
};
struct GMTarget
{
    NiPoint3* pkVerts;
    int pad[3];
};
struct GMMorph
{
    char pad[8];
    unsigned int uiElementCount;
    int pad2;
    GMTarget* pTargets;
    bool bRel;
};
struct GMSelf
{
    char pad[0x28];
    float fScaledTime;
    TgtV* pkTarget;
    char pad30[8];
    GMMorph* pkMorph;
    GMItem* pkItems;
    char pad40;
    bool m_bHasRegionData;
    float GetWeight(unsigned int i)
    {
        float f = 0.0f;
        if (pkItems)
            f = pkItems[i].m_fWeight;
        return f;
    }
    float GetW(unsigned int i)
    {
        return pkItems[i].m_fWeight;
    }
    void SetWeight(unsigned int i, float f)
    {
        if (pkItems)
            pkItems[i].m_fWeight = f;
    }
};
void* _fnv_zlib_memset(void*, int, unsigned int);
void AddScaledPoints(NiPoint3*, float, NiPoint3*, int);
extern const float runtimeFloatSettingDefault166;

// @fnv 0x00a3aa10
void FUN_00a3aa10_shell::UpdateMorphWeights(float fTime)
{
    GMSelf* self = (GMSelf*)this;
    bool bupdate;
    NiPoint3* pkVerts;
    unsigned int uiIndex;
    int iVertexDataArraySize;
    unsigned int uiNumTargets;

    pkVerts = ((GMV*)this)->GetVerts();
    uiNumTargets = self->pkMorph->uiElementCount;
    iVertexDataArraySize = *(unsigned short*)(*(char**)((char*)self->pkTarget + 0xb8) + 8);
    for (uiIndex = 0; uiIndex < uiNumTargets; uiIndex++)
    {
        InterpV* pkInterp = ((GMV*)this)->GetInterp(uiIndex);
        float fFrac = self->GetWeight(uiIndex);
        if (uiIndex == 0 && self->pkMorph->bRel)
        {
            if (self->m_bHasRegionData)
                fFrac = 0.0f;
            else
                fFrac = 1.0f;
        }
        else if (!pkInterp || !pkInterp->Update(self->fScaledTime, self->pkTarget, fFrac))
        {
            continue;
        }
        self->SetWeight(uiIndex, fFrac);
    }
    if (!self->m_bHasRegionData)
        _fnv_zlib_memset(pkVerts, 0, sizeof(NiPoint3) * iVertexDataArraySize);
    bupdate = false;
    for (uiIndex = 0; uiIndex < uiNumTargets; uiIndex++)
    {
        if (self->pkItems)
        {
            float fFrac = self->GetW(uiIndex);
            if (fFrac >= 0.001f || fFrac <= runtimeFloatSettingDefault166)
            {
                NiPoint3* pkDeltaVerts = self->pkMorph->pTargets[uiIndex].pkVerts;
                AddScaledPoints(pkVerts, fFrac, pkDeltaVerts, iVertexDataArraySize);
                bupdate = true;
            }
        }
    }
    if (bupdate && self->pkTarget->IsVis())
        ((GeomData*)*(void**)((char*)self->pkTarget + 0xb8))->SetDirtyFlags(1);
}
}  // namespace fnv_00a3aa10

struct NiStream
{
    unsigned char m_aucPad[0xD8];
    unsigned int m_uiNifVersion;

    void* __thiscall GetLoadedObject();
    unsigned int __thiscall GetLinkID();
};

struct NiD3DShaderProgram
{
    const char* __thiscall GetName();
};

struct FUN_00a3b5a0_shell : public NiGeomMorpherController
{
    void ClearInterpolatorArray();
    void LinkObject(NiStream& kStream);
    void FUN_00a3b5a0(NiStream& kStream);
};

// Links the object to the stream, reads morph data, sets per-target interpolators and key times depending on the stream version.
// @fnv 0x00a3b5a0
void FUN_00a3b5a0_shell::FUN_00a3b5a0(NiStream& kStream)
{
    typedef void(__thiscall * SetInterpolatorType)(NiGeomMorpherController*, const char*, unsigned int);
    typedef void(__thiscall * SetTimeType)(NiGeomMorpherController*, float, float);

    LinkObject(kStream);

    m_spMorphTargetData = static_cast<NiMorphData*>(kStream.GetLoadedObject());

    if (kStream.m_uiNifVersion < 0x14010003)
    {
        ClearInterpolatorArray();

        for (unsigned int uiIndex = 0; uiIndex < GetNumTargets(); ++uiIndex)
        {
            NiMorphData::MorphTarget* pkTarget = m_spMorphTargetData->GetTarget(uiIndex);
            m_pInterpolatorItems[uiIndex].m_fWeight = pkTarget->m_fMorphWeight;
        }
    }

    if (kStream.m_uiNifVersion < 0x0A010068 && m_spMorphTargetData)
    {
        unsigned int uiNumTargets = m_spMorphTargetData->m_uiNumTargets;

        for (unsigned int uiIndex = 0; uiIndex < uiNumTargets; ++uiIndex)
        {
            NiMorphData::MorphTarget* pkTarget = m_spMorphTargetData->GetTarget(uiIndex);
            const char* pcName = reinterpret_cast<NiD3DShaderProgram*>(pkTarget)->GetName();

            void** ppVTable = reinterpret_cast<void**>(*reinterpret_cast<void***>(this));
            SetInterpolatorType pfnSetInterpolator = reinterpret_cast<SetInterpolatorType>(ppVTable[0x32]);
            pfnSetInterpolator(this, pcName, uiIndex);
        }
    }
    else if (kStream.m_uiNifVersion < 0x14010003)
    {
        unsigned int ItemUpdateArray = kStream.GetLinkID();

        if (ItemUpdateArray != 0)
        {
            for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; ++uiIndex)
            {
                void* pkInterpolator = kStream.GetLoadedObject();
                void** ppVTable = reinterpret_cast<void**>(*reinterpret_cast<void***>(this));
                SetInterpolatorType pfnSetInterpolator = reinterpret_cast<SetInterpolatorType>(ppVTable[0x32]);
                pfnSetInterpolator(this, static_cast<const char*>(pkInterpolator), uiIndex);
            }
        }
    }

    if (m_spMorphTargetData && kStream.m_uiNifVersion <= 0x0401000C)
    {
        void** ppVTable = reinterpret_cast<void**>(*reinterpret_cast<void***>(this));
        SetTimeType pfnSetTime = reinterpret_cast<SetTimeType>(ppVTable[0x38]);
        pfnSetTime(this, m_fLoKeyTime, m_fHiKeyTime);
    }
}

class A3A750Target
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void* IsAVObject();
};

class A3A750TimeController
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void AdvanceControllerTime();

    void SetTarget(A3A750Target* pkTarget);

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
};

class A3A750Controller : public A3A750TimeController
{
  public:
    void FUN_00a3a750(A3A750Target* pkTarget);

    void* m_pkInterpolator;
    int unk3C;
    short unk40;
    char unk42;
    bool m_bManagerControlled;
};

// @fnv 0x00a3a750
void A3A750Controller::FUN_00a3a750(A3A750Target* pkTarget)
{
    if (pkTarget->IsAVObject())
    {
        A3A750TimeController::SetTarget(pkTarget);
        if (m_pkInterpolator)
        {
            AdvanceControllerTime();
            m_bManagerControlled = true;
        }
    }
    else
    {
        A3A750TimeController::SetTarget(0);
    }
}

class FUN_00a3a7a0_item;

struct FUN_00a3a7a0_list
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_uiCount;
};

class FUN_00a3a7a0_vtbase
{
  public:
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
};

class FUN_00a3a7a0_item : public FUN_00a3a7a0_vtbase
{
  public:
    virtual void Apply(float a1, float a2);
};

class FUN_00a3a7a0_cls : public FUN_00a3a7a0_vtbase
{
  public:
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
    FUN_00a3a7a0_list* m_pEntries;

    virtual FUN_00a3a7a0_item* GetItem(unsigned int index);
    void ApplyToAllItems(float a1, float a2);
};

// Iterates over the list up to m_uiCount, gets each item via GetItem, and calls Apply(a1, a2) on non-null items.
// @fnv 0x00a3a7a0
void FUN_00a3a7a0_cls::ApplyToAllItems(float afValue1, float afValue2)
{
    for (unsigned int i = 0; i < m_pEntries->m_uiCount; ++i)
    {
        FUN_00a3a7a0_item* item = GetItem(i);
        if (item != 0)
        {
            item->Apply(afValue1, afValue2);
        }
    }
}

struct FUN_00a38fe0_shell
{
    bool __thiscall FUN_00a2f8b0(NiStream& stream);
};

struct FUN_00a3a7f0_target
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
    virtual void FUN_00a3a7f0_target_call(NiStream* stream);
};

struct FUN_00a3a7f0_obj
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
    virtual void vfB0();
    virtual unsigned short FUN_00a3a7f0_count();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void* FUN_00a3a7f0_get(unsigned short index);

    bool __thiscall LoadFromStream(NiStream* stream);
};

// @fnv 0x00a3a7f0
bool __thiscall FUN_00a3a7f0_obj::LoadFromStream(NiStream* stream)
{
    FUN_00a38fe0_shell* helper = reinterpret_cast<FUN_00a38fe0_shell*>(this);

    if (!helper->FUN_00a2f8b0(*stream))
        return false;

    void* morphData = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x38);

    if (morphData)
    {
        reinterpret_cast<FUN_00a3a7f0_target*>(morphData)->FUN_00a3a7f0_target_call(stream);
    }

    unsigned short index = 0;
    while (index < FUN_00a3a7f0_count())
    {
        void* item = FUN_00a3a7f0_get(index);

        if (item)
        {
            reinterpret_cast<FUN_00a3a7f0_target*>(item)->FUN_00a3a7f0_target_call(stream);
        }

        ++index;
    }

    return true;
}

struct InterpolatorCaller
{
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43() = 0;
    virtual void Slot44() = 0;
    virtual void Slot45() = 0;
    virtual void Slot46() = 0;
    virtual void Slot47() = 0;
    virtual void GetInterpolatorTimeRange(float* minimum, float* maximum) = 0;
};

struct MorpherCaller
{
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual void Slot43() = 0;
    virtual void Slot44() = 0;
    virtual void Slot45() = 0;
    virtual void Slot46() = 0;
    virtual void Slot47() = 0;
    virtual void Slot48() = 0;
    virtual NiInterpolator* GetInterpolator(unsigned int index) = 0;
};

struct TimeFlags
{
    unsigned char lowerBits : 5;
    unsigned char updateAllowed : 1;
    unsigned char upperBits : 2;
};
extern const float DAT_01096ce0;
extern const float DAT_01015f5c;

__forceinline unsigned char IsManaged(const NiTimeController* object)
{
    return (object->m_uiObjectFlags >> 5) & 1;
}
struct FUN_00a3a950_shell : NiGeomMorpherController
{
    void UpdateKeyTimeRange();
};

// @fnv 0x00a3a950
void FUN_00a3a950_shell::UpdateKeyTimeRange()
{
    if (!IsManaged(this))
    {
        NiMorphData* morphData = m_spMorphTargetData.m_pObject;
        unsigned int numTargets = morphData ? morphData->m_uiNumTargets : 0;
        m_fLoKeyTime = DAT_01096ce0;
        m_fHiKeyTime = DAT_01015f5c;

        unsigned int index = 0;
        if (index < numTargets)
        {
            do
            {
                NiInterpolator* interpolator = reinterpret_cast<MorpherCaller*>(this)->GetInterpolator(index);
                if (interpolator)
                {
                    float upper = DAT_01015f5c;
                    float lower = DAT_01096ce0;
                    reinterpret_cast<InterpolatorCaller*>(interpolator)->GetInterpolatorTimeRange(&lower, &upper);
                    if (lower < m_fLoKeyTime)
                    {
                        m_fLoKeyTime = lower;
                    }
                    if (upper > m_fHiKeyTime)
                    {
                        m_fHiKeyTime = upper;
                    }
                }
                ++index;
            } while (index < numTargets);
        }
    }
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

extern const NiPoint3 DAT_011f426c;

struct NiBound
{
    NiPoint3 center;
    float radius;
    void ComputeBoundingSphere(unsigned int vertexCount, const NiPoint3* vertices);
    void Merge(const NiBound* other);
};

struct MorphTarget
{
    NiPoint3* vertices;
    void* name;
    float weight;
    void* interpolator;
};

struct MorphData
{
    void* vtable;
    unsigned int refCount;
    unsigned int targetCount;
    unsigned int vertexCount;
    MorphTarget* targets;
    MorphTarget* GetTarget(unsigned int index) const
    {
        return index < targetCount ? &targets[index] : 0;
    }
};

struct GeometryData
{
    NiBound* GetBound()
    {
        return reinterpret_cast<NiBound*>(reinterpret_cast<char*>(this) + 0x10);
    }
};

struct Geometry
{
    GeometryData* GetModelData() const
    {
        return *reinterpret_cast<GeometryData* const*>(reinterpret_cast<const char*>(this) + 0xb8);
    }
};

struct MorpherController
{
    MorphData* GetMorphData() const
    {
        return *reinterpret_cast<MorphData* const*>(reinterpret_cast<const char*>(this) + 0x38);
    }
    Geometry* GetGeometry() const
    {
        return *reinterpret_cast<Geometry* const*>(reinterpret_cast<const char*>(this) + 0x2c);
    }
    void UpdateGeometryBound();
};

// @fnv 0x00a3abe0
void MorpherController::UpdateGeometryBound()
{
    NiBound morphBound;
    const unsigned int count = GetMorphData()->targetCount;
    if (count != 0)
    {
        MorphData* data = GetMorphData();
        morphBound.ComputeBoundingSphere(data->vertexCount, data->GetTarget(0)->vertices);
        for (unsigned int i = 1; i < count; ++i)
        {
            NiBound targetBound;
            data = GetMorphData();
            targetBound.ComputeBoundingSphere(data->vertexCount, data->GetTarget(i)->vertices);
            morphBound.Merge(&targetBound);
        }
    }
    else
    {
        morphBound.center = DAT_011f426c;
        morphBound.radius = 0.0f;
    }
    volatile float radiusValue = morphBound.radius;
    NiBound* pBound = GetGeometry()->GetModelData()->GetBound();
    pBound->center = morphBound.center;
    pBound->radius = radiusValue;
}

struct FUN_00a3acb0_item
{
    void* p;
    int q;
};

struct FUN_00a3acb0_elem
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
    virtual void Slot26(void* p);
};

struct FUN_00a3acb0_cls
{
    char pad[0x3c];
    FUN_00a3acb0_item* items;
    void FUN_00a6d0c0(void* p);
    unsigned int FUN_008d3ed0();
    void FUN_00a3acb0(void* p);
};

// Calls FUN_00a6d0c0(p), then forwards p to Slot26 on each non-null item pointer in items up to FUN_008d3ed0().
// @fnv 0x00a3acb0
void FUN_00a3acb0_cls::FUN_00a3acb0(void* p)
{
    FUN_00a6d0c0(p);
    unsigned short i;
    for (i = 0; i < FUN_008d3ed0(); i++)
    {
        FUN_00a3acb0_elem* pElem = (FUN_00a3acb0_elem*)items[i].p;
        if (pElem != 0)
        {
            pElem->Slot26(p);
        }
    }
}

struct A3AF10MemoryManager
{
    void Deallocate(void* pvMem);
};

extern A3AF10MemoryManager g_A3AF10MemoryManager;

// Stand-in for NiInterpController (out-of-line destructor).
class A3AF10InterpController : public NiObject
{
  public:
    unsigned short m_uiObjectFlags;
    unsigned char m_aucPadA[2];
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiObjectNET* m_pkTarget;
    NiTimeController* m_pkNext;

    virtual ~A3AF10InterpController();
};

struct A3AF10InterpItem
{
    NiPointer<NiInterpolator> m_spControllerInterpolator;
    float m_fWeight;

    ~A3AF10InterpItem() throw()
    {}
};

// NiGeomMorpherController destructor.
class FUN_00a3af10 : public A3AF10InterpController
{
  public:
    unsigned short m_uFlags2;
    unsigned char m_aucPad[2];
    NiPointer<NiMorphData> m_spMorphTargetData;
    A3AF10InterpItem* m_pInterpolatorItems;
    bool m_bUpdateEnabled;
    bool m_bUpdateNormals;
    bool m_bNeedsUpdate;
    bool m_bUpdateBounds;

    virtual ~FUN_00a3af10() throw();
};

// Releases the morph data pointer and destroys the interpolator item array, then frees its allocation cookie.
// @fnv 0x00a3af10
FUN_00a3af10::~FUN_00a3af10() throw()
{
    m_spMorphTargetData = 0;
    // NiDelete[] m_pInterpolatorItems, expanded: destroy elements back to front, then free the count cookie
    if (m_pInterpolatorItems)
    {
        unsigned int* puiCookie = reinterpret_cast<unsigned int*>(m_pInterpolatorItems) - 1;
        int i = *puiCookie;
        A3AF10InterpItem* pkItem = m_pInterpolatorItems + i;
        while (--i >= 0)
        {
            --pkItem;
            pkItem->~A3AF10InterpItem();
        }
        g_A3AF10MemoryManager.Deallocate(puiCookie);
    }
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a3b530_cls
{
    int unk00;

    void BaseCleanup();

    FUN_00a3b530_cls* FUN_00a3b530(unsigned char acFlags);
};

// @fnv 0x00a3b530
FUN_00a3b530_cls* FUN_00a3b530_cls::FUN_00a3b530(unsigned char acFlags)
{
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x44);
    }
    return this;
}

struct FUN_00a3ba10_vt
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
};

struct FUN_00a3ba10_shell : public NiGeomMorpherController
{
    void FUN_00a3b460();
    void SetMorphData(NiMorphData* pkMorphData, bool bCanUpdate);
};

// Stores pkMorphData, calls FUN_00a3b460, and if bCanUpdate is set invokes the virtual method at vtable slot v59.
// @fnv 0x00a3ba10
void FUN_00a3ba10_shell::SetMorphData(NiMorphData* pkMorphData, bool bCanUpdate)
{
    m_spMorphTargetData = pkMorphData;
    FUN_00a3b460();
    if (bCanUpdate)
    {
        reinterpret_cast<FUN_00a3ba10_vt*>(this)->v59();
    }
}

struct Info
{
    int unk00;
    int m_04;
};
struct Owner
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
    Info* m_b8;
};
struct Mgr
{
    bool Check(void* p, int n);
};
extern Mgr* DAT_011f5b04;
extern unsigned char DAT_011f3725;
extern float DAT_01096324;
struct Obj56
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V0A();
    virtual void V0B();
    virtual void V0C();
    virtual void V0D();
    virtual void V0E();
    virtual void V0F();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V1A();
    virtual void V1B();
    virtual void V1C();
    virtual void V1D();
    virtual void V1E();
    virtual void V1F();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    void Attach(void* self, Owner* o);
};
bool Free_00714a00();
Obj56* Free_00a56f90();
struct SetterArg
{
    float m_00;
    unsigned char unk04;
    unsigned char m_05;
    unsigned char unk06;
    unsigned char m_07;
};
struct FUN_00a3b080_cls
{
    int unk00;
    int unk04;
    unsigned short m_08Low : 5;
    unsigned short m_08Top : 3;
    unsigned short m_08Hi : 8;
    unsigned short unk0A;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    float m_28;
    Owner* m_2c;
    int unk30;
    int unk34;
    int m_38;
    int unk3C;
    unsigned char m_40;
    unsigned char m_41;
    unsigned char m_42;
    bool Sub_00a36250(float v);
    void Sub_00a3aa10(float v);
    void ApplySetterArg(SetterArg* a1);
};

// Applies a SetterArg to this object: sets flags and m_28, calls Sub_00a36250/Sub_00a3aa10, and attaches an object when m_2c and m_40 are set.
// @fnv 0x00a3b080
void FUN_00a3b080_cls::ApplySetterArg(SetterArg* a1)
{
    if (m_38 == 0)
    {
        return;
    }
    if (a1->m_05 != 0)
    {
        a1->m_07 = 1;
        return;
    }
    unsigned char uiFlags = m_08Top;
    if ((uiFlags & 1) != 0)
    {
        m_40 = 1;
        m_28 = DAT_01096324;
    }
    else
    {
        bool ok = Sub_00a36250(a1->m_00);
        if (!ok || m_42 != 0)
        {
            m_40 = 1;
        }
    }
    if (m_2c == 0)
    {
        return;
    }
    if (m_40 == 0)
    {
        return;
    }
    Sub_00a3aa10(m_28);
    if (DAT_011f3725 == 0)
    {
        return;
    }
    if (!Free_00714a00())
    {
        return;
    }
    if (m_2c->m_b8->m_04 != 1)
    {
        return;
    }
    Obj56* obj = Free_00a56f90();
    if (obj != 0)
    {
        obj->Attach(this, m_2c);
        if (!DAT_011f5b04->Check(obj, 2))
        {
            obj->V25();
        }
    }
}

void* __cdecl FUN_00aa13e0(unsigned int size);

extern int DAT_01096cec;

struct MorphData_b10413
{
    int unk00;
    void IncRefCount();
    void DecRefCount();
};

template <class T> struct Ptr_b10413
{
    T* m_pObject;
    Ptr_b10413(T* o = 0)
    {
        m_pObject = o;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
};

struct Base_b10413
{
    void* m_pVTable;
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
    void FUN_00a2f8c0();
    Base_b10413() throw()
    {
        FUN_00a2f8c0();
        m_pVTable = (void*)&DAT_01096cec;
    }
};

struct Obj_b10413 : public Base_b10413
{
    unsigned short m_uiObjectFlags;
    Ptr_b10413<MorphData_b10413> m_spMorphTargetData;
    void* m_pInterpolatorItems;
    bool m_bUpdateEnabled;
    bool m_bUpdateNormals;
    bool m_bNeedsUpdate;
    bool m_bUpdateBounds;

    Obj_b10413(MorphData_b10413* pkData) throw();
    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};

Obj_b10413::Obj_b10413(MorphData_b10413* pkData) throw() : m_spMorphTargetData(pkData)
{
    m_uiObjectFlags = 0;
    m_pInterpolatorItems = 0;
    m_bUpdateEnabled = false;
    m_bUpdateNormals = false;
    m_bNeedsUpdate = false;
    m_bUpdateBounds = false;
}

// Allocates and constructs an Obj_b10413 with a null MorphData pointer, returning the new object.
// @fnv 0x00a3b550
Obj_b10413* __cdecl FUN_00a3b550()
{
    return new Obj_b10413(0);
}

class MorphObject
{
  public:
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
    virtual bool IsEqual(MorphObject* pkObject);
};

template <class T> class MorphPointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

struct MorphInterpItem
{
    MorphPointer<MorphObject> m_spControllerInterpolator;
    float m_fWeight;
};

class MorphController
{
  public:
    bool FUN_00c283f0(MorphObject* pkObject);  // NiInterpController::IsEqual
    unsigned int FUN_008d3ed0();               // GetNumTargets
    bool FUN_00a3ad00(MorphObject* pkObject);

    int unk00[14];
    MorphPointer<MorphObject> m_spMorphTargetData;  // +0x38
    MorphInterpItem* m_pInterpolatorItems;          // +0x3c
};

// @fnv 0x00a3ad00
bool MorphController::FUN_00a3ad00(MorphObject* pkObject)
{
    if (!FUN_00c283f0(pkObject))
        return false;

    MorphController* pkMorph = (MorphController*)pkObject;

    if (!m_spMorphTargetData->IsEqual(pkMorph->m_spMorphTargetData))
        return false;

    for (unsigned int i = 0; i < FUN_008d3ed0(); i++)
    {
        MorphInterpItem& kOther = pkMorph->m_pInterpolatorItems[i];
        if ((kOther.m_spControllerInterpolator && !m_pInterpolatorItems[i].m_spControllerInterpolator) ||
            (!kOther.m_spControllerInterpolator && m_pInterpolatorItems[i].m_spControllerInterpolator))
            return false;
        if (kOther.m_spControllerInterpolator &&
            !kOther.m_spControllerInterpolator->IsEqual(m_pInterpolatorItems[i].m_spControllerInterpolator))
            return false;
        if (kOther.m_fWeight != m_pInterpolatorItems[i].m_fWeight)
            return false;
    }
    return true;
}

// 0x00a41590  lea eax,[ecx+4]; ret
struct C00a41590
{
    char pad00[0x4];
    int m4;
    int* FUN_00a41590();
};

// @fnv 0x00a41590
int* C00a41590::FUN_00a41590()
{
    return &m4;
}

class TESObjectDoorController
{
  public:
    static void* operator new(unsigned int n);
};
class NiMorphDataA3B
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class NiCloningProcessA3B;
template <class T> class NiPtrA3B
{
  public:
    NiPtrA3B(T* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    T* m_pObject;
};
namespace a3bb {
class FUN_00a2f8c0
{
  public:
    FUN_00a2f8c0() throw();
    virtual ~FUN_00a2f8c0() throw();
    char unk04[0x30];
};
}
class NiGeomMorpherControllerA3B : public a3bb::FUN_00a2f8c0
{
  public:
    NiGeomMorpherControllerA3B(NiMorphDataA3B* pkData = 0) throw()
        : m_spMorphTargetData(pkData), m_pInterpolatorItems(0)
    {
        m_uiObjectFlags = 0;
        m_bUpdateEnabled = false;
        m_bUpdateNormals = false;
        m_bNeedsUpdate = false;
        m_bUpdateBounds = false;
    }
    virtual ~NiGeomMorpherControllerA3B() throw();
    static void* operator new(unsigned int n)
    {
        return TESObjectDoorController::operator new(n);
    }
    unsigned short m_uiObjectFlags;
    NiPtrA3B<NiMorphDataA3B> m_spMorphTargetData;
    void* m_pInterpolatorItems;
    bool m_bUpdateEnabled;
    bool m_bUpdateNormals;
    bool m_bNeedsUpdate;
    bool m_bUpdateBounds;

    void FUN_00a3ba70(NiGeomMorpherControllerA3B* pkClone, NiCloningProcessA3B& kCloning);
    NiGeomMorpherControllerA3B* FUN_00a3bb80(NiCloningProcessA3B& kCloning);
};
// Allocates a new NiGeomMorpherControllerA3B, calls FUN_00a3ba70 with it and kCloning, and returns it.
// @fnv 0x00a3bb80
NiGeomMorpherControllerA3B* NiGeomMorpherControllerA3B::FUN_00a3bb80(NiCloningProcessA3B& kCloning)
{
    NiGeomMorpherControllerA3B* pkClone = new NiGeomMorpherControllerA3B;
    FUN_00a3ba70(pkClone, kCloning);
    return pkClone;
}

struct NiBinaryOutput
{
    void* vtable;
    unsigned int position;
    void* read;
    unsigned int(__cdecl* write)(NiBinaryOutput*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int bytes)
    {
        unsigned int uiComponentSize = bytes;
        unsigned int result = write(this, data, bytes, &uiComponentSize, 1);
        position += result;
    }
};
class NiStreamSV
{
  public:
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
    virtual void SaveLink(void*);
    NiBinaryOutput* GetOutput()
    {
        return *reinterpret_cast<NiBinaryOutput**>(reinterpret_cast<char*>(this) + 0x250);
    }
    template <class T> void Save(const T& value)
    {
        GetOutput()->Write(&value, sizeof(T));
    }
    void SaveBool(bool value)
    {
        unsigned char byte = value;
        Save(byte);
    }
};
struct S00c27120
{
    void FUN_00c27120(NiStreamSV&);
};
struct NiGMCShell_a3b350 : NiGeomMorpherController
{
    unsigned int GetNumTargetsSV() const
    {
        if (m_spMorphTargetData.m_pObject)
            return m_spMorphTargetData.m_pObject->m_uiNumTargets;
        return 0;
    }
    void FUN_00a3b350(NiStreamSV& stream);
};
// Calls FUN_00c27120, then saves a value, morph target link, update flag, target count, and interpolator links and weights.
// @fnv 0x00a3b350
void NiGMCShell_a3b350::FUN_00a3b350(NiStreamSV& stream)
{
    reinterpret_cast<S00c27120*>(this)->FUN_00c27120(stream);
    stream.Save(m_uiObjectFlags);
    stream.SaveLink(m_spMorphTargetData.m_pObject);
    unsigned char bNeedsUpdate = m_bNeedsUpdate;
    stream.Save(bNeedsUpdate);
    unsigned int count = GetNumTargetsSV();
    stream.Save(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        stream.SaveLink(m_pInterpolatorItems[i].m_spControllerInterpolator.m_pObject);
        stream.Save(m_pInterpolatorItems[i].m_fWeight);
    }
}
