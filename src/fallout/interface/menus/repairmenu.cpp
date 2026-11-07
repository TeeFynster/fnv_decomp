// fallout/interface/menus/repairmenu.cpp: RepairMenu and local menu handlers (18 functions)

#include "../../../../include/RepairMenu.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/InventoryMenu.h"
#include "../../../../include/ListBox_ItemChange___.h"
#include "../../../../include/Menu.h"
#include "../../../../include/Tile.h"
// TileListBoxCalls_repairmenu: local type (was include/TileListBoxCalls.h, which had no evidence of one real class); its methods are 0x00a011b0 Tile::GetFloat
#include "../../../../include/Tile.h"

class TileListBoxCalls_repairmenu : public Tile
{
  public:
    float GetFloat(int trait);
};
#include "repairmenu_packet.h"
#include "../../../../include/hkMemoryAllocator.h"
// AudioMgr_BSAudio: this unit's view of BSAudio (0x00453a70 BSAudio::QInstance; 0x00ad73b0 GetSoundHandleByFormID,
// 0x00ad7480 GetSoundHandleByFilename, 0x00ad7550 GetSoundHandleByEditorName, 0x00ad8570 per the community PDB). It
// returns this unit's own sound-handle copy, so it stays local until that copy moves onto BSSoundHandle.
class AudioPlaybackHandle;
class Snd;
class SndForm;
class SndSrc;
class AudioMgr_BSAudio
{
public:
    static AudioMgr_BSAudio* Get();
    AudioPlaybackHandle Make(int id, SndForm* form);
    AudioPlaybackHandle Make2(int id);
    bool PlayAt(void* node, float f, int flags);
    AudioPlaybackHandle GetHandle(const char* name, int flags, int a);
    AudioPlaybackHandle GetSoundByEditorID(const char* editorID, int flags, int a);
    AudioPlaybackHandle GetSoundByEditorID(const char* editorID, int flags);
    Snd Make(void* a, SndSrc* b);
};
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/Setting.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/TESObjectWEAP.h"
static const int kGetClassValue = 1035;
// @fnv 0x007b54b0
int RepairMenu::GetClass()
{
    return kGetClassValue;
}
// Applies the accumulated movement offset at 0x274 to the menu's X/Y tile values and resets it to zero.
// @fnv 0x0077f700
void RepairMenu::UpdateRepairList()
{
    static float baseX = ((TileListBoxCalls_repairmenu*)pMenu)->GetFloat(4001);
    static float baseY = ((TileListBoxCalls_repairmenu*)pMenu)->GetFloat(4002);
    float x = 0.0f;
    float y = 0.0f;
    if (reinterpret_cast<float*>(this)[0x274 / sizeof(float)] > 0.0)
    {
        DAT_011d9e91 = true;
        NiSinCos_004169a0(RandomFloatTwoPi(), x, y);
        x *= reinterpret_cast<float*>(this)[0x274 / sizeof(float)];
        y *= reinterpret_cast<float*>(this)[0x274 / sizeof(float)];
    }
    if (DAT_011d9e91)
    {
        ((Tile*)pMenu)->Set(4001, baseX + x, true);
        ((Tile*)pMenu)->Set(4002, baseY + y, true);
    }
    if (reinterpret_cast<float*>(this)[0x274 / sizeof(float)] == 0.0)
        DAT_011d9e91 = false;
    reinterpret_cast<float*>(this)[0x274 / sizeof(float)] = 0.0f;
}
// Loads repair_menu.xml, stores the resulting RepairMenu, initializes its list and tiles, and returns the tile or null on failure.
// @fnv 0x007b5520
Tile* RepairMenu::Create()
{
    Menu* pExistingMenu;
    Tile* pTile;
    InterfaceManager* pInterface;
    pInterface = InterfaceManager_GetSingleton();
    pExistingMenu = Tile::FindMenuById(RepairMenu_GetClassStatic());
    if (pExistingMenu)
        delete pExistingMenu;
    pTile = pInterface->CombatController_GetCombatState()->ReadFile("Data\\Menus\\repair_menu.xml");
    DAT_011da75c = (RepairMenu*)pTile->GetMenu();
    if (DAT_011da75c && DAT_011da75c->GetClass() == RepairMenu_GetClassStatic())
    {
        DAT_011da75c->SetTileMenu((TileMenu*)pTile, false);
        ((InventoryMenu*)DAT_011da75c)->Menu_SetRenderedMenu();
        if (!DAT_011da75c->IsWellFormedMenu_007b5730())
        {
            Warning("MENUS: Repair Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (((TileListBoxCalls_repairmenu*)pTile)->GetFloat(4007) == 6006.0 || ((TileListBoxCalls_repairmenu*)pTile)->GetFloat(4007) == 102.0)
            pTile->Set(4013, Tile::GetInterfaceScale(), true);
        DAT_011da75c->m_kItemList.Initialize(DAT_011da75c->m_pTiles[1], "RM_RepairListTemplate");
        DAT_011da75c->m_kItemList.FUN_007a1930(false);
        DAT_011da75c->m_pTiles[5]->SetTraitFloat(DAT_011da754, 1.0f);
        DAT_011da75c->m_pTiles[10]->SetTraitFloat(DAT_011da754, 1.0f);
        DAT_011da75c->SetMenuVisibility(true);
        return pTile;
    }
    else
    {
        if (DAT_011da75c && ((BSSimpleList<BGSPerkEntry*>*)DAT_011da75c)->GetNext())
            delete DAT_011da75c;
    }
    return 0;
}

// Checks the 13 entries at offset 0x28 and returns true only if none of them is zero.
// @fnv 0x007b5730
// src: XBOX_PDB 0x007b5730
bool RepairMenu::IsWellFormedMenu_007b5730()
{
    for (int iIndex = 0; iIndex < 13; ++iIndex)
    {
        if (((int*)((char*)this + 0x28))[iIndex] == 0)
            return false;
    }
    return true;
}

// @fnv 0x007b5720
// src: XBOX_PDB 0x007b5720
int RepairMenu_GetClassStatic()
{
    return 0x40b;
}

struct Box071ae60
{
    unsigned int ListBox_ItemChange_NumUnfiltered();
};
// Retained: RepairMenu.h does not declare this handler (0x007b6a00).
struct Standin007b6a00
{
    char _00[0x48];
    Tile* _48;
    Tile* _4c;
    char _50[0x0C];
    Box071ae60 _5c;
    void RepairMenu_DoLeave(int aiID, Tile* apTarget);
};
// For ID 14, clears tile 0xFA3 on _4c and, when _5c.FUN_0071ae60() returns more than 1, also clears it on _48.
// @fnv 0x007b6a00
// src: XBOX_PDB 0x007b6a00
void Standin007b6a00::RepairMenu_DoLeave(int aiID, Tile* apTarget)
{
    if (aiID == 14)
    {
        _4c->Set(0xFA3, 0);
        if (_5c.ListBox_ItemChange_NumUnfiltered() > 1)
        {
            _48->Set(0xFA3, 0);
        }
    }
}

void __cdecl PlayUISound(int);
// Retained: RepairMenu.h does not declare the HandleMenuInput override.
struct FUN_007b6a50_Host
{
    virtual void Vf0() = 0;
    virtual void Vf1() = 0;
    virtual void Vf2() = 0;
    virtual void Vf3(int, int) = 0;
    bool HandleButton(int aiButton, float afValue);
};
// @fnv 0x007b6a50
bool FUN_007b6a50_Host::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 6:
    case 10:
        PlayUISound(3);
        this->Vf3(12, 0);
        break;
    }
    return bhandled;
}

