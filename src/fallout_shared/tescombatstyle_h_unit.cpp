
#include "../../include/TESCombatStyle.h"

// @fnv 0x004a7290
float TESCombatStyle::UpdateCombatStyle()
{
    return ((float*)this)[0] * ((float*)this)[0] + ((float*)this)[1] * ((float*)this)[1] +
           ((float*)this)[2] * ((float*)this)[2];
}
