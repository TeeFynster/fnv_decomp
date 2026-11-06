#pragma once

class StatsChunkData
{
public:
    unsigned int data[23];

    void SwapEndianFields();
};
