
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nifile_console.h"

struct MersenneTwister
{
    int _0;
    int _4;
    char _8[0x9C0];
    int _9C8;
    void BSRandom_Init(unsigned int);
    void Seed(unsigned int);
};
// @fnv 0x00aa5170
// src: COMMUNITY 0x00aa5170
void MersenneTwister::BSRandom_Init(unsigned int a)
{
    _4 = 0;
    _9C8 = 0x271;
    Seed(a);
}
