// gamebryo2.2/corelibs/nianimation/nipoint3interpolator.cpp: NiPoint3Interpolator (24 functions)
#define FNV64_NIPOINTER_INLINE_BODIES
#include "NiRefObject_inline.h"

#include "../../../../include/Actor.h"
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/HUDMainMenu.h"
#include "../../../../include/ImageSpaceModifierInstanceDOF.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/NiPoint2.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3Interpolator.h"
#include <new>
#include "../../../../include/NiPointLight.h"
#include "../../../../include/NiPosData.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiStream.h"
#include "nipoint3interpolator_unit.h"

// Samples the interpolator's position data at the given time into m_kValue and returns whether the value differs from the default point.
// @fnv 0x00a49870
bool NiPoint3Interpolator::Update(float time, NiObjectNET* target, NiPoint3& value)
{
    if (m_fLastTime == time)
    {
        value = m_kValue;
        if (m_kValue.x != DAT_011a9424 || m_kValue.y != DAT_011a9428 || m_kValue.z != DAT_011a942c)
            return true;
        return false;
    }

    NiPosData* pData = m_spPosData;
    if (pData)
    {
        unsigned int numKeys = pData->m_uiNumKeys;
        NiAnimationKey::KeyType type = pData->m_eRequestType;
        unsigned char keySize = pData->m_ucKeyDataSize;
        PositionKeyInterpolator* keys = pData->m_pKeyArray;
        if (numKeys > 0)
        {
            m_kValue =
                PositionKeyInterpolator::InterpolatePosition(time, keys, type, numKeys, m_uiLastKeyIndex, keySize);
        }
    }

    if (m_kValue.x == DAT_011a9424 && m_kValue.y == DAT_011a9428 && m_kValue.z == DAT_011a942c)
        return false;

    value = m_kValue;
    m_fLastTime = time;
    return true;
}

#include "nipoint3interpolator_create.h"
#pragma optimize("", off)
// Switches on state (and force) to set up or tear down VATS objects, lights and player state, then updates the last-time field and HUD visibility.
// @fnv 0x009c6c30
void NiPoint3Interpolator::CreateObject(int state, bool force)
{
    if (state != reinterpret_cast<int&>(m_fLastTime) || force)
    {
        DAT_011f21f0 = g_thePlayer;
        switch (state)
        {
        case 3:
            state40 = 0;
            state44 = 0;
            if (!reinterpret_cast<VATS*>(&g_011f2250)->VATS_GetVATSLight())
            {
                NiPointLight* pPointLight = new NiPointLight;
                reinterpret_cast<VATS*>(&g_011f2250)->SetLight(pPointLight, true);
            }
            break;
        case 2:
            state40 = 0;
            state44 = 0;
            GetVATSEffect()->FOVATSEffectManager_DisableScan();
            if (!reinterpret_cast<VATS*>(&g_011f2250)->VATS_GetVATSLight())
            {
                NiPointLight* pPointLight = new NiPointLight;
                reinterpret_cast<VATS*>(&g_011f2250)->SetLight(pPointLight, true);
            }
            break;
        case 4:
            state40 = 0;
            state44 = 0;
            state3c = 0;
            DAT_011f21d4 = 0.0f;
            DAT_011f21d8 = 0.0f;
            DAT_011f21d2 = false;
            DAT_011f21e4 = false;
            if (state28)
            {
                ImageSpaceModifierInstance_Stop(state28);
                state28 = 0;
            }
            if (state2c)
            {
                ImageSpaceModifierInstance_Stop(state2c);
                state2c = 0;
            }
            state2c = ImageSpaceModifierInstanceRB_Trigger(0.0f, DAT_011ce564.Float()->f, DAT_011ce424.Float()->f, DAT_011cf1f8.Float()->f,
                                   DAT_011ce6d8.Float()->f, &NiPoint2(DAT_01016248, DAT_01016248), 0.0f);
            if (state2c)
                state2c->ImageSpaceModifierInstance_SetPermanent(true);
            break;
        case 0:
            if (DAT_011f21e8)
            {
                delete DAT_011f21e8;
                DAT_011f21e8 = 0;
            }
            if (DAT_011f21ec)
            {
                delete DAT_011f21ec;
                DAT_011f21ec = 0;
            }
            reinterpret_cast<GameTimerRecord*>(&g_timeGlobal)->SetGlobalTimeMultiplier(1.0f, true);
            DAT_011f21c0 = 0;
            DAT_011f21c4 = 0;
            DAT_011f21c8 = 0;
            if (state10)
                state10->ResetCameraState();
            DAT_011f21b8 = 0;
            state0c = 0;
            state10 = 0;
            state14 = 0.0f;
            state18 = 0.0f;
            state1c = 0;
            state20 = 0;
            DAT_011f21dc = 0;
            DAT_011f21d3 = false;
            if (state28)
            {
                ImageSpaceModifierInstance_Stop(state28);
                state28 = 0;
            }
            if (state2c)
            {
                ImageSpaceModifierInstance_Stop(state2c);
                state2c = 0;
            }
            state38 = true;
            g_thePlayer->SetAimingWeapon(false, false, false);
            g_thePlayer->CanStartCombat(false);
            g_osGlobals->Main_GetControls(6)->Controls_ClearUserAction();
            if (state40)
            {
                g_thePlayer->UnEquipObject(state40, 1, state44, false, true, true);
                state40 = 0;
                state44 = 0;
            }
            break;
        }
        BSShaderManager_SetFullScreenMotionBlurVATS(state == 2);
        reinterpret_cast<int&>(m_fLastTime) = state;
        if (reinterpret_cast<int&>(m_fLastTime) == 0)
        {
            HUDMainMenu::UpdateVisibilityState(1);
            DAT_011f21d0 = true;
        }
    }
    switch (state)
    {
    case 2:
    case 3:
        if (DAT_011f21cc)
            reinterpret_cast<VATS*>(&g_011f2250)->SetCurrentTarget(DAT_011f21cc);
        break;
    case 0:
        if (reinterpret_cast<VATS*>(&g_011f2250)->VATS_GetVATSLight())
        {
            reinterpret_cast<ExtraDataList*>(FUN_00450b80(0))
                ->Set3DObject(reinterpret_cast<VATS*>(&g_011f2250)->VATS_GetVATSLight()->ShadowSceneLight_GetLight());
            static_cast<NiNode*>(FUN_00450b80(0))->RemoveObject(reinterpret_cast<VATS*>(&g_011f2250)->VATS_GetVATSLight()->ShadowSceneLight_GetLight());
            reinterpret_cast<VATS*>(&g_011f2250)->SetLight(0, true);
        }
        break;
    }
}
#pragma optimize("", on)

