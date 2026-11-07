
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkVector4.h"
struct HkpStandIn;
struct HkpAllocator
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void release(HkpStandIn* object, unsigned short size) = 0;
};
struct HkpRouter
{
    void* reserved;
    unsigned char padding[12];
    HkpAllocator* allocator;
};
struct HkpStandIn
{
    virtual void v0() = 0;

    void ForwardCall_00e490d0();
    HkpStandIn* FUN_00e01010(int flags);

    unsigned short value;
};
HkpRouter* _D1A0E0GetMemoryRouter();
struct FUN_00e49100_t
{
    int GetNextKey(int key);
};
struct FUN_00e49290_Target
{
// @fnv 0x00e49290
    virtual int FUN_00e49290_f0(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f1(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f2(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f3(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f4(int)
    {
        return 0;
    }
};
struct FUN_00e49290_Owner
{
    unsigned char pad[0x10];
    FUN_00e49290_Target target;
};
struct FUN_00e49290_Data
{
    unsigned char pad0[8];
    int* p8;
    unsigned char pad1[8];
    int* p14;
    unsigned int count;
    unsigned char pad2[4];
    int* p20;
};
struct FUN_00e49290_Class
{
    unsigned char pad[8];
    FUN_00e49290_Data* data;
    FUN_00e49290_Owner* owner;

    int hkpConvexPieceMeshShape_getCollisionFilterInfo(unsigned int index);
};
// src: HAVOK_LIB 0x00e49290
int FUN_00e49290_Class::hkpConvexPieceMeshShape_getCollisionFilterInfo(unsigned int index)
{
    int result;

    if (index < this->data->count)
    {
        int i = this->data->p14[index];
        result = this->data->p8[i + 1];
    }
    else
    {
        result = this->data->p20[index - this->data->count];
    }

    return this->owner->target.FUN_00e49290_f4(result);
}
int hkpConvexPieceMeshShape_ReturnZero();
struct Ref
{
    void FUN_00c905b0() throw();
};
struct P
{
    virtual ~P()
    {}
    int a, b, c;
};
struct S
{
    virtual ~S()
    {}
    int d;
};
struct Ptr
{
    Ref* p;
    ~Ptr()
    {
        p->FUN_00c905b0();
    }
};
struct D : P, S
{
    Ptr m18;
    Ptr m1c;
    __forceinline ~D()
    {}
    void ForwardCall_00e490d0();
};
#include <xmmintrin.h>
inline void* __cdecl operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}

struct ShapeBufferE49
{
    __declspec(align(16)) unsigned char m_data[0x200];
};

class TriangleShapeE49
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kVertices[3];
};

class ShapeContainerE49
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual const TriangleShapeE49* GetShapeForKey(int iKey, ShapeBufferE49& kBuffer) const;
};

class MeshShapeE49
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShapeContainerE49 m_container;
};

struct FaceTableE49
{
    int unk00;
    int unk04;
    int* m_piFaceData;
    int unk0c;
    int unk10;
    int* m_piFaceStart;
    unsigned int m_uiNumFaces;
    int unk1c;
    int* m_piTriangleKeys;
};

class FUN_00e607c0
{
  public:
    FUN_00e607c0(float fRadius);

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkVector4* m_pkVertices;
    int m_iNumVertices;
    MeshShapeE49* m_pkMesh;
    int* m_piKeys;
    int m_iNumKeys;
};

class PieceBaseE49
{
  public:
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
};

class PieceAgentE49
{
  public:
    virtual void unk00();
    int unk04;
    FaceTableE49* m_pkFaces;
    MeshShapeE49* m_pkMesh;
    float m_fBoundRadius;

    FUN_00e607c0* ProcessEntries_00e49120(unsigned int uiIndex, void* pvMemory);
};

class PieceSourceE49 : public PieceBaseE49, public PieceAgentE49
{
  public:
// src: HAVOK_LIB 0x00e49040
    __declspec(noinline) hkBool hkpConvexPieceMeshShape_vertexIsSet(const int* piFace, int m_iEdgeNumber) const
    {
        int iWord = m_iEdgeNumber / 31;
        int iBit = m_iEdgeNumber % 31;
        return (piFace[piFace[0] + iWord + 1] & (1 << iBit)) != 0;
    }
};

