// src/staging/blk_00da0000_od_o2_nood_variant_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00da0000_od_o2_nood_variant_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/staging/blk_00da0000_od_o2_nood_variant_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00da0000_od_o2_nood_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00da0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00da0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00da0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"
struct ScratchBlock
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
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};
void __cdecl Object_InitializeDispatchFunctionTable(ScratchBlock* block);
class ScratchOwner
{
  public:
    void AddEntry(ScratchBlock* block, int a, int b);
};
void __cdecl hkListAgent3_registerAgent3(ScratchOwner* owner);
struct S00da0780_Member
{
    S00da0780_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};
class __declspec(align(16)) S00da0780_Object
{
  public:
    S00da0780_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    S00da0780_Member m_kMember;
    int unk0C;
};
const void* __cdecl getVtablehkLocalFrameGroup();
#include <xmmintrin.h>
__declspec(align(16)) struct FUN_00da7180_cls
{
    __m128 m_v00;
    __m128 m_v10;
    float m_f20;
    unsigned int m_i24;
    float m_f28;
    unsigned int m_i2C;
    unsigned int m_i30;

    FUN_00da7180_cls* AssignFields_00da7180(const FUN_00da7180_cls* src);
};

extern char g_initFlag;
void __cdecl ValidateHavokKeyCode(char*);

class S00da8180_Lane
{
  public:
    S00da8180_Lane(const __m128& x) : m_vValue(x)
    {}
    S00da8180_Lane(float x)
    {
        m_vValue = ::_mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return ::_mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }
    operator float() const
    {
        float s;
        ::_mm_store_ss(&s, m_vValue);
        return s;
    }

  private:
    __m128 m_vValue;
};

