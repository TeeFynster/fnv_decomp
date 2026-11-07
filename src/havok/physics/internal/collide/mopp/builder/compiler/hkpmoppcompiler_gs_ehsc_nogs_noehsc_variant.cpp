// src/havok/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
// local form of hkVector4: 0x00dd4cb0 needs its original packet form (compiled function extent differs: 1106 vs 1088).


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
union __m128;
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class PacketCallLocal_00dd4cb0
{
public:
#if defined(FNV_FOURFLOATVECTOR_NO_SSE)
    union Components
    {
        float m128_f32[4];
        unsigned __int64 m128_u64[2];
        signed char m128_i8[16];
        short m128_i16[8];
        int m128_i32[4];
        __int64 m128_i64[2];
        unsigned char m128_u8[16];
        unsigned short m128_u16[8];
        unsigned int m128_u32[4];
    };
#else
    typedef __declspec(align(4)) __m128 Components;
#endif

    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        Components m_vComponents;
        Components m;
        float f[4];
        Components values;
        Components q;
        Components value;
        Components quad;
        float elements[4];
        float m_fComponents[4];
    };

    PacketCallLocal_00dd4cb0();
    PacketCallLocal_00dd4cb0(float x, float y, float z, float w);
    PacketCallLocal_00dd4cb0(const __m128& vector);

    PacketCallLocal_00dd4cb0* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(PacketCallLocal_00dd4cb0* vector);
    void __thiscall SetQuaternionComponentsFromVector(const PacketCallLocal_00dd4cb0* vector);
    PacketCallLocal_00dd4cb0& ComputeValue_00e531a0(int parameter);
    PacketCallLocal_00dd4cb0 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const PacketCallLocal_00dd4cb0& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const PacketCallLocal_00dd4cb0& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const PacketCallLocal_00dd4cb0& vector);
    void Sub(const PacketCallLocal_00dd4cb0& vector);
    void Cross(const PacketCallLocal_00dd4cb0& a, const PacketCallLocal_00dd4cb0& b);

    void setAbs4(const PacketCallLocal_00dd4cb0& vector);
    void setMul4(const SimdReal& scalar, const PacketCallLocal_00dd4cb0& vector);
    void addMul4(const SimdReal& scalar, const PacketCallLocal_00dd4cb0& vector);
    void setAddMul4(const PacketCallLocal_00dd4cb0& a, const PacketCallLocal_00dd4cb0& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const PacketCallLocal_00dd4cb0& vector);
    void setAddMul(const PacketCallLocal_00dd4cb0& a, const PacketCallLocal_00dd4cb0& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const PacketCallLocal_00dd4cb0& vector);
    void transformed(const Transform& transform, const PacketCallLocal_00dd4cb0& vector);
    void addScaled(const PacketCallLocal_00dd4cb0& base, const PacketCallLocal_00dd4cb0& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkpMoppCode.h"
struct InitArg;
struct SubFirst
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;

    void hkpMoppSplitter_hkpMoppSplitParams_hkpMoppSplitParams(InitArg* apArg);
};
struct SubSecond
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;

    void hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(InitArg* apArg);
};
struct FUN_00dd4bf0
{
    int m_i00;
    int m_i04;
    SubFirst m_kFirst;
    SubSecond m_kSecond;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    int m_i4c;
    __m128 m_kVector;
    int m_iMode;
    char m_bFlag;

    FUN_00dd4bf0(InitArg* apArg);
};
struct SourceData
{
    float x;
    float y;
    float z;
    unsigned int unk0C;
    __m128 unk10;
    unsigned int unk20;
    unsigned char unk24;
};
struct Destination
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    float unk40;
    float unk44;
    float unk48;
    __m128 unk50;
    unsigned int unk60;
    unsigned char unk64;
    void CopyFromSourceData(unsigned int srcAddress);
};

