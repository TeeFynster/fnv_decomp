
// fallout/interface/menus/quantitymenu.cpp
//
// Recovered quantity-menu translation unit. Every menu derives from Menu and
// overrides the shared AssignTileByID slot with its own tile table.
#include "../../../../include/Tile.h"
#include "../../../../include/Menu.h"
#include "../../../../include/InterfaceManager.h"
#include "../../../../include/SleepWaitMenu.h"
#include "../../../../include/QuantityMenu.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/Setting.h"

// Stores tile into the tile array at index when index is within [0, NUM_TILES).
// @fnv 0x007a8ab0
void SleepWaitMenu::AssignTileByID(int index, Tile* tile)
{
    if (index >= 0 && index < NUM_TILES)
        m_pTiles[index] = tile;
}

namespace fnv_007abdf0 {
int __cdecl FUN_00707ad0();
extern SleepWaitMenu* DAT_011da618;
// If DAT_011da618 is set, sets its tile to 0x1772/1, then calls FUN_00a1d9e0 or FUN_00a1d910 depending on FUN_00707ad0.
// @fnv 0x007abdf0
void FUN_007abdf0()
{
    if (DAT_011da618)
    {
        DAT_011da618->FUN_00726070()->Set(0x1772, 1);
        if (FUN_00707ad0())
            DAT_011da618->FUN_00a1d9e0();
        else
            DAT_011da618->FUN_00a1d910();
    }
}
}  // namespace fnv_007abdf0

// Handles button 0xA by calling HandleSelection(5, 0) and returns whether the button was handled.
// @fnv 0x007ac130
bool QuantityMenu::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    if (aiButton == 0xA)
    {
        HandleSelection(5, 0);
        bhandled = true;
    }
    return bhandled;
}

double __cdecl FUN_00408820(float value);
void __cdecl FUN_00706f30(int message);
struct MenuValueWatcher
{
    void* vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Tile* thresholdSource;
    int unk2c, unk30;
    Tile* valueSource;
    int unk38, unk3c;
    float lastValue;
    void UpdateThresholdCheck();
};
// @fnv 0x007ac170
void MenuValueWatcher::UpdateThresholdCheck()
{
    if (FUN_00408820(valueSource->FUN_00a011b0(0xfc4) - lastValue) >= thresholdSource->FUN_00a011b0(0x1007))
    {
        FUN_00706f30(4);
        lastValue = valueSource->FUN_00a011b0(0xfc4);
    }
}

extern Setting DAT_011d3ac8;
extern Setting DAT_011d38b8;
extern Setting DAT_011d29f4;
extern Setting DAT_011d3bc8;
// The tile offsets 0x28/0x38/0x3c and validator 0x007abdb0 match the shared SleepWaitMenu.
extern SleepWaitMenu* DAT_011da618;
extern void* DAT_011da614;
InterfaceManager* FUN_004b7210();
BSAudio* FUN_00453a70();
int FUN_007abda0();
Menu* __cdecl FUN_00a09030(int id);
int FUN_007023c0();
void FUN_005b5e40(const char* msg);
float FUN_00a01530();
int __cdecl MinInt(int a, int b);
int __cdecl FUN_00647b70(int a, int b);
static const char kMenuFile_7aba00[] = "Data\\Menus\\quantity_menu.xml";
static const char kWarning_7aba00[] =
    "MENUS: Quantity Menu Creation Failed... Are your menu and art resources up to date?";
