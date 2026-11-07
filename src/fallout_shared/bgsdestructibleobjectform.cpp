// fallout_shared/bgsdestructibleobjectform.cpp: BGSDestructibleObjectForm, TESObjectREFR, ActorValueOwner, TargetLocation (35 functions)

#include "../../include/Actor.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BGSDebris.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSExplosion.h"
#include "../../include/BGSReconstructFormsInAllFilesMap.h"
#include "../../include/BSAudio.h"
#include "../../include/ExtraDataList.h"
#include "../../include/HUDMainMenu.h"
#include "../../include/PatrolActorPackageData.h"
#include "../../include/Setting.h"
#include "../../include/TES.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectWEAP.h"
#include "bgsdestructibleobjectform_decls.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/GO.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiBound.h"
#include "../../include/NiNode.h"
#include "../../include/NiPoint3.h"
#include "../../include/bhkCollisionObject.h"

// Call targets for operations not yet declared by the shared reference and extra-data headers.
extern "C" void __cdecl ReadExtraHealth();
extern "C" void __cdecl RemoveExtraHealth();
extern "C" void __cdecl RemoveExtraModel();
extern "C" void __cdecl HasReferenceDestruction();
extern "C" void __cdecl RestoreReferenceEnabledState();

// @fnv 0x007038b0
void BGSDestructibleObjectForm::UpdateTargetHealthBar(TESObjectREFR* reference)
{
    HUDMainMenu::UpdateTargetActor(reinterpret_cast<Actor*>(reference));
}

// Returns the model path from GetTESModel(), or null if the reference has no model.
// @fnv 0x005715d0
const char* TESObjectREFR::GetModelFilePath()
{
    TESModel* model = GetTESModel();
    if (model)
        return model->GetModelFilePath();
    return 0;
}

// Returns the bound size of the object reference, or 0.0 if there is no object reference.
// @fnv 0x00571600
float TESObjectREFR::GetBoundingRadius()
{
    if (GetObjectReference())
        return GetObjectReference()->GetBoundSize();
    return 0.0f;
}

// Iterates all references in the reconstruct map and applies time-scaled damage to each non-disabled, non-deleted form, either directly or via the task queue.
// @fnv 0x004772f0
void BGSDestructibleObjectForm::UpdateDestructionMap()
{
    void* pIterPos;
    float fTime = g_timeGlobal.FUN_0084d030();
    pIterPos = g_011c4104.GetFirstPos();
    while (pIterPos)
    {
        TESForm* ref = 0;
        unsigned int value = 0;
        g_011c4104.GetNext(pIterPos, (TESFile*&)ref, (BGSReconstructFormsInFileMap*&)value);
        if (ref && !ref->GetDisabled() && !ref->IsDeleted())
        {
            float damage = value * fTime;
            if (*g_011c3ea4.Int() == 1)
            {
                if (ref->IsActor())
                {
                    Actor* actor = (Actor*)ref;
                    actor->DamageHealthAndFatigue(damage, 0.0f, 0);
                }
                else
                    ((TESObjectREFR*)ref)->DamageObject(damage, true);
            }
            else
                TaskQueueInterface::GetSingleton()->QueueReferenceFloatTask(ref, damage, true);
        }
    }
}

// @fnv 0x00571630
TESModel* TESObjectREFR::GetTESModel()
{
    TESModel* model = GetExtraData()->ExtraDataList_GetModelSwap();
    if (!model && GetObjectReference())
    {
        if (static_cast<const TESForm*>(GetObjectReference())->GetFormType() == 40)
        {
            TESObjectWEAP* weapon = (TESObjectWEAP*)GetObjectReference();
            if (GetExtraData()->GetWeaponModIndex())
                model = weapon->GetModTESModel(GetExtraData()->GetWeaponModIndex(), false);
            else
                model = weapon->GetWeaponModel();
        }
        else
            model = dynamic_cast<TESModel*>(GetObjectReference());
    }
    if (!model)
    {
        TESBipedModelForm* biped = TESBipedModelForm::GetFormAsBipedModel(static_cast<TESForm*>(GetObjectReference()));
        if (biped)
        {
            TESForm* pActor;
            int uiSex = 0;
            pActor = GetOwner();
            if (pActor && static_cast<const TESForm*>(pActor)->GetFormType() == 42)
                uiSex = ((TESActorBase*)pActor)->GetSex();
            model = biped->GetWeaponModel((SEX)uiSex);
        }
    }
    return model;
}

// Queues the model, explosion model and debris model of every stage in data for loading at the given priority.
// @fnv 0x00477640
void BGSDestructibleObjectForm::QueueResourceLoad(TESBoundObject* object, IO_TASK_PRIORITY priority, QueuedFile* file)
{
    if (!reinterpret_cast<DestructibleData*>(pData))
        return;
    for (unsigned int i = 0; i < reinterpret_cast<DestructibleData*>(pData)->count; i++)
    {
        if (reinterpret_cast<DestructibleData*>(pData)->stages[i]->model)
            g_modelLoader->ProcessModelRequest(reinterpret_cast<DestructibleData*>(pData)->stages[i]->model, priority, file,
                                               TES::GetModelResourceType((TESObject*)object), true, false, false);
        if (reinterpret_cast<DestructibleData*>(pData)->stages[i]->explosion)
            reinterpret_cast<DestructibleData*>(pData)->stages[i]->explosion->QueueResourceLoad(priority, file);
        if (reinterpret_cast<DestructibleData*>(pData)->stages[i]->debris)
            reinterpret_cast<DestructibleData*>(pData)->stages[i]->debris->QueueResourceLoad(priority, file);
    }
}

