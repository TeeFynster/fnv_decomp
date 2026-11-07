#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve this unit's intrinsic storage and its aliasing behavior.
#define _INCLUDED_MM2
// Exe 0x00e36670 InitializeWheelCollisionOutput: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

// HavokAllocatorContext_hkpvehiclelinearcastwheelcollide: local type (was include/HavokAllocatorContext.h, which had no evidence of one real class); no method of it is bound to a named game function
class hkMemoryAllocator;

class HavokAllocatorContext_hkpvehiclelinearcastwheelcollide
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    union
    {
        hkMemoryAllocator* m_router;
        hkMemoryAllocator* m_alloc;
    };
};
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkpRootCdPoint.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkpAabbPhantom.h"
#include "../../../../../../include/hkMemoryAllocator.h"

#include "../../../../../../include/hkpCollidable.h"
#include "../../../../../../include/hkpTypedBroadPhaseHandle.h"
#include "../../../../../../include/hkpRigidBody.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpWorld.h"
#include "../../../../../../include/hkpVehicleWheelCollide.h"
#include "../../../../../../include/hkpVehicleLinearCastWheelCollide.h"
#include "../../../../../../include/hkpPhantom.h"
#include "../../../../../../include/hkpPhantomOverlapListener.h"
#include "../../../../../../include/hkpRejectChassisListener.h"
#include "../../../../../../include/hkpVehicleData.h"
#include "../../../../../../include/hkpVehicleInstance.h"
#include "../../../../../../include/hkpVehicleInstanceWheelInfo.h"
#include "../../../../../../include/hkpVehicleSuspension.h"

inline void* operator new(unsigned int, void* pvMem) throw();

extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern const LocalM128 DAT_010c44d0;

__forceinline hkAabb::hkAabb() {}
__forceinline const hkVector4& hkTransform::getTranslation() const
{
    return reinterpret_cast<const hkVector4&>(m_vTranslation);
}
__forceinline LocalM128& hkVector4::getQuad() { return m_vComponents; }
__forceinline const LocalM128& hkVector4::getQuad() const { return m_vComponents; }
__forceinline float& hkVector4::operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}
__forceinline void hkVector4::setXYZ(const hkVector4& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, _mm_unpackhi_ps(v.m_vComponents, m_vComponents), 0xc4);
}

__forceinline hkpRigidBody* hkpVehicleInstance::getChassis() const
{
    return static_cast<hkpRigidBody*>(m_pEntity);
}

extern "C" HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* __cdecl hkMemoryRouter_getInstance() throw();

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* array, int numElem, int sizeElem) throw();

inline hkMemoryAllocator& GetWheelHeap(HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* context)
{
    return *context->m_alloc;
}

// The original wheel-state resize reserves raw storage, then updates only the count.
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = m_iCapacityState & 0x3fffffff;
    if (capacity < n)
    {
        int doubled = 2 * capacity;
        int newCapacity = (n < doubled) ? doubled : n;
        hkArrayUtil__reserve(alloc, this, newCapacity, sizeof(T));
    }
}
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T> inline void ResizeWheelArray(hkArrayBase<T>& array, int n)
{
    array._setSize(reinterpret_cast<hkMemoryAllocator&>(GetWheelHeap(hkMemoryRouter_getInstance())), n);
}

typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef short hkInt16;
typedef unsigned short hkUint16;

// Wheel states are 0x60 bytes: phantom/shape, transform at 0x10, cast endpoint at 0x50.
class __declspec(align(16)) hkpVehicleLinearCastWheelCollideWheelState
{
public:
    hkpAabbPhantom* m_pPhantom;
    hkpShape* m_pCollisionShape;
    hkUint32 m_08;
    hkUint32 m_0c;
    hkTransform m_kMotionTransform;
    hkVector4 m_vTo;
};

struct LCHit
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    hkContactPoint* m_obj;
    int m_2c;
    int m_valid;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
};

