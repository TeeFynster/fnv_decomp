#pragma once

// ProcessLists: the actor process manager (JIP/xNVSE ProcessManager), a global object, no vtable. 0x103e0 bytes:
// the object is at 0x011e0e80 (static constructor 0x00fa9890 -> ProcessLists::ProcessLists 0x0096d020) and the
// next global is at 0x011f1260. The constructor builds MobileObjectProcessArray at +0x04 (0x0096a850), the
// BSSimpleLists at +0x58..+0x80 and +0x102e4, ActorTaskManager at +0x160 (AITaskManager::AITaskManager 0x008c9330),
// the RecursiveSpinLocks at +0x10300/+0x10320, LipSyncBackgroundManager at +0x10360 (0x00905e30) and the
// CountingSemaphore (BSSemaphore 0x0086c6a0, args 0, 0x28) at +0x103c0, memsets the actor cache at +0x88 (0xc8 bytes)
// and sets the flags at +0x15c/+0x15d and +0x103a0..+0x103ae. Its last member ends at +0x103cc; the 32-byte
// alignment of the locks pads it to 0x103e0. Member names from the unit-private copy
// (src/fallout/ai/processlists_private/processlists_ProcessLists.h).

#include "ActorTaskManager.h"
#include "BSSimpleList.h"
#include "CountingSemaphore.h"
#include "LipSyncBackgroundManager.h"
#include "MobileObjectProcessArray.h"
#include "NiPointer.h"
#include "RecursiveSpinLock.h"

class Actor;
class ActorList;
class BGSLoadGameBuffer;
class BSTempEffect;
class Crime;
class DialoguePackage;
class MagicShaderHitEffect;
class MagicHitEffectEx;
class MobileObject;
class MuzzleFlash;
class PlayerCharacter;
class Reset3DMobIterator;
class RefX;
class TESForm;
class TESObjectREFR;

class ProcessLists
{
  public:
    float m_fProcessListValue1;                                         // 0x00000
    MobileObjectProcessArray m_kMobileObjectProcessList;                // 0x00004
    BSSimpleList<Crime*>* m_pkCrimeLists[5];                            // 0x00044
    BSSimpleList<NiPointer<BSTempEffect> > m_kTemporaryEffectList;      // 0x00058
    BSSimpleList<NiPointer<BSTempEffect> > m_kTemporaryEffectList2;     // 0x00060
    BSSimpleList<MuzzleFlash*> m_kMuzzleFlashList;                      // 0x00068
    BSSimpleList<MobileObject*> m_kMobileObjectList;                    // 0x00070
    BSSimpleList<TESObjectREFR*> m_kObjectReferenceList;                // 0x00078
    BSSimpleList<Actor*> m_kAliveActorList;                             // 0x00080
    Actor* m_apActorCache[50];                                          // 0x00088
    int m_iActorCount;                                                  // 0x00150
    float m_fProcessListValue2;                                         // 0x00154
    float m_fProcessUpdateTimer;                                        // 0x00158
    bool m_bFirstFlagBeforeTaskManager;                                 // 0x0015c
    bool m_bSecondFlagBeforeTaskManager;                                // 0x0015d
    ActorTaskManager m_kTaskManager;                                    // 0x00160
    BSSimpleList<DialoguePackage*> DialoguePackageList;                 // 0x102e4
    RecursiveSpinLock m_kActorListLock;                                 // 0x10300
    RecursiveSpinLock kUpdateLock;                                      // 0x10320
    BSSimpleList<MobileObject*>* m_pMobileObjectList;                   // 0x10340
    BSSimpleList<MobileObject*>* m_pkSecondMobileObjectList;            // 0x10344
    LipSyncBackgroundManager m_kLipSyncBackgroundManager;               // 0x10360
    bool m_bFirstOfThreeFlags;                                          // 0x103a0
    bool m_bSecondOfThreeFlags;                                         // 0x103a1
    bool m_bThirdOfThreeFlags;                                          // 0x103a2
    Actor* ActorProcessData;                                            // 0x103a4
    bool m_bThirdBooleanFlag;                                           // 0x103a8
    bool m_bUpdateLowProcesses;                                         // 0x103a9
    bool m_bRunSecondProcessUpdate;                                     // 0x103aa
    bool m_bUpdateLowListProcessLists;                                  // 0x103ab
    bool m_bSeventhBooleanFlag;                                         // 0x103ac
    bool m_bFourthOfFiveFlags;                                          // 0x103ad
    bool m_bFourthBooleanFlagBeforeFloat;                               // 0x103ae
    int m_iMobileObjectCount;                                           // 0x103b0
    float m_fCrimeListUpdateTimer;                                      // 0x103b4
    int m_iCrimeNumber;                                                 // 0x103b8
    float SemaphoreTimingState;                                         // 0x103bc
    CountingSemaphore m_kLoadSemaphore;                                 // 0x103c0

