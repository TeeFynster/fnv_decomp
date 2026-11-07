
// src/fallout_shared/tesobjectcell_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectCELL, TESObjectREFR, TESWorldSpace). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "../../include/Actor.h"
#include "../../include/BaseExtraList.h"
#include "../../include/BGSLoadedReferenceCollection.h"
#include "../../include/ExtraDataList.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/MobileObject.h"
#include "../../include/NiUpdateData.h"
#include "../../include/Sky.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESWeather.h"
#include "../../include/BSExtraData.h"
#include "../../include/NiColor.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObject.h"

class NiAVObject;
extern BGSLoadedReferenceCollection* DAT_011c95c8;

void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int TESTerrainLODManager_GetGrassNode();
NiAVObject* TESMain_GetWeatherRoot();


struct FUN_0040f410 : BSExtraData
{
    unsigned int references;
    FUN_0040f410();
};
// BaseExtraList.h lacks the pointer-and-destroy removal overload at 0x00410020.
// Keep only that declaration here; the data layout comes from the shared base.
struct ExtraDataRemoval : BaseExtraList
{
    bool RemoveExtraData(BSExtraData*, bool);
};
struct RefList548
{
    TESObjectREFR* item;
    RefList548* next;
    TESObjectREFR*& FUN_006815c0();
    RefList548* FUN_00726070();
};
class GlobalObject_0096d020
{
  public:
    void FUN_0096e870(MobileObject*);
};
// The shared cell header does not yet declare the loaded-3D reference operation.
// This extension adds only that declaration; TESObjectCELL owns the layout.
struct Cell3DReferenceAccess : TESObjectCELL
{
    void TESObjectCELL_SetLowestProcessToMiddleLow(bool RetainReference);
};

class RefX : public TESObjectREFR
{
  public:
    virtual void Unk_240();
    virtual void v091();
    virtual void v092();
    virtual void Unk_24c();

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
    void FUN_005ae3d0(RefX*& rpkRef);  // AddHead
    bool BSSimpleList_TESLevSpell_IsInList(RefX*& rpkRef);  // IsInList
};
extern RefList DAT_011ca13c;
extern RefList DAT_011ca144;

class CellNavHandler
{
  public:
    void AddToPersistentRefData(RefX* pkRef);
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
};  // IsSleepingOrResting
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
    void ModelLoader_QueueReference(RefX* pkRef, int iCell);
};
extern CellModelLoader* DAT_011c3b3c;
class CellProcessLists
{
  public:
    void FUN_0096e870(RefX* pkRef);
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
    void TaskQueueInterface_QueueSet3DNull(RefX* pkRef);
};
CellTaskQueue* FUN_004537b0();
bool AILinearTaskThreadManager_ShouldQueue3DTask();
// Declarations absent from TESObjectCELL.h; no duplicate cell layout or vtable.
class CellReferenceAccess : public TESObjectCELL
{
  public:
    CellNavHandler* FUN_0054ddd0();
    bool TESObjectCELL_GetAttached();
    bool TESObjectCELL_GetAttaching();
    void TESObjectCELL_AddScriptedRef(RefX* pkRef);
    void TESObjectCELL_AttachReference3D(RefX* pkRef, bool bArg);
    bool TESObjectCELL_IsLoading();
};

