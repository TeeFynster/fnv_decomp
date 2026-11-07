
// src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../../../include/hkAabb.h"
#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkpBvTreeShape.h"
#include "../../../../../../../../include/hkpMoppCode.h"
#include "../../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../../include/hkpSingleShapeContainer.h"
#include "../../../../../../../../include/hkMoppBvTreeShapeBase.h"
#include "../../../../../../../../include/hkpMoppBvTreeShape.h"
#include "../../../../../../../../include/hkpCdBody.h"

__forceinline hkAabb::hkAabb() {}
__forceinline const float& hkVector4::operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
inline const __m128& hkVector4::getQuad() const { return m_vComponents; }
inline __m128& hkVector4::getQuad() { return m_vComponents; }



// @fnv 0x00d54420
void hkpMoppBvTreeShape::CalculateAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const
{
    m_pChildAtom.m_pContainedShape->CalculateAabb(transform, tolerance, out);
}

extern int DAT_010c6fd0;
extern int DAT_010d0dac;

// The shared headers have no constructor declarations. These initializers take the real objects;
// the unused EDX parameter preserves the original ECX-this, stack-argument calling convention.
// Keep the base initializer and tree destructor out of line, as called by the original constructors/deleters.
__declspec(noinline) hkMoppBvTreeShapeBase* __fastcall InitializeMoppBase(hkMoppBvTreeShapeBase* self, void*, int type, const hkpMoppCode& code);

// @fnv 0x00d544f0
hkpMoppBvTreeShape* __fastcall InitializeMoppTree(hkpMoppBvTreeShape* self, void*, hkpShape* child, const hkpMoppCode& code)
{
    typedef hkMoppBvTreeShapeBase* (__thiscall* BaseInitializer)(hkMoppBvTreeShapeBase*, int, const hkpMoppCode&);
    reinterpret_cast<BaseInitializer>(&InitializeMoppBase)(self, 10, code);
    *reinterpret_cast<int**>(self) = &DAT_010d0dac;
    *reinterpret_cast<int**>(&self->m_pChildAtom) = &DAT_010c6fd0;
    self->m_pChildAtom.m_pContainedShape = child;

    child->addReference();
    return self;
}

hkMemoryRouter* _D1A0E0GetMemoryRouter();

// @fnv 0x00d54930
hkpMoppBvTreeShape* __fastcall DeleteMoppTree(hkpMoppBvTreeShape* self, void*, unsigned char flags)
{
    self->hkpMoppBvTreeShape::~hkpMoppBvTreeShape();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(self, self->m_usMemSizeAndFlags);
    }

    return self;
}

extern const hkClass DAT_01269c8c;

// @fnv 0x00d54300
void hkpMoppBvTreeShape::calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const throw()
{
    collector->beginObject("Mesh", m_pChildAtom.m_pContainedShape, 0);
    collector->beginObject("Mopp", m_pMoppCode, 0);
    hkReferencedObject::calcContentStatistics(collector, &DAT_01269c8c);
}

struct __declspec(align(16)) FUN_00dd1bf0_Obj
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;

    void __thiscall hkpMoppObbVirtualMachine_queryObb(const hkpMoppCode* code, const hkTransform& transform,
                                const hkVector4& extent, hkReal tolerance, hkArray<hkpShapeKey>& hits);
};

// @fnv 0x00d54350
void hkpMoppBvTreeShape::GetObbHits(const hkTransform& transform, const hkVector4& extent,
                                  hkReal tolerance, hkArray<hkpShapeKey>& hits) const
{
    FUN_00dd1bf0_Obj local;
    local.hkpMoppObbVirtualMachine_queryObb(m_pMoppCode, transform, extent, tolerance, hits);
}

inline hkpShapeContainer::~hkpShapeContainer() {}
inline hkpSingleShapeContainer::~hkpSingleShapeContainer()
{
    if (m_pContainedShape)
        const_cast<hkpShape*>(m_pContainedShape)->removeReference();
}

inline hkMoppBvTreeShapeBase::~hkMoppBvTreeShapeBase() throw()
{
    const_cast<hkpMoppCode*>(m_pMoppCode)->removeReference();
}

