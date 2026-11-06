// gamebryo2.2/corelibs/nimain/nioldscreenspace_decls.h: declares ScreenReference, ScreenPointer
#ifndef NIOLD_SCREENSPACE_DECLS_H
#define NIOLD_SCREENSPACE_DECLS_H

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class ScreenReference
{
  public:
    virtual void vfn_00();
    virtual void DeleteThis();
    volatile long references;
    void DecRef()
    {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
    void AcquireReference()
    {
        InterlockedIncrement(&references);
    }
};
class ScreenPointer
{
  public:
    ScreenReference* pointer;
    ScreenPointer() throw() : pointer(0)
    {}
    ~ScreenPointer() throw()
    {
        if (pointer)
            pointer->DecRef();
    }
    ScreenPointer& operator=(const ScreenPointer& other) throw()
    {
        if (pointer == other.pointer)
            return *this;
        ScreenReference* old = pointer;
        if (old != 0)
            old->DecRef();
        pointer = other.pointer;
        if (pointer)
            pointer->AcquireReference();
        return *this;
    }
};
#endif
