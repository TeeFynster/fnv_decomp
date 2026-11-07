
// src/gamebryo2.2/corelibs/nimain/nibound.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nibound.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <string.h>
#include "../../../../include/NiBound.h"
void* _NiMalloc(unsigned int);
int NiSprintf(char*, unsigned int, const char*, ...);
// Formats and returns a string containing the prefix, center coordinates, and bound radius.
// @fnv 0x00a7fb20
// src: XBOX_PDB 0x00a7fb20
char* NiBound::GetViewerString_00a7fb20(const char* pPrefix)
{
    char* pString;
    unsigned int uiPrefixLen;
    uiPrefixLen = strlen(pPrefix);
    pString = (char*)_NiMalloc(uiPrefixLen + 0x41);
    NiSprintf(pString, uiPrefixLen + 0x41, "%s = (%g, %g, %g) , %g", pPrefix, m_kCenter.x, m_kCenter.y, m_kCenter.z,
              m_fRadius);
    return pString;
}
