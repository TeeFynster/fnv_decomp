// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkThreadMemory.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkQsTransform.h"
#include "../../../../../../include/hkError.h"

// Read the legacy heap slot as its allocator type to retain the original aliasing behavior.
inline hkMemoryAllocator& hkThreadMemory::heap()
{
    return **reinterpret_cast<hkMemoryAllocator**>(&m_pMemoryAllocator);
}

extern "C" const char str_010eb400[];  // "Compression Ratio: "
extern "C" const char str_010eb414[];  // ":1."
extern "C" const char str_010eb418[];  // "Original Size: "
extern "C" const char str_010eb428[];  // " bytes. Compressed Size: "
extern "C" const char str_010eb444[];  // "Size of largest block (PS3 SPU): "
extern "C" const char str_010eb468[];  // " bytes."
extern "C" const char str_010eb470[];  // .\Animation\SplineCompressed\hkaSplineCompressedAnimationCtor.cpp
extern "C" const char str_010eb4b4[];  // "Number of blocks: "
extern "C" const char str_010eb4c8[];  // "Compression"
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

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
void ResizeAudioStream(hkMemoryAllocator& a, void* array, int sizeElem);
void hkArrayUtil__reserve(hkMemoryAllocator& a, void* array, int reqElem, int sizeElem);

struct Se31d50_ContainerHeap
{
    __forceinline hkMemoryAllocator& get(const void*)
    {
        return hkThreadMemory::GetMonitorStream()->heap();
    }
};
template <bool B> struct Se31d50_Trait
{
};
typedef Se31d50_Trait<true> Se31d50_IsPod;
typedef Se31d50_Trait<false> Se31d50_IsClass;
struct Se31d50_ArrayUtil
{
    template <typename T> static __forceinline void construct(T*, int, Se31d50_IsPod)
    {}
    template <typename T> static __forceinline void destruct(T*, int, Se31d50_IsPod)
    {}
    template <typename T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, Se31d50_IsPod)
    {
        for (int i = 0; i < n; ++i)
            t[i] = tcopy;
    }
};
// The shared hkArray currently exposes storage only, without the allocation API below.
template <typename T> struct Se31d50_ArrayBase
{
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline Se31d50_ArrayBase()
    {}
    __forceinline ~Se31d50_ArrayBase()
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline const T* begin() const
    {
        return m_data;
    }
    __forceinline void clear()
    {
        Se31d50_ArrayUtil::destruct(m_data, m_iElementCount, Se31d50_IsPod());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        Se31d50_ArrayUtil::destruct(m_data + n, m_iElementCount - n, Se31d50_IsPod());
        Se31d50_ArrayUtil::construct(m_data + m_iElementCount, n - m_iElementCount, Se31d50_IsPod());
        m_iElementCount = n;
    }
    __forceinline void _pushBack(hkMemoryAllocator& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(T));
        }
        Se31d50_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, Se31d50_IsPod());
        m_iElementCount++;
    }
    __forceinline void setOwnedData(T* ptr, int size, int capacity)
    {
        m_data = ptr;
        m_iElementCount = size;
        m_iCapacityState = capacity;
    }
};
template <typename T> struct Se31d50_Array : Se31d50_ArrayBase<T>
{
    __forceinline Se31d50_Array()
    {}
    __forceinline void init()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = Se31d50_ArrayBase<T>::DONT_DEALLOCATE_FLAG;
    }
    __forceinline Se31d50_Array(int n)
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = Se31d50_ArrayBase<T>::DONT_DEALLOCATE_FLAG;
        hkMemoryAllocator& a = Se31d50_ContainerHeap().get(this);
        T* p = n ? a._bufAlloc<T>(n) : 0;
        int cap = n ? n : (int)0x80000000;
        this->setOwnedData(p, n, cap);
        Se31d50_ArrayUtil::construct(this->m_data, n, Se31d50_IsPod());
    }
    __forceinline ~Se31d50_Array()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        this->_clearAndDeallocate(Se31d50_ContainerHeap().get(this));
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->_setSize(Se31d50_ContainerHeap().get(this), n);
    }
    __forceinline void AddBack(const T& t)
    {
        this->_pushBack(Se31d50_ContainerHeap().get(this), t);
    }
};
__forceinline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x) {}
__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline const __m128& hkSimdReal::getQuad() const { return m_vValue; }

