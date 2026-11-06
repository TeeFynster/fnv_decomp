#pragma once

#include <stddef.h>
#include "NiNode.h"

class NiSortAdjustNode : public NiNode
{
  public:
    NiSortAdjustNode(unsigned int uiChildCount);
    NiSortAdjustNode(int mode = 0);
    virtual ~NiSortAdjustNode();


    void SetSelectiveUpdate(bool bValue);
    void SetSelectiveUpdateTransforms(bool bValue);
    void SetArraySize(unsigned int size);
    void* __thiscall Destructor(unsigned int flags);
};
