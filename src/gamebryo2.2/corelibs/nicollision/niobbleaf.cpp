// LocalVec: unit-local copy of the former shared stand-in Vec. Its Dot sums y*y first, unlike NiPoint3.h's in-class Dot (x87 operand order).
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
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPoint3.h"
#include <string.h>

// src/gamebryo2.2/corelibs/nicollision/niobbleaf.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niobbleaf.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00eb8250_Tri
{
    LocalVec3* m_kPointA;
    LocalVec3* m_kPointB;
    LocalVec3* m_iThirdValue;
};

struct S_00eb8250_Edges
{
    void* m_e0;
    void* m_e1;
    void* m_e2;
};

int __cdecl NiOBBLeaf_TestEdgeTri(void* a, void* b, S_00eb8250_Tri* tri, LocalVec3* n, float d, int p3, float p4, int p5,
                         int p6);

// Computes the triangle's normal and plane offset, then tests it against all three edge pairs via FUN_00eb7dc0, OR-ing the results.
// @fnv 0x00eb8250
// src: GAMEBRYO_LIB 0x00eb8250
int __cdecl NiOBBLeaf_FindIntersection(S_00eb8250_Edges* e, S_00eb8250_Tri* tri, int p3, float p4, int p5, int p6)
{
    LocalVec3 u, v, n;
    u.x = tri->m_kPointB->x - tri->m_kPointA->x;
    u.y = tri->m_kPointB->y - tri->m_kPointA->y;
    u.z = tri->m_kPointB->z - tri->m_kPointA->z;
    v.x = tri->m_iThirdValue->x - tri->m_kPointA->x;
    v.y = tri->m_iThirdValue->y - tri->m_kPointA->y;
    v.z = tri->m_iThirdValue->z - tri->m_kPointA->z;
    n.x = u.y * v.z - u.z * v.y;
    n.y = u.z * v.x - u.x * v.z;
    n.z = u.x * v.y - u.y * v.x;
    const LocalVec3& a = *tri->m_kPointA;
    float d = a.x * n.x + a.y * n.y + a.z * n.z;
    int r = NiOBBLeaf_TestEdgeTri(e->m_e0, e->m_e1, tri, &n, d, p3, p4, p5, p6);
    r |= NiOBBLeaf_TestEdgeTri(e->m_e0, e->m_e2, tri, &n, d, p3, p4, p5, p6);
    r |= NiOBBLeaf_TestEdgeTri(e->m_e1, e->m_e2, tri, &n, d, p3, p4, p5, p6);
    return r;
}

// FUN_00eb85d0 - 170 bytes.
//
// The pack's unit file is empty, so the whole object graph is modelled here
// from the disassembly of the original.
//
// Frame layout (ESP relative, the function has no frame pointer):
//   [esp-0x40] .. [esp-0x01]   one 0x40-byte local node structure
//       +0x00  shape*        (stack parameter 1)
//       +0x04  shape*        (stack parameter 2)
//       +0x08  shape*        (stack parameter 3)
//       +0x0c  shape*        (stack parameter 4)
//       +0x10  int           pointer handed to ComputeContactTime
//       +0x14  float[3]      in-vector, also handed to ComputeContactTime
//       +0x20  float[3]      out-vector of the first ProjectOntoAxes call
//       +0x2c  float[3]      out-vector of the second ProjectOntoAxes call
//       +0x38  shape*        &this->m_8c
//       +0x3c  shape*        &pObj->m_8c
//
// `this` (ECX) and the first stack argument are two physics objects of the
// same type: both own a sub-object at +0x04 and a shape at +0x8c.

struct FNV_Shape
{
    int unk00;
};

struct FNV_Vec3
{
    float x;
    float y;
    float z;
};

// the sub-object at +0x04 of a physics object; its method takes the node's
// in-vector and produces an out-vector.
struct FNV_Body
{
    int unk00;
    void ProjectOntoAxes(FNV_Vec3* in, FNV_Vec3* out);
};

struct FNV_Node
{
    FNV_Shape* m_00;
    FNV_Shape* m_04;
    FNV_Shape* m_08;
    FNV_Shape* m_0c;
    int m_10;
    FNV_Vec3 m_14;
    FNV_Vec3 m_20;
    FNV_Vec3 m_2c;
    FNV_Shape* m_38;
    FNV_Shape* m_3c;
};

struct FNV_PhysObj
{
    int unk00;
    FNV_Body m_04;
    double unk08;
    double unk10;
    double unk18;
    double unk20;
    double unk28;
    double unk30;
    double unk38;
    double unk40;
    double unk48;
    double unk50;
    double unk58;
    double unk60;
    double unk68;
    double unk70;
    double unk78;
    double unk80;
    int unk88;
    FNV_Shape m_8c;

