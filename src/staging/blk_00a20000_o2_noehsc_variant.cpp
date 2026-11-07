
// src/staging/blk_00a20000_o2_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00a20000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00a20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/NiBinaryStream.h"
#include "../../include/NiTObjectArray.h"
#include "../../include/NiTPrimitiveSet.h"
#include "../../include/NiPoint3.h"
#include "../../include/Vec4.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiBound.h"
#include "../../include/NiColor.h"
#include "../../include/NiFloatInterpolator.h"
#include "../../include/NiKeyBasedInterpolator.h"
#include "../../include/NiStream.h"
#include "../../include/NiTFixedStringMap_NiAVObject___.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTStringPointerMap.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                               unsigned int* sizes, unsigned int count)
{
    unsigned int transferred = m_pfnRead(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += transferred;
    return transferred;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
                                                unsigned int* sizes, unsigned int count)
{
    unsigned int transferred = m_pfnWrite(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += transferred;
    return transferred;
}

void NiBezFloatKey_Copy(float* a, const float* b);
extern "C" int _NiPoint3_ZERO;
extern "C" unsigned int DAT_011f4270;
extern "C" unsigned int DAT_011f4274;
void __cdecl Runtime_UpdateState_00a27470(int a, int b, int c, int* p);
extern "C" void __cdecl ReadBlockEntries(void*, void*);
void __cdecl NiEulerRotKey_SaveToStream(void* a, void* b, unsigned int c);
extern MemoryManager g_memoryManager;
void NiStepPosKey_DeleteArray(void* p);
extern "C" void __cdecl SaveKey(int, int);
void __cdecl NiTCBPosKey_SaveToStream(int a, int b, unsigned int count);
struct FUN_00a2cc10_T
{
    float f;
    char c;
};
void __cdecl NiStepBoolKey_Copy(FUN_00a2cc10_T* dst, const FUN_00a2cc10_T* src);
void CopyFloat2(float* dst, const float* src);
extern int DAT_011f49e0;
void __stdcall FUN_00a312d0(int, int, int, int, int);
void __cdecl Object_ForwardCall_00a31680();
extern "C" float __cdecl GetAccumulatedValue();
struct FUN_00a3ea40_cls
{
    void UpdateIfFlagged();
};
struct P03MM
{
    void* Allocate(unsigned int);
};
void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS
{
    float time;
    NiPoint3 pos;
    NiPoint3 in;
    NiPoint3 out;
    float extra[6];
    ~TCBKeyS()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
NiPoint3 GetKeyPosAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);
void NiInterpScalar_AdjustBezier(float p0, float t0, float* tan0, float p1, float t1, float* tan1, float t, float p, float* a,
                  float* b);
void ComputeTCBKeyTangents(TCBKeyS* keys, unsigned int count, unsigned int stride);
bool Object_CopyData_00a282a0(float t, TCBKeyS** pKeys, unsigned int* pCount);
extern "C" unsigned char DAT_011f367d;
void StoreGlobalByte(int a, int b, int c, unsigned char* d);
struct Inner_00a6db50
{
    void Set(float, float, float, float);
};
Inner_00a6db50* ScaleAndApply(Inner_00a6db50* a, float b, const float* c);
void CopyFloat7(float* dst, const float* src);
struct FUN_00a30880_T
{
    void ReleaseItems();
};
void CopyFloatBlock(float* dst, const float* src);
struct FUN_00a29a70 : public Inner_00a6db50
{
    float a, b, c, d;
    float e, f, g;
    char h, i, j;
    float k, l, m;
    float n, o, p;
    float q, r, s;
    FUN_00a29a70();
};
void __cdecl IsLightEqual();
void __cdecl NiTCBPosKey_Interpolate();
void __cdecl ComputeInterpolatedPosition();
void __cdecl NiTCBPosKey_InterpolateD2();
void __cdecl NiTCBPosKey_FillDerivedVals();
void __cdecl NiTCBPosKey_ComputeMaxCurvature();
void __cdecl InsertBezPosKey();
void __cdecl Object_SetKeyFunctionTables(int a, int b);
struct FUN_00a2ceb0_cls
{
    float pad;
    float x, y, z, w;
    FUN_00a2ceb0_cls& Clear();
};
extern unsigned char DAT_01096968;
typedef int(__stdcall* FnInterlockedDecrement)(void*);
extern FnInterlockedDecrement DAT_00fdf1c4;
struct FUN_00a31260_StandIn
{
    void* p0;
    void* p1;
    void* p2;
    unsigned char b3;
    unsigned char b4;
    void ReleaseReferencedObjectsAndResetFlags();
};
struct FUN_00a30700_T
{
    void* p0;
    void* p1;
    void ReleaseRefs();
};
struct Base_00a26eb0
{
    void AccumulateAnimSink(NiStream&);
};
struct FUN_00a27430_T : Base_00a26eb0
{
    char pad[4];
    NiColor m_kDiffuseColor;
    void LoadBinaryFields_00a27430(NiStream& stream);
};
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
void Object_UpdateFields_00a28620(int param_1, int param_2);
struct Helper
{
    unsigned int a;
    char b;
};
bool AreFloatsEqual(const Helper* x, const Helper* y);
bool NiBoolKey_Equal(const Helper* a, const Helper* b);
struct SStream;
struct SObj;
void __cdecl WriteFloatToStream(SStream*, SObj*);
void __cdecl NiAnimationKey_SaveToStream(SStream* a, SObj* b, unsigned int c);
extern int DAT_01096114;
extern void __cdecl _NiFree(void*);
extern MemoryManager _g_memoryManager;
struct FUN_00a2e790_StandIn : public NiTFixedStringMap_NiAVObject___
{
    void* p;
    void* DestroyFixedStringMap(unsigned char deleting);
};
struct FUN_00a39120_cls
{
    float x, y, z, w;
    Inner_00a6db50* ScaleFourComponents(Inner_00a6db50* out, float s);
};
struct FloatRecord_b5532
{
    int unk00;
    float m_04;
};
bool AreFloatsEqual(FloatRecord_b5532* a, FloatRecord_b5532* b);
bool AreRecordsEqual(FloatRecord_b5532* a, FloatRecord_b5532* b);
typedef void(__thiscall* Fn_00a26fa0_cb)(void*);
void __stdcall ApplyCallbackBackwards(char* p, int iTileIndex, int nCount, Fn_00a26fa0_cb pFn);
struct TempArrayElement
{
    void* a;
    void* b;
    void* c;
    void* d;
    ~TempArrayElement()
    {}
    static void* operator new[](unsigned int size)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(size);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
TempArrayElement* __cdecl AllocateTempArray(unsigned int count);
extern MemoryManager g_memoryManager;
void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS;
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
struct BezFloatKey
{
    float time;
    float value;
    float inTan;
    float outTan;
    ~BezFloatKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
float GenInterpFloat(float t, BezFloatKey* keys, int type, unsigned int count, unsigned int stride);
void NiInterpScalar_AdjustBezier(float p0, float t0, float* tan0, float p1, float t1, float* tan1, float t, float p, float* a,
                  float* b);
bool Object_InsertBezierFloatKey(float fTime, BezFloatKey*& pkKeys, unsigned int& uiNumKeys);
class A27250Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
class A27250Stream
{
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
    NiBinaryStream* m_pUnderlyingStream;
};
template <class T> inline void A27250BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void A27250LoadBinary(A27250Stream& kStream, T& value)
{
    A27250BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
class A27250FloatKey
{
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
A27250FloatKey* LoadFloatKeys(A27250Stream& kStream, unsigned int uiNumKeys);
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
void __cdecl ApplyAnimToTarget(int a, AnimTarget* b);
struct FUN_00a27b60_tail
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct FUN_00a27b60_rec
{
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
void __cdecl NiBezPosKey_Copy(FUN_00a27b60_rec* dst, const FUN_00a27b60_rec* src);
struct A27BD0Point3
{
    float x;
    float y;
    float z;

    bool IsEqual(const A27BD0Point3& kOther) const;
};
struct A27BD0Key
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
bool A27BD0KeyEqual(const A27BD0Key& kA, const A27BD0Key& kB);
struct A27BD0BezKey : A27BD0Key
{
    float m_fValue;
    float m_fInTangent;
    float m_fOutTangent;
    A27BD0Point3 m_kTCB;
};
bool BezKeyEqual(const A27BD0BezKey& kA, const A27BD0BezKey& kB);
struct DynamicMemoryAllocator
{
    void* Allocate(unsigned int auiSize);
    void Free(void* apPtr);
};
extern "C" DynamicMemoryAllocator DAT_011f6238;
struct Elem64
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

    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
    ~Elem64()
    {}
};
void* AllocateElem64Array(unsigned int count);
class A27C80Point3
{
  public:
    float x, y, z;

    A27C80Point3()
    {}
    A27C80Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    A27C80Point3 operator+(const A27C80Point3& pt) const
    {
        return A27C80Point3(x + pt.x, y + pt.y, z + pt.z);
    }
    A27C80Point3 operator*(float fScalar) const
    {
        return A27C80Point3(x * fScalar, y * fScalar, z * fScalar);
    }
};
struct A27C80CubicKey
{
    float m_fTime;
    A27C80Point3 m_kValue;
    A27C80Point3 m_kTangent;
    A27C80Point3 m_kB;
    A27C80Point3 m_kC;
    A27C80Point3 m_kCubicCoefficient;
};
void EvaluateCubicKey(float fTime, const A27C80CubicKey& kKey, unsigned int uiUnused, A27C80Point3& kResult);
extern double DAT_01021928;
extern double DAT_01011590;
void __cdecl NiBezPosKey_InterpolateD1(float t, TCBKeyS* key, unsigned int type, NiPoint3* result);
class A281E0Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
class A281E0Stream;
struct A281E0Point3
{
    float x;
    float y;
    float z;

    void LoadBinary(A281E0Stream& kStream);
};
class A281E0BezPosKey
{
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};
A281E0BezPosKey* LoadBezPosKeys(A281E0Stream& kStream, unsigned int uiNumKeys);
class NiColorSaveHelper
{
  public:
    float r;
    float g;
    float b;

    void SaveBinary(NiStream& kStream);
};
struct A28260Key
{
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
void __cdecl SaveKeyArray(NiStream& kStream, A28260Key* pkKeys, unsigned int uiNumKeys);
struct Inner_b5508
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Vec4* Set(float a, float b, float c, float d);
};
void NiRotKey_Interpolate(unsigned int a0, unsigned int a1, unsigned int a2, Vec4* out);
struct FUN_00a28720_target
{
    void __thiscall FUN_00a6e4a0(void* value);
};
void __cdecl CallAnimCallback(void* a, void* b);
void __cdecl Object_ProcessState_00a28720(void* a, void* b);
extern "C" unsigned int DAT_011f366c;
extern "C" unsigned int DAT_011f3670;
extern "C" unsigned int DAT_011f3674;
extern "C" unsigned int DAT_011f3678;
void __cdecl FUN_00a28740(void* out, float t, void* keys, void* arg4, unsigned int n, unsigned int* pIdx,
                          unsigned char stride);
struct FUN_00a289b0_Vec4
{
    unsigned int a, b, c, d;
};
FUN_00a289b0_Vec4* __cdecl SampleKeyedVec4(FUN_00a289b0_Vec4* out, float t, char* keys, void* arg4, unsigned int count,
                                           unsigned char stride);
struct Sub_a28
{
    int unk00;
    bool Object_HasEqualFloatComponents(Sub_a28* other);
};
struct Obj_a28
{
    int unk00;
    Sub_a28 m_kSub;
};
bool __cdecl AreFloatsEqual(Obj_a28* a, Obj_a28* b);
bool __cdecl Object_ProcessAndReturnValue_00a28a80(Obj_a28* a, Obj_a28* b);
struct Blk16
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};
struct Blk36
{
    float m_00;
    Blk16 m_04;
    Blk16 m_14;
};
void CopyBlk36(Blk36* dst, const Blk36* src);
struct SpawnTarget
{
    void Callee(float a, void* p1, void* p2, void* p3, void* p4);
};
void __cdecl CallSpawnTarget(float a, char* x, char* y, SpawnTarget* z);
// Reconstruction of FUN_00a28dc0.
//
// The object is a fixed-size array of 36-byte key records:
//   +0x00  quaternion q0   (16 bytes)
//   +0x10  quaternion q1   (16 bytes)
//   +0x20  float           ( 4 bytes)
// The key array itself starts at obj+0x04 (obj+0x00 is a scalar header).
struct FNVQuat
{
    float x;
    float y;
    float z;
    float w;
};
struct FNVKey
{
    FNVQuat q0;
    FNVQuat q1;
    float e;
};
struct FNVAnim
{
    float f00;
    FNVKey keys[64];
};
extern void __cdecl NiRotKey_FillDerivedVals(FNVAnim* obj, unsigned int count, unsigned int flag);
extern FNVQuat* __cdecl NiQuaternion_Intermediate(FNVQuat* out, FNVQuat* a, FNVQuat* b, FNVQuat* c);
void __cdecl NiBezRotKey_FillDerivedVals(FNVAnim* obj, unsigned int count, unsigned int flag);
// The game class NiBound - a 16-byte bound (three position floats and a radius).
// UHelper layout as read off the image: a float at +0, then two 16-byte
// NiBound sub-objects at +4 and at +0x14.
struct UHelper
{
    float unk00;
    NiBound unk04;
    NiBound unk14;
};
// The primary comparison: the float at +0 and the NiBound sub-object at +4.
bool Object_ProcessAndReturnValue_00a28a80(UHelper* a, UHelper* b);
bool CompareBounds(UHelper* a, UHelper* b);
typedef void(__cdecl* A291F0Func)();
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
void __cdecl RegisterCurveOps(int eContent, int eType);
struct FUN_00a29550_owner
{
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
    NiBinaryStream* m_250;
};
int __cdecl Runtime_UpdateState_00a29550(int a1, int a2);
struct Inner
{
    void FUN_00a698a0(void* target);
};
struct Outer
{
    int unk00;
    Inner inner04;
};
void __cdecl CallAnimCallback(void* target, Outer* source);
void __cdecl Object_ProcessState_00a29660(void* target, Outer* source);
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
struct FNV_Inner
{
    float v[4];
};
struct FNV_Obj
{
    int unk00;
    FNV_Inner inner;
    int m14[3];
    int m20[3];
    char m2c[3];
    int m30[3];
    int m3c[3];
};
typedef bool(__cdecl* FNV_CbFn)(float, int*, int*);
extern FNV_CbFn g_fnv_cb_011f3810[];
// The game's vector constructor iterator: it calls the element constructor
// (a plain function pointer, the object pointer travels in ECX) once per
// element.  It pops its own four arguments.
extern "C" void __stdcall FNV_array_ctor_iterator(void* base, unsigned int size, unsigned int count, void* ctor);
// The element constructor of the allocated object.
extern "C" void __cdecl FNV_element_ctor(void* self);
bool UpdateArrayElements(float t, void** pOut, int* pFlag);
class A29F00Stream
{
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
template <class T> inline void A29F00BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void A29F00LoadBinary(A29F00Stream& kStream, T& value)
{
    A29F00BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}
typedef void*(__cdecl* A29F00LoadFunc)(A29F00Stream& kStream, unsigned int uiNumKeys);
extern unsigned char DAT_011f3758[];
extern A29F00LoadFunc DAT_011f3db0[];
class A29F00KeyData
{
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
struct A29FE0Context
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
    NiBinaryStream* m_pDataStream;
};
struct A29FE0Block
{
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
void ReadBlockEntries(A29FE0Context* pkContext, A29FE0Block* pkBlock);
struct Quaternion
{
    float x;
    float y;
    float z;
    float w;
    Quaternion& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }
    Quaternion operator+(const Quaternion& other) const
    {
        Quaternion result = *this;
        result.x += other.x;
        result.y += other.y;
        result.z += other.z;
        result.w += other.w;
        return result;
    }
};
struct QuaternionKey
{
    float time;
    Quaternion value;
};
void __cdecl InterpolateQuaternion(float interpolation, const QuaternionKey* first, const QuaternionKey* second,
                                   Quaternion* output);
float __cdecl NiInterpScalar_Linear(float a, float b, float c);
void __cdecl NiLinFloatKey_Interpolate(float s, const NiPoint3* a, const NiPoint3* b, float* out);
struct CopyTail12
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};
struct CopyBlk16
{
    float m_00;
    CopyTail12 m_04;
};
void __cdecl Runtime_UpdateState_00a2a7b0(CopyBlk16* dst, const CopyBlk16* src);
class A2A890Point3
{
  public:
    float x, y, z;

    A2A890Point3()
    {}
    A2A890Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    A2A890Point3 operator-(const A2A890Point3& pt) const
    {
        return A2A890Point3(x - pt.x, y - pt.y, z - pt.z);
    }
};
struct A2A890Key
{
    float m_fTime;
    A2A890Point3 m_kValue;
};
void NiLinPosKey_InterpolateD1(float fTime, const A2A890Key& kKey0, const A2A890Key& kKey1, A2A890Point3& kResult);
struct VertexRecord
{
    int x, y, z, w;
    ~VertexRecord()
    {}
    void LoadBinaryFields_00a27430(int);
    static void* operator new[](unsigned int size)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(size);
    }
};
VertexRecord* __cdecl CreateVertexRecords(int v, unsigned int count);
// MemoryManager and NiPoint3 use shared declarations; P03MM is the allocation-call adapter.
extern MemoryManager g_memoryManager;
void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS;
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);
NiPoint3 GetKeyPosAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);
// Linear position key: time + position (16 bytes).
struct AnimKeyBase
{
    float time;
    ~AnimKeyBase() throw()
    {}
};
struct LinPosKey : AnimKeyBase
{
    NiPoint3 pos;
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
bool InsertLinPosKey(float t, LinPosKey** pKeys, unsigned int* pCount);
struct FUN_00a6e330_StandIn
{
    void __thiscall FUN_00a6e330(float value, const void* first, const void* second);
};
void __cdecl Runtime_ForwardCall_00a2ab90(float value, const void* first, const void* second, FUN_00a6e330_StandIn* result);
// Structural equality of two light-like objects: base equality, three scalar terms, four vectors.
struct A2AE90Point3
{
    float x;
    float y;
    float z;
    bool IsEqual(const A2AE90Point3& kOther) const;
};
struct A2AE90Light
{
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
bool __cdecl IsLightEqual(A2AE90Light* pkA, A2AE90Light* pkB);
// FNV candidate v2: AllocateBezierKeys (0x00a2af30, 61 bytes)
// return new BezierKeyS[count]; with sizeof(element)=76 (0x4c), non-trivial dtor -> 4-byte cookie,
// class-specific operator new[] inlining to ((P03MM*)&g_memoryManager)->Allocate(n).
// Packet TU already provides MemoryManager/NiPoint3/P03MM/g_memoryManager/TCBKeyS(64B);
// element type must be 76 bytes, so it is a distinct type, not the packet's TCBKeyS.
struct BezierKeyS
{
    float time;
    NiPoint3 pos;
    NiPoint3 in;
    NiPoint3 out;
    float extra[9];
    ~BezierKeyS()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
BezierKeyS* __cdecl AllocateBezierKeys(unsigned int count);
struct S_00a2af70_V
{
    float x, y, z;
};
struct S_00a2af70_P
{
    int unk00;
    S_00a2af70_V c1;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    S_00a2af70_V c2;
    S_00a2af70_V c3;
    S_00a2af70_V c4;
};
static __forceinline S_00a2af70_V Scale(const S_00a2af70_V& v, float t)
{
    S_00a2af70_V r;
    r.x = v.x * t;
    r.y = v.y * t;
    r.z = v.z * t;
    return r;
}
static __forceinline S_00a2af70_V Add(const S_00a2af70_V& a, const S_00a2af70_V& b)
{
    S_00a2af70_V r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}
void __cdecl NiTCBPosKey_Interpolate(float t, S_00a2af70_P* p, int unused, S_00a2af70_V* out);
struct S_00a2b050_V3
{
    float x, y, z;
    S_00a2b050_V3()
    {}
    S_00a2b050_V3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    S_00a2b050_V3 operator+(const S_00a2b050_V3& o) const
    {
        return S_00a2b050_V3(x + o.x, y + o.y, z + o.z);
    }
    S_00a2b050_V3 operator*(float s) const
    {
        return S_00a2b050_V3(x * s, y * s, z * s);
    }
};
struct S_00a2b050_Obj
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
    S_00a2b050_V3 pos;
    S_00a2b050_V3 velA;
    S_00a2b050_V3 velB;
};
S_00a2b050_V3* __cdecl ComputeInterpolatedPosition(float t, S_00a2b050_Obj* o, int unused, S_00a2b050_V3* out);
extern "C" double DAT_01034208;
extern "C" double DAT_01011590;
void __cdecl NiTCBPosKey_InterpolateD2(float amount, const float* transform, unsigned int unused, NiPoint3* result);
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    unsigned int size = sizeof(T);
    stream.m_pkIstr->BinaryRead(&value, size, &size, 1);
}
struct FUN_00a2b980_cls
{
    char unk00[0x10];
    unsigned int m_uiA;
    unsigned int m_uiB;
    unsigned int m_uiC;

    void LoadBinaryFields_00a27430(NiStream& stream);
    void ReadKeyFields(NiStream& stream);
};
template <class T>
inline void BA2BA10BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BA2BA10SaveBinary(NiStream& kStream, const T& value)
{
    BA2BA10BinaryStreamSave(*(NiBinaryStream*)kStream.m_pBackingStream, &value);
}
struct BA2BA10Key
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};
void __cdecl ApplyAnimToTarget(NiStream& kStream, BA2BA10Key* pkKey);
void __cdecl SaveKey(NiStream& kStream, BA2BA10Key* pkKey);
struct A2BBF0Quad
{
    int m_iA;
    int m_iB;
    int m_iC;
    int m_iD;
};
struct A2BBF0Record
{
    float m_fTime;
    A2BBF0Quad m_kControlPoint;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    A2BBF0Quad m_kStartPoint;
    A2BBF0Quad m_kEnd;
};
void NiTCBRotKey_Copy(A2BBF0Record* pkDst, const A2BBF0Record* pkSrc);
struct A2BDE0Quaternion
{
    float w;
    float x;
    float y;
    float z;

    bool IsEqual(const A2BDE0Quaternion& kOther) const;
};
struct A2BDE0Key
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
bool A2BDE0KeyEqual(const A2BDE0Key& kA, const A2BDE0Key& kB);
struct A2BDE0BezRotKey : A2BDE0Key
{
    float m_fValueX;
    float m_fValueY;
    float m_fValueZ;
    A2BDE0Quaternion m_kInQuat;
    A2BDE0Quaternion m_kOutQuat;
};
bool BezRotKeyEqual(const A2BDE0BezRotKey& kA, const A2BDE0BezRotKey& kB);
struct TQuat
{
    float w, x, y, z;
    TQuat()
    {}
    TQuat Mul(const TQuat& q) const;
    TQuat operator+(const TQuat& q) const;
    TQuat operator-(const TQuat& q) const;
    static TQuat Log(const TQuat& q);
    static TQuat Exp(const TQuat& q);
};
TQuat Conj(const TQuat& q);
TQuat operator*(float s, const TQuat& q);
struct TCBRotKey
{
    float m_fTime;
    TQuat m_kRotationValue;
    float m_fValueX;
    float m_fValueY;
    float m_fValueZ;
    TQuat m_kOutgoingTangent;
    TQuat m_kIncomingTangent;
    void ComputeTangents(const TCBRotKey& prev, const TCBRotKey& next);
};
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
void __cdecl NiTCBRotKey_FillDerivedVals(Quad64* base, unsigned int count, void* c);
struct S_a2c300_Stream
{
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
__forceinline void S_a2c300_SaveI(NiBinaryStream* i, void* src, unsigned bytes)
{
    unsigned sz = bytes;
    i->BinaryRead(src, bytes, &sz, 1);
}
__forceinline void S_a2c300_Save(S_a2c300_Stream* s, void* src, unsigned bytes)
{
    S_a2c300_SaveI(s->unk24c, src, bytes);
}
struct S_a2c300_Obj
{
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
struct S_a2c390_Stream
{
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
inline void S_a2c390_BinLoad(NiBinaryStream* i, void* dst, unsigned bytes)
{
    unsigned comp = bytes;
    i->BinaryWrite(dst, bytes, &comp, 1);
}
template <class T> inline void S_a2c390_Load(S_a2c390_Stream* s, T& v)
{
    S_a2c390_BinLoad(s->unk250, &v, sizeof(T));
}
struct S_a2c390_Obj
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
void __cdecl LoadObjFields(S_a2c390_Stream* s, S_a2c390_Obj* o);
extern "C" void __cdecl LoadObjFields(void* ctx, void* entry);
struct Entry64
{
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
void __cdecl NiTCBRotKey_SaveToStream(void* ctx, Entry64* entries, unsigned int count);
struct ShapeValues
{
    float initial;
    float start;
    float intermediateA;
    float intermediateB;
    float intermediateC;
    float end;
    float extent;
};
extern "C" float __cdecl func_0x00a42070(float input, float leftStart, float leftExtent, float rightStart,
                                         float rightEnd);
void __cdecl NiTCBFloatKey_Interpolate(float input, const ShapeValues* left, const ShapeValues* right, float* result);
struct Key
{
    float t;
    float v;
    float a;
    float b;
    float c;
    float d;
    float e;
};
// src: GAMEBRYO_LIB 0x00a2c6a0
__declspec(noinline) void __cdecl NiTCBFloatKey_CalculateDVals(Key* k, float a, float b, float c, float d)
{
    k->a = a * c;
    k->b = b * d;
}
void __cdecl NiTCBFloatKey_FillDerivedVals(Key* keys, unsigned int count);
struct S_00a2c9d0_Owner
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
struct FUN_00a2c9d0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void LoadBaseAndMemberValue(S_00a2c9d0_Owner* owner);
    void LoadBaseAndThreeValues(S_00a2c9d0_Owner* owner);
};
struct FUN_00a2ca60_Obj
{
    char _00[8];
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
};
void __cdecl WriteFloatToStream(NiStream* pkStream, FUN_00a2ca60_Obj* pkObj);
void __cdecl Object_WriteKeyFields(NiStream* pkStream, FUN_00a2ca60_Obj* pkObj);
struct KeyframeElement
{
    float time;
    float value;
    float inTangent;
    float outTangent;
    float tension;
    float continuity;
    float bias;
    ~KeyframeElement();
    void LoadBaseAndThreeValues(void* context);
    static void* operator new[](unsigned int bytes)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(bytes);
    }
};
KeyframeElement* __cdecl AllocateKeyframeElements(void* context, unsigned int count);
extern "C" void __cdecl Object_WriteKeyFields(void* a1, void* a2);
void __cdecl NiTCBFloatKey_SaveToStream(void* a1, void* a2, unsigned int count);
struct FUN_00a2cc40_S
{
    unsigned int unk00;
    unsigned char m_04;
};
void SelectByteByThreshold(float f, FUN_00a2cc40_S* a, FUN_00a2cc40_S* b, unsigned char* out);
struct A2CC60Stream;
struct A2CC60Entry
{
    int unk00;
    int unk04;
};
void WriteEnabledFlag(A2CC60Stream* pkStream, A2CC60Entry* pkEntry);
void Object_WriteEnabledFlags(A2CC60Stream* pkStream, A2CC60Entry* pkEntries, unsigned int ItemUpdateArray);
struct Arr8
{
    float f;
    char c;
    ~Arr8()
    {}
    __forceinline static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    __forceinline static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
void* __cdecl AllocateArr8Array(unsigned int count);
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
void SelectPayloadByThreshold(float f, FUN_00a2cf20_Value* a, FUN_00a2cf20_Value* b, FUN_00a2cf20_Payload* out);
struct FUN_00a2d200_arg
{
    unsigned int unk00;
    float m_04;
};
void NiStepFloatKey_Interpolate(float t, FUN_00a2d200_arg* a, FUN_00a2d200_arg* b, float* out);
struct KeyVec
{
    int m_iX;
    int m_iY;
    int m_iZ;
};
struct KeyData
{
    int m_iT;
    KeyVec m_v;
};
struct KeyOut
{
    int m_iX;
    int m_iY;
    int m_iZ;
};
void __cdecl SelectKeyVec(float afBlendWeight, const KeyData* pA, const KeyData* pB, KeyOut* pOut);
extern char* DAT_0109b220;
struct FNVRefObject
{
    virtual void UnusedVirtual();
    virtual void DeleteThis();
    volatile long referenceCount;
};
struct FNVHolder
{
    void* vtable;
    int unk04;
    int unk08;
    FNVRefObject* object;
    char* text;
    void ReleaseReference_00a2dd10();
};
struct FUN_00a351d0_cls
{
    void __thiscall CrossFadeTo(int a, float b, int c, float d, float e);
};
void __stdcall CallFUN_00a351d0(FUN_00a351d0_cls* self, int a, float b, int c, float d, float e);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern unsigned int DAT_011f36a8;
struct ObjA00a2;
extern ObjA00a2* DAT_011f36a4;
extern "C" void __cdecl FUN_00fdad30(void);
int __cdecl FUN_00ec658f(void(__cdecl* pfn)(void));
struct ObjA00a2
{
    long m_uiRefCount;
    virtual void v00();
    virtual void DeleteThis();
};
struct PtrA00a2
{
    ObjA00a2* m_pObject;
};
struct ArrA00a2
{
    void* m_vtbl;
    ObjA00a2** m_ppData;
    unsigned short unk08;
    unsigned short m_usMax;
    unsigned short m_usElementCount;

    void UpdateFields_00a2e680(unsigned int uiIndex, PtrA00a2& pSceneObject);
};
// Target object whose virtual slot 0xE0 (slot 56) is invoked for every entry.
class A30540Target
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
struct A30540Entry
{
    void* unk00;
    void* unk04;
    A30540Target* m_pFlagTarget;
    unsigned char m_uiFilterValue;
};
class FUN_00a30540_cls
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned int m_uiItemCount;
    void* unk10;
    A30540Entry* m_pEntries;
    void NiControllerSequence_DetachInterpolators();
};
extern "C" int __cdecl strcmp(const char* s1, const char* s2);
struct FUN_00a305e0_cls
{
    const char* m_00;

    bool Equals(const char* other);
};
static double DAT_010241b0 = -3.4028234663852886e+38;
static float DAT_01096b8c = -3.4028234663852886e+38f;
struct S_00a385d0_V3
{
    float x, y, z;
    S_00a385d0_V3 Neg() const
    {
        S_00a385d0_V3 r;
        r.x = -x;
        r.y = -y;
        r.z = -z;
        return r;
    }
};
struct S_00a385d0_Q
{
    float a, b, c, d;
};
S_00a385d0_Q* __cdecl FUN_00a6dc00(S_00a385d0_Q* dst, const S_00a385d0_Q* src);
struct S_00a385d0_T
{
    S_00a385d0_V3 pos;
    S_00a385d0_Q rot;
    float scale;
    void InvertTransform(S_00a385d0_T* out);
};
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
#include "../../include/NiMemObject.h"
inline void* __cdecl operator new(unsigned int, void* memory) throw()
{
    return memory;
}
NiFloatInterpolator* __cdecl CreateNiFloatInterpolator();
int __cdecl AreFloatsEqual(const float* pfA, const float* pfB);
// AccumulateAnimSink: dispatch a request to the animation sink found at +0x24c
// of the object passed in, and accumulate the returned count.
struct AnimSink
{
    int m_00;
    int m_04;
    int(__cdecl* m_08)(AnimSink* self, void* ctx, int count, int* out, int flag);
};
class FUN_00a3da20_cls
{
  public:
    void AccumulateAnimSink(int a1);
};
struct FUN_00a3da50_Anim
{
    int m_unk00;
    int m_iArrayLength;
    int m_unk08;
    int(__cdecl* m_pfn)(FUN_00a3da50_Anim* pAnim, int iIndex, int iMode, int* pOut, int iFlag);
};
struct FUN_00a3da50_Owner
{
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
    FUN_00a3da50_Anim* m_pAnim;
};
int __cdecl CallAnimCallback(FUN_00a3da50_Owner* pOwner, int iIndex);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct S_a3dd40_Obj
{
    virtual ~S_a3dd40_Obj();
    virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
struct S_a3dd40_Ptr
{
    S_a3dd40_Obj* m_p;
    S_a3dd40_Ptr& operator=(S_a3dd40_Obj* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = p;
        }
        return *this;
    }
    ~S_a3dd40_Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
};
struct FUN_00a3ca30
{
    virtual ~FUN_00a3ca30() throw();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
extern "C" void __cdecl _NiFree_00aa10f0(void*) throw();
struct FUN_00a3dd40 : FUN_00a3ca30
{
    S_a3dd40_Ptr m_kPointA;
    S_a3dd40_Ptr m_kPointB;
    void* m_p;
    virtual ~FUN_00a3dd40() throw();
};
extern "C" float __cdecl func_0x00a42070(float input, float leftStart, float leftExtent, float rightStart,
                                         float rightEnd);
void __cdecl NiBezFloatKey_Interpolate(float a, const float* b, const float* c, float* out);
struct FloatKey
{
    float time;
    float value;
    ~FloatKey() throw()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
};
void __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int count);
float __cdecl GetValueAtTime(float t, TCBKeyS* keys, int type, unsigned int count, unsigned int stride);
bool __cdecl Object_ConstructObject_00a2a620(float t, TCBKeyS** pKeys, unsigned int* pCount);
struct FUN_00a2ab10_Tail
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
};
struct FUN_00a2ab10_T
{
    float f00;
    FUN_00a2ab10_Tail tail;
};
void __cdecl Runtime_CopyFloatAndTail(FUN_00a2ab10_T* dst, const FUN_00a2ab10_T* src);
struct BezPosKey
{
    float time;
    NiPoint3 pos;
    NiPoint3 in;
    NiPoint3 out;
    NiPoint3 unk28;
    NiPoint3 unk34;
    NiPoint3 unk40;
    ~BezPosKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
void BezSortKeys(BezPosKey* keys, unsigned int count, unsigned int stride);
bool InsertBezPosKey(float t, BezPosKey** pKeys, unsigned int* pCount);
extern "C" double DAT_01011590;
extern "C" double DAT_01021928;
void ComputeTCBKeyTangents(TCBKeyS* keys, unsigned int count, unsigned int stride);
struct Elem00a2dd70
{
    int unk00;
    int unk04;
    FNVHolder holder;
};
struct Dtor00a2dd70
{
    int unk00;
    int unk04;
    FNVHolder holder;

    Dtor00a2dd70* FUN_00a2dd70(unsigned char acFlags);
};

struct Elem48
{
    int unk00;
    float m04, m08, m0C, m10;
    float m14, m18, m1C;
    float m20, m24, m28;
    unsigned char m2C, m2D, m2E, unk2F;
    float m30, m34, m38;
    float m3C, m40, m44;
    Elem48() throw();
    ~Elem48() throw();
    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
};

// @fnv 0x00a29db0
// src: GUESS 0x00a29db0 (confidence: low)
Elem48* __cdecl Runtime_GetIndexedValue_00a29db0(unsigned int count)
{
    return new Elem48[count];
}

struct Elem20
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;

    Elem20();
    ~Elem20()
    {}
    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
};
// @fnv 0x00a2ab40
// src: GUESS 0x00a2ab40 (confidence: low)
void* Object_GetIndexedValue_00a2ab40(unsigned int count)
{
    return new Elem20[count];
}

struct A2ABC0Stream;
struct A2ABC0Key
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;

    A2ABC0Key();
    ~A2ABC0Key()
    {}
    void ProcessState_00a29640(A2ABC0Stream* s);
    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
};
// @fnv 0x00a2abc0
// src: GUESS 0x00a2abc0 (confidence: low)
void* Object_ProcessEntries_00a2abc0(A2ABC0Stream* s, unsigned int count)
{
    A2ABC0Key* p = new A2ABC0Key[count];
    for (unsigned int i = 0; i < count; i++)
        p[i].ProcessState_00a29640(s);
    return p;
}

struct BoolKeyS
{
    float time;
    bool value;
    ~BoolKeyS() throw()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
bool GenInterpBool(float t, BoolKeyS* keys, int type, unsigned int count, unsigned int stride);

// @fnv 0x00a2ccd0
// src: GUESS 0x00a2ccd0 (confidence: low)
bool Runtime_AllocateStorage_00a2ccd0(float fTime, BoolKeyS*& pkKeys, unsigned int& uiNumKeys)
{
    unsigned int uiIndex;
    BoolKeyS* pkOldKeys = pkKeys;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkOldKeys, uiNumKeys, &uiIndex, sizeof(BoolKeyS)))
    {
        BoolKeyS* pkNewKeys = new BoolKeyS[uiNumKeys + 1];
        _memmove(pkNewKeys, pkOldKeys, uiIndex * sizeof(BoolKeyS));
        if (uiNumKeys > uiIndex)
            _memmove(&pkNewKeys[uiIndex + 1], &pkOldKeys[uiIndex], (uiNumKeys - uiIndex) * sizeof(BoolKeyS));
        bool bValue = GenInterpBool(fTime, pkOldKeys, 5, uiNumKeys, sizeof(BoolKeyS));
        BoolKeyS* pkKey = &pkNewKeys[uiIndex];
        pkKey->time = fTime;
        pkKey->value = bValue;
        uiNumKeys++;
        delete[] pkOldKeys;
        pkKeys = pkNewKeys;
        return true;
    }
    return false;
}

struct A28F00Elem
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

    A28F00Elem();
    ~A28F00Elem()
    {}
    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Allocate(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
};

// @fnv 0x00a28f00
// src: COMMUNITY 0x00a28f00
A28F00Elem* __cdecl NiBezRotKey_CreateArray(unsigned int ItemUpdateArray)
{
    return new A28F00Elem[ItemUpdateArray];
}

extern MemoryManager g_memoryManager;

void* _memmove(void* d, const void* s, unsigned int n);
struct TCBKeyS;
bool FindKeyIndex(float t, TCBKeyS* keys, unsigned int count, unsigned int* idx, unsigned int stride);

FUN_00a289b0_Vec4* __cdecl SampleKeyedVec4(FUN_00a289b0_Vec4* out, float t, char* keys, void* arg4, unsigned int count,
                                           unsigned char stride);
struct FNVAnim;
void __cdecl NiBezRotKey_FillDerivedVals(FNVAnim* obj, unsigned int count, unsigned int flag);

// local form of NiQuaternion: 0x00a28f50 needs the empty default ctor and out-of-line scalar ctor; the shared form changes bytes.
struct QuatS
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    QuatS()
    {}
    QuatS(float w, float x, float y, float z) throw();
};

