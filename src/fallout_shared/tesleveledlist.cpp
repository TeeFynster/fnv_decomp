// fallout_shared/tesleveledlist.cpp: TESLeveledList, TESFile, NiRefObject, TmpEndian and more (46 functions)

#define FNV64_INCLUDE_BSMULTIBOUND_CAPSULE
#include "../../include/BSShaderAccumulator.h"

#include "../../include/BGSCameraPath.h"
#include "../../include/BGSPerkEntry.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/TESFile.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/BSFile.h"
#include "../../include/BaseProcess.h"
#include "../../include/ExtraDataList.h"
#include "../../include/FormChangeMask.h"
#include "../../include/HighProcess.h"
#include "../../include/TESContainer.h"
#include "../../include/TESLeveledList.h"
#include "../../include/NiRefObject.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/BSFaceGenKeyframe.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/NiColor.h"
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESGlobal.h"
#include "../../include/bhkLiquidAction.h"

// windows.h defines a printer API macro with the same name as the buffer method.
#undef GetForm

// Remaining declarations cover types not yet supported by the shared headers.

extern unsigned int DAT_010a2480;

class ContainerItemExtra
{
  public:
    unsigned int data[3];
    ContainerItemExtra();
    void ContainerItemExtra_AdjustHealthPercent(float);
    void InitItem(TESForm*);
};
struct LeveledObject
{
    void* __vecDelDtor(unsigned int);
    void* Destroy(unsigned int);
    TESForm* pForm;
    unsigned short m_sCount;
    unsigned short sLevel;
    ContainerItemExtra* m_pExtraData;
};

class TESGlobalValueReader
{
  public:
    float GetValue();
};

class PlayerQuestData
{
  public:
    PerkEntryConditionSet* GetConditions();
};
class ActorCause;

class MersenneTwister
{
  public:
    static MersenneTwister* GetRandomGenerator();
    unsigned int GetRandomUInt();
};
unsigned int DialogueRandom();

void* operator new(unsigned int) throw();

int Warning(const char*, ...);

extern "C" double __cdecl floor(double value);
extern "C" int __cdecl _ftol2_sse();

// @fnv 0x00487740
void TESLeveledList::InitializeComponent()
{
    m_pChanceGlobal = 0;
    m_ucChanceNone = 0;
    m_pLevelGlobal = 0;
}

// @fnv 0x00487770
void TESLeveledList::ClearComponent()
{
    InitializeLeveledList();
}

// @fnv 0x00488f10
void TESLeveledList::Revert(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetOldChangeFlags(0x80000000).operator bool())
        ClearScriptAddedLeveledObjects();
}

