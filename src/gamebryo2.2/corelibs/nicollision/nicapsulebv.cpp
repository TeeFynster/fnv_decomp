#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiBoundingVolume.h"
#include "../../../../include/NiCapsuleBV.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiPoint3.h"
#include <string.h>

// src/gamebryo2.2/corelibs/nicollision/nicapsulebv.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicapsulebv.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00c1ba40
// src: GUESS 0x00c1ba40 (confidence: low)
int __cdecl Object_ComputeValue_00c1ba40()
{
    return 2;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
// Keep callers independent of the implementation while preserving the ECX argument.
void __fastcall UpdateCapsuleSegment(NiCapsuleBV* capsule);

// @fnv 0x00ea0700
NiBoundingVolume* NiCapsuleBV::Clone()
{
    NiCapsuleBV* pNewInstance = (NiCapsuleBV*)g_memoryManager.Allocate(0x3c);
    if (pNewInstance)
        return pNewInstance->CopyConstruct(*this);
    return 0;
}

struct ComparableRecord
{
    bool IsEquivalentWithEqualFloat(const ComparableRecord&) const;
};

// @fnv 0x00e9f170
int NiCapsuleBV::IsEqual(const NiBoundingVolume& kABV) const
{
    if (kABV.F3() == 2 && reinterpret_cast<const ComparableRecord*>(((const NiCapsuleBV&)kABV)._pad)->IsEquivalentWithEqualFloat(*reinterpret_cast<const ComparableRecord*>(_pad)))
        return 1;
    return 0;
}

// @fnv 0x00e9f280
void NiCapsuleBV::Copy(const NiBoundingVolume& kABV)
{
    NiCapsuleBV* kCBV = (NiCapsuleBV*)&kABV;
    m_kCenter = kCBV->m_kCenter;
    m_kAxisDirection = kCBV->m_kAxisDirection;
    m_fHalfLength = kCBV->m_fHalfLength;
    m_fBoundRadius = kCBV->m_fBoundRadius;
    UpdateCapsuleSegment(this);
}

extern int DAT_010f17d0;

// @fnv 0x00ea0640
__declspec(noinline) NiCapsuleBV* NiCapsuleBV::CopyConstruct(const NiCapsuleBV& source)
{
    *(void**)this = &DAT_010f17d0;
    reinterpret_cast<unsigned int&>(m_kCenter.x) = reinterpret_cast<const unsigned int&>(source.m_kCenter.x);
    reinterpret_cast<unsigned int&>(m_kCenter.y) = reinterpret_cast<const unsigned int&>(source.m_kCenter.y);
    reinterpret_cast<unsigned int&>(m_kCenter.z) = reinterpret_cast<const unsigned int&>(source.m_kCenter.z);
    reinterpret_cast<unsigned int&>(m_kAxisDirection.x) = reinterpret_cast<const unsigned int&>(source.m_kAxisDirection.x);
    reinterpret_cast<unsigned int&>(m_kAxisDirection.y) = reinterpret_cast<const unsigned int&>(source.m_kAxisDirection.y);
    reinterpret_cast<unsigned int&>(m_kAxisDirection.z) = reinterpret_cast<const unsigned int&>(source.m_kAxisDirection.z);
    m_fHalfLength = source.m_fHalfLength;
    m_fBoundRadius = source.m_fBoundRadius;
    UpdateCapsuleSegment(this);
    return this;
}

struct MatchList
{
    int unk00;
    int unk04;
    void** entries;
    unsigned short unk0c;
    unsigned short count;
    unsigned short unk10;
    unsigned short unk12;
    unsigned int foundIndex;
};
bool __cdecl NiBoundingVolume_FindTriIntersect(float value, void* item, unsigned int arg3, unsigned int arg4, unsigned int arg5,
                          unsigned int arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9,
                          unsigned int arg10, unsigned int arg11, unsigned int arg12);
// Scans list->entries for the first item accepted by FUN_00e9ca50, stores its index in list->foundIndex and returns true, otherwise returns false.
// @fnv 0x00e9ec10
// src: COMMUNITY 0x00e9ec10
bool __cdecl NiUnionBV_UnionTriFindIntersect(float value, MatchList* pMatchList, unsigned int arg3, unsigned int arg4, unsigned int arg5,
                          unsigned int arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9,
                          unsigned int arg10, unsigned int arg11, unsigned int arg12)
{
    for (unsigned int i = 0; i < pMatchList->count; ++i)
    {
        void* item = pMatchList->entries[i];
        if (NiBoundingVolume_FindTriIntersect(value, item, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12))
        {
            pMatchList->foundIndex = i;
            return true;
        }
    }
    return false;
}

extern double DAT_01011590;

struct S_00e9f1b0_P3
{
    float x, y, z;
    S_00e9f1b0_P3()
    {}
    S_00e9f1b0_P3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};
inline S_00e9f1b0_P3 operator*(const S_00e9f1b0_P3& p, float s)
{
    return S_00e9f1b0_P3(p.x * s, p.y * s, p.z * s);
}
inline S_00e9f1b0_P3 operator*(const S_00e9f1b0_P3& p, double s)
{
    return S_00e9f1b0_P3((float)(p.x * s), (float)(p.y * s), (float)(p.z * s));
}
inline S_00e9f1b0_P3 operator-(const S_00e9f1b0_P3& a, const S_00e9f1b0_P3& b)
{
    return S_00e9f1b0_P3(a.x - b.x, a.y - b.y, a.z - b.z);
}

// Computes m20 as m04 minus m10 scaled by (m1c - m38), and m2c as that scaled delta times DAT_01011590.
// @fnv 0x00e9f1b0
__declspec(noinline) void NiCapsuleBV::UpdateSegment()
{
    const S_00e9f1b0_P3& center = reinterpret_cast<const S_00e9f1b0_P3&>(m_kCenter);
    const S_00e9f1b0_P3& axis = reinterpret_cast<const S_00e9f1b0_P3&>(m_kAxisDirection);
    S_00e9f1b0_P3 origin = center - axis * (m_fHalfLength - m_fBoundRadius);
    memcpy(_pad, &origin, sizeof(origin));
    S_00e9f1b0_P3 direction = (axis * (m_fHalfLength - m_fBoundRadius)) * DAT_01011590;
    memcpy(_pad + 12, &direction, sizeof(direction));
}

extern float DAT_010141cc;
extern float DAT_01017d00;

struct S_00e9f400_P3
{
    float x, y, z;
};
struct S_00e9f400_Obj
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
    void InitFromParams(int a, int b, float c, float d, float e, int f);
    void Solve(int a, int b);
    float NiIntersector_GetContactTime();
    int FUN_00be0aa0();
    S_00e9f400_P3* NiIntersector_GetContactPoint();
    S_00e9f400_P3* NiIntersector_GetContactNormal();
    void SetVtbl();
};

