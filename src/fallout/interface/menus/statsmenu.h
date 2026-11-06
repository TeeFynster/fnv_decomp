
#include "../../../../include/StatsMenu.h"
#include "../../../../include/Tile.h"
// the CRT memset (0x00403d30), declared as able to throw as the original EH frame needs (windows.h declares memset nothrow)
extern "C" void* __cdecl fnv_memset_00403d30(void*, int, unsigned int) throw(...);

// @fnv 0x0071f660
int StatsMenu::GetClass()
{
    return 1003;
}

// @fnv 0x0071fa50
void StatsMenu::AssignTileByID(int id, Tile* tile)
{
    if (id >= 0 && id < 60)
        m_pTiles[id] = tile;
}

// @fnv 0x007dc040
bool StatsMenu::SetTileFlashing(Tile* tile, unsigned int flashing)
{
    if (flashing)
        tile->SetTraitFade(4009, 255.0f, 0.0f, 1.0f, Tile::TFCT_NONLINEAR_LONG_DARK_REPEATING);
    else
    {
        tile->UpdateTrait(4009);
        tile->Set(4009, 255);
    }
    return true;
}

// @fnv 0x007db2c0
StatsMenu::BodyPartDisplay::BodyPartDisplay()
{
    m_iBodyPartCount = 0;
    fnv_memset_00403d30(m_auiBodyPartValues, -1, sizeof(m_auiBodyPartValues));
}
