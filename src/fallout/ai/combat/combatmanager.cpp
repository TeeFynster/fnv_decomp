// fallout/ai/combat/combatmanager.cpp: CombatManager and combat helpers (37 functions)

#include "../../../../include/Actor.h"
#include "../../../../include/ActorCombatGroup.h"
#include "../../../../include/AnimIdle.h"
#include "../../../../include/AutoMemContext.h"
#include "../../../../include/AutoMemHelper.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/BSShaderManager.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/CombatController.h"
#include "../../../../include/CombatTarget.h"
#include "../../../../include/CombatThreatMap.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiAlphaProperty.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiTMap.h"
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/PathingSolution.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/SettingT_GameSettingCollection_.h"
#include "../../../../include/SpectatorPackage.h"
#include "../../../../include/TES.h"
#include "../../../../include/TESPackage.h"
#include "../../../../include/TESRaceForm.h"
#include "../../../../include/TESWorldSpace.h"
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/TopicInfoArray.h"
#include "../../../../include/int64.h"
#include "../../../../include/MobileObjectProcessArray.h"
#include "../../../../include/CombatManager.h"

template <>
bool NiTMapBase<DFALL<NiTMapItem<Actor*, unsigned __int64> >, Actor*, unsigned __int64>::GetAt(
    Actor* key, unsigned __int64& outValue) const;

// These entry points are not yet declared by CombatController.h.
// Call them with their original thiscall ABI without a replacement class.
extern "C" void* CombatController_GetDetectionModifier();
extern "C" void CombatController_ResetModifierIfActive();

// These entry points are not yet declared with these signatures in the shared headers.
// Their bindings are the original Actor/ActorCombatGroup methods, with this passed in ecx.
extern "C" void Actor_FUN_009670f0();             // 0x009670f0
extern "C" void ActorCombatGroup_RebuildDebugVisuals();    // 0x009878b0
extern "C" void ActorCombatGroup_FUN_0097ef30();             // 0x0097ef30
extern "C" void ActorCombatGroup_FUN_0098a2e0();              // 0x0098a2e0
int __fastcall ActorCombatGroup_HasPlayerThreat(ActorCombatGroup*); // 0x009931a0
extern "C" void ActorCombatGroup_FUN_00989880();        // 0x00989880
extern "C" void ActorCombatGroup_GetTimestampResult();    // 0x00989090 (explicit result buffer)
extern "C" void ActorCombatGroup_GetModifierSum();         // 0x0098cb30
extern "C" void ActorCombatGroup_AddActor();               // 0x009867d0
extern "C" void ActorCombatGroup_ClearMembers();           // 0x00986bd0
extern "C" void ActorCombatGroup_MergeActors();            // 0x00987530
extern "C" void ActorCombatGroup_AddTarget();              // 0x00986410 (bool result)

extern "C" void Actor_FUN_008b0970();                    // 0x008b0970
extern "C" void Actor_FUN_00566950();                    // 0x00566950
extern "C" void Actor_FUN_00474cb0();                    // 0x00474cb0
extern "C" void ActorCombatGroup_RemoveActor();           // 0x009869a0 (Actor argument)
extern "C" void ActorCombatGroup_GetIndex();              // 0x00559450
extern "C" void ActorCombatGroup_FUN_00986c40();          // 0x00986c40
extern "C" void ActorCombatGroup_FUN_00987820();          // 0x00987820
extern "C" void ActorCombatGroup_LoadGame();              // 0x0098e3d0
extern "C" void ActorCombatGroup_SaveGame();              // 0x0098de90

extern "C" void ActorCombatGroup_SetQuantity();           // 0x00537e90

class CombatCoverMap;


extern PlayerCharacter* g_thePlayer;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting413;

typedef ActorCombatGroup*(__thiscall* ActorGetCombatGroupProc)(Actor* actor);

// @fnv 0x00993790
void CombatManager::ApplyLoadBuffer(BGSLoadGameBuffer* buffer)
{
    for (unsigned int i = 0; i < m_kCombatGroups.GetSize(); i++)
    {
        ActorCombatGroup* group = m_kCombatGroups.GetAt(i);
        if (group)
            group->RemoveActorsNotInGroup(buffer);
    }
    m_pThreatMap->ProcessAllProjectiles(buffer);
}

void* __cdecl operator new(unsigned int);

extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;

void __cdecl InitCombatActions();
void __cdecl InitCombatGoalTable();
void __cdecl CombatGroupStrategy_InitGroupStrategies();
void __cdecl NegateCharacterControllerValue();
void __cdecl EnsureGlobalAllocated();

