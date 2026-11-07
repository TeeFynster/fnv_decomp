
// src/staging/blk_00a20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <string.h>
// Constructor-free position and tangent payloads use PointStorage; Vec3 constructs objects.
#include "PointStorage.h"
#include "../../include/NiAnimationKey.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiBound.h"
#include "../../include/NiFloatInterpolator.h"
#include "../../include/NiKeyBasedInterpolator.h"
#include "../../include/NiQuaternion.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTStringPointerMap.h"
#include "../../include/NiColorA.h"
// LocalVector3: unit-local copy of the former shared stand-in Vector3. Same layout as NiPoint3; its inline operator*/operator+ build their result in a temporary, while this unit's NiPoint3 operators build theirs through the constructor (one NiPoint3 cannot carry both bodies).
class FloatMatrix3;

class LocalVector3
{
public:
    float x;
    float y;
    float z;

    LocalVector3()
    {
    }
    LocalVector3(float x, float y, float z) : x(x), y(y), z(z)
    {}
    LocalVector3(float x, int y, int z);

    LocalVector3 AddVector(const LocalVector3& other) const;
    LocalVector3 ScaleSwizzled(float scale) const;
    LocalVector3 operator*(double multiplier) const;
    LocalVector3 operator*(float multiplier) const;
    LocalVector3 operator+(const LocalVector3& right) const;
    LocalVector3 operator-(const LocalVector3& right) const
    {
        return LocalVector3(x - right.x, y - right.y, z - right.z);
    }
    LocalVector3& operator-=(const LocalVector3& right);
    LocalVector3& operator+=(const LocalVector3& right);
    float& operator[](int index);
    float Dot(const LocalVector3& right) const;
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
    void Normalize();
    float Length() const;

    LocalVector3 Diff_00b13040(const LocalVector3& other) const;
    LocalVector3 FUN_00b12890(const FloatMatrix3& matrix) const;
    LocalVector3 FUN_00b12810(const LocalVector3& other) const;
    void Normalize_00b12790();
    void __thiscall SubtractIntoVector(LocalVector3* dest, void* context);
    void __thiscall Unitize_004a0c10();
// src: GUESS 0x00439ef0 (confidence: high)
    LocalVector3 SubtractIntoVector(const LocalVector3& other) const
    {
        return LocalVector3(x - other.x, y - other.y, z - other.z);
    }
    float FUN_004a7290() const
    {
        return x * x + y * y + z * z;
    }
};
#include "../../include/MemoryManager.h"
#include "../../include/NiColor.h"
#include "../../include/NiStream.h"
// NiStreamStandInW_blk_00a20000_o2: local type (was include/NiStreamStandInW.h, which had no evidence of one real class); no method of it is bound to a named game function

struct NiStreamStandInW_blk_00a20000_o2
{
public:
    char _000[0x250];
    NiBinaryStream* m_pBackingStream;
};
#include "../../include/NiTFixedStringMap_NiAVObject___.h"
#include "../../include/NiPoint3.h"

inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& pt) const { return NiPoint3((x + pt.x), (y + pt.y), (z + pt.z)); }
inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const { return NiPoint3((x - pt.x), (y - pt.y), (z - pt.z)); }
inline NiPoint3 NiPoint3::operator*(float fScalar) const { return NiPoint3(x * fScalar, y * fScalar, z * fScalar); }
inline NiPoint3 operator*(float fScalar, const NiPoint3& pt) { return NiPoint3(fScalar * pt.x, fScalar * pt.y, fScalar * pt.z); }

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int read = m_pfnRead(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += read;
    return read;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int written = m_pfnWrite(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int size = sizeof(T);
    BinaryRead(&value, sizeof(T), &size, 1);
}

inline unsigned int NiBinaryStream::Read(void* value, unsigned int bytes)
{
    unsigned int size = bytes;
    return BinaryRead(value, bytes, &size, 1);
}

inline void NiBinaryStream::Write(void* value, unsigned int bytes)
{
    unsigned int size = bytes;
    BinaryWrite(value, bytes, &size, 1);
}

inline void NiBinaryStream::Write(void* value)
{
    unsigned int size = 4;
    BinaryWrite(value, 4, &size, 1);
}

inline float NiQuaternion::Dot(const NiQuaternion& p, const NiQuaternion& q)
{
    return (p.m_fVectorY * q.m_fVectorY) + p.m_fVectorX * q.m_fVectorX + p.m_fVectorZ * q.m_fVectorZ + p.m_fScalarPart * q.m_fScalarPart;
}

// @fnv 0x00a26f80
// src: GAMEBRYO_LIB 0x00a26f80
void NiBezFloatKey_Copy(float* afDest, const float* afSrc)
{
    afDest[0] = afSrc[0];
    afDest[1] = afSrc[1];
    afDest[2] = afSrc[2];
    afDest[3] = afSrc[3];
}

extern "C" int _NiPoint3_ZERO;
extern "C" unsigned int DAT_011f4270;
extern "C" unsigned int DAT_011f4274;

// @fnv 0x00a27470
// src: GUESS 0x00a27470 (confidence: low)
void __cdecl Runtime_UpdateState_00a27470(int a, int b, int c, int* pOut)
{
    pOut[0] = _NiPoint3_ZERO;
    pOut[1] = DAT_011f4270;
    pOut[2] = DAT_011f4274;
}

extern "C" void __cdecl ReadBlockEntries(void*, void*);

// Calls ReadBlockEntries for each of c elements, passing a and successive 0x48-byte records starting at b.
// @fnv 0x00a2a0e0
// src: GAMEBRYO_LIB 0x00a2a0e0
void __cdecl NiEulerRotKey_SaveToStream(void* a, void* b, unsigned int c)
{
    for (unsigned int i = 0; i < c; ++i)
        ReadBlockEntries(a, (char*)b + i * 0x48);
}

extern MemoryManager g_memoryManager;

// @fnv 0x00a2a600
// src: COMMUNITY 0x00a2a600
void NiStepPosKey_DeleteArray(void* p)
{
    if (p)
        g_memoryManager.Deallocate((char*)p - 4);
}

extern "C" void __cdecl SaveKey(int, int);

// Calls SaveKey(a, b) count times, advancing b by 0x4c each iteration.
// @fnv 0x00a2bb60
// src: GAMEBRYO_LIB 0x00a2bb60
void __cdecl NiTCBPosKey_SaveToStream(int aiArg, int aiBase, unsigned int count)
{
    if (count > 0)
    {
        for (unsigned int i = 0; i < count; ++i)
        {
            SaveKey(aiArg, aiBase);
            aiBase += 0x4c;
        }
    }
}

struct FUN_00a2cc10_T {
    float f;
    char c;
};

// @fnv 0x00a2cc10
// src: GAMEBRYO_LIB 0x00a2cc10
void __cdecl NiStepBoolKey_Copy(FUN_00a2cc10_T* dst, const FUN_00a2cc10_T* src)
{
    dst->f = src->f;
    dst->c = src->c;
}

// @fnv 0x00a2d1e0
void CopyFloat2(float* dst, const float* src)
{
    *dst = *src;
    dst[1] = src[1];
}

extern int DAT_011f49e0;
void __stdcall FUN_00a312d0(int, int, int, int, int);
// @fnv 0x00a31680
// src: GUESS 0x00a31680 (confidence: low)
void __cdecl Object_ForwardCall_00a31680()
{
    FUN_00a312d0((int)&DAT_011f49e0, (int)&DAT_011f49e0, (int)&DAT_011f49e0, (int)&DAT_011f49e0, (int)&DAT_011f49e0);
}

extern "C" float __cdecl GetAccumulatedValue();

struct FUN_00a3ea40_cls {
    void UpdateIfFlagged();
};

// @fnv 0x00a3ea40
void FUN_00a3ea40_cls::UpdateIfFlagged()
{
    if ((*(unsigned short*)((char*)this + 0xc) & 1) != 0)
    {
        *(float*)((char*)this + 0x24) = GetAccumulatedValue();
        *(unsigned short*)((char*)this + 0xc) &= 0xfffe;
    }
}

struct P03MM { void* Allocate(unsigned int); };
void* _memmove(void* d, const void* s, unsigned int n);


struct TCBKeyS {
    float time;
    PointStorage pos;
    PointStorage in;
    PointStorage out;
    float extra[6];
    ~TCBKeyS() {}
    static void* operator new[](unsigned int n) { return ((P03MM*)&g_memoryManager)->Allocate(n); }
    static void operator delete[](void* p, unsigned int) { g_memoryManager.Deallocate(p); }
};
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
NiPoint3 GetKeyPosAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);
void NiInterpScalar_AdjustBezier(float p0, float t0, float* tan0, float p1, float t1, float* tan1, float t, float p, float* a, float* b);
void ComputeTCBKeyTangents(TCBKeyS* keys, unsigned int count, unsigned int stride);

// @fnv 0x00a282a0
// src: GUESS 0x00a282a0 (confidence: low)
bool Object_CopyData_00a282a0(float afTime, TCBKeyS** pKeys, unsigned int* pCount)
{
    TCBKeyS* old = *pKeys;
    unsigned int idx;
    if (FindKeyIndex(afTime, old, *pCount, &idx, sizeof(TCBKeyS))) {
    TCBKeyS* keys = new TCBKeyS[*pCount + 1];
    _memmove(keys, old, idx * sizeof(TCBKeyS));
    if (*pCount > idx)
        _memmove(&keys[idx + 1], &old[idx], (*pCount - idx) * sizeof(TCBKeyS));
    NiPoint3 v = GetKeyPosAtTime(afTime, old, 2, *pCount, sizeof(TCBKeyS));
    TCBKeyS* cur = &keys[idx];
    cur->time = afTime;
    memcpy(&cur->pos, &v, sizeof(cur->pos));
    *(unsigned int*)&cur->in.x = (unsigned int)_NiPoint3_ZERO;
    *(unsigned int*)&cur->in.y = DAT_011f4270;
    *(unsigned int*)&cur->in.z = DAT_011f4274;
    *(unsigned int*)&cur->out.x = (unsigned int)_NiPoint3_ZERO;
    *(unsigned int*)&cur->out.y = DAT_011f4270;
    *(unsigned int*)&cur->out.z = DAT_011f4274;
    if (idx != 0 && idx != *pCount) {
        TCBKeyS* prev = &keys[idx - 1];
        TCBKeyS* next = &keys[idx + 1];
        float t0 = prev->time;
        PointStorage p0 = prev->pos;
        PointStorage tan0 = prev->out;
        float t1 = next->time;
        PointStorage p = cur->pos;
        PointStorage p1 = next->pos;
        PointStorage tan1 = next->in;
        PointStorage a, b;
        NiInterpScalar_AdjustBezier(p0.x, t0, &tan0.x, p1.x, t1, &tan1.x, afTime, p.x, &a.x, &b.x);
        NiInterpScalar_AdjustBezier(p0.y, t0, &tan0.y, p1.y, t1, &tan1.y, afTime, p.y, &a.y, &b.y);
        NiInterpScalar_AdjustBezier(p0.z, t0, &tan0.z, p1.z, t1, &tan1.z, afTime, p.z, &a.z, &b.z);
        prev->out = tan0;
        cur->in = a;
        cur->out = b;
        next->in = tan1;
    }
    ++*pCount;
    if (old)
        g_memoryManager.Deallocate((int*)old - 1);
    *pKeys = keys;
    ComputeTCBKeyTangents(keys, *pCount, sizeof(TCBKeyS));
    return true;
    }
    return false;
}

extern "C" unsigned char DAT_011f367d;
// @fnv 0x00a291d0
void StoreGlobalByte(int a, int b, int c, unsigned char* pDest)
{
    *pDest = DAT_011f367d;
}


// Calls Set on the object with each element of c multiplied by b, then returns the object.
// @fnv 0x00a2bc90
NiQuaternion* ScaleAndApply(NiQuaternion* apObject, float afScale, const float* afValues)
{
    apObject->SetValues(afScale * afValues[0], afScale * afValues[1], afScale * afValues[2], afScale * afValues[3]);
    return apObject;
}

// Copies seven consecutive floats from src to dst.
// @fnv 0x00a2c5d0
void CopyFloat7(float* dst, const float* src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
}


struct FUN_00a30880_T { void ReleaseItems(); };
struct HolderBase { void FUN_00a2e620(); };
// Partial view of the owning NiControllerManager, not a map.
class NiControllerSequence;
struct ControllerManagerStorage {
    char pad[0x34];
    HolderBase h1;
    unsigned short usSize1;
    void** pp1;
    unsigned short unk3c;
    unsigned short usSize2;
    char pad40[0x10];
    // NiControllerManager ctor 0x00a2eed0 stores base vftable 0x01096124
    // and final NiTStringPointerMap<NiControllerSequence*> vftable 0x01096260.
    NiTStringPointerMap<NiControllerSequence*> map;
    void ClearEntries();
};
// Iterates the pp1 array up to usSize2, calls ReleaseItems and zeroes offset 0x40 on each entry, then calls FUN_00a2e620 and RemoveAll on the embedded holders.
// @fnv 0x00a2e9a0
void ControllerManagerStorage::ClearEntries()
{
    unsigned int i = 0;
    if (i < usSize2) {
        do {
            FUN_00a30880_T* t = (FUN_00a30880_T*)pp1[i];
            if (t) {
                t->ReleaseItems();
                *(unsigned int*)((char*)t + 0x40) = 0;
            }
            i++;
        } while (i < usSize2);
    }
    ((HolderBase*)((char*)this + 0x34))->FUN_00a2e620();
    map.RemoveAll();
}

// @fnv 0x00a2ae10
void CopyFloatBlock(float* afDest, const float* afSource)
{
    *afDest = *afSource;
    *(int*)(afDest + 1) = *(int*)(afSource + 1);
    *(int*)(afDest + 2) = *(int*)(afSource + 2);
    *(int*)(afDest + 3) = *(int*)(afSource + 3);
    afDest[4] = afSource[4];
    afDest += 16;
    afSource += 16;
    afDest[-11] = afSource[-11];
    afDest[-10] = afSource[-10];
    *(int*)(afDest - 9) = *(int*)(afSource - 9);
    *(int*)(afDest - 8) = *(int*)(afSource - 8);
    *(int*)(afDest - 7) = *(int*)(afSource - 7);
    *(int*)(afDest - 6) = *(int*)(afSource - 6);
    *(int*)(afDest - 5) = *(int*)(afSource - 5);
    *(int*)(afDest - 4) = *(int*)(afSource - 4);
    *(int*)(afDest - 3) = *(int*)(afSource - 3);
    *(int*)(afDest - 2) = *(int*)(afSource - 2);
    *(int*)(afDest - 1) = *(int*)(afSource - 1);
    *(int*)(afDest) = *(int*)(afSource);
    *(int*)(afDest + 1) = *(int*)(afSource + 1);
    *(int*)(afDest + 2) = *(int*)(afSource + 2);
}

struct FUN_00a29a70 {
    float a, b, c, d;
    float e, f, g;
    char h, i, j;
    float k, l, m;
    float n, o, p;
    float q, r, s;
    FUN_00a29a70();
};
// @fnv 0x00a29a70
FUN_00a29a70::FUN_00a29a70()
{
    ((NiQuaternion*)((char*)this + 4))->SetValues(0.0f, 0.0f, 0.0f, 0.0f);
    *(unsigned int*)((char*)this + 0x14) = 0;
    *(unsigned int*)((char*)this + 0x18) = 0;
    *(unsigned int*)((char*)this + 0x1c) = 0;
    *(unsigned int*)((char*)this + 0x30) = 0;
    *(unsigned int*)((char*)this + 0x34) = 0;
    *(unsigned int*)((char*)this + 0x38) = 0;
    *(unsigned int*)((char*)this + 0x20) = 0;
    *(unsigned int*)((char*)this + 0x24) = 0;
    *(unsigned int*)((char*)this + 0x28) = 0;
    *(unsigned int*)((char*)this + 0x3c) = 0;
    *(unsigned int*)((char*)this + 0x40) = 0;
    *(unsigned int*)((char*)this + 0x44) = 0;
    *(char*)((char*)this + 0x2c) = 0;
    *(char*)((char*)this + 0x2d) = 0;
    *(char*)((char*)this + 0x2e) = 0;
}

void __cdecl IsLightEqual();
void __cdecl NiTCBPosKey_Interpolate();
void __cdecl ComputeInterpolatedPosition();
void __cdecl NiTCBPosKey_InterpolateD2();
void __cdecl NiTCBPosKey_FillDerivedVals();
void __cdecl NiTCBPosKey_ComputeMaxCurvature();
void __cdecl InsertBezPosKey();

// Stores seven function pointers into seven global tables at the slot computed from a and b.
// @fnv 0x00a2baa0
// src: GUESS 0x00a2baa0 (confidence: medium)
void __cdecl Object_SetKeyFunctionTables(int a, int b)
{
    unsigned int idx = (b + a * 6) * 4;
    *(void**)(0x011f3d20 + idx) = (void*)NiTCBPosKey_ComputeMaxCurvature;
    *(void**)(0x011f3c90 + idx) = (void*)NiTCBPosKey_Interpolate;
    *(void**)(0x011f3c00 + idx) = (void*)ComputeInterpolatedPosition;
    *(void**)(0x011f3b70 + idx) = (void*)NiTCBPosKey_InterpolateD2;
    *(void**)(0x011f3ae0 + idx) = (void*)IsLightEqual;
    *(void**)(0x011f3780 + idx) = (void*)NiTCBPosKey_FillDerivedVals;
    *(void**)(0x011f3810 + idx) = (void*)InsertBezPosKey;
}

struct FUN_00a2ceb0_cls {
    float pad;
    float x, y, z, w;
    FUN_00a2ceb0_cls& Clear();
};

// @fnv 0x00a2ceb0
FUN_00a2ceb0_cls& FUN_00a2ceb0_cls::Clear() {
    w = z = y = x = 0.0f;
    return *this;
}

extern unsigned char DAT_01096968;
typedef int (__stdcall *FnInterlockedDecrement)(void*);
extern FnInterlockedDecrement DAT_00fdf1c4;
struct FUN_00a31260_StandIn {
    void* p0;
    void* p1;
    void* p2;
    unsigned char b3;
    unsigned char b4;
    void ReleaseReferencedObjectsAndResetFlags();
};
// Releases p0 and p1 via an interlocked decrement and virtual destructor when the count reaches zero, then clears p2 and sets b3/b4.
// @fnv 0x00a31260
// src: GUESS 0x00a31260 (confidence: medium)
void FUN_00a31260_StandIn::ReleaseReferencedObjectsAndResetFlags()
{
    FnInterlockedDecrement pfnDecrement = DAT_00fdf1c4;
    void* obj;
    obj = p0;
    if (obj) {
        if (pfnDecrement((char*)obj + 4) == 0)
            ((void (__thiscall*)(void*))(*(void***)obj)[1])(obj);
        p0 = 0;
    }
    obj = p1;
    if (obj) {
        if (pfnDecrement((char*)obj + 4) == 0)
            ((void (__thiscall*)(void*))(*(void***)obj)[1])(obj);
        p1 = 0;
    }
    p2 = 0;
    b3 = DAT_01096968;
    b4 = 0xff;
}

struct FUN_00a30700_T {
    void* p0;
    void* p1;
    void ReleaseRefs();
};

