#include "../../../../../../../include/hkpBufferSize.h"
#include "../../../../../../../include/hkpAgentMachineMode.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include <xmmintrin.h>
#include "../../../../../../../include/AgentSectorPointerArray.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../include/Pair.h"
#include "../../../../../../../include/QuantizedFloat8.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkContactPointMaterial.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../include/hkSweptTransform.h"
#include "../../../../../../../include/hkpAgent1nSector.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../../include/hkpShapeContainer.h"

struct Out
{
    int res;
    int val;
};
struct Updater
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int update(int x, int y);
};
static void extractChildShapes_00da4a50(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y, Out* out2, Out* out1);
void S00da4a50_Wrap(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y, Out* out2, Out* out1);


extern unsigned long g_pMonitorStream;
__forceinline hkMonitorStream& hkMonitorStream::getInstance() { return *static_cast<hkMonitorStream*>(TlsGetValue(g_pMonitorStream)); }
__forceinline char* __cdecl hkMonitorStream::getStart() { return m_start.val(); }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable() { return getEnd() < getCapacityMinus16(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }

__forceinline hkpCdBody::hkpCdBody() {}
__forceinline hkpCdBody::hkpCdBody(const hkpCdBody* parent) { m_parent = parent; m_pMotionState = parent->m_pMotionState; }
__forceinline hkpCdBody::hkpCdBody(const hkpCdBody* parent, const void* motion) { m_parent = parent; m_pMotionState = motion; }
__forceinline const hkTransform& hkpCdBody::getTransform() const { return *static_cast<const hkTransform*>(m_pMotionState); }
__forceinline const hkMotionState* hkpCdBody::GetMotionState() const { return static_cast<const hkMotionState*>(m_pMotionState); }
__forceinline const hkpShape* hkpCdBody::getShape() const { return m_pCollisionShape; }
__forceinline unsigned int hkpCdBody::getShapeKey() const { return m_uiCollisionShapeKey; }
__forceinline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key) { m_pCollisionShape = shape; m_uiCollisionShapeKey = key; }
__forceinline hkpShapeType hkpShape::getType() const { return *reinterpret_cast<const hkpShapeType*>(&m_type); }
// ProcessAgent is the agent's seventh virtual slot; the shared header does not name it yet.
template <class Input, class Output>
static __forceinline void ProcessCollisionAgent(hkpCollisionAgent* agent, const hkpCdBody& a,
                                                const hkpCdBody& b, const Input& input, Output& output)
{
    typedef void (__thiscall* Process)(hkpCollisionAgent*, const hkpCdBody&, const hkpCdBody&, const Input&, Output&);
    reinterpret_cast<Process>((*reinterpret_cast<void* const* const*>(agent))[6])(agent, a, b, input, output);
}

// Inline implementations needed by the approved shared math declarations.
__forceinline hkVector4::hkVector4(const hkVector4& vector) : m_vComponents(vector.m_vComponents) {}
__forceinline hkSimdReal::hkSimdReal() {}
__forceinline hkSimdReal::hkSimdReal(float value)
{
    m_vValue = _mm_load_ss(&value);
}
__forceinline hkSimdReal::hkSimdReal(const __m128& value) : m_vValue(value) {}
__forceinline hkSimdReal::operator float() const
{
    float value;
    _mm_store_ss(&value, m_vValue);
    return value;
}
__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline QuantizedFloat8::QuantizedFloat8() {}
__forceinline hkTransform::hkTransform() {}
__forceinline hkQuaternion::hkQuaternion() {}
struct S00da4920_Sub
{
    void hkTransform_setInverse(void* arg);
};
struct S00da4920_Blob
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
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    __m128 m_v70;
};
extern char DAT_010c4c00;
static void hkAgent1nMachine_flipInput(S00da4920_Blob* src, S00da4920_Blob* dst);
void S00da4920_entry(S00da4920_Blob* src, S00da4920_Blob* dst);

// Keep the unit's scalar conversion path distinct from the shared monitor wrapper.
template <typename TYPE> class AgentValue
{
  public:
    __forceinline AgentValue()
    {}
    __forceinline AgentValue(TYPE e) : m_kStorage(e)
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
typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef signed long __w64 hkLong;
typedef unsigned __w64 Y2;
typedef hkReal hkTime;
__forceinline hkLong __cdecl hkGetByteOffset(const void* base, const void* pntr)
{
    return hkLong(pntr) - hkLong(base);
}
template <typename TYPE> __forceinline TYPE* __cdecl hkAddByteOffset(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

class hkClass;
typedef int hkBool32;

extern "C"
{
    extern const hkReal g_afRealLookupTable[256];
}


namespace MemoryUtilities {
void __cdecl CopyByteRange(void* dst, const void* src, int Y6);
}

class Y1
{
  public:
    __forceinline void* __cdecl operator new(Y2, void* p)
    {
        return p;
    }
    typedef hkMemoryAllocator Allocator;
    static Y1& __cdecl GetMonitorStream();
    inline Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    hkStackMemory m_aiEntries;
    Allocator* m_pTemp;
    Allocator* m_pStreamAllocator;
};
class hkStatisticsCollector;
#include "../../../../../../../include/hkArray.h"
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return Y1::GetMonitorStream().heap();
}
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
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T> __forceinline T* hkArrayBase<T>::_expandAt(hkMemoryAllocator& alloc, int index, int numtoinsert)
{
    const int newsize = numtoinsert + m_iElementCount;
    const int numtomove = m_iElementCount - index;
    if (newsize > getCapacity())
    {
        GrowArrayCapacity(alloc, newsize);
    }
    MemoryUtilities::CopyByteRange(m_data + index + numtoinsert, m_data + index, numtomove * sizeof(T));
    m_iElementCount = newsize;
    return m_data + index;
}
typedef __m128 hkQuadReal;
typedef const hkVector4& hkVector4Parameter;

typedef const hkSimdReal& hkSimdRealParameter;
namespace MathUtilities {
inline void prefetch128(const void* p)
{
    _mm_prefetch((const char*)p, 0);
}
template <int SIZE> inline void forcePrefetch(const void* p)
{
    const char* q = (const char*)p;
    _mm_prefetch(q, 0);
    if (SIZE > 64)
    {
        _mm_prefetch(q + 64, 0);
    }
    if (SIZE > 128)
    {
        _mm_prefetch(q + 128, 0);
    }
    if (SIZE > 192)
    {
        _mm_prefetch(q + 192, 0);
    }
}
}



// local form of hkRotation: 0x00da4aa0/0x00da5b80 need the unit hkMatrix3 base and inline router allocation without importing different SIMD overloads.
class __declspec(align(16)) RotationLocal_Agent1n : public hkMatrix3
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }
};
class AgentTransform
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }
    __forceinline AgentTransform()
    {}
    void SetConjugate(const AgentTransform& t);
    void SetMulInverse(const AgentTransform& bTa, const AgentTransform& bTc);

  private:
    RotationLocal_Agent1n m_rotation;
    hkVector4 m_vTranslation;
};
inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
    static __declspec(align(16)) const hkUint32 negateMask[4] = {0x80000000, 0x80000000, 0x80000000, 0x00000000};
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const hkQuadReal*)&negateMask);
}
inline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
inline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    hkQuadReal zwSum =
        _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))),
                   _mm_shuffle_ps(m_vComponents, m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3)))));
    return _mm_add_ps(xySum, zwSum);
}
inline hkReal& hkVector4::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
    if (i == 0)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    }
    else if (i == 3)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3))));
    }
}
__forceinline hkMatrix3::hkMatrix3() {}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
inline void hkMatrix3::operator=(const hkMatrix3& a)
{
    m_kColumn0 = a.getColumn(0);
    m_kColumn1 = a.getColumn(1);
    m_kColumn2 = a.getColumn(2);
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
    return m_vCenterOfMass1(3);
}
class MemoryUtils
{
  public:
    enum ReplaceType
    {
        REPLACE_ONE,
        REPLACE_ALL
    };
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);

  private:
    static void copyAndReplace(char* dest, const char* orig, int origLen, const MemoryUtils& from,
                               const MemoryUtils& to, const hkArray<int>& indices);
};
void __cdecl MemoryUtils::memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    {
        do
        {
            dst32[0] = src32[0];
            dst32[1] = src32[1];
            dst32[2] = src32[2];
            dst32[3] = src32[3];
            dst32 += 4;
            src32 += 4;
        } while (--numQuads > 0);
    }
}

inline hkMotionState::hkMotionState()
{}
inline const hkSweptTransform& hkMotionState::getSweptTransform() const
{
    return m_kSweptTransform;
}

typedef hkUint16 hkContactPointId;

inline hkVector4& hkContactPoint::getSeparatingNormal()
{
    return m_vSeparatingNormal;
}
inline void hkContactPoint::setFlipped(const hkContactPoint& point)
{
    hkVector4 dist;
    dist.setBroadcast(point.m_vSeparatingNormal, 3);
    m_vContactPosition.setAddMul4(point.m_vContactPosition, point.m_vSeparatingNormal, dist);
    m_vSeparatingNormal.setNeg3(point.m_vSeparatingNormal);
}
inline void hkContactPoint::flip()
{
    setFlipped(*this);
}

#include "../../../../../../../include/hkpBufferSize.h"
struct __declspec(align(16)) hkpShapeBuffer { char m_data[HK_SHAPE_BUFFER_SIZE]; };
typedef hkUint32 hkpShapeKey;
class ShapeKeyCombination
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }
    hkpShapeKey m_uiShapeKeyA;
    hkpShapeKey m_uiShapeKeyB;
};
class hkpConvexShape;

struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct CollisionAgentContext;
struct FourByteState
{
    hkUchar m_ucAgentType;
    hkUchar m_ucNnTrackType;
    hkUchar m_usNumContactPoints;
    hkUchar m_iElementCount;
};
typedef void Y3;
struct MachineAgentInputLocalForm
{ // local form of hkpAgent3Input: 0x00da5b80 needs the AgentValue/AgentTransform ctor and copy split; shared replacement compiles to 4599 bytes versus exe 4663.
    MachineAgentInputLocalForm() : m_pAdditionalCollidableBody(0)
    {}
    AgentValue<const hkpCdBody*> m_pBodyA;
    AgentValue<const hkpCdBody*> m_pBodyB;
    AgentValue<const hkpCdBody*> m_pAdditionalCollidableBody;
    AgentValue<const GskAgentInput*> m_pRayCastInput;
    AgentValue<hkpContactMgr*> m_pContactManager;
    AgentTransform m_kTransform;
};
struct AgentSubtypeMarker : public MachineAgentInputLocalForm
{
    AgentValue<hkReal> m_fSubtypeValue;
    hkVector4 m_vSubtypePosition;
};
namespace AgentCallbacks {
typedef int AgentType;
enum
{
    MIN_TOTAL_SIZE = 16,
    MAX_MEMORY_INCREASE = 80,
    MAX_TOTAL_SIZE = 128
};
enum StreamCommand
{
    STREAM_NULL = 0,
    STREAM_END = 1,
    STREAM_CALL = 2,
    STREAM_CALL_FLIPPED = 3,
    STREAM_CALL_WITH_TIM = 4,
    STREAM_CALL_WITH_TIM_FLIPPED = 5,
    STREAM_CALL_AGENT = 6,
    TRANSFORM_FLAG = 0x08,
    STREAM_CALL_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL,
    STREAM_CALL_FLIPPED_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_FLIPPED,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_WITH_TIM,
    STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_WITH_TIM_FLIPPED,
    STREAM_CALL_AGENT_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_AGENT,
};
typedef Y3*(__cdecl* CreateFunc)(const MachineAgentInputLocalForm& input, FourByteState* entry, Y3* agentData);
typedef void(__cdecl* DestroyFunc)(FourByteState* entry, Y3* agentData, hkpContactMgr* mgr,
                                   hkpConstraintOwner& constraintOwner, hkpCollisionDispatcher* dispatcher);
typedef Y3*(__cdecl* ProcessFunc)(const AgentSubtypeMarker& input, FourByteState* entry, Y3* agentData,
                                  hkVector4* separatingNormalOut, WorldOperationEntry& result);
enum Symmetric
{
    IS_SYMMETRIC,
    IS_NOT_SYMMETRIC,
    IS_NOT_SYMMETRIC_AND_FLIPPED
};
typedef void(__cdecl* SepNormalFunc)(const MachineAgentInputLocalForm& input, FourByteState* entry, Y3* agentData,
                                     hkVector4& separatingNormalOut);
typedef Y3*(__cdecl* CleanupFunc)(FourByteState* entry, Y3* agentData, hkpContactMgr* mgr,
                                  hkpConstraintOwner& constraintOwner);
typedef void(__cdecl* RemovePointFunc)(FourByteState* entry, Y3* agentData, hkContactPointId idToRemove);
typedef void(__cdecl* CommitPotentialFunc)(FourByteState* entry, Y3* agentData, hkContactPointId iContactPointId);
typedef void(__cdecl* CreateZombieFunc)(FourByteState* entry, Y3* agentData, hkContactPointId idTobecomeZombie);
typedef void(__cdecl* UpdateFilterFunc)(FourByteState* entry, Y3* agentData, const hkpCdBody& bodyA,
                                        const hkpCdBody& bodyB, const CollisionAgentContext& input, hkpContactMgr* mgr,
                                        hkpConstraintOwner& constraintOwner);
typedef void(__cdecl* CalcStatisticsFunc)(FourByteState* entry, Y3* agentData, const CollisionAgentContext& input,
                                          hkStatisticsCollector* collector);
typedef void(__cdecl* InvalidateTimFunc)(FourByteState* entry, Y3* agentData, const CollisionAgentContext& input);
typedef void(__cdecl* WarpTimeFunc)(FourByteState* entry, Y3* agentData, hkTime oldTime, hkTime newTime,
                                    const CollisionAgentContext& input);
}
struct AgentQualityInfo
{
    __declspec(align(16)) hkReal m_fMinimumCollisionSeparation;
    hkReal m_fMinimumExtraSeparation;
    hkReal m_fMaximumExtraSeparation;
    hkReal m_fTimeOfImpactSeparation;
    AgentValue<hkBool32> m_iQualityInfoValue10;
    hkBool m_bUseContinuousPhysics;
    hkReal m_fCreateContactThreshold;
};
class hkpConvexListFilter;
struct CollisionAgentContext
{
  public:
    hkReal getTolerance() const
    {
        return m_fScalar;
    }