// @fnv 0x00990f20
// src: COMMUNITY 0x00990f20
void __cdecl CombatManager_Create()
{
    if (BGSSaveLoadGlobalDataWorldspacePtr)
        return;

    AutoMemContext context(static_cast<MEM_CONTEXT>(0x2b), true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\CombatManager.cpp", 0x43);
    BGSSaveLoadGlobalDataWorldspacePtr = reinterpret_cast<TESWorldSpace*>(new CombatThreatMap());
    InitCombatActions();
    InitCombatGoalTable();
    CombatGroupStrategy_InitGroupStrategies();
    NegateCharacterControllerValue();
    EnsureGlobalAllocated();
}

struct FUN_00991dc0_shell : public CombatManager
{
    void CombatManager_UpdateCombatants();
};

typedef void(__thiscall* ActorVFn)(Actor*);
// Iterates every group, calls a virtual function on each member actor, and re-reads the member count when it changes.
// @fnv 0x00991dc0
// src: XBOX_PDB 0x00991dc0
void FUN_00991dc0_shell::CombatManager_UpdateCombatants()
{
    for (unsigned int i = 0; i < ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetSize(); i++)
    {
        ActorCombatGroup* pgroup = ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetAt(i);
        if (pgroup)
        {
            unsigned int imemberCount = pgroup->GetCount();
            for (unsigned int j = 0; j < imemberCount; j++)
            {
                Actor* pactor = pgroup->GetIntAt(static_cast<int>(j));
                (*(ActorVFn**)pactor)[0x430 / 4](pactor);
                unsigned int inewMemberCount = pgroup->GetCount();
                if (inewMemberCount != imemberCount)
                {
                    imemberCount = inewMemberCount;
                    j--;
                }
            }
        }
    }
}

class ActiveEffect;
class BGSIdleCollection;
class CombatAction;
class CombatGoal;
class CombatProcedure;
class IDebugText;
class InventoryStackRecord;
class PackageTargetRecord;
class Projectile;
class Script;
class TESBoundObject;
class TESCombatStyle;
class PerkEntryConditionSet;
class TESEscortPackageData;
class TESFile;
class TESIdleForm;
class TESObjectWEAP;
class TESPackageData;
class TESPatrolPackageData;
class TESTopic;
class TESUseWeaponPackageData;
namespace fnv_00991770 {
struct CombatPlan;
struct CombatBehavior;
struct CombatState;
struct LocationDescriptor;
struct DurationData;
struct blob12
{
    char b[12];
};
struct FUN_00991770_shell : public CombatManager
{
    void UpdateDetectionVisuals();
};


struct Flt
{
    operator unsigned int() const;
};

struct Calendar
{
    unsigned int GetDaysPassed();
};

struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};

// ProcessListsView: unit-local view (declares only what 0x00991770 calls), not the shared ProcessLists; renamed so no local type keeps the shared name
struct ProcessListsView
{
    unsigned char* GetLifeStateControlFlag();
};

struct DetectionVisualPosition
{
    float x, y, z;
};

struct TeleportableReference
{
    NiPoint3 const& GetPosition();
};


struct DetectionEvent
{
    int soundLevel;
    NiPoint3 pos;
};

NiAVObject* __fastcall TESObjectCELL_GetMarkerNode(TESObjectCELL*);
NiAVObject* __cdecl BSTestObjects_CreateSphere(float, int, int, NiColorA const&);
NiAVObject* __cdecl BSTestObjects_Create3DArrow(NiPoint3 const&, NiPoint3 const&, float, float, NiColorA const&, NiColorA const&);
void __cdecl AttachLightingPropertyRecursive(unsigned int);

extern float const g_011d86e0_arg1;
extern float _DAT_010162c0;
extern float DAT_0108aff0;
extern float DAT_0108da38;
extern TeleportableReference DAT_011e0e80;
extern ProcessListsView g_011f197c;

// @fnv 0x00991770
void FUN_00991770_shell::UpdateDetectionVisuals()
{
    (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x14))->TESForm::ClearData();
    (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x18))->TESForm::ClearData();
    (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x1c))->TESForm::ClearData();
    for (unsigned int i = 0; i < reinterpret_cast<NiTPrimitiveArray<ActorCombatGroup*>*>(this)->GetSize(); ++i)
    {
        ActorCombatGroup* pgroup = reinterpret_cast<NiTPrimitiveArray<ActorCombatGroup*>*>(this)->GetAt(i);
        if (pgroup)
        {
            reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, int)>(&ActorCombatGroup_RebuildDebugVisuals)(pgroup, 0);
            unsigned int imemberCount = pgroup->GetCount();
            for (unsigned int j = 0; j < imemberCount; ++j)
            {
                Actor* pactor = pgroup->GetIntAt(static_cast<int>(j));
                if (pactor)
                {
                    TESForm* pcombatController = reinterpret_cast<TESForm*>(pactor->GetCombatController());
                    if (pcombatController)
                    {
                        pcombatController->TESForm::Revert(static_cast<unsigned int>(0));
                    }
                }
            }
        }
    }
    if (*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38) &&
        reinterpret_cast<Calendar*>(
            static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
            ->GetDaysPassed())
    {
        reinterpret_cast<NiNode*>(reinterpret_cast<Calendar*>(static_cast<unsigned int>(*reinterpret_cast<Flt*>(
                                                                       reinterpret_cast<char*>(this) + 0x38)))
                                           ->GetDaysPassed())
            ->RemoveObject(reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))));
    }
    *reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x38) = 0;
    if (!reinterpret_cast<TESObjectREFR*>(g_thePlayer)->GetParentCell() ||
        !TESObjectCELL_GetMarkerNode(reinterpret_cast<TESObjectREFR*>(g_thePlayer)->GetParentCell()))
    {
        return;
    }
    if (*g_011f197c.GetLifeStateControlFlag())
    {
        if (!*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))
        {
            *reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x38) = new NiNode(0);
        }
        unsigned int iHighActorCount =
            reinterpret_cast<TopicInfoArray*>(const_cast<NiPoint3*>(&DAT_011e0e80.GetPosition()))->ProcessArray_GetProcessLevelTail(0);
        for (unsigned int i = 0; i < iHighActorCount + 1; ++i)
        {
            MobileObject* pMobileObject =
                (i == iHighActorCount)
                    ? reinterpret_cast<MobileObject*>(g_thePlayer)
                    : reinterpret_cast<const MobileObjectProcessArray*>(&DAT_011e0e80.GetPosition())->GetItem(i);
            if (pMobileObject && reinterpret_cast<TESForm*>(pMobileObject)->IsActor())
            {
                Actor* pactor = reinterpret_cast<Actor*>(pMobileObject);
                DetectionEvent* pdetectionEvent =
                    reinterpret_cast<DetectionEvent*>(reinterpret_cast<BaseProcess*>(reinterpret_cast<TES*>(pactor)->GetLogDate())
                        ->FindDetectionEventForActor(pactor));
                if (pdetectionEvent)
                {
                    NiColorA arrowColor(0.0f, 0.25f, 0.25f, 0.5f);
                    NiColorA sphereColor(0.0f, g_011d86e0_arg1, g_011d86e0_arg1, 0.5f);
                    NiColorA color(1.0f, DAT_0108da38, DAT_0108aff0, 0.5f);
                    float fradius = pdetectionEvent->soundLevel + 32.0;
                    NiAVObject* psphere = BSTestObjects_CreateSphere(fradius, 10, 10, sphereColor);
                    psphere->NiAVObject_SetTranslate(pdetectionEvent->pos);
                    reinterpret_cast<NiNode*>(
                        static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
                        ->AttachChildInAvailableSlot(psphere, true);
                    DetectionVisualPosition actorPos = *reinterpret_cast<const DetectionVisualPosition*>(reinterpret_cast<const TESObjectREFR*>(pactor)->GetPos());
                    NiAVObject* parrow = BSTestObjects_Create3DArrow(reinterpret_cast<const NiPoint3&>(actorPos), pdetectionEvent->pos, _DAT_010162c0, _DAT_010162c0,
                                                      arrowColor, sphereColor);
                    reinterpret_cast<NiNode*>(
                        static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
                        ->AttachChildInAvailableSlot(parrow, true);
                }
            }
        }
    }
    if (*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))
    {
        NiAlphaProperty* pAlphaProperty = new NiAlphaProperty();
        pAlphaProperty->NiAlphaProperty_SetAlphaBlending(true);
        reinterpret_cast<NiAVObject*>(
            static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
            ->AttachProperty(reinterpret_cast<NiObject*>(pAlphaProperty));
        AttachLightingPropertyRecursive(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38));
        BSShaderManager::UpdateObjectTypeRecurse(reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(
                                                     *reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))),
                                                 false, false);
        reinterpret_cast<NiNode*>(TESObjectCELL_GetMarkerNode(reinterpret_cast<TESObjectREFR*>(g_thePlayer)->GetParentCell()))
            ->AttachChildInAvailableSlot(reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(
                                             *reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38))),
                                         true);
        reinterpret_cast<NiAVObject*>(
            static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
            ->UpdateSceneObject();
        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<NiNode*>(
            static_cast<unsigned int>(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x38)))
            ->Update(static_cast<const NiUpdateData&>(UpdateData));
    }
}
}  // namespace fnv_00991770

