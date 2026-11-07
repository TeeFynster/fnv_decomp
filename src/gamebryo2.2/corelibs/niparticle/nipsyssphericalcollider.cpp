// src/gamebryo2.2/corelibs/niparticle/nipsyssphericalcollider.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsyssphericalcollider.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiMemObject.h"
#include <string.h>
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysCollider.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiPSysPlanarCollider.h"
#include "../../../../include/NiPlane.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/StrArr.h"

// Inline bodies used by this unit are kept beside the shared declarations.
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}
inline void NiBinaryStream::ReadFloat(float& value)
{
    unsigned int size = 4;
    unsigned int& position = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4);
    position += (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(this, &value, 4, &size, 1);
}
inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}
inline void NiBinaryStream::Write(float* value)
{
    unsigned int size = 4;
    unsigned int& position = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4);
    position += (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 0xc))(this, value, 4, &size, 1);
}
inline NiTransform::NiTransform() {}
inline bool NiPlane::operator==(const NiPlane& other) const
{
    return x == other.x && y == other.y && z == other.z && c == other.c;
}
inline void StrArr::AppendInline(char* value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, value);
}
inline NiPoint3::NiPoint3(float a, float b, float d) : x(a), y(b), z(d) {}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    return NiPoint3(x - p.x, y - p.y, z - p.z);
}
inline NiPoint3 NiPoint3::operator*(float s) const
{
    return NiPoint3(x * s, y * s, z * s);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    return NiPoint3(x + p.x, y + p.y, z + p.z);
}
inline NiPoint3 NiPoint3::operator/(float s) const
{
    float inv = 1.0f / s;
    return NiPoint3(x * inv, y * inv, z * inv);
}
inline float NiPoint3::operator*(const NiPoint3& p) const
{
    return x * p.x + y * p.y + z * p.z;
}
inline NiPoint3& NiPoint3::operator-=(const NiPoint3& p)
{
    x -= p.x;
    y -= p.y;
    z -= p.z;
    return *this;
}

extern "C" const void* g_012026a0;

// @fnv 0x00c281f0
// src: COMMUNITY 0x00c281f0
const void* __cdecl NiPSysSphericalCollider_GetRTTI()
{
    return &g_012026a0;
}

// Retained locally until include/ supplies NiPSysSphericalCollider.
struct NiPSysSphericalCollider : NiPSysCollider
{
    NiAVObject* m_pkColliderObject;
    float m_fBoundRadius;
    float m_fScaledRadius;
    float m_fSquaredRadius;
    NiPoint3 m_kCenter;
    NiTransform m_kCachedNodeTransform;
    NiTransform m_kCachedOwnerTransform;

    void LoadBinary_00c28070(NiStream&);
    void BaseResolve(float fInitialTime, NiPSysData* pkData, unsigned short usCurrentParticle);
    void ResolveSphericalCollision(float fInitialTime, NiPSysData* pkData, unsigned short usCurrentParticle);
};
// @fnv 0x00c28070
// src: XBOX_PDB 0x00c28070
void NiPSysSphericalCollider::LoadBinary_00c28070(NiStream& kStream)
{
    NiPSysCollider::LoadBinary(kStream);
    kStream.ResetStreamState();
    if (kStream.GetFileVersion() >= 0x0A000113)
        kStream.GetBinaryStream()->ReadFloat(m_fBoundRadius);
}

namespace fnv_00c28200 {
void __cdecl _delete(void*, unsigned int);

struct NiPSysSphericalCollider : NiRefObject
{
    char _pad[0x20];
    NiRefObject* m_ptr;
    char _pad2[0xB0 - 0x2C];
    void* FUN_00c28200(unsigned int);
};
// Releases m_ptr, runs the base destructor, and frees this with _delete when flags has bit 0 set; returns this.
// @fnv 0x00c28200
void* NiPSysSphericalCollider::FUN_00c28200(unsigned int flags)
{
    if (m_ptr)
        m_ptr->DecRefCount();
    NiRefObject::~NiRefObject();
    if (flags & 1)
        _delete(this, 0xb0);
    return this;
}
}  // namespace fnv_00c28200

