#pragma once

#include "bhkPhantom.h"

class WorldHolder;

class bhkAabbPhantom : public bhkPhantom
{
public:
    virtual ~bhkAabbPhantom();
    virtual WorldHolder* GetWorld();

    void FUN_00c9f530();
    void* FUN_0056e5e0(unsigned int flags);
    void bhkPhantom_UpdateCFilter();
    static NiObject* __cdecl CreateObject();

    int m4;
    void* m8;
};