class ActiveEffect;
class BGSIdleCollection;
class CombatAction;
class CombatGoal;
class CombatProcedure;
class IDebugText;
class InventoryStackRecord;
class PackageTargetRecord;
class Projectile;
class Script;
class TESBoundObject;
class TESCombatStyle;
class PerkEntryConditionSet;
class TESEscortPackageData;
class TESFile;
class TESIdleForm;
class TESObjectWEAP;
class TESPackageData;
class TESPatrolPackageData;
class TESTopic;
class TESUseWeaponPackageData;
class Tile;
namespace fnv_00992d90 {
struct CombatPlan;
struct CombatBehavior;
struct CombatState;
struct LocationDescriptor;
struct DurationData;
struct blob12
{
    char b[12];
};
struct FUN_00992d90_shell : public CombatManager
{
    bool UpdateCombatMusic();
};


struct RegionPoint
{
    float GetX();
};

struct Animation
{
    float FUN_00453700();
};


struct FUN_00435de0_ctor
{
    float fTimeStamp;
    void* FUN_00435de0(float);
};

float __cdecl CombatTimer_GetTimer();

extern double _gModifierZero;
extern float DAT_0108d9b0;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting486;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting485;
extern SettingT_GameSettingCollection_ g_011ce72c;
extern SettingT_GameSettingCollection_ g_011ceec0;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting483;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting484;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// Checks combat groups against the player to decide whether combat music should play, updating the music timer and timestamp fields accordingly.
// @fnv 0x00992d90
bool FUN_00992d90_shell::UpdateCombatMusic()
{
    bool bplayingMusic =
        (reinterpret_cast<RegionPoint*>(reinterpret_cast<char*>(this) + 0x20)->GetX() != -DAT_0108d9b0) ? true : false;
    if (!reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x2c)->CheckTimer() ||
        g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
    {
        return bplayingMusic;
    }
    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x2c)
        ->Start(g_011ceec0.Float()->f);
    bool bplayCombatMusic = false;
    float fnearbyGroupCombatStrength = 0.0f;
    bool bnearbyGroupDetected = false;
    float fplayerCombatStrength = static_cast<Actor*>(g_thePlayer)->GetCombatRating(-1.0f);
    for (unsigned int i = 0; i < reinterpret_cast<NiTPrimitiveArray<ActorCombatGroup*>*>(this)->GetSize(); ++i)
    {
        ActorCombatGroup* pgroup = reinterpret_cast<NiTPrimitiveArray<ActorCombatGroup*>*>(this)->GetAt(i);
        if (pgroup)
        {
            if (reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*)>(&ActorCombatGroup_FUN_0097ef30)(pgroup) ||
                !reinterpret_cast<PathingSolution*>(pgroup)->GetVirtualNodeCount() ||
                reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*)>(&ActorCombatGroup_FUN_0098a2e0)(pgroup))
            {
                continue;
            }
            if (pgroup->ContainsActor(reinterpret_cast<Actor*>(g_thePlayer)))
            {
                float flastDetectedTimeStampStorage;
                reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, CombatTargetTimestamp*, Actor*)>(
                    &ActorCombatGroup_GetTimestampResult)(pgroup, reinterpret_cast<CombatTargetTimestamp*>(&flastDetectedTimeStampStorage),
                                                        reinterpret_cast<Actor*>(g_thePlayer));
                if (reinterpret_cast<CombatTargetTimestamp*>(&flastDetectedTimeStampStorage)->GetElapsedTime() <
                    originalRuntimeFloatSetting413.Float()->f)
                {
                    if (bplayingMusic)
                    {
                        bplayCombatMusic = true;
                    }
                    else
                    {
                        float fgroupCombatStrength = 0.0f;
                        unsigned int imemberCount = pgroup->GetCount();
                        for (unsigned int i = 0; i < imemberCount; ++i)
                        {
                            Actor* pmember = pgroup->GetIntAt(static_cast<int>(i));
                            if (reinterpret_cast<bool (__thiscall*)(Actor*, Actor*)>(&Actor_FUN_009670f0)(g_thePlayer, pmember))
                            {
                                CombatController* pcombatController = pmember->GetCombatController();
                                if (pcombatController)
                                {
                                    fgroupCombatStrength +=
                                        reinterpret_cast<Animation*>(reinterpret_cast<void* (__thiscall*)(CombatController*)>(&CombatController_GetDetectionModifier)(pcombatController))->FUN_00453700();
                                }
                            }
                        }
                        if (fgroupCombatStrength > _gModifierZero)
                        {
                            float fthreatRatio = fplayerCombatStrength / fgroupCombatStrength;
                            if (fthreatRatio < originalRuntimeFloatSetting486.Float()->f)
                            {
                                bplayCombatMusic = true;
                            }
                        }
                    }
                }
            }
            else if (reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*)>(&ActorCombatGroup_HasPlayerThreat)(pgroup))
            {
                if (bplayingMusic)
                {
                    if (reinterpret_cast<int (__thiscall*)(ActorCombatGroup*, Actor*, float)>(&ActorCombatGroup_FUN_00989880)(pgroup, 
                            reinterpret_cast<Actor*>(g_thePlayer),
                            originalRuntimeFloatSetting485.Float()->f))
                    {
                        bplayCombatMusic = true;
                    }
                }
                else
                {
                    if (reinterpret_cast<int (__thiscall*)(ActorCombatGroup*, Actor*, float)>(&ActorCombatGroup_FUN_00989880)(pgroup, 
                            reinterpret_cast<Actor*>(g_thePlayer),
                            originalRuntimeFloatSetting484.Float()->f))
                    {
                        if (!bnearbyGroupDetected)
                        {
                            unsigned int imemberCount = pgroup->GetCount();
                            for (unsigned int i = 0; i < imemberCount; ++i)
                            {
                                Actor* pmember = pgroup->GetIntAt(static_cast<int>(i));
                                if (reinterpret_cast<bool (__thiscall*)(Actor*, Actor*)>(&Actor_FUN_009670f0)(g_thePlayer, pmember))
                                {
                                    bnearbyGroupDetected = true;
                                    break;
                                }
                            }
                        }
                        fnearbyGroupCombatStrength += reinterpret_cast<float (__thiscall*)(ActorCombatGroup*, int)>(&ActorCombatGroup_GetModifierSum)(pgroup,0);
                        if (bnearbyGroupDetected &&
                            fplayerCombatStrength * g_011ce72c.Float()->f <
                                fnearbyGroupCombatStrength)
                        {
                            bplayCombatMusic = true;
                        }
                    }
                }
            }
        }
        if (bplayCombatMusic)
        {
            break;
        }
    }
    if (bplayingMusic != bplayCombatMusic)
    {
        if (bplayCombatMusic)
        {
            reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x24)->TESWeightForm_InitializeDataComponent();
            FUN_00435de0_ctor ts1;
            ts1.FUN_00435de0(CombatTimer_GetTimer());
            *reinterpret_cast<FUN_00435de0_ctor*>(reinterpret_cast<char*>(this) + 0x20) = ts1;
        }
        else if (!reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x24)->IsRunning())
        {
            reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x24)
                ->Start(originalRuntimeFloatSetting483.Float()->f);
        }
        else if (reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x24)->CheckTimer())
        {
            FUN_00435de0_ctor ts2;
            ts2.FUN_00435de0(-DAT_0108d9b0);
            *reinterpret_cast<FUN_00435de0_ctor*>(reinterpret_cast<char*>(this) + 0x20) = ts2;
            reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x24)->TESWeightForm_InitializeDataComponent();
        }
    }
    return reinterpret_cast<RegionPoint*>(reinterpret_cast<char*>(this) + 0x20)->GetX() != -DAT_0108d9b0;
}
}  // namespace fnv_00992d90

extern "C" void ActorCombatGroup_GetID();
// Returns the combat group with the requested ID.
// @fnv 0x00991d60
ActorCombatGroup* CombatManager::FindByKey(unsigned int key)
{
    for (unsigned int i = 0; i < m_kCombatGroups.GetSize(); ++i)
    {
        ActorCombatGroup* node = m_kCombatGroups.GetAt(i);
        if (node && reinterpret_cast<unsigned int (__thiscall*)(ActorCombatGroup*)>(&ActorCombatGroup_GetID)(node) == key)
            return node;
    }
    return 0;
}


struct FUN_00992530_shell : public CombatManager
{
    bool CombatManager_GetWanttoHelpGroup(Actor* apActor, Actor* apTarget);
};

// @fnv 0x00992530
// src: XBOX_PDB 0x00992530
bool FUN_00992530_shell::CombatManager_GetWanttoHelpGroup(Actor* apActor, Actor* apTarget)
{
    unsigned int kIresult = 0;
    if (!reinterpret_cast<bool (__thiscall*)(Actor*, Actor*)>(&Actor_FUN_008b0970)(apActor, apTarget))
        return false;
    if (apActor && apTarget)
    {
        ActorCombatGroup* pgroup2 = apTarget->GetCombatGroup();
        if (pgroup2)
        {
            unsigned int ihelperCount4 = pgroup2->PathingSolution_GetVirtualNodeCount();
            unsigned int imemberCount5;
            for (unsigned int i5 = 0; i5 < ihelperCount4; i5++)
            {
                Actor* phelper2 = reinterpret_cast<Actor*>(pgroup2->CombatGroup_GetTarget(i5));
                if (reinterpret_cast<bool (__thiscall*)(Actor*, Actor*)>(&Actor_FUN_008b0970)(apActor, phelper2))
                    return false;
            }
            imemberCount5 = pgroup2->GetCount();
            for (unsigned int j2 = 0; j2 < imemberCount5; j2++)
            {
                Actor* pmember = pgroup2->GetIntAt(static_cast<int>(j2));
                int iattack = 0;
                if (apActor->IsHostileToActor(pmember, 0, &iattack, false))
                    return false;
            }
        }
    }
    return true;
}

