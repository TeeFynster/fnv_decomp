
// src/fallout/ai/playercharacter_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/playercharacter.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "PlayerCharacter.h"

struct FUN_00c6fd20_class
{
    void* m_60c;
    int bhkCharacterController_GetSupportBody();
};
// @fnv 0x00c6fd20
// src: XBOX_PDB 0x00c6fd20
int FUN_00c6fd20_class::bhkCharacterController_GetSupportBody()
{
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x60c))
        return *reinterpret_cast<int*>(
            reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x60c)) + 0xc);
    return 0;
}
