#pragma once

#include "NiObject.h"
#include <stddef.h>

class NiPalette : public NiObject
{
public:
    struct PaletteColorEntry
    {
        unsigned char r, g, b, a;
    };

    NiPalette(const NiPalette& src) throw();
    NiPalette(bool, unsigned int, const PaletteColorEntry*) throw();
    virtual ~NiPalette();
    virtual void DeleteThis();


    unsigned int GetEntries(PaletteColorEntry*& entries) const throw();
    PaletteColorEntry* GetEntries(unsigned int& count) const throw();
    void IncRefCount();
    void DecRefCount();
    void* DestroyPalette(unsigned int);

    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
};