// Removes the tile with id 0xfa9 and clears DAT_011da75c.
// @fnv 0x007b5770
RepairMenu::~RepairMenu()
{
    m_pTiles[8]->UpdateTrait(0xfa9);
    DAT_011da75c = 0;
}

struct HealthOwner
{
    float GetHealthPercent(bool abAdjusted);
    bool IsEquipped(bool abCheck);
};

struct ChildTile;
struct ChildTileList
{
    void* GetHeadPos() const;
    ChildTile*& GetAtPos(void* apPos) const;
};

struct ChildTile
{
    void SetInt(int aiID, int aiValue);
};

struct RepairTile
{
    int unk00;
    ChildTileList children;
    void SetInt(int aiID, int aiValue);
    float GetValueFloat(int aiID);
    RepairTile* GetChildById(int aiID);
    void SetFloat(int aiID, float afValue, bool abPropagate);
};

struct SkillOwner
{
    void* GetSkill(int aiActorValue);
};

struct PlayerStub
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
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
    SkillOwner skills;
};

float ComputeRepairAmount(void* apSkill, float afSourceHealth, float afTargetHealth, int* apOut);
float BSMIN(float a, float b);

extern HealthOwner* DAT_011da760;
extern PlayerStub* g_thePlayer;

// @fnv 0x007b57f0
void UpdateRepairTile(RepairTile* apTile, HealthOwner* apItem)
{
    if (!apTile || !apItem)
        return;

    float fHealthPercent = apItem->GetHealthPercent(true);
    apTile->SetInt(0xfaa, 0xe);
    apTile->SetInt(0xfa3, apTile->GetValueFloat(0xfac) >= 0.0);
    apTile->GetChildById(0xf)->SetFloat(0xfb1, fHealthPercent * 0.6f, true);
    if (apItem->IsEquipped(false))
        apTile->children.GetAtPos(apTile->children.GetHeadPos())->SetInt(0xfa3, 1);

    float fRepairHealth = DAT_011da760->GetHealthPercent(true);
    float fResult = 0.0f;
    int iOut = -1;
    fResult = ComputeRepairAmount(g_thePlayer->skills.GetSkill(0x27), fRepairHealth, fHealthPercent, &iOut) / 100.0;
    fResult = BSMIN(fResult, 1.0f);
    apTile->SetFloat(0x1004, fResult, true);
}

