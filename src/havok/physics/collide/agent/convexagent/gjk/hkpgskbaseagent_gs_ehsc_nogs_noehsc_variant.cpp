// src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct hkpGskBaseAgent
{
    virtual void hkpGskBaseAgent_cleanup(bool);
};
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern float DAT_01012054;
class FUN_00dabeb0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_f18;
    int unk1C;

    void Reset(bool flag);
};
extern float DAT_01012054;
class FUN_00dabed0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_18;
    int unk1c;
    __m128 m_20;

    void SetValueIfExpected(float expected, float value, int unused);
};
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
struct hkpCdBody
{
    const void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    const void* m_pMotionState;
};
struct GskAgentInput
{
    int unk00;
    int unk04;
    float m_fScalar;
};
struct hkTransform
{
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_kColumn3;
    void hkTransform_setMulInverseMul(const void* a, const void* b);
};
struct GskInput
{
    const hkTransform* m_kTransform;
    const void* m_pTransformB;
    const void* m_pShapeA;
    const void* m_pShapeB;
    float m_fScalar;
};
struct GskOutput
{
    __m128 m_pos;
    __m128 m_vHitNormal;
};
struct hkContactPoint
{
    __m128 m_vContactPosition;
    __m128 m_vSeparatingNormal;
};
struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
};
struct hkpCdPointCollector
{
    virtual void vfunc00();
    virtual void AddCdPoint(const ContactPointPair& point);
};
int hkpGsk_getClosestPoint(const GskInput* input, void* status, __m128* out1, __m128* out2);
class FUN_00dac9e0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void ProcessGskContact(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const GskAgentInput* input,
                           hkpCdPointCollector* collector);
};
void __stdcall FUN_00dabe80(int, int, int, int);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
struct hkVector4DAC0
{
    __m128 m_vComponents;

    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
    __forceinline void _setRotatedDir(const struct hkMatrix3DAC0& r, const hkVector4DAC0& b);
};
struct hkMatrix3DAC0
{
    hkVector4DAC0 m_kColumn0;
    hkVector4DAC0 m_kColumn1;
    hkVector4DAC0 m_kColumn2;
};
struct hkTransformDAC0
{
    hkMatrix3DAC0 m_rotation;
    hkVector4DAC0 m_vTranslation;

    void hkTransform_setMulInverseMul(const hkTransformDAC0& kA, const hkTransformDAC0& kB);

    const hkMatrix3DAC0& getRotation() const
    {
        return m_rotation;
    }
};
__forceinline void hkVector4DAC0::_setRotatedDir(const hkMatrix3DAC0& r, const hkVector4DAC0& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
class hkpConvexShapeDAC0
{
  public:
    virtual ~hkpConvexShapeDAC0();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned long m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
};
struct hkpCdBodyDAC0
{
    const hkpConvexShapeDAC0* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransformDAC0* m_pMotionState;
};
struct hkpCollisionInputDAC0;
struct FUN_00daad40_solver
{
    void hkpGsk_getClosestFeature(const hkpConvexShapeDAC0* pkShapeA, const hkpConvexShapeDAC0* pkShapeB,
                      const hkTransformDAC0& kAtB, hkVector4DAC0& kPointOut);
};
void __cdecl FUN_00dac020(const hkpCdBodyDAC0& kBodyA, const hkpCdBodyDAC0& kBodyB, const hkpCollisionInputDAC0& kInput,
                          FUN_00daad40_solver* pkSolver, hkVector4DAC0& kSeparatingNormal);
extern char g_gskBaseAgentVtbl;
struct GskNode;
__declspec(align(16)) struct GskTmp
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
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
    void Setup(int a, int b);
};
struct GskSub
{
    int m_00;
    int m_04;
    int m_08;
    void Init(GskNode* a, GskNode* b, GskTmp* t);
    void Init2(GskNode* a, GskNode* b, GskTmp* t);
};
struct GskNode
{
    GskNode* m_00;
    int unk04;
    int m_08;
    GskNode* m_0c;
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
struct FUN_00dabf10_cls
{
    void* m_00;
    short unk04;
    short m_06;
    int m_08;
    GskSub m_0c;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;

