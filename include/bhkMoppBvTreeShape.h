#pragma once

#include "bhkBvTreeShape.h"

class MoppCodeHeader;

class bhkMoppBvTreeShape : public bhkBvTreeShape
{
public:
    virtual unsigned int slotA8();
    virtual MoppCodeHeader* slotB4(char* pAllocated);

    void FUN_00c87710(NiStream& stream);
    unsigned int FUN_00cc9f60(NiStream& stream);

    static NiObject* __cdecl CreateObject();
};