// @fnv 0x00e9f400
// src: XBOX_PDB 0x00e9f400
bool __cdecl NiCapsuleBV_CapsuleSphereFindIntersect(float p1, int p2, int p3, int p4, int p5, float* p6, S_00e9f400_P3* p7, bool abWantNormal,
                          S_00e9f400_P3* p9, S_00e9f400_P3* p10)
{
    S_00e9f400_Obj obj;
    obj.InitFromParams(p2, p4, p1, DAT_01017d00, DAT_010141cc, 0x20);
    obj.Solve(p3, p5);
    *p6 = obj.NiIntersector_GetContactTime();
    if (obj.FUN_00be0aa0() != 3 && obj.FUN_00be0aa0() != 2)
    {
        obj.SetVtbl();
        return false;
    }
    *p7 = *obj.NiIntersector_GetContactPoint();
    if (abWantNormal)
    {
        *p9 = *obj.NiIntersector_GetContactNormal();
        S_00e9f400_P3 n;
        n.x = -p9->x;
        n.y = -p9->y;
        n.z = -p9->z;
        *p10 = n;
    }
    obj.SetVtbl();
    return true;
}

struct S_Vec3
{
    float x, y, z;
};

struct S_Seg
{
    S_Vec3 p;
    S_Vec3 d;
};

struct S_Sphere
{
    int unk00;
    S_Vec3 pos;
    float radius;
};

extern float DAT_011f426c;
extern float DAT_011f4270;
extern float DAT_011f4274;

float __cdecl NiSqrDistance_Compute(const S_Seg* a, const S_Seg* b, float* s, float* t);
float __cdecl DistanceSquaredToSegment(const S_Vec3* p, const S_Seg* b, float* s);

// @fnv 0x00e9f620
bool __cdecl SweepSphereAgainstCapsule(float t, NiCapsuleBV* apCapsule, const S_Vec3* from, S_Sphere* apSphere,
                                       const S_Vec3* to)
{
    S_Vec3 d;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    float fDistSq;
    float s;
    float fSegParam2;
    bool nz = d.x != DAT_011f426c || d.y != DAT_011f4270 || d.z != DAT_011f4274;
    if (nz)
    {
        S_Seg sweepSeg;
        d.x *= t;
        d.y *= t;
        d.z *= t;
        sweepSeg.p = apSphere->pos;
        sweepSeg.d = d;
        fDistSq = NiSqrDistance_Compute(&sweepSeg, reinterpret_cast<const S_Seg*>(apCapsule->_pad), &s, &fSegParam2);
    }
    else
    {
        fDistSq = DistanceSquaredToSegment(&apSphere->pos, reinterpret_cast<const S_Seg*>(apCapsule->_pad), &s);
    }
    float fRadiusSum = apCapsule->m_fBoundRadius + apSphere->radius;
    float fRadiusSumSq = fRadiusSum * fRadiusSum;
    return fDistSq <= fRadiusSumSq;
}

namespace fnv_00ea04b0 {
struct S_00ea04b0_Alloc
{
    void* Game_DoHeapAlloc(unsigned int sz) throw();
};

extern "C" S_00ea04b0_Alloc DAT_011f6238;

extern "C" NiPoint3 DAT_011f426c;
extern "C" NiPoint3 DAT_011a946c;

__forceinline void ConstructCapsule(NiCapsuleBV* p, NiPoint3 v1, NiPoint3 v2) throw()
{
    p->m_fHalfLength = 1.0f;
    p->m_fBoundRadius = 1.0f;
    *(void**)p = &DAT_010f17d0;
    reinterpret_cast<NiPoint3&>(p->m_kCenter) = v2;
    reinterpret_cast<NiPoint3&>(p->m_kAxisDirection) = v1;
    UpdateCapsuleSegment(p);
}

// Allocates a NiCapsuleBV from two global NiPoint3 values, calls vfn_00 with arg, and returns the object.
// @fnv 0x00ea04b0
NiCapsuleBV* CreateObjWithArg(void* arg)
{
    void* mem = DAT_011f6238.Game_DoHeapAlloc(0x3c);
    NiCapsuleBV* p;
    if (mem)
    {
        ConstructCapsule((NiCapsuleBV*)mem, DAT_011f426c, DAT_011a946c);
        p = (NiCapsuleBV*)mem;
    }
    else
    {
        p = 0;
    }
    p->LoadBinary(*static_cast<NiStream*>(arg));
    return p;
}
}  // namespace fnv_00ea04b0