// @fnv 0x007b6970
void RepairMenu::SetRepairMenuText(const char* apText)
{
    m_pTiles[8]->SetString(4036, apText, true);
    m_pTiles[9]->Set(4003, 0);
    m_pTiles[8]->Set(4003, 1);
    if (!m_pTiles[8]->Tile_HasFadeControl(4009))
    {
        m_pTiles[8]->StartFade(4009, 255.0f, 64.0f, 2.0f, true);
    }
}

namespace fnv_007b6fb0 {
extern RepairMenu* DAT_011da75c;
extern int DAT_011da760;

class RmSub
{
  public:
    virtual ~RmSub();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
};

class RmTile
{
  public:
    void CallA(int);
    void CallB(int, int);
};

// @fnv 0x007b6fb0
void ResetRepairMenu()
{
    reinterpret_cast<RmSub*>(&DAT_011da75c->m_kItemList)->vf1c();
    DAT_011da760 = 0;
    DAT_011da75c->HandleMouseoverTileAlt(0xe, 0);
    reinterpret_cast<RmTile*>(DAT_011da75c->m_pTiles[8])->CallA(0xfa9);
    reinterpret_cast<RmTile*>(DAT_011da75c->m_pTiles[8])->CallB(0xfa3, 0);
}
}  // namespace fnv_007b6fb0

namespace fnv_007b7020 {
struct RepairInventory
{
    float ItemChange_GetItemHealth(int mode);
    struct RepairForm* FUN_0044ddc0();
    int GetIconFilename(int mode, int active);
};
struct RepairForm
{
    int FUN_00401170();
    float TESObjectARMO_GetArmorRating();
    float TESObjectARMO_GetDamageThreshold();
};
struct RepairTile
{
    void Tile_Set(int id, float value, int flag);
    void FUN_00700320(int id, int value);
    void Tile_Set_00a01350(int id, const char* text);
    void Tile_Set_00a01350(int id, const char* text, int flag);
    void Tile_Set_00a01350(int id, int value);
};
struct RepairString
{
    const char* FUN_00403df0(int);
};
struct RepairList
{
    virtual void vf00();
    virtual int vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual int vf14(int, int, int, int);
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20(void(__cdecl*)());
    void ListBox_ItemChange_Traverse(void(__cdecl*)(), int, int);
};
struct RepairHud
{
    int FUN_0066ef20(int);
};
struct RepairManager
{
    void InterfaceManager_SetCurrentFocusTarget();
    void InterfaceManager_TutorialManager_ShowMessage();
};
extern RepairInventory* DAT_011da760;
extern int DAT_011da74c;
extern RepairString DAT_011d2c7c;
extern RepairString DAT_011d396c;
extern RepairString DAT_011d20c4;
extern RepairHud* DAT_011dea3c;
extern const double DAT_01017a40;
extern const double DAT_01012060;
extern const char DAT_01047008[];
extern float __cdecl GetWeaponDamage(RepairForm*, float, int, int);
extern float __cdecl FUN_004bd510(float, float);
extern float __cdecl FUN_00646360(int, float);
extern void __cdecl FUN_00406d30(char*, int, const char*);
extern void __cdecl UpdateRepairTile();
extern void __cdecl CompareSortEntries();
extern void __cdecl PopulateRepairMenu();
extern bool __cdecl InterfaceManager_Has360Controller();
extern void __cdecl Interface_SetRepairMenuVisible(int, int, int);
extern InterfaceManager* __stdcall InterfaceManager_GetSingleton(int);
extern InterfaceManager* __stdcall InterfaceManager_GetSingleton(int, int);
extern int __stdcall RepairMenu_GetClassStatic(int);

// @fnv 0x007b7020
// src: XBOX_PDB 0x007b7020
void __cdecl RepairMenu_InitRepairMenu(int target)
{
    if (DAT_011da75c != 0)
    {
        if (target != 0)
        {
            DAT_011da760 = reinterpret_cast<RepairInventory*>(target);
        }
        float percent = DAT_011da760->ItemChange_GetItemHealth(1) / DAT_01017a40;
        reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[4])->Tile_Set(0x1004, percent, 1);
        reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[4])->FUN_00700320(0xfa3, 1);
        RepairForm* form = DAT_011da760->FUN_0044ddc0();
        int type = form->FUN_00401170();
        if (type == 0x28)
        {
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                ->Tile_Set_00a01350(DAT_011da74c, DAT_011d2c7c.FUN_00403df0(1));
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                ->FUN_00700320(DAT_011da754, (int)FUN_004bd510(GetWeaponDamage(form, percent, target, 0), 1.0f));
        }
        else if (type == 0x18)
        {
            RepairForm* branchForm = form;
            float low = FUN_00646360((int)branchForm->TESObjectARMO_GetArmorRating(), percent);
            float maximum = FUN_00646360((int)branchForm->TESObjectARMO_GetDamageThreshold(), percent);
            if (maximum > DAT_01012060)
            {
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                    ->Tile_Set_00a01350(DAT_011da74c, DAT_011d396c.FUN_00403df0(1));
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])->FUN_00700320(DAT_011da754, (int)maximum);
            }
            else if (low > DAT_01012060)
            {
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                    ->Tile_Set_00a01350(DAT_011da74c, DAT_011d20c4.FUN_00403df0(1));
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])->FUN_00700320(DAT_011da754, (int)low);
            }
            else
            {
                char unavailableText[128];
                FUN_00406d30(unavailableText, 128, DAT_01047008);
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                    ->Tile_Set_00a01350(DAT_011da74c, DAT_011d20c4.FUN_00403df0(1));
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                    ->Tile_Set_00a01350(DAT_011da754, unavailableText, 1);
            }
        }
        else
        {
            char unavailableText[128];
            FUN_00406d30(unavailableText, 128, DAT_01047008);
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                ->Tile_Set_00a01350(DAT_011da74c, DAT_011d20c4.FUN_00403df0(1));
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])->Tile_Set_00a01350(DAT_011da754, unavailableText, 1);
        }

        if (target != 0)
        {
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[3])
                ->Tile_Set_00a01350(0xfcc, DAT_011da760->GetIconFilename(0, 1));
            PopulateRepairMenu();
        }
        reinterpret_cast<RepairList*>(&DAT_011da75c->m_kItemList)->ListBox_ItemChange_Traverse(&UpdateRepairTile, 0, 0x7fffffff);
        reinterpret_cast<RepairList*>(&DAT_011da75c->m_kItemList)->vf20(&CompareSortEntries);
        reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[0])
            ->FUN_00700320(
                DAT_011da754,
                reinterpret_cast<RepairHud*>(reinterpret_cast<char*>(DAT_011dea3c) + 0xa4)->FUN_0066ef20(0x27));
        if (target && InterfaceManager_Has360Controller())
        {
            reinterpret_cast<RepairManager*>(
                InterfaceManager_GetSingleton(reinterpret_cast<RepairList*>(&DAT_011da75c->m_kItemList)->vf14(1, 0, 0xfc3, 1)))
                ->InterfaceManager_SetCurrentFocusTarget();
        }
        DAT_011da75c
            ->HandleMouseover(0xe, reinterpret_cast<Tile*>(reinterpret_cast<RepairList*>(&DAT_011da75c->m_kItemList)->vf04()));
        if (target != 0)
        {
            Interface_SetRepairMenuVisible(1, 0, 0);
            reinterpret_cast<RepairManager*>(reinterpret_cast<char*>(InterfaceManager_GetSingleton(6, RepairMenu_GetClassStatic(500))) + 0x4d4)
                ->InterfaceManager_TutorialManager_ShowMessage();
        }
    }
}
}  // namespace fnv_007b7020