// @fnv 0x00e36250
// src: HAVOK_LIB 0x00e36250
hkContactPoint* hkpVehicleLinearCastWheelCollide::determineNearestHit(int iWheel, LCHit* pHits)
{
    int numHits = static_cast<const hkpVehicleLinearCastWheelCollide*>(this)->getNumHits(static_cast<unsigned char>(iWheel));
    hkContactPoint* nearest = 0;
    for (int i = 0; i < numHits; i++)
    {
        const LCHit& rHit = pHits[i];
        if (rHit.m_valid)
        {
            hkContactPoint* pHitObj = rHit.m_obj;
            if (!nearest || pHitObj->m_vSeparatingNormal.w < nearest->m_vSeparatingNormal.w)
                nearest = pHitObj;
        }
    }
    return nearest;
}

// Orders the wheel phantom overlaps through vtable slot 0x28 and returns their count at 0xd4.
// @fnv 0x00e363a0
// src: HAVOK_LIB 0x00e363a0
unsigned int hkpVehicleLinearCastWheelCollide::getNumCommands(unsigned char wheelIndex)
{
    hkpAabbPhantom* wheel = m_kWheelStates[wheelIndex].m_pPhantom;
    wheel->vf10();
    return wheel->m_ppOverlappingCollidables.m_iElementCount;
}

// Iterates count records at this+0x10 and passes each record's first dword to p->FUN_00c936a0.
// @fnv 0x00e36870
// src: HAVOK_LIB 0x00e36870
void hkpVehicleLinearCastWheelCollide::addToWorld_00e36870(hkpWorld* apHost)
{
    int count = m_kWheelStates.m_iElementCount;

    if (count > 0)
    {
        for (int i = 0; i < count; ++i)
        {
            hkpPhantom* value = m_kWheelStates.m_data[i].m_pPhantom;
            apHost->hkpWorld_addPhantom(value);
        }
    }
}

struct FUN_00c92c70_Class
{
    void hkpWorld_removePhantom(void*);
};

// Iterates the entries in the array at this+0x10, calling FUN_00c92c70 on each entry's object at offset 8.
// @fnv 0x00e368a0
// src: HAVOK_LIB 0x00e368a0
void hkpVehicleLinearCastWheelCollide::removeFromWorld()
{
    int count = m_kWheelStates.m_iElementCount;
    if (count > 0)
    {
        int offset = 0;
        do
        {
            void* p = *(void**)((char*)m_kWheelStates.m_data + offset);
            FUN_00c92c70_Class* q = (FUN_00c92c70_Class*)*(void**)((char*)p + 8);
            q->hkpWorld_removePhantom(p);
            offset += 0x60;
            count--;
        } while (count != 0);
    }
}

// Sets collision filter data on this collider and every non-null wheel phantom.
// @fnv 0x00e368d0
void hkpVehicleLinearCastWheelCollide::SetTargetArg(void* arg)
{
    int count = m_kWheelStates.m_iElementCount;
    m_uiWheelCount = reinterpret_cast<hkUint32>(arg);
    for (int i = 0; i < count; i++)
    {
        hkpAabbPhantom* t = m_kWheelStates.m_data[i].m_pPhantom;
        if (t != 0)
        {
            t->m_kCollidable.m_kBroadPhaseHandle.m_uiCollisionFilterData = reinterpret_cast<hkUint32>(arg);
        }
    }
}

void __cdecl centerWheelContactPoint();
// @fnv 0x00e36aa0
// src: HAVOK_SRC 0x00e36aa0
void __cdecl hkpVehicleLinearCastWheelCollide_wheelCollideCallback()
{
    centerWheelContactPoint();
}

extern "C" HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* __cdecl hkMemoryRouter_getInstance() throw();

template <> __forceinline hkArray<hkpVehicleLinearCastWheelCollideWheelState>::~hkArray()
{
    HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* mem = hkMemoryRouter_getInstance();
    hkMemoryAllocator* router = mem->m_router;
    int cap = this->m_iCapacityState;
    this->m_iElementCount = 0;
    if (!(cap & 0x80000000))
    {
        router->bufFree(this->m_data, (cap & 0x3fffffff) * sizeof(hkpVehicleLinearCastWheelCollideWheelState));
    }
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}

// @fnv 0x00e36b80
hkpVehicleLinearCastWheelCollide::~hkpVehicleLinearCastWheelCollide() throw()
{
    int numWheels = this->m_kWheelStates.m_iElementCount;
    for (int i = 0; i < numWheels; ++i)
    {
        hkpVehicleLinearCastWheelCollideWheelState* ws = &this->m_kWheelStates.m_data[i];
        ws->m_pCollisionShape->removeReference();
        hkpPhantom* phantom = ws->m_pPhantom;
        if (this->m_usMemSizeAndFlags != 0 && phantom->m_usMemSizeAndFlags != 0)
        {
            phantom->removePhantomOverlapListener_00d07c80(&this->m_kRejectChassisListener);
        }
        phantom->removeReference();
    }
}

