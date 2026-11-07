
// src/havok/animation/animation/animation/deltacompressed/hkadeltacompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/deltacompressed/hkadeltacompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaDeltaCompressedAnimation.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"

struct FUN_00e34b40_s {
    unsigned int hkaDeltaCompressedAnimation_getFullCacheKey(unsigned int arg);
};
// @fnv 0x00e34b40
// src: HAVOK_LIB 0x00e34b40
unsigned int FUN_00e34b40_s::hkaDeltaCompressedAnimation_getFullCacheKey(unsigned int arg)
{
    return (arg / *(unsigned int*)((char*)this + 0x2c)) + *(unsigned int*)((char*)this + 0x6c);
}

// @fnv 0x00e34a90
void __stdcall ZeroBuffer(int aiUnused1, int aiUnused2, unsigned int count, unsigned int* puiDst)
{
    if (count > 0)
    {
        unsigned int* p = puiDst;
        for (unsigned int i = 0; i < count; ++i)
            p[i] = 0;
    }
}

struct FnvCpu_FUN_00e34990_CpuObject {
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
// @fnv 0x00e34990
// src: GUESS 0x00e34990 (confidence: low)
int FnvCpu_FUN_00e34990_CpuObject::GetValue()
{
    return value;
}

struct FUN_00e349a0_class : hkaDeltaCompressedAnimation {
    int hkaDeltaCompressedAnimation_getNumDataChunks(unsigned int arg, int unused);
};

// @fnv 0x00e349a0
// src: HAVOK_SRC 0x00e349a0
int FUN_00e349a0_class::hkaDeltaCompressedAnimation_getNumDataChunks(unsigned int auiValue, int unused) {
    unsigned int blk = (unsigned int)m_iDofCount;
    unsigned int r = auiValue % blk;
    return (r + 1 == blk) ? 4 : 3;
}

struct AnimDispatch {
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
// Forwards frameTime, the stored section ids and the given source ids and count to Dispatch.
// @fnv 0x00e34a60
void AnimDispatch::DispatchToSections(float frameTime, int sourceA, int sourceB, int count)
{
    Dispatch(frameTime, m_sectionA, sourceA, m_sectionB, sourceB, count);
}

// stand-in for the extraction/reader object passed in (vtable slot 5 called)
struct e34b50_reader {
    virtual void q00();
    virtual void q04();
    virtual void q08();
    virtual void q0c();
    virtual void q10();
    virtual void read(void* dest, const void* src, int size);
};

struct FUN_00e34b50_s : hkaDeltaCompressedAnimation {
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

// For each block, calls reader->read with buf + 3, m_kCompressedData.m_data + i, and size.
// @fnv 0x00e34b50
// src: HAVOK_LIB 0x00e34b50
void FUN_00e34b50_s::hkaDeltaCompressedAnimation_clearAllCacheKeys(e34b50_reader* reader) {
    int buf;
    int blockSize = m_iDofCount;
    int count = vf08();
    int numBlocks = (count - 1) / blockSize + 1;
    int size = m_eQuantizationFormat.m_uiDynamicDofCount * blockSize * 4;
    int i;
    for (i = 0; i < numBlocks; i++) {
        reader->read((char*)&buf + 3, m_kCompressedData.m_data + i, size);
    }
}

struct CompressedBlockRange {
    unsigned int alignedStart;
    unsigned int alignedSize;
    unsigned char prefixBytes;
};
class DeltaAnimationStandIn : public hkaDeltaCompressedAnimation {
public:
    void GetCompressedBlockRange(unsigned int blockIndex, unsigned int blockCount, CompressedBlockRange* result);
};
// Computes the 16-byte aligned start and size of a compressed block, storing the result in the supplied CompressedBlockRange.
// @fnv 0x00e34bb0
void DeltaAnimationStandIn::GetCompressedBlockRange(unsigned int blockIndex, unsigned int blockCount, CompressedBlockRange* apRange)
{
    unsigned int start = m_uiCompressedBlockSize * blockIndex +
        (unsigned int)m_kCompressedData.m_data + m_uiNumDynamicDofs;
    unsigned char offset = (unsigned char)start & 15;
    apRange->alignedStart = start & ~15u;
    apRange->prefixBytes = offset;
    unsigned int actualSize = (blockIndex == blockCount - 1) ? m_iLastBlockSize : m_uiCompressedBlockSize;
    apRange->alignedSize = (actualSize + offset + 15) & ~15u;
}

struct BlkInfo {
    unsigned int a;
    unsigned int b;
    unsigned char c;
};

struct FUN_00e34c90_s : hkaDeltaCompressedAnimation {
    unsigned int GetCompressedBlockRange(unsigned int index, unsigned int count, BlkInfo* info);
    unsigned int GetMaxBlockSize();
};

// @fnv 0x00e34c90
unsigned int FUN_00e34c90_s::GetMaxBlockSize()
{
    int maxSize = 0;
    unsigned int numBlocks = (unsigned int)((m_iFrameCount + m_iDofCount - 1) / m_iDofCount);
    unsigned int i = 0;
    if (numBlocks > (unsigned int)maxSize) {
        unsigned int chunkSize = (m_uiNumDynamicDofs + 0xf) & 0xfffffff0u;
        do {
            BlkInfo info;
            info.a = 0;
            info.b = 0;
            info.c = 0;
            GetCompressedBlockRange(i, numBlocks, &info);
            int iCurSize = info.b + chunkSize + 0x80;
            if (i < numBlocks - 1) {
                GetCompressedBlockRange(i + 1, numBlocks, &info);
                iCurSize += info.b;
            }
            if (iCurSize > maxSize)
                maxSize = iCurSize;
            ++i;
        } while (i < numBlocks);
    }
    return (unsigned int)maxSize;
}

struct Source {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual int GetData(int a);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    int m_iElementIndex;
};
struct Stream {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void Write(int* pCount, int data, int size);
    virtual void v08(); virtual void v09(); virtual void v0a();
    virtual void Begin();
    virtual void End();
};
struct StreamHolder {
    Stream* m_pBinaryStream;
};

// Reads an element from src, computes its byte size, and writes it to the binary stream wrapped by h.
// @fnv 0x00e34ab0
// src: XBOX_PDB 0x00e34ab0
static __declspec(noinline) void releaseToCache_00e34ab0(Source* apSource, int aiElementIndex, StreamHolder* apStreamHolder, int aiElementCount)
{
    int data = apSource->GetData(aiElementIndex);
    int size = apSource->m_iElementIndex * aiElementCount * 4;
    apStreamHolder->m_pBinaryStream->Begin();
    apStreamHolder->m_pBinaryStream->Write(&aiElementCount, data, size);
    apStreamHolder->m_pBinaryStream->End();
}

void Caller_00e34ab0(Source* src, int a, StreamHolder* h, int count)
{
    releaseToCache_00e34ab0(src, a, h, count);
    releaseToCache_00e34ab0(src, count, h, a);
}

struct S00e34c10_Block {
    int unk00;
    int unk04;
    int unk08;
};

struct S00e34c10_Cache {
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

struct S00e34c10_Anim : hkaDeltaCompressedAnimation {
    void __thiscall GetCompressedBlockRange(unsigned int blockIndex, int numBlocks,
                                 S00e34c10_Block* apBlocks);
    void __thiscall hkaDeltaCompressedAnimation_getDataChunks(unsigned int frameIndex, int unused,
                                 S00e34c10_Cache* cache, int mode);
};

// Stores animation pointers and alignment in cache, computes block indices, and calls GetCompressedBlockRange to fill cache blocks.
// @fnv 0x00e34c10
// src: HAVOK_LIB 0x00e34c10
void __thiscall S00e34c10_Anim::hkaDeltaCompressedAnimation_getDataChunks(
    unsigned int frameIndex, int unused, S00e34c10_Cache* cache, int mode)
{
    cache->anim = this;
    cache->animAlign = *(unsigned char*)&cache->anim & 0xf;
    cache->unk04 = 0x80;

    cache->data = m_kCompressedData.m_data;
    cache->quantizedDataOffset = (int)((m_uiNumDynamicDofs + 0xf) & 0xfffffff0);
    cache->dataAlign = *(unsigned char*)&cache->data & 0xf;

    unsigned int blockIndex = frameIndex / (unsigned int)m_iDofCount;
    int numBlocks = (m_iFrameCount + m_iDofCount - 1) / m_iDofCount;

    GetCompressedBlockRange(blockIndex, numBlocks, &cache->blocks[0]);

    if (mode == 4) {
        unsigned int uiNextBlockIndex = (blockIndex + 1) % (unsigned int)numBlocks;
        GetCompressedBlockRange(uiNextBlockIndex, numBlocks, &cache->blocks[1]);
    }
}

// FUN_00e34d80 - hkaDeltaCompressedAnimation block decode launcher (Havok timer-wrapped)
// Per-TU private conventions: anim arrives in eax; callee FUN_00e349c0 takes dst in eax.

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long tlsIndex);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);

extern unsigned int DAT_0126835c;
extern char DAT_010eb77c[];
extern char DAT_010c41f8[];

struct DqArgs {
    unsigned int m_uiItemCount;          // +0x00
    unsigned int m_iDofCount;      // +0x04
    unsigned int m_offset;         // +0x08
    hkUint8 m_ucSecondQuantizationParameter;           // +0x0c
    hkUint8 m_ucFirstQuantizationParameter;         // +0x0d
    unsigned int m_offsetIdxOff;   // +0x10
    unsigned int m_scaleIdxOff;    // +0x14
    unsigned int m_bitWidthIdxOff; // +0x18
    unsigned int m_quantOff;       // +0x1c
};

// simplified stand-in body; never byte-compared, only its convention + clobber set matter
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
    for (i = 0; i < args.m_uiItemCount; i++) {
        unsigned int q = quant[i >> 2] >> (i & 31);
        out[i] = offs[i] + scale[i] * (float)((q & bitMask) * width);
    }
}

// Decompresses delta-compressed animation data into dst by calling FUN_00e349c0 with quantization parameters and offsets from anim.
// @fnv 0x00e34d80
// src: HAVOK_LIB 0x00e34d80
static __declspec(noinline) void decompressBlockToCache_00e34d80(hkaDeltaCompressedAnimation* anim, unsigned int time, float* dst, unsigned int count)
{
    {
        hkMonitorStream* prof = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (prof->m_end.m_storage < prof->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* ev = (hkMonitorStream::TimerCommand*)prof->m_end.val();
            ev->m_commandAndMonitor = DAT_010eb77c;
            _ReadWriteBarrier();
            volatile unsigned int stamped = (unsigned int)__rdtsc();
            ev->m_time0 = stamped;
            prof->m_end.m_storage = (char*)(ev + 1);
        }
    }
    {
        int numPoses = anim->m_iFrameCount;
        unsigned int q = time / (unsigned int)anim->m_iDofCount;
        int r = anim->m_iDofCount;
        if (r > numPoses) {
            r = numPoses;
            q = 0;
        }
        int end = anim->m_iDofCount * (int)q + r;
        if (end > numPoses) {
            r = numPoses - anim->m_iDofCount * (int)q;
        }
        unsigned char* data = (unsigned char*)anim->m_kCompressedData.m_data;
        DqArgs args;
        args.m_uiItemCount = count;
        args.m_offset = (unsigned int)r;
        args.m_ucSecondQuantizationParameter = anim->m_eQuantizationFormat.m_ucSecondQuantizationParameter;
        args.m_ucFirstQuantizationParameter = anim->m_eQuantizationFormat.m_ucFirstQuantizationParameter;
        args.m_offsetIdxOff = (unsigned int)(data + anim->m_eQuantizationFormat.m_uiOffsetIndexOffset);
        args.m_scaleIdxOff = (unsigned int)(data + anim->m_eQuantizationFormat.m_uiScaleIndexOffset);
        args.m_bitWidthIdxOff = (unsigned int)(data + anim->m_eQuantizationFormat.m_uiBitWidthIndexOffset);
        args.m_quantOff = (unsigned int)(data + (anim->m_uiCompressedBlockSize * q + anim->m_uiNumDynamicDofs));
        args.m_iDofCount = (unsigned int)anim->m_iDofCount;
        _decompress_00e349c0(dst, args);
    }
    {
        hkMonitorStream* prof = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if (prof->m_end.m_storage < prof->m_capacityMinus16.m_storage) {
            hkMonitorStream::TimerCommand* ev = (hkMonitorStream::TimerCommand*)prof->m_end.val();
            ev->m_commandAndMonitor = DAT_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned int stamped = (unsigned int)__rdtsc();
            ev->m_time0 = stamped;
            prof->m_end.m_storage = (char*)(ev + 1);
        }
    }
}

// dummy callers negotiating the private conventions (never byte-compared)
extern "C" void dq_args_fill(DqArgs* out);
extern "C" float* dq_dst2_src(void);

hkaDeltaCompressedAnimation* volatile dq_anim_g;
unsigned int volatile dq_time_g;
float* volatile dq_dst_g;
unsigned int volatile dq_count_g;

void dq_call(void)
{
    decompressBlockToCache_00e34d80(dq_anim_g, dq_time_g, dq_dst_g, dq_count_g);
}

void dq_call2(void)
{
    DqArgs a;
    dq_args_fill(&a);
    _decompress_00e349c0(dq_dst2_src(), a);
}

struct AnimationStatistics {
    unsigned int dynamicTranslation, dynamicRotation, dynamicScale, dynamicFloat;
    unsigned int clearTranslation, clearRotation, clearScale;
    unsigned int staticTranslation, staticRotation, staticScale, staticFloat;
    unsigned int transformDOFs, floatDOFs;
    float compressionRatio;
    AnimationStatistics() {
        dynamicTranslation = 0; dynamicRotation = 0; dynamicScale = 0; dynamicFloat = 0;
        clearTranslation = 0; clearRotation = 0; clearScale = 0;
        staticTranslation = 0; staticRotation = 0; staticScale = 0; staticFloat = 0;
        transformDOFs = 0; floatDOFs = 0;
        compressionRatio = 0.0f;
    }
};
void __cdecl hkaTrackAnalysis_calcStats(const unsigned short*, const unsigned short*, unsigned int, unsigned int, AnimationStatistics*);
inline unsigned short swapMask(unsigned short value) {
    union Input { unsigned short value; unsigned int bits; } input;
    union Output { unsigned short value; struct { unsigned char high, low; } bytes; } output;
    input.value = value;
    output.bytes.high = (unsigned char)(input.bits >> 8);
    output.bytes.low = (unsigned char)input.bits;
    return output.value;
}
inline float swapFloat(float value) {
    union Input { float value; unsigned int bits; } input;
    union Output { float value; struct { unsigned char first, second, third, fourth; } bytes; } output;
    input.value = value;
    output.bytes.first = (unsigned char)(input.bits >> 24);
    output.bytes.second = (unsigned char)(input.bits >> 16);
    output.bytes.third = (unsigned char)(input.bits >> 8);
    output.bytes.fourth = (unsigned char)input.bits;
    return output.value;
}
struct AnimationEndian : hkaDeltaCompressedAnimation {
    void hkaDeltaCompressedAnimation_handleEndian();
};
// Swaps byte order of masks, static values, and dynamic offsets and scales when the first data byte is nonzero.
// @fnv 0x00e35050
// src: HAVOK_LIB 0x00e35050
void AnimationEndian::hkaDeltaCompressedAnimation_handleEndian() {
    if (m_uiFramesPerBlock != 4) return;
    bool needsSwap = m_kCompressedData.m_data[0] != 0;
    bool& swapRef = needsSwap;
    if (!swapRef) return;
    unsigned short* masks = (unsigned short*)(m_kCompressedData.m_data + 4);
    unsigned short* currentMask = masks;
    for (int i = 0; i < m_iNumberOfFloatTracks + m_iNumTransformTracks; ++i, ++currentMask)
        *currentMask = swapMask(*currentMask);
    AnimationStatistics statistics;
    hkaTrackAnalysis_calcStats(masks, masks + m_iNumTransformTracks, m_iNumTransformTracks, m_iNumberOfFloatTracks, &statistics);
    int staticCount = statistics.dynamicTranslation + (statistics.dynamicRotation + (statistics.dynamicScale + statistics.dynamicFloat));
    float* staticValues = (float*)(m_kCompressedData.m_data + m_uiNumBlocks);
    for (int j = 0; j < staticCount; ++j, ++staticValues)
        *staticValues = swapFloat(*staticValues);
    unsigned int dynamicCount = statistics.staticTranslation + (statistics.staticRotation + (statistics.staticScale + statistics.staticFloat));
    float* offsets = (float*)(m_kCompressedData.m_data + m_eQuantizationFormat.m_uiOffsetIndexOffset);
    float* scales = (float*)(m_kCompressedData.m_data + m_eQuantizationFormat.m_uiScaleIndexOffset);
    for (unsigned int k = 0; k < dynamicCount; ++k, ++offsets, ++scales) {
        *offsets = swapFloat(*offsets);
        *scales = swapFloat(*scales);
    }
}

#include <string.h>
#include <windows.h>
namespace fnv_00e34e80 {
extern DWORD DAT_0126835c;
extern unsigned int* g_escape;
extern int g_never;

__forceinline void hkTimer(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* c = (hkMonitorStream::TimerCommand*)s->m_end.val();
        c->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc(); _ReadWriteBarrier(); c->m_time0 = *&t; if (0) memmove(&t, &t, 4);
        s->m_end.m_storage = (char*)(c + 1);
    }
}

struct ChunkAccessManager {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* retrieveChunk(hkUint32 key, int size);
    virtual void* allocateChunk(hkUint32 key, int size);
    virtual void unk14();
    virtual hkBool markForRead(hkUint32 key, int size);
    virtual void unk1c();
    virtual hkBool MarkForWrite(hkUint32 key, int size);
    virtual hkBool unmarkForWrite(hkUint32 key, int size);
    virtual hkBool isLocked(hkUint32 key, int size);
    virtual void lock();
    virtual void unlock();
};

struct hkaDeltaAnimExt : hkaDeltaCompressedAnimation {
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0a();
    virtual void vfunc0b();
    virtual void vfunc0c();
    virtual void vfunc0d();
    virtual void vfunc0e();
    virtual void vfunc0f();
};

struct ChunkCacheRef { ChunkAccessManager* m_pAccessManager; };

static void decompressBlockToCache_00e34d80(const hkaDeltaCompressedAnimation* anim, int block, void* out, int numPoses);

// Locks the chunk access manager, retrieves or allocates a chunk, and returns its data pointer or null.
// @fnv 0x00e34e80
// src: XBOX_PDB 0x00e34e80
static void* retrieveFromCache_00e34e80(ChunkCacheRef* cache, const hkaDeltaCompressedAnimation* anim, int block, int numPoses)
{
    hkTimer("TtcacheD");
    hkUint32 key = ((hkaDeltaAnimExt*)anim)->getBlockKey(block);
    int size = anim->m_iDofCount * numPoses * 4;
    ChunkAccessManager* c = cache->m_pAccessManager;
    c->lock();
    if (cache->m_pAccessManager->isLocked(key, size)) {
        cache->m_pAccessManager->unlock();
        hkTimer("Et");
        return 0;
    }
    void* data = cache->m_pAccessManager->retrieveChunk(key, size);
    if (data == 0) {
        data = cache->m_pAccessManager->allocateChunk(key, size);
        if (data == 0) {
            cache->m_pAccessManager->unlock();
            hkTimer("Et"); _ReadWriteBarrier(); 
            return 0;
        }
        cache->m_pAccessManager->markForRead(key, size);
        cache->m_pAccessManager->MarkForWrite(key, size);
        cache->m_pAccessManager->unlock();
        decompressBlockToCache_00e34d80(anim, block, data, numPoses);
        cache->m_pAccessManager->lock();
        cache->m_pAccessManager->unmarkForWrite(key, size);
        cache->m_pAccessManager->unlock();
    } else {
        cache->m_pAccessManager->markForRead(key, size);
        cache->m_pAccessManager->unlock();
    }
    hkTimer("Et");
    return data;
}

extern int g_sink;
// src: HAVOK_LIB 0x00e34d80
static void decompressBlockToCache_00e34d80(const hkaDeltaCompressedAnimation* anim, int block, void* out, int numPoses)
{
    hkTimer("TtcacheD");
    g_sink = anim->m_iDofCount + anim->m_iFrameCount * block + (int)out + numPoses + anim->m_uiNumDynamicDofs;
    hkTimer("Et");
}

void* SampleCaller(const hkaDeltaCompressedAnimation* anim, int block, int numPoses)
{
    ChunkCacheRef ref;
    ref.m_pAccessManager = (ChunkAccessManager*)anim->m_pExtractedMotion;
    return retrieveFromCache_00e34e80(&ref, anim, block, numPoses);
}
}  // namespace fnv_00e34e80

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct Chunk {
    hkUint8* data;
    unsigned int size;
    hkUint8 offset;
};
struct TrackStatistics {
    unsigned int staticTranslations, staticRotations, staticScales;
    unsigned int dynamicTranslations, dynamicRotations, dynamicScales;
    unsigned int totalStatic;
    unsigned int selectedTranslations, selectedRotations, selectedScales;
    unsigned int selectedFloats, totalDynamic, totalFloats;
    float weight;
    __forceinline void Reset() {
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
struct DecodeParameters {
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
struct Quantization {
    hkUint8 bitWidth;
    hkUint8 preserved;
    float scale;
    float offset;
};
struct RecomposeParameters {
    unsigned int numTransformTracks;
    unsigned int numFloatTracks;
    const hkUint16* transformMasks;
    const hkUint16* floatMasks;
    const float* staticTransforms;
    const float* staticFloats;
    const float* dynamicTransforms;
    const float* dynamicFloats;
};
union BlendStorage {
    float inverseDelta;
    volatile unsigned int stamp;
};
struct SampleScratch {
    union {
        TrackStatistics statistics;
        DecodeParameters parameters;
    };
    RecomposeParameters m_kRecomposeParameters;
};
struct ScratchAllocator { char* current; };
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
    for (unsigned int i = 0; i < parameters.numDOFs; ++i) {
        quantization.offset = parameters.offsets[i];
        quantization.scale = parameters.scales[i];
        quantization.bitWidth = parameters.bitWidths ? parameters.bitWidths[i] : parameters.maxBitWidth;
        DecodeQuantizedBlock(parameters.data + byteOffset, &quantization, output, parameters.numValues);
        PrefixSum(output, parameters.numValues);
        output += parameters.blockSize;
        byteOffset += hkCalcQuantizedSize(parameters.numValues, &quantization);
    }
}

__forceinline void UpdateBlockTail(unsigned int f, const int& step, int total, int& result) {
    int block = f / step;
    _ReadWriteBarrier();
    if ((block+1)*step > total) result = total - block*step;
}
// Decodes delta-compressed animation chunks, interpolates between frames, and recomposes transforms and floats into output buffers.
// @fnv 0x00e354b0
// src: HAVOK_LIB 0x00e354b0
void __cdecl hkaDeltaCompressedAnimation_samplePartialWithDataChunks(unsigned int frame, float delta, unsigned int numTransforms,
                         hkQsTransform* transforms, unsigned int numFloats, float* floats,
                         const Chunk* chunks, int chunkCount)
{
    volatile unsigned int stamp;
    SampleScratch scratch;
    const hkaDeltaCompressedAnimation* r = reinterpret_cast<const hkaDeltaCompressedAnimation*>(chunks[0].data + chunks[0].offset);
    const hkaDeltaCompressedAnimation* it = r;
    hkMonitorStream* pStream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (pStream->m_end.m_storage < pStream->m_capacityMinus16.m_storage) {
        volatile hkMonitorStream::TimerBeginListCommand* record = reinterpret_cast<volatile hkMonitorStream::TimerBeginListCommand*>(pStream->m_end.m_storage);
        record->m_commandAndMonitor = "LtSampleDeltaChunk";
        record->m_nameOfFirstSplit = "StStaticD";
        _ReadWriteBarrier();
        stamp = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        record->m_time0 = stamp;
        pStream->m_end.m_storage = reinterpret_cast<char*>(const_cast<hkMonitorStream::TimerBeginListCommand*>(record)) + 16;
    }
    const hkUint8* data = chunks[1].data + chunks[1].offset;
    const hkUint16* masks = reinterpret_cast<const hkUint16*>(data + r->m_uiFramesPerBlock);
    const float* staticDOFs = reinterpret_cast<const float*>(data + r->m_uiNumBlocks);
    unsigned int numDOFs = r->m_eQuantizationFormat.m_uiDynamicDofCount;
    const unsigned int uiNumTransformTracks = r->m_iNumTransformTracks;
    if (numTransforms != uiNumTransformTracks || numFloats != r->m_iNumberOfFloatTracks) {
        TrackStatistics& statistics = scratch.statistics;
        statistics.Reset();
        if (numFloats == 0) {
            AnalyzeTrackWithZeroCount(masks, masks + uiNumTransformTracks, numTransforms, 0, &statistics);
            numDOFs = statistics.selectedScales + statistics.selectedRotations + statistics.selectedTranslations;
        } else {
            AnalyzeTrackWithZeroCount(masks, masks + uiNumTransformTracks, uiNumTransformTracks, numFloats, &statistics);
            numDOFs = statistics.selectedScales + statistics.selectedFloats + statistics.selectedRotations + statistics.selectedTranslations;
        }
    }
    pStream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (pStream->m_end.m_storage < pStream->m_capacityMinus16.m_storage) {
        volatile hkMonitorStream::TimerBeginListCommand* record = reinterpret_cast<volatile hkMonitorStream::TimerBeginListCommand*>(pStream->m_end.m_storage);
        record->m_commandAndMonitor = "StDecompressDChunk";
        _ReadWriteBarrier();
        stamp = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        record->m_time0 = stamp;
        pStream->m_end.m_storage = reinterpret_cast<char*>(const_cast<hkMonitorStream::TimerBeginListCommand*>(record)) + 12;
    }
    BlendStorage blend;
    float& inverseDelta = blend.inverseDelta;
    inverseDelta = 1.0f - delta;
    unsigned int bufferValues = r->m_iDofCount * numDOFs;
    ScratchAllocator* c = hkMemoryRouter_getInstance();
    float* decompressed;
    decompressed = reinterpret_cast<float*>(c->current);
    int iAlignMask = ~127;
    c->current += (bufferValues * sizeof(float) + 127) & iAlignMask;
    c = hkMemoryRouter_getInstance();
    float* interpolated = reinterpret_cast<float*>(c->current);
    int tmp1 = ~127;
    c->current = c->current + ((numDOFs * sizeof(float) + 127) & tmp1);
    {
    DecodeParameters& parameters = scratch.parameters;
    {
    const hkaDeltaCompressedAnimation* __restrict countAnimation = r;
    parameters.numValues = countAnimation->m_iDofCount;
    if (parameters.numValues <= countAnimation->m_iFrameCount) {
        UpdateBlockTail(frame, countAnimation->m_iDofCount, countAnimation->m_iFrameCount, parameters.numValues);
    } else parameters.numValues = countAnimation->m_iFrameCount;
    }
    const hkaDeltaCompressedAnimation* __restrict idxAnimation = r;
    const hkaDeltaCompressedAnimation* __restrict byteAnimation = r;
    int decodeBlockSize = r->m_iDofCount;
    hkUint8 preserved = r->m_eQuantizationFormat.m_ucSecondQuantizationParameter;
    parameters.preserved = preserved;
    parameters.numDOFs = numDOFs;
    parameters.blockSize = decodeBlockSize;
    parameters.maxBitWidth = byteAnimation->m_eQuantizationFormat.m_ucFirstQuantizationParameter;
    parameters.offsets = reinterpret_cast<const float*>(data + idxAnimation->m_eQuantizationFormat.m_uiOffsetIndexOffset);
    parameters.scales = reinterpret_cast<const float*>(data + idxAnimation->m_eQuantizationFormat.m_uiScaleIndexOffset);
    parameters.bitWidths = data + idxAnimation->m_eQuantizationFormat.m_uiBitWidthIndexOffset;
    unsigned int i;
    if (chunkCount == 3) {
        parameters.data = chunks[2].data + chunks[2].offset;
        _decompress_00e349c0(decompressed, parameters);
        unsigned int blockSize = it->m_iDofCount;
        unsigned int value;
        float* destination = interpolated;
        value = frame % blockSize;
        for (i = 0; i < (unsigned int)numDOFs; ++i) {
            destination[i] = delta * decompressed[value + 1] + inverseDelta * decompressed[value];
            value += blockSize;
        }
    } else {
        parameters.data = chunks[2].data + chunks[2u].offset;
        _decompress_00e349c0(decompressed, parameters);
        unsigned int blockSize = it->m_iDofCount;
        unsigned int value;
        value = frame % blockSize;
        i = 0;
        while (i < numDOFs) {
            { interpolated[i] = inverseDelta * decompressed[value]; }
            value += blockSize;
            ++i;
        }
        parameters.data = chunks[3].data + chunks[3].offset;
        int block = (frame + 1) / blockSize;
        const hkaDeltaCompressedAnimation* k = it;
        if ((block + 1) * k->m_iDofCount > k->m_iFrameCount)
            parameters.numValues = k->m_iFrameCount - block * blockSize;
        _decompress_00e349c0(decompressed, parameters);
        unsigned int uiValue;
        uiValue = 0;
        const hkaDeltaCompressedAnimation* __restrict loopAnimation =
            it;
        i = 0;
        while (i < numDOFs) {
            interpolated[i] += delta * decompressed[uiValue];
            uiValue += loopAnimation->m_iDofCount;
            ++i;
        }
    }
    }
    pStream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (pStream->m_end.m_storage < pStream->m_capacityMinus16.m_storage) {
        volatile hkMonitorStream::TimerBeginListCommand* record = reinterpret_cast<volatile hkMonitorStream::TimerBeginListCommand*>(pStream->m_end.m_storage);
        record->m_commandAndMonitor = "StRecomposeDChunk";
        _ReadWriteBarrier();
        blend.stamp = (unsigned int)__rdtsc();
        { _ReadWriteBarrier(); }
        record->m_time0 = blend.stamp;
        pStream->m_end.m_storage = reinterpret_cast<char*>(const_cast<hkMonitorStream::TimerBeginListCommand*>(record)) + 12;
    }
    RecomposeParameters& m_kRecomposeParameters = scratch.m_kRecomposeParameters;
    m_kRecomposeParameters.numTransformTracks = numTransforms;
    m_kRecomposeParameters.numFloatTracks = numFloats;
    m_kRecomposeParameters.staticTransforms = staticDOFs;
    m_kRecomposeParameters.transformMasks = masks;
    m_kRecomposeParameters.dynamicTransforms = interpolated;
    const hkaDeltaCompressedAnimation* resultAnimation = it;
    m_kRecomposeParameters.staticFloats = staticDOFs + resultAnimation->m_uiOffsetDataOffset;
    m_kRecomposeParameters.dynamicFloats = interpolated + resultAnimation->m_uiScaleDataOffset;
    const hkInt32 iNumTransformTracks = resultAnimation->m_iNumTransformTracks;
    m_kRecomposeParameters.floatMasks = (masks + iNumTransformTracks);
    hkaTrackAnalysis_recompose(&m_kRecomposeParameters, transforms, floats);
    hkMemoryRouter_getInstance()->current = reinterpret_cast<char*>(interpolated);
    hkMemoryRouter_getInstance()->current = reinterpret_cast<char*>(decompressed);
    pStream = static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));
    if (pStream->m_end.m_storage < pStream->m_capacityMinus16.m_storage) {
        volatile hkMonitorStream::TimerBeginListCommand* record = reinterpret_cast<volatile hkMonitorStream::TimerBeginListCommand*>(pStream->m_end.m_storage);
        record->m_commandAndMonitor = "lt";
        _ReadWriteBarrier();
        blend.stamp = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        record->m_time0 = blend.stamp;
        pStream->m_end.m_storage = reinterpret_cast<char*>(const_cast<hkMonitorStream::TimerBeginListCommand*>(record)) + 12;
    }
}