struct ValueObj_7b
{
    float GetValue();
};
struct ValueList_7b
{
    ValueObj_7b** Find(int aiID);
};
struct FUN_004bddd0_shell
{
    float GetHealth(bool abFlag);
    bool ItemChange_GetWorn(bool abFlag);
};
struct SortEntry_7b
{
    Tile* pItem;
    FUN_004bddd0_shell* pData;
};

extern int DAT_011da748;

// Compares two sort entries by a flag, a list value against 255, health, and a secondary predicate, returning -1, 0 or 1.
// @fnv 0x007b5950
int CompareSortEntries(SortEntry_7b* apA, SortEntry_7b* apB)
{
    int iResult = 0;
    bool bHasA6 = apA->pItem->IsTraitNonZero(DAT_011da748);
    bool bHasB = apB->pItem->IsTraitNonZero(DAT_011da748);
    bool bLowA = (*((ValueList_7b*)((char*)apA->pItem + 4))->Find(0xfa9))->GetValue() < 255.0;
    bool bLowB4 = (*((ValueList_7b*)((char*)apB->pItem + 4))->Find(0xfa9))->GetValue() < 255.0;
    if (bHasA6 && !bHasB)
    {
        iResult = -1;
    }
    else if (!bHasA6 && bHasB)
    {
        iResult = 1;
    }
    else if (bLowA && !bLowB4)
    {
        iResult = 1;
    }
    else if (!bLowA && bLowB4)
    {
        iResult = -1;
    }
    else
    {
        iResult = (apA->pData->GetHealth(true) < apB->pData->GetHealth(true))
                      ? 1
                      : ((apA->pData->GetHealth(true) > apB->pData->GetHealth(true)) ? -1 : 0);
        if (bLowA && bLowB4)
        {
            iResult = -iResult;
        }
        if (iResult == 0)
        {
            if (apA->pData->ItemChange_GetWorn(false))
            {
                iResult = -1;
            }
            else if (apB->pData->ItemChange_GetWorn(false))
            {
                iResult = 1;
            }
        }
    }
    return iResult;
}

