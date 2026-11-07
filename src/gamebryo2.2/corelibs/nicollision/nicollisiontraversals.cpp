
// src/gamebryo2.2/corelibs/nicollision/nicollisiontraversals.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicollisiontraversals.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; RaycastShape/IntersectShape (0x00e993d0) use the stand-in's own operator/ctor bodies and a different x87 order than this unit's NiPoint3 bodies.
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
#include "../../../../include/Normal.h"
#include "../../../../include/NiPoint2.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/Bound.h"
#include "../../../../include/Mat3.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/Transform.h"

extern int DAT_0126fa68;
extern int DAT_0126fa6c;
extern int DAT_0126fa70;
extern int DAT_0126fa74;
extern float DAT_0126fa78;

// Stores f and the three components of p into globals and returns a pointer to DAT_0126fa68.
// @fnv 0x00e9c7d0
// src: GAMEBRYO_LIB 0x00e9c7d0
int* __cdecl NiCollisionConvert_ConvertToSphereBV_Fast(float afValue, int* apComponents)
{
    DAT_0126fa78 = afValue;
    DAT_0126fa6c = apComponents[0];
    DAT_0126fa70 = apComponents[1];
    DAT_0126fa74 = apComponents[2];
    return &DAT_0126fa68;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern int _NiPoint3_ZERO;
struct Obj
{
    int f0;
    int f4;
    int f8;
    int fC;
    float f10;
    Obj* InitFromParams(float, int*);
};
// @fnv 0x00e9c800
// src: COMMUNITY 0x00e9c800
Obj* NiCollisionConvert_ConvertToSphereBV_Safe(float afValue, int* p)
{
    void* pMemory = g_memoryManager.Allocate(20);
    Obj* pObj;
    if (pMemory)
        pObj = ((Obj*)pMemory)->InitFromParams(1.0f, &_NiPoint3_ZERO);
    else
        pObj = 0;
    pObj->f10 = afValue;
    pObj->f4 = p[0];
    pObj->f8 = p[1];
    pObj->fC = p[2];
    return pObj;
}

struct SpawnParam
{
    int m_iType;
    int m_iSub;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

struct ItemOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int* m_pItems;
    unsigned short unkA4;
    unsigned short m_uiItemCount;
    int unkA8;
    int unkAC;
    int m_uiEdgeIndex;
};

bool __cdecl NiCollisionTraversals_FindIntersections(int a1, int a2, SpawnParam* p, int item);

// @fnv 0x00e9c680
// src: COMMUNITY 0x00e9c680
bool __cdecl NiCollisionTraversals_FindIntersectionsSwitchNode(int a1, int a2, SpawnParam* p, ItemOwner* owner)
{
    bool result = false;
    int idx = owner->m_uiEdgeIndex;
    if (idx < 0)
    {
        goto done;
    }
    if (p->m_iType == 1 && p->m_iSub == 1 && p->unk28 != 0)
    {
        return true;
    }
    if (owner->m_uiEdgeIndex < 0)
    {
        goto done;
    }
    if (idx >= owner->m_uiItemCount)
    {
        goto done;
    }
    {
        int item = owner->m_pItems[idx];
        if (item == 0)
        {
            goto done;
        }
        if (NiCollisionTraversals_FindIntersections(a1, a2, p, item))
        {
            result = true;
        }
    }
done:
    return result;
}

namespace fnv_00e9c6f0 {
extern int DAT_011f5eb4;

// Exe 0x00e9c6f0: unit-local ListNode view; declarations and layout are preserved.
struct NicollisiontraversalsListNodeView
{
    int unk00;
    NicollisiontraversalsListNodeView* m_pNext;
};

struct ItemOwner
{
    virtual void v00();
    virtual void v04();
    virtual NicollisiontraversalsListNodeView* v08();
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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int* m_pItems;
    unsigned short unkA4;
    unsigned short m_uiItemCount;
};

struct Dispatch
{
    void Run(ItemOwner* owner);
};

struct SpawnParam
{
    int m_iType;
    int m_iSub;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Dispatch m_sub;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

bool __cdecl NiCollisionTraversals_FindIntersections(int a1, int a2, SpawnParam* p, int item);
bool __cdecl NiCollisionTraversals_FindIntersectionsSwitchNode(int a1, int a2, SpawnParam* p, ItemOwner* owner);

// @fnv 0x00e9c6f0
// src: COMMUNITY 0x00e9c6f0
bool __cdecl NiCollisionTraversals_FindIntersectionsNode(int a1, int a2, SpawnParam* pSpawnParam, ItemOwner* owner)
{
    if (pSpawnParam->unk08 == 0 && pSpawnParam->m_iType == 1)
    {
        pSpawnParam->m_sub.Run(owner);
        return true;
    }

    if (owner != 0)
    {
        NicollisiontraversalsListNodeView* node = owner->v08();
        if (node != 0)
        {
            do
            {
                if (node == (NicollisiontraversalsListNodeView*)&DAT_011f5eb4)
                {
                    return NiCollisionTraversals_FindIntersectionsSwitchNode(a1, a2, pSpawnParam, owner);
                }
                node = node->m_pNext;
            } while (node != 0);
        }
    }

    bool result = false;
    for (unsigned int i = 0; i < owner->m_uiItemCount; ++i)
    {
        if (pSpawnParam->m_iType == 1 && pSpawnParam->m_iSub == 1 && pSpawnParam->unk28 != 0)
        {
            return true;
        }
        int item = owner->m_pItems[i];
        if (item != 0)
        {
            if (NiCollisionTraversals_FindIntersections(a1, a2, pSpawnParam, item))
            {
                result = true;
            }
        }
    }
    return result;
}
}  // namespace fnv_00e9c6f0

struct S_00e9c490_Entry
{
    int unk00;
    int unk04;
    NiPoint3 unk08;
    float unk14;
};
struct S_00e9c490_Pool
{
    int unk00;
    S_00e9c490_Entry* GetTexture(void* node);
};
struct S_00e9c490_Ctx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    short unk12;
    int unk14;
    S_00e9c490_Pool unk18;
};
struct S_00e9c490_Ref
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
    unsigned int unk30;
};
struct S_00e9c490_Node
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00e9c490_Ref* v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
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
    unsigned int unk30;
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
    NiPoint3 unk8c;
};
extern char DAT_0126fa64;
extern char DAT_0126fa65;
extern int DAT_011f4a48;
extern int DAT_011f5f64;
static const float DAT_01011d78 = 0.0f;
bool __cdecl RayIntersectsBound(S_00e9c490_Node* node, NiPoint3* p1, NiPoint3* p2);
bool __cdecl NiCollisionTraversals_FindIntersectionsNode(NiPoint3* p1, NiPoint3* p2, S_00e9c490_Ctx* ctx, S_00e9c490_Node* node);
bool __cdecl RaycastShape(NiPoint3* p1, NiPoint3* p2, S_00e9c490_Ctx* ctx, S_00e9c490_Node* node);
bool __cdecl NiObject_IsKindOf(const void* rtti, S_00e9c490_Node* node);

