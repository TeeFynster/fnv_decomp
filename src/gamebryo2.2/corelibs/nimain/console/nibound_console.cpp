#include "../../../../../include/BSPackedAdditionalGeometryData.h"
#include "../../../../../include/NiAdditionalGeometryData.h"
#include "../../../../../include/NiRenderer.h"

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern void* DAT_0109ded8;

struct NiAGDDataBlock
{
    void* m_pVtbl;
    unsigned int m_uiRef;
    unsigned int m_uiSize;
    unsigned char m_bFlag;
    unsigned char m_bFlag2;
};

// Allocates a 16-byte NiAGDDataBlock, initialises its fields to zero, sets its vtable, and returns it (or null on failure).
// @fnv 0x00a7f650
NiAGDDataBlock* __cdecl CreateNiAGDDataBlock()
{
    NiAGDDataBlock* pDataBlock = (NiAGDDataBlock*)g_memoryManager.Allocate(0x10);
    if (pDataBlock != 0)
    {
        pDataBlock->m_uiRef = 0;
        pDataBlock->m_uiSize = 0;
        pDataBlock->m_bFlag = 0;
        *(void**)(void*)pDataBlock = (void*)&DAT_0109ded8;
        pDataBlock->m_bFlag2 = 0;
        return pDataBlock;
    }
    return 0;
}


struct NiAGDDataBlockFreeBuffer
{
    void __thiscall FreeBuffer(void* pvBuffer);
};

// If pvBuffer is null and m_bFlag is set, substitutes m_uiSize, then calls the renderer's vtable slot at offset 0x138 with the buffer.
// @fnv 0x00a7f5f0
void __thiscall NiAGDDataBlockFreeBuffer::FreeBuffer(void* pvBuffer)
{
    void* pVal = pvBuffer;
    if (pvBuffer == 0 && ((NiAGDDataBlock*)this)->m_bFlag != 0)
        pVal = (void*)((NiAGDDataBlock*)this)->m_uiSize;
    NiRenderer* pRenderer = NiRenderer::ms_pRenderer;
    void** pVt = (void**)*(void**)pRenderer;
    ((void(__thiscall*)(NiRenderer*, void*))pVt[0x138 / 4])(pRenderer, pVal);
}

// The shared block has no buffer methods yet. Explicit ECX and unused EDX
// parameters retain the original thiscall argument layout.
// If pvBuffer is null and unk0C is set, substitutes unk08/unk04; unless
// unk0D is set, calls the renderer slot at 0x130 with the buffer and size.
// @fnv 0x00a7f570
void __fastcall FreePackedAGDBuffer(BSPackedAdditionalGeometryData::NiBSPackedAGDDataBlock* pBlock,
                                  void*, void* pvBuffer, unsigned int uiBufferSize)
{
    if (!pvBuffer && pBlock->unk0C)
    {
        pvBuffer = pBlock->unk08;
        uiBufferSize = pBlock->unk04;
    }
    if (!pBlock->unk0D)
    {
        NiRenderer* pRenderer = NiRenderer::ms_pRenderer;
        void** pVt = *(void***)pRenderer;
        ((void(__thiscall*)(NiRenderer*, void*, unsigned int))pVt[0x130 / 4])(pRenderer, pvBuffer, uiBufferSize);
    }
}

// @fnv 0x00a7f5b0
void __fastcall ReleasePackedAGDBuffer(BSPackedAdditionalGeometryData::NiBSPackedAGDDataBlock* pBlock,
                                     void*, void* pvBuffer, unsigned int uiBufferSize)
{
    if (!pvBuffer && pBlock->unk0C)
    {
        pvBuffer = pBlock->unk08;
        uiBufferSize = pBlock->unk04;
    }
    if (!pBlock->unk0D)
    {
        NiRenderer* pRenderer = NiRenderer::ms_pRenderer;
        void** pVt = *(void***)pRenderer;
        ((void(__thiscall*)(NiRenderer*, void*, unsigned int))pVt[0x134 / 4])(pRenderer, pvBuffer, uiBufferSize);
    }
}

