
// src/fallout_shared/bgsprimitive_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/bgsprimitive.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../include/BSMultiBound.h"
#include "../../include/BSMultiBoundAABB.h"
#include "../../include/BSMultiBoundOBB.h"
#include "../../include/BSMultiBoundShape.h"
#include "../../include/BSMultiBoundSphere.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3 NiPoint3::operator+(const NiPoint3& point) const
{
    return NiPoint3(x + point.x, y + point.y, z + point.z);
}

inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}

inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include "../../include/MemoryManager.h"
#include "../../include/NiFrustumPlanes.h"
#include "../../include/NiObject.h"
#include "../../include/NiPlane.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
// PodPoint3: unit-local copy of the former shared stand-in Point3. Same layout as NiPoint3 but constructor-free (an aggregate under VC9): with NiPoint3, 0x00c38b00 does not match (POD construction/return; NiPoint3's user constructors change the code).
#include <stddef.h>
class PodPoint3
{
public:
    float x;
    float y;
    float z;

    // Legacy compilers require an aggregate for brace initialization.
#if !defined(_MSC_VER) || _MSC_VER >= 1800
    PodPoint3()
    {}
    PodPoint3(float fX, float fY, float fZ)
        : x(fX), y(fY), z(fZ)
    {}
#endif

    PodPoint3 operator+(const PodPoint3& other) const;
    PodPoint3 operator-(const PodPoint3& other) const;
    PodPoint3 operator-() const;
    PodPoint3 operator*(float scalar) const;
    float operator*(const PodPoint3& other) const;
    PodPoint3& operator+=(const PodPoint3& other);
    friend PodPoint3 operator*(float scalar, const PodPoint3& point);

    float DotPart(float value, const PodPoint3& point) const;
    float DotProduct(const PodPoint3& point) const;
    double DotProduct(const PodPoint3& point);
    float Length() const;

    PodPoint3& ScaleComponents(float scalar);
    PodPoint3 FUN_00439e90(const PodPoint3& shift) const;
    PodPoint3* FUN_00439e90(PodPoint3* output, const PodPoint3* other) const;
    PodPoint3 SubtractIntoVector(const PodPoint3& other) const;
    void SubtractIntoVector();
    PodPoint3 FUN_004b3800(const PodPoint3& axis) const;
    void Unitize_004a0c10();
    float FUN_00457910();
    float FUN_00457990() const;
    double FUN_004a7290();
    PodPoint3* FUN_006815c0();
    PodPoint3* SetComponents(float x, float y, float z);
    void FUN_0043d410(float x, int y, int z);
    char* GetViewerString_00a59af0(const char* text);

    static void* operator new[](size_t size);
    static void operator delete[](void* memory);
    static const PodPoint3 ZERO;
};
// LocalPt3: unit-local copy of the former shared stand-in Pt3. Same layout as NiPoint3; with NiPoint3, OccShape::FUN_00c387f0 (0x00c387f0) does not match (constructor/inline bodies differ).
class LocalPt3
{
public:
    float x;
    float y;
    float z;

    LocalPt3();
    LocalPt3(float fX, float fY, float fZ);

    LocalPt3 operator+(const LocalPt3& other) const;
    LocalPt3 operator-(const LocalPt3& other) const;
    LocalPt3 operator-() const;
    LocalPt3 operator*(float scale) const;
    LocalPt3& operator*=(float scale);
    bool operator!=(const LocalPt3& other) const;

    float Dot(const LocalPt3& other) const;
    float DotAccumulated(const LocalPt3& other) const;
    float DotPlane(const LocalPt3& other) const;
    float DotProduct(const LocalPt3& other) const;
    LocalPt3 Cross(const LocalPt3& other) const;
    float SqrLength() const;
    float Length2() const;
    float Length() const;
    float Len() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;

    void Unitize_004a0c10();
    LocalPt3* SubtractIntoVector(LocalPt3* out, LocalPt3* other);
    LocalPt3 SubtractIntoVector(const LocalPt3& rhs);
    bool FUN_00439090(LocalPt3* other);
    float FUN_00457990() const;

    static const LocalPt3 ms_kFirstPoint;
    static const LocalPt3 ms_kSecondPoint;
    static const LocalPt3 ms_kThirdPoint;
};
#include "../../include/NiMatrix3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../include/NiPoint3.h"
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

class ColorPair
{
  public:
    float r;
    float g;
    float b;
    bool operator==(const ColorPair& c) const
    {
        return r == c.r && g == c.g && b == c.b;
    }
};

class ColorPropertyBase
{
  public:
    bool BSMultiBoundShape_IsEqual(const ColorPropertyBase* pkOther);
};

class ColorProperty : public ColorPropertyBase
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ColorPair m_kPrimaryColor;  // +0x0c
    ColorPair m_kColorB;        // +0x18

    bool BSMultiBoundAABB_IsEqual(const ColorPropertyBase* pkObject);
};

// @fnv 0x00c38090
// src: XBOX_PDB 0x00c38090
bool ColorProperty::BSMultiBoundAABB_IsEqual(const ColorPropertyBase* pkObject)
{
    bool bEqual = BSMultiBoundShape_IsEqual(pkObject);
    if (bEqual)
    {
        const ColorProperty* pkOther = (const ColorProperty*)pkObject;
        bEqual = m_kPrimaryColor == pkOther->m_kPrimaryColor;
        bEqual &= m_kColorB == pkOther->m_kColorB;
    }
    return bEqual;
}

extern "C" double __cdecl fabs(double);

class Pt
{
  public:
    float x, y, z;
    Pt()
    {}
    Pt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    Pt operator-(const Pt& pt) const
    {
        return Pt(x - pt.x, y - pt.y, z - pt.z);
    }
};

inline float PtFabsf(float _X)
{
    return ((float)fabs((double)_X));
}
inline float PtFabs(float _X)
{
    return (PtFabsf(_X));
}
inline float PtAbs(float _X)
{
    return (PtFabs(_X));
}