// @fnv 0x00e9c490
// src: COMMUNITY 0x00e9c490
bool __cdecl NiCollisionTraversals_FindIntersections(NiPoint3* pPoint1, NiPoint3* pPoint2, S_00e9c490_Ctx* pContext,
                          S_00e9c490_Node* node)
{
    if (!node)
        return false;
    if (pContext->unk11 && (node->unk30 & 1))
        return false;
    S_00e9c490_Ref* ref = node->v3();
    if (ref && (unsigned char)(ref->unk30 >> 21) & 1)
        return false;
    if (RayIntersectsBound(node, pPoint1, pPoint2) || (ref && (unsigned char)(ref->unk30 >> 13) & 1))
    {
        if (ref)
            return NiCollisionTraversals_FindIntersectionsNode(pPoint1, pPoint2, pContext, node);
        if (node->v7())
            return RaycastShape(pPoint1, pPoint2, pContext, node);
        if (DAT_0126fa65 && NiObject_IsKindOf(&DAT_011f4a48, node))
        {
            NiPoint3 d = node->unk8c.SubtractIntoVector(*pPoint1);
            if (pPoint2->DotProduct(d) < DAT_01011d78)
                return false;
            float len = d.FUN_00457990();
            pContext->unk18.GetTexture(node)->unk14 = len;
            return false;
        }
        if (DAT_0126fa64 && NiObject_IsKindOf(&DAT_011f5f64, node))
        {
            NiPoint3 d = node->unk8c.SubtractIntoVector(*pPoint1);
            if (pPoint2->DotProduct(d) < DAT_01011d78)
                return false;
            S_00e9c490_Entry* pEntry = pContext->unk18.GetTexture(node);
            float len = d.FUN_00457990();
            pEntry->unk14 = len;
            if (pContext->unk08 == 1)
            {
                // Use the scalar multiply ABI with an explicit result buffer to reuse d.
                typedef NiPoint3* (NiPoint3::*ScaleInto)(NiPoint3*, float) const;
                pEntry->unk08 = pPoint1->FUN_00439e90(
                    *(pPoint2->*reinterpret_cast<ScaleInto>(&NiPoint3::ApplyScaled))(&d, len));
            }
            return false;
        }
    }
    return false;
}

// @fnv 0x00e9c7c0
// src: XBOX_PDB 0x00e9c7c0
int NiBoundingVolume_Type()
{
    return -1;
}

#include <math.h>
#include "../../../../include/NiBoundingVolume.h"
#include "../../../../include/Vec4.h"
inline NiPoint2 NiPoint2::operator*(float f) const
{
    NiPoint2 r = *this;
    r.x *= f;
    r.y *= f;
    return r;
}
inline NiPoint2 NiPoint2::operator+(const NiPoint2& b) const
{
    NiPoint2 r = *this;
    r.x += b.x;
    r.y += b.y;
    return r;
}
// RaycastPoint: the point of RaycastGeometry (0x00e9a280) and its Pick/Geometry helpers. Same layout as NiPoint3, but
// its inline operators build their result component-wise in a temporary, while this unit's NiPoint3::operator-/operator*
// build theirs through the constructor (RaycastShape 0x00e9b4f0, OrientedBoxBound::ComputeFromPoints 0x00eadf30); one
// NiPoint3 cannot carry both bodies, and each form only matches its own functions (tried 2026-11-04).
class RaycastPoint
{
public:
    float x;
    float y;
    float z;

    __declspec(noalias) RaycastPoint() throw();
    RaycastPoint operator*(float f) const;
    RaycastPoint operator+(const RaycastPoint& rhs) const;
    RaycastPoint operator-(const RaycastPoint& rhs) const;
    RaycastPoint Cross(const RaycastPoint& rhs) const;
    float Length() const;
    float FUN_004a7290() const;
    __declspec(noalias) void Unitize_004a0c10();
};
inline RaycastPoint::RaycastPoint() throw() {}
inline RaycastPoint RaycastPoint::operator*(float f) const
{
    RaycastPoint r;
    r.x = x * f;
    r.y = y * f;
    r.z = z * f;
    return r;
}
inline RaycastPoint RaycastPoint::operator+(const RaycastPoint& b) const
{
    RaycastPoint r;
    r.x = x + b.x;
    r.y = y + b.y;
    r.z = z + b.z;
    return r;
}
inline RaycastPoint RaycastPoint::operator-(const RaycastPoint& b) const
{
    RaycastPoint r;
    r.x = x - b.x;
    r.y = y - b.y;
    r.z = z - b.z;
    return r;
}
inline RaycastPoint RaycastPoint::Cross(const RaycastPoint& b) const
{
    RaycastPoint r;
    r.x = y * b.z - z * b.y;
    r.y = z * b.x - x * b.z;
    r.z = x * b.y - y * b.x;
    return r;
}

RaycastPoint operator*(float f, const RaycastPoint& p)
{
    RaycastPoint r;
    r.x = f * p.x;
    r.y = f * p.y;
    r.z = f * p.z;
    return r;
}
struct P4
{
    float r, g, b, a;
    P4() : r(0), g(0), b(0), a(0)
    {}
    P4 operator*(float f) const
    {
        P4 c = *this;
        c.r *= f;
        c.g *= f;
        c.b *= f;
        c.a *= f;
        return c;
    }
    P4 operator+(const P4& d) const
    {
        P4 c = *this;
        c.r += d.r;
        c.g += d.g;
        c.b += d.b;
        c.a += d.a;
        return c;
    }
    P4 AddDelta(const P4&);
};
P4 __cdecl Object_ProcessAndReturnValue_00532f40(float, const P4&);
extern NiPoint2 DAT_011f4980;
extern P4 DAT_011a9be0;
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    RaycastPoint Apply(const RaycastPoint& p) const
    {
        RaycastPoint r;
        r.x = m00 * p.x + (m01 * p.y) + m02 * p.z;
        r.y = (((m10 * p.x) + m11 * p.y) + (p.z * m12));
        r.z = m20 * p.x + m21 * p.y + p.z * m22;
        return r;
    }
    RaycastPoint InverseRotatePoint(const RaycastPoint& p) const
    {
        RaycastPoint r;
        r.x = m00 * p.x + p.y * m10 + (m20 * p.z);
        r.y = ((m01 * p.x + p.y * m11) + (m21 * p.z));
        r.z = m02 * p.x + m12 * p.y + (m22 * p.z);
        return r;
    }
    RaycastPoint InverseRotateVector(const RaycastPoint& p) const
    {
        RaycastPoint r;
        r.x = m00 * p.x + m10 * p.y + m20 * p.z;
        r.y = p.x * m01 + m11 * p.y + m21 * p.z;
        r.z = (m02 * p.x + m12 * p.y + m22 * p.z);
        return r;
    }
    __declspec(noalias) RaycastPoint FUN_004b4500(const RaycastPoint*);
};