struct CombatBox
{
    void CombatManager_TargetLocalActor(unsigned int a, unsigned int b);
    void CombatManager_NotifyCombatGroupAddedTarget(unsigned int a, unsigned int b);
};
// @fnv 0x009926c0
// src: XBOX_PDB 0x009926c0
void CombatBox::CombatManager_NotifyCombatGroupAddedTarget(unsigned int uiFirst, unsigned int uiSecond)
{
    CombatManager_TargetLocalActor(uiSecond, uiFirst);
}

namespace fnv_009926e0 {
struct CombatBox
{
    void ClearFlagIfSet(unsigned int a, unsigned int b);
    void SwapAndDispatch(unsigned int a, unsigned int b);
};
// @fnv 0x009926e0
void CombatBox::SwapAndDispatch(unsigned int uiFirst, unsigned int uiSecond)
{
    ClearFlagIfSet(uiSecond, uiFirst);
}
}  // namespace fnv_009926e0

namespace fnv_00992700 {
struct CombatBox
{
    void CombatManager_AddLocalActor(unsigned int a);
    void CombatManager_NotifyCombatGroupAddedMember(unsigned int a, unsigned int b);
};
// @fnv 0x00992700
// src: XBOX_PDB 0x00992700
void CombatBox::CombatManager_NotifyCombatGroupAddedMember(unsigned int uiUnused, unsigned int uiValue)
{
    CombatManager_AddLocalActor(uiValue);
}
}  // namespace fnv_00992700

struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int mask);
    bool TESCombatStyle_GetExplosiveWeaponsIgnoreSelf();
};
// @fnv 0x009928a0
// src: XBOX_PDB 0x009928a0
bool CombatFlagHolder::TESCombatStyle_GetExplosiveWeaponsIgnoreSelf()
{
    return HasCombatFlag(0x20);
}

namespace fnv_009928c0 {
struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int mask);
};
// @fnv 0x009928c0
bool CombatFlagHolder::HasCombatFlag(unsigned int mask)
{
    return (*(unsigned int*)((char*)this + 0xa8) & mask) ? true : false;
}
}  // namespace fnv_009928c0

namespace fnv_009928e0 {
struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int mask);
    bool HasCombatFlag40();
};
// @fnv 0x009928e0
bool CombatFlagHolder::HasCombatFlag40()
{
    return HasCombatFlag(0x40);
}
}  // namespace fnv_009928e0

namespace fnv_00992900 {
struct CombatFlagHolder
{
    bool HasCombatFlag(unsigned int mask);
    bool HasCombatFlag80();
};
// @fnv 0x00992900
bool CombatFlagHolder::HasCombatFlag80()
{
    return HasCombatFlag(0x80);
}
}  // namespace fnv_00992900

struct CombatOwner
{
    void CombatManager_AddLocalActor(unsigned int key);
};
// @fnv 0x009929e0
// src: XBOX_PDB 0x009929e0
void CombatOwner::CombatManager_AddLocalActor(unsigned int key)
{
    unsigned __int64 pair = 0;
    if (!(*(NiTMap<Actor*, unsigned __int64>**)((char*)this + 0x10))->GetAt(reinterpret_cast<Actor*>(key), pair))
        (*(NiTMap<Actor*, unsigned __int64>**)((char*)this + 0x10))->SetAt(reinterpret_cast<Actor*>(key), 0);
}

struct CombatMapOwner
{
    void CombatManager_RemoveLocalActor(unsigned int key);
};
// @fnv 0x00992a30
// src: COMMUNITY 0x00992a30
void CombatMapOwner::CombatManager_RemoveLocalActor(unsigned int key)
{
    (*(NiTMap<Actor*, unsigned __int64>**)((char*)this + 0x10))->RemoveAt(reinterpret_cast<Actor*>(key));
}

struct Flt
{
    operator unsigned int() const;
};
struct CPStandIn00992a50
{
    int f0, f4, f8, fc;
    NiTMap<Actor*, unsigned __int64>* pHelper;
    void CombatManager_TargetLocalActor(Actor* pactor, Flt& flt);
};

// Reads a bit mask for pactor, sets the bit given by flt if clear, and writes the mask back.
// @fnv 0x00992a50
// src: XBOX_PDB 0x00992a50
void CPStandIn00992a50::CombatManager_TargetLocalActor(Actor* pactor, Flt& aiBitIndex)
{
    __int64 ullBit;
    unsigned __int64 ullMask = 0;
    if (!pHelper->GetAt(pactor, ullMask))
        ullMask = 0;
    ullBit = 1 << (unsigned int)aiBitIndex;
    if ((ullMask & ullBit) == 0)
    {
        ullMask |= ullBit;
        pHelper->SetAt(pactor, ullMask);
    }
}

namespace fnv_00992b00 {
struct Flt
{
    operator unsigned int() const;
};
struct CPStandIn00992b00
{
    int f0, f4, f8, fc;
    NiTMap<Actor*, unsigned __int64>* pHelper;
    void ClearFlagIfSet(Actor* pactor, Flt& flt);
};

// Queries the actor's mask via the helper; if the bit for flt is set, clears it and writes the updated mask back.
// @fnv 0x00992b00
void CPStandIn00992b00::ClearFlagIfSet(Actor* apActor, Flt& flt)
{
    __int64 ullBit;
    unsigned __int64 ullMask = 0;
    if (!pHelper->GetAt(apActor, ullMask))
        return;
    ullBit = 1 << (unsigned int)flt;
    if ((ullMask & ullBit) != 0)
    {
        ullMask &= ~ullBit;
        pHelper->SetAt(apActor, ullMask);
    }
}
}  // namespace fnv_00992b00

// @fnv 0x009931a0
int __fastcall ActorCombatGroup_HasPlayerThreat(ActorCombatGroup* group)
{
    return *(char*)((char*)group + 0x154) == 1;
}

// The actor-to-group mask map uses the Gamebryo map layout: bucket count at +4,
// bucket table at +8, and nodes with next/key/value at +0/+4/+8.
// @fnv 0x00993a00
template <>
bool NiTMapBase<DFALL<NiTMapItem<Actor*, unsigned __int64> >, Actor*, unsigned __int64>::GetAt(
    Actor* key, unsigned __int64& outValue) const
{
    unsigned int uiIndex = KeyToHashIndex(key);
    NiTMapItem<Actor*, unsigned __int64>* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            outValue = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

// @fnv 0x00993a80
template <>
void NiTMapBase<DFALL<NiTMapItem<Actor*, unsigned __int64> >, Actor*, unsigned __int64>::GetNext(
    void*& pos, Actor*& key, unsigned __int64& value) const
{
    NiTMapItem<Actor*, unsigned __int64>* pkItem = static_cast<NiTMapItem<Actor*, unsigned __int64>*>(pos);
    unsigned int uiIndex;
    key = pkItem->m_key;
    value = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        pos = pkItem->m_pkNext;
        return;
    }
    uiIndex = KeyToHashIndex(pkItem->m_key);
    for (++uiIndex; uiIndex < m_uiHashSize; ++uiIndex)
    {
        pkItem = m_ppkHashTable[uiIndex];
        if (pkItem)
        {
            pos = pkItem;
            return;
        }
    }
    pos = 0;
}

struct CombatMap
{
    void ComputeHash();
};
struct CombatMapRef
{
    void CombatPlanner_GetNodeKey(CombatMap** p);
};
// @fnv 0x009950a0
// src: COMMUNITY 0x009950a0
void CombatMapRef::CombatPlanner_GetNodeKey(CombatMap** ppCombatMap)
{
    (*ppCombatMap)->ComputeHash();
}

