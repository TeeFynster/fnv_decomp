#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/havok/common/visualize/shape/hkdisplaysemicircle_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/visualize/shape/hkdisplaysemicircle_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/visualize/shape/hkdisplaysemicircle_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/visualize/shape/hkdisplaysemicircle.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/visualize/shape/hkdisplaysemicircle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaysemicircle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

__if_not_exists(__m128)
{
    typedef ::__m128 LocalM128;
}
__if_not_exists(_mm_add_ps)
{
using ::_mm_add_ps;
}
__if_not_exists(_mm_sub_ps)
{
using ::_mm_sub_ps;
}
__if_not_exists(_mm_mul_ps)
{
using ::_mm_mul_ps;
}
__if_not_exists(_mm_load_ss)
{
using ::_mm_load_ss;
}
__if_not_exists(_mm_load_ps)
{
using ::_mm_load_ps;
}
__if_not_exists(_mm_shuffle_ps)
{
using ::_mm_shuffle_ps;
}
__if_not_exists(_mm_store_ps)
{
using ::_mm_store_ps;
}
__if_not_exists(_ReadWriteBarrier)
{
    extern "C" void _ReadWriteBarrier();
}

namespace ArcPointsPrivate {
struct Holder_de4af0
{
    int unk00, unk04, unk08, unk0C;
    void* m_pAllocator;  // +0x10
};
struct Frame_de4af0;
// 16 byte vector stored as four floats. Used as a `this` object and as
// the in-place input/output of the frame transform.
struct Vec_de4af0
{
    union
    {
        LocalM128 v;
        struct
        {
            float m_f00, m_f04, m_f08, m_f0C;
        };
    };
    void add(const Vec_de4af0& a, const Vec_de4af0& b)
    {
        v = _mm_add_ps(a.v, b.v);
    }
    void sub(const Vec_de4af0& a, const Vec_de4af0& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    Vec_de4af0& operator=(const Vec_de4af0& b)
    {
        v = b.v;
        return *this;
    }
    void hkVector4_setRotatedDir(Frame_de4af0* f, Vec_de4af0* v);
};
// Three-column rotation used by the transform helpers.
struct Frame_de4af0
{
    LocalM128 column0, column1, column2;
    void FUN_00cb2e30(void* p, float t);
};
// Output array: data pointer, element count, capacity.
struct VecArr_de4af0
{
    Vec_de4af0* m_pData;  // +0x00
    int m_iArrayLength;         // +0x04
    unsigned int m_uCap;  // +0x08
};
Holder_de4af0* hkMemoryRouter_getInstance();
extern "C" void hkArrayUtil__reserve(void* alloc, VecArr_de4af0* arr, unsigned int newCap, unsigned int stride);
struct ArcSamples_de4af0
{
    int unk00;         // +0x00
    int unk04;         // +0x04
    int unk08;         // +0x08
    int unk0C;         // +0x0c
    int unk10;         // +0x10
    int unk14;         // +0x14
    int unk18;         // +0x18
    int unk1C;         // +0x1c
    int unk20;         // +0x20
    int unk24;         // +0x24
    int unk28;         // +0x28
    int unk2C;         // +0x2c
    int unk30;         // +0x30
    int unk34;         // +0x34
    int unk38;         // +0x38
    int unk3C;         // +0x3c
    int unk40;         // +0x40
    int unk44;         // +0x44
    int unk48;         // +0x48
    int unk4C;         // +0x4c
    int unk50;         // +0x50
    int unk54;         // +0x54
    int unk58;         // +0x58
    int unk5C;         // +0x5c
    Vec_de4af0 m_v60;  // +0x60
    Vec_de4af0 m_v70;  // +0x70
    Vec_de4af0 m_v80;  // +0x80
    float m_f90;       // +0x90
    float m_f94;       // +0x94
    float m_f98;       // +0x98
    int m_i9c;         // +0x9c
    void hkDisplaySemiCircle_generatePoints(VecArr_de4af0* arr);
};
// @fnv 0x00de4af0
// src: XBOX_PDB 0x00de4af0
void ArcSamples_de4af0::hkDisplaySemiCircle_generatePoints(VecArr_de4af0* arr)
{
    const Vec_de4af0& origin = m_v80;
    __declspec(align(16)) float step = (m_f94 - m_f90) / (float)m_i9c;
    Frame_de4af0 local;
    local.FUN_00cb2e30(&m_v60, m_f90);
    Vec_de4af0 x;
    _mm_store_ps(&x.m_f00,
                 _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&m_f98), _mm_load_ss(&m_f98), 0), _mm_load_ps(&m_v70.m_f00)));
    x.hkVector4_setRotatedDir(&local, &x);
    x.add(origin, x);
    local.FUN_00cb2e30(&m_v60, step);
    int n = m_i9c + 2;
    Holder_de4af0* h = hkMemoryRouter_getInstance();
    _ReadWriteBarrier();
    void* alloc = h->m_pAllocator;
    unsigned int cap = arr->m_uCap & 0x3fffffffu;
    if ((int)cap < n)
    {
        unsigned int newCap = cap * 2;
        if (n >= (int)newCap)
        {
            newCap = n;
        }
        hkArrayUtil__reserve(alloc, arr, newCap, 0x10);
    }
    LocalM128 initial = x.v;
    arr->m_iArrayLength = n;
    arr->m_pData[0].v = initial;
    int i = 0;
    if (m_i9c >= i)
    {
        unsigned int off = 0;
        do
        {
            Vec_de4af0 y;
            _mm_store_ps(&y.m_f00, _mm_sub_ps(_mm_load_ps(&x.m_f00), _mm_load_ps(&m_v80.m_f00)));
            y.hkVector4_setRotatedDir(&local, &y);
            y.add(origin, y);
            _mm_store_ps(&arr->m_pData[off + 1].m_f00, _mm_load_ps(&y.m_f00));
            x = y;
            off++;
            i++;
        } while (i <= m_i9c);
    }
}

}
