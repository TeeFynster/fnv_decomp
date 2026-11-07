#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkaBone.h"
#include "../../../../../include/hkaSkeleton.h"
#include "../../../../../include/hkaSkeletonMapperData.h"
#include "../../../../../include/hkError.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkReferencedObject.h"

// Keep the original inline behavior while using the shared class declarations.
inline const char* hkStringPtr::cString() const
{
    return reinterpret_cast<char*>((unsigned long)(m_pcText) & ~1);
}

// src/havok/animation/animation/mapper/hkaskeletonmapperutils_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/animation/mapper/hkaskeletonmapperutils_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/animation/animation/mapper/hkaskeletonmapperutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapperutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct CE5F90QsTransform
{
    float m_vTranslation[4];
    float m_rotation[4];
    float m_vScale[4];
};
void __cdecl hkaSkeletonMapperUtils_computeMappingTransform(CE5F90QsTransform* out, const CE5F90QsTransform* a, const CE5F90QsTransform* b, int mode,
                          float weightA, float weightB);
void __cdecl hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(CE5F90QsTransform* out, const CE5F90QsTransform* poseA, short boneA,
                          const CE5F90QsTransform* poseB, short boneB, int mode, float weightA, float weightB);
extern "C" void _ReadBarrier();
#include <xmmintrin.h>

extern const LocalM128 DAT_010c71e0;
extern const LocalM128 DAT_010c71b0;
extern const LocalM128 DAT_010c7170;
extern const LocalM128 DAT_010c44d0;
extern const LocalM128 DAT_010c4c00;
extern const LocalM128 DAT_010c4c10;

__forceinline LocalM128 hkQuadRecip(LocalM128 r)
{
    LocalM128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}

class HkSimd
{
  public:
    HkSimd(const LocalM128& x) : m_vValue(x)
    {}
    HkSimd(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    HkSimd()
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const LocalM128& getQuad() const
    {
        return m_vValue;
    }

  private:
    LocalM128 m_vValue;
};

struct HkQuat;

class HkVec4
{
  public:
    __forceinline void operator=(const HkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const LocalM128& v)
    {
        m_vComponents = v;
    }
    __forceinline LocalM128& getQuad()
    {
        return m_vComponents;
    }
    __forceinline const LocalM128& getQuad() const
    {
        return m_vComponents;
    }

    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void SetAllComponents(float a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    __forceinline void SetAllComponents(const HkSimd& a)
    {
        m_vComponents = _mm_shuffle_ps(a.getQuad(), a.getQuad(), 0);
    }
    __forceinline void setAdd4(const HkVec4& v0, const HkVec4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setSub4(const HkVec4& v0, const HkVec4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void sub4(const HkVec4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setMul4(const HkVec4& a, const HkVec4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const HkSimd& r, const HkVec4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    __forceinline void addMul4(const HkVec4& x, const HkVec4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setAddMul4(const HkVec4& a, const HkVec4& x, const HkVec4& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setCross(const HkVec4& v0, const HkVec4& v1)
    {
        LocalM128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        LocalM128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setNeg4(const HkVec4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setNeg3(const HkVec4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00);
    }
    __forceinline void setXYZ0(const HkVec4& xyz)
    {
        m_vComponents = _mm_and_ps(xyz, DAT_010c4c10);
    }
    __forceinline void setXYZW(const HkVec4& xyz, const HkVec4& w)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    __forceinline void setReciprocal4(const HkVec4& vec)
    {
        m_vComponents = hkQuadRecip(vec.m_vComponents);
    }
    __forceinline void setReciprocal3(const HkVec4& v)
    {
        HkVec4 v1111;
        v1111.getQuad() = DAT_010c7170;
        HkVec4 tmp;
        tmp.setXYZW(v, v1111);
        setReciprocal4(tmp);
    }
    __forceinline void setBroadcast(const HkVec4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        }
    }
    __forceinline void broadcast(int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline HkSimd getSimdAt(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline HkSimd dot3(const HkVec4& a) const
    {
        LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline HkSimd lengthSquared3() const
    {
        return this->dot3(*this);
    }
    __forceinline void SetRotatedDirection(const HkQuat& quat, const HkVec4& direction);
    __forceinline void setRotatedInverseDir(const HkQuat& quat, const HkVec4& direction);

  private:
    LocalM128 m_vComponents;

  public:
    operator LocalM128() const
    {
        return m_vComponents;
    }
};

struct HkQuat
{
    inline HkQuat()
    {}
    inline void operator=(const HkQuat& q)
    {
        m_vec = q.m_vec;
    }
    __forceinline const HkVec4& getImag() const
    {
        return m_vec;
    }
    inline void setIdentity()
    {
        m_vec.getQuad() = DAT_010c71b0;
    }
    inline void SetConjugate(const HkQuat& q)
    {
        m_vec.setNeg3(q.getImag());
    }
// src: COMMUNITY 0x00c66320
    inline void setMul(const HkQuat& q0, const HkQuat& q1)
    {
        HkVec4 vec;
        vec.setCross(q0.getImag(), q1.getImag());
        vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
        vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
        HkVec4 dot;
        dot.SetAllComponents(q0.m_vec.dot3(q1.m_vec));
        HkVec4 w;
        w.setMul4(q0.m_vec, q1.m_vec);
        w.sub4(dot);
        m_vec.setXYZW(vec, w);
    }
    HkVec4 m_vec;
};

__forceinline void HkVec4::SetRotatedDirection(const HkQuat& quat, const HkVec4& direction)
{
    HkVec4 minusHalf;
    minusHalf.getQuad() = DAT_010c71e0;
    HkVec4 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    HkVec4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);
    HkVec4 ret;
    ret.setMul4(direction, q2minus1);
    HkVec4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());
    HkVec4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

__forceinline void HkVec4::setRotatedInverseDir(const HkQuat& quat, const HkVec4& direction)
{
    HkVec4 minusHalf;
    minusHalf.getQuad() = DAT_010c71e0;
    HkVec4 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    HkVec4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);
    HkVec4 ret;
    ret.setMul4(direction, q2minus1);
    HkVec4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());
    HkVec4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

// local form of hkQsTransform: 0x00ce61c0 needs inline QsTransform operations; shared form gives 10941 bytes vs exe 13246.
struct HkQs
{
    __forceinline HkQs()
    {}
    __forceinline HkQs(const HkQs& t)
    {
        m_vTranslation = t.m_vTranslation;
        m_rotation = t.m_rotation;
        m_vScale = t.m_vScale;
    }
    __forceinline void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.setIdentity();
        m_vScale.SetAllComponents(1.0f);
    }
    __forceinline const HkVec4& getTranslation() const
    {
        return m_vTranslation;
    }
    __forceinline void SetConjugate(const HkQs& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        HkVec4 invScale;
        invScale.setReciprocal3(t.m_vScale);
        m_vScale.setXYZ0(invScale);
    }
    __forceinline void SetProduct(const HkQs& aTb, const HkQs& bTc)
    {
        HkVec4 extraTrans;
        extraTrans.SetRotatedDirection(aTb.m_rotation, bTc.m_vTranslation);
        m_vTranslation.setAdd4(aTb.m_vTranslation, extraTrans);
        m_rotation.setMul(aTb.m_rotation, bTc.m_rotation);
        m_vScale.setMul4(aTb.m_vScale, bTc.m_vScale);
    }
    __forceinline void SetMulInverse(const HkQs& a, const HkQs& b)
    {
        HkQs h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
    HkVec4 m_vTranslation;
    HkQuat m_rotation;
    HkVec4 m_vScale;
};

template <typename E, typename S> class HkEnumValue
{
  public:
    operator E() const
    {
        return static_cast<E>(m_kStorage);
    }
    void operator=(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
    hkBool operator==(E e) const
    {
        return m_kStorage == static_cast<S>(e);
    }
    S m_kStorage;
};

__forceinline long __cdecl hkByteOffset(const void* base, const void* pntr)
{
    return long(pntr) - long(base);
}

template <typename TYPE> __forceinline TYPE* __cdecl hkAddOffset(TYPE* base, long offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

template <typename TYPE> class HkPad
{
  public:
    __forceinline HkPad()
    {}
    __forceinline HkPad(TYPE e) : m_kStorage(e)
    {}
    __forceinline void operator=(TYPE e)
    {
        m_kStorage = e;
    }
    __forceinline TYPE val() const
    {
        return m_kStorage;
    }
    __forceinline TYPE operator->() const
    {
        return m_kStorage;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE m_kStorage;
};

template <typename T> struct HkSizeOf
{
    enum
    {
        val = sizeof(T)
    };
};

struct HkHeap
{
    __declspec(nothrow) virtual void slot00() throw();
    __declspec(nothrow) virtual void slot04() throw();
    __declspec(nothrow) virtual void slot08() throw();
    __declspec(nothrow) virtual void slot0c() throw();
    __declspec(nothrow) virtual void ReturnMemory(void* p, int numBytes) throw();
    template <typename TYPE> inline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = HkSizeOf<TYPE>::val;
        ReturnMemory(p, numElem * sizeof(TYPE));
    }
};

class HkStack
{
  public:
    __forceinline void* allocateStack(int numBytes, const char* what);
    __forceinline void deallocateStack(void* p);
    __forceinline int getFreeStackSize()
    {
        return int(hkByteOffset(m_next, m_kRayEnd));
    }

  protected:
    HkPad<void*> m_next;
    HkPad<void*> m_kRayStart;
    HkPad<void*> m_kRayEnd;
};

__forceinline void* HkStack::allocateStack(int numBytes, const char* what)
{
    if (numBytes > getFreeStackSize())
    {
    }
    void* current = m_next;
    m_next = hkAddOffset(current, numBytes);
    return current;
}

void HkStack::deallocateStack(void* p)
{
    m_next = p;
}

class HkRouter
{
  public:
    __declspec(nothrow) static HkRouter& __cdecl hkMemoryRouter_getInstance() throw();
    inline HkStack& stack()
    {
        return m_aiEntries;
    }
    inline HkHeap& temp()
    {
        return *m_pTemp;
    }
    inline HkHeap& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    HkStack m_aiEntries;
    HkHeap* m_pTemp;
    HkHeap* m_pStreamAllocator;
};

template <typename TYPE> __forceinline TYPE* __cdecl hkAllocStack(int n, const char* what = 0)
{
    HkRouter& mem = HkRouter::hkMemoryRouter_getInstance();
    return static_cast<TYPE*>(
        mem.stack().allocateStack((((n * HkSizeOf<TYPE>::val) + ((128) - 1)) & (~((128) - 1))), what));
}

template <typename TYPE> __forceinline void __cdecl hkFreeStack(TYPE* ptr)
{
    HkRouter::hkMemoryRouter_getInstance().stack().deallocateStack(static_cast<void*>(ptr));
}

struct HkHeapAllocator
{
    HkHeap& get(const void*)
    {
        return HkRouter::hkMemoryRouter_getInstance().heap();
    }
};

template <typename T> struct HkArrayElement
{
    T value;
    __forceinline HkArrayElement()
    {}
    __forceinline HkArrayElement(const T& v) : value(v)
    {}
    static __forceinline void* operator new(size_t, void* p)
    {
        return p;
    }
    static __forceinline void operator delete(void*, void*)
    {}
};

template <bool N> struct HkTraitBool
{
    typedef HkTraitBool<N> type;
    enum
    {
        result = N
    };
};
typedef HkTraitBool<true> HkPodTag;
typedef HkTraitBool<false> HkClassTag;
template <typename T> struct HkPodTrait : public HkTraitBool<false>
{
};
template <> struct HkPodTrait<short> : public HkPodTag
{
};
template <> struct HkPodTrait<HkQs> : public HkPodTag
{
};

class HkArrUtil
{
  public:
    template <typename T> static __forceinline void construct(T* t, int n, HkPodTag);
    template <typename T> static __forceinline void construct(T* t, int n, HkClassTag);
    template <typename T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, HkPodTag);
    template <typename T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, HkClassTag);
    template <typename T> static __forceinline void destruct(T* t, int n, HkPodTag);
    template <typename T> static __forceinline void destruct(T* t, int n, HkClassTag);
    template <typename T> static __forceinline void constructWithArray(T* t, int n, const T* tcopy, HkPodTag);
    template <typename T> static __forceinline void constructWithArray(T* t, int n, const T* tcopy, HkClassTag);
    __declspec(nothrow) static void __cdecl hkArrayUtil__reserve(HkHeap& a, void* array, int reqElem, int sizeElem) throw();
    __declspec(nothrow) static void __cdecl FUN_00c90940(HkHeap& a, void* array, int sizeElem) throw();
};

template <typename T> __forceinline void HkArrUtil::construct(T* t, int n, HkPodTag)
{}

template <typename T> __forceinline void HkArrUtil::construct(T* t, int n, HkClassTag)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) HkArrayElement<T>;
    }
}

template <typename T> __forceinline void HkArrUtil::constructWithCopy(T* t, int n, const T& tcopy, HkPodTag)
{
    for (int i = 0; i < n; ++i)
    {
        t[i] = tcopy;
    }
}

template <typename T> __forceinline void HkArrUtil::constructWithCopy(T* t, int n, const T& tcopy, HkClassTag)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) HkArrayElement<T>(tcopy);
    }
}

template <typename T> __forceinline void HkArrUtil::destruct(T* t, int n, HkPodTag)
{}

template <typename T> __forceinline void HkArrUtil::destruct(T* t, int n, HkClassTag)
{
    for (int i = 0; i < n; ++i)
    {
        static_cast<T*>(t)[i].~T();
    }
}

template <typename T> __forceinline void HkArrUtil::constructWithArray(T* t, int n, const T* tcopy, HkPodTag)
{
    for (int i = 0; i < n; ++i)
    {
        t[i] = tcopy[i];
    }
}

template <typename T> __forceinline void HkArrUtil::constructWithArray(T* t, int n, const T* tcopy, HkClassTag)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) HkArrayElement<T>(tcopy[i]);
    }
}

