#pragma once

#include <guiddef.h>

class SChannelHookCallInfo
{
public:
    IID iid;
    unsigned long cbSize;
    GUID uCausality;
    unsigned long dwServerPid;
    unsigned long iMethod;
    void* pObject;
};
