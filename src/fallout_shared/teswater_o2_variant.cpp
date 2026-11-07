
// src/fallout_shared/teswater_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/teswater.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.


extern int DAT_0109cb9c;
void __fastcall ReleaseStorage_00a5a390(void* p);

struct FUN_00a6fae0_Class
{
    void __thiscall UpdateFields_00a6fae0();
};

// @fnv 0x00a6fae0
// src: GUESS 0x00a6fae0 (confidence: low)
void __thiscall FUN_00a6fae0_Class::UpdateFields_00a6fae0()
{
    *(int*)this = (int)&DAT_0109cb9c;
    ReleaseStorage_00a5a390(this);
}

// Lazily create the shader property for this geometry, picking the shader type by whether the geometry is skinned.

class B9F30MemoryManager
{
  public:
    void* Allocate(unsigned int uiSize);
    void Deallocate(void* pvMem);
};
extern B9F30MemoryManager g_kB9F30MemoryManager;

struct B9F30SkinData
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
    void* m_pkSkinInstance;
};

class B9F30Geometry
{
  public:
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    B9F30SkinData* m_pkSkinData;
};

class B9F30Property
{
  public:
    B9F30Property(B9F30Geometry* pkGeometry, int m_iPassId, ...);

    static void* operator new(unsigned int uiSize)
    {
        return g_kB9F30MemoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_kB9F30MemoryManager.Deallocate(pvMem);
    }

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class B9F30Owner
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    B9F30Property* m_pkProperty;

    B9F30Property* WaterShaderProperty_GetWaterPass(B9F30Geometry* pkGeometry);
};

// @fnv 0x00b69f30
// src: XBOX_PDB 0x00b69f30
B9F30Property* B9F30Owner::WaterShaderProperty_GetWaterPass(B9F30Geometry* pkGeometry)
{
    if (!m_pkProperty)
    {
        if (pkGeometry->m_pkSkinData->m_pkSkinInstance)
            m_pkProperty = new B9F30Property(pkGeometry, 0x289, true, 0, 0);
        else
            m_pkProperty = new B9F30Property(pkGeometry, 0x288, true, 0, 0);
    }
    return m_pkProperty;
}