    int RunSwapTests(FNV_Node* node);
    int NiOBBLeaf_FaceFaceCollision(FNV_PhysObj* pObj, FNV_Shape* a2, FNV_Shape* a3, FNV_Shape* a4, FNV_Shape* a5, unsigned char* a6);
};

extern int ComputeContactTime(FNV_PhysObj* a, FNV_PhysObj* b, int* c, FNV_Vec3* d);

// @fnv 0x00eb85d0
// src: GAMEBRYO_LIB 0x00eb85d0
int FNV_PhysObj::NiOBBLeaf_FaceFaceCollision(FNV_PhysObj* pObj, FNV_Shape* pShape0, FNV_Shape* pShape1, FNV_Shape* pShape2,
                              FNV_Shape* pShape3, unsigned char* pbResult)
{
    FNV_Node node;
    node.m_38 = 0;
    node.m_3c = 0;
    node.m_00 = pShape0;
    node.m_04 = pShape1;
    node.m_08 = pShape2;
    node.m_0c = pShape3;

    if (ComputeContactTime(this, pObj, &node.m_10, &node.m_14))
    {
        *pbResult = 1;
        node.m_38 = &this->m_8c;
        node.m_3c = &pObj->m_8c;
        this->m_04.ProjectOntoAxes(&node.m_14, &node.m_20);
        pObj->m_04.ProjectOntoAxes(&node.m_14, &node.m_2c);
        return this->RunSwapTests(&node);
    }
    return 0;
}

struct S_00eb8680_Sub
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
    int NiOBBox_TestIntersection(S_00eb8680_Sub* other);
    void UpdateWorldBounds(void* p);
};

struct S_00eb8680_Obj
{
    virtual bool vfn0();
    virtual bool vfn1();
    virtual bool vfn2(void* a, void* b, void* c, void* d, unsigned e, int f, int g);
    S_00eb8680_Sub sub;
    void* unk80;
    void* unk84;
    int unk88;
    __forceinline bool S_try(void* p, void* a2, void* a3, void* a4, unsigned n, int k1, int k2)
    {
        return vfn2(p, a2, a3, a4, n, k1, k2);
    }
    bool NiOBBLeaf_TestCollision(S_00eb8680_Obj* other, unsigned char* a2, unsigned char* a3, void* a4, unsigned count, int k1,
                      int k2);
};

// @fnv 0x00eb8680
// src: XBOX_PDB 0x00eb8680
bool S_00eb8680_Obj::NiOBBLeaf_TestCollision(S_00eb8680_Obj* other, unsigned char* pDataA, unsigned char* pDataB, void* a4,
                                  unsigned count, int k1, int k2)
{
    if (k1 != unk88)
    {
        sub.UpdateWorldBounds(pDataA + 0x68);
        unk88 = k1;
    }
    if (k2 != other->unk88)
    {
        other->sub.UpdateWorldBounds(pDataB + 0x68);
        other->unk88 = k2;
    }
    if (!sub.NiOBBox_TestIntersection(&other->sub))
        return false;
    if (other->vfn1() || count == 0 || (!other->unk80 && !other->unk84))
        return true;
    return S_try(other->unk80, pDataA, pDataB, a4, count - 1, k1, k2) ||
           S_try(other->unk84, pDataA, pDataB, a4, count - 1, k1, k2);
}

struct S_00eb8790_Transform
{
    int unk00;
};

struct S_00eb8790_Body
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
    S_00eb8790_Transform m_kMotionTransform;  // 68
};

struct S_00eb8790_Volume
{
    int unk00, unk04, unk08;
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
    void UpdateWorldBounds(const S_00eb8790_Transform& transform);
    int NiOBBox_TestIntersection(const S_00eb8790_Volume& other);
};

struct S_00eb8790_Node
{
    virtual void v0();
    virtual bool isLeaf();
    virtual void v2();
    virtual int NiOBBLeaf_FindCollisions(S_00eb8790_Node* other, int a1, int a2, S_00eb8790_Body* bodyA, S_00eb8790_Body* bodyB,
                             int a5, int depth, int stampA, int stampB, int a9);

    int NiOBBLeaf_FaceFaceCollision(S_00eb8790_Node* other, int a1, int a2, S_00eb8790_Body* bodyA, S_00eb8790_Body* bodyB, int a9);
    int NiOBBNode_BoxBoxCollision(S_00eb8790_Node* other, int a1, int a2, S_00eb8790_Body* bodyA, S_00eb8790_Body* bodyB, int a9);

