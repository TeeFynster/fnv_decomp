#pragma once

#include "Character.h"
#include "MagicTarget.h"
#include "NiAVObject.h"
#include "NiPoint3.h"
#include "BSSoundHandle.h"

class ActorCombatEntry;
class ActorRef;
class ArgObj;
class BaseB;
class BSAudio;
class BGSNote;
class BGSQuestObjective;
class BGSEntryPointPerkEntry;
class CollisionFilter;
class Form;
class InventoryDropPoint;
class InventoryStackRecord;
class MagicItem;
class MagicShaderHitEffect;
struct Matrix;
class MusicMarkerReference;
class PerkForm;
class PlayerBase;
class PlayerQuestData;
class QuestObjectiveNode;
class Ref;
class RegionSound;
class ScriptContext;
class SpellItem;
class TelekinesisReference;
class TESQuest;
class TESTopic;
class WeatherCell;

enum ACTION_FLAGS;

// Player action uses the shared global enum; process methods use _AnimationAction::Action.
#include "ANIMATION_ACTION.h"

class PlayerCharacter : public Character
{
public:
    enum ModifierGroup
    {
        TEMPORARY = 0,
        SCRIPTS = 1,
        DAMAGE = 2
    };

    union
    {
        unsigned int layoutPadding1C8[31];
        struct
        {
            unsigned char unk1C8[0x38];
            unsigned int activationState;                 // 0x200
            unsigned int unk204;
            TESPackage* pCurrentPackage;                   // 0x208
            union
            {
                bool bResting;                             // 0x20C
                bool movingThroughDoor;
            };
            unsigned char unk20D[0x37];
        };
    };
    float ActorValueModifierData[77];                      // 0x244
    float m_afScriptModifiers[77];                         // 0x378
    float ActorValueState;                                 // 0x4AC
    float ActorValueData[77];                              // 0x4B0
    union
    {
        unsigned int layoutPadding5E4[26];
        struct
        {
            BSSimpleList<BGSNote*> notes;                  // 0x5E4
            unsigned char unk5EC[0xD];
            bool regionSoundsEnabled;                     // 0x5F9
            unsigned char unk5FA[0xA];
            TESObjectREFR* lastExteriorDoor;                // 0x604
            unsigned char unk608[0x42];
            bool previousThirdPerson;                     // 0x64A
            unsigned char unk64B;
        };
    };
    union
    {
        bool bThirdPerson;                                // 0x64C
        bool thirdPerson;
    };
    unsigned char layoutPadding64D;
    unsigned short layoutPadding64E;
    unsigned int layoutPadding650[12];
    unsigned char m_ucValueAt680;                          // 0x680
    unsigned char layoutPadding681;
    unsigned short layoutPadding682;
    union
    {
        unsigned int layoutPadding684[13];
        struct
        {
            unsigned char unk684[0xC];
            Animation* p1stPersonAnimation;                // 0x690
            NiPointer<NiNode> firstPersonNode;             // 0x694
            unsigned char unk698[0x20];
        };
    };
    TESQuest* m_pCurrentQuest;                             // 0x6B8
    BSSimpleList<BGSQuestObjective*> m_kObjectiveList;      // 0x6BC
    union
    {
        unsigned int layoutPadding6C4[61];
        struct
        {
            unsigned char unk6C4[0xB0];
            BSSimpleList<RegionSound*> regionSounds;       // 0x774
            unsigned char unk77C[0x1C];
            bool underAIControl;                          // 0x798
            unsigned char unk799[0x1F];
        };
    };
    unsigned char m_ucByteAtOffset7B8;                     // 0x7B8
    unsigned char layoutPadding7B9;
    unsigned short layoutPadding7BA;
    bool m_bHasPerks;                                      // 0x7BC
    unsigned char layoutPadding7BD;
    unsigned short layoutPadding7BE;
    union
    {
        unsigned int layoutPadding7C0[47];
        struct
        {
            unsigned char unk7C0[0x1C];
            unsigned int regionSoundTimer;                // 0x7DC
            unsigned char unk7E0[0x9C];
        };
    };
    BSSimpleList<PerkForm*> Perks;                         // 0x87C
    BSSimpleList<BGSEntryPointPerkEntry*> m_kEntryPointPerks[74]; // 0x884
    BSSimpleList<PerkForm*> m_kCompanionPerks;               // 0xAD4
    union
    {
        unsigned int layoutPaddingADC[221];
        struct
        {
            unsigned char unkADC[0x288];
            ActorCombatGroup* m_pCombatData;               // 0xD64
            unsigned char unkD68[0xB0];
            float fVATSTimer;                             // 0xE18
            unsigned char unkE1C[0x34];
        };
    };

