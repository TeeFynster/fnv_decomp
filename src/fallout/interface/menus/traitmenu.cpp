#include "../../../../include/TraitMenu.h"
#include "../../../../include/OSGlobals.h"
#include "../../../../include/Actor.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/EffectSetting.h"
#include "../../../../include/EffectItem.h"
#include "../../../../include/Menu.h"
#include "../../../../include/StatsMenu.h"
#include "../../../../include/Tile.h"
#include "../../../../include/BGSPerk.h"
#include "../../../../include/HUDMainMenu.h"
#include "../../../../include/StartMenu.h"
#include "../../../../include/Setting.h"
// EffectNode_traitmenu: local type (was include/EffectNode.h, which had no evidence of one real class); its methods are 0x006815c0 ReturnThis, 0x00726070 TESHealthForm::GetHealth, 0x008256d0 BSSimpleList<Actor *>::IsEmpty
class ActiveEffect;
class TESForm;

class EffectNode_traitmenu
{
public:
    TESForm* form;
    EffectNode_traitmenu* next;

    bool __thiscall FUN_008256d0();
    ActiveEffect** __thiscall FUN_006815c0();
    EffectNode_traitmenu* __thiscall FUN_00726070();
    EffectItem** GetItem();
    EffectNode_traitmenu* GetNext();
};
// NiNodeBooleanState_traitmenu: local type (was include/NiNodeBooleanState.h, which had no evidence of one real class); its methods are 0x008d0360 ReturnTrue, 0x008d51f0 CharacterProgression::QReadyToLevelUp, 0x008d5270 CharacterProgression::FinishLevelUp
#include "../../../../include/NiAVObject.h"

class NiNode;

class NiNodeBooleanState_traitmenu
{
public:
    NiPointer<NiNode> pData;

    __declspec(noinline) bool GetBooleanValue();
    void CharacterProgression_FinishLevelUp();
};

// src/fallout/interface/menus/traitmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/traitmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x007e68a0
// src: COMMUNITY 0x007e68a0
int TraitMenu::GetMenuID_007e68a0()
{
    return 0x43c;
}

// @fnv 0x007e6dc0
// src: COMMUNITY 0x007e6dc0
int TraitMenu_GetMenuID_0()
{
    return 0x43c;
}

// @fnv 0x007e6dd0
// src: GUESS 0x007e6dd0 (confidence: high)
bool TraitMenu::HasAllNineTiles()
{
    for (int i = 0; i < 9; ++i)
    {
        if (m_pTiles[i] == 0)
            return false;
    }
    return true;
}

extern HUDMainMenu DAT_011f2250;

// @fnv 0x007e73c0
// src: XBOX_PDB 0x007e73c0
void TraitMenu::DoIdle_007e73c0()
{
    if ((int)m_eFadeState == 4)
    {
        if (!DAT_011f2250.RefreshTargetDisplay())
        {
            SetMenuVisibility(false);
        }
    }
}


extern int DAT_011daf5c;
extern int DAT_011daf74;

// @fnv 0x007e7630
// src: GUESS 0x007e7630 (confidence: medium)
void Tile_ClearTraitAndUpdateEffectChanges(Tile* apTile)
{
    if (apTile->ContainsTrait(DAT_011daf5c))
    {
        apTile->Set(DAT_011daf5c, 0);
        ((Tile*)DAT_011daf74)->UpdateEffectChanges(apTile);
    }
}

// Stores tile in the slot at index id when id is between 0 and 8.
// @fnv 0x007e68b0
void TraitMenu::SetTileById(int id, Tile* tile)
{
    if (id >= 0 && id < 9)
    {
        m_pTiles[id] = tile;
    }
}

namespace fnv_007e75d0 {

// Exe 0x007e75d0: unit-local Interface view; declarations and layout are preserved.
struct TraitmenuInterfaceView
{
    static void __cdecl PlayUISound(int);
};
}  // namespace fnv_007e75d0

