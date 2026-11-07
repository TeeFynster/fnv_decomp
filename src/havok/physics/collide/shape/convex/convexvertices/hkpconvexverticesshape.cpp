#include "../../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original float-only intrinsic representation: byte-array lanes in
// the compiler header introduce /GS buffers into the original SIMD routines.
#define _INCLUDED_MM2
// Exe 0x00d58d80 GetCollisionSpheres: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
extern "C" LocalM128 _mm_rcp_ps(LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);

#include "../../../../../../../include/V4.h"
// local form of hkVector4: 0x00d59cc0 needs its original packet form (compiled function extent differs: 808 vs 633).


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
union __m128;
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class PacketCallLocal_00d59cc0
{
public:
#if defined(FNV_FOURFLOATVECTOR_NO_SSE)
    union Components
    {
        float m128_f32[4];
        unsigned __int64 m128_u64[2];
        signed char m128_i8[16];
        short m128_i16[8];
        int m128_i32[4];
        __int64 m128_i64[2];
        unsigned char m128_u8[16];
        unsigned short m128_u16[8];
        unsigned int m128_u32[4];
    };
#else
    typedef __declspec(align(4)) __m128 Components;
#endif

    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        Components m_vComponents;
        Components m;
        float f[4];
        Components values;
        Components q;
        Components value;
        Components quad;
        float elements[4];
        float m_fComponents[4];
    };

    PacketCallLocal_00d59cc0();
    PacketCallLocal_00d59cc0(float x, float y, float z, float w);
    PacketCallLocal_00d59cc0(const __m128& vector);

    PacketCallLocal_00d59cc0* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(PacketCallLocal_00d59cc0* vector);
    void __thiscall SetQuaternionComponentsFromVector(const PacketCallLocal_00d59cc0* vector);
    PacketCallLocal_00d59cc0& ComputeValue_00e531a0(int parameter);
    PacketCallLocal_00d59cc0 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const PacketCallLocal_00d59cc0& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const PacketCallLocal_00d59cc0& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const PacketCallLocal_00d59cc0& vector);
    void Sub(const PacketCallLocal_00d59cc0& vector);
    void Cross(const PacketCallLocal_00d59cc0& a, const PacketCallLocal_00d59cc0& b);

    void setAbs4(const PacketCallLocal_00d59cc0& vector);
    void setMul4(const SimdReal& scalar, const PacketCallLocal_00d59cc0& vector);
    void addMul4(const SimdReal& scalar, const PacketCallLocal_00d59cc0& vector);
    void setAddMul4(const PacketCallLocal_00d59cc0& a, const PacketCallLocal_00d59cc0& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const PacketCallLocal_00d59cc0& vector);
    void setAddMul(const PacketCallLocal_00d59cc0& a, const PacketCallLocal_00d59cc0& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const PacketCallLocal_00d59cc0& vector);
    void transformed(const Transform& transform, const PacketCallLocal_00d59cc0& vector);
    void addScaled(const PacketCallLocal_00d59cc0& base, const PacketCallLocal_00d59cc0& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#include "../../../../../../../include/MemoryManager.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkSimdRealq.h"
#include "../../../../../../../include/hkVector4q.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpConvexVerticesShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkSphere.h"

// 0x00c85750 supplies the same heap-at-0x10 router used by the other shared-array helpers.
hkMemoryRouter* GetMemoryRouter_c85750();

// @fnv 0x00d58d60
void hkpConvexVerticesShape::GetFirstVertex(hkVector4& vertex) const
{
    float* out = reinterpret_cast<float*>(&vertex);
    float* p = reinterpret_cast<float*>(m_kRotatedVertices.m_data);
    out[0] = p[0];
    out[1] = p[4];
    out[2] = p[8];
    out[3] = 0.0f;
}

void __cdecl hkAabbUtil_calcAabb_00d26230(void*, void*, void*, float, int);

// Calls FUN_00d26230 with this+0x20, this+0x30, the float at this+0x10 plus b, and c.
// @fnv 0x00d591d0
void hkpConvexVerticesShape::CalculateAabb(const hkTransform& a, float afDelta, hkAabb& c) const
{
    hkAabbUtil_calcAabb_00d26230(
        const_cast<hkTransform*>(&a),
        reinterpret_cast<void*>(reinterpret_cast<char*>(const_cast<hkpConvexVerticesShape*>(this)) + 0x20),
        reinterpret_cast<void*>(reinterpret_cast<char*>(const_cast<hkpConvexVerticesShape*>(this)) + 0x30),
        m_fSphereRadius + afDelta,
        reinterpret_cast<int>(&c)
    );
}

struct RefObj { void RetainReference(); void removeReference(); };
struct DDCC60World { void removeReference(); };
// Local fallback: shared hkpConvexVerticesShape lacks AssignReference and FUN_00d59f40.
struct FUN_00d5a320 {
    void ProcessEntries_00d59f40();
    void AssignReference(RefObj* p, bool b);
};
// Releases the current reference at this+0x60, stores p there, and if b and p are set calls FUN_00d59f40.
// @fnv 0x00d5a320
void FUN_00d5a320::AssignReference(RefObj* apRef, bool b)
{
    if (apRef) apRef->RetainReference();
    if (*(DDCC60World**)((char*)this + 0x60)) (*(DDCC60World**)((char*)this + 0x60))->removeReference();
    *(RefObj**)((char*)this + 0x60) = apRef;
    if (b && apRef) ProcessEntries_00d59f40();
}

hkMemoryRouter* _D1A0E0GetMemoryRouter();

// Local fallback: shared shape has no explicit deleting-destructor wrapper.
struct FUN_00d5a4e0_Base {
    void FUN_00d59870();
};

struct FUN_00d5a4e0_StandIn : public FUN_00d5a4e0_Base {
    unsigned char m_auiShapeKeys[4];
    unsigned short m_iElementCount;

    FUN_00d5a4e0_StandIn* FUN_00d5a4e0(unsigned char deleting);
};

// @fnv 0x00d5a4e0
FUN_00d5a4e0_StandIn* FUN_00d5a4e0_StandIn::FUN_00d5a4e0(unsigned char deleting) {
    this->FUN_00d59870();

    if (deleting & 1) {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short size = m_iElementCount;
        hkMemoryAllocator* manager = reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
        manager->blockFree(this, size);
    }

    return this;
}

// @fnv 0x00d58d40
// src: XBOX_PDB 0x00d58d40
static Vec4* __cdecl ConvexVerticesShape_FetchVectorFromPpuArray(Vec4* base, int index)
{
    return base + index;
}

Vec4* caller_d58d40(Vec4* base, int index)
{
    return ConvexVerticesShape_FetchVectorFromPpuArray(base, index);
}

// @fnv 0x00d58d10
int hkpConvexVerticesShape::GetNumCollisionSpheres() const
{
    return m_iStridedVertexCount;
}

// @fnv 0x00d58d50
const hkArray<hkVector4>& hkpConvexVerticesShape::GetPlaneEquations() const
{
    return m_kVertexPositions;
}

struct CallTarget_00d5a410 { int hkArrayBase_hkVector4_spliceInto(int, int, int, int, int); };
struct SearchObject {
    int ProcessAndReturnValue_00d5a4c0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d5a4c0
// src: GUESS 0x00d5a4c0 (confidence: low)
int SearchObject::ProcessAndReturnValue_00d5a4c0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiCallResult = (unsigned int)((CallTarget_00d5a410*)this)->hkArrayBase_hkVector4_spliceInto((int)arg0, (int)arg1, (int)0u, (int)arg2, (int)arg3);
    return (int)uiCallResult;
}

extern "C" LocalM128 _mm_setr_ps(float, float, float, float);

__forceinline const float& hkVector4q::operator()(int i) const { return ((const float*)&m_vComponents)[i]; }

__forceinline void hkVector4_S::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
struct FourVectorsQ { hkVector4q m_uiX; hkVector4q m_uiY; hkVector4q m_uiZ; };

// Writes m_kRotatedVertices positions and m_fSphereRadius into sphereBuffer as hkSphere entries, returning sphereBuffer.
// @fnv 0x00d58d80
const hkSphere* hkpConvexVerticesShape::GetCollisionSpheres(hkSphere* sphereBuffer) const
{
    hkSphere* out = sphereBuffer;
    const FourVectorsQ* fv = reinterpret_cast<const FourVectorsQ*>(m_kRotatedVertices.m_data);
    int i = m_iStridedVertexCount - 1;
    for (; i >= 3; i -= 4)
    {
        (out++)->m_pos.set(fv->m_uiX(0), fv->m_uiY(0), fv->m_uiZ(0), m_fSphereRadius);
        (out++)->m_pos.set(fv->m_uiX(1), fv->m_uiY(1), fv->m_uiZ(1), m_fSphereRadius);
        (out++)->m_pos.set(fv->m_uiX(2), fv->m_uiY(2), fv->m_uiZ(2), m_fSphereRadius);
        (out++)->m_pos.set(fv->m_uiX(3), fv->m_uiY(3), fv->m_uiZ(3), m_fSphereRadius);
        fv++;
    }
    if (i >= 0) (out++)->m_pos.set(fv->m_uiX(0), fv->m_uiY(0), fv->m_uiZ(0), m_fSphereRadius);
    if (i >= 1) (out++)->m_pos.set(fv->m_uiX(1), fv->m_uiY(1), fv->m_uiZ(1), m_fSphereRadius);
    if (i >= 2) (out++)->m_pos.set(fv->m_uiX(2), fv->m_uiY(2), fv->m_uiZ(2), m_fSphereRadius);
    return sphereBuffer;
}

extern "C" {
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ss(LocalM128, LocalM128);
LocalM128 _mm_xor_ps(LocalM128, LocalM128);
LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
}


typedef LocalM128 hkQuadReal;

extern const hkQuadReal hkQuadRealSignMask;

struct hkMatrix3;

__forceinline void hkVector4q::setNeg4(const hkVector4q& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, hkQuadRealSignMask); }
__forceinline hkSimdRealq hkVector4q::dot4xyz1(const hkVector4q& a) const
{
    const hkQuadReal xx = _mm_mul_ps(m_vComponents, a.m_vComponents);
    const hkQuadReal x2 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
    const hkQuadReal x3 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
    hkSimdRealq r;
    r.m_vValue = _mm_add_ps(x3, x2);
    return r;
}
__forceinline void hkVector4q::setW(const hkSimdRealq& w)
{
    const hkQuadReal ww = _mm_shuffle_ps(w.m_vValue, w.m_vValue, 0);
    m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, ww), 0xc4);
}


