#pragma once

#include "DetectionTaskData.h"
#include "AnimationTaskData.h"
#include "PackageUpdateTaskData.h"
#include "ActorUpdateTaskData.h"
#include "ActorsScriptTaskData.h"
#include "MovementTaskData.h"

class MobileObjectTaskletContext
{
public:
    MobileObjectTaskletContext();
    MobileObjectTaskletContext(MobileObject* apObject);
    MobileObjectTaskletContext(unsigned int auiObjectCount);
    ~MobileObjectTaskletContext();

    enum Type
    {
        START = 0,
        EXECUTE = 1,
        END = 2
    };

    unsigned int eType;
    unsigned int uiObjectCount;
    MobileObject* pObject;
};

#include "BSTFreeListElem.h"

#include "BSTFreeList.h"

#include "BSTStaticFreeList.h"

class ActorTaskManager
{
public:
    DetectionTaskData kDetectionTaskData;
    AnimationTaskData kAnimationTaskData;
    PackageUpdateTaskData kPackageUpdateTaskData;
    ActorUpdateTaskData kActorUpdateTaskData;
    ActorsScriptTaskData kActorsScriptTaskData;
    MovementTaskData kMovementTaskData;
    BSTStaticFreeList<MobileObjectTaskletContext, 4096> kMessagePool;
    bool m_bTrailingManagerFlag;

    void WaitForTasksDuringRendering();
    void QueryPerformanceCounter(int);
    void TES_LockHavokUpdateMT(bool);
};
