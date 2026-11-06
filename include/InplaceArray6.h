#pragma once

class InplaceArray6
{
public:
    void* data;
    int size;
    unsigned int capacityAndFlags;
    void* buffer0;
    void* buffer1;
    void* buffer2;
    void* buffer3;
    void* buffer4;
    void* buffer5;

    InplaceArray6()
    {
        size = 0;
        data = &buffer0;
        capacityAndFlags = (1u << 31) | 6u;
    }
};

