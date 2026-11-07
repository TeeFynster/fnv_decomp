// fallout/ai/baseprocess.cpp: BaseProcess, SavedProcess, Target8d (46 functions)

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/LowProcess.h"
#include "../../../include/TESPackage.h"
#include "baseprocess_worker.h"
#include "../../../include/BaseFormComponent.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/GO.h"
#include "../../../include/MobileObject.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/TESChildCell.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESSaveLoadGame.h"

static const int kCalculateMoveModeValue1 = 257;

// @fnv 0x008d0540
unsigned int BaseProcess::GetAttackChance(Actor* apActor, float afValue1, float afValue2, float afValue3, bool abFlag1,
                                 bool abFlag2) const
{
    return kCalculateMoveModeValue1;
}

// @fnv 0x008d1050
void BaseProcess::ApplyLoadBuffer(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->ApplyLoadBuffer(buffer);
}

// @fnv 0x008d1000
void BaseProcess::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->FUN_008c6970(buffer);
    if (m_pCachedValues)
        reinterpret_cast<CachedValuesCall*>(m_pCachedValues)->ClearField44();
}

// @fnv 0x008d08b0
void BaseProcess::SetCurrentPackageAndTarget(TESPackage* package, Actor* reference)
{
    TESObjectREFR* target = package->GetResolvedTargetReference((MobileObject*)reference);
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->SetPackageAndTarget(package, target);
}

// @fnv 0x008d0870
void BaseProcess::SetReferenceTarget(Actor* reference)
{
    reinterpret_cast<GuardActorPackageDataCall*>(&m_kProcessData)->SetReferenceTarget((TESObjectREFR*)reference);
    ActorPackageData* data =
        reinterpret_cast<ActorPackageData*>(reinterpret_cast<LowProcess*>(this)->LowProcess::GetCurrentPackageData());
    if (data)
        reinterpret_cast<ActorPackageDataVirtualCall*>(data)->SetReferenceTarget((TESObjectREFR*)reference);
}

// @fnv 0x008d1070
void BaseProcess::Revert(BGSLoadFormBuffer* buffer)
{
    m_fValue1 = -1.0F;
    m_uiStateFlags = 0;
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->FUN_008c6c80(buffer);
    if (m_pCachedValues)
        reinterpret_cast<CachedValuesCall*>(m_pCachedValues)->ClearField44();
}

// @fnv 0x008d0f90
void BaseProcess::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(static_cast<void*>(&m_fValue2), 4u);
    if (buffer->GetVersion() >= 6)
    {
        buffer->ReadTypedData(static_cast<void*>(&m_fValue1), 4u);
        buffer->ReadTypedData(static_cast<void*>(&m_uiStateFlags), 4u);
    }
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->LoadGame(buffer);
}

