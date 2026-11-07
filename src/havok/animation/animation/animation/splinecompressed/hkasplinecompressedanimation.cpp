// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkaSplineCompressedAnimation.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMemoryAllocator.h"

typedef unsigned short hkUint16;
typedef unsigned long hkUlong;

// @fnv 0x00e33330
// src: HAVOK_LIB 0x00e33330
int hkaSplineCompressedAnimation::getSizeInBytes() const
{
    return m_data.m_iElementCount + sizeof(hkUint32) *
        (m_kFloatOffsets.m_iElementCount + m_kTransformOffsets.m_iElementCount +
         m_kFirstUInt32Array.m_iElementCount) + sizeof(hkaSplineCompressedAnimation);
}

extern bool DAT_0126efb8;
void __cdecl hkaProcessFlyingColors(bool*);

// @fnv 0x00e52fa0
int __cdecl GetIndexedValueWithOffset(int offset, const int* values, int index, int count)
{
    if (!DAT_0126efb8)
    {
        hkaProcessFlyingColors(&DAT_0126efb8);
        if (!DAT_0126efb8)
            return 0;
    }

    return offset + (count & 0x7fffffff) + values[index];
}

// @fnv 0x00e32ed0
// src: GUESS 0x00e32ed0 (confidence: high)
int __stdcall hkaSplineCompressedAnimation_ReturnConstant_3(int a1, int a2)
{
    return 3;
}

// samplePartialPose occupies vtable offset 0x10; the shared base currently names it vf04.
typedef int (__thiscall* SamplePartialPoseFn)(const hkaSplineCompressedAnimation*, float, int, int, int, int, int);

// Forwards time, both track counts and the three output/cache arguments to samplePartialPose.
// @fnv 0x00e32ee0
// src: HAVOK_SRC 0x00e32ee0
int __fastcall hkaSplineCompressedAnimation_sampleTracks(const hkaSplineCompressedAnimation* animation, void*, float time,
                            int parameterA, int parameterB, int parameterC)
{
    SamplePartialPoseFn sample = reinterpret_cast<SamplePartialPoseFn>(
        (*reinterpret_cast<void* const* const*>(animation))[4]);
    return sample(animation, time, animation->m_iNumTransformTracks, parameterA,
                  animation->m_iNumberOfFloatTracks, parameterB, parameterC);
}

typedef void(__cdecl* SplineDecodeFn)(int, void*);
extern int DAT_010eb3b8[];
extern int DAT_010eb3d0[];
extern SplineDecodeFn DAT_011be4b8[];
// @fnv 0x00e33030
void __cdecl DecodeSplineFrames(int* cursor, int type, int lastFrame, int firstFrame, int endFrame, void* output)
{
    int alignment = DAT_010eb3b8[type];
    *cursor = (*cursor + alignment - 1) & ~(alignment - 1);
    int stride = DAT_010eb3d0[type];
    if (firstFrame >= 0)
    {
        int byteOffset = (endFrame - firstFrame) * stride;
        SplineDecodeFn* volatile decodeSlot = &DAT_011be4b8[type];
        int remaining = firstFrame + 1;
        char* destination = static_cast<char*>(output);
        do
        {
            (*decodeSlot)(*cursor + byteOffset, destination);
            byteOffset += stride;
            destination += 16;
        } while (--remaining != 0);
    }
    *cursor += (lastFrame + 1) * stride;
}

struct hkaAnimationDataChunk
{
    const char* m_data;
    int m_iElementCount;
    unsigned char m_offset;

    void set(const void* p, int iSize)
    {
        unsigned char offset = static_cast<unsigned char>(reinterpret_cast<unsigned long>(p) & 15);
        m_data = reinterpret_cast<const char*>(reinterpret_cast<unsigned long>(p) & ~15);
        m_offset = offset;
        m_iElementCount = (offset + iSize + 15) & ~15;
    }
};

