#include "../../../../include/SettingT.h"
// fallout/ai/combat/vats.cpp: VATS, PlayerCharacter, SoundListView, ListHolder and more (26 functions)

#include "../../../../include/BGSCameraShot.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/GO.h"
#include "../../../../include/InventoryStackRecord.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3Interpolator.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/SettingT_GameSettingCollection_.h"
#include "../../../../include/hkpCharacterContext.h"
#include "../../../../include/Actor.h"
#include "../../../../include/HUDMainMenu.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiAdditionalGeometryData.h"
#include "../../../../include/ShadowSceneNode.h"
#include "../../../../include/TESIdleForm.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiPointLight.h"
#include "../../../../include/VATSCommand.h"
class GameSettingCollection;
class VATSCommand;
struct Node;
class Projectile;
class ImageSpaceModifierInstanceForm;
class ImageSpaceModifierInstanceRB;
class ShadowSceneLight;

class Animation
{
  public:
    void Animation_SetGlobalTimeMultiplier(float);
};

class TimeGlobal
{
  public:
    void ApplyGlobalTimeMultiplier();
};

typedef char VATSPlayerTimerOffsetCheck[offsetof(PlayerCharacter, fVATSTimer) == 0xE18 ? 1 : -1];
typedef char VATSPlayerSizeCheck[sizeof(PlayerCharacter) == 0xE50 ? 1 : -1];

class CameraPathManager
{
  public:
    void SetCameraPathEnabled(bool enabled, unsigned int mask);
};

// BGSCameraShot.h does not yet declare these VATS camera helpers.
struct CameraShotExtra : BGSCameraShot
{
    bool IsInitialized();
    float TESCombatStyle_GetTargetingFOV();
    void __thiscall ResetCameraState();
    float __thiscall GetFloatAtOffset58();
    bool __thiscall BGSCameraShot_IsFirstPerson();
    int GetField38();
    void SetByteAt76(unsigned char value);
};

// No include/VATS.h exists yet; keep one VATS definition for the 0x48-byte state.
class VATS
{
  public:
    BSSimpleList<VATSCommand*> m_kCommandList;
    int eMode;
    BSSimpleList<BGSCameraShot*>* m_pCameraShotList;
    BGSCameraShot* pCamera;
    float m_fCameraTime;
    float m_fCameraDuration;
    Projectile* m_pSource;
    Projectile* m_pTargetProjectile;
    TESIdleForm* m_pIdleForm;
    ImageSpaceModifierInstanceForm* m_pImagespaceModifier;
    ImageSpaceModifierInstanceRB* pTransitionImagespaceMod;
    bool bIsPlayer;
    unsigned char layoutPadding31[3];
    NiPointer<ShadowSceneLight> m_spShadowSceneLight;
    bool m_bShadowLightEnabled;
    unsigned char layoutPadding39[3];
    int m_iShadowLightState;
    TESBoundObject* m_pCurrentWeaponObject;
    ExtraDataList* m_pWeaponExtraData;
    void Update(int mode, bool force);
    float GetModeTimeMultiplier();
    void QuitVATSPlayback(bool abForceQuit, bool abFinishCommandPlayback);
    void AddCommand(VATSCommand*);
    void FUN_009c6c30(int, bool);
    void ForceTargetKillShot(TESObjectREFR*, int);
    void UpdateVATSLight(Actor*);
    void ProcessVATSCommands();
    bool FUN_008256d0();
    Node* FUN_006815c0();
    void FUN_0063f7b0();
    void RemoveCommandsForTarget(TESObjectREFR*);
    bool IsValidCommand(VATSCommand*);
    bool VATS_GetLineOfSight(VATSCommand*);
    void ExecuteVATSMeleeAttack(VATSCommand*);
    void FreeHeadAction();
    bool UseNextCamera();
    VATSCommand* VATS_GetCurrentAction();
    void HandleCommand(VATSCommand*);
    void SetValue(int);
    void EvaluateCommand(VATSCommand*);
};
typedef char VATSSizeCheck[sizeof(VATS) == 0x48 ? 1 : -1];
typedef char VATSModeOffsetCheck[offsetof(VATS, eMode) == 8 ? 1 : -1];
typedef char VATSCameraOffsetCheck[offsetof(VATS, pCamera) == 0x10 ? 1 : -1];

float BSTimer_QGlobalTimeMultiplierTarget();

extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern VATS DAT_011f2250;
extern bool DAT_011f21d0;
extern SettingT_GameSettingCollection_ DAT_011cf374;


#include "../../../../include/bhkWorld.h"

