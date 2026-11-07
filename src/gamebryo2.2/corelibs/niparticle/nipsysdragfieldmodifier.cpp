#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysFieldModifier.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiTransform.h"


// Preserve the original uninitialized rotation without invoking its default constructor.
__forceinline NiTransform::NiTransform() : m_Rotate(m_Rotate)
{}

// src/gamebryo2.2/corelibs/niparticle/nipsysdragfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysdragfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01202770;

// @fnv 0x00c2c800
// src: COMMUNITY 0x00c2c800
GlobalObjectO2_00a7b610* __cdecl NiPSysDragFieldModifier_GetRTTI()
{
    return &g_01202770;
}

void __cdecl FUN_00c31750(void);
void __cdecl __Dummy_00b6fef0(void*, int);

struct FUN_00c2c810_shell
{
    void* __thiscall FUN_00c2c810(int arg);
};

// Calls FUN_00c31750, then if bit 0 of arg is set calls __Dummy_00b6fef0 on this with 0x40, and returns this.
// @fnv 0x00c2c810
void* __thiscall FUN_00c2c810_shell::FUN_00c2c810(int arg)
{
    void* p = this;
    FUN_00c31750();
    if (arg & 1)
        __Dummy_00b6fef0(p, 0x40);
    return p;
}

extern NiPoint3 _NiPoint3_ZERO;
extern int DAT_010bff2c;
struct CloningProcess
{
    NiObject* operator()(NiObject*);
};
struct NiPSysDragFieldModifier : NiPSysFieldModifier
{
    NiPSysFieldModifier* __thiscall CreateClone_00c2c8d0(CloningProcess&);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}

// Allocates and initialises a NiPSysDragFieldModifier clone, copies the byte at offset 0x30 and the NiPoint3 at offset 0x34 from this, and returns it.
// @fnv 0x00c2c8d0
// src: XBOX_PDB 0x00c2c8d0
NiPSysFieldModifier* __thiscall NiPSysDragFieldModifier::CreateClone_00c2c8d0(CloningProcess& process)
{
    NiPSysFieldModifier* clone = static_cast<NiPSysFieldModifier*>(BSFadeNode::operator new(0x40));
    if (clone)
    {
        ::new (clone) NiPSysFieldModifier;
        *(void**)clone = &DAT_010bff2c;
        *(unsigned char*)((char*)clone + 0x30) = 0;
        *(NiPoint3*)((char*)clone + 0x34) = _NiPoint3_ZERO;
    }
    else
    {
        clone = 0;
    }
    CopyMemberData(clone, process);
    *(unsigned char*)((char*)clone + 0x30) = *(unsigned char*)((char*)this + 0x30);
    *(NiPoint3*)((char*)clone + 0x34) = *(NiPoint3*)((char*)this + 0x34);
    return clone;
}

struct Particle
{
    NiPoint3 velocity;
    float rotation;
    float size;
    float age;
    float lifetime;
};
struct BoundDataBlock
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
    unsigned short activeCount;
    unsigned short unk52;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    Particle* particles;
};
struct DragFieldFields
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float damping;
};
// Scales each active particle's velocity by a damping factor derived from deltaTime, age and damping, zeroing it once the factor reaches zero.
// @fnv 0x00c2c830
void __fastcall ApplyDragDamping(DragFieldFields* self, void*, float deltaTime, BoundDataBlock* data)
{
    for (unsigned short i = 0; i < data->activeCount; ++i)
    {
        Particle& p = data->particles[i];
        float alpha = (deltaTime - p.age) * self->damping;
        if (alpha < 1.0f)
        {
            float factor = 1.0f - alpha;
            p.velocity.x *= factor;
            p.velocity.y *= factor;
            p.velocity.z *= factor;
        }
        else
        {
            p.velocity = _NiPoint3_ZERO;
        }
    }
}

// FUN_00c2cae0: /MT /O2 /GS /EHsc /Gy, 56 bytes, __thiscall with one stack argument.
// Compares this modifier against another one: a shared "compatible" helper, the
// type tag byte at +0x30, and the drag-field data block at +0x34.

struct FUN_00c2cae0_cls;

struct DragFieldData
{
    int unk00;
    bool FUN_00439090(DragFieldData* other);
};

