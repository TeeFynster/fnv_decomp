#include "../../../include/Actor.h"
#include "../../../include/MagicCaster.h"
#include "../../../include/MagicFogProjectile.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiControllerManager.h"
#include "../../../include/NiControllerSequence.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiObject.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/Projectile.h"
#include "../../../include/Setting.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/NiMatrix3.h"

// src/fallout/magic/magicfogprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicfogprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void _Deallocate(void*);
// Calls FUN_008196e0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00819330
void* MagicFogProjectile::DestroyIfFlagged(unsigned int flags)
{
    FUN_008196e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Retained: MagicFogProjectile does not declare FUN_0081a920.
struct FUN_0081a920_shell
{
    bool ProcessAndTransformResult_0081a920();
};
// Returns true when the int at offset 0xb4 is not 1 and the object is not deleted.
// @fnv 0x0081a920
// src: GUESS 0x0081a920 (confidence: low)
bool FUN_0081a920_shell::ProcessAndTransformResult_0081a920()
{
    return *(int*)((char*)this + 0xb4) != 1 && !reinterpret_cast<const TESForm*>(this)->IsDeleted();
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x0081ad00
// src: XBOX_PDB 0x0081ad00
unsigned short MagicFogProjectile::GetSaveSize_0081ad00(unsigned int flags)
{
    unsigned short isize = 0;
    isize += GetSaveRecordSize(flags);
    isize += 4;
    isize += 4;
    isize += 4;
    isize += 4;
    isize += 4;
    if (*(int*)((char*)this + 0xb4) == 1)
        isize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x71)
    {
        isize += 4;
        isize += 2;
        VirtualInterface* pNode = *(VirtualInterface**)((char*)this + 0xc8);
        while (pNode)
        {
            isize += 4;
            isize += 1;
            pNode = pNode->next;
        }
    }
    return isize;
}

extern double _gModifierZero;
// Returns true when _m14 is greater than _gModifierZero.
// @fnv 0x00818ba0
bool MagicFogProjectile::IsAboveZero()
{
    return *(float*)((char*)this + 0x14) > _gModifierZero;
}

// @fnv 0x00819830
void MagicFogProjectile::DeleteAllNodes()
{
    VirtualInterface* pNode;
    // Use the offset directly: this unit is built with /Od, so property getters add calls.
    while (*(VirtualInterface**)((char*)this + 0xC8))
    {
        pNode = *(VirtualInterface**)((char*)this + 0xC8);
        *(VirtualInterface**)((char*)this + 0xC8) = (*(VirtualInterface**)((char*)this + 0xC8))->next;
        delete pNode;
    }
    *(VirtualInterface**)((char*)this + 0xC8) = 0;
}

// Retained: MagicProjectile does not declare ClearIfMatches.
struct FUN_0081eb50_shell
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
    virtual void v49(int);
    char _pad[0x90];
    int m94;
    bool ClearIfMatches(int);
};
// If a equals m94, resets m94 to 0, calls v49(1), and returns true; otherwise returns false.
// @fnv 0x0081eb50
bool FUN_0081eb50_shell::ClearIfMatches(int aiValue)
{
    bool r = false;
    if (aiValue == m94)
    {
        m94 = 0;
        r = true;
        v49(1);
    }
    return r;
}