struct FloatValue
{
    float Read();
};
struct Values
{
    FloatValue** Find(int);
};
struct ClickTile
{
    int unk00;
    Values values;
    bool Enabled(int);
};
struct FormStub
{
    int* GetBase();
};
struct ItemStub
{
    FormStub* GetForm();
    int GetObject();
    bool Equipped(bool);
};
struct RepairList
{
    virtual void vf0();
    virtual int SelectedIndex();
    ItemStub* Selected();
    void Remove(int);
    unsigned int Count();
};
struct AudioPlaybackHandle
{
    int unk00, unk04, unk08;
    ~AudioPlaybackHandle();
    void Play();
};
AudioMgr_BSAudio* GetAudio();
// The player singleton at 0x011dea3c uses RemoveItem (slot 0x5f) and Update (slot 0xf1).
extern PlayerCharacter* DAT_011dea3c;
void UpdateRepair(int);
void UpdateEquip();
void PlayMenu(int);
void CloseMenu(int, int, int);
// Retained: the shared HandleRepairAction symbol is bound to 0x007b7d80, not this handler.
struct FUN_007b5b40_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Click(int, ClickTile*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    ClickTile* tiles[13];
    RepairList list;
    void DoRepair(ItemStub*);
    void HandleRepairMenuAction(int id, ClickTile* target);
};
// @fnv 0x007b5b40
void FUN_007b5b40_cls::HandleRepairMenuAction(int aiActionId, ClickTile* apTargetTile)
{
    bool unused4 = false;
    if (!apTargetTile && aiActionId >= 0 && aiActionId < 13)
        apTargetTile = tiles[aiActionId];
    switch (aiActionId)
    {
    case 14:
        if ((*apTargetTile->values.Find(0xfa9))->Read() < 255.0)
        {
        }
        else
        {
            if (list.Selected() != (ItemStub*)DAT_011da760 && tiles[9]->Enabled(0xfa3))
            {
                ItemStub* item5 = list.Selected();
                int base = item5->GetForm() ? *item5->GetForm()->GetBase() : 0;
                DoRepair(item5);
                DAT_011dea3c->RemoveItem(reinterpret_cast<TESForm*>(item5->GetObject()), reinterpret_cast<ExtraDataList*>(base), 1, 0, 0, 0, 0, 0, 1, 0);
                GetAudio()->GetSoundByEditorID("UIRepairWeapon", 0x121, 0).Play();
                list.Remove(list.SelectedIndex());
                if (list.Count() == 1 || DAT_011da760->GetHealthPercent(true) >= 99.0)
                    Click(12, 0);
                else
                    UpdateRepair(0);
                if (item5->Equipped(false))
                {
                    DAT_011dea3c->Update();
                    UpdateEquip();
                }
            }
        }
        break;
    case 12:
        PlayMenu(0x24);
        CloseMenu(1, 0, 0);
        break;
    }
}

// ExtraDataList exposes its deleting-destructor slot as BaseExtraList::vf00.
// Use the destructor ABI for deletion without redeclaring its shared layout.
struct RepairExtraDeletion
{
    virtual ~RepairExtraDeletion();
};
struct RepairExtraNode
{
    ExtraDataList*& FUN_006815c0();
    RepairExtraNode* FUN_00726070();
    void FUN_0063f7b0();
    void FUN_005ae3d0(ExtraDataList*&);
    void RemoveMatchingItem(ExtraDataList*&);
};
struct RepairInventoryItem : HealthOwner
{
    TESBoundObject* FUN_0044ddc0();
    bool HasEffect(int);
    RepairExtraNode* Modelloader_GetReferencedThis();
};
struct RepairInventoryChanges
{
    RepairInventoryItem* FUN_004bfba0(TESBoundObject*, bool, bool);
};
RepairInventoryChanges* __cdecl FUN_004bf220(PlayerStub*);
unsigned int __cdecl FUN_004873d0(TESBoundObject*);
void __cdecl FUN_004d5c60(int);
// Computes a repair amount from skill and health, applies it to the item's extra data, and merges the repaired entry into the inventory changes list.
// @fnv 0x007b5d80
void RepairMenu::ApplyRepair(void* source)
{
    float repairVal = 0.0f;
    repairVal = ComputeRepairAmount(g_thePlayer->skills.GetSkill(39), DAT_011da760->GetHealthPercent(true),
                                    static_cast<HealthOwner*>(source)->GetHealthPercent(true), 0) /
                100.0;
    repairVal = BSMIN(repairVal, 1.0f);
    TESObjectWEAP* bound = dynamic_cast<TESObjectWEAP*>(((RepairInventoryItem*)DAT_011da760)->FUN_0044ddc0());
    if (bound)
        repairVal *= bound->GetModdedValue(((RepairInventoryItem*)DAT_011da760)->HasEffect(10));
    else
        repairVal *= FUN_004873d0(((RepairInventoryItem*)DAT_011da760)->FUN_0044ddc0());
    RepairInventoryItem* entryTmp =
        FUN_004bf220(g_thePlayer)->FUN_004bfba0(((RepairInventoryItem*)DAT_011da760)->FUN_0044ddc0(), true, false);
    ExtraDataList* extra7 = ((RepairInventoryItem*)DAT_011da760)->Modelloader_GetReferencedThis()
                                ? ((RepairInventoryItem*)DAT_011da760)->Modelloader_GetReferencedThis()->FUN_006815c0()
                                : 0;
    ExtraDataList* repairA = new ExtraDataList;
    int count = -1;
    bool found9 = false;
    count = extra7->ExtraDataList_GetCount();
    repairA->ExtraDataList_DuplicateExtraListForContainer(extra7);
    repairA->ExtraDataList_SetCount(1);
    repairA->SetExtraHealth(repairVal);
    FUN_004d5c60(34);
    ((RepairInventoryItem*)DAT_011da760)->Modelloader_GetReferencedThis()->FUN_0063f7b0();
    if (count > 1)
        extra7->ExtraDataList_SetCount(count - 1);
    for (RepairExtraNode* node = entryTmp->Modelloader_GetReferencedThis(); node && node->FUN_006815c0(); node = node->FUN_00726070())
    {
        if (!node->FUN_006815c0()->ExtraDataList_CompareListForContainer(repairA, true, false) &&
            !repairA->ExtraDataList_CompareListForContainer(node->FUN_006815c0(), true, false))
        {
            node->FUN_006815c0()->ExtraDataList_SetCount(node->FUN_006815c0()->ExtraDataList_GetCount() + 1);
            ((RepairInventoryItem*)DAT_011da760)->Modelloader_GetReferencedThis()->FUN_005ae3d0(node->FUN_006815c0());
            found9 = true;
        }
    }
    if (!found9)
    {
        if (count > 1)
        {
            entryTmp->Modelloader_GetReferencedThis()->FUN_005ae3d0(repairA);
            ((RepairInventoryItem*)DAT_011da760)->Modelloader_GetReferencedThis()->FUN_005ae3d0(repairA);
        }
        else
        {
            extra7->SetExtraHealth(repairVal);
            ((RepairInventoryItem*)DAT_011da760)->Modelloader_GetReferencedThis()->FUN_005ae3d0(extra7);
        }
    }
    else if (count == 1)
    {
        entryTmp->Modelloader_GetReferencedThis()->RemoveMatchingItem(extra7);
    }
    if (found9 || count == 1)
    {
        repairA->ExtraDataList_SetScriptLocals((void*)0);
        delete reinterpret_cast<RepairExtraDeletion*>(repairA);
    }
}