    virtual void Unk_139();
    virtual BSSimpleList<PerkForm*>* GetPerks(bool teammate);

    virtual ~PlayerCharacter();
    virtual int GetActorValue(ActorValue::Index actorValue);
    virtual ActorCombatGroup* GetCombatGroup();
    virtual unsigned char GetPerkRank(BGSPerk* perk, bool teammate);

    float GetActorValueModifierAmount(ModifierGroup modifier, ActorValue::Index actorValue);
    bool IsSleepingOrResting();
    bool IsSleepingOrResting() const;
    bool HasCombatState();
    bool GetUnderAIControl();
    void SetUnderAIControl(bool enabled);
    void UpdateCameraMode();
    void Show1stPerson(bool show);
    bool IsActorInCombatWithPlayer(Actor* actor);
    int GetCharacterLevel();
    Animation* GetAnimation(bool firstPerson);
    Animation* GetAnimation(bool firstPerson) const;
    static bool __cdecl UpdatePlayerStatus();
    BipedAnim* GetBipedAnim(bool firstPerson);
    BipedAnim* GetBipedAnimation(bool firstPerson);
    NiNode* GetNode(bool firstPerson);
    int GetPlayerLevel();
    void UpdateRadiationEffects();
    MagicShaderHitEffect* GetField6A4();
    int GetField230();
    MusicMarkerReference* GetMusicMarkerReference();
    void WriteProgressData(int value);
    void UpdatePlayerState();
    float GetScale();
    bool PlaceAtPosition(NiPoint3& position);
    bhkCharacterController* GetPhysicsCharacterController();
    ANIMATION_ACTION GetAnimAction();
    bool IsAlert();
    unsigned short GetAnimGroup(ANIM_GROUP_ENUM group, InventoryStackRecord* record,
                               bool firstPerson, Animation* animation);
    void SetActionGroupFlags(unsigned short group, ACTION_FLAGS flags);
    void ResetActorValueModifiers();
    TESObjectCELL* GetTarget();
    BSSimpleList<RegionSound*>* GetRegionSounds();
    void ResetRegionSoundTimer();
    bool IsRegionSoundsEnabled();
    void Refresh();
    void UpdateAnimationMovement(Animation* animation, float delta);
    NiPoint3* GetFieldAtOffsetDD4();
    NiPoint3 GetPosition();
    float GetLooking();
    CollisionFilter GetVectorElement();
    TESObjectCELL* GetParentCell();
    void FUN_0093dd20(); // 0x0093dd20
    int FUN_00962620(); // 0x00962620
    int GetSitSleepState();
    void SetAnimGroup(unsigned short group, int flags);
    BaseProcess* GetLogDate();
    BaseProcess* GetCurrentAIProcess();
    BaseProcess* GetCurrentAIProcess() const;
    void UpdatePlayerControls();
    void FocusOnActor(MobileObject* actor, float value, bool enabled);
    void SetAimingWeapon(bool first, bool second, bool third);
    void UpdatePlayerInventory();
    void UpdateCamera(bool first, const bool second);
    float GetLookingZAngle(int flags);
    BSSoundHandle PlayHUDSound(const char* sound, int arg2, int arg3, int arg4);
    int FindAudioEntry();
    unsigned short GetLevel();
    bool IsFastTravelAllowed();
    void SetDateTimeText(BSStringT<char>& text);
    float GetAngleZ(int flags);
    MagicCaster* GetFloatAsUInt();
    void GetCameraPosAndDir(NiPoint3* position, NiPoint3* direction, bool firstPerson);
    void SetField644(float value);
    bool V8B(int flags);
    void ModifyKarmaForTheft(int amount);
    void ModifyKarmaForStolenItem(TESForm* object, int count);
    bool HasNote(BGSNote* note);
    bool IsPlayerBipedAnimation(BipedAnim* animation);
    void ApplyHitShaderToReference(TESObjectREFR* reference);
    BSSimpleList<ActorCombatEntry*>* GetListofPerceivedActors();
    bool HasAction(void* action);
    BSSimpleList<TESTopic*>* GetSelfOffset6A8();
    int GetTerminalAccessResult(TESObjectREFR* reference);
    TESActorBase* GetActorBase();
    void ProcessAllActions();
    void* GetPlayerNode();
    bool CompleteQuestObjective(PlayerQuestData* item);
    bool AddMagicItem(MagicItem* item);
    void OnSpellRemoved(SpellItem* spell);
    void AddTopics(BSSimpleList<TESTopic*>* topics);
    bool IsSneaking();
    bool MovingCheck();
    Matrix FUN_0056fac0(const Matrix&);
    bool FUN_004eaf60();
    bool FUN_0050d4a0();
    void FUN_005c1a00(bool, int);
    void FUN_00950110(bool);
    void FUN_005098c0();
    bool FUN_00953c50(bool*);
    int FUN_00490f80();
    void FUN_00929220(MagicShaderHitEffect*);
    void FUN_005c4210(bool);
    void FUN_005c4210(unsigned char);
    void FUN_005cc7a0(bool);   // 0x005cc7a0: stores the flag at +0x79b
    int FUN_00950b00(bool firstPerson);
    void* FUN_00950bb0(int i);
    void UpdateAim(int a1, void* pkNode, float* pfX, float* pfY, int a5,
                   float m_fGridOriginX, float afWorldOriginY);
    int FUN_00963730();
    bool FUN_0088b880(int a1, Actor* target, int a3, int a4, int a5);
    TESQuest* FUN_005cbb50();
    void FUN_009529d0(int value);
    void FUN_009529d0(TESQuest* quest);
    ScriptContext* FUN_005d43c0(bool first, bool second);
    void FUN_00961280();
    void FUN_0095f930(TelekinesisReference*, int, float);
    TESObjectREFR* FUN_00798400();
    int __fastcall FUN_004f8960();
    PlayerBase* FUN_00464e10();
    void FUN_00950030();
    unsigned int FUN_0061f6c0();
    int FUN_007d1340();
    bool FUN_00878340();
    WeatherCell* FUN_005454d0();
    void FUN_00969b20();

