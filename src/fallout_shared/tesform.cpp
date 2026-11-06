// fallout_shared/tesform.cpp: TESForm, TESValueForm, TESFile, BGSSaveLoadChangesMap and more (128 functions)

// Use the shared base definitions required by ActorValueInfo and the components.
#include "tesform_layout_support.h"
#include "tesform_containers.h"
#include "../../include/TESForm.h"
#include "../../include/FormChangeMask.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESDataHandler.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/TESSaveLoadGame.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/FormRecordHeader.h"
#include "../../include/MapEntryCount.h"
#include "../../include/TESFileHeader.h"
// The unit support header already supplies NiFile and the container layouts.
#define FNV_LAYOUT_SUPPORT_H
#include "../../include/TESFile.h"
#undef FNV_LAYOUT_SUPPORT_H
#include "../../include/ActorValueOwner.h"
#include "../../include/BSExtraData.h"
#include "../../include/CachedValuesOwner.h"
#include "../../include/DummyPointerMap.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/TESChildCell.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/ActorValueInfo.h"
#include "../../include/BGSClipRoundsForm.h"
#include "../../include/BGSSaveLoadChangesMap.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESDescription.h"
#include "../../include/TESFullName.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESIcon.h"
#include "../../include/TESModel.h"
#include "../../include/TESQualityForm.h"
#include "../../include/TESTexture.h"
#include "../../include/TESUsesForm.h"
#include "../../include/TESWeightForm.h"

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESSaveLoadGame* g_TESSaveLoadGame;
FNV_STATIC_ASSERT(sizeof(TESValueForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESValueForm, uiValue) == 4);

// Walks the source-file list, returning the last non-null TESFile, or the one at fileIndex when fileIndex is not -1.
// @fnv 0x00484e60
TESFile* TESForm::GetFile(int fileIndex)
{
    TESFile* sourceFile;
    int index;
    BSSimpleList<TESFile*>* fileList;
    TESFile* selected;
    fileList = GetSourceFiles();
    index = 0;
    sourceFile = 0;
    selected = 0;
    while (fileList)
    {
        sourceFile = fileList->GetItem();
        fileList = fileList->GetNext();
        if (sourceFile)
        {
            selected = sourceFile;
            if (fileIndex != -1)
            {
                ++index;
                if (index > fileIndex)
                {
                    break;
                }
            }
        }
    }
    return selected;
}

// Covered functions reconstructed from the supplied disassembly.
// @fnv 0x00401170
ENUM_FORM_ID TESForm::GetFormType() const
{
    return static_cast<ENUM_FORM_ID>(cFormType);
}
// @fnv 0x00440da0
bool TESForm::GetDisabled() const
{
    return (iFormFlags & 0x800);
}
// @fnv 0x00483710
void TESForm::ClearData()
{}
// @fnv 0x00484490
void TESForm::NotifySaveLoadGameOfFormChange()
{
    UpdateFormChangeFlags();
    if (g_TESSaveLoadGame)
        g_TESSaveLoadGame->HasFormChanges(this, false);
    if (g_BGSSaveLoadGame)
        g_BGSSaveLoadGame->HasFormChanges(this);
    iFormFlags |= 0x4000;
}

// @fnv 0x004844f0
void TESForm::SetMasterFile(bool set)
{
    if (set)
        iFormFlags |= 0x1;
    else
        iFormFlags &= ~0x1;
}

// @fnv 0x00484530
void TESForm::MarkForDeletion(bool set)
{
    if (set)
        iFormFlags |= 0x20;
    else
        iFormFlags &= ~0x20;
    MarkAsModified(1);
}

// @fnv 0x00484650
void TESForm::SetDestroyed(bool abDestroyed)
{
    if (abDestroyed)
        iFormFlags |= 0x800000;
    else
        iFormFlags &= ~0x800000;
    MarkAsModified(1);
}

// @fnv 0x004846a0
void TESForm::SetDestructible(bool set)
{
    if (set)
        iFormFlags |= 0x1000000;
    else
        iFormFlags &= ~0x1000000;
}

// @fnv 0x004848b0
void TESForm::SetFormFlag40(bool set)
{
    if (set)
        iFormFlags |= 0x40;
    else
        iFormFlags &= ~0x40;
    MarkAsModified(1);
}

// @fnv 0x00484900
void TESForm::SetHavokDeath(bool set)
{
    if (set)
        iFormFlags |= 0x10000;
    else
        iFormFlags &= ~0x10000;
    MarkAsModified(1);
}

// @fnv 0x00484950
void TESForm::SetNeedToChangeProcess(bool set)
{
    if (set)
        iFormFlags |= 0x20000;
    else
        iFormFlags &= ~0x20000;
}

// @fnv 0x00484990
void TESForm::SetIgnoreFriendlyHits(bool set)
{
    if (set)
        iFormFlags |= 0x100000;
    else
        iFormFlags &= ~0x100000;
}

// @fnv 0x00484ab0
void TESForm::SetInitializationState(bool set)
{
    if (set)
        iFormFlags |= 0x8;
    else
        iFormFlags &= ~0x8;
}

// @fnv 0x00484b40
bool TESForm::IsReservedFormID(unsigned int formID)
{
    if (formID != 0 && formID <= 0x7ff)
        return true;
    else
        return false;
}
// @fnv 0x00484e40
bool TESForm::IsReservedFormID()
{
    return IsReservedFormID(GetFormID());
}
// @fnv 0x00484b60
void TESForm::MarkAsModified(unsigned int flags)
{
    g_BGSSaveLoadGame->NotifyFormIDChanged(this, flags, false);
}
// Forwards this form and the given flags to g_BGSSaveLoadGame's handler with the third argument set to true.
// @fnv 0x00484b90
void TESForm::SetFormFlags(int flags)
{
    g_BGSSaveLoadGame->NotifyFormIDChanged(this, flags, true);
}
// @fnv 0x00484bc0
void TESForm::MarkAsUnmodified(unsigned int flags)
{
    g_BGSSaveLoadGame->ClearFormChangeFlags(this, flags);
}
// Reads 4 bytes of change flags from the load buffer when flag 1 is set and merges the masked bits into the form's flags field.
// @fnv 0x00484da0
void TESForm::LoadGame(BGSLoadFormBuffer* apLoadBuffer)
{
    // Select the original bool conversion, rather than the non-const int overload.
    if (static_cast<BGSLoadFormBuffer*>(apLoadBuffer)->GetChangeFlags(1u).operator bool())
    {
        unsigned int flags = 0;
        static_cast<BGSLoadFormBuffer*>(apLoadBuffer)->ReadTypedData(static_cast<void*>(&flags), 4u);
        if (GetIsReference())
            iFormFlags = (iFormFlags & 0xff6ed79f) | (flags & 0x00912860);
        else
            iFormFlags = (iFormFlags & 0xbffff3df) | (flags & 0x40000c20);
    }
}
// Stores value in uiValue and, if this is a TESForm, marks it as modified with flag 2.
// @fnv 0x0048e960
void TESValueForm::SetFormValue(unsigned int value)
{
    uiValue = value;
    TESForm* form = dynamic_cast<TESForm*>(this);
    if (form)
        form->MarkAsModified(2);
}
// Stores item into m_item when item is non-null; returns early otherwise.
// @fnv 0x00726c60
template <> void BSSimpleList<TESFile*>::SetItem(TESFile* const& apFile)
{
    if (!apFile)
        return;
    m_item = apFile;
}
// @fnv 0x00484ee0
TESFile* TESForm::GetOwnerMaster()
{
    BSSimpleList<TESFile*>* pFileNode = GetSourceFiles();
    TESFile* pOwnerMaster = 0;
    while (pFileNode && !pFileNode->IsEmpty())
    {
        TESFile* file = pFileNode->GetItem();
        pFileNode = pFileNode->GetNext();
        if (file->IsMasterFile())
            pOwnerMaster = file;
    }
    return pOwnerMaster;
}

// Looks up editorID in the form table and returns the matching TESForm, or null if editorID is empty or not found.
// @fnv 0x00483a00
TESForm* TESForm::LookupFormByEditorID(const char* editorID)
{
    TESForm* form = 0;
    if (editorID && *editorID && ms_pEditorIDMap && ms_pEditorIDMap->GetAt(editorID, form))
    {
        return form;
    }
    else
    {
        return 0;
    }
}

// Lazily allocates the three global form lookup containers (pointer map, case-insensitive string map, large primitive array) if they are null.
// @fnv 0x00483a50
void TESForm::InitializeFormIDMap()
{
    if (!ms_pFormIDMap)
    {
        ms_pFormIDMap = new NiTPointerMap<unsigned int, TESForm*>(0x2008D);
    }
    if (!ms_pEditorIDMap)
    {
        ms_pEditorIDMap = new BSTCaseInsensitiveStringMap<TESForm*>(0xFA1, true);
    }
    if (!ms_pAllForms)
    {
        ms_pAllForms = new NiTLargePrimitiveArray<TESForm*>(32, 1);
    }
}

// @fnv 0x00484f50
void TESForm::SetFile(TESFile* file)
{
    TESFile* parentFile = file ? file->GetThreadSafeRootFile() : 0;
    if (parentFile)
    {
        file = parentFile;
    }
    if (!file)
    {
        BSSimpleList<TESFile*>* source = GetSourceFiles();
        BSSimpleList<TESFile*>* lastSource = 0;
        while (source)
        {
            if (source->GetItem())
            {
                lastSource = source;
            }
            source = source->GetNext();
        }
        if (lastSource)
        {
            lastSource->RemoveHead();
        }
        else
        {
            GetSourceFiles()->RemoveHead();
        }
    }
    else if (file->IsMasterFile())
    {
        BSSimpleList<TESFile*>* source = GetSourceFiles();
        BSSimpleList<TESFile*>* lastMaster = 0;
        while (source && !source->IsEmpty())
        {
            TESFile* sourceFile = source->GetItem();
            if (sourceFile->IsMasterFile())
            {
                lastMaster = source;
                source = source->GetNext();
            }
            else
            {
                if (lastMaster)
                {
                    lastMaster->Remove(sourceFile);
                    source = lastMaster->GetNext();
                }
                else
                {
                    source->RemoveHead();
                }
            }
        }
        GetSourceFiles()->AddTail(file);
    }
    else
    {
        BSSimpleList<TESFile*>* source = GetSourceFiles();
        BSSimpleList<TESFile*>* lastSource = 0;
        while (source)
        {
            TESFile* sourceFile = source->GetItem();
            if (sourceFile)
            {
                lastSource = source;
                if (sourceFile == file)
                {
                    return;
                }
            }
            source = source->GetNext();
        }
        if (lastSource)
        {
            lastSource->AddTail(file);
        }
        else
        {
            GetSourceFiles()->AddHead(file);
        }
    }
}

// @fnv 0x00467bb0
unsigned int TESFile::GetOffset()
{
    return m_uiRecordSize;
}

extern int DAT_01014210;

// @fnv 0x0040ecb0
void __fastcall FUN_0040ecb0(int* p)
{
    *p = (int)&DAT_01014210;
}