// @fnv 0x0093e770
void VATS::Update(int mode, bool force)
{
    g_timeGlobal.ApplyGlobalTimeMultiplier();
    if (reinterpret_cast<PlayerCharacter*>(this)->GetAnimation(
            !reinterpret_cast<PlayerCharacter*>(this)->PlayerCharacter_Is3rdPerson()))
    {
        reinterpret_cast<PlayerCharacter*>(this)
            ->GetAnimation(!reinterpret_cast<PlayerCharacter*>(this)->PlayerCharacter_Is3rdPerson())
            ->Animation_SetGlobalTimeMultiplier(1.0f);
    }
    if (mode == 2 && (force || !PlayerCharacter::UpdatePlayerStatus()))
    {
        reinterpret_cast<CameraPathManager*>(g_thePlayer)->SetCameraPathEnabled(false, 3);
        DAT_011f2250.QuitVATSPlayback(false, true);
        reinterpret_cast<BGSCameraShot*>(&DAT_011f2250)->ResetCameraShot();
        reinterpret_cast<NiPoint3Interpolator*>(&DAT_011f2250)->CreateObject(0, true);
        DAT_011f21d0 = true;
    }
    reinterpret_cast<PlayerCharacter*>(this)->fVATSTimer = 0.0f;
}

// @fnv 0x009c8cc0
float VATS::GetModeTimeMultiplier()
{
    float multiplier = 1.0f;
    if (eMode == 4)
    {
        if (pCamera && !static_cast<CameraShotExtra*>(pCamera)->IsInitialized())
            multiplier = 1.0f;
        else if (pCamera && static_cast<CameraShotExtra*>(pCamera)->TESCombatStyle_GetTargetingFOV() > 0.0)
            multiplier = static_cast<CameraShotExtra*>(pCamera)->TESCombatStyle_GetTargetingFOV();
        else
            multiplier = DAT_011cf374.Float()->f;
    }
    multiplier *= BSTimer_QGlobalTimeMultiplierTarget() / hkpCharacterContext::GetReferenceTimeStep();
    return multiplier;
}

class HitData;
typedef char _sizecheck_VATS_COMMAND[sizeof(VATSCommand) == 40 ? 1 : -1];

extern PlayerCharacter* DAT_011f21f0;

struct Animation;


struct FUN_00498910_shell
{
    void Animation_SpecialIdleFree(bool, bool);
};

struct Node
{
    VATSCommand* item;
    Node* next;
};


struct StandIn
{
    void* FUN_009c8870(unsigned int);
};

// @fnv 0x009ca410
void VATS::ProcessVATSCommands()
{
    if (*(void**)((char*)this + 0x24))
    {
        ((FUN_00498910_shell*)((const Actor*)DAT_011f21f0)->GetAnimation())->Animation_SpecialIdleFree(true, false);
        *(void**)((char*)this + 0x24) = 0;
    }

    while (!FUN_008256d0())
    {
        VATSCommand* pcommand = FUN_006815c0()->item;
        VATSCommand* pItem = pcommand;
        VATSCommand* pItemCopy = pItem;
        pItemCopy ? ((StandIn*)pItemCopy)->FUN_009c8870(1) : 0;
        FUN_0063f7b0();
    }
}

extern float DAT_011afe74;
extern float DAT_011afe78;
extern unsigned char DAT_012677cc;

// Returns DAT_011afe78 when DAT_012677cc is set, otherwise DAT_011afe74.
// @fnv 0x009c8ef0
// src: COMMUNITY 0x009c8ef0
float __cdecl bhkWorld_GetMaxPickTime()
{
    float fResult;
    if (DAT_012677cc)
        fResult = DAT_011afe78;
    else
        fResult = DAT_011afe74;
    return fResult;
}

struct SoundListEntry;

struct SoundListView
{
    void AddTail(SoundListEntry* const&);
    void AddCommand(SoundListEntry* apCommand);
};

// @fnv 0x009c71a0
void SoundListView::AddCommand(SoundListEntry* apCommand)
{
    AddTail(apCommand);
}

struct ListHolder
{
    bool _ref_008256d0();
    void* _ref_006815c0();
    void* VATS_GetCurrentAction();
};

// @fnv 0x009c71c0
// src: XBOX_PDB 0x009c71c0
void* ListHolder::VATS_GetCurrentAction()
{
    if (!_ref_008256d0())
        return *(void**)_ref_006815c0();
    return 0;
}

struct MyList
{
    bool _ref_008256d0();
    MyList* _ref_00726070();
    VATSCommand** _ref_006815c0();
    VATSCommand* VATS_GetLastAction();
};
// @fnv 0x009c71f0
// src: XBOX_PDB 0x009c71f0
VATSCommand* MyList::VATS_GetLastAction()
{
    MyList* iter;
    iter = this;
    while (iter && !iter->_ref_008256d0())
    {
        if (!iter->_ref_00726070())
            return *iter->_ref_006815c0();
        iter = iter->_ref_00726070();
    }
    return 0;
}

