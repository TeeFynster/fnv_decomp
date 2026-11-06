
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
unsigned int FUN_0054f4c0();
NiAVObject* FUN_0054f4f0();


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
    void FUN_00551480(bool RetainReference);
};

class RefX : public TESObjectREFR
{
  public:
    virtual void Unk_240();
    virtual void v091();
    virtual void v092();
    virtual void Unk_24c();

    void* FUN_007af430();
    bool FUN_00564e60();
    bool FUN_00440da0();  // GetDisabled
    class RefExtra* FUN_005d43c0();
    TESObjectCELL* FUN_008d6f30();  // GetParentCell
    bool FUN_005656d0();
    bool FUN_0056a250();
    bool FUN_00437b90();
    void FUN_005728c0(int iValue);
    bool FUN_00548700();
    bool IsFlag20000000Set();
};

class RefExtra
{
  public:
    void FUN_0041d390(TESObjectCELL* pkCell);
};

struct RefList
{
    void FUN_005ae3d0(RefX*& rpkRef);  // AddHead
    bool FUN_005f65d0(RefX*& rpkRef);  // IsInList
};
extern RefList DAT_011ca13c;
extern RefList DAT_011ca144;

class CellNavHandler
{
  public:
    void FUN_00587d10(RefX* pkRef);
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
    int FUN_00458be0(TESObjectCELL* pkCell, int iA, int iB);
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
    void QueueReference(RefX* pkRef, int iCell);
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
    void FUN_0087b400(RefX* pkRef);
};
CellTaskQueue* FUN_004537b0();
bool FUN_008c7aa0();
// Declarations absent from TESObjectCELL.h; no duplicate cell layout or vtable.
class CellReferenceAccess : public TESObjectCELL
{
  public:
    CellNavHandler* FUN_0054ddd0();
    bool FUN_00450ff0();
    bool FUN_004523c0();
    void FUN_00545560(RefX* pkRef);
    void FUN_00548880(RefX* pkRef, bool bArg);
    bool FUN_00548720();
};

