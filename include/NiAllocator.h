#pragma once

class NiAllocator
{
public:
    virtual void vfn_00();
    virtual void* vfn_04(unsigned int& size, unsigned int& alignment, int event,
                         bool accurateSize, const char* file, int line, const char* function);
    virtual void vf02();
    virtual void vf03();
    virtual void* Allocate(unsigned int& size, unsigned int& alignment, int event,
                           bool accurateSize, const char* file, int line, const char* function);
    virtual void Free(void* memory, int event, int size);
    virtual void* Realloc(void* memory, unsigned int& size, unsigned int& alignment,
                          int event, int a4, int a5, int a6, int a7, int a8);
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();

    void* __thiscall Allocate(unsigned int size);
    void __thiscall Deallocate(void* memory);
};
