#include "../../../../../../../include/hkVector4.h"

// src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster_gs_nogs_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d97a10_Class
{
    void hkKdTreeCollidableRayBundleCaster_getHitFractions(float* p) const;
};
struct S_00d979e0_Inner
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    float unk10;
};
struct S_00d979e0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d979e0_Inner* unk10;
    float hkpKdTreeCollidableRaycaster_getHitFraction() const;
};
struct S_00d98300_Entry
{
    float m_00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    void reset()
    {
        m_00 = 1.0f;
        m_04 = -1;
        m_30 = 0;
        m_10 = -1;
    }
};
struct S_00d98300
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d98300_Entry m_entries[4];
    void ResetEntries();
};
struct NestedFlagBlock
{
    unsigned long blk_00;  // 0x00
    unsigned long blk_04;  // 0x04
    unsigned long blk_08;  // 0x08
    unsigned long blk_0c;  // 0x0c
    unsigned long blk_10;  // 0x10
    unsigned long blk_14;  // 0x14
    unsigned long blk_18;  // 0x18
    unsigned long blk_1c;  // 0x1c
    unsigned long blk_20;  // 0x20
    unsigned long blk_24;  // 0x24
    unsigned long blk_28;  // 0x28
    unsigned long blk_2c;  // 0x2c
    unsigned long blk_30;  // 0x30
    unsigned long blk_34;  // 0x34
    unsigned long blk_38;  // 0x38
    unsigned long blk_3c;  // 0x3c
    unsigned long blk_40;  // 0x40
    unsigned long blk_44;  // 0x44
    unsigned long blk_48;  // 0x48
    unsigned long blk_4c;  // 0x4c
    unsigned long flag;    // 0x50
};
struct FUN_00d979c0_Class
{
    unsigned long dword_00;   // 0x00
    unsigned long dword_04;   // 0x04
    unsigned long dword_08;   // 0x08
    unsigned long dword_0c;   // 0x0c
    NestedFlagBlock* nested;  // 0x10

    bool* GetFlag(bool* out);
};
struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};
struct FUN_00d979f0_cls : SpawnedBase
{
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;

    FUN_00d979f0_cls* ResetFields() throw();
};

#include <xmmintrin.h>
struct Mat4
{
    __m128 r0;
    __m128 r1;
    __m128 r2;
    __m128 r3;
};

struct Ray
{
    struct Node* m_00;
    int unk04;
    Mat4* m_08;
};

struct Frame;

struct Node
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual bool* unk20(bool* flag, Frame* f, void* p);
    virtual void unk24(Frame* f, Ray* a, int b);
};

struct Helper
{
    virtual void unk00();
    virtual bool* unk04(bool* const out, void* key, Ray* a1);
};



struct Frame
{
    Frame() : k40(0), k44(0)
    {}
    hkVector4 r0;
    hkVector4 r1;
    int k40;
    int k44;
};

// hkpWorldRayCastInput (Havok): m_from, m_to, m_enableShapeCollectionFilter +0x20, m_filterInfo +0x24
struct WorldRayCastInput
{
    __m128 v0;
    __m128 v1;
    int unk20;
    int m_24;
};

struct Hdr2
{
    __m128 m_00;
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
    Ray* m_50;
};

static __forceinline void Xform3(hkVector4* out, const __m128& pt, const Mat4* M)
{
    __m128 d = _mm_sub_ps(pt, M->r3);
    __m128 r0 = M->r0;
    __m128 r1 = M->r1;
    __m128 r2 = M->r2;
    __m128 lo = _mm_unpacklo_ps(r0, r1);
    __m128 hi = _mm_unpackhi_ps(r0, r1);
    r0 = _mm_movelh_ps(lo, r2);
    r1 = _mm_shuffle_ps(_mm_movehl_ps(r0, lo), r2, 0xd4);
    r2 = _mm_shuffle_ps(hi, r2, 0xe4);
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(d, d, 0x55), r1);
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(d, d, 0), r0);
    __m128 z = _mm_mul_ps(r2, _mm_shuffle_ps(d, d, 0xaa));
    _mm_store_ps(&out->x, _mm_add_ps(_mm_add_ps(y, x), z));
}

struct Raycaster
{
    int unk00;
    WorldRayCastInput* m_04;
    Helper* m_08;
    int m_0C;
    Hdr2* m_10;
    int m_14;

    bool* hkpKdTreeCollidableRaycaster_addMidPhaseHit(bool* const out, Ray* a1);
};

// @fnv 0x00d97a40
// src: HAVOK_SRC 0x00d97a40
bool* Raycaster::hkpKdTreeCollidableRaycaster_addMidPhaseHit(bool* const out, Ray* a1)
{
    Node* v = a1->m_00;
    if (v)
    {
        bool flag;
        if (!m_08 || *m_08->unk04(&flag, m_04, a1))
        {
            WorldRayCastInput* A = m_04;
            Mat4* M = a1->m_08;
            Frame f;
            Xform3(&f.r0, A->v0, M);
            Xform3(&f.r1, A->v1, M);
            f.k40 = A->m_24;
            f.k44 = m_0C;
            if (m_14)
            {
                v->unk24(&f, a1, m_14);
            }
            else
            {
                v->unk20(&flag, &f, m_10);
                if (flag)
                {
                    m_10->m_50 = a1;
                    __m128& dst = m_10->m_00;
                    __m128 q = dst;
                    __m128 t = _mm_mul_ps(_mm_shuffle_ps(q, q, 0), M->r0);
                    t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(q, q, 0x55), M->r1));
                    t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(q, q, 0xaa), M->r2));
                    dst = t;
                    *out = true;
                    return out;
                }
            }
        }
    }
    *out = false;
    return out;
}
