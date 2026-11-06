#pragma once

#include <stddef.h>

class __declspec(align(16)) Vector228
{
public:
    float x;
    float y;
    float z;
    float w;
};

typedef char Vector228_size_check[(sizeof(Vector228) == 16) ? 1 : -1];
typedef char Vector228_x_offset_check[(offsetof(Vector228, x) == 0) ? 1 : -1];
typedef char Vector228_y_offset_check[(offsetof(Vector228, y) == 4) ? 1 : -1];
typedef char Vector228_z_offset_check[(offsetof(Vector228, z) == 8) ? 1 : -1];
typedef char Vector228_w_offset_check[(offsetof(Vector228, w) == 12) ? 1 : -1];