// @fnv 0x00e33350
void hkaSplineCompressedAnimation::GetDataChunks(unsigned int frame, float delta,
                                                     hkaAnimationDataChunk* dataChunks, int numDataChunks) const
    throw()
{
    dataChunks[0].m_data = reinterpret_cast<const char*>(this);
    // DMA chunks include padding to the next 16-byte boundary.
    dataChunks[0].m_iElementCount = (sizeof(hkaSplineCompressedAnimation) + 15) & ~15;

    int block;
    float blockTime;
    unsigned char quantizedTime;
    GetBlockAndTime(frame, delta, block, blockTime, quantizedTime);

    const int blockEnd = (block == m_iBlockCount - 1) ? m_data.GetLogicalSize() : m_kFirstUInt32Array.m_data[block + 1];
    const int blockSize = (blockEnd - m_kFirstUInt32Array.m_data[block] + 15) & ~15;

    dataChunks[1].set(m_data.begin() + m_kFirstUInt32Array.m_data[block], blockSize);
    {
        const void* p = m_kFloatBlockOffsets.begin() + block;
        unsigned char offset = static_cast<unsigned char>(reinterpret_cast<unsigned long>(p) & 15);
        dataChunks[2].m_offset = offset;
        dataChunks[2].m_data = reinterpret_cast<const char*>(reinterpret_cast<unsigned long>(p) & ~15);
        dataChunks[2].m_iElementCount = (offset + sizeof(unsigned int) + 15) & ~15;
    }
}

struct hkMathE334
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};

// The shared header has no declaration for this ECX-receiver query.
// @fnv 0x00e33400
// src: HAVOK_LIB 0x00e33400
int __fastcall hkaSplineCompressedAnimation_getMaxSizeOfCombinedDataChunks(const hkaSplineCompressedAnimation* animation)
{
    int iMaxGap = 0;
    int iPrev = animation->m_data.m_iElementCount;
    for (int i = animation->m_kFirstUInt32Array.m_iElementCount - 1; i >= 0; i--)
    {
        int iCurOffset = animation->m_kFirstUInt32Array.m_data[i];
        iMaxGap = hkMathE334::max2(iMaxGap, iPrev - iCurOffset);
        iPrev = iCurOffset;
    }
    return ((iMaxGap + 15) & ~15) + 0xa0;
}

template <typename T> inline T max2E347(T a, T b)
{
    return a > b ? a : b;
}
template <typename T> inline T min2E347(T a, T b)
{
    return a < b ? a : b;
}

// Computes the block index for a frame, clamps it, and outputs the block-local time and its quantized value.
// Keep the original out-of-line calls from GetDataChunks and the pose sampler.
// @fnv 0x00e34720
__declspec(noinline) void hkaSplineCompressedAnimation::GetBlockAndTime(unsigned int frame, float delta, int& blockOut,
                                                       float& blockTimeOut, unsigned char& quantizedTimeOut) const
    throw()
{
    blockOut = frame / (m_iMaxFramesPerBlock - 1);
    blockOut = max2E347(blockOut, 0);
    blockOut = min2E347(blockOut, m_iBlockCount - 1);
    const unsigned int firstFrameOfBlock = blockOut * (m_iMaxFramesPerBlock - 1);
    const float fLocalFrame = (frame - firstFrameOfBlock) + delta;
    blockTimeOut = fLocalFrame * m_fPerFrameDuration;
    quantizedTimeOut =
        static_cast<unsigned char>((blockTimeOut * m_fBlockInverseDuration) * (m_iMaxFramesPerBlock - 1));
}

void __cdecl DecodeSplineFrame(const unsigned char*& dataInOut, int quantization, float frameDuration, float time,
                               int numItems, void* out, int stride);