    bool IsFlagSet() const;
    void FUN_009442e0(float value);
    float FUN_00944300();
    unsigned int GetField688();
    char GetByteAtOffset681();
    unsigned char __thiscall GetByteAt66E();
    void __thiscall SetFieldE28(float value);
    float GetFieldE28();
    bool FUN_009443c0();
    bool HasFlag400();
    bool HasFlag20000();
    void __thiscall FUN_0094c380();
    void __thiscall FUN_00621370(int value);
    unsigned int __thiscall GetField6EC();
    void FUN_0095f6a0();
    NiPoint3& FUN_0094df30(NiPoint3& destination);
    QuestObjectiveNode* GetOffset6BC();
    void FUN_00952a20(BGSQuestObjective* objective);
    bool FUN_00952830(BSAudio* topic, unsigned int sort, unsigned int flags);
    bool FUN_00952830(int value, unsigned char sort, int flags);
    void FUN_0094c8e0(BaseB* node);
    void SetArg(ArgObj* argument);
    void __thiscall ClearHelper();
    void RestorePlayerLocation(bool travel);
    bool IsPlayerTargeted(Ref* actor, bool mode);
    unsigned char FUN_00967ae0();
    unsigned char FUN_008bbc10();
    void SetActiveState(int first, int second, int third);
    float FUN_00950610(float value);
    void UpdateScopeZoom(float elapsed);
    void FUN_00960520(float delta);
    void FUN_0095f930(ActorRef* actor, int mode, float distance);
    void FUN_0095f6c0(float delta);
    void ApplyFormPayload(Form* form, int unused);
    void RemoveEnchantment(TESBoundObject* form, int unused);
    bool __thiscall FUN_009614b0(TESBoundObject* object, InventoryDropPoint* dropPoint, int first, int second);
    bool FUN_00967b70(InventoryStackRecord* record);
    void FUN_00484ce0(unsigned int, int);
    void FUN_00484d00(unsigned int, int);
    bool FUN_00969860();                        // 0x00969860
    bool FUN_008defe0();                        // 0x008defe0
};
