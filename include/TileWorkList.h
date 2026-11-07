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
    void NiTPointerListBase_DFALL_NiTListItem_NiAVObject_NiAVObject_AddHead(NiAVObject* const&);
    unsigned int NiNode_GetChildCount();
    SceneNode* NiNode_GetAtChecked(unsigned int auiIndex);
};