namespace fnv_00e359f0 {
#include <windows.h>
#include <intrin.h>



extern "C" void _ReadWriteBarrier(void);

static __forceinline void TimerBeginList(const char* name, const char* first)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* p = s->m_end.m_storage;
    if (p < s->m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerBeginListCommand* h = (hkMonitorStream::TimerBeginListCommand*)p;
        h->m_commandAndMonitor = name;
        h->m_nameOfFirstSplit = first;
        DWORD t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        _ReadWriteBarrier();
        h->m_time0 = t;
        s->m_end = p + sizeof(hkMonitorStream::TimerBeginListCommand);
    }
}

static __forceinline void TimerSplit(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* p = s->m_end.m_storage;
    if (p < s->m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)p;
        h->m_commandAndMonitor = name;
        DWORD t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        _ReadWriteBarrier();
        h->m_time0 = t;
        s->m_end.m_storage = p + sizeof(hkMonitorStream::TimerCommand);
    }
}

struct HeapAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReleaseBlock(void* p, int size);
};
struct ThreadMemory {
    char* m_stackCur;
    int unk04;
    int unk08;
    int unk0c;
    HeapAllocator* m_pStreamAllocator;
};
ThreadMemory* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(HeapAllocator* alloc, void* arr, int cap, int elemSize);