// @fnv 0x007e75d0
bool TraitMenu::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 11:
        if (tile40->ContainsTrait(0xFAF))
        {
            fnv_007e75d0::TraitmenuInterfaceView::PlayUISound(1);
            HandleSelection(6, 0);
            bhandled = true;
        }
    }
    return bhandled;
}
namespace fnv_007e76e0 {

extern int DAT_011daf5c;
extern PlayerCharacter* g_thePlayer;
// @fnv 0x007e76e0
// src: COMMUNITY 0x007e76e0
void TraitMenu_IncreaseSelectedTraitRank(Tile* apTile, BGSPerk* apPerk)
{
    if (apTile->ContainsTrait(DAT_011daf5c))
        g_thePlayer->SetPerkRank(apPerk, g_thePlayer->GetPerkRank(apPerk, false) + 1, false);
}
}  // namespace fnv_007e76e0

struct PerkCursor
{
    BGSPerk** GetItem();
    PerkCursor* GetNext();
};

extern PlayerCharacter* g_thePlayer;

extern StartMenu g_011d35b8;
extern int DAT_011daf78;
// The game wrapper has a different address from the CRT strcpy_s declaration.
int GameStrcpyS(char*, unsigned int, const char*);
int _sprintf_s(char*, unsigned int, const char*, ...);
unsigned int BSStringLength(const char*);
// Initializes the LUM_PerkTemplate list and adds a tile per perk with its name and rank, setting two tile values.
// @fnv 0x007e7030
void TraitMenu::PopulatePerkList()
{
    int itotalSkillPoints = 0;
    int inumSkills = 0;
    box.Initialize(tile2c, "LUM_PerkTemplate");
    for (PerkCursor* pcurrentPerk = (PerkCursor*)((char*)this + 0x84); pcurrentPerk && *pcurrentPerk->GetItem();
         pcurrentPerk = pcurrentPerk->GetNext())
    {
        Tile* pnew;
        int icurrRank;
        char strtemp[64];
        icurrRank = g_thePlayer->GetPerkRank(*pcurrentPerk->GetItem(), false);
        pnew = 0;
        GameStrcpyS(strtemp, 64, (*pcurrentPerk->GetItem())->TESFullName::GetFullName());
        if (!BSStringLength(strtemp))
            GameStrcpyS(strtemp, 64, static_cast<const StartMenu&>(g_011d35b8).GetMenuTitle());
        if ((*pcurrentPerk->GetItem())->BGSPerk_GetNumRanks() > 1 && icurrRank > 0)
            _sprintf_s(strtemp, 64, "%s (%d)", strtemp, icurrRank + 1);
        pnew = box.AddItemTile(*pcurrentPerk->GetItem(), strtemp, 0, 0);
        pnew->Set(0xfaa, 10);
        pnew->Set(DAT_011daf78, icurrRank + 1);
    }
}

struct ListBox_TESObjectREFR
{
    void Traverse(void(__cdecl*)(Tile*, void*), int, int);
};

extern Actor* _g_thePlayer;
extern void __cdecl _FUN_007df4e0();
void __cdecl HUDMainMenu_ClearXPMeterFinishedMoving();
void __cdecl TraitMenu_IncreaseSelectedTraitRank(Tile*, void*);
// @fnv 0x007e6e10
// src: XBOX_PDB 0x007e6e10
void __cdecl TraitMenu_Close()
{
    HUDMainMenu_ClearXPMeterFinishedMoving();
    if (DAT_011daf74)
    {
        ((ListBox_TESObjectREFR*)((char*)DAT_011daf74 + 0x54))->Traverse(TraitMenu_IncreaseSelectedTraitRank, 0, 0x7fffffff);
        if (((NiNodeBooleanState_traitmenu*)((PlayerCharacter*)_g_thePlayer)->GetCharacterProgressionInfo())->GetBooleanValue())
            _g_thePlayer->ConfigureActorState(true, false);
        _FUN_007df4e0();
        StatsMenu::UpdateStatusEffects();
        ((Menu*)DAT_011daf74)->FUN_00726070()->Set(0x1772, 1);
        ((Menu*)DAT_011daf74)->LoadMenuData();
        DAT_011daf74 = 0;
    }
}

template <class T> struct TraitMenu::ListBoxItem
{
    Tile* pTile;
    BGSPerk* pValue;
};

extern int DAT_011daf70;

int __cdecl BSstrcmp(char const*, char const*);

