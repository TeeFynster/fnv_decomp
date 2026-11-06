#pragma once

#include "ListBoxBase.h"
#include "MagicTarget.h"

class ListBoxItem_enum_MiscStatManager__MiscStatID_;
class Tile;
enum MiscStatManager__MiscStatID;

class ListBox_enum_MiscStatManager__MiscStatID_ : public ListBoxBase
{
public:
    BSSimpleList<ListBoxItem_enum_MiscStatManager__MiscStatID_*>
        bSSimpleList_ListBoxItem_enum_MiscStatManager__MiscStatID____Component;
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

    Tile* GetTileForData(MiscStatManager__MiscStatID& value);
};
