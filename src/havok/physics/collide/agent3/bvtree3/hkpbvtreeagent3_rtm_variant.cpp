#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// Preserve this RTM unit's intrinsic type; the SDK union adds array members
// that make VC9 insert stack checks into the original unchecked routine.
#define _INCLUDED_MM2
// Exe 0x00d2d4f0 FUN_00d2d4f0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct { float x, y, z, w; };
} __m128, LocalM128;
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
#include "../../../../../../include/hkStackMemory.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkMotionState.h"
#include "../../../../../../include/hkStepInfo.h"
#include "../../../../../../include/hkSweptTransform.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpBvTreeShape.h"
#include "../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../include/FinishingFlag.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkQuaternion.h"
// src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void* __cdecl InitAndReturnTail(void*, void*, void*);
void __fastcall hkBvTreeAgent3_process(void* self, int, void*, int);
void __fastcall CallWithValueSource(void* self, int, int, int);
void __fastcall hkBvTreeAgent3_ProcessState_00d2d430(void* self, int, int, int);
void __fastcall Object__hkAgent1nMachine_WarpTime_Thunk(void* self, int, int, int);
void hkBvTreeAgent3_process_UpdateState_00d2d9d0(void* pObject);
extern "C" void __cdecl _hkAgent1nMachine_WarpTime(void*, float, float, int);
void __cdecl Object__hkAgent1nMachine_WarpTime_Thunk(void*, void* target, float first, float second, int flags);
// Exe 0x00d2da70: unit-local Interface view; declarations and layout are preserved.
struct Hkpbvtreeagent3InterfaceView
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
void Hkpbvtreeagent3_ForwardCall_00d2d4b0(Hkpbvtreeagent3InterfaceView** a);
struct LessU32
{
    int pad;
    bool operator()(unsigned a, unsigned b) const
    {
        return a < b;
    }
};
// Partitions pArr[d..h] around a middle pivot using cmpLess, swapping out-of-order elements, then recurses on the left part and loops on the right.
// @fnv 0x00d2da70
extern "C" void __cdecl QuickSortRange(unsigned* auiArray, int aiLow, int aiHigh, LessU32 aComparator)
{
setpoint:
    int iRight = aiHigh;
    int iLeft = aiLow;
    __declspec(align(16)) unsigned pivot = auiArray[(aiLow + aiHigh) >> 1];
    do
    {
        while (aComparator(auiArray[iLeft], pivot))
            iLeft++;
        while (aComparator(pivot, auiArray[iRight]))
            iRight--;
        if (iRight >= iLeft)
        {
            if (iRight != iLeft)
            {
                unsigned t = auiArray[iRight];
                auiArray[iRight] = auiArray[iLeft];
                auiArray[iLeft] = t;
            }
            iRight--;
            iLeft++;
        }
    } while (iLeft <= iRight);
    if (aiLow < iRight)
        QuickSortRange(auiArray, aiLow, iRight, aComparator);
    if (iLeft < aiHigh)
    {
        aiLow = iLeft;
        goto setpoint;
    }
}
struct ValueSource
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
};
struct CallBuf
{
    int unk00;
    ValueSource** unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(void* a, void* b);
void __cdecl CallWithValueSource(void* apUnused, void* p2, int aiArg0, ValueSource** apValueSource, int aiArg1,
                                 int aiArg2, int aiArg3);
struct SpawnedObject
{
    int unk00;
    int unk04;
    int unk08;
    int m_kind;            // 0x0c
    unsigned char m_flag;  // 0x10
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    void* m_ptr18;  // 0x18
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* m_ptr34;  // 0x34
};
void* __cdecl GetSpawnedObjectPointer(void** holder);
struct Agent
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(const char* typeName);
    virtual void f7();
};
extern "C" void __cdecl hkpAgentMachineUtil_calc1nStatistics(int, int, void*);
extern "C" void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(int, int);
void __cdecl hkBvTreeAgent3_ProcessState_00d2d430(int a1, int a2, int a3, Agent* p);
// src: GUESS 0x00d2d460 (confidence: low)
void __cdecl Object_ForwardCall_00d2d460(int a, int b, int c)
{
    hkpAgent1nSector_ProcessEntries_00da3510(b, c);
}
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" const char str_010ce7ec[];
extern "C" const char str_010ce7e0[];
extern "C" const char str_010ce7d4[];
extern "C" const char str_01076f38[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
struct S00d2d890_Rec
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
    const char* tag;
};
struct S00d2d890_Buf
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct S00d2d890_Hits
{
    int q000;
    int q001;
    int q002;
    int q003;
    int q004;
    int q005;
    int q006;
    int q007;
    int q008;
    int q009;
    int q00a;
    int q00b;
    int q00c;
    int q00d;
    int q00e;
    int q00f;
    int q010;
    int q011;
    int q012;
    int q013;
    int q014;
    int q015;
    int q016;
    int q017;
    int q018;
    int q019;
    int q01a;
    int q01b;
    int q01c;
    int q01d;
    int q01e;
    int q01f;
    int q020;
    int q021;
    int q022;
    int q023;
    int q024;
    int q025;
    int q026;
    int q027;
    int q028;
    int q029;
    int q02a;
    int q02b;
    int q02c;
    int q02d;
    int q02e;
    int q02f;
    int q030;
    int q031;
    int q032;
    int q033;
    int q034;
    int q035;
    int q036;
    int q037;
    int q038;
    int q039;
    int q03a;
    int q03b;
    int q03c;
    int q03d;
    int q03e;
    int q03f;
    int q040;
    int q041;
    int q042;
    int q043;
    int q044;
    int q045;
    int q046;
    int q047;
    int q048;
    int q049;
    int q04a;
    int q04b;
    int q04c;
    int q04d;
    int q04e;
    int q04f;
    int q050;
    int q051;
    int q052;
    int q053;
    int q054;
    int q055;
    int q056;
    int q057;
    int q058;
    int q059;
    int q05a;
    int q05b;
    int q05c;
    int q05d;
    int q05e;
    int q05f;
    int q060;
    int q061;
    int q062;
    int q063;
    int q064;
    int q065;
    int q066;
    int q067;
    int q068;
    int q069;
    int q06a;
    int q06b;
    int q06c;
    int q06d;
    int q06e;
    int q06f;
    int q070;
    int q071;
    int q072;
    int q073;
    int q074;
    int q075;
    int q076;
    int q077;
    int q078;
    int q079;
    int q07a;
    int q07b;
    int q07c;
    int q07d;
    int q07e;
    int q07f;
};
struct S00d2d890_Rec3
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
};
struct S00d2d890_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
char** hkMemoryRouter_getInstance();
int hkpCdBody_UpdateState_00d2d4f0(int a, int b, hkTransform* l, void* c, int d, int e, char* f, int g);
int Hkpbvtreeagent3_ForwardCall_00d2d4b0(int a, S00d2d890_Hits* h);
int hkAgent1nMachine_Process(int a, void* b, int c, char* d, int e);
char* __cdecl hkBvTreeAgent3_process(char* self, int a1, char* child, int a3, int a4);
__declspec(noinline) void hkBvTreeAgent3_process_UpdateState_00d2d9d0(void* pObject);
void hkBvTreeAgent3_registerAgent3(hkpCollisionDispatcher* target);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;
class hkStatisticsCollector;
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}

