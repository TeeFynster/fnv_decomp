
// src/havok/physics/internal/collide/gjk/hkpgskcache.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/hkpgskcache.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00dafcd0 FUN_00dafcd0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../../include/Vec4.h"

extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps(float const*);
    void _mm_store_ps(float*, LocalM128);
}

extern LocalM128 DAT_010c44d0;

__forceinline Vec4::Vec4(const LocalM128& q) : m_vComponents(q)
{}

class Node
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38(const Vec4& in, void* out);
    virtual void v3c(int* flag, int on, void* out);
};

__declspec(align(16)) struct Vec4Blk
{
    float x;
    float y;
    float z;
    float w;
};

struct Xform
{
    LocalM128 c0;
    LocalM128 c1;
    LocalM128 c2;
    LocalM128 t;
};

class Cls_dafcd0
{
  public:
    short m_00;
    short m_02;
    short m_04;
    short m_06;
    unsigned char m_08;
    unsigned char m_09;
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
    unsigned char m_0b;
    void hkpGskCache_init(Node* a, Node* b, const Vec4Blk* m);
};

// Queries both nodes via v3c, v38 and the matrix m, then stores two shorts and flag bytes, two clamped v2c nibbles, and zeroes m_04, m_06 and m_0b.
// @fnv 0x00dafcd0
// src: XBOX_PDB 0x00dafcd0
void Cls_dafcd0::hkpGskCache_init(Node* apNodeA, Node* apNodeB, const Vec4Blk* apMatrix)
{
    Vec4Blk Q;
    Vec4Blk P;
    Vec4Blk t40;
    Vec4Blk RS;
    Vec4Blk out60;
    {
        int flag = 0;
        apNodeA->v3c(&flag, 1, &t40);
        apNodeB->v3c(&flag, 1, &P);
    }

    LocalM128 pv = _mm_load_ps(&P.x);
    const Xform& X = *(const Xform*)apMatrix;
    LocalM128 R = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(pv, pv, 0x55), X.c1), _mm_mul_ps(_mm_shuffle_ps(pv, pv, 0), X.c0)),
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(pv, pv, 0xaa), X.c2), X.t));
    Vec4 C(_mm_sub_ps(R, _mm_load_ps(&t40.x)));
    apNodeA->v38(C, &Q);

    LocalM128 D = _mm_sub_ps(R, _mm_load_ps(&Q.x));
    LocalM128 c0 = _mm_load_ps(&apMatrix[0].x);
    LocalM128 c1 = _mm_load_ps(&apMatrix[1].x);
    LocalM128 c2 = _mm_load_ps(&apMatrix[2].x);
    {
        LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
        LocalM128 ctmp = _mm_unpackhi_ps(c0, c1);
        c0 = _mm_movelh_ps(tmp, c2);
        tmp = _mm_movehl_ps(c0, tmp);
        c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
        c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    }
    LocalM128 S =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(D, D, 0x55), c1), _mm_mul_ps(_mm_shuffle_ps(D, D, 0), c0)),
                   _mm_mul_ps(_mm_shuffle_ps(D, D, 0xaa), c2));
    C.m_vComponents = D;
    S = _mm_xor_ps(S, DAT_010c44d0);
    apNodeB->v38(Vec4(S), &out60);

    m_02 = *(short*)((char*)&out60 + 0xc);
    m_00 = *(short*)((char*)&Q + 0xc);
    m_04 = 0;
    m_06 = 0;
    m_08 = 1;
    m_09 = 1;

    int n1 = apNodeA->v2c();
    int n2 = apNodeB->v2c();
    if (n1 > 3)
    {
        n1 = 0xf;
    }
    m_ucLowNibble = n1;
    if (n2 > 3)
    {
        n2 = 0xf;
    }
    m_ucHighNibble = n2;
    m_0b = 0;
}

class Iface
{
  public:
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v0A()
    {}
    virtual int v0B()
    {
        return 0;
    }
    virtual void v0C()
    {}
    virtual void v0D()
    {}
    virtual void v0E(void* a, void* b)
    {}
    virtual void v0F(unsigned short* a, int b, void* c)
    {}
};



__declspec(align(16)) struct Mat4
{
    Vec4 r0;
    Vec4 r1;
    Vec4 r2;
    Vec4 r3;
};

// distinct from P3: exe 0x00dafe70 works with three 16-byte SIMD basis columns (48 bytes), not a three-float point.
__declspec(align(16)) struct GskBasisColumns
{
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
};