// ~hkpMoppBvTreeShape (0x00d543e0) is in hkpmoppbvtreeshape_gs_ehsc_nogs_noehsc_variant.cpp: Havok was built without
// exceptions, and the original destructor has no EH frame around its removeReference() calls.

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

inline hkMemoryAllocator& GetHeapAllocator(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}

inline void hkReferencedObject::operator delete(void* p)
{
    GetHeapAllocator(hkMemoryRouter_getInstance()).blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

// @fnv 0x00d548f0
hkMoppBvTreeShapeBase* __fastcall DeleteMoppBase(hkMoppBvTreeShapeBase* self, void*, unsigned int flags) throw()
{
    self->hkMoppBvTreeShapeBase::~hkMoppBvTreeShapeBase();
    if (flags & 1)
        hkMoppBvTreeShapeBase::operator delete(self);
    return self;
}

// @fnv 0x00d54440
int hkpMoppBvTreeShape::CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const
{
    unsigned char c = reinterpret_cast<const volatile unsigned char&>(m_pMoppCode->m_eBuildType);

    if (c != 0 && c != 1)
        return -1;
    try
    {
        if (c == 1)
            return -1;
    }
    catch (...)
    {
        throw;
    }

    int result = m_pChildAtom.m_pContainedShape->CalcSizeForSpu(input, 0x100);
    if (result < 0)
        return -1;
    if (result > 0x100)
        return -1;

    m_iChildSize = result;
    return 0x40;
}

#include <xmmintrin.h>
extern char DAT_010d0d70;
// @fnv 0x00d54490
__declspec(noinline) hkMoppBvTreeShapeBase* __fastcall InitializeMoppBase(hkMoppBvTreeShapeBase* self, void*, int type, const hkpMoppCode& code)
{
    const hkpMoppCode* src = &code;
    reinterpret_cast<volatile short&>(self->m_sReferenceCount) = 1;
    reinterpret_cast<volatile hkUlong&>(self->m_ulUserData) = 0;
    reinterpret_cast<int&>(self->m_type) = type;
    reinterpret_cast<volatile unsigned char&>(self->m_uiUserData) = 0;
    *reinterpret_cast<void* volatile*>(self) = &DAT_010d0d70;
    self->m_pMoppCode = src;
    const_cast<hkpMoppCode*>(src)->addReference();
    self->m_kMoppCodeInfo.m_vComponents = src->m_info.m_offset.m_vComponents;
    self->m_pMoppData = src->m_data.m_data;
    self->m_uiMoppDataSize = src->m_data.m_iElementCount;
    return self;
}

// Same 0x50-byte ray output used by hkpShape::FUN_00c9e400: keys at +0x20, level at +0x40.
struct ShapeRayCastOutput
{
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_18;
    int m_1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    void changeLevel(int iDelta)
    {
        m_uiShapeKeyIndex += iDelta;
    }
    void setKey(unsigned int uiKey)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = uiKey;
    }
};

// hkpShape::FUN_00c9e400 uses the same four consecutive ray outputs.
struct ShapeRayCastOutputArray
{

    ShapeRayCastOutput m_akRayOutputs[4];
};

struct ShapeRayBundleCastInput;


namespace fnv_00d54520 {
// Exe 0x00d54380 FUN_00d54380: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern const char str_010d0de4[];
extern const char str_010c41f8[];

struct S54520_Timer
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_unk08;
};
struct __declspec(align(16)) S54520_Work
{
    LocalM128 m_kShapeVectorData[4];
    int m_z0;
    int m_z1;
    int t48;
    int t4c;
    int t50;
    int t54;
    int t58;
    int t5c;
    int t60;
    int t64;
    void UpdateState_00dd2df0(hkBool*, const hkpShapeContainer*, hkpMoppCode*, const ShapeRayCastQuery&, ShapeRayCastOutput*);
};
struct S54520_Frame
{
    unsigned int m_codeStorage[16];
    S54520_Work m_vm;
};
} // namespace fnv_00d54520