// Returns an actor value by dispatching on the ActorValue::Index to the matching getter on the containing object.
// @fnv 0x005f0fb0
int ActorValueOwner::GetActorValue(ActorValue::Index value)
{
    int result = 0;
    switch (value)
    {
    case 5:
        result = ((TESAttributes*)((char*)this - 0x48))->GetAttributeValue5();
        break;
    case 6:
        result = ((TESAttributes*)((char*)this - 0x48))->GetPerception();
        break;
    case 7:
        result = ((TESAttributes*)((char*)this - 0x48))->GetAttributeValue7();
        break;
    case 8:
        result = ((TESAttributes*)((char*)this - 0x48))->GetCharisma();
        break;
    case 9:
        result = ((TESAttributes*)((char*)this - 0x48))->GetIntelligence();
        break;
    case 10:
        result = ((TESAttributes*)((char*)this - 0x48))->GetAttributeValue10();
        break;
    case 11:
        result = ((TESAttributes*)((char*)this - 0x48))->GetLuck();
        break;
    case 16:
        result = ((TESActorBase*)((char*)this - 0x100))->GetHealth_005f0b00();
        break;
    case 22:
        result = ((const TESActorBaseData*)((char*)this - 0xd0))->GetFatigue();
        break;
    case 0:
        result = ((PatrolActorPackageData*)((char*)this - 0x70))->IsPatrolling();
        break;
    case 57:
        result = ((TESAIForm*)((char*)this - 0x70))->GetAssistance();
        break;
    case 1:
        result = ((TESAIForm*)((char*)this - 0x70))->_GetByte05();
        break;
    case 2:
        result = ((BSAudio*)((char*)this - 0x70))->TESRegionData_GetPriority();
        break;
    case 3:
        result = ((TESAIForm*)((char*)this - 0x70))->GetResponsibility();
        break;
    case 4:
        result = ((TESAIForm*)((char*)this - 0x70))->MenuTopic_GetTopicIsChoice();
        break;
    case 21:
        result = ((TESActorBaseData*)((char*)this - 0xd0))->GetShortAtOffset12();
        break;
    case 23:
        result = (int)((const TESActorBaseData*)((char*)this - 0xd0))->GetHealthRegeneration();
        break;
    }
    return result;
}

// @fnv 0x00478be0
void BGSDestructibleObjectForm::InitItem(TESForm* owner)
{
    if (reinterpret_cast<DestructibleData*>(pData))
    {
        for (unsigned int i = 0; i < reinterpret_cast<DestructibleData*>(pData)->count; i++)
        {
            if (reinterpret_cast<DestructibleData*>(pData)->stages[i]->explosion)
            {
                unsigned int explosionID = (unsigned int)reinterpret_cast<DestructibleData*>(pData)->stages[i]->explosion;
                TESForm::RemapFormIDForFile(explosionID, owner->GetFile(-1));
                reinterpret_cast<DestructibleData*>(pData)->stages[i]->explosion = dynamic_cast<BGSExplosion*>(TESForm::GetFormByID(explosionID));
                if (!reinterpret_cast<DestructibleData*>(pData)->stages[i]->explosion)
                {
                    if (owner)
                    {
                        if (((BGSCameraPath*)owner)->HasNameForWarning())
                            Warning("MASTERFILE: Unable to find stage %i explosion (%08X) on owner object \"%s\".", i,
                                    explosionID, owner->GetName());
                        else
                            Warning("MASTERFILE: Unable to find stage %i explosion (%08X) on owner object (%08X).", i,
                                    explosionID, owner->GetFormID());
                    }
                    else
                        Warning("MASTERFILE: Unable to find stage %i explosion (%08X) on unknown owner.", i,
                                explosionID);
                }
            }
            if (reinterpret_cast<DestructibleData*>(pData)->stages[i]->debris)
            {
                unsigned int debrisID = (unsigned int)reinterpret_cast<DestructibleData*>(pData)->stages[i]->debris;
                TESForm::RemapFormIDForFile(debrisID, owner->GetFile(-1));
                reinterpret_cast<DestructibleData*>(pData)->stages[i]->debris = dynamic_cast<BGSDebris*>(TESForm::GetFormByID(debrisID));
                if (!reinterpret_cast<DestructibleData*>(pData)->stages[i]->debris)
                {
                    if (owner)
                    {
                        if (((BGSCameraPath*)owner)->HasNameForWarning())
                            Warning("MASTERFILE: Unable to find stage %i debris (%08X) on owner object \"%s\".", i,
                                    debrisID, owner->GetName());
                        else
                            Warning("MASTERFILE: Unable to find stage %i debris (%08X) on owner object (%08X).", i,
                                    debrisID, owner->GetFormID());
                    }
                    else
                        Warning("MASTERFILE: Unable to find stage %i debris (%08X) on unknown owner.", i, debrisID);
                }
            }
            if (reinterpret_cast<DestructibleData*>(pData)->stages[i]->model)
                ((TESModelTextureSwap*)reinterpret_cast<DestructibleData*>(pData)->stages[i]->model)->InitItem(owner);
        }
        switch (static_cast<const TESForm*>(owner)->GetFormType())
        {
        case 42:
        case 43: {
            TESActorBase* actor = (TESActorBase*)owner;
            reinterpret_cast<DestructibleData*>(pData)->health = actor->GetHealth_005f0b00();
            break;
        }
        }
    }
}