inline hkMemoryAllocator& GetHeapE36E(HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* context)
{
    return *reinterpret_cast<hkMemoryAllocator*>(context->m_alloc);
}

__forceinline void* hkpVehicleLinearCastWheelCollide::operator new(unsigned int uiSize) throw()
{
    hkReferencedObject* p = (hkReferencedObject*)GetHeapE36E(hkMemoryRouter_getInstance()).blockAlloc(uiSize);
    p->m_usMemSizeAndFlags = (unsigned short)uiSize;
    return p;
}

// @fnv 0x00e36e20
hkpVehicleLinearCastWheelCollide* hkpVehicleLinearCastWheelCollide::CloneWithChassis(
    const hkpRigidBody& kNewChassis, const hkArray<hkpPhantom*>& kNewPhantoms) const throw()
{
    hkpVehicleLinearCastWheelCollide* pkNew = new hkpVehicleLinearCastWheelCollide();
    const int iNumWheels = m_kWheelStates.GetLogicalSize();
    ResizeWheelArray(pkNew->m_kWheelStates, iNumWheels);
    for (hkUint8 i = 0; i < iNumWheels; i++)
    {
        hkpVehicleLinearCastWheelCollideWheelState& kWheelState = pkNew->m_kWheelStates[i];
        // Keep the source array storage read independent of the newly allocated wheel state.
        kWheelState.m_pCollisionShape = static_cast<const volatile hkArrayBase<hkpVehicleLinearCastWheelCollideWheelState>&>(m_kWheelStates).m_data[i].m_pCollisionShape;
        kWheelState.m_pCollisionShape->addReference();
        hkpAabbPhantom* pkPhantom = static_cast<hkpAabbPhantom*>(kNewPhantoms[i]);
        kWheelState.m_pPhantom = pkPhantom;
        pkPhantom->addReference();
        pkPhantom->removePhantomOverlapListener_00d07c80((hkpRejectChassisListener*)&m_kRejectChassisListener);
        pkPhantom->addPhantomOverlapListener_00d07de0(&pkNew->m_kRejectChassisListener);
        pkNew->m_kRejectChassisListener.m_pChassisCollidable = const_cast<hkpLinkedCollidable*>(&kNewChassis.m_kCollidable);
    }
    pkNew->m_uiWheelCount = m_uiWheelCount;
    pkNew->m_fMaxExtraPenetration = m_fMaxExtraPenetration;
    pkNew->m_fMaxExtraPenetrationAgainstFixed = m_fMaxExtraPenetrationAgainstFixed;
    return pkNew;
}

__declspec(align(16)) struct LCWheelCastOut
{
    unsigned int u00, u04, u08, u0c, u10, u14, u18, u1c;
    unsigned int u20, u24, u28, u2c, u30, u34, u38, u3c;
    unsigned int u40, u44, u48, u4c, u50, u54, u58, u5c;
    unsigned int u60, u64, u68, u6c;
};

// Iterates over each wheel of the vehicle, queries the cast, applies hit or no-hit results, and updates the wheel state.
// @fnv 0x00e361b0
void hkpVehicleLinearCastWheelCollide::UpdateAllWheels(int aiUnused, hkpVehicleInstance* vehicle, hkpVehicleWheelCollide::WheelCollideResult* results)
{
    LCWheelCastOut output;
    unsigned char i;
    char found;
    const unsigned char numWheels = vehicle->m_data->m_iWheelCount;

    for (i = 0; i < numWheels; i++)
    {
        char* status = castQuery(&found, vehicle, i, &output);
        if (*status != 0)
            applyHit(vehicle, i, &output, results);
        else
            noHit(vehicle, i, results);
        InitializeWheelCollisionOutput(vehicle, i, *results);
        results++;
    }
}

