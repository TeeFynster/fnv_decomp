// fallout/ai/movement/actormover.cpp: ActorMover, MobileObject and pathing helpers (79 functions)

#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/Actor.h"
#include "../../../../include/ActorMover.h"
#include "../../../../include/ActorPathHandler.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/ActorPathingMessageQueue.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/GameSettingCollection.h"
#include "../../../../include/BSAnimGroupSequence.h"
#include "../../../../include/LowProcess.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PathingRequest.h"
// PathActor_actormover: local type (was include/PathActor.h, which had no evidence of one real class); its methods are 0x00575d70 TESObjectREFR::GetWorldSpace, 0x0057b0a0 TESObjectREFR::GetRelevantWaterHeight, 0x005c3420 PathingLocation::GetLocation, 0x006dd6a0 PathingLocation::HasNavMeshData
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PathNode.h"

class PathPoint;

class PathActor_actormover
{
public:
    int Exists();
    void Stop(int);
    void Prepare(int aiFlag);
    bool IsDone();
    NiPoint3 GetPosition();
    bool IsWithinProcThreshold();
    bool FUN_008b3bb0();
    float TESObjectREFR_GetRelevantWaterHeight();
    void* TESObjectREFR_GetWorldSpace();
    void* FUN_008d6f30();
    void PathToLocation(PathingRequest*, PathPoint*, void*, void*, float, int);
    void SetPathingRequestAvoidNodes(PathingRequest*);
    void StopMoving_008b3ab0();
    void UpdatePathing(PathActor_actormover* actor);
};
#include "../../../../include/PathingLocation.h"
#include "../../../../include/PathingRequestLOS.h"
#include "../../../../include/PathingSolution.h"
#include "../../../../include/PathingGraphNode.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TES.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/NiPoint3.h"

#include <string.h>
#pragma intrinsic(memcpy)

// NiPointer<void> is only used as an opaque reference; its primary template forms void&.
template <> class NiPointer<void>;

// The shared declaration lacks the boolean flag getter at 0x006b05d0.
bool __fastcall GetPathingSolutionFlag40(PathingSolution* solution);

#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/PlayerCharacter.h"

extern "C" const NiPoint3 NiPoint3_ZERO;

// @fnv 0x008b3d10
bool ActorMover::HasLookAtTarget()
{
    return m_bHasLookAtTarget;
}
// @fnv 0x009ddb50
bool ActorMover::IsMovementActive()
{
    return eState == 4;
}
// @fnv 0x009de080
void ActorMover::ResetMovementData()
{
    m_bHasMovementData = false;
    m_uiMovementFlags = 0;
}

// @fnv 0x009dd0a0
void ActorMover::StopMoving()
{
    ClearMovementPath();
    RefreshMovementState();
}

// @fnv 0x00931850
unsigned int MobileObject::GetCurrentProcessLevel()
{
    if (m_pBaseProcess)
        return m_pBaseProcess->GetProcessLevel();
    return PROCESS_TYPE_PROCESS_TYPE_NONE;
}
// Returns the preferred move mode type when pathing failed, otherwise returns the stored move mode.
// @fnv 0x009ddb70
unsigned int ActorMover::GetActorStateFlags()
{
    unsigned int uiMoveMode = bPathingFailed ? GetPreferredMoveModeType() : m_uiMovementMode;
    return uiMoveMode;
}
// @fnv 0x009de230
void ActorMover::RunProcedure()
{
    memcpy(&m_kLookAtTargetPosition, &NiPoint3_ZERO, sizeof(NiPoint3));
    m_bHasLookAtTarget = false;
    RefreshMovementState();
}
// @fnv 0x009dc590
void ActorMover::UpdateMovement(float elapsed)
{
    if (m_bMovementPaused)
        return;
    ActorPathHandler::PATH_HANDLER_RESULT result = m_pPathHandler->vfn_0c(elapsed);
    HandlePathingResult(result);
}
// @fnv 0x009ddbb0
bool ActorMover::GetPathingDelta(NiPoint3& delta)
{
    bool valid = false;
    if (m_bHasPathingDelta)
    {
        m_bHasPathingDelta = false;
        memcpy(&delta, &m_kPathingDelta, sizeof(NiPoint3));
        valid = true;
    }
    return valid;
}
// @fnv 0x009dd150
void ActorMover::ClearMovementPath()
{
    if (eState != 6)
    {
        if (m_pPathHandler && !m_pPathHandler->vfn_34())
            eState = 6;
        m_bMovementComplete = true;
    }
    if (bPathingFailed)
        m_bMovementComplete = true;
    UpdateMovementStatus(false);
}
// @fnv 0x009dcdb0
bool ActorMover::HasActiveMovement()
{
    if (m_bHasMovementData)
        return false;
    if (eState == 4)
        return true;
    if (m_bMovementActive)
        return true;
    if (!m_pActorNode.operator->() || !m_pActorNode->PathingSolution_IsValid() || bPathingFailed)
        return false;
    return true;
}

// New bodies are reconstructed from the complete supplied PC instruction spans.
// @fnv 0x009dd0c0
void ActorMover::ForceStopMoving()
{
    ClearMovementPath();
    if (m_bMovementComplete)
    {
        m_bMovementComplete = false;
        SetMovementMode(true);
        m_uiMovementMode = GetPreferredMoveModeType();
        memcpy(&m_kPathingDelta, &NiPoint3_ZERO, sizeof(NiPoint3));
        m_bHasPathingDelta = true;
    }
    DebugOnStopMoving();
}

class TESSound;
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BSOcclusionPlane.h"
#include "../../../../include/PathingActorData.h"
#include "../../../../include/CombatController.h"
#include "../../../../include/TESPackage.h"
#include "../../../../include/TESObjectMISC.h"
#include "../../../../include/NiPoint3.h"

// @fnv 0x009db930
void TESObjectMISC::SetLoopingSound(TESSound* sound)
{
    *(TESSound**)((char*)this + 0xa8) = sound;
}

struct FUN_0040e130
{
    FUN_0040e130(int, float);
    ~FUN_0040e130();
    virtual void vfn_0();
};
struct FUN_0040e0b0 : public FUN_0040e130
{
    FUN_0040e0b0(int a, float b);
};
// @fnv 0x0040e0b0
FUN_0040e0b0::FUN_0040e0b0(int a, float b) : FUN_0040e130(a, b)
{
    GameSettingCollection::Instance()->v1(this);
}

// @fnv 0x009daf80
// src: XBOX_PDB 0x009daf80
void __fastcall ActorMover_ClearCurrentData(TESForm* pForm)
{
    *(int*)((char*)pForm + 0x6c) = 6;
    ((NiPointer<PathingRequest>*)((char*)pForm + 0x1c))->operator=(0);
    ((NiPointer<NiNode>*)((char*)pForm + 0x20))->operator=(0);
    if (*(ActorPathHandler**)((char*)pForm + 0x24) != 0)
    {
        delete *(ActorPathHandler**)((char*)pForm + 0x24);
        *(ActorPathHandler**)((char*)pForm + 0x24) = 0;
    }
    if (*(unsigned char*)((char*)pForm + 0x74) != 0)
    {
        ((NiPointer<ActorPathingMessageQueue>*)((char*)pForm + 0x30))->operator=(new ActorPathingMessageQueue);
        *(unsigned char*)((char*)pForm + 0x74) = 0;
    }
    ((ActorMover*)pForm)->ResetMovementData();
    pForm->TESForm::ClearData();
}

// @fnv 0x009dba30
// src: XBOX_PDB 0x009dba30
bool ActorMover::SetGoal(const PathingRequest* apRequest)
{
    return BackGroundBuildPath(apRequest);
}

struct ArrHelper
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() const;
};

