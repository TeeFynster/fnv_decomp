#pragma once

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

class hkCriticalSection
{
public:
    int m_kCriticalSection[6];

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }

    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};
