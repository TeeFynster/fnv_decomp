#include "../../../../../../../include/hkArray.h"
// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Keep the original intrinsic representation: the CRT's byte-array lanes
// make VC9 add a stack cookie to this function.
#define _INCLUDED_MM2
// Exe 0x00d59f40 FUN_00d59f40: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" {
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
}

#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpConvexVerticesConnectivity.h"
#include "../../../../../../../include/hkpConvexVerticesShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"

struct ThreadMemory;

extern "C" {
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    double __cdecl sqrt(double) throw();
    ThreadMemory& __cdecl hkMemoryRouter_getInstance() throw();
}

struct Allocator {

    virtual void Method0();

    virtual void Method1();

    virtual void Method2();

    virtual void* allocateChunk(int* reqSizeInOut) throw();

    virtual void deallocateChunk(void* ptr, int size) throw();

};



struct ThreadMemory {

    void* m_stackCurrent;

    int unk04;

    int unk08;

    int unk0C;

    Allocator* m_pMemoryAllocator;



    Allocator& heap() throw() { return *m_pMemoryAllocator; }

};



struct FUN_00d5a4c0_Helper {

    void ProcessAndReturnValue_00d5a4c0(void* mem, int index, const void* src, int num) throw();

};



static __forceinline void copyVecs(hkVector4* dst, const hkVector4* src, int n) throw() {

    for (int i = 0; i < n; ++i) {

        *(LocalM128*)&dst[i] = *(const LocalM128*)&src[i];

    }

}



static __forceinline void copy16(void* dst, const void* src) throw() {

    unsigned __int64* d = (unsigned __int64*)dst;

    const unsigned __int64* s = (const unsigned __int64*)src;

    int i = 0;

    do {

        d[i] = s[i];

    } while (++i < 2);

}



static __forceinline void PlaneArray_initialize(hkArrayBase<hkVector4>& self, hkpConvexVerticesShape* shape) throw()
{

        self.m_data = 0;

        self.m_iCapacityState = 0x80000000;

        const hkArray<hkVector4>& other = shape->m_kVertexPositions;

        Allocator& alloc = ((ThreadMemory*)&hkMemoryRouter_getInstance())->heap();

        if (other.m_iElementCount > 0) {

            int req = other.m_iElementCount * 16;

            self.m_data = (hkVector4*)alloc.allocateChunk(&req);

            self.m_iCapacityState = req / 16;

        }

        self.m_iElementCount = other.m_iElementCount;

        copyVecs(self.m_data, other.m_data, self.m_iElementCount);

    }
static __forceinline void PlaneArray_removeAt(hkArrayBase<hkVector4>& self, int index) throw();

static __forceinline void PlaneArray_ClearAndRelease(hkArrayBase<hkVector4>& self, Allocator& alloc) throw();

static __forceinline void PlaneArray_destroy(hkArrayBase<hkVector4>& self) throw();

static __forceinline void PlaneArray_removeAt(hkArrayBase<hkVector4>& self, int index) throw()
{

        self.m_iElementCount--;

        if (self.m_iElementCount != index) {

            copy16(&self.m_data[index], &self.m_data[self.m_iElementCount]);

        }

    }

static __forceinline void PlaneArray_ClearAndRelease(hkArrayBase<hkVector4>& self, Allocator& alloc) throw()
{

        self.m_iElementCount = 0;

        if ((self.m_iCapacityState & 0x80000000) == 0) {

            alloc.deallocateChunk(self.m_data, (self.m_iCapacityState & 0x3fffffff) * 16);

        }

        self.m_data = 0;

        self.m_iCapacityState = 0x80000000;

    }

static __forceinline void PlaneArray_destroy(hkArrayBase<hkVector4>& self) throw()
{

        PlaneArray_ClearAndRelease(self, ((ThreadMemory*)&hkMemoryRouter_getInstance())->heap());

    }

struct PlaneArrayPolicy
{
    static __forceinline void destroy(hkArrayBase<hkVector4>& self) { PlaneArray_destroy(self); }
};



struct LocalArray {

    hkVector4* m_data;

    int m_iElementCount;

    int m_iCapacityState;

    void* m_initialStack;



    __forceinline LocalArray(int capacity) throw() {

        m_data = 0;

        m_iElementCount = 0;

        m_iCapacityState = 0x80000000;

        ThreadMemory* mem = (ThreadMemory*)&hkMemoryRouter_getInstance();

        void* p = mem->m_stackCurrent;

        int nBytes = (capacity * 16 + 127) & ~127;

        mem->m_stackCurrent = (char*)p + nBytes;

        m_data = (hkVector4*)p;

        m_initialStack = p;

        m_iCapacityState = capacity | 0x80000000;

    }



