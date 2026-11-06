// bscore/console/bsthread_console_pc.h: declares BSThreadCriticalSectionPC, BSThread, BSThreadEntryPC
#ifndef FNV_BSTHREAD_CONSOLE_PC_H
#define FNV_BSTHREAD_CONSOLE_PC_H


#include "layout_support.h"

#include "../../../include/BSThread.h"

extern "C"
{
    extern void(__stdcall* fnv_EnterCriticalSection)(void*);
    extern void(__stdcall* fnv_LeaveCriticalSection)(void*);
    __declspec(dllimport) void* __stdcall GetCurrentThread();
    __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
    __declspec(dllimport) void* __stdcall CreateThread(void*, unsigned long, unsigned long(__stdcall*)(void*), void*,
                                                       unsigned long, unsigned int*);
    __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);
    __declspec(dllimport) int __stdcall SetThreadPriority(void*, int);
}

class BSThreadEntryPC
{
  public:
    virtual ~BSThreadEntryPC();
    virtual unsigned long ThreadProc();
};

// The thread entry point has no identity candidate in the task or lookup index.
unsigned long __stdcall RunThreadProc(void*);
extern void(__stdcall* DAT_00fdf054)(void*);

#endif
