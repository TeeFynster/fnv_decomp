// src/havok/physics/internal/collide/gjk/hkpgsk_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/gjk/hkpgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/hkpgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/hkpgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Entry
{
    char pad[12];
    unsigned short val;
    char pad2[2];
};
struct Dest
{
    unsigned short words[4];
    unsigned char count1;
    unsigned char count2;
};
struct ThisClass
{
    int count1;
    int count2;
    char pad[0x18];
    Entry entries1[3];
    char pad2[0x90];
    Entry entries2[3];

    void hkpGsk_exitAndExportCacheImpl(Dest* out);
};

#include <xmmintrin.h>
// local form of hkVector4: 0x00da98f0 needs its original assignment/copy type for store/shift scheduling (10 differing bytes with shared form).
struct __declspec(align(16)) GskVectorPacketLocal_00da98f0
{
    __m128 quad;
    GskVectorPacketLocal_00da98f0()
    {}
    GskVectorPacketLocal_00da98f0(__m128 q) : quad(q)
    {}
    GskVectorPacketLocal_00da98f0& operator=(const GskVectorPacketLocal_00da98f0& rhs)
    {
        quad = rhs.quad;
        return *this;
    }
};
struct __declspec(align(16)) SegmentClosestResult
{
    GskVectorPacketLocal_00da98f0 pointA, pointB;
    float distanceSquared;
};
extern void __cdecl hkLineSegmentUtil_closestLineSegLineSeg(const GskVectorPacketLocal_00da98f0*, const GskVectorPacketLocal_00da98f0*, const GskVectorPacketLocal_00da98f0*, const GskVectorPacketLocal_00da98f0*, SegmentClosestResult*);
extern const signed char DAT_010cb440[];
extern const float DAT_0104da48;
struct Simplex
{
    int countA, countB, unk08, unk0c;
    GskVectorPacketLocal_00da98f0 unk10;
    GskVectorPacketLocal_00da98f0 verticesA[4];
    GskVectorPacketLocal_00da98f0 unk60, unk70, unk80, unk90;
    GskVectorPacketLocal_00da98f0 verticesB[4];
    GskVectorPacketLocal_00da98f0 supportB[4];
    int TestTriangleOrientationAndSwapVertices(const GskVectorPacketLocal_00da98f0*, const GskVectorPacketLocal_00da98f0*, int);
    void hkpGsk_reduceDimensionExtended();
};
// @fnv 0x00da98f0
// src: XBOX_PDB 0x00da98f0
void Simplex::hkpGsk_reduceDimensionExtended()
{
    if (countB == 3)
    {
        for (int i = 0; i < countA; ++i)
        {
            if (TestTriangleOrientationAndSwapVertices(&verticesA[i], verticesB, 0) == 7)
            {
                verticesA[0] = verticesA[i];
                countA = 1;
                return;
            }
        }
    }
    if (countA == 3)
    {
        for (int j = 0; j < countB; ++j)
        {
            if (TestTriangleOrientationAndSwapVertices(&verticesB[j], verticesA, 0) == 7)
            {
                supportB[0] = supportB[j];
                verticesB[0] = verticesB[j];
                countB = 1;
                return;
            }
        }
    }
    float bestDistance = DAT_0104da48;
    int edgesA = 1 + 2 * (countA == 3), edgesB = 1 + 2 * (countB == 3);
    int bestA = 0, bestB = 0;
    for (int i = 0; i < edgesA; ++i)
    {
        for (int j = 0; j < edgesB; ++j)
        {
            GskVectorPacketLocal_00da98f0 directionA = _mm_sub_ps(verticesA[DAT_010cb440[i + 2]].quad, verticesA[i].quad);
            GskVectorPacketLocal_00da98f0 directionB = _mm_sub_ps(verticesB[DAT_010cb440[j + 2]].quad, verticesB[j].quad);
            SegmentClosestResult result;
            hkLineSegmentUtil_closestLineSegLineSeg(&verticesA[i], &directionA, &verticesB[j], &directionB, &result);
            if (result.distanceSquared < bestDistance)
            {
                bestDistance = result.distanceSquared;
                bestA = i;
                bestB = j;
            }
        }
    }
    if (edgesA == 3)
    {
        --countA;
        verticesA[DAT_010cb440[bestA]] = verticesA[countA];
    }
    if (edgesB == 3)
    {
        --countB;
        int destination = DAT_010cb440[bestB];
        supportB[destination] = supportB[countB];
        verticesB[destination] = verticesB[countB];
    }
}

union Collision_vector
{
    __m128 value;
    float component[4];
};

struct Collision_vcls
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
    virtual void v0f(void* a, int b, void* out);
    int unk04;
    int unk08;
    int unk0c;
    float m_10;
};

struct Collision_in
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char m_08;
    unsigned char m_09;
    unsigned char m_0a;
};

struct Collision_mat
{
    __m128 m_00;
    __m128 m_10;
    __m128 m_20;
    __m128 m_30;
};

