#include "../../../include/TESTexture.h"
// fallout/magic/magicshaderhiteffect.cpp: MagicShaderHitEffect, Effect, ThisHolder, Actor and more (45 functions)

#include "../../../include/Actor.h"
#include "../../../include/NiBound.h"
#include "../../../include/NiMemObject.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/NiTimeController.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/TESEffectShader.h"
#include "../../../include/MagicShaderHitEffect.h"
#include "../../../include/MagicHitEffect.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/BGSDebris.h"
#include "../../../include/BSShaderPPLightingProperty.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiObjectNET.h"
#include "../../../include/TES.h"
#include "../../../include/TESObjectACTI.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESObjectWEAP.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/TESChallenge.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/BSAudio.h"
#include "../../../include/DisintegrateArmorEffect.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/TESSaveLoadGame.h"

// Retained local declarations for types not yet supported by the shared headers.

// BSAudio still declares this factory with the obsolete sound-handle return type.
class ShaderSoundAudio : public BSAudio
{
  public:
    BSSoundHandle GetSoundHandleByEditorID(const char*, unsigned int);
};

struct ShaderTreeCleanup : TESEffectShader
{
    void ClearItemRef(NiNode*, BSShaderPPLightingProperty::TextureEffectData*);
};

class ActiveEffect;
class TESBoundObject;
class BipedAnim;
class NiSourceTexture;
template <class T> class ShaderParticleArray
{
  public:
    unsigned int GetSize();
    T& GetAt(unsigned int);
};
class CloningProcess
{
  public:
    unsigned int data[7];
    CloningProcess(float);
    ~CloningProcess();
};


struct BipedObject
{
    unsigned int unknown[2];
    NiAVObject* object;
};
class BipedAnim
{
  public:
    BipedObject* FindEntry(TESBoundObject*);
};
class InventoryItem
{
  public:
    TESBoundObject* GetObject();
};

class ParticleShaderProperty
{
  public:
    ShaderParticleArray<NiPointer<NiAVObject> >& GetFieldAt11C();
    void ParticleShaderProperty_SetEmitterTypeRay(float);
    void SetByteAtOffset6C(int);
    void ClearField64();
    void ParticleShaderProperty_SetEmitterTypeCollision();
    void DispatchRefOp(NiAVObject*);
    void SetParticleTime(float);
    void UpdateParticlesAtTime(float, bool, bool);
};
class ParticleShader
{
  public:
    static unsigned int GetShaderParticleCount();
};

struct DebrisModelEntry
{
    signed char chance;
    const char* filename;
};
template <class T> class WeightedResultList
{
  public:
    unsigned int data[9];
    WeightedResultList();
    ~WeightedResultList();
    void AddWeightedItem(T, unsigned int);
    T FindFirstItemExceedingRemaining();
};
class Model : public NiObjectNET
{
};
class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
    void LoadModel(const char*, NiPointer<Model>&);
};
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void QueueTaskWithTwoObjects(NiAVObject*, NiNode*, bool, bool);
};
bool IsConditionMet();
float BSMAX_00404010(float, float);
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
extern PlayerCharacter* g_thePlayer;
extern ModelLoader* g_modelLoader;
extern TES* g_TES;
extern unsigned char DAT_011a9448;

// The shared smart pointer has no equality overload; retain the out-of-line comparison.
template <class T> struct ShaderPointerComparison : NiPointer<T>
{
    bool operator==(T*) const;
};

