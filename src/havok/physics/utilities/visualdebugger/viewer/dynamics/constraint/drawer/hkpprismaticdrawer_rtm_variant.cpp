
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprismaticdrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprismaticdrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprismaticdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprismaticdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00de7730 FUN_00de7730: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);

static __forceinline LocalM128 addScaled(LocalM128 base, LocalM128 dir, double d)
{
    float x = (float)d;
    LocalM128 s = _mm_load_ss(&x);
    return _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), dir), base);
}

// The unit keeps its own __m128 (no char lanes, so /GS adds no cookie); hkVector4.h uses it.
#include "../../../../../../../../../include/hkVector4.h"
struct Matrix
{
    hkVector4 col0, col1, col2, col3;
};
struct Shape
{
    int unk000, unk004, unk008, unk00c;
    int unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c;
    hkVector4 unk050, unk060, unk070, unk080, unk090, unk0a0, unk0b0;
    float unk0c0, unk0c4, unk0c8, unk0cc;
};
struct Input
{
    int unk000, unk004, unk008;
    Shape* unk00c;
};
struct Draw
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
    virtual void line(const hkVector4*, const hkVector4*, unsigned int, int, int);
};
struct Member
{
    void hkpPrimitiveDrawer_setDisplayHandler(Draw*);
};
struct Simulation
{
    float unk000, unk004, unk008, unk00c;
    float unk010, unk014, unk018, unk01c;
    float unk020, unk024, unk028, unk02c;
    float unk030, unk034, unk038, unk03c;
    hkVector4 unk040, unk050, unk060, unk070, unk080, unk090, unk0a0, unk0b0;
    Member unk0c0;
    void hkpConstraintDrawer_updateCommonParameters(Input*, Matrix*, Matrix*);
    void hkpConstraintDrawer_drawPivots(int, int);
    void hkpConstraintDrawer_drawBodyFrames(int, int);
    void ComputeValues_00de7730(Input*, Draw*, int, int);
};
extern "C" unsigned int __cdecl PackColorBigEndian(float, float, float, float);

// @fnv 0x00de7730
// src: GUESS 0x00de7730 (confidence: low)
void Simulation::ComputeValues_00de7730(Input* input, Draw* draw, int a, int b)
{
    Shape* shape = input->unk00c;
    unk0c0.hkpPrimitiveDrawer_setDisplayHandler(draw);
    Matrix transform0, transform1;
    hkpConstraintDrawer_updateCommonParameters(input, &transform0, &transform1);
    // Matrix has the hkTransform layout (rotation columns + translation); 0x00c7f640 = hkVector4::_setTransformedPos.
    unk050.setTransformedPos_00c7f640(reinterpret_cast<const hkTransform&>(transform0), shape->unk090);
    unk040.setTransformedPos_00c7f640(reinterpret_cast<const hkTransform&>(transform1), shape->unk050);
    hkpConstraintDrawer_drawPivots(a, b);
    hkpConstraintDrawer_drawBodyFrames(a, b);
    hkVector4 dir0, dir1;
    dir0.hkVector4_setRotatedDir(reinterpret_cast<const hkRotation*>(&unk090), &shape->unk060);   // _setRotatedDir
    dir1.hkVector4_setRotatedDir(reinterpret_cast<const hkRotation*>(&unk090), &shape->unk070);
    draw->line(&unk040, &unk050, 0xffff0000, a, b);
    hkVector4 from, to;
    if (shape->unk0cc != 3.402820018375656e38)
    {
        float x0 = (float)(double)shape->unk0cc;
        LocalM128 s0 = _mm_load_ss(&x0);
        float x1 = (float)(double)shape->unk0c8;
        from.value = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s0, s0, 0), dir0.value), unk050.value);
        LocalM128 s1 = _mm_load_ss(&x1);
        to.value = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s1, s1, 0), dir0.value), unk050.value);
        draw->line(&to, &from, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), a, b);
    }
    else
    {
        float limit = unk01c * unk000;
        from.value = addScaled(unk050.value, dir0.value, limit);
        to.value = addScaled(unk050.value, dir0.value, -limit);
        draw->line(&to, &from, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), a, b);
    }
    LocalM128 centre = addScaled(unk050.value, dir0.value, shape->unk0c8);
    float other = shape->unk0cc;
    float scale = unk01c * unk000;
    from.value = addScaled(centre, dir1.value, 0.5 * scale);
    to.value = addScaled(centre, dir1.value, -0.5 * scale);
    draw->line(&from, &to, 0xffffffff, a, b);
    LocalM128 s = _mm_load_ss(&other);
    centre = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), dir0.value), unk050.value);
    scale = unk01c * unk000;
    from.value = addScaled(centre, dir1.value, 0.5 * scale);
    to.value = addScaled(centre, dir1.value, -0.5 * scale);
    draw->line(&from, &to, 0xffffffff, a, b);
}
