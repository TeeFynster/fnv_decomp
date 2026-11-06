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
void FUN_00878250(bool);
void FUN_00878200(ActorReferenceArray::ActorReferenceSetupData&);
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
    FUN_00878250(data.c);
    if (g_thePlayer->FUN_00878340() && BSFaceGenManager::GetModelMap() &&
        BSFaceGenManager::GetModelMap()->HasModels() && !Tile::FindMenuById(0x40c))
        BSFaceGenManager::GetModelMap()->PurgeUnusedModels(false);
    FUN_00878200(data);
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
                for (local.i = 0; local.i < reinterpret_cast<TopicInfoArray*>(actorArray)->FUN_005be5c0(0); local.i++)
                {
                    local.ref = reinterpret_cast<TopicInfoArray*>(actorArray)->FUN_00968670(local.i);
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
                            local.scale = local.actor->FUN_008c4330();
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
                                local.process->FUN_00977c90(local.value);
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
                    local.playerScale = g_thePlayer->FUN_008c4330();
                    local.playerValue *= local.playerScale;
                }
                if (g_thePlayer && local.playerValue > 0.0 && local.playerValue > local.process->GetField440())
                    local.process->FUN_00977c90(local.playerValue);
                if (local.maximum < local.playerValue)
                    local.maximum = local.playerValue;
                local.process->SetWaterLevel(local.process->GetField440());
            }
        }
    }
    active = local.maximum > 0.0 ? 1 : 0;
    if (local.reset)
    {
        for (local.resetIndex = 0; local.resetIndex < reinterpret_cast<TopicInfoArray*>(actorArray)->FUN_005be5c0(0);
             local.resetIndex++)
        {
            local.resetRef = reinterpret_cast<TopicInfoArray*>(actorArray)->FUN_00968670(local.resetIndex);
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

NiRenderer* __cdecl FUN_0043c4b0(void);
void __cdecl FUN_00652190(void);
void __cdecl FUN_008781e0(int);
void __cdecl FUN_00a5b460(void);
void __cdecl FUN_00aa7030(void);
void __fastcall FUN_00c3e340(IOManager*);
extern IOManager* DAT_01202d98;

// @fnv 0x00878200
void __cdecl FUN_00878200(unsigned char* aFreeData)
{
    FUN_00a5b460();
    FUN_00aa7030();
    if (aFreeData[5])
    {
        FUN_00652190();
    }
    FUN_008781e0(*(int*)(aFreeData + 8));
    if (aFreeData[3])
    {
        FUN_0043c4b0()->FinishScene();
    }
    FUN_00c3e340(DAT_01202d98);
}

class ModelLoader
{
  public:
    void FUN_00448620(bool);
};

extern ModelLoader* g_modelLoader;
extern TES* g_TES;

void __cdecl FUN_00868d70(int);
void __fastcall FUN_00b5fd60(ShadowSceneNode*);
void __cdecl FUN_00c459d0(int);
void __cdecl FUN_00651e30();
void __cdecl FUN_00651f40();

// @fnv 0x00878250
void __cdecl FUN_00878250(bool abRunExtraSteps)
{
    FUN_00868d70(1);
    FUN_00b5fd60(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0));
    FUN_00c459d0(0);
    if (abRunExtraSteps)
    {
        FUN_00651e30();
        FUN_00651f40();
    }
    g_modelLoader->FUN_00448620(true);
    g_TES->SetTESActive(false);
}

// @fnv 0x00878340
bool PlayerCharacter::FUN_00878340()
{
    return *((bool*)((char*)this + 0x75d));
}