// @fnv 0x0081FC70
bool MagicShaderHitEffect::Init()
{
    if (GetEffect())
    {
        m_fFirstFloatValue = GetEffect()->GetAge();
        bWasPlaying = !GetEffect()->GetEffectSetting()->IsFlagSet_00403e60(0x400);
        if (GetEffect()->HasFlag(0x10))
            m_fEffectShaderScale = 100.0f;
    }
    struct ScenegraphData
    {
        float extent;
        NiAVObject* particles;
        NiAVObject* shaders;
    } scenegraph;
    bool bWeapon = false;
    bool bTargetIsActor = false;
    scenegraph.extent = 0.0f;
    bool bResetParticles = false;
    if (pTarget == g_thePlayer && g_thePlayer->GetNode(false))
    {
        bool bThirdPerson = !g_thePlayer->GetNode(false)->GetAppCulled_00456610();
        bResetParticles = m_fFirstFloatValue > 0.0 && bThirdPerson != b3rdPerson;
        b3rdPerson = bThirdPerson;
    }
    scenegraph.shaders = 0;
    scenegraph.particles = 0;
    GetSceneGraphData(bTargetIsActor, bWeapon, scenegraph.extent, scenegraph.shaders, scenegraph.particles);
    if (scenegraph.shaders && scenegraph.particles && m_pEffectShader)
    {
        if (m_pEffectShader->GetFormID() == 0x852fe || m_pEffectShader->GetFormID() == 0x84a51)
        {
            BSSoundHandle sound = static_cast<ShaderSoundAudio*>(BSAudio::GetSingleton())->GetSoundHandleByEditorID("AMBFireMediumLP", 0x12);
            NiPoint3 position = *static_cast<const TESObjectREFR*>(pTarget)->GetPos();
            sound.SetPosition(position.x, position.y, position.z);
            sound.SetVolume(1.0f);
            sound.Play(true);
            sound.SetObjectToFollow(pTarget->GetNiNode());
        }
        bool bParticles = true;
        if (m_bUseActorParticleEffects && pTarget->IsActor() && ((Actor*)pTarget)->GetProcess())
        {
            if (((Actor*)pTarget)->GetProcess()->IsAnimationActive())
                bParticles = false;
            if (!((Actor*)pTarget)->GetProcess()->IsAdditionalActorFlagSet() && g_thePlayer->GetField6A4() != this)
                bParticles = false;
        }
        if (bParticles && !m_pEffectShader->IsFlagSet_00507040(8))
        {
            if (reinterpret_cast<const ShaderPointerComparison<NiNode>&>(m_pParticleShaderNode) == (NiNode*)0)
            {
                m_pParticleShaderNode = new NiNode(0);
                m_pParticleShaderNode->SetName(NiFixedString("ParticleShader Geometry"));
                m_pParticleShaderNode->SetRotate_0043fa80(&DAT_011a9448);
            }
            if (!m_kParticleShaderProperties.GetSize())
            {
                NiPointer<NiSourceTexture> texture(0);
                if (m_pEffectShader->GetFieldAt158()->GetTextureNameLength() > 0)
                {
                    char path[260];
                    sprintf_s(path, 260, "%s\\%s", "Textures",
                              m_pEffectShader->GetFieldAt158()->GetTextureResourceName());
                    g_TES->CreateTextureImage(static_cast<const char*>(path), texture, false, false);
                    struct ParticleCounts
                    {
                        int total;
                        int perShader;
                    } counts;
                    counts.total = (int)BSMAX_00404010(m_pEffectShader->Explosion_GetRadius(), m_pEffectShader->NiAVObject_GetWorldScale());
                    counts.perShader = ParticleShader::GetShaderParticleCount();
                    for (int i = 0; i * counts.perShader < counts.total; ++i)
                    {
                        NiPointer<ParticleShaderProperty> particleProperty =
                            m_pEffectShader->CreateParticleShaderProperty(m_pParticleShaderNode, scenegraph.particles,
                                                                          texture, m_fEffectShaderScale);
                        m_kParticleShaderProperties.BSSimpleArray_NiPointer_NiAVObject_1024_Add(particleProperty);
                    }
                }
            }
            for (unsigned int i = 0; i < m_kParticleShaderProperties.GetSize(); ++i)
            {
                ParticleShaderProperty* property = m_kParticleShaderProperties.GetAt(i);
                if (bWeapon)
                    property->ParticleShaderProperty_SetEmitterTypeRay(scenegraph.extent);
                if (m_bUseActorParticleEffects)
                    property->SetByteAtOffset6C(0);
                if (pTarget)
                {
                    TESObjectACTI* activator = dynamic_cast<TESObjectACTI*>(pTarget->GetObjectReference());
                    if (bTargetIsActor || activator)
                    {
                        if (pTarget == g_thePlayer && !b3rdPerson)
                            property->ClearField64();
                        else
                            property->ParticleShaderProperty_SetEmitterTypeCollision();
                    }
                }
                property->DispatchRefOp(scenegraph.particles);
                if (bResetParticles)
                {
                    property->SetParticleTime(0.0f);
                    property->UpdateParticlesAtTime((float)(m_fEffectShaderScale - 0.16599999368190765), false, true);
                    property->UpdateParticlesAtTime(m_fEffectShaderScale, false, true);
                }
            }
            AttachToTarget();
        }
        else if (m_kParticleShaderProperties.GetSize() && (NiNode*)m_pParticleShaderNode)
        {
            for (unsigned int i = 0; i < m_kParticleShaderProperties.GetSize(); ++i)
                m_pEffectShader->StopParticleShader(m_pParticleShaderNode, m_kParticleShaderProperties.GetAt(i));
            m_kParticleShaderProperties.RemoveAll(true);
            if ((NiNode*)m_pParticleShaderNode)
                m_pParticleShaderNode->AssignParent(0);
            m_pParticleShaderNode = (NiNode*)0;
        }
        if (!m_pEffectShader->IsFlagSet_00507040(1))
        {
            if (reinterpret_cast<const ShaderPointerComparison<BSShaderPPLightingProperty::TextureEffectData>&>(spTexEffectData) ==
                (BSShaderPPLightingProperty::TextureEffectData*)0)
            {
                NiPointer<NiSourceTexture> fillTexture(0);
                if (m_pEffectShader->GetFieldAt14C()->GetTextureNameLength() > 0)
                {
                    char path[260];
                    sprintf_s(path, 260, "%s\\%s", "Textures",
                              m_pEffectShader->GetFieldAt14C()->GetTextureResourceName());
                    g_TES->CreateTextureImage(static_cast<const char*>(path), fillTexture, false, false);
                }
                NiPointer<NiSourceTexture> holesTexture(0);
                if (m_pEffectShader->GetFieldAt164()->GetTextureNameLength() > 0)
                {
                    char path[260];
                    sprintf_s(path, 260, "%s\\%s", "Textures",
                              m_pEffectShader->GetFieldAt164()->GetTextureResourceName());
                    g_TES->CreateTextureImage(static_cast<const char*>(path), holesTexture, false, false);
                }
                spTexEffectData = m_pEffectShader->CreateEffectData(scenegraph.shaders, fillTexture, holesTexture);
                if ((BSShaderPPLightingProperty::TextureEffectData*)spTexEffectData &&
                    (NiSourceTexture*)spTexEffectData->spTexture && pTarget && pTarget->IsActor() &&
                    ((Actor*)pTarget)->GetAlphaMult() > 0.9900000095367432)
                {
                    ((Actor*)pTarget)->GetLightIntensity(0.99f);
                    ((Actor*)pTarget)->UpdateActorPresentation();
                }
            }
            m_pEffectShader->ApplyShaderToTree(scenegraph.shaders, spTexEffectData);
        }
        if (!bResetParticles && !m_kAddonModelObjects.GetSize() && m_pEffectShader &&
            m_pEffectShader->GetAddonModels() && m_kParticleShaderProperties.GetSize() > 0 &&
            (ParticleShaderProperty*)m_kParticleShaderProperties.GetAt(0) &&
            m_kParticleShaderProperties.GetAt(0)->GetFieldAt11C().GetSize() > 0)
        {
            ParticleShaderProperty* property;
            BSSimpleList<DebrisModelEntry*>* entry;
            {
                WeightedResultList<const char*> weightedModels;
                entry = m_pEffectShader->GetAddonModels()->GetData();
                while (entry && !entry->IsEmpty())
                {
                    g_modelLoader->LoadFile(entry->GetItem()->filename, 0, true, false, false, false);
                    weightedModels.AddWeightedItem(entry->GetItem()->filename, entry->GetItem()->chance);
                    entry = entry->GetNext();
                }
                property = m_kParticleShaderProperties.GetAt(0);
                for (unsigned int i = 0; i < property->GetFieldAt11C().GetSize(); ++i)
                {
                    NiAVObject* object = property->GetFieldAt11C().GetAt(i);
                    if (object->IsSceneNode())
                    {
                        NiPointer<Model> model(0);
                        g_modelLoader->LoadModel(weightedModels.FindFirstItemExceedingRemaining(), model);
                        if ((Model*)model && model->GetControllers())
                        {
                            CloningProcess cloneProcess(1.0f);
                            NiAVObject* clone = static_cast<NiAVObject*>(model->GetControllers()->CloneObject(cloneProcess));
                            if (IsConditionMet())
                                TaskQueueInterface::GetSingleton()->QueueTaskWithTwoObjects(
                                    clone, object->IsSceneNode(), true, false);
                            else
                                object->IsSceneNode()->AttachChildInAvailableSlot(clone, true);
                            m_fAddonModelTimer = 0.0f;
                            m_fAddonModelScale = BSMAX_00404010(0.01f, m_pEffectShader->TESEffectShader_GetAddOnScaleStart());
                            clone->NiAVObject_SetScale(m_fAddonModelScale);
                            NiTimeController::UpdateControllersForTarget(static_cast<NiObjectNET*>(clone));
                            m_kAddonModelObjects.BSSimpleArray_NiPointer_NiAVObject_1024_Add(clone);
                        }
                    }
                }
            }
        }
        if (m_kParticleShaderProperties.GetSize() <= 0 &&
            !(BSShaderPPLightingProperty::TextureEffectData*)spTexEffectData)
            return false;
        else
            return true;
    }
    return false;
}

// @fnv 0x00820C10
void MagicShaderHitEffect::GetSceneGraphData(bool& isActor, bool& isWeapon, float& extent, NiAVObject*& shaderObject,
                                             NiAVObject*& particleObject)
{
    bool bParticles = false;
    bool bArmor = false;
    NiAVObject* pObject = 0;
    bool bWeapon = false;
    Actor* pTargetActor = dynamic_cast<Actor*>(pTarget);
    BipedAnim* pBiped = 0;
    if (pTargetActor)
    {
        if (pTargetActor != g_thePlayer)
            pBiped = reinterpret_cast<BipedAnim*>(pTargetActor->GetValidBip01Names());
        else if (g_thePlayer->PlayerCharacter_GetInventory3D() && g_thePlayer->GetField6A4() == this)
            bWeapon = true;
        else
            pBiped = g_thePlayer->GetBipedAnimation(!b3rdPerson);
    }
    if (m_bUseActorParticleEffects || bParticles)
    {
        if (pTarget && pTarget->IsActor())
        {
            Actor* targetActor = (Actor*)pTarget;
            BaseProcess* process = targetActor->GetProcess();
            if (process)
                process->GetActiveWeapon();
        }
    }
    else if (bArmor)
    {
        DisintegrateArmorEffect* effect = dynamic_cast<DisintegrateArmorEffect*>(GetEffect());
        if (effect)
        {
            InventoryItem* item = effect->GetItem();
            if (item)
                m_pAffectedArmorObject = item->GetObject();
        }
        if (pTarget && pTarget->IsActor() && m_pAffectedArmorObject && pBiped)
        {
            BipedObject* worn = pBiped->FindEntry(m_pAffectedArmorObject);
            if (worn)
                pObject = worn->object;
        }
    }
    else if (pTarget)
    {
        pObject = pTarget->GetNiNode();
        if (pTarget->IsActor())
        {
            if (pTarget == g_thePlayer)
                pObject = g_thePlayer->GetNode(!b3rdPerson);
            isActor = true;
        }
        else
        {
            TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(pTarget->GetObjectReference());
            if (weapon && pObject)
            {
                isWeapon = true;
                if (pObject->GetBoundingVolume().FUN_0084d030() <= 0.0)
                {
                    NiUpdateData update(0.0f, false, false);
                    pObject->Update(update);
                }
                NiPoint3 offset = pObject->GetBoundingVolume().GetNavMeshData() - pObject->NiAVObject_GetWorldTranslate();
                extent = static_cast<const NiPoint3&>(offset).ComputeMagnitude() + pObject->GetBoundingVolume().FUN_0084d030();
            }
        }
    }
    shaderObject = pObject;
    particleObject = pObject;
}

// Releases the array storage through its virtual deallocator.
// @fnv 0x006a8500
void __fastcall FreeShaderArrayStorage(BSSimpleArray<NiPointer<ParticleShaderProperty> >* pThis)
{
    pThis->_Deallocate(pThis->pBuffer);
    pThis->pBuffer = 0;
}

