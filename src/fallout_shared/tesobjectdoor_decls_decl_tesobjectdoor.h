// fallout_shared/tesobjectdoor_decls_decl_tesobjectdoor.h: declares NiPoint3, TESForm, TESBoundObject, TESFullName, TESBoundAnimObject and more
#ifndef TESOBJECTDOOR_DECLS_H
#define TESOBJECTDOOR_DECLS_H

class NiFixedString;
extern NiFixedString* DAT_011c61dc;
class TESFile;
class Script;
class TESGlobal;
class DoorAccessData;
enum ENUM_FORM_ID
{
    FORM_DOOR = 28
};
enum CHUNK_ID
{
    CHUNK_NONE = 0
};
class TESObjectREFR;
class TESBoundObject;
class Actor;
class PlayerCharacter;
class TESObjectCELL;
class TESWorldSpace;
class NiNode;
class Animation;
class BaseProcess;
class TESSound;
struct NiPoint3
{
    float x, y, z;
};
class TESForm
{
  public:
    virtual ~TESForm();
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
    virtual void readOBNDSubRecord(TESFile*);
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
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
    virtual const char* GetEditorID();
    virtual bool SetEditorID(const char*);
    unsigned char type;
    unsigned int flags, iFormID;
    void* files[2];
    bool GetInitialized() const;
    void SetInitializationState(bool);
    void SetFormType(ENUM_FORM_ID);
    unsigned int GetFormID();
    void LoadRecordHeader(TESFile*);
    TESFile* GetFile(int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    static TESForm* GetFormByID(unsigned int);
};
class TESBoundObject : public TESForm
{
  public:
    char bounds[24];
};
class TESFullName
{
  public:
    TESFullName();
    virtual ~TESFullName();
    char name[8];
    const char* GetFullName();
};
class TESBoundAnimObject : public TESBoundObject
{
  public:
    TESBoundAnimObject();
    ~TESBoundAnimObject();
};
class TESModel
{
  public:
    TESModel();
    virtual ~TESModel();
    char modelData[20];
    static void LoadModelData(TESModel*, TESFile*);
};
class TESModelTextureSwap : public TESModel
{
  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    char textureSwaps[8];
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
    void InitItem(TESForm*);
};
class TESScriptableForm
{
  public:
    TESScriptableForm();
    virtual void vfn_0();
    char scriptData[8];
    void SetScript(Script*);
    void InitItem(TESForm*);
};
class BGSDestructibleObjectForm
{
  public:
    BGSDestructibleObjectForm();
    virtual ~BGSDestructibleObjectForm();
    void* data;
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    void InitItem(TESForm*);
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    BSSimpleList();
    ~BSSimpleList();
    bool IsEmpty();
    T& GetItem();
    BSSimpleList* GetNext();
    void AddHead(const T&);
    void Remove(const T&);
    void RemoveHead();
    void SetItem(const T&);
};
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
    bool NextChunk();
};
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};
class LockExtraData
{
  public:
    unsigned int level;
    TESBoundObject* key;
    bool IsLocked();
    int GetLockLevel(TESObjectREFR*);
    bool MeetsMinimumLockLevel();
};
class ExtraLock
{
  public:
    char prefix[12];
    LockExtraData* data;
    void FUN_00517360();
};
class TeleportableReference
{
  public:
    TESObjectCELL* DoorTeleportData_GetTeleportCell();
    TESWorldSpace* GetTeleportWorldspace();
    NiPoint3* GetPosition();
    NiPoint3* GetRotation();
};
class Animation
{
  public:
    void SpecialIdleFree(bool, bool);
};
class TESObjectREFR : public TESForm
{
  public:
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
    virtual NiNode* GetNiNode_v();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual Animation* GetAnimData();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* GetPos();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual int GetSitSleepState();
    virtual bool IsCharacter();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    bool FUN_00477ba0();
    TeleportableReference* Set3DObject();
    LockExtraData* GetLock();
    ExtraLock* FindExtraLock();
    bool Activate(TESObjectREFR*, bool, TESBoundObject*, int);
    void RefreshReference();
    void SetLocationOnReference(NiPoint3*);
    void SetReferenceAngle(float);
    void TESObjectREFR_SetAngleOnReferenceX(float);
    bool IsCellInterior();
    static void SetParentCellAndWorldspace(TESObjectREFR*, TESObjectCELL*, TESWorldSpace*);
};
class BaseProcess
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
    virtual void vfn_44(Actor*, int, int, bool, int, bool);
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
    virtual void readOBNDSubRecord(TESFile*);
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
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
    virtual void vfn_134(TESObjectREFR*);
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
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual void vfn_48c();
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual void vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4();
    virtual void vfn_4b8();
    virtual void vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual int vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual void vfn_504();
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual void vfn_514();
    virtual void vfn_518();
    virtual void vfn_51c();
    virtual void vfn_520();
    virtual void vfn_524();
    virtual void vfn_528();
    virtual void vfn_52c();
    virtual void vfn_530();
    virtual void vfn_534();
    virtual void vfn_538();
    virtual void vfn_53c();
    virtual void vfn_540();
    virtual void vfn_544();
    virtual void vfn_548();
    virtual void vfn_54c();
    virtual void vfn_550();
    virtual void vfn_554();
    virtual void vfn_558();
    virtual void vfn_55c();
    virtual void vfn_560();
    virtual void vfn_564();
    virtual void vfn_568();
    virtual void vfn_56c();
    virtual void vfn_570();
    virtual void vfn_574();
    virtual void vfn_578();
    virtual void vfn_57c();
    virtual void vfn_580();
    virtual void vfn_584();
    virtual void vfn_588();
    virtual void vfn_58c();
    virtual void vfn_590();
    virtual void vfn_594();
    virtual void vfn_598();
    virtual void vfn_59c();
    virtual void vfn_5a0();
    virtual void vfn_5a4();
    virtual void vfn_5a8();
    virtual void vfn_5ac();
    virtual void vfn_5b0();
    virtual void vfn_5b4();
    virtual void vfn_5b8();
    virtual void vfn_5bc();
    virtual void vfn_5c0();
    virtual void vfn_5c4();
    virtual void vfn_5c8();
    virtual void vfn_5cc();
    virtual void vfn_5d0();
    virtual void vfn_5d4();
    virtual void vfn_5d8();
    virtual void vfn_5dc();
    virtual void vfn_5e0();
    virtual void vfn_5e4();
    virtual void vfn_5e8();
    virtual void vfn_5ec();
    virtual void vfn_5f0();
    virtual void vfn_5f4();
    virtual void vfn_5f8();
    virtual void vfn_5fc();
    virtual void vfn_600();
    virtual void vfn_604();
    virtual void vfn_608();
    virtual void vfn_60c();
    virtual int vfn_610();
    int GetProcessLevel();
    void SetPlaybackTime(Actor*, TESObjectREFR*, bool);
};
class Actor : public TESObjectREFR
{
  public:
    BaseProcess* GetProcess();
    bool HasObjects(TESBoundObject*, int, int, unsigned int, int&);
    void Actor_SetForceUpdateQuest(int);
};
class PlayerCharacter : public Actor
{
  public:
    char unknownTo200[0x200 - 0x18];
    unsigned int activationState;
    char unknown204[8];
    bool movingThroughDoor;
    char unknown20d[0x604 - 0x20d];
    TESObjectREFR* lastExteriorDoor;
    bool IsSleepingOrResting();
    void ProcessAllActions();
};
class TES
{
  public:
    bool IsCellBuffered(TESObjectCELL*, bool);
};
class Setting
{
  public:
    const char* GetString();
};
#include "../../include/BSSoundHandle.h"
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandle GetSoundHandleByFormID(unsigned int, unsigned int);
    BSSoundHandle GetSoundHandleByEditorID(const char*, unsigned int);
    bool TESRegionData_GetPriority();
    void Update(bool);
};
class TESSound : public TESForm
{
  public:
    unsigned int GetFormID();
};
class BGSOpenCloseForm
{
  public:
    BGSOpenCloseForm();
    virtual void vfn_0();
    virtual void vfn_4();
    virtual bool vfn_8();
    static void HandleOpenCloseActivation(TESObjectREFR*, TESObjectREFR*, BGSOpenCloseForm*);
};
class TESObjectDOOR : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm
{
  public:
    ~TESObjectDOOR();  // declared for the original code (decl_variants.py)