// @fnv 0x007e7740
// src: COMMUNITY 0x007e7740
int Trait_CompareForSorting(TraitMenu::ListBoxItem<BGSPerk*>* apItem1, TraitMenu::ListBoxItem<BGSPerk*>* apItem2)
{
    int iresult;

    iresult = 0;
    if (apItem1->pTile->GetFloat(DAT_011daf70) < apItem2->pTile->GetFloat(DAT_011daf70))
    {
        iresult = 1;
    }
    else if (apItem1->pTile->GetFloat(DAT_011daf70) > apItem2->pTile->GetFloat(DAT_011daf70))
    {
        iresult = -1;
    }
    else if (apItem1->pValue->GetByteAt39() < apItem2->pValue->GetByteAt39())
    {
        iresult = -1;
    }
    else if (apItem1->pValue->GetByteAt39() > apItem2->pValue->GetByteAt39())
    {
        iresult = 1;
    }
    else
    {
        iresult = BSstrcmp(apItem1->pTile->GetString(0xfc4),
                               apItem2->pTile->GetString(0xfc4));
    }

    return iresult;
}

// Constructor-only local layout: exe 0x00753230 installs CharGenMenu RTTI vftable 0x01071bb4, not TraitMenu's 0x010779bc.
struct CharGenConstructorBase_traitmenu
{
    unsigned int field_04, field_08, field_0c, field_10, field_14, field_18;
    unsigned int field_1c, field_20, field_24, field_28, field_2c, field_30;
    unsigned int field_34, field_38, field_3c, field_40, field_44;
    CharGenConstructorBase_traitmenu();
    ~CharGenConstructorBase_traitmenu();
    virtual void vf00();
};
// Exe 0x00753230 constructs this CharGenMenu member at +0x58 via 0x00721060.
struct CharGenConstructorMember_traitmenu
{
    CharGenConstructorMember_traitmenu();
    ~CharGenConstructorMember_traitmenu();
};
extern const char str_01071ba0[], str_01071b94[], str_01071b88[];
extern const char str_01071b7c[], str_01071b70[], str_01071b64[];
extern int DAT_011d9210, DAT_011d9214, DAT_011d9224;
extern int DAT_011d9218, DAT_011d921c, DAT_011d9220;
extern float DAT_01012054;
int __cdecl Tile_AddUserTrait(const char*, int);
// Exe 0x00753230 writes +0x48/+0x50/+0x54/+0x55; this separately attributed constructor is not TraitMenu.
struct CharGenConstructor_traitmenu : CharGenConstructorBase_traitmenu
{
    int field_48, field_4c;
    float field_50;
    bool field_54, field_55;
    unsigned short field_56;
    CharGenConstructorMember_traitmenu field_58;
    CharGenConstructor_traitmenu();
};
// @fnv 0x00753230
CharGenConstructor_traitmenu::CharGenConstructor_traitmenu()
{
    DAT_011d9210 = Tile_AddUserTrait(str_01071ba0, -1);
    DAT_011d9214 = Tile_AddUserTrait(str_01071b94, -1);
    DAT_011d9224 = Tile_AddUserTrait(str_01071b88, -1);
    DAT_011d9218 = Tile_AddUserTrait(str_01071b7c, -1);
    DAT_011d921c = Tile_AddUserTrait(str_01071b70, -1);
    DAT_011d9220 = Tile_AddUserTrait(str_01071b64, -1);
    field_48 = 0;
    field_50 = DAT_01012054;
    field_55 = false;
    field_54 = false;
}

extern int DAT_011daf74;
// @fnv 0x007e6910
TraitMenu::~TraitMenu()
{
    DAT_011daf74 = 0;
}

struct MessageTemplate
{
    const char* FUN_00403df0();
};
extern MessageTemplate DAT_011d4558, DAT_011d2c10;
int _sprintf_s(char*, unsigned, const char*, ...);
// Computes lastValue - firstValue, formats it into a message via one of two templates, and passes it to tile38 with a fixed id.
// @fnv 0x007e71b0
void TraitMenu::UpdateValueDifferenceMessage()
{
    char message[64];
    {
        int difference = lastValue - firstValue;
        if (difference == 1)
        {
            _sprintf_s(message, 64, DAT_011d4558.FUN_00403df0(), difference);
            tile38->Tile_Set_00a01350(0xfc4, message, 1);
            tile38->FUN_00700320(0xfa3, 1);
        }
        else
        {
            _sprintf_s(message, 64, DAT_011d2c10.FUN_00403df0(), difference);
            tile38->Tile_Set_00a01350(0xfc4, message, 1);
            tile38->FUN_00700320(0xfa3, 1);
        }
    }
}

