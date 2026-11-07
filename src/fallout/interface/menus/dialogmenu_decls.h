// Dialogue menu shared types and the local APIs not yet supported by the shared headers.
// Actor.h lacks CalculateDisposition(PlayerCharacter*, void*) at virtual slot 0x344.
// MobileObject.h lacks the two-argument virtual speech call at slot 0x264.
// PlayerCharacter.h includes Actor.h, so its adoption depends on those actor declarations.
// DialogMenu adoption is blocked by its include/ListBox_int_.h dependency:
// the approved header lacks this unit's constructor, destructor, SortAndSynchronize,
// SetSelectionMode, ClearItems, and virtual vfn_18/Clear slots. Keep the local
// DialogMenu and ListBox_int_ definitions until that dependency supports this unit.
#ifndef FNV_DIALOGMENU_DECLS_H
#define FNV_DIALOGMENU_DECLS_H

#include <stddef.h>
#include <windows.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#pragma pack(push, 4)
namespace ActorValue { enum Index { ActorValue__Index_SPEECH = 43 }; enum Section; }
#include "../../../../include/DIALOGUE_TYPE.h"
#include "../../../../include/SettingT.h"
#include "../../../../include/BSStringT.h"
#include "../../../../include/InterfaceManager.h"
#include "../../../../include/TESConditionItem.h"
#include "../../../../include/TESResponse.h"
#include "../../../../include/BSSimpleList.h"
#include "../../../../include/BSSimpleArray.h"
#include "TESTopic.h"

#include "../../../../include/ActorValueInfo.h"
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/BGSExplosion.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/HighProcess.h"
#include "../../../../include/BGSPerk.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/BSFaceGenNiNode.h"

#include "../../../../include/DialogMenuPoint2.h"
#include "../../../../include/ExtraDataList.h"

#include "../../../../include/ImageSpaceModifierInstanceDOF.h"
#include "../../../../include/ImageSpaceModifierInstanceForm.h"
#include "../../../../include/ListBoxBase.h"

#include "../../../../include/Menu.h"

#include "../../../../include/NiPoint3.h"
#include "../../../../include/PerkEntryConditionSet.h"

#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/TESImageSpaceModifier.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESPackage.h"
#include "../../../../include/TESSoundFile.h"
#include "../../../../include/TESTopicInfo.h"
#include "../../../../include/TESTopicInfoData.h"
#include "../../../../include/Tile.h"
// TileListBoxCalls_dialogmenu_decls: local type (was include/TileListBoxCalls.h, which had no evidence of one real class); its methods are 0x00a011b0 Tile::GetFloat
#include "../../../../include/Tile.h"

class TileListBoxCalls_dialogmenu_decls : public Tile
{
  public:
    float GetFloat(int trait);
};
class PlayerCharacterView;
class DialogueResponse;
// MobileObjectView: unit-local slot view of MobileObject (the shared MobileObject.h lacks the two-argument speech virtual at slot 0x264)
class MobileObjectView
{
  public:
    bool MobileObject_IsTalkingActivator();
    TESPackage* GetCurrentPackage();
    const char* GetFullName();
    void MobileObject_StopCurrentDialogue();
    bool IsInThirdPerson();
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
    virtual void SetAltered(bool);
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool IsActor();
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
    virtual BSFaceGenNiNode* GetFaceGenNodeBiped(unsigned int);
    virtual BSFaceGenNiNode* GetFaceGenNodeSkinned(unsigned int);
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
    virtual NiPoint3* GetPos();
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
    virtual void vfn_264(float, DialogueResponse*, bool);
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual bool vfn_274(bool);
    virtual void vfn_278(bool);
    virtual void vfn_27c();
    virtual void vfn_280(PlayerCharacterView*, int, int, bool, bool, bool, bool, bool, bool);
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
    virtual PlayerCharacterView* vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual bool vfn_2e8();
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
    virtual int CalculateDisposition(PlayerCharacterView*, void*);
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
    virtual void RewardXP(unsigned int);
    unsigned char layoutPadding4[0x78];
    bool bDialogueSelected;
};
// ActorView: unit-local view of Actor (the shared Actor.h lacks CalculateDisposition(PlayerCharacter*, void*) at virtual slot 0x344)
class ActorView : public MobileObjectView
{
  public:
    void SetSpeakingState(bool);
    void StopMoving();
    bool ShouldShowSubtitles();
    static void SetActorDialogueState(unsigned int, bool);
};
// PlayerCharacterView: unit-local view of PlayerCharacter on the ActorView/MobileObjectView chain above
class PlayerCharacterView : public MobileObjectView
{
  public:
    unsigned char layoutPadding80[0x24];
    ActorValueOwner actorValueOwner;
    bool PlayerCharacter_Is3rdPerson();
    void Show1stPerson(bool);
    void FocusOnActor(MobileObjectView*, float, bool);
    void SetAimingWeapon(bool, bool, bool);
    void UpdatePlayerInventory();
    void UpdateCamera(bool, const bool);
    void UpdatePlayerState();
    bool HasCombatState();
};
class ListBoxItem_int_;
class DialogListBoxItems
{
public:
    ListBoxItem_int_* m_item;
    DialogListBoxItems* m_pkNext;
    DialogListBoxItems();
    ~DialogListBoxItems();
};
// DialogListBox: unit-local ListBox<int>; the shared ListBox_int_.h lacks this unit's ctor, dtor, SortAndSynchronize, SetSelectionMode, ClearItems and the vfn_18/Clear slots
class DialogListBox : public ListBoxBase, public DialogListBoxItems
{
public:
    // These two dialog-list virtuals follow the six shared ListBoxBase slots.
    virtual void vfn_18();
    virtual void Clear();
    DialogListBox();
    ~DialogListBox();
    void SortAndSynchronize(int (__cdecl*)(ListBoxItem_int_*, ListBoxItem_int_*));
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    unsigned short layoutPadding1E;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;
    unsigned short layoutPadding2E;

