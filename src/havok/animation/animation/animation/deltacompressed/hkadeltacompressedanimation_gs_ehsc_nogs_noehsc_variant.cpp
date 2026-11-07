
// src/havok/animation/animation/animation/deltacompressed/hkadeltacompressedanimation_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/deltacompressed/hkadeltacompressedanimation.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/animation/deltacompressed/hkadeltacompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/deltacompressed/hkadeltacompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkaDeltaCompressedAnimation.h"
struct FUN_00e34b40_s
{
    unsigned int hkaDeltaCompressedAnimation_getFullCacheKey(unsigned int arg);
};
void __stdcall ZeroBuffer(int a, int b, unsigned int count, unsigned int* dst);
struct FnvCpu_FUN_00e34990_CpuObject
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
    int value;
    int GetValue();
};
struct FUN_00e349a0_class : hkaDeltaCompressedAnimation
{
    int hkaDeltaCompressedAnimation_getNumDataChunks(unsigned int arg, int unused);
};
struct AnimDispatch
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Dispatch(float frameTime, int sectionA, int sourceA, int sectionB, int sourceB, int count);
    int m_04;
    int m_08;
    int m_0c;
    int m_sectionA;
    int m_sectionB;
    void DispatchToSections(float frameTime, int sourceA, int sourceB, int count);
};
// stand-in for the extraction/reader object passed in (vtable slot 5 called)
struct e34b50_reader
{
    virtual void q00();
    virtual void q04();
    virtual void q08();
    virtual void q0c();
    virtual void q10();
    virtual void read(void* dest, const void* src, int size);
};
struct FUN_00e34b50_s : hkaDeltaCompressedAnimation
{
    // base vtable has the dtor pair (slots 0,1); fill up to slot 8
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20_2();
    virtual int v20();
    void hkaDeltaCompressedAnimation_clearAllCacheKeys(e34b50_reader* reader);
};
struct CompressedBlockRange
{
    unsigned int alignedStart;
    unsigned int alignedSize;
    unsigned char prefixBytes;
};
class DeltaAnimationStandIn : public hkaDeltaCompressedAnimation
{
  public:
    void GetCompressedBlockRange(unsigned int blockIndex, unsigned int blockCount, CompressedBlockRange* result);
};
struct BlkInfo
{
    unsigned int a;
    unsigned int b;
    unsigned char c;
};
struct FUN_00e34c90_s : hkaDeltaCompressedAnimation
{
    unsigned int GetCompressedBlockRange(unsigned int index, unsigned int count, BlkInfo* info);
    unsigned int GetMaxBlockSize();
};
struct Source
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual int GetData(int a);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    int m_iElementIndex;
};
struct Stream
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void Write(int* pCount, int data, int size);
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void Begin();
    virtual void End();
};
struct StreamHolder
{
    Stream* m_pBinaryStream;
};
static void releaseToCache_00e34ab0(Source* src, int a, StreamHolder* h, int count);
void Caller_00e34ab0(Source* src, int a, StreamHolder* h, int count);
struct S00e34c10_Block
{
    int unk00;
    int unk04;
    int unk08;
};
struct S00e34c10_Cache
{
    void* anim;
    int unk04;
    unsigned char animAlign;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char* data;
    int quantizedDataOffset;
    unsigned char dataAlign;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    S00e34c10_Block blocks[2];
};
struct S00e34c10_Anim : hkaDeltaCompressedAnimation
{
    void __thiscall GetCompressedBlockRange(unsigned int blockIndex, int numBlocks, S00e34c10_Block* apBlocks);
    void __thiscall hkaDeltaCompressedAnimation_getDataChunks(unsigned int frameIndex, int unused, S00e34c10_Cache* cache, int mode);
};
// FUN_00e34d80 - hkaDeltaCompressedAnimation block decode launcher (Havok timer-wrapped)
// Per-TU private conventions: anim arrives in eax; callee FUN_00e349c0 takes dst in eax.
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long tlsIndex);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned int DAT_0126835c;
extern char DAT_010eb77c[];
extern char DAT_010c41f8[];
struct DqEvt
{
    const char* tag;
    unsigned int time;
    unsigned int unk08;
};
struct DqProf
{
    unsigned int unk00;
    DqEvt* head;
    unsigned int unk08;
    DqEvt* end;
};
struct DqArgs
{
    unsigned int m_uiItemCount;               // +0x00
    unsigned int m_iDofCount;                 // +0x04
    unsigned int m_offset;                    // +0x08
    hkUint8 m_ucSecondQuantizationParameter;  // +0x0c
    hkUint8 m_ucFirstQuantizationParameter;   // +0x0d
    unsigned int m_offsetIdxOff;              // +0x10
    unsigned int m_scaleIdxOff;               // +0x14
    unsigned int m_bitWidthIdxOff;            // +0x18
    unsigned int m_quantOff;                  // +0x1c
};
// src: HAVOK_LIB 0x00e349c0
static __declspec(noinline) void _decompress_00e349c0(float* dst, DqArgs args)
{
    float* out = dst + args.m_offset;
    const float* offs = (const float*)args.m_offsetIdxOff;
    const float* scale = (const float*)args.m_scaleIdxOff;
    float width = *(const float*)args.m_bitWidthIdxOff;
    const unsigned int* quant = (const unsigned int*)args.m_quantOff;
    unsigned int bitMask = (1u << args.m_ucFirstQuantizationParameter) - 1u;
    unsigned int i;
    for (i = 0; i < args.m_uiItemCount; i++)
    {
        unsigned int q = quant[i >> 2] >> (i & 31);
        out[i] = offs[i] + scale[i] * (float)((q & bitMask) * width);
    }
}
static void decompressBlockToCache_00e34d80(hkaDeltaCompressedAnimation* anim, unsigned int time, float* dst, unsigned int count);
// dummy callers negotiating the private conventions (never byte-compared)
extern "C" void dq_args_fill(DqArgs* out);
extern "C" float* dq_dst2_src(void);
hkaDeltaCompressedAnimation* volatile dq_anim_g;
unsigned int volatile dq_time_g;
float* volatile dq_dst_g;
unsigned int volatile dq_count_g;
void dq_call(void);
void dq_call2(void)
{
    DqArgs a;
    dq_args_fill(&a);
    _decompress_00e349c0(dq_dst2_src(), a);
}
struct AnimationStatistics
{
    unsigned int dynamicTranslation, dynamicRotation, dynamicScale, dynamicFloat;
    unsigned int clearTranslation, clearRotation, clearScale;
    unsigned int staticTranslation, staticRotation, staticScale, staticFloat;
    unsigned int transformDOFs, floatDOFs;
    float compressionRatio;
    AnimationStatistics()
    {
        dynamicTranslation = 0;
        dynamicRotation = 0;
        dynamicScale = 0;
        dynamicFloat = 0;
        clearTranslation = 0;
        clearRotation = 0;
        clearScale = 0;
        staticTranslation = 0;
        staticRotation = 0;
        staticScale = 0;
        staticFloat = 0;
        transformDOFs = 0;
        floatDOFs = 0;
        compressionRatio = 0.0f;
    }
};
void __cdecl hkaTrackAnalysis_calcStats(const unsigned short*, const unsigned short*, unsigned int, unsigned int,
                          AnimationStatistics*);
