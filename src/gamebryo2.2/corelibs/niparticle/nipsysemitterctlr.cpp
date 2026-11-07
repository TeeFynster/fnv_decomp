// gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp: particle emitter controllers (39 functions)

#include "NiObject.h"
#include "NiRefObject_inline.h"
#include "../../../../include/NiBoolInterpController.h"
#include "../../../../include/NiBoolInterpolator.h"
#include "../../../../include/NiInterpController.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiPSysEmitterCtlr.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiPSysModifierBoolCtlr.h"
#include "../../../../include/NiPSysModifierCtlr.h"
#include "../../../../include/NiSingleInterpController.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTPrimitiveSet_float_.h"
#include "../../../../include/NiTSet_float_NiTMallocInterface_float___.h"
#include "../../../../include/NiTimeController.h"
class NiFloatData;
// LocalNiFloatInterpolator: NiPSysEmitterCtlr 0x00c1c0e0 builds it with placement new and no unwind state, so its constructor must be
// throw(); include/NiFloatInterpolator.h declares it without an exception specification.
class LocalNiFloatInterpolator : public NiInterpolator
{
public:
    LocalNiFloatInterpolator(NiFloatData* data) throw();
    void SetAnimationKeys(void* keys, unsigned int count, unsigned int keyType);
};
#include "nipsysemitterctlr_external.h"
#include "../../../../include/NiBoolData.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/StrArr.h"
#include <new>

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

inline void NiInterpolator::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiInterpolator::DecRefCount()
{
    NiRefObject::DecRefCount();
}

// @fnv 0x00c1bdf0
void NiPSysEmitterCtlr::LoadBinary(NiStream& stream)
{
    NiPSysModifierCtlr::LoadBinary(stream);
    stream.ResetStreamState();
}

// Calls the base ProcessClone, then clones the interpolator stored in the member if it is non-null.
// @fnv 0x00c1bdc0
void NiPSysEmitterCtlr::ProcessClone(CloningProcess& process)
{
    NiPSysModifierCtlr::ProcessClone(process);
    NiInterpolator* interpolator = m_spVisibilityInterpolator.m_pObject;
    if (interpolator)
        interpolator->ProcessClone(process);
}

// @fnv 0x00c1bd30
void NiPSysEmitterCtlr::CopyMemberData(NiPSysEmitterCtlr* destination, CloningProcess& arProcess)
{
    NiPSysModifierCtlr::CopyMemberData(destination, arProcess);

    NiInterpolator* source = m_spVisibilityInterpolator.m_pObject;
    if (source)
    {
        NiInterpolator* cloned = static_cast<NiInterpolator*>(source->MakeClone(arProcess));

        NiInterpolator* oldInterpolator = destination->m_spVisibilityInterpolator.m_pObject;
        if (oldInterpolator != cloned)
        {
            if (oldInterpolator)
                oldInterpolator->DecRefCount();
            destination->m_spVisibilityInterpolator.m_pObject = cloned;
            if (cloned)
                cloned->IncRefCount();
        }
    }

    if ((destination->m_uiObjectFlags & 0x6) == 0 && destination->m_fPhase == 0.0f)
        destination->m_fPhase = GetRandomNumber() / DAT_01029790 * DAT_01017a40;
}

// @fnv 0x00c1c0e0
void NiPSysEmitterCtlr::LinkObject(NiStream& stream)
{
    NiPSysModifierCtlr::LinkObject(stream);

    if (stream.m_uiNifFileVersion < 0x0a010068)
    {
        NiObject* data = stream.GetLoadedObject();
        if (!data)
            return;

        data->IncRefCount();

        LocalNiFloatInterpolator* floatMemory = static_cast<LocalNiFloatInterpolator*>(NiPSysEmitterCtlr::operator new(0x18));
        LocalNiFloatInterpolator* floatInterpolator;
        if (floatMemory)
            floatInterpolator = ::new (floatMemory) LocalNiFloatInterpolator(0);
        else
            floatInterpolator = 0;

        unsigned int* fields = reinterpret_cast<unsigned int*>(data);
        floatInterpolator->SetAnimationKeys(reinterpret_cast<void*>(fields[3]), fields[2], fields[4]);
        fields[2] = 0;
        fields[3] = 0;
        fields[4] = 0;
        reinterpret_cast<unsigned char*>(data)[0x14] = 0;
        SetInterpolator(floatInterpolator, 0);

        NiBoolInterpolator* boolMemory = static_cast<NiBoolInterpolator*>(NiPSysEmitterCtlr::operator new(0x18));
        NiBoolInterpolator* boolInterpolator;
        if (boolMemory)
            boolInterpolator = ::new (boolMemory) NiBoolInterpolator(static_cast<void*>(0));
        else
            boolInterpolator = 0;

        boolInterpolator->SetAnimationKeys(reinterpret_cast<void*>(fields[7]), fields[8], fields[6]);
        fields[6] = 0;
        fields[7] = 0;
        reinterpret_cast<unsigned char*>(data)[0x24] = 0;
        SetInterpolator(boolInterpolator, 1);
        data->DecRefCount();
        return;
    }

    if ((m_uiObjectFlags & 0x6) == 0 && m_fPhase == 0.0f)
        m_fPhase = GetRandomNumber() / DAT_01029790 * DAT_01017a40;

    NiInterpolator* active = static_cast<NiInterpolator*>(stream.GetLoadedObject());
    NiInterpolator* old = m_spVisibilityInterpolator.m_pObject;
    if (old != active)
    {
        if (old)
            old->DecRefCount();
        m_spVisibilityInterpolator.m_pObject = active;
        if (active)
            active->IncRefCount();
    }
}

// Constructor entry points not yet declared by the shared controller headers.
void __fastcall ConstructInterpController(NiInterpController* controller) throw();
extern void* kVtbl_NiSingleInterpController;

