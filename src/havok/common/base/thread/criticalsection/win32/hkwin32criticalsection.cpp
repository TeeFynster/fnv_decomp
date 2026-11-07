// src/havok/common/base/thread/criticalsection/win32/hkwin32criticalsection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/criticalsection/win32/hkwin32criticalsection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
struct FUN_00cf6da0_cls
{
    CRITICAL_SECTION m_00;
    FUN_00cf6da0_cls* ProcessAndReturnValue_00cf6da0(DWORD spinCount);
};

// @fnv 0x00cf6da0
// src: GUESS 0x00cf6da0 (confidence: low)
FUN_00cf6da0_cls* FUN_00cf6da0_cls::ProcessAndReturnValue_00cf6da0(DWORD spinCount)
{
    InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)this, spinCount);
    return this;
}
