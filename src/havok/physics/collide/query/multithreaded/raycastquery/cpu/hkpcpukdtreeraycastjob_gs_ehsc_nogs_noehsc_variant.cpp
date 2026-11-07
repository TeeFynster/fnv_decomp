// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"

struct FUN_00e4dd90_shell
{
    void __thiscall hkKdTreeCpuBroadphaseBundleCastCollector_getHitFractions(float* output);
};
struct FUN_00e4dde0
{
    virtual void Vfn0();
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    FUN_00e4dde0();
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FUN_00e4e3c0
{
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;

    FUN_00e4e3c0();

// @fnv 0x00e4e3c0
    virtual ~FUN_00e4e3c0()
    {}

    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        // The game dispatches Free through vtable slot 2.
        typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        ((FreeFunction)(*(void***)pAllocator)[2])(pAllocator, apMemory, sizeof(FUN_00e4e3c0));
    }
};
FUN_00e4e3c0::FUN_00e4e3c0()
{
    m_i04 = 0;
}

#include <xmmintrin.h>
__declspec(align(16)) struct Vec
{
    float x, y, z, w;
};
class HkVec4
{
  public:
    void operator=(const HkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const __m128& q)
    {
        m_vComponents = q;
    }
    operator __m128() const
    {
        return m_vComponents;
    }
    void setSub4(const HkVec4& a, const HkVec4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setRotatedInverseDir(const struct KdRayRotation& r, const HkVec4& b);
    void SetRotatedVector(const struct KdRayRotation& a, const HkVec4& b);
    void SetTransformedPosition(const struct Mat4& t, const HkVec4& b);
    void SetRotatedDirection(const struct KdRayRotation& r, const HkVec4& b);
    __m128 m_vComponents;
};
// hkRotation (three columns; rotation part of Mat4 = hkTransform) over this unit's HkVec4 stand-in.
struct KdRayRotation
{
    HkVec4 c0;
    HkVec4 c1;
    HkVec4 c2;
    const HkVec4& getColumn(int x) const
    {
        return (&c0)[x];
    }
};
struct Mat4
{
    KdRayRotation rot;
    HkVec4 trans;
    const KdRayRotation& getRotation() const
    {
        return rot;
    }
    const HkVec4& getTranslation() const
    {
        return trans;
    }
};
__forceinline void HkVec4::SetRotatedVector(const KdRayRotation& a, const HkVec4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void HkVec4::SetRotatedDirection(const KdRayRotation& r, const HkVec4& v)
{
    SetRotatedVector(r, v);
}
__forceinline void HkVec4::setRotatedInverseDir(const KdRayRotation& r, const HkVec4& b)
{
    __m128 c0 = r.getColumn(0).m_vComponents;
    __m128 c1 = r.getColumn(1).m_vComponents;
    __m128 c2 = r.getColumn(2).m_vComponents;
    {
        __m128 _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, 0xd4);
        c2 = _ctmp;
    }
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void HkVec4::SetTransformedPosition(const Mat4& t, const HkVec4& b)
{
    HkVec4 t0;
    t0.setSub4(b, t.getTranslation());
    setRotatedInverseDir(t.getRotation(), t0);
}
struct AItem
{
    HkVec4 r0;
    HkVec4 r1;
    float tail0;
    float tail1;
    float tail2;
    float tail3;
};

struct BoolResult
{
    char b;
};
class GuardInner
{

  public:
    virtual void Alpha();

    virtual BoolResult __thiscall Query(void* f8, void* p1);
};

struct F04Obj
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    GuardInner inner;
};

__declspec(align(16)) struct FUN_009c1aa0_Class
{

  public:
    float x, y, z, w;

    float gate;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
    float f48;

    FUN_009c1aa0_Class& __thiscall ProcessEntries_009c1aa0(const FUN_009c1aa0_Class& src);
    bool DidHit() const
    {
        return gate < 1.0f;
    }
};

struct DestEntry
{

    union
    {
        __m128 row;
        int w0;
    } u;

    float gate;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
    float f48;

    float f4c;
    union
    {
        void* field50;
        int info50;
    };

    int tail54;
    int tail58;
    int tail5c;
};

struct DestObj
{

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
    int unk2c;
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
    int unk58;
    int unk5c;

    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;

    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;

    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;

    char flagc0;
    char fc1;
    char fc2;
    char fc3;

    DestEntry* entries;
};

struct Mask
{
    __m128 q;
};
class HeadObj
{

  public:
    virtual void Alpha();

    virtual void Bravo();

    virtual void Charlie();

    virtual void Delta();

    virtual void Echo();

    virtual void Foxtrot();

    virtual void Golf();

    virtual void Hotel();

    virtual void India();

    virtual void Juliett();

    virtual Mask __thiscall V28(void* mat, void* arr, const Mask& p2);

    int h04;
    int h08;
    int h0c;
    int h10;
    int h14;
    int h18;
    int h1c;
    int h20;

