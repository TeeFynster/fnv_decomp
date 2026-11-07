#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Preserve the float-only compiler intrinsic type: VC9's byte-array views
// of __m128 would add /GS instrumentation to the original SIMD stack locals.
#define _INCLUDED_MM2
// Exe 0x00d33f40 FUN_00d33f40: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

#include <windows.h>
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpFlagCdBodyPairCollector.h"
#include "../../../../../../../include/hkpSimpleClosestContactCollector.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/RootContactPoint.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpClosestCdPointCollector.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpConvexListAgent.h"
#include "../../../../../../../include/hkpConvexListShape.h"
#include "../../../../../../../include/hkpGskfAgent.h"

extern "C" void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(void*, void*);
extern "C" void __cdecl hkpConvexListAgent_QueryClosestPointsAfterHullTest(int, int, int, int);
extern "C"
{
    void __cdecl hkpConvexListAgent_staticGetPenetrations(void* a, void* b, void* c, void* d);
}
extern void* __cdecl CreateConvexListAgent();
extern void* __cdecl InitSpawnedBuffer();
extern void* __cdecl Runtime_UpdateState_00d34970();
extern void* __cdecl hkpConvexListAgent_staticLinearCast_UpdateState_00d349b0();
extern void* __cdecl hkpConvexListAgent_createConvexConvexListAgent();
extern void* __cdecl _FUN_00d33b90();
extern void* __cdecl _FUN_00d339d0();
extern void* __cdecl hkpConvexListAgent_staticLinearCast();
extern void* __cdecl hkpConvexListAgent_createConvexListConvexListAgent();
void __cdecl RegisterConvexListAgentCollisionFuncs(hkpConvexListAgent* self);
extern void __cdecl hkpAgentMachineUtil_calc1nStatistics(void*, void*, void*);
void __cdecl hkAgent1nMachine_Destroy(void*, int, int, int);
void* __stdcall hkpConvexListAgent_linearCast(void* a, void* b, void* c, void* d, void* e);
struct D338e0Agent
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};
inline void D338e0Agent::vf00()
{}
inline void D338e0Agent::vf04()
{}
inline void D338e0Agent::vf08()
{}
inline void D338e0Agent::vf0C()
{}
inline int D338e0Agent::vf10()
{
    return 0;
}
struct D338e0Local
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
};
extern "C" void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(int*, D338e0Local*);
inline void D338e0Dispatch(D338e0Local* local, int* ownerField, int result)
{
    local->field0C = result;
    hkAgent1nMachine_UpdateShapeCollectionFilter(ownerField, local);
}
void __cdecl ReleaseAllEntries(void* out, void* src, void* arg);
void InitBlockPool(void* p);
class hkCollectorBaseD347
{
  public:
    hkCollectorBaseD347() : m_bHasHit(false)
    {}
    virtual void AddHit(void* hit) = 0;

    bool m_bHasHit;
};
class hkCollectorD347 : public hkCollectorBaseD347
{
  public:
    hkCollectorD347(int filter) : m_iFilter(filter)
    {}
    virtual void AddHit(void* hit);