struct PreviewForm
{
    int Type();
    float Armor();
    float Threshold();
};
struct PreviewItem
{
    PreviewForm* Form();
    float Health(bool);
};
struct PreviewTile
{
    float Value(int);
    void SetFloat(int, float, bool);
    void SetString(int, const char*, bool);
    void SetInt(int, int);
};
struct PreviewList
{
    virtual void v0();
    virtual PreviewTile* GetTile();
    PreviewItem* Selected();
    unsigned int Count();
};
struct PreviewSetting
{
    float* Float();
    const char* String();
};
struct PreviewPipboy
{
    void Rotate(int, float, float, bool);
};
struct PreviewInterface
{
    PreviewPipboy* Pipboy();
};
PreviewInterface* GetPreviewInterface();
extern PreviewSetting g_011db2f0, g_011db358, g_011d3dcc, g_011d1f2c, g_011d270c, g_011d018c, g_011d4ee8, g_011d2b20,
    g_011d2c7c, g_011d396c, g_011d20c4;
extern int DAT_011da7d8, DAT_011da74c;
extern HealthOwner* DAT_011da760;
int TraitID(const char*);
int FormatPreview(char*, unsigned int, const char*, ...);
int CopyPreview(char*, unsigned int, const char*);
int AppendPreview(char*, unsigned int, const char*);
float WeaponValue(PreviewForm*, float, PreviewItem*, int);
float AdjustWeapon(float, float);
double ArmorValue(int, float);
float MaxPreview(float, float);
// Retained: RepairMenu.h does not declare UpdatePreviewComparison.
struct PreviewMenu
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
    PreviewTile* tile38;
    PreviewTile* tile3c;
    PreviewTile* tile40;
    PreviewTile* tile44;
    PreviewTile* tile48;
    PreviewTile* tile4c;
    PreviewTile* tile50;
    PreviewTile* tile54;
    int unk58;
    PreviewList list;
    void Error(const char*);
    void UpdatePreviewComparison(int, PreviewTile*);
};