// @fnv 0x00487f70
void TESLeveledList::PopulateContainerWithLeveledItems(unsigned short level, unsigned short count,
                                                       TESContainer* container, int mode)
{
    if (level < 1)
        level = 1;
    if (container && count > 0)
    {
        unsigned int selectionLevel = level;
        if ((FUN_004877e0() && mode == 0) || mode > 0)
        {
            struct LevelScan
            {
                unsigned short maxLevel;
                BSSimpleList<LeveledObject*>* node;
            } scan;
            scan.maxLevel = 0;
            scan.node = reinterpret_cast<BSSimpleList<LeveledObject*>*>(
                reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
            while (scan.node && !reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(scan.node)->IsEmpty())
            {
                unsigned short entryLevel = scan.node->GetItem()->sLevel;
                if (entryLevel > scan.maxLevel)
                    scan.maxLevel = entryLevel;
                scan.node = scan.node->GetNext();
            }
            if (scan.maxLevel < selectionLevel)
                selectionLevel = scan.maxLevel;
        }
        TESContainer selected;
        if (vfn_14())
        {
            for (int i = 0; i < count; ++i)
            {
                struct Selection
                {
                    TESForm* form;
                    unsigned short quantity;
                    ContainerItemExtra* extra;
                } result;
                result.form = 0;
                result.quantity = 0;
                result.extra = 0;
                SelectLeveledObject((unsigned short)selectionLevel, result.form, result.quantity, result.extra, false,
                                    mode);
                if (result.form && result.quantity)
                {
                    TESLeveledList* nested = GetFormAsLeveledList(result.form);
                    if (nested)
                        nested->PopulateContainerWithLeveledItems(level, result.quantity, &selected, mode);
                    else if (result.form->IsActor_InEditor())
                    {
                        TESForm* object = result.form;
                        if (object)
                            selected.AddObject(object, result.quantity, result.extra);
                    }
                }
            }
        }
        else
        {
            struct Selection
            {
                TESForm* form;
                unsigned short quantity;
                ContainerItemExtra* extra;
            } result;
            {
                bool useAll;
                result.form = 0;
                result.quantity = 0;
                result.extra = 0;
                if (FUN_004878a0())
                {
                    int roll;
                    {
                        unsigned char chance;
                        useAll = false;
                        chance = vfn_10();
                        roll = DialogueRandom() % 100;
                        if (roll >= chance)
                        {
                            BSSimpleList<LeveledObject*>* node = reinterpret_cast<BSSimpleList<LeveledObject*>*>(
                                reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
                            while (node && !reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(node)->IsEmpty())
                            {
                                LeveledObject* entry = node->GetItem();
                                node = node->GetNext();
                                result.form = entry->pForm;
                                result.quantity = entry->m_sCount;
                                result.extra = entry->m_pExtraData;
                                if (result.form && result.quantity)
                                {
                                    TESLeveledList* nested = GetFormAsLeveledList(result.form);
                                    if (nested)
                                        nested->PopulateContainerWithLeveledItems(level, result.quantity, &selected,
                                                                                  mode);
                                    else if (result.form->IsActor_InEditor())
                                    {
                                        TESForm* object = result.form;
                                        if (object)
                                            selected.AddObject(object, result.quantity, result.extra);
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    SelectLeveledObject((unsigned short)selectionLevel, result.form, result.quantity, result.extra,
                                        false, mode);
                    if (result.form && result.quantity)
                    {
                        TESLeveledList* nested = GetFormAsLeveledList(result.form);
                        if (nested)
                            nested->PopulateContainerWithLeveledItems(level, result.quantity, &selected, mode);
                        else if (result.form->IsActor_InEditor())
                        {
                            TESForm* object = result.form;
                            if (object)
                                selected.AddObject(object, result.quantity, result.extra);
                        }
                    }
                }
                selected.ScaleEntryCounts(count);
            }
        }
        container->MergeContainer(&selected);
    }
}

// Rolls chance and level range over perk entries, picks one entry, optionally recurses into a nested leveled list, and writes form, count and extra.
// @fnv 0x00487d00
void TESLeveledList::SelectLeveledObject(unsigned short level, TESForm*& form, unsigned short& count,
                                         ContainerItemExtra*& extra, bool recurse, int mode)
{
    struct LevelRange
    {
        int lastLevel;
        BSSimpleList<LeveledObject*>* first;
        int minimumLevel;
        unsigned int choices;
    } range;
    bool foundRange;
    {
        form = 0;
        count = 0;
        extra = 0;
        unsigned char chance = vfn_10();
        if (chance > 0)
        {
            int roll = DialogueRandom() % 100;
            if (roll < chance)
                return;
        }
        range.minimumLevel = level;
        if ((FUN_004877e0() && mode == 0) || mode > 0)
        {
            int difference = vfn_18();
            if (difference)
                range.minimumLevel = level - difference;
            else
                range.minimumLevel = -1;
        }
        range.choices = 1;
        range.lastLevel = 0;
        range.first = 0;
        BSSimpleList<LeveledObject*>* node =
            reinterpret_cast<BSSimpleList<LeveledObject*>*>(reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
        foundRange = false;
        while (node)
        {
            LeveledObject* entry = node->GetItem();
            if (entry)
            {
                int entryLevel = entry->sLevel;
                if (entryLevel > level)
                    break;
                if (entryLevel > range.lastLevel && (range.lastLevel == 0 || !foundRange))
                {
                    if (entryLevel >= range.minimumLevel)
                        foundRange = true;
                    range.choices = 1;
                    range.first = node;
                    range.lastLevel = entryLevel;
                }
                else
                    ++range.choices;
            }
            node = node->GetNext();
        }
        if (range.first)
        {
            struct SelectedForm
            {
                unsigned short count;
                LeveledObject* entry;
                ContainerItemExtra* extra;
                TESForm* form;
            } result;
            {
                unsigned int pick = DialogueRandom() % range.choices;
                node = range.first;
                while (pick)
                {
                    node = node->GetNext();
                    --pick;
                    if (!node)
                        return;
                }
                result.entry = node->GetItem();
                result.form = result.entry->pForm;
                result.count = result.entry->m_sCount;
                result.extra = result.entry->m_pExtraData;
                {
                    TESLeveledList* nested = GetFormAsLeveledList(result.entry->pForm);
                    if (nested && recurse)
                    {
                        struct RecursiveForm
                        {
                            ContainerItemExtra* extra;
                            TESForm* form;
                            unsigned short count;
                        } recursive;
                        recursive.form = 0;
                        recursive.count = 0;
                        recursive.extra = 0;
                        nested->SelectLeveledObject(level, recursive.form, recursive.count, recursive.extra, recurse,
                                                    mode);
                        result.form = recursive.form;
                        result.count *= recursive.count;
                        if (recursive.extra)
                            result.extra = recursive.extra;
                    }
                    form = result.form;
                    count = result.count;
                    extra = result.extra;
                }
            }
        }
    }
}

// Resolves each perk entry's form and the chance global against the owner's file, removing and warning about entries that fail to resolve.
// @fnv 0x00488570
void TESLeveledList::InitItem(TESForm* owner)
{
    struct ResolveState
    {
        LeveledObject* entry;
        BSSimpleList<LeveledObject*>* node;
        BSSimpleList<LeveledObject*>* previous;
        TESFile* file;
    } resolveState;
    {
        resolveState.previous = 0;
        resolveState.node =
            reinterpret_cast<BSSimpleList<LeveledObject*>*>(reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
        resolveState.entry = 0;
        resolveState.file = owner ? owner->GetFile(-1) : 0;
        unsigned int formID, globalID;
        while (resolveState.node && (resolveState.entry = resolveState.node->GetItem()) != 0)
        {
            formID = reinterpret_cast<unsigned int>(resolveState.entry->pForm);
            TESForm::RemapFormIDForFile(formID, resolveState.file);
            resolveState.entry->pForm = TESForm::GetFormByID(formID);
            if (!resolveState.entry->pForm)
            {
                reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(resolveState.node)->RemoveHead();
                struct DeletedEntry
                {
                    LeveledObject* doomed;
                    LeveledObject* object;
                } deletion;
                deletion.doomed = resolveState.entry;
                deletion.object = deletion.doomed;
                deletion.object ? deletion.object->Destroy(1) : 0;
                resolveState.entry = 0;
                if (owner)
                {
                    if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                        Warning("MASTERFILE: Unable to find Leveled Object Form (%08X) for owner object \"%s\".",
                                formID, owner->GetName());
                    else
                        Warning("MASTERFILE: Unable to find Leveled Object Form (%08X) for owner object (%08X).",
                                formID, owner->GetFormID());
                }
                else
                    Warning("MASTERFILE: Unable to find Leveled Object Form (%08X) for unknown owner.", formID);
            }
            else
            {
                resolveState.previous = resolveState.node;
                resolveState.node = resolveState.node->GetNext();
            }
            if (resolveState.entry && resolveState.entry->m_pExtraData)
                resolveState.entry->m_pExtraData->InitItem(owner);
        }
        if (m_pLevelGlobal)
        {
            globalID = reinterpret_cast<unsigned int>(m_pLevelGlobal);
            TESForm::RemapFormIDForFile(globalID, resolveState.file);
            m_pLevelGlobal = dynamic_cast<TESGlobal*>(TESForm::GetFormByID(globalID));
            if (!m_pLevelGlobal)
            {
                if (owner)
                {
                    if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                        Warning("MASTERFILE: Unable to find Leveled Chance Global (%08X) for owner object \"%s\".",
                                globalID, owner->GetName());
                    else
                        Warning("MASTERFILE: Unable to find Leveled Chance Global (%08X) for owner object (%08X).",
                                globalID, owner->GetFormID());
                }
                else
                    Warning("MASTERFILE: Unable to find Leveled Chance Global (%08X) for unknown owner.", globalID);
            }
        }
    }
}

// @fnv 0x00488d70
void TESLeveledList::LoadGame(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetChangeFlags(0x80000000).operator bool())
    {
        if (!reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(&m_kLeveledObjects)->IsEmpty())
            ClearScriptAddedLeveledObjects();
        unsigned int uiEntryCount = buffer->ReadElementCount();
        for (unsigned int i = 0; i < uiEntryCount; ++i)
        {
            struct SavedForm
            {
                TESForm* form;
                float health;
            } savedItem;
            {
                savedItem.form = 0;
                unsigned short count = 0;
                unsigned short level = 0;
                savedItem.health = 0;
                savedItem.form =
                    TESForm::GetFormByID(reinterpret_cast<BGSLoadGameBuffer*>(buffer)->ReadFormIdentifier());
                buffer->ReadTypedData(static_cast<void*>(&level), 2u);
                buffer->ReadTypedData(static_cast<void*>(&count), 2u);
                buffer->ReadTypedData(static_cast<void*>(&savedItem.health), 4u);
                if (savedItem.form)
                {
                    ContainerItemExtra* extra = 0;
                    if (savedItem.health != -1.0)
                    {
                        extra = new ContainerItemExtra;
                        extra->ContainerItemExtra_AdjustHealthPercent(savedItem.health);
                    }
                    reinterpret_cast<FileEntryList*>(this)->Copy(buffer->GetForm(), level, count, savedItem.form,
                                                                 extra);
                }
            }
        }
    }
}

// @fnv 0x004726f0
bool TESFile::NextChunk()
{
    struct ChunkPosition
    {
        unsigned int offset, formSize;
    } chunkPos;
    chunkPos.formSize = m_kRecordInfo.length;
    if (IsCurrentFormCompressed())
        chunkPos.formSize = reinterpret_cast<HighProcess*>(this)->HighProcess::GetPostAnimationAction();
    m_uiRecordOffset += m_uiChunkSize + 6;
    if (m_uiRecordOffset >= chunkPos.formSize)
    {
        FUN_004720d0();
        return false;
    }
    chunkPos.offset = m_uiRecordSize + reinterpret_cast<bhkLiquidAction*>(this)->GetInstanceSize() + m_uiRecordOffset;
    if (!IsCurrentFormCompressed())
        m_pFile->Seek(chunkPos.offset, DAT_010a2480);
    m_uiCurrentOffset = 0;
    FUN_004720d0();
    GetChunkID();
    return true;
}

// @fnv 0x00487900
void TESLeveledList::InitializeLeveledList()
{
    BSSimpleList<LeveledObject*>* node =
        reinterpret_cast<BSSimpleList<LeveledObject*>*>(reinterpret_cast<PlayerQuestData*>(this)->GetConditions());
    while (node)
    {
        LeveledObject* entry = node->GetItem();
        if (entry)
        {
            struct DeletedEntry
            {
                LeveledObject* doomed;
                LeveledObject* object;
            } deletion;
            deletion.doomed = entry;
            deletion.object = deletion.doomed;
            deletion.object ? deletion.object->Destroy(1) : 0;
            reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(node)->RemoveHead();
        }
        else
            node = node->GetNext();
    }
    reinterpret_cast<BSSimpleList<ActorCause*>*>(&m_kLeveledObjects)->RemoveAll();
}

// @fnv 0x004877e0
bool TESLeveledList::GetAllBelow()
{
    if (m_ucChanceNone & 1)
        return true;
    else
        return false;
}

// @fnv 0x004878a0
bool TESLeveledList::GetUseAll()
{
    if (m_ucChanceNone & 4)
        return true;
    else
        return false;
}

// @fnv 0x00487f50
unsigned int DialogueRandom()
{
    return MersenneTwister::GetRandomGenerator()->GetRandomUInt();
}

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

// Returns the value of the TESGlobalValueReader at offset 0x10 if present, otherwise the byte at offset 0x0c.
// @fnv 0x00487790
unsigned char TESLeveledList::GetChanceNone()
{
    if (m_pLevelGlobal)
        return static_cast<unsigned char>(
            reinterpret_cast<TESGlobalValueReader*>(m_pLevelGlobal)->GetValue());
    return m_pChanceGlobal;
}

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];

// @fnv 0x00487840
bool TESLeveledList::UsesAllEntries()
{
    if (m_ucChanceNone & 2)
        return true;
    else
        return false;
}

typedef char _sizecheck_LEVELED_OBJECT[sizeof(LeveledObject) == 12 ? 1 : -1];
struct FUN_00487ba0_shell : public LeveledObject
{
    void InitLeveledObject();
};

// @fnv 0x00487ba0
LeveledObject* __fastcall InitLeveledObject(LeveledObject* pThis)
{
    pThis->pForm = 0;
    pThis->m_pExtraData = 0;
    pThis->m_sCount = 1;
    pThis->sLevel = 1;
    return pThis;
}

float __cdecl floor(float);

// Reads the reference's level multiplier and all-below flag, computes a level from its level, and adds leveled list items to the container.
// @fnv 0x00488350
void TESLeveledList::PopulateContainerFromReference(TESObjectREFR* apRef, TESContainer* apOutCont)
{
    if (!apRef || !apOutCont)
        return;

    float fLevelMult = 1.0f;
    int iallbelowforce = 0;
    apRef->GetExtraData()->GetLeveledItemData(fLevelMult, iallbelowforce);

    unsigned int icalclevel = 1;
    icalclevel = apRef->GetReferenceLevel(true);

    int ilevel = (int)floor(icalclevel * fLevelMult);
    if (ilevel < 1)
        ilevel = 1;

    PopulateContainerWithLeveledItems((unsigned short)ilevel, 1, apOutCont, iallbelowforce);
}

namespace fnv_0050ad90 {

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct LeveledListLevelDifference
{
    static int __thiscall Creature(TESLeveledList* list);
};

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c8e1c;

// @fnv 0x0050ad90
int __thiscall LeveledListLevelDifference::Creature(TESLeveledList* list)
{
    return *g_011c8e1c.Int();
}
}  // namespace fnv_0050ad90

namespace fnv_0050b370 {

typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct LeveledListLevelDifference
{
    static int __thiscall Character(TESLeveledList* list);
};

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c8ed4;

// @fnv 0x0050b370
int __thiscall LeveledListLevelDifference::Character(TESLeveledList* list)
{
    return *g_011c8ed4.Int();
}
}  // namespace fnv_0050b370

#include "../../include/NiMemObject.h"
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00526ac0_shell : public TESGlobal
{
    float BSMultiBoundCapsule_QMultiBoundRadius();
};

// @fnv 0x00526ac0
// src: XBOX_PDB 0x00526ac0
float FUN_00526ac0_shell::BSMultiBoundCapsule_QMultiBoundRadius()
{
    return *(float*)((char*)this + 0x24);
}

// Sets or clears bit 0 of the byte at offset 0xd of this object according to bFlag.
// @fnv 0x00487800
void TESLeveledList::SetCalcAllBelow(bool bFlag)
{
    if (bFlag)
        m_ucChanceNone |= 1;
    else
        m_ucChanceNone &= 0xfffffffe;
}

// Sets or clears bit 1 of the byte at offset 0x0d according to the set argument.
// @fnv 0x00487860
void TESLeveledList::SetMultCalc(bool set)
{
    if (set)
        m_ucChanceNone |= 2;
    else
        m_ucChanceNone &= ~2;
}

struct FUN_00c611d0_shell
{
    int GetFour();
};

// @fnv 0x00c611d0
int FUN_00c611d0_shell::GetFour()
{
    return 4;
}

struct FUN_00c611e0_shell
{
    int __thiscall BSMultiBoundCapsule_CheckBound(int arg1);
};

// @fnv 0x00c611e0
// src: COMMUNITY 0x00c611e0
int __thiscall FUN_00c611e0_shell::BSMultiBoundCapsule_CheckBound(int arg1)
{
    return 0;
}

struct FUN_00c61230_shell
{
    bool BSMultiBoundCapsule_WithinFrustum(int);
};

// @fnv 0x00c61230
// src: XBOX_PDB 0x00c61230
bool FUN_00c61230_shell::BSMultiBoundCapsule_WithinFrustum(int)
{
    return false;
}

struct FUN_00c61240_shell
{
    bool __thiscall BSMultiBoundCapsule_CompletelyWithinFrustum(int);
};

// @fnv 0x00c61240
// src: XBOX_PDB 0x00c61240
bool __thiscall FUN_00c61240_shell::BSMultiBoundCapsule_CompletelyWithinFrustum(int)
{
    return 0;
}

struct FUN_00c61250_shell
{
    void __thiscall BSMultiBoundCapsule_GetNiBound(int a);
};

// @fnv 0x00c61250
// src: COMMUNITY 0x00c61250
void __thiscall FUN_00c61250_shell::BSMultiBoundCapsule_GetNiBound(int a)
{}

struct FUN_00c61260_shell
{
    void BSMultiBoundCapsule_CreateDebugGeometry(int a, int b, int c, int d, int e, int f);
};

// @fnv 0x00c61260
// src: COMMUNITY 0x00c61260
void __thiscall FUN_00c61260_shell::BSMultiBoundCapsule_CreateDebugGeometry(int a, int b, int c, int d, int e, int f)
{}

extern "C" void* g_01204398;

struct FUN_00c61270_shell
{
    void* __thiscall BSMultiBoundCapsule_GetRTTI();
};

// @fnv 0x00c61270
// src: COMMUNITY 0x00c61270
void* __thiscall FUN_00c61270_shell::BSMultiBoundCapsule_GetRTTI()
{
    return &g_01204398;
}

// Keep the scalar-deletion entry's explicit thiscall ABI outside NiRefObject.
struct NiRefObjectDeletion
{
    static void* __thiscall Delete(NiRefObject* obj, unsigned int flags);
};

extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

// @fnv 0x00c61280
void* __thiscall NiRefObjectDeletion::Delete(NiRefObject* obj, unsigned int flags)
{
    obj->NiRefObject::~NiRefObject();
    if (flags & 1)
        __Dummy_00b6fef0(obj, 0x28);
    return obj;
}

// @fnv 0x004878c0
void __thiscall TESLeveledList::SetUseAll(bool abSet)
{
    if (abSet)
        m_ucChanceNone |= 4;
    else
        m_ucChanceNone &= ~4;
}

extern void __fastcall FUN_00c4f980(void*);
extern int DAT_010c34ac;

// Initialize the capsule without introducing calls to its empty point constructors.
// @fnv 0x00c60d50
// src: EXE 0x00c60d50
BSMultiBoundCapsule* __fastcall BSMultiBoundCapsule_BSMultiBoundCapsule(BSMultiBoundCapsule* capsule)
{
    FUN_00c4f980(capsule);
    *reinterpret_cast<int**>(capsule) = &DAT_010c34ac;
    return capsule;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<2>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
struct TmpEndian
{
    unsigned short f0;
    int f1;
    unsigned short f2;
    void SwapEndian();
};
// Byte-swaps the three fields f0, f1 and f2 of this struct via BSEndian.
// @fnv 0x00488510
void TmpEndian::SwapEndian()
{
    BSEndian(&f0, EndianSizeTag<2>());
    BSEndian(&f1, EndianSizeTag<2>());
    BSEndian(&f2, EndianSizeTag<2>());
}

// These leaves pass an opaque stream handle. NiStream is a struct in the
// approved headers and a class in the pending headers; neither layout is used.
struct ColorStreamIO
{
    static void __thiscall Load(NiColor* color, void* stream);
    static void __thiscall Save(NiColor* color, void* stream);
};
struct FUN_00c4f9f0_shell
{
    char _pad[12];
    void BSMultiBoundShape_LoadBinary(void*);
};
template <typename T> void ReadBinaryValue(void*, T&);
struct FUN_00c60e70_shell : public FUN_00c4f9f0_shell
{
    NiColor c1;
    NiColor c2;
    unsigned int u;
    void BSMultiBoundCapsule_LoadBinary(void*);
};
// @fnv 0x00c60e70
// src: XBOX_PDB 0x00c60e70
void FUN_00c60e70_shell::BSMultiBoundCapsule_LoadBinary(void* stream)
{
    BSMultiBoundShape_LoadBinary(stream);
    ColorStreamIO::Load(&c1, stream);
    ColorStreamIO::Load(&c2, stream);
    ReadBinaryValue<unsigned int>(stream, u);
}

struct FUN_00c60ec0_shell
{
    void BSMultiBoundShape_LinkObject(int);
    void BSMultiBoundCapsule_LinkObject(int a);
};

// @fnv 0x00c60ec0
// src: XBOX_PDB 0x00c60ec0
void FUN_00c60ec0_shell::BSMultiBoundCapsule_LinkObject(int aiValue)
{
    BSMultiBoundShape_LinkObject(aiValue);
}

struct FUN_00c38020_shell
{
    unsigned char BSMultiBoundShape_RegisterStreamables(int);
    bool BSMultiBoundCapsule_RegisterStreamables(int);
};
// @fnv 0x00c60ee0
// src: XBOX_PDB 0x00c60ee0
bool FUN_00c38020_shell::BSMultiBoundCapsule_RegisterStreamables(int a)
{
    if (!BSMultiBoundShape_RegisterStreamables(a))
        return false;
    return true;
}

namespace fnv_00c60f10 {
struct FUN_00c38050_Holder
{
    void BSMultiBoundShape_SaveBinary(void*);
    unsigned char data[12];
};
void __cdecl CallAnimCallback(void*, int*);
struct Host : FUN_00c38050_Holder
{
    NiColor c1;
    NiColor c2;
    int f24;
    void BSMultiBoundCapsule_SaveBinary(void*);
};
// @fnv 0x00c60f10
// src: XBOX_PDB 0x00c60f10
void Host::BSMultiBoundCapsule_SaveBinary(void* s)
{
    FUN_00c38050_Holder::BSMultiBoundShape_SaveBinary(s);
    ColorStreamIO::Save(&c1, s);
    ColorStreamIO::Save(&c2, s);
    CallAnimCallback(s, &f24);
}
}  // namespace fnv_00c60f10

// @fnv 0x00488c50
void TESLeveledList::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    if (apSaveGameBuffer->GetChangeFlags(0x80000000).operator bool())
    {
        unsigned int isaveGameCount = 0;
        unsigned int isaveGameBufferPos = apSaveGameBuffer->StartVariableSizedValue();
        BSSimpleList<LeveledObject*>* pCurrentElementNext = (BSSimpleList<LeveledObject*>*)((char*)this + 0x14);
        while (pCurrentElementNext)
        {
            LeveledObject* pitem = pCurrentElementNext->GetItem();
            if (pitem)
            {
                apSaveGameBuffer->SerializeFormData(pitem->pForm, 0);
                apSaveGameBuffer->SaveData((char*)pitem + 6, 2, 0);
                apSaveGameBuffer->SaveData((char*)pitem + 4, 2, 0);
                float fhealthPercent = -1.0f;
                if (*(void**)((char*)pitem + 8))
                    fhealthPercent = ((BSFaceGenKeyframe*)*(void**)((char*)pitem + 8))->GetTime();
                apSaveGameBuffer->SaveData(&fhealthPercent, 4, 0);
                isaveGameCount++;
            }
            pCurrentElementNext = pCurrentElementNext->GetNext();
        }
        apSaveGameBuffer->SaveVariableSizedValue_00865ff0(isaveGameCount, isaveGameBufferPos);
    }
}

struct Shell
{
    void CopyMembersStreamWithField(Shell*, int);
    char pad0c[0xc];
    NiPoint3 m0c;
    NiPoint3 m18;
    float m24;
    void BSMultiBoundShape_CopyMembers(Shell* dest, int a);
};
// Calls CopyMembersStreamWithField on dest, then copies m0c, m18 and m24 from this into dest.
// @fnv 0x00c60e00
// src: XBOX_PDB 0x00c60e00
void Shell::BSMultiBoundShape_CopyMembers(Shell* dest, int aiArg)
{
    CopyMembersStreamWithField(dest, aiArg);
    // Preserve the original trivial, bitwise vector copies. NiPoint3's shared
    // assignment operator is out of line with this unit's /Od build flags.
    reinterpret_cast<NiPoint3&>(dest->m0c) = reinterpret_cast<const NiPoint3&>(m0c);
    reinterpret_cast<NiPoint3&>(dest->m18) = reinterpret_cast<const NiPoint3&>(m18);
    float f = m24;
    dest->m24 = f;
}

namespace fnv_00c60d70 {
struct A51BF0Base
{
    char padding[4];

    static void* __cdecl operator new(unsigned int size);
};

struct Shell : public A51BF0Base
{
    char padding[36];

    void BSMultiBoundShape_CopyMembers(Shell* object, int value);
};

struct FUN_00c60d70_shell : public Shell
{
    Shell* BSMultiBoundCapsule_CreateClone(int value);
};

// Allocates a BSMultiBoundCapsule, copies the members, and returns the new object.
// @fnv 0x00c60d70
// src: XBOX_PDB 0x00c60d70
Shell* FUN_00c60d70_shell::BSMultiBoundCapsule_CreateClone(int value)
{
    Shell* shell = reinterpret_cast<Shell*>(new BSMultiBoundCapsule);
    BSMultiBoundShape_CopyMembers(shell, value);
    return shell;
}
}  // namespace fnv_00c60d70

struct ScriptAddedEntries
{
    unsigned char FUN_008256d0();
    LeveledObject*& FUN_006815c0();
    void FUN_0063f7b0();
};
struct CurrentLeveledEntries
{
    void RemoveMatchingItem(LeveledObject* const&);
};

// @fnv 0x00487980
void TESLeveledList::ClearScriptAddedLeveledObjects()
{
    while (!reinterpret_cast<ScriptAddedEntries*>(&m_kLeveledObjects)->FUN_008256d0())
    {
        LeveledObject* entryToDestroy = reinterpret_cast<ScriptAddedEntries*>(&m_kLeveledObjects)->FUN_006815c0();
        reinterpret_cast<ScriptAddedEntries*>(&m_kLeveledObjects)->FUN_0063f7b0();
        reinterpret_cast<CurrentLeveledEntries*>(&leveledList)->RemoveMatchingItem(entryToDestroy);

        LeveledObject* item = entryToDestroy;
        LeveledObject* removed = item;
        removed ? removed->Destroy(1) : 0;
    }
}

extern void __cdecl TESForm_AddChunk_3(unsigned int, unsigned int);
extern void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
extern void __cdecl AppendChunk(unsigned int, const void*, unsigned int);
extern unsigned char __cdecl TESForm_QEndianSwapOnSave();

struct LevelNode_00488400
{
    LeveledObject** FUN_006815c0();
    LevelNode_00488400* FUN_00726070();
};

struct ExtraSaver_00488400 : ContainerItemExtra
{
    void WriteToChunk();
};

// @fnv 0x00488400
void TESLeveledList::Save()
{
    TESForm_AddChunk_3(0x444c564c, m_pChanceGlobal);
    TESForm_AddChunk_3(0x464c564c, m_ucChanceNone);
    if (m_pLevelGlobal)
    {
        unsigned int chanceFormID = m_pLevelGlobal->GetFormID();
        TESForm_AddChunk_00485910(0x474c564c, chanceFormID);
    }
    LevelNode_00488400* pEntryNode = static_cast<LevelNode_00488400*>(GetLeveledList());
    LeveledObject* entry;
    while (pEntryNode && (entry = *pEntryNode->FUN_006815c0()) != 0)
    {
        TmpEndian levelEntryData;
        levelEntryData.f1 = entry->pForm->GetFormID();
        levelEntryData.f0 = entry->sLevel;
        levelEntryData.f2 = entry->m_sCount;
        if (TESForm_QEndianSwapOnSave())
            levelEntryData.SwapEndian();
        AppendChunk(0x4f4c564c, &levelEntryData, 12);
        if (TESForm_QEndianSwapOnSave())
            levelEntryData.SwapEndian();
        if (entry->m_pExtraData)
            static_cast<ExtraSaver_00488400*>(entry->m_pExtraData)->WriteToChunk();
        pEntryNode = pEntryNode->FUN_00726070();
    }
}

struct NiObject;

struct TCEq
{
    bool BSMultiBoundShape_IsEqual(NiObject* pObject);
};

struct TCColorEq : public TCEq
{
    int unk00;
    int unk04;
    int unk08;
    NiPoint3 m0c;
    NiPoint3 m18;
    float m24;
    bool BSMultiBoundCapsule_IsEqual(NiObject* pObject);
};

// Calls the base equality check, then compares m0c, m18 and m24 against the same fields of pObject cast to TCColorEq.
// @fnv 0x00c60f60
// src: XBOX_PDB 0x00c60f60
bool TCColorEq::BSMultiBoundCapsule_IsEqual(NiObject* pObject)
{
    bool bResultTmp = BSMultiBoundShape_IsEqual(pObject);
    if (bResultTmp)
    {
        TCColorEq* pOther = (TCColorEq*)pObject;
        {
            NiPoint3* pB = &pOther->m0c;
            NiPoint3* pA = &m0c;
            bResultTmp = pA->x == pB->x && pA->y == pB->y && pA->z == pB->z;
        }
        {
            NiPoint3* pB3 = &pOther->m18;
            NiPoint3* pA9 = &m18;
            bResultTmp &= (bool)(int)(pA9->x == pB3->x && pA9->y == pB3->y && pA9->z == pB3->z);
        }
        {
            float fValue3 = m24;
            bResultTmp &= (fValue3 == pOther->m24);
        }
    }
    return bResultTmp;
}

struct VTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual int v8c();
};

struct Struct08
{
    int unk00;
    int unk04;
    int unk08;
    VTarget* unk0c;
};

struct C00c611f0
{
    int BSMultiBoundCapsule_CheckBound_00c611f0(Struct08* arg);
};

// Calls v8c on the VTarget pointer stored in arg->unk0c and returns 0.
// @fnv 0x00c611f0
// src: XBOX_PDB 0x00c611f0
int C00c611f0::BSMultiBoundCapsule_CheckBound_00c611f0(Struct08* apStruct)
{
    int res;
    VTarget* volatile form = apStruct->unk0c;
    res = form->v8c();
    return 0;
}

struct ListExtra
{
    TESForm* owner;
    unsigned int rank;
    float health;
    bool FUN_0040e9c0();
    bool Compare(ListExtra*);
};
struct LeveledEntry
{
    TESForm* form;
    unsigned short count, level;
    ListExtra* extra;
};
// Exe 0x004889d0: unit-local ListNode view; declarations and layout are preserved.
struct TesleveledlistListNodeView
{
    LeveledEntry* item;
    TesleveledlistListNodeView* next;
    bool FUN_008256d0();
    TesleveledlistListNodeView* FUN_00726070();
    LeveledEntry*& FUN_006815c0();
};
// The external leaf consumes the component receiver in ECX and returns its embedded head.
TesleveledlistListNodeView* __fastcall FUN_00717e50(TESLeveledList*);
// Compares this leveled list against another, returning true if any property or entry differs.
// @fnv 0x004889d0
bool TESLeveledList::IsEqualToBase(BaseFormComponent* component)
{
    TESLeveledList* pOtherList = dynamic_cast<TESLeveledList*>(component);
    if (!pOtherList)
        return true;
    if (GetAllBelow() != pOtherList->GetAllBelow())
        return true;
    if (vfn_14() != pOtherList->vfn_14())
        return true;
    if (vfn_10() != pOtherList->vfn_10())
        return true;
    if (GetUseAll() != pOtherList->GetUseAll())
        return true;
    if (m_pLevelGlobal != pOtherList->m_pLevelGlobal)
        return true;
    TesleveledlistListNodeView* first = FUN_00717e50(this);
    TesleveledlistListNodeView* pSecondNode = FUN_00717e50(pOtherList);
    if (first->FUN_008256d0() != pSecondNode->FUN_008256d0())
        return true;
    if (!first->FUN_008256d0())
    {
        while (first && pSecondNode)
        {
            LeveledEntry* a = first->FUN_006815c0();
            LeveledEntry* b = pSecondNode->FUN_006815c0();
            if (a && b)
            {
                if (a->form != b->form)
                    return true;
                if (a->level != b->level)
                    return true;
                if (a->count != b->count)
                    return true;
                if (a->extra && !b->extra)
                {
                    if (!a->extra->FUN_0040e9c0())
                        return true;
                }
                if (!a->extra && b->extra)
                {
                    if (!b->extra->FUN_0040e9c0())
                        return true;
                }
                if (a->extra && b->extra)
                {
                    if (a->extra->Compare(b->extra))
                        return true;
                }
            }
            first = first->FUN_00726070();
            pSecondNode = pSecondNode->FUN_00726070();
        }
        if (first || pSecondNode)
            return true;
    }
    else
    {
        if (!pSecondNode->FUN_008256d0())
            return true;
    }
    return false;
}

// Allocates and returns a new BSMultiBoundCapsule instance on the heap.
// @fnv 0x00c610a0
// src: EXE 0x00c610a0
BSMultiBoundCapsule* __cdecl BSMultiBoundCapsule_CreateObject(void)
{
    return new BSMultiBoundCapsule();
}

extern "C" void* __cdecl FUN_00ec43fb(void* in, int vfDelta, void* srcType, void* targetType, int isReference);
extern char DAT_01183040[]; /* .?AVBaseFormComponent@@ */
extern char DAT_01186c1c[]; /* .?AVTESLeveledList@@ */

class LevObjX
{
  public:
    TESForm* form;
    unsigned short level;
    unsigned short count;
    ContainerItemExtra* extra;
    LevObjX()
    {}
};

class LLNode_cls
{
  public:
    LevObjX** FUN_006815c0();
    LLNode_cls* FUN_00726070();
    bool FUN_008256d0();
    void FUN_005ae3d0(LevObjX*& obj);
    void FUN_00905820(LevObjX*& obj);
};

class CIE_cls : public ContainerItemExtra
{
  public:
    bool FUN_0040e9c0();
    void FUN_0040e980(ContainerItemExtra* src3);
};

// Copies the leveled list entries and properties from another TESLeveledList instance into this one.
// @fnv 0x004887a0
void TESLeveledList::BaseFormRecord(BaseFormComponent* apSource)
{
    TESLeveledList* src3 = (TESLeveledList*)FUN_00ec43fb(apSource, 0, &DAT_01183040, &DAT_01186c1c, 0);
    if (src3 == 0)
    {
        return;
    }
    InitializeLeveledList();
    LLNode_cls* it = static_cast<LLNode_cls*>(src3->GetLeveledList());
    LevObjX* cell5;
    LLNode_cls* dst = static_cast<LLNode_cls*>(GetLeveledList());
    while (it != 0 && (cell5 = *it->FUN_006815c0()) != 0)
    {
        LevObjX* newObj = new LevObjX();
        newObj->form = cell5->form;
        newObj->count = cell5->count;
        newObj->level = cell5->level;
        if (cell5->extra != 0 && !static_cast<CIE_cls*>(cell5->extra)->FUN_0040e9c0())
        {
            newObj->extra = new ContainerItemExtra();
            static_cast<CIE_cls*>(newObj->extra)->FUN_0040e980(cell5->extra);
        }
        if (static_cast<LLNode_cls*>(GetLeveledList())->FUN_008256d0())
        {
            dst->FUN_005ae3d0(newObj);
        }
        else
        {
            dst->FUN_00905820(newObj);
            dst = dst->FUN_00726070();
        }
        it = it->FUN_00726070();
    }
    m_pLevelGlobal = src3->m_pLevelGlobal;
    ExtraWeaponModFlags_SetWeaponModFlags(src3->vfn_10());
    SetCalcAllBelow(src3->FUN_004877e0());
    SetMultCalc(src3->vfn_14());
    SetUseAll(src3->FUN_004878a0());
}
