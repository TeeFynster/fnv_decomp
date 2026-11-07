#include "../../../../include/Tile.h"
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/InventoryStackRecord.h"
#include "../../../../include/TESObjectWEAP.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/Menu.h"
#include "../../../../include/RepairServicesMenu.h"
#include "../../../../include/TESTopic.h"

// src/fallout/interface/menus/repairservicesmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/repairservicesmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x007b74c0
// src: COMMUNITY 0x007b74c0
int RepairServicesMenu::GetMenuID_007b74c0()
{
    return 0x422;
}

// @fnv 0x007b7890
// src: COMMUNITY 0x007b7890
int __cdecl RepairServicesMenu_GetMenuID_()
{
    return 0x422;
}

// Returns true only if all 16 menu tiles are non-null.
// @fnv 0x007b78a0
// src: COMMUNITY 0x007b78a0
bool __thiscall RepairServicesMenu::CompanionWheelMenu_IsWellFormedMenu()
{
    for (int i = 0; i < 16; ++i)
    {
        if (reinterpret_cast<int*>(layoutExtension)[i] == 0)
            return false;
    }
    return true;
}

// @fnv 0x007b8ae0
void RepairServicesMenu::UpdateRepairServiceTiles(int aiID, Tile* apTarget)
{
    if (aiID == 0x11)
    {
        pTile5C->Set(0xFAF, 1);
        field34->Set(0xFA3, 0);
        field38->Set(0xFA3, 0);
    }
}

void __cdecl StartDialogueForTopic(TESTopic*);
extern RepairServicesMenu* DAT_011da7f0;
// @fnv 0x007b78e0
// src: XBOX_PDB 0x007b78e0
void __cdecl RepairServicesMenu_Close()
{
    StartDialogueForTopic(TESTopic::GetAudioBackendData(5, 5));
    reinterpret_cast<Tile*>(DAT_011da7f0->pMenu)->Set(0x1772, 1);
    ((Menu*)DAT_011da7f0)->LoadMenuData();
}

namespace fnv_007b82c0 {
extern int DAT_011da7dc;
extern RepairServicesMenu* DAT_011da7f0;

// @fnv 0x007b82c0
// src: XBOX_PDB 0x007b82c0
void __cdecl RepairServicesMenu_RepairAllFunc(Tile* pTile, void* pItem)
{
    if (pTile->ContainsTrait(DAT_011da7dc))
        DAT_011da7f0->ApplyRepair(pItem);
}
}  // namespace fnv_007b82c0

// Destructor that clears the global DAT_011da7f0 pointer to null.
// @fnv 0x007b7500
RepairServicesMenu::~RepairServicesMenu()
{
    DAT_011da7f0 = 0;
}

struct ListBoxItem
{
    Tile* m_pTile;
    InventoryStackRecord* m_pInventoryEntryData;
};

extern int DAT_011da7dc;

// @fnv 0x007b7c40
// src: COMMUNITY 0x007b7c40
int __cdecl RepairServicesMenu_Compare(ListBoxItem* apItem1, ListBoxItem* apItem2)
{
    bool bisGreyedOut1;
    bool bisGreyedOut2;
    int iresult = 0;

    bisGreyedOut1 = !apItem1->m_pTile->ContainsTrait(DAT_011da7dc);
    bisGreyedOut2 = !apItem2->m_pTile->ContainsTrait(DAT_011da7dc);

    if (bisGreyedOut1 && !bisGreyedOut2)
    {
        iresult = 1;
    }
    else if (!bisGreyedOut1 && bisGreyedOut2)
    {
        iresult = -1;
    }
    else
    {
        if (apItem1->m_pInventoryEntryData->GetConditionPercent(false) <
            apItem2->m_pInventoryEntryData->GetConditionPercent(false))
        {
            iresult = 1;
        }
        else if (apItem1->m_pInventoryEntryData->GetConditionPercent(false) >
                 apItem2->m_pInventoryEntryData->GetConditionPercent(false))
        {
            iresult = -1;
        }
        else
        {
            if (apItem1->m_pInventoryEntryData->ItemChange_GetWorn(false))
            {
                iresult = -1;
            }
            else if (apItem2->m_pInventoryEntryData->ItemChange_GetWorn(false))
            {
                iresult = 1;
            }
        }
    }

    if (bisGreyedOut1 && bisGreyedOut2)
        iresult = -iresult;

    return iresult;
}

