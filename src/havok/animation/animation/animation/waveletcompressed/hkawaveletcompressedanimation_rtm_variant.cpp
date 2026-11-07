// src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkaWaveletCompressedAnimation.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkStreamWriter.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMemoryRouter.h"

typedef unsigned short hkUint16;
struct hkQsTransform;
int __cdecl hkCalcQuantizedSize(int aiValue, const char* apBytes);
unsigned int __fastcall hkaWaveletCompressedAnimation_getFullCacheKey(hkaWaveletCompressedAnimation* self, int, unsigned int a);
struct FUN_00e2f8c0_Class
{
    unsigned char m_auiShapeKeys[0x2c];
    unsigned int m_divisor;

    int hkaWaveletCompressedAnimation_getNumDataChunks(unsigned int value, int unused);
};
void __stdcall hkaWaveletCompressedAnimation_sampleIndividualFloatTracks(int aiUnused1, int aiUnused2, unsigned int count, void* dest);
struct FUN_00e2f7c0_Class : hkaWaveletCompressedAnimation
{
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual unsigned int v8();
    void hkaAnimation_getFrameAndDelta(float t, unsigned int* outIndex, float* outFrac);
};
struct FUN_00e2f8b0_Obj
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

    int GetUnk28();
};
class FUN_00e2f860
{
  public:
    hkUint16 m_maxIterations;
    hkUint16 m_firstFreeIndex;
    hkUint16 m_flags;
    hkUint16 m_pad06;
    hkReal m_fScalar;
    volatile unsigned char m_enabled;
    hkReal m_offset;
    hkReal m_linearTolerance;
    hkReal m_angularTolerance;
    hkReal m_linearLimit;
    hkReal m_fAngularLimit;

    FUN_00e2f860();
};
class ObjE2F8
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Process(float fTime, int iA, int iB, int iC, int iD, int iE);
    int unk04, unk08, unk0C;
    int m_iFirst;
    int m_iSecond;

    void hkaWaveletCompressedAnimation_sampleTracks(float fTime, int iB, int iD, int iE);
};
struct e2f910_Cls
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(void* dest, int value, int count);
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual int vf40(int value);

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
    int m_iDofCount;
};
struct e2f910_Stream
{
    e2f910_Cls* ctrl;
};
extern "C" e2f910_Cls* e2f910_obj(void);
volatile int g_e2f910_a2 = 0;
volatile int g_e2f910_a4 = 0;
e2f910_Stream* volatile g_e2f910_stream = 0;
static void releaseToCache(e2f910_Cls* anim, int arg1, e2f910_Stream* stream, int count);
void e2f910_probe_caller(void);
class hkBufferE2FA
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual int getNumElements();

    int unk04[10];
    int m_iDofCount;
    int unk30;
    int m_iElementIndex;
    int unk38[11];
    char* m_data;

    void Write(hkStreamWriter* writer);
};
extern unsigned char DAT_0126ef84;
void __cdecl hkaProcessFlyingColors(void*);
extern const float DAT_010ec880[];
struct QParam_00e51660
{
    unsigned char m_uiFirstQuantizationParameter;
    unsigned char m_ucSecondQuantizationParameter;
    unsigned short unk02;
    float m_vScale;
    float m_offset;
};
static __forceinline void Decode_e51660(const unsigned char* __restrict& in, const QParam_00e51660* qParam, float* out,
                                        int totalCount)
{
    unsigned char bitWidth = qParam->m_uiFirstQuantizationParameter;
    int bw = bitWidth;
    unsigned int count = totalCount;
    float scale = DAT_010ec880[bw] * qParam->m_vScale;

    switch (bitWidth)
    {
    default: {
        unsigned int bitBuffer = 0;
        unsigned int mask = (unsigned short)((1 << bw) - 1);
        unsigned int i = 0;
        int bitsInRegister = 0;
        while (i < count)
        {
            if (bitsInRegister >= bw)
            {
                do
                {
                    if (i < count)
                    {
                        unsigned short val = bitBuffer & mask;
                        out[i] = (val + 0.5) * scale + qParam->m_offset;
                    }
                    bitBuffer >>= bw;
                    bitsInRegister -= bw;
                    i++;
                } while (bitsInRegister >= bw);
            }
            unsigned short word = *in++;
            word |= (unsigned short)(*in++) << 8;
            bitBuffer |= (unsigned int)word << bitsInRegister;
            bitsInRegister += 16;
        }
        break;
    }
    case 16: {
        for (unsigned int i = 0; i < count; ++i)
        {
            unsigned short val = *in++;
            val |= (unsigned short)(*in++) << 8;
            out[i] = (val + 0.5) * scale + qParam->m_offset;
        }
        break;
    }
    case 8: {
        for (unsigned int i = 0; i < count; ++i)
        {
            out[i] = (*in++ + 0.5) * scale + qParam->m_offset;
        }
        break;
    }
    }
}
void __cdecl DecodeQuantizedBlock(const unsigned char* __restrict in, const QParam_00e51660* qParam, float* out,
                                  int totalCount);