__forceinline void hkVector4::set(float a, float b, float c, float d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}
__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline void hkVector4::setMul4(float a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(_mm_set_ss(a), _mm_set_ss(a), 0), b.m_vComponents);
}
__forceinline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline const float& hkVector4::operator()(int i) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[i];
}
__forceinline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
    __m128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
    return _mm_add_ps(sum0, sum1);
}
__forceinline hkSimdReal lengthInverse4(const hkVector4& v)
{
    const __m128 half = _mm_set_ss(0.5f);
    const __m128 three = _mm_set_ss(3.0f);
    const __m128 zero = _mm_set_ss(0.0f);
    const __m128 len2 = v.dot4(v).getQuad();
    const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const __m128 approx = _mm_rsqrt_ss(len2);
    const __m128 refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}
__forceinline void hkVector4::normalize4()
{
    __m128 lenInv = lengthInverse4(*this).broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
}
enum Se31d50_RotQ
{
    Se31d50_POLAR32 = 0
};
enum Se31d50_ScalQ
{
    Se31d50_BITS8 = 0
};
enum Se31d50_AnimType
{
    Se31d50_SPLINE = 5
};
template <typename E, typename S> struct Se31d50_Enum
{
    S m_kStorage;
    __forceinline operator E() const
    {
        return (E)m_kStorage;
    }
    __forceinline void operator=(E e)
    {
        m_kStorage = (S)e;
    }
};
struct Se31d50_TrackParams
{
    float m_fRotationTolerance;
    float m_fTranslationTolerance;
    float m_fScaleTolerance;
    float m_fFloatingTolerance;
    unsigned short m_iRotationDegree;
    unsigned short m_iTranslationDegree;
    unsigned short m_iScaleDegree;
    unsigned short m_iFloatingDegree;
    Se31d50_Enum<Se31d50_RotQ, unsigned char> m_eRotationQuantizationType;
    Se31d50_Enum<Se31d50_ScalQ, unsigned char> m_eTranslationQuantizationType;
    Se31d50_Enum<Se31d50_ScalQ, unsigned char> m_eScaleQuantizationType;
    Se31d50_Enum<Se31d50_ScalQ, unsigned char> m_eFloatQuantizationType;
};
struct Se31d50_PerTrack
{
    Se31d50_Array<Se31d50_TrackParams> m_kTrackParams;
    Se31d50_Array<int> m_kFirstIntArray;
    Se31d50_Array<int> m_kSecondIntArray;
};
struct Se31d50_AnimParams
{
    unsigned short m_iMaxFramesPerBlock;
    hkBool m_bEnableSampleSingleTracks;
};
// The shared animation base lacks the frame-count virtual signature used here.
struct Se31d50_Raw
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetIntegerValue() const;
    int unk04;
    int unk08;
    float unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Se31d50_Array<hkQsTransform> m_kTransforms;
    Se31d50_Array<float> m_kFloats;
};
extern hkError* DAT_01268360;
// The shared hkOstream lacks the integer writer declaration used by these reports.
struct Se31d50_ErrStream
{
    void* unk00;
    int unk04;
    void* unk08;
    void FUN_00cb1600(void* buf, int bufSize);
    void FUN_00cc00e0();
    Se31d50_ErrStream& ProcessAndReturnValue_00cc01c0(const char* s);
    Se31d50_ErrStream& WriteInt(int i);
    Se31d50_ErrStream& EvaluateValue_00cc02d0(unsigned int u);
    Se31d50_ErrStream& WriteFloat(float f);
    __forceinline Se31d50_ErrStream(void* buf, int bufSize)
    {
        FUN_00cb1600(buf, bufSize);
    }
    __forceinline ~Se31d50_ErrStream()
    {
        FUN_00cc00e0();
    }
    __forceinline Se31d50_ErrStream& operator<<(const char* s)
    {
        return ProcessAndReturnValue_00cc01c0(s);
    }
    __forceinline Se31d50_ErrStream& operator<<(int i)
    {
        return WriteInt(i);
    }
    __forceinline Se31d50_ErrStream& operator<<(unsigned int i)
    {
        return EvaluateValue_00cc02d0(i);
    }
    __forceinline Se31d50_ErrStream& operator<<(float f)
    {
        return WriteFloat(f);
    }
};
typedef Se31d50_Array<hkVector4> Se31d50_VecArr;
typedef Se31d50_Array<float> Se31d50_FltArr;
typedef Se31d50_Array<unsigned char> Se31d50_ByteArr;
void _ApproximateNURBSCurve(int numPoints, const float* U, const hkVector4* P, int degree, float tolerance, int* numKnots,
                  float* knots, int* numCP, hkVector4* cp);

