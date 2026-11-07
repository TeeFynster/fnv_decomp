#include "../../../../../../include/hkArray.h"
#define FNV_HAVOK_SHARED_ARRAYS
// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkaInterleavedUncompressedAnimation.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/Vec4.h"
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
struct FUN_00e3f970_class
{
    int hkaInterleavedUncompressedAnimation_getMaxSizeOfCombinedDataChunks();
};
struct FUN_00e3f990_class
{
    int GetRatio();
};
struct FUN_00e3f920_class
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void hkaInterleavedUncompressedAnimation_sampleTracks(float, int, int, int);
};
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
#include <xmmintrin.h>
#include "../../../../../../include/hkQsTransform.h"

typedef hkArrayBase<hkQsTransform> XformArrayX;
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

namespace E3fda0Simd {
// Exe 0x00e3fda0 FUN_00e3fda0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float x, y, z, w;
} __m128, LocalM128;
extern "C"
{
    E3fda0Simd::LocalM128 _mm_load_ss(const float*);
    E3fda0Simd::LocalM128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, E3fda0Simd::LocalM128);
    void _mm_store_ss(float*, E3fda0Simd::LocalM128);
    E3fda0Simd::LocalM128 _mm_shuffle_ps(E3fda0Simd::LocalM128, E3fda0Simd::LocalM128, unsigned int);
    E3fda0Simd::LocalM128 _mm_mul_ps(E3fda0Simd::LocalM128, E3fda0Simd::LocalM128);
    E3fda0Simd::LocalM128 _mm_add_ps(E3fda0Simd::LocalM128, E3fda0Simd::LocalM128);
    E3fda0Simd::LocalM128 _mm_sub_ps(E3fda0Simd::LocalM128, E3fda0Simd::LocalM128);
    E3fda0Simd::LocalM128 _mm_sub_ss(E3fda0Simd::LocalM128, E3fda0Simd::LocalM128);
}

}
struct DataChunk
{
    const unsigned char* m_data;
    unsigned int m_iElementCount;
    unsigned char m_offset;
};


struct FUN_005611c0_t
{
    float x, y, z, w;
    void normalize_005611c0();
};

extern ::__m128 DAT_010ec7f0;
extern ::__m128 DAT_010c7160;

inline float scalarValue(E3fda0Simd::LocalM128 value)
{
    float result;
    E3fda0Simd::_mm_store_ss(&result, value);
    return result;
}

