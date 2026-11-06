#pragma once

#include <stddef.h>

class NiCriticalSection
{
public:
    unsigned char m_kCriticalSection[24]; // Opaque Win32 CRITICAL_SECTION storage.
    unsigned char unk18[4];
    unsigned long m_ulThreadOwner;
    unsigned int m_uiLockCount;
    unsigned char layoutPadding24[92];

    void Lock(const char* pcFile = 0);
    void Unlock();
    void SleepWrapper(int iMS);
};

typedef char NiCriticalSectionSizeCheck[sizeof(NiCriticalSection) == 128 ? 1 : -1];
typedef char NiCriticalSectionOwnerOffsetCheck[offsetof(NiCriticalSection, m_ulThreadOwner) == 28 ? 1 : -1];
typedef char NiCriticalSectionCountOffsetCheck[offsetof(NiCriticalSection, m_uiLockCount) == 32 ? 1 : -1];