// @fnv 0x00a38e00
NiSingleInterpController* __fastcall ConstructSingleInterpController(NiSingleInterpController* controller)
{
    ConstructInterpController(controller);
    *(void**)controller = &kVtbl_NiSingleInterpController;
    controller->m_spControllerInterpolator.m_pObject = 0;
    return controller;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4054;
// Returns the address of the global object g_011f4054.
// @fnv 0x00a537e0
// src: COMMUNITY 0x00a537e0
void* __cdecl NiBoolData_GetRTTI()
{
    return &g_011f4054;
}

// @fnv 0x00c1ba30
// src: XBOX_PDB 0x00c1ba30
void __fastcall NiPSysEmitterCtlr_Stop(NiPSysEmitterCtlr* self, int unused)
{
    self->m_fScaledLastTime = DAT_01015f5c;
    self->NiTimeController::Stop();
}

extern const char* const g_01203340_arg1;
// @fnv 0x00c1c2f0
// src: COMMUNITY 0x00c1c2f0
const char* const* __cdecl NiPSysEmitterCtlr_GetRTTI()
{
    return &g_01203340_arg1;
}

extern int DAT_011ae754;
extern int DAT_011ae758;

// @fnv 0x00c1ba50
// src: XBOX_PDB 0x00c1ba50
const char* const* __stdcall NiPSysEmitterCtlr_GetInterpolatorID(unsigned short usIndex)
{
    if (usIndex == 0)
        return reinterpret_cast<const char* const*>(DAT_011ae754);
    int r = (usIndex != 1) - 1;
    r = r & DAT_011ae758;
    return reinterpret_cast<const char* const*>(r);
}

// Stores pkInterpolator into the interpolator slot at offset 0x34 (ref-counted) when usIndex is 0, or at offset 0x40 when usIndex is 1.
// @fnv 0x00c1bcc0
void NiPSysEmitterCtlr::SetInterpolator(NiInterpolator* pkInterpolator, unsigned short usIndex)
{
    if (usIndex == 0)
    {
        char* p = (char*)this + 0x34;
        NiPointer<NiInterpolator>* pInterpolatorPtr = (NiPointer<NiInterpolator>*)p;
        if (pInterpolatorPtr->m_pObject != pkInterpolator)
        {
            if (pInterpolatorPtr->m_pObject)
                pInterpolatorPtr->m_pObject->DecRefCount();
            pInterpolatorPtr->m_pObject = pkInterpolator;
            if (pInterpolatorPtr->m_pObject)
                pInterpolatorPtr->m_pObject->IncRefCount();
        }
    }
    else if (usIndex == 1)
    {
        char* p = (char*)this + 0x40;
        NiPointer<NiInterpolator>* pInterpolatorPtr = (NiPointer<NiInterpolator>*)p;
        *pInterpolatorPtr = pkInterpolator;
    }
}

extern MemoryManager g_memoryManager;
extern int DAT_0109a1d4;
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00a53a10
void* NiBoolData::Destroy(unsigned int auiFlags)
{
    void* keys = m_pKeyArray;
    *(void**)this = (void*)&DAT_0109a1d4;
    if (keys)
        g_memoryManager.Deallocate((char*)keys - 4);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        _delete(this, 0x18);
    return this;
}

extern "C" int __cdecl NiStricmp(const char*, const char*);
extern const unsigned short DAT_NiInterpController_INVALID_INDEX;
// Compares pcID against two strings and returns 0, 1, or DAT_NiInterpController_INVALID_INDEX when neither matches.
// @fnv 0x00c1ba80
unsigned short __stdcall GetInterpControllerIndex(const char* pcControllerID)
{
    if (NiStricmp(pcControllerID, (const char*)DAT_011ae754) == 0)
        return 0;
    if (NiStricmp(pcControllerID, (const char*)DAT_011ae758) == 0)
        return 1;
    return DAT_NiInterpController_INVALID_INDEX;
}

struct S1
{
    void* FUN_00a3c390(float);
};
// @fnv 0x00c1bad0
NiInterpolator* __stdcall CreateInterpolatorByIndex(unsigned short usInterpolatorIndex)
{
    if (usInterpolatorIndex == 0)
    {
        void* p = BSFadeNode::operator new(0x18);
        if (!p)
            return 0;
        return (NiInterpolator*)((S1*)p)->FUN_00a3c390(0.0f);
    }
    if (usInterpolatorIndex == 1)
    {
        void* p = BSFadeNode::operator new(0x18);
        if (!p)
            return 0;
        return ::new (p) NiBoolInterpolator(false);
    }
    return 0;
}

struct FUN_00c1bb90_Inner
{
    char pad[0x14];
    float v;
};
struct S_00c1bb90
{
    float GetValueForIndex(unsigned char);
};
// Returns the cached float at offset 0x20 when the flag at 0xE is 1 and a matches the byte at 0xF, otherwise the float from the array at 0x14 indexed by a.
// @fnv 0x00c1bb90
float S_00c1bb90::GetValueForIndex(unsigned char a)
{
    if (*(unsigned char*)((char*)this + 0xE) == 1 && a == *(unsigned char*)((char*)this + 0xF))
        return *(float*)((char*)this + 0x20);
    return ((FUN_00c1bb90_Inner*)*(char**)((char*)this + 0x14))[a].v;
}

// Returns the NiInterpolator pointer stored at offset 0x34 for index 0, at 0x40 for index 1, otherwise null.
// @fnv 0x00c1bc90
NiInterpolator* __fastcall GetEmitterInterpolator(NiPSysEmitterCtlr* self, int unused, unsigned short usIndex)
{
    if (usIndex == 0)
        return self->m_spControllerInterpolator.m_pObject;
    if (usIndex == 1)
        return self->m_spVisibilityInterpolator.m_pObject;
    return 0;
}

bool __stdcall FUN_00a57780(NiStream& kStream);
// Calls FUN_00a57780, then if the interpolator at offset 0x40 is non-null, registers its streamables with kStream; returns true.
// @fnv 0x00c1be10
bool __fastcall RegisterEmitterInterpolatorStreamables(NiPSysEmitterCtlr* self, int unused, NiStream& kStream)
{
    if (!FUN_00a57780(kStream))
        return false;
    NiInterpolator* pkEmitter = self->m_spVisibilityInterpolator.m_pObject;
    if (pkEmitter)
        pkEmitter->RegisterStreamables(kStream);
    return true;
}

// The shared modifier controller does not yet declare its SaveBinary override.
void SaveModifierCtlrBinary();

// @fnv 0x00c1be40
void __fastcall SaveEmitterBinary(NiPSysEmitterCtlr* self, int unused, NiStream& kStream)
{
    reinterpret_cast<void(__thiscall*)(NiPSysModifierCtlr*, NiStream&)>(&SaveModifierCtlrBinary)(self, kStream);
    kStream.SaveLinkID(self->m_spVisibilityInterpolator.m_pObject);
}

void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFreeAlias(void*);
// Supply the missing set operations without duplicating the shared storage.
struct FloatSetOperations : NiTPrimitiveSet_float_
{
    void Reallocate(unsigned int capacity);
    void PushBack(const float& value);
};

// Resizes the float storage while preserving the used elements.
// @fnv 0x00c1beb0
void FloatSetOperations::Reallocate(unsigned int uiNewCapacity)
{
    if (uiNewCapacity == m_uiElementCount)
        return;
    float* pfNewData;
    if (uiNewCapacity > 0)
    {
        pfNewData = (float*)_NiMalloc(uiNewCapacity * 4);
        for (unsigned int i = 0; i < m_uiAllocatedCapacity; ++i)
            pfNewData[i] = m_pBase[i];
    }
    else
    {
        pfNewData = 0;
    }
    _NiFreeAlias(m_pBase);
    m_pBase = pfNewData;
    m_uiElementCount = uiNewCapacity;
}

bool __fastcall CheckSingleInterpTarget(NiSingleInterpController* controller);
struct B00c1bff0
{
    void* FUN_00c1b0f0(void*);
};
struct M00c1bff0
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};
extern int g_01202500_arg1;
struct EmitterTargetCheck : NiPSysEmitterCtlr
{
    bool NiPSysEmitterCtlr_TargetIsRequiredType();
};
// Checks FUN_00a38df0, resolves a modifier via reinterpret_cast<B00c1bff0*>(m_pkTarget)->FUN_00c1b0f0(&m_kTargetModifierName), then scans its RTTI chain for g_01202500_arg1 and returns whether it is found.
// @fnv 0x00c1bff0
// src: XBOX_PDB 0x00c1bff0
bool EmitterTargetCheck::NiPSysEmitterCtlr_TargetIsRequiredType()
{
    if (!CheckSingleInterpTarget(this))
        return false;
    M00c1bff0* pkModifier = (M00c1bff0*)reinterpret_cast<B00c1bff0*>(m_pkTarget)->FUN_00c1b0f0(&m_kTargetModifierName);
    if (!pkModifier)
        return false;
    void* pRttiEntry = pkModifier->v2();
    for (; pRttiEntry; pRttiEntry = *(void**)((char*)pRttiEntry + 4))
    {
        if (pRttiEntry == (void*)&g_01202500_arg1)
            return true;
    }
    return false;
}

