#pragma once

#include "Menu.h"
#include "BSSimpleList.h"
#include "ListBox_ItemChange___.h"

class TESObjectREFR;
class TESBoundObject;
class InventoryStackRecord;

class BarterMenu : public Menu
{
public:
    union
    {
        unsigned char layoutExtension[0xF8];
        struct
        {
            union
            {
                Tile* m_apTiles[22];
                Tile* m_pTiles[22];
                Tile* tiles[22];
            };
            union { TESObjectREFR* m_pkMerchant; TESObjectREFR* m_merchant; };
            union { float m_fBarterTotal; float m_barterTotal; float unk84; };
            int unk88;
            union { int m_iMerchantCaps; int m_i8C; int unk8C; };
            union { int m_i90; int unk90; };
            union { float m_f94; float unk94; };
            union { float m_f98; float unk98; };
            union { int m_iMerchantFilter; int m_i9C; };
            union { int m_iPlayerFilter; int m_iA0; };
            union { int m_iA4; void* unkA4; };
            ListBox_ItemChange___ m_kMerchantList;
            ListBox_ItemChange___ m_kPlayerList;
            union { ListBox_ItemChange___* m_pkActiveList; ListBox_ItemChange___* unk108; };
            BSSimpleList<InventoryStackRecord*> m_kMerchantItems;
            BSSimpleList<InventoryStackRecord*> m_kPlayerItems;
            union { bool m_b11C; unsigned char unk11C; };
            unsigned char unk11D[3];
        };
    };

    BarterMenu();
    virtual ~BarterMenu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void PostDragTileChange(unsigned int, Tile*, Tile*);
    virtual void PreDragTileChange(unsigned int, Tile*, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void OnClickHeld(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);
    virtual void OnUpdateUserTrait(int);
    virtual void HandleControllerConnectOrDisconnect(bool);

    unsigned char HasNoZeroEntries();
    void RebuildInventoryLists(int);
    void RebuildInventoryLists(TESBoundObject*);
    void CompleteBarterTransaction();
    void UpdateTileText(int);
    void HandleTileClick(int, Tile*);
    void UpdateTileState(int, void*);
    bool HandleAction(int, int);
    InventoryStackRecord* FindMatchingEntry(BSSimpleList<InventoryStackRecord*>*, InventoryStackRecord*);
    InventoryStackRecord* FindEntry(BSSimpleList<InventoryStackRecord*>*, void*);
    void DecrementEntryCount(int);
    void AddOrUpdateEntryCount(int);

    void* __thiscall FUN_0072d070(unsigned int flags);
    void __thiscall FUN_0072d0a0();
    void __thiscall UpdateCapsLabels();
    void __thiscall DoLeave(int, void*);
    void __thiscall DoWheelMove(int, int);
    void __thiscall DoIdle();
};
