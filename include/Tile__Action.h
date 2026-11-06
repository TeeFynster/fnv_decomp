#pragma once

#include "Tile.h"


class Tile__Action
{
public:
    void** m_ppVirtualMethodTable;
    Tile::VALUE_ACTION eActionType;
    Tile__Action* m_pActionSuccessor;
};