// @fnv 0x00548230
void TESObjectCELL::AddReference(RefX* pkRef, bool bArg)
{
    if (!pkRef || !pkRef->BGSSaveFormBuffer_GetForm())
        return;
    if (pkRef->TESObjectREFR_GetVisibleDistant() && !pkRef->FUN_00440da0())
        (*reinterpret_cast<unsigned short*>(formData + 0x84))++;
    if (FUN_005516c0())
    {
        CellRefLockEnter();
        reinterpret_cast<RefList*>(GetRefList_009604f0())->FUN_005ae3d0(pkRef);
        CellRefLockLeave();
        pkRef->BSFile_GetDevice()->ExtraDataList_SetPersistentCell(this);
        CellNavHandler* pkHandler = static_cast<CellReferenceAccess*>(this)->FUN_0054ddd0();
        if (pkHandler)
            pkHandler->AddToPersistentRefData(pkRef);
        if (!DAT_011c3f2c->FUN_004516b0())
            SetAltered(true);
        return;
    }
    TESObjectCELL* pkOldCell = pkRef->FUN_008d6f30();
    if (pkOldCell)
        pkOldCell->RemoveReference(pkRef);
    CellRefLockEnter();
    reinterpret_cast<RefList*>(GetRefList_009604f0())->FUN_005ae3d0(pkRef);
    pkRef->SetParentCell(reinterpret_cast<TESObjectCELL*>(this));
    CellRefLockLeave();
    if (static_cast<CellReferenceAccess*>(this)->TESObjectCELL_GetAttached())
        DAT_011c95c8->AddReference_00526f20((BGSPerkEntry*)pkRef);
    if ((*reinterpret_cast<void**>(formData + 0xA0)))
    {
        if ((!pkRef->IsActor() || pkRef->FUN_00440da0()) && pkRef->TESObjectREFR_HasScript())
            static_cast<CellReferenceAccess*>(this)->TESObjectCELL_AddScriptedRef(pkRef);
        if (pkRef->TESObjectREFR_IsActivatingChildren())
            AddActivatingRef(pkRef);
    }
    if (!pkRef->FUN_00440da0() && pkRef->GetNiNode())
    {
        MobileObject* pkMobile = dynamic_cast<MobileObject*>(static_cast<TESObjectREFR*>(pkRef));
        if (!pkMobile)
            pkRef->AnimateNiNode();
    }
    bool bHandled = false;
    if (!DAT_011c3f2c->FUN_004516b0() && !bHandled && !pkRef->TESForm_GetDisabledOrDeleted())
    {
        void* pvNode = pkRef->GetNiNode();
        if (DAT_011dea10->FUN_004511e0(this, 0))
        {
            bool bQueue = false;
            if (pvNode)
                static_cast<CellReferenceAccess*>(this)->TESObjectCELL_AttachReference3D(pkRef, bArg);
            else
            {
                if (!pkRef->IsActor())
                    bQueue = true;
                else if (!DAT_011dea3c->FUN_0094df60() && !static_cast<CellReferenceAccess*>(this)->TESObjectCELL_IsLoading())
                    bQueue = true;
                if (bQueue)
                {
                    if (pkRef->IsActor() && (!DAT_011de45c->FUN_0047c850() || DAT_011de45c->FUN_0047c850()))
                    {
                        if (static_cast<CellReferenceAccess*>(this)->TESObjectCELL_GetAttached() || static_cast<CellReferenceAccess*>(this)->TESObjectCELL_GetAttaching())
                            pkRef->Unk_240();
                        else
                            pkRef->Unk_24c();
                    }
                    DAT_011c3b3c->ModelLoader_QueueReference(pkRef, DAT_011dea10->TES_GetCellPriority(this, 0, 0));
                }
            }
            if (!bQueue && pkRef->IsActor())
                DAT_011e0e80.FUN_0096e870(pkRef);
        }
        else
        {
            DAT_011ca0f4.RemoveKey(pkRef->GetNiNode());
            if (pkRef->IsActor() && !DAT_011dea3c->FUN_0094df60() && !DAT_011de45c->FUN_0047c850())
            {
                if (!AILinearTaskThreadManager_ShouldQueue3DTask())
                    pkRef->Set3D(0, false);
                else
                    FUN_004537b0()->TaskQueueInterface_QueueSet3DNull(pkRef);
            }
        }
    }
    pkRef->TESObjectREFR_AddLight(0);
    if (!pkRef->FUN_008d6f30()->IsInterior())
    {
        if (pkRef->TESForm_GetReflectedByAutoWater() && !DAT_011ca13c.BSSimpleList_TESLevSpell_IsInList(pkRef))
            DAT_011ca13c.FUN_005ae3d0(pkRef);
        if (pkRef->IsFlag20000000Set() && !DAT_011ca144.BSSimpleList_TESLevSpell_IsInList(pkRef))
            DAT_011ca144.FUN_005ae3d0(pkRef);
    }
}

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
TESBoundObject* __fastcall BGSSaveFormBuffer_GetForm(TESObjectREFR* reference);
bool __fastcall FUN_00440d80(const TESObjectREFR* reference);
bool __fastcall FUN_00440da0(TESObjectREFR* reference);
bool __fastcall FUN_00477ba0(TESObjectREFR* reference);
void* __fastcall FUN_00568e50(TESObjectREFR* reference);
void __fastcall TESObjectCELL_CellRefLockLeave(TESObjectCELL* cell);
unsigned int __cdecl GetRandomNumberInRange(int low, int high);
// @fnv 0x0054afb0
// src: COMMUNITY 0x0054afb0
TESObjectREFR* __cdecl TESObjectCELL_PickRandomTeleportDoorInSpace(TESForm* source, TESForm* destination, void* context)
{
    TESObjectREFR* result = 0;
    if (source && destination && context && source != destination)
    {
        unsigned int countB = 0;
        ReferenceList candidatesVal;
        ReferenceList* cursor4 = 0;
        TESWorldSpace* world = 0;
        TESObjectCELL* cellVal = dynamic_cast<TESObjectCELL*>(source);
        TESObjectCELL* lockedCellVal = 0;
        if (cellVal)
        {
            cursor4 = GetRefList_009604f0(cellVal);
            lockedCellVal = cellVal;
        }
        else
        {
            world = dynamic_cast<TESWorldSpace*>(source);
            if (world && world->GetInteriorCell())
            {
                cursor4 = GetRefList_009604f0(world->GetInteriorCell());
                lockedCellVal = world->GetInteriorCell();
            }
        }
        lockedCellVal->CellRefLockEnter();
        while (cursor4 && !cursor4->IsEmpty())
        {
            TESObjectREFR* reference = cursor4->GetItem();
            if (BGSSaveFormBuffer_GetForm(reference)->GetFormType() == 28 && !FUN_00440d80(reference) && !FUN_00440da0(reference) &&
                !FUN_00477ba0(reference))
            {
                TESObjectDOOR* door = dynamic_cast<TESObjectDOOR*>(BGSSaveFormBuffer_GetForm(reference));
                if (door && door->IsRandomDoor() && door->HasEntry(destination) && !FUN_00568e50(reference))
                {
                    candidatesVal.Append(reference);
                    ++countB;
                }
            }
            cursor4 = cursor4->GetNext();
        }
        TESObjectCELL_CellRefLockLeave(lockedCellVal);
        if (countB > 0 && !candidatesVal.IsEmpty())
        {
            unsigned int selectedX = GetRandomNumberInRange(0, countB);
            unsigned int index2 = 0;
            cursor4 = &candidatesVal;
            while (cursor4 && !cursor4->IsEmpty())
            {
                if (index2 == selectedX)
                {
                    result = cursor4->GetItem();
                    break;
                }
                else
                {
                    ++index2;
                    cursor4 = cursor4->GetNext();
                }
            }
            candidatesVal.RemoveAll();
        }
    }
    return result;
}

