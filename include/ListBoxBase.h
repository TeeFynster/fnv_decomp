#pragma once

class Menu;
class Tile;

class ListBoxBase
{
public:
    ListBoxBase();

    virtual bool Highlight(Tile* apTile);
    virtual Tile* GetHighlightedItem();
    virtual Tile* GetTileForButton(int aeButton);
    virtual bool BelongsTo(const Menu* apMenu);
    virtual void ScrollToHighlight();
    virtual Tile* GetTileAt(unsigned int auiIndex, bool abFiltered);

    bool BelongsTo(void* apMenu);

    bool SetSelectedTile(Tile* tile);
    Tile* GetSelectedTile();
    Tile* HandleKeyboardInput(int inputCode);
    bool IsParentMenu(Menu* menu);
    Tile* GetItemTile(int index, bool countFromTop);
    void Destroy(bool doFree);
    void ClearList();
    void vfn_18();
    void Clear();
    void vfn_00();
    Tile* vfn_04();
};