// Grows the storage when full, then appends the value.
// @fnv 0x00c1c240
void FloatSetOperations::PushBack(float const& afValue)
{
    if (m_uiAllocatedCapacity == m_uiElementCount)
    {
        unsigned int n = m_uiElementCount > 0 ? m_uiElementCount + m_uiElementCount : 1;
        Reallocate(n);
    }
    m_pBase[m_uiAllocatedCapacity++] = afValue;
}

void __cdecl _NiFreeAlias(void*);
void __fastcall DestroyModifierCtlr(NiPSysModifierCtlr* controller);
struct EmitterRelease : NiPSysEmitterCtlr
{
    void Release();
};
// Frees the pointer at offset 0x50, decrements the ref count of the interpolator at offset 0x40, then calls FUN_00c312a0.
// @fnv 0x00c1c300
void EmitterRelease::Release()
{
    _NiFreeAlias(m_kBirthRateKeys.m_pBase);
    NiInterpolator* p = m_spVisibilityInterpolator.m_pObject;
    if (p)
        p->DecRefCount();
    DestroyModifierCtlr(this);
}

void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
struct EmitterDestroy : NiPSysEmitterCtlr
{
    void* ReleaseAndMaybeDelete(unsigned int);
};
// Frees the pointer at offset 0x50, decrements the ref count of the object at 0x40, calls FUN_00c312a0, and deletes this if flag bit 0 is set.
// @fnv 0x00c1c340
void* EmitterDestroy::ReleaseAndMaybeDelete(unsigned int flag)
{
    _NiFreeAlias(m_kBirthRateKeys.m_pBase);
    NiObject* pk = m_spVisibilityInterpolator.m_pObject;
    if (pk)
        pk->DecRefCount();
    DestroyModifierCtlr(this);
    if (flag & 1)
        _delete(this, 0x5c);
    return this;
}

namespace fnv_00c2b7d0 {
struct RTTI_00c2b7d0
{
    int _0;
    RTTI_00c2b7d0* m_pkBase;
};
extern RTTI_00c2b7d0 g_01202500_arg1;
struct S_00c31530
{
    bool IsTargetParticleSystem(void* pkTarget);
};
struct S_00c1b0f0
{
    void* FUN_00c1b0f0(void* p);
};
struct Mod_00c2b7d0
{
    virtual void _v0();
    virtual void _v1();
    virtual RTTI_00c2b7d0* _v2();
};
struct Holder00c2b7d0
{
    bool NiPSysEmitterCtlr_InterpTargetIsCorrectType(void* pkTarget);
};
// Checks the target via IsTargetParticleSystem, resolves a modifier from this+0x38, then walks its RTTI base chain looking for g_01202500_arg1.
// @fnv 0x00c2b7d0
// src: XBOX_PDB 0x00c2b7d0
bool Holder00c2b7d0::NiPSysEmitterCtlr_InterpTargetIsCorrectType(void* pkTarget)
{
    void* pkModifier;
    if (!((S_00c31530*)this)->IsTargetParticleSystem(pkTarget))
        return false;
    pkModifier = ((S_00c1b0f0*)pkTarget)->FUN_00c1b0f0((void*)((char*)this + 0x38));
    if (!pkModifier)
        return false;
    RTTI_00c2b7d0* pkRTTI = ((Mod_00c2b7d0*)pkModifier)->_v2();
    if (!pkRTTI)
        return false;
    for (; pkRTTI; pkRTTI = pkRTTI->m_pkBase)
    {
        if (pkRTTI == &g_01202500_arg1)
            return true;
    }
    return false;
}
}  // namespace fnv_00c2b7d0

