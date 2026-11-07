
// src/havok/physics/collide/shape/compound/tree/mopp/hkpmopputility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/tree/mopp/hkpmopputility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CallTarget_00d5ed80
{
    int Search(int, int, int, int);
};
struct SearchObject
{
    int ProcessAndReturnValue_00d5eda0(unsigned int arg0, unsigned int arg1, unsigned int arg2);
};
// @fnv 0x00d5eda0
// src: GUESS 0x00d5eda0 (confidence: low)
int SearchObject::ProcessAndReturnValue_00d5eda0(unsigned int arg0, unsigned int arg1, unsigned int arg2)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00d5ed80*)this)->Search((int)arg0, (int)arg1, (int)arg2, (int)1u);
    return (int)callResult0;
}