// @fnv 0x008d0660
void BaseProcess::Copy(BaseProcess* source)
{
    if (!source)
        return;
    void* thisMiddleHigh;
    void* sourceSecond;
    void* sourceMiddleHigh;
    void* thisSecond;
    void* thisThird;
    void* sourceThird;
    void* sourceLow;
    void* thisLow;
    thisThird = __RTDynamicCast(source, 0, &DAT_0118a6b8, &DAT_0118a6d4, 0);
    sourceLow = __RTDynamicCast(source, 0, &DAT_0118a6b8, &DAT_0118c64c, 0);
    thisMiddleHigh = __RTDynamicCast(source, 0, &DAT_0118a6b8, &DAT_011a3668, 0);
    sourceMiddleHigh = __RTDynamicCast(source, 0, &DAT_0118a6b8, &DAT_011a364c, 0);
    thisSecond = __RTDynamicCast(this, 0, &DAT_0118a6b8, &DAT_0118a6d4, 0);
    sourceSecond = __RTDynamicCast(this, 0, &DAT_0118a6b8, &DAT_0118c64c, 0);
    sourceThird = __RTDynamicCast(this, 0, &DAT_0118a6b8, &DAT_011a3668, 0);
    thisLow = __RTDynamicCast(this, 0, &DAT_0118a6b8, &DAT_011a364c, 0);
    if (thisThird)
    {
        if (reinterpret_cast<BaseProcess*>(thisThird)->GetProcessBlendAmount() > 0.0)
        {
            reinterpret_cast<BaseProcess*>(thisThird)->StopRunOncePackage();
            reinterpret_cast<BaseProcess*>(thisThird)->SetTarget(0);
        }
    }
    if (thisSecond)
    {
        if (reinterpret_cast<BaseProcess*>(thisSecond)->GetProcessBlendAmount() > 0.0)
        {
            reinterpret_cast<BaseProcess*>(thisSecond)->StopRunOncePackage();
            reinterpret_cast<BaseProcess*>(thisSecond)->SetTarget(0);
        }
    }
    if (thisSecond && thisThird)
        reinterpret_cast<MiddleHighProcessCall*>(thisSecond)
            ->CopyProcessDataFrom(reinterpret_cast<MiddleHighProcessCall*>(thisThird));
    if (sourceSecond && sourceLow)
        reinterpret_cast<CopyCall00914c60*>(sourceSecond)->MiddleHighProcess_MiddleHighCopy(reinterpret_cast<CopyCall00914c60*>(sourceLow));
    if (sourceThird && thisMiddleHigh)
        reinterpret_cast<CachedValuesCopyCall*>(sourceThird)
            ->Copy(reinterpret_cast<CachedValuesCopyCall*>(thisMiddleHigh));
    if (thisLow && sourceMiddleHigh)
        reinterpret_cast<LowProcess*>(thisLow)->HandlePackageChange(
            reinterpret_cast<LowProcess*>(sourceMiddleHigh));
    if (m_pCachedValues && source->m_pCachedValues)
        reinterpret_cast<LowProcessCachedCopyCall*>(m_pCachedValues)
            ->HandlePackageChange(reinterpret_cast<LowProcessCachedCopyCall*>(source->m_pCachedValues));
}

struct FUN_0049bb50_shell : public ActorPackageContext
{
    void AddToOffset(int);
};

// @fnv 0x0049bb50
void FUN_0049bb50_shell::AddToOffset(int aiOffset)
{
    *(int*)((char*)this + 0xc) += aiOffset;
}

struct Dummy_00527770
{
    void NiTMap_unsigned_int_TESObjectREFR_NiTMap(int arg);
};

// Calls FUN_00527770 with 0x25, sets the first pointer to "@kR", and zeroes the ints at offsets 16 and 20 before returning pThis.
// @fnv 0x00526b00
// src: EXE 0x00526b00
void* __fastcall LoadedReferenceMap_LoadedReferenceMap(void* pThis)
{
    ((Dummy_00527770*)pThis)->NiTMap_unsigned_int_TESObjectREFR_NiTMap(0x25);
    *(const char**)pThis = "@kR";
    *((int*)pThis + 4) = 0;
    *((int*)pThis + 5) = 0;
    return pThis;
}


// @fnv 0x008d03e0
int BaseProcess::GetCurrentProcedure() const
{
    return const_cast<ActorPackageContext&>(m_kProcessData).GetProcedureIndex();
}


void __fastcall DeleteData(void* pThis);

// @fnv 0x008d0640
BaseProcess::~BaseProcess()
{
    DeleteData(reinterpret_cast<char*>(this) + 4);
}

// @fnv 0x008d1030
void __fastcall ClearField44(int param_1)
{
    *reinterpret_cast<int*>(param_1 + 0x44) = 0;
}

struct FUN_00524b60_shell
{
    unsigned char __thiscall GetByteAt102();
};

// @fnv 0x00524b60
unsigned char __thiscall FUN_00524b60_shell::GetByteAt102()
{
    return *(unsigned char*)((char*)this + 0x102);
}

extern float DAT_01085df0;


// @fnv 0x008d02d0
double BaseProcess::GetActorValueAtIndex(Actor* apActor, DetectionListType abWhichList)
{
    (void)apActor;
    (void)abWhichList;
    return -DAT_01085df0;
}

struct TESIdleForm;


// @fnv 0x008d02f0
bool BaseProcess::StartIdleAnimation(Actor* apMobile, TESIdleForm* apIdle, ANIM_IDLE_PLAY_TYPE aeType,
                                                 bool abForce3d, bool abChooseNewOne, bool abTestConditions)
{
    return false;
}


