
#include "../../include/BSMultiBoundAABB.h"
#include "../../include/BSMultiBoundShape.h"
#include "../../include/bhkLiquidAction.h"

// @fnv 0x00471840
unsigned int bhkLiquidAction::GetInstanceSize()
{
    return 24;
}

// @fnv 0x004a7ba0
void BSMultiBoundAABB::SetGridPosition(const NiPoint3& center)
{
    Center = center;
}
