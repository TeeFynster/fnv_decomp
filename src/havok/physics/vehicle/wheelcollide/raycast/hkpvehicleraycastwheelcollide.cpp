
// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the unit's original SIMD union: VC9 treats the SDK byte-array
// views as /GS buffers and changes parameter copies in the wheel output code.
#define _INCLUDED_MM2
// Exe 0x00e423d0 InitializeMissedWheelContact: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" {
LocalM128 _mm_load_ss(const float*);
void _mm_store_ss(float*, LocalM128);
LocalM128 _mm_load_ps(const float*);
void _mm_store_ps(float*, LocalM128);
LocalM128 _mm_add_ss(LocalM128, LocalM128);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_sub_ps(LocalM128, LocalM128);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_rcp_ps(LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
}

#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpPhantomOverlapListener.h"
#include "../../../../../../include/hkpRejectChassisListener.h"
#include "../../../../../../include/hkpVehicleWheelCollide.h"
#include "../../../../../../include/hkpVehicleRayCastWheelCollide.h"
#include "../../../../../../include/hkpVehicleData.h"
#include "../../../../../../include/hkpVehicleInstance.h"
#include "../../../../../../include/hkpVehicleSuspension.h"
#include "../../../../../../include/hkpVehicleInstanceWheelInfo.h"
#include "../../../../../../include/hkpAabbPhantom.h"
#include "../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../include/hkpWorldRayCastOutput.h"

typedef signed char hkInt8;
typedef unsigned char hkUint8;

// hkArray.h identifies hkMemoryRouter as the shared hkMemoryRouter layout.
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

union __declspec(align(16)) hkAabbQ
{
    float m_data[8];
};

// These Havok constructors are inline in the original unit.

inline void* hkpVehicleRayCastWheelCollide::operator new(unsigned int nbytes)
{
    hkpVehicleRayCastWheelCollide* b = static_cast<hkpVehicleRayCastWheelCollide*>(hkMemoryRouter_getInstance().heap().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return b;
}

// @fnv 0x00e41f10
void hkpVehicleRayCastWheelCollide::SetUserInfo(int aiValue)
{
    m_uiWheelCount = aiValue;
    hkpAabbPhantom* p = m_pPhantom;
    if (p)
        p->m_kCollidable.m_kBroadPhaseHandle.m_uiCollisionFilterData = aiValue;
}

struct FUN_00c936a0_host
{
    void* hkpWorld_addPhantom(void* phantom);
};

// @fnv 0x00e41ef0
void* hkpVehicleRayCastWheelCollide::AddToWorld(void* world)
{
    return ((FUN_00c936a0_host*)world)->hkpWorld_addPhantom(m_pPhantom);
}

// @fnv 0x00e41e70
void hkpVehicleRayCastWheelCollide::UpdatePhantom(const hkpVehicleInstance* vehicle)
{
    hkAabbQ aabb;
    this->GetWheelAabb(vehicle, &aabb);
    this->m_pPhantom->hkpAabbPhantom_setAabb(aabb);
}

struct FUN_00c92c70_host
{
    void hkpWorld_removePhantom(void* phantom);
};
// @fnv 0x00e41f00
void hkpVehicleRayCastWheelCollide::RemoveFromWorld()
{
    void* p = m_pPhantom;
    ((FUN_00c92c70_host*)*(void**)((char*)p + 8))->hkpWorld_removePhantom(p);
}

extern int DAT_010e5ae4;
extern int DAT_0102e388;

// 0x00e360f0 destroys the embedded hkpRejectChassisListener.
struct RejectChassisListenerMethods : public hkpRejectChassisListener
{
    void Destroy();
};

// @fnv 0x00e41fc0
void hkpVehicleRayCastWheelCollide::Destroy()
{
    hkpAabbPhantom* phantom = this->m_pPhantom;
    *(int**)this = &DAT_010e5ae4;

    if (phantom)
    {
        if (this->m_kChassisRejectionListener.m_pChassisCollidable)
        {
            phantom->removePhantomOverlapListener_00d07c80(&m_kChassisRejectionListener);
        }

        this->m_pPhantom->removeReference();
    }

    static_cast<RejectChassisListenerMethods*>(&this->m_kChassisRejectionListener)->Destroy();
    *(int**)this = &DAT_0102e388;
}

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <typename T> __forceinline void ConstructWithCopy(T* destination, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        destination[i] = value;
}

// @fnv 0x00e42610
void hkpVehicleRayCastWheelCollide::AppendPhantom(hkArray<hkpAabbPhantom*>& phantoms)
{
    hkpAabbPhantom* phantom = m_pPhantom;
    hkMemoryAllocator& allocator = hkMemoryRouter_getInstance().heap();
    if (phantoms.m_iElementCount == phantoms.getCapacity())
        ResizeAudioStream(&allocator, &phantoms, sizeof(hkpAabbPhantom*));
    ConstructWithCopy(phantoms.m_data + phantoms.m_iElementCount, 1, phantom);
    phantoms.m_iElementCount++;
}

// @fnv 0x00e41f30
void hkpVehicleRayCastWheelCollide::CreateWheelPhantom(const hkpVehicleInstance* vehicle)
{
    hkAabbQ aabb;

    this->GetWheelAabb(vehicle, &aabb);

    hkMemoryRouter& host = hkMemoryRouter_getInstance();

    hkpAabbPhantom* allocated = reinterpret_cast<hkpAabbPhantom*>(host.heap().blockAlloc(0xe0));

    allocated->m_usMemSizeAndFlags = 0xe0;

    hkpAabbPhantom* pPhantom =
        allocated->FUN_00cf2cb0(reinterpret_cast<const hkAabb&>(aabb), this->m_uiWheelCount);

    this->m_pPhantom = pPhantom;

    this->m_kChassisRejectionListener.m_pChassisCollidable = &reinterpret_cast<hkpWorldObject*>(vehicle->m_pEntity)->m_kCollidable;

    pPhantom->addPhantomOverlapListener_00d07de0(&this->m_kChassisRejectionListener);
}

extern "C" LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);