// @fnv 0x00a30700
void FUN_00a30700_T::ReleaseRefs()
{
    FnInterlockedDecrement fn = DAT_00fdf1c4;
    void* p;

    p = p1;
    if (p)
    {
        if (fn((char*)p + 4) == 0)
        {
            void** vt = *(void***)p;
            ((void (__thiscall*)(void*))vt[1])(p);
        }
    }

    p = p0;
    if (p)
    {
        if (fn((char*)p + 4) == 0)
        {
            void** vt = *(void***)p;
            ((void (__thiscall*)(void*))vt[1])(p);
        }
    }
}

struct Base_00a26eb0 {
    void AccumulateAnimSink(NiStream&);
};
struct FUN_00a27430_T : Base_00a26eb0 {
    char pad[4];
    NiColor m_kDiffuseColor;
    void LoadBinaryFields_00a27430(NiStream& stream);
};
// @fnv 0x00a27430
// src: GUESS 0x00a27430 (confidence: medium)
void FUN_00a27430_T::LoadBinaryFields_00a27430(NiStream& stream)
{
    Base_00a26eb0::AccumulateAnimSink(stream);
    m_kDiffuseColor.LoadBinary(stream);
}

void BezKeyEqual();
void EvaluateCubicKey();
void NiBezPosKey_InterpolateD1();
void NiBezPosKey_InterpolateD2();
void NiBezPosKey_ComputeMaxCurvature();

extern int DAT_011f3d20;
extern int DAT_011f3c90;
extern int DAT_011f3c00;
extern int DAT_011f3b70;
extern int DAT_011f3ae0;
extern int DAT_011f3780;
extern int DAT_011f3810;

// @fnv 0x00a28620
// src: GUESS 0x00a28620 (confidence: low)
void Object_UpdateFields_00a28620(int param_1, int param_2)
{
    int iVar1 = (param_2 + param_1 * 6) * 4;
    *(void**)((char*)&DAT_011f3d20 + iVar1) = (void*)NiBezPosKey_ComputeMaxCurvature;
    *(void**)((char*)&DAT_011f3c90 + iVar1) = (void*)EvaluateCubicKey;
    *(void**)((char*)&DAT_011f3c00 + iVar1) = (void*)NiBezPosKey_InterpolateD1;
    *(void**)((char*)&DAT_011f3b70 + iVar1) = (void*)NiBezPosKey_InterpolateD2;
    *(void**)((char*)&DAT_011f3ae0 + iVar1) = (void*)BezKeyEqual;
    *(void**)((char*)&DAT_011f3780 + iVar1) = (void*)ComputeTCBKeyTangents;
    *(void**)((char*)&DAT_011f3810 + iVar1) = (void*)Object_CopyData_00a282a0;
}

struct Helper { unsigned int a; char b; };
bool AreFloatsEqual(const Helper* x, const Helper* y);
// Returns false if AreFloatsEqual fails for the two Helpers, otherwise returns whether their b fields are equal.
// @fnv 0x00a291a0
// src: GAMEBRYO_LIB 0x00a291a0
bool NiBoolKey_Equal(const Helper* apFirst, const Helper* apSecond)
{
    if (!AreFloatsEqual(apFirst, apSecond)) return false;
    return apFirst->b == apSecond->b;
}

// NiColorA does not yet declare LoadBinary; preserve its original member-call ABI.
extern "C" void NiColorA_LoadBinary();

namespace fnv_00a29640 {
struct Base_00a26eb0 {
    void AccumulateAnimSink(NiStream&);
};

struct FUN_00a29640_T : Base_00a26eb0 {
    char pad[4];
    NiColorA m_kDiffuseColor;
    void ProcessState_00a29640(NiStream& stream);
};
// @fnv 0x00a29640
// src: GUESS 0x00a29640 (confidence: low)
void FUN_00a29640_T::ProcessState_00a29640(NiStream& stream)
{
    AccumulateAnimSink(stream);
    ((void (__thiscall*)(NiColorA*, NiStream&))NiColorA_LoadBinary)(&m_kDiffuseColor, stream);
}
}  // namespace fnv_00a29640

struct SStream;
struct SObj;
void __cdecl WriteFloatToStream(SStream*, SObj*);

// Calls WriteFloatToStream for each of c SObj entries starting at b, advancing 8 bytes per entry.
// @fnv 0x00a2d230
// src: COMMUNITY 0x00a2d230
void __cdecl NiAnimationKey_SaveToStream(SStream* pStream, SObj* b, unsigned int c)
{
    if (c > 0) {
        SObj* d = b;
        unsigned int n = c;
        do {
            WriteFloatToStream(pStream, d);
            d = (SObj*)((char*)d + 8);
        } while (--n);
    }
}

namespace fnv_00a2d5b0 {
void __cdecl Object_ComputeValue_00a291e0();
void __cdecl SelectKeyVec();
void __cdecl NiStepPosKey_InterpolateD1();
void __cdecl Object_AreDataEqual_Thunk();
void __cdecl Object_CopyData_00a2d4a0();
void __cdecl Object_DoNothing();
extern unsigned int DAT_011f3d20;
extern unsigned int DAT_011f3c90;
extern unsigned int DAT_011f3c00;
extern unsigned int DAT_011f3b70;
extern unsigned int DAT_011f3ae0;
extern unsigned int DAT_011f3780;
extern unsigned int DAT_011f3810;

// Fills the seven function-pointer tables at index (param_2 + param_1 * 6) * 4 with the given handler addresses.
// @fnv 0x00a2d5b0
// src: GUESS 0x00a2d5b0 (confidence: medium)
void NiStepPosKey_InterpolateD1_RegisterSevenKeyHandlers(int param_1, int param_2)
{
    int iVar1 = (param_2 + param_1 * 6) * 4;
    *(void**)((char*)&DAT_011f3d20 + iVar1) = (void*)&Object_ComputeValue_00a291e0;
    *(void**)((char*)&DAT_011f3c90 + iVar1) = (void*)&SelectKeyVec;
    *(void**)((char*)&DAT_011f3c00 + iVar1) = (void*)&NiStepPosKey_InterpolateD1;
    *(void**)((char*)&DAT_011f3b70 + iVar1) = (void*)&Runtime_UpdateState_00a27470;
    *(void**)((char*)&DAT_011f3ae0 + iVar1) = (void*)&Object_AreDataEqual_Thunk;
    *(void**)((char*)&DAT_011f3780 + iVar1) = (void*)&Object_DoNothing;
    *(void**)((char*)&DAT_011f3810 + iVar1) = (void*)&Object_CopyData_00a2d4a0;
}
}  // namespace fnv_00a2d5b0


extern int DAT_01096114;
extern void __cdecl _NiFree(void*);
extern MemoryManager _g_memoryManager;

struct FUN_00a2e790_StandIn : public NiTFixedStringMap_NiAVObject___ {
    void* p;
    void* DestroyFixedStringMap(unsigned char deleting);
};

// @fnv 0x00a2e790
void* FUN_00a2e790_StandIn::DestroyFixedStringMap(unsigned char deleting)
{
    *(void**)this = (void*)&DAT_01096114;
    RemoveAll();
    _NiFree(p);
    if (deleting & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00a39120_cls {
    float x, y, z, w;
    NiQuaternion* ScaleFourComponents(NiQuaternion* out, float s);
};

// Multiplies x, y, z and w by s, stores the result in out via Set, and returns out.
// @fnv 0x00a39120
// src: GUESS 0x00a39120 (confidence: medium)
NiQuaternion* FUN_00a39120_cls::ScaleFourComponents(NiQuaternion* out, float afScale)
{
    out->SetValues(x * afScale, y * afScale, z * afScale, w * afScale);
    return out;
}

struct FloatRecord_b5532
{
    int unk00;
    float m_04;
};

bool AreFloatsEqual(FloatRecord_b5532* a, FloatRecord_b5532* b);

// Returns true if AreFloatsEqual(a, b) succeeds and the two records' m_04 floats are equal.
// @fnv 0x00a26b00
bool AreRecordsEqual(FloatRecord_b5532* apRecordA, FloatRecord_b5532* apRecordB)
{
    if (!AreFloatsEqual(apRecordA, apRecordB))
    {
        return false;
    }
    return apRecordA->m_04 == apRecordB->m_04;
}

typedef void (__thiscall *Fn_00a26fa0_cb)(void *);

// Walks a strided array backwards: the callback is invoked with
// pBase + step*(count-1) down to pBase, one element per step.
// @fnv 0x00a26fa0
void __stdcall ApplyCallbackBackwards(char *pBase, int iStride, int nCount, Fn_00a26fa0_cb pFn)
{
    pBase += iStride * nCount;
    while (--nCount >= 0) {
        pBase -= iStride;
        pFn(pBase);
    }
}

struct TempArrayElement
{
    void* a;
    void* b;
    void* c;
    void* d;
    ~TempArrayElement() {}
    static void* operator new[](unsigned int size)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(size);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};

// Allocates an array of TempArrayElement of the given count using the memory manager's operator new[].
// @fnv 0x00a27040
TempArrayElement* __cdecl AllocateTempArray(unsigned int count)
{
    return new TempArrayElement[count];
}

extern MemoryManager g_memoryManager;

void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS;
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);

struct BezFloatKey {
    float time;
    float value;
    float inTan;
    float outTan;
    ~BezFloatKey() {}
    static void* operator new[](unsigned int n) { return ((P03MM*)&g_memoryManager)->Allocate(n); }
    static void operator delete[](void* p, unsigned int) { g_memoryManager.Deallocate(p); }
};

float GenInterpFloat(float t, BezFloatKey* keys, int type, unsigned int count, unsigned int stride);
void NiInterpScalar_AdjustBezier(float p0, float t0, float* tan0, float p1, float t1, float* tan1, float t, float p, float* a, float* b);

// Inserts a new BezFloatKey at fTime into the key array, reallocating it, interpolating the value, and recomputing tangents for neighbouring keys.
// @fnv 0x00a27080
// src: GUESS 0x00a27080 (confidence: medium)
bool Object_InsertBezierFloatKey(float fTime, BezFloatKey*& pkKeys, unsigned int& uiNumKeys)
{
    unsigned int uiInsertIndex;
    BezFloatKey* pkOld = pkKeys;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkOld, uiNumKeys, &uiInsertIndex, 16))
    {

    BezFloatKey* pkNewKeys = new BezFloatKey[uiNumKeys + 1];
    _memmove(pkNewKeys, pkOld, uiInsertIndex * 16);
    if (uiNumKeys > uiInsertIndex)
        _memmove((char*)pkNewKeys + uiInsertIndex * 16 + 16, (char*)pkOld + uiInsertIndex * 16,
                 (uiNumKeys - uiInsertIndex) * 16);

    float fValue = GenInterpFloat(fTime, pkOld, 2, uiNumKeys, 16);
    BezFloatKey* pkNew = (BezFloatKey*)((char*)pkNewKeys + uiInsertIndex * 16);
    pkNew->time = fTime;
    pkNew->value = fValue;
    pkNew->inTan = 0.0f;
    pkNew->outTan = 0.0f;

    if (uiInsertIndex != 0 && uiInsertIndex != uiNumKeys)
    {
        BezFloatKey* pkPrev = (BezFloatKey*)((char*)pkNewKeys + (uiInsertIndex - 1) * 16);
        BezFloatKey* pkNext = (BezFloatKey*)((char*)pkNewKeys + (uiInsertIndex + 1) * 16);
        float fPrevValue = pkPrev->value;
        float fPriorKeyTime = pkPrev->time;
        float fPrevOutTan = pkPrev->outTan;
        float fNextValue = pkNext->value;
        float fNextTime = pkNext->time;
        float fNextInTan = pkNext->inTan;
        float fInTan, fOutTan;
        NiInterpScalar_AdjustBezier(fPrevValue, fPriorKeyTime, &fPrevOutTan, fNextValue, fNextTime, &fNextInTan,
                     fTime, fValue, &fInTan, &fOutTan);
        pkPrev->outTan = fPrevOutTan;
        pkNew->inTan = fInTan;
        pkNew->outTan = fOutTan;
        pkNext->inTan = fNextInTan;
    }

    uiNumKeys++;
    if (pkOld)
        g_memoryManager.Deallocate((unsigned int*)pkOld - 1);
    pkKeys = pkNewKeys;
    return true;
    }
    return false;
}

class A27250Heap {
public:
    void* Allocate(unsigned int uiSize);
};




class A27250Stream {
public:
    int unk000;
    int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030;
    int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060;
    int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090;
    int unk094; int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0;
    int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0;
    int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120;
    int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C; int unk150;
    int unk154; int unk158; int unk15C; int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180;
    int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0;
    int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0;
    int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204; int unk208; int unk20C; int unk210;
    int unk214; int unk218; int unk21C; int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240;
    int unk244; int unk248;
    NiBinaryStream* m_pUnderlyingStream;
};