static const char kSound_7aba00[] = "UIPopUpMessageWindow";
static const char kChild1_7aba00[] = "QM_HowManyText";
static const char kChild2_7aba00[] = "QM_Background";
// Loads quantity_menu.xml, builds the quantity menu, sets its max/initial/step values and labels, stores the callback, and returns the tile or 0 on failure.
// @fnv 0x007aba00
Tile* __cdecl CreateQuantityMenu(int max, void* callback, int initial)
{
    InterfaceManager* im4 = FUN_004b7210();
    bool flag_ = false;
    Menu* old = FUN_00a09030(FUN_007abda0());
    if (old)
        delete old;
    if (FUN_007023c0())
        flag_ = true;
    Tile* tile6 = im4->FUN_00586150()->FUN_00a01b00(kMenuFile_7aba00);
    DAT_011da618 = static_cast<SleepWaitMenu*>(tile6->GetMenu());
    if (DAT_011da618 && DAT_011da618->GetClass() == FUN_007abda0())
    {
        DAT_011da618->FUN_00a1dc70(reinterpret_cast<TileMenu*>(tile6), false);
        if (!DAT_011da618->FUN_007abdb0())
        {
            FUN_005b5e40(kWarning_7aba00);
            return 0;
        }
        FUN_00453a70()->FUN_00ad7550(kSound_7aba00, 0x121).Play(false);
        if (tile6->FUN_00a011b0(0xfa7) == 6006.0 || tile6->FUN_00a011b0(0xfa7) == 102.0)
        {
            tile6->FUN_00a012d0(0xfad, FUN_00a01530(), true);
        }
        int value9 = MinInt(initial, max);
        int bigStep = FUN_00647b70(max / 20, 1);
        int smallStep = FUN_00647b70(max / 4, 1);
        if (bigStep > 10)
            bigStep -= bigStep % 10;
        DAT_011da618->m_pTiles[0]->FUN_00700320(0x1004, max);
        DAT_011da618->m_pTiles[0]->FUN_00700320(0x1006, value9);
        DAT_011da618->m_pTiles[0]->FUN_00700320(0x1007, bigStep);
        DAT_011da618->m_pTiles[0]->FUN_00700320(0x1008, smallStep);
        DAT_011da618->m_pTiles[0]->FUN_00a012d0(0xff0, 0.0f, true);
        DAT_011da614 = callback;
        tile6->GetNamedChild(kChild1_7aba00)->FUN_00a01350(0xfc4, DAT_011d3ac8.FUN_00403df0(), true);
        DAT_011da618->m_pTiles[4]->FUN_00a01350(0xfc4, DAT_011d38b8.FUN_00403df0(), true);
        DAT_011da618->m_pTiles[5]->FUN_00a01350(0xfc4, DAT_011d29f4.FUN_00403df0(), true);
        if (flag_)
        {
            DAT_011da618->FUN_00726070()
                ->GetNamedChild(kChild2_7aba00)
                ->FUN_00a012d0(0xfa9, *DAT_011d3bc8.FUN_00403e20() * 255.0, true);
        }
        DAT_011da618->FUN_00a1dc20(false);
        return tile6;
    }
    else
    {
        if (DAT_011da618 && DAT_011da618->FUN_00726070())
            delete DAT_011da618;
    }
    return 0;
}

int TruncateFloatToInt(float value);
float FUN_00404010(float a, float b);
float FUN_0040ebd0(float a, float b);
void __cdecl SleepWaitRefresh();
extern void(__cdecl* g_pSleepWaitCallback)(int);
extern const float kNegOne;


// @fnv 0x007abe40
void SleepWaitMenu::HandleSelection(int index, Tile* tile)
{
    float fValue = m_pTiles[3]->GetFloat(0xfc4);
    if (!tile && index >= 0 && index < 6)
        tile = m_pTiles[index];
    switch (index)
    {
    case 4:
    case 5:
        if (g_pSleepWaitCallback)
            g_pSleepWaitCallback(index == 4 ? TruncateFloatToInt(fValue) : 0);
        SleepWaitRefresh();
        break;
    case 1:
    case 2: {
        float fScaledValue = m_pTiles[0]->GetFloat(0x1004);
        m_pTiles[0]->SetFloat(
            0x1006, FUN_0040ebd0(FUN_00404010(fValue + (index == 2 ? 1.0f : kNegOne), 0.0f), fScaledValue), true);
        m_pTiles[0]->SetFloat(0xff0, 0.0f, true);
    }
    break;
    }
}

float FUN_00404010(float afA, float afB);
float FUN_0040ebd0(float afA, float afB);

struct QtyMenuStub : public Menu
{
    Tile* pScrollTile;
    Tile* pTile2C;
    Tile* pTile30;
    Tile* pBarTile;

    bool HandleQuantityKey(int aiKey, int aiUnused);
};

// @fnv 0x007abf80
bool QtyMenuStub::HandleQuantityKey(int aiKey, int aiUnused)
{
    bool bHandled = false;
    switch (aiKey)
    {
    case 13:
    case 14: {
        float fCur4 = pBarTile->GetFloat(0xFC4);
        float fScaledValue = pScrollTile->GetFloat(0x1004);
        float fStep = pScrollTile->GetFloat(0x1008);
        pScrollTile->SetFloat(
            0x1006, FUN_0040ebd0(FUN_00404010(fCur4 + (aiKey == 14 ? fStep : -fStep), 0.0f), fScaledValue), true);
        pScrollTile->SetFloat(0xFF0, 0.0f, true);
        bHandled = true;
    }
    break;
    case 15:
    case 16: {
        float fCur3 = pBarTile->GetFloat(0xFC4);
        float fMax2 = pScrollTile->GetFloat(0x1004);
        float fStep9 = pScrollTile->GetFloat(0x1007);
        pScrollTile->SetFloat(
            0x1006, FUN_0040ebd0(FUN_00404010(fCur3 + (aiKey == 16 ? fStep9 : -fStep9), 0.0f), fMax2), true);
        pScrollTile->SetFloat(0xFF0, 0.0f, true);
        bHandled = true;
    }
    break;
    }
    return bHandled;
}