// Passes the inputs to DecodeSplineFrame, then aligns dataInOut to a 4-byte boundary.
// @fnv 0x00e33dc0
void hkaSplineCompressedAnimation::ExtractFrame(float time, int quantization, int numItems, void* out,
                                    const unsigned char*& dataInOut, int stride)
{
    DecodeSplineFrame(dataInOut, quantization, m_fPerFrameDuration, time, numItems, out, stride);
    dataInOut = (const unsigned char*)(((unsigned long)dataInOut + 3) & ~3);
}

// Per-component selects each output component from a or b based on the low and high nibbles of mask.
// @fnv 0x00e346a0
void __cdecl BlendVector4(unsigned char mask, const hkVector4& a, const hkVector4& b, hkVector4& out)
{
    int maskA = mask & 0xf;
    int maskB = (~mask >> 4) & ~mask & 0xf;
    if (maskA & 1)
        out.x = a.x;
    else if (maskB & 1)
        out.x = b.x;
    if (maskA & 2)
        out.y = a.y;
    else if (maskB & 2)
        out.y = b.y;
    if (maskA & 4)
        out.z = a.z;
    else if (maskB & 4)
        out.z = b.z;
    if (maskA & 8)
        out.w = a.w;
    else if (maskB & 8)
        out.w = b.w;
}

__declspec(noinline) int __cdecl FindKeyInterval(int n, int p, int u, const hkUint8* knots)
{
    hkUint8 value = (hkUint8)u;
    if (value >= knots[n + 1])
        return n;
    if (value <= knots[0])
        return p;
    int low = p;
    int high = n + 1;
    int mid = (low + high) / 2;
    while (value < knots[mid] || value >= knots[mid + 1])
    {
        if (value < knots[mid])
            high = mid;
        else
            low = mid;
        mid = (low + high) / 2;
    }
    return mid;
}

// Reads n and p, scales 2*p knots around the selected span into pfU, advances pDataInOut, and returns the span index.
// @fnv 0x00e32f10
// src: HAVOK_LIB 0x00e32f10
int __cdecl hkaSplineCompressedAnimation_readKnots(const hkUint8*& pDataInOut, int& iNOut, int& iPOut, int iU, hkReal fScale, hkReal* pfU)
{
    hkUint16 iN16 = *reinterpret_cast<const hkUint16*>(pDataInOut);
    pDataInOut += sizeof(hkUint16);
    int iN = iN16;
    hkUint8 iP8 = *pDataInOut;
    pDataInOut += sizeof(hkUint8);
    int iP = iP8;
    const hkUint8* pKnots = pDataInOut;
    int iNumKnots = iN + iP + 1;
    int iSpan = FindKeyInterval(iN, iP, iU, pKnots);
    for (int i = 0; i < 2 * iP; i++)
    {
        hkReal fKnot = pDataInOut[iSpan - iP + 1 + i];
        pfU[i] = fKnot * fScale;
    }
    pDataInOut = pKnots + iNumKnots + 1;
    iNOut = iN;
    iPOut = iP;
    return iSpan;
}

#include <xmmintrin.h>
struct ResultArg
{
    hkVector4* ptr;
    hkVector4* get() const
    {
        return ptr;
    }
};
extern const hkVector4 DAT_01268700;
void __cdecl hkaSplineCompressedAnimation_readNURBSCurve(unsigned int*, int, float, float, int, int, const hkVector4*, hkVector4*);
// Writes a constant vector when enabled is zero; otherwise calls FUN_00e33a30, then aligns cursor to a 4-byte boundary.
// @fnv 0x00e33e10
// The unused EDX argument preserves the thiscall entry point while using the shared receiver type.
void __fastcall EvaluateSpline(const hkaSplineCompressedAnimation* animation, void*, float time, int track,
                               int enabled, int block, unsigned int* cursor, ResultArg result)
{
    __m128 constant = _mm_load_ps(&DAT_01268700.x);
    if ((unsigned char)enabled == 0)
    {
        _mm_store_ps(&result.get()->x, constant);
        *cursor = (*cursor + 3) & ~3u;
        return;
    }
    hkVector4 vDefaults;
    _mm_store_ps(&vDefaults.x, constant);
    hkaSplineCompressedAnimation_readNURBSCurve(cursor, track, animation->m_fPerFrameDuration, time, enabled, block, &vDefaults, result.get());
    *cursor = (*cursor + 3) & ~3u;
}