struct TCBRotKeyS
{
    float m_fTime;
    QuatS m_kQuat;
    float m_fValueX;
    float m_fValueY;
    float m_fValueZ;
    float unk20;
    TCBRotKeyS() : m_kQuat(0.0f, 0.0f, 0.0f, 0.0f)
    {}
    ~TCBRotKeyS()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
typedef TCBRotKeyS RotKeyS;
// @fnv 0x00a28f50
// src: COMMUNITY 0x00a28f50
bool NiBezRotKey_Insert(float t, RotKeyS*& pkKeys, unsigned int& uiNumKeys)
{
    TCBRotKeyS* pkOld = (TCBRotKeyS*)pkKeys;
    unsigned int uiInsertAt;
    if (FindKeyIndex(t, (TCBKeyS*)pkOld, uiNumKeys, &uiInsertAt, sizeof(TCBRotKeyS)))
    {
        TCBRotKeyS* pkNewKeys = new TCBRotKeyS[uiNumKeys + 1];
        _memmove(pkNewKeys, pkOld, uiInsertAt * sizeof(TCBRotKeyS));
        if (uiNumKeys > uiInsertAt)
            _memmove(&pkNewKeys[uiInsertAt + 1], &pkOld[uiInsertAt], (uiNumKeys - uiInsertAt) * sizeof(TCBRotKeyS));

        QuatS kQuat;
        SampleKeyedVec4((FUN_00a289b0_Vec4*)&kQuat, t, (char*)pkOld, (void*)2, uiNumKeys, sizeof(TCBRotKeyS));
        TCBRotKeyS* pkNewKey = &pkNewKeys[uiInsertAt];
        pkNewKey->m_fTime = t;
        pkNewKey->m_kQuat = kQuat;
        uiNumKeys++;
        delete[] pkOld;
        pkKeys = pkNewKeys;
        NiBezRotKey_FillDerivedVals((FNVAnim*)pkNewKeys, uiNumKeys, sizeof(TCBRotKeyS));
        return true;
    }
    return false;
}

struct A290A0Stream;
struct A290A0Key
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
    A290A0Key();
    ~A290A0Key();
    void __thiscall ProcessState_00a29640(A290A0Stream* pkStream);
    static void* operator new[](unsigned int uiSize)
    {
        return DAT_011f6238.Allocate(uiSize);
    }
};

