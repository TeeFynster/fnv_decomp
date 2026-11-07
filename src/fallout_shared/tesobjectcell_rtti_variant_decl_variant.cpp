
// src/fallout_shared/tesobjectcell_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x005434d0: the skeleton of src/fallout_shared/tesobjectcell_rtti_variant.cpp
// with declarations corrected to what the original code does (tesobjectcell_packet_rtti_variant.h: public: virtual ~TESObjectCELL(); -> public: virtual ~TESObjectCELL(); virtual void Vir; tesobjectcell_packet_rtti_variant.h: TESObjectCELL += bool FUN_005434d0(struct FormGroupQuery* group); bool IsFormTypeBelowThreshold(struct FormGroupQuery* group); unsigned int FUN_00544). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tesobjectcell_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectCELL, TESObjectREFR, TESWorldSpace). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "../../include/TESObjectCELL.h"
#include "../../include/BGSLoadedReferenceCollection.h"
#include "../../include/NiNode.h"
#include "../../include/MobileObject.h"
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESObject.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/BaseExtraList.h"
#include "../../include/ExtraDataList.h"
#include "../../include/PlayerMover.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESSound.h"
#include "../../include/TESWorldSpace.h"
// Private packet declarations, with shared-header definitions supplied above.
struct TESRecordHeader;
class TESImageSpaceModifier;
template <class T> class BSSimpleList;
class BGSEncounterZone;
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
class BSExtraData;
#include "../../include/RecursiveSpinLock.h"
class ExteriorCellData
{
  public:
    int x;
    int y;
};
class TESWorldSpace;

void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int TESTerrainLODManager_GetGrassNode();
NiAVObject* TESMain_GetWeatherRoot();
class RefView : public TESObjectREFR
{
  public:
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual bool IsActor();  // +0x100
    virtual void v0x41();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void Unk_1c4();  // +0x1c4
    virtual void v072();
    virtual void Unk_1cc(int iA, int iB);  // +0x1cc
    virtual void* GetNode3D();             // +0x1d0
    virtual void v0x75();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void SetParentCell(TESObjectCELL* pkCell);  // +0x228
    virtual void v0x8b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void Unk_240();  // +0x240
    virtual void v091();
    virtual void v092();
    virtual void Unk_24c();  // +0x24c

    void* BGSSaveFormBuffer_GetForm();
    bool TESObjectREFR_GetVisibleDistant();
    bool FUN_00440da0();  // GetDisabled
    class RefExtra* BSFile_GetDevice();
    TESObjectCELL* FUN_008d6f30();  // GetParentCell
    bool TESObjectREFR_HasScript();
    bool TESObjectREFR_IsActivatingChildren();
    bool TESForm_GetDisabledOrDeleted();
    void TESObjectREFR_AddLight(int iValue);
    bool TESForm_GetReflectedByAutoWater();
    bool IsFlag20000000Set();
};
class RefExtra
{
  public:
    void ExtraDataList_SetPersistentCell(TESObjectCELL* pkCell);
};
struct RefList
{
    void FUN_005ae3d0(RefView*& rpkRef);  // AddHead
    bool BSSimpleList_TESLevSpell_IsInList(RefView*& rpkRef);  // IsInList
};
extern RefList DAT_011ca13c;
extern RefList DAT_011ca144;
class CellNavHandler
{
  public:
    void AddToPersistentRefData(RefView* pkRef);
};
class CellDataHandler
{
  public:
    bool FUN_004516b0();
};
extern CellDataHandler* DAT_011c3f2c;
class CellTES
{
  public:
    bool FUN_004511e0(TESObjectCELL* pkCell, int iValue);
    int TES_GetCellPriority(TESObjectCELL* pkCell, int iA, int iB);
};
extern CellTES* DAT_011dea10;
class CellPlayer
{
  public:
    bool FUN_0094df60();
};
// IsSleepingOrResting
extern CellPlayer* DAT_011dea3c;
class CellSaveLoad
{
  public:
    bool FUN_0047c850();
};
extern CellSaveLoad* DAT_011de45c;
class CellModelLoader
{
  public:
    void ModelLoader_QueueReference(RefView* pkRef, int iCell);
};
extern CellModelLoader* DAT_011c3b3c;
class CellProcessLists
{
  public:
    void FUN_0096e870(RefView* pkRef);
};
extern CellProcessLists DAT_011e0e80;
class CellNodeMap
{
  public:
    bool RemoveKey(void* pvNode);
};
extern CellNodeMap DAT_011ca0f4;
class CellTaskQueue
{
  public:
    void TaskQueueInterface_QueueSet3DNull(RefView* pkRef);
};
CellTaskQueue* FUN_004537b0();
bool AILinearTaskThreadManager_ShouldQueue3DTask();

