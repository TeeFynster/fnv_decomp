#include "../../include/hkArray.h"

// src/staging/blk_00d40000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkThreadMemory.h"
#include "../../include/hkVector4.h"

#include "../../include/hkQuaternion.h"
#include "../../include/hkpCollisionDispatcher.h"

// These operations are inlined by this unit in the original game.


inline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}

inline hkMemoryAllocator& hkThreadMemory::heap()
{
    return *reinterpret_cast<hkMemoryAllocator*>(m_pMemoryAllocator);
}

void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

template <class T> __forceinline void D51ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <class T>
static __forceinline void D51Array_AddBack(hkArrayBase<T>& self, const T& t);

template <class T>
static __forceinline void D51Array_AddBack(hkArrayBase<T>& self, const T& t)
{
        hkThreadMemory* mem = hkThreadMemory::GetMonitorStream();
        if (self.m_iElementCount == self.getCapacity())
        {
            ResizeAudioStream(mem->m_pMemoryAllocator, (&self), sizeof(T));
        }
        D51ConstructWithCopy(self.m_data + self.m_iElementCount, 1, t);
        self.m_iElementCount++;
    }

struct D51Stream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkArrayBase<hkVector4> m_kShapeVectorData;
    hkArrayBase<int> m_commands;
};

struct D51Input
{
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    hkVector4 m_iThirdValue;
};

struct D51Writer
{
    int unk00;
    D51Stream* m_stream;
    int unk08;
    int unk0c;
    int unk10;
    short unk14;
    bool m_bValueAt0C;

    int UpdateState_00d51c30(const D51Input& input);
};

// @fnv 0x00d51c30
// src: GUESS 0x00d51c30 (confidence: low)
int D51Writer::UpdateState_00d51c30(const D51Input& input)
{
    D51Array_AddBack(m_stream->m_commands, 8);
    int index = m_stream->m_kShapeVectorData.GetLogicalSize();
    D51Array_AddBack(m_stream->m_kShapeVectorData, input.m_kPointA);
    D51Array_AddBack(m_stream->m_kShapeVectorData, input.m_kPointB);
    D51Array_AddBack(m_stream->m_kShapeVectorData, input.m_iThirdValue);
    m_bValueAt0C = true;
    return index;
}

namespace fnv_00d52640 {

void ResizeAudioStream(void* allocator, void* array, int elemSize);

template <typename T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

}  // namespace fnv_00d52640

// hkArray<T>::pushBack: _pushBack through hkContainerHeapAllocator (hkThreadMemory's heap here).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkThreadMemory::GetMonitorStream()->heap();
}
template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& allocator, const T& t)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
    {
        fnv_00d52640::ResizeAudioStream(&allocator, this, sizeof(T));
    }
    fnv_00d52640::hkConstructWithCopy(m_data + m_iElementCount, 1, t);
    m_iElementCount++;
}

namespace fnv_00d52640 {

struct S00d52640_Writer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkArray<hkVector4> m_kShapeVectorData;
    hkArray<int> m_commands;
    int unk28;
    int unk2c;
    int unk30;
    hkArray<const hkReferencedObject*> m_kTrackedObjects;
};

struct FUN_00d52640_c
{
    int unk00;
    S00d52640_Writer* m_pStreamWriter;
    int ProcessAndReturnValue_00d52640(bool flag, const hkReferencedObject* object);
};

// @fnv 0x00d52640
// src: GUESS 0x00d52640 (confidence: low)
int FUN_00d52640_c::ProcessAndReturnValue_00d52640(bool flag, const hkReferencedObject* object)
{
    // A leading assembly label suppresses MSVC /GS parameter copies for the shared vector's union.
    // It emits no instructions and preserves the original stack layout.
    __asm { vector_start: }
    m_pStreamWriter->m_commands.pushBack(0xe);
    m_pStreamWriter->m_commands.pushBack(flag);

    int index = m_pStreamWriter->m_kShapeVectorData.m_iElementCount;
    hkVector4 v;
    v.set((float)m_pStreamWriter->m_kTrackedObjects.m_iElementCount, 0.0f, 0.0f, 0.0f);
    object->addReference();
    m_pStreamWriter->m_kShapeVectorData.pushBack(v);
    m_pStreamWriter->m_kTrackedObjects.pushBack(object);

    S00d52640_Writer* writer = m_pStreamWriter;
    writer->unk08 += 1;
    writer->unk04 += 0x40;
    writer->unk0c += 3;
    return index;
}
}  // namespace fnv_00d52640

