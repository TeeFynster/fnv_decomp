
// src/havok/common/internal/convexhull/hkplaneequationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkplaneequationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Arg
{
    void* data;
    int count;
};

struct B
{
    int f0;
    int f1;
    int f2;
    int f3;

    void* hkgpConvexHull_BuildConfig_BuildConfig();
};

struct A
{
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;

    void FUN_00d76ca0();
    int ProcessEntries_00d774a0(void*, int, void*);
    void ProcessState_00d76120(int, int);
    void ReleaseStorage_00d76940();
};

// @fnv 0x00dd6270
int __cdecl ProcessArg(Arg* a, int second)
{
    if (a->count < 4)
    {
        return 1;
    }

    B objB;
    A objA;

    objA.FUN_00d76ca0();

    int count = a->count;
    void* data = a->data;

    void* q = objB.hkgpConvexHull_BuildConfig_BuildConfig();
    int iResult = objA.ProcessEntries_00d774a0(data, count, q);

    if (iResult != -1)
    {
        objA.ProcessState_00d76120(1, second);
        objA.ReleaseStorage_00d76940();
        return 0;
    }

    objA.ReleaseStorage_00d76940();
    return 1;
}
