
// src/havok/common/internal/kdtree/build/hkkdtreebuildingutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/kdtree/build/hkkdtreebuildingutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct BufferPair
{
    void* m_pFirst;
    void* m_pSecond;
};

// If aiCount is positive, frees both pointers of apPair through the allocator, each with aiCount * 16 bytes.
// @fnv 0x00d9d840
void __cdecl FreeBufferPair(BufferPair* apPair, int aiCount)
{
    if (aiCount <= 0)
        return;

    void* pSecond = apPair->m_pSecond;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    pAllocator->blockFree(pSecond, aiCount * 16);

    void* pFirst = apPair->m_pFirst;
    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    pAllocator2->blockFree(pFirst, aiCount * 16);
}

#include <xmmintrin.h>
// ---------------------------------------------------------------------------
// MixChannels - builds one audio description and hands it to the mixer.
//
// The mixer takes a description block that points back at the sound object,
// the per channel settings and a constant mask table.  The sound object is
// set up before the mix and released afterwards.
// ---------------------------------------------------------------------------

// Sixteen bytes of per channel shorts.  The first three channels are muted
// (0) and the next three are left at full scale (0xffff).
struct __declspec(align(16)) ChannelMix
{
    unsigned short w00, w02, w04, w06, w08, w0a, w0c, w0e;
};

// The description that is passed to the mixer.  The two sixteen byte blocks
// are moved around as vectors by the mixer.
struct __declspec(align(16)) MixDesc
{
    void* p00;  // owner
    int v04;    // 0
    void* p08;  // buffer
    int v0c;    // 0
    int v10;    // channel count
    int v14;
    int v18;
    int v1c;
    ChannelMix mix20;  // per channel settings
    void* p30;         // the sound object
    int v34;
    int v38;
    int v3c;
    ChannelMix mask40;  // constant mask
};

// The sound object that is set up before and released after the mix.
struct __declspec(align(16)) SoundObject
{
    int unk00[64];
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    void Start();
    void Stop();
};

// The constant mask table the mixer ANDs the channel settings with.
extern __declspec(align(16)) __m128 g_mixMask;

// The mixer itself.
int __cdecl Mix(MixDesc* desc, int** p2, int count, int* p4, int** p5);

// Initializes a MixDesc and SoundObject, calls Mix with count, and stores its return value in out.
// @fnv 0x00d9d880
void __cdecl MixChannels(void* p1, int* p2, int count, void* p4, int channels, int* p6, int* apResult)
{
    int* p2Copy;
    int one;
    int* p6Copy;
    ChannelMix mix;
    MixDesc desc;
    SoundObject soundObj;

    // The mask is a plain sixteen byte block; copy it over as a vector.
    *(__m128*)&desc.mask40 = g_mixMask;

    // Mute the first three channels, keep the next three at full scale.
    mix.w00 = mix.w02 = mix.w04 = 0;
    mix.w08 = mix.w0a = mix.w0c = 0xffff;

    p2Copy = p2;

    desc.v04 = 0;
    desc.v0c = 0;
    desc.p00 = p1;

    one = 1;

    desc.v10 = channels;

    // The channel settings travel to the mixer as a vector as well.
    *(__m128*)&desc.mix20 = *(__m128*)&mix;

    desc.p08 = p4;

    // Bring the sound object up, let the mixer know about it and run it.
    soundObj.Start();
    desc.p30 = &soundObj;
    p6Copy = p6;
    *apResult = Mix(&desc, &p2Copy, count, &one, &p6Copy);

    // And shut it down again.
    soundObj.Stop();
}

struct __declspec(align(16)) S_00d9dab0_Aabb16
{
    unsigned short m_min0;
    unsigned short m_min1;
    unsigned short m_min2;
    unsigned short m_key;
    unsigned short m_max0;
    unsigned short m_max1;
    unsigned short m_max2;
    unsigned short m_key1;
};

struct S_00d9dab0_Coll
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual unsigned int GetIteratorKey(int i);
    virtual void getAabb(unsigned int key, S_00d9dab0_Aabb16* out);
};

// Fills out[start..end) with AABBs from coll, storing the iterator key split into m_key and m_key1 in each entry.
// @fnv 0x00d9dab0
void FillAabbArray(S_00d9dab0_Coll* coll, int start, int end, S_00d9dab0_Aabb16* out)
{
    S_00d9dab0_Aabb16* p = out + start;
    for (int i = start; i < end; i++)
    {
        _mm_prefetch((const char*)(p + 4), _MM_HINT_NTA);
        unsigned int key = coll->GetIteratorKey(i);
        S_00d9dab0_Aabb16 aabb;
        coll->getAabb(key, &aabb);
        aabb.m_key = (unsigned short)key;
        aabb.m_key1 = (unsigned short)(key >> 16);
        *(__m128*)p = *(__m128*)&aabb;
        p++;
    }
}

struct S9d950_Rel
{

    int m_off;

    int m_iElementCount;
};

struct S9d950_Owner
{

    S9d950_Rel* m_pairs;

    int unk04;

    int unk08;

    int unk0c;
};

struct S9d950_Box
{

    int a, b, c, d;
};

// Relocates pair entries in apA->m_pairs when aiB >= 8, then stores the max of apC's four fields into apA->unk0c.
// @fnv 0x00d9d950
// src: HAVOK_LIB 0x00d9d950
void __cdecl hkKdTreeBuildingUtils_completeDistributedBuild(S9d950_Owner* apA, int aiB, const S9d950_Box* apC, const int* apD)
{

    if (aiB >= 8)
    {

        S9d950_Rel* p = apA->m_pairs;

        int iSrc = 8;

        for (int i = 4; i < 8; ++i)
        {
            int head = p[iSrc].m_off;
            S9d950_Rel& dstPair = p[i];
            S9d950_Rel& srcPair = p[iSrc];
            if ((int)head >= 0)
            {
                dstPair = srcPair;
            }
            else
            {
                S9d950_Rel* left = (S9d950_Rel*)((unsigned long)&srcPair + (srcPair.m_off & 0x7ffffffc));
                dstPair = srcPair;
                int d = left - (p + i);
                dstPair.m_off = (d * 8) | (dstPair.m_off & 0x80000003);
            }
            iSrc += apD[i - 4];
        }
    }

    if (apC != 0)
    {

        int y = apC->c > apC->d ? apC->c : apC->d;

        int x = apC->a > apC->b ? apC->a : apC->b;

        apA->unk0c = x > y ? x : y;
    }
}