namespace fnv_00d56470 {

extern const __m128 DAT_01017d10;
static const float DAT_01017d00 = 0.001f;

// The shared vector has no equals3 member; preserve the three-lane comparison here.
inline bool equals3(const hkVector4& a, const hkVector4& b, float fEpsilon)
{
    const __m128 kDiff = _mm_and_ps(_mm_sub_ps(a.m_vComponents, b.m_vComponents), DAT_01017d10);
    const __m128 kEps = _mm_load_ps1(&fEpsilon);
    return (_mm_movemask_ps(_mm_cmple_ps(kDiff, kEps)) & 7) == 7;
}

extern hkVector4 DAT_01267e30;

struct FUN_00d56470_cls
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkQuaternion m_rotation;
    hkVector4 m_vTranslation;

    FUN_00d56470_cls* hkpExtendedMeshShape_ShapesSubpart_ShapesSubpart(int bCompute);
};

// @fnv 0x00d56470
// src: XBOX_PDB 0x00d56470
FUN_00d56470_cls* FUN_00d56470_cls::hkpExtendedMeshShape_ShapesSubpart_ShapesSubpart(int bCompute)
{
    if (bCompute)
    {
        const int iTranslated = !equals3(m_vTranslation, DAT_01267e30, DAT_01017d00);
        const int iRotated = (m_rotation.GetAngle() < DAT_01017d00) ? 0 : 2;
        reinterpret_cast<int*>(&m_vTranslation)[3] = iRotated | iTranslated | 0x3f000000;
    }
    return this;
}
}  // namespace fnv_00d56470

// The original registration helper inlines this shared table's default initialization.
inline hkpCollisionDispatcher::Agent3FunctionTable::Agent3FunctionTable()
{
    m_bIsPredictive = false;
    m_bAgentFlag1 = false;
    m_bAgentFlag2 = false;
    m_pUpdateFilterFunc = 0;
    m_pCalcStats = 0;
    m_pAgentFunction10 = 0;
    m_pAgentFunction11 = 0;
    m_pAgentFunction7 = 0;
}

void __cdecl hkBoxBoxAgent3_initAgentFunc(void* buf);

// @fnv 0x00d40130
// src: HAVOK_LIB 0x00d40130
void __cdecl hkBoxBoxAgent3_registerAgent3(hkpCollisionDispatcher* self)
{
    hkpCollisionDispatcher::Agent3FunctionTable kFuncs;
    hkBoxBoxAgent3_initAgentFunc(&kFuncs);
    self->AddEntry(&kFuncs, 4, 4);
}

struct Handle_d49550
{
    int m_v;
};
struct __declspec(align(16)) FUN_00c9ce00
{
    FUN_00c9ce00(Handle_d49550 kHandle);
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
};
extern int DAT_010c7888;
// @fnv 0x00d49550
// src: HAVOK_LIB 0x00d49550
int* __cdecl getVtablehkpRigidBody()
{
    Handle_d49550 kHandle = {0};
    FUN_00c9ce00 kObject(kHandle);
    return &DAT_010c7888;
}

class __declspec(align(16)) S00d4b1a0_Object
{
  public:
    S00d4b1a0_Object(FinishingFlag flag);  // FUN_00d4a170
    void* m_ppVirtualMethodTable;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4b1a0
// src: GUESS 0x00d4b1a0 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00d4b1a0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4b1a0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct W_00d49c40
{
    int x;
};

struct __declspec(align(16)) S_00d49c40
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

    void SetVirtualTable_00d49c40(W_00d49c40 w);
};

