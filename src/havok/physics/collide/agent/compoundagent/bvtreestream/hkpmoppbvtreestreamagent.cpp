
// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpmoppbvtreestreamagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtreestream/hkpmoppbvtreestreamagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Heap
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void Free(void*, unsigned int);
};
struct Global
{
    unsigned int unk00, unk04, unk08, unk0c;
    Heap* heap10;
};
Global* hkMemoryRouter_getInstance();
struct FUN_00d2dc40
{
    int unk04;
    int unk08;
    virtual ~FUN_00d2dc40();
    static void operator delete(void* p);
};
// @fnv 0x00d2dc40
FUN_00d2dc40::~FUN_00d2dc40()
{}
void FUN_00d2dc40::operator delete(void* p)
{
    Global* global = hkMemoryRouter_getInstance();
    global->heap10->Free(p, 0xc);
}
