// Identical trait-value stubs at three original game addresses.
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/NiSortAdjustNode.h"
#include "../../include/TileRect.h"

// @fnv 0x005578e0
Tile* TileRect::SetTraitValue(int, float, const char*)
{
    return 0;
}

// Keep the duplicate stubs' receiver in ECX and all three arguments on the
// stack, as in the member-function ABI, without inventing more tile classes.
struct TraitValueArguments
{
    int valueID;
    float floatValue;
    const char* strValue;
};

// @fnv 0x00a1f600
Tile* __fastcall FUN_00a1f600(TileRect*, TraitValueArguments)
{
    return 0;
}

// @fnv 0x00aaa650
Tile* __fastcall FUN_00aaa650(TileRect*, TraitValueArguments)
{
    return 0;
}
