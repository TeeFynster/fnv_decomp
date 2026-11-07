
// src/gamebryo2.2/corelibs/nimain/nishaderlibrarydesc.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nishaderlibrarydesc.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct IndexedObjectCollection
{
    void* __thiscall NiShaderLibraryDesc_GetShaderDesc(int idx);
};

// @fnv 0x00a9ffe0
// src: XBOX_PDB 0x00a9ffe0
void* __thiscall IndexedObjectCollection::NiShaderLibraryDesc_GetShaderDesc(int idx)
{
    return (*(void***)((char*)this + 0x3C))[idx];
}

struct MyDesc
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
    unsigned short unk44;

    unsigned int NiShaderLibraryDesc_GetShaderCount();
};

// @fnv 0x00a9ffd0
// src: XBOX_PDB 0x00a9ffd0
unsigned int MyDesc::NiShaderLibraryDesc_GetShaderCount()
{
    return unk44;
}