    __forceinline ~LocalArray() throw() {

        void* initial = m_initialStack;

        if (initial == m_data) {

            m_iElementCount = 0;

        }

        ((ThreadMemory*)&hkMemoryRouter_getInstance())->m_stackCurrent = initial;

        ClearAndRelease(((ThreadMemory*)&hkMemoryRouter_getInstance())->heap());

    }



    __forceinline void ClearAndRelease(Allocator& alloc) throw() {

        m_iElementCount = 0;

        if ((m_iCapacityState & 0x80000000) == 0) {

            alloc.deallocateChunk(m_data, (m_iCapacityState & 0x3fffffff) * 16);

        }

        m_data = 0;

        m_iCapacityState = 0x80000000;

    }

};



static __forceinline float dot3_vec(LocalM128 a, LocalM128 b) throw() {

    LocalM128 m = _mm_mul_ps(a, b);

    LocalM128 shuf_y = _mm_shuffle_ps(m, m, 0x55);

    LocalM128 sum_xy = _mm_add_ss(shuf_y, m);

    LocalM128 shuf_z = _mm_shuffle_ps(m, m, 0xaa);

    LocalM128 sum_xyz = _mm_add_ss(shuf_z, sum_xy);

    float r;

    _mm_store_ss(&r, sum_xyz);

    return r;

}



static __forceinline void appendPlane(hkArray<hkVector4>& array, const hkVector4& v) throw() { copyVecs(array.m_data + array.m_iElementCount, &v, 1); ++array.m_iElementCount; }




extern "C" LocalM128 _mm_load_ss(const float*);
class PlaneScalar {
    LocalM128 value;
public:
    PlaneScalar() {}
    PlaneScalar(float f) { value = _mm_load_ss(&f); }
    PlaneScalar(const LocalM128& q): value(q) {}
    operator float() const { float f; _mm_store_ss(&f,value); return f; }
    __forceinline LocalM128 splat() const { return _mm_shuffle_ps(value,value,0); }
};
enum PlaneResult { PlaneSuccess, PlaneFailure };
class PlaneVector {
    LocalM128 value;
public:
    __forceinline operator LocalM128() const { return value; }
    __forceinline void operator=(const PlaneVector& v) { value=v.value; }
    __forceinline void difference(const PlaneVector& a,const PlaneVector& b) { value=_mm_sub_ps(a.value,b.value); }
    __forceinline void cross(const PlaneVector& a,const PlaneVector& b) {
        LocalM128 p=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xc9),_mm_shuffle_ps(b.value,b.value,0xd2));
        LocalM128 q=_mm_mul_ps(_mm_shuffle_ps(a.value,a.value,0xd2),_mm_shuffle_ps(b.value,b.value,0xc9));
        value=_mm_sub_ps(p,q);
    }
    __forceinline PlaneScalar dot(const PlaneVector& b) const {
        LocalM128 products=_mm_mul_ps(value,b.value);
        LocalM128 pair=_mm_add_ss(_mm_shuffle_ps(products,products,0x55),products);
        return _mm_add_ss(_mm_shuffle_ps(products,products,0xaa),pair);
    }
    __forceinline PlaneScalar squared() const { return dot(*this); }
    __forceinline void scale(const PlaneScalar& s) { value=_mm_mul_ps(s.splat(),value); }
    __forceinline PlaneResult normalize() {
        const float square=squared();
        if (square!=0.0f) {
            scale(1.0f/(float)sqrt((double)square));
            return PlaneSuccess;
        }
        return PlaneFailure;
    }
};

struct FaceVertex { float x, y, z, w; };

struct PlaneScanMath {

    LocalM128 fixedNormal;

    LocalM128& work;

    __forceinline PlaneScanMath(LocalM128 n, LocalM128& w) throw() : fixedNormal(n), work(w) {}

    __forceinline void scale(const LocalM128& v) throw() { fixedNormal = _mm_mul_ps(v, fixedNormal); }

    __forceinline float evaluate(const LocalM128& p) throw() {

        work = p; work = _mm_mul_ps(work, fixedNormal);

        LocalM128 y = _mm_shuffle_ps(work, work, 0x55);

        y = _mm_add_ss(y, work);

        LocalM128 z = _mm_shuffle_ps(work, work, 0xaa);

        z = _mm_add_ss(z, y);

        float result;

        _mm_store_ss(&result, z);

        return result;

    }

};



