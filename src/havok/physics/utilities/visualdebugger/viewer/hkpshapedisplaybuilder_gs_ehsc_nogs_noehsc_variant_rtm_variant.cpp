// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkAabb.h"
// local form of hkVector4: 0x00ddfd10 needs original typed calls (shared extent 4708 vs 4724).


// Define FNV_VECTOR_USE_LOCAL_SSE when __m128 and intrinsics are already declared.
#if !defined(FNV_VECTOR_USE_LOCAL_SSE)
#include <xmmintrin.h>
#endif

class Scalar;
class Comparison;
class Transform;
class hkRotation;

class DisplayVectorCallLocal_00ddfd10
{
public:
    union
    {
        __m128 q;
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };

    __forceinline DisplayVectorCallLocal_00ddfd10() {}
    __forceinline DisplayVectorCallLocal_00ddfd10(const DisplayVectorCallLocal_00ddfd10& vector) : q(vector.q) {}
    __forceinline DisplayVectorCallLocal_00ddfd10(const __m128& vector) : q(vector) {}
    DisplayVectorCallLocal_00ddfd10(float x, float y, float z);
    __forceinline DisplayVectorCallLocal_00ddfd10& operator=(const DisplayVectorCallLocal_00ddfd10& vector)
    {
        q = vector.q;
        return *this;
    }
    __forceinline void operator=(const __m128& vector)
    {
        q = vector;
    }
    operator __m128() const;
    DisplayVectorCallLocal_00ddfd10 operator*(float value) const;
    DisplayVectorCallLocal_00ddfd10 operator+(const DisplayVectorCallLocal_00ddfd10& vector) const;
    DisplayVectorCallLocal_00ddfd10 operator-() const;
    float& operator()(int index);
    const float& operator()(int index) const;
    __m128& packet();
    const __m128& packet() const;