struct S2f850
{
    int pad0;
    NavMeshPtr* data;
    unsigned int FUN_00761540();
    void BSSimpleArray_NavMeshPtr_1024_ConstructItems(NavMeshPtr*, int);
    unsigned int BSSimpleArray_NiPointer_NiAVObject_1024_Add(const NavMeshPtr& aValue);
};
// @fnv 0x006c61b0
// src: XBOX_PDB 0x006c61b0
unsigned int S2f850::BSSimpleArray_NiPointer_NiAVObject_1024_Add(const NavMeshPtr& aValue)
{
    unsigned int uiIndex = FUN_00761540();
    BSSimpleArray_NavMeshPtr_1024_ConstructItems(&data[uiIndex], 1);
    data[uiIndex] = aValue;
    return uiIndex;
}

// @fnv 0x006c6200
template <> void BSSimpleArray<NiPointer<ParticleShaderProperty> >::RemoveAll(bool abFreeStorage)
{
    if (pBuffer)
    {
        ReleaseElements(pBuffer, iSize);
        if (abFreeStorage)
        {
            FreeShaderArrayStorage(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}

void __fastcall FUN_0081f770(void* pThis);

struct FUN_0081f320_helper
{
    void* FUN_0081f320(unsigned int flags);
};

// Calls FUN_0081f770 on this, then deletes this with NiMemObject::operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0081f320
void* FUN_0081f320_helper::FUN_0081f320(unsigned int flags)
{
    FUN_0081f770(this);
    if (flags & 1)
    {
        NiMemObject::operator delete(this, 0x6c);
    }
    return this;
}

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x00822580
// src: GUESS 0x00822580 (confidence: low)
void* __fastcall Object_ProcessAndReturnValue_00822580(int** ppObject)
{
    *ppObject = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(ppObject)->FUN_0042fcb0(0, 0);
    return ppObject;
}

// Releases each particle shader property held by the array.
// @fnv 0x00822820
template <> void BSSimpleArray<NiPointer<ParticleShaderProperty> >::ReleaseElements(
    NiPointer<ParticleShaderProperty>* apElems, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
        apElems[i] = (ParticleShaderProperty*)0;
}

class NavMeshInfo;
namespace fnv_00822860 {
struct S2f850
{
    void BSSimpleArray_NavMeshPtr_1024_ConstructItems(NavMeshInfo**, unsigned int);
};
struct UW
{
    unsigned int v;
};
struct AX
{
    virtual void* v0(unsigned int);
    virtual NavMeshInfo** Allocate(unsigned int);
    NavMeshInfo** data;
    unsigned int size;
    unsigned int alloc;
};
// @fnv 0x00822860
// src: XBOX_PDB 0x00822860
void __fastcall BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(AX* self, UW uiMaxSize, UW uiSize)
{
    self->data = 0;
    self->size = 0;
    self->alloc = 0;
    if (uiSize.v > uiMaxSize.v)
        uiMaxSize.v = uiSize.v;
    if (uiMaxSize.v > 0)
    {
        self->data = self->Allocate(uiMaxSize.v);
        self->alloc = uiMaxSize.v;
    }
    if (uiSize.v > 0)
    {
        ((S2f850*)self)->BSSimpleArray_NavMeshPtr_1024_ConstructItems(self->data, uiSize.v);
        self->size = uiSize.v;
    }
}
}  // namespace fnv_00822860

extern int g_011dc804;

// @fnv 0x0081f310
int* __fastcall GetGlobalIntPtr(int* thisPtr)
{
    return &g_011dc804;
}

struct FUN_00820b70_shell
{
    char m_auiShapeKeys[0x64];
    int m_0x64;
    float m_0x68;

    void ParticleShaderProperty_SetEmitterTypeRay(float a);
};

// Sets m_0x64 to 2 and stores the float argument in m_0x68.
// @fnv 0x00820b70
// src: COMMUNITY 0x00820b70
void FUN_00820b70_shell::ParticleShaderProperty_SetEmitterTypeRay(float afValue)
{
    m_0x64 = 2;
    m_0x68 = afValue;
}

// @fnv 0x00820b90
// src: COMMUNITY 0x00820b90
void __fastcall ParticleShaderProperty_SetEmitterTypeCollision(int pObject)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(pObject) + 0x64) = 1;
}

// @fnv 0x00820bb0
void __fastcall ClearField64(void* apObject)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(apObject) + 0x64) = 0;
}

struct Arr3520
{
    void RemoveAll(bool);
};

extern int DAT_0107b824;

// @fnv 0x00822560
// src: GUESS 0x00822560 (confidence: medium)
void __fastcall Object_ResetVirtualTableAndRemoveAll(Arr3520* pArray)
{
    *(int*)pArray = (int)&DAT_0107b824;
    pArray->RemoveAll(true);
}

struct FUN_00820b50_shell
{
    void* GetFieldAt11C();
};

// @fnv 0x00820b50
void* FUN_00820b50_shell::GetFieldAt11C()
{
    return reinterpret_cast<char*>(this) + 0x11C;
}



// @fnv 0x00820bf0
MagicShaderHitEffect* PlayerCharacter::GetField6A4()
{
    return *(MagicShaderHitEffect**)((char*)this + 0x6a4);
}

struct ShaderBaseLoad
{
    void SaveLoad(ActiveEffect*, TESObjectREFR*);
};

struct FUN_0081bd30_s
{
    unsigned short GetSaveSize(ActiveEffect*, TESObjectREFR*);
};



extern TESSaveLoadGame* g_TESSaveLoadGame;



// Computes the save size for an active effect: base size from GetSaveSize plus 4, and if the save version is at least 0x37, adds 1 and 4 more.
// @fnv 0x00821dd0
unsigned short MagicShaderHitEffect::GetEffectSaveSize(ActiveEffect* aEffect, TESObjectREFR* aRefr)
{
    unsigned short isize = 0;
    isize += ((FUN_0081bd30_s*)this)->GetSaveSize(aEffect, aRefr);
    isize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x37)
    {
        isize += 1;
        isize += 4;
    }
    return isize;
}

namespace fnv_008225b0 {
struct Arr3520
{
    void* m_data;
    void RemoveAll(bool);
};
extern int DAT_010159d4;

struct FUN_008225b0_shell : Arr3520
{
    void UpdateState_008225b0();
};

// @fnv 0x008225b0
// src: GUESS 0x008225b0 (confidence: low)
void FUN_008225b0_shell::UpdateState_008225b0()
{
    m_data = &DAT_010159d4;
    RemoveAll(true);
}
}  // namespace fnv_008225b0

struct FUN_008225d0_shell
{
    void* __thiscall BSSimpleArray_Allocate(unsigned int param_1);
};

// Allocates a block of param_1 * 4 bytes via operator new and returns the pointer.
// @fnv 0x008225d0
// src: COMMUNITY 0x008225d0
void* __thiscall FUN_008225d0_shell::BSSimpleArray_Allocate(unsigned int param_1)
{
    void* result = operator new(param_1 * 4);
    return result;
}

struct AX
{
    unsigned int vtable;
    void __thiscall BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};

// src: XBOX_PDB 0x006b3eb0
void __thiscall AX::BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int)
{}

extern unsigned int DAT_0107b84c;

struct FUN_00822600_shell : AX
{
    AX* __thiscall InitVtable();
};

// Sets the object's vtable to DAT_0107b84c, calls FUN_006b3eb0 with 0, 0, and returns this as an AX pointer.
// @fnv 0x00822600
AX* __thiscall FUN_00822600_shell::InitVtable()
{
    vtable = (unsigned int)&DAT_0107b84c;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return (AX*)this;
}

namespace fnv_00822630 {
struct GlobalObject_00869f00
{
    int* m_data;
    void Clear(bool);
    void UpdateState_00822630();
};

extern int DAT_0107b84c;

// @fnv 0x00822630
// src: GUESS 0x00822630 (confidence: low)
void GlobalObject_00869f00::UpdateState_00822630()
{
    m_data = &DAT_0107b84c;
    Clear(true);
}
}  // namespace fnv_00822630

TESEffectShader* __cdecl MagicSystem_GetDetectLifeShaderEffect(void);

