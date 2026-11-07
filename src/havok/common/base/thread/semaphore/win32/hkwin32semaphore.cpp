
// src/havok/common/base/thread/semaphore/win32/hkwin32semaphore.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/semaphore/win32/hkwin32semaphore.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* h, unsigned long ms);

// @fnv 0x00d04380
// src: XBOX_PDB 0x00d04380
int __fastcall hkSemaphore_acquire(void* h, int)
{
    return WaitForSingleObject(*(void**)h, (unsigned long)-1);
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* h, long releaseCount, long* previousCount);
struct FUN_00d04390
{
    void* handle;
    unsigned long wait(unsigned long amount);
};
// @fnv 0x00d04390
unsigned long FUN_00d04390::wait(unsigned long amount)
{
    return (unsigned long)ReleaseSemaphore(*(void**)this, (long)amount, 0);
}

struct FUN_00d97970_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;

    void InitBase(unsigned int aValue);
    FUN_00d97970_cls* Init(unsigned int aValue);
};

// @fnv 0x00d97970
FUN_00d97970_cls* FUN_00d97970_cls::Init(unsigned int aValue)
{
    volatile unsigned int* pWords = (volatile unsigned int*)this;
    pWords[0] = 0;
    pWords[1] = 0;
    pWords[2] = 0x80000000u;
    pWords[7] = 0;
    pWords[8] = 0;
    pWords[9] = 0x80000000u;
    InitBase(aValue);
    return this;
}

#include <windows.h>
struct FUN_00d04350_cls
{
    void* handle;
    FUN_00d04350_cls* Create(long initialCount, long maximumCount);
};

// @fnv 0x00d04350
FUN_00d04350_cls* FUN_00d04350_cls::Create(long initialCount, long maximumCount)
{
    handle = CreateSemaphoreA(0, initialCount, maximumCount, 0);
    return this;
}

struct FUN_00d04370_cls
{
    HANDLE m_hHandle;

    void ForwardCall_00d04370();
};

// @fnv 0x00d04370
// src: GUESS 0x00d04370 (confidence: low)
void FUN_00d04370_cls::ForwardCall_00d04370()
{
    CloseHandle(m_hHandle);
}