extern "C" void _ReadWriteBarrier(void);
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct Allocator
{
    virtual void slot0() throw();
    virtual void* allocate(int) throw();
    virtual void slot8() throw();
    virtual void slotC() throw();
    virtual void freeBlock(void*, int) throw();
};
void* __cdecl FUN_00c85690(Allocator*, int) throw();
void __cdecl hkMemoryRouter_easyFree(Allocator*, void*) throw();
void __cdecl hkArrayUtil__reserve(Allocator*, void*, int, int) throw();
void __cdecl hkString_memCpy(void*, const void*, int) throw();
template <class T> struct MergeArray
{
    T* data;
    int size;
    int capacity;
    static void fill(T* p, int num)
    {
        _ReadWriteBarrier();
        if (num > 0)
            FUN_00ec61c0(p, 0xcd, num * sizeof(T));
    }
    void init()
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
    }
    int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    void reserve(int n)
    {
        Allocator& a = reinterpret_cast<Allocator&>(reinterpret_cast<Allocator&>((&hkMemoryRouter::getInstance())->heap()));
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            hkArrayUtil__reserve(&a, this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    void reserveExactly(int n)
    {
        Allocator& a = reinterpret_cast<Allocator&>((&hkMemoryRouter::getInstance())->heap());
        if (getCapacity() < n)
            hkArrayUtil__reserve(&a, this, n, sizeof(T));
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        size = n;
    }
    void setSizeFill(int n)
    {
        reserve(n);
        fill(data + size, n - size);
        size = n;
    }
    void ClearAndRelease()
    {
        Allocator& a = reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap());
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.freeBlock(data, (capacity & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
extern char DAT_0102e368;
inline void* hkpMoppCode::operator new(std::size_t n)
{
    hkReferencedObject* b = (hkReferencedObject*)(&hkMemoryRouter::getInstance())->heap().blockAlloc(n);
    b->m_usMemSizeAndFlags = (unsigned short)n;
    return b;
}
template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum()
{}
template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum(ENUM value) : m_kStorage((STORAGE)value)
{}
inline hkpMoppCode::hkpMoppCode() throw()
{
    m_info.m_offset.m_vComponents = _mm_setzero_ps();
    m_eBuildType = hkEnum<BuildType, hkInt8>(BUILD_NOT_SET);
}
struct PrimitiveSource
{
    virtual void slot0() throw();
    virtual void slot4() throw();
    virtual void slot8() throw();
    virtual void setAssembler(void*, int) throw();
    virtual int count() throw();
    virtual void SetDataPointer(void*) throw();
};
struct hkpMoppCodeGenerator : hkReferencedObject
{
    int byteCapacity;
    int byteSize;
    unsigned char* byteData;
    MergeArray<int> state;
    hkpMoppCodeGenerator(int) throw();
    hkpMoppCode* AllocateStorage_00e064f0() throw();
    ~hkpMoppCodeGenerator() throw();
};
struct CostSettings
{
    float primitive, plane, axis, split, balance, minimum, maximum, scale;
};
extern char DAT_0102e388;
struct hkpMoppCostFunction
{
    void* vfptr;
    unsigned short memSizeAndFlags;
    short referenceCount;
    float axis, plane, primitive, split, balance, scale;
    hkpMoppCostFunction(CostSettings*) throw();
    ~hkpMoppCostFunction() throw()
    {
        vfptr = &DAT_0102e388;
    }
};
struct AssemblerSettings
{
    int unk00;
};
struct ChunkRecord
{
    int offset;
    int primitive;
};
struct ChunkEntry
{
    hkpMoppCodeGenerator* generator;
    int flags;
};
struct ChunkList
{
    int fixedSize;
    int unk04, unk08, unk0C;
    ChunkEntry* entries;
    int count;
    int capacity;
    int useFixedSize;
    ChunkEntry& at(const int& i)
    {
        return entries[i];
    }
};
struct AssemblerInterface
{
    virtual void slot0() throw();
    virtual void slot4() throw();
    virtual void slot8() throw();
    virtual int outputSize() throw();
    virtual void* output() throw();
    virtual void slot14() throw();
    virtual void finalize(int, PacketCallLocal_00dd4cb0*) throw();
};
struct hkpMoppDefaultAssembler : AssemblerInterface
{
    unsigned short memoryFlags, referenceCount;
    int unk08, unk0C, unk10;
    ChunkList* chunks;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48;
    int unk4C;
    float unk50, unk54, unk58, unk5C;
    PacketCallLocal_00dd4cb0 unk60;
    int unk70, unk74, unk78, unk7C;
    hkpMoppDefaultAssembler(AssemblerSettings*, hkpMoppCodeGenerator*, PrimitiveSource*) throw();
    ~hkpMoppDefaultAssembler() throw();
};
struct ScratchLayout
{
    unsigned char* start;
    unsigned char* nodes;
    unsigned char* end;
};
struct hkpMoppDefaultSplitter
{
    void* vtbl;
    int unk04;
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkpMoppCostFunction* costFunction;
    hkpMoppDefaultAssembler* assembler;
    PrimitiveSource* source;
    int unk2C, unk30, unk34, treeDepth;
    void FUN_00e09ba0() throw();
    void Hkpmoppdefaultsplitter_UpdateState_00e09bd0() throw();
    hkpMoppDefaultSplitter() throw()
    {
        FUN_00e09ba0();
    }
    ~hkpMoppDefaultSplitter() throw()
    {
        Hkpmoppdefaultsplitter_UpdateState_00e09bd0();
    }
    int hkpMoppDefaultSplitter_buildTree(PrimitiveSource*, hkpMoppCostFunction*, hkpMoppDefaultAssembler*, int*, ScratchLayout*) throw();
};
struct EncodedReference
{
    unsigned char tag, indexHigh, indexMiddle, indexLow, indexLast;
    int FUN_00dd4bb0() throw();
};
static __declspec(noinline) void StoreBigEndian(EncodedReference* reference, int value) throw()
{
    reference->indexHigh = (unsigned int)value >> 24;
    reference->indexMiddle = (unsigned int)value >> 16;
    reference->indexLow = (unsigned int)value >> 8;
    reference->indexLast = value;
}
inline void* allocateScratch(int n)
{
    Allocator* heap = reinterpret_cast<Allocator*>(&(&hkMemoryRouter::getInstance())->heap());
    return FUN_00c85690(heap, n);
}
struct MoppBuilder
{
    int result;
    ChunkList* chunks;
    int options;
    int extraPrimitives;
    int unk10, unk14, unk18;
    bool largeBuffer;
    CostSettings cost;
    AssemblerSettings assembler;
    int FUN_00dd4b80(PrimitiveSource*) throw();
    hkpMoppCode* AllocateStorage_00dd4cb0(PrimitiveSource*, void*, int) throw();
};
// @fnv 0x00dd4cb0
// src: GUESS 0x00dd4cb0 (confidence: low)
hkpMoppCode* MoppBuilder::AllocateStorage_00dd4cb0(PrimitiveSource* source, void* buffer, int bufferSize)
{
    int primitiveCount = source->count() + extraPrimitives;
    hkpMoppCodeGenerator generator(primitiveCount * 12);
    hkpMoppCostFunction costFunction(&cost);
    hkpMoppDefaultAssembler output(&assembler, &generator, source);
    output.chunks = chunks;
    AssemblerInterface* outputInterface = &output;
    source->setAssembler(outputInterface->output(), outputInterface->outputSize());
    int required = FUN_00dd4b80(source);
    void* scratch = (!buffer || bufferSize < required) ? allocateScratch(required) : buffer;
    ScratchLayout layout;
    layout.start = (unsigned char*)scratch;
    layout.nodes = (unsigned char*)scratch + primitiveCount * 20;
    int nodeCount = largeBuffer ? 4096 : primitiveCount;
    layout.end = layout.nodes + nodeCount * 124;
    source->SetDataPointer(scratch);
    int status;
    {
        hkpMoppDefaultSplitter splitter;
        status = splitter.hkpMoppDefaultSplitter_buildTree(source, &costFunction, &output, &options, &layout);
    }
    if (scratch != buffer)
    {
        Allocator* heap = reinterpret_cast<Allocator*>(&(&hkMemoryRouter::getInstance())->heap());
        hkMemoryRouter_easyFree(heap, scratch);
    }
    result = status;
    hkpMoppCode* code;
    if (!chunks)
    {
        code = generator.AllocateStorage_00e064f0();
    }
    else
    {
        MergeArray<int> offsets;
        offsets.init();
        offsets.SetSizeAndGrow(chunks->count + 1);
        offsets.data[0] = 0;
        for (int i = 0; i < chunks->count; ++i)
        {
            int size;
            if (chunks->useFixedSize)
                size = chunks->fixedSize;
            else
                size = (chunks->entries[i].generator->byteSize + 15) & ~15;
            offsets.data[i + 1] = offsets.data[i] + size;
        }
        for (int i = 0; i < chunks->count; ++i)
        {
            ChunkEntry* entry = &chunks->entries[i];
            MergeArray<ChunkRecord>& records = *(MergeArray<ChunkRecord>*)&entry->generator->state;
            for (int j = 0; j < records.size; ++j)
            {
                hkpMoppCodeGenerator* current = entry->generator;
                EncodedReference* reference =
                    (EncodedReference*)(current->byteData + current->byteCapacity - records.data[j].offset);
                StoreBigEndian(reference, offsets.data[reference->FUN_00dd4bb0()]);
            }
        }
        int totalSize = offsets.data[offsets.size - 1];
        code = new hkpMoppCode;
        MergeArray<unsigned char>& bytes = *(MergeArray<unsigned char>*)&code->m_data;
        bytes.reserveExactly(totalSize);
        bytes.setSizeFill(totalSize);
        for (int i = 0; i < chunks->count; ++i)
        {
            unsigned char* dest = bytes.data + offsets.data[i];
            hkpMoppCode* part = chunks->at(i).generator->AllocateStorage_00e064f0();
            hkString_memCpy(dest, part->m_data.m_data, part->m_data.m_iElementCount);
            delete part;
            chunks->at(i).generator->removeReference();
        }
        offsets.ClearAndRelease();
    }
    outputInterface->finalize(status, (PacketCallLocal_00dd4cb0*)&code->m_info);
    return code;
}
