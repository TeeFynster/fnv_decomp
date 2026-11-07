#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#include "../../../../../../include/hkArray.h"

// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkThreadMemory.h"

inline hkMemory& GetThreadHeap(hkThreadMemory* memory)
{
    return *memory->m_pMemoryAllocator;
}

typedef ::__m128 LocalM128;

extern "C" LocalM128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, LocalM128 a);

struct __declspec(align(16)) FUN_005611c0_t
{
    float x, y, z, w;
    FUN_005611c0_t(const FUN_005611c0_t& o)
    {
        *(LocalM128*)&x = *(const LocalM128*)&o.x;
    }
    void normalize_005611c0();
};

struct Buffer
{
    char* m_data;
    int m_iElementCount;
};

void __cdecl hkaSplineCompressedAnimation_writeAlignQuaternion(int type, Buffer* buf);
void __cdecl hkaSplineCompressedAnimation_writeZeros(int size, Buffer* buf);
void __cdecl CallHandlerByIndex(int, int, int);
extern int DAT_010eb3d0[];

struct VecArray
{
    FUN_005611c0_t* m_data;
};

struct Writer
{
    char pad[0x74];
    Buffer m_buf;

    void ProcessEntries_00e319e0(unsigned char flags, int type, const FUN_005611c0_t* v, int last, const VecArray* arr);
};

// @fnv 0x00e319e0
// src: GUESS 0x00e319e0 (confidence: low)
void Writer::ProcessEntries_00e319e0(unsigned char flags, int type, const FUN_005611c0_t* apVec, int last,
                          const VecArray* apVecArray)
{
    if (flags & 0xf0)
    {
        hkaSplineCompressedAnimation_writeAlignQuaternion(type, &m_buf);
        int size = DAT_010eb3d0[type];
        for (int i = 0; i <= last; i++)
        {
            FUN_005611c0_t t = apVecArray->m_data[i];
            t.normalize_005611c0();
            hkaSplineCompressedAnimation_writeZeros(size, &m_buf);
            CallHandlerByIndex(type, (int)&t, (int)(m_buf.m_data + m_buf.m_iElementCount - size));
        }
    }
    else if (flags & 0x0f)
    {
        hkaSplineCompressedAnimation_writeAlignQuaternion(type, &m_buf);
        int size = DAT_010eb3d0[type];
        FUN_005611c0_t t = *apVec;
        t.normalize_005611c0();
        hkaSplineCompressedAnimation_writeZeros(size, &m_buf);
        CallHandlerByIndex(type, (int)&t, (int)(m_buf.m_data + m_buf.m_iElementCount - size));
    }
}

namespace fnv_00e31ad0 {
struct Buffer
{
    unsigned short* data;
    unsigned int byteSize;
};
void __cdecl hkaSplineCompressedAnimation_writeZeros(unsigned int, Buffer*);
// @fnv 0x00e31ad0
void __cdecl WriteUInt16ToBuffer(unsigned short value, Buffer* buffer)
{
    hkaSplineCompressedAnimation_writeZeros(2, buffer);
    *(unsigned short*)((char*)buffer->data + buffer->byteSize - 2) = value;
}
}  // namespace fnv_00e31ad0

void ResizeAudioStream(hkMemory& alloc, void* arr, int elemSize);
template <typename T> inline void S_00e31ca0_constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
typedef hkArray<unsigned char> S_00e31ca0_ByteArray;
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
return reinterpret_cast<hkMemoryAllocator&>(GetThreadHeap(hkThreadMemory::GetMonitorStream()));
}
template<> __forceinline void hkArrayBase<unsigned char>::_pushBack(hkMemoryAllocator& sharedAlloc, unsigned char const& t)
{
hkMemory& alloc = reinterpret_cast<hkMemory&>(sharedAlloc);

        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(unsigned char));
        S_00e31ca0_constructWithCopy<unsigned char>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;

}

typedef hkArrayBase<float> S_00e31ca0_FloatArray;
void WriteUInt16ToBuffer(int v, S_00e31ca0_ByteArray& out);
void AppendChar(int v, S_00e31ca0_ByteArray& out);
struct S_00e31ca0
{
    int unk0;
    int unk4;
    int unk8;
    float unkC;
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
    S_00e31ca0_ByteArray m_out;
    void AppendScaledValues(int a, int b, S_00e31ca0_FloatArray& values);
};
// @fnv 0x00e31ca0
void S_00e31ca0::AppendScaledValues(int aiFirst, int aiSecond, S_00e31ca0_FloatArray& arValues)
{
    int last = aiFirst + aiSecond + 1;
    WriteUInt16ToBuffer(aiFirst, m_out);
    AppendChar(aiSecond, m_out);
    for (int i = 0; i <= last; i++)
    {
        unsigned char ucScaled = (unsigned char)(int)(arValues.m_data[i] / unkC * (unk28 - 1) + 0.5);
        m_out.pushBack(ucScaled);
    }
}

