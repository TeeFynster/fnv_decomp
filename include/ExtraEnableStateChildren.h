#pragma once

#include "BSExtraData.h"

class ExtraEnableStateChildren : public BSExtraData
{
public:
    struct ChildrenList
    {
        ~ChildrenList();
        void RemoveAll();
    };

    virtual ~ExtraEnableStateChildren();

    void* FUN_00433410(unsigned int flags);
    void FUN_00433440();

    ChildrenList list;
};