// @fnv 0x00822010
// src: COMMUNITY 0x00822010
bool MagicShaderHitEffect::CheckShouldSave_00822010()
{
    if (pEffect != 0)
        return false;
    if (pTarget == 0 || m_pEffectShader == 0 || m_bUseActorParticleEffects || m_pEffectShader == MagicSystem_GetDetectLifeShaderEffect())
        return false;
    return true;
}

extern int DAT_0107b824;
struct Caller00822860
{
    void BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(unsigned int, bool);
};
struct FUN_00822530_shell
{
    void* vtable;
    FUN_00822530_shell* InitializeArrayView();
};
// Sets the object's vtable to DAT_0107b824, calls FUN_00822860 with 0 and false, and returns this.
// @fnv 0x00822530
// src: GUESS 0x00822530 (confidence: medium)
FUN_00822530_shell* FUN_00822530_shell::InitializeArrayView()
{
    vtable = &DAT_0107b824;
    reinterpret_cast<Caller00822860*>(this)->BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(0, false);
    return this;
}

void __fastcall Object_ResetVirtualTableAndRemoveAll(void*);
void __cdecl _Deallocate(void*);
struct S008226F0
{
    void* FUN_008226f0(unsigned int);
};
// @fnv 0x008226f0
void* S008226F0::FUN_008226f0(unsigned int flags)
{
    Object_ResetVirtualTableAndRemoveAll(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct ThisHolder
{
    void UpdateState_008225b0();
    void* FUN_00822720(unsigned int);
};
// Calls FUN_008225b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00822720
void* ThisHolder::FUN_00822720(unsigned int flags)
{
    UpdateState_008225b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Struct00822750
{
    void UpdateState_00822630();
    void* FUN_00822750(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00822630, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00822750
void* Struct00822750::FUN_00822750(unsigned int flags)
{
    UpdateState_00822630();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0087d230 {
struct Arr3520
{
    virtual ~Arr3520();
    void RemoveAll(bool);
};
struct FUN_008225b0 : Arr3520
{
    virtual ~FUN_008225b0();
};
struct FUN_0087d230 : FUN_008225b0
{
    virtual ~FUN_0087d230();
};
// @fnv 0x0087d230
FUN_0087d230::~FUN_0087d230()
{
    Arr3520::RemoveAll(true);
}
}  // namespace fnv_0087d230

struct FUN_00820bd0_shell
{
    void SetByteAtOffset6C(unsigned char a);
};

// @fnv 0x00820bd0
void FUN_00820bd0_shell::SetByteAtOffset6C(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x6c) = aucValue;
}

struct FUN_0081be80_s
{
    void MagicHitEffect_SaveGameBGS(BGSSaveFormBuffer*);
};

// @fnv 0x00822250
// src: COMMUNITY 0x00822250
void MagicShaderHitEffect::SaveGameBGS_00822250(BGSSaveFormBuffer* pBuffer)
{
    reinterpret_cast<FUN_0081be80_s*>(this)->MagicHitEffect_SaveGameBGS(pBuffer);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x28, 1, 0);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x34, 4, 0);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x60, 4, 0);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x64, 4, 0);
    pBuffer->SaveData(reinterpret_cast<char*>(this) + 0x4c, 1, 0);
    pBuffer->SerializeFormData(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[0x2c / 4]), 0);
    pBuffer->SerializeFormData(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[0x30 / 4]), 0);
}


// Computes a size: starts at 0, adds 4 twice, then adds the result of GetSaveSize(0, pTarget), and returns it.
// @fnv 0x00822060
// src: GUESS 0x00822060 (confidence: medium)
unsigned short MagicShaderHitEffect::GetReferenceSaveSize()
{
    unsigned short isize;
    isize = 0;
    isize += 4;
    isize += 4;
    isize += GetSaveSize(0, pTarget);
    return isize;
}

// Returns the process light intensity when a process is set, otherwise returns 1.0f.
// @fnv 0x008c4850
// src: XBOX_PDB 0x008c4850
float Actor::GetAlphaMult()
{
    return m_pBaseProcess ? m_pBaseProcess->GetLightIntensity() : 1.0f;
}

struct ShaderBaseSave
{
    void MagicHitEffect_SaveGame(ActiveEffect*, TESObjectREFR*);
};

namespace fnv_00821e40 {
extern TESSaveLoadGame* g_TESSaveLoadGame;



}  // namespace fnv_00821e40

// @fnv 0x00821e40
// src: COMMUNITY 0x00821e40
void MagicShaderHitEffect::SaveGame_00821e40(ActiveEffect* pEffect, TESObjectREFR* a2)
{
    reinterpret_cast<ShaderBaseSave*>(this)->MagicHitEffect_SaveGame(pEffect, a2);
    fnv_00821e40::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 0x34, 4);
    if (fnv_00821e40::g_TESSaveLoadGame->FUN_008df040() >= 0x37)
    {
        fnv_00821e40::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 0x28, 1);
        int v = 0;
        if (m_pAffectedArmorObject)
            v = m_pAffectedArmorObject->GetFormID();
        fnv_00821e40::g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID(&v, 4);
    }
}

struct FUN_0081bed0_s
{
    void LoadFormData(BGSLoadFormBuffer*);
};

struct TESBoundObject;
TESForm* GetFormByID(unsigned int);
// Loads the base form data, then reads several fields from the buffer and resolves two form IDs into a TESBoundObject and a TESEffectShader.
// @fnv 0x008222f0
// src: XBOX_PDB 0x008222f0
void MagicShaderHitEffect::LoadGame_008222f0(BGSLoadGameBuffer* buffer)
{
    reinterpret_cast<FUN_0081bed0_s*>(this)->LoadFormData((BGSLoadFormBuffer*)buffer);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((char*)this + 0x28, 1);
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((char*)this + 0x34, 4);
    if (buffer->GetVersion() >= 8)
    {
        ((BGSLoadFormBuffer*)buffer)->ReadTypedData((char*)this + 0x60, 4);
        ((BGSLoadFormBuffer*)buffer)->ReadTypedData((char*)this + 0x64, 4);
    }
    ((BGSLoadFormBuffer*)buffer)->ReadTypedData((char*)this + 0x4c, 1);
    *(TESBoundObject**)((char*)this + 0x2c) =
        dynamic_cast<TESBoundObject*>(GetFormByID(buffer->ReadFormIdentifier()));
    *(TESEffectShader**)((char*)this + 0x30) =
        dynamic_cast<TESEffectShader*>(GetFormByID(buffer->ReadFormIdentifier()));
}

extern unsigned int __cdecl RandomUnsignedInt(void*);

struct FUN_00822650_shell : InventoryItem
{
    unsigned int FindFirstItemExceedingRemaining();
};

// @fnv 0x00822650
unsigned int FUN_00822650_shell::FindFirstItemExceedingRemaining()
{
    unsigned int result = 0;
    bool found = false;
    unsigned int remaining = RandomUnsignedInt(*(void**)((char*)this + 0x20));
    for (unsigned int i = 0; i < (unsigned int)GetObject() && !found; ++i)
    {
        if (remaining < ((BSSimpleArray<unsigned int>*)((char*)this + 0x10))->GetAt(static_cast<int>(i)))
        {
            result = ((BSSimpleArray<unsigned int>*)this)->GetAt(static_cast<int>(i));
            found = true;
        }
        remaining -= ((BSSimpleArray<unsigned int>*)((char*)this + 0x10))->GetAt(static_cast<int>(i));
    }
    return result;
}

namespace fnv_00695230 {
typedef void* NavMeshPtr;

struct Elem4
{
    unsigned int value;
};

struct Arr3520
{
    void RemoveAll(bool);
};

struct S2f850
{
    void BSSimpleArray_NavMeshPtr_1024_ConstructItems(NavMeshPtr*, int);
};

struct FUN_0042fc00_shell
{
    void FUN_0042fc00(void*, unsigned int);
};

struct FUN_006c6200_cls
{
    void FUN_00822820(Elem4*, unsigned int);
};

struct FUN_00695230_shell
{
    virtual void unused()
    {}
    virtual void* allocate(unsigned int)
    {
        return 0;
    }

    void* data;
    unsigned int count;
    unsigned int capacity;