// @fnv 0x008d0350
void BaseProcess::AddDetectionEvent(Actor*, NiPoint3, SOUND_LEVEL, int, TESObjectREFR*)
{}

struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct ActorValueOwner;
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
struct BSFile;
struct BSMultiBound;
struct BSMultiBoundRoom;
class BSSoundHandle;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct ChangeData;
struct ChangesMap;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct CellReferenceChangeData;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExteriorCellNewReferencesMap;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct CellChangesMap;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InteriorCellNewReferencesMap;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct FormRecordMetadata;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct WorldReferenceObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
class NiMatrix3;
struct NiNode;
struct NiPointLight;
struct NiTexture;
struct NumericIDBufferMap;
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
struct SaveGameRecord;
struct FormIDEntry;
struct SaveGameFile;
struct EmptyClass;
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
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct _FILETIME;
struct _SYSTEMTIME;
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
struct blob8
{
    char b[8];
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
typedef char _sizecheck_TESSaveLoadGame[sizeof(TESSaveLoadGame) == 456 ? 1 : -1];
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];

// @fnv 0x008d0370
bool BaseProcess::SetCurrentAmmunition(InventoryStackRecord* apForm)
{
    return 0;
}


// @fnv 0x008d0390
float BaseProcess::GetDistanceBetweenActors(Actor* apActor, Actor* apTarget)
{
    return 0.0f;
}


// @fnv 0x008d05f0
float BaseProcess::GetPermanentActorValueFloat(ActorValue::Index aiWhich)
{
    return 0.0f;
}


// @fnv 0x008d08f0
NiPoint3* BaseProcess::GetLastKnownPosition() const
{
    return const_cast<NiPoint3*>(&NiPoint3::ZERO);
}

// @fnv 0x008d10c0
float BaseProcess::UpdateProcessTiming() const
{
    return 20.0f;
}


// @fnv 0x00acb7e0
int BaseProcess::GetKnockedState()
{
    return -1;
}

// @fnv 0x008cc730
void BaseProcess::Move(MobileObject* apRef, NiPoint3 akSource)
{}

// @fnv 0x008d02a0
NiPoint3 BaseProcess::GetActorWorldPosition(Actor* apActor)
{
    return NiPoint3::ZERO;
}


// @fnv 0x008d0310
NiPoint3 BaseProcess::GetActorNodePosition(Actor* apActor, DetectionListType abWhichList)
{
    return NiPoint3::ZERO;
}


struct DetectionViewData;
struct FUN_008d0340_s
{
    DetectionViewData* BaseProcess_InsertIntoDetectionList(Actor*, int, bool, int, int, bool, bool);
};
// @fnv 0x008d0340
// src: COMMUNITY 0x008d0340
DetectionViewData* FUN_008d0340_s::BaseProcess_InsertIntoDetectionList(Actor* apactor, int aedetect, bool abLineSight, int aiLevel,
                                                int abWhichList, bool ab360view, bool abcombat)
{
    return 0;
}

// @fnv 0x008d0380
void BaseProcess::ProcessEquipmentRequest(Actor* apActor, bool abEquip, TESBoundObject* apObject, int aiNumber,
                                  ExtraDataList* apExtra, bool abNow, bool abForceEquip, bool abFromMenus,
                                  bool abForceUnequip, bool abEquipCalling, bool abPlayPickUpSounds)
{}

// The shared AssignCharacterController takes a reference, but this entry destroys
// a value parameter. Keep only this unsupported declaration until that signature is shared.
struct FUN_008d04d0_s
{
    void BaseProcess_SetCharacterController(GO apCon);
};

// @fnv 0x008d04d0
// src: COMMUNITY 0x008d04d0
void FUN_008d04d0_s::BaseProcess_SetCharacterController(GO apCon)
{}

// @fnv 0x008d04f0
void BaseProcess::ProcessDialogueTopic(Actor* apActor, TESTopic* aptopic, bool abForceSub, bool abStop, bool abQue,
                                  bool abSayCallBack)
{}

// @fnv 0x008d0500
void BaseProcess::UpdateActorStateWithOptions(Actor* apActor, bool abNewpackage, bool abInterateIndex, unsigned int emovemode,
                                  bool abSecondLoc)
{}