// @fnv 0x007b6120
void PreviewMenu::UpdatePreviewComparison(int event, PreviewTile* target)
{
    char text[64];
    switch (event)
    {
    case 14: {
        PreviewItem* item7 = list.Selected();
        int selection7 = item7 ? (int)list.GetTile()->Value(0xfac) : 0;
        if (DAT_011da7d8 != selection7)
        {
            GetPreviewInterface()->Pipboy()->Rotate(
                0, DAT_011da7d8 < selection7 ? *g_011db2f0.Float() : -*g_011db2f0.Float(), *g_011db358.Float(), true);
            DAT_011da7d8 = selection7;
        }
        if (item7 && DAT_011da760)
        {
            float limitX = 75.0f;
            if (item7->Form()->Type() == 24)
                limitX = 50.0f;
            if (limitX <= item7->Health(true))
                ((PreviewMenu*)DAT_011da75c)->tile54->SetString(0xfc4, g_011d3dcc.String(), true);
            else
                ((PreviewMenu*)DAT_011da75c)->tile54->SetString(0xfc4, g_011d1f2c.String(), true);
            if (item7 == (PreviewItem*)DAT_011da760)
            {
                if (list.Count() > 1)
                    Error(g_011d270c.String());
                tile54->SetFloat(TraitID("_line_alpha"), 128.0f, true);
            }
            else
            {
                float health4 = target->Value(0x1004);
                int cost4 = (int)target->Value(0x1005);
                if (cost4 > 100)
                {
                    FormatPreview(text, 64, g_011d4ee8.String(), *g_011d018c.Float() * 10.0, "%");
                    Error(text);
                    tile54->SetFloat(TraitID("_line_alpha"), 128.0f, true);
                }
                else if (cost4 > 0)
                {
                    FormatPreview(text, 64, g_011d2b20.String(), cost4, "%");
                    Error(text);
                    tile54->SetFloat(TraitID("_line_alpha"), 128.0f, true);
                }
                else
                {
                    tile54->SetFloat(TraitID("_line_alpha"), 255.0f, true);
                    tile4c->SetFloat(0x1004, health4, true);
                    tile4c->SetInt(0xfa3, 1);
                    tile48->SetInt(0xfa3, 0);
                    if (((PreviewItem*)DAT_011da760)->Form()->Type() == 40)
                    {
                        tile50->SetString(DAT_011da74c, g_011d2c7c.String(), true);
                        tile50->SetInt(DAT_011da754,
                                       (int)AdjustWeapon(WeaponValue(((PreviewItem*)DAT_011da760)->Form(), health4,
                                                                     (PreviewItem*)DAT_011da760, 0),
                                                         1.0f));
                    }
                    else if (item7->Form()->Type() == 24)
                    {
                        char empty[128];
                        {
                            PreviewForm* armor = ((PreviewItem*)DAT_011da760)->Form();
                            float oldhealth5 = ((PreviewItem*)DAT_011da760)->Health(true) / 100.0;
                            float oldarmor = ArmorValue((int)armor->Armor(), oldhealth5);
                            float oldthreshold3 = ArmorValue((int)armor->Threshold(), oldhealth5);
                            float newarmor3 = ArmorValue((int)armor->Armor(), health4);
                            float newthreshold2 = ArmorValue((int)armor->Threshold(), health4);
                            CopyPreview(empty, 128, "--");
                            if (newthreshold2 > 0.0)
                            {
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile3c->SetString(DAT_011da74c, g_011d396c.String(), true);
                                if (oldthreshold3 > 0.0)
                                    ((PreviewMenu*)DAT_011da75c)->tile3c->SetInt(DAT_011da754, (int)oldthreshold3);
                                else
                                    ((PreviewMenu*)DAT_011da75c)->tile3c->SetString(DAT_011da754, empty, true);
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile50->SetString(DAT_011da74c, g_011d396c.String(), true);
                                ((PreviewMenu*)DAT_011da75c)->tile50->SetInt(DAT_011da754, (int)newthreshold2);
                            }
                            else if (newarmor3 > 0.0)
                            {
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile3c->SetString(DAT_011da74c, g_011d20c4.String(), true);
                                if (oldarmor > 0.0)
                                    ((PreviewMenu*)DAT_011da75c)->tile3c->SetInt(DAT_011da754, (int)oldarmor);
                                else
                                    ((PreviewMenu*)DAT_011da75c)->tile3c->SetString(DAT_011da754, empty, true);
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile50->SetString(DAT_011da74c, g_011d20c4.String(), true);
                                ((PreviewMenu*)DAT_011da75c)->tile50->SetInt(DAT_011da754, (int)newarmor3);
                            }
                            else
                            {
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile3c->SetString(DAT_011da74c, g_011d20c4.String(), true);
                                ((PreviewMenu*)DAT_011da75c)->tile3c->SetString(DAT_011da754, empty, true);
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile50->SetString(DAT_011da74c, g_011d20c4.String(), true);
                                ((PreviewMenu*)DAT_011da75c)->tile50->SetString(DAT_011da754, empty, true);
                            }
                        }
                    }
                    float healthdiff8 = (tile4c->Value(0x1004) - tile38->Value(0x1004)) * 100.0;
                    float statdiff9 = tile50->Value(DAT_011da754) - tile3c->Value(DAT_011da754);
                    healthdiff8 = MaxPreview(0.0f, healthdiff8);
                    statdiff9 = MaxPreview(0.0f, statdiff9);
                    FormatPreview(text, 64, "+%i", (int)(healthdiff8 + 0.5));
                    AppendPreview(text, 64, "%");
                    tile40->SetString(0xfc4, text, true);
                    FormatPreview(text, 64, "+%i", (int)(statdiff9 + 0.5));
                    tile44->SetString(0xfc4, text, true);
                }
            }
        }
        break;
    }
    }
}