struct ContainerChanges550
{
    float InventoryChanges_RemoveAllItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, int);
};
struct ReferenceAccess550 : TESObjectREFR
{
    ExtraDataList* BSFile_GetDevice();
    void* TESObjectREFR_GetLock();
    void TESObjectREFR_UnLock();
};
struct RefList550
{
    TESObjectREFR* item;
    RefList550* next;
    TESObjectREFR*& FUN_006815c0();
    RefList550* FUN_00726070();
};
extern TESObjectREFR* g_thePlayer;
void TESObjectCELL_UpdateSeenDataForPlayer();
// @fnv 0x0054b5b0
// src: COMMUNITY 0x0054b5b0
void TESObjectCELL::SaveGameTest()
{
    CellRefLockEnter();
    RefList550* position = reinterpret_cast<RefList550*>(GetRefList_009604f0());
    while (position)
    {
        TESObjectREFR* reference = position->FUN_006815c0();
        if (reference && reference != g_thePlayer)
        {
            Actor* actor = dynamic_cast<Actor*>(reference);
            ContainerChanges550* changes =
                reinterpret_cast<ContainerChanges550*>(
                    static_cast<ReferenceAccess550*>(reference)->BSFile_GetDevice()->FUN_00418520());
            if (changes)
                changes->InventoryChanges_RemoveAllItems(reference, g_thePlayer, false, false, true, false, -1, 0);
            // Actor.h still declares slot 0x460 without its reference and float parameters.
            if (actor && !actor->FUN_00440da0() && !actor->FUN_00440d80())
                reinterpret_cast<void (__thiscall*)(Actor*, TESObjectREFR*, float)>(
                    (*reinterpret_cast<void***>(actor))[0x118])(actor, g_thePlayer, 10.0f);
            if (actor && !actor->GetEssential() && !actor->FUN_00440da0() && !actor->FUN_00440d80() &&
                !actor->HasHealth(false))
            {
                actor->Alert(reinterpret_cast<PlayerCharacter*>(g_thePlayer), 0, 0, 0, 0, 0, 1, 0);
                actor->Actor_Kill(0, 0.0f);
            }
            if (static_cast<ReferenceAccess550*>(reference)->TESObjectREFR_GetLock())
                static_cast<ReferenceAccess550*>(reference)->TESObjectREFR_UnLock();
            TESObjectCELL_UpdateSeenDataForPlayer();
        }
        position = position->FUN_00726070();
    }
    CellRefLockLeave();
}