    void BSSimpleArray_NiPointer_1024_SetSize(unsigned int, bool);
};

// Resizes the container to index elements: clears when index is 0, grows or shrinks the buffer and adjusts count and capacity.
// @fnv 0x00695230
// src: COMMUNITY 0x00695230
void FUN_00695230_shell::BSSimpleArray_NiPointer_1024_SetSize(unsigned int uiNewSize, bool flag)
{
    if (uiNewSize == 0)
    {
        reinterpret_cast<Arr3520*>(this)->RemoveAll(flag);
        return;
    }

    if (uiNewSize > capacity)
    {
        if (capacity == 0)
        {
            data = reinterpret_cast<Elem4*>(allocate(uiNewSize));
            capacity = uiNewSize;
        }
        else
        {
            reinterpret_cast<FUN_0042fc00_shell*>(this)->FUN_0042fc00(reinterpret_cast<void*>(uiNewSize), count);
            capacity = uiNewSize;
        }

        reinterpret_cast<S2f850*>(this)->BSSimpleArray_NavMeshPtr_1024_ConstructItems(
            reinterpret_cast<NavMeshPtr*>(static_cast<unsigned char*>(data) + count * sizeof(Elem4)),
            uiNewSize - count);
        count = uiNewSize;
    }
    else if (uiNewSize < count)
    {
        reinterpret_cast<FUN_006c6200_cls*>(this)->FUN_00822820(
            reinterpret_cast<Elem4*>(static_cast<unsigned char*>(data) + uiNewSize * sizeof(Elem4)), count - uiNewSize);
        count = uiNewSize;

        if (flag && uiNewSize <= capacity / 4)
        {
            reinterpret_cast<FUN_0042fc00_shell*>(this)->FUN_0042fc00(reinterpret_cast<void*>(uiNewSize), uiNewSize);
            capacity = uiNewSize;
        }
    }
    else
    {
        reinterpret_cast<S2f850*>(this)->BSSimpleArray_NavMeshPtr_1024_ConstructItems(
            reinterpret_cast<NavMeshPtr*>(static_cast<unsigned char*>(data) + count * sizeof(Elem4)),
            uiNewSize - count);
        count = uiNewSize;
    }
}
}  // namespace fnv_00695230

struct MI_0081c630
{
    TESChallenge* GetEffectSettingForRange(int);
};



// @fnv 0x00821f70
void MagicShaderHitEffect::InitHitEffect(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData)
{
    bool btempFinished;
    float ftempAge;

    DoNothing_008d05e0(apEffect, apTarget, 0);

    if (apEffect != 0)
    {
        m_pEffectShader = reinterpret_cast<TESEffectShader*>(reinterpret_cast<MI_0081c630*>(reinterpret_cast<InventoryItem*>(apEffect)->GetObject())
                              ->GetEffectSettingForRange(0)
                              ->GetFormTwo());
    }
    else
    {
        m_pEffectShader = static_cast<TESEffectShader*>(apData);
    }

    ftempAge = m_fFirstFloatValue;
    btempFinished = bWasPlaying;

    Init();

    m_fFirstFloatValue = ftempAge;
    bWasPlaying = btempFinished;

    Update(0.0f);
}







// Initializes an effect-shader hit effect: stores the shader and duration, sets up third-person state for the player, and loads the shader's addon models.
// @fnv 0x0081f580
MagicShaderHitEffect::MagicShaderHitEffect(TESObjectREFR* apTarget, TESEffectShader* apShader, float afDuration)
    : MagicHitEffect(apTarget, 0), m_pParticleShaderNode(0), spTexEffectData(0)
{
    m_pEffectShader = apShader;
    m_fEffectShaderScale = 0.0f;
    spTexEffectData = 0;
    m_pParticleShaderNode = 0;
    m_bUseActorParticleEffects = false;
    m_pAffectedArmorObject = 0;
    m_fAddonModelTimer = 1.0f;
    m_fAddonModelScale = 1.0f;
    if (pTarget == g_thePlayer)
    {
        b3rdPerson = g_thePlayer->GetNode(false) && !g_thePlayer->GetNode(false)->GetAppCulled_00456610();
    }
    else
    {
        b3rdPerson = false;
    }
    if (afDuration < 0.0)
    {
        m_fParticleParameter5 = 3.402823466e+38f;
    }
    else
    {
        m_fParticleParameter5 = afDuration;
    }
    if (m_pEffectShader && m_pEffectShader->GetAddonModels())
    {
        BSSimpleList<DebrisModelEntry*>* pIter = m_pEffectShader->GetAddonModels()->GetData();
        while (pIter && !pIter->IsEmpty())
        {
            g_modelLoader->LoadFile(pIter->GetItem()->filename, 0, true, false, false, false);
            pIter = pIter->GetNext();
        }
    }
}

struct FUN_008220c0_mgr
{
    void TESSaveLoadGame_SaveNumericID(unsigned int* p, int n);
};
extern FUN_008220c0_mgr* DAT_011de45c;
unsigned int __fastcall GetHavokWorldObjectCountInSceneGraph_0084e3a0(void* p);



// Writes the values returned by FUN_0084e3a0 for m_1c and m_30 to DAT_011de45c, then calls v53(0, m_1c).
// @fnv 0x008220c0
// src: COMMUNITY 0x008220c0
void MagicShaderHitEffect::SaveGameTES_008220c0()
{
    unsigned int a = (unsigned int)GetHavokWorldObjectCountInSceneGraph_0084e3a0(pTarget);
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&a, 4);
    unsigned int b = (unsigned int)GetHavokWorldObjectCountInSceneGraph_0084e3a0(m_pEffectShader);
    DAT_011de45c->TESSaveLoadGame_SaveNumericID(&b, 4);
    SaveGame(0, pTarget);
}



struct ShaderBaseApplyLoad
{
    void FUN_009dace0(void*);
};

// Calls FUN_009dace0 with a1, saves m_20 and m_24, calls vfn_c4, restores both fields, then calls vfn_94(0.0f).
// @fnv 0x008223d0
// src: GUESS 0x008223d0 (confidence: medium)
void MagicShaderHitEffect::LoadPreservingPlaybackState(unsigned int a1)
{
    float saved;
    unsigned char savedFlag;
    reinterpret_cast<ShaderBaseApplyLoad*>(this)->FUN_009dace0((void*)a1);
    saved = m_fFirstFloatValue;
    savedFlag = bWasPlaying;
    Init();
    m_fFirstFloatValue = saved;
    *reinterpret_cast<unsigned char*>(&bWasPlaying) = savedFlag;
    Update(0.0f);
}

struct HitEffShaderSource
{
    TESEffectShader* GetEffectShader();
};

struct HitEffEffectSetting : EffectSetting
{
    HitEffShaderSource* GetShaderSource(int aiIndex);
};

struct HitEffActiveEffect : ActiveEffect
{
    HitEffEffectSetting* GetHitEffectSetting();
};







// @fnv 0x0081f350
MagicShaderHitEffect::MagicShaderHitEffect(TESObjectREFR* apTarget, ActiveEffect* apEffect)
    : MagicHitEffect(apTarget, apEffect), m_pParticleShaderNode(0), spTexEffectData(0)
{
    m_pEffectShader = 0;
    m_pEffectShader =
        static_cast<HitEffActiveEffect*>(apEffect)->GetHitEffectSetting()->GetShaderSource(0)->GetEffectShader();
    m_fEffectShaderScale = 0.0f;
    spTexEffectData = 0;
    m_pParticleShaderNode = 0;
    m_bUseActorParticleEffects = false;
    m_pAffectedArmorObject = 0;
    m_fAddonModelTimer = 1.0f;
    m_fAddonModelScale = 1.0f;
    if (pTarget == (TESObjectREFR*)g_thePlayer)
        b3rdPerson = g_thePlayer->GetNode(false) && !g_thePlayer->GetNode(false)->GetAppCulled_00456610();
    else
        b3rdPerson = false;

    if (false)
    {
        DisintegrateArmorEffect* pDisintegrate = dynamic_cast<DisintegrateArmorEffect*>(GetEffect());
        if (pDisintegrate)
        {
            InventoryItem* pItem = pDisintegrate->GetItem();
            if (pItem)
                m_pAffectedArmorObject = pItem->GetObject();
        }
    }

    if (m_pEffectShader && m_pEffectShader->GetAddonModels())
    {
        BSSimpleList<DebrisModelEntry*>* pIter = m_pEffectShader->GetAddonModels()->GetData();
        while (pIter && !pIter->IsEmpty())
        {
            g_modelLoader->LoadFile(pIter->GetItem()->filename, 0, true, false, false, false);
            pIter = pIter->GetNext();
        }
    }
}