struct FUN_00c2cae0_cls
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
    unsigned char m_30;
    DragFieldData m_34;
    bool FUN_00c32060(FUN_00c2cae0_cls* other);
    bool NiPSysDragFieldModifier_IsEqual(FUN_00c2cae0_cls* other);
};

// @fnv 0x00c2cae0
// src: XBOX_PDB 0x00c2cae0
bool FUN_00c2cae0_cls::NiPSysDragFieldModifier_IsEqual(FUN_00c2cae0_cls* other)
{
    if (FUN_00c32060(other))
    {
        if (other->m_30 == this->m_30)
        {
            if (!other->m_34.FUN_00439090(&this->m_34))
            {
                return true;
            }
        }
    }
    return false;
}

struct State
{
    int value;
    State(int value) : value(value)
    {}
};
struct Callback
{
    int unk00;
    int count;
    int(__cdecl* invoke)(Callback*, void**, int, const State&, int);
};
void __stdcall LoadFromStream(void*);
struct Subobject
{
    void __thiscall FUN_00a59be0(void*);
};
struct FUN_00c2ce10_owner
{
    void __thiscall InvokeCallbackAndUpdate(void* object);
};
// @fnv 0x00c2ce10
void FUN_00c2ce10_owner::InvokeCallbackAndUpdate(void* object)
{
    void* original = object;
    LoadFromStream(original);
    Callback* pCallback = *reinterpret_cast<Callback**>(static_cast<char*>(original) + 0x24c);

    pCallback->count += pCallback->invoke(pCallback, &object, 1, State(1), 1);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x30) =
        *reinterpret_cast<unsigned char*>(&object) != 0;
    reinterpret_cast<Subobject*>(reinterpret_cast<char*>(this) + 0x34)->FUN_00a59be0(original);
}

struct FNVCallbackOwner
{
    int unknown00;
    int total04;
    int unknown08;
    int(__cdecl* callback0c)(FNVCallbackOwner*, unsigned char*, int, int*, int);
};
struct FNVParameter
{
    FNVCallbackOwner* owner() const
    {
        return *reinterpret_cast<FNVCallbackOwner* const*>(reinterpret_cast<const char*>(this) + 0x250);
    }
};
struct FNVChild
{
    void __thiscall FUN_00a69780(FNVParameter*);
};
struct FNVMain
{
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14, unknown18, unknown1c;
    int unknown20, unknown24, unknown28, unknown2c;
    unsigned char enabled30;
    unsigned char state31, state32, state33;
    FNVChild child34;
    void __thiscall FUN_00c321f0(FNVParameter*);
    void __thiscall NiPSysDragFieldModifier_SaveBinary(FNVParameter*);
};
// Calls FUN_00c321f0, invokes the owner's callback0c with the enabled byte and adds its result to total04, then calls child34.FUN_00a69780.
// @fnv 0x00c2ce70
// src: XBOX_PDB 0x00c2ce70
void __thiscall FNVMain::NiPSysDragFieldModifier_SaveBinary(FNVParameter* pParameter)
{
    FUN_00c321f0(pParameter);
    unsigned char enabled = enabled30;
    FNVCallbackOwner* owner = pParameter->owner();
    int(__cdecl * pCallback)(FNVCallbackOwner*, unsigned char*, int, int*, int) = owner->callback0c;
    int value = 1;
    owner->total04 += pCallback(owner, &enabled, 1, &value, 1);
    child34.FUN_00a69780(pParameter);
}