    FUN_00dabf10_cls* FUN_00dabf10(GskNode* a1, GskNode* a2, int a3);
};
struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
    hkBool(char b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    float m_weldTolerance;
    float m_fScalar;
};
struct ContactData
{
    __m128 m_vHitNormal;
    __m128 m_vContactPosition;
    float m_fClosestPointDistanceSquared;
    __m128 m_data30;
    __m128 m_data40;
};
struct Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void GetVerticesForIds(const short* ids, int numIds, __m128* vertsOut);
    int pad04;
    int pad08;
    int pad0c;
    float m_fSphereRadius;
};
struct GskCache
{
    short m_kVertices[4];
    unsigned char m_ucDimensionA, m_ucDimensionB, m_features, unk17;
};
struct GskStatus
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_featureA;
    int m_featureB;
    int unk10;
    int unk14;
    int pad18;
    int pad1c;
    __m128 m_vertsA[12];
    __m128 m_vertsB[10];

    void hkpGsk_getClosestFeature(const void* shapeA, const void* shapeB, const hkTransform* bTa, void* out10);
    void hkpGsk_exitAndExportCacheImpl(void* cache);
    void hkpGsk_convertFeatureToClosestDistance(void* out10, hkContactPoint* pointOut);
};
extern "C"
{
    void _mm_store_ps(float*, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_set_ss(float);
}
static __forceinline short* unpackCache(GskCache& c, int& b, unsigned& f, int& a)
{
    b = c.m_ucDimensionB;
    f = c.m_features;
    a = c.m_ucDimensionA;
    return c.m_kVertices;
}
struct GskAgentStandin : public hkpGskBaseAgent
{
    int unk04;
    int unk08;
    GskCache m_pAccessManager;

    hkBool FUN_00dac7f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                        hkContactPoint& pointOut);
};
#include <windows.h>
struct S_00dac2b0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};
struct S_00dac2b0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00dac2b0_MonitorStream& GetMonitorStream()
    {
        return *(S_00dac2b0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00dac2b0_TimerCommand* h = (S_00dac2b0_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};
struct __declspec(align(16)) S_00dac2b0_Transform
{
    float m[16];
    void hkTransform_setMulInverseMul(const S_00dac2b0_Transform* a, const S_00dac2b0_Transform* b);
};
struct __declspec(align(16)) S_00dac2b0_Vec
{
    float x, y, z, w;
};
struct S_00dac2b0_Shape;
struct S_00dac2b0_Cache
{
    unsigned short id0, id1, id2, id3;
    unsigned char dimA, dimB, dims;
    void hkpGskCache_initTriangle(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t);
    void hkpGskCache_init(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t);
};
struct S_00dac2b0_Shape
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, S_00dac2b0_Vec* out) const;
    int unk04;
    int unk08;
    int m_type;
    float m_fSphereRadius;
};
struct __declspec(align(16)) S_00dac2b0_Gsk
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_maxA;
    int m_maxB;
    int m_iCachedVertexCount;
    int m_zero;
    int unk18;
    int unk1C;
    S_00dac2b0_Vec m_vertsA[12];
    S_00dac2b0_Vec m_vertsB[10];
    int hkpGsk_getClosestFeature(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t,
                     S_00dac2b0_Vec* out);
};
struct S_00dac2b0_Body
{
    const S_00dac2b0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00dac2b0_Transform* m_pMotionState;
};
struct S_00dac2b0_Collector
{
    virtual void v0();
    virtual void AddCdBodyPair(const S_00dac2b0_Body& a, const S_00dac2b0_Body& b);
};
void __cdecl TestGsk(const S_00dac2b0_Body& bodyA, const S_00dac2b0_Body& bodyB, const void* input,
                     S_00dac2b0_Collector& collector);
