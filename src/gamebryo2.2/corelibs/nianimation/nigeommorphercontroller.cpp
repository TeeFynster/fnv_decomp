
// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp
// NiGeomMorpherController: morph-target interpolator management.
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiMorphData.h"

#include "../../../../include/NiGeomMorpherController.h"
#include "../../../../include/NiInterpController.h"

#include "../../../../include/NiColorInterpolator.h"
#include "../../../../include/NiColorData.h"
#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/NiFloatInterpolator.h"
#include "../../../../include/NiStream.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

int NiStricmp(const char*, const char*);
extern const NiColorA DAT_011a9430;

// Keep the original inline operations while using the shared class declarations.
inline NiMorphData::MorphTarget* NiMorphData::GetTarget(unsigned int uiIndex) const
{
    if (uiIndex < m_uiNumTargets)
        return &m_pMorphTargets[uiIndex];
    return 0;
}

inline void NiInterpolator::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiInterpolator::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::NiPointer(T* pkNew)
{
    m_pObject = pkNew;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
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

inline NiBound::NiBound()
{
}

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
NiAnimationKey::KeyContent NiColorInterpolator::GetColorKeyContent(unsigned short) const
{
    return NiAnimationKey::COLORKEY;
}

// @fnv 0x00a3bc00
unsigned int NiColorInterpolator::GetColorKeyCount(unsigned short) const
{
    if (!m_spColorData.m_pObject)
        return 0;

    return m_spColorData.m_pObject->m_uiNumKeys;
}

// @fnv 0x00a3bc10
NiAnimationKey::KeyType NiColorInterpolator::GetColorKeyType(unsigned short) const
{
    if (!m_spColorData.m_pObject)
        return NiAnimationKey::NOINTERP;

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

    return reinterpret_cast<const NiColorA&>(m_kColorValue) == DAT_011a9430 ? false : true;
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

extern bool DAT_011f3724;

// Copies interpolator pointers and weights from this controller into pkDest, cloning each interpolator and updating reference counts.
// @fnv 0x00a3ba70
void NiGeomMorpherController::CopyMemberData(NiGeomMorpherController* pkDest, CloningProcess& kCloning)
{
    NiInterpController::CopyMemberData(pkDest, kCloning);
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
            NiInterpolator* pkNew = static_cast<NiInterpolator*>(kInterpItem.m_spControllerInterpolator.m_pObject->CloneObject(kCloning));
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

// @fnv 0x00a3a8a0
// src: GAMEBRYO_LIB 0x00a3a8a0
void* __fastcall NiGeomMorpherController_GetInterpolator(NiGeomMorpherController* self, int unused, unsigned short idx)
{
    return self->m_pInterpolatorItems[idx].m_spControllerInterpolator.m_pObject;
}

// Stores pkInterpolator into the morph controller's interpolator slot at usIndex, releasing the old interpolator and incrementing the new one's ref count.
// @fnv 0x00a3a8b0
// src: GAMEBRYO_LIB 0x00a3a8b0
void __fastcall NiGeomMorpherController_SetInterpolator(NiGeomMorpherController* self, int, NiInterpolator* pkInterpolator, unsigned short usIndex)
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

// Reads the morph weight at usIndex from the controller's weight array (or 0.0f) and allocates a NiFloatInterpolator initialized with that value.
// @fnv 0x00a3a900
NiInterpolator* __fastcall CreateMorphWeightInterpolator(NiGeomMorpherController* self, int, unsigned short usIndex)
{
    float fValue = 0.0f;
    if (self->m_pInterpolatorItems)
        fValue = self->m_pInterpolatorItems[usIndex].m_fWeight;
    NiFloatInterpolator* p = static_cast<NiFloatInterpolator*>(BSFadeNode::operator new(0x18));
    if (p)
        return static_cast<NiInterpolator*>(p->FUN_00a3c390(fValue));
    return 0;
}

// @fnv 0x00a3a940
NiGeomMorpherController::InterpItem::InterpItem() : m_spControllerInterpolator(0), m_fWeight(0.0f)
{
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

// @fnv 0x00a3aba0
// src: XBOX_PDB 0x00a3aba0
void __fastcall NiGeomMorpherController_OnPreDisplay(NiGeomMorpherController* self, int)
{
    if (self->m_pkTarget && self->m_bUpdateEnabled)
    {
        GeomData* pData = reinterpret_cast<GeomT*>(self->m_pkTarget)->data;
        pData->SetDirtyFlags(1);
        if ((self->m_uiObjectFlags & 1) && pData->f24)
            pData->s40();
        self->m_bUpdateEnabled = false;
    }
}

// @fnv 0x00a3adc0
unsigned short NiGeomMorpherController::GetTargetCount() const
{
    if (m_spMorphTargetData.m_pObject)
        return static_cast<unsigned short>(m_spMorphTargetData.m_pObject->m_uiNumTargets);
    return 0;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f3738;
struct DynCastHelper
{
    DynCastHelper* DynamicCast(const GlobalObjectO2_00a7b610*);
};
// Reads a float from the morph data array at usIndex and passes it to the interpolator's SetFloatValue after a dynamic cast.
// @fnv 0x00a3ae50
void __fastcall SetMorphPose(NiGeomMorpherController* self, int, NiInterpolator* pkInterp, unsigned short usMorphIndex)
{
    float fValue = 0.0f;
    NiGeomMorpherController::InterpItem* data = self->m_pInterpolatorItems;
    if (data)
        fValue = data[usMorphIndex].m_fWeight;
    NiFloatInterpolator* pkPoseInterp;
    if (!pkInterp)
        pkPoseInterp = 0;
    else
        pkPoseInterp = (NiFloatInterpolator*)((DynCastHelper*)pkInterp)->DynamicCast(&g_011f3738);
    pkPoseInterp->SetFloatValue(fValue);
}

namespace fnv_00a3afd0 {
struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_011f3728;
// @fnv 0x00a3afd0
// src: COMMUNITY 0x00a3afd0
GlobalObjectO2_00a7b610* __cdecl NiGeomMorpherController_GetRTTI()
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

// Walks the RTTI base chain of self->m_pkTarget and returns true if it reaches g_011f4a48_arg1, otherwise false.
// @fnv 0x00a3afe0
bool __fastcall IsRTTIDerivedFrom(NiGeomMorpherController* self, int)
{
    FUN_00a3afe0_tgt* pTgt = reinterpret_cast<FUN_00a3afe0_tgt*>(self->m_pkTarget);
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
    void NiGeometryData_ReplaceData(unsigned short usVerts, MorphPoint3* pkDest, void* pvA, void* pvB, void* pvC,
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

// @fnv 0x00a3b010
MorphPoint3* __fastcall GetMorphVertices(NiGeomMorpherController* self, int)
{
    MorphGeom* pkGeom = (MorphGeom*)self->m_pkTarget;
    if (!pkGeom)
        return 0;

    MorphPoint3* pkVerts = pkGeom->GetModelData()->GetCached();
    if (pkVerts)
        return pkVerts;

    unsigned short usVerts = pkGeom->GetModelData()->GetVertexCount();
    MorphPoint3* pkNew = new MorphPoint3[usVerts];
    MorphGeomData* pkData = pkGeom->GetModelData();
    pkData->NiGeometryData_ReplaceData(usVerts, pkNew, pkData->GetA(), pkData->GetB(), pkData->GetC(), pkData->GetFlags() & 1,
                         pkData->GetFlags() & 0xf000);
    return pkNew;
}

extern float DAT_011a854c[5];
extern float DAT_011a8538[5];

struct FUN_00a3e680_shell
{
    float SampleLength(int iA, int iB, float fT);
    float NiPathInterpolator_PathLength(int iA, int iB, float fT);
};

// Samples SampleLength at five scaled points from DAT_011a854c, weights each by DAT_011a8538, sums them and multiplies by fT.
// @fnv 0x00a3e680
// src: XBOX_PDB 0x00a3e680
float FUN_00a3e680_shell::NiPathInterpolator_PathLength(int iA, int iB, float fT)
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
struct blob12
{
    char b[12];
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

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

void* _fnv_zlib_memset(void*, int, unsigned int);
void AddScaledPoints(NiPoint3*, float, NiPoint3*, int);
extern const float runtimeFloatSettingDefault166;

// vf58 returns the morph vertex array; its shared declaration currently has no return value.
inline NiPoint3* GetMorphVertexArray(NiGeomMorpherController* self)
{
    typedef NiPoint3* (__thiscall* GetVertices)(NiGeomMorpherController*);
    return reinterpret_cast<GetVertices>((*reinterpret_cast<void***>(self))[58])(self);
}

inline float GetMorphWeight(const NiGeomMorpherController* self, unsigned int i)
{
    float f = 0.0f;
    if (self->m_pInterpolatorItems)
        f = self->m_pInterpolatorItems[i].m_fWeight;
    return f;
}

inline void SetMorphWeight(NiGeomMorpherController* self, unsigned int i, float f)
{
    if (self->m_pInterpolatorItems)
        self->m_pInterpolatorItems[i].m_fWeight = f;
}

// @fnv 0x00a3aa10
void __fastcall UpdateMorphWeights(NiGeomMorpherController* self, int, float fTime)
{
    bool bupdate;
    NiPoint3* pkVerts;
    unsigned int uiIndex;
    int iVertexDataArraySize;
    unsigned int uiNumTargets;

    pkVerts = GetMorphVertexArray(self);
    uiNumTargets = self->m_spMorphTargetData.m_pObject->m_uiNumTargets;
    iVertexDataArraySize = *(unsigned short*)(*(char**)((char*)self->m_pkTarget + 0xb8) + 8);
    for (uiIndex = 0; uiIndex < uiNumTargets; uiIndex++)
    {
        InterpV* pkInterp = reinterpret_cast<InterpV*>(self->GetInterpolator(uiIndex));
        float fFrac = GetMorphWeight(self, uiIndex);
        if (uiIndex == 0 && self->m_spMorphTargetData.m_pObject->m_bTargetsAreRelative)
        {
            if (self->m_bUpdateNormals)
                fFrac = 0.0f;
            else
                fFrac = 1.0f;
        }
        else if (!pkInterp || !pkInterp->Update(self->m_fControllerTime, self->m_pkTarget, fFrac))
        {
            continue;
        }
        SetMorphWeight(self, uiIndex, fFrac);
    }
    if (!self->m_bUpdateNormals)
        _fnv_zlib_memset(pkVerts, 0, sizeof(NiPoint3) * iVertexDataArraySize);
    bupdate = false;
    for (uiIndex = 0; uiIndex < uiNumTargets; uiIndex++)
    {
        if (self->m_pInterpolatorItems)
        {
            float fFrac = self->m_pInterpolatorItems[uiIndex].m_fWeight;
            if (fFrac >= 0.001f || fFrac <= runtimeFloatSettingDefault166)
            {
                NiPoint3* pkDeltaVerts = self->m_spMorphTargetData.m_pObject->m_pMorphTargets[uiIndex].m_pkVertexPositions;
                AddScaledPoints(pkVerts, fFrac, pkDeltaVerts, iVertexDataArraySize);
                bupdate = true;
            }
        }
    }
    if (bupdate && reinterpret_cast<TgtV*>(self->m_pkTarget)->IsVis())
        ((GeomData*)*(void**)((char*)self->m_pkTarget + 0xb8))->SetDirtyFlags(1);
}
}  // namespace fnv_00a3aa10

inline unsigned int NiStream::GetFileVersion() const
{
    return m_uiNifFileVersion;
}

// Links the object to the stream, reads morph data, sets per-target interpolators and key times depending on the stream version.
// @fnv 0x00a3b5a0
void __fastcall LinkMorphData(NiGeomMorpherController* self, int, NiStream& kStream)
{
    typedef void(__thiscall * SetInterpolatorType)(NiGeomMorpherController*, const char*, unsigned int);
    typedef void(__thiscall * SetTimeType)(NiGeomMorpherController*, float, float);

    self->NiInterpController::LinkObject(kStream);

    self->m_spMorphTargetData = static_cast<NiMorphData*>(kStream.GetLoadedObject());

    if (kStream.GetFileVersion() < 0x14010003)
    {
        self->ClearInterpolatorArray();

        for (unsigned int uiIndex = 0; uiIndex < self->GetNumTargets(); ++uiIndex)
        {
            NiMorphData::MorphTarget* pkTarget = self->m_spMorphTargetData->GetTarget(uiIndex);
            self->m_pInterpolatorItems[uiIndex].m_fWeight = pkTarget->m_fMorphWeight;
        }
    }

    if (kStream.GetFileVersion() < 0x0A010068 && self->m_spMorphTargetData)
    {
        unsigned int uiNumTargets = self->m_spMorphTargetData->m_uiNumTargets;

        for (unsigned int uiIndex = 0; uiIndex < uiNumTargets; ++uiIndex)
        {
            NiMorphData::MorphTarget* pkTarget = self->m_spMorphTargetData->GetTarget(uiIndex);
            const char* pcName = reinterpret_cast<NiD3DShaderProgram*>(pkTarget)->NiD3DShaderProgram::GetName();

            void** ppVTable = reinterpret_cast<void**>(*reinterpret_cast<void***>(self));
            SetInterpolatorType pfnSetInterpolator = reinterpret_cast<SetInterpolatorType>(ppVTable[0x32]);
            pfnSetInterpolator(self, pcName, uiIndex);
        }
    }
    else if (kStream.GetFileVersion() < 0x14010003)
    {
        unsigned int ItemUpdateArray = kStream.GetLinkID();

        if (ItemUpdateArray != 0)
        {
            for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; ++uiIndex)
            {
                void* pkInterpolator = kStream.GetLoadedObject();
                void** ppVTable = reinterpret_cast<void**>(*reinterpret_cast<void***>(self));
                SetInterpolatorType pfnSetInterpolator = reinterpret_cast<SetInterpolatorType>(ppVTable[0x32]);
                pfnSetInterpolator(self, static_cast<const char*>(pkInterpolator), uiIndex);
            }
        }
    }

    if (self->m_spMorphTargetData && kStream.GetFileVersion() <= 0x0401000C)
    {
        void** ppVTable = reinterpret_cast<void**>(*reinterpret_cast<void***>(self));
        SetTimeType pfnSetTime = reinterpret_cast<SetTimeType>(ppVTable[0x38]);
        pfnSetTime(self, self->m_fLoKeyTime, self->m_fHiKeyTime);
    }
}

// @fnv 0x00a3a750
void __fastcall SetMorphTarget(NiGeomMorpherController* self, int, NiObjectNET* pkTarget)
{
    if (pkTarget->IsGeometry())
    {
        self->NiTimeController::SetTarget(pkTarget);
        if (self->m_spMorphTargetData.m_pObject)
        {
            self->vf59();
            self->m_bUpdateBounds = true;
        }
    }
    else
    {
        self->NiTimeController::SetTarget(0);
    }
}

// Iterates over the list up to m_uiCount, gets each item via GetItem, and calls Apply(a1, a2) on non-null items.
// @fnv 0x00a3a7a0
void __fastcall SetMorphActiveTimeRange(NiGeomMorpherController* self, int, float afValue1, float afValue2)
{
    for (unsigned int i = 0; i < self->m_spMorphTargetData.m_pObject->m_uiNumTargets; ++i)
    {
        NiInterpolator* item = self->GetInterpolator(i);
        if (item != 0)
        {
            item->SetActiveTimeRange(afValue1, afValue2);
        }
    }
}

// The shared base does not declare this RegisterStreamables override yet.
extern bool __cdecl RegisterInterpStreamables();

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

// @fnv 0x00a3a7f0
bool __fastcall RegisterMorphStreamables(NiGeomMorpherController* self, int, NiStream* stream)
{
    if (!reinterpret_cast<bool (__thiscall*)(NiInterpController*, NiStream&)>(&RegisterInterpStreamables)(self, *stream))
        return false;

    void* morphData = self->m_spMorphTargetData.m_pObject;

    if (morphData)
    {
        reinterpret_cast<FUN_00a3a7f0_target*>(morphData)->FUN_00a3a7f0_target_call(stream);
    }

    unsigned short index = 0;
    while (index < self->GetTargetCount())
    {
        void* item = self->GetInterpolator(index);

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

// @fnv 0x00a3a950
void __fastcall UpdateKeyTimeRange(NiGeomMorpherController* self, int)
{
    if (!IsManaged(self))
    {
        NiMorphData* morphData = self->m_spMorphTargetData.m_pObject;
        unsigned int numTargets = morphData ? morphData->m_uiNumTargets : 0;
        self->m_fLoKeyTime = DAT_01096ce0;
        self->m_fHiKeyTime = DAT_01015f5c;

        unsigned int index = 0;
        if (index < numTargets)
        {
            do
            {
                NiInterpolator* interpolator = self->GetInterpolator(index);
                if (interpolator)
                {
                    float upper = DAT_01015f5c;
                    float lower = DAT_01096ce0;
                    reinterpret_cast<InterpolatorCaller*>(interpolator)->GetInterpolatorTimeRange(&lower, &upper);
                    if (lower < self->m_fLoKeyTime)
                    {
                        self->m_fLoKeyTime = lower;
                    }
                    if (upper > self->m_fHiKeyTime)
                    {
                        self->m_fHiKeyTime = upper;
                    }
                }
                ++index;
            } while (index < numTargets);
        }
    }
}

extern const NiPoint3 DAT_011f426c;

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

// @fnv 0x00a3abe0
void __fastcall UpdateGeometryBound(NiGeomMorpherController* self, int)
{
    NiBound morphBound;
    const unsigned int count = self->m_spMorphTargetData.m_pObject->m_uiNumTargets;
    if (count != 0)
    {
        NiMorphData* data = self->m_spMorphTargetData.m_pObject;
        morphBound.ComputeBoundingSphere(data->m_uiNumVertsPerTarget, data->GetTarget(0)->m_pkVertexPositions);
        for (unsigned int i = 1; i < count; ++i)
        {
            NiBound targetBound;
            data = self->m_spMorphTargetData.m_pObject;
            targetBound.ComputeBoundingSphere(data->m_uiNumVertsPerTarget, data->GetTarget(i)->m_pkVertexPositions);
            morphBound.NiBound_Merge(&targetBound);
        }
    }
    else
    {
        morphBound.m_kCenter = DAT_011f426c;
        morphBound.m_fRadius = 0.0f;
    }
    volatile float radiusValue = morphBound.m_fRadius;
    NiBound* pBound = reinterpret_cast<Geometry*>(self->m_pkTarget)->GetModelData()->GetBound();
    pBound->m_kCenter = morphBound.m_kCenter;
    pBound->m_fRadius = radiusValue;
}

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

// Calls FUN_00a6d0c0(p), then forwards p to Slot26 on each non-null item pointer in items up to FUN_008d3ed0().
// @fnv 0x00a3acb0
void __fastcall ProcessMorphClone(NiGeomMorpherController* self, int, void* p)
{
    self->NiInterpController::ProcessClone(*static_cast<CloningProcess*>(p));
    unsigned short i;
    for (i = 0; i < self->GetNumTargets(); i++)
    {
        FUN_00a3acb0_elem* pElem = (FUN_00a3acb0_elem*)self->m_pInterpolatorItems[i].m_spControllerInterpolator.m_pObject;
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

inline NiGeomMorpherController::InterpItem::~InterpItem()
{
}

// Releases the morph data pointer and destroys the interpolator item array, then frees its allocation cookie.
// @fnv 0x00a3af10
NiGeomMorpherController::~NiGeomMorpherController() throw()
{
    m_spMorphTargetData = 0;
    // NiDelete[] m_pInterpolatorItems, expanded: destroy elements back to front, then free the count cookie
    if (m_pInterpolatorItems)
    {
        unsigned int* puiCookie = reinterpret_cast<unsigned int*>(m_pInterpolatorItems) - 1;
        int i = *puiCookie;
        InterpItem* pkItem = m_pInterpolatorItems + i;
        while (--i >= 0)
        {
            --pkItem;
            pkItem->~InterpItem();
        }
        g_A3AF10MemoryManager.Deallocate(puiCookie);
    }
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

// @fnv 0x00a3b530
NiGeomMorpherController* __fastcall DeleteMorphController(NiGeomMorpherController* self, int, unsigned char acFlags)
{
    self->NiGeomMorpherController::~NiGeomMorpherController();
    if (acFlags & 1)
    {
        FUN_00aa1460(self, 0x44);
    }
    return self;
}

// Stores pkMorphData, calls FUN_00a3b460, and if bCanUpdate is set invokes the virtual method at vtable slot v59.
// @fnv 0x00a3ba10
void NiGeomMorpherController::SetMorphData(NiMorphData* pkMorphData, bool bCanUpdate)
{
    m_spMorphTargetData = pkMorphData;
    ClearInterpolatorArray();
    if (bCanUpdate)
    {
        vf59();
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

// Applies a SetterArg to this object: sets flags and m_28, calls Sub_00a36250/Sub_00a3aa10, and attaches an object when m_2c and m_40 are set.
// @fnv 0x00a3b080
void __fastcall ApplySetterArg(NiGeomMorpherController* self, int, SetterArg* a1)
{
    if (self->m_spMorphTargetData.m_pObject == 0)
    {
        return;
    }
    if (a1->m_05 != 0)
    {
        a1->m_07 = 1;
        return;
    }
    unsigned char uiFlags = ((self->NiTimeController::m_uiObjectFlags >> 5) & 7);
    if ((uiFlags & 1) != 0)
    {
        self->m_bUpdateEnabled = 1;
        self->m_fControllerTime = DAT_01096324;
    }
    else
    {
        bool ok = self->DontDoUpdate(a1->m_00);
        if (!ok || self->m_bNeedsUpdate != 0)
        {
            self->m_bUpdateEnabled = 1;
        }
    }
    if (reinterpret_cast<Owner*>(self->m_pkTarget) == 0)
    {
        return;
    }
    if (self->m_bUpdateEnabled == 0)
    {
        return;
    }
    reinterpret_cast<void (__thiscall*)(NiGeomMorpherController*, float)>(&fnv_00a3aa10::UpdateMorphWeights)(self, self->m_fControllerTime);
    if (DAT_011f3725 == 0)
    {
        return;
    }
    if (!Free_00714a00())
    {
        return;
    }
    if (reinterpret_cast<Owner*>(self->m_pkTarget)->m_b8->m_04 != 1)
    {
        return;
    }
    Obj56* obj = Free_00a56f90();
    if (obj != 0)
    {
        obj->Attach(self, reinterpret_cast<Owner*>(self->m_pkTarget));
        if (!DAT_011f5b04->Check(obj, 2))
        {
            obj->V25();
        }
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

// Allocates a morph controller with no morph data.
// @fnv 0x00a3b550
// src: EXE 0x00a3b550
NiGeomMorpherController* __cdecl NiGeomMorpherController_CreateObject()
{
    return new NiGeomMorpherController(0);
}

// NiInterpController's IsEqual override is not declared in the shared header yet.
extern bool __cdecl IsInterpControllerEqual();

// @fnv 0x00a3ad00
bool __fastcall IsMorphEqual(NiGeomMorpherController* self, int, NiObject* pkObject)
{
    if (!reinterpret_cast<bool (__thiscall*)(NiInterpController*, NiObject*)>(&IsInterpControllerEqual)(self, pkObject))
        return false;

    NiGeomMorpherController* pkMorph = (NiGeomMorpherController*)pkObject;

    if (!self->m_spMorphTargetData->IsEqual(pkMorph->m_spMorphTargetData))
        return false;

    for (unsigned int i = 0; i < self->GetNumTargets(); i++)
    {
        NiGeomMorpherController::InterpItem& kOther = pkMorph->m_pInterpolatorItems[i];
        if ((kOther.m_spControllerInterpolator && !self->m_pInterpolatorItems[i].m_spControllerInterpolator) ||
            (!kOther.m_spControllerInterpolator && self->m_pInterpolatorItems[i].m_spControllerInterpolator))
            return false;
        if (kOther.m_spControllerInterpolator &&
            !kOther.m_spControllerInterpolator->IsEqual(self->m_pInterpolatorItems[i].m_spControllerInterpolator))
            return false;
        if (kOther.m_fWeight != self->m_pInterpolatorItems[i].m_fWeight)
            return false;
    }
    return true;
}

// 0x00a41590  lea eax,[ecx+4]; ret
struct C00a41590
{
    char pad00[0x4];
    int m4;
    int* NiMorphData_MorphTarget_GetName();
};

// @fnv 0x00a41590
// src: XBOX_PDB 0x00a41590
int* C00a41590::NiMorphData_MorphTarget_GetName()
{
    return &m4;
}

// Allocates a controller, clones this controller's members and returns the clone.
// @fnv 0x00a3bb80
NiObject* NiGeomMorpherController::MakeClone(CloningProcess& kCloning)
{
    NiGeomMorpherController* pkClone = new NiGeomMorpherController;
    CopyMemberData(pkClone, kCloning);
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
template <class T> inline void SaveStreamValue(NiStream& stream, const T& value)
{
    NiBinaryOutput* output = reinterpret_cast<NiBinaryOutput*&>(stream.m_pkOstr);
    output->Write(&value, sizeof(T));
}

struct S00c27120
{
    void NiInterpController_SaveBinary(NiStream&);
};

inline unsigned int GetMorphTargetCountSV(const NiGeomMorpherController* self)
{
    if (self->m_spMorphTargetData.m_pObject)
        return self->m_spMorphTargetData.m_pObject->m_uiNumTargets;
    return 0;
}

// Calls FUN_00c27120, then saves a value, morph target link, update flag, target count, and interpolator links and weights.
// @fnv 0x00a3b350
void __fastcall SaveMorphData(NiGeomMorpherController* self, int, NiStream& stream)
{
    reinterpret_cast<S00c27120*>(self)->NiInterpController_SaveBinary(stream);
    SaveStreamValue(stream, self->m_uiObjectFlags);
    stream.SaveLinkID(reinterpret_cast<const NiObject*>(self->m_spMorphTargetData.m_pObject));
    unsigned char bNeedsUpdate = self->m_bNeedsUpdate;
    SaveStreamValue(stream, bNeedsUpdate);
    unsigned int count = GetMorphTargetCountSV(self);
    SaveStreamValue(stream, count);
    for (unsigned int i = 0; i < count; ++i)
    {
        stream.SaveLinkID(reinterpret_cast<const NiObject*>(self->m_pInterpolatorItems[i].m_spControllerInterpolator.m_pObject));
        SaveStreamValue(stream, self->m_pInterpolatorItems[i].m_fWeight);
    }
}
