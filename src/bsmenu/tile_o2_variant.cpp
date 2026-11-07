
// src/bsmenu/tile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsmenu/tile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "Tile__FloatAction.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiBound.h"

struct FUN_00bb79d0_class
{
    void __thiscall TileShaderProperty_SetUseScissorTest(bool value);
};

// @fnv 0x00bb79d0
// src: COMMUNITY 0x00bb79d0
void __thiscall FUN_00bb79d0_class::TileShaderProperty_SetUseScissorTest(bool value)
{
    *(char*)((char*)this + 0xac) = value;
}

extern MemoryManager _g_memoryManager;
void operator delete(void*, unsigned int);
struct NiPoint2;
struct NiColorA;
struct SharedData_S
{
    char pad[0xc];
    int m_uiRefCount;
    void ForwardCall_00a8a670();
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
        {
            ForwardCall_00a8a670();
            ::operator delete(this, 0x10);
        }
    }
};
struct GeomData_S
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual SharedData_S* GetShared();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual unsigned short GetActiveVertexQuantity();
    int pad04;
    unsigned short m_usVertices;
    unsigned short pad0a;
    unsigned short m_usTrianglePoints;
    unsigned short pad0e;
    NiBound m_kBound;
    NiPoint3* m_pkVertex;
    NiPoint3* m_pkNormal;
    NiColorA* m_pkColor;
    NiPoint2* m_pkTexture;
    void NiGeometryData_Replace(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, NiColorA* pkColor,
                      NiPoint2* pkTexture, unsigned short usNumTextureSets, unsigned short eNBTMethod);
};

// @fnv 0x00a670c0
// src: XBOX_PDB 0x00a670c0
void GeomData_S::NiGeometryData_Replace(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, NiColorA* pkColor,
                              NiPoint2* pkTexture, unsigned short usNumTextureSets, unsigned short eNBTMethod)
{
    if (GetShared())
    {
        if (pkVertex != m_pkVertex)
            GetShared()->DecRefCount();
        if (pkNormal != m_pkNormal)
            GetShared()->DecRefCount();
        if (pkColor != m_pkColor)
            GetShared()->DecRefCount();
        if (pkTexture != m_pkTexture)
            GetShared()->DecRefCount();
    }
    else
    {
        if (pkVertex != m_pkVertex)
            _g_memoryManager.Deallocate(m_pkVertex);
        if (pkNormal != m_pkNormal)
            _g_memoryManager.Deallocate(m_pkNormal);
        if (pkColor != m_pkColor)
            _g_memoryManager.Deallocate(m_pkColor);
        if (pkTexture != m_pkTexture)
            _g_memoryManager.Deallocate(m_pkTexture);
    }
    m_usVertices = usVertices;
    m_pkVertex = pkVertex;
    m_pkNormal = pkNormal;
    unsigned short usActive = GetActiveVertexQuantity();
    if (usActive && m_pkVertex)
        m_kBound.ComputeFromPoints(usActive, m_pkVertex);
    m_pkColor = pkColor;
    m_pkTexture = pkTexture;
    m_usTrianglePoints = (m_usTrianglePoints & 0xffe) | (usNumTextureSets & 1) | eNBTMethod;
}