// @fnv 0x00c1bbc0
void __fastcall SetEmitterActiveTimeRange(NiPSysEmitterCtlr* self, int unused, float afValue1, float afValue2)
{
    self->NiSingleInterpController::SetActiveTimeRange(afValue1, afValue2);
    NiInterpolator* pk = self->m_spVisibilityInterpolator.m_pObject;
    if (pk)
        pk->SetActiveTimeRange(afValue1, afValue2);
}

struct NiBlendInterpolator;
struct FUN_00a40520
{
    FUN_00a40520(bool, float, unsigned char);
};
struct FUN_00a40520_shell
{
    NiBlendInterpolator* FUN_00a40520(bool, float, unsigned char);
};
struct FUN_00a56560_shell
{
    NiBlendInterpolator* ConstructBlendInterpolator(bool, float, unsigned char);
};
// Allocates a 0x34-byte NiBlendInterpolator and constructs variant 0 or 1 based on usIndex, returning null otherwise.
// @fnv 0x00c1bb20
// src: XBOX_PDB 0x00c1bb20
NiBlendInterpolator* __stdcall NiPSysEmitterCtlr_CreateBlendInterpolator(unsigned short usVariant, bool bAccumulateAnimations,
                                            bool bManagerControlled, float fWeightThreshold, unsigned char ucArraySize)
{
    if (usVariant == 0)
    {
        void* p = BSFadeNode::operator new(0x34);
        if (p)
            return reinterpret_cast<FUN_00a40520_shell*>(p)->FUN_00a40520(bAccumulateAnimations, fWeightThreshold,
                                                                          ucArraySize);
    }
    else if (usVariant == 1)
    {
        void* p = BSFadeNode::operator new(0x34);
        if (p)
            return reinterpret_cast<FUN_00a56560_shell*>(p)->ConstructBlendInterpolator(bAccumulateAnimations,
                                                                                        fWeightThreshold, ucArraySize);
    }
    return 0;
}

char* __cdecl _FUN_00a7d330(char*);
void __stdcall AppendModifierInfo(StrArr*);

// @fnv 0x00c1ce70
void __fastcall AppendEmitterViewerStrings(NiPSysEmitterCtlr* self, int unused, StrArr* pkStrings)
{
    AppendModifierInfo(pkStrings);
    char* pcString = _FUN_00a7d330((char*)g_01203340_arg1);
    unsigned int uiIndex = pkStrings->m_usSize;
    unsigned int uiSize = pkStrings->m_usMaxSize;
    if (uiIndex >= uiSize)
    {
        unsigned int uiGrow = pkStrings->m_usGrowBy;
        pkStrings->SetSize(uiGrow + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcString);
    NiInterpolator* pkInterp = self->m_spVisibilityInterpolator.m_pObject;
    if (pkInterp)
    {
        void** vtbl = *(void***)pkInterp;
        void(__thiscall * fn)(NiInterpolator*, StrArr*) = (void(__thiscall*)(NiInterpolator*, StrArr*))vtbl[0x60 / 4];
        fn(pkInterp, pkStrings);
    }
}

extern int DAT_0109a864;

struct S_00a56be0
{
    void* unk00;
    int unk04;
    volatile int unk08;
    volatile int unk0c;
    volatile int unk10;

    void FUN_00a5d3a0();
    S_00a56be0* Initialize();
};

// @fnv 0x00a56be0
S_00a56be0* S_00a56be0::Initialize()
{
    this->FUN_00a5d3a0();

    unk08 = 0;
    unk00 = &DAT_0109a864;
    unk0c = 0;
    unk10 = 0;

    return this;
}

struct CBaseA
{
    virtual void v0();
    int m4;
    CBaseA() throw();
};

struct CChildA;

struct CChildA : CBaseA
{
    int m8;
    int mc;
    int m10;
    unsigned char m14;
    CChildA()
    {
        m8 = 0;
        mc = 0;
        m10 = 0;
        m14 = 0;
    }
    static void* operator new(unsigned int size);
    void M(unsigned int a, unsigned int b, unsigned int c);
};

// Creates key data when needed, installs the keys, and resets the cached key index.
// @fnv 0x00c1bf10
void NiBoolInterpolator::SetAnimationKeys(void* keys, unsigned int keyType, unsigned int count)
{
    if (count > 0)
    {
        if (!m_spBoolData.m_pObject)
            m_spBoolData = reinterpret_cast<NiBoolData*>(new CChildA);
        reinterpret_cast<CChildA*>(m_spBoolData.m_pObject)->M(reinterpret_cast<unsigned int>(keys), count, keyType);
        m_uiLastKeyIndex = 0;
    }
    else
    {
        if (m_spBoolData.m_pObject)
            reinterpret_cast<CChildA*>(m_spBoolData.m_pObject)->M(0, 0, 0);
    }
}

struct C1BF90Entry
{
    int unk00;
    int unk04;
};

struct C1BF90Result
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned char unk0E;
    unsigned char unk0F;
    int unk10;
    C1BF90Entry* unk14;
    int unk18;
    unsigned char FindHighestWeightIndex();
};

struct EmitterBoolInterpolatorLookup : NiPSysEmitterCtlr
{
    int GetObjectValueByKey();
};

void FindEmitterBlendInterpolator();
extern unsigned char DAT_01096968;
extern GlobalObjectO2_00a7b610 DAT_011f407c;

