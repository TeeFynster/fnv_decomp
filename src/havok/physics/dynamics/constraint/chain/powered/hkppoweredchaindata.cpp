
// src/havok/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/powered/hkppoweredchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpPoweredChainData.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryAllocator.h"








// @fnv 0x00e3b720
// src: HAVOK_LIB 0x00e3b720
void hkpPoweredChainData::getConstraintInfo_00e3b720(int* info) const
{
    info[4] = (int)&m_kBridgeAtoms;
    int zero = 0;
    info[2] = zero;
    info[3] = zero;
    info[0] = zero;
    info[1] = 0x10;
    info[5] = 0xc;
    int count = m_pConstraintInfo.m_iElementCount;
    int total = count * 3;
    int size = (count * 0x534 + 0x53) & 0xfffffff0;
    total = total * 2;
    size = size + 0x10;
    info[1] = size;
    info[2] = total;
    info[3] = total;
}

struct FUN_00e3b7d0_second
{
    int pad[7];
    unsigned char* data;
};

struct FUN_00e3b7d0_object
{
    int pad0[3];
    hkpPoweredChainData* first;
    int pad1[8];
    FUN_00e3b7d0_second* second;
};

// Clears a two-bit field at the given bit position in the byte at index within a 48-byte-strided block and sets it to 2.
// @fnv 0x00e3b7d0
// src: HAVOK_LIB 0x00e3b7d0
void hkpPoweredChainData_disableMotor(FUN_00e3b7d0_object* object, int index, int bit)
{
    int count = object->first->m_pConstraintInfo.m_iElementCount;
    FUN_00e3b7d0_second* second = object->second;
    unsigned char* data = second->data;
    data += count * 48;

    unsigned char mask = static_cast<unsigned char>(3 << (bit * 2));
    unsigned char value = static_cast<unsigned char>(2 << (bit * 2));
    data[index] = static_cast<unsigned char>((data[index] & ~mask) | value);
}

// @fnv 0x00e3b670
// src: GUESS 0x00e3b670 (confidence: high)
int hkpPoweredChainData::ReturnConstant_102()
{
    return 102;
}

class hkBaseE3B8 : public hkReferencedObject
{
  public:
    void* m_pOwnerObject;
    hkBaseE3B8() throw() : m_pOwnerObject(0)
    {}
};

struct FUN_00d21ce0_cls
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;

    FUN_00d21ce0_cls() throw()
    {
        m_type = 1;
    }
    void hkpBridgeConstraintAtom_init(void* owner) throw();
};

// The shared hkpPoweredChainData declares these methods, but its bridge member
// cannot be default-constructed: hkpBridgeConstraintAtom's implicit constructor
// calls the private hkpConstraintAtom default constructor (C2248). The chain base
// also lacks a FinishingFlag constructor.
// Keep only the constructor views until the shared construction support is usable.
class FUN_00e3b8f0 : public hkBaseE3B8
{
  public:
    FUN_00d21ce0_cls m_link;
    hkArray<void*> m_items;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    float m_3c;

    FUN_00e3b8f0() throw();
    virtual ~FUN_00e3b8f0() throw();
};

// Initializes the float members to default values and calls m_link.FUN_00d21ce0 with this as owner.
// @fnv 0x00e3b8f0
FUN_00e3b8f0::FUN_00e3b8f0() throw()
{
    m_24 = 0.6f;
    m_28 = 1.0f;
    m_2c = 1.1920929e-08f;
    m_30 = 1.0f;
    m_34 = 1.1920929e-08f;
    m_38 = 1.0f;
    m_3c = 0.1f;
    m_link.hkpBridgeConstraintAtom_init(this);
}

namespace fnv_00e3b960 {
struct FUN_00d21ce0_cls
{
    int unk00;
    int unk04;
    void* m_08;
    void hkpBridgeConstraintAtom_init(void* p) throw();
};

struct hkMemberE3B9 : public FUN_00d21ce0_cls
{
    hkMemberE3B9(FinishingFlag flag)
    {
        if (flag.m_bFinishing)
            hkpBridgeConstraintAtom_init(m_08);
    }
};

class FUN_00e3b960 : public hkReferencedObject
{
  public:
    int unk08;
    hkMemberE3B9 m_kMemberDescriptor;

    FUN_00e3b960(FinishingFlag flag);
    virtual ~FUN_00e3b960();
};

// @fnv 0x00e3b960
FUN_00e3b960::FUN_00e3b960(FinishingFlag flag) : hkReferencedObject(flag), m_kMemberDescriptor(flag)
{
    if (flag.m_bFinishing)
        m_kMemberDescriptor.hkpBridgeConstraintAtom_init(this);
}
}  // namespace fnv_00e3b960

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