struct Buffer
{
    char* data;
    unsigned stride;
    bool owned;
    Buffer() : data(0), stride(0), owned(false)
    {}
    ~Buffer()
    {}
    RaycastPoint& Point(unsigned i) const
    {
        return *reinterpret_cast<RaycastPoint*>(data + stride * i);
    }
    NiPoint2& UV(unsigned i) const
    {
        return *reinterpret_cast<NiPoint2*>(data + stride * i);
    }
    void NiGeometryDataIteratorNiColorA_Get(unsigned, P4*);
};
struct GeometryData
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual unsigned short GetTriangleTotal();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RaycastPoint* positions;
    RaycastPoint* normals;
    P4* colors;
    NiPoint2* texcoords;
    struct Provider* provider;
    bool FUN_00a67360(bool);
    void NiGeometryData_UnlockPackedVertexData();
    void NiGeometryData_GetVerticesIterator(Buffer*);
    void GetBounds(Buffer*);
    void NiGeometryData_GetAdditionalColorData(Buffer*);
    void GetKeyAndMode(unsigned, Buffer*);
    unsigned short* FUN_00a7b850();
};
struct Provider
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool Available();
};
struct Geometry
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
    // NiTransform storage begins at 0x68 without SIMD alignment.
    unsigned char worldStorage[sizeof(Transform)];
    Transform& World()
    {
        return *reinterpret_cast<Transform*>(worldStorage);
    }
    // Transform also covers the padding at 0x9c through 0xa7.
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryData* data;
};
struct Hit
{
    int unk00, unk04;
    RaycastPoint point;
    float distance;
    unsigned short triangle, i0, i1, i2;
    NiPoint2 uv;
    RaycastPoint normal;
    P4 color;
};
struct HitList
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Hit* GetTexture(Geometry*);
};
struct Pick
{
    int mode;
    int sort;
    int unk08;
    int coordinates;
    bool GetFrontOnly() const
    {
        return frontOnly;
    }
    bool frontOnly;
    char unk11;
    short unk12;
    int unk14;
    HitList hits;
    bool wantUV, wantNormal, interpolateNormal, wantColor;
    bool GetUV() const
    {
        return wantUV;
    }
    bool GetPlaneNormal() const
    {
        return wantNormal;
    }
    bool GetColor() const
    {
        return wantColor;
    }
};
bool __cdecl FUN_00eadb90(const RaycastPoint*, const RaycastPoint*, const RaycastPoint*, const RaycastPoint*, const RaycastPoint*, bool, RaycastPoint*, float*, float*, float*);
// Tests a ray against geometry triangles when available and fills hit data, including optional interpolated attributes.
// @fnv 0x00e9a280
bool __cdecl RaycastGeometry(const RaycastPoint* origin, const RaycastPoint* direction, Pick* pick, Geometry* geometry)
{
    Transform& worldTransform = geometry->World();
    RaycastPoint delta;
    delta = *origin - *reinterpret_cast<const RaycastPoint*>(&worldTransform.position);
    float inverseScale;
    inverseScale = 1.0f / worldTransform.scale;
    RaycastPoint localOrigin = reinterpret_cast<Matrix&>(worldTransform.rotation).InverseRotatePoint(delta) * inverseScale;
    const Matrix& rotation = reinterpret_cast<Matrix&>(worldTransform.rotation);
    RaycastPoint localDirection = rotation.InverseRotateVector(*direction) * inverseScale;
    bool found = false;
    unsigned short count;
    count = geometry->data->GetTriangleTotal();
    bool locked = false;
    GeometryData* data = geometry->data;
    Buffer positionBuffer;
    RaycastPoint p0, p1, p2;
    RaycastPoint normal;
    RaycastPoint* positions = geometry->data->positions;
    if (!positions)
    {
        Provider* provider = data->provider;
        if (provider && provider->Available())
        {
            locked = data->FUN_00a67360(true);
            data->NiGeometryData_GetVerticesIterator(&positionBuffer);
        }
    }
    unsigned short* triangles = data->FUN_00a7b850();
    if (!triangles || (!positions && !positionBuffer.data))
    {
        Hit* hit;
        hit = pick->hits.GetTexture(geometry);
        RaycastPoint offset = *reinterpret_cast<const RaycastPoint*>(&geometry->World().position) - *origin;
        float distance;
        float squared = offset.x * offset.x + offset.y * offset.y + offset.z * offset.z;
        distance = (float)sqrt(squared);
        hit->distance = distance;
        return true;
    }
    for (unsigned short triangle = 0; triangle < count; ++triangle)
    {
        unsigned short i0, i1, i2;
        {
            unsigned index = 3 * triangle;
            i0 = triangles[index];
            i1 = triangles[index + 1];
            i2 = triangles[index + 2];
        }
        if (locked)
        {
            p0 = positionBuffer.Point(i0);
            p1 = positionBuffer.Point(i1);
            p2 = positionBuffer.Point(i2);
        }
        else
        {
            p0 = positions[i0];
            p1 = positions[i1];
            p2 = positions[i2];
        }
        RaycastPoint intersection;
        float distance, b1, b2;
        if (!FUN_00eadb90(&localOrigin, &localDirection, &p0, &p1, &p2, pick->GetFrontOnly(), &intersection, &distance,
                          &b1, &b2))
            continue;
        found = true;
        Hit* hit = pick->hits.GetTexture(geometry);
        if (pick->coordinates == 1)
            intersection =
                *reinterpret_cast<const RaycastPoint*>(&worldTransform.position) + reinterpret_cast<Matrix&>(worldTransform.rotation).Apply(intersection) * worldTransform.scale;
        hit->point = intersection;
        hit->distance = distance;
        hit->triangle = triangle;
        hit->i0 = i0;
        hit->i1 = i1;
        hit->i2 = i2;
        float b0;
        b0 = 1.0f - (b1 + b2);
        if (pick->GetUV())
        {
            Buffer uv;
            data->GetKeyAndMode(0, &uv);
            if (uv.data)
            {
                const NiPoint2& uv0 = uv.UV(i0);
                const NiPoint2& uv1 = uv.UV(i1);
                const NiPoint2& uv2 = uv.UV(i2);
                hit->uv = uv0 * b0 + uv1 * b1 + uv2 * b2;
            }
            else
            {
                NiPoint2* coords = geometry->data->texcoords;
                if (coords)
                    hit->uv = coords[i0] * b0 + coords[i1] * b1 + coords[i2] * b2;
                else
                    hit->uv = DAT_011f4980;
            }
        }
        else
            hit->uv = DAT_011f4980;
        if (pick->GetPlaneNormal())
        {
            Buffer normalBuffer;
            data->GetBounds(&normalBuffer);
            if (normalBuffer.data)
            {
                RaycastPoint n0 = normalBuffer.Point(i0), n1 = normalBuffer.Point(i1), n2 = normalBuffer.Point(i2);
                normal = n0 * b0 + n1 * b1 + n2 * b2;
            }
            else if (pick->interpolateNormal && geometry->data->normals)
            {
                RaycastPoint* normals;
                normals = geometry->data->normals;
                normal = normals[i0] * b0 + normals[i1] * b1 + normals[i2] * b2;
            }
            else
            {
                RaycastPoint edge2;
                RaycastPoint edge1;
                edge1 = p1 - p0;
                edge2 = p2 - p0;
                normal = edge1.Cross(edge2);
            }
            normal.Unitize_004a0c10();
            if (pick->coordinates == 1)
                normal = reinterpret_cast<Matrix&>(worldTransform.rotation).FUN_004b4500(&normal);
            hit->normal = normal;
        }
        else
            hit->normal = *reinterpret_cast<const RaycastPoint*>(&_NiPoint3_ZERO);
        if (pick->GetColor())
        {
            Buffer colorBuffer;
            data->NiGeometryData_GetAdditionalColorData(&colorBuffer);
            if (colorBuffer.data)
            {
                P4 c0, c1, c2;
                colorBuffer.NiGeometryDataIteratorNiColorA_Get(i0, &c0);
                colorBuffer.NiGeometryDataIteratorNiColorA_Get(i1, &c1);
                colorBuffer.NiGeometryDataIteratorNiColorA_Get(i2, &c2);
                hit->color = c0 * b0 + c1 * b1 + c2 * b2;
            }
            else
            {
                P4* colors = geometry->data->colors;
                if (colors)
                {
                    P4 blended = Object_ProcessAndReturnValue_00532f40(b0, colors[i0])
                                     .AddDelta(Object_ProcessAndReturnValue_00532f40(b1, colors[i1]))
                                     .AddDelta(Object_ProcessAndReturnValue_00532f40(b2, colors[i2]));
                    hit->color = blended;
                }
                else
                    hit->color = DAT_011a9be0;
            }
        }
        else
            hit->color = DAT_011a9be0;
        if (1 == pick->mode && pick->sort == 1)
        {
            if (locked)
                data->NiGeometryData_UnlockPackedVertexData();
            return true;
        }
    }
    if (locked)
        data->NiGeometryData_UnlockPackedVertexData();
    return found;
}

