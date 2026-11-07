#pragma once

#include "Menu.h"
#include "ListBox_ItemChange___.h"

class RepairEntry;
class RepairPlayer;
class Holder;
class RepairTile;
class StatTile;

class RepairServicesMenu : public Menu
{
public:
    class RepairItemList : public ListBox_ItemChange___
    {
    public:
        void* FUN_007a1910();
        void ListBox_ItemChange_Traverse(bool (__cdecl*)(void*, void*), void*, int);
        void ListBox_ItemChange_Traverse(void (__cdecl*)(Tile*, void*), int, int);
        void PopulateInventoryList(RepairPlayer*, bool (__cdecl*)(Holder*), int, int, int, int);
    };

    union
    {
        unsigned char layoutExtension[0x78];
        struct
        {
            union
            {
                Tile* tiles[16];
                struct
                {
                    Tile* unk28;
                    Tile* unk2C;
                    Tile* pTile30;
                    Tile* field34;
                    Tile* field38;
                    union { Tile* pTile3C; Tile* field3c; };
                    union { Tile* pTile40; Tile* field40; };
                    Tile* field44;
                    Tile* field48;
                    Tile* field4c;
                    union { Tile* pTile50; Tile* field50; };
                    union { Tile* pTile54; Tile* field54; };
                    Tile* field58;
                    union { Tile* pTile5C; Tile* field5c; };
                    Tile* unk60;
                    Tile* pTile64;
                };
            };
            RepairItemList kRepairList;
            union { int iTotalCost; int totalCost; };
            union { int iRepairSkill; int iSkill; int iUnk9C; int displayedCost; };
        };
    };

    RepairServicesMenu();
    virtual ~RepairServicesMenu();
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual int GetClass();

    int GetMenuID_007b74c0();
    bool CompanionWheelMenu_IsWellFormedMenu();
    void UpdateRepairServiceTiles(int aiID, Tile* apTarget);
    void RefreshRepairMenu();
    void ApplyRepair(void*);
    void ApplyRepair(RepairEntry* apEntry);
    void HandleRepairAction(int id, RepairTile* tile);
    void UpdateItemComparison(int event, StatTile* tile);
};

