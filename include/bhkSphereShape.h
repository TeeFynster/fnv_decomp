#pragma once

#include "bhkConvexShape.h"

class ArgB;

class bhkSphereShape : public bhkConvexShape
{
public:
    bhkSphereShape(float fRadius, bool bFlag);
    virtual ~bhkSphereShape();

    virtual const NiRTTI* GetRTTI() const;
    virtual MoppCodeHeader* slotB4(char* pAllocated);

    void* GetHavokShape();
    void* FUN_004ae750();
    void FUN_0056ea00(float radius);
    void FUN_00c84df0(void* a, ArgB* b);
    void FUN_00ca0740(void* a, ArgB* b);
    void FUN_00ca5460(void* a, ArgB* b);
    void FUN_00cb7a90(void* a, ArgB* b);
    void ScaleTarget(void* a, ArgB* b);

    static NiObject* __cdecl CreateObject();
    static const NiRTTI ms_kRTTI;
};