class CenteredPointBounds
{
  public:
    int unk00;
    int unk04;
    int unk08;
    Pt m_kCenter;
    Pt m_kExtent;
    bool BSMultiBoundAABB_QPointWithin(const Pt& kPoint);
};

// @fnv 0x00c38a20
// src: XBOX_PDB 0x00c38a20
bool CenteredPointBounds::BSMultiBoundAABB_QPointWithin(const Pt& kPoint)
{
    Pt kDiff = kPoint - m_kCenter;
    return !(PtAbs(kDiff.x) - m_kExtent.x > 0.01f) && !(PtAbs(kDiff.y) - m_kExtent.y > 0.01f) &&
           !(PtAbs(kDiff.z) - m_kExtent.z > 0.01f);
}

extern int g_01202818;
extern void fnv_stub_grow(unsigned int, unsigned int);

struct Obj_0096a610
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    unsigned int __thiscall GetSize()
    {
        return unk08;
    }

    void __thiscall FUN_0096a610(const unsigned int& value)
    {
        unsigned int index = GetSize();
        unsigned int temp = value;
        unsigned int max = unk04;
        unsigned int base = unk00;
        if (index >= max)
            fnv_stub_grow(base, max);
        temp = temp + base;
        unk08 = index + 1;
        unk0C = temp;
    }
};

struct Obj_00a598f0
{
    unsigned int __thiscall ToString(const char* name);
};

struct C_00c36580
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
    Obj_00a598f0 unk24;

    void __thiscall AddPropertyNames(int value);
    void __thiscall BSMultiBoundOBB_GetViewerStrings(Obj_0096a610* value);
};

int __cdecl NiViewerStrings_NiGetViewerString_Title(int value);

// @fnv 0x00c36580
// src: XBOX_PDB 0x00c36580
void __thiscall C_00c36580::BSMultiBoundOBB_GetViewerStrings(Obj_0096a610* value)
{
    AddPropertyNames((int)value);

    int src = g_01202818;
    unsigned int first = (unsigned int)NiViewerStrings_NiGetViewerString_Title(src);
    value->FUN_0096a610(first);

    unsigned int second = unk24.ToString("Axis");
    value->FUN_0096a610(second);
}

// Previous geometry reconstruction credited to another contributor.

// Preserve the original empty element-construction loop for the shared POD type.
static __forceinline void InitializePoint3Array(PodPoint3* points, int count)
{
    while (--count >= 0)
        ++points;
}

inline PodPoint3 PodPoint3::operator-(const PodPoint3& p) const
{
    PodPoint3 result;
    result.x = x - p.x;
    result.y = y - p.y;
    result.z = z - p.z;
    return result;
}

namespace BoxGeometry {


struct Color
{
    float r, g, b, a;
};

extern Color DAT_011a9be0;
extern PodPoint3 DAT_011a946c, DAT_011a9478, DAT_011a9484;

struct GeometryData
{

    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    PodPoint3* vertices;

    unsigned int unk24;

    Color* colors;

    unsigned int unk2c, unk30, unk34, unk38, unk3c;

    bool* flags;

    unsigned short* FUN_00a7b850();

    __forceinline PodPoint3* GetVertices()
    {
        PodPoint3* result = vertices;
        return result;
    }

    __forceinline Color* GetColors()
    {
        Color* result = colors;
        return result;
    }

    __forceinline bool* GetFlags()
    {
        bool* result = flags;
        return result;
    }
};

struct Geometry
{

    unsigned int unk00;

    unsigned int unk04;

    unsigned int unk08;

    unsigned int unk0c;

    unsigned int unk10;

    unsigned int unk14;

    unsigned int unk18;

    unsigned int unk1c;

    unsigned int unk20;

    unsigned int unk24;

    unsigned int unk28;

    unsigned int unk2c;

    unsigned int unk30;

    unsigned int unk34;

    unsigned int unk38;

    unsigned int unk3c;

    unsigned int unk40;

    unsigned int unk44;

    unsigned int unk48;

    unsigned int unk4c;

    unsigned int unk50;

    unsigned int unk54;

    PodPoint3 position;

    unsigned int unk64;

    unsigned int unk68;

    unsigned int unk6c;

    unsigned int unk70;

    unsigned int unk74;

    unsigned int unk78;

    unsigned int unk7c;

    unsigned int unk80;

    unsigned int unk84;

    unsigned int unk88;

    unsigned int unk8c;

    unsigned int unk90;

    unsigned int unk94;

    unsigned int unk98;

    unsigned int unk9c;

    unsigned int unka0;

    unsigned int unka4;

    unsigned int unka8;

    unsigned int unkac;

    unsigned int unkb0;

    unsigned int unkb4;

    GeometryData* data;

    __forceinline GeometryData* GetData()
    {
        return data;
    }
};

// BSMultiBoundAABB's layout seen through this unit's PodPoint3 math: Center at +0x0c, half extents (m_kOffset) at +0x18;
// other units bind 0x00c39270 as BSMultiBoundAABB::FUN_00c39270. Not the 16-byte sphere Bound.
struct AABBDebugView
{

    unsigned int unk00, unk04, unk08;

    PodPoint3 center;

    float extentX, extentY, extentZ;
// src: XBOX_PDB 0x00c39270
    void BSMultiBoundAABB_GetVertices(PodPoint3* out)
    {
        PodPoint3 axisX = DAT_011a946c * extentX;
        PodPoint3 axisY = DAT_011a9478 * extentY;
        PodPoint3 axisZ = DAT_011a9484 * extentZ;
        out[0] = center + axisX + axisY + axisZ;
        out[1] = center + axisX + axisY - axisZ;
        out[2] = center + axisX - axisY + axisZ;
        out[3] = center + axisX - axisY - axisZ;
        out[4] = center - axisX + axisY + axisZ;
        out[5] = center - axisX + axisY - axisZ;
        out[6] = center - axisX - axisY + axisZ;
        out[7] = center - axisX - axisY - axisZ;
    }