extern Setting DAT_011d1890, DAT_011d1bd4, DAT_011d19f0;
extern NiRTTI DAT_012024e0, DAT_01202550, DAT_01202540;
bool NiObject_IsKindOf(const NiRTTI*, NiObject*);
void* NiObject_DynamicCast(const NiRTTI*, NiObject*);
struct Emitter
{
    float NiPSysSpawnModifier_GetLifeSpan();
    void NiPSysSpawnModifier_SetLifeSpan(float);
};
struct Controller
{
    float TESCombatStyle_GetTargetingFOV();
    void PathingLOSGridMap_SetSightRadius(float);
    float FUN_004a7bd0();
    void CombatLocation_SetRadius(float);
    float QueuedModel_GetOverriddenVisualDistance();
    void TESQuest_SetScriptProcessingDelay(float);
};
// Retained: NiParticleSystem does not declare these modifier accessors.
struct Particle : NiObject
{
    unsigned NiParticleSystem_GetModifierCount();
    NiObject* GetByIndex(unsigned);
};
// Retained: MagicFogProjectile does not declare ScaleEffect.
struct Effect
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    float sizeScale, speedScale;
    void ScaleEffect(NiObject*);
};
// Scales the effect's size and speed settings and applies the scaled values to each particle's emitter and controller, recursing into child nodes.
// @fnv 0x00819890
void Effect::ScaleEffect(NiObject* object)
{
    float fSpeedFactor;
    {
        float fSpeedFactor2;
        {
            float fSizeFactor = sizeScale * *DAT_011d1890.Setting_Float_00403e20();
            fSpeedFactor = speedScale * *DAT_011d1bd4.Setting_Float_00403e20();
            fSpeedFactor2 = speedScale * *DAT_011d19f0.Setting_Float_00403e20();
            if (NiObject_IsKindOf(&DAT_012024e0, object))
            {
                Particle* particle = (Particle*)object;
                for (unsigned i = 0; i < particle->NiParticleSystem_GetModifierCount(); ++i)
                {
                    Controller* controller;
                    {
                        Emitter* emitter;
                        {
                            NiObject* entry = particle->GetByIndex(i);
                            emitter = (Emitter*)NiObject_DynamicCast(&DAT_01202550, entry);
                            if (emitter)
                                emitter->NiPSysSpawnModifier_SetLifeSpan(emitter->NiPSysSpawnModifier_GetLifeSpan() * fSizeFactor);
                            controller = (Controller*)NiObject_DynamicCast(&DAT_01202540, entry);
                            if (controller)
                            {
                                controller->PathingLOSGridMap_SetSightRadius(controller->TESCombatStyle_GetTargetingFOV() * fSizeFactor);
                                controller->CombatLocation_SetRadius(controller->FUN_004a7bd0() * fSpeedFactor2);
                                controller->TESQuest_SetScriptProcessingDelay(controller->QueuedModel_GetOverriddenVisualDistance() * fSpeedFactor);
                            }
                        }
                    }
                }
            }
            else if (object && object->IsSceneNode())
            {
                NiNode* node = (NiNode*)object;
                for (unsigned i = 0; i < node->FUN_0043b480(); ++i)
                {
                    NiObject* child = node->FUN_0043b4a0(i);
                    ScaleEffect(child);
                }
            }
        }
    }
}

void* __cdecl operator new(unsigned int);
struct FUN_0081aa80
{
    TESForm* form;
    unsigned char flags;
    FUN_0081aa80* next;
    FUN_0081aa80(TESForm*, unsigned char, FUN_0081aa80*);
};
struct SaveManager
{
    void TESSaveLoadGame_LoadGameDataOLD(void*, unsigned);
    unsigned char FUN_008df040();
};
extern SaveManager* DAT_011de45c;
void* __cdecl FUN_00401460(void*, const void*, unsigned);
// Resets the projectile, reads several 4-byte fields and a form ID from the stream, then reads a list of form/flag records when the save version is at least 0x71.
// @fnv 0x0081afa0
void Projectile::LoadFromStream(int a, int b)
{
    DeleteAllNodes();
    AnimateNiNode();
    LoadGame_0081e980(a, b);
    TESForm_LoadGameDataOLD((char*)this + 0xA8, 4);
    TESForm_LoadGameDataOLD(&kImpacts, 4);
    TESForm_LoadGameDataOLD((char*)this + 0xAC, 4);
    DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD((char*)this + 0xB4, 4);
    TESForm_LoadGameDataOLD((char*)this + 0xB8, 4);
    if (*(int*)((char*)this + 0xB4) == 1)
    {
        unsigned formID;
        TESForm_LoadGameDataOLD(&formID, 4);
        FUN_00401460(&id, &formID, 4);
    }
    if (DAT_011de45c->FUN_008df040() >= 0x71)
    {
        TESForm_LoadGameDataOLD((char*)this + 0xB0, 4);
        unsigned short count;
        TESForm_LoadGameDataOLD(&count, 2);
        for (unsigned i = 0; i < count; ++i)
        {
            FUN_0081aa80* record;
            {
                TESForm* form;
                {
                    unsigned char flags;
                    TESForm_LoadNumericID(&form, 4);
                    TESForm_LoadGameDataOLD(&flags, 1);
                    record = new FUN_0081aa80(form, flags, (FUN_0081aa80*)head);
                    head = (Link*)record;
                }
            }
        }
    }
}

void __cdecl BSUtilities_ProcessSelectiveUpdate(NiNode* pkNode);
NiControllerManager* __cdecl NiObject_DynamicCast(void* pkRTTI, void* pkController);
extern char g_kNiControllerManagerRTTI_011f36ac[];
extern const float g_fInfinity_0107ad40;
extern float g_fGameTime_011c3c08;

static const char s_szAreaEffect[] = "AreaEffect";
static const char s_szSpecialIdle[] = "SpecialIdle_Projectile";
extern const char g_szFogInitEnd[] = "";