#include "../../../../../../../include/hkMatrix3.h"
__forceinline hkMatrix3::hkMatrix3() {}


struct hkTransformq
{
    hkMatrix3 m_rotation;
    hkVector4q m_vTranslation;
};

__forceinline void ConvexInverseDir(hkVector4q& out, const hkMatrix3& r, const hkVector4q& b)
{
    hkQuadReal c0 = r.m_kColumn0.m_vComponents;
    hkQuadReal c1 = r.m_kColumn1.m_vComponents;
    hkQuadReal c2 = r.m_kColumn2.m_vComponents;
    const hkQuadReal t0 = _mm_unpacklo_ps(c0, c1);
    const hkQuadReal t1 = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(t0, c2);
    c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, t0), c2, 0xd4);
    c2 = _mm_shuffle_ps(t1, c2, 0xe4);
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

#pragma pack(push, 1)
struct VectorComponents { float x, y, z, w; };
#pragma pack(pop)

union hkVector4U
{
    VectorComponents m_vec;
    hkQuadReal m_vComponents;
};

void* __cdecl GetThreadMemoryQ() throw();

static __forceinline hkMemoryRouter* hkGetThreadMemory() { return (hkMemoryRouter*)GetThreadMemoryQ(); }

template <class T>
static __forceinline void hkArrayq_destroy(hkArrayBase<T>& self);