// @fnv 0x00d4b200
// src: GUESS 0x00d4b200 (confidence: low)
int Object_ProcessAndReturnValue_00d4b200()
{
    S_00d49c40 obj;
    obj.SetVirtualTable_00d49c40(W_00d49c40());
    return obj.unk00;
}

struct W_d4a180
{
    int x;
};

struct __declspec(align(16)) SpawnedObject
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108;
    void FUN_00d4a180(W_d4a180 w);
};

// @fnv 0x00d4b260
// src: HAVOK_LIB 0x00d4b260
int getVtablehkpStorageExtendedMeshShape()
{
    SpawnedObject obj;
    obj.FUN_00d4a180(W_d4a180());
    return obj.unk000;
}

struct ZeroD4B
{
    int v;
};

struct __declspec(align(16)) HolderD4B
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;

    void FUN_00d56f10(ZeroD4B arg);
};

// @fnv 0x00d4b330
// src: GUESS 0x00d4b330 (confidence: low)
int Runtime_UpdateState_00d4b330()
{
    HolderD4B holder;
    ZeroD4B z = {0};
    holder.FUN_00d56f10(z);
    return *(int*)&holder.unk00;
}

namespace fnv_00d4be60 {
class __declspec(align(16)) S00d4be60_Object
{
  public:
    S00d4be60_Object(FinishingFlag flag);  // FUN_00d4b3b0
    virtual void vf00();
    int m_kNextStreamField[19];
};

// @fnv 0x00d4be60
// src: GUESS 0x00d4be60 (confidence: low)
const void* __cdecl Object_ProcessAndReturnValue_00d4be60()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4be60_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}
}  // namespace fnv_00d4be60

namespace fnv_00d4bec0 {
class __declspec(align(16)) S00d4bec0_Object
{
  public:
    S00d4bec0_Object(FinishingFlag flag);  // FUN_00d4ba30
    void* m_ppVirtualMethodTable;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4bec0
// src: GUESS 0x00d4bec0 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00d4bec0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4bec0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}
}  // namespace fnv_00d4bec0

namespace fnv_00d4bf40 {
class __declspec(align(16)) S00d4bf40_Object
{
  public:
    S00d4bf40_Object(FinishingFlag flag);  // FUN_00dcd380
    void* m_ppVirtualMethodTable;
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4bf40
// src: GUESS 0x00d4bf40 (confidence: medium)
const void* __cdecl Object_GetConstructedVirtualTable_00d4bf40()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4bf40_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}
}  // namespace fnv_00d4bf40

struct FnvCpu_FUN_00d4f7f0_CpuData0
{
    __m128 field00;
    __m128 field10;
    __m128 field20;
};
struct FnvCpu_FUN_00d4f7f0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    void UpdateState_00d4f7f0(FnvCpu_FUN_00d4f7f0_CpuData0* input0);
};
// @fnv 0x00d4f7f0
// src: GUESS 0x00d4f7f0 (confidence: low)
void FnvCpu_FUN_00d4f7f0_CpuObject::UpdateState_00d4f7f0(FnvCpu_FUN_00d4f7f0_CpuData0* input0)
{
    input0->field00 = this->field20;
    input0->field10 = this->field30;
    input0->field20 = this->field40;
}

struct FnvCpu_FUN_00d4f820_CpuData0
{
    __m128 field00;
    __m128 field10;
    __m128 field20;
};
struct FnvCpu_FUN_00d4f820_CpuObject
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
    __m128 field50;
    __m128 field60;
    __m128 field70;
    void UpdateFields_00d4f820(FnvCpu_FUN_00d4f820_CpuData0* input0);
};
// @fnv 0x00d4f820
// src: GUESS 0x00d4f820 (confidence: low)
void FnvCpu_FUN_00d4f820_CpuObject::UpdateFields_00d4f820(FnvCpu_FUN_00d4f820_CpuData0* input0)
{
    input0->field00 = this->field50;
    input0->field10 = this->field60;
    input0->field20 = this->field70;
}

