// gamebryo2.2/corelibs/nimain/nipoint3.cpp: NiColor, NiPoint3 (4 functions)

#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiStream.h"
#include "nipoint3_stream.h"
// Reads the r, g and b components of the color from the stream's input.
// @fnv 0x00a59be0
void NiColor::LoadBinary(NiStream& stream)
{
    stream.m_pkIstr->Read(&r);
    stream.m_pkIstr->Read(&g);
    stream.m_pkIstr->Read(&b);
}
// Writes the color's r, g and b components to the stream's output.
// @fnv 0x00a69780
void NiColor::SaveBinary(NiStream& stream)
{
    stream.m_pkOstr->Write(&r);
    stream.m_pkOstr->Write(&g);
    stream.m_pkOstr->Write(&b);
}

extern "C" int __cdecl NiSprintf(char*, unsigned int, char const*, ...);
extern "C" void* __cdecl _NiMalloc(unsigned int);
extern "C" unsigned int __cdecl strlen(char const*);

// Allocates a buffer sized to the prefix plus 0x40 and formats "%s = (%g,%g,%g)" from the prefix and x, y, z into it, returning the buffer.
// @fnv 0x00a59af0
// src: XBOX_PDB 0x00a59af0
char* __thiscall NiPoint3::GetViewerString_00a59af0(const char* pPrefix)
{
    unsigned int uiLen = strlen(pPrefix) + 0x40;
    char* pString = (char*)_NiMalloc(uiLen);
    NiSprintf(pString, uiLen, "%s = (%g,%g,%g)", pPrefix, x, y, z);
    return pString;
}

#include <math.h>
void* _NiMalloc_00aa1070(unsigned int uiSize);

// Allocates 256 words and stores masked bit patterns from square roots of floats constructed in two ranges.
// @fnv 0x00a59b50
unsigned int* __cdecl BuildSqrtLut()
{
    unsigned int* pLut = (unsigned int*)_NiMalloc_00aa1070(0x400);
    for (unsigned int iIndex = 0; iIndex < 0x80; iIndex++)
    {
        float fValue;
        unsigned int* pFloatBits = (unsigned int*)&fValue;
        *pFloatBits = (iIndex | 0x3f80) << 16;
        fValue = sqrt(fValue);
        pLut[iIndex] = *pFloatBits & 0x7fffff;
        *pFloatBits = (iIndex | 0x4000) << 16;
        fValue = sqrt(fValue);
        pLut[iIndex + 0x80] = *pFloatBits & 0x7fffff;
    }
    return pLut;
}
