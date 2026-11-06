#pragma once

namespace Pathing
{
class CheckLineOfSightFilter
{
public:
    // RTTI: vftable 0x0106c944, one slot (0x00ec60fa, pure); CheckLineOfSightFilterWater overrides it (0x006cd5c0)
    virtual bool IsLineOfSightClear(unsigned int, unsigned int, unsigned int,
                                    unsigned int, unsigned int, unsigned int) = 0;
};
}