namespace fnv_00d51890 {
void ResizeAudioStream(void* alloc, void* array, int elemSize);

template <typename T> inline void D51ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
static __forceinline void HkArrD51_AddBack(hkArrayBase<T>& self, const T& t);

template <class T>
static __forceinline void HkArrD51_AddBack(hkArrayBase<T>& self, const T& t)
{
        hkThreadMemory* r = hkThreadMemory::GetMonitorStream();
        if (self.m_iElementCount == self.getCapacity())
            fnv_00d51890::ResizeAudioStream(r->m_pMemoryAllocator, (&self), sizeof(T));
        fnv_00d51890::D51ConstructWithCopy<T>(self.m_data + self.m_iElementCount, 1, t);
        self.m_iElementCount++;
    }

struct HkCoreD51
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArrayBase<hkVector4> m_vecs;
    hkArrayBase<int> m_auiHeaderValues;
};

struct HkOwnerD51
{
    int unk00;
    HkCoreD51* m_core;
    int unk08;
    int unk0C;
    unsigned char m_flags[4];

    int UpdateState_00d51890(const hkVector4& v, int index);
};

// @fnv 0x00d51890
// src: GUESS 0x00d51890 (confidence: low)
int HkOwnerD51::UpdateState_00d51890(const hkVector4& v, int index)
{
    HkArrD51_AddBack(m_core->m_auiHeaderValues, 3);
    HkArrD51_AddBack(m_core->m_auiHeaderValues, index);
    int result = m_core->m_vecs.m_iElementCount;
    HkArrD51_AddBack(m_core->m_vecs, v);
    m_flags[index] = 1;
    return result;
}
}  // namespace fnv_00d51890

namespace fnv_00d51d40 {

void __cdecl ResizeAudioStream(void* allocator, void* array, unsigned int stride);
template <typename T> inline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct VectorArray
{
    __m128* elements;
    unsigned int count;
    unsigned int capacityFlags;
};
struct IndexArray
{
    unsigned int* elements;
    unsigned int count;
    unsigned int capacityFlags;
};
struct GeometryArrays
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    VectorArray vertices;
    IndexArray indices;
};
struct GeometryBuilder
{
    unsigned int unknown00;
    GeometryArrays* arrays;
    unsigned int state08;
    unsigned int state0c;
    unsigned int state10;
    unsigned char status14;
    unsigned char status15;
    unsigned char status16;
    bool updated;
    unsigned int ProcessAndReturnValue_00d51d40(const __m128* vectors);
};
// @fnv 0x00d51d40
// src: GUESS 0x00d51d40 (confidence: low)
unsigned int GeometryBuilder::ProcessAndReturnValue_00d51d40(const __m128* vectors)
{
    IndexArray* indexBuffer = &arrays->indices;
    hkThreadMemory* heap = hkThreadMemory::GetMonitorStream();
    if (indexBuffer->count == (indexBuffer->capacityFlags & 0x3fffffff))
        fnv_00d51d40::ResizeAudioStream(heap->m_pMemoryAllocator, indexBuffer, 4);
    hkConstructWithCopy(indexBuffer->elements + indexBuffer->count, 1, 9u);
    ++indexBuffer->count;

    unsigned int previousCount = arrays->vertices.count;
    VectorArray* positions = &arrays->vertices;
    heap = hkThreadMemory::GetMonitorStream();
    if (positions->count == (positions->capacityFlags & 0x3fffffff))
        fnv_00d51d40::ResizeAudioStream(heap->m_pMemoryAllocator, positions, 16);
    positions->elements[positions->count] = vectors[0];
    ++positions->count;

    positions = &arrays->vertices;
    heap = hkThreadMemory::GetMonitorStream();
    if (positions->count == (positions->capacityFlags & 0x3fffffff))
        fnv_00d51d40::ResizeAudioStream(heap->m_pMemoryAllocator, positions, 16);
    positions->elements[positions->count] = vectors[1];
    ++positions->count;

    positions = &arrays->vertices;
    heap = hkThreadMemory::GetMonitorStream();
    if (positions->count == (positions->capacityFlags & 0x3fffffff))
        fnv_00d51d40::ResizeAudioStream(heap->m_pMemoryAllocator, positions, 16);
    positions->elements[positions->count] = vectors[2];
    ++positions->count;

    updated = true;
    return previousCount;
}
}  // namespace fnv_00d51d40

