// fallout_shared/tesobjectcell_packet.h: unit-local DoorCell, GarbageCollectorObjectPtr, InteriorCellData,
// CellLightingTemplate, ExteriorCellData; the game classes come from include/.
#ifndef TESOBJECTCELL_PACKET_H
#define TESOBJECTCELL_PACKET_H

#include "../../include/TESFile.h"
#include "../../include/PlayerMover.h"
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/NiNode.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/NiAVObject.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESSound.h"
#include "../../include/BSSimpleList.h"
#include "../../include/BGSLoadedReferenceCollection.h"
#include "../../include/BaseExtraList.h"
#include "../../include/ExtraDataList.h"
#include "../../include/RecursiveSpinLock.h"
#include "../../include/TESObjectCELL.h"

class TESForm;
class DoorCell
{
  public:
    TESForm* GetOwner();
};
extern unsigned int DAT_011ca438;
class GarbageCollectorObjectPtr
{
  public:
    NiAVObject* operator->() const;
};
class GlobalObject_00633c90 : public GarbageCollectorObjectPtr
{
};
extern GlobalObject_00633c90 g_011deda4;
struct InteriorCellData
{
    char pad[0x20];
    float clipDist;
};
class CellLightingTemplate
{
  public:
    float TESCombatStyle_GetWeaponMinRangeMult();
};
extern BGSLoadedReferenceCollection* DAT_011c95c8;
class ActorCause;
class ExteriorCellData
{
  public:
    int x;
    int y;
};

#endif
