#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/speedtree/lightingengine_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/lightingengine.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/lightingengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/lightingengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/hkVector4.h"
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

extern double FUN_00ec6054(double);

__forceinline float& LocalVec3::operator[](int index)
{
    return ((float*)this)[index];
}
__forceinline LocalVec3::LocalVec3()
{
    x = y = z = 0.0f;
}
__forceinline LocalVec3::LocalVec3(float a, float b, float c) : x(a), y(b), z(c)
{}
// src: COMMUNITY 0x00b12790
inline void LocalVec3::Normalize_00b12790()
{
    float lengthSquared = x * x + y * y + z * z;
    float length = (float)FUN_00ec6054(lengthSquared);
    float reciprocal = 1.0f / length;
    x *= reciprocal;
    y *= reciprocal;
    z *= reciprocal;
}
inline float LocalVec3::FUN_00b2a180(void* ptr)
{
    const LocalVec3& rhs = *(const LocalVec3*)ptr;
    float value = x * rhs.x + y * rhs.y + z * rhs.z;
    return value;
}
inline LocalVec3 LocalVec3::AddVector(const LocalVec3& rhs)
{
    return LocalVec3(x + rhs.x, y + rhs.y, z + rhs.z);
}
inline LocalVec3 LocalVec3::ScaleSwizzled(float value)
{
    return LocalVec3(x * value, y * value, z * value);
}
// src: GUESS 0x00b2a1c0 (confidence: medium)
inline LocalVec3& LocalVec3::AddComponents(void* ptr)
{
    const LocalVec3& rhs = *(const LocalVec3*)ptr;
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}
// src: COMMUNITY 0x00b04d40
inline float LocalVec3::CVec3_Distance(LocalVec3* rhs)
{
    float squared = (rhs->z - z) * (rhs->z - z) + (rhs->y - y) * (rhs->y - y) + (rhs->x - x) * (rhs->x - x);
    int bits = *(int*)&squared;
    bits = (bits >> 1) + 0x1fc00000;
    return *(float*)&bits;
}
struct Color
{
    float r, g, b;
    __forceinline const float& operator[](int index) const
    {
        return ((const float*)this)[index];
    }
};
static __declspec(noinline) unsigned int PackChannel(float value, bool adjust, unsigned char alpha)
{
    if (adjust)
        value *= (float)(alpha / 255.0);
    if (value > 1.0)
        value = 1.0f;
    if (value < 0.0)
        value = 0.0f;
    return (unsigned int)(int)(value * 255.0);
}
struct GameContext
{
    int unk00;
    LocalVec3 rotation;
    int unk10;
    unsigned int packed14;
    unsigned char alpha18, unk19, unk1a, unk1b;
    LocalVec3 location;
    void CBillboardLeaf_GetColor(float*);
// src: COMMUNITY 0x00b404c0
    void CBillboardLeaf_SetColor(const Color& values, bool adjust)
    {
        unsigned int packed = PackChannel(values.r, adjust, alpha18);
        packed += PackChannel(values.g, adjust, alpha18) << 8;
        packed += PackChannel(values.b, adjust, alpha18) << 16;
        packed14 = packed - 0x1000000;
    }
    void CBillboardLeaf_AdjustStaticLighting(int, LocalVec3*, float);
    float CVec3_Distance(LocalVec3*);
};
struct Record;
struct Iterator
{
    int unk00, unk04;
    void FUN_00b42980(int, Record*);
    __forceinline Iterator(int value, Record* owner)
    {
        FUN_00b42980(value, owner);
    }
    bool EvaluateValue_00b2ac30(Iterator*);
    GameContext*& EvaluateValue_00b2ab50();
    void ProcessAndReturnValue_00b2abc0();
    __forceinline bool operator!=(Iterator const& rhs)
    {
        return !EvaluateValue_00b2ac30((Iterator*)&rhs);
    }
    __forceinline GameContext*& operator->()
    {
        return EvaluateValue_00b2ab50();
    }
};
struct Record
{
    int unk00, unk04, unk08;
    int origin, destination, unk14;
    __forceinline int getBegin()
    {
        return origin;
    }
    __forceinline int GetStreamEnd()
    {
        return destination;
    }
    __forceinline Iterator begin()
    {
        return Iterator(origin, this);
    }
    __forceinline Iterator end()
    {
        return Iterator(destination, this);
    }
};
struct DeviceData
{
    LocalVec3 position;
    LocalVec3 scale;
    LocalVec3 mix;
    int unk24, unk28, unk2c;
    float transformMode;
    float constant, linear, quadratic;
};
extern DeviceData DAT_011ad168[8];
extern unsigned char DAT_011f8d50[8];
extern float DAT_01012054;
extern double DAT_01012060;
extern double DAT_01012070;
__forceinline void BlendWeight(float& weight, float blend)
{
    weight = weight * (1.0 - blend) + blend;
}
struct Scene
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34;
    int state38, unk3c, unk40, unk44;
    LocalVec3 colors48;
    int unk54, unk58, unk5c;
    LocalVec3 position60;
    int unk6c;
    float blend70;
    int flags74;
    __forceinline float GetBlend()
    {
        return blend70;
    }
    void CLightingEngine_ComputeLeafStaticLighting(int output, Record* records, int count);
};
// @fnv 0x00b2a210
// src: COMMUNITY 0x00b2a210
void Scene::CLightingEngine_ComputeLeafStaticLighting(int output, Record* records, int count)
{
    if (state38 == 1 && flags74 != 0)
    {
        for (int i = 0; i < count; ++i)
        {
            Iterator it = records[i].begin();
            for (; it != records[i].end(); it.ProcessAndReturnValue_00b2abc0())
            {
                void* location = &it->location;
                void* rotationW = &it->rotation;
                Color origin20;
                it->CBillboardLeaf_GetColor(&origin20.r);
                LocalVec3 best;
                float maximumW2 = DAT_01012054;
                LocalVec3 result5;
                for (int j = 0; j < 8; ++j)
                {
                    if (DAT_011f8d50[j])
                    {
                        LocalVec3 dir(DAT_011ad168[j].position.x, DAT_011ad168[j].position.y, DAT_011ad168[j].position.z);
                        LocalVec3 normal_29 =
                            DAT_011ad168[j].transformMode == DAT_01012060 ? dir : dir.Diff_00b13040(rotationW);
                        normal_29.Normalize_00b12790();
                        float weight = normal_29.FUN_00b2a180(location);
                        if (weight >= maximumW2)
                        {
                            maximumW2 = weight;
                            best.xb = dir.xb;
                            best.yb = dir.yb;
                            best.zb = dir.zb;
                        }
                        if (weight < DAT_01012060)
                            weight = 0.0f;
                        BlendWeight(weight, blend70);
                        if ((flags74 & 1) != 0)
                        {
                            LocalVec3 pos29(position60.x, position60.y, position60.z);
                            LocalVec3 combined5(DAT_011ad168[j].mix.x * colors48.x, DAT_011ad168[j].mix.y * colors48.y,
                                           DAT_011ad168[j].mix.z * colors48.z);
                            float falloff = 1.0f;
                            if (DAT_011ad168[j].transformMode != DAT_01012060)
                            {
                                float dist8 = ((LocalVec3*)rotationW)->CVec3_Distance(&dir);
                                float polynomial = DAT_011ad168[j].constant + DAT_011ad168[j].linear * dist8 +
                                                   DAT_011ad168[j].quadratic * dist8 * dist8;
                                if (polynomial != DAT_01012060)
                                    falloff = 1.0f / polynomial;
                            }
                            LocalVec3 attenuation((weight * DAT_011ad168[j].scale.x) * origin20[0],
                                             (weight * DAT_011ad168[j].scale.y) * origin20[1],
                                             (weight * DAT_011ad168[j].scale.z) * origin20[2]);
                            result5.AddComponents(
                                &pos29.AddVector(combined5.AddVector(attenuation).ScaleSwizzled(falloff)));
                        }
                    }
                }
                result5[0]<DAT_01012060 ? result5[0] = 0.0 : result5[0]> DAT_01012070 ? result5[0] = 1.0
                                                                                      : result5[0] = result5[0];
                result5[1]<DAT_01012060 ? result5[1] = 0.0 : result5[1]> DAT_01012070 ? result5[1] = 1.0
                                                                                      : result5[1] = result5[1];
                result5[2]<DAT_01012060 ? result5[2] = 0.0 : result5[2]> DAT_01012070 ? result5[2] = 1.0
                                                                                      : result5[2] = result5[2];
                if ((flags74 & 1) != 0)
                {
                    it->CBillboardLeaf_SetColor((Color&)result5, 0);
                }
                if ((flags74 & 2) != 0)
                {
                    it->CBillboardLeaf_AdjustStaticLighting(output, &best, blend70);
                }
            }
        }
    }
}

struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
    float CTreeFileAccess_ParseFloat();
};
inline void DeadTop()
{
    int aiD[63];
    aiD[14] = 0;
}
struct LightQ
{
    int iMode;
    float afA[13];
    int iCount;
    float afB[13];
    float fScale;
    int iX;
    int iY;
    float afC[13];
    void CLightingEngine_Parse(Parser* p);
};
// @fnv 0x00b2a940
// src: COMMUNITY 0x00b2a940
void LightQ::CLightingEngine_Parse(Parser* p)
{
    DeadTop();
    int iToken = p->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x1f42:
            iMode = p->GetNextElement();
            break;
        case 0x1f43:
            for (int i = 0; i < 13; i++)
                afA[i] = p->CTreeFileAccess_ParseFloat();
            break;
        case 0x1f44:
            iCount = p->GetNextElement();
            break;
        case 0x1f45:
            for (int j = 0; j < 13; j++)
                afB[j] = p->CTreeFileAccess_ParseFloat();
            break;
        case 0x1f46:
            fScale = p->CTreeFileAccess_ParseFloat();
            break;
        case 0x1f47:
            iX = p->GetNextElement();
            break;
        case 0x1f48:
            iY = p->GetNextElement();
            break;
        case 0x1f49:
            for (int k = 0; k < 13; k++)
                afC[k] = p->CTreeFileAccess_ParseFloat();
            break;
        default:
            throw FUN_00b09480("malformed lighting information", false);
        }
        iToken = p->GetNextElement();
    } while (iToken != 0x1f41);
}
