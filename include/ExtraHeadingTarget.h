#pragma once

#include "BSExtraData.h"

namespace extra_save
{
class SForm;
}

class ExtraHeadingTarget : public BSExtraData
{
public:
    virtual ~ExtraHeadingTarget();

    void __thiscall FUN_00435ef0();
    void* __thiscall FUN_0042c960(unsigned int flags);

    extra_save::SForm* target;
};
