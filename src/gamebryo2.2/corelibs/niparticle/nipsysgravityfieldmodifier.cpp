
// src/gamebryo2.2/corelibs/niparticle/nipsysgravityfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysgravityfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <string.h>

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysFieldModifier.h"
#include "../../../../include/NiPSysGravityFieldModifier.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiMatrix3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit's Vec3 operator* multiplies scalar*component while its NiPoint3 operator* multiplies component*scalar (x87 operand order), so one NiPoint3 cannot carry both.
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

// Keep the math operations used by this unit inline, as in the original code.
inline NiPoint3::NiPoint3(float fx, float fy, float fz) : x(fx), y(fy), z(fz) {}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    NiPoint3 r;
    r.x = x - p.x;
    r.y = y - p.y;
    r.z = z - p.z;
    return r;
}
inline NiPoint3 NiPoint3::operator*(float f) const { return NiPoint3(f * x, f * y, f * z); }
inline float NiPoint3::SqrLength() { return x * x + y * y + z * z; }
inline float NiPoint3::SqrLength() const { return x * x + y * y + z * z; }
inline LocalVec3::LocalVec3() {}
inline LocalVec3::LocalVec3(float fx, float fy, float fz) : x(fx), y(fy), z(fz) {}
inline LocalVec3 LocalVec3::operator*(float s) const { return LocalVec3(x * s, y * s, z * s); }
inline LocalVec3& LocalVec3::operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
inline LocalVec3& LocalVec3::operator+=(const LocalVec3& p) { x += p.x; y += p.y; z += p.z; return *this; }
inline NiTransform::NiTransform() {}
// NiMatrix3::operator*(const NiPoint3&) const, inlined here over this unit's LocalVec3.
struct NiMatrix3_Vec3View : public NiMatrix3
{
    LocalVec3 operator*(const LocalVec3& p) const
    {
        return LocalVec3(m_pEntry[0][0] * p.x + m_pEntry[0][1] * p.y + m_pEntry[0][2] * p.z,
                    m_pEntry[1][0] * p.x + m_pEntry[1][1] * p.y + m_pEntry[1][2] * p.z,
                    m_pEntry[2][0] * p.x + m_pEntry[2][1] * p.y + m_pEntry[2][2] * p.z);
    }
};

// @fnv 0x00c267f0
void NiPSysGravityFieldModifier::SaveBinary(NiStream& stream)
{
    NiPSysFieldModifier::SaveBinary(stream);
    reinterpret_cast<NiColor*>(&originalDirection)->SaveBinary(stream);
}

extern "C"
{
    extern const void* g_01202708;
}

// @fnv 0x00c2a9b0
// src: COMMUNITY 0x00c2a9b0
const void* __cdecl NiPSysGravityFieldModifier_GetRTTI()
{
    return &g_01202708;
}

void __cdecl FUN_00c31750(void);
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00c31750, then deletes this with size 0x48 when bit 0 of a1 is set, and returns this.
// @fnv 0x00c2a9c0
void* NiPSysGravityFieldModifier::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x48);
    return this;
}

// @fnv 0x00c2ac50
NiObject* NiPSysGravityFieldModifier::MakeClone(CloningProcess& kCloning)
{
    NiPSysGravityFieldModifier* pkObject;
    void* pMemory = BSFadeNode::operator new(0x48);
    if (pMemory)
        pkObject = ((NiPSysGravityFieldModifier*)pMemory)->Ctor();
    else
        pkObject = 0;
    reinterpret_cast<NiPSysFieldModifier*>(this)->NiPSysFieldModifier::CopyMemberData(pkObject, kCloning);
    pkObject->originalDirection = originalDirection;
    pkObject->normalizedDirection = originalDirection;
    pkObject->normalizedDirection.ComputeMagnitude();
    return (NiObject*)pkObject;
}

// @fnv 0x00c2aa50
NiPSysGravityFieldModifier* __cdecl CreateGravityFieldModifier()
{
    void* memory = BSFadeNode::operator new(0x48);
    if (memory != 0)
        return reinterpret_cast<NiPSysGravityFieldModifier*>(memory)->Ctor();

    return 0;
}

