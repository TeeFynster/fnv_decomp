
// src/havok/physics/dynamics/entity/util/hkpentityaabbutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/util/hkpentityaabbutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d1b1d0_Item {
    unsigned int m_key;
    int m_uiFilterValue;
};

struct S_00d1b1d0_Less {
    bool operator()(const S_00d1b1d0_Item& a, const S_00d1b1d0_Item& b) const { return a.m_key < b.m_key; }
};

template <typename T>
__forceinline void S_00d1b1d0_swap(T& x, T& y)
{
    __declspec(align(16)) T t(x);
    x = y;
    y = t;
}

// @fnv 0x00d1b1d0
// src: GUESS 0x00d1b1d0 (confidence: low)
void Hkpentityaabbutil_ProcessEntries_00d1b1d0(S_00d1b1d0_Item* pItems, int iLow, int iHigh, S_00d1b1d0_Less cmpLess)
{
setStart:
    const int iMid = (iLow + iHigh) >> 1;
    int lo = iLow;
    int hi = iHigh;
    __declspec(align(16)) const S_00d1b1d0_Item pivotItem = pItems[iMid];
    do {
        while (cmpLess(pItems[lo], pivotItem)) lo++;
        while (cmpLess(pivotItem, pItems[hi])) hi--;
        if (lo <= hi) {
            if (hi != lo) {
                S_00d1b1d0_swap(pItems[hi], pItems[lo]);
            }
            hi--;
            lo++;
        }
    } while (lo <= hi);
    if (iLow < hi) Hkpentityaabbutil_ProcessEntries_00d1b1d0(pItems, iLow, hi, cmpLess);
    if (lo < iHigh) {
        iLow = lo;
        goto setStart;
    }
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