// Retained: MagicFogProjectile does not declare InitProjectileEffect.
struct FogProjectileInit
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();

    virtual NiNode* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& GetPos();

    char pad004[0xb8 - 4];
    float m_fScale;

    const NiPoint3& FUN_00430830();
    void ScaleEffect(NiAVObject* pkObject);
    void InitProjectileEffect();
};

// @fnv 0x00819a90
void FogProjectileInit::InitProjectileEffect()
{
    NiNode* pkNode = Get3D();
    if (pkNode)
    {
        pkNode->NiAVObject_SetScale(m_fScale);
        pkNode->NiAVObject_SetTranslate(GetPos());
        NiPoint3 kAngleX = FUN_00430830();
        NiMatrix3 kKRot;
        kKRot.FromEulerAnglesZXY(kAngleX.z, kAngleX.x, kAngleX.y);
        pkNode->SetRotate_0043fa80(kKRot);
        BSUtilities_ProcessSelectiveUpdate(pkNode);
        NiAVObject* pkArea_2 = static_cast<const NiNode*>(pkNode)->GetObjectByName(NiFixedString(s_szAreaEffect));
        if (pkArea_2)
            ScaleEffect(pkArea_2);
        NiControllerManager* pkManagerTmp = NiObject_DynamicCast(g_kNiControllerManagerRTTI_011f36ac, static_cast<const NiObjectNET*>(pkNode)->GetControllers());
        if (pkManagerTmp)
        {
            NiControllerSequence* pkSeqCur = pkManagerTmp->NiControllerManager_GetSequenceByName(NiFixedString(s_szSpecialIdle));
            if (pkSeqCur)
            {
                pkManagerTmp->FUN_0048fef0(0.0f);
                pkManagerTmp->FUN_0047aab0(pkSeqCur, 0, 0, 1.0f, 0.0f, 0);
                pkManagerTmp->FUN_0047aa40(1);
                pkSeqCur->PathingLOSGridMap_SetSightRadius(-g_fInfinity_0107ad40);
                NiUpdateData kTimeY(g_fGameTime_011c3c08 - 0.1f, 1, 0);
                pkNode->NiAVObject_Update(kTimeY);
            }
        }
    }
}

struct ItemB
{
    unsigned char FindEffectItemIndex();
};
struct ItemC
{
    float ActorPackage_GetPackageStartTime();
};
struct Node2
{
    TESForm* m0;
    void* m4;
    Node2* next;
};
struct SaveMgrExt
{
    void TESSaveLoadGame_SaveGameDataOLD(void*, unsigned int);
    unsigned short* FUN_00825c00();
    unsigned char FUN_008df040();
};

// Retained: MagicFogProjectile does not declare SaveToStream or its save helpers.
class FUN_0081ade0_cls
{
  public:
    void SaveGame_0081e8c0(int);
    void TESForm_SaveGameDataOLD(void*, unsigned int);
    void ForwardToSaveLoadGame(void*, unsigned int);
    int FUN_00810fd0();
    int FUN_00810fd0(int);
    void SaveToStream(int a1);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84;
    int m88;
    int unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int unkBC, unkC0, unkC4;
    Node2* m_c8;
    ItemC* m_cc;
};

// @fnv 0x0081ade0
void FUN_0081ade0_cls::SaveToStream(int a1)
{
    float f;
    unsigned short* out;
    SaveGame_0081e8c0(a1);
    TESForm_SaveGameDataOLD(&m_a8, 4);
    TESForm_SaveGameDataOLD(&m88, 4);
    TESForm_SaveGameDataOLD(&m_ac, 4);
    ((SaveMgrExt*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&m_b4, 4);
    TESForm_SaveGameDataOLD(&m_b8, 4);
    if (m_b4 == 1)
    {
        f = 0.0f;
        if (m_cc != 0)
        {
            f = m_cc->ActorPackage_GetPackageStartTime();
        }
        TESForm_SaveGameDataOLD(&f, 4);
    }
    if ((int)((SaveMgrExt*)DAT_011de45c)->FUN_008df040() >= 0x71)
    {
        Node2* cur;
        unsigned short cnt;
        TESForm_SaveGameDataOLD(&m_b0, 4);
        cnt = 0;
        out = ((SaveMgrExt*)DAT_011de45c)->FUN_00825c00();
        TESForm_SaveGameDataOLD(&cnt, 2);
        cur = m_c8;
        while (cur != 0)
        {
            int tmp = 0;
            if (cur->m0 != 0)
            {
                tmp = cur->m0->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            }
            ForwardToSaveLoadGame(&tmp, 4);
            unsigned char flag = 0;
            if (FUN_00810fd0() != 0 && cur->m4 != 0)
            {
                flag = ((ItemB*)(FUN_00810fd0((int)cur->m4) + 0xc))->FindEffectItemIndex();
            }
            TESForm_SaveGameDataOLD(&flag, 1);
            cnt++;
            cur = cur->next;
        }
        *out = cnt;
    }
}

TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormId);

