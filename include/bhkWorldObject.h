#pragma once

#include "bhkSerializable.h"

class bhkFilter;
class bhkShape;
class hkSerializableCinfo;

class bhkWorldObject : public bhkSerializable
{
public:
    bhkWorldObject();
    virtual ~bhkWorldObject();

    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();

    bhkFilter GetFilter();
    bhkShape* FUN_004ae6a0();
    bhkFilter FUN_0043b4f0();
    void FUN_00c85790();
    void* FUN_0056d4c0(unsigned int flags);
    void* FUN_004ae750();
    float FUN_004b5400();

    hkSerializableCinfo* pInfo;
    unsigned int iFlags;
};