    int m_iFilter;
};
extern "C" void __cdecl hkpShapeCollectionAgent_staticGetPenetrations(void* a, void* b, void* c, hkCollectorBaseD347& collector);
void __cdecl hkCollectorD347_ProcessState_00d34790(void* b, void* a, void* c, int filter);
extern "C" void __cdecl hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810();
// @fnv 0x00d36930
// src: GUESS 0x00d36930 (confidence: low)
extern "C" void __cdecl hkpConvexListAgent_ForwardCall_00d36930()
{
    hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810();
}
struct hkMemberD337
{
    int unk00;
};
void __cdecl _hkAgent1nMachine_WarpTime(hkMemberD337* member, float a, float b, int c);
// @fnv 0x00d33890
extern void __cdecl ReleaseAllEntries(void*, int, void*);
struct ContactAgent
{
    virtual void Invalidate(int);
    int unk04, collidable08;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int contact30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int state80;
    unsigned char flag84;
    void hkpConvexListAgent_cleanup(void*);
};
// src: HAVOK_LIB 0x00d33890
void ContactAgent::hkpConvexListAgent_cleanup(void* input)
{
    if (flag84)
    {
        ReleaseAllEntries(&contact30, collidable08, input);
    }
    else
    {
        hkAgent1nMachine_Destroy(&contact30, state80, collidable08, (int)input);
    }
    Invalidate(1);
}
extern float DAT_01012054;
extern char DAT_010cebf0[];
struct __declspec(align(16)) S00d33940_Out
{
    float x;
    float y;
    float z;
    float w;
    float x1;
    float y1;
    float z1;
    float w1;
    float x2;
    float y2;
    float z2;
    float w2;
    float x3;
    float y3;
    float z3;
    float w3;
    void hkTransform_setMulInverseMul(int a, int b);
};
struct S00d33940_Sub
{
    void hkpGskCache_init(int a, int b, S00d33940_Out* c);
};
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern char DAT_010cebd0;
struct HitCollector
{
    void* m_vtbl;
    bool m_bHit;
};
void __cdecl TestGsk(void* a, void* b, void* c, HitCollector* col);
void __cdecl hkCollectorD347_ProcessState_00d34790(void* a, void* b, void* c, void* d);
// @fnv 0x00d33b90
// src: HAVOK_LIB 0x00d33b90
extern "C" void __cdecl hkpConvexListAgent_staticGetPenetrations(void* a, void* b, void* c, void* d)
{
    volatile DWORD tick;
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.m_storage;
        pRec->m_commandAndMonitor = "LtCvxList";
        reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(pRec)->m_nameOfFirstSplit = "StcheckHull";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)((char*)pRec + 0x10));
    }

    HitCollector col;
    col.m_vtbl = &DAT_010cebd0;
    col.m_bHit = false;
    TestGsk(a, b, c, &col);
    if (col.m_bHit)
    {
        pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.m_storage;
            pRec->m_commandAndMonitor = "Stchildren";
            _ReadWriteBarrier();
            tick = (DWORD)__rdtsc();
            pRec->m_time0 = tick;
            pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)((char*)pRec + 0xc));
        }
        hkCollectorD347_ProcessState_00d34790(a, b, c, d);
    }

    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.m_storage;
        pRec->m_commandAndMonitor = "lt";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)((char*)pRec + 0xc));
    }
}
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010cec28[];
extern const char str_01076f38[];
extern int DAT_010c476c;
extern float DAT_0104da48;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" int __cdecl TestGsk(const void* a, const void* b, const void* c, void* d);
extern "C" void __cdecl FUN_00dac450(const void* a, const void* b, const void* c, void* d);
extern "C" void __cdecl QueryClosestPoints(const void* a, const void* b, const void* c, void* d);
struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const void* m_pBodyA;
    const void* m_pBodyB;
};
// @fnv 0x00d339d0
// src: GUESS 0x00d339d0 (confidence: medium)
extern "C" void __cdecl hkpConvexListAgent_QueryClosestPointsAfterHullTest(int a1, int a2, int a3, int a4)
{
    {
        hkMonitorStream* pForm = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_end.m_storage;
        if (p < pForm->m_capacityMinus16.m_storage)
        {
            *(const char**)p = "LtCvxList";
            *(const char**)(p + 12) = "StcheckHull";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_end.m_storage = p + 16;
        }
    }

    hkpFlagCdBodyPairCollector flagCollector;
    TestGsk((const void*)a1, (const void*)a2, (const void*)a3, &flagCollector);
    if (flagCollector.DidHit())
    {
        hkMonitorStream* pForm = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_end.m_storage;
        if (p < pForm->m_capacityMinus16.m_storage)
        {
            *(const char**)p = "Stchildren";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            // Keep this timer read separate from the child-path timer read.
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = t;
            pForm->m_end.m_storage = p + 12;
        }
        QueryClosestPoints((const void*)a1, (const void*)a2, (const void*)a3, (hkpCdPointCollector*)a4);
    }
    else
    {
        hkpClosestCdPointCollector x;
        FUN_00dac450((const void*)a1, (const void*)a2, (const void*)a3, &x);
        if (!x.DidHit())
        {
            goto timer_end;
        }
        const hkpConvexListShape* shapeB = (const hkpConvexListShape*)((const hkpCdBody*)a2)->m_pCollisionShape;
        if (x.m_kHitPoint.m_kPoint.getDistance() > shapeB->m_minDistanceToUseConvexHull)
        {
            ContactPointPair point;
            point.m_pBodyA = (const void*)a1;
            point.m_pBodyB = (const void*)a2;
            point.m_kPoint = x.m_kHitPoint.m_kPoint;
            ((hkpCdPointCollector*)a4)->AddCdPoint(point);
            goto timer_end;
        }
        hkMonitorStream* pForm = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_end.m_storage;
        if (p < pForm->m_capacityMinus16.m_storage)
        {
            *(const char**)p = str_010cec28;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_end.m_storage = p + 12;
        }
        QueryClosestPoints((const void*)a1, (const void*)a2, (const void*)a3, (hkpCdPointCollector*)a4);
    }

timer_end: {
    hkMonitorStream* pForm = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* p = pForm->m_end.m_storage;
    if (p < pForm->m_capacityMinus16.m_storage)
    {
        *(const char**)p = str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(p + 4) = t;
        pForm->m_end.m_storage = p + 12;
    }
}
}