template <class T>
inline void A27250BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void A27250LoadBinary(A27250Stream& kStream, T& value)
{
    A27250BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

class A27250FloatKey {
public:
    ~A27250FloatKey();

    static void* operator new[](unsigned int uiSize)
    {
        return reinterpret_cast<A27250Heap&>(g_memoryManager).Allocate(uiSize);
    }

    void LoadBinary(A27250Stream& kStream);

    float m_fTime;
    float m_fValue;
    float m_fForwardTangent;
    float m_fBackwardTangent;
};

// Allocates an array of uiNumKeys float keys, loads each key via LoadBinary plus its two extra floats from kStream, and returns the array.
// @fnv 0x00a27250
A27250FloatKey* LoadFloatKeys(A27250Stream& kStream, unsigned int uiNumKeys)
{
    A27250FloatKey* pkKeys = new A27250FloatKey[uiNumKeys];
    for (unsigned int i = 0; i < uiNumKeys; i++) {
        pkKeys[i].LoadBinary(kStream);
        A27250LoadBinary(kStream, pkKeys[i].m_fForwardTangent);
        A27250LoadBinary(kStream, pkKeys[i].m_fBackwardTangent);
    }
    return pkKeys;
}

// ApplyAnimToTarget: forwards two arguments to CallAnimCallback, then calls the
// member at +4 of the second argument with the first argument.
struct AnimNode
{
    void Apply(int n);
};

struct AnimTarget
{
    int unk00;
    AnimNode m_node;
};

void __cdecl CallAnimCallback(int a, void* b);

// Calls CallAnimCallback with a and b, then applies animation node in b using a.
// @fnv 0x00a27450
void __cdecl ApplyAnimToTarget(int a, AnimTarget* apTarget)
{
    CallAnimCallback(a, apTarget);
    apTarget->m_node.Apply(a);
}

struct FUN_00a27b60_tail {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00a27b60_rec {
    float m_f00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
};

// Copies a 0x40-byte record from src to dst field by field, including a trailing three-word block.
// @fnv 0x00a27b60
// src: GAMEBRYO_LIB 0x00a27b60
void __cdecl NiBezPosKey_Copy(FUN_00a27b60_rec* apDest, const FUN_00a27b60_rec* apSource)
{
    apDest->m_f00 = apSource->m_f00;
    apDest->unk04 = apSource->unk04;
    apDest->unk08 = apSource->unk08;
    apDest->unk0C = apSource->unk0C;
    apDest->unk10 = apSource->unk10;
    apDest->unk14 = apSource->unk14;
    apDest->unk18 = apSource->unk18;
    apDest->unk1C = apSource->unk1C;
    apDest->unk20 = apSource->unk20;
    apDest->unk24 = apSource->unk24;
    apDest->unk28 = apSource->unk28;
    apDest->unk2C = apSource->unk2C;
    apDest->unk30 = apSource->unk30;
    apDest = (FUN_00a27b60_rec*)((char*)apDest + 0x34);
    apSource = (const FUN_00a27b60_rec*)((const char*)apSource + 0x34);
    ((FUN_00a27b60_tail*)apDest)->unk00 = ((const FUN_00a27b60_tail*)apSource)->unk00;
    ((FUN_00a27b60_tail*)apDest)->unk04 = ((const FUN_00a27b60_tail*)apSource)->unk04;
    ((FUN_00a27b60_tail*)apDest)->unk08 = ((const FUN_00a27b60_tail*)apSource)->unk08;
}

struct A27BD0Point3 {
    float x;
    float y;
    float z;

    bool IsEqual(const A27BD0Point3& kOther) const;
};

struct A27BD0Key {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

bool A27BD0KeyEqual(const A27BD0Key& kA, const A27BD0Key& kB);

struct A27BD0BezKey : A27BD0Key {
    float m_fValue;
    float m_fInTangent;
    float m_fOutTangent;
    A27BD0Point3 m_kTCB;
};

// Compares two BezKey records: base key fields, value, in/out tangents and TCB point, returning true only if all are equal.
// @fnv 0x00a27bd0
bool BezKeyEqual(const A27BD0BezKey& kA, const A27BD0BezKey& kB)
{
    if (!A27BD0KeyEqual(kA, kB))
        return false;
    return kA.m_fValue == kB.m_fValue && kA.m_fInTangent == kB.m_fInTangent && kA.m_fOutTangent == kB.m_fOutTangent
        && kA.m_kTCB.IsEqual(kB.m_kTCB);
}

struct DynamicMemoryAllocator {
    void* Allocate(unsigned int auiSize);
    void Free(void* apPtr);
};

extern "C" DynamicMemoryAllocator DAT_011f6238;

struct Elem64 {
    int unk00;
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

    static void* operator new[](unsigned int aSize) { return DAT_011f6238.Allocate(aSize); }
    static void operator delete[](void* apBlock) { DAT_011f6238.Free(apBlock); }
    ~Elem64() {}
};

// Allocates an array of Elem64 elements using the custom allocator and returns the block pointer.
// @fnv 0x00a27c40
void* AllocateElem64Array(unsigned int count)
{
    return new Elem64[count];
}

class A27C80Point3 {
public:
    float x, y, z;

    A27C80Point3() {}
    A27C80Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}

    A27C80Point3 operator+(const A27C80Point3& pt) const { return A27C80Point3(x + pt.x, y + pt.y, z + pt.z); }
    A27C80Point3 operator*(float fScalar) const { return A27C80Point3(x * fScalar, y * fScalar, z * fScalar); }
};

struct A27C80CubicKey {
    float m_fTime;
    A27C80Point3 m_kValue;
    A27C80Point3 m_kTangent;
    A27C80Point3 m_kB;
    A27C80Point3 m_kC;
    A27C80Point3 m_kCubicCoefficient;
};

// @fnv 0x00a27c80
void EvaluateCubicKey(float fTime, const A27C80CubicKey& kKey, unsigned int uiUnused, A27C80Point3& kResult) {
    kResult = kKey.m_kValue + (kKey.m_kB + (kKey.m_kC + kKey.m_kCubicCoefficient * fTime) * fTime) * fTime;
}

extern double DAT_01021928;
extern double DAT_01011590;
// Scales the key's extra components by t and two constants, sums them into a direction, offsets it by t, adds key->out and stores the result.
// @fnv 0x00a27d60
// src: GAMEBRYO_LIB 0x00a27d60
void __cdecl NiBezPosKey_InterpolateD1(float afTime, TCBKeyS* key, unsigned int type, PointStorage* result)
{
    const float scaled = static_cast<float>(DAT_01021928 * afTime);
    PointStorage fromScaled = {key->extra[3] * scaled, key->extra[4] * scaled, key->extra[5] * scaled};
    PointStorage fromDefault = {static_cast<float>(DAT_01011590 * key->extra[0]),
                         static_cast<float>(DAT_01011590 * key->extra[1]),
                         static_cast<float>(DAT_01011590 * key->extra[2])};
    PointStorage direction = {fromScaled.x + fromDefault.x, fromScaled.y + fromDefault.y, fromScaled.z + fromDefault.z};
    PointStorage offset = {afTime * direction.x, afTime * direction.y, afTime * direction.z};
    PointStorage translated = {key->out.x + offset.x, key->out.y + offset.y, key->out.z + offset.z};
    *result = translated;
}

namespace fnv_00a27e40 {
extern "C" const double DAT_01034208;
extern "C" const double DAT_01011590;
struct Vec3Output { float x,y,z; };
// @fnv 0x00a27e40
// src: GAMEBRYO_LIB 0x00a27e40
extern "C" void __cdecl NiBezPosKey_InterpolateD2(float radians, const float* transform, unsigned int mode, Vec3Output* output) {
    radians = (float)(radians * DAT_01034208);
    Vec3Output offset;
    offset.x = radians * transform[13];
    offset.y = radians * transform[14];
    offset.z = radians * transform[15];
    Vec3Output base;
    base.x = (float)(transform[10] * DAT_01011590);
    base.y = (float)(transform[11] * DAT_01011590);
    base.z = (float)(transform[12] * DAT_01011590);
    Vec3Output sum;
    sum.x = base.x + offset.x;
    sum.y = reinterpret_cast<volatile Vec3Output&>(offset).y + base.y;
    sum.z = base.z + offset.z;
    *output = sum;
}
}  // namespace fnv_00a27e40

class A281E0Heap {
public:
    void* Allocate(unsigned int uiSize);
};

class A281E0Stream;

struct A281E0Point3 {
    float x;
    float y;
    float z;

    void LoadBinary(A281E0Stream& kStream);
};

class A281E0BezPosKey {
public:
    ~A281E0BezPosKey();

    static void* operator new[](unsigned int uiSize)
    {
        return reinterpret_cast<A281E0Heap&>(g_memoryManager).Allocate(uiSize);
    }

    void LoadBinary(A281E0Stream& kStream);

    float m_fTime;
    A281E0Point3 m_kPos;
    A281E0Point3 m_kInTan;
    A281E0Point3 m_kOutTan;
    int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
};

// @fnv 0x00a281e0
A281E0BezPosKey* LoadBezPosKeys(A281E0Stream& kStream, unsigned int uiNumKeys)
{
    A281E0BezPosKey* pkKeys = new A281E0BezPosKey[uiNumKeys];
    for (unsigned int i = 0; i < uiNumKeys; i++) {
        pkKeys[i].LoadBinary(kStream);
        pkKeys[i].m_kInTan.LoadBinary(kStream);
        pkKeys[i].m_kOutTan.LoadBinary(kStream);
    }
    return pkKeys;
}

class NiStream;

class NiColorSaveHelper {
public:
    float r;
    float g;
    float b;

    void SaveBinary(NiStream& kStream);
};

struct A28260Key {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiColorSaveHelper m_kColor0;
    NiColorSaveHelper m_kColor1;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

void __cdecl ApplyAnimToTarget(NiStream& kStream, A28260Key* pkKey);

// For each of uiNumKeys keys, saves the key via ApplyAnimToTarget and then saves its two colors to kStream.
// @fnv 0x00a28260
void __cdecl SaveKeyArray(NiStream& kStream, A28260Key* pkKeys, unsigned int uiNumKeys)
{
    for (unsigned int ui = 0; ui < uiNumKeys; ui++)
    {
        A28260Key* pkKey = &pkKeys[ui];
        ApplyAnimToTarget(kStream, pkKey);
        pkKey->m_kColor0.SaveBinary(kStream);
        pkKey->m_kColor1.SaveBinary(kStream);
    }
}

// The identity quaternion setter at 0x00a6db50 returns this in EAX; the shared declaration discards it.
typedef NiQuaternion* (NiQuaternion::*ReturningQuaternionSetter)(float, float, float, float);

// @fnv 0x00a286e0
// src: GAMEBRYO_LIB 0x00a286e0
void NiRotKey_Interpolate(unsigned int auiUnused0, unsigned int auiUnused1, unsigned int auiUnused2, NiQuaternion* out)
{
    unsigned int storage[sizeof(NiQuaternion) / sizeof(unsigned int)];
    NiQuaternion* holder = reinterpret_cast<NiQuaternion*>(storage);
    NiQuaternion* src = (holder->*reinterpret_cast<ReturningQuaternionSetter>(&NiQuaternion::SetValues))(1.0f, 0.0f, 0.0f, 0.0f);
    memcpy(out, src, sizeof(*out));
}

struct FUN_00a28720_target {
    void __thiscall FUN_00a6e4a0(void* value);
};

void __cdecl CallAnimCallback(void* a, void* b);

// Calls CallAnimCallback with a and b, then invokes FUN_00a6e4a0 on the object at b+4 passing a.
// @fnv 0x00a28720
// src: GUESS 0x00a28720 (confidence: low)
void __cdecl Object_ProcessState_00a28720(void* a, void* b) {
    CallAnimCallback(a, b);
    reinterpret_cast<FUN_00a28720_target*>(
        reinterpret_cast<char*>(b) + 4)->FUN_00a6e4a0(a);
}

extern "C" unsigned int DAT_011f366c;
extern "C" unsigned int DAT_011f3670;
extern "C" unsigned int DAT_011f3674;
extern "C" unsigned int DAT_011f3678;
void __cdecl FUN_00a28740(void* out, float t, void* keys, void* arg4, unsigned int n, unsigned int* pIdx, unsigned char stride);

struct FUN_00a289b0_Vec4 {
    unsigned int a, b, c, d;
};

// @fnv 0x00a289b0
FUN_00a289b0_Vec4* __cdecl SampleKeyedVec4(FUN_00a289b0_Vec4* out, float fTime, char* keys, void* arg4, unsigned int count, unsigned char stride)
{
    if (count != 0) {
        if (fTime < *(float*)keys) {
            unsigned int* v = (unsigned int*)(keys + 4);
            out->a = v[0];
            out->b = v[1];
            out->c = v[2];
            out->d = v[3];
            return out;
        }
        if (*(float*)(keys + (count - 1) * stride) < fTime) {
            *out = *(FUN_00a289b0_Vec4*)(keys + (count - 1) * stride + 4);
            return out;
        }
        unsigned int idx = 0;
        FUN_00a28740(out, fTime, keys, arg4, count, &idx, stride);
        return out;
    }
    out->a = DAT_011f366c;
    out->b = DAT_011f3670;
    out->c = DAT_011f3674;
    out->d = DAT_011f3678;
    return out;
}

struct Sub_a28 {
    int unk00;
    bool Object_HasEqualFloatComponents(Sub_a28* other);
};

struct Obj_a28 {
    int unk00;
    Sub_a28 m_kSub;
};

bool __cdecl AreFloatsEqual(Obj_a28* a, Obj_a28* b);

// Returns false if AreFloatsEqual(a, b) fails, otherwise returns the result of comparing a->m_kSub with b->m_kSub via FUN_00a92660.
// @fnv 0x00a28a80
// src: GUESS 0x00a28a80 (confidence: low)
bool __cdecl Object_ProcessAndReturnValue_00a28a80(Obj_a28* apObjA, Obj_a28* apObjB)
{
    if (!AreFloatsEqual(apObjA, apObjB))
        return false;
    return apObjA->m_kSub.Object_HasEqualFloatComponents(&apObjB->m_kSub);
}

struct Blk16 {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};
struct Blk36 {
    float m_00;
    Blk16 m_04;
    Blk16 m_14;
};
// Copies the m_00 float and the m_04 and m_14 blocks from src into dst.
// @fnv 0x00a28d40
void CopyBlk36(Blk36* dst, const Blk36* src) {
    dst->m_00 = src->m_00;
    dst->m_04 = src->m_04;
    dst->m_14 = src->m_14;
}

struct SpawnTarget
{
    void Callee(float a, void* p1, void* p2, void* p3, void* p4);
};

// Calls Callee on z, passing a and pointers into the buffers x and y at offsets 4 and 0x14.
// @fnv 0x00a28d90
void __cdecl CallSpawnTarget(float afValue, char* pBufferX, char* pBufferY, SpawnTarget* pTarget)
{
    pTarget->Callee(afValue, pBufferX + 4, pBufferX + 0x14, pBufferY + 0x14, pBufferY + 4);
}

// Reconstruction of FUN_00a28dc0.
//
// The object is a fixed-size array of 36-byte key records:
//   +0x00  quaternion q0   (16 bytes)
//   +0x10  quaternion q1   (16 bytes)
//   +0x20  float           ( 4 bytes)
// The key array itself starts at obj+0x04 (obj+0x00 is a scalar header).

struct FNVQuat {
    float x;
    float y;
    float z;
    float w;
};

struct FNVKey {
    FNVQuat q0;
    FNVQuat q1;
    float   e;
};

struct FNVAnim {
    float   f00;
    FNVKey  keys[64];
};

extern void  __cdecl NiRotKey_FillDerivedVals(FNVAnim* obj, unsigned int count, unsigned int flag);
extern FNVQuat* __cdecl NiQuaternion_Intermediate(FNVQuat* out, FNVQuat* a, FNVQuat* b, FNVQuat* c);

// For count >= 2, calls FUN_00a28ab0 then fills each key's q1 with FUN_00a6dd50 results from neighbouring q0 values, clamping the ends.
// @fnv 0x00a28dc0
// src: GAMEBRYO_LIB 0x00a28dc0
void __cdecl NiBezRotKey_FillDerivedVals(FNVAnim* pAnim, unsigned int count, unsigned int flag)
{
    if (count < 2) {
        return;
    }

    NiRotKey_FillDerivedVals(pAnim, count, flag);

    FNVQuat qTmp;

    // i == 0 : the "previous" key degenerates to the key itself.
    FNVQuat* pResult0 = NiQuaternion_Intermediate(&qTmp, &pAnim->keys[0].q0, &pAnim->keys[0].q0, &pAnim->keys[1].q0);
    pAnim->keys[0].q1 = *pResult0;

    unsigned int last = count - 1;

    if (last > 1) {
        unsigned int n = last - 1;
        FNVKey* p = &pAnim->keys[1];
        do {
            FNVQuat* pResult1 = NiQuaternion_Intermediate(&qTmp, &p[-1].q0, &p->q0, &p[1].q0);
            p->q1 = *pResult1;
            p++;
        } while (--n);
    }

    // i == count-1 : the "next" key degenerates to the key itself.
    FNVQuat* pResult2 = NiQuaternion_Intermediate(&qTmp, &pAnim->keys[count - 2].q0, &pAnim->keys[last].q0, &pAnim->keys[last].q0);
    pAnim->keys[last].q1 = *pResult2;
}

// The game class NiBound - a 16-byte bound (three position floats and a radius).


// UHelper layout as read off the image: a float at +0, then two 16-byte
// NiBound sub-objects at +4 and at +0x14.
struct UHelper {
    float unk00;
    NiBound unk04;
    NiBound unk14;
};

// The primary comparison: the float at +0 and the NiBound sub-object at +4.
bool Object_ProcessAndReturnValue_00a28a80(UHelper* a, UHelper* b);

// Adds the comparison of the NiBound sub-object at +0x14.
// Returns false if FUN_00a28a80 fails; otherwise compares the unk14 NiBound of both UHelper objects via FUN_00a92660.
// @fnv 0x00a28ea0
bool CompareBounds(UHelper* pFirst, UHelper* pSecond) {
    if (!Object_ProcessAndReturnValue_00a28a80(pFirst, pSecond)) {
        return false;
    }
    return pFirst->unk14.Object_HasEqualFloatComponents(pSecond->unk14);
}

namespace fnv_00a28ed0 {
// FUN_00a28ed0: cdecl loop calling FUN_00a28720(base, elem) over count elements of stride 0x24.

void __cdecl Object_ProcessState_00a28720(void* base, void* elem);

// Calls FUN_00a28720 on each 0x24-byte element in the array, iterating count times.
// @fnv 0x00a28ed0
// src: GAMEBRYO_LIB 0x00a28ed0
void __cdecl NiBezRotKey_SaveToStream(void* base, char* elems, unsigned int count)
{
    unsigned int n = count;
    if (n > 0)
    {
        char* cur = elems;
        do
        {
            Object_ProcessState_00a28720(base, cur);
            cur += 0x24;
            n--;
        } while (n != 0);
    }
}
}  // namespace fnv_00a28ed0

typedef void (__cdecl *A291F0Func)();

void __cdecl Object_ComputeValue_00a291e0();
void __cdecl A291F0CurveA();
void __cdecl A291F0CurveB();
void __cdecl A291F0CurveC();
void __cdecl NiBoolKey_Equal();
void __cdecl Object_DoNothing();

extern A291F0Func g_akA291F0FillDerived[6][6];
extern A291F0Func g_akA291F0CurveA[6][6];
extern A291F0Func g_akA291F0CurveB[6][6];
extern A291F0Func g_akA291F0CurveC[6][6];
extern A291F0Func g_akA291F0Insert[6][6];
extern A291F0Func g_akA291F0Interp[6][6];
extern A291F0Func g_akA291F0Cubic[6][6];

// Fills the per-content/per-type slots of seven curve operation tables with the given function pointers, clearing the cubic slot.
// @fnv 0x00a291f0
void __cdecl RegisterCurveOps(int eContent, int eType)
{
    g_akA291F0FillDerived[eContent][eType] = Object_ComputeValue_00a291e0;
    g_akA291F0CurveA[eContent][eType] = A291F0CurveA;
    g_akA291F0CurveB[eContent][eType] = A291F0CurveB;
    g_akA291F0CurveC[eContent][eType] = A291F0CurveC;
    g_akA291F0Insert[eContent][eType] = NiBoolKey_Equal;
    g_akA291F0Interp[eContent][eType] = Object_DoNothing;
    g_akA291F0Cubic[eContent][eType] = 0;
}

struct FUN_00a29550_stream;
typedef int (__cdecl *FUN_00a29550_fn)(FUN_00a29550_stream*, int, int, int*, int);
struct FUN_00a29550_stream {
    unsigned int unk00;
    int m_04;
    unsigned int unk08;
    FUN_00a29550_fn m_0c;
};
struct FUN_00a29550_owner {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    FUN_00a29550_stream* m_250;
};

// @fnv 0x00a29550
// src: GUESS 0x00a29550 (confidence: low)
int __cdecl Runtime_UpdateState_00a29550(int apOwner, int a2) {
    FUN_00a29550_stream* s = reinterpret_cast<FUN_00a29550_owner*>(apOwner)->m_250;
    FUN_00a29550_fn fn = s->m_0c;
    apOwner = 1;
    int r = fn(s, a2, 1, &apOwner, 1);
    s->m_04 += r;
    return r;
}

struct Inner {
    void FUN_00a698a0(void* target);
};
struct Outer {
    int unk00;
    Inner inner04;
};
void __cdecl CallAnimCallback(void* target, Outer* source);
// Calls CallAnimCallback with target and source, then invokes source->inner04.FUN_00a698a0 on target.
// @fnv 0x00a29660
// src: GUESS 0x00a29660 (confidence: low)
void __cdecl Object_ProcessState_00a29660(void* target, Outer* source)
{
    CallAnimCallback(target, source);
    source->inner04.FUN_00a698a0(target);
}

// Reconstruction of UpdateArrayElements (0x00a29e40, 189 bytes).
//
// The original does two things:
//
//  1) If the caller's "already initialised" flag is still zero it lazily
//     allocates one element of the game's FUN_00a29a70 object through the
//     global memory manager and hands the pointer back to the caller.
//     The allocation is the game's array-new support: the memory manager
//     returns 0x4c bytes (the 0x48 byte element plus a 4 byte element count
//     that is stored in front of the element) and the vector constructor
//     iterator then runs the element constructor on it.
//     The iterator is the non-EH four argument one (it pops its own
//     arguments), which is why the expansion is written out here instead of
//     using a `new[]` expression: with /EHsc the compiler would emit the
//     five argument EH flavour plus an exception handling frame.
//
//  2) It then walks the three parallel three-element groups of the object
//     (int at +0x14, int at +0x20, int at +0x30, int at +0x3c), and for every
//     group with a non-zero count it calls the handler taken from the table
//     at 0x011f3810 with (time, &value, &count), then writes the (possibly
//     modified) values back and clears the fourth group.

struct FNV_Inner { float v[4]; };

struct FNV_Obj {
    int       unk00;
    FNV_Inner inner;
    int       m14[3];
    int       m20[3];
    char      m2c[3];
    int       m30[3];
    int       m3c[3];
};

typedef bool (__cdecl *FNV_CbFn)(float, int*, int*);
extern FNV_CbFn g_fnv_cb_011f3810[];

// The game's vector constructor iterator: it calls the element constructor
// (a plain function pointer, the object pointer travels in ECX) once per
// element.  It pops its own four arguments.
extern "C" void __stdcall FNV_array_ctor_iterator(void* base, unsigned int size, unsigned int count, void* ctor);

// The element constructor of the allocated object.
extern "C" void __cdecl FNV_element_ctor(void* self);

// @fnv 0x00a29e40
bool UpdateArrayElements(float t, void** pOut, int* piFlag)
{
    if (*piFlag == 0) {
        FNV_Obj* p;
        void* block = ((P03MM*)&g_memoryManager)->Allocate(0x4c);
        if (block) {
            *(int*)block = 1;                      // element count cookie
            p = (FNV_Obj*)((char*)block + 4);       // the element itself
            FNV_array_ctor_iterator(p, 0x48, 1, (void*)&FNV_element_ctor);
        } else {
            p = 0;
        }
        *pOut = p;
        *piFlag = 1;
    }
    FNV_Obj* arr = (FNV_Obj*)*pOut;
    char flag = 0;
    for (unsigned int i = 0; i < 3; i++) {
        unsigned char c = (unsigned char)i;
        int f = arr->m30[c];
        int n = arr->m14[c];
        if (n) {
            FNV_CbFn fn = g_fnv_cb_011f3810[arr->m20[c]];
            bool r = fn(t, &f, &n);
            if (r) flag = 1;
            arr->m14[c] = n;
            arr->m30[c] = f;
            arr->m3c[c] = 0;
        }
    }
    return flag;
}



class A29F00Stream {
public:
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
    unsigned int m_uiFileVersion;
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
    NiBinaryStream* m_pUnderlyingStream;
};

template <class T>
inline void A29F00BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void A29F00LoadBinary(A29F00Stream& kStream, T& value)
{
    A29F00BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

typedef void* (__cdecl *A29F00LoadFunc)(A29F00Stream& kStream, unsigned int uiNumKeys);

extern unsigned char DAT_011f3758[];
extern A29F00LoadFunc DAT_011f3db0[];

class A29F00KeyData {
public:
    void LoadKeyData(A29F00Stream& kStream);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_auiNumKeys[3];
    unsigned int m_aeKeyType[3];
    unsigned char m_aucKeySize[4];
    void* m_ppKeyData[3];
};

// @fnv 0x00a29f00
void A29F00KeyData::LoadKeyData(A29F00Stream& kStream)
{
    if (kStream.m_uiFileVersion < 0x0A010068) {
        int iUnused;
        A29F00LoadBinary(kStream, iUnused);
    }

    for (unsigned int i = 0; i < 3; i++) {
        A29F00LoadBinary(kStream, m_auiNumKeys[i]);
        if (m_auiNumKeys[i] > 0) {
            unsigned int eType;
            A29F00LoadBinary(kStream, eType);
            m_aeKeyType[i] = eType;
            m_aucKeySize[i] = DAT_011f3758[eType];
            m_ppKeyData[i] = DAT_011f3db0[eType](kStream, m_auiNumKeys[i]);
        }
    }
}



struct A29FE0Context {
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
    NiBinaryStream* m_pDataStream;
};

struct A29FE0Block {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_auiCount[3];
    unsigned int m_auiType[3];
    int unk2C;
    void* m_apvData[3];
};

typedef void (*A29FE0LoadFunc)(A29FE0Context* pkContext, void* pvData, unsigned int ItemUpdateArray);
extern A29FE0LoadFunc g_apfnA29FE0Load[];

// Reads three count/type pairs from the stream and, for each nonzero count, reads its type and calls the matching loader with the data pointer.
// @fnv 0x00a29fe0
void ReadBlockEntries(A29FE0Context* pkContext, A29FE0Block* pkBlock) {
    unsigned int* puiCount = pkBlock->m_auiCount;
    for (int i = 0; i < 3; i++, puiCount++) {
        pkContext->m_pDataStream->Write(puiCount, 4);
        if (*puiCount > 0) {
            pkContext->m_pDataStream->Write(puiCount + 3, 4);
            g_apfnA29FE0Load[puiCount[3]](pkContext, ((void**)puiCount)[7], *puiCount);
        }
    }
}

struct Quaternion {
    float x;
    float y;
    float z;
    float w;
    Quaternion& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }
    Quaternion operator+(const Quaternion& other) const {
        Quaternion result = *this;
        result.x += other.x;
        result.y += other.y;
        result.z += other.z;
        result.w += other.w;
        return result;
    }
};
struct QuaternionKey {
    float time;
    Quaternion value;
};
// Linearly interpolates between two quaternion keys by the given factor and writes the blended quaternion to output.
// @fnv 0x00a2a200
void __cdecl InterpolateQuaternion(float interpolation, const QuaternionKey* first, const QuaternionKey* second, Quaternion* output)
{
    float inverse = 1.0f - interpolation;
    Quaternion left = first->value;
    Quaternion right = second->value;
    left *= inverse;
    right *= interpolation;
    *output = right + left;
}


float __cdecl NiInterpScalar_Linear(float a, float b, float c);

// @fnv 0x00a2a560
// src: GAMEBRYO_LIB 0x00a2a560
void __cdecl NiLinFloatKey_Interpolate(float s, const NiPoint3* apPointA, const NiPoint3* apPointB, float* pfResult) {
    float by = apPointB->y;
    float ay = apPointA->y;
    *pfResult = NiInterpScalar_Linear(s, ay, by);
}

namespace fnv_00a2a5a0 {
struct Pool { void* Alloc(unsigned n); };
extern Pool DAT_011f6238;
struct Elem {
    int a; int b;
    void Init(int x);
    ~Elem();
    static void* operator new[](unsigned n) { return DAT_011f6238.Alloc(n); }
    static void operator delete[](void*) {}
};
// Allocates an array of n Elem objects and calls Init(x) on each element, returning the array.
// @fnv 0x00a2a5a0
Elem* CreateInitializedElems(int x, unsigned auiCount)
{
    Elem* r = new Elem[auiCount];
    for (unsigned i = 0; i < auiCount; i++) r[i].Init(x);
    return r;
}
}  // namespace fnv_00a2a5a0

struct CopyTail12 {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};

struct CopyBlk16 {
    float m_00;
    CopyTail12 m_04;
};

// @fnv 0x00a2a7b0
// src: GUESS 0x00a2a7b0 (confidence: low)
void __cdecl Runtime_UpdateState_00a2a7b0(CopyBlk16* dst, const CopyBlk16* src)
{
    dst->m_00 = src->m_00;
    dst->m_04 = src->m_04;
}

class A2A890Point3 {
public:
    float x, y, z;

    A2A890Point3() {}
    A2A890Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}

    A2A890Point3 operator-(const A2A890Point3& pt) const { return A2A890Point3(x - pt.x, y - pt.y, z - pt.z); }
};

struct A2A890Key {
    float m_fTime;
    A2A890Point3 m_kValue;
};

// Stores into kResult the difference of kKey1.m_kValue and kKey0.m_kValue; fTime is unused.
// @fnv 0x00a2a890
// src: GAMEBRYO_LIB 0x00a2a890
void NiLinPosKey_InterpolateD1(float fTime, const A2A890Key& kKey0, const A2A890Key& kKey1, A2A890Point3& kResult) {
    kResult = kKey1.m_kValue - kKey0.m_kValue;
}

struct VertexRecord {
    int x, y, z, w;
    ~VertexRecord() {}
    void LoadBinaryFields_00a27430(int);
    static void* operator new[](unsigned int size) { return ((P03MM*)&g_memoryManager)->Allocate(size); }
};
// @fnv 0x00a2a8e0
VertexRecord* __cdecl CreateVertexRecords(int v, unsigned int count)
{
    VertexRecord* items = new VertexRecord[count];
    for (unsigned int i = 0; i < count; ++i)
        items[i].LoadBinaryFields_00a27430(v);
    return items;
}

// MemoryManager, P03MM and NiPoint3 are declared above.
extern MemoryManager g_memoryManager;
void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS;
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
NiPoint3 GetKeyPosAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);

// Linear position key: time + position (16 bytes).
struct AnimKeyBase {
    float time;
    ~AnimKeyBase() throw() {}
};
struct LinPosKey : AnimKeyBase {
    PointStorage pos;
    static void* operator new[](unsigned int n) { return ((P03MM*)&g_memoryManager)->Allocate(n); }
    static void operator delete[](void* p) { g_memoryManager.Deallocate(p); }
};

// Inserts a new linear position key at time t (value sampled from the existing curve).
// Inserts a new LinPosKey at time t into the sorted key array, shifting existing keys and evaluating the position via GetKeyPosAtTime.
// @fnv 0x00a2a940
bool InsertLinPosKey(float t, LinPosKey** pKeys, unsigned int* pCount)
{
    LinPosKey* keys = *pKeys;
    unsigned int idx;
    if (FindKeyIndex(t, (TCBKeyS*)keys, *pCount, &idx, sizeof(LinPosKey))) {
        LinPosKey* newKeys = new LinPosKey[*pCount + 1];
        _memmove(newKeys, keys, idx * sizeof(LinPosKey));
        if (*pCount > idx)
            _memmove(&newKeys[idx + 1], &keys[idx], (*pCount - idx) * sizeof(LinPosKey));
        NiPoint3 v = GetKeyPosAtTime(t, (TCBKeyS*)keys, 1, *pCount, sizeof(LinPosKey));
        LinPosKey* k = &newKeys[idx];
        k->time = t;
        memcpy(&k->pos, &v, sizeof(k->pos));
        ++*pCount;
        // free the old array including its element-count cookie
        if (keys)
            g_memoryManager.Deallocate((unsigned int*)keys - 1);
        *pKeys = newKeys;
        return true;
    }
    return false;
}

struct FUN_00a6e330_StandIn {
    void __thiscall FUN_00a6e330(float value, const void* first, const void* second);
};

// Calls FUN_00a6e330 on result with value and the two pointers advanced by 4 bytes.
// @fnv 0x00a2ab90
// src: GUESS 0x00a2ab90 (confidence: low)
void __cdecl Runtime_ForwardCall_00a2ab90(
    float value,
    const void* first,
    const void* second,
    FUN_00a6e330_StandIn* result
) {
    result->FUN_00a6e330(
        value,
        static_cast<const void*>(static_cast<const char*>(first) + 4),
        static_cast<const void*>(static_cast<const char*>(second) + 4)
    );
}

// Structural equality of two light-like objects: base equality, three scalar terms, four vectors.

struct A2AE90Point3 {
    float x;
    float y;
    float z;
    bool IsEqual(const A2AE90Point3& kOther) const;
};

struct A2AE90Light {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fDimmer;
    float m_fFirstLightParameter;
    float m_fSecondLightParameter;
    A2AE90Point3 m_kAmbient;
    A2AE90Point3 m_kDiffuse;
    A2AE90Point3 m_kSpecular;
    A2AE90Point3 m_kLightVector;
};

bool __cdecl A2AE90BaseIsEqual(A2AE90Light* pkA, A2AE90Light* pkB);

// Compares two lights: first the base fields, then dimmer, two floats and the ambient, diffuse, specular and remaining point values.
// @fnv 0x00a2ae90
bool __cdecl IsLightEqual(A2AE90Light* pkA, A2AE90Light* pkB)
{
    if (!A2AE90BaseIsEqual(pkA, pkB))
        return false;

    return pkA->m_fDimmer == pkB->m_fDimmer &&
        pkA->m_fFirstLightParameter == pkB->m_fFirstLightParameter &&
        pkA->m_fSecondLightParameter == pkB->m_fSecondLightParameter &&
        pkA->m_kAmbient.IsEqual(pkB->m_kAmbient) &&
        pkA->m_kDiffuse.IsEqual(pkB->m_kDiffuse) &&
        pkA->m_kSpecular.IsEqual(pkB->m_kSpecular) &&
        pkA->m_kLightVector.IsEqual(pkB->m_kLightVector);
}

// FNV candidate v2: AllocateBezierKeys (0x00a2af30, 61 bytes)
// return new BezierKeyS[count]; with sizeof(element)=76 (0x4c), non-trivial dtor -> 4-byte cookie,
// class-specific operator new[] inlining to ((P03MM*)&g_memoryManager)->Allocate(n).
// MemoryManager, PointStorage, P03MM, g_memoryManager and TCBKeyS are declared above;
// element type must be 76 bytes, so it is a distinct type, not the packet's TCBKeyS.
struct BezierKeyS {
    float time;
    PointStorage pos;
    PointStorage in;
    PointStorage out;
    float extra[9];
    ~BezierKeyS() {}
    static void* operator new[](unsigned int n) { return ((P03MM*)&g_memoryManager)->Allocate(n); }
    static void operator delete[](void* p, unsigned int) { g_memoryManager.Deallocate(p); }
};

// Allocates an array of count BezierKeyS objects using the memory manager and returns the pointer.
// @fnv 0x00a2af30
BezierKeyS* __cdecl AllocateBezierKeys(unsigned int count) {
    return new BezierKeyS[count];
}

struct S_00a2af70_V { float x, y, z; };
struct S_00a2af70_P {
    int unk00;
    S_00a2af70_V c1;
    int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
    S_00a2af70_V c2;
    S_00a2af70_V c3;
    S_00a2af70_V c4;
};

static __forceinline S_00a2af70_V Scale(const S_00a2af70_V& v, float t) {
    S_00a2af70_V r; r.x = v.x * t; r.y = v.y * t; r.z = v.z * t; return r;
}
static __forceinline S_00a2af70_V Add(const S_00a2af70_V& a, const S_00a2af70_V& b) {
    S_00a2af70_V r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r;
}

// @fnv 0x00a2af70
// src: GAMEBRYO_LIB 0x00a2af70
void __cdecl NiTCBPosKey_Interpolate(float t, S_00a2af70_P* p, int unused, S_00a2af70_V* out)
{
    *out = Add(p->c1, Scale(Add(p->c2, Scale(Add(p->c3, Scale(p->c4, t)), t)), t));
}

struct S_00a2b050_V3 {
    float x, y, z;
    S_00a2b050_V3() {}
    S_00a2b050_V3(float a, float b, float c) { x = a; y = b; z = c; }
    S_00a2b050_V3 operator+(const S_00a2b050_V3& o) const { return S_00a2b050_V3(x + o.x, y + o.y, z + o.z); }
    S_00a2b050_V3 operator*(float s) const { return S_00a2b050_V3(x * s, y * s, z * s); }
};
struct S_00a2b050_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S_00a2b050_V3 pos;
    S_00a2b050_V3 velA;
    S_00a2b050_V3 velB;
};
// Computes o->pos plus (velA*2 + velB*3*t)*t and stores the result in out, returning out.
// @fnv 0x00a2b050
S_00a2b050_V3* __cdecl ComputeInterpolatedPosition(float t, S_00a2b050_Obj* pObj, int unused, S_00a2b050_V3* out)
{
    S_00a2b050_V3 r = pObj->pos + (pObj->velA * 2.0f + pObj->velB * (3.0f * t)) * t;
    *out = r;
    return out;
}

