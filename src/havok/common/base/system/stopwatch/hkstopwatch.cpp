
// src/havok/common/base/system/stopwatch/hkstopwatch.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/stopwatch/hkstopwatch.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d60570_t
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern FUN_00d60570_t* DAT_01269cc0;
// @fnv 0x00d60570
// src: XBOX_PDB 0x00d60570
void hkStopwatch_getTickCounter()
{
    DAT_01269cc0->v3();
}

namespace fnv_00d60580 {
struct FUN_00d60580_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
};
extern FUN_00d60580_vt* DAT_01269cc0;
// @fnv 0x00d60580
// src: XBOX_PDB 0x00d60580
void __cdecl hkStopwatch_getTicksPerSecond()
{
    DAT_01269cc0->v4();
}
}  // namespace fnv_00d60580

// @fnv 0x00d60550
float DivideInt64ToFloat(__int64 aiNumerator, __int64 aiDenominator)
{
    return (float)((double)aiNumerator / (double)aiDenominator);
}
