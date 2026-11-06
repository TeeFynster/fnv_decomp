// Authoring header for fallout/interface/menus/loadingmenu.h (unit 512).
#ifndef FNV_LOADINGMENU_H
#define FNV_LOADINGMENU_H

#include "../../../../include/LoadingMenu.h"
#include "../../../../include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile___.h"
#include "../../../../include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator.h"
#include "../../../../include/NiTPointerAllocator_unsigned_int_.h"
#include "../../../../include/NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___.h"
#include "../../../../include/NiTPointerList_Tile___.h"
#include "../../../../include/NiColorA.h"

#include "../../../../include/MiscStatManager__MiscStatID.h"
enum FONTS
{
    FONTS_FONT_NONE = -1,
    FONTS_FONT_1 = 0,
    FONTS_FONT_2 = 1,
    FONTS_FONT_3 = 2,
    FONTS_FONT_4 = 3,
    FONTS_FONT_5 = 4,
    FONTS_FONT_6 = 5,
    FONTS_FONT_7 = 6,
    FONTS_FONT_8 = 7,
    FONTS_FONT_COUNT = 8
};
typedef char loadingmenu_tagRECT_size_check[(sizeof(tagRECT) == 16) ? 1 : -1];
typedef char loadingmenu_tagRECT_left_offset_check[(offsetof(tagRECT, left) == 0) ? 1 : -1];
typedef char loadingmenu_tagRECT_top_offset_check[(offsetof(tagRECT, top) == 4) ? 1 : -1];
typedef char loadingmenu_tagRECT_right_offset_check[(offsetof(tagRECT, right) == 8) ? 1 : -1];
typedef char loadingmenu_tagRECT_bottom_offset_check[(offsetof(tagRECT, bottom) == 12) ? 1 : -1];
typedef char loadingmenu_NiTPointerAllocator_unsigned_int__size_check[(sizeof(NiTPointerAllocator_unsigned_int_) == 1) ? 1 : -1];
typedef char loadingmenu_NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator_size_check[(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator) == 4) ? 1 : -1];
typedef char loadingmenu_NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator_m_uiCount_offset_check[(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator, m_uiCount) == 0) ? 1 : -1];
typedef char loadingmenu_NiTListBase_NiTPointerAllocator_unsigned_int__Tile____size_check[(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___) == 12) ? 1 : -1];
typedef char loadingmenu_NiTListBase_NiTPointerAllocator_unsigned_int__Tile____m_pkHead_offset_check[(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_pkHead) == 0) ? 1 : -1];
typedef char loadingmenu_NiTListBase_NiTPointerAllocator_unsigned_int__Tile____m_pkTail_offset_check[(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_pkTail) == 4) ? 1 : -1];
typedef char loadingmenu_NiTListBase_NiTPointerAllocator_unsigned_int__Tile____m_kItemCount_offset_check[(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_kItemCount) == 8) ? 1 : -1];
typedef char loadingmenu_NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile____size_check[(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___) == 12) ? 1 : -1];
typedef char loadingmenu_NiTPointerList_Tile____size_check[(sizeof(NiTPointerList_Tile___) == 12) ? 1 : -1];
typedef char loadingmenu_RgbaColor_size_check[(sizeof(NiColorA) == 16) ? 1 : -1];
typedef char loadingmenu_RgbaColor_r_offset_check[(offsetof(NiColorA, r) == 0) ? 1 : -1];
typedef char loadingmenu_RgbaColor_g_offset_check[(offsetof(NiColorA, g) == 4) ? 1 : -1];
typedef char loadingmenu_RgbaColor_b_offset_check[(offsetof(NiColorA, b) == 8) ? 1 : -1];
typedef char loadingmenu_RgbaColor_a_offset_check[(offsetof(NiColorA, a) == 12) ? 1 : -1];
typedef char loadingmenu_TileLayout_size_check[(sizeof(TileLayout) == 24) ? 1 : -1];
typedef char loadingmenu_TileLayout_m_iXPosition_offset_check[(offsetof(TileLayout, m_iXPosition) == 0) ? 1 : -1];
typedef char loadingmenu_TileLayout_m_iYPosition_offset_check[(offsetof(TileLayout, m_iYPosition) == 4) ? 1 : -1];
typedef char loadingmenu_TileLayout_nHeight_offset_check[(offsetof(TileLayout, nHeight) == 8) ? 1 : -1];
typedef char loadingmenu_TileLayout_nWidth_offset_check[(offsetof(TileLayout, nWidth) == 12) ? 1 : -1];
typedef char loadingmenu_TileLayout_m_eFont_offset_check[(offsetof(TileLayout, m_eFont) == 16) ? 1 : -1];
typedef char loadingmenu_TileLayout_m_ucFontStyle_offset_check[(offsetof(TileLayout, m_ucFontStyle) == 20) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_size_check[(sizeof(LoadingMenu) == 1472) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_pTiles_offset_check[(offsetof(LoadingMenu, m_pTiles) == 40) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kTileRectangle_offset_check[(offsetof(LoadingMenu, m_kTileRectangle) == 192) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kFirstTileList_offset_check[(offsetof(LoadingMenu, m_kFirstTileList) == 208) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kSecondTileList_offset_check[(offsetof(LoadingMenu, m_kSecondTileList) == 220) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kThirdTileList_offset_check[(offsetof(LoadingMenu, m_kThirdTileList) == 232) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kFourthTileList_offset_check[(offsetof(LoadingMenu, m_kFourthTileList) == 244) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kFifthTileList_offset_check[(offsetof(LoadingMenu, m_kFifthTileList) == 256) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_aeMiscStatIdentifiers_offset_check[(offsetof(LoadingMenu, m_aeMiscStatIdentifiers) == 268) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kLoadingScreenTip_offset_check[(offsetof(LoadingMenu, m_kLoadingScreenTip) == 440) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kLoadingScreenColor_offset_check[(offsetof(LoadingMenu, m_kLoadingScreenColor) == 448) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kLoadScreenItems_offset_check[(offsetof(LoadingMenu, m_kLoadScreenItems) == 464) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_pkLoadScreenList_offset_check[(offsetof(LoadingMenu, m_pkLoadScreenList) == 472) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_pCurrentLoadScreen_offset_check[(offsetof(LoadingMenu, m_pCurrentLoadScreen) == 476) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_uiLoadScreenIndex_offset_check[(offsetof(LoadingMenu, m_uiLoadScreenIndex) == 480) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_LoadScreenData_offset_check[(offsetof(LoadingMenu, LoadScreenData) == 484) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_pLocation_offset_check[(offsetof(LoadingMenu, pLocation) == 488) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_TileShaderState_offset_check[(offsetof(LoadingMenu, TileShaderState) == 492) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_pAlternateTileShaderState_offset_check[(offsetof(LoadingMenu, m_pAlternateTileShaderState) == 496) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kFirstDate_offset_check[(offsetof(LoadingMenu, m_kFirstDate) == 500) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kSecondDate_offset_check[(offsetof(LoadingMenu, m_kSecondDate) == 512) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kLoadScreenTextures_offset_check[(offsetof(LoadingMenu, m_kLoadScreenTextures) == 524) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_uiLoadingScreenNumber_offset_check[(offsetof(LoadingMenu, m_uiLoadingScreenNumber) == 540) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_usAdditionalFlags_offset_check[(offsetof(LoadingMenu, m_usAdditionalFlags) == 544) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_usFlags_offset_check[(offsetof(LoadingMenu, usFlags) == 546) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_kTileLayouts_offset_check[(offsetof(LoadingMenu, m_kTileLayouts) == 548) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_uiFirstStateValue_offset_check[(offsetof(LoadingMenu, m_uiFirstStateValue) == 1460) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_uiSecondStateValue_offset_check[(offsetof(LoadingMenu, m_uiSecondStateValue) == 1464) ? 1 : -1];
typedef char loadingmenu_LoadingMenu_m_iStateFlags_offset_check[(offsetof(LoadingMenu, m_iStateFlags) == 1468) ? 1 : -1];

// @fnv 0x00788730
int LoadingMenu::GetClass()
{
    return 1007;
}

// @fnv 0x00788740
void LoadingMenu::AssignTileByID(int uiIndex, Tile* pTile)
{
    if (pTile && uiIndex < 38 && uiIndex >= 0)
        m_pTiles[uiIndex] = pTile;
}
#endif