extern "C" double DAT_01034208;
extern "C" double DAT_01011590;


    inline LocalVector3 LocalVector3::operator*(double multiplier) const {
        LocalVector3 scaled;
        scaled.x = float(x * multiplier);
        scaled.y = float(y * multiplier);
        scaled.z = float(z * multiplier);
        return scaled;
    }
    inline LocalVector3 LocalVector3::operator*(float multiplier) const {
        LocalVector3 scaled;
        scaled.x = x * multiplier;
        scaled.y = y * multiplier;
        scaled.z = z * multiplier;
        return scaled;
    }
    inline LocalVector3 LocalVector3::operator+(const LocalVector3& right) const {
        LocalVector3 sum;
        sum.x = x + right.x;
        sum.y = y + right.y;
        sum.z = z + right.z;
        return sum;
    }

// Scales amount by DAT_01034208, then writes the sum of two Vector3s read from transform offsets 13 and 16, weighted by DAT_01011590 and amount, into result.
// @fnv 0x00a2b130
// src: GAMEBRYO_LIB 0x00a2b130
void __cdecl NiTCBPosKey_InterpolateD2(float amount, const float* transform, unsigned int unused, LocalVector3* result)
{
    amount *= DAT_01034208;
    const LocalVector3* start = reinterpret_cast<const LocalVector3*>(transform + 13);
    const LocalVector3* end = reinterpret_cast<const LocalVector3*>(transform + 16);
    *result = (*start * DAT_01011590) + (*end * amount);
}



struct NiStreamImpl {
    char pad[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};

template <class T> inline void ReadBinaryValue(NiStreamImpl& stream, T& value)
{
    stream.m_pUnderlyingStream->Read(value);
}

struct FUN_00a2b980_cls {
    char unk00[0x10];
    unsigned int m_uiA;
    unsigned int m_uiB;
    unsigned int m_uiC;

