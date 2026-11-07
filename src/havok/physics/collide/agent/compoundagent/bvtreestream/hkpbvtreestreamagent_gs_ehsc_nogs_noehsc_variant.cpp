#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipBodyCollector.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipCollector.h"

// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl hkpBvTreeAgent_staticGetPenetrations(void*, void*, void*, void*);
struct FUN_00d2dd30_class
{
    void __thiscall FUN_00d2dd30(void* a, void* b, void* c, void* d);
};
extern "C" void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(void* a, void* b);
struct FUN_00d2ddd0_class
{
    void __thiscall FUN_00d2ddd0(int a);
};
extern "C" void __cdecl hkpBvTreeAgent_staticGetClosestPoints(void*, void*, void*, void*);
// @fnv 0x00d2dd50
extern "C" void __stdcall FUN_00d2dd50(void* a, void* b, void* c, void* d)
{
    hkpBvTreeAgent_staticGetClosestPoints(a, b, c, d);
}

void __cdecl hkpBvTreeAgent_staticLinearCast(void*, void*, void*, void*, void*);
struct OperationAdapter
{
    void FUN_00d2dd70(void* a, void* b, void* c, void* d, void* e);
};
struct FUN_00d2dda0_class
{
    virtual void finish(int);
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
    void __thiscall FUN_00d2dda0(int value);
};
extern void __cdecl hkAgent1nMachine_Destroy(void*, int, int, int);
void __cdecl _hkAgent1nMachine_WarpTime(void* self, float a, float b, void* c);
struct FUN_00d2ddf0_Class
{
    void __thiscall FUN_00d2ddf0(float a, float b, void* c);
};
struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct Obj : RefObj
{
    int pad[14];
    Obj* hkpBvTreeStreamAgent_hkpBvTreeStreamAgent(int, int, int, int);
};
inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)hkMemoryRouter::getInstance().heap().blockAlloc(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}
void* __cdecl hkpBvTreeStreamAgent_createShapeBvAgent(int a, int b, int c, int d);
void hkpBvTreeStreamAgent_createBvTreeShapeAgent();
void hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970();
void hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0();
void hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0();
void hkpBvTreeStreamAgent_createShapeBvAgent();
void hkpBvTreeAgent_staticGetClosestPoints();
void hkpBvTreeAgent_staticLinearCast();
struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
    void AppendRecordAndRegisterAgents(Conversion*, int, int);
};
void hkpBvTreeStreamAgent_registerMultiRayAgent(Registry* registry);
typedef void*(__cdecl* S_00d2e8e0_CreateFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_GetPenetrationsFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_GetClosestPointsFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_LinearCastFunc)(void*, void*, void*, void*, void*);
void* hkpBvTreeStreamAgent_dispatchBvTreeConvexList(void*, void*, void*, void*);
void hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970(void*, void*, void*, void*);
void hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0(void*, void*, void*, void*);
void hkpBvTreeAgent_staticLinearCast_UpdateState_00d2e9f0(void*, void*, void*, void*, void*);
void* hkpBvTreeStreamAgent_dispatchConvexListBvTree(void*, void*, void*, void*);
void hkpBvTreeAgent_staticGetClosestPoints(void*, void*, void*, void*);
void hkpBvTreeAgent_staticLinearCast(void*, void*, void*, void*, void*);
struct S_00d2e8e0_AgentFuncs
{
    S_00d2e8e0_CreateFunc m_pCreateFunc;
    S_00d2e8e0_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d2e8e0_GetClosestPointsFunc m_pGetPenetrationsFunc;
    S_00d2e8e0_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d2e8e0_Dispatcher
{
    void AppendRecordAndRegisterAgents(S_00d2e8e0_AgentFuncs& f, int typeA, int typeB);
};
void Object_RegisterSymmetricAgentFunctions(S_00d2e8e0_Dispatcher* dispatcher);
void __cdecl hkpBvTreeAgent_staticGetClosestPoints(int a, int b, int c, hkpCdPointCollector* collector);
void __cdecl hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0(int a, int b, int c, int d);
extern float DAT_0104da48;
struct Context
{
    void hkpShapeCollectionAgent_getClosestPoints(void* first, void* second, void* third, hkpSymmetricAgentFlipCollector* collector);
    void UpdateState_00d2edd0(void* first, void* second, void* third, void* fourth);
};
extern "C" void* __cdecl hkStatisticsCollector_getAllocatedSize(void* ptr, unsigned int size);
extern "C" void __cdecl hkpAgentMachineUtil_calc1nStatistics(void* a, int b, void* c);
extern "C" const char str_010ce828[];
struct VisitTarget
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void Visit(int kind, const char* name, void* data, unsigned int size, void* extra)
    {}
    int unk04;
    int m_08;
    int unk0C;
    unsigned char m_10;
};
struct PackedBuffer
{
    void* m_ptr;
    unsigned int m_uiItemCount;
    unsigned int m_flag;
};
struct BufOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    PackedBuffer m_buf;
    void __thiscall VisitPackedBuffer(VisitTarget* target, int flags);
};
void __cdecl hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970(void* bodyA, void* bodyB, void* arg3, void* orig_collector);
struct FUN_00d2eb50_nib
{
    unsigned char lo : 4;
    unsigned char hi : 4;
};
struct FUN_00d2eb50_cls
{
    unsigned short m_w00;
    unsigned short m_w02;
    unsigned short m_w04;
    unsigned char m_unk06;
    unsigned char m_unk07;
    unsigned char m_b08;
    unsigned char m_b09;
    FUN_00d2eb50_nib m_nib0a;
    void __thiscall SwapFields();
};
struct CpuCallData
{
    void* descriptor;
    float bound;
    unsigned int value;
};
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject
{
    void FUN_00d2dd50(void*, void*, unsigned int, CpuCallData*);
    void DispatchWithBoundData(void*, void*, unsigned int, unsigned int);
};
struct CallTarget_00d2de20
{
    int hkpBvTreeStreamAgent_updateShapeCollectionFilter(int, int, int, int);
};
struct SearchObject
{
    int CallTarget(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// Game side wrapper that fills the collector and hands it to the query routine.
struct FUN_00d43cd0_class
{
    void __thiscall ProcessCollisionEntries(void* a, void* b, void* c, void* d);
    void __thiscall UpdateState_00d2ed90(void* a1, void* a2, void* a3, void* a4);
};

#include <xmmintrin.h>
struct S2ee10_Ref
{
    void* p;
};

struct S2ee10_Vec4;
extern "C" const S2ee10_Vec4 DAT_010c4c00;

struct S2ee10_Simd
{
    __m128 m_vValue;
};

struct S2ee10_Vec4
{
    __m128 m_vComponents;
    inline void setNeg4(const S2ee10_Vec4& v);
    inline S2ee10_Simd getSimdAt3() const
    {
        S2ee10_Simd r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
    inline void addMul4(const S2ee10_Simd& r, const S2ee10_Vec4& a)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(r.m_vValue, a.m_vComponents), m_vComponents);
    }
};

inline void S2ee10_Vec4::setNeg4(const S2ee10_Vec4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00.m_vComponents);
}

