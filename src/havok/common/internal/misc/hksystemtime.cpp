// src/havok/common/internal/misc/hksystemtime.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/misc/hksystemtime.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __int64 __cdecl __time64(__int64*);

// @fnv 0x00e29910
// src: GUESS 0x00e29910 (confidence: medium)
int Hksystemtime_Time64_Thunk(void)
{
    return (int)__time64(0);
}
