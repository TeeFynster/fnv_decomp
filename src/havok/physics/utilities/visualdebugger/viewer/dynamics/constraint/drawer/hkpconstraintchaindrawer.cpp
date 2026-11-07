#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpconstraintchaindrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpconstraintchaindrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// LocalVec: unit-local copy of the former shared stand-in Vec. This unit uses the stand-in's matrix/SpeedTree members (FUN_00c7f640/FUN_00c7f700 transforms, FUN_00b12790/FUN_00b13040), which NiPoint3 does not have.
#include <xmmintrin.h>
class Matrix;
class Scalar;
class Simd;
class Tok;
class Mask;
class Elem;
class Iter;
class CIter;
class CMutIter;
class Mat3;
class Mat4;
class hkVector4;
class hkQuaternion;

class LocalVec
{
public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        struct
        {
            void* m_pData;
            int m_iArrayLength;
            int m_iCapacity;
        };
    };

    LocalVec();
    LocalVec(float a, float b, float c);
    // Keep the implicit copy constructor, copy assignment and destructor trivial.

    void negative(const LocalVec& n);
    void inv(const Matrix& m, const LocalVec& n);
    void point(const Matrix& m, const LocalVec& b);
    void difference(const LocalVec& a, const LocalVec& b);
    Scalar dot(const LocalVec& n) const;
    Scalar at(int i) const;
    void set(float a, float b, float c, float d);

    Simd lengthSquared() const;
    void mul(const Simd& factor);
    void SetProduct(const Simd& factor, const LocalVec& v);

    void resize(unsigned n);
    Tok& operator[](unsigned i);
    void release(int elemSize);

    LocalVec& operator-=(const LocalVec& v);
    LocalVec& operator+=(const LocalVec& v);
    LocalVec operator*(float scale) const;
    LocalVec operator+(const LocalVec& v) const;
    LocalVec operator-(const LocalVec& v) const;
    float Squared() const;
    float Length() const;
    float Normalize();
    float Dot(const LocalVec& v) const;
    LocalVec Cross(const LocalVec& v) const;
    LocalVec ApplyScaled(float scale);
    LocalVec ApplyScaled(float scale) const;
    void ProcessState_00acf580(unsigned n, Tok value);
    LocalVec GetNegatedVector();
    LocalVec GetNegatedVector() const;
    LocalVec FUN_0053d1a0(const LocalVec& v);
    LocalVec FUN_004b3800(const LocalVec& v);
    LocalVec FUN_004b3800(const LocalVec& v) const;
    LocalVec FUN_00439e90(const LocalVec& v);
    LocalVec FUN_00439e90(const LocalVec& v) const;
    LocalVec SubtractIntoVector(const LocalVec& v);
    LocalVec SubtractIntoVector(const LocalVec& v) const;
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    void FUN_006815c0();
    void ScaleComponents(float scale);
    LocalVec& ComputeValue_0063c8a0(const LocalVec& v);
    float FUN_004a7290();
    float FUN_004a7290() const;
    void SetQuaternionComponentsFromVector(const float* values);
    void FUN_00a38560();
    void NiQuaternion_ToRotation(void* value);

    LocalVec& ScaleByInverse(float divisor);
    float FUN_00457910();
    LocalVec* FastNavMeshTriLocation_GetLocation();
    bool HasEqualComponents(const LocalVec& v);

    __m128 get() const;
    void set(__m128 value);
    void operator=(const __m128& value);
    operator __m128() const;
    __m128& getQuad();
    const __m128& getQuad() const;
    __m128& quad();
    const __m128& quad() const;
    float& operator()(int component);
    const float& operator()(int component) const;
    void setZero4();
    void setSub4(const LocalVec& a, const LocalVec& b);
    void setAdd4(const LocalVec& a, const LocalVec& b);
    void setMul4(const LocalVec& a, const LocalVec& b);
    void setMul4(const Scalar& a, const LocalVec& b);
    void add4(const LocalVec& v);
    void mul4(const LocalVec& v);
    void mul4(const Scalar& value);
    void add3clobberW(const LocalVec& v);
    void sub3clobberW(const LocalVec& v);
    void setBroadcast3clobberW(const LocalVec& v, int component);
    Scalar horizontalAdd3() const;
    void setCross(const LocalVec& a, const LocalVec& b);
    Scalar dot3(const LocalVec& v) const;
    Scalar lengthSquared3() const;
    Scalar lengthInverse3() const;
    void normalize3();
    Scalar getSimdAt(int component) const;
    void setInterpolate4(const LocalVec& a, const LocalVec& b, const Scalar& fraction);
    void setAddMul4(const LocalVec& a, const LocalVec& b, const Scalar& scale);
    void setNeg4(const LocalVec& v);
    Mask compareLessThanZero4() const;
    void SetRotatedDirection(const hkQuaternion& rotation, const LocalVec& direction);
    void setRotatedTranslation(const hkQuaternion& rotation, const LocalVec& direction);
    void cross(const LocalVec& a, const LocalVec& b);
    Scalar squared() const;
    Scalar inverseLength() const;
    void normalize();
    void negate(const LocalVec& v);

    void setTransformedPos_00c7f640(const void* matrix, const hkVector4& point);
    void setTransformedPos_00c7f640(Mat4* matrix, void* point);
    void setTransformedPos_00c7f640(const void* matrix, const LocalVec* point);
    void setTransformedPos_00c7f640(const void* matrix, const void* point);
    void hkVector4_setRotatedDir(Mat3* matrix, void* point);
    void hkVector4_setRotatedDir(const void* matrix, const LocalVec* point);
    void Normalize_00b12790();
    void Diff_00b13040(LocalVec* out, const LocalVec* v);
    LocalVec* ScaleSwizzled(LocalVec* out, float factor);
    void AddVector(LocalVec* out, const LocalVec* v);
    float Dot(const LocalVec& v);
    LocalVec* FUN_004a3c90(const LocalVec* v);
    LocalVec* FUN_0062b0a0(LocalVec* out, LocalVec* v);
    LocalVec* hkVector4_lengthInverse3(LocalVec* target);

    void FUN_00cf7690(Elem* value);
    void UpdateState_00b1e970();
    Iter begin();
    Iter end();
    CIter UpdateState_00b33030(CIter first, CIter last);
    void m_vStrips_clear();
    unsigned int size() const;
    unsigned int capacity() const;
    void ClearAllElements();
    void B2EDestroyRange_Thunk(Elem* first, Elem* last);
    bool InitBuffer(unsigned int count);
    Elem* _Ucopy(Elem* first, Elem* last, Elem* out);
    LocalVec& CTreeEngine_SetLeafTextures(const LocalVec& v);
    CMutIter ProcessAndReturnValue_00aceb80(CMutIter first, CMutIter last);
    void ProcessState_00acac40();
    LocalVec& ReleaseStorage_00ad61e0(const LocalVec& v);
};
#include "../../../../../../../../../include/hkRotation.h"
#include "../../../../../../../../../include/hkTransform.h"