// The two indirect calls pass &outCount as an argument; the out-count slot has
// to live in an inner scope so that MSVC keeps the call target in EDX *and*
// hoists the `mov edx, [ebx+8]` load to the top of the block (the outer-scope
// version puts the target in EAX, the direct-call version sinks the load).
struct Holder
{
    int unk00;
    int unk04;
    int(__cdecl* unk08)(Holder*, void*, unsigned int, unsigned int*, unsigned int);
};

struct SubA
{
    void FUN_00a59be0(unsigned int a1);
};

// The unused EDX argument preserves the original thiscall stack arguments.
void __cdecl LoadBoundingVolume();
typedef void (__thiscall* LoadBoundingVolumeFn)(NiBoundingVolume*, unsigned int);

// @fnv 0x00ea0540
void __fastcall LoadCapsuleBinary(NiCapsuleBV* capsule, void*, unsigned int a1)
{
    unsigned int obj = a1;
    reinterpret_cast<LoadBoundingVolumeFn>(&LoadBoundingVolume)(capsule, obj);
    reinterpret_cast<SubA*>((char*)capsule + 0x4)->FUN_00a59be0(obj);
    reinterpret_cast<SubA*>((char*)capsule + 0x10)->FUN_00a59be0(obj);

    {
        Holder* h = *(Holder**)((char*)obj + 0x24c);
        {
            unsigned int a1 = 4;
            int r1 = h->unk08(h, (char*)capsule + 0x1c, 4, &a1, 1);
            h->unk04 += r1;
        }
    }
    {
        Holder* h2 = *(Holder**)((char*)obj + 0x24c);
        {
            unsigned int a1 = 4;
            int r2 = h2->unk08(h2, (char*)capsule + 0x38, 4, &a1, 1);
            h2->unk04 += r2;
        }
    }

    UpdateCapsuleSegment(capsule);
}

struct S_00ea05c0_Bin;
typedef int(__cdecl* S_00ea05c0_Fn)(S_00ea05c0_Bin* b, void* buf, unsigned int size, int* count, unsigned int n);
struct S_00ea05c0_Bin
{
    int unk00;
    int m04;
    int unk08;
    S_00ea05c0_Fn m0c;
    int Read(void* buf, unsigned int size, int* count, unsigned int n)
    {
        return m0c(this, buf, size, count, n);
    }
};
__forceinline void BinW(S_00ea05c0_Bin* bin, void* v, unsigned int bytes)
{
    int sz = 4;
    bin->m04 += bin->Read(v, bytes, &sz, 1);
}

struct NiColorSaveHelper
{
    int a;
    int b;
    int c;
    void SaveBinary(void*);
};

// Keep stream parameters independent of the pending NiStream class/struct change.
void __cdecl SaveBoundingVolume();
typedef void (__thiscall* SaveBoundingVolumeFn)(NiBoundingVolume*, void*);

// Saves the base bounding volume, two point helpers, half-length, and radius.
// @fnv 0x00ea05c0
void __fastcall SaveCapsuleBinary(NiCapsuleBV* capsule, void*, void* stream)
{
    reinterpret_cast<SaveBoundingVolumeFn>(&SaveBoundingVolume)(capsule, stream);
    reinterpret_cast<NiColorSaveHelper*>(&capsule->m_kCenter)->SaveBinary(stream);
    reinterpret_cast<NiColorSaveHelper*>(&capsule->m_kAxisDirection)->SaveBinary(stream);
    BinW(*reinterpret_cast<S_00ea05c0_Bin**>((char*)stream + 0x250), &capsule->m_fHalfLength, 4);
    BinW(*reinterpret_cast<S_00ea05c0_Bin**>((char*)stream + 0x250), &capsule->m_fBoundRadius, 4);
}

namespace fnv_00ea0690 {
struct S_P3
{
    int x, y, z;
};

extern int DAT_011f426c;
extern int DAT_011f4270;
extern int DAT_011f4274;
extern int DAT_011a946c;
extern int DAT_011a9470;
extern int DAT_011a9474;

// Allocates a 0x3c-byte object, initializes its vtable, center and axis vectors and two floats to 1.0, calls FUN_00e9f1b0, and returns it.
// @fnv 0x00ea0690
// src: GAMEBRYO_SRC 0x00ea0690
NiCapsuleBV* __cdecl NiCapsuleBV_Create()
{
    NiCapsuleBV* p = (NiCapsuleBV*)g_memoryManager.Allocate(0x3c);
    if (p)
    {
        S_P3 c = {DAT_011f426c, DAT_011f4270, DAT_011f4274};
        S_P3 a = {DAT_011a946c, DAT_011a9470, DAT_011a9474};
        p->m_fHalfLength = 1.0f;
        p->m_fBoundRadius = 1.0f;
        *(void**)p = &DAT_010f17d0;
        reinterpret_cast<S_P3&>(p->m_kCenter) = c;
        reinterpret_cast<S_P3&>(p->m_kAxisDirection) = a;
        UpdateCapsuleSegment(p);
        return p;
    }
    return 0;
}
}  // namespace fnv_00ea0690

