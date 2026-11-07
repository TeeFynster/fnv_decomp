
// src/speedtree/projectedshadow_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/projectedshadow.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../include/IdvFileError.h"
#include "../../include/NiPoint3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3/CVec3; this unit's code depends on the stand-in's own overload set and inline bodies (its own NiPoint3/CVec3 bodies differ), so the shared class cannot replace it.
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

// src/speedtree/projectedshadow.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/projectedshadow.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Sub
{
    void fopen_0044a730(int a, int b);
};
struct V3
{
    float x, y, z;
    V3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
};
struct FUN_00b3e6c0_cls
{
    V3 a;
    V3 b;
    V3 c;
    Sub s;
    FUN_00b3e6c0_cls* ClearVectors();
};

struct Vec2
{
    float x, y;
};
inline LocalVec3::LocalVec3()
{}
inline LocalVec3::LocalVec3(const float* data)
{
    x = data[0];
    y = data[1];
    z = data[2];
}
LocalVec3 LocalVec3::ScaleSwizzled(float scale) const
{
    LocalVec3 r;
    r.x = scale * x;
    r.y = scale * y;
    r.z = scale * z;
    return r;
}
// src: COMMUNITY 0x00b13040
LocalVec3 LocalVec3::Diff_00b13040(const LocalVec3& v) const
{
    LocalVec3 r;
    r.x = x - v.x;
    r.y = y - v.y;
    r.z = z - v.z;
    return r;
}
LocalVec3 LocalVec3::AddVector(const LocalVec3& v) const
{
    LocalVec3 r;
    r.x = v.x + x;
    r.y = v.y + y;
    r.z = v.z + z;
    return r;
}
// src: COMMUNITY 0x00b04d40
float LocalVec3::CVec3_Distance(const LocalVec3& v) const
{
    union FloatBits
    {
        float value;
        int bits;
    };
    FloatBits squared;
    squared.value = (v.z - z) * (v.z - z) + ((v.y - y) * (v.y - y) + (v.x - x) * (v.x - x));
    FloatBits estimate;
    estimate.bits = (squared.bits >> 1) + 0x1fc00000;
    return estimate.value;
}
__forceinline float Id(float x)
{
    return x;
}
__forceinline void Fill(LocalVec3* dst, const float* data)
{
    LocalVec3 r;
    r.x = data[0];
    r.y = data[1];
    r.z = data[2];
    *dst = r;
}
// Optional texture sub-rectangle that 0x00b3ea10 remaps each projected shadow uv into (MapX/MapY lerp between
// the lower and upper edges). Not the shared AABB Bounds.
struct ShadowUVRect
{
    float upperX, upperY, lowerX, unknown0C, unknown10, lowerY;
    __forceinline float MapX(float value) const
    {
        float aX = lowerX;
        int p6;
        int q5;
        return Id(aX) + (upperX - aX) * Id(value);
    }
    __forceinline float MapY(float value) const
    {
        float aY = lowerY;
        int n2;
        int q1;
        return Id(aY) + (upperY - aY) * Id(value);
    }
};
struct VecRange
{
    unsigned int unknown0, unknown4, unknown8;
    float* begin;
    float* end;
    __forceinline unsigned int Size() const
    {
        return (unsigned int)(end - begin);
    }
};
struct Context
{
    unsigned int unknown00, unknown04, unknown08, unknown0C, unknown10, unknown14, unknown18, unknown1C;
    unsigned short unknown20, count;
    unsigned int unknown24, unknown28, unknown2C, unknown30, unknown34, unknown38, unknown3C;
    unsigned int unknown40, unknown44, unknown48, unknown4C, unknown50, unknown54, unknown58, unknown5C;
    unsigned int unknown60, unknown64, unknown68, unknown6C, unknown70, unknown74, unknown78, unknown7C;
    unsigned int unknown80, unknown84;
    VecRange points;
    const float* CIndexedGeometry_GetVertexCoord(unsigned short index);
    void CIndexedGeometry_AddVertexTexCoord1(Vec2* uv);
};
struct Scr
{
    __forceinline static void Touch()
    {
        int s0;
        int s1;
        int s2;
        int s3;
        int s4;
        int s5;
        int s6;
        int s7;
        int s8;
        int s9;
        int s10;
        int s11;
        int s12;
        int s13;
        int s14;
        int s15;
        int s16;
        int s17;
        int s18;
        int s19;
        int s20;
        int s21;
        int s22;
        int s23;
    }
};
struct Agent
{
    LocalVec3 first, second;
    LocalVec3 ProjectOntoLine(const LocalVec3& start, const LocalVec3& end, const LocalVec3& point);
    void CProjectedShadow_ComputeTexCoords(Context*, LocalVec3, float, ShadowUVRect*);
};
// @fnv 0x00b3ea10
// src: COMMUNITY 0x00b3ea10
void Agent::CProjectedShadow_ComputeTexCoords(Context* context, LocalVec3 point, float extent, ShadowUVRect* bounds)
{
    LocalVec3 lowerAA = point.Diff_00b13040(static_cast<const LocalVec3&>(first).ScaleSwizzled(extent));
    LocalVec3 kUpperA = point.AddVector(static_cast<const LocalVec3&>(first).ScaleSwizzled(extent));
    LocalVec3 lowerB6 = point.Diff_00b13040(static_cast<const LocalVec3&>(second).ScaleSwizzled(extent));
    LocalVec3 upperB4 = point.AddVector(static_cast<const LocalVec3&>(second).ScaleSwizzled(extent));
    Scr::Touch();
    context->count = 0;
    for (unsigned short index3 = 0; index3 < (unsigned short)(context->points.Size() / 3); ++index3)
    {
        const float* input = context->CIndexedGeometry_GetVertexCoord(index3);
        LocalVec3 value2;
        Fill(&value2, input);
        LocalVec3 projectedA7 = ProjectOntoLine(lowerAA, kUpperA, value2);
        Vec2 uv5;
        uv5.x = lowerAA.CVec3_Distance(projectedA7) / (extent * 2.0f);
        if (bounds)
        {
            uv5.x = bounds->MapX(uv5.x);
        }
        LocalVec3 projectedB2 = ProjectOntoLine(lowerB6, upperB4, value2);
        uv5.y = lowerB6.CVec3_Distance(projectedB2) / (extent * 2.0f);
        if (bounds)
        {
            uv5.y = bounds->MapY(uv5.y);
        }
        context->CIndexedGeometry_AddVertexTexCoord1(&uv5);
    }
}

