#include "../../../include/SettingT.h"
// fallout/misc/memorylevelmanager.cpp: MemoryLevelManager (5 functions)

#include "../../../include/BaseProcess.h"
#include "../../../include/BGSReconstructFormsInAllFilesMap.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/Tile.h"
#include "../../../include/BSFaceGenManager.h"
#include "../../../include/BSFaceGenModelMap.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/NiAdditionalGeometryData.h"
#include "../../../include/NiRenderer.h"
#include "../../../include/TES.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/TopicInfoArray.h"

// Private declarations inferred from the two packet call sites.
struct ActorReferenceArray::ActorReferenceSetupData
{
    unsigned int a;
    unsigned char b;
    bool c;
    unsigned short d;
    unsigned int e;
};

class MemoryLevelManager
{
  public:
    typedef ActorReferenceArray::ActorReferenceSetupData ActorReferenceSetupData;
    static void SetupActorReferences();
    unsigned int reserved;
    unsigned char actorArray[0x158];
    bool active;
    void ResetActorReferences();
};
void MemoryLevelManager_FreeReleasedObjects(bool);
void MemoryLevelManager_EndMemoryFree(ActorReferenceArray::ActorReferenceSetupData&);
extern PlayerCharacter* g_thePlayer;

class TESReputation;
template <class T> class BSSimpleList;
class BGSLoadedReferenceCollection;
extern BGSLoadedReferenceCollection* DAT_011c95c8;
extern bool DAT_011f12d8;

class GameSettingCollection;
using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1045;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting292;
float ScaleByInverseRatio(float, float, float);

// @fnv 0x008782b0
void MemoryLevelManager::SetupActorReferences()
{
    ActorReferenceSetupData data;
    TESObjectCELL::InitializeTESResources(data, true, true, true);
    MemoryLevelManager_FreeReleasedObjects(data.c);
    if (g_thePlayer->GetAllowEGMCacheClear() && BSFaceGenManager::GetModelMap() &&
        BSFaceGenManager::GetModelMap()->HasModels() && !Tile::FindMenuById(0x40c))
        BSFaceGenManager::GetModelMap()->PurgeUnusedModels(false);
    MemoryLevelManager_EndMemoryFree(data);
}
// @fnv 0x009777a0
void MemoryLevelManager::ResetActorReferences()
{
    struct Locals
    {
        Actor* resetRef;
        Actor* resetActor;
        unsigned int resetIndex;
        BaseProcess* playerProcess;
        float playerScale;
        float distance;
        float value;
        float scale;
        unsigned int i;
        Actor* ref;
        float radius;
        BaseProcess* process;
        float playerDistance;
        float playerValue;
        Actor* actor;
        float amount;
        TESFile* key;
        ExtraDataList* extra;
        TESObjectREFR* source;
        void* pos;
        unsigned char padding0;
        unsigned char padding1;
        unsigned char padding2;
        bool reset;
        unsigned int unused;
        BGSReconstructFormsInAllFilesMap* map;
        float maximum;
    } local;
    // This local name preserves MSVC 2008 stack allocation order.
    BaseProcess* maximum;
    local.reset = false;
    local.maximum = 0.0f;
    local.unused = 0;
    local.map = reinterpret_cast<BGSReconstructFormsInAllFilesMap*>(
        reinterpret_cast<TESDataHandler*>(DAT_011c95c8)->GetTESReputationList());
    if (local.map)
    {
        local.pos = local.map->GetFirstPos();
        if (local.pos)
            DAT_011f12d8 = true;
        else if (!local.pos && DAT_011f12d8)
        {
            DAT_011f12d8 = false;
            local.reset = true;
        }
        while (local.pos)
        {
            local.key = 0;
            local.source = 0;
            local.map->GetNext(local.pos, local.key, reinterpret_cast<BGSReconstructFormsInFileMap*&>(local.source));
            local.extra = local.source ? local.source->GetExtraData() : 0;
            if (local.extra)
            {
                local.radius = local.extra->GetRadius();
                local.amount = local.extra->FUN_00422450();
                local.ref = 0;
                local.actor = 0;
                local.process = 0;
                for (local.i = 0; local.i < reinterpret_cast<TopicInfoArray*>(actorArray)->ProcessArray_GetProcessLevelTail(0); local.i++)
                {
                    local.ref = reinterpret_cast<TopicInfoArray*>(actorArray)->ProcessArray_GetItem(local.i);
                    local.actor = 0;
                    if (local.ref && local.ref->IsActor())
                        local.actor = local.ref;
                    if (local.actor)
                    {
                        local.process = local.actor->GetProcess();
                        if (local.process->GetField43C() >
                            reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting1045)
                                ->Float()
                                ->f)
                        {
                            local.distance = local.actor->GetDistanceToReference(local.source, false, true);
                            local.value = ScaleByInverseRatio(local.amount, local.radius, local.distance);
                            local.scale = local.actor->Actor_GetRadiationResistanceMult();
                            local.value *= local.scale;
                            if (local.actor &&
                                local.value >
                                    reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting292)
                                        ->Float()
                                        ->f &&
                                local.value > local.process->GetField440())
                            {
                                if (local.actor->UpdateActorInventory())
                                {
                                    if (!local.process->IsReferenceAvoided(local.source))
                                        local.process->AddAvoidArea(local.actor, *static_cast<const TESObjectREFR*>(local.source)->GetPos(), local.radius,
                                                                    3.402823466e+38f, local.value, local.source, false);
                                    else if (!local.actor->HasEssentialStatus())
                                        local.actor->UpdatePlayerStatus(0x200);
                                    else
                                        local.actor->UpdateActorEquipmentState(local.source, 0.0f);
                                }
                                local.process->HighProcess_SetRadiationLevel(local.value);
                            }
                            local.process->SetWaterLevel(local.process->GetField440());
                        }
                    }
                }
                local.process = g_thePlayer->GetProcess();
                local.playerDistance = g_thePlayer->GetDistanceToReference(local.source, false, true);
                local.playerValue = ScaleByInverseRatio(local.amount, local.radius, local.playerDistance);
                if (local.playerValue > 0.0)
                {
                    local.playerScale = g_thePlayer->Actor_GetRadiationResistanceMult();
                    local.playerValue *= local.playerScale;
                }
                if (g_thePlayer && local.playerValue > 0.0 && local.playerValue > local.process->GetField440())
                    local.process->HighProcess_SetRadiationLevel(local.playerValue);
                if (local.maximum < local.playerValue)
                    local.maximum = local.playerValue;
                local.process->SetWaterLevel(local.process->GetField440());
            }
        }
    }
    active = local.maximum > 0.0 ? 1 : 0;
    if (local.reset)
    {
        for (local.resetIndex = 0; local.resetIndex < reinterpret_cast<TopicInfoArray*>(actorArray)->ProcessArray_GetProcessLevelTail(0);
             local.resetIndex++)
        {
            local.resetRef = reinterpret_cast<TopicInfoArray*>(actorArray)->ProcessArray_GetItem(local.resetIndex);
            local.resetActor = local.resetRef && local.resetRef->IsActor() ? local.resetRef : 0;
            if (local.resetActor)
            {
                maximum = local.resetActor->GetProcess();
                if (maximum)
                    maximum->SetWaterLevel(0.0f);
            }
        }
        local.playerProcess = g_thePlayer->GetProcess();
        if (local.playerProcess)
            local.playerProcess->SetWaterLevel(0.0f);
    }
}

