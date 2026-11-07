
// hkasplinecompressedanimation_ctx_variant.cpp: context variant of src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkaSplineCompressedAnimation.h"
#include "../../../../../../include/hkVector4.h"

int __cdecl GetIndexedValueWithOffset(int offset, const int* values, int index, int count);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern "C" void _ReadWriteBarrier(void);

struct S00e340e0_Cmd { const char* name; unsigned int ticks; unsigned int extra; };
struct S00e340e0_Mon {
    char* m_kRayStart;
    S00e340e0_Cmd* m_kRayEnd;
    char* m_pRayCursor;
    S00e340e0_Cmd* m_pCurrentCommand;
};

static __forceinline void S00e340e0_timer(const char* name)
{
    S00e340e0_Mon* mon = (S00e340e0_Mon*)TlsGetValue(DAT_0126835c);
    S00e340e0_Cmd* e = mon->m_kRayEnd;
    if (e < mon->m_pCurrentCommand)
    {
        e->name = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        e->ticks = ticks;
        mon->m_kRayEnd = e + 1;
    }
}

int __stdcall S00e340e0_vnum(const void* self);
int __stdcall S00e340e0_read(const unsigned char* p, float t, unsigned char qt, unsigned char q, int type, void* out);

// The shared header supplies the complete animation layout but not these sampling entry points.
// This fieldless adapter adds their declarations without duplicating animation storage.
struct SplineAnimationSampler : hkaSplineCompressedAnimation {
    __declspec(noinline) void hkaAnimation_getFrameAndDelta(float time, unsigned int& frame, float& delta) const;
    __declspec(noinline) void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut, unsigned char& quantizedTimeOut) const;
    __declspec(noinline) void EvaluateSpline(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkVector4& out) const;
    __declspec(noinline) void ExtractFrame(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkQuaternion& out) const;
    __declspec(noinline) void sampleScale(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkVector4& out) const;
    __declspec(noinline) void hkaSplineCompressedAnimation_sampleFloat(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, float& out) const;
    void sampleAtFrame(unsigned int frame, float delta, unsigned int maxNumTransformTracks, hkQsTransform* transformTracksOut, unsigned int maxNumFloatTracks, float* floatTracksOut) const;
    void hkaSplineCompressedAnimation_samplePartialTracks(float time, unsigned int maxNumTransformTracks, hkQsTransform* transformTracksOut, unsigned int maxNumFloatTracks, float* floatTracksOut, void* cache) const;
};


// src: HAVOK_LIB 0x00e2f7c0
void SplineAnimationSampler::hkaAnimation_getFrameAndDelta(float time, unsigned int& frameOut, float& deltaOut) const
{
    const unsigned int maxFrameIndex = S00e340e0_vnum(this) - 1;
    const float frameFloat = (time / m_fAnimationDuration) * maxFrameIndex;
    frameOut = (unsigned int)frameFloat;
    if (frameOut > maxFrameIndex - 1) { frameOut = maxFrameIndex - 1; deltaOut = 1.0f; return; }
    deltaOut = frameFloat - frameOut;
}
void SplineAnimationSampler::GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut, unsigned char& quantizedTimeOut) const
{
    blockOut = frame / (m_iMaxFramesPerBlock - 1);
    blockOut = blockOut > 0 ? blockOut : 0;
    blockOut = blockOut < m_iBlockCount - 1 ? blockOut : m_iBlockCount - 1;
    const unsigned int first = blockOut * (m_iMaxFramesPerBlock - 1);
    const float realFrame = (float)(frame - first) + delta;
    blockTimeOut = realFrame * m_fPerFrameDuration;
    quantizedTimeOut = (unsigned char)((blockTimeOut * m_fBlockInverseDuration) * (m_iMaxFramesPerBlock - 1));
}
void SplineAnimationSampler::EvaluateSpline(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkVector4& out) const
{ data += S00e340e0_read(data, t, qt, q, type, &out); }
void SplineAnimationSampler::ExtractFrame(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkQuaternion& out) const
{ data += S00e340e0_read(data, t, qt, q, type, &out); }
// src: XBOX_PDB 0x00e33e90
void SplineAnimationSampler::sampleScale(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkVector4& out) const
{ data += S00e340e0_read(data, t, qt, q, type, &out); }
// src: XBOX_PDB 0x00e33f10
void SplineAnimationSampler::hkaSplineCompressedAnimation_sampleFloat(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, float& out) const
{ data += S00e340e0_read(data, t, qt, q, type, &out); }

// @fnv 0x00e340e0
// src: HAVOK_LIB 0x00e340e0
void SplineAnimationSampler::hkaSplineCompressedAnimation_samplePartialTracks(float time, unsigned int maxNumTransformTracks, hkQsTransform* transformTracksOut, unsigned int maxNumFloatTracks, float* floatTracksOut, void* cache) const
{
    S00e340e0_timer("TtSampleSpline");
    unsigned int frame;
    float delta;
    hkaAnimation_getFrameAndDelta(time, frame, delta);
    int block;
    float blockTime;
    unsigned char quantizedTime;
    GetBlockAndTime(frame, delta, block, blockTime, quantizedTime);
    const int* offsets = reinterpret_cast<const int*>(m_kFirstUInt32Array.m_data);
    int base = (int)m_data.m_data;
    const unsigned char* transformData = (const unsigned char*)GetIndexedValueWithOffset(base, offsets, block, m_iMaskAndQuantizationSize);
    const int* maskOffsets = reinterpret_cast<const int*>(m_kFirstUInt32Array.m_data);
    int maskBase = (int)m_data.m_data;
    const unsigned char* maskPtr = (const unsigned char*)GetIndexedValueWithOffset(maskBase, maskOffsets, block, 0x80000000);
    if (!transformData || !maskPtr) { S00e340e0_timer("Et"); return; }
    for (unsigned int i = 0; i < maxNumTransformTracks; i++)
    {
        unsigned char mask = *maskPtr++;
        EvaluateSpline(blockTime, quantizedTime, *maskPtr++, mask & 3, transformData, transformTracksOut[i].m_vTranslation);
        ExtractFrame(blockTime, quantizedTime, *maskPtr++, (mask >> 2) & 0xf, transformData, transformTracksOut[i].m_rotation);
        sampleScale(blockTime, quantizedTime, *maskPtr++, mask >> 6, transformData, transformTracksOut[i].m_vScale);
    }
    const unsigned char* floatData = m_data.m_data + m_kFloatBlockOffsets.m_data[block] + m_kFirstUInt32Array.m_data[block];
    const unsigned char* floatMask = m_data.m_data + m_iNumTransformTracks * 4 + m_kFirstUInt32Array.m_data[block];
    for (unsigned int j = 0; j < maxNumFloatTracks; j++)
    {
        unsigned char m = *floatMask++;
        hkaSplineCompressedAnimation_sampleFloat(blockTime, quantizedTime, m & 0xf9, (m >> 1) & 3, floatData, floatTracksOut[j]);
    }
    S00e340e0_timer("Et");
}