// @fnv 0x00a290a0
// src: COMMUNITY 0x00a290a0
A290A0Key* __cdecl NiBezRotKey_CreateFromStream(A290A0Stream* pkStream, unsigned int ItemUpdateArray)
{
    A290A0Key* pkKeys = new A290A0Key[ItemUpdateArray];
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        pkKeys[i].ProcessState_00a29640(pkStream);
    }
    return pkKeys;
}

struct RotKeyQuat
{
    float w;
    float x;
    float y;
    float z;
};

struct TimedRotationKey : AnimKeyBase
{
    RotKeyQuat m_kRotationValue;
    TimedRotationKey();
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

void NiColorA_K_InterpolateColorClampedToKeys(RotKeyQuat* pkResult, float fTime, TimedRotationKey* pkKeys, int eType, unsigned int uiNumKeys,
                  unsigned int uiKeySize);

// @fnv 0x00a2a390
// src: GUESS 0x00a2a390 (confidence: low)
bool Runtime_AllocateStorage_00a2a390(float fTime, TimedRotationKey*& pkKeys, unsigned int& uiNumKeys)
{
    TimedRotationKey* pkOld = pkKeys;
    unsigned int uiIndex;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkOld, uiNumKeys, &uiIndex, sizeof(TimedRotationKey)))
    {
        TimedRotationKey* pkNew = new TimedRotationKey[uiNumKeys + 1];
        _memmove(pkNew, pkOld, uiIndex * sizeof(TimedRotationKey));
        if (uiNumKeys > uiIndex)
            _memmove(&pkNew[uiIndex + 1], &pkOld[uiIndex], (uiNumKeys - uiIndex) * sizeof(TimedRotationKey));

        RotKeyQuat kQuat;
        NiColorA_K_InterpolateColorClampedToKeys(&kQuat, fTime, pkOld, 1, uiNumKeys, sizeof(TimedRotationKey));
        TimedRotationKey* pkKey = &pkNew[uiIndex];
        pkKey->time = fTime;
        pkKey->m_kRotationValue = kQuat;
        uiNumKeys++;

        delete[] pkOld;
        pkKeys = pkNew;
        return true;
    }
    return false;
}