// @fnv 0x00471d60
bool TESFile::GetActive()
{
    if (m_uiFileCount & 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x004835e0
unsigned int __fastcall GetField20C(char* pThis)
{
    return *(unsigned int*)(pThis + 0x20c);
}

struct S00485110
{
    void CallWithThis(TESFile* f);
};
// @fnv 0x00485110
void S00485110::CallWithThis(TESFile* apTarget)
{
    apTarget->LoadForm(reinterpret_cast<TESForm*>(this));
}

// Returns the smaller of two unsigned short values.
// @fnv 0x004865f0
unsigned short __cdecl MinUnsignedShort(unsigned short ausValue1, unsigned short ausValue2)
{
    return ausValue1 < ausValue2 ? ausValue1 : ausValue2;
}

struct FormEnumEntry
{
    unsigned int m_uiFormID;
    int unk4;
    int unk8;
};

extern FormEnumEntry DAT_01187008[];
extern int DAT_011c54f0;
extern unsigned int DAT_011c54f4;

// @fnv 0x00486890
int __cdecl FindFormEnumIndex(unsigned int aiFormString)
{
    if (aiFormString == DAT_011c54f4)
    {
        return DAT_011c54f0;
    }
    for (int i = 0; i < 0x79; ++i)
    {
        if (DAT_01187008[i].m_uiFormID == aiFormString)
        {
            DAT_011c54f0 = i;
            DAT_011c54f4 = aiFormString;
            return DAT_011c54f0;
        }
    }
    return 0;
}

// @fnv 0x00486930
template <>
NiTPointerMap<unsigned int, TESForm*>::NiTPointerMap(unsigned int uiHashSize)
    : NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, TESForm*>(uiHashSize)
{
}

// @fnv 0x00486ab0
template <>
BSTCaseInsensitiveStringMap<TESForm*>::BSTCaseInsensitiveStringMap(unsigned int uiHashSize, bool bCopy)
    : NiTStringMap<TESForm*>(uiHashSize, bCopy)
{
}

// @fnv 0x0048ce80
void __fastcall ClearString(char* this_ptr)
{
    ((BSStringT<char>*)(this_ptr + 4))->Set(0, 0);
}

struct S00551440
{
    char pad[0x24];
    unsigned char flags;
    void FUN_00551440(bool v);
};
// Sets or clears bit 0x10 in the flags byte according to v.
// @fnv 0x00551440
void S00551440::FUN_00551440(bool v)
{
    if (v)
        flags |= 0x10;
    else
        flags &= ~0x10;
}

struct FUN_00576d30_shell : public TESForm
{
    bool FUN_00576d30();
};

// @fnv 0x00576d30
bool FUN_00576d30_shell::FUN_00576d30()
{
    return (iFormFlags & 0x200000) ? true : false;
}

extern int DAT_011c54bc;
void __cdecl FUN_00483b80();
struct FUN_00483630_holder
{
    char pad[0xc];
    BSSimpleList<TESFile*> l;
    virtual ~FUN_00483630_holder();
};
// @fnv 0x00483630
FUN_00483630_holder::~FUN_00483630_holder()
{
    ((TESForm*)this)->UpdateFormChangeFlags();
    l.RemoveAll();
    if (!((TESForm*)this)->IsTemporary() && g_TESSaveLoadGame)
    {
        g_TESSaveLoadGame->HasFormChanges((TESForm*)this, false);
        g_TESSaveLoadGame->FinalizeForm((TESForm*)this);
    }
    if (!((TESForm*)this)->IsTemporary() && g_BGSSaveLoadGame)
        g_BGSSaveLoadGame->HasFormChanges((TESForm*)this);
    if (--DAT_011c54bc == 0)
        FUN_00483b80();
}

struct FUN_00483c70_shell : public TESForm
{
    void FUN_00483c70();
};

extern TESDataHandler* g_dataHandler;
// @fnv 0x00483c70
void FUN_00483c70_shell::FUN_00483c70()
{
    if (IsTemporary())
        return;
    if (ms_pFormIDMap)
        ms_pFormIDMap->RemoveAt(iFormID);
    for (unsigned int iIndex = 0; ms_pAllForms && iIndex < static_cast<const NiTLargePrimitiveArray<TESForm*>*>(ms_pAllForms)->GetSize(); iIndex++)
    {
        if (ms_pAllForms->GetAt(iIndex) == this)
        {
            ms_pAllForms->RemoveAt(iIndex);
            break;
        }
    }
    if (g_dataHandler)
        g_dataHandler->RemoveIDFromDataHandler(*(unsigned int*)((char*)this + 0xc));
}

// @fnv 0x00485d50
void ResolveFormID(unsigned int* aiID, TESFile* apFile)
{
    if (g_TESSaveLoadGame->GetLoading())
    {
        *aiID = g_TESSaveLoadGame->ConvertNumericID(*aiID);
    }
    else if (!TESForm::IsReservedFormID(*aiID))
    {
        if (apFile)
        {
            TESFile* pMasterFile = apFile->GetMasterFile((*aiID >> 24) + 1);
            if (pMasterFile)
            {
                *aiID = (pMasterFile->GetFileCompileIndex() << 24) | (*aiID & 0xffffff);
            }
            else
            {
                *aiID = (apFile->GetFileCompileIndex() << 24) | (*aiID & 0xffffff);
            }
        }
    }
}

struct NiFormArray;
struct PerkEntryConditionSet;
struct TESIdleForm;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectREFR;
struct FileEntryList;
struct IdleAnimationManager
{
    void RemoveIdleForm(TESIdleForm*);
    void InitializeIdleAnimations();
    void ResetIdleAnimations();
    void LoadIdleAnimations();
    NiFormArray* AddRootIdleArray(TESForm*);
    NiFormArray* AddRootIdleArray(char*, void*, bool);
    NiFormArray* GetRootIdleArray(TESForm*);
    NiFormArray* GetRootIdleArray(char*);
    NiFormArray* GetIdleArray(TESForm*);
    NiFormArray* GetIdleArray(char*);
    static void BuildIdlePath(char*, char*);
    void* FindIdleArrayEntry(char*, int);
    void ClearIdleData();
    static TESObject* GetCurrentUsedItem();
    static void SetUsedItem(TESObject*);
    static void SetUsedItemLevel(int);
    static int GetUsedItemLevel();
    static void SetUsedItemActivate(bool);
    static bool GetUsedItemActivate();
    bool GetInitialized();
    TESIdleForm* FindIdleFormForObject(TESObjectREFR*, TESObjectREFR*);
    char m_acIdlePath[20];
    bool bInitialized;
    char _pad_15[3];
    NiTPrimitiveArray<unsigned int> m_kIdleForms;
};
typedef char _sizecheck_TESIdleManager[sizeof(IdleAnimationManager) == 40 ? 1 : -1];
struct FUN_005ffbf0_shell : public IdleAnimationManager
{
    void AddIdleToArray(TESIdleForm*);
};

// @fnv 0x005ffbf0
void FUN_005ffbf0_shell::AddIdleToArray(TESIdleForm* apIdle)
{
    if (apIdle)
        m_kIdleForms.AddFirstEmpty((const unsigned int&)apIdle);
}

struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadGameBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct TESFileGroup;
struct FurnitureMark;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
class NiMatrix3;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESGlobal;
struct TESIdleForm;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
struct FUN_004011d0_shell : public TESForm
{
    bool FUN_004011d0();
};

// @fnv 0x004011d0
bool FUN_004011d0_shell::FUN_004011d0()
{
    return (iFormFlags & 0x20000) ? true : false;
}

class ActiveEffect;
class Actor;
class ActorMover;
class AlchemyItem;
struct BGSEncounterZone;
struct BGSImpactDataSet;
class BGSLoadGameBuffer;
class BGSPerk;
class BGSPerkEntry;
class BGSSaveGameBuffer;
class BGSTextureSet;
class BSAnimGroupSequence;
class BSAnimNote;
class BSAnimNoteReceiver;
class BSExtraData;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSMultiBound;
class BSMultiBoundRoom;
class BaseProcess;
class CellMopp;
class CombatController;
class ActorCombatGroup;
class ContinuousBeamProjectile;
class EffectItem;
class ExtraDataList;
class ExtraLock;
class FurnitureMark;
class IDebugText;
struct InventoryChanges;
class InventoryStackRecord;
class MagicCaster;
class MagicItem;
class MagicProjectile;
class MagicTarget;
class MobileObject;
class NiAVObject;
class NiControllerManager;
class NiControllerSequence;
class NiFixedString;
class NiGeometry;
class NiLight;
class NiMatrix3;
class NiNode;
class NiPoint3;
class NiPointLight;
class PlacedObjectInfo;
class PathingAvoidNodeArray;
class PathingLocation;
class PathingRequest;
class Projectile;
class QueuedFile;
class Script;
class ScriptLocals;
class SpellItem;
class TESActorBase;
class TESAmmo;
class TESBoundObject;
class TESClass;
class TESCombatStyle;
class TESContainer;
class TESFaction;
class TESGlobal;
class TESIdleForm;
class TESObject;
class TESObjectARMO;
class TESObjectBOOK;
class TESObjectCELL;
class TESObjectCLOT;
class TESObjectLIGH;
class TESObjectREFR;
class TESObjectWEAP;
class TESPackage;
class TESRace;
class TESSkill;
class TESSound;
class TESTopic;
class TESTopicInfo;
class TESWorldSpace;
class TargetEntry;
class TrespassPackage;
class WeaponObject;
class bhkCharacterController;
class bhkNiCollisionObject;
class bhkRagdollController;
class bhkRigidBody;
class hkpRigidBody;
namespace fnv_004011f0 {
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct ExplosionForm;
struct BipedAnim;
struct CombatGroupCollection;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct TESFileGroup;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct CellDataNode;
struct MagicEffectCollection;
struct MapMarkerData;
struct Point3Offset;
struct AnimationInterpolator;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct TrapEntry;
struct WaterZone;
struct bhkRagdollPenetrationUtil;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
struct FUN_004011f0_shell : public TESForm
{
    bool FUN_004011f0();
};

// @fnv 0x004011f0
bool FUN_004011f0_shell::FUN_004011f0()
{
    return (iFormFlags & 0x80000) ? true : false;
}
}  // namespace fnv_004011f0

struct S3c60
{
    int GetArchetype(void);
    int FUN_00408a40(void);
};

extern "C" int __cdecl GetEntryByIndex(int);

// @fnv 0x00408a40
int S3c60::FUN_00408a40()
{
    return GetEntryByIndex(GetArchetype());
}

extern unsigned char DAT_011c3c0d;

// @fnv 0x00456c70
unsigned char FUN_00456c70()
{
    return DAT_011c3c0d;
}

struct Base5a
{
    virtual ~Base5a();
};

void Deallocate(void* memory);

struct FUN_00483600_holder : Base5a
{
    void* DestroyHolder(unsigned int flags);
};

// Runs the base destructor, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00483600
void* FUN_00483600_holder::DestroyHolder(unsigned int flags)
{
    Base5a::~Base5a();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00484610_shell
{
    int _pad0;
    int _pad1;
    unsigned int iFormFlags;
    void SetFlag2000(bool value);
};

// @fnv 0x00484610
void FUN_00484610_shell::SetFlag2000(bool abSet)
{
    if (abSet)
        iFormFlags |= 0x2000;
    else
        iFormFlags &= ~0x2000;
}

struct FUN_004849d0_shell
{
    unsigned int m0;
    unsigned int m1;
    unsigned int iFormFlags;
    void SetFlag200(bool abVal);
};

// @fnv 0x004849d0
void FUN_004849d0_shell::SetFlag200(bool abVal)
{
    if (abVal)
        iFormFlags |= 0x200;
    else
        iFormFlags &= ~0x200;
}

struct FUN_00484bf0_shell
{
    unsigned short __thiscall FUN_00484bf0(unsigned int aiFlags);
};

// Returns 4 when bit 0 of aiFlags is set, otherwise 0.
// @fnv 0x00484bf0
unsigned short __thiscall FUN_00484bf0_shell::FUN_00484bf0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    if (aiFlags & 1)
        isize += 4;
    return isize;
}

extern unsigned int kGroupFormType;

struct FUN_004854e0_shell : TESForm
{
    bool IsGroupFormOfType(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly);
};

// Returns true if apGroupFORM is a group form with form ID 0 whose flags match the value indexed by this form's type.
// @fnv 0x004854e0
bool FUN_004854e0_shell::IsGroupFormOfType(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly)
{
    bool bretval = false;
    if (apGroupFORM && apGroupFORM->form == kGroupFormType && apGroupFORM->iFormID == 0)
    {
        if (apGroupFORM->flags == *(unsigned int*)(this->GetFormType() * 0xc + 0x1187008))
            bretval = true;
    }
    return bretval;
}

extern "C" void __cdecl AppendChunk(int, int, int);

// @fnv 0x004856d0
void __cdecl FUN_004856d0(int arg)
{
    AppendChunk(arg, 0, 0);
}

void __cdecl AppendChunk(void* a1, void* a2, void* a3);

// @fnv 0x004856f0
void __cdecl FUN_004856f0(void* apArg1, void* apArg2, void* apArg3)
{
    AppendChunk(apArg1, apArg2, apArg3);
}

void __cdecl FUN_00485750(void* arg0, void* arg1, void* arg2);

// @fnv 0x00485710
void __cdecl FUN_00485710(void* arg0, void* arg1, void* arg2)
{
    FUN_00485750(arg0, arg1, arg2);
}

extern void __cdecl FUN_00485820(void*, void*, void*);

// @fnv 0x00485730
void __cdecl FUN_00485730(void* apArg1, void* apArg2, void* apArg3)
{
    FUN_00485820(apArg1, apArg2, apArg3);
}

extern void* DAT_011c54cc;
void __cdecl Deallocate(void*);

struct FUN_00485b30_shell
{
    void ResetGlobalPointer();
};

// Frees the pointer stored in DAT_011c54cc and sets it to null.
// @fnv 0x00485b30
void FUN_00485b30_shell::ResetGlobalPointer()
{
    Deallocate(DAT_011c54cc);
    DAT_011c54cc = 0;
}

struct FUN_00485e00_shell
{
    void __thiscall FUN_00485e20(int, int);
    void __thiscall FUN_00485e00();
};

// @fnv 0x00485e00
void __thiscall FUN_00485e00_shell::FUN_00485e00()
{
    FUN_00485e20(0, 0);
}


// NiTPointerMap::NewItem: a node from the NiTPointerAllocator pool (the allocator is the item count's empty base).
// @fnv 0x00486a90
template <>
NiTMapItem<unsigned int, FormChangeRecord*>* NiTPointerMap<unsigned int, FormChangeRecord*>::NewItem()
{
    return reinterpret_cast<NiTMapItem<unsigned int, FormChangeRecord*>*>(m_kItemCount.Allocate());
}

extern int DAT_0118a870[];

struct FUN_0051dab0_shell
{
    int __thiscall GetIndexedValue();
};

// @fnv 0x0051dab0
int __thiscall FUN_0051dab0_shell::GetIndexedValue()
{
    return DAT_0118a870[*(char*)(((char*)this) + 0xf4)];
}

// Exe 0x005516c0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct TesformOffset08View
{
    unsigned int GetFlags(void);
};

struct FUN_005516c0
{
    bool IsCellPersistent();
};

// Returns true if GetFlags() has bit 0x400 set, otherwise false.
// @fnv 0x005516c0
bool FUN_005516c0::IsCellPersistent()
{
    if (((TesformOffset08View*)this)->GetFlags() & 0x400)
    {
        return true;
    }
    else
    {
        return false;
    }
}

extern "C" void __cdecl FUN_005548a0(int);

struct FUN_00554880_shell
{
    void __thiscall FUN_00554880(unsigned char arg);
};

// @fnv 0x00554880
void __thiscall FUN_00554880_shell::FUN_00554880(unsigned char arg)
{
    FUN_005548a0(arg);
}

extern unsigned char __cdecl FUN_00588a60(unsigned char);

struct FUN_00588a40_shell
{
    unsigned char __thiscall FUN_00588a40(unsigned char arg);
};

// @fnv 0x00588a40
unsigned char __thiscall FUN_00588a40_shell::FUN_00588a40(unsigned char arg)
{
    return FUN_00588a60(arg);
}

namespace fnv_005e9690 {
extern "C" void __cdecl FUN_004856d0(int);

struct FUN_005e9690_shell
{
    void __thiscall FUN_005e9690();
};

// @fnv 0x005e9690
void __thiscall FUN_005e9690_shell::FUN_005e9690()
{
    FUN_004856d0(0x464b5250);
}
}  // namespace fnv_005e9690

struct FUN_0061bbd0_shell
{
    unsigned char __thiscall FUN_0061bbd0(unsigned char param);
};

extern unsigned char __cdecl FUN_0061bbf0(unsigned char);

// @fnv 0x0061bbd0
unsigned char __thiscall FUN_0061bbd0_shell::FUN_0061bbd0(unsigned char param)
{
    return FUN_0061bbf0(param);
}

struct FUN_00621b00_shell
{
    float __thiscall FUN_00621b00();
};

// @fnv 0x00621b00
float __thiscall FUN_00621b00_shell::FUN_00621b00()
{
    return *(float*)((char*)this + 0x10);
}

// @fnv 0x008df040
unsigned char TESSaveLoadGame::GetCurrentVersion()
{
    return m_ucCurrentVersion;
}

struct FUN_004011b0_shell
{
    unsigned int m_BaseFormComponent;  // +0x00
    unsigned int m_Padding;            // +0x04
    unsigned int iFormFlags;        // +0x08
    bool IsFlagSet() const;
};

// @fnv 0x004011b0
bool FUN_004011b0_shell::IsFlagSet() const
{
    return (iFormFlags & 0x10000) ? true : false;
}

struct FUN_00401210_shell
{
    int _pad0;
    int _pad1;
    unsigned int iFormFlags;
    bool HasFlag() const;
};

// @fnv 0x00401210
bool FUN_00401210_shell::HasFlag() const
{
    return (iFormFlags & 0x2000000) ? true : false;
}

struct FUN_00401250_shell
{
    unsigned int m_BaseFormComponent[2];
    unsigned int iFormFlags;
    bool IsFlag200Set();
};

// @fnv 0x00401250
bool FUN_00401250_shell::IsFlag200Set()
{
    return (iFormFlags & 0x200) ? true : false;
}

struct FUN_00484a70_shell
{
    int m_00;
    int m_04;
    int m_08;
    void FUN_00484a70(bool value);
};

// Sets or clears bit 0x80 in m_08 according to value.
// @fnv 0x00484a70
void FUN_00484a70_shell::FUN_00484a70(bool abSet)
{
    if (abSet)
        m_08 |= 0x80;
    else
        m_08 &= ~0x80;
}

struct FUN_004362a0 : BSExtraData
{
    int _c;
    ~FUN_004362a0();
};
// Destructor that calls TESForm::ClearData on the _c member.
// @fnv 0x004362a0
FUN_004362a0::~FUN_004362a0()
{
    ((TESForm*)&_c)->TESForm::ClearData();
}

namespace fnv_004363c0 {
struct FUN_004363c0
{
    BSExtraData data;
    int _4;
    int _8;
    int _c;
    ~FUN_004363c0();
};
// @fnv 0x004363c0
FUN_004363c0::~FUN_004363c0()
{
    ((TESForm*)((char*)this + 12))->TESForm::ClearData();
}
}  // namespace fnv_004363c0

namespace fnv_004364e0 {
struct FUN_004364e0 : BSExtraData
{
    BSSoundHandle m;
    virtual ~FUN_004364e0();
};
// Destructor for a BSExtraData-derived object; destroys its member and the base class.
// @fnv 0x004364e0
FUN_004364e0::~FUN_004364e0()
{}
}  // namespace fnv_004364e0

namespace fnv_00436600 {
struct FUN_00436600 : BSExtraData
{
    ~FUN_00436600();
};
// @fnv 0x00436600
FUN_00436600::~FUN_00436600()
{
    ((TESForm*)((char*)this + 12))->TESForm::ClearData();
}
}  // namespace fnv_00436600

namespace fnv_00436720 {
struct FUN_00436720 : BSExtraData
{
    int _f0c;
    ~FUN_00436720();
};
// @fnv 0x00436720
FUN_00436720::~FUN_00436720()
{
    ((TESForm*)&_f0c)->TESForm::ClearData();
}
}  // namespace fnv_00436720

extern int DAT_00ffffff;
// @fnv 0x004696f0
void TESDataHandler::RemoveIDFromDataHandler(unsigned int value)
{
    unsigned int desired;
    desired = iNumCompile;
    desired = 0xff;
    if (value && (value >> 0x18) == desired && !bDontRemoveIDs &&
        value < iNextID && (value & (unsigned int)&DAT_00ffffff) > 0x7ff)
        iNextID = value;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<1>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
void __cdecl BSEndian(int*, EndianSizeTag<4>);
// @fnv 0x00470650
void __fastcall ConvertFormRecordEndian(FormRecordHeader* record)
{
    BSEndian((unsigned char*)record, EndianSizeTag<1>());
    BSEndian((unsigned char*)((char*)record + 4), EndianSizeTag<1>());
    BSEndian((unsigned char*)((char*)record + 8), EndianSizeTag<1>());
    BSEndian((unsigned char*)((char*)record + 12), EndianSizeTag<1>());
    BSEndian((unsigned char*)((char*)record + 16), EndianSizeTag<1>());
    BSEndian((unsigned short*)((char*)record + 20), EndianSizeTag<2>());
    BSEndian((unsigned short*)((char*)record + 22), EndianSizeTag<2>());
}

// Looks up aiSearchID in the form map and returns the stored TESForm pointer, or 0 if the map is null or has no entry.
// @fnv 0x004839c0
TESForm* FUN_004839c0(unsigned int aiSearchID)
{
    TESForm* pTempForm = 0;
    if (TESForm::ms_pFormIDMap &&
        ((DummyPointerMap*)TESForm::ms_pFormIDMap)->GetAt(aiSearchID, (unsigned int&)pTempForm))
        return pTempForm;
    else
        return 0;
}

struct FUN_00483d20_shell : TESForm
{
    unsigned char SaveIfNotTemporary(TESFile* apFile);
};
// @fnv 0x00483d20
unsigned char FUN_00483d20_shell::SaveIfNotTemporary(TESFile* apFile)
{
    TES_RETURN_CODE eRetVal;
    if (IsTemporary())
        return 0;
    SaveForm();
    eRetVal = static_cast<TES_RETURN_CODE>(apFile->WriteFormContents(this));
    return eRetVal == 0;
}

struct FUN_00483fc0_shell : TESForm
{
    bool WriteToFile(TESFile* apFile);
};
// @fnv 0x00483fc0
bool FUN_00483fc0_shell::WriteToFile(TESFile* apFile)
{
    if (IsTemporary())
        return false;
    if (IsDeleted())
    {
        apFile->WriteForm(this);
        apFile->RewriteFormHeader();
        return true;
    }
    return AppendForm(apFile);
}

struct Fake84860
{
    int _pad;
    unsigned int _flags;
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18(int)
    {}
    void FUN_00484860(bool);
};
// Sets or clears bit 0x400 in _flags according to abQuest, then calls v18(1).
// @fnv 0x00484860
void Fake84860::FUN_00484860(bool abQuest)
{
    if (abQuest)
    {
        _flags |= 0x400;
    }
    else
    {
        _flags &= ~0x400;
    }
    v18(1);
}

struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
    void FUN_00484c20(unsigned int);
};
// If bit 0 of aiFlags is set, calls FUN_00484ce0 on the object at this+8 with 4.
// @fnv 0x00484c20
void PC7d::FUN_00484c20(unsigned int aiFlags)
{
    if (aiFlags & 1)
        FUN_00484ce0((unsigned int)((char*)this + 8), 4);
}

struct FUN_00484d40_Host
{
    void __thiscall FUN_00484d40(unsigned int* apNumericID, int aiSize);
};
// Forwards the numeric ID buffer and its size to the save/load game object's handler.
// @fnv 0x00484d40
void __thiscall FUN_00484d40_Host::FUN_00484d40(unsigned int* apNumericID, int aiSize)
{
    g_TESSaveLoadGame->FUN_00857aa0(apNumericID, aiSize);
}

struct FakeForm
{
    char _pad[8];
    int _v08;
    void SaveIfChanged(BGSSaveFormBuffer*);
};
// If the form buffer reports change flags for bit 1, saves the 4-byte value at _v08 into the buffer.
// @fnv 0x00484d60
void FakeForm::SaveIfChanged(BGSSaveFormBuffer* buffer)
{
    // Select the original bool conversion, rather than the non-const int overload.
    if (buffer->GetChangeFlags(1).operator bool())
        buffer->SaveData(&_v08, 4, 0);
}

struct FUN_00485130_shell
{
    void WarnCopyUnsupported(TESForm* apCopy);
};
struct TESForm_Proxy40e30
{
    char const* FUN_00440e30();
};
int _FNV_Warning(char const*, char const*, char const*);
// Logs a warning that copying the given form is unsupported, printing its name and type name.
// @fnv 0x00485130
void FUN_00485130_shell::WarnCopyUnsupported(TESForm* apCopy)
{
    _FNV_Warning("FORMS: Trying to copy form \"%s\".\r\nNo copy function for %s form types.\r\n", apCopy->GetName(),
                 ((TESForm_Proxy40e30*)apCopy)->FUN_00440e30());
}

void _FNV_Warning(const char*, ...);
struct Fake440e30
{
    const char* FUN_00440e30();
};
struct Mid485170
{
    bool FUN_00485170(TESForm*);
};
// Warns that no compare function exists for the form types and returns false.
// @fnv 0x00485170
bool Mid485170::FUN_00485170(TESForm* apCopy)
{
    _FNV_Warning("FORMS: Trying to compare form \"%s\".\r\nNo compare function for %s form types.\r\n",
                 apCopy->GetName(), ((Fake440e30*)apCopy)->FUN_00440e30());
    return false;
}

extern void* DAT_011c54cc;
extern int DAT_011c54d0;
bool FUN_00401500();
struct Holder : public TESForm
{
    void FUN_00485680();
};
// @fnv 0x00485680
void Holder::FUN_00485680()
{
    FormRecordHeader* pForm;
    if (IsTemporary())
        return;
    pForm = (FormRecordHeader*)DAT_011c54cc;
    pForm->length = DAT_011c54d0 - 0x18;
    if (FUN_00401500())
        ConvertFormRecordEndian(pForm);
}

struct FUN_00485b60
{
    unsigned int FUN_00485bc0();
    bool FUN_00485be0(unsigned int);
};
// Returns true when the low 24 bits of aiID equal the value returned by FUN_00485bc0, otherwise false.
// @fnv 0x00485be0
bool FUN_00485b60::FUN_00485be0(unsigned int aiID)
{
    if ((aiID & 0x00FFFFFF) != FUN_00485bc0())
        return false;
    return true;
}

void _NiFreeAlias(void*);

// @fnv 0x00486a60
template <>
NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, TESForm*>::~NiTMapBase()
{
    RemoveAll();
    _NiFreeAlias(m_ppkHashTable);
}

void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
// @fnv 0x00487010
void TESFullName::FUN_00487010()
{
    if (GetModelLength())
        FUN_004856f0(0x4C4C5546, (void*)GetFullName(), GetModelLength() + 1);
}

struct FUN_00549580_shell
{
    bool FUN_00549580() const;
};

// @fnv 0x00549580
bool FUN_00549580_shell::FUN_00549580() const
{
    return (((const TESForm*)this)->iFormFlags & 64) ? true : false;
}

struct FUN_009f87b0_shell
{
    void FUN_006796c0();
    void FUN_009f9720();
    unsigned int m_0x88;
    unsigned int m_0x8c;
};

TESForm* __cdecl GetFormByID(unsigned int);

// @fnv 0x009f9720
void FUN_009f87b0_shell::FUN_009f9720()
{
    FUN_006796c0();
    unsigned int v3 = *(unsigned int*)((char*)this + 0x88);
    if (v3)
        *(unsigned int*)((char*)this + 0x88) = (unsigned int)GetFormByID(v3);
    unsigned int v8c = *(unsigned int*)((char*)this + 0x8c);
    if (v8c)
        *(unsigned int*)((char*)this + 0x8c) = (unsigned int)GetFormByID(v8c);
}

struct FUN_004846e0_shell
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(int);
    unsigned int _4;
    unsigned int _8;
    void FUN_004846e0(bool);
};
// @fnv 0x004846e0
void FUN_004846e0_shell::FUN_004846e0(bool abSet)
{
    if (abSet)
        _8 |= 0x4000000;
    else
        _8 &= 0xFBFFFFFF;
    v18(1);
}

class Actor;
class BGSAcousticSpace;
struct BGSEncounterZone;
class BGSLightingTemplate;
struct BGSMusicType;
class BSFile;
class BSMultiBoundNode;
class BSPortalGraph;
class CellMopp;
class ExtraDataList;
class InteriorData;
class IntSeenData;
struct InventoryChanges;
class NavMeshCollection;
class NiAVObject;
class NiCamera;
class NiColor;
class NiNode;
class NiPick;
class NiPoint3;
class NiRenderedTexture;
class SeenData;
class TESActorBase;
class TESClimate;
class TESGlobal;
struct TESImageSpace;
class TESObject;
class TESObjectCELL;
class TESObjectLAND;
class TESObjectREFR;
class TESRegionObjectBase;
struct TESWaterForm;
class TESWorldSpace;
class bhkWorld;
namespace fnv_00483720 {
struct CellRecord;
struct ExteriorData;
struct TESFileGroup;
struct ImpactSwap;
struct LoadedCellData;
struct TESRegionList;
struct RegionPoint;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorldM;
struct blob12
{
    char b[12];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct FormComponentArray
{
    void InitializeFromForm(TESForm*);
    void ClearFormComponentArray();
    void InitializeDataAllComponents();
    void ClearDataAllComponents();
    void CopyComponentData(FormComponentArray*);
    bool AreComponentsEqual(FormComponentArray*);
    char m_pComponents[152];
};
typedef char _sizecheck_FormComponentCollection[sizeof(FormComponentArray) == 152 ? 1 : -1];
struct FUN_00483720_shell : public TESForm
{
    void ClearFormData();
};

void __fastcall ClearString(char*);
struct FUN_0047c050
{
    void* m_pComponents[38];
    FUN_0047c050();
    ~FUN_0047c050();
    void InitializeFromForm(TESForm*);
    void CallElements();
};

// @fnv 0x00483720
void FUN_00483720_shell::ClearFormData()
{
    switch (GetFormType())
    {
    case 0x39: {
        TESObjectCELL* pthiscell = (TESObjectCELL*)this;
        ClearString((char*)pthiscell + 0x18);
        ((TESForm*)pthiscell)->TESForm::ClearData();
        break;
    }
    case 0x11:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x49:
    case 0x69:
        TESForm::ClearData();
        break;
    default: {
        FUN_0047c050 components;
        components.InitializeFromForm(this);
        components.CallElements();
        break;
    }
    }
}
}  // namespace fnv_00483720

class Actor;
class BGSAcousticSpace;
struct BGSEncounterZone;
class BGSLightingTemplate;
struct BGSMusicType;
class BSFile;
class BSMultiBoundNode;
class BSPortalGraph;
class CellMopp;
class ExtraDataList;
class InteriorData;
class IntSeenData;
struct InventoryChanges;
class NavMeshCollection;
class NiAVObject;
class NiCamera;
class NiColor;
class NiNode;
class NiPick;
class NiPoint3;
class NiRenderedTexture;
class SeenData;
class TESActorBase;
class TESClimate;
class TESGlobal;
struct TESImageSpace;
class TESObject;
class TESObjectCELL;
class TESObjectLAND;
class TESObjectREFR;
class TESRegionObjectBase;
struct TESWaterForm;
class TESWorldSpace;
class bhkWorld;
namespace fnv_00483870 {
struct CellRecord;
struct ExteriorData;
struct TESFileGroup;
struct ImpactSwap;
struct LoadedCellData;
struct TESRegionList;
struct RegionPoint;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorldM;
struct blob12
{
    char b[12];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct FormComponentArray
{
    void InitializeFromForm(TESForm*);
    void ClearFormComponentArray();
    void InitializeDataAllComponents();
    void ClearDataAllComponents();
    void CopyComponentData(FormComponentArray*);
    bool AreComponentsEqual(FormComponentArray*);
    char m_pComponents[152];
};
typedef char _sizecheck_FormComponentCollection[sizeof(FormComponentArray) == 152 ? 1 : -1];
struct FUN_00483870_shell : public TESForm
{
    void FUN_00483870();
};

struct Holder_47c5b0
{
    void FUN_0047c5b0();
};
struct FUN_0047c050
{
    int m_pComponents[38];
    FUN_0047c050();
    ~FUN_0047c050();
};

// @fnv 0x00483870
void FUN_00483870_shell::FUN_00483870()
{
    switch (GetFormType())
    {
    case 0x39: {
        TESObjectCELL* pthiscell = (TESObjectCELL*)this;
        ((TESForm*)((char*)pthiscell + 0x18))->TESForm::ClearData();
        ((TESForm*)pthiscell)->TESForm::ClearData();
        break;
    }
    case 0x11:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x49:
    case 0x69:
        TESForm::ClearData();
        break;
    default: {
        FUN_0047c050 components;
        ((FormComponentArray*)&components)->InitializeFromForm(this);
        ((Holder_47c5b0*)&components)->FUN_0047c5b0();
        break;
    }
    }
}
}  // namespace fnv_00483870

class TESObjectREFR;
namespace fnv_00484730 {
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
typedef char _sizecheck_TESDescription[sizeof(TESDescription) == 8 ? 1 : -1];
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
typedef char _sizecheck_TESIcon[sizeof(TESIcon) == 12 ? 1 : -1];
typedef char _sizecheck_ActorValueInfo[sizeof(ActorValueInfo) == 196 ? 1 : -1];
struct FUN_00484730_shell : public TESForm
{
    void FUN_00484730(bool);
};


// @fnv 0x00484730
void FUN_00484730_shell::FUN_00484730(bool abAltered)
{
    if (abAltered)
    {
        if (!((TESForm*)this)->FUN_00460340() && !IsTemporary() && ms_pAllForms)
        {
            bool bAddToList = true;
            for (unsigned int iIndex = 0; iIndex < static_cast<const NiTLargePrimitiveArray<TESForm*>*>(ms_pAllForms)->GetSize(); iIndex++)
            {
                if (ms_pAllForms->GetAt(iIndex) == this)
                {
                    bAddToList = false;
                    break;
                }
            }
            if (bAddToList)
            {
                ms_pAllForms->Add(static_cast<TESForm*>(this));
            }
        }
        *(unsigned int*)((char*)this + 8) |= 2;
    }
    else
    {
        if (((TESForm*)this)->FUN_00460340() && ms_pAllForms)
        {
            for (unsigned int iIndex = 0; iIndex < static_cast<const NiTLargePrimitiveArray<TESForm*>*>(ms_pAllForms)->GetSize(); iIndex++)
            {
                if (ms_pAllForms->GetAt(iIndex) == this)
                {
                    ms_pAllForms->RemoveAt(iIndex);
                    break;
                }
            }
        }
        *(unsigned int*)((char*)this + 8) &= ~2u;
    }
}
}  // namespace fnv_00484730

typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];
typedef char _sizecheck_BGSClipRoundsForm[sizeof(BGSClipRoundsForm) == 8 ? 1 : -1];
typedef char _sizecheck_TESUsesForm[sizeof(TESUsesForm) == 8 ? 1 : -1];
typedef char _sizecheck_TESQualityForm[sizeof(TESQualityForm) == 8 ? 1 : -1];
typedef char _sizecheck_TESWeightForm[sizeof(TESWeightForm) == 8 ? 1 : -1];
struct FUN_00486620_shell : public TESForm
{
    unsigned int FUN_00486620();
};


// Sums the save sizes contributed by the form's Uses, Value, Health, Weight, Quality, AttackDamage, Attributes and ClipRounds components.
// @fnv 0x00486620
unsigned int FUN_00486620_shell::FUN_00486620()
{
    TESAttributes* pAttributes;
    BGSClipRoundsForm* pClipRounds;
    TESUsesForm* pUses;
    TESQualityForm* pQuality;
    TESWeightForm* pWeight;
    TESAttackDamageForm* pAttack;
    TESValueForm* pValue;
    unsigned int uiSaveSize;
    TESHealthForm* pHealth;
    pUses = dynamic_cast<TESUsesForm*>((TESForm*)this);
    pValue = dynamic_cast<TESValueForm*>((TESForm*)this);
    pHealth = dynamic_cast<TESHealthForm*>((TESForm*)this);
    pWeight = dynamic_cast<TESWeightForm*>((TESForm*)this);
    pQuality = dynamic_cast<TESQualityForm*>((TESForm*)this);
    pAttack = dynamic_cast<TESAttackDamageForm*>((TESForm*)this);
    pAttributes = dynamic_cast<TESAttributes*>((TESForm*)this);
    pClipRounds = dynamic_cast<BGSClipRoundsForm*>((TESForm*)this);
    uiSaveSize = 0;
    if (pUses)
        uiSaveSize += 1;
    if (pValue)
        uiSaveSize += 4;
    if (pHealth)
        uiSaveSize += 4;
    if (pWeight)
        uiSaveSize += 4;
    if (pQuality)
        uiSaveSize += 4;
    if (pAttack)
        uiSaveSize += 2;
    if (pAttributes)
        uiSaveSize += pAttributes->GetAttributeDataSize();
    if (pClipRounds)
        uiSaveSize += 1;
    return uiSaveSize;
}


// @fnv 0x00483b80
void FUN_00483b80()
{
    if (TESForm::ms_pFormIDMap)
    {
        TESForm::ms_pFormIDMap->RemoveAll();
        delete TESForm::ms_pFormIDMap;
        TESForm::ms_pFormIDMap = 0;
    }
    if (TESForm::ms_pEditorIDMap)
    {
        TESForm::ms_pEditorIDMap->RemoveAll();
        delete TESForm::ms_pEditorIDMap;
        TESForm::ms_pEditorIDMap = 0;
    }
    if (TESForm::ms_pAllForms)
    {
        TESForm::ms_pAllForms->RemoveAll();
        delete TESForm::ms_pAllForms;
        TESForm::ms_pAllForms = 0;
    }
}

namespace fnv_00485340 {
// Exe 0x00485340: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct TesformOffset08View
{
    unsigned int GetFlags();
};

struct FUN_00485340_shell : public TESForm
{
    void FUN_00485340(BaseFormComponent* apCopyFC);
};
// Copies the form type, flags and a pathing state from apCopyFC into this form, marking it altered when the pathing state differs.
// @fnv 0x00485340
void FUN_00485340_shell::FUN_00485340(BaseFormComponent* apCopyFC)
{
    TESForm* pCopy = dynamic_cast<TESForm*>(apCopyFC);
    if (!pCopy)
        return;
    if (((TESForm*)this)->FUN_00460340() != ((TESForm*)pCopy)->FUN_00460340())
        SetAltered(((TESForm*)pCopy)->FUN_00460340());
    *((unsigned char*)this + 4) = pCopy->GetFormType();
    iFormFlags = ((TesformOffset08View*)pCopy)->GetFlags() & 0xffffbfff | (iFormFlags & 0x4000);
}
}  // namespace fnv_00485340

namespace fnv_00436180 {
struct FUN_00436180 : BSExtraData
{
    virtual ~FUN_00436180();
    void ClearData();
};
// Destructor that calls ClearData on the object at offset 0xc.
// @fnv 0x00436180
FUN_00436180::~FUN_00436180()
{
    ((FUN_00436180*)((char*)this + 0xc))->ClearData();
}
}  // namespace fnv_00436180

struct FUN_00484580_shell : TESForm
{
    void FUN_00484580(bool set);
};

// @fnv 0x00484580
void FUN_00484580_shell::FUN_00484580(bool set)
{
    if (set)
    {
        if (!g_TESSaveLoadGame->GetLoading())
            MarkAsModified(0x200000);
        ((unsigned int*)this)[2] |= 0x2000;
    }
    else
    {
        if (!g_TESSaveLoadGame->GetLoading())
            MarkAsUnmodified(0x200000);
        ((unsigned int*)this)[2] &= ~0x2000;
    }
}


struct GroupData
{
    FormRecordHeader Data;
};
extern unsigned int kGroupFormType;
struct FUN_00485530_shell : TESForm
{
    void InitGroupForm(FormRecordHeader* apOutGroupFORM, GroupData* apParentGroup);
};
// @fnv 0x00485530
void FUN_00485530_shell::InitGroupForm(FormRecordHeader* apOutGroupFORM, GroupData* apParentGroup)
{
    if (apOutGroupFORM && !apParentGroup)
    {
        apOutGroupFORM->form = kGroupFormType;
        apOutGroupFORM->iFormID = 0;
        apOutGroupFORM->flags = *(unsigned int*)(0x1187008 + GetFormType() * 12);
        apOutGroupFORM->length = 0;
        apOutGroupFORM->m_uiVersionControlInfo = 0;
        apOutGroupFORM->m_usFormVersion = 0;
        apOutGroupFORM->m_usHeaderUnknown = 0;
    }
}

extern "C" void* __cdecl _NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
// @fnv 0x00486990
template <>
NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, TESForm*>::NiTMapBase(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_kItemCount.m_uiCount = 0;
    int iByteCount = m_uiHashSize << 2;
    m_ppkHashTable = static_cast<NiTMapItem<unsigned int, TESForm*>**>(_NiMalloc(iByteCount));
    memset(m_ppkHashTable, 0, m_uiHashSize << 2);
}

// @fnv 0x00486a00
template <>
NiTPointerMap<unsigned int, TESForm*>::~NiTPointerMap()
{
    RemoveAll();
}

namespace fnv_004855a0 {
// Exe 0x004855a0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
class TesformOffset08View : public TESForm
{
  public:
    unsigned int GetFlags();
    void FUN_004855a0();
};

extern void* DAT_011c54cc;
extern int DAT_011c54d0;

struct FormEnumEntry
{
    unsigned int iFormString;
    unsigned char padding[8];
};

extern FormEnumEntry DAT_01187008[];

int __cdecl FUN_00470bb0();

// @fnv 0x004855a0
void TesformOffset08View::FUN_004855a0()
{
    FormRecordHeader* pForm;

    if (IsTemporary())
        return;

    DAT_011c54d0 = sizeof(FormRecordHeader);
    DAT_011c54cc = ::operator new(DAT_011c54d0);
    pForm = static_cast<FormRecordHeader*>(DAT_011c54cc);
    pForm->flags = GetFlags();
    if (GetFormType() != 1)
        pForm->flags = pForm->flags & 0x30032FE0;
    pForm->form = DAT_01187008[GetFormType()].iFormString;
    pForm->iFormID = GetFormID();
    pForm->length = 0;
    pForm->m_usFormVersion = FUN_00470bb0();
    pForm->m_uiVersionControlInfo = 0;
    pForm->m_usHeaderUnknown = 0;
    Unk_37();
}
}  // namespace fnv_004855a0

void* DAT_011c54cc;
int DAT_011c54d0;

void* __memcpy(void* destination, const void* source, unsigned int count);
void* _Reallocate(void* buffer, unsigned int size);
void _FUN_00485910(int value, int size);
unsigned char _FUN_00401500();

struct FUN_004141e0_class
{
    unsigned int chunk;
    unsigned short length;
    void FUN_004141e0();
};

// @fnv 0x00485990
void AppendChunk(unsigned int chunk, const void* data, unsigned int size)
{
    unsigned int offset;
    {
        unsigned short length = static_cast<unsigned short>(size);
        if (size > 0xffff)
        {
            _FUN_00485910(0x58585858, size);
            length = 0;
        }

        {
            unsigned char* chunkData;
            {
                unsigned char* dataDestination;
                {
                    FUN_004141e0_class* newChunk;

                    offset = DAT_011c54d0;
                    DAT_011c54d0 = DAT_011c54d0 + size + 6;
                    DAT_011c54cc = _Reallocate(DAT_011c54cc, DAT_011c54d0);

                    newChunk =
                        reinterpret_cast<FUN_004141e0_class*>(static_cast<unsigned char*>(DAT_011c54cc) + offset);
                    chunkData = static_cast<unsigned char*>(DAT_011c54cc) + offset;

                    newChunk->chunk = chunk;
                    newChunk->length = length;

                    if (_FUN_00401500())
                        newChunk->FUN_004141e0();

                    __memcpy(chunkData, newChunk, 6);

                    dataDestination = static_cast<unsigned char*>(DAT_011c54cc) + offset + 6;
                    __memcpy(dataDestination, data, size);
                }
            }
        }
    }
}

namespace fnv_00485a70 {
struct FUN_004141e0_class
{
    unsigned char _padding[3];

    void FUN_004141e0();
};

struct CHUNK : public FUN_004141e0_class
{
    unsigned short length;
};

struct FUN_00485a70_class
{
    bool FUN_00485a70(CHUNK* apChunk, unsigned short asExpandSize);
};

bool _FUN_00401500();
void* __cdecl _Reallocate(void* buffer, unsigned int size);

void* DAT_011c54cc;
int DAT_011c54d0;

// @fnv 0x00485a70
bool FUN_00485a70_class::FUN_00485a70(CHUNK* apChunk, unsigned short asExpandSize)
{
    bool bendian = false;
    bendian = _FUN_00401500();

    if (bendian)
        apChunk->FUN_004141e0();

    if ((apChunk->length == 0 && asExpandSize == 0) || (apChunk->length + asExpandSize > 0xffff))
    {
        if (bendian)
            apChunk->FUN_004141e0();
        return false;
    }

    apChunk->length += asExpandSize;

    if (bendian)
        apChunk->FUN_004141e0();

    DAT_011c54d0 += asExpandSize;
    DAT_011c54cc = _Reallocate(DAT_011c54cc, DAT_011c54d0);
    return true;
}
}  // namespace fnv_00485a70

class FUN_00484a10_cls : public TESForm
{
  public:
    void SetFlag40(bool set);
};

// Sets or clears bit 0x40 in the form's flags field and marks the form as modified.
// @fnv 0x00484a10
void FUN_00484a10_cls::SetFlag40(bool set)
{
    set ? (iFormFlags |= 0x40) : (iFormFlags &= 0xffffffbf);
    MarkAsModified(1);
}

struct FUN_0047c050
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    FUN_0047c050();
    ~FUN_0047c050();
    void FUN_0047c070(void* value);
    void FUN_0047c600(FUN_0047c050* other);
};
struct FormCloneOperation
{
    void FUN_004851b0(void* targetForm);
};
// @fnv 0x004851b0
void FormCloneOperation::FUN_004851b0(void* targetForm)
{
    FUN_0047c050 z;
    FUN_0047c050 a;
    z.FUN_0047c070(this);
    a.FUN_0047c070(targetForm);
    z.FUN_0047c600(&a);
}

class TESForm;

struct FUN_00509540_obj
{
    FUN_00509540_obj();
    ~FUN_00509540_obj();
    void FUN_0047c070(void* apOther);
    bool CompareComponents(FUN_00509540_obj* apOther);
    bool FUN_00485270(TESForm* apArg);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
};

// @fnv 0x00485270
bool FUN_00509540_obj::FUN_00485270(TESForm* apArg)
{
    if (apArg == 0)
        return true;
    FUN_00509540_obj p;
    FUN_00509540_obj a;
    p.FUN_0047c070(this);
    a.FUN_0047c070(apArg);
    return p.CompareComponents(&a);
}

struct CompareForm : TESForm
{
    bool FUN_004853e0(BaseFormComponent* rhs);
    int FUN_00474cb0();
    unsigned int FUN_0044ddc0();
};
extern "C" int __cdecl FUN_00404dc0(const char*, const char*);

// @fnv 0x004853e0
bool CompareForm::FUN_004853e0(BaseFormComponent* apOther)
{
    TESForm* otherForm = dynamic_cast<TESForm*>(apOther);
    if (!otherForm)
        return true;

    if (cFormType != otherForm->GetFormType())
        return true;

    if (FUN_00474cb0() || reinterpret_cast<CompareForm*>(otherForm)->FUN_00474cb0())
    {
        if (FUN_00474cb0() != reinterpret_cast<CompareForm*>(otherForm)->FUN_00474cb0())
            return true;
        else
        {
            if (FUN_00404dc0(GetName(), otherForm->GetName()))
                return true;
        }
    }

    unsigned int flagsA = FUN_0044ddc0();
    unsigned int flagsB = reinterpret_cast<CompareForm*>(otherForm)->FUN_0044ddc0();
    flagsA &= 0xffffbff4;
    flagsB &= 0xffffbff4;
    if (flagsA != flagsB)
        return true;
    return false;
}

struct FUN_004867a0_vbase
{
    virtual void v00(void* a);
    virtual void v01(void* a);
    virtual void v02(void* a);
    virtual void v03(void* a);
    virtual void v04(void* a);
    virtual void v05(void* a);
    virtual void v06(void* a);
    virtual void v07(void* a);
    virtual void v08(void* a);
    virtual void v09(void* a);
    virtual void v0A(void* a);
    virtual void v0B(void* a);
    virtual void v0C(void* a);
    virtual void v0D(void* a);
    virtual void v0E(void* a);
    virtual void v0F(void* a);
    virtual void v10(void* a);
    virtual void v11(void* a);
    virtual void v12(void* a);
    virtual void v13(void* a);
    virtual void v14(void* a);
    virtual void v15(void* a);
    virtual void v16(void* a);
    virtual void v17(void* a);
    virtual void v18(void* a);
    virtual void v19(void* a);
    virtual void v1A(void* a);
    virtual void v1B(void* a);
    virtual void v1C(void* a);
    virtual void v1D(void* a);
    virtual void v1E(void* a);
    virtual void v1F(void* a);
    virtual void v20(void* a);
    virtual void v21(void* a);
    virtual void v22(void* a);
    virtual void v23(void* a);
    virtual void v24(void* a);
    virtual void v25(void* a);
    virtual void v26(void* a);
    virtual void v27(void* a);
    virtual void v28(void* a);
    virtual void v29(void* a);
    virtual void v2A(void* a);
    virtual void v2B(void* a);
    virtual void v2C(void* a);
    virtual void v2D(void* a);
    virtual void v2E(void* a);
    virtual void v2F(void* a);
    virtual void v30(void* a);
    virtual void v31(void* a);
    virtual void v32(void* a);
    virtual void v33(void* a);
    virtual void v34(void* a);
    virtual void v35(void* a);
    virtual void v36(void* a);
    virtual void v37(void* a);
    virtual void v38(void* a);
    virtual void v39(void* a);
    virtual void v3A(void* a);
    virtual void v3B(void* a);
    virtual void v3C(void* a);
    virtual void v3D(void* a);
    virtual void v3E(void* a);
    virtual void v3F(void* a);
    virtual void v40(void* a);
    virtual void v41(void* a);
    virtual void v42(void* a);
    virtual void v43(void* a);
    virtual void v44(void* a);
    virtual void v45(void* a);
    virtual void v46(void* a);
    virtual void v47(void* a);
    virtual void v48(void* a);
    virtual void v49(void* a);
    virtual void v4A(void* a);
    virtual void v4B(void* a);
    virtual void v4C(void* a);
    virtual void v4D(void* a);
    virtual void v4E(void* a);
    virtual void v4F(void* a);
};

struct FUN_004867a0_holder
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_004867a0_holder(void* p);
    ~FUN_004867a0_holder();
    void* GetItem();
};

