#pragma once

#include "TESObjectREFR.h"
#include "BSSoundHandle.h"

class Animation;
class BaseProcess;
class BGSLoadFormBuffer;
class BSFaceGenNiNode;
class CharacterControllerValue;
class DialogueResponse;
class HighProcess;
class PlayerCharacter;
class Actor;
class TESPackage;
class TESTopicInfo;
class bhkCharacterController;
enum PROCESS_TYPE;

class MobileObject : public TESObjectREFR
{
public:
    BaseProcess* m_pBaseProcess;
    TESObjectREFR* m_pLinkedReference;
    MobileObject* m_pMobileObject;
    float ProcessReferenceState;
    float ReferenceMobileState;
    bool m_bFirstFlag;
    bool m_bSecondBooleanValue;
    bool m_bThirdFlag;
    bool m_bFourthBooleanValue;
    bool m_bFifthFlag;
    bool m_bSixthFlag;
    bool m_bSeventhFlag;
    bool m_bEighthFlag;
    char m_cCharacterValue;
    bool m_bNinthFlag;
    bool m_bTenthFlag;
    bool m_bThirdActorFlag;

    virtual void StartHighProcess(void);
    virtual void Unk_91(void);
    virtual void Unk_92(void);
    virtual void Unk_93(void);
    virtual void Move(float delta, NiPoint3* movement, unsigned int flags);
    virtual void Unk_95(void);
    virtual void Unk_96(void);
    virtual void Unk_97(float);   // slot 151: Actor 0x00886360 (ret 4, reads a float arg)
    virtual void Unk_98(void);
    virtual void vfn_264(float, DialogueResponse*, bool);
    virtual void Unk_9A(float arg0);
    virtual bool IsInCombat();
    virtual void Unk_9C(void);
    virtual bool vfn_274(bool);
    virtual void vfn_278(bool);
    virtual void Unk_9F(void* arg0);
    // 0x00934fd0 (Actor 0x008b2170): ret 0x24 with the result in al; TESNPC::Activate (0x00607990) tests it for a
    // non-player Actor target.
    virtual bool vfn_280(Actor*, int, int, bool, bool, bool, bool, bool, bool);
    // Actor RTTI slot 161 (0x008a20d0): 13 stack arguments, ST0 result (UpdateDialogue 0x008dbe30).
    virtual float vfn_284(int, BSSoundHandle*, int, int, unsigned int, int, int, TESObjectREFR*, bool, bool, bool, bool, bool);
    virtual void Unk_A2(void);
    virtual void vfn_28c(TESPackage*, int);
    virtual void Unk_A4(void);
    virtual TESForm* Unk_A5(void);   // returns the +0x170 form if its type is 0x41, else 0 (Actor override 0x0087f750)
    virtual TESForm* Unk_A6(void);   // returns the +0x170 form if its type is 0x39, else 0 (Actor override 0x0087f7a0)
    virtual void Unk_A7(void);
    virtual void Unk_A8(void);
    virtual void Unk_A9(void);
    virtual void SetPos(NiPoint3* position);
    virtual void Unk_AB(NiPoint3& result);
    virtual void Unk_AC(float);    // slot 172: Actor 0x00888ac0 forwards (float) to process slot 188
    virtual double Unk_AD();       // slot 173: Actor 0x00888af0 returns process slot 189 (GetDetectionStrength)
    virtual void Unk_AE(void);
    virtual float GetCurrentTargetDistance(bool ignoreImmobile);
    virtual void SetTarget(TESObjectREFR* target); // slot +0x2c0: Actor RTTI 0x0087d5e0 forwards its pointer argument, ret 4
    virtual void SetFurnitureHeading(float heading);
    virtual TESObjectREFR* GetPackageTargetRef();
    virtual bool IsWithinDistance(NiPoint3* apPoint, float afRadius, bool abCheckZ, bool abExact);
    virtual void Unk_B4(void);
    virtual void Unk_B5(void);
    virtual void Unk_B6(void);
    virtual void SetActorEssentialState(int value);
    virtual void Unk_B8(void);
    virtual void Unk_B9(void);
    virtual bool GetIsDying();
    virtual void Unk_BB(void);
    virtual void Unk_BC(void);
    virtual void Unk_BD(TESPackage*, int, int);  // 0x2f4: takes a package and two flags (callers in backuppackage/character/lowprocess/highprocess)
    virtual void Update(float delta);
    virtual void Unk_BF(void);
    virtual void Unk_C0(void);

