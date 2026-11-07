#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"
#include "NiAVObject.h"
#include "TESFile.h"
#include "TESForm.h"
#include "TESObjectREFR.h"

class BGSExplosion;
class BGSDebris;
class CollisionComponent;
class DestructibleData;
class DestructionStage;
class DestructionStageData;
class IDebugText;
class QueuedFile;
class TESBoundObject;
class TESModel;
enum IO_TASK_PRIORITY;

template <class T, unsigned int Growth> class BSSimpleArray;
template <class Key, class Value> class NiTMap;

class BGSDestructibleObjectForm : public BaseFormComponent
{
public:
    CollisionComponent* pData;

    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);

    void Save();
    static void LoadDestructibleData(BGSDestructibleObjectForm* form, TESFile* file);
    void InitItem(TESForm* form);
    CollisionComponent* GetData();
    DestructionStageData* GetStage(unsigned int stage);
    unsigned char GetStageCount();
    DestructionStageData** AllocateStageArray(unsigned char count);
    void SortStages();
    void SetDestructibleData(DestructionStageData* data);
    void ClearStageData(unsigned int stage);
    static bool HasDestructibleData(TESForm* form);
    static unsigned int GetDestructionStageCount(TESForm* form);
    static BGSDestructibleObjectForm* GetDestructibleObjectForm(TESForm* form);
    static int GetModelSwapIndex(TESForm* form, TESModel* model);
    static TESModel* GetModelSwap(TESForm* form, int index);
    bool HasValidStages();
    bool GetTargetableInVATS();
    void SetTargetableInVATS(bool targetable);
    unsigned int GetMaxHealth(TESObjectREFR* reference);
    void DamageObject(TESObjectREFR* reference, float damage, bool terminal);
    unsigned int SpawnExplosionsAtBlastNodes(NiAVObject*, BGSExplosion*, unsigned int, TESObjectREFR*);
    void SpawnExplosionAtBlastNode(NiAVObject*, unsigned int, void*);
    void SpawnExplosionAtBlastNode(NiAVObject*, unsigned int, BSSimpleArray<NiNode*, 1024>&);
    unsigned int SpawnDebrisAtDebrisNodes(NiAVObject*, BGSDebris*, unsigned int, TESObjectREFR*, unsigned int);
    void FindDebrisNodes(NiAVObject*, unsigned int, void*);
    void FindDebrisNodes(NiAVObject*, unsigned int, BSSimpleArray<NiNode*, 1024>&);
    static void UpdateDamageStageNodes(NiAVObject*, unsigned int);
    void FindDamageStageNodes(NiAVObject*, unsigned int, void*);
    void FindDamageStageNodes(NiAVObject*, unsigned int, BSSimpleArray<NiNode*, 1024>&);
    bool UpdateCurrentDamageStage(TESObjectREFR*, bool);
    void ApplyTerminalDamage(TESObjectREFR*);
    void FindModelSwapNodes(NiAVObject*, void*);
    void FindModelSwapNodes(NiAVObject*, BSSimpleArray<NiNode*, 1024>&);
    static void UpdateDestructionMap();
    static void UpdateTargetHealthBar(TESObjectREFR*);
    static int GetDestructionStageIndex(TESObjectREFR*);
    static bool IsDestructionStageNode(NiAVObject*);
    void QueueResourceLoad(TESBoundObject*, int, QueuedFile*);
    void QueueResourceLoad(TESBoundObject*, IO_TASK_PRIORITY, QueuedFile*);
    void PreloadReplacementModels(TESBoundObject*);
    void UnloadReplacementModels();
    static bool IsDangerousObject(TESForm*);
    float CalculateDangerousExplosionHealth(unsigned char, float, float, BGSExplosion**);
    static float CalculateDangerousExplosionHealth(TESObjectREFR*, float, float, BGSExplosion**);
    float CalculateDangerousExplosionTerminalTime(unsigned char, float, float, BGSExplosion**);
    void DrawDebugText(IDebugText*, TESObjectREFR*);
    void DisplayNodeDebugText(IDebugText*, TESObjectREFR*);
    static unsigned int GetSelfDamage(TESObjectREFR*, float);
    static void SetDestructionStage(TESObjectREFR*, unsigned int);
    static void ClearDestruction(TESObjectREFR*);
    static NiTMap<TESObjectREFR*, unsigned int>* GetDestructibleObjectMap();
    static float GetLastUpdateTime();
    static void SetLastUpdateTime(float);
    void ClearStages();
    void CreateData();
    void RemoveData();
    void EnsureCurrentEntry();
    DestructionStage** AllocateSpawnedItemArray(unsigned int);
    void BGSDestructibleObjectForm_RemoveData();
    void FUN_004786e0(BaseFormComponent* source);
    DestructibleData* FUN_00726070();
};