struct ActorCombatGroup;
// @fnv 0x008d0530
bool BaseProcess::ShouldAttackTarget(Actor* apActor, Actor* apTarget, bool abCheckForAmbush, bool absendalarm,
                                  ActorCombatGroup* apGroup, bool abfleeing, bool abForceFlee, bool abAggressor, bool acTeam,
                                  bool bforcecombat, bool abForceAttack, bool abCastSpell, TESPackage* apPackage)
{
    return false;
}

// @fnv 0x008d0570
int BaseProcess::GetActorValueI(TESActorBase* apActorBase, ActorValue::Index aiWhich, Actor* apActor)
{
    return -1;
}

// @fnv 0x008d0580
float BaseProcess::GetActorValueF(TESActorBase* apActorBase, ActorValue::Index aiWhich, Actor* apActor)
{
    return 0.0f;
}

// Constructs and returns a default-constructed instance of the local struct type, ignoring the passed type argument.
// @fnv 0x008d0590
BSSoundHandle BaseProcess::GetActorSoundHandle(unsigned int aeType)
{
    return BSSoundHandle();
}

// @fnv 0x008d05c0
void BaseProcess::SetActorSoundHandle(unsigned int a, BSSoundHandle d)
{}

// @fnv 0x008d0600
void BaseProcess::SetTargetReferenceByIndex(HeadTrackType a, TESObjectREFR* b)
{}

struct FUN_008c64d0_target
{
    void FUN_008c64d0(unsigned int, unsigned int);
};

// Forwards the new and old flag values to the object at offset 4 of this shell.
// @fnv 0x008d0e60
void BaseProcess::InitLoadGameTES(unsigned int aiFlags, unsigned int aiOldFlags, MobileObject* pmob)
{
    ((FUN_008c64d0_target*)((char*)this + 4))->FUN_008c64d0(aiFlags, aiOldFlags);
}