    void BSMultiBoundAABB_MakeDebugGeom(Geometry*, Geometry*, Color);
};

// @fnv 0x00c38b00
// src: XBOX_PDB 0x00c38b00
void AABBDebugView::BSMultiBoundAABB_MakeDebugGeom(Geometry* lines, Geometry* triangles, Color color)
{

    PodPoint3 corners[8];
    InitializePoint3Array(corners, 8);

    BSMultiBoundAABB_GetVertices(corners);

    unsigned short edgesA[12][2] = {{0, 1}, {0, 2}, {1, 3}, {3, 2}, {4, 5}, {4, 6},
                                    {5, 7}, {7, 6}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

    unsigned short faces[12][3] = {{2, 3, 1}, {2, 1, 0}, {5, 7, 6}, {5, 6, 4}, {7, 2, 6}, {7, 3, 2},
                                   {4, 0, 5}, {5, 0, 1}, {6, 0, 4}, {6, 2, 0}, {3, 7, 1}, {7, 5, 1}};

    Color faceColor9 = color;

    Color edgeColor = DAT_011a9be0;

    PodPoint3* vertices9 = lines->GetData()->GetVertices();

    Color* colors8 = lines->GetData()->GetColors();

    bool* lineFlags9 = lines->GetData()->GetFlags();

    lines->position = center;

    for (int edge = 0; edge < 12; ++edge)
    {

        vertices9[2 * edge] = corners[edgesA[edge][0]] - center;

        colors8[2 * edge] = edgeColor;

        vertices9[2 * edge + 1] = corners[edgesA[edge][1]] - center;

        colors8[2 * edge + 1] = edgeColor;

        lineFlags9[2 * edge] = true;

        lineFlags9[2 * edge + 1] = false;
    }

    vertices9 = triangles->GetData()->GetVertices();

    colors8 = triangles->GetData()->GetColors();

    unsigned short* indices = triangles->GetData()->FUN_00a7b850();

    triangles->position = center;

    for (unsigned short triangle3 = 0; triangle3 < 12; ++triangle3)
    {

        vertices9[3 * triangle3] = corners[faces[triangle3][0]] - center;

        colors8[3 * triangle3] = faceColor9;

        vertices9[3 * triangle3 + 1] = corners[faces[triangle3][1]] - center;

        colors8[3 * triangle3 + 1] = faceColor9;

        vertices9[3 * triangle3 + 2] = corners[faces[triangle3][2]] - center;

        colors8[3 * triangle3 + 2] = faceColor9;

        indices[3 * triangle3] = 3 * triangle3;

        indices[3 * triangle3 + 1] = 3 * triangle3 + 1;

        indices[3 * triangle3 + 2] = 3 * triangle3 + 2;
    }
}

}

inline NiPoint2::NiPoint2(float fX, float fY)
{
    x = fX;
    y = fY;
}

namespace bs {


struct FUN_00c335d0 : NiObject
{
    NiPoint3 kTargetCenter;
    NiPoint2 m_kPoint2;
    NiMatrix3 kRotationBasis;
    int m_uiShapeType;
    NiFrustumPlanes m_kFrustumPlanes;
    NiPoint3 m_kCornerPoints[4];
    NiPoint3 m_kReferencePoint;
    bool m_bIsInFrustum;
    bool m_bIsVisible;
    bool m_bCornerVisible[4];
    bool m_bDecalTextureCreated;
    FUN_00c335d0* m_apDecalObjects[4];
    FUN_00c335d0();
    virtual ~FUN_00c335d0();
};

// @fnv 0x00c335d0
FUN_00c335d0::FUN_00c335d0()
{
    kTargetCenter = NiPoint3::ZERO;
    m_kPoint2 = NiPoint2(50.0f, 50.0f);
    kRotationBasis = NiMatrix3::IDENTITY;
    m_uiShapeType = 0;
    m_bDecalTextureCreated = true;
    for (int i = 0; i < 4; i++)
        m_apDecalObjects[i] = 0;
}
}

#include <math.h>
#include "../../include/NiRefObject.h"
struct SphereBound { float x, y, z, r; };

template <> inline NiPointer<BSMultiBoundShape>::operator BSMultiBoundShape*() const
{
    return m_pObject;
}

inline BSMultiBoundShape* BSMultiBound::GetShape() const
{
    return pShape;
}

inline float NiPlane::Distance(const NiPoint3& kPt) const
{
    // The original calls the out-of-line dot product (0x004b6190); NiPoint3.h defines Dot in its class.
    return reinterpret_cast<const NiPoint3*>(this)->DotProduct(kPt) - c;
}

// src: COMMUNITY 0x00c37a00
inline void BSMultiBoundShape::BSMultiBoundOBB_GetVertices(NiPoint3* pts)
{
    NiPoint3 axisX, axisY, axisZ;
    axisX *= static_cast<BSMultiBoundOBB*>(this)->m_kOffset.x;
    axisY *= static_cast<BSMultiBoundOBB*>(this)->m_kOffset.y;
    axisZ *= static_cast<BSMultiBoundOBB*>(this)->m_kOffset.z;
    pts[0] = reinterpret_cast<const NiPoint3&>(static_cast<BSMultiBoundOBB*>(this)->Center) - axisX - axisY - axisZ;
    pts[1] = reinterpret_cast<const NiPoint3&>(static_cast<BSMultiBoundOBB*>(this)->Center) + axisX - axisY - axisZ;
    pts[2] = reinterpret_cast<const NiPoint3&>(static_cast<BSMultiBoundOBB*>(this)->Center) + axisX + axisY - axisZ;
    pts[3] = reinterpret_cast<const NiPoint3&>(static_cast<BSMultiBoundOBB*>(this)->Center) - axisX + axisY - axisZ;
    pts[4] = reinterpret_cast<const NiPoint3&>(static_cast<BSMultiBoundOBB*>(this)->Center) - axisX - axisY + axisZ;
    pts[5] = reinterpret_cast<const NiPoint3&>(static_cast<BSMultiBoundOBB*>(this)->Center) + axisX - axisY + axisZ;
    pts[6] = reinterpret_cast<const NiPoint3&>(static_cast<BSMultiBoundOBB*>(this)->Center) + axisX + axisY + axisZ;
    pts[7] = reinterpret_cast<const NiPoint3&>(static_cast<BSMultiBoundOBB*>(this)->Center) - axisX + axisY + axisZ;
}

inline void BSMultiBoundShape::GetPlanes(NiPlane* planes)
{
    for (int i = 0; i < 3; i++)
    {
        NiPoint3 kNormal;
        float* pRow = reinterpret_cast<float*>(&static_cast<BSMultiBoundOBB*>(this)->unk24);
        kNormal.x = pRow[i];
        kNormal.y = pRow[i + 3];
        kNormal.z = pRow[i + 6];
        *reinterpret_cast<NiPoint3*>(&planes[i]) = kNormal;
        planes[i].c = kNormal.DotProduct(static_cast<BSMultiBoundOBB*>(this)->Center);  // out-of-line, as NiPlane::Distance
    }
}

// @fnv 0x00c369b0
// src: XBOX_PDB 0x00c369b0
int BSMultiBoundShape::BSMultiBoundOBB_CheckBound_00c369b0(BSMultiBound* p)
{
    int v = p->GetShape()->GetShapeType();
    if (v == 1)
    {
        BSMultiBoundShape* j = (BSMultiBoundShape*)p->GetShape();
        NiPoint3 e[8];
        j->BSMultiBoundAABB_GetVertices(e);
        NiPlane c[3];
        this->GetPlanes(c);
        for (int i = 0; i < 8; i++)
        {
            float dx = (float)fabs(c[0].Distance(*(NiPoint3*)&e[i]));
            if (dx - static_cast<BSMultiBoundAABB*>(this)->m_kOffset.x > 0.0)
                return 0;
            float dz = (float)fabs(c[1].Distance(*(NiPoint3*)&e[i]));
            if (dz - static_cast<BSMultiBoundAABB*>(this)->m_kOffset.y > 0.0)
                return 0;
            float dy = (float)fabs(c[2].Distance(*(NiPoint3*)&e[i]));
            if (dy - static_cast<BSMultiBoundAABB*>(this)->m_kOffset.z > 0.0)
                return 0;
        }
        return 2;
    }
    else if (v == 2)
    {
        BSMultiBoundShape* c = (BSMultiBoundShape*)p->GetShape();
        NiPoint3 j[8];
        c->BSMultiBoundOBB_GetVertices(j);
        NiPlane e[3];
        this->GetPlanes(e);
        for (int i = 0; i < 8; i++)
        {
            float dx = (float)fabs(e[0].Distance(*(NiPoint3*)&j[i]));
            if (dx - static_cast<BSMultiBoundAABB*>(this)->m_kOffset.x > 0.0)
                return 0;
            float dz = (float)fabs(e[1].Distance(*(NiPoint3*)&j[i]));
            if (dz - static_cast<BSMultiBoundAABB*>(this)->m_kOffset.y > 0.0)
                return 0;
            float dy = (float)fabs(e[2].Distance(*(NiPoint3*)&j[i]));
            if (dy - static_cast<BSMultiBoundAABB*>(this)->m_kOffset.z > 0.0)
                return 0;
        }
        return 2;
    }
    else if (v == 3)
    {
        BSMultiBoundShape* c = (BSMultiBoundShape*)p->GetShape();
        SphereBound j;
        c->va4(&j);
        return this->v98(&j);
    }
    return 0;
}

struct C37050_Plane
{
    float a, b, c, d;
    int ClassifyPoint(const PodPoint3& point) const;
};
inline bool NiFrustumPlanes::IsPlaneActive(unsigned int i)
{
    int unused[83];
    (void)unused;
    return ((1 << i) & m_uiActivePlaneMask) ? true : false;
}
// BSMultiBoundOBB has no FUN_00c37050 frustum overload in the shared header.
struct C37050_Bound
{
    void BSMultiBoundOBB_GetVertices(PodPoint3* corners);
    bool BSMultiBoundOBB_CompletelyWithinFrustum(const NiFrustumPlanes& frustum);
};
// @fnv 0x00c37050
// src: XBOX_PDB 0x00c37050
bool C37050_Bound::BSMultiBoundOBB_CompletelyWithinFrustum(const NiFrustumPlanes& frustum)
{
    PodPoint3 corners[8];
    InitializePoint3Array(corners, 8);
    BSMultiBoundOBB_GetVertices(corners);
    for (int i = 0; i < 6; i++)
    {
        if (const_cast<NiFrustumPlanes&>(frustum).IsPlaneActive(i))
        {
            for (int j = 0; j < 8; j++)
            {
                if (reinterpret_cast<const C37050_Plane&>(frustum.m_akPlanes[i]).ClassifyPoint(corners[j]) == 2)
                    return false;
            }
        }
    }
    return true;
}

static __forceinline void DeadQ1()
{
    int dq[1];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ4()
{
    int dq[4];
}
static __forceinline void DeadQ5()
{
    int dq[5];
}
static __forceinline void DeadQ6()
{
    int dq[6];
}

extern const double DAT_01016408;
struct Pt3Q
{
    float x, y, z;
    float DotProduct(const Pt3Q& o) const;
};
struct PlaneQ
{
    Pt3Q m_kPlaneNormal;
    float m_fPlaneConstant;
    PlaneQ()
    {
        FUN_00a69940();
    }
    void FUN_00a69940();
    float Distance(const Pt3Q& p)
    {
        return m_kPlaneNormal.DotProduct(p) - m_fPlaneConstant;
    }
};
static inline float DistOf(PlaneQ* pl, const Pt3Q& p)
{
    return pl->m_kPlaneNormal.DotProduct(p) - pl->m_fPlaneConstant;
}
static inline float AbsQ(float f)
{
    return fabs(f);
}
struct FrustQ
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    float m_fTolX, m_fTolY, m_fTolZ;
    void GetPlanes(PlaneQ* p);
    bool BSMultiBoundOBB_QPointWithin(const Pt3Q& kPt);
};
// @fnv 0x00c378c0
// src: XBOX_PDB 0x00c378c0
bool FrustQ::BSMultiBoundOBB_QPointWithin(const Pt3Q& kPt)
{
    PlaneQ akPlanes3[3];
    DeadQ6();
    GetPlanes(akPlanes3);
    {
        float fDistZ = AbsQ(akPlanes3[0].Distance(kPt));
        if (fDistZ - m_fTolX > DAT_01016408)
            return false;
        float fDistX9 = AbsQ(DistOf(&akPlanes3[1], kPt));
        if (fDistX9 - m_fTolY > DAT_01016408)
            return false;
    }
    float fDistY = AbsQ(DistOf(&akPlanes3[2], kPt));
    if (fDistY - m_fTolZ > DAT_01016408)
        return false;
    return true;
}

extern "C" double fabs(double);
extern double DAT_01012060;


inline LocalVec3::LocalVec3() {}
inline LocalVec3::LocalVec3(float a, float b, float c) : x(a), y(b), z(c) {}
inline LocalVec3 LocalVec3::operator-(const LocalVec3& v) const
{ return LocalVec3(x - v.x, y - v.y, z - v.z); }

__forceinline float AbsPoint(float x)
{
    return (double)(float)fabs((double)x);
}
struct Bound16
{
    LocalVec3 c;
    float r;
};
struct PtOp
{
    float x;
    float y;
    float z;
    PtOp SubtractIntoVector(const PtOp& o) const;
};
struct Prim;
struct Param
{
    int p_00;
    int p_04;
    int p_08;
    Prim* m_0c;
    __forceinline Prim* GetBV()
    {
        Prim* result = m_0c;
        return result;
    }
};
struct Prim
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
    virtual int v35();
    virtual void v36();
    virtual void v37();
    virtual int v38(void* p);
    virtual void v39();
    virtual void v40();
    virtual int v41(void* p);
    int m_04;
    int m_08;
    LocalVec3 m_kCenterPosition;
    LocalVec3 m_radii;
// src: COMMUNITY 0x00c39560
    inline bool BSMultiBoundAABB_FastPointWithin(LocalVec3 v)
    {
        LocalVec3 delta = v - m_kCenterPosition;
        return AbsPoint(delta.x) - m_radii.x <= 0.01 && AbsPoint(delta.y) - m_radii.y <= 0.01 &&
               AbsPoint(delta.z) - m_radii.z <= 0.01;
    }
    void BSMultiBoundOBB_GetVertices(LocalVec3* arr);
    int BSMultiBoundAABB_CheckBound(Param* arg);
};