// Sums the hit counts of all wheels in m_kWheelStates by calling getNumHits for each wheel index and returns the total.
// @fnv 0x00e36360
int hkpVehicleLinearCastWheelCollide::GetTotalHits() const
{
    int iTotal = 0;
    const int iNumWheels = m_kWheelStates.GetLogicalSize();
    for (unsigned char i = 0; i < iNumWheels; ++i)
    {
        iTotal += getNumHits(i);
    }
    return iTotal;
}

extern "C" LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);

extern const LocalM128 DAT_010c44d0;

class hkpVehicleSuspensionSuspensionWheelParameters
{
public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    float m_fRestLength;
    unsigned int unk24, unk28, unk2C;
};

// 0x00e36670 initializes wheel output without reading this; its signature matches the shared base virtual, not a ray-cast class.
// @fnv 0x00e36670
void hkpVehicleWheelCollide::InitializeWheelCollisionOutput(const hkpVehicleInstance* pkVehicle,
                                                                      unsigned char ucWheelNum,
                                                                      hkpVehicleWheelCollide::WheelCollideResult& kCdInfo)
{
    const float fRestLength = pkVehicle->m_pSuspension->m_kWheelParams[ucWheelNum].m_fRestLength;
    const hkpVehicleInstanceWheelInfo& kWheel = pkVehicle->m_kWheelInfoArray.m_data[ucWheelNum];
    kCdInfo.m_pUserData = 0;
    kCdInfo.m_fContactFriction = fRestLength;
    kCdInfo.m_fValueAtOffset4C = 0.0f;
    kCdInfo.m_vContactPoint.m_vContactPosition = reinterpret_cast<const hkVector4&>(kWheel.unk60);
    hkVector4 kNormal;
    kNormal.setNeg4(reinterpret_cast<const hkVector4&>(kWheel.unk80));
    kCdInfo.m_vContactPoint.m_vSeparatingNormal.setXYZ(kNormal);
    kCdInfo.m_fSuspensionLength = 0.0f;
    kCdInfo.m_fValueAtOffset50 = 1.0f;
    kCdInfo.m_vContactPoint.m_vSeparatingNormal(3) = fRestLength;
}

// Passes result and the wheel state at wheelIndex through two helpers with z zeroed in between, and stores the final vector in result.
// @fnv 0x00e36900
// src: XBOX_PDB 0x00e36900
void hkpVehicleLinearCastWheelCollide::centerWheelContactPoint(int unused, unsigned char wheelIndex, hkVector4* result)
{
    hkVector4 second;
    hkVector4 first;

    const hkTransform* ws = &m_kWheelStates[wheelIndex].m_kMotionTransform;

    first.hkVector4_setTransformedInversePos(static_cast<const hkTransform*>(ws), result);

    first.z = 0.0f;

    second.setTransformedPos_00c7f640(*static_cast<const hkTransform*>(ws), first);

    result->m_vComponents = second.m_vComponents;
}

// For each wheel state, fetch its AABB and push it into the associated object via FUN_00cf24a0.
// @fnv 0x00e36950
void hkpVehicleLinearCastWheelCollide::UpdateWheelAabb(unsigned char wheelIndex)
{
    int count = m_kWheelStates.m_iElementCount;
    unsigned char stateIndex = 0;

    if (count > 0)
    {
        do
        {
            hkpVehicleLinearCastWheelCollide_updateWheelState(wheelIndex, stateIndex);

            hkAabb aabb;
            hkpVehicleLinearCastWheelCollide_calcAabbOfWheel(wheelIndex, stateIndex, &aabb);

            m_kWheelStates.m_data[stateIndex].m_pPhantom->hkpAabbPhantom_setAabb(aabb);

            ++stateIndex;
        } while (stateIndex < count);
    }
}

extern hkReal DAT_0104da48;
extern hkReal DAT_0104da4c;
extern hkUint8 DAT_010c476c;

struct __declspec(align(16)) LCCastInput
{
    hkVector4 m_vTo;
    volatile hkReal m_10;
    volatile hkReal m_14;
    hkUint32 m_18;
    hkUint32 m_1c;
    const hkUint8* m_20;
    hkReal m_24;
    hkUint32 m_28;
    hkUint32 m_2c;
    hkUint32 m_30;
    hkUint32 m_34;
    hkUint32 m_38;
    hkUint32 m_3c;
    hkUint32 m_40;
    hkUint32 m_44;
    hkUint32 m_48;
    hkReal m_4c;
    hkInt32 m_50;
    hkUint32 m_54;
    hkUint32 m_58;
    hkUint32 m_5c;
    hkUint32 m_60;
    hkUint32 m_64;
    hkUint32 m_68;
    hkUint32 m_6c;
    hkUint32 m_70;
    hkUint32 m_74;
    hkUint32 m_78;
    hkUint32 m_7c;
    hkUint32 m_80;
    hkUint32 m_84;
    hkUint32 m_88;
    hkUint32 m_8c;
    hkUint32 m_90;
    hkUint32 m_94;
    hkUint32 m_98;
    hkUint32 m_9c;
};

