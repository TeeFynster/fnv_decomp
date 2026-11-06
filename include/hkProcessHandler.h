#pragma once

class hkProcessHandler
{
public:
    virtual void v00();
    virtual void v04();
    virtual int getProcessId(const char* pcName) throw();
    virtual void v0c();
    virtual void v10();
    virtual void selectProcess(int aiAllocationTag) throw();
    virtual void deleteProcess(int tag);
};
