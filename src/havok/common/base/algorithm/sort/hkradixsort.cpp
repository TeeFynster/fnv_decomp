// src/havok/common/base/algorithm/sort/hkradixsort.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/algorithm/sort/hkradixsort.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
// Counts two byte positions, then stably sorts words from data through temp and back to data.
// @fnv 0x00d9fcf0
// src: XBOX_PDB 0x00d9fcf0
void hkRadixSort_sort16(unsigned int* data, int count, unsigned int* temp)
{
    __declspec(align(16)) unsigned int* ptrs1[256];
    __declspec(align(16)) unsigned int* ptrs0[256];
    __declspec(align(16)) unsigned int hist0[256];
    __declspec(align(16)) unsigned int hist1[256];
    unsigned int* h;
    int iIndex;

    h = hist0;
    for (iIndex = 0; iIndex < 64; iIndex++)
    {
        h[0] = 0;
        h[1] = 0;
        h[2] = 0;
        h[3] = 0;
        h += 4;
    }
    h = hist1;
    for (iIndex = 0; iIndex < 64; iIndex++)
    {
        h[0] = 0;
        h[1] = 0;
        h[2] = 0;
        h[3] = 0;
        h += 4;
    }

    {
        const unsigned int* src = data;
        const unsigned int* dst = temp;
        for (iIndex = 0; iIndex < count; iIndex += 4)
        {
            const unsigned char* b = (const unsigned char*)src;
            unsigned int lo;
            unsigned int hi;
            lo = b[0];
            hi = b[1];
            hist0[lo]++;
            hist1[hi]++;
            _mm_prefetch((const char*)(src + 256), _MM_HINT_NTA);
            _mm_prefetch((const char*)(dst + 256), _MM_HINT_NTA);
            lo = b[4];
            hi = b[5];
            hist0[lo]++;
            hist1[hi]++;
            lo = b[8];
            hi = b[9];
            hist0[lo]++;
            hist1[hi]++;
            lo = b[12];
            hi = b[13];
            hist0[lo]++;
            hist1[hi]++;
            src += 4;
            dst += 4;
        }
    }

    ptrs0[0] = temp;
    ptrs1[0] = data;
    for (iIndex = 0; iIndex < 255; iIndex++)
    {
        ptrs0[iIndex + 1] = ptrs0[iIndex] + hist0[iIndex];
        ptrs1[iIndex + 1] = ptrs1[iIndex] + hist1[iIndex];
    }

    for (iIndex = 0; iIndex < count; iIndex += 4)
    {
        unsigned char cKey;
        {
            cKey = (unsigned char)data[iIndex + 0];
            *ptrs0[cKey]++ = data[iIndex + 0];
        }
        {
            cKey = (unsigned char)data[iIndex + 1];
            unsigned int* __restrict out = ptrs0[cKey];
            *out = data[iIndex + 1];
            ptrs0[cKey] = out + 1;
        }
        {
            cKey = (unsigned char)data[iIndex + 2];
            *ptrs0[cKey]++ = data[iIndex + 2];
        }
        {
            cKey = (unsigned char)data[iIndex + 3];
            *ptrs0[cKey]++ = data[iIndex + 3];
        }
    }
    for (iIndex = 0; iIndex < count; iIndex += 4)
    {
        const unsigned char* b = (const unsigned char*)&temp[iIndex];
        unsigned char cKey;
        {
            cKey = b[1];
            *ptrs1[cKey]++ = temp[iIndex + 0];
        }
        {
            cKey = b[5];
            unsigned int* __restrict out = ptrs1[cKey];
            *out = temp[iIndex + 1];
            ptrs1[cKey] = out + 1;
        }
        {
            cKey = b[9];
            *ptrs1[cKey]++ = temp[iIndex + 2];
        }
        {
            cKey = b[13];
            *ptrs1[cKey]++ = temp[iIndex + 3];
        }
    }
}