// Loads the base interpolator and a NiColor from the stream, then reads a NiObject and stores it as a ref-counted member.
// @fnv 0x00a49530
void NiPoint3Interpolator::LoadBinary(NiStream& kStream)
{
    NiStream* pkStream = &kStream;
    NiKeyBasedInterpolator::LoadBinary(*pkStream);
    reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0x0c)->LoadBinary(*pkStream);
    NiObject* pkData = pkStream->DeserializeObject();
    NiObject*& rspData = *reinterpret_cast<NiObject**>(reinterpret_cast<char*>(this) + 0x18);
    if (rspData != pkData)
    {
        if (rspData)
            rspData->DecRefCount();
        rspData = pkData;
        if (pkData)
            pkData->IncRefCount();
    }
}

void __fastcall UpdateState_00a3ca30(void* pThis);

struct NiMemObject_Delete : public NiMemObject
{
    static void __cdecl operator delete(void* pvMem, size_t stElementSize);
};

// @fnv 0x00a49ae0
NiPoint3Interpolator* __fastcall FUN_00a49ae0(NiPoint3Interpolator* pThis, int, unsigned int uiFlags)
{
    NiPosData* pkData = *(NiPosData**)((char*)pThis + 0x18);
    if (pkData)
        pkData->DecRefCount();

    UpdateState_00a3ca30(pThis);

    if (uiFlags & 1)
        NiMemObject_Delete::operator delete(pThis, 0x20);

    return pThis;
}

// @fnv 0x00a49410
// src: GAMEBRYO_LIB 0x00a49410
void* __fastcall NiPoint3Interpolator_GetKeyCount(char* self, int, int)
{
    void* d = *(void**)(self + 0x18);
    if (!d)
        return 0;
    return *(void**)((char*)d + 8);
}

// @fnv 0x00a49420
// src: GAMEBRYO_LIB 0x00a49420
void* __fastcall NiPoint3Interpolator_GetKeyType(char* self, int, int)
{
    void* d = *(void**)(self + 0x18);
    if (!d)
        return 0;
    return *(void**)((char*)d + 0x10);
}

