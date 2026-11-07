#pragma once

#pragma push_macro("ActorPathHandler")
#undef ActorPathHandler
#include "ActorPathHandler.h"
#include "NiAVObject.h"
#include "NiPoint3.h"
#include "PathingLocation.h"

class Actor;
class ActorPathingMessageQueue;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NiNode;
class PathingRequest;
class TESForm;
class TESPackage;
class TESObjectREFR;
class TESWorldSpace;
struct DcVec;
struct Fx_Arg;
struct PkgTriple;

class ActorMover
{
public:
    ~ActorMover();

    virtual void* DestroyIfFlagged(unsigned int flags);
    virtual void SetMoveModeFlags(unsigned int);
    virtual void ClearFlags(unsigned int mask);
    virtual void SetAnimationFlags(unsigned short flags);
    virtual void ResetMovementData();
    virtual void Update_009dc120(float);
    virtual void vf06();
    virtual void vf07();
    virtual unsigned int vf08();
    virtual bool GetPathingDelta(NiPoint3&);
    virtual void SaveGame_009df100(BGSSaveFormBuffer* buffer);
    virtual void LoadGame_009df3d0(BGSLoadFormBuffer* buffer);
    virtual void InitLoadGame_009df8c0(BGSLoadFormBuffer* buffer);
    virtual void FinishLoadGame_009dfa00(BGSLoadFormBuffer* buffer);
    virtual void ResetPathingState(BGSLoadFormBuffer* apBuffer);

    NiPoint3 m_kLookAtTargetPosition;                 // 0x04
    NiPoint3 m_kPathingDelta;                        // 0x10
    NiPointer<PathingRequest> request;              // 0x1c
    NiPointer<NiNode> m_pActorNode;                  // 0x20
    union
    {
        ActorPathHandler* m_pPathHandler;           // 0x24
        unsigned int preferredMoveMode;
    };
    Actor* pActor;                                  // 0x28
    unsigned int unk2C;
    NiPointer<ActorPathingMessageQueue> m_queue;     // 0x30
    unsigned int unk34;
    unsigned int m_uiMovementFlags;                 // 0x38
    unsigned int m_uiMovementMode;                  // 0x3c
    unsigned short currentNode;                    // 0x40
    unsigned short lastNode;                       // 0x42
    PathingLocation m_pathingLocation;              // 0x44
    int eState;                                    // 0x6c
    bool bPathingFailed;                            // 0x70
    bool m_bHasMovementData;                        // 0x71
    bool m_bMovementComplete;                       // 0x72
    bool m_bHasLookAtTarget;                        // 0x73
    bool m_bMovementActive;                         // 0x74
    bool m_bMovementStateFlag;                      // 0x75
    bool m_bMovementPaused;                         // 0x76
    bool m_bHasPathingDelta;                        // 0x77
    bool unk78;
    unsigned char unk79[3];
    unsigned int lastTime;                          // 0x7c
    unsigned int startTime;                         // 0x80
    int retries;                                   // 0x84

    void ClearMovementPath();
    void RefreshMovementState();
    void StopMoving();
    bool HasLookAtTarget();
    bool IsMovementActive();
    unsigned int GetPreferredMoveModeType();
    void RunProcedure();
    void UpdateMovement(float);
    void HandlePathingResult(ActorPathHandler::PATH_HANDLER_RESULT);
    void UpdateMovementStatus(bool);
    bool HasActiveMovement();
    void ForceStopMoving();
    void Revert(BGSLoadFormBuffer* apBuffer);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    bool GetLookAtTargetPosition(NiPoint3& point);
    unsigned int GetCurrentMoveModeType();
    void SetupPackageTarget(TESPackage*);
    void ForceMoveMode(int value);
    unsigned int GetActorStateFlags();
    void UpdateTeleportPathState();
    void UpdateFlagFromTarget();
    DcVec* GetVec(DcVec* out, float f);
    PkgTriple* FUN_009de0a0(PkgTriple* out);
    bool ApplyNodeLookup(Fx_Arg* arg);
    bool SetGoal_009dba50(int, int, int, float, int);
    bool SetGoalAndAngle(int, int, int, float, float, int);
    void SetGoalAndAngle(NiPoint3*, TESObjectREFR*, TESWorldSpace*, float, float, int);
    bool SetGoal_009dbb10(TESObjectREFR*, float, int);
    void SetGoalAndAngle_(TESObjectREFR*, float, int);
    int GetCurrentNodeIndex();
    bool IsWaitingForAvoidance();
    bool IsMovementBlocked();
    float GetCurrentPercent();
    float GetDistanceTraveled();
    float GetDistanceRemaining();
    bool ComputePathPassesThroughPlayersArea();
    void PathingSolution_GetLastVirtualNode();
    void FUN_009dd0a0();
    void FUN_009dd150();

    void ResetMoverState(bool clearWaiting);
    void ResetMoverState(int);
    bool HasPathingSolution();
    void SetMoveTarget(NiPoint3 target);
    bool GetPathCoordinate(NiPoint3* position);
    int UpdatePathHandler();
    void ResetPathing();
    void SetPathFailed(bool failed);
    void HandlePathResult(int result);
    void UpdatePathMovement();
    void UpdatePathingState(float);
    void SetEnabled(bool enabled);
    void SetEnabled(int);
    void UpdateTargeting();
    void SetFormID(TESForm* form);
    PathingLocation* GetPathingLocation();

    bool BackGroundBuildPath(const PathingRequest* request);
    bool SetGoal(const PathingRequest* request);
    void ActorMover_ClearCurrentData();
    bool PathingSolution_IsValid();
    void FUN_009dc590(float);
    int EndOfCurrentPathCheck();
    bool IsPathingComplete();
    void* RequestRotateActor(NiPoint3 point, bool flag);
    bool RequestRotateActor_009dce80(float delta, bool force);
    unsigned int GetPreferredMoveModeType_009dd130();
    void FinishMoving(bool clearHandler);
    void FinishMoving(int);
    void SetCurrentFrameMoveModeAndDelta();
    bool GetNodeLocation(int, int);
    bool IsPathValid();
    bool MoveActorToLocation(const NiPoint3& location);
    void FUN_00483710();

protected:
    void SetMovementMode(bool);

private:
    void DebugOnStopMoving();
};

#pragma pop_macro("ActorPathHandler")