namespace fnv_00d52000 {
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);
template <typename T> inline void D52ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
static __forceinline void ArrayD52_AddBack(hkArrayBase<T>& self, const T& val);

template <class T>
static __forceinline void ArrayD52_AddBack(hkArrayBase<T>& self, const T& val)
{
        hkThreadMemory& router = *hkThreadMemory::GetMonitorStream();
        if (self.m_iElementCount == self.getCapacity())
            fnv_00d52000::ResizeAudioStream(router.m_pMemoryAllocator, (&self), sizeof(T));
        D52ConstructWithCopy<T>(self.m_data + self.m_iElementCount, 1, val);
        self.m_iElementCount++;
    }
struct OwnerD52
{
    int unk00, unk04, unk08, unk0c;
    hkArrayBase<hkVector4> m_vecs;
    hkArrayBase<int> m_auiHeaderValues;
};
struct D52Class
{
    int unk00;
    OwnerD52* m_pOwnerObject;
    int unk08, unk0c, unk10, unk14;
    bool m_dirty;
    int ProcessAndReturnValue_00d52000(const hkVector4& v);
};
// @fnv 0x00d52000
// src: GUESS 0x00d52000 (confidence: low)
int D52Class::ProcessAndReturnValue_00d52000(const hkVector4& v)
{
    ArrayD52_AddBack(m_pOwnerObject->m_auiHeaderValues, 1);
    int index = m_pOwnerObject->m_vecs.GetLogicalSize();
    ArrayD52_AddBack(m_pOwnerObject->m_vecs, v);
    m_dirty = true;
    return index;
}
}  // namespace fnv_00d52000

static const float DAT_01011d78 = 0.0f;
template <typename T> inline void D529E0_ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <class T>
static __forceinline void D529E0_Array_AddBack(hkArrayBase<T>& self, const T& value);

template <class T>
static __forceinline void D529E0_Array_AddBack(hkArrayBase<T>& self, const T& value)
{
        hkThreadMemory* router = hkThreadMemory::GetMonitorStream();
        if (self.m_iElementCount == (self.m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pMemoryAllocator, (&self), sizeof(T));
        D529E0_ConstructWithCopy<T>(self.m_data + self.m_iElementCount, 1, value);
        self.m_iElementCount++;
    }
struct D529E0_Batch
{
    int unk00;
    int m_04;
    int m_08;
    int m_0C;
    hkArrayBase<__m128> m_kShapeVectorData;
    hkArrayBase<int> m_commands;
};
struct D529E0_Builder
{
    int unk00;
    D529E0_Batch* m_batch;
    int ProcessAndReturnValue_00d529e0(unsigned char a1, float a2);
};
// @fnv 0x00d529e0
// src: GUESS 0x00d529e0 (confidence: low)
int D529E0_Builder::ProcessAndReturnValue_00d529e0(unsigned char a1, float a2)
{
    D51Array_AddBack(m_batch->m_commands, 0x15);
    D529E0_Array_AddBack<int>(m_batch->m_commands, a1);
    __m128 v = _mm_setr_ps(a2, DAT_01011d78, DAT_01011d78, DAT_01011d78);
    int index = m_batch->m_kShapeVectorData.m_iElementCount;
    D51Array_AddBack(m_batch->m_kShapeVectorData, v);
    D529E0_Batch* batch = m_batch;
    batch->m_04 += 0x40;
    batch->m_08 += 1;
    batch->m_0C += 2;
    return index;
}

__forceinline void hkVector4::normalize3()
{
    __m128 vector = quad;
    __m128 squared = _mm_mul_ps(vector, vector);
    __m128 length = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
    length = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), length);
    __m128 estimate = _mm_rsqrt_ss(length);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, estimate), estimate));
    __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(length, _mm_set_ss(0.0f)), inverse);
    __m128 result = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), vector);

    quad = result;
}