extern hkVector4 DAT_01268720;

void __cdecl hkaSplineCompressedAnimation_readNURBSCurve(const hkUint8*& dataInOut, hkUint8 quantizedTime, hkReal frameDuration, hkReal u,
                          hkUint8 mask, int quantization, const hkVector4& I, hkVector4& out);

// Calls FUN_00e33a30 when mask is nonzero; otherwise assigns DAT_01268720 to out, then aligns dataInOut to a 4-byte boundary.
// Keep the original out-of-line calls from both track samplers.
// @fnv 0x00e33e90
// src: XBOX_PDB 0x00e33e90
__declspec(noinline) void hkaSplineCompressedAnimation::sampleScale(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask,
                                                    int quantization, const hkUint8*& dataInOut,
                                                    hkVector4& out) const
{
    if (!mask)
    {
        out = DAT_01268720;
    }
    else
    {
        hkaSplineCompressedAnimation_readNURBSCurve(dataInOut, quantizedTime, m_fPerFrameDuration, blockTime, mask, quantization,
                     hkVector4(DAT_01268720), out);
    }
    dataInOut = reinterpret_cast<const hkUint8*>((reinterpret_cast<hkUlong>(dataInOut) + 3) & ~3);
}

// Samples transform and float tracks from a spline animation at the given frame and delta, writing results to the output arrays.
// @fnv 0x00e33f90
// src: HAVOK_LIB 0x00e33f90
void hkaSplineCompressedAnimation_samplePartialWithDataChunks(unsigned int frameIndex, float delta, unsigned int maxNumTransformTracks,
                  hkQsTransform* transformsOut, unsigned int maxNumFloatTracks, float* floatsOut,
                  const hkaAnimationDataChunk* dataChunks, int numDataChunks)
{
    const hkaSplineCompressedAnimation* anim = reinterpret_cast<const hkaSplineCompressedAnimation*>(dataChunks[0].m_data);
    float blockTime;
    unsigned char quantizedTime;
    {
        int block;
        anim->GetBlockAndTime(frameIndex, delta, block, blockTime, quantizedTime);
    }
    {
        const unsigned char* mask =
            reinterpret_cast<const unsigned char*>(dataChunks[1].m_data) + dataChunks[1].m_offset;
        const unsigned char* dataPtr = mask + anim->m_iMaskAndQuantizationSize;
        for (unsigned int i = 0; i < maxNumTransformTracks; i++)
        {
            unsigned char quantizationTypes = *mask++;
            anim->EvaluateSpline(blockTime, quantizedTime, *mask++, quantizationTypes & 3, dataPtr,
                                 transformsOut[i].m_vTranslation);
            anim->ExtractFrame(blockTime, quantizedTime, *mask++, (quantizationTypes >> 2) & 15, dataPtr,
                               transformsOut[i].m_rotation);
            anim->sampleScale(blockTime, quantizedTime, *mask++, quantizationTypes >> 6, dataPtr,
                               transformsOut[i].m_vScale);
        }
    }
    {
        unsigned int floatOffset =
            *reinterpret_cast<const unsigned int*>(dataChunks[2].m_data + dataChunks[2].m_offset);
        const unsigned char* floatData =
            reinterpret_cast<const unsigned char*>(dataChunks[1].m_data) + dataChunks[1].m_offset + floatOffset;
        const unsigned char* floatMask = reinterpret_cast<const unsigned char*>(dataChunks[1].m_data) +
                                         dataChunks[1].m_offset + anim->m_iNumTransformTracks * 4;
        for (unsigned int uiFloatIndex = 0; uiFloatIndex < maxNumFloatTracks; uiFloatIndex++)
        {
            unsigned char ucFloatMask = *floatMask++;
            anim->hkaSplineCompressedAnimation_sampleFloat(blockTime, quantizedTime, ucFloatMask & 0xf9, (ucFloatMask >> 1) & 3, floatData,
                               floatsOut[uiFloatIndex]);
        }
    }
}