template <class T>
static __forceinline void hkArrayq_destroy(hkArrayBase<T>& self)
{
        hkMemoryAllocator& alloc = hkGetThreadMemory()->heap();
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
        {
            alloc.bufFree(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }

struct hkArrayqPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { hkArrayq_destroy(self); }
};

template <class T>
__forceinline T* hkAllocateStack(int n)
{
    hkMemoryRouter* mem = hkGetThreadMemory();
    char* p = static_cast<char*>(mem->m_stack.m_next.m_storage);
    mem->m_stack.m_next.m_storage = p + ((n * sizeof(T) + 127) & ~127);
    return (T*)p;
}

template <class T>
__forceinline void hkDeallocateStack(T* p)
{
    hkGetThreadMemory()->m_stack.m_next.m_storage = (char*)p;
}

template <class T>
struct hkLocalArrayq : public hkArray<T, hkArrayqPolicy>
{
    T* m_pStackAllocation;

    __forceinline hkLocalArrayq(int n)
    {
        this->m_data = hkAllocateStack<T>(n);
        m_pStackAllocation = this->m_data;
        this->m_iCapacityState = n | 0x80000000;
    }
    __forceinline ~hkLocalArrayq()
    {
        if (m_pStackAllocation == this->m_data)
        {
            this->m_iElementCount = 0;
        }
        hkDeallocateStack<T>(m_pStackAllocation);
    }
};

static __forceinline void hkTransformPoints(const hkTransform& t, const hkVector4q* vectorsIn, int numVectors, hkVector4q* vectorsOut)
{
    hkVector4U c0;
    c0.m_vec = reinterpret_cast<const VectorComponents*>(&t)[0];
    hkVector4U c1;
    c1.m_vec = reinterpret_cast<const VectorComponents*>(&t)[1];
    hkVector4U c2;
    c2.m_vec = reinterpret_cast<const VectorComponents*>(&t)[2];
    hkVector4U trans;
    trans.m_vec = reinterpret_cast<const VectorComponents*>(&t)[3];
    int i = numVectors - 1;
    do
    {
        const hkQuadReal b = vectorsIn[i].m_vComponents;
        const hkQuadReal b0 = _mm_shuffle_ps(b, b, 0x00);
        const hkQuadReal r0 = _mm_mul_ps(c0.m_vComponents, b0);
        const hkQuadReal b1 = _mm_shuffle_ps(b, b, 0x55);
        const hkQuadReal r1 = _mm_mul_ps(c1.m_vComponents, b1);
        const hkQuadReal b2 = _mm_shuffle_ps(b, b, 0xaa);
        const hkQuadReal r2 = _mm_mul_ps(c2.m_vComponents, b2);
        vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, trans.m_vComponents));
    }
    while (--i >= 0);
}

static __forceinline void hkTransformPlaneEquations(const hkTransformq& t, const hkVector4q* planes, int numPlanes, hkVector4q* planesOut)
{
    hkMatrix3 rotation;
    rotation.m_kColumn0 = t.m_rotation.m_kColumn0;
    rotation.m_kColumn1 = t.m_rotation.m_kColumn1;
    rotation.m_kColumn2 = t.m_rotation.m_kColumn2;
    hkVector4q tr;
    tr.setNeg4(t.m_vTranslation);
    hkVector4q pivotShift;
    ConvexInverseDir(pivotShift, rotation, tr);

    int i = numPlanes - 1;
    do
    {
        const hkSimdRealq newDist = planes->dot4xyz1(pivotShift);
        planesOut->SetRotatedDirection(rotation, *planes);
        planesOut->setW(newDist);
        planes++;
        planesOut++;
    }
    while (--i >= 0);
}

// Local fallback: shared shape lacks Transform, FUN_00d59200 and FUN_00d59900.
class hkpConvexVerticesShapeq : public hkpConvexShape
{
public:

    virtual int GetNumCollisionSpheres() const throw();
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    void* m_kRotatedVertices;
    int m_rotatedSize;
    int m_rotatedCapacity;
    int m_iStridedVertexCount;
    void* m_pConvexPiece;
    hkVector4q* m_planeData;
    int m_iPlaneCount;
    int m_planeCapacity;

    void FUN_00d59200(hkArray<hkVector4q, hkArrayqPolicy>& vertices) const throw();
    void hkpConvexVerticesShape_copyVertexData(const float* vertices, int striding, int numVertices) throw();
    void Transform(const hkTransform& t);
};

// Gets the vertices, transforms them by t, calls FUN_00d59900 with them, then transforms the m_planeData plane equations in place by t.
// @fnv 0x00d59cc0
void hkpConvexVerticesShapeq::Transform(const hkTransform& t)
{
    hkLocalArrayq<hkVector4q> vertices(GetNumCollisionSpheres());
    FUN_00d59200(vertices);
    hkTransformPoints(t, vertices.begin(), vertices.GetLogicalSize(), vertices.begin());
    hkpConvexVerticesShape_copyVertexData((const float*)vertices.begin(), sizeof(hkVector4q), vertices.GetLogicalSize());
    hkTransformPlaneEquations((const hkTransformq&)t, m_planeData, m_iPlaneCount, m_planeData);
}

