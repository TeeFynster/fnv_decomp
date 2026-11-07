#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/BSTreeNode.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/Transform.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/bhkCapsuleShape.h"
#include "../../../include/bhkConvexShape.h"
// bhkLimitedHingeVector_bstreenode_o2_nood_variant: local type (was include/bhkLimitedHingeVector.h, which had no evidence of one real class); its methods are 0x004b4db0 bhkVector4::operator=
class bhkLimitedHingeVector_bstreenode_o2_nood_variant
{
public:
    union
    {
        struct
        {
            int unk00;
            int unk04;
            int unk08;
            int unk0C;
        };
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float value[4];
        unsigned char vecData[16];
    };

    void SetQuaternionComponentsFromVector(const float*);
};
#include "../../../include/bhkShape.h"
#include "../../../include/bhkSphereRepShape.h"
#include "../../../include/hkVector4.h"
#include "../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../../include/NiPoint3.h"

// src/fallout_shared/speedtree/bstreenode_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy /GF (unit src/fallout_shared/speedtree/bstreenode.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/speedtree/bstreenode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreenode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>

struct Inner
{
    unsigned char unk00[0x14];
    void* m14;
    unsigned char unk18[0x18];
    __m128 rows[4];
};

struct Param
{
    unsigned char unk00[4];
    void* m4;
    unsigned char unk08[8];
    bhkLimitedHingeVector_bstreenode_o2_nood_variant vecs[4];
};

extern const __m128 g_01268370[4];

struct MyObj
{
    unsigned char unk00[8];
    Inner* m8;
    void __thiscall bhkShape_CopyCinfo(void*);
    void __thiscall bhkTransformShape_CopyCinfo(void*);
};

// @fnv 0x00c8c410
// src: XBOX_PDB 0x00c8c410
void __thiscall MyObj::bhkTransformShape_CopyCinfo(void* pArg)
{
    this->bhkShape_CopyCinfo(pArg);
    Param* p = (Param*)pArg;
    p->m4 = (this && this->m8) ? this->m8->m14 : 0;
    const __m128* src = (this && this->m8) ? (const __m128*)((char*)this->m8 + 0x30) : g_01268370;
    __m128 tmp[4];
    tmp[0] = src[0];
    tmp[1] = src[1];
    tmp[2] = src[2];
    tmp[3] = src[3];
    bhkLimitedHingeVector_bstreenode_o2_nood_variant* pv = p->vecs;
    pv[0].SetQuaternionComponentsFromVector((float*)tmp);
    pv[1].SetQuaternionComponentsFromVector((float*)&tmp[1]);
    pv[2].SetQuaternionComponentsFromVector((float*)&tmp[2]);
    pv[3].SetQuaternionComponentsFromVector((float*)&tmp[3]);
}

namespace fnv_00c8c5b0 {
extern unsigned int DAT_0126fd98;

struct AllocVt
{
    void* v0;
    void*(__thiscall* Alloc)(void*, unsigned int);
};
struct AllocObj
{
    AllocVt* vt;
};
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00cf5990
{
    unsigned int unk00;
    unsigned short w4;
    FUN_00cf5990(unsigned int, void*);
    void FUN_00c905b0();
    static void* operator new(unsigned int)
    {
        hkMemoryRouter* h = hkMemoryRouter_getInstance();
        AllocObj* al = reinterpret_cast<AllocObj*>(h->m_heap);
        FUN_00cf5990* p = (FUN_00cf5990*)al->vt->Alloc(al, 0x70);
        p->w4 = 0x70;
        return p;
    }
    static void operator delete(void*);
};

struct Inner
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int m10;
};
struct Mid
{
    unsigned int unk00, unk04;
    Inner* p;
};
struct Top
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    Mid* p;
};

struct Src
{
    unsigned int m0, m4;
    Top* m8;
    unsigned int mC;
    float f[16];
};

extern __declspec(thread) unsigned int DAT_000002b4;
struct Guard
{
    unsigned int saved;
    Guard() : saved(DAT_000002b4)
    {
        DAT_000002b4 = 0x10;
    }
    ~Guard()
    {
        DAT_000002b4 = saved;
    }
};
__forceinline Transform* InitializeTransform(Transform* transform, Src* apSrc)
{
    transform->r[0] = _mm_setr_ps(apSrc->f[0], apSrc->f[1], apSrc->f[2], apSrc->f[3]);
    transform->r[1] = _mm_setr_ps(apSrc->f[4], apSrc->f[5], apSrc->f[6], apSrc->f[7]);
    transform->r[2] = _mm_setr_ps(apSrc->f[8], apSrc->f[9], apSrc->f[10], apSrc->f[11]);
    transform->r[3] = _mm_setr_ps(apSrc->f[12], apSrc->f[13], apSrc->f[14], apSrc->f[15]);
    return transform;
}

