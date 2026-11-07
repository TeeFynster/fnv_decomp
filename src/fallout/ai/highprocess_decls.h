// fallout/ai/highprocess_decls.h: declares TESObjectCELL, NiPoint3, NiPoint3, BSAudio, BaseProcess and more
#ifndef FNV_HIGHPROCESS_DECLS_H
#define FNV_HIGHPROCESS_DECLS_H

class QuestDialogueInfo;
class TESIdleForm;
class TESObjectWEAP;
class NiAVObject;


#include "ActorPackageContext.h"


class Animation;
class BSAnimGroupSequence;
class NiBSBoneLODController;
class GlobalObject_0045d260;
class DetectionEvent;
class DetectionViewData;
class ActorGroupState;
class ActorValueStore;
class KFModel;
class LipSyncAnimation;
class MuzzleFlash;
class DetectionEventData;
class TopicInfoRecord;
class ActorPathingMessageQueue;
class PathingRequest;
class NiBillboardNode;
class BSBound;
class ActorSupportClass;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class BooleanFloatQuery;
class FurnitureMark;
class bhkCharacterController;
class bhkSimpleShapePhantom;
class MiddleHighProcess__DeferredHideLimb;
class QueuedFile;
class PaddedFloatRecord;
class TESEffectShader;
class ArrowProjectile;
class ActorCombatGroup;

class ActorValueStore
{
  public:
    unsigned char state[0x268];
    ActorValueStore();
    void ResetCacheValues();
    bool CachedActorValues_IsDirty(ActorValue::Index);
    void CachedActorValues_SetActorValue(ActorValue::Index, float);
    float GetFloatAt(ActorValue::Index);
    void InvalidateValue(ActorValue::Index);
};
class LipSyncAnimation
{
  public:
    ~LipSyncAnimation();
    static void operator delete(void*);
};

class GlobalObject_0040e0b0
{
};

#include "../../../include/SettingT_GameSettingCollection_.h"
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting175;
class HighProcessDetectionActor
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual DetectionViewData* vfn_f0(Actor*, int, bool, int, int, bool, bool);
    virtual void vfn_f4();
    virtual DetectionEvent* vfn_f8(Actor*);
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual bool vfn_22c(bool);
};


class DoorCell
{
  public:
    TESForm* GetOwner();
};


class HighProcessCellView
{
  public:
    bool TESObjectCELL_GetOffLimits();
};
class HighProcessPlayerAlpha
{
  public:
    unsigned char state[0xc8];
    float alpha;
};



#include "../../../include/QuestDialogueInfo.h"
extern ProcessLists g_processLists;   // 0x011e0e80
extern GlobalObject_0045d260 g_011e0244;
extern BSSimpleList<TESTopicInfo*> DAT_011e0280;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting87, originalRuntimeFloatSetting103,
    originalRuntimeFloatSetting922;
extern SettingT_GameSettingCollection_ DAT_011cf788;
extern const double DAT_01084d28, runtimeInitializationDouble2;
int AiFormulas_GetDetectedEvent(int, bool, float, int, int, bool, bool, bool, int, bool, bool);




class HighProcessCombatSource
{
  public:
    bool TESRace_GetPlayable();
};


double TESAIForm_GetConfidenceLevel(unsigned char);
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting106;
extern GlobalObject_0040e0b0 g_011cdf10;
extern SettingT_GameSettingCollection_ DAT_011cf414;




class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
    double FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting109;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting108;
class DetectionEventData
{
  public:
    TESObjectREFR* target;
    NiPoint3 position;
};
class ScriptLocals;
class BSPortalGraph;


unsigned int DialogueRandom();
extern const float g_011c72ac_arg1;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting134;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting135;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting136;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting137;