struct FUN_004867a0_cls : FUN_004867a0_vbase
{
    void* GetA();
    void* GetB();
    void* FUN_004867a0(void* unused, void* arg);
};

struct FUN_004867a0_arg
{
    void FUN_00844700(void* a, void* b);
};

void* FUN_00465110(void* p);

// @fnv 0x004867a0
void* FUN_004867a0_cls::FUN_004867a0(void* unused, void* arg)
{
    FUN_004867a0_vbase* obj = (FUN_004867a0_vbase*)FUN_00465110(GetA());
    if (obj != 0)
    {
        FUN_004867a0_holder holder(GetB());
        this->v4D("");
        obj->v42(this);
        if (holder.GetItem() != 0)
        {
            this->v4D(holder.GetItem());
        }
    }
    if (obj != 0 && arg != 0)
    {
        ((FUN_004867a0_arg*)arg)->FUN_00844700(this, obj);
    }
    return obj;
}

struct S4868f0_host
{
    unsigned int FUN_0084e3a0();
    unsigned int FUN_00401280();
    unsigned int FUN_00440e30();
    void FUN_004868f0(unsigned int a);
};

extern "C" int __cdecl FUN_00406f60(unsigned int, const char*, unsigned int, unsigned int, unsigned int);

// @fnv 0x004868f0
void S4868f0_host::FUN_004868f0(unsigned int a)
{
    FUN_00406f60(a, "%s Form '%s' (%08X)", FUN_00440e30(), FUN_00401280(), FUN_0084e3a0());
}

