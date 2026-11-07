// src/havok/common/base/types/hkbasetypes.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/hkbasetypes.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern unsigned char DAT_010c7948;
extern unsigned char DAT_010c7b48;
extern unsigned char DAT_010c7d48;
extern unsigned char str_010c7d44;

struct FUN_00ca9360_cls
{
    unsigned char m_00;
    FUN_00ca9360_cls* FindFloatTableIndex(const float* key);
};

// Binary-searches a sorted float table for the value at key and stores the resulting index in m_00, or 0 if below the first entry.
// @fnv 0x00ca9360
// src: GUESS 0x00ca9360 (confidence: medium)
FUN_00ca9360_cls* FUN_00ca9360_cls::FindFloatTableIndex(const float* key)
{
    FUN_00ca9360_cls* pResult = this;
    unsigned lo;
    lo = (unsigned)&DAT_010c7948;
    int iKey = *(const int*)key;
    unsigned hi;
    unsigned mid;

    if (iKey < 0x3c23d70a)
    {
        pResult->m_00 = 0;
        return pResult;
    }
    hi = (unsigned)&DAT_010c7d48;
    if (iKey > 0x4358cccd)
    {
        lo = (unsigned)&DAT_010c7b48;
    }
    else
    {
        hi = (unsigned)&DAT_010c7b48;
    }

    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;
    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid)
        lo = mid;
    else
        hi = mid;

    mid = (hi >> 1) + (lo >> 1);
    if (iKey > *(const int*)mid && mid < (unsigned)&str_010c7d44)
    {
        mid += 4;
    }
    pResult->m_00 = (unsigned char)(((int)(mid - (unsigned)&DAT_010c7948)) >> 2);
    return pResult;
}