struct TargetHolder
{
    void** vt;
    unsigned int unk04;
    Top* m8;
    unsigned int unk0C;
    unsigned int m10;
    void bhkTransformShape_Init(Src* apSrc);
};

// @fnv 0x00c8c5b0
// src: XBOX_PDB 0x00c8c5b0
void TargetHolder::bhkTransformShape_Init(Src* apSrc)
{
    Guard g0;
    // Keep the original alignment and /GS buffer treatment of the temporary.
    __declspec(align(16)) char storage[sizeof(Transform)];
    FUN_00cf5990* n = new FUN_00cf5990(apSrc->m4, InitializeTransform(reinterpret_cast<Transform*>(storage), apSrc));
    ((void(__thiscall*)(void*, FUN_00cf5990*))this->vt[35])(this, n);
    n->FUN_00c905b0();
    ((void(__thiscall*)(void*, Src*))this->vt[47])(this, apSrc);
    if (this->m8)
    {
        if (this->m8->p)
        {
            if (this->m8->p->p)
                this->m10 = this->m8->p->p->m10 & 0x1f;
        }
    }
}
}  // namespace fnv_00c8c5b0

struct Alloc
{
    virtual void v0();
    virtual void* Alloc_(unsigned int);
};
struct AudioTlsState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
};
struct Data8
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float unk20[4], unk30[4];
};
struct Output
{
    int unk00;
    float unk04;
    int unk08, unk0c;
    // The fourth lanes belong to this output record; shared NiPoint3 holds xyz.
    NiPoint3 unk10;
    float unk1c;
    NiPoint3 unk20;
    float unk2c;
    int unk30;
    int unk34;
    int unk38;
};
struct FUN_00d22dc0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int unk04;
    void* unk08;
    FUN_00d22dc0(const __m128&, const __m128&, float, int, int);
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
    static void* operator new(unsigned int n);
    static void operator delete(void*);
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Call(void*, void*, void*, const char*);
    int unk04;
    Data8* unk08;
    void bhkConvexShape_CopyCinfo(Output*);
    void bhkCapsuleShape_BuildDisplayGeometry(void*, void*);
};
extern unsigned int DAT_0126fd98;
extern float DAT_010c72bc;
extern float DAT_01267e30[];
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void* FUN_00d22dc0::operator new(unsigned int n)
{
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    Alloc* allocator = reinterpret_cast<Alloc*>(h->m_heap);
    void* p = allocator->Alloc_(n);
    *(short*)((char*)p + 4) = (short)n;
    return p;
}
extern __declspec(thread) AudioTlsState tls;
struct TlsRestore
{
    int old;
    TlsRestore()
    {
        AudioTlsState* td = &tls;
        old = td->unk2b4;
        td->unk2b4 = 0x10;
    }
    ~TlsRestore()
    {
        tls.unk2b4 = old;
    }
};
// @fnv 0x00cab1b0
// src: XBOX_PDB 0x00cab1b0
void Obj::bhkCapsuleShape_BuildDisplayGeometry(void* a1, void* a2)
{
    TlsRestore guard;
    Output out;
    out.unk04 = DAT_010c72bc;
    out.unk10.x = 0;
    out.unk10.y = 0;
    out.unk10.z = 0;
    out.unk1c = 0;
    out.unk00 = 0;
    out.unk20.x = 1;
    out.unk20.y = 0;
    out.unk20.z = 0;
    out.unk2c = 0;
    bhkConvexShape_CopyCinfo(&out);
    out.unk10.SetQuaternionComponentsFromVector(this && unk08 ? unk08->unk20 : DAT_01267e30);
    out.unk20.SetQuaternionComponentsFromVector(this && unk08 ? unk08->unk30 : DAT_01267e30);
    FUN_00d22dc0* sub =
        new FUN_00d22dc0(_mm_setr_ps(out.unk10.x, out.unk10.y, out.unk10.z, out.unk1c),
                         _mm_setr_ps(out.unk20.x, out.unk20.y, out.unk20.z, out.unk2c), out.unk04, 6, 1);
    sub->v4();
    void* inner = sub->unk08;
    if (inner)
        Call(a1, inner, a2, "bhkCapsuleShape");
}

struct SpawnedSource
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
};

struct SpawnedSourceOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void Apply(SpawnedSource* apSource);

    void bhkCapsuleShape_Init(__m128* apA, __m128* apB, float afT);
    void bhkCapsuleShape_Init_00cab820(SpawnedSource* apSource);
};