// @fnv 0x00c384f0
// src: XBOX_PDB 0x00c384f0
int Prim::BSMultiBoundAABB_CheckBound(Param* arg)
{
    int mode_2 = arg->GetBV()->v35();
    if (mode_2 == 1)
    {
        Prim* q = arg->GetBV();
        LocalVec3 diff_2 = m_kCenterPosition - q->m_kCenterPosition;
        float resZ = AbsPoint(diff_2.x) + q->m_radii.x - m_radii.x;
        float resY4 = AbsPoint(diff_2.y) + q->m_radii.y - m_radii.y;
        float resX9 = AbsPoint(diff_2.z) + q->m_radii.z - m_radii.z;
        if (resZ > 0.0 || resY4 > 0.0 || resX9 > 0.0)
            return 0;
        return 2;
    }
    else if (mode_2 == 2)
    {
        Prim* q = arg->GetBV();
        if (!BSMultiBoundAABB_FastPointWithin(q->m_kCenterPosition))
            return 0;
        else
        {
            LocalVec3 arr[8];
            q->BSMultiBoundOBB_GetVertices(arr);
            for (int i3 = 0; i3 < 8; ++i3)
            {
                if (!BSMultiBoundAABB_FastPointWithin(arr[i3]))
                    return 0;
            }
            return 2;
        }
    }
    else if (mode_2 == 3)
    {
        Prim* q = arg->GetBV();
        Bound16 out;
        q->v41(&out);
        return v38(&out);
    }
    return 0;
}



