#pragma once

#include "ListBoxBase.h"
#include "MagicTarget.h"

class ListBoxItem_StatsMenu__StatusEffect___;
class Tile;

class ListBox_StatsMenu__StatusEffect___ : public ListBoxBase
{
public:
    BSSimpleList<ListBoxItem_StatsMenu__StatusEffect___*>
        bSSimpleList_ListBoxItem_StatsMenu__StatusEffect______Component;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;
    unsigned char layoutPadding2E[2];
};
