
// src/fallout_shared/tesobjectrefr_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobjectrefr.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "tesobjectrefr_decls.h"
#include "../../include/BSExtraData.h"
#include "../../include/NonActorMagicTarget.h"
GarbageCollectorUpdateState* MemoryLevelManager_GetSingleton();
void* DecalData_GetDefaultDecalData();
void FalloutRadio_NewCellEntered();
void TESWaterSystem_SetPlayerForceUnderwater(unsigned char value);
float BSAudio_GetMinDialogDist();
float BSAudio_GetMaxDialogDist();
void CheckWithinMultiBoundTask_CancelAttachment(unsigned int index);

struct ExtraList
{
    BSExtraData* BaseExtraList_GetExtraData(int type);
    void BaseExtraList_AddExtra(BSExtraData* p);
};
bool __cdecl TESMagicTargetForm_CanBeMagicTarget(int x);
class Owner
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int flag);
    int BGSSaveFormBuffer_GetForm();
    ExtraList* BSFile_GetDevice();
    MagicTarget* TESObjectREFR_GetMagicTarget();
};
// @fnv 0x00575f30
// src: COMMUNITY 0x00575f30
MagicTarget* Owner::TESObjectREFR_GetMagicTarget()
{
    NonActorMagicTarget* p = 0;
    if (TESMagicTargetForm_CanBeMagicTarget(BGSSaveFormBuffer_GetForm()))
    {
        p = dynamic_cast<NonActorMagicTarget*>(BSFile_GetDevice()->BaseExtraList_GetExtraData(0x33));
        if (!p)
        {
            p = new NonActorMagicTarget(this);
            BSFile_GetDevice()->BaseExtraList_AddExtra(p);
            v18(0x80000000);
        }
    }
    return p;
}
