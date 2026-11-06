// Reconstructed bCore spin-lock (bscore/bsspinlock.h).
//
// object to 0x20). The remaining API (out-of-line Lock/TryLock/Unlock
// and the two static tunables) is declared from the cross-referenced
// original code: 0x0040fbf0 Lock(name), 0x0078d200 TryLock,
// 0x0040fba0 Unlock.
#ifndef BSCORE_BSSPINLOCK_H
#define BSCORE_BSSPINLOCK_H

#include "layout_support.h"

#include "../../include/RecursiveSpinLock.h"

FNV_STATIC_ASSERT(sizeof(RecursiveSpinLock) == 0x20);
FNV_STATIC_ASSERT(offsetof(RecursiveSpinLock, m_uiOwningThreadID) == 0x0);
FNV_STATIC_ASSERT(offsetof(RecursiveSpinLock, m_uiRecursionCount) == 0x4);

// The process-wide bCore spin-lock.
RecursiveSpinLock g_spinLock;

// @fnv 0x0078d1f0
bool BSSpinLockGlobalTryLock()
{
    return g_spinLock.TryLock();
}

#endif