float __cdecl hkaWaveletCompressedAnimation_SwapFloatByteOrder(float f);
static unsigned short hkaWaveletCompressedAnimation_SwapUnsignedShortByteOrder(unsigned short v);
unsigned short volatile g_in;
unsigned short g_out;
void caller();
#include <xmmintrin.h>
extern float DAT_01012068;
extern __m128 DAT_010c71b0;
// Companion quad-writer variant (scalar-load broadcast form) that shares the
// module with FUN_00e2fbc0; TU order matters for VC9's codegen state.
struct DestWrapPre
{
    float* p;
    DestWrapPre(float* q) : p(q)
    {}
};
void __stdcall sse_preload_quad(int, int, unsigned int count, DestWrapPre dest)
{
    if (count > 0)
    {
        __m128 one = _mm_set_ss(DAT_01012068);
        __m128 zero = _mm_setzero_ps();
        one = _mm_shuffle_ps(one, one, 0);
        __m128* p = (__m128*)dest.p;
        p += 2;
        do
        {
            p[-2] = zero;
            p[-1] = DAT_010c71b0;
            p[0] = one;
            p += 3;
        } while (--count);
    }
}
struct DestWrap
{
    float* p;
    DestWrap(float* q) : p(q)
    {}
};
void __stdcall hkaWaveletCompressedAnimation_sampleIndividualTransformTracks(int, int, unsigned int count, DestWrap dest);
extern "C" void __cdecl _ReadWriteBarrier(void);
struct SwapCountsE2
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m;
    float n;
    SwapCountsE2() : a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0), j(0), k(0), l(0), m(0), n(0.0f)
    {}
};
void __cdecl hkaTrackAnalysis_calcStats(unsigned short*, unsigned short*, int, int, SwapCountsE2*);
inline unsigned short SwapShortE2(unsigned short v)
{
    union
    {
        unsigned short s;
        unsigned int u;
    } value;
    value.s = v;
    struct
    {
        unsigned char first, second;
    } b;
    b.first = (unsigned char)(*(volatile unsigned int*)&value >> 8);
    b.second = (unsigned char)value.u;
    return *(unsigned short*)&b;
}
inline float SwapFloatE2(float v)
{
    unsigned int u = *(unsigned int*)&v;
    struct
    {
        unsigned char first, second, third, fourth;
    } b;
    b.first = (unsigned char)(u >> 24);
    b.second = (unsigned char)(u >> 16);
    b.third = (unsigned char)(u >> 8);
    b.fourth = (unsigned char)u;
    return *(float*)&b;
}
inline unsigned int SwapIntE2(unsigned int u)
{
    struct
    {
        unsigned char first, second, third, fourth;
    } b;
    b.first = (unsigned char)(u >> 24);
    b.second = (unsigned char)(u >> 16);
    b.third = (unsigned char)(u >> 8);
    b.fourth = (unsigned char)u;
    return *(unsigned int*)&b;
}
void __fastcall hkaWaveletCompressedAnimation_handleEndian(hkaWaveletCompressedAnimation* self);
#include <string.h>
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern void* DAT_00fdf044;
typedef void*(__stdcall* S00e306d0_TlsFn)(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010eb358[];
extern const char str_010c41f8[];
struct S00e306d0_Args
{
    unsigned int f00;
    unsigned int f04;
    unsigned char b08;
    unsigned char b09;
    unsigned char b0a;
    unsigned char b0b;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
};
static volatile unsigned int s00e306d0_sink;
// src: HAVOK_LIB 0x00e300b0
static __declspec(noinline) void _decompress(unsigned int x, S00e306d0_Args args)
{
    unsigned int* p = (unsigned int*)x;
    p[0] = args.f00;
    p[1] = args.f18;
    p[2] = args.f04;
}
struct S00e306d0_Obj
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
    unsigned int m_ui2c;
    unsigned char m_b30;
    unsigned char m_b31;
    unsigned char unk32;
    unsigned char unk33;
    int unk34;
    unsigned int m_ui38;
    unsigned int m_ui3c;
    unsigned int m_ui40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    unsigned int m_ui54;
    int unk58;
    unsigned int m_ui5c;
    int unk60;
    unsigned int m_ui64;
};
static void decompressBlockToCache(S00e306d0_Obj* self, unsigned int a, unsigned int b, unsigned int c);
void S00e306d0_Wrap(S00e306d0_Obj* self, unsigned int a, unsigned int b, unsigned int c);
#include <windows.h>
struct hkDmaRefE2FA
{
    const void* m_ptr;
    int m_iElementCount;
    unsigned char m_offset;

