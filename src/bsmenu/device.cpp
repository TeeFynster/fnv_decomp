// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_007adc60_shell
{
    unsigned int dwFlags;
    void __thiscall RaceSexMenu_SetFlag(int aIndex, bool aSet);
};

// Sets or clears bit aIndex in the flags word at offset 0xec of this object, according to aSet.
// @fnv 0x007adc60
// src: XBOX_PDB 0x007adc60
void __thiscall FUN_007adc60_shell::RaceSexMenu_SetFlag(int aIndex, bool aSet)
{
    if (aSet)
        ((unsigned int*)this)[0xec / 4] |= (1 << aIndex);
    else
        ((unsigned int*)this)[0xec / 4] &= ~(1 << aIndex);
}