struct ProfileIndex
{
    unsigned long value;
    __forceinline ProfileIndex(unsigned long v) : value(v)
    {}
};
static __forceinline void* profileBuffer(const ProfileIndex& index)
{
    return TlsGetValue(index.value);
}
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_sqrt_ss(LocalM128);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_load_ss(const float*);
}
static __forceinline LocalM128 Splat(const float& f)
{
    LocalM128 r = _mm_load_ss(&f);
    return _mm_shuffle_ps(r, r, 0);
}
static __forceinline float ParseFloatValue(LocalM128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}

extern void* DAT_010ceb44;
extern const char str_010ceb84[], str_010ceb7c[], str_010ceb70[], str_010ceca0[], str_01076f38[];

struct L16
{
    Vec4 v;
};
struct L64
{
    L16 a, b, c, d;
};
struct L256
{
    L64 a, b, c, d;
};
struct L1024
{
    L256 a, b, c, d;
};
struct L4096
{
    L1024 a, b, c, d;
};
struct L128
{
    L64 a, b;
};
struct Arg4;
struct Shape;  // Collision-output snapshot: 0x1080 bytes consumed by the snapshot/reset methods.
struct Workspace
{
    L4096 contacts;
    L128 state;
    void __thiscall FUN_00d33670(Arg4&);
    void __thiscall hkpProcessCollisionOutputBackup_rollbackOutput(const Shape&, const Shape&, Arg4&, void*);
};

struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Vec4 m_40;
    Vec4 m_50;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    float m_9c;
    float m_a0;
};
struct ShapeHead
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int count;
};
struct Shape
{
    ShapeHead* m_00;
    int unkp04;
    Obj* m_08;
    Shape* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    float m_4c;
};
struct Arg3
{
    int unk00;
    int unk04;
    float m_08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    float m_58;
};
struct Arg4
{
    int unkp00;
    void* m_04;
};
struct CollObj
{
    Vec4 a, b, c, d;
    void __thiscall hkTransform_setMulInverseMul(Obj*, Obj*);
};
struct SStruct
{
    void* pCo;
    void* pObjA;
    void* a0;
    void* b0;
    float f;
};
struct StackObj
{
    void* vptr;
    short unkp04;
    short m_06s;
    int kind;
    void* saved;
    char flag;
    char unkp19a;
    short unkp20;
};
struct Big
{
    const Shape* a;
    const Shape* b;
    int zero;
    const Arg3* c;
    void* agent08;
    int unkp14, unk18, unk1c;
    CollObj co;
    int p60, p64, p68, p6c;
    Vec4 vec;
};