void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

static __forceinline void ConstructArray13(char* p, int n, char const& e)
{
        for (int i = 0; i < n; i++)
            p[i] = e;
    }
typedef hkArray<char> E317C0CharArray;
template<> __forceinline void hkArrayBase<char>::_pushBack(hkMemoryAllocator& sharedAlloc, char const& e)
{
hkMemory& alloc = reinterpret_cast<hkMemory&>(sharedAlloc);

        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(char));
        ConstructArray13(m_data + m_iElementCount, 1, e);
        m_iElementCount++;

}


// Appends the character c to the E317C0CharArray out via its push-back method.
// @fnv 0x00e317c0
void __cdecl AppendChar(char acChar, E317C0CharArray& arOut)
{
    arOut.pushBack(acChar);
}

extern void __cdecl hkaSplineCompressedAnimation_writeZeros(int amount, struct MemWriter* writer);

struct MemWriter
{
    int used;
    char* data;
};

// @fnv 0x00e31b00
void __cdecl WriteFloatToMemWriter(float value, MemWriter* writer)
{
    hkaSplineCompressedAnimation_writeZeros(4, writer);
    *(float*)(writer->data + writer->used - 4) = value;
}

struct E32C80Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E32C80Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class E32C80Base
{
  public:
    E32C80Base(void* info);
    virtual void unk00();

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
};

class FUN_00e32c80 : public E32C80Base
{
  public:
    FUN_00e32c80(void* info, void* arg1, void* arg2);
    virtual void unk00();

    void init(void* info, void* arg1, void* arg2);

    E32C80Array m_array44;
    E32C80Array m_array50;
    E32C80Array m_array5C;
    E32C80Array m_array68;
    E32C80Array m_array74;
};

// Constructs the object by forwarding info, arg1 and arg2 to init after initializing the E32C80Base base with info.
// @fnv 0x00e32c80
FUN_00e32c80::FUN_00e32c80(void* info, void* arg1, void* arg2) : E32C80Base(info)
{
    init(info, arg1, arg2);
}

struct hkMemory
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void deallocateChunk(void* p, int nbytes) throw();
};

