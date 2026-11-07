#pragma once

#include "QueuedKF.h"

class QueuedReplacementKF : public QueuedKF
{
public:
    virtual void Finish();
    virtual bool GetDescription(char* description, unsigned int bufferSize);

    void QueuedKF_Finish();
    void IncrementCounter();
    bool BSTask_int64_GetTaskCanceled();
    void Finish_0043e940();
    bool GetDescription_0043ea00(char* apDescription, unsigned int aiBufferSize);
};
