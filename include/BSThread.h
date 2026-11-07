#pragma once

#include "BSThreadCriticalSectionPC.h"

class BSThread
{
public:
    enum StackSize  // values: Xbox PDB BSThread::StackSize
    {
        INHERIT_MAIN = 0,
        SMALL_STACK_SIZE = 16384,
        MEDIUM_STACK_SIZE = 32768,
        LARGE_STACK_SIZE = 65536,
        MAINTHREAD_STACK_SIZE = 131072
    };

    BSThread();
    virtual ~BSThread();
    virtual unsigned int ThreadProc();

    void Initialize(StackSize stackSize, const char* name, bool suspended);
    void Initialize(int stackSize, const char* name, bool suspended);
    void SetThreadPriority(int priority);
    void SetSchedulingPriority(unsigned int priority);
    void SetSchedulingPriority(int priority);
    void SetName(const char* name);
    void SetPriority(int priority);
    void Wakeup();
    void Run();
    unsigned int GetThreadID();
    bool TESAnimGroup_GetDecal();
    void FUN_00aa6430(int stackSize, const char* name, bool suspended);
    void FUN_00aa6540(const char* name);
    void FUN_00aa6550(unsigned int priority);
    void FUN_00aa6550(int priority);
    void FUN_00aa6560(int priority);

    BSThreadCriticalSectionPC CriticalSection;
    void* m_pThreadHandle;
    void* m_pCurrentThreadHandle;
    unsigned int m_uiCreatedThreadId;
    unsigned int m_uiCurrentThreadId;
    bool m_bThreadStarted;
    unsigned char unk2D[3];
};