    S_00eb8790_Volume m_iBufferSize;  // 04
    S_00eb8790_Node* m_childA;        // 80
    S_00eb8790_Node* m_childB;        // 84
    int m_stamp;                      // 88
};

// @fnv 0x00eb8790
// src: XBOX_PDB 0x00eb8790
int S_00eb8790_Node::NiOBBLeaf_FindCollisions(S_00eb8790_Node* other, int a1, int a2, S_00eb8790_Body* bodyA,
                                  S_00eb8790_Body* bodyB, int a5, int depth, int stampA, int stampB, int a9)
{
    if (stampA != m_stamp)
    {
        m_iBufferSize.UpdateWorldBounds(bodyA->m_kMotionTransform);
        m_stamp = stampA;
    }
    if (stampB != other->m_stamp)
    {
        other->m_iBufferSize.UpdateWorldBounds(bodyB->m_kMotionTransform);
        other->m_stamp = stampB;
    }
    if (!m_iBufferSize.NiOBBox_TestIntersection(other->m_iBufferSize))
        return 0;
    if (!other->isLeaf())
    {
        if (depth && (other->m_childA || other->m_childB))
        {
            int result = NiOBBLeaf_FindCollisions(other->m_childA, a1, a2, bodyA, bodyB, a5, depth - 1, stampA, stampB, a9);
            if (result >= 1)
                return result;
            S_00eb8790_Node* pChildB = other->m_childB;
            result = NiOBBLeaf_FindCollisions(pChildB, a1, a2, bodyA, bodyB, a5, depth - 1, stampA, stampB, a9);
            if (result >= 1)
                return result;
            return 0;
        }
        return NiOBBNode_BoxBoxCollision(other, a1, a2, bodyA, bodyB, a9);
    }
    if (a5 < 0 && depth < 0)
        return NiOBBLeaf_FaceFaceCollision(other, a1, a2, bodyA, bodyB, a9);
    return NiOBBNode_BoxBoxCollision(other, a1, a2, bodyA, bodyB, a9);
}

// ComputeBarycentric: barycentric-style solve over three edge vectors from a base point.
struct Vec3f
{
    float x;
    float y;
    float z;
    Vec3f(const Vec3f& a, const Vec3f& b) : x(a.x - b.x), y(a.y - b.y), z(a.z - b.z)
    {}
    float Dot(const Vec3f& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};

// Computes barycentric coordinates of a4 relative to triangle (a1,a2,base) and writes them to out.
// @fnv 0x00eb72b0
void ComputeBarycentric(const Vec3f* apVertex0, const Vec3f* apVertex1, const Vec3f* apVertex2, const Vec3f* apPoint,
                        Vec3f* apBarycentric)
{
    Vec3f p(*apVertex0, *apVertex2);
    Vec3f v1(*apVertex1, *apVertex2);
    Vec3f r(*apPoint, *apVertex2);

    float d11 = p.Dot(p);
    float fDot01 = p.Dot(v1);
    float fDot11 = v1.Dot(v1);
    float fDot02 = p.Dot(r);
    float fDot12 = v1.Dot(r);
    float fInvDenom = 1.0f / (d11 * fDot11 - fDot01 * fDot01);
    float s = (fDot11 * fDot02 - fDot01 * fDot12) * fInvDenom;
    apBarycentric->x = s;
    float t = (d11 * fDot12 - fDot01 * fDot02) * fInvDenom;
    apBarycentric->y = t;
    apBarycentric->z = 1.0f - s - t;
}

// @fnv 0x00ee8990
// src: COMMUNITY 0x00ee8990
bool NiObject_StreamCanSkip()
{
    return false;
}

inline LocalVec3::LocalVec3()
{}
inline LocalVec3::LocalVec3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
inline LocalVec3 LocalVec3::operator-(const LocalVec3& pt) const
{
    return LocalVec3(x - pt.x, y - pt.y, z - pt.z);
}
inline LocalVec3 LocalVec3::Cross(const LocalVec3& pt) const
{
    return LocalVec3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
}

struct SubA
{
    int unk00;
    void UpdateWorldBounds(void* p);
};

struct Node
{
    int unk00;
    int unk04;
    LocalVec3 m_08;
    float m_14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    LocalVec3 m_28;
};

struct Helper
{
    int unk00;
    Node* GetTexture(void* p);
};

struct Rec
{
    int unk00;
    int unk04;
    unsigned char m_08;
    int unk0c;
    unsigned char m_10;
    int unk14;
    Helper m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned char unk30;
    unsigned char m_31;
};

struct Owner
{
    int unk00;
    SubA m_04;
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
    int m_88;
    LocalVec3* m_8c;
    LocalVec3* m_90;
    LocalVec3* m_94;
};

extern "C" unsigned char __cdecl FUN_00eadb90(LocalVec3* a, LocalVec3* b, LocalVec3* c, LocalVec3* d, LocalVec3* e, unsigned char f, LocalVec3* g,
                                              float* h, float* i, int* j);

struct Obj5
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
    int m_68;
};