__forceinline void hkVector4::setCross(const hkVector4& l, const hkVector4& r)
{
    __m128 left = l.quad, right = r.quad;
    quad = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(left, left, 0xc9), _mm_shuffle_ps(right, right, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(left, left, 0xd2), _mm_shuffle_ps(right, right, 0xc9)));
}

static __forceinline __m128 crossVector(__m128 left, __m128 right)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(left, left, 0xc9), _mm_shuffle_ps(right, right, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(left, left, 0xd2), _mm_shuffle_ps(right, right, 0xc9)));
}
struct BasisPair
{
    hkVector4 unk00;
    hkVector4 unk10;
    hkVector4 axisA;
    hkVector4 axisB;
    hkVector4 normalA;
    hkVector4 axisC;
    hkVector4 axisD;
    hkVector4 normalB;
    const hkVector4* ProcessAndReturnValue_00d52ce0(const hkVector4* a, const hkVector4* c, const hkVector4* b, const hkVector4* d);
};
// @fnv 0x00d52ce0
// src: GUESS 0x00d52ce0 (confidence: low)
const hkVector4* BasisPair::ProcessAndReturnValue_00d52ce0(const hkVector4* a, const hkVector4* c, const hkVector4* b, const hkVector4* d)
{
    axisA = *a;
    axisA.normalize3();
    axisB = *b;
    axisB.normalize3();
    normalA.setCross(*a, *b);
    axisC = *c;
    axisC.normalize3();
    axisD = *d;
    axisD.normalize3();
    normalB.quad = crossVector(c->quad, d->quad);
    return c;
}

extern "C"
{
    double __cdecl fabs(double);
}

struct Row172
{
    float x, y, z, w;
    void hkVector4_setRotatedInverseDir(int index, const hkVector4* value);
};
struct Frame172
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Row172 row20, row30, row40, row50, row60, row70;
    void UpdateFields_00d53060(int first, int second, const hkVector4* direction);
};
static __forceinline float Absolute172(float value)
{
    volatile float result = static_cast<float>(fabs(static_cast<double>(value)));
    return result;
}
static __forceinline __m128 Normalize172(__m128 vector)
{
    __m128 squares = _mm_mul_ps(vector, vector);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
    __m128 length2 = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), sum);
    __m128 estimate = _mm_rsqrt_ss(length2);
    __m128 error = _mm_mul_ss(_mm_mul_ss(length2, estimate), estimate);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), error);
    __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
    __m128 zeroMask = _mm_cmpeq_ss(length2, _mm_set_ss(0.0f));
    inverse = _mm_andnot_ps(zeroMask, inverse);
    return _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), vector);
}
// @fnv 0x00d53060
// src: GUESS 0x00d53060 (confidence: low)
void Frame172::UpdateFields_00d53060(int first, int second, const hkVector4* direction)
{
    float ax = Absolute172(direction->m_f[0]);
    float ay = Absolute172(direction->m_f[1]);
    float az = Absolute172(direction->m_f[2]);
    int other = 0;
    int i = other + 1, j = other + 2;
    if (ay < ax)
    {
        ax = ay;
        i = 0;
        other = 1;
    }
    if (az < ax)
        j = other;
    hkVector4 perpendicular;
    perpendicular.quad = _mm_setzero_ps();
    perpendicular.m_f[i] = direction->m_f[j];
    perpendicular.m_f[j] = -direction->m_f[i];
    perpendicular.quad = Normalize172(perpendicular.quad);
    __m128 p = perpendicular.quad;
    __m128 d = direction->quad;
    hkVector4 cross;
    __m128 left = _mm_mul_ps(_mm_shuffle_ps(d, d, 0xc9), _mm_shuffle_ps(p, p, 0xd2));
    __m128 right = _mm_mul_ps(_mm_shuffle_ps(d, d, 0xd2), _mm_shuffle_ps(p, p, 0xc9));
    cross.quad = _mm_sub_ps(left, right);
    row20.hkVector4_setRotatedInverseDir(first, direction);
    row30.hkVector4_setRotatedInverseDir(first, &perpendicular);
    row40.hkVector4_setRotatedInverseDir(first, &cross);
    row50.hkVector4_setRotatedInverseDir(second, direction);
    row60.hkVector4_setRotatedInverseDir(second, &perpendicular);
    row70.hkVector4_setRotatedInverseDir(second, &cross);
}