struct __declspec(align(16)) Vector4D5A360 {
    float x;
    float y;
    float z;
    float w;
    void operator=(const Vector4D5A360& v) { *reinterpret_cast<LocalM128*>(this) = *reinterpret_cast<const LocalM128*>(&v); }
};
template <class T> __forceinline void CopyD5A360(T* pDst, const T* pSrc, int iEntryIndex)
{
    for (int i = 0; i < iEntryIndex; i++)
        pDst[i] = pSrc[i];
}
template <class T>
static __forceinline hkArrayBase<T>& ArrayD5A360_assign(hkArrayBase<T>& self, const hkArrayBase<T>& a);

template <class T>
static __forceinline hkArrayBase<T>& ArrayD5A360_assign(hkArrayBase<T>& self, const hkArrayBase<T>& a)
{
        hkMemoryAllocator& kAlloc = *GetMemoryRouter_c85750()->m_heap;
        if (self.getCapacity() < a.m_iElementCount)
        {
            if ((self.m_iCapacityState & 0x80000000) == 0)
                kAlloc.bufFree(self.m_data, self.getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            self.m_data = static_cast<T*>(kAlloc.bufAlloc(iNumBytes));
            self.m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        self.m_iElementCount = a.m_iElementCount;
        CopyD5A360(self.m_data, a.m_data, self.m_iElementCount);
        return *(&self);
    }

struct ArrayD5A360Policy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { }
    template <class T>
    static __forceinline void assign(hkArrayBase<T>& self, const hkArrayBase<T>& other) { ArrayD5A360_assign(self, other); }
};
// Local fallback: shared shape lacks SetVertices and FUN_00d59f40.
struct ConvexD5A360 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
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
    int unk50;
    hkArray<Vector4D5A360, ArrayD5A360Policy> m_kVertices;
    int m_iConnectivity;
    void ProcessEntries_00d59f40();
    void SetVertices(const hkArray<Vector4D5A360, ArrayD5A360Policy>& kVertices);
};

// Copies kVertices into m_kVertices and calls FUN_00d59f40 if m_iConnectivity is nonzero.
// @fnv 0x00d5a360
void ConvexD5A360::SetVertices(const hkArray<Vector4D5A360, ArrayD5A360Policy>& kVertices)
{
    m_kVertices = kVertices;
    if (m_iConnectivity)
        ProcessEntries_00d59f40();
}

// @fnv 0x00d58d20
void hkpConvexVerticesShape::GetCentre(LocalM128* out)
{
    *out = *reinterpret_cast<const LocalM128*>(&unk30);
}

class hkpConvexVerticesShapeFourVectors
{
public:
    hkReal m_uiX[4];
    hkReal m_uiY[4];
    hkReal m_uiZ[4];
};

struct Vector4WithInt24W
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkUint32 w;
    hkReal& operator()(int i) { return (&x)[i]; }
    void set(hkReal a, hkReal b, hkReal c) { x = a; y = b; z = c; }
    void setInt24W(int value) { w = (hkUint32)value | 0x3f000000; }
};

typedef hkUint16 hkpVertexId;

// Copies numIds rotated vertex positions from m_kRotatedVertices into verticesOut, packing each vertexId into the w field.
// @fnv 0x00d59060
void hkpConvexVerticesShape::GetVerticesFromIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* verticesOut) const
{
    int i = numIds - 1;
    __assume(i >= 0);
    for (; i >= 0; i--)
    {
        int vertexId = ids[0];
        const hkpConvexVerticesShapeFourVectors& fv = m_kRotatedVertices.m_data[vertexId >> 2];
        int a = vertexId & 3;
        Vector4WithInt24W& v = verticesOut[0];
        v(0) = fv.m_uiX[a];
        v(1) = fv.m_uiY[a];
        v(2) = fv.m_uiZ[a];
        v.setInt24W(vertexId);
        verticesOut++;
        ids++;
    }
}

class SpliceAllocator;
struct AlignedSpliceVector {LocalM128 value;};
void __cdecl hkArrayUtil__reserve(SpliceAllocator& allocator,void* array,int capacity,int elementBytes);
void __cdecl hkMemUtil_memMove(void* destination,const void* source,unsigned bytes);
struct VectorSpliceArray {
    AlignedSpliceVector* data;
    int size;
    int capacityAndFlags;
    void hkArrayBase_hkVector4_spliceInto(SpliceAllocator& allocator,int first,int removeCount,const AlignedSpliceVector* source,int insertCount);
};
// Removes removeCount elements at first, inserts insertCount elements from source, and grows the buffer via FUN_00c908c0 if capacity is insufficient.
// @fnv 0x00d5a410
// src: XBOX_PDB 0x00d5a410
void VectorSpliceArray::hkArrayBase_hkVector4_spliceInto(SpliceAllocator& allocator,int first,int removeCount,const AlignedSpliceVector* source,int insertCount) {
    int newSize=size-removeCount+insertCount;
    int tailCount=size-first-removeCount;
    if((capacityAndFlags&0x3fffffff)<newSize) {
        int requested=(capacityAndFlags&0x3fffffff)*2;
        if(newSize>=requested)requested=newSize;
        hkArrayUtil__reserve(allocator,this,requested,sizeof(AlignedSpliceVector));
    }
    hkMemUtil_memMove(data+first+insertCount,data+first+removeCount,tailCount*sizeof(AlignedSpliceVector));
    AlignedSpliceVector* destination=data+first;
    for(int i=0;i<insertCount;++i) {
        LocalM128 value=source[i].value;
        destination[i].value=value;
    }
    size=newSize;
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

// hkArray<T>::~hkArray() = clearAndDeallocate() on the heap allocator (slot 4 of hkMemoryAllocator is ReturnMemory).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance().heap();
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{ __if_exists(A::destroy) { A::destroy(*this); } __if_not_exists(A::destroy) {
    clearAndDeallocate();
} }


// @fnv 0x00d59870
hkpConvexVerticesShape::~hkpConvexVerticesShape() throw()
{
    if (m_pConnectivity)
        m_pConnectivity->removeReference();
}

extern "C" LocalM128 _mm_load_ps(const float*);
struct SelectBits { LocalM128 v; };
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_cmplt_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_and_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_andnot_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_or_ps(LocalM128 a, LocalM128 b);

struct MatchVector
{
    LocalM128 m_vComponents;

    MatchVector() {}
 SelectBits compare(const MatchVector& a) const { SelectBits result; result.v=_mm_cmplt_ps(m_vComponents,a.m_vComponents); return result; }
    MatchVector(const MatchVector& v) { m_vComponents = v.m_vComponents; }
    MatchVector(float v)
    {
        m_vComponents.m128_f32[0] = v;
        m_vComponents.m128_f32[1] = v;
        m_vComponents.m128_f32[2] = v;
        m_vComponents.m128_f32[3] = v;
    }
    void operator=(const MatchVector& v) { m_vComponents = v.m_vComponents; }
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
    const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
    void setMul4(const MatchVector& a, const MatchVector& b) { m_vComponents = _mm_mul_ps(_mm_load_ps((const float*)&a.m_vComponents), b.m_vComponents); }
    void addMul4(const MatchVector& a, const MatchVector& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_load_ps((const float*)&a.m_vComponents), b.m_vComponents)); }
    void add4(const MatchVector& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    void setSelect4(const SelectBits& comp, const MatchVector& trueValue, const MatchVector& falseValue) { m_vComponents = _mm_or_ps(_mm_and_ps(comp.v, trueValue.m_vComponents), _mm_andnot_ps(comp.v, falseValue.m_vComponents)); }
    void selectIndex(const SelectBits& comp,const MatchVector& trueValue,const MatchVector& falseValue) {m_vComponents=_mm_or_ps(_mm_and_ps(comp.v,trueValue.m_vComponents),_mm_andnot_ps(_mm_load_ps((const float*)&comp.v),falseValue.m_vComponents));}
void setInt24W(int value) { ((int*)&m_vComponents)[3] = value | 0x3f000000; }
};