struct LocalFloatArray {
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    float* m_pStackAllocation;

    __forceinline LocalFloatArray(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        ThreadMemory* r = hkMemoryRouter_getInstance();
        char* p = r->m_stackCur;
        r->m_stackCur = p + ((n * 4 + 0x7f) & ~0x7f);
        m_data = (float*)p;
        m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = (float*)p;
    }
    __forceinline void reserve(HeapAllocator* h, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int c2 = cap + cap;
            hkArrayUtil__reserve(h, this, n < c2 ? c2 : n, 4);
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        ThreadMemory* r = hkMemoryRouter_getInstance();
        reserve(r->m_pStreamAllocator, n);
        m_iElementCount = n;
    }
    __forceinline void destroy(HeapAllocator* h)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h->ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * 4);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void destroyLocal()
    {
        float* mem = m_pStackAllocation;
        if (mem == m_data)
            m_iElementCount = 0;
        hkMemoryRouter_getInstance()->m_stackCur = (char*)mem;
        ThreadMemory* r = hkMemoryRouter_getInstance();
        destroy(r->m_pStreamAllocator);
    }
};

struct MaskStats {
    int m_staticTranslations;
    int m_staticRotations;
    int m_staticScales;
    int m_dynamicTranslations;
    int m_dynamicRotations;
    int m_dynamicScales;
    int m_identity;
    int m_dynamicTranslationDOFs;
    int m_dynamicRotationDOFs;
    int m_dynamicScaleDOFs;
    int m_dynamicFloatDOFs;
    int m_staticFloatDOFs;
    int m_identityFloats;
    float m_fScalar;
    MaskStats()
        : m_staticTranslations(0), m_staticRotations(0), m_staticScales(0),
          m_dynamicTranslations(0), m_dynamicRotations(0), m_dynamicScales(0),
          m_identity(0), m_dynamicTranslationDOFs(0), m_dynamicRotationDOFs(0),
          m_dynamicScaleDOFs(0), m_dynamicFloatDOFs(0), m_staticFloatDOFs(0),
          m_identityFloats(0), m_fScalar(0.0f) {}
};
void __cdecl AnalyzeTrackWithZeroCount(const hkUint16* mask, const hkUint16* maskEnd, hkUint32 numT, hkUint32 numF, MaskStats* stats);