struct VectorLane
{
    union
    {
        E3fda0Simd::LocalM128 v;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct TransformLane
{
    VectorLane translation, rotation, scale;
};

extern "C" void _ReadWriteBarrier();
// @fnv 0x00e3fda0
// src: XBOX_PDB 0x00e3fda0
void hkaInterleavedUncompressedAnimation_samplePartialWithDataChunks(unsigned int frameIndex, float frameDelta, unsigned int maxNumTransformTracks,
                  hkQsTransform* transformOutArg, int maxNumFloatTracks, float* floatOutArg,
                  const DataChunk* dataChunks, int numDataChunks)
{
    const hkaAnimation* anim = (const hkaAnimation*)dataChunks[0].m_data;
    int chunkIndex = 1;
    if (anim->m_iNumTransformTracks > 0)
    {
        const TransformLane* __restrict pose0 = (const TransformLane*)dataChunks[1].m_data;
        const TransformLane* __restrict pose1 = pose0 + anim->m_iNumTransformTracks;
        if (maxNumTransformTracks > 0)
        {
            TransformLane* transformTracksOut = (TransformLane*)transformOutArg;
            for (unsigned int left = 0; left < maxNumTransformTracks; ++left)
            {
                E3fda0Simd::LocalM128 invScalar;
                (void)invScalar;

                E3fda0Simd::LocalM128 tss = E3fda0Simd::_mm_load_ss(&frameDelta);
                E3fda0Simd::LocalM128 tAll = E3fda0Simd::_mm_shuffle_ps(tss, tss, 0);
                E3fda0Simd::LocalM128 ones = (*reinterpret_cast<const E3fda0Simd::LocalM128*>(&DAT_010ec7f0));
                E3fda0Simd::LocalM128 inv = E3fda0Simd::_mm_sub_ps(ones, tAll);
                E3fda0Simd::LocalM128 scale = E3fda0Simd::_mm_add_ps(E3fda0Simd::_mm_mul_ps(inv, pose0->scale.v),
                                                                  E3fda0Simd::_mm_mul_ps(tAll, pose1->scale.v));
                transformTracksOut->scale.v = scale;

                ones = (*reinterpret_cast<const E3fda0Simd::LocalM128*>(&DAT_010ec7f0));
                inv = E3fda0Simd::_mm_sub_ps(ones, tAll);
                E3fda0Simd::LocalM128 trans = E3fda0Simd::_mm_add_ps(E3fda0Simd::_mm_mul_ps(inv, pose0->translation.v),
                                                                  E3fda0Simd::_mm_mul_ps(tAll, pose1->translation.v));
                transformTracksOut->translation.v = trans;

                E3fda0Simd::LocalM128 r0 = pose0->rotation.v;
                float oneMinus = 1.0f - scalarValue(tss);
                E3fda0Simd::LocalM128 prod = E3fda0Simd::_mm_mul_ps(r0, pose1->rotation.v);
                prod = E3fda0Simd::_mm_add_ps(E3fda0Simd::_mm_shuffle_ps(prod, prod, 0x4e), prod);
                prod = E3fda0Simd::_mm_add_ps(E3fda0Simd::_mm_shuffle_ps(prod, prod, 0xb1), prod);
                E3fda0Simd::LocalM128 pos;
                E3fda0Simd::_mm_store_ps(reinterpret_cast<float*>(&pos), tss);
                E3fda0Simd::LocalM128 neg;
                const Vec4* picked;
                if (scalarValue(prod) < 0.0f)
                {
                    E3fda0Simd::_mm_store_ps(
                        reinterpret_cast<float*>(&neg),
                        E3fda0Simd::_mm_sub_ss((*reinterpret_cast<const E3fda0Simd::LocalM128*>(&DAT_010c7160)), tss));
                    picked = reinterpret_cast<const Vec4*>(&neg);
                }
                else
                {
                    picked = reinterpret_cast<const Vec4*>(&pos);
                }
                E3fda0Simd::LocalM128 chosen = E3fda0Simd::_mm_load_ps(reinterpret_cast<const float*>(picked));
                float signedT = scalarValue(chosen);
                E3fda0Simd::LocalM128 signedScalar = E3fda0Simd::_mm_load_ss(&signedT);
                invScalar = E3fda0Simd::_mm_load_ss(&oneMinus);
                E3fda0Simd::LocalM128 signedAll = E3fda0Simd::_mm_shuffle_ps(signedScalar, signedScalar, 0);
                E3fda0Simd::LocalM128 invAll = E3fda0Simd::_mm_shuffle_ps(invScalar, invScalar, 0);
                FUN_005611c0_t quat;
                E3fda0Simd::_mm_store_ps(&quat.x,
                                         E3fda0Simd::_mm_add_ps(E3fda0Simd::_mm_mul_ps(signedAll, pose1->rotation.v),
                                                                E3fda0Simd::_mm_mul_ps(invAll, r0)));
                quat.normalize_005611c0();
                transformTracksOut->rotation.v = E3fda0Simd::_mm_load_ps(&quat.x);
                pose0++;
                pose1++;
                transformTracksOut++;
            }
        }
        chunkIndex = 2;
    }
    if (anim->m_iNumberOfFloatTracks > 0)
    {
        const DataChunk* floats = &dataChunks[chunkIndex];
        const float* b;
        (void)b;
        float t;
        (void)t;
        const float* a;
        (void)a;
        float oneMinus;
        (void)oneMinus;
        a = (const float*)(floats->m_data + floats->m_offset);
        b = a + anim->m_iNumberOfFloatTracks;
        t = frameDelta;
        oneMinus = 1.0f - t;
        unsigned int i = 0;
        for (; i < (unsigned int)maxNumFloatTracks; ++i)
        {
            floatOutArg[i] = *a * oneMinus + t * *b;
            a++;
            b++;
        }
    }
}
