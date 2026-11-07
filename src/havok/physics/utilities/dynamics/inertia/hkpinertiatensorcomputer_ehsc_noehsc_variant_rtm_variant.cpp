#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#include "../../../../../../include/Vec4.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
#include "../../../../../../include/hkGeometry.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/Transform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpMassProperties.h"
#include "../../../../../../include/hkAabb.h"
// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Object
{
};
void __cdecl Hkpinertiatensorcomputer_CopyAndScalePropertyBlock(float* source, float value, Object* destination);
void __cdecl hkpInertiaTensorComputer_setAndScaleToDensity(float* source, float scale, Object* destination);
struct Receiver
{
    void SetScalarAndRescaleVector(float value);
};
struct State
{
    int first;
    int count;
    int context;
};
void hkpInertiaTensorComputer_computeConvexHullMassProperties(void* state, float zero, void* receiver);
int __cdecl ApplyLimitToReceiver(int owner, int context, int count, float limit, Receiver* receiver, float value);

void __cdecl hkpInertiaTensorComputer_shiftInertiaToCom(const hkVector4& shift, float mass, hkMatrix3& inertia);
void __cdecl AddInertiaTensor(float* param_1, float fScale, float* pMatrix);
struct FUN_00cec6b0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    float m_64;
    float m_68;
    float m_6C;
    float m_70;
    float m_74;
    float m_78;
    float m_7C;
    float m_80;
    float m_84;
    float m_88;

    void InternalInertiaTensorComputer_computeInertialTensorInternal(float a1, float b, float* p, float* M);
};
struct CECCD0Value
{
    float m_uiFilterValue;

    void set(float v);
    void ScaleValue(float scale);
};
struct S_00ced230_T
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
};
static inline float S_MaxGT(float x, float y)
{
    return (x > y) ? x : y;
}
static inline float S_MaxLT(float x, float y)
{
    return (x < y) ? y : x;
}
void __cdecl hkpInertiaTensorComputer_clipInertia(float afDivisor, S_00ced230_T* pData);


struct S_00cee1c0_Arr
{
    unsigned int* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    unsigned int* m_pTrailingData;
};
hkMemoryRouter* hkMemoryRouter_getInstance();
float __cdecl hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(S_00cee1c0_Arr* arr, int unk, float value);
void __cdecl ProcessArrayWithValue(unsigned int* source, int count, int unk, float value);
namespace fnv_anon_00cec3d0 {}
using namespace fnv_anon_00cec3d0;
namespace fnv_anon_00cec3d0 {
struct S00cec3d0_Base
{
    int A;
    int B;
    int C;
    float P1;
    float Pa;
    float Pb;
    float m_fComponent0;
    float m_fComponent1;
    float m_fComponent2;
    float m_fComponent3;
    float m_fComponent4;
    float m_fComponent5;
    float m_fComponent6;

    __declspec(noinline) void InternalInertiaTensorComputer_compProjectionIntegrals(const float* v);
};
}
struct S00cec3d0_Face : S00cec3d0_Base
{
    float Fa;
    float Fb;
    float Fc;
    float m_fVertex0X;
    float m_fVertex0Y;
    float m_fVertex0Z;
    float m_fVertex1X;
    float m_fVertex1Y;
    float m_fVertex1Z;
    float m_fVertex2X;
    float m_fVertex2Y;
    float m_fVertex2Z;

    void InternalInertiaTensorComputer_compFaceIntegrals(const float* verts, const float* n);
};
static inline float S00cec3d0_Sqr(float x)
{
    return x * x;
}
static inline float S00cec3d0_Cube(float x)
{
    return x * x * x;
}
// src: HAVOK_LIB 0x00cec000
void S00cec3d0_Base::InternalInertiaTensorComputer_compProjectionIntegrals(const float* v)
{
    P1 = v[A] * v[B];
    Pa = v[A];
}

extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_setzero_ps();
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
}

struct Matrix
{
    hkVector4 c0, c1, c2;
};

extern const hkVector4 DAT_01017d10;
void HkgeometryutilityGsEhscNogsNoehsc_ComputeValues_00d5ac50(char*, Matrix*, hkVector4*, hkVector4*, hkVector4*);
struct Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void getAabb(const Transform*, float, hkAabb*);
};
void Object_GetAABBExtentAxes(Shape* shape, const Matrix* input, hkVector4* outA, hkVector4* outB);
struct MotionLike
{
    int unk00;
    float field04;
    int unk08;
    int unk0c;
    __m128 field10;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    __m128 field50;
    __m128 field60;
    __m128 field70;
    __m128 field80;
    float field90;
};
void Hkpinertiatensorcomputer_CopySelectedSourceFields(const MotionLike* source, MotionLike* destination);
extern "C" __m128 _mm_load_ss(const float*);
struct Sub
{
    void Multiply(const hkVector4* p);
};
struct Owner
{
    int unk00;
    float m04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    Sub m20;
};
static void hkMatrix3_mul(Owner* self, float value);
Owner* volatile g_owner;
volatile float g_value;
Owner* volatile g_sink;
void caller();