// @fnv 0x00cab820
// src: XBOX_PDB 0x00cab820
void SpawnedSourceOwner::bhkCapsuleShape_Init_00cab820(SpawnedSource* apSource)
{
    __m128 vA = _mm_setr_ps(apSource->m_f20, apSource->m_f24, apSource->m_f28, apSource->m_f2C);
    __m128 vB = _mm_setr_ps(apSource->m_f10, apSource->m_f14, apSource->m_f18, apSource->m_f1C);
    bhkCapsuleShape_Init(&vB, &vA, apSource->m_f04);
    Apply(apSource);
}

inline void hkVector4::operator=(const hkVector4& vector)
{
    m_vComponents = vector.m_vComponents;
}
inline void hkVector4::set(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

namespace fnv_00cb7c60 {
extern __declspec(thread) int g_tlsHeapContext;

struct HeapContextScope
{
    int m_saved;
    HeapContextScope()
    {
        m_saved = g_tlsHeapContext;
        g_tlsHeapContext = 16;
    }
    ~HeapContextScope()
    {
        g_tlsHeapContext = m_saved;
    }
};


struct hkMemAllocator;
hkMemoryRouter* hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemAllocator& alloc, void* array, int numElem, int sizeElem);

struct VecArrayLocalForm
{ // local form of hkArray: 0x00cb7c60 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    hkVector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    void GrowArrayCapacity(hkMemAllocator& a, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(a, this, newSize, sizeof(hkVector4));
        }
    }
    void _setSize(hkMemAllocator& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        _setSize(*reinterpret_cast<hkMemAllocator*>((&hkMemoryRouter_getInstance()->heap())), n);
    }
    void setSizeCleared(int n)
    {
        clear();
        SetSizeAndGrow(n);
    }
};

struct VertsOut
{
    int unk00;
    VecArrayLocalForm unk04;
};

struct VertsData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 unk20;
};

struct VertsSource
{
    int unk00;
    int unk04;
    VertsData* unk08;
    void bhkShape_CopyCinfo(VertsOut* out);
    int getNumVerts() const
    {
        return (this && unk08) ? unk08->unk10 : 0;
    }
    const hkVector4* getVerts() const
    {
        return (this && unk08) ? &unk08->unk20 : 0;
    }
    void bhkMultiSphereShape_CopyCinfo(VertsOut* out);
};

// @fnv 0x00cb7c60
// src: XBOX_PDB 0x00cb7c60
void VertsSource::bhkMultiSphereShape_CopyCinfo(VertsOut* out)
{
    HeapContextScope scope;
    bhkShape_CopyCinfo(out);
    int n = getNumVerts();
    out->unk04.clear();
    out->unk04.SetSizeAndGrow(n);
    const hkVector4* src = getVerts();
    for (int i = 0; i < n; i++)
        out->unk04.m_data[i] = src[i];
}
}  // namespace fnv_00cb7c60

namespace fnv_00cab710 {
extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;
}
inline bhkShape::bhkShape() : m_0c(0), m_10(0)
{
    ++fnv_00cab710::DAT_012680f8;
}
inline bhkSphereRepShape::bhkSphereRepShape()
{
    ++fnv_00cab710::DAT_01268274;
}
inline bhkConvexShape::bhkConvexShape()
{
    ++fnv_00cab710::DAT_01268250;
}

namespace fnv_00cab710 {
extern float DAT_01268328;
extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;


// Shared bhkCapsuleShape lacks this constructor and FUN_00cab0e0.
class bhkCapsuleShapeCtor : public bhkConvexShape
{
  public:
    bhkCapsuleShapeCtor(const NiPoint3& kPoint1, const NiPoint3& kPoint2, float fRadius);
    void bhkCapsuleShape_Init(const hkVector4& kA, const hkVector4& kB, float fRadius);
};

// @fnv 0x00cab710
bhkCapsuleShapeCtor::bhkCapsuleShapeCtor(const NiPoint3& kPoint1, const NiPoint3& kPoint2, float fRadius)
{
    // Preserve the original vector temporaries' alignment and /GS buffers.
    __declspec(align(16)) char storageA[sizeof(hkVector4)];
    hkVector4& kA = *reinterpret_cast<hkVector4*>(storageA);
    kA.set(kPoint1.x * DAT_01268328, kPoint1.y * DAT_01268328, kPoint1.z * DAT_01268328, 0.0f);
    __declspec(align(16)) char storageB[sizeof(hkVector4)];
    hkVector4& kB = *reinterpret_cast<hkVector4*>(storageB);
    kB.set(kPoint2.x * DAT_01268328, kPoint2.y * DAT_01268328, kPoint2.z * DAT_01268328, 0.0f);
    bhkCapsuleShape_Init(kA, kB, fRadius * DAT_01268328);
}
}  // namespace fnv_00cab710