// Casts one ray through the MOPP code and records the root key when a child is hit.
// @fnv 0x00d54520
hkBool hkpMoppBvTreeShape::IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const
{
    using namespace fnv_00d54520;
    hkBool out;
    S54520_Frame frame;
    {
        hkMonitorStream* mon = (hkMonitorStream*)TlsGetValue(fnv_00d54520::DAT_0126835c);
        char* pos = mon->m_end.m_storage;
        if (pos < mon->m_capacityMinus16.m_storage)
        {
            volatile unsigned int ticks;
            S54520_Timer* t = (S54520_Timer*)pos;
            t->m_name = fnv_00d54520::str_010d0de4;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_end.m_storage = pos + sizeof(S54520_Timer);
        }
    }
    output.m_uiShapeKeyIndex++;
    hkpMoppCode& box = *(hkpMoppCode*)(((unsigned int)&frame.m_codeStorage[0] + 15) & ~15u);
    int size = m_uiMoppDataSize;
    box.m_info.m_offset.m_vComponents = m_kMoppCodeInfo.m_vComponents;
    box.m_data.m_data = m_pMoppData;
    box.m_data.m_iElementCount = size;
    box.m_data.m_iCapacityState = size;
    frame.m_vm.m_z0 = 0;
    frame.m_vm.m_z1 = 0;
    reinterpret_cast<signed char&>(box.m_eBuildType) = 2;
    frame.m_vm.UpdateState_00dd2df0(&out,
                          m_pChildAtom.m_pContainedShape ? static_cast<const hkpShapeContainer*>(static_cast<const hkpShapeCollection*>(m_pChildAtom.m_pContainedShape)) : 0,
                          &box, input, &output);
    output.m_uiShapeKeyIndex--;
    if (out.m_cBooleanValue)
        output.m_uiShapeKeys[output.m_uiShapeKeyIndex] = 0;
    {
        hkMonitorStream* mon = (hkMonitorStream*)TlsGetValue(fnv_00d54520::DAT_0126835c);
        char* pos = mon->m_end.m_storage;
        if (pos < mon->m_capacityMinus16.m_storage)
        {
            volatile unsigned int ticks;
            S54520_Timer* t = (S54520_Timer*)pos;
            t->m_name = fnv_00d54520::str_010c41f8;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_end.m_storage = pos + sizeof(S54520_Timer);
        }
    }
    return out;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const int DAT_010c92e0[4];

extern "C" const char str_010d0df0[];
extern "C" const char str_010c41f8[];

struct hkTimerCommandD546
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        m_uiStartTicks = uiTicks;
    }
};

inline hkMonitorStream& hkMonitorStream::getInstance() { return *reinterpret_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c)); }
// A unit-local view: the original inlines a differently shaped variant of this Havok accessor.
struct hkMonitorStream_hkpmoppbvtreeshape : hkMonitorStream { bool memoryAvailable() const; };
inline bool hkMonitorStream_hkpmoppbvtreeshape::memoryAvailable() const { return m_end.m_storage < m_capacityMinus16.m_storage; }
inline char* __cdecl hkMonitorStream::getEnd() { return m_end.m_storage; }
inline void __cdecl hkMonitorStream::setEnd(char* p) { m_end.m_storage = p; }

__forceinline void timerD546(const char* pcCommand)
{
    hkMonitorStream& kStream = hkMonitorStream::getInstance();
    if (static_cast<const hkMonitorStream_hkpmoppbvtreeshape&>(kStream).memoryAvailable())
    {
        hkTimerCommandD546* h = reinterpret_cast<hkTimerCommandD546*>(kStream.getEnd());
        h->m_pCommandName = pcCommand;
        h->setTime();
        kStream.setEnd((char*)(h + 1));
    }
}

// No shared Vector4Comparison header is available; hkpShape declares this SIMD mask type.
struct Vector4Comparison
{
    union
    {
        __m128 m_uiMask;
        unsigned int m_int[4];
        float m_float[4];
    };
    int anyIsSet(int iMask) const
    {
        return _mm_movemask_ps(m_uiMask) & iMask;
    }
};

// Retained locally: include/ has no hkpMoppRayBundleVirtualMachine header; its entry is dd4870.
struct hkpMoppRayBundleVirtualMachine
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
    int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c;
    int m_a0, m_a4, m_a8, m_ac, m_b0, m_b4, m_b8, m_bc;
    int m_c0, m_c4, m_c8, m_cc, m_d0, m_d4, m_d8, m_dc;
    Vector4Comparison UpdateState_00dd4870(const hkpShapeContainer* pkCollection, const hkpMoppCode* pkCode,
                                         const ShapeRayBundleCastInput& kInput,
                                         ShapeRayCastOutputArray& kResults,
                                         const Vector4Comparison& kRayMask) throw();
};