    ProcessLists();                                                     // 0x0096d020
    ~ProcessLists();                                                    // 0x0096d290

    // Declarations the units bind (union of their copies); FUN_ names are placeholders.
    void AddActorToAliveList(Actor*);
    void AddHitEffect(MagicHitEffectEx* p);
    void AddReference(MobileObject*, int, bool, bool, bool);
    void AddMagicShaderHitEffect(TESObjectREFR*, char const*);
    void AddMobileObjectToList(MobileObject*);
    void AdvanceProcessLists(float);
    void CalculateAliveActorList();
    bool CanAddActorToList(Actor*, int);
    void ModelLoader_CancelReference(TESObjectREFR*);
    ActorList* FUN_00717e50();
    void ProcessLists_UpdateMiddleHighList(float, bool);
    void MiddleHighProcess_CalculateLightValue(float, bool);
    void MiddleHighProcess_CalculateLightValue(float, int);
    void ProcessLists_UpdateAnimationScenegraph();
    void ProcessLists_RunActorAnimationUpdates();
    void ProcessLists_ParallelActorAnimationMovementUpdates();
    float ProcessLists_GetSystemTimeClock();
    void FUN_0096d4b0(float);
    unsigned short Crime_CreateIndex(int, Crime*);
    Crime* ProcessLists_GetCrimeByIndex(int, unsigned short);
    void ProcessLists_UpdateNonRenderSafeStuff(float);
    MagicShaderHitEffect* FindMagicShaderHitEffect(TESObjectREFR*);
    // Called on the singleton (0x011e0e80) by highprocess.cpp; FUN_ names are placeholders.
    void ProcessLists_AddReference(MobileObject*, int, bool, bool, bool);            // 0x0096d450: forwards to m_kMobileObjectProcessList (0x0096a970)
    void ProcessLists_AddReference(RefX*, int, bool, int, bool);
    void ProcessLists_RemoveReference(MobileObject*, int);                              // 0x0096d470: forwards to m_kMobileObjectProcessList (0x0096aaf0)
    TESObjectREFR* ProcessLists_GetActorRefInHigh(TESForm*, bool);                        // 0x00970a20
    TESObjectREFR* ProcessLists_GetActorRefInHigh_00970b30(TESForm*, int, int);                    // 0x00970b30
    BSSimpleList<Actor*>* CollectNearbyRefs(void*, void*);              // 0x009711e0
    BSSimpleList<Actor*>* CollectCombatTargets(int, void*);             // 0x009715c0
    Crime* FindCrime(Actor*, int, int aiCrimeType);                     // 0x00972570: searches m_pkCrimeLists[aiCrimeType]
    void ProcessLists_RemoveCrimeGlobalCrimeList(void*);                                           // 0x009726e0
    BSSimpleList<Actor*>* CollectActorsByPackage(Actor*, int, bool);    // 0x00971c30 (highprocess.cpp FUN_00900020 call)
    BSSimpleList<Actor*>* GetAliveActorList();
    int GetHighestDetectionValue(PlayerCharacter*, int);
    unsigned char* GetLifeStateControlFlag();
    const MobileObjectProcessArray* GetProcessArray() const;
    MobileObjectProcessArray* GetProcessArray();
    void InitLoadGame(BGSLoadGameBuffer*);
    bool IsActorTalkingThroughActivator(Actor*);
    void ProcessMobileObjects(Reset3DMobIterator*);
    void ProcessMobileObjects(void*);
    static void ProcessPlayerCellActors();
    void RegisterTempEffect(BSTempEffect*);
    void RemoveActorFromAliveList(Actor*);
    void RemoveReference(MobileObject*, int);
    void RemoveMobileObjectFromList(MobileObject*);
    void Revert(BGSLoadGameBuffer*);
    void RunActorUpdates();
    void UpdateActor3D();
    void UpdateCrimeLists();
    void UpdateFollowerTempList();
    void UpdateHighProcess();
    void UpdateInterfaceTempEffects(float);
    void UpdateLowListProcessLists(float, bool);
    void UpdateLowProcesses(float, bool);
    void UpdateMagicTempEffects(float);
};