struct ColorKeyValue
{
    float r;
    float g;
    float b;
    float a;
};
struct ColorKey
{
    float m_fTime;
    ColorKeyValue m_kValue;
    ColorKey();  // FUN_00a2bdb0
    ~ColorKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};
ColorKeyValue* __cdecl SampleKeyedVec4(ColorKeyValue* pkOut, float fTime, ColorKey* pkKeys, int iType,
                                       unsigned int ItemUpdateArray, unsigned char ucStride);
void __cdecl NiRotKey_FillDerivedVals(ColorKey* pkKeys, unsigned int ItemUpdateArray, unsigned int uiStride);

// @fnv 0x00a2ac30
// src: GUESS 0x00a2ac30 (confidence: low)
bool NiRotKey_FillDerivedVals_AllocateStorage_00a2ac30(float fTime, ColorKey** ppkKeys, unsigned int* puiNumKeys)
{
    ColorKey* pkKeys = *ppkKeys;
    unsigned int uiIndex;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkKeys, *puiNumKeys, &uiIndex, sizeof(ColorKey)))
    {
        ColorKey* pkNew = new ColorKey[*puiNumKeys + 1];
        _memmove(pkNew, pkKeys, uiIndex * sizeof(ColorKey));
        if (*puiNumKeys > uiIndex)
            _memmove(&pkNew[uiIndex + 1], &pkKeys[uiIndex], (*puiNumKeys - uiIndex) * sizeof(ColorKey));
        ColorKeyValue kValue;
        SampleKeyedVec4(&kValue, fTime, pkKeys, 1, *puiNumKeys, sizeof(ColorKey));
        ColorKey& kKey = pkNew[uiIndex];
        kKey.m_fTime = fTime;
        kKey.m_kValue = kValue;
        ++*puiNumKeys;
        delete[] pkKeys;
        *ppkKeys = pkNew;
        NiRotKey_FillDerivedVals(pkNew, *puiNumKeys, sizeof(ColorKey));
        return true;
    }
    return false;
}

