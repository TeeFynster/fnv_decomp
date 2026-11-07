// src/unmapped/memcpyp_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/unmapped/memcpyp.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Item
{
    virtual void Reserved();
    virtual void Destroy();
    volatile long references;
};

struct Owner
{
    unsigned char unk00[0x4c];
    Item* item;
    void NiPixelData_SetPalette(Item* replacement);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

// @fnv 0x00a76a60
// src: COMMUNITY 0x00a76a60
void Owner::NiPixelData_SetPalette(Item* replacement)
{
    Item* previous = item;
    if (previous != replacement)
    {
        if (previous && InterlockedDecrement(&previous->references) == 0)
            previous->Destroy();
        item = replacement;
        if (replacement)
            InterlockedIncrement(&replacement->references);
    }
}