extern char DAT_011f4248;
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
__forceinline NiPoint3::NiPoint3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
__forceinline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
}
__forceinline NiPoint3 NiPoint3::operator*(float f) const
{
    return NiPoint3(x * f, y * f, z * f);
}

__forceinline void ScaleOut(float f, NiPoint3& o, const NiPoint3& v)
{
    o.x = (((f * v.x)));
    o.y = f * v.y;
    o.z = f * v.z;
}

__forceinline void DotOut(const NiPoint3& a, const NiPoint3& b, float& o)
{
    o = a.x * b.x + a.y * b.y + a.z * b.z;
}
__forceinline void Dot0(const NiPoint3& a, const float& by, const float& bx, const float& bz, float& o)
{
    o = (((a.x * bx)) + (a.y * by) + (a.z) * bz);
}
__forceinline void Dot1(const NiPoint3& a, float bz, float bx, float by, float& o)
{
    o = (a.x * bx + a.y * (float)by) + a.z * (float)bz;
}
__forceinline void Dot2(const NiPoint3& a, float bx, float by, float bz, float& o)
{
    o = ((a.x * bx) + (a.y) * by) + a.z * (float)bz;
}


struct OrientedBoxBound
{
    NiPoint3 m_kCenter;
    NiPoint3 m_akAxis0;
    NiPoint3 m_akAxis1;
    NiPoint3 m_akAxis2;
    float m_afExtent0;
    float m_afExtent1;
    float m_afExtent2;
    void ComputeFromPoints(unsigned short count, const NiPoint3* pts);
};
// Computes the box center, axes, and extents from points, with an axis-aligned fallback for degenerate dimensions.
// @fnv 0x00eadf30
void OrientedBoxBound::ComputeFromPoints(unsigned short count, const NiPoint3* apPoints)
{
    const NiPoint3* points = apPoints;
    float minZ, minY, minX;
    float afMin[3];
    float afMax[3];
    float afEigenvalue[3];
    float mat[9];
    float maxX = points[0].x;
    minX = maxX;
    float maxY = points[0].y;
    minY = maxY;
    float maxZ = points[0].z;
    minZ = maxZ;
    m_kCenter = points[0];
    for (unsigned short i = 1; i < count; ++i)
    {
        m_kCenter += points[i];
        if (points[i].x < minX)
            minX = points[i].x;
        else if (maxX < points[i].x)
            maxX = points[i].x;
        if (points[i].y < minY)
            minY = points[i].y;
        else if (maxY < points[i].y)
            maxY = points[i].y;
        if (points[i].z < minZ)
            minZ = points[i].z;
        else if (maxZ < points[i].z)
            maxZ = points[i].z;
    }
    NiPoint3 ptScaled;
    ScaleOut((float)(1.0f / (float)count), ptScaled, m_kCenter);
    m_kCenter = ptScaled;
    if (minX != maxX && minY != maxY && minZ != maxZ)
    {
        memcpy(mat, &DAT_011f4248, 36);
        for (unsigned short i = 0; i < count; ++i)
        {
            mat[0] += m_kCenter.x * m_kCenter.x;
            mat[1] += m_kCenter.y * m_kCenter.x;
            mat[2] += m_kCenter.z * m_kCenter.x;
            mat[4] += m_kCenter.y * m_kCenter.y;
            mat[5] += m_kCenter.z * m_kCenter.y;
            mat[8] += m_kCenter.z * m_kCenter.z;
        }
        mat[3] = mat[1];
        mat[6] = mat[2];
        mat[7] = mat[5];
        ((NiMatrix3*)mat)->EigenSolveSymmetric(afEigenvalue, (NiPoint3*)&m_akAxis0);
        afMin[0] = points[0].x - m_kCenter.x;
        afMin[1] = points[0].y - m_kCenter.y;
        afMin[2] = points[0].z - m_kCenter.z;
        memcpy(afMax, afMin, sizeof(afMax));
        for (unsigned short i = 1; i < count; ++i)
        {
            NiPoint3 ptDiff = points[i] - m_kCenter;
            float p0;
            Dot0(m_akAxis0, ptDiff.y, ptDiff.x, ptDiff.z, p0);
            if (p0 < afMin[0])
                afMin[0] = p0;
            else if (p0 > afMax[0])
                afMax[0] = p0;
            float p1;
            Dot1(ptDiff, m_akAxis1.z, m_akAxis1.x, m_akAxis1.y, p1);
            if (p1 < afMin[1])
                afMin[1] = p1;
            else if (p1 > afMax[1])
                afMax[1] = p1;
            float y;
            Dot2(ptDiff, m_akAxis2.x, m_akAxis2.y, m_akAxis2.z, y);
            if (y < afMin[2])
                afMin[2] = y;
            else if (y > afMax[2])
                afMax[2] = y;
        }
        float mid0 = (afMax[0] + afMin[0]) * 0.5;
        {
            NiPoint3 offset;
            ScaleOut(mid0, offset, m_akAxis0);
            m_kCenter += offset;
        }
        float mid1 = (afMax[1] + afMin[1]) * 0.5;
        {
            NiPoint3 offset;
            ScaleOut(mid1, offset, m_akAxis1);
            m_kCenter += offset;
        }
        float mid2 = (afMax[2] + afMin[2]) * 0.5;
        {
            NiPoint3 offset;
            ScaleOut(mid2, offset, m_akAxis2);
            m_kCenter += offset;
        }
        m_afExtent0 = (afMax[0] - afMin[0]) * 0.5;
        m_afExtent1 = (afMax[1] - afMin[1]) * 0.5;
        m_afExtent2 = (afMax[2] - afMin[2]) * 0.5;
    }
    else
    {
        m_akAxis0 = NiPoint3(1.0f, 0.0f, 0.0f);
        m_akAxis1 = NiPoint3(0.0f, 1.0f, 0.0f);
        m_akAxis2 = NiPoint3(0.0f, 0.0f, 1.0f);
        float fExtentX = (maxX - minX) * 0.5;
        float fExtentY = (maxY - minY) * 0.5;
        float fExtentZ = (maxZ - minZ) * 0.5;
        if (fExtentX <= 0.0f)
            fExtentX = 0.1f;
        if (fExtentY <= 0.0f)
            fExtentY = 0.1f;
        if (fExtentZ <= 0.0f)
            fExtentZ = 0.1f;
        m_afExtent0 = fExtentX;
        m_afExtent1 = fExtentY;
        m_afExtent2 = fExtentZ;
    }
}