struct QuatA
{
    float w, x, y, z;
    QuatA()
    {}
    void Set(float, float, float, float);
};
struct FUN_00a2bdb0
{
    float time;
    QuatA value;
    float tension, continuity, bias;
    QuatA a;
    QuatA b;
    FUN_00a2bdb0()
    {
        value.Set(0.0f, 0.0f, 0.0f, 0.0f);
    }
    ~FUN_00a2bdb0()
    {}
    static void* operator new[](unsigned n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned)
    {
        g_memoryManager.Deallocate(p);
    }
};
QuatA __cdecl SampleKeyedVec4(float, FUN_00a2bdb0*, int, unsigned, unsigned);
void __cdecl NiTCBRotKey_FillDerivedVals(FUN_00a2bdb0*, unsigned, unsigned);
// @fnv 0x00a2c1b0
// src: GUESS 0x00a2c1b0 (confidence: low)
bool __cdecl NiTCBRotKey_FillDerivedVals_AllocateStorage_00a2c1b0(float time, FUN_00a2bdb0** keys, unsigned* count)
{
    FUN_00a2bdb0* oldKeys = *keys;
    unsigned index;
    if (FindKeyIndex(time, (TCBKeyS*)oldKeys, *count, &index, 64))
    {
        FUN_00a2bdb0* newKeys = new FUN_00a2bdb0[*count + 1];
        _memmove(newKeys, oldKeys, index * sizeof(FUN_00a2bdb0));
        if (*count > index)
            _memmove(newKeys + index + 1, oldKeys + index, (*count - index) * sizeof(FUN_00a2bdb0));
        QuatA value = SampleKeyedVec4(time, oldKeys, 3, *count, 64);
        FUN_00a2bdb0& key = newKeys[index];
        key.time = time;
        key.value = value;
        key.bias = key.continuity = key.tension = 0.0f;
        ++*count;
        delete[] oldKeys;
        *keys = newKeys;
        NiTCBRotKey_FillDerivedVals(newKeys, *count, 64);
        return true;
    }
    return false;
}