namespace fnv_007b6aa0 {
struct Extra
{
    bool Check();
};
struct Item;
struct ExtraNode
{
    Extra*& Head();
    ExtraNode* Next();
};
struct Item
{
    int unk00;
    int unk04;
    int unk08;
    Item(void*, int);
    void* Form();
    int Count();
    float Health(bool);
    ExtraNode* Extras();
    const char* Name();
    bool Equipped(bool);
};
struct ItemNode
{
    Item* data;
    ItemNode* next;
    ItemNode();
    ~ItemNode();
    Item*& Head();
    ItemNode* Next();
};
struct Changes
{
    static Changes* GetOrAddInventoryChanges(void*);
    void Collect(void*, ItemNode*);
};
struct Value
{
    void Clear();
    void Link(int, void*, int);
    void SetNumber(int, float);
    void Finish(int);
};
struct UITile
{
    void SetInt(int, int);
    Value* GetValue(int);
    UITile* Child(const char*);
    void SetString(int, const char*, bool);
};
struct Box
{
    UITile* Add(Item*, const char*, int, int);
    void Remove(UITile*);
};
extern Setting gSystemLocaleState;
extern Setting g_011d4378, g_011d4030, g_011d4da4, g_011d1f2c, g_011d29f4;
extern Item* selectedItem;
extern RepairMenu* repairView;
extern void* playerObject;
extern int DAT_011da748, DAT_011da74c;
float RoundHealth(float);
int CompareText(const char*, const char*);
void* operator new(unsigned int);
struct ExtraList
{
    void AddHead(Extra*&);
};
// @fnv 0x007b6aa0
void __cdecl PopulateRepairMenu()
{
    if (!selectedItem)
        return;
    ItemNode selectedExtra;
    {
        Changes* c;
        c = Changes::GetOrAddInventoryChanges(playerObject);
        c->Collect(selectedItem->Form(), &selectedExtra);
    }
    for (ItemNode* node = &selectedExtra; node && node->Head(); node = node->Next())
    {
        UITile* n;
        n = 0;
        Item* item;
        item = 0;
        for (int index = 0; index < node->Head()->Count(); ++index)
        {
            float rawHealth;
            float extra;
            rawHealth = node->Head()->Health(true);
            extra = RoundHealth(rawHealth);
            bool tmp;
            tmp = false;
            Extra* special;
            special = node->Head()->Extras() ? node->Head()->Extras()->Head() : 0;
            if (special && special->Check())
                tmp = true;
            if (extra < 100.0 || node->Head()->Form() != selectedItem->Form())
            {
                if (!index)
                {
                    item = node->Head();
                    n = reinterpret_cast<Box*>(&repairView->m_kItemList)->Add(item, item->Name(), 0, 0);
                    if (n && item->Form() == selectedItem->Form())
                    {
                        Extra* x;
                        x = item->Extras() ? item->Extras()->Head() : 0;
                        Extra* list;
                        list = selectedItem->Extras() ? selectedItem->Extras()->Head() : 0;
                        if (x == list)
                        {
                            selectedItem = item;
                            n->SetInt(DAT_011da748, 1);
                            Value* healthValue;
                            healthValue = reinterpret_cast<UITile*>(repairView->m_pTiles[2])->GetValue(0xfb0);
                            Value* p;
                            p = reinterpret_cast<UITile*>(repairView->m_pTiles[2])->GetValue(0xfa2);
                            healthValue->Clear();
                            healthValue->Link(0x7d0, n, 0xfb0);
                            healthValue->SetNumber(0x7d2, 1.0f);
                            healthValue->Finish(0);
                            p->Clear();
                            p->Link(0x7d0, n, 0xfa2);
                            p->Finish(0);
                        }
                        else if (tmp || item->Equipped(false))
                            reinterpret_cast<Box*>(&repairView->m_kItemList)->Remove(n);
                    }
                }
                else
                {
                    item = new Item(node->Head()->Form(), 1);
                    for (ExtraNode* extraNode = node->Head()->Extras(); extraNode && extraNode->Head();
                         extraNode = extraNode->Next())
                        ((ExtraList*)item->Extras())->AddHead(extraNode->Head());
                    n = reinterpret_cast<Box*>(&repairView->m_kItemList)->Add(item, item->Name(), 0, 0);
                }
            }
        }
    }
    if (CompareText(gSystemLocaleState.String(), "ENGLISH"))
    {
        reinterpret_cast<UITile*>(repairView->FUN_00726070())->Child("RM_Headline_Title")->SetString(0xfc4, g_011d4378.String(), true);
        reinterpret_cast<UITile*>(repairView->m_pTiles[0])->SetString(DAT_011da74c, g_011d4030.String(), true);
        reinterpret_cast<UITile*>(repairView->m_pTiles[4])->SetString(DAT_011da74c, g_011d4da4.String(), true);
        reinterpret_cast<UITile*>(repairView->m_pTiles[9])->SetString(DAT_011da74c, g_011d4da4.String(), true);
        reinterpret_cast<UITile*>(repairView->m_pTiles[11])->SetString(0xfc4, g_011d1f2c.String(), true);
        reinterpret_cast<UITile*>(repairView->m_pTiles[12])->SetString(0xfc4, g_011d29f4.String(), true);
    }
}
}  // namespace fnv_007b6aa0