struct S2ee10_ContactPoint
{
    S2ee10_Vec4 m_vContactPosition;
    S2ee10_Vec4 m_vSeparatingNormal;
    S2ee10_Vec4 m_extra;
};

struct S2ee10_GskCache
{
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_flagsLo : 4;
    unsigned char m_flagsHi : 4;

    inline void flip()
    {
        unsigned char lo = m_flagsLo;
        m_flagsLo = m_flagsHi;
        m_flagsHi = lo;
        unsigned char d = m_ucDimensionA;
        m_ucDimensionA = m_ucDimensionB;
        m_ucDimensionB = d;
        int idx = m_ucDimensionA + m_ucDimensionB - 1;
        unsigned short v0 = m_kVertices[0];
        m_kVertices[0] = m_kVertices[idx];
        m_kVertices[idx] = v0;
        if ((m_ucDimensionA & m_ucDimensionB) == 2)
        {
            unsigned short t = m_kVertices[1];
            m_kVertices[1] = m_kVertices[2];
            m_kVertices[2] = t;
        }
    }
};

struct S2ee10_ToiInfo
{
    S2ee10_Vec4 m_vSeparatingNormal;
    float m_uiCommandId;
    int unk14;
    int unk18;
    int unk1c;
    S2ee10_GskCache m_kGskCache;

    inline void flip()
    {
        m_vSeparatingNormal.setNeg4(m_vSeparatingNormal);
        m_kGskCache.flip();
    }
};

struct S2ee10_Output
{
    S2ee10_ContactPoint* m_pAlignedPairData;
    int m_pConstraintOwner;
    int m_potentials;
    int unk0c;
    S2ee10_ContactPoint m_akContactPoints[256];
    S2ee10_Vec4 unk3010;
    S2ee10_ToiInfo m_fTimeOfImpact;
};

struct CollisionAgentContext;
class hkpAgentBase
{
  public:
    void hkpShapeCollectionAgent_processCollision(S2ee10_Ref bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                      S2ee10_Output& output);
};

class hkpSymmetricAgentT : public hkpAgentBase
{
  public:
    void ProcessEntries_00d2ee10(const hkpCdBody& bodyA, S2ee10_Ref bodyB, const CollisionAgentContext& input,
                      S2ee10_Output& output);
};

// @fnv 0x00d2ee10
// src: GUESS 0x00d2ee10 (confidence: low)
void hkpSymmetricAgentT::ProcessEntries_00d2ee10(const hkpCdBody& bodyA, S2ee10_Ref bodyB, const CollisionAgentContext& input,
                                      S2ee10_Output& output)
{
    float oldTime = output.m_fTimeOfImpact.m_uiCommandId;
    S2ee10_ContactPoint* cp = output.m_pAlignedPairData;
    hkpAgentBase::hkpShapeCollectionAgent_processCollision(bodyB, bodyA, input, output);
    for (; cp < output.m_pAlignedPairData; cp++)
    {
        cp->m_vContactPosition.addMul4(cp->m_vSeparatingNormal.getSimdAt3(), cp->m_vSeparatingNormal);
        cp->m_vSeparatingNormal.setNeg4(cp->m_vSeparatingNormal);
    }
    if (oldTime != output.m_fTimeOfImpact.m_uiCommandId)
    {
        __m128 n = _mm_load_ps((const float*)&output.m_fTimeOfImpact.m_vSeparatingNormal);
        output.m_fTimeOfImpact.m_vSeparatingNormal.m_vComponents = _mm_xor_ps(n, DAT_010c4c00.m_vComponents);
        output.m_fTimeOfImpact.m_kGskCache.flip();
    }
}