// @fnv 0x00c26db0
// src: XBOX_PDB 0x00c26db0
char NiPSysGravityFieldModifier::IsEqual_00c26db0(NiPSysGravityFieldModifier* other)
{
    if (!NiPSysFieldModifier::IsEqual(other))
        return false;
    return !other->m_kLightVector.FUN_00439090(&m_kLightVector);
}

extern "C" float DAT_011a9478;
extern "C" float DAT_011a947c;
extern "C" float DAT_011a9480;
extern "C" int DAT_010bf2ac;

// Thiscall with no stack arguments uses the same registers as this fastcall initializer.
void __fastcall ConstructFieldModifierBase(NiPSysFieldModifier*);

// @fnv 0x00c2a9e0
NiPSysGravityFieldModifier* NiPSysGravityFieldModifier::Ctor()
{
    ConstructFieldModifierBase(reinterpret_cast<NiPSysFieldModifier*>(this));
    *reinterpret_cast<void**>(this) = &DAT_010bf2ac;
    NiPoint3 direction;
    direction.x = -DAT_011a9478;
    direction.y = -DAT_011a947c;
    direction.z = -DAT_011a9480;
    originalDirection = direction;
    normalizedDirection = direction;
    normalizedDirection.ComputeMagnitude();
    return reinterpret_cast<NiPSysGravityFieldModifier*>(this);
}

// Loads the base modifier and a NiPoint3 from the stream, copies the point to offset 0x3c and calls FUN_004a0c10 on it.
// @fnv 0x00c2aa70
void NiPSysGravityFieldModifier::LoadBinary(NiStream& aStream)
{
    NiPSysFieldModifier::LoadBinary(aStream);
    NiPoint3* a = &originalDirection;
    a->LoadBinary(aStream);
    volatile unsigned int* src = reinterpret_cast<volatile unsigned int*>(&originalDirection);
    src[0] = src[0];
    src[1] = src[1];
    src[2] = src[2];
    NiPoint3* b = &normalizedDirection;
    *b = *(NiPoint3*)a;
    b->Unitize_004a0c10();
}

struct FUN_00c2af80_Array
{
    void* unk00;
    void* unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;

    void __thiscall FUN_0096ad30(unsigned int size);
    void __thiscall FUN_0096ae90(unsigned int index, void** item);
};

void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* value);

// NiPSysFieldModifier's shared declaration does not expose its viewer-string override.
void __fastcall GetFieldModifierViewerStrings(NiPSysFieldModifier*, void*, NiViewerStringsArray*);

// @fnv 0x00c2af80
void NiPSysGravityFieldModifier::GetViewerStrings(NiViewerStringsArray* stream)
{
    typedef void (__thiscall *GetFieldStrings)(NiPSysFieldModifier*, NiViewerStringsArray*);
    reinterpret_cast<GetFieldStrings>(&GetFieldModifierViewerStrings)(this, stream);

    FUN_00c2af80_Array* array = reinterpret_cast<FUN_00c2af80_Array*>(stream);

    void* item = NiViewerStrings_NiGetViewerString_Title(const_cast<void*>(g_01202708));

    unsigned int count = array->unk0A;
    if (count >= array->unk08)
        array->FUN_0096ad30(array->unk0E + count);
    array->FUN_0096ae90(count, &item);

    item = originalDirection.GetViewerString_00a59af0("Direction");

    count = array->unk0A;
    if (count >= array->unk08)
        array->FUN_0096ad30(array->unk0E + count);
    array->FUN_0096ae90(count, &item);
}