    MobileObject();
    virtual ~MobileObject();
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual NiPoint3* GetPos() const;
    virtual bool IsProjectile() const;

    bool HasSaidTopicInfo(TESTopicInfo* info);
    bhkCharacterController* GetPhysicsCharacterController();
    bool IsActorDead();
    bool GetCharControllerFlag() const;
    BSSoundHandle PlaySoundByEditorName(const char* editorName, bool loop, unsigned int flags, bool unused);
    void AdvanceMovement(float delta);
    float GetLooking() const;
    bool IsInDialogueWithPlayer() const;
    void ProcessAnimation();
    TESPackage* GetCurrentPackage();
    TESPackage* GetCurrentPackage() const;
    bool IsCombatStateActive() const;
    void SetChaseMode(bool chase);
    void SetFlag86(bool);
    bool IsTalkingActivator() const;
    bool GetShouldUseEmotionAnimation() const;
    BaseProcess* GetCurrentAIProcess() const;
    BaseProcess* GetCurrentProcess();
    PROCESS_TYPE GetProcessTier() const;
    int GetProcessTier();
    unsigned int GetCurrentProcessLevel();
    float GetActorHeight() const;
    const char* GetFullName();
    bool IsInThirdPerson();
    float GetRelevantWaterHeight();
    float GetRelevantWaterHeight() const;
    TESObjectCELL* GetParentCell();
    HighProcess* GetHighProcess();
    void SetProcessFlags(unsigned int, unsigned int);
    CharacterControllerValue GetVectorElement();
    void ApplyLoadBuffer(BGSLoadFormBuffer* buffer);
    void SayResponse(float delay, void* response);
    void vfn_264(float delay, void* response);

    float AdjustRot(unsigned int arg1);
    Animation* GetAnimation();
    bool IsAnimationDriven();
    const char* GetEditorID();
    BSFaceGenNiNode* GetFaceGenNodeBiped(unsigned int);
    BSFaceGenNiNode* GetFaceGenNodeSkinned(unsigned int);

    using TESObjectREFR::IsDead;
    bool IsDead();
    void FUN_008c30a0() {}

    bool FUN_00440d80();
    bool FUN_00440da0();
    bool MobileObject_IsTalkingActivator();
    bool IsSwimming_005a2030() const;
    bool Actor_IsAtPoint(const NiPoint3& targetPos, float radius, bool addCharRadius, bool check3D);
    BaseProcess* FUN_008d8520();
    BaseProcess* FUN_008d8520() const;
    void ArrowProjectile_InitLoadGame(unsigned int, unsigned int);
    int FUN_00931850();
    bool FUN_009336c0();
    void MobileObject_StopCurrentDialogue();

    TESObjectREFR* GetCurrentTarget();
    void Unk_B3(void);
    bool IsMagicProjectile();
    void Unk_94(void);
    void Unk_99(void);
    void Unk_9A(void);
    void Unk_9B(void);
    void Unk_9D(void);
    void Unk_9E(void);
    void Unk_9F(void);
    void Unk_A0(void);
    void Unk_A3(void);
    void Unk_A3(void* arg0, bool arg1);
    void Unk_AA(void);
    void Unk_AA(NiPoint3& arg0);
    void Unk_AB(void);
    void Unk_B1(void);
    void Unk_B2(void);
    void Unk_B7(void);
    bool Unk_BA();
    void Unk_BE(void);
    void vfn_2c4(float);
    TESObjectREFR* vfn_2c8();
    bool vfn_2e8();

    bool V137();
    bool V198();
    void V200(TESObjectREFR*, bool);
};