struct FUN_006212c0_Context
{
    void InitializeFields_006212c0(void* data);
};

// Casts the wheel's shape, writes a hit flag byte through hitOut, and on a hit passes the cast data to context via FUN_006212c0.
// @fnv 0x00e369d0
void hkpVehicleLinearCastWheelCollide::CastWheel(int hitOut, hkUint32 b, hkUint8 wheelIndex, int context)
{
    hkpVehicleLinearCastWheelCollideWheelState* pWheelState = &m_kWheelStates.m_data[wheelIndex];

    // Raw word storage preserves the original stack buffer classification.
    unsigned int resultStorage[sizeof(hkpCollidable) / sizeof(unsigned int)];
    hkpCollidable& result = *reinterpret_cast<hkpCollidable*>(resultStorage);
    new (&result) hkpCollidable(
        static_cast<const void*>(pWheelState->m_pCollisionShape), &pWheelState->m_kMotionTransform, 0);
    result.m_kBroadPhaseHandle.m_uiCollisionFilterData = m_uiWheelCount;

    LCCastInput input;
    input.m_10 = DAT_0104da4c;
    input.m_14 = DAT_0104da4c;
    LocalM128 tmp = *reinterpret_cast<const LocalM128*>(&pWheelState->m_vTo);
    input.m_10 = m_fMaxExtraPenetration;
    input.m_14 = m_fMaxExtraPenetrationAgainstFixed;
    input.m_4c = DAT_0104da48;
    *reinterpret_cast<LocalM128*>(&input.m_vTo) = tmp;
    input.m_24 = DAT_0104da48;
    input.m_20 = &DAT_010c476c;
    input.m_50 = 0;

    pWheelState->m_pPhantom
        ->hkpAabbPhantom_linearCast(&result,
                       reinterpret_cast<const LinCastInputS&>(input), &input.m_20, 0);

    if (input.m_50 != 0)
    {
        ((FUN_006212c0_Context*)(*(volatile int*)&context))->InitializeFields_006212c0(&input.m_30);
        hkUint8* __restrict pHitOut = (hkUint8*)(*(volatile int*)&hitOut);
        *pHitOut = 1;
    }
    else
    {
        hkUint8* __restrict h0 = (hkUint8*)(*(volatile int*)&hitOut);
        *h0 = 0;
    }
}

// 0x00e36c30 stores shapes at wheel-state offset 0x04 with stride 0x60, identifying the former ray-cast stand-in as the linear-cast class.
// @fnv 0x00e36c30
void hkpVehicleLinearCastWheelCollide::SetWheelPhantoms(const hkpVehicleInstance* vehicle,
                                                        const hkArray<hkReferencedObject*>& phantoms)
{
    int numWheels = (unsigned char)vehicle->m_data->m_iWheelCount;
    ResizeWheelArray(m_kWheelStates, numWheels);
    for (unsigned char i = 0; i < numWheels; i++)
    {
        m_kWheelStates[i].m_pCollisionShape = static_cast<hkpShape*>(phantoms[i]);
        phantoms[i]->addReference();
    }
}

inline hkMemoryAllocator& GetHeapE36C(HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* context)
{
    return *reinterpret_cast<hkMemoryAllocator*>(context->m_alloc);
}