inline LocalVec3 operator*(float s, const LocalVec3& p)
{
    LocalVec3 r;
    r.x = s * p.x;
    r.y = s * p.y;
    r.z = s * p.z;
    return r;
}
struct Point3ParameterData
{
    NiPoint3 m_kValue;
    int unk0C;
    int unk10;
    float m_fZValue;
    int unk18;
};
// @fnv 0x00c2aac0
void NiPSysGravityFieldModifier::ApplyGravityToParticles(float fTime, NiPSysData* pkData)
{
    NiTransform kField;
    memcpy(&kField, &m_spFieldObject->m_kWorld, sizeof(kField));
    NiTransform kInv;
    {
        NiTransform kPSys;
        memcpy(&kPSys, &reinterpret_cast<NiAVObject*>(m_pkTarget)->m_kWorld, sizeof(kPSys));
        kPSys.FUN_004b4880(kInv);
    }
    LocalVec3 kAccel;
    {
        NiTransform kX = kInv * kField;
        LocalVec3 kDirection = (const NiMatrix3_Vec3View&)kX.m_Rotate * reinterpret_cast<const LocalVec3&>(m_kLightVector);
        kDirection.Unitize();
        kDirection *= m_fInfluence;
        kAccel = kDirection;
    }
    for (unsigned short i = 0; i < pkData->m_usActive; i++)
    {
        Point3ParameterData* pkInfo = &pkData->m_pkParticleInfo[i];
        float fTimeSinceScaleStart = fTime - pkInfo->m_fZValue;
        if (fTimeSinceScaleStart != 0.0f)
        {
            LocalVec3 change = kAccel * fTimeSinceScaleStart;
            NiPoint3& velocity = pkInfo->m_kValue;
            velocity.x += change.x;
            float fVelocityY = velocity.y;
            velocity.y = fVelocityY + change.y;
            velocity.z += change.z;
        }
    }
}

#include <math.h>

inline NiPoint3 RotateFieldDirection(const NiMatrix3& matrix, const NiPoint3& direction)
{
    return matrix * direction;
}

float BSMAX_00404010(float, float);
// Applies a directional force to particles within the field, scaling by m_fInfluence, time delta, and optional distance m_fFieldAttenuation or m_bEnableMaxDistance radius.
// @fnv 0x00c2acb0
void NiPSysGravityFieldModifier::ApplyForceToParticles(float time, NiPSysData* pkData)
{
    NiPSysData* data = pkData;
    if (m_fInfluence == 0 || data->m_usActive == 0 || !m_spFieldObject)
        return;
    if (!m_bEnableMaxDistance && m_fFieldAttenuation == 0)
    {
        ApplyGravityToParticles(time, pkData);
        return;
    }
    NiTransform fieldWorld;
    fieldWorld = m_spFieldObject->m_kWorld;
    NiTransform inverse;
    {
        NiTransform world;
        memcpy(&world, &reinterpret_cast<NiAVObject*>(m_pkTarget)->m_kWorld, sizeof(world));
        world.FUN_004b4880(inverse);
    }
    {
        NiTransform world = inverse * fieldWorld;
        float halfAttenuation = 0.5 * m_fFieldAttenuation;
        NiPoint3 forceDirection;
        forceDirection = RotateFieldDirection(world.m_Rotate, normalizedDirection);
        for (unsigned short i = 0; i < data->m_usActive; i++)
        {
            Point3ParameterData& particle = data->m_pkParticleInfo[i];
            float delta = time - particle.m_fZValue;
            if (!delta)
                continue;
            NiPoint3 position = data->m_pkVertex[i];
            NiPoint3 offset = position - world.m_Translate;
            float distanceSquared = offset.SqrLength();
            if (m_bEnableMaxDistance && !(m_fFieldStrength >= distanceSquared))
                continue;
            NiPoint3 change;
            if (m_fFieldAttenuation == 0.0f || distanceSquared == 0.0f)
            {
                change = forceDirection * (m_fInfluence * delta);
            }
            else
            {
                float scale = m_fInfluence * delta / BSMAX_00404010(1.0f, (float)pow(distanceSquared, halfAttenuation));
                const NiPoint3& dir = forceDirection;
                const double& wide = scale;
                change = NiPoint3(wide * dir.x, scale * dir.y, scale * dir.z);
            }
            particle.m_kValue += change;
        }
    }
}