extern char DAT_0106ed20;
extern char DAT_0106ed18;
extern char DAT_01075da0;
extern char DAT_01075d94;
extern int DAT_011da7e0;
extern int DAT_011da7e8;
extern int DAT_011da7e4;
extern int __cdecl Tile_TextToTrait(const char*);

// Initializes the repair service traits and clears the total cost.
// @fnv 0x007b7400
RepairServicesMenu::RepairServicesMenu()
{
    DAT_011da7e0 = Tile_TextToTrait(&DAT_0106ed20);
    DAT_011da7e8 = Tile_TextToTrait(&DAT_0106ed18);
    DAT_011da7e4 = Tile_TextToTrait(&DAT_01075da0);
    DAT_011da7dc = Tile_TextToTrait(&DAT_01075d94);
    iTotalCost = 0;
}

struct Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual bool v94();
    int FUN_00401170();
    double TESObjectARMO_GetArmorRating();
    double TESObjectARMO_GetDamageThreshold();
    bool TESBipedModelForm_GetPlayable();
};

struct Holder
{
    Obj* FUN_0044ddc0();
    double ItemChange_GetItemHealth(int);
};

struct Cfg
{
    float* Setting_Float_00403e20();
};

extern Cfg DAT_011d018c;
extern double DAT_01020758;
extern double DAT_01012060;

Obj* __cdecl FUN_00480db0(Obj*);
bool __cdecl TESContainer_IsGold(Obj*);
int __cdecl GetHealthForm(Obj*);

// Checks the holder's object and its state, comparing a value against config thresholds and returning whether the condition holds.
// @fnv 0x007b7b40
// src: COMMUNITY 0x007b7b40
bool __cdecl RepairServicesMenu_ShouldHideItem(Holder* pHolder)
{
    bool result2 = true;
    Obj* a7 = pHolder->FUN_0044ddc0();
    Obj* b = FUN_00480db0(a7);
    if (a7 == 0 || (b != 0 && !b->TESBipedModelForm_GetPlayable()) || TESContainer_IsGold(a7) || a7->v94())
    {
        result2 = true;
    }
    else
    {
        result2 =
            GetHealthForm(a7) == 0 || pHolder->ItemChange_GetItemHealth(1) >= (double)*DAT_011d018c.Setting_Float_00403e20() * DAT_01020758 ||
            (a7->FUN_00401170() == 0x18 && a7->TESObjectARMO_GetArmorRating() <= DAT_01012060 && a7->TESObjectARMO_GetDamageThreshold() <= DAT_01012060);
    }
    return result2;
}

struct RepairPlayer
{
    void FUN_008924e0(void*, int);
};
extern RepairPlayer* DAT_011dea3c;
extern void* DAT_011da7f4;
extern int DAT_011da7e4;
extern char DAT_01075d38, DAT_01073a94;
bool __cdecl RepairServicesMenu_RepairAllFunc(void*, void*);

// @fnv 0x007b7d80
void RepairServicesMenu::HandleRepairAction(int iActionId, RepairTile* tile)
{
    if (!tile && iActionId >= 0 && iActionId < 16)
        tile = reinterpret_cast<RepairTile*>(tiles[iActionId]);
    switch (iActionId)
    {
    case 17:
        if (reinterpret_cast<Tile*>(tile)->IsTraitNonZero(DAT_011da7dc))
        {
            ApplyRepair(kRepairList.FUN_007a1910());
            DAT_011dea3c->FUN_008924e0(DAT_011da7f4, (int)reinterpret_cast<Tile*>(tile)->FUN_00a011b0(DAT_011da7e4));
            BSAudio::GetSingleton()->GetSoundHandleByEditorID(&DAT_01075d38, 0x121).Play(false);
            RefreshRepairMenu();
        }
        else
        {
            BSAudio::GetSingleton()->GetSoundHandleByEditorID(&DAT_01073a94, 0x121).Play(false);
        }
        break;
    case 14:
        kRepairList.ListBox_ItemChange_Traverse(RepairServicesMenu_RepairAllFunc, 0, 0x7fffffff);
        DAT_011dea3c->FUN_008924e0(DAT_011da7f4, totalCost);
        BSAudio::GetSingleton()->GetSoundHandleByEditorID(&DAT_01075d38, 0x121).Play(false);
        RefreshRepairMenu();
        break;
    case 15:
        RepairServicesMenu_Close();
        break;
    }
}

