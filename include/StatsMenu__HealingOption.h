#pragma once

class AlchemyItem;
class Tile;
class InventoryStackRecord;
class bool___cdecl__StatsMenu__HealingOption__;

class StatsMenu__HealingOption
{
public:
    AlchemyItem* m_pHealingItem;
    Tile* pTile;
    InventoryStackRecord* m_pStatusEffect;
    bool___cdecl__StatsMenu__HealingOption__* m_pfnIsAvailable;
};
