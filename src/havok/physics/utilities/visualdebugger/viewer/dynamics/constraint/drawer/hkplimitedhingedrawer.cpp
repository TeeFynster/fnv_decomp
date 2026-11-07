
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkplimitedhingedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkplimitedhingedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../../include/hkMemoryRouter.h"

extern const double DAT_01097800;
typedef struct __declspec(intrin_type) __declspec(align(16)) {
    float x, y, z, w;
} __m128, LocalM128;
extern "C"
{
    __m128 _mm_set_ss(float);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps1(const float*);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
}
struct Matrix;
// local form of hkVector4: 0x00de7a70 needs a trivial packet in DrawWork's union; the shared copy constructor makes that union ill-formed.
struct __declspec(align(16)) HingeVectorStorageLocal_00de
{
    __m128 value;
    void setTransformedPos_00c7f640(const Matrix*, const HingeVectorStorageLocal_00de*);
    void hkVector4_setRotatedDir(const void*, const HingeVectorStorageLocal_00de*);
};
struct AxisPair
{
    HingeVectorStorageLocal_00de axis, other;
};
struct Matrix
{
    HingeVectorStorageLocal_00de x, y, z, t;
};
struct Shape
{
    void UpdateState_00de4950(float, float, float, int, const HingeVectorStorageLocal_00de*, const HingeVectorStorageLocal_00de*, const HingeVectorStorageLocal_00de*);
};
struct Array
{
    Shape** data;
    int size;
    int capacity;
};
struct LineScratch
{
    HingeVectorStorageLocal_00de end, base, axis;
};
union DrawWork
{
    LineScratch line;
    Array shapes;
};
struct Allocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void freeBuffer(void*, int);
};
void __cdecl hkArrayUtil__reserve(Allocator*, Array*, int, int);
unsigned __cdecl PackColorBigEndian(float, float, float, float);
struct Display
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void line(const HingeVectorStorageLocal_00de*, const HingeVectorStorageLocal_00de*, unsigned, int, int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void geometry(Array*, unsigned, int, int);
};
struct DisplayContext
{
    int a, b, c, d;
    void hkpPrimitiveDrawer_setDisplayHandler(Display*);
};
// hkpLimitedHingeConstraintData seen as 16-byte rows (constraint instance +0xc): header row, atom transforms/axes, angle-limit enable byte, min/max angle
struct LimitedHingeDataView
{
    HingeVectorStorageLocal_00de v00, v10, v20, v30, v40, v50, v60, v70, v80, v90, va0, vb0;
    char c0, c1, enabled, c3;
    float minimum, maximum;
};
struct Input
{
    int a, b, c;
    LimitedHingeDataView* data;
};
struct Viewer
{
    float length, scale;
    int f08, f0c, f10, f14, flags;
    float multiplier;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    HingeVectorStorageLocal_00de pivot, origin;
    HingeVectorStorageLocal_00de m60, m70, m80, m90, ma0, mb0;
    DisplayContext context;
    Shape shape;
    void hkpConstraintDrawer_updateCommonParameters(Input*, Matrix*, Matrix*);
    void hkpConstraintDrawer_drawBodyFrames(int, int);
    void hkpConstraintDrawer_drawPivots(int, int);
    void DrawHingeConstraintGeometry(Input*, Display*, int, int);
};
__forceinline __m128 broadcast(float value)
{
    float low = value;
    return _mm_load_ps1(&low);
}
__forceinline __m128 broadcastScalar(float value)
{
    float low = value;
    __m128 v = _mm_load_ss(&low);
    return _mm_shuffle_ps(v, v, 0);
}
// Draws lines via display->line and, when data->enabled and the range is small, a shape via display->geometry, using vectors transformed from input->data.
// @fnv 0x00de7a70
// src: GUESS 0x00de7a70 (confidence: medium)
void Viewer::DrawHingeConstraintGeometry(Input* input, Display* display, int id, int tag)
{
    LimitedHingeDataView* data = input->data;
    context.hkpPrimitiveDrawer_setDisplayHandler(display);
    Matrix first, second;
    hkpConstraintDrawer_updateCommonParameters(input, &first, &second);
    origin.setTransformedPos_00c7f640(&first, &data->v90);
    pivot.setTransformedPos_00c7f640(&second, &data->v50);
    hkpConstraintDrawer_drawBodyFrames(id, tag);
    hkpConstraintDrawer_drawPivots(id, tag);
    AxisPair axes;
    DrawWork scratch;
    axes.axis.hkVector4_setRotatedDir(&m90, &data->v60);
    axes.other.hkVector4_setRotatedDir(&m90, &data->v80);
    display->line(&pivot, &origin, 0xffff0000, id, tag);
    {
        float distance = length * multiplier;
        scratch.line.axis.value =
            _mm_add_ps(origin.value, _mm_mul_ps(broadcastScalar(0.75 * distance), axes.axis.value));
        scratch.line.base.value =
            _mm_add_ps(origin.value, _mm_mul_ps(broadcastScalar(DAT_01097800 * distance), axes.axis.value));
        display->line(&scratch.line.base, &scratch.line.axis, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), id, tag);
    }
    {
        scratch.line.axis.hkVector4_setRotatedDir(&m60, &data->v20);
        float distance = length * multiplier;
        scratch.line.base.value =
            _mm_add_ps(pivot.value, _mm_mul_ps(broadcastScalar(0.75 * distance), scratch.line.axis.value));
        scratch.line.end.value =
            _mm_add_ps(pivot.value, _mm_mul_ps(broadcastScalar(DAT_01097800 * distance), scratch.line.axis.value));
        display->line(&scratch.line.end, &scratch.line.base, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), id, tag);
    }
    if (data->enabled)
    {
        float high = data->maximum, low = data->minimum;
        if (high - low < 100000000376832.0)
        {
            shape.UpdateState_00de4950(scale * multiplier, low, high, flags, &origin, &axes.axis, &axes.other);
            scratch.shapes.data = 0;
            scratch.shapes.size = 0;
            scratch.shapes.capacity = 0x80000000;
            hkMemoryRouter* router = &hkMemoryRouter::getInstance();
            Allocator* allocator = reinterpret_cast<Allocator*>(router->m_heap);
            int capacity = scratch.shapes.capacity & 0x3fffffff;
            if (capacity < 1)
            {
                capacity *= 2;
                if (capacity <= 1)
                    capacity = 1;
                hkArrayUtil__reserve(allocator, &scratch.shapes, capacity, 4);
            }
            scratch.shapes.size = 1;
            scratch.shapes.data[0] = &shape;
            display->geometry(&scratch.shapes, 0xffffffff, id, tag);
            router = &hkMemoryRouter::getInstance();
            allocator = reinterpret_cast<Allocator*>(router->m_heap);
            scratch.shapes.size = 0;
            if ((scratch.shapes.capacity & 0x80000000) == 0)
                allocator->freeBuffer(scratch.shapes.data, (scratch.shapes.capacity & 0x3fffffff) * 4);
        }
    }
    {
        float distance = length * multiplier;
        scratch.line.base.value = origin.value;
        scratch.line.end.value = scratch.line.base.value;
        scratch.line.end.value =
            _mm_add_ps(scratch.line.end.value, _mm_mul_ps(broadcastScalar(0.5 * distance), axes.other.value));
        display->line(&scratch.line.base, &scratch.line.end, 0xffffff00, id, tag);
    }
    {
        scratch.line.axis.hkVector4_setRotatedDir(&m60, &data->v40);
        float distance = length * multiplier;

        float magnitude = float(0.75 * distance);
        __m128 squared = _mm_mul_ps(scratch.line.axis.value, scratch.line.axis.value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), sum);
        __m128 inv = _mm_rsqrt_ss(sum);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 half = _mm_set_ss(0.5f);
        __m128 factor = _mm_mul_ss(_mm_mul_ss(half, inv), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(sum, inv), inv)));
        factor = _mm_andnot_ps(_mm_cmpeq_ss(sum, zero), factor);
        scratch.line.axis.value = _mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), scratch.line.axis.value);
        scratch.line.base.value = pivot.value;
        scratch.line.end.value = pivot.value;
        scratch.line.end.value =
            _mm_add_ps(scratch.line.end.value, _mm_mul_ps(broadcastScalar(magnitude), scratch.line.axis.value));
        display->line(&scratch.line.base, &scratch.line.end, 0xffffff00, id, tag);
    }
}