  public:
    AgentValue<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    AgentValue<hkBool32> m_collisionQuality;
    AgentValue<hkReal> m_fScalar;
    AgentValue<const hkpCollisionFilter*> m_iFilter;
    AgentValue<const hkpConvexListFilter*> m_pConvexListCollisionFilter;
    mutable AgentValue<hkBool32> m_bCreatePredictiveAgents;
    struct AabbBoundsAndScale
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().blockFree(p, sizeof(CollisionAgentContext::AabbBoundsAndScale));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        hkVector4 m_kAabbMin;
        hkVector4 m_kAabbMaximum;
        hkVector4 m_kAabbScale;
    };
    AabbBoundsAndScale m_aiValues;
};
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;

static __forceinline AgentCallbacks::CreateFunc GetAgent3CreateFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<AgentCallbacks::CreateFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pCreateFunc);
}
static __forceinline AgentCallbacks::DestroyFunc GetAgent3DestroyFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<AgentCallbacks::DestroyFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pAgent3DestroyFuncs);
}
static __forceinline AgentCallbacks::CleanupFunc GetAgent3CleanupFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<AgentCallbacks::CleanupFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pAgentFunction3);
}
static __forceinline AgentCallbacks::ProcessFunc GetAgent3ProcessFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<AgentCallbacks::ProcessFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pAgentFunction8);
}
static __forceinline AgentCallbacks::SepNormalFunc GetAgent3SepNormalFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<AgentCallbacks::SepNormalFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pAgentFunction7);
}
static __forceinline AgentCallbacks::Symmetric GetAgent3Symmetric(hkpCollisionDispatcher* dispatcher, int type)
{
    return static_cast<AgentCallbacks::Symmetric>(dispatcher->m_kAgent3FunctionTable[type].m_eSymmetric);
}

__forceinline hkAgent3::AgentType hkpCollisionDispatcher::getAgent3Type(hkpShapeType typeA, hkpShapeType typeB, int predictive) const
{
    if (predictive) return m_ucAgent3TypeTable[typeA][typeB];
    return m_ucAgent2TypeTable[typeA][typeB];
}
class ContactImpulseInfo
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    hkReal m_fAccumulatedImpulse;
};

class PhysicsMaterial : public hkContactPointMaterial
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    hkReal m_uiUserData;
};
__declspec(align(16)) class ContactDataPhysicsMaterial : public PhysicsMaterial
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }
};
struct ContactPointWithId
{
    hkContactPoint m_kPoint;
    AgentValue<hkUint32> m_usContactPointId;
};

static __forceinline float GetStepTime(const hkPadSpu<float>& time)
{
    return time.val();
}

struct GskAgentInput : public CollisionAgentContext
{
  public:
    GskAgentInput() : m_pAgent1nSector(0)
    {}

  public:
    hkStepInfo m_pStepInfo;
    mutable AgentValue<AgentQualityInfo*> m_pCollisionQualityInfo;
    mutable hkpAgent1nSector* m_pAgent1nSector;
};
class ConvexFeaturePairCache
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    void init(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const AgentTransform& btoa);
    inline void flip();
};
__declspec(align(16)) class HeapContactFeatureCache : public ConvexFeaturePairCache
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }
};
enum
{
    HK_MAX_CONTACT_POINT = 256
};
struct CollisionContactResults
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    AgentValue<ContactPointWithId*> m_pAlignedPairData;
    AgentValue<hkpConstraintOwner*> m_pConstraintOwner;
    ContactPointWithId m_akContactPoints[HK_MAX_CONTACT_POINT];
    struct CollisionCacheState
    {
      public:
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().blockFree(p, sizeof(CollisionContactResults::CollisionCacheState));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        inline CollisionCacheState();
        inline void flip();

      public:
        hkContactPoint m_vContactPoint;
        AgentValue<hkReal> m_uiCommandId;
        AgentValue<hkReal> m_fSeparation;
        HeapContactFeatureCache m_kGskCache;
        ContactDataPhysicsMaterial m_kProperties;
    };
    struct CollisionCacheState m_fTimeOfImpact;
};
void CollisionContactResults::CollisionCacheState::flip()
{
    hkVector4& norm = m_vContactPoint.getSeparatingNormal();
    norm.setNeg3(norm);
    m_kGskCache.flip();
}
struct WorldOperationEntry : public CollisionContactResults
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    struct ContactPointAgentEntry
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().blockFree(p, sizeof(WorldOperationEntry::ContactPointAgentEntry));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        ContactPointWithId* m_vContactPoint;
        FourByteState* m_pAgentEntry;
        void* m_pUserData;
    };
    struct ContactPointBuffer
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().blockAlloc(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().blockFree(p, sizeof(WorldOperationEntry::ContactPointBuffer));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        void reset()
        {
            m_pFirstFreeContactPoint = &m_akContactRecords[0];
            m_ppFirstFreeContactPointer = &m_apContactPointPointers[0];
        }
        ContactPointAgentEntry* m_pFirstFreeContactPoint;
        ContactPointWithId** m_ppFirstFreeContactPointer;
        ContactPointWithId* m_apContactPointPointers[HK_MAX_CONTACT_POINT];
        ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
    };

  public:
    AgentValue<ContactPointBuffer*> m_akContactRecords;
};
extern hkMemoryAllocator::MemoryState g_eOutOfMemoryState;
__forceinline hkMemoryAllocator::MemoryState hkGetOutOfMemoryState()
{
    return g_eOutOfMemoryState;
}
__forceinline bool hkMemoryStateIsOutOfMemory(int id)
{
    bool lowOnMem = hkGetOutOfMemoryState() == hkMemoryAllocator::MEMORY_STATE_OUT_OF_MEMORY;
    return lowOnMem;
}
namespace MotionUtilities {
void __cdecl ComputeTransformAtTime(const hkSweptTransform& sweptTrans, hkTime time, AgentTransform& transformOut);
__forceinline void __cdecl calcTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                       hkVector4& timOut);
}
void __cdecl MotionUtilities::calcTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                          hkVector4& timOut)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();
    hkVector4 diff0;
    diff0.setSub4(st0.m_vCenterOfMass0, st0.m_vCenterOfMass1);
    hkVector4 diff1;
    diff1.setSub4(st1.m_vCenterOfMass1, st1.m_vCenterOfMass0);
    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();
    (timOut.*static_cast<void (hkVector4::*)(const hkSimdReal&, const hkVector4&)>(&hkVector4::setMul4))(f0, diff0);
    timOut.addMul4(f1, diff1);
    timOut(3) = f0 * ms0.m_kDeltaAngle(3) * ms0.m_fObjectRadius + f1 * ms1.m_kDeltaAngle(3) * ms1.m_fObjectRadius;
}
struct ShapeKeyAgentEntry : FourByteState
{
    ShapeKeyCombination m_kShapeKeyPair;
};
struct ByteStateWithThreeIntegers : ShapeKeyAgentEntry
{
    hkUint32 m_uiEntryValue;
};
struct ByteStateWithMixedNumericData : ShapeKeyAgentEntry
{
    hkTime m_fFloatValue;
    hkVector4 m_vSeparatingNormal;
};
struct EmptyMarker
{
};
typedef Y3* (*hkAgent1nMachine_VisitorCallback)(EmptyMarker& vin, ShapeKeyAgentEntry* entry, Y3* agentData);
extern "C"
{
    void __cdecl ResetAgentTrack(AgentSectorPointerArray& agentTrack);
    void __cdecl BuildShapeCollectionBWorldOperations(AgentSectorPointerArray& agentTrack,
                                                      const AgentSubtypeMarker& input,
                                                      const hkpShapeContainer* shapeContainterB,
                                                      const hkpShapeKey* hitList, WorldOperationEntry& output);
    void __cdecl UpdateAgentTrackShapeFilter(AgentSectorPointerArray& agentTrack, EmptyMarker& vin);
    void __cdecl hkAgentNmMachine_UpdateShapeCollectionFilter(AgentSectorPointerArray& agentTrack, EmptyMarker& vin);
    void __cdecl VisitTrackedAgents(AgentSectorPointerArray& agentTrack, EmptyMarker& vin, hkpContactMgr* mgr,
                                    hkAgent1nMachine_VisitorCallback visitor);
    void __cdecl DestroyAgentTrack(AgentSectorPointerArray& agentTrack, hkpCollisionDispatcher* dispatch,
                                   hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner);
    void __cdecl CollideTrackedAgents(AgentSectorPointerArray& track, const CollisionAgentContext& input);
    void __cdecl UpdateTrackedAgentTimes(AgentSectorPointerArray& track, hkTime oldTime, hkTime newTime,
                                         const CollisionAgentContext& input);
    void __cdecl ProcessShapeCollection(MachineAgentInputLocalForm& input, const hkpShapeContainer* shapeCollection,
                                        WorldOperationEntry& output);
    ShapeKeyAgentEntry* hkAgent1nMachine_FindAgent(AgentSectorPointerArray& agentTrack, ShapeKeyCombination keyPair,
                                                   Y3** agentDataOut);
}


// The shared type is the sector header; its stream occupies the remainder of the allocation.
__forceinline void* __cdecl hkpAgent1nSector::operator new(std::size_t)
{
    return Y1::GetMonitorStream().heap().blockAlloc(SECTOR_SIZE);
}
__forceinline void __cdecl hkpAgent1nSector::operator delete(void* p)
{
    if (p) Y1::GetMonitorStream().heap().blockFree(p, SECTOR_SIZE);
}
__forceinline FourByteState* hkpAgent1nSector::getBegin()
{
    return reinterpret_cast<FourByteState*>(&m_unk0C + 1);
}
inline FourByteState* hkpAgent1nSector::GetStreamEnd()
{
    return reinterpret_cast<FourByteState*>(reinterpret_cast<char*>(&m_unk0C + 1) + m_uiAgentCount);
}
inline void* hkpAgent1nSector::getEndOfCapacity()
{
    return reinterpret_cast<char*>(&m_unk0C + 1) + NET_SECTOR_SIZE;
}
inline int hkpAgent1nSector::getCapacity() { return NET_SECTOR_SIZE; }
inline hkpAgent1nSector::hkpAgent1nSector() : m_uiAgentCount(0) {}

namespace AgentSectorUtilities {
__forceinline hkpCollisionAgent*& __cdecl getChildAgent(Y3* agentData)
{
    return *reinterpret_cast<hkpCollisionAgent**>(agentData);
}
__forceinline Y3* __cdecl getAgentDataEnd(Y3* agentData)
{
    return hkAddByteOffset(agentData, (((sizeof(getChildAgent(agentData))) + ((16) - 1)) & (~((16) - 1))));
}
}
extern "C"
{
    const hkpCdBody* __cdecl GetTransformedCdBody(const hkpCdBody* cdBody, hkpCdBody* newCdBodies,
                                                  hkMotionState* newMotionStates, int numSlots,
                                                  AgentValue<hkUchar>& cdBodyHasTransformFlag);
}