// The shared spline animation header lacks the builder methods and parameter types.
struct Se31d50_Anim
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int GetValueAt2C() const;
    int unk04;
    Se31d50_Enum<Se31d50_AnimType, int> m_type;
    float m_fAnimationDuration;
    int m_iNumTransformTracks;
    int m_iNumberOfFloatTracks;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_iFrameCount;
    int m_iBlockCount;
    int m_iMaxFramesPerBlock;
    int m_iMaskAndQuantizationSize;
    float m_fBlockDuration;
    float m_fBlockInverseDuration;
    float m_fPerFrameDuration;
    Se31d50_Array<unsigned int> m_kFirstUInt32Array;
    Se31d50_Array<unsigned int> m_kFloatBlockOffsets;
    Se31d50_Array<unsigned int> m_kTransformOffsets;
    Se31d50_Array<unsigned int> m_kFloatOffsets;
    Se31d50_ByteArr m_kCompressedData;
    int m_iEndian;
    int getSizeInBytes() const;
    void AppendScaledValues(int n, int p, const Se31d50_FltArr& U);
    void ProcessEntries_00e319e0(unsigned char mask, Se31d50_RotQ q, const hkVector4& s, int n, const Se31d50_VecArr& p);
    void WriteCompressedAnimation(unsigned char mask, Se31d50_ScalQ q, const hkVector4& s,
                                  const hkVector4& mn, const hkVector4& mx, int n, const Se31d50_VecArr& p);
    void hkaSplineCompressedAnimation_initialize(const Se31d50_Raw& raw, const Se31d50_PerTrack& trackParams,
                      const Se31d50_AnimParams& animationParams);
    static hkVector4 Runtime_ProcessEntries_00e31410(const Se31d50_VecArr& d);
    static hkVector4 hkArrayBase_ProcessEntries_00e31470(const Se31d50_VecArr& d);
    static hkVector4 hkArrayBase_ProcessEntries_00e314c0(const Se31d50_VecArr& d);
    static unsigned char hkaSplineCompressedAnimation_isStatic(const hkVector4& mean, const hkVector4& mn, const hkVector4& mx,
                                      float tol, const hkVector4& id);
    static unsigned char PackBitFields(Se31d50_ScalQ t, Se31d50_RotQ r, Se31d50_ScalQ s);
    static unsigned char hkaSplineCompressedAnimation_packMaskAndQuantizationType(unsigned char mask, Se31d50_ScalQ f);
    static void hkaSplineCompressedAnimation_writeZeros(int n, Se31d50_ByteArr& out);
    static void hkaSplineCompressedAnimation_writeAlign(int align, Se31d50_ByteArr& out);
    static void FillInterpolatedValues(int n, Se31d50_FltArr& U, float a, float b);
    static void hkVector4_ProcessEntries_00e310c0(const hkQsTransform* t, int numTracks, int numFrames, int first, int track, Se31d50_VecArr& a,
                             Se31d50_VecArr& b, Se31d50_VecArr& c);
    static void Object_ProcessEntries_00e31180(const float* f, int numTracks, int numFrames, int first, int track, Se31d50_VecArr& a);
};