// The original extraction call cannot throw; retain that contract around the shared declaration.
__forceinline void GetShapeVertices(const hkpConvexVerticesShape* shape, hkArray<hkVector4>& vertices) throw()
{
    shape->FUN_00d59200(vertices);
}

// @fnv 0x00d59f40
// src: GUESS 0x00d59f40 (confidence: low)
void hkpConvexVerticesShape::ProcessEntries_00d59f40()

{

    hkpConvexVerticesShape* shape = this;

    hkArray<hkVector4, PlaneArrayPolicy> planes(FinishingFlag(0)); PlaneArray_initialize(planes, shape);

    hkArray<hkVector4>& planeEquations = shape->m_kVertexPositions;

    shape->m_kVertexPositions.m_iElementCount = 0;

    int numVertices = shape->m_iStridedVertexCount;



    LocalArray vertices(numVertices);

    GetShapeVertices(shape, reinterpret_cast<hkArray<hkVector4>&>(vertices));



    int vertOffset = 0;

    for (int faceIdx = 0; faceIdx < shape->m_pConnectivity->m_kNumVerticesPerFace.m_iElementCount; ++faceIdx) {

        if (planes.GetLogicalSize() == 0) {

            break;

        }

        int numVerts = shape->m_pConnectivity->m_kNumVerticesPerFace.m_data[faceIdx];

        if (numVerts < 3) {

            continue;

        }

        int idx0 = shape->m_pConnectivity->m_kVertexIndices.m_data[vertOffset];

        int idx1 = shape->m_pConnectivity->m_kVertexIndices.m_data[vertOffset + 1];

        int idx2 = shape->m_pConnectivity->m_kVertexIndices.m_data[vertOffset + 2];

        vertOffset += numVerts;



        // Preserve the original scalar copies before the SIMD calculation.
        struct FaceVertices { FaceVertex v1, v0, v2, normal; } face;

        face.v0 = reinterpret_cast<const FaceVertex&>(vertices.m_data[idx0]);

        face.v1 = reinterpret_cast<const FaceVertex&>(vertices.m_data[idx1]);

        face.v2 = reinterpret_cast<const FaceVertex&>(vertices.m_data[idx2]);



        LocalM128 e1 = _mm_sub_ps(*(LocalM128*)&face.v1, *(LocalM128*)&face.v0);

        LocalM128 e2 = _mm_sub_ps(*(LocalM128*)&face.v2, *(LocalM128*)&face.v0);



        LocalM128 xmm2 = _mm_shuffle_ps(e2, e2, 0xc9);

        LocalM128 xmm3 = _mm_shuffle_ps(e1, e1, 0xd2);

        LocalM128 shuf_e2 = _mm_shuffle_ps(e2, e2, 0xd2);

        xmm2 = _mm_mul_ps(xmm2, xmm3);

        LocalM128 shuf_e1 = _mm_shuffle_ps(e1, e1, 0xc9);

        shuf_e2 = _mm_mul_ps(shuf_e2, shuf_e1);

        LocalM128& normal = *(LocalM128*)&face.normal;

        normal = _mm_sub_ps(shuf_e2, xmm2);



if (reinterpret_cast<PlaneVector&>(normal).normalize()==PlaneSuccess) {
    PlaneScanMath scan(normal,e1);
            int bestIdx = 0;

            float maxDot = scan.evaluate(*(LocalM128*)&planes[0]);

            for (int j = 1; j < planes.GetLogicalSize(); ++j) {

                float dot = scan.evaluate(*(LocalM128*)&planes[j]);

                if (dot > maxDot) {

                    maxDot = dot;

                    bestIdx = j;

                }

            }



            appendPlane(planeEquations, planes[bestIdx]);

            PlaneArray_removeAt(planes, bestIdx);

        } else {

            appendPlane(planeEquations, planes[0]);

        }

    }



    if (planes.GetLogicalSize() > 0) {

        int index = shape->m_kVertexPositions.m_iElementCount;

        ThreadMemory* mem = (ThreadMemory*)&hkMemoryRouter_getInstance();

        reinterpret_cast<FUN_00d5a4c0_Helper*>(&planeEquations)->ProcessAndReturnValue_00d5a4c0(

            mem->m_pMemoryAllocator, index, planes.begin(), planes.GetLogicalSize());

    }

}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
