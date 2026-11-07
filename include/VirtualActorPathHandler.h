#pragma once

#include "ActorPathHandler.h"
#include "IDebugText.h"
#include "NiPoint3.h"

class Actor;
class ActorMover;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class PathingRequest;
class PathingSolution;
template <class T> class NiPointer;

class VirtualActorPathHandler : public ActorPathHandler
{
public:
    VirtualActorPathHandler(Actor*, ActorMover*, NiPointer<PathingSolution>&, PathingRequest*);
    virtual ~VirtualActorPathHandler();
    VirtualActorPathHandler& operator=(const VirtualActorPathHandler&);

    void SetInitialPathState();
    void LoadGame(BGSLoadFormBuffer*);
    int Init(float, float);
    int GetVirtualNodeIndexAtPosition(NiPoint3&);
    virtual bool GetPathingDelta(NiPoint3* delta);
    int UpdatePathMovement(float);
    float GetDistanceRemaining_009eb070();
    void SaveToBuffer(BGSSaveFormBuffer*);
    void* DestroyIfFlagged(unsigned int);
    int UpdateWhilePlayerWaits(float);
    float GetPercentTraveled();
    NiPoint3 GetPoint(float);
    NiPoint3 GetNextPathPoint() const;
    void PrintPathDebugInfo(IDebugText*, DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY);
    bool GetPointAtIndex(unsigned int, NiPoint3*);

    unsigned int m_uiPathPointIndex;
    float m_fPathValue16;
    float m_fPathValue2;
};
