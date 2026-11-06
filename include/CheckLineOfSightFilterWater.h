#pragma once

#include "Pathing__CheckLineOfSightFilter.h"

class CheckLineOfSightFilterWater : public Pathing::CheckLineOfSightFilter
{
public:
    bool m_bCheckWater;
    unsigned char layoutPadding5[3];

    virtual bool IsLineOfSightClear(unsigned int, unsigned int, unsigned int,
                                   unsigned int, unsigned int, unsigned int);
};