float __cdecl bhkWorld_GetMaxPickTime();
extern float DAT_012677c4;
// Returns true when the pick count override is not active and FUN_009c8ef0() is less than DAT_012677c4; otherwise false.
// @fnv 0x009c8ea0
// src: COMMUNITY 0x009c8ea0
bool __cdecl bhkWorld_GetPickTimeOverMax()
{
    return !bhkWorld::QPickCountOverride() ? bhkWorld_GetMaxPickTime() < DAT_012677c4 : false;
}

// @fnv 0x009c9900
void CameraShotExtra::SetByteAt76(unsigned char param_2)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x76) = param_2;
}

struct FUN_009ca4a0
{
    void VATS_COMMAND_Initialize();
    FUN_009ca4a0();
};

// @fnv 0x009ca4a0
FUN_009ca4a0::FUN_009ca4a0()
{
    VATS_COMMAND_Initialize();
}

struct Helper62d0
{
    Helper62d0& operator=(void const*);
};

struct FUN_009d9ec0_shell
{
    void AssignAtOffsetB0(void* p);
};

// @fnv 0x009d9ec0
void FUN_009d9ec0_shell::AssignAtOffsetB0(void* apValue)
{
    ((Helper62d0*)((char*)this + 0xb0))->operator=(apValue);
}

struct FUN_0063cfe0_Inner
{
    virtual ~FUN_0063cfe0_Inner();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct FUN_0063cfe0_shell
{
    char _pad_00[0x18];
    FUN_0063cfe0_Inner m_inner;
    void TESClimate_GetNightSkyModel();
};

// @fnv 0x0063cfe0
// src: COMMUNITY 0x0063cfe0
void FUN_0063cfe0_shell::TESClimate_GetNightSkyModel()
{
    m_inner.v5();
}

struct VATS_COMMAND_LIST
{
    VATS_COMMAND_LIST();
    int iType;
    bool bFlag;
    char _pad_6[2];
    char _pad_8[4];
    PlayerCharacter* pOwner;
    char _pad_10[24];
    void __thiscall CreateCommandAndUpdateHUD();
};
// @fnv 0x009ca1f0
void __thiscall VATS_COMMAND_LIST::CreateCommandAndUpdateHUD()
{
    ((VATS*)this)->QuitVATSPlayback(false, false);
    VATS_COMMAND_LIST* pCommand = new VATS_COMMAND_LIST;
    pCommand->iType = 15;
    pCommand->bFlag = true;
    pCommand->pOwner = g_thePlayer;
    ((SoundListView*)this)->AddCommand((SoundListEntry*)pCommand);
    ((NiPoint3Interpolator*)this)->CreateObject(4, false);
    HUDMainMenu::UpdateVisibilityState(4);
}

bool __cdecl ActionPoints_IsAttackAction(int);


// No include/HitData.h exists yet; constructor/reset at 0x009b4d90/0x009b4dc0 use this 0x64-byte layout.
class HitData
{
  public:
    Actor* m_pAggressor;
    TESObjectREFR* pTarget;
    TESObjectREFR* m_pSourceReference;
    unsigned int m_uiHitLocation;
    unsigned int m_uiHitFlags;
    float m_fDamage;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    TESObjectWEAP* pWeapon;
    float m_fWeaponDamage;
    NiPoint3 vOffset1;
    NiPoint3 vOffset2;
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;

    HitData();
    void ClearData_009b4dc0();
    void SetFlag(int flag, bool val);
};
typedef char HitDataSizeCheck[sizeof(HitData) == 0x64 ? 1 : -1];

void __cdecl SetContextInfo(HitData*, VATSCommand*);


// @fnv 0x009c8e00
// src: COMMUNITY 0x009c8e00
void VATS::EvaluateCommand(VATSCommand* apCommand)
{
    if (apCommand && ActionPoints_IsAttackAction(apCommand->eAction))
    {
        if (apCommand->bSuccess && apCommand->pTarget && !bhkWorld_GetPickTimeOverMax())
        {
            if (!DAT_011f21f0->Actor_LineOfSight(1, (Actor*)apCommand->pTarget, 1, 0, 0))
            {
                apCommand->bSuccess = false;
            }
        }

        if (apCommand->m_pActionObject)
        {
            apCommand->m_pActionObject->ClearData_009b4dc0();
        }

        SetContextInfo(apCommand->m_pActionObject, apCommand);
    }
}

struct NiLight;
struct ShadowSceneLight;


struct FUN_009c9a50_shell
{
    char pad_00[0x34];
    GO m_34;

    void SetLight(NiLight* apLight, bool abClear);
};

// @fnv 0x009c9a50
void FUN_009c9a50_shell::SetLight(NiLight* apLight, bool abClear)
{
    if (abClear && m_34 != 0)
    {
        m_34 = 0;
    }

    if (apLight)
    {
        m_34 = NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)->GetShadowSceneLight(apLight, true);
        NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)->AttachChildInAvailableSlot((NiAVObject*)apLight, true);
    }
}

void* __cdecl operator new(unsigned int);


struct FUN_009ca500_shell : public VATSCommand
{
    void VATS_COMMAND_Initialize();
};

