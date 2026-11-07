
// src/fallout_shared/pathfinding/navmeshobstaclemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/pathfinding/navmeshobstaclemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.


void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl FUN_00ec61c0(void* p, int fill, unsigned int size);
int __cdecl FUN_00ec658f(void(__cdecl* fn)());

struct ArrayHolderBase
{
    virtual void Unk_00();
    int m_04;
    void* m_08;
    unsigned int m_0C;
    bool m_10;
    ArrayHolderBase()
    {
        m_04 = 0x25;
        m_0C = 0;
        m_08 = _NiMalloc_00aa1070(m_04 * 4);
        FUN_00ec61c0(m_08, 0, m_04 * 4);
        m_10 = true;
    }
};

struct ArrayHolder : ArrayHolderBase
{
    virtual ~ArrayHolder()
    {
        m_10 = false;
    }
};

// @fnv 0x00b61890
// src: COMMUNITY 0x00b61890
ArrayHolder* __cdecl TallGrassShaderProperty_GetCachedGeometryMap()
{
    static ArrayHolder obj;
    return &obj;
}