    Tile* AddItem(int, const char*, int (*)(ListBoxItem_int_*, ListBoxItem_int_*), const char*);
    void Synchronize();
    void Initialize(Tile*, const char*);
    bool ContainsKey(Tile*);
    void SetSelectionMode(int, int);
    void ClearItems();
};

class MenuTopic;
class TopicMenuController;
// LocalDialogMenu: unit-local DialogMenu (RTTI size 0x13c) built on DialogListBox; the shared DialogMenu.h needs ListBox_int_.h, which lacks those members
class LocalDialogMenu : public Menu
{
public:
    enum DialogState
    {
        eCameraZoomIn,
        eLoadSpeech,
        eSpeechIdle,
        ePlaySpeech,
        eCameraZoomOut,
        eServiceFadeOut
    };

    enum GoodbyeState
    {
        eInDialogue,
        eNaturalGoodbye,
        eForceGoodbye,
        eInvalidChoiceList
    };

    LocalDialogMenu();
    void* ScalarDeletingDestructor(unsigned int);
    virtual ~LocalDialogMenu();
    virtual void AssignTileByID(int id, Tile* tile);
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int button, float value);

    DialogState m_eDialogState;
    GoodbyeState m_eGoodbyeState;
    Tile* m_pTiles[4];
    DialogListBox m_kResponseListBox;
    TopicMenuController* pDialogueItem;
    BSSoundHandle m_kActorProcessResult;
    MobileObjectView* m_pDialogueSpeaker;
    char m_cCurrentTopicLabel[128];
    bool m_bResponseStarted;
    unsigned char layoutPadding105[3];
    float m_fCameraTransitionTime;
    unsigned int m_uiDialogMenuFlags;
    DialogMenuPoint2 m_kDialogMenuPoint1;
    DialogMenuPoint2 m_kDialogMenuPoint2;
    DialogMenuPoint2 m_kDialogMenuPoint3;
    float m_fCameraTransitionAlpha;
    ImageSpaceModifierInstanceDOF* m_pDialogueDepthOfFieldModifier;
    bool m_bPauseRequested;
    bool bPaused;
    unsigned char layoutPadding132[2];
    DialogState m_eStateBeforePause;
    bool m_bServiceDialogue;
    bool m_bSuppressDialogueText;
    bool m_bServiceMenuRequested;
    unsigned char layoutPadding13B[1];

    void SetActive(bool abActive);
    void RefreshTopics();
    void SetCurrentTopic(MenuTopic* topic);
    DialogState BeginDialogueResponse(bool);
    void LoadTopicsList();
    bool AreTilesInitialized();
    bool DialogMenu_IsWellFormedMenu();
    TESSound* GetCastSound();

    static int ms_iDialogMenuValue;
    static void Close();
    static Tile* Create(MobileObjectView*, TESTopic*, MobileObjectView*);
    static void* Create(void*, void*, void*);
};

class DialogMenuInterfaceCalls
{
  public:
    enum enumMenus
    {
        Dialog = 1009
    };
    static bool GetSelectedTargetIndex(enumMenus menu);
    static bool IsConsoleActive();
    static void SetHUDVisible(bool);
};

FNV_STATIC_ASSERT(sizeof(Menu) == 0x28);
FNV_STATIC_ASSERT(sizeof(DialogListBox) == 0x30);
FNV_STATIC_ASSERT(sizeof(LocalDialogMenu) == 0x13C);
FNV_STATIC_ASSERT(offsetof(LocalDialogMenu, m_eGoodbyeState) == 0x2C);
FNV_STATIC_ASSERT(offsetof(LocalDialogMenu, m_kResponseListBox) == 0x40);
#endif