struct Collider : BSFadeNode
{
    Collider* __thiscall NiPSysSphericalCollider_NiPSysSphericalCollider(float, int, int, int, int, float);
};
// @fnv 0x00c282a0
Collider* CreateCollider()
{
    Collider* p = (Collider*)BSFadeNode::operator new(0xb0);
    if (p)
        return p->NiPSysSphericalCollider_NiPSysSphericalCollider(1.0f, 0, 0, 0, 0, 1.0f);
    return 0;
}

namespace fnv_00c29450 {
using ::NiMemObject;
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

struct ShaderBufferRecord;

struct NiTStringPointerMap_SBE
{
    bool GetAt(const char*, ShaderBufferRecord*&);
};

// This file supplies ProcessClone through a local derived method because the shared
// planar collider does not declare its override.
struct PlanarColliderClone : NiPSysPlanarCollider
{
    void ProcessPlanarClone(CloningProcess&);
};
// @fnv 0x00c29450
void PlanarColliderClone::ProcessPlanarClone(CloningProcess& kCloning)
{
    NiPSysCollider::ProcessClone(reinterpret_cast<::CloningProcess&>(kCloning));
    ShaderBufferRecord* pkClone = 0;
    ((NiTStringPointerMap_SBE*)kCloning.m_pCloneMap)->GetAt((const char*)this, pkClone);
    NiPSysPlanarCollider* pkDest = (NiPSysPlanarCollider*)pkClone;
    if (m_pkColliderObject)
    {
        if (((NiTStringPointerMap_SBE*)kCloning.m_pCloneMap)
                ->GetAt((const char*)m_pkColliderObject, pkClone))
            pkDest->m_pkColliderObject = (NiAVObject*)pkClone;
        else
            pkDest->m_pkColliderObject = m_pkColliderObject;
    }
}
}  // namespace fnv_00c29450

struct SphericalColliderClone : NiPSysSphericalCollider
{
    Collider* CloneCollider(CloningProcess& kCloning);
};
// @fnv 0x00c28250
Collider* SphericalColliderClone::CloneCollider(CloningProcess& kCloning)
{
    Collider* pkObject = (Collider*)BSFadeNode::operator new(0xb0);
    if (pkObject)
        pkObject = pkObject->NiPSysSphericalCollider_NiPSysSphericalCollider(1.0f, 0, 0, 0, 0, 1.0f);
    else
        pkObject = 0;
    ((NiPSysPlanarCollider*)this)->CopyMemberData((NiPSysPlanarCollider*)pkObject, kCloning);
    ((NiPSysSphericalCollider*)pkObject)->m_fBoundRadius = m_fBoundRadius;
    return pkObject;
}

struct ColliderPoint
{
    float x, y, z;
};

extern "C" void TransformDiffers();
inline bool operator!=(const NiTransform& a, const NiTransform& b)
{
    return reinterpret_cast<bool (__thiscall*)(const NiTransform*, const NiTransform&)>(TransformDiffers)(&a, b);
}

struct ColliderOwner
{
    int unk00, unk04, unk08, unk0C;
    NiAVObject* node;
    NiAVObject* GetNode() const
    {
        return node;
    }
};

struct UpdateCollider
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    ColliderOwner* owner;
    NiPSysCollider* next;
    NiAVObject* node;
    float radius, scaledRadius, squaredRadius;
    ColliderPoint center;
    NiTransform cachedNode, cachedOwner;
    void UpdateColliderTransform();
};
// Recomputes the collider's center, scaled radius and squared radius from the node and owner world transforms when either has changed, then calls next->vf37().
// @fnv 0x00c27f60
void UpdateCollider::UpdateColliderTransform()
{
    if (cachedNode != node->m_kWorld || cachedOwner != owner->GetNode()->m_kWorld)
    {
        NiTransform nodeTransform;
        if (node)
            memcpy(&nodeTransform, &node->m_kWorld, sizeof(nodeTransform));
        else
            nodeTransform.ResetToIdentity();
        NiTransform ownerTransform;
        memcpy(&ownerTransform, &owner->GetNode()->m_kWorld, sizeof(ownerTransform));
        NiTransform inverse;
        ownerTransform.FUN_004b4880(inverse);
        NiTransform relative = inverse * nodeTransform;
        float newRadius = radius * relative.m_fScale;
        center = reinterpret_cast<const ColliderPoint&>(relative.m_Translate);
        scaledRadius = newRadius;
        squaredRadius = scaledRadius * scaledRadius;
        memcpy(&cachedOwner, &ownerTransform, sizeof(cachedOwner));
        memcpy(&cachedNode, &nodeTransform, sizeof(cachedNode));
    }
    if (next)
        next->vf37();
}