typedef LocalM128 hkQuadReal;
typedef const hkVector4& hkVector4Parameter;
typedef const hkSimdReal& hkSimdRealParameter;
class Vector4Comparison;
typedef const Vector4Comparison& hkVector4ComparisonParameter;
class Vector4Comparison
{
  public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_X = 1,
        MASK_Y = 2,
        MASK_XY = 3,
        MASK_Z = 4,
        MASK_XZ = 5,
        MASK_YZ = 6,
        MASK_XYZ = 7,
        MASK_W = 8,
        MASK_XW = 9,
        MASK_YW = 10,
        MASK_XYW = 11,
        MASK_ZW = 12,
        MASK_XZW = 13,
        MASK_YZW = 14,
        MASK_XYZW = 15
    };
    __forceinline void setAnd(hkVector4ComparisonParameter a, hkVector4ComparisonParameter b)
    {
        m_uiMask = _mm_and_ps(a.m_uiMask, b.m_uiMask);
    }
    __forceinline hkBool32 allAreSet(Mask m) const
    {
        return (_mm_movemask_ps(m_uiMask) & m) == m;
    }

  public:
    hkQuadReal m_uiMask;
    friend class hkVector4;
};
namespace MathUtilities {
template <typename T> inline T __cdecl min2(T x, T y)
{
    return x < y ? x : y;
}
}
__forceinline hkAabb::hkAabb() {}
__forceinline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x) {}
__forceinline hkSimdReal::hkSimdReal(float x) { m_vValue = _mm_load_ss(&x); }
__forceinline LocalM128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
__forceinline const hkQuadReal& hkVector4::getQuad() const
{
    return m_vComponents;
}
static __forceinline void SetAll3(hkVector4& out, hkReal a)
{
    out.m_vComponents = _mm_set_ps1(a);
}
__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
__forceinline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}
__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}
__forceinline void hkVector4::sub4(const hkVector4& v)
{
    m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
}
__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
__forceinline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
__forceinline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
__forceinline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    hkQuadReal cross0;
    cross0 =
        _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))),
                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))));
    hkQuadReal cross1;
    cross1 =
        _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))),
                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
