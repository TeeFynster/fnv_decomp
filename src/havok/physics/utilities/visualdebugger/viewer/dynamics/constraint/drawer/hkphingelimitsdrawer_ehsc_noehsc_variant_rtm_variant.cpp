#define FNV64_HKENUM_INLINE_BODIES
// VC9's CRT SIMD union contains byte arrays which introduce /GS cookies.
// Use the original intrinsic representation while consuming the shared game types.
#define _INCLUDED_MM2
// Exe 0x00de5fe0 @FUN_00de5fe0@24: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct { float x, y, z, w; } lanes;
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_load_ss(const float*);
}

#include "../../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../../../include/hkColor.h"
#include "../../../../../../../../../include/hkDebugDisplayHandler.h"
#include "../../../../../../../../../include/hkDisplayGeometry.h"
#include "../../../../../../../../../include/hkDisplaySemiCircle.h"
#include "../../../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../../include/hkTransform.h"
#include "../../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../../../../include/hkpHingeLimitsData.h"
#include "../../../../../../../../../include/hkpSetLocalRotationsConstraintAtom.h"
#include "../../../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../../include/hkBool.h"
#include "../../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../../include/hkpConstraintAtom.h"
#include "../../../../../../../../../include/hkpConstraintData.h"


// Keep the original inline behavior with the shared class declarations.

template <typename TYPE> inline void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
    bufFree(p, numElem * sizeof(TYPE));
}

inline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x)
{}
inline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}
inline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
inline const LocalM128& hkSimdReal::getQuad() const
{
    return m_vValue;
}
inline hkTransform::hkTransform()
{}

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef signed long __w64 hkLong;
#include "../../../../../../../../../include/hkResult.h"
typedef unsigned __w64 hk_size_t;
__forceinline hkLong __cdecl hkGetByteOffset(const void* base, const void* pntr)
{
    return hkLong(pntr) - hkLong(base);
}
__forceinline int __cdecl hkGetByteOffsetInt(const void* base, const void* pntr)
{
    return static_cast<int>(hkGetByteOffset(base, pntr));
}

#include "../../../../../../../../../include/hkEnum.h"
using ::hkEnum;
template <typename T> struct TypeSizeConstant
{
    enum
    {
        val = sizeof(T)
    };
};
#include "../../../../../../../../../include/hkArray.h"
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}
template <typename T> __forceinline void hkArrayUtil::destruct(T* t, int n, hkTypeIsPod)
{}
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil::_reserve(alloc, this, newSize, sizeof(T));
    }
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    hkArrayUtil::destruct(m_data, m_iElementCount, typename IsPodType<T>::type());
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
    {
        alloc._bufFree<T>(m_data, getCapacity());
    }
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}
typedef LocalM128 hkQuadReal;
typedef const hkSimdReal& hkSimdRealParameter;
__forceinline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
__forceinline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
static __forceinline hkSimdReal lengthInverse3(const hkVector4& vector)
{
    const hkQuadReal half = _mm_set_ss(0.5f);
    const hkQuadReal three = _mm_set_ss(3.0f);
    const hkQuadReal zero = _mm_set_ss(0.0f);
    const hkQuadReal len2 = vector.dot3(vector).getQuad();
    const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const hkQuadReal approx = _mm_rsqrt_ss(len2);
    const hkQuadReal refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}
__forceinline void hkVector4::normalize3()
{
    hkQuadReal lenInv = lengthInverse3(*this).broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
}
extern "C" hkVector4 DAT_01267e30;
inline const hkVector4& __cdecl hkVector4::getZero()
{

    return DAT_01267e30;
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
inline const hkVector4& hkRotation::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}