extern const LocalM128 DAT_010c44d0;

inline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}
inline void hkVector4::setXYZ(const hkVector4& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, _mm_unpackhi_ps(v.m_vComponents, m_vComponents), 0xc4);
}
__forceinline float& hkVector4::operator()(int i)
{
    return reinterpret_cast<float*>(&m_vComponents)[i];
}

// Complete the wheel-parameter type forward-declared by the shared suspension header.
class hkpVehicleSuspensionSuspensionWheelParameters
{
public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    float m_fRestLength;
    unsigned int unk24, unk28, unk2C;
};

// Copies WheelInfo+0x60 (m_vContactNormal), negates the hard point, and stores the rest length.
// @fnv 0x00e423d0
void __stdcall InitializeMissedWheelContact(const hkpVehicleInstance* pkVehicle, unsigned char ucWheelNum,
                                          ::hkpVehicleWheelCollide::WheelCollideResult& kCdInfo)
{
    const float fRestLength = pkVehicle->m_pSuspension->m_kWheelParams[ucWheelNum].m_fRestLength;
    const hkpVehicleInstance::WheelInfo& kWheel = reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(pkVehicle->m_kWheelInfoArray.m_data)[ucWheelNum];
    kCdInfo.m_pUserData = 0;
    kCdInfo.m_fContactFriction = fRestLength;
    kCdInfo.m_fValueAtOffset4C = 0.0f;
    kCdInfo.m_vContactPoint.m_vContactPosition = kWheel.m_vContactNormal;
    hkVector4 kNormal;
    kNormal.setNeg4(kWheel.m_vHardPointWs);
    kCdInfo.m_vContactPoint.m_vSeparatingNormal.setXYZ(kNormal);
    kCdInfo.m_fSuspensionLength = 0.0f;
    kCdInfo.m_fValueAtOffset50 = 1.0f;
    kCdInfo.m_vContactPoint.m_vSeparatingNormal(3) = fRestLength;
}

