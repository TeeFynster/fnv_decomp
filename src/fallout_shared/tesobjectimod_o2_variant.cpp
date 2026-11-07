
// src/fallout_shared/tesobjectimod_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectimod.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/TESObjectIMOD.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/TESForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESDescription.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"
#include "../../include/ENUM_FORM_ID.h"

struct B1
{
    virtual void AdjustThisAndForward_0051a680(unsigned int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
};

struct B2
{
    virtual void AdjustThisAndForward_0051a680(unsigned int);
};

struct Derived : B1, B2
{
    Derived();
// @fnv 0x0051a680
// src: GUESS 0x0051a680 (confidence: low)
    virtual void AdjustThisAndForward_0051a680(unsigned int);
};

Derived::Derived()
{}