  public:
    char magicForms[4];
    TESSound* m_pOpenSound;
    TESSound* m_pSecondarySound;
    TESSound* m_pLoopingSound;
    unsigned char cFlags;
    BSSimpleList<TESForm*> m_kRandomTeleportTargets;
    TESObjectDOOR();
    static NiFixedString* GetOpenSequenceName();
    void ResetFormData();
    void ClearData();
    void InitItem();
    bool Load(TESFile*);
    bool IsTeleportDoor();
    bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    bool IsRandomDoor();
    TESObjectREFR* FindRandomTeleportTarget(TESObjectREFR*, TESObjectREFR*);
    void QueueDoorTeleport(TESObjectREFR*);
    TESSound* GetOpenSound();
    void ClearRandomTeleportList();
    BSSimpleList<TESForm*>* TESDataHandler_GetFactions();
    static bool ProcessDoorActivation(TESObjectREFR*, Actor*, bool, bool);
    static bool ProcessDoorActivation(DoorAccessData*, Actor*, TESObjectREFR*, bool, bool);
};
class DoorAccessData
{
  public:
    TESObjectCELL* m_pSourceCell;
    TESObjectCELL* m_pDestinationCell;
    LockExtraData* m_pTeleportData;
    TESForm* m_pKeyForm;
    int m_iLockLevel;
    TESGlobal* m_pLockLevelGlobal;
    DoorAccessData(TESObjectREFR*);
    ~DoorAccessData();
};
class Interface
{
  public:
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
    static void PlayUISound(int);
};
extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;
extern TESBoundObject* g_pLockpickItem;
extern TESObjectREFR* DAT_011c9350;
extern Setting DAT_011c9384, DAT_011d276c, DAT_011d5110;
extern const float DAT_010162c0;
void TESObjectDOOR_LinkRandomTeleportDoors(TESObjectREFR*, TESObjectREFR*);
void TESIdleManager_SetUsedItem(TESBoundObject*);
void TESIdleManager_SetUsedItemLevel(int);
void TESIdleManager_SetUsedItemActivate(bool);
void Interface_CreateLockPickMenu(TESObjectREFR*, int, int);
void ApplyPerkModifiers(int, Actor*, float*);
int Warning(const char*, ...);
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
#endif