template <typename T> class HkArrBaseLocalForm
{ // local form of hkArrayBase: 0x00ce61c0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
  public:
    __forceinline HkArrBaseLocalForm();
    __forceinline ~HkArrBaseLocalForm()
    {}
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline void clear()
    {
        HkArrUtil::destruct(m_data, m_iElementCount, typename HkPodTrait<T>::type());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(HkHeap& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void _pushBack(HkHeap& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            HkArrUtil::FUN_00c90940(alloc, this, sizeof(T));
        }
        HkArrUtil::constructWithCopy(m_data + m_iElementCount, 1, t, typename HkPodTrait<T>::type());
        m_iElementCount++;
    }
    __forceinline void GrowArrayCapacity(HkHeap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            HkArrUtil::hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(HkHeap& alloc, int n, const T& fill)
    {
        GrowArrayCapacity(alloc, n);
        HkArrUtil::destruct(m_data + n, m_iElementCount - n, typename HkPodTrait<T>::type());
        HkArrUtil::constructWithCopy(m_data + m_iElementCount, n - m_iElementCount, fill, typename HkPodTrait<T>::type());
        m_iElementCount = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        HkArrUtil::destruct(m_data + n, m_iElementCount - n, typename HkPodTrait<T>::type());
        HkArrUtil::construct(m_data + m_iElementCount, n - m_iElementCount, typename HkPodTrait<T>::type());
        m_iElementCount = n;
    }
    __forceinline T& _expandOne(HkHeap& alloc)
    {
        if (m_iElementCount == getCapacity())
        {
            HkArrUtil::FUN_00c90940(alloc, this, sizeof(T));
        }
        HkArrUtil::construct(m_data + m_iElementCount, 1, typename HkPodTrait<T>::type());
        return m_data[m_iElementCount++];
    }
    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }
    __forceinline const T& back() const
    {
        return m_data[m_iElementCount - 1];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline const T* begin() const
    {
        return m_data;
    }
    static __forceinline void __cdecl copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            dst[i] = src[i];
        }
    }

  protected:
    __forceinline HkArrBaseLocalForm<T>& copyFromArray(HkHeap& alloc, const HkArrBaseLocalForm<T>& a, HkClassTag)
    {
        int oldSize = m_iElementCount;
        int newSize = a.GetLogicalSize();
        int copiedSize = newSize > oldSize ? oldSize : newSize;
        GrowArrayCapacity(alloc, newSize);
        HkArrUtil::destruct(m_data + newSize, oldSize - newSize, HkClassTag());
        copy(m_data, a.m_data, copiedSize);
        HkArrUtil::constructWithArray(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize, HkClassTag());
        m_iElementCount = newSize;
        return *this;
    }

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
        FORCE_SIGNED = -1
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T>
__forceinline HkArrBaseLocalForm<T>::HkArrBaseLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
{}

template <typename T> class HkArr : public HkArrBaseLocalForm<T>
{
  public:
    __forceinline HkArr() : HkArrBaseLocalForm<T>()
    {}
    __forceinline ~HkArr();
    __forceinline HkArr& operator=(const HkArrBaseLocalForm<T>& a);
    __forceinline HkArr& operator=(const HkArr& a);
    __forceinline void ClearAndRelease()
    {
        HkArrBaseLocalForm<T>::_clearAndDeallocate(HkHeapAllocator().get(this));
    }
    __forceinline void AddBack(const T& e)
    {
        HkArrBaseLocalForm<T>::_pushBack(HkHeapAllocator().get(this), e);
    }
    __forceinline void SetSizeAndGrow(int size, const T& fill)
    {
        HkArrBaseLocalForm<T>::_setSize(HkHeapAllocator().get(this), size, fill);
    }
    __forceinline T& AllocatePair()
    {
        return HkArrBaseLocalForm<T>::_expandOne(HkHeapAllocator().get(this));
    }
};

template <typename T> __forceinline HkArr<T>::~HkArr()
{
    ClearAndRelease();
}

template <typename T> __forceinline HkArr<T>& HkArr<T>::operator=(const HkArrBaseLocalForm<T>& a)
{
    this->copyFromArray(HkHeapAllocator().get(this), a, typename HkPodTrait<T>::type());
    return *this;
}

template <typename T> __forceinline HkArr<T>& HkArr<T>::operator=(const HkArr<T>& a)
{
    this->copyFromArray(HkHeapAllocator().get(this), a, typename HkPodTrait<T>::type());
    return *this;
}

template <typename T> class HkLocalArr : public HkArr<T>
{
  public:
    __forceinline HkLocalArr(int capacity)
    {
        this->m_data = hkAllocStack<T>(capacity);
        this->m_iCapacityState = capacity | HkArr<T>::DONT_DEALLOCATE_FLAG;
        m_pStackAllocation = this->m_data;
    }
    __forceinline hkBool wasReallocated() const
    {
        return m_pStackAllocation != this->m_data;
    }
    __forceinline ~HkLocalArr()
    {
        if (!wasReallocated())
        {
            HkArr<T>::clear();
        }
        hkFreeStack<T>(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

template <class TYPE> class HkRef
{
  public:
    __forceinline void operator=(TYPE* e)
    {
        if (e)
        {
            e->addReference();
        }
        if (m_pRetainedObject)
        {
            m_pRetainedObject->removeReference();
        }
        m_pRetainedObject = e;
    }
    TYPE* m_pRetainedObject;
};

class HkLocalFrame;

// The shared hkaSkeleton does not yet declare m_kReferencePose.
class HkSkeleton : public hkReferencedObject
{
  public:
    struct LocalFrameOnBone
    {
        HkRef<HkLocalFrame> m_pLocalFrame;
        int m_iBoneIndex;
    };
    __forceinline HkSkeleton()
    {}
    hkStringPtr m_name;
    HkArr<short> m_kParentIndices;
    HkArr<hkaBone> m_kBones;
    HkArr<HkQs> m_kReferencePose;
    HkArr<hkStringPtr> m_kBoneNames;
    HkArr<LocalFrameOnBone> m_kLocalFrames;
};

__forceinline hkError& hkErrorInstance()
{
    return *hkError::s_instance;
}

// Using shared hkOstream here changes FUN_00ce61c0 from 13246 to 13278 bytes.
// Retain this stream interface until the shared declaration preserves that code.
class FUN_00cc00e0 : public hkReferencedObject
{
  public:
    __declspec(nothrow) ~FUN_00cc00e0() throw();
    __declspec(nothrow) FUN_00cc00e0& ProcessAndReturnValue_00cc01c0(const char* s) throw();
    __declspec(nothrow) FUN_00cc00e0& WriteName(const hkStringPtr& s) throw();

  protected:
    void* m_pStreamWriter;
};

class FUN_00cb1600 : public FUN_00cc00e0
{
  public:
    __declspec(nothrow) FUN_00cb1600(void* buf, int bufSize) throw();
};

typedef int(__cdecl* HkCompareFunc)(const char*, const char*);

struct HkUserChain
{
    const char* m_kRayStart;
    const char* m_kRayEnd;
};

struct HkUserMapping
{
    ~HkUserMapping() throw()
    {}
    const char* m_pBoneNameA;
    const char* m_pBoneNameB;
};

enum HkMappingType
{
    HK_RAGDOLL_MAPPING = 0,
    HK_RETARGETING_MAPPING = 1
};

struct HkSimpleMapping
{
    HkSimpleMapping()
    {
        m_sBoneA = 0;
        m_sBoneB = 0;
        m_kAFromBTransform.setIdentity();
    }
    short m_sBoneA;
    short m_sBoneB;
    HkQs m_kAFromBTransform;
};

struct HkChainMapping
{
    HkChainMapping()
    {
        m_sStartBoneA = 0;
        m_sEndBoneA = 0;
        m_sStartBoneB = 0;
        m_sEndBoneB = 0;
        m_kStartAFromBTransform.setIdentity();
        m_kEndAFromBTransform.setIdentity();
    }
    short m_sStartBoneA;
    short m_sEndBoneA;
    short m_sStartBoneB;
    short m_sEndBoneB;
    HkQs m_kStartAFromBTransform;
    HkQs m_kEndAFromBTransform;
};

struct HkMotionParams
{
    __declspec(nothrow) void __cdecl hkQsTransform_ComputePoseScaleFactors(HkMappingType type, const HkQs* poseAMS, int numBonesA,
                                                  const HkQs* poseBMS, int numBonesB, HkQs& aMotionOut,
                                                  HkQs& bMotionOut) throw();
    int m_iValueAfterFlags;
    int m_iFirstMotionBoneIndex;
    int m_iSecondMotionBoneIndex;
    float m_fFirstMotionParameter;
    float m_fSecondMotionParameter;
};

struct HkMapperParams
{
    __declspec(noinline) HkMapperParams(const HkMapperParams& other) throw()
        : m_pSkeletonA(other.m_pSkeletonA), m_pSkeletonB(other.m_pSkeletonB), m_kBoneNameCompareFunction(other.m_kBoneNameCompareFunction),
          m_fFirstMappingTolerance(other.m_fFirstMappingTolerance),
          m_fSecondMappingTolerance(other.m_fSecondMappingTolerance), m_bFirstMappingOption(other.m_bFirstMappingOption),
          m_bSecondMappingOption(other.m_bSecondMappingOption), m_eMappingType(other.m_eMappingType),
          m_kMotionParams(other.m_kMotionParams)
    {
        m_kUserChainList = other.m_kUserChainList;
        m_kFirstUserMappingList = other.m_kFirstUserMappingList;
        m_kSecondUserMappingList = other.m_kSecondUserMappingList;
    }
    __declspec(noinline) ~HkMapperParams() throw()
    {}
    const HkSkeleton* m_pSkeletonA;
    const HkSkeleton* m_pSkeletonB;
    HkCompareFunc m_kBoneNameCompareFunction;
    float m_fFirstMappingTolerance;
    float m_fSecondMappingTolerance;
    HkArr<HkUserChain> m_kUserChainList;
    HkArr<HkUserMapping> m_kFirstUserMappingList;
    HkArr<HkUserMapping> m_kSecondUserMappingList;
    hkBool m_bFirstMappingOption;
    hkBool m_bSecondMappingOption;
    HkEnumValue<HkMappingType, int> m_eMappingType;
    HkMotionParams m_kMotionParams;
};

struct Match
{
    int m_sBoneA;
    int m_sBoneB;
};

__declspec(nothrow) short __cdecl FUN_00cdd390(const HkSkeleton& skeleton, const char* name,
                                               HkCompareFunc compare) throw();
__declspec(nothrow) hkBool
    __cdecl FUN_00cde3d0(const HkSkeleton& skeleton, short startBone, short endBone, HkArr<short>& bonesOut) throw();
__declspec(nothrow) void __cdecl FUN_00cddcf0(int numTransforms, const short* parentIndices, const HkQs* poseLocal,
                                              HkQs* poseModelOut) throw();
__declspec(nothrow) int __cdecl FUN_00cb0fe0(const char* s1, const char* s2) throw();
__declspec(nothrow) void __cdecl hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(HkMappingType type, const HkQs* poseA, short boneA, const HkQs* poseB,
                                              short boneB, HkQs& mapOut, float tolerance = 1.0e-5f,
                                              float defaultScale = 1.0f) throw();
__declspec(nothrow) void __cdecl Object_BuildBonePairMapping(HkMappingType type, const HkSkeleton* skeletonA, const HkQs* poseA,
                                              short startA, short endA, const HkSkeleton* skeletonB, const HkQs* poseB,
                                              short startB, short endB, HkChainMapping& mapAFromBOut) throw();

__forceinline bool __cdecl checkRotation(const HkMapperParams& params, short boneA, short boneB,
                                         const HkQs& aToBTransform, const HkQs& bToATransform)
{
    return true;
}

// @fnv 0x00ce61c0
// src: COMMUNITY 0x00ce61c0
__declspec(nothrow) void __cdecl hkaSkeletonMapperUtils_createMapping(const HkMapperParams& originalParams, hkaSkeletonMapperData& originalAToB,
                                              hkaSkeletonMapperData& originalBToA) throw()
{
    hkErrorInstance().beginSection(0x54e4323e, "hkaSkeletonMapperUtils::createMapping");

    bool switchedOrder = false;
    HkMapperParams params(originalParams);

    if (params.m_eMappingType == HK_RAGDOLL_MAPPING &&
        originalParams.m_pSkeletonA->m_kBones.GetLogicalSize() > originalParams.m_pSkeletonB->m_kBones.GetLogicalSize())
    {
        params.m_pSkeletonA = originalParams.m_pSkeletonB;
        params.m_pSkeletonB = originalParams.m_pSkeletonA;

        params.m_kFirstUserMappingList = originalParams.m_kSecondUserMappingList;
        params.m_kSecondUserMappingList = originalParams.m_kFirstUserMappingList;

        switchedOrder = true;
    }

    hkaSkeletonMapperData& aToB = switchedOrder ? originalBToA : originalAToB;
    hkaSkeletonMapperData& bToA = switchedOrder ? originalAToB : originalBToA;

    const int numBonesA = params.m_pSkeletonA->m_kBones.GetLogicalSize();
    const int numBonesB = params.m_pSkeletonB->m_kBones.GetLogicalSize();

    HkLocalArr<HkQs> modelPoseA(numBonesA);
    modelPoseA.setSizeUnchecked(numBonesA);
    FUN_00cddcf0(numBonesA, params.m_pSkeletonA->m_kParentIndices.begin(),
                 params.m_pSkeletonA->m_kReferencePose.begin(), modelPoseA.begin());

    HkLocalArr<HkQs> modelPoseB(numBonesB);
    modelPoseB.setSizeUnchecked(numBonesB);
    FUN_00cddcf0(numBonesB, params.m_pSkeletonB->m_kParentIndices.begin(),
                 params.m_pSkeletonB->m_kReferencePose.begin(), modelPoseB.begin());

    const HkQs* poseA = (params.m_eMappingType == HK_RAGDOLL_MAPPING) ? modelPoseA.begin()
                                                                      : params.m_pSkeletonA->m_kReferencePose.begin();
    const HkQs* poseB = (params.m_eMappingType == HK_RAGDOLL_MAPPING) ? modelPoseB.begin()
                                                                      : params.m_pSkeletonB->m_kReferencePose.begin();

    const int UNMATCHED = -1;
    const int INCHAIN = -2;

    HkLocalArr<short> map_AtoB(numBonesA);
    map_AtoB.SetSizeAndGrow(numBonesA, UNMATCHED);
    HkLocalArr<short> map_BtoA(numBonesB);
    map_BtoA.SetSizeAndGrow(numBonesB, UNMATCHED);

    aToB.m_eMappingType = params.m_eMappingType;
    bToA.m_eMappingType = params.m_eMappingType;

    reinterpret_cast<HkRef<const HkSkeleton>&>(aToB.m_pSkeletonA) = params.m_pSkeletonA;
    reinterpret_cast<HkRef<const HkSkeleton>&>(aToB.m_pSkeletonB) = params.m_pSkeletonB;

    reinterpret_cast<HkRef<const HkSkeleton>&>(bToA.m_pSkeletonA) = params.m_pSkeletonB;
    reinterpret_cast<HkRef<const HkSkeleton>&>(bToA.m_pSkeletonB) = params.m_pSkeletonA;

    {
        const int numMappings = params.m_kFirstUserMappingList.GetLogicalSize();
        for (int i = 0; i < numMappings; i++)
        {
            const HkUserMapping& mapping = params.m_kFirstUserMappingList[i];

            const short boneIn = FUN_00cdd390(*params.m_pSkeletonA, mapping.m_pBoneNameA, params.m_kBoneNameCompareFunction);
            const short boneOut = FUN_00cdd390(*params.m_pSkeletonB, mapping.m_pBoneNameB, params.m_kBoneNameCompareFunction);

            if (boneIn != -1 && boneOut != -1)
            {
                HkSimpleMapping simpleMapping;
                simpleMapping.m_sBoneA = boneIn;
                simpleMapping.m_sBoneB = boneOut;

                hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(params.m_eMappingType, poseA, boneIn, poseB, boneOut, simpleMapping.m_kAFromBTransform,
                             params.m_fFirstMappingTolerance, params.m_fSecondMappingTolerance);

                reinterpret_cast<HkArr<HkSimpleMapping>&>(aToB.m_kSimpleMappings).AddBack(simpleMapping);

                map_BtoA[boneOut] = boneIn;
            }
            else
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't find bones for mapping (")
                        .ProcessAndReturnValue_00cc01c0(mapping.m_pBoneNameA)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(mapping.m_pBoneNameB)
                        .ProcessAndReturnValue_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 127);
                }
                else
                    ;
            }
        }
    }

    {
        const int numMappings = params.m_kSecondUserMappingList.GetLogicalSize();
        for (int i = 0; i < numMappings; i++)
        {
            const HkUserMapping& mapping = params.m_kSecondUserMappingList[i];

            const short boneIn = FUN_00cdd390(*params.m_pSkeletonB, mapping.m_pBoneNameA, params.m_kBoneNameCompareFunction);
            const short boneOut = FUN_00cdd390(*params.m_pSkeletonA, mapping.m_pBoneNameB, params.m_kBoneNameCompareFunction);

            if (boneIn != -1 && boneOut != -1)
            {
                HkSimpleMapping simpleMapping;
                simpleMapping.m_sBoneA = boneIn;
                simpleMapping.m_sBoneB = boneOut;

                hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(params.m_eMappingType, poseB, boneIn, poseA, boneOut, simpleMapping.m_kAFromBTransform);

                reinterpret_cast<HkArr<HkSimpleMapping>&>(bToA.m_kSimpleMappings).AddBack(simpleMapping);

                map_AtoB[boneOut] = boneIn;
            }
            else
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't find bones for mapping (")
                        .ProcessAndReturnValue_00cc01c0(mapping.m_pBoneNameA)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(mapping.m_pBoneNameB)
                        .ProcessAndReturnValue_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 158);
                }
                else
                    ;
            }
        }
    }

    if (params.m_eMappingType == HK_RAGDOLL_MAPPING)
    {
        const int numChains = params.m_kUserChainList.GetLogicalSize();
        for (int i = 0; i < numChains; i++)
        {
            const HkUserChain& chain = params.m_kUserChainList[i];

            short startChainA = FUN_00cdd390(*params.m_pSkeletonA, chain.m_kRayStart, params.m_kBoneNameCompareFunction);
            short endChainA = FUN_00cdd390(*params.m_pSkeletonA, chain.m_kRayEnd, params.m_kBoneNameCompareFunction);

            short startChainB = FUN_00cdd390(*params.m_pSkeletonB, chain.m_kRayStart, params.m_kBoneNameCompareFunction);
            short endChainB = FUN_00cdd390(*params.m_pSkeletonB, chain.m_kRayEnd, params.m_kBoneNameCompareFunction);

            if (startChainA < 0 && startChainB < 0)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chain.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chain.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0("). Start bone not found in either skeleton.");
                    hkErrorInstance().message(1, 0x38521c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 185);
                }
                else
                    ;
                continue;
            }

            if (endChainA < 0 && endChainB < 0)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chain.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chain.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0("). End bone not found in either skeleton.");
                    hkErrorInstance().message(1, 0x38521c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 191);
                }
                else
                    ;
                continue;
            }

            if (startChainA < 0)
                startChainA = map_BtoA[startChainB];
            if (endChainA < 0)
                endChainA = map_BtoA[endChainB];
            if (startChainB < 0)
                startChainB = map_AtoB[startChainA];
            if (endChainB < 0)
                endChainB = map_AtoB[endChainA];

            HkArr<short> chainA;
            HkArr<short> chainB;
            const hkBool chainAok = FUN_00cde3d0(*params.m_pSkeletonA, startChainA, endChainA, chainA);
            const hkBool chainBok = FUN_00cde3d0(*params.m_pSkeletonB, startChainB, endChainB, chainB);

            if (!chainAok || !chainBok)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chain.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chain.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c63, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 210);
                }
                else
                    ;
                continue;
            }

            const int chainLengthA = chainA.GetLogicalSize();
            const int chainLengthB = chainB.GetLogicalSize();

            if (chainLengthA < 2 || chainLengthB < 2)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chain.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chain.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 220);
                }
                else
                    ;
                continue;
            }

            for (int a = 1; a < chainLengthA - 1; a++)
            {
                if (map_AtoB[chainA[a]] != UNMATCHED)
                {
                    if (1)
                    {
                        char assertBuf[512];
                        FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                        ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                            .ProcessAndReturnValue_00cc01c0(chain.m_kRayStart)
                            .ProcessAndReturnValue_00cc01c0(" - ")
                            .ProcessAndReturnValue_00cc01c0(chain.m_kRayEnd)
                            .ProcessAndReturnValue_00cc01c0(")");
                        hkErrorInstance().message(1, 0xabba1c65, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp",
                                                  230);
                    }
                    else
                        ;
                    continue;
                }
            }

            for (int b = 1; b < chainLengthB - 1; b++)
            {
                if (map_BtoA[chainB[b]] != UNMATCHED)
                {
                    if (1)
                    {
                        char assertBuf[512];
                        FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                        ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                            .ProcessAndReturnValue_00cc01c0(chain.m_kRayStart)
                            .ProcessAndReturnValue_00cc01c0(" - ")
                            .ProcessAndReturnValue_00cc01c0(chain.m_kRayEnd)
                            .ProcessAndReturnValue_00cc01c0(")");
                        hkErrorInstance().message(1, 0xabba1c66, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp",
                                                  239);
                    }
                    else
                        ;
                    continue;
                }
            }

            {
                if (1)
                {
                    char reportBuf[512];
                    FUN_00cb1600 ostr(reportBuf, sizeof(reportBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Creating chain ")
                        .WriteName(params.m_pSkeletonA->m_kBones[startChainA].m_name)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .WriteName(params.m_pSkeletonA->m_kBones[endChainA].m_name);
                    hkErrorInstance().message(0, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 249);
                }
                else
                    ;

                const HkQs& transformStartA = modelPoseA[startChainA];
                const HkQs& transformStartB = modelPoseB[startChainB];
                const HkQs& transformEndA = modelPoseA[endChainA];
                const HkQs& transformEndB = modelPoseB[endChainB];

                {
                    HkChainMapping chainMappingAtoB;

                    chainMappingAtoB.m_sStartBoneA = startChainA;
                    chainMappingAtoB.m_sEndBoneA = endChainA;
                    chainMappingAtoB.m_sStartBoneB = startChainB;
                    chainMappingAtoB.m_sEndBoneB = endChainB;
                    chainMappingAtoB.m_kEndAFromBTransform.SetMulInverse(transformEndA, transformEndB);
                    chainMappingAtoB.m_kStartAFromBTransform.SetMulInverse(transformStartA, transformStartB);

                    reinterpret_cast<HkArr<HkChainMapping>&>(aToB.m_kChainMappings).AddBack(chainMappingAtoB);
                }

                {
                    HkChainMapping chainMappingBtoA;

                    chainMappingBtoA.m_sStartBoneA = startChainB;
                    chainMappingBtoA.m_sEndBoneA = endChainB;
                    chainMappingBtoA.m_sStartBoneB = startChainA;
                    chainMappingBtoA.m_sEndBoneB = endChainA;
                    chainMappingBtoA.m_kEndAFromBTransform.SetMulInverse(transformEndB, transformEndA);
                    chainMappingBtoA.m_kStartAFromBTransform.SetMulInverse(transformStartB, transformStartA);

                    reinterpret_cast<HkArr<HkChainMapping>&>(bToA.m_kChainMappings).AddBack(chainMappingBtoA);
                }

                for (int a = 1; a < chainLengthA - 1; a++)
                {
                    map_AtoB[chainA[a]] = INCHAIN;
                }
                for (int b = 1; b < chainLengthB - 1; b++)
                {
                    map_BtoA[chainB[b]] = INCHAIN;
                }
            }
        }
    }
    else
    {
        const int numChains = params.m_kUserChainList.GetLogicalSize();

        for (int i = 0; i < numChains / 2; i++)
        {
            const HkUserChain& chainA = params.m_kUserChainList[i * 2];
            const HkUserChain& chainB = params.m_kUserChainList[i * 2 + 1];

            short startChainA = FUN_00cdd390(*params.m_pSkeletonA, chainA.m_kRayStart, params.m_kBoneNameCompareFunction);
            short endChainA = FUN_00cdd390(*params.m_pSkeletonA, chainA.m_kRayEnd, params.m_kBoneNameCompareFunction);

            short startChainB = FUN_00cdd390(*params.m_pSkeletonB, chainB.m_kRayStart, params.m_kBoneNameCompareFunction);
            short endChainB = FUN_00cdd390(*params.m_pSkeletonB, chainB.m_kRayEnd, params.m_kBoneNameCompareFunction);

            if (startChainA < 0 || endChainA < 0)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chainA.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chainA.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0("). Start or end bone not found.");
                    hkErrorInstance().message(1, 0xabbaa938, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 325);
                }
                else
                    ;
                continue;
            }

            if (startChainB < 0 || endChainB < 0)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chainB.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chainB.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0("). Start or end bone not found.");
                    hkErrorInstance().message(1, 0xabbaa938, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 331);
                }
                else
                    ;
                continue;
            }

            HkArr<short> chainABones;
            HkArr<short> chainBBones;
            const hkBool chainAok = FUN_00cde3d0(*params.m_pSkeletonA, startChainA, endChainA, chainABones);
            const hkBool chainBok = FUN_00cde3d0(*params.m_pSkeletonB, startChainB, endChainB, chainBBones);

            if (!chainAok)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chainA.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chainA.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c63, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 343);
                }
                else
                    ;
                continue;
            }

            if (!chainBok)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chainB.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chainB.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c63, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 349);
                }
                else
                    ;
                continue;
            }

            const int chainLengthA = chainABones.GetLogicalSize();
            const int chainLengthB = chainBBones.GetLogicalSize();

            if (chainLengthA < 2)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chainA.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chainA.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1d64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 359);
                }
                else
                    ;
                continue;
            }

            if (chainLengthB < 2)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                        .ProcessAndReturnValue_00cc01c0(chainB.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .ProcessAndReturnValue_00cc01c0(chainB.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1d64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 366);
                }
                else
                    ;
                continue;
            }

            for (int a = 0; a < chainLengthA; a++)
            {
                if (map_AtoB[chainABones[a]] != UNMATCHED)
                {
                    if (1)
                    {
                        char assertBuf[512];
                        FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                        ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                            .ProcessAndReturnValue_00cc01c0(chainA.m_kRayStart)
                            .ProcessAndReturnValue_00cc01c0(" - ")
                            .ProcessAndReturnValue_00cc01c0(chainA.m_kRayEnd)
                            .ProcessAndReturnValue_00cc01c0(")  Perhaps a bone is mapped twice?");
                        hkErrorInstance().message(1, 0xabba1d65, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp",
                                                  376);
                    }
                    else
                        ;
                    continue;
                }
            }

            for (int b = 0; b < chainLengthB; b++)
            {
                if (map_BtoA[chainBBones[b]] != UNMATCHED)
                {
                    if (1)
                    {
                        char assertBuf[512];
                        FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                        ostr.ProcessAndReturnValue_00cc01c0("Couldn't make a chain (")
                            .ProcessAndReturnValue_00cc01c0(chainB.m_kRayStart)
                            .ProcessAndReturnValue_00cc01c0(" - ")
                            .ProcessAndReturnValue_00cc01c0(chainB.m_kRayEnd)
                            .ProcessAndReturnValue_00cc01c0(")  Perhaps a bone is mapped twice?");
                        hkErrorInstance().message(1, 0xabba1d66, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp",
                                                  385);
                    }
                    else
                        ;
                    continue;
                }
            }

            {
                if (1)
                {
                    char reportBuf[512];
                    FUN_00cb1600 ostr(reportBuf, sizeof(reportBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Creating chains: ")
                        .ProcessAndReturnValue_00cc01c0("( ")
                        .ProcessAndReturnValue_00cc01c0(chainA.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(", ")
                        .ProcessAndReturnValue_00cc01c0(chainA.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0(" )   ( ")
                        .ProcessAndReturnValue_00cc01c0(chainB.m_kRayStart)
                        .ProcessAndReturnValue_00cc01c0(", ")
                        .ProcessAndReturnValue_00cc01c0(chainB.m_kRayEnd)
                        .ProcessAndReturnValue_00cc01c0(" )");
                    hkErrorInstance().message(0, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 397);
                }
                else
                    ;

                HkChainMapping chainMappingAFromB;
                HkChainMapping chainMappingBFromA;

                Object_BuildBonePairMapping(params.m_eMappingType, params.m_pSkeletonA, poseA, startChainA, endChainA,
                             params.m_pSkeletonB, poseB, startChainB, endChainB, chainMappingAFromB);

                Object_BuildBonePairMapping(params.m_eMappingType, params.m_pSkeletonB, poseB, startChainB, endChainB,
                             params.m_pSkeletonA, poseA, startChainA, endChainA, chainMappingBFromA);

                reinterpret_cast<HkArr<HkChainMapping>&>(bToA.m_kChainMappings).AddBack(chainMappingBFromA);
                reinterpret_cast<HkArr<HkChainMapping>&>(aToB.m_kChainMappings).AddBack(chainMappingAFromB);

                for (int a = 0; a < chainLengthA; a++)
                {
                    map_AtoB[chainABones[a]] = INCHAIN;
                }
                for (int b = 0; b < chainLengthB; b++)
                {
                    map_BtoA[chainBBones[b]] = INCHAIN;
                }
            }
        }
    }

    if (params.m_bFirstMappingOption)
    {
        HkArr<Match> matches;

        HkCompareFunc compare;
        if (params.m_kBoneNameCompareFunction)
        {
            compare = params.m_kBoneNameCompareFunction;
        }
        else
        {
            if (params.m_eMappingType == HK_RAGDOLL_MAPPING && params.m_fFirstMappingTolerance > 0.0f)
            {
                compare = 0;
            }
            else
            {
                compare = FUN_00cb0fe0;
            }
        }

        const HkSimd tolSqrd = params.m_fFirstMappingTolerance * params.m_fFirstMappingTolerance;

        for (int idxA = 0; idxA < numBonesA; idxA++)
        {
            if (compare)
            {
                for (int idxB = 0; idxB < numBonesB; idxB++)
                {
                    const char* nameA = params.m_pSkeletonA->m_kBones[idxA].m_name.cString();
                    const char* nameB = params.m_pSkeletonB->m_kBones[idxB].m_name.cString();

                    if (compare(nameA, nameB) == 0)
                    {
                        Match& match = matches.AllocatePair();
                        match.m_sBoneA = idxA;
                        match.m_sBoneB = idxB;
                    }
                }
            }
            else
            {
                const HkQs& transformA = modelPoseA[idxA];
                float shortest = 100000.0f;
                int shortestIndex = -1;
                for (int idxB = 0; idxB < numBonesB; idxB++)
                {
                    const HkQs& transformB = modelPoseB[idxB];

                    HkVec4 dif;
                    dif.setSub4(transformA.getTranslation(), transformB.getTranslation());
                    const float ls = dif.lengthSquared3();
                    if (ls < shortest)
                    {
                        shortest = ls;
                        shortestIndex = idxB;
                    }
                }
                if (shortest < tolSqrd)
                {
                    Match& match = matches.AllocatePair();
                    match.m_sBoneA = idxA;
                    match.m_sBoneB = shortestIndex;
                }
            }
        }

        const int numMatches = matches.GetLogicalSize();

        for (int i = 0; i < numMatches; i++)
        {
            const short boneA = (short)matches[i].m_sBoneA;
            const short boneB = (short)matches[i].m_sBoneB;

            if (map_AtoB[boneA] != UNMATCHED || map_BtoA[boneB] != UNMATCHED)
            {
                continue;
            }

            {
                HkSimpleMapping simpleMappingAtoB;
                simpleMappingAtoB.m_sBoneA = boneA;
                simpleMappingAtoB.m_sBoneB = boneB;

                const char* boneAName = params.m_pSkeletonA->m_kBones[boneA].m_name.cString();
                const char* boneBName = params.m_pSkeletonB->m_kBones[boneB].m_name.cString();

                hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(params.m_eMappingType, poseA, boneA, poseB, boneB, simpleMappingAtoB.m_kAFromBTransform,
                             params.m_fFirstMappingTolerance, 1.0f);

                reinterpret_cast<HkArr<HkSimpleMapping>&>(aToB.m_kSimpleMappings).AddBack(simpleMappingAtoB);
            }

            {
                HkSimpleMapping simpleMappingBtoA;
                simpleMappingBtoA.m_sBoneA = boneB;
                simpleMappingBtoA.m_sBoneB = boneA;

                const char* boneAName = params.m_pSkeletonA->m_kBones[boneA].m_name.cString();
                const char* boneBName = params.m_pSkeletonB->m_kBones[boneB].m_name.cString();

                hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(params.m_eMappingType, poseB, boneB, poseA, boneA, simpleMappingBtoA.m_kAFromBTransform,
                             params.m_fFirstMappingTolerance, 1.0f);

                reinterpret_cast<HkArr<HkSimpleMapping>&>(bToA.m_kSimpleMappings).AddBack(simpleMappingBtoA);
            }

            checkRotation(params, boneA, boneB, reinterpret_cast<HkArr<HkSimpleMapping>&>(aToB.m_kSimpleMappings).back().m_kAFromBTransform,
                          reinterpret_cast<HkArr<HkSimpleMapping>&>(bToA.m_kSimpleMappings).back().m_kAFromBTransform);

            map_AtoB[boneA] = boneB;
            map_BtoA[boneB] = boneA;

            if (1)
            {
                char reportBuf[512];
                FUN_00cb1600 ostr(reportBuf, sizeof(reportBuf));
                ostr.ProcessAndReturnValue_00cc01c0("Matching ").WriteName(params.m_pSkeletonA->m_kBones[boneA].m_name);
                hkErrorInstance().message(0, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 561);
            }
            else
                ;
        }
    }

    if (params.m_bSecondMappingOption)
    {
        for (int boneA = 0; boneA < numBonesA; boneA++)
        {
            if (map_AtoB[boneA] < 0)
            {
                continue;
            }

            const short endChainA = (short)boneA;
            const short endChainB = map_AtoB[boneA];

            short startChainA = params.m_pSkeletonA->m_kParentIndices[boneA];

            while (startChainA != -1 && UNMATCHED == map_AtoB[startChainA])
            {
                startChainA = params.m_pSkeletonA->m_kParentIndices[startChainA];
            }

            if (-1 == startChainA || INCHAIN == map_AtoB[startChainA])
            {
                continue;
            }

            const short startChainB = map_AtoB[startChainA];

            HkArr<short> chainA;
            HkArr<short> chainB;
            const hkBool chainAok = FUN_00cde3d0(*params.m_pSkeletonA, startChainA, endChainA, chainA);
            const hkBool chainBok = FUN_00cde3d0(*params.m_pSkeletonB, startChainB, endChainB, chainB);

            if (!chainAok || !chainBok)
            {
                continue;
            }

            const int chainLengthA = chainA.GetLogicalSize();
            const int chainLengthB = chainB.GetLogicalSize();

            if (chainLengthA == 2 && chainLengthB == 2)
            {
                continue;
            }

            {
                bool ok = true;
                for (int b = 1; b < chainLengthB - 1; b++)
                {
                    if (map_BtoA[chainB[b]] != UNMATCHED)
                    {
                        ok = false;
                        continue;
                    }
                }
                if (!ok)
                {
                    continue;
                }
            }

            {
                if (1)
                {
                    char reportBuf[512];
                    FUN_00cb1600 ostr(reportBuf, sizeof(reportBuf));
                    ostr.ProcessAndReturnValue_00cc01c0("Creating chain ")
                        .WriteName(params.m_pSkeletonA->m_kBones[startChainA].m_name)
                        .ProcessAndReturnValue_00cc01c0(" - ")
                        .WriteName(params.m_pSkeletonA->m_kBones[endChainA].m_name);
                    hkErrorInstance().message(0, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 637);
                }
                else
                    ;

                const HkQs& transformStartA = modelPoseA[startChainA];
                const HkQs& transformStartB = modelPoseB[startChainB];
                const HkQs& transformEndA = modelPoseA[endChainA];
                const HkQs& transformEndB = modelPoseB[endChainB];

                {
                    HkChainMapping chainMappingAtoB;

                    chainMappingAtoB.m_sStartBoneA = startChainA;
                    chainMappingAtoB.m_sEndBoneA = endChainA;
                    chainMappingAtoB.m_sStartBoneB = startChainB;
                    chainMappingAtoB.m_sEndBoneB = endChainB;
                    chainMappingAtoB.m_kEndAFromBTransform.SetMulInverse(transformEndA, transformEndB);
                    chainMappingAtoB.m_kStartAFromBTransform.SetMulInverse(transformStartA, transformStartB);

                    reinterpret_cast<HkArr<HkChainMapping>&>(aToB.m_kChainMappings).AddBack(chainMappingAtoB);
                }

                {
                    HkChainMapping chainMappingBtoA;

                    chainMappingBtoA.m_sStartBoneA = startChainB;
                    chainMappingBtoA.m_sEndBoneA = endChainB;
                    chainMappingBtoA.m_sStartBoneB = startChainA;
                    chainMappingBtoA.m_sEndBoneB = endChainA;
                    chainMappingBtoA.m_kEndAFromBTransform.SetMulInverse(transformEndB, transformEndA);
                    chainMappingBtoA.m_kStartAFromBTransform.SetMulInverse(transformStartB, transformStartA);

                    reinterpret_cast<HkArr<HkChainMapping>&>(bToA.m_kChainMappings).AddBack(chainMappingBtoA);
                }

                for (int a = 1; a < chainLengthA - 1; a++)
                {
                    map_AtoB[chainA[a]] = INCHAIN;
                }
                for (int b = 1; b < chainLengthB - 1; b++)
                {
                    map_BtoA[chainB[b]] = INCHAIN;
                }
            }
        }
    }

    for (int b = 0; b < numBonesB; b++)
    {
        if (UNMATCHED == map_BtoA[b])
        {
            reinterpret_cast<HkArr<short>&>(aToB.m_kUnmappedBones).AddBack((short)b);
        }
    }

    for (int a = 0; a < numBonesA; a++)
    {
        if (UNMATCHED == map_AtoB[a])
        {
            reinterpret_cast<HkArr<short>&>(bToA.m_kUnmappedBones).AddBack((short)a);
        }
    }

    aToB.m_bKeepUnmappedLocal.m_cBooleanValue = true;
    bToA.m_bKeepUnmappedLocal.m_cBooleanValue = true;

    reinterpret_cast<HkQs&>(originalAToB.m_kExtractedMotionMapping).setIdentity();
    reinterpret_cast<HkQs&>(originalBToA.m_kExtractedMotionMapping).setIdentity();

    if (params.m_eMappingType == HK_RETARGETING_MAPPING)
    {
        params.m_kMotionParams.hkQsTransform_ComputePoseScaleFactors(params.m_eMappingType, modelPoseA.begin(), numBonesA, modelPoseB.begin(),
                                           numBonesB, reinterpret_cast<HkQs&>(originalAToB.m_kExtractedMotionMapping),
                                           reinterpret_cast<HkQs&>(originalBToA.m_kExtractedMotionMapping));
    }

    hkErrorInstance().endSection();
}

#include <xmmintrin.h>
namespace fnv_00ce5a70 {
typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_add_ss;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_and_ps;
using ::_mm_xor_ps;
using ::_mm_shuffle_ps;
using ::_mm_rcp_ps;
using ::_mm_sqrt_ss;
using ::_mm_unpackhi_ps;
using ::_mm_unpacklo_ps;
using ::_mm_movelh_ps;
using ::_mm_load_ss;
using ::_mm_store_ss;
}

extern const LocalM128 DAT_010c71e0;
extern const LocalM128 DAT_010c7170;
extern const LocalM128 DAT_010c44d0;
extern const LocalM128 DAT_010c4c00;
extern const LocalM128 DAT_010c4c10;

struct HkQuat;
struct HkVec
{
    LocalM128 m;
    __forceinline void setRotatedInverseDir(const HkQuat& q, const HkVec& v);
    __forceinline void SetRotatedDirection(const HkQuat& q, const HkVec& v);
    __forceinline void setReciprocal3(const HkVec& v);
    __forceinline float length3() const;
};
struct HkQuat
{
    HkVec v;
    void setMul(const HkQuat& a, const HkQuat& b) throw();
    void setMulInverse(const HkQuat& a, const HkQuat& b) throw();
};
// local form of hkQsTransform: 0x00ce5a70 needs inline SetConjugate/SetProduct and original scalar aliases; shared form gives 667 bytes vs exe 999.
struct HkQs
{
    HkVec m_vTranslation;
    HkQuat m_rotation;
    HkVec m_vScale;
    hkBool* FUN_00ce50e0(hkBool* res) const throw();
    __forceinline void SetConjugate(const HkQs& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.m = _mm_xor_ps(m_vTranslation.m, DAT_010c44d0);
        m_rotation.v.m = _mm_xor_ps(t.m_rotation.v.m, DAT_010c4c00);
        m_vScale.setReciprocal3(t.m_vScale);
    }
    __forceinline void SetProduct(const HkQs& a, const HkQs& b)
    {
        m_vTranslation.SetRotatedDirection(a.m_rotation, b.m_vTranslation);
        m_vTranslation.m = _mm_add_ps(m_vTranslation.m, a.m_vTranslation.m);
        m_rotation.setMul(a.m_rotation, b.m_rotation);
        m_vScale.m = _mm_mul_ps(b.m_vScale.m, a.m_vScale.m);
    }
};

static __forceinline LocalM128 dot3_from_prod(LocalM128 prod)
{
    LocalM128 y = _mm_shuffle_ps(prod, prod, 0x55);
    LocalM128 d = _mm_add_ss(y, prod);
    LocalM128 z = _mm_shuffle_ps(prod, prod, 0xAA);
    return _mm_add_ss(z, d);
}

__forceinline void HkVec::setRotatedInverseDir(const HkQuat& quat, const HkVec& vec)
{
    LocalM128 q = quat.v.m;
    LocalM128 v = vec.m;
    LocalM128 qw = _mm_shuffle_ps(quat.v.m, quat.v.m, 0xFF);
    LocalM128 prod = _mm_mul_ps(v, q);
    LocalM128 dot = dot3_from_prod(prod);
    LocalM128 v_yzx = _mm_shuffle_ps(v, v, 0xC9);
    LocalM128 q_zxy = _mm_shuffle_ps(q, q, 0xD2);
    LocalM128 cross = _mm_mul_ps(v_yzx, q_zxy);
    LocalM128 v_zxy = _mm_shuffle_ps(v, v, 0xD2);
    LocalM128 q_yzx = _mm_shuffle_ps(q, q, 0xC9);
    cross = _mm_sub_ps(cross, _mm_mul_ps(v_zxy, q_yzx));
    cross = _mm_mul_ps(cross, qw);
    LocalM128 qw2 = _mm_mul_ps(qw, qw);
    qw2 = _mm_add_ps(qw2, DAT_010c71e0);
    LocalM128 term = _mm_mul_ps(qw2, v);
    LocalM128 qdot = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    term = _mm_add_ps(term, qdot);
    term = _mm_add_ps(cross, term);
    m = _mm_add_ps(term, term);
}

__forceinline void HkVec::SetRotatedDirection(const HkQuat& quat, const HkVec& vec)
{
    LocalM128 q = quat.v.m;
    LocalM128 v = vec.m;
    LocalM128 qw = _mm_shuffle_ps(quat.v.m, quat.v.m, 0xFF);
    LocalM128 prod = _mm_mul_ps(v, q);
    LocalM128 dot = dot3_from_prod(prod);
    LocalM128 q_zxy = _mm_shuffle_ps(q, q, 0xD2);
    LocalM128 v_yzx = _mm_shuffle_ps(v, v, 0xC9);
    LocalM128 cross = _mm_mul_ps(v_yzx, q_zxy);
    LocalM128 v_zxy = _mm_shuffle_ps(v, v, 0xD2);
    LocalM128 q_yzx = _mm_shuffle_ps(q, q, 0xC9);
    cross = _mm_sub_ps(_mm_mul_ps(v_zxy, q_yzx), cross);
    cross = _mm_mul_ps(cross, qw);
    LocalM128 qw2 = _mm_mul_ps(qw, qw);
    qw2 = _mm_add_ps(qw2, DAT_010c71e0);
    LocalM128 term = _mm_mul_ps(qw2, v);
    LocalM128 qdot = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    term = _mm_add_ps(term, qdot);
    term = _mm_add_ps(cross, term);
    m = _mm_add_ps(term, term);
}

static __forceinline HkVec quadReciprocal(const HkVec& v)
{
    HkVec result;
    LocalM128 r = _mm_rcp_ps(v.m);
    LocalM128 e = _mm_mul_ps(r, v.m);
    e = _mm_mul_ps(e, r);
    result.m = _mm_sub_ps(_mm_add_ps(r, r), e);
    return result;
}
__forceinline void HkVec::setReciprocal3(const HkVec& vec)
{
    LocalM128 s = vec.m;
    LocalM128 ones = DAT_010c7170;
    LocalM128 hi = _mm_unpackhi_ps(s, ones);
    LocalM128 mixed = _mm_shuffle_ps(s, hi, 0xC4);
    HkVec v;
    v.m = mixed;
    HkVec result = quadReciprocal(v);
    m = _mm_and_ps(result.m, DAT_010c4c10);
}

__forceinline float HkVec::length3() const
{
    LocalM128 v = m;
    LocalM128 sq = _mm_mul_ps(v, v);
    LocalM128 d = dot3_from_prod(sq);
    d = _mm_sqrt_ss(d);
    float out;
    _mm_store_ss(&out, d);
    return out;
}

// src: COMMUNITY 0x00c66320
__declspec(noinline) void HkQuat::setMul(const HkQuat& a, const HkQuat& b) throw()
{
    LocalM128 av = a.v.m, bv = b.v.m;
    LocalM128 ax = _mm_shuffle_ps(av, av, 0), ay = _mm_shuffle_ps(av, av, 0x55);
    LocalM128 az = _mm_shuffle_ps(av, av, 0xaa), aw = _mm_shuffle_ps(av, av, 0xff);
    LocalM128 bx = _mm_shuffle_ps(bv, bv, 0), by = _mm_shuffle_ps(bv, bv, 0x55);
    LocalM128 bz = _mm_shuffle_ps(bv, bv, 0xaa), bw = _mm_shuffle_ps(bv, bv, 0xff);
    LocalM128 x = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(ay, bz), _mm_mul_ps(az, by)), _mm_mul_ps(aw, bx)),
                          _mm_mul_ps(bw, ax));
    LocalM128 y = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(az, bx), _mm_mul_ps(ax, bz)), _mm_mul_ps(aw, by)),
                          _mm_mul_ps(bw, ay));
    LocalM128 z = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(ax, by), _mm_mul_ps(ay, bx)), _mm_mul_ps(aw, bz)),
                          _mm_mul_ps(bw, az));
    LocalM128 sum = _mm_add_ps(_mm_add_ps(_mm_mul_ps(ay, by), _mm_mul_ps(ax, bx)), _mm_mul_ps(az, bz));
    LocalM128 w = _mm_sub_ps(_mm_mul_ps(aw, bw), sum);
    LocalM128 xy = _mm_unpacklo_ps(x, y), zw = _mm_unpacklo_ps(z, w);
    v.m = _mm_movelh_ps(xy, zw);
}

