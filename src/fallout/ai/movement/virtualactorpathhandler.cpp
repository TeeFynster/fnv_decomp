// fallout/ai/movement/virtualactorpathhandler.cpp: VirtualActorPathHandler (16 functions)

#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/IDebugText.h"
#include "../../../../include/NiPoint3.h"
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include "../../../../include/ActorPathHandler.h"
#include "../../../../include/NiPlane.h"
#include "../../../../include/PathingActorData.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/PathingSolution.h"
#include "../../../../include/VirtualActorPathHandler.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/PathingLocation.h"
#include "../../../../include/PathingGraphNode.h"

// GetLocation/IsTransitionNode bind to 0x00717e50/0x006ca0c0, the shared PathingGraphNode accessors.

// Actor.h lacks the player-comparison call at 0x008bc7f0; this adds no actor layout or virtual slots.
struct PlayerComparisonCall : Actor
{
    bool FUN_008bc7f0(PlayerCharacter*);
};

class UseDoorCalls
{
  public:
    void QueueActorLocationTask();
    void QueueActorTask();
};
class FullNameCall
{
  public:
    const char* GetFullName();
};
void* __stdcall FUN_004537b0(Actor*);
void* __stdcall FUN_004537b0(Actor*, NiPoint3&);
extern const double DAT_0102f078;
extern PlayerCharacter* g_thePlayer;
int Warning(const char*, ...);

// Resets two members to 0 and clears a third member by setting it to 0.
// @fnv 0x009eb040
void VirtualActorPathHandler::SetInitialPathState()
{
    pCurrentPathingSolution.operator=(static_cast<PathingSolution*>(0));
    m_pPathingRequest.operator=(static_cast<PathingRequest*>(0));
    m_uiPathPointIndex = 0;
}

// @fnv 0x009eb3e0
void VirtualActorPathHandler::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData((void*)&m_uiPathPointIndex, 4u);
    buffer->ReadTypedData((void*)&m_fPathValue16, 4u);
    buffer->ReadTypedData((void*)&m_fPathValue2, 4u);
}

// @fnv 0x009ea770
VirtualActorPathHandler::VirtualActorPathHandler(Actor* actor, ActorMover* mover, NiPointer<PathingSolution>& path,
                                                 PathingRequest* request)
    : ActorPathHandler(actor, mover, path, request)
{
    m_fPathValue16 = 0.0f;
    m_fPathValue2 = 0.0f;
}

// @fnv 0x009ea820
int VirtualActorPathHandler::Init(float startIndex, float amount)
{
    m_uiPathPointIndex = (unsigned int)startIndex;
    m_fPathValue16 = 0.0f;
    m_fPathValue2 = pCurrentPathingSolution.operator PathingSolution*()->CalculatePathLength();
    if (startIndex == 0.0)
        return vfn_0c(amount);
    else
        return 0;
}

class PlayerS
{
  public:
    bool IsSleepingOrResting();
};
class Calendar
{
  public:
    float GetGameTimeScale();
};
extern Calendar g_calendar;
extern double _gModifierZero;
extern const double _DAT_01012640;
extern const double DAT_010848d0;
extern float DAT_011e0358;
extern const NiPoint3 NiPoint3_ZERO;
float __cdecl GetDirectionAngle(const NiPoint3&);