struct AgentProcessingBodyTemp
{
    hkpCdBody m_pBodyA;
    hkpCdBody m_pBodyB;
    AgentTransform m_kTransformA;
    AgentTransform m_kTransformB;
};
__declspec(noinline) static void CreateAgentInputWithTemporaryBodies(MachineAgentInputLocalForm& in,
                                                                     AgentProcessingBodyTemp& bodyTemp,
                                                                     MachineAgentInputLocalForm& out)
{
    MotionUtilities::ComputeTransformAtTime(in.m_pBodyA->GetMotionState()->getSweptTransform(),
                           GetStepTime(in.m_pRayCastInput->m_pStepInfo.m_uiStartTime), bodyTemp.m_kTransformA);
    MotionUtilities::ComputeTransformAtTime(in.m_pBodyB->GetMotionState()->getSweptTransform(),
                           GetStepTime(in.m_pRayCastInput->m_pStepInfo.m_uiStartTime), bodyTemp.m_kTransformB);
    out.m_pBodyA = &bodyTemp.m_pBodyA;
}
__declspec(noinline) static void InvertAgentSubtypeMarker(AgentSubtypeMarker& in, AgentSubtypeMarker& out)
{
    out.m_vSubtypePosition.setNeg3(in.m_vSubtypePosition);
    out.m_kTransform.SetConjugate(in.m_kTransform);
}
class WrappedShapeKeys
{
  public:
    __forceinline bool operator==(const ShapeKeyCombination& p)
    {
        return m_uiShapeKeyB == p.m_uiShapeKeyB && m_uiShapeKeyA == p.m_uiShapeKeyA;
    }
    __forceinline bool operator>(const ShapeKeyCombination& p)
    {
        return m_uiShapeKeyB > p.m_uiShapeKeyB || (m_uiShapeKeyB == p.m_uiShapeKeyB && m_uiShapeKeyA > p.m_uiShapeKeyA);
    }
    __forceinline void operator=(const ShapeKeyCombination& p)
    {
        m_uiShapeKeyA = p.m_uiShapeKeyA;
        m_uiShapeKeyB = p.m_uiShapeKeyB;
    }
    __forceinline void writeTo(ShapeKeyCombination& p)
    {
        p.m_uiShapeKeyB = m_uiShapeKeyB;
        p.m_uiShapeKeyA = m_uiShapeKeyA;
    }
    AgentValue<hkpShapeKey> m_uiShapeKeyA;
    AgentValue<hkpShapeKey> m_uiShapeKeyB;
};
static __forceinline void extractChildShapes(const WrappedShapeKeys& shapeKeyPair,
                                             WrappedShapeKeys& extractedShapeKeys,
                                             const hkpShapeContainer* shapeContainerA,
                                             const hkpShapeContainer* shapeContainerB, hkpShapeBuffer& shapeBufferA,
                                             hkpShapeBuffer& shapeBufferB, hkpCdBody& modifiedBodyA,
                                             hkpCdBody& modifiedBodyB)
{
    {
        hkpShapeKey key = shapeKeyPair.m_uiShapeKeyB;
        if (extractedShapeKeys.m_uiShapeKeyB != key)
        {
            extractedShapeKeys.m_uiShapeKeyB = key;
            const hkpShape* shapeB = shapeContainerB->GetShapeForKey(key, shapeBufferB);
            modifiedBodyB.SetCollisionShapeAndKey(shapeB, key);
        }
    }
    {
        hkpShapeKey key = shapeKeyPair.m_uiShapeKeyA;
        if (extractedShapeKeys.m_uiShapeKeyA != key)
        {
            extractedShapeKeys.m_uiShapeKeyA = key;
            const hkpShape* shapeA = shapeContainerA->GetShapeForKey(key, shapeBufferA);
            modifiedBodyA.SetCollisionShapeAndKey(shapeA, key);
        }
    }
}
// @fnv 0x00da5b80
// src: GUESS 0x00da5b80 (confidence: low)
void __cdecl ProcessAgentSectorsAndChildren_00da5b80(AgentSectorPointerArray& agentTrack, const AgentSubtypeMarker& inputIn,
                          const hkpShapeContainer* shapeContainerA, const hkpShapeContainer* shapeContainerB,
                          const ShapeKeyCombination* newKeys, WorldOperationEntry& output)
{
    MathUtilities::prefetch128(agentTrack.m_kSectors.m_data);
    AgentSubtypeMarker input;
    MemoryUtils::memCpy16NonEmpty(&input, &inputIn, sizeof(AgentSubtypeMarker) / 16);
    WrappedShapeKeys extractedShapeKeys;
    extractedShapeKeys.m_uiShapeKeyA = 0xffffffff;
    extractedShapeKeys.m_uiShapeKeyB = 0xffffffff;
    hkpCollisionDispatcher* dispatcher = input.m_pRayCastInput->m_pCollisionDispatcher;
    const int numSlotsForTransformedCdBodies = 4;
    hkMotionState transformForTransformedShapeB[numSlotsForTransformedCdBodies];
    hkMotionState transformForTransformedShapeA[numSlotsForTransformedCdBodies];
    hkpCdBody cdBodyForTransformedShapeB[numSlotsForTransformedCdBodies];
    hkpCdBody cdBodyForTransformedShapeA[numSlotsForTransformedCdBodies];
    AgentValue<const hkpCdBody*>* modifiedBodyBPtr = &input.m_pBodyB;
    AgentValue<const hkpCdBody*>* modifiedBodyAPtr = &input.m_pBodyA;
    hkpCdBody childBodyB(inputIn.m_pBodyB);
    *modifiedBodyBPtr = &childBodyB;
    hkpCdBody childBodyA(inputIn.m_pBodyA);
    *modifiedBodyAPtr = &childBodyA;
    int numTim = 0;
    hkpAgent1nSector* readSector = agentTrack.m_kSectors.m_data[0];
    MathUtilities::forcePrefetch<512>(readSector);
    hkpAgent1nSector* currentSector =
        (input.m_pRayCastInput->m_pAgent1nSector) ? input.m_pRayCastInput->m_pAgent1nSector : ::new (hkpAgent1nSector::operator new(hkpAgent1nSector::SECTOR_SIZE))
            hkpAgent1nSector;
    input.m_pRayCastInput->m_pAgent1nSector = 0;
    int currentSectorIndex = 0;
    bool prevInputInitialized = false;
    bool prevFlippedInputInitialized = false;
    MachineAgentInputLocalForm prevInput;
    MachineAgentInputLocalForm prevFlippedInput;
    AgentProcessingBodyTemp prevTemp;
    AgentProcessingBodyTemp prevFlippedTemp;
    __declspec(align(16)) hkUchar extensionBuffer[AgentCallbacks::MAX_TOTAL_SIZE];
    bool inExtensionBuffer = false;
    int nextReadSectorIndex = 1;
    void* readData = readSector->getBegin();
    void* readEnd = readSector->GetStreamEnd();
    void* currentData = currentSector->getBegin();
    void* currentDataEnd = currentSector->getEndOfCapacity();
    int bytesUsedInCurrentSector = 0;
    hkpShapeBuffer shapeBufferA;
    hkpShapeBuffer shapeBufferB;
    while (1)
    {
        WrappedShapeKeys shapeKeyPair;
        *modifiedBodyBPtr = &childBodyB;
        *modifiedBodyAPtr = &childBodyA;
        input.m_kTransform = inputIn.m_kTransform;
        if (!newKeys)
        {
            ShapeKeyAgentEntry* entry = reinterpret_cast<ShapeKeyAgentEntry*>(readData);
            int entrySize = entry->m_iElementCount;
            MemoryUtils::memCpy16NonEmpty(currentData, readData, entrySize >> 4);
            readData = hkAddByteOffset(readData, entrySize);
            shapeKeyPair = entry->m_kShapeKeyPair;
        }
        else
        {
            ShapeKeyAgentEntry* readHeader = reinterpret_cast<ShapeKeyAgentEntry*>(readData);
            shapeKeyPair = *newKeys;
            if (shapeKeyPair == readHeader->m_kShapeKeyPair)
            {
                int size = readHeader->m_iElementCount;
                MemoryUtils::memCpy16NonEmpty(currentData, readData, size >> 4);
                readData = hkAddByteOffset(readData, size);
                newKeys++;
            }
            else if (shapeKeyPair > readHeader->m_kShapeKeyPair)
            {
                void* agentData = ((readHeader->m_ucAgentType & 6) == AgentCallbacks::STREAM_CALL_WITH_TIM)
                                      ? (void*)hkAddByteOffset(readHeader, sizeof(ByteStateWithMixedNumericData))
                                      : (void*)hkAddByteOffset(readHeader, sizeof(ByteStateWithThreeIntegers));
                readData = hkAddByteOffset(readData, readHeader->m_iElementCount);
                GetAgent3DestroyFunc(dispatcher, readHeader->m_ucNnTrackType)(
                    readHeader, agentData, input.m_pContactManager, *output.m_pConstraintOwner.val(), dispatcher);
                goto checkReadSector;
            }
            else
            {
                if (input.m_pRayCastInput->m_iFilter->IsCollisionEnabled(
                        *input.m_pRayCastInput, *inputIn.m_pBodyA, *inputIn.m_pBodyB, *shapeContainerA,
                        *shapeContainerB, shapeKeyPair.m_uiShapeKeyA, shapeKeyPair.m_uiShapeKeyB))
                {
                    if (hkMemoryStateIsOutOfMemory(18))
                    {
                        newKeys++;
                        goto checkReadSector;
                    }
                    extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                       shapeBufferB, childBodyA, childBodyB);
                    const hkpShape* shapeB = (*modifiedBodyBPtr)->m_pCollisionShape;
                    const hkpShape* shapeA = (*modifiedBodyAPtr)->m_pCollisionShape;
                    AgentValue<hkUchar> cdBodyHasTransformFlag = 0;
                    *modifiedBodyBPtr = GetTransformedCdBody(*modifiedBodyBPtr, cdBodyForTransformedShapeB,
                                                             transformForTransformedShapeB,
                                                             numSlotsForTransformedCdBodies, cdBodyHasTransformFlag);
                    shapeB = (*modifiedBodyBPtr)->m_pCollisionShape;
                    *modifiedBodyAPtr = GetTransformedCdBody(*modifiedBodyAPtr, cdBodyForTransformedShapeA,
                                                             transformForTransformedShapeA,
                                                             numSlotsForTransformedCdBodies, cdBodyHasTransformFlag);
                    shapeA = (*modifiedBodyAPtr)->m_pCollisionShape;
                    input.m_kTransform.SetMulInverse(reinterpret_cast<const AgentTransform&>((*modifiedBodyAPtr)->getTransform()),
                                                     reinterpret_cast<const AgentTransform&>((*modifiedBodyBPtr)->getTransform()));
                    ShapeKeyAgentEntry* h = reinterpret_cast<ShapeKeyAgentEntry*>(currentData);
                    shapeKeyPair.writeTo(h->m_kShapeKeyPair);
                    h->m_ucNnTrackType = hkUchar(dispatcher->getAgent3Type(
                        shapeA->getType(), shapeB->getType(), input.m_pRayCastInput->m_bCreatePredictiveAgents));
                    h->m_usNumContactPoints = 0;
                    AgentSubtypeMarker flippedInput;
                    AgentSubtypeMarker* in = &input;
                    int isFlipped = 0;
                    if (GetAgent3Symmetric(dispatcher, h->m_ucNnTrackType) == AgentCallbacks::IS_NOT_SYMMETRIC_AND_FLIPPED)
                    {
                        isFlipped = 1;
                        in = &flippedInput;
                        InvertAgentSubtypeMarker(input, flippedInput);
                    }
                    if (GetAgent3SepNormalFunc(dispatcher, h->m_ucNnTrackType))
                    {
                        ByteStateWithMixedNumericData* entry =
                            reinterpret_cast<ByteStateWithMixedNumericData*>(currentData);
                        entry->m_ucAgentType =
                            hkUchar(AgentCallbacks::STREAM_CALL_WITH_TIM + isFlipped) | cdBodyHasTransformFlag;
                        entry->m_fFloatValue = -1.0f;
                        entry->m_vSeparatingNormal.setZero4();
                        void* agentData = entry + 1;
                        void* agentEnd = GetAgent3CreateFunc(dispatcher, entry->m_ucNnTrackType)(*in, entry, agentData);
                        hkUlong size = hkGetByteOffset(entry, agentEnd);
                        entry->m_iElementCount = hkUchar(size);
                        ;
                    }
                    else
                    {
                        ByteStateWithThreeIntegers* entry = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                        entry->m_ucAgentType = hkUchar(AgentCallbacks::STREAM_CALL + isFlipped) | cdBodyHasTransformFlag;
                        void* agentData = entry + 1;
                        void* agentEnd = GetAgent3CreateFunc(dispatcher, entry->m_ucNnTrackType)(*in, entry, agentData);
                        hkUlong size = hkGetByteOffset(entry, agentEnd);
                        entry->m_iElementCount = hkUchar(size);
                        ;
                    }
                }
                else
                {
                    ByteStateWithThreeIntegers* h = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                    *reinterpret_cast<hkUint32*>(h) = 0;
                    shapeKeyPair.writeTo(h->m_kShapeKeyPair);
                    h->m_iElementCount = sizeof(ByteStateWithThreeIntegers);
                }
                newKeys++;
            }
        }
        {
            bool thisChildHasTransformApplied = false;
            AgentCallbacks::StreamCommand command =
                AgentCallbacks::StreamCommand(reinterpret_cast<FourByteState*>(currentData)->m_ucAgentType);
        commandSwitch:
            switch (command)
            {
            case AgentCallbacks::STREAM_CALL_WITH_TRANSFORM:
            case AgentCallbacks::STREAM_CALL_FLIPPED_WITH_TRANSFORM:
            case AgentCallbacks::STREAM_CALL_WITH_TIM_WITH_TRANSFORM:
            case AgentCallbacks::STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM:
            case AgentCallbacks::STREAM_CALL_AGENT_WITH_TRANSFORM: {
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                AgentValue<hkUchar> dummyCdBodyHasTransformFlag = 0;
                *modifiedBodyBPtr =
                    GetTransformedCdBody(*modifiedBodyBPtr, cdBodyForTransformedShapeB, transformForTransformedShapeB,
                                         numSlotsForTransformedCdBodies, dummyCdBodyHasTransformFlag);
                *modifiedBodyAPtr =
                    GetTransformedCdBody(*modifiedBodyAPtr, cdBodyForTransformedShapeA, transformForTransformedShapeA,
                                         numSlotsForTransformedCdBodies, dummyCdBodyHasTransformFlag);
                input.m_kTransform.SetMulInverse(reinterpret_cast<const AgentTransform&>((*modifiedBodyAPtr)->getTransform()),
                                                 reinterpret_cast<const AgentTransform&>((*modifiedBodyBPtr)->getTransform()));
                command = AgentCallbacks::StreamCommand(hkUchar(command) & hkUchar(~AgentCallbacks::TRANSFORM_FLAG));
                thisChildHasTransformApplied = true;
                prevFlippedInputInitialized = false;
                prevInputInitialized = false;
                goto commandSwitch;
            }
            case AgentCallbacks::STREAM_CALL_AGENT: {
                ByteStateWithThreeIntegers* paddedEntry = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                void* agentData = paddedEntry + 1;
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                hkpCollisionAgent* agent = AgentSectorUtilities::getChildAgent(agentData);
                ProcessCollisionAgent(agent, **modifiedBodyAPtr, **modifiedBodyBPtr, *input.m_pRayCastInput, output);
                currentData = AgentSectorUtilities::getAgentDataEnd(agentData);
                break;
            }
            case AgentCallbacks::STREAM_CALL: {
                ByteStateWithThreeIntegers* entry = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                void* agentData = entry + 1;
                currentData =
                    GetAgent3ProcessFunc(dispatcher, entry->m_ucNnTrackType)(input, entry, agentData, 0, output);
                entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                break;
            }
            case AgentCallbacks::STREAM_CALL_FLIPPED: {
                AgentSubtypeMarker flippedInput;
                InvertAgentSubtypeMarker(input, flippedInput);
                ByteStateWithThreeIntegers* entry = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                hkReal oldToi = output.m_fTimeOfImpact.m_uiCommandId;
                void* agentData = entry + 1;
                ContactPointWithId* oldResultBegin = output.m_pAlignedPairData;
                currentData =
                    GetAgent3ProcessFunc(dispatcher, entry->m_ucNnTrackType)(flippedInput, entry, agentData, 0, output);
                entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                while (oldResultBegin < output.m_pAlignedPairData)
                {
                    oldResultBegin->m_kPoint.flip();
                    oldResultBegin++;
                }
                if (oldToi != output.m_fTimeOfImpact.m_uiCommandId)
                {
                    output.m_fTimeOfImpact.flip();
                }
                break;
            }
            case AgentCallbacks::STREAM_CALL_WITH_TIM_FLIPPED: {
                AgentSubtypeMarker flippedInput;
                InvertAgentSubtypeMarker(input, flippedInput);
                ByteStateWithMixedNumericData* entry = reinterpret_cast<ByteStateWithMixedNumericData*>(currentData);
                hkReal distAtT1;
                if (entry->m_fFloatValue != GetStepTime(flippedInput.m_pRayCastInput->m_pStepInfo.m_uiStartTime))
                {
                    const AgentQualityInfo* ci = flippedInput.m_pRayCastInput->m_pCollisionQualityInfo;
                    if (!ci->m_iQualityInfoValue10.val())
                    {
                        entry->m_fFloatValue = GetStepTime(flippedInput.m_pRayCastInput->m_pStepInfo.m_fEndTime);
                        distAtT1 = ci->m_fCreateContactThreshold * 0.5f;
                        entry->m_vSeparatingNormal.setZero4();
                        entry->m_vSeparatingNormal(3) = distAtT1;
                        goto PROCESS_AT_T1_FLIPPED;
                    }
                    if (!prevFlippedInputInitialized)
                    {
                        prevFlippedInputInitialized = !thisChildHasTransformApplied;
                        CreateAgentInputWithTemporaryBodies(flippedInput, prevFlippedTemp, prevFlippedInput);
                        prevFlippedTemp.m_pBodyB.SetCollisionShapeAndKey(flippedInput.m_pBodyB->getShape(),
                                                                         flippedInput.m_pBodyB->m_uiCollisionShapeKey);
                    }
                    extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                       shapeBufferB, childBodyA, childBodyB);
                    prevFlippedTemp.m_pBodyA.SetCollisionShapeAndKey((*modifiedBodyBPtr)->m_pCollisionShape,
                                                                     (*modifiedBodyBPtr)->m_uiCollisionShapeKey);
                    prevFlippedTemp.m_pBodyB.SetCollisionShapeAndKey((*modifiedBodyAPtr)->m_pCollisionShape,
                                                                     (*modifiedBodyAPtr)->m_uiCollisionShapeKey);
                    void* agentData = entry + 1;
                    GetAgent3SepNormalFunc(dispatcher, entry->m_ucNnTrackType)(prevFlippedInput, entry, agentData,
                                                                               entry->m_vSeparatingNormal);
                }
                entry->m_fFloatValue = GetStepTime(flippedInput.m_pRayCastInput->m_pStepInfo.m_fEndTime);
                {
                    hkReal worstCaseDeltaDist = flippedInput.m_vSubtypePosition.dot4xyz1(entry->m_vSeparatingNormal);
                    distAtT1 = entry->m_vSeparatingNormal(3) - worstCaseDeltaDist;
                }
                if (distAtT1 >= flippedInput.m_pRayCastInput->getTolerance())
                {
                    entry->m_vSeparatingNormal(3) = distAtT1;
                    if (!entry->m_usNumContactPoints)
                    {
                        currentData = hkAddByteOffset(currentData, entry->m_iElementCount);
                    }
                    else
                    {
                        void* agentData = entry + 1;
                        currentData = GetAgent3CleanupFunc(dispatcher, entry->m_ucNnTrackType)(
                            entry, agentData, flippedInput.m_pContactManager, *output.m_pConstraintOwner.val());
                        entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                    }
                    numTim++;
                    break;
                }
            PROCESS_AT_T1_FLIPPED:
                flippedInput.m_fSubtypeValue = distAtT1;
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                ContactPointWithId* oldResultBegin = output.m_pAlignedPairData;
                hkReal oldToi = output.m_fTimeOfImpact.m_uiCommandId;
                void* agentData = entry + 1;
                currentData = GetAgent3ProcessFunc(dispatcher, entry->m_ucNnTrackType)(
                    flippedInput, entry, agentData, &entry->m_vSeparatingNormal, output);
                entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                while (oldResultBegin < output.m_pAlignedPairData)
                {
                    oldResultBegin->m_kPoint.flip();
                    oldResultBegin++;
                }
                if (oldToi != output.m_fTimeOfImpact.m_uiCommandId)
                {
                    output.m_fTimeOfImpact.flip();
                }
                break;
            }
            case AgentCallbacks::STREAM_CALL_WITH_TIM: {
                ByteStateWithMixedNumericData* entry = reinterpret_cast<ByteStateWithMixedNumericData*>(currentData);
                hkReal distAtT1;
                if (entry->m_fFloatValue != GetStepTime(input.m_pRayCastInput->m_pStepInfo.m_uiStartTime))
                {
                    if (entry->m_fFloatValue >= GetStepTime(input.m_pRayCastInput->m_pStepInfo.m_fEndTime))
                    {
                        hkReal backDt = entry->m_fFloatValue - GetStepTime(input.m_pRayCastInput->m_pStepInfo.m_fEndTime);
                        hkVector4 backTim;
                        MotionUtilities::calcTimInfo(*input.m_pBodyA->GetMotionState(),
                                                     *input.m_pBodyB->GetMotionState(), backDt, backTim);
                        hkReal backLinear = backTim.dot3(entry->m_vSeparatingNormal);
                        hkReal backAng = backTim(3);
                        distAtT1 = entry->m_vSeparatingNormal(3) + backLinear - backAng;
                    }
                    else
                    {
                        const AgentQualityInfo* ci = input.m_pRayCastInput->m_pCollisionQualityInfo;
                        if (!ci->m_iQualityInfoValue10.val())
                        {
                            entry->m_fFloatValue = GetStepTime(input.m_pRayCastInput->m_pStepInfo.m_fEndTime);
                            distAtT1 = ci->m_fCreateContactThreshold * 0.1f;
                            entry->m_vSeparatingNormal.setZero4();
                            entry->m_vSeparatingNormal(3) = distAtT1;
                            goto PROCESS_AT_T1;
                        }
                        if (!prevInputInitialized)
                        {
                            prevInputInitialized = !thisChildHasTransformApplied;
                            CreateAgentInputWithTemporaryBodies(input, prevTemp, prevInput);
                        }
                        extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB,
                                           shapeBufferA, shapeBufferB, childBodyA, childBodyB);
                        prevTemp.m_pBodyB.SetCollisionShapeAndKey((*modifiedBodyBPtr)->m_pCollisionShape,
                                                                  (*modifiedBodyBPtr)->m_uiCollisionShapeKey);
                        prevTemp.m_pBodyA.SetCollisionShapeAndKey((*modifiedBodyAPtr)->m_pCollisionShape,
                                                                  (*modifiedBodyAPtr)->m_uiCollisionShapeKey);
                        void* agentData = entry + 1;
                        GetAgent3SepNormalFunc(dispatcher, entry->m_ucNnTrackType)(prevInput, entry, agentData,
                                                                                   entry->m_vSeparatingNormal);
                    }
                }
                entry->m_fFloatValue = GetStepTime(input.m_pRayCastInput->m_pStepInfo.m_fEndTime);
                {
                    hkReal worstCaseDeltaDist = input.m_vSubtypePosition.dot4xyz1(entry->m_vSeparatingNormal);
                    distAtT1 = entry->m_vSeparatingNormal(3) - worstCaseDeltaDist;
                }
                if (distAtT1 >= input.m_pRayCastInput->getTolerance())
                {
                    entry->m_vSeparatingNormal(3) = distAtT1;
                    if (!entry->m_usNumContactPoints)
                    {
                        currentData = hkAddByteOffset(currentData, entry->m_iElementCount);
                    }
                    else
                    {
                        void* agentData = entry + 1;
                        currentData = GetAgent3CleanupFunc(dispatcher, entry->m_ucNnTrackType)(
                            entry, agentData, input.m_pContactManager, *output.m_pConstraintOwner.val());
                        entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                    }
                    numTim++;
                    break;
                }
            PROCESS_AT_T1:
                input.m_fSubtypeValue = distAtT1;
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                void* agentData = entry + 1;
                currentData = GetAgent3ProcessFunc(dispatcher, entry->m_ucNnTrackType)(
                    input, entry, agentData, &entry->m_vSeparatingNormal, output);
                entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                break;
            }
            case AgentCallbacks::STREAM_NULL: {
                currentData = hkAddByteOffset(currentData, sizeof(ByteStateWithThreeIntegers));
                break;
            }
            case AgentCallbacks::STREAM_END: {
                currentData = hkAddByteOffset(currentData, sizeof(ByteStateWithThreeIntegers));
                break;
            }
            default:;
            }
        }
    checkReadSector:;
        if (readData == readEnd)
        {
            if (input.m_pRayCastInput->m_pAgent1nSector)
            {
                delete readSector;
            }
            else
            {
                input.m_pRayCastInput->m_pAgent1nSector = readSector;
            }
            if (nextReadSectorIndex < agentTrack.m_kSectors.m_iElementCount)
            {
                readSector = agentTrack.m_kSectors.m_data[nextReadSectorIndex];
                readData = readSector->getBegin();
                readEnd = readSector->GetStreamEnd();
                nextReadSectorIndex++;
            }
            else
            {
                break;
            };
        }
        if (hkAddByteOffset(currentData, AgentCallbacks::MAX_TOTAL_SIZE) <= currentDataEnd)
        {
            continue;
        }
        if (!inExtensionBuffer)
        {
            inExtensionBuffer = true;
            bytesUsedInCurrentSector = hkGetByteOffset(currentSector->getBegin(), currentData);
            ;
            currentData = extensionBuffer;
            currentDataEnd = hkAddByteOffset(extensionBuffer, AgentCallbacks::MAX_TOTAL_SIZE);
            continue;
        }
        int bytesUsedInExtensionBuffer;
        bytesUsedInExtensionBuffer = hkGetByteOffset(extensionBuffer, currentData);
        {
            int freeBytes = currentSector->getCapacity() - bytesUsedInCurrentSector;
            if (bytesUsedInExtensionBuffer <= freeBytes)
            {
                void* dst = hkAddByteOffset(static_cast<void*>(currentSector->getBegin()), bytesUsedInCurrentSector);
                MemoryUtils::memCpy16NonEmpty(dst, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
                bytesUsedInCurrentSector += bytesUsedInExtensionBuffer;
                if (bytesUsedInCurrentSector < currentSector->getCapacity())
                {
                    currentData = extensionBuffer;
                    continue;
                }
                inExtensionBuffer = false;
                currentData = 0;
                currentDataEnd = 0;
            }
        }
        currentSector->m_uiAgentCount = bytesUsedInCurrentSector;
        if (currentSectorIndex >= nextReadSectorIndex)
        {
            reinterpret_cast<hkArray<hkpAgent1nSector*>&>(agentTrack.m_kSectors).expandAt(nextReadSectorIndex, 1);
            nextReadSectorIndex++;
        }
        agentTrack.m_kSectors.m_data[currentSectorIndex] = currentSector;
        ;
        currentSectorIndex++;
        currentSector = (input.m_pRayCastInput->m_pAgent1nSector) ? input.m_pRayCastInput->m_pAgent1nSector
                                                                    : ::new (hkpAgent1nSector::operator new(hkpAgent1nSector::SECTOR_SIZE))
            hkpAgent1nSector;
        input.m_pRayCastInput->m_pAgent1nSector = 0;
        currentData = currentSector->getBegin();
        currentDataEnd = currentSector->getEndOfCapacity();
        if (inExtensionBuffer)
        {
            MemoryUtils::memCpy16NonEmpty(currentData, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
            currentData = hkAddByteOffset(currentData, bytesUsedInExtensionBuffer);
            inExtensionBuffer = false;
        }
    }
    if (!inExtensionBuffer)
    {
        bytesUsedInCurrentSector = hkGetByteOffset(currentSector->getBegin(), currentData);
    }
    else
    {
        int bytesUsedInExtensionBuffer = hkGetByteOffset(extensionBuffer, currentData);
        ;
        void* dst = hkAddByteOffset(static_cast<void*>(currentSector->getBegin()), bytesUsedInCurrentSector);
        MemoryUtils::memCpy16NonEmpty(dst, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
        bytesUsedInCurrentSector += bytesUsedInExtensionBuffer;
    };
    currentSector->m_uiAgentCount = bytesUsedInCurrentSector;
    reinterpret_cast<hkArray<hkpAgent1nSector*>&>(agentTrack.m_kSectors).setSize(currentSectorIndex + 1);
    agentTrack.m_kSectors.m_data[currentSectorIndex] = currentSector;
    ;
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::AddValueCommand* h =
                reinterpret_cast<hkMonitorStream::AddValueCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "M"
                                "i"
                                "numTim";
            h->m_value = float(numTim);
            mStream.setEnd((char*)(h + 1));
        }
    };
}