void FUN_00d33670(void* a);
void hkpProcessCollisionOutputBackup_rollbackOutput(void* a, void* b, void* c, void* d);
void* hkTransform_setMulInverseMul(void* a, void* b);
int hkpGsk_getClosestPoint(SStruct* a, void* b, void* c, void* d);
void hkpConvexListAgent_switchToGskMode(void* a);
void hkpConvexListAgent_switchToStreamMode(void* a);
void FUN_00d42020(void* a, void* b, void* c, void* d);
struct AddressValue
{
    void* value;
    __forceinline AddressValue(void* p) : value(p)
    {}
};
void hkAgent1nMachine_Process(void* a, const void* b, AddressValue wrapped, void* d, void* e);
void ReleaseAllEntries(void* a, void* b, void* c);

typedef void(__thiscall* Ws70Fn)(void*, const void*);
typedef void(__thiscall* Ws00Fn)(void*, const void*, const void*, const void*, void*);
typedef void*(__thiscall* CbFn)(void*, void*, void*);
typedef void(__thiscall* Ag1Fn)(void*, void*);
typedef void(__thiscall* Ag4Fn)(void*, const void*, const void*, const void*, void*);

struct StreamState
{
    short flags;
    char count;
    char unknown;
    int field04, field08;
    float distance;
};
struct ScalarScratch;
struct Agent
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 m_20w;
    short unkp30;
    char m_32;
    char unkp33;
    int unk34;
    int unk38;
    float m_3c;
    __forceinline StreamState& streaming()
    {
        return *reinterpret_cast<StreamState*>(&unkp30);
    }
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    char m_84;
    char m_85;
    short m_86;
    void __thiscall hkpConvexListAgent_switchToGskMode(void*);
    void __thiscall hkpConvexListAgent_switchToStreamMode(void*);
    void __thiscall FUN_00d42020(const Shape&, const Shape&, const Arg3&, Arg4&);
    __forceinline void processCached(const Shape&, const Shape&, const Arg3&, Arg4&, const Vec4&, Workspace&, StackObj&,
                                     ScalarScratch&, bool&);
    void streamCollision(const Shape&, const Shape&, const Arg3&, Arg4&, const Vec4&, ShapeHead*);
    void __thiscall hkpConvexListAgent_processCollision(const Shape& a, const Shape& b, const Arg3& c, Arg4& d);
};

__forceinline void projectDistance(Vec4& normal, const Vec4& vec)
{
    LocalM128 p = _mm_mul_ps(normal.m_vComponents, vec.m_vComponents);
    LocalM128 v = vec.m_vComponents;
    LocalM128 s3 = _mm_shuffle_ps(v, v, 0xff);
    LocalM128 s2 = _mm_shuffle_ps(p, p, 0xaa);
    LocalM128 s1 = _mm_shuffle_ps(p, p, 0x55);
    LocalM128 rr = _mm_add_ps(_mm_add_ss(s2, s3), _mm_add_ss(s1, p));
    float dot;
    _mm_store_ss(&dot, rr);
    normal.w -= dot;
}
// Keep the two rounded scale values together for x87 and SIMD consumers.
struct MotionScales
{
    float a, b;
};
struct ScalarScratch
{
    union
    {
        float dt;
        hkMonitorStream* volatile monitor;
        float minimum;
    } first;
    union
    {
        float factor;
        volatile unsigned stamp;
    } a;
    float radius;
    union
    {
        float factor;
        volatile unsigned stamp;
    } b;
    union
    {
        ShapeHead* shape;
        volatile unsigned stamp;
    } last;
};
__forceinline void calculateMotion(const Obj& oa, const Obj& ob, ScalarScratch& scratch, Vec4& vec)
{
    scratch.a.factor = scratch.first.dt * oa.m_50.w;
    scratch.b.factor = scratch.first.dt * ob.m_50.w;
    LocalM128 scaleA = Splat(scratch.a.factor);
    LocalM128 scaleB = Splat(scratch.b.factor);
    LocalM128 vc = ob.m_40.m_vComponents;
    LocalM128 vd = ob.m_50.m_vComponents;
    LocalM128 va = oa.m_40.m_vComponents;
    LocalM128 vb = oa.m_50.m_vComponents;
    vec.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(vd, vc), scaleB), _mm_mul_ps(_mm_sub_ps(va, vb), scaleA));
    vec.w = oa.m_9c * scratch.a.factor * oa.m_a0 + ob.m_9c * scratch.b.factor * ob.m_a0;
}