struct FUN_00eb8930_cls : Owner
{
    int NiOBBLeaf_FindIntersections(LocalVec3* a1, LocalVec3* a2, Rec* a3, unsigned char* out, Obj5* a5, int a6);
};

// Calls an intersection helper and, on success, stores its returned point and parameter in a node, with an optional triangle normal.
// @fnv 0x00eb8930
// src: XBOX_PDB 0x00eb8930
int FUN_00eb8930_cls::NiOBBLeaf_FindIntersections(LocalVec3* a1, LocalVec3* a2, Rec* apRec, unsigned char* pOutHit, Obj5* apObj5, int a6)
{
    if (a6 != m_88)
    {
        m_04.UpdateWorldBounds(&apObj5->m_68);
        m_88 = a6;
    }
    unsigned char flag = apRec->m_10;
    int index;
    float u;
    float t;
    LocalVec3 point;
    unsigned char ok = FUN_00eadb90(a1, a2, m_8c, m_90, m_94, flag, &point, &t, &u, &index);
    *pOutHit = ok;
    if (ok == 0)
        return 0;
    Node* n = apRec->m_18.GetTexture(apObj5);
    // The original point assignments copy all three float bit patterns.
    memcpy(&n->m_08, &point, sizeof(point));
    n->m_14 = t;
    if (apRec->m_31 != 0)
    {
        LocalVec3 ub = *m_90 - *m_8c;
        LocalVec3 wa = *m_94 - *m_8c;
        LocalVec3 cross = ub.Cross(wa);
        cross.Unitize_004a0c10();
        memcpy(&n->m_28, &cross, sizeof(cross));
    }
    return 0;
}

inline LocalVec::LocalVec()
{}
inline LocalVec::LocalVec(float a, float b, float c) : x(a), y(b), z(c)
{}
inline LocalVec LocalVec::operator+(const LocalVec& b) const
{
    LocalVec r;
    r.x = x + b.x;
    r.y = y + b.y;
    r.z = z + b.z;
    return r;
}
inline float LocalVec::Dot(const LocalVec& b) const
{
    return y * b.y + x * b.x + z * b.z;
}
inline LocalVec operator*(float s, const LocalVec& v)
{
    LocalVec r;
    r.x = v.x;
    r.x *= s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}
inline LocalVec ScaleVector(const LocalVec& v, float s)
{
    LocalVec r;
    r.x = v.x;
    r.x *= s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}