// @fnv 0x0045bb80
// src: XBOX_PDB 0x0045bb80
int __fastcall NiAVObject_GetWorldTranslate(int param_1)
{
    return param_1 + 0x8C;
}

// @fnv 0x00461130
// src: XBOX_PDB 0x00461130
int __fastcall NiAVObject_GetWorldRotate(int pThis)
{
    return pThis + 0x68;
}

extern int DAT_0101a4c4;
void __fastcall FUN_008c6060(void* pThis);

// Initialises the BaseFormComponent at pThis, sets its vtable to DAT_0101a4c4, calls FUN_008c6060, and returns pThis.
// @fnv 0x00475350
// src: GUESS 0x00475350 (confidence: medium)
void* __fastcall BGSDestructibleObjectForm_InitializeFormComponent(void* pThis)
{
    ((BaseFormComponent*)pThis)->BaseFormComponent::BaseFormComponent();
    *(int**)pThis = &DAT_0101a4c4;
    FUN_008c6060(pThis);
    return pThis;
}

// @fnv 0x00475380
BGSDestructibleObjectForm::~BGSDestructibleObjectForm()
{
    BGSDestructibleObjectForm_RemoveData();
}

struct DestructionStageData
{
    void CreateReplacementModel();
    void Copy(DestructionStageData*);
    void CheckReplacementModel();
    bool GetCapDamage();
    void SetCapDamage(bool);
    bool GetDisableObject();
    void SetDisableObject(bool);
    bool GetDestroyObject();
    void SetDestroyObject(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucHealthPercentage;
    unsigned char m_ucStageIndex;
    unsigned char cFlags;
    char _pad_3[1];
    unsigned int m_uiSelfDamagePerSecond;
    BGSExplosion* m_pDebrisObject;
    BGSDebris* m_pDebris;
    unsigned int m_uiDebrisCount;
    TESModelTextureSwap* m_pReplacementModel;
};
typedef char _sizecheck_DestructibleObjectStage[sizeof(DestructionStageData) == 24 ? 1 : -1];

struct DestructibleObjectData_local
{
    unsigned int m_uiHealthValue;
    unsigned char m_ucStageCount;
    unsigned char cFlags;
    char _pad[2];
    DestructionStageData** pStageArray;
};

bool __fastcall IsFlag2Set(DestructionStageData*);

// Returns true if any stage of the destructible object data has a model texture swap, explosion, debris, or passes IsFlag2Set.
// @fnv 0x00475a00
bool BGSDestructibleObjectForm::HasValidStages()
{
    if (!reinterpret_cast<DestructibleObjectData_local*>(pData))
    {
        return false;
    }
    for (unsigned int i = 0; i < reinterpret_cast<DestructibleObjectData_local*>(pData)->m_ucStageCount; ++i)
    {
        DestructionStageData* pstage = reinterpret_cast<DestructibleObjectData_local*>(pData)->pStageArray[i];
        if (pstage)
        {
            if (pstage->m_pReplacementModel || pstage->m_pDebrisObject || pstage->m_pDebris || IsFlag2Set(pstage))
            {
                return true;
            }
        }
    }
    return false;
}

struct FUN_00476980_S
{
    void FUN_004769c0(int, int);
    FUN_00476980_S* NiMatrix3_NiMatrix3(int a, int b, int c);
};
// @fnv 0x00476980
// src: COMMUNITY 0x00476980
FUN_00476980_S* FUN_00476980_S::NiMatrix3_NiMatrix3(int aiValue0, int aiValue1, int aiValue2)
{
    FUN_004769c0(0, aiValue0);
    FUN_004769c0(1, aiValue1);
    FUN_004769c0(2, aiValue2);
    return this;
}

void __fastcall _ref_006815c0(void*);

struct _dummy_476a80
{
    char pad[0x24];
    _dummy_476a80* NiTransform_NiTransform();
};

// @fnv 0x00476a80
// src: XBOX_PDB 0x00476a80
_dummy_476a80* _dummy_476a80::NiTransform_NiTransform()
{
    _ref_006815c0(this);
    _ref_006815c0((char*)this + 0x24);
    return this;
}

struct BSFadeNode_Dummy
{
    char pad[0xb4];
    float f1;
    float f2;
};

void __cdecl BSFadeNode_SetFadingFlag();

// Sets the fade node's two float fields to 1.0 and calls FUN_00476ae0 with true.
// @fnv 0x00476ab0
// src: XBOX_PDB 0x00476ab0
void __fastcall BSFadeNode_TurnFadeNodeOn(BSFadeNode_Dummy* pThis)
{
    pThis->f2 = 1.0f;
    pThis->f1 = 1.0f;
    typedef void(__thiscall * Fn)(BSFadeNode_Dummy*, bool);
    ((Fn)&BSFadeNode_SetFadingFlag)(pThis, true);
}

struct MersenneTwister
{
    void Init(unsigned int);
    void Seed(unsigned int);
    void Kill();
    unsigned int GetRandomUInt(unsigned int, unsigned int);
    unsigned int GetRandomUInt();
    unsigned int GetRandomUInt(unsigned int);
    int Int(int, int);
    int Int();
    float Float(float, float);
    float Float0To1();
    float FloatNeg1To1();
    float FloatTwoPi();
    float FloatNegPiToPi();
    bool Bool(float);
    static MersenneTwister* GetRandomGenerator();
    unsigned int m_uiSeed;
    unsigned int m_uiLastValue;
    char mt[2496];
    unsigned int mti;
};
typedef char _sizecheck_BSRandom[sizeof(MersenneTwister) == 2508 ? 1 : -1];
struct FUN_00476b90_shell : public MersenneTwister
{
    float BSRandom_Float(float, float);
};

// @fnv 0x00476b90
// src: XBOX_PDB 0x00476b90
float FUN_00476b90_shell::BSRandom_Float(float afMin, float afMax)
{
    unsigned int r = GetRandomUInt();
    return (float)(r * (afMax - afMin) / 4294967296.0 + afMin);
}

// @fnv 0x00477ba0
bool __fastcall IsDestroyed(TESForm* form)
{
    return (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(form) + 8) & 0x800000) ? true : false;
}

