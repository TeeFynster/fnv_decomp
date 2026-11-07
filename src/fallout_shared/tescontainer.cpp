// fallout_shared/tescontainer.cpp: TESContainer, InventoryItemEntry and inventory helpers (31 functions)

#include "../../include/BGSPerkEntry.h"
class InventoryStackRecord;
class TESObject;
#include "../../include/BaseFormComponent.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/BSSimpleList.h"

#include "../../include/BSStringT.h"

#include "../../include/TESContainer.h"
#include "../../include/Actor.h"
#include "../../include/ExtraDataList.h"
#include "../../include/GridArray.h"
#include "../../include/InventoryStackRecord.h"
#include "../../include/Script.h"
#include "../../include/TESForm.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESLeveledList.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESScriptableForm.h"

#include "../../include/BGSSaveLoadGame.h"
#include "../../include/InventoryChanges.h"
#include "../../include/PatrolActorPackageData.h"

class ContainerItemExtra
{
  public:
    void* m_pForm;
    union
    {
        void* m_pGlobal;
        int m_cRank;
        unsigned int bits;
    };
    float m_fHealth;
    ContainerItemExtra();
    void Copy(ContainerItemExtra* other);
    bool IsDefault();
};

class InventoryItemEntry
{
  public:
    int count;
    void* object;
    ContainerItemExtra* extra;
    void Copy(InventoryItemEntry* other);
    void InitItem(TESForm* form);
};

struct ContainerCountState
{
    int count;
    BSSimpleList<InventoryStackRecord*>* list;
};

struct CopyComponentState
{
    BSSimpleList<InventoryStackRecord*>* list;
    TESContainer* source;
};

// Copies object, count and, when the source extra is non-default, allocates a new ContainerItemExtra and copies it.
// @fnv 0x00481540
void InventoryItemEntry::Copy(InventoryItemEntry* other)
{
    if (other)
    {
        object = other->object;
        count = other->count;
        if (other->extra && !other->extra->IsDefault())
        {
            extra = new ContainerItemExtra();
            extra->Copy(other->extra);
        }
    }
}

// Constructs a TESContainer, initializing its objectList and calling Init().
// @fnv 0x00481610
TESContainer::TESContainer() : objectList()
{
    Init();
}

// @fnv 0x004816e0
void TESContainer::Free()
{
    ClearObjects();
}

// @fnv 0x00481680
TESContainer::~TESContainer()
{
    Free();
}

// Copies the object list from the source TESContainer component into this container, adding each item.
// @fnv 0x00481c80
void TESContainer::CopyFromBase(BaseFormComponent* component)
{
    CopyComponentState state;
    state.source = dynamic_cast<TESContainer*>(component);
    if (state.source == 0)
        return;
    ClearObjects();
    state.list = state.source->GetObjectList();
    while (state.list != 0 && !state.list->IsEmpty())
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>(state.list->GetItem());
        AddObject(item);
        state.list = state.list->GetNext();
    }
}

// Searches the container's object list for an entry whose object pointer equals object and returns whether one is found.
// @fnv 0x00481eb0
bool TESContainer::HasObjectOfType(TESObject* object)
{
    BSSimpleList<InventoryStackRecord*>* list = GetObjectList();
    if (list->GetItem() == 0)
        list = 0;
    while (list != 0)
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>(list->GetItem());
        if (item->object == object)
            return true;
        list = list->GetNext();
    }
    return false;
}

// Counts how many items in the container's object list match the given object, summing their counts.
// @fnv 0x00482a90
int TESContainer::GetObjectCount(TESObject* object)
{
    ContainerCountState state;
    state.count = 0;
    state.list = GetObjectList();
    while (state.list != 0 && state.list->GetItem() != 0)
    {
        if (reinterpret_cast<InventoryItemEntry*>(state.list->GetItem())->object == object)
            state.count += reinterpret_cast<InventoryItemEntry*>(state.list->GetItem())->count;
        state.list = state.list->GetNext();
    }
    return state.count;
}

// @fnv 0x00481f30
bool TESContainer::IsValidContainerType(unsigned char type)
{
    switch (type)
    {
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x28:
    case 0x29:
    case 0x2e:
    case 0x2f:
    case 0x31:
    case 0x32:
    case 0x34:
    case 0x67:
    case 0x6c:
    case 0x73:
    case 0x74:
        return true;
    default:
        return false;
    }
}