class ReferenceList
{
  public:
    TESObjectREFR* item;
    ReferenceList* next;
    ReferenceList();
    ~ReferenceList();
    bool IsEmpty();
    TESObjectREFR*& GetItem();
    ReferenceList* GetNext();
    void Append(TESObjectREFR*& reference);
    void RemoveAll();
};
// Verified native methods use only their typed receiver in ECX.
ReferenceList* __fastcall GetRefList_009604f0(TESObjectCELL* cell);
TESObjectCELL* __fastcall FUN_005f36f0(TESWorldSpace* world);
TESBoundObject* __fastcall BGSSaveFormBuffer_GetForm(TESObjectREFR* reference);
bool __fastcall FUN_00440d80(const TESObjectREFR* reference);
bool __fastcall FUN_00440da0(TESObjectREFR* reference);
bool __fastcall FUN_00477ba0(TESObjectREFR* reference);
void* __fastcall FUN_00568e50(TESObjectREFR* reference);
void __fastcall TESObjectCELL_CellRefLockLeave(TESObjectCELL* cell);
unsigned int __cdecl GetRandomNumberInRange(int low, int high);
TESObjectREFR* __cdecl TESObjectCELL_PickRandomTeleportDoorInSpace(TESForm* source, TESForm* destination, void* context);

struct FormGroupQuery
{
    unsigned int tag, unk04, value, kind;
};
extern unsigned int DAT_01187020;
TESForm* TESForm_GetFormByNumericID(unsigned int);
// @fnv 0x005434d0
// src: XBOX_PDB 0x005434d0
bool TESObjectCELL::SavesBefore(FormGroupQuery* group)
{

    bool matched = false;

    if (group && group->tag == DAT_01187020)
    {

        switch (group->kind)
        {

        case 0:
            matched = IsFormTypeBelowThreshold(group);
            break;

        case 2:

            if (IsCellInterior() && GetGroupBlockKey() < group->value)

                matched = true;

            break;

        case 3:

            if (IsCellInterior() && GetGroupSubBlockKey() < group->value)

                matched = true;

            break;

        case 6:
        case 8:
        case 9: {

            TESObjectCELL* cell = dynamic_cast<TESObjectCELL*>(TESForm_GetFormByNumericID(group->value));

            if (cell)

                matched = Sort(cell);

            break;
        }

        case 4:

            if (!IsCellInterior())
            {

                if (FUN_005516c0())
                    matched = true;

                else if (GetGroupBlockKey() < group->value)
                    matched = true;
            }
            else
                matched = true;

            break;

        case 5:

            if (!IsCellInterior())
            {

                if (FUN_005516c0())
                    matched = true;

                else if (GetGroupSubBlockKey() < group->value)
                    matched = true;
            }
            else
                matched = true;

            break;

        case 1:

            if (!IsCellInterior())
            {

                TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(TESForm_GetFormByNumericID(group->value));

                if (world)

                    matched = Sort(world);
            }
            else
                matched = true;

            break;

        case 7:
            matched = true;
            break;
        }
    }

    return matched;
}