struct FNVArray195
{
    void* vtable;
    void* elements;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growBy;
    void __thiscall FUN_0096ad30(unsigned int requiredSize);
    void __thiscall FUN_0096ae90(unsigned int index, void** value);
};
struct FNVSubObject195
{
    int unk00;
    void* __thiscall GetViewerString_00a59af0(const void* key);
};
struct GlobalObjectO2_00a7b610
{
    void* object;
};
extern GlobalObjectO2_00a7b610 g_01202770;
extern char UNK_010bffd0;
extern char UNK_01044b44;
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* object);
void* __cdecl NiGetViewerString(const void* key, unsigned int attribute);
struct FNVObject195
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    unsigned char attribute30;
    FNVSubObject195 subobject34;
    void __thiscall FUN_00c322b0(FNVArray195* storage);
    void __thiscall NiPSysDragFieldModifier_GetViewerStrings(FNVArray195* storage);
};
// @fnv 0x00c2cec0
// src: XBOX_PDB 0x00c2cec0
void __thiscall FNVObject195::NiPSysDragFieldModifier_GetViewerStrings(FNVArray195* pArray)
{
    FNVArray195* const array = pArray;
    FUN_00c322b0(array);
    void* value = NiViewerStrings_NiGetViewerString_Title(g_01202770.object);
    unsigned int uiIndex = array->count;
    if (uiIndex >= array->capacity)
    {
        array->FUN_0096ad30(uiIndex + array->growBy);
    }
    array->FUN_0096ae90(uiIndex, &value);
    value = NiGetViewerString(&UNK_010bffd0, attribute30);
    uiIndex = array->count;
    if (uiIndex >= array->capacity)
    {
        array->FUN_0096ad30(uiIndex + array->growBy);
    }
    array->FUN_0096ae90(uiIndex, &value);
    value = subobject34.GetViewerString_00a59af0(&UNK_01044b44);
    uiIndex = array->count;
    if (uiIndex >= array->capacity)
    {
        array->FUN_0096ad30(uiIndex + array->growBy);
    }
    array->FUN_0096ae90(uiIndex, &value);
}

struct AVStandIn
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
    NiTransform m_kWorldSpaceTransform;
    NiTransform GetWorldTransform() const
    {
        return m_kWorldSpaceTransform;
    }
};
struct PSysDataStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* m_pkVertex;
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
    unsigned short m_usActiveVertices;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Particle* m_pkParticleInfo;
};
static inline float Dot(const NiPoint3& a, const NiPoint3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
struct FieldModStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AVStandIn* m_pkSystem;
    int unk14;
    AVStandIn* m_pkFieldObject;
    float m_fInfluence;
    float unk20;
    float unk24;
    float unk28;
    float m_fDistanceLimit;
    void ApplyFieldModToParticles(float fTime, PSysDataStandIn* pkData);
};

// @fnv 0x00c2c950
void FieldModStandIn::ApplyFieldModToParticles(float fTime, PSysDataStandIn* pkData)
{
    NiTransform kField;
    kField = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kInv;
    NiPoint3 kFieldOrigin;
    {
        NiTransform kSys;
        kSys = m_pkSystem->m_kWorldSpaceTransform;
        kSys.FUN_004b4880(kInv);
    }
    {
        NiTransform kXform = kInv * kField;
        kFieldOrigin = kXform.m_Translate;
    }
    for (unsigned short i = 0; i < pkData->m_usActiveVertices; i++)
    {
        Particle& kParticle = pkData->m_pkParticleInfo[i];
        float fT = (fTime - kParticle.age) * m_fInfluence;
        if (fT != 0.0f)
        {
            NiPoint3 kPos = pkData->m_pkVertex[i];
            NiPoint3 kDiff;
            kDiff.x = kPos.x - kFieldOrigin.x;
            kDiff.y = kPos.y - kFieldOrigin.y;
            kDiff.z = kPos.z - kFieldOrigin.z;
            float fDistSq = Dot(kDiff, kDiff);
            if (fDistSq <= m_fDistanceLimit)
            {
                if (fT < 1.0f)
                {
                    float fScale = 1.0f - fT;
                    kParticle.velocity.x *= fScale;
                    kParticle.velocity.y *= fScale;
                    kParticle.velocity.z *= fScale;
                }
                else
                {
                    kParticle.velocity = _NiPoint3_ZERO;
                }
            }
        }
    }
}

extern "C" double __cdecl sqrt(double);

struct NiPoint3Helper : NiPoint3
{
    bool __thiscall FUN_00439090(const NiPoint3& kPt) const;
    void __thiscall Unitize_004a0c10();
};


inline NiPoint3 SubtractPoint(const NiPoint3& a, const NiPoint3& b)
{
    NiPoint3 res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    res.z = a.z - b.z;
    return res;
}

struct PointWords
{
    unsigned int x, y, z;
};
inline void CopyPoint(NiPoint3& dst, const NiPoint3& src)
{
    const PointWords& p = (const PointWords&)src;
    PointWords& d = (PointWords&)dst;
    unsigned int x = p.x, y = p.y, z = p.z;
    d.x = x;
    d.y = y;
    d.z = z;
}
struct DragModifier
{
    int unk00, unk04, unk08, unk0c;
    AVStandIn* m_pkTarget;
    int unk14;
    AVStandIn* m_spFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    char pad25, pad26, pad27;
    float m_fDistanceLimit;
    int unk2c;
    bool m_bFlagAtOffset30;
    char pad31, pad32, pad33;
    NiPoint3 m_kLightVector;