struct xDays
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void Detach(struct xProc* p);
};

struct xProc
{
    xDays* GetDays();
};

template <class T> struct xPtr
{
    T* m_pObject;
    operator T*() const;
    bool operator!=(T* p) const;
    void operator=(T* p);
    ~xPtr();
};

template <class T> struct xArr
{
    T* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiAlloc;
    unsigned int m_uiGrow;
    unsigned int GetSize();
    T& GetAt(int i);
    void RemoveAll(bool b);
    ~xArr();
};

template <class T> struct xArr2
{
    T* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiAlloc;
    unsigned int m_uiGrow;
    int m_iPad[2];
    unsigned int GetSize();
    T& GetAt(int i);
    ~xArr2();
};





struct xAudio
{
    static xAudio* Get();
    void Play(NiNode* n, float f, int i);
};

struct xLoader
{
    void Queue(const char* p);
};

// Retain the destructor view: using the shared base destructor in 0x0081F770
// conflicts with its existing binding (0x008646F0 instead of 0x0081B7B0).
struct xEffectBase
{
    virtual void v000();
    char _pad04[0x18];
    TESObjectREFR* m_pReference;
    char _pad20[0x10];
    TESEffectShader* m_pForm;
    int m_34;
    int GetID();
    ~xEffectBase();
};

struct FUN_0081f770 : xEffectBase
{
    xArr<xPtr<NiNode> > m_kNodeArray;
    xPtr<NiNode> m_spNode;
    int m_4c;
    xArr2<xPtr<xProc> > m_kProcs;
    xPtr<NiNode> m_spRootNode;
    ~FUN_0081f770();
};



extern xLoader* xg_pLoader;
extern "C" int __cdecl sprintf_s(char* buf, unsigned int size, const char* fmt, ...);

// @fnv 0x0081f770
FUN_0081f770::~FUN_0081f770()
{
    if (!GetID() & (m_pReference != g_thePlayer))
        m_pReference = 0;
    if (m_spRootNode)
    {
        if (m_pReference == g_thePlayer)
        {
            NiNode* pkNode = g_thePlayer->GetNode(1);
            if (pkNode)
                static_cast<ShaderTreeCleanup*>(m_pForm)->ClearItemRef(pkNode, reinterpret_cast<BSShaderPPLightingProperty::TextureEffectData*>((NiNode*)m_spRootNode));
            pkNode = g_thePlayer->GetNode(0);
            if (pkNode)
                static_cast<ShaderTreeCleanup*>(m_pForm)->ClearItemRef(pkNode, reinterpret_cast<BSShaderPPLightingProperty::TextureEffectData*>((NiNode*)m_spRootNode));
        }
        else if (m_pReference)
        {
            NiNode* pk3D = m_pReference->GetNiNode();
            if (pk3D)
                static_cast<ShaderTreeCleanup*>(m_pForm)->ClearItemRef(pk3D, reinterpret_cast<BSShaderPPLightingProperty::TextureEffectData*>((NiNode*)m_spRootNode));
        }
    }
    if (m_spNode != 0)
    {
        for (unsigned int i = 0; i < m_kNodeArray.GetSize(); i++)
            m_pForm->StopParticleShader(reinterpret_cast<NiAVObject*>((NiNode*)m_spNode), reinterpret_cast<ParticleShaderProperty*>((NiNode*)m_kNodeArray.GetAt(i)));
    }
    if (m_kProcs.GetSize() > 0)
    {
        for (unsigned int j = 0; j < m_kProcs.GetSize(); j++)
        {
            xProc* pkProc = m_kProcs.GetAt(j);
            if (pkProc->GetDays())
                pkProc->GetDays()->Detach(pkProc);
        }
    }
    m_kNodeArray.RemoveAll(true);
    if (m_spNode != 0)
        ((NiNode*)m_spNode)->AssignParent(0);
    m_spNode = 0;
    m_spRootNode = 0;
    if (m_pForm)
    {
        if (m_pReference && (m_pForm->GetFormID() == 0x852fe || m_pForm->GetFormID() == 0x84a51))
            xAudio::Get()->Play(m_pReference->GetNiNode(), 1.0f, 0);
        char acPath[260];
        if (m_pForm->GetFieldAt158()->GetTextureResourceName())
        {
            sprintf_s(acPath, 0x104, "%s\\%s", "Textures", m_pForm->GetFieldAt158()->GetTextureResourceName());
            g_TES->LoadCanopyShadowTexture(static_cast<const char*>(acPath), 0);
        }
        if (m_pForm->GetFieldAt14C()->GetTextureNameLength() > 0)
        {
            sprintf_s(acPath, 0x104, "%s\\%s", "Textures", m_pForm->GetFieldAt14C()->GetTextureResourceName());
            g_TES->LoadCanopyShadowTexture(static_cast<const char*>(acPath), 0);
        }
        if (m_pForm && m_pForm->GetAddonModels())
        {
            BSSimpleList<DebrisModelEntry*>* pkCond = m_pForm->GetAddonModels()->GetData();
            while (pkCond && !pkCond->IsEmpty())
            {
                xg_pLoader->Queue(pkCond->GetItem()->filename);
                pkCond = pkCond->GetNext();
            }
        }
    }
}

namespace ParticleUpdate {
struct Scene
{
    float GetFieldB4Float();
};
template <class T> struct Ref
{
    T* value;
    T* Modelloader_GetReferencedThis();
};
struct Property
{
    float FUN_006a78f0();
    void TileShaderProperty_SetTileAlpha(float);
    void BoltShaderProperty_SetBoltsRadius(float);
    void ParticleShaderProperty_UpdateParticles(float, bool, bool);
    int EffectSetting_GetLight();
};
template <class T> struct Array
{
    unsigned int unk0;
    T* data;
    unsigned int count;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    T& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
};
struct TestRef
{
    void* value;
    unsigned int unk4;
    bool FUN_0052aa80(int);
};
// TESEffectShader with the particle/texture-effect update members (0x00507da0 etc.) that TESEffectShader.h does not declare
struct EffectShaderUpdateView : TESEffectShader
{
    float TESEffectShader_BirthParticles(float, float, float, bool);
    float TESObjectWEAP_GetShotsPerSecond();
    float GetFootWeight();
    float GetFloatAt144();
    float GetValue();
    float TESEffectShader_GetAddOnScaleStart();
    float TESObjectWEAP_GetFiringRumbleRightMotorStrength();
    void UpdateShaderState(BSShaderPPLightingProperty::TextureEffectData*, float, float, float, bool);
};

bool NiObject_IsKindOf(void*, Scene*);
extern unsigned int DAT_011f9140;
extern double DAT_0106d508, DAT_01012060, DAT_0101a6b0;
extern float DAT_0106682c, DAT_01013ea4;
unsigned int FUN_00ba52d0();
float BSMIN(float, float);
float BSMAX_00404010(float, float);
void FUN_00b6bb30(NiNode*, float);

}  // namespace ParticleUpdate

struct ShaderHitEffectUpdateBase
{
    bool UpdateMagicHitEffect(float);
};