extern const MatchVector DAT_010d9fe0;
extern const MatchVector DAT_010d0fa0;

struct hkFourTransposedPointsQ
{
    MatchVector m_uiX;
    MatchVector m_uiY;
    MatchVector m_uiZ;
};

// Local fallback: the shared GetSupportVertex signature changes the generated code.
struct MatchShape : public hkpShape
{
    float m_fSphereRadius;
    int unk14, unk18, unk1c;
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    hkFourTransposedPointsQ* m_kRotatedVertices;
    int m_rotatedSize;
    int m_rotatedCapacity;
    int m_iStridedVertexCount;
    void hkpConvexVerticesShape_getSupportingVertexImpl(const MatchVector& direction, MatchVector& supportingVertexOut) const;
};

// Finds the vertex with the maximum dot product against direction and writes its position and index to supportingVertexOut.
// @fnv 0x00d58ee0
// src: HAVOK_SRC 0x00d58ee0
void MatchShape::hkpConvexVerticesShape_getSupportingVertexImpl(const MatchVector& direction, MatchVector& supportingVertexOut) const
{
    const hkFourTransposedPointsQ* fv = m_kRotatedVertices;
    static const MatchVector minusMax(-3.40282e+38f);

    MatchVector bestDot = minusMax;
    MatchVector bestIndices;
    bestIndices.m_vComponents = _mm_setzero_ps();
    MatchVector curIndices = DAT_010d9fe0;

    MatchVector dirX;
    dirX.m_vComponents = _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0x00);
    MatchVector dirY;
    dirY.m_vComponents = _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0x55);
    MatchVector dirZ;
    dirZ.m_vComponents = _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xaa);

    const hkFourTransposedPointsQ* p = fv;
    for (int i = 0; i < m_rotatedSize * 4; i += 4)
    {
        MatchVector dot;
        dot.setMul4(p->m_uiX,dirX); dot.addMul4(p->m_uiY,dirY); dot.addMul4(p->m_uiZ,dirZ);
        SelectBits mask = bestDot.compare(dot);
        bestDot.setSelect4(mask, dot, bestDot);
        bestIndices.selectIndex(mask,curIndices,bestIndices);
        curIndices.m_vComponents = _mm_add_ps(DAT_010d0fa0.m_vComponents,curIndices.m_vComponents);
        p++;
    }

    int a = (bestDot(0) > bestDot(1)) ? 0 : 1;
    int b = (bestDot(2) > bestDot(3)) ? 2 : 3;
    int best = (bestDot(a) > bestDot(b)) ? a : b;
    int vertexId = (int)bestIndices(best);

    const hkFourTransposedPointsQ& v = fv[(unsigned int)vertexId >> 2];
    int k = vertexId & 3;
    supportingVertexOut(0) = v.m_uiX(k);
    supportingVertexOut(1) = v.m_uiY(k);
    supportingVertexOut(2) = v.m_uiZ(k);
    supportingVertexOut.setInt24W(vertexId);
}

extern void* DAT_010d0fc4;
extern "C" void _ReadWriteBarrier();

struct InputValues {
    int x;
    int y;
    int z;
};

struct FinalCall {
    void hkpConvexVerticesShape_copyVertexData(int x, int z, int y);
};

__forceinline void AllocateVectors(
    hkMemoryAllocator& allocator,
    int count,
    Vector4D5A360*& data,
    int& capacity)
{
    int bytes = count * 16;
    data = static_cast<Vector4D5A360*>(allocator.bufAlloc(bytes));
    capacity = bytes / 16;
}