// @fnv 0x009dc530
// src: COMMUNITY 0x009dc530
bool ActorMover::PathingSolution_IsValid()
{
    if (((ArrHelper*)((char*)this + 8))->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        return false;
    if (*(int*)((char*)this + 0x18) != -1 && *(int*)((char*)this + 0x1c) != -1 &&
        ((ArrHelper*)((char*)this + 0x20))->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        return false;
    if (GetPathingSolutionFlag40((PathingSolution*)this))
        return true;
    return true;
}

struct FUN_009dc950_Arg
{
    int val;
};

// If pThis->m_pPathHandler is set, calls its vtable slot v5c with a1.val.
// @fnv 0x009dc950
void __fastcall ForwardValueToVtbl(ActorMover* pThis, FUN_009dc950_Arg aArg)
{
    if (pThis->m_pPathHandler)
    {
        pThis->m_pPathHandler->vf23(aArg.val);
    }
}

extern PlayerCharacter* pPlayer;

// @fnv 0x009dcae0
// src: XBOX_PDB 0x009dcae0
bool __fastcall ActorMover_IsActorInLoadedArea(ActorMover* pMover)
{
    if (!((BSOcclusionPlane*)pMover->pActor)->GetCullResult() ||
        !reinterpret_cast<TESObjectCELL*>(((BSOcclusionPlane*)pMover->pActor)->GetCullResult())->IsOutdoorCell() ||
        pPlayer->IsSleepingOrResting())
    {
        return false;
    }
    return true;
}

// @fnv 0x009dcd40
// src: XBOX_PDB 0x009dcd40
bool ActorMover::IsPathingComplete()
{
    if (m_bMovementActive)
    {
        return false;
    }
    else if (eState == 6 || eState == 7)
    {
        return true;
    }
    else if (((NiNode*)m_pActorNode &&
              ((NiNode*)(NiNode*)m_pActorNode)->PathingSolution_IsValid()) ||
             eState == 4)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// @fnv 0x009dd130
// src: XBOX_PDB 0x009dd130
unsigned int ActorMover::GetPreferredMoveModeType_009dd130()
{
    return unk34 & 0xff00;
}

// @fnv 0x009dd1c0
// src: XBOX_PDB 0x009dd1c0
void ActorMover::FinishMoving(bool abClearHandler)
{
    switch (eState)
    {
    case 7:
    case 8:
        break;
    default:
        eState = 6;
        break;
    }

    request.operator=(0);
    m_pActorNode.operator=(0);

    if (m_pPathHandler && abClearHandler)
        m_pPathHandler->vf28();

    if (m_bMovementActive)
    {
        m_queue = new ActorPathingMessageQueue;
        m_bMovementActive = false;
    }

    UpdateMovementStatus(false);
    ((TESForm*)this)->TESForm::ClearData();
}

void* __cdecl operator new(unsigned int);
void* __fastcall FUN_009dff40(void*, int, void*, void*);

struct Dummy_0xe4
{
    char pad[0xe4];
    Dummy_0xe4(void* a, void* b)
    {
        FUN_009dff40(this, 0, a, b);
    }
};

// Stores the high byte of auiPreferredMoveMode into bits 8-15 of the field at offset 0x34, lazily creating the object at 0x24, and the low nibble into bits 0-3.
// @fnv 0x009ddf60
void ActorMover::SetMoveModeFlags(unsigned int auiPreferredMoveMode)
{
    if (auiPreferredMoveMode & 0xff00)
    {
        if (*(void**)((char*)this + 0x24) == 0)
        {
            *(void**)((char*)this + 0x24) = new Dummy_0xe4(*(void**)((char*)this + 0x28), this);
        }
        unk34 =
            (unk34 & 0xf) | (auiPreferredMoveMode & 0xff00);
    }
    if (auiPreferredMoveMode & 0xf)
    {
        unk34 =
            (auiPreferredMoveMode & 0xf) | (unk34 & 0xff00);
    }
}

class NiMatrix3;
class NiQuaternion;
class hkVector4;
namespace fnv_009dfa00 {
struct SaveLoadFile;

struct blob4
{
    char b[4];
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
using ::NiMemObject;
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

class PathManager
{
  public:
    static PathManager* __cdecl GetRandomGenerator();
    bool BuildPath(NiPointer<PathingRequest>, NiPointer<ActorPathingMessageQueue>, bool);
};

} // namespace fnv_009dfa00

// @fnv 0x009dfa00
// src: XBOX_PDB 0x009dfa00
void ActorMover::FinishLoadGame_009dfa00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    using namespace fnv_009dfa00;
    if (m_bMovementActive && *(NiPointer<PathingRequest>*)((char*)this + 0x1c))
    {
        bool bforceFail = false;
        if ((*(NiPointer<PathingRequest>*)((char*)this + 0x1c))->GetType() == 5)
        {
            PathingRequestLOS* plosRequest =
                (PathingRequestLOS*)(PathingRequest*)*(NiPointer<PathingRequest>*)((char*)this + 0x1c);
            if (!plosRequest->GetLOSActor())
                bforceFail = true;
        }
        if (!*(NiPointer<ActorPathingMessageQueue>*)((char*)this + 0x30))
            *(NiPointer<ActorPathingMessageQueue>*)((char*)this + 0x30) = new ActorPathingMessageQueue();
        if (bforceFail ||
            !PathManager::GetRandomGenerator()->BuildPath(*(NiPointer<PathingRequest>*)((char*)this + 0x1c),
                                                 *(NiPointer<ActorPathingMessageQueue>*)((char*)this + 0x30), true))
        {
            UpdateMovementStatus(true);
            m_bMovementActive = false;
        }
    }
}

void __cdecl Deallocate(void*);
namespace p07 {

// Calls the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
} // namespace p07

// @fnv 0x009daec0
void* ActorMover::DestroyIfFlagged(unsigned int flags)
{
    using namespace p07;
    this->~ActorMover();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace p07 {

float __cdecl GetDirectionAngle(const NiPoint3&);

} // namespace p07

// @fnv 0x009dce20
// src: XBOX_PDB 0x009dce20
void* ActorMover::RequestRotateActor(NiPoint3 aPoint, bool abFlag)
{
    using namespace p07;
    NiPoint3 kDelta = aPoint - *static_cast<const Actor*>(pActor)->GetPos();
    {
        float fDistance = GetDirectionAngle(kDelta);
        return (this->*reinterpret_cast<void* (ActorMover::*)(float, bool)>(&ActorMover::RequestRotateActor_009dce80))(fDistance, abFlag);
    }
}

namespace fnv_009de420 {

// Returns true if the Flt at offset 0x20 is non-zero and its PathingSolution FUN_006b05d0 check succeeds; otherwise false.
} // namespace fnv_009de420

// @fnv 0x009de420
bool ActorMover::HasPathingSolution()
{
    using namespace fnv_009de420;
    if ((NiNode*)m_pActorNode &&
        GetPathingSolutionFlag40((PathingSolution*)(unsigned int)(NiNode*)m_pActorNode))
        return true;
    return false;
}

// @fnv 0x009daef0
ActorMover::~ActorMover()
{
    ::ActorMover_ClearCurrentData((TESForm*)this);
}

// @fnv 0x009db950
void ActorMover::ResetMoverState(bool clearWaiting)
{
    m_bMovementComplete = false;
    ResetMovementData();
    request = (PathingRequest*)0;
    if (m_bMovementActive)
    {
        m_queue = new ActorPathingMessageQueue();
        if (clearWaiting)
            m_bMovementActive = false;
    }
    m_pActorNode = (NiNode*)0;
    UpdateMovementStatus(false);
    ((TESForm*)this)->TESForm::ClearData();
}

struct PathingRequestHelper
{
    int data[0x2a];
    PathingRequestHelper();
    virtual ~PathingRequestHelper();
};

void __cdecl SetupPathingRequest(void* actor, PathingRequestHelper* request, int a, int b, int c, float d, int e);
// Builds a PathingRequestHelper via SetupPathingRequest from pActor and the given arguments, then returns the result of FUN_009dba30 on it.
// @fnv 0x009dba50
// src: XBOX_PDB 0x009dba50
bool ActorMover::SetGoal_009dba50(int aiArg1, int aiArg2, int aiArg3, float afArg4, int aiArg5)
{
    PathingRequestHelper request;
    SetupPathingRequest(pActor, &request, aiArg1, aiArg2, aiArg3, afArg4, aiArg5);
    return SetGoal((PathingRequest*)&request);
}

namespace fnv_009dbb60 {
struct PathingRequestHelper
{
    int data[0x2a];
    PathingRequestHelper();
    void SetTargetAngle(float f);
    virtual ~PathingRequestHelper();
};

void __cdecl SetupPathingRequest(void* actor, PathingRequestHelper* request, int a, int b, int c, float e, int f);
} // namespace fnv_009dbb60

// @fnv 0x009dbb60
// src: COMMUNITY 0x009dbb60
bool ActorMover::SetGoalAndAngle(int aiArg1, int aiArg2, int aiArg3, float afValue, float afArg4, int aiArg5)
{
    using namespace fnv_009dbb60;
    fnv_009dbb60::PathingRequestHelper request;
    SetupPathingRequest(pActor, &request, aiArg1, aiArg2, aiArg3, afArg4, aiArg5);
    request.SetTargetAngle(afValue);
    return SetGoal((PathingRequest*)&request);
}

namespace fnv_00564db0 {

// Exe 0x00564db0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct ActormoverOffset08View
{
    unsigned int GetFlags();
};

struct FUN_00564db0_cls
{
    void TESObjectREFR_SetTargeted(bool abVal);
};

// @fnv 0x00564db0
// src: XBOX_PDB 0x00564db0
void __thiscall FUN_00564db0_cls::TESObjectREFR_SetTargeted(bool abVal)
{
    int iflags = ((ActormoverOffset08View*)this)->GetFlags();
    if (abVal)
        iflags |= 0x40000;
    else
        iflags &= 0xfffbffff;
    ((TESObjectREFR*)this)->SetFlags(iflags);
}
}  // namespace fnv_00564db0

struct TypeValueCount
{
    int iType;
    float fValue;
    int iCount;
};
unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
struct FUN_00691c90_shell
{
    virtual ~FUN_00691c90_shell();
    TypeValueCount* pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;
    void BSSimpleArray_RemoveFast_0(unsigned int auiIndex, unsigned int auiCount);
    void FUN_0072ba80(TypeValueCount*, unsigned int);
    void BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(TypeValueCount*, TypeValueCount*, unsigned int);
};
// @fnv 0x00691c90
// src: COMMUNITY 0x00691c90
void FUN_00691c90_shell::BSSimpleArray_RemoveFast_0(unsigned int auiIndex, unsigned int auiCount)
{
    unsigned int uiMoveCount = FUN_0042f5a0(iSize - auiIndex - auiCount, auiCount);
    FUN_0072ba80(&pBuffer[auiIndex], auiCount);
    BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(&pBuffer[auiIndex], pBuffer + iSize - uiMoveCount, uiMoveCount);
    iSize -= auiCount;
}

struct FUN_006d3ae0
{
    void SetValue(float value);
};

// @fnv 0x006d3ae0
void FUN_006d3ae0::SetValue(float value)
{
    *(float*)((char*)this + 0x68) = value;
}

// @fnv 0x009de060
// src: XBOX_PDB 0x009de060
void ActorMover::ForceMoveMode(int aiValue)
{
    m_bHasMovementData = true;
    m_uiMovementFlags = aiValue;
}

namespace fnv_009de160 {

struct ActorAvoidListNode
{
    Actor* pItem;
    ActorAvoidListNode* pNext;
};
struct Dummy_0xe4 : ActorPathHandler
{
    Dummy_0xe4(void* apActor, void* apMover);
    float m_fFirstPathingScalar;
    float m_fSecondPathingScalar;
    NiPoint3 m_kPathVector1;
    NiPoint3 m_kPathVector2;
    NiPoint3 m_kPathVector3;
    NiPoint3 m_kActorPosition;
    NiPoint3 m_kPathVector4;
    ActorAvoidListNode ActorAvoidEntryList;
    unsigned int ByteAndFlagState;
    unsigned int m_uiPathPointIndex;
    float m_fPathValue1;
    float m_fPathValue2;
    float m_fSplineParameter;
    float m_fPathValue4;
    float m_fPathValue5;
    int m_iPathValue1;
    float m_fPathValue6;
    float m_fPathValue7;
    float m_fPathValue8;
    float m_fPathValue9;
    float m_fPathValue10;
    float m_fPathValue11;
    float m_fPathValue12;
    float m_fPathValue13;
    NiPoint3 m_kPathVector5;
    float m_fPathValue14;
    float m_fPathValue15;
    float m_fPathValue16;
    float m_fPathValue17;
    float m_fPathValue18;
    bool m_bHasPathingSolution;
    bool m_bPathingRequestPending;
    float m_fElapsedTime;
    int eState;
    int m_iPathParameter1;
    int m_iPathParameter2;
    int m_iPathValue2;
    TESObjectREFR* m_pPathTargetReference;
    bool m_bPathFlag1;
    bool m_bPathFlag2;
    float fDoorWaitTime;
};

} // namespace fnv_009de160

// @fnv 0x009de160
void ActorMover::SetMoveTarget(NiPoint3 aTarget)
{
    using namespace fnv_009de160;
    memcpy(&m_kLookAtTargetPosition, &aTarget, sizeof(NiPoint3));
    m_bHasLookAtTarget = true;
    if (((MobileObject*)pActor)->GetCurrentProcessLevel())
        return;
    if (!m_pPathHandler)
        m_pPathHandler = new fnv_009de160::Dummy_0xe4(pActor, this);
    ((TESForm*)this)->TESForm::ClearData();
}

struct FUN_009deff0_Class
{
    void SetFlagA3(bool b);
};
// @fnv 0x009deff0
void FUN_009deff0_Class::SetFlagA3(bool abValue)
{
    ((char*)this)[0xa3] = abValue;
}

namespace fnv_009dfb80 {

extern NiPoint3 _NiPoint3_ZERO;

} // namespace fnv_009dfb80

// @fnv 0x009dfb80
void ActorMover::ResetPathingState(BGSLoadFormBuffer* apLoadGameBuffer)
{
    using namespace fnv_009dfb80;
    if (m_bMovementActive)
        m_queue = new ActorPathingMessageQueue;
    eState = 0;
    request = (PathingRequest*)0;
    m_pActorNode = (NiNode*)0;
    delete m_pPathHandler;
    m_pPathHandler = 0;
    unk34 = 0x101;
    UpdateMovementStatus(false);
    currentNode = 0xffff;
    lastNode = 0xffff;
    m_bMovementStateFlag = false;
    m_bMovementComplete = false;
    m_bMovementActive = false;
    m_bMovementPaused = false;
    memcpy(&m_kLookAtTargetPosition, &_NiPoint3_ZERO, sizeof(NiPoint3));
    memcpy(&m_kPathingDelta, &_NiPoint3_ZERO, sizeof(NiPoint3));
    m_bHasLookAtTarget = false;
    m_bHasMovementData = false;
    unk78 = false;
    m_bHasPathingDelta = false;
    m_uiMovementFlags = 0;
    m_uiMovementMode = 0;
    unk2C = 0;
    retries = 0;
    lastTime = 0;
    startTime = 0;
}

// @fnv 0x0045cec0
template <> NiPointer<NiNode>::~NiPointer()
{
    if (m_pObject != 0)
    {
        m_pObject->DecRefCount();
    }
}

struct FUN_009dfd50Class
{
    void BSSimpleArray_VirtualPathingNode_1024_GetLast();
};

// @fnv 0x009ddb30
// src: XBOX_PDB 0x009ddb30
void __thiscall ActorMover::PathingSolution_GetLastVirtualNode()
{
    ((FUN_009dfd50Class*)((char*)this + 8))->BSSimpleArray_VirtualPathingNode_1024_GetLast();
}

// @fnv 0x009dbb10
// src: XBOX_PDB 0x009dbb10
bool ActorMover::SetGoal_009dbb10(TESObjectREFR* apRef, float afValue, int aiValue)
{
    return SetGoal_009dba50((int)((const TESObjectREFR*)apRef)->GetPos(), (int)((LowProcess*)apRef)->LowProcess::GetTarget(), (int)apRef->GetParentWorldSpace(),
                        afValue, aiValue);
}

class TESSound;

// Calls FUN_009dbb60 with the reference's position, target sound, world space, Z angle, and the two given values.
// @fnv 0x009dbc30
// src: COMMUNITY 0x009dbc30
void ActorMover::SetGoalAndAngle_(TESObjectREFR* apReference, float afValue, int aiValue)
{
    SetGoalAndAngle(((const TESObjectREFR*)apReference)->GetPos(), ((LowProcess*)apReference)->LowProcess::GetTarget(), apReference->GetParentWorldSpace(),
                 apReference->GetAngleOnReference().z, afValue, aiValue);
}

// Returns the value from the inner object's f12() if p is non-null, otherwise returns 0.
// @fnv 0x009dcab0
// src: XBOX_PDB 0x009dcab0
int ActorMover::GetCurrentNodeIndex()
{
    if (m_pPathHandler != 0)
        return m_pPathHandler->vfn_30();
    else
        return 0;
}

// Queries the handler when a valid movement path is present.
// @fnv 0x009dcb30
// src: XBOX_PDB 0x009dcb30
bool ActorMover::IsWaitingForAvoidance()
{
    if (m_pPathHandler && (NiNode*)m_pActorNode && ((NiNode*)(NiNode*)m_pActorNode)->PathingSolution_IsValid())
        return m_pPathHandler->vfn_3c();
    return true;
}

namespace fnv_009dcb90 {

// Queries the handler when a valid movement path is present.
} // namespace fnv_009dcb90

// @fnv 0x009dcb90
// src: XBOX_PDB 0x009dcb90
bool ActorMover::IsMovementBlocked()
{
    using namespace fnv_009dcb90;
    if (m_pPathHandler && (NiNode*)m_pActorNode && ((NiNode*)(NiNode*)m_pActorNode)->PathingSolution_IsValid())
        return m_pPathHandler->vfn_40();
    return 0;
}

// Returns the value from pHandler if it is set, otherwise returns 0.0f.
// @fnv 0x009dcbf0
// src: COMMUNITY 0x009dcbf0
float ActorMover::GetCurrentPercent()
{
    if (m_pPathHandler)
        return m_pPathHandler->vfn_1c();
    else
        return 0.0f;
}

// Returns the value from mPtr by calling its F6 method, or 0.0f when mPtr is null.
// @fnv 0x009dcc20
// src: COMMUNITY 0x009dcc20
float ActorMover::GetDistanceTraveled()
{
    if (m_pPathHandler)
        return m_pPathHandler->vfn_18();
    else
        return 0.0f;
}

// Returns the value from the handler pointer if set, otherwise returns 0.0f.
// @fnv 0x009dcc50
// src: COMMUNITY 0x009dcc50
float ActorMover::GetDistanceRemaining()
{
    if (m_pPathHandler)
        return m_pPathHandler->vfn_28();
    else
        return 0.0f;
}

// @fnv 0x009dccf0
// src: COMMUNITY 0x009dccf0
bool ActorMover::ComputePathPassesThroughPlayersArea()
{
    if (!(NiNode*)m_pActorNode || !((NiNode*)(NiNode*)m_pActorNode)->PathingSolution_IsValid())
        return false;
    return m_pPathHandler->vfn_44();
}

// @fnv 0x009de040
void ActorMover::ClearFlags(unsigned int mask)
{
    unk34 &= ~mask;
}

namespace fnv_009de110 {

// Returns false if flt is zero or ptr is null; otherwise calls ptr->func(a, b) and returns its result.
} // namespace fnv_009de110

// @fnv 0x009de110
// src: XBOX_PDB 0x009de110
bool ActorMover::GetNodeLocation(int aiArg1, int aiArg2)
{
    using namespace fnv_009de110;
    if ((NiNode*)m_pActorNode && m_pPathHandler)
        return m_pPathHandler->vfn_24((unsigned int)aiArg1, *(NiPoint3*)aiArg2);
    return false;
}

// Stores the form's form ID at offset 0x2c, or 0 when pForm is null.
// @fnv 0x009de3a0
void ActorMover::SetFormID(TESForm* pForm)
{
    unk2C = pForm ? pForm->GetFormID() : 0;
}

// @fnv 0x009de3e0
// src: XBOX_PDB 0x009de3e0
bool ActorMover::IsPathValid()
{
    if ((NiNode*)m_pActorNode && ((NiNode*)(NiNode*)m_pActorNode)->PathingSolution_IsValid())
        return true;
    return false;
}

// Returns a pointer to m_pathingLocation if its FUN_006a9520 check fails, otherwise returns null.
// @fnv 0x009de460
PathingLocation* ActorMover::GetPathingLocation()
{
    if (!m_pathingLocation.QUnused())
        return &m_pathingLocation;
    return 0;
}

namespace fnv_006e29f0 {
struct _Mem_2064
{
    char pad[0x28];
    ~_Mem_2064();
};

struct FUN_006d3ae0
{
    void SetValue(float v);
};
struct FUN_006e2b50_shell
{
    void SetCantOpenDoors(bool b);
};
struct FUN_006e2b70_shell
{
    void SetCanSwim(bool b);
};
struct FUN_006e2b90
{
    void SetFlag(unsigned char f);
};
struct FUN_006e2bb0_shell
{
    void SetInitialPathHeading(float f);
};
// Actor.h does not yet declare the no-argument call at 0x008be280.
float __fastcall Actor_GetWidth(Actor*);
bool __fastcall Actor_DoesSwim(Actor* a);
bool __fastcall DoesFly_0087f390(Actor* a);
extern const double DAT_010290b8;
struct FUN_006e29f0_sub
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
    virtual bool v10();
};
struct FUN_006e29f0_shell
{
    void InitFromActor(Actor* apActor);
};

// Copies pathing location, value, flags and actor-base data from apActor into this object.
// @fnv 0x006e29f0
void FUN_006e29f0_shell::InitFromActor(Actor* apActor)
{
    *(PathingLocation*)((char*)this + 0xc) = PathingLocation((TESObjectREFR*)apActor);
    ((FUN_006d3ae0*)this)->SetValue((float)(Actor_GetWidth(apActor) * DAT_010290b8));
    *(PathingActorData*)this = *(PathingActorData*)apActor;
    ((FUN_006e2b70_shell*)this)->SetCanSwim(Actor_DoesSwim(apActor));
    ((FUN_006e2b90*)this)->SetFlag(DoesFly_0087f390(apActor));
    if (apActor->IsCreature())
    {
        ((FUN_006e2b50_shell*)this)
            ->SetCantOpenDoors(((FUN_006e29f0_sub*)((char*)apActor->GetActorBase() + 0x30))->v10());
    }
    ((FUN_006e2bb0_shell*)this)->SetInitialPathHeading(apActor->GetCurrentTargetDistance(false));
}
}  // namespace fnv_006e29f0

namespace fnv_009dbc90 {
class _Mem_2064
{
  public:
    ~_Mem_2064();
};

struct PathingRequest_b
{
    void SetAvoidNodeArray(void* apAvoidNodes);
};

struct FUN_006e2b50_shell
{
    void SetCantOpenDoors(bool);
};

struct FUN_006e2b70_shell
{
    void SetCanSwim(bool);
};

struct FUN_006e2b90
{
    void SetFlag(unsigned char);
};

struct Dummy
{
    bool DoesFly();
};

bool __fastcall DoesSwim(TESActorBase*);

struct ActorBaseComponent30
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
    virtual bool v10();
};

// @fnv 0x009dbc90
void __cdecl SetupPathingRequest(Actor* apActor, PathingRequest* apRequest, NiPoint3 const& aGoalLocation,
                                 TESObjectCELL* apCell, TESWorldSpace* apWorldSpace, float afTargetRadius,
                                 void* apAvoidNodes)
{
    PathingLocation pathingLocation(aGoalLocation, apCell, apWorldSpace);
    apRequest->InitFromActor(apActor);
    apRequest->SetDestination(&pathingLocation);
    if (afTargetRadius <= 0.0)
    {
        apRequest->SetCenterRadius(TESPackage::GetPackageDefaultFloat());
    }
    else
    {
        apRequest->SetCenterRadius(afTargetRadius);
    }
    ((PathingRequest_b*)apRequest)->SetAvoidNodeArray(apAvoidNodes);
    if (apActor->IsCreature())
    {
        ((FUN_006e2b50_shell*)apRequest)
            ->SetCantOpenDoors(((ActorBaseComponent30*)((char*)apActor->GetActorBase() + 0x30))->v10());
    }
    ((FUN_006e2b70_shell*)apRequest)->SetCanSwim(DoesSwim(apActor->GetActorBase()));
    ((FUN_006e2b90*)apRequest)->SetFlag(((Dummy*)apActor->GetActorBase())->DoesFly());
}
}  // namespace fnv_009dbc90

namespace fnv_009dc7f0 {

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// Actor.h lacks TryMove(int) at 0x00881860 and the call at 0x0088d640.
// Retain this local method view for those unsupported declarations.
struct ActorStub_009dc7f0
{
    void Actor_GetOutofFurnitureQuick();
    void TryMove(int);
};

// Updates the actor's sit/sleep handling and the teleport path flag based on the path object's state and node counts.
} // namespace fnv_009dc7f0

// @fnv 0x009dc7f0
void ActorMover::UpdateTeleportPathState()
{
    using namespace fnv_009dc7f0;
    if (pActor->GetProcess()->GetSitSleepState() == 4 || pActor->GetProcess()->GetSitSleepState() == 9)
        return;
    else if (pActor->GetProcess()->GetSitSleepState())
    {
        ((ActorStub_009dc7f0*)pActor)->Actor_GetOutofFurnitureQuick();
        return;
    }
    if (!m_pPathHandler || IsPathingComplete())
    {
        if (!g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
            ((ActorStub_009dc7f0*)pActor)->TryMove(0);
    }
    else if (m_bMovementStateFlag && m_pPathHandler->vfn_34())
    {
        if (!m_pActorNode)
            return;
        if (currentNode == lastNode && currentNode < ((PathingSolution*)(NiNode*)m_pActorNode)->GetVirtualNodeCount() - 1)
            return;
        m_bMovementStateFlag = false;
    }
    else
    {
        if (m_pPathHandler->vfn_34())
            return;
        m_bMovementStateFlag = true;
    }
}

class ActiveEffect;
class BGSIdleCollection;
class CombatAction;
class CombatGoal;
class ActorCombatGroup;
class CombatProcedure;
class IDebugText;
class InventoryStackRecord;
class NiMatrix3;
class NiQuaternion;
class PackageTargetRecord;
class Projectile;
class Script;
class TESCombatStyle;
class PerkEntryConditionSet;
class TESEscortPackageData;
class TESFile;
class TESIdleForm;
class TESObjectWEAP;
class TESPackage;
class TESPackageData;
class TESPatrolPackageData;
class TESTopic;
class TESUseWeaponPackageData;
class TESWorldSpace;
class hkVector4;
class BSPortalGraph;
namespace fnv_009df8c0 {
struct SaveLoadFile;
struct CombatPlan;
struct CombatBehavior;
struct CombatState;
struct LocationDescriptor;
struct DurationData;

struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];

struct HighActorCullerCell
{
    BSPortalGraph* GetPortalGraph_009d9f20();
};

struct SPathReq
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual int GetType();
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void LoadGame(BGSLoadFormBuffer*);
};

} // namespace fnv_009df8c0

// @fnv 0x009df8c0
// src: XBOX_PDB 0x009df8c0
void ActorMover::InitLoadGame_009df8c0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    using namespace fnv_009df8c0;
    if (m_pPathHandler)
        m_pPathHandler->LoadGame(apLoadGameBuffer);
    if ((PathingRequest*)request)
    {
        if (((SPathReq*)(unsigned int)(PathingRequest*)request)->GetType() == 5)
        {
            PathingRequestLOS* plosRequest = (PathingRequestLOS*)(unsigned int)(PathingRequest*)request;
            CombatController* pcombatController = pActor->GetCombatController();
            if (pcombatController && pcombatController->GetCombatGroup())
            {
                NiPointer<BSPortalGraph> kGraph(((HighActorCullerCell*)pcombatController->GetCombatGroup())->GetPortalGraph_009d9f20());
                plosRequest->AssignAtOffsetB0(reinterpret_cast<const NiPointer<void>&>(kGraph));
            }
        }
        ((SPathReq*)(unsigned int)(PathingRequest*)request)->LoadGame(apLoadGameBuffer);
        *(PathingActorData*)(unsigned int)(PathingRequest*)request =
            *(PathingActorData*)pActor;
    }
}

