#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/dynamics/constraint/util/hkpconstraintpivotsutil_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/dynamics/constraint/util/hkpconstraintpivotsutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/constraint/util/hkpconstraintpivotsutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/util/hkpconstraintpivotsutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00d85160 FUN_00d85160: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps(void);

// Preserve this unit's intrinsic storage while using the shared vector definition.
#define _INCLUDED_MM2
#include "../../../../../../include/hkVector4q.h"


struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;

    void setIdentityRotation()
    {
        m_kColumn0.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1.setZero4();
        m_kColumn1(1) = 1.0f;
        m_kColumn2.setZero4();
        m_kColumn2(2) = 1.0f;
    }
};

extern hkTransformq g_identityTransform;
extern float DAT_0104da48;

struct hkpShapeq
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;

    unsigned int getType() const
    {
        return m_type;
    }
};

struct hkpSphereShapeq : public hkpShapeq
{
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1C;

    hkpSphereShapeq(float radius) throw();
};

struct hkpCdBodyq
{
    const hkpShapeq* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyq* m_parent;

    hkpCdBodyq(const hkpShapeq* shape, const hkTransformq* t)
    {
        m_pCollisionShape = shape;
        m_pMotionState = t;
        m_uiCollisionShapeKey = 0xffffffff;
        m_parent = 0;
    }
};

struct hkContactPointq
{
    hkVector4q m_vContactPosition;
    hkVector4q m_vSeparatingNormal;
    void setDistance(float d)
    {
        m_vSeparatingNormal(3) = d;
    }
};

struct hkpCdPointCollectorq
{
    virtual void AddCdPoint(const void* point);
    float m_fEarlyOutDistance;
};

struct hkpClosestCdPointCollectorq : public hkpCdPointCollectorq
{
    hkContactPointq m_kPoint;
    const void* m_pRootCollidableA;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    const void* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    hkpClosestCdPointCollectorq()
    {
        reset();
    }
    void reset()
    {
        m_kPoint.setDistance(DAT_0104da48);
        m_fEarlyOutDistance = DAT_0104da48;
        m_pRootCollidableA = 0;
    }
    virtual void AddCdPoint(const void* point);
    bool DidHit() const
    {
        return m_pRootCollidableA != 0;
    }
};

struct hkpCollidableCollidableFilterq
{
    virtual int IsCollisionEnabled(const void* a, const void* b) const;
};
struct hkpShapeCollectionFilterq
{
    virtual int isCollisionEnabled2(const void* in, const void* a, const void* b, unsigned int k) const;
};
struct hkpRayShapeCollectionFilterq
{
    virtual int isCollisionEnabled3(const void* in, const void* s, unsigned int k) const;
};
struct hkpRayCollidableFilterq
{
    virtual int isCollisionEnabled4(const void* in, const void* c) const;
};

struct hkReferencedObjectq
{
    virtual ~hkReferencedObjectq();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct hkpCollisionFilterq : public hkReferencedObjectq,
                             public hkpCollidableCollidableFilterq,
                             public hkpShapeCollectionFilterq,
                             public hkpRayShapeCollectionFilterq,
                             public hkpRayCollidableFilterq
{
    int unk18;
    int unk1C;
    unsigned int m_type;
    int unk24;
    int unk28;
    int unk2C;

    hkpCollisionFilterq() throw();
    ~hkpCollisionFilterq() throw();
};

struct hkpNullCollisionFilterq : public hkpCollisionFilterq
{
    hkpNullCollisionFilterq()
    {
        m_type = 1;
    }
    virtual int IsCollisionEnabled(const void* a, const void* b) const;
    virtual int isCollisionEnabled2(const void* in, const void* a, const void* b, unsigned int k) const;
    virtual int isCollisionEnabled3(const void* in, const void* s, unsigned int k) const;
    virtual int isCollisionEnabled4(const void* in, const void* c) const;
};

struct hkpCollisionInputq
{
    void* m_pCollisionDispatcher;
    unsigned int m_collisionQuality;
    float m_fScalar;
    const hkpCollisionFilterq* m_iFilter;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

typedef void(__cdecl* GetClosestPointsFunc)(const hkpCdBodyq& bodyA, const hkpCdBodyq& bodyB,
                                            const hkpCollisionInputq& input, hkpCdPointCollectorq& collector);

struct AgentFuncsq
{
    void* m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    GetClosestPointsFunc m_getClosestPointsFunc;
    void* m_pLinearCastFunc;
    int m_flags;
};

struct hkpCollisionDispatcherq
{
    void* m_ppVirtualMethodTable;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    AgentFuncsq m_agent2Funcs[64];

    GetClosestPointsFunc getGetClosestPointsFunc(unsigned int typeA, unsigned int typeB) const
    {
        return m_agent2Funcs[m_agent2TypeMap[typeA][typeB]].m_getClosestPointsFunc;
    }
};

struct hkpWorldq
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    hkpCollisionInputq* m_pCollisionInput;
    int unk7C;
    hkpCollisionDispatcherq* m_pDispatcher;

    const hkpCollisionInputq* getCollisionInput() const
    {
        return m_pCollisionInput;
    }
    hkpCollisionDispatcherq* getCollisionDispatcher() const
    {
        return m_pDispatcher;
    }
};

// @fnv 0x00d85160
// src: GUESS 0x00d85160 (confidence: low)
unsigned int hkpWorldq_ProcessAndReturnValue_00d85160(hkpWorldq* world, const hkpShapeq* shape, const hkVector4q& position)
{
    hkpSphereShapeq sphere(0.01f);

    hkTransformq transform;
    transform.m_vTranslation = position;
    transform.setIdentityRotation();

    hkpCdBodyq bodyA(&sphere, &transform);
    hkpCdBodyq bodyB(shape, &g_identityTransform);

    hkpClosestCdPointCollectorq collector;

    GetClosestPointsFunc getClosestPoints =
        world->getCollisionDispatcher()->getGetClosestPointsFunc(sphere.getType(), shape->getType());

    hkpCollisionInputq input = *world->getCollisionInput();
    input.m_fScalar = 3.40282e+38f * 0.5f;

    hkpNullCollisionFilterq filter;
    input.m_iFilter = &filter;

    getClosestPoints(bodyA, bodyB, input, collector);

    if (collector.DidHit())
    {
        return collector.m_uiShapeKeyB;
    }
    return 0;
}