// Runs the MOPP ray-bundle virtual machine against the contained shape and returns the per-ray hit mask.
// @fnv 0x00d54610
// src: XBOX_PDB 0x00d54610
Vector4Comparison hkpMoppBvTreeShape::castRayBundleImpl(const ShapeRayBundleCastInput& kInput,
                                                             ShapeRayCastOutputArray& kResults,
                                                             const Vector4Comparison& kRayMask) const throw()
{
    timerD546(str_010d0df0);

    kResults.m_akRayOutputs[0].changeLevel(1);
    kResults.m_akRayOutputs[1].changeLevel(1);
    kResults.m_akRayOutputs[2].changeLevel(1);
    kResults.m_akRayOutputs[3].changeLevel(1);

    unsigned int auiCodeBuf[(sizeof(hkpMoppCode) + 16) / 4];
    hkpMoppCode* pkCode = (hkpMoppCode*)(((unsigned long)auiCodeBuf + 15) & ~15);
    int iMoppDataSize = m_uiMoppDataSize;
    pkCode->m_info.m_offset.m_vComponents = m_kMoppCodeInfo.m_vComponents;
    pkCode->m_data.m_data = m_pMoppData;
    pkCode->m_data.m_iElementCount = iMoppDataSize;
    pkCode->m_data.m_iCapacityState = iMoppDataSize;
    reinterpret_cast<signed char&>(pkCode->m_eBuildType) = 2;

    const hkpShapeContainer* pkContainer =
        m_pChildAtom.m_pContainedShape
            ? static_cast<const hkpShapeContainer*>(static_cast<const hkpShapeCollection*>(m_pChildAtom.m_pContainedShape))
            : (const hkpShapeContainer*)0;

    hkpMoppRayBundleVirtualMachine kVm;
    Vector4Comparison kRet = kVm.UpdateState_00dd4870(pkContainer, pkCode, kInput, kResults, kRayMask);

    for (int i = 0; i < 4; i++)
    {
        kResults.m_akRayOutputs[i].changeLevel(-1);
        if (kRet.anyIsSet(DAT_010c92e0[i]))
            kResults.m_akRayOutputs[i].setKey(0);
    }

    timerD546(str_010c41f8);
    return kRet;
}

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern void* DAT_00fdf044;
extern unsigned long DAT_0126835c;
extern "C" const char str_010c41f8[];
extern char str_010d0de4;
struct S00d54720_Record
{
    const char* name;
    unsigned int ticks;
    unsigned int unk08;
};

typedef hkMonitorStream*(__stdcall* S00d54720_GetFn)(unsigned long);
struct S00d54720_Body
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
};
struct S00d54720_CodeBuf
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
};
struct S00d54720_Vm
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    int unk40;
    int unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void hkpMoppLongRayVirtualMachine_queryLongRay(const void* code, const hkpMoppCode* info, const void* input, const S00d54720_Body* body,
                      void* collector);
};
struct S00d54720_Frame
{
    S00d54720_Body body;
    S00d54720_CodeBuf codePtrBuffer;
};