namespace fnv_00a2c420 {
namespace na2c {
struct Alloc
{
    void* Game_DoHeapAlloc(unsigned int size);
};
}
struct FUN_00a2bdb0
{
    int d[16];
    FUN_00a2bdb0() throw();
    ~FUN_00a2bdb0() throw()
    {}
    static void* operator new[](unsigned int aSize)
    {
        return ((na2c::Alloc*)&DAT_011f6238)->Game_DoHeapAlloc(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
    void SaveExtraFields(S_a2c300_Stream* s);
};

// @fnv 0x00a2c420
// src: GUESS 0x00a2c420 (confidence: low)
FUN_00a2bdb0* __cdecl Object_ProcessEntries_00a2c420(S_a2c300_Stream* s, unsigned int count)
{
    FUN_00a2bdb0* arr = new FUN_00a2bdb0[count];
    for (unsigned int i = 0; i < count; i++)
        arr[i].SaveExtraFields(s);
    return arr;
}
}  // namespace fnv_00a2c420

struct ScalarKeyA2
{
    float time, value, tension, bias, continuity, inTangent, outTangent;
    ~ScalarKeyA2() throw()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
bool FindKeyIndex(float, ScalarKeyA2*, unsigned int, unsigned int*, unsigned int);
float GetValueAtTime(float, ScalarKeyA2*, int, unsigned int, unsigned int);
void NiTCBFloatKey_FillDerivedVals(ScalarKeyA2*, unsigned int, unsigned int);
// @fnv 0x00a2c890
// src: GUESS 0x00a2c890 (confidence: low)
bool NiTCBFloatKey_FillDerivedVals_AllocateStorage_00a2c890(float time, ScalarKeyA2** keys, unsigned int* count)
{
    ScalarKeyA2* old = *keys;
    unsigned int index;
    if (FindKeyIndex(time, old, *count, &index, 28))
    {
        ScalarKeyA2* result = new ScalarKeyA2[*count + 1];
        _memmove(result, old, index * sizeof(ScalarKeyA2));
        if (*count > index)
            _memmove(result + index + 1, old + index, (*count - index) * sizeof(ScalarKeyA2));
        float value = GetValueAtTime(time, old, 3, *count, 28);
        ScalarKeyA2& key = result[index];
        key.time = time;
        key.value = value;
        key.continuity = key.bias = key.tension = 0.0f;
        ++*count;
        delete[] old;
        *keys = result;
        NiTCBFloatKey_FillDerivedVals(result, *count, 28);
        return true;
    }
    return false;
}

struct A2CF60Elem
{
    float unk00;
    float x;
    float y;
    float z;
    float w;

