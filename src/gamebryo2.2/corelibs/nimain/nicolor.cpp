
// src/gamebryo2.2/corelibs/nimain/nicolor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nicolor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiColor.h"
#include "../../../../include/NiColorA.h"
#include <string.h>

struct FUN_00a698a0_stream;
typedef int(__cdecl* FUN_00a698a0_write_fn)(FUN_00a698a0_stream*, const void*, int, int*, int);
struct FUN_00a698a0_stream
{
    int unk00;
    int bytesWritten;
    int unk08;
    FUN_00a698a0_write_fn write;
};
// Writes the four 4-byte fields at offsets 0, 4, 8 and 12 of this object to the stream stored at context+0x250, accumulating bytesWritten.
// @fnv 0x00a698a0
void NiColorA::SaveBinary(NiStream& kStream)
{
    FUN_00a698a0_stream* stream = *(FUN_00a698a0_stream**)((char*)&kStream + 0x250);
    int size = 4;
    {
        int written = 4;
        stream->bytesWritten += stream->write(stream, this, size, &written, 1);
    }
    stream = *(FUN_00a698a0_stream**)((char*)&kStream + 0x250);
    {
        int written = 4;
        stream->bytesWritten += stream->write(stream, (char*)this + 4, size, &written, 1);
    }
    stream = *(FUN_00a698a0_stream**)((char*)&kStream + 0x250);
    {
        int written = 4;
        stream->bytesWritten += stream->write(stream, (char*)this + 8, size, &written, 1);
    }
    stream = *(FUN_00a698a0_stream**)((char*)&kStream + 0x250);
    {
        int written = 4;
        stream->bytesWritten += stream->write(stream, (char*)this + 12, size, &written, 1);
    }
}

void* _NiMalloc(unsigned int);
int NiSprintf(char*, unsigned int, const char*, ...);
// Formats the three color components with the given prefix and returns the resulting string.
// @fnv 0x00a696c0
char* NiColor::GetFormattedString(const char* pPrefix) const
{
    char* pString;
    unsigned int uiLen;
    uiLen = strlen(pPrefix);
    pString = (char*)_NiMalloc(uiLen + 34);
    NiSprintf(pString, uiLen + 34, "%s = (%5.3f,%5.3f,%5.3f)", pPrefix, r, g, b);
    return pString;
}

void* __cdecl _NiMalloc(unsigned int);
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);
// Formats the four components with pPrefix and returns the resulting string.
// @fnv 0x00a69720
char* NiColorA::GetViewerString(const char* pPrefix) const
{
    char* pString;
    unsigned int uiLen;
    uiLen = strlen(pPrefix);
    pString = (char*)_NiMalloc(uiLen + 0x24);
    NiSprintf(pString, uiLen + 0x24, "%s = (%5.3f,%5.3f,%5.3f,%5.3f)", pPrefix, r, g, b, a);
    return pString;
}