// The calls at 0x00d07c80/0x00d07de0 remove/add phantom overlap listeners,
// and chassis+0x10 is hkpWorldObject::m_kCollidable, not simulation-island data.
// @fnv 0x00e42590
hkpVehicleRayCastWheelCollide* hkpVehicleRayCastWheelCollide::Clone(hkpWorldObject* chassis, const hkArray<hkpAabbPhantom*>& phantoms)
{
    hkpVehicleRayCastWheelCollide* clone = new hkpVehicleRayCastWheelCollide();
    clone->m_pPhantom = phantoms.m_data[0];
    clone->m_pPhantom->addReference();
    clone->m_pPhantom->removePhantomOverlapListener_00d07c80(&m_kChassisRejectionListener);
    clone->m_pPhantom->addPhantomOverlapListener_00d07de0(&clone->m_kChassisRejectionListener);
    clone->m_kChassisRejectionListener.m_pChassisCollidable = &chassis->m_kCollidable;
    clone->m_uiWheelCount = m_uiWheelCount;
    return clone;
}

// Constructs a vehicle wheel collide object, initializing wheel count to 0, phantom to null, collision disabled, and type to 1.
// @fnv 0x00e42550
hkpVehicleRayCastWheelCollide::hkpVehicleRayCastWheelCollide() : m_uiWheelCount(0), m_pPhantom(0)
{
    m_bWheelCollisionEnabled.m_cBooleanValue = 0;
    m_type = 1;
}

struct __declspec(align(16)) WheelRayInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    unsigned char m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};

// Builds an input from vectors at source offsets 0x50 and 0x60 (filter info = m_uiWheelCount) and passes it with output to m_pPhantom's FUN_00cf26b0.
// @fnv 0x00e41eb0
void __thiscall hkpVehicleRayCastWheelCollide::CastWheelRay(const hkpVehicleInstanceWheelInfo& wheel, hkpWorldRayCastOutput& output)
{
    WheelRayInput input;
    *(LocalM128*)&input.m_vFrom = *(LocalM128*)((const char*)&wheel + 0x50);
    *(LocalM128*)&input.m_vTo = *(LocalM128*)((const char*)&wheel + 0x60);
    input.m_uiFilterInfo = m_uiWheelCount;
    input.m_bEnableShapeCollectionFilter = 1;
    m_pPhantom->hkpAabbPhantom_castRay_00cf26b0(&input, &output);
}

// Iterates over vehicle wheels, casts a ray for each, and processes or finalizes the collision output based on whether the ray hit.
// @fnv 0x00e420c0
void hkpVehicleRayCastWheelCollide::CollideWheels(float deltaTime, const hkpVehicleInstance* vehicle,
                                  ::hkpVehicleWheelCollide::WheelCollideResult* cdInfoOut)
{
    const unsigned char numWheels = static_cast<unsigned char>(vehicle->m_data->m_iWheelCount);
    for (unsigned char w_it = 0; w_it < numWheels; ++w_it)
    {
        const hkpVehicleInstanceWheelInfo& wheel_info = vehicle->m_kWheelInfoArray.m_data[w_it];
        ::hkpVehicleWheelCollide::WheelCollideResult& cd_wheelInfo = cdInfoOut[w_it];
        hkpWorldRayCastOutput raycastOutput;
        CastWheelRay(wheel_info, raycastOutput);
        if (raycastOutput.DidHit())
        {
            ProcessWheelRayCastResult(vehicle, w_it, raycastOutput, cd_wheelInfo);
        }
        else
        {
            FinalizeWheelCollisionOutput(vehicle, w_it, cd_wheelInfo);
        }
        InitializeWheelCollisionOutput(vehicle, w_it, cd_wheelInfo);
    }
}

extern "C" LocalM128 _mm_min_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_max_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, LocalM128 a);