#include <math.h>
inline LocalVec3::LocalVec3() {}
// The Mat3 LocalVec3 members as RaycastShape/IntersectShape use them (Mat3.h declares the NiPoint3 ones).
struct Mat3LocalView : public Mat3
{
    LocalVec3 RotateCaptured(const LocalVec3& v, const float& cachedm01, const float& cachedm02, const float& cachedm10) const;
    LocalVec3 InverseRotate(const float& vx, const float& vy, const float& vz) const;
    __declspec(noalias) LocalVec3 FUN_004b4500(const LocalVec3& point) const;
};
inline LocalVec3 Mat3LocalView::RotateCaptured(const LocalVec3& v, const float& cachedm01, const float& cachedm02, const float& cachedm10) const
{
    LocalVec3 r;
    r.x = v.y * cachedm10 + m00 * v.x + m20 * v.z;
    r.y = v.x * cachedm01 + v.y * m11 + m21 * v.z;
    r.z = cachedm02 * v.x + m12 * v.y + v.z * m22;
    return r;
}
inline LocalVec3 Mat3LocalView::InverseRotate(const float& vx, const float& vy, const float& vz) const
{
    LocalVec3 r;
    r.x = vy * m10 + m00 * vx + m20 * vz;
    r.y = vx * m01 + vy * m11 + m21 * vz;
    r.z = m02 * vx + m12 * vy + vz * m22;
    return r;
}

inline void LocalVec3::AssignOutput(const LocalVec3& v)
{
    LocalVec3 copy(v);
    memcpy(this, &copy, 12);
}
inline LocalVec3::LocalVec3(float a, float b, float c) : x(a), y(b), z(c) {}
inline LocalVec3 LocalVec3::operator-(const LocalVec3& v) const
{
    LocalVec3 r(x - v.x, y - v.y, z - v.z);
    return r;
}
inline LocalVec3 LocalVec3::operator*(float f) const
{
    LocalVec3 r(x * f, y * f, z * f);
    return r;
}
inline LocalVec3 LocalVec3::Added(const LocalVec3& v) const
{
    LocalVec3 r(x + v.x, v.y + y, v.z + z);
    return r;
}

namespace fnv_00e993d0 {
// Keep vector copies as the original three-word memcpy.
inline void CopyVector(LocalVec3& destination, const LocalVec3& source)
{
    memcpy(&destination, &source, sizeof(LocalVec3));
}

inline LocalVec3 ScalePoint(float f, const LocalVec3& v)
{
    return v * f;
}

struct Vec2
{
    float x, y;
    Vec2()
    {}
    Vec2& operator*=(float f)
    {
        x *= f;
        y *= f;
        return *this;
    }
    Vec2& operator+=(const Vec2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    Vec2 operator+(const Vec2&) const;
};
extern Vec2 __cdecl FUN_00532fd0(float, const Vec2&);
extern LocalVec3 __cdecl FUN_004a3760(float, const LocalVec3&);
extern Vec4 __cdecl Object_ProcessAndReturnValue_00532f40(float, const Vec4&);

struct QueryResult
{

    int unk00, unk04;

    LocalVec3 point;

    float distance;

    unsigned short triangle, a, b, c;

    Vec2 uv;

    LocalVec3 normal;

    Vec4 tangent;
};

struct Output
{

    int unk00;

    QueryResult* GetTexture(void*);
};

struct Options
{

    int mode, stopAtFirst, unk08, coordinateMode;

    bool unk10;
    unsigned char unk11, unk12, unk13;

    int unk14;

    Output output;

    int unk1C, unk20, unk24, unk28, unk2C;

    unsigned char needsUV, needsNormal, needsTangent, needsColor;
};

struct BufferView
{

    LocalVec3* data;

    int stride;

    bool owned;
    void NiGeometryDataIteratorNiColorA_Get(unsigned int, Vec4*);
};

struct Stream
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
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual bool Available();
};
struct Mesh
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
    virtual void v3C();

    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();

    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();

    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();

    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();

    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();

    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();

    virtual void vA0();
    virtual void vA4();

    virtual unsigned short GetTriangleTotal();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;

    LocalVec3* vertices;

    LocalVec3* normals;

    Vec4* colors;

    Vec2* texcoords;

    Stream* stream;

    bool FUN_00a67360(int);

    void NiGeometryData_GetVerticesIterator(BufferView*);

    unsigned short* FUN_00a75f10();

    void NiGeometryData_UnlockPackedVertexData();

    void GetKeyAndMode(int, BufferView*);

    void GetBounds(BufferView*);

    void NiGeometryData_GetAdditionalColorData(BufferView*);
};

struct Shape
{

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;

    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;

    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;

    int unk60, unk64;

    // NiTransform storage begins at 0x68 without SIMD alignment.
    unsigned char worldStorage[sizeof(Transform)];
    Transform& World()
    {
        return *reinterpret_cast<Transform*>(worldStorage);
    }

    // Transform also covers the padding at 0x9c through 0xa7.
    int unkA8, unkAC, unkB0, unkB4;

    Mesh* mesh;
};

extern bool __cdecl FUN_00eadb90(const LocalVec3*, const LocalVec3*, const LocalVec3*, const LocalVec3*, const LocalVec3*, bool, LocalVec3*, float*,
                                 float*, float*);