struct GenericConstraintAtomScheme
{
};
inline const hkpConstraintData* hkpConstraintInstance::getData() const
{
    return m_data;
}
class DebugDisplayHandlerHolder
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  protected:
    hkDebugDisplayHandler* m_pDisplayHandler;

  public:
    DebugDisplayHandlerHolder();
    void hkpPrimitiveDrawer_setDisplayHandler(hkDebugDisplayHandler* displayHandler);
};
class ConstraintDrawer
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  protected:
    void hkpConstraintDrawer_drawPivots(int id, int tag);
    void hkpConstraintDrawer_drawBodyFrames(int id, int tag);
    void hkpConstraintDrawer_updateCommonParameters(const hkpConstraintInstance* constraint, hkTransform& refLocalToWorld,
                      hkTransform& attLocalToWorld);

  private:
    hkReal m_fLineLength;
    hkReal m_fArcRadius;
    hkReal m_fConeAngle;
    hkReal m_fPlaneAngle;
    hkReal m_fPlaneRadius;
    hkReal m_iPlaneCount;
    int m_iArcSegmentCount;
    hkReal m_vScale;

  protected:
    hkReal getLineLengthForDraw()
    {
        return m_vScale * m_fLineLength;
    }
    hkReal getArcRadiusForDraw()
    {
        return m_vScale * m_fArcRadius;
    }
    int getNumArcSegmentsForDraw()
    {
        return m_iArcSegmentCount;
    }

  protected:
    hkVector4 m_vFirstConstraintPivot;
    hkVector4 m_vSecondConstraintPivot;
    hkVector4 m_vVectorAtOffset40;
    hkVector4 m_vVectorAtOffset50;
    hkRotation m_kFirstRotation;
    hkRotation m_kSecondRotation;
    DebugDisplayHandlerHolder m_kDisplayGeometry;
};
class HingeConstraintDrawer : public ConstraintDrawer
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void __cdecl operator delete(void* p)
    {
        if (p)
        {
            ;
            hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(HingeConstraintDrawer));
        }
    }
    __forceinline void* __cdecl operator new(hk_size_t n, void* p)
    {
        ;
        return p;
    }
    __forceinline void* __cdecl operator new[](hk_size_t, void* p)
    {
        return p;
    }
    __forceinline void __cdecl operator delete(void*, void*)
    {}
    __forceinline void __cdecl operator delete[](void*, void*)
    {}
    class CommandArgument;
    __forceinline void drawHinge(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int id,
                                 int tag);

  protected:
    hkDisplaySemiCircle m_fAngularLimit;
};
inline hkReal hkpHingeLimitsData::getMaxAngularLimit() const
{
    return m_kBridgeAtoms.m_kAngularLimit.m_fMaxAngle;
}
inline hkReal hkpHingeLimitsData::getMinAngularLimit() const
{
    return m_kBridgeAtoms.m_kAngularLimit.m_fMinAngle;
}
__forceinline void HingeConstraintDrawer::drawHinge(hkpConstraintInstance* constraint,
                                                    hkDebugDisplayHandler* displayHandler, int id, int tag)
{
    const hkpHingeLimitsData* lhinge = static_cast<const hkpHingeLimitsData*>(constraint->getData());
    m_kDisplayGeometry.hkpPrimitiveDrawer_setDisplayHandler(displayHandler);
    hkTransform refLocalToWorld;
    hkTransform attLocalToWorld;
    hkpConstraintDrawer_updateCommonParameters(constraint, refLocalToWorld, attLocalToWorld);
    m_vVectorAtOffset50.setTransformedPos_00c7f640(refLocalToWorld, hkVector4::getZero());
    m_vVectorAtOffset40.setTransformedPos_00c7f640(attLocalToWorld, hkVector4::getZero());
    hkpConstraintDrawer_drawBodyFrames(id, tag);
    hkpConstraintDrawer_drawPivots(id, tag);
    const hkVector4* baseA = &lhinge->m_kBridgeAtoms.m_kLocalRotations.m_kRotationA.getColumn(0);
    const hkVector4* baseB = &lhinge->m_kBridgeAtoms.m_kLocalRotations.m_kRotationB.getColumn(0);
    hkVector4 axisInWorld;
    axisInWorld.hkVector4_setRotatedDir(m_kSecondRotation, baseB[0]);
    hkVector4 axisPerpInWorld;
    axisPerpInWorld.hkVector4_setRotatedDir(m_kSecondRotation, baseB[2]);
    displayHandler->DisplayLine(m_vVectorAtOffset40, m_vVectorAtOffset50, hkColor::RED, id, tag);
    {
        hkVector4 startAxis, endAxis;
        endAxis.setMul4(hkSimdReal(getLineLengthForDraw() * 0.75), axisInWorld);
        endAxis.add4(m_vVectorAtOffset50);
        startAxis.setMul4(hkSimdReal(getLineLengthForDraw() * -0.75), axisInWorld);
        startAxis.add4(m_vVectorAtOffset50);
        displayHandler->DisplayLine(startAxis, endAxis, hkColor::PackColorBigEndian(0.f, .5f, 1.f, 1.f), id, tag);
    }
    {
        hkReal thetaMax = lhinge->getMaxAngularLimit();
        hkReal thetaMin = lhinge->getMinAngularLimit();
        m_fAngularLimit.UpdateState_00de4950(getArcRadiusForDraw(), thetaMin, thetaMax, getNumArcSegmentsForDraw(),
                                     m_vVectorAtOffset50, axisInWorld, axisPerpInWorld);
        hkArray<hkDisplayGeometry*> geometry;
        geometry.setSize(1);
        geometry[0] = &m_fAngularLimit;
        displayHandler->DisplayGeometryList(geometry, hkColor::WHITE, id, tag);
    }
    {
        hkVector4 start;
        hkVector4 end;
        start = m_vVectorAtOffset50;
        end = start;
        end.addMul4(hkSimdReal(getLineLengthForDraw() * 0.75), axisPerpInWorld);
        displayHandler->DisplayLine(start, end, hkColor::YELLOW, id, tag);
        hkVector4 axisPerpA;
        axisPerpA.hkVector4_setRotatedDir(m_kFirstRotation, baseA[2]);
        axisPerpA.normalize3();
        start = m_vVectorAtOffset40;
        end = start;
        end.addMul4(hkSimdReal(getLineLengthForDraw() * 0.5), axisPerpA);
        displayHandler->DisplayLine(start, end, hkColor::YELLOW, id, tag);
    }
}
// @fnv 0x00de5fe0
// src: GUESS 0x00de5fe0 (confidence: medium)
extern "C" __declspec(noinline) void __fastcall hkpConstraintInstance_DrawHinge_Thunk(HingeConstraintDrawer* drawer, void*,
                                                             hkpConstraintInstance* constraint,
                                                             hkDebugDisplayHandler* handler, int id, int tag)
{
    drawer->drawHinge(constraint, handler, id, tag);
}
