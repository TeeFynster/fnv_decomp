#pragma once

#include "NiSearchPath.h"

class BSSearchPath : public NiSearchPath
{
public:
    virtual ~BSSearchPath();
    virtual bool ResolveSearchPath(char* pcPath, unsigned int uiStringLen);
    virtual bool FUN_00b013e0(char* apFile);

    static void* operator new(unsigned int uiSize);

    void FUN_00aa24f0();
    void* FUN_00b01480(unsigned int flags);
};
