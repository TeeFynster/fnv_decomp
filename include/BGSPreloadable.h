#pragma once

#include "BaseFormComponent.h"

class QueuedFile;

enum IO_TASK_PRIORITY;

class BGSPreloadable : public BaseFormComponent
{
public:
    BGSPreloadable();

    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);
};
