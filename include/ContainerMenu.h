#pragma once

#include <stddef.h>

#include "Menu.h"
#include "ListBox_ItemChange___.h"
#include "BSSoundHandle.h"
#include "StrMem.h"
#include "BSSoundHandle.h"

class Actor;
class ActorView;
class ExpectedReference;
class InventoryEntry;
class ItemEntry;
class MenuForm;
class MenuList;
class PlaybackHandle;
template <class T> class BSStringT;
class PlaybackTopic;
class TESBoundObject;
class TESObjectREFR;
class TileObj;

enum Interface__CONTAINER_MENU_MODE;
enum ContainerMenu__FILTER_MODE;
enum MENU_SOUNDS;

class ContainerMenu : public Menu
{
public:
    Tile* m_pTiles[19];
    TESObjectREFR* m_pContainer;
    BSSimpleList<TESBoundObject*> m_kContainerItems;
    Interface__CONTAINER_MENU_MODE m_eContainerMenuMode;
    int m_iStolenItemCount;
    bool m_bFirstContainerFlag;
    bool m_bSecondContainerFlag;
    unsigned char unk8A[2];
    ContainerMenu__FILTER_MODE m_eFilterMode;
    ContainerMenu__FILTER_MODE m_eSecondFilterMode;
    MENU_SOUNDS m_eMenuSounds;
    ListBox_ItemChange___ m_kFirstItemChangeList;
    ListBox_ItemChange___ m_kSecondItemChangeList;
    ListBox_ItemChange___* m_pCurrentList;
    unsigned int m_uiCurrentItemIndex;
    BSSoundHandle m_kFadeSequence;

    ContainerMenu();
    virtual ~ContainerMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);

    static void __cdecl Close();
    void UpdateContainer(TESObjectREFR*, bool);
    void ContainerMenu_UpdateLists(int);
    void ContainerMenu_UpdateLists(MenuForm*);
    bool HasTiles();
    void PlayContainerSound(TESObjectREFR*, bool);
    void InitContainerMode();
    void AttachAndDeliver(void*, void*, void*);
    void AttachAndDeliver(MenuForm*, void*, MenuList*);
    bool IsPlacingMine(InventoryEntry*, ExpectedReference*, ActorView*);
    int GetContainerValue(ItemEntry*, int, bool);
    bool PickpocketCheck(Actor*, int);
    void SetLabelText(const char*);
    void UpdatePaneTitle(TileObj*);
    void PlaySelectedTopicInfo(PlaybackTopic*);
    void ShowMessageWithSound(BSStringT<char>, PlaybackHandle);
    void ShowMessageWithSound(StrMem, BSSoundHandle);
};

typedef char ContainerMenu_check_size[(sizeof(ContainerMenu) == 0x10C) ? 1 : -1];
typedef char ContainerMenu_check_m_pTiles[(offsetof(ContainerMenu, m_pTiles) == 0x28) ? 1 : -1];
typedef char ContainerMenu_check_m_pContainer[(offsetof(ContainerMenu, m_pContainer) == 0x74) ? 1 : -1];
typedef char ContainerMenu_check_m_kContainerItems[(offsetof(ContainerMenu, m_kContainerItems) == 0x78) ? 1 : -1];
typedef char ContainerMenu_check_m_eContainerMenuMode[(offsetof(ContainerMenu, m_eContainerMenuMode) == 0x80) ? 1 : -1];
typedef char ContainerMenu_check_m_iStolenItemCount[(offsetof(ContainerMenu, m_iStolenItemCount) == 0x84) ? 1 : -1];
typedef char ContainerMenu_check_m_bFirstContainerFlag[(offsetof(ContainerMenu, m_bFirstContainerFlag) == 0x88) ? 1 : -1];
typedef char ContainerMenu_check_m_bSecondContainerFlag[(offsetof(ContainerMenu, m_bSecondContainerFlag) == 0x89) ? 1 : -1];
typedef char ContainerMenu_check_unk8A[(offsetof(ContainerMenu, unk8A) == 0x8A) ? 1 : -1];
typedef char ContainerMenu_check_m_eFilterMode[(offsetof(ContainerMenu, m_eFilterMode) == 0x8C) ? 1 : -1];
typedef char ContainerMenu_check_m_eSecondFilterMode[(offsetof(ContainerMenu, m_eSecondFilterMode) == 0x90) ? 1 : -1];
typedef char ContainerMenu_check_m_eMenuSounds[(offsetof(ContainerMenu, m_eMenuSounds) == 0x94) ? 1 : -1];
typedef char ContainerMenu_check_m_kFirstItemChangeList[(offsetof(ContainerMenu, m_kFirstItemChangeList) == 0x98) ? 1 : -1];
typedef char ContainerMenu_check_m_kSecondItemChangeList[(offsetof(ContainerMenu, m_kSecondItemChangeList) == 0xC8) ? 1 : -1];
typedef char ContainerMenu_check_m_pCurrentList[(offsetof(ContainerMenu, m_pCurrentList) == 0xF8) ? 1 : -1];
typedef char ContainerMenu_check_m_uiCurrentItemIndex[(offsetof(ContainerMenu, m_uiCurrentItemIndex) == 0xFC) ? 1 : -1];
typedef char ContainerMenu_check_m_kFadeSequence[(offsetof(ContainerMenu, m_kFadeSequence) == 0x100) ? 1 : -1];