extern const double DAT_010cbf40;
// src: XBOX_PDB 0x00ceba60
static __declspec(noinline) void __cdecl hkpInertiaTensorComputer_computeSphereVolumeMassProperties(float a, float b, hkpMassProperties* out)
{
    out->m_kCenterOfMass1.m_vComponents = _mm_setzero_ps();
    out->m_iBufferSize = a * b;
    out->m_fViscosityFriction = a + b;
}
void(__cdecl* g_S00ceccf0_fp)(float, float, hkpMassProperties*) = &hkpInertiaTensorComputer_computeSphereVolumeMassProperties;
// src: XBOX_PDB 0x00cebfd0
static __declspec(noinline) void hkMatrix3_mul(hkpMassProperties* out, float value)
{
    out->m_iBufferSize *= value;
    out->m_fViscosityFriction *= value;
}
int __cdecl hkpInertiaTensorComputer_computeSphereVolumeMassProperties_UpdateState_00ceccf0(float start, float span, float t, hkpMassProperties* out);
// Incident-edge walk: detach edges touching `unk`, recurse to the other end,
// then fold the node's inertia diagonal with the children's sum and max.
// Local array is an inplace hkArray (cap 16, dont-free flag 0x80000000).
struct Edge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int n14;
    int n18;
};
// local form of hkMatrix3: 0x00cee290 needs a trivial 0x30-byte scalar matrix beside the separately constructed hkMatrix3; sharing the latter adds constructor/assignment calls.
struct __declspec(align(16)) InertiaMatrixPodLocal_00ce
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
};
struct ShapeIface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void getInertia(InertiaMatrixPodLocal_00ce* out);
};
struct Node
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    ShapeIface shape;
    int unkE4;
    char kind;
    bool isStatic() const
    {
        return kind == 5 || kind == 4;
    }
    ShapeIface* getMotion()
    {
        return &shape;
    }
    void hkpRigidBody_setInertiaLocal(InertiaMatrixPodLocal_00ce* m);
};
struct LocalArr
{
    Edge** m_data;
    int m_iElementCount;
    int m_cap;
    Edge* storage[16];
};
void __cdecl ResizeAudioStream(void* heap, void* array, int elemSize);
__forceinline void releaseArr(LocalArr* a)
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    hkMemoryAllocator* heap = router->m_heap;
    int cap = a->m_cap;
    a->m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
        heap->bufFree(a->m_data, (cap & 0x3fffffff) * 4);
}
__forceinline float fMinimumInputValue(float a, float b)
{
    return a > b ? a : b;
}
__forceinline float fTargetUpperBound(float a, float b)
{
    return a < b ? a : b;
}
float __cdecl hkInertiaTensorComputer_optimizeInertiasOfConstraintTreeInt(S_00cee1c0_Arr* arr, int unk, float value);

extern "C" void _mm_store_ps(float*, __m128);
struct Probe
{
    unsigned char flag;
    unsigned char status1;
    unsigned char status2;
    unsigned char status3;
    int next;
    int previous;
    int index;
};
struct Track
{
    int stage;
    int frame;
    int sequence;
    int timer;
    int interpolation;
    void FUN_00d76ca0();
    void hkgpConvexHull_build_00d77200(void* state, Probe* probe);
    int GetInnerField1A8();
    void ForwardCall_00d762f0();
    float GetMass();
    double hkgpConvexHull_getVolume();
    __m128* hkgpConvexHull_getCenterOfMass();
    __m128* hkgpConvexHull_getWorldInertia();
    void hkgpConvexHull_expandByPlanarMargin(float scale);
    void ReleaseStorage_00d76940();
};
struct RowMatrix
{
    __m128 row0, row1, row2;
    void Multiply(const Vec4* weight);
};
struct Receiver2
{
    float time;
    float enabled;
    float pad08;
    float pad0c;
    __m128 translation;
    RowMatrix matrix;
};
struct Status
{
    void hkgpConvexHull_BuildConfig_BuildConfig();
};
extern float DAT_011b153c;
extern double DAT_01020998;
extern double DAT_010cbf50;
extern double DAT_010cbf48;
inline __m128 scalarVector(float x)
{
    __m128 result = {x};
    return result;
}
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _ReadWriteBarrier();
int __cdecl hkpInertiaTensorComputer_computeConvexHullMassProperties(void* state, float value, Receiver2* receiver);


static __forceinline float S_Max(float a, float b)
{
    return a > b ? a : b;
}
static __forceinline void S_SetZero(hkMatrix3* m)
{
    __m128 z = _mm_setzero_ps();
    _ReadWriteBarrier();
    _mm_store_ps(&m->m_kColumn0.x, z);
    _mm_store_ps(&m->m_kColumn1.x, z);
    _mm_store_ps(&m->m_kColumn2.x, z);
}
void __cdecl SetDiagonal(hkMatrix3* m);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
}
struct S_00ced090_Elem
{
    float unk00;
    float unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
};

struct S_00ced090_State
{
    S_00ced090_Elem* first;
    int count;
};

void __cdecl AddInertiaTensor(hkVector4* d, float m, hkMatrix3* mat);
int __cdecl hkpInertiaTensorComputer_combineMassProperties(S_00ced090_State* s, hkpMassProperties* out);
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern __declspec(thread) int DAT_012722b4;
struct S00cf0f40_Guard
{
    int m_saved;
    S00cf0f40_Guard()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cf0f40_Guard()
    {
        DAT_012722b4 = m_saved;
    }
};
struct S00cf0f40_Stream
{
    int unk00;
    unsigned int m_pos;
    unsigned int(__cdecl* m_read)(S00cf0f40_Stream* self, void* dst, unsigned int size, unsigned int* comp,
                                  unsigned int n);
    unsigned int BinaryRead(void* p, unsigned int size, unsigned int* comp, unsigned int n)
    {
        unsigned int r = m_read(this, p, size, comp, n);
        m_pos += r;
        return r;
    }
};
inline unsigned int S00cf0f40_Load(S00cf0f40_Stream& s, unsigned int* p, unsigned int n)
{
    unsigned int uiSize = sizeof(unsigned int);
    return s.BinaryRead(p, n * sizeof(unsigned int), &uiSize, 1);
}
struct S00cf0f40_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
    unsigned char unk1E6;
    unsigned char unk1E7;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    S00cf0f40_Stream* m_stream;
};
struct S00cf0f40_Vec
{
    unsigned int x, y, z, w;
};
struct S00cf0f40_Arr;
inline hkMemoryAllocator& S00cf0f40_heap(hkMemoryRouter* r)
{
    return *r->m_heap;
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* heap, void* arr, int cap, int elemSize);
struct S00cf0f40_Arr
{
    S00cf0f40_Vec* m_data;
    int m_iElementCount;
    int m_capFlags;