struct FUN_005df560_S
{
    void GetRowFloats(unsigned int row, float* a, float* b, float* c);
};
// Reads three consecutive floats at offset row*12 from this and writes them to the three output pointers.
// @fnv 0x005df560
void FUN_005df560_S::GetRowFloats(unsigned int row, float* pfOut0, float* pfOut1, float* pfOut2)
{
    *pfOut0 = *(float*)((char*)this + row * 12);
    *pfOut1 = *(float*)((char*)this + row * 12 + 4);
    *pfOut2 = *(float*)((char*)this + row * 12 + 8);
}

namespace fnv_004753d0 {
extern "C" void* __cdecl BGSDestructibleObjectForm_GetDestructionForm(void*);

// Looks up the destructible wrapper for apForm via FUN_00475400 and returns its FUN_00475a00 result, or false if no wrapper exists.
// @fnv 0x004753d0
// src: XBOX_PDB 0x004753d0
bool BGSDestructibleObjectForm_IsDestructible(void* apForm)
{
    BGSDestructibleObjectForm* pWrapper = (BGSDestructibleObjectForm*)BGSDestructibleObjectForm_GetDestructionForm(apForm);
    if (!pWrapper)
    {
        return false;
    }
    return pWrapper->HasValidStages();
}
}  // namespace fnv_004753d0

// @fnv 0x00477410
// src: COMMUNITY 0x00477410
void BGSDestructibleObjectForm_RemoveDestructibleObject(unsigned int index)
{
    g_011c4104.RemoveAt(reinterpret_cast<TESFile*>(index));
}

namespace fnv_00477ce0 {

// If a2 is zero, removes the entry for a1 from g_011c4104; otherwise sets a1 to a2 in that map.
// @fnv 0x00477ce0
void __cdecl SetOrRemoveMapEntry(unsigned int uiKey, unsigned int uiValue)
{
    if (uiValue == 0)
    {
        g_011c4104.RemoveAt(reinterpret_cast<TESFile*>(uiKey));
    }
    else
    {
        g_011c4104.SetAt(reinterpret_cast<TESFile*>(uiKey), reinterpret_cast<BGSReconstructFormsInFileMap*>(uiValue));
    }
}
}  // namespace fnv_00477ce0

struct FUN_004759a0_Elem
{
    char _pad[20];
    int value;
};
struct FUN_004759a0_Mid
{
    char _pad0[4];
    unsigned char cnt;
    FUN_004759a0_Elem** arr;
};

BGSDestructibleObjectForm* __cdecl BGSDestructibleObjectForm_GetDestructionForm(void*);
// @fnv 0x004759a0
int __cdecl GetElementValue(void* a, int aiIndex)
{
    BGSDestructibleObjectForm* pFirst = BGSDestructibleObjectForm_GetDestructionForm(a);
    if (!pFirst || aiIndex == -1)
        return 0;
    {
        FUN_004759a0_Mid* q = reinterpret_cast<FUN_004759a0_Mid*>(pFirst->FUN_00726070());
        if (!q)
            return 0;
        if (aiIndex < q->cnt)
            return q->arr[aiIndex]->value;
        return 0;
    }
}

int __cdecl FinishScriptRunLock(void*);
struct Flt
{
    operator unsigned int() const;
};
struct QIdle;
struct QIdlePtr
{
    QIdlePtr& operator=(QIdle*);
};
struct FUN_004778a0_Mid
{
    char pad[12];
    int lock;
    union
    {
        Flt f;
        QIdlePtr q;
    };
};

// @fnv 0x004778a0
void BGSDestructibleObjectForm::UnloadReplacementModels()
{
    if (!reinterpret_cast<FUN_004778a0_Mid*>(pData))
        return;
    if ((unsigned int)(reinterpret_cast<FUN_004778a0_Mid*>(pData)->f))
    {
        FinishScriptRunLock(&(reinterpret_cast<FUN_004778a0_Mid*>(pData)->lock));
        if (reinterpret_cast<FUN_004778a0_Mid*>(pData)->lock <= 0)
            reinterpret_cast<FUN_004778a0_Mid*>(pData)->q = 0;
    }
}

extern Setting originalRuntimeFloatSetting818;
extern "C" void __cdecl ExplosionHasAnyFlags();
// Returns the float at offset 0x7c, multiplied by originalRuntimeFloatSetting818.Float() when reinterpret_cast<bool (__thiscall*)(BGSExplosion*, int)>(&ExplosionHasAnyFlags)(explosion, 1) is false.
// @fnv 0x00477900
float __fastcall GetExplosionRadius(BGSExplosion* explosion)
{
    return (float)(reinterpret_cast<bool (__thiscall*)(BGSExplosion*, int)>(&ExplosionHasAnyFlags)(explosion, 1) ? (double)explosion->Data.fRadius
                                  : (double)(explosion->Data.fRadius * *originalRuntimeFloatSetting818.Float()));
}