    void set(const void* p, int size)
    {
        m_offset = (unsigned char)((unsigned int)p & 0xf);
        m_ptr = p;
        m_iElementCount = size;
    }
};
struct hkSlotE2FA
{
    int unk00;
    int unk04;
    int unk08;
};
struct hkJobDescE2FA
{
    hkDmaRefE2FA m_queue;
    hkDmaRefE2FA m_data;
    hkSlotE2FA m_slot;
    hkSlotE2FA m_nextSlot;
};
class hkQueueE2FA
{
  public:
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
    unsigned int m_slotSize;
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
    unsigned int m_numSlots;
    int m_iDataSize;
    int unk60;
    void* m_data;

    void hkaWaveletCompressedAnimation_getBlockDataAndSize(unsigned int slot, hkDmaRefE2FA* out) const;
    void hkaWaveletCompressedAnimation_getDataChunks(unsigned int offset, int unused, hkDmaRefE2FA* desc, int mode) const;
};
struct InfoE2FB
{
    InfoE2FB() : m_iFirstValue(0), m_uiLogicalSize(0), m_bFlag(false)
    {}
    int m_iFirstValue;
    int m_uiLogicalSize;
    unsigned char m_bFlag;
};
class HostE2FB : public hkaWaveletCompressedAnimation
{
  public:
    void hkaWaveletCompressedAnimation_getBlockDataAndSize(unsigned int uiIndex, InfoE2FB* pkInfo);
    int hkaWaveletCompressedAnimation_getMaxSizeOfCombinedDataChunks();
};
// src: HAVOK_LIB 0x00e2fa60
__declspec(noinline) void HostE2FB::hkaWaveletCompressedAnimation_getBlockDataAndSize(unsigned int uiIndex, InfoE2FB* pkInfo)
{
    const unsigned int* blockOffsets =
        reinterpret_cast<const unsigned int*>(m_kCompressedData.m_data + m_uiIndexDataOffset);
    unsigned int address =
        reinterpret_cast<unsigned int>(m_kCompressedData.m_data + m_uiNumDynamicDofs) + blockOffsets[uiIndex];
    pkInfo->m_iFirstValue = address & ~15;
    pkInfo->m_bFlag = address & 15;
    if (uiIndex != m_uiNumIndices - 1)
        pkInfo->m_uiLogicalSize = blockOffsets[uiIndex + 1] - blockOffsets[uiIndex];
    else
        pkInfo->m_uiLogicalSize = m_uiNumDynamicTracks - blockOffsets[uiIndex];
    pkInfo->m_uiLogicalSize = (pkInfo->m_uiLogicalSize + static_cast<unsigned char>(address & 15) + 15) & ~15;
}
struct ChunkRetry
{
    const void* data;
    unsigned int size;
    unsigned char misalignment;
    void setStart(const void* p)
    {
        unsigned long bits = (unsigned long)p;
        misalignment = (unsigned char)(bits & 15);
        bits &= ~15UL;
        data = (const void*)bits;
    }
    void finish()
    {
        size = (size + misalignment + 15) & ~15U;
    }
};
struct AnimRetry : hkaWaveletCompressedAnimation
{
    void hkaWaveletCompressedAnimation_getBlockDataAndSize(int block, ChunkRetry& chunk) const;
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" unsigned long DAT_0126835c;
extern "C" void _ReadWriteBarrier();
inline void monitorBegin(const char* name, const char* object, unsigned& stamp)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (stream->m_end.m_storage < stream->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerBeginListCommand* record = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(stream->m_end.m_storage);
        record->m_commandAndMonitor = name;
        record->m_nameOfFirstSplit = object;
        _ReadWriteBarrier();
        stamp = (unsigned int)__rdtsc();
        record->m_time0 = static_cast<const volatile unsigned&>(stamp);
        stream->m_end.m_storage = reinterpret_cast<char*>(record + 1);
    }
}
inline void monitorEarlySplit(const char* name, unsigned& stamp)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (stream->m_end.m_storage < stream->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* record = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
        record->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        stamp = (unsigned int)__rdtsc();
        record->m_time0 = static_cast<const volatile unsigned&>(stamp);
        stream->m_end.m_storage = reinterpret_cast<char*>(record + 1);
    }
}
inline void monitorSplit(const char* name)
{
    hkMonitorStream* stream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (stream->m_end.m_storage < stream->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* record = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
        record->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        unsigned int stamp = (unsigned int)__rdtsc();
        record->m_time0 = static_cast<const volatile unsigned&>(stamp);
        stream->m_end.m_storage = reinterpret_cast<char*>(record + 1);
    }
}
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct Chunk
{
    const hkUint8* data;
    unsigned int size;
    hkUint8 offset;
    const hkUint8* bytes() const
    {
        return data + offset;
    }
};
struct WaveletParameters
{
    unsigned int count;
    int blockSize;
    hkUint8 preserved, maxBitWidth;
    const float* offsets;
    const float* scales;
    const hkUint8* bitWidths;
    const hkUint8* data;
};
struct Quantization
{
    hkUint8 bitWidth, preserved;
    float scale, offset;
};
struct PackedFormat
{
    unsigned int bits, value, rawCount;
};
int __cdecl hkCalcQuantizedSize(int, const Quantization*);
unsigned int __cdecl DecodeBlock(const float*, const PackedFormat*, float*, unsigned int);
void __cdecl DecodeQuantizedBlock(const float*, const Quantization*, float*, int);
void __cdecl hkInverseWaveletTransform(float*, int);
struct TrackStatistics
{