struct SphericalColliderReader : NiPSysCollider
{
    unsigned int& linkId()
    {
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x2c);
    }
    float& radius()
    {
        return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x30);
    }
    void FUN_00c32900(NiStream& stream);
    void ReadSphericalCollider(NiStream& stream);
};
// Reads the base collider data, then reads the link id and radius float from the stream.
// @fnv 0x00c280c0
void SphericalColliderReader::ReadSphericalCollider(NiStream& stream)
{
    FUN_00c32900(stream);
    stream.SaveLinkID(reinterpret_cast<const NiObject*>(linkId()));
    stream.Istr().Write(&radius());
}

inline NiPoint3 operator*(float s, const NiPoint3& p)
{
    return NiPoint3(s * p.x, s * p.y, s * p.z);
}

struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
};

// @fnv 0x00c27e20
void NiPSysSphericalCollider::ResolveSphericalCollision(float fInitialTime, NiPSysData* pkData,
                                                         unsigned short usCurrentParticle)
{
    Point3ParameterData* pkCurrentParticle = &pkData->m_pkParticleInfo[usCurrentParticle];
    NiPoint3& kVel = pkCurrentParticle->m_kValue;
    NiPoint3 kNormal = (m_kCollisionPosition - m_kCenter) / m_fScaledRadius;
    float fProjection = kVel * kNormal;
    NiPoint3 kTemp = fProjection * kNormal;
    kVel -= kTemp + kTemp;
    kVel *= m_fBounceFactor;
    BaseResolve(fInitialTime, pkData, usCurrentParticle);
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const void*);
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
extern const char DAT_010be8cc[];
extern const char DAT_01015a9c[];
extern const char DAT_0102909c[];
struct InfoName
{
    int unk00;
    int unk04;
    const char* name;
};
struct ColliderInfo
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
    InfoName* info;
    float radius;
    void AppendProperties(StrArr*);
    void NiPSysSphericalCollider_GetViewerStrings(StrArr* strings);
};
// @fnv 0x00c282d0
// src: XBOX_PDB 0x00c282d0
void ColliderInfo::NiPSysSphericalCollider_GetViewerStrings(StrArr* strings)
{
    AppendProperties(strings);
    strings->AppendInline(NiViewerStrings_NiGetViewerString_Title(g_012026a0));
    strings->AppendInline(NiGetViewerString_00a7d5e0(DAT_010be8cc, info ? info->name : DAT_0102909c));
    strings->AppendInline(NiGetViewerString_00a7d550(DAT_01015a9c, radius));
}

struct SphericalColliderComparison
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
    NiObject* m_pkColliderObject;
    float m_fBoundRadius;
    bool NiPSysSphericalCollider_IsEqual(SphericalColliderComparison* pkObject);
};

extern "C" void ColliderIsEqual();

// Returns false if the base comparison, collider-object comparison, or bound-radius comparison fails.
// @fnv 0x00c27ae0
// src: XBOX_PDB 0x00c27ae0
bool SphericalColliderComparison::NiPSysSphericalCollider_IsEqual(SphericalColliderComparison* pkObject)
{
    if (!reinterpret_cast<bool (__thiscall*)(const NiPSysCollider*, NiObject*)>(ColliderIsEqual)(
            reinterpret_cast<const NiPSysCollider*>(this), reinterpret_cast<NiObject*>(pkObject)))
        return false;

    SphericalColliderComparison* pkDest = pkObject;

    if ((m_pkColliderObject && !pkDest->m_pkColliderObject) || (!m_pkColliderObject && pkDest->m_pkColliderObject) ||
        (m_pkColliderObject && pkDest->m_pkColliderObject &&
         !static_cast<const NiObject*>(m_pkColliderObject)->IsEqual(pkDest->m_pkColliderObject)))
    {
        return false;
    }

    if (m_fBoundRadius != pkDest->m_fBoundRadius)
        return false;

    return true;
}