void* __cdecl operator new(unsigned int);

// ExtraCell3D owns the reference count associated with the cell's loaded 3D.

extern GlobalObject_0096d020 g_011e0e80;

// @fnv 0x00551480
// src: XBOX_PDB 0x00551480
void Cell3DReferenceAccess::TESObjectCELL_SetLowestProcessToMiddleLow(bool RetainReference)
{
    FUN_0040f410* extra = static_cast<FUN_0040f410*>((*reinterpret_cast<ExtraDataList*>(formData + 0x04)).GetExtraData(9));
    if (!extra && RetainReference)
    {
        extra = new FUN_0040f410;
        (*reinterpret_cast<ExtraDataList*>(formData + 0x04)).AddExtra(extra);
        CellRefLockEnter();
        RefList548* position = reinterpret_cast<RefList548*>(GetRefList_009604f0());
        while (position && position->FUN_006815c0())
        {
            MobileObject* mobile = dynamic_cast<MobileObject*>(position->FUN_006815c0());
            position = position->FUN_00726070();
            if (mobile && !mobile->FUN_00440da0() && mobile->FUN_008d8520() && mobile->FUN_00931850() == 3)
                g_011e0e80.FUN_0096e870(mobile);
        }
        CellRefLockLeave();
    }
    if (extra)
    {
        if (RetainReference)
            extra->references++;
        else
            extra->references--;
        if (!extra->references)
            static_cast<ExtraDataRemoval*>(static_cast<BaseExtraList*>(&(*reinterpret_cast<ExtraDataList*>(formData + 0x04))))->RemoveExtraData(extra, true);
    }
}

TESForm* TESForm_GetFormByNumericID(unsigned int auiFormId);

class NodeView
{
  public:
    virtual void v000();
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
    virtual void UpdateDownwardPass(NiUpdateData& kData, unsigned int uiFlags);  // +0xa8
    NodeView* NiAVObject_GetParent();
};

class SceneRoot
{
  public:
    virtual void v000();
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
    virtual void Unk_0c4();  // +0xc4
};

class RefNodeView
{
  public:
    virtual void v000();
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
    virtual void v040();
    virtual void v041();
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
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual NodeView* GetNode3D();  // +0x1d0
};