struct Collision_ctx
{
    void* m_vptr;
    Collision_mat* m_04;
    Collision_vcls* m_08;
    Collision_vcls* m_0c;
    float m_10;
};

struct Collision_workspace
{
    unsigned int countA;
    unsigned int countB;
    unsigned int low;
    unsigned int high;
    unsigned int unk10;
    unsigned int changed;
    unsigned int unk18;
    unsigned int unk1c;
    __m128 vector20;
    __m128 vector30;
    __m128 vector40;
    __m128 vector50;
    __m128 vector60;
    __m128 vector70;
    __m128 vector80;
    __m128 vector90;
    __m128 vectora0;
    __m128 vectorb0;
    __m128 vectorc0;
    __m128 vectord0;
    __m128 vectore0;
    __m128 vectorf0;
    __m128 vector100;
    __m128 vector110;
    __m128 vector120;
    __m128 vector130;
    __m128 vector140;
    __m128 vector150;
    __m128 vector160;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    int hkpGsk_getClosestFeature(Collision_vcls*, Collision_vcls*, void*, Collision_vector*);
};

// @fnv 0x00dabca0
// src: XBOX_PDB 0x00dabca0
int hkpGsk_getClosestPoint(Collision_ctx* self, Collision_in* in, Collision_vector* out, Collision_vector* out2)
{
    Collision_vector normal;
    Collision_workspace scratch;
    float w;
    float d;
    float bb;

    Collision_vcls* shapeA = self->m_08;
    Collision_vcls* shapeB = self->m_0c;

    scratch.countA = in->m_08;
    scratch.countB = in->m_09;
    scratch.unk10 = 0;
    scratch.low = in->m_0a & 0xf;
    scratch.high = in->m_0a >> 4;
    scratch.changed = 0;

    shapeA->v0f((void*)in, (int)scratch.countA, &scratch.vector20);
    shapeB->v0f((void*)((char*)in + scratch.countA * 2), (int)scratch.countB, &scratch.vectore0);

    scratch.hkpGsk_getClosestFeature(self->m_08, self->m_0c, (void*)self->m_vptr, &normal);
    if (scratch.changed != 0)
    {
        ((ThisClass*)&scratch)->hkpGsk_exitAndExportCacheImpl((Dest*)in);
    }

    Collision_mat* M = self->m_04;
    w = normal.component[3];
    d = (w - self->m_08->m_10) - self->m_0c->m_10;

    __m128 v = _mm_mul_ps(_mm_shuffle_ps(normal.value, normal.value, 0x55), M->m_10);
    v = _mm_add_ps(v, _mm_mul_ps(_mm_shuffle_ps(normal.value, normal.value, 0), M->m_00));
    v = _mm_add_ps(v, _mm_mul_ps(_mm_shuffle_ps(normal.value, normal.value, 0xaa), M->m_20));
    out->value = v;
    out->component[3] = d;

    if (self->m_10 > d)
    {
        __m128 finalVector;
        if (scratch.countA == 1)
        {
            bb = self->m_0c->m_10 - w;
            finalVector = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(bb), normal.value), scratch.vector20);
        }
        else if (scratch.countB == 1)
        {
            bb = self->m_0c->m_10;
            finalVector = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(bb), normal.value), scratch.vectora0);
        }
        else
        {
            bb = self->m_0c->m_10 - w;
            finalVector = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(bb), normal.value), scratch.vector130);
        }

        M = self->m_04;
        __m128 s = finalVector;
        __m128 o = _mm_mul_ps(_mm_shuffle_ps(s, s, 0x55), M->m_10);
        o = _mm_add_ps(o, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), M->m_00));
        __m128 z = _mm_mul_ps(_mm_shuffle_ps(s, s, 0xaa), M->m_20);
        z = _mm_add_ps(z, M->m_30);
        o = _mm_add_ps(o, z);
        out2->value = o;

        return 0;
    }
    return 1;
}

struct Result
{
    __m128 v;
};
// @fnv 0x00da8350
// src: GUESS 0x00da8350 (confidence: low)
static __declspec(noinline) Result
    HkpgskGsNogs_ComputeValues_00da8350(const __m128* pkPoint, const __m128* pkOrigin, const __m128* pkNormal, __m128* pkNormalOut)
{

    __m128 kDelta = _mm_sub_ps(*pkPoint, *pkOrigin);
    __m128 kNormal = *pkNormal;
    *pkNormalOut = kNormal;
    __m128 kProduct = _mm_mul_ps(kNormal, kDelta);
    __m128 kY = _mm_shuffle_ps(kProduct, kProduct, 0x55);
    __m128 kZ = _mm_shuffle_ps(kProduct, kProduct, 0xaa);
    kY = _mm_add_ss(kY, kProduct);
    kZ = _mm_add_ss(kZ, kY);
    Result r;
    r.v = kZ;
    return r;
}
__m128* volatile gP;
__m128* volatile gO;
__m128* volatile gN;
__m128* volatile gOut;
__m128* volatile gD;
void Caller()
{
    *gD = HkpgskGsNogs_ComputeValues_00da8350(gP, gO, gN, gOut).v;
}