struct bhkWorldObject;

struct H0043b4d0
{
    int value;
    int CFilter_GetLayer();
};

struct W_0043b4f0
{
    H0043b4d0 bhkWorldObject_GetCollisionFilter();
};

// If object has a collision object whose world object type is 19, sets it app-culled and returns true; otherwise recurses into child nodes.
// @fnv 0x00477560
// src: COMMUNITY 0x00477560
bool __cdecl BGSDestructibleObjectForm_HideSmallDebris(NiAVObject* object)
{
    bool result = false;

    if (object)
    {
        bool bIsLodObject = false;
        bhkCollisionObject* collisionObject = bhkCollisionObject::GetFromNiAVObject(object);

        if (collisionObject)
        {
            bhkWorldObject* worldObject = collisionObject->bhkNiCollisionObject_GetWorldObject();

            if (worldObject)
            {
                if (reinterpret_cast<W_0043b4f0*>(worldObject)->bhkWorldObject_GetCollisionFilter().CFilter_GetLayer() == 19)
                    bIsLodObject = true;
            }
        }

        if (bIsLodObject)
        {
            result = true;
            object->SetAppCulled(true);
        }
        else
        {
            NiNode* node = object->IsSceneNode();

            if (node)
            {
                unsigned int count = node->GetNumChildren();

                for (unsigned int index = 0; index < count; ++index)
                {
                    if (BGSDestructibleObjectForm_HideSmallDebris(node->GetAt(index)))
                        result = true;
                }
            }
        }
    }

    return result;
}

// @fnv 0x00475ab0
unsigned int BGSDestructibleObjectForm::GetMaxHealth(TESObjectREFR* pForm)
{
    if (pForm->IsActor())
    {
        Actor* ref = reinterpret_cast<Actor*>(pForm);
        return (unsigned int)reinterpret_cast<ActorValueOwner*>((char*)ref + 0xa4)->GetBaseActorValueFloat(static_cast<ActorValue::Index>(0x10));
    }
    return reinterpret_cast<DestructibleData*>(pData)->health;
}

struct TargetName
{
    int unk00;
    operator const char*() const;
};

struct NamedTarget
{
    NiPoint3 GetTargetPos(void* pArg);
};

NamedTarget* __fastcall LookupNamedTarget(const char* pName);

struct TargetLocation
{
    TESObjectREFR* pRef;
    TargetName kName;
    int unk08;
    NiPoint3 GetTargetPosition();
};

// Returns the target position from the named target if kName is set, otherwise from pRef's 3D bound or its GetPos.
// @fnv 0x009c5f30
NiPoint3 TargetLocation::GetTargetPosition()
{
    NiPoint3 kPos = NiPoint3::ZERO;
    if ((const char*)kName)
    {
        kPos = LookupNamedTarget(kName)->GetTargetPos(&unk08);
    }
    else if (pRef)
    {
        if (pRef->GetNiNode())
        {
            kPos = static_cast<const NiAVObject*>(pRef->GetNiNode())->GetBoundingVolume().GetNavMeshData();
        }
        else
        {
            kPos = *static_cast<const TESObjectREFR*>(pRef)->GetPos();
        }
    }
    return kPos;
}

// Leading layouts for form types whose shared definitions are outside this migration.
struct Fields_c
{
    virtual void FormVtableSlot();
    unsigned int unk04;
    unsigned int unk08;
};
struct Fields_54
{
    virtual void FormVtableSlot();
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
};
struct Fields_58
{
    virtual void FormVtableSlot();
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
};
struct Fields_64
{
    virtual void FormVtableSlot();
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
};
struct Fields_68
{
    virtual void FormVtableSlot();
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
};
struct Fields_7c
{
    virtual void FormVtableSlot();
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
};
struct Fields_84
{
    virtual void FormVtableSlot();
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
};
struct Fields_88
{
    virtual void FormVtableSlot();
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
};
struct Fields_94
{
    virtual void FormVtableSlot();
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
};
struct Fields_9c
{
    virtual void FormVtableSlot();
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
    unsigned int unk98;
};
struct Fields_a4
{
    virtual void FormVtableSlot();
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
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
};
struct Fields_144
{
    virtual void FormVtableSlot();
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
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
};
struct Fields_14c
{
    virtual void FormVtableSlot();
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
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
};
struct Form1d : Fields_94, BGSDestructibleObjectForm
{
};
struct Form2f : Fields_a4, BGSDestructibleObjectForm
{
};

struct Form1f : Fields_84, BGSDestructibleObjectForm
{
};
struct Form1b : Fields_7c, BGSDestructibleObjectForm
{
};
struct Form1a : Fields_144, BGSDestructibleObjectForm
{
};
struct Form19 : Fields_9c, BGSDestructibleObjectForm
{
};
struct Form18 : Fields_14c, BGSDestructibleObjectForm
{
};
struct Form1e : Fields_94, BGSDestructibleObjectForm
{
};
struct Form27 : Fields_68, BGSDestructibleObjectForm
{
};
struct Form29 : Fields_88, BGSDestructibleObjectForm
{
};
struct Form15 : Fields_68, BGSDestructibleObjectForm
{
};
struct Input22
{
    unsigned int unk00;
};
struct Form22 : Fields_c, BGSDestructibleObjectForm, Input22
{
};
struct Form25 : Fields_54, BGSDestructibleObjectForm
{
};
struct Input26
{
    virtual void FormVtableSlot();
};
struct Form26 : Fields_c, Input26, Fields_64, BGSDestructibleObjectForm
{
};
struct Form1c : Fields_68, BGSDestructibleObjectForm
{
};
struct Form16 : Fields_68, BGSDestructibleObjectForm
{
};
struct Form17 : Fields_68, BGSDestructibleObjectForm
{
};
struct Form33 : Fields_58, BGSDestructibleObjectForm
{
};

