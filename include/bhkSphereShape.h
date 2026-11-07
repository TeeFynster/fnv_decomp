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
    void* Bipedanim_GetReferenceFlagsOrZero();
    void bhkSphereShape_Init(float radius);
    void bhkShape_CopyMembers(void* a, ArgB* b);
    void CopyMembers_00ca0740(void* a, ArgB* b);
    void bhkPackedNiTriStripsShape_CopyMembers(void* a, ArgB* b);
    void bhkMultiSphereShape_CopyMembers(void* a, ArgB* b);
    void ScaleTarget(void* a, ArgB* b);

    static NiObject* __cdecl CreateObject();
    static const NiRTTI ms_kRTTI;
};