    A2CF60Elem();
    ~A2CF60Elem()
    {}
    void ProcessState_00a29640(void* apStream);

    static void* operator new[](unsigned int auiSize)
    {
        return DAT_011f6238.Allocate(auiSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Free(apBlock);
    }
};

// @fnv 0x00a2cf60
// src: GUESS 0x00a2cf60 (confidence: low)
A2CF60Elem* __cdecl Object_ProcessEntries_00a2cf60(void* apStream, unsigned int auiCount)
{
    A2CF60Elem* pkItems = new A2CF60Elem[auiCount];
    for (unsigned int i = 0; i < auiCount; i++)
        pkItems[i].ProcessState_00a29640(apStream);
    return pkItems;
}

namespace fnv_00a2d000 {
struct QuatS
{
    float w, x, y, z;
};
struct QuatR : QuatS
{
    QuatR()
    {}
};

struct QuatKey
{
    float time;
    QuatS q;
    QuatKey()
    {
        q.w = 0.0f;
        q.x = 0.0f;
        q.y = 0.0f;
        q.z = 0.0f;
    }
    ~QuatKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};

QuatR NiColorA_K_InterpolateColorClampedToKeys(float t, QuatKey* keys, int type, unsigned int count, unsigned int stride);

// @fnv 0x00a2d000
// src: GUESS 0x00a2d000 (confidence: low)
bool Object_ProcessAndReturnValue_00a2d000(float t, QuatKey** pKeys, unsigned int* pCount)
{
    QuatKey* keys = *pKeys;
    unsigned int idx;
    if (FindKeyIndex(t, (TCBKeyS*)keys, *pCount, &idx, sizeof(QuatKey)))
    {
        unsigned int count = *pCount + 1;
        QuatKey* newKeys = new QuatKey[count];
        _memmove(newKeys, keys, idx * sizeof(QuatKey));
        if (*pCount > idx)
            _memmove(&newKeys[idx + 1], &keys[idx], (*pCount - idx) * sizeof(QuatKey));
        QuatR q = NiColorA_K_InterpolateColorClampedToKeys(t, keys, 5, *pCount, sizeof(QuatKey));
        QuatKey& key = newKeys[idx];
        key.time = t;
        key.q = q;
        ++*pCount;
        delete[] keys;
        *pKeys = newKeys;
        return true;
    }
    return false;
}
}  // namespace fnv_00a2d000

// local form of NiQuaternion: 0x00a2d6c0 needs an empty inline default ctor; the shared ctor changes bytes.
struct A2D6C0Quaternion
{
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;

