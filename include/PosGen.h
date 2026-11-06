#pragma once

#include "Random.h"

class PosGen : public Random
{
public:
    PosGen();
    virtual ~PosGen();
    virtual float Next();
    virtual FloatIntPair* vf04(FloatIntPair* value);
    void Build(bool ready);

    float xi;
    float* sx;
    float* m_pYValues;
    bool NotReady;
    unsigned char layoutPadding11[3];
};
