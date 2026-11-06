#pragma once

#include "BSExtraData.h"

class __declspec(novtable) ExtraIgnoredBySandbox : public BSExtraData
{
public:
    virtual ~ExtraIgnoredBySandbox();

    ExtraIgnoredBySandbox();
    ExtraIgnoredBySandbox* Initialize();
};
