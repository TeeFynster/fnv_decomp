#pragma once

#include <cstddef>

class FourByteState;

class hkpAgent1nSector
{
public:
    enum
    {
        SECTOR_SIZE = 512,
        NET_SECTOR_SIZE = SECTOR_SIZE - 16
    };

    unsigned int m_uiAgentCount;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;

    hkpAgent1nSector();

    static void* __cdecl operator new(std::size_t size);
    static void __cdecl operator delete(void* p);

    FourByteState* getBegin();
    FourByteState* GetStreamEnd();
    void* getEndOfCapacity();
    int getCapacity();
};