extern const char $SG8126[];

void _FNV_Warning(const char*, ...);


// Retained allocation definition: ActorCombatGroup.h lacks the 0x15C layout and unsigned-id constructor (0x00985d10).
struct FUN_00985d10
{
    char pad[0x15c];
    void* operator new(size_t size);
    FUN_00985d10(unsigned int);
};

struct FUN_00991e80_shell
{
    char pad_00[0x34];
    unsigned int m_uiDebugFlags;

    FUN_00985d10* CombatManager_CreateCombatGroup();
};

// Allocates a combat group with the next id, adds it to the manager, warns if the returned position exceeds 0x40, and sets that position as its quantity.
// @fnv 0x00991e80
// src: XBOX_PDB 0x00991e80
FUN_00985d10* FUN_00991e80_shell::CombatManager_CreateCombatGroup()
{
    AutoMemHelper tempMemContext(0x2b, true, $SG8126, 0x161);
    FUN_00985d10* pgroup = new FUN_00985d10(m_uiDebugFlags++);
    unsigned int ipos = reinterpret_cast<NiTPrimitiveArray<ActorCombatGroup*>*>(this)->Add(
        reinterpret_cast<ActorCombatGroup* const&>(pgroup));
    if (ipos > 0x40)
    {
        _FNV_Warning(
            "COMBAT: In CombatManager, MAX_NUM_COMBAT_GROUPS( %i ) has been exceeded to %i.  Its value needs to be raised.",
            0x40, ipos);
    }
    reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, unsigned int)>(&ActorCombatGroup_SetQuantity)(reinterpret_cast<ActorCombatGroup*>(pgroup), ipos);
    return pgroup;
}

struct FUN_009922b0_shell : public CombatManager
{
    CombatController* GetOrCreateCombatController(Actor* apActor, ActorCombatGroup* apGroup);
};
// @fnv 0x009922b0
CombatController* FUN_009922b0_shell::GetOrCreateCombatController(Actor* apActor, ActorCombatGroup* apGroup)
{
    CombatController* pcombatController;
    AutoMemContext tempMemContext((MEM_CONTEXT)0x2b, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\CombatManager.cpp",
                                  0x1c6);
    pcombatController = apActor->GetCombatController();
    if (pcombatController)
    {
        ActorCombatGroup* pcurrentGroup = pcombatController->GetCombatGroup();
        if (pcurrentGroup != apGroup && reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*, ActorCombatGroup*)>(&ActorCombatGroup_MergeActors)(apGroup, pcurrentGroup))
            reinterpret_cast<void (__thiscall*)(ActorCombatGroup*)>(&ActorCombatGroup_ClearMembers)(pcurrentGroup);
    }
    else if (reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_AddActor)(apGroup, apActor))
    {
        pcombatController = new CombatController(apActor, apGroup, false);
    }
    return pcombatController;
}

namespace fnv_009923d0 {


struct FUN_009923d0_shell
{
    ActorCombatGroup* CombatManager_CreateCombatGroup();

    CombatController* CreateCombatController(void* arg1, void* arg2);
};

// Gets a group via FUN_00991e80, initializes it with arg1, then allocates and returns a CombatController built from arg1, the group and arg2.
// @fnv 0x009923d0
CombatController* FUN_009923d0_shell::CreateCombatController(void* arg1, void* arg2)
{
    ActorCombatGroup* m_pCombatData = CombatManager_CreateCombatGroup();
    m_pCombatData = m_pCombatData;
    reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, void*)>(&ActorCombatGroup_AddActor)(m_pCombatData, arg1);
    CombatController* m_pCombatController = new CombatController(arg1, reinterpret_cast<ActorCombatGroup*>(m_pCombatData), arg2);
    return m_pCombatController;
}
}  // namespace fnv_009923d0

namespace fnv_00992920 {
extern BGSSaveLoadGame* g_BGSSaveLoadGame;


struct CombatMapOwner
{
    void CombatManager_RemoveLocalActor(unsigned int);
};


struct Member14
{
    void RemoveEntryForRef(void*);
};

struct Member1C
{
    void RemoveEntry(unsigned int);
};

struct TargetObj
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
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
};

struct FUN_00992920_shell : CombatMapOwner
{
    char pad_00[0x14];
    Member14* member_14;
    char pad_18[4];
    Member1C* member_1c;

    void ProcessCombatTarget(TargetObj* arg1);
};

// @fnv 0x00992920
void FUN_00992920_shell::ProcessCombatTarget(TargetObj* pTarget)
{
    if (g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        return;

    TargetObj* pActor = 0;
    if (pTarget->IsActor())
        pActor = pTarget;

    for (unsigned int i = 0; i < reinterpret_cast<NiTPrimitiveArray<ActorCombatGroup*>*>(this)->GetSize(); i++)
    {
        ActorCombatGroup* pGroup = reinterpret_cast<NiTPrimitiveArray<ActorCombatGroup*>*>(this)->GetAt(i);
        if (pGroup)
            reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, void*)>(&ActorCombatGroup_FUN_00987820)(pGroup, pTarget);
    }

    if (pActor)
    {
        CombatMapOwner::CombatManager_RemoveLocalActor((unsigned int)pActor);
        member_1c->RemoveEntry((unsigned int)pActor);
    }

    member_14->RemoveEntryForRef(pTarget);
}
}  // namespace fnv_00992920

class ActiveEffect;
class BGSIdleCollection;
class CombatAction;
class CombatGoal;
class CombatProcedure;
class IDebugText;
class InventoryStackRecord;
class PackageTargetRecord;
class Projectile;
class Script;
class TESBoundObject;
class TESCombatStyle;
class PerkEntryConditionSet;
class TESEscortPackageData;
class TESFile;
class TESIdleForm;
class TESObjectWEAP;
class TESPackageData;
class TESPatrolPackageData;
class TESTopic;
class TESUseWeaponPackageData;
namespace fnv_00991600 {
struct CombatPlan;
struct CombatBehavior;
struct CombatState;
struct LocationDescriptor;
struct DurationData;
struct blob12
{
    char b[12];
};
struct FUN_00991600_shell : public CombatManager
{
    void CombatManager_UpdateMainThread(bool);
};


struct FUN_00991770_obj
{
    void UpdateDetectionVisuals();
};
int __fastcall NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(void*);
// @fnv 0x00991600
// src: COMMUNITY 0x00991600
void FUN_00991600_shell::CombatManager_UpdateMainThread(bool abTimeStopped)
{
    unsigned int igroupCount = ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetSize();
    if (igroupCount)
    {
        for (unsigned int i = 0; i < igroupCount; i++)
        {
            ActorCombatGroup* pgroup = ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetAt(i);
            if (pgroup && reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*)>(&ActorCombatGroup_FUN_00986c40)(pgroup))
            {
                delete pgroup;
                m_kCombatGroups.SetAt(i, static_cast<ActorCombatGroup*>(0));
            }
        }
        if (!NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(this))
        {
            m_kCombatGroups.Compact();
            m_pActorCombatGroupMap->RemoveAll();
        }
    }
    if (!abTimeStopped)
    {
        for (unsigned int i = 0; i < ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetSize(); i++)
        {
            ActorCombatGroup* pgroup = ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetAt(i);
            if (pgroup)
            {
                unsigned int imemberCount = pgroup->GetCount();
                for (unsigned int j = 0; j < imemberCount; j++)
                {
                    CombatController* pcombatController;
                    Actor* pactor = pgroup->GetIntAt(static_cast<int>(j));
                    pcombatController = pactor->GetCombatController();
                    if (pcombatController)
                        reinterpret_cast<void (__thiscall*)(CombatController*)>(&CombatController_ResetModifierIfActive)(pcombatController);
                }
            }
        }
    }
    ((FUN_00991770_obj*)this)->UpdateDetectionVisuals();
}
}  // namespace fnv_00991600

