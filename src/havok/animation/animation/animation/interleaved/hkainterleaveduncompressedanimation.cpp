#include "../../../../../../include/hkArray.h"
#define FNV_HAVOK_SHARED_ARRAYS

// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaInterleavedUncompressedAnimation.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"

struct FUN_00e3f950_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int hkaInterleavedUncompressedAnimation_getNumDataChunks(int a, int b);
};

// @fnv 0x00e3f950
// src: HAVOK_LIB 0x00e3f950
int FUN_00e3f950_class::hkaInterleavedUncompressedAnimation_getNumDataChunks(int aiUnused1, int aiUnused2)
{
    int result = 1;
    if (m_10 > 0)
        result = 2;
    if (m_14 > 0)
        ++result;
    return result;
}

struct FUN_00e3f970_class
{
    int hkaInterleavedUncompressedAnimation_getMaxSizeOfCombinedDataChunks();
};
// @fnv 0x00e3f970
// src: HAVOK_LIB 0x00e3f970
int FUN_00e3f970_class::hkaInterleavedUncompressedAnimation_getMaxSizeOfCombinedDataChunks()
{
    int* p = (int*)this;
    int a = p[5];
    int b = p[4];
    return (((a * 8 + 31) & ~15) + b * 3 * 32 + 64);
}

struct FUN_00e3f990_class
{
    int GetRatio();
};

// @fnv 0x00e3f990
int FUN_00e3f990_class::GetRatio()
{
    if (*(int*)((char*)this + 0x10))
        return *(int*)((char*)this + 0x2c) / *(int*)((char*)this + 0x10);
    return *(int*)((char*)this + 0x38) / *(int*)((char*)this + 0x14);
}

struct FUN_00e3f920_class
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void hkaInterleavedUncompressedAnimation_sampleTracks(float, int, int, int);
};
// Invokes virtual function at offset 0x10 passing a, m_10, b, m_14, c, d.
// @fnv 0x00e3f920
// src: HAVOK_SRC 0x00e3f920
void FUN_00e3f920_class::hkaInterleavedUncompressedAnimation_sampleTracks(float afValue, int b, int c, int d)
{
    ((void(__thiscall*)(void*, float, int, int, int, int, int))(*reinterpret_cast<void***>(this))[4])(
        this, afValue, *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x10), b,
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x14), c, d);
}

struct S00e3fb60_Anim : public hkaInterleavedUncompressedAnimation
{
    void hkaAnimation_getFrameAndDelta(float time, int& frameIndex, float& weight) const;
    void hkaInterleavedUncompressedAnimation_sampleIndividualFloatTracks(float time, const short* tracks, int numTracks, float* out);
};

// src: HAVOK_LIB 0x00e2f7c0
__declspec(noinline) void S00e3fb60_Anim::hkaAnimation_getFrameAndDelta(float time, int& frameIndex, float& weight) const
{
    unsigned int numPoses = m_kTransforms.m_iElementCount / m_iNumTransformTracks;
    float f = (time / m_fAnimationDuration) * (float)(numPoses - 1);
    unsigned int i = (unsigned int)f;
    frameIndex = i;
    weight = f - (float)i;
}

// Interpolates float animation tracks between two frames at the given time, writing results to out.
// @fnv 0x00e3fb60
// src: HAVOK_LIB 0x00e3fb60
void S00e3fb60_Anim::hkaInterleavedUncompressedAnimation_sampleIndividualFloatTracks(float time, const short* tracks, int numTracks, float* out)
{
    int frameIndex;
    hkaAnimation_getFrameAndDelta(time, frameIndex, time);
    float invWeight = 1.0f - time;
    for (unsigned int i = 0; i < (unsigned int)numTracks; ++i)
    {
        short track = tracks[i];
        if (track >= 0)
        {
            int n = m_iNumberOfFloatTracks;
            if (track < n)
            {
                const float* frame0 = &m_kFloats.m_data[frameIndex * n];
                out[i] = frame0[track + n] * time + frame0[track] * invWeight;
            }
        }
    }
}

struct S00e3fd20_Desc
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    void __thiscall hkaInterleavedUncompressedAnimation_getDataChunks(int scale, int unused1, int* out, int unused2);
};

// Writes a descriptor into out, storing this pointer, a 0x40 size, and optional segment and alignment data based on m_10 and m_14.
// @fnv 0x00e3fd20
// src: HAVOK_LIB 0x00e3fd20
void __thiscall S00e3fd20_Desc::hkaInterleavedUncompressedAnimation_getDataChunks(int scale, int unused1, int* out, int unused2)
{
    out[0] = (int)this;
    out[1] = 0x40;

    int segment = 1;

    if (m_10 > 0)
    {
        out[3] = m_10 * scale * 0x30 + m_28;
        out[4] = m_10 * 0x60;
        segment = 2;
    }

    if (m_14 > 0)
    {
        int* descriptor = out + segment * 3;
        int count = *(volatile int*)&m_14;

        unsigned int address = (unsigned int)m_34 + count * scale * 4;
        unsigned char offset = (unsigned char)address;
        offset &= 0xf;
        address &= 0xfffffff0;

        descriptor[0] = (int)address;
        *((unsigned char*)descriptor + 8) = offset;
        descriptor[1] = (int)((offset + count * 8 + 0xf) & 0xfffffff0);
    }
}