#include <math.h>
extern "C" float g_010be824;
struct CollisionVector
{
    float x, y, z;
    CollisionVector()
    {}
    CollisionVector(float a, float b, float c) : x(a), y(b), z(c)
    {}
    CollisionVector operator-(const CollisionVector& b) const
    {
        return CollisionVector(x - b.x, y - b.y, z - b.z);
    }
    CollisionVector operator+(const CollisionVector& b) const
    {
        return CollisionVector(x + b.x, y + b.y, z + b.z);
    }
    CollisionVector operator*(float s) const
    {
        return CollisionVector(x * s, y * s, z * s);
    }
    float operator*(const CollisionVector& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    float SquaredLength() const
    {
        return (*this) * (*this);
    }
};
struct CollisionParticle
{
    CollisionVector velocity;
    float age, lifespan, lastUpdate, generation;
};
struct CollisionParticles
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CollisionVector* positions;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    CollisionParticle* particles;
};
struct SphereCollision
{
    int unk00, unk04, unk08, unk0c, unk10;
    CollisionVector hitPoint;
    float hitTime;
    ColliderOwner* owner;
    NiPSysCollider* next;
    NiAVObject* node;
    float radius, scaledRadius, squaredRadius;
    CollisionVector center;
    SphereCollision* FUN_00c32450(float, float&, CollisionParticles*, unsigned short);
    SphereCollision* TestSphereCollision(float, float&, CollisionParticles*, unsigned short);
};
// Tests if a particle at the given index hits this sphere, updating earliest and hitPoint if so, then delegates to FUN_00c32450.
// @fnv 0x00c27b40
SphereCollision* SphereCollision::TestSphereCollision(float time, float& earliest, CollisionParticles* data,
                                                      unsigned short index)
{
    bool hit = false;
    const CollisionVector& position = data->positions[index];
    const CollisionVector& velocity = data->particles[index].velocity;
    CollisionVector difference = position - center;
    float c = difference.SquaredLength() - squaredRadius;
    bool inside = -c > g_010be824;
    if (inside || c > g_010be824)
    {
        float projection = -(difference * velocity);
        if (inside || projection > 0.0f)
        {
            float speedSquared = velocity.SquaredLength();
            float t = projection / speedSquared;
            difference = (position + velocity * t) - center;
            const CollisionVector& relative = difference;
            float distanceSquared = relative.SquaredLength();
            if (inside || distanceSquared < squaredRadius)
            {
                float delta = squaredRadius - distanceSquared;
                if (inside)
                    t += sqrtf(delta / speedSquared);
                else
                    t -= sqrtf(delta / speedSquared);
                if (t < earliest - time)
                {
                    hit = true;
                    float collisionTime = time + t;
                    hitTime = earliest = collisionTime;
                    hitPoint = position + velocity * t;
                }
            }
        }
    }
    SphereCollision* result = FUN_00c32450(time, earliest, data, index);
    return result ? result : (hit ? this : 0);
}

