// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct CpuObject
{
    int value;
    void hkpPrimitiveDrawer_setDisplayHandler(int value);
};

namespace ArrowDraw {
namespace ArrowDrawMath {
// Exe 0x00e10d50 FUN_00e10d50: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C"
{
    extern LocalM128 _mm_add_ss(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_add_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_sub_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_mul_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_shuffle_ps(LocalM128 _A, LocalM128 _B, unsigned int _Imm8);
    extern LocalM128 _mm_load_ss(float const* _A);
}
}

extern const float DAT_01064f60;
extern float DAT_01016b78;
extern double DAT_010c4ab0;
extern const ArrowDrawMath::LocalM128 DAT_010c71e0;

struct ArrowDrawVector
{
    ArrowDrawMath::LocalM128 m;
    void add(const ArrowDrawVector& a)
    {
        m = ArrowDrawMath::_mm_add_ps(m, a.m);
    }
    ArrowDrawVector& operator=(const ArrowDrawVector& a)
    {
        m = a.m;
        return *this;
    }
};

struct ArrowDrawQuaternion
{
    float x, y, z, w;
    void hkQuaternion_setAxisAngle(int axis, float angle);
};

struct ArrowDrawTarget
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void edge(const ArrowDrawVector* a, const ArrowDrawVector* b, int c, int d, int e);
};

struct ArrowDrawObject : ::CpuObject
{
    void ProcessEntries_00e11180(const ArrowDrawVector* p1, int p2, const ArrowDrawVector* p3, int p4, float p5, int p6, int p7);
    void ComputeValues_00e10d50(const ArrowDrawVector* a0, int a1, const ArrowDrawVector* a2, int a3, float a4, int a5, int a6);
};

static __forceinline ArrowDrawMath::LocalM128 Hk_e10d50_splat(float f)
{
    ArrowDrawMath::LocalM128 v = ArrowDrawMath::_mm_load_ss(&f);
    return ArrowDrawMath::_mm_shuffle_ps(v, v, 0);
}

static __forceinline ArrowDrawMath::LocalM128 Hk_e10d50_rot(const ArrowDrawMath::LocalM128& q, ArrowDrawMath::LocalM128 v)
{
    ArrowDrawMath::LocalM128 w = ArrowDrawMath::_mm_shuffle_ps(q, q, 0xff);
    ArrowDrawMath::LocalM128 ww = ArrowDrawMath::_mm_add_ps(DAT_010c71e0, ArrowDrawMath::_mm_mul_ps(w, w));
    ArrowDrawMath::LocalM128 r = ArrowDrawMath::_mm_mul_ps(v, ww);
    ArrowDrawMath::LocalM128 p = ArrowDrawMath::_mm_mul_ps(q, v);
    ArrowDrawMath::LocalM128 xy = ArrowDrawMath::_mm_add_ss(ArrowDrawMath::_mm_shuffle_ps(p, p, 0x55), p);
    ArrowDrawMath::LocalM128 d = ArrowDrawMath::_mm_add_ss(ArrowDrawMath::_mm_shuffle_ps(p, p, 0xaa), xy);
    d = ArrowDrawMath::_mm_shuffle_ps(d, d, 0);
    r = ArrowDrawMath::_mm_add_ps(r, ArrowDrawMath::_mm_mul_ps(d, q));
    ArrowDrawMath::LocalM128 c = ArrowDrawMath::_mm_sub_ps(
        ArrowDrawMath::_mm_mul_ps(ArrowDrawMath::_mm_shuffle_ps(q, q, 0xc9), ArrowDrawMath::_mm_shuffle_ps(v, v, 0xd2)),
        ArrowDrawMath::_mm_mul_ps(ArrowDrawMath::_mm_shuffle_ps(q, q, 0xd2),
                                  ArrowDrawMath::_mm_shuffle_ps(v, v, 0xc9)));
    r = ArrowDrawMath::_mm_add_ps(r, ArrowDrawMath::_mm_mul_ps(w, c));
    return ArrowDrawMath::_mm_add_ps(r, r);
}

// @fnv 0x00e10d50
// src: GUESS 0x00e10d50 (confidence: low)
void ArrowDrawObject::ComputeValues_00e10d50(const ArrowDrawVector* a0, int a1, const ArrowDrawVector* a2, int a3, float a4,
                                   int a5, int a6)
{
    ArrowDrawVector p1, p2;
    ArrowDrawQuaternion q1, q2;
    p1.m = ArrowDrawMath::_mm_add_ps(ArrowDrawMath::_mm_mul_ps(Hk_e10d50_splat(a4), ((const ArrowDrawVector*)a1)->m),
                                     a0->m);
    ((ArrowDrawTarget*)value)->edge(a0, &p1, a3, a5, a6);
    q1.hkQuaternion_setAxisAngle((int)a2, DAT_01064f60);
    q2.hkQuaternion_setAxisAngle((int)a2, DAT_01016b78);
    double na = -a4;
    ArrowDrawMath::LocalM128 r1 = Hk_e10d50_rot(*(ArrowDrawMath::LocalM128*)&q1, ((const ArrowDrawVector*)a1)->m);
    volatile float s = (float)(na * DAT_010c4ab0);
    ArrowDrawTarget* nextSink = (ArrowDrawTarget*)value;
    p2.m = ArrowDrawMath::_mm_add_ps(ArrowDrawMath::_mm_mul_ps(Hk_e10d50_splat(s), r1), p1.m);
    nextSink->edge(&p1, &p2, a3, a5, a6);
    ArrowDrawMath::LocalM128 r2 = Hk_e10d50_rot(*(ArrowDrawMath::LocalM128*)&q2, r1);
    p2.m = ArrowDrawMath::_mm_add_ps(ArrowDrawMath::_mm_mul_ps(Hk_e10d50_splat(s), r2), p1.m);
    ((ArrowDrawTarget*)value)->edge(&p1, &p2, a3, a5, a6);
}

}
