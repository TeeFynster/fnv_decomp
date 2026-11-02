
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

struct NiRenderer
{
    static NiRenderer* ms_pRenderer;
};

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

struct RendererCall
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void Call130(void*, unsigned int);
};
struct BSPackedAdditionalGeometryData
{
    struct NiBSPackedAGDDataBlock
    {
        unsigned int _0;
        unsigned int _4;
        void* _8;
        unsigned char _12;
        unsigned char _13;
        void FUN_00a7f570(void* pvBuffer, unsigned int uiBufferSize);
    };
};
// If pvBuffer is null and _12 is set, substitutes _8/_4; then, unless _13 is set, calls Call130 on the renderer with the buffer and size.
// @fnv 0x00a7f570
void BSPackedAdditionalGeometryData::NiBSPackedAGDDataBlock::FUN_00a7f570(void* pvBuffer, unsigned int uiBufferSize)
{
    if (!pvBuffer && _12)
    {
        pvBuffer = _8;
        uiBufferSize = _4;
    }
    if (!_13)
    {
        ((RendererCall*)NiRenderer::ms_pRenderer)->Call130(pvBuffer, uiBufferSize);
    }
}

struct FakeRenderer
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void Func(void*, unsigned int);
};
struct BlockHolder
{
    int _00;
    unsigned int m4;
    void* m8;
    unsigned char mc;
    unsigned char md;
    void __thiscall FUN_00a7f5b0(void* pvBuffer, unsigned int uiBufferSize);
};
// @fnv 0x00a7f5b0
void __thiscall BlockHolder::FUN_00a7f5b0(void* pvBuffer, unsigned int uiBufferSize)
{
    if (!pvBuffer && mc)
    {
        pvBuffer = m8;
        uiBufferSize = m4;
    }
    if (!md)
    {
        ((FakeRenderer*)NiRenderer::ms_pRenderer)->Func(pvBuffer, uiBufferSize);
    }
}

namespace fnv_00a7f620 {
struct NiAdditionalGeometryData
{
    bool __thiscall FUN_00a727f0(const NiAdditionalGeometryData*);
    char _pad_0[0x2c];
    unsigned int m_uiShaderDeclarationIndex;
    unsigned int m_uiUnknownValue;
};
struct BSPackedAdditionalGeometryData : NiAdditionalGeometryData
{
    bool __thiscall FUN_00a7f620(const NiAdditionalGeometryData* pkObject);
};
// @fnv 0x00a7f620
bool __thiscall BSPackedAdditionalGeometryData::FUN_00a7f620(const NiAdditionalGeometryData* pkObject)
{
    if (FUN_00a727f0(pkObject) && m_uiShaderDeclarationIndex == pkObject->m_uiShaderDeclarationIndex &&
        m_uiUnknownValue == pkObject->m_uiUnknownValue)
        return true;
    return false;
}
}  // namespace fnv_00a7f620

struct FUN_00a7f560_shell
{
    void* __thiscall FUN_00a7f560(unsigned int uiBufferSize);
};

// @fnv 0x00a7f560
void* FUN_00a7f560_shell::FUN_00a7f560(unsigned int uiBufferSize)
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
    void Merge(const Sphere& other);
};

// Sets this sphere to the other when it contains this; otherwise adjusts center and radius to enclose both.
// @fnv 0x00a7f3f0
void Sphere::Merge(const Sphere& other)
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