struct RefNodeList
{
    RefNodeView* m_pkItem;
    RefNodeList* m_pkNext;
    bool FUN_008256d0();           // IsEmpty
    RefNodeView** FUN_006815c0();  // GetItem
    RefNodeList* FUN_00726070();   // GetNext
};

class FormTypeView
{
  public:
    int FUN_00401170();
};  // GetFormType
class KeyRefView
{
  public:
    FormTypeView* BGSSaveFormBuffer_GetForm();
};

extern NiColor DAT_011a9b7c;

class LightForm
{
  public:
    virtual void v000();
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
    virtual NiColor* GetColor();  // +0xc0
    int FUN_00401170();           // GetFormType
    unsigned int FUN_005e3fc0();  // packed RGB
    TESWeather* FUN_0059bb30();
};

class BaseLight
{
  public:
    int FUN_00401170();
    unsigned int FUN_005e3fc0();
};

struct SkyColorData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

Sky* FUN_0046dd00();

class PointLightNode
{
  public:
    void SetEffectColor(NiColor& kColor);
};
class PointLightPtr
{
  public:
    PointLightNode* Modelloader_GetReferencedThis();
};

class MapRefView
{
  public:
    LightForm* FUN_00569580();
    BaseLight* BGSSaveFormBuffer_GetForm();
    PointLightPtr* TESObjectREFR_GetLight();
};

class PlayerLightView
{
  public:
    LightForm* PlayerCharacter_GetCurrentRegion();
};

template <class K, class V> struct CellRefMap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* FUN_004b9ba0();                                    // GetFirstPos
    void FUN_006b7f20(void*& rpvPos, K& rkKey, V& rkValue);  // GetNext
};

struct CellLoadedData
{
    int unk00;
    RefNodeList kRefs;                              // +0x04
    CellRefMap<KeyRefView*, NodeView*> kActors;     // +0x0c
    CellRefMap<LightForm*, NiColor*> kColors;       // +0x1c
    CellRefMap<MapRefView*, void*> kMapReferences;  // +0x2c
};

struct CellIntSetting
{
    int* Setting_Int();
};
extern CellIntSetting DAT_011c3ea4;
struct CellFloatSetting
{
    float* Setting_Float_00403e20();
};
extern CellFloatSetting DAT_011ccccc;
struct CellTimer
{
    float FUN_0084d030();
};
extern CellTimer DAT_011f6394;
extern float DAT_0118b698;
extern float DAT_0118b694;
extern float DAT_0102f0e4;

class ManagedTaskQueue : public CellTaskQueue
{
  public:
    void TaskQueueInterface_QueueCellTransformChildTask(NodeView* pkNode);
    void TaskQueueInterface_QueueMorphControllerUpdate(NodeView* pkNode);
};
void RunWithLock(NodeView* pkNode);
class CellShadowScene
{
  public:
    void FUN_00b5d9f0(NodeView* pkNode, int iValue);
};
CellShadowScene* FUN_00450b80(int iValue);
unsigned int BSTreeManager_GetCamera();
bool NodeInFrustum(NodeView* pkNode, unsigned int uiCamera);
bool AILinearTaskThreadManager_ShouldQueue3DTask();

class CellWaterView
{
  public:
    void BGSTerrainManager_SetNeedsImmediateUpdate(int iValue);
};
class CellWaterOwner
{
  public:
    CellWaterView* FUN_00586170();
};

