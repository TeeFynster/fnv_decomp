// src/havok/physics/collide/shape/heightfield/storagesampledheightfield/hkpstoragesampledheightfieldshapeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/storagesampledheightfield/hkpstoragesampledheightfieldshapeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d49600_Vec
{
    float x;
    float y;
    float z;
};
struct S_00d49600
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    S_00d49600_Vec* unk60;
    int unk64;
    int unk68;
    float unk6C;
    float hkpStorageSampledHeightFieldShape_getHeightAtImpl(int x, int z);
};
// Returns the z component of the vector at unk60 indexed by (unk68 - z) * unk10 + x, plus unk6C.
// @fnv 0x00d49600
// src: XBOX_PDB 0x00d49600
float S_00d49600::hkpStorageSampledHeightFieldShape_getHeightAtImpl(int x, int z)
{
    return unk60[(unk68 - z) * unk10 + x].z + unk6C;
}

struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d496d0();
    CpuObject* FUN_00d49630(unsigned int flags);
};
// @fnv 0x00d49630
CpuObject* CpuObject::FUN_00d49630(unsigned int flags)
{
    FUN_00d496d0();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
