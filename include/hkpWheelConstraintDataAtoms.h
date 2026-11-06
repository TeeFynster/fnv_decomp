#pragma once

class hkpWheelConstraintDataAtoms
{
public:
    enum Axis
    {
        AXIS_SUSPENSION = 0,
        AXIS_PERP_SUSPENSION = 1,
        AXIS_AXLE = 0,
        AXIS_STEERING = 1
    };

    char pad0[0x130];
};
