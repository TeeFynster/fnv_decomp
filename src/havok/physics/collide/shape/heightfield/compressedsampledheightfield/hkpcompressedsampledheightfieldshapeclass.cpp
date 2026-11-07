
// src/havok/physics/collide/shape/heightfield/compressedsampledheightfield/hkpcompressedsampledheightfieldshapeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/compressedsampledheightfield/hkpcompressedsampledheightfieldshapeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ByteFlag
{
    char m_cValue;

    ByteFlag(char acValue) : m_cValue(acValue)
    {}
};

struct FUN_00e01140_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    char m_cFlag;

    ByteFlag hkpCompressedSampledHeightFieldShape_getTriangleFlipImpl();
};

// @fnv 0x00e01140
// src: XBOX_PDB 0x00e01140
ByteFlag FUN_00e01140_cls::hkpCompressedSampledHeightFieldShape_getTriangleFlipImpl()
{
    return ByteFlag(m_cFlag);
}

struct FUN_00e01150_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_i10;
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
    unsigned short* m_pTable;
    int unk64;
    int unk68;
    int unk6c;
    float m_f70;
    float m_f74;

    float GetTableValue(int col, int row);
};

// @fnv 0x00e01150
float FUN_00e01150_cls::GetTableValue(int col, int row)
{
    unsigned short v = m_pTable[m_i10 * row + col];
    return (float)v * m_f74 + m_f70;
}

struct FUN_00e01140_cls;
struct BufferManager
{
    virtual void Unknown0() = 0;
    virtual void Unknown1() = 0;
    virtual void Destroy(FUN_00e01140_cls*, unsigned short) = 0;
    virtual void Unknown3() = 0;
    virtual void Release(unsigned int, unsigned int) = 0;
};
struct BufferContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BufferManager* manager;
};
BufferContext* __cdecl hkMemoryRouter_getInstance();
void __fastcall SetVirtualTable_00d24660(FUN_00e01140_cls*);

struct FUN_00e01180_cls : FUN_00e01140_cls
{
    FUN_00e01180_cls* FUN_00e01180(unsigned int flags);
};
// Releases the buffer through the manager, resets the buffer fields, calls FUN_00d24660, and destroys the object when flags has bit 0 set.
// @fnv 0x00e01180
FUN_00e01180_cls* FUN_00e01180_cls::FUN_00e01180(unsigned int flags)
{
    BufferContext* context = hkMemoryRouter_getInstance();
    BufferManager* manager = context->manager;
    unk64 = 0;
    if (!(unk68 & 0x80000000))
    {
        manager->Release(unk60, (unk68 & 0x3fffffff) * 2);
    }
    unk60 = 0;
    unk68 = 0x80000000;
    SetVirtualTable_00d24660(this);
    if (flags & 1)
    {
        BufferContext* context = hkMemoryRouter_getInstance();
        BufferManager* manager = context->manager;
        manager->Destroy(this, (unsigned short)unk04);
    }
    return this;
}
