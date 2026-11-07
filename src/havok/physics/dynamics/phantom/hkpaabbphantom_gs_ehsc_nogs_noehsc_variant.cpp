
// src/havok/physics/dynamics/phantom/hkpaabbphantom_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/phantom/hkpaabbphantom.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/phantom/hkpaabbphantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpaabbphantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkpAabbPhantom.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpCdBody.h"
#include "../../../../../include/hkpCollisionFilter.h"
#include "../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../include/hkpShape.h"
#include "../../../../../include/hkpRayHitCollector.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkRotation.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkMonitorStream.h"

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned long DAT_0126835c;
extern float DAT_0104da4c;
extern const char str_010cbfd0[];
extern const char str_010c41f8[];

struct WorldRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    char m_pad21;
    char m_pad22;
    char m_pad23;
    hkUint32 m_uiFilterInfo;
};
struct __declspec(align(16)) ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct PadReal
{
    float v;
};
struct CollInput
{
    void* m_pCollisionDispatcher;
    int m_weld;
    PadReal m_fScalar;
    void* m_iFilter;
    void* m_pConvexListCollisionFilter;
    int m_createPredictive;
    hkVector4 m_aabb0;
    hkVector4 m_aabb1;
    hkVector4 m_aabb2;
    CollInput() : m_weld(0)
    {}
};
struct ProcInput : CollInput
{
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    hkVector4 unk60;
    void* m_pConfiguration;
};
struct LcInput : CollInput
{
    hkVector4 m_path;
    float m_fMaxExtraPenetration;
    float m_fStartPointTolerance;
    void* m_pConfiguration;
    LcInput()
    {
        m_fMaxExtraPenetration = DAT_0104da4c;
    }
    void set(const ProcInput& ci)
    {
        m_pCollisionDispatcher = ci.m_pCollisionDispatcher;
        m_weld = ci.m_weld;
        m_fScalar = ci.m_fScalar;
        m_iFilter = ci.m_iFilter;
        m_pConvexListCollisionFilter = ci.m_pConvexListCollisionFilter;
        m_createPredictive = ci.m_createPredictive;
        _mm_store_ps(m_aabb0.m_f, _mm_load_ps(ci.m_aabb0.m_f));
        _mm_store_ps(m_aabb1.m_f, _mm_load_ps(ci.m_aabb1.m_f));
        _mm_store_ps(m_aabb2.m_f, _mm_load_ps(ci.m_aabb2.m_f));
        m_pConfiguration = ci.m_pConfiguration;
    }
    void setTol(float tol)
    {
        m_fScalar.v = tol;
    }
};
struct LinCastInputS
{
    hkVector4 m_vTo;
    float m_fMaxExtraPenetration;
    float m_fMaxExtraPenetrationAgainstFixed;
};
struct FilterS
{
    virtual void unk0();
    virtual bool* IsCollisionEnabled(bool* r, const hkpCollidable& a, const hkpCollidable& b) const;
};
// The shared filter lacks the explicit result-buffer overload used by this unit.
struct CollFilterS : hkReferencedObject, FilterS
{
};
// The shared phantom header does not yet declare this linear-cast entry point.
struct PhantomS : hkpAabbPhantom
{
    void hkpAabbPhantom_linearCast(const hkpCollidable* collA, const LinCastInputS& input, void* castCollector, void* startCollector);
};
// @fnv 0x00cf2880
// src: EXE 0x00cf2880
void PhantomS::hkpAabbPhantom_linearCast(const hkpCollidable* collA, const LinCastInputS& input, void* castCollector,
                            void* startCollector)
{
    union
    {
        unsigned int tick;
        float len;
        int i;
    } sh;
    {
        hkMonitorStream* ms = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (ms->m_end.m_storage < ms->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)ms->m_end.val();
            h->m_commandAndMonitor = str_010cbfd0;
            _ReadWriteBarrier();
            *(volatile unsigned int*)&sh.tick = (unsigned int)__rdtsc();
            h->m_time0 = *(volatile unsigned int*)&sh.tick;
            ms->m_end.m_storage = (char*)(h + 1);
        }
    }
    __m128 path = _mm_sub_ps(*reinterpret_cast<const __m128*>(&input.m_vTo),
                             *reinterpret_cast<const __m128*>(static_cast<const char*>(collA->m_pMotionState) + 48));
    LcInput lcInput;
    lcInput.set(*static_cast<const ProcInput*>(static_cast<const hkpWorld*>(m_pOwningWorld)->m_pCollisionInput));
    _mm_store_ps(lcInput.m_path.m_f, path);
    {
        __m128 l = _mm_mul_ps(path, path);
        _mm_store_ss(&sh.len,
                     _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(l, l, 0xaa), _mm_add_ss(_mm_shuffle_ps(l, l, 0x55), l))));
        lcInput.m_fStartPointTolerance = sh.len;
    }
    lcInput.m_fScalar.v = input.m_fMaxExtraPenetrationAgainstFixed;
    lcInput.m_fMaxExtraPenetration = input.m_fMaxExtraPenetration;
    hkpCollisionDispatcher* dispatcher = static_cast<hkpCollisionDispatcher*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pDispatcher);
    CollFilterS* filter = static_cast<CollFilterS*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pCollisionFilter);
    int n = m_ppOverlappingCollidables.m_iElementCount;
    for (sh.i = 0; sh.i < n; sh.i++)
    {
        const hkpCollidable* collB = static_cast<const hkpCollidable*>(m_ppOverlappingCollidables.m_data[sh.i]);
        bool r;
        bool* enabled = filter->IsCollisionEnabled(&r, *collA, *collB);
        if (collB->m_pCollisionShape && *enabled && collB != collA)
        {
            int t = dispatcher->m_agent2TypeMap[*reinterpret_cast<const int*>(&collA->m_pCollisionShape->m_type)][*reinterpret_cast<const int*>(&collB->m_pCollisionShape->m_type)];
            dispatcher->m_agent2Funcs[t].m_pLinearCastFunc(*reinterpret_cast<const hkpCdBody*>(collA),
                *reinterpret_cast<const hkpCdBody*>(collB), *reinterpret_cast<const ShapeSweepParameters*>(&lcInput),
                *static_cast<hkpCdPointCollector*>(castCollector), static_cast<hkpCdPointCollector*>(startCollector));
        }
    }
    {
        hkMonitorStream* ms = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (ms->m_end.m_storage < ms->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)ms->m_end.val();
            h->m_commandAndMonitor = str_010c41f8;
            _ReadWriteBarrier();
            *(volatile unsigned int*)&sh.tick = (unsigned int)__rdtsc();
            h->m_time0 = *(volatile unsigned int*)&sh.tick;
            ms->m_end.m_storage = (char*)(h + 1);
        }
    }
}