// Returns vf54() if nonzero; otherwise looks up an object by DAT_011f407c and returns a value indexed by its key, or 0.
// @fnv 0x00c1bf90
int __thiscall EmitterBoolInterpolatorLookup::GetObjectValueByKey()
{
    int iVf54Result = reinterpret_cast<int>(m_spVisibilityInterpolator->IsNiBoolInterpolator());
    if (iVf54Result == 0)
    {
        if (m_spVisibilityInterpolator.m_pObject != 0)
        {
            C1BF90Result* pResult = reinterpret_cast<C1BF90Result*(__thiscall*)(NiInterpolator*, const void*)>(&FindEmitterBlendInterpolator)(m_spVisibilityInterpolator, &DAT_011f407c);
            if (pResult != 0)
            {
                unsigned char key = pResult->FindHighestWeightIndex();
                if (key != DAT_01096968)
                {
                    if (pResult->unk0E == 1 && key == pResult->unk0F)
                        return pResult->unk18;

                    return pResult->unk14[key * 3].unk00;
                }
            }
        }
        return 0;
    }

    return iVf54Result;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern char* g_pcC1C280NullString;

char* __cdecl FUN_00a5b690(const char* pcString);

static const float NI_INFINITY = 3.402823466e+38f;
static const float INVALID_FLOAT = -NI_INFINITY;

class BC1C280FixedString
{
  public:
    BC1C280FixedString(const char* pcString) throw()
    {
        if (pcString == 0)
            m_kHandle = g_pcC1C280NullString;
        else
            m_kHandle = FUN_00a5b690(pcString);
    }
    ~BC1C280FixedString() throw()
    {
        if (m_kHandle != g_pcC1C280NullString)
            InterlockedDecrement((long*)(m_kHandle - 8));
    }

    char* m_kHandle;
};

// The shared modifier header lacks the named-constructor declaration.
class BC1C280Base : public NiPSysModifierCtlr
{
public:
    BC1C280Base(const BC1C280FixedString& name) throw();
    virtual ~BC1C280Base();
};

struct BC1C280Tracker
{
    BC1C280Tracker() : m_pkTarget(0), m_uiCount(0), m_fLastValue(INVALID_FLOAT), m_bModifierActive(false)
    {}

    void* m_pkTarget;
    unsigned int m_uiCount;
    float m_fLastValue;
    bool m_bModifierActive;
};

struct BC1C280Links
{
    BC1C280Links() : m_pkFirst(0), m_pkSecond(0), m_pkThird(0)
    {}

    void* m_pkFirst;
    void* m_pkSecond;
    void* m_pkThird;
};

class FUN_00c1c280_cls : public BC1C280Base
{
  public:
    FUN_00c1c280_cls(const char* pcName) throw();
    virtual ~FUN_00c1c280_cls();

    BC1C280Tracker m_kTracker;
    BC1C280Links m_kLinks;
};

// Constructs the object by forwarding pcName to the BC1C280Base base-class constructor.
// @fnv 0x00c1c280
FUN_00c1c280_cls::FUN_00c1c280_cls(const char* pcName) throw() : BC1C280Base(pcName)
{}

// The shared emitter has no declaration for this operation; it needs no additional storage.
struct EmitterKeyTimeRange : NiPSysEmitterCtlr
{
    void UpdateKeyTimeRange();
};

// @fnv 0x00c1bc10
void EmitterKeyTimeRange::UpdateKeyTimeRange()
{
    if ((bool)(static_cast<unsigned short>((m_uiObjectFlags & MANAGERCONTROLLED_MASK) >> 5) & 1))
        return;
    m_spControllerInterpolator->GetInterpolatorTimeRange(m_fLoKeyTime, m_fHiKeyTime);
    float fBegin;
    float fSecondEnd;
    m_spVisibilityInterpolator->GetInterpolatorTimeRange(fBegin, fSecondEnd);
    if (fBegin < m_fLoKeyTime)
        m_fLoKeyTime = fBegin;
    if (fSecondEnd > m_fHiKeyTime)
        m_fHiKeyTime = fSecondEnd;
}

namespace fnv_00c1be60 {
class NiBaseC1B : public NiPSysEmitterCtlr
{
public:
    bool BaseIsEqual(NiObject* object);
    bool NiPSysEmitterCtlr_IsEqual(NiObject* object);
};

// @fnv 0x00c1be60
// src: XBOX_PDB 0x00c1be60
bool NiBaseC1B::NiPSysEmitterCtlr_IsEqual(NiObject* pkObject)
{
    if (!BaseIsEqual(pkObject))
        return false;

    NiBaseC1B* pkOther = (NiBaseC1B*)pkObject;
    if ((!pkOther->m_spVisibilityInterpolator && m_spVisibilityInterpolator) || (pkOther->m_spVisibilityInterpolator && !m_spVisibilityInterpolator))
        return false;
    if (pkOther->m_spVisibilityInterpolator && !pkOther->m_spVisibilityInterpolator->IsEqual(m_spVisibilityInterpolator))
        return false;
    return true;
}
}  // namespace fnv_00c1be60

struct EmitterStandIn
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
    virtual void UpdateEmitter(float fTime, unsigned short uiNumParticles, const float* afAges);
};
extern unsigned short DAT_011ae75c;
struct AgeSet : NiTPrimitiveSet_float_
{
    void Add(const float& fValue)
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            ((FloatSetOperations*)this)->Reallocate(m_uiElementCount > 0 ? 2 * m_uiElementCount : 1);
        m_pBase[m_uiAllocatedCapacity++] = fValue;
    }
};
struct EmitCtlr : NiPSysEmitterCtlr
{
    void EmitParticlesInInterval(float fTime, float fCurTime, float fLastTime, float fEmitStart, float fEmitStop,
                                 float fEmissionRate);
};
// @fnv 0x00c1c3c0
void EmitCtlr::EmitParticlesInInterval(float fTime, float fCurTime, float fLastTime, float fEmitStart, float fEmitStop,
                                       float fEmissionRate)
{
    if (fEmissionRate > 0.0f && fEmitStart < fEmitStop && fEmitStart < fCurTime && fLastTime < fEmitStop)
    {
        float fDuration = ((fCurTime <= fEmitStop) ? fCurTime - fEmitStart : fEmitStop - fEmitStart);
        float fStart = 0.0f;
        if (fEmitStart <= fLastTime)
            fStart = fLastTime - fEmitStart;
        unsigned short usFirst = (unsigned short)(fStart * fEmissionRate);
        unsigned int uiElementCount = (unsigned short)((unsigned short)(fDuration * fEmissionRate) - usFirst);
        if ((unsigned short)uiElementCount > (unsigned short)DAT_011ae75c)
            uiElementCount = DAT_011ae75c;
        float fInvBirthRate = 1.0f / fEmissionRate;
        m_kBirthRateKeys.m_uiAllocatedCapacity = 0;
        for (unsigned short us = 0; us < (unsigned short)uiElementCount; us++)
        {
            float m_fFirstFloatValue = fDuration - (++usFirst) * fInvBirthRate;
            ((AgeSet&)m_kBirthRateKeys).Add(m_fFirstFloatValue);
        }
        ((EmitterStandIn*)m_pkTargetModifier)->UpdateEmitter(fTime, uiElementCount, m_kBirthRateKeys.m_pBase);
    }
}