// Returns the form cast to BGSDestructibleObjectForm for supported form types, or null if the form is null or unsupported.
// @fnv 0x00475400
// src: XBOX_PDB 0x00475400
BGSDestructibleObjectForm* __cdecl BGSDestructibleObjectForm_GetDestructionForm(void* form)
{
    BGSDestructibleObjectForm* result = 0;
    if (form)
    {
        switch (static_cast<const TESForm*>(form)->GetFormType())
        {
        case 0x1d: {
            Form1d* object = static_cast<Form1d*>(form);
            result = object;
            break;
        }
        case 0x2f: {
            Form2f* object = static_cast<Form2f*>(form);
            result = object;
            break;
        }
        case 0x28: {
            TESObjectWEAP* object = static_cast<TESObjectWEAP*>(form);
            result = object;
            break;
        }
        case 0x1f:
        case 0x2e:
        case 0x32:
        case 0x67: {
            Form1f* object = static_cast<Form1f*>(form);
            result = object;
            break;
        }
        case 0x1b: {
            Form1b* object = static_cast<Form1b*>(form);
            result = object;
            break;
        }
        case 0x1a: {
            Form1a* object = static_cast<Form1a*>(form);
            result = object;
            break;
        }
        case 0x19: {
            Form19* object = static_cast<Form19*>(form);
            result = object;
            break;
        }
        case 0x18: {
            Form18* object = static_cast<Form18*>(form);
            result = object;
            break;
        }
        case 0x1e: {
            Form1e* object = static_cast<Form1e*>(form);
            result = object;
            break;
        }
        case 0x27: {
            Form27* object = static_cast<Form27*>(form);
            result = object;
            break;
        }
        case 0x29: {
            Form29* object = static_cast<Form29*>(form);
            result = object;
            break;
        }
        case 0x15: {
            Form15* object = static_cast<Form15*>(form);
            result = object;
            break;
        }
        case 0x22: {
            Form22* object = static_cast<Form22*>(static_cast<Input22*>(form));
            result = object;
            break;
        }
        case 0x25: {
            Form25* object = static_cast<Form25*>(form);
            result = object;
            break;
        }
        case 0x26: {
            Form26* object = static_cast<Form26*>(static_cast<Input26*>(form));
            result = object;
            break;
        }
        case 0x1c: {
            Form1c* object = static_cast<Form1c*>(form);
            result = object;
            break;
        }
        case 0x16: {
            Form16* object = static_cast<Form16*>(form);
            result = object;
            break;
        }
        case 0x17: {
            Form17* object = static_cast<Form17*>(form);
            result = object;
            break;
        }
        case 0x33: {
            Form33* object = static_cast<Form33*>(form);
            result = object;
            break;
        }
        case 0x2a: {
            TESActorBase* object = static_cast<TESActorBase*>(form);
            result = object;
            break;
        }
        case 0x2b: {
            TESActorBase* object = static_cast<TESActorBase*>(form);
            result = object;
            break;
        }
        }
    }
    return reinterpret_cast<BGSDestructibleObjectForm*>(result);
}

// Looks up a1's owner, scans its list for an entry whose value equals a2, and returns its index or -1 if not found.
// @fnv 0x00475920
int FindIndexByValue(void* a1, unsigned int aiValue)
{
    BGSDestructibleObjectForm* pOwner = BGSDestructibleObjectForm_GetDestructionForm(a1);
    if (pOwner == 0)
    {
        return -1;
    }
    FUN_004759a0_Mid* pList = reinterpret_cast<FUN_004759a0_Mid*>(pOwner->FUN_00726070());
    if (pList == 0)
    {
        return -1;
    }
    for (unsigned int i = 0; i < pList->cnt; i++)
    {
        if (pList->arr[i]->value == (int)aiValue)
        {
            return i;
        }
    }
    return -1;
}

float __cdecl FUN_00476b20(float);

// @fnv 0x00477430
// src: GUESS 0x00477430 (confidence: low)
int __cdecl TESObjectREFR_ProcessEntries_00477430(TESObjectREFR* ref)
{
    int iStage = -1;
    if (ref)
    {
        BGSDestructibleObjectForm* pForm = BGSDestructibleObjectForm_GetDestructionForm(ref->GetObjectReference());
        FUN_004759a0_Mid* pData = pForm ? reinterpret_cast<FUN_004759a0_Mid*>(pForm->FUN_00726070()) : 0;
        if (pData)
        {
            float fExtraValue = reinterpret_cast<float (__thiscall*)(ExtraDataList*)>(&ReadExtraHealth)(ref->GetExtraData());
            if (fExtraValue != -1.0)
            {
                unsigned char cPct = (unsigned char)FUN_00476b20(
                    (float)(fExtraValue * 100.0 / pForm->GetMaxHealth(ref)));
                iStage = pData->cnt;
                for (int i = 0; i < pData->cnt; i++)
                {
                    if (((DestructionStageData*)pData->arr[i])->m_ucStageIndex < cPct)
                    {
                        iStage = i;
                        break;
                    }
                }
            }
        }
    }
    return iStage;
}

