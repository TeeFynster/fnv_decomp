
// src/fallout_shared/bgsmovablestatic_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/bgsmovablestatic.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "../../include/BGSMovableStatic.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESSound.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObjectSTAT.h"

class unkOwnerBase
{
  public:
    virtual ~unkOwnerBase();
    int unk04;
    int unk08;
};

class BGSMovableStaticOwner : public unkOwnerBase, public BGSDestructibleObjectForm, public TESObjectSTAT
{
};

void FixupFormID(unsigned int* formID, TESFile* file);
TESForm* LookupForm(unsigned int formID);
void FNV_Warning(const char* fmt, ...);

// @fnv 0x004fbb70
// src: XBOX_PDB 0x004fbb70
void TESObjectSTAT::BGSMovableStatic_InitItem()
{
    if (GetInitialized())
        return;

    ((BGSMovableStaticOwner*)((char*)this - 0x14))
        ->BGSDestructibleObjectForm::InitItem(
            ((BGSMovableStaticOwner*)((char*)this - 0x14))
                ? (TESForm*)((char*)((BGSMovableStaticOwner*)((char*)this - 0x14)) + 0x14)
                : (TESForm*)0);
    ((BGSMovableStaticOwner*)((char*)this - 0x14))
        ->TESModelTextureSwap::InitItem(((BGSMovableStaticOwner*)((char*)this - 0x14))
                                            ? (TESForm*)((char*)((BGSMovableStaticOwner*)((char*)this - 0x14)) + 0x14)
                                            : (TESForm*)0);

    unsigned int soundID = (unsigned int)((BGSMovableStatic*)((char*)this - 0x14))->soundLoop;
    if (soundID)
    {
        FixupFormID(&soundID, GetFile(-1));
        ((BGSMovableStatic*)((char*)this - 0x14))->soundLoop = dynamic_cast<TESSound*>(LookupForm(soundID));
        if (!((BGSMovableStatic*)((char*)this - 0x14))->soundLoop)
            FNV_Warning("MASTERFILE: Could not find looping sound (%08X) for movable static '%s' (%08X).", soundID,
                        ((TESForm*)((char*)((BGSMovableStaticOwner*)((char*)this - 0x14)) + 0x14))->GetName(),
                        GetFormID());
    }

    SetInitializationState(true);
}