namespace fnv_00e34310 {
// Exe 0x00e34310 FUN_00e34310: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C" LocalM128 _mm_setzero_ps(void);

template <class T> inline T& hkArrayAtE343(hkArray<T>& a, int i)
{
    return a.m_data[i];
}
template <class T> inline const T& hkArrayAtE343(const hkArray<T>& a, int i)
{
    return a.m_data[i];
}

inline void hkSetZero4E343(hkVector4& v)
{
    *(LocalM128*)&v = _mm_setzero_ps();
}

const hkUint8* __cdecl GetIndexedValueWithOffset(const hkUint8* base, const hkUint32* offsets, hkUint32 block,
                                                 hkUint32 offset);

}  // namespace fnv_00e34310

// Evaluates spline-compressed transform tracks at the given time, writing translation, rotation, and scale into transformTracksOut for each valid track index.
// @fnv 0x00e34310
// src: HAVOK_SRC 0x00e34310
void hkaSplineCompressedAnimation::sampleIndividualTransformTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks,
                                                    hkQsTransform* transformTracksOut) const
{
    using namespace fnv_00e34310;
    hkUint32 frame;
    hkReal delta;
    hkaAnimation_getFrameAndDelta(time, frame, delta);

    hkUint32 block;
    hkReal blockTime;
    hkUint8 quantizedTime;
    GetBlockAndTime(frame, delta, block, blockTime, quantizedTime);

    for (hkUint32 i = 0; i < numTracks; i++)
    {
        const hkInt16 track = tracks[i];
        if (track >= 0 && track < m_iNumTransformTracks)
        {
            const hkUint8* dataStream =
                GetIndexedValueWithOffset(&hkArrayAtE343(m_data, 0), &hkArrayAtE343(m_kFirstUInt32Array, 0), block,
                                          hkArrayAtE343(m_kTransformOffsets, block * m_iNumTransformTracks + track));
            const hkUint8* mask = GetIndexedValueWithOffset(&hkArrayAtE343(m_data, 0),
                                                            &hkArrayAtE343(m_kFirstUInt32Array, 0), block, 4 * track);
            const hkUint8 quantizationTypes = mask[0];
            EvaluateSpline(blockTime, quantizedTime, mask[1], quantizationTypes & 3, dataStream,
                           transformTracksOut[i].m_vTranslation);
            ExtractFrame(blockTime, quantizedTime, mask[2], (quantizationTypes >> 2) & 0xf, dataStream,
                         transformTracksOut[i].m_rotation);
            sampleScale(blockTime, quantizedTime, mask[3], quantizationTypes >> 6, dataStream,
                         transformTracksOut[i].m_vScale);
        }
        else
        {
            hkSetZero4E343(transformTracksOut[i].m_vTranslation);
            hkSetZero4E343(reinterpret_cast<hkVector4&>(transformTracksOut[i].m_rotation));
            hkSetZero4E343(transformTracksOut[i].m_vScale);
        }
    }
}

template <class T> inline T& hkArrayAtE344(hkArray<T>& a, int i)
{
    return a.m_data[i];
}
template <class T> inline const T& hkArrayAtE344(const hkArray<T>& a, int i)
{
    return a.m_data[i];
}

const hkUint8* __cdecl GetIndexedValueWithOffset(const hkUint8* base, const hkUint32* offsets, hkUint32 block,
                                                 hkUint32 offset);