struct InputManager
{
    int GetAxisState();
};
extern OSGlobals* DAT_011dea0c;
extern unsigned int DAT_011db004;
bool Interface_Has360Controller();
float NiAbs_00408820(float);
unsigned int gm_GetTickCount();
int Tile_TextToTrait(const char*);

// @fnv 0x007e73f0
bool TraitMenu::HandleKey(int key, int unused)
{
    bool handled = false;
    switch (key)
    {
    case 9:
        if (list.GetHighlightedItem())
        {
            list.GetHighlightedItem()->Tile_PlayTileSound(0xfcb);
            HandleSelection(10, list.GetHighlightedItem());
            handled = true;
        }
        break;
    }
    if (Interface_Has360Controller() && scroll->IsTraitNonZero(0xfa3))
    {
        int delta = 0;
        int step = 0;
        delta = DAT_011dea0c->Main_GetControls(0, 10)->GetAxisState();
        if (NiAbs_00408820((float)delta) <= 8689.0)
            delta = 0;
        if (delta != 0)
            step = delta < 0 ? 1 : -1;
        if (step != 0 && gm_GetTickCount() > DAT_011db004)
        {
            Tile* trait = scroll;
            int iValueId = Tile_TextToTrait("_current_value");
            int tile = (int)trait->FUN_00a011b0(iValueId);
            trait->Tile_Set(iValueId, (float)(tile + step), false);
            if (tile != trait->FUN_00a011b0(iValueId))
            {
                trait->SetTraitFloat(Tile_TextToTrait("_SetInCode"), 1.0f);
            }
            DAT_011db004 = gm_GetTickCount() + (DAT_011db004 ? 50 : 500);
        }
        else if (step == 0)
            DAT_011db004 = 0;
    }
    return handled;
}

extern PlayerCharacter* DAT_011dea3c;
extern int DAT_011daf70;
extern float DAT_01023cd8;
extern float DAT_0101e704;
// @fnv 0x007e7670
// src: GUESS 0x007e7670 (confidence: low)
void Tile_UpdateState_007e7670(Tile* pDest, BGSPerk* pPlayer)
{
    float fValue;
    if (pPlayer->BGSPerk_IsPerkAvailable(DAT_011dea3c) && pPlayer->GetByteAt39() <= DAT_011dea3c->GetLevel())
        fValue = DAT_01023cd8;
    else
        fValue = DAT_0101e704;
    pDest->Tile_Set(DAT_011daf70, fValue, 1);
}

struct EffectList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    EffectNode_traitmenu list;
};
struct PerkEntry
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int GetType();
    EffectList* GetEffects();
};
// BGSPerk.h lacks GetRank(int); retain only this call declaration, with no layout copy.
struct PerkRankList
{
    PerkEntry* GetRank(int);
};

struct EffectChange
{
    int magnitude;
    int unk04;
    int unk08;
    int unk0C;
    EffectChange();
};
struct EffectChangeList
{
    void Clear(bool);
    void Add(EffectChange*);
};
extern EffectChangeList g_011daff0;
extern int DAT_011daf78;
extern int DAT_011daf5c;