void __cdecl ProgramFlow(const char* apMessage);
void __cdecl FNV_Warning(const char* apMessage);
int __cdecl BSstrcmp(const char* apString1, const char* apString2);
float __cdecl FUN_00a01530();
void __cdecl DialogMenu_ServiceStart();

struct RSMInterfaceManager
{
    static RSMInterfaceManager* __cdecl GetSingleton();
    Tile* GetMenuRoot();
};

struct RSMSetting
{
    const char* GetString();
};

struct RSMExtraList
{
    int GetByType(int aiType);
};

struct RSMActor
{
    int unk00[0x29];
    RSMExtraList kExtraList;
};

int __cdecl RepairServicesMenu_GetMenuID_();
RepairServicesMenu* __cdecl Tile_GetMenuByClass(int aiMenuID);

extern RepairServicesMenu* g_pRepairServicesMenu;
extern RSMActor* g_pRepairServicesVendor;
extern int g_iRepairServicesValue1;
extern int g_iRepairServicesValue2;
extern RSMSetting g_kLanguageSetting;
extern RSMSetting g_kHeadlineSetting;
extern RSMSetting g_kEmptyListSetting;
extern RSMSetting g_kCapsSetting;
extern RSMSetting g_kDescSetting1;
extern RSMSetting g_kDescSetting2;

