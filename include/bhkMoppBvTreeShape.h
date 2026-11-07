#pragma once

#include "bhkBvTreeShape.h"

class MoppCodeHeader;

class bhkMoppBvTreeShape : public bhkBvTreeShape
{
public:
    virtual unsigned int slotA8();
    virtual MoppCodeHeader* slotB4(char* pAllocated);

    void bhkSerializable_LoadCInfo(NiStream& stream);
    unsigned int LoadCInfo(NiStream& stream);

    static NiObject* __cdecl CreateObject();
};