// @fnv 0x007e7850
void TraitMenu::UpdateEffectChanges(Tile* tile)
{
    PerkRankList* item7 = list54.FindItemData(tile);
    unsigned char rank4 = (unsigned char)tile->GetFloat(DAT_011daf78);
    PerkEntry* cur = item7->GetRank(rank4);
    PerkEntry* prev6 = rank4 > 1 ? item7->GetRank(rank4 - 1) : 0;
    if (cur && cur->GetType() == 1)
    {
        EffectList* curEffects = cur->GetEffects();
        EffectList* prevEffects = prev6 ? prev6->GetEffects() : 0;
        g_011daff0.Clear(true);
        for (EffectNode_traitmenu* node3 = curEffects ? &curEffects->list : 0; node3 && *node3->GetItem();
             node3 = node3->GetNext())
        {
            EffectChange changeVal;
            int id9 = (*node3->GetItem())->FUN_00403ea0();
            changeVal.magnitude = (*node3->GetItem())->GetMagnitude();
            if (id9 == -1)
                continue;
            for (EffectNode_traitmenu* prevNodeTmp = prevEffects ? &prevEffects->list : 0; prevNodeTmp && *prevNodeTmp->GetItem();
                 prevNodeTmp = prevNodeTmp->GetNext())
            {
                if ((*prevNodeTmp->GetItem())->FUN_00403ea0() == id9)
                    changeVal.magnitude -= (*prevNodeTmp->GetItem())->GetMagnitude();
            }
            if (!tile->IsTraitNonZero(DAT_011daf5c))
                changeVal.magnitude *= -1;
            if ((*node3->GetItem())->GetEffectSetting()->IsDetrimentalToActorValue(id9))
                changeVal.magnitude *= -1;
            g_011daff0.Add(&changeVal);
        }
    }
}