    void LoadBinaryFields_00a27430(NiStreamImpl& stream);
    void ReadKeyFields(NiStreamImpl& stream);
};

// Calls FUN_00a27430, then reads m_uiA, m_uiB and m_uiC from the stream.
// @fnv 0x00a2b980
// src: GUESS 0x00a2b980 (confidence: medium)
void FUN_00a2b980_cls::ReadKeyFields(NiStreamImpl& stream)
{
    LoadBinaryFields_00a27430(stream);
    ReadBinaryValue(stream, m_uiA);
    ReadBinaryValue(stream, m_uiB);
    ReadBinaryValue(stream, m_uiC);
}



template <class T>
inline void BA2BA10BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void BA2BA10SaveBinary(NiStreamStandInW_blk_00a20000_o2& kStream, const T& value)
{
    BA2BA10BinaryStreamSave(*(NiBinaryStream*)kStream.m_pBackingStream, &value);
}

struct BA2BA10Key {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

void __cdecl ApplyAnimToTarget(NiStreamStandInW_blk_00a20000_o2& kStream, BA2BA10Key* pkKey);

// @fnv 0x00a2ba10
void __cdecl SaveKey(NiStreamStandInW_blk_00a20000_o2& kStream, BA2BA10Key* pkKey)
{
    ApplyAnimToTarget(kStream, pkKey);
    BA2BA10SaveBinary(kStream, pkKey->m_fVectorY);
    BA2BA10SaveBinary(kStream, pkKey->m_fVectorZ);
    BA2BA10SaveBinary(kStream, pkKey->m_fScalarPart);
}

namespace fnv_00a2bb00 {
struct SpawnHeap {
    int unk00;
    void* Game_DoHeapAlloc(unsigned int auiSize);
};

extern "C" SpawnHeap DAT_011f6238;

struct Element76 {
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
    ~Element76() {}
    void Init(int a1);
    static void* operator new[](unsigned int auiSize) { return DAT_011f6238.Game_DoHeapAlloc(auiSize); }
};

// Allocates an array of Element76 objects and calls Init(a1) on each element.
// @fnv 0x00a2bb00
void* __cdecl AllocateElement76Array(int a1, unsigned int auiCount)
{
    Element76* items = new Element76[auiCount];
    Element76* p;
    if (auiCount > 0) {
        p = items;
        do {
            p->Init(a1);
            p = (Element76*)((char*)p + 0x4c);
        } while (--auiCount != 0);
    }
    return items;
}
}  // namespace fnv_00a2bb00

struct A2BBF0Quad {
    int m_iA;
    int m_iB;
    int m_iC;
    int m_iD;
};

struct A2BBF0Record {
    float m_fTime;
    A2BBF0Quad m_kControlPoint;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    A2BBF0Quad m_kStartPoint;
    A2BBF0Quad m_kEnd;
};

// @fnv 0x00a2bbf0
// src: GAMEBRYO_LIB 0x00a2bbf0
void NiTCBRotKey_Copy(A2BBF0Record* pkDst, const A2BBF0Record* pkSrc) {
    pkDst->m_fTime = pkSrc->m_fTime;
    pkDst->m_kControlPoint = pkSrc->m_kControlPoint;
    pkDst->m_fCoefficientA = pkSrc->m_fCoefficientA;
    pkDst->m_fB = pkSrc->m_fB;
    pkDst->m_fC = pkSrc->m_fC;
    pkDst->m_kStartPoint = pkSrc->m_kStartPoint;
    pkDst->m_kEnd = pkSrc->m_kEnd;
}

namespace fnv_00a2bc60 {
struct SpawnTarget
{
    void Callee(float a, void* p1, void* p2, void* p3, void* p4);
};

// Calls SpawnTarget::Callee with a and offsets into x and y.
// @fnv 0x00a2bc60
void __cdecl InvokeSpawnTarget(float afValue, char* pFirst, char* pSecond, SpawnTarget* pTarget)
{
    pTarget->Callee(afValue, pFirst + 4, pFirst + 0x20, pSecond + 0x30, pSecond + 4);
}
}  // namespace fnv_00a2bc60



struct A2BDE0Key {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

bool A2BDE0KeyEqual(const A2BDE0Key& kA, const A2BDE0Key& kB);

struct A2BDE0BezRotKey : A2BDE0Key {
    float m_fValueX;
    float m_fValueY;
    float m_fValueZ;
    NiBound m_kInQuat;
    NiBound m_kOutQuat;
};

// Compares two rotation keys: base key equality, three floats, and the in/out quaternions.
// @fnv 0x00a2bde0
bool BezRotKeyEqual(const A2BDE0BezRotKey& kA, const A2BDE0BezRotKey& kB)
{
    if (!A2BDE0KeyEqual(kA, kB))
        return false;
    return kA.m_fValueX == kB.m_fValueX && kA.m_fValueY == kB.m_fValueY && kA.m_fValueZ == kB.m_fValueZ
        && const_cast<NiBound&>(kA.m_kInQuat).Object_HasEqualFloatComponents(kB.m_kInQuat) && const_cast<NiBound&>(kA.m_kOutQuat).Object_HasEqualFloatComponents(kB.m_kOutQuat);
}

struct TQuat {
    float w, x, y, z;
    TQuat() {}
    TQuat Mul(const TQuat& q) const;
    TQuat operator+(const TQuat& q) const;
    TQuat operator-(const TQuat& q) const;
    static TQuat Log(const TQuat& q);
    static TQuat Exp(const TQuat& q);
};
TQuat Conj(const TQuat& q);
TQuat operator*(float s, const TQuat& q);

struct TCBRotKey {
    float m_fTime;
    TQuat m_kRotationValue;
    float m_fValueX;
    float m_fValueY;
    float m_fValueZ;
    TQuat m_kOutgoingTangent;
    TQuat m_kIncomingTangent;
    void ComputeTangents(const TCBRotKey& prev, const TCBRotKey& next);
};

// @fnv 0x00a2beb0
void TCBRotKey::ComputeTangents(const TCBRotKey& prev, const TCBRotKey& next)
{
    TQuat qLogPrev = TQuat::Log(Conj(prev.m_kRotationValue).Mul(m_kRotationValue));
    TQuat qLogNext = TQuat::Log(Conj(m_kRotationValue).Mul(next.m_kRotationValue));

    float invDelta = 1.0f / (next.m_fTime - prev.m_fTime);
    float fTension, fContPlus, fContMinus, fBiasPlus, fBiasMinus;
    fTension = 1.0f - m_fValueX;
    fContMinus = 1.0f - m_fValueY;
    fContPlus = 1.0f + m_fValueY;
    fBiasMinus = 1.0f - m_fValueZ;
    fBiasPlus = 1.0f + m_fValueZ;

    float f = (m_fTime - prev.m_fTime) * invDelta;
    TQuat qOutTangent = (f * fTension * fContMinus * fBiasMinus) * qLogNext + (f * fTension * fContPlus * fBiasPlus) * qLogPrev;
    m_kOutgoingTangent = m_kRotationValue.Mul(TQuat::Exp(0.5f * (qOutTangent - qLogNext)));

    f = (next.m_fTime - m_fTime) * invDelta;
    TQuat qInTangent = (f * fTension * fContPlus * fBiasMinus) * qLogNext + (f * fTension * fContMinus * fBiasPlus) * qLogPrev;
    m_kIncomingTangent = m_kRotationValue.Mul(TQuat::Exp(0.5f * (qLogPrev - qInTangent)));
}

struct Quad64
{
    int unk00;
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
    void ComputeTangents(void* a, void* b);
};

void __cdecl NiRotKey_FillDerivedVals(void* a, unsigned int count, void* c);

// @fnv 0x00a2c130
// src: GAMEBRYO_LIB 0x00a2c130
void __cdecl NiTCBRotKey_FillDerivedVals(Quad64* apQuads, unsigned int count, void* c)
{
    if (count < 2)
        return;
    NiRotKey_FillDerivedVals(apQuads, count, c);
    apQuads[0].ComputeTangents(apQuads, &apQuads[1]);
    unsigned int n = count - 1;
    if (n > 1)
    {
        Quad64* cur = apQuads;
        unsigned int k = n - 1;
        do
        {
            Quad64* next = cur + 1;
            next->ComputeTangents(cur, cur + 2);
            cur = next;
            k--;
        } while (k != 0);
    }
    apQuads[n].ComputeTangents(&apQuads[count - 2], &apQuads[n]);
}


struct S_a2c300_Stream {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    NiBinaryStream* unk24c;
};
__forceinline void S_a2c300_SaveI(NiBinaryStream* i, void* src, unsigned bytes) {
    unsigned sz = bytes;
    i->m_uiAbsoluteCurrentPos += i->m_pfnRead(i, src, bytes, &sz, 1);
}
__forceinline void S_a2c300_Save(S_a2c300_Stream* s, void* src, unsigned bytes) {
    S_a2c300_SaveI(s->unk24c, src, bytes);
}
struct S_a2c300_Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void ProcessState_00a29640(S_a2c300_Stream* s);
    void SaveExtraFields(S_a2c300_Stream* s);
};
// Calls FUN_00a29640, then serializes the 4-byte fields unk14, unk18 and unk1c to the stream via S_a2c300_Save.
// @fnv 0x00a2c300
void S_a2c300_Obj::SaveExtraFields(S_a2c300_Stream* pStream) {
    ProcessState_00a29640(pStream);
    S_a2c300_Save(pStream, &unk14, 4);
    S_a2c300_Save(pStream, &unk18, 4);
    S_a2c300_Save(pStream, &unk1c, 4);
}


struct S_a2c390_Stream {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    NiBinaryStream* unk250;
};
void __cdecl Object_ProcessState_00a28720(S_a2c390_Stream* s, void* obj);
inline void S_a2c390_BinLoad(NiBinaryStream* i, void* dst, unsigned bytes) {
    unsigned comp = bytes;
    i->m_uiAbsoluteCurrentPos += i->m_pfnWrite(i, dst, bytes, &comp, 1);
}
template<class T> inline void S_a2c390_Load(S_a2c390_Stream* s, T& v) {
    S_a2c390_BinLoad(s->unk250, &v, sizeof(T));
}
struct S_a2c390_Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
// Calls FUN_00a28720 on s and o, then loads o->unk14, o->unk18 and o->unk1c from the stream.
// @fnv 0x00a2c390
void __cdecl LoadObjFields(S_a2c390_Stream* pStream, S_a2c390_Obj* pObj) {
    Object_ProcessState_00a28720(pStream, pObj);
    S_a2c390_Load(pStream, pObj->unk14);
    S_a2c390_Load(pStream, pObj->unk18);
    S_a2c390_Load(pStream, pObj->unk1c);
}

extern "C" void __cdecl LoadObjFields(void* ctx, void* entry);

struct Entry64 {
    unsigned int unk00;
    unsigned int unk01;
    unsigned int unk02;
    unsigned int unk03;
    unsigned int unk04;
    unsigned int unk05;
    unsigned int unk06;
    unsigned int unk07;
    unsigned int unk08;
    unsigned int unk09;
    unsigned int unk10;
    unsigned int unk11;
    unsigned int unk12;
    unsigned int unk13;
    unsigned int unk14;
    unsigned int unk15;
};

// Walk an array of 0x40-byte entries, passing each one to the helper.
// Calls LoadObjFields with ctx and each entry in the array, advancing through count entries.
// @fnv 0x00a2c490
// src: GAMEBRYO_LIB 0x00a2c490
void __cdecl NiTCBRotKey_SaveToStream(void* pContext, Entry64* entries, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        LoadObjFields(pContext, entries);
        entries++;
    }
}

struct ShapeValues {
    float initial;
    float start;
    float intermediateA;
    float intermediateB;
    float intermediateC;
    float end;
    float extent;
};
extern "C" float __cdecl func_0x00a42070(float input, float leftStart, float leftExtent, float rightStart, float rightEnd);

// @fnv 0x00a2c610
// src: GAMEBRYO_LIB 0x00a2c610
void __cdecl NiTCBFloatKey_Interpolate(float input, const ShapeValues* left, const ShapeValues* right, float* apfResult) {
    const float rightStart = right->start;
    const float leftStart = left->start;
    *apfResult = func_0x00a42070(input, leftStart, left->extent, rightStart, right->end);
}

namespace fnv_00a2c660 {
struct DynamicMemoryAllocator {
    void* Allocate(unsigned int auiSize);
    void Free(void* apPtr);
};

extern "C" DynamicMemoryAllocator DAT_011f6238;

struct Elem28 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    static void* operator new[](unsigned int aSize) { return DAT_011f6238.Allocate(aSize); }
    static void operator delete[](void* apBlock) { DAT_011f6238.Free(apBlock); }
    ~Elem28() {}
};

// Allocates an array of count Elem28 objects using the custom allocator and returns the block pointer.
// @fnv 0x00a2c660
void* AllocateElem28Array(unsigned int count)
{
    return new Elem28[count];
}
}  // namespace fnv_00a2c660

struct Key {
    float t;
    float v;
    float a;
    float b;
    float c;
    float d;
    float e;
};

// src: GAMEBRYO_LIB 0x00a2c6a0
__declspec(noinline) void __cdecl NiTCBFloatKey_CalculateDVals(Key* k, float a, float b, float c, float d) {
    k->a = a * c;
    k->b = b * d;
}

// @fnv 0x00a2c7a0
// src: GAMEBRYO_LIB 0x00a2c7a0
void __cdecl NiTCBFloatKey_FillDerivedVals(Key* keys, unsigned int count) {
    if (count < 2) {
        return;
    }
    NiTCBFloatKey_CalculateDVals(keys, 2.0f * keys[0].v - keys[1].v, keys[1].v, 1.0f, 1.0f);
    unsigned int n = count - 1;
    if (n > 1) {
        Key* p = keys;
        unsigned int c = n - 1;
        do {
            Key* q = p + 1;
            NiTCBFloatKey_CalculateDVals(q, p->v, p[2].v, q->t - p->t, p[2].t - q->t);
            p = q;
        } while (--c != 0);
    }
    unsigned int i = count - 2;
    Key* last = keys + n;
    NiTCBFloatKey_CalculateDVals(last, keys[i].v, 2.0f * last->v - keys[i].v, 1.0f, 1.0f);
}


struct S_00a2c9d0_Owner {
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    NiBinaryStream* m_stream;
};
struct FUN_00a2c9d0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void LoadBaseAndMemberValue(S_00a2c9d0_Owner* owner);
    void LoadBaseAndThreeValues(S_00a2c9d0_Owner* owner);
};

// Calls FUN_00a26eb0, then reads three 4-byte values from owner->m_stream into unk08, unk0c and unk10.
// @fnv 0x00a2c9d0
// src: GUESS 0x00a2c9d0 (confidence: medium)
void FUN_00a2c9d0_cls::LoadBaseAndThreeValues(S_00a2c9d0_Owner* owner)
{
    LoadBaseAndMemberValue(owner);
    owner->m_stream->Read(&unk08, 4);
    owner->m_stream->Read(&unk0c, 4);
    owner->m_stream->Read(&unk10, 4);
}



struct FUN_00a2ca60_Obj {
    char _00[8];
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
};

void __cdecl WriteFloatToStream(NiStreamStandInW_blk_00a20000_o2* pkStream, FUN_00a2ca60_Obj* pkObj);

// Calls WriteFloatToStream, then writes the object's m_08, m_0c and m_10 fields to the stream.
// @fnv 0x00a2ca60
// src: GUESS 0x00a2ca60 (confidence: medium)
void __cdecl Object_WriteKeyFields(NiStreamStandInW_blk_00a20000_o2* pkStream, FUN_00a2ca60_Obj* pkObj)
{
    WriteFloatToStream(pkStream, pkObj);
    pkStream->m_pBackingStream->Write(&pkObj->m_08);
    pkStream->m_pBackingStream->Write(&pkObj->m_0c);
    pkStream->m_pBackingStream->Write(&pkObj->m_10);
}

struct KeyframeElement {
    float time;
    float value;
    float inTangent;
    float outTangent;
    float tension;
    float continuity;
    float bias;
    ~KeyframeElement();
    void LoadBaseAndThreeValues(void* context);
    static void* operator new[](unsigned int bytes) {
        return ((P03MM*)&g_memoryManager)->Allocate(bytes);
    }
};
// @fnv 0x00a2caf0
KeyframeElement* __cdecl AllocateKeyframeElements(void* context, unsigned int count) {
    KeyframeElement* elements = new KeyframeElement[count];
    if (count > 0) {
        KeyframeElement* cursor = elements;
        do {
            cursor->LoadBaseAndThreeValues(context);
            ++cursor;
            --count;
        } while (count != 0);
    }
    return elements;
}

extern "C" void __cdecl Object_WriteKeyFields(void* a1, void* a2);

// Calls FUN_00a2ca60 for each of count elements, advancing a2 by 0x1c bytes per iteration.
// @fnv 0x00a2cb50
// src: GAMEBRYO_LIB 0x00a2cb50
void __cdecl NiTCBFloatKey_SaveToStream(void* a1, void* a2, unsigned int count)
{
    unsigned int n = count;
    if (n <= 0)
        return;
    do {
        Object_WriteKeyFields(a1, a2);
        a2 = (char*)a2 + 0x1c;
        n = n - 1;
    } while (n != 0);
}

struct FUN_00a2cc40_S
{
    unsigned int unk00;
    unsigned char m_04;
};

// @fnv 0x00a2cc40
void SelectByteByThreshold(float afThreshold, FUN_00a2cc40_S* apFirst, FUN_00a2cc40_S* apSecond, unsigned char* apResult)
{
    unsigned char* src = &apSecond->m_04;
    if (afThreshold < 1.0f)
    {
        src = &apFirst->m_04;
    }
    *apResult = *src;
}

struct A2CC60Stream;

struct A2CC60Entry {
    int unk00;
    int unk04;
};

void WriteEnabledFlag(A2CC60Stream* pkStream, A2CC60Entry* pkEntry);

// Calls WriteEnabledFlag for each of the given number of entries, passing the stream and a pointer to each entry.
// @fnv 0x00a2cc60
// src: GUESS 0x00a2cc60 (confidence: medium)
void Object_WriteEnabledFlags(A2CC60Stream* pkStream, A2CC60Entry* pkEntries, unsigned int ItemUpdateArray) {
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        WriteEnabledFlag(pkStream, &pkEntries[i]);
}

struct Arr8 {
    float f;
    char c;
    ~Arr8() {}
    __forceinline static void* operator new[](unsigned int n) {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    __forceinline static void operator delete[](void* p, unsigned int) {
        g_memoryManager.Deallocate(p);
    }
};

// Allocates an array of count Arr8 objects using the memory manager and returns the pointer.
// @fnv 0x00a2cc90
void* __cdecl AllocateArr8Array(unsigned int count) {
    return new Arr8[count];
}

struct FUN_00a2cf20_Payload
{
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};

struct FUN_00a2cf20_Value
{
    unsigned int m_hdr;
    FUN_00a2cf20_Payload m_payload;
};

// Copies the payload of a into out when f is below 1.0, otherwise copies the payload of b.
// @fnv 0x00a2cf20
void SelectPayloadByThreshold(float afThreshold, FUN_00a2cf20_Value* apValueA, FUN_00a2cf20_Value* apValueB, FUN_00a2cf20_Payload* apResult)
{
    if (afThreshold < 1.0f)
    {
        *apResult = apValueA->m_payload;
    }
    else
    {
        *apResult = apValueB->m_payload;
    }
}

struct FUN_00a2d200_arg
{
    unsigned int unk00;
    float m_04;
};

// Writes a->m_04 to *out when t is below 1.0, otherwise writes b->m_04.
// @fnv 0x00a2d200
// src: GAMEBRYO_LIB 0x00a2d200
void NiStepFloatKey_Interpolate(float t, FUN_00a2d200_arg* a, FUN_00a2d200_arg* b, float* apResult)
{
    if (t < 1.0f)
    {
        *apResult = a->m_04;
    }
    else
    {
        *apResult = b->m_04;
    }
}

namespace fnv_00a2d260 {
struct DynamicMemoryAllocator {
    void* Game_DoHeapAlloc(unsigned int auiSize);
    void MemoryManager_Deallocate(void* apPtr);
};

extern "C" unsigned int DAT_011f6238;

struct TCBKeyS;

struct KeyPair8 {
    float time;
    float value;

    ~KeyPair8() {}
    static void* operator new[](unsigned int aSize) { return reinterpret_cast<DynamicMemoryAllocator*>(&DAT_011f6238)->Game_DoHeapAlloc(aSize); }
};

bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
float GetValueAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);
void* _memmove(void* d, const void* s, unsigned int n);

// @fnv 0x00a2d260
bool InsertKeyPair(float afTime, KeyPair8** pKeys, unsigned int* pCount)
{
    unsigned int idx;
    KeyPair8* data = *pKeys;
    if (FindKeyIndex(afTime, (TCBKeyS*)data, *pCount, &idx, 8))
    {
        unsigned int newCount = *pCount + 1;
        KeyPair8* newData = new KeyPair8[newCount];
        
        _memmove(newData, data, idx * 8);
        if (*pCount > idx)
        {
            _memmove(newData + idx + 1, data + idx, (*pCount - idx) * 8);
        }

        float v = GetValueAtTime(afTime, (TCBKeyS*)data, 5, *pCount, 8);
        KeyPair8* item = &newData[idx];
        item->time = afTime;
        item->value = v;

        (*pCount)++;
        if (data)
        {
            reinterpret_cast<DynamicMemoryAllocator*>(&DAT_011f6238)->MemoryManager_Deallocate((char*)data - 4);
        }
        *pKeys = newData;
        return true;
    }
    return false;
}
}  // namespace fnv_00a2d260

struct KeyVec {
    int m_iX;
    int m_iY;
    int m_iZ;
};

struct KeyData {
    int m_iT;
    KeyVec m_v;
};

struct KeyOut {
    int m_iX;
    int m_iY;
    int m_iZ;
};

// @fnv 0x00a2d3f0
void __cdecl SelectKeyVec(float afBlendWeight, const KeyData* pA, const KeyData* pB, KeyOut* pOut)
{
    if (afBlendWeight < 1.0f) {
        pOut->m_iX = pA->m_v.m_iX;
        pOut->m_iY = pA->m_v.m_iY;
        pOut->m_iZ = pA->m_v.m_iZ;
    } else {
        pOut->m_iX = pB->m_v.m_iX;
        pOut->m_iY = pB->m_v.m_iY;
        pOut->m_iZ = pB->m_v.m_iZ;
    }
}

namespace fnv_00a2d690 {
void __cdecl Object_ProcessState_00a28720(void*, void*);

// Calls FUN_00a28720 for each of count elements, advancing b by 0x14 bytes per iteration; returns early when count is 0.
// @fnv 0x00a2d690
// src: GUESS 0x00a2d690 (confidence: low)
void __cdecl Runtime_ProcessEntries_00a2d690(void* a, void* b, unsigned int count)
{
    if (count <= 0)
        return;

    for (unsigned int i = count; i != 0; --i)
    {
        Object_ProcessState_00a28720(a, b);
        b = static_cast<char*>(b) + 0x14;
    }
}
}  // namespace fnv_00a2d690

extern char* DAT_0109b220;
struct FNVRefObject {
    virtual void UnusedVirtual();
    virtual void DeleteThis();
    volatile long referenceCount;
};
struct FNVHolder {
    void* vtable;
    int unk04;
    int unk08;
    FNVRefObject* object;
    char* text;
    void ReleaseReference_00a2dd10();
};
// @fnv 0x00a2dd10
// src: GUESS 0x00a2dd10 (confidence: medium)
void FNVHolder::ReleaseReference_00a2dd10() {
    FnInterlockedDecrement decrement = DAT_00fdf1c4;
    FNVRefObject* held = object;
    if (held) {
        if (decrement((void*)&held->referenceCount) == 0)
            held->DeleteThis();
        object = 0;
    }
    if (text != DAT_0109b220)
        decrement(text - 8);
    held = object;
    if (held && decrement((void*)&held->referenceCount) == 0)
        held->DeleteThis();
}

struct FUN_00a351d0_cls {
    void __thiscall CrossFadeTo(int a, float b, int c, float d, float e);
};