// @fnv 0x009ca500
// src: XBOX_PDB 0x009ca500
void FUN_009ca500_shell::VATS_COMMAND_Initialize()
{
    eAction = 0x16;
    bSuccess = false;
    m_kFieldAfterWeaponFlags = false;
    m_bFirstActionFlag = false;
    m_bSecondActionFlag = false;
    m_ucFirstActionCode = 0;
    m_ucSecondActionCode = 0;
    pTarget = 0;
    m_iActionValue = 0x4d;
    m_pActionObject = new HitData();
    m_fArmorDamage = 0.0f;
    m_fOverrideActionPoints = 0.0f;
    m_fHealthDamage = 0.0f;
    m_bFinalActionFlag = false;
}


extern int DAT_011f21b8;

// @fnv 0x009c8c40
void VATS::SetValue(int a)
{
    m_pTargetProjectile = reinterpret_cast<Projectile*>(a);
    if (pCamera != 0)
    {
        HandleCommand(VATS_GetCurrentAction());
        if (m_fCameraDuration == 0.0)
        {
            bool ok = true;
            while (pCamera != 0 && ok && DAT_011f21b8 > static_cast<CameraShotExtra*>(pCamera)->GetField38())
                ok = UseNextCamera();
        }
    }
}

extern TESObjectREFR* DAT_011f21cc;


// Clears DAT_011f21cc if it equals target, then walks the command list removing every command whose pTarget is target.
// @fnv 0x009c9e90
void VATS::RemoveCommandsForTarget(TESObjectREFR* target)
{
    if (target == DAT_011f21cc)
        DAT_011f21cc = 0;

    BSSimpleList<VATSCommand*>* current = &m_kCommandList;
    BSSimpleList<VATSCommand*>* previous = 0;
    while (current != 0 && !current->IsEmpty())
    {
        VATSCommand* command = current->GetItem();
        if (command->pTarget == target)
        {
            VATSCommand* temporary = command;
            VATSCommand* deleting = temporary;
            deleting ? reinterpret_cast<StandIn*>(deleting)->FUN_009c8870(1) : 0;

            if (previous)
            {
                previous->Remove(command);
                current = previous->GetNext();
            }
            else
            {
                current->RemoveHead();
            }
        }
        else
        {
            previous = current;
            current = current->GetNext();
        }
    }
}

struct VatsCmd9c9
{
    int m_eRequestType;
};
struct VatsList9c9
{
    VatsCmd9c9** FUN_006815c0();
    bool IsValidCommand(VatsCmd9c9* pkCmd);
};

// @fnv 0x009c9f60
bool VatsList9c9::IsValidCommand(VatsCmd9c9* pkCmd)
{
    VatsCmd9c9* pkCommand = pkCmd;
    if (!pkCommand)
        pkCommand = *FUN_006815c0();
    if (pkCommand)
    {
        switch (pkCommand->m_eRequestType)
        {
        case 0:
        case 1:
        case 2:
        case 16:
        case 17:
        case 20:
        case 21:
            return true;
        }
    }
    return false;
}


struct ThisStub
{
    void Animation_UpdateSceneGraphNoController();
};


class TemporaryEffect
{
  public:
    float GetAlphaMult();
    void SetProcessValue(float);
    void FUN_008c4640();
};
extern TemporaryEffect* DAT_011f21e8;
extern TemporaryEffect* DAT_011f21ec;

struct TIM_008b2010
{
    TESIdleForm* FUN_00600950(PlayerCharacter*, TESObjectREFR*);
};
extern TIM_008b2010* DAT_011cb6a0;

using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting548;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting554;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting555;

struct TESObjectWEAP;

void PlayMysteriousStrangerMusic();
float __cdecl GetActorReach(Actor*, int);
bool __fastcall TESObjectWEAP_IsMeleeWeapon(TESObjectWEAP*);
bool __cdecl BuildPathingRequest(PlayerCharacter*, TESObjectREFR*, float, NiPoint3*);
void FNV_Warning(const char*, ...);


