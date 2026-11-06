#pragma once

#include "QueuedFile.h"

class QueuedHead : public QueuedFile
{
public:
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void DispatchToManager();
    virtual void OnChildCompletion();

    bool GetQueuedHeadDescription(char* apDescription, unsigned int aiBufferSize);
};
