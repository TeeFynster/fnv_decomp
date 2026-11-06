#pragma once

#include "BSWin32TaskletData.h"
#include "NiAVObject.h"
#include "PathingSolution.h"
#include "ActorPathingMessageQueue.h"

class PathingRequest;

class PathingTaskData : public BSWin32TaskletData
{
public:
    virtual ~PathingTaskData();
    virtual void Process();

    bool HasPendingMessages();
    void SetTaskYielded();
    bool GetByteAtOffset64();

    NiPointer<PathingRequest> m_pPathingRequest;
    NiPointer<PathingSolution> m_pPathingSolution;
    char pad20[0x40];
    NiPointer<ActorPathingMessageQueue> spQueue;
};
