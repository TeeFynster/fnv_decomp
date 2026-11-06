#pragma once

#include "Vector228.h"

class Contact228
{
public:
    Vector228 normal;
    union
    {
        Vector228 position;
        struct
        {
            float px, py, pz, distance;
        };
    };
};