// @fnv 0x00a49430
// src: GAMEBRYO_LIB 0x00a49430
void* __fastcall NiPoint3Interpolator_GetKeyArray(char* self, int, int)
{
    void* d = *(void**)(self + 0x18);
    if (!d)
        return 0;
    return *(void**)((char*)d + 0xc);
}

// @fnv 0x00a49440
// src: GAMEBRYO_LIB 0x00a49440
unsigned char __fastcall NiPoint3Interpolator_GetKeyStride(char* self, int, int)
{
    void* d = *(void**)(self + 0x18);
    if (!d)
        return 0;
    return *((unsigned char*)d + 0x14);
}

struct HC1Base
{
    bool BSPackedAdditionalGeometryData_RegisterStreamables(NiStream*);
};
struct HC1Data
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
    virtual void RegisterStreamables(NiStream&);
};

// Calls FUN_00aa0ad0 on this as HC1Base; if it succeeds, registers the HC1Data at offset 0x18 with the stream and returns true.
// @fnv 0x00a49590
bool NiPoint3Interpolator::RegisterStreamables(NiStream& stream)
{
    NiStream* kStream = &stream;
    if (!reinterpret_cast<HC1Base*>(this)->BSPackedAdditionalGeometryData_RegisterStreamables(kStream))
        return false;
    HC1Data* d = *reinterpret_cast<HC1Data**>(reinterpret_cast<char*>(this) + 0x18);
    if (d)
        d->RegisterStreamables(*kStream);
    return true;
}

struct FUN_00a95ca0_helper
{
    void NiKeyBasedInterpolator_LinkObject(NiStream*);
};
// @fnv 0x00a495c0
void NiPoint3Interpolator::SaveBinary(NiStream& kStream)
{
    NiStream* stream = &kStream;
    ((FUN_00a95ca0_helper*)this)->NiKeyBasedInterpolator_LinkObject(stream);
    reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0xc)->SaveBinary(*stream);
    stream->SaveLinkID(reinterpret_cast<const NiObject*>(*(void**)((char*)this + 0x18)));
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3f70;
// @fnv 0x00a49640
// src: COMMUNITY 0x00a49640
GlobalObjectO2_00a7b610* NiPoint3Interpolator_GetRTTI()
{
    return &g_011f3f70;
}

extern float DAT_011a9424;
extern float DAT_011a9428;
extern float DAT_011a942c;

// @fnv 0x00a49460
// src: GAMEBRYO_LIB 0x00a49460
bool __fastcall NiPoint3Interpolator_GetChannelPosed(NiPoint3Interpolator* self, int, unsigned short channel)
{
    if (*(int*)((char*)self + 0x18))
        return false;
    if (*(float*)((char*)self + 0x0c) != DAT_011a9424 || *(float*)((char*)self + 0x10) != DAT_011a9428 ||
        *(float*)((char*)self + 0x14) != DAT_011a942c)
        return true;
    return false;
}

struct FUN_00a48f70_shell
{
    void FUN_00a48f70(float m_fStartTime, float m_fMaximumDistance);
};
// Retrieves the object stored at offset 0x18 and, if non-null, forwards the two float arguments to its FUN_00a48f70 method.
// @fnv 0x00a49500
void NiPoint3Interpolator::SetActiveTimeRange(float afArg1, float afArg2)
{
    FUN_00a48f70_shell* p = *(FUN_00a48f70_shell**)((char*)this + 0x18);
    if (p)
        p->FUN_00a48f70(afArg1, afArg2);
}

struct RefObj00
{
    virtual void F0();
    virtual void F1();
    long ref;
};
// @fnv 0x00a494b0
// src: XBOX_PDB 0x00a494b0
void NiPoint3Interpolator::SetPoseValue(NiPoint3 aVec)
{
    RefObj00* pRef = reinterpret_cast<RefObj00*>(m_spPosData);
    if (pRef)
    {
        if (InterlockedDecrement(&pRef->ref) == 0)
            pRef->F1();
        m_spPosData = 0;
    }
    m_kValue = aVec;
}

extern const NiPoint3 g_kA495F0InvalidPoint;

// @fnv 0x00a495f0
NiPoint3Interpolator::NiPoint3Interpolator(NiPosData* pkPosData)
    : m_kValue(g_kA495F0InvalidPoint)
{
    m_spPosData = pkPosData;
    if (pkPosData)
        pkPosData->IncRefCount();
    m_uiLastKeyIndex = 0;
}

