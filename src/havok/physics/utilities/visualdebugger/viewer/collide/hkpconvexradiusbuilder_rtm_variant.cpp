// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkAabb.h"
#define FNV_TRANSFORM_NO_SSE
#include "../../../../../../../include/Transform.h"
#undef FNV_TRANSFORM_NO_SSE

namespace bounding_plane_rework {
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    } lanes;
} __m128, LocalM128;
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern const Transform DAT_01268370;
struct Shape
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void getBounds(const Transform*, float, hkAabb*);
};
struct Allocator;
struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
extern Holder* hkMemoryRouter_getInstance();
extern void __cdecl hkArrayUtil__reserve(Allocator*, void*, int, int);
struct PlaneArray
{
    __m128* data;
    int size, capacity;
};
// @fnv 0x00de3200
// src: XBOX_PDB 0x00de3200
static __declspec(noinline) void _addBoundingPlanes(Shape* shape, PlaneArray* planes, float radius)
{
    // getBounds fills uninitialized output storage; do not invoke hkAabb::hkAabb().
    __m128 boundsStorage[sizeof(hkAabb) / sizeof(__m128)];
    hkAabb& bounds = *reinterpret_cast<hkAabb*>(boundsStorage);
    shape->getBounds(&DAT_01268370, radius, &bounds);
    Holder* holder = hkMemoryRouter_getInstance();
    Allocator* allocationHeap = holder->allocator;
    int wanted = planes->size + 6;
    int capacity = planes->capacity & 0x3fffffff;
    if (capacity < wanted)
    {
        int doubled = capacity + capacity;
        if (wanted < doubled)
            wanted = doubled;
        hkArrayUtil__reserve(allocationHeap, planes, wanted, 16);
    }
    planes->size += 6;
    int start = planes->size;
    planes->data[start - 6] = _mm_setr_ps(1.0f, 0.0f, 0.0f, -bounds.m_kMaximumCorner.x);
    planes->data[start - 5] = _mm_setr_ps(0.0f, 1.0f, 0.0f, -bounds.m_kMaximumCorner.y);
    planes->data[start - 4] = _mm_setr_ps(0.0f, 0.0f, 1.0f, -bounds.m_kMaximumCorner.z);
    planes->data[start - 3] = _mm_setr_ps(-1.0f, 0.0f, 0.0f, bounds.m_kMinimumCorner.x);
    planes->data[start - 2] = _mm_setr_ps(0.0f, -1.0f, 0.0f, bounds.m_kMinimumCorner.y);
    planes->data[start - 1] = _mm_setr_ps(0.0f, 0.0f, -1.0f, bounds.m_kMinimumCorner.z);
}
extern "C" void planeBuilderWitness(Shape* shape, PlaneArray* planes, float radius)
{
    _addBoundingPlanes(shape, planes, radius);
}

}