// @fnv 0x00548230
void TESObjectCELL::AddReference(RefX* pkRef, bool bArg)
{
    if (!pkRef || !pkRef->FUN_007af430())
        return;
    if (pkRef->FUN_00564e60() && !pkRef->FUN_00440da0())
        (*reinterpret_cast<unsigned short*>(formData + 0x84))++;
    if (FUN_005516c0())
    {
        CellRefLockEnter();
        reinterpret_cast<RefList*>(FUN_009604f0())->FUN_005ae3d0(pkRef);
        CellRefLockLeave();
        pkRef->FUN_005d43c0()->FUN_0041d390(this);
        CellNavHandler* pkHandler = static_cast<CellReferenceAccess*>(this)->FUN_0054ddd0();
        if (pkHandler)
            pkHandler->FUN_00587d10(pkRef);
        if (!DAT_011c3f2c->FUN_004516b0())
            SetAltered(true);
        return;
    }
    TESObjectCELL* pkOldCell = pkRef->FUN_008d6f30();
    if (pkOldCell)
        pkOldCell->RemoveReference(pkRef);
    CellRefLockEnter();
    reinterpret_cast<RefList*>(FUN_009604f0())->FUN_005ae3d0(pkRef);
    pkRef->SetParentCell(reinterpret_cast<TESObjectCELL*>(this));
    CellRefLockLeave();
    if (static_cast<CellReferenceAccess*>(this)->FUN_00450ff0())
        DAT_011c95c8->FUN_00526f20((BGSPerkEntry*)pkRef);
    if ((*reinterpret_cast<void**>(formData + 0xA0)))
    {
        if ((!pkRef->IsActor() || pkRef->FUN_00440da0()) && pkRef->FUN_005656d0())
            static_cast<CellReferenceAccess*>(this)->FUN_00545560(pkRef);
        if (pkRef->FUN_0056a250())
            FUN_005455c0(pkRef);
    }
    if (!pkRef->FUN_00440da0() && pkRef->GetNiNode())
    {
        MobileObject* pkMobile = dynamic_cast<MobileObject*>(static_cast<TESObjectREFR*>(pkRef));
        if (!pkMobile)
            pkRef->AnimateNiNode();
    }
    bool bHandled = false;
    if (!DAT_011c3f2c->FUN_004516b0() && !bHandled && !pkRef->FUN_00437b90())
    {
        void* pvNode = pkRef->GetNiNode();
        if (DAT_011dea10->FUN_004511e0(this, 0))
        {
            bool bQueue = false;
            if (pvNode)
                static_cast<CellReferenceAccess*>(this)->FUN_00548880(pkRef, bArg);
            else
            {
                if (!pkRef->IsActor())
                    bQueue = true;
                else if (!DAT_011dea3c->FUN_0094df60() && !static_cast<CellReferenceAccess*>(this)->FUN_00548720())
                    bQueue = true;
                if (bQueue)
                {
                    if (pkRef->IsActor() && (!DAT_011de45c->FUN_0047c850() || DAT_011de45c->FUN_0047c850()))
                    {
                        if (static_cast<CellReferenceAccess*>(this)->FUN_00450ff0() || static_cast<CellReferenceAccess*>(this)->FUN_004523c0())
                            pkRef->Unk_240();
                        else
                            pkRef->Unk_24c();
                    }
                    DAT_011c3b3c->QueueReference(pkRef, DAT_011dea10->FUN_00458be0(this, 0, 0));
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
                if (!FUN_008c7aa0())
                    pkRef->Set3D(0, false);
                else
                    FUN_004537b0()->FUN_0087b400(pkRef);
            }
        }
    }
    pkRef->FUN_005728c0(0);
    if (!pkRef->FUN_008d6f30()->IsInterior())
    {
        if (pkRef->FUN_00548700() && !DAT_011ca13c.FUN_005f65d0(pkRef))
            DAT_011ca13c.FUN_005ae3d0(pkRef);
        if (pkRef->IsFlag20000000Set() && !DAT_011ca144.FUN_005f65d0(pkRef))
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
ReferenceList* __fastcall FUN_009604f0(TESObjectCELL* cell);
TESBoundObject* __fastcall FUN_007af430(TESObjectREFR* reference);
bool __fastcall FUN_00440d80(const TESObjectREFR* reference);
bool __fastcall FUN_00440da0(TESObjectREFR* reference);
bool __fastcall FUN_00477ba0(TESObjectREFR* reference);
void* __fastcall FUN_00568e50(TESObjectREFR* reference);
void __fastcall FUN_00541ae0(TESObjectCELL* cell);
unsigned int __cdecl GetRandomNumberInRange(int low, int high);
// @fnv 0x0054afb0
TESObjectREFR* __cdecl FUN_0054afb0(TESForm* source, TESForm* destination, void* context)
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
            cursor4 = FUN_009604f0(cellVal);
            lockedCellVal = cellVal;
        }
        else
        {
            world = dynamic_cast<TESWorldSpace*>(source);
            if (world && world->GetInteriorCell())
            {
                cursor4 = FUN_009604f0(world->GetInteriorCell());
                lockedCellVal = world->GetInteriorCell();
            }
        }
        lockedCellVal->CellRefLockEnter();
        while (cursor4 && !cursor4->IsEmpty())
        {
            TESObjectREFR* reference = cursor4->GetItem();
            if (FUN_007af430(reference)->GetFormType() == 28 && !FUN_00440d80(reference) && !FUN_00440da0(reference) &&
                !FUN_00477ba0(reference))
            {
                TESObjectDOOR* door = dynamic_cast<TESObjectDOOR*>(FUN_007af430(reference));
                if (door && door->FUN_005194d0() && door->HasEntry(destination) && !FUN_00568e50(reference))
                {
                    candidatesVal.Append(reference);
                    ++countB;
                }
            }
            cursor4 = cursor4->GetNext();
        }
        FUN_00541ae0(lockedCellVal);
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
    float FUN_004ce380(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, int);
};
struct ReferenceAccess550 : TESObjectREFR
{
    ExtraDataList* FUN_005d43c0();
    void* FUN_00569160();
    void FUN_005692a0();
};
struct RefList550
{
    TESObjectREFR* item;
    RefList550* next;
    TESObjectREFR*& FUN_006815c0();
    RefList550* FUN_00726070();
};
extern TESObjectREFR* g_thePlayer;
void FUN_00555c20();
// @fnv 0x0054b5b0
void TESObjectCELL::FUN_0054b5b0()
{
    CellRefLockEnter();
    RefList550* position = reinterpret_cast<RefList550*>(FUN_009604f0());
    while (position)
    {
        TESObjectREFR* reference = position->FUN_006815c0();
        if (reference && reference != g_thePlayer)
        {
            Actor* actor = dynamic_cast<Actor*>(reference);
            ContainerChanges550* changes =
                reinterpret_cast<ContainerChanges550*>(
                    static_cast<ReferenceAccess550*>(reference)->FUN_005d43c0()->FUN_00418520());
            if (changes)
                changes->FUN_004ce380(reference, g_thePlayer, false, false, true, false, -1, 0);
            // Actor.h still declares slot 0x460 without its reference and float parameters.
            if (actor && !actor->FUN_00440da0() && !actor->FUN_00440d80())
                reinterpret_cast<void (__thiscall*)(Actor*, TESObjectREFR*, float)>(
                    (*reinterpret_cast<void***>(actor))[0x118])(actor, g_thePlayer, 10.0f);
            if (actor && !actor->FUN_0087f3d0() && !actor->FUN_00440da0() && !actor->FUN_00440d80() &&
                !actor->HasHealth(false))
            {
                actor->Alert(reinterpret_cast<PlayerCharacter*>(g_thePlayer), 0, 0, 0, 0, 0, 1, 0);
                actor->FUN_0089d900(0, 0.0f);
            }
            if (static_cast<ReferenceAccess550*>(reference)->FUN_00569160())
                static_cast<ReferenceAccess550*>(reference)->FUN_005692a0();
            FUN_00555c20();
        }
        position = position->FUN_00726070();
    }
    CellRefLockLeave();
}

void* __cdecl operator new(unsigned int);

// ExtraCell3D owns the reference count associated with the cell's loaded 3D.

extern GlobalObject_0096d020 g_011e0e80;

// @fnv 0x00551480
void Cell3DReferenceAccess::FUN_00551480(bool RetainReference)
{
    FUN_0040f410* extra = static_cast<FUN_0040f410*>((*reinterpret_cast<ExtraDataList*>(formData + 0x04)).GetExtraData(9));
    if (!extra && RetainReference)
    {
        extra = new FUN_0040f410;
        (*reinterpret_cast<ExtraDataList*>(formData + 0x04)).AddExtra(extra);
        CellRefLockEnter();
        RefList548* position = reinterpret_cast<RefList548*>(FUN_009604f0());
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

TESForm* FUN_004839c0(unsigned int auiFormId);

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
    NodeView* FUN_009611e0();
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
    FormTypeView* FUN_007af430();
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
    PointLightNode* FUN_00559450();
};

class MapRefView
{
  public:
    LightForm* FUN_00569580();
    BaseLight* FUN_007af430();
    PointLightPtr* FUN_005725f0();
};

class PlayerLightView
{
  public:
    LightForm* FUN_005454d0();
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
    int* FUN_0043d4d0();
};
extern CellIntSetting DAT_011c3ea4;
struct CellFloatSetting
{
    float* FUN_00403e20();
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
    void FUN_0087aad0(NodeView* pkNode);
    void FUN_0087abb0(NodeView* pkNode);
};
void RunWithLock(NodeView* pkNode);
class CellShadowScene
{
  public:
    void FUN_00b5d9f0(NodeView* pkNode, int iValue);
};
CellShadowScene* FUN_00450b80(int iValue);
unsigned int FUN_00552380();
bool FUN_004b5fc0(NodeView* pkNode, unsigned int uiCamera);
bool FUN_008c7aa0();

class CellWaterView
{
  public:
    void FUN_00929260(int iValue);
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
    bool FUN_00450ff0();
    SceneRoot* FUN_004543c0();
    NodeView* FUN_005497a0();
    bool FUN_005495a0();
    bool FUN_00557d10();
    void FUN_00557aa0();
    CellWaterOwner* FUN_0054ddd0();
    int GetByteAtOffset38();
    void FUN_00551890(float fTimeSinceScaleStart, bool bSkipLoaded);
};
// @fnv 0x00551890
void CellUpdateAccess::FUN_00551890(float fTimeSinceScaleStart, bool bSkipLoaded)
{
    if (IsInterior() && FUN_00450ff0())
    {
        SceneRoot* pkRoot = FUN_004543c0();
        if (pkRoot)
            pkRoot->Unk_0c4();
    }
    // NiUpdateData pad3/pad4/pad5 are the flag bytes at offsets 6/7/8.
    bool bThreaded = false;
    if (FUN_008c7aa0())
        bThreaded = true;
    NodeView* pkDynamic = FUN_005497a0();
    if (pkDynamic && !bSkipLoaded)
    {
        NiUpdateData kData(fTimeSinceScaleStart, false, bThreaded);
        pkDynamic->UpdateDownwardPass(kData, 0);
        if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
        {
            ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087aad0(pkDynamic);
            if (bThreaded && static_cast<unsigned char>(kData.pad3))
                RunWithLock(pkDynamic);
            if (bThreaded && static_cast<unsigned char>(kData.pad4))
                ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087abb0(pkDynamic);
        }
    }
    if ((*reinterpret_cast<short*>(formData + 0x86)) > 0 && FUN_005495a0() && FUN_00557d10())
        FUN_00557aa0();
    if ((*reinterpret_cast<bool*>(formData + 0xAE)) && FUN_0054ddd0() && GetByteAtOffset38() == 6)
    {
        (*reinterpret_cast<bool*>(formData + 0xAC)) = true;
        (*reinterpret_cast<bool*>(formData + 0xAA)) = false;
        (*reinterpret_cast<bool*>(formData + 0xAB)) = false;
        if (FUN_0054ddd0())
            FUN_0054ddd0()->FUN_00586170()->FUN_00929260(1);
        (*reinterpret_cast<bool*>(formData + 0xAE)) = false;
    }
    if ((*reinterpret_cast<bool*>(formData + 0xAA)))
    {
        if (DAT_0118b698 * DAT_0118b694 <= (*reinterpret_cast<float*>(formData + 0xA4)))
        {
            if (FUN_0054ddd0() && !(*reinterpret_cast<bool*>(formData + 0xAC)))
                FUN_0054ddd0()->FUN_00586170()->FUN_00929260(1);
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
                    if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
                    {
                        ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087aad0(pkNode);
                        if (bThreaded && static_cast<unsigned char>(kNodeData.pad3))
                            RunWithLock(pkNode);
                        if (bThreaded && static_cast<unsigned char>(kNodeData.pad4))
                            ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087abb0(pkNode);
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
                if (pkActorNode && pkActorNode->FUN_009611e0() != pkDynamic)
                {
                    if (pkKeyNew->FUN_007af430()->FUN_00401170() == 0x25 && !FUN_004b5fc0(pkActorNode, FUN_00552380()))
                        continue;
                    NiUpdateData kActorData(fTimeSinceScaleStart, false, bThreaded);
                    pkActorNode->UpdateDownwardPass(kActorData, 0);
                    if (static_cast<unsigned char>(kActorData.pad5))
                        FUN_00450b80(0)->FUN_00b5d9f0(pkActorNode, 1);
                    if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
                    {
                        ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087aad0(pkActorNode);
                        if (bThreaded && static_cast<unsigned char>(kActorData.pad3))
                            RunWithLock(pkActorNode);
                        if (bThreaded && static_cast<unsigned char>(kActorData.pad4))
                            ((ManagedTaskQueue*)FUN_004537b0())->FUN_0087abb0(pkActorNode);
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
                            pkWeather = dynamic_cast<TESWeather*>(FUN_004839c0(0x15e));
                        if (pkWeather)
                        {
                            Sky* pkSky = FUN_0046dd00();
                            SkyColorData kSkyDataOut;
                            float fBlendRes;
                            int iIndexNew;
                            pkSky->FUN_0063b630(&kSkyDataOut, pkWeather, 1.0f, &fBlendRes, &iIndexNew);
                            pkSky->FUN_0063bab0(&kSkyDataOut, pkWeather, 0, 4, &fBlendRes, &iIndexNew);
                            float fValue = pkSky->FUN_00644950() * *DAT_011ccccc.FUN_00403e20();
                            pkSky->FUN_0063c690(pkColorPos, &kSkyDataOut, fValue);
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
                        pkSource = ((PlayerLightView*)DAT_011dea3c)->FUN_005454d0();
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
                                pkWeather = dynamic_cast<TESWeather*>(FUN_004839c0(0x15e));
                            if (pkWeather)
                            {
                                Sky* pkSky = FUN_0046dd00();
                                SkyColorData kSkyDataOut;
                                float fBlendRes;
                                int iIndexNew;
                                pkSky->FUN_0063b630(&kSkyDataOut, pkWeather, 1.0f, &fBlendRes, &iIndexNew);
                                pkSky->FUN_0063bab0(&kSkyDataOut, pkWeather, 0, 4, &fBlendRes, &iIndexNew);
                                float fValue = pkSky->FUN_00644950() * *DAT_011ccccc.FUN_00403e20();
                                pkSky->FUN_0063c690(&kColor, &kSkyDataOut, fValue);
                            }
                            break;
                        }
                        }
                    }
                    if (pkLightRefTmp->FUN_007af430()->FUN_00401170() == 0x1e)
                    {
                        BaseLight* pkBaseRes = pkLightRefTmp->FUN_007af430();
                        unsigned int uiBaseColor = pkBaseRes->FUN_005e3fc0();
                        float m_fThirdCreatureStatCur = DAT_0102f0e4;
                        kColor.r *= (unsigned char)(uiBaseColor & 0xff) * m_fThirdCreatureStatCur;
                        kColor.g *=
                            (unsigned char)(((unsigned short)uiBaseColor >> 8) & 0xff) * m_fThirdCreatureStatCur;
                        kColor.b *= (unsigned char)((uiBaseColor >> 16) & 0xff) * m_fThirdCreatureStatCur;
                        PointLightPtr* pkLightPtrCur = pkLightRefTmp->FUN_005725f0();
                        if (pkLightPtrCur && pkLightPtrCur->FUN_00559450())
                            pkLightPtrCur->FUN_00559450()->SetEffectColor(kColor);
                    }
                }
            }
        }
    }
}
