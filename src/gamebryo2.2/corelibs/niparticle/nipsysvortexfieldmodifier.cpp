
// src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/Mat3.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiPSysFieldModifier.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/StrArr.h"

extern "C" void* g_01202688;

// @fnv 0x00c26810
// src: COMMUNITY 0x00c26810
void* __cdecl NiPSysVortexFieldModifier_GetRTTI()
{
    return &g_01202688;
}

struct NiPSysVortexFieldModifier : NiPSysFieldModifier
{
    NiColor m_kFogTint;
    void LoadBinary_00c267d0(NiStream& stream);
};
// @fnv 0x00c267d0
// src: XBOX_PDB 0x00c267d0
void NiPSysVortexFieldModifier::LoadBinary_00c267d0(NiStream& stream)
{
    NiPSysFieldModifier::LoadBinary(stream);
    ((NiColor*)((char*)this + 0x30))->LoadBinary(stream);
}

void __cdecl FUN_00c31750();
void __cdecl operator delete(void*, unsigned int);

struct FUN_00c26920_shell
{
    FUN_00c26920_shell* __thiscall DestroyIfFlagged(int a);
};

// Calls FUN_00c31750, then deletes this with size 0x3c when bit 0 of a is set, and returns this.
// @fnv 0x00c26920
FUN_00c26920_shell* __thiscall FUN_00c26920_shell::DestroyIfFlagged(int a)
{
    FUN_00c31750();
    if (a & 1)
        operator delete(this, 0x3c);
    return this;
}

#include "../../../../include/NiMemObject.h"
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

// 0x00c2c110 is the drag modifier clone hook (ctor 0x00c2c030, drag object at 0x18), not an air field.
struct ParticleDragCloneOwner : NiPSysModifier
{
    NiObject* m_pkDragObject;
    void RemapDragObject(CloningProcess&);
};
// Calls NiPSysModifier::ProcessClone, then remaps the drag object through the clone map, falling back to the original pointer.
// @fnv 0x00c2c110
void ParticleDragCloneOwner::RemapDragObject(CloningProcess& aCloneProcess)
{
    NiPSysModifier::ProcessClone(aCloneProcess);
    NiObject* pMappedObject = 0;
    ((NiTPointerMap<NiObject*, NiObject*>*)aCloneProcess.m_pCloneMap)->GetAt(this, pMappedObject);
    ParticleDragCloneOwner* destination = (ParticleDragCloneOwner*)pMappedObject;
    if (m_pkDragObject)
    {
        if (((NiTPointerMap<NiObject*, NiObject*>*)aCloneProcess.m_pCloneMap)
                ->GetAt(m_pkDragObject, pMappedObject))
        {
            destination->m_pkDragObject = pMappedObject;
            return;
        }
        destination->m_pkDragObject = m_pkDragObject;
    }
}

char* __cdecl _FUN_00a7d330(void*);

extern void* _g_01202688;

struct C27A30Base
{
    void FUN_00c322b0(StrArr*);
};

struct FUN_00c27060_shell : C27A30Base
{
    void AppendNameAndDirection(StrArr* pkStrings);
};

// @fnv 0x00c27060
void FUN_00c27060_shell::AppendNameAndDirection(StrArr* pkStrings)
{
    FUN_00c322b0(pkStrings);
    char* pcStr = _FUN_00a7d330(_g_01202688);
    unsigned int uiIdx = pkStrings->m_usSize;
    if (uiIdx >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIdx);
    pkStrings->SetAt(uiIdx, pcStr);
    pcStr = ((NiPoint3*)((char*)this + 0x30))->GetViewerString_00a59af0("Direction");
    uiIdx = pkStrings->m_usSize;
    if (uiIdx >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIdx);
    pkStrings->SetAt(uiIdx, pcStr);
}

struct CloneVec3
{
    int x;
    int y;
    int z;
};

extern "C" CloneVec3 DAT_011f426c;

struct CloneItemBase
{
    CloneItemBase();
    virtual void Vfn0();
    char _pad_4[0x2c];
};

struct CloneItem : CloneItemBase
{
    void* operator new(unsigned int) throw();
    CloneItem() throw()
    {
        m_30 = DAT_011f426c;
    }
    virtual void Vfn0();
    CloneVec3 m_30;
};

