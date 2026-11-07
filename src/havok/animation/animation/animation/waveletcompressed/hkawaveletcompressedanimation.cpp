// src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaWaveletCompressedAnimation.h"
#include "../../../../../../include/hkBool.h"
// hkTimerCommand_hkawaveletcompressedanimation: local type (was include/hkTimerCommand.h, which had no evidence of one real class); no method of it is bound to a named game function
class hkTimerCommand_hkawaveletcompressedanimation
{
public:
    const char* m_pCommandName;
    unsigned int m_ticks;
    unsigned int m_auiShapeKeys;
};
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMonitorStream.h"

// Computes an offset from a and the first two bytes of b: ((a - b[1]) * b[0] + 7) / 8 + b[1] * 4.
// @fnv 0x00e51da0
// src: XBOX_PDB 0x00e51da0
int __cdecl hkCalcQuantizedSize(int aiValue, const char* apBytes)
{
    unsigned char x = (unsigned char)apBytes[1];
    unsigned char y = (unsigned char)apBytes[0];
    return ((aiValue - x) * y + 7) / 8 + x * 4;
}

// @fnv 0x00e2f9f0
// src: HAVOK_LIB 0x00e2f9f0
unsigned int __fastcall hkaWaveletCompressedAnimation_getFullCacheKey(hkaWaveletCompressedAnimation* self, int, unsigned int a)
{
    return a / *(unsigned int*)((char*)self + 0x2c) + *(int*)((char*)self + 0x64);
}

struct FUN_00e2f8c0_Class
{
    unsigned char m_auiShapeKeys[0x2c];
    unsigned int m_divisor;

    int hkaWaveletCompressedAnimation_getNumDataChunks(unsigned int value, int unused);
};

// @fnv 0x00e2f8c0
// src: HAVOK_SRC 0x00e2f8c0
int FUN_00e2f8c0_Class::hkaWaveletCompressedAnimation_getNumDataChunks(unsigned int value, int unused)
{
    return (value % m_divisor + 1 == m_divisor) ? 4 : 3;
}

// If count is greater than zero, writes count zero ints into dest.
// @fnv 0x00e2f950
// src: HAVOK_SRC 0x00e2f950
void __stdcall hkaWaveletCompressedAnimation_sampleIndividualFloatTracks(int aiUnused1, int aiUnused2, unsigned int count, void* dest)
{
    if (count > 0)
    {
        int* p = (int*)dest;
        for (unsigned int i = 0; i < count; i++)
            p[i] = 0;
    }
}

struct FUN_00e2f7c0_Class : hkaWaveletCompressedAnimation {
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

// @fnv 0x00e2f7c0
// src: HAVOK_LIB 0x00e2f7c0
void FUN_00e2f7c0_Class::hkaAnimation_getFrameAndDelta(float afTime, unsigned int* auiIndex, float* afFraction)
{
    unsigned int uiLastIndex = vf08() - 1;
    float x = afTime / m_fAnimationDuration * (float)uiLastIndex;
    unsigned int uiIndex = (unsigned int)x;
    *auiIndex = uiIndex;
    if (uiIndex > uiLastIndex - 1) {
        *auiIndex = uiLastIndex - 1;
        *afFraction = 1.0f;
        return;
    }
    *afFraction = x - (float)uiIndex;
}

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
// @fnv 0x00e2f8b0
// src: GUESS 0x00e2f8b0 (confidence: low)
int FUN_00e2f8b0_Obj::GetUnk28()
{
    return unk28;
}

class FUN_00e2f860 {
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

// Initializes solver parameters such as m_maxIterations, m_fScalar, and tolerance values to their default values.
// @fnv 0x00e2f860
FUN_00e2f860::FUN_00e2f860()
{
    m_maxIterations = 8;
    m_firstFreeIndex = 0xffff;
    m_flags = 0;
    m_fScalar = 0.1f;
    m_offset = 0.0f;
    m_linearTolerance = 0.01f;
    m_angularTolerance = 0.001f;
    m_linearLimit = 0.01f;
    m_fAngularLimit = 0.001f;
    m_enabled = false;
}

class ObjE2F8 {
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

// @fnv 0x00e2f8e0
// src: HAVOK_SRC 0x00e2f8e0
void ObjE2F8::hkaWaveletCompressedAnimation_sampleTracks(float fTime, int aiSecond, int aiFourth, int aiFifth)
{
    Process(fTime, m_iFirst, aiSecond, m_iSecond, aiFourth, aiFifth);
}

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

// @fnv 0x00e2f910
// src: XBOX_PDB 0x00e2f910
static __declspec(noinline) void releaseToCache(e2f910_Cls* anim, int arg1, e2f910_Stream* stream, int count)
{
    int r1 = anim->vf40(arg1);
    int size = anim->m_iDofCount * count;
    size *= 2;
    size *= 2;
    stream->ctrl->vf2C();
    stream->ctrl->vf1C(&count, r1, size);
    return stream->ctrl->vf30();
}

void e2f910_probe_caller(void)
{
    releaseToCache(e2f910_obj(), g_e2f910_a2, g_e2f910_stream, g_e2f910_a4);
}

// Cache-key flush interface: 0x00e2fa00 flushes successive buffer keys through hkBool slot 0x14; hkStreamWriter::write uses int slot 0x10.
class WaveletCacheKeyFlusher {
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual hkBool flushKey(const void* key, int chunkBytes);
};

class hkBufferE2FA {
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

