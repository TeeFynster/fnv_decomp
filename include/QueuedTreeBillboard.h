#pragma once

#include "QueuedTexture.h"

class QueuedTreeBillboard : public QueuedTexture
{
public:
    virtual ~QueuedTreeBillboard();
    virtual void Finish() override;
    virtual bool GetDescription(char* description, unsigned int bufferSize) override;
    virtual void ProcessLoadedAnimIdle() override;
    virtual void vf12();

    void ApplyQueuedTexture();
    void QueueForPostProcess();
    bool GetDescription_0043d820(char* apDescription, unsigned int aiBufferSize);
    bool QueuedFileEntry_GetDescription(char* apDescription, unsigned int aiBufferSize, const char* apStr);
    void __thiscall FUN_0043d5b0();
    void* __thiscall FUN_0043d580(unsigned int flags);
};