struct CloneHost
{
    char _pad_0[0x30];
    CloneVec3 m_30;
    void NiPSysFieldModifier_CopyMembers(CloneItem* pItem, int a);
    CloneItem* NiPSysVortexFieldModifier_CreateClone(int a);
};

// Allocates a CloneItem, passes it with a to FUN_00c32020, copies m_30 into the item's m_30, and returns it.
// @fnv 0x00c26940
// src: XBOX_PDB 0x00c26940
CloneItem* CloneHost::NiPSysVortexFieldModifier_CreateClone(int a)
{
    CloneItem* pItem = new CloneItem;
    this->NiPSysFieldModifier_CopyMembers(pItem, a);
    pItem->m_30 = m_30;
    return pItem;
}

struct Pt_c268
{
    float x;
    float y;
    float z;
    Pt_c268()
    {}
    Pt_c268(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    Pt_c268 operator-(const Pt_c268& o) const
    {
        return Pt_c268(x - o.x, y - o.y, z - o.z);
    }
    Pt_c268 operator*(float f) const
    {
        return Pt_c268(x * f, y * f, z * f);
    }
    float operator*(const Pt_c268& o) const
    {
        return x * o.x + y * o.y + z * o.z;
    }
    // The game helper forms the unit cross product with this vector as receiver.
    Pt_c268 FUN_0053d1a0(const Pt_c268& value) const;
    Pt_c268& operator-=(const Pt_c268& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        return *this;
    }
};
extern const Pt_c268 _NiPoint3_ZERO;

// @fnv 0x00c26820
// src: GUESS 0x00c26820 (confidence: low)
Pt_c268 __stdcall Object_ProcessAndReturnValue_00c26820(const Pt_c268& origin, const Pt_c268& direction, const Pt_c268& point)
{
    Pt_c268 vDifference = point - origin;
    float dot = vDifference * direction;
    vDifference -= direction * dot;
    if (vDifference.x == _NiPoint3_ZERO.x && vDifference.y == _NiPoint3_ZERO.y && vDifference.z == _NiPoint3_ZERO.z)
        return vDifference;
    return direction.FUN_0053d1a0(vDifference);
}

#include <math.h>
inline float NiSqrt(float fValue)
{
    return sqrtf(fValue);
}

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    NiPoint3 res;
    res.x = x - pt.x;
    res.y = y - pt.y;
    res.z = z - pt.z;
    return res;
}
inline float NiPoint3::Length() const
{
    return NiSqrt(x * x + y * y + z * z);
}
inline NiPoint3 Mat3::operator*(const NiPoint3& pt) const
{
    return NiPoint3(m00 * pt.x + m01 * pt.y + m02 * pt.z, m10 * pt.x + m11 * pt.y + m12 * pt.z,
                m20 * pt.x + m21 * pt.y + m22 * pt.z);
}
// Keep the original empty construction; transform values are copied by assignment.
inline NiTransform::NiTransform()
{}

struct AVObj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64;
    NiTransform m_kWorldSpaceTransform;
};

struct ParticleInfo
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};

struct PSysData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    NiPoint3* m_pkVertex;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    unsigned short m_usActiveVertices;
    unsigned short unk52;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    ParticleInfo* m_pkParticleInfo;
    NiPoint3* GetVertices()
    {
        return m_pkVertex;
    }
    ParticleInfo* GetParticleInfo()
    {
        return m_pkParticleInfo;
    }
};

struct VortexModifier
{
    int unk00, unk04, unk08, unk0c;
    AVObj* m_pkTarget;
    int unk14;
    AVObj* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    float m_fDistanceLimit;
    int unk2c;
    NiPoint3 m_kLightVector;

    NiPoint3 Object_ProcessAndReturnValue_00c26820(const NiPoint3& akStart, const NiPoint3& kDirection, const NiPoint3& kPoint);
    void ApplyVortexVelocityWithinDistance(float fTime, PSysData* pkData);
};

