// fallout/interface/menus/mapmenu_decls.h: declares NiPoint3, NiPoint2, SettingT_GameSettingCollection_, TimeGlobal, InputManager and more
#ifndef MAPMENU_DECLS_H
#define MAPMENU_DECLS_H

#include <stddef.h>
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);
class NiNode;
class Tile;
class TileMenu;
class Menu;
class TESObjectREFR;
class TESWorldSpace;
class TESObjectCELL;
class TESForm;
class TESQuest;
class RegionObjectEntry;
class BGSNote;
class TESTopic;
class TESTopicInfo;
class DialogueItem;
class DialogueResponse;
class PathingPath;
class Character;
class BSAudio;
class FOPipboyManager;
class InterfaceManager;
class BSRenderedMenu;
class TESBoundObject;
class BGSQuestObjective;
class TESChallenge;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    ~BSSimpleList();
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    void RemoveAll();
    void AddTail(const T&);
};
template <class T, unsigned int N = 1024> class BSSimpleArray
{
  public:
    BSSimpleArray();
    ~BSSimpleArray();
    T* data;
    unsigned int size, capacity, grow;
    void Clear(bool);
    void Add(const T&);
};
template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short len, capacity;
    BSStringT();
    ~BSStringT();
    int __cdecl PrintfString(const char*, ...);
    operator const T*() const;
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 operator*(float) const;
    static const NiPoint3 ZERO;
};
class NiPoint2
{
  public:
    NiPoint2();
    float x, y;
};
#include "../../../../include/BSSoundHandle.h"
union SETTING_VALUE;
class SettingT_GameSettingCollection_
{
  public:
    char pad[12];
    const char* String();
    SETTING_VALUE* Float();
};
class INISettingCollection;
union SETTING_VALUE
{
    bool b;
    float f;
    const char* s;
};
template <class T> class SettingT
{
  public:
    char pad[12];
    SETTING_VALUE* Bool();
};
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
class InputManager
{
  public:
    int Controls_GetMouseButton(int, int);
    int Controls_GetUserAction(int, int);
};
class OSGlobals
{
  public:
    InputManager* Main_GetControls();
};
class Interface
{
  public:
    enum enumMenus
    {
        Map = 0x3ff
    };
    static bool GetSelectedTargetIndex(enumMenus);
    static FOPipboyManager* GetPipboyManagerInstance();
    FOPipboyManager* GetPipboyManager();
    static void PlayUISound(int);
    static void __cdecl SetTileFormattedText(Tile*, int, const char*, ...);
    static bool __cdecl ShowButtonDialog(const char*, const char*, const char*, void (*)(), int, int, float, float,
                                         ...);
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
};
class FORenderedMenu
{
  public:
    void StartBurst(float, float, float);
};
class FOPipboyManager : public FORenderedMenu
{
  public:
    bool IsUnk28Set();
    bool GetByteAtOffsetB9();
    FORenderedMenu* FUN_00704370();
};
class TileListBoxCalls
{
  public:
    virtual Tile* Destroy(bool);
    virtual void Init(Tile*, const char*, Tile*);
    float GetFloat(int);
};
class Tile : public TileListBoxCalls
{
  public:
    virtual Tile* Destroy(bool);
    virtual void Init(Tile*, const char*, Tile*);
    void* fields[13];
    class Value
    {
      public:
        void SetBooleanValue(bool);
    };
    void Set(int, float, bool);
    void Set(int, const char*, bool);
    void Set(int, int);
    bool ContainsTrait(int);
    const char* GetString(int);
    float GetScreenX();
    float GetScreenY();
    Tile* GetParent();
    Value* GetValue(int);
    Tile* GetNamedChild(const char*);
    Tile* GetChildById(int);
    void ResetImage();
    void UpdateTrait(int);
    void SetFlag8000(bool);
    void SetImageFlags(int);
    static int GetTraitID(const char*);
    static float GetInterfaceScale();
    static Menu* FindMenuById(int);
    Tile* ReadFile(const char*);
    Menu* GetMenu();
    NiNode* GetModel_0056c7f0();
};
int GetTileValueID(const char*, int);
int Warning(const char*, ...);
class NiTexture;
class NiProperty;
class TileShaderProperty
{
  public:
    NiTexture* BGSCameraShot_GetLocationNode();
    void SetTextureImage(NiTexture*);
    void FUN_007700d0(bool);
};
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
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
    NiProperty* GetProperty(unsigned int);
};
unsigned int NiShadeProperty_GetType();
class NiNode : public NiAVObject
{
  public:
    NiAVObject* NiNode_GetAtChecked(unsigned int);
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
    virtual void RemoveObject(NiAVObject*);
    unsigned int FUN_0043b480();
    NiAVObject* GetAt(unsigned int);
};
class MapMarkerData
{
  public:
    const char* GetMapLabel();
    bool IsTravelLocation();
};
enum ENUM_FORM_ID
{
    kWorldSpace = 0x41
};
class TESForm
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual ~TESForm();
    char data[12];
    unsigned int GetFormID();
    ENUM_FORM_ID GetFormType() const;
    void NotifySaveLoadGameOfFormChange();
};
class TESObjectREFR : public TESForm
{
  public:
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
    virtual NiPoint3* GetPos();
    char refrData[0x60];
    TESObjectCELL* GetParentCell();
    TESWorldSpace* GetParentWorldSpace();
    MapMarkerData* GetMapMarkerData();
    void ClearReferenceState(TESBoundObject*);
};
class Character : public TESObjectREFR
{
  public:
    char characterData[0x158];
    Character(bool);
};
class PlayerCharacter : public TESObjectREFR
{
  public:
    bool IsFastTravelAllowed();
    TESObjectREFR* QPlayerMapMarker();
    void SetActiveQuest(TESQuest*);
    void SetDateTimeText(BSStringT<char>&);
};
class TESQuest
{
  public:
    bool GetCompleted();
};
class TESWorldSpace : public TESForm
{
  public:
    void GetCellAtPosition(NiPoint3&, bool);
};
class TESObjectCELL : public TESForm
{
  public:
    void AdjustCoordForNorthRotation(NiPoint3&, NiPoint3&, bool);
};
class RegionObjectEntry
{
  public:
    PathingPath* GetTeleportPath();
    TESObjectREFR* GetReference(bool);
};
class BGSNote
{
  public:
    int GetNoteType();
    TESForm* GetNoteSound();
    TESTopic* GetNoteTopic();
    TESBoundObject* GetNoteSpeaker();
    bool GetUnk7d();
    void SetSoundNotePlayed(bool);
};
class TESTopicInfo
{
  public:
    void RunResultScript(int, Character*);
};
class DialogueResponse
{
  public:
    BSStringT<char>* GetVoiceFilePath();
    BSStringT<char>& GetDialogueText();
};
class DialogueItem
{
  public:
    bool SelectDefaultResponseList();
    bool NextResponse();
    DialogueResponse* GetActiveResponse();
    TESTopicInfo* GetInfo();
};
class Conversation
{
  public:
    char data[12];
    ~Conversation();
    Conversation(Character*, PlayerCharacter*, TESTopic*);
    bool FirstItem();
    DialogueItem* GetCurrentItem();
    void* Destroy(bool);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandle GetSoundHandleByFormID(unsigned int, unsigned int);
    BSSoundHandle GetSoundHandleByFilePath(const char*, unsigned int, void*);
    BSSoundHandle GetSoundHandleByEditorID(const char*, unsigned int);
    static void EnableAudio();
    // Instance audio entry at 0x00ad85a0 is distinct from the static dialogue flag helper.
    void EnterDialogue();
    float GetMusicVolume();
};
class FalloutRadio
{
  public:
    static bool SetRadioEnabled(bool);
    static bool SetRadioReferenceEnabled(TESObjectREFR*, bool);
};
template <class T> class ListBox
{
  public:
    ListBox();
    ~ListBox();
    virtual void vfn_00();
    virtual Tile* GetSelectedTile();
    char fields[44];
    T GetSelectedData();
    T GetSelectedData(Tile*);
    Tile* GetTileForData(T&);
    void Traverse(void (*)(Tile*, T), int, int);
    void Filter(bool (*)(T));
    void Initialize(Tile*, const char*);
    void SetSelectedTile(Tile*, bool);
    void ClearSelection(bool);
    void BSSimpleArray_BSStringT_char_1024_BSSimpleArray();
    void FUN_007a1c90();
    void FUN_007a27f0();
    void FUN_007a36e0();
    void FUN_007a43a0();
    void FUN_007a50f0();
};
template <> void ListBox<TESQuest*>::ClearSelection(bool);
class Menu
{
  public:
    virtual ~Menu();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void HandleSelection(int, Tile*);
    virtual void vfn_10();
    virtual void HandleMouseDown(int, Tile*);
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual unsigned int GetID();
    TileMenu* pMenu;
    char menuFields[32];
    Menu();
    static bool ReadMenuDefinition(const char*, Menu*);
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
    Tile* FUN_00726070();
};
class MapMenu : public Menu
{
  public:
    virtual void* Destroy(bool);
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void HandleSelection(int, Tile*);
    virtual void vfn_10();
    virtual void HandleMouseDown(int, Tile*);
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual unsigned int GetID();
    int GetClass();
    Tile* m_pTiles[22];
    int m_iMapDisplayMode;
    Tile* m_pMapTile;
    float m_fMapRotation;
    bool m_bMapMenuActive;
    char pad8d[3];
    BGSNote* m_pSelectedNote;
    unsigned int m_uiMapState;
    BSSimpleList<BSSoundHandle> m_kSoundList;
    BSSimpleArray<BSStringT<char> > SubtitlesToShow;
    BSSimpleList<BSSoundHandle>* m_pkActiveSoundList;
    bool m_bMapListUpdatePending;
    char padbd[3];
    float m_fMapZoom;
    int m_iMapSelectionIndex;
    float m_fSavedMusicVolume;
    TESQuest* m_pSelectedQuest;
    RegionObjectEntry* m_pSelectedMapMarkerInfo;
    Tile* m_pSelectedMarkerTile;
    BSSimpleList<TESObjectREFR*> m_kMapMarkerList, LocalMapMarkerList;
    NiPoint2 m_kMapMinimumPoint, m_kMapMaximumPoint;
    TESForm* m_pCurrentMapSpace;
    NiPoint3 m_kPlayerWorldPosition;
    TESForm* m_pCurrentMapForm;
    TESWorldSpace* m_pCurrentWorldspace;
    bool m_bLocalMapMode;
    char pad111[3];
    TESObjectREFR* m_pFirstMapReference;
    TESObjectREFR* m_pSecondMapReference;
    TESObjectCELL* pAdjustNorthRotationCell;
    NiPoint2 m_kMapOffset;
    unsigned int m_uiMapMarkerCount;
    bool m_bNeedsMapUpdate;
    char pad12d[3];
    ListBox<TESQuest*> m_kQuestListBox;
    ListBox<BGSNote*> m_kNoteListBox;
    ListBox<TESObjectREFR*> m_kMapMarkerListBox;
    ListBox<BGSQuestObjective*> m_kObjectiveListBox;
    ListBox<TESChallenge*> m_kChallengeListBox;
    BSSimpleArray<Tile*> m_kMapMarkerTiles;
    MapMenu();
    static Tile* Create();
    static void MenuDepthController();
    void UpdateDialog();
    static void StopMapMenuSounds();
    static void SetMapPositionToPlayer();
    static void UpdateMapPosition();
    static void OpenMap();
    void UpdateSelectedQuestMarkers();
    void SelectNote(BGSNote*);
    void RefreshMapData();
    void SetMapDisplayMode(bool);
    void ResetWaveform();
    static void MapMenu_SetKnobPosition(bool);
    NiPoint3 WorldToMapPosition(NiPoint3, TESWorldSpace*);
    NiPoint3 MapToWorldPosition(NiPoint3, TESWorldSpace*);
    TESObjectREFR* GetTeleportDestination(TESObjectREFR*, PathingPath*);
    TESWorldSpace* CalculatePlayerMarkerSpace(NiPoint3);
    void RefreshMapMarkers();
    void UpdateMapObjectives();
    void UpdateMapHighlight();
    void SetFlag8000();
    bool HasNoZeroEntries();
    void Menu_SetRenderedMenu();
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
};
extern const double DAT_01074f68, DAT_010301a8;
void MapMenu_RenderLocalMapGrid(bool);
class Calendar
{
  public:
    float GetGameTime();
    BSStringT<char> GetCurrentMonthName();
};
struct SystemLocaleState
{
    char fields[12];
    const char* String();
};
extern SystemLocaleState gSystemLocaleState;
extern Calendar g_calendar;
int BSstrcmp(const char*, const char*);
extern SettingT_GameSettingCollection_ DAT_011d1da8, DAT_011d3f64, DAT_011d45f4, DAT_011d3414, DAT_011d2f10,
    DAT_011d3180, DAT_011d4cfc, DAT_011d27a8, DAT_011d3798, DAT_011d3210, DAT_011d21e4;
