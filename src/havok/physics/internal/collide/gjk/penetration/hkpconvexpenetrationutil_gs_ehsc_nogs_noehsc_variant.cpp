
// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkpConvexShape.h"

struct Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};
struct Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_auiShapeKeys[4];
    Entry m_usTrailingValue[4];
    void ProcessEntries_00e2d440();
    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
};
struct FUN_00df9c40_Obj
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
    __m128* unk60;
    __m128* unk64;
    __m128* unk68;
    int unk6C;

    void PushVectorTriple(const __m128* src);
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" void _mm_store_ps(float* p, __m128 a);

extern const __m128 DAT_010c44d0;
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);

__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    hkVector4 kC0 = r.m_kColumn0;
    hkVector4 kC1 = r.m_kColumn1;
    hkVector4 kC2 = r.m_kColumn2;
    __m128 tmp = _mm_unpacklo_ps(kC0.m_vComponents, kC1.m_vComponents);
    const __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(kC0.m_vComponents, kC1.m_vComponents), kC2.m_vComponents, 0xe4);
    kC0.m_vComponents = _mm_movelh_ps(tmp, kC2.m_vComponents);
    tmp = _mm_movehl_ps(kC0.m_vComponents, tmp);
    kC1.m_vComponents = _mm_shuffle_ps(tmp, kC2.m_vComponents, 0xd4);
    kC2.m_vComponents = ctmp;
    const __m128 r0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), kC0.m_vComponents);
    const __m128 r1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), kC1.m_vComponents);
    const __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), kC2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const __m128 r0 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), t.m_rotation.m_kColumn0.m_vComponents);
    const __m128 r1 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), t.m_rotation.m_kColumn1.m_vComponents);
    const __m128 r2 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), t.m_rotation.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_vTranslation));
}

struct hkpCdVertexPairDF9B
{
    hkVector4 m_vContactPosition;
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
};

class hkpMinkowskiDF9B
{
  public:
    void UpdateState_00df9b50(const hkVector4& kDirection, hkpCdVertexPairDF9B& kOut) const;

    hkTransform m_kTransform;
    unsigned int unk40, unk44, unk48, unk4C, unk50;
    const hkpConvexShape* m_pShapeA;
    const hkpConvexShape* m_pShapeB;
};

// @fnv 0x00df9b50
// src: GUESS 0x00df9b50 (confidence: low)
void hkpMinkowskiDF9B::UpdateState_00df9b50(const hkVector4& kDirection, hkpCdVertexPairDF9B& kOut) const
{
    m_pShapeA->GetSupportVertex(kDirection, reinterpret_cast<Vector4WithInt24W&>(kOut.m_kVertexA));
    hkVector4 kNegDir;
    kNegDir.setNeg4(kDirection);
    hkVector4 kRotated;
    kRotated._setRotatedInverseDir(m_kTransform.m_rotation, kNegDir);
    hkVector4 kLocalDir;
    kLocalDir = kRotated;
    m_pShapeB->GetSupportVertex(kLocalDir, reinterpret_cast<Vector4WithInt24W&>(kOut.m_kVertexB));
    hkVector4 kBInA;
    kBInA._setTransformedPos(m_kTransform, kOut.m_kVertexB);
    kOut.m_vContactPosition.setSub4(kOut.m_kVertexA, kBInA);
}

extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

template <class T> struct S00df9ef0_Pad
{
    T* m_p;
    __forceinline T* val() const
    {
        return m_p;
    }
    __forceinline T* operator->() const
    {
        return m_p;
    }
};

struct S00df9ef0_Hit
{
    hkVector4 a;
    hkVector4 b;
    hkVector4 c;
    int d;
};

struct S00df9ef0_Obj
{
    void UpdateState_00df9b50(const hkVector4* in, hkVector4* out);

    void ComputeValues_00df9ef0(hkVector4* p, S00df9ef0_Pad<hkVector4> r, S00df9ef0_Hit* q, S00df9ef0_Pad<float> outF);
};