extern Vec4 DAT_011a9be0;
extern LocalVec3 DAT_011f426c;
extern Vec2 DAT_011f4980;
// @fnv 0x00e993d0
bool __cdecl IntersectShape(const LocalVec3* rayStart, const LocalVec3* rayDirection, Options* options, Shape* shape)
{
    const Transform& xform = shape->World();
    double cachedm01 = reinterpret_cast<const Mat3&>(xform.rotation).m01;
    double cachedm02 = reinterpret_cast<const Mat3&>(xform.rotation).m02;
    double cachedm10 = reinterpret_cast<const Mat3&>(xform.rotation).m10;
    LocalVec3 difference = *rayStart - *reinterpret_cast<const LocalVec3*>(&xform.position);
    float invScale = 1.0f / xform.scale;
    CopyVector(difference, *reinterpret_cast<const LocalVec3*>(
        &reinterpret_cast<const Mat3LocalView&>(xform.rotation).InverseRotate(difference.x, difference.y, difference.z)));
    LocalVec3 localStart = difference * invScale;
    CopyVector(difference, *reinterpret_cast<const LocalVec3*>(
        &reinterpret_cast<const Mat3LocalView&>(xform.rotation).RotateCaptured(
            *reinterpret_cast<const ::LocalVec3*>(rayDirection), cachedm01, cachedm02, cachedm10)));
    LocalVec3 localDirection = difference * invScale;
    bool anyHit = false;
    const unsigned short triangleCount = shape->mesh->GetTriangleTotal();
    bool ownsPositions = false;
    Mesh* mesh = shape->mesh;
    BufferView positions = {0, 0, false};
    LocalVec3* directVertices = mesh->vertices;
    if (!directVertices)
    {
        Stream* stream = mesh->stream;
        if (stream && stream->Available())
        {
            ownsPositions = mesh->FUN_00a67360(1);
            mesh->NiGeometryData_GetVerticesIterator(&positions);
        }
    }
    unsigned short* triangles = mesh->FUN_00a75f10();
    if (triangles && (directVertices || positions.data))
    {
        for (unsigned short tri = 0; tri < triangleCount; ++tri)
        {
            unsigned short a, b, c;
            if (tri & 1)
            {
                a = triangles[tri + 1];
                b = triangles[tri];
            }
            else
            {
                a = triangles[tri];
                b = triangles[tri + 1];
            }
            c = triangles[tri + 2];
            if (a == b || b == c)
                continue;
            LocalVec3 va, vb, vc;
            if (!directVertices)
            {
                CopyVector(va, *(LocalVec3*)((unsigned char*)positions.data + a * positions.stride));
                CopyVector(vb, *(LocalVec3*)((unsigned char*)positions.data + b * positions.stride));
                CopyVector(vc, *(LocalVec3*)((unsigned char*)positions.data + c * positions.stride));
            }
            else
            {
                const LocalVec3& aVertex = directVertices[a];
                CopyVector(va, aVertex);
                const LocalVec3& bVertex = directVertices[b];
                CopyVector(vb, bVertex);
                const LocalVec3& cVertex = directVertices[c];
                CopyVector(vc, cVertex);
            }
            LocalVec3 point;
            float distance, u, v;
            bool frontOnly = options->unk10;
            if (!FUN_00eadb90(&localStart, &localDirection, &va, &vb, &vc, frontOnly, &point, &distance, &u, &v))
                continue;
            anyHit = true;
            QueryResult* result = options->output.GetTexture(shape);
            if (options->coordinateMode == 1)
            {
                const LocalVec3& rotated = *reinterpret_cast<const LocalVec3*>(
                    &reinterpret_cast<const Mat3LocalView&>(xform.rotation).FUN_004b4500(
                        *reinterpret_cast<const ::LocalVec3*>(&point)));
                float scale = xform.scale;
                LocalVec3 scaled(rotated.x * scale, rotated.y * scale, rotated.z * scale);
                CopyVector(point, scaled.Added(*reinterpret_cast<const LocalVec3*>(&xform.position)));
            }
            CopyVector(result->point, point);
            result->distance = distance;
            result->triangle = tri;
            result->a = a;
            result->b = b;
            result->c = c;
            float weight = 1.0f - (u + v);
            if (options->needsUV)
            {
                BufferView uv = {0, 0, false};
                mesh->GetKeyAndMode(0, &uv);
                if (uv.data)
                {
                    const Vec2* pa = (Vec2*)((unsigned char*)uv.data + a * uv.stride);
                    const Vec2* pb = (Vec2*)((unsigned char*)uv.data + b * uv.stride);
                    const Vec2* pc = (Vec2*)((unsigned char*)uv.data + c * uv.stride);
                    Vec2 tc = *pc;
                    tc *= v;
                    Vec2 tb = *pb;
                    tb *= u;
                    Vec2 ta = *pa;
                    ta *= weight;
                    Vec2 sum = ta;
                    sum += tb;
                    Vec2 value = sum;
                    value += tc;
                    result->uv = value;
                }
                else
                {
                    Vec2* texcoords = shape->mesh->texcoords;
                    if (texcoords)
                    {
                        Vec2 sum = FUN_00532fd0(weight, texcoords[a]) + FUN_00532fd0(u, texcoords[b]) +
                                   FUN_00532fd0(v, texcoords[c]);
                        result->uv = sum;
                    }
                    else
                        result->uv = DAT_011f4980;
                }
            }
            else
            {
                result->uv = DAT_011f4980;
            }
            if (options->needsNormal)
            {
                BufferView normals = {0, 0, false};
                mesh->GetBounds(&normals);
                LocalVec3 normal;
                if (normals.data)
                {
                    LocalVec3 na = *(LocalVec3*)((unsigned char*)normals.data + a * normals.stride);
                    LocalVec3 nb = *(LocalVec3*)((unsigned char*)normals.data + b * normals.stride);
                    LocalVec3 nc = *(LocalVec3*)((unsigned char*)normals.data + c * normals.stride);
                    const LocalVec3& sum = ((na * weight).Added(nb * u)).Added(nc * v);
                    CopyVector(normal, sum);
                }
                else
                {
                    LocalVec3* directNormals;
                    if (options->needsTangent && (directNormals = shape->mesh->normals) != 0)
                        CopyVector(normal, FUN_004a3760(weight, directNormals[a]) + FUN_004a3760(u, directNormals[b]) +
                                 FUN_004a3760(v, directNormals[c]));
                    else
                    {
                        LocalVec3 edge1, edge2;
                        CopyVector(edge1, vb - va);
                        CopyVector(edge2, vc - va);
                        CopyVector(normal, edge1.FUN_004b3800(edge2));
                    }
                }
                reinterpret_cast<RaycastPoint&>(normal).Unitize_004a0c10();
                if (options->coordinateMode == 1)
                    CopyVector(normal, *reinterpret_cast<const LocalVec3*>(
                        &reinterpret_cast<const Mat3LocalView&>(xform.rotation).FUN_004b4500(
                            *reinterpret_cast<const ::LocalVec3*>(&normal))));
                result->normal.AssignOutput(normal);
            }
            else
                CopyVector(result->normal, DAT_011f426c);
            if (options->needsColor)
            {
                BufferView colors = {0, 0, false};
                mesh->NiGeometryData_GetAdditionalColorData(&colors);
                if (colors.data)
                {
                    Vec4 ca, cb, cc;
                    colors.NiGeometryDataIteratorNiColorA_Get(a, &ca);
                    colors.NiGeometryDataIteratorNiColorA_Get(b, &cb);
                    colors.NiGeometryDataIteratorNiColorA_Get(c, &cc);
                    Vec4 sum = Object_ProcessAndReturnValue_00532f40(weight, ca) + Object_ProcessAndReturnValue_00532f40(u, cb) + Object_ProcessAndReturnValue_00532f40(v, cc);
                    result->tangent = sum;
                }
                else
                {
                    Vec4* directColors = shape->mesh->colors;
                    if (directColors)
                    {
                        Vec4 sum = Object_ProcessAndReturnValue_00532f40(weight, directColors[a]) + Object_ProcessAndReturnValue_00532f40(u, directColors[b]) +
                                   Object_ProcessAndReturnValue_00532f40(v, directColors[c]);
                        result->tangent = sum;
                    }
                    else
                        result->tangent = DAT_011a9be0;
                }
            }
            else
                result->tangent = DAT_011a9be0;
            if (options->mode == 1 && options->stopAtFirst == 1)
            {
                if (ownsPositions)
                    mesh->NiGeometryData_UnlockPackedVertexData();
                return true;
            }
        }
        if (ownsPositions)
            mesh->NiGeometryData_UnlockPackedVertexData();
        return anyHit;
    }

    QueryResult* result = options->output.GetTexture(shape);
    LocalVec3 delta = *reinterpret_cast<const LocalVec3*>(&shape->World().position) - *rayStart;
    float squared = delta.y * delta.y + delta.x * delta.x + delta.z * delta.z;
    squared = sqrt(squared);
    result->distance = squared;
    return true;
}
}  // namespace fnv_00e993d0

inline void NiPoint3::AssignOutput(const NiPoint3& v)
{
    NiPoint3 copy(v);
    memcpy(this, &copy, 12);
}
inline NiPoint3 NiPoint3::Sum(const NiPoint3& v) const
{
    return NiPoint3(x + v.x, y + v.y, z + v.z);
}
inline NiPoint3 NiPoint3::Added(const NiPoint3& v) const
{
    return NiPoint3(x + v.x, v.y + y, v.z + z);
}

