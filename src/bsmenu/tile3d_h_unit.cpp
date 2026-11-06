#include "../../include/Tile3D.h"

// @fnv 0x00a0bdc0
int Tile3D::GetType()
{
    return 0x388;
}
// @fnv 0x00709860
Tile::Tile() : m_kValues(16, false), m_pRenderedNodeEntry(0)
{
    m_pRenderedNodeEntry = 0;
    pParent = 0;
    uiFlags = 0;
    m_bFlagAfterUiFlags = false;
}
