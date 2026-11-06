#pragma once

#include "ListBoxBase.h"
#include "MagicTarget.h"

class ListBoxItem_int_;
class Tile;

class ListBox_int_ : public ListBoxBase
{
public:
    BSSimpleList<ListBoxItem_int_*> bSSimpleList_ListBoxItem_int____Component;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    unsigned short layoutPadding1E;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;
    unsigned short layoutPadding2E;

    Tile* AddItem(int, const char*, int (*)(ListBoxItem_int_*, ListBoxItem_int_*), const char*);
    void Synchronize();
    void Initialize(Tile*, const char*);
    bool ContainsKey(Tile*);
    bool SetTileSelection(Tile*, int);
};