__forceinline __m128 normalize3(const __m128& v)
{
    __m128 square = _mm_mul_ps(v, v);
    __m128 y = _mm_shuffle_ps(square, square, 0x55);
    y = _mm_add_ss(y, square);
    square = _mm_shuffle_ps(square, square, 0xaa);
    square = _mm_add_ss(square, y);
    __m128 reciprocal = _mm_rsqrt_ss(square);
    __m128 correction = _mm_mul_ss(square, reciprocal);
    correction = _mm_mul_ss(correction, reciprocal);
    correction = _mm_sub_ss(_mm_set_ss(3.0f), correction);
    __m128 factor = _mm_mul_ss(_mm_set_ss(0.5f), reciprocal);
    factor = _mm_mul_ss(factor, correction);
    __m128 mask = _mm_cmpeq_ss(square, _mm_set_ss(0.0f));
    factor = _mm_andnot_ps(mask, factor);
    factor = _mm_shuffle_ps(factor, factor, 0);
    return _mm_mul_ps(factor, v);
}
__forceinline __m128 cross3(const __m128& a, const __m128& b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
}
// Reuse the current source's vector layout and basis storage without redefining either.
struct BasisPairSetup : BasisPair
{
    const __m128& UpdateState_00d4f5d0(const __m128&, const __m128&, const __m128&, const __m128&);
};
// @fnv 0x00d4f5d0
// src: GUESS 0x00d4f5d0 (confidence: low)
const __m128& BasisPairSetup::UpdateState_00d4f5d0(const __m128& referenceA, const __m128& referenceB, const __m128& inputAxisA,
                                           const __m128& inputAxisB)
{
    axisA.quad = normalize3(inputAxisA);
    axisB.quad = referenceA;
    axisB.quad = normalize3(axisB.quad);
    normalA.quad = cross3(axisA.quad, axisB.quad);
    axisC.quad = normalize3(inputAxisB);
    axisD.quad = referenceB;
    axisD.quad = normalize3(axisD.quad);
    normalB.quad = cross3(axisC.quad, axisD.quad);
    return inputAxisB;
}

namespace WorldLinearDof {

struct Writer
{
    unsigned int unk00;
    D51Stream* m_stream;
    unsigned int unk08, unk0c;
    unsigned char m_specifiedA[3];
    unsigned char m_specifiedB[3];

    int UpdateState_00d51a50(const hkVector4& direction, int axis);
};

// @fnv 0x00d51a50
// src: GUESS 0x00d51a50 (confidence: low)
int Writer::UpdateState_00d51a50(const hkVector4& direction, int axis)
{
    D51Array_AddBack(m_stream->m_commands, 5);
    D51Array_AddBack(m_stream->m_commands, axis);
    int index = m_stream->m_kShapeVectorData.GetLogicalSize();
    D51Array_AddBack(m_stream->m_kShapeVectorData, direction);
    m_specifiedA[axis] = 1;
    m_specifiedB[axis] = 1;
    return index;
}

}

struct PivotBWriter
{
    int unk00;
    D51Stream* m_stream;
    int unk08, unk0c, unk10, unk14;
    unsigned char m_pivotASet;
    bool m_pivotBSet;

    int ProcessAndReturnValue_00d520a0(const hkVector4& pivot);
};

// @fnv 0x00d520a0
// src: GUESS 0x00d520a0 (confidence: low)
int PivotBWriter::ProcessAndReturnValue_00d520a0(const hkVector4& pivot)
{
    D51Array_AddBack(m_stream->m_commands, 2);
    int index = m_stream->m_kShapeVectorData.GetLogicalSize();
    D51Array_AddBack(m_stream->m_kShapeVectorData, pivot);
    m_pivotBSet = true;
    return index;
}