struct FUN_006d0b80
{
    FUN_006d0b80(PathingRequest*, PathingSolution*);
    ~FUN_006d0b80();
    int PathBuilder_UpdatePathMoveToLow();
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
    int f6;
    int f7;
    int f8;
    int f9;
    int f10;
    int f11;
    int f12;
};
// Constructs a FUN_006d0b80 from the request and solution, then returns the result of FUN_006c93d0 on it.
// @fnv 0x006d53b0
// src: COMMUNITY 0x006d53b0
int Pathing_UpdateSolutionMoveToLow(PathingRequest* pRequest, PathingSolution* b)
{
    FUN_006d0b80 obj(pRequest, b);
    return obj.PathBuilder_UpdatePathMoveToLow();
}

struct TESForm;
void __fastcall ActorMover_ClearCurrentData(TESForm*);
struct Sol11
{
    bool PathingSolution_IsValid();
    int FUN_00441110();
    unsigned int PathingSolution_GetVirtualNodeCount();
    void* GetVirtualNode_006e78b0(unsigned int);
};
struct QueueVt11;
struct Req11
{
    bool GetByteAtOffset9B();
};
struct Node11
{
    void* FUN_00717e50();
};
struct Loc11
{
    int m_00;
    Loc11& operator=(const Loc11&);
    void FUN_006ddbe0();
};
struct Msg11
{
    int m_type;
    NiPointer<Sol11> m_sol;
    Msg11();
    ~Msg11();
};
struct ProcVt11
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
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual int v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual int v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual int v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void v6e4();
    virtual void v6e8();
    virtual void v6ec();
    virtual void v6f0();
    virtual void v6f4();
    virtual void v6f8();
    virtual bool v6fc();
};

struct QueueVt11
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual bool v10(void*);
};
struct Proc11 : public ProcVt11
{
    int FUN_0045cd60();
};

// @fnv 0x009dc120
// src: XBOX_PDB 0x009dc120
void ActorMover::Update_009dc120(float f)
{
    if (m_bMovementComplete)
    {
        unk78 = 1;
        FinishMoving(1);
        m_bMovementComplete = 0;
    }
    if (pActor->HasHealth(false))
    {
        if (m_pPathHandler)
        {
            m_pPathHandler->vf28();
        }
        goto END;
    }
    {
        Proc11* proc = reinterpret_cast<Proc11*>(pActor->GetProcess());
        if (proc == 0)
            goto END;
        if (proc->v610() == 4)
            goto END;
        if (proc->FUN_0045cd60() != pActor->GetProcessTier())
            goto END;
        if (proc->v4bc() != 0)
            goto END;
        if (pActor->GetHasKnockedState())
            goto END;
        if (proc->v40c() != 0)
            goto END;
        if (proc->v6fc())
            goto END;
        if (m_bMovementStateFlag)
        {
            m_bMovementStateFlag = 0;
            UpdatePathMovement();
        }
        if (!bPathingFailed)
        {
            if (!m_bMovementActive)
            {
                if ((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode) && ((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode))->PathingSolution_IsValid())
                {
                    eState = 3;
                    FUN_009dc590(f);
                    goto END;
                }
            }
            else
            {
                Msg11 msg;
                if (((QueueVt11*)(*(NiPointer<QueueVt11>*)&m_queue))->v10(&msg))
                {
                    switch (msg.m_type)
                    {
                    case 0:
                        eState = 3;
                        m_bMovementActive = 0;
                        (*(NiPointer<Sol11>*)&m_pActorNode) = msg.m_sol;
                        UpdatePathingState(f);
                        break;
                    case 1: {
                        m_bMovementActive = 0;
                        (*(NiPointer<Sol11>*)&m_pActorNode) = msg.m_sol;
                        if ((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode) && ((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode))->PathingSolution_IsValid() && ((Req11*)(*(NiPointer<Req11>*)&request))->GetByteAtOffset9B())
                        {
                            eState = 3;
                            UpdatePathingState(f);
                            break;
                        }
                        eState = 7;
                        SetEnabled(1);
                        if ((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode))
                        {
                            int idx = ((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode))->FUN_00441110();
                            if (idx != -1)
                            {
                                if (((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode))->PathingSolution_GetVirtualNodeCount() > 0)
                                {
                                    void* node = ((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode))->GetVirtualNode_006e78b0(idx);
                                    if (node)
                                    {
                                        (*(Loc11*)&m_pathingLocation) = *(Loc11*)((Node11*)node)->FUN_00717e50();
                                        (*(Loc11*)&m_pathingLocation).FUN_006ddbe0();
                                    }
                                }
                            }
                        }
                        ::ActorMover_ClearCurrentData((TESForm*)this);
                        break;
                    }
                    default:
                        break;
                    }
                    goto END;
                }
                goto SECB;
            }
        }
    }
SECB:
    if (!((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode) && ((Sol11*)(*(NiPointer<Sol11>*)&m_pActorNode))->PathingSolution_IsValid() && !bPathingFailed))
    {
        if (m_pPathHandler)
        {
            if (m_pPathHandler->vfn_10(f) == 5)
            {
                eState = 6;
            }
        }
    }
END:
    SetCurrentFrameMoveModeAndDelta();
    FUN_00483710();
}