static __forceinline Vector4Comparison CompareLessThanEqual4(const hkVector4& v, const hkVector4& a)
{
    Vector4Comparison m;
    m.m_uiMask = _mm_cmple_ps(v.m_vComponents, a.m_vComponents);
    return m;
}
extern __declspec(align(16)) const hkUint32 DAT_010c44d0[4];
__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const hkQuadReal*)&DAT_010c44d0);
}
__forceinline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_min_ps(a.getQuad(), b.getQuad());
}
__forceinline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_max_ps(a.getQuad(), b.getQuad());
}
static __forceinline void SetRotatedInverseDir(hkVector4& out, const hkRotation& r, const hkVector4& b)
{
    hkQuadReal c0 = r.getColumn(0).m_vComponents;
    hkQuadReal c1 = r.getColumn(1).m_vComponents;
    hkQuadReal c2 = r.getColumn(2).m_vComponents;
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, (((3) << 6) | ((2) << 4) | ((1) << 2) | ((0))));
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, (((3) << 6) | ((1) << 4) | ((1) << 2) | ((0))));
        c2 = _ctmp;
    };
    const hkQuadReal b0 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
static __forceinline void SetTransformedInversePos(hkVector4& out, const hkTransform& a, const hkVector4& b)
{
    hkVector4 t0;
    t0.setSub4(b, a.getTranslation());
    SetRotatedInverseDir(out, a.getRotation(), t0);
}
__forceinline const hkReal& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
__forceinline const hkVector4& hkRotation::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
__forceinline const hkVector4& hkTransform::getTranslation() const
{
    return reinterpret_cast<const hkVector4&>(m_row3);
}
__forceinline const hkRotation& hkTransform::getRotation() const
{
    return reinterpret_cast<const hkRotation&>(m_row0);
}
__forceinline hkReal hkSweptTransform::getInvDeltaTime() const
{
    return m_vCenterOfMass1(3);
}
__forceinline const hkSweptTransform& hkMotionState::getSweptTransform() const
{
    return m_kSweptTransform;
}
__forceinline hkBool hkAabb::contains(const hkAabb& other) const
{
    Vector4Comparison mincomp = CompareLessThanEqual4(m_kMinimumCorner, other.m_kMinimumCorner);
    Vector4Comparison maxcomp = CompareLessThanEqual4(other.m_kMaximumCorner, m_kMaximumCorner);
    Vector4Comparison both;
    both.setAnd(mincomp, maxcomp);
    return both.allAreSet(Vector4Comparison::MASK_XYZ) != 0;
}
typedef hkUint16 hkContactPointId;
#include "../../../../../../include/hkpBufferSize.h"
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
typedef hkUint32 hkpShapeKey;
__forceinline void hkpShape::getAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
{
    CalculateAabb(localToWorld, tolerance, out);
}
const hkTransform& hkpCdBody::getTransform() const
{
    ;
    return *static_cast<const hkTransform*>(m_pMotionState);
}
const hkMotionState* hkpCdBody::GetMotionState() const
{
    return static_cast<const hkMotionState*>(m_pMotionState);
}
const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct CollisionAgentContext;
class hkpCollisionAgent;
struct FourByteState
{
};
struct AgentProcessingInput
{
};
struct AgentSubtypeMarker : public AgentProcessingInput
{
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
    hkPadSpu<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    hkPadSpu<hkBool32> m_collisionQuality;
    hkPadSpu<hkReal> m_fScalar;
    hkPadSpu<const hkpCollisionFilter*> m_iFilter;
    hkPadSpu<const hkpConvexListFilter*> m_pConvexListCollisionFilter;
    struct AabbBoundsAndScale
    {
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
                hkMemoryRouter::getInstance().heap().blockFree(
                    p, sizeof(CollisionAgentContext::AabbBoundsAndScale));
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
        hkVector4 m_kAabbMin;
        hkVector4 m_kAabbMaximum;
        hkVector4 m_kAabbScale;
    };
    AabbBoundsAndScale m_aiValues;
};
class hkpContactMgrFactory;
struct hkpAgent1nSector;
struct GskAgentInput : public CollisionAgentContext
{
  public:
    GskAgentInput() : m_pAgent1nSector(0)
    {}

