#pragma once

class BSTaskletManagerCallback
{
public:
    virtual void* __thiscall Destroy(unsigned int flags);
    virtual void vf01() = 0;

    BSTaskletManagerCallback* Initialize(int a);
};