    void Write(WaveletCacheKeyFlusher* cache);
};

// Flushes each animation block cache key derived from m_data, using blockBytes as the chunk size.
// @fnv 0x00e2fa00
void hkBufferE2FA::Write(WaveletCacheKeyFlusher* cache)
{
    int numBlocks = (getNumElements() - 1) / m_iDofCount + 1;
    int blockBytes = m_iElementIndex * m_iDofCount * 4;
    for (int i = 0; i < numBlocks; i++)
        cache->flushKey(m_data + i, blockBytes);
}

namespace fnv_00e300b0 {
struct WBlk {
    unsigned int count;
    int blockSize;
    unsigned int qHeader;
    float* offsets;
    float* scales;
    unsigned char* bitWidths;
    unsigned char* quantized;
};

struct BitDesc {
    unsigned char bits;
    unsigned char preserved;
};

struct WaveState {
    BitDesc desc;
    float scale;
    float off;
    int bits;
    int quant;
    int preserved;
};

int __cdecl hkCalcQuantizedSize(int a, const char* b);
void* __cdecl hkMemoryRouter_getInstance(void);
int __cdecl DecodeBlock(unsigned char* data, int* qp, unsigned char* block, int nbytes);
void __cdecl DecodeQuantizedBlock(unsigned char* block, BitDesc* desc, float* out, int n);
void __cdecl hkInverseWaveletTransform(float* out, int n);

// Processes each entry using its offsets, scales, and bit width, and writes float output.
// @fnv 0x00e300b0
// src: HAVOK_LIB 0x00e300b0
static __declspec(noinline) void _decompress(float* out, WBlk blk)
{
    int lv = 0;

    WaveState ws;
    ws.desc.preserved = (unsigned char)blk.qHeader;
    ws.desc.bits = (unsigned char)(blk.qHeader >> 8);
    ws.preserved = (unsigned char)blk.qHeader;

    int bytes = hkCalcQuantizedSize(blk.blockSize, (const char*)&ws.desc);
    unsigned char** slot = (unsigned char**)hkMemoryRouter_getInstance();
    unsigned char* base = *slot;
    *slot = base + ((bytes + 0x7f) & ~0x7f);

    unsigned char* data = blk.quantized;
    for (unsigned i = 0; i < blk.count; ++i) {
        ws.off = blk.offsets[i];
        ws.scale = blk.scales[i];
        if (blk.bitWidths)
            ws.desc.bits = blk.bitWidths[i];
        else
            ws.desc.bits = *((unsigned char*)&blk.qHeader + 1);

        int trackBytes = hkCalcQuantizedSize(blk.blockSize, (const char*)&ws.desc);
        int bits = ws.desc.bits;
        ws.bits = bits;
        lv = 1 << bits;
        ws.quant = (int)(unsigned)(-ws.off * lv / ws.scale);
        if (ws.quant == lv)
            --ws.quant;

        data += DecodeBlock(data, &ws.bits, base, trackBytes);
        DecodeQuantizedBlock(base, &ws.desc, out, blk.blockSize);
        hkInverseWaveletTransform(out, blk.blockSize);
        out += blk.blockSize;
    }

    *(unsigned char**)hkMemoryRouter_getInstance() = base;
}

extern "C" float* wblk_dst();
extern "C" unsigned wblk_u(int n);
extern "C" int wblk_i(int n);
extern "C" float* wblk_f(int n);
extern "C" unsigned char* wblk_p(int n);

void wblk_caller()
{
    WBlk blk;
    blk.count = wblk_u(0);
    blk.blockSize = wblk_i(1);
    blk.qHeader = wblk_u(2);
    blk.offsets = wblk_f(3);
    blk.scales = wblk_f(4);
    blk.bitWidths = wblk_p(5);
    blk.quantized = wblk_p(6);
    _decompress(wblk_dst(), blk);
}
}  // namespace fnv_00e300b0

extern unsigned char DAT_0126ef84;
void __cdecl hkaProcessFlyingColors(void*);
extern const float DAT_010ec880[];

struct QParam_00e51660 {
    unsigned char m_uiFirstQuantizationParameter;
    unsigned char m_ucSecondQuantizationParameter;
    unsigned short unk02;
    float m_vScale;
    float m_offset;
};

static __forceinline void Decode_e51660(const unsigned char* __restrict& in, const QParam_00e51660* qParam, float* out, int totalCount) {
    unsigned char bitWidth = qParam->m_uiFirstQuantizationParameter;
    int bw = bitWidth;
    unsigned int count = totalCount;
    float scale = DAT_010ec880[bw] * qParam->m_vScale;

    switch (bitWidth) {
    default: {
        unsigned int bitBuffer = 0;
        unsigned int mask = (unsigned short)((1 << bw) - 1);
        unsigned int i = 0;
        int bitsInRegister = 0;
        while (i < count) {
            if (bitsInRegister >= bw) {
                do {
                    if (i < count) {
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
        for (unsigned int i = 0; i < count; ++i) {
            unsigned short val = *in++;
            val |= (unsigned short)(*in++) << 8;
            out[i] = (val + 0.5) * scale + qParam->m_offset;
        }
        break;
    }
    case 8: {
        for (unsigned int i = 0; i < count; ++i) {
            out[i] = (*in++ + 0.5) * scale + qParam->m_offset;
        }
        break;
    }
    }
}

// Copies the leading m_ucSecondQuantizationParameter values as floats, then decodes the remaining values through Decode_e51660 into out.
// @fnv 0x00e51660
void __cdecl DecodeQuantizedBlock(const unsigned char* __restrict in, const QParam_00e51660* qParam, float* out, int totalCount) {
    int preserved = qParam->m_ucSecondQuantizationParameter;

    for (int i = 0; i < preserved; ++i) {
        union {
            float f;
            unsigned char b[4];
        } u;
        u.b[0] = *in++;
        u.b[1] = *in++;
        u.b[2] = *in++;
        u.b[3] = *in++;
        out[i] = u.f;
    }

    if (!DAT_0126ef84) {
        hkaProcessFlyingColors(&DAT_0126ef84);
        if (!DAT_0126ef84) {
            return;
        }
    }

    Decode_e51660(in, qParam, out += qParam->m_ucSecondQuantizationParameter, totalCount - qParam->m_ucSecondQuantizationParameter);
}

// Swaps the byte order of a float by reinterpreting its bits as a 32-bit integer and reversing the four bytes.
// @fnv 0x00e2f970
// src: GUESS 0x00e2f970 (confidence: high)
float __cdecl hkaWaveletCompressedAnimation_SwapFloatByteOrder(float f)
{
    union { float f; unsigned int u; unsigned char b[4]; } v;
    v.f = f;
    unsigned int u = v.u;
    v.b[0] = (unsigned char)(u >> 24);
    v.b[1] = (unsigned char)(u >> 16);
    v.b[2] = (unsigned char)(u >> 8);
    v.b[3] = (unsigned char)u;
    return v.f;
}

// @fnv 0x00e2f9d0
// src: GUESS 0x00e2f9d0 (confidence: high)
static __declspec(noinline) unsigned short hkaWaveletCompressedAnimation_SwapUnsignedShortByteOrder(unsigned short usValue)
{
    union U { unsigned short w; unsigned char b[2]; } u;
    u.b[0] = (unsigned char)(usValue >> 8);
    u.b[1] = (unsigned char)usValue;
    return u.w;
}
unsigned short volatile g_in; unsigned short g_out;
void caller() { g_out = hkaWaveletCompressedAnimation_SwapUnsignedShortByteOrder(g_in); }

#include <xmmintrin.h>
extern float DAT_01012068;
extern __m128 DAT_010c71b0;

// Companion quad-writer variant (scalar-load broadcast form) that shares the
// module with FUN_00e2fbc0; TU order matters for VC9's codegen state.
struct DestWrapPre { float* p; DestWrapPre(float* q) : p(q) {} };
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

struct DestWrap { float* p; DestWrap(float* q) : p(q) {} };
// Writes a repeating pattern of zero, DAT_010c71b0, and one into the float array at dest.p for count iterations.
// @fnv 0x00e2fbc0
// src: HAVOK_SRC 0x00e2fbc0
void __stdcall hkaWaveletCompressedAnimation_sampleIndividualTransformTracks(int, int, unsigned int count, DestWrap dest)
{
    if (count > 0)
    {
        __m128 zero = _mm_setzero_ps();
        __m128 one = _mm_set1_ps(DAT_01012068);
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

extern "C" void __cdecl _ReadWriteBarrier(void);
struct SwapCountsE2 {
    int a, b, c, d, e, f, g, h, i, j, k, l, m;
    float n;
    SwapCountsE2() : a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0), j(0), k(0), l(0), m(0), n(0.0f) {}
};
void __cdecl hkaTrackAnalysis_calcStats(unsigned short*, unsigned short*, int, int, SwapCountsE2*);
inline unsigned short SwapShortE2(unsigned short v) {
    union { unsigned short s; unsigned int u; } value;
    value.s = v;
    struct { unsigned char first, second; } b;
    b.first = (unsigned char)(*(volatile unsigned int*)&value >> 8);
    b.second = (unsigned char)value.u;
    return *(unsigned short*)&b;
}
inline float SwapFloatE2(float v) {
    unsigned int u = *(unsigned int*)&v;
    struct { unsigned char first, second, third, fourth; } b;
    b.first = (unsigned char)(u >> 24);
    b.second = (unsigned char)(u >> 16);
    b.third = (unsigned char)(u >> 8);
    b.fourth = (unsigned char)u;
    return *(float*)&b;
}
inline unsigned int SwapIntE2(unsigned int u) {
    struct { unsigned char first, second, third, fourth; } b;
    b.first = (unsigned char)(u >> 24);
    b.second = (unsigned char)(u >> 16);
    b.third = (unsigned char)(u >> 8);
    b.fourth = (unsigned char)u;
    return *(unsigned int*)&b;
}
// When frames-per-block is 4 and the first compressed-data byte is nonzero, swaps byte order in masks, static floats, offsets, scales, and indices.
// @fnv 0x00e2fc10
// src: HAVOK_LIB 0x00e2fc10
void __fastcall hkaWaveletCompressedAnimation_handleEndian(hkaWaveletCompressedAnimation* self) {
    if (self->m_uiFramesPerBlock == 4) {
        unsigned char* data = self->m_kCompressedData.m_data;
        bool flag = (*data != 0);
        _ReadWriteBarrier();
        if (flag != 0) {
            unsigned short* masks = (unsigned short*)(data + 4);
            unsigned short* p = masks;
            for (int x = 0; x < self->m_iNumTransformTracks + self->m_iNumberOfFloatTracks; ++x, ++p)
                *p = SwapShortE2(*p);
            SwapCountsE2 counts;
            int transforms = self->m_iNumTransformTracks;
            hkaTrackAnalysis_calcStats(masks, masks + transforms, transforms, self->m_iNumberOfFloatTracks, &counts);
            float* statics = (float*)(self->m_kCompressedData.m_data + self->m_uiNumBlocks);
            int count = counts.a + counts.b + counts.c + counts.d;
            for (int x = 0; x < count; ++x, ++statics)
                *statics = SwapFloatE2(*statics);
            int dynamicCount = counts.h + counts.i + counts.j + counts.k;
            float* offsets = (float*)(self->m_kCompressedData.m_data + self->m_eQuantizationFormat.m_uiOffsetIndexOffset);
            float* scales = (float*)(self->m_kCompressedData.m_data + self->m_eQuantizationFormat.m_uiScaleIndexOffset);
            for (unsigned int x = 0; x < (unsigned int)dynamicCount; ++x, ++offsets, ++scales) {
                *offsets = SwapFloatE2(*offsets);
                *scales = SwapFloatE2(*scales);
            }
            unsigned int* indices = (unsigned int*)(self->m_kCompressedData.m_data + self->m_uiIndexDataOffset);
            for (unsigned int x = 0; x < self->m_uiNumIndices; ++x, ++indices)
                *indices = SwapIntE2(*indices);
        }
    }
}

#include <string.h>
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern void* DAT_00fdf044;
typedef void* (__stdcall* S00e306d0_TlsFn)(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010eb358[];
extern const char str_010c41f8[];

struct S00e306d0_Args {
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
static __declspec(noinline) void _decompress(unsigned int x, S00e306d0_Args args) { unsigned int* p = (unsigned int*)x; p[0] = args.f00; p[1] = args.f18; p[2] = args.f04; }

static inline void timerBeginS00e306d0(hkMonitorStream* stream) {
        char* p = stream->m_end.val();
        if (p < stream->m_capacityMinus16.val()) {
            *(const char**)p = str_010eb358;
            _ReadWriteBarrier();
            unsigned int tb = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&tb;
            if (0) memmove(&tb, &tb, 4);
            p += 12;
            stream->m_end.m_storage = p;
        }
    }

static inline void timerEndS00e306d0(hkMonitorStream* stream) {
        char* p = stream->m_end.val();
        if (p < stream->m_capacityMinus16.val()) {
            *(const char**)p = str_010c41f8;
            _ReadWriteBarrier();
            unsigned int te = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&te;
            if (0) memmove(&te, &te, 4);
            p += 12;
            stream->m_end.m_storage = p;
        }
    }

struct S00e306d0_Obj {
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

// Calls timerBegin and timerEnd around a 12-byte write to b containing c, a computed address, and the divisor.
// @fnv 0x00e306d0
// src: HAVOK_LIB 0x00e306d0
static __declspec(noinline) void decompressBlockToCache(S00e306d0_Obj* self, unsigned int auiIndex, unsigned int auiTarget, unsigned int auiValue)
{
    S00e306d0_TlsFn tls = (S00e306d0_TlsFn)DAT_00fdf044;
    hkMonitorStream* s = (hkMonitorStream*)tls(DAT_0126835c);
    timerBeginS00e306d0(s);

    unsigned int base = self->m_ui64;
    unsigned int uiDivisor = self->m_ui2c;
    S00e306d0_Args args;
    args.f00 = auiValue;
    args.b08 = self->m_b31;
    args.b09 = self->m_b30;
    args.f0c = self->m_ui38 + base;
    args.f10 = self->m_ui3c + base;
    args.f14 = self->m_ui40 + base;
    unsigned int q = auiIndex / uiDivisor;
    args.f04 = uiDivisor;
    args.f18 = *(unsigned int*)(base + self->m_ui54 + q * 4) + self->m_ui5c + base;
    _decompress(auiTarget, args);

    s = (hkMonitorStream*)tls(DAT_0126835c);
    timerEndS00e306d0(s);
}

void S00e306d0_Wrap(S00e306d0_Obj* self, unsigned int a, unsigned int b, unsigned int c)
{
    decompressBlockToCache(self, a, b, c);
}

#include <windows.h>
namespace fnv_00e307b0 {
extern DWORD DAT_0126835c;
extern unsigned int* g_escape;
extern int g_never;

__forceinline void hkTimer(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage) {
        hkTimerCommand_hkawaveletcompressedanimation* c = (hkTimerCommand_hkawaveletcompressedanimation*)s->m_end.val();
        c->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc(); _ReadWriteBarrier(); c->m_ticks = *&t; if (0) memmove(&t, &t, 4);
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

struct hkaWaveletAnimExt : hkaWaveletCompressedAnimation {
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

static void decompressBlockToCache(const hkaWaveletCompressedAnimation* anim, int block, void* out, int numPoses);

// Locks the chunk cache and retrieves or allocates a wavelet animation block, decoding new allocations; returns null on failure.
// @fnv 0x00e307b0
// src: XBOX_PDB 0x00e307b0
static void* retrieveFromCache(ChunkCacheRef* cache, const hkaWaveletCompressedAnimation* anim, int block, int numPoses)
{
    hkTimer("TtcacheW");
    hkUint32 key = ((hkaWaveletAnimExt*)anim)->getBlockKey(block);
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
        decompressBlockToCache(anim, block, data, numPoses);
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
// src: HAVOK_LIB 0x00e306d0
static void decompressBlockToCache(const hkaWaveletCompressedAnimation* anim, int block, void* out, int numPoses)
{
    hkTimer("TtcacheW");
    g_sink = anim->m_iDofCount + anim->m_iFrameCount * block + (int)out + numPoses + anim->m_uiNumDynamicDofs;
    hkTimer("Et");
}

void* SampleCaller(const hkaWaveletCompressedAnimation* anim, int block, int numPoses)
{
    ChunkCacheRef ref;
    ref.m_pAccessManager = (ChunkAccessManager*)anim->m_pExtractedMotion;
    return retrieveFromCache(&ref, anim, block, numPoses);
}
}  // namespace fnv_00e307b0

struct hkDmaRefE2FA {
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

struct hkSlotE2FA {
    int unk00;
    int unk04;
    int unk08;
};

struct hkJobDescE2FA {
    hkDmaRefE2FA m_queue;
    hkDmaRefE2FA m_data;
    hkSlotE2FA m_slot;
    hkSlotE2FA m_nextSlot;
};

class hkQueueE2FA {
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

// Populates a job descriptor with queue, data, and slot references, optionally including the next slot when mode is 4.
// @fnv 0x00e2fac0
// src: HAVOK_LIB 0x00e2fac0
void hkQueueE2FA::hkaWaveletCompressedAnimation_getDataChunks(unsigned int offset, int unused, hkDmaRefE2FA* desc, int mode) const
{

    desc[0].m_ptr = this;
    desc[0].m_iElementCount = 0x70;
    desc[0].m_offset = (unsigned char)(unsigned int)desc[0].m_ptr &15;

    desc[1].m_ptr = m_data;
    desc[1].m_iElementCount = (m_iDataSize+15)&~15;
    desc[1].m_offset = (unsigned char)(unsigned int)desc[1].m_ptr &15;

    unsigned int slot = offset / m_slotSize;
    hkaWaveletCompressedAnimation_getBlockDataAndSize(slot, &desc[2]);

    if (mode == 4) {
        unsigned int nextSlot = (slot + 1) % m_numSlots;
        hkaWaveletCompressedAnimation_getBlockDataAndSize(nextSlot, &desc[3]);
    }
}

struct InfoE2FB {
    InfoE2FB() : m_iFirstValue(0), m_uiLogicalSize(0), m_bFlag(false) {}
    int m_iFirstValue;
    int m_uiLogicalSize;
    unsigned char m_bFlag;
};

class HostE2FB : public hkaWaveletCompressedAnimation {
public:
    void hkaWaveletCompressedAnimation_getBlockDataAndSize(unsigned int uiIndex, InfoE2FB* pkInfo);
    int hkaWaveletCompressedAnimation_getMaxSizeOfCombinedDataChunks();
};

// src: HAVOK_LIB 0x00e2fa60
__declspec(noinline) void HostE2FB::hkaWaveletCompressedAnimation_getBlockDataAndSize(unsigned int uiIndex, InfoE2FB* pkInfo)
{
    const unsigned int* blockOffsets = reinterpret_cast<const unsigned int*>(m_kCompressedData.m_data + m_uiIndexDataOffset);
    unsigned int address = reinterpret_cast<unsigned int>(m_kCompressedData.m_data + m_uiNumDynamicDofs) + blockOffsets[uiIndex];
    pkInfo->m_iFirstValue = address & ~15;
    pkInfo->m_bFlag = address & 15;
    if (uiIndex != m_uiNumIndices - 1)
        pkInfo->m_uiLogicalSize = blockOffsets[uiIndex + 1] - blockOffsets[uiIndex];
    else
        pkInfo->m_uiLogicalSize = m_uiNumDynamicTracks - blockOffsets[uiIndex];
    pkInfo->m_uiLogicalSize = (pkInfo->m_uiLogicalSize + static_cast<unsigned char>(address & 15) + 15) & ~15;
}

// Iterates over m_uiNumIndices, calling FUN_00e2fa60 to compute per-index sizes and returns the largest iSize found.
// @fnv 0x00e2fb30
// src: HAVOK_LIB 0x00e2fb30
int HostE2FB::hkaWaveletCompressedAnimation_getMaxSizeOfCombinedDataChunks()
{
    int iMax = 0;
    unsigned int i = 0;
    unsigned int uiLastIndex = m_uiNumIndices;
    if (i < uiLastIndex) {
        unsigned int uiBaseOffset = (m_uiNumDynamicDofs + 15) & ~15;
        --uiLastIndex;
        do {
            InfoE2FB kInfo;
            hkaWaveletCompressedAnimation_getBlockDataAndSize(i, &kInfo);
            int iSize = uiBaseOffset + kInfo.m_uiLogicalSize + 0x70;
            if (i < uiLastIndex) {
                hkaWaveletCompressedAnimation_getBlockDataAndSize(i + 1, &kInfo);
                iSize += kInfo.m_uiLogicalSize;
            }
            if (iSize > iMax)
                iMax = iSize;
            i++;
        } while (i < m_uiNumIndices);
    }
    return iMax;
}

struct ChunkRetry {
    const void* data;
    unsigned int size;
    unsigned char misalignment;
    void setStart(const void* p) {
        unsigned long bits = (unsigned long)p;
        misalignment = (unsigned char)(bits & 15);
        bits &= ~15UL;
        data = (const void*)bits;
    }
    void finish() { size = (size + misalignment + 15) & ~15U; }
};
struct AnimRetry : hkaWaveletCompressedAnimation {
    void hkaWaveletCompressedAnimation_getBlockDataAndSize(int block, ChunkRetry& chunk) const;
};
// Computes the aligned start and size of a compressed animation data block and stores them in the ChunkRetry.
// @fnv 0x00e2fa60
// src: HAVOK_LIB 0x00e2fa60
void AnimRetry::hkaWaveletCompressedAnimation_getBlockDataAndSize(int block, ChunkRetry& chunk) const {
    const unsigned int* offsets = (const unsigned int*)(m_kCompressedData.m_data + m_uiIndexDataOffset);
    const unsigned char* start = m_kCompressedData.m_data + m_uiNumDynamicDofs + offsets[block];
    chunk.setStart(start);
    if (block != m_uiNumIndices - 1) {
        chunk.size = offsets[block+1] - offsets[block];
    } else {
        chunk.size = m_uiNumDynamicTracks - offsets[block];
    }
    chunk.finish();
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" unsigned __int64 __rdtsc();

extern "C" unsigned long DAT_0126835c;
extern "C" void _ReadWriteBarrier();

struct ObjectTimerRecord:hkTimerCommand_hkawaveletcompressedanimation {const char* object;};


inline void monitorBegin(const char* name,const char* object,unsigned& stamp) {hkMonitorStream* stream=static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));if(stream->m_end.m_storage<stream->m_capacityMinus16.m_storage){ObjectTimerRecord* record=reinterpret_cast<ObjectTimerRecord*>(stream->m_end.val());record->m_pCommandName=name;record->object=object;_ReadWriteBarrier();stamp=(unsigned int)__rdtsc();record->m_ticks=static_cast<const volatile unsigned&>(stamp);stream->m_end=reinterpret_cast<char*>(record+1);}}

inline void monitorEarlySplit(const char* name,unsigned& stamp) {hkMonitorStream* stream=static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));if(stream->m_end.m_storage<stream->m_capacityMinus16.m_storage){hkTimerCommand_hkawaveletcompressedanimation* record=reinterpret_cast<hkTimerCommand_hkawaveletcompressedanimation*>(stream->m_end.val());record->m_pCommandName=name;_ReadWriteBarrier();stamp=(unsigned int)__rdtsc();record->m_ticks=static_cast<const volatile unsigned&>(stamp);stream->m_end=reinterpret_cast<char*>(record+1);}}

inline void monitorSplit(const char* name) {hkMonitorStream* stream=static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c));if(stream->m_end.m_storage<stream->m_capacityMinus16.m_storage){hkTimerCommand_hkawaveletcompressedanimation* record=reinterpret_cast<hkTimerCommand_hkawaveletcompressedanimation*>(stream->m_end.val());record->m_pCommandName=name;_ReadWriteBarrier();unsigned int stamp=(unsigned int)__rdtsc();record->m_ticks=static_cast<const volatile unsigned&>(stamp);stream->m_end=reinterpret_cast<char*>(record+1);}}



extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct Chunk {const hkUint8* data;unsigned int size;hkUint8 offset;const hkUint8* bytes() const {return data+offset;}};

struct WaveletParameters {unsigned int count;int blockSize;hkUint8 preserved,maxBitWidth;const float* offsets;const float* scales;const hkUint8* bitWidths;const hkUint8* data;};

struct Quantization {hkUint8 bitWidth,preserved;float scale,offset;};

struct PackedFormat {unsigned int bits,value,rawCount;};

int __cdecl hkCalcQuantizedSize(int,const Quantization*);

unsigned int __cdecl DecodeBlock(const float*,const PackedFormat*,float*,unsigned int);

void __cdecl DecodeQuantizedBlock(const float*,const Quantization*,float*,int);

void __cdecl hkInverseWaveletTransform(float*,int);

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

void __cdecl FUN_00e4e610(const hkUint16*,const hkUint16*,unsigned int,unsigned int,TrackStatistics*);

void __cdecl hkaTrackAnalysis_recompose(const RecomposeParameters*,hkQsTransform*,float*);

// src: HAVOK_LIB 0x00e300b0
static void _decompress(WaveletParameters parameters,float* output) {

 Quantization quantization;quantization.preserved=parameters.preserved;quantization.bitWidth=parameters.maxBitWidth;

 unsigned int bytes=hkCalcQuantizedSize(parameters.blockSize,&quantization);

 hkMemoryRouter* router=hkMemoryRouter_getInstance();float* temporary=reinterpret_cast<float*>(reinterpret_cast<char*&>(router->m_stack.m_next.m_storage));reinterpret_cast<char*&>(router->m_stack.m_next.m_storage)+=(bytes+127)&~127u;

 const hkUint8* data=parameters.data;

 for(unsigned int i=0;i<parameters.count;++i) {

  quantization.offset=parameters.offsets[i];quantization.scale=parameters.scales[i];quantization.bitWidth=parameters.bitWidths?parameters.bitWidths[i]:parameters.maxBitWidth;

  bytes=hkCalcQuantizedSize(parameters.blockSize,&quantization);

  PackedFormat format;format.bits=quantization.bitWidth;format.rawCount=parameters.preserved;

  int range=1<<quantization.bitWidth;format.value=(unsigned int)(-quantization.offset*range/quantization.scale);if(format.value==(unsigned int)range)--format.value;

  data+=DecodeBlock(reinterpret_cast<const float*>(data),&format,temporary,bytes);

  DecodeQuantizedBlock(temporary,&quantization,output,parameters.blockSize);hkInverseWaveletTransform(output,parameters.blockSize);output+=parameters.blockSize;

 }

 reinterpret_cast<char*&>(hkMemoryRouter_getInstance()->m_stack.m_next.m_storage)=reinterpret_cast<char*>(temporary);

}

// Decodes wavelet-compressed animation chunks, interpolates between frames by weight, and recomposes transform and float tracks.
// @fnv 0x00e30200
// src: HAVOK_LIB 0x00e30200
void __cdecl hkaWaveletCompressedAnimation_samplePartialWithDataChunks(unsigned int frame,float weight,unsigned int numTransforms,hkQsTransform* transforms,unsigned int numFloats,float* floats,const Chunk* chunks,int chunkCount) {

 const hkaWaveletCompressedAnimation* animation=reinterpret_cast<const hkaWaveletCompressedAnimation*>(chunks[0].data+chunks[0].offset);

 unsigned int total;
 monitorBegin("LtSampleWaveChunk","StStaticW",total);


 const hkUint8* staticStart=chunks[1].data+chunks[1].offset;

 const hkUint16* masks=reinterpret_cast<const hkUint16*>(staticStart+animation->m_uiFramesPerBlock);

 const float* staticDOFs=reinterpret_cast<const float*>(staticStart+animation->m_uiNumBlocks);

 unsigned int count=animation->m_eQuantizationFormat.m_uiDynamicDofCount;
 {
 unsigned int transformTracks=animation->m_iNumTransformTracks;

 if(numTransforms!=transformTracks||numFloats!=(unsigned int)animation->m_iNumberOfFloatTracks) {

  TrackStatistics statistics;statistics.Reset();

  if(numFloats==0){FUN_00e4e610(masks,masks+transformTracks,numTransforms,0,&statistics);count=statistics.selectedTranslations+statistics.selectedRotations+statistics.selectedScales;}

  else {FUN_00e4e610(masks,masks+transformTracks,transformTracks,numFloats,&statistics);count=statistics.selectedScales+statistics.selectedFloats+statistics.selectedRotations+statistics.selectedTranslations;}

 }

 }
 monitorEarlySplit("StDecompressWChunk",total);

 float inverseWeight=1.0f-weight;

 total=count*animation->m_iDofCount;
 hkMemoryRouter* router=hkMemoryRouter_getInstance();float* decoded=reinterpret_cast<float*>(reinterpret_cast<char*&>(router->m_stack.m_next.m_storage));reinterpret_cast<char*&>(router->m_stack.m_next.m_storage)+=(total*4+127)&~127u;

 router=hkMemoryRouter_getInstance();float* __restrict output=reinterpret_cast<float*>(reinterpret_cast<char*&>(router->m_stack.m_next.m_storage));reinterpret_cast<char*&>(router->m_stack.m_next.m_storage)+=(count*4+127)&~127u;

 {

  WaveletParameters parameters;parameters.count=count;parameters.blockSize=animation->m_iDofCount;parameters.preserved=animation->m_eQuantizationFormat.m_ucSecondQuantizationParameter;parameters.maxBitWidth=animation->m_eQuantizationFormat.m_ucFirstQuantizationParameter;

  parameters.offsets=reinterpret_cast<const float*>(staticStart+animation->m_eQuantizationFormat.m_uiOffsetIndexOffset);parameters.scales=reinterpret_cast<const float*>(staticStart+animation->m_eQuantizationFormat.m_uiScaleIndexOffset);parameters.bitWidths=staticStart+animation->m_eQuantizationFormat.m_uiBitWidthIndexOffset;

  if(chunkCount==3){
   parameters.data=chunks[2].data;parameters.data+=chunks[2].offset;_decompress(parameters,decoded);
   unsigned int stride=animation->m_iDofCount;unsigned int index=frame%stride;
   for(unsigned int i=0;i<count;++i){output[i]=inverseWeight*decoded[index]+weight*decoded[index+1];index+=stride;}
  }
  else {
   parameters.data=chunks[2].data;parameters.data+=chunks[2].offset;_decompress(parameters,decoded);
   {unsigned int index=frame%animation->m_iDofCount;
   for(unsigned int i=0;i<count;++i){output[i]=inverseWeight*decoded[index];index+=animation->m_iDofCount;}}
   parameters.data=chunks[3].data;parameters.data+=chunks[3].offset;_decompress(parameters,decoded);
   unsigned int index=0;for(unsigned int i=0;i<count;++i){output[i]+=weight*decoded[index];index+=animation->m_iDofCount;}
  }

 }

 monitorSplit("StRecomposeWChunk");

 RecomposeParameters m_kRecomposeParameters;m_kRecomposeParameters.numTransformTracks=numTransforms;m_kRecomposeParameters.numFloatTracks=numFloats;m_kRecomposeParameters.staticTransforms=staticDOFs;m_kRecomposeParameters.transformMasks=masks;m_kRecomposeParameters.dynamicTransforms=output;m_kRecomposeParameters.staticFloats=staticDOFs+animation->m_uiOffsetDataOffset;m_kRecomposeParameters.dynamicFloats=output+animation->m_uiScaleDataOffset;m_kRecomposeParameters.floatMasks=masks+animation->m_iNumTransformTracks;

 hkaTrackAnalysis_recompose(&m_kRecomposeParameters,transforms,floats);

 reinterpret_cast<char*&>(hkMemoryRouter_getInstance()->m_stack.m_next.m_storage)=reinterpret_cast<char*>(output);reinterpret_cast<char*&>(hkMemoryRouter_getInstance()->m_stack.m_next.m_storage)=reinterpret_cast<char*>(decoded);monitorSplit("lt");

}

extern char DAT_010eb3a8[];
extern char DAT_010eb338[];
extern char DAT_010eb398[];
extern char DAT_010eb38c[];
extern char DAT_010eb37c[];
extern char DAT_01076f38[];
extern char DAT_010eb370[];
extern char DAT_010c41f8[];

static inline void MonBeginE30(const char* name, const char* sub)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* p = s->m_end.val();
    if (p < s->m_capacityMinus16.val()) {
        ObjectTimerRecord* r = (ObjectTimerRecord*)p;
        r->m_pCommandName = name;
        r->object = sub;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        r->m_ticks = ticks;
        s->m_end.m_storage = p + 16;
    }
}
static inline void MonSplitE30(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* p = s->m_end.val();
    if (p < s->m_capacityMinus16.val()) {
        hkTimerCommand_hkawaveletcompressedanimation* r = (hkTimerCommand_hkawaveletcompressedanimation*)p;
        r->m_pCommandName = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        r->m_ticks = ticks;
        s->m_end.m_storage = p + 12;
    }
}

class CacheCtrlE30 {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void* vf0C(int key, int size);
    virtual void* vf10(int key, int size);
    virtual void vf14();
    virtual hkBool vf18(int key, int size);
    virtual void vf1C();
    virtual hkBool vf20(int key, int size);
    virtual hkBool vf24(int key, int size);
    virtual hkBool vf28(int key, int size);
    virtual void lock();
    virtual void unlock();
};

// src: XBOX_PDB 0x00e307b0
static __declspec(noinline) float* retrieveFromCache(CacheCtrlE30** cache, e2f910_Cls* anim, unsigned int frame, unsigned int numD)
{
    MonSplitE30(DAT_010eb370);
    int key = anim->vf40(frame);
    int size = anim->m_iDofCount * numD;
    size *= 2;
    size *= 2;
    (*cache)->lock();
    if ((*cache)->vf28(key, size).m_cBooleanValue) {
        (*cache)->unlock();
        MonSplitE30(DAT_010c41f8);
        return 0;
    }
    float* data = (float*)(*cache)->vf0C(key, size);
    if (data == 0) {
        data = (float*)(*cache)->vf10(key, size);
        if (data == 0) {
            (*cache)->unlock();
            MonSplitE30(DAT_010c41f8);
            return 0;
        }
        (*cache)->vf18(key, size);
        (*cache)->vf20(key, size);
        (*cache)->unlock();
        decompressBlockToCache((S00e306d0_Obj*)anim, frame, (unsigned int)data, numD);
        (*cache)->lock();
        (*cache)->vf24(key, size);
        (*cache)->unlock();
    } else {
        (*cache)->vf18(key, size);
        (*cache)->unlock();
    }
    MonSplitE30(DAT_010c41f8);
    return data;
}

struct TrackAnalysisE30 {
    int staticTranslations;
    int staticRotations;
    int staticScales;
    int staticFloats;
    int dynamicTranslations;
    int dynamicRotations;
    int dynamicScales;
    int translationDOFs;
    int rotationDOFs;
    int scaleDOFs;
    int floatDOFs;
    int transformTracks;
    int floatTracks;
    float tolerance;
    void clear() {
        staticTranslations = 0;
        staticRotations = 0;
        staticScales = 0;
        staticFloats = 0;
        dynamicTranslations = 0;
        dynamicRotations = 0;
        dynamicScales = 0;
        translationDOFs = 0;
        rotationDOFs = 0;
        scaleDOFs = 0;
        floatDOFs = 0;
        transformTracks = 0;
        floatTracks = 0;
        tolerance = 0.0f;
    }
};
void __cdecl FUN_00e4e610(const unsigned short*, const unsigned short*, int, int, TrackAnalysisE30*);


struct WaveletSamplerE30 : FUN_00e2f7c0_Class {
    void hkaWaveletCompressedAnimation_samplePartialTracks(float time, unsigned int transformCount, hkQsTransform* transforms,
                      unsigned int floatCount, float* floats, CacheCtrlE30* cache);
};

// @fnv 0x00e30980
// src: HAVOK_LIB 0x00e30980
void WaveletSamplerE30::hkaWaveletCompressedAnimation_samplePartialTracks(float time, unsigned int transformCount, hkQsTransform* transforms,
                                     unsigned int floatCount, float* floats, CacheCtrlE30* cache)
{
    MonBeginE30(DAT_010eb3a8, DAT_010eb338);
    union { TrackAnalysisE30 analysis; RecomposeParameters params; } u;
    unsigned int quantizedDOFs = m_eQuantizationFormat.m_uiDynamicDofCount;
    const unsigned short* masks = (const unsigned short*)(m_kCompressedData.m_data + m_uiFramesPerBlock);
    unsigned int dynamicDOFs = quantizedDOFs;
    int numTT = m_iNumTransformTracks;
    if (transformCount != numTT || floatCount != m_iNumberOfFloatTracks) {
        TrackAnalysisE30& analysis = u.analysis;
        analysis.clear();
        if (floatCount == 0) {
            FUN_00e4e610(masks, masks + numTT, transformCount, 0, &analysis);
            dynamicDOFs = analysis.rotationDOFs + analysis.scaleDOFs + analysis.translationDOFs;
        } else {
            FUN_00e4e610(masks, masks + numTT, numTT, floatCount, &analysis);
            dynamicDOFs = analysis.scaleDOFs + analysis.floatDOFs + analysis.rotationDOFs + analysis.translationDOFs;
        }
    }
    MonSplitE30(DAT_010eb398);
    unsigned int frame;
    float frac;
    hkaAnimation_getFrameAndDelta(time, &frame, &frac);
    float inverseDelta = (float)(1.0f - frac);
    int blockDOFs = m_iDofCount * dynamicDOFs;
    hkMemoryRouter* a = hkMemoryRouter_getInstance();
    float* block = (float*)reinterpret_cast<char*&>(a->m_stack.m_next.m_storage);
    reinterpret_cast<char*&>(a->m_stack.m_next.m_storage) = (char*)block + ((blockDOFs * 4 + 127) & ~127);
    a = hkMemoryRouter_getInstance();
    float* interpolated = (float*)reinterpret_cast<char*&>(a->m_stack.m_next.m_storage);
    reinterpret_cast<char*&>(a->m_stack.m_next.m_storage) = (char*)interpolated + ((dynamicDOFs * 4 + 127) & ~127);
    float* decompressed = block;
    if (!cache || !(decompressed = retrieveFromCache(&cache, (e2f910_Cls*)this, frame, quantizedDOFs))) {
        decompressBlockToCache((S00e306d0_Obj*)this, frame, (unsigned int)block, dynamicDOFs);
        decompressed = block;
    }
    MonSplitE30(DAT_010eb38c);
    unsigned int offset = frame % m_iDofCount;
    if (offset + 1 != m_iDofCount) {
        float delta = frac;
        for (unsigned int i = 0; i < dynamicDOFs; ++i) {
            interpolated[i] = decompressed[offset] * inverseDelta + decompressed[offset + 1] * delta;
            offset += m_iDofCount;
        }
        if (decompressed != block)
            releaseToCache((e2f910_Cls*)this, frame, (e2f910_Stream*)&cache, quantizedDOFs);
    } else {
        for (unsigned int i = 0; i < dynamicDOFs; ++i) {
            interpolated[i] = decompressed[offset] * inverseDelta;
            offset += m_iDofCount;
        }
        if (decompressed != block)
            releaseToCache((e2f910_Cls*)this, frame, (e2f910_Stream*)&cache, quantizedDOFs);
        MonSplitE30(DAT_010eb398);
        ++frame;
        offset = 0;
        decompressed = block;
        if (!cache || !(decompressed = retrieveFromCache(&cache, (e2f910_Cls*)this, frame, quantizedDOFs))) {
            decompressBlockToCache((S00e306d0_Obj*)this, frame, (unsigned int)block, dynamicDOFs);
            decompressed = block;
        }
        MonSplitE30(DAT_010eb38c);
        float delta = frac;
        for (unsigned int i = 0; i < dynamicDOFs; ++i) {
            interpolated[i] += decompressed[offset] * delta;
            offset += m_iDofCount;
        }
        if (decompressed != block)
            releaseToCache((e2f910_Cls*)this, frame, (e2f910_Stream*)&cache, quantizedDOFs);
    }
    MonSplitE30(DAT_010eb37c);
    {
    RecomposeParameters& params = u.params;
    params.numTransformTracks = transformCount;
    params.transformMasks = masks;
    params.numFloatTracks = floatCount;
    params.staticTransforms = (const float*)(m_kCompressedData.m_data + m_uiNumBlocks);
    params.staticFloats = params.staticTransforms + m_uiOffsetDataOffset;
    params.dynamicTransforms = interpolated;
    params.dynamicFloats = interpolated + m_uiScaleDataOffset;
    params.floatMasks = masks + m_iNumTransformTracks;
    hkaTrackAnalysis_recompose(&params, transforms, floats);
    }
    MonSplitE30(DAT_01076f38);
    reinterpret_cast<char*&>(hkMemoryRouter_getInstance()->m_stack.m_next.m_storage) = (char*)interpolated;
    reinterpret_cast<char*&>(hkMemoryRouter_getInstance()->m_stack.m_next.m_storage) = (char*)block;
}