__forceinline void Agent::streamCollision(const Shape& a, const Shape& b, const Arg3& c, Arg4& d, const Vec4& vec,
                                          ShapeHead* bHead)
{
    Big big;
    big.zero = 0;
    big.a = &a;
    big.b = &b;
    big.agent08 = m_08;
    LocalM128 motion = vec.m_vComponents;
    big.c = &c;
    big.vec.m_vComponents = motion;
    big.co.hkTransform_setMulInverseMul(a.m_08, b.m_08);
    int count = bHead->count;
    // The shared router accessor is bound to 0x00c85750; its first slot holds the scratch cursor.
    hkMemoryRouter* pool = (&hkMemoryRouter::getInstance());
    int* arr = (int*)pool->m_stack.m_next.m_storage;
    pool->m_stack.m_next.m_storage = (int*)((unsigned int)arr + (((unsigned int)(count * 4 + 4) + 0x7f) & ~0x7f));
    for (int i = 0; i < count; i++)
        arr[i] = i;
    arr[count] = -1;
    hkAgent1nMachine_Process(&streaming(), &big, AddressValue(&bHead->unk14), arr, &d);
    hkMemoryRouter* pool2 = (&hkMemoryRouter::getInstance());
    pool2->m_stack.m_next.m_storage = arr;
}
__forceinline void Agent::processCached(const Shape& a, const Shape& b, const Arg3& c, Arg4& d, const Vec4& vec,
                                        Workspace& ws, StackObj& so, ScalarScratch& scratch, bool& retry)
{
    if (m_20w.w > c.m_08)
    {
        projectDistance(m_20w, vec);
        if (m_20w.w > c.m_08)
        {
            if (m_32 != 0)
                ReleaseAllEntries(&unkp30, m_08, d.m_04);
            return;
        }
    }
    {
        hkMonitorStream* pBuf;
        pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        scratch.first.monitor = pBuf;
        hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.m_storage;
        if (pRec < (hkMonitorStream::TimerCommand*)pBuf->m_capacityMinus16.m_storage)
        {
            pRec->m_commandAndMonitor = str_010ceca0;
            _ReadWriteBarrier();
            scratch.a.stamp = (unsigned int)__rdtsc();
            pRec->m_time0 = scratch.a.stamp;
            scratch.first.monitor->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(pRec + 1));
        }
        so.kind = 2;
        so.m_06s = 1;
        so.vptr = &DAT_010ceb44;
        so.flag = 0;
        so.saved = m_08;
        m_08 = &so;
        FUN_00d42020(a, b, c, d);
        m_08 = so.saved;
        if (so.flag == 0)
        {
            if (m_32 == 0)
                return;
            if (m_85 != 0)
                return;
            const Shape* pa = &b;
            while (pa->m_0c)
                pa = pa->m_0c;
            scratch.radius = pa->m_4c;
            const Shape* pb = &a;
            while (pb->m_0c)
                pb = pb->m_0c;
            scratch.first.minimum = pb->m_4c;
            double cachedDistance;
            if (scratch.first.minimum < scratch.radius)
            {
                scratch.first.minimum = (const float&)(scratch.first.minimum * 1.0f);
                cachedDistance = m_20w.w;
            }
            else
            {
                scratch.first.minimum = scratch.radius;
                cachedDistance = m_20w.w;
            }
            scratch.radius = 2.0f * scratch.first.minimum;
            if (!(cachedDistance < -scratch.radius))
                return;
        }
        ws.hkpProcessCollisionOutputBackup_rollbackOutput(a, b, d, m_08);
        hkpConvexListAgent_switchToStreamMode(d.m_04);
        retry = true;
        return;
    }
}
// @fnv 0x00d33f40
// src: HAVOK_SRC 0x00d33f40
void __thiscall Agent::hkpConvexListAgent_processCollision(const Shape& a, const Shape& b, const Arg3& c, Arg4& d)
{
    Workspace ws;
    Vec4 vec;

    ScalarScratch scratch;
    CollObj co;
    union
    {
        SStruct query;
        StackObj manager;
    } temp;

    {
        hkMonitorStream* pBuf;
        hkMonitorStream::TimerBeginListCommand* pRec = (hkMonitorStream::TimerBeginListCommand*)(pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c))->m_end.m_storage;
        if (pRec < (hkMonitorStream::TimerBeginListCommand*)pBuf->m_capacityMinus16.m_storage)
        {
            pRec->m_commandAndMonitor = str_010ceb84;
            pRec->m_nameOfFirstSplit = str_010ceb7c;
            _ReadWriteBarrier();
            scratch.a.stamp = (unsigned int)__rdtsc();
            pRec->m_time0 = scratch.a.stamp;
            pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(pRec + 1));
        }
    }
    scratch.last.shape = b.m_00;
    scratch.first.dt = c.m_58;
    calculateMotion(*a.m_08, *b.m_08, scratch, vec);
    ws.FUN_00d33670(d);
    if (m_84 != 0)
        goto project;