// @fnv 0x00a7f620
bool __fastcall IsPackedAdditionalGeometryDataEqual(BSPackedAdditionalGeometryData* pData,
                                                   void*, const NiAdditionalGeometryData* pkObject)
{
    if (pData->NiAdditionalGeometryData_IsEqual(pkObject) && pData->m_uiShaderDeclarationIndex == pkObject->m_uiShaderDeclarationIndex &&
        pData->m_uiUnknownValue == pkObject->m_uiUnknownValue)
        return true;
    return false;
}

// @fnv 0x00a7f560
void* __fastcall AllocatePackedAGDBuffer(BSPackedAdditionalGeometryData::NiBSPackedAGDDataBlock*,
                                       void*, unsigned int uiBufferSize)
{
    void* p = NiRenderer::ms_pRenderer;
    void** vtbl = *(void***)p;
    return ((void*(__thiscall*)(void*, unsigned int))vtbl[0x12c / 4])(p, uiBufferSize);
}

struct Vec88
{

    float x, y, z;

    Vec88()
    {}

    Vec88(float a, float b, float c) : x(a), y(b), z(c)
    {}

    Vec88 operator+(const Vec88& v) const
    {
        return Vec88(x + v.x, y + v.y, z + v.z);
    }

    Vec88 operator-(const Vec88& v) const
    {
        return Vec88(x - v.x, y - v.y, z - v.z);
    }

    Vec88 operator*(float f) const
    {
        return Vec88(x * f, y * f, z * f);
    }

    float LengthSquared() const
    {
        return x * x + y * y + z * z;
    }
};

extern Vec88 DAT_011f426c;

extern "C" double __cdecl sqrt(double);

struct Bound88
{

    Vec88 center;
    float radius;

    void ComputeBoundingSphere(int count, const Vec88* points);
};

// @fnv 0x00a7ee30
void Bound88::ComputeBoundingSphere(int count, const Vec88* points)
{

    if (count <= 0)
    {
        center = DAT_011f426c;
        radius = 0;
        return;
    }

    Vec88 minCorner = points[0];

    Vec88 maxCorner = points[0];

    int iNextIndex = 1;
    if (count - 1 >= 4)
    {
        unsigned int uiGroupCount = ((unsigned int)(count - 5) >> 2) + 1;
        const float* cursor = &points[1].z;
        iNextIndex = uiGroupCount * 4 + 1;
        do
        {

            if (minCorner.x > cursor[-2])
                minCorner.x = cursor[-2];

            if (minCorner.y > cursor[-1])
                minCorner.y = cursor[-1];

            if (minCorner.z > cursor[0])
                minCorner.z = cursor[0];

            if (maxCorner.x < cursor[-2])
                maxCorner.x = cursor[-2];

            if (maxCorner.y < cursor[-1])
                maxCorner.y = cursor[-1];

            if (maxCorner.z < cursor[0])
                maxCorner.z = cursor[0];

            if (minCorner.x > cursor[1])
                minCorner.x = cursor[1];

            if (minCorner.y > cursor[2])
                minCorner.y = cursor[2];

            if (minCorner.z > cursor[3])
                minCorner.z = cursor[3];

            if (maxCorner.x < cursor[1])
                maxCorner.x = cursor[1];

            if (maxCorner.y < cursor[2])
                maxCorner.y = cursor[2];

            if (maxCorner.z < cursor[3])
                maxCorner.z = cursor[3];

            if (minCorner.x > cursor[4])
                minCorner.x = cursor[4];

            if (minCorner.y > cursor[5])
                minCorner.y = cursor[5];

            if (minCorner.z > cursor[6])
                minCorner.z = cursor[6];

            if (maxCorner.x < cursor[4])
                maxCorner.x = cursor[4];

            if (maxCorner.y < cursor[5])
                maxCorner.y = cursor[5];

            if (maxCorner.z < cursor[6])
                maxCorner.z = cursor[6];

            if (minCorner.x > cursor[7])
                minCorner.x = cursor[7];

            if (minCorner.y > cursor[8])
                minCorner.y = cursor[8];

            if (minCorner.z > cursor[9])
                minCorner.z = cursor[9];

            if (maxCorner.x < cursor[7])
                maxCorner.x = cursor[7];

            if (maxCorner.y < cursor[8])
                maxCorner.y = cursor[8];

            if (maxCorner.z < cursor[9])
                maxCorner.z = cursor[9];
            cursor += 12;
        } while (--uiGroupCount);
    }
    if (iNextIndex < count)
    {
        const float* tailCursor = &points[iNextIndex].z;
        int remaining = count - iNextIndex;
        do
        {

            if (minCorner.x > tailCursor[-2])
                minCorner.x = tailCursor[-2];

            if (minCorner.y > tailCursor[-1])
                minCorner.y = tailCursor[-1];

            if (minCorner.z > tailCursor[0])
                minCorner.z = tailCursor[0];

            if (maxCorner.x < tailCursor[-2])
                maxCorner.x = tailCursor[-2];

            if (maxCorner.y < tailCursor[-1])
                maxCorner.y = tailCursor[-1];

            if (maxCorner.z < tailCursor[0])
                maxCorner.z = tailCursor[0];
            tailCursor += 3;
        } while (--remaining);
    }
    center = (minCorner + maxCorner) * 0.5f;

    float fMaxDistSq = 0.0f;

    for (iNextIndex = 0; iNextIndex < count; iNextIndex++)
    {

        Vec88 vDelta = points[iNextIndex] - center;

        float squared = vDelta.LengthSquared();

        if (squared > fMaxDistSq)
            fMaxDistSq = squared;
    }

    volatile float rounding = (float)sqrt(fMaxDistSq);
    radius = rounding;
}

