#include "../../../../../../../../include/hkBool.h"


// src/havok/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d2ced0
{
    void PerformVoidOperation();
};
struct FUN_00d2d330_shell
{
    void InitializeWorkerThread();
    void hkCpuJobThreadPool_removeThread();
    void hkCpuJobThreadPool_setNumThreads(int desired);
};
struct FUN_00d2ce30_shell
{
    unsigned char m_ucValue;
    bool hkCpuJobThreadPool_isProcessing();
};
struct FUN_00d2ce90_class
{
    unsigned char padding_000[0x12c];
    void* m_uiFilterValue;
    int m_uiItemCount;
    unsigned char padding_134[0x08];
    bool m_running;

    void hkCpuJobThreadPool_waitForCompletion();
};
int __fastcall hkSemaphore_acquire(void*);
struct FUN_00d2d380
{
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    const char* m1c;
    FUN_00d2d380();
};
struct FUN_00d2ce40_cls
{
    int hkCpuJobThreadPool_getNumThreads();
};
class FUN_00d2cf00
{
  public:
    ~FUN_00d2cf00() throw();
};
class hkMemoryAllocatorXd2d3b0
{
  public:
    virtual ~hkMemoryAllocatorXd2d3b0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterXd2d3b0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXd2d3b0* m_pStreamAllocator;

    hkMemoryAllocatorXd2d3b0& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterXd2d3b0& __cdecl hkMemoryRouter_getInstance() throw();
class hkObjd2d3b0 : public FUN_00d2cf00
{
  public:
    hkObjd2d3b0* DestroyIfFlagged(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, static_cast<hkObjd2d3b0*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};
class ElemD2CD
{
  public:
    void FUN_00d04390(int flag);
    int unk00[12];
};
class OwnerD2CD
{
  public:
    int unk00[11];
    ElemD2CD m_pElements[5];
    int unk11C[3];
    int m_128;
    int unk12C;
    int m_iCapacityFlags;
    int unk134[2];
    hkBool m_13C;

    void hkCpuJobThreadPool_processAllJobs(int value, int unused);
};
extern char DAT_010ce774;
extern char DAT_0102e388;
void hkReferencedObject_setLockMode(int);
struct EventObjD2C
{
    void ForwardCall_00d04370();
    void FUN_00d04390(int);
};
struct ThreadObjD2C
{
    void* m_threadPool;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char m_ucState;
    char pad19[3];
    EventObjD2C m_evt;
    int unk20;
    int unk24;
    int unk28;
    EventObjD2C m_pTail;
    void hkThread_stopThread_ForwardCall_00d87a70();
};
struct VBaseD2C
{
    void* vptr00;
    int unk04;
    int unk08;
    int unk0c;
};
struct ArrBaseD2C
{
    ThreadObjD2C m_threads[6];
};
struct ClsD2C : VBaseD2C, ArrBaseD2C
{
    int m_uiItemCount;
    void hkCpuJobThreadPool_waitForCompletion();
    void ProcessEntries_00d2cf00();
};

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* lpThreadAttributes, unsigned long dwStackSize,
                                                              unsigned long(__stdcall* lpStartAddress)(void*),
                                                              void* lpParameter, unsigned long dwCreationFlags,
                                                              unsigned long* lpThreadId);
extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long dwExceptionCode,
                                                               unsigned long dwExceptionFlags,
                                                               unsigned long nNumberOfArguments,
                                                               const unsigned long* lpArguments);
extern "C" unsigned long __cdecl _exception_code(void);

struct THREADNAME_INFO
{
    unsigned long dwType;
    const char* szName;
    unsigned long dwThreadID;
    unsigned long dwFlags;
};

struct Thr_00d87940
{
    unsigned int m0;
    unsigned int m4;
    unsigned int m8;
    unsigned int mC;
    int hkThread_startThread(unsigned long a0, unsigned long a1, const char* a2, unsigned long a3);
};

// @fnv 0x00d87940
// src: HAVOK_LIB 0x00d87940
int Thr_00d87940::hkThread_startThread(unsigned long a0, unsigned long a1, const char* a2, unsigned long a3)
{
    m0 = (unsigned int)CreateThread(0, a3, (unsigned long(__stdcall*)(void*))a0, (void*)a1, 0, &a1);
    if (m0 == 0)
    {
        return 1;
    }
    m8 = a1;
    mC = 0;
    THREADNAME_INFO info;
    info.dwType = 0x1000;
    info.szName = a2;
    info.dwThreadID = a1;
    info.dwFlags = 0;
    __try
    {
        RaiseException(0x406D1388, 0, 4, (const unsigned long*)&info);
    }
    __except (_exception_code() == 0x406D1388 ? -1 : 1)
    {}
    return 0;
}