extern "C" double __cdecl fabs(double);
// src: GUESS 0x00e31410 (confidence: low)
__declspec(noinline) hkVector4 Se31d50_Anim::Runtime_ProcessEntries_00e31410(const Se31d50_VecArr& data)
{
    hkVector4 mean;
    mean.setZero4();
    const int n = data.GetLogicalSize();
    for (int i = 0; i < n; i++)
    {
        mean.add4(data[i]);
    }
    mean.setMul4(1.0f / n, mean);
    return mean;
}
// src: GUESS 0x00e31470 (confidence: low)
__declspec(noinline) hkVector4 Se31d50_Anim::hkArrayBase_ProcessEntries_00e31470(const Se31d50_VecArr& data)
{
    hkVector4 m = data[0];
    const int n = data.GetLogicalSize();
    for (int i = 1; i < n; i++)
    {
        m.setMin4(m, data[i]);
    }
    return m;
}
// src: GUESS 0x00e314c0 (confidence: low)
__declspec(noinline) hkVector4 Se31d50_Anim::hkArrayBase_ProcessEntries_00e314c0(const Se31d50_VecArr& data)
{
    hkVector4 m = data[0];
    const int n = data.GetLogicalSize();
    for (int i = 1; i < n; i++)
    {
        m.setMax4(m, data[i]);
    }
    return m;
}
// src: HAVOK_LIB 0x00e311f0
__declspec(noinline) unsigned char Se31d50_Anim::hkaSplineCompressedAnimation_isStatic(const hkVector4& mean, const hkVector4& mn,
                                                              const hkVector4& mx, float tol,
                                                              const hkVector4& id)
{
    unsigned char mask = 0;
    for (int i = 0; i < 4; i++)
    {
        if ((float)fabs(mean(i) - mn(i)) > tol || (float)fabs(mean(i) - mx(i)) > tol)
        {
            mask |= (1 << (i + 4));
        }
        else if ((float)fabs(mean(i) - id(i)) > tol)
        {
            mask |= (1 << i);
        }
    }
    return mask;
}
__declspec(noinline) unsigned char Se31d50_Anim::PackBitFields(Se31d50_ScalQ t, Se31d50_RotQ r, Se31d50_ScalQ s)
{
    return (unsigned char)(t | (r << 2) | (s << 6));
}
// src: HAVOK_LIB 0x00e30f40
__declspec(noinline) unsigned char Se31d50_Anim::hkaSplineCompressedAnimation_packMaskAndQuantizationType(unsigned char mask, Se31d50_ScalQ f)
{
    return (unsigned char)(mask | (f << 1));
}
__declspec(noinline) void Se31d50_Anim::FillInterpolatedValues(int n, Se31d50_FltArr& U, float a, float b)
{
    U[0] = a;
    U[n] = b;
    for (int i = 1; i < n; i++)
    {
        U[i] = (float)i / n * (b - a) + a;
    }
}
// src: GUESS 0x00e310c0 (confidence: low)
__declspec(noinline) void Se31d50_Anim::hkVector4_ProcessEntries_00e310c0(const hkQsTransform* src, int numTracks, int numFrames, int first,
                                                     int track, Se31d50_VecArr& a, Se31d50_VecArr& b, Se31d50_VecArr& c)
{
    for (int i = 0; i < numFrames; i++)
    {
        const hkQsTransform& t = src[(i + first) * numTracks + track];
        a[i].set(t.m_vTranslation(0), t.m_vTranslation(1), t.m_vTranslation(2), 0.0f);
        b[i].set(reinterpret_cast<const hkVector4&>(t.m_rotation)(0), reinterpret_cast<const hkVector4&>(t.m_rotation)(1), reinterpret_cast<const hkVector4&>(t.m_rotation)(2), reinterpret_cast<const hkVector4&>(t.m_rotation)(3));
        c[i].set(t.m_vScale(0), t.m_vScale(1), t.m_vScale(2), 0.0f);
    }
}
// src: GUESS 0x00e31180 (confidence: low)
__declspec(noinline) void Se31d50_Anim::Object_ProcessEntries_00e31180(const float* f, int numTracks, int numFrames, int first, int track,
                                                     Se31d50_VecArr& a)
{
    for (int i = 0; i < numFrames; i++)
    {
        a[i].set(f[(i + first) * numTracks + track], 0.0f, 0.0f, 0.0f);
    }
}
__forceinline int Se31d50_max2(int x, int y)
{
    return x > y ? x : y;
}
__forceinline int Se31d50_min2(int x, int y)
{
    return x < y ? x : y;
}

