#pragma once

#include <stddef.h>

class NiPoint4
{
public:
    float x;
    float y;
    float z;
    float w;
};

typedef char NiPoint4_size_check[(sizeof(NiPoint4) == 16) ? 1 : -1];
typedef char NiPoint4_x_offset_check[(offsetof(NiPoint4, x) == 0) ? 1 : -1];
typedef char NiPoint4_y_offset_check[(offsetof(NiPoint4, y) == 4) ? 1 : -1];
typedef char NiPoint4_z_offset_check[(offsetof(NiPoint4, z) == 8) ? 1 : -1];
typedef char NiPoint4_w_offset_check[(offsetof(NiPoint4, w) == 12) ? 1 : -1];