    void __thiscall ApplyDragDamping(float fTime, BoundDataBlock* pkData);
    void __thiscall ApplyFieldModToParticles(float fTime, BoundDataBlock* pkData);
    void __thiscall NiPSysDragFieldModifier_Update(float fTime, BoundDataBlock* pkData);
};

// Applies a drag field modifier to active particles, scaling or zeroing their velocity based on influence, distance, and motion direction.
// @fnv 0x00c2cb20
// src: XBOX_PDB 0x00c2cb20
void __thiscall DragModifier::NiPSysDragFieldModifier_Update(float fTime, BoundDataBlock* pkData)
{
    if (m_fInfluence == 0.0f)
        return;

    if (pkData->activeCount == 0 || !m_spFieldObject)
        return;

    if (!m_bFlagAtOffset30 && m_fFieldAttenuation == 0.0f)
    {
        if (m_bEnableMaxDistance)
            ApplyFieldModToParticles(fTime, pkData);
        else
            ApplyDragDamping(fTime, pkData);
        return;
    }

    NiTransform r;
    r = m_spFieldObject->m_kWorldSpaceTransform;
    NiTransform kInvTargetWorld;
    NiTransform kFieldWorld;
    kFieldWorld = m_pkTarget->m_kWorldSpaceTransform;
    kFieldWorld.FUN_004b4880(kInvTargetWorld);
    new (&kFieldWorld) NiTransform(kInvTargetWorld * r);

    NiPoint3 kMotionVelocity;
    (void)&kMotionVelocity;
    NiPoint3 kSub;
    NiPoint3 b;
    if (m_bFlagAtOffset30)
    {
        if (((NiPoint3Helper*)&m_kLightVector)->FUN_00439090(_NiPoint3_ZERO))
        {
            kSub = kFieldWorld.FUN_004b4500(&m_kLightVector);
            CopyPoint(b, kSub);
            ((NiPoint3Helper*)&b)->Unitize_004a0c10();
        }
    }

    for (unsigned short i = 0; i < pkData->activeCount; ++i)
    {
        Particle* y = &pkData->particles[i];
        float kTargetWorld = fTime - y->age;
        if (kTargetWorld == 0.0f)
            continue;

        NiPoint3 kPos;
        const PointWords* positions = (const PointWords*)pkData->unk20;
        PointWords& dst = (PointWords&)kPos;
        dst.x = positions[i].x;
        dst.y = positions[i].y;
        dst.z = positions[i].z;
        NiPoint3 res = SubtractPoint(kPos, kFieldWorld.m_Translate);

        float fDistSq = res.x * res.x + res.y * res.y + res.z * res.z;
        double distanceResult = (float)sqrt(fDistSq);
        float fDistance = (float)distanceResult;

        if (m_bEnableMaxDistance)
        {
            if (!(fDistance <= m_fDistanceLimit))
                continue;
        }

        float fDot = 1.0f;
        if (m_bFlagAtOffset30)
        {
            const PointWords& srcV = (const PointWords&)y->velocity;
            PointWords words = {srcV.x, srcV.y, srcV.z};
            (PointWords&)kMotionVelocity = words;
            ((NiPoint3Helper*)&kMotionVelocity)->Unitize_004a0c10();
            fDot = (kMotionVelocity.x * b.x) + (b.y * kMotionVelocity.y) + (b.z * kMotionVelocity.z);
        }

        float fFactor = (kTargetWorld * m_fInfluence * fDot) / (1.0 + m_fFieldAttenuation * fDistance);
        if (fFactor < 1.0f)
        {
            const NiPoint3& velocity = y->velocity;
            kSub.x = velocity.x * fFactor;
            kSub.y = velocity.y * fFactor;
            kSub.z = fFactor * velocity.z;
            y->velocity.x -= kSub.x;
            y->velocity.y -= kSub.y;
            y->velocity.z -= kSub.z;
        }
        else
        {
            y->velocity = _NiPoint3_ZERO;
        }
    }
}