struct FogBaseForm
{
    TESForm* BGSProjectile_GetExplosion();
    TESForm* EffectSetting_GetLight();
};

struct FogLight
{
    int unk00[7];
    FogLight(unsigned int auiFormId, void* pkNode);
    void* operator new(unsigned int uiSize);
    void operator delete(void* pvMem);
    void MagicLight_Fade(int iUnk, float fRadius);
    void NiTimeController_SetPhase(float fFadeAmount);
};

struct FogProcess
{
    void FUN_00548230(void* pkProjectile, int iUnk);
};

struct FogRefNode
{
    TESForm* m_pkForm;
    int m_iValue;
    FogRefNode* m_pkNext;
};

struct FogIndexList
{
    int FUN_00406ee0(unsigned char m_ucClipIdentifier);
};
struct FogFile
{
    int unk00, unk04, unk08;
    FogIndexList kList;
};

struct FogSaveManager
{
    unsigned char FUN_008df040();
};
extern FogSaveManager* g_pkSaveManager_011de45c;

// Retained: MagicFogProjectile does not declare LoadProjectile or its load helpers.
struct FogProjectileLoad
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();

    virtual void* Get3D();

    char pad004[0xac - 4];
    float m_fBoundRadius;
    char pad0b0[0xb4 - 0xb0];
    int unkb4;
    char pad0b8[0xbc - 0xb8];
    BSSoundHandle m_kSound;
    FogRefNode* m_pkRefs;
    FogLight* m_pkLight;

    void ResolveMagicReferences(int a1, int a2);
    void InitProjectileEffect();
    FogProcess* FUN_008d6f30();
    FogBaseForm* GetAVEffect();
    BSSoundHandle PlaySoundByFormID(unsigned int auiFormId, int a2, int a3, int a4);
    FogFile* FUN_00810fd0();
    void LoadProjectile(int a1, int a2);
};

// Runs the projectile load steps, rebuilds the sound handle and light, and remaps reference forms and indices when the save version is at least 0x71.
// @fnv 0x0081b180
void FogProjectileLoad::LoadProjectile(int a1, int a2)
{
    ResolveMagicReferences(a1, a2);
    InitProjectileEffect();
    FUN_008d6f30()->FUN_00548230(this, 0);
    if (unkb4 != 1 && GetAVEffect()->BGSProjectile_GetExplosion())
    {
        unsigned int uiProjectileSoundFormID = GetAVEffect()->BGSProjectile_GetExplosion()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        if (m_kSound.IsValid())
            m_kSound.Release();
        m_kSound = PlaySoundByFormID(uiProjectileSoundFormID, 1, 0x40000102, 1);
    }
    float fFadeAmount;
    FUN_00401460(&fFadeAmount, &m_pkLight, 4);
    m_pkLight = 0;
    if (Get3D() && GetAVEffect()->EffectSetting_GetLight())
    {
        m_pkLight = new FogLight(GetAVEffect()->EffectSetting_GetLight()->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), Get3D());
        if (m_pkLight)
        {
            m_pkLight->MagicLight_Fade(0, m_fBoundRadius);
            m_pkLight->NiTimeController_SetPhase(fFadeAmount);
        }
    }
    if (g_pkSaveManager_011de45c->FUN_008df040() >= 0x71)
    {
        FogRefNode* pkNode = m_pkRefs;
        while (pkNode)
        {
            unsigned int uiFormID_2 = (unsigned int)pkNode->m_pkForm;
            unsigned char ucIndexZ = (unsigned char)pkNode->m_iValue;
            if (uiFormID_2)
                pkNode->m_pkForm = dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(uiFormID_2));
            if (FUN_00810fd0())
                pkNode->m_iValue = FUN_00810fd0()->kList.FUN_00406ee0(ucIndexZ);
            pkNode = pkNode->m_pkNext;
        }
    }
}

extern unsigned int DAT_011dea3c;
extern Setting DAT_011d15f8;
void __cdecl _11DC778_Subtract(float);

struct FUN_0081de70
{
    virtual ~FUN_0081de70();
    int unk04, unk08, unk0C, unk10, unk14;
};

struct MagicFogIface8196
{
    virtual void v00();
};