__forceinline void ResizePlanes(
    hkArray<Vector4D5A360, ArrayD5A360Policy>& planes,
    const hkArray<Vector4D5A360, ArrayD5A360Policy>& source)
{
    hkMemoryAllocator& allocator = hkMemoryRouter_getInstance().heap();

    if ((planes.m_iCapacityState & 0x3fffffff) < source.m_iElementCount) {
        if ((planes.m_iCapacityState & 0x80000000) == 0)
            allocator.bufFree(
                planes.m_data,
                (planes.m_iCapacityState & 0x3fffffff) * 16);

        AllocateVectors(
            allocator,
            source.m_iElementCount,
            planes.m_data,
            planes.m_iCapacityState);
    }

    planes.m_iElementCount = source.m_iElementCount;
    CopyD5A360(planes.m_data, source.m_data, planes.m_iElementCount);
}

template<class T> struct ConstructedArray : hkArray<T, ArrayD5A360Policy> {
    __forceinline ConstructedArray() : hkArray<T, ArrayD5A360Policy>() {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
};

// Local constructor fallback: shared shape lacks this constructor and its inline base initialization.
struct RefPart {
    void** m_ppVirtualMethodTable;
    unsigned short unk04;
    unsigned short referenceCount;
    __forceinline RefPart() : referenceCount(1) {}
};
struct ShapePart : RefPart {
    int userData;
    int type;
    __forceinline ShapePart(int shapeType) { userData = 0; type = shapeType; m_ppVirtualMethodTable = &DAT_010d0fc4; }
};
struct SpherePart : ShapePart {
    __forceinline SpherePart(int shapeType) : ShapePart(shapeType) {}
};
struct ConvexPart : SpherePart {
    float radius;
    __forceinline ConvexPart(int shapeType, float r) : SpherePart(shapeType) { radius = r; }
};
struct FUN_00d59bd0 : ConvexPart {
    int unk14;
    int unk18;
    int unk1C;
    Vector4D5A360 halfExtents;
    Vector4D5A360 center;
    ConstructedArray<Vector4D5A360> rotated;
    int numVertices;
    int convexPiece;
    ConstructedArray<Vector4D5A360> planes;
    int connectivity;

    FUN_00d59bd0(
        InputValues* input,
        const hkArray<Vector4D5A360, ArrayD5A360Policy>& source,
        float r);
};

// Constructs the base with type 6 and radius r, copies source into planes, then calls FUN_00d59900 with input->x, input->z and input->y.
// @fnv 0x00d59bd0
FUN_00d59bd0::FUN_00d59bd0(InputValues* input, const hkArray<Vector4D5A360, ArrayD5A360Policy>& source, float r)
    : ConvexPart(6, r), convexPiece(0), connectivity(0)
{
    ResizePlanes(planes, source);
    ((FinalCall*)this)->hkpConvexVerticesShape_copyVertexData(input->x, input->z, input->y);
}

extern "C" LocalM128 _mm_set_ss(float);
extern "C" float _mm_cvtss_f32(LocalM128);
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_loadu_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" void _ReadWriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" void _WriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" unsigned long DAT_0126835c;
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
extern LocalM128 DAT_010c7160;
extern float DAT_01012054;

struct ConvexPiece;

struct TimerRec { const char* m_name; unsigned int m_uiCommandId; unsigned int unk08; };
struct TimerStream { int unk00; TimerRec* m_cur; int unk08; TimerRec* m_kRayEnd; };

__forceinline void TimerMark(const char* name, int kind)
{
    TimerStream* s = (TimerStream*)TlsGetValue(DAT_0126835c);
    TimerRec* r = s->m_cur;
    if (r < s->m_kRayEnd) {
        r->m_name = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        r->m_uiCommandId = t;
        s->m_cur = r + 1;
    }
}

__forceinline void TimerMarkOut(const char* name, int kind)
{
    TimerStream* s = (TimerStream*)TlsGetValue(DAT_0126835c);
    TimerRec* r = s->m_cur;
    if (r < s->m_kRayEnd) {
        r->m_name = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        r->m_uiCommandId = t;
        s->m_cur = r + 1;
    }
}

struct hkBoolRet { char m_cBooleanValue; hkBoolRet(bool b) { m_cBooleanValue = (char)b; } };

// Preserve the original uninitialized scratch vectors.
__forceinline V4::V4() {}

struct FourVecs { float xs[4]; float ys[4]; float zs[4]; };

void __cdecl ResizeAudioStream(void*, void*, int);



struct ConvexPiece {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    const unsigned char* m_bytes;
    int unk20, unk24;
    const unsigned short* m_kIndices;
    int m_numFaces;
};

struct RayInput { V4 m_vFrom; V4 m_vTo; };
struct RayOutput {
    V4 m_vHitNormal;
    float m_fHitFraction;
    int unk14, unk18, unk1c;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};

static __forceinline float LowFloat(LocalM128 a) { float x; _mm_store_ss(&x, a); return x; }

static __forceinline void GetVert(V4& p, const FourVecs* fv, unsigned int b)
{
    unsigned int c = b & 3;
    const FourVecs& g = fv[b >> 2];
    p.x = g.xs[c];
    p.y = g.ys[c];
    p.z = g.zs[c];
}

static __forceinline float Dot4xyz1(const V4& p, const V4& v)
{
    LocalM128 q = *(const LocalM128*)&p;
    LocalM128 xx = _mm_mul_ps(q, *(const LocalM128*)&v);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
    LocalM128 zw = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(q, q, 0xff));
    float r;
    _mm_store_ss(&r, _mm_add_ps(xy, zw));
    return r;
}

// Local fallback: the shared IntersectRayWithShape signature changes the generated code.
struct ConvexVertsShape {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    FourVecs* m_rotated;
    int m_rotatedSize;
    int m_rotatedCap;
    int m_iStridedVertexCount;
    ConvexPiece* m_piece;
    hkArrayBase<V4> m_kPlaneArray;
    hkBoolRet hkpConvexVerticesShape_castRayImpl(const RayInput& input, RayOutput& results);
};