// For each active particle with nonzero time delta, adds a scaled vector to its velocity when distance is at most m_fDistanceLimit squared.
// @fnv 0x00c269b0
// src: GUESS 0x00c269b0 (confidence: medium)
void VortexModifier::ApplyVortexVelocityWithinDistance(float fTime, PSysData* pkData)
{
    NiTransform kField;
    kField = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kInvPSys;
    {
        NiTransform kPSys;
        kPSys = m_pkTarget->m_kWorldSpaceTransform;
        kPSys.FUN_004b4880(kInvPSys);
    }
    {
        NiTransform kFieldToPSys = kInvPSys * kField;
        NiPoint3 kPosition = (*(NiPoint3*)&kFieldToPSys.m_Translate);
        NiPoint3 kDirection = (*(Mat3*)&kFieldToPSys.m_Rotate) * m_kLightVector;
        kDirection.Unitize_004a0c10();
        float fMaxDistanceSqr = m_fDistanceLimit * m_fDistanceLimit;
        for (unsigned short us = 0; us < pkData->m_usActiveVertices; us++)
        {
            ParticleInfo* pkCurrentParticle = &pkData->GetParticleInfo()[us];
            float fDeltaT = fTime - pkCurrentParticle->m_fZValue;
            if (fDeltaT != 0.0f)
            {
                NiPoint3* __restrict pkVertex = pkData->m_pkVertex;
                NiPoint3 kParticlePosition = pkVertex[us];
                float fDistance = static_cast<const NiPoint3&>(kParticlePosition - (*(NiPoint3*)&kFieldToPSys.m_Translate)).Length();  // the inline const body, as the stand-in had only that one
                if (fDistance != 0.0f && fDistance <= fMaxDistanceSqr)
                {
                    NiPoint3 kDeltaV = Object_ProcessAndReturnValue_00c26820(kPosition, kDirection, kParticlePosition);
                    kDeltaV *= m_fInfluence * fDeltaT;
                    pkCurrentParticle->m_kValue += kDeltaV;
                }
            }
        }
    }
}

namespace fnv_00c26c00 {
typedef Pt_c268 NiPoint3;
inline NiPoint3& operator+=(NiPoint3& a, NiPoint3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
struct NormVec3
{
    float x;
    float y;
    float z;
    void Unitize_004a0c10();
};
typedef char _sizecheck_NiTransform[sizeof(NiTransform) == 52 ? 1 : -1];
struct TransformNode
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
    NiTransform transform;
};
struct Particle
{
    NiPoint3 velocity;
    float unk0c;
    float unk10;
    float age;
    float unk18;
};
struct ParticleList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* positions;
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
    unsigned short count;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Particle* particles;
    NiPoint3* GetPositions()
    {
        return positions;
    }
};

inline NiPoint3 RotMul(const float* m, const NiPoint3& v)
{
    return NiPoint3(m[0] * v.x + m[1] * v.y + m[2] * v.z, m[4] * v.y + m[3] * v.x + m[5] * v.z,
                m[6] * v.x + m[7] * v.y + m[8] * v.z);
}
struct ForceOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TransformNode* node10;
    int unk14;
    TransformNode* node18;
    float unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    NiPoint3 m_dir;
    void ApplyParticleForces(float, ParticleList*);
    NiPoint3 ComputeForce(const NiPoint3& origin, const NiPoint3& axis, const NiPoint3& point);
    NiPoint3 Force(const NiPoint3& origin, const NiPoint3& axis, NiPoint3 point)
    {
        const NiPoint3 kPoint = point;
        return ComputeForce(origin, axis, kPoint);
    }
};
// Computes the force on each particle in list from node10's transform and m_dir, scaled by age, and adds it to each particle's velocity.
// @fnv 0x00c26c00
// src: GUESS 0x00c26c00 (confidence: medium)
void ForceOwner::ApplyParticleForces(float delta, ParticleList* list)
{
    NiTransform transformB;
    NiTransform transformA;
    transformB = node18->transform;
    transformA = node10->transform;
    NiTransform combined;
    NiTransform* pA = &transformA;
    pA->FUN_004b4880(combined);
    combined.FUN_0062c250(pA, transformB);
    NiPoint3 axis = RotMul(&transformA.m_Rotate.m_pEntry[0][0], m_dir);
    NiPoint3 origin = (*(NiPoint3*)&transformA.m_Translate);
    ((NormVec3*)&axis)->Unitize_004a0c10();
    for (unsigned short i = 0; i < list->count; ++i)
    {
        Particle* pParticle = list->particles + i;
        float age = delta;
        age -= pParticle->age;
        if (age != 0.0f)
        {
            NiPoint3& vel = pParticle->velocity;
            NiPoint3 result = Force(origin, axis, list->GetPositions()[i]);
            age = unk1c * age;
            result.x = age * result.x;
            result.y = age * result.y;
            result.z = age * result.z;
            vel += (const NiPoint3&)result;
        }
    }
}
}  // namespace fnv_00c26c00