#include <string>
#include <memory>
#include <stdexcept>
template <> std::string& std::string::assign(const std::string&, unsigned int, unsigned int);
template <> std::string& std::string::assign(const char*);
template <> std::_String_val<char, std::allocator<char> >::_String_val(std::allocator<char>);


inline void AssignPoint3(NiPoint3& destination, const NiPoint3& source)
{
    destination.x = source.x;
    destination.y = source.y;
    destination.z = source.z;
}
struct Vec3Ret
{
    float x, y, z;
    operator const NiPoint3&() const
    {
        return *(const NiPoint3*)this;
    }
};

inline IdvFileError::IdvFileError(const std::string& message, bool system)
    : std::runtime_error(message + " [" + (system ? std::string(strerror(errno)) : std::string("")) + "]")
{}

struct NarrowString : std::string
{
    NarrowString(std::string s) : std::string(s)
    {}
    std::string ProcessEntries_00b09f90();
};

std::string __cdecl IdvFormatString(const char*, ...);

struct ChunkReader
{
    int GetNextElement();
    Vec3Ret GetVector3();
    std::string CTreeFileAccess_ParseString();
};

struct FrondInfo
{
    NiPoint3 p0, p1, p2;
    std::string name;
    void ProcessEntries_00b3e750(ChunkReader*);
};

// @fnv 0x00b3e750
// src: GUESS 0x00b3e750 (confidence: low)
void FrondInfo::ProcessEntries_00b3e750(ChunkReader* reader)
{
    int token = reader->GetNextElement();
    do
    {
        switch (token)
        {
        case 0x4652:
            AssignPoint3(p0, reader->GetVector3());
            break;
        case 0x4653:
            AssignPoint3(p1, reader->GetVector3());
            break;
        case 0x4654:
            AssignPoint3(p2, reader->GetVector3());
            break;
        case 0x4655: {
            NarrowString text(reader->CTreeFileAccess_ParseString());
            name = text.ProcessEntries_00b09f90();
            break;
        }
        default:
            throw IdvFileError(IdvFormatString("malformed frond info (token %d)", token), false);
        }
        token = reader->GetNextElement();
    } while (token != 0x4651);
}