    int getCapacity() const
    {
        return m_capFlags & 0x3fffffff;
    }
    void ClearAndRelease()
    {
        hkMemoryAllocator& heap = S00cf0f40_heap(hkMemoryRouter_getInstance());
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            heap.bufFree(m_data, getCapacity() * sizeof(S00cf0f40_Vec));
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    void reserve(int n)
    {
        hkMemoryAllocator& heap = S00cf0f40_heap(hkMemoryRouter_getInstance());
        int cap = getCapacity();
        if (cap < n)
        {
            int nc = cap * 2;
            hkArrayUtil__reserve(&heap, this, n < nc ? nc : n, sizeof(S00cf0f40_Vec));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
inline void S00cf0f40_Swap4(void* p)
{
    unsigned int t;
    memcpy(&t, p, 4);
    t = _byteswap_ulong(t);
    memcpy(p, &t, 4);
}
unsigned int __cdecl bhkStream_LoadBinary(S00cf0f40_Owner* owner, S00cf0f40_Arr* arr);

#include <math.h>
extern "C"
{
    __m128 _mm_setzero_ps();
    __m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

// VC9 changes scheduling when the register union exposes integer lanes.
// Keep float-only intrinsic registers while using the shared object layouts.
namespace InertiaSimd {
// Exe 0x00cee290 FUN_00cee290: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
typedef LocalM128 Quad;
extern "C" {
Quad _mm_setzero_ps(); Quad _mm_load_ss(const float*); void _mm_store_ss(float*, Quad);
Quad _mm_set_ss(float); Quad _mm_add_ss(Quad,Quad); Quad _mm_mul_ss(Quad,Quad);
Quad _mm_sqrt_ss(Quad); Quad _mm_rsqrt_ss(Quad); Quad _mm_cmpeq_ss(Quad,Quad);
Quad _mm_add_ps(Quad,Quad); Quad _mm_sub_ps(Quad,Quad); Quad _mm_mul_ps(Quad,Quad);
Quad _mm_sub_ss(Quad,Quad); Quad _mm_andnot_ps(Quad,Quad);
Quad _mm_shuffle_ps(Quad,Quad,unsigned int);
}
static __forceinline Quad& packet(hkVector4& v) { return *reinterpret_cast<Quad*>(&v); }
static __forceinline const Quad& packet(const hkVector4& v) { return *reinterpret_cast<const Quad*>(&v); }
static __forceinline Quad dot3ScalarCall(const hkVector4& v, const hkVector4& a)
{
    Quad x2 = _mm_mul_ps(packet(v), packet(a));
    Quad xySum = _mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);
    return _mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),xySum);
}
static __forceinline float length3ScalarCall(const hkVector4& v)
{
    float f; _mm_store_ss(&f,_mm_sqrt_ss(dot3ScalarCall(v,v))); return f;
}
static __forceinline void addMul4(hkVector4& dst, float scalar, const hkVector4& v)
{
    Quad r = _mm_load_ss(&scalar);
    packet(dst) = _mm_add_ps(packet(dst),_mm_mul_ps(_mm_shuffle_ps(r,r,0),packet(v)));
}
}
typedef float hkReal;
__forceinline hkVector4::hkVector4(const hkVector4& v) { InertiaSimd::packet(*this) = InertiaSimd::packet(v); }
__forceinline void hkVector4::operator=(const hkVector4& v) { InertiaSimd::packet(*this) = InertiaSimd::packet(v); }
__forceinline void hkVector4::setZero4() { InertiaSimd::packet(*this) = InertiaSimd::_mm_setzero_ps(); }
__forceinline void hkVector4::add4(const hkVector4& v)
{ InertiaSimd::packet(*this) = InertiaSimd::_mm_add_ps(InertiaSimd::packet(*this),InertiaSimd::packet(v)); }
__forceinline void hkVector4::setSub4(const hkVector4& a,const hkVector4& b)
{ InertiaSimd::packet(*this) = InertiaSimd::_mm_sub_ps(InertiaSimd::packet(a),InertiaSimd::packet(b)); }
__forceinline void hkVector4::setMul4(float scalar,const hkVector4& v)
{
    InertiaSimd::Quad r = InertiaSimd::_mm_load_ss(&scalar);
    InertiaSimd::packet(*this) = InertiaSimd::_mm_mul_ps(InertiaSimd::_mm_shuffle_ps(r,r,0),InertiaSimd::packet(v));
}
__forceinline void hkVector4::setCross(const hkVector4& a,const hkVector4& b)
{
    using namespace InertiaSimd;
    Quad c0 = InertiaSimd::_mm_mul_ps(InertiaSimd::_mm_shuffle_ps(InertiaSimd::packet(a),InertiaSimd::packet(a),0xc9),InertiaSimd::_mm_shuffle_ps(InertiaSimd::packet(b),InertiaSimd::packet(b),0xd2));
    Quad c1 = InertiaSimd::_mm_mul_ps(InertiaSimd::_mm_shuffle_ps(InertiaSimd::packet(a),InertiaSimd::packet(a),0xd2),InertiaSimd::_mm_shuffle_ps(InertiaSimd::packet(b),InertiaSimd::packet(b),0xc9));
    InertiaSimd::packet(*this) = InertiaSimd::_mm_sub_ps(c0,c1);
}
__forceinline void hkVector4::normalize3()
{
    using namespace InertiaSimd;
    const Quad half = InertiaSimd::_mm_set_ss(0.5f);
    const Quad three = InertiaSimd::_mm_set_ss(3.0f);
    const Quad zero = InertiaSimd::_mm_set_ss(0.0f);
    const Quad len2 = InertiaSimd::dot3ScalarCall(*this,*this);
    const Quad isZero = InertiaSimd::_mm_cmpeq_ss(len2,zero);
    const Quad approx = InertiaSimd::_mm_rsqrt_ss(len2);
    const Quad refined = InertiaSimd::_mm_mul_ss(InertiaSimd::_mm_mul_ss(half,approx),InertiaSimd::_mm_sub_ss(three,InertiaSimd::_mm_mul_ss(InertiaSimd::_mm_mul_ss(len2,approx),approx)));
    Quad inv = InertiaSimd::_mm_andnot_ps(isZero,refined);
    Quad lenInv = InertiaSimd::_mm_shuffle_ps(inv,inv,0);
    InertiaSimd::packet(*this) = InertiaSimd::_mm_mul_ps(lenInv,InertiaSimd::packet(*this));
}

__forceinline hkReal& hkVector4::operator()(int a)
{
        return reinterpret_cast<hkReal*>(&InertiaSimd::packet(*this))[a];
    }

__forceinline const hkReal& hkVector4::operator()(int a) const
{
        return reinterpret_cast<const hkReal*>(&InertiaSimd::packet(*this))[a];
    }

__forceinline hkMatrix3::hkMatrix3()
{}

__forceinline hkVector4& hkMatrix3::getColumn(int x)
{
        return (&m_kColumn0)[x];
    }

__forceinline const hkVector4& hkMatrix3::getColumn(int x) const
{
        return (&m_kColumn0)[x];
    }

__forceinline hkReal& hkMatrix3::operator()(int r, int c)
{
        return getColumn(c)(r);
    }

__forceinline void hkMatrix3::operator=(const hkMatrix3& a)
{
        m_kColumn0 = a.getColumn(0);
        m_kColumn1 = a.getColumn(1);
        m_kColumn2 = a.getColumn(2);
    }

__forceinline void hkMatrix3::setZero()
{
        hkVector4 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }

__forceinline hkpMassProperties::hkpMassProperties() : m_iBufferSize(0.0f), m_fViscosityFriction(0.0f)
{
        m_kCenterOfMass1.setZero4();
        m_kInertiaTensor.setZero();
    }

template <typename TYPE> __forceinline TYPE* hkMemoryAllocator::_bufAlloc(int& reqNumInOut)
{
        const int SIZE_ELEM = sizeof(TYPE);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = bufAlloc(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<TYPE*>(p);
    }

template <typename TYPE> __forceinline void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
        const int SIZE_ELEM = sizeof(TYPE);
        bufFree(p, numElem * SIZE_ELEM);
    }


__forceinline hkMemoryRouter& hkMemoryRouter::getInstance()
{
        return *hkMemoryRouter_getInstance();
    }

// hkArrayBase / hkArray / hkInplaceArray / hkContainerHeapAllocator: include/hkArray.h (via hkGeometry.h);
// the bodies this unit uses are defined here.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(&alloc, this, newSize, sizeof(T));
    }
}
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}