namespace fnv_00c2c170 {
struct AirVector
{
    float x, y, z;
    __declspec(noalias) void Unitize_004a0c10();
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
    AirVector operator-(const AirVector& b) const
    {
        AirVector r = {x - b.x, y - b.y, z - b.z};
        return r;
    }
    AirVector operator*(float f) const
    {
        AirVector r = {x * f, y * f, z * f};
        return r;
    }
    AirVector& operator+=(const AirVector& b)
    {
        x = b.x + x;
        y += b.y;
        z += b.z;
        return *this;
    }
    float Dot(const AirVector& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};
struct AirNode
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    NiTransform world;
};
struct AirParticle
{
    AirVector velocity;
    float unk0c, unk10, birthTime, unk18;
};
struct AirParticles
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    AirVector* positions;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned short count, unk52;
    unsigned int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    AirParticle* particles;
    AirVector* GetVertices() const
    {
        return positions;
    }
    AirParticle* GetParticleInfo() const
    {
        return particles;
    }
};
inline AirVector Scale(AirVector a, float f)
{
    AirVector r = {f * a.x, f * a.y, f * a.z};
    return r;
}
struct AirField
{
    unsigned int unk00, unk04, unk08, unk0c;
    AirNode* owner;
    unsigned int unk14;
    AirNode* field;
    AirVector direction;
    float magnitude, nearDistance, farDistance;
    void NiPSysDragModifier_Update(float time, const AirParticles* data);
};
// Updates each particle's velocity along the normalized axis, with distance falloff above nearDistance and a time-based scale.
// @fnv 0x00c2c170
// src: XBOX_PDB 0x00c2c170
void AirField::NiPSysDragModifier_Update(float time, const AirParticles* apParticles)
{
    if (!(magnitude > 0.0f))
        return;
    if (apParticles->count <= 0)
        return;
    if (!field)
        return;
    NiTransform fieldWorld;
    fieldWorld = field->world;
    NiTransform transform;
    transform = owner->world;
    NiTransform inverse;
    transform.FUN_004b4880(inverse);
    inverse.FUN_0062c250(&transform, fieldWorld);
    AirVector axis;
    axis = (const AirVector&)((Mat3*)&transform)->FUN_004b4500(*(NiPoint3*)&direction);
    axis.Unitize_004a0c10();
    float axisSquared = axis.SquaredLength();
    float range = farDistance - nearDistance;
    for (unsigned short i = 0; i < apParticles->count; ++i)
    {
        AirVector position = apParticles->GetVertices()[i];
        AirVector displacement = position - *(AirVector*)&transform.m_Translate;
        AirParticle* pAlias0 = &apParticles->GetParticleInfo()[i];
        AirParticle* pAlias1 = pAlias0;
        AirParticle* particle = pAlias1;
        float distance = (float)sqrt(displacement.SquaredLength());
        float force = magnitude;
        float age = (float)((time - particle->birthTime) / 0.03333330154418945);
        if (distance > nearDistance)
        {
            if (distance >= farDistance)
                continue;
            distance -= nearDistance;
            force *= 1.0f - distance / range;
        }
        float along = axis.Dot(particle->velocity);
        if (force * age > 1.0)
        {
            age = -along / axisSquared;
            particle->velocity += Scale(axis, age);
        }
        else
        {
            age = -force * age * (along / axisSquared);
            particle->velocity += Scale(axis, age);
        }
    }
}
}  // namespace fnv_00c2c170
