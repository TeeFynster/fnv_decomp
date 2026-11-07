// src/havok/physics/collide/shape/hkpshapecontainer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/hkpshapecontainer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpShapeContainer.h"

struct FUN_00d1f1e0_class
{
// @fnv 0x00d1f1e0
    virtual void FUN_00d1f1e0_0()
    {}
    virtual void FUN_00d1f1e0_1()
    {}
    virtual int FUN_00d1f1e0_2()
    {
        return -1;
    }
    virtual int FUN_00d1f1e0_3(int)
    {
        return -1;
    }

    int hkpShapeContainer_getNumChildShapes();
};

// src: HAVOK_LIB 0x00d1f1e0
int FUN_00d1f1e0_class::hkpShapeContainer_getNumChildShapes()
{
    int count = 0;
    int child = FUN_00d1f1e0_2();

    while (child != -1)
    {
        ++count;
        child = FUN_00d1f1e0_3(child);
    }

    return count;
}

struct FUN_00d1f210_cls
{
    int unk00;
    int m_04;
    int hkpShapeContainer_getChildShape(int a1, int a2);
};

// @fnv 0x00d1f210
// src: COMMUNITY 0x00d1f210
int FUN_00d1f210_cls::hkpShapeContainer_getChildShape(int a1, int a2)
{
    return m_04;
}

// @fnv 0x00d1f1d0
// src: COMMUNITY 0x00d1f1d0
int __stdcall hkpShapeContainer_getCollisionFilterInfo(int)
{
    return 0;
}
