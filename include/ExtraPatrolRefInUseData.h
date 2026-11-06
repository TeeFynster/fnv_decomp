#pragma once

#include "BSExtraData.h"

class TESForm;

class ExtraPatrolRefInUseData : public BSExtraData
{
public:
    virtual ~ExtraPatrolRefInUseData();

    ExtraPatrolRefInUseData(TESForm* apForm);
    bool FUN_00437ab0(void* apPotentialUser);

    unsigned int User;
};