// Computes wheel bounds from WheelInfo vectors at offsets 0x50 and 0x60.
// @fnv 0x00e42010
void __stdcall ComputeWheelAabb(const hkpVehicleInstance* self, hkAabbQ* aabb)
{
    _mm_store_ps(&aabb->m_data[0], _mm_min_ps(_mm_load_ps(&reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(self->m_kWheelInfoArray.m_data)[0].m_vContactPointVelocity.x),
                                              _mm_load_ps(&reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(self->m_kWheelInfoArray.m_data)[0].m_vContactNormal.x)));
    _mm_store_ps(&aabb->m_data[4], _mm_max_ps(_mm_load_ps(&reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(self->m_kWheelInfoArray.m_data)[0].m_vContactPointVelocity.x),
                                              _mm_load_ps(&reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(self->m_kWheelInfoArray.m_data)[0].m_vContactNormal.x)));
    for (int i = 1; i < self->m_data->m_iWheelCount; i++)
    {
        const hkpVehicleInstance::WheelInfo* b = &reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(self->m_kWheelInfoArray.m_data)[i];
        LocalM128 vMin = _mm_min_ps(_mm_load_ps(&aabb->m_data[0]), _mm_load_ps(&b->m_vContactNormal.x));
        _mm_store_ps(&aabb->m_data[0], vMin);
        vMin = _mm_min_ps(vMin, _mm_load_ps(&b->m_vContactPointVelocity.x));
        _mm_store_ps(&aabb->m_data[0], vMin);
        LocalM128 vMax = _mm_max_ps(_mm_load_ps(&aabb->m_data[4]), _mm_load_ps(&b->m_vContactNormal.x));
        _mm_store_ps(&aabb->m_data[4], vMax);
        vMax = _mm_max_ps(vMax, _mm_load_ps(&b->m_vContactPointVelocity.x));
        _mm_store_ps(&aabb->m_data[4], vMax);
    }
}

struct CollidableRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const hkpRayShapeCollectionFilter* m_pRayShapeCollectionFilter;
    hkUlong m_ulUserData;
    int unk2c;
};

struct CollidableRayCastCommand
{
    CollidableRayCastQuery m_kRayCastQuery;
    hkUint32 m_uiCollisionFilterInfo;
    hkInt32 m_iCommandParameter;
    hkpCollidable* const* m_kCollidables;
    int m_iCollidableCount;
    hkpWorldRayCastOutput* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    char m_bResultFlag;
};

// Sets up one ray-cast command per wheel from the vehicle instance and returns the wheel count, or 0 when no collidables overlap.
// @fnv 0x00e42460
int hkpVehicleRayCastWheelCollide::BuildRayCastCommands(const hkpVehicleInstance* vehicle,
                                                const hkpCollisionFilter* collisionFilter, hkInt32 filterSize,
                                                CollidableRayCastCommand* commandStorage,
                                                hkpWorldRayCastOutput* outputStorage) const
{
    m_pPhantom->vf10();

    const int numCollidables = m_pPhantom->m_ppOverlappingCollidables.m_iElementCount;
    if (numCollidables > 0)
    {
        const hkInt8 numWheels = vehicle->m_data->m_iWheelCount;
        if (numWheels > 0)
        {
            int i = 0;
            int count = (hkUint8)numWheels;
            do
            {
                CollidableRayCastCommand& command = *commandStorage;
                const hkpVehicleInstance::WheelInfo& wheelInfo = reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(vehicle->m_kWheelInfoArray.m_data)[i];

                command.m_kRayCastQuery.m_vFrom.m_vComponents = wheelInfo.m_vContactPointVelocity.m_vComponents;
                command.m_kRayCastQuery.m_vTo.m_vComponents = wheelInfo.m_vContactNormal.m_vComponents;
                command.m_kRayCastQuery.m_uiFilterInfo = m_uiWheelCount;
                command.m_kRayCastQuery.m_pRayShapeCollectionFilter = collisionFilter;
                command.m_uiCollisionFilterInfo = collisionFilter->m_type;
                command.m_iCommandParameter = filterSize;
                command.m_bResultFlag = false;
                command.m_kCollidables = reinterpret_cast<hkpCollidable* const*>(m_pPhantom->m_ppOverlappingCollidables.m_data);
                command.m_pResultBuffer = outputStorage;
                command.m_iCollidableCount = numCollidables;
                command.m_iResultCount = 1;
                command.m_iResultCapacity = 0;
                ++i;
                ++commandStorage;
                ++outputStorage;
            } while (--count != 0);
        }
        return numWheels;
    }
    return 0;
}
