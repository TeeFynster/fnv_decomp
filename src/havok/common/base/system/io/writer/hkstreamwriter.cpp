// src/havok/common/base/system/io/writer/hkstreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/hkstreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkStreamWriter.h"

// @fnv 0x00cb15d0
// src: GUESS 0x00cb15d0 (confidence: high)
int __stdcall hkStreamWriter_ReturnOne(int arg0, int arg1)
{
    return 1;
}

// @fnv 0x00cb15f0
// src: HAVOK_SRC 0x00cb15f0
void __stdcall hkStreamWriter_seekTellSupported(unsigned char* flag)
{
    *flag = 0;
}

// @fnv 0x00cb15e0
// src: HAVOK_SRC 0x00cb15e0
int __cdecl hkStreamWriter_tell()
{
    return -1;
}
