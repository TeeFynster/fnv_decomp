// fallout_shared/bgspickupputdownsounds.cpp: TESIcon, BGSPickupPutdownSounds (8 functions)

#include "layout_support.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BGSClipRoundsForm.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/TESIcon.h"
#include "../../include/TESSound.h"
#include "../../include/BGSEquipType.h"
// CombatNode_bgspickupputdownsounds: local type (was include/CombatNode.h, which had no evidence of one real class); its methods are 0x00505c00 TESCombatStyle::GetPowerAttackF, 0x00505c20 TESCombatStyle::GetPowerAttackB, 0x005524b0 TESCombatStyle::GetPowerAttackChance, 0x006a9560 TESCombatStyle::GetPowerAttackL
class CombatNode_bgspickupputdownsounds
{
public:
    unsigned int FUN_00726070();
    signed char GetByteAtOffset8C();
    bool HasCombatFlag(int);
    signed char FUN_0073cb80();
    signed char TESCombatStyle_GetPowerAttackF();
    signed char GetByteAtOffset9A();
    signed char GetByteAtOffset9B();
    signed char FUN_009e8670();
};
#include "../../include/TESFullName.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESRaceForm.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESWeightForm.h"

#include "bgspickupputdownsounds_decls.h"

// @fnv 0x00402c20
TESIcon::TESIcon() : TESTexture()
{}

// Resolves the pickup and putdown sound form IDs to TESSound objects, warning when either sound cannot be found.
// @fnv 0x0047b6a0
void BGSPickupPutdownSounds::InitItem(TESForm* owner)
{
    struct InitData
    {
        unsigned int formID;
        TESFile* file;
    } initData;

    initData.formID = (unsigned int)m_pPickupSound;
    initData.file = owner ? owner->GetFile(-1) : 0;

    if (initData.formID)
    {
        TESForm::RemapFormIDForFile(initData.formID, initData.file);
        m_pPickupSound = dynamic_cast<TESSound*>(GetFormByID(initData.formID));
        if (!m_pPickupSound)
        {
            if (owner)
            {
                if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find pickup sound (%08X) for owner object \"%s\".", initData.formID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find pickup sound  (%08X) for owner object (%08X).", initData.formID,
                            owner->GetFormID());
            }
            else
            {
                Warning("MASTERFILE: Unable to find pickup sound  (%08X) for unknown owner.", initData.formID);
            }
        }
    }

    initData.formID = (unsigned int)m_pPutdownSound;
    if (initData.formID)
    {
        TESForm::RemapFormIDForFile(initData.formID, initData.file);
        m_pPutdownSound = dynamic_cast<TESSound*>(GetFormByID(initData.formID));
        if (!m_pPutdownSound)
        {
            if (owner)
            {
                if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find putdown sound (%08X) for owner object \"%s\".", initData.formID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find putdown sound  (%08X) for owner object (%08X).",
                            initData.formID, owner->GetFormID());
            }
            else
            {
                Warning("MASTERFILE: Unable to find putdown sound  (%08X) for unknown owner.", initData.formID);
            }
        }
    }
}

extern int DAT_0101abd8;
void __fastcall BGSPickupPutdownSounds_InitializeDataComponent(void* pThis);

// Initialises the BaseFormComponent base, installs the vtable from DAT_0101abd8, calls FUN_0047b540, and returns pThis.
// @fnv 0x0047b4f0
// src: EXE 0x0047b4f0
void* __fastcall BGSPickupPutdownSounds_BGSPickupPutdownSounds(BaseFormComponent* apComponent)
{
    apComponent->BaseFormComponent::BaseFormComponent();
    *(int**)apComponent = &DAT_0101abd8;
    BGSPickupPutdownSounds_InitializeDataComponent(apComponent);
    return apComponent;
}

// @fnv 0x0047b540
// src: XBOX_PDB 0x0047b540
void __fastcall BGSPickupPutdownSounds_InitializeDataComponent(void* pThis)
{
    *(int*)((char*)pThis + 4) = 0;
    *(int*)((char*)pThis + 8) = 0;
}

// Aggregate parameters stay on the stack under __fastcall, preserving the
// component argument's original calling convention for these free functions.
struct PickupPutdownComponentArgument
{
    BaseFormComponent* component;
};

// Exe 0x0047b5d0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BgspickupputdownsoundsOffset08View
{
    unsigned int GetFlags();
};
// Copies pickup and putdown sound references when the component has the matching type.
// @fnv 0x0047b5d0
void __fastcall CopyPickupPutdownSounds(BGSPickupPutdownSounds* sounds, PickupPutdownComponentArgument argument)
{
    BGSPickupPutdownSounds* source = dynamic_cast<BGSPickupPutdownSounds*>(argument.component);
    if (!source)
        return;
    ((TESRaceForm*)sounds)->Initialize(((CombatNode_bgspickupputdownsounds*)source)->FUN_00726070());
    ((TESObjectREFR*)sounds)->SetFlags(((BgspickupputdownsoundsOffset08View*)source)->GetFlags());
}

namespace fnv_0047b560 {
// Exe 0x0047b560: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BgspickupputdownsoundsOffset08View
{
    unsigned int GetFlags();
};
struct ItemList
{
    void* GetItem();
};
extern "C" void __cdecl TESForm_AddChunk_00485910(int, int);
// @fnv 0x0047b560
void __fastcall LogFormIDs(BGSPickupPutdownSounds* sounds)
{
    if (((ItemList*)sounds)->GetItem())
    {
        unsigned int id = ((TESForm*)((ItemList*)sounds)->GetItem())->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e59, id);
    }
    if (((BgspickupputdownsoundsOffset08View*)sounds)->GetFlags())
    {
        unsigned int id = ((TESForm*)((BgspickupputdownsoundsOffset08View*)sounds)->GetFlags())->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e5a, id);
    }
}
}  // namespace fnv_0047b560

namespace fnv_0047b630 {
// Exe 0x0047b630: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BgspickupputdownsoundsOffset08View
{
    unsigned int GetFlags();
};

// Returns false only when the component has the matching type and both sound references match.
// @fnv 0x0047b630
bool __fastcall IsSamePickupPutdownSounds(BGSPickupPutdownSounds* sounds, PickupPutdownComponentArgument argument)
{
    BGSPickupPutdownSounds* pickup = dynamic_cast<BGSPickupPutdownSounds*>(argument.component);
    if (pickup == 0)
        return true;
    if (reinterpret_cast<CombatNode_bgspickupputdownsounds*>(sounds)->FUN_00726070() != reinterpret_cast<CombatNode_bgspickupputdownsounds*>(pickup)->FUN_00726070() ||
        reinterpret_cast<BgspickupputdownsoundsOffset08View*>(sounds)->GetFlags() != reinterpret_cast<BgspickupputdownsoundsOffset08View*>(pickup)->GetFlags())
        return true;
    return false;
}
}  // namespace fnv_0047b630

extern int DAT_0101abd8;

// @fnv 0x0047b520
void __fastcall FreePickupPutdownSounds(BGSPickupPutdownSounds* sounds)
{
    *(int**)sounds = &DAT_0101abd8;
    reinterpret_cast<TESForm*>(sounds)->TESForm::ClearData();
}
