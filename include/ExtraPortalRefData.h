#pragma once

#include "BSExtraData.h"

class LinkedReferencePair;

class ExtraPortalRefData : public BSExtraData
{
public:
    LinkedReferencePair* pData;

    ExtraPortalRefData();
    virtual ~ExtraPortalRefData();
    virtual bool Compare(BSExtraData* apCompare);

    void FUN_004200c0();
    bool FUN_00420300(BSExtraData* apCompare);
    void* __thiscall FUN_00420380(unsigned int flags);
    void __thiscall FUN_004203b0();
};
