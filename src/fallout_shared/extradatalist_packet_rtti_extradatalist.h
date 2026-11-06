// fallout_shared/extradatalist_packet_rtti_extradatalist.h: declares BaseExtraList, ExtraDataList, TaskQueueInterface
#ifndef FNV_EXTRADATALIST_PACKET_H
#define FNV_EXTRADATALIST_PACKET_H

// Canonical layouts come from include/ (src/fallout_shared has same-named local headers, so the shadowed ones are
// included by path). This unit owns BaseExtraList and ExtraDataList and uses their shared definitions.
#include "../../include/layout_support.h"
class ExtraDismemberedLimbs;
class SeenData;
class LockExtraData;
class TESImageSpaceModifier;
#include "../../include/ExtraDataList.h"
#include "../../include/TESObjectREFR.h"
#include "Actor.h"
#include "BaseProcess.h"
#include "RecursiveSpinLock.h"
#include "NiMemObject.h"
// No canonical headers yet for these.
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
};
extern TaskQueueInterface* DAT_011df1a8;
// include/layout_support.h declares TESObjectCELL, TESDataHandler and TESObjectREFR without these members.
struct FUN_004610d0_shell : public TESDataHandler
{
    BSSimpleList<TESImageSpaceModifier*>* GetTESImageSpaceModifierList();
};
struct FUN_00555bc0_shell : public TESObjectCELL
{
    SeenData* FindSeenData();
};
struct FUN_00569140_shell : public TESObjectREFR
{
    LockExtraData* GetMyLock();
};
struct FUN_00569580_shell : public TESObjectREFR
{
    TESForm* GetOwnerForm();
};
extern void* kVtbl_ExtraDataList[];
#endif