// Advances the effect timer, updates properties, addons and texture, and finishes the effect when all parts are done.
// @fnv 0x00820f30
bool MagicShaderHitEffect::Update(float afDeltaTime)
{
    if (!reinterpret_cast<ShaderHitEffectUpdateBase*>(this)->UpdateMagicHitEffect(afDeltaTime) || !pTarget || !pTarget->GetNiNode())
    {
        ResetTargetPointer();
        return false;
    }
    m_fEffectShaderScale += afDeltaTime;
    bool done = bWasPlaying;
    AttachToTarget();
    float multiplier = 1.0f;
    if (pTarget->IsActor() && m_pEffectShader != MagicSystem_GetDetectLifeShaderEffect())
    {
        if (static_cast<BSShaderPPLightingProperty::TextureEffectData*>(spTexEffectData) && static_cast<NiSourceTexture*>(static_cast<BSShaderPPLightingProperty::TextureEffectData*>(spTexEffectData)->spTexture) && pTarget->IsActor() &&
            static_cast<Actor*>(pTarget)->GetAlphaMult() > ParticleUpdate::DAT_0106d508)
        {
            static_cast<Actor*>(pTarget)->GetLightIntensity(ParticleUpdate::DAT_0106682c);
            static_cast<Actor*>(pTarget)->UpdateActorPresentation();
        }
        ParticleUpdate::Scene* scene = reinterpret_cast<ParticleUpdate::Scene*>(pTarget->GetNiNode());
        if (ParticleUpdate::NiObject_IsKindOf(&ParticleUpdate::DAT_011f9140, scene))
        {
            ParticleUpdate::Scene* castScene = scene;
            multiplier = castScene->GetFieldB4Float();
        }
        else
        {
            // The shared declaration for slot 0x420 is void; preserve its x87 float result.
            static_cast<Actor*>(pTarget)->Unk_108();
            __asm fstp multiplier
        }
        float actorScale = static_cast<Actor*>(pTarget)->GetAlphaMult();
        if (actorScale > ParticleUpdate::DAT_01012060)
            multiplier /= actorScale;
    }
    if (m_kParticleShaderProperties.GetSize() > 0 && reinterpret_cast<ParticleUpdate::TestRef*>(&m_pParticleShaderNode)->FUN_0052aa80(0))
    {
        float total = 0.0f;
        for (unsigned int index = 0; index < m_kParticleShaderProperties.GetSize(); index++)
            total += reinterpret_cast<ParticleUpdate::Property*>(static_cast<ParticleShaderProperty*>(m_kParticleShaderProperties.GetAt(index)))->FUN_006a78f0() * ParticleUpdate::FUN_00ba52d0();
        float available = static_cast<ParticleUpdate::EffectShaderUpdateView*>(m_pEffectShader)->TESEffectShader_BirthParticles(total, afDeltaTime, m_fEffectShaderScale, bWasPlaying);
        if (available > ParticleUpdate::DAT_01012060)
            done = false;
        for (unsigned int index2 = 0; index2 < m_kParticleShaderProperties.GetSize(); index2++)
        {
            float amount = ParticleUpdate::BSMIN(available, float(ParticleUpdate::FUN_00ba52d0()));
            available -= amount;
            ParticleUpdate::Property* propertySlot1 = reinterpret_cast<ParticleUpdate::Property*>(static_cast<ParticleShaderProperty*>(m_kParticleShaderProperties.GetAt(index2)));
            propertySlot1->TileShaderProperty_SetTileAlpha(amount / ParticleUpdate::FUN_00ba52d0());
            propertySlot1->BoltShaderProperty_SetBoltsRadius(multiplier);
            propertySlot1->ParticleShaderProperty_UpdateParticles(m_fEffectShaderScale, false, true);
            if (propertySlot1->EffectSetting_GetLight() > 0)
                done = false;
        }
        if (m_kAddonModelObjects.GetSize() > 0)
        {
            float delta = afDeltaTime / (!bWasPlaying ? static_cast<ParticleUpdate::EffectShaderUpdateView*>(m_pEffectShader)->TESObjectWEAP_GetShotsPerSecond() : static_cast<ParticleUpdate::EffectShaderUpdateView*>(m_pEffectShader)->GetFootWeight() * ParticleUpdate::DAT_0101a6b0);
            m_fAddonModelTimer = ParticleUpdate::BSMAX_00404010(0.0f, ParticleUpdate::BSMIN(1.0f, m_fAddonModelTimer + delta));
            if (m_fAddonModelTimer > ParticleUpdate::DAT_01012060)
                done = false;
            delta = afDeltaTime / (!bWasPlaying ? static_cast<ParticleUpdate::EffectShaderUpdateView*>(m_pEffectShader)->GetFloatAt144() : static_cast<ParticleUpdate::EffectShaderUpdateView*>(m_pEffectShader)->GetValue() * ParticleUpdate::DAT_0101a6b0);
            m_fAddonModelScale = ParticleUpdate::BSMAX_00404010(0.0f, ParticleUpdate::BSMIN(1.0f, m_fAddonModelScale + delta));
            float maximumSlot16 = 1.0f;
            float minimum = !bWasPlaying ? ParticleUpdate::BSMAX_00404010(ParticleUpdate::DAT_01013ea4, static_cast<ParticleUpdate::EffectShaderUpdateView*>(m_pEffectShader)->TESEffectShader_GetAddOnScaleStart())
                                      : ParticleUpdate::BSMAX_00404010(ParticleUpdate::DAT_01013ea4, static_cast<ParticleUpdate::EffectShaderUpdateView*>(m_pEffectShader)->TESObjectWEAP_GetFiringRumbleRightMotorStrength());
            float factorSlot13 = minimum + (maximumSlot16 - minimum) * m_fAddonModelScale;
            for (unsigned int index3 = 0; index3 < m_kAddonModelObjects.GetSize(); index3++)
            {
                ParticleUpdate::FUN_00b6bb30(static_cast<NiAVObject*>(m_kAddonModelObjects.GetAt(index3))->IsSceneNode(), m_fAddonModelTimer);
                static_cast<NiAVObject*>(m_kAddonModelObjects.GetAt(index3))->NiAVObject_SetScale(factorSlot13);
            }
        }
    }
    if (static_cast<BSShaderPPLightingProperty::TextureEffectData*>(spTexEffectData))
    {
        static_cast<ParticleUpdate::EffectShaderUpdateView*>(m_pEffectShader)->UpdateShaderState(static_cast<BSShaderPPLightingProperty::TextureEffectData*>(spTexEffectData), afDeltaTime, m_fEffectShaderScale, m_fFirstFloatValue, bWasPlaying);
        *reinterpret_cast<float*>(static_cast<BSShaderPPLightingProperty::TextureEffectData*>(spTexEffectData)->data + 0x18) *= multiplier;
        *reinterpret_cast<float*>(static_cast<BSShaderPPLightingProperty::TextureEffectData*>(spTexEffectData)->data + 0x28) *= multiplier;
        if (*reinterpret_cast<float*>(static_cast<BSShaderPPLightingProperty::TextureEffectData*>(spTexEffectData)->data + 0x48) > ParticleUpdate::DAT_01012060 || *reinterpret_cast<float*>(static_cast<BSShaderPPLightingProperty::TextureEffectData*>(spTexEffectData)->data + 0x38) > ParticleUpdate::DAT_01012060)
            done = false;
    }
    if (bWasPlaying && done)
    {
        if (pTarget->IsActor() && static_cast<Actor*>(pTarget)->GetProcess())
            static_cast<Actor*>(pTarget)->GetProcess()->UpdateActorAppearance(true, true, false);
        ResetTargetPointer();
        return false;
    }
    return true;
}

template <class T> struct ShaderPointerInequality : NiPointer<T>
{
    bool operator!=(int) const;
};



struct BSAudioX_821bd0
{
    void BSAudio_StopMovingSounds(NiNode*, float, bool);
};



// Applies the shader effect to the target's nodes, plays a sound for certain shader types, then clears the effect data and target.
// @fnv 0x00821bd0
void MagicShaderHitEffect::ApplyAndCleanup()
{
    if (pTarget && m_pEffectShader &&
        (GetHavokWorldObjectCountInSceneGraph_0084e3a0(m_pEffectShader) == 0x852fe || GetHavokWorldObjectCountInSceneGraph_0084e3a0(m_pEffectShader) == 0x84a51))
        ((BSAudioX_821bd0*)BSAudio::GetSingleton())->BSAudio_StopMovingSounds(pTarget->GetNiNode(), 1.0f, false);

    if (spTexEffectData)
    {
        if (pTarget == g_thePlayer)
        {
            NiNode* pNode = g_thePlayer->GetNode(true);
            if (pNode)
                static_cast<ShaderTreeCleanup*>(m_pEffectShader)->ClearItemRef(pNode, spTexEffectData);
            pNode = g_thePlayer->GetNode(false);
            if (pNode)
                static_cast<ShaderTreeCleanup*>(m_pEffectShader)->ClearItemRef(pNode, spTexEffectData);
        }
        else if (pTarget)
        {
            NiNode* pRoot = pTarget->GetNiNode();
            if (pRoot)
                static_cast<ShaderTreeCleanup*>(m_pEffectShader)->ClearItemRef(pRoot, spTexEffectData);
        }
    }

    if (reinterpret_cast<const ShaderPointerInequality<NiNode>&>(m_pParticleShaderNode) != 0)
    {
        for (unsigned int i = 0; i < m_kParticleShaderProperties.GetSize(); i++)
            m_pEffectShader->StopParticleShader(m_pParticleShaderNode, m_kParticleShaderProperties.GetAt(i));
    }
    m_kParticleShaderProperties.RemoveAll(true);
    if (reinterpret_cast<const ShaderPointerInequality<NiNode>&>(m_pParticleShaderNode) != 0)
        ((NiAVObject*)m_pParticleShaderNode)->AssignParent(0);
    m_pParticleShaderNode = 0;
    spTexEffectData = 0;
    pTarget = 0;
}