#include <math.h>
namespace fnv_00e9b4f0 {
inline NiPoint3 ScalePoint(float f, const NiPoint3& v)
{
    return v * f;
}

struct Vec2
{
    float x, y;
    Vec2()
    {}
    Vec2& operator*=(float f)
    {
        x *= f;
        y *= f;
        return *this;
    }
    Vec2& operator+=(const Vec2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    Vec2 operator+(const Vec2&) const;
};
extern Vec2 __cdecl FUN_00532fd0(float, const Vec2&);
extern NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);
extern Vec4 __cdecl Object_ProcessAndReturnValue_00532f40(float, const Vec4&);
extern __declspec(noalias) NiPoint3 __cdecl NiPoint3_TransformByMatrix3(const NiPoint3&, const float*);







struct QueryResult
{
    int unk00, unk04;
    NiPoint3 point;
    float distance;
    unsigned short triangle, a, b, c;
    void SetVertices(unsigned short i0, unsigned short i1, unsigned short i2)
    {
        a = i0;
        b = i1;
        c = i2;
    }
    Vec2 uv;
    NiPoint3 normal;
    Vec4 tangent;
};

struct Output
{
    int unk00;
    QueryResult* GetTexture(void*);
};

struct Options
{
    int mode, stopAtFirst, unk08, coordinateMode;
    bool unk10;
    unsigned char unk11, unk12, unk13;
    int unk14;
    Output output;
    int unk1C, unk20, unk24, unk28, unk2C;
    unsigned char needsUV, needsNormal, needsTangent, needsColor;
};

struct BufferView
{
    NiPoint3* data;
    int stride;
    bool owned;
    void NiGeometryDataIteratorNiColorA_Get(unsigned int, Vec4*);
};

struct Stream
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
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual bool Available();
};
struct Mesh
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
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual unsigned short GetTriangleTotal();
    virtual void GetTriangle(unsigned short, unsigned short*, unsigned short*, unsigned short*);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    NiPoint3* vertices;
    NiPoint3* normals;
    Vec4* colors;
    Vec2* texcoords;
    Stream* stream;
    int unk34, unk38, unk3C, unk40;
    unsigned short unk44;
    bool FUN_00a67360(int);
    void NiGeometryData_GetVerticesIterator(BufferView*);
    void NiGeometryData_UnlockPackedVertexData();
    void GetKeyAndMode(int, BufferView*);
    void GetBounds(BufferView*);
    void NiGeometryData_GetAdditionalColorData(BufferView*);
};

struct RTTI
{
    const char* name;
    const RTTI* parent;
};

struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual const RTTI* GetRTTI();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Bound* bound;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64;
    // NiTransform storage begins at 0x68 without SIMD alignment.
    unsigned char worldStorage[sizeof(Transform)];
    Transform& World()
    {
        return *reinterpret_cast<Transform*>(worldStorage);
    }
    // Transform also covers the padding at 0x9c through 0xa7.
    int unkA8, unkAC, unkB0, unkB4;
    Mesh* mesh;
    int unkBC;
};

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4a20;
extern GlobalObjectO2_00a7b610 g_011f4a40;
bool NiObject_IsKindOf(const void*, Shape*);
bool __cdecl RaycastGeometry(const NiPoint3*, const NiPoint3*, Options*, Shape*);
bool __cdecl IntersectShape(const NiPoint3*, const NiPoint3*, Options*, Shape*);

extern bool __cdecl FUN_00eadb90(const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*,
                                 bool, NiPoint3*, float*, float*, float*);

extern Vec4 DAT_011a9be0;
extern NiPoint3 DAT_011f426c;
extern Vec2 DAT_011f4980;
extern Bound DAT_011f4288;

inline bool IsKindOfType(const void* rtti, Shape* shape)
{
    for (const RTTI* r = shape->GetRTTI(); r; r = r->parent)
        if (r == rtti)
            return true;
    return false;
}