namespace fnv_00992640 {


struct FUN_00992640_shell : TESWorldSpace
{
    bool CombatManager_GetWantToHelpTarget(Actor*, Actor*);
};

// @fnv 0x00992640
// src: XBOX_PDB 0x00992640
bool FUN_00992640_shell::CombatManager_GetWantToHelpTarget(Actor* apActor, Actor* apAttacker)
{
    ActorCombatGroup* pgroup = apAttacker->GetCombatGroup();
    if (pgroup == 0)
    {
        return false;
    }
    unsigned int iGroupCount = ((PathingSolution*)pgroup)->GetVirtualNodeCount();
    for (unsigned int i = 0; i < iGroupCount; ++i)
    {
        Actor* pGroupMember = reinterpret_cast<Actor*>(pgroup->CombatGroup_GetTarget(i));
        if (CombatManager_GetWanttoHelpGroup(apActor, pGroupMember))
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00992640

namespace fnv_009931c0 {
struct FUN_009931c0_shell : public CombatManager
{
    unsigned int CountCombatGroupMembers(Actor*, unsigned int*);
};

extern Actor* _g_thePlayer;
// @fnv 0x009931c0
unsigned int FUN_009931c0_shell::CountCombatGroupMembers(Actor* apActor, unsigned int* apNumLost)
{
    unsigned int icount = 0;
    if (apNumLost)
        *apNumLost = 0;
    for (unsigned int i = 0; i < ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetSize(); i++)
    {
        ActorCombatGroup* pgroup = ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetAt(i);
        if (pgroup && (!apActor || pgroup->ContainsActor(apActor)))
        {
            unsigned int igroupCount = pgroup->GetCount();
            if (igroupCount > 0 && pgroup == _g_thePlayer->GetCombatGroup())
                igroupCount--;
            icount += igroupCount;
            if (apActor && apNumLost)
            {
                CombatTargetTimestamp flastDetectedTimeStamp = pgroup->GetLastDetectedTimestamp(apActor);
                if (flastDetectedTimeStamp.GetElapsedTime() > originalRuntimeFloatSetting413.Float()->f)
                    *apNumLost += igroupCount;
            }
        }
    }
    return icount;
}
}  // namespace fnv_009931c0

class NiMatrix3;
class NiQuaternion;
class hkVector4;
namespace fnv_00993440 {
struct SaveLoadFile;
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_00993440_shell : public CombatManager
{
    void LoadCombatState(BGSLoadGameBuffer*);
};


// Retained allocation definition: ActorCombatGroup.h lacks the 0x15C layout and unsigned-id constructor (0x00985d10).
struct FUN_00985d10
{
    FUN_00985d10(unsigned int);
    char pad[0x15c];
};
struct ThreatShim
{
    void CombatThreatMap_LoadGame(BGSLoadGameBuffer*);
};
struct StampShim
{
    void FUN_009a5ff0(BGSLoadGameBuffer*);
};
struct CMView
{
    char pad[0x10];
    NiTMap<Actor*, unsigned __int64>* m_pActorCombatGroupMap;
    ThreatShim* m_pThreatMap;
};
// @fnv 0x00993440
void FUN_00993440_shell::LoadCombatState(BGSLoadGameBuffer* apLoadGameBuffer)
{
    ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadTypedData((void*)((char*)this + 0x34), 4u);
    unsigned int icount;
    unsigned int inumCombatGroups = ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadElementCount();
    for (unsigned int i = 0; i < inumCombatGroups; i++)
    {
        ActorCombatGroup* pgroup;
        unsigned int igroupNum = 0;
        ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadTypedData((void*)&igroupNum, 4u);
        unsigned int igroupID = 0;
        ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadTypedData((void*)&igroupID, 4u);
        pgroup = (ActorCombatGroup*)new FUN_00985d10(0);
        reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, unsigned int)>(&ActorCombatGroup_SetQuantity)(pgroup, igroupNum);
        ((TESRaceForm*)pgroup)->Initialize(igroupID);
        reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, BGSLoadGameBuffer*)>(&ActorCombatGroup_LoadGame)(pgroup, apLoadGameBuffer);
        m_kCombatGroups.SetAtGrow(igroupNum, pgroup);
    }
    ((CMView*)this)->m_pThreatMap->CombatThreatMap_LoadGame(apLoadGameBuffer);
    icount = ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadElementCount();
    for (unsigned int i = 0; i < icount; i++)
    {
        Actor* pactor = 0;
        int64 itargetingBitfield;
        itargetingBitfield.lo = 0;
        itargetingBitfield.hi = 0;
        ((BGSLoadFormBuffer*)apLoadGameBuffer)->ReadFormIdentifier(&pactor);
        ((CMView*)this)
            ->m_pActorCombatGroupMap->SetAt(pactor, *reinterpret_cast<unsigned __int64*>(&itargetingBitfield));
    }
    ((StampShim*)((char*)this + 0x20))->FUN_009a5ff0(apLoadGameBuffer);
    reinterpret_cast<TimeoutTimer*>((char*)this + 0x24)->LoadGame((BGSLoadFormBuffer*)apLoadGameBuffer);
    reinterpret_cast<TimeoutTimer*>((char*)this + 0x2c)->LoadGame((BGSLoadFormBuffer*)apLoadGameBuffer);
}
}  // namespace fnv_00993440

namespace fnv_009932d0 {
struct Flt
{
    operator unsigned int();
};
struct S009a59e0
{
    void SaveThreats(BGSSaveFormBuffer*);
};
struct S009a5f90
{
    void SaveTimeStamp(void*);
};

struct FUN_009932d0_shell
{
    void CombatManager_SaveGame(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x009932d0
// src: COMMUNITY 0x009932d0
void FUN_009932d0_shell::CombatManager_SaveGame(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SaveData((char*)this + 0x34, 4, 0);
    unsigned int uiSavedCount = 0;
    unsigned int uiPos = apBuffer->StartVariableSizedValue();
    {
        unsigned int uiMapCount;
        unsigned int uiPos2;
        for (unsigned int i = 0; i < ((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetSize(); i++)
        {
            Flt* pItem = (Flt*)((NiTPrimitiveArray<ActorCombatGroup*>*)this)->GetAt(i);
            if (pItem)
            {
                unsigned int uiNext;
                {
                    unsigned int uiID = *pItem;
                    apBuffer->SaveData(&uiID, 4, 0);
                }
                uiNext = (unsigned int)((BSSimpleList<void*>*)pItem)->GetNext();
                apBuffer->SaveData(&uiNext, 4, 0);
                reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, BGSSaveFormBuffer*)>(&ActorCombatGroup_SaveGame)(reinterpret_cast<ActorCombatGroup*>(pItem), apBuffer);
                uiSavedCount++;
            }
        }
        apBuffer->SaveVariableSizedValue_00865ff0(uiSavedCount, uiPos);
        ((S009a59e0*)*(void**)((char*)this + 0x14))->SaveThreats(apBuffer);
        uiMapCount = 0;
        uiPos2 = apBuffer->StartVariableSizedValue();
        for (void* pMapPos = (*(NiTMap<Actor*, unsigned __int64>**)((char*)this + 0x10))->GetFirstPos();
             pMapPos;)
        {
            Actor* uiKey;
            unsigned __int64 uiValue;
            (*(NiTMap<Actor*, unsigned __int64>**)((char*)this + 0x10))->GetNext(pMapPos, uiKey, uiValue);
            apBuffer->SerializeFormData((void*)uiKey, 0);
            uiMapCount++;
        }
        apBuffer->SaveVariableSizedValue_00865ff0(uiMapCount, uiPos2);
    }
    ((S009a5f90*)((char*)this + 0x20))->SaveTimeStamp(apBuffer);
    reinterpret_cast<TimeoutTimer*>((char*)this + 0x24)->SaveGame(apBuffer);
    reinterpret_cast<TimeoutTimer*>((char*)this + 0x2c)->SaveGame(apBuffer);
}
}  // namespace fnv_009932d0

struct Manager496
{
    int unk00, unk04, unk08, unk0c;
    NiTMap<Actor*, unsigned __int64>* map;
    int CountNearbyActors(NiPoint3, float, float, Actor*, int*, int*, int*, int*);
};
// Actor.h does not yet declare slot 0x136 with its aggregate return signature.
typedef void(__thiscall* PredictActorPosition)(Actor*, NiPoint3*, float);
// The inherited slot 0x8B takes the original bool argument.
typedef bool(__thiscall* IsActorDead)(Actor*, bool);
// @fnv 0x00992ba0
int Manager496::CountNearbyActors(NiPoint3 origin, float range, float time, Actor* source, int* outSelf,
                                  int* outGroup, int* outAllied, int* outEnemy)
{
    int i = 0;
    int b = 0;
    int c = 0;
    int a = 0;
    int e = 0;
    ActorCombatGroup* d = source->GetCombatGroup();
    float g = range * range;
    unsigned __int64 f = 0;
    if (d)
        f = 1ui64 << reinterpret_cast<unsigned int (__thiscall*)(ActorCombatGroup*)>(&ActorCombatGroup_GetIndex)(d);
    void* h = map->GetFirstPos();
    while (h)
    {
        Actor* F = 0;
        unsigned __int64 I = 0;
        map->GetNext(h, reinterpret_cast<Actor*&>(F), I);
        if (!F || (F && (reinterpret_cast<IsActorDead>((*reinterpret_cast<void***>(F))[0x8b])(F, false) || static_cast<const TESForm*>(F)->GetDisabled() || static_cast<const TESForm*>(F)->GetDeleted())))
            continue;
        fnv_00991770::DetectionVisualPosition A;
        reinterpret_cast<PredictActorPosition>((*reinterpret_cast<void***>(F))[0x136])(F, reinterpret_cast<NiPoint3*>(&A), time);
        NiPoint3 H = origin - reinterpret_cast<const NiPoint3&>(A);
        if (g > H.FUN_004a7290())
        {
            i++;
            if (F == source)
                b++;
            else if (F->GetCombatGroup() == d)
                c++;
            else if (I & f)
                a++;
            else
                e++;
        }
    }
    if (outSelf)
        *outSelf = b;
    if (outGroup)
        *outGroup = c;
    if (outAllied)
        *outAllied = a;
    if (outEnemy)
        *outEnemy = e;
    return i;
}

typedef void(__thiscall* SetCombatGroupProc_00991f80)(Actor*, ActorCombatGroup*);
typedef unsigned int(__thiscall* GetActorValueProc_00991f80)(Actor*);
extern const char UNK_0108dab0[];
void __cdecl Warning_005b5e40(const char*, unsigned int, unsigned int);
struct FUN_00991f80_shell : CombatManager
{
    FUN_00985d10* CombatManager_SplitPlayerCombatGroup(Actor* actor);
};
// @fnv 0x00991f80
// src: EXE 0x00991f80
FUN_00985d10* FUN_00991f80_shell::CombatManager_SplitPlayerCombatGroup(Actor* apActor)
{
    ActorCombatGroup* pGroup = g_thePlayer->GetCombatGroup();
    reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_RemoveActor)(pGroup, apActor);
    if (pGroup->GetCount() > 1)
    {
        ActorCombatGroup* pOldGroup = pGroup;
        reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_RemoveActor)(pOldGroup, (Actor*)g_thePlayer);
        pGroup = (ActorCombatGroup*)((FUN_00991e80_shell*)this)->CombatManager_CreateCombatGroup();
        reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_AddActor)(pGroup, (Actor*)g_thePlayer);
        ((SetCombatGroupProc_00991f80)(*(void***)g_thePlayer)[0xff])((Actor*)g_thePlayer, pGroup);
        pGroup->CombatGroup_CopyTargets(pOldGroup);
        for (unsigned int uStack_14 = 0; uStack_14 < pOldGroup->GetCount(); uStack_14++)
        {
            Actor* piVar5 = pOldGroup->GetIntAt(static_cast<int>(uStack_14));
            if (reinterpret_cast<bool (__thiscall*)(Actor*)>(&Actor_FUN_00566950)(piVar5))
            {
                if (reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_AddActor)(pGroup, piVar5))
                {
                    reinterpret_cast<void (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_RemoveActor)(pOldGroup, piVar5);
                    ((SetCombatGroupProc_00991f80)(*(void***)piVar5)[0xff])((Actor*)piVar5, pGroup);
                    uStack_14--;
                }
                else
                {
                    Warning_005b5e40(UNK_0108dab0,
                                 reinterpret_cast<int (__thiscall*)(Actor*)>(&Actor_FUN_00474cb0)(piVar5)
                                     ? ((GetActorValueProc_00991f80)(*(void***)piVar5)[0x130 / 4])(piVar5)
                                     : reinterpret_cast<unsigned int>(piVar5->TESObjectREFR_GetFullName()),
                                 static_cast<unsigned int>(piVar5->GetHavokWorldObjectCountInSceneGraph_0084e3a0()));
                }
            }
        }
    }
    pGroup->CombatGroup_AddTarget(apActor);
    FUN_00985d10* pResult = ((FUN_00991e80_shell*)this)->CombatManager_CreateCombatGroup();
    reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_AddActor)(reinterpret_cast<ActorCombatGroup*>(pResult), apActor);
    return pResult;
}