// UpdateFlagFromTarget: thiscall, void. Calls bool vslot 0x34 on the object at this+0x24.

// Tracks whether the shared handler is active.
// @fnv 0x009dc780
void ActorMover::UpdateFlagFromTarget()
{
    if (m_pPathHandler == 0)
    {
    }
    else
    {
        if (m_bMovementStateFlag != 0 && m_pPathHandler->vfn_34() == 0)
        {
            m_bMovementStateFlag = 0;
        }
        else
        {
            if (m_pPathHandler->vfn_34() == 0)
            {
            }
            else
            {
                m_bMovementStateFlag = 1;
            }
        }
    }
}

struct DcVec
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

// Writes a DcVec to out via m_24->v11(out, f) when m_24 is set, otherwise copies the vector returned by m_28->v125(), and returns out.
// The shared mover exposes explicit-output declarations for these two calls.
// Their aggregate-return overloads pass the destination directly to the shared
// handler virtuals; this declaration-only extension adds no object layout.
struct ActorMoverVectorResults : ActorMover
{
    NiPoint3 GetVec(float);
    NiPoint3 GetHandlerPosition();
};

// @fnv 0x009dcc80
NiPoint3 ActorMoverVectorResults::GetVec(float f)
{
    if (m_pPathHandler != 0)
    {
        return m_pPathHandler->vfn_2c(f);
    }
    else
    {
        return *static_cast<const Actor*>(pActor)->GetPos();
    }
}

struct PkgTriple
{
    void* a;
    void* b;
    void* c;
};


// Returns a triple: copies it from m_28's GetTriple when the m_20 helper check fails or m_24 is null, otherwise lets m_24 fill it via ProcessOut.
// @fnv 0x009de0a0
NiPoint3 ActorMoverVectorResults::GetHandlerPosition()
{
    if (reinterpret_cast<NiPointer<NiNode>*>(&m_pActorNode)->operator->() == 0 || m_pPathHandler == 0)
    {
        return *static_cast<const Actor*>(pActor)->GetPos();
    }
    else
    {
        return m_pPathHandler->vfn_20();
    }
}

struct PathCoordinate
{
    NiPoint3* FUN_005c3420();
};
struct PathQuery
{
    PathCoordinate* FUN_00717e50(NiPoint3*);
};

// @fnv 0x009de2b0
bool ActorMover::GetPathCoordinate(NiPoint3* position)
{
    if (m_pActorNode.operator->() && m_pActorNode.operator->()->PathingSolution_IsValid())
    {
        PathQuery* query = reinterpret_cast<PathNode*>(m_pActorNode.operator->())->PathingSolution_GetLastVirtualNode();
        if (query)
        {
            // Raw output storage avoids an outlined call to the shared empty constructor.
            void* coordinateStorage[sizeof(NiPoint3) / sizeof(void*)];
            memcpy(position, query->FUN_00717e50((NiPoint3*)coordinateStorage)->FUN_005c3420(), sizeof(NiPoint3));
            return true;
        }
    }
    return false;
}

struct Fx_Arg
{
    void Apply(int v);
};

struct Fx_Obj
{
    int Lookup();
};

struct Fx_Node
{
    bool Test();
    Fx_Obj* Find();
};

// If sub's node exists, tests it, finds its object, applies the object's lookup to arg and returns true; otherwise returns false.
// @fnv 0x009de330
bool ActorMover::ApplyNodeLookup(Fx_Arg* arg)
{
    Fx_Obj* obj;

    if (((NiPointer<Fx_Node>*)&m_pActorNode)->operator->() != 0)
    {
        if (((NiPointer<Fx_Node>*)&m_pActorNode)->operator->()->Test())
        {
            obj = ((NiPointer<Fx_Node>*)&m_pActorNode)->operator->()->Find();
            if (obj != 0)
            {
                arg->Apply(obj->Lookup());
                return true;
            }
        }
    }
    return false;
}

// Declare only the missing 0x00881860 operation; Actor supplies the entire shared layout.
struct ActorMovementOperation : Actor
{
    void TryMove(int flag);
};

// These folded accessors are not declared by PathingSolution.h.
int __fastcall GetPathingCurrentNodeIndex(PathingSolution* solution); // 0x009611e0
unsigned int __fastcall GetPathingLastNodeIndex(PathingSolution* solution); // 0x00441110

struct FUN_009e0190
{
    void* member00;
    void* member04;
    void* member08;
    void* member0c;
    void* member10;
    void* member14;
    void* member18;
    void* member1c;
    void* member20;
    void* member24;
    void* member28;
    void* member2c;
    void* member30;
    void* member34;
    void* member38;
    void* member3c;
    void* member40;
    void* member44;
    void* member48;
    void* member4c;
    void* member50;
    void* member54;
    void* member58;
    void* member5c;
    void* member60;
    void* member64;
    void* member68;
    void* member6c;
    void* member70;
    void* member74;
    void* member78;
    void* member7c;
    void* member80;
    void* member84;
    void* member88;
    void* member8c;
    void* member90;
    void* member94;
    void* member98;
    void* member9c;
    void* membera0;
    void* membera4;
    void* membera8;
    void* memberac;
    void* memberb0;
    void* memberb4;
    void* memberb8;
    void* memberbc;
    void* memberc0;
    void* memberc4;
    void* memberc8;
    void* membercc;
    void* memberd0;
    void* memberd4;
    void* memberd8;
    void* memberdc;
    void* membere0;
    FUN_009e0190(Actor* a, ActorMover* b, NiPointer<PathingSolution>& c, PathingRequest* d);
};

struct FUN_009ea770
{
    void* member00;
    void* member04;
    void* member08;
    void* member0c;
    void* member10;
    void* member14;
    void* member18;
    void* member1c;
    FUN_009ea770(Actor* a, ActorMover* b, NiPointer<PathingSolution>& c, PathingRequest* d);
};

int QueryPathScope(PathingRequest* a, PathingSolution* b, int c);

// Checks the pathing request/solution state, swaps m_24 for a new handler, then calls vfn_04 and HandlePathResult with the result.
// @fnv 0x009dbdc0
void ActorMover::UpdatePathingState(float a1)
{
    FUN_00483710();
    bool flag;
    if ((*(NiPointer<PathingSolution>*)&m_pActorNode).operator->()->GetObjectFlags() > 0)
    {
        if (pActor->FUN_00931850())
        {
            flag = false;
            request.operator->()->FUN_006e2b20(pActor);
            switch (Pathing_UpdateSolutionMoveToLow(request.operator->(), (PathingSolution*)(*(NiPointer<PathingSolution>*)&m_pActorNode).operator->()))
            {
                break;
            case -1:
            case 0:
                eState = 7;
                SetEnabled(1);
                return;
            }
        }
        else
        {
            flag = true;
        }
    }
    else
    {
        if (!pActor->FUN_00931850())
        {
            flag = true;
            request.operator->()->FUN_006e2b20(pActor);
            switch (QueryPathScope(request.operator->(), (PathingSolution*)(*(NiPointer<PathingSolution>*)&m_pActorNode).operator->(), 0))
            {
                break;
            case -1:
            case 0:
                static_cast<ActorMovementOperation*>(pActor)->TryMove(1);
                eState = 7;
                SetEnabled(1);
                return;
            }
        }
        else
        {
            flag = false;
        }
    }
    if (flag)
    {
        currentNode = GetPathingCurrentNodeIndex((*(NiPointer<PathingSolution>*)&m_pActorNode).operator->());
        lastNode = GetPathingLastNodeIndex((*(NiPointer<PathingSolution>*)&m_pActorNode).operator->());
        ActorPathHandler* old = m_pPathHandler;
        m_pPathHandler = (ActorPathHandler*)new FUN_009e0190(pActor, this, (*(NiPointer<PathingSolution>*)&m_pActorNode), request.operator->());
        m_pPathHandler->vf22(old);
        if (old)
        {
            delete old;
        }
    }
    else
    {
        currentNode = 0;
        lastNode = (*(NiPointer<PathingSolution>*)&m_pActorNode).operator->()->PathingSolution_GetVirtualNodeCount() - 1;
        if (m_pPathHandler)
        {
            delete m_pPathHandler;
        }
        m_pPathHandler = (ActorPathHandler*)new FUN_009ea770(pActor, this, (*(NiPointer<PathingSolution>*)&m_pActorNode), request.operator->());
    }
    int res = m_pPathHandler->vfn_04(0.0f, a1);
    HandlePathResult(res);
}

void __fastcall ActorMover_ClearPath(ActorMover* apMover);

// Handles a pathing result code: on failure sets state 7 and resets the path, on success checks completion and distance to the last node.
// @fnv 0x009dc5e0
void ActorMover::HandlePathResult(int aiResult)
{
    switch (aiResult)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        eState = 7;
        ResetPathing();
        SetPathFailed(true);
        break;
    case 5:
    case 6: {
        int iUpdateResult = UpdatePathHandler();
        if (!((PathingSolution*)m_pActorNode.operator->())->IsIncomplete())
        {
            if (aiResult == 6 && eState != 7)
            {
                eState = 3;
            }
            ResetPathing();
        }
        else if (iUpdateResult != 1)
        {
            if (((PathingSolution*)m_pActorNode.operator->())->GetNodeCount() > 0)
            {
                NiPoint3 kDelta =
                    reinterpret_cast<PathingGraphNode*>(((PathingSolution*)m_pActorNode.operator->())->GetVirtualNode(GetPathingLastNodeIndex((PathingSolution*)m_pActorNode.operator->())))->FUN_00717e50().GetPoint() -
                    *static_cast<const Actor*>(pActor)->GetPos();
                if (kDelta.GetSquaredXYLength() <= request.operator->()->FUN_009b0bd0() * request.operator->()->FUN_009b0bd0())
                {
                    break;
                }
            }
            eState = 7;
            SetPathFailed(true);
            ActorMover_ClearPath(this);
            ResetPathing();
        }
    }
    break;
    }
}

struct MovementStatus
{
    bool IsHighestPriority();
};
// Actor.h lacks the no-argument movement query at 0x008843a0.
bool __fastcall CanActorMove(Actor*);

// @fnv 0x009dce80
// src: XBOX_PDB 0x009dce80
bool ActorMover::RequestRotateActor_009dce80(float delta, bool force)
{
    bool result = false;
    ResetMoverState(1);
    if (reinterpret_cast<MovementStatus*>(pActor->GetAnimData()) && reinterpret_cast<MovementStatus*>(pActor->GetAnimData())->IsHighestPriority())
        unk78 = true;
    if (!CanActorMove(pActor) || pActor->GetSitSleepState())
    {
        eState = 6;
        result = true;
    }
    else if (!ActorMover_IsActorInLoadedArea(this))
    {
        eState = 6;
        pActor->SetFurnitureHeading(delta);
        result = true;
    }
    if (!result)
    {
        if (m_pPathHandler && !m_pPathHandler->vfn_34())
        {
            delete m_pPathHandler;
            m_pPathHandler = 0;
        }
        if (!m_pPathHandler)
            m_pPathHandler = (ActorPathHandler*)new Dummy_0xe4(pActor, this);
        if (m_pPathHandler->vfn_08(delta, force))
        {
            eState = 4;
            result = true;
        }
        else
        {
            eState = 6;
            result = false;
        }
    }
    FUN_00483710();
    return result;
}

struct PathVec
{
    float x, y, z;
    PathVec operator-(const PathVec&) const;
    float Length() const;
};
struct PathPosition
{
    PathVec GetPosition();
};
struct PathEntry
{
    PathPosition* GetData();
};
struct PathRequest
{
    void Update(PathActor_actormover*);
    bool IsValid();
};
struct PathSolution
{
    unsigned Count();
    PathEntry* Last();
    unsigned Start();
    unsigned End();
    bool IsValid();
    void* Extra();
    PathEntry* At(unsigned);
};
struct SmallPathHandler : ActorPathHandler
{
    int unk14, unk18, unk1c;
    SmallPathHandler(PathActor_actormover*, void*, NiPointer<PathSolution>*, PathRequest*);
};
struct LargePathHandler : SmallPathHandler
{
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0;
    LargePathHandler(PathActor_actormover*, void*, NiPointer<PathSolution>*, PathRequest*);
};
extern float RoundPath(float);
extern int UpdatePath(PathRequest*, PathSolution*);
extern int ExtendPath(PathRequest*, PathSolution*, unsigned);
extern bool SpecialMovement();
struct SpecialPathActor
{
    void MoveTo(const PathVec&);
};
extern SpecialPathActor* __stdcall GetSpecialActor(PathActor_actormover*);
struct RegularPathActor
{
    virtual void v000();
};

