#pragma once

#include "BSExtraData.h"

class TESForm;

class ExtraPatrolRefInUseData : public BSExtraData
{
public:
    virtual ~ExtraPatrolRefInUseData();

    ExtraPatrolRefInUseData(TESForm* apForm);
    bool GetCanBeUsedBy(void* apPotentialUser);

    unsigned int User;
};
