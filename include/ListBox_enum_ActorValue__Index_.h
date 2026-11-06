#pragma once

#include "ListBoxBase.h"
#include "MagicTarget.h"

class ListBoxItem_enum_ActorValue__Index_;
class Tile;

namespace ActorValue
{
    enum Index;
}

class ListBox_enum_ActorValue__Index_ : public ListBoxBase
{
public:
    BSSimpleList<ListBoxItem_enum_ActorValue__Index_*>
        bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component;
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

    void Traverse(void (__cdecl* callback)(Tile*, ActorValue::Index), int first, int last);
};
