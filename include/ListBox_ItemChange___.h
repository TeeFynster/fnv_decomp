#pragma once

class Tile;

class ListBox_ItemChange___
{
public:
    ListBox_ItemChange___();
    ~ListBox_ItemChange___();
    void Initialize(Tile*, const char*);
    void FUN_007a1930(bool);
    Tile* GetHighlightedItem();
    void ListBox_ItemChange_SetListState(float, float);
    Tile* FUN_00825c00();
    void ApplyFilter(void (__cdecl*)());
    void ListBox_ItemChange_Traverse(void (__cdecl*)(void*, int), int, int);
    void ListBox_ItemChange_Traverse(void (__cdecl*)(Tile*), int, int);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