// Retained: the shared class does not own the sound member needed for identical destructor cleanup.
struct FUN_008196e0 : public FUN_0081de70, public MagicFogIface8196
{
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8;
    BSSoundHandle m_kSound;
    int unkC8;
    MagicFogProjectile::LightState* m_pkCc;
    virtual ~FUN_008196e0();
    void* FUN_009185e0();
    void DeleteAllNodes();
};

// @fnv 0x008196e0
FUN_008196e0::~FUN_008196e0()
{
    unsigned int uiValue = FUN_009185e0() ? (unsigned int)((MagicCaster*)FUN_009185e0())->GetCasterReference() : 0;
    if (uiValue != DAT_011dea3c)
        _11DC778_Subtract(*DAT_011d15f8.Setting_Float_00403e20());
    DeleteAllNodes();
    if (m_kSound.IsValid())
    {
        m_kSound.Stop();
        m_kSound.Release();
    }
    if (m_pkCc)
        delete m_pkCc;
    m_pkCc = 0;
}

struct FogColor
{
    unsigned int m_uiColor;
    FogColor();
    void CFilter_SetLayer(int iAlpha);
    void CFilter_SetGroup(int iColor);
};

struct HandleRef
{
    unsigned int m_uiCurrentValue;
    HandleRef();
    int CFilter_GetGroup();
};
struct FogColorHolder
{
    HandleRef bhkWorldObject_GetCollisionFilter();
};
struct FogRace
{
    FogColorHolder* bhkNiCollisionObject_GetWorldObject();
};
FogRace* __cdecl FindFirstCollisionObject(void* pkNode);
int __cdecl bhkCollisionFilter_GetNewSystemGroup();
void __cdecl MagicProjectile_AddTrackedProjectile(float fValue);

extern Actor* g_thePlayer_011dea3c;

struct FogShader
{
    FogColor bhkCharacterController_GetCollisionFilter();
    void bhkCharacterController_SetCollisionFilter(FogColor kColor);
};

extern Setting g_s_011d15f8;

// Retained: MagicFogProjectile does not declare FUN_0081b430 or its update helpers.
struct FogProjectileImpl
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();

    virtual void* Get3D();

    void UpdateFlags(int a1, int a2);
    FogShader* FUN_009306d0();
    MagicCaster* FUN_009185e0();
    void MagicFogProjectile_FinishInitLoadGameTES(int a1, int a2);
};

// @fnv 0x0081b430
// src: COMMUNITY 0x0081b430
void FogProjectileImpl::MagicFogProjectile_FinishInitLoadGameTES(int a1, int a2)
{
    UpdateFlags(a1, a2);
    FogShader* pkShaderZ = FUN_009306d0();
    if (pkShaderZ)
    {
        int iColor;
        if (FUN_009185e0() && FUN_009185e0()->GetCasterReference())
        {
            TESObjectREFR* pkRef = FUN_009185e0()->GetCasterReference();
            Actor* pkActor = dynamic_cast<Actor*>(pkRef);
            if (pkActor)
            {
                iColor = pkActor->FUN_00931ed0().CFilter_GetGroup();
            }
            else
            {
                FogRace* pkRaceA = FindFirstCollisionObject(pkRef->GetNiNode());
                FogColorHolder* pkHolderPtr = pkRaceA ? pkRaceA->bhkNiCollisionObject_GetWorldObject() : 0;
                iColor = pkHolderPtr ? pkHolderPtr->bhkWorldObject_GetCollisionFilter().CFilter_GetGroup() : bhkCollisionFilter_GetNewSystemGroup();
            }
        }
        else
        {
            FogRace* pkRace2 = FindFirstCollisionObject(Get3D());
            FogColorHolder* pkHolder2 = pkRace2 ? pkRace2->bhkNiCollisionObject_GetWorldObject() : 0;
            iColor = pkHolder2 ? pkHolder2->bhkWorldObject_GetCollisionFilter().CFilter_GetGroup() : bhkCollisionFilter_GetNewSystemGroup();
        }
        FogColor kColor = pkShaderZ->bhkCharacterController_GetCollisionFilter();
        kColor.CFilter_SetLayer(7);
        kColor.CFilter_SetGroup(iColor);
        pkShaderZ->bhkCharacterController_SetCollisionFilter(kColor);
    }
    TESObjectREFR* _pkCaster = FUN_009185e0() ? FUN_009185e0()->GetCasterReference() : 0;
    if (_pkCaster != g_thePlayer_011dea3c)
        MagicProjectile_AddTrackedProjectile(*g_s_011d15f8.Setting_Float_00403e20());
}
