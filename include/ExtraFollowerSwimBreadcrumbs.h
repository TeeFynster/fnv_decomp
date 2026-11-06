#pragma once

#include "BSExtraData.h"
#include "MagicTarget.h"
#include "NiPoint3.h"

class FollowerSwimBreadcrumb;

class ExtraFollowerSwimBreadcrumbs : public BSExtraData
{
public:
    virtual ~ExtraFollowerSwimBreadcrumbs();

    void __thiscall FUN_00437d10();
    void* __thiscall FUN_00437ce0(unsigned int flags);

    int iCount;
    NiPoint3 kLastPos;
    int iLastCell;
    BSSimpleList<FollowerSwimBreadcrumb*> kBreadcrumbs;
};
