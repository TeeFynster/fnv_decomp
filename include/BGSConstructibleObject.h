#pragma once

#include "TESObjectMISC.h"

class BGSConstructibleObject : public TESObjectMISC
{
public:
    BGSConstructibleObject();
    virtual ~BGSConstructibleObject();

    void InitializeData();
    void* __thiscall FUN_004f94b0();
    void* __thiscall Destroy(unsigned int flags);

    void* m_pCreatedObject;
    void* m_pWorkbenchKeyword;
};
