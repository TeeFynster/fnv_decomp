// gamebryo2.2/corelibs/nimain/console/nipoint3_console.cpp: free functions (2 functions)

#include "NiPoint3.h"

// Compiler-emitted startup initializer: the 17-DWORD startup table (160-byte
// region, first 68 bytes active here) is copied into the BSS buffer at
// process start. The MSVC /O2 .ctors for the global copy-initialization
// below lowers to a frameless "rep movsd" of 17 DWORDs.
struct NiPoint3StartupTable
{
    int data[17];
};

// @fnv 0x00a62110
NiPoint3StartupTable gNiPoint3StartupSrc = {{8193, 1, 0, -1, 0, 0, 0, 264, 1, 0, 264, 2, 0, 264, 3, 0, 264}};
NiPoint3StartupTable gNiPoint3StartupDst = gNiPoint3StartupSrc;

extern void* DAT_011f4aa8;

// Normalizes each of count NiPoint3 vectors spaced by stride bytes, scaling by the reciprocal of its length via a lookup table.
// @fnv 0x00a7e960
void NormalizePoints(NiPoint3* pElementBuffer, unsigned int count, unsigned int stride)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        union
        {
            float f;
            unsigned int u;
        } fInvLen;
        fInvLen.f = pElementBuffer->x * pElementBuffer->x + pElementBuffer->y * pElementBuffer->y +
                    pElementBuffer->z * pElementBuffer->z;
        if (fInvLen.u == 0)
        {
            fInvLen.f = 0.0f;
        }
        else
        {
            unsigned short usExponent = (fInvLen.u >> 23) - 127;
            fInvLen.u &= 0x7fffff;
            if (usExponent & 1)
            {
                fInvLen.u |= 0x800000;
            }
            int iExponent = ((short)usExponent >> 1) + 127;
            fInvLen.u >>= 16;
            fInvLen.u = (iExponent << 23) | ((unsigned int*)DAT_011f4aa8)[fInvLen.u];
            fInvLen.f = 1.0f / fInvLen.f;
        }
        pElementBuffer->x *= fInvLen.f;
        pElementBuffer->y *= fInvLen.f;
        pElementBuffer->z *= fInvLen.f;
        pElementBuffer = (NiPoint3*)((char*)pElementBuffer + stride);
    }
}