class hkClass;
namespace fnv_00da4aa0 {
typedef float hkReal;
typedef unsigned char Q42;
typedef unsigned char Q150;
typedef unsigned short Q133;
typedef unsigned int Q49;
typedef unsigned long __w64 Q165;
typedef signed long __w64 hkLong;
typedef unsigned __w64 Q3;
typedef hkReal hkTime;
__forceinline hkLong __cdecl Q19(const void* base, const void* pntr)
{
    return hkLong(pntr) - hkLong(base);
}
template <typename TYPE> __forceinline TYPE* __cdecl Q11(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

typedef int Q134;

extern "C"
{
    extern const hkReal Q128[256];
}

template <typename TYPE> class Q20
{
  public:
    __forceinline Q20()
    {}
    __forceinline Q20(TYPE e) : q89(e)
    {}
    __forceinline void operator=(TYPE e)
    {
        q89 = e;
    }
    __forceinline TYPE val() const
    {
        return q89;
    }
    __forceinline TYPE operator->() const
    {
        return q89;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE q89;
};

namespace MemoryUtilities {
void __cdecl CopyByteRange(void* dst, const void* src, int nbytes);
}

class Q0
{
  public:
    __forceinline void* __cdecl operator new(Q3, void* p)
    {
        return p;
    }
    typedef hkMemoryAllocator Allocator;
    static Q0& __cdecl GetMonitorStream();
    inline Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    hkStackMemory m_aiEntries;
    Allocator* m_pTemp;
    Allocator* m_pStreamAllocator;
};
class Q114
{
  public:
    static const struct Q13 Members[];
    __forceinline virtual ~Q114()
    {}

  public:
    __forceinline Q114()
    {}
};
class Q67;
class Q16 : public Q114
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        Q16* b = static_cast<Q16*>(Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes)));
        b->q82 = static_cast<Q133>(nbytes);
        ;
        return b;
    }
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(Q67* collector, const hkClass* cls) const;

  public:
    enum
    {
        MASK_MEMSIZE = 0x7fff
    };
    Q133 q82;

  public:
    Q16(class FinishingFlag flag)
    {}
};
template <bool N> struct Q153
{
    typedef Q153<N> type;
    enum
    {
        result = N
    };
};
typedef Q153<true> Q154;
class Q184
{
  public:
    template <typename T> static __forceinline void construct(T* t, int n, Q154);
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& a, void*, int reqElem, int sizeElem);
};
struct Q99
{
    hkMemoryAllocator& get(const void*)
    {
        return Q0::GetMonitorStream().heap();
    }
};
template <typename T> class Q25
{
  public:
    typedef Q25<T> ThisType;

  protected:
    __forceinline Q25(const Q25& a)
    {
        ;
    }

  public:
    __forceinline void _useExternalArray(T*, int cap);
    __forceinline T& operator[](int i);
    __forceinline int GetLogicalSize() const;
    __forceinline int getCapacity() const;
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n);
    __forceinline void _setSize(hkMemoryAllocator& alloc, int size);
    __forceinline T* _expandAt(hkMemoryAllocator& alloc, int index, int numToInsert);
    typedef T* iterator;
    __forceinline iterator begin();

  protected:
    __forceinline Q25<T>& copyFromArray(hkMemoryAllocator&, const Q25<T>& src, Q154);

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
        FORCE_SIGNED = -1
    };

  protected:
    friend class Q67;
    T* m_data;
    int m_iElementCount;
    int q136;

  public:
    Q25(FinishingFlag f)
    {}
};
template <typename T, typename Allocator = Q99> class Q155 : public Q25<T>
{
  public:
    typedef Allocator AllocatorType;

  protected:
    __forceinline Q155(const Q155& a);

  public:
    __forceinline Q155& operator=(const Q25<T>& a);
    __forceinline void SetSizeAndGrow(int size)
    {
        Q25<T>::_setSize(AllocatorType().get(this), size);
    }
    __forceinline T* expandAt(int i, int n)
    {
        return Q25<T>::_expandAt(AllocatorType().get(this), i, n);
    }
};
template <typename T> __forceinline T& Q25<T>::operator[](int i)
{
    ;
    return m_data[i];
}
template <typename T> __forceinline int Q25<T>::GetLogicalSize() const
{
    return m_iElementCount;
}
template <typename T> __forceinline int Q25<T>::getCapacity() const
{
    return (q136 & static_cast<int>(CAPACITY_MASK));
}
template <typename T> __forceinline void Q25<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        Q184::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
    }
}
template <typename T> __forceinline void Q25<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T> __forceinline T* Q25<T>::_expandAt(hkMemoryAllocator& alloc, int index, int numtoinsert)
{
    const int newsize = numtoinsert + m_iElementCount;
    const int numtomove = m_iElementCount - index;
    if (newsize > getCapacity())
    {
        GrowArrayCapacity(alloc, newsize);
    }
    MemoryUtilities::CopyByteRange(m_data + index + numtoinsert, m_data + index, numtomove * sizeof(T));
    m_iElementCount = newsize;
    return m_data + index;
}
template <typename T> typename Q25<T>::iterator Q25<T>::begin()
{
    return m_data;
}
typedef __m128 Q57;
class Q1;
typedef const Q1& Q137;