struct Entry_a36
{
    int unk;
    int unkCur;
    float weight;
    int unk0C;
    int uNewnk;
    int uTmpnk;
};

namespace nsa {
struct FUN_00a368f0_cls
{
    int unk;
    int unkCur;
    int unkValue;
    unsigned char unk0C;
    unsigned char count;
    unsigned char fixed;
    unsigned char fixedIndex;
    int uNewnk;
    Entry_a36* entries;
    unsigned char FindHighestWeightIndex();
};
}

// Returns fixedIndex if fixed is 1, otherwise scans entries for the highest weight and returns its index, or 0xff if none exceed zero.
// @fnv 0x00a368f0
unsigned char nsa::FUN_00a368f0_cls::FindHighestWeightIndex()
{
    if (fixed == 1)
        return fixedIndex;
    float fBestWeight = 0.0f;
    unsigned char bestIndex = 0xff;
    for (unsigned char i = 0; i < count; i++)
    {
        if (entries[i].weight > fBestWeight)
        {
            fBestWeight = entries[i].weight;
            bestIndex = i;
        }
    }
    if (bestIndex == 0xff)
        return 0xff;
    return bestIndex;
}

extern char DAT_011f3738;
extern char DAT_011f3e58;
extern char DAT_011f404c;

struct C040Node
{
    void* m_pData;
    C040Node* m_pNext;
};

struct C040Owner
{
    virtual void v0();
    virtual void v1();
    virtual C040Node* v2();
};

unsigned char __cdecl NiObject_IsKindOf(void* a, void* b);

__forceinline bool C040Has(C040Owner* o, void* p)
{
    for (C040Node* n = o->v2(); n; n = n->m_pNext)
        if (n == p)
            return true;
    return false;
}

// Checks whether obj contains one of the global nodes for the given type (0 or 1), or for type 1 whether FUN_0043b300 matches DAT_011f407c.
// @fnv 0x00c1c040
// src: XBOX_PDB 0x00c1c040
bool __stdcall NiPSysEmitterCtlr_InterpolatorIsCorrectType(C040Owner* pOwner, unsigned short type)
{
    if (type == 0)
    {
        if (pOwner && (C040Has(pOwner, &DAT_011f3738) || C040Has(pOwner, &DAT_011f3e58)))
            return true;
    }
    else if (type == 1)
    {
        if (pOwner && C040Has(pOwner, &DAT_011f404c))
            return true;
        if (NiObject_IsKindOf(&DAT_011f407c, pOwner))
            return true;
    }
    return false;
}

struct ParticleAgeSet : NiTPrimitiveSet_float_
{
    ParticleAgeSet()
    {
        m_pBase = 0;
        m_uiElementCount = 0;
        m_uiAllocatedCapacity = 0;
    }
};

// The shared modifier header lacks its constructor declaration.
void __fastcall ConstructModifierCtlr(NiPSysModifierCtlr* controller) throw();
static const float kNegInfinity = -3.402823466e+38f;

// @fnv 0x00c1c390
inline NiPSysEmitterCtlr* __fastcall ConstructEmitterCtlr(NiPSysEmitterCtlr* controller) throw()
{
    ConstructModifierCtlr(controller);
    *(void**)controller = &kVtbl_NiPSysEmitterCtlr;
    controller->m_spVisibilityInterpolator.NiPointer<NiInterpolator>::NiPointer();
    controller->m_fScaledLastTime = kNegInfinity;
    controller->m_bIsInitialized = false;
    reinterpret_cast<ParticleAgeSet*>(&controller->m_kBirthRateKeys)->ParticleAgeSet::ParticleAgeSet();
    return controller;
}

// @fnv 0x00c1c570
NiObject* NiPSysEmitterCtlr::MakeClone(CloningProcess& process)
{
    NiPSysEmitterCtlr* clone = static_cast<NiPSysEmitterCtlr*>(NiPSysEmitterCtlr::operator new(sizeof(NiPSysEmitterCtlr)));
    clone = clone ? ConstructEmitterCtlr(clone) : 0;
    CopyMemberData(clone, process);
    return clone;
}

// @fnv 0x00c1c5e0
NiPSysEmitterCtlr* __cdecl CreateNiPSysEmitterCtlr()
{
    NiPSysEmitterCtlr* controller = static_cast<NiPSysEmitterCtlr*>(NiPSysEmitterCtlr::operator new(sizeof(NiPSysEmitterCtlr)));
    if (controller)
        return ConstructEmitterCtlr(controller);
    return 0;
}

