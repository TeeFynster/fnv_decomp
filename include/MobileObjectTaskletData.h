#pragma once

#include "BSWin32TaskletData.h"
#include "BSTCommonLLMessageQueue.h"
#include "LockPrimitive.h"

class MobileObject;
class MobileObjectTaskletContext;
template <class T> class BSSimpleList;
template <class T> class BSTFreeListElem;



class MobileObjectTaskletData : public BSWin32TaskletData
{
public:
    MobileObjectTaskletData(BSTFreeList<MobileObjectTaskletContext>* apList);
    virtual ~MobileObjectTaskletData();
    virtual void Process();
    virtual void SetMobileObjectCount(unsigned int auiObjectCount);
    virtual void ProcessMobileObject(MobileObject* apObject);
    virtual void SetThreadNumber(unsigned int auiThreadNumber);

    BSSimpleList<MobileObject*>* pMobList;
    BSTCommonLLMessageQueue<MobileObjectTaskletContext> kMessageQueue;
    unsigned int MobileObjectTaskletState;
    unsigned int eType;

    void FUN_008c83a0();
    bool ProcessMessage(void* apMessage, int aiThread);
    void ProcessMessages(int aiType);
};