// @fnv 0x00e34490
// src: HAVOK_LIB 0x00e34490
void hkaSplineCompressedAnimation::sampleIndividualFloatTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks,
                                                    hkReal* floatTracksOut) const
{
    hkUint32 frame;
    hkReal delta;
    hkaAnimation_getFrameAndDelta(time, frame, delta);

    hkUint32 block;
    hkReal blockTime;
    hkUint8 quantizedTime;
    GetBlockAndTime(frame, delta, block, blockTime, quantizedTime);

    for (hkUint32 i = 0; i < numTracks; i++, floatTracksOut++)
    {
        const hkInt16 track = tracks[i];
        if (track >= 0 && track < m_iNumberOfFloatTracks)
        {
            const hkUint8* dataStream =
                GetIndexedValueWithOffset(&hkArrayAtE344(m_data, 0), &hkArrayAtE344(m_kFirstUInt32Array, 0), block,
                                          hkArrayAtE344(m_kFloatOffsets, block * m_iNumberOfFloatTracks + track));
            const hkUint8 mask =
                *GetIndexedValueWithOffset(&hkArrayAtE344(m_data, 0), &hkArrayAtE344(m_kFirstUInt32Array, 0), block,
                                           4 * m_iNumTransformTracks + track);
            hkaSplineCompressedAnimation_sampleFloat(blockTime, quantizedTime, mask & 0xf9, (mask >> 1) & 3, dataStream, *floatTracksOut);
        }
        else
        {
            *floatTracksOut = 0.0f;
        }
    }
}

extern void* __cdecl hkMemoryRouter_getInstance(void);
extern void __cdecl UpdateFields_00dfb5a0(int value);
extern void __cdecl FUN_00c905b0(void);

extern int DAT_010de0ec;
extern int DAT_0102e388;

// hkMemoryRouter::heap is the allocator pointer at offset 0x10.
struct SplineMemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_heap;
};

// Calls the hkaAnimation destructor at 0x00dfb720 with its receiver in ECX.
void __fastcall DestroyAnimationBase(hkaAnimation* animation);

// @fnv 0x00e345a0
void __fastcall DestroySplineCompressedAnimation(hkaSplineCompressedAnimation* animation)
{
    int zero = 0;
    int flag = 0x80000000;

    *reinterpret_cast<int**>(animation) = &DAT_010de0ec;

    {
        SplineMemoryRouter* manager = static_cast<SplineMemoryRouter*>(hkMemoryRouter_getInstance());
        hkMemoryAllocator* track = manager->m_heap;

        int val = animation->m_data.m_iCapacityState;
        animation->m_data.m_iElementCount = zero;
        if ((val & flag) == 0)
        {
            track->bufFree(animation->m_data.m_data, val & 0x3FFFFFFF);
        }
        animation->m_data.m_data = 0;
        animation->m_data.m_iCapacityState = flag;
    }

    {
        SplineMemoryRouter* manager = static_cast<SplineMemoryRouter*>(hkMemoryRouter_getInstance());
        hkMemoryAllocator* track = manager->m_heap;

        int val = animation->m_kFloatOffsets.m_iCapacityState;
        animation->m_kFloatOffsets.m_iElementCount = zero;
        if ((val & flag) == 0)
        {
            track->bufFree(animation->m_kFloatOffsets.m_data, (val & 0x3FFFFFFF) * 4);
        }
        animation->m_kFloatOffsets.m_data = 0;
        animation->m_kFloatOffsets.m_iCapacityState = flag;
    }

    {
        SplineMemoryRouter* manager = static_cast<SplineMemoryRouter*>(hkMemoryRouter_getInstance());
        hkMemoryAllocator* track = manager->m_heap;

        int val = animation->m_kTransformOffsets.m_iCapacityState;
        animation->m_kTransformOffsets.m_iElementCount = zero;
        if ((val & flag) == 0)
        {
            track->bufFree(animation->m_kTransformOffsets.m_data, (val & 0x3FFFFFFF) * 4);
        }
        animation->m_kTransformOffsets.m_data = 0;
        animation->m_kTransformOffsets.m_iCapacityState = flag;
    }

    {
        SplineMemoryRouter* manager = static_cast<SplineMemoryRouter*>(hkMemoryRouter_getInstance());
        hkMemoryAllocator* track = manager->m_heap;

        int val = animation->m_kFloatBlockOffsets.m_iCapacityState;
        animation->m_kFloatBlockOffsets.m_iElementCount = zero;
        if ((val & flag) == 0)
        {
            track->bufFree(animation->m_kFloatBlockOffsets.m_data, (val & 0x3FFFFFFF) * 4);
        }
        animation->m_kFloatBlockOffsets.m_data = 0;
        animation->m_kFloatBlockOffsets.m_iCapacityState = flag;
    }

    {
        SplineMemoryRouter* manager = static_cast<SplineMemoryRouter*>(hkMemoryRouter_getInstance());
        hkMemoryAllocator* track = manager->m_heap;

        int val = animation->m_kFirstUInt32Array.m_iCapacityState;
        animation->m_kFirstUInt32Array.m_iElementCount = zero;
        if ((val & flag) == 0)
        {
            track->bufFree(animation->m_kFirstUInt32Array.m_data, (val & 0x3FFFFFFF) * 4);
        }
        animation->m_kFirstUInt32Array.m_data = 0;
        animation->m_kFirstUInt32Array.m_iCapacityState = flag;
    }

    DestroyAnimationBase(animation);
}