// Creates wheel shapes if none exist, sets the chassis collidable on the reject listener, and builds a phantom per wheel from its AABB.
// @fnv 0x00e36cc0
void hkpVehicleLinearCastWheelCollide::InitializeWheelCollisions(const hkpVehicleInstance* pkVehicle) throw()
{
    const int iNumWheels = (hkUint8)pkVehicle->m_data->m_iWheelCount;

    if (m_kWheelStates.GetLogicalSize() == 0)
    {
        ResizeWheelArray(m_kWheelStates, iNumWheels);
        for (hkUint8 i = 0; i < iNumWheels; i++)
        {
            m_kWheelStates[i].m_pCollisionShape = hkpVehicleLinearCastWheelCollide_createWheelShape(pkVehicle->m_data->m_kWheelParams[i].m_fMaxFriction,
                                                               pkVehicle->m_data->m_kWheelParams[i].m_fSphereRadius);
        }
    }

    m_kRejectChassisListener.m_pChassisCollidable = &pkVehicle->getChassis()->m_kCollidable;

    for (hkUint8 i = 0; i < iNumWheels; i++)
    {
        hkpVehicleLinearCastWheelCollide_updateWheelState(pkVehicle, i);
        hkAabb kAabb;
        hkpVehicleLinearCastWheelCollide_calcAabbOfWheel(pkVehicle, i, kAabb);
        hkpAabbPhantom* pvMem = static_cast<hkpAabbPhantom*>(
            GetHeapE36C(hkMemoryRouter_getInstance()).blockAlloc(sizeof(hkpAabbPhantom)));
        pvMem->m_usMemSizeAndFlags = sizeof(hkpAabbPhantom);
        const unsigned int uiElapsedMilliseconds = i * sizeof(hkpVehicleLinearCastWheelCollideWheelState);
        hkpAabbPhantom* pkPhantom = ::new (pvMem) hkpAabbPhantom(kAabb, m_uiWheelCount);
        *(hkpPhantom**)((char*)m_kWheelStates.m_data + uiElapsedMilliseconds) = pkPhantom;
        (*(hkpPhantom**)((char*)m_kWheelStates.m_data + uiElapsedMilliseconds))
            ->addPhantomOverlapListener_00d07de0(&m_kRejectChassisListener);
    }
}

// Initializes the penetration tolerances and selects linear-cast wheel collision.
// @fnv 0x00e36b20
hkpVehicleLinearCastWheelCollide::hkpVehicleLinearCastWheelCollide() throw()
{
    m_fMaxExtraPenetration = 1.192092896e-07f;
    m_fMaxExtraPenetrationAgainstFixed = 1.192092896e-07f;
    m_bWheelCollisionEnabled = 0;
    m_type = 2;
}

extern "C" LocalM128 _mm_setr_ps(float x, float y, float z, float w);
extern const float g_fZeroE36120;
extern const LocalM128 g_kSignMaskE36120;
__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}

HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* GetContextE36120();
struct ShapeE36120
{
    static void* operator new(unsigned int nbytes) throw()
    {
        HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* pkContext = GetContextE36120();
        ShapeE36120* pkShape = static_cast<ShapeE36120*>(reinterpret_cast<hkMemoryAllocator*>(pkContext->m_alloc)->blockAlloc(nbytes));
        pkShape->m_usMemSize = (unsigned short)nbytes;
        return pkShape;
    }
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSize;
    unsigned short m_usRefCount;
};
struct CapsuleE36120 : public ShapeE36120
{
    CapsuleE36120(const hkVector4& kA, const hkVector4& kB, float fRadius, float fExtra) throw();
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
};

// @fnv 0x00e36120
// src: XBOX_PDB 0x00e36120
ShapeE36120* __stdcall hkpVehicleLinearCastWheelCollide_createWheelShape(float afHeight, float fRadius)
{
    hkVector4 kTop;
    kTop.set(g_fZeroE36120, g_fZeroE36120, afHeight * 0.5, g_fZeroE36120);
    hkVector4 kBottom;
    kBottom.m_vComponents = _mm_xor_ps(g_kSignMaskE36120, kTop.m_vComponents);
    return new CapsuleE36120(kTop, kBottom, fRadius, 0.0f);
}

inline void* operator new(unsigned int, void* pvMem) throw()
{
    return pvMem;
}

__forceinline void hkpTypedBroadPhaseHandle::SetOwnerPointer(void* owner)
{
    m_iOwnerOffset = (signed char)((unsigned long)owner - (unsigned long)this);
}

