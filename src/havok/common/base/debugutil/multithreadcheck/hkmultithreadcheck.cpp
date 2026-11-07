
// src/havok/common/base/debugutil/multithreadcheck/hkmultithreadcheck.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/multithreadcheck/hkmultithreadcheck.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMultiThreadCheck.h"

class FUN_00cf6d20_Class
{
  public:
    void hkMultiThreadCheck_disableChecks();
};

// @fnv 0x00cf6d20
// src: XBOX_PDB 0x00cf6d20
void FUN_00cf6d20_Class::hkMultiThreadCheck_disableChecks()
{
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 4) |= 0x8000;
}