    void set(float x, float y, float z, float w = 0.0f);
    void zero();
    void setZero4();
    void subtract(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void sub(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void setSub(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void setSub4(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void add(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void setAdd(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void setAdd4(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void add4(const DisplayVectorCallLocal_00ddfd10& vector);
    void mul(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void mul4(const DisplayVectorCallLocal_00ddfd10& vector);
    void mul4(const Scalar& scalar);
    void multiply(const Scalar& scalar);
    void scale(const Scalar& scalar);
    void product(const Scalar& scalar, const DisplayVectorCallLocal_00ddfd10& vector);
    void cross(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void setCross(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b);
    void negate(const DisplayVectorCallLocal_00ddfd10& vector);
    void setNeg4(const DisplayVectorCallLocal_00ddfd10& vector);
    void addMul(const DisplayVectorCallLocal_00ddfd10& a, __m128 scale, const DisplayVectorCallLocal_00ddfd10& b);
    void setAddMul4(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b, const Scalar& scalar);
    void interpolate(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b, const Scalar& t);
    void setInterpolate4(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b, const Scalar& t);
    void Interpolate(const DisplayVectorCallLocal_00ddfd10& oldValue, const DisplayVectorCallLocal_00ddfd10& newValue, float factor);
    void SetTransformedPoint(const Transform& transform, const DisplayVectorCallLocal_00ddfd10& point);

    Scalar getSimdAt(int index) const;
    Scalar dot(const DisplayVectorCallLocal_00ddfd10& vector) const;
    Scalar dot3(const DisplayVectorCallLocal_00ddfd10& vector) const;
    float DotProduct(const DisplayVectorCallLocal_00ddfd10& vector);
    Scalar sum() const;
    Scalar norm() const;
    Scalar lengthSquared3() const;
    Scalar length3() const;
    float length() const;
    Scalar inverseLength() const;
    void normalize();
    void normalize3();
    Comparison compareLessThanZero4() const;
    int getMajorAxis() const;
    int maxAxisSecond() const;
    int maxAxis() const;
    float GetAngle();

    void SetComponents(float x, float y, float z);
    DisplayVectorCallLocal_00ddfd10 SubtractIntoVector(const DisplayVectorCallLocal_00ddfd10& vector);
    DisplayVectorCallLocal_00ddfd10 FUN_00439e90(const DisplayVectorCallLocal_00ddfd10& vector);
    void ScaleComponents(float value);
    void Unitize_004a0c10();
    void normalize_005611c0();
    void setMul(const DisplayVectorCallLocal_00ddfd10* a, const DisplayVectorCallLocal_00ddfd10* b);
    void setMulInverse(const DisplayVectorCallLocal_00ddfd10* a, const DisplayVectorCallLocal_00ddfd10* b);
    void hkQuaternion_getAxis(DisplayVectorCallLocal_00ddfd10* vector);
    void setTransformedPos_00c7f640(const Transform& transform, const DisplayVectorCallLocal_00ddfd10& point);
    void hkQuaternion_setAxisAngle(const DisplayVectorCallLocal_00ddfd10* vector, float value);
    void FUN_00cb26e0(const hkRotation* rotation);

    template <int I> void splat(const DisplayVectorCallLocal_00ddfd10& vector);

    static const DisplayVectorCallLocal_00ddfd10& getZero();
};

#include "../../../../../../include/Transform.h"

// Preserve uninitialized output bounds; getAabb fills every component.
__forceinline hkAabb::hkAabb()
{}

struct S_00ddfcd0_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};
struct S_00ddfcd0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddfcd0_Allocator* m_pStreamAllocator;
    S_00ddfcd0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddfcd0_Router* hkMemoryRouter_getInstance();
struct S_00ddfcd0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00ddfcd0_RefObj() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~S_00ddfcd0_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00ddfcd0_RefObj* b = static_cast<S_00ddfcd0_RefObj*>(hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};
struct S_00ddfcd0_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00ddfcd0_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct S_00ddfcd0_Obj : S_00ddfcd0_RefObj
{
    S_00ddfcd0_Array m_ppData;
    S_00ddfcd0_Obj() throw()
    {}
    virtual ~S_00ddfcd0_Obj() throw();
};
S_00ddfcd0_RefObj* hkpUserShapeDisplayBuildercreate();

#include <xmmintrin.h>
class Scalar
{
    __m128 value;

  public:
    __forceinline Scalar(const __m128& v) : value(v)
    {}
    __forceinline Scalar(float f)
    {
        value = _mm_load_ss(&f);
    }
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
    __forceinline const __m128& quad() const
    {
        return value;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
__forceinline DisplayVectorCallLocal_00ddfd10::operator __m128() const
{
    return q;
}
__forceinline float& DisplayVectorCallLocal_00ddfd10::operator()(int n)
{
    return reinterpret_cast<float*>(&q)[n];
}
__forceinline const float& DisplayVectorCallLocal_00ddfd10::operator()(int n) const
{
    return reinterpret_cast<const float*>(&q)[n];
}
__forceinline void DisplayVectorCallLocal_00ddfd10::setZero4()
{
    q = _mm_setzero_ps();
}
__forceinline void DisplayVectorCallLocal_00ddfd10::set(float a, float b, float c, float d)
{
    q = _mm_setr_ps(a, b, c, d);
}
__forceinline void DisplayVectorCallLocal_00ddfd10::setSub4(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b)
{
    q = _mm_sub_ps(a.q, b.q);
}
__forceinline void DisplayVectorCallLocal_00ddfd10::setAdd4(const DisplayVectorCallLocal_00ddfd10& a, const DisplayVectorCallLocal_00ddfd10& b)
{
    q = _mm_add_ps(a.q, b.q);
}
__forceinline void DisplayVectorCallLocal_00ddfd10::add4(const DisplayVectorCallLocal_00ddfd10& b)
{
    q = _mm_add_ps(q, b.q);
}
__forceinline void DisplayVectorCallLocal_00ddfd10::mul4(const DisplayVectorCallLocal_00ddfd10& b)
{
    q = _mm_mul_ps(q, b.q);
}
__forceinline void DisplayVectorCallLocal_00ddfd10::mul4(const Scalar& x)
{
    q = _mm_mul_ps(x.broadcast(), q);
}
__forceinline Scalar DisplayVectorCallLocal_00ddfd10::dot3(const DisplayVectorCallLocal_00ddfd10& b) const
{
    __m128 s = _mm_mul_ps(q, b.q);
    __m128 y = _mm_shuffle_ps(s, s, 0x55), z = _mm_shuffle_ps(s, s, 0xaa);
    return _mm_add_ss(z, _mm_add_ss(y, s));
}
__forceinline Scalar DisplayVectorCallLocal_00ddfd10::length3() const
{
    return _mm_sqrt_ss(dot3(*this).quad());
}
__forceinline void DisplayVectorCallLocal_00ddfd10::SetTransformedPoint(const Transform& m, const DisplayVectorCallLocal_00ddfd10& p)
{
    setTransformedPos_00c7f640(m, p);
}
extern DisplayVectorCallLocal_00ddfd10 DAT_01267e30, DAT_01017d10;
__forceinline int DisplayVectorCallLocal_00ddfd10::getMajorAxis() const
{
    DisplayVectorCallLocal_00ddfd10 v;
    v = _mm_and_ps(q, (__m128)DAT_01017d10);
    return v(0) < v(1) ? (v(1) < v(2) ? 2 : 1) : (v(0) < v(2) ? 2 : 0);
}
__forceinline const DisplayVectorCallLocal_00ddfd10& DisplayVectorCallLocal_00ddfd10::getZero()
{
    return DAT_01267e30;
}
struct Basis
{
    DisplayVectorCallLocal_00ddfd10 a, b, c;
    __forceinline DisplayVectorCallLocal_00ddfd10& column(int i)
    {
        return (&a)[i];
    }
    __forceinline float& operator()(int r, int c)
    {
        return column(c)(r);
    }
    __forceinline void setZero()
    {
        a.setZero4();
        b.setZero4();
        c.setZero4();
    }
    __forceinline void setIdentity()
    {
        setZero();
        float unit = 1;
        (*this)(0, 0) = unit;
        (*this)(1, 1) = unit;
        (*this)(2, 2) = unit;
    }
};
struct Rotation : Basis
{
};
__forceinline Transform& Transform::operator=(const Transform& m)
{
    FUN_00c6cd60(m);
    return *this;
}
__forceinline void Transform::SetProduct(const Transform& a, const Transform& b)
{
    hkTransform_setMul(a, b);
}
__forceinline void Transform::setIdentity()
{
    reinterpret_cast<Rotation*>(r)->setIdentity();
    reinterpret_cast<DisplayVectorCallLocal_00ddfd10*>(&r[3])->setZero4();
}
__forceinline void Transform::setTranslation(const DisplayVectorCallLocal_00ddfd10& p)
{
    *reinterpret_cast<DisplayVectorCallLocal_00ddfd10*>(&r[3]) = p;
}
extern Transform DAT_01268370;
__forceinline const Transform& Transform::GetIdentityTransform()
{
    return DAT_01268370;
}
class SphereRec
{
    DisplayVectorCallLocal_00ddfd10 pos;

  public:
    __forceinline SphereRec()
    {}
    __forceinline SphereRec(const DisplayVectorCallLocal_00ddfd10& p, float r)
    {
        pos = p;
        pos(3) = r;
    }
    __forceinline const DisplayVectorCallLocal_00ddfd10& getPosition() const
    {
        return pos;
    }
};
struct ShapeBuffer
{
    __declspec(align(16)) char bytes[512];
};
struct HeapView
{
    virtual void f0();
    virtual void f4();
    virtual void f8();
    virtual void fc();
    virtual void ReleaseBlock(void*, int);
};
void hkArrayUtil__reserve(S_00ddfcd0_Allocator*, void*, int, int);
void FUN_00c90940(S_00ddfcd0_Allocator*, void*, int);
template <class T> __forceinline void copyRange(T* p, int n, const T& v)
{
    for (int i = 0; i < n; ++i)
        p[i] = v;
}
template <class T> class ArrayBase
{
  public:
    T* data;
    int size, capacity;

  public:
    __forceinline ArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~ArrayBase()
    {}
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline const T* begin() const
    {
        return data;
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline void reserve(S_00ddfcd0_Allocator& heap, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int twice = 2 * cap;
            int next = n < twice ? twice : n;
            hkArrayUtil__reserve(&heap, this, next, sizeof(T));
        }
    }
    __forceinline T* expandBy(S_00ddfcd0_Allocator& heap, int n)
    {
        int old = size;
        reserve(heap, size + n);
        size += n;
        return data + old;
    }
    __forceinline void SetSizeAndGrow(S_00ddfcd0_Allocator& heap, int n)
    {
        reserve(heap, n);
        size = n;
    }
    __forceinline void AddBack(S_00ddfcd0_Allocator& heap, const T& v)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00c90940(&heap, this, sizeof(T));
        copyRange(data + size, 1, v);
        ++size;
    }
    __forceinline void clear()
    {
        size = 0;
    }
    __forceinline void release(S_00ddfcd0_Allocator& heap)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            ((HeapView*)&heap)->ReleaseBlock(data, (capacity & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
__forceinline void* operator new(unsigned int, void* p)
{
    return p;
}
template <class T> struct Array : ArrayBase<T>
{
    __forceinline Array()
    {}
    __forceinline ~Array()
    {
        release(hkMemoryRouter_getInstance()->heap());
    }
    __forceinline T* expandBy(int n)
    {
        return ArrayBase<T>::expandBy(hkMemoryRouter_getInstance()->heap(), n);
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        ArrayBase<T>::SetSizeAndGrow(hkMemoryRouter_getInstance()->heap(), n);
    }
    __forceinline void AddBack(const T& v)
    {
        ArrayBase<T>::AddBack(hkMemoryRouter_getInstance()->heap(), v);
    }
};
template <class T> struct LocalArray : Array<T>
{
    T* saved;
    __forceinline LocalArray(int n)
    {
        S_00ddfcd0_Router* r = hkMemoryRouter_getInstance();
        T* p = (T*)r->unk0;
        r->unk0 = (int)p + ((n * sizeof(T) + 127) & ~127);
        data = p;
        capacity = n | 0x80000000;
        saved = p;
    }
    __forceinline ~LocalArray()
    {
        T* p = saved;
        if (p == data)
            clear();
        hkMemoryRouter_getInstance()->unk0 = (int)p;
    }
};
struct Mesh
{
    struct Triangle
    {
        int a, b, c, material;
        __forceinline void set(int x, int y, int z, int m = -1)
        {
            a = x;
            b = y;
            c = z;
            material = m;
        }
    };
    Array<DisplayVectorCallLocal_00ddfd10> m_kVertices;
    Array<Triangle> m_uiTriangleCount;
    __forceinline void* operator new(unsigned int n)
    {
        return hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(n);
    }
};
struct FUN_00cce5e0 : Mesh
{
    FUN_00cce5e0();
};
struct Strided
{
    const float* data;
    int count, stride;
    __forceinline Strided(const ArrayBase<DisplayVectorCallLocal_00ddfd10>& a)
        : data((const float*)a.begin()), count(a.GetLogicalSize()), stride(sizeof(DisplayVectorCallLocal_00ddfd10))
    {}
};
struct MeshUtility
{
    static __forceinline void ConvertStridedToMesh(const Strided& s, Mesh& m);
};
void FUN_00d5a5e0(const Strided&, Mesh&);
__forceinline void MeshUtility::ConvertStridedToMesh(const Strided& s, Mesh& m)
{
    FUN_00d5a5e0(s, m);
}
struct RefObject
{
    virtual ~RefObject()
    {}
    unsigned short GetAllocationSize, refs;
    __forceinline void* operator new(unsigned int n)
    {
        RefObject* p = (RefObject*)hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(n);
        p->GetAllocationSize = (unsigned short)n;
        return p;
    }
};
struct Display : RefObject
{
    Mesh* geometry;
    __declspec(align(16)) Transform transform;
    int displayType;
    __forceinline Mesh* getGeometry()
    {
        return geometry;
    }
    __forceinline Transform& getTransform()
    {
        return transform;
    }
};
struct FUN_00e0af50 : Display
{
    SphereRec sphere;
    int sides, rings;
    FUN_00e0af50(const SphereRec&, int, int);
};
struct FUN_00d22dc0 : Display
{
    DisplayVectorCallLocal_00ddfd10 top, bottom;
    float radius;
    int sides, segments;
    FUN_00d22dc0(const DisplayVectorCallLocal_00ddfd10&, const DisplayVectorCallLocal_00ddfd10&, float, int, int);
};
struct FUN_00d58510 : Display
{
    DisplayVectorCallLocal_00ddfd10 top, bottom;
    float radius;
    int sides, segments;
    FUN_00d58510(const DisplayVectorCallLocal_00ddfd10&, const DisplayVectorCallLocal_00ddfd10&, float, int, int);
};
struct FUN_00de1f50 : Display
{
    DisplayVectorCallLocal_00ddfd10 half;
    FUN_00de1f50(const DisplayVectorCallLocal_00ddfd10&);
};
struct FUN_00de4f20 : Display
{
    DisplayVectorCallLocal_00ddfd10 normal, center, perp, extent;
    FUN_00de4f20(const DisplayVectorCallLocal_00ddfd10&, const DisplayVectorCallLocal_00ddfd10&, const DisplayVectorCallLocal_00ddfd10&, const DisplayVectorCallLocal_00ddfd10&);
};
struct FUN_00de1d20 : Display
{
    FUN_00de1d20(Mesh*);
};
struct BaseShape;
struct Container
{
    virtual void f0();
    virtual void f4();
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int) const;
    virtual void f10();
    virtual const BaseShape* GetShapeForKey(unsigned int, ShapeBuffer&) const;
    int unk04;
};
struct Bool
{
    char value;
    __forceinline operator bool() const
    {
        return value != 0;
    }
};
struct BaseShape
{
    virtual void f0();
    virtual void f4();
    virtual void f8();
    virtual void fc();
    virtual const Container* GetShapeContainer() const;
    virtual void f14();
    virtual void f18();
    virtual void getAabb(const Transform&, float, hkAabb&) const;
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual int getNumCollisionSpheres() const;
    virtual const SphereRec* getCollisionSpheres(SphereRec*) const;
    virtual float GetHeightAtGridPoint(int, int) const;
    virtual Bool IsTriangleWindingFlipped() const;
    int unk04, unk08, type;
    __forceinline int getType() const
    {
        return type;
    }
};
struct Convex : BaseShape
{
    float radius;
    __forceinline float getRadius() const
    {
        return radius;
    }
};
struct BallShape : Convex
{
};
struct MultiBallShape : BaseShape
{
    int count;
    DisplayVectorCallLocal_00ddfd10 points[8];
    __forceinline const DisplayVectorCallLocal_00ddfd10* getSpheres() const
    {
        return points;
    }
    __forceinline int getNumSpheres() const
    {
        return count;
    }
};
struct PlaneShape : BaseShape
{
    DisplayVectorCallLocal_00ddfd10 plane;
    __forceinline const DisplayVectorCallLocal_00ddfd10& getPlane() const
    {
        return plane;
    }
};
struct CapsuleShape : Convex
{
    DisplayVectorCallLocal_00ddfd10 endpoints[2];
    __forceinline const DisplayVectorCallLocal_00ddfd10& getVertex(int i) const
    {
        return endpoints[i];
    }
};
struct CylinderShape : Convex
{
    DisplayVectorCallLocal_00ddfd10 endpoints[2];
    __forceinline const DisplayVectorCallLocal_00ddfd10& getVertex(int i) const
    {
        return endpoints[i];
    }
    float FUN_00d571a0() const;
    __forceinline float GetCylinderRadius() const
    {
        return FUN_00d571a0();
    }
};
struct RayShape : BaseShape
{
    struct Ray
    {
        DisplayVectorCallLocal_00ddfd10 m_kRayStart, m_kRayEnd;
    };
    Array<Ray> rays;
    float penetration;
    __forceinline const Array<Ray>& getRays() const
    {
        return rays;
    }
};
struct CenteredPointBounds : Convex
{
    DisplayVectorCallLocal_00ddfd10 half;
    __forceinline const DisplayVectorCallLocal_00ddfd10& getHalfExtents() const
    {
        return half;
    }
};
struct TranslateShape : Convex
{
    int unk14;
    const BaseShape* child;
    int unk1c;
    DisplayVectorCallLocal_00ddfd10 translation;
    __forceinline const DisplayVectorCallLocal_00ddfd10& getTranslation() const
    {
        return translation;
    }
    __forceinline const BaseShape* GetShapeForKey() const
    {
        return child;
    }
};
struct ConvexTransformShape : Convex
{
    int unk14;
    const BaseShape* child;
    int unk1c;
    __declspec(align(16)) Transform transform;
    __forceinline const Transform& getTransform() const
    {
        return transform;
    }
    __forceinline const BaseShape* GetShapeForKey() const
    {
        return child;
    }
};
struct TransformShape : BaseShape
{
    int unk10;
    const BaseShape* child;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    __declspec(align(16)) Transform transform;
    __forceinline const Transform& getTransform() const
    {
        return transform;
    }
    __forceinline const BaseShape* GetShapeForKey() const
    {
        return child;
    }
};
struct BoundingShape : BaseShape
{
    const BaseShape* child;
    __forceinline const BaseShape* getBoundingVolumeShape() const
    {
        return child;
    }
};
struct ChildInfo
{
    const BaseShape* shape;
    int unk04, unk08, unk0c;
};
struct ListShape : BaseShape, Container
{
    Array<ChildInfo> entries;
    __forceinline const BaseShape* getChildShapeInl(int i) const
    {
        return entries[i].shape;
    }
};
struct TriangleShape : Convex
{
    DisplayVectorCallLocal_00ddfd10 vertices[3], extrusion;
    __forceinline const DisplayVectorCallLocal_00ddfd10& getVertex(int i) const
    {
        return vertices[i];
    }
    __forceinline const DisplayVectorCallLocal_00ddfd10& getExtrusion() const
    {
        return extrusion;
    }
};
struct ConvexVerticesShape : Convex
{
};
struct CollectionShape : BaseShape, Container
{
};
struct PieceShape : Convex
{
    DisplayVectorCallLocal_00ddfd10* vertices;
    int vertexCount;
    int unk1c;
    const CollectionShape* m_pDisplayMesh;
    const unsigned int* m_pIndexData;
    int m_iIndexCount;
};
struct HeightShape : BaseShape
{
    int m_iXResolution, m_iZResolution, unk18, unk1c;
    DisplayVectorCallLocal_00ddfd10 m_kHeightScaleVector;
    __forceinline float getHeightAt(int a, int b) const
    {
        return GetHeightAtGridPoint(a, b);
    }
    __forceinline Bool getTriangleFlip() const
    {
        return IsTriangleWindingFlipped();
    }
};
struct Node
{
    int unk00, unk04;
    struct Env
    {
        int m_iFirstValue, m_iSecondValue;
    } m_kEnvironment;
    Display* current;
    Display* hkpShapeDisplayBuilder_getCurrentRawGeometry(Array<Display*>&);
    __forceinline Display* GetCurrentDisplay(Array<Display*>& a)
    {
        return hkpShapeDisplayBuilder_getCurrentRawGeometry(a);
    }
    void hkpShapeDisplayBuilder_buildShapeDisplay(const BaseShape*, const Transform&, Array<Display*>&);
};
struct UserBuilders
{
    int unk00, unk04;
    struct Entry
    {
        void(__cdecl* f)(const BaseShape*, const Transform&, Array<Display*>&, Node*);
        int type;
    };
    Array<Entry> m_kBuilderEntries;
    static __forceinline UserBuilders& GetMonitorStream();
};
extern UserBuilders* DAT_01269ce0;
__forceinline UserBuilders& UserBuilders::GetMonitorStream()
{
    return *DAT_01269ce0;
}

// @fnv 0x00ddfd10
// src: XBOX_PDB 0x00ddfd10
void Node::hkpShapeDisplayBuilder_buildShapeDisplay(const BaseShape* shape, const Transform& mat, Array<Display*>& out)
{
    switch (shape->getType())
    {
    case 1: {
        const BallShape* s = static_cast<const BallShape*>(shape);
        DisplayVectorCallLocal_00ddfd10 zero;
        zero.setZero4();
        SphereRec sphere(zero, s->getRadius());
        FUN_00e0af50* g = new FUN_00e0af50(sphere, m_kEnvironment.m_iSecondValue, m_kEnvironment.m_iFirstValue);
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 21: {
        const MultiBallShape* s = static_cast<const MultiBallShape*>(shape);
        const DisplayVectorCallLocal_00ddfd10* points = s->getSpheres();
        for (int i = 0; i < s->getNumSpheres(); ++i)
        {
            SphereRec sphere(DisplayVectorCallLocal_00ddfd10::getZero(), points[i](3));
            FUN_00e0af50* g = new FUN_00e0af50(sphere, m_kEnvironment.m_iSecondValue, m_kEnvironment.m_iFirstValue);
            g->getTransform().setIdentity();
            g->getTransform().setTranslation(points[i]);
            out.AddBack(g);
        }
        break;
    }
    case 28: {
        const PlaneShape* s = static_cast<const PlaneShape*>(shape);
        const DisplayVectorCallLocal_00ddfd10& plane = s->getPlane();
        hkAabb bounds;
        s->getAabb(Transform::GetIdentityTransform(), 0.001f, bounds);
        DisplayVectorCallLocal_00ddfd10 ext;
        ext.setSub4(*reinterpret_cast<const DisplayVectorCallLocal_00ddfd10*>(&bounds.m_kMaximumCorner.x), *reinterpret_cast<const DisplayVectorCallLocal_00ddfd10*>(&bounds.m_kMinimumCorner.x));
        DisplayVectorCallLocal_00ddfd10 axis;
        axis.setZero4();
        axis(ext.getMajorAxis()) = 1;
        ext.mul4(0.5f);
        DisplayVectorCallLocal_00ddfd10 center(ext);
        center.add4(*reinterpret_cast<const DisplayVectorCallLocal_00ddfd10*>(&bounds.m_kMinimumCorner.x));
        FUN_00de4f20* g = new FUN_00de4f20(plane, axis, center, ext);
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 5: {
        const CapsuleShape* s = static_cast<const CapsuleShape*>(shape);
        FUN_00d22dc0* g = new FUN_00d22dc0(s->getVertex(1), s->getVertex(0), s->getRadius(), 6, 1);
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 2: {
        const CylinderShape* s = static_cast<const CylinderShape*>(shape);
        DisplayVectorCallLocal_00ddfd10 a;
        a.SetTransformedPoint(mat, s->getVertex(1));
        DisplayVectorCallLocal_00ddfd10 b;
        b.SetTransformedPoint(mat, s->getVertex(0));
        FUN_00d58510* g = new FUN_00d58510(a, b, s->FUN_00d571a0(), 9, 1);
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 24: {
        const RayShape* s = static_cast<const RayShape*>(shape);
        Display* display = GetCurrentDisplay(out);
        Mesh* mesh = display->getGeometry();
        int base = 0;
        for (int i = 0; i < s->getRays().GetLogicalSize(); ++i)
        {
            RayShape::Ray ray = s->getRays()[i];
            DisplayVectorCallLocal_00ddfd10* a = mesh->m_kVertices.expandBy(1);
            *a = ray.m_kRayStart;
            a->SetTransformedPoint(mat, *a);
            DisplayVectorCallLocal_00ddfd10* b = mesh->m_kVertices.expandBy(1);
            *b = ray.m_kRayStart;
            DisplayVectorCallLocal_00ddfd10 offset;
            offset.set(0.01f, 0, 0, 0);
            b->add4(offset);
            DisplayVectorCallLocal_00ddfd10* c = mesh->m_kVertices.expandBy(1);
            *c = ray.m_kRayEnd;
            c->SetTransformedPoint(mat, *c);
            Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(1);
            t->set(base, base + 1, base + 2);
            base += 3;
        }
        break;
    }
    case 4: {
        const CenteredPointBounds* s = static_cast<const CenteredPointBounds*>(shape);
        FUN_00de1f50* g = new FUN_00de1f50(s->getHalfExtents());
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 11: {
        const TranslateShape* s = static_cast<const TranslateShape*>(shape);
        __declspec(align(16)) Transform local;
        local.setIdentity();
        local.setTranslation(s->getTranslation());
        __declspec(align(16)) Transform result;
        result.SetProduct(mat, local);
        hkpShapeDisplayBuilder_buildShapeDisplay(s->GetShapeForKey(), result, out);
        break;
    }
    case 12: {
        const ConvexTransformShape* s = static_cast<const ConvexTransformShape*>(shape);
        __declspec(align(16)) Transform result;
        result.SetProduct(mat, s->getTransform());
        hkpShapeDisplayBuilder_buildShapeDisplay(s->GetShapeForKey(), result, out);
        break;
    }
    case 15: {
        const TransformShape* s = static_cast<const TransformShape*>(shape);
        __declspec(align(16)) Transform result;
        result.SetProduct(mat, s->getTransform());
        hkpShapeDisplayBuilder_buildShapeDisplay(s->GetShapeForKey(), result, out);
        break;
    }
    case 27:
        hkpShapeDisplayBuilder_buildShapeDisplay(static_cast<const BoundingShape*>(shape)->getBoundingVolumeShape(), mat, out);
        break;
    case 8:
    case 10: {
        const Container* c = shape->GetShapeContainer();
        ShapeBuffer buffer;
        for (unsigned int key = c->GetFirstKey(); key != 0xffffffff; key = c->GetNextShapeKey(key))
        {
            const BaseShape* child = c->GetShapeForKey(key, buffer);
            hkpShapeDisplayBuilder_buildShapeDisplay(child, mat, out);
        }
        break;
    }
    case 9: {
        const ListShape* s = static_cast<const ListShape*>(shape);
        for (unsigned int key = s->GetFirstKey(); key != 0xffffffff; key = s->GetNextShapeKey(key))
        {
            const BaseShape* child = s->getChildShapeInl(key);
            hkpShapeDisplayBuilder_buildShapeDisplay(child, mat, out);
        }
        break;
    }
    case 7:
    case 14:
    case 16:
    case 22:
    case 23: {
        const Container* c = shape->GetShapeContainer();
        ShapeBuffer buffer;
        for (unsigned int key = c->GetFirstKey(); key != 0xffffffff; key = c->GetNextShapeKey(key))
        {
            const BaseShape* child = c->GetShapeForKey(key, buffer);
            hkpShapeDisplayBuilder_buildShapeDisplay(child, mat, out);
        }
        break;
    }
    case 3: {
        const TriangleShape* s = static_cast<const TriangleShape*>(shape);
        Mesh* mesh = GetCurrentDisplay(out)->getGeometry();
        int base = mesh->m_kVertices.GetLogicalSize();
        DisplayVectorCallLocal_00ddfd10* v = mesh->m_kVertices.expandBy(3);
        v[0].SetTransformedPoint(mat, s->getVertex(0));
        v[1].SetTransformedPoint(mat, s->getVertex(1));
        v[2].SetTransformedPoint(mat, s->getVertex(2));
        Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(1);
        t->set(base, base + 1, base + 2);
        if (s->getExtrusion().length3() > 0)
        {
            DisplayVectorCallLocal_00ddfd10 a;
            a.setAdd4(s->getVertex(0), s->getExtrusion());
            DisplayVectorCallLocal_00ddfd10 b;
            b.setAdd4(s->getVertex(1), s->getExtrusion());
            DisplayVectorCallLocal_00ddfd10 c;
            c.setAdd4(s->getVertex(2), s->getExtrusion());
            DisplayVectorCallLocal_00ddfd10* e = mesh->m_kVertices.expandBy(3);
            e[0].SetTransformedPoint(mat, a);
            e[1].SetTransformedPoint(mat, b);
            e[2].SetTransformedPoint(mat, c);
            Mesh::Triangle* et = mesh->m_uiTriangleCount.expandBy(7);
            et[0].set(base + 3, base + 1, base);
            et[1].set(base + 3, base + 4, base + 1);
            et[2].set(base + 4, base + 5, base + 1);
            et[3].set(base + 5, base + 2, base + 1);
            et[4].set(base + 5, base, base + 2);
            et[5].set(base + 5, base + 3, base);
            et[6].set(base + 5, base + 4, base + 3);
        }
        break;
    }
    case 6: {
        const ConvexVerticesShape* s = static_cast<const ConvexVerticesShape*>(shape);
        int count = s->getNumCollisionSpheres();
        LocalArray<SphereRec> points(count);
        points.SetSizeAndGrow(count);
        const SphereRec* p = s->getCollisionSpheres(points.begin());
        Array<DisplayVectorCallLocal_00ddfd10> transformed;
        transformed.SetSizeAndGrow(count);
        for (int i = 0; i < count; ++i)
            transformed.data[i].SetTransformedPoint(mat, p[i].getPosition());
        Mesh* mesh = new Mesh;
        MeshUtility::ConvertStridedToMesh(transformed, *mesh);
        FUN_00de1d20* g = new FUN_00de1d20(mesh);
        out.AddBack(g);
        break;
    }
    case 20: {
        const PieceShape* s = static_cast<const PieceShape*>(shape);
        Mesh* mesh = new FUN_00cce5e0;
        ShapeBuffer buffer;
        for (int i = 0; i < s->m_iIndexCount; ++i)
        {
            const TriangleShape* child =
                static_cast<const TriangleShape*>(s->m_pDisplayMesh->GetShapeForKey(s->m_pIndexData[i], buffer));
            Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(1);
            int base = mesh->m_kVertices.GetLogicalSize();
            t->set(base, base + 1, base + 2);
            for (int j = 0; j < 3; ++j)
            {
                DisplayVectorCallLocal_00ddfd10* v = mesh->m_kVertices.expandBy(1);
                v->SetTransformedPoint(mat, child->getVertex(j));
            }
        }
        FUN_00de1d20* g = new FUN_00de1d20(mesh);
        out.AddBack(g);
        break;
    }
    case 13: {
        const HeightShape* s = static_cast<const HeightShape*>(shape);
        Mesh* mesh = GetCurrentDisplay(out)->getGeometry();
        DisplayVectorCallLocal_00ddfd10 scale = s->m_kHeightScaleVector;
        for (int i = 0; i < s->m_iXResolution - 1; ++i)
            for (int j = 0; j < s->m_iZResolution - 1; ++j)
            {
                DisplayVectorCallLocal_00ddfd10 a;
                a.set((float)(float)i + 0.0, s->getHeightAt(i, j), (float)(float)j + 0.0);
                a.mul4(scale);
                DisplayVectorCallLocal_00ddfd10 b;
                b.set((float)(float)i + 0.0, s->getHeightAt(i, j + 1), (float)(float)j + 1.0);
                b.mul4(scale);
                DisplayVectorCallLocal_00ddfd10 c;
                c.set((float)(float)i + 1.0, s->getHeightAt(i + 1, j), (float)(float)j + 0.0);
                c.mul4(scale);
                DisplayVectorCallLocal_00ddfd10 d;
                d.set((float)(float)i + 1.0, s->getHeightAt(i + 1, j + 1), (float)(float)j + 1.0);
                d.mul4(scale);
                int base = mesh->m_kVertices.GetLogicalSize();
                DisplayVectorCallLocal_00ddfd10* v = mesh->m_kVertices.expandBy(4);
                v[0].SetTransformedPoint(mat, a);
                v[1].SetTransformedPoint(mat, b);
                v[2].SetTransformedPoint(mat, c);
                v[3].SetTransformedPoint(mat, d);
                if (s->getTriangleFlip())
                {
                    Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(2);
                    t[0].set(base, base + 1, base + 3);
                    t[1].set(base, base + 3, base + 2);
                }
                else
                {
                    Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(2);
                    t[0].set(base, base + 1, base + 2);
                    t[1].set(base + 3, base + 2, base + 1);
                }
            }
        break;
    }
    default:
        for (int i = 0; i < UserBuilders::GetMonitorStream().m_kBuilderEntries.GetLogicalSize(); ++i)
            if (UserBuilders::GetMonitorStream().m_kBuilderEntries[i].type == shape->getType())
                UserBuilders::GetMonitorStream().m_kBuilderEntries[i].f(shape, mat, out, this);
        break;
    }
}
