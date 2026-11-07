// speedtree/librandom_source/idvrandom.cpp: RandomNumberGenerator, Uniform (8 functions)

#include "../../../include/Random.h"
#include "idvrandom_decls.h"

// @fnv 0x00b3f100
RandomNumberGenerator::RandomNumberGenerator()
{
    if (!DAT_011f8eb8)
        SeedRandomGenerator(-1);
}

// @fnv 0x00b3f160
void RandomNumberGenerator::SeedRandomGenerator(long seed)
{
    if (seed == -1)
    {
        long randomSeed = 12345;
        if (DAT_011f8eb8)
            randomSeed = (long)GenerateRandomFloat(0.0f, 2147483648.0f);
        long currentTime = (long)_time64(0);
        if (randomSeed > currentTime)
            Random::Set((double)currentTime / randomSeed);
        else
            Random::Set((double)randomSeed / currentTime);
    }
    else
    {
        if (seed <= 1)
            seed = 1;
        Random::SetLong(seed);
    }
    DAT_011f8eb8 = true;
}

// @fnv 0x00b3f270
int Random::vf06()
{
    return 1;
}

extern Random DAT_011f8ebc;
// Linearly interpolates between fMin and afMax using a random sample.
// @fnv 0x00b3f130
float RandomNumberGenerator::GenerateRandomFloat(float fMin, float afMax)
{
    return (float)((afMax - fMin) * (double)DAT_011f8ebc.Random::Next() + fMin);
}

struct FloatIntPair
{
    float f;
    int i;
};
// Sets p->i to 0 and p->f to 0.5, then returns p.
// @fnv 0x00b3f210
FloatIntPair* Random::vf04(FloatIntPair* pValue)
{
    pValue->i = 0;
    pValue->f = 0.5f;
    return pValue;
}

extern float DAT_010a58ec;
// Sets p->i to 0 and p->f to DAT_010a58ec, then returns p.
// @fnv 0x00b3f240
FloatIntPair* Random::vf05(FloatIntPair* pValue)
{
    pValue->i = 0;
    pValue->f = DAT_010a58ec;
    return pValue;
}
extern double _gModifierZero;
struct Uniform
{
    float Next();
    float Density_00b3f2a0(float x) const;
};

// @fnv 0x00b3f280
float Uniform::Next()
{
    return ((Random*)this)->Random::Next();
}

// Returns 1.0f when x is within [_gModifierZero, 1.0], otherwise 0.0f.
// @fnv 0x00b3f2a0
// src: XBOX_PDB 0x00b3f2a0
float Uniform::Density_00b3f2a0(float afValue) const
{
    return (afValue < _gModifierZero || afValue > 1.0) ? 0.0f : 1.0f;
}