inline unsigned short swapMask(unsigned short value)
{
    union Input
    {
        unsigned short value;
        unsigned int bits;
    } input;
    union Output
    {
        unsigned short value;
        struct
        {
            unsigned char high, low;
        } bytes;
    } output;
    input.value = value;
    output.bytes.high = (unsigned char)(input.bits >> 8);
    output.bytes.low = (unsigned char)input.bits;
    return output.value;
}
inline float swapFloat(float value)
{
    union Input
    {
        float value;
        unsigned int bits;
    } input;
    union Output
    {
        float value;
        struct
        {
            unsigned char first, second, third, fourth;
        } bytes;
    } output;
    input.value = value;
    output.bytes.first = (unsigned char)(input.bits >> 24);
    output.bytes.second = (unsigned char)(input.bits >> 16);
    output.bytes.third = (unsigned char)(input.bits >> 8);
    output.bytes.fourth = (unsigned char)input.bits;
    return output.value;
}
struct AnimationEndian : hkaDeltaCompressedAnimation
{
    void hkaDeltaCompressedAnimation_handleEndian();
};
#include <string.h>
#include <windows.h>
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct ProfileRecord
{
    const char* name;
    unsigned int time;
    unsigned int secondaryTime;
    const char* object;
};
struct ProfileStream
{
    char* allocation;
    char* current;
    char* begin;
    char* end;
};
struct Chunk
{
    hkUint8* data;
    unsigned int size;
    hkUint8 offset;
};
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
struct DecodeParameters
{
    unsigned int numDOFs;
    int blockSize;
    int numValues;
    hkUint8 preserved;
    hkUint8 maxBitWidth;
    const float* offsets;
    const float* scales;
    const hkUint8* bitWidths;
    const hkUint8* data;
};
struct Quantization
{
    hkUint8 bitWidth;
    hkUint8 preserved;
    float scale;
    float offset;
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
union BlendStorage
{
    float inverseDelta;
    volatile unsigned int stamp;
};
struct SampleScratch
{
    union
    {
        TrackStatistics statistics;
        DecodeParameters parameters;
    };
    RecomposeParameters m_kRecomposeParameters;
};
struct ScratchAllocator
{
    char* current;
};
extern "C" ScratchAllocator* hkMemoryRouter_getInstance();
void __cdecl AnalyzeTrackWithZeroCount(const hkUint16*, const hkUint16*, unsigned int, unsigned int, TrackStatistics*);
void __cdecl hkaTrackAnalysis_recompose(const RecomposeParameters*, hkQsTransform*, float*);
void __cdecl DecodeQuantizedBlock(const hkUint8*, const Quantization*, float*, int);
void __cdecl PrefixSum(float*, int);
int __cdecl hkCalcQuantizedSize(int, const Quantization*);
// src: HAVOK_LIB 0x00e349c0
static void _decompress_00e349c0(float* output, DecodeParameters parameters)
{
    Quantization quantization;
    quantization.preserved = parameters.preserved;
    unsigned int byteOffset = 0;
    for (unsigned int i = 0; i < parameters.numDOFs; ++i)
    {
        quantization.offset = parameters.offsets[i];
        quantization.scale = parameters.scales[i];
        quantization.bitWidth = parameters.bitWidths ? parameters.bitWidths[i] : parameters.maxBitWidth;
        DecodeQuantizedBlock(parameters.data + byteOffset, &quantization, output, parameters.numValues);
        PrefixSum(output, parameters.numValues);
        output += parameters.blockSize;
        byteOffset += hkCalcQuantizedSize(parameters.numValues, &quantization);
    }
}
__forceinline void UpdateBlockTail(unsigned int f, const int& step, int total, int& result)
{
    int block = f / step;
    _ReadWriteBarrier();
    if ((block + 1) * step > total)
        result = total - block * step;
}
void __cdecl hkaDeltaCompressedAnimation_samplePartialWithDataChunks(unsigned int frame, float delta, unsigned int numTransforms, hkQsTransform* transforms,
                          unsigned int numFloats, float* floats, const Chunk* chunks, int chunkCount);

#include <xmmintrin.h>
extern float DAT_01012068;
extern __m128 DAT_010c71b0;

// @fnv 0x00e34d30
// src: HAVOK_SRC 0x00e34d30
void __stdcall hkaDeltaCompressedAnimation_sampleIndividualTransformTracks(int a, int b, unsigned int count, unsigned int* target)
{
    if (count > 0)
    {
        __m128 zero = _mm_setzero_ps();
        __m128 ones = _mm_load1_ps(&DAT_01012068);
        unsigned char* p = (unsigned char*)target + 0x20;

        do
        {
            _mm_store_ps((float*)(p - 0x20), zero);
            _mm_store_ps((float*)(p - 0x10), DAT_010c71b0);
            _mm_store_ps((float*)p, ones);

            p += 0x30;
            --count;
        } while (count != 0);
    }
}