    A2D6C0Quaternion()
    {}
};

struct A2D6C0RotKey
{
    float m_fTime;
    A2D6C0Quaternion m_kRotationValue;

    A2D6C0RotKey();
    ~A2D6C0RotKey()
    {}
    static void* operator new[](unsigned int n)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(n);
    }
    static void operator delete[](void* p, unsigned int)
    {
        g_memoryManager.Deallocate(p);
    }
};

A2D6C0Quaternion __cdecl SampleKeyedVec4(float fTime, A2D6C0RotKey* pkKeys, int eType, unsigned int uiNumKeys,
                                         unsigned int uiKeySize);
void __cdecl NiRotKey_FillDerivedVals(A2D6C0RotKey* pkKeys, unsigned int uiNumKeys, unsigned int uiKeySize);

// @fnv 0x00a2d6c0
// src: GUESS 0x00a2d6c0 (confidence: low)
bool __cdecl Object_ProcessAndReturnValue_00a2d6c0(float fTime, A2D6C0RotKey*& pkKeys, unsigned int& uiNumKeys)
{
    A2D6C0RotKey* pkOld = pkKeys;
    unsigned int uiInsert;
    if (FindKeyIndex(fTime, (TCBKeyS*)pkOld, uiNumKeys, &uiInsert, sizeof(A2D6C0RotKey)))
    {
        A2D6C0RotKey* pkNew;
        pkNew = new A2D6C0RotKey[uiNumKeys + 1];
        _memmove(pkNew, pkOld, uiInsert * sizeof(A2D6C0RotKey));
        if (uiNumKeys > uiInsert)
            _memmove(&pkNew[uiInsert + 1], &pkOld[uiInsert], (uiNumKeys - uiInsert) * sizeof(A2D6C0RotKey));
        A2D6C0Quaternion kQuat = SampleKeyedVec4(fTime, pkOld, 5, uiNumKeys, sizeof(A2D6C0RotKey));
        A2D6C0RotKey* pkKey = &pkNew[uiInsert];
        pkKey->m_fTime = fTime;
        pkKey->m_kRotationValue = kQuat;
        uiNumKeys++;
        delete[] pkOld;
        pkKeys = pkNew;
        NiRotKey_FillDerivedVals(pkNew, uiNumKeys, sizeof(A2D6C0RotKey));
        return true;
    }
    return false;
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}

// Preserve the inline sequence-pointer operations formerly supplied by layout_support.h.
template <> inline NiPointer<NiControllerSequence>::NiPointer(const NiPointer<NiControllerSequence>& other)
{
    m_pObject = other.m_pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <> inline NiPointer<NiControllerSequence>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <> inline NiPointer<NiControllerSequence>::operator NiControllerSequence*() const
{
    return m_pObject;
}
template <> inline NiControllerSequence* NiPointer<NiControllerSequence>::operator->() const
{
    return m_pObject;
}
template <> inline NiPointer<NiControllerSequence>& NiPointer<NiControllerSequence>::operator=(NiControllerSequence* object)
{
    if (m_pObject != object)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
template <> inline NiPointer<NiControllerSequence>& NiPointer<NiControllerSequence>::operator=(const NiPointer<NiControllerSequence>& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = other.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}



// RemoveAtAndFill at 0x00a47540 does not alias the caller's sequence references.
template <> __declspec(noalias) NiPointer<NiControllerSequence>
NiTArray<NiPointer<NiControllerSequence>, NiTNewInterface<NiPointer<NiControllerSequence> > >::RemoveAtAndFill(unsigned int uiIndex);

// Gamebryo container accessors used inline by RemoveSequence.
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{
    return m_usSize;
}
template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int uiIndex)
{
    return m_pBase[uiIndex];
}
template <class T, class TAlloc> inline unsigned int NiTSet<T, TAlloc>::GetSize() const
{
    return m_uiUsed;
}
template <class T, class TAlloc> inline T& NiTSet<T, TAlloc>::GetAt(unsigned int uiIndex)
{
    return m_pBase[uiIndex];
}
template <class T, class TAlloc> inline void NiTSet<T, TAlloc>::RemoveAt(unsigned int uiIndex)
{
    m_pBase[uiIndex] = m_pBase[--m_uiUsed];
}

// Gamebryo map iteration bodies used inline by RemoveSequence.
template <class TAlloc, class TKEY, class TVAL>
inline void* NiTMapBase<TAlloc, TKEY, TVAL>::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; i++)
    {
        if (m_ppkHashTable[i])
            return m_ppkHashTable[i];
    }
    return 0;
}

template <class TAlloc, class TKEY, class TVAL>
inline void NiTMapBase<TAlloc, TKEY, TVAL>::GetNext(void*& pos, TKEY& key, TVAL& val) const
{
    NiTMapItem<TKEY, TVAL>* pkItem = (NiTMapItem<TKEY, TVAL>*)pos;
    key = pkItem->m_key;
    val = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        pos = pkItem->m_pkNext;
        return;
    }
    unsigned int i = KeyToHashIndex(pkItem->m_key);
    for (++i; i < m_uiHashSize; i++)
    {
        pkItem = m_ppkHashTable[i];
        if (pkItem)
        {
            pos = pkItem;
            return;
        }
    }
    pos = 0;
}

class SeqMgrE2E7
{
  public:
    virtual ~SeqMgrE2E7();
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
    NiTObjectArray<NiPointer<NiControllerSequence> > m_kSequences;
    NiTPrimitiveSet<NiControllerSequence*> m_kPlayingSequences;
    // RTTI vftable 0x01096260, stored by the manager ctor/dtor.
    NiTStringPointerMap<NiControllerSequence*> m_kPointerMap;

    void NiControllerManager_RemoveSequence(NiControllerSequence* pkSequence, NiPointer<NiControllerSequence>& spOut);
};

// @fnv 0x00a2e7d0
// src: COMMUNITY 0x00a2e7d0
void SeqMgrE2E7::NiControllerManager_RemoveSequence(NiControllerSequence* pkSequence, NiPointer<NiControllerSequence>& spOut)
{
    for (unsigned int ui = 0; ui < m_kSequences.GetSize(); ui++)
    {
        NiPointer<NiControllerSequence> pListSequence = m_kSequences.GetAt(ui);
        if (pListSequence == pkSequence)
        {
            m_kSequences.RemoveAtAndFill(ui);

            void* kIter = m_kPointerMap.GetFirstPos();
            while (kIter)
            {
                const char* pcName;
                NiControllerSequence* pkSeq;
                m_kPointerMap.GetNext(kIter, pcName, pkSeq);
                if (pkSeq == pkSequence)
                {
                    m_kPointerMap.RemoveAt(pcName);
                    break;
                }
            }

            for (unsigned int uj = 0; uj < m_kPlayingSequences.GetSize(); uj++)
            {
                if (m_kPlayingSequences.GetAt(uj) == pkSequence)
                    m_kPlayingSequences.RemoveAt(uj);
            }

            pListSequence->ReleaseItems();
            pListSequence->m_pkOwnerManager = 0;
            spOut = pListSequence;
            return;
        }
    }
    spOut = 0;
}
