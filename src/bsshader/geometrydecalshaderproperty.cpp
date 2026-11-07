// src/bsshader/geometrydecalshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/geometrydecalshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/StrArr.h"
void __stdcall BSShaderLightingProperty_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
extern const char* DAT_012005b8;
// Grows the string array if it is full, then appends the string returned by _FUN_00a7d330(DAT_012005b8) at the end.
// @fnv 0x00bb44a0
// src: XBOX_PDB 0x00bb44a0
void __stdcall GeometryDecalShaderProperty_GetViewerStrings(StrArr* apStrings)
{
    BSShaderLightingProperty_GetViewerStrings(apStrings);
    char* pString = _FUN_00a7d330(DAT_012005b8);
    unsigned int uiIndex = apStrings->m_usSize;
    if (uiIndex >= apStrings->m_usMaxSize)
        apStrings->SetSize(uiIndex + apStrings->m_usGrowBy);
    apStrings->SetAt(uiIndex, pString);
}
