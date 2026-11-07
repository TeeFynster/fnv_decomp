#include "../../../../include/BSSimpleList.h"
#include "../../../../include/SettingT.h"
#ifndef FNV_DIALOGMENU_RUNTIME_H
#define FNV_DIALOGMENU_RUNTIME_H

#include "dialogmenu_decls.h"
class MediaSet;

void* operator new(unsigned int) throw();
void operator delete(void*) throw();
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
int ConcatDialogText(char*, unsigned int, const char*);
int Warning(const char*, ...);
// LocalDialogueItem: unit-local DialogueItem declaring only the calls this unit makes
class LocalDialogueItem
{
  public:
    TESTopicInfo* GetInfo();
    TESQuest* GetQuest();
    TESTopic* GetAudioBackendData();
    TESObjectREFR* SelectDefaultResponseList();
};
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
extern SettingT<GameSettingCollection> DAT_011d27fc, DAT_011d3fe8;
extern SettingT<GameSettingCollection> DAT_011d0a24;
extern int DAT_011d9504;

class BGSImpactDataSet;

int ComputeWeightedValue(float, float, int);

struct DialogMenuConditionFunction
{
    unsigned short function;
    unsigned short padding;
    ActorValue::Index actorValue;
};

class MenuTopic
{
  public:
    BSStringT<char> m_kPrompt;
    bool m_bFirstFlag, m_bIsRefusal, m_bThirdFlag;
    BSSimpleList<DialogueResponse*> m_kResponseList;
    TESQuest* pQuest;
    TESTopicInfo* pInfo;
    TESTopic* m_pOriginalTopic;
    BSSimpleList<DialogueResponse*>* m_pCurrentResponseList;
    bool m_bIsRemappedRumor, m_bInfoHasBeenRead;
    TESTopic* pTopic;
    MenuTopic(TESQuest*, TESTopic*, TESTopicInfo*, MobileObjectView*, bool);
    ~MenuTopic();
    DialogueResponse* GetActiveResponse();
    // 0x0083E170 is MenuTopic::GetActiveResponse; this caller passes an unused argument.
    DialogueResponse* GetActiveResponse(int);
    bool NextResponse();
    void FillResponseList();
};
class TopicMenuController
{
  public:
    MenuTopic* GetSelectedTopic();
    MenuTopic* GetFirstTopic();
    bool SelectTopic(bool);
    bool AdvanceTopic();
    bool DialogMenu_SetClickedMenuItem(int);
    bool ShouldSkipTopic(MenuTopic*);
    bool Initialize(MobileObjectView*, TESTopic*);
    bool ActiveEffect_IsActive();
    void AddHeadIfNotNull(BSSimpleList<MenuTopic*>*);
    void RunTopicResultScript();
    void UpdateTopicList();
    static void IncrementMiscStat(int);
};
class Date;
class PlayerQuestData
{
  public:
    Date* GetLogDate();
};

extern PlayerCharacterView* g_thePlayer;
extern TESTopicInfo* DAT_011d9518;

TESTopicInfo* FindFollowupTopicInfo(TESTopicInfo*, bool*, void*, PlayerCharacterView*, bool, bool);
FNV_STATIC_ASSERT(sizeof(MenuTopic) == 0x2C);

InterfaceManager* InterfaceManager_GetSingleton();
int DialogMenu_GetClassStatic();
bool Cmd_Default_Execute();

class INISettingCollection;
extern SettingT<INISettingCollection> DAT_011d8934;
extern SettingT<GameSettingCollection> DAT_011d46fc;
extern float DAT_011a008c;
extern LocalDialogMenu* DAT_011d9510;
extern int DAT_011d9508;

FNV_STATIC_ASSERT(offsetof(InterfaceManager, kTutorialManager) == 0x4D4);

extern SettingT<GameSettingCollection> DAT_011d3ee0, DAT_011d243c, DAT_011d318c;
extern float DAT_011d951c;
extern unsigned int DAT_011d9594;
extern bool DAT_011f21d0, DAT_011f21d1;
float BSMIN(float, float);
class DialogMenuAudioCalls
{
  public:
    void EnableAudio();
    void DeactivateAudio();
};
extern bool DAT_011d9514;
extern SettingT<GameSettingCollection> DAT_011cd450;
#endif
