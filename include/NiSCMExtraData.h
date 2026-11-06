#pragma once

#include "NiExtraData.h"

class NiSCMExtraData : public NiExtraData
{
public:
    void* Destroy(unsigned int);

    char _pad[24];
    void* m_24;
    char _pad2[4];
    void* m_2c;
};