struct RecomposeJob {
    hkUint32 m_numQsTransforms;
    hkUint32 m_numFloats;
    const hkUint16* m_uiMask;
    const hkUint16* m_maskEnd;
    const float* m_static;
    const float* m_staticEnd;
    const float* m_dynamicFloats;
    const float* m_dynamicEnd;
};
void __cdecl hkaTrackAnalysis_recompose(RecomposeJob* job, hkQsTransform* transforms, float* floats);

struct ChunkCache {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual float* retrieveChunk(hkUint32 key, hkUint32 size);
    virtual float* allocateChunk(hkUint32 key, hkUint32 size);
    virtual void v14();
    virtual void release(hkUint32* data, hkUint32 key, hkUint32 size);
    virtual void storeChunk(hkUint32* data, hkUint32 key, hkUint32 size);
    virtual void markB(hkUint32* data, hkUint32 key, hkUint32 size);
    virtual void markC(hkUint32* data, hkUint32 key, hkUint32 size);
    virtual char* query(hkUint32* data, hkUint32 key, hkUint32 size);
    virtual void lock();
    virtual void unlock();
};

class DeltaSampler : public hkaDeltaCompressedAnimation {
public:
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual hkUint32 getPoseCount() const;
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual hkUint32 getChunkKey(hkUint32 frame) const;