// Tests the ray against a shape's mesh or bound data and writes distance plus mesh hit attributes when available.
// @fnv 0x00e9b4f0
bool __cdecl RaycastShape(const NiPoint3* rayStart, const NiPoint3* rayDirection, Options* options, Shape* shape)
{
    NiPoint3 va, vb, vc;
    NiPoint3 normal;
    if (options->unk08 && !shape->unkBC)
    {
        if (IsKindOfType(&g_011f4a20, shape))
        {
            if (shape->mesh->unk44 == 1)
                return IntersectShape(rayStart, rayDirection, options, shape);
        }
        else if (NiObject_IsKindOf(&g_011f4a40, shape))
            return RaycastGeometry(rayStart, rayDirection, options, shape);
        const Transform& xform = shape->World();
        NiPoint3 difference = *rayStart - *reinterpret_cast<const NiPoint3*>(&xform.position);
        float invScale = (float)(1.0f / xform.scale);
        NiPoint3 localStart = NiPoint3_TransformByMatrix3(difference, &reinterpret_cast<const Mat3&>(xform.rotation).m00) * invScale;
        NiPoint3 localDirection = NiPoint3_TransformByMatrix3(*rayDirection, &reinterpret_cast<const Mat3&>(xform.rotation).m00) * invScale;
        bool anyHit = false;
        const unsigned short triangleCount = shape->mesh->GetTriangleTotal();
        bool ownsPositions = false;
        Mesh* mesh = shape->mesh;
        BufferView positions = {0, 0, false};
        NiPoint3* directVertices = mesh->vertices;
        if (!directVertices)
        {
            Stream* stream = mesh->stream;
            if (stream && stream->Available())
            {
                ownsPositions = mesh->FUN_00a67360(1);
                mesh->NiGeometryData_GetVerticesIterator(&positions);
            }
            if (!positions.data)
            {
                QueryResult* result = options->output.GetTexture(shape);
                NiPoint3 offset = reinterpret_cast<const NiPoint3*>(&shape->World().position)->SubtractIntoVector(*rayStart);
                result->distance = offset.FUN_00457990();
                return true;
            }
        }
        for (unsigned short tri = 0; tri < triangleCount; ++tri)
        {
            unsigned short a, b, c;
            shape->mesh->GetTriangle(tri, &a, &b, &c);
            if (!directVertices)
            {
                va = *(NiPoint3*)((unsigned char*)positions.data + a * positions.stride);
                vb = *(NiPoint3*)((unsigned char*)positions.data + b * positions.stride);
                vc = *(NiPoint3*)((unsigned char*)positions.data + c * positions.stride);
            }
            else
            {
                va = directVertices[a];
                vb = directVertices[b];
                vc = directVertices[c];
            }
            NiPoint3 point;
            float distance, u, v;
            bool frontOnly = options->unk10;
            if (FUN_00eadb90(&localStart, &localDirection, &va, &vb, &vc, frontOnly, &point, &distance, &u, &v))
            {
                anyHit = true;
                QueryResult* result = options->output.GetTexture(shape);
                if (options->coordinateMode == 1)
                {
                    point = ScalePoint(xform.scale, *reinterpret_cast<const NiPoint3*>(
                        &reinterpret_cast<const Mat3&>(xform.rotation).FUN_004b4500(
                            reinterpret_cast<const ::NiPoint3*>(&point))))
                        .Added(*reinterpret_cast<const NiPoint3*>(&xform.position));
                }
                result->point = point;
                result->distance = distance;
                result->triangle = tri;
                result->SetVertices(a, b, c);
                float weight = 1.0f - (u + v);
                if (options->needsUV)
                {
                    BufferView uv = {0, 0, false};
                    mesh->GetKeyAndMode(0, &uv);
                    if (uv.data)
                    {
                        const Vec2* pa = (Vec2*)((unsigned char*)uv.data + a * uv.stride);
                        const Vec2* pb = (Vec2*)((unsigned char*)uv.data + b * uv.stride);
                        const Vec2* pc = (Vec2*)((unsigned char*)uv.data + c * uv.stride);
                        Vec2 tc = *pc;
                        tc *= v;
                        Vec2 tb = *pb;
                        tb *= u;
                        Vec2 ta = *pa;
                        ta *= weight;
                        Vec2 sum = ta;
                        sum += tb;
                        Vec2 value = sum;
                        value += tc;
                        result->uv = value;
                    }
                    else
                    {
                        Vec2* texcoords = shape->mesh->texcoords;
                        if (texcoords)
                        {
                            Vec2 sum = FUN_00532fd0(weight, texcoords[a]) + FUN_00532fd0(u, texcoords[b]) +
                                       FUN_00532fd0(v, texcoords[c]);
                            result->uv = sum;
                        }
                        else
                            result->uv = DAT_011f4980;
                    }
                }
                else
                {
                    result->uv = DAT_011f4980;
                }
                if (options->needsNormal)
                {
                    BufferView normals = {0, 0, false};
                    mesh->GetBounds(&normals);
                    if (normals.data)
                    {
                        NiPoint3 na = *(NiPoint3*)((unsigned char*)normals.data + a * normals.stride);
                        NiPoint3 nb = *(NiPoint3*)((unsigned char*)normals.data + b * normals.stride);
                        NiPoint3 nc = *(NiPoint3*)((unsigned char*)normals.data + c * normals.stride);
                        normal = (na * weight).Sum(nb * u).Sum(nc * v);
                    }
                    else
                    {
                        NiPoint3* directNormals;
                        if (options->needsTangent && (directNormals = shape->mesh->normals) != 0)
                            normal = FUN_004a3760(weight, directNormals[a])
                                         .FUN_00439e90(FUN_004a3760(u, directNormals[b]))
                                         .FUN_00439e90(FUN_004a3760(v, directNormals[c]));
                        else
                        {
                            NiPoint3 edge1, edge2;
                            edge1 = vb - va;
                            edge2 = vc - va;
                            normal = edge1.FUN_004b3800(edge2);
                        }
                    }
                    // RaycastPoint declares the same normalize routine with its noalias contract.
                    reinterpret_cast<RaycastPoint&>(normal).Unitize_004a0c10();
                    if (options->coordinateMode == 1)
                        normal = *reinterpret_cast<const NiPoint3*>(
                            &reinterpret_cast<const Mat3&>(xform.rotation).FUN_004b4500(
                                reinterpret_cast<const ::NiPoint3*>(&normal)));
                    result->normal.AssignOutput(normal);
                }
                else
                    result->normal = DAT_011f426c;
                if (options->needsColor)
                {
                    BufferView colors = {0, 0, false};
                    mesh->NiGeometryData_GetAdditionalColorData(&colors);
                    if (colors.data)
                    {
                        // Preserve zero initialization and trivial copies for color samples.
                        P4 ca, cb, cc;
                        colors.NiGeometryDataIteratorNiColorA_Get(a, reinterpret_cast<Vec4*>(&ca));
                        colors.NiGeometryDataIteratorNiColorA_Get(b, reinterpret_cast<Vec4*>(&cb));
                        colors.NiGeometryDataIteratorNiColorA_Get(c, reinterpret_cast<Vec4*>(&cc));
                        Vec4 sum = Object_ProcessAndReturnValue_00532f40(weight, *reinterpret_cast<const Vec4*>(&ca))
                            + Object_ProcessAndReturnValue_00532f40(u, *reinterpret_cast<const Vec4*>(&cb))
                            + Object_ProcessAndReturnValue_00532f40(v, *reinterpret_cast<const Vec4*>(&cc));
                        memcpy(&result->tangent, &sum, sizeof(sum));
                    }
                    else
                    {
                        Vec4* directColors = shape->mesh->colors;
                        if (directColors)
                        {
                            Vec4 sum = Object_ProcessAndReturnValue_00532f40(weight, directColors[a]) + Object_ProcessAndReturnValue_00532f40(u, directColors[b]) +
                                       Object_ProcessAndReturnValue_00532f40(v, directColors[c]);
                            memcpy(&result->tangent, &sum, sizeof(sum));
                        }
                    }
                }
                else
                    result->tangent = DAT_011a9be0;
                if (options->mode == 1 && options->stopAtFirst == 1)
                {
                    if (ownsPositions)
                        mesh->NiGeometryData_UnlockPackedVertexData();
                    return true;
                }
            }
        }
        if (ownsPositions)
            mesh->NiGeometryData_UnlockPackedVertexData();
        return anyHit;
    }

    Bound sphere = shape->bound ? *shape->bound : DAT_011f4288;
    normal = *reinterpret_cast<const NiPoint3*>(&sphere.x) - *rayStart;
    float along = rayDirection->y * normal.y + normal.x * rayDirection->x + normal.z * rayDirection->z;
    if (along < 0.0f)
        return false;
    QueryResult* result = options->output.GetTexture(shape);
    along = normal.x * normal.x + normal.y * normal.y + normal.z * normal.z;
    result->distance = (float)sqrt((double)along);
    if (options->unk08 == 1)
    {
        NiPoint3 offset = *rayDirection * result->distance;
        NiPoint3 hit;
        hit.x = rayStart->x + offset.x;
        hit.y = rayStart->y + offset.y;
        hit.z = offset.z + rayStart->z;
        result->point = hit;
    }
    return true;
}
}  // namespace fnv_00e9b4f0

extern int DAT_011a946c;
extern int DAT_011a9478;
extern int DAT_011a9484;
extern int DAT_011a9490;
extern int DAT_011f426c;
struct TempBounds
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
    void ComputeFromPoints(unsigned int code, int* point);
};

struct Helper
{
    NiBoundingVolume* FUN_00ea0820(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);
};
// Builds temporary bounds from code and point, allocates a NiBoundingVolume, then copies the bounds into it.
// @fnv 0x00e9c850
// src: COMMUNITY 0x00e9c850
NiBoundingVolume* __cdecl NiCollisionConvert_ConvertToBoxBV(unsigned int code, int* point)
{
    if ((unsigned short)code == 0 || point == 0)
        return 0;
    TempBounds stBounds;
    stBounds.ComputeFromPoints(code, point);
    NiBoundingVolume* result = (NiBoundingVolume*)g_memoryManager.Allocate(0x40);
    if (result != 0)
        result = ((Helper*)result)
                     ->FUN_00ea0820(*(NiPoint3*)&DAT_011a9490, *(NiPoint3*)&DAT_011f426c, *(NiPoint3*)&DAT_011a946c,
                                    *(NiPoint3*)&DAT_011a9478, *(NiPoint3*)&DAT_011a9484);
    else
        result = 0;
    memcpy((char*)result + 4, &stBounds, 60);
    return result;
}