struct ActiveKey
{
    float time;
    bool value;
    ActiveKey* At(unsigned int i, unsigned char stride)
    {
        return (ActiveKey*)((char*)this + i * stride);
    }
};
// Key-based operations whose declarations are not present in the shared interpolator header.
struct EmitterKeyInterpolator : NiInterpolator
{
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual bool Posed(unsigned short channel);
    __declspec(noalias) ActiveKey* NiBoolInterpolator_GetKeys(unsigned int&, unsigned int&, unsigned char&);
    __declspec(noalias) ActiveKey* NiFloatInterpolator_GetKeys_0(unsigned int&, unsigned int&, unsigned char&);
};
struct C630Blend
{
    void UpdateNormalizedWeights();
    unsigned char FindHighestWeightIndex();
    float GetValueForIndex(unsigned char);
};
struct C630Modifier
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    float span;
};
struct C630Target
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0;
    float offset;
};
extern float DAT_01015f5c;
extern const float DAT_01096324;
extern double DAT_010241b0;
extern double DAT_01011588;
extern GlobalObjectO2_00a7b610 DAT_011f407c;
extern char DAT_011f3e58;
extern "C" bool __cdecl InterpolateBooleanKey(float, ActiveKey*, unsigned int, unsigned int, unsigned int&,
                                              unsigned char);
// Retained emitter layout: inheriting the shared emitter changes 0x00c1c630 (2105 bytes to 2082).
struct C630Ctlr
{
    int unk00, unk04;
    unsigned short m_uiObjectFlags, unk0a;
    int unk0c, unk10;
    float m_fLoKeyTime, m_fHiKeyTime;
    int unk1c;
    float m_fLastTime;
    int unk24;
    float m_fControllerTime;
    NiObjectNET* m_pkTarget;
    int unk30;
    NiPointer<NiInterpolator> m_spControllerInterpolator;
    int unk38;
    NiPSysModifier* m_pkTargetModifier;
    NiPointer<NiInterpolator> m_spVisibilityInterpolator;
    NiInterpolator* m_pEmitterActiveInterpolator;
    float m_fScaledLastTime;
    bool m_bIsInitialized;
    void EmitParticlesInInterval(float a, float b, float c, float d, float e, float f);

