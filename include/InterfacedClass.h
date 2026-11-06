#pragma once

class InterfacedClass
{
public:
    InterfacedClass();
    virtual ~InterfacedClass();
    virtual void* AllocateInterface(unsigned int auiThread) = 0;
};