    unsigned int staticTranslations, staticRotations, staticScales;

    unsigned int dynamicTranslations, dynamicRotations, dynamicScales;

    unsigned int totalStatic;

    unsigned int selectedTranslations, selectedRotations, selectedScales;

    unsigned int selectedFloats, totalDynamic, totalFloats;

    float weight;

    __forceinline void Reset()
    {

        staticTranslations = 0;

        staticRotations = 0;

        staticScales = 0;

        dynamicTranslations = 0;

        dynamicRotations = 0;

        dynamicScales = 0;

        totalStatic = 0;

        selectedTranslations = 0;

        selectedRotations = 0;

        selectedScales = 0;

        selectedFloats = 0;

        totalDynamic = 0;

        totalFloats = 0;

        weight = 0.0f;
    }
};
struct RecomposeParameters
{

    unsigned int numTransformTracks;

    unsigned int numFloatTracks;

    const hkUint16* transformMasks;

    const hkUint16* floatMasks;

    const float* staticTransforms;

    const float* staticFloats;

    const float* dynamicTransforms;

    const float* dynamicFloats;
};
void __cdecl FUN_00e4e610(const hkUint16*, const hkUint16*, unsigned int, unsigned int, TrackStatistics*);
void __cdecl hkaTrackAnalysis_recompose(const RecomposeParameters*, hkQsTransform*, float*);
// src: HAVOK_LIB 0x00e300b0
static void _decompress(WaveletParameters parameters, float* output)
{

    Quantization quantization;
    quantization.preserved = parameters.preserved;
    quantization.bitWidth = parameters.maxBitWidth;

    unsigned int bytes = hkCalcQuantizedSize(parameters.blockSize, &quantization);

    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    float* temporary = reinterpret_cast<float*>(router->m_stack.m_next.m_storage);
    router->m_stack.m_next.m_storage = (char*)router->m_stack.m_next.m_storage + ((bytes + 127) & ~127u);

    const hkUint8* data = parameters.data;

    for (unsigned int i = 0; i < parameters.count; ++i)
    {

        quantization.offset = parameters.offsets[i];
        quantization.scale = parameters.scales[i];
        quantization.bitWidth = parameters.bitWidths ? parameters.bitWidths[i] : parameters.maxBitWidth;

        bytes = hkCalcQuantizedSize(parameters.blockSize, &quantization);

        PackedFormat format;
        format.bits = quantization.bitWidth;
        format.rawCount = parameters.preserved;

        int range = 1 << quantization.bitWidth;
        format.value = (unsigned int)(-quantization.offset * range / quantization.scale);
        if (format.value == (unsigned int)range)
            --format.value;

        data += DecodeBlock(reinterpret_cast<const float*>(data), &format, temporary, bytes);

        DecodeQuantizedBlock(temporary, &quantization, output, parameters.blockSize);
        hkInverseWaveletTransform(output, parameters.blockSize);
        output += parameters.blockSize;
    }

    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage = (void*)(reinterpret_cast<int>(temporary));
}
void __cdecl hkaWaveletCompressedAnimation_samplePartialWithDataChunks(unsigned int frame, float weight, unsigned int numTransforms, hkQsTransform* transforms,
                          unsigned int numFloats, float* floats, const Chunk* chunks, int chunkCount);