static __forceinline void warnAlways(int id, const char* text, int line)
{
    char assertBuf[512];
    hkOstream ostr(assertBuf, 512);
    ostr << text;
    hkError::s_instance->message(1, id, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", line);
}

// @fnv 0x00ce5a70
// src: COMMUNITY 0x00ce5a70
void __cdecl hkaSkeletonMapperUtils_computeMappingTransform(CE5F90QsTransform* mappingType, const CE5F90QsTransform* poseA,
                          const CE5F90QsTransform* poseB, int outputAddress, float tolerance, float defaultScale)
{
    int type = reinterpret_cast<int>(mappingType);
    CE5F90QsTransform* mapOut = reinterpret_cast<CE5F90QsTransform*>(outputAddress);
    HkQs* a = (HkQs*)poseA;
    HkQs* b = (HkQs*)poseB;
    HkQs* out = (HkQs*)mapOut;

    if (type == 0)
    {
        HkQs inverse;
        inverse.SetConjugate(*a);
        out->SetProduct(inverse, *b);
    }
    else if (type == 1)
    {
        if (tolerance < 0.0f)
        {
            warnAlways(0xabba39c3, "Tolerance must be positive", 846);
        }
        float lenA = a->m_vTranslation.length3();
        float lenB = b->m_vTranslation.length3();
        bool aZero = lenA <= tolerance;
        bool bZero = lenB <= tolerance;
        float scale;
        switch (aZero || bZero)
        {
        case false:
            scale = lenB / lenA;
            break;
        default:
            if (aZero != bZero)
            {
                warnAlways(
                    0xabba2b94,
                    "Attempt to map a zero length bone to a non-zero length bone.  This may result in poor accuracy.",
                    860);
            }
            scale = defaultScale;
            break;
        }
        LocalM128 sv = _mm_load_ss(&scale);
        sv = _mm_shuffle_ps(sv, sv, 0);
        out->m_vScale.m = sv;
        out->m_rotation.setMulInverse(b->m_rotation, a->m_rotation);
        float neg = -scale;
        LocalM128 ns = _mm_load_ss(&neg);
        ns = _mm_shuffle_ps(ns, ns, 0);
        LocalM128 tr = _mm_mul_ps(ns, a->m_vTranslation.m);
        tr = _mm_add_ps(tr, b->m_vTranslation.m);
        out->m_vTranslation.m = tr;
    }
    else
    {
        warnAlways(0xabbaef91, "Unsupported mapping type", 876);
    }

    hkBool valid;
    if (!out->FUN_00ce50e0(&valid)->m_cBooleanValue)
    {
        warnAlways(0xabba10fc, "Mapping is invalid", 881);
    }
}
}  // namespace fnv_00ce5a70
