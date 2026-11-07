
// src/havok/common/internal/misc/hksystemtime_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/misc/hksystemtime.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/internal/misc/hksystemtime.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/misc/hksystemtime.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" __int64 __cdecl __time64(__int64*);
int Hksystemtime_Time64_Thunk(void);

#include <math.h>
__if_not_exists(__m128)
{
    
// Exe 0x00e29cd0 _FUN_00e29cd0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
        float m128_f32[4];
        unsigned __int64 m128_u64[2];
    } __m128, LocalM128;
}
extern "C"
{
    __if_not_exists(_mm_load_ss)
    {
        LocalM128 _mm_load_ss(const float* p);
    }
    __if_not_exists(_mm_sub_ps)
    {
        LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    }
    __if_not_exists(_mm_mul_ps)
    {
        LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
    }
    __if_not_exists(_mm_add_ss)
    {
        LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
    }
    __if_not_exists(_mm_mul_ss)
    {
        LocalM128 _mm_mul_ss(LocalM128 a, LocalM128 b);
    }
    __if_not_exists(_mm_rsqrt_ss)
    {
        LocalM128 _mm_rsqrt_ss(LocalM128 a);
    }
    __if_not_exists(_mm_shuffle_ps)
    {
        LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
    }
    __if_not_exists(_mm_store_ss)
    {
        void _mm_store_ss(float* p, LocalM128 a);
    }
}
typedef float S29cd0_hkReal;
typedef LocalM128 S29cd0_hkQuadReal;