class S00da8180_Quad4
{
  public:
    S00da8180_Quad4()
    {}
    S00da8180_Quad4(const S00da8180_Quad4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const S00da8180_Quad4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = ::_mm_setzero_ps();
    }
    __forceinline void setSub4(const S00da8180_Quad4& a, const S00da8180_Quad4& b)
    {
        m_vComponents = ::_mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const S00da8180_Lane& r, const S00da8180_Quad4& v)
    {
        m_vComponents = ::_mm_mul_ps(r.broadcast(), v.m_vComponents);
    }
    __forceinline void mul4(const S00da8180_Lane& s)
    {
        m_vComponents = ::_mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline S00da8180_Lane horizontalAdd3() const
    {
        __m128 xy = ::_mm_add_ss(::_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return ::_mm_add_ss(::_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xy);
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }

  private:
    __m128 m_vComponents;
};

struct S00da8180_MoppCodeInfo
{
    S00da8180_Quad4 m_offset;
    inline float getScale() const
    {
        return m_offset(3);
    }
};

struct S00da8180_MoppCode
{
    int m_ppVirtualMethodTable;
    int m_refs;
    int m_pad08;
    int m_pad0c;
    S00da8180_MoppCodeInfo m_info;
    const unsigned char* m_data;
    int m_iElementCount;
    int m_pRayCursor;
};

struct S00da8180_MoppShape
{
    int m_ppVirtualMethodTable;
    int m_refs;
    int m_ulUserData;
    int m_type;
    int m_pShapeCollection;
    const S00da8180_MoppCode* m_pMoppCode;
    inline const S00da8180_MoppCode* getMoppCode() const
    {
        return m_pMoppCode;
    }
};

struct S00da8180_CastShape
{
    int m_ppVirtualMethodTable;
    int m_refs;
    int m_ulUserData;
    int m_type;
    inline int getType() const
    {
        return m_type;
    }
};

struct S00da8180_CastBody
{
    const void* m_pCollisionShape;
    inline const void* getShape() const
    {
        return m_pCollisionShape;
    }
};

struct __declspec(align(16)) AabbCastInput
{
    S00da8180_Quad4 m_vFrom;
    S00da8180_Quad4 m_vTo;
    S00da8180_Quad4 m_vHalfExtents;
    int m_pad30;
    const S00da8180_CastBody* m_pFirstCastBody;
    const S00da8180_CastBody* m_pSecondCastBody;
};

struct __declspec(align(16)) MachineVectorIndexRecord
{
    S00da8180_Quad4 m_offset;
    S00da8180_Quad4 SetCenterPosition;
    float m_fValueAtOffset20;
    int m_iValueAtOffset04;
    float m_FtoBoxRatio;
    int m_iIndex;
    unsigned int m_property;
};

struct __declspec(align(16)) Vector4Pair
{
    S00da8180_Quad4 m_vFrom;
    S00da8180_Quad4 m_vTo;
};

class S00da8180_AabbCastMachine
{
  public:
    int m_pad00;
    int m_pad04;
    int m_pad08;
    int m_pad0c;
    const S00da8180_MoppCode* m_pMoppCode;
    float m_vRayDirectionVector;
    int m_iRayDirectionIndex;
    float m_fEarlyOutHitFraction;
    float m_refEarlyOutHitFraction;
    void* m_pPointCollector;
    void* m_startCollector;
    const AabbCastInput* m_pRayCastInput;
    int m_isStartQuery;

    void ProcessMoppCommands_00da71c0(const MachineVectorIndexRecord* query, const unsigned char* pc, Vector4Pair* fQuery, int level);
    void ProcessAndReturnValue_00da8180(const AabbCastInput& input, void* castCollector, void* startCollector);
};

extern void visitLevel(int);

// src: GUESS 0x00da71c0 (confidence: low)
__declspec(noinline) void S00da8180_AabbCastMachine::ProcessMoppCommands_00da71c0(const MachineVectorIndexRecord* query,
                                                                  const unsigned char* pc, Vector4Pair* fQuery,
                                                                  int level)
{
    visitLevel(query->m_iValueAtOffset04 + pc[level]);
    Vector4Pair child;
    child.m_vFrom = fQuery->m_vFrom;
    child.m_vTo = fQuery->m_vTo;
    if (level < 3)
    {
        ProcessMoppCommands_00da71c0(query, pc + 1, &child, level + 1);
    }
}

// @fnv 0x00da8180
// src: GUESS 0x00da8180 (confidence: low)
void S00da8180_AabbCastMachine::ProcessAndReturnValue_00da8180(const AabbCastInput& input, void* castCollector, void* startCollector)
{
    if (!g_initFlag)
    {
        ValidateHavokKeyCode(&g_initFlag);
        if (!g_initFlag)
        {
            return;
        }
    }
    m_pRayCastInput = &input;
    const S00da8180_MoppShape* bvB = static_cast<const S00da8180_MoppShape*>(input.m_pSecondCastBody->getShape());
    m_pMoppCode = bvB->getMoppCode();
    m_pPointCollector = castCollector;
    m_startCollector = startCollector;
    m_iRayDirectionIndex = static_cast<const S00da8180_CastShape*>(input.m_pFirstCastBody->getShape())->getType();
    m_fEarlyOutHitFraction = 1.0f;
    m_refEarlyOutHitFraction = m_fEarlyOutHitFraction;
    const unsigned char* programCounter = &m_pMoppCode->m_data[0];
    MachineVectorIndexRecord query;
    query.m_offset.setZero4();
    m_vRayDirectionVector = 1.0f / m_pMoppCode->m_info.getScale();
    query.m_FtoBoxRatio = m_pMoppCode->m_info.getScale() / 65536.0;
    query.SetCenterPosition.setMul4(query.m_FtoBoxRatio, input.m_vHalfExtents);
    query.m_fValueAtOffset20 = query.SetCenterPosition.horizontalAdd3();
    query.m_fValueAtOffset20 *= 3.0;
    Vector4Pair fQuery;
    fQuery.m_vFrom.setSub4(input.m_vFrom, m_pMoppCode->m_info.m_offset);
    fQuery.m_vTo.setSub4(input.m_vTo, m_pMoppCode->m_info.m_offset);
    fQuery.m_vFrom.mul4(query.m_FtoBoxRatio);
    fQuery.m_vTo.mul4(query.m_FtoBoxRatio);
    query.m_iIndex = 0;
    query.m_iValueAtOffset04 = 0;
    query.m_property = 0;
    m_isStartQuery = (*programCounter != 0xd) - 1;
    ProcessMoppCommands_00da71c0(&query, programCounter, &fQuery, 0);
}
