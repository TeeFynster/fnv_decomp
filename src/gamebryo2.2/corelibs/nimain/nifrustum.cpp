
// src/gamebryo2.2/corelibs/nimain/nifrustum.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nifrustum.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiFrustum.h"

extern "C" int NiSprintf(char*, unsigned int, const char*, ...);
extern "C" void* _NiMalloc(unsigned int);
extern "C" unsigned int strlen(const char*);

// Allocates a buffer sized from the prefix length and formats the frustum's near, far, left, right, top, bottom and ortho values into it, returning the string.
// @fnv 0x00a71bc0
// src: XBOX_PDB 0x00a71bc0
char* NiFrustum::GetViewerString_00a71bc0(const char* pcPrefix)
{
    char* pcString;
    unsigned int uiLen;

    uiLen = strlen(pcPrefix);
    pcString = (char*)_NiMalloc(uiLen + 0x50);
    NiSprintf(pcString, uiLen + 0x50, "%s = (N=%g,F=%g,L=%g,R=%g,T=%g,B=%g,O=%u)", pcPrefix, nearPlane, farPlane,
              left, right, top, bottom, ortho);
    return pcString;
}
