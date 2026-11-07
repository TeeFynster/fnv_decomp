// src/unmapped/sprintf_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/unmapped/sprintf.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <stddef.h>
#include <windows.h>
// @fnv 0x00aa29e0
// src: GAMEBRYO_LIB 0x00aa29e0
int __cdecl NiMessageBoxUtilities_DefaultMessageBox(const char* pcText, const char* pcTitle)
{
    MessageBoxA(NULL, pcText, pcTitle, MB_TOPMOST);
    return 0;
}