// @fnv 0x009c9280
void VATS::ExecuteVATSMeleeAttack(VATSCommand* pAttackCmd)
{
    if (pAttackCmd->m_ucFirstActionCode)
    {
        if ((TemporaryEffect*)DAT_011f21f0 == DAT_011f21e8 || (TemporaryEffect*)DAT_011f21f0 == DAT_011f21ec ||
            this->IsValidCommand(pAttackCmd))
        {
            if (pAttackCmd->pTarget)
            {
                float fDistance = 0.0f;
                if (pAttackCmd->m_bFirstActionFlag)
                {
                    fDistance = *originalRuntimeFloatSetting548.Float();
                    if (DAT_011f21e8->GetAlphaMult() != 1.0)
                    {
                        DAT_011f21e8->SetProcessValue(1.0f);
                        DAT_011f21e8->FUN_008c4640();
                        PlayMysteriousStrangerMusic();
                    }
                }
                else if (pAttackCmd->m_bFinalActionFlag)
                {
                    fDistance = *originalRuntimeFloatSetting548.Float();
                    if (DAT_011f21ec->GetAlphaMult() != 1.0)
                    {
                        DAT_011f21ec->SetProcessValue(1.0f);
                        DAT_011f21ec->FUN_008c4640();
                        PlayMysteriousStrangerMusic();
                    }
                }
                else
                {
                    fDistance =
                        GetActorReach((Actor*)DAT_011f21f0, (int)((Actor*)DAT_011f21f0)->Actor_GetCurrentWeapon());
                    if (!((Actor*)DAT_011f21f0)->Actor_GetCurrentWeapon())
                    {
                        fDistance *= *originalRuntimeFloatSetting554.Float();
                    }
                    else if (TESObjectWEAP_IsMeleeWeapon((TESObjectWEAP*)((Actor*)DAT_011f21f0)->Actor_GetCurrentWeapon()))
                    {
                        fDistance *= *originalRuntimeFloatSetting555.Float();
                    }
                }

                NiPoint3 targetPos;
                if ((TemporaryEffect*)DAT_011f21f0 == DAT_011f21e8 || (TemporaryEffect*)DAT_011f21f0 == DAT_011f21ec)
                {
                    ((TESObjectREFR*)DAT_011f21f0)->SetLocationOnReference(*((const TESObjectREFR*)g_thePlayer)->GetPos());
                }

                if (BuildPathingRequest(DAT_011f21f0, pAttackCmd->pTarget, fDistance, &targetPos))
                {
                    ((Actor*)DAT_011f21f0)->SetPos(&targetPos);
                    reinterpret_cast<void (__thiscall*)(Actor*, TESObjectREFR*)>((*reinterpret_cast<void***>(DAT_011f21f0))[0xB0])((Actor*)DAT_011f21f0, pAttackCmd->pTarget);
                    if (g_thePlayer == DAT_011f21f0 && !this->VATS_GetLineOfSight(pAttackCmd))
                    {
                        ((Actor*)DAT_011f21f0)->SetPos(((const TESObjectREFR*)pAttackCmd->pTarget)->GetPos());
                        reinterpret_cast<void (__thiscall*)(Actor*, TESObjectREFR*)>((*reinterpret_cast<void***>(DAT_011f21f0))[0xB0])((Actor*)DAT_011f21f0, pAttackCmd->pTarget);
                    }
                }
                else
                {
                    ((Actor*)DAT_011f21f0)->SetPos(((const TESObjectREFR*)pAttackCmd->pTarget)->GetPos());
                    reinterpret_cast<void (__thiscall*)(Actor*, TESObjectREFR*)>((*reinterpret_cast<void***>(DAT_011f21f0))[0xB0])((Actor*)DAT_011f21f0, pAttackCmd->pTarget);
                }

                ((ThisStub*)((TESObjectREFR*)DAT_011f21f0)->GetAnimData())->Animation_UpdateSceneGraphNoController();
            }
        }

        this->m_pIdleForm = DAT_011cb6a0->FUN_00600950(DAT_011f21f0, pAttackCmd->pTarget);
        if (this->m_pIdleForm)
        {
            if (this->m_pIdleForm->GetFlagsMasked() != 4)
            {
                FNV_Warning(
                    "COMBAT: Bad VATS Melee Attack '%s' in the idle manager. Attacks should be tagged for 'Weapon' anim group section.",
                    this->m_pIdleForm->GetName());
                this->m_pIdleForm = 0;
            }
        }
    }
}

namespace fnv_009c9ae0 {
// 0x009c9ae0  unit_21e1906d19b4.cpp  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, 1 stack arg (ret 4) - VATS point-light update.


struct LightTarget9c9
{
    NiAVObject* ShadowSceneLight_GetLight();
};
struct FloatGlobal9c9
{
    float FUN_00450410();
};


NiPoint3 NiPoint3_TransformByMatrix3(NiPoint3 const& krValue, float const* pafMatrix);
float LinearInterpolate(float a, float b, float c, float d, float e);
float BSMAX_00404010(float a, float b);
float BSMIN(float a, float b);

extern Actor* g_pkPlayer9c9;
extern FloatGlobal9c9 DAT_011f2304;
extern FloatGlobal9c9 DAT_011f222c;
extern FloatGlobal9c9 DAT_011f220c;
extern FloatGlobal9c9 DAT_011f2200;
extern FloatGlobal9c9 DAT_011f2298;
extern SettingT_GameSettingCollection_ DAT_011f22cc;
extern SettingT_GameSettingCollection_ DAT_011f22a8;
extern SettingT_GameSettingCollection_ DAT_011f21f4;

}  // namespace fnv_009c9ae0

