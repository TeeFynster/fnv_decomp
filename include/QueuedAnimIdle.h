#pragma once

#include "QueuedKF.h"

class QueuedAnimIdle : public QueuedKF
{
public:
    virtual void OnChildCompletion();
    virtual void ProcessLoadedAnimIdle();
};