// ~hkArray (clearAndDeallocate) through the thread memory's heap.
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkThreadMemory* tm = hkThreadMemory::GetMonitorStream();
    hkMemory* mem = tm->m_pMemoryAllocator;
    this->m_iElementCount = 0;
    if (!(this->m_iCapacityState & (int)0x80000000))
    {
        mem->deallocateChunk(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    this->m_data = 0;
    this->m_iCapacityState = (int)0x80000000;
}

struct Struct28
{
    char data[28];
};

struct FUN_00e32cf0_Class
{
    hkArray<Struct28> arr1;
    hkArray<int> arr2;
    hkArray<int> arr3;

    ~FUN_00e32cf0_Class() throw();
};

// Destructor for a container holding three hkArray members; the arrays are destroyed by their own destructors.
// @fnv 0x00e32cf0
FUN_00e32cf0_Class::~FUN_00e32cf0_Class() throw()
{}

void __cdecl Object_UpdateFields_00e31740(unsigned char a, unsigned int b, char** pp);
void __cdecl Object_UpdateFields_00e31780(unsigned char a, unsigned int b, char** pp);

union e319Rec
{
    unsigned char raw;
    struct
    {
        unsigned char lo : 2;
        unsigned char mid : 4;
        unsigned char hi : 2;
    } f;
};

union e319Tail
{
    unsigned char raw;
    struct
    {
        unsigned char b0 : 1;
        unsigned char sel : 2;
        unsigned char rest : 5;
    } f;
};

struct e319Cls
{
    char pad[0x10];
    int m_10;
    int m_14;
    char padCur[0x14];
    int m_2c;
    char kad[4];
    char* m_34;
    char pNewad[0xc];
    int* m_44;
    char pTmpad[0x2c];
    int m_74;
    char pad78[8];
    int m_80;
    void hkaSplineCompressedAnimation_handleEndian();
};

// @fnv 0x00e31900
// src: HAVOK_LIB 0x00e31900
void e319Cls::hkaSplineCompressedAnimation_handleEndian()
{
    if (m_80 == 0)
        return;
    for (int i = 0; i < m_2c; i++)
    {
        unsigned char* pSrc = (unsigned char*)(m_44[i] + m_74);
        char* p = m_34 + (unsigned int)pSrc;
        for (int n = 0; n < m_10; n++)
        {
            e319Rec rec;
            rec.raw = *pSrc++;
            Object_UpdateFields_00e31740(*pSrc++, rec.f.lo, &p);
            Object_UpdateFields_00e31780(*pSrc++, rec.f.mid, &p);
            Object_UpdateFields_00e31740(*pSrc++, rec.f.hi, &p);
        }
        for (int iTail = 0; iTail < m_14; iTail++)
        {
            unsigned char ucTail = *pSrc++;
            Object_UpdateFields_00e31740((unsigned char)(ucTail & 0xf9), (ucTail >> 1) & 3, &p);
        }
    }
}

// Havok-style constructor: base init from a1, five empty hkArray members, then a temporary set of
// arrays (one 28-byte element from a2, two int arrays sized from a1 and zero-filled) handed to a
// member initialiser together with a3.
void ReserveMoreL(hkMemory& alloc, void* arr, int elemSize) throw();
void ReserveL(hkMemory& alloc, void* arr, int numElem, int elemSize) throw();
inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

template <class T> struct ArrLLocalForm
{ // local form of hkArray: 0x00e32af0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ArrLLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _pushBack(hkMemory& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ReserveMoreL(alloc, this, sizeof(T));
        new (&m_data[m_iElementCount]) T(t);
        m_iElementCount++;
    }
    void pushBack(const T& t)
    {
        _pushBack(GetThreadHeap(hkThreadMemory::GetMonitorStream()), t);
    }
    void GrowArrayCapacity(hkMemory& alloc, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            ReserveL(alloc, this, newSize, sizeof(T));
        }
    }
    void _setSize(hkMemory& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        _setSize(GetThreadHeap(hkThreadMemory::GetMonitorStream()), n);
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

struct SrcL
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_numA;
    int m_numB;
};
struct Elem28L
{
    int v00, v04, v08, v0c, v10, v14, v18;
};
struct LocalArraysL
{
    ArrLLocalForm<Elem28L> m_pElements;
    ArrLLocalForm<int> m_kPointA;
    ArrLLocalForm<int> m_kPointB;
    ~LocalArraysL() throw();
};
struct BaseL
{
    BaseL(SrcL* src) throw();
    virtual void vf0();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
};
struct FUN_00e32af0 : BaseL
{
    ArrLLocalForm<int> m_arr44;
    ArrLLocalForm<int> m_arr50;
    ArrLLocalForm<int> m_arr5c;
    ArrLLocalForm<int> m_arr68;
    ArrLLocalForm<int> m_arr74;
    FUN_00e32af0(SrcL* src, const Elem28L* elem, void* arg3) throw();
    void InitL(SrcL* src, LocalArraysL* arrays, void* arg3) throw();
};

// Builds temporary arrays from src counts and elem, zero-fills them, then calls InitL to initialize the object.
// @fnv 0x00e32af0
FUN_00e32af0::FUN_00e32af0(SrcL* pSource, const Elem28L* elem, void* arg3) throw() : BaseL(pSource)
{
    LocalArraysL arrays;
    arrays.m_pElements.pushBack(*elem);
    arrays.m_kPointA.SetSizeAndGrow(pSource->m_numA);
    arrays.m_kPointB.SetSizeAndGrow(pSource->m_numB);
    for (int i = 0; i < pSource->m_numA; i++)
        arrays.m_kPointA[i] = 0;
    for (int i = 0; i < pSource->m_numB; i++)
        arrays.m_kPointB[i] = 0;
    InitL(pSource, &arrays, arg3);
}

#include <stdlib.h>
extern "C"
{
    void __cdecl hkaSplineCompressedAnimation_writeAlign(int alignment, void* stream);
    void __cdecl WriteFloatToMemWriter(float val, void* stream);
    void __cdecl AppendChar(unsigned int val, void* stream);
    void __cdecl WriteUInt16ToBuffer(unsigned int val, void* stream);
    unsigned char __cdecl ScaleToByte(float minVal, float maxVal, float val);
    unsigned short __cdecl NormalizeToUShort(float minVal, float maxVal, float val);
}

struct Vector4Array
{
    const float* m_data;
};

struct AnimationCompressor
{
    char pad[0x74];
    char m_stream;

    void WriteCompressedAnimation(unsigned char mask, int quantType, const float* staticValues, const float* minValues,
                                  const float* maxValues, int numFrames, const Vector4Array* data);
};