// 0x00e363d0 builds each wheel's collidable with this constructor inlined (Havok defines it inline in hkpCollidable.h).
__forceinline hkpCollidable::hkpCollidable(const hkpShape* shape, const hkTransform* transform, int type)
    : m_pCollisionShape(shape), m_uiCollisionShapeKey(0xffffffff), m_pMotionState(transform), m_parent(0),
      m_iOwnerOffset(0), m_kBroadPhaseHandle(type)
{
    m_fAllowedPenetrationDepth = -1.0f;
    m_kBroadPhaseHandle.SetOwnerPointer(this);
    m_uiForceCollideOntoPpu = 0;
    m_uiShapeSizeOnSpu = 0;
}

// Xbox PDB: hkpPairLinearCastCommand is 0x40 bytes; no shared header exists yet.
struct hkpPairLinearCastCommand
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    const hkpCollidable* m_pCollidableA;
    const hkpCollidable* m_pCollidableB;
    hkpRootCdPoint* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    hkpRootCdPoint* m_pStartPointResultBuffer;
    int m_iStartPointResultCount;
    int m_iStartPointResultCapacity;
};

// Fills one linear cast command for each collidable overlapping each wheel's phantom, creating a collidable per wheel, and returns the command count.
// @fnv 0x00e363d0
// src: HAVOK_SRC 0x00e363d0
int hkpVehicleLinearCastWheelCollide::buildLinearCastCommands(const hkpVehicleInstance* pkVehicle,
                                           const hkpCollisionFilter* pkFilter,
                                           hkpCollidable* pkCollidableStorage,
                                           hkpPairLinearCastCommand* pkCommandStorage,
                                           hkpRootCdPoint* pkOutputStorage) const throw()
{
    int iNumCommands = 0;
    const int iNumWheels = m_kWheelStates.GetLogicalSize();
    for (char i = 0; i < iNumWheels; ++i)
    {
        const hkpVehicleLinearCastWheelCollideWheelState& kWheelState = m_kWheelStates[i];
        if (pkCollidableStorage)
            new (pkCollidableStorage) hkpCollidable(kWheelState.m_pCollisionShape, &kWheelState.m_kMotionTransform, 0);

        kWheelState.m_pPhantom->vf10();
        const hkArray<void*>& kOverlapping = kWheelState.m_pPhantom->m_ppOverlappingCollidables;
        const int iNumOverlapping = kOverlapping.GetLogicalSize();
        for (char j = 0; j < iNumOverlapping; ++j)
        {
            ++iNumCommands;
            hkpPairLinearCastCommand& kCommand = *pkCommandStorage;
            kCommand.m_pCollidableA = pkCollidableStorage;
            kCommand.m_pCollidableB = static_cast<hkpCollidable*>(kOverlapping.m_data[j]);
            kCommand.m_vFrom = kWheelState.m_kMotionTransform.getTranslation();
            kCommand.m_vTo = kWheelState.m_vTo;
            kCommand.m_pResultBuffer = pkOutputStorage;
            kCommand.m_iResultCount = 1;
            kCommand.m_iResultCapacity = 0;
            kCommand.m_iStartPointResultCount = 0;
            // Exe 0x00e364b7 advances output slots by 0x70 bytes, independently of the contact-point size.
            pkOutputStorage = reinterpret_cast<hkpRootCdPoint*>(reinterpret_cast<char*>(pkOutputStorage) + 0x70);
            ++pkCommandStorage;
        }
        ++pkCollidableStorage;
    }
    return iNumCommands;
}

void __cdecl ResizeAudioStream(void* heap, void* arr, int elementSize);

// Iterates wheel states and appends each wheel's phantom pointer to the output array, growing it when needed.
// @fnv 0x00e36ab0
// src: HAVOK_LIB 0x00e36ab0
void hkpVehicleLinearCastWheelCollide::getPhantoms(hkArray<hkpPhantom*>* output)
{
    const int wheelCount = m_kWheelStates.GetLogicalSize();
    for (int wheel = 0; wheel < wheelCount; ++wheel)
    {
        hkpPhantom* phantom = m_kWheelStates[wheel].m_pPhantom;
        HavokAllocatorContext_hkpvehiclelinearcastwheelcollide* memory = hkMemoryRouter_getInstance();
        if (output->m_iElementCount == (output->m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(memory->m_router, output, sizeof(phantom));
        hkpPhantom** slot = output->m_data + output->m_iElementCount;
        __assume(slot != 0);
        new (slot) hkpPhantom*(phantom);
        ++output->m_iElementCount;
    }
}
