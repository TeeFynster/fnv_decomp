// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
struct S_0082f1f0_Lock
{
    CRITICAL_SECTION m_cs;
    void BSCriticalSection_Unlock();
};

// @fnv 0x0082f1f0
// src: XBOX_PDB 0x0082f1f0
void S_0082f1f0_Lock::BSCriticalSection_Unlock()
{
    LeaveCriticalSection(&m_cs);
}