extern char DAT_011841cc;
extern char DAT_011846d4;
extern "C" void* __cdecl FUN_00ec43fb(void* key, int option, const void* source, const void* destination, int flags);

struct ActionObject
{
    void** methods;
};

typedef void(__thiscall* ActionHandler)(ActionObject* self, int target, void* data, unsigned char mode);

struct ActionCaller
{
    bool InvokeAction(int target, void* key, unsigned char mode, int unused, void* data);
};

// @fnv 0x0050f670
bool ActionCaller::InvokeAction(int target, void* key, unsigned char mode, int unused, void* data)
{
    ActionObject* object = (ActionObject*)FUN_00ec43fb(key, 0, &DAT_011841cc, &DAT_011846d4, 0);
    if (object != 0 && target != 0)
    {
        void* savedData = data;
        ((ActionHandler)object->methods[244])(object, target, savedData, mode);
        return true;
    }
    return false;
}

struct FUN_0050f780_Class
{
    void __thiscall ForwardTo008d0600(int arg1, unsigned char arg2);
    void __thiscall FUN_008d0600(int arg1, unsigned char arg2);
};

// @fnv 0x0050f780
void FUN_0050f780_Class::ForwardTo008d0600(int arg1, unsigned char arg2)
{
    FUN_008d0600(arg1, arg2);
}

bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int record, const void* data, unsigned int bytes);
struct Record
{
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    void __thiscall FUN_00483710();
};
struct FUN_005e9620_class
{
    unsigned int unk00;
    unsigned char unk04;
    unsigned char unk05;
    void __thiscall FUN_005e9620(unsigned char value);
};
// @fnv 0x005e9620
void __thiscall FUN_005e9620_class::FUN_005e9620(unsigned char value)
{
    Record data;
    data.field2 = unk05;
    data.field1 = unk04;
    data.field0 = value;
    if (FUN_00401500())
    {
        data.FUN_00483710();
    }
    AppendChunk(0x454b5250, &data, 3);
    if (FUN_00401500())
    {
        data.FUN_00483710();
    }
}

extern const char* g_packageTypeNames[];

struct C67ACD0Package
{
    int unk00;

    int GetType();
    const char* GetTypeName();
};

// @fnv 0x0067acd0
const char* C67ACD0Package::GetTypeName()
{
    return g_packageTypeNames[GetType()];
}

struct CompressionStream
{
    unsigned char* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    unsigned int m_ulTotalInputBytes;
    unsigned char* m_pNextOutputByte;
    unsigned int m_uiAvailableOutputBytes;
    unsigned int m_ulTotalOutputBytes;
    char* msg;
    void* state;
    void*(__cdecl* m_pAllocateCallback)(void*, unsigned int, unsigned int);
    void(__cdecl* m_pFreeCallback)(void*, void*);
    void* opaque;
    int data_type;
    unsigned int m_ulAdler32Checksum;
    unsigned int reserved;
};
extern "C" int __cdecl FUN_00b46360(CompressionStream*, int, const char*, int);
extern "C" int __cdecl deflate(CompressionStream*, int);
extern "C" int __cdecl FUN_00b47370(CompressionStream*);