stream: {
    hkMonitorStream* pBuf;
    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    scratch.first.monitor = pBuf;
    hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)pBuf->m_end.m_storage;
    if (pRec < (hkMonitorStream::TimerCommand*)pBuf->m_capacityMinus16.m_storage)
    {
        pRec->m_commandAndMonitor = str_010ceb70;
        _ReadWriteBarrier();
        scratch.b.stamp = (unsigned int)__rdtsc();
        pRec->m_time0 = scratch.b.stamp;
        scratch.first.monitor->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(pRec + 1));
    }
    short oc = m_86;
    m_86 = (short)(oc - 1);
    if (oc >= 0)
        goto sqrtpath;
    m_86 = 0x19;
    {
        co.hkTransform_setMulInverseMul(a.m_08, b.m_08);
        SStruct& s = temp.query;
        Vec4 objD;
        s.a0 = a.m_00;
        s.b0 = b.m_00;
        s.pCo = &co;
        s.pObjA = a.m_08;
        s.f = c.m_08;
        int res = hkpGsk_getClosestPoint(&s, &m_0c, &m_20w, &objD);
        if (res == 0)
        {
            streaming().distance = -m_20w.w;
            goto sqrtpath;
        }
        hkpConvexListAgent_switchToGskMode(d.m_04);
        ws.hkpProcessCollisionOutputBackup_rollbackOutput(a, b, d, m_08);
    }
}
// Update cached separation before choosing GSK or cached-contact export.
project: {
    bool retry = false;
    processCached(a, b, c, d, vec, ws, temp.manager, scratch, retry);
    if (retry)
        goto stream;
    goto tail;
}
// Streaming path: reduce cached distance by motion length, then visit all shape keys.
sqrtpath: {
    LocalM128 vv = vec.m_vComponents;
    LocalM128 sq = _mm_mul_ps(vv, vv);
    LocalM128 sh1 = _mm_shuffle_ps(sq, sq, 0x55);
    LocalM128 s1 = _mm_add_ss(sh1, sq);
    LocalM128 sh2 = _mm_shuffle_ps(sq, sq, 0xaa);
    LocalM128 s2 = _mm_add_ss(sh2, s1);
    LocalM128 len = _mm_sqrt_ss(s2);
    _mm_store_ss(&scratch.radius, len);
    streaming().distance -= scratch.radius;
    streamCollision(a, b, c, d, vec, scratch.last.shape);
}
tail:
    m_85 = 1;
    {
        hkMonitorStream* pBuf;
        unsigned long index = DAT_0126835c;
        hkMonitorStream::TimerCommand* pRec = (hkMonitorStream::TimerCommand*)(pBuf = (hkMonitorStream*)profileBuffer(ProfileIndex(index)))->m_end.m_storage;
        if (pRec < (hkMonitorStream::TimerCommand*)pBuf->m_capacityMinus16.m_storage)
        {
            pRec->m_commandAndMonitor = str_01076f38;
            _ReadWriteBarrier();
            scratch.last.stamp = (unsigned int)__rdtsc();
            pRec->m_time0 = scratch.last.stamp;
            pBuf->m_end.m_storage = reinterpret_cast<char*>((hkMonitorStream::TimerCommand*)(pRec + 1));
        }
    }
}
