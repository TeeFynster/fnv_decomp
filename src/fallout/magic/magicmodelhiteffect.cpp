// fallout/magic/magicmodelhiteffect.cpp: MagicModelHitEffect (22 functions)

#include "../../../include/NiTPointerMap.h"
#include "../../../include/TESModel.h"
#include "../../../include/TES.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/BGSLoadGameSubBuffer.h"
#include "../../../include/BSTempEffect.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/MagicHitEffect.h"
#include "../../../include/MagicModelHitEffect.h"
#include "../../../include/NiControllerManager.h"
#include "../../../include/NiControllerSequence.h"
#include "../../../include/NiObjectNET.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/PlayerCharacter.h"
#include "magicmodelhiteffect_decls.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/MiddleHighProcess.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/NP.h"
#include "../../../include/Actor.h"
#include "../../../include/EffectItem.h"
#include "../../../include/TESSaveLoadGame.h"

struct Animation
{
    float FUN_00453700();
};

// @fnv 0x0081c950
bool MagicModelHitEffect::Init()
{
    if (reinterpret_cast<NiAVObject*>(this)->GetParent())
    {
        this->m_fFirstFloatValue = reinterpret_cast<ActiveEffect*>(reinterpret_cast<NiAVObject*>(this)->GetParent())->GetAge();
        this->bWasPlaying = !reinterpret_cast<ActiveEffect*>(reinterpret_cast<NiAVObject*>(this)->GetParent())
                                 ->GetEffectSetting()
                                 ->IsFlagSet(0x400);
    }

    if (this->pTarget)
    {
        if (this->pTarget->GetNiNode())
        {
            if (this->pTarget == reinterpret_cast<TESObjectREFR*>(g_thePlayer))
                this->b3rdPerson = g_thePlayer->FUN_004eaf60();

            if (this->pFilename)
            {
                if (*this->pFilename)
                {
                    NiNode* model = g_modelLoader->LoadFile(this->pFilename, 0, true, false, false, false);
                    if (model)
                    {
                        NiControllerManager* manager = reinterpret_cast<NiControllerManager*>(FUN_00653270(
                            &DAT_011f36ac,
                            reinterpret_cast<NiProperty*>(reinterpret_cast<NiObjectNET*>(model)->GetControllers())));
                        if (manager)
                        {
                            NiControllerSequence* sequence;
                            sequence = manager->FindSequenceByName(NiFixedString(kMagicModelHitEffectName));
                            if (!sequence)
                                return false;
                        }
                    }

                    this->spRetainedObject = LoadAndCloneModel(this->pFilename);
                    g_modelLoader->QueueModelLoad(this->pFilename, false, 1);
                    if (reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())
                    {
                        if (this->pTarget->GetNiNode())
                        {
                            this->AttachToTarget();
                            FUN_00c4b500(reinterpret_cast<NiAVObject*>(
                                reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->()));

                            {
                                NiUpdateData map(
                                    static_cast<float>(static_cast<double>(g_timeGlobal.GetTimeStamp()) / 1000.0), true,
                                    false);
                                reinterpret_cast<NiAVObject*>(
                                    reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())
                                    ->Update(map);
                            }

                            NiControllerManager* targetManager = reinterpret_cast<NiControllerManager*>(FUN_00653270(
                                &DAT_011f36ac,
                                reinterpret_cast<NiProperty*>(
                                    reinterpret_cast<NiObjectNET*>(
                                        reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())
                                        ->GetControllers())));
                            if (targetManager)
                            {
                                NiControllerSequence* targetSequence;
                                targetSequence =
                                    targetManager->FindSequenceByName(NiFixedString(kMagicModelHitEffectName));
                                if (targetSequence)
                                {
                                    targetManager->DeactivateAllSequences(0.0f);
                                    targetManager->ActivateControllerSequence(targetSequence, 0, false, 1.0f, 0.0f, (NiControllerSequence*)0);
                                    targetManager->FUN_0047aa40(true);
                                    if (this->m_fFirstFloatValue > 0.0f)
                                        targetSequence->SetSequenceTime(this->m_fFirstFloatValue, false);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

struct MI_0081c630
{
    EffectSetting* GetEffectSettingForRange(int);
};

// Initializes the base, clears the retained objects and flags, and selects the effect model path.
// @fnv 0x0081c630
MagicModelHitEffect::MagicModelHitEffect(TESObjectREFR* ref, ActiveEffect* ae) : MagicHitEffect(ref, ae), spRetainedObject(0), m_spTargetObject(0)
{
    spRetainedObject = static_cast<NiAVObject*>(0);
    m_spTargetObject = static_cast<NiAVObject*>(0);
    b3rdPerson = false;
    pFilename = 0;
    pFilename = reinterpret_cast<TESModel*>(reinterpret_cast<char*>(((MI_0081c630*)ae->FUN_0044ddc0())->GetEffectSettingForRange(0)) + sizeof(TESForm))->GetModelFilePath();
    m_bFirstPerson = false;
}

// This unit emits the load-form destructor as a forwarding call to the base.
// @fnv 0x0081db90 (implicit destructor)
struct ModelEffectLoadFormBuffer : BGSLoadGameBuffer
{
};

extern const NiRTTI g_011dc724;

// @fnv 0x0081c5f0
const NiRTTI* MagicModelHitEffect::GetRTTI() const
{
    return &g_011dc724;
}

extern double _gModifierZero;

// Initialises the effect with the target, filename and lifetime (clamped to FLT_MAX when negative), clearing the object and clone pointers.
// @fnv 0x0081c720
MagicModelHitEffect::MagicModelHitEffect(TESObjectREFR* apTarget, const char* apFilename, float afLifetime)
    : MagicHitEffect(apTarget, 0), spRetainedObject(0), m_spTargetObject(0)
{
    spRetainedObject = static_cast<NiAVObject*>(0);
    m_spTargetObject = static_cast<NiAVObject*>(0);
    b3rdPerson = false;
    pFilename = apFilename;
    m_bFirstPerson = false;
    if (afLifetime < _gModifierZero)
    {
        m_fParticleParameter5 = 3.402823466e+38F;
    }
    else
    {
        m_fParticleParameter5 = afLifetime;
    }
}

struct Flt
{
    operator unsigned int() const;
};
unsigned short __cdecl FUN_0055fdb0(NiControllerManager*);
// @fnv 0x0081d0b0
unsigned short MagicModelHitEffect::GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    unsigned short isize = 0;
    isize += MagicHitEffect::GetSaveSize(apEffect, apTarget);
    isize += 2;
    if (*reinterpret_cast<Flt*>(&spRetainedObject))
    {
        NiControllerManager* pmanager = (NiControllerManager*)FUN_00653270(
            &DAT_011f36ac, (NiProperty*)((NiObjectNET*)(unsigned int)*reinterpret_cast<Flt*>(&spRetainedObject))->GetControllers());
        if (pmanager)
        {
            isize += FUN_0055fdb0(pmanager);
        }
    }
    return isize;
}

struct FUN_0081be50_s
{
    void SetTargetCell(ActiveEffect*, TESObjectREFR*);
};

// @fnv 0x0081d390
void MagicModelHitEffect::InitLoadGame(ActiveEffect* apEffect, TESObjectREFR* apRefr)
{
    ((FUN_0081be50_s*)this)->SetTargetCell(apEffect, apRefr);
}

// Returns true when _18 is zero and both _1c and _2c are non-zero; otherwise returns false.
// @fnv 0x0081d5a0
bool MagicModelHitEffect::IsSaveable()
{
    if (pEffect)
        return false;
    if (!pTarget || !pFilename)
        return false;
    return true;
}

namespace fnv_0081c810 {
struct Flt
{
    operator unsigned int();
};

struct SNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void InsertChild(unsigned int);
};
}  // namespace fnv_0081c810

// @fnv 0x0081c810
MagicModelHitEffect::~MagicModelHitEffect()
{
    if (*(fnv_0081c810::Flt*)&spRetainedObject)
    {
        NiNode* pparent = ((NiAVObject*)(unsigned int)*(fnv_0081c810::Flt*)&spRetainedObject)->GetParent();
        if (pparent)
            ((fnv_0081c810::SNode*)pparent)->InsertChild(*(fnv_0081c810::Flt*)&spRetainedObject);
        spRetainedObject = 0;
    }
    m_spTargetObject = 0;
    if (pFilename && *pFilename)
    {
        g_modelLoader->QueueModelLoad(pFilename, false, 1);
        if (m_bFirstPerson)
            delete const_cast<char*>(pFilename);
    }
    pFilename = 0;
    m_kLoadGameSubBuffer.FUN_00435b20();
}

namespace fnv_0081d800 {
struct FUN_0081be80_s
{
    void FUN_0081be80(BGSSaveFormBuffer*);
};
struct Flt
{
    operator unsigned int();
};
void __cdecl FUN_00563f30(NiControllerManager*, BGSSaveGameBuffer*, float);
}  // namespace fnv_0081d800

// @fnv 0x0081d800
void MagicModelHitEffect::SaveGame(BGSSaveGameBuffer* apSaveGameBuffer)
{
    NiControllerManager* pmanager;
    ((fnv_0081d800::FUN_0081be80_s*)this)->FUN_0081be80((BGSSaveFormBuffer*)apSaveGameBuffer);
    apSaveGameBuffer->SaveGameString(pFilename, 0);
    pmanager = 0;
    if (*reinterpret_cast<fnv_0081d800::Flt*>(&spRetainedObject))
        pmanager = (NiControllerManager*)FUN_00653270(
            &DAT_011f36ac, (NiProperty*)((NiObjectNET*)(unsigned int)*reinterpret_cast<fnv_0081d800::Flt*>(&spRetainedObject))->GetControllers());
    {
        unsigned int uiStartPosition = ((BGSSaveFormBuffer*)apSaveGameBuffer)->FUN_00865f20();
        unsigned int uiFormIdBefore = ((TESForm*)apSaveGameBuffer)->GetFormID();
        if (pmanager)
        {
            Actor* pactor = reinterpret_cast<Actor*>(apSaveGameBuffer->GetActor());
            Animation* panim = pactor ? reinterpret_cast<Animation*>(pactor->GetAnimData()) : 0;
            float ftime = panim ? panim->FUN_00453700() : -1.0f;
            fnv_0081d800::FUN_00563f30(pmanager, apSaveGameBuffer, -1.0f);
        }
        unsigned int uiFormIdAfter = ((TESForm*)apSaveGameBuffer)->GetFormID();
        ((BGSSaveFormBuffer*)apSaveGameBuffer)->FUN_00865ff0(uiFormIdAfter - uiFormIdBefore, uiStartPosition);
    }
}

unsigned int __cdecl FUN_0044a670(const char*);

// @fnv 0x0081d5d0
unsigned short MagicModelHitEffect::GetSaveSize()
{
    unsigned short usSize = 0;

    usSize += 4;
    usSize += 1;
    usSize += FUN_0044a670(pFilename);
    usSize += GetSaveSize(0, pTarget);

    return usSize;
}

struct FUN_0081d640_target
{
    unsigned int GetKey();
};

struct FUN_0081d640_mgr
{
    void Add(void* p, unsigned int n);
    void Set(void* p, unsigned int n);
};

extern FUN_0081d640_mgr* g_mgr;
unsigned char __cdecl Query_0044a670(unsigned int v);

// Reads the key of the object at m_1c, adds it to g_mgr, queries m_2c for a flag, sets it, and calls SaveGame(0, pTarget).
// @fnv 0x0081d640
void MagicModelHitEffect::SaveGame()
{
    unsigned int uiKey = ((FUN_0081d640_target*)pTarget)->GetKey();
    g_mgr->Add(&uiKey, 4);
    unsigned char flag = Query_0044a670((unsigned int)pFilename);
    g_mgr->Set(&flag, 1);
    g_mgr->Set((void*)pFilename, flag);
    SaveGame(0, pTarget);
}

class B81D920Loadable
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void* GetModelFilePath();
};

class B81D920Primary
{
  public:
    virtual ~B81D920Primary();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class B81D920Object
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B81D920Loadable m_kLoadable;
};

class B81D920Handle
{
  public:
    B81D920Object* GetObject();
};

class B81D920Ref
{
  public:
    B81D920Handle* GetHandle();
};

class B81D920ModelLoader
{
  public:
    void ProcessModelRequest(void* pvModel, int iPriority, bool bA, bool bB, int iC, int iD, int iE);
};

extern B81D920ModelLoader* g_pkB81D920ModelLoader;

class B81D920Base
{
  public:
    void LoadGame(BGSLoadFormBuffer* pkBuffer);
};

// @fnv 0x0081d920
void MagicModelHitEffect::LoadGame(BGSLoadGameBuffer* pkBuffer)
{
    reinterpret_cast<B81D920Base*>(this)->LoadGame(reinterpret_cast<BGSLoadFormBuffer*>(pkBuffer));
    pFilename = pkBuffer->LoadString(0);
    m_bFirstPerson = true;
    m_kLoadGameSubBuffer.LoadGame(pkBuffer);
    if (reinterpret_cast<B81D920Ref*>(pEffect) && reinterpret_cast<B81D920Ref*>(pEffect)->GetHandle()->GetObject()->m_kLoadable.GetModelFilePath())
        g_pkB81D920ModelLoader->ProcessModelRequest(reinterpret_cast<B81D920Ref*>(pEffect)->GetHandle()->GetObject()->m_kLoadable.GetModelFilePath(),
                                                    5, 0, 0, 1, 0, 0);
}

// @fnv 0x0081d9d0
void MagicModelHitEffect::InitLoadGame(BGSLoadGameBuffer* pkTarget)
{
    BSTempEffect::InitLoadGame(pkTarget);
}

class FUN_0081cc70_refvt
{
  public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037();
    virtual void s038();
    virtual void s039();
    virtual void s040();
    virtual void s041();
    virtual void s042();
    virtual void s043();
    virtual void s044();
    virtual void s045();
    virtual void s046();
    virtual void s047();
    virtual void s048();
    virtual void s049();
    virtual void s050();
    virtual void s051();
    virtual void s052();
    virtual void s053();
    virtual void s054();
    virtual void s055();
    virtual void s056();
    virtual void s057();
    virtual void s058();
    virtual void s059();
    virtual void s060();
    virtual void s061();
    virtual void s062();
    virtual void s063();
    virtual void s064();
    virtual void s065();
    virtual void s066();
    virtual void s067();
    virtual void s068();
    virtual void s069();
    virtual void s070();
    virtual void s071();
    virtual void s072();
    virtual void s073();
    virtual void s074();
    virtual void s075();
    virtual void s076();
    virtual void s077();
    virtual void s078();
    virtual void s079();
    virtual void s080();
    virtual void s081();
    virtual void s082();
    virtual void s083();
    virtual void s084();
    virtual void s085();
    virtual void s086();
    virtual void s087();
    virtual void s088();
    virtual void s089();
    virtual void s090();
    virtual void s091();
    virtual void s092();
    virtual void s093();
    virtual void s094();
    virtual void s095();
    virtual void s096();
    virtual void s097();
    virtual void s098();
    virtual void s099();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual int s116();
};

struct FUN_0081cc70_helper
{
    NiAVObject* FUN_00559450();
};

NiTimeController__CycleType __fastcall GetSequenceCycleType(NiControllerSequence* sequence);

// The shared MagicHitEffect header does not yet declare its Update override.
struct MagicHitEffectUpdater
{
    bool Update(float afTime);
};

// @fnv 0x0081cc70
bool MagicModelHitEffect::Update(float afTime)
{
    if (pTarget == 0 || ((FUN_0081cc70_refvt*)pTarget)->s116() == 0 || !reinterpret_cast<MagicHitEffectUpdater*>(this)->Update(afTime))
    {
        return false;
    }
    if (((FUN_0081cc70_helper*)&spRetainedObject)->FUN_00559450() != 0)
    {
        AttachToTarget();
        SkyShaderProperty* prop = FUN_00653270(
            &DAT_011f36ac,
            reinterpret_cast<NiProperty*>(((NiObjectNET*)((FUN_0081cc70_helper*)&spRetainedObject)->FUN_00559450())->GetControllers()));
        if (prop != 0)
        {
            NiControllerSequence* seq =
                ((NiControllerManager*)prop)->FindSequenceByName(NiFixedString("SpecialIdle_HitEffect"));
            if (seq != 0)
            {
                if (seq->FUN_00508120() > seq->FUN_00508100() &&
                    seq->GetState())
                {
                    if (GetSequenceCycleType(seq) == 2 || bWasPlaying != 0)
                    {
                        bWasPlaying = 1;
                        seq->Deactivate(0.0f, false);
                        m_fParticleParameter5 = m_fFirstFloatValue;
                    }
                }
            }
        }
    }
    if (bWasPlaying != 0)
    {
        if ((double)m_fParticleParameter5 + 2.0 < m_fFirstFloatValue)
        {
            return false;
        }
    }
    return true;
}

struct B006815c0
{
    float x, y, z;
    B006815c0();
    bool FUN_00439090(const B006815c0&);
};
struct Node505
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node505* IsSceneNode();
    unsigned int FUN_0043b480();
    Node505* FUN_0043b4a0(unsigned int);
    B006815c0& FUN_0043c490();
    const B006815c0& FUN_0045bb80();
    Node505* FUN_0043d450();
    B006815c0& FUN_006815c0();
    void FUN_00440460(const B006815c0&);
    void* FUN_006a9540();
    void FUN_0043fa80(void*);
};
struct Form505
{
    int FUN_00401170();
};

struct Holder505
{
    Node505* FUN_00559450();
};
extern B006815c0 DAT_011f426c;
// The base node-attachment helper takes the retained object as an argument.
struct MagicHitEffectNodeAttacher
{
    void AttachNode(Node505* node);
};

// @fnv 0x0081ce20
void MagicModelHitEffect::AttachToTarget()
{
    Node505* node = 0;
    if (pTarget == reinterpret_cast<TESObjectREFR*>(g_thePlayer))
    {
        b3rdPerson = g_thePlayer->FUN_004eaf60();
        node = reinterpret_cast<Node505*>(g_thePlayer->FUN_00950bb0(0));
    }
    else
    {
        node = reinterpret_cast<Node505*>(pTarget->GetNiNode());
    }
    reinterpret_cast<MagicHitEffectNodeAttacher*>(this)->AttachNode(
        reinterpret_cast<Holder505*>(&spRetainedObject)->FUN_00559450());
    if (node)
    {
        B006815c0 vecPosition;
        if ((pTarget->IsActor() && pTarget->HasHealth(false)) || pTarget->GetHasKnockedState())
        {
            bool lower = true;
            Node505* root = node->IsSceneNode();
            if (root && root->FUN_0043b480() > 0)
            {
                Node505* pBranchNode = root->FUN_0043b4a0(0);
                Node505* pChildNode = pBranchNode ? pBranchNode->IsSceneNode() : 0;
                if (pChildNode && pChildNode->FUN_0043b480() > 0)
                {
                    pBranchNode = pChildNode->FUN_0043b4a0(0);
                    Node505* pLeafNode = pBranchNode ? pBranchNode->IsSceneNode() : 0;
                    if (pLeafNode && pLeafNode->FUN_0043c490().FUN_00439090(DAT_011f426c))
                        lower = false;
                }
            }
            vecPosition = node->FUN_0045bb80();
            if (lower)
                vecPosition.z -= 64.0;
        }
        else if (pTarget->GetObjectReference() &&
                 reinterpret_cast<Form505*>(pTarget->GetObjectReference())->FUN_00401170() == 28)
        {
            vecPosition = node->FUN_0043d450()->FUN_006815c0();
            vecPosition.z = node->FUN_0045bb80().z;
        }
        else
        {
            vecPosition = node->FUN_0045bb80();
        }
        if (reinterpret_cast<Holder505*>(&spRetainedObject)->FUN_00559450())
        {
            reinterpret_cast<Holder505*>(&spRetainedObject)->FUN_00559450()->FUN_00440460(vecPosition);
            reinterpret_cast<Holder505*>(&spRetainedObject)->FUN_00559450()->FUN_0043fa80(node->FUN_006a9540());
        }
    }
}


struct ObjectPtrLocal
{
    NiAVObject* object;
    NiAVObject* FUN_00559450();
};
struct SaveManagerLocal
{
    const char* FUN_00825c00();
    void FUN_00600ab0(const char*);
    void FUN_008579e0(void*, unsigned int);
};
extern SaveManagerLocal* DAT_011de45c;
extern const float DAT_01012054;
void* __cdecl FUN_00653270(const NiRTTI*, NiTimeController*);
void __cdecl FUN_0055ffa0(void*, NiAVObject*, float);
void __cdecl FormHeap_Free(void*);
// @fnv 0x0081d3b0
void MagicModelHitEffect::FinishLoadGameTES(ActiveEffect* effect, TESObjectREFR* target, void* apData)
{
    MagicHitEffect::FinishLoadGameTES(effect, target, 0);
    const char* previous = pFilename;
    if (effect)
    {
        pFilename = reinterpret_cast<const char*>(reinterpret_cast<TESModel*>(reinterpret_cast<char*>(effect->FUN_0084e3a0()->GetEffectSetting()) + sizeof(TESForm))->GetModelFilePath());
    }
    else
    {
        pFilename = static_cast<const char*>(apData);
    }
    float age = MagicHitEffect::m_fFirstFloatValue;
    bool finished = bWasPlaying;
    Init();
    MagicHitEffect::m_fFirstFloatValue = age;
    bWasPlaying = finished;
    const char* saved = DAT_011de45c->FUN_00825c00();
    DAT_011de45c->FUN_00600ab0(previous);
    unsigned short version3;
    DAT_011de45c->FUN_008579e0(&version3, 2);
    if (reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject)->FUN_00559450())
    {
        void* controller4 = FUN_00653270(
            &DAT_011f36ac,
            reinterpret_cast<NiObjectNET*>(reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject)->FUN_00559450())
                ->GetControllers());
        if (controller4)
        {
            float time_ = DAT_01012054;
            Actor* actor4 = target && target->IsActor() ? reinterpret_cast<Actor*>(target) : 0;
            MiddleHighProcess* aProcess;
            if (actor4 && effect && (aProcess = dynamic_cast<MiddleHighProcess*>(actor4->MobileObject::FUN_008d8520())) &&
                static_cast<const MiddleHighProcess*>(aProcess)->GetAnimation())
                time_ = static_cast<const MiddleHighProcess*>(aProcess)->GetAnimation()->FUN_00453700();
            FUN_0055ffa0(controller4, reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject)->FUN_00559450(), time_);
        }
    }
    DAT_011de45c->FUN_00600ab0(saved);
    FormHeap_Free(const_cast<char*>(previous));
    Update(0.0f);
}


struct ModelObjectStub
{
    NiObject* GetRoot();
};
struct ModelPtrAccess
{
    ModelObjectStub* m_pObject;
    operator ModelObjectStub*() const;
};
NiNode* __cdecl NiDynamicCastNode(const NiRTTI*, NiObject*);
void __cdecl ApplyLoadedModelData(NiNode*, BGSLoadFormBuffer*, float);

// @fnv 0x0081d9f0
void MagicModelHitEffect::ApplyLoadBuffer(BGSLoadGameBuffer* apBuffer)
{
    MagicHitEffect::ApplyLoadBuffer(apBuffer);
    float fSavedAge = m_fFirstFloatValue;
    bool bSavedFinished5 = bWasPlaying;
    Init();
    m_fFirstFloatValue = fSavedAge;
    bWasPlaying = bSavedFinished5;
    if (((const NP*)&m_kLoadGameSubBuffer)->operator void*())
    {
        NiNode* pNodeX = 0;
        if (*(ModelPtrAccess*)&spRetainedObject)
            pNodeX =
                NiDynamicCastNode(&DAT_011f36ac, ((ModelObjectStub*)*(ModelPtrAccess*)&spRetainedObject)->GetRoot());
        if (pNodeX)
        {
            Actor* pActor4 = (Actor*)apBuffer->GetActor();
            Animation* pAnim2 = pActor4 ? reinterpret_cast<Animation*>(pActor4->GetAnimData()) : 0;
            float fTime = pAnim2 ? pAnim2->FUN_00453700() : -1.0f;
            BGSLoadFormBuffer* pLoadBuffer = m_kLoadGameSubBuffer.CreateFormBuffer(0);
            ApplyLoadedModelData(pNodeX, pLoadBuffer, fTime);
            delete reinterpret_cast<ModelEffectLoadFormBuffer*>(pLoadBuffer);
        }
    }
    m_kLoadGameSubBuffer.FUN_00435b20();
    Update(0.0f);
}

struct FUN_0081bd80_shell
{
    void FUN_0081bd80(ActiveEffect*, TESObjectREFR*);
};
unsigned short __cdecl FUN_0055fdb0(NiControllerManager*);
void __cdecl FUN_0055fe70(NiControllerManager*, float);
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct RefV_0081d150
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

// Calls the base helper, passes a 16-bit value to g_TESSaveLoadGame, and may update a controller manager using an actor's animation time.
// @fnv 0x0081d150
void MagicModelHitEffect::SaveGame(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    ((FUN_0081bd80_shell*)this)->FUN_0081bd80(apEffect, apTarget);
    NiControllerManager* pmanager = 0;
    if ((unsigned int)*reinterpret_cast<Flt*>(&spRetainedObject))
        pmanager = (NiControllerManager*)FUN_00653270(
            &DAT_011f36ac, (NiProperty*)((NiObjectNET*)(unsigned int)*reinterpret_cast<Flt*>(&spRetainedObject))->GetControllers());
    unsigned short usState = 0;
    if (pmanager)
        usState = FUN_0055fdb0(pmanager);
    g_TESSaveLoadGame->FUN_008579b0(&usState, 2);
    if (usState)
    {
        float ftime = -1.0f;
        TES* pactor = (apTarget && ((RefV_0081d150*)apTarget)->IsActor()) ? (TES*)apTarget : 0;
        if (pactor && apEffect)
        {
            MiddleHighProcess* pprocess = dynamic_cast<MiddleHighProcess*>((BaseProcess*)pactor->GetLogDate());
            if (pprocess && static_cast<const MiddleHighProcess*>(pprocess)->GetAnimation())
                ftime = static_cast<const MiddleHighProcess*>(pprocess)->GetAnimation()->FUN_00453700();
        }
        FUN_0055fe70(pmanager, ftime);
    }
}

#include <string.h>
namespace fnv_0081d2a0 {
struct QueueHelper
{
    void FUN_00444040(int, int, int, int, bool, bool, bool);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
// Calls SaveLoad, queues the effect model for loading if present, and reads a size-prefixed buffer from the save stream into the object.
}  // namespace fnv_0081d2a0

// @fnv 0x0081d2a0
void MagicModelHitEffect::LoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    unsigned short isize;
    char* pbuffer;
    MagicHitEffect::LoadGame(apEffect, apTarget);
    if (apEffect &&
        ((TESModel*)(((TimeGlobal*)((TESForm*)apEffect)->GetFormID())->GetTimeStamp() + 0x18))->GetModelFilePath())
    {
        ((fnv_0081d2a0::QueueHelper*)g_modelLoader)
            ->FUN_00444040((int)((TESModel*)(((TimeGlobal*)((TESForm*)apEffect)->GetFormID())->GetTimeStamp() + 0x18))
                               ->GetModelFilePath(),
                           5, 0, 0, true, false, false);
    }
    fnv_0081d2a0::g_TESSaveLoadGame->FUN_008579e0(&isize, 2);
    if (isize)
    {
        pbuffer = (char*)::operator new(isize + 2);
        memcpy(pbuffer, &isize, 2);
        fnv_0081d2a0::g_TESSaveLoadGame->FUN_008579e0(pbuffer + 2, isize);
        pFilename = pbuffer;
    }
}

namespace fnv_0081d6c0 {
extern TESSaveLoadGame* g_TESSaveLoadGame;
TESForm* GetFormByID(unsigned int aiID);

// MagicModelHitEffect::LoadGame (vB4)
// Validates a form ID and target cell, reads a string, then calls LoadGame, InitLoadGame and FinishLoadGameTES on the target.
}  // namespace fnv_0081d6c0

// @fnv 0x0081d6c0
bool MagicModelHitEffect::LoadGame()
{
    bool bSuccess = true;
    unsigned int iformID;
    fnv_0081d6c0::g_TESSaveLoadGame->ValidateFormIDArray(&iformID, 4);
    pTarget = dynamic_cast<TESObjectREFR*>(fnv_0081d6c0::GetFormByID(iformID));
    if (!pTarget || !pTarget->GetParentCell() || !pTarget->GetParentCell()->IsOutdoorCell())
        bSuccess = false;
    {
        unsigned char isize;
        fnv_0081d6c0::g_TESSaveLoadGame->FUN_008579e0(&isize, 1);
        char* pBuffer = new char[isize + 1];
        memset(pBuffer, 0, isize + 1);
        fnv_0081d6c0::g_TESSaveLoadGame->FUN_008579e0(pBuffer, isize);
        m_bFirstPerson = true;
        LoadGame(0, pTarget);
        if (bSuccess)
        {
            InitLoadGame(0, pTarget);
            FinishLoadGameTES(0, pTarget, pBuffer);
        }
    }
    return bSuccess;
}