// Advances the actor along the path: recomputes the current segment from handler progress, updates or extends the path, and rebuilds the handler.
// @fnv 0x009dd2d0
void ActorMover::UpdatePathMovement()
{
    unsigned current;
    float progress;
    unsigned next;
    int result6;
    float fraction;
    if (!(*(NiPointer<PathSolution>*)&m_pActorNode).operator->() || !(*(NiPointer<PathRequest>*)&request).operator->())
    {
        delete m_pPathHandler;
        m_pPathHandler = 0;
        eState = 6;
        SetEnabled(0);
        return;
    }
    if (((PathActor_actormover*)pActor)->Exists())
    {
        if (!m_pPathHandler->vfn_34())
            return;
        if (lastNode == currentNode)
            current = lastNode + 1;
        else
        {
            progress = m_pPathHandler->vfn_1c();
            current = (unsigned)(int)RoundPath((lastNode - currentNode) * progress);
            current += currentNode;
        }
        if (current > (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Count() - 1)
            current = (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Count() - 1;
        (*(NiPointer<PathRequest>*)&request).operator->()->Update(((PathActor_actormover*)pActor));
        switch (UpdatePath((*(NiPointer<PathRequest>*)&request).operator->(), (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()))
        {
        case 1:
            currentNode = (unsigned short)current;
            lastNode = (unsigned short)((*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Count() - 1);
            break;
        case -1:
        case 0:
            eState = 7;
            SetEnabled(1);
            return;
        }
        delete m_pPathHandler;
        m_pPathHandler = new SmallPathHandler(((PathActor_actormover*)pActor), this, ((NiPointer<PathSolution>*)&m_pActorNode), (*(NiPointer<PathRequest>*)&request).operator->());
        m_pPathHandler->vfn_04((float)currentNode, 0.0f);
        return;
    }
    if (m_pPathHandler->vfn_34())
        next = currentNode + 1;
    else
        next = (unsigned int)m_pPathHandler->vfn_30() > 0 ? (unsigned int)m_pPathHandler->vfn_30() - 1 : 0;
    if (next >= (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Count() - 1)
    {
        if (SpecialMovement())
            GetSpecialActor(((PathActor_actormover*)pActor))->MoveTo((*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Last()->GetData()->GetPosition());
        else
            reinterpret_cast<Actor*>(((PathActor_actormover*)pActor))->SetPos(
                const_cast<NiPoint3*>(reinterpret_cast<const NiPoint3*>(&((NiPointer<PathSolution>*)&m_pActorNode)->operator->()->Last()->GetData()->GetPosition())));
        FinishMoving(1);
        return;
    }
    (*(NiPointer<PathRequest>*)&request).operator->()->Update(((PathActor_actormover*)pActor));
    switch (ExtendPath((*(NiPointer<PathRequest>*)&request).operator->(), (*(NiPointer<PathSolution>*)&m_pActorNode).operator->(), next))
    {
    case 2:
        currentNode = (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Start();
        lastNode = (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->End();
        break;
    case -1:
    case 0:
        if ((*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->IsValid() && (*(NiPointer<PathRequest>*)&request).operator->()->IsValid() && (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Extra())
        {
            currentNode = (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Start();
            lastNode = (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->End();
        }
        else
        {
            ((PathActor_actormover*)pActor)->Stop(1);
            eState = 8;
            SetEnabled(1);
            return;
        }
        break;
    }
    if (currentNode == lastNode)
    {
        FinishMoving(1);
        return;
    }
    fraction = 0.0f;
    if (!m_pPathHandler->vfn_34())
    {
        PathVec startPoint = (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->At((*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->Start())->GetData()->GetPosition();
        PathVec endPoint6 = (*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->At((*(NiPointer<PathSolution>*)&m_pActorNode).operator->()->End())->GetData()->GetPosition();
        float distance = (endPoint6 - startPoint).Length();
        fraction = m_pPathHandler->vfn_18() / distance;
    }
    delete m_pPathHandler;
    m_pPathHandler = new LargePathHandler(((PathActor_actormover*)pActor), this, ((NiPointer<PathSolution>*)&m_pActorNode), (*(NiPointer<PathRequest>*)&request).operator->());
    result6 = m_pPathHandler->vfn_04(fraction, 0.0f);
    if (result6 == 5 || result6 == 6)
    {
        HandlePathResult(result6);
        FinishMoving(1);
    }
}

namespace ActorMovement {
struct Cell
{
    bool FUN_00425fd0();
};
struct World
{
};
struct Area
{
    int FindNavMeshInfoForCellKey();
};
// Exe 0x009de490: unit-local Map view; declarations and layout are preserved.
struct ActormoverMapView
{
    Area* TES_GetNavMeshInfoMap(World*, unsigned int);
    double GetCellHeightAtPosition(const NiPoint3&, Cell*);
};
extern ActormoverMapView* DAT_011dea10;
unsigned int PackShortPair(unsigned short, unsigned short);
struct Reference
{
    int FUN_00441110();
    int NiAVObject_GetParent();
    NiPoint3 FUN_005c3420();
    Cell* FUN_006dd4f0();
};
struct Request
{
    Reference* NiAVObject_GetRotate_006a9540();
    Reference* GetOffsetC();
};
struct Queue
{
    unsigned int value;
    void FUN_006d2c00();
};
struct Clock
{
    unsigned int FUN_00825c00();
};
extern Clock DAT_011f6394;
extern float DAT_0109222c, DAT_01092230, DAT_01092234;
extern double DAT_01016978;

} // namespace ActorMovement

// @fnv 0x009de490
void ActorMover::SetEnabled(bool abEnabled)
{
    using namespace ActorMovement;
    bPathingFailed = abEnabled;
    if (!abEnabled)
        ((ActorMovement::Queue*)&m_pathingLocation)->FUN_006d2c00();
    if (abEnabled)
    {
        if (pActor->FUN_00931850() == 3 && (!pActor->FUN_008d6f30() || !reinterpret_cast<Cell*>(pActor->FUN_008d6f30())->FUN_00425fd0()))
        {
            int xSlot14 = int(static_cast<const Actor*>(pActor)->GetPos()->x) >> 12;
            int y = int(static_cast<const Actor*>(pActor)->GetPos()->y) >> 12;
            if (!xSlot14 && !y &&
                !DAT_011dea10
                     ->TES_GetNavMeshInfoMap(reinterpret_cast<World*>(pActor->TESObjectREFR_GetWorldSpace()), PackShortPair((unsigned short)xSlot14, (unsigned short)y))
                     ->FindNavMeshInfoForCellKey())
                pActor->Actor_MoveActorAndFollowers(((NiPointer<ActorMovement::Request>*)&request)->operator->()->NiAVObject_GetRotate_006a9540()->FUN_005c3420(), 0.0f,
                                    ((NiPointer<ActorMovement::Request>*)&request)->operator->()->NiAVObject_GetRotate_006a9540()->NiAVObject_GetParent(),
                                    ((NiPointer<ActorMovement::Request>*)&request)->operator->()->NiAVObject_GetRotate_006a9540()->FUN_00441110(), 0, 1);
        }
        float intervalSlot1 = pActor->FUN_008b0190(7) ? DAT_0109222c : DAT_01092230;
        if (((NiPointer<ActorMovement::Request>*)&request)->operator->())
        {
            Cell* fromSlot12 = ((NiPointer<ActorMovement::Request>*)&request)->operator->()->GetOffsetC()->FUN_006dd4f0();
            Cell* to = ((NiPointer<ActorMovement::Request>*)&request)->operator->()->NiAVObject_GetRotate_006a9540()->FUN_006dd4f0();
            if (fromSlot12 && to)
            {
                bool fromAboveSlot13 = DAT_011dea10->GetCellHeightAtPosition(
                                           ((NiPointer<ActorMovement::Request>*)&request)->operator->()->GetOffsetC()->FUN_005c3420(), fromSlot12) >
                                       ((NiPointer<ActorMovement::Request>*)&request)->operator->()->GetOffsetC()->FUN_005c3420().z;
                bool toAboveSlot1 =
                    DAT_011dea10->GetCellHeightAtPosition(((NiPointer<ActorMovement::Request>*)&request)->operator->()->NiAVObject_GetRotate_006a9540()->FUN_005c3420(), to) >
                    ((NiPointer<ActorMovement::Request>*)&request)->operator->()->NiAVObject_GetRotate_006a9540()->FUN_005c3420().z;
                if (fromAboveSlot13 != toAboveSlot1)
                    intervalSlot1 = DAT_01092234;
            }
        }
        float elapsedSlot0 = (DAT_011f6394.FUN_00825c00() - lastTime) * DAT_01016978;
        float total = (DAT_011f6394.FUN_00825c00() - startTime) * DAT_01016978;
        if (elapsedSlot0 >= intervalSlot1)
        {
            retries = 0;
            lastTime = DAT_011f6394.FUN_00825c00();
            startTime = DAT_011f6394.FUN_00825c00();
        }
        else if (total >= intervalSlot1 && retries >= 2)
        {
            UpdateTargeting();
            retries = 0;
            lastTime = DAT_011f6394.FUN_00825c00();
            startTime = DAT_011f6394.FUN_00825c00();
        }
        else
        {
            ++retries;
            lastTime = DAT_011f6394.FUN_00825c00();
        }
        FUN_00483710();
    }
}

class TESWorldSpace;
namespace fnv_009de8b0 {

struct PLoc
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
    PLoc(void* refr);
    ~PLoc();
    unsigned int FUN_006dd4f0() const;
    NiPoint3 FUN_005c3420();
    void FUN_006dd6f0(int a);
    bool FUN_006dd6a0();
};
struct Req
{
    PLoc* GetOffsetC();
    PLoc* NiAVObject_GetRotate_006a9540();
    float FUN_009b0bd0();
};

struct ProjBase
{
    bool DoesSwim();
    bool DoesFly();
};
struct RefrV
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void Call2a8(NiPoint3*);
};
// Actor.h lacks the query at 0x008bc7f0 and the calls at 0x008985d0
// and 0x008be280. Retain this local actor view until those are shared.
struct Actor13 : public RefrV
{
    bool Actor_IsFollowing_008bc7f0(void* player);
    void Actor_InitiateMovementBlockedPackage();
    int FUN_00931850();
    ProjBase* FUN_004181e0();
    float Actor_GetWidth();
};
struct Player13 : public RefrV
{
    void* FUN_008d6f30();
};

extern TES* g_TES;
extern "C" Player13* g_thePlayer;
extern "C" float _runtimeFloatSettingDefault38;
extern "C" double _gModifierZero;

TESWorldSpace* __fastcall TESObjectREFR_GetWorldSpace(TESObjectREFR* refr);
void __cdecl TESObjectREFR_MoveRefToNewSpace(void* actor, void* cell, void* ws);
struct Helper13
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
    Helper13();
    ~Helper13();
    void AssignPathingLocation(PLoc* loc);
    void FUN_006d1bc0(const PLoc& loc);
    void FUN_006d3b00(float f);
    void FUN_006d3ae0(float f);
    void FUN_006e2b20(void* actor);
    void SetByteAtOffset9B(int a);
    void SetFlagA3(bool b);
    void SetCantOpenDoors(bool b);
    void SetCanSwim(bool b);
    void FUN_006e2b90(bool b);
    void SetByteAtA1(int a);
};
struct S_FUN_006b05a0
{
    void* PathingSolution_GetLastNode();
};
struct ContNode;
ContNode* __fastcall FUN_00717e50(void* p);
struct Sol13
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
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    Sol13();
    ~Sol13();
    unsigned int GetObjectFlags();
    float GetTotalPathLength();
    NiPoint3 GetPointAtDistance(float a, float b);
};
bool __cdecl FUN_006d0900(Helper13* h, Sol13* s);

} // namespace fnv_009de8b0

// @fnv 0x009de8b0
void ActorMover::UpdateTargeting()
{
    using namespace fnv_009de8b0;
    if (m_pPathHandler != 0)
    {
        if (((NiPointer<PathingSolution>*)&m_pPathHandler->pCurrentPathingSolution)->operator->() != 0)
        {
            if (m_pPathHandler->vf29())
            {
                FUN_00483710();
                return;
            }
        }
    }
    unsigned long bA4;
    unsigned int zX;
    bool iAB;
    iAB = false;
    if ((PathingRequest*)request == 0)
        return;
    if (((Actor13*)pActor)->Actor_IsFollowing_008bc7f0(g_thePlayer))
    {
        if (m_pPathHandler != 0)
        {
            if (((NiPointer<PathingSolution>*)&m_pActorNode)->operator->() != 0)
            {
                if (!m_pPathHandler->vfn_34())
                {
                    if (!GetPathingSolutionFlag40((PathingSolution*)((NiPointer<PathingSolution>*)&m_pActorNode)->operator->()))
                    {
                        ((Actor13*)pActor)->Actor_InitiateMovementBlockedPackage();
                        return;
                    }
                }
            }
        }
        if (((Actor13*)pActor)->GetPos()->SubtractIntoVector(g_thePlayer->GetPos()).NiPoint3_XYLength() >
            ((Req*)(PathingRequest*)request)->FUN_009b0bd0() * 2)
            iAB = true;
    }
    if (((Actor13*)pActor)->FUN_00931850() == 0)
    {
        bA4 = ((Req*)(PathingRequest*)request)->GetOffsetC()->FUN_006dd4f0();
        zX = ((Req*)(PathingRequest*)request)->NiAVObject_GetRotate_006a9540()->FUN_006dd4f0();
        if (0 != bA4 && 0 != zX)
        {
            bool resultB;
            resultB = g_TES->GetCellHeightAtPosition(&((Req*)(PathingRequest*)request)->GetOffsetC()->FUN_005c3420(), bA4) >
                      ((Req*)(PathingRequest*)request)->GetOffsetC()->FUN_005c3420().z;
            bool y6;
            y6 = g_TES->GetCellHeightAtPosition(&((Req*)(PathingRequest*)request)->NiAVObject_GetRotate_006a9540()->FUN_005c3420(), zX) >
                 ((Req*)(PathingRequest*)request)->NiAVObject_GetRotate_006a9540()->FUN_005c3420().z;
            if (resultB != y6)
                iAB = true;
        }
        PLoc aLoc4(((Actor13*)pActor));
        aLoc4.FUN_006dd6f0(0);
        if (!aLoc4.FUN_006dd6a0())
            iAB = true;
    }
    if (iAB)
    {
        Helper13 solution4;
        solution4.AssignPathingLocation(((Req*)(PathingRequest*)request)->NiAVObject_GetRotate_006a9540());
        solution4.FUN_006d1bc0(((Actor13*)pActor));
        solution4.FUN_006d3b00(10.0f);
        solution4.FUN_006d3ae0((float)(((Actor13*)pActor)->Actor_GetWidth() * (double)0.6f));
        solution4.FUN_006e2b20(((Actor13*)pActor));
        solution4.SetByteAtOffset9B(1);
        solution4.SetFlagA3(true);
        solution4.SetCantOpenDoors(false);
        solution4.SetCanSwim(((Actor13*)pActor)->FUN_004181e0()->DoesSwim());
        solution4.FUN_006e2b90(((Actor13*)pActor)->FUN_004181e0()->DoesFly());
        solution4.SetByteAtA1(1);
        NiPoint3 idx;
        void* _limitA;
        _limitA = g_thePlayer->FUN_008d6f30();
        {
            Sol13 bB4;
            if (FUN_006d0900(&solution4, &bB4))
            {
                if (bB4.GetObjectFlags() >= 2)
                {
                    float iB2;
                    iB2 = 128.0f;
                    if (((Actor13*)pActor)->Actor_GetWidth() * (double)0.5f > 100.0)
                        iB2 = _runtimeFloatSettingDefault38;
                    float i4;
                    i4 = bB4.GetTotalPathLength();
                    float cell3;
                    cell3 = i4 - iB2;
                    if (cell3 < _gModifierZero)
                        cell3 = (float)(i4 * (double)0.5f);
                    memcpy(&idx, &bB4.GetPointAtDistance(0.0f, cell3), sizeof(idx));
                }
                else
                {
                    return;
                }
            }
            else
            {
                if (bB4.GetObjectFlags() == 0)
                {
                    return;
                }
                else
                {
                    memcpy(&idx, &((PLoc*)FUN_00717e50(((S_FUN_006b05a0*)&bB4)->PathingSolution_GetLastNode()))->FUN_005c3420(), sizeof(idx));
                }
            }
            FUN_00483710();
            if (((Actor13*)pActor)->Actor_IsFollowing_008bc7f0(g_thePlayer) &&
                TESObjectREFR_GetWorldSpace((TESObjectREFR*)((Actor13*)pActor)) != TESObjectREFR_GetWorldSpace((TESObjectREFR*)g_thePlayer))
            {
                TESObjectREFR_MoveRefToNewSpace(((Actor13*)pActor), g_thePlayer->FUN_008d6f30(), TESObjectREFR_GetWorldSpace((TESObjectREFR*)g_thePlayer));
                ((Actor13*)pActor)->Call2a8((NiPoint3*)&idx);
            }
            else
            {
                MoveActorToLocation(*(NiPoint3*)&idx);
            }
        }
    }
}

struct TimeGlobal
{
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;
struct SavedRequest
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual unsigned char GetType();
    virtual void v14();
    virtual void Save(BGSSaveFormBuffer*);
};
struct SavedSolution
{
    void FUN_006e8b10(BGSSaveFormBuffer*);
};
struct SavedLocation
{
    virtual void Save(BGSSaveFormBuffer*);
};

// Writes movement, pathing, state and timing fields to the save buffer, then saves the location, reference, request, path and handler.
// @fnv 0x009df100
// src: XBOX_PDB 0x009df100
void ActorMover::SaveGame_009df100(BGSSaveFormBuffer* buffer)
{
    buffer->FUN_00865e50(&currentNode, 2, 0);
    buffer->FUN_00865e50(&lastNode, 2, 0);
    buffer->FUN_00865e50(&bPathingFailed, 1, 0);
    buffer->FUN_00865e50(&unk34, 4, 0);
    buffer->FUN_00865e50(&m_bHasMovementData, 1, 0);
    buffer->FUN_00865e50(&m_uiMovementFlags, 4, 0);
    buffer->FUN_00865e50(&m_bMovementComplete, 1, 0);
    buffer->FUN_00865e50(&m_bHasLookAtTarget, 1, 0);
    buffer->FUN_00865e50(&m_kLookAtTargetPosition, 12, 0);
    buffer->FUN_00865e50(&m_kPathingDelta, 12, 0);
    buffer->FUN_00865e50(&m_uiMovementMode, 4, 0);
    buffer->FUN_00865e50(&m_bMovementActive, 1, 0);
    buffer->FUN_00865e50(&m_bMovementStateFlag, 1, 0);
    buffer->FUN_00865e50(&m_bHasPathingDelta, 1, 0);
    buffer->FUN_00865e50(&m_bMovementPaused, 1, 0);
    buffer->FUN_00865e50(&unk78, 1, 0);
    buffer->FUN_00865e50(&eState, 4, 0);
    unsigned int elapsed = g_timeGlobal.GetTimeStamp() - lastTime;
    buffer->FUN_00865e50(&elapsed, 4, 0);
    buffer->FUN_00865e50(&retries, 4, 0);
    ((SavedLocation*)&m_pathingLocation)->Save(buffer);
    buffer->FUN_00865db0(unk2C, 0);
    unsigned char flags = 0;
    if (((NiPointer<SavedRequest>*)&request)->operator->())
        flags |= 1;
    if (((NiPointer<SavedSolution>*)&m_pActorNode)->operator->())
        flags |= 2;
    if (m_pPathHandler)
        flags |= m_pPathHandler->vfn_34() ? 8 : 4;
    buffer->FUN_00865e50(&flags, 1, 0);
    if (((NiPointer<SavedRequest>*)&request)->operator->())
    {
        unsigned char type = ((NiPointer<SavedRequest>*)&request)->operator->()->GetType();
        buffer->FUN_00865e50(&type, 1, 0);
        ((NiPointer<SavedRequest>*)&request)->operator->()->Save(buffer);
    }
    if (((NiPointer<SavedSolution>*)&m_pActorNode)->operator->())
        ((NiPointer<SavedSolution>*)&m_pActorNode)->operator->()->FUN_006e8b10(buffer);
    if (m_pPathHandler)
        m_pPathHandler->Save(buffer);
}

namespace loadpath {
struct Buffer
{
    virtual unsigned char Version();
    void Read(void*, unsigned int);
    void ReadRef(void*);
};
struct Clock
{
    unsigned int Now();
};
extern Clock g_timeGlobal;
struct ObjectResolver
{
    void* Resolve();
};
struct Node
{
    bool Valid();
    ObjectResolver* Data();
};
struct Solution
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Solution();
    int a00;
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
    void FUN_006e8d50(Buffer*);
    unsigned int PathingSolution_GetVirtualNodeCount();
    Node* GetVirtualNode_006e78b0(unsigned int);
};
struct Request
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Load(Buffer*);
    void Attach(void*);
};
Request* MakeRequest(unsigned int);
struct ProcessFlags
{
    bool Test(int);
};
struct Process
{
    int a00;
    ProcessFlags flags;
};
struct Location
{
    virtual void v00();
    virtual void Load(Buffer*);
};

struct VirtualHandler : ActorPathHandler
{
    VirtualHandler(Actor*, ActorMover*, NiPointer<Solution>&, Request*);
    int a14;
    int a18;
    int a1c;
};
struct NormalHandler : ActorPathHandler
{
    NormalHandler(Actor*, ActorMover*, NiPointer<Solution>&, Request*);
    int a14;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
    int a44;
    int a48;
    int a4c;
    int a50;
    int a54;
    int a58;
    int a5c;
    int a60;
    int a64;
    int a68;
    int a6c;
    int a70;
    int a74;
    int a78;
    int a7c;
    int a80;
    int a84;
    int a88;
    int a8c;
    int a90;
    int a94;
    int a98;
    int a9c;
    int aa0;
    int aa4;
    int aa8;
    int aac;
    int ab0;
    int ab4;
    int ab8;
    int abc;
    int ac0;
    int ac4;
    int ac8;
    int acc;
    int ad0;
    int ad4;
    int ad8;
    int adc;
    int ae0;
};
void Warning(const char*, ...);

// Reads the mover's saved fields from a buffer, reconstructs its request, path and handler, and forces a failure if the path is stale.
} // namespace loadpath

// @fnv 0x009df3d0
// src: XBOX_PDB 0x009df3d0
void ActorMover::LoadGame_009df3d0(BGSLoadFormBuffer* buffer)
{
    using namespace loadpath;
    ((loadpath::Buffer*)buffer)->Read(&currentNode, 2);
    ((loadpath::Buffer*)buffer)->Read(&lastNode, 2);
    ((loadpath::Buffer*)buffer)->Read(&bPathingFailed, 1);
    ((loadpath::Buffer*)buffer)->Read(&unk34, 4);
    ((loadpath::Buffer*)buffer)->Read(&m_bHasMovementData, 1);
    ((loadpath::Buffer*)buffer)->Read(&m_uiMovementFlags, 4);
    ((loadpath::Buffer*)buffer)->Read(&m_bMovementComplete, 1);
    ((loadpath::Buffer*)buffer)->Read(&m_bHasLookAtTarget, 1);
    ((loadpath::Buffer*)buffer)->Read(&m_kLookAtTargetPosition, 12);
    ((loadpath::Buffer*)buffer)->Read(&m_kPathingDelta, 12);
    ((loadpath::Buffer*)buffer)->Read(&m_uiMovementMode, 4);
    ((loadpath::Buffer*)buffer)->Read(&m_bMovementActive, 1);
    ((loadpath::Buffer*)buffer)->Read(&m_bMovementStateFlag, 1);
    ((loadpath::Buffer*)buffer)->Read(&m_bHasPathingDelta, 1);
    ((loadpath::Buffer*)buffer)->Read(&m_bMovementPaused, 1);
    ((loadpath::Buffer*)buffer)->Read(&unk78, 1);
    ((loadpath::Buffer*)buffer)->Read(&eState, 4);
    if (((loadpath::Buffer*)buffer)->Version() >= 14)
    {
        unsigned int uiSavedTime = 0;
        ((loadpath::Buffer*)buffer)->Read(&uiSavedTime, 4);
        if (uiSavedTime < loadpath::g_timeGlobal.Now())
            lastTime = loadpath::g_timeGlobal.Now() - uiSavedTime;
        ((loadpath::Buffer*)buffer)->Read(&retries, 4);
    }
    if (((loadpath::Buffer*)buffer)->Version() >= 7)
        ((loadpath::Location*)&m_pathingLocation)->Load((loadpath::Buffer*)buffer);
    ((loadpath::Buffer*)buffer)->ReadRef(&unk2C);
    unsigned char uiStaleFlags = 0;
    ((loadpath::Buffer*)buffer)->Read(&uiStaleFlags, 1);
    if (uiStaleFlags & 1)
    {
        unsigned char uiRequestKind = 0;
        ((loadpath::Buffer*)buffer)->Read(&uiRequestKind, 1);
        ((NiPointer<loadpath::Request>*)&request)->operator=(MakeRequest(uiRequestKind));
        ((loadpath::Request*)*(NiPointer<loadpath::Request>*)&request)->Load((loadpath::Buffer*)buffer);
        if (pActor && pActor->GetProcess() && !reinterpret_cast<loadpath::Process*>(pActor->GetProcess())->flags.Test(0))
            ((loadpath::Request*)*(NiPointer<loadpath::Request>*)&request)->Attach(pActor);
    }
    bool flags = false;
    if (uiStaleFlags & 2)
    {
        ((NiPointer<loadpath::Solution>*)&m_pActorNode)->operator=(new Solution);
        ((loadpath::Solution*)*(NiPointer<loadpath::Solution>*)&m_pActorNode)->FUN_006e8d50((loadpath::Buffer*)buffer);
        for (unsigned int index = 0; index < ((loadpath::Solution*)*(NiPointer<loadpath::Solution>*)&m_pActorNode)->PathingSolution_GetVirtualNodeCount(); ++index)
        {
            if (((loadpath::Solution*)*(NiPointer<loadpath::Solution>*)&m_pActorNode)->GetVirtualNode_006e78b0(index)->Valid() &&
                !((ObjectResolver*)((loadpath::Solution*)*(NiPointer<loadpath::Solution>*)&m_pActorNode)->GetVirtualNode_006e78b0(index)->Data())->Resolve())
            {
                Warning("PATHFINDING: Actor %s (0x%08x) is using a stale path (the navmesh changed), forcing a failure",
                        pActor->GetName(), pActor->ID());
                flags = true;
                break;
            }
        }
    }
    if (uiStaleFlags & 4)
    {
        m_pPathHandler = new VirtualHandler(pActor, this, *(NiPointer<loadpath::Solution>*)&m_pActorNode, *(NiPointer<loadpath::Request>*)&request);
    }
    else if (uiStaleFlags & 8)
    {
        m_pPathHandler = new NormalHandler(pActor, this, *(NiPointer<loadpath::Solution>*)&m_pActorNode, *(NiPointer<loadpath::Request>*)&request);
    }
    if (m_pPathHandler)
        m_pPathHandler->Load(buffer);
    if (flags)
    {
        ActorMover_ClearCurrentData();
        eState = 7;
        SetEnabled(1);
    }
}

struct Process884750
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual bool IsBusy();
};
// Keep the unsupported no-argument call at 0x0047c850 without a local Actor copy.
bool __fastcall IsActorLoading(Actor*);
extern Actor* g_thePlayer;

// Returns false if the actor is loading, has anim action 7, or is the busy player, otherwise true.
// @fnv 0x00884750
bool __fastcall IsActorReadyForMovement(Actor* actor)
{
    if (IsActorLoading(actor))
        return false;
    int iAction = actor->GetAnimAction();
    if (iAction == 7)
        return false;
    if (actor == g_thePlayer && actor->m_pBaseProcess &&
        reinterpret_cast<Process884750*>(actor->m_pBaseProcess)->IsBusy())
        return false;
    return true;
}

struct PathManager
{
    PathManager();
    virtual ~PathManager();
};
extern PathManager DAT_011c5290;
void __cdecl FUN_00fc8480();
void __cdecl _atexit(void(__cdecl*)(void));
// Returns a pointer to a function-local static PathManager.
// @fnv 0x0047d0b0
PathManager* __cdecl GetPathManager()
{
    static PathManager pManager;
    return &pManager;
}

// Actor.h lacks these no-argument movement queries (0x0050d4a0/0x008eea60).
bool __fastcall HasActorMovementAnimation(Actor*);

bool __fastcall CanActorUseMovementMode400(Actor*);

struct FrameMoveTimeView14
{
    float FUN_0084d030();
};
struct TimeGlobal;
extern TimeGlobal g_timeGlobal;

class FUN_00491040_shell
{
  public:
    BSAnimGroupSequence* Animation_GetCurrentSequence(int section);
};

class AnimData : public FUN_00491040_shell
{
  public:
    void GetMovement(NiPoint3* outDelta, Actor* actor, int a3, int a4);
    bool IsHighestPriority();
};

// Computes the actor's movement delta from animation or pathing, adjusts movement mode flags, and stores the result in m_kPathingDelta.
// @fnv 0x009ddc00
// src: XBOX_PDB 0x009ddc00
void ActorMover::SetCurrentFrameMoveModeAndDelta()
{
    bool bHaveValidDelta = false;
    unsigned int mode = 0;
    // Keep the original raw initialization and copies without outlining the empty constructor.
    void* moveDelta[sizeof(NiPoint3) / sizeof(void*)];
    memcpy(&moveDelta, &NiPoint3_ZERO, sizeof(NiPoint3));

    if (this->m_bHasMovementData)
    {
        mode = this->m_uiMovementFlags;
        AnimData* anim = this->pActor->GetAnimData();
        if (anim)
        {
            if (HasActorMovementAnimation(this->pActor))
            {
                anim->GetMovement((NiPoint3*)&moveDelta, this->pActor, 1, 0);
            }
            else
            {
                anim->GetMovement((NiPoint3*)&moveDelta, this->pActor, 0, 1);
            }
        }
        else
        {
            if (!this->pActor->IsVisible(7))
            {
                memcpy(&moveDelta, &NiPoint3(0.0f,
                                       this->pActor->GetCurrentMovementSpeed() *
                                           ((FrameMoveTimeView14*)&g_timeGlobal)->FUN_0084d030(),
                                       0.0f), sizeof(NiPoint3));
            }
        }
        bHaveValidDelta = true;
    }
    else
    {
        if (this->m_pPathHandler)
        {
            mode = this->m_pPathHandler->GetActorStateFlags();
            if (this->m_pPathHandler->GetPathingDelta((NiPoint3*)&moveDelta))
            {
                bHaveValidDelta = true;
            }
            if (this->unk78)
            {
                mode &= ~0xF;
                memcpy(&moveDelta, &NiPoint3_ZERO, sizeof(NiPoint3));
                bHaveValidDelta = true;
                switch (this->pActor->GetAnimAction_008a7570())
                {
                case 0xc:
                case 0xd:
                case 0xe:
                    this->unk78 = false;
                    bHaveValidDelta = false;
                    break;
                default:
                    AnimData* anim = this->pActor->GetAnimData();
                    if (!anim || !anim->IsHighestPriority())
                    {
                        this->unk78 = false;
                    }
                    break;
                }
            }
        }
    }

    if (mode & 0x200)
    {
        if (!IsActorReadyForMovement(this->pActor))
        {
            mode &= ~0x200;
            mode |= 0x100;
        }
    }

    if (mode & 0x400)
    {
        if (!CanActorUseMovementMode400(this->pActor))
        {
            mode &= ~0x400;
        }
    }

    if ((mode & 0x400) != (this->m_uiMovementMode & 0x400))
    {
        AnimData* anim = this->pActor->GetAnimData();
        if (!anim || (anim->Animation_GetCurrentSequence(0) && anim->Animation_GetCurrentSequence(0)->GetState() != 1) ||
            (anim->Animation_GetCurrentSequence(1) && anim->Animation_GetCurrentSequence(1)->GetState() != 1) ||
            (anim->Animation_GetCurrentSequence(4) && anim->Animation_GetCurrentSequence(4)->GetState() != 1) ||
            this->pActor->GetAnimAction_008a7570() != -1)
        {
            mode &= ~0x400;
            mode |= (this->m_uiMovementMode & 0x400);
        }
    }

    this->m_uiMovementMode = mode;
    memcpy(&this->m_kPathingDelta, &moveDelta, sizeof(NiPoint3));
    this->m_bHasPathingDelta = bHaveValidDelta;
    FUN_00483710();
}

class BackgroundPathLocation14
{
  public:
    bool PathingLocation_QUnused();
    unsigned int FUN_006dd4f0() const;
    void* FUN_00441110();
    NiPoint3 FUN_005c3420() const;
    void FUN_006ddbe0();
};

struct Cell14
{
    bool FUN_00425fd0();
};

struct MobileObject_Helper
{
    float GetRelevantWaterHeight() const;
    void* FUN_008d6f30();
};

namespace std {
float abs(float);
}

#include "../../../../include/NiMemObject.h"

class BackgroundPathRequest14
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual unsigned int vfn_10();
    BackgroundPathLocation14& GetOffsetC();
    BackgroundPathLocation14* NiAVObject_GetRotate_006a9540();
    float FUN_009b0bd0() const;
    float GetSmoothingRandomness();
    bool TESCombatStyle_GetPowerAttackF();
    float BGSProjectile_GetMuzzleFlashDuration();
    void FUN_006e2b20(void*);
    void FUN_009db930(unsigned int);
    void IncRefCount();
    void DecRefCount();
};

// Subclasses of BackgroundPathRequest14: size in bytes minus 4 (for BackgroundPathRequest14 vtable)
// FUN_006e26a0: 0xb0 total -> 0xac
struct FUN_006e26a0 : public NiMemObject, public BackgroundPathRequest14
{
    FUN_006e26a0(const BackgroundPathRequest14*);
    int pad0_00;
    int pad0_01;
    int pad0_02;
    int pad0_03;
    int pad0_04;
    int pad0_05;
    int pad0_06;
    int pad0_07;
    int pad0_08;
    int pad0_09;
    int pad0_0a;
    int pad0_0b;
    int pad0_0c;
    int pad0_0d;
    int pad0_0e;
    int pad0_0f;
    int pad0_10;
    int pad0_11;
    int pad0_12;
    int pad0_13;
    int pad0_14;
    int pad0_15;
    int pad0_16;
    int pad0_17;
    int pad0_18;
    int pad0_19;
    int pad0_1a;
    int pad0_1b;
    int pad0_1c;
    int pad0_1d;
    int pad0_1e;
    int pad0_1f;
    int pad0_20;
    int pad0_21;
    int pad0_22;
    int pad0_23;
    int pad0_24;
    int pad0_25;
    int pad0_26;
    int pad0_27;
    int pad0_28;
    int pad0_29;
    int pad0_2a;
};

// FUN_006e5400: 0xb4 total -> 0xb0
struct FUN_006e5400 : public NiMemObject, public BackgroundPathRequest14
{
    FUN_006e5400(const BackgroundPathRequest14*);
    int pad3_00;
    int pad3_01;
    int pad3_02;
    int pad3_03;
    int pad3_04;
    int pad3_05;
    int pad3_06;
    int pad3_07;
    int pad3_08;
    int pad3_09;
    int pad3_0a;
    int pad3_0b;
    int pad3_0c;
    int pad3_0d;
    int pad3_0e;
    int pad3_0f;
    int pad3_10;
    int pad3_11;
    int pad3_12;
    int pad3_13;
    int pad3_14;
    int pad3_15;
    int pad3_16;
    int pad3_17;
    int pad3_18;
    int pad3_19;
    int pad3_1a;
    int pad3_1b;
    int pad3_1c;
    int pad3_1d;
    int pad3_1e;
    int pad3_1f;
    int pad3_20;
    int pad3_21;
    int pad3_22;
    int pad3_23;
    int pad3_24;
    int pad3_25;
    int pad3_26;
    int pad3_27;
    int pad3_28;
    int pad3_29;
    int pad3_2a;
    int pad3_2b;
};

// FUN_006e5640: 0xdc total -> 0xd8
struct FUN_006e5640 : public NiMemObject, public BackgroundPathRequest14
{
    FUN_006e5640(const BackgroundPathRequest14*);
    int pad4_00;
    int pad4_01;
    int pad4_02;
    int pad4_03;
    int pad4_04;
    int pad4_05;
    int pad4_06;
    int pad4_07;
    int pad4_08;
    int pad4_09;
    int pad4_0a;
    int pad4_0b;
    int pad4_0c;
    int pad4_0d;
    int pad4_0e;
    int pad4_0f;
    int pad4_10;
    int pad4_11;
    int pad4_12;
    int pad4_13;
    int pad4_14;
    int pad4_15;
    int pad4_16;
    int pad4_17;
    int pad4_18;
    int pad4_19;
    int pad4_1a;
    int pad4_1b;
    int pad4_1c;
    int pad4_1d;
    int pad4_1e;
    int pad4_1f;
    int pad4_20;
    int pad4_21;
    int pad4_22;
    int pad4_23;
    int pad4_24;
    int pad4_25;
    int pad4_26;
    int pad4_27;
    int pad4_28;
    int pad4_29;
    int pad4_2a;
    int pad4_2b;
    int pad4_2c;
    int pad4_2d;
    int pad4_2e;
    int pad4_2f;
    int pad4_30;
    int pad4_31;
    int pad4_32;
    int pad4_33;
    int pad4_34;
    int pad4_35;
};

// PathingRequestLOS.h lacks the constructor taking const PathingRequest* at 0x006e5940.
// Retain this construction view until that overload is available (0xd8 total).
struct FUN_006e5940 : public NiMemObject, public BackgroundPathRequest14
{
    FUN_006e5940(const BackgroundPathRequest14*);
    int pad5_00;
    int pad5_01;
    int pad5_02;
    int pad5_03;
    int pad5_04;
    int pad5_05;
    int pad5_06;
    int pad5_07;
    int pad5_08;
    int pad5_09;
    int pad5_0a;
    int pad5_0b;
    int pad5_0c;
    int pad5_0d;
    int pad5_0e;
    int pad5_0f;
    int pad5_10;
    int pad5_11;
    int pad5_12;
    int pad5_13;
    int pad5_14;
    int pad5_15;
    int pad5_16;
    int pad5_17;
    int pad5_18;
    int pad5_19;
    int pad5_1a;
    int pad5_1b;
    int pad5_1c;
    int pad5_1d;
    int pad5_1e;
    int pad5_1f;
    int pad5_20;
    int pad5_21;
    int pad5_22;
    int pad5_23;
    int pad5_24;
    int pad5_25;
    int pad5_26;
    int pad5_27;
    int pad5_28;
    int pad5_29;
    int pad5_2a;
    int pad5_2b;
    int pad5_2c;
    int pad5_2d;
    int pad5_2e;
    int pad5_2f;
    int pad5_30;
    int pad5_31;
    int pad5_32;
    int pad5_33;
    int pad5_34;
};

// FUN_006e6010: 0xbc total -> 0xb8
struct FUN_006e6010 : public NiMemObject, public BackgroundPathRequest14
{
    FUN_006e6010(const BackgroundPathRequest14*);
    int pad6_00;
    int pad6_01;
    int pad6_02;
    int pad6_03;
    int pad6_04;
    int pad6_05;
    int pad6_06;
    int pad6_07;
    int pad6_08;
    int pad6_09;
    int pad6_0a;
    int pad6_0b;
    int pad6_0c;
    int pad6_0d;
    int pad6_0e;
    int pad6_0f;
    int pad6_10;
    int pad6_11;
    int pad6_12;
    int pad6_13;
    int pad6_14;
    int pad6_15;
    int pad6_16;
    int pad6_17;
    int pad6_18;
    int pad6_19;
    int pad6_1a;
    int pad6_1b;
    int pad6_1c;
    int pad6_1d;
    int pad6_1e;
    int pad6_1f;
    int pad6_20;
    int pad6_21;
    int pad6_22;
    int pad6_23;
    int pad6_24;
    int pad6_25;
    int pad6_26;
    int pad6_27;
    int pad6_28;
    int pad6_29;
    int pad6_2a;
    int pad6_2b;
    int pad6_2c;
    int pad6_2d;
};

// FUN_006e5db0: 0xc0 total -> 0xbc
struct FUN_006e5db0 : public NiMemObject, public BackgroundPathRequest14
{
    FUN_006e5db0(const BackgroundPathRequest14*);
    int pad7_00;
    int pad7_01;
    int pad7_02;
    int pad7_03;
    int pad7_04;
    int pad7_05;
    int pad7_06;
    int pad7_07;
    int pad7_08;
    int pad7_09;
    int pad7_0a;
    int pad7_0b;
    int pad7_0c;
    int pad7_0d;
    int pad7_0e;
    int pad7_0f;
    int pad7_10;
    int pad7_11;
    int pad7_12;
    int pad7_13;
    int pad7_14;
    int pad7_15;
    int pad7_16;
    int pad7_17;
    int pad7_18;
    int pad7_19;
    int pad7_1a;
    int pad7_1b;
    int pad7_1c;
    int pad7_1d;
    int pad7_1e;
    int pad7_1f;
    int pad7_20;
    int pad7_21;
    int pad7_22;
    int pad7_23;
    int pad7_24;
    int pad7_25;
    int pad7_26;
    int pad7_27;
    int pad7_28;
    int pad7_29;
    int pad7_2a;
    int pad7_2b;
    int pad7_2c;
    int pad7_2d;
    int pad7_2e;
};

// FUN_006e4d20: 0x10c total -> 0x108
struct FUN_006e4d20 : public NiMemObject, public BackgroundPathRequest14
{
    FUN_006e4d20(const BackgroundPathRequest14*);
    int pad8_00;
    int pad8_01;
    int pad8_02;
    int pad8_03;
    int pad8_04;
    int pad8_05;
    int pad8_06;
    int pad8_07;
    int pad8_08;
    int pad8_09;
    int pad8_0a;
    int pad8_0b;
    int pad8_0c;
    int pad8_0d;
    int pad8_0e;
    int pad8_0f;
    int pad8_10;
    int pad8_11;
    int pad8_12;
    int pad8_13;
    int pad8_14;
    int pad8_15;
    int pad8_16;
    int pad8_17;
    int pad8_18;
    int pad8_19;
    int pad8_1a;
    int pad8_1b;
    int pad8_1c;
    int pad8_1d;
    int pad8_1e;
    int pad8_1f;
    int pad8_20;
    int pad8_21;
    int pad8_22;
    int pad8_23;
    int pad8_24;
    int pad8_25;
    int pad8_26;
    int pad8_27;
    int pad8_28;
    int pad8_29;
    int pad8_2a;
    int pad8_2b;
    int pad8_2c;
    int pad8_2d;
    int pad8_2e;
    int pad8_2f;
    int pad8_30;
    int pad8_31;
    int pad8_32;
    int pad8_33;
    int pad8_34;
    int pad8_35;
    int pad8_36;
    int pad8_37;
    int pad8_38;
    int pad8_39;
    int pad8_3a;
    int pad8_3b;
    int pad8_3c;
    int pad8_3d;
    int pad8_3e;
    int pad8_3f;
    int pad8_40;
    int pad8_41;
};

struct PathManager14
{
    bool BuildPath(NiPointer<BackgroundPathRequest14>, NiPointer<ActorPathingMessageQueue>, bool);
};

struct PathManager;
PathManager* __cdecl GetPathManager();
bool __fastcall TESObjectCELL_GetAttached(void*);
void __cdecl DetailedActorPathHandler_UpdateAvoidNodesForPath(void*, BackgroundPathRequest14*, void*);
void __fastcall ActorMover_ClearCurrentData(TESForm*);

extern PlayerCharacter* _g_thePlayer;

// Builds a request from apRequest, notifies the handler when present, then submits it to the path manager or returns early.
// @fnv 0x009db090
// src: XBOX_PDB 0x009db090
bool ActorMover::BackGroundBuildPath(const PathingRequest* apRequest)
{
    bool result5 = false;
    bool sleeping;
    ((BackgroundPathRequest14*)apRequest)->vfn_0c();
    eState = 1;
    ResetMoverState(0);
    if (!((BackgroundPathRequest14*)apRequest)->NiAVObject_GetRotate_006a9540()->PathingLocation_QUnused())
    {
        BackgroundPathLocation14* locA5 = &((BackgroundPathRequest14*)apRequest)->GetOffsetC();
        BackgroundPathLocation14* locB2 = ((BackgroundPathRequest14*)apRequest)->NiAVObject_GetRotate_006a9540();
        unsigned int cell2 = locA5->FUN_006dd4f0();
        bool bNotInterior2 = !(cell2 != 0 && ((Cell14*)cell2)->FUN_00425fd0());
        bool same3 =
            bNotInterior2 ? (locA5->FUN_00441110() == locB2->FUN_00441110()) : (cell2 == locB2->FUN_006dd4f0());
        bool zA3 = (locA5->FUN_005c3420().z < ((MobileObject_Helper*)pActor)->GetRelevantWaterHeight() + 50.0f);
        bool zB9 = (locB2->FUN_005c3420().z < ((MobileObject_Helper*)pActor)->GetRelevantWaterHeight() + 50.0f);
        if (same3 && !zA3 && !zB9)
        {
            NiPoint3 diff8 = locA5->FUN_005c3420() - locB2->FUN_005c3420();
            if ((double)((const NiPoint3*)&diff8)->GetSquaredXYLength() <=
                (double)((BackgroundPathRequest14*)apRequest)->FUN_009b0bd0() *
                    (double)((BackgroundPathRequest14*)apRequest)->FUN_009b0bd0())
            {
                if ((double)std::abs(diff8.z) <= (double)((BackgroundPathRequest14*)apRequest)->GetSmoothingRandomness())
                {
                    FinishMoving(1);
                    bool flag = true;
                    if (((BackgroundPathRequest14*)apRequest)->TESCombatStyle_GetPowerAttackF())
                    {
                        flag = RequestRotateActor_009dce80(((BackgroundPathRequest14*)apRequest)->BGSProjectile_GetMuzzleFlashDuration(), true);
                    }
                    return flag;
                }
            }
        }
    }
    switch (((BackgroundPathRequest14*)apRequest)->vfn_10())
    {
    case 0: {
        (*(NiPointer<BackgroundPathRequest14>*)&request) = new FUN_006e26a0((const BackgroundPathRequest14*)apRequest);
        break;
    }
    case 3: {
        (*(NiPointer<BackgroundPathRequest14>*)&request) = new FUN_006e5400((const BackgroundPathRequest14*)apRequest);
        break;
    }
    case 4: {
        (*(NiPointer<BackgroundPathRequest14>*)&request) = new FUN_006e5640((const BackgroundPathRequest14*)apRequest);
        break;
    }
    case 5: {
        (*(NiPointer<BackgroundPathRequest14>*)&request) = new FUN_006e5940((const BackgroundPathRequest14*)apRequest);
        break;
    }
    case 6: {
        (*(NiPointer<BackgroundPathRequest14>*)&request) = new FUN_006e6010((const BackgroundPathRequest14*)apRequest);
        break;
    }
    case 7: {
        (*(NiPointer<BackgroundPathRequest14>*)&request) = new FUN_006e5db0((const BackgroundPathRequest14*)apRequest);
        break;
    }
    case 8: {
        (*(NiPointer<BackgroundPathRequest14>*)&request) = new FUN_006e4d20((const BackgroundPathRequest14*)apRequest);
        break;
    }
    }
    ((BackgroundPathRequest14*)(*(NiPointer<BackgroundPathRequest14>*)&request))->GetOffsetC().FUN_006ddbe0();
    ((BackgroundPathRequest14*)(*(NiPointer<BackgroundPathRequest14>*)&request))->NiAVObject_GetRotate_006a9540()->FUN_006ddbe0();
    ((BackgroundPathRequest14*)(*(NiPointer<BackgroundPathRequest14>*)&request))->FUN_006e2b20(((MobileObject_Helper*)pActor));
    DebugOnStopMoving();
    ((BackgroundPathRequest14*)(*(NiPointer<BackgroundPathRequest14>*)&request))->FUN_009db930(retries + 3);
    if (!bPathingFailed && m_pPathHandler != 0)
    {
        m_pPathHandler->vfn_38((PathingRequest*)(BackgroundPathRequest14*)(*(NiPointer<BackgroundPathRequest14>*)&request));
    }
    if (m_pPathHandler != 0 && m_pPathHandler->vfn_34())
    {
        DetailedActorPathHandler_UpdateAvoidNodesForPath(((MobileObject_Helper*)pActor), (BackgroundPathRequest14*)(*(NiPointer<BackgroundPathRequest14>*)&request), m_pPathHandler);
    }
    else
    {
        if (((MobileObject_Helper*)pActor)->FUN_008d6f30() != 0)
        {
            if (TESObjectCELL_GetAttached(((MobileObject_Helper*)pActor)->FUN_008d6f30()))
            {
                DetailedActorPathHandler_UpdateAvoidNodesForPath(((MobileObject_Helper*)pActor), (BackgroundPathRequest14*)(*(NiPointer<BackgroundPathRequest14>*)&request), 0);
            }
        }
    }
    {
        sleeping = _g_thePlayer->IsSleepingOrResting();
        if ((ActorPathingMessageQueue*)m_queue == 0)
        {
            m_queue = new ActorPathingMessageQueue();
        }
        if (!((PathManager14*)GetPathManager())->BuildPath((*(NiPointer<BackgroundPathRequest14>*)&request), m_queue, !sleeping))
        {
            (::ActorMover_ClearCurrentData)((TESForm*)this);
            eState = 7;
            SetEnabled(1);
        }
        else
        {
            m_bMovementActive = 1;
            result5 = true;
        }
    }
    return result5;
}

bool IsConditionMet();

struct TaskQueueInterface
{
    static TaskQueueInterface* GetInstance();
};

struct FUN_0087b650_shell
{
    void QueueActorLocationTask(Actor*, const NiPoint3*);
};

struct FUN_0087b190_shell
{
    void QueueActorTask(Actor*);
};

struct SetLoc_S
{
    void SetLocationOnReference(const NiPoint3&);
};

struct PlayerSleepView
{
    bool IsSleepingOrResting();
};
struct TESWorldSpace_SV
{
    TESObjectCELL* GetCellByWorldPosition(const NiPoint3&);
};

struct TESObjectREFR_Ext : TESObjectREFR
{
    static void SetParentCellAndWorldspace(TESObjectREFR*, TESObjectCELL*, TESWorldSpace_SV*);
};

// @fnv 0x009df010
// src: XBOX_PDB 0x009df010
bool ActorMover::MoveActorToLocation(const NiPoint3& aNewLoc)
{
    if (IsConditionMet())
    {
        ((FUN_0087b650_shell*)TaskQueueInterface::GetInstance())->QueueActorLocationTask(pActor, &aNewLoc);
        ((FUN_0087b190_shell*)TaskQueueInterface::GetInstance())->QueueActorTask(pActor);
    }
    else
    {
        pActor->SetPos((NiPoint3*)&aNewLoc);
    }

    ((SetLoc_S*)pActor)->SetLocationOnReference(aNewLoc);

    TESWorldSpace_SV* pworld = (TESWorldSpace_SV*)pActor->GetParentWorldSpace();
    if (!pworld)
        return true;

    TESObjectCELL* pcurrentCell = pActor->GetParentCell();
    TESObjectCELL* pnewcell = pworld->GetCellByWorldPosition(aNewLoc);
    if (pcurrentCell != pnewcell)
    {
        TESObjectREFR_Ext::SetParentCellAndWorldspace(pActor, 0, pworld);
    }

    if (!pActor->GetProcessTier() && !((PlayerSleepView*)g_thePlayer)->IsSleepingOrResting())
        return false;

    return true;
}

namespace PathEndCheck14 {
struct Node
{
    bool PathingNode_IsTeleportDoorNode();
    bool PathingNode_ActivateNode(::TESObjectREFR*);
};
struct Solution
{
    unsigned int GetObjectFlags();
    Node& PathingSolution_GetLastNode();
    unsigned int PathingSolution_GetVirtualNodeCount();
};
void __fastcall PathingSolution_ClearCurrentDetailedPath(Solution*);

// Handles a zero lastNode case, checks the current path node, and conditionally calls path routines before returning 0, 1, or 2.
} // namespace PathEndCheck14

// @fnv 0x009dc980
// src: COMMUNITY 0x009dc980
int ActorMover::EndOfCurrentPathCheck()
{
    using namespace PathEndCheck14;
    Node* pnode;
    if (!lastNode)
    {
        eState = 7;
        SetEnabled(true);
        FUN_009dd0a0();
        return 2;
    }
    currentNode = lastNode;
    if (((NiPointer<PathEndCheck14::Solution>*)&m_pActorNode)->operator->()->GetObjectFlags() > 0)
    {
        pnode = &((NiPointer<PathEndCheck14::Solution>*)&m_pActorNode)->operator->()->PathingSolution_GetLastNode();
        if (pnode->PathingNode_IsTeleportDoorNode())
        {
            if (!pnode->PathingNode_ActivateNode(pActor) && !pActor->GetCurrentAIProcess()->GetCurrentFadeState())
            {
                eState = 7;
                SetEnabled(true);
                FUN_009dd150();
                return 2;
            }
            else
            {
                PathingSolution_ClearCurrentDetailedPath(((NiPointer<PathEndCheck14::Solution>*)&m_pActorNode)->operator->());
                return 1;
            }
        }
    }
    if (currentNode >= ((NiPointer<PathEndCheck14::Solution>*)&m_pPathHandler->pCurrentPathingSolution)->operator->()->PathingSolution_GetVirtualNodeCount() - 1)
        FUN_009dd150();
    return 0;
}