static float S00df9ef0_Dot3(__m128 v)
{
    __m128 s1 = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s1);
    float f;
    _mm_store_ss(&f, s);
    return f;
}

// @fnv 0x00df9ef0
// src: GUESS 0x00df9ef0 (confidence: low)
void S00df9ef0_Obj::ComputeValues_00df9ef0(hkVector4* p, S00df9ef0_Pad<hkVector4> r, S00df9ef0_Hit* q,
                                 S00df9ef0_Pad<float> outF)
{
    S00df9ef0_Hit h;
    hkVector4 neg;
    _mm_store_ps(&neg.x, _mm_xor_ps(_mm_load_ps(&p->x), DAT_010c44d0));
    this->UpdateState_00df9b50(p, &h.a);
    S00df9ef0_Hit* qq = q;
    this->UpdateState_00df9b50(&neg, &qq->a);

    float f1 = S00df9ef0_Dot3(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(&h.a.x), _mm_load_ps(&r->x)), _mm_load_ps(&p->x)));
    float f2 = S00df9ef0_Dot3(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(&qq->a.x), _mm_load_ps(&r->x)), _mm_load_ps(&neg.x)));

    if (f1 >= f2)
    {
        __m128 vb = _mm_load_ps(&h.b.x);
        _mm_store_ps(&qq->a.x, _mm_load_ps(&h.a.x));
        _mm_store_ps(&qq->b.x, vb);
        _mm_store_ps(&qq->c.x, _mm_load_ps(&h.c.x));
        qq->d = h.d;
        *outF.val() = f1;
    }
    else
    {
        *outF.val() = f2;
    }
}

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmplt_ps(__m128 a, __m128 b);
extern "C" int _mm_movemask_ps(__m128 a);

struct Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const hkVector4* m_p0;
    int unk14;
    int unk18;
    int unk1C;
    const hkVector4* m_p1;
    int unk24;
    int unk28;
    int unk2C;
    const hkVector4* m_p2;
};

struct Edges
{
    hkVector4 e0;
    hkVector4 e1;
    hkVector4 e2;
};

struct Result4 : hkVector4
{
    __declspec(noalias) void hkVector4_setRotatedInverseDir(const Edges* edges, const Tri* tri);
};

struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_iThirdValue;
    int m_10;
    int hkWingedEdge_findVisibilityBoundaryEdges(const Tri* tri, const hkVector4* pos, int* outA, int* outB);
    int AllocateTriangleFan(int a, int b, const hkVector4* pos);
};

struct Tester
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
    hkVector4 m_40;
    int ComputeValues_00df9c90(Shape* shape, const Tri* tri, const hkVector4* pos, int* result);
};

// @fnv 0x00df9c90
// src: GUESS 0x00df9c90 (confidence: low)
int Tester::ComputeValues_00df9c90(Shape* shape, const Tri* tri, const hkVector4* pos, int* result)
{
    Edges edges;
    __m128 p = *(const __m128*)pos;
    *(__m128*)&edges.e0 = _mm_sub_ps(p, *(const __m128*)tri->m_p0);
    *(__m128*)&edges.e1 = _mm_sub_ps(p, *(const __m128*)tri->m_p1);
    *(__m128*)&edges.e2 = _mm_sub_ps(p, *(const __m128*)tri->m_p2);
    Result4 bary;
    bary.hkVector4_setRotatedInverseDir(&edges, tri);
    if (_mm_movemask_ps(_mm_cmplt_ps(*(__m128*)&bary, *(__m128*)&m_40)) & 7)
    {
        *result = 0;
        return 1;
    }
    int a = 0;
    int b;
    if (shape->hkWingedEdge_findVisibilityBoundaryEdges(tri, pos, &a, &b))
    {
        *result = 3;
        return 1;
    }
    if (shape->m_iThirdValue - shape->m_10 + 100 < a)
    {
        *result = 2;
        return 1;
    }
    if (shape->AllocateTriangleFan(a, b, pos))
    {
        *result = 3;
        return 1;
    }
    return 0;
}