extern int DAT_011da354, DAT_011da358, DAT_011da350, DAT_011da34c, DAT_011da35c;
extern MapMenu* DAT_011da368;
extern PlayerCharacter* g_thePlayer;
extern TimeGlobal g_timeGlobal;
extern OSGlobals* g_osGlobals;
extern bool DAT_011da36c, DAT_011da36d, DAT_011da36f, DAT_011da408;
extern signed char DAT_011da36e;
extern unsigned int DAT_011da40c;
extern int DAT_011da344, DAT_011da348, DAT_011da360;
extern SettingT<INISettingCollection> DAT_011da3b8;
extern SettingT_GameSettingCollection_ DAT_011d47bc, DAT_011d4438, DAT_011d4960, DAT_011d33a8, DAT_011d4f54,
    DAT_011d3a2c, DAT_011d34f8, DAT_011d3684, DAT_011d4a38, DAT_011d48e8, DAT_011db458, DAT_011db37c;
extern SettingT_GameSettingCollection_* DAT_011a03e4[3];
extern SettingT_GameSettingCollection_ DAT_011d38ac, DAT_011d204c, DAT_011d5020, DAT_011d28a4, DAT_011d4aec;
int MapMenu_GetClassStatic();
InterfaceManager* InterfaceManager_GetSingleton();
bool InterfaceManager_Has360Controller();
bool FalloutRadio_IsPipboyRadioEnabled();
bool Interface_Has360Controller();
class InterfaceManager
{
  public:
    class TutorialState
    {
      public:
        bool ShowMessage(int, int, unsigned int);
    };
    char fields[0x4d4];
    TutorialState tutorials;
    Tile* GetParent();
    float InterfaceManager_GetPipboyMouseX();
    float GetScaledValue();
    Tile* CombatController_GetCombatState();
};
void MapMenu_SetPlayerMarkerCallback();
void OnPCFastTravel();
void SetMapMenuTraitUnselected(Tile*, TESObjectREFR*);
bool MapMenu_ShouldHideNote(BGSNote*);
bool MapMenu_ChallengeFilterFunc(TESChallenge*);
extern "C" int sprintf_s(char*, size_t, const char*, ...);
extern "C" int _stricmp(const char*, const char*);
template <class T> class NiPointer
{
  public:
    T* ptr;
    NiPointer& operator=(T*);
};
class TileImage : public Tile
{
  public:
    unsigned int imageFlags;
    NiPointer<NiAVObject> texture;
    void SetTexture(NiAVObject*);
};
#endif