struct FadeNodeView
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual BSFadeNode_Dummy* AsFadeNode();
};
struct SceneObjectView
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual FadeNodeView* AsNode();
};

struct SaveLoadView
{
    bool FUN_004623f0(bool);
};
struct WorldView
{
    void TES_AttachModel(TESObjectREFR*, void*, int, int);
};
struct FinalView
{
    void RemoveEntryForRef();
};
struct ManagerView
{
    FinalView* FUN_00825c00(TESObjectREFR*);
};
extern SaveLoadView* DAT_011ddf38;
extern WorldView* DAT_011dea10;
extern ManagerView* DAT_011f1958;
void __cdecl bhkWorld_Activate(SceneObjectView*, bool, bool, int);
void __cdecl BGSDestructibleObjectForm_UpdateDamageStageNodes(NiAVObject*, int);

// @fnv 0x00477d10
// src: XBOX_PDB 0x00477d10
void __cdecl BGSDestructibleObjectForm_ClearDestruction(TESObjectREFR* reference)
{
    if (!reinterpret_cast<bool (__thiscall*)(const TESObjectREFR*)>(&HasReferenceDestruction)(reference))
        return;
    BGSDestructibleObjectForm* destructible = BGSDestructibleObjectForm_GetDestructionForm(reinterpret_cast<TESObjectREFR*>(reference)->GetObjectReference());
    float health = reinterpret_cast<float (__thiscall*)(ExtraDataList*)>(&ReadExtraHealth)(reference->BSFile_GetDevice());
    if (health == -1.0)
        return;
    reinterpret_cast<void (__thiscall*)(ExtraDataList*)>(&RemoveExtraHealth)(reference->BSFile_GetDevice());
    if (IsDestroyed(reference))
        reference->SetDestroyed(false);
    if (reference->BSFile_GetDevice()->ExtraDataList_GetModelSwap())
    {
        reinterpret_cast<void (__thiscall*)(ExtraDataList*)>(&RemoveExtraModel)(reference->BSFile_GetDevice());
        if (reinterpret_cast<SceneObjectView*>(reference->GetNiNode()))
        {
            bool allowChanges = DAT_011ddf38->FUN_004623f0(false);
            reference->Set3D(0, true);
            DAT_011ddf38->FUN_004623f0(allowChanges);
            DAT_011dea10->TES_AttachModel(reference, reference->GetParentCell(), 0, 0);
            if (reinterpret_cast<SceneObjectView*>(reference->GetNiNode()))
            {
                SceneObjectView* object = reinterpret_cast<SceneObjectView*>(reference->GetNiNode());
                FadeNodeView* fade = object ? object->AsNode() : 0;
                BSFadeNode_Dummy* node = fade ? fade->AsFadeNode() : 0;
                if (node)
                    BSFadeNode_TurnFadeNodeOn(node);
                bhkWorld_Activate(object, true, true, 0);
            }
        }
    }
    else if (reinterpret_cast<SceneObjectView*>(reference->GetNiNode()))
    {
        BGSDestructibleObjectForm_UpdateDamageStageNodes(reference->Get3DSimple(), 0);
    }
    if (reinterpret_cast<TESForm*>(reference)->GetDisabled())
        reinterpret_cast<void (__thiscall*)(TESObjectREFR*)>(&RestoreReferenceEnabledState)(reference);
    g_011c4104.RemoveAt(reinterpret_cast<TESFile*>(reference));
    DAT_011f1958->FUN_00825c00(reference)->RemoveEntryForRef();
}

unsigned char __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int auiType, char* apData, unsigned int auiSize);
void __cdecl ourMemset(void* apDst, int aiValue, unsigned int auiSize);
void __cdecl TESForm_AddChunk(int aiType);

extern "C" void __cdecl WriteReplacementModel();

struct FUN_00477f20_src
{
    unsigned char ucByte0;
    unsigned char ucByte1;
    unsigned char ucByte2;
    unsigned char ucByte3;
    unsigned int uiValue4;
    TESForm* pSound8;
    TESForm* pSoundC;
    unsigned int uiValue10;
    TESModelTextureSwap* pObj14;
};

struct FUN_00477f20_data
{
    unsigned int uiValue;
    unsigned char ucCount;
    unsigned char ucFlag;
    FUN_00477f20_src** ppEntries;
};

struct FUN_004781b0
{
    unsigned int uiValue;
    unsigned char ucCount;
    unsigned char ucFlag;
    FUN_004781b0();
    void QuestPerkEntryData_Endian();
};

struct FUN_00478130_entry
{
    unsigned char ucByte0;
    unsigned char m_ucClipIdentifier;
    unsigned char ucByte2;
    unsigned char ucByte3;
    unsigned int uiValue4;
    unsigned int uiSound8;
    unsigned int uiSoundC;
    unsigned int uiValue10;
    void SAVE_DESTRUCTIBLE_OBJECT_STAGE_Endian();
};

