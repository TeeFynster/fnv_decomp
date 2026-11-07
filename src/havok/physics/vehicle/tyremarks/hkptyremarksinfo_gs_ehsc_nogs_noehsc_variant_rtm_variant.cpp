// src/havok/physics/vehicle/tyremarks/hkptyremarksinfo_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/tyremarks/hkptyremarksinfo_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/vehicle/tyremarks/hkptyremarksinfo_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/tyremarks/hkptyremarksinfo.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/vehicle/tyremarks/hkptyremarksinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/tyremarks/hkptyremarksinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/V4.h"
#include "../../../../../include/hkpTyremarksWheel.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkStatisticsCollector.h"
#include "../../../../../include/hkVector4.h"
#include <xmmintrin.h>
struct __declspec(align(16)) hkpTyremarkV
{
    float m_uiX, m_uiY, m_uiZ, m_w;
};
struct __declspec(align(16)) hkpTyremark
{
    hkpTyremarkV m_kPointA, m_kPointB;
};
__declspec(noinline) hkpTyremark* __thiscall hkpTyremarksWheel::ComputeIndex(int index)
{
    return &m_data[(m_iMaxNumTyremarks + index) % m_numTyremarks];
}
struct S00e39e90_Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArray<hkpTyremarksWheel*> m_kTyremarksWheels;

    void __thiscall hkpTyremarksInfo_getWheelTyremarksStrips(int arg1, int wheelIndex, hkpTyremark* out);
};

struct Scalar4
{
    __m128 lane;
    Scalar4(float x)
    {
        lane = _mm_load_ss(&x);
    }
    Scalar4(const __m128& x)
    {
        lane = x;
    }
    __m128 expanded() const
    {
        return _mm_shuffle_ps(lane, lane, 0);
    }
    operator float() const
    {
        float x;
        _mm_store_ss(&x, lane);
        return x;
    }
};
__forceinline Scalar4 operator+(const Scalar4& a, const Scalar4& b)
{
    return Scalar4(_mm_add_ss(a.lane, b.lane));
}
inline V4::V4()
{}
inline V4::V4(const V4& other)
{
    q = other.q;
}
inline V4::V4(const __m128& value)
{
    q = value;
}
inline void V4::operator=(const V4& other)
{
    q = other.q;
}
inline void V4::scaled(const Scalar4& scale, const V4& other)
{
    q = _mm_mul_ps(scale.expanded(), other.q);
}
inline Scalar4 V4::laneY() const
{
    return Scalar4(_mm_shuffle_ps(q, q, 0x55));
}
inline Scalar4 V4::laneZ() const
{
    return Scalar4(_mm_shuffle_ps(q, q, 0xaa));
}
inline Scalar4 V4::laneAt(int i) const
{
    switch (i)
    {
    case 0:
        return Scalar4(q);
    case 1:
        return laneY();
    case 2:
        return laneZ();
    default:
        return Scalar4(_mm_shuffle_ps(q, q, 0xff));
    }
}
inline void V4::add(const V4& other)
{
    q = _mm_add_ps(q, other.q);
}

