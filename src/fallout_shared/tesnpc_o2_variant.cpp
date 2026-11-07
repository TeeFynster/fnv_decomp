
// src/fallout_shared/tesnpc_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesnpc.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// include/TESFile.h needs the Windows types before layout_support.h stubs them.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "../../include/ActorBaseAttributes.h"
#include "../../include/ActorSkillData.h"
#include "../../include/BGSBipedModelList.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSHeadPart.h"
#include "../../include/BGSListForm.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/BGSTouchSpellForm.h"
#include "../../include/BSFaceGenAnimationData.h"
#include "../../include/BSFaceGenNiNode.h"
#include "../../include/CombatController.h"
#include "../../include/ExtraDismemberedLimbs.h"
#include "../../include/MagicCaster.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiNode.h"
#include "../../include/NiUpdateData.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimation.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESClass.h"
#include "../../include/TESCombatStyle.h"
#include "../../include/TESContainer.h"
#include "../../include/TESEyes.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESHair.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESNPC.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESRace.h"
#include "../../include/TESRaceForm.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSpellList.h"
#include "../../include/TESTopic.h"

// Adjustor thunk for FUN_0060c440: "sub ecx, 0xdc; jmp FUN_00601370".
//
// This is the MSVC this-adjusting thunk that the compiler emits for a virtual
// function inherited from a secondary base: it converts the secondary base
// sub-object pointer (this + 0xdc) back into the derived object pointer
// (sub ecx, 0xdc) and tail-jumps to the final overrider.
//
// The subtracted offset is the size of the first base, so the first base is
// laid out as a vtable pointer plus 54 int members (4 + 54 * 4 = 0xdc bytes).
// Both bases declare the same virtual function, the derived class redeclares
// it and only defines its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_0060c440();
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_0060c440();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c440
// src: GUESS 0x0060c440 (confidence: low)
    virtual void AdjustThisAndForward_0060c440();
};

Derived::Derived()
{}

// FUN_0060c450 is a MSVC this-adjusting thunk (adjustor thunk).
//
// The class AdjustorThunkHolder inherits AdjustorSecondaryBase at offset
// 0x7c (the primary base is 0x7c bytes long), and overrides the virtual
// function FUN_0060c450 that AdjustorSecondaryBase declares.  For that
// override the compiler emits a thunk that moves `this` back to the
// secondary base sub-object and jumps to the implementation:
//
//     sub ecx, 0x7c
//     jmp AdjustorThunkHolder::FUN_0060c450
//
// The overriding implementation itself lives in another translation unit,
// so it is only declared here.

struct AdjustorPrimaryBase
{
    virtual void FUN_0060c450();
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
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
};

struct AdjustorSecondaryBase
{
    virtual void FUN_0060c450();
};

struct AdjustorThunkHolder : AdjustorPrimaryBase, AdjustorSecondaryBase
{
// @fnv 0x0060c450
    virtual void FUN_0060c450();
    AdjustorThunkHolder();
};

AdjustorThunkHolder::AdjustorThunkHolder()
{}

namespace fnv_0060c460 {
struct PrimaryBase
{
    virtual void AdjustThisAndForward_0060c460();
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_0060c460();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c460
// src: GUESS 0x0060c460 (confidence: low)
    virtual void AdjustThisAndForward_0060c460();
};

Derived::Derived()
{}
}  // namespace fnv_0060c460

namespace fnv_0060c470 {
// Adjustor (this-adjusting) thunk for FUN_0060c470:
//     sub ecx, 0x90 ; jmp FUN_00608e00
// MSVC emits such a thunk in the vftable of a class that inherits the same
// virtual from two bases: the thunk converts the secondary base sub-object
// pointer back to the primary base pointer by subtracting the size of the
// primary base (0x90 = 4 byte vptr + 35 int members) and tail jumps to the
// implementation.  Both bases declare the virtual, the derived class
// redeclares it and defines only its constructor, which makes the compiler
// emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0060c470();
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

struct SecondaryBase
{
    virtual void FUN_0060c470();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c470
    virtual void FUN_0060c470();
};

Derived::Derived()
{}
}  // namespace fnv_0060c470

// Adjustor thunk: sub ecx,0x90 ; jmp <base virtual>.
// The primary base occupies 0x90 bytes, so the secondary base sub-object starts
// at +0x90 and the compiler emits an adjustor thunk for the secondary base's
// virtual slot, moving 'this' back onto the secondary base before the jump.
struct AdjPrimaryBase
{
    virtual void FUN_0060c490();
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

struct AdjSecondaryBase
{
    virtual void FUN_0060c490();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x0060c490
    virtual void FUN_0060c490();
};

AdjDerived::AdjDerived()
{}

namespace fnv_0060c4a0 {
// Adjustor (this-adjusting) thunk for FUN_0060c4a0: "sub ecx, 0x7c; jmp FUN_00608e00".
// PrimaryBase is the first base (vptr + 30 int fields = 0x7c bytes); SecondaryBase
// declares the same virtual; Derived derives from both, redeclares the virtual and
// defines only its constructor, so the compiler emits the adjusting thunk.
struct PrimaryBase
{
    virtual void* FUN_0060c4a0(unsigned int flags);
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void* FUN_0060c4a0(unsigned int flags);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c4a0
    virtual void* FUN_0060c4a0(unsigned int flags);
};

Derived::Derived()
{}
}  // namespace fnv_0060c4a0