extern unsigned char DAT_011f4428;
extern "C" NiNode* __cdecl NiObject_DynamicCast(const void*, NiAVObject*);

// These out-of-line matrix operations use a trivial copy; the shared matrix
// declares a separate copy constructor.
struct ShaderEffectMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ShaderEffectMatrix Transpose() const;
    ShaderEffectMatrix operator*(const ShaderEffectMatrix& rhs) const;
    NiPoint3 operator*(const NiPoint3& pt) const;
};

struct PtrCheck
{
    bool operator!=(int) const;
};

class EffView : public MagicShaderHitEffect
{
  public:
    TESObjectREFR* GetTarget();
    void MagicHitEffect_UpdateParentCell(NiAVObject*);
};

// @fnv 0x008217e0
void __fastcall UpdateEffectNode(EffView* pEffectView)
{
    bool bInitTmp = (pEffectView->GetTarget() == g_thePlayer);
    bool pTargetObj5 = (bInitTmp && g_thePlayer != 0 && g_thePlayer->GetField6A4() == pEffectView) ? 1 : 0;
    bool pActor1 = (bInitTmp && g_thePlayer != 0 && g_thePlayer->GetNode(false) != 0 &&
                    g_thePlayer->GetNode(false)->GetAppCulled_00456610())
                       ? 1
                       : 0;
    NiAVObject* pRef4 = 0;
    if (!pEffectView->m_bUseActorParticleEffects)
    {
        if (bInitTmp)
        {
            pRef4 = g_thePlayer->GetNode(false);
        }
        else
        {
            pRef4 = pEffectView->pTarget->GetNiNode();
        }
    }
    else
    {
        float f_j;
        bool b_k;
        NiAVObject* p1_j;
        NiAVObject* p2_c;
        pEffectView->GetSceneGraphData(b_k, b_k, f_j, p1_j, p2_c);
        pRef4 = p2_c;
    }

    if (((PtrCheck*)&pEffectView->m_pParticleShaderNode)->operator!=(0) && pRef4 != 0)
    {
        ShaderEffectMatrix mat = pEffectView->m_bUseActorParticleEffects ? reinterpret_cast<const ShaderEffectMatrix&>(pRef4->NiAVObject_GetWorldRotate())
                                                                : *(const ShaderEffectMatrix*)&DAT_011a9448;
        if (pTargetObj5)
        {
        }
        else
        {
            if (pActor1 && g_thePlayer->GetNode(true) != 0)
            {
                NiNode* pCastNode = NiObject_DynamicCast(&DAT_011f4428, g_thePlayer->GetNode(true));
                if (pCastNode != 0 && pCastNode != pEffectView->m_pParticleShaderNode->GetParent())
                {
                    pCastNode->AttachChildInAvailableSlot(static_cast<NiAVObject*>(pEffectView->m_pParticleShaderNode), true);
                }
                if (pActor1)
                {
                    pEffectView->m_pParticleShaderNode->SetRotate_0043fa80(
                        &(reinterpret_cast<const ShaderEffectMatrix&>(pEffectView->m_pParticleShaderNode->GetParent()->NiAVObject_GetWorldRotate()).Transpose() *
                          static_cast<const ShaderEffectMatrix&>(mat)));
                    ((NiAVObject*)pEffectView->m_pParticleShaderNode)
                        ->NiAVObject_SetTranslate(
                            reinterpret_cast<const ShaderEffectMatrix&>(
                                pEffectView->m_pParticleShaderNode->GetParent()->NiAVObject_GetWorldRotate())
                                .Transpose() *
                            (pRef4->NiAVObject_GetWorldTranslate() - pEffectView->m_pParticleShaderNode->GetParent()->NiAVObject_GetWorldTranslate()));
                    NiUpdateData updateData(0.0f, false, false);
                    pEffectView->m_pParticleShaderNode->Update(updateData);
                }
                else
                {
                    pEffectView->m_pParticleShaderNode->SetRotate_0043fa80(&mat);
                    ((NiAVObject*)pEffectView->m_pParticleShaderNode)
                        ->NiAVObject_SetTranslate(pRef4->NiAVObject_GetWorldTranslate());
                }
            }
            else
            {
                ((NiAVObject*)pEffectView->m_pParticleShaderNode)
                    ->NiAVObject_SetTranslate(pRef4->NiAVObject_GetWorldTranslate());
                pEffectView->m_pParticleShaderNode->SetRotate_0043fa80(&mat);
            }
        }
    }

    if (pActor1 || pTargetObj5)
    {
        pEffectView->MagicHitEffect_UpdateParentCell(0);
    }
    else
    {
        pEffectView->MagicHitEffect_UpdateParentCell(pEffectView->m_pParticleShaderNode);
    }
}

namespace fnv_00822130 {
struct Node
{
    bool TESObjectCELL_GetAttached();
};
struct Manager
{
    void FUN_00857aa0(void**, int);
};
extern Manager* DAT_011de45c;
extern char DAT_011841cc, DAT_01183918, DAT_01183028;
TESForm* __cdecl TESForm_GetFormByNumericID(void*);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);

}  // namespace fnv_00822130

// Reads two 4-byte values, resolves reference and shader forms, calls vfnd8, and calls vfndc and vfne0 when both resolve.
// @fnv 0x00822130
// src: XBOX_PDB 0x00822130
bool MagicShaderHitEffect::LoadGame_00822130()
{
    bool result2 = true;
    void* firstB;
    fnv_00822130::DAT_011de45c->FUN_00857aa0(&firstB, 4);
    pTarget = dynamic_cast<TESObjectREFR*>(fnv_00822130::TESForm_GetFormByNumericID(firstB));
    if (!pTarget || !reinterpret_cast<fnv_00822130::Node*>(pTarget->GetParentCell()) || !reinterpret_cast<fnv_00822130::Node*>(pTarget->GetParentCell())->TESObjectCELL_GetAttached())
        result2 = false;
    void* second;
    fnv_00822130::DAT_011de45c->FUN_00857aa0(&second, 4);
    TESEffectShader* other7 = dynamic_cast<TESEffectShader*>(fnv_00822130::TESForm_GetFormByNumericID(second));
    if (!other7)
        result2 = false;
    LoadGame(0, pTarget);
    if (result2)
    {
        InitLoadGame(0, pTarget);
        FinishLoadGameTES(0, pTarget, other7);
    }
    return result2;
}

struct FUN_006e6da0
{
    int a;
};
void* __cdecl operator new(unsigned int uiSize, FUN_006e6da0* pPlace);
inline void __cdecl operator delete(void*, FUN_006e6da0*)
{}
class FUN_00633c90
{
  public:
    FUN_00633c90(int iArg);
    int unk0;
};
class ArrX
{
  public:
    void ConstructElements(FUN_006e6da0* pData, unsigned int ItemUpdateArray);
};
// @fnv 0x00822780
void ArrX::ConstructElements(FUN_006e6da0* pData, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        new (&pData[i]) FUN_00633c90(0);
    }
}

TESForm* GetFormByID(int);

extern TESSaveLoadGame* g_TESSaveLoadGame;

// Reads effect shader scale, particle effects flag, and affected armor object ID from the save stream.
// @fnv 0x00821ed0
// src: XBOX_PDB 0x00821ed0
void MagicShaderHitEffect::LoadGame_00821ed0(ActiveEffect* effect, TESObjectREFR* target)
{
    reinterpret_cast<ShaderBaseLoad*>(this)->SaveLoad(effect, target);
    g_TESSaveLoadGame->ReadTypedData(&m_fEffectShaderScale, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x37)
    {
        g_TESSaveLoadGame->ReadTypedData(&m_bUseActorParticleEffects, 1);
        unsigned int objectID;
        g_TESSaveLoadGame->FUN_00857aa0(&objectID, 4);
        if (objectID)
            m_pAffectedArmorObject = dynamic_cast<TESBoundObject*>(GetFormByID(objectID));
    }
}
