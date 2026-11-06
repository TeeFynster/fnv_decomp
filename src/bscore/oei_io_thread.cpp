// bscore/oei_io_thread.cpp: IO_Thread (2 functions)

#include "oei_io_thread_decls.h"
#include "../../include/MemoryManager.h"

__forceinline void CountingSemaphore::Wait()
{
    WaitForSingleObject(hSemaphore, 0xffffffffUL);
    InterlockedDecrement(reinterpret_cast<volatile long*>(&iCount));
}

__forceinline void CountingSemaphore::Signal()
{
    ReleaseSemaphore(hSemaphore, 1, 0);
    InterlockedIncrement(reinterpret_cast<volatile long*>(&iCount));
}

// @fnv 0x00aa8430
unsigned int OEI::IO::IO_Thread::ThreadProc()
{
    bool quit;
    SetSchedulingPriority(1);
    while (true)
    {
        g_pRequestAvailableSemaphore->Wait();
        LockRequestQueue(g_pRequestQueueLock);
        IORequest* request = g_pIORequestQueue->RemoveHead();
        UnlockRequestQueue(g_pRequestQueueLock);
        quit = false;
        switch (request->m_eRequestType)
        {
        case IRT_QUIT:
            quit = true;
            break;
        case IRT_SEEK:
            request->result.result_int = fseek(request->m_pFile, request->m_uiSize, request->m_eSeekWhence);
            break;
        case IRT_READ:
            request->result.result_unsigned_int = fread(request->m_pBuffer, 1, request->m_uiSize, request->m_pFile);
            break;
        case IRT_WRITE:
            request->result.result_unsigned_int = fwrite(request->m_pBuffer, 1, request->m_uiSize, request->m_pFile);
            break;
        }
        if (quit)
        {
            g_pShutdownCompleteSemaphore->Signal();
            break;
        }
        if (request->m_pCompletionSemaphore)
            request->m_pCompletionSemaphore->Signal();
    }
    return 0;
}

extern MemoryManager g_memoryManager;

struct FUN_00aa89d0_holder
{
    void FUN_00aa63c0();
    FUN_00aa89d0_holder* Destroy(unsigned int flags);
};

// Calls FUN_00aa63c0, then frees this via g_memoryManager.Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00aa89d0
FUN_00aa89d0_holder* FUN_00aa89d0_holder::Destroy(unsigned int flags)
{
    FUN_00aa63c0();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
