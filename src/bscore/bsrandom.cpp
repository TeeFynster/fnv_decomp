
// bscore/bsrandom.cpp
//
// Translation unit that emits the bsrandom.inl helper bodies as out-of-line
// /Gy comdats, exactly as the original consumer translation units did.
#include "../../include/ProcessLists.h"
#include "bsrandom.h"
#include "bsrandom_decls.h"
#include "bsrandom.inl"

namespace {
// The game's consumer translation units call these helpers directly;
// these calls select the identical comdat bodies for emission.
void ReferenceBSRandomHelpers()
{
    RandomFloat(0.0f, 1.0f);
    RandomFloat0To1();
    RandomBoolean(0.5f);
}
}

// @fnv 0x00aa5140
MersenneTwister::MersenneTwister()
{
    m_uiSeed = 1;
    m_uiLastValue = 0;
    mti = 0x271;
}

// @fnv 0x00aa51a0
void MersenneTwister::Seed(unsigned int seed)
{
    mt[0] = seed;
    for (mti = 1; mti < 0x270; ++mti)
    {
        mt[mti] = mt[mti - 1] * 0x10dcd;
    }
}

#include "bsrandom_precipitation.h"
// Constructs the local aggregate, allocating its shader accumulator and camera.
// @fnv 0x0049fcd0
FUN_0049fcd0_Object::FUN_0049fcd0_Object() : node(0), accumulator(0), object(0)
{
    accumulator = reinterpret_cast<NiAVObject*>(new BSShaderAccumulatorAlloc(BSShaderManager::BRCM_NORMAL, 1, 759));
    object = reinterpret_cast<NiAVObject*>(new NiCamera);
}

// Advances the Mersenne Twister state, regenerating the table when mti reaches 0x270, and returns a random value masked or reduced modulo bound.
// @fnv 0x00aa5230
unsigned int MersenneTwister::GetRandomUInt(unsigned int bound)
{
    if (bound == 0)
        return 0;

    unsigned int y;
    if (mti >= 0x270)
    {
        if (mti == 0x271)
            Seed(GetTickCount());

        int iIndex;
        for (iIndex = 0; iIndex < 0xe3; ++iIndex)
        {
            y = (mt[iIndex] & 0x80000000) | (mt[iIndex + 1] & 0x7fffffff);
            mt[iIndex] = (y >> 1) ^ mt[iIndex + 397] ^ DAT_011ac3b0[y & 1];
        }
        for (; iIndex < 0x26f; ++iIndex)
        {
            y = (mt[iIndex] & 0x80000000) | (mt[iIndex + 1] & 0x7fffffff);
            mt[iIndex] = (y >> 1) ^ mt[iIndex - 227] ^ DAT_011ac3b0[y & 1];
        }
        y = (mt[0x26f] & 0x80000000) | (mt[0] & 0x7fffffff);
        mt[0x26f] = (y >> 1) ^ mt[0x18c] ^ DAT_011ac3b0[y & 1];
        mti = 0;
    }

    y = mt[mti];
    ++mti;
    if (bound == 0xffffffff || bound == 0x7fff)
    {
        return y & bound;
    }
    else
    {
        return y % bound;
    }
}

extern ProcessLists g_011c77b4;

// @fnv 0x00446e10
// src: COMMUNITY 0x00446e10
unsigned char TESRenderer_GetFullScreen()
{
    return *g_011c77b4.GetLifeStateControlFlag();
}

// @fnv 0x00aa5220
void MersenneTwister::Kill()
{}