namespace wav {

struct DecompressParams
{
    unsigned int m_iBlockCount;
    int m_iElementIndex;
    int m_numFloats;
    unsigned char m_quantFormat;
    unsigned char m_defaultBits;
    unsigned char unk0e;
    unsigned char unk0f;
    const float* m_maxs;
    const float* m_mins;
    const unsigned char* m_bits;
    const char* m_data;
};

}

void __cdecl FUN_00e592a0(float* dst, int numFloats);

// @fnv 0x00e349c0
// src: HAVOK_LIB 0x00e349c0
static __declspec(noinline) void _decompress_00e349c0(float* dst, wav::DecompressParams params)
{
    const char* data = params.m_data;
    unsigned int offset = 0;
    QParam_00e51660 info;
    info.m_ucSecondQuantizationParameter = params.m_quantFormat;
    for (unsigned int i = 0; i < params.m_iBlockCount; i++)
    {
        info.m_offset = params.m_maxs[i];
        info.m_vScale = params.m_mins[i];
        info.m_uiFirstQuantizationParameter = params.m_bits ? params.m_bits[i] : params.m_defaultBits;
        DecodeQuantizedBlock(reinterpret_cast<const unsigned char*>(data + offset), &info, dst, params.m_numFloats);
        FUN_00e592a0(dst, params.m_numFloats);
        dst += params.m_iElementIndex;
        offset += hkCalcQuantizedSize(params.m_numFloats, (const char*)&info);
    }
}

void DecompressCaller(float* dst, wav::DecompressParams params)
{
    _decompress_00e349c0(dst, params);
}