// @fnv 0x009c9ae0
// src: XBOX_PDB 0x009c9ae0
void VATS::UpdateVATSLight(Actor* apActor)
{
    using namespace fnv_009c9ae0;
    if (apActor->IsActor())
    {
        if (apActor->GetNiNode())
        {
            if (reinterpret_cast<LightTarget9c9*>(m_spShadowSceneLight.operator->()))
            {
                Actor* pOwner = apActor;
                if (pOwner->GetProcess())
                {
                    NiPoint3 kCenter5 = (const NiPoint3&)((const NiAVObject*)apActor->GetNiNode())->NiAVObject_GetWorldBound().GetNavMeshData();
                    NiPoint3 aKDir = *(const NiPoint3*)((const Actor*)g_pkPlayer9c9)->GetPos() - *(const NiPoint3*)((const Actor*)apActor)->GetPos();

                    // The 36-byte rotation uses the shared matrix; 0x004a0c90 is its Z rotation helper.
                    NiMatrix3 kRotX;
                    kRotX.MakeZRotation(DAT_011f2304.FUN_00450410());

                    aKDir.Unitize();
                    aKDir = NiPoint3_TransformByMatrix3(aKDir, (float const*)&kRotX);
                    aKDir *= DAT_011f222c.FUN_00450410();

                    kCenter5 = kCenter5 + aKDir;
                    kCenter5.z += DAT_011f220c.FUN_00450410();

                    NiPoint3 kOffset5(DAT_011f21f4.Float()->f, DAT_011f22a8.Float()->f,
                                      DAT_011f22cc.Float()->f);

                    int iOutVal = 0;
                    float fA9 = 0.0f;
                    float fB_ = 0.0f;

                    NiPoint3 _kSpawn = *(const NiPoint3*)((const Actor*)pOwner)->GetPos() + NiPoint3(0.0f, 0.0f, ((const Actor*)pOwner)->GetActorHeight());

                    float fScaleTmp =
                        ((ShadowSceneNode*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0U))->FUN_00b5b610(_kSpawn, &iOutVal, &fA9, &fB_, *(const NiPoint3*)((const Actor*)g_pkPlayer9c9)->GetPos(),
                                                      reinterpret_cast<LightTarget9c9*>(m_spShadowSceneLight.operator->())->ShadowSceneLight_GetLight()) *
                        100.0;

                    float fRadiusTmp;
                    float _fRange = BSMIN(
                        1.0f, BSMAX_00404010(0.0f, LinearInterpolate(1.0f, 0.0f, DAT_011f2298.FUN_00450410(),
                                                                   DAT_011f2200.FUN_00450410(), fScaleTmp)));

                    kOffset5 *= _fRange;

                    fRadiusTmp = (kCenter5 - (const NiPoint3&)((const NiAVObject*)apActor->GetNiNode())->NiAVObject_GetWorldBound().GetNavMeshData()).Length() * 2.0f;

                    reinterpret_cast<LightTarget9c9*>(m_spShadowSceneLight.operator->())->ShadowSceneLight_GetLight()->NiAVObject_SetWorldTranslate(&kCenter5);
                    reinterpret_cast<LightTarget9c9*>(m_spShadowSceneLight.operator->())->ShadowSceneLight_GetLight()->FUN_0050dd50((const ::NiPoint3&)NiPoint3(fRadiusTmp, 0.0f, 0.0f));
                    ((NiPointLight*)reinterpret_cast<LightTarget9c9*>(m_spShadowSceneLight.operator->())->ShadowSceneLight_GetLight())->SetEffectColor((const ::NiPoint3&)kOffset5);
                    reinterpret_cast<LightTarget9c9*>(m_spShadowSceneLight.operator->())->ShadowSceneLight_GetLight()->SetAppCulled(false);
                }
            }
        }
    }
}

namespace fnv_009c9fe0 {


struct Cmd9c9
{
    int m_kNextStreamField[3];
    TESObjectREFR* m_pkTarget;
};

struct CmdList9c9
{
    Cmd9c9** FUN_006815c0();
    NiPoint3 VATS_GetTargetPercentagePos(float fDistance);
};

// @fnv 0x009c9fe0
// src: COMMUNITY 0x009c9fe0
NiPoint3 CmdList9c9::VATS_GetTargetPercentagePos(float afScale)
{
    NiPoint3 kPlayerPos = (const NiPoint3&)((TESObjectREFR*)DAT_011f21f0)->Get3D()->NiAVObject_GetWorldBound().GetNavMeshData();
    Cmd9c9* pkCmd = *FUN_006815c0();
    if ((pkCmd && pkCmd->m_pkTarget) || DAT_011f21cc)
    {
        NiPoint3 kTarget = NiPoint3::ZERO;
        if (pkCmd && pkCmd->m_pkTarget)
        {
            if (pkCmd->m_pkTarget->GetNiNode())
                kTarget = (const NiPoint3&)((const NiAVObject*)pkCmd->m_pkTarget->GetNiNode())->NiAVObject_GetWorldBound().GetNavMeshData();
            else
                kTarget = *(const NiPoint3*)((const TESObjectREFR*)pkCmd->m_pkTarget)->GetPos();
        }
        else if (DAT_011f21cc)
        {
            if (((TESObjectREFR*)DAT_011f21cc)->GetNiNode())
                kTarget = (const NiPoint3&)((const NiAVObject*)((TESObjectREFR*)DAT_011f21cc)->GetNiNode())->NiAVObject_GetWorldBound().GetNavMeshData();
            else
                kTarget = *(const NiPoint3*)((const TESObjectREFR*)DAT_011f21cc)->GetPos();
        }
        NiPoint3 kDirection = kTarget.SubtractIntoVector(kPlayerPos);
        float fScaleMultiplier = kDirection.FUN_00457910();
        kPlayerPos.ComputeValue_0063c8a0(kDirection.ApplyScaled(fScaleMultiplier).ApplyScaled(afScale).ProcessAndReturnValue_0053d280(100.0f));
    }
    return kPlayerPos;
}
}  // namespace fnv_009c9fe0