struct NiPosDataRangeHelper : NiPosData
{
    void FUN_00a49140(float startTime, float endTime, NiPosData*& result);
};
NiPoint3Interpolator* __stdcall NiInterpolator_GetSequenceInterpolator(float startTime, float endTime);

inline void AssignPosData(NiPosData*& destination, NiPosData* nextData)
{
    NiPosData* oldData = destination;
    if (oldData != nextData)
    {
        if (oldData)
            oldData->DecRefCount();
        destination = nextData;
        if (nextData)
            nextData->IncRefCount();
    }
}

// Creates a point3 interpolator for the given time range and copies the extracted position data from m_spPosData into it.
// @fnv 0x00a497b0
NiPoint3Interpolator* NiPoint3Interpolator::CreateRangeInterpolator(float startTime, float endTime)
{
    NiPoint3Interpolator* result = NiInterpolator_GetSequenceInterpolator(startTime, endTime);
    if (m_spPosData)
    {
        NiPosData* extractedData = 0;
        static_cast<NiPosDataRangeHelper*>(m_spPosData)->FUN_00a49140(startTime, endTime, extractedData);
        AssignPosData(result->m_spPosData, extractedData);
        result->m_uiLastKeyIndex = 0;
        if (extractedData)
            extractedData->DecRefCount();
    }
    return result;
}

class InterpolatorCloning : public NiInterpolator
{
  public:

    void CopyMemberData(InterpolatorCloning* pkDest, CloningProcess& kCloning);
};

// @fnv 0x00a499a0
void NiPoint3Interpolator::CloneTo(NiPoint3Interpolator* pkDest, CloningProcess& kCloning)
{
    reinterpret_cast<InterpolatorCloning*>(this)->CopyMemberData(reinterpret_cast<InterpolatorCloning*>(pkDest), kCloning);
    pkDest->m_kValue = m_kValue;
    reinterpret_cast<NiPointer<NiRefObject>&>(pkDest->m_spPosData) = reinterpret_cast<NiPointer<NiRefObject>&>(m_spPosData);
    pkDest->m_uiLastKeyIndex = m_uiLastKeyIndex;
}

extern "C" float DAT_011a9424;

inline NiPoint3Interpolator::NiPoint3Interpolator() throw()
: m_kValue(reinterpret_cast<const NiPoint3&>(DAT_011a9424))
{
    m_spPosData = 0;
    // Keep VC9's stores ordered as in the original smart-pointer constructor.
    reinterpret_cast<unsigned int volatile&>(m_uiLastKeyIndex) = 0;
}

// @fnv 0x00a49b30
// src: XBOX_PDB 0x00a49b30
NiPoint3Interpolator* NiPoint3Interpolator::CreateClone_00a49b30(void* pvCloning)
{
    // The original point3 allocation is 0x20 bytes; the shared union also describes VATS state.
    NiPoint3Interpolator* pkClone = ::new (NiPoint3Interpolator::operator new(0x20)) NiPoint3Interpolator;
    CopyMemberData(pkClone, pvCloning);
    return pkClone;
}

struct StrArrList
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short cap;
    unsigned short count;
    unsigned short unkC;
    unsigned short growBy;
    void Grow(unsigned int newCount);
    void SetAt(unsigned int index, unsigned int* value);
};

struct Sub0cHelper
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int GetViewerString_00a59af0(const char* name);
};

extern "C" unsigned int DAT_011f3f70;
unsigned int __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
unsigned int __cdecl NiGetViewerString_00a7d5a0(const char* name, unsigned int v);

// The shared base does not declare its viewer-string helper.
struct InterpolatorViewerHelper
{
    void GetViewerStrings(StrArrList*);
};

// @fnv 0x00a49bb0
void NiPoint3Interpolator::GetViewerStrings(NiViewerStringsArray* strings)
{
    StrArrList* list = reinterpret_cast<StrArrList*>(strings);
    unsigned int value;

    reinterpret_cast<InterpolatorViewerHelper*>(this)->GetViewerStrings(list);
    value = NiViewerStrings_NiGetViewerString_Title(DAT_011f3f70);
    {
        unsigned int count = list->count;
        if (count >= list->cap)
        {
            list->Grow(count + list->growBy);
        }
        list->SetAt(count, &value);
    }

    value = reinterpret_cast<Sub0cHelper*>(&m_kValue)->GetViewerString_00a59af0("m_kPoint3Value");
    {
        unsigned int count = list->count;
        if (count >= list->cap)
        {
            list->Grow(count + list->growBy);
        }
        list->SetAt(count, &value);
    }

    unsigned int v18 = reinterpret_cast<unsigned int>(m_spPosData);
    value = NiGetViewerString_00a7d5a0("m_spPoint3Data", v18);
    {
        unsigned int count = list->count;
        if (count >= list->cap)
        {
            list->Grow(count + list->growBy);
        }
        list->SetAt(count, &value);
    }
}

