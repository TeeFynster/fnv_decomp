#include "../../../include/PathingPath.h"

// src/fallout_shared/pathfinding/teleportpath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/teleportpath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef char _sizecheck_TeleportPath[sizeof(PathingPath) == 56 ? 1 : -1];
struct FUN_006f4990_shell : public PathingPath
{
    void ClearTeleportPath();
};

struct GlobalObject_00869f00
{
    void Clear(bool);
};

// @fnv 0x006f4990
void FUN_006f4990_shell::ClearTeleportPath()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
    ((GlobalObject_00869f00*)((char*)this + 0x10))->Clear(true);
}

struct Elem16
{
    int a;
    int b;
    int c;
    int d;
};
struct Arr16
{
    int _0;
    Elem16* _4;
    int _8;
    int _12;
    unsigned int BSSimpleArray_TeleportLink_1024_AddUninitialized();
    void ConstructBounds(void*, int);
    unsigned int AppendElement(const Elem16* aPath);
};
// @fnv 0x006f2d20
unsigned int Arr16::AppendElement(const Elem16* aPath)
{
    unsigned int idx = BSSimpleArray_TeleportLink_1024_AddUninitialized();
    ConstructBounds(&_4[idx], 1);
    _4[idx] = *aPath;
    return idx;
}

struct FUN_006f4b40
{
    char pad[16];
    ~FUN_006f4b40();
};
struct FUN_006f4b90
{
    char pad[16];
    ~FUN_006f4b90();
};
struct FUN_006f4930
{
    FUN_006f4b40 m1;
    FUN_006f4b90 m2;
    ~FUN_006f4930();
};
// @fnv 0x006f4930
FUN_006f4930::~FUN_006f4930()
{}

struct FUN_006f4b10 : FUN_006f4b40
{
    FUN_006f4b10();
};
struct FUN_006f4b60 : FUN_006f4b90
{
    FUN_006f4b60();
};
struct FUN_006815c0
{
    int unk00;
    int unk04;
    int unk08;
    FUN_006815c0();
};
struct FUN_006f48b0
{
    FUN_006f4b10 first;
    FUN_006f4b60 second;
    FUN_006815c0 third;
    FUN_006815c0 fourth;
    FUN_006f48b0();
};
// Default constructor: initialises the first, second, third and fourth members in order.
// @fnv 0x006f48b0
FUN_006f48b0::FUN_006f48b0() : first(), second(), third(), fourth()
{}

#include <windows.h>
// @fnv 0x0040b460
// src: COMMUNITY 0x0040b460
void NiAtomicIncrement_0040b460(unsigned int* aui32Value)
{
    InterlockedIncrement((volatile LONG*)aui32Value);
}