    int h24;
    int h28;
    int h2c;
    int h30;
    int h34;
    int h38;
    int h3c;
    int h40;

    int h44;
    int h48;
    int h4c;

    int field50;
};

struct Param
{
    HeadObj* head;
    int unk04;
    const void* motion;
    const Mat4& getTransform() const
    {
        return *static_cast<const Mat4*>(motion);
    }
    HeadObj* getShape() const
    {
        return head;
    }
};

class LocalArr
{

  public:
    FUN_009c1aa0_Class entries[4];

    void __thiscall FUN_00d98390();

    void __thiscall FUN_00d98300();
};

struct LocalGroup
{
    HkVec4 to;
    HkVec4 from;
    Mask result;
    LocalArr arr;
};
struct BundleInput
{
    HkVec4 from[3];
    HkVec4 to[3];
    unsigned int filterInfo;
    const void* filter;
};
struct Cls
{

    int unk00;

    F04Obj* f04;

    AItem* f08;

    DestObj* f0c;

    BundleInput work;

    int flags80[4];

    void __thiscall hkKdTreeCpuBroadphaseBundleCastCollector_addMidPhaseHit(Param* p1, const Mask& p2);
};

// @fnv 0x00e4de10
// src: HAVOK_SRC 0x00e4de10
void __thiscall Cls::hkKdTreeCpuBroadphaseBundleCastCollector_addMidPhaseHit(Param* p1, const Mask& p2)
{
    HeadObj* head = p1->head;
    if (head)
    {
        const Mat4& transform = p1->getTransform();
        if (!f04 || f04->inner.Query(f08, p1).b)
        {
            work.from[0].SetTransformedPosition(transform, f08[0].r0);
            work.to[0].SetTransformedPosition(transform, f08[0].r1);
            work.from[1].SetTransformedPosition(transform, f08[1].r0);
            work.to[1].SetTransformedPosition(transform, f08[1].r1);
            work.from[2].SetTransformedPosition(transform, f08[2].r0);
            work.to[2].SetTransformedPosition(transform, f08[2].r1);
            HkVec4 tempFrom;
            tempFrom.SetTransformedPosition(transform, f08[3].r0);
            HkVec4 tempTo;
            tempTo.SetTransformedPosition(transform, f08[3].r1);
            {
                __m128 tmp3, tmp2, tmp1, tmp0;
                tmp0 = _mm_shuffle_ps((work.from[0]), (work.from[1]), 0x44);
                tmp2 = _mm_shuffle_ps((work.from[0]), (work.from[1]), 0xEE);
                tmp1 = _mm_shuffle_ps((work.from[2]), (tempFrom), 0x44);
                tmp3 = _mm_shuffle_ps((work.from[2]), (tempFrom), 0xEE);
                (work.from[0]) = _mm_shuffle_ps(tmp0, tmp1, 0x88);
                (work.from[1]) = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
                (work.from[2]) = _mm_shuffle_ps(tmp2, tmp3, 0x88);
                (tempFrom) = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
            }
            {
                __m128 tmp3, tmp2, tmp1, tmp0;
                tmp0 = _mm_shuffle_ps((work.to[0]), (work.to[1]), 0x44);
                tmp2 = _mm_shuffle_ps((work.to[0]), (work.to[1]), 0xEE);
                tmp1 = _mm_shuffle_ps((work.to[2]), (tempTo), 0x44);
                tmp3 = _mm_shuffle_ps((work.to[2]), (tempTo), 0xEE);
                (work.to[0]) = _mm_shuffle_ps(tmp0, tmp1, 0x88);
                (work.to[1]) = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
                (work.to[2]) = _mm_shuffle_ps(tmp2, tmp3, 0x88);
                (tempTo) = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
            }

            LocalArr bundleOutput;
            bundleOutput.FUN_00d98390();
            bundleOutput.FUN_00d98300();
            head->V28(&work, &bundleOutput, p2);
            for (int i = 0; i < 4; i++)
            {
                if (bundleOutput.entries[i].gate < 1.0f &&
                    (flags80[i] == 0 || bundleOutput.entries[i].gate < f0c->entries[i].gate))
                {
                    DestEntry* dst = &f0c->entries[i];
                    ((FUN_009c1aa0_Class*)dst)->ProcessEntries_009c1aa0(bundleOutput.entries[i]);
                    dst->info50 = *(int*)&(&bundleOutput.entries[i])[1].x;
                    f0c->entries[i].field50 = p1;
                    const KdRayRotation& rot = transform.getRotation();
                    ((HkVec4&)f0c->entries[i].u.row).SetRotatedDirection(rot, (const HkVec4&)bundleOutput.entries[i]);
                    float v;
                    if (f0c->flagc0 != 0)
                        v = 0.0f;
                    else
                        v = f0c->entries[i].gate;
                    f0c->entries[i].gate = v;
                    flags80[i] = 1;
                }
            }
        }
    }
}