// @fnv 0x00d46c90
// src: GUESS 0x00d46c90 (confidence: high)
unsigned int __stdcall NiPoint3Interpolator_ReturnOne(unsigned int a1)
{
    return 1;
}

// @fnv 0x00a49650
NiPoint3Interpolator::NiPoint3Interpolator(NiPoint3 kPoseValue) throw()
    : m_kValue(kPoseValue)
{
    // Keep VC9's stores ordered as in the original smart-pointer constructor.
    reinterpret_cast<NiPosData* volatile&>(m_spPosData) = 0;
    m_uiLastKeyIndex = 0;
}

struct PosKeyValue496
{
    float m_fTime;
    NiPoint3 m_kPos;
};

__forceinline void ClearPosData(NiPosData*& rpkData)
{
    if (rpkData != 0)
    {
        if (rpkData)
            rpkData->DecRefCount();
        rpkData = 0;
    }
}

struct PosDataView496 : NiPosData
{
    __forceinline PositionKeyInterpolator* ComputePositionAtTime(unsigned int& uiNumKeys, NiAnimationKey::KeyType& eType,
                                                                 unsigned char& ucSize) const
    {
        uiNumKeys = m_uiNumKeys;
        eType = m_eRequestType;
        ucSize = m_ucKeyDataSize;
        return m_pKeyArray;
    }
};

// If the position data has zero keys, clears it and resets m_kValue; if all keys share one value, clears the data and stores that value in m_kValue.
// @fnv 0x00a49690
void NiPoint3Interpolator::CollapseConstantPosData()
{
    NiPosData* pkData = m_spPosData;
    if (!pkData)
        return;

    unsigned int uiNumKeys;
    NiAnimationKey::KeyType eType;
    unsigned char ucSize;
    PositionKeyInterpolator* pkKeys = ((PosDataView496*)pkData)->ComputePositionAtTime(uiNumKeys, eType, ucSize);

    if (uiNumKeys == 0)
    {
        ClearPosData(m_spPosData);
        m_kValue = reinterpret_cast<const NiPoint3&>(DAT_011a9424);
        return;
    }
    else
    {
        NiPoint3 kValue = (NiPoint3&)((PosKeyValue496*)pkKeys)->m_kPos;
        if (uiNumKeys != 1)
        {
            if (eType != NiAnimationKey::LINKEY && eType != NiAnimationKey::STEPKEY)
                return;
            bool bAllEqual = true;
            for (unsigned int i = 1; bAllEqual && i < uiNumKeys; i++)
            {
                if (((PosKeyValue496*)((char*)pkKeys + ucSize * i))->m_kPos.operator!=(kValue))
                    bAllEqual = false;
            }
            if (!bAllEqual)
                return;
        }

        ClearPosData(m_spPosData);
        m_kValue = kValue;
    }
}

// Allocates and returns a point3 interpolator.
// @fnv 0x00a49a30
// src: EXE 0x00a49a30
NiPoint3Interpolator* __cdecl NiPoint3Interpolator_CreateObject()
{
    return ::new (NiPoint3Interpolator::operator new(0x20)) NiPoint3Interpolator();
}

struct InterpolatorComparisonBase
{
    bool IsEqual(NiObject*);
};

// @fnv 0x00a49a80
bool NiPoint3Interpolator::IsEqual(NiObject* object) const
{
    NiPoint3Interpolator* other = static_cast<NiPoint3Interpolator*>(object);
    if (!reinterpret_cast<InterpolatorComparisonBase*>(const_cast<NiPoint3Interpolator*>(this))->IsEqual(other))
        return false;
    if (const_cast<NiPoint3&>(m_kValue).operator!=(other->m_kValue))
        return false;
    if ((m_spPosData != 0 && other->m_spPosData == 0) || (m_spPosData == 0 && other->m_spPosData != 0))
        return false;
    NiPosData* pPosData = m_spPosData;
    if (pPosData != 0)
    {
        NiPosData* pOtherPosData = other->m_spPosData;
        if (!pPosData->IsEqual(pOtherPosData))
            return false;
    }
    return true;
}