struct FUN_00992110_shell : public FUN_00991e80_shell
{
    CombatController* CombatManager_AddCombatant(Actor* apActor, Actor* apTarget, int aiArg3, int aiArg4);
};

// @fnv 0x00992110
// src: COMMUNITY 0x00992110
CombatController* FUN_00992110_shell::CombatManager_AddCombatant(Actor* apActor, Actor* apTarget, int aiArg3, int aiArg4)
{
    AutoMemHelper kMem(0x2b, true, $SG8126, 0x1a7);
    CombatController* pController = apActor->GetCombatController();
    ActorCombatGroup* pGroup2 = 0;
    if (!pController)
    {
        if (!apActor->Actor_CanAttackActor(apTarget))
            return 0;
        pGroup2 = (ActorCombatGroup*)CombatManager_CreateCombatGroup();
        reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_AddActor)(pGroup2, apActor);
        pController = new CombatController(apActor, (ActorCombatGroup*)pGroup2, false);
        if (!reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_AddTarget)(pGroup2, apTarget))
        {
            delete pController;
            return 0;
        }
    }
    else
    {
        pGroup2 = reinterpret_cast<ActorCombatGroup*>(pController->GetCombatGroup());
        reinterpret_cast<bool (__thiscall*)(ActorCombatGroup*, Actor*)>(&ActorCombatGroup_AddTarget)(pGroup2, apTarget);
    }
    return pController;
}