static inline void transformInversePos(hkVector4& out, const hkTransform& a, const hkVector4& b)
{
    __m128 t = _mm_sub_ps(*(const __m128*)&b, *(const __m128*)&a.m_vTranslation);
    __m128 c0 = *(const __m128*)&a.m_rotation.m_kColumn0;
    __m128 c1 = *(const __m128*)&a.m_rotation.m_kColumn1;
    __m128 c2 = *(const __m128*)&a.m_rotation.m_kColumn2;
    {
        __m128 tmp, ctmp;
        tmp = _mm_unpacklo_ps(c0, c1);
        ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(tmp, c2);
        c1 = _mm_movehl_ps(c0, tmp);
        c1 = _mm_shuffle_ps(c1, c2, 0xd4);
        c2 = ctmp;
    }
    __m128 b0 = _mm_shuffle_ps(t, t, 0x00);
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 b1 = _mm_shuffle_ps(t, t, 0x55);
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 b2 = _mm_shuffle_ps(t, t, 0xaa);
    __m128 r2 = _mm_mul_ps(c2, b2);
    *(__m128*)&out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

// The shared phantom header does not yet declare this collector ray-cast entry point.
class Phantom_00cf2510 : public hkpAabbPhantom
{
  public:
    void hkpAabbPhantom_castRay(const WorldRayCastInput& input, hkpRayHitCollector& collector) const;
};

// @fnv 0x00cf2510
// src: XBOX_PDB 0x00cf2510
void Phantom_00cf2510::hkpAabbPhantom_castRay(const WorldRayCastInput& input, hkpRayHitCollector& collector) const
{
    {
        hkMonitorStream& mStream = *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.val();
            h->m_commandAndMonitor = "TtrcPhantom";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            h->m_time0 = t;
            mStream.m_end.m_storage = (char*)(h + 1);
        }
    }

    ShapeRayCastQuery sinput;
    sinput.m_uiFilterInfo = 0;
    sinput.m_pRayShapeCollectionFilter = 0;
    sinput.m_uiFilterInfo = input.m_uiFilterInfo;
    sinput.m_pRayShapeCollectionFilter =
        (input.m_bEnableShapeCollectionFilter)
            ? static_cast<const hkpRayShapeCollectionFilter*>(static_cast<const hkpCollisionFilter*>(((hkpWorld*)m_pOwningWorld)->m_pCollisionFilter))
            : 0;

    hkpCollidable** cols = (hkpCollidable**)m_ppOverlappingCollidables.m_data;
    for (int i = m_ppOverlappingCollidables.m_iElementCount - 1; i >= 0; i--)
    {
        const hkpShape* shape = (const hkpShape*)(*cols)->m_pCollisionShape;
        if (shape)
        {
            const hkTransform& trans = *(const hkTransform*)(*cols)->m_pMotionState;
            transformInversePos(sinput.m_vFrom, trans, input.m_vFrom);
            transformInversePos(sinput.m_vTo, trans, input.m_vTo);
            shape->CastRayWithCollector(sinput, *reinterpret_cast<const hkpCdBody*>(*cols), collector);
        }
        cols++;
    }

    {
        hkMonitorStream& mStream = *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (mStream.m_end.m_storage < mStream.m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.m_end.val();
            h->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            h->m_time0 = t;
            mStream.m_end.m_storage = (char*)(h + 1);
        }
    }
}
