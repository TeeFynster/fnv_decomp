#pragma once

class nitmapbase_FormMap
{
public:
    unsigned int storage[4]; // not a char array: a char array would make locals holding the map /GS buffers (0x00849b10)

    nitmapbase_FormMap();
    ~nitmapbase_FormMap();
};