struct P2Sub18
{
    int pad_0;
    int pad_4;
    int pad_8;
    int pad_c;
    int pad_10;
    int pad_14;
    int pad_18;
    int pad_1c;
    int pad_20;
    int pad_24;
    int pad_28;
    int pad_2c;
    int pad_30;
    int pad_34;
    int pad_38;
    int pad_3c;
    int pad_40;
    int pad_44;
    int pad_48;
    int pad_4c;
    int pad_50;
    int pad_54;
    int pad_58;
    int pad_5c;
    int pad_60;
    int pad_64;
    int pad_68;
    int pad_6c;
    int pad_70;
    int pad_74;
    int pad_78;
    int pad_7c;
    int pad_80;
    int pad_84;
    int pad_88;
    int pad_8c;
    int pad_90;
    int pad_94;
    int pad_98;
    int pad_9c;
    int pad_a0;
    int pad_a4;
    int pad_a8;
    int pad_ac;
    int pad_b0;
    int pad_b4;
    int pad_b8;
    int pad_bc;
    int pad_c0;
    int pad_c4;
    int pad_c8;
    int pad_cc;
    int pad_d0;
    int pad_d4;
    int pad_d8;
    int pad_dc;
    int pad_e0;
    int pad_e4;
    int pad_e8;
    int pad_ec;
    V4 f_f0;
    int pad_100;
    int pad_104;
    int pad_108;
    int pad_10c;
    int pad_110;
    int pad_114;
    int pad_118;
    int pad_11c;
    int pad_120;
    int pad_124;
    int pad_128;
    int pad_12c;
    int pad_130;
    int pad_134;
    int pad_138;
    int pad_13c;
    int pad_140;
    int pad_144;
    int pad_148;
    int pad_14c;
    int pad_150;
    int pad_154;
    int pad_158;
    int pad_15c;
    int pad_160;
    int pad_164;
    int pad_168;
    int pad_16c;
    int pad_170;
    int pad_174;
    int pad_178;
    int pad_17c;
    int pad_180;
    int pad_184;
    int pad_188;
    int pad_18c;
    int pad_190;
    int pad_194;
    int pad_198;
    int pad_19c;
    int pad_1a0;
    int pad_1a4;
    int pad_1a8;
    int pad_1ac;
    V4 f_1b0;
};
struct WheelSpec
{
    int unk00;
    int unk04;
    float width;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct P2Sub1c
{
    int pad_0;
    int pad_4;
    int pad_8;
    int pad_c;
    int pad_10;
    int pad_14;
    int pad_18;
    int pad_1c;
    signed char count20;
    char pad_21;
    char pad_22;
    char pad_23;
    int pad_24;
    int pad_28;
    int pad_2c;
    int pad_30;
    int pad_34;
    int pad_38;
    int pad_3c;
    int pad_40;
    int pad_44;
    int pad_48;
    int pad_4c;
    V4 f_50;
    int pad_60;
    int pad_64;
    int pad_68;
    int pad_6c;
    int pad_70;
    int pad_74;
    int pad_78;
    int pad_7c;
    int pad_80;
    int pad_84;
    int pad_88;
    WheelSpec* f_8c;
};
struct Obj
{
    V4 v0;
    V4 v10;
    int pad_20;
    int pad_24;
    int pad_28;
    int pad_2c;
    int pad_30;
    int pad_34;
    int pad_38;
    int pad_3c;
    int pad_40;
    int pad_44;
    int pad_48;
    int pad_4c;
    int pad_50;
    int pad_54;
    int pad_58;
    int pad_5c;
    int pad_60;
    int pad_64;
    int pad_68;
    int pad_6c;
    int pad_70;
    int pad_74;
    int pad_78;
    int pad_7c;
    int pad_80;
    int pad_84;
    int pad_88;
    int pad_8c;
    int pad_90;
    int pad_94;
    int pad_98;
    int pad_9c;
    int pad_a0;
    int pad_a4;
    int pad_a8;
    int pad_ac;
    int pad_b0;
    int pad_b4;
    int pad_b8;
    int pad_bc;
    int pad_c0;
    int pad_c4;
    float f_c8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
};
struct P2
{
    int pad_0;
    int pad_4;
    int pad_8;
    int pad_c;
    int pad_10;
    int pad_14;
    P2Sub18* f18;
    P2Sub1c* f1c;
    int pad_20;
    int pad_24;
    int pad_28;
    int pad_2c;
    int pad_30;
    int pad_34;
    int pad_38;
    int pad_3c;
    int pad_40;
    int pad_44;
    Obj* f48;
};
struct BObj
{
    V4 v0;
    void hkVector4_setRotatedDir(void* a, void* b);
};
class Seg
{
  public:
    V4 v0;
    V4 v1;
    Seg* InitializeFields_00e39e50();
    float GetUnk1C_00e39e80() const;
};
#include "../../../../../include/hkpTyremarksInfo.h"


// src: GUESS 0x00e39e50 (confidence: low)
__declspec(noinline) Seg* Seg::InitializeFields_00e39e50()
{
    *(__m128*)&v0 = _mm_setzero_ps();
    *(__m128*)&v1 = _mm_setzero_ps();
    return this;
}
// src: GUESS 0x00e39e80 (confidence: low)
__declspec(noinline) float Seg::GetUnk1C_00e39e80() const
{
    return v1.w;
}
// src: XBOX_PDB 0x00e39f50
__declspec(noinline) void hkpTyremarksWheel::addTyremarkPoint(hkpTyremark* tyremark)
{
    Seg* o = reinterpret_cast<Seg*>(tyremark);
    if (o->GetUnk1C_00e39e80() != 0.0f || reinterpret_cast<Seg*>(m_data)[(m_iMaxNumTyremarks + m_numTyremarks - 1) % m_numTyremarks].GetUnk1C_00e39e80() != 0.0f)
    {
        *(__m128*)&reinterpret_cast<Seg*>(m_data)[m_iMaxNumTyremarks].v0 = *(__m128*)&o->v0;
        *(__m128*)&reinterpret_cast<Seg*>(m_data)[m_iMaxNumTyremarks].v1 = *(__m128*)&o->v1;
        m_iMaxNumTyremarks = (m_iMaxNumTyremarks + 1) % m_numTyremarks;
    }
}
__forceinline __m128 scalar(float f)
{
    return _mm_load_ss(&f);
}
__forceinline __m128 splat(__m128 f)
{
    return _mm_shuffle_ps(f, f, 0);
}
__forceinline float toFloat(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}

// @fnv 0x00e39fd0
// src: HAVOK_SRC 0x00e39fd0
void hkpTyremarksInfo::updateTyremarksInfo(float p1, void* vehicle)
{
    P2* p2 = static_cast<P2*>(vehicle);
    V4 A;
    A.scaled(p1, p2->f18->f_1b0);
    BObj B;
    B.hkVector4_setRotatedDir(&p2->f18->f_f0, &p2->f1c->f_50);
    for (int i = 0; i < p2->f1c->count20; ++i)
    {
        Obj* obj = &p2->f48[i];
        float energy = obj->f_c8 - m_fMinTyremarkPointDistance;
        if (energy > 0.0f)
        {
            energy *= 255.0 / (m_fMaxTyremarkPointDistance - m_fMinTyremarkPointDistance);
            if (energy > 255.0f)
                energy = 255.0f;
        }
        else
            energy = 0.0f;
        float width = p2->f1c->f_8c[i].width;
        V4 raised;
        raised.scaled(0.05f, obj->v10);
        raised.add(obj->v0);
        Scalar4 left((float)(width * -0.5));
        Scalar4 right((float)(width * 0.5));
        V4 W;
        W.scaled(right, B.v0);
        W.add(raised);
        W.x += A.x;
        W.w += A.w;
        Seg seg;
        seg.InitializeFields_00e39e50();
        seg.v0.scaled(left, B.v0);
        seg.v0.add(raised);
        seg.v0.add(A);
        seg.v0.w = energy;
        seg.v1 = W;
        seg.v1.y = (W.laneAt(1) + A.laneAt(1));
        seg.v1.z = (W.laneAt(2) + A.laneAt(2));
        seg.v1.w = energy;
        m_kTyremarksWheels.m_data[i]->addTyremarkPoint(reinterpret_cast<hkpTyremark*>(&seg));
    }
}