  public:
    hkStepInfo m_pStepInfo;
    mutable hkPadSpu<hkpCollisionQualityInfo*> m_pCollisionQualityInfo;
    mutable hkpAgent1nSector* m_pAgent1nSector;
};
namespace hkBvTreeAgent3 {
hkpAgentData* __cdecl process(const AgentSubtypeMarker& input, FourByteState* entry, hkpAgentData* agentData,
                              hkVector4* separatingNormal, WorldOperationEntry& result);
void __cdecl RegisterAgentFunctions(hkpCollisionDispatcher* dispatcher);
void __cdecl InitAgentFunc(hkpCollisionDispatcher::Agent3FunctionTable& f);
void __cdecl CleanupAgent(FourByteState* entry, hkpAgentData* agentData, const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                          const CollisionAgentContext& input, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner);
void __cdecl AddStat(FourByteState* entry, hkpAgentData* agentData, const CollisionAgentContext& input,
                     hkStatisticsCollector* collector);
void __cdecl RemovePoint(FourByteState* entry, hkpAgentData* agentData, const CollisionAgentContext& input);
void __cdecl WarpTime(FourByteState* entry, hkpAgentData* agentData, hkTime oldTime, hkTime newTime,
                      const CollisionAgentContext& input);

const hkpShapeContainer* __cdecl GetContainerFromBody(const hkpCdBody* body, hkpShapeBuffer& buffer);
const hkpShapeCollection* __cdecl GetCollectionFromBody(const hkpCdBody* body,
                                                                                hkpShapeBuffer& buffer);
}
inline hkUint32 hkpBvTreeShape::GetAabbHits(const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys) const
{
    return GetAabbHitsToBuffer(aabb, hits, maxNumKeys);
}
namespace AlgorithmUtilities {
template <typename T> class less
{
  public:
    __forceinline hkBool32 operator()(const T& a, const T& b)
    {
        return (a < b);
    }
};
template <typename T> __forceinline void __cdecl quickSort(T* pArr, int iSize)
{
    quickSort(pArr, iSize, less<T>());
}
template <typename T, typename L> void __cdecl QuickSortSubrange(T* pArr, int d, int h, L cmpLess);
}
namespace AlgorithmUtilities {
template <typename T, typename L> void __cdecl quickSort(T* pArr, int iSize, L cmpLess)
{
    if (iSize > 1)
    {
        int low = 0;
        int high = iSize - 1;
        QuickSortSubrange(pArr, low, high, cmpLess);
    }
}
}
// @fnv 0x00d2d4f0
// src: GUESS 0x00d2d4f0 (confidence: low)
int __cdecl hkpCdBody_UpdateState_00d2d4f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkTransform& bTa,
                         const hkVector4& linearTimInfo, const GskAgentInput& input, hkAabb* cachedAabb,
                         hkpShapeKey* hitListOut, int hitListCapacity)
{
    hkAabb aabb;
    int numHits;
    {
        const hkMotionState* msA = bodyA.GetMotionState();
        const hkMotionState* msB = bodyB.GetMotionState();
        hkVector4 timInfo;
        SetRotatedInverseDir(timInfo, bodyB.getTransform().getRotation(), linearTimInfo);
        hkVector4 aabbExtents;
        if (input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
        {
            const hkReal secOrdErrA = (msA->m_kDeltaAngle(3) + msB->m_kDeltaAngle(3)) * msA->m_fObjectRadius;
            const hkReal secOrdErrB = msB->m_kDeltaAngle(3) * msB->m_kDeltaAngle(3) * msB->m_fObjectRadius;
            const hkReal checkEpsilon = input.m_fScalar * 0.5f + (secOrdErrA + secOrdErrB);
            bodyA.getShape()->getAabb(bTa, checkEpsilon, aabb);
            hkVector4 massCenterAinB;
            {
                hkVector4 radius4;
                SetAll3(radius4, input.m_fScalar * 0.5f + msA->m_fObjectRadius + secOrdErrB);
                SetTransformedInversePos(massCenterAinB, bodyB.getTransform(),
                                                         msA->getSweptTransform().m_vCenterOfMass1);
                hkVector4 maxR;
                maxR.setAdd4(massCenterAinB, radius4);
                hkVector4 minR;
                minR.setSub4(massCenterAinB, radius4);
                aabb.m_kMinimumCorner.setMax4(aabb.m_kMinimumCorner, minR);
                aabb.m_kMaximumCorner.setMin4(aabb.m_kMaximumCorner, maxR);
            }
            aabbExtents.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
            {
                if (msB->m_kDeltaAngle(3) > 0.0f)
                {
                    hkVector4 relPos;
                    relPos.setSub4(massCenterAinB, msB->getSweptTransform().m_vCenterOfMassLocal);
                    hkVector4 offsetOut;
                    offsetOut.setCross(relPos, msB->m_kDeltaAngle);
                    hkReal f = input.m_pStepInfo.m_fTimeStep * msB->getSweptTransform().getInvDeltaTime();
                    timInfo.addMul4(f, offsetOut);
                }
                hkVector4 zero;
                zero.setZero4();
                hkVector4 minPath;
                minPath.setMin4(zero, timInfo);
                hkVector4 maxPath;
                maxPath.setMax4(zero, timInfo);
                aabb.m_kMinimumCorner.add4(minPath);
                aabb.m_kMaximumCorner.add4(maxPath);
            }
        }
        else
        {
            const hkReal checkEpsilon = input.m_fScalar * 0.5f;
            bodyA.getShape()->getAabb(bTa, checkEpsilon, aabb);
            aabbExtents.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
        }
        if (cachedAabb)
        {
            if (cachedAabb->contains(aabb))
            {
                return -1;
            }
            {
                hkVector4 zero;
                zero.setZero4();
                hkVector4 minPath;
                minPath.setMin4(zero, timInfo);
                hkVector4 maxPath;
                maxPath.setMax4(zero, timInfo);
                hkVector4 expand4;
                SetAll3(expand4, input.m_fScalar * 0.5f);
                aabb.m_kMinimumCorner.sub4(expand4);
                aabb.m_kMaximumCorner.add4(expand4);
                const hkReal maxExpand = 0.4f;
                const hkReal framesLookAhead = -2.0f;
                hkVector4 minExtentPath;
                minExtentPath.setMul4(hkSimdReal(framesLookAhead), maxPath);
                hkVector4 maxExtentPath;
                maxExtentPath.setMul4(hkSimdReal(framesLookAhead), minPath);
                hkVector4 maxExpand4;
                maxExpand4.setMul4(hkSimdReal(maxExpand), aabbExtents);
                maxExtentPath.setMin4(maxExtentPath, maxExpand4);
                hkVector4 minExpand4;
                minExpand4.setNeg4(maxExpand4);
                minExtentPath.setMax4(minExtentPath, minExpand4);
                aabb.m_kMinimumCorner.add4(minExtentPath);
                aabb.m_kMaximumCorner.add4(maxExtentPath);
                *cachedAabb = aabb;
            }
        }
    }
    {
        const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>(bodyB.getShape());
        numHits = bvB->GetAabbHits(aabb, hitListOut, hitListCapacity);
    }
    if (numHits >= hitListCapacity)
    {
        const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>(bodyB.getShape());
        numHits =
            input.m_iFilter->FilterAabb(input, bodyA, bodyB, bvB, aabb, hitListOut, hitListCapacity);
        numHits = MathUtilities::min2(numHits, hitListCapacity - 1);
    }
    AlgorithmUtilities::quickSort(hitListOut, numHits);
    hitListOut[numHits] = 0xffffffff;
    return numHits;
}