inline hkVector4::hkVector4(const hkVector4& o)
{
    m_vComponents = o.m_vComponents;
}
inline void hkVector4::operator=(const hkVector4& o)
{
    m_vComponents = o.m_vComponents;
}

inline hkRotation::hkRotation()
{}
inline hkRotation::hkRotation(const hkRotation& o)
    : m_kColumn0(o.m_kColumn0), m_kColumn1(o.m_kColumn1), m_kColumn2(o.m_kColumn2)
{}
inline void hkRotation::operator=(const hkRotation& o)
{
    m_kColumn0 = o.m_kColumn0;
    m_kColumn1 = o.m_kColumn1;
    m_kColumn2 = o.m_kColumn2;
}

struct RigidBody
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
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    hkTransform m_kMotionTransform;
};

struct StiffSpringInfo
{
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    hkVector4 m_extra;
};
struct BallSocketInfo
{
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
};
struct PoweredInfo
{
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    hkVector4 m_kRotationInA;
    hkVector4 m_kRotationInB;
    hkVector4 m_extra;
};

struct ChainData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType() const;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pConstraintInfo;
};

struct ChainInstance
{
    int unk00;
    int unk04;
    int unk08;
    ChainData* m_data;
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
    RigidBody** m_ppRigidBodies;
    int m_iActorEntryCount;
};

