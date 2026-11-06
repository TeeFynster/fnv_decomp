#pragma once

#include "QueuedFile.h"

class QueuedReplacementKFList : public QueuedFile
{
public:
    void OnChildCompletion() override;

    void FUN_00446a40();
};
