#pragma once

#include "QueuedKF.h"

class QueuedReplacementKF : public QueuedKF
{
public:
    virtual void Finish();
    virtual bool GetDescription(char* description, unsigned int bufferSize);

    void FUN_0043e4b0();
    void IncrementCounter();
    bool FUN_00449130();
    void FUN_0043e940();
    bool FUN_0043ea00(char* apDescription, unsigned int aiBufferSize);
};
