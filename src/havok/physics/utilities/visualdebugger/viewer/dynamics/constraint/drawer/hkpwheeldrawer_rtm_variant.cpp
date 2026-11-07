// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpwheeldrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpwheeldrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpwheeldrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpwheeldrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00de71d0 FUN_00de71d0: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps1(const float*);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);

struct Matrix
{
    LocalM128 x, y, z, w;
};
struct Dbg
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
    virtual void Line(LocalM128* a, LocalM128* b, unsigned int c, int d, int e);
};

struct Sub
{
    void hkpPrimitiveDrawer_setDisplayHandler(Dbg* d);
};
struct Ops
{
    void setTransformedPos_00c7f640(const Matrix* p, const LocalM128* q);
    void hkVector4_setRotatedDir(const LocalM128* p, const LocalM128* q);
};
struct Ex
{
    void hkpConstraintDrawer_updateCommonParameters(void* a, Matrix* b, Matrix* c);
    void hkpConstraintDrawer_drawBodyFrames(int a, int b);
    void hkpConstraintDrawer_drawPivots(int a, int b);
};

struct Body
{
    LocalM128 unk00, unk10, unk20, unk30, unk40, v50;
    LocalM128 v60, v70, unk80, v90, limitsA0, unkB0, unkC0, vD0;
    LocalM128 unkE0, unkF0, unk100, v110;
};
struct Input
{
    int unk00, unk04, unk08;
    Body* body;
};

struct DrawObject
{
    float m00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float m1c;
    LocalM128 unk20;
    LocalM128 unk30;
    LocalM128 m40;
    LocalM128 m50;
    LocalM128 m60;
    LocalM128 unk70;
    LocalM128 unk80;
    LocalM128 m90;
    LocalM128 unka0;
    LocalM128 unkb0;
    LocalM128 mc0;
    void ComputeValues_00de71d0(Input* a, Dbg* dbg, int p3, int p4);
};

static inline LocalM128 bc(const float& s)
{
    LocalM128 x = _mm_load_ss(&s);
    return _mm_shuffle_ps(x, x, 0);
}

// @fnv 0x00de71d0
// src: GUESS 0x00de71d0 (confidence: low)
void DrawObject::ComputeValues_00de71d0(Input* a, Dbg* dbg, int p3, int p4)
{
    Body* b = a->body;
    Matrix t0, t1;
    LocalM128 q1, vc, vd, x2;

    ((Sub*)&mc0)->hkpPrimitiveDrawer_setDisplayHandler(dbg);
    ((Ex*)this)->hkpConstraintDrawer_updateCommonParameters(a, &t0, &t1);
    ((Ops*)&m50)->setTransformedPos_00c7f640(&t0, &b->v90);
    ((Ops*)&m40)->setTransformedPos_00c7f640(&t1, &b->v50);
    ((Ex*)this)->hkpConstraintDrawer_drawBodyFrames(p3, p4);
    ((Ex*)this)->hkpConstraintDrawer_drawPivots(p3, p4);
    dbg->Line(&m40, &m50, 0xffff0000, p3, p4);

    ((Ops*)&q1)->hkVector4_setRotatedDir(&m90, &b->v60);
    float k = m00 * m1c;
    float s;
    s = (float)((double)k * -0.5);
    vc = _mm_add_ps(_mm_mul_ps(bc(s), q1), m50);
    s = (float)((double)k * 0.5);
    vd = _mm_add_ps(_mm_mul_ps(bc(s), q1), m50);
    dbg->Line(&vc, &vd, 0xff008000, p3, p4);

    float wa = b->limitsA0.y;
    float wb = b->limitsA0.z;
    ((Ops*)&vd)->hkVector4_setRotatedDir(&m90, &b->v70);
    LocalM128 r = _mm_add_ps(_mm_mul_ps(bc(wb), q1), m50);
    float kk = m00 * m1c;
    s = (float)((double)kk * (double)0.1f);
    vc = _mm_add_ps(_mm_mul_ps(bc(s), vd), r);
    s = (float)((double)kk * -(double)0.1f);
    x2 = _mm_add_ps(_mm_mul_ps(bc(s), vd), r);
    dbg->Line(&vc, &x2, 0xffffffff, p3, p4);

    float kf = m00 * m1c;
    LocalM128 x4 = _mm_add_ps(_mm_mul_ps(bc(wa), q1), m50);
    vc = _mm_add_ps(_mm_mul_ps(bc((float)((double)kf * (double)0.1f)), vd), x4);
    x2 = _mm_add_ps(_mm_mul_ps(bc((float)((double)kf * -(double)0.1f)), vd), x4);
    dbg->Line(&vc, &x2, 0xffffffff, p3, p4);

    ((Ops*)&vd)->hkVector4_setRotatedDir(&m90, &b->v110);
    k = m1c * m00;
    x2 = _mm_add_ps(_mm_mul_ps(bc((float)((double)k * -0.5)), vd), m50);
    vc = _mm_add_ps(_mm_mul_ps(bc((float)((double)k * 0.5)), vd), m50);
    dbg->Line(&x2, &vc, 0xffffff00, p3, p4);

    ((Ops*)&vd)->hkVector4_setRotatedDir(&m60, &b->vD0);
    k = m00 * m1c;
    x2 = _mm_add_ps(_mm_mul_ps(bc((float)((double)k * -0.5)), vd), m40);
    vc = _mm_add_ps(_mm_mul_ps(bc((float)((double)k * 0.5)), vd), m40);
    dbg->Line(&x2, &vc, 0xff0000ff, p3, p4);
}