struct Vec3e
{
    float x, y, z;
};
struct IsectObj
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
    void Initialize(int a, int b, float c, float d, float e, int f);
    void Solve(int a, int b);
    float NiIntersector_GetContactTime();
    int FUN_00be0aa0();
    Vec3e* NiIntersector_GetContactPoint();
    Vec3e* NiIntersector_GetContactNormal();
    void SetVtbl();
};
extern float DAT_010141cc;
extern float DAT_01017d00;
// @fnv 0x00e9f510
// src: XBOX_PDB 0x00e9f510
bool __cdecl NiCapsuleBV_CapsuleCapsuleFindIntersect(float p1, int p2, int p3, int p4, int p5, float* p6, Vec3e* p7, bool abWantNormal, Vec3e* p9,
                          Vec3e* p10)
{
    IsectObj o;
    o.Initialize(p2, p4, p1, DAT_01017d00, DAT_010141cc, 0x20);
    o.Solve(p3, p5);
    *p6 = o.NiIntersector_GetContactTime();
    if (o.FUN_00be0aa0() != 3 && o.FUN_00be0aa0() != 2)
    {
        o.SetVtbl();
        return false;
    }
    *p7 = *o.NiIntersector_GetContactPoint();
    if (abWantNormal)
    {
        *p9 = *o.NiIntersector_GetContactNormal();
        Vec3e n = {-p9->x, -p9->y, -p9->z};
        *p10 = n;
    }
    o.SetVtbl();
    return true;
}

struct TrianglePointSet
{
    S_Vec3 m_kStartPoint;
    S_Vec3 m_kPoint1;
    S_Vec3 m_kPoint2;
};

extern const S_Vec3 NiPoint3_ZERO;

float __cdecl NiSqrDistance_Compute_00eaff20(const S_Seg* pkSeg, const TrianglePointSet* pkPgm, float* pfSegParam, float* pfPgmParam0,
                           float* pfPgmParam1);

inline S_Vec3 operator-(const S_Vec3& kA, const S_Vec3& kB)
{
    S_Vec3 kResult;
    kResult.x = kA.x - kB.x;
    kResult.y = kA.y - kB.y;
    kResult.z = kA.z - kB.z;
    return kResult;
}

inline S_Vec3 operator*(const S_Vec3& kA, float fScale)
{
    S_Vec3 kResult;
    kResult.x = kA.x * fScale;
    kResult.y = kA.y * fScale;
    kResult.z = kA.z * fScale;
    return kResult;
}

inline bool operator!=(const S_Vec3& kA, const S_Vec3& kB)
{
    return kA.x != kB.x || kA.y != kB.y || kA.z != kB.z;
}

// @fnv 0x00e9f760
bool __cdecl IsCapsuleSweptHit(float fTime, NiCapsuleBV* pkCapsule0, const S_Vec3* pkVelocity0, NiCapsuleBV* pkCapsule1,
                               const S_Vec3* pkVelocity1)
{
    S_Vec3 kRelVelocity = *pkVelocity1 - *pkVelocity0;
    float fParam0;
    float fParam1;
    float fSqrDist;
    if (kRelVelocity != NiPoint3_ZERO)
    {
        TrianglePointSet kSwept;
        kSwept.m_kStartPoint = reinterpret_cast<const S_Seg*>(pkCapsule1->_pad)->p;
        kSwept.m_kPoint1 = reinterpret_cast<const S_Seg*>(pkCapsule1->_pad)->d;
        kSwept.m_kPoint2 = kRelVelocity * fTime;
        fSqrDist = NiSqrDistance_Compute_00eaff20(reinterpret_cast<const S_Seg*>(pkCapsule0->_pad), &kSwept, &fSqrDist, &fParam0, &fParam1);
    }
    else
    {
        fSqrDist = NiSqrDistance_Compute(reinterpret_cast<const S_Seg*>(pkCapsule0->_pad), reinterpret_cast<const S_Seg*>(pkCapsule1->_pad), &fSqrDist, &fParam1);
    }

    float fRadiusSum = pkCapsule0->m_fBoundRadius + pkCapsule1->m_fBoundRadius;
    float fRadiusSqr = fRadiusSum * fRadiusSum;
    return fSqrDist <= fRadiusSqr;
}

struct S9f2c0_P3
{
    float x, y, z;
    S9f2c0_P3()
    {}
    S9f2c0_P3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    S9f2c0_P3 operator+(const S9f2c0_P3& p) const
    {
        return S9f2c0_P3(x + p.x, y + p.y, z + p.z);
    }
    S9f2c0_P3 operator*(float s) const
    {
        return S9f2c0_P3(x * s, y * s, z * s);
    }
};
struct S9f2c0_M3
{
    float m[3][3];
    S9f2c0_P3 operator*(const S9f2c0_P3& p) const
    {
        return S9f2c0_P3(m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z,
                         m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
                         m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z);
    }
};
// Transforms the capsule's center, axis, half-length, and bound radius from model to world space using the given transform, then calls FUN_00e9f1b0.
// @fnv 0x00e9f2c0
void NiCapsuleBV::TransformToWorld(const NiCapsuleBV& kModel, const NiTransform& kWorld)
{
    reinterpret_cast<S9f2c0_P3&>(m_kCenter) =
        (reinterpret_cast<const S9f2c0_M3&>(kWorld.m_Rotate) * reinterpret_cast<const S9f2c0_P3&>(kModel.m_kCenter)) *
        kWorld.m_fScale + reinterpret_cast<const S9f2c0_P3&>(kWorld.m_Translate);
    reinterpret_cast<S9f2c0_P3&>(m_kAxisDirection) =
        reinterpret_cast<const S9f2c0_M3&>(kWorld.m_Rotate) * reinterpret_cast<const S9f2c0_P3&>(kModel.m_kAxisDirection);
    m_fHalfLength = kWorld.m_fScale * kModel.m_fHalfLength;
    m_fBoundRadius = kWorld.m_fScale * kModel.m_fBoundRadius;
    UpdateCapsuleSegment(this);
}