struct FUN_008c65d0_target
{
    void SavePackage(BGSSaveFormBuffer*);
};
// @fnv 0x008d0f30
void BaseProcess::SaveGameBGS(BGSSaveGameBuffer* apBuffer)
{
    reinterpret_cast<BGSSaveFormBuffer*>(apBuffer)->SaveData((char*)this + 0x1c, 4, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(apBuffer)->SaveData((char*)this + 0x20, 4, 0);
    reinterpret_cast<BGSSaveFormBuffer*>(apBuffer)->SaveData((char*)this + 0x24, 4, 0);
    ((FUN_008c65d0_target*)((char*)this + 4))->SavePackage(reinterpret_cast<BGSSaveFormBuffer*>(apBuffer));
}

struct FUN_008c65a0_shell
{
    void FUN_008c65a0(int);
};
// @fnv 0x008d0f10
void BaseProcess::RevertTES(unsigned int aiFlags, MobileObject* pmob)
{
    ((FUN_008c65a0_shell*)&m_kProcessData)->FUN_008c65a0(aiFlags);
}

namespace fnv_008d0900 {
struct FormIDEntry
{
    unsigned int iFormID;
    unsigned char pad;
    unsigned char iFlags[4];
};



typedef TESSaveLoadGame SaveManager;

extern SaveManager* DAT_011de45c;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

extern GlobalObject_0045cf30 g_011de4e8;

// Exe 0x008d0900: unit-local BaseprocessInterfaceView view used by this matched implementation.
struct BaseprocessInterfaceView
{
    static void __cdecl PrintDebugMessage(const char* format, ...);
};

struct FUN_008c61a0_Class
{
    unsigned short ComputeTotal(unsigned int aiFlags);
};

TESForm* _ref_004839c0(unsigned int iFormID);


// Accumulates a save-size value from the save manager, a virtual call on this+4, and a constant, logging the delta when the debug flag is set.
// @fnv 0x008d0900
}  // namespace fnv_008d0900

unsigned short BaseProcess::GetSaveSize(unsigned int aiFlags, MobileObject* pmob)
{
    unsigned short pform;
    unsigned short pheader;
    fnv_008d0900::FormIDEntry* isize;
    TESForm* itempStartSize;

    pform = 0;
    pheader = pform;

    if (fnv_008d0900::DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        pform += 4;
        pform += 2;
    }

    pform += reinterpret_cast<fnv_008d0900::FUN_008c61a0_Class*>(reinterpret_cast<unsigned char*>(this) + 4)->ComputeTotal(aiFlags);
    pform += 4;

    if (*fnv_008d0900::g_011de4e8.Bool())
    {
        isize = static_cast<fnv_008d0900::FormIDEntry*>(fnv_008d0900::DAT_011de45c->GetHitSound());
        if (isize)
        {
            itempStartSize = fnv_008d0900::_ref_004839c0(isize->iFormID);
            fnv_008d0900::BaseprocessInterfaceView::PrintDebugMessage(
                "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                static_cast<unsigned int>(pform) - pheader, isize->iFormID, itempStartSize->GetName(),
                *reinterpret_cast<unsigned int*>(isize->iFlags), 0xE8,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BaseProcess.cpp");
        }
        else
        {
            fnv_008d0900::BaseprocessInterfaceView::PrintDebugMessage("GetSaveSize(): %-5i ending at line %i in file %s",
                                         static_cast<unsigned int>(pform) - pheader, 0xE8,
                                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BaseProcess.cpp");
        }
    }

    return pform;
}




// Calls the virtual function vfn_144 with param_3.
// @fnv 0x008d04a0
void BaseProcess::SetProcessTarget(MobileObject*, int aiValue)
{
    SetPackageExecutionState(aiValue);
}

extern char DAT_01184920[];
extern char DAT_011846d4[];
extern void* DAT_011dea3c;

void* __cdecl FUN_00ec43fb(void*, int, char*, char*, int);

struct FUN_008a6ce0_shell
{
    void Actor_EvaluatePackage(int, int);
};


// @fnv 0x008d0e80
void BaseProcess::FinishLoadGameTES(unsigned int aiUnused1, unsigned int aiUnused2, MobileObject* p3)
{
    void* t = FUN_00ec43fb(p3, 0, DAT_01184920, DAT_011846d4, 0);
    if (t != 0 && t != DAT_011dea3c && this->GetCurrentPackage() == 0 && static_cast<const BaseProcess*>(this)->GetPackageInfoValue() == -1)
    {
        this->SetAnimationState(0u);
        ((FUN_008a6ce0_shell*)t)->Actor_EvaluatePackage(1, 1);
    }
}

struct SaveHeaderView
{
    unsigned int id;
    unsigned char type;
    unsigned char flags;
};
struct TESSaveLoadGameHelper
{
    unsigned int GetTimeStamp();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(void*, int);
    SaveHeaderView* GetHitSound();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
extern const char DAT_010865e0[];
extern const char DAT_010153a0[];
extern const char DAT_0101536c[];
extern const char DAT_01015318[];
void __cdecl ProgramFlow(const char*, ...);
void __cdecl FNV_Warning(const char*, ...);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
struct ProcessData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void FUN_008c6250(unsigned int);
};
struct SavedProcess
{
    int unk00;
    ProcessData data;
    unsigned int unk1c;
    void BaseProcess_SaveGameTES(unsigned int, unsigned int);
};
struct FormView
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
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* Describe();
};
// @fnv 0x008d0a10
// src: COMMUNITY 0x008d0a10
void SavedProcess::BaseProcess_SaveGameTES(unsigned int flags, unsigned int unused)
{
    unsigned short length = 0;
    unsigned int* begin = 0;
    unsigned int initial = ((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
    if (*g_011de4e8.Bool())
        initial = ((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
    if (((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int tag = 0x424c4f4b;
        ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&tag, 4);
        begin = (unsigned int*)((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
        ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&length, 2);
    }
    data.FUN_008c6250(flags);
    ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&unk1c, 4);
    if (*g_011de4e8.Bool())
    {
        unsigned int header = ((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
        SaveHeaderView* end = ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->GetHitSound();
        if (end)
        {
            TESForm* form = TESForm_GetFormByNumericID(end->id);
            ProgramFlow(DAT_010153a0, header - initial, end->id, ((FormView*)form)->Describe(),
                         *(unsigned int*)&end->flags, 0xf9, DAT_010865e0);
        }
        else
            ProgramFlow(DAT_0101536c, header - initial, 0xf9, DAT_010865e0);
    }
    if (((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uiTimestamp = ((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
        unsigned int finalPosition = (unsigned int)begin;
        if (uiTimestamp > finalPosition + 65535)
            FNV_Warning(DAT_01015318, DAT_010865e0, 0xf9);
        *(unsigned short*)begin = (unsigned short)(uiTimestamp - finalPosition);
    }
}

namespace fnv_008d0bc0 {
extern "C" char DAT_011de45c;
extern "C" char DAT_010865e0;
extern "C" char DAT_01015718;
extern "C" char DAT_010156a8;
extern "C" char DAT_01015588;
extern "C" char DAT_01015500;
extern "C" char DAT_010154a0;
extern "C" char DAT_01015440;
struct Record8d
{
    unsigned id;
    char data[6];
};
struct Reader8d
{
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_LoadGameDataOLD(void*, unsigned);
    Record8d* BGSProjectile_GetExplosion();
    unsigned char FUN_008df040();
    unsigned FUN_00825c00();
};
struct Object8d
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* name();
};
Object8d* __cdecl TESForm_GetFormByNumericID(unsigned);
void __cdecl Warning_005b5e40(const char*, ...);
struct Base8d
{
    void FUN_008c6320(void*, void*);
};
struct Target8d
{
    char pad[4];
    Base8d base;
    char rest[23];
    unsigned field;
    void LoadAndValidate(void*, void*, void*);
};
// Reads a tag and count from the reader, calls base.FUN_008c6320, reads field, then logs size mismatches between the recorded and actual block length.
// @fnv 0x008d0bc0
void Target8d::LoadAndValidate(void* arg1, void* arg2, void* arg3)
{
    unsigned short count = 0;
    unsigned start = 0;
    if ((*(Reader8d**)&DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned tag;
        (*(Reader8d**)&DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&tag, 4);
        if (tag != 0x424c4f4b)
        {
            Record8d* record = (*(Reader8d**)&DAT_011de45c)->BGSProjectile_GetExplosion();
            if (record)
            {
                Object8d* object = TESForm_GetFormByNumericID(record->id);
                Warning_005b5e40(&DAT_01015718, &DAT_010865e0, 0x104, record->id, object->name(),
                             *(unsigned char*)((char*)record + 9), *(unsigned*)((char*)record + 5));
            }
            else
            {
                Warning_005b5e40(&DAT_010156a8, &DAT_010865e0, 0x104, (*(Reader8d**)&DAT_011de45c)->FUN_008df040());
            }
        }
        start = (*(Reader8d**)&DAT_011de45c)->FUN_00825c00();
        (*(Reader8d**)&DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&count, 2);
    }
    base.FUN_008c6320(arg1, arg2);
    (*(Reader8d**)&DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&field, 4);
    if ((*(Reader8d**)&DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned end = (*(Reader8d**)&DAT_011de45c)->FUN_00825c00();
        Record8d* record = (*(Reader8d**)&DAT_011de45c)->BGSProjectile_GetExplosion();
        if (record)
        {
            Object8d* object = TESForm_GetFormByNumericID(record->id);
            if (end > start + count)
            {
                Warning_005b5e40(&DAT_01015588, end - (start + count), &DAT_010865e0, 0x109, record->id, object->name(),
                             *(unsigned char*)((char*)record + 9), *(unsigned*)((char*)record + 5));
            }
            else if (end < start + count)
            {
                Warning_005b5e40(&DAT_01015500, start + count - end, &DAT_010865e0, 0x109, record->id, object->name(),
                             *(unsigned char*)((char*)record + 9), *(unsigned*)((char*)record + 5));
            }
        }
        else
        {
            if (end > start + count)
            {
                Warning_005b5e40(&DAT_010154a0, end - (start + count), &DAT_010865e0, 0x109,
                             (*(Reader8d**)&DAT_011de45c)->FUN_008df040());
            }
            else if (end < start + count)
            {
                Warning_005b5e40(&DAT_01015440, start + count - end, &DAT_010865e0, 0x109,
                             (*(Reader8d**)&DAT_011de45c)->FUN_008df040());
            }
        }
    }
}
}  // namespace fnv_008d0bc0