    void hkaAnimation_getFrameAndDelta(float time, hkUint32* frame, float* delta) const;
    void hkaDeltaCompressedAnimation_samplePartialTracks(float time, hkUint32 maxNumTransformTracks, hkQsTransform* transformTracksOut,
                      hkUint32 maxNumFloatTracks, float* floatTracksOut, ChunkCache* cache) const;
};

void __cdecl _decompress_00e349c0(int a, int b, int c, int d, int e, int f, int g, int h);

static __declspec(noinline) void Decompress(const DeltaSampler* anim, hkUint32 frame, float* out, hkUint32 count)
{
    TimerSplit("StDecompressD");
    int block = anim->m_iDofCount;
    hkUint32 b = frame / block;
    int n = block;
    if (n > anim->m_iFrameCount) { n = anim->m_iFrameCount; b = 0; }
    _decompress_00e349c0(b * block, n, anim->m_eQuantizationFormat.m_uiDynamicDofCount, anim->m_kCompressedData.m_iElementCount, (int)out, count, 0, 0);
    TimerSplit("StInterpD");
}

static __declspec(noinline) const float* GetCachedChunkData(ChunkCache** cache, const DeltaSampler* anim, hkUint32 frame, hkUint32 numD)
{
    TimerSplit("StCache");
    hkUint32 key = anim->getChunkKey(frame);
    hkUint32 size = anim->m_iDofCount * numD * sizeof(float);
    (*cache)->lock();
    if (*(*cache)->query(&numD, key, size)) {
        (*cache)->unlock();
        TimerSplit("Et");
        return 0;
    }
    float* data = (*cache)->retrieveChunk(key, size);
    if (data == 0) {
        data = (*cache)->allocateChunk(key, size);
        if (data == 0) {
            (*cache)->unlock();
            TimerSplit("Et");
            return 0;
        }
        (*cache)->release(&numD, key, size);
        (*cache)->markB(&numD, key, size);
        (*cache)->unlock();
        Decompress(anim, frame, data, numD);
        (*cache)->lock();
        (*cache)->markC(&numD, key, size);
        (*cache)->unlock();
    } else {
        (*cache)->release(&numD, key, size);
        (*cache)->unlock();
    }
    TimerSplit("Et");
    return data;
}