// Local roles: j = write cursor, e = output buffer, c = record header,
// l = zlib status, k = new record size, ba = compressed buffer,
// b = stored original size, q = input size, cf = zlib stream,
// eb = compression capacity, f = compressed size.
// @fnv 0x00483d70
void CompressSaveLoadRecord()
{
    if (DAT_011c54cc && (unsigned int)DAT_011c54d0 > 24)
    {
        FormRecordHeader* c = (FormRecordHeader*)DAT_011c54cc;
        if (FUN_00401500())
            ConvertFormRecordEndian(c);
        if (c->flags & 0x40000)
        {
            if (FUN_00401500())
                ConvertFormRecordEndian(c);
            return;
        }
        unsigned int q = DAT_011c54d0 - 24;
        unsigned char* j = (unsigned char*)DAT_011c54cc;
        j += 24;
        CompressionStream cf;
        cf.m_pAllocateCallback = 0;
        cf.m_pFreeCallback = 0;
        cf.opaque = 0;
        cf.state = 0;
        int l = FUN_00b46360(&cf, -1, "1.2.1", 56);
        if (l != 0)
        {
            _FNV_Warning("SAVELOAD: Error initializing ZLib stream for deflate.");
            return;
        }
        unsigned int eb = q * 2;
        unsigned char* ba = new unsigned char[eb];
        cf.m_uiAvailableInputBytes = q;
        cf.m_pNextInputByte = j;
        cf.m_uiAvailableOutputBytes = eb;
        cf.m_pNextOutputByte = ba;
        l = deflate(&cf, 4);
        if (l == -2)
        {
            _FNV_Warning("SAVELOAD: Error deflating ZLib stream.");
            delete[] ba;
            return;
        }
        unsigned int f = eb - cf.m_uiAvailableOutputBytes;
        unsigned int k = f + 28;
        unsigned char* e = new unsigned char[k];
        j = e;
        c->flags |= 0x40000;
        c->length = k - 24;
        if (FUN_00401500())
            ConvertFormRecordEndian(c);
        __memcpy(j, c, 24);
        j += 24;
        unsigned int b = q;
        if (FUN_00401500())
            BSEndian((int*)&b, EndianSizeTag<4>());
        __memcpy(j, &b, 4);
        j += 4;
        __memcpy(j, ba, f);
        Deallocate(DAT_011c54cc);
        DAT_011c54cc = e;
        DAT_011c54d0 = k;
        FUN_00b47370(&cf);
        delete[] ba;
    }
}