// @fnv 0x00d592a0
// src: HAVOK_SRC 0x00d592a0
hkBoolRet ConvexVertsShape::hkpConvexVerticesShape_castRayImpl(const RayInput& input, RayOutput& results)
{
    TimerMark("TtrcConvexVert", 0);
    if (m_kPlaneArray.m_iElementCount == 0) {
        ConvexPiece* buildPiece = m_piece;
        if (buildPiece) {
            const unsigned short* face = buildPiece->m_kIndices;
            int n = buildPiece->m_numFaces - 1;
            if (n > 0) {
                struct FaceScratch { V4 p1, p0, p2, plane; LocalM128 zero, three, half; };
                FaceScratch scratch;
                scratch.zero = _mm_set_ss(DAT_01011d78);
                scratch.three = _mm_set_ss(DAT_01017718);
                scratch.half = _mm_set_ss(DAT_01016248);
                hkArrayBase<V4>* arr = &m_kPlaneArray;
                int count = n;
                do {
                    const unsigned char* tri = buildPiece->m_bytes + *face;
                    GetVert(scratch.p0, m_rotated, tri[0]);
                    GetVert(scratch.p1, m_rotated, tri[1]);
                    GetVert(scratch.p2, m_rotated, tri[2]);
                    LocalM128 a = *(LocalM128*)&scratch.p0;
                    LocalM128 d1 = _mm_sub_ps(*(LocalM128*)&scratch.p1, a);
                    LocalM128 d2 = _mm_sub_ps(*(LocalM128*)&scratch.p2, a);
                    LocalM128 cross = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(d1, d1, 0xc9), _mm_shuffle_ps(d2, d2, 0xd2)),
                        _mm_mul_ps(_mm_shuffle_ps(d1, d1, 0xd2), _mm_shuffle_ps(d2, d2, 0xc9)));
                    LocalM128 sq = _mm_mul_ps(cross, cross);
                    LocalM128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
                    len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), len);
                    LocalM128 r = _mm_rsqrt_ss(len);
                    LocalM128 scale = _mm_mul_ss(_mm_mul_ss(scratch.half, r),
                        _mm_sub_ss(scratch.three, _mm_mul_ss(_mm_mul_ss(len, r), r)));
                    scale = _mm_andnot_ps(_mm_cmpeq_ss(len, scratch.zero), scale);
                    *(LocalM128*)&scratch.plane = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), cross);
                    LocalM128 pd = _mm_mul_ps(*(LocalM128*)&scratch.plane, a);
                    LocalM128 dot = _mm_add_ss(_mm_shuffle_ps(pd, pd, 0x55), pd);
                    dot = _mm_add_ss(_mm_shuffle_ps(pd, pd, 0xaa), dot);
                    scratch.plane.w = LowFloat(_mm_sub_ss(DAT_010c7160, dot));
                    hkMemoryRouter& router = hkMemoryRouter_getInstance();
                    if (arr->m_iElementCount == (arr->m_iCapacityState & 0x3fffffff)) {
                        ResizeAudioStream(router.m_heap, arr, 0x10);
                    }
                    *(LocalM128*)&arr->m_data[arr->m_iElementCount] = *(LocalM128*)&scratch.plane;
                    arr->m_iElementCount++;
                    ++face;
                } while (--count != 0);
            }
        }
    }

    float lo = -1.0f;
    float hi = results.m_fHitFraction;
    LocalM128 best = _mm_setzero_ps();
    int i = m_kPlaneArray.m_iElementCount - 1;
    if (i >= 0) {
    ConvexPiece* piece = m_piece;
    LocalM128 from = *(const LocalM128*)&input.m_vFrom;
    LocalM128 to = *(const LocalM128*)&input.m_vTo;
    do {
        LocalM128 q;
        if(piece) q = *(const LocalM128*)&m_kPlaneArray.m_data[i];
        else q = _mm_load_ps(&m_kPlaneArray.m_data[i].x);
        LocalM128 a = _mm_mul_ps(q, from);
        LocalM128 axy = _mm_add_ss(_mm_shuffle_ps(a, a, 0x55), a);
        LocalM128 azw = _mm_add_ss(_mm_shuffle_ps(a, a, 0xaa), _mm_shuffle_ps(q, q, 0xff));
        float d0 = LowFloat(_mm_add_ps(axy, azw));
        LocalM128 b = _mm_mul_ps(q, to);
        LocalM128 bxy = _mm_add_ss(_mm_shuffle_ps(b, b, 0x55), b);
        LocalM128 bzw = _mm_add_ss(_mm_shuffle_ps(b, b, 0xaa), _mm_shuffle_ps(q, q, 0xff));
        float d1 = LowFloat(_mm_add_ps(bxy, bzw));
        if (d0 >= 0.0f) {
            if (d1 >= 0.0f) {
                TimerMarkOut("Et", 1);
                return false;
            }
            float t = (float)(d0 / (d0 - d1));
            if (t >= lo) {
                lo = t;
                best = q;
            }
        }
        else {
            if (!(d1 >= 0.0f)) {
                continue;
            }
            float t = (float)(d0 / (d0 - d1));
            if (!(t > hi)) {
                hi = t;
            }
        }
        if (hi < lo) {
            TimerMarkOut("Et", 2);
            return false;
        }
    } while (--i >= 0);
    }
    if (lo < 0.0f) {
        TimerMarkOut("Et", 3);
        return false;
    }
    results.m_fHitFraction = lo;
    *(LocalM128*)&results.m_vHitNormal = best;
    results.m_uiShapeKeys[results.m_uiShapeKeyIndex] = -1;
    TimerMarkOut("Et", 0);
    return true;
}

static __forceinline void VertArray96Q_SetSizeAndGrow(hkArrayBase<hkVector4q>& self, int n);