// @fnv 0x00477f20
void BGSDestructibleObjectForm::Save()
{
    if (reinterpret_cast<FUN_00477f20_data*>(pData))
    {
        FUN_004781b0 kHeader;
        kHeader.uiValue = reinterpret_cast<FUN_00477f20_data*>(pData)->uiValue;
        kHeader.ucCount = reinterpret_cast<FUN_00477f20_data*>(pData)->ucCount;
        kHeader.ucFlag = reinterpret_cast<FUN_00477f20_data*>(pData)->ucFlag;
        if (TESForm_QEndianSwapOnSave())
            kHeader.QuestPerkEntryData_Endian();
        AppendChunk(0x54534544, (char*)&kHeader, 8);
        if (TESForm_QEndianSwapOnSave())
            kHeader.QuestPerkEntryData_Endian();

        for (unsigned int i = 0; i < reinterpret_cast<FUN_00477f20_data*>(pData)->ucCount; i++)
        {
            FUN_00478130_entry kEntry;
            ourMemset(&kEntry, 0, 0x14);
            kEntry.m_ucClipIdentifier = i;
            kEntry.ucByte0 = reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->ucByte1;
            kEntry.uiValue4 = reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->uiValue4;
            kEntry.ucByte2 = reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->ucByte0;
            kEntry.ucByte3 = reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->ucByte2;
            kEntry.uiValue10 = reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->uiValue10;
            if (reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->pSound8)
                kEntry.uiSound8 = reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->pSound8->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            if (reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->pSoundC)
                kEntry.uiSoundC = reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->pSoundC->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            if (TESForm_QEndianSwapOnSave())
                kEntry.SAVE_DESTRUCTIBLE_OBJECT_STAGE_Endian();
            AppendChunk(0x44545344, (char*)&kEntry, 0x14);
            if (TESForm_QEndianSwapOnSave())
                kEntry.SAVE_DESTRUCTIBLE_OBJECT_STAGE_Endian();
            if (reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->pObj14)
                reinterpret_cast<void (__thiscall*)(TESModelTextureSwap*, unsigned int, unsigned int, unsigned int)>(&WriteReplacementModel)(
                    reinterpret_cast<FUN_00477f20_data*>(pData)->ppEntries[i]->pObj14, 0x4c444d44, 0x54444d44, 0x53444d44);
            TESForm_AddChunk(0x46545344);
        }
    }
}

extern double DAT_01012060;
extern double DAT_01017a40;

struct MyDestructionStage
{
    unsigned char stage;
    unsigned char healthPercentage;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int selfDamagePerSecond;
    BGSExplosion* explosion;
    BGSDebris* debris;
    unsigned int count;
    TESModel* model;
};

struct MyDestructibleData
{
    unsigned int health;
    unsigned char count;
    unsigned char flags;
    unsigned short pad;
    MyDestructionStage** stages;
};

extern "C" BGSDestructibleObjectForm* __cdecl BGSDestructibleObjectForm_GetDestructionForm(TESBoundObject*);
float __cdecl FUN_00476b20(float);

// @fnv 0x00477bc0
unsigned int __cdecl GetDestructionStageSelfDamage(TESObjectREFR* refr, float damage)
{
    if (refr == 0 || damage == DAT_01012060)
        return 0;

    BGSDestructibleObjectForm* aActorData = BGSDestructibleObjectForm_GetDestructionForm(refr->GetObjectReference());
    if (aActorData == 0)
        return 0;

    MyDestructibleData* data = reinterpret_cast<MyDestructibleData*>(aActorData->FUN_00726070());
    if (data == 0)
        return 0;

    unsigned int health = aActorData->GetMaxHealth(refr);
    unsigned char aAPGeom = (unsigned char)FUN_00476b20((damage * DAT_01017a40) / (float)health);

    unsigned int aActorMesh = 0;
    unsigned int aAOriginal = 0;
    for (unsigned int i = 0; i < data->count; ++i)
    {
        MyDestructionStage* stage = data->stages[i];
        if (stage->healthPercentage >= aAPGeom)
        {
            aActorMesh = stage->selfDamagePerSecond;
        }
        else
        {
            break;
        }
    }
    return aActorMesh;
}

// A 40-byte allocation view for the queued-file constructor call.

struct QIdlePtrSV : public GO
{
    QIdlePtrSV& operator=(void*);
};

struct FUN_00c3c590_QueuedFile
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;

    FUN_00c3c590_QueuedFile(int);
};

int __cdecl InitScriptRunLock(void*);
void* __cdecl operator new(unsigned int);

// @fnv 0x00477780
void BGSDestructibleObjectForm::PreloadReplacementModels(::TESBoundObject* apBoundObject)
{
    if (!reinterpret_cast<DestructibleData*>(pData))
        return;

    if (!reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(reinterpret_cast<DestructibleData*>(pData)) + 0x10)->GO::operator unsigned int())
    {
        reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(reinterpret_cast<DestructibleData*>(pData)) + 0x10)
            ->
            operator=(new FUN_00c3c590_QueuedFile(5));

        QueueResourceLoad(apBoundObject, static_cast< ::IO_TASK_PRIORITY>(5),
                          reinterpret_cast< ::QueuedFile*>(
                              reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(reinterpret_cast<DestructibleData*>(pData)) + 0x10)
                                  ->GO::operator unsigned int()));

        if (!reinterpret_cast<GO*>(reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(reinterpret_cast<DestructibleData*>(pData)) + 0x10)
                                       ->GO::operator unsigned int())
                 ->GetObjectFlags())
        {
            reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(reinterpret_cast<DestructibleData*>(pData)) + 0x10)->operator=(0);
        }
    }

    if (reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(reinterpret_cast<DestructibleData*>(pData)) + 0x10)->GO::operator unsigned int())
    {
        InitScriptRunLock(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(reinterpret_cast<DestructibleData*>(pData)) + 0xc));
    }
}