// Finds up to two intersection times and points where the moving segment start+velocity*t to end+velocity*t crosses the plane defined by normal and plane.
// @fnv 0x00eb7440
int __cdecl IntersectPlane(float duration, const LocalVec& normal, float plane, const LocalVec& velocity, const LocalVec& start,
                           const LocalVec& end, float& time0, LocalVec& point0, float& time1, LocalVec& point1)
{
    float delta = duration - 0.0f;
    float d00 = static_cast<const LocalVec&>((start + 0.0f * velocity)).Dot(normal) - plane;
    float d01 = static_cast<const LocalVec&>((end + 0.0f * velocity)).Dot(normal) - plane;
    float d10 = static_cast<const LocalVec&>((start + duration * velocity)).Dot(normal) - plane;
    float d11 = static_cast<const LocalVec&>((end + duration * velocity)).Dot(normal) - plane;
    int found = 0;
    if (d00 * d01 <= 0.0f)
    {
        if (d00 == 0.0f && d01 == 0.0f)
        {
            time0 = 0.0f;
            time1 = 0.0f;
            point0 = start + time0 * velocity;
            point1 = end + ScaleVector(velocity, time1);
            return 1;
        }
        time0 = 0.0f;
        float fraction = d00 / (d00 - d01);
        point0 = ((1.0f - fraction) * start + fraction * end) + 0.0f * velocity;
        found = 1;
    }
    if (d00 * d10 <= 0.0f)
    {
        if (d00 == 0.0f && d10 == 0.0f)
        {
            time0 = 0.0f;
            time1 = duration;
            point0 = start + time0 * velocity;
            point1 = start + time1 * velocity;
            return 1;
        }
        float time = 0.0f + delta * d00 / (d00 - d10);
        LocalVec point = start + time * velocity;
        if (found)
        {
            time1 = time;
            point1 = point;
            if (time0 > time1)
            {
                float saved = time0;
                time0 = time1;
                time1 = saved;
                LocalVec savedPoint = point0;
                point0 = point1;
                point1 = savedPoint;
            }
            return 1;
        }
        time0 = time;
        point0 = point;
        found = 1;
    }
    if (d01 * d11 <= 0.0f)
    {
        if (d01 == 0.0f && d11 == 0.0f)
        {
            time0 = 0.0f;
            time1 = duration;
            point0 = end + time0 * velocity;
            point1 = end + time1 * velocity;
            return 1;
        }
        float time = 0.0f + delta * d01 / (d01 - d11);
        LocalVec point = end + time * velocity;
        if (found)
        {
            time1 = time;
            point1 = point;
            if (time0 > time1)
            {
                float saved = time0;
                time0 = time1;
                time1 = saved;
                LocalVec savedPoint = point0;
                point0 = point1;
                point1 = savedPoint;
            }
            return 1;
        }
        time0 = time;
        point0 = point;
        found = 1;
    }
    if (d10 * d11 <= 0.0f)
    {
        if (d10 == 0.0f && d11 == 0.0f)
        {
            time0 = duration;
            time1 = duration;
            point0 = start + ScaleVector(velocity, time0);
            point1 = end + time1 * velocity;
            return 1;
        }
        float fraction = d10 / (d10 - d11);
        LocalVec point = ((1.0f - fraction) * start + fraction * end) + duration * velocity;
        if (found)
        {
            time1 = duration;
            point1 = point;
            if (time0 > time1)
            {
                float saved = time0;
                time0 = time1;
                time1 = saved;
                LocalVec savedPoint = point0;
                point0 = point1;
                point1 = savedPoint;
            }
            return 1;
        }
        time0 = duration;
        point0 = point;
        found = 1;
    }
    if (found)
    {
        time1 = time0;
        point1 = point0;
        return 1;
    }
    return 0;
}

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
}
inline NiPoint3 NiPoint3::Cross(const NiPoint3& pt) const
{
    return NiPoint3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
}
inline float NiPoint3::operator*(const NiPoint3& pt) const
{
    return x * pt.x + y * pt.y + z * pt.z;
}
extern "C" void _ReadWriteBarrier();
inline NiPoint3 NiPoint3::operator+(const NiPoint3& pt) const
{
    return NiPoint3(x + pt.x, y + pt.y, z + pt.z);
}
inline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(inverse * x, inverse * y, inverse * z);
}
inline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
inline NiPoint3& NiPoint3::operator-=(const NiPoint3& pt)
{
    x -= pt.x;
    y -= pt.y;
    z -= pt.z;
    return *this;
}