inline void hkReferencedObject::operator delete(void* p)
{
    reinterpret_cast<hkMemoryAllocator&>(::hkMemoryRouter_getInstance().heap())
        .blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

inline hkpConstraintData::~hkpConstraintData() throw()
{}

// @fnv 0x00e3b770
// src: HAVOK_LIB 0x00e3b770
void hkpPoweredChainData::getRuntimeInfo_00e3b770(int unused, RuntimeInfo* result)
{
    int size = m_pConstraintInfo.m_iElementCount;
    int stride = size * 6;

    result->stride = stride;

    stride += size * 2;
    int aligned = (size + 3) & ~3;
    result->offset = aligned + stride * 8;
}

struct Motor
{
    void FUN_00c90510();
};
class hkpPoweredChainDataConstraintInfo
{
public:
    __m128 frameA;
    __m128 frameB;
    __m128 frameC;
    __m128 frameD;
    union
    {
        struct
        {
            Motor* motorA;
            Motor* motorB;
            Motor* motorC;
        };
        hkReferencedObject* m_apkObjects[3];
    };
    bool enabled;
};
extern void __cdecl ResizeAudioStream(void* allocator, hkArray<hkpPoweredChainDataConstraintInfo>* array, int elementSize);
extern const __m128 DAT_012683b0;
// Appends a constraint entry, storing frames and motor pointers, and retaining each motor.
// @fnv 0x00e3b850
// src: XBOX_PDB 0x00e3b850
void hkpPoweredChainData::addConstraintInfoInBodySpace(const __m128* apFrameA, const __m128* apFrameB, const __m128* apFrameC,
                                    Motor* motorA, Motor* motorB, Motor* motorC)
{
    hkArray<hkpPoweredChainDataConstraintInfo>* array = &m_pConstraintInfo;
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    if (array->m_iElementCount == (int)(array->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router->m_heap, array, sizeof(hkpPoweredChainDataConstraintInfo));
    hkpPoweredChainDataConstraintInfo& info = array->m_data[array->m_iElementCount++];
    info.frameA = *apFrameA;
    info.frameB = *apFrameB;
    info.frameC = *apFrameC;
    info.motorA = motorA;
    motorA->FUN_00c90510();
    info.motorB = motorB;
    motorB->FUN_00c90510();
    info.motorC = motorC;
    motorC->FUN_00c90510();
    info.enabled = false;
    info.frameD = DAT_012683b0;
}

struct S00e3b810_Out
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    float m_v;
};

struct S00e3b810_Src
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    float m_kPointA;
    float m_kPointB;
};

struct S00e3b810_Dst
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float m_h;
};

// @fnv 0x00e3b810
// src: HAVOK_LIB 0x00e3b810
static __declspec(noinline) void hk1dAngularVelocityMotorCommitJacobianInMotorInfo(const S00e3b810_Src* src, S00e3b810_Dst* d, S00e3b810_Out* out,
                                              const float* s)
{
    out->m_uiX = src->m_uiZ * s[1];
    out->m_uiY = src->m_w * s[1];
    out->m_uiZ = src->m_uiY;
    out->m_w = src->m_kPointA;
    out->m_v = src->m_kPointB;
    d->m_h = s[2] * src->m_uiX;
}

S00e3b810_Out* volatile g_S00e3b810_out;
const float* volatile g_S00e3b810_s;
const S00e3b810_Src* volatile g_S00e3b810_src;
S00e3b810_Dst* volatile g_S00e3b810_d;

void S00e3b810_Caller()
{
    hk1dAngularVelocityMotorCommitJacobianInMotorInfo(g_S00e3b810_src, g_S00e3b810_d, g_S00e3b810_out, g_S00e3b810_s);
}

// hkArray<T>::~hkArray() = clearAndDeallocate() on the heap allocator (slot 4 frees).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(::hkMemoryRouter_getInstance().heap());
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}

// Releases all retained motors, then frees the constraint-entry array.
// @fnv 0x00e3b9a0
hkpPoweredChainData::~hkpPoweredChainData() throw()
{
    for (int i = 0; i < m_pConstraintInfo.m_iElementCount; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_pConstraintInfo.m_data[i].m_apkObjects[j])
                m_pConstraintInfo.m_data[i].m_apkObjects[j]->removeReference();
        }
    }
}