// Forwards the five arguments to self->CrossFadeTo.
// @fnv 0x00a2e1b0
void __stdcall CallFUN_00a351d0(FUN_00a351d0_cls* self, int aiArg1, float afArg2, int aiArg3, float afArg4, float afArg5)
{
    self->CrossFadeTo(aiArg1, afArg2, aiArg3, afArg4, afArg5);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern unsigned int DAT_011f36a8;
struct ObjA00a2;
extern ObjA00a2* DAT_011f36a4;
extern "C" void __cdecl FUN_00fdad30(void);
int __cdecl FUN_00ec658f(void (__cdecl* pfn)(void));

struct ObjA00a2 {
    long m_uiRefCount;
    virtual void v00();
    virtual void DeleteThis();
};

struct PtrA00a2 {
    ObjA00a2* m_pObject;
};

struct ArrA00a2 {
    void* m_vtbl;
    ObjA00a2** m_ppData;
    unsigned short unk08;
    unsigned short m_usMax;
    unsigned short m_usElementCount;

    void UpdateFields_00a2e680(unsigned int uiIndex, PtrA00a2& pSceneObject);
};

// @fnv 0x00a2e680
// src: GUESS 0x00a2e680 (confidence: low)
void ArrA00a2::UpdateFields_00a2e680(unsigned int uiIndex, PtrA00a2& aPtr)
{
    if (!(DAT_011f36a8 & 1)) {
        DAT_011f36a8 |= 1;
        DAT_011f36a4 = 0;
        FUN_00ec658f(FUN_00fdad30);
    }
    if (uiIndex >= m_usMax) {
        m_usMax = (unsigned short)(uiIndex + 1);
        if (aPtr.m_pObject != DAT_011f36a4) m_usElementCount += 1;
    } else if (aPtr.m_pObject != DAT_011f36a4) {
        if (m_ppData[uiIndex] == DAT_011f36a4) m_usElementCount += 1;
    } else {
        if (m_ppData[uiIndex] != DAT_011f36a4) m_usElementCount -= 1;
    }
    ObjA00a2** pSlot = &m_ppData[uiIndex];
    ObjA00a2* pOld = *pSlot;
    if (pOld != aPtr.m_pObject) {
        if (pOld) {
            if (InterlockedDecrement(&pOld->m_uiRefCount) == 0) pOld->DeleteThis();
        }
        ObjA00a2* pNew = aPtr.m_pObject;
        *pSlot = pNew;
        if (pNew) InterlockedIncrement(&pNew->m_uiRefCount);
    }
}

// Target object whose virtual slot 0xE0 (slot 56) is invoked for every entry.
class A30540Target {
public:
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
    virtual void v55();
    virtual void v56(int value);
};

struct A30540Entry {
    void* unk00;
    void* unk04;
    A30540Target* m_pFlagTarget;
    unsigned char m_uiFilterValue;
};

class FUN_00a30540_cls {
public:
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned int m_uiItemCount;
    void* unk10;
    A30540Entry* m_pEntries;
    void NiControllerSequence_DetachInterpolators();
};

// @fnv 0x00a30540
// src: XBOX_PDB 0x00a30540
void FUN_00a30540_cls::NiControllerSequence_DetachInterpolators()
{
    for (unsigned int index = 0; index < m_uiItemCount; index++) {
        A30540Entry* entry = &m_pEntries[index];
        if (entry->m_pFlagTarget != 0) {
            entry->m_pFlagTarget->v56(entry->m_uiFilterValue);
        }
    }
}

extern "C" int __cdecl strcmp(const char* s1, const char* s2);

struct FUN_00a305e0_cls {
    const char* m_00;

    bool Equals(const char* other);
};

// Returns true if the stored string pointer matches other, or if both are non-null and strcmp reports them equal.
// @fnv 0x00a305e0
bool FUN_00a305e0_cls::Equals(const char* other)
{
    if (m_00 == other) {
        return true;
    }
    if (other == 0 || m_00 == 0) {
        return false;
    }
    return strcmp(m_00, other) == 0;
}

namespace fnv_00a363b0 {
extern "C" unsigned char DAT_01096784;
extern "C" float DAT_01096b8c;
extern "C" unsigned int DAT_011a8400;
extern "C" unsigned int DAT_011a8404;
extern "C" unsigned int DAT_011a8408;
extern "C" unsigned int DAT_011f3704;
extern "C" unsigned int DAT_011f3708;
extern "C" unsigned int DAT_011f370c;
extern "C" unsigned int DAT_011f3710;
struct ArrayManager {
  void* Game_DoHeapAlloc(unsigned int size);
};
extern "C" ArrayManager DAT_011f6238;
struct FUN_00a362f0 {
  unsigned int unk00;
  unsigned int unk04;
  unsigned int unk08;
  unsigned int unk0c;
  unsigned int unk10;
  unsigned int unk14;
  unsigned int unk18;
  unsigned int unk1c;
  unsigned int unk20;
  unsigned int unk24;
  unsigned int unk28;
  unsigned int unk2c;
  unsigned int unk30;
  unsigned int unk34;
  unsigned int unk38;
  unsigned int unk3c;
  unsigned int unk40;
  volatile unsigned int unk44;
  volatile unsigned int unk48;
  unsigned int unk4c;
  unsigned int unk50;
  unsigned int unk54;
  unsigned int unk58;
  unsigned int unk5c;
  unsigned int unk60;
  unsigned int unk64;
  __declspec(nothrow) FUN_00a362f0();
  static void* operator new[](unsigned int n) {
    return DAT_011f6238.Game_DoHeapAlloc(n);
  }
};
struct Base {
  void* vtable;
  unsigned int unk04;
  unsigned int unk08;
  unsigned char unk0c;
  volatile unsigned char count;
  unsigned char unk0e;
  unsigned char unk0f;
  unsigned int unk10;
  unsigned int unk14;
  unsigned int unk18;
  unsigned int unk1c;
  unsigned int unk20;
  unsigned int unk24;
  unsigned int unk28;
  unsigned int unk2c;
  void NiBlendInterpolator_NiBlendInterpolator_00a370b0(int, float, int);
};
struct Object : Base {
  unsigned int unk30;
  unsigned int unk34;
  unsigned int unk38;
  unsigned int unk3c;
  unsigned int unk40;
  unsigned int unk44;
  unsigned int unk48;
  volatile float unk4c;
  FUN_00a362f0* unk50;
  unsigned char unk54;
  Object* InitObject(int a, float b, int c);
};
// Calls FUN_00a370b0, sets the vtable and several fields from globals, and allocates an array of FUN_00a362f0 sized by count into unk50.
// @fnv 0x00a363b0
Object* Object::InitObject(int aiArg, float afArg, int aiArg2) {
  NiBlendInterpolator_NiBlendInterpolator_00a370b0(aiArg,afArg,aiArg2);
  vtable = &DAT_01096784;
  unk30 = DAT_011a8400;
  unk34 = DAT_011a8404;
  unk38 = DAT_011a8408;
  unk3c = DAT_011f3704;
  unk40 = DAT_011f3708;
  unk44 = DAT_011f370c;
  unk48 = DAT_011f3710;
  unk4c = DAT_01096b8c;
  unsigned char itemCount = count;
  unk50 = 0;
  unk54 = 0;
  if (itemCount > 0) {
    FUN_00a362f0* items = new FUN_00a362f0[itemCount];
    unk50 = items;
  }
  return this;
}
}  // namespace fnv_00a363b0

static double DAT_010241b0 = -3.4028234663852886e+38;
static float DAT_01096b8c = -3.4028234663852886e+38f;
struct S_00a385d0_V3 {
    float x, y, z;
    S_00a385d0_V3 Neg() const { S_00a385d0_V3 r; r.x = -x; r.y = -y; r.z = -z; return r; }
};
struct S_00a385d0_Q { float a, b, c, d; };
S_00a385d0_Q* __cdecl FUN_00a6dc00(S_00a385d0_Q* dst, const S_00a385d0_Q* src);

struct S_00a385d0_T {
    S_00a385d0_V3 pos;
    S_00a385d0_Q rot;
    float scale;
    void InvertTransform(S_00a385d0_T* out);
};

// @fnv 0x00a385d0
void S_00a385d0_T::InvertTransform(S_00a385d0_T* out) {
    if (scale == DAT_010241b0) out->scale = DAT_01096b8c;
    else out->scale = 1.0f / scale;
    if (rot.b == DAT_010241b0) out->rot.b = DAT_01096b8c;
    else { S_00a385d0_Q t; out->rot = *FUN_00a6dc00(&t, &rot); }
    if (pos.x == DAT_010241b0) out->pos.x = DAT_01096b8c;
    else out->pos = pos.Neg();
}

// FUN_00a3a730 : __thiscall, 27 bytes
//   mov edx, [esp+8]
//   mov eax, [ecx]
//   mov eax, [eax+0xa0]
//   push 1
//   push edx
//   mov edx, [esp+0xc]
//   push edx
//   push 0
//   call eax
//   ret 8
// Forwards two arguments to the virtual slot 0xa0 of this object.

class FUN_00a3a730_cls
{
public:
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
    virtual void v40(int a, int b, int c, int d);
    void NiParallelUpdateTaskManager_AddTask(int a, int b);
};

// @fnv 0x00a3a730
// src: COMMUNITY 0x00a3a730
void FUN_00a3a730_cls::NiParallelUpdateTaskManager_AddTask(int aiArg1, int aiArg2)
{
    v40(0, aiArg1, aiArg2, 1);
}

#include "../../include/NiMemObject.h"

extern float DAT_0109a918;

template <> inline NiPointer<NiFloatData>::NiPointer() { m_pObject = 0; }
template <> inline NiPointer<NiFloatData>::~NiPointer() { if (m_pObject != 0) m_pObject->DecRefCount(); }
inline NiFloatInterpolator::NiFloatInterpolator()
    : NiKeyBasedInterpolator(), value(DAT_0109a918), data(), lastIndex(0) {}
inline void* __cdecl operator new(unsigned int, void* memory) throw() {
    return memory;
}
// Allocates a NiFloatInterpolator via NiMemObject::operator new and placement-constructs it, returning null on allocation failure.
// @fnv 0x00a3c570
NiFloatInterpolator* __cdecl CreateNiFloatInterpolator() {
    void* memory = NiMemObject::operator new(sizeof(NiFloatInterpolator));
    if (memory)
        return ::new (memory) NiFloatInterpolator;
    return 0;
}

// @fnv 0x00a3d520
int __cdecl AreFloatsEqual(const float* pfA, const float* pfB)
{
    if (*pfA == *pfB)
        return 1;
    return 0;
}

// AccumulateAnimSink: dispatch a request to the animation sink found at +0x24c
// of the object passed in, and accumulate the returned count.

struct AnimSink {
    int m_00;
    int m_04;
    int (__cdecl *m_08)(AnimSink* self, void* ctx, int count, int* out, int flag);
};

class FUN_00a3da20_cls {
public:
    void AccumulateAnimSink(int a1);
};

// Calls the sink's callback with count 4 and adds its return value to the sink's m_04 counter.
// @fnv 0x00a3da20
void FUN_00a3da20_cls::AccumulateAnimSink(int a1)
{
    AnimSink* sink = *(AnimSink**)((char*)a1 + 0x24c);
    int (__cdecl *fn)(AnimSink*, void*, int, int*, int) = sink->m_08;
    a1 = 4;
    sink->m_04 += fn(sink, this, 4, &a1, 1);
}

struct FUN_00a3da50_Anim {
    int m_unk00;
    int m_iArrayLength;
    int m_unk08;
    int (__cdecl *m_pfn)(FUN_00a3da50_Anim *pAnim, int iIndex, int iMode, int *pOut, int iFlag);
};

struct FUN_00a3da50_Owner {
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5C;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6C;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7C;
    int m_unk80;
    int m_unk84;
    int m_unk88;
    int m_unk8C;
    int m_unk90;
    int m_unk94;
    int m_unk98;
    int m_unk9C;
    int m_unkA0;
    int m_unkA4;
    int m_unkA8;
    int m_unkAC;
    int m_unkB0;
    int m_unkB4;
    int m_unkB8;
    int m_unkBC;
    int m_unkC0;
    int m_unkC4;
    int m_unkC8;
    int m_unkCC;
    int m_unkD0;
    int m_unkD4;
    int m_unkD8;
    int m_unkDC;
    int m_unkE0;
    int m_unkE4;
    int m_unkE8;
    int m_unkEC;
    int m_unkF0;
    int m_unkF4;
    int m_unkF8;
    int m_unkFC;
    int m_unk100;
    int m_unk104;
    int m_unk108;
    int m_unk10C;
    int m_unk110;
    int m_unk114;
    int m_unk118;
    int m_unk11C;
    int m_unk120;
    int m_unk124;
    int m_unk128;
    int m_unk12C;
    int m_unk130;
    int m_unk134;
    int m_unk138;
    int m_unk13C;
    int m_unk140;
    int m_unk144;
    int m_unk148;
    int m_unk14C;
    int m_unk150;
    int m_unk154;
    int m_unk158;
    int m_unk15C;
    int m_unk160;
    int m_unk164;
    int m_unk168;
    int m_unk16C;
    int m_unk170;
    int m_unk174;
    int m_unk178;
    int m_unk17C;
    int m_unk180;
    int m_unk184;
    int m_unk188;
    int m_unk18C;
    int m_unk190;
    int m_unk194;
    int m_unk198;
    int m_unk19C;
    int m_unk1A0;
    int m_unk1A4;
    int m_unk1A8;
    int m_unk1AC;
    int m_unk1B0;
    int m_unk1B4;
    int m_unk1B8;
    int m_unk1BC;
    int m_unk1C0;
    int m_unk1C4;
    int m_unk1C8;
    int m_unk1CC;
    int m_unk1D0;
    int m_unk1D4;
    int m_unk1D8;
    int m_unk1DC;
    int m_unk1E0;
    int m_unk1E4;
    int m_unk1E8;
    int m_unk1EC;
    int m_unk1F0;
    int m_unk1F4;
    int m_unk1F8;
    int m_unk1FC;
    int m_unk200;
    int m_unk204;
    int m_unk208;
    int m_unk20C;
    int m_unk210;
    int m_unk214;
    int m_unk218;
    int m_unk21C;
    int m_unk220;
    int m_unk224;
    int m_unk228;
    int m_unk22C;
    int m_unk230;
    int m_unk234;
    int m_unk238;
    int m_unk23C;
    int m_unk240;
    int m_unk244;
    int m_unk248;
    int m_unk24C;
    FUN_00a3da50_Anim *m_pAnim;
};

// @fnv 0x00a3da50
int __cdecl CallAnimCallback(FUN_00a3da50_Owner *pOwner, int iIndex)
{
    int iOut;
    FUN_00a3da50_Anim *pAnim = pOwner->m_pAnim;
    int (__cdecl *pfn)(FUN_00a3da50_Anim *, int, int, int *, int) = pAnim->m_pfn;
    iOut = 4;
    int iResult = pfn(pAnim, iIndex, 4, &iOut, 1);
    pAnim->m_iArrayLength += iResult;
    return iResult;
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct S_a3dd40_Obj {
    virtual ~S_a3dd40_Obj();
    virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
    void DecRefCount() throw() { if (!InterlockedDecrement(&m_uiRefCount)) DeleteThis(); }
};

struct S_a3dd40_Ptr {
    S_a3dd40_Obj* m_p;
    S_a3dd40_Ptr& operator=(S_a3dd40_Obj* p) {
        if (m_p != p) {
            if (m_p) m_p->DecRefCount();
            m_p = p;
        }
        return *this;
    }
    ~S_a3dd40_Ptr() throw() { if (m_p) m_p->DecRefCount(); }
};

struct FUN_00a3ca30 {
    virtual ~FUN_00a3ca30() throw();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

extern "C" void __cdecl _NiFree_00aa10f0(void*) throw();

struct FUN_00a3dd40 : FUN_00a3ca30 {
    S_a3dd40_Ptr m_kPointA;
    S_a3dd40_Ptr m_kPointB;
    void* m_p;
    virtual ~FUN_00a3dd40() throw();
};

// @fnv 0x00a3dd40
FUN_00a3dd40::~FUN_00a3dd40() throw()
{
    m_kPointA = 0;
    m_kPointB = 0;
    _NiFree_00aa10f0(m_p);
}

extern "C" float __cdecl func_0x00a42070(float input, float leftStart, float leftExtent, float rightStart, float rightEnd);

// @fnv 0x00a26fe0
// src: GAMEBRYO_LIB 0x00a26fe0
void __cdecl NiBezFloatKey_Interpolate(float a, const float* b, const float* c, float* pfResult)
{
    float c2 = c[2];
    float c1 = c[1];
    float b3 = b[3];
    float b1 = b[1];
    *pfResult = func_0x00a42070(a, b1, b3, c1, c2);
}

namespace fnv_00a29e00 {
typedef void (__cdecl *FUN_00a29e00_Callback)(int, int, unsigned char);

extern "C" FUN_00a29e00_Callback DAT_011f3780[];

// For each of 3 entries, if the target is nonzero, calls the callback from DAT_011f3780 indexed by slot with target, value and flag.
// @fnv 0x00a29e00
void __cdecl DispatchEntryCallbacks(void* pData)
{
    unsigned int index = 0;
    unsigned char* base = static_cast<unsigned char*>(pData);
    int* entry = reinterpret_cast<int*>(base + 0x30);

    do {
        int target = *entry;

        if (target) {
            unsigned char flag = *(base + 0x2C + index);
            int value = entry[-7];
            int slot = entry[-4];
            FUN_00a29e00_Callback callback = DAT_011f3780[slot];

            callback(target, value, flag);
        }

        ++index;
        ++entry;
    } while (index < 3);
}
}  // namespace fnv_00a29e00

struct FloatKey {
    float time;
    float value;
    ~FloatKey() throw() {}
    static void* operator new[](unsigned int n) { return ((P03MM*)&g_memoryManager)->Allocate(n); }
};

void __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int count);
float __cdecl GetValueAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);

// @fnv 0x00a2a620
// src: GUESS 0x00a2a620 (confidence: medium)
bool __cdecl Object_ConstructObject_00a2a620(float t, TCBKeyS** pKeys, unsigned int* puiCount)
{
    TCBKeyS* old = *pKeys;
    unsigned int idx;
    if (FindKeyIndex(t, old, *puiCount, &idx, 8)) {
        unsigned int newCount = *puiCount + 1;
        FloatKey* dst = new FloatKey[newCount];
        FUN_00ec44d0(dst, old, idx * 8);
        if (*puiCount > idx) {
            FUN_00ec44d0(dst + idx + 1, (FloatKey*)old + idx, (*puiCount - idx) * 8);
        }
        float v = GetValueAtTime(t, old, 1, *puiCount, 8);
        FloatKey* key = &dst[idx];
        key->time = t;
        key->value = v;
        (*puiCount)++;
        if (old != 0) {
            g_memoryManager.Deallocate((char*)old - 4);
        }
        *pKeys = (TCBKeyS*)dst;
        return true;
    }
    return false;
}

struct FUN_00a2ab10_Tail {
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
};

struct FUN_00a2ab10_T {
    float f00;
    FUN_00a2ab10_Tail tail;
};

// Copies the float and the four-word tail from src into dst.
// @fnv 0x00a2ab10
// src: GUESS 0x00a2ab10 (confidence: high)
void __cdecl Runtime_CopyFloatAndTail(FUN_00a2ab10_T* dst, const FUN_00a2ab10_T* src) {
    dst->f00 = src->f00;
    dst->tail = src->tail;
}

struct BezPosKey {
    float time;
    PointStorage pos;
    PointStorage in;
    PointStorage out;
    PointStorage unk28;
    PointStorage unk34;
    PointStorage unk40;
    ~BezPosKey() {}
    static void* operator new[](unsigned int n) { return ((P03MM*)&g_memoryManager)->Allocate(n); }
    static void operator delete[](void* p) { g_memoryManager.Deallocate(p); }
};
void BezSortKeys(BezPosKey* keys, unsigned int count, unsigned int stride);

// @fnv 0x00a2b850
bool InsertBezPosKey(float t, BezPosKey** pKeys, unsigned int* puiCount) {
    BezPosKey* oldKeys = *pKeys;
    unsigned int idx;
    if (FindKeyIndex(t, (TCBKeyS*)oldKeys, *puiCount, &idx, sizeof(BezPosKey))) {
        BezPosKey* newKeys = new BezPosKey[*puiCount + 1];
        _memmove(newKeys, oldKeys, idx * sizeof(BezPosKey));
        if (*puiCount > idx)
            _memmove(&newKeys[idx + 1], &oldKeys[idx], (*puiCount - idx) * sizeof(BezPosKey));
        NiPoint3 pos = GetKeyPosAtTime(t, (TCBKeyS*)oldKeys, 3, *puiCount, sizeof(BezPosKey));
        BezPosKey& key = newKeys[idx];
        key.time = t;
        memcpy(&key.pos, &pos, sizeof(key.pos));
        key.in.x = 0.0f;
        key.in.y = 0.0f;
        key.in.z = 0.0f;
        ++*puiCount;
        if (oldKeys)
            BezPosKey::operator delete[]((unsigned int*)oldKeys - 1);
        *pKeys = newKeys;
        BezSortKeys(newKeys, *puiCount, sizeof(BezPosKey));
        return true;
    }
    return false;
}

namespace fnv_00a2d4a0 {
struct InsertPositionKey {
    float time;
    PointStorage position;
    ~InsertPositionKey() {}
    static void* operator new[](unsigned int bytes) { return ((P03MM*)&g_memoryManager)->Allocate(bytes); }
};

bool FindKeyIndex(float, InsertPositionKey*, unsigned int, unsigned int*, unsigned int);
NiPoint3 GetKeyPosAtTime(float, InsertPositionKey*, int, unsigned int, unsigned int);
void* FUN_00ec44d0(void*, const void*, unsigned int);

// @fnv 0x00a2d4a0
// src: GUESS 0x00a2d4a0 (confidence: low)
bool Object_CopyData_00a2d4a0(float time, InsertPositionKey*& keys, unsigned int& count) {
    InsertPositionKey* old = keys;
    unsigned int index;
    if (FindKeyIndex(time, old, count, &index, 16)) {
        InsertPositionKey* pNewKeys = new InsertPositionKey[count + 1];
        FUN_00ec44d0(pNewKeys, old, index * sizeof(InsertPositionKey));
        if (count > index) {
            FUN_00ec44d0(pNewKeys + index + 1, old + index, (count - index) * sizeof(InsertPositionKey));
        }
        NiPoint3 position = GetKeyPosAtTime(time, old, 5, count, 16);
        InsertPositionKey* pInsertedKey = &pNewKeys[index];
        pInsertedKey->time = time;
        memcpy(&pInsertedKey->position, &position, sizeof(pInsertedKey->position));
        count++;
        if (old) {
            g_memoryManager.Deallocate((char*)old - 4);
        }
        keys = pNewKeys;
        return true;
    }
    return false;
}
}  // namespace fnv_00a2d4a0

// Scans the keys for the first whose time is not less than fTime, storing its index in uiIndex and returning false on an exact time match.
// @fnv 0x00a3d5d0
bool NiAnimationKey::FindKeyIndex(float fTime, NiAnimationKey* pkKeys, unsigned int uiNumKeys,
    unsigned int& uiIndex, unsigned char ucKeySize)
{
    bool bResult = true;
    for (uiIndex = 0; uiIndex < uiNumKeys; uiIndex++) {
        NiAnimationKey* pkKey = pkKeys->GetKeyPointerByIndex(uiIndex, ucKeySize);
        if (pkKey->GetTime() < fTime)
            continue;
        if (!(pkKey->GetTime() > fTime))
            bResult = false;
        break;
    }
    return bResult;
}

extern "C" double DAT_01011590;
extern "C" double DAT_01021928;

// For each key after the first, computes two NiPoint3 tangent values from neighbouring positions scaled by DAT_01011590 and DAT_01021928 and stores them in the key.
// @fnv 0x00a27ee0
void ComputeTCBKeyTangents(TCBKeyS* keys, unsigned int count, unsigned int stride)
{
    int remaining = (int)count + -1;
    if (remaining) {
        float* p = &keys[1].pos.z;
        double tcb = DAT_01011590;
        double scale = DAT_01021928;
        do {
            PointStorage scaledOut;
            scaledOut.x = p[-12] * tcb;
            scaledOut.y = p[-11] * tcb;
            scaledOut.z = p[-10] * tcb;
            PointStorage nextInScaled;
            nextInScaled.x = p[1] + scaledOut.x;
            nextInScaled.y = *(volatile float*)(p + 2) + scaledOut.y;
            nextInScaled.z = p[3] + scaledOut.z;
            volatile PointStorage delta;
            delta.x = p[-2] - p[-18];
            delta.y = p[-1] - p[-17];
            delta.z = p[0] - p[-16];
            PointStorage scaledDelta;
            scaledDelta.x = delta.x * scale;
            scaledDelta.y = delta.y * scale;
            scaledDelta.z = delta.z * scale;
            PointStorage result;
            result.x = scaledDelta.x - nextInScaled.x;
            result.y = scaledDelta.y - nextInScaled.y;
            result.z = scaledDelta.z - nextInScaled.z;
            PointStorage& out = *(PointStorage*)(p - 9);
            out = result;

            volatile PointStorage deltaAgain;
            deltaAgain.x = *(volatile float*)(p - 2) - p[-18];
            deltaAgain.y = p[-1] - p[-17];
            deltaAgain.z = p[0] - p[-16];
            PointStorage scaledDeltaAgain;
            scaledDeltaAgain.x = deltaAgain.x * tcb;
            scaledDeltaAgain.y = deltaAgain.y * tcb;
            scaledDeltaAgain.z = deltaAgain.z * tcb;
            PointStorage nextInOut;
            nextInOut.x = *(volatile float*)(p + 1) + p[-12];
            nextInOut.y = *(volatile float*)(p + 2) + p[-11];
            nextInOut.z = *(volatile float*)(p + 3) + p[-10];
            PointStorage resultAgain;
            resultAgain.x = nextInOut.x - scaledDeltaAgain.x;
            resultAgain.y = nextInOut.y - scaledDeltaAgain.y;
            resultAgain.z = nextInOut.z - scaledDeltaAgain.z;
            *(PointStorage*)(p - 6) = resultAgain;
            p += 16;
        } while (--remaining);
    }
}

struct Elem00a2dd70 {
    int unk00;
    int unk04;
    FNVHolder holder;
};

struct Dtor00a2dd70 {
    int unk00;
    int unk04;
    FNVHolder holder;

    Dtor00a2dd70* FUN_00a2dd70(unsigned char acFlags);
};

// @fnv 0x00a2dd70
Dtor00a2dd70* Dtor00a2dd70::FUN_00a2dd70(unsigned char acFlags)
{
    if (acFlags & 2) {
        int count = ((int*)this)[-1];
        Elem00a2dd70* e = (Elem00a2dd70*)((char*)this + count * sizeof(Elem00a2dd70));
        char* base = (char*)this - 4;
        if (--count >= 0) {
            do {
                --e;
                FNVRefObject* o = e->holder.object;
                if (o != 0) {
                    if (InterlockedDecrement(&o->referenceCount) == 0) {
                        o->DeleteThis();
                    }
                    e->holder.object = 0;
                }
                if (e->holder.text != DAT_0109b220) {
                    InterlockedDecrement((long*)(e->holder.text - 8));
                }
                o = e->holder.object;
                if (o != 0) {
                    if (InterlockedDecrement(&o->referenceCount) == 0) {
                        o->DeleteThis();
                    }
                }
            } while (--count >= 0);
        }
        if (acFlags & 1) {
            g_memoryManager.Deallocate(base);
        }
        return (Dtor00a2dd70*)base;
    }

    holder.ReleaseReference_00a2dd10();
    if (acFlags & 1) {
        g_memoryManager.Deallocate(this);
    }
    return this;
}

typedef void* (__cdecl* A29CF0CreateFn)(unsigned int uiNumKeys);
typedef void (__cdecl* A29CF0CopyFn)(void* pkNewKey, const void* pkOrigKey);
extern A29CF0CreateFn DAT_011f3930[];
extern A29CF0CopyFn DAT_011f39c0[];

// Copies three key arrays from pvSrc to pvDest, allocating each via the create function and copying elements with the copy function.
// @fnv 0x00a29cf0
void __cdecl CopyKeyData(void* pvDest, void* pvSrc)
{
    A29F00KeyData* pkDest = (A29F00KeyData*)pvDest;
    A29F00KeyData* pkSrc = (A29F00KeyData*)pvSrc;
    for (unsigned int i = 0; i < 3; i++)
    {
        pkDest->m_auiNumKeys[i] = pkSrc->m_auiNumKeys[i];
        pkDest->m_aeKeyType[i] = pkSrc->m_aeKeyType[i];
        unsigned int uiNumKeys = pkSrc->m_auiNumKeys[i];
        if (uiNumKeys)
        {
            A29CF0CreateFn pfnCreateKey = DAT_011f3930[pkSrc->m_aeKeyType[i]];
            pkDest->m_ppKeyData[i] = pfnCreateKey(uiNumKeys);
            A29CF0CopyFn pfnCopyKey = DAT_011f39c0[pkSrc->m_aeKeyType[i]];
            for (unsigned int j = 0; j < uiNumKeys; j++)
                pfnCopyKey((char*)pkDest->m_ppKeyData[i] + j * pkDest->m_aucKeySize[i],
                    (char*)pkSrc->m_ppKeyData[i] + j * pkSrc->m_aucKeySize[i]);
        }
    }
}

void __cdecl CompareHelpers(int a, int b);

// @fnv 0x00a2a1a0
// src: GUESS 0x00a2a1a0 (confidence: medium)
void __cdecl Object_CompareHelpers_Thunk(int a, int b)
{
    CompareHelpers(a, b);
}

struct A2C550Key {
    float m_fTime;
    float m_fValue;
    float m_fValueX;
    float m_fValueY;
    float m_fValueZ;
    float m_fData6;
    float m_fData7;
};
bool AreRecordsEqual(const A2C550Key& kA, const A2C550Key& kB);
// Returns true if AreRecordsEqual accepts the pair and the remaining five float fields of kA and kB are all equal.
// @fnv 0x00a2c550
// src: GUESS 0x00a2c550 (confidence: high)
bool Runtime_AreRecordsAndFloatFieldsEqual(const A2C550Key& kA, const A2C550Key& kB)
{
    if (!AreRecordsEqual(kA, kB))
        return false;
    return kA.m_fValueX == kB.m_fValueX && kA.m_fValueY == kB.m_fValueY && kA.m_fValueZ == kB.m_fValueZ
        && kA.m_fData6 == kB.m_fData6 && kA.m_fData7 == kB.m_fData7;
}

void __cdecl Object_ProcessState_00a29660(void* dst, const void* src);
// @fnv 0x00a2cfd0
// src: GUESS 0x00a2cfd0 (confidence: low)
void __cdecl Runtime_ProcessEntries_00a2cfd0(void* target, const unsigned char* source, unsigned int count) { for (unsigned int remaining = count; remaining > 0; --remaining) { Object_ProcessState_00a29660(target, source); source += 20; } }

namespace fnv_00a2d1d0 {
struct FloatRecord_b5532;
bool __cdecl AreRecordsEqual(FloatRecord_b5532* a, FloatRecord_b5532* b);

// @fnv 0x00a2d1d0
// src: GUESS 0x00a2d1d0 (confidence: medium)
bool __cdecl Runtime_AreRecordsEqual_Thunk(FloatRecord_b5532* a, FloatRecord_b5532* b)
{
    return AreRecordsEqual(a, b);
}
}  // namespace fnv_00a2d1d0


struct Key415 { float time; NiPoint3 value; };
// Subtracts the value of key b from key a and stores the resulting NiPoint3 in result.
// @fnv 0x00a2d420
// src: GAMEBRYO_LIB 0x00a2d420
void NiStepPosKey_InterpolateD1(float unused,const Key415& a,const Key415& b,NiPoint3& result) {
 result = a.value - b.value;
}

struct FNVAnim;
void __cdecl NiRotKey_FillDerivedVals(FNVAnim* object, unsigned int count, unsigned int flags);
// @fnv 0x00a2d670
// src: GUESS 0x00a2d670 (confidence: medium)
void __cdecl NiRotKey_FillDerivedVals_Thunk(FNVAnim* object, unsigned int count, unsigned int flags)
{
    NiRotKey_FillDerivedVals(object, count, flags);
}

bool Object_ProcessAndReturnValue_00a28a80(UHelper* a, UHelper* b);

// @fnv 0x00a2d680
// src: GUESS 0x00a2d680 (confidence: low)
bool Object_ForwardCall_00a2d680(UHelper* a, UHelper* b)
{
    return Object_ProcessAndReturnValue_00a28a80(a, b);
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern "C" bool __cdecl AreDataEqual(void* a, void* b);

// @fnv 0x00a2a7e0
// src: GUESS 0x00a2a7e0 (confidence: medium)
bool __cdecl Object_AreDataEqual_Thunk(void* a, void* b) {
    return AreDataEqual(a, b);
}

struct FUN_00a31240_T {
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    FUN_00a31240_T& ComputeValue_00a31240();
};

extern "C" unsigned char DAT_01096968;

// @fnv 0x00a31240
// src: GUESS 0x00a31240 (confidence: low)
FUN_00a31240_T& FUN_00a31240_T::ComputeValue_00a31240() {
    this->unk00 = 0;
    this->unk04 = 0;
    this->unk08 = 0;
    this->unk0C = DAT_01096968;
    this->unk0D = 0xff;
    return *this;
}

namespace KeyTables {
typedef void* KeyFn;
extern KeyFn DAT_011f3d20[][6];
extern KeyFn DAT_011f3c90[][6];
extern KeyFn DAT_011f3c00[][6];
extern KeyFn DAT_011f3b70[][6];
extern KeyFn DAT_011f3ae0[][6];
extern KeyFn DAT_011f3780[][6];
extern KeyFn DAT_011f3810[][6];
}
struct NiKeyA { static void __cdecl Runtime_UpdateState_00a27470(); };
struct NiKeyB { static void __cdecl Runtime_UpdateState_00a27470(); };
struct NiKeyC { static void __cdecl Runtime_UpdateState_00a27470(); };
// Stores six function pointers and a null into the KeyTables arrays at [eContent][eType].
// @fnv 0x00a27aa0
// src: GUESS 0x00a27aa0 (confidence: medium)
void __cdecl Object_SetKeyFunctionTable(int eContent, int eType)
{
    KeyTables::DAT_011f3d20[eContent][eType] = (void*)&Object_ComputeValue_00a291e0;
    KeyTables::DAT_011f3c90[eContent][eType] = (void*)&NiKeyA::Runtime_UpdateState_00a27470;
    KeyTables::DAT_011f3c00[eContent][eType] = (void*)&NiKeyB::Runtime_UpdateState_00a27470;
    KeyTables::DAT_011f3b70[eContent][eType] = (void*)&NiKeyC::Runtime_UpdateState_00a27470;
    KeyTables::DAT_011f3ae0[eContent][eType] = (void*)&AreDataEqual;
    KeyTables::DAT_011f3780[eContent][eType] = (void*)&Object_DoNothing;
    KeyTables::DAT_011f3810[eContent][eType] = 0;
}


class TimedRotationKey {
public:
    void Fix(TimedRotationKey& prev) { if(NiQuaternion::Dot(m_kRotationValue,prev.m_kRotationValue)<0.0f) memcpy(&m_kRotationValue, &m_kRotationValue.Negate(), sizeof(m_kRotationValue)); }
    float m_fTime;
    NiQuaternion m_kRotationValue;
    TimedRotationKey* GetKeyPointerByIndex(unsigned int uiIndex, unsigned char ucKeySize)
    {
        return (TimedRotationKey*)((char*)this + uiIndex * ucKeySize);
    }
};
// Negates rotation quaternions whose dot product with the previous key is negative, then clamps each key's X component to [-1, 1].
// @fnv 0x00a28ab0
// src: GAMEBRYO_LIB 0x00a28ab0
void __cdecl NiRotKey_FillDerivedVals(TimedRotationKey* pkKeys, unsigned int uiNumKeys, unsigned char ucKeySize)
{
    unsigned int ui;
    for (ui = 0; ui < uiNumKeys - 1; ui++)
    {
        pkKeys->GetKeyPointerByIndex(ui + 1, ucKeySize)->Fix(*pkKeys->GetKeyPointerByIndex(ui, ucKeySize));
    }
    for (ui = 0; ui < uiNumKeys; ui++)
    {
        TimedRotationKey* pkKey = pkKeys->GetKeyPointerByIndex(ui, ucKeySize);
        float fW = pkKey->m_kRotationValue.m_fVectorX;
        if (fW < -1.0f)
            pkKey->m_kRotationValue.m_fVectorX = -1.0f;
        else if (fW > 1.0f)
            pkKey->m_kRotationValue.m_fVectorX = 1.0f;
    }
}

extern "C" unsigned char DAT_011f367d;
extern "C" unsigned char __cdecl InterpolateBooleanKey(float, const void*, int, unsigned int, unsigned int*, unsigned char);

// Returns the value at the first or last key when fTime is out of range, otherwise calls InterpolateBooleanKey to interpolate between keys.
// @fnv 0x00a29470
// src: GAMEBRYO_LIB 0x00a29470
extern "C" unsigned char __cdecl NiBoolKey_GenInterpDefault(float fTime, const void* pkKeys, int uiType, unsigned int uiNumKeys, unsigned char ucSize) {
    if (uiNumKeys) {
        if (fTime < *(const float*)pkKeys)
            return *((const unsigned char*)pkKeys + 4);
        if (fTime > *(const float*)((const char*)pkKeys + (uiNumKeys - 1) * ucSize))
            return *((const unsigned char*)pkKeys + (uiNumKeys - 1) * ucSize + 4);
        unsigned int uiLastIdx = 0;
        return InterpolateBooleanKey(fTime, pkKeys, uiType, uiNumKeys, &uiLastIdx, ucSize);
    }
    return DAT_011f367d;
}

struct NiColorA_K { float r, g, b, a; NiColorA_K() {} };
extern NiColorA_K DAT_011f3680;
struct NiColorKey_K {
    float m_fTime;
    NiColorA_K m_kFogTint;
    float GetTime() const { return m_fTime; }
    NiColorA_K GetColor() const { return m_kFogTint; }
    NiColorKey_K* GetKeyPointerByIndex(unsigned int ui, unsigned char ucSize) { return (NiColorKey_K*)((char*)this + ui * ucSize); }
};
NiColorA_K __cdecl InterpolateColor(float fTime, NiColorKey_K* pkKeys, unsigned int eType,
    unsigned int uiNumKeys, unsigned int& uiLastIdx, unsigned char ucSize);
// Returns the color at fTime by clamping to the first or last key when out of range, otherwise calling InterpolateColor to interpolate between keys.
// @fnv 0x00a298f0
// src: GUESS 0x00a298f0 (confidence: high)
NiColorA_K __cdecl NiColorA_K_InterpolateColorClampedToKeys(float fTime, NiColorKey_K* pkKeys, unsigned int eType,
    unsigned int uiNumKeys, unsigned char ucSize)
{
    if (uiNumKeys) {
        if (fTime < pkKeys->GetTime())
            return pkKeys->GetColor();
        if (fTime > pkKeys->GetKeyPointerByIndex(uiNumKeys - 1, ucSize)->GetTime())
            return pkKeys->GetKeyPointerByIndex(uiNumKeys - 1, ucSize)->GetColor();
        unsigned int uiLastIdx = 0;
        return InterpolateColor(fTime, pkKeys, eType, uiNumKeys, uiLastIdx, ucSize);
    }
    return DAT_011f3680;
}

struct RotationChannels {
    int unk00, unk04, unk08, unk0c, unk10;
    void* keys[3];
    unsigned int counts[3];
    unsigned char types[3];
    unsigned char unk2f;
    unsigned int strides[3];
    unsigned int indices[3];
};
struct EulerQuat {
    float w, x, y, z;
    __forceinline void FromAngleAxesXYZ(float fAngleX, float fAngleY, float fAngleZ)
    {
        float fSinX, fCosX;
        fnv_SinCos(0.5 * fAngleX, fSinX, fCosX);
        float fSinY, fCosY;
        fnv_SinCos(0.5 * fAngleY, fSinY, fCosY);
        float fSinZ, fCosZ;
        fnv_SinCos(0.5 * fAngleZ, fSinZ, fCosZ);
        w = fCosX * (fCosZ * fCosY) + fSinX * (fSinZ * fSinY);
        x = fSinX * (fCosZ * fCosY) - fCosX * (fSinZ * fSinY);
        y = fCosX * (fSinY * fCosZ) + fSinX * (fSinZ * fCosY);
        z = fCosX * (fSinZ * fCosY) - fSinX * (fSinY * fCosZ);
    }
};
float InterpolateKey(float, unsigned int, unsigned int, void*, unsigned int*, unsigned char);
// @fnv 0x00a29b10
// src: GUESS 0x00a29b10 (confidence: low)
void Runtime_ProcessEntries_00a29b10(float fTime, const void* pkKey0, const void* pkKey1, void* pvResult)
{
    RotationChannels* pkEuler = (RotationChannels*)pkKey0;
    float afAngle[3];
    for (unsigned int i = 0; i < 3; ++i) {
        if (!pkEuler->keys[i])
            afAngle[i] = 0.0f;
        else
            afAngle[i] = InterpolateKey(fTime, pkEuler->strides[i], pkEuler->counts[i], pkEuler->keys[i], &pkEuler->indices[i], pkEuler->types[i]);
    }
    ((EulerQuat*)pvResult)->FromAngleAxesXYZ(afAngle[0], afAngle[1], afAngle[2]);
}

typedef bool (__cdecl *CompareFn)(unsigned int, unsigned int);
extern CompareFn g_compareTable[];

struct CompareBlock {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_cnt[3];
    unsigned int m_idx[3];
    unsigned char m_kPointB[3];
    unsigned char unk2F;
    unsigned int m_v[3];
};

// Returns true only when the three groups match in m_cnt, m_idx and the byte array, and each m_idx's g_compareTable function accepts all m_cnt value pairs.
// @fnv 0x00a29c20
// src: GAMEBRYO_LIB 0x00a29c20
bool NiEulerRotKey_Equal(const void* left, const CompareBlock* apRight)
{
    const CompareBlock* a = static_cast<const CompareBlock*>(left);
    for (unsigned int i = 0; i < 3; i++) {
        if (a->m_cnt[i] != apRight->m_cnt[i]) {
            return false;
        }
        if (a->m_idx[i] != apRight->m_idx[i]) {
            return false;
        }
        if (a->m_kPointB[i] != apRight->m_kPointB[i]) {
            return false;
        }
        if (a->m_cnt[i] > 0) {
            CompareFn fn = g_compareTable[a->m_idx[i]];
            for (unsigned int j = 0; j < a->m_cnt[i]; j++) {
                unsigned int uiRightValue = apRight->m_kPointB[i] * j + apRight->m_v[i];
                unsigned int uiLeftValue = a->m_kPointB[i] * j + a->m_v[i];
                if (!fn(uiLeftValue, uiRightValue)) {
                    return false;
                }
            }
        }
    }
    return true;
}

struct S_00a2a7f0_V3 {
    float x, y, z;
    S_00a2a7f0_V3() {}
    S_00a2a7f0_V3(float a, float b, float c) : x(a), y(b), z(c) {}
    S_00a2a7f0_V3 operator*(float s) const { return S_00a2a7f0_V3(x * s, y * s, z * s); }
    S_00a2a7f0_V3 operator+(const S_00a2a7f0_V3& o) const { return S_00a2a7f0_V3(x + o.x, y + o.y, z + o.z); }
};
struct S_00a2a7f0_Key {
    float time;
    S_00a2a7f0_V3 v;
};

// Computes a linear interpolation between two keyframe vectors using factor t and stores the result in out.
// @fnv 0x00a2a7f0
// src: GAMEBRYO_LIB 0x00a2a7f0
void __cdecl NiLinPosKey_Interpolate(float t, const S_00a2a7f0_Key* apFrom, const S_00a2a7f0_Key* apTo, S_00a2a7f0_V3* out)
{
    const S_00a2a7f0_Key* pFrom = apFrom;
    float s = 1.0f - t;
    *(float*)&apFrom = s;
    *out = apTo->v * t + pFrom->v * *(float*)&apFrom;
}

struct A2B1D0Vec {
    float x, y, z;
    A2B1D0Vec() {}
    A2B1D0Vec(float a, float b, float c) { x=a; y=b; z=c; }
    A2B1D0Vec operator-(const A2B1D0Vec& v) const { A2B1D0Vec r; r.x=x-v.x; r.y=y-v.y; r.z=z-v.z; return r; }
    A2B1D0Vec operator+(const A2B1D0Vec& v) const { return A2B1D0Vec(x+v.x,y+v.y,z+v.z); }
    A2B1D0Vec operator*(float f) const { return A2B1D0Vec(x*f,y*f,z*f); }
    A2B1D0Vec& operator*=(float f) { x*=f; y*=f; z*=f; return *this; }
};
struct A2B1D0Key {
    float time;
    A2B1D0Vec value;
    float tension, continuity, bias;
    A2B1D0Vec inTangent, outTangent;
    void NiTCBPosKey_CalculateDVals(const A2B1D0Vec& previous, const A2B1D0Vec& next, float before, float after);
};
// @fnv 0x00a2b1d0
// src: GAMEBRYO_LIB 0x00a2b1d0
void A2B1D0Key::NiTCBPosKey_CalculateDVals(const A2B1D0Vec& previous, const A2B1D0Vec& next, float before, float after) {
    A2B1D0Vec vDeltaPrev = value - previous;
    A2B1D0Vec vDeltaNext = next - value;
    float plusBias = 1.0f + bias;
    float minusBias = 1.0f - bias;
    float halfTension = (1.0f - tension) * 0.5;
    float plusContinuity = 1.0f + continuity;
    float a = halfTension * plusContinuity;
    float minusContinuity = 1.0f - continuity;
    float b = halfTension * minusContinuity;
    inTangent = vDeltaPrev * (b * plusBias) + vDeltaNext * (a * minusBias);
    float outNext = b * minusBias;
    A2B1D0Vec nextPart = vDeltaNext * outNext;
    float outPrev = a * plusBias;
    A2B1D0Vec prevPart = vDeltaPrev * outPrev;
    outTangent = prevPart + nextPart;
    float adjustment = 2.0 / (before + after);
    inTangent *= before * adjustment;
    outTangent *= after * adjustment;
}




struct PositionSplineKey {
    float m_fTime;
    NiPoint3 m_kPositionValue;
    float m_fValueX;
    float m_fValueY;
    float m_fValueZ;
    NiPoint3 m_kForwardTangent;
    NiPoint3 m_kBackwardTangent;
    NiPoint3 m_kOutgoingTangent;
    NiPoint3 m_kIncomingTangent;
    void NiTCBPosKey_CalculateDVals(const NiPoint3& kPrev, const NiPoint3& kNext, float fDT0, float fDT1);
};

inline void Calc(PositionSplineKey& p, PositionSplineKey& c, PositionSplineKey& n) { c.NiTCBPosKey_CalculateDVals(p.m_kPositionValue,n.m_kPositionValue,c.m_fTime-p.m_fTime,n.m_fTime-c.m_fTime); }

// Computes forward, backward, outgoing, and incoming tangents for each PositionSplineKey in a TCB spline of uiNumKeys keys.
// @fnv 0x00a2b410
// src: GAMEBRYO_LIB 0x00a2b410
void __cdecl NiTCBPosKey_FillDerivedVals(PositionSplineKey* pkTCB, unsigned int uiNumKeys)
{
    unsigned int uiNumKeysM1 = uiNumKeys - 1;
    if (uiNumKeys >= 2)
    {
        pkTCB[0].NiTCBPosKey_CalculateDVals(2.0f * pkTCB[0].m_kPositionValue - pkTCB[1].m_kPositionValue, pkTCB[1].m_kPositionValue, 1.0f, 1.0f);
        for(unsigned ui=1; ui<uiNumKeysM1; ++ui) {
            Calc(pkTCB[ui-1],pkTCB[ui],pkTCB[ui+1]);
        }
        unsigned int lastIndex=uiNumKeysM1;
        unsigned int prevIndex=uiNumKeys-2;
        pkTCB[lastIndex].NiTCBPosKey_CalculateDVals(pkTCB[prevIndex].m_kPositionValue, 2.0f*pkTCB[lastIndex].m_kPositionValue-pkTCB[prevIndex].m_kPositionValue,1.0f,1.0f);
    }

    PositionSplineKey* pkKey = pkTCB;
    PositionSplineKey* pkNext = pkTCB+1;
    for (unsigned int ui = 0; ui < uiNumKeysM1; ui++, pkKey++, pkNext++)
    {
        pkKey[0].m_kOutgoingTangent = 3.0f * (pkNext[0].m_kPositionValue - pkKey[0].m_kPositionValue)
            - (2.0f * pkKey[0].m_kBackwardTangent + pkNext[0].m_kForwardTangent);
        pkKey[0].m_kIncomingTangent = (pkKey[0].m_kBackwardTangent + pkNext[0].m_kForwardTangent)
            - 2.0f * (pkNext[0].m_kPositionValue - pkKey[0].m_kPositionValue);
    }
}

struct ElemA2 {
    float m_00, m_04, m_08, m_0c, m_10;
    ~ElemA2() {}
    static void* operator new[](unsigned int size) {
        return ((P03MM*)&g_memoryManager)->Allocate(size);
    }
    static void* operator new[](unsigned int size, unsigned int& total) throw() {
        total = size;
        return 0;
    }
};
typedef char ElemA2_size_check[sizeof(ElemA2) == 20 ? 1 : -1];
extern "C" void __stdcall _vector_constructor_iterator(void*, unsigned int, unsigned int, void*);
extern "C" void Clear();
// Allocates a raw block for count ElemA2 items, writes the count at the front, and constructs the elements via _vector_constructor_iterator.
// @fnv 0x00a2ced0
// src: GUESS 0x00a2ced0 (confidence: low)
void* __cdecl Runtime_AllocateStorage_00a2ced0(unsigned int count) {
    unsigned int total;
    new(total) ElemA2[count];
    char* raw = (char*)((P03MM*)&g_memoryManager)->Allocate(total);
    if (raw) {
        *(unsigned int*)raw = count;
        ElemA2* result = (ElemA2*)(raw + 4);
        _vector_constructor_iterator(result, 20, count, (void*)&Clear);
        return result;
    }
    return 0;
}

struct FUN_00a2d470_Entry {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

void __cdecl ApplyAnimToTarget(int a, FUN_00a2d470_Entry* e);

// Iterates over an array of FUN_00a2d470_Entry records and calls ApplyAnimToTarget for each one against the given target.
// @fnv 0x00a2d470
// src: GUESS 0x00a2d470 (confidence: high)
void __cdecl Runtime_ApplyAnimationsToTarget(int aiTarget, FUN_00a2d470_Entry* entries, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        ApplyAnimToTarget(aiTarget, &entries[i]);
    }
}

struct CloneableObj {
    void BSMultiTargetTreadTransfController_CopyMembers(CloneableObj* pObject, void* pData);
    void FUN_00a6cfe0(CloneableObj* pObject, void* pData);
};
// @fnv 0x00a2f8a0
// src: XBOX_PDB 0x00a2f8a0
void CloneableObj::BSMultiTargetTreadTransfController_CopyMembers(CloneableObj* pObject, void* pData)
{
    FUN_00a6cfe0(pObject, pData);
}

namespace sa359d0 {

extern "C" const char DAT_01096694[];

struct ControllerBase {
    const char* m_pVtbl;
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
    int unk30;

    static void* operator new(unsigned int uiSize);
    ControllerBase() throw();
};

struct Controller : ControllerBase {
    int m_i34;
    unsigned short m_us38;
    int m_i3c;
    unsigned short m_us40;

    Controller()
    {
        m_pVtbl = DAT_01096694;
        m_i34 = 0;
        m_us38 = 0;
        m_i3c = 0;
        m_us40 = 0;
    }
};

// Allocates and returns a new Controller object.
// @fnv 0x00a359d0
// src: XBOX_PDB 0x00a359d0
ControllerBase* BSMultiTargetTreadTransfController_CreateObject()
{
    return new Controller;
}

}

#include <math.h>
struct TextureCodec { unsigned int unk00,unk04,unk08,offset0c,converterIndex; unsigned char bytesPerElement; };
struct TexelSampler { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14; TextureCodec* codec;
float SampleLength(unsigned int x,unsigned int y,float value); };
typedef void (__cdecl *ConverterFn)(float,unsigned int,unsigned int,float*);
extern ConverterFn DAT_011f3c18[];
// Calls the codec's converter (by converterIndex) with value and offsets derived from x and y, and returns the length of the resulting 3-float vector.
// @fnv 0x00a3e5f0
float TexelSampler::SampleLength(unsigned int x,unsigned int y,float value) {
  unsigned int rgb=0, type;
  TextureCodec* pCodec=codec;
  unsigned char base;
  if(pCodec) {type=pCodec->converterIndex;base=pCodec->bytesPerElement;rgb=pCodec->offset0c;}
  else {type=0;base=0;}
  float afComponents[3];
  DAT_011f3c18[type](value,base*x+rgb,base*y+rgb,afComponents);
  float stride=afComponents[0]*afComponents[0]+afComponents[1]*afComponents[1]+afComponents[2]*afComponents[2];
  return sqrtf(stride);
}

extern "C" double DAT_01011588;
extern "C" double DAT_01011590;

// Float TCB (Kochanek-Bartels) key.
struct FUN_00a2c6a0_Key {
    float time;        // +0x00
    float value;       // +0x04
    float tension;     // +0x08
    float continuity;  // +0x0c
    float bias;        // +0x10
    float ds;          // +0x14
    float dd;          // +0x18
};

// Computes the ds and dd tangent components for a keyframe from its bias, tension, continuity and neighbouring values.
// @fnv 0x00a2c6a0
// src: GAMEBRYO_LIB 0x00a2c6a0
void __cdecl NiTCBFloatKey_CalculateDVals(FUN_00a2c6a0_Key* key, float prev, float next, float prevLen, float nextLen)
{
    float fDeltaPrev = key->value - prev;
    float fDeltaNext = next - key->value;
    float fOpBias = key->bias + 1.0f;
    float fOmBias = 1.0f - key->bias;
    float fOmTension = (1.0f - key->tension) * DAT_01011588;
    float fOpContinuity = key->continuity + 1.0f;
    float a = fOpContinuity * fOmTension;
    float fOmContinuity = 1.0f - key->continuity;
    float b = fOmTension * fOmContinuity;
    float adj = DAT_01011590 / (prevLen + nextLen);

    float ds = b * fOpBias * fDeltaPrev + a * fOmBias * fDeltaNext;
    key->ds = prevLen * adj * ds;
    float dd = a * fOpBias * fDeltaPrev + b * fOmBias * fDeltaNext;
    key->dd = nextLen * adj * dd;
}

namespace fnv_00a2aa50 {
void __cdecl InsertLinPosKey();

// Stores function pointers into KeyTables arrays indexed by content and type.
// @fnv 0x00a2aa50
// src: GUESS 0x00a2aa50 (confidence: medium)
void NiLinPosKey_Interpolate_RegisterKeyTableHandlers(int content, int type)
{
    KeyTables::DAT_011f3d20[content][type] = (void*)&Object_ComputeValue_00a291e0;
    KeyTables::DAT_011f3c90[content][type] = (void*)&NiLinPosKey_Interpolate;
    KeyTables::DAT_011f3c00[content][type] = (void*)&NiLinPosKey_InterpolateD1;
    KeyTables::DAT_011f3b70[content][type] = (void*)&Runtime_UpdateState_00a27470;
    KeyTables::DAT_011f3ae0[content][type] = (void*)&Object_AreDataEqual_Thunk;
    KeyTables::DAT_011f3780[content][type] = (void*)&Object_DoNothing;
    KeyTables::DAT_011f3810[content][type] = (void*)&InsertLinPosKey;
}
}  // namespace fnv_00a2aa50

namespace LinearColorArrayDetail
{
struct ArrayElement : NiColorKey_K
{
    ArrayElement() throw() {}
    ~ArrayElement() {}
    static void* operator new[](unsigned int bytes, unsigned int& requested) throw()
    {
        requested = bytes;
        return 0;
    }
};
struct ArrayCookie
{
    unsigned int count;
};
}

extern "C" void* __fastcall NiColorKey_Init(void* element);

// Allocates a block of NiColorKey_K elements via g_memoryManager and constructs them with FUN_0052d160.
// @fnv 0x00a2a1b0
// src: GUESS 0x00a2a1b0 (confidence: low)
NiColorKey_K* NiColorKey_K_AllocateStorage_00a2a1b0(unsigned int count)
{
    unsigned int requested;
    new(requested) LinearColorArrayDetail::ArrayElement[count];
    LinearColorArrayDetail::ArrayCookie* block =
        static_cast<LinearColorArrayDetail::ArrayCookie*>(
            reinterpret_cast<P03MM*>(&g_memoryManager)->Allocate(requested));
    if (block)
    {
        block->count = count;
        NiColorKey_K* result = reinterpret_cast<NiColorKey_K*>(block + 1);
        _vector_constructor_iterator(result, sizeof(NiColorKey_K), count,
            reinterpret_cast<void*>(&NiColorKey_Init));
        return result;
    }
    return 0;
}

struct A2CC30_Shell {
    static bool __cdecl NiBoolKey_Equal(const Helper* apFirst, const Helper* apSecond);
};

// @fnv 0x00a2cc30
// src: GUESS 0x00a2cc30 (confidence: low)
bool __cdecl NiBoolKey_Equal_ForwardCall_00a2cc30(int param_1, int param_2)
{
    return A2CC30_Shell::NiBoolKey_Equal(reinterpret_cast<const Helper*>(param_1),
                                      reinterpret_cast<const Helper*>(param_2));
}
