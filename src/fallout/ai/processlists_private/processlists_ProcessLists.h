// and dependency headers establish the PC member order and natural alignment.
#ifndef FNV_PROCESSLISTS_PRIVATE_PROCESSLISTS_H
#define FNV_PROCESSLISTS_PRIVATE_PROCESSLISTS_H

#include "processlists_layout_support.h"
#include "processlists_lock_free_map.h"

class Crime;
class MagicShaderHitEffect;
class BGSLoadGameBuffer;

class MuzzleFlash;
class DialoguePackage;

class ProcessLists
{
  public:
    float m_fProcessListValue1;
    MobileObjectProcessArray m_kMobileObjectProcessList;
    BSSimpleList<Crime*>* m_pkCrimeLists[5];
    BSSimpleList<NiPointer<BSTempEffect> > m_kTemporaryEffectList;
    BSSimpleList<NiPointer<BSTempEffect> > m_kTemporaryEffectList2;
    BSSimpleList<MuzzleFlash*> m_kMuzzleFlashList;
    BSSimpleList<MobileObject*> m_kMobileObjectList;
    BSSimpleList<TESObjectREFR*> m_kObjectReferenceList;
    BSSimpleList<Actor*> m_kAliveActorList;
    Actor* m_apActorCache[50];
    int m_iActorCount;
    float m_fProcessListValue2;
    float m_fProcessUpdateTimer;
    bool m_bFirstFlagBeforeTaskManager;
    bool m_bSecondFlagBeforeTaskManager;
    ActorTaskManager m_kTaskManager;
    BSSimpleList<DialoguePackage*> DialoguePackageList;
    RecursiveSpinLock m_kActorListLock;
    RecursiveSpinLock kUpdateLock;
    BSSimpleList<MobileObject*>* m_pMobileObjectList;
    BSSimpleList<MobileObject*>* m_pkSecondMobileObjectList;
    LipSyncBackgroundManager m_kLipSyncBackgroundManager;
    bool m_bFirstOfThreeFlags;
    bool m_bSecondOfThreeFlags;
    bool m_bThirdOfThreeFlags;
    Actor* ActorProcessData;
    bool m_bThirdBooleanFlag;
    bool m_bUpdateLowProcesses;
    bool m_bRunSecondProcessUpdate;
    bool m_bUpdateLowListProcessLists;
    bool m_bSeventhBooleanFlag;
    bool m_bFourthOfFiveFlags;
    bool m_bFourthBooleanFlagBeforeFloat;
    int m_iMobileObjectCount;
    float m_fCrimeListUpdateTimer;
    int m_iCrimeNumber;
    float SemaphoreTimingState;
    CountingSemaphore m_kLoadSemaphore;

    void AdvanceProcessLists(float time);
    void InitLoadGame(BGSLoadGameBuffer* buffer);
    bool CanAddActorToList(Actor* actor, int count);
    void Revert(BGSLoadGameBuffer* buffer);
    MagicShaderHitEffect* FindMagicShaderHitEffect(TESObjectREFR* target);
    ~ProcessLists();
    const MobileObjectProcessArray* GetProcessArray() const;  // PC 00717E50
    MobileObjectProcessArray* GetProcessArray();              // PC 00717E50
    BSSimpleList<Actor*>* GetAliveActorList();
    void AddActorToAliveList(Actor* apActor);
    void RemoveActorFromAliveList(Actor* apActor);
    void CalculateAliveActorList();
    void RunActorUpdates();
    void AddMobileObjectToList(MobileObject* object);
    void RemoveMobileObjectFromList(MobileObject* object);
    void UpdateMagicTempEffects(float delta);
    void UpdateFollowerTempList();
    void UpdateInterfaceTempEffects(float delta);
    void UpdateHighProcess();
    bool IsActorTalkingThroughActivator(Actor* apActor);
};
FNV_STATIC_ASSERT(sizeof(ProcessLists) == 0x103E0);
FNV_STATIC_ASSERT(__alignof(ProcessLists) == 32);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_fProcessListValue1) == 0);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kMobileObjectProcessList) == 4);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_pkCrimeLists) == 0x44);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kTemporaryEffectList) == 0x58);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kTemporaryEffectList2) == 0x60);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kMuzzleFlashList) == 0x68);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kMobileObjectList) == 0x70);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kObjectReferenceList) == 0x78);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kAliveActorList) == 0x80);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_apActorCache) == 0x88);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_iActorCount) == 0x150);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_fProcessListValue2) == 0x154);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_fProcessUpdateTimer) == 0x158);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bFirstFlagBeforeTaskManager) == 0x15C);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bSecondFlagBeforeTaskManager) == 0x15D);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kTaskManager) == 0x160);
FNV_STATIC_ASSERT(offsetof(ProcessLists, DialoguePackageList) == 0x102E4);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kActorListLock) == 0x10300);
FNV_STATIC_ASSERT(offsetof(ProcessLists, kUpdateLock) == 0x10320);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_pMobileObjectList) == 0x10340);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_pkSecondMobileObjectList) == 0x10344);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kLipSyncBackgroundManager) == 0x10360);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bFirstOfThreeFlags) == 0x103A0);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bSecondOfThreeFlags) == 0x103A1);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bThirdOfThreeFlags) == 0x103A2);
FNV_STATIC_ASSERT(offsetof(ProcessLists, ActorProcessData) == 0x103A4);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bThirdBooleanFlag) == 0x103A8);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bUpdateLowProcesses) == 0x103A9);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bRunSecondProcessUpdate) == 0x103AA);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bUpdateLowListProcessLists) == 0x103AB);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bSeventhBooleanFlag) == 0x103AC);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bFourthOfFiveFlags) == 0x103AD);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_bFourthBooleanFlagBeforeFloat) == 0x103AE);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_iMobileObjectCount) == 0x103B0);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_fCrimeListUpdateTimer) == 0x103B4);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_iCrimeNumber) == 0x103B8);
FNV_STATIC_ASSERT(offsetof(ProcessLists, SemaphoreTimingState) == 0x103BC);
FNV_STATIC_ASSERT(offsetof(ProcessLists, m_kLoadSemaphore) == 0x103C0);

// Genuine names-only original object: ?g_kProcessLists@@3VProcessLists@@A
// qualified cross-platform identity inference, supported by independently
// annotated PC singleton ownership and direct object-address use at 0096E327.
// This is not an exact PC symbol annotation and does not define new storage.
extern ProcessLists g_kProcessLists;
#endif