struct Src
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char m_flag17;
    void* unk18;
    void* unk1C;
    LocalM128 m_v20;
    LocalM128 m_v30;
    LocalM128 m_v40;
};

class FUN_00dafe70_cls
{
  public:
    unsigned short unk00;
    unsigned short m_w2;
    unsigned short m_w4;
    unsigned short m_w6;
    unsigned char m_b8;
    unsigned char m_b9;
    unsigned char m_bA;
    unsigned char m_bB;

    void hkpGskCache_init(Iface* a1, Src* a2, const unsigned int* a3);
    void hkpGskCache_initTriangle(Iface* a1, Src* a2, const unsigned int* a3);
};

extern "C"
{
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
}

static LocalM128 Xf(LocalM128 v, const LocalM128& r0, const LocalM128& r1, const LocalM128& r2, const LocalM128& r3)
{
    LocalM128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), r0);
    LocalM128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), r1);
    LocalM128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), r2);
    return _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, r3));
}

typedef Vec4 UQ; // Shared SIMD storage also supplies the integer lane views.
__declspec(align(16)) struct Frame3
{
    UQ r1;
    UQ r2;
    UQ r3;
};

// @fnv 0x00dafe70
// src: XBOX_PDB 0x00dafe70
void FUN_00dafe70_cls::hkpGskCache_initTriangle(Iface* apIface, Src* apSrc, const unsigned int* apMatrix)
{
    if (apSrc->m_flag17 != 0)
    {
        hkpGskCache_init(apIface, apSrc, apMatrix);
        return;
    }
    m_w2 = 0;
    unsigned short* pWords = &m_w2;
    m_w4 = 1;
    const unsigned int* pMatrix = apMatrix;
    m_w6 = 2;

    UQ row0, row1, row2, row3;
    LocalM128 pv[3];
    row0.xb = pMatrix[0];
    row0.yb = pMatrix[1];
    row0.zb = pMatrix[2];
    row0.wb = pMatrix[3];
    row1.xb = pMatrix[4];
    row1.yb = pMatrix[5];
    row1.zb = pMatrix[6];
    row1.wb = pMatrix[7];
    LocalM128 r0 = row0.v;
    LocalM128 r1 = row1.v;
    row2.xb = pMatrix[8];
    row2.yb = pMatrix[9];
    row2.zb = pMatrix[10];
    row2.wb = pMatrix[11];
    LocalM128 r2 = row2.v;
    row3.xb = pMatrix[12];
    row3.yb = pMatrix[13];
    row3.zb = pMatrix[14];
    row3.wb = pMatrix[15];
    LocalM128 r3 = row3.v;

    const LocalM128* vin = (const LocalM128*)&apSrc->m_v20;
    LocalM128* out = pv;
    for (int k = 2; k >= 0; --k)
    {
        out[k] = Xf(vin[k], r0, r1, r2, r3);
    }

    LocalM128 vMid = pv[1];
    LocalM128 d = _mm_sub_ps(vMid, pv[0]);
    LocalM128 e = _mm_sub_ps(pv[2], vMid);
    LocalM128 t2 = _mm_mul_ps(_mm_shuffle_ps(d, d, 0xc9), _mm_shuffle_ps(e, e, 0xd2));
    LocalM128 t1 = _mm_mul_ps(_mm_shuffle_ps(d, d, 0xd2), _mm_shuffle_ps(e, e, 0xc9));
    UQ hit;
    UQ nq;
    UQ vResult;
    nq.v = _mm_sub_ps(t2, t1);

    apIface->v0F(pWords, 1, &hit);

    LocalM128 dt = _mm_mul_ps(_mm_sub_ps(hit.v, pv[0]), nq.v);
    LocalM128 vSum = _mm_add_ss(_mm_shuffle_ps(dt, dt, 0x55), dt);
    vSum = _mm_add_ss(_mm_shuffle_ps(dt, dt, 0xaa), vSum);
    LocalM128 bc = _mm_shuffle_ps(vSum, vSum, 0);
    nq.v = _mm_xor_ps(_mm_and_ps(bc, DAT_010c44d0), nq.v);

    apIface->v0E(&nq, &vResult);

    unk00 = *(unsigned short*)((char*)&vResult + 0xc);
    m_b8 = 1;
    m_b9 = 3;
    int c = apIface->v0B();
    if (c > 3)
    {
        c = 0xf;
    }
    m_bA = (unsigned char)((c & 0xf) | 0x30);
    m_bB = 0;
}