struct ColliderNormal : CollisionVector
{
    ColliderNormal() {}
    ColliderNormal(float a, float b, float c) : CollisionVector(a, b, c) {}
    // Evaluate the second axis first to retain the original floating-point load order.
    static ColliderNormal Cross(const CollisionVector& b, const CollisionVector& a)
    {
        const float& az = a.z;
        return ColliderNormal(a.y * b.z - az * b.y, az * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    }
};
struct ColliderMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    CollisionVector operator*(const CollisionVector& p) const
    {
        double y1 = m11 * p.y;
        double z1 = m21 * p.y;
        return CollisionVector(m00 * p.x + m01 * p.y + m02 * p.z, m10 * p.x + y1 + m12 * p.z, m20 * p.x + z1 + m22 * p.z);
    }
};
extern const NiPoint3 NiPoint3_ZERO;
extern const ColliderMatrix DAT_011a9448;
struct PlanarColliderUpdate
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    ColliderOwner* owner;
    NiPSysCollider* next;
    NiAVObject* node;
    float width, height;
    NiPoint3 axis1, axis2;
    float squareWidth, squareHeight;
    NiPlane plane;
    NiPoint3 center;
    ColliderMatrix rotation;
    NiTransform cachedNode, cachedOwner;
    void Update();
};
// Recomputes plane, center, rotation, and squared dimensions when the plane is zero or transforms differ, then updates the next collider.
// @fnv 0x00c294b0
void PlanarColliderUpdate::Update()
{
    if (static_cast<const NiPlane&>(plane) == NiPlane(NiPoint3_ZERO, 0.0f) ||
        (node && (cachedNode != node->m_kWorld || cachedOwner != owner->GetNode()->m_kWorld)))
    {
        memcpy(&center, &NiPoint3_ZERO, sizeof(center));
        rotation = DAT_011a9448;
        ColliderNormal normal = ColliderNormal::Cross(
            reinterpret_cast<const CollisionVector&>(axis2), reinterpret_cast<const CollisionVector&>(axis1));
        reinterpret_cast<NiPoint3&>(normal).Unitize_004a0c10();
        float w = width;
        float h = height;
        if (node)
        {
            NiTransform nodeWorld;
            memcpy(&nodeWorld, &node->m_kWorld, sizeof(nodeWorld));
            NiTransform ownerWorld;
            memcpy(&ownerWorld, &owner->GetNode()->m_kWorld, sizeof(ownerWorld));
            NiTransform inverse;
            ownerWorld.FUN_004b4880(inverse);
            NiTransform relative = inverse * nodeWorld;
            memcpy(&center, &relative.m_Translate, sizeof(center));
            rotation = reinterpret_cast<const ColliderMatrix&>(relative.m_Rotate.m_pEntry[0][0]);
            static_cast<CollisionVector&>(normal) = rotation * normal;
            reinterpret_cast<NiPoint3&>(normal).Unitize_004a0c10();
            w *= relative.m_fScale;
            h *= relative.m_fScale;
            memcpy(&cachedNode, &nodeWorld, sizeof(cachedNode));
            memcpy(&cachedOwner, &ownerWorld, sizeof(cachedOwner));
        }
        w *= 0.5;
        h *= 0.5;
        squareWidth = w * w;
        squareHeight = h * h;
        plane = NiPlane(reinterpret_cast<const NiPoint3&>(normal), center);
    }
    if (next)
        next->vf37();
}

extern const ColliderMatrix DAT_011f4248;
extern const char DAT_010be834[];
// The shared collider has no constructor entry point for this initializer.
extern "C" void InitializeColliderBase();

// Initializes collider fields, passes settings to the base initializer, sets a nonnegative radius, and initializes cached transforms.
// @fnv 0x00c28110
// src: EXE 0x00c28110
Collider* Collider::NiPSysSphericalCollider_NiPSysSphericalCollider(float fBounce, int bSpawnOnCollide, int bDieOnCollide, int pkSpawnModifier,
                                 int pkColliderObj, float fRadius)
{
    UpdateCollider* p = (UpdateCollider*)this;
    reinterpret_cast<void (__thiscall*)(NiPSysCollider*, float, int, int, int)>(InitializeColliderBase)(
        reinterpret_cast<NiPSysCollider*>(this), fBounce, bSpawnOnCollide, bDieOnCollide, pkSpawnModifier);
    p->node = (NiAVObject*)pkColliderObj;
    p->radius = 1.0f;
    p->squaredRadius = 1.0f;
    *(const void**)this = DAT_010be834;
    p->center = reinterpret_cast<const ColliderPoint&>(NiPoint3_ZERO);
    if (fRadius >= 0.0f)
        p->radius = fRadius;
    ColliderPoint kMaxPoint = {-3.402823466e+38F, -3.402823466e+38F, -3.402823466e+38F};
    reinterpret_cast<ColliderPoint&>(p->cachedNode.m_Translate) = reinterpret_cast<ColliderPoint&>(p->cachedOwner.m_Translate) = kMaxPoint;
    reinterpret_cast<ColliderMatrix&>(p->cachedNode.m_Rotate.m_pEntry[0][0]) = reinterpret_cast<ColliderMatrix&>(p->cachedOwner.m_Rotate.m_pEntry[0][0]) =
        DAT_011f4248;
    p->cachedNode.m_fScale = p->cachedOwner.m_fScale = -3.402823466e+38F;
    return this;
}
