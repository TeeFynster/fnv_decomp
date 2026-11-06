#pragma once

#include "QueuedFileEntry.h"

class QueuedModel : public QueuedFileEntry
{
public:
    virtual void GenerateKey() override;
    virtual void DispatchToManager() override;
    virtual void OnChildCompletion() override;
    virtual void vf12();
};