inline LocalPt3::LocalPt3() {}
inline LocalPt3::LocalPt3(float a, float b, float c) : x(a), y(b), z(c) {}
inline LocalPt3 LocalPt3::operator*(float f) const
{ return LocalPt3(x * f, y * f, z * f); }

struct Plane4
{
    float nx, ny, nz, d;
    int WhichSide(const LocalPt3* p) const
    {
        float fDist = nx * p->x + ny * p->y + nz * p->z - d;
        if (fDist < 0.0)
            return 2;
        if (fDist > 0.0)
            return 1;
        return 0;
    }
};

struct OccShape
{
    int unk00, unk04, unk08;
    LocalPt3 kTargetCenter;
    float fScaleMultiplier, m_fGlyphExtent, m_fGlyphWidthInPixels;
    void GetVertices(LocalPt3* m_pkDeltas)
    {
        LocalPt3 vX = LocalPt3::ms_kFirstPoint * fScaleMultiplier;
        LocalPt3 vY = LocalPt3::ms_kSecondPoint * m_fGlyphExtent;
        LocalPt3 vZ = LocalPt3::ms_kThirdPoint * m_fGlyphWidthInPixels;
        m_pkDeltas[0] = kTargetCenter + vX + vY + vZ;
        m_pkDeltas[1] = kTargetCenter + vX + vY - vZ;
        m_pkDeltas[2] = kTargetCenter + vX - vY + vZ;
        m_pkDeltas[3] = kTargetCenter + vX - vY - vZ;
        m_pkDeltas[4] = kTargetCenter - vX + vY + vZ;
        m_pkDeltas[5] = kTargetCenter - vX + vY - vZ;
        m_pkDeltas[6] = kTargetCenter - vX - vY + vZ;
        m_pkDeltas[7] = kTargetCenter - vX - vY - vZ;
    }
    bool BSMultiBoundAABB_WithinFrustum(NiFrustumPlanes* pkPlanes);
};

