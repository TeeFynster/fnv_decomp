
// src/gamebryo2.2/corelibs/nimain/niavobjectpalette.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niavobjectpalette.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiAVObjectPalette.h"
#include "../../../../include/StrArr.h"

void __stdcall AppendCameraPathEntries(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
extern char const* const g_011f4a04_arg1;
// Appends the string returned by _FUN_00a7d330(g_011f4a04_arg1) to pkStrings, growing it if the current index reaches its size.
// @fnv 0x00a88a70
void NiAVObjectPalette::AppendString(StrArr* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    char* pString = _FUN_00a7d330(g_011f4a04_arg1);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    pkStrings->SetAt(uiIndex, pString);
}