inline NiPoint3::NiPoint3(float X, float Y, float Z) : x(X), y(Y), z(Z)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
inline NiPoint3 NiPoint3::operator*(float s) const
{
    return NiPoint3(x * s, y * s, z * s);
}
inline NiPoint3 NiPoint3::Cross(const NiPoint3& b) const
{
    return NiPoint3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
}
inline float NiPoint3::LengthSquared() const
{
    return x * x + y * y + z * z;
}
// Preserve the original call effects and ECX this argument.
__declspec(noalias) void __fastcall NormalizeCapsuleVector(NiPoint3* vector);
__declspec(noalias) float __cdecl CapsuleDotProduct();
typedef float (__thiscall* CapsuleDotProductFn)(const NiPoint3*, const NiPoint3&);

__forceinline NiPoint3 CopyConstructCapsuleVector(const NiPoint3& source)
{
    NiPoint3 result;
    result.x = source.x;
    result.y = source.y;
    result.z = source.z;
    return result;
}
__forceinline void CopyCapsuleVector(NiPoint3& target, const NiPoint3& source)
{
    memcpy(&target, &source, sizeof(target));
}
inline NiPoint3 operator*(float s, const NiPoint3& b)
{
    return NiPoint3(s * b.x, s * b.y, s * b.z);
}
struct CenterPoint
{
    float x, y, z;
    float Dot(const NiPoint3& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    NiPoint3 operator+(const NiPoint3& b) const
    {
        return NiPoint3(x + b.x, y + b.y, z + b.z);
    }
    NiPoint3 operator-(const NiPoint3& b) const
    {
        return NiPoint3(x - b.x, y - b.y, z - b.z);
    }
};
struct PtOp
{
    float x;
    float y;
    float z;
};

struct Trio
{
    NiPoint3 n;
    NiPoint3 tmp;
    NiPoint3 v;
};
struct Query
{
    NiPoint3 origin;
    NiPoint3 V;
    NiPoint3 U;
};
struct BigStruct
{
    NiPoint3 c20;
    NiPoint3 c2c;
    NiPoint3 prod;
};
float __cdecl NiSqrDistance_Compute_00eb1d20(NiPoint3* c20, Query* q, float* pf3c, float* p30, float* pftmp);
float __cdecl TriangleTriangleDistance(Query* q, BigStruct* bs, float* p30, float* pftmp, float* pR, float* pf3c);
// Tests capsule proximity to the triangle formed by pOrg, pA, and pB, then compares the computed squared distance with the squared radius.
// @fnv 0x00e9f8c0
bool __cdecl CapsuleTriangleIntersect(float afScale, NiCapsuleBV* apCapsule, NiPoint3* p2, NiPoint3* apOrigin, NiPoint3* apVecA,
                                      NiPoint3* apVecB, NiPoint3* apVec6)
{
    float tr, big;
    Query s;
    float fResult;
    NiPoint3 vDir;
    float i;
    CopyCapsuleVector(s.origin, *apOrigin);
    CopyCapsuleVector(s.V, *apVecA - *apOrigin);
    CopyCapsuleVector(s.U, *apVecB - *apOrigin);
    CopyCapsuleVector(vDir, *p2 - *apVec6);
    NiPoint3 n = -s.V.Cross(s.U);
    n.Dot(n);
    fResult = reinterpret_cast<const CenterPoint&>(apCapsule->m_kCenter).Dot(n);
    big = apCapsule->m_fHalfLength > apCapsule->m_fBoundRadius ? apCapsule->m_fHalfLength : apCapsule->m_fBoundRadius;
    i = apOrigin->Dot(n);
    float dist = fResult - i;
    if (dist * dist > (float)(n.LengthSquared() * big * big))
    {
        NormalizeCapsuleVector(&n);
        NiPoint3 point;
        if (fResult > i)
        {
            if (n.Dot(vDir) >= 0.0f)
                return false;
            CopyCapsuleVector(point, reinterpret_cast<const CenterPoint&>(apCapsule->m_kCenter) - big * n);
        }
        else
        {
            if (n.Dot(vDir) <= 0.0f)
                return false;
            NiPoint3 vOffset = big * n;
            CopyCapsuleVector(point, NiPoint3(reinterpret_cast<const CenterPoint&>(apCapsule->m_kCenter).x + vOffset.x, reinterpret_cast<const CenterPoint&>(apCapsule->m_kCenter).y + vOffset.y, reinterpret_cast<const CenterPoint&>(apCapsule->m_kCenter).z + vOffset.z));
        }
        i = apOrigin->Dot(n);
        NiPoint3 support = CopyConstructCapsuleVector(point);
        double dPlane = (double)i + (double)0.001f;
        tr = support.Dot(n);
        if (tr > dPlane)
        {
            CopyCapsuleVector(point, support + afScale * vDir);
            tr = point.Dot(n);
            if (tr > dPlane)
                return false;
        }
    }
    if (vDir.x != DAT_011f426c)
        goto ftmp;
    if (vDir.y != DAT_011f4270)
        goto ftmp;
    if (vDir.z != DAT_011f4274)
        goto ftmp;
    fResult = NiSqrDistance_Compute_00eb1d20(reinterpret_cast<NiPoint3*>(apCapsule->_pad), &s, &i, &fResult, &tr);
    goto done;
ftmp: {
    BigStruct bigStruct;
    CopyCapsuleVector(bigStruct.c20, *reinterpret_cast<const NiPoint3*>(apCapsule->_pad));
    CopyCapsuleVector(bigStruct.c2c, *reinterpret_cast<const NiPoint3*>(apCapsule->_pad + 12));
    CopyCapsuleVector(bigStruct.prod, afScale * vDir);
    fResult = TriangleTriangleDistance(&s, &bigStruct, &fResult, &tr, &big, &i);
}
done:
    return fResult <= apCapsule->m_fBoundRadius * apCapsule->m_fBoundRadius;
}

#include <math.h>
inline float magnitude(float value)
{
    return (float)fabs(value);
}
inline float dot3(const S_Vec3& a, const S_Vec3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline float component(const S_Vec3& v)
{
    return v.y;
}
inline S_Vec3 cross3(const S_Vec3& a, const S_Vec3& b)
{
    S_Vec3 v;
    v.x = component(a) * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - component(a) * b.x;
    return v;
}

// Computes the squared distance between segments a and b and writes the closest-point parameters s and t.
// @fnv 0x00eaf310
// src: XBOX_PDB 0x00eaf310
float __cdecl NiSqrDistance_Compute(const S_Seg& a, const S_Seg& b, float& s, float& t)
{
    float edge;
    S_Vec3 vDelta = a.p - b.p;
    float aa = dot3(a.d, a.d);
    float ab = -dot3(b.d, a.d);
    float bb = dot3(b.d, b.d);
    float ad = dot3(a.d, vDelta);
    float bd = -dot3(b.d, vDelta);
    float dd = dot3(vDelta, vDelta);
    float det = magnitude(aa * bb - ab * ab);
    const S_Vec3& vUB = b.d;
    S_Vec3 vCross = cross3(a.d, vUB);
    if (dot3(vCross, vCross) > 0.000001f)
    {
        s = ab * bd - bb * ad;
        t = ab * ad - aa * bd;
        if (s >= 0.0f)
        {
            if (s <= det)
            {
                if (t >= 0.0f)
                {
                    if (t <= det)
                    {
                        float inv = 1.0f / det;
                        s *= inv;
                        t *= inv;
                        return magnitude(s * (aa * s + ab * t + 2.0 * ad) + t * (ab * s + bb * t + 2.0 * bd) + dd);
                    }
                    t = 1.0f;
                    edge = ab + ad;
                    if (edge >= 0.0f)
                    {
                        s = 0.0f;
                        return magnitude(bb + 2.0 * bd + dd);
                    }
                    if (-edge >= aa)
                    {
                        s = 1.0f;
                        return magnitude(aa + bb + dd + 2.0 * (bd + edge));
                    }
                    s = -edge / aa;
                    return magnitude(edge * s + bb + 2.0 * bd + dd);
                }
                t = 0.0f;
                if (ad >= 0.0f)
                {
                    s = 0.0f;
                    return magnitude(dd);
                }
                if (-ad >= aa)
                {
                    s = 1.0f;
                    return magnitude(aa + 2.0 * ad + dd);
                }
                s = -ad / aa;
                return magnitude(ad * s + dd);
            }
            if (t >= 0.0f)
            {
                if (t <= det)
                {
                    s = 1.0f;
                    edge = ab + bd;
                    if (edge >= 0.0f)
                    {
                        t = 0.0f;
                        return magnitude(aa + 2.0 * ad + dd);
                    }
                    if (-edge >= bb)
                    {
                        t = 1.0f;
                        return magnitude(aa + bb + dd + 2.0 * (ad + edge));
                    }
                    t = -edge / bb;
                    return magnitude(edge * t + aa + 2.0 * ad + dd);
                }
                edge = ab + ad;
                if (-edge <= aa)
                {
                    t = 1.0f;
                    if (edge >= 0.0f)
                    {
                        s = 0.0f;
                        return magnitude(bb + 2.0 * bd + dd);
                    }
                    s = -edge / aa;
                    return magnitude(edge * s + bb + 2.0 * bd + dd);
                }
                s = 1.0f;
                edge = ab + bd;
                if (-edge >= bb)
                {
                    t = 1.0f;
                    return magnitude(aa + bb + dd + 2.0 * (ad + edge));
                }
                if (edge > 0.0f)
                {
                    t = 0.0f;
                    return magnitude(aa + 2.0 * ad + dd);
                }
                t = -edge / bb;
                return magnitude(edge * t + aa + 2.0 * ad + dd);
            }
            if (-ad < aa)
            {
                t = 0.0f;
                if (ad >= 0.0f)
                {
                    s = 0.0f;
                    return magnitude(dd);
                }
                s = -ad / aa;
                return magnitude(ad * s + dd);
            }
            s = 1.0f;
            edge = ab + bd;
            if (edge >= 0.0f)
            {
                t = 0.0f;
                return magnitude(aa + 2.0 * ad + dd);
            }
            if (-edge >= bb)
            {
                t = 1.0f;
                return magnitude(aa + bb + dd + 2.0 * (ad + edge));
            }
            t = -edge / bb;
            return magnitude(edge * t + aa + 2.0 * ad + dd);
        }
        if (t >= 0.0f)
        {
            if (t <= det)
            {
                s = 0.0f;
                if (bd >= 0.0f)
                {
                    t = 0.0f;
                    return magnitude(dd);
                }
                if (-bd >= bb)
                {
                    t = 1.0f;
                    return magnitude(bb + 2.0 * bd + dd);
                }
                t = -bd / bb;
                return magnitude(bd * t + dd);
            }
            edge = ab + ad;
            if (edge < 0.0f)
            {
                t = 1.0f;
                if (-edge >= aa)
                {
                    s = 1.0f;
                    return magnitude(aa + bb + dd + 2.0 * (bd + edge));
                }
                s = -edge / aa;
                return magnitude(edge * s + bb + 2.0 * bd + dd);
            }
            s = 0.0f;
            edge = bb + bd;
            if (edge <= 0.0f)
            {
                t = 1.0f;
                return magnitude(bb + 2.0 * bd + dd);
            }
            if (bd >= 0.0f)
            {
                t = 0.0f;
                return magnitude(dd);
            }
            t = -bd / bb;
            return magnitude(bd * t + dd);
        }
        if (ad < 0.0f)
        {
            t = 0.0f;
            if (-ad >= aa)
            {
                s = 1.0f;
                return magnitude(aa + 2.0 * ad + dd);
            }
            s = -ad / aa;
            return magnitude(ad * s + dd);
        }
        s = 0.0f;
        if (bd >= 0.0f)
        {
            t = 0.0f;
            return magnitude(dd);
        }
        if (-bd >= bb)
        {
            t = 1.0f;
            return magnitude(bb + 2.0 * bd + dd);
        }
        t = -bd / bb;
        return magnitude(bd * t + dd);
    }
    if (ab > 0.0f)
    {
        if (ad >= 0.0f)
        {
            s = 0.0f;
            t = 0.0f;
            return magnitude(dd);
        }
        if (-ad <= aa)
        {
            s = -ad / aa;
            t = 0.0f;
            return magnitude(ad * s + dd);
        }
        s = 1.0f;
        edge = aa + ad;
        if (-edge >= ab)
        {
            t = 1.0f;
            return magnitude(aa + bb + dd + 2.0 * (ab + ad + bd));
        }
        t = -edge / ab;
        return magnitude(aa + 2.0 * ad + dd + t * (bb * t + 2.0 * (ab + bd)));
    }
    if (-ad >= aa)
    {
        s = 1.0f;
        t = 0.0f;
        return magnitude(aa + 2.0 * ad + dd);
    }
    if (ad <= 0.0f)
    {
        s = -ad / aa;
        t = 0.0f;
        return magnitude(ad * s + dd);
    }
    s = 0.0f;
    if (ad >= -ab)
    {
        t = 1.0f;
        return magnitude(bb + 2.0 * bd + dd);
    }
    t = -ad / ab;
    return magnitude(dd + t * (2.0 * bd + bb * t));
}

#include <string.h>
void* __cdecl _NiMalloc_00aa1070(unsigned int);
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
struct S_00ea0730_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
};
// Formats name as "name = CAPSULE_BV", grows the array if needed, and appends the buffer pointer to arr.
// @fnv 0x00ea0730
void __stdcall AddCapsuleBV(const char* name, S_00ea0730_Arr* arr)
{
    unsigned int n = strlen(name) + 14;
    char* buf = (char*)_NiMalloc_00aa1070(n);
    FUN_00a305b0(buf, n, "%s = CAPSULE_BV", name);
    unsigned int i = arr->esize;
    if (i >= arr->size)
        arr->FUN_0096ad30(i + arr->growBy);
    arr->FUN_0096ae90(i, buf);
}

namespace fnv_00e9fdc0 {
__forceinline void CopyVector(NiPoint3& target, const NiPoint3& source)
{
    memcpy(&target, &source, sizeof(target));
}

__forceinline NiPoint3 AddCapsuleVectors(const NiPoint3& aa, const NiPoint3& bb)
{
    const NiPoint3& a = reinterpret_cast<const NiPoint3&>(aa);
    const NiPoint3& b = reinterpret_cast<const NiPoint3&>(bb);
    return NiPoint3(a.x + b.x, a.y + b.y, a.z + b.z);
}
struct CenterPoint
{
    float x, y, z;
    float Dot(const NiPoint3& b) const
    {
        float r = x * b.x + y * b.y + z * b.z;
        return r;
    }
    NiPoint3 FUN_00439e90(const NiPoint3& b) const;
    NiPoint3 SubtractIntoVector(const NiPoint3& b) const;
};
struct PtOp
{
    float x;
    float y;
    float z;
};

struct CapsuleSegment
{
    NiPoint3 p, d;
};
struct CollisionTriangle
{
    NiPoint3 p, u, v;
    NiPoint3 NiTrigon_GetNormal() const;
};
struct CapsuleTriangleQuery
{
    void* vtable;
    float maxTime, derivativeStep, inverseStep, threshold;
    int maxIterations, resultType;
    float contactTime;
    NiPoint3 contactPoint, contactNormal;
    NiCapsuleBV* capsule;
    CollisionTriangle triangle;
    float inverseRadiusSquared, segmentParameter, triangleParameter;
    void FUN_00eb3750(NiCapsuleBV*, const NiPoint3*, const NiPoint3*, const NiPoint3*, float, float, float, int);
    void Solve(int, int);
    float NiIntersector_GetContactTime();
    int FUN_00be0aa0();
    const NiPoint3* NiIntersector_GetContactPoint();
    const NiPoint3* NiIntersector_GetContactNormal();
    void SetVtbl();
};
__declspec(noalias) float __cdecl NiSqrDistance_Compute_00eb1d20(const CapsuleSegment*, const CollisionTriangle*, float*, float*, float*);
__declspec(noinline) NiPoint3 __cdecl FUN_004a3760(float s, const NiPoint3& v)
{
    return NiPoint3(s * v.x, s * v.y, s * v.z);
}
extern double DAT_0101dae8;
extern double DAT_01016978;
extern const float DAT_01011d78 = 0.0f;
struct DistanceData
{
    CapsuleSegment segment;
    NiPoint3 motion;
    CollisionTriangle triangle;
    float radiusSquared, segmentParameter, triangleU, triangleV;
};
// Tests a moving capsule against a triangle for static overlap and swept collision, returning contact time, point, and normal.
// @fnv 0x00e9fdc0
// src: XBOX_PDB 0x00e9fdc0
bool __cdecl NiCapsuleBV_CapsuleTriFindIntersect(float afTime, NiCapsuleBV* apCapsule, NiPoint3* a2, const NiPoint3* apTriA, NiPoint3* apTriB, NiPoint3* apTriC,
                          NiPoint3* a6, float* a7, NiPoint3* apPoint, bool abNormal, NiPoint3* apNormal, NiPoint3* apNormal2)
{
    DistanceData collisionData;
    CopyVector(collisionData.segment.p, *reinterpret_cast<const NiPoint3*>(apCapsule->_pad));
    CopyVector(collisionData.segment.d, *reinterpret_cast<const NiPoint3*>(apCapsule->_pad + 12));
    collisionData.radiusSquared = apCapsule->m_fBoundRadius * apCapsule->m_fBoundRadius;
    CopyVector(collisionData.triangle.p, *apTriA);
    CopyVector(collisionData.triangle.u, *apTriB - *apTriA);
    CopyVector(collisionData.triangle.v, *apTriC - *apTriA);
    float separation = NiSqrDistance_Compute_00eb1d20(&collisionData.segment, &collisionData.triangle, &collisionData.segmentParameter,
                                    &collisionData.triangleU, &collisionData.triangleV) -
                       collisionData.radiusSquared;
    if (separation <= 0.0f)
    {
        *a7 = 0.0f;
        CopyVector(*apPoint, (collisionData.triangle.p + collisionData.triangleU * collisionData.triangle.u) +
                   collisionData.triangleV * collisionData.triangle.v);
        if (abNormal)
        {
            CopyVector(*apNormal2, collisionData.triangle.NiTrigon_GetNormal());
            CopyVector(*apNormal, -*apNormal2);
        }
        return true;
    }
    NiPoint3 motion = *a2 - *a6;
    CopyVector(collisionData.motion, motion);
    float lengthSquared = collisionData.motion.LengthSquared();
    if (lengthSquared * afTime <= DAT_0101dae8)
        return false;
    NiPoint3 normal = -collisionData.triangle.u.Cross(collisionData.triangle.v);
    float centerPlane = reinterpret_cast<const CenterPoint&>(apCapsule->m_kCenter).Dot(normal);
    float extent = apCapsule->m_fHalfLength > apCapsule->m_fBoundRadius ? apCapsule->m_fHalfLength : apCapsule->m_fBoundRadius;
    float radiusPlaneSquared = normal.LengthSquared() * extent * extent;
    float trianglePlane = normal.Dot(*apTriA);
    float planeDistance = centerPlane - trianglePlane;
    if (planeDistance * planeDistance > radiusPlaneSquared)
    {
        NormalizeCapsuleVector(&normal);
        NiPoint3 support;
        if (centerPlane > trianglePlane)
        {
            float speed = motion.Dot(normal);
            if (speed >= DAT_01011d78)
                return false;
            CopyVector(support, reinterpret_cast<const NiPoint3&>(apCapsule->m_kCenter).SubtractIntoVector(FUN_004a3760(extent, normal)));
        }
        else
        {
            float speed = motion.Dot(normal);
            if (speed <= DAT_01011d78)
                return false;
            CopyVector(support, reinterpret_cast<const NiPoint3&>(apCapsule->m_kCenter).FUN_00439e90(FUN_004a3760(extent, normal)));
        }
        trianglePlane = normal.Dot(*apTriA);
        double planeLimit = trianglePlane + (double)0.001f;
        float supportPlane = normal.Dot(support);
        if (supportPlane > planeLimit)
        {
            if (reinterpret_cast<CapsuleDotProductFn>(&CapsuleDotProduct)(&normal, AddCapsuleVectors(support, FUN_004a3760(afTime, collisionData.motion))) >
                trianglePlane + (double)0.001f)
                return false;
        }
    }
    CapsuleTriangleQuery query;
    query.FUN_00eb3750(apCapsule, apTriA, apTriB, apTriC, afTime, DAT_01017d00, DAT_010141cc, 0x20);
    query.Solve((int)a2, (int)a6);
    *a7 = query.NiIntersector_GetContactTime();
    if (query.FUN_00be0aa0() != 3 && query.FUN_00be0aa0() != 2)
    {
        query.SetVtbl();
        return false;
    }
    const NiPoint3* point = query.NiIntersector_GetContactPoint();
    CopyVector(*apPoint, *point);
    if (abNormal)
    {
        const NiPoint3* pNormal = query.NiIntersector_GetContactNormal();
        CopyVector(*apNormal, *pNormal);
        CopyVector(*apNormal2, -*apNormal);
    }
    query.SetVtbl();
    return true;
}
}  // namespace fnv_00e9fdc0