__forceinline hkGeometry::hkGeometry()
{
}
__forceinline void hkGeometry::Triangle::set(int a, int b, int c, int material)
{
    m_kPointA = a;
    m_kPointB = b;
    m_iThirdValue = c;
    m_iMaterialIndex = material;
}
template <typename T> static __forceinline T* inertiaExpand(hkArray<T>& a, int n)
{
    hkMemoryAllocator& alloc = hkContainerHeapAllocator().get(&a);
    int oldsize = a.m_iElementCount;
    int count = a.m_iElementCount + n;
    int capacity = a.m_iCapacityState & 0x3fffffff;
    if (capacity < count)
    {
        int cap2 = 2 * capacity;
        hkArrayUtil__reserve(&alloc, &a, count < cap2 ? cap2 : count, sizeof(T));
    }
    a.m_iElementCount += n;
    return a.m_data + oldsize;
}
template <typename T> static __forceinline void inertiaCopy(hkArray<T>& dst, const hkArrayBase<T>& src)
{
    hkMemoryAllocator& alloc = hkContainerHeapAllocator().get(&dst);
    if ((dst.m_iCapacityState & 0x3fffffff) < src.GetLogicalSize())
    {
        if ((dst.m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(dst.m_data, dst.m_iCapacityState & 0x3fffffff);
        int n = src.GetLogicalSize();
        dst.m_data = alloc._bufAlloc<T>(n);
        dst.m_iCapacityState = n;
    }
    dst.m_iElementCount = src.GetLogicalSize();
    hkArrayBase<T>::copy(dst.m_data, src.m_data, dst.m_iElementCount);
}

// src: HAVOK_LIB 0x00cebe80
__declspec(noinline) void __cdecl hkpInertiaTensorComputer_shiftInertiaToCom(const hkVector4& shift, hkReal mass, hkMatrix3& inertia)
{
    inertia(0, 0) -= mass * (shift(1) * shift(1) + shift(2) * shift(2));
    inertia(1, 1) -= mass * (shift(2) * shift(2) + shift(0) * shift(0));
    inertia(2, 2) -= mass * (shift(0) * shift(0) + shift(1) * shift(1));
    inertia(1, 0) += mass * shift(0) * shift(1);
    inertia(0, 1) = inertia(1, 0);
    inertia(2, 1) += mass * shift(1) * shift(2);
    inertia(1, 2) = inertia(2, 1);
    inertia(0, 2) += mass * shift(0) * shift(2);
    inertia(2, 0) = inertia(0, 2);
}
// src: GUESS 0x00ced6b0 (confidence: medium)
__declspec(noinline) void __cdecl hkpInertiaTensorComputer_computeBoxVolumeMassProperties_ComputeGeometryMassProperties(const hkGeometry* geom, hkReal mass, hkpMassProperties& result)
{
    result.m_fViscosityFriction += mass;
    result.m_iBufferSize += (hkReal)geom->m_kVertices.m_iElementCount;
}

// @fnv 0x00cee290
// src: GUESS 0x00cee290 (confidence: low)
int __cdecl hkVector4_UpdateState_00cee290(const hkVector4& v0, const hkVector4& v1, const hkVector4& v2, hkReal mass,
                         hkReal surfaceThickness, hkpMassProperties& result)
{
    if (mass <= 0.0f)
        return 1;
    if (surfaceThickness < 0.0f)
        return 1;

    const hkReal tolerance = 1e-5f;
    hkVector4 com;
    hkMatrix3 inertia;
    hkVector4 normal;
    {
        hkVector4 cb;
        cb.setSub4(v2, v1);
        hkVector4 ab;
        ab.setSub4(v0, v1);
        normal.setCross(cb, ab);
    }
    const hkReal area = InertiaSimd::length3ScalarCall(normal);

    if (surfaceThickness < tolerance)
    {
        com = v0;
        com.add4(v1);
        com.add4(v2);
        com.setMul4(0.33333334f, com);
        const hkReal xx =
            (hkReal)(mass / 12.0 * (com(0) * 9.0 * com(0) + v0(0) * v0(0) + v1(0) * v1(0) + (v2(0) * v2(0))));
        const hkReal yy =
            (hkReal)(mass / 12.0 * (((com(1) * 9.0) * com(1)) + (v0(1) * v0(1)) + v1(1) * v1(1) + (v2(1) * v2(1))));
        const hkReal zz =
            (hkReal)(mass / 12.0 * (((com(2) * 9.0) * com(2)) + (v0(2) * v0(2)) + v1(2) * v1(2) + v2(2) * v2(2)));
        const hkReal xy =
            (hkReal)(mass / 12.0 * (com(0) * 9.0 * com(1) + v0(0) * v0(1) + v1(0) * v1(1) + v2(0) * v2(1)));
        const hkReal xz =
            (hkReal)(mass / 12.0 * (com(0) * 9.0 * com(2) + v0(0) * v0(2) + v1(0) * v1(2) + v2(0) * v2(2)));
        const hkReal yz =
            (hkReal)(mass / 12.0 * (com(1) * 9.0 * com(2) + v0(1) * v0(2) + v1(1) * v1(2) + v2(1) * v2(2)));
        inertia(0, 0) = yy + zz;
        inertia(1, 1) = xx + zz;
        inertia(2, 2) = xx + yy;
        inertia(0, 1) = inertia(1, 0) = -xy;
        inertia(0, 2) = inertia(2, 0) = -xz;
        inertia(2, 1) = inertia(1, 2) = -yz;
        hkpInertiaTensorComputer_shiftInertiaToCom(com, mass, inertia);
    }
    else if (area < tolerance)
    {
        com = v0;
        com.add4(v1);
        com.add4(v2);
        com.setMul4(0.33333334f, com);
        const hkReal x = com(0);
        const hkReal y = com(1);
        const hkReal z = com(2);
        inertia(0, 0) = (y * y + z * z) * mass;
        inertia(1, 1) = (x * x + z * z) * mass;
        inertia(2, 2) = (y * y + x * x) * mass;
        inertia(0, 1) = -mass * (y * x);
        inertia(1, 0) = -mass * (y * x);
        inertia(0, 2) = -mass * (z * x);
        inertia(2, 0) = -mass * (z * x);
        inertia(2, 1) = -mass * (y * z);
        inertia(1, 2) = -mass * (y * z);
    }
    else
    {
        normal.normalize3();
        hkInplaceArray<hkVector4, 6> vertices(0);
        vertices.setSize(6);
        vertices[0] = v0;
        vertices[1] = v0;
        InertiaSimd::addMul4(vertices[0], (hkReal)(surfaceThickness * 0.5), normal);
        InertiaSimd::addMul4(vertices[1], (hkReal)(-surfaceThickness * 0.5), normal);
        vertices[2] = v1;
        vertices[3] = v1;
        InertiaSimd::addMul4(vertices[2], (hkReal)(surfaceThickness * 0.5), normal);
        InertiaSimd::addMul4(vertices[3], (hkReal)(-surfaceThickness * 0.5), normal);
        vertices[4] = v2;
        vertices[5] = v2;
        InertiaSimd::addMul4(vertices[4], (hkReal)(surfaceThickness * 0.5), normal);
        InertiaSimd::addMul4(vertices[5], (hkReal)(-surfaceThickness * 0.5), normal);
        hkpMassProperties massProperties;
        {
            hkGeometry geom;
            inertiaCopy(geom.m_kVertices, vertices);
            inertiaExpand(geom.m_uiTriangleCount, 1)->set(0, 2, 4);
            inertiaExpand(geom.m_uiTriangleCount, 1)->set(1, 5, 3);
            inertiaExpand(geom.m_uiTriangleCount, 1)->set(0, 3, 2);
            inertiaExpand(geom.m_uiTriangleCount, 1)->set(0, 1, 3);
            inertiaExpand(geom.m_uiTriangleCount, 1)->set(1, 0, 4);
            inertiaExpand(geom.m_uiTriangleCount, 1)->set(1, 4, 5);
            inertiaExpand(geom.m_uiTriangleCount, 1)->set(2, 5, 4);
            inertiaExpand(geom.m_uiTriangleCount, 1)->set(2, 3, 5);
            hkpInertiaTensorComputer_computeBoxVolumeMassProperties_ComputeGeometryMassProperties(&geom, mass, massProperties);
        }
        com = massProperties.m_kCenterOfMass1;
        inertia = massProperties.m_kInertiaTensor;
    }
    result.m_fViscosityFriction = mass;
    result.m_kInertiaTensor = inertia;
    result.m_kCenterOfMass1 = com;
    result.m_iBufferSize = (hkReal)(area * 0.5 * surfaceThickness);
    return 0;
}

namespace CapsuleMassSimd {
namespace NativeRegisters {
// Exe 0x00cee290 FUN_00cee290: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
}
typedef NativeRegisters::LocalM128 CapsuleMassQuad;
extern "C"
{
    CapsuleMassQuad _mm_add_ss(CapsuleMassQuad, CapsuleMassQuad);
    CapsuleMassQuad _mm_mul_ss(CapsuleMassQuad, CapsuleMassQuad);
    CapsuleMassQuad _mm_sub_ss(CapsuleMassQuad, CapsuleMassQuad);
    CapsuleMassQuad _mm_mul_ps(CapsuleMassQuad, CapsuleMassQuad);
    CapsuleMassQuad _mm_add_ps(CapsuleMassQuad, CapsuleMassQuad);
    CapsuleMassQuad _mm_sqrt_ss(CapsuleMassQuad);
    CapsuleMassQuad _mm_rsqrt_ss(CapsuleMassQuad);
    CapsuleMassQuad _mm_set_ss(float);
    CapsuleMassQuad _mm_set_ps1(float);
    CapsuleMassQuad _mm_move_ss(CapsuleMassQuad, CapsuleMassQuad);
    CapsuleMassQuad _mm_cmpeq_ss(CapsuleMassQuad, CapsuleMassQuad);
    CapsuleMassQuad _mm_andnot_ps(CapsuleMassQuad, CapsuleMassQuad);
    void _mm_store_ss(float*, CapsuleMassQuad);
    CapsuleMassQuad _mm_load_ss(const float*);
    CapsuleMassQuad _mm_shuffle_ps(CapsuleMassQuad, CapsuleMassQuad, unsigned int);
    CapsuleMassQuad _mm_setzero_ps();
    CapsuleMassQuad _mm_setr_ps(float, float, float, float);
    CapsuleMassQuad _mm_sub_ps(CapsuleMassQuad, CapsuleMassQuad);
}
extern "C" double __cdecl fabs(double);
static __forceinline float capsuleMassAbs(float x)
{
    return (float)fabs((double)x);
}

extern const double DAT_010cbf70 = 0.999989986419677734375;
extern const double DAT_010cbf40 = 4.18879032135009765625;
extern const double DAT_010cbf68 = 0.375;
extern const double DAT_010cbf60 = -0.375;
extern const float DAT_01011d78, DAT_01017718, DAT_01016248, DAT_01012068;

class CapsuleMassScalar
{
    CapsuleMassQuad value;

  public:
    CapsuleMassScalar()
    {}
    CapsuleMassScalar(const CapsuleMassQuad& quad) : value(quad)
    {}
    CapsuleMassScalar(float scalar)
    {
        value = CapsuleMassSimd::_mm_load_ss(&scalar);
    }
    __forceinline const CapsuleMassQuad& quad() const
    {
        return value;
    }
    __forceinline CapsuleMassQuad splat() const
    {
        return CapsuleMassSimd::_mm_shuffle_ps(value, value, 0);
    }
    operator float() const
    {
        float result;
        CapsuleMassSimd::_mm_store_ss(&result, value);
        return result;
    }
};
struct __declspec(align(16)) CapsuleMassVector
{
    union
    {
        CapsuleMassQuad m;
        struct
        {
            float x, y, z, w;
        };
    };
    __forceinline CapsuleMassVector()
    {}
    __forceinline CapsuleMassVector(int)
    {
        m = CapsuleMassSimd::_mm_setzero_ps();
    }
    __forceinline CapsuleMassScalar length3ScalarCall() const;
    __forceinline CapsuleMassScalar dot3ScalarCall(const CapsuleMassVector& b) const;
    __forceinline void normalize3();
    __forceinline CapsuleMassScalar inverseLength3() const;
    void hkVector4_setRotatedDir(const struct CapsuleMassMatrix*, const CapsuleMassVector*);
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    {
        m = CapsuleMassSimd::_mm_setr_ps(a, b, c, d);
    }
};
struct CapsuleMassMatrix
{
    CapsuleMassVector row0, row1, row2;
    __forceinline CapsuleMassMatrix()
    {}
    __forceinline CapsuleMassMatrix(int) : row0(0), row1(0), row2(0)
    {}
    __forceinline CapsuleMassMatrix(bool) : row0(0), row1(0), row2(0)
    {
        row0.x = 1.0f;
        row1.y = 1.0f;
        row2.z = 1.0f;
    }
    __forceinline CapsuleMassMatrix& operator=(const CapsuleMassMatrix& b)
    {
        row0.m = b.row0.m;
        row1.m = b.row1.m;
        row2.m = b.row2.m;
        return *this;
    }
    void hkRotation_set(const CapsuleMassVector*);
    void Multiply(const CapsuleMassVector*);
    __forceinline void zero()
    {
        row0.m = CapsuleMassSimd::_mm_setzero_ps();
        row1.m = CapsuleMassSimd::_mm_setzero_ps();
        row2.m = CapsuleMassSimd::_mm_setzero_ps();
    }
    __forceinline float& at(int r, int c)
    {
        return (&row0)[c].m.m128_f32[r];
    }
    __forceinline void identity()
    {
        zero();
        float unit = 1.0f;
        at(0, 0) = unit;
        at(1, 1) = unit;
        at(2, 2) = unit;
    }
};
struct CapsuleMassQuaternion : CapsuleMassVector
{
    void hkQuaternion_setAxisAngle(const CapsuleMassVector*, float);
};
struct CapsuleMassTransform
{
    CapsuleMassMatrix rotation;
    CapsuleMassVector translation;
    __forceinline CapsuleMassTransform()
    {}
    __forceinline CapsuleMassTransform(bool) : rotation(true), translation(0)
    {}
    __forceinline CapsuleMassTransform& operator=(const CapsuleMassTransform& b)
    {
        CapsuleMassQuad a = b.rotation.row0.m, c = b.rotation.row1.m, d = b.rotation.row2.m, t = b.translation.m;
        rotation.row0.m = a;
        rotation.row1.m = c;
        rotation.row2.m = d;
        translation.m = t;
        return *this;
    }
    __forceinline void identity()
    {
        rotation.identity();
        translation.m = CapsuleMassSimd::_mm_setzero_ps();
    }
};
struct CapsuleMassBody
{
    float volume, mass;
    CapsuleMassVector center;
    CapsuleMassMatrix inertia;
    __forceinline CapsuleMassBody() : center(0)
    {
        volume = 0.0f;
        mass = 0.0f;
        inertia = CapsuleMassMatrix(0);
    }
    __forceinline CapsuleMassBody(int) : volume(0.0f), mass(0.0f), center(0)
    {}
    __forceinline CapsuleMassBody(bool)
    {
        inertia.row0.m = CapsuleMassSimd::_mm_setzero_ps();
        inertia.row1.m = CapsuleMassSimd::_mm_setzero_ps();
        inertia.row2.m = CapsuleMassSimd::_mm_setzero_ps();
    }
    __forceinline CapsuleMassBody(const CapsuleMassBody& b)
    {
        volume = b.volume;
        mass = b.mass;
        center.m = b.center.m;
        inertia = b.inertia;
    }
};
struct CapsuleMassElement
{
    static __forceinline void* operator new(unsigned int, void* p)
    {
        return p;
    }
    CapsuleMassBody properties;
    CapsuleMassTransform transform;
    __forceinline CapsuleMassElement() : transform(true)
    {}
    __forceinline CapsuleMassElement(int) : properties(0), transform(true)
    {}
    __forceinline CapsuleMassElement(const CapsuleMassElement& b) : properties(b.properties)
    {
        transform = b.transform;
    }
};
extern void __cdecl ResizeAudioStream(void*, void*, int);
struct CapsuleMassArray
{
    CapsuleMassElement* data;
    int size;
    unsigned capacity;
    CapsuleMassElement local[3];
    __forceinline CapsuleMassArray() : data(local), size(0), capacity(0x80000003u)
    {}
    __forceinline void append(const CapsuleMassElement& e)
    {
        hkMemoryRouter* r = hkMemoryRouter_getInstance();
        if (size == (capacity & 0x3fffffff))
            CapsuleMassSimd::ResizeAudioStream(r->m_heap, this, sizeof(CapsuleMassElement));
        new (data + size) CapsuleMassElement(e);
        ++size;
    }
    __forceinline ~CapsuleMassArray()
    {
        hkMemoryRouter* router = hkMemoryRouter_getInstance();
        hkMemoryAllocator* h = router->m_heap;
        unsigned cap = capacity;
        size = 0;
        if ((cap & 0x80000000u) == 0)
            h->bufFree(data, (cap & 0x3fffffff) * sizeof(CapsuleMassElement));
    }
};
extern int __cdecl hkpInertiaTensorComputer_combineMassProperties(CapsuleMassArray*, Receiver*);
extern int __cdecl hkpInertiaTensorComputer_computeSphereVolumeMassProperties(float, float, CapsuleMassBody*);
extern float __cdecl ClampedAcos(float);

static __forceinline CapsuleMassQuad capsuleMassSum3(CapsuleMassQuad v)
{
    return CapsuleMassSimd::_mm_add_ss(CapsuleMassSimd::_mm_shuffle_ps(v, v, 0xaa),
                                       CapsuleMassSimd::_mm_add_ss(CapsuleMassSimd::_mm_shuffle_ps(v, v, 0x55), v));
}
static __forceinline float capsuleMassReal(CapsuleMassQuad v)
{
    float f;
    CapsuleMassSimd::_mm_store_ss(&f, v);
    return f;
}
__forceinline CapsuleMassScalar CapsuleMassVector::length3ScalarCall() const
{
    return CapsuleMassSimd::_mm_sqrt_ss(dot3ScalarCall(*this).quad());
}
__forceinline CapsuleMassScalar CapsuleMassVector::dot3ScalarCall(const CapsuleMassVector& b) const
{
    return CapsuleMassScalar(capsuleMassSum3(CapsuleMassSimd::_mm_mul_ps(m, b.m)));
}
__forceinline CapsuleMassScalar CapsuleMassVector::inverseLength3() const
{
    const CapsuleMassQuad half = CapsuleMassSimd::_mm_set_ss(0.5f);
    const CapsuleMassQuad three = CapsuleMassSimd::_mm_set_ss(3.0f);
    const CapsuleMassQuad zero = CapsuleMassSimd::_mm_set_ss(0.0f);
    const CapsuleMassQuad squared = dot3ScalarCall(*this).quad();
    const CapsuleMassQuad isZero = CapsuleMassSimd::_mm_cmpeq_ss(squared, zero);
    const CapsuleMassQuad approx = CapsuleMassSimd::_mm_rsqrt_ss(squared);
    const CapsuleMassQuad refined = CapsuleMassSimd::_mm_mul_ss(
        CapsuleMassSimd::_mm_mul_ss(half, approx),
        CapsuleMassSimd::_mm_sub_ss(three,
                                    CapsuleMassSimd::_mm_mul_ss(CapsuleMassSimd::_mm_mul_ss(squared, approx), approx)));
    return CapsuleMassSimd::_mm_andnot_ps(isZero, refined);
}
__forceinline void CapsuleMassVector::normalize3()
{
    CapsuleMassQuad inverse = inverseLength3().splat();
    m = CapsuleMassSimd::_mm_mul_ps(inverse, m);
}
static __forceinline CapsuleMassQuad capsuleMassCross(CapsuleMassQuad a, CapsuleMassQuad b)
{
    return CapsuleMassSimd::_mm_sub_ps(CapsuleMassSimd::_mm_mul_ps(CapsuleMassSimd::_mm_shuffle_ps(a, a, 0xc9),
                                                                   CapsuleMassSimd::_mm_shuffle_ps(b, b, 0xd2)),
                                       CapsuleMassSimd::_mm_mul_ps(CapsuleMassSimd::_mm_shuffle_ps(a, a, 0xd2),
                                                                   CapsuleMassSimd::_mm_shuffle_ps(b, b, 0xc9)));
}

// @fnv 0x00ceeca0
// src: XBOX_PDB 0x00ceeca0
__declspec(noinline) int __cdecl hkpInertiaTensorComputer_computeCapsuleVolumeMassProperties(const CapsuleMassVector* source, const CapsuleMassVector* destination,
                                              float radius, float mass, Receiver* receiver)
{
    if (mass <= 0.0f)
        return 1;
    if (radius <= 0.0f)
        return 1;
    CapsuleMassVector between;
    between.m = CapsuleMassSimd::_mm_sub_ps(destination->m, source->m);
    float length = float(between.length3ScalarCall());
    CapsuleMassTransform transform;
    if (length > 0.0f)
    {
        between.normalize3();
        CapsuleMassVector up;
        up.set(0.0f, 0.0f, 1.0f);

        if (capsuleMassAbs(float(up.dot3ScalarCall(between))) < DAT_010cbf70)
        {
            CapsuleMassVector axis;
            axis.m = capsuleMassCross(up.m, between.m);
            axis.normalize3();
            CapsuleMassQuaternion q;
            q.hkQuaternion_setAxisAngle(&axis, ClampedAcos(float(up.dot3ScalarCall(between))));
            transform.rotation.hkRotation_set(&q);
        }
        else
            transform.rotation.identity();
    }
    else
        transform.rotation.identity();
    CapsuleMassQuad h = CapsuleMassSimd::_mm_set_ss(0.5f);
    transform.translation.m = CapsuleMassSimd::_mm_mul_ps(CapsuleMassSimd::_mm_shuffle_ps(h, h, 0),
                                                          CapsuleMassSimd::_mm_add_ps(source->m, destination->m));
    float sphereVolume = (float)(radius * DAT_010cbf40 * radius * radius);
    float cylinderVolume = (float)(radius * 3.1415927410125732421875 * radius * length);
    float volume = sphereVolume + cylinderVolume;
    float sphereMass = sphereVolume * mass / volume;
    float cylinderMass = cylinderVolume * mass / volume;
    CapsuleMassArray elements;
    double halfLength;
    {
        CapsuleMassElement element(0);
        element.transform = transform;
        halfLength = length * 0.5;
        element.properties.center.set(0.0f, 0.0f, 0.0f);
        element.properties.inertia = CapsuleMassMatrix(0);
        CapsuleMassVector scale;
        scale.m = CapsuleMassSimd::_mm_load_ss(&cylinderMass);
        element.properties.inertia.row0.x = (float)(halfLength * length * 0.5 / 3.0 + radius * radius * 0.25);
        element.properties.inertia.row1.y = element.properties.inertia.row0.x;
        element.properties.inertia.row2.z = (float)(radius * radius * 0.5);
        element.properties.inertia.Multiply(&scale);
        element.properties.volume = cylinderVolume;
        element.properties.mass = cylinderMass;
        element.properties.center.m = CapsuleMassSimd::_mm_setzero_ps();
        elements.append(element);
    }
    {
        CapsuleMassElement cap;
        cap.transform = transform;
        CapsuleMassVector offset;
        offset.set(0.0f, 0.0f, (float)halfLength);
        offset.hkVector4_setRotatedDir(&transform.rotation, &offset);
        offset.m = CapsuleMassSimd::_mm_add_ps(cap.transform.translation.m, offset.m);
        cap.transform.translation.m = offset.m;
        cap.properties.center.set(0.0f, 0.0f, (float)(radius * DAT_010cbf68));
        CapsuleMassBody ball(false);
        hkpInertiaTensorComputer_computeSphereVolumeMassProperties(radius, sphereMass, &ball);
        cap.properties.inertia = ball.inertia;
        CapsuleMassVector half;
        half.m = CapsuleMassSimd::_mm_load_ss(&DAT_01016248);
        cap.properties.inertia.Multiply(&half);
        hkpInertiaTensorComputer_shiftInertiaToCom(*reinterpret_cast<const hkVector4*>(&cap.properties.center), (float)(sphereMass * 0.5),
                     *reinterpret_cast<hkMatrix3*>(&cap.properties.inertia));
        cap.properties.volume = (float)(sphereVolume * 0.5);
        cap.properties.mass = (float)(sphereMass * 0.5);
        elements.append(cap);
    }
    {
        CapsuleMassElement cap;
        cap.transform = transform;
        CapsuleMassVector offset;
        offset.set(0.0f, 0.0f, (float)-halfLength);
        offset.hkVector4_setRotatedDir(&transform.rotation, &offset);
        offset.m = CapsuleMassSimd::_mm_add_ps(cap.transform.translation.m, offset.m);
        cap.transform.translation.m = offset.m;
        cap.properties.center.set(0.0f, 0.0f, (float)(radius * DAT_010cbf60));
        CapsuleMassBody ball(false);
        hkpInertiaTensorComputer_computeSphereVolumeMassProperties(radius, sphereMass, &ball);
        cap.properties.inertia = ball.inertia;
        CapsuleMassVector half;
        half.m = CapsuleMassSimd::_mm_load_ss(&DAT_01016248);
        cap.properties.inertia.Multiply(&half);
        hkpInertiaTensorComputer_shiftInertiaToCom(*reinterpret_cast<const hkVector4*>(&cap.properties.center), (float)(sphereMass * 0.5),
                     *reinterpret_cast<hkMatrix3*>(&cap.properties.inertia));
        cap.properties.volume = (float)(sphereVolume * 0.5);
        cap.properties.mass = (float)(sphereMass * 0.5);
        elements.append(cap);
    }
    hkpInertiaTensorComputer_combineMassProperties(&elements, receiver);
    return 0;
}

}
