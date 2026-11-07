#pragma once

#include "FalloutRadio.h"

class BSFileEntry;
class QueuedChildren;
class QueuedParents;
class RadioState;

class RadioConvTask
{
public:
    virtual void* DestroyIfFlagged(unsigned int flags);
    virtual void Run_008372e0();
    virtual void vf02();
    virtual void vf03();
    virtual bool __thiscall GetDescription(char* apDescription, unsigned int aiBufferSize);
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();

    RadioConvTask(RadioState*);
    ~RadioConvTask();
    void FUN_008372c0();

    __declspec(align(8)) int iRefCount;
    int eState;
    __int64 Key;
    int eContext;
    unsigned char spParent[4];
    QueuedChildren* pChildren;
    QueuedParents* pAdditionalParents;
    char* pFileName;
    BSFileEntry* pFileEntry;
    FalloutRadio::RadioConversation* pStation;
    unsigned char _pad34[4];
};
