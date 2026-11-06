#pragma once

#include "BSExtraData.h"

class TESForm;

class ExtraOwnership : public BSExtraData
{
public:
    virtual ~ExtraOwnership();
    virtual bool Compare(BSExtraData* extra);

    ExtraOwnership();
    ExtraOwnership(TESForm* owner);
    bool FUN_00431a70(BSExtraData* apCompare);

    void* pOwner;
};