struct TESFormSortProxy : public TESForm
{
    bool IsLessThan(TESForm* apOther);
};

// Compares this form's remapped form-type rank against another form's and returns true when this rank is lower.
// @fnv 0x00484020
bool TESFormSortProxy::IsLessThan(TESForm* apOther)
{
    unsigned int uiThisRank;
    unsigned int uiOtherRank;
    uiOtherRank = apOther->GetFormType();
    uiThisRank = GetFormType();
    switch (uiOtherRank)
    {
    case 0x67:
        uiOtherRank = 0x137;
        break;
    case 0x6C:
        uiOtherRank = 0x138;
        break;
    case 0x73:
        uiOtherRank = 0x139;
        break;
    case 0x74:
        uiOtherRank = 0x13A;
        break;
    default:
        uiOtherRank *= 10;
        break;
    }
    switch (uiThisRank)
    {
    case 0x67:
        uiThisRank = 0x137;
        break;
    case 0x6C:
        uiThisRank = 0x138;
        break;
    case 0x73:
        uiThisRank = 0x139;
        break;
    case 0x74:
        uiThisRank = 0x13A;
        break;
    default:
        uiThisRank *= 10;
        break;
    }
    if (uiThisRank < uiOtherRank)
        return true;
    return false;
}

struct FormMap
{
    void RemoveKey(unsigned int);
    void FUN_00844700(unsigned int, TESForm*);
};
struct DebugTarget
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void GetDebugInfo(BSStringT<char>*);
};
extern const char DAT_0101c9c8[];
extern unsigned char DAT_011c54b9;
void __cdecl FUN_00461300();
struct FUN_00485c10_shell : public TESForm
{
    bool FUN_004077c0();
    const char* FUN_00440e30();
    void FUN_00485c10(unsigned int id, bool notify);
};
// @fnv 0x00485c10
void FUN_00485c10_shell::FUN_00485c10(unsigned int id, bool notify)
{
    if (id == iFormID)
        return;
    if (!FUN_004077c0())
    {
        DebugTarget* debug = 0;
        if (iFormID != 0)
        {
            reinterpret_cast<FormMap*>(TESForm::ms_pFormIDMap)->RemoveKey(iFormID);
        }
        debug = 0;
        if (debug != 0)
        {
            FUN_00461300();
            BSStringT<char> details;
            debug->GetDebugInfo(&details);
            _FNV_Warning(DAT_0101c9c8, id, FUN_00440e30(), details.String());
            DAT_011c54b9 = 1;
        }
        else if (notify && iFormID != 0)
        {
            g_dataHandler->RemoveIDFromDataHandler(iFormID);
        }
        if (id != 0)
        {
            reinterpret_cast<FormMap*>(TESForm::ms_pFormIDMap)->FUN_00844700(id, this);
        }
    }
    iFormID = id;
}

struct SDEndianTag
{
};

bool __cdecl SDIsBigEndian();
void __cdecl SDSwapBytes(int* apValue, SDEndianTag);
void __cdecl SDSwapBytes(float* apValue, SDEndianTag);
void __cdecl SDSwapBytes(short* apValue, SDEndianTag);
void* __cdecl SDMemCpy(void* apDest, const void* apSrc, unsigned int auiSize);
void __cdecl SDWriteChunk(unsigned int auiChunk, const void* apData, unsigned int auiSize);
void __cdecl SDWarning(const char* apMessage);

struct SDIntComponent
{
    int GetValue();
};


struct SDSaveForm : TESForm
{
    int GetSaveOffset();
    char* GetSaveBuffer();
    bool ReserveSaveData(char* apStart, unsigned short ausSize);
    void FUN_00485e20(const void* apData, unsigned int auiSize);
};

// @fnv 0x00485e20
void SDSaveForm::FUN_00485e20(const void* apData, unsigned int auiSize)
{
    if (auiSize > 0xffff)
    {
        SDWarning("MASTERFILE: Trying to SaveData that's too large.");
        return;
    }

    unsigned short usSize9 = 0;
    int _iOffset = GetSaveOffset();
    SDWriteChunk('ATAD', apData, auiSize);
    char* pStart = GetSaveBuffer() + _iOffset;

    TESUsesForm* pUses7 = dynamic_cast<TESUsesForm*>(static_cast<TESForm*>(this));
    TESValueForm* pValueTmp = dynamic_cast<TESValueForm*>(static_cast<TESForm*>(this));
    TESHealthForm* pHealth5 = dynamic_cast<TESHealthForm*>(static_cast<TESForm*>(this));
    TESWeightForm* pWeight4 = dynamic_cast<TESWeightForm*>(static_cast<TESForm*>(this));
    TESQualityForm* pQuality2 = dynamic_cast<TESQualityForm*>(static_cast<TESForm*>(this));
    TESAttackDamageForm* pDamage2 = dynamic_cast<TESAttackDamageForm*>(static_cast<TESForm*>(this));
    TESAttributes* kPAttributes = dynamic_cast<TESAttributes*>(static_cast<TESForm*>(this));
    BGSClipRoundsForm* pClipRounds3 = dynamic_cast<BGSClipRoundsForm*>(static_cast<TESForm*>(this));

    if (pUses7)
        usSize9 += 1;
    if (pValueTmp)
        usSize9 += 4;
    if (pHealth5)
        usSize9 += 4;
    if (pWeight4)
        usSize9 += 4;
    if (pQuality2)
        usSize9 += 4;
    if (pDamage2)
        usSize9 += 2;
    if (kPAttributes)
        usSize9 += kPAttributes->GetAttributeDataSize();
    if (pClipRounds3)
        usSize9 += 1;

    if (!usSize9)
        return;

    _iOffset = GetSaveOffset();
    if (!ReserveSaveData(pStart, usSize9))
        return;

    char* pWrite2 = GetSaveBuffer() + _iOffset;
    if (pUses7)
    {
        *pWrite2 = pUses7->GetFormUses();
        pWrite2 += 1;
    }
    if (pValueTmp)
    {
        *(int*)pWrite2 = ((SDIntComponent*)pValueTmp)->GetValue();
        if (SDIsBigEndian())
            SDSwapBytes((int*)pWrite2, SDEndianTag());
        pWrite2 += 4;
    }
    if (pHealth5)
    {
        *(int*)pWrite2 = pHealth5->GetBaseHealth();
        if (SDIsBigEndian())
            SDSwapBytes((int*)pWrite2, SDEndianTag());
        pWrite2 += 4;
    }
    if (pWeight4)
    {
        float fWeight = pWeight4->GetWeightForForm();
        if (SDIsBigEndian())
            SDSwapBytes(&fWeight, SDEndianTag());
        SDMemCpy(pWrite2, &fWeight, 4);
        pWrite2 += 4;
    }
    if (pQuality2)
    {
        float fQuality4 = pQuality2->GetFormQuality();
        if (SDIsBigEndian())
            SDSwapBytes(&fQuality4, SDEndianTag());
        SDMemCpy(pWrite2, &fQuality4, 4);
        pWrite2 += 4;
    }
    if (pDamage2)
    {
        *(short*)pWrite2 = pDamage2->GetAttackDamage();
        if (SDIsBigEndian())
            SDSwapBytes((short*)pWrite2, SDEndianTag());
        pWrite2 += 2;
    }
    if (kPAttributes)
        pWrite2 += kPAttributes->Save(pWrite2);
    if (pClipRounds3)
    {
        *pWrite2 = pClipRounds3->GetClipRounds();
        pWrite2 += 1;
    }
}

namespace fnv_00483370 {
extern NiTPointerMap<unsigned int, TESForm*>* DAT_011c54c0;
extern char DAT_0101c748, DAT_0101c6e0, DAT_0101c6a0;
extern int DAT_011c54bc;
extern bool DAT_011c54b8;
struct TypeInfo
{
    unsigned char unk00;
    const char* unk04;
    unsigned int unk08;
};
extern TypeInfo DAT_01187000[];
void __cdecl FUN_0043b2b0(bool);
void __cdecl FNV_Warning(const char*, ...);
void __cdecl FUN_0040fbe0(const char*);
void __cdecl FUN_00483a50();
extern TESDataHandler* DAT_011c3f2c;
TESFile* __fastcall GetField20C(char*);
struct BaseFC
{
    virtual void slot();
    BaseFC();
};
struct FUN_00483370 : BaseFC
{
    unsigned char cFormType;
    unsigned int iFormFlags;
    unsigned int iFormID;
    BSSimpleList<TESFile*> m_kSourceFiles;
    virtual void slot();
    FUN_00483370();
};
// @fnv 0x00483370
FUN_00483370::FUN_00483370()
{
    if (DAT_011c54bc == 0)
        FUN_00483a50();
    DAT_011c54bc++;
    if (!DAT_011c54b8)
    {
        bool bInvalid = false;
        FUN_0043b2b0(true);
        for (unsigned int i = 0; i < 121; ++i)
        {
            DAT_01187000[i].unk08 = DAT_01187000[i].unk04[0] | (DAT_01187000[i].unk04[1] << 8) |
                                    (DAT_01187000[i].unk04[2] << 16) | (DAT_01187000[i].unk04[3] << 24);
            if (DAT_01187000[i].unk00 != i)
            {
                FNV_Warning((const char*)&DAT_0101c748, i);
                bInvalid = true;
            }
            for (unsigned int j = 0; j < 121; ++j)
            {
                if (i != j && DAT_01187000[i].unk08 == DAT_01187000[j].unk08)
                {
                    FNV_Warning((const char*)&DAT_0101c6e0, i, j, DAT_01187000[i].unk04);
                    bInvalid = true;
                }
            }
        }
        FUN_0043b2b0(false);
        if (bInvalid)
            FUN_0040fbe0((const char*)&DAT_0101c6a0);
        DAT_011c54b8 = true;
    }
    cFormType = 0;
    iFormFlags = 8;
    iFormID = 0;
    if (DAT_011c3f2c && !DAT_011c3f2c->FUN_00482f20())
    {
        iFormID = DAT_011c3f2c->GetNextID();
        if (GetField20C((char*)DAT_011c3f2c))
            ((TESForm*)this)->SetFile(GetField20C((char*)DAT_011c3f2c));
        if (iFormID <= 0x7ff)
            ((TESForm*)this)->TESForm::SetRefID(0x800, true);
    }
    if (iFormID)
        DAT_011c54c0->SetAt(iFormID, (TESForm*)this);
}
}  // namespace fnv_00483370

bool __cdecl FUN_00401500();
void __cdecl AppendChunk(void*, void*, void*);
void* __cdecl FormHeap_Allocate(unsigned int size);
void __cdecl FormHeap_Free(void* p);
void* __cdecl FUN_00401460(void* dst, void* src, unsigned int size);
void __cdecl FUN_00401080(void* p, bool value);

struct BoolBox
{
    bool value;
};

