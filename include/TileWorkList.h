#pragma once

class Link;
class TileWork;
class Tile_Set_Helper;
class NiAVObject;
class SceneNode;

class TileWorkList
{
public:
    Link* head;

    void* First();
    TileWork* Next(Link*& pos);
    Tile_Set_Helper*& At(void*);
    void FUN_004700d0(NiAVObject* const&);
    unsigned int FUN_00453470();
    SceneNode* FUN_0045bc00(unsigned int auiIndex);
};
