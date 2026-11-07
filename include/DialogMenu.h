#pragma once

#include "Menu.h"
#include "ListBox_int_.h"
#include "BSSoundHandle.h"
#include "DialogMenuPoint2.h"

class Tile;
class MenuTopic;
class TopicMenuController;
class MobileObject;
class TESTopic;
class TESSound;
class ImageSpaceModifierInstanceDOF;

class DialogMenu : public Menu
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

    DialogMenu();
    void* ScalarDeletingDestructor(unsigned int);
    virtual ~DialogMenu();
    virtual void AssignTileByID(int id, Tile* tile);
    virtual void HandleSelection(int, Tile*);
    virtual void UpdateDialog();
    virtual int GetClass();
    virtual bool HandleMenuInput(int button, float value);

    DialogState m_eDialogState;
    GoodbyeState m_eGoodbyeState;
    Tile* m_pTiles[4];
    ListBox_int_ m_kResponseListBox;
    TopicMenuController* pDialogueItem;
    BSSoundHandle m_kActorProcessResult;
    MobileObject* m_pDialogueSpeaker;
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
    static Tile* Create(MobileObject*, TESTopic*, MobileObject*);
    static void* Create(void*, void*, void*);
};