typedef const hkSimdReal& Q60;
namespace MathUtilities {
inline void prefetch128(const void* p)
{
    _mm_prefetch((const char*)p, 0);
}
template <int SIZE> inline void forcePrefetch(const void* p)
{
    const char* q = (const char*)p;
    _mm_prefetch(q, 0);
    if (SIZE > 64)
    {
        _mm_prefetch(q + 64, 0);
    }
    if (SIZE > 128)
    {
        _mm_prefetch(q + 128, 0);
    }
    if (SIZE > 192)
    {
        _mm_prefetch(q + 192, 0);
    }
}
}
class Q1
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void operator=(const Q1& v);
    __forceinline void setZero4();
    __forceinline void setSub4(const Q1& a, const Q1& b);
    __forceinline void setMul4(Q60 r, const Q1& a);
    __forceinline void addMul4(Q60 r, const Q1& a);
    __forceinline void setAddMul4(const Q1& a, const Q1& x, const Q1& y);
    __forceinline void setNeg3(const Q1& v);
    __forceinline hkSimdReal dot3(const Q1& a) const;
    __forceinline hkSimdReal dot4xyz1(const Q1& a) const;
    __forceinline hkReal& operator()(int i);
    __forceinline const hkReal& operator()(int i) const;
    __forceinline void setBroadcast(Q137 v, int i);

  private:
    Q57 m_vComponents;

  public:
    operator Q57() const
    {
        return m_vComponents;
    }
};


// local form of hkRotation: 0x00da4aa0/0x00da5b80 need the unit hkMatrix3 base and inline router allocation without importing different SIMD overloads.
class __declspec(align(16)) RotationLocal_Agent1n : public hkMatrix3
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
};
class Q28
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline Q28()
    {}
    void SetConjugate(const Q28& t);
    void SetMulInverse(const Q28& bTa, const Q28& bTc);

  private:
    RotationLocal_Agent1n m_rotation;
    Q1 m_vTranslation;
};
inline void Q1::operator=(const Q1& v)
{
    m_vComponents = v.m_vComponents;
}
inline void Q1::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
inline void Q1::setSub4(const Q1& v0, const Q1& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void Q1::setNeg3(const Q1& v)
{
    static __declspec(align(16)) const Q49 negateMask[4] = {0x80000000, 0x80000000, 0x80000000, 0x00000000};
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const Q57*)&negateMask);
}
inline void Q1::setMul4(Q60 r, const Q1& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
inline void Q1::addMul4(Q60 r, const Q1& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline void Q1::setAddMul4(const Q1& a, const Q1& x, const Q1& y)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}
inline hkSimdReal Q1::dot3(const Q1& a) const
{
    Q57 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    Q57 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
inline hkSimdReal Q1::dot4xyz1(const Q1& a) const
{
    Q57 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    Q57 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    Q57 zwSum =
        _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))),
                   _mm_shuffle_ps(m_vComponents, m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3)))));
    return _mm_add_ps(xySum, zwSum);
}
inline hkReal& Q1::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal& Q1::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline void Q1::setBroadcast(const Q1& v, int i)
{
    if (i == 0)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    }
    else if (i == 1)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    }
    else if (i == 2)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    }
    else if (i == 3)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3))));
    }
}


class Q88
{
  public:
    enum ReplaceType
    {
        REPLACE_ONE,
        REPLACE_ALL
    };
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);

  private:
    static void copyAndReplace(char* dest, const char* orig, int origLen, const Q88& from, const Q88& to,
                               const Q155<int>& indices);
};
void __cdecl Q88::memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const Q49* src32 = reinterpret_cast<const Q49*>(src);
    Q49* dst32 = reinterpret_cast<Q49*>(dst);
    {
        do
        {
            dst32[0] = src32[0];
            dst32[1] = src32[1];
            dst32[2] = src32[2];
            dst32[3] = src32[3];
            dst32 += 4;
            src32 += 4;
        } while (--numQuads > 0);
    }
}



typedef Q133 Q86;




// Shape type ids as the exe's agent/dispatch tables index them (values are what the code compares against).
enum Q36  // src: HAVOK_SRC (names)
{
    HK_SHAPE_ALL = -1,
    HK_SHAPE_INVALID = 0,
    HK_SHAPE_SPHERE = 1,
    HK_SHAPE_CYLINDER = 2,
    HK_SHAPE_TRIANGLE = 3,
    HK_SHAPE_BOX = 4,
    HK_SHAPE_CAPSULE = 5,
    HK_SHAPE_CONVEX_VERTICES = 6,
    HK_SHAPE_COLLECTION = 7,
    HK_SHAPE_BV_TREE = 8,
    HK_SHAPE_LIST = 9,
    HK_SHAPE_MOPP = 10,
    HK_SHAPE_CONVEX_TRANSLATE = 11,
    HK_SHAPE_CONVEX_TRANSFORM = 12,
    HK_SHAPE_SAMPLED_HEIGHT_FIELD = 13,
    HK_SHAPE_EXTENDED_MESH = 14,
    HK_SHAPE_TRANSFORM = 15,
    HK_SHAPE_COMPRESSED_MESH = 16,
    HK_SHAPE_MAX_ID_SPU = 17,
    HK_SHAPE_CONVEX = 18,
    HK_SHAPE_PACKED_CONVEX_VERTICES = 19,
    HK_SHAPE_MOPP_EMBEDDED = 20,
    HK_SHAPE_CONVEX_PIECE = 21,
    HK_SHAPE_MULTI_SPHERE = 22,
    HK_SHAPE_CONVEX_LIST = 23,
    HK_SHAPE_TRIANGLE_COLLECTION = 24,
    HK_SHAPE_MULTI_RAY = 25,
    HK_SHAPE_HEIGHT_FIELD = 26,
    HK_SHAPE_SPHERE_REP = 27,
    HK_SHAPE_BV = 28,
    HK_SHAPE_PLANE = 29,
    HK_SHAPE_PHANTOM_CALLBACK = 30,
    HK_SHAPE_USER0 = 31,
    HK_SHAPE_USER1 = 32,
    HK_SHAPE_USER2 = 33,
    HK_SHAPE_MAX_ID = 34,
    HK_FIRST_SHAPE_TYPE = HK_SHAPE_SPHERE
};
typedef ::hkpShapeBuffer Q95;
typedef Q49 Q26;
class Q53
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    Q26 q186;
    Q26 q23;
};
class Q124;

