#pragma once

#include "BSExtraData.h"

class LockExtraData;
class TESObjectREFR;

class ExtraLock : public BSExtraData
{
public:
    virtual ~ExtraLock();
    virtual bool Compare(BSExtraData* extra);

    ExtraLock(LockExtraData* lock);

    void Unlock();
    void Lock();
    void* __thiscall ReleaseIfFlagged(unsigned int flags);
    void FUN_00517360();
    int FUN_0043a320();
    void FUN_0043a210(TESObjectREFR* apRef, bool abFlag);
    void FUN_00430ca0();
    bool MenuTopic_GetResponseListEmpty();
    void MenuTopic_FillResponseList(int);

    LockExtraData* pLock;
};