class CombatDamageCalculator
{
  public:
    static double GetDamageMultiplier(float, float);
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting148;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting147;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting138;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting139;
extern unsigned int DAT_011e01e0;





class DetectionViewData
{
  public:
    Actor* pActor;
    DETECTION_LEVEL m_eDetectionLevel;
    int iLevel;
    NiPoint3 m_kActorPosition;
    CombatTargetTimestamp m_abyActorState;
    bool b360view, m_bCombatState, m_bHasLineOfSight, m_bIsDetected;
    int m_iDetectionValue;
    DetectionViewData();
    void LoadGame(BGSLoadGameBuffer*);
    void ResolveActorFormId();
};
// include/ has no DetectionEvent.h yet; keep the one checked 0x1c-byte layout here.
class DetectionEvent
{
  public:
    int type;
    NiPoint3 position;
    CombatTargetTimestamp time;
    int state;
    TESObjectREFR* source;
    DetectionEvent();
    void LoadFields_008d72e0(BGSLoadFormBuffer*);
    void SetTargetReference(BGSLoadFormBuffer*);
};
class TopicInfoRecord
{
  public:
    unsigned char state[52];
    TopicInfoRecord();
    void FUN_008d7420(BGSLoadFormBuffer*);
    void UpdateFields_008d74a0(BGSLoadFormBuffer*);
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
#include "../../../include/FADER_ENUM.h"
class FaderManager
{
  public:
    float GetFadeValue(FADER_ENUM);
};
// Exe callers use 0x011d8804 as the fade manager, calling GetFadeValue (0x007014e0).
extern FaderManager* DAT_011d8804;

class GlobalObject_0045d260
{
};
extern GlobalObject_0045d260 g_011e0246;
extern bool DAT_011f1221;
#include "../../../include/PTYPE.h"

class Calendar
{
  public:
    float GetGameTime();
};
extern Calendar g_calendar;
extern int* DAT_011a3ff0[];
extern const double DAT_010240c0, DAT_0101a6b0;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting246;
extern SettingT_GameSettingCollection_ DAT_011cdd30;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1045;
extern GlobalObject_0040e0b0 g_011d1314;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1046;
float BSMIN(float, float);
double NiAbs_00408820(float);
double fabsf_00408860(float);
class AIFormulas
{
  public:
    double CalculateDetectionValue(TESObjectREFR*, bool, bool);
};


class HighProcessConditions
{
  public:
    bool ContainsTrait(TESObjectREFR*, TESObjectREFR*);
};
class IdleAnimationManager
{
  public:
    TESIdleForm* FindIdleFormForObject(MobileObject*, TESObjectREFR*);
};
extern IdleAnimationManager* DAT_011cb6a0;
extern BSSimpleArray<unsigned int, 1024> DAT_011f2250;

class Animation
{
  public:
    NiControllerManager* GetControllerManager_00496940();
    void SpecialIdleFree(bool, bool);
    bool Animation_SpecialIdleDonePlaying(); // 0x004985f0
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, AnimIdle::PLAY_TYPE_ENUM);
    bool Animation_GetAnimsLoading();
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdleReady();
    bool IsSpecialIdlePlaying(TESIdleForm*);
};
class DetectionParameters;
enum ACTOR_AGGRESSION
{
    AggressionNone = 0
};

namespace ActorValue {
bool GetFlag(Index, unsigned int);
}
#include "../../../include/NiMemObject.h"

class BSFileEntry;
#include "../../../include/ACTOR_SOUND_HANDLE.h"
class LocationDescriptor
{
  public:
    BSFileEntry* SetLocRef();
    TESObjectREFR* ResolveLocationReference(Actor*);
    unsigned int PackageLocation_GetRadius();
    TESObjectREFR* GetLocationReference();   // 0x0067f390
    TESObjectCELL* FUN_0067f3e0(); // 0x0067f3e0
    int PackageLocation_GetLocType();                      // 0x00678ca0
};

class TargetDoorController
{
  public:
    ~TargetDoorController();
    static void operator delete(void*);
};
class DecalDataDeleter
{
  public:
    void* DeleteThis(int);
};
class MuzzleFlash
{
  public:
    ~MuzzleFlash();
    static void operator delete(void*);
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting185;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting347;
extern const float runtimeFloatSettingDefault13;
struct PlayerDetectionCounter
{
    unsigned int frame;
    unsigned char flags[4];
};
extern PlayerDetectionCounter DAT_011a3780[];
float FloatFloor(float);


#include "../../../include/ActorCombatGroup.h"
class ActorGroupState
{
  public:
    ActorGroupState();
    Actor* actor;
    ActorCombatGroup* group;
    bool flag8, flag9, flaga, flagb;
    bool ignoreDefensivePackage, spectator;
    unsigned char padding[2];
    int priority;
};


extern TESWorldSpace* BGSSaveLoadGlobalDataWorldspacePtr;
class NiTexture;





class Biped;





#include "../../../include/Interface.h"
bool BSShaderManager_IsRefractionEnabled();
void AttachControllerManager(NiAVObject*, NiAVObjectPalette*);
void SetObjectFormID(NiAVObject*, unsigned int);
extern bool DAT_011c5cb4;


#endif