// @fnv 0x00c387f0
// src: XBOX_PDB 0x00c387f0
bool OccShape::BSMultiBoundAABB_WithinFrustum(NiFrustumPlanes* pkPlanes)
{
    LocalPt3 kVerts[8];
    bool bFlat = (m_fGlyphWidthInPixels == 0.0);
    GetVertices(kVerts);
    for (int i = 0; i < 6; i++)
    {
        if (bool(pkPlanes->m_uiActivePlaneMask & (1 << i)))
        {
            bool bAllOut = true;
            for (int j = 0; j < 8; j++)
            {
                if (!bFlat || (j % 2) != 0)
                {
                    if (reinterpret_cast<const Plane4&>(pkPlanes->m_akPlanes[i]).WhichSide(&kVerts[j]) != 2)
                        bAllOut = false;
                }
            }
            if (bAllOut)
                return false;
        }
    }
    return true;
}

class CloningProcess;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct FUN_00c4f8e0
{
    int unk000;
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
    static void* operator new(unsigned int size)
    {
        int unused[4];
        (void)unused;
        return Object_DispatchCommandFour(size);
    }
    FUN_00c4f8e0();
};
struct C4F390_Owner
{
    void CopyFields(FUN_00c4f8e0* clone, CloningProcess& cloning);
    FUN_00c4f8e0* BSPortal_CreateClone(CloningProcess& cloning);
};
// @fnv 0x00c4f390
// src: XBOX_PDB 0x00c4f390
FUN_00c4f8e0* C4F390_Owner::BSPortal_CreateClone(CloningProcess& cloning)
{
    FUN_00c4f8e0* clone = new FUN_00c4f8e0;
    CopyFields(clone, cloning);
    return clone;
}

struct NodeA
{
    int unk00;
    int unk04;
    int unk08;
    NodeA* unk0C;

    inline int Get08()
    {
        return unk08;
    }
};

class ObjA
{
  public:
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
    int unkA0;
    int unkA4;
    int unkA8;
    NodeA* unkAC;

    int BSMultiBoundRoom_GetCullResult();
};

// @fnv 0x00c4f860
// src: COMMUNITY 0x00c4f860
int ObjA::BSMultiBoundRoom_GetCullResult()
{
    NodeA* a = unkAC;
    NodeA* b;
    NodeA* c5;
    NodeA* d;
    return a ? (b = unkAC, c5 = b->unk0C, (c5 ? (d = b->unk0C, d->Get08()) : 0)) : 0;
}

float sqrt_004019b0(float);
// src: XBOX_PDB 0x004579e0
inline float NiSqrt_004579e0(float value) { return sqrt_004019b0(value); }
inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& rhs) const
{ return NiPoint3(x - rhs.x, y - rhs.y, z - rhs.z); }
inline float NiPoint3::SqrLength() const { return x * x + y * y + z * z; }
inline float NiPoint3::Length() const { return NiSqrt_004579e0(x * x + y * y + z * z); }
// Non-const locals call these overloads: same inline bodies as the const ones.
inline float NiPoint3::SqrLength() { return x * x + y * y + z * z; }
inline float NiPoint3::Length() { return NiSqrt_004579e0(x * x + y * y + z * z); }

// @fnv 0x00c4ff60
// src: XBOX_PDB 0x00c4ff60
int BSMultiBoundSphere::CheckBound(BSMultiBound* other)
{
    int type = other->GetShape()->GetShapeType();
    if (type == 1)
    {
        BSMultiBoundAABB* box2 = static_cast<BSMultiBoundAABB*>(other->GetShape());
        NiPoint3 _vertices[8];
        box2->BSMultiBoundAABB_GetVertices(_vertices);
        float radiusSquared8 = radius * radius;
        for (int i = 0; i < 8; i++)
        {
            NiPoint3 diff2 = center.operator-(_vertices[i]);
            float distanceSquared = diff2.SqrLength();
            if (distanceSquared > radiusSquared8)
                return 0;
        }
        return 2;
    }
    else if (type == 2)
    {
        BSMultiBoundOBB* box3 = static_cast<BSMultiBoundOBB*>(other->GetShape());
        NiPoint3 vertices5[8];
        box3->BSMultiBoundOBB_GetVertices(vertices5);
        float radiusSquared = radius * radius;
        for (int i = 0; i < 8; i++)
        {
            NiPoint3 diff = center.operator-(vertices5[i]);
            {
                float distanceSquared = diff.SqrLength();
                if (distanceSquared > radiusSquared)
                    return 0;
            }
        }
        return 2;
    }
    else if (type == 3)
    {
        BSMultiBoundSphere* sphere = static_cast<BSMultiBoundSphere*>(other->GetShape());
        {
            NiPoint3 diff3 = center.operator-(sphere->center);
            {
                float distance = diff3.Length();
                if (distance + sphere->radius - radius <= 0.0)
                    return 2;
            }
        }
    }
    return 0;
}



// BSMultiBoundSphere has no FUN_00c50380 point-containment declaration.
struct C50380_Sphere
{
    int unk00;
    int unk04;
    int unk08;
    PodPoint3 m_kCenter;
    float m_fBoundRadius;

    bool __thiscall BSMultiBoundSphere_QPointWithin(PodPoint3* other);
};


// @fnv 0x00c50380
// src: XBOX_PDB 0x00c50380
bool __thiscall C50380_Sphere::BSMultiBoundSphere_QPointWithin(PodPoint3* other)
{
    // Preserve the frame space reserved for the original inline point helpers.
    DeadQ4();
    float fDist = other->SubtractIntoVector(m_kCenter).FUN_00457990();
    return (fDist < m_fBoundRadius) ? true : false;
}