#include <xmmintrin.h>
// local form of hkQsTransform: 0x00e3ffc0 needs legacy animation-header dispatch; shared header adoption changes exe virtual-call bytes.
struct QsTransformX
{
    __m128 m_vTranslation, m_rotation, m_vScale;
};
typedef hkArrayBase<QsTransformX> XformArrayX;
typedef hkArrayBase<float> FloatArrayX;

struct SrcAnimX
{
    void* m_vfptr;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_type;
    float m_fAnimationDuration;
    int m_iNumTransformTracks;
    int m_iNumberOfFloatTracks;
    void* m_pExtractedMotion;
    void* m_annotData;
    int m_annotSize;
    int m_annotCapacityAndFlags;
    XformArrayX m_kTransforms;
    FloatArrayX m_kFloats;
};

class HeapMgrX
{
  public:
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void* AllocateBufferWithSize(int* numBytes)
    {
        return 0;
    }
    virtual void ReturnMemory(void* data, int numBytes)
    {}
};

struct AudioSvcX
{
    int m_00, m_04, m_08, m_0c;
    HeapMgrX* m_pStreamAllocator;
};

class BaseAnimX
{
  public:
    BaseAnimX(SrcAnimX* src);
};

class FUN_00e402e0 : public BaseAnimX
{
  public:
    FUN_00e402e0(SrcAnimX* src);
    void* m_vfptr;
    int m_unk04, m_unk08, m_unk0c, m_unk10, m_unk14, m_unk18, m_unk1c, m_unk20, m_unk24;
    XformArrayX m_kTransforms;
    FloatArrayX m_kFloats;
};

void* hkMemoryRouter_getInstance();
extern int DAT_010e5474;