static __forceinline void VertArray96Q_SetSizeAndGrow(hkArrayBase<hkVector4q>& self, int n)
{
        hkMemoryAllocator& alloc = hkMemoryRouter_getInstance().heap();
        int cap = self.m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap + cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(reinterpret_cast<SpliceAllocator&>(alloc), (&self), newSize, sizeof(hkVector4q));
        }
        self.m_iElementCount = n;
    }

// @fnv 0x00d59200
void hkpConvexVerticesShape::GetOriginalVertices(hkArray<hkVector4>& output) const
{
    hkArrayBase<hkVector4q>& vertices = reinterpret_cast<hkArrayBase<hkVector4q>&>(output);
    VertArray96Q_SetSizeAndGrow(vertices, m_iStridedVertexCount);
    for (int i = 0; i < m_iStridedVertexCount; i++)
    {
        int a = i / 4;
        int b = i & 3;
        vertices[i].set(reinterpret_cast<const FourVectorsQ*>(m_kRotatedVertices.m_data)[a].m_uiX(b), reinterpret_cast<const FourVectorsQ*>(m_kRotatedVertices.m_data)[a].m_uiY(b), reinterpret_cast<const FourVectorsQ*>(m_kRotatedVertices.m_data)[a].m_uiZ(b), 0.0f);
    }
}

extern LocalM128 DAT_010c71d0;


void __cdecl ArrayUtilReserve_c908c0(hkMemoryAllocator& alloc, void* array, int numElements, int sizeElem);

__forceinline float& PacketCallLocal_00d59cc0::operator()(int i) { return m_vComponents.m128_f32[i]; }

struct FourVectors
{
    PacketCallLocal_00d59cc0 m_uiX;
    PacketCallLocal_00d59cc0 m_uiY;
    PacketCallLocal_00d59cc0 m_uiZ;
};

template <class T>
static __forceinline void Array_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator& alloc, int n);

template <class T>
static __forceinline void Array__setSize(hkArrayBase<T>& self, hkMemoryAllocator& alloc, int n);

template <class T>
static __forceinline void Array_SetSizeAndGrow(hkArrayBase<T>& self, int n);

template <class T>
static __forceinline void Array_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator& alloc, int n)
{
        const int capacity = self.getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ArrayUtilReserve_c908c0(alloc, (&self), newSize, sizeof(T));
        }
    }

template <class T>
static __forceinline void Array__setSize(hkArrayBase<T>& self, hkMemoryAllocator& alloc, int n)
{
        Array_GrowArrayCapacity(self, alloc, n);
        self.m_iElementCount = n;
    }

template <class T>
static __forceinline void Array_SetSizeAndGrow(hkArrayBase<T>& self, int n)
{ Array__setSize(self, GetMemoryRouter_c85750()->heap(), n); }

struct Aabb
{
    LocalM128 m_kMinimumCorner;
    LocalM128 m_kMaximumCorner;

    __forceinline void getCenter(PacketCallLocal_00d59cc0& center) const
    {
        center.m_vComponents = _mm_mul_ps(_mm_add_ps(m_kMinimumCorner, m_kMaximumCorner), DAT_010c71d0);
    }
    __forceinline void getHalfExtents(PacketCallLocal_00d59cc0& halfExtents) const
    {
        halfExtents.m_vComponents = _mm_mul_ps(_mm_sub_ps(m_kMaximumCorner, m_kMinimumCorner), DAT_010c71d0);
    }
};

void __cdecl CalcAabb_cbeaf0(const float* vertexArray, int numVertices, int striding, Aabb& aabbOut);

// Local fallback: shared shape lacks FUN_00d59900 and named AABB members.
struct ConvexVerticesShape
{
    void* vtable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
    float unk14;
    float unk18;
    float unk1C;
    PacketCallLocal_00d59cc0 m_kAabbHalfExtents;
    PacketCallLocal_00d59cc0 m_kAabbCenter;
    hkArrayBase<FourVectors> m_kRotatedVertices;
    int m_iStridedVertexCount;

    void hkpConvexVerticesShape_copyVertexData(const float* vertexIn, int byteStriding, int numVertices);
};

// Stores numVertices, copies vertexIn into m_kRotatedVertices padded to a multiple of four, and computes the AABB center and half-extents.
// @fnv 0x00d59900
// src: XBOX_PDB 0x00d59900
void ConvexVerticesShape::hkpConvexVerticesShape_copyVertexData(const float* vertexIn, int byteStriding, int numVertices)
{
    m_iStridedVertexCount = numVertices;
    int paddedSize = (numVertices + 3) & ~3;
    Array_SetSizeAndGrow(m_kRotatedVertices, paddedSize / 4);

    const float* v = vertexIn;
    int i;
    for (i = 0; i < numVertices; i++)
    {
        int a = (unsigned)i >> 2;
        int b = i & 3;
        m_kRotatedVertices[a].m_uiX(b) = v[0];
        m_kRotatedVertices[a].m_uiY(b) = v[1];
        m_kRotatedVertices[a].m_uiZ(b) = v[2];
        v = (const float*)((const char*)v + byteStriding);
    }

    v = (const float*)((const char*)v - byteStriding);
    // i == numVertices <= paddedSize; strict < drops the unroller's redundant
    // overflow guard. Equality still exits through the scalar cmp.
    __assume(i < paddedSize);
    for (; i < paddedSize; i++)
    {
        int a = i >> 2;
        int b = i & 3;
        m_kRotatedVertices[a].m_uiX(b) = v[0];
        m_kRotatedVertices[a].m_uiY(b) = v[1];
        m_kRotatedVertices[a].m_uiZ(b) = v[2];
    }

    Aabb aabb;
    CalcAabb_cbeaf0(vertexIn, numVertices, byteStriding, aabb);
    aabb.getHalfExtents(m_kAabbHalfExtents);
    aabb.getCenter(m_kAabbCenter);
}

template <class T, class A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray<T, A>& other)
{
    A::assign(*this, other);
    return *this;
}