class NiPoint3OB
{
  public:
    NiPoint3OB()
    {}
    NiPoint3OB(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3OB operator+(const NiPoint3OB& kPt) const
    {
        return NiPoint3OB(x + kPt.x, y + kPt.y, z + kPt.z);
    }
    NiPoint3OB operator-(const NiPoint3OB& kPt) const
    {
        return NiPoint3OB(x - kPt.x, y - kPt.y, z - kPt.z);
    }
    NiPoint3OB& operator*=(float fScale)
    {
        x *= fScale;
        y *= fScale;
        z *= fScale;
        return *this;
    }
    float x;
    float y;
    float z;
    static const NiPoint3OB ZERO;
};

class NiMatrix3OB
{
  public:
    void GetCol(unsigned int uiCol, NiPoint3OB& kCol) const
    {
        kCol.x = m_afEntries[0][uiCol];
        kCol.y = m_afEntries[1][uiCol];
        kCol.z = m_afEntries[2][uiCol];
    }
    float m_afEntries[3][3];
};

// Moving this method to BSMultiBoundOBB::FUN_00c37a00(NiPoint3*) changes its stack layout.
class NiOBBOB
{
  public:
    void BSMultiBoundOBB_GetVertices(NiPoint3OB* pkVerts);
    int m_aiPad[3];
    NiPoint3OB m_kCenter;
    float m_afExtents[3];
    NiMatrix3OB m_kBasis;
};

// @fnv 0x00c37a00
// src: COMMUNITY 0x00c37a00
void NiOBBOB::BSMultiBoundOBB_GetVertices(NiPoint3OB* pkVerts)
{
    NiPoint3OB kX = NiPoint3OB::ZERO;
    NiPoint3OB kY = NiPoint3OB::ZERO;
    NiPoint3OB kZ = NiPoint3OB::ZERO;
    m_kBasis.GetCol(0, kX);
    kX *= m_afExtents[0];
    m_kBasis.GetCol(1, kY);
    kY *= m_afExtents[1];
    m_kBasis.GetCol(2, kZ);
    kZ *= m_afExtents[2];
    pkVerts[0] = m_kCenter + kX + kY + kZ;
    pkVerts[1] = m_kCenter + kX + kY - kZ;
    pkVerts[2] = m_kCenter + kX - kY + kZ;
    pkVerts[3] = m_kCenter + kX - kY - kZ;
    pkVerts[4] = m_kCenter - kX + kY + kZ;
    pkVerts[5] = m_kCenter - kX + kY - kZ;
    pkVerts[6] = m_kCenter - kX - kY + kZ;
    pkVerts[7] = m_kCenter - kX - kY - kZ;
}

// 0x011f6238 is the MemoryManager; its allocator is bound at 0x00aa3e40.
extern MemoryManager DAT_011f6238;
struct FUN_00a5ecb0
{
    virtual ~FUN_00a5ecb0();
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
    unsigned int m_flags;
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
    FUN_00a5ecb0(int arg);
    void SetBit(bool value, unsigned int mask)
    {
        if (value)
            m_flags |= mask;
        else
            m_flags &= ~mask;
    }
};
struct FUN_00c3a220
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    FUN_00c3a220();
    ~FUN_00c3a220();
};
struct FUN_00c47660
{
    int unk000;
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
    FUN_00c47660();
    static void* operator new(unsigned int size)
    {
        int unused[3];
        (void)unused;
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    static void operator delete(void* p);
};
struct C4F460_Node : FUN_00a5ecb0
{
    FUN_00c47660* m_pChildAtom;
    FUN_00c3a220 m_kMemberDescriptor;
    int m_C0;
    C4F460_Node(int value);
    virtual ~C4F460_Node();
};
// @fnv 0x00c4f460
C4F460_Node::C4F460_Node(int value) : FUN_00a5ecb0(0)
{
    m_pChildAtom = new FUN_00c47660;
    SetBit(true, 0x800);
    m_C0 = value;
}

namespace fnv_00c4f550 {
// Other units bind 0x00aa4060 to MemoryManager::Deallocate on 0x011f6238.
extern MemoryManager DAT_011f6238;

struct FUN_00c47770
{  // owned object; destructor at 0x00c47770
    int unk00;
    ~FUN_00c47770();
    static void operator delete(void* pvMem)
    {
        int unused; /* frame space only */
        DAT_011f6238.Deallocate(pvMem);
    }
};

struct FUN_00c3a620
{  // member at +0xb0; destructor at 0x00c3a620
    unsigned int unk00, unk04, unk08, unk0C;
    void UpdateFields_00b5af80(int iMode);
    ~FUN_00c3a620();
};

struct FUN_00a5e930
{  // base class; destructor at 0x00a5e930
    virtual ~FUN_00a5e930();
};

class Owner_c4f550 : public FUN_00a5e930
{
  public:
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    unsigned int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    unsigned int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    unsigned int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    unsigned int unkA4, unkA8;
    FUN_00c47770* m_pkOwned;  // +0xac
    FUN_00c3a620 m_kList;     // +0xb0
    unsigned int m_uiCount;   // +0xc0
    virtual ~Owner_c4f550();
};

// @fnv 0x00c4f550
Owner_c4f550::~Owner_c4f550()
{
    delete m_pkOwned;
    m_kList.UpdateFields_00b5af80(1);
    m_uiCount = 0;
}
}  // namespace fnv_00c4f550

namespace fnv_00c4f8e0 {
extern int(__stdcall* DAT_00fdf1c0)(long*);
class FUN_00c335d0
{
  public:
    virtual void vf0();
    FUN_00c335d0();
    ~FUN_00c335d0();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
};
struct RefObject
{
    unsigned int vtable;
    long references;
    void IncRefCount()
    {
        DAT_00fdf1c0(&references);
    }
    void DecRefCount()
    {
        if (DAT_00fdf1c0(&references) == 0)
            DeleteThis();
    }
    void DeleteThis();
};
static __forceinline void Dead2()
{
    int aiD[2];
}
struct NodePointer
{
    RefObject* object;
    NodePointer(RefObject* p = 0) : object(p)
    {
        if (object)
            object->IncRefCount();
    }
    ~NodePointer()
    {
        if (object)
            object->DecRefCount();
    }
    NodePointer& FUN_0066b0d0(RefObject*);
};
class FUN_00c4f8e0 : public FUN_00c335d0
{
  public:
    NodePointer node;
    FUN_00c4f8e0();
    virtual void vf0();
};
extern void* DAT_0101e82c;
// @fnv 0x00c4f8e0
FUN_00c4f8e0::FUN_00c4f8e0()
{
    Dead2();
    node.FUN_0066b0d0(0);
}
}  // namespace fnv_00c4f8e0

struct OBPoint
{
    float x;
    float y;
    float z;

