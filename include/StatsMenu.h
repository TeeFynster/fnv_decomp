#pragma once

#include "Menu.h"
#include "StatsMenu__HealingOption.h"
#include "StatsMenu__NamedEffectsList.h"
#include "StatsMenu__StatusEffectList.h"
#include "ListBox_enum_ActorValue__Index_.h"
#include "ListBox_enum_MiscStatManager__MiscStatID_.h"
#include "ListBox_PerkRankData___.h"
#include "ListBox_StatsMenu__StatusEffect___.h"
#include "ListBox_TESReputation___.h"

#include "MiscStatManager.h"

class StatsMenu : public Menu
{
public:
    enum Page
    {
        SM_STATUS = 0,
        SM_FIRST_PAGE = 0,
        SM_SPECIAL = 1,
        SM_SKILLS = 2,
        SM_PERKS = 3,
        SM_GENERAL = 4,
        SM_LAST_PAGE = 4,
        SM_PAGE_COUNT = 5
    };

    class BodyPartDisplay
    {
    public:
        int m_iBodyPartCount;
        BSSimpleList<Tile*> m_kBodyPartTileLists[6];
        unsigned int m_auiBodyPartValues[6];

        BodyPartDisplay();
    };

    virtual void AssignTileByID(int, Tile*);
    virtual int GetClass();

    StatsMenu__HealingOption m_kHealingOptions[4];
    StatsMenu__NamedEffectsList m_kNamedEffectsList;
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex0;
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex1;
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex2;
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex3;
    StatsMenu__StatusEffectList m_kStatusEffectEntries;

    Tile* m_pTiles[60];
    ListBox_enum_ActorValue__Index_ m_kPrimaryActorValueList;
    ListBox_enum_ActorValue__Index_ m_kSecondaryActorValueList;
    ListBox_PerkRankData___ m_kPerkRankList;
    ListBox_enum_MiscStatManager__MiscStatID_ m_kMiscStatList;
    ListBox_StatsMenu__StatusEffect___ m_kStatusEffectList;
    ListBox_TESReputation___ m_kReputationList;
    union
    {
        bool m_bUpdateOption;
        unsigned char m_bHealingMode;
    };
    bool m_bStatUpdatePending;
    unsigned char unk2A2[2];

    static StatsMenu* ms_pInventoryMenu;
    static float GetChartScale();
    static void SetStatsPage(unsigned char page);
    static bool SetTileFlashing(Tile*, unsigned int);
    static void UpdatePrimaryActorValueTile(Tile* tile, ActorValue::Index value);
    static void UpdateSecondaryActorValueTile(Tile* tile, ActorValue::Index value);
    static void UpdateMiscStatTile(Tile* tile, MiscStatManager__MiscStatID value);
    static void __cdecl UpdateStatusEffects();
    static void ClearPerks();

    void SetCurrentPage(Page page);
    Page GetCurrentPage();
    void SetCurrentPageFromChar(char a);
    int GetTraitForValue(ActorValue::Index value);
    void UpdateActorValueTiles();
    void RefreshActorValueTile(ActorValue::Index value);
    void RefreshMiscStat(MiscStatManager__MiscStatID value);
    void RefreshMiscStat(MiscStatManager::MiscStat value);
    void __thiscall RefreshHealingOptions();
    void FUN_0071f700();
    void* FUN_0071f6d0(unsigned int flags);
};