class IOManager;

NiRenderer* __cdecl NiXenonRenderer_GetRenderer(void);
void __cdecl BSFaceGenManager_UnlockFaceGenAccess(void);
void __cdecl BSTexturePalette_SetMaxTexturesToPurge(int);
void __cdecl NiGlobalStringTable_FreeUnusedStrings(void);
void __cdecl MemoryPool_FreeUnusedPagesForAllPools_00aa7030(void);
void __fastcall IOManager_Resume(IOManager*);
extern IOManager* DAT_01202d98;

// @fnv 0x00878200
// src: XBOX_PDB 0x00878200
void __cdecl MemoryLevelManager_EndMemoryFree(unsigned char* aFreeData)
{
    NiGlobalStringTable_FreeUnusedStrings();
    MemoryPool_FreeUnusedPagesForAllPools_00aa7030();
    if (aFreeData[5])
    {
        BSFaceGenManager_UnlockFaceGenAccess();
    }
    BSTexturePalette_SetMaxTexturesToPurge(*(int*)(aFreeData + 8));
    if (aFreeData[3])
    {
        NiXenonRenderer_GetRenderer()->FinishScene();
    }
    IOManager_Resume(DAT_01202d98);
}

class ModelLoader
{
  public:
    void ModelLoader_ClearUnusedModels(bool);
};

extern ModelLoader* g_modelLoader;
extern TES* g_TES;

void __cdecl GarbageCollector_ClearAll(int);
void __fastcall ShadowSceneNode_ProcessQueuedLights(ShadowSceneNode*);
void __cdecl NiObjectGarbage_ClearAll(int);
void __cdecl BSFaceGenManager_ClearModelCache();
void __cdecl BSFaceGenManager_ClearEGTCache();

// @fnv 0x00878250
// src: XBOX_PDB 0x00878250
void __cdecl MemoryLevelManager_FreeReleasedObjects(bool abRunExtraSteps)
{
    GarbageCollector_ClearAll(1);
    ShadowSceneNode_ProcessQueuedLights(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0));
    NiObjectGarbage_ClearAll(0);
    if (abRunExtraSteps)
    {
        BSFaceGenManager_ClearModelCache();
        BSFaceGenManager_ClearEGTCache();
    }
    g_modelLoader->ModelLoader_ClearUnusedModels(true);
    g_TES->SetTESActive(false);
}

// @fnv 0x00878340
// src: XBOX_PDB 0x00878340
bool PlayerCharacter::GetAllowEGMCacheClear()
{
    return *((bool*)((char*)this + 0x75d));
}
