#pragma once

class Tile;
class InventoryStackRecord;

class HotkeyWheelDisplay
{
public:
    Tile* m_pWheelTile;
    Tile* m_ppHotkeySlotTiles[8];
    bool m_bHasHotkeySelection;
    unsigned char layoutPadding25[3];
    int m_iTileValueIdAtOffset28;
    int m_iTileValueIdAtOffset2C;
    int m_iTileValueIdAtOffset30;

    HotkeyWheelDisplay();
    ~HotkeyWheelDisplay();
    bool GetVisible();
    void SetVisible(bool);
    void RefreshHotkeyWheel();
    void Initialize(Tile*);
    int SetHotkeyItem(int, int);
    void SetHotkeyItem(InventoryStackRecord*);
    int SetHotkeyItem(unsigned int, bool);
    int HandleHotkeyInput(int, int);
    int GetSelectedHotkeyIndex(int);
    int DispatchByType(int key);
};