struct ResourceProvider
{
    Tile* CombatController_GetCombatState(const char*);
};
ResourceProvider* __cdecl InterfaceManager_GetSingleton();
TraitMenu* __cdecl Tile_GetMenuByClass(int);
void __cdecl FNV_Warning(const char*);
float __stdcall FUN_00a01530(int);
int __cdecl Tile_TextToTrait(const char*);
extern Setting DAT_011d2f94, DAT_011d351c, DAT_011d2310, DAT_011d33d8, DAT_011d35c4, DAT_011da034;
struct PerkNode
{
    BGSPerk** FUN_006815c0();
    PerkNode* FUN_00726070();
};
struct DataHandlerView
{
    PerkNode* InterfaceManager_GetHUDEffects();
};
extern DataHandlerView* DAT_011c3f2c;
extern int DAT_011daf64, DAT_011daf68;
void __cdecl Tile_UpdateState_007e7670(Tile*, void*);
// Loads trait_menu.xml, builds the trait menu, fills its perk list with eligible perks, sets its labels and counts, and returns the menu tile or 0 on failure.
// @fnv 0x007e6990
// src: XBOX_PDB 0x007e6990
Tile* __cdecl TraitMenu_Create()
{
    TraitMenu* oldMenu = Tile_GetMenuByClass(1084);
    ResourceProvider* root = InterfaceManager_GetSingleton();
    if (oldMenu)
        delete oldMenu;
    Tile* manager = root->CombatController_GetCombatState("Data\\Menus\\trait_menu.xml")->Tile_ReadFile();
    DAT_011daf74 = (int)manager->GetMenu();
    if (DAT_011daf74 && ((TraitMenu*)DAT_011daf74)->GetClass() == TraitMenu_GetMenuID_0())
    {
        ((TraitMenu*)DAT_011daf74)->FUN_00a1dc70((TileMenu*)manager, false);
        if (!((TraitMenu*)DAT_011daf74)->HasAllNineTiles())
        {
            FNV_Warning("MENUS: Trait Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (manager->FUN_00a011b0(4007) == 6006.0 || manager->FUN_00a011b0(4007) == 102.0)
            manager->Tile_Set(4013, FUN_00a01530(1));
        int count = *DAT_011d2f94.Int();
        ((TraitMenu*)DAT_011daf74)->selected = 0;
        ((TraitMenu*)DAT_011daf74)->count = count;
        char text[64];
        if (count == 1)
            _sprintf_s(text, 64, DAT_011d351c.String(), count);
        else
            _sprintf_s(text, 64, DAT_011d2310.String(), count);
        ((TraitMenu*)DAT_011daf74)->tile28->Set(4036, text, true);
        ((TraitMenu*)DAT_011daf74)->tile3c->Set(4036, DAT_011d33d8.String(), true);
        ((TraitMenu*)DAT_011daf74)->tile40->Set(Tile_TextToTrait("_Title"), DAT_011d35c4.String(), true);
        for (PerkNode* node = DAT_011c3f2c->InterfaceManager_GetHUDEffects(); node && *node->FUN_006815c0(); node = node->FUN_00726070())
        {
            BGSPerk* perk = *node->FUN_006815c0();
            if (perk->Level() > 0 && g_thePlayer->GetPerkRank(perk, false) < perk->BGSPerk_GetNumRanks() &&
                perk->GetByteAtOffset56() && perk->IsPerkAttainable(g_thePlayer) && perk->CheckPlayerConditions())
            {
                bool valid = true;
                if (*DAT_011da034.Bool())
                {
                    if (!perk->BGSPerk_IsPerkAvailable(g_thePlayer) || perk->Level() > g_thePlayer->GetLevel())
                        valid = false;
                }
                if (valid)
                    ((TraitMenu*)DAT_011daf74)->perks.AddTail(perk);
            }
        }
        ((TraitMenu*)DAT_011daf74)->PopulatePerkList();
        ((TraitMenu*)DAT_011daf74)->FUN_00726070()->Set(DAT_011daf64, ((TraitMenu*)DAT_011daf74)->selected);
        ((TraitMenu*)DAT_011daf74)->FUN_00726070()->Set(DAT_011daf68, ((TraitMenu*)DAT_011daf74)->count);
        ((TraitMenu*)DAT_011daf74)->UpdateValueDifferenceMessage();
        ((TraitMenu*)DAT_011daf74)->box.Traverse(Tile_UpdateState_007e7670, 0, 0x7fffffff);
        ((TraitMenu*)DAT_011daf74)->box.Sort(Trait_CompareForSorting);
        ((TraitMenu*)DAT_011daf74)->box.UpdateScrollTile(true);
        return manager;
    }
    else
    {
        if (DAT_011daf74 && ((TraitMenu*)DAT_011daf74)->FUN_00726070())
            delete (TraitMenu*)DAT_011daf74;
    }
    return 0;
}

void __cdecl Interface_PlayMenuSound(int);

// For id 10, fills the icon and description tiles from the perk list item, toggles their visibility, and updates the scroll tile's current value.
// @fnv 0x007e6ea0
void TraitMenu::UpdatePerkTile(int id, Tile* tile)
{
    switch (id)
    {
    case 10:
        this->tile30->SetString(0xFCC, this->list54.GetItemForTile(tile)->TESIcon::GetTextureResourceName(), true);
        char buf[0x200];
        this->list54.GetItemForTile(tile)->GetDescription(buf, 0x200);
        this->tile34->SetString(0xFC4, buf, true);
        if (BSStringLength(this->tile30->GetString(0xFCC)) > 1)
        {
            this->tile30->Set(0xFA3, 1);
        }
        else
        {
            this->tile30->Set(0xFA3, 0);
        }
        this->tile34->Set(0xFA3, 1);
        this->tile44->Set(0xFA3, 0);
        Interface_PlayMenuSound(4);
        Tile* scroll2 = this->tile48;
        int traitVal = Tile_TextToTrait("_current_value");
        scroll2->Tile_Set(traitVal, 0.0f, false);
        scroll2->SetTraitFloat(Tile_TextToTrait("_SetInCode"), 1.0f);
        break;
    }
}

extern int DAT_011daf70;
extern int DAT_011daf64;
void __cdecl Interface_PlayMenuSound(int);
void __cdecl TraitMenu_Close();
void __cdecl Tile_ClearTraitAndUpdateEffectChanges(Tile* apTile);

// Handles tile actions by ID: toggles perk selection and refreshes the tile, or resets the selection and traverses the list.
// @fnv 0x007e7280
void TraitMenu::HandleTileAction(int aiTileID, Tile* apTile)
{
    switch (aiTileID)
    {
    case 10:
        if (kList.IsSelected(apTile))
        {
            kList.Deselect(apTile);
            RefreshTile(apTile);
        }
        else if (apTile->GetFloat(DAT_011daf70) == 255.0 && iNumSelected < iMaxSelected)
        {
            kList.Select(apTile);
            RefreshTile(apTile);
        }
        iNumSelected = kList.GetSelectedCount();
        GetTile()->Set(DAT_011daf64, iNumSelected);
        UpdatePerkList();
        break;
    case 6:
        TraitMenu_Close();
        break;
    case 5:
        Interface_PlayMenuSound(1);
        iNumSelected = 0;
        GetTile()->Set(DAT_011daf64, iNumSelected);
        kList.Traverse(Tile_ClearTraitAndUpdateEffectChanges, 0, 0x7fffffff);
        UpdatePerkList();
        break;
    }
}
