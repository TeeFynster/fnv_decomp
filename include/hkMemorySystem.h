#pragma once

#include "hkMemoryRouter.h"

struct Flag;

class hkMemorySystem
{
public:
    struct FrameInfo
    {
        FrameInfo();
        int m_iSolverBufferSize;
        int m_iLargeBlockSize;
    };

    class Flags
    {
    public:
        Flags(int iFlags) : m_iFlags(iFlags) {}
        Flags(const Flags& other) : m_iFlags(other.m_iFlags) {}
        int m_iFlags;
    };

    virtual ~hkMemorySystem();
    virtual hkMemoryRouter* CreateMemoryRouter(const FrameInfo& info, Flags flags);
    virtual void v2();
    virtual void InitializeThreadRouter(hkMemoryRouter* router, const char* name, Flag flag);
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();

    static hkMemorySystem* __cdecl GetMonitorStream();
    static void __cdecl ReplaceInstance(hkMemorySystem* system);
    void GetMonitorStream(void*, int);
};