struct Sub
{
    void hkpPrimitiveDrawer_setDisplayHandler(void* a);
};
struct Listener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void Fire(LocalVec* a, LocalVec* b, unsigned c, int d, int e);
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
    hkVector4 m_posA;
    hkVector4 m_posB;
    LocalVec m40;
    float m4C;
    LocalVec m50;
    float m5C;
    hkRotation m_kFirstRotation;
    hkRotation m_kSecondRotation;
    Sub mC0;
    void hkpConstraintDrawer_drawPivots(int a, int b);
    void hkpConstraintDrawer_drawBodyFrames(int a, int b);
    void FireChainConstraints(ChainInstance* c, Listener* l, int a, int b);
};

// @fnv 0x00de6390
void Obj::FireChainConstraints(ChainInstance* apChain, Listener* apListener, int aiArg1, int aiArg2)
{
    ChainData* data = apChain->m_data;
    mC0.hkpPrimitiveDrawer_setDisplayHandler(apListener);
    int iPairCount = apChain->m_iActorEntryCount - 1;
    for (int iPair = 0; iPair < iPairCount; iPair++)
    {
        RigidBody* pBodyA = apChain->m_ppRigidBodies[iPair];
        RigidBody* pBodyB = apChain->m_ppRigidBodies[iPair + 1];
        const hkVector4* sourceB = reinterpret_cast<const hkVector4*>(&pBodyB->m_kMotionTransform);
        // Vector storage preserves the original copy without the flat transform's GS buffer classification.
        hkVector4 storageB[4] = { sourceB[0], sourceB[1], sourceB[2], sourceB[3] };
        hkVector4 storageA[4] = {
            reinterpret_cast<const hkVector4&>(pBodyA->m_kMotionTransform.m_kColumn0),
            reinterpret_cast<const hkVector4&>(pBodyA->m_kMotionTransform.m_kColumn1),
            reinterpret_cast<const hkVector4&>(pBodyA->m_kMotionTransform.m_kColumn2),
            reinterpret_cast<const hkVector4&>(pBodyA->m_kMotionTransform.m_vTranslation)
        };
        hkTransform& transformB = reinterpret_cast<hkTransform&>(storageB);
        hkTransform& transformA = reinterpret_cast<hkTransform&>(storageA);
        m_kSecondRotation = transformB.m_rotation;
        m_kFirstRotation = transformA.m_rotation;
        m_posB.m_vComponents = transformB.m_vTranslation;
        m_posA.m_vComponents = transformA.m_vTranslation;
        hkVector4 pivotB;
        hkVector4 pivotA;
        switch (data->getType())
        {
        case 100:
            pivotB = ((StiffSpringInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((StiffSpringInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        case 101:
            pivotB = ((BallSocketInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((BallSocketInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        case 102:
            pivotB = ((PoweredInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((PoweredInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        }
        m50.setTransformedPos_00c7f640(&transformB, pivotB);
        m40.setTransformedPos_00c7f640(&transformA, pivotA);
        hkpConstraintDrawer_drawPivots(aiArg1, aiArg2);
        hkpConstraintDrawer_drawBodyFrames(aiArg1, aiArg2);
        apListener->Fire(&m40, &m50, 0xffff0000, aiArg1, aiArg2);
    }
}
