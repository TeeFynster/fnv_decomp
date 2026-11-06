#include "../../include/bhkLiquidAction.h"

extern unsigned int DAT_012681bc;

// @fnv 0x0056d380
bhkLiquidAction::bhkLiquidAction(const LiquidActionInfo& info)
{
    ConfigureBody(info);
    ++DAT_012681bc;
}