struct FUN_009c95e0_AnimGroup
{
    bool FUN_004937c0();
    bool FUN_004937e0();
};
struct FUN_009c95e0_Seq
{
    FUN_009c95e0_AnimGroup* GetAnimGroup();
};
struct FUN_009c95e0_Anim
{
    FUN_009c95e0_Seq* Animation_GetCurrentSequence(int a);
    int GetSlotValue(int a);
};
extern SettingT_GameSettingCollection_ DAT_011cf81c;

extern int DAT_011f21b8;

// Processes a VATS command, updating the camera state flag DAT_011f21b8 based on validity, animation, and target distance checks.
// @fnv 0x009c95e0
void VATS::HandleCommand(VATSCommand* command)
{
    if (IsValidCommand(command))
    {
        FUN_009c95e0_Anim* animation = (FUN_009c95e0_Anim*)((const Actor*)DAT_011f21f0)->GetAnimation();
        if (DAT_011f21b8 == 0)
        {
            FUN_009c95e0_Seq* sequence = animation->Animation_GetCurrentSequence(4);
            if (!sequence || (sequence->GetAnimGroup()->FUN_004937c0() && command->m_ucFirstActionCode == 0) ||
                (sequence->GetAnimGroup()->FUN_004937e0() && animation->GetSlotValue(4) >= 1))
            {
                DAT_011f21b8 = 2;
            }
            else if (command->pTarget)
            {
                if (command->pTarget->HasHealth(false))
                    DAT_011f21b8 = 2;
            }
            if (DAT_011f21b8 == 2)
            {
                if (m_fCameraDuration == 0.0)
                {
                    bool flag = true;
                    while (flag && DAT_011f21b8 > static_cast<CameraShotExtra*>(pCamera)->GetField38())
                        flag = UseNextCamera();
                }
            }
        }
        return;
    }
    if (command && command->eAction == 0x12)
    {
        DAT_011f21b8 = 2;
        static_cast<CameraShotExtra*>(pCamera)->SetByteAt76(1);
        return;
    }
    if (m_pSource && DAT_011f21b8 == 0)
        DAT_011f21b8 = 1;
    if (m_pSource || m_pTargetProjectile)
    {
        if (!m_pSource)
            DAT_011f21b8 = 2;
        else if (m_pSource && m_pTargetProjectile && (!pCamera || static_cast<CameraShotExtra*>(pCamera)->GetField38() == 2))
            DAT_011f21b8 = 2;
        else
        {
            NiPoint3 ptOffset = *static_cast<const TESObjectREFR*>(command->pTarget)->GetPos() - *reinterpret_cast<const TESObjectREFR*>(m_pSource)->GetPos();
            if (ptOffset.Length() < *DAT_011cf81c.Setting_Int() + command->pTarget->GetMaximum().y)
                DAT_011f21b8 = 2;
            else if (m_pTargetProjectile)
            {
                ptOffset = *static_cast<const TESObjectREFR*>(command->pTarget)->GetPos() - *reinterpret_cast<const TESObjectREFR*>(m_pTargetProjectile)->GetPos();
                if (ptOffset.Length() < *DAT_011cf81c.Setting_Int() + command->pTarget->GetMaximum().y)
                    DAT_011f21b8 = 2;
            }
        }
    }
    else if (DAT_011f21b8 == 1)
        DAT_011f21b8 = 2;
}


struct VatsCmd_ca2c0 : public VATSCommand
{
    VatsCmd_ca2c0();
};