union EarlyScratch
{
    volatile unsigned int ticks;
    int result;
    float distance;
};
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern unsigned long hkMonitorStreamTls;
struct S_00dac0b0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};
struct S_00dac0b0_TimerBeginListCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    const char* m_pFirst;
};
struct S_00dac0b0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};
static inline void S_00dac0b0_TimerBeginList(const char* name, const char* firstSplit, EarlyScratch& scratch)
{
    S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00dac0b0_TimerBeginListCommand* h = (S_00dac0b0_TimerBeginListCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        h->m_pFirst = firstSplit;
        _ReadWriteBarrier();
        scratch.ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = scratch.ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void S_00dac0b0_Timer(const char* name, EarlyScratch& scratch)
{
    S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00dac0b0_TimerCommand* h = (S_00dac0b0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        scratch.ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = scratch.ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
static inline void S_00dac0b0_TimerEnd()
{
    {
        S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
        if (s->m_kRayEnd < s->m_pCurrentCommand)
        {
            S_00dac0b0_TimerCommand* h = (S_00dac0b0_TimerCommand*)s->m_kRayEnd;
            h->m_pCommandName = "lt";
            _ReadWriteBarrier();
            struct Tk
            {
                unsigned int v;
            };
            Tk t;
            *(volatile unsigned int*)&t.v = (unsigned int)__rdtsc();
            *(Tk*)&h->m_uiStartTicks = t;
            s->m_kRayEnd = (char*)(h + 1);
        }
    }
}
struct S_00dac0b0_Vertex
{
    float x, y, z, w;
};
struct S_00dac0b0_Transform
{
    S_00dac0b0_Vertex col0;
    S_00dac0b0_Vertex col1;
    S_00dac0b0_Vertex col2;
    S_00dac0b0_Vertex trans;
    void hkTransform_setMulInverseMul(const S_00dac0b0_Transform* a, const S_00dac0b0_Transform* b);
};
struct S_00dac0b0_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, S_00dac0b0_Vertex* out) const;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
};
struct S_00dac0b0_Body
{
    S_00dac0b0_Shape* m_pCollisionShape;
    int unk04;
    const S_00dac0b0_Transform* m_kMotionTransform;
};
struct S_00dac0b0_PackedCache
{
    unsigned short id0, id1, id2, id3;
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_flags;
};
struct S_00dac0b0_Gsk
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_ucLowNibble;
    int m_ucHighNibble;
    int m_iCachedVertexCount;
    int m_changed;
    int unk18;
    int unk1C;
    S_00dac0b0_Vertex a00;
    S_00dac0b0_Vertex a01;
    S_00dac0b0_Vertex a02;
    S_00dac0b0_Vertex a03;
    S_00dac0b0_Vertex a04;
    S_00dac0b0_Vertex a05;
    S_00dac0b0_Vertex a06;
    S_00dac0b0_Vertex a07;
    S_00dac0b0_Vertex a08;
    S_00dac0b0_Vertex a09;
    S_00dac0b0_Vertex a10;
    S_00dac0b0_Vertex a11;
    S_00dac0b0_Vertex b00;
    S_00dac0b0_Vertex b01;
    S_00dac0b0_Vertex b02;
    S_00dac0b0_Vertex b03;
    S_00dac0b0_Vertex b04;
    S_00dac0b0_Vertex b05;
    S_00dac0b0_Vertex b06;
    S_00dac0b0_Vertex b07;
    S_00dac0b0_Vertex b08;
    S_00dac0b0_Vertex b09;
    S_00dac0b0_Transform aTb;
    int hkpGsk_getClosestFeature(S_00dac0b0_Shape* a, S_00dac0b0_Shape* b, const S_00dac0b0_Transform& aTb, S_00dac0b0_Vertex* out);
    void hkpGsk_exitAndExportCacheImpl(S_00dac0b0_PackedCache* dst);
};
template <class T> struct S_00dac0b0_Pad
{
    T* m_p;
    T* val() const
    {
        return m_p;
    }
};
struct S_00dac0b0_Out
{
    virtual void v00();
    virtual void v04(const S_00dac0b0_Body& a, const S_00dac0b0_Body& b);
};
struct S_00dac0b0_Agent : hkpGskBaseAgent
{
    int unk04;
    int unk08;
    S_00dac0b0_PackedCache m_pAccessManager;
    int unk18;
    int unk1C;
    S_00dac0b0_Vertex m_sepNormal;
    void FUN_00dac0b0(S_00dac0b0_Pad<const S_00dac0b0_Body> pA, S_00dac0b0_Pad<const S_00dac0b0_Body> pB,
                      const void* input, S_00dac0b0_Pad<S_00dac0b0_Out> pOut);
};
