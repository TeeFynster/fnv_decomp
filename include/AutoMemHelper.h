#pragma once

class AutoMemHelper
{
public:
    AutoMemHelper(int aiMemoryContext, bool bPush, const char* pcFile, int iLine);
    AutoMemHelper(int aiMemoryContext, int bPush, const char* pcFile, int iLine);
    AutoMemHelper(int aiMemoryContext, bool bPush, char* pcFile, int iLine);
    ~AutoMemHelper();

    int pad;
};
