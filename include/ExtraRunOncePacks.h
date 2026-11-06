#pragma once

#include "BSExtraData.h"
#include "BSSimpleList.h"

namespace extra_save
{
struct ListItem;
typedef BSSimpleList<ListItem*> ExtraSavePackageListView;
}

class ExtraRunOncePacks : public BSExtraData
{
public:
    ExtraRunOncePacks();
    virtual ~ExtraRunOncePacks();
    virtual bool Compare(BSExtraData* extra);

    void SetExtra(int a, unsigned char b);
    void FUN_004330e0();
    void* FUN_004330b0(unsigned int flags);

    extra_save::ExtraSavePackageListView* list;
};