struct Q44;
class Q46;
struct Q6;
class Q51;
struct Q12;
struct Q21
{
    Q42 q74;
    Q42 q38;
    Q42 q75;
    Q42 m_iElementCount;
};
typedef void Q10;
struct Q41
{
    Q41() : q156(0)
    {}
    Q20<const hkpCdBody*> q72;
    Q20<const hkpCdBody*> q65;
    Q20<const hkpCdBody*> q156;
    Q20<const Q44*> q34;
    Q20<Q46*> q59;
    Q28 m_kTransform;
};
struct Q14 : public Q41
{
    Q20<hkReal> q162;
    Q1 q76;
};
namespace Q7 {
typedef int AgentType;
enum
{
    MIN_TOTAL_SIZE = 16,
    MAX_MEMORY_INCREASE = 80,
    MAX_TOTAL_SIZE = 128
};
enum StreamCommand
{
    STREAM_NULL = 0,
    STREAM_END = 1,
    STREAM_CALL = 2,
    STREAM_CALL_FLIPPED = 3,
    STREAM_CALL_WITH_TIM = 4,
    STREAM_CALL_WITH_TIM_FLIPPED = 5,
    STREAM_CALL_AGENT = 6,
    TRANSFORM_FLAG = 0x08,
    STREAM_CALL_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL,
    STREAM_CALL_FLIPPED_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_FLIPPED,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_WITH_TIM,
    STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_WITH_TIM_FLIPPED,
    STREAM_CALL_AGENT_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_AGENT,
};
typedef Q10*(__cdecl* CreateFunc)(const Q41& input, Q21* entry, Q10* agentData);
typedef void(__cdecl* DestroyFunc)(Q21* entry, Q10* agentData, Q46* mgr, Q51& constraintOwner, hkpCollisionDispatcher* dispatcher);
typedef Q10*(__cdecl* ProcessFunc)(const Q14& input, Q21* entry, Q10* agentData, Q1* separatingNormalOut, Q6& result);
enum Symmetric
{
    IS_SYMMETRIC,
    IS_NOT_SYMMETRIC,
    IS_NOT_SYMMETRIC_AND_FLIPPED
};
typedef void(__cdecl* SepNormalFunc)(const Q41& input, Q21* entry, Q10* agentData, Q1& separatingNormalOut);
typedef Q10*(__cdecl* CleanupFunc)(Q21* entry, Q10* agentData, Q46* mgr, Q51& constraintOwner);
typedef void(__cdecl* RemovePointFunc)(Q21* entry, Q10* agentData, Q86 idToRemove);
typedef void(__cdecl* CommitPotentialFunc)(Q21* entry, Q10* agentData, Q86 iContactPointId);
typedef void(__cdecl* CreateZombieFunc)(Q21* entry, Q10* agentData, Q86 idTobecomeZombie);
typedef void(__cdecl* UpdateFilterFunc)(Q21* entry, Q10* agentData, const hkpCdBody& bodyA, const hkpCdBody& bodyB, const Q12& input,
                                        Q46* mgr, Q51& constraintOwner);
typedef void(__cdecl* CalcStatisticsFunc)(Q21* entry, Q10* agentData, const Q12& input, Q67* collector);
typedef void(__cdecl* InvalidateTimFunc)(Q21* entry, Q10* agentData, const Q12& input);
typedef void(__cdecl* WarpTimeFunc)(Q21* entry, Q10* agentData, hkTime oldTime, hkTime newTime, const Q12& input);
}
struct Q61
{
    __declspec(align(16)) hkReal m_fMinimumCollisionSeparation;
    hkReal m_fMinimumExtraSeparation;
    hkReal m_fMaximumExtraSeparation;
    hkReal q175;
    Q20<Q134> q79;
    hkBool q174;
    hkReal q116;
};
class Q131;
struct Q12
{
  public:
    hkReal getTolerance() const
    {
        return q187;
    }

  public:
    Q20<hkpCollisionDispatcher*> q176;
    Q20<Q134> q188;
    Q20<hkReal> q187;
    Q20<const hkpCollisionFilter*> m_iFilter;
    Q20<const Q131*> q197;
    mutable Q20<Q134> q102;
    struct AabbBoundsAndScale
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().blockFree(p, sizeof(Q12::AabbBoundsAndScale));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        Q1 m_kAabbMin;
        Q1 m_kAabbMaximum;
        Q1 m_kAabbScale;
    };
    AabbBoundsAndScale m_aiValues;
};
class Q87;
class Q39;
class Q80;
struct Q68;

static __forceinline Q7::CreateFunc GetAgent3CreateFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<Q7::CreateFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pCreateFunc);
}
static __forceinline Q7::DestroyFunc GetAgent3DestroyFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<Q7::DestroyFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pAgent3DestroyFuncs);
}
static __forceinline Q7::CleanupFunc GetAgent3CleanupFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<Q7::CleanupFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pAgentFunction3);
}
static __forceinline Q7::ProcessFunc GetAgent3ProcessFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<Q7::ProcessFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pAgentFunction8);
}
static __forceinline Q7::SepNormalFunc GetAgent3SepNormalFunc(hkpCollisionDispatcher* dispatcher, int type)
{
    return reinterpret_cast<Q7::SepNormalFunc>(dispatcher->m_kAgent3FunctionTable[type].m_pAgentFunction7);
}
static __forceinline Q7::Symmetric GetAgent3Symmetric(hkpCollisionDispatcher* dispatcher, int type)
{
    return static_cast<Q7::Symmetric>(dispatcher->m_kAgent3FunctionTable[type].m_eSymmetric);
}
class Q149
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkReal m_fAccumulatedImpulse;
};

class Q97 : public hkContactPointMaterial
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkReal m_uiUserData;
    typedef Q49 UserData;
};
__declspec(align(16)) class Q55 : public Q97
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    UserData q192[7];
};
struct Q40
{
    hkContactPoint q181;
    Q20<Q49> m_usContactPointId;
};

struct Q44 : public Q12
{
  public:
    Q44() : q27(0)
    {}

  public:
    hkStepInfo q64;
    mutable Q20<Q61*> q81;
    mutable hkpAgent1nSector* q27;
};
class Q193
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    void init(const Q124* shapeA, const Q124* shapeB, const Q28& btoa);
    inline void flip();
};
__declspec(align(16)) class Q182 : public Q193
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
};
enum
{
    HK_MAX_CONTACT_POINT = 256
};
struct Q62
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    Q20<Q40*> q47;
    Q20<Q51*> q84;
    Q40 m_akContactPoints[HK_MAX_CONTACT_POINT];
    struct CollisionCacheState
    {
      public:
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().blockFree(p, sizeof(Q62::CollisionCacheState));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        inline CollisionCacheState();
        inline void flip();

      public:
        hkContactPoint q126;
        Q20<hkReal> m_uiCommandId;
        Q20<hkReal> q183;
        Q182 m_kGskCache;
        Q55 m_kProperties;
    };
    struct CollisionCacheState m_fTimeOfImpact;
};
void Q62::CollisionCacheState::flip()
{
    hkVector4& norm = q126.getSeparatingNormal();
    hkVector4 flippedNormal;
    flippedNormal.setNeg3(norm);
    norm = flippedNormal;
    m_kGskCache.flip();
}
struct Q6 : public Q62
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    struct ContactPointAgentEntry
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().blockFree(p, sizeof(Q6::ContactPointAgentEntry));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        Q40* q126;
        Q21* q94;
        void* q110;
    };
    struct ContactPointBuffer
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().blockFree(p, sizeof(Q6::ContactPointBuffer));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        void reset()
        {
            q29 = &q9[0];
            q77 = &q105[0];
        }
        ContactPointAgentEntry* q29;
        Q40** q77;
        Q40* q105[HK_MAX_CONTACT_POINT];
        ContactPointAgentEntry q9[HK_MAX_CONTACT_POINT];
    };

  public:
    Q20<ContactPointBuffer*> q9;
};
extern hkMemoryAllocator::MemoryState Q140;
__forceinline hkMemoryAllocator::MemoryState Q118()
{
    return Q140;
}
__forceinline bool Q93(int id)
{
    bool lowOnMem = Q118() == hkMemoryAllocator::MEMORY_STATE_OUT_OF_MEMORY;
    return lowOnMem;
}
namespace Q56 {
void __cdecl ComputeTransformAtTime(const hkSweptTransform& sweptTrans, hkTime time, Q28& transformOut);
__forceinline void __cdecl calcTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime, Q1& timOut);
}
void __cdecl Q56::calcTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime, Q1& timOut)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();
    Q1 diff0;
    diff0.setSub4(reinterpret_cast<const Q1&>(st0.m_vCenterOfMass0), reinterpret_cast<const Q1&>(st0.m_vCenterOfMass1));
    Q1 diff1;
    diff1.setSub4(reinterpret_cast<const Q1&>(st1.m_vCenterOfMass1), reinterpret_cast<const Q1&>(st1.m_vCenterOfMass0));
    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();
    timOut.setMul4(f0, diff0);
    timOut.addMul4(f1, diff1);
    timOut(3) = f0 * ms0.m_kDeltaAngle(3) * ms0.m_fObjectRadius + f1 * ms1.m_kDeltaAngle(3) * ms1.m_fObjectRadius;
}
struct Q18 : Q21
{
    Q53 q69;
};
struct Q2 : Q18
{
    Q49 m_uiEntryValue;
};
struct Q22 : Q18
{
    hkTime q17;
    Q1 InvokeFifthVirtualFunction;
};
struct Q32
{
};
typedef Q10* (*Q78)(Q32& vin, Q18* entry, Q10* agentData);
extern "C"
{
    void __cdecl Q171(AgentSectorPointerArray& agentTrack);
    enum Q194
    {
        HKP_AGENT_MACHINE_MODE_1N = 1,
        HKP_AGENT_MACHINE_MODE_NM = 2
    };
    void __cdecl Q163(AgentSectorPointerArray& agentTrack, const Q14& input, const hkpShapeContainer* shapeContainerA, const hkpShapeContainer* shapeCollectionB,
                      const Q53* hitList, Q6& output);
    void __cdecl Q107(AgentSectorPointerArray& agentTrack, Q32& vin);
    void __cdecl Q108(AgentSectorPointerArray& agentTrack, Q32& vin);
    void __cdecl Q143(AgentSectorPointerArray& agentTrack, Q32& vin, Q46* mgr, Q78 visitor);
    void __cdecl Q164(AgentSectorPointerArray& agentTrack, hkpCollisionDispatcher* dispatch, Q46* mgr, Q51& constraintOwner);
    void __cdecl Q147(AgentSectorPointerArray& track, const Q12& input);
    void __cdecl Q160(AgentSectorPointerArray& track, hkTime oldTime, hkTime newTime, const Q12& input);
    void __cdecl Q119(Q41& input, const hkpShapeContainer* shapeCollection, Q6& output);
    Q18* Q158(AgentSectorPointerArray& agentTrack, Q53 keyPair, Q10** agentDataOut);
}



namespace Q127 {
__forceinline hkpCollisionAgent*& __cdecl getChildAgent(Q10* agentData)
{
    return *reinterpret_cast<hkpCollisionAgent**>(agentData);
}
__forceinline Q10* __cdecl getAgentDataEnd(Q10* agentData)
{
    return Q11(agentData, (((sizeof(getChildAgent(agentData))) + ((16) - 1)) & (~((16) - 1))));
}
}
extern "C"
{
    const hkpCdBody* __cdecl Q43(const hkpCdBody* cdBody, hkpCdBody* newCdBodies, hkMotionState* newMotionStates, int numSlots,
                          Q20<Q42>& cdBodyHasTransformFlag);
}