// Loads the repair services menu XML, validates its ID, binds the vendor and repair list, and applies localized strings when the language is English.
// @fnv 0x007b7570
Tile* __cdecl CreateRepairServicesMenu(RSMActor* apVendor)
{
    RepairServicesMenu* pOldMenu5;
    Tile* pTile;
    RSMInterfaceManager* pInterfaceMgr2;

    if (!apVendor)
    {
        ProgramFlow(
            "Create() -- Missing vendor parameter.  4 bytes large, responds to the name 'Vendy'.  Please call if you see him!");
        return 0;
    }

    pInterfaceMgr2 = RSMInterfaceManager::GetSingleton();
    pOldMenu5 = Tile_GetMenuByClass(RepairServicesMenu_GetMenuID_());
    if (pOldMenu5)
        delete pOldMenu5;

    pTile = pInterfaceMgr2->GetMenuRoot()->ReadFile("Data\\Menus\\repair_services_menu.xml");
    g_pRepairServicesMenu = reinterpret_cast<RepairServicesMenu*>(pTile->GetMenu());
    if (g_pRepairServicesMenu && g_pRepairServicesMenu->GetClass() == RepairServicesMenu_GetMenuID_())
    {
        g_pRepairServicesMenu->SetTileMenu(reinterpret_cast<TileMenu*>(pTile), false);
        if (!g_pRepairServicesMenu->CompanionWheelMenu_IsWellFormedMenu())
        {
            FNV_Warning("MENUS: Repair Services Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (pTile->GetFloat(0xfa7) == 6006.0 || pTile->GetFloat(0xfa7) == 102.0)
            pTile->SetFloat(0xfad, FUN_00a01530(), true);
        g_pRepairServicesMenu->pTile40->SetTraitFloat(g_iRepairServicesValue2, 1.0f);
        g_pRepairServicesMenu->pTile54->SetTraitFloat(g_iRepairServicesValue2, 1.0f);
        g_pRepairServicesVendor = apVendor;
        g_pRepairServicesMenu->iUnk9C = apVendor->kExtraList.GetByType(0x27);
        g_pRepairServicesMenu->kRepairList.Initialize(g_pRepairServicesMenu->pTile30, "RSM_RepairListTemplate");
        g_pRepairServicesMenu->RefreshRepairMenu();
        DialogMenu_ServiceStart();
        if (BSstrcmp(g_kLanguageSetting.GetString(), "ENGLISH"))
        {
            pTile->GetNamedChild("RSM_Headline_Title")
                ->SetString(g_iRepairServicesValue1, g_kHeadlineSetting.GetString(), true);
            pTile->GetNamedChild("RSM_EmptyRepairListText")
                ->SetString(g_iRepairServicesValue1, g_kEmptyListSetting.GetString(), true);
            g_pRepairServicesMenu->pTile3C->SetString(g_iRepairServicesValue1, g_kCapsSetting.GetString(), true);
            g_pRepairServicesMenu->pTile50->SetString(g_iRepairServicesValue1, g_kCapsSetting.GetString(), true);
            g_pRepairServicesMenu->pTile5C->SetString(0xfc4, g_kDescSetting1.GetString(), true);
            g_pRepairServicesMenu->pTile64->SetString(0xfc4, g_kDescSetting2.GetString(), true);
        }
        g_pRepairServicesMenu->FUN_00a1dc20(0);
        return pTile;
    }
    else if (g_pRepairServicesMenu && g_pRepairServicesMenu->FUN_00726070())
    {
        delete g_pRepairServicesMenu;
    }
    return 0;
}

struct RSItemForm;

struct RSItem
{
    RSItemForm* GetType();
    float GetConditionPercent(bool abPercent);
    bool ItemChange_GetWorn(bool abUnk);
};

struct RSTileList
{
    void* GetHeadPos();
    void* GetTailPos();
    Tile*& GetAt(void* apPos);
};

struct RSPlayer
{
    int GetCaps();
};

extern RepairServicesMenu* g_pRepairServicesMenu;
extern RSPlayer* g_pRSPlayer;
int __cdecl TESValueForm_GetFormValue(RSItemForm* apForm);
int __cdecl GetLevelAdjustedMult(int aiSkill, float afHealth, float afValue);

// @fnv 0x007b7920
void __cdecl UpdateRepairMenuTile(Tile* apTile, RSItem* apItem)
{
    if (!apTile || !apItem)
        return;

    int iCost = GetLevelAdjustedMult(g_pRepairServicesMenu->iSkill, apItem->GetConditionPercent(true),
                                     TESValueForm_GetFormValue(apItem->GetType()));
    float fAlpha4 = (iCost > 0 && iCost <= g_pRSPlayer->GetCaps()) ? 255.0f : 128.0f;
    apTile->SetInt(0xfaa, 0x11);
    apTile->SetInt(DAT_011da7e4, iCost);
    g_pRepairServicesMenu->iTotalCost += iCost;
    reinterpret_cast<RSTileList*>(&apTile->m_kChildTileList)->GetAt(reinterpret_cast<RSTileList*>(&apTile->m_kChildTileList)->GetTailPos())->SetFloat(0xfa9, fAlpha4, true);
    apTile->GetChildById(0x12)->SetFloat(0xfa9, fAlpha4, true);
    reinterpret_cast<RSTileList*>(&apTile->m_kChildTileList)->GetAt(reinterpret_cast<RSTileList*>(&apTile->m_kChildTileList)->GetHeadPos())->SetFloat(0xfa9, fAlpha4, true);
    apTile->SetInt(0xfa3, apTile->GetFloat(0xfac) >= 0.0);
    apTile->GetChildById(0x12)->SetFloat(0xfb1, apItem->GetConditionPercent(true) * (double)0.6f, true);
    apTile->SetInt(DAT_011da7dc, fAlpha4 == 255.0);
    if (apItem->ItemChange_GetWorn(false))
        reinterpret_cast<RSTileList*>(&apTile->m_kChildTileList)->GetAt(reinterpret_cast<RSTileList*>(&apTile->m_kChildTileList)->GetHeadPos())->SetInt(0xfa3, 1);
}

// List sorting uses virtual slot 0x20; the shared list header has no Sort declaration.
struct RepairListView
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Sort(int(__cdecl*)(ListBoxItem*, ListBoxItem*));
};
struct RepairPlayerView
{
    int Actor_GetGoldAmount();
};
struct RepairSetting
{
    const char* FUN_00403df0();
    int* Setting_Int();
};
extern RepairSetting DAT_011d3a08, DAT_011d25b0, DAT_011d4030, DAT_011d4780;
extern char DAT_01075f34, DAT_01070854;
void __cdecl UpdateRepairMenuTile(Tile*, void*);
int __cdecl BSsprintf(char*, int, const char*, ...);

// @fnv 0x007b8b30
void RepairServicesMenu::RefreshRepairMenu()
{
    char szText[64];
    if (DAT_011da7f0)
    {
        ((RepairServicesMenu*)DAT_011da7f0)->totalCost = 0;
        ((RepairServicesMenu*)DAT_011da7f0)->HandleMouseoverTileAlt(17, 0);
        DAT_011da7f0->kRepairList.PopulateInventoryList(DAT_011dea3c, RepairServicesMenu_ShouldHideItem, 0, 0, 1, 0);
        DAT_011da7f0->kRepairList.ListBox_ItemChange_Traverse(UpdateRepairMenuTile, -1, 0x7fffffff);
        ((RepairListView*)&((RepairServicesMenu*)DAT_011da7f0)->kRepairList)->Sort(RepairServicesMenu_Compare);
        if (((RepairPlayerView*)DAT_011dea3c)->Actor_GetGoldAmount() > *DAT_011d3a08.Setting_Int())
            BSsprintf(szText, 64, &DAT_01075f34, DAT_011d25b0.FUN_00403df0(), *DAT_011d3a08.Setting_Int());
        else
            BSsprintf(szText, 64, &DAT_01070854, DAT_011d25b0.FUN_00403df0(),
                         ((RepairPlayerView*)DAT_011dea3c)->Actor_GetGoldAmount());
        ((Tile*)tiles[1])->Tile_Set_00a01350(0xfc4, szText, true);
        BSsprintf(szText, 64, &DAT_01070854, DAT_011d4030.FUN_00403df0(), displayedCost);
        ((Tile*)tiles[0])->Tile_Set_00a01350(0xfc4, szText, true);
        BSsprintf(szText, 64, DAT_011d4780.FUN_00403df0(), ((RepairServicesMenu*)DAT_011da7f0)->totalCost);
        ((Tile*)((RepairServicesMenu*)DAT_011da7f0)->tiles[14])->Tile_Set_00a01350(0xfc4, szText, true);
        ((Tile*)((RepairServicesMenu*)DAT_011da7f0)->tiles[14])
            ->Set(0xfaf,
                  ((RepairServicesMenu*)DAT_011da7f0)->totalCost > 0 &&
                      ((RepairServicesMenu*)DAT_011da7f0)->totalCost <= ((RepairPlayerView*)DAT_011dea3c)->Actor_GetGoldAmount());
    }
}

struct StatForm
{
    int FUN_00401170();
    double TESObjectARMO_GetArmorRating();
    double TESObjectARMO_GetDamageThreshold();
};
struct StatItem
{
    StatForm* FUN_0044ddc0();
    double ItemChange_GetItemHealth(int);
    const char* GetIconFilename(int);
};
struct StatItemProvider
{
    StatItem* FUN_007a1910();
};
struct StatValue
{
    float value;
};
struct StatSetting
{
    const char* FUN_00403df0();
    StatValue* Setting_Float_00403e20();
};
extern StatSetting DAT_011d2c7c, DAT_011d396c, DAT_011d20c4, DAT_011d0ff0, DAT_011d4ee8, DAT_011d3cf4;
float __cdecl GetWeaponDamage(StatForm*, float, StatItem*, int);
double __cdecl FUN_004bd510(float, float);
double __cdecl FUN_00646360(int, float);
float __cdecl BSMIN(float, float);
float __cdecl BSMAX_00404010(float, float);
int __cdecl RepairCopyString(char*, unsigned int, const char*);
int __cdecl RepairAppendString(char*, unsigned int, const char*);
int __cdecl RepairFormatString(char*, unsigned int, const char*, ...);

// @fnv 0x007b82f0
void RepairServicesMenu::UpdateItemComparison(int event, StatTile* tile)
{
    if (event == 17)
    {
        char text[64];
        StatItem* selectedItemTmp = static_cast<StatItem*>(kRepairList.FUN_007a1910());
        float health2 = 0.0f;
        float projected6 = 0.0f;
        field5c->Set(0xfaf, (int)reinterpret_cast<Tile*>(tile)->IsTraitNonZero(DAT_011da7dc));
        field38->Set(0xfa3, 1);
        field34->Set(0xfcc, selectedItemTmp->GetIconFilename(0), true);
        field34->Set(0xfa3, 1);
        health2 = selectedItemTmp->ItemChange_GetItemHealth(1) / 100.0;
        field3c->Set(0x1004, health2, true);
        if (selectedItemTmp->FUN_0044ddc0()->FUN_00401170() == 40)
        {
            field40->Set(DAT_011da7e0, DAT_011d2c7c.FUN_00403df0(), true);
            field40->Set(
                DAT_011da7e8,
                (int)FUN_004bd510(GetWeaponDamage(selectedItemTmp->FUN_0044ddc0(), health2, selectedItemTmp, 0), 1.0f));
        }
        else if (selectedItemTmp->FUN_0044ddc0()->FUN_00401170() == 24)
        {
            float armor3 = FUN_00646360((int)selectedItemTmp->FUN_0044ddc0()->TESObjectARMO_GetArmorRating(), health2);
            float threshold0 = FUN_00646360((int)selectedItemTmp->FUN_0044ddc0()->TESObjectARMO_GetDamageThreshold(), health2);
            if (threshold0 > 0.0)
            {
                ((RepairServicesMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e0, DAT_011d396c.FUN_00403df0(), true);
                ((RepairServicesMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e8, (int)threshold0);
            }
            else if (armor3 > 0.0)
            {
                ((RepairServicesMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e0, DAT_011d20c4.FUN_00403df0(), true);
                ((RepairServicesMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e8, (int)armor3);
            }
            else
            {
                char empty0[128];
                RepairCopyString(empty0, 128, "--");
                ((RepairServicesMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e0, DAT_011d20c4.FUN_00403df0(), true);
                ((RepairServicesMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e8, empty0, true);
            }
        }
        projected6 = DAT_011d0ff0.Setting_Float_00403e20()->value +
                     (((StatSetting&)DAT_011d018c).Setting_Float_00403e20()->value - DAT_011d0ff0.Setting_Float_00403e20()->value) *
                         (iRepairSkill / 100.0f);
        projected6 = BSMIN(projected6 / 10.0, 1.0f);
        if (FUN_004bd510(projected6, 0.001f) <= FUN_004bd510(health2, 0.001f))
        {
            RepairFormatString(text, 64, DAT_011d4ee8.FUN_00403df0(), projected6 * 100.0, "%");
            field4c->Set(0xfc4, text, true);
            field50->Set(0xfa3, 0);
        }
        else
        {
            field50->Set(0x1004, projected6, true);
            field50->Set(0xfa3, 1);
            if (selectedItemTmp->FUN_0044ddc0()->FUN_00401170() == 40)
            {
                field54->Set(DAT_011da7e0, DAT_011d2c7c.FUN_00403df0(), true);
                field54->Set(DAT_011da7e8, (int)FUN_004bd510(GetWeaponDamage(selectedItemTmp->FUN_0044ddc0(),
                                                                             projected6, selectedItemTmp, 0),
                                                             1.0f));
            }
            else if (selectedItemTmp->FUN_0044ddc0()->FUN_00401170() == 24)
            {
                float aThreshold1 = FUN_00646360((int)selectedItemTmp->FUN_0044ddc0()->TESObjectARMO_GetArmorRating(), projected6);
                float armor6 = FUN_00646360((int)selectedItemTmp->FUN_0044ddc0()->TESObjectARMO_GetDamageThreshold(), projected6);
                if (armor6 > 0.0)
                {
                    ((RepairServicesMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e0, DAT_011d396c.FUN_00403df0(), true);
                    ((RepairServicesMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e8, (int)armor6);
                }
                else if (aThreshold1 > 0.0)
                {
                    ((RepairServicesMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e0, DAT_011d20c4.FUN_00403df0(), true);
                    ((RepairServicesMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e8, (int)aThreshold1);
                }
                else
                {
                    char emptyTmp[128];
                    RepairCopyString(emptyTmp, 128, "--");
                    ((RepairServicesMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e0, DAT_011d20c4.FUN_00403df0(), true);
                    ((RepairServicesMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e8, emptyTmp, true);
                }
            }
            float healthDelta_2 = (field50->FUN_00a011b0(0x1004) - field3c->FUN_00a011b0(0x1004)) * 100.0;
            float statDelta2 = field54->FUN_00a011b0(DAT_011da7e8) - field40->FUN_00a011b0(DAT_011da7e8);
            healthDelta_2 = BSMAX_00404010(0.0f, healthDelta_2);
            statDelta2 = BSMAX_00404010(0.0f, statDelta2);
            RepairFormatString(text, 64, "+%i", (int)(healthDelta_2 + 0.5));
            RepairAppendString(text, 64, "%");
            field44->Set(0xfc4, text, true);
            RepairFormatString(text, 64, "+%i", (int)(statDelta2 + 0.5));
            field48->Set(0xfc4, text, true);
            RepairFormatString(text, 64, DAT_011d3cf4.FUN_00403df0(), (int)reinterpret_cast<Tile*>(tile)->FUN_00a011b0(DAT_011da7e4));
            field58->Set(0xfc4, text, true);
            field58->Set(0xfa9, reinterpret_cast<Tile*>(tile)->IsTraitNonZero(DAT_011da7dc) ? 255.0f : 128.0f, true);
        }
    }
}

float __cdecl BSMIN(float afValue, float afMin);
unsigned int __cdecl FUN_004873d0(TESBoundObject* apObject);

struct ExtraListNode
{
    ExtraDataList** GetItem();
    ExtraListNode* GetNext();
    void AddHead(ExtraDataList* const& apItem);
    void Remove(ExtraDataList* const& apItem);
};

struct RepairEntry
{
    TESBoundObject* FUN_0044ddc0();
    bool HasEffect(int aiValue);
    ExtraListNode* GetExtraLists();
    void* FUN_004bde40();
};

struct RepairInventory
{
    static RepairInventory* __cdecl GetOrAddInventoryChanges(void* apRef);
    RepairEntry* FUN_004bfba0(TESBoundObject* apForm, int aiUnk1, int aiUnk2);
};

// Computes a repair value from iRepairSkill and the entry's form, then merges or replaces the extra health extra data in the player's inventory changes.
// @fnv 0x007b7f70
void RepairServicesMenu::ApplyRepair(RepairEntry* apEntry)
{
    TESObjectWEAP* pWeapon;
    RepairEntry* pPlayerEntry;
    ExtraDataList* pNewList4;
    bool bMergedTmp;
    ExtraDataList* pOldListOut;
    ExtraListNode* pNodeOut;
    int iCount8;

    float fHealthPercent = 0.0f;
    fHealthPercent = DAT_011d0ff0.Setting_Float_00403e20()->value +
              (*DAT_011d018c.Setting_Float_00403e20() - DAT_011d0ff0.Setting_Float_00403e20()->value) * (iRepairSkill / 100.0f);
    fHealthPercent = BSMIN(fHealthPercent / 10.0, 1.0f);
    pWeapon = dynamic_cast<TESObjectWEAP*>(apEntry->FUN_0044ddc0());
    if (pWeapon)
        fHealthPercent *= pWeapon->GetModdedValue(apEntry->HasEffect(10));
    else
        fHealthPercent *= FUN_004873d0(apEntry->FUN_0044ddc0());
    pPlayerEntry = RepairInventory::GetOrAddInventoryChanges(DAT_011dea3c)->FUN_004bfba0(apEntry->FUN_0044ddc0(), 1, 0);
    pOldListOut = apEntry->GetExtraLists() ? *apEntry->GetExtraLists()->GetItem() : 0;
    pNewList4 = new ExtraDataList;
    iCount8 = -1;
    bMergedTmp = false;
    iCount8 = pOldListOut->GetCount();
    pNewList4->CopyFrom(pOldListOut);
    pNewList4->SetCount(1);
    pNewList4->SetExtraHealth(fHealthPercent);
    if (iCount8 > 1)
        pOldListOut->SetCount(iCount8 - 1);
    for (pNodeOut = pPlayerEntry->GetExtraLists(); pNodeOut && *pNodeOut->GetItem(); pNodeOut = pNodeOut->GetNext())
    {
        if (apEntry->FUN_0044ddc0()->FUN_00401170() == 0x18 && apEntry->FUN_004bde40())
            break;
        if (!(*pNodeOut->GetItem())->ExtraDataList_CompareListForContainer(pNewList4, 1, 0) &&
            !pNewList4->ExtraDataList_CompareListForContainer(*pNodeOut->GetItem(), 1, 0))
        {
            (*pNodeOut->GetItem())->SetCount((*pNodeOut->GetItem())->GetCount() + 1);
            bMergedTmp = true;
        }
    }
    if (!bMergedTmp)
    {
        if (iCount8 > 1)
            pPlayerEntry->GetExtraLists()->AddHead(pNewList4);
        else
            pOldListOut->SetExtraHealth(fHealthPercent);
    }
    else if (iCount8 == 1)
        pPlayerEntry->GetExtraLists()->Remove(pOldListOut);
    if (bMergedTmp || iCount8 == 1)
    {
        pNewList4->ExtraDataList_SetScriptLocals(0);
        // Preserve virtual deletion through slot zero, exposed as vf00 by BaseExtraList.
        delete reinterpret_cast<Menu*>(pNewList4);
    }
}
