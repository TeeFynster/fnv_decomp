
// src/gamebryo2.2/corelibs/nicollision/niobbroot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niobbroot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiOBBRoot.h"

struct MM
{
    void _DeallocateAlias(void*);
};
extern MM g_memoryManager;
extern int DAT_010f1b44;
struct DelBase
{
    virtual ~DelBase();
};
// Deletes the bound and optionally deallocates this object.
// @fnv 0x00eb5fc0
void* NiOBBRoot::Destroy(unsigned int auiFlags)
{
    DelBase* t = reinterpret_cast<DelBase*>(unk08);
    *reinterpret_cast<void**>(this) = (void*)&DAT_010f1b44;
    delete t;
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct S_00eb6030_Bound
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Test(S_00eb6030_Bound* other, int a2, int a3, int a4, int a5, int a6, int a7, int mine, int theirs,
                     int a8);
};
// Forwards both bounds and their values at offset 0x50 to the bound Test method.
// @fnv 0x00eb6030
int NiOBBRoot::TestAgainst(NiOBBRoot* other, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    if (this == other)
        return 0;
    S_00eb6030_Bound* mine = reinterpret_cast<S_00eb6030_Bound*>(unk08);
    int iMine = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x50);
    int t = *reinterpret_cast<int*>(reinterpret_cast<char*>(other) + 0x50);
    return mine->Test(reinterpret_cast<S_00eb6030_Bound*>(other->unk08), a2, a3, a4, a5, a6, a7, iMine, t, a8);
}

// Forwarder: this->m_08->virtual_slot_0x10(a) tail-jumped.
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Forward(int a);
};

// @fnv 0x00dbd750
void NiOBBRoot::vf03(int a)
{
    reinterpret_cast<Target*>(unk08)->Forward(a);
}

struct FUN_00eb5ff0_view
{
    virtual void w0();
    virtual void w1();
    virtual int w2(FUN_00eb5ff0_view* first, int a2, int a3, int a4, int a5, int mine, int theirs);
};

// Compares both bounds using their values at offset 0x50.
// @fnv 0x00eb5ff0
unsigned char NiOBBRoot::CompareBounds(NiOBBRoot* other, int a2, int a3, int a4, int a5)
{
    if (this == other)
    {
        return 0;
    }
    FUN_00eb5ff0_view* bound = reinterpret_cast<FUN_00eb5ff0_view*>(this->unk08);
    int theirs = *reinterpret_cast<int*>(reinterpret_cast<char*>(other) + 0x50);
    int mine = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x50);
    return (unsigned char)bound->w2(reinterpret_cast<FUN_00eb5ff0_view*>(other->unk08), a2, a3, a4, a5, mine, theirs);
}
