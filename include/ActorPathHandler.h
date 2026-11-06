#pragma once

#include "NiPoint3.h"

class Actor;
class ActorMover;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class PathingRequest;
class PathingSolution;

template <class T> class NiPointer;

// src: XBOX_PDB (NiPointer<PathingSolution> and NiPointer<PathingRequest>).
#include "NiPointer.h"

class ActorPathHandler
{
public:
    enum PATH_HANDLER_RESULT  // values: Xbox PDB ActorPathHandler::PATH_HANDLER_RESULT
    {
        PATH_HANDLER_RESULT_NONE = -1,
        PATH_HANDLER_RESULT_OK = 0,
        PATH_HANDLER_RESULT_CANT_MOVE = 1,
        PATH_HANDLER_RESULT_CANT_REACH_Z = 2,
        PATH_HANDLER_RESULT_CANT_USE_DOOR = 3,
        PATH_HANDLER_RESULT_FELL_OFF_PATH = 4,
        PATH_HANDLER_RESULT_DONE = 5,
        PATH_HANDLER_RESULT_DONE_SLEEP_SPECIAL = 6
    };

    ActorPathHandler();
    ActorPathHandler(int a1, int a2);
    ActorPathHandler(const ActorPathHandler&);
    ActorPathHandler(void*, void*, void*, void*);
    ActorPathHandler(Actor*, ActorMover*, NiPointer<PathingSolution>&, PathingRequest*);
    ActorPathHandler& operator=(const ActorPathHandler&);

    virtual ~ActorPathHandler();
    virtual int vfn_04(float, float);
    virtual bool vfn_08(float, bool);
    virtual PATH_HANDLER_RESULT vfn_0c(float);
    virtual PATH_HANDLER_RESULT vfn_10(float);
    virtual void vfn_14();
    virtual float vfn_18();
    virtual float vfn_1c();
    virtual NiPoint3 vfn_20();
    virtual bool vfn_24(unsigned int, NiPoint3&);
    virtual float vfn_28();
    virtual NiPoint3 vfn_2c(float);
    virtual int vfn_30();
    virtual bool vfn_34();
    virtual void vfn_38(PathingRequest*);
    virtual bool vfn_3c();
    virtual bool vfn_40();
    virtual bool vfn_44();
    virtual unsigned int GetActorStateFlags();
    virtual bool GetPathingDelta(NiPoint3* outDelta);
    virtual void vf20();
    virtual void vf21();
    virtual void vf22(ActorPathHandler*);
    virtual void vf23(int);
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual bool vf29();
    virtual void Save(BGSSaveFormBuffer*);
    virtual void Load(BGSLoadFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);

    void vfn_00();
    bool CanTransition();

    PATH_HANDLER_RESULT CompleteNoPathUpdate(float fSeconds);
    void FUN_009dfe40(void*, void*, void*, void*);
    void* FUN_009dfe10(unsigned int flags);

    Actor* pActor;
    ActorMover* m_pActorMover;
    NiPointer<PathingSolution> pCurrentPathingSolution;
    NiPointer<PathingRequest> m_pPathingRequest;
};
