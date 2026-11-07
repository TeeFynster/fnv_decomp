
// hudmainmenu_ctx2_variant.cpp: context variant of src/fallout/interface/menus/hudmainmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "../../../../include/HUDMainMenu.h"
#include "../../../../include/Tile.h"
static const int kGetClassValue = 1004;
// m_pTiles is addressed by 1-based tile ID; slot 0 is the menu root.
enum
{
    kTileIDMax = 86
};

struct XPState
{
    bool Ready();
};
struct XPValues
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual float GetValue(int);
};
struct XPPlayer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    XPValues values;
    int PendingLevels();
    XPState* State();
    unsigned short Level();
    bool IsBusy();
};
struct XPVats
{
    unsigned int Flags();
};
struct XPGate
{
    bool Active();
};
struct AmountEntry
{
    int unk00;
    int unk04;
    int amount;
};
struct XPSetting
{
    const char* String();
    int* Int();
};
struct XPClock
{
    unsigned int Time();
};
struct XPSound
{
    int soundID;
    int state;
    int unk08;
    XPSound();
    ~XPSound();
    XPSound& operator=(const XPSound&);
    bool Play(bool);
};
struct XPAudio
{
    XPSound GetSoundByEditorID(const char*, unsigned int);
};
extern XPAudio* GetXPAudio();
extern XPPlayer* _g_thePlayer;
extern HUDMainMenu* HUDMainMenu_pme;
extern XPVats xpVats;
extern float xpAlpha;
extern unsigned int xpFlags;
extern int xpCurrentLevel, xpNextLevel;
extern XPSetting xpLabel, xpLevelLabel, xpMaxLevel;
extern XPClock xpClock;
extern int LookupXPTrait(const char*, int);
extern bool Interface_IsInMenuMode();
extern int Interface_GetTopMenuID();
extern int LevelXP(int);
extern float LinearInterpolate(float, float, float, float, float);
extern float XPClampLow(float, float);
extern float XPClampHigh(float, float);
extern int XPMax(int, int);
extern int XPMin(int, int);
extern int XPSprintf(char*, unsigned int, const char*, ...);
extern void InterfaceManager_PlayMenuSound(int);
struct XPMenu : HUDMainMenu
{
    void HUDMainMenu_UpdateXPMeter();
};