// @fnv 0x00481700
void TESContainer::ClearObjects()
{
    BSSimpleList<InventoryStackRecord*>* list = GetObjectList();
    InventoryItemEntry* item;
    while ((item = reinterpret_cast<InventoryItemEntry*>(list->GetItem())) != 0)
    {
        InventoryItemEntry* deletion = item;
        InventoryItemEntry* temporary = deletion;
        temporary ? reinterpret_cast<BGSPerkEntry*>(temporary)->Destroy(1) : 0;
        list->RemoveHead();
    }
}
// Initializes each entry in the object list with form, removing and deleting entries whose object becomes null.
// @fnv 0x00481bb0
void TESContainer::InitItem(TESForm* form)
{
    BSSimpleList<InventoryStackRecord*>* list = GetObjectList();
    BSSimpleList<InventoryStackRecord*>* previous = 0;
    while (list != 0 && !list->IsEmpty())
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>(list->GetItem());
        item->InitItem(form);
        if (item->object == 0)
        {
            if (previous != 0)
            {
                previous->Remove(reinterpret_cast<InventoryStackRecord* const&>(item));
                list = previous->GetNext();
            }
            else
            {
                list->RemoveHead();
            }
            InventoryItemEntry* deletion = item;
            InventoryItemEntry* temporary = deletion;
            temporary ? reinterpret_cast<BGSPerkEntry*>(temporary)->Destroy(1) : 0;
            item = 0;
        }
        else
        {
            previous = list;
            list = list->GetNext();
        }
    }
}

struct ContainerObjectNew : InventoryItemEntry
{
    ContainerObjectNew();
};

// If object is non-null, allocates a ContainerObjectNew, copies object into it, and adds it to the head of the object list.
// @fnv 0x00481a90
void TESContainer::AddObject(InventoryItemEntry* object)
{
    if (!object)
        return;
    InventoryItemEntry* newObj = new ContainerObjectNew;
    newObj->Copy(object);
    GetObjectList()->AddHead((InventoryStackRecord*&)newObj);
}

InventoryItemEntry** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);

// Iterates the object list of apAddCont and adds each entry's object, count and extra to this container.
// @fnv 0x00481fd0
void TESContainer::MergeContainer(TESContainer* apAddCont)
{
    if (apAddCont)
    {
        void* pListEntry = apAddCont->GetObjectList();
        while (pListEntry)
        {
            InventoryItemEntry* pcont = *_ref_006815c0(pListEntry);
            if (pcont)
            {
                AddObject(static_cast<TESForm*>(pcont->object), pcont->count, pcont->extra);
            }
            pListEntry = _ref_00726070(pListEntry);
        }
    }
}

InventoryItemEntry** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);