// Writes animation header and per-frame quantized values to m_stream based on mask and quantType.
// @fnv 0x00e31b20
void AnimationCompressor::WriteCompressedAnimation(unsigned char mask, int quantType, const float* staticValues,
                                                   const float* minValues, const float* maxValues, int numFrames,
                                                   const Vector4Array* data)
{
    void* stream = &m_stream;
    hkaSplineCompressedAnimation_writeAlign(4, stream);

    unsigned int bit = 1;
    for (int i = 0; i < 3; ++i, bit = _rotl(bit, 1))
    {
        if (mask & _rotl(bit, 4))
        {
            WriteFloatToMemWriter(minValues[i], stream);
            WriteFloatToMemWriter(maxValues[i], stream);
        }
        else if (mask & bit)
        {
            WriteFloatToMemWriter(staticValues[i], stream);
        }
    }

    if (mask & 0xf0)
    {
        for (int frame = 0; frame <= numFrames; ++frame)
        {
            int comp = 0;
            unsigned int b = 1;
            for (; comp < 3; ++comp, b = _rotl(b, 1))
            {
                if (mask & _rotl(b, 4))
                {
                    if (quantType == 0)
                    {
                        AppendChar(ScaleToByte(minValues[comp], maxValues[comp], data->m_data[frame * 4 + comp]),
                                   stream);
                    }
                    else
                    {
                        WriteUInt16ToBuffer(
                            NormalizeToUShort(minValues[comp], maxValues[comp], data->m_data[frame * 4 + comp]),
                            stream);
                    }
                }
            }
        }
    }
}

namespace fnv_00e31800 {
struct Buf
{
    char* m_data;
    unsigned int m_len;
    unsigned int m_cap;
};

extern "C" void _ReadWriteBarrier(void);

void __cdecl ResizeAudioStream(void* alloc, Buf* buf, int n);

// Appends count zero bytes to buf, calling FUN_00c90940 when its length equals the masked capacity.
// @fnv 0x00e31800
// src: HAVOK_LIB 0x00e31800
void __cdecl hkaSplineCompressedAnimation_writeZeros(int count, Buf* buf)
{
    if (count > 0)
    {
        do
        {
            hkThreadMemory* h = hkThreadMemory::GetMonitorStream();
            if (buf->m_len == (buf->m_cap & 0x3fffffff))
            {
                ResizeAudioStream(h->m_pMemoryAllocator, buf, 1);
            }
            char* slot = buf->m_data + buf->m_len;
            _ReadWriteBarrier();
            *slot = 0;
            buf->m_len++;
        } while (--count);
    }
}
}  // namespace fnv_00e31800

namespace fnv_00e31850 {
#include <string.h>

struct BufferInfo
{
    char* volatile data;
    unsigned int length;
    unsigned int capacity;
};
extern void __cdecl ResizeAudioStream(void*, BufferInfo*, int);
// Appends zero bytes until no bits selected by alignment minus one remain set in the buffer length.
// @fnv 0x00e31850
// src: HAVOK_LIB 0x00e31850
void __cdecl hkaSplineCompressedAnimation_writeAlign(unsigned int alignment, BufferInfo* buffer)
{
    unsigned int mask = alignment - 1;
    while (buffer->length & mask)
    {
        hkThreadMemory* alloc = hkThreadMemory::GetMonitorStream();
        if (buffer->length == (buffer->capacity & 0x3fffffff))
            ResizeAudioStream(alloc->m_pMemoryAllocator, buffer, 1);
        memset(buffer->data + buffer->length, 0, 1);
        ++buffer->length;
    }
}
}  // namespace fnv_00e31850

namespace fnv_00e318a0 {
extern unsigned int DAT_010eb3e8[];

struct FUN_00e318a0_buf
{
    char* m_pData;
    unsigned int m_uLength;
    unsigned int m_uCapacityFlags;
};

extern void __cdecl ResizeAudioStream(void* apAllocator, FUN_00e318a0_buf* apBuf, int aiFlag);

// @fnv 0x00e318a0
// src: HAVOK_LIB 0x00e318a0
void __cdecl hkaSplineCompressedAnimation_writeAlignQuaternion(unsigned int auBit, FUN_00e318a0_buf* apBuf)
{
    unsigned int mask = DAT_010eb3e8[auBit];
    if ((apBuf->m_uLength & mask) != 0)
    {
        do
        {
            hkThreadMemory* holder = hkThreadMemory::GetMonitorStream();
            if (apBuf->m_uLength == (apBuf->m_uCapacityFlags & 0x3fffffff))
            {
                ResizeAudioStream(holder->m_pMemoryAllocator, apBuf, 1);
            }
            char* volatile* pp = &apBuf->m_pData;
            char* p = (char*)((unsigned int)*pp + apBuf->m_uLength);
            *p = 0;
            apBuf->m_uLength++;
            mask = *(volatile unsigned int*)&DAT_010eb3e8[auBit];
        } while ((apBuf->m_uLength & mask) != 0);
    }
}
}  // namespace fnv_00e318a0