class S29cd0_hkSimdReal
{
  public:
    __forceinline S29cd0_hkSimdReal(const S29cd0_hkQuadReal& x) : m_vValue(x)
    {}
    __forceinline S29cd0_hkSimdReal(S29cd0_hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline S29cd0_hkSimdReal()
    {}
    __forceinline operator S29cd0_hkReal() const
    {
        S29cd0_hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline S29cd0_hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const S29cd0_hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    S29cd0_hkQuadReal m_vValue;
};
typedef const S29cd0_hkSimdReal& S29cd0_hkSimdRealParameter;
__forceinline S29cd0_hkSimdReal operator*(S29cd0_hkSimdRealParameter r, S29cd0_hkSimdRealParameter s)
{
    return _mm_mul_ss(r.getQuad(), s.getQuad());
}

class S29cd0_hkVector4
{
  public:
    __forceinline void operator=(const S29cd0_hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setSub4(const S29cd0_hkVector4& v0, const S29cd0_hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline S29cd0_hkSimdReal dot3(const S29cd0_hkVector4& a) const
    {
        S29cd0_hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        S29cd0_hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline void fastNormalize3()
    {
        S29cd0_hkQuadReal len2 = this->dot3(*this).getQuad();
        S29cd0_hkSimdReal approx = _mm_rsqrt_ss(len2);
        m_vComponents = _mm_mul_ps(m_vComponents, approx.broadcast());
    }
    __forceinline S29cd0_hkSimdReal fastNormalizeWithLength3()
    {
        S29cd0_hkQuadReal len2 = this->dot3(*this).getQuad();
        S29cd0_hkQuadReal approx = _mm_rsqrt_ss(len2);
        approx = _mm_shuffle_ps(approx, approx, 0);
        m_vComponents = _mm_mul_ps(m_vComponents, approx);
        return _mm_mul_ss(len2, approx);
    }
    S29cd0_hkQuadReal m_vComponents;
};

class S29cd0_hkBool
{
  public:
    __forceinline S29cd0_hkBool()
    {}
    __forceinline S29cd0_hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    __forceinline S29cd0_hkBool& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }
    char m_cBooleanValue;
};

class S29cd0_hkMemoryAllocator
{
  public:
    virtual ~S29cd0_hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename TYPE> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(TYPE);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};

class S29cd0_hkStackMemory
{
  public:
    __forceinline void* allocateStack(int numBytes, const char* what)
    {
        void* current = m_next;
        m_next = (char*)current + numBytes;
        return current;
    }
    __forceinline void deallocateStack(void* p)
    {
        m_next = p;
    }
    void* m_next;
    void* m_kRayStart;
    void* m_kRayEnd;
};

class S29cd0_hkMemoryRouter
{
  public:
    __forceinline S29cd0_hkStackMemory& stack()
    {
        return m_aiEntries;
    }
    __forceinline S29cd0_hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    S29cd0_hkStackMemory m_aiEntries;
    S29cd0_hkMemoryAllocator* m_pTemp;
    S29cd0_hkMemoryAllocator* m_pStreamAllocator;
};
extern "C" S29cd0_hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

template <typename TYPE> __forceinline TYPE* S29cd0_hkAllocateStack(int n, const char* what = 0)
{
    S29cd0_hkMemoryRouter& mem = *hkMemoryRouter_getInstance();
    return static_cast<TYPE*>(mem.stack().allocateStack((n * sizeof(TYPE) + 127) & ~127, what));
}
template <typename TYPE> __forceinline void S29cd0_hkDeallocateStack(TYPE* ptr)
{
    hkMemoryRouter_getInstance()->stack().deallocateStack(static_cast<void*>(ptr));
}

struct S29cd0_hkContainerHeapAllocator
{
    __forceinline S29cd0_hkMemoryAllocator& get(const void*)
    {
        return hkMemoryRouter_getInstance()->heap();
    }
};

template <typename T> class S29cd0_hkArrayBase
{ // local form of hkArrayBase: 0x00e29cd0 needs inline element destruction/copy and S29cd0_hkMemoryAllocator buffer-free ABI for its stack-array cleanup.
  public:
    enum
    {
        CAPACITY_MASK = 0x3FFFFFFF,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    __forceinline S29cd0_hkArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
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
    __forceinline void clear()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            static_cast<T*>(m_data)[i].~T();
        }
        m_iElementCount = 0;
    }
    __forceinline void pushBackUnchecked(const T& t)
    {
        for (int i = 0; i < 1; ++i)
        {
            new (static_cast<void*>(m_data + m_iElementCount + i)) T(t);
        }
        m_iElementCount++;
    }
    __forceinline void _clearAndDeallocate(S29cd0_hkMemoryAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T, typename Allocator = S29cd0_hkContainerHeapAllocator>
class S29cd0_hkArray : public S29cd0_hkArrayBase<T>
{
  public:
    typedef Allocator AllocatorType;
    __forceinline S29cd0_hkArray() : S29cd0_hkArrayBase<T>()
    {}
    __forceinline ~S29cd0_hkArray()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        S29cd0_hkArrayBase<T>::_clearAndDeallocate(AllocatorType().get(this));
    }
};

template <typename T> class S29cd0_hkLocalArray : public S29cd0_hkArray<T>
{
  public:
    __forceinline S29cd0_hkLocalArray(int capacity)
    {
        this->m_data = S29cd0_hkAllocateStack<T>(capacity);
        this->m_iCapacityState = capacity | S29cd0_hkArray<T>::DONT_DEALLOCATE_FLAG;
        m_pStackAllocation = this->m_data;
    }
    __forceinline S29cd0_hkBool wasReallocated() const
    {
        return m_pStackAllocation != this->m_data;
    }
    __forceinline ~S29cd0_hkLocalArray()
    {
        if (!wasReallocated())
        {
            S29cd0_hkArray<T>::clear();
        }
        S29cd0_hkDeallocateStack<T>(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

struct S29cd0_int4
{
    __forceinline static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    __forceinline static void operator delete(void*, void*)
    {}
    __forceinline S29cd0_int4()
    {
        for (int i = 0; i < 4; i++)
            m_ppIndices[i] = 0;
        m_iFirstInteger = 0;
    }
    __forceinline int& operator[](int i)
    {
        return m_ppIndices[i];
    }
    __forceinline const int& operator[](int i) const
    {
        return m_ppIndices[i];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iFirstInteger;
    }
    __forceinline bool isFull() const
    {
        return m_iFirstInteger >= 4;
    }
    __forceinline void AddBack(int a)
    {
        m_ppIndices[m_iFirstInteger] = a;
        m_iFirstInteger++;
    }
    int m_ppIndices[4];
    int m_iFirstInteger;
};

struct S29cd0_hkpShapeRayCastCollectorOutput
{
    S29cd0_hkVector4 m_vHitNormal;
    S29cd0_hkReal m_fHitFraction;
    int m_iExtraInfo;
    int m_unk18;
    int m_unk1c;
};
struct S29cd0_hkpShapeRayCastOutput : public S29cd0_hkpShapeRayCastCollectorOutput
{
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};
struct S29cd0_hkpWorldRayCastOutput : public S29cd0_hkpShapeRayCastOutput
{
    const void* m_pRootCollidable;
};
struct S29cd0_hkpWorldRayCastInput
{
    S29cd0_hkVector4 m_vFrom;
    S29cd0_hkVector4 m_vTo;
    S29cd0_hkBool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};
struct S29cd0_hkpWorldRayCastCommand
{
    S29cd0_hkpWorldRayCastInput m_kRayCastQuery;
    S29cd0_hkpWorldRayCastOutput* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    S29cd0_hkBool m_bResultFlag;
    S29cd0_hkBool m_bUseCollector;
};
struct S29cd0_hkpWorldRayCastBundleCommand
{
    S29cd0_hkpWorldRayCastInput m_kRayCastQuery[4];
    int m_iRayCount;
    S29cd0_hkBool m_bUseCollector;
    S29cd0_hkpWorldRayCastOutput* m_pResultBuffer[4];
    __declspec(align(16)) int m_iResultCapacity[4];
    S29cd0_hkBool m_bResultFlag;
};

// src: GUESS 0x00e29a10 (confidence: low)
__declspec(noinline) void Runtime_ProcessEntries_00e29a10(const S29cd0_hkLocalArray<S29cd0_int4>& clusters,
                                       const S29cd0_hkVector4* rayFrom, const S29cd0_hkVector4* rayTo,
                                       S29cd0_hkpWorldRayCastOutput* resultBuffer,
                                       S29cd0_hkpWorldRayCastCommand* singleCommandsOut, int& numSingleCommandsOut,
                                       S29cd0_hkpWorldRayCastBundleCommand* bundledCommandsOut,
                                       int& numBundledCommandsOut)
{
    S29cd0_hkpWorldRayCastOutput* output = resultBuffer;
    int numSingle = 0;
    int numBundled = 0;
    S29cd0_hkpWorldRayCastCommand* single = singleCommandsOut;
    S29cd0_hkpWorldRayCastBundleCommand* bundle = bundledCommandsOut;
    int numClusters = clusters.GetLogicalSize();
    for (int i = 0; i < numClusters; i++)
    {
        const S29cd0_int4& cluster = clusters[i];
        if (cluster.GetLogicalSize() == 1)
        {
            int rayIdx = cluster[0];
            single->m_kRayCastQuery.m_vFrom = rayFrom[rayIdx];
            single->m_kRayCastQuery.m_vTo = rayTo[rayIdx];
            single->m_kRayCastQuery.m_uiFilterInfo = 0;
            single->m_kRayCastQuery.m_bEnableShapeCollectionFilter = false;
            single->m_pResultBuffer = output + rayIdx;
            single->m_iResultCount = 1;
            single->m_iResultCapacity = 0;
            single->m_bUseCollector = false;
            single++;
            numSingle++;
        }
        else
        {
            int numActiveRays = cluster.GetLogicalSize();
            for (int j = 0; j < numActiveRays; j++)
            {
                int rayIdx = cluster[j];
                bundle->m_kRayCastQuery[j].m_vFrom = rayFrom[rayIdx];
                bundle->m_kRayCastQuery[j].m_vTo = rayTo[rayIdx];
                bundle->m_kRayCastQuery[j].m_uiFilterInfo = 0;
                bundle->m_kRayCastQuery[j].m_bEnableShapeCollectionFilter = false;
                bundle->m_pResultBuffer[j] = output + rayIdx;
                bundle->m_iResultCapacity[j] = 0;
            }
            bundle->m_iRayCount = numActiveRays;
            bundle->m_bUseCollector = false;
            bundle++;
            numBundled++;
        }
    }
    numSingleCommandsOut = numSingle;
    numBundledCommandsOut = numBundled;
}

// src: GUESS 0x00e29920 (confidence: low)
__declspec(noinline) bool Object_ProcessAndReturnValue_00e29920(const S29cd0_hkVector4& points00, const S29cd0_hkVector4& points01,
                                       const S29cd0_hkVector4& rayVector0, const S29cd0_hkVector4& points10,
                                       const S29cd0_hkVector4& points11, const S29cd0_hkVector4& rayVector1,
                                       S29cd0_hkReal angleAllowance, S29cd0_hkReal distanceAllowance)
{
    S29cd0_hkSimdReal cosAngle = rayVector0.dot3(rayVector1);
    if (cosAngle < angleAllowance)
        return false;
    S29cd0_hkSimdReal allowance = distanceAllowance;
    S29cd0_hkVector4 d0;
    d0.setSub4(points10, points00);
    S29cd0_hkVector4 d1;
    d1.setSub4(points11, points01);
    S29cd0_hkSimdReal dist;
    dist = d0.dot3(d0);
    if (dist > allowance)
        return false;
    dist = d1.dot3(d1);
    if (dist > allowance)
        return false;
    return true;
}

// @fnv 0x00e29cd0
// src: XBOX_PDB 0x00e29cd0
extern "C" void __cdecl hkTreeBundleRayCastUtil_autoBundleFromList(int* indices, int numIndices, const S29cd0_hkVector4* rayFrom,
                                     const S29cd0_hkVector4* rayTo, int numRays, S29cd0_hkReal angleVariance,
                                     S29cd0_hkReal distanceVariance2, S29cd0_hkpWorldRayCastOutput* resultBuffer,
                                     S29cd0_hkpWorldRayCastCommand* singleCommandsOut, int& numSingleCommandsOut,
                                     S29cd0_hkpWorldRayCastBundleCommand* bundledCommandsOut,
                                     int& numBundledCommandsOut)
{
    const S29cd0_hkReal cosVariance = fabsf(cosf(angleVariance));
    S29cd0_hkLocalArray<S29cd0_int4> clusters(numIndices);
    int* ptr = indices;
    for (int i = 0; i < numIndices; i++)
    {
        int rayIdx = *ptr;
        ptr++;
        S29cd0_hkVector4 from = rayFrom[rayIdx];
        S29cd0_hkVector4 to = rayTo[rayIdx];
        S29cd0_hkVector4 dir;
        dir.setSub4(to, from);
        S29cd0_hkSimdReal len2 = powf(dir.fastNormalizeWithLength3(), 2.0f);
        for (int c = 0; c < clusters.GetLogicalSize(); c++)
        {
            S29cd0_int4& cluster = clusters[c];
            if (cluster.isFull())
                continue;
            for (int j = 0; j < 1; j++)
            {
                int other = cluster[j];
                S29cd0_hkVector4 from1 = rayFrom[other];
                S29cd0_hkVector4 to1 = rayTo[other];
                S29cd0_hkVector4 dir1;
                dir1.setSub4(to1, from1);
                dir1.fastNormalize3();
                if (Object_ProcessAndReturnValue_00e29920(from, to, dir, from1, to1, dir1, cosVariance,
                                 len2 * S29cd0_hkSimdReal(distanceVariance2)))
                {
                    cluster.AddBack(rayIdx);
                    goto NEXT_RAY;
                }
            }
        }
        {
            S29cd0_int4 newCluster;
            newCluster.AddBack(rayIdx);
            clusters.pushBackUnchecked(newCluster);
        }
    NEXT_RAY:;
    }
    Runtime_ProcessEntries_00e29a10(clusters, rayFrom, rayTo, resultBuffer, singleCommandsOut, numSingleCommandsOut, bundledCommandsOut,
                 numBundledCommandsOut);
}
