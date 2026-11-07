#include "../../include/BSStringT.h"

// src/fallout_shared/tesdescription_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesdescription.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/TESObjectBOOK.h"
#include "../../include/TESDescription.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"

typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
typedef char _sizecheck_TESIcon[sizeof(TESIcon) == 12 ? 1 : -1];

extern "C" unsigned char DAT_011c54ba;
unsigned char TESForm_QEndianSwapOnSave();

extern int DAT_011c5490;
void __cdecl WriteDescChunk(void*, int);

// Adjustor thunk: the secondary-base (+0x3c) vtable entry for an override defined on the derived class.

class D1CC0Primary
{
  public:
    virtual void AdjustThisAndForward_00501cc0(unsigned int uiValue);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

class D1CC0Secondary
{
  public:
    virtual void AdjustThisAndForward_00501cc0(unsigned int uiValue);
};

class D1CC0Derived : public D1CC0Primary, public D1CC0Secondary
{
  public:
    D1CC0Derived();
// @fnv 0x00501cc0
// src: GUESS 0x00501cc0 (confidence: low)
    virtual void AdjustThisAndForward_00501cc0(unsigned int uiValue);
};

D1CC0Derived::D1CC0Derived()
{}

// Synthetic thunk emitter: 0x88 bytes and two primary virtual slots, unlike TESObjectBOOK's 0xc4-byte layout and BookData at 0xc0.
// Its secondary base models only the +0x84 adjustment into the owner; the override
// target is TESObjectBOOK::FUN_00515220 (0x00515220), also bound in tesobjectbook.cpp.
struct SaveSizeThunkPrimary
{
    virtual void Slot0();
    virtual unsigned short GetOwnerSaveSize(unsigned int changeFlags);
    unsigned char prefix[0x80];
    SaveSizeThunkPrimary() throw();
};

struct SaveSizeThunkSecondary
{
    virtual unsigned short GetOwnerSaveSize(unsigned int changeFlags);
    SaveSizeThunkSecondary() throw();
};

struct SaveSizeThunkEmitter : SaveSizeThunkPrimary, SaveSizeThunkSecondary
{
// @fnv 0x00515430
    virtual unsigned short GetOwnerSaveSize(unsigned int changeFlags);
    SaveSizeThunkEmitter() throw();
};

SaveSizeThunkEmitter::SaveSizeThunkEmitter() throw()
{}