// Wraps a FUN_00dd2ed0 call in two timer records, passing the MOPP data and info, the contained shape's container, a0, a body built from cdBody, and collector.
// @fnv 0x00d54720
void hkpMoppBvTreeShape::CastRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                             hkpRayHitCollector& collector) const
{
    S00d54720_GetFn getMonitor = (S00d54720_GetFn)DAT_00fdf044;
    {
        hkMonitorStream* monitor = getMonitor(DAT_0126835c);
        S00d54720_Record* record = reinterpret_cast<S00d54720_Record*>(monitor->m_end.m_storage);
        if (record < reinterpret_cast<S00d54720_Record*>(monitor->m_capacityMinus16.m_storage))
        {
            record->name = &str_010d0de4;
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            record->ticks = ticks;
            monitor->m_end.m_storage = reinterpret_cast<char*>(record + 1);
        }
    }
    {
        S00d54720_Frame frame;
        S00d54720_Vm vm;

        frame.body.unk0c = (void*)&cdBody;
        vm.unk40 = 0;
        vm.unk44 = 0;
        frame.body.unk08 = const_cast<void*>(cdBody.m_pMotionState);
            hkpMoppCode* code = (hkpMoppCode*)(((unsigned int)&frame.codePtrBuffer + 15) & ~15U);
        int codeSize = m_uiMoppDataSize;
        code->m_info.m_offset.m_vComponents = m_kMoppCodeInfo.m_vComponents;
        code->m_data.m_data = reinterpret_cast<unsigned char*>(m_pMoppData);
        code->m_data.m_iElementCount = codeSize;
        code->m_data.m_iCapacityState = codeSize;
        reinterpret_cast<volatile signed char&>(code->m_eBuildType) = 2;
        frame.body.unk00 = const_cast<hkpShape*>(m_pChildAtom.m_pContainedShape);
        frame.body.unk04 = 0;
        vm.hkpMoppLongRayVirtualMachine_queryLongRay(m_pChildAtom.m_pContainedShape ? static_cast<const hkpShapeContainer*>(static_cast<const hkpShapeCollection*>(m_pChildAtom.m_pContainedShape)) : 0,
                       code, &input, &frame.body, &collector);
    }
    {
        hkMonitorStream* monitor = getMonitor(DAT_0126835c);
        S00d54720_Record* record = reinterpret_cast<S00d54720_Record*>(monitor->m_end.m_storage);
        if (record < reinterpret_cast<S00d54720_Record*>(monitor->m_capacityMinus16.m_storage))
        {
            record->name = str_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            record->ticks = ticks;
            monitor->m_end.m_storage = reinterpret_cast<char*>(record + 1);
        }
    }
}

#include <xmmintrin.h>
namespace fnv_00d54380 {

// Exe 0x00d54380 FUN_00d54380: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {

    struct

    {

        float x, y, z, w;

    };

} __m128, LocalM128;

extern "C" LocalM128 _mm_load_ps1(const float* p);

extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);

extern "C" LocalM128 _mm_max_ps(LocalM128 a, LocalM128 b);

extern "C" LocalM128 _mm_min_ps(LocalM128 a, LocalM128 b);

struct hkMoppObbVirtualMachineD543

{

    __declspec(noalias) void hkpMoppObbVirtualMachine_queryAabb(const hkpMoppCode* pkCode, const hkAabb& kAabb,

                                          hkArray<unsigned int>* pkHits);

    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;

    unsigned int unk30, unk34, unk38, unk3C;

};

} // namespace fnv_00d54380

// Clips kAabbIn against the MOPP code bounds and queries the BV-tree for hits into kHits.

// @fnv 0x00d54380

// src: XBOX_PDB 0x00d54380
void hkpMoppBvTreeShape::hkMoppBvTreeShapeBase_queryAabb(const hkAabb& kAabbIn, hkArray<unsigned int>& kHits) const

{

    hkAabb kAabb;
    typedef fnv_00d54380::LocalM128 BoundsQuad;
    const BoundsQuad& info = reinterpret_cast<const BoundsQuad&>(m_kMoppCodeInfo.m_vComponents);
    reinterpret_cast<BoundsQuad&>(kAabb.m_kMinimumCorner.m_vComponents) =
        fnv_00d54380::_mm_max_ps(info, reinterpret_cast<const BoundsQuad&>(kAabbIn.m_kMinimumCorner.m_vComponents));
    float scale = static_cast<float>(16777216.0 / reinterpret_cast<const float*>(&m_kMoppCodeInfo.m_vComponents)[3]);
    BoundsQuad maxPoint = fnv_00d54380::_mm_add_ps(fnv_00d54380::_mm_load_ps1(&scale), info);
    reinterpret_cast<BoundsQuad&>(kAabb.m_kMaximumCorner.m_vComponents) =
        fnv_00d54380::_mm_min_ps(maxPoint, reinterpret_cast<const BoundsQuad&>(kAabbIn.m_kMaximumCorner.m_vComponents));

    fnv_00d54380::hkMoppObbVirtualMachineD543 kQuery;

    kQuery.hkpMoppObbVirtualMachine_queryAabb(m_pMoppCode, kAabb, &kHits);

}