static __declspec(noinline) void PutInCache(const DeltaSampler* anim, hkUint32 frame, ChunkCache** cache, hkUint32 numD)
{
    hkUint32 key = anim->getChunkKey(frame);
    hkUint32 size = anim->m_iDofCount * numD * 4;
    (*cache)->lock();
    (*cache)->storeChunk(&numD, key, size);
    (*cache)->unlock();
}


// src: HAVOK_LIB 0x00e2f7c0
__declspec(noinline) void DeltaSampler::hkaAnimation_getFrameAndDelta(float time, hkUint32* frame, float* delta) const
{
    hkUint32 last = getPoseCount() - 1;
    float position = time / m_fAnimationDuration * last;
    *frame = (hkUint32)position;
    if (*frame > last-1) { *frame = last-1; *delta = 1.0f; }
    else { *delta = position - *frame; }
}
// @fnv 0x00e359f0
// src: HAVOK_LIB 0x00e359f0
void DeltaSampler::hkaDeltaCompressedAnimation_samplePartialTracks(float time, hkUint32 maxNumTransformTracks, hkQsTransform* transformTracksOut,
                                hkUint32 maxNumFloatTracks, float* floatTracksOut, ChunkCache* cache) const
{
    TimerBeginList("LtSampleDelta", "StStaticD");

    const hkUint32 numD = m_eQuantizationFormat.m_uiDynamicDofCount;
    const hkUint16* staticMask = (const hkUint16*)(m_kCompressedData.m_data + m_uiFramesPerBlock);
    hkUint32 numDynamic = numD;

    if (maxNumTransformTracks != (hkUint32)m_iNumTransformTracks || maxNumFloatTracks != (hkUint32)m_iNumberOfFloatTracks) {
        MaskStats stats;
        if (maxNumFloatTracks == 0) {
            AnalyzeTrackWithZeroCount(staticMask, m_iNumTransformTracks + staticMask, maxNumTransformTracks, 0, &stats);
            numDynamic = stats.m_dynamicTranslationDOFs + stats.m_dynamicRotationDOFs + stats.m_dynamicScaleDOFs;
        } else {
            AnalyzeTrackWithZeroCount(staticMask, staticMask + m_iNumTransformTracks, m_iNumTransformTracks, maxNumFloatTracks, &stats);
            numDynamic = stats.m_dynamicTranslationDOFs + stats.m_dynamicRotationDOFs + stats.m_dynamicScaleDOFs + stats.m_dynamicFloatDOFs;
        }
    }

    TimerSplit("StDecompressD");

    float t; hkUint32 frame; hkaAnimation_getFrameAndDelta(time,&frame,&t);
    const float oneMinusDelta = 1.0f - t;

    LocalFloatArray dynamicDOFs(numDynamic);
    dynamicDOFs.SetSizeAndGrow(numDynamic);
    LocalFloatArray block(m_iDofCount * numDynamic);
    block.SetSizeAndGrow(m_iDofCount * numDynamic);

    const float* data = 0;
    if (cache)
        data = GetCachedChunkData(&cache, this, frame, numD);
    if (!data) {
        Decompress(this, frame, block.m_data, numDynamic);
        data = block.m_data;
    }

    TimerSplit("StInterpD");

    hkUint32 offset = frame % m_iDofCount;
    if (offset + 1 != (hkUint32)m_iDofCount) {
        for (hkUint32 i = 0; i < numDynamic; i++) {
            const float* p = data + offset;
            dynamicDOFs.m_data[i] = p[0] * oneMinusDelta + p[1] * t;
            offset += m_iDofCount;
        }
        if (data != block.m_data)
            PutInCache(this, frame, &cache, numD);
    } else {
        for (hkUint32 i = 0; i < numDynamic; i++) {
            dynamicDOFs.m_data[i] = data[offset] * oneMinusDelta;
            offset += m_iDofCount;
        }
        if (data != block.m_data)
            PutInCache(this, frame, &cache, numD);

        TimerSplit("StDecompressD");

        ++frame;
        hkUint32 offset2 = 0;
        const float* data2 = 0;
        if (cache)
            data2 = GetCachedChunkData(&cache, this, frame, numD);
        if (!data2) {
            Decompress(this, frame, block.m_data, numDynamic);
            data2 = block.m_data;
        }

        TimerSplit("StInterpD");

        for (hkUint32 i = 0; i < numDynamic; i++) {
            dynamicDOFs.m_data[i] += data2[offset2] * t;
            offset2 += m_iDofCount;
        }
        if (data2 != block.m_data)
            PutInCache(this, frame, &cache, numD);
    }

    TimerSplit("StRecomposeD");

    {
    const float* staticDOFs = (const float*)(m_kCompressedData.m_data + m_uiNumBlocks);
    RecomposeJob job;
    job.m_numQsTransforms = maxNumTransformTracks;
    job.m_numFloats = maxNumFloatTracks;
    job.m_static = staticDOFs;
    job.m_dynamicFloats = dynamicDOFs.m_data;
    job.m_uiMask = staticMask;
    job.m_staticEnd = staticDOFs + m_uiOffsetDataOffset;
    job.m_dynamicEnd = dynamicDOFs.m_data + m_uiScaleDataOffset;
    job.m_maskEnd = staticMask + m_iNumTransformTracks;
    hkaTrackAnalysis_recompose(&job, transformTracksOut, floatTracksOut);
    }

    TimerSplit("lt");

    block.destroyLocal();
    dynamicDOFs.destroyLocal();
}
}  // namespace fnv_00e359f0