// @fnv 0x00e49120
// src: GUESS 0x00e49120 (confidence: low)
FUN_00e607c0* PieceAgentE49::ProcessEntries_00e49120(unsigned int uiIndex, void* pvMemory)
{
    FUN_00e607c0* pkPieces = new (pvMemory) FUN_00e607c0(m_fBoundRadius);
    pkPieces->m_pkMesh = m_pkMesh;

    ShapeBufferE49 kBuffer;
    if (uiIndex < m_pkFaces->m_uiNumFaces)
    {
        int iStart = m_pkFaces->m_piFaceStart[uiIndex];
        const int* piData = m_pkFaces->m_piFaceData;
        const int* j = &piData[iStart];
        pkPieces->m_iNumKeys = *j;
        pkPieces->m_piKeys = (int*)(j + 1);
        hkVector4* pkOut = (hkVector4*)(((unsigned int)pvMemory + 0x3b) & ~15);
        pkPieces->m_pkVertices = pkOut;
        pkPieces->m_iNumVertices = 0;
        for (int i = 0; i < pkPieces->m_iNumKeys; i++)
        {
            int iKey = pkPieces->m_piKeys[i];
            const TriangleShapeE49* pkTriangle = m_pkMesh->m_container.GetShapeForKey(iKey, kBuffer);
            int piFace = 0;
            do
            {
                if (static_cast<PieceSourceE49*>(this)->hkpConvexPieceMeshShape_vertexIsSet(j, i * 3 + piFace))
                {
                    *pkOut = pkTriangle->m_kVertices[piFace];
                    pkOut++;
                    pkPieces->m_iNumVertices++;
                }
                piFace++;
            } while (piFace < 3);
        }
    }
    else
    {
        pkPieces->m_iNumKeys = 1;
        int* piKeys = &m_pkFaces->m_piTriangleKeys[uiIndex - m_pkFaces->m_uiNumFaces];
        pkPieces->m_piKeys = piKeys;
        hkVector4* pkOut = (hkVector4*)(((unsigned int)pvMemory + 0x3b) & ~15);
        pkPieces->m_pkVertices = pkOut;
        pkPieces->m_iNumVertices = 3;
        int iKey = pkPieces->m_piKeys[0];
        const TriangleShapeE49* pkTriangle = m_pkMesh->m_container.GetShapeForKey(iKey, kBuffer);
        pkOut[0] = pkTriangle->m_kVertices[0];
        pkOut[1] = pkTriangle->m_kVertices[1];
        pkOut[2] = pkTriangle->m_kVertices[2];
    }
    return pkPieces;
}

__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
__forceinline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}
struct xAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};
struct xTransform;
typedef __declspec(align(16)) int xShapeBuffer[128];

struct xChild
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void getAabb(const xTransform& t, float tolerance, xAabb& out) const;
};
struct xContainer
{
    virtual void k0();
    virtual void k1();
    virtual int GetFirstKey() const;
    virtual int GetNextShapeKey(int key) const;
    virtual void k4();
    virtual const xChild* GetShapeForKey(int key, xShapeBuffer& buffer) const;
};
struct xShapeBase
{
    virtual void s0();
    int a, b, c;
};
struct xCollection : xShapeBase, xContainer
{
    void hkpConvexPieceMeshShape_getAabb(const xTransform& t, float tolerance, xAabb& out) const;
};

// @fnv 0x00e492d0
// src: XBOX_PDB 0x00e492d0
void xCollection::hkpConvexPieceMeshShape_getAabb(const xTransform& t, float tolerance, xAabb& out) const
{
    out.m_kMinimumCorner.set(3.40282e+38f, 3.40282e+38f, 3.40282e+38f, 0.0f);
    out.m_kMaximumCorner.set(-3.40282e+38f, -3.40282e+38f, -3.40282e+38f, 0.0f);
    xShapeBuffer shapeBuffer;
    for (int key = GetFirstKey(); key != -1; key = GetNextShapeKey(key))
    {
        const xChild* child = GetShapeForKey(key, shapeBuffer);
        xAabb childAabb;
        child->getAabb(t, tolerance, childAabb);
        out.m_kMinimumCorner.setMin4(out.m_kMinimumCorner, childAabb.m_kMinimumCorner);
        out.m_kMaximumCorner.setMax4(out.m_kMaximumCorner, childAabb.m_kMaximumCorner);
    }
}
