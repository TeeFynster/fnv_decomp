#pragma once

#include "Menu.h"
#include "ListBox_int_.h"

class Tile;
class TESObjectREFR;
class BooleanFloatQuery;
struct ActorX;
struct ActorM;
struct ChanceX;
struct TargetX;
struct LimbM;
struct LimbListM;
struct TargetListM;


class VATSMenu : public Menu
{
public:
    class ActionList : public ListBox_int_
    {
    public:
        ActionList();
        ~ActionList();
    };

    class TargetCommand
    {
    public:
        int eAction;
        bool bSuccess;
        bool m_kFieldAfterWeaponFlags;
        bool m_bFirstActionFlag;
        bool m_bSecondActionFlag;
        unsigned char m_ucFirstActionCode;
        unsigned char m_ucSecondActionCode;
        char unk0A[2];
        TESObjectREFR* pTarget;
        int m_iActionValue;
        BooleanFloatQuery* m_pActionObject;
        float m_fArmorDamage;
        float m_fHealthDamage;
        float m_fOverrideActionPoints;
        bool m_bFinalActionFlag;
        char unk25[3];

        TargetCommand();
        ~TargetCommand();
        void VATS_COMMAND_Initialize();
    };

    virtual ~VATSMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);

    union
    {
        char layoutExtension_pad28[128];
        Tile* m_pTiles[32];
    };
    void* m_pAdditionalHudTile;
    bool m_bStateFlag8;
    char layoutExtension_padad[3];
    ActionList m_acMenuText;
    float m_fOverrideActionPoints;
    float m_fValue1;
    float m_fValue2;
    float m_fValue3;
    float m_fValue4;
    float m_fValue5;
    bool m_bFirstFlag;
    bool m_bStateFlag1;
    bool m_bStateFlag2;
    bool m_bStateFlag3;
    float m_fHitChance;
    void* m_pTargetChance;
    bool m_bStateFlag4;
    char layoutExtension_pad105[3];
    void* m_pSelectedChance;
    bool m_bStateFlag5;
    bool m_bStateFlag9;
    bool m_bAdditionalStateFlag;
    bool m_bStateFlag10;
    bool m_bStateFlag6;
    char layoutExtension_pad111[3];
    unsigned int m_uiTargetCount;
    bool m_bStateFlag7;
    char layoutExtension_pad119[3];
    TargetCommand m_acTargetText;

    VATSMenu();
    void AttachTileByID(int aiID, Tile* apTile);
    int GetSelectedTargetIndex();
    unsigned int Create();
    unsigned int GetFilteredCount();
    unsigned int GetUnfilteredCount();
    int ListBox_BGSQuestObjective_NumUnfiltered();
    int ListBox_enum_MiscStatManager_MiscStatID_NumUnfiltered();

    void HandleClick(int aiID, int aiArg);
    bool HandleKey(int aiKey);
    void DoEnter_007ef7b0(int aiID, int aiArg);
    void DoLeave_007ef830(int aiID, int aiOther);
    void DoWheelMove_007ef760(int aiID, Tile* apTarget);
    void DoStillDown_007ef8b0(int aiID, Tile* apTarget);

    BSSimpleList<TargetX*>* FindListEntryForTarget(ActorX* apTarget);
    TargetListM* FindListEntryForTarget(ActorM* apTarget);
    void AssignActionTiles(BSSimpleList<TargetX*>* apNode);
    BSSimpleList<ChanceX*>* FindEntryForRef();
    LimbListM* FindListEntryByValue(int aiLimb);
    void UpdateLimbHighlight();
    void UpdateQueueEntry(TargetCommand* apCmd, bool abArg2, bool abArg3);
    float CalculateProbableEnemyHealth();
    void UpdateHitChanceDisplay();
    bool UpdateVatsTargeting();
    void VATSMenu_SetTargetLimb();
    bool UpdateAmmo();
    bool VATSMenu_PickNewTarget();
    int VATSMenu_GetActorValueFromBodyPart(int aiLimb);
    int GetConsecutiveMatchCount();
    void UpdateLimbTiles();
    float CalculateVATSChance(LimbListM* apTarget);
    bool VATSMenu_LimbOnScreen(LimbM* apLimb);
    void Update();
};