inline NiPoint3 operator*(float k, const NiPoint3& p)
{
    return NiPoint3(k * p.x, k * p.y, k * p.z);
}
inline float DotThird(const NiPoint3& a, const NiPoint3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
struct S_eb6b90_Matrix
{
    float m_afEntries[3][3];
    S_eb6b90_Matrix()
    {}
};

struct S_eb6b90_Transform
{
    S_eb6b90_Matrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;

    S_eb6b90_Transform()
    {}
    void FUN_00a86bf0();
};

struct S_eb6b90_Root;
struct S_eb6b90_Box
{
    NiPoint3 m_kCenterPosition;
    NiPoint3 m_akBasis[3];
    float m_afExtents[3];
    NiPoint3 m_kWorldCenter;
    NiPoint3 m_akWorldBasis[3];
    float m_afWorldExtent[3];
    S_eb6b90_Root* m_pkTreeNode;

    NiPoint3& Center()
    {
        return m_kCenterPosition;
    }
    NiPoint3& Basis(int i)
    {
        return m_akBasis[i];
    }
    S_eb6b90_Box()
    {
        m_pkTreeNode = 0;
    }
    void UpdateWorldBounds(const S_eb6b90_Transform& kXform);  // Transform
};

struct S_eb6b90_Root;

struct S_eb6b90_Payload
{
    S_eb6b90_Box m_kBoundsBox;
    int unk80;
    int unk84;
    int unk88;
};
extern void* DAT_010f1b70;
struct S_eb6b90_Node
{

    virtual bool IsTerminalNode()
    {
        return false;
    }
    S_eb6b90_Payload payload;

    S_eb6b90_Node()
    {
        payload.unk88 = 0;
        payload.unk80 = 0;
        payload.unk84 = 0;
    }
};

struct FUN_00eb6b90 : S_eb6b90_Node
{
    NiPoint3* m_apkWorldVertex[3];

    FUN_00eb6b90(S_eb6b90_Root* pkRoot, unsigned short* pusTriList, NiPoint3* pkVertex,
                 NiPoint3* pkWorldVertex, unsigned short m_usTriangleID);
};

// Initializes a triangle node by computing its bounding box center, basis axes, and extents from three vertices.
// @fnv 0x00eb6b90
FUN_00eb6b90::FUN_00eb6b90(S_eb6b90_Root* pkRoot, unsigned short* pusTriList, NiPoint3* pkVertex,
                           NiPoint3* pkWorldVertex, unsigned short m_usTriangleID)
{
    unsigned short triStart = 3 * m_usTriangleID;
    unsigned short vi = pusTriList[triStart];
    m_apkWorldVertex[0] = pkWorldVertex + vi;
    const NiPoint3& kP0 = pkVertex[vi];
    ++triStart;
    vi = pusTriList[triStart];
    m_apkWorldVertex[1] = pkWorldVertex + vi;
    const NiPoint3& kP1 = pkVertex[vi];
    ++triStart;
    vi = pusTriList[triStart];
    m_apkWorldVertex[2] = pkWorldVertex + vi;
    const NiPoint3& kMid = pkVertex[vi];
    NiPoint3& kTargetCenter = payload.m_kBoundsBox.Center();
    NiPoint3* akAxis = payload.m_kBoundsBox.m_akBasis;
    float* extent = payload.m_kBoundsBox.m_afExtents;
    kTargetCenter = (kP0 + kP1 + kMid) / 3.0f;

    akAxis[0] = kP1 - kP0;
    akAxis[0].Unitize_004a0c10();
    akAxis[1] = kMid - kP0;
    float projection = akAxis[0] * akAxis[1];
    akAxis[1] -= projection * akAxis[0];
    akAxis[1].Unitize_004a0c10();
    akAxis[2] = akAxis[0].Cross(akAxis[1]);

    NiPoint3 minCoord(0.0f, 0.0f, 0.0f);
    NiPoint3 maxCoord(0.0f, 0.0f, 0.0f);
    NiPoint3 kDiff;
    float fX;
    float fY;
    float fZ;

    {
        kDiff = kP0 - kTargetCenter;
        fX = akAxis[0] * kDiff;
        fY = akAxis[1] * kDiff;
        fZ = akAxis[2] * kDiff;
        if (fX < minCoord.x)
            minCoord.x = fX;
        else if (fX > maxCoord.x)
            maxCoord.x = fX;
        if (fY < minCoord.y)
            minCoord.y = fY;
        else if (fY > maxCoord.y)
            maxCoord.y = fY;
        if (fZ < minCoord.z)
            minCoord.z = fZ;
        else if (fZ > maxCoord.z)
            maxCoord.z = fZ;
    }
    {
        kDiff = kP1 - kTargetCenter;
        fX = akAxis[0] * kDiff;
        fY = akAxis[1] * kDiff;
        fZ = akAxis[2] * kDiff;
        if (fX < minCoord.x)
            minCoord.x = fX;
        else if (fX > maxCoord.x)
            maxCoord.x = fX;
        if (fY < minCoord.y)
            minCoord.y = fY;
        else if (fY > maxCoord.y)
            maxCoord.y = fY;
        if (fZ < minCoord.z)
            minCoord.z = fZ;
        else if (fZ > maxCoord.z)
            maxCoord.z = fZ;
    }
    {
        kDiff = kMid - kTargetCenter;
        fX = akAxis[0] * kDiff;
        fY = akAxis[1] * kDiff;
        fZ = akAxis[2] * kDiff;
        if (fX < minCoord.x)
            minCoord.x = fX;
        else if (fX > maxCoord.x)
            maxCoord.x = fX;
        if (fY < minCoord.y)
            minCoord.y = fY;
        else if (fY > maxCoord.y)
            maxCoord.y = fY;
        if (fZ < minCoord.z)
            minCoord.z = fZ;
        else if (fZ > maxCoord.z)
            maxCoord.z = fZ;
    }

    NiPoint3 kExtent = 0.5f * (maxCoord - minCoord);
    extent[0] = kExtent.x;
    extent[1] = kExtent.y;
    extent[2] = kExtent.z;

    NiPoint3 kP2 = 0.5f * (maxCoord + minCoord);
    kTargetCenter += akAxis[0] * kP2.x + akAxis[1] * kP2.y + akAxis[2] * kP2.z;

    S_eb6b90_Transform usIndex;
    usIndex.FUN_00a86bf0();
    payload.m_kBoundsBox.UpdateWorldBounds(usIndex);

    payload.m_kBoundsBox.m_pkTreeNode = pkRoot;
}

int __cdecl IntersectPlane(float, LocalVec3*, float, int, void*, void*, float*, LocalVec3*, float*,
                           LocalVec3*);
// Clips barycentric coordinates to the positive octant and updates the bound and point when a nearer candidate is found.
// @fnv 0x00eb7dc0
// src: GAMEBRYO_LIB 0x00eb7dc0
int __cdecl NiOBBLeaf_TestEdgeTri(void* a, void* b, S_00eb8250_Tri* apTriangle, LocalVec3* apNormal, float d, int p3,
                         float p4, volatile int apNearestDistance, int apHitPoint)
{
    float t;
    struct Geometry
    {
        float distanceA, distanceB;
        LocalVec3 coordA, distance, pointB, pointA;
    } g;
    (void)g.distanceB;
    if (!IntersectPlane(p4, apNormal, d, p3, a, b, &g.distanceA, &g.coordA, &g.distanceB, &g.distance))
        goto noHit;
    ComputeBarycentric((const Vec3f*)apTriangle->m_kPointA, (const Vec3f*)apTriangle->m_kPointB, (const Vec3f*)apTriangle->m_iThirdValue,
                       (const Vec3f*)&g.coordA, (Vec3f*)&g.pointA);
    ComputeBarycentric((const Vec3f*)apTriangle->m_kPointA, (const Vec3f*)apTriangle->m_kPointB, (const Vec3f*)apTriangle->m_iThirdValue,
                       (const Vec3f*)&g.distance, (Vec3f*)&g.pointB);
    do
    {
        if (g.pointA.x < 0.0f)
        {
            if (g.pointB.x < 0.0f)
                return 0;
            t = g.pointA.x / (g.pointA.x - g.pointB.x);
            float clippedy = t * g.pointB.y + (1.0f - t) * g.pointA.y;
            if (!(clippedy >= 0.0f))
                goto noHit;
            float clippedz = t * g.pointB.z + (1.0f - t) * g.pointA.z;
            if (!(clippedz >= 0.0f))
                goto noHit;
            float* pNearestDistance = (float*)apNearestDistance;
            float fInterpDistance = t * g.distanceB + (1.0f - t) * g.distanceA;
            if (fInterpDistance < *pNearestDistance)
            {
                *pNearestDistance = fInterpDistance;
                g.pointB.x = t * g.distance.x;
                g.pointB.y = t * g.distance.y;
                g.pointB.z = t * g.distance.z;
                g.distanceB = 1.0f - t;
                g.pointA.x = g.distanceB * g.coordA.x;
                g.pointA.y = g.distanceB * g.coordA.y;
                g.pointA.z = g.distanceB * g.coordA.z;
                g.distance.x = static_cast<const volatile float&>(g.pointA.x) + g.pointB.x;
                g.distance.y = g.pointA.y + g.pointB.y;
                g.distance.z = g.pointA.z + g.pointB.z;
                memcpy((LocalVec3*)apHitPoint, &g.distance, sizeof(LocalVec3));
            }
            return 1;
        }
        else if (g.pointA.y < 0.0f)
        {
            if (g.pointB.y < 0.0f)
                break;
            t = g.pointA.y / (g.pointA.y - g.pointB.y);
            float clippedx = t * g.pointB.x + (1.0f - t) * g.pointA.x;
            if (!(clippedx >= 0.0f))
                return 0;
            float clippedz = t * g.pointB.z + (1.0f - t) * g.pointA.z;
            if (!(clippedz >= 0.0f))
                return 0;
            float* pNearestDistance = (float*)apNearestDistance;
            float fInterpDistance = t * g.distanceB + (1.0f - t) * g.distanceA;
            if (fInterpDistance < *pNearestDistance)
            {
                *pNearestDistance = fInterpDistance;
                g.pointB.x = t * g.distance.x;
                g.pointB.y = t * g.distance.y;
                g.pointB.z = t * g.distance.z;
                g.distanceB = 1.0f - t;
                g.pointA.x = g.distanceB * g.coordA.x;
                g.pointA.y = g.distanceB * g.coordA.y;
                g.pointA.z = g.distanceB * g.coordA.z;
                g.distance.x = static_cast<const volatile float&>(g.pointA.x) + g.pointB.x;
                g.distance.y = g.pointA.y + g.pointB.y;
                g.distance.z = g.pointA.z + g.pointB.z;
                memcpy((LocalVec3*)apHitPoint, &g.distance, sizeof(LocalVec3));
            }
            return 1;
        }
        else if (g.pointA.z < 0.0f)
        {
            if (g.pointB.z < 0.0f)
            {
            noHit:
                return 0;
            }
            t = g.pointA.z / (g.pointA.z - g.pointB.z);
            float clippedx = t * g.pointB.x + (1.0f - t) * g.pointA.x;
            if (clippedx >= 0.0f)
            {
                float clippedy = t * g.pointB.y + (1.0f - t) * g.pointA.y;
                if (!(clippedy >= 0.0f))
                    return 0;
                float* pNearestDistance = (float*)apNearestDistance;
                float fInterpDistance = t * g.distanceB + g.distanceA * (1.0f - t);
                if (fInterpDistance < *pNearestDistance)
                {
                    *pNearestDistance = fInterpDistance;
                    g.pointB.x = t * g.distance.x;
                    g.pointB.y = t * g.distance.y;
                    g.pointB.z = t * g.distance.z;
                    g.distanceB = 1.0f - t;
                    g.pointA.x = g.distanceB * g.coordA.x;
                    g.pointA.y = g.distanceB * g.coordA.y;
                    g.pointA.z = g.distanceB * g.coordA.z;
                    g.distance.x = static_cast<const volatile float&>(g.pointA.x) + g.pointB.x;
                    g.distance.y = g.pointA.y + g.pointB.y;
                    g.distance.z = g.pointA.z + g.pointB.z;
                    memcpy((LocalVec3*)apHitPoint, &g.distance, sizeof(LocalVec3));
                }
                return 1;
            }
        }
        else
        {
            goto inside;
        }
    } while (false);
    return 0;
inside:
    float* pNearestDistance = (float*)apNearestDistance;
    if (g.distanceA < *pNearestDistance)
    {
        *pNearestDistance = g.distanceA;
        memcpy((LocalVec3*)apHitPoint, &g.coordA, sizeof(LocalVec3));
    }
    return 1;
}

extern "C" __declspec(noalias) int __cdecl NiOBBLeaf_FindIntersection(S_00eb8250_Edges*, S_00eb8250_Tri*, const NiPoint3&, float,
                                                        float*, NiPoint3*);
struct PhysObjInfo
{
    int unk00;
    float duration;
    int unk08;
    int unk0c;
    NiPoint3 velocity;
};

struct PhysObj_eb83b0
{
    int unk00;
    FNV_Body m_04;
    double unk08;
    double unk10;
    double unk18;
    double unk20;
    double unk28;
    double unk30;
    double unk38;
    double unk40;
    double unk48;
    double unk50;
    double unk58;
    double unk60;
    double unk68;
    double unk70;
    int unk78;
    PhysObjInfo* unk7c;
    double unk80;
    int unk88;
    FNV_Shape m_8c;
};

// Computes the earliest collision time and contact point between two physical objects using their shapes, velocities, and duration.
// @fnv 0x00eb83b0
int ComputeContactTime(PhysObj_eb83b0* apObjA, PhysObj_eb83b0* apObjB, float* pfTimeOut, NiPoint3* apContactOut)
{
    PhysObjInfo* pInfoA = apObjA->unk7c;
    float duration = pInfoA->duration;
    NiPoint3* velocityB = &apObjB->unk7c->velocity;
    float timeA = 3.402823466e+38F;
    NiPoint3 vContactA, vContactB;
    NiPoint3 relativeVelocity;
    relativeVelocity = pInfoA->velocity - *velocityB;
    int hitA = NiOBBLeaf_FindIntersection((S_00eb8250_Edges*)&apObjA->m_8c, (S_00eb8250_Tri*)&apObjB->m_8c, relativeVelocity,
                            duration, &timeA, &vContactA);
    float timeB = 3.402823466e+38F;
    relativeVelocity = *velocityB - pInfoA->velocity;
    int hitB = NiOBBLeaf_FindIntersection((S_00eb8250_Edges*)&apObjB->m_8c, (S_00eb8250_Tri*)&apObjA->m_8c, relativeVelocity,
                            duration, &timeB, &vContactB);
    if (hitA)
    {
        if (hitB)
        {
            if (timeA <= timeB)
            {
                *pfTimeOut = timeA;
                *apContactOut = vContactA + timeA * (*velocityB);
            }
            else
            {
                *pfTimeOut = timeB;
                *apContactOut = vContactB + timeB * pInfoA->velocity;
            }
        }
        else
        {
            *pfTimeOut = timeA;
            *apContactOut = vContactA + timeA * (*velocityB);
        }
    }
    else
    {
        if (hitB)
        {
            *pfTimeOut = timeB;
            *apContactOut = vContactB + timeB * pInfoA->velocity;
        }
    }
    return hitA || hitB;
}