// Walks the object list and multiplies each contained entry's count by aiMult.
// @fnv 0x00482040
void TESContainer::ScaleEntryCounts(int aiMult)
{
    void* pCurrentElementNext = (void*)GetObjectList();
    while (pCurrentElementNext)
    {
        InventoryItemEntry* pcont = *_ref_006815c0(pCurrentElementNext);
        if (pcont)
        {
            pcont->count *= aiMult;
        }
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
}

namespace fnv_00482090 {
bool __fastcall _ref_008256d0(void* pThis);
InventoryItemEntry** __fastcall _ref_006815c0(void* pThis);
void* __fastcall _ref_00726070(void* pThis);

struct ContainerItemExtra_helper
{
    void ContainerItemExtra_AdjustHealthPercent(float);
};

}  // namespace fnv_00482090

// Walks the container's item list, creating each item's extra data if missing, applies afHealthPerc to it, and deletes extras that become default.
// @fnv 0x00482090
// src: COMMUNITY 0x00482090
void TESContainer::ApplyHealthPercentToContainer(float afHealthPerc)
{
    void* pCurrentElementNext = (void*)GetObjectList();
    while (pCurrentElementNext && !fnv_00482090::_ref_008256d0(pCurrentElementNext))
    {
        InventoryItemEntry* pcont = *fnv_00482090::_ref_006815c0(pCurrentElementNext);
        if (!pcont->extra)
            pcont->extra = new ContainerItemExtra;
        ((fnv_00482090::ContainerItemExtra_helper*)pcont->extra)->ContainerItemExtra_AdjustHealthPercent(afHealthPerc);
        if (pcont->extra->IsDefault())
        {
            delete pcont->extra;
            pcont->extra = 0;
        }
        pCurrentElementNext = fnv_00482090::_ref_00726070(pCurrentElementNext);
    }
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct LeveledObject;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESActorBase;
struct TESBoundObject;
struct TESGlobal;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
typedef char _sizecheck_TESLeveledList[sizeof(TESLeveledList) == 28 ? 1 : -1];

int __fastcall FNV_GetFormType(TESForm*);

struct TESLevPad
{
    virtual void Dummy();
    char pad[0x2C];
};

struct TESLevFormStub : public TESLevPad, public TESLeveledList
{
};

// Returns apForm cast to TESLeveledList when its form type is 0x34, 0x2C, 0x2D or 0x4C, otherwise null.
// @fnv 0x00487be0
// src: COMMUNITY 0x00487be0
TESLeveledList* __cdecl TESLeveledList_GetFormAsLeveledList(TESForm* apForm)
{
    TESLeveledList* pLeveledList = 0;
    if (apForm)
    {
        switch (FNV_GetFormType(apForm))
        {
        case 0x34: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x2C: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x2D: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x4C: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        }
    }
    return pLeveledList;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Runs the destructor on this object, frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00481760
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class FormRecordHeader;
class HWND__;
class NiAVObject;
class NiColor;
class NiPoint3;
class TESBoundObject;
class TESObject;
struct TESWaterForm;
namespace fnv_004817f0 {
struct BipedAnim;
struct CHUNK;
struct TESFileGroup;
struct TESFormList;
struct blob8
{
    char b[8];
};
struct ContainerObjectNew : public InventoryItemEntry
{
    ContainerObjectNew();
};
}  // namespace fnv_004817f0

// If apObj is non-null, allocates a fnv_004817f0::ContainerObjectNew copying its object and count, adds it to the head of the object list, and returns it.
// @fnv 0x004817f0
InventoryItemEntry* TESContainer::AddObject(ContainerChanges* apObj)
{
    if (!apObj)
        return 0;
    InventoryItemEntry* pcobj;
    BSSimpleList<InventoryStackRecord*>* pList = GetObjectList();
    pcobj = new fnv_004817f0::ContainerObjectNew;
    pcobj->object = *(void**)apObj;
    pcobj->count = ((int*)apObj)[1];
    GetObjectList()->AddHead(reinterpret_cast<InventoryStackRecord*&>(pcobj));
    return pcobj;
}

struct CompareHelper
{
    bool Compare(ContainerItemExtra* other);
};

struct FUN_00481470_shell
{
    int count;
    void* object;
    ContainerItemExtra* extra;
    bool IsNotEqual(InventoryItemEntry* apCompare);
};

// Returns true when apCompare is null or its count, object or extra differ from this shell's, comparing extras via CompareHelper::Compare.
// @fnv 0x00481470
bool FUN_00481470_shell::IsNotEqual(InventoryItemEntry* apCompare)
{
    if (!apCompare)
        return true;
    if (count != apCompare->count)
        return true;
    if (object != apCompare->object)
        return true;
    if (extra && !extra->IsDefault() && !apCompare->extra)
        return true;
    if (!extra && apCompare->extra && !apCompare->extra->IsDefault())
        return true;
    if (extra && apCompare->extra && ((CompareHelper*)extra)->Compare(apCompare->extra))
        return true;
    return false;
}

// @fnv 0x00481f10
// src: XBOX_PDB 0x00481f10
bool __cdecl TESContainer_IsGold(TESObject* pObj)
{
    if (pObj && ((TESForm*)pObj)->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == 0xF)
        return true;
    return false;
}

namespace fnv_004818e0 {
void* __cdecl operator new(unsigned int);
namespace N {
struct ContainerItemExtra
{
    bool Compare(::ContainerItemExtra*);
};
}
struct G2
{
    void AddHead(int*);
};
struct ContainerObjectNew
{
    int a, b, c;
    ContainerObjectNew();
};
}  // namespace fnv_004818e0

// Finds a container entry matching apObj and apExtra, adds aiCount to its count, or creates a new entry and prepends it to the list.
// @fnv 0x004818e0
InventoryItemEntry* TESContainer::AddObject(TESObject* apObj, int aiCount, ContainerItemExtra* apExtra)
{
    if (!apObj || !aiCount)
        return 0;
    BSSimpleList<InventoryItemEntry*>* pCurrentElementNext;
    InventoryItemEntry* pcobj;
    pcobj = 0;
    pCurrentElementNext = (BSSimpleList<InventoryItemEntry*>*)GetObjectList();
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        pcobj = pCurrentElementNext->GetItem();
        if (pcobj->object == apObj)
        {
            if (pcobj->extra)
            {
                if (apExtra && !((fnv_004818e0::N::ContainerItemExtra*)pcobj->extra)->Compare(apExtra))
                    break;
            }
            else if (!apExtra)
                break;
        }
        pcobj = 0;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    if (pcobj)
    {
        pcobj->count += aiCount;
    }
    else
    {
        pcobj = (InventoryItemEntry*)new fnv_004818e0::ContainerObjectNew;
        pcobj->count = aiCount;
        pcobj->object = apObj;
        if (apExtra)
        {
            pcobj->extra = new ContainerItemExtra;
            pcobj->extra->Copy(apExtra);
        }
        ((fnv_004818e0::G2*)GetObjectList())->AddHead((int*)&pcobj);
    }
    return pcobj;
}

class ActorPackageData;
class AlchemyItem;
class BGSAcousticSpace;
struct BGSEncounterZone;
class BGSListForm;
class BGSLoadFormBuffer;
struct BGSMusicType;
class BGSPrimitive;
class BGSSaveFormBuffer;
class BGSTalkingActivator;
class BSExtraData;
class BSMultiBound;
class BSMultiBoundRoom;
class BSOcclusionPlane;
class BSPortal;
class BaseExtraList;
class CellMopp;
class ExtraAction;
class ExtraActorCause;
class ExtraAmmo;
class ExtraAnim;
class ExtraAudioBuoyMarker;
class ExtraAudioMarker;
class ExtraDismemberedLimbs;
class ExtraFactionChanges;
class ExtraFollower;
class ExtraFollowerSwimBreadcrumbs;
struct ExtraLeveledItem;
class ExtraLock;
class ExtraMapMarker;
class ExtraNavMeshPortal;
class ExtraRefractionProperty;
struct ExtraSayToTopicInfo;
class ExtraSayTopicInfoOnceADay;
class ExtraStartingPosition;
class ExtraTeleport;
class NiNode;
class NiPoint3;
class NiRenderedTexture;
class ScriptLocals;
class SeenData;
class TESActorBase;
class TESAmmo;
class TESBoundObject;
class TESClimate;
class TESCombatStyle;
class TESFaction;
class TESGlobal;
struct TESImageSpace;
class TESLevItem;
class TESModel;
class TESNPC;
class TESObject;
class TESObjectCELL;
class TESObjectLAND;
class TESObjectWEAP;
class TESPackage;
class TESTopic;
class TESTopicInfo;
struct TESWaterForm;
class TESWorldSpace;
class TrespassPackage;
class bhkWorld;
namespace fnv_00482770 {
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BipedAnim;
struct CollisionData;
struct Crime;
struct TeleportableReference;
struct ExtraAshPileReference;
struct ExtraCannotWearData;
struct ExtraLight;
struct ExtraTalkingActor;
struct PositionRotation;
struct ImpactSwap;
struct InventoryIterator;
struct MapMarkerData;
struct MenuTopic;
struct Point3Offset;
struct IndexedPointerCollection;
struct PatrolReferenceData;
struct PatrolRefData;
struct LinkedReferencePair;
struct RadioReferenceData;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceFloatEntry;
struct RagDollData;
struct PointerFlagNode;
struct TopicInfoVisitRecord;
struct TESRegionList;
struct WorldLocation;
struct WaterZone;
struct _D3DLOCKED_RECT;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
typedef char _sizecheck_InventoryChanges[sizeof(InventoryChanges) == 20 ? 1 : -1];
struct Fn40ea20
{
    void ContainerItemExtra_AddToExtraDataList(ExtraDataList*, TESHealthForm*);
};
struct FUN_004c29a0_t
{
    void InventoryChanges_AddItem(void*, ExtraDataList*, int);
};
struct ContList
{
    bool _ref_008256d0();
    InventoryItemEntry** _ref_006815c0();
    ContList* GetNext();
};
extern PatrolActorPackageData* g_osGlobals;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

}  // namespace fnv_00482770

// @fnv 0x00482770
void TESContainer::AddInventoryChangesToContainer(int aiLevItemIndex, InventoryChanges* apChanges)
{
    bool bhadChanges = false;
    if (apChanges)
    {
        fnv_00482770::ContList* pCurrentElementNext = (fnv_00482770::ContList*)GetObjectList();
        while (pCurrentElementNext && !pCurrentElementNext->_ref_008256d0())
        {
            InventoryItemEntry* pcont = *pCurrentElementNext->_ref_006815c0();
            if (pcont)
            {
                bhadChanges = true;
                ExtraDataList* pextra = new ExtraDataList();
                pextra->SetLeveledItemIndex(aiLevItemIndex);
                pextra->ExtraDataList_SetCount((unsigned short)pcont->count);
                if (pcont->extra)
                    ((fnv_00482770::Fn40ea20*)pcont->extra)
                        ->ContainerItemExtra_AddToExtraDataList(pextra, TESHealthForm::GetFormAsHealthForm((TESForm*)pcont->object));
                ((fnv_00482770::FUN_004c29a0_t*)apChanges)->InventoryChanges_AddItem(pcont->object, pextra, pcont->count);
            }
            pCurrentElementNext = pCurrentElementNext->GetNext();
        }
        if (bhadChanges && ((GridArray*)apChanges)->GetCenterX() && fnv_00482770::g_osGlobals->IsPatrolling())
        {
            if (!fnv_00482770::g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading() || fnv_00482770::g_BGSSaveLoadGame->IsFlag20Set())
                ((GridArray*)apChanges)->GetCenterX()->SetFormFlags(0x8000000);
        }
    }
}

struct RefH
{
    bool IsDeleted() const;
};
struct ItemNode
{
    int pad;
    RefH* ref;
};
struct FUN_00481310_shell
{
    void FUN_00481310();
};
// The shared header has no declaration for this operation; the free helper keeps the object in ECX.
// Iterates the object list and calls FUN_00481310 on each item whose ref is not deleted.
// @fnv 0x00481b40
void __fastcall InitializeContainerItems(TESContainer* container)
{
    BSSimpleList<ItemNode*>* node = (BSSimpleList<ItemNode*>*)container->GetObjectList();
    if (!node->GetItem())
        node = 0;
    while (node)
    {
        ItemNode* item = node->GetItem();
        if (!item->ref->IsDeleted())
            ((FUN_00481310_shell*)item)->FUN_00481310();
        node = (BSSimpleList<ItemNode*>*)node->GetNext();
    }
}

struct ObjectReference
{
    bool __thiscall FUN_00440d80();
};
struct ContainerNode
{
    InventoryItemEntry** __thiscall FUN_006815c0();
    ContainerNode* __thiscall FUN_00726070();
};
int __cdecl FUN_00ec7d40(int);
double __cdecl FUN_0048ebc0(void*, unsigned char);
// @fnv 0x00481e10
float __thiscall TESContainer::GetContainerWeight(bool flag)
{
    ContainerNode* node;
    float sum = 0.0f;
    node = reinterpret_cast<ContainerNode*>(GetObjectList());
    if (*node->FUN_006815c0() == 0)
        node = 0;
    while (node != 0)
    {
        InventoryItemEntry* entry = *node->FUN_006815c0();
        node = node->FUN_00726070();
        if (reinterpret_cast<ObjectReference*>(entry->object)->FUN_00440d80())
            continue;
        sum = static_cast<float>((double)FUN_00ec7d40(entry->count) * FUN_0048ebc0(entry->object, flag) + sum);
    }
    return sum;
}

class ScriptLocals;
struct ItemExtra
{
    void ContainerItemExtra_AddToExtraDataList(ExtraDataList*, void*);
};
struct Item
{
    int count;
    TESForm* form;
    ItemExtra* extra;
};
struct Node
{
    Item** FUN_006815c0();
    Node* FUN_00726070();
};
struct SettingString
{
    const char* FUN_00403df0();
};
extern SettingString DAT_011d4e7c, DAT_011d3114;
extern Actor* DAT_011dea3c;
Script* TESScriptableForm_GetFormScript(TESForm*);
void* GetHealthForm(TESForm*);
const char* TESFullName_GetFullName(TESForm*);
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
// @fnv 0x004821a0
// src: COMMUNITY 0x004821a0
void TESContainer::AddContainerToReference(TESObjectREFR* target, bool silent)
{
    if (target)
    {
        Actor* last = dynamic_cast<Actor*>(target);
        Item* actor = 0;
        Node* node = reinterpret_cast<Node*>(GetObjectList());
        while (node)
        {
            Item* item = *node->FUN_006815c0();
            if (item)
            {
                Script* script = TESScriptableForm_GetFormScript(item->form);
                int count = item->count;
                actor = item;
                if (script)
                {
                    for (int index = 0; index < count; ++index)
                    {
                        ExtraDataList* extra = 0;
                        extra = new ExtraDataList;
                        extra->ExtraDataList_SetCount(1);
                        if (extra && !extra->ExtraDataList_GetScript())
                        {
                            extra->ExtraDataList_SetScript(script);
                            extra->ExtraDataList_SetScriptLocals(script->FUN_005abf60());
                            TESObjectREFR* ref = new TESObjectREFR;
                            ref->FUN_00484490();
                            script->FUN_005ac1e0(ref, extra->ExtraDataList_GetScriptLocals(), 0, false);
                            delete ref;
                            if (item->extra)
                                item->extra->ContainerItemExtra_AddToExtraDataList(extra, GetHealthForm(item->form));
                        }
                        if (last)
                            last->AddItem(item->form, extra, 1);
                        else
                            target->TESObjectREFR_AddBoundObjectItem(item->form, extra, 1);
                    }
                }
                else
                {
                    ExtraDataList* data = 0;
                    if (item->extra)
                    {
                        data = new ExtraDataList;
                        data->ExtraDataList_SetCount((unsigned short)item->count);
                        item->extra->ContainerItemExtra_AddToExtraDataList(data, GetHealthForm(item->form));
                    }
                    if (last)
                        last->AddItem(item->form, data, item->count);
                    else
                        target->TESObjectREFR_AddBoundObjectItem(item->form, data, item->count);
                }
            }
            node = node->FUN_00726070();
        }
        if (last == DAT_011dea3c && actor && !silent)
        {
            BSStringT<char> text;
            if (actor->count > 1)
                text.PrintfString("%i %s%s %s", actor->count, TESFullName_GetFullName(actor->form), DAT_011d3114.FUN_00403df0(),
                             DAT_011d4e7c.FUN_00403df0());
            else
                text.PrintfString("%s %s", TESFullName_GetFullName(actor->form), DAT_011d4e7c.FUN_00403df0());
            switch (actor->form->FUN_00401170())
            {
            case 25:
            case 30:
            case 31:
            case 40:
            case 41:
            case 46:
            case 47:
            case 50:
            case 103:
            case 108:
            case 115:
            case 116:
                QueueUIMessage(text.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_giftbox.dds",
                               silent ? 0 : DAT_011dea3c->Actor_GetPickUpSoundName(actor->form, 1, 0), 2.0f, false);
                break;
            case 24:
                QueueUIMessage(text.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_giftbox.dds",
                               silent ? 0 : DAT_011dea3c->Actor_GetPickUpSoundName(actor->form, 1, 0), 2.0f, false);
                break;
            }
        }
    }
}

extern float DAT_01015f5c;
extern char DAT_01183108;
extern char DAT_01183998;

struct FUN_00482910_rec
{
    int unk00;
    int unk04;
};

struct FUN_00482910_node
{
    void* FUN_006815c0();
    FUN_00482910_node* FUN_00726070();
};

struct FUN_00482910_obj
{
    float GetDesirability(FUN_00482910_rec* r);
};

int __cdecl FUN_00ec43fb(int a, int b, void* c, void* d, int e);

// Scores each weapon and returns the one with the highest score above DAT_01015f5c.
// @fnv 0x00482910
TESObjectWEAP* TESContainer::GetBestWeapon(TESActorBase* pScorer)
{
    FUN_00482910_node* p = reinterpret_cast<FUN_00482910_node*>(GetObjectList());
    float best = DAT_01015f5c;
    FUN_00482910_rec* result2 = 0;
    while (p != 0)
    {
        FUN_00482910_rec* t3 = *(FUN_00482910_rec**)p->FUN_006815c0();
        if (t3 != 0)
        {
            FUN_00482910_rec* r = (FUN_00482910_rec*)FUN_00ec43fb(t3->unk04, 0, &DAT_01183108, &DAT_01183998, 0);
            if (r != 0)
            {
                float f7 = reinterpret_cast<FUN_00482910_obj*>(pScorer)->GetDesirability(r);
                if (f7 > best)
                {
                    best = f7;
                    result2 = r;
                }
            }
        }
        p = p->FUN_00726070();
    }
    return reinterpret_cast<TESObjectWEAP*>(result2);
}

void* __fastcall _ref_00717e50(void*);
int __fastcall _ref_005ae380(void*);
// Compares this container's entries against another TESContainer's entries, returning true when they differ or the counts do not match.
// @fnv 0x00481d10
bool TESContainer::CompareWithBase(BaseFormComponent* other)
{
    TESContainer* otherContainer = dynamic_cast<TESContainer*>(other);
    if (otherContainer == 0)
        return true;
    int matchCount = 0;
    void* current = _ref_00717e50(this);
    void* otherCurrent = 0;
    InventoryItemEntry* itemBeingChecked;
    while (current != 0)
    {
        itemBeingChecked = *_ref_006815c0(current);
        if (itemBeingChecked != 0)
        {
            otherCurrent = _ref_00717e50(otherContainer);
            bool differenceFound = false;
            while (otherCurrent != 0)
            {
                InventoryItemEntry* compareItem = *_ref_006815c0(otherCurrent);
                if (compareItem != 0)
                {
                    if (!reinterpret_cast<FUN_00481470_shell*>(compareItem)->IsNotEqual(itemBeingChecked))
                    {
                        differenceFound = true;
                        break;
                    }
                }
                otherCurrent = _ref_00726070(otherCurrent);
            }
            if (!differenceFound)
                return true;
            ++matchCount;
        }
        current = _ref_00726070(current);
    }
    if (_ref_005ae380(_ref_00717e50(otherContainer)) != matchCount)
        return true;
    return false;
}

void* __cdecl operator new(unsigned int);
// The shared header has no declaration for this operation; the free helper keeps the object in ECX.
// Copies the object list in reverse order, then removes entries that share the same object pointer.
// @fnv 0x00482b00
BSSimpleList<InventoryStackRecord*>* __fastcall CopyUniqueContainerObjects(TESContainer* container)
{
    BSSimpleList<InventoryStackRecord*>* pNewList = new BSSimpleList<InventoryStackRecord*>;
    BSSimpleList<InventoryStackRecord*>* pList = &container->objectList;
    while (pList && pList->GetItem())
    {
        pNewList->AddHead(pList->GetItem());
        pList = pList->GetNext();
    }
    pList = pNewList;
    BSSimpleList<InventoryStackRecord*>* iter = 0;
    while (pList && pList->GetItem())
    {
        iter = pList->GetNext();
        while (iter && iter->GetItem())
        {
            if (reinterpret_cast<InventoryItemEntry*>(pList->GetItem())->object == reinterpret_cast<InventoryItemEntry*>(iter->GetItem())->object)
            {
                pList->Remove(iter->GetItem());
                iter = pList->GetNext();
            }
            else
                iter = iter->GetNext();
        }
        pList = pList->GetNext();
    }
    return pNewList;
}

struct VATSCommand;
struct VATS_CommandList
{
    void RemoveMatchingItem(VATSCommand* const& apCommand);
};
// @fnv 0x00481790
void TESContainer::RemoveContainerObject(InventoryItemEntry* apEntry)
{
    if (!apEntry)
        return;
    ((VATS_CommandList*)GetObjectList())->RemoveMatchingItem((VATSCommand* const&)apEntry);
    BGSPerkEntry* pkEntry = reinterpret_cast<BGSPerkEntry*>(apEntry);
    BGSPerkEntry* pkDeleteCur = pkEntry;
    pkDeleteCur ? pkDeleteCur->Destroy(1) : 0;
}

struct ArmorRater
{
    float GetDesirability(TESObjectARMO* armor);
};
static const float kNegInfinity = -3.402823466e+38f;
// Scans the container's object list for armor matching the given biped slot and returns the one with the highest rater score, or null.
// @fnv 0x004829c0
TESObjectARMO* TESContainer::FindBestArmor(TESActorBase* rater, int slot)
{
    BSSimpleList<InventoryStackRecord*>* iter = GetObjectList();
    float best = kNegInfinity;
    TESObjectARMO* pkResult = 0;
    while (iter)
    {
        InventoryItemEntry* pkObject = (InventoryItemEntry*)iter->GetItem();
        if (pkObject)
        {
            TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>((TESBoundObject*)pkObject->object);
            if (armor && slot != -1 && armor->TESBipedModelForm::FUN_00480af0(slot, 0, 0))
            {
                float fVal = reinterpret_cast<ArmorRater*>(rater)->GetDesirability(armor);
                if (fVal > best)
                {
                    best = fVal;
                    pkResult = armor;
                }
            }
        }
        iter = iter->GetNext();
    }
    return pkResult;
}

struct RecipeAmmoData
{
    void FUN_006ecd40(unsigned int count);
};

struct RecipeProcess
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual bool IsBoundObject();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual RecipeAmmoData* GetAmmoData();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void RemoveItem(void* item, int extra, int count, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
};

struct RecipeActorForm
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual bool IsBoundObject();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual RecipeAmmoData* GetAmmoData();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void RemoveItem(void* item, int extra, int count, int a4, int a5, int a6, int a7, int a8, int a9, int a10);

    int FUN_00401170();
    void* Actor_GetCurrentWeapon();
    int FUN_00575610(void* item);
    void Actor_UnEquipObject(void* item, int count, void* extra, bool a4, bool a5, bool a6);
    RecipeProcess* FUN_008d8520();
    bool TESObjectWEAP_IsThrownWeapon();
    void TESObjectREFR_AddBoundObjectItem(void* item, int extra, int count);
};

struct RecipeListBox
{
    void* FindItemData(void* item);
};

struct RecipeMenuState
{
    int unk00;
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
    RecipeActorForm* crafterRef;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    RecipeListBox* recipeList;
};

struct ActiveRecipe
{
    void* ComputeValue_005a8080();
    void* BSFile_GetDevice();
};

struct RecipeComponentItem
{
    void* FUN_00726070();
    int Modelloader_GetReferencedThis();
};

struct RecipeComponentNode
{
    bool FUN_008256d0();
    RecipeComponentItem** FUN_006815c0();
    RecipeComponentNode* FUN_00726070();
};

struct FUN_004f2770_Class
{
    const char* Actor_GetPickUpSoundName(void* item, int a2, int a3);
};

struct GameSettingStr
{
    const char* FUN_00403df0();
};

struct WeaponFormOps
{
    void* TESObjectWEAP_GetCurrentAmmo(void* actor);
};

extern RecipeMenuState* DAT_011d8e90;
extern ActiveRecipe* DAT_011d8e94;
extern FUN_004f2770_Class* _g_thePlayer;
extern float DAT_01030ff0;
extern float DAT_010162c0;
extern const char str_0101c178[];
extern const char str_01012058[];
extern const char str_0101c140[];

int __cdecl FUN_005f5950(int a1, int a2, void* a3, int a4, int a5, int a6, int a7);
void __cdecl FUN_004d5e10(int statId, int delta);
const char* __cdecl TESFullName_GetFullName(void* form);
bool __cdecl QueueUIMessage(const char* msg, int emotion, const char* iconPath, const char* soundName, float duration,
                            bool instant);
void __cdecl RecipeMenu_Close();

// Removes recipe components from the crafter and adds the crafted item, queuing a UI message with the item name and quantity.
// @fnv 0x007284f0
void CraftRecipe(int count)
{
    bool playedSound;
    bool isCasinoChip;
    {
        int compQty;
        {
            void* compForm;
            {
                RecipeComponentNode* node;
                {
                    RecipeActorForm* itemForm;
                    {
                        void* recipeTile = DAT_011d8e90->recipeList->FindItemData(&DAT_011d8e94);
                        node = (RecipeComponentNode*)DAT_011d8e94->ComputeValue_005a8080();
                        itemForm = 0;
                        compForm = 0;
                        compQty = 0;
                        if (count == 0)
                        {
                            return;
                        }
                        playedSound = 0;
                        isCasinoChip = 0;
                        for (; node != 0 && !node->FUN_008256d0();)
                        {
                            compForm = (*node->FUN_006815c0())->FUN_00726070();
                            if (!playedSound)
                            {
                                FUN_005f5950(12, 1, compForm, 0, 0, 0, 0);
                                if (((RecipeActorForm*)compForm)->FUN_00401170() == 0x6c)
                                {
                                    isCasinoChip = 1;
                                }
                            }
                            playedSound = 1;
                            compQty = (*node->FUN_006815c0())->Modelloader_GetReferencedThis();
                            if (compForm != 0 && ((RecipeActorForm*)compForm)->IsBoundObject())
                            {
                                itemForm = (RecipeActorForm*)compForm;
                            }
                            if (itemForm != 0)
                            {
                                RecipeActorForm* actor;
                                {
                                    bool isCurrentAmmo = 0;
                                    actor = (DAT_011d8e90->crafterRef != 0 && DAT_011d8e90->crafterRef->IsActor())
                                                ? DAT_011d8e90->crafterRef
                                                : 0;
                                    if (actor != 0 && actor->Actor_GetCurrentWeapon() != 0)
                                    {
                                        isCurrentAmmo =
                                            (((WeaponFormOps*)actor->Actor_GetCurrentWeapon())->TESObjectWEAP_GetCurrentAmmo(_g_thePlayer) ==
                                             (*node->FUN_006815c0())->FUN_00726070());
                                    }
                                    if (itemForm->FUN_00401170() == 0x28)
                                    {
                                        if (actor->FUN_00575610(itemForm) == 1 && itemForm == actor->Actor_GetCurrentWeapon())
                                        {
                                            actor->Actor_UnEquipObject(itemForm, 1, 0, 0, 0, 1);
                                        }
                                    }
                                    DAT_011d8e90->crafterRef->RemoveItem(itemForm, 0, compQty * count, 0, 0, 0, 0, 0, 1,
                                                                         0);
                                    if (isCurrentAmmo)
                                    {
                                        actor->FUN_008d8520()->GetAmmoData()->FUN_006ecd40(0);
                                    }
                                }
                            }
                            node = node->FUN_00726070();
                        }
                        if (!isCasinoChip)
                        {
                            FUN_004d5e10(0x20, count);
                        }
                        node = (RecipeComponentNode*)DAT_011d8e94->BSFile_GetDevice();
                        itemForm = 0;
                        compForm = 0;
                        compQty = 0;
                        for (; node != 0 && !node->FUN_008256d0();)
                        {
                            compForm = (*node->FUN_006815c0())->FUN_00726070();
                            compQty = (*node->FUN_006815c0())->Modelloader_GetReferencedThis();
                            if (compForm != 0 && ((RecipeActorForm*)compForm)->IsBoundObject())
                            {
                                itemForm = (RecipeActorForm*)compForm;
                            }
                            if (itemForm != 0)
                            {
                                if (itemForm->FUN_00401170() == 0x28)
                                {
                                    RecipeActorForm* weapForm = itemForm;
                                    if (weapForm->TESObjectWEAP_IsThrownWeapon())
                                    {
                                        DAT_011d8e90->crafterRef->TESObjectREFR_AddBoundObjectItem(itemForm, 0, compQty * count);
                                    }
                                    else
                                    {
                                        TESContainer tempCont1;
                                        if (itemForm != 0)
                                        {
                                            tempCont1.FUN_004818e0((TESForm*)itemForm, compQty * count, 0);
                                        }
                                        tempCont1.ApplyHealthPercentToContainer(DAT_01030ff0);
                                        tempCont1.AddContainerToReference(DAT_011d8e90->crafterRef, 0);
                                    }
                                }
                                else if (itemForm->FUN_00401170() == 0x18 || itemForm->FUN_00401170() == 0x1a)
                                {
                                    TESContainer tempCont2;
                                    if (itemForm != 0)
                                    {
                                        tempCont2.FUN_004818e0((TESForm*)itemForm, compQty * count, 0);
                                    }
                                    tempCont2.ApplyHealthPercentToContainer(DAT_01030ff0);
                                    tempCont2.AddContainerToReference(DAT_011d8e90->crafterRef, 0);
                                }
                                else
                                {
                                    DAT_011d8e90->crafterRef->TESObjectREFR_AddBoundObjectItem(itemForm, 0, compQty * count);
                                }
                                BSStringT<char> msgStr;
                                if (compQty * count > 1)
                                {
                                    msgStr.PrintfString(str_0101c178, compQty * count, TESFullName_GetFullName(itemForm),
                                                 DAT_011d3114.FUN_00403df0(), DAT_011d4e7c.FUN_00403df0());
                                }
                                else
                                {
                                    msgStr.PrintfString(str_01012058, TESFullName_GetFullName(itemForm),
                                                 DAT_011d4e7c.FUN_00403df0());
                                }
                                QueueUIMessage(msgStr.String(), 0, str_0101c140,
                                               _g_thePlayer->Actor_GetPickUpSoundName(itemForm, 1, 0), DAT_010162c0, 0);
                            }
                            node = node->FUN_00726070();
                        }
                        RecipeMenu_Close();
                    }
                }
            }
        }
    }
}

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class FormRecordHeader;
class HWND__;
class NiColor;
class NiPoint3;
class TESBoundObject;
namespace fnv_004826d0 {
struct CHUNK;
struct TESFileGroup;
struct blob8
{
    char b[8];
};
typedef char _sizecheck_TESScriptableForm[sizeof(TESScriptableForm) == 12 ? 1 : -1];

extern unsigned char DAT_01183028;
extern unsigned char DAT_01183254;
extern "C" void* __cdecl FNV_DynamicCast(void*, long, void*, void*, int);
// Dynamic-casts apForm to TESScriptableForm and returns its script, or null if the cast fails.
// @fnv 0x004826d0
// src: XBOX_PDB 0x004826d0
Script* TESScriptableForm_GetFormScript(TESForm* apForm)
{
    TESScriptableForm* pSF =
        static_cast<TESScriptableForm*>(FNV_DynamicCast(apForm, 0, &DAT_01183028, &DAT_01183254, 0));
    return pSF ? pSF->GetScriptForForm() : 0;
}
}  // namespace fnv_004826d0