struct Slot4
{
    unsigned int value;
    static void* operator new[](unsigned int size)
    {
        return FormHeap_Allocate(size);
    }
    static void operator delete[](void* p)
    {
        FormHeap_Free(p);
    }
};

// When FUN_00401500() is true, copies arg1 into a temporary array, calls FUN_00401080 on each element with false, then appends it.
// @fnv 0x00485750
void __cdecl FUN_00485750(void* apDestination, void* apSource, void* aiCount)
{
    Slot4* p4;
    unsigned int bytes7 = (unsigned int)aiCount * 4;

    if (FUN_00401500())
    {
        unsigned int i;
        p4 = new Slot4[(unsigned int)aiCount];
        FUN_00401460(p4, apSource, bytes7);
        for (i = 0; i < (unsigned int)aiCount; ++i)
        {

            FUN_00401080(&p4[i], BoolBox().value);
        }
        AppendChunk(apDestination, p4, (void*)bytes7);
        delete[] p4;
    }
    else
    {
        AppendChunk(apDestination, apSource, (void*)bytes7);
    }
}

namespace fnv_0069da40 {
void* __cdecl _memcpy(void*, const void*, unsigned int);

template <int N> struct EndianSizeTag
{
};
void __cdecl FUN_00401080(int*, EndianSizeTag<0>);
void __cdecl FUN_00407a90(unsigned short*, EndianSizeTag<0>);

class DA00694f80
{
  public:
    DA00694f80();
    virtual ~DA00694f80();
    void SetSize(unsigned int size, bool b);
    unsigned short& GetAt(int index);
    int unk04;
    int unk08;
    int unk0C;
};

class TESFileRecordLoader
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    DA00694f80* unk24;

    bool LoadRecord(void* src, int unused, TESFile* file);
};

// Copies a 0x24-byte header from src, converts header values if needed, allocates unk24, then reads counts and unsigned-short values from src.
// @fnv 0x0069da40
bool TESFileRecordLoader::LoadRecord(void* src, int unused, TESFile* file)
{
    unsigned int totalCount;
    unsigned int headerSize7 = 0x24;
    unsigned short* dataPtr;
    unsigned int i4;
    unsigned short subCount2;
    unsigned short j;

    _memcpy(this, src, headerSize7);
    if (file->IsEndianConversionRequired())
    {
        FUN_00401080(&unk00, EndianSizeTag<0>());
        FUN_00401080(&unk04, EndianSizeTag<0>());
        FUN_00401080(&unk08, EndianSizeTag<0>());
        FUN_00401080(&unk0C, EndianSizeTag<0>());
        FUN_00401080(&unk10, EndianSizeTag<0>());
        FUN_00401080(&unk14, EndianSizeTag<0>());
        FUN_00401080(&unk18, EndianSizeTag<0>());
        FUN_00401080(&unk1C, EndianSizeTag<0>());
        FUN_00401080(&unk20, EndianSizeTag<0>());
    }
    if (unk00 == 0)
    {
        unk24 = 0;
        return false;
    }
    totalCount = unk00 * unk00;
    unk24 = new DA00694f80[totalCount];
    dataPtr = (unsigned short*)((char*)src + headerSize7);
    for (i4 = 0; i4 < totalCount; ++i4)
    {
        subCount2 = *dataPtr++;
        if (file->IsEndianConversionRequired())
        {
            FUN_00407a90(&subCount2, EndianSizeTag<0>());
        }
        unk24[i4].SetSize(subCount2, true);
        if (subCount2 > 0)
        {
            if (file->IsEndianConversionRequired())
            {
                for (j = 0; j < subCount2; ++j)
                {
                    FUN_00407a90(&dataPtr[j], EndianSizeTag<0>());
                }
            }
            _memcpy(&unk24[i4].GetAt(0), dataPtr, subCount2 * 2);
            dataPtr += subCount2;
        }
    }
    return true;
}
}  // namespace fnv_0069da40

extern unsigned int kGroupFormType;
int __cdecl FindFormEnumIndex(unsigned int);

struct FUN_00484150_shell : public TESForm
{
    bool IsFormTypeBelowThreshold(FormRecordHeader* apGroupForm);
};

// Checks if a group form's form type is below a threshold based on its iFormID, returning true if the type index is less than the threshold.
// @fnv 0x00484150
bool FUN_00484150_shell::IsFormTypeBelowThreshold(FormRecordHeader* apGroupForm)
{
    bool bResultTmp = false;
    unsigned int v1;
    unsigned int v2;
    unsigned int v9;
    unsigned int v8;
    unsigned int v7;

    if (apGroupForm && apGroupForm->form == kGroupFormType)
    {
        switch (apGroupForm->iFormID)
        {
        case 0:
            v2 = FindFormEnumIndex(apGroupForm->flags);
            v1 = GetFormType();
            switch (v2)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v2 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v2 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v2 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v2 = 314;
                break;
            default:
                v2 *= 10;
                break;
            }
            switch (v1)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v1 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v1 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v1 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v1 = 314;
                break;
            default:
                v1 *= 10;
                break;
            }
            if (v1 < v2)
            {
                bResultTmp = true;
            }
            break;
        case 2:
        case 3:
        case 6:
            v9 = GetFormType();
            switch (v9)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v9 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v9 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v9 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v9 = 314;
                break;
            default:
                v9 *= 10;
                break;
            }
            if (v9 < 570)
            {
                bResultTmp = true;
            }
            break;
        case 1:
        case 4:
        case 5:
            v8 = GetFormType();
            switch (v8)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v8 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v8 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v8 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v8 = 314;
                break;
            default:
                v8 *= 10;
                break;
            }
            if (v8 < 650)
            {
                bResultTmp = true;
            }
            break;
        case 7:
            v7 = GetFormType();
            switch (v7)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v7 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v7 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v7 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v7 = 314;
                break;
            default:
                v7 *= 10;
                break;
            }
            if (v7 < 690)
            {
                bResultTmp = true;
            }
            break;
        }
    }
    return bResultTmp;
}

namespace fnv_004861f0 {
extern "C" void* __cdecl FUN_00ec43fb(void* in, int vfDelta, void* srcType, void* targetType, int isReference);
extern char DAT_01183028[]; /* .?AVTESForm@@ */
extern char DAT_01186b88[]; /* .?AVTESUsesForm@@ */
extern char DAT_01186b6c[]; /* .?AVTESValueForm@@ */
extern char DAT_01186c3c[]; /* .?AVTESHealthForm@@ */
extern char DAT_01183274[]; /* .?AVTESWeightForm@@ */
extern char DAT_01186bdc[]; /* .?AVTESQualityForm@@ */
extern char DAT_01186c90[]; /* .?AVTESAttackDamageForm@@ */
extern char DAT_01186c74[]; /* .?AVTESAttributes@@ */
extern char DAT_011868d4[]; /* .?AVBGSClipRoundsForm@@ */

extern "C" void* __cdecl memcpy(void* dest, const void* src, size_t count);
unsigned short __cdecl MinUnsignedShort(unsigned short a, unsigned short b) throw();
struct Swap_004861f0
{
};
void __cdecl FUN_00401080(int* p, Swap_004861f0 b) throw();
void __cdecl FUN_00407a90(short* p, Swap_004861f0 b) throw();


struct Form_004861f0 : TESForm
{
    void FUN_004861f0(TESFile* file, void* dest, unsigned short count);
};

// Reads a chunk from the file into a stack buffer, copies it to dest, and parses form fields into the component objects.
// @fnv 0x004861f0
void Form_004861f0::FUN_004861f0(TESFile* file, void* dest, unsigned short count)
{
    TESAttributes* pAttr9;
    BGSClipRoundsForm* pClip;
    TESUsesForm* pUses;
    TESQualityForm* pQuality;
    unsigned short pos4;
    TESWeightForm* pWeightFormTmp;
    TESAttackDamageForm* pDamage5;
    TESValueForm* pValue;
    unsigned short chunkSize3;
    int val3;
    char* buffer2;
    TESHealthForm* pHealth4;
    short damage9;
    float fval;

    chunkSize3 = file->GetChunkSize();
    pos4 = count;
    buffer2 = (char*)_alloca(chunkSize3);
    file->GetChunkData(buffer2, chunkSize3);
    memcpy(dest, buffer2, MinUnsignedShort(chunkSize3, count));

    pUses = (TESUsesForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186b88, 0);
    pValue = (TESValueForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186b6c, 0);
    pHealth4 = (TESHealthForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c3c, 0);
    pWeightFormTmp = (TESWeightForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01183274, 0);
    pQuality = (TESQualityForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186bdc, 0);
    pDamage5 = (TESAttackDamageForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c90, 0);
    pAttr9 = (TESAttributes*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c74, 0);
    pClip = (BGSClipRoundsForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_011868d4, 0);

    if (pUses && pos4 < chunkSize3)
    {
        pUses->SetFormUses((unsigned char)buffer2[pos4]);
        pos4 += 1;
    }
    if (pValue && pos4 < chunkSize3)
    {
        val3 = *(int*)(buffer2 + pos4);
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            FUN_00401080(&val3, Swap_004861f0());
        pValue->SetFormValue(static_cast<unsigned int>(val3));
    }
    if (pHealth4 && pos4 < chunkSize3)
    {
        val3 = *(int*)(buffer2 + pos4);
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            FUN_00401080(&val3, Swap_004861f0());
        pHealth4->SetFormHealth(val3);
    }
    if (pWeightFormTmp && pos4 < chunkSize3)
    {
        float weight;
        memcpy(&weight, buffer2 + pos4, 4);
        fval = weight;
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            FUN_00401080((int*)&fval, Swap_004861f0());
        pWeightFormTmp->SetFormWeight(fval);
    }
    if (pQuality && pos4 < chunkSize3)
    {
        float quality;
        memcpy(&quality, buffer2 + pos4, 4);
        fval = quality;
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            FUN_00401080((int*)&fval, Swap_004861f0());
        pQuality->SetFormQuality((unsigned char)fval);
    }
    if (pDamage5 && pos4 < chunkSize3)
    {
        damage9 = *(short*)(buffer2 + pos4);
        pos4 += 2;
        if (file->IsEndianConversionRequired())
            FUN_00407a90(&damage9, Swap_004861f0());
        pDamage5->SetAttackDamage(damage9);
    }
    if (pAttr9)
    {
        pos4 += pAttr9->Load(buffer2 + pos4);
    }
    if (pClip && pos4 < chunkSize3)
    {
        pClip->SetFormClipRounds((unsigned char)buffer2[pos4]);
        pos4 += 1;
    }
}
}  // namespace fnv_004861f0

namespace form_load_legacy {

extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
extern char DAT_01183028[];
extern char DAT_011841cc[];

struct TESFormLoadProxy : public ::TESForm
{
    void FUN_00484d00(void*, unsigned int);
    void FUN_00484c50(unsigned int, unsigned int);
};

// When bit 0 of flags is set, reads a value into itempFormFlags and merges masked bits into iFormFlags according to whether pref is nonnull.
// @fnv 0x00484c50
void TESFormLoadProxy::FUN_00484c50(unsigned int flags, unsigned int currentFlags)
{
    ::TESObjectREFR* pref;
    unsigned int itempFormFlags;

    if (flags & 1)
    {
        FUN_00484d00(&itempFormFlags, 4);
        pref = (::TESObjectREFR*)FUN_00ec43fb(this, 0, &DAT_01183028, &DAT_011841cc, 0);
        if (pref)
        {
            iFormFlags = (iFormFlags & 0xff6ed79f) | (itempFormFlags & 0x00912860);
        }
        else
        {
            iFormFlags = (iFormFlags & 0xbffff3df) | (itempFormFlags & 0x40000c20);
        }
    }
}

}
