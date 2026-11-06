// Unit-private lock record and callable declarations.
#ifndef FNV_EXTRADATAOBJECTS_PRIVATE_PACKET_H
#define FNV_EXTRADATAOBJECTS_PRIVATE_PACKET_H

#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

class TESKey;

#include "../../include/LOCK_LEVEL.h"

class LockExtraData
{
  public:
    unsigned char m_uiLockState;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESKey* pKey;  // +0x4, 4 bytes
    char cFlags;   // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    unsigned int m_uiLockDifficulty;  // +0xC, 4 bytes
    unsigned int m_uiLockValue;       // +0x10, 4 bytes

    void SetLocked(bool aLocked);
    int GetLevel(TESObjectREFR*);
    static int ConvertLockLevel(int);
    static int EnumToNumericValue(LOCK_LEVEL);
    int GetLockLevel(TESObjectREFR*);
    bool MeetsMinimumLockLevel();
};
FNV_STATIC_ASSERT(sizeof(LockExtraData) == 20);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockState) == 0);
FNV_STATIC_ASSERT(offsetof(LockExtraData, pKey) == 4);
FNV_STATIC_ASSERT(offsetof(LockExtraData, cFlags) == 8);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockDifficulty) == 12);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockValue) == 16);


#endif
