// bscore/oei_io_thread_decls.h: declares IORequest, IO_Thread
#ifndef FNV_OEI_IO_THREAD_DECLS_H
#define FNV_OEI_IO_THREAD_DECLS_H

#include "../../include/CountingSemaphore.h"
#include "BSThread.h"
#include "RecursiveLock.h"
#include "_RTL_CRITICAL_SECTION.h"

struct _iobuf;
extern "C" int __cdecl fseek(_iobuf*, long, int);
extern "C" unsigned int __cdecl fread(void*, unsigned int, unsigned int, _iobuf*);
extern "C" unsigned int __cdecl fwrite(const void*, unsigned int, unsigned int, _iobuf*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" void(__stdcall* fnv_EnterCriticalSection)(_RTL_CRITICAL_SECTION*);
extern "C" void(__stdcall* fnv_LeaveCriticalSection)(_RTL_CRITICAL_SECTION*);


__forceinline void LockRequestQueue(RecursiveLock* section)
{
    fnv_EnterCriticalSection(reinterpret_cast<_RTL_CRITICAL_SECTION*>(section->CriticalSection));
}
__forceinline void UnlockRequestQueue(RecursiveLock* section)
{
    // Unused local homes reproduce the original inlined unlock frame.
    // The diagnostic names are inferred; their original purpose is unknown.
    unsigned long threadOwner;
    unsigned long previousOwner;
    fnv_LeaveCriticalSection(reinterpret_cast<_RTL_CRITICAL_SECTION*>(section->CriticalSection));
}

namespace OEI {
namespace IO {
enum IO_Request_Type
{
    IRT_INVALID,
    IRT_SEEK,
    IRT_READ,
    IRT_WRITE,
    IRT_QUIT
};
enum Seek_Whence_Type
{
    SWT_SET,
    SWT_CURRENT,
    SWT_END
};
class IORequest
{
  public:
    _iobuf* m_pFile;
    IO_Request_Type m_eRequestType;
    Seek_Whence_Type m_eSeekWhence;
    void* m_pBuffer;
    unsigned int m_uiSize;
    CountingSemaphore* m_pCompletionSemaphore;
    union
    {
        int result_int;
        unsigned int result_unsigned_int;
    } result;
};
class IO_Thread : public BSThread
{
  public:
    unsigned int ThreadProc();
};
}
}

template <class T> class BSListNode;
template <class T> class BSListBase
{
  public:
    void** m_ppVirtualMethodTable;
    BSListNode<T>* m_pkHead;
    BSListNode<T>* m_pkTail;
    unsigned int m_uiCount;
};
template <class T> class BSPointerListBase : public BSListBase<T>
{
  public:
    T RemoveHead();
};
template <class T> class BSList : public BSPointerListBase<T>
{
};

extern CountingSemaphore* g_pRequestAvailableSemaphore;
extern CountingSemaphore* g_pShutdownCompleteSemaphore;
extern RecursiveLock* g_pRequestQueueLock;
extern BSList<OEI::IO::IORequest*>* g_pIORequestQueue;
FNV_STATIC_ASSERT(sizeof(OEI::IO::IORequest) == 0x1c);
FNV_STATIC_ASSERT(offsetof(OEI::IO::IORequest, m_eRequestType) == 4);
FNV_STATIC_ASSERT(offsetof(OEI::IO::IORequest, result) == 0x18);
#endif