    bool DontDoUpdate(float);
    EmitterKeyInterpolator* GetObjectValueByKey();
    EmitterKeyInterpolator* NiPSysEmitterCtlr_GetBirthRateInterpolator();
    bool Manager() const
    {
        return (bool)(((m_uiObjectFlags & 0x20) >> 5) & 1);
    }
    void NiPSysEmitterCtlr_Update(float* time);
};
// Updates the particle controller time and emits particles over the active intervals between the old and new times using the rate interpolator.
// @fnv 0x00c1c630
// src: XBOX_PDB 0x00c1c630
void C630Ctlr::NiPSysEmitterCtlr_Update(float* time)
{
    if (m_fLastTime > *time)
        m_fScaledLastTime = DAT_01015f5c;
    if (!m_pkTarget || !m_pkTargetModifier)
        return;
    if (Manager())
        m_fControllerTime = DAT_01096324;
    if (m_fLastTime != DAT_010241b0 && !(m_uiObjectFlags & 6) &&
        *time - m_fLastTime > ((C630Modifier*)m_pkTargetModifier)->span)
        m_fLastTime = *time;
    if (DontDoUpdate(*time))
        return;
    if (!m_spVisibilityInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject)
        return;
    float activeBlendTime = DAT_01015f5c;
    if (NiObject_IsKindOf(&DAT_011f407c, m_spVisibilityInterpolator))
    {
        C630Blend* blend = (C630Blend*)m_spVisibilityInterpolator.m_pObject;
        blend->UpdateNormalizedWeights();
        unsigned char index = blend->FindHighestWeightIndex();
        if (index != DAT_01096968)
            activeBlendTime = blend->GetValueForIndex(index);
    }
    EmitterKeyInterpolator* emitterActive = GetObjectValueByKey();
    bool activeTimeSet = activeBlendTime != DAT_010241b0;
    float birthRateTime = DAT_01015f5c;
    if (NiObject_IsKindOf(&DAT_011f3e58, m_spControllerInterpolator))
    {
        C630Blend* blend = (C630Blend*)m_spControllerInterpolator.m_pObject;
        blend->UpdateNormalizedWeights();
        unsigned char index = blend->FindHighestWeightIndex();
        if (index != DAT_01096968)
            birthRateTime = blend->GetValueForIndex(index);
    }
    EmitterKeyInterpolator* rateInterp = NiPSysEmitterCtlr_GetBirthRateInterpolator();
    bool rateTimeSet = birthRateTime != DAT_010241b0;
    if (!emitterActive || !rateInterp)
        return;
    float newTime = m_fControllerTime;
    if (activeTimeSet || rateTimeSet)
        newTime = birthRateTime;
    if (Manager() && m_pEmitterActiveInterpolator != (NiInterpolator*)rateInterp)
    {
        m_fScaledLastTime = newTime;
        emitterActive->UpdateBool(newTime, m_pkTarget, m_bIsInitialized);
        m_pEmitterActiveInterpolator = (NiInterpolator*)rateInterp;
        return;
    }
    m_pEmitterActiveInterpolator = (NiInterpolator*)rateInterp;
    unsigned int activeCount, activeType;
    unsigned char boolKeySize;
    ActiveKey* emitterKeys = emitterActive->NiBoolInterpolator_GetKeys(activeCount, activeType, boolKeySize);
    if (!activeCount && !emitterActive->Posed(0))
        return;
    if (emitterActive->Posed(0))
    {
        bool activeInterp;
        emitterActive->UpdateBool(0.0f, m_pkTarget, activeInterp);
        if (activeInterp == 0)
            return;
        float oldTime = m_fScaledLastTime;
        float offset = ((C630Target*)m_pkTarget)->offset;
        m_fScaledLastTime = newTime;
        float rateValue;
        if (rateInterp->Posed(0))
        {
            float deltaTime;
            deltaTime = newTime - oldTime;
            if (newTime < oldTime)
            {
                oldTime = 0.0f;
                deltaTime = newTime;
            }
            if (!rateInterp->UpdateFloat(0.0f, m_pkTarget, rateValue))
                return;
            EmitParticlesInInterval(deltaTime + offset, newTime, oldTime, 0.0f, newTime, rateValue);
            return;
        }
        unsigned int rateCount, rateType;
        unsigned char ucRateSize;
        ActiveKey* birthKeys = rateInterp->NiFloatInterpolator_GetKeys_0(rateCount, rateType, ucRateSize);
        float rateBegin = birthKeys->time;
        float rateEnd = birthKeys->At(rateCount - 1, ucRateSize)->time;
        float deltaTime = 0.0f;
        if (oldTime > newTime)
        {
            double dDelta = rateEnd - oldTime;
            rateInterp->UpdateFloat((float)(dDelta * DAT_01011588 + oldTime), m_pkTarget, rateValue);
            deltaTime = (float)dDelta;
            EmitParticlesInInterval(offset + deltaTime, rateEnd, oldTime, rateBegin, rateEnd, rateValue);
            oldTime = birthKeys->time;
        }
        double dDelta = newTime - oldTime;
        rateInterp->UpdateFloat((float)(dDelta * DAT_01011588 + oldTime), m_pkTarget, rateValue);
        EmitParticlesInInterval((float)(offset + dDelta + deltaTime), newTime, oldTime, rateBegin, newTime, rateValue);
        return;
    }
    unsigned int uiLastIndex = 0;
    bool bActive;
    bActive = InterpolateBooleanKey(newTime, emitterKeys, activeType, activeCount, uiLastIndex, boolKeySize);
    if (m_fScaledLastTime == DAT_010241b0)
    {
        m_bIsInitialized = bActive;
        m_fScaledLastTime = newTime;
        return;
    }
    float oldTime = m_fScaledLastTime;
    bool bLastActive = m_bIsInitialized;
    m_bIsInitialized = bActive;
    m_fScaledLastTime = newTime;
    bool stopLoop = false;
    long iLoop = 0;
    while (!stopLoop && iLoop < 20)
    {
        bool isWrapped = false;
        if (oldTime > newTime)
            isWrapped = true;
        unsigned long beginIndex;
        if (bLastActive)
        {
            for (beginIndex = activeCount; beginIndex > 0; --beginIndex)
            {
                ActiveKey* pkActiveKey = emitterKeys->At(beginIndex - 1, boolKeySize);
                if (pkActiveKey->time <= oldTime && !pkActiveKey->value)
                    break;
            }
        }
        else
        {
            for (beginIndex = 0; beginIndex < activeCount; ++beginIndex)
            {
                ActiveKey* pkActiveKey;
                pkActiveKey = emitterKeys->At(beginIndex, boolKeySize);
                if (pkActiveKey->time > oldTime && (isWrapped || pkActiveKey->time <= newTime) && pkActiveKey->value)
                    break;
            }
            if (beginIndex == activeCount)
            {
                if (!isWrapped)
                    break;
                for (beginIndex = 0; beginIndex < activeCount; ++beginIndex)
                {
                    ActiveKey* pkActiveKey = emitterKeys->At(beginIndex, boolKeySize);
                    if (newTime > pkActiveKey->time && pkActiveKey->value)
                        break;
                }
                if (beginIndex == activeCount)
                    break;
            }
        }
        unsigned long uiEnd;
        for (uiEnd = beginIndex; uiEnd < activeCount; ++uiEnd)
        {
            if (!emitterKeys->At(uiEnd, boolKeySize)->value)
                break;
        }
        if (uiEnd == activeCount)
            --uiEnd;
        ActiveKey* pkBegin = emitterKeys->At(beginIndex, boolKeySize);
        ActiveKey* pkEnd = emitterKeys->At(uiEnd, boolKeySize);
        float fCurrentEnd, intervalStart, birthBegin, birthEnd;
        float rateValue;
        if (isWrapped)
        {
            if (oldTime < pkEnd->time)
            {
                fCurrentEnd = emitterKeys->At(activeCount - 1, boolKeySize)->time;
                intervalStart = oldTime;
                birthBegin = pkBegin->time;
                birthEnd = pkEnd->time;
                float fSampleTime = birthBegin + 0.5 * (birthEnd - birthBegin);
                rateInterp->UpdateFloat(fSampleTime, m_pkTarget, rateValue);
            }
            else
            {
                fCurrentEnd = newTime;
                intervalStart = emitterKeys->time;
                birthBegin = pkBegin->time;
                if (pkEnd->time < newTime)
                    birthEnd = pkEnd->time;
                else
                    birthEnd = newTime;
                float fSampleTime;
                fSampleTime = birthBegin + 0.5 * (birthEnd - birthBegin);
                rateInterp->UpdateFloat(fSampleTime, m_pkTarget, rateValue);
            }
        }
        else if (pkEnd->time < newTime)
        {
            fCurrentEnd = pkEnd->time;
            intervalStart = oldTime;
            birthBegin = pkBegin->time;
            birthEnd = pkEnd->time;
            float fSampleTime = birthBegin + 0.5 * (birthEnd - birthBegin);
            rateInterp->UpdateFloat(fSampleTime, m_pkTarget, rateValue);
        }
        else
        {
            fCurrentEnd = newTime;
            intervalStart = oldTime;
            birthBegin = pkBegin->time;
            birthEnd = pkEnd->time;
            rateInterp->UpdateFloat(newTime, m_pkTarget, rateValue);
        }
        float offset = ((C630Target*)m_pkTarget)->offset;
        if (isWrapped)
            offset = (m_fHiKeyTime - m_fLoKeyTime) + offset;
        EmitParticlesInInterval(offset + newTime - oldTime, fCurrentEnd, intervalStart, birthBegin, birthEnd,
                                rateValue);
        if (pkEnd->time < newTime)
        {
            oldTime = fCurrentEnd;
            bLastActive =
                InterpolateBooleanKey(oldTime, emitterKeys, activeType, activeCount, uiLastIndex, boolKeySize);
        }
        else
        {
            stopLoop = true;
        }
        ++iLoop;
    }
}