#include <math.h>
struct NiPt3
{
    float x, y, z;
    NiPt3()
    {}
    NiPt3(float ax, float ay, float az) : x(ax), y(ay), z(az)
    {}
    NiPt3 operator-(const NiPt3& o) const
    {
        return NiPt3(x - o.x, y - o.y, z - o.z);
    }
    NiPt3 operator+(const NiPt3& o) const
    {
        return NiPt3(x + o.x, y + o.y, z + o.z);
    }
    NiPt3 operator*(float s) const
    {
        return NiPt3(x * s, y * s, z * s);
    }
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
};

extern const float kSphereEpsilon;

struct Sphere
{
    NiPt3 center;
    float radius;
    void NiBound_Merge(const Sphere& other);
};

// Sets this sphere to the other when it contains this; otherwise adjusts center and radius to enclose both.
// @fnv 0x00a7f3f0
// src: GAMEBRYO_LIB 0x00a7f3f0
void Sphere::NiBound_Merge(const Sphere& other)
{
    NiPt3 vDelta = center - other.center;
    float distSq = vDelta.SqrLength();
    float fRadiusDiff = other.radius - radius;
    float fRadiusDiffSq = fRadiusDiff * fRadiusDiff;
    float dist;
    if (fRadiusDiff >= 0.0f)
    {
        if (fRadiusDiffSq >= distSq)
        {
            center = other.center;
            radius = other.radius;
            return;
        }
        dist = sqrtf(distSq);
        if (dist > kSphereEpsilon)
        {
            float t = (dist - fRadiusDiff) / (dist * 2.0f);
            center = other.center + vDelta * t;
        }
        radius = (dist + other.radius + radius) * 0.5;
        return;
    }
    if (!(fRadiusDiffSq < distSq))
        return;
    dist = sqrtf(distSq);
    if (dist > kSphereEpsilon)
    {
        float t = (dist - fRadiusDiff) / (dist * 2.0f);
        center = other.center + vDelta * t;
    }
    radius = (dist + other.radius + radius) * 0.5;
}