// @fnv 0x0077c4e0
// src: XBOX_PDB 0x0077c4e0
void XPMenu::HUDMainMenu_UpdateXPMeter()
{
    static int minTrait = LookupXPTrait("_x_min", -1);
    static int maxTrait = LookupXPTrait("_x_max", -1);
    bool hasPendingLevel18 = _g_thePlayer->PendingLevels() > 0;
    bool canLevelUp13 = _g_thePlayer->State()->Ready();
    if ((Interface_IsInMenuMode() && Interface_GetTopMenuID() != 1008 && Interface_GetTopMenuID() != 1055 && Interface_GetTopMenuID() != 1057 &&
         Interface_GetTopMenuID() != 1009) ||
        xpVats.Flags() == 4 || ((XPGate*)&m_kMenuData)->Active())
    {
        HUDMainMenu_pme->m_pTiles[44]->Set(4003, 0);
        HUDMainMenu_pme->m_pTiles[45]->Set(4003, 0);
        HUDMainMenu_pme->m_pTiles[46]->Set(4003, 0);
        HUDMainMenu_pme->m_pTiles[47]->Set(4003, 0);
        HUDMainMenu_pme->m_pTiles[48]->Set(4003, 0);
        HUDMainMenu_pme->m_pTiles[49]->Set(4003, 0);
        HUDMainMenu_pme->m_pTiles[44]->Set(4009, 0.0f, true);
        HUDMainMenu_pme->m_pTiles[44]->Stop(4009);
        xpFlags |= 1;
        m_bSequenceActive = false;
    }
    else if (xpAlpha == 0.0)
    {
        m_bSequenceActive = true;
    }
    else
    {
        float alpha = m_pTiles[44]->Read(4009);
        bool visible = alpha > 0.0;
        bool done = m_pTiles[44]->Done(4009);
        if (xpFlags & 1)
        {
            if (!visible && done && !((BSSimpleList<AmountEntry*>*)&m_kXPUpdates)->IsEmpty())
            {
                BSSimpleList<AmountEntry*>* node = (BSSimpleList<AmountEntry*>*)&m_kXPUpdates;
                int total = 0;
                while (node && !node->IsEmpty())
                {
                    total += node->GetItem()->amount;
                    node = node->GetNext();
                }
                while (((BSSimpleList<AmountEntry*>*)&m_kXPUpdates)->GetItem())
                {
                    AmountEntry* update = ((BSSimpleList<AmountEntry*>*)&m_kXPUpdates)->GetItem();
                    delete update;
                    ((BSSimpleList<AmountEntry*>*)&m_kXPUpdates)->RemoveHead();
                }
                if (total > 0 && !m_bSequenceActive)
                {
                    float position;
                    {
                        XPSound xpSound12;
                        xpSound12 = GetXPAudio()->GetSoundByEditorID("UIPopUpExperienceUp", 0x121);
                        xpSound12.Play(false);
                        position = 0.0f;
                        int levelStartXP28 = 0;
                        int levelEndXP11 = 0;
                        int currentXP15 = (int)_g_thePlayer->values.GetValue(24);
                        xpCurrentLevel = _g_thePlayer->Level();
                        xpNextLevel = xpCurrentLevel + 1;
                        levelStartXP28 = LevelXP(xpCurrentLevel);
                        levelEndXP11 = LevelXP(xpNextLevel);
                        if (currentXP15 > levelEndXP11 && hasPendingLevel18)
                            position = m_pTiles[47]->Read(maxTrait);
                        if (levelStartXP28 == levelEndXP11)
                            position = (float)levelStartXP28;
                        else
                            position = LinearInterpolate(m_pTiles[47]->Read(minTrait), m_pTiles[47]->Read(maxTrait),
                                                         (float)levelStartXP28, (float)levelEndXP11,
                                                         _g_thePlayer->values.GetValue(24) - total);
                        m_pTiles[47]->Set(4001,
                                          XPClampHigh(XPClampLow(position, m_pTiles[47]->Read(minTrait)),
                                                      m_pTiles[47]->Read(maxTrait)),
                                          true);
                        m_pTiles[44]->Set(4003, 1);
                        m_pTiles[45]->Set(4003, 1);
                        m_pTiles[46]->Set(4003, 1);
                        m_pTiles[46]->Set(4036, xpLabel.String(), true);
                        m_pTiles[47]->Set(4003, 1);
                        m_pTiles[48]->Set(4003, 1);
                        m_pTiles[49]->Set(4003, 1);
                        m_pTiles[44]->Set(4009, 0.0f, true);
                        m_pTiles[45]->Set(4009, 0.0f, true);
                        m_pTiles[46]->Set(4009, 0.0f, true);
                        m_pTiles[47]->Set(4009, 0.0f, true);
                        m_pTiles[48]->Set(4009, 0.0f, true);
                        m_pTiles[49]->Set(4009, 0.0f, true);
                        char text[16];
                        XPSprintf(text, 16, "+%i", total);
                        m_pTiles[45]->Set(4036, text, true);
                        XPSprintf(text, 16, "%i", xpCurrentLevel);
                        m_pTiles[48]->Set(4036, text, true);
                        XPSprintf(text, 16, "%i", xpNextLevel);
                        m_pTiles[49]->Set(4036, text, true);
                        m_pTiles[44]->Animate(4009, 0.0f, xpAlpha, 2.0f, 0);
                        m_pTiles[45]->Animate(4009, 0.0f, xpAlpha, 2.0f, 0);
                        m_pTiles[46]->Animate(4009, 0.0f, xpAlpha, 2.0f, 0);
                        m_pTiles[47]->Animate(4009, 0.0f, xpAlpha, 2.0f, 0);
                        m_pTiles[48]->Animate(4009, 0.0f, xpAlpha, 2.0f, 0);
                        m_pTiles[49]->Animate(4009, 0.0f, xpAlpha, 2.0f, 0);
                        visible = true;
                    }
                }
            }
            else
            {
                float animatedPosition1 = m_pTiles[47]->AnimValue(4001);
                float meterMin34 = m_pTiles[47]->Read(minTrait);
                float meterMax4 = m_pTiles[47]->Read(maxTrait);
                bool meterDone = m_pTiles[47]->Done(4001);
                if (!m_pTiles[47]->Flag(4111) && done && visible)
                {
                    int currentXP15 = (int)_g_thePlayer->values.GetValue(24);
                    if (xpCurrentLevel == xpNextLevel)
                        ++xpNextLevel;
                    int levelStartXP8 = LevelXP(xpCurrentLevel);
                    int levelEndXP11 = LevelXP(xpNextLevel);
                    m_pTiles[47]->Set(4111, 1);
                    if (currentXP15 > levelEndXP11)
                    {
                        if (meterMax4 < m_pTiles[47]->Read(4001))
                            m_pTiles[47]->Set(4001, meterMax4, true);
                        m_pTiles[47]->Animate(4001, m_pTiles[47]->Read(4001), meterMax4, 1.0f, 0);
                    }
                    else
                    {
                        m_pTiles[47]->Animate(
                            4001, m_pTiles[47]->Read(4001),
                            LinearInterpolate(meterMin34, meterMax4, (float)levelStartXP8, (float)levelEndXP11,
                                              (float)XPMin(XPMax(currentXP15, levelStartXP8), levelEndXP11)),
                            2.0f, 0);
                    }
                }
                else if (done && !visible)
                {
                    HUDMainMenu_pme->m_pTiles[44]->Set(4003, 0);
                    HUDMainMenu_pme->m_pTiles[45]->Set(4003, 0);
                    HUDMainMenu_pme->m_pTiles[46]->Set(4003, 0);
                    HUDMainMenu_pme->m_pTiles[47]->Set(4003, 0);
                    HUDMainMenu_pme->m_pTiles[48]->Set(4003, 0);
                    HUDMainMenu_pme->m_pTiles[49]->Set(4003, 0);
                    if ((xpFlags & 8) && !m_bSequenceActive)
                    {
                        m_bSequenceActive = true;
                        m_pTiles[50]->Set(4110, 0);
                    }
                }
                else if (!meterDone && done && visible)
                {
                    int currentXP15 = (int)_g_thePlayer->values.GetValue(24);
                    int levelStartXP8 = LevelXP(xpCurrentLevel);
                    int levelEndXP11 = LevelXP(xpNextLevel);
                    if (canLevelUp13 && meterMax4 == m_pTiles[47]->Read(4001) && !_g_thePlayer->IsBusy() &&
                        !hasPendingLevel18)
                        InterfaceManager_PlayMenuSound(21);
                    if (currentXP15 > levelEndXP11 && xpNextLevel < *xpMaxLevel.Int() && !hasPendingLevel18)
                    {
                        ++xpCurrentLevel;
                        ++xpNextLevel;
                        levelStartXP8 = levelEndXP11;
                        levelEndXP11 = LevelXP(xpNextLevel);
                        m_pTiles[47]->Set(4001, meterMin34, true);
                        char levelText[3];
                        XPSprintf(levelText, 3, "%i", xpCurrentLevel);
                        m_pTiles[48]->Set(4036, levelText, true);
                        XPSprintf(levelText, 3, "%i", xpNextLevel);
                        m_pTiles[49]->Set(4036, levelText, true);
                        if (currentXP15 > levelEndXP11)
                        {
                            if (meterMin34 > meterMax4)
                                meterMin34 = meterMax4;
                            m_pTiles[47]->Animate(4001, meterMin34, meterMax4, 1.0f, 0);
                        }
                        else
                        {
                            m_pTiles[47]->Animate(4001, meterMin34,
                                                  LinearInterpolate(meterMin34, meterMax4, (float)levelStartXP8,
                                                                    (float)levelEndXP11, (float)currentXP15),
                                                  2.0f, 0);
                        }
                    }
                }
                else if (m_pTiles[47]->Done(4001) && m_pTiles[47]->Flag(4111) && m_pTiles[44]->Done(4009) &&
                         m_pTiles[44]->Read(4009) > 0.0)
                {
                    m_pTiles[47]->Set(4111, 0);
                    m_pTiles[44]->Animate(4009, m_pTiles[44]->Read(4009), 0.0f, 2.0f, 0);
                    m_pTiles[45]->Animate(4009, m_pTiles[45]->Read(4009), 0.0f, 2.0f, 0);
                    m_pTiles[46]->Animate(4009, m_pTiles[46]->Read(4009), 0.0f, 2.0f, 0);
                    m_pTiles[47]->Animate(4009, m_pTiles[47]->Read(4009), 0.0f, 2.0f, 0);
                    m_pTiles[48]->Animate(4009, m_pTiles[48]->Read(4009), 0.0f, 2.0f, 0);
                    m_pTiles[49]->Animate(4009, m_pTiles[49]->Read(4009), 0.0f, 2.0f, 0);
                }
            }
            if (canLevelUp13)
            {
                if (!hasPendingLevel18 && !visible && !(xpFlags & 8))
                    xpFlags = 2;
                else
                    xpFlags |= 4;
            }
        }
        else if ((xpFlags & 2) && !(xpFlags & 8) && !visible && done && !_g_thePlayer->IsBusy())
        {
            bool noticeDone = m_pTiles[50]->Done(4009);
            bool noticeZero = m_pTiles[50]->Read(4009) == 0.0;
            if (noticeDone && noticeZero && !m_pTiles[50]->Flag(4110) && _g_thePlayer->PendingLevels() == 0)
            {
                GetXPAudio()->GetSoundByEditorID("UILevelUpText", 0x121).Play(false);
                m_pTiles[50]->Set(4009, 0.0f, true);
                m_pTiles[50]->Animate(4009, 0.0f, xpAlpha, 0.5f, 0);
                m_pTiles[50]->Set(4036, xpLevelLabel.String(), true);
                m_pTiles[50]->Set(4003, 1);
                m_pTiles[50]->SetUInt(4109, xpClock.Time());
                m_pTiles[50]->Set(4110, 1);
            }
            else
            {
                if (xpClock.Time() - m_pTiles[50]->Read(4109) > 1500.0 && !noticeZero && noticeDone)
                {
                    m_pTiles[50]->SetUInt(4109, xpClock.Time() + 2000);
                    m_pTiles[50]->Animate(4009, xpAlpha, 0.0f, 0.5f, 0);
                }
                else if (!m_bSequenceActive && noticeDone && noticeZero)
                {
                    m_bSequenceActive = true;
                    xpFlags = 8;
                    m_pTiles[50]->Set(4110, 0);
                }
            }
        }
        else if (xpFlags & 4)
        {
            bool noticeFinished40 = (xpFlags & 8) > 0;
            bool noticeDone = m_pTiles[50]->Done(4009);
            bool noticeIsZero37 = m_pTiles[50]->Read(4009) == 0.0;
            if (!noticeFinished40)
            {
                if (hasPendingLevel18)
                    xpFlags |= 1;
                else if (!visible)
                    xpFlags = 2;
            }
            else if (!m_bSequenceActive && noticeDone && noticeIsZero37)
            {
                m_bSequenceActive = true;
                xpFlags = 8;
                m_pTiles[50]->Set(4110, 0);
            }
        }
    }
}