// Advances the actor along its path solution by the distance it can travel this frame, updating position, angle and path index, and returns a status code.
// @fnv 0x009ea8a0
int VirtualActorPathHandler::UpdatePathMovement(float afDeltaT)
{
    float fdelta = afDeltaT;
    BaseProcess* pprocess = pActor->GetCurrentProcess();
    if (pprocess && pprocess->GetSitSleepState())
        return 0;
    if (((PlayerS*)g_thePlayer)->IsSleepingOrResting() || ((PlayerComparisonCall*)pActor)->FUN_008bc7f0(g_thePlayer))
    {
        fdelta = _DAT_01012640 / g_calendar.GetGameTimeScale();
    }
    else if (!pActor->HasCombatState())
    {
        fdelta = DAT_010848d0 / g_calendar.GetGameTimeScale();
        BaseProcess* pactorProcess = pActor->GetCurrentProcess();
        if (pactorProcess)
            fdelta = (DAT_011e0358 - pactorProcess->FUN_007df1f0()) * _DAT_01012640 /
                     g_calendar.GetGameTimeScale();
    }
    if (m_uiPathPointIndex >= ((PathingSolution*)pCurrentPathingSolution)->FUN_005a4320())
        return 5;
    NiPoint3 currentLoc = *static_cast<const TESObjectREFR*>(pActor)->GetPos();
    NiPoint3 deltaToNode = NiPoint3_ZERO;
    NiPoint3 nextLoc;
    float fdistCanTravel = pActor->GetCurrentMovementSpeed() * fdelta;
    float fdistToNode = 0;
    while (fdistCanTravel >= _gModifierZero)
    {
        nextLoc = ((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->GetVirtualNode(m_uiPathPointIndex))
                      ->GetLocation()
                      .GetLocation<NiPoint3>();
        deltaToNode = nextLoc - currentLoc;
        fdistToNode = reinterpret_cast<NiPoint3&>(deltaToNode).Length();
        if (fdistCanTravel >= fdistToNode)
        {
            m_fPathValue16 += fdistToNode;
            fdistCanTravel -= fdistToNode;
            currentLoc = reinterpret_cast<const NiPoint3&>(nextLoc);
            float fangle = GetDirectionAngle(deltaToNode);
            pActor->SetFurnitureHeading(fangle);
            if (((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->GetVirtualNode(m_uiPathPointIndex))
                    ->IsTransitionNode())
            {
                switch (GetVirtualNodeIndexAtPosition(currentLoc))
                {
                case -2:
                case -1:
                    return 3;
                case 1:
                    pActor->TESObjectREFR::FUN_008ad1c0(currentLoc, fangle, pActor->GetParentCell(),
                                       pActor->GetParentWorldSpace(), 1, 0);
                    return 0;
                }
            }
            else
            {
                pActor->TESObjectREFR::FUN_008ad1c0(currentLoc, fangle, pActor->GetParentCell(),
                                   pActor->GetParentWorldSpace(), 1, 0);
                if (pActor->GetProcessTier() == 0 && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
                    return 0;
                m_uiPathPointIndex++;
            }
            if (m_uiPathPointIndex >= ((PathingSolution*)pCurrentPathingSolution)->FUN_005a4320())
                return 5;
        }
        else
        {
            break;
        }
    }
    float fscale = fdistToNode != _gModifierZero ? 1.0 - (fdistToNode - fdistCanTravel) / fdistToNode : 0.0;
    reinterpret_cast<NiPoint3&>(deltaToNode) *= fscale;
    reinterpret_cast<NiPoint3&>(currentLoc) += deltaToNode;
    m_fPathValue16 += reinterpret_cast<NiPoint3&>(deltaToNode).Length();
    float fangle = GetDirectionAngle(deltaToNode);
    pActor->SetFurnitureHeading(fangle);
    pActor->TESObjectREFR::FUN_008ad1c0(currentLoc, fangle, pActor->GetParentCell(), pActor->GetParentWorldSpace(), 1,
                       0);
    if (pActor->GetProcessTier() == 0 && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
        return 0;
    if (pCurrentPathingSolution &&
        m_uiPathPointIndex + 1 == ((PathingSolution*)pCurrentPathingSolution)->FUN_005a4320() &&
        ((PathingRequest*)m_pPathingRequest)->FUN_009b0bd0() + fdistCanTravel >= fdistToNode)
    {
        m_uiPathPointIndex++;
        return 5;
    }
    return 0;
}

extern "C" float __cdecl FUN_00404010(float, float);


// @fnv 0x009eb070
float VirtualActorPathHandler::FUN_009eb070()
{
    float flength = ((float*)this)[7] - ((float*)this)[6];
    flength = FUN_00404010(flength, 0.0f);
    return flength;
}


// Saves three 4-byte values at offsets 0x14, 0x18 and 0x1c of this object into the save buffer.
// @fnv 0x009eb390
void VirtualActorPathHandler::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((char*)this + 0x14, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x18, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x1c, 4, 0);
}

void __cdecl _Deallocate(void*);
// Calls FUN_009ea7c0 on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009ea740
void* VirtualActorPathHandler::DestroyIfFlagged(unsigned int flags)
{
    VirtualActorPathHandler::~VirtualActorPathHandler();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x009ea7c0
VirtualActorPathHandler::~VirtualActorPathHandler()
{
    ((VirtualActorPathHandler*)this)->SetInitialPathState();
}

// Forwards the delta time to the virtual method V003 and returns its result.
// @fnv 0x009ead60
int VirtualActorPathHandler::FUN_009ead60(float afDeltaT)
{
    return vfn_0c(afDeltaT);
}

struct Flt
{
    operator unsigned int();
};
extern unsigned int __fastcall FUN_005a4320(char*);
extern double gModifierZero;
// @fnv 0x009eb0b0
float VirtualActorPathHandler::FUN_009eb0b0()
{
    if (!reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xc)->operator unsigned int())
        return 0.0f;
    if (m_uiPathPointIndex >=
            FUN_005a4320(reinterpret_cast<char*>(
                reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xc)->operator unsigned int())) ||
        m_fPathValue2 <= gModifierZero)
        return 1.0f;
    return m_fPathValue16 / m_fPathValue2;
}

// Returns the actor's position.
// @fnv 0x009eb120
NiPoint3 VirtualActorPathHandler::GetPoint(float afUnused)
{
    return *static_cast<const TESObjectREFR*>(pActor)->GetPos();
}


// Accessor at 0x009ddb30 is not declared by the shared PathingSolution yet.
PathingGraphNode* __fastcall GetLastVirtualPathNode(PathingSolution* solution);


// Returns the position of the next path node, the virtual node, or the starting position when the solution has no nodes.
// @fnv 0x009eb160
NiPoint3 VirtualActorPathHandler::GetNextPathPoint() const
{
    if (((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))->GetNodeCount() >
        0)
    {
        if (*(unsigned int*)((char*)this + 0x14) + 1 <
            (*(NiPointer<PathingSolution>*)((char*)this + 0xc))->FUN_005a4320())
        {
            return ((PathingGraphNode*)((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
                ->GetVirtualNode(*(unsigned int*)((char*)this + 0x14) + 1))
                ->GetLocation()
                .GetLocation();
        }
        else
        {
            return GetLastVirtualPathNode((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
                ->GetLocation()
                .GetLocation();
        }
    }
    else
    {
        return *static_cast<const TESObjectREFR*>(pActor)->GetPos();
    }
}


// Prints the actor's starting position and, if a pathing solution exists, the current path node index and count; otherwise prints "No path".
// @fnv 0x009eb2b0
void VirtualActorPathHandler::PrintPathDebugInfo(IDebugText* apDebugText, DEBUGTEXT_LOCATION aLoc, DEBUGTEXT_JUSTIFY aJust)
{
    NiPoint3 loc = *static_cast<const TESObjectREFR*>(pActor)->GetPos();
    apDebugText->Print(aLoc, aJust, "VirtualPathHandler: Actor's Positon %1.f %1.f %1.f", loc.x, loc.y, loc.z);

    if ((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
    {
        apDebugText->Print(aLoc, aJust, "Current path node %u of %u", *(unsigned int*)((char*)this + 0x14),
                           (*(NiPointer<PathingSolution>*)((char*)this + 0xc))->FUN_005a4320());
    }
    else
    {
        apDebugText->Print(aLoc, aJust, "No path");
    }
}


unsigned int __fastcall FUN_005a4320(void* p);
void* __fastcall FUN_00559450(void* p);


// If the container at unk0c is valid and index is in range, copies the NiPoint3 at that index into out and returns true; otherwise returns false.
// @fnv 0x009eb230
bool VirtualActorPathHandler::GetPointAtIndex(unsigned int index, NiPoint3* out)
{
    if (FUN_00559450(&pCurrentPathingSolution) != 0)
    {
        if (index < FUN_005a4320(FUN_00559450(&pCurrentPathingSolution)))
        {
            *out = ((PathingGraphNode*)((PathingSolution*)FUN_00559450(&pCurrentPathingSolution))->GetVirtualNode(index))
                       ->GetLocation()
                       .GetLocation();
            return true;
        }
    }
    return false;
}

bool __cdecl FUN_008c7aa0();
struct DoorReference : TESObjectREFR
{
    void FUN_00575830(const NiPoint3&);
    bool FUN_00573170(Actor*, bool, TESBoundObject*, int);
    int FUN_00474cb0();
    const char* FUN_0055d520();
    int GetCellLoadState();
};
struct CellNameView : TESForm
{
    FullNameCall fullName;
    int FUN_00474cb0();
};
struct PointComparison : NiPoint3
{
    bool FUN_00439090(const NiPoint3&);
};
struct PointMagnitude : NiPoint3
{
    float GetSquaredXYLength();
};
// Advances the door path node, moves the actor through the door, and returns -1, -2, 1 or 0 depending on the next node and actor position checks.
// @fnv 0x009ead90
int VirtualActorPathHandler::GetVirtualNodeIndexAtPosition(NiPoint3& position)
{
    if (FUN_008c7aa0())
    {
        ((UseDoorCalls*)FUN_004537b0(pActor, position))->QueueActorLocationTask();
        ((UseDoorCalls*)FUN_004537b0(pActor))->QueueActorTask();
    }
    else
    {
        ((DoorReference*)pActor)->FUN_00575830(position);
    }
    DoorReference* pPathNodeDoor =
        (DoorReference*)((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->FUN_006e78b0(m_uiPathPointIndex))->GetTeleportDoor();
    ++m_uiPathPointIndex;
    if (pPathNodeDoor && !pPathNodeDoor->FUN_00573170(pActor, false, 0, 1))
        return -1;
    if ((PathingSolution*)pCurrentPathingSolution &&
        m_uiPathPointIndex < ((PathingSolution*)pCurrentPathingSolution)->FUN_005a4320())
    {
        NiPoint3 actorPosition = *static_cast<const TESObjectREFR*>(pActor)->GetPos();
        float distance =
            ((PointMagnitude&)(actorPosition - reinterpret_cast<const NiPoint3&>(((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->GetVirtualNode(m_uiPathPointIndex))
                                                   ->GetLocation()
                                                   .GetLocation<NiPoint3>())))
                .GetSquaredXYLength();
        if (distance > DAT_0102f078)
        {
            if (((PointComparison&)position).FUN_00439090(actorPosition))
            {
                Warning(
                    "PATHFINDING: Actor %s used teleport door %s in cell %s and was not moved to the expected pathing location, check teleport marker",
                    ((DoorReference*)pActor)->FUN_00474cb0() ? pActor->GetName()
                                                             : ((DoorReference*)pActor)->FUN_0055d520(),
                    pPathNodeDoor->GetName(),
                    pPathNodeDoor->GetParentCell() ? (((CellNameView*)pPathNodeDoor->GetParentCell())->FUN_00474cb0()
                                                  ? ((CellNameView*)pPathNodeDoor->GetParentCell())->fullName.GetFullName()
                                                  : ((TESForm*)pPathNodeDoor->GetParentCell())->GetName())
                                           : "");
            }
            return -2;
        }
    }
    position = *static_cast<const TESObjectREFR*>(pActor)->GetPos();
    if (!((DoorReference*)pActor)->GetCellLoadState() && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
    {
        ++m_uiPathPointIndex;
        m_fPathValue16 = 0.0f;
        return 1;
    }
    return 0;
}