extern "C" unsigned long __readfsdword(unsigned long);
namespace fnv_00cb7d80 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

extern volatile unsigned int DAT_0126fd98;
struct TlsGuard_t
{
    TlsBlock_t* thread;
    int m_saved;
    TlsGuard_t(int value)
    {
        unsigned index = DAT_0126fd98;
        thread = ((TlsBlock_t**)__readfsdword(0x2c))[index];
        m_saved = thread->m_2b4;
        thread->m_2b4 = value;
    }
    ~TlsGuard_t()
    {
        thread->m_2b4 = m_saved;
    }
};
extern unsigned int DAT_012683e0;
extern float DAT_011b1cd4;
extern char str_010c8900[];
extern char str_010c88f8[];
extern char str_010c88ec[];

char* __cdecl NiViewerStrings_NiGetViewerString_Title(unsigned int v);
char* __cdecl NiGetViewerString_00a7d4d0(const char* fmt, int v);
void __cdecl BSsprintf(char* buf, unsigned int size, const char* fmt, unsigned int idx);

struct NiStrArr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_w08;
    unsigned short m_w0A;
    unsigned short unk0C;
    unsigned short m_w0E;
    void FUN_0096ad30(unsigned int a);
    void FUN_0096ae90(unsigned int a, char** out);
    void append(char*& text)
    {
        unsigned count = m_w0A;
        if (count >= m_w08)
            FUN_0096ad30(count + m_w0E);
        FUN_0096ae90(count, &text);
    }
};

struct __declspec(align(16)) StrRec
{
    float x;
    float y;
    float z;
    float w;
};

struct StrNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int m_uiItemCount;
    int unk14;
    int unk18;
    int unk1C;
    StrRec records[1];
};

struct RecordCollection
{
    unsigned int unk00;
    unsigned int unk04;
    StrNode* m_08;

    void bhkSphereRepShape_GetViewerStrings(NiStrArr* a);

    void bhkMultiSphereShape_GetViewerStrings(NiStrArr* a1);
};

inline float getX(__m128 v)
{
    float r;
    _mm_store_ss(&r, v);
    return r;
}
inline float getY(__m128 v)
{
    float r;
    _mm_store_ss(&r, _mm_shuffle_ps(v, v, 0x55));
    return r;
}
inline float getZ(__m128 v)
{
    float r;
    _mm_store_ss(&r, _mm_shuffle_ps(v, v, 0xaa));
    return r;
}
union ScalarString
{
    float value;
    char* text;
};
inline NiPoint3 scale(__m128 v, float k)
{
    NiPoint3 r;
    r.x = getX(v) * k;
    r.y = getY(v) * k;
    r.z = getZ(v) * k;
    return r;
}
char* __cdecl NiGetViewerString_00a7d550(const char* buf, float f);

// @fnv 0x00cb7d80
// src: XBOX_PDB 0x00cb7d80
void RecordCollection::bhkMultiSphereShape_GetViewerStrings(NiStrArr* a1)
{
    TlsGuard_t guard(0x10);
    bhkSphereRepShape_GetViewerStrings(a1);
    int n;
    {
        char* text = NiViewerStrings_NiGetViewerString_Title(DAT_012683e0);
        a1->append(text);

        if (this != 0 && m_08 != 0)
        {
            n = m_08->m_uiItemCount;
        }
        else
        {
            n = 0;
        }
        text = NiGetViewerString_00a7d4d0(str_010c8900, n);

        a1->append(text);
    }

    if (this != 0)
    {
        StrNode* node = m_08;
        if (node != 0)
        {
            StrRec* rec = node->records;
            if (rec)
                for (int i = 0; i < n; ++i)
                {
                    __m128 cur = _mm_load_ps(&rec->x);
                    ScalarString scalar;
                    scalar.value = rec->w;
                    NiPoint3 pt = scale(cur, DAT_011b1cd4);
                    char buf[0x20];
                    BSsprintf(buf, 0x20, str_010c88f8, i);
                    {
                        char* t2 = pt.GetViewerString_00a59af0(buf);
                        a1->append(t2);
                    }
                    BSsprintf(buf, 0x20, str_010c88ec, i);
                    scalar.text = NiGetViewerString_00a7d550(buf, scalar.value);
                    a1->append(scalar.text);
                    ++rec;
                }
        }
    }
}
}  // namespace fnv_00cb7d80
