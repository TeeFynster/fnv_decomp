
// src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpusplitsimulationislandjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpusplitsimulationislandjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct D942F0Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D942F0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct D942F0Island
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_pOwningWorld;
    int unk1C;
    int unk20;
    unsigned char unk24;
    unsigned char m_flags;

    void markDirty();
};

void __cdecl hkpWorldOperationUtil_splitSimulationIsland(D942F0Island* island, void* world, void* context, D942F0Array* out);

// @fnv 0x00d942f0
void __cdecl ClearFlagsAndMarkDirty(D942F0Island* island, void* context)
{
    island->m_flags &= ~3;
    D942F0Array entities;
    island->markDirty();
    hkpWorldOperationUtil_splitSimulationIsland(island, island->m_pOwningWorld, context, &entities);
}