struct Q58
{
    hkpCdBody q72;
    hkpCdBody q65;
    Q28 q172;
    Q28 q173;
};
static __declspec(noinline) void Q54(Q41& in, Q58& bodyTemp, Q41& out)
{
    Q56::ComputeTransformAtTime(in.q72->GetMotionState()->getSweptTransform(), GetStepTime(in.q34->q64.m_uiStartTime), bodyTemp.q172);
    Q56::ComputeTransformAtTime(in.q65->GetMotionState()->getSweptTransform(), GetStepTime(in.q34->q64.m_uiStartTime), bodyTemp.q173);
    out.q72 = &bodyTemp.q72;
    out.q65 = &bodyTemp.q65;
    out.q59 = in.q59;
    out.q34 = in.q34;
    bodyTemp.q72.SetCollisionShapeAndKey(in.q72->getShape(), in.q72->getShapeKey());
    ::new (&bodyTemp.q72) hkpCdBody(in.q72, static_cast<const void*>(&bodyTemp.q172));
    ::new (&bodyTemp.q65) hkpCdBody(in.q65, static_cast<const void*>(&bodyTemp.q173));
    out.m_kTransform.SetMulInverse(bodyTemp.q172, bodyTemp.q173);
}
static __declspec(noinline) void Q50(Q14& in, Q14& out)
{
    out.q72 = in.q65;
    out.q65 = in.q72;
    out.q34 = in.q34;
    out.q59 = in.q59;
    out.q76.setNeg3(in.q76);
    out.m_kTransform.SetConjugate(in.m_kTransform);
}
class Q120
{
  public:
    __forceinline bool operator==(const Q53& p)
    {
        return q23 == p.q23;
    }
    __forceinline bool operator>(const Q53& p)
    {
        return q23 > p.q23;
    }
    __forceinline void operator=(const Q53& p)
    {
        q23 = p.q23;
    }
    __forceinline void writeTo(Q53& p)
    {
        p.q186 = 0xffffffff;
        p.q23 = q23;
    }
    Q20<Q26> q23;
};
// The shared container names the welding-query slot vf06.
static __forceinline bool IsWeldingEnabled(const hkpShapeContainer* container)
{
    typedef bool (__thiscall* Query)(const hkpShapeContainer*);
    return reinterpret_cast<Query>((*reinterpret_cast<void* const* const*>(container))[6])(container);
}
static __forceinline void extractChildShapes(Q26 key, const hkpShapeContainer* container, Q95& buffer, hkpCdBody& childBody)
{
    const hkpShape* childShape = container->GetShapeForKey(key, buffer);
    childBody.SetCollisionShapeAndKey(childShape, key);
}
static __forceinline void fixupPotentialContactPointers(const Q150* bufferIn, void* bufferOut, int size,
                                                        Q6::ContactPointBuffer* potentialInfo)
{
    if (potentialInfo)
    {
        for (Q6::ContactPointAgentEntry* ref = &potentialInfo->q9[0]; ref < potentialInfo->q29; ref++)
        {
            long offset = Q19(bufferIn, ref->q94);
            if (offset >= 0 && offset < size)
            {
                ref->q94 = reinterpret_cast<Q21*>(Q11(bufferOut, offset));
                ref->q110 = Q11(bufferOut, Q19(bufferIn, ref->q110));
            }
        }
    }
}
// @fnv 0x00da4aa0
// src: XBOX_PDB 0x00da4aa0
void __cdecl hkAgent1nMachine_Process(AgentSectorPointerArray& agentTrack, const Q14& inputIn, const hkpShapeContainer* shapeContainerB, const Q26* newKeys,
                          Q6& output)
{
    MathUtilities::prefetch128(reinterpret_cast<Q155<hkpAgent1nSector*>&>(agentTrack.m_kSectors).begin());
    Q6::ContactPointBuffer potentialContacts;
    Q6::ContactPointBuffer* oldPotentialInfo = output.q9;
    if (!oldPotentialInfo && IsWeldingEnabled(shapeContainerB))
    {
        potentialContacts.reset();
        output.q9 = &potentialContacts;
    }
    else
    {
        output.q9 = 0;
    }
    Q14 input;
    Q88::memCpy16NonEmpty(&input, &inputIn, sizeof(Q14) / 16);
    hkpCollisionDispatcher* dispatcher = input.q34->q176;
    const int numSlotsForTransformedCdBodies = 4;
    hkMotionState transformForTransformedShapeB[numSlotsForTransformedCdBodies];
    hkpCdBody cdBodyForTransformedShapeB[numSlotsForTransformedCdBodies];
    Q20<const hkpCdBody*>* modifiedBodyBPtr = &input.q65;
    Q20<const hkpCdBody*>* modifiedBodyAPtr = &input.q72;
    hkpCdBody childBodyB(inputIn.q65);
    *modifiedBodyBPtr = &childBodyB;
    ;
    int numTim = 0;
    hkpAgent1nSector* readSector = reinterpret_cast<Q155<hkpAgent1nSector*>&>(agentTrack.m_kSectors)[0];
    MathUtilities::forcePrefetch<512>(readSector);
    hkpAgent1nSector* currentSector = (input.q34->q27) ? input.q34->q27 : ::new (hkpAgent1nSector::operator new(hkpAgent1nSector::SECTOR_SIZE))
            hkpAgent1nSector;
    input.q34->q27 = 0;
    int currentSectorIndex = 0;
    bool prevInputInitialized = false;
    bool prevFlippedInputInitialized = false;
    Q41 prevInput;
    Q41 prevFlippedInput;
    Q58 prevTemp;
    Q58 prevFlippedTemp;
    __declspec(align(16)) Q42 extensionBuffer[Q7::MAX_TOTAL_SIZE];
    bool inExtensionBuffer = false;
    int nextReadSectorIndex = 1;
    void* readData = readSector->getBegin();
    void* readEnd = readSector->GetStreamEnd();
    void* currentData = currentSector->getBegin();
    void* currentDataEnd = currentSector->getEndOfCapacity();
    int bytesUsedInCurrentSector = 0;
    Q95 shapeBufferB;
    while (1)
    {
        Q120 shapeKeyPair;
        *modifiedBodyBPtr = &childBodyB;
        input.m_kTransform = inputIn.m_kTransform;
        if (!newKeys)
        {
            Q18* entry = reinterpret_cast<Q18*>(readData);
            int entrySize = entry->m_iElementCount;
            Q88::memCpy16NonEmpty(currentData, readData, entrySize >> 4);
            readData = Q11(readData, entrySize);
            shapeKeyPair = entry->q69;
        }
        else
        {
            Q18* readHeader = reinterpret_cast<Q18*>(readData);
            shapeKeyPair.q23 = *newKeys;
            if (shapeKeyPair == readHeader->q69)
            {
                int size = readHeader->m_iElementCount;
                Q88::memCpy16NonEmpty(currentData, readData, size >> 4);
                readData = Q11(readData, size);
                newKeys++;
            }
            else if (shapeKeyPair > readHeader->q69)
            {
                void* agentData = ((readHeader->q74 & 6) == Q7::STREAM_CALL_WITH_TIM)
                                      ? (void*)Q11(readHeader, sizeof(Q22))
                                      : (void*)Q11(readHeader, sizeof(Q2));
                readData = Q11(readData, readHeader->m_iElementCount);
                fnv_00da4aa0::GetAgent3DestroyFunc(dispatcher, readHeader->q38)(readHeader, agentData, input.q59, *output.q84.val(),
                                                                  dispatcher);
                goto checkReadSector;
            }
            else
            {
                if (input.q34->m_iFilter->IsCollisionEnabled(reinterpret_cast<const CollisionAgentContext&>(*input.q34), *inputIn.q72, *inputIn.q65, *shapeContainerB,
                                                             shapeKeyPair.q23))
                {
                    if (Q93(18))
                    {
                        newKeys++;
                        goto checkReadSector;
                    }
                    extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                    const hkpShape* shapeB = (*modifiedBodyBPtr)->m_pCollisionShape;
                    const hkpShape* shapeA = (*modifiedBodyAPtr)->m_pCollisionShape;
                    Q20<Q42> cdBodyHasTransformFlag = 0;
                    *modifiedBodyBPtr =
                        Q43(*modifiedBodyBPtr, cdBodyForTransformedShapeB, transformForTransformedShapeB,
                            numSlotsForTransformedCdBodies, cdBodyHasTransformFlag);
                    shapeB = (*modifiedBodyBPtr)->m_pCollisionShape;
                    input.m_kTransform.SetMulInverse(reinterpret_cast<const Q28&>((*modifiedBodyAPtr)->getTransform()),
                                                     reinterpret_cast<const Q28&>((*modifiedBodyBPtr)->getTransform()));
                    Q18* h = reinterpret_cast<Q18*>(currentData);
                    shapeKeyPair.writeTo(h->q69);
                    h->q38 = Q42(dispatcher->getAgent3Type(shapeA->getType(), shapeB->getType(), input.q34->q102));
                    h->q75 = 0;
                    Q14 flippedInput;
                    Q14* in = &input;
                    int isFlipped = 0;
                    if (fnv_00da4aa0::GetAgent3Symmetric(dispatcher, h->q38) == Q7::IS_NOT_SYMMETRIC_AND_FLIPPED)
                    {
                        isFlipped = 1;
                        in = &flippedInput;
                        Q50(input, flippedInput);
                    }
                    if (fnv_00da4aa0::GetAgent3SepNormalFunc(dispatcher, h->q38))
                    {
                        Q22* entry = reinterpret_cast<Q22*>(currentData);
                        entry->q74 = Q42(Q7::STREAM_CALL_WITH_TIM + isFlipped) | cdBodyHasTransformFlag;
                        entry->q17 = -1.0f;
                        entry->InvokeFifthVirtualFunction.setZero4();
                        void* agentData = entry + 1;
                        void* agentEnd = fnv_00da4aa0::GetAgent3CreateFunc(dispatcher, entry->q38)(*in, entry, agentData);
                        Q165 size = Q19(entry, agentEnd);
                        entry->m_iElementCount = Q42(size);
                        ;
                    }
                    else
                    {
                        Q2* entry = reinterpret_cast<Q2*>(currentData);
                        entry->q74 = Q42(Q7::STREAM_CALL + isFlipped) | cdBodyHasTransformFlag;
                        void* agentData = entry + 1;
                        void* agentEnd = fnv_00da4aa0::GetAgent3CreateFunc(dispatcher, entry->q38)(*in, entry, agentData);
                        Q165 size = Q19(entry, agentEnd);
                        entry->m_iElementCount = Q42(size);
                        ;
                    }
                }
                else
                {
                    Q2* h = reinterpret_cast<Q2*>(currentData);
                    *reinterpret_cast<Q49*>(h) = 0;
                    shapeKeyPair.writeTo(h->q69);
                    h->m_iElementCount = sizeof(Q2);
                }
                newKeys++;
            }
        }
        {
            bool thisChildHasTransformApplied = false;
            Q7::StreamCommand command = Q7::StreamCommand(reinterpret_cast<Q21*>(currentData)->q74);
        commandSwitch:
            switch (command)
            {
            case Q7::STREAM_CALL_WITH_TRANSFORM:
            case Q7::STREAM_CALL_FLIPPED_WITH_TRANSFORM:
            case Q7::STREAM_CALL_WITH_TIM_WITH_TRANSFORM:
            case Q7::STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM:
            case Q7::STREAM_CALL_AGENT_WITH_TRANSFORM: {
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                Q20<Q42> dummyCdBodyHasTransformFlag = 0;
                *modifiedBodyBPtr = Q43(*modifiedBodyBPtr, cdBodyForTransformedShapeB, transformForTransformedShapeB,
                                        numSlotsForTransformedCdBodies, dummyCdBodyHasTransformFlag);
                input.m_kTransform.SetMulInverse(reinterpret_cast<const Q28&>((*modifiedBodyAPtr)->getTransform()),
                                                 reinterpret_cast<const Q28&>((*modifiedBodyBPtr)->getTransform()));
                command = Q7::StreamCommand(Q42(command) & Q42(~Q7::TRANSFORM_FLAG));
                thisChildHasTransformApplied = true;
                prevFlippedInputInitialized = false;
                prevInputInitialized = false;
                goto commandSwitch;
            }
            case Q7::STREAM_CALL_AGENT: {
                Q2* paddedEntry = reinterpret_cast<Q2*>(currentData);
                void* agentData = paddedEntry + 1;
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                hkpCollisionAgent* agent = Q127::getChildAgent(agentData);
                ProcessCollisionAgent(agent, **modifiedBodyAPtr, **modifiedBodyBPtr, *input.q34, output);
                currentData = Q127::getAgentDataEnd(agentData);
                break;
            }
            case Q7::STREAM_CALL: {
                Q2* entry = reinterpret_cast<Q2*>(currentData);
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                void* agentData = entry + 1;
                currentData = fnv_00da4aa0::GetAgent3ProcessFunc(dispatcher, entry->q38)(input, entry, agentData, 0, output);
                entry->m_iElementCount = Q42(Q19(entry, currentData));
                break;
            }
            case Q7::STREAM_CALL_FLIPPED: {
                Q14 flippedInput;
                Q50(input, flippedInput);
                Q2* entry = reinterpret_cast<Q2*>(currentData);
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                hkReal oldToi = output.m_fTimeOfImpact.m_uiCommandId;
                void* agentData = entry + 1;
                Q40* oldResultBegin = output.q47;
                currentData = fnv_00da4aa0::GetAgent3ProcessFunc(dispatcher, entry->q38)(flippedInput, entry, agentData, 0, output);
                entry->m_iElementCount = Q42(Q19(entry, currentData));
                while (oldResultBegin < output.q47)
                {
                    oldResultBegin->q181.flip();
                    oldResultBegin++;
                }
                if (oldToi != output.m_fTimeOfImpact.m_uiCommandId)
                {
                    output.m_fTimeOfImpact.flip();
                }
                break;
            }
            case Q7::STREAM_CALL_WITH_TIM_FLIPPED: {
                Q14 flippedInput;
                Q50(input, flippedInput);
                Q22* entry = reinterpret_cast<Q22*>(currentData);
                hkReal distAtT1;
                if (entry->q17 != GetStepTime(flippedInput.q34->q64.m_uiStartTime))
                {
                    const Q61* ci = flippedInput.q34->q81;
                    if (!ci->q79.val())
                    {
                        entry->q17 = GetStepTime(flippedInput.q34->q64.m_fEndTime);
                        distAtT1 = ci->q116 * 0.5f;
                        entry->InvokeFifthVirtualFunction.setZero4();
                        entry->InvokeFifthVirtualFunction(3) = distAtT1;
                        goto PROCESS_AT_T1_FLIPPED;
                    }
                    if (!prevFlippedInputInitialized)
                    {
                        prevFlippedInputInitialized = !thisChildHasTransformApplied;
                        Q54(flippedInput, prevFlippedTemp, prevFlippedInput);
                        prevFlippedTemp.q65.SetCollisionShapeAndKey(flippedInput.q65->getShape(),
                                                                    flippedInput.q65->m_uiCollisionShapeKey);
                    }
                    extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                    prevFlippedTemp.q72.SetCollisionShapeAndKey((*modifiedBodyBPtr)->m_pCollisionShape, (*modifiedBodyBPtr)->m_uiCollisionShapeKey);
                    void* agentData = entry + 1;
                    fnv_00da4aa0::GetAgent3SepNormalFunc(dispatcher, entry->q38)(prevFlippedInput, entry, agentData,
                                                                   entry->InvokeFifthVirtualFunction);
                }
                entry->q17 = GetStepTime(flippedInput.q34->q64.m_fEndTime);
                {
                    hkReal worstCaseDeltaDist = flippedInput.q76.dot4xyz1(entry->InvokeFifthVirtualFunction);
                    distAtT1 = entry->InvokeFifthVirtualFunction(3) - worstCaseDeltaDist;
                }
                if (distAtT1 >= flippedInput.q34->getTolerance())
                {
                    entry->InvokeFifthVirtualFunction(3) = distAtT1;
                    if (!entry->q75)
                    {
                        currentData = Q11(currentData, entry->m_iElementCount);
                    }
                    else
                    {
                        void* agentData = entry + 1;
                        currentData = fnv_00da4aa0::GetAgent3CleanupFunc(dispatcher, entry->q38)(entry, agentData, flippedInput.q59,
                                                                                   *output.q84.val());
                        entry->m_iElementCount = Q42(Q19(entry, currentData));
                    }
                    numTim++;
                    break;
                }
            PROCESS_AT_T1_FLIPPED:
                flippedInput.q162 = distAtT1;
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                Q40* oldResultBegin = output.q47;
                hkReal oldToi = output.m_fTimeOfImpact.m_uiCommandId;
                void* agentData = entry + 1;
                currentData = fnv_00da4aa0::GetAgent3ProcessFunc(dispatcher, entry->q38)(flippedInput, entry, agentData,
                                                                           &entry->InvokeFifthVirtualFunction, output);
                entry->m_iElementCount = Q42(Q19(entry, currentData));
                while (oldResultBegin < output.q47)
                {
                    oldResultBegin->q181.flip();
                    oldResultBegin++;
                }
                if (oldToi != output.m_fTimeOfImpact.m_uiCommandId)
                {
                    output.m_fTimeOfImpact.flip();
                }
                break;
            }
            case Q7::STREAM_CALL_WITH_TIM: {
                Q22* entry = reinterpret_cast<Q22*>(currentData);
                hkReal distAtT1;
                if (entry->q17 != GetStepTime(input.q34->q64.m_uiStartTime))
                {
                    if (entry->q17 >= GetStepTime(input.q34->q64.m_fEndTime))
                    {
                        hkReal backDt = entry->q17 - GetStepTime(input.q34->q64.m_fEndTime);
                        Q1 backTim;
                        Q56::calcTimInfo(*input.q72->GetMotionState(), *input.q65->GetMotionState(), backDt, backTim);
                        hkReal backLinear = backTim.dot3(entry->InvokeFifthVirtualFunction);
                        hkReal backAng = backTim(3);
                        distAtT1 = entry->InvokeFifthVirtualFunction(3) + backLinear - backAng;
                    }
                    else
                    {
                        const Q61* ci = input.q34->q81;
                        if (!ci->q79.val())
                        {
                            entry->q17 = GetStepTime(input.q34->q64.m_fEndTime);
                            distAtT1 = ci->q116 * 0.1f;
                            entry->InvokeFifthVirtualFunction.setZero4();
                            entry->InvokeFifthVirtualFunction(3) = distAtT1;
                            goto PROCESS_AT_T1;
                        }
                        if (!prevInputInitialized)
                        {
                            prevInputInitialized = !thisChildHasTransformApplied;
                            Q54(input, prevTemp, prevInput);
                        }
                        extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                        prevTemp.q65.SetCollisionShapeAndKey((*modifiedBodyBPtr)->m_pCollisionShape, (*modifiedBodyBPtr)->m_uiCollisionShapeKey);
                        void* agentData = entry + 1;
                        fnv_00da4aa0::GetAgent3SepNormalFunc(dispatcher, entry->q38)(prevInput, entry, agentData,
                                                                       entry->InvokeFifthVirtualFunction);
                    }
                }
                entry->q17 = GetStepTime(input.q34->q64.m_fEndTime);
                {
                    hkReal worstCaseDeltaDist = input.q76.dot4xyz1(entry->InvokeFifthVirtualFunction);
                    distAtT1 = entry->InvokeFifthVirtualFunction(3) - worstCaseDeltaDist;
                }
                if (distAtT1 >= input.q34->getTolerance())
                {
                    entry->InvokeFifthVirtualFunction(3) = distAtT1;
                    if (!entry->q75)
                    {
                        currentData = Q11(currentData, entry->m_iElementCount);
                    }
                    else
                    {
                        void* agentData = entry + 1;
                        currentData = fnv_00da4aa0::GetAgent3CleanupFunc(dispatcher, entry->q38)(entry, agentData, input.q59,
                                                                                   *output.q84.val());
                        entry->m_iElementCount = Q42(Q19(entry, currentData));
                    }
                    numTim++;
                    break;
                }
            PROCESS_AT_T1:
                input.q162 = distAtT1;
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                void* agentData = entry + 1;
                currentData = fnv_00da4aa0::GetAgent3ProcessFunc(dispatcher, entry->q38)(input, entry, agentData,
                                                                           &entry->InvokeFifthVirtualFunction, output);
                entry->m_iElementCount = Q42(Q19(entry, currentData));
                break;
            }
            case Q7::STREAM_NULL: {
                currentData = Q11(currentData, sizeof(Q2));
                break;
            }
            case Q7::STREAM_END: {
                currentData = Q11(currentData, sizeof(Q2));
                break;
            }
            default:;
            }
        }
    checkReadSector:;
        if (readData == readEnd)
        {
            if (input.q34->q27)
            {
                delete readSector;
            }
            else
            {
                input.q34->q27 = readSector;
            }
            if (nextReadSectorIndex < reinterpret_cast<Q155<hkpAgent1nSector*>&>(agentTrack.m_kSectors).GetLogicalSize())
            {
                readSector = reinterpret_cast<Q155<hkpAgent1nSector*>&>(agentTrack.m_kSectors)[nextReadSectorIndex];
                readData = readSector->getBegin();
                readEnd = readSector->GetStreamEnd();
                nextReadSectorIndex++;
            }
            else
            {
                break;
            };
        }
        if (Q11(currentData, Q7::MAX_TOTAL_SIZE) <= currentDataEnd)
        {
            continue;
        }
        if (!inExtensionBuffer)
        {
            inExtensionBuffer = true;
            bytesUsedInCurrentSector = Q19(currentSector->getBegin(), currentData);
            ;
            currentData = extensionBuffer;
            currentDataEnd = Q11(extensionBuffer, Q7::MAX_TOTAL_SIZE);
            continue;
        }
        int bytesUsedInExtensionBuffer;
        bytesUsedInExtensionBuffer = Q19(extensionBuffer, currentData);
        {
            int freeBytes = currentSector->getCapacity() - bytesUsedInCurrentSector;
            if (bytesUsedInExtensionBuffer <= freeBytes)
            {
                void* dst = Q11(static_cast<void*>(currentSector->getBegin()), bytesUsedInCurrentSector);
                Q88::memCpy16NonEmpty(dst, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
                bytesUsedInCurrentSector += bytesUsedInExtensionBuffer;
                fixupPotentialContactPointers(extensionBuffer, dst, bytesUsedInExtensionBuffer, output.q9);
                if (bytesUsedInCurrentSector < currentSector->getCapacity())
                {
                    currentData = extensionBuffer;
                    continue;
                }
                inExtensionBuffer = false;
                currentData = 0;
                currentDataEnd = 0;
            }
        }
        currentSector->m_uiAgentCount = bytesUsedInCurrentSector;
        if (currentSectorIndex >= nextReadSectorIndex)
        {
            reinterpret_cast<Q155<hkpAgent1nSector*>&>(agentTrack.m_kSectors).expandAt(nextReadSectorIndex, 1);
            nextReadSectorIndex++;
        }
        reinterpret_cast<Q155<hkpAgent1nSector*>&>(agentTrack.m_kSectors)[currentSectorIndex] = currentSector;
        ;
        currentSectorIndex++;
        currentSector = (input.q34->q27) ? input.q34->q27 : ::new (hkpAgent1nSector::operator new(hkpAgent1nSector::SECTOR_SIZE))
            hkpAgent1nSector;
        input.q34->q27 = 0;
        currentData = currentSector->getBegin();
        currentDataEnd = currentSector->getEndOfCapacity();
        if (inExtensionBuffer)
        {
            Q88::memCpy16NonEmpty(currentData, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
            fixupPotentialContactPointers(extensionBuffer, currentData, bytesUsedInExtensionBuffer, output.q9);
            currentData = Q11(currentData, bytesUsedInExtensionBuffer);
            inExtensionBuffer = false;
        }
    }
    if (!inExtensionBuffer)
    {
        bytesUsedInCurrentSector = Q19(currentSector->getBegin(), currentData);
    }
    else
    {
        int bytesUsedInExtensionBuffer = Q19(extensionBuffer, currentData);
        ;
        void* dst = Q11(static_cast<void*>(currentSector->getBegin()), bytesUsedInCurrentSector);
        Q88::memCpy16NonEmpty(dst, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
        Q6::ContactPointBuffer* potentialInfo = output.q9;
        if (potentialInfo)
        {
            if (potentialInfo->q29 > &potentialInfo->q9[0])
            {
                Q6::ContactPointAgentEntry* lastContactRef = potentialInfo->q29 - 1;
                long offsetInExtensionBuffer = Q19(extensionBuffer, lastContactRef->q94);
                if (offsetInExtensionBuffer >= 0 && offsetInExtensionBuffer < bytesUsedInExtensionBuffer)
                {
                    ;
                    lastContactRef->q94 = reinterpret_cast<Q21*>(Q11(dst, offsetInExtensionBuffer));
                    lastContactRef->q110 = Q11(dst, Q19(extensionBuffer, lastContactRef->q110));
                }
            }
        }
        bytesUsedInCurrentSector += bytesUsedInExtensionBuffer;
    };
    currentSector->m_uiAgentCount = bytesUsedInCurrentSector;
    reinterpret_cast<Q155<hkpAgent1nSector*>&>(agentTrack.m_kSectors).SetSizeAndGrow(currentSectorIndex + 1);
    reinterpret_cast<Q155<hkpAgent1nSector*>&>(agentTrack.m_kSectors)[currentSectorIndex] = currentSector;
    ;
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::AddValueCommand* h = reinterpret_cast<hkMonitorStream::AddValueCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "M"
                      "i"
                      "numTim";
            h->m_value = float(numTim);
            mStream.setEnd((char*)(h + 1));
        }
    };
    ;
    input.q65 = inputIn.q65;
    input.m_kTransform = inputIn.m_kTransform;
    if (output.q9)
    {
        if (output.q9->q29 > &output.q9->q9[0])
        {
            Q119(input, shapeContainerB, output);
        }
    }
    output.q9 = oldPotentialInfo;
}
}  // namespace fnv_00da4aa0