    OBPoint()
    {}
    OBPoint(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    OBPoint operator+(const OBPoint& arOther) const
    {
        return OBPoint(x + arOther.x, y + arOther.y, z + arOther.z);
    }
    OBPoint operator-(const OBPoint& arOther) const
    {
        return OBPoint(x - arOther.x, y - arOther.y, z - arOther.z);
    }
    OBPoint operator*(float afScale) const
    {
        return OBPoint(x * afScale, y * afScale, z * afScale);
    }
};

extern const OBPoint g_kOBUnitX;
extern const OBPoint g_kOBUnitY;
extern const OBPoint g_kOBUnitZ;

struct OBBox
{
    int unk00;
    int unk04;
    int unk08;
    OBPoint kTargetCenter;
    float fExtentX;
    float fExtentY;
    float fExtentZ;

    void BSMultiBoundAABB_GetVertices(OBPoint* apCorners);
};

// @fnv 0x00c39270
// src: XBOX_PDB 0x00c39270
void OBBox::BSMultiBoundAABB_GetVertices(OBPoint* apCorners)
{
    OBPoint kX = g_kOBUnitX * fExtentX;
    OBPoint kY = g_kOBUnitY * fExtentY;
    OBPoint kZ = g_kOBUnitZ * fExtentZ;

    apCorners[0] = kTargetCenter + kX + kY + kZ;
    apCorners[1] = kTargetCenter + kX + kY - kZ;
    apCorners[2] = kTargetCenter + kX - kY + kZ;
    apCorners[3] = kTargetCenter + kX - kY - kZ;
    apCorners[4] = kTargetCenter - kX + kY + kZ;
    apCorners[5] = kTargetCenter - kX + kY - kZ;
    apCorners[6] = kTargetCenter - kX - kY + kZ;
    apCorners[7] = kTargetCenter - kX - kY - kZ;
}

namespace FrustumBoxTest {



struct Plane
{
    PodPoint3 normal;
    float distance;
    int ClassifyPoint(const PodPoint3&) const;
};

struct FloatMatrix3
{
    float entries[3][3];
    void GetColumn(unsigned int column, PodPoint3& result) const
    {
        result.x = entries[0][column];
        result.y = entries[1][column];
        result.z = entries[2][column];
    }
};

struct OrientedBox
{
    unsigned int unk00, unk04, unk08;
    PodPoint3 center;
    PodPoint3 extents;
    FloatMatrix3 rotation;

// src: COMMUNITY 0x00c37a00
    void BSMultiBoundOBB_GetVertices(PodPoint3* vertices)
    {
        PodPoint3 axisX = PodPoint3::ZERO;
        PodPoint3 axisY = PodPoint3::ZERO;
        PodPoint3 axisZ = PodPoint3::ZERO;
        rotation.GetColumn(0, axisX);
        axisX.ScaleComponents(extents.x);
        rotation.GetColumn(1, axisY);
        axisY.ScaleComponents(extents.y);
        axisZ.x = rotation.entries[0][2];
        axisZ.y = rotation.entries[1][2];
        axisZ.z = rotation.entries[2][2];
        axisZ.ScaleComponents(extents.z);
        vertices[0] = center + axisX + axisY + axisZ;
        vertices[1] = (center + axisX + axisY).SubtractIntoVector(axisZ);
        vertices[2] = (center + axisX).SubtractIntoVector(axisY) + axisZ;
        vertices[3] = (center + axisX).SubtractIntoVector(axisY).SubtractIntoVector(axisZ);
        vertices[4] = center.SubtractIntoVector(axisX) + axisY + axisZ;
        vertices[5] = (center.SubtractIntoVector(axisX) + axisY).SubtractIntoVector(axisZ);
        vertices[6] = center.SubtractIntoVector(axisX).SubtractIntoVector(axisY) + axisZ;
        vertices[7] = center.SubtractIntoVector(axisX).SubtractIntoVector(axisY).SubtractIntoVector(axisZ);
    }

    bool BSMultiBoundOBB_WithinFrustum(NiFrustumPlanes*);
};

// @fnv 0x00c36f20
// src: XBOX_PDB 0x00c36f20
bool OrientedBox::BSMultiBoundOBB_WithinFrustum(NiFrustumPlanes* frustum)
{
    PodPoint3 vertices[8];
    InitializePoint3Array(vertices, 8);
    bool flat = (extents.z == 0.0);
    BSMultiBoundOBB_GetVertices(vertices);
    for (int plane = 0; plane < 6; ++plane)
    {
        if ((bool)(frustum->m_uiActivePlaneMask & (1 << plane)))
        {
            bool outside = true;
            for (int vertex = 0; vertex < 8; ++vertex)
            {
                if (!flat || vertex % 2)
                {
                    if (reinterpret_cast<const Plane&>(frustum->m_akPlanes[plane]).ClassifyPoint(vertices[vertex]) != 2)
                        outside = false;
                }
            }
            if (outside)
                return false;
        }
    }
    return true;
}

}