// Update operations not yet declared in the shared cell header.
class CellUpdateAccess : public TESObjectCELL
{
  public:
    bool TESObjectCELL_GetAttached();
    SceneRoot* TESObjectCELL_GetbhkWorld();
    NodeView* FUN_005497a0();
    bool TESObjectCELL_All3DWithVisibleDistantLoaded();
    bool TESObjectCELL_ShouldDisplayHighDetail();
    void TESObjectCELL_FadeToHighDetail();
    CellWaterOwner* FUN_0054ddd0();
    int GetByteAtOffset38();
    void TESObjectCELL_UpdateManagedNodes(float fTimeSinceScaleStart, bool bSkipLoaded);
};
// @fnv 0x00551890
// src: XBOX_PDB 0x00551890
void CellUpdateAccess::TESObjectCELL_UpdateManagedNodes(float fTimeSinceScaleStart, bool bSkipLoaded)
{
    if (IsInterior() && TESObjectCELL_GetAttached())
    {
        SceneRoot* pkRoot = TESObjectCELL_GetbhkWorld();
        if (pkRoot)
            pkRoot->Unk_0c4();
    }
    // NiUpdateData pad3/pad4/pad5 are the flag bytes at offsets 6/7/8.
    bool bThreaded = false;
    if (AILinearTaskThreadManager_ShouldQueue3DTask())
        bThreaded = true;
    NodeView* pkDynamic = FUN_005497a0();
    if (pkDynamic && !bSkipLoaded)
    {
        NiUpdateData kData(fTimeSinceScaleStart, false, bThreaded);
        pkDynamic->UpdateDownwardPass(kData, 0);
        if (*DAT_011c3ea4.Setting_Int() > 1)
        {
            ((ManagedTaskQueue*)FUN_004537b0())->TaskQueueInterface_QueueCellTransformChildTask(pkDynamic);
            if (bThreaded && static_cast<unsigned char>(kData.pad3))
                RunWithLock(pkDynamic);
            if (bThreaded && static_cast<unsigned char>(kData.pad4))
                ((ManagedTaskQueue*)FUN_004537b0())->TaskQueueInterface_QueueMorphControllerUpdate(pkDynamic);
        }
    }
    if ((*reinterpret_cast<short*>(formData + 0x86)) > 0 && TESObjectCELL_All3DWithVisibleDistantLoaded() && TESObjectCELL_ShouldDisplayHighDetail())
        TESObjectCELL_FadeToHighDetail();
    if ((*reinterpret_cast<bool*>(formData + 0xAE)) && FUN_0054ddd0() && GetByteAtOffset38() == 6)
    {
        (*reinterpret_cast<bool*>(formData + 0xAC)) = true;
        (*reinterpret_cast<bool*>(formData + 0xAA)) = false;
        (*reinterpret_cast<bool*>(formData + 0xAB)) = false;
        if (FUN_0054ddd0())
            FUN_0054ddd0()->FUN_00586170()->BGSTerrainManager_SetNeedsImmediateUpdate(1);
        (*reinterpret_cast<bool*>(formData + 0xAE)) = false;
    }
    if ((*reinterpret_cast<bool*>(formData + 0xAA)))
    {
        if (DAT_0118b698 * DAT_0118b694 <= (*reinterpret_cast<float*>(formData + 0xA4)))
        {
            if (FUN_0054ddd0() && !(*reinterpret_cast<bool*>(formData + 0xAC)))
                FUN_0054ddd0()->FUN_00586170()->BGSTerrainManager_SetNeedsImmediateUpdate(1);
            (*reinterpret_cast<bool*>(formData + 0xAC)) = true;
            (*reinterpret_cast<bool*>(formData + 0xAA)) = false;
            (*reinterpret_cast<bool*>(formData + 0xAB)) = false;
        }
        (*reinterpret_cast<float*>(formData + 0xA4)) += DAT_011f6394.FUN_0084d030();
    }
    if ((*reinterpret_cast<CellLoadedData**>(formData + 0xA0)))
    {
        if (bSkipLoaded)
        {
            RefNodeList* pkIter = &(*reinterpret_cast<CellLoadedData**>(formData + 0xA0))->kRefs;
            while (pkIter && !pkIter->FUN_008256d0())
            {
                RefNodeView* pkRef = *pkIter->FUN_006815c0();
                NodeView* pkNode = pkRef->GetNode3D();
                pkIter = pkIter->FUN_00726070();
                if (pkNode)
                {
                    NiUpdateData kNodeData(fTimeSinceScaleStart, false, bThreaded);
                    pkNode->UpdateDownwardPass(kNodeData, 0);
                    if (static_cast<unsigned char>(kNodeData.pad5))
                        FUN_00450b80(0)->FUN_00b5d9f0(pkNode, 1);
                    if (*DAT_011c3ea4.Setting_Int() > 1)
                    {
                        ((ManagedTaskQueue*)FUN_004537b0())->TaskQueueInterface_QueueCellTransformChildTask(pkNode);
                        if (bThreaded && static_cast<unsigned char>(kNodeData.pad3))
                            RunWithLock(pkNode);
                        if (bThreaded && static_cast<unsigned char>(kNodeData.pad4))
                            ((ManagedTaskQueue*)FUN_004537b0())->TaskQueueInterface_QueueMorphControllerUpdate(pkNode);
                    }
                }
            }
        }
        else
        {
            void* pvPos = (*reinterpret_cast<CellLoadedData**>(formData + 0xA0))->kActors.FUN_004b9ba0();
            while (pvPos)
            {
                KeyRefView* pkKeyNew = 0;
                NodeView* pkActorNode = 0;
                (*reinterpret_cast<CellLoadedData**>(formData + 0xA0))->kActors.FUN_006b7f20(pvPos, pkKeyNew, pkActorNode);
                if (pkActorNode && pkActorNode->NiAVObject_GetParent() != pkDynamic)
                {
                    if (pkKeyNew->BGSSaveFormBuffer_GetForm()->FUN_00401170() == 0x25 && !NodeInFrustum(pkActorNode, BSTreeManager_GetCamera()))
                        continue;
                    NiUpdateData kActorData(fTimeSinceScaleStart, false, bThreaded);
                    pkActorNode->UpdateDownwardPass(kActorData, 0);
                    if (static_cast<unsigned char>(kActorData.pad5))
                        FUN_00450b80(0)->FUN_00b5d9f0(pkActorNode, 1);
                    if (*DAT_011c3ea4.Setting_Int() > 1)
                    {
                        ((ManagedTaskQueue*)FUN_004537b0())->TaskQueueInterface_QueueCellTransformChildTask(pkActorNode);
                        if (bThreaded && static_cast<unsigned char>(kActorData.pad3))
                            RunWithLock(pkActorNode);
                        if (bThreaded && static_cast<unsigned char>(kActorData.pad4))
                            ((ManagedTaskQueue*)FUN_004537b0())->TaskQueueInterface_QueueMorphControllerUpdate(pkActorNode);
                    }
                }
            }
            pvPos = (*reinterpret_cast<CellLoadedData**>(formData + 0xA0))->kColors.FUN_004b9ba0();
            while (pvPos)
            {
                LightForm* pkForm = 0;
                NiColor* pkUnused = 0;
                (*reinterpret_cast<CellLoadedData**>(formData + 0xA0))->kColors.FUN_006b7f20(pvPos, pkForm, pkUnused);
                if (pkForm)
                {
                    NiColor* pkColorPos = pkForm->GetColor();
                    switch (pkForm->FUN_00401170())
                    {
                    case 0x1e: {
                        LightForm* pkLightTmp = pkForm;
                        unsigned int uiColor = pkLightTmp->FUN_005e3fc0();
                        float fScale = DAT_0102f0e4;
                        pkColorPos->r = (unsigned char)(uiColor & 0xff) * fScale;
                        pkColorPos->g = (unsigned char)(((unsigned short)uiColor >> 8) & 0xff) * fScale;
                        pkColorPos->b = (unsigned char)((uiColor >> 16) & 0xff) * fScale;
                        break;
                    }
                    case 0x37: {
                        LightForm* pkRegion = pkForm;
                        TESWeather* pkWeather = pkRegion->FUN_0059bb30();
                        if (!pkWeather)
                            pkWeather = dynamic_cast<TESWeather*>(TESForm_GetFormByNumericID(0x15e));
                        if (pkWeather)
                        {
                            Sky* pkSky = FUN_0046dd00();
                            SkyColorData kSkyDataOut;
                            float fBlendRes;
                            int iIndexNew;
                            pkSky->FillColorBlend(&kSkyDataOut, pkWeather, 1.0f, &fBlendRes, &iIndexNew);
                            pkSky->FillColorBlendColors(&kSkyDataOut, pkWeather, 0, 4, &fBlendRes, &iIndexNew);
                            float fValue = pkSky->Sky_GetFlash() * *DAT_011ccccc.Setting_Float_00403e20();
                            pkSky->SetColor_0063c690(pkColorPos, &kSkyDataOut, fValue);
                        }
                        break;
                    }
                    }
                }
            }
            pvPos = (*reinterpret_cast<CellLoadedData**>(formData + 0xA0))->kMapReferences.FUN_004b9ba0();
            while (pvPos)
            {
                MapRefView* pkLightRefTmp = 0;
                void* pvLightData = 0;
                (*reinterpret_cast<CellLoadedData**>(formData + 0xA0))->kMapReferences.FUN_006b7f20(pvPos, pkLightRefTmp, pvLightData);
                if (pvLightData)
                {
                    NiColor kColor = DAT_011a9b7c;
                    LightForm* pkSource = pkLightRefTmp->FUN_00569580();
                    if (!pkSource)
                        pkSource = ((PlayerLightView*)DAT_011dea3c)->PlayerCharacter_GetCurrentRegion();
                    if (pkSource)
                    {
                        switch (pkSource->FUN_00401170())
                        {
                        case 0x1e: {
                            LightForm* pkLightTmp = pkSource;
                            unsigned int uiColor = pkLightTmp->FUN_005e3fc0();
                            float fScale = DAT_0102f0e4;
                            kColor.r = (unsigned char)(uiColor & 0xff) * fScale;
                            kColor.g = (unsigned char)(((unsigned short)uiColor >> 8) & 0xff) * fScale;
                            kColor.b = (unsigned char)((uiColor >> 16) & 0xff) * fScale;
                            break;
                        }
                        case 0x37: {
                            LightForm* pkRegion = pkSource;
                            TESWeather* pkWeather = pkRegion->FUN_0059bb30();
                            if (!pkWeather)
                                pkWeather = dynamic_cast<TESWeather*>(TESForm_GetFormByNumericID(0x15e));
                            if (pkWeather)
                            {
                                Sky* pkSky = FUN_0046dd00();
                                SkyColorData kSkyDataOut;
                                float fBlendRes;
                                int iIndexNew;
                                pkSky->FillColorBlend(&kSkyDataOut, pkWeather, 1.0f, &fBlendRes, &iIndexNew);
                                pkSky->FillColorBlendColors(&kSkyDataOut, pkWeather, 0, 4, &fBlendRes, &iIndexNew);
                                float fValue = pkSky->Sky_GetFlash() * *DAT_011ccccc.Setting_Float_00403e20();
                                pkSky->SetColor_0063c690(&kColor, &kSkyDataOut, fValue);
                            }
                            break;
                        }
                        }
                    }
                    if (pkLightRefTmp->BGSSaveFormBuffer_GetForm()->FUN_00401170() == 0x1e)
                    {
                        BaseLight* pkBaseRes = pkLightRefTmp->BGSSaveFormBuffer_GetForm();
                        unsigned int uiBaseColor = pkBaseRes->FUN_005e3fc0();
                        float m_fThirdCreatureStatCur = DAT_0102f0e4;
                        kColor.r *= (unsigned char)(uiBaseColor & 0xff) * m_fThirdCreatureStatCur;
                        kColor.g *=
                            (unsigned char)(((unsigned short)uiBaseColor >> 8) & 0xff) * m_fThirdCreatureStatCur;
                        kColor.b *= (unsigned char)((uiBaseColor >> 16) & 0xff) * m_fThirdCreatureStatCur;
                        PointLightPtr* pkLightPtrCur = pkLightRefTmp->TESObjectREFR_GetLight();
                        if (pkLightPtrCur && pkLightPtrCur->Modelloader_GetReferencedThis())
                            pkLightPtrCur->Modelloader_GetReferencedThis()->SetEffectColor(kColor);
                    }
                }
            }
        }
    }
}