// @fnv 0x00e31d50
// src: XBOX_PDB 0x00e31d50
void Se31d50_Anim::hkaSplineCompressedAnimation_initialize(const Se31d50_Raw& raw, const Se31d50_PerTrack& trackParams,
                                const Se31d50_AnimParams& animationParams)
{
    m_iEndian = 0;
    m_type = Se31d50_SPLINE;
    m_iMaxFramesPerBlock = animationParams.m_iMaxFramesPerBlock;
    hkBool enableSampleSingleTracks = animationParams.m_bEnableSampleSingleTracks;
    m_iFrameCount = raw.GetIntegerValue();
    m_iBlockCount = Se31d50_max2(1, (m_iFrameCount + m_iMaxFramesPerBlock - 3) / (m_iMaxFramesPerBlock - 1));
    m_fBlockDuration = m_fAnimationDuration / (m_iFrameCount - 1) * (m_iMaxFramesPerBlock - 1);
    m_fBlockInverseDuration = 1.0f / m_fBlockDuration;
    m_fPerFrameDuration = m_fAnimationDuration / (m_iFrameCount - 1);
    int f = 0;
    m_iMaskAndQuantizationSize = (4 * m_iNumTransformTracks + m_iNumberOfFloatTracks + 3) & ~3;
    for (int i = 0; i < m_iBlockCount; i++)
    {
        m_kFirstUInt32Array.AddBack(m_kCompressedData.GetLogicalSize());
        const int nf = Se31d50_min2(m_iMaxFramesPerBlock, m_iFrameCount - f);
        const float blockDuration = m_fAnimationDuration / (m_iFrameCount - 1) * (nf - 1);
        int maskPos = m_kCompressedData.GetLogicalSize();
        hkaSplineCompressedAnimation_writeZeros(m_iMaskAndQuantizationSize, m_kCompressedData);
        for (int isFloat = 0; isFloat < 2; isFloat++)
        {
            const int numTracks = (isFloat == 0) ? m_iNumTransformTracks : m_iNumberOfFloatTracks;
            const int numComponents = (isFloat == 0) ? 3 : 1;
            if (isFloat == 1)
            {
                m_kFloatBlockOffsets.AddBack(m_kCompressedData.GetLogicalSize() - m_kFirstUInt32Array[i]);
            }
            for (int t = 0; t < numTracks; t++)
            {
                if (enableSampleSingleTracks)
                {
                    if (isFloat == 0)
                    {
                        m_kTransformOffsets.AddBack(m_kCompressedData.GetLogicalSize() - m_kFirstUInt32Array[i]);
                    }
                    else
                    {
                        m_kFloatOffsets.AddBack(m_kCompressedData.GetLogicalSize() - m_kFirstUInt32Array[i]);
                    }
                }
                const Se31d50_TrackParams& params =
                    trackParams.m_kTrackParams[(isFloat == 0) ? trackParams.m_kFirstIntArray[t]
                                                              : trackParams.m_kSecondIntArray[t]];
                Se31d50_VecArr data[3];
                Se31d50_VecArr* pData = data;
                int n = 2;
                do
                {
                    pData->init();
                    ++pData;
                } while (--n >= 0);
                Se31d50_FltArr U[3];
                Se31d50_FltArr* pU = U;
                n = 2;
                do
                {
                    pU->init();
                    ++pU;
                } while (--n >= 0);
                for (int c = 0; c < numComponents; c++)
                {
                    data[c].SetSizeAndGrow(nf);
                    U[c].SetSizeAndGrow(nf);
                    FillInterpolatedValues(nf - 1, U[c], 0.0f, blockDuration);
                }
                int degree[3];
                float tolerance[3];
                if (isFloat == 0)
                {
                    degree[0] = params.m_iTranslationDegree;
                    degree[1] = params.m_iRotationDegree;
                    degree[2] = params.m_iScaleDegree;
                    tolerance[0] = params.m_fTranslationTolerance;
                    tolerance[1] = params.m_fRotationTolerance;
                    tolerance[2] = params.m_fScaleTolerance;
                }
                else
                {
                    degree[0] = params.m_iFloatingDegree;
                    tolerance[0] = params.m_fFloatingTolerance;
                }
                if (isFloat == 0)
                {
                    hkVector4_ProcessEntries_00e310c0(raw.m_kTransforms.begin(), m_iNumTransformTracks, nf, f, t, data[0], data[1], data[2]);
                }
                else
                {
                    Object_ProcessEntries_00e31180(raw.m_kFloats.begin(), m_iNumberOfFloatTracks, nf, f, t, data[0]);
                }
                for (int c = 0; c < numComponents; c++)
                {
                    hkVector4 mean = Runtime_ProcessEntries_00e31410(data[c]);
                    hkVector4 minV = hkArrayBase_ProcessEntries_00e31470(data[c]);
                    hkVector4 maxV = hkArrayBase_ProcessEntries_00e314c0(data[c]);
                    if (c == 1)
                    {
                        mean.normalize4();
                    }
                    hkVector4 identity[3];
                    identity[0].set(0.0f, 0.0f, 0.0f, 0.0f);
                    identity[1].set(0.0f, 0.0f, 0.0f, 1.0f);
                    identity[2].set(1.0f, 1.0f, 1.0f, 0.0f);
                    unsigned char mask = hkaSplineCompressedAnimation_isStatic(mean, minV, maxV, tolerance[c], identity[c]);
                    if (isFloat == 1 && mask == 0)
                    {
                        mask = 1;
                    }
                    if (isFloat == 0)
                    {
                        if (c == 0)
                        {
                            m_kCompressedData[maskPos] =
                                PackBitFields(params.m_eTranslationQuantizationType, params.m_eRotationQuantizationType,
                                             params.m_eScaleQuantizationType);
                            maskPos++;
                        }
                        m_kCompressedData[maskPos] = mask;
                        maskPos++;
                    }
                    else
                    {
                        m_kCompressedData[maskPos] = hkaSplineCompressedAnimation_packMaskAndQuantizationType(mask, params.m_eFloatQuantizationType);
                        maskPos++;
                    }
                    Se31d50_VecArr controlPoints(nf * 3);
                    Se31d50_FltArr knots(nf * 3 + 2);
                    if (mask & 0xf0)
                    {
                        int numKnots;
                        int numControlPoints;
                        _ApproximateNURBSCurve(nf, U[c].begin(), data[c].begin(), degree[c], tolerance[c], &numKnots,
                                     knots.begin(), &numControlPoints, controlPoints.begin());
                        knots.SetSizeAndGrow(numKnots);
                        controlPoints.SetSizeAndGrow(numControlPoints);
                        if (controlPoints.GetLogicalSize() > nf)
                        {
                            degree[c] = 1;
                            _ApproximateNURBSCurve(nf, U[c].begin(), data[c].begin(), degree[c], tolerance[c], &numKnots,
                                         knots.begin(), &numControlPoints, controlPoints.begin());
                            knots.SetSizeAndGrow(numKnots);
                            controlPoints.SetSizeAndGrow(numControlPoints);
                        }
                        AppendScaledValues(controlPoints.GetLogicalSize() - 1,
                                     knots.GetLogicalSize() - controlPoints.GetLogicalSize() - 1, knots);
                    }
                    if (c == 1)
                    {
                        ProcessEntries_00e319e0(mask, params.m_eRotationQuantizationType, mean, controlPoints.GetLogicalSize() - 1,
                                     controlPoints);
                    }
                    else
                    {
                        if (mask & 0xf0)
                        {
                            minV = hkArrayBase_ProcessEntries_00e31470(controlPoints);
                            maxV = hkArrayBase_ProcessEntries_00e314c0(controlPoints);
                        }
                        WriteCompressedAnimation(mask,
                                                 (isFloat == 0)
                                                     ? (Se31d50_ScalQ)((c == 0) ? params.m_eTranslationQuantizationType
                                                                                : params.m_eScaleQuantizationType)
                                                     : (Se31d50_ScalQ)params.m_eFloatQuantizationType,
                                                 mean, minV, maxV, controlPoints.GetLogicalSize() - 1, controlPoints);
                    }
                    hkaSplineCompressedAnimation_writeAlign(4, m_kCompressedData);
                }
            }
        }
        f += nf - 1;
        hkaSplineCompressedAnimation_writeAlign(16, m_kCompressedData);
    }
    DAT_01268360->beginSection(0x36118e94, str_010eb4c8);
    {
        char reportBuf[512];
        Se31d50_ErrStream ostr(reportBuf, sizeof(reportBuf));
        ostr.ProcessAndReturnValue_00cc01c0(str_010eb4b4).WriteInt(m_iBlockCount);
        DAT_01268360->message(0, -1, reportBuf, str_010eb470, 366);
    }
    {
        char reportBuf[512];
        Se31d50_ErrStream ostr(reportBuf, sizeof(reportBuf));
        ostr.ProcessAndReturnValue_00cc01c0(str_010eb444).WriteInt(GetValueAt2C()).ProcessAndReturnValue_00cc01c0(str_010eb468);
        DAT_01268360->message(0, -1, reportBuf, str_010eb470, 367);
    }
    const unsigned int originalSize =
        raw.m_kTransforms.GetLogicalSize() * sizeof(float) * 16 + raw.m_kFloats.GetLogicalSize() * sizeof(float);
    {
        char reportBuf[512];
        Se31d50_ErrStream ostr(reportBuf, sizeof(reportBuf));
        ostr.ProcessAndReturnValue_00cc01c0(str_010eb418)
            .EvaluateValue_00cc02d0(originalSize)
            .ProcessAndReturnValue_00cc01c0(str_010eb428)
            .WriteInt(getSizeInBytes())
            .ProcessAndReturnValue_00cc01c0(str_010eb468);
        DAT_01268360->message(0, -1, reportBuf, str_010eb470, 372);
    }
    {
        char reportBuf[512];
        Se31d50_ErrStream ostr(reportBuf, sizeof(reportBuf));
        ostr.ProcessAndReturnValue_00cc01c0(str_010eb400).WriteFloat((float)originalSize / getSizeInBytes()).ProcessAndReturnValue_00cc01c0(str_010eb414);
        DAT_01268360->message(0, -1, reportBuf, str_010eb470, 373);
    }
    DAT_01268360->endSection();
}