#include <xmmintrin.h>
namespace fnv_00e33960 {
extern const unsigned int DAT_010eb3b8[];
extern const unsigned int DAT_010eb3d0[];

typedef void (*UnpackFunc)(const void*, hkVector4*);
extern const UnpackFunc DAT_011be4b8[];

typedef void (*SplineEvalFunc)(float, int, const void*, const void*, hkVector4*);
extern const SplineEvalFunc DAT_011be4d0[];

extern const __m128 DAT_010c71b0;

int __cdecl hkaSplineCompressedAnimation_readKnots(const unsigned char** data, int* b, int* a, int a2, float a3, void* knots);
void __cdecl DecodeSplineFrames(const unsigned char** data, int type, int b, int a, int result,
                                hkVector4* controlPoints);

struct SplineKnots
{
    float k0, k1, k2, k3, k4, k5;
};

// Uses mask bits to spline-evaluate, type-specifically unpack, or load a constant vector.
// @fnv 0x00e33960
void __cdecl DecodeSplineFrame(const unsigned char** data, int a2, float a3, float a4, unsigned char mask, int type,
                               hkVector4* out)
{
    if (mask & 0xF0)
    {
        int a;
        int b;
        SplineKnots knots;
        __declspec(align(16)) hkVector4 controlPoints[4];

        int result = hkaSplineCompressedAnimation_readKnots(data, &b, &a, a2, a3, &knots);
        int a_val = a;
        DecodeSplineFrames(data, type, b, a_val, result, controlPoints);
        DAT_011be4d0[a_val](a4, a_val, &knots, controlPoints, out);
        return;
    }

    if (mask & 0x0F)
    {
        unsigned int align = DAT_010eb3b8[type];
        const unsigned char* cur = *data;
        const unsigned char* ptr = (const unsigned char*)(((uintptr_t)cur + align - 1) & ~(align - 1));
        *data = ptr;
        DAT_011be4b8[type](ptr, out);
        *data += DAT_010eb3d0[type];
        return;
    }

    *(__m128*)out = DAT_010c71b0;
}
}  // namespace fnv_00e33960

// The shared header has no declaration for this ECX-receiver query.
// @fnv 0x00e32ec0
// src: GUESS 0x00e32ec0 (confidence: medium)
int __fastcall hkaSplineCompressedAnimation_GetFrameCount(const hkaSplineCompressedAnimation* animation)
{
    return animation->m_iFrameCount;
}