// Copies transform and float track arrays from src into m_kTransforms and m_kFloats, resizing via the audio service heap manager when capacity is insufficient.
// @fnv 0x00e402e0
FUN_00e402e0::FUN_00e402e0(SrcAnimX* apSrcAnim)
    : BaseAnimX(apSrcAnim), m_vfptr((void*)&DAT_010e5474), m_kTransforms(), m_kFloats()
{
    {
        HeapMgrX* pHeapMgr = ((AudioSvcX*)hkMemoryRouter_getInstance())->m_pStreamAllocator;
        int iCapacity = m_kTransforms.m_iCapacityState & 0x3FFFFFFF;
        if (iCapacity < apSrcAnim->m_kTransforms.m_iElementCount)
        {
            if ((m_kTransforms.m_iCapacityState & 0x80000000) == 0)
                pHeapMgr->ReturnMemory(m_kTransforms.m_data, iCapacity * 48);
            int numBytes = apSrcAnim->m_kTransforms.m_iElementCount * 48;
            m_kTransforms.m_data = (QsTransformX*)pHeapMgr->AllocateBufferWithSize(&numBytes);
            m_kTransforms.m_iCapacityState = numBytes / 48;
        }
        int iNumTransforms = apSrcAnim->m_kTransforms.m_iElementCount;
        m_kTransforms.m_iElementCount = iNumTransforms;
        QsTransformX* pDstTransforms = m_kTransforms.m_data;
        const QsTransformX* s = apSrcAnim->m_kTransforms.m_data;
        for (int i = 0; i < iNumTransforms; i++)
        {
            pDstTransforms[i].m_vTranslation = s[i].m_vTranslation;
            pDstTransforms[i].m_rotation = s[i].m_rotation;
            pDstTransforms[i].m_vScale = s[i].m_vScale;
        }
    }
    {
        HeapMgrX* pHeapMgr = ((AudioSvcX*)hkMemoryRouter_getInstance())->m_pStreamAllocator;
        int iCapacity = m_kFloats.m_iCapacityState & 0x3FFFFFFF;
        if (iCapacity < apSrcAnim->m_kFloats.m_iElementCount)
        {
            if ((m_kFloats.m_iCapacityState & 0x80000000) == 0)
                pHeapMgr->ReturnMemory(m_kFloats.m_data, iCapacity * 4);
            int numBytes = apSrcAnim->m_kFloats.m_iElementCount * 4;
            m_kFloats.m_data = (float*)pHeapMgr->AllocateBufferWithSize(&numBytes);
            m_kFloats.m_iCapacityState = numBytes / 4;
        }
        int iNumFloats = apSrcAnim->m_kFloats.m_iElementCount;
        m_kFloats.m_iElementCount = iNumFloats;
        const float* s = apSrcAnim->m_kFloats.m_data;
        float* pDstTransforms = m_kFloats.m_data;
        for (int i = 0; i < iNumFloats; i++)
            pDstTransforms[i] = s[i];
    }
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
typedef void*(__stdcall* TlsGetValueFn)(unsigned long);
extern unsigned long DAT_0126835c;

struct QsTm
{
    __m128 t;
    __m128 r;
    __m128 s;
};
struct QsT
{
    float v[12];
};
struct SampleRec
{
    int a;
    int b;
    char c;
};

inline SampleRec* S00e3ffc0_zero(SampleRec* recs)
{
    recs[0].a = 0;
    recs[0].b = 0;
    recs[0].c = 0;
    recs[1].a = 0;
    recs[1].b = 0;
    recs[1].c = 0;
    recs[2].a = 0;
    recs[2].b = 0;
    recs[2].c = 0;
    return recs;
}
struct FUN_00e2f7c0_Obj
{
    void hkaAnimation_getFrameAndDelta(float a1, int* a2, float* a3);
};
__forceinline int S00e3ffc0_getFrame(FUN_00e2f7c0_Obj* o, float t, float* d)
{
    int f;
    o->hkaAnimation_getFrameAndDelta(t, &f, d);
    return f;
}
void __cdecl hkaInterleavedUncompressedAnimation_samplePartialWithDataChunks(int frame, float delta, unsigned int nT, QsT* tOut, unsigned int nF, float* fOut,
                          SampleRec* recs, int n);

struct hkaAnimSlot : hkaInterleavedUncompressedAnimation
{
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void SampleIndividualTracks(int frame, float delta, SampleRec* recs, int n);
    void hkaInterleavedUncompressedAnimation_samplePartialTracks(float time, unsigned int nT, QsT* tOut, unsigned int nF, float* fOut, int a6);
};

// Samples the animation into tOut and fOut, using the last frame when time is at or beyond the animation duration.
// @fnv 0x00e3ffc0
// src: HAVOK_SRC 0x00e3ffc0
void hkaAnimSlot::hkaInterleavedUncompressedAnimation_samplePartialTracks(float time, unsigned int nT, QsT* tOut, unsigned int nF, float* fOut, int a6)
{
    TlsGetValueFn pfnTlsGetValue = &TlsGetValue;
    union
    {
        volatile unsigned int tick;
        float delta;
    } u;
    {
        hkMonitorStream* pProfLog = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* pCurRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfLog->m_end.m_storage);
        if (reinterpret_cast<char*>(pCurRec) < pProfLog->m_capacityMinus16.m_storage)
        {
            pCurRec->m_commandAndMonitor = "TtsamplePose";
            _ReadWriteBarrier();
            u.tick = (unsigned int)__rdtsc();
            pCurRec->m_time0 = u.tick;
            pProfLog->m_end.m_storage = reinterpret_cast<char*>(pCurRec + 1);
        }
    }
    if (time >= m_fAnimationDuration)
    {
        for (unsigned int i = 0; i < nT; ++i)
        {
            const QsTm* s = (const QsTm*)m_kTransforms.m_data + (m_kTransforms.m_iElementCount - m_iNumTransformTracks + i);
            QsTm* d = (QsTm*)tOut + i;
            d->t = s->t;
            d->r = s->r;
            d->s = s->s;
        }
        for (unsigned int iFloat = 0; iFloat < nF; ++iFloat)
            fOut[iFloat] = m_kFloats.m_data[m_kFloats.m_iElementCount - m_iNumberOfFloatTracks + iFloat];
        {
            hkMonitorStream* pProfLog = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
            hkMonitorStream::TimerCommand* pCurRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfLog->m_end.m_storage);
            if (reinterpret_cast<char*>(pCurRec) < pProfLog->m_capacityMinus16.m_storage)
            {
                pCurRec->m_commandAndMonitor = "Et";
                _ReadWriteBarrier();
                u.tick = (unsigned int)__rdtsc();
                pCurRec->m_time0 = u.tick;
                pProfLog->m_end.m_storage = reinterpret_cast<char*>(pCurRec + 1);
            }
        }
        return;
    }
    {
        int frame = S00e3ffc0_getFrame((FUN_00e2f7c0_Obj*)this, time, &u.delta);
        SampleRec recs[3];
        SampleIndividualTracks(frame, u.delta, S00e3ffc0_zero(recs), 3);
        hkaInterleavedUncompressedAnimation_samplePartialWithDataChunks(frame, u.delta, nT, tOut, nF, fOut, recs, 3);
    }
    {
        hkMonitorStream* pProfLog = (hkMonitorStream*)pfnTlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* pCurRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfLog->m_end.m_storage);
        if (reinterpret_cast<char*>(pCurRec) < pProfLog->m_capacityMinus16.m_storage)
        {
            pCurRec->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            u.tick = (unsigned int)__rdtsc();
            pCurRec->m_time0 = u.tick;
            pProfLog->m_end.m_storage = reinterpret_cast<char*>(pCurRec + 1);
        }
    }
}
