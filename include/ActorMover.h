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
    virtual void FUN_009dc120(float);
    virtual void vf06();
    virtual void vf07();
    virtual unsigned int vf08();
    virtual bool GetPathingDelta(NiPoint3&);
    virtual void FUN_009df100(BGSSaveFormBuffer* buffer);
    virtual void FUN_009df3d0(BGSLoadFormBuffer* buffer);
    virtual void FUN_009df8c0(BGSLoadFormBuffer* buffer);
    virtual void FUN_009dfa00(BGSLoadFormBuffer* buffer);
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
    void FUN_009de060(int value);
    unsigned int GetActorStateFlags();
    void UpdateTeleportPathState();
    void UpdateFlagFromTarget();
    DcVec* GetVec(DcVec* out, float f);
    PkgTriple* FUN_009de0a0(PkgTriple* out);
    bool ApplyNodeLookup(Fx_Arg* arg);
    bool FUN_009dba50(int, int, int, float, int);
    bool FUN_009dbb60(int, int, int, float, float, int);
    void FUN_009dbb60(NiPoint3*, TESObjectREFR*, TESWorldSpace*, float, float, int);
    bool FUN_009dbb10(TESObjectREFR*, float, int);
    void FUN_009dbc30(TESObjectREFR*, float, int);
    int FUN_009dcab0();
    bool FUN_009dcb30();
    bool FUN_009dcb90();
    float FUN_009dcbf0();
    float FUN_009dcc20();
    float FUN_009dcc50();
    bool FUN_009dccf0();
    void FUN_009ddb30();
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

    bool FUN_009db090(const PathingRequest* request);
    bool FUN_009dba30(const PathingRequest* request);
    void FUN_009daf80();
    bool FUN_009dc530();
    void FUN_009dc590(float);
    int FUN_009dc980();
    bool FUN_009dcd40();
    void* FUN_009dce20(NiPoint3 point, bool flag);
    bool FUN_009dce80(float delta, bool force);
    unsigned int FUN_009dd130();
    void FUN_009dd1c0(bool clearHandler);
    void FUN_009dd1c0(int);
    void FUN_009ddc00();
    bool FUN_009de110(int, int);
    bool FUN_009de3e0();
    bool FUN_009df010(const NiPoint3& location);
    void FUN_00483710();

protected:
    void SetMovementMode(bool);

private:
    void DebugOnStopMoving();
};

#pragma pop_macro("ActorPathHandler")