extern SettingT_GameSettingCollection_ DAT_011cf3f0;
extern SettingT_GameSettingCollection_ DAT_011cea74;
extern SettingT_GameSettingCollection_ DAT_011ce3cc;
struct ThreatState
{
    bool TESCombatStyle_GetExplosiveWeaponsIgnoreSelf();
    bool HasCombatFlag40();
    bool HasCombatFlag80();
};
struct ThreatValueOwner
{
    virtual void Slot0();
    virtual void Slot1();
    virtual int Value(int);
};
struct ThreatActor
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
    int unk60;
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
    int unk9c;
    int unka0;
    ThreatValueOwner values;
    float FUN_00477900();
    float FUN_006a78f0();
    ThreatState* Actor_GetCombatStyle();
};
struct ThreatPosition
{
    float x, y, z;
};
float ComputeExplosionDamageFalloff(float, float, float);
struct ThreatManager
{
    int CountNearbyActors(ThreatPosition, float, float, ThreatActor*, int*, int*, int*, int*);
    bool IsThreatWithinLimits(ThreatActor*, ThreatActor*, const ThreatPosition&, float);
};
// @fnv 0x00992720
bool ThreatManager::IsThreatWithinLimits(ThreatActor* actor, ThreatActor* target, const ThreatPosition& position,
                                         float radius)
{
    if (!target)
        return true;
    float strength = target->FUN_00477900();
    float distance = target->FUN_006a78f0();
    if (distance < DAT_011cf3f0.Float()->f)
        return true;
    strength = ComputeExplosionDamageFalloff(strength, distance, DAT_011cf3f0.Float()->f);
    if (strength < DAT_011cea74.Float()->f)
        return true;
    int firstB = 0;
    int second_ = 0;
    int third8 = 0;
    int fourth_2 = 0;
    int result2 = CountNearbyActors(position, strength, radius, actor, &firstB, &second_, &third8, &fourth_2);
    ThreatState* state = actor->Actor_GetCombatStyle();
    if (firstB && !state->TESCombatStyle_GetExplosiveWeaponsIgnoreSelf())
        return false;
    if (second_ && !state->HasCombatFlag40())
        return false;
    if (fourth_2 && actor->values.Value(3) >= *DAT_011ce3cc.Setting_Int() && !state->HasCombatFlag80())
        return false;
    return true;
}

extern "C" void* __cdecl memset(void* dest, int c, unsigned int count);

extern int DAT_011f1590;


class SubClass_997600
{
  public:
    SubClass_997600(CombatController* parent, float val);
    int s000;
    int s001;
    int s002;
    int s003;
    int s004;
    int s005;
    int s006;
    int s007;
    int s008;
    int s009;
    int s010;
    int s011;
    int s012;
    int s013;
    int s014;
    int s015;
    int s016;
    int s017;
    int s018;
    int s019;
    int s020;
    int s021;
    int s022;
    int s023;
    int s024;
    int s025;
    int s026;
    int s027;
    int s028;
    int s029;
    int s030;
    int s031;
    int s032;
    int s033;
    int s034;
    int s035;
    int s036;
    int s037;
    int s038;
    int s039;
    int s040;
    int s041;
    int s042;
    int s043;
    int s044;
    int s045;
    int s046;
    int s047;
    int s048;
    int s049;
    int s050;
    int s051;
    int s052;
    int s053;
    int s054;
    int s055;
    int s056;
    int s057;
    int s058;
    int s059;
    int s060;
    int s061;
    int s062;
    int s063;
    int s064;
    int s065;
    int s066;
    int s067;
    int s068;
    int s069;
    int s070;
    int s071;
    int s072;
    int s073;
    int s074;
    int s075;
    int s076;
    int s077;
    int s078;
    int s079;
    int s080;
    int s081;
    int s082;
    int s083;
    int s084;
    int s085;
    int s086;
    int s087;
    int s088;
    int s089;
    int s090;
    int s091;
    int s092;
    int s093;
    int s094;
    int s095;
    int s096;
    int s097;
    int s098;
    int s099;
    int s100;
    int s101;
    int s102;
    int s103;
    int s104;
    int s105;
    int s106;
    int s107;
    int s108;
    int s109;
    int s110;
    int s111;
    int s112;
    int s113;
    int s114;
    int s115;
    int s116;
    int s117;
    int s118;
    int s119;
    int s120;
    int s121;
    int s122;
    int s123;
    int s124;
    int s125;
    int s126;
    int s127;
    int s128;
    int s129;
    int s130;
    int s131;
    int s132;
    int s133;
    int s134;
    int s135;
    int s136;
    int s137;
    int s138;
};


// Initializes the process fields, creates a SubClass_997600, and if an actor is set, resolves the package and calls SetupPackageTarget.
// @fnv 0x0097d3a0
CombatController::CombatController(Actor* apActor, int a2, TESPackage* apPackage)
    : unkE8(static_cast<AnimIdle*>(0)), unkEC(static_cast<AnimIdle*>(0))
{
    float val = (DAT_011f1590 % 10) * (double)0.1f;
    DAT_011f1590++;
    this->unk80 = reinterpret_cast<ActorCombatGroup*>(a2);
    this->unk84 = 0;
    this->unk88 = 0;
    this->unk9C = reinterpret_cast<CombatState*>(new SubClass_997600(this, val));
    this->unkA0 = 0;
    this->unkA4 = 0;
    this->unkA8 = 0;
    this->unkAC = 0;
    this->unkB0 = 0;
    this->unkF0 = 0;
    this->unkF4 = 0;
    this->unkB4.FUN_008d7f40(0.1f);
    this->unk148 = 0.0f;
    memset(&this->unk14C, 0, sizeof(this->unk14C));
    this->actor = apActor;
    this->unkC0 = 0;
    this->SetPackageType(0x12);
    this->floatE0 = -1.0f;
    this->byteC4 = 0;
    this->byteE4 = 0;
    this->byteC7 = 0;
    this->unkC8 = 0;
    this->floatCC = 128.0f;
    this->floatD0 = 64.0f;
    this->byteD4 = 1;
    this->byteD5 = 1;
    this->floatD8 = 1.0f;
    this->floatDC = 1.0f;
    this->unk148 = 0.0f;
    this->byte124 = 0;
    this->byteC6 = 0xff;
    this->byteC5 = 0;
    this->byteF9 = 0;
    this->FUN_00984f60(0xc);
    this->byteF8 = 0;
    this->byte125 = 0;
    this->byte126 = 0;
    this->unk144 = 0;
    memset(&this->unkFC, 0, sizeof(this->unkFC));
    memset(&this->unk110, 0, sizeof(this->unk110));
    memset(this->unk128, 0, sizeof(this->unk128));
    memset(&this->unk140, 0, sizeof(this->unk140));
    this->byte142 = 0;
    if (this->actor != 0)
    {
        if (apPackage == 0)
        {
            apPackage = this->actor->GetProcess()->GetCurrentPackage();
        }
        this->SetupPackageTarget(apPackage);
    }
}

// SpectatorPackage.h omits SetTarget; declare its external entry point here.
// The call uses the original thiscall ABI without a replacement class.
extern "C" void SpectatorPackage_SetTarget();

namespace fnv_00992480 {

struct CombatOwner_SV
{
    void CombatManager_AddLocalActor(unsigned int);
    void CombatManager_AddSpectatorForCombatGroup(Actor* a1, Actor* a2);
};

// Calls Unk_103 and reloads the package if its type is not 0x18; passes a2 to a SpectatorPackage if present, then calls FUN_009929e0 on a1.
// @fnv 0x00992480
// src: XBOX_PDB 0x00992480
void CombatOwner_SV::CombatManager_AddSpectatorForCombatGroup(Actor* apActor, Actor* apTarget)
{
    if (apActor == apTarget)
        return;

    TESPackage* package;
    {
        BaseProcess* process = apActor->GetProcess();
        package = process->GetCurrentPackage();
        if (!package || package->GetPackType() != 0x18)
        {
            apActor->Unk_103();
            package = process->GetCurrentPackage();
        }
    }
    if (package && package->GetPackType() == 0x18)
    {
        SpectatorPackage* spectatorPackage = (SpectatorPackage*)package;
        reinterpret_cast<void (__thiscall*)(SpectatorPackage*, Actor*)>(&SpectatorPackage_SetTarget)(spectatorPackage, apTarget);
    }
    CombatManager_AddLocalActor((unsigned int)apActor);
}
}  // namespace fnv_00992480