// Creates a VATS command targeting a1, sets its action, success, and hit data, then queues it and updates the VATS state.
// @fnv 0x009ca2c0
// src: COMMUNITY 0x009ca2c0
void VATS::ForceTargetKillShot(TESObjectREFR* apTarget, int a2)
{
    QuitVATSPlayback(false, false);
    VATSCommand* cmd = new VatsCmd_ca2c0();
    cmd->eAction = 0x12;
    cmd->bSuccess = true;
    cmd->pTarget = apTarget;
    if (a2 == -1)
    {
        a2 = 0;
    }
    cmd->m_pActionObject->m_uiHitFlags = a2;
    if (g_thePlayer->GetCurrentProcess() && g_thePlayer->GetCurrentProcess()->GetActiveWeapon())
    {
        TESObjectWEAP* weapon = g_thePlayer->GetCurrentProcess()->GetActiveWeapon()->GetFlags();
        cmd->m_pActionObject->pWeapon = weapon;
    }
    cmd->m_pActionObject->SetFlag(0x10, true);
    DAT_011f21f0 = g_thePlayer;
    AddCommand(cmd);
    FUN_009c6c30(4, false);
}

extern SettingT_GameSettingCollection_ g_011ce7e4;

class TemporaryEffect;
extern TemporaryEffect* DAT_011f21e8;
extern TemporaryEffect* DAT_011f21ec;
void __cdecl FUN_004d5c60(int);


struct VATS_COMMAND_Del : public VATSCommand
{
    ~VATS_COMMAND_Del();
};


// Deletes the current command, removes commands meeting the target checks, then sets player state and triggers action callbacks.
// @fnv 0x009c86b0
// src: XBOX_PDB 0x009c86b0
void VATS::FreeHeadAction()
{
    if (FUN_008256d0())
    {
        return;
    }
    VATSCommand* pCmd = FUN_006815c0()->item;
    if (pCmd)
    {
        delete (VATS_COMMAND_Del*)pCmd;
        pCmd = 0;
        FUN_0063f7b0();
        if (m_pIdleForm)
        {
            ((FUN_00498910_shell*)((const Actor*)DAT_011f21f0)->GetAnimation())->Animation_SpecialIdleFree(true, false);
            m_pIdleForm = 0;
        }
        while (!FUN_008256d0())
        {
            pCmd = FUN_006815c0()->item;
            bool bRemove = false;
            if (pCmd && pCmd->pTarget)
            {
                if (((TESObjectREFR*)pCmd->pTarget)->HasHealth(false))
                {
                    bRemove = true;
                }
                else if (pCmd->m_bFirstActionFlag)
                {
                    if (((TESObjectREFR*)pCmd->pTarget)->GetHealth() > *g_011ce7e4.Setting_Int())
                    {
                        bRemove = true;
                    }
                }
            }
            if (bRemove)
            {
                delete (VATS_COMMAND_Del*)pCmd;
                pCmd = 0;
                FUN_0063f7b0();
            }
            else
            {
                break;
            }
        }
        if (pCmd && pCmd->m_bFirstActionFlag)
        {
            DAT_011f21f0 = (PlayerCharacter*)DAT_011f21e8;
            FUN_004d5c60(25);
        }
        if (pCmd && pCmd->m_bFinalActionFlag)
        {
            DAT_011f21f0 = (PlayerCharacter*)DAT_011f21ec;
            FUN_004d5c60(28);
        }
    }
}

struct CameraDisplayManager
{
    void __thiscall PlayerCharacter_SetFirstPerson(bool);
};
extern CameraDisplayManager* DAT_011dea3c;
extern unsigned char DAT_011f21d3;

// Advances the camera shot list past the current shot, updates m_fCameraDuration, and notifies the display manager or sets DAT_011f21d3.
// @fnv 0x009c9920
// src: XBOX_PDB 0x009c9920
bool __thiscall VATS::UseNextCamera()
{
    ::BSSimpleList< ::BGSCameraShot*>* nextCamera = m_pCameraShotList;
    bool found = false;
    while (nextCamera && nextCamera->GetItem() != pCamera)
    {
        nextCamera = nextCamera->GetNext();
    }
    if (nextCamera)
    {
        nextCamera = nextCamera->GetNext();
    }
    if (nextCamera)
    {
        if (pCamera)
        {
            static_cast<CameraShotExtra*>(pCamera)->ResetCameraState();
            pCamera = 0;
        }
        pCamera = nextCamera->GetItem();
        if (pCamera && m_fCameraDuration < static_cast<CameraShotExtra*>(pCamera)->GetFloatAtOffset58())
        {
            m_fCameraDuration = static_cast<CameraShotExtra*>(pCamera)->GetFloatAtOffset58();
        }
        if (pCamera && static_cast<CameraShotExtra*>(pCamera)->BGSCameraShot_IsFirstPerson())
        {
            DAT_011dea3c->PlayerCharacter_SetFirstPerson(true);
        }
        else
        {
            DAT_011f21d3 = 1;
        }
        found = true;
    }
    else if (!nextCamera && pCamera && !static_cast<CameraShotExtra*>(pCamera)->IsInitialized())
    {
        static_cast<CameraShotExtra*>(pCamera)->ResetCameraState();
        pCamera = 0;
    }
    return found;
}
