#define FNV64_HKENUM_INLINE_BODIES
#include "../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/staging/blk_00e40000_o2_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e40000_o2_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/staging/blk_00e40000_o2_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00e40000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv_asm_helpers.h"
#include "../../include/hkpConstraintInstance.h"
#include "../../include/hkpConstraintData.h"
#include "../../include/Actor.h"
#include "../../include/hkVector4.h"
#include "../../include/hkMatrix3.h"
#include "../../include/CodeInfo.h"
#include "../../include/hkVector4.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkStackMemory.h"
#include "../../include/V4.h"
#include "../../include/hkSimdReal.h"
#include "../../include/hkAabb.h"
#include "../../include/hkBool.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkQsTransform.h"
#include "../../include/hkQuaternion.h"
#include "../../include/hkRotation.h"
#include "../../include/hkTransform.h"
#include "../../include/hkpMoppCode.h"
#include "../../include/hkpRemoveTerminalsMoppModifier2.h"
#include "../../include/hkpVehicleFrictionDescription.h"
#include "../../include/hkpVehicleFrictionStatus.h"

__forceinline hkVector4& hkMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}

__forceinline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}

// src/staging/blk_00e40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
struct FUN_00e428f0_class {
    void Remove(void*);
    void hkpVehicleCastBatchingManager_removeVehicle(void* p);
};
int __cdecl hkpVehicleCastBatchingManager_getStandardFilterSize(int pObject);
extern "C" void __cdecl FUN_00cb0a60();
struct FUN_00e4e400_class {
    FUN_00e4e400_class* __thiscall hkaAnnotationTrack_hkaAnnotationTrack();
};
void Object_UpdateFields_00e52860(const float* src, float* dst);
void Runtime_UpdateState_00e52ef0(const float* src, float* dst);
struct FUN_00e58780_Class {
    int* GetElementPtr(int a, int b);
};
struct FUN_00e587c0_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    float GetFloatAt(int idx, int base);
};
struct GlobalObjectO2_00d472a0 { int x; };
GlobalObjectO2_00d472a0 g_0126e600;
void __stdcall FindResourceWithExpectedName(int, GlobalObjectO2_00d472a0*);
void __stdcall Runtime_ForwardCall_00e5c5b0(int a);
extern "C" void __stdcall FindResourceWithExpectedName(int, int);
struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c5f0;
void __stdcall Runtime_ForwardCall_00e5c5f0(int aiValue);
struct FUN_00e459c0_class {
    void SetBitMaskFlags(int a, int b);
};
struct FUN_00e45a10_class {
    void __thiscall ClearFlags(int a, int b);
};
struct FUN_00e587b0_Class {
    int* __thiscall GetElementAddress_00e587b0(int idx);
};
struct FUN_00e58880_Class {
    float GetIndexedValue_00e58880(int offset);
};
int __cdecl Factorial(int count);
extern const float runtimeFloatSettingDefault132;
extern const float runtimeFloatSettingDefault255;
extern const float g_011c7344_arg1;
extern int DAT_010e62a4;
struct FUN_00e44280_struct {
    int* m_00;
    unsigned short m_06;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00e44280_struct* InitializeDefaults();
};
struct FUN_00e407d0_class {
    void SetSlotValue(int idx, char b);
};
struct FUN_00e426f0_class {
    unsigned short m_00;
    unsigned short m_02;
    unsigned short m_04;
    unsigned short m_06;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
    unsigned short m_10;
    unsigned short m_12;
    unsigned short m_14;
    void AddObject(void* p);
    void AddByteFromObject(void* p);
};
struct FUN_00e61480_class {
    void hkxMeshSection_collectVertexPositions(int);
};
struct FUN_00e4ab50_class {
    int m_00;
    int m_04;
    int* m_08;
    int m_0c;
    void __thiscall ApplyToAll(int a);
};
extern int DAT_010ec1fc;
struct FUN_00cb0a70 {
    void m(int);
};
struct FUN_00e4af80 {
    int vtbl;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e4af80* Set(int arg);
};
struct FUN_00e58b10_class {
    void FillWithValue(float* out);
    void hkaSparseLSQMatrix_float_MultiplyAdd(int a, int b, int c);
    void hkaSparseLSQMatrix_float_Multiply(int a, int b, int c);
};
extern const char* const g_0126c5f0_arg1;
void __stdcall FindResourceWithExpectedName(int, int);
void __stdcall Runtime_ForwardCall_00e5c5d0(int aiValue);
struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126eb10;
void __stdcall FindResourceWithExpectedName(int a, GlobalObjectO2_00d472a0* b);
void __stdcall Runtime_ForwardCall_00e5c630(int aiValue);
struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126eac8;
void __stdcall FindResourceWithExpectedName(int, GlobalObjectO2_00d472a0*);
void __stdcall CallWithGlobalObject(int aiValue);
struct FUN_00e406d0_cls
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
    int unk40;
    float* m_44;
    int unk48;
    int unk4C;
    float* m_50;
    void ClampBoundsAt(int index, float value);
};
struct HolderStub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};
HolderStub* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize);
struct ValueArray {
    unsigned int* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};
struct FUN_00e41db0_cls {
    int unk00;
    int unk04;
    ValueArray m_08;
    void AppendValue(unsigned int value);
};
class BE41DF0ReferencedObject {
public:
    BE41DF0ReferencedObject() throw() : m_sReferenceCount(1) {}
    virtual ~BE41DF0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
template <class T>
struct BE41DF0Array {
    BE41DF0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class FUN_00e41df0_cls : public BE41DF0ReferencedObject {
public:
    FUN_00e41df0_cls() throw();
    virtual ~FUN_00e41df0_cls();

    BE41DF0Array<void*> m_kEntries;
};
// FUN_00e42650: iterate an array of listener objects and notify each one.
struct EventListener {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a);
};
struct FUN_00e42650_cls {
    int m_00;
    int m_04;
    EventListener** m_08;
    int m_0c;

    void hkpVehicleManager_addToWorld(int a);
};
struct FUN_00e42680_Item {
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
};
struct FUN_00e42680_cls {
    int m_00;
    int m_04;
    FUN_00e42680_Item** m_08;
    int m_0c;

    void CallItemsVirtual();
};
extern "C" int DAT_010e5e9c;
struct FUN_00e43ac0_cls {
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    float m_08;
    float m_0c;
    float m_10;
    FUN_00e43ac0_cls();
};
extern double DAT_010ebf20;
extern double DAT_010ebf18;
extern double DAT_01012638;
extern double DAT_0101ff48;
float __cdecl ComputeScaledRatio(float param_1, float afDivisor, float afValue, float afScale);
extern "C" int DAT_010e5ff4;
struct FUN_00e43f30_cls {
    void* volatile m_00;
    unsigned short m_04;
    volatile unsigned short m_06;
    volatile float m_08;
    volatile float m_0c;
    volatile float m_10;
    volatile float m_14;
    volatile float m_18;
    volatile int m_1c;
    volatile int m_20;
    volatile unsigned int m_24;
    volatile int m_28;
    volatile int m_2c;
    volatile unsigned int m_30;
    FUN_00e43f30_cls();
};
class BE468B0Base {
public:
    virtual ~BE468B0Base();

    int m_iRefCount;
};
class BE468B0InterfaceA {
public:
    virtual void OnA();
};
class BE468B0InterfaceB {
public:
    virtual void OnB();
};
class BE468B0InterfaceC {
public:
    virtual void OnC();
};
class BE468B0InterfaceD {
public:
    virtual void OnD();
};
class BE468B0Shape : public BE468B0Base, public BE468B0InterfaceA, public BE468B0InterfaceB,
    public BE468B0InterfaceC, public BE468B0InterfaceD {
public:
    BE468B0Shape();
    virtual ~BE468B0Shape();

    int m_iFirst;
    int m_iSecond;
    int m_iEnabled;
    int unk24;
    int unk28;
    int unk2C;
};
class BE468B0Listener {
public:
    virtual void OnEvent();
};
template <class T>
class BE468B0Array {
public:
    BE468B0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class FUN_00e468b0_cls : public BE468B0Shape, public BE468B0Listener {
public:
    FUN_00e468b0_cls();
    virtual ~FUN_00e468b0_cls();
    virtual void OnA();
    virtual void OnB();
    virtual void OnC();
    virtual void OnD();
    virtual void OnEvent();

    BE468B0Array<int> m_kEntries;
};
struct S_e49fe0_B0 { virtual void d0(); int unk4; };
struct S_e49fe0_B8 { virtual void d8(); };
struct S_e49fe0_Bc { virtual void dc(); };
struct S_e49fe0_B10 { virtual void d10(); };
struct S_e49fe0_B14 { virtual void d14(); };
struct FUN_00cbfba0 : S_e49fe0_B0, S_e49fe0_B8, S_e49fe0_Bc, S_e49fe0_B10, S_e49fe0_B14 {
    FUN_00cbfba0();
};
struct S_e49fe0_Arr {
    int m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_e49fe0_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000) {}
};
struct FUN_00e49fe0 : FUN_00cbfba0 {
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S_e49fe0_Arr arr;
    FUN_00e49fe0();
    virtual void d0();
    virtual void d8();
    virtual void dc();
    virtual void d10();
    virtual void d14();
};
struct E4AAA0Allocator;
void __cdecl hkArrayUtil__reserve(E4AAA0Allocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl hkMemUtil_memMove(void* dst, const void* src, unsigned int nbytes);
struct E4AAA0Element {
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};
static __forceinline void E4AAA0Array_reserve(hkArrayBase<E4AAA0Element>& self, E4AAA0Allocator& alloc, int n);

static __forceinline void E4AAA0Array_reserve(hkArrayBase<E4AAA0Element>& self, E4AAA0Allocator& alloc, int n)
{
        const int cap = self.getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, (&self), newSize, sizeof(E4AAA0Element));
        }
    }
class E4AE50ReferencedObject {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    E4AE50ReferencedObject() { m_sReferenceCount = 1; }
    virtual ~E4AE50ReferencedObject() {}
};
template <class T>
class E4AE50Array {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E4AE50Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};
class FUN_00e4ae50 : public E4AE50ReferencedObject {
public:
    E4AE50Array<void*> m_entries;

    FUN_00e4ae50();
    virtual ~FUN_00e4ae50();
};
// FUN_00e4ae80 (11 bytes)
//
//   00e4ae80  8b c1                    mov eax, ecx
//   00e4ae82  c7 00 ec c1 0e 01        mov dword ptr [eax], 0x010ec1ec
//   00e4ae88  c2 04 00                 ret 4
//
// This is a CONSTRUCTOR of the class whose vftable lives at 0x010ec1ec
// (hkxMaterialShaderSet - see tools/pe.py rtti 0x010ec1ec).  A constructor
// returns `this` in EAX, so `this` is live-out in EAX and MSVC emits the vptr
// store through EAX (a hand written `this->m_vtbl = ...` would instead give
// `mov eax,OFFSET sym / mov [ecx],eax`).  The single 4-byte stack argument is
// unused, which is why the epilogue is `ret 4`.
//
// The class is stand-in only: it needs one virtual so that the compiler emits
// a vftable, and the vftable slot points at the (undefined) virtual, so the
// only defined function symbol in this translation unit is the constructor.
struct FUN_00e4ae80_class {
    FUN_00e4ae80_class(int flags);
    virtual void vfunc_00();
};
// add ecx,0x14; jmp FUN_00cb0c10 : the derived override forwards to the secondary base's
// virtual, so `this` is moved forward by the size of the primary base (vptr + 4 ints = 0x14)
// before the tail jump to the secondary base's implementation.
struct ThunkPrimary
{
    virtual void ForwardCall_00e4af50();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct ThunkSecondary
{
    virtual void UpdateState_00cb0c10();
};
struct ThunkDerived : ThunkPrimary, ThunkSecondary
{
    ThunkDerived();
    virtual void ForwardCall_00e4af50();
};
ThunkDerived::ThunkDerived()
{
}
struct S_00e4af60_helper {
    void FUN_00cb0a60();
};
struct S_00e4af60_class {
    void* unk00;
    short unk04;
    short unk06;
    void* unk08;
    int unk0c;
    int unk10;
    S_00e4af60_helper unk14;

    S_00e4af60_class* InitializeFields_00e4af60();
};
extern int DAT_010ec1fc;
void __cdecl AccumulateNeighborSum(float k, const float* src, float* dst, int n);
extern float DAT_0102295c;
extern float DAT_0101622c;
void __cdecl DeinterleaveFloats(float* a, float* b, unsigned int n);
void __cdecl AccumulateNeighborSum(float c, float* a, float* b, unsigned int n);
void __cdecl hkUpdateReflect(float c, float* a, float* b, unsigned int n);
void __cdecl _hkWaveletTransform(float* afValues, unsigned int n);
struct PackedFormat {
    unsigned char bits;
    unsigned char rawCount;
    unsigned short unk02;
    float range;
    float minimum;
};
void _hkQuantizeReal(const float* afSource, unsigned int count, const PackedFormat* format, unsigned char* pucDest);
void __cdecl PackFourFloatsToNibbles(const float* afValues, unsigned char* aucPacked);
extern const float g_x;
float __cdecl Object_GetGlobalValue_00e52f40();
extern const float g_010ec960;
float __cdecl Runtime_GetField010ec960();
extern const float g_010af2f0;
float __cdecl Object_GetGlobalValue_00e52f60();
extern const float g_010ec964;
float __cdecl Runtime_GetField010ec964();
extern const float DAT_010ec968;
float __cdecl Object_GetDAT_010ec968_00e52f80();
extern float DAT_0104da4c;
float __cdecl Runtime_GetDAT0104da4c(void);
void __cdecl SwapBytes(void* pData);
inline void SwapByte(unsigned char& left, unsigned char& right)
{
    unsigned char temporary = left;
    left = right;
    right = temporary;
}
void __cdecl _handleEndianSignedQuaternion48(unsigned char* bytes);
extern "C" void _ReadWriteBarrier(void);
void __cdecl _handleEndianSignedQuaternion128(unsigned char* pucBuffer);

struct E53230Color {
    float r;
    float g;
    float b;
    float a;

    E53230Color& DivideByScalar(float fScalar);
};

struct S_e53300_Vec;
struct S_e53300_Vec {
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    S_e53300_Vec& FUN_00e53200(float f);
    S_e53300_Vec ScaleCopy(float f);
};
struct Quad4 {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    Quad4* Eval(float t);
};
class FUN_00e53350_cls : public Quad4 {
public:
    Quad4 EvalCopy(float t);
};
struct SpawnedObject {
    void Method(float* pOut, float f);
};
float* __cdecl Object_ScaleCopy_Thunk(float* pOut, float fValue, SpawnedObject* pObj);
// Thin cdecl wrapper: forwards its first argument and a float to a
// thiscall method of the object given as the third argument, then hands
// the first argument back to the caller.
struct FUN_00e533c0_cls {
    void SetValue(float* pOut, float fValue);
};
float* __cdecl SetValueAndReturn(float* pOut, float fValue, FUN_00e533c0_cls* pObj);
double __cdecl FUN_00ec6940(double value);
struct FourComponentVector {
    float x, y, z, w;
    __declspec(noinline) FourComponentVector(float a, float b, float c, float d);
    FourComponentVector hkaNURBS_Point_floor() const;
};
FourComponentVector::FourComponentVector(float a, float b, float c, float d)
    : x(a), y(b), z(c), w(d) {}
struct FUN_00e53580_cls {
    float GetIndexedValue_00e53580(int idx);
};
struct S_00e53590_Foo {
    int* __thiscall GetElementAddress_00e53590(int index);
};
struct Vec4f {
    float x;
    float y;
    float z;
    float w;
    Vec4f(float a, float b, float c, float d);
    float operator[](int i) const;
    float& operator[](int i);
};
__declspec(noinline) Vec4f::Vec4f(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}
__declspec(noinline) float Vec4f::operator[](int i) const
{
    return (&x)[i];
}
__declspec(noinline) float& Vec4f::operator[](int i)
{
    return (&x)[i];
}
Vec4f hkaNURBS_Point_Min(const Vec4f& a, const Vec4f& b);
int __cdecl FindFloatInterval(int aiLeft, int aiRight, float value, float** pp);
void __cdecl ComputeBasisFunctions(int span, float u, int degree, float** knots, float* basis);
int __cdecl FindInsertIndex(float value, float **table, int count);
int __cdecl CountRuns(float** apValues, int aiCount);
bool* __cdecl IsSampleBoundary(bool* result, int index, float** samples, int endIndex);
int __cdecl hkaNURBS_MinIndex(float **apValues, int count);
void __cdecl hkaNURBS_Point_Dot(int a, int b);
struct FUN_00e54ad0_cls
{
    int unk00;
    void EvaluateSelfDotProduct();
};
// The two callees below are unnamed in the binary's symbol table; they bind by position.
extern void __cdecl helper_before();
extern double __cdecl helper_value();
float __cdecl GetHelperValueAsFloat();
class FUN_00e54b00_cls
{
public:
    float GetHelperValueAsFloat();
    void EvalCopy(int a, float b);
    int hkaNURBS_Point_normalize(int p);
};
struct FUN_00e54b20_out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct FUN_00e54b20_src
{
    void* Lookup(FUN_00e54b20_out* out, unsigned int key);
};
struct FUN_00e54b20_sink
{
    void Consume();
};
void __cdecl LookupAndConsume(FUN_00e54b20_src* src, unsigned int key);
class E54B50Vector4 {
public:
    double Length() const;

    float x;
    float y;
    float z;
    float w;
};
double E54B50Dot(const E54B50Vector4& kA, const E54B50Vector4& kB);
float Vector4NormalizedDot(const E54B50Vector4& kA, const E54B50Vector4& kB);
struct FUN_00e54ae0_class
{
    void __thiscall GetHelperValueAsFloat();
};
struct FUN_00e532b0_class
{
    FUN_00e54ae0_class* __thiscall UpdateState_00e532b0(void* buffer, void* value);
};
void __cdecl hkaNURBS_Distance3D(void* value, FUN_00e532b0_class* object);
char* __cdecl IsSampleBoundary(int* base, int idx, int b, int c);
int __cdecl FindFirstNonZero(int aiStartIndex, int b, int c);
struct E54C50IntArray {
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
inline void E54C50MemCpy4(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *reinterpret_cast<int*>(static_cast<char*>(dst) + i) = *reinterpret_cast<const int*>(static_cast<const char*>(src) + i);
}
void RemoveAndDecrement(int index, E54C50IntArray& array, int end);
struct Float4 { float x, y, z, w; };
extern const double DAT_01016978;
void __cdecl hkaNURBS_CurvePoint(Float4* out, int a, int b, int c, int d, float input);
float __cdecl LookupAndConsume(const Float4* left, const Float4* right);
unsigned char* __cdecl CheckVerticesAboveThresholds(unsigned char* result, int a, int b, int c, int d, int last, Float4** verticesPtr, float** valuesPtr, float** thresholdsPtr);
extern void __cdecl hkaNURBS_ApproximateCurve(int, int, int, int, float, int, int, int, int);
void __cdecl _ApproximateNURBSCurve(int i1, int i2, int i3, int i4, float f5, int i6, int i7, int i8, int i9);
struct FUN_00e58820_cls {
    float* m_data;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    void FillWithValue(const float* value);
};
struct FUN_00e58890_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int EvaluateValue_00e58890();
};
struct SpawnArray
{
    void* unk00;
    int unk04;
    unsigned int unk08;
    void Reset()
    {
        unk00 = 0;
        unk04 = 0;
        unk08 = 0x80000000;
    }
};
struct FUN_00e58b50_cls
{
    SpawnArray m_kPointA;
    SpawnArray m_kPointB;
    SpawnArray m_iThirdValue;
    int unk24;
    int unk28;
    FUN_00e58b50_cls* ResetSpawnArrays(int a1, int a2);
};
void __cdecl DifferenceInPlace(float* samples, unsigned int count);
struct FUN_00e5c490_entry
{
    unsigned int m_ptr;
    unsigned int m_unk04;
};
int CompareStringsCaseInsensitive(unsigned int item, unsigned int ctx);
class FUN_00e5c490_cls
{
public:
    unsigned int m_unk00;
    FUN_00e5c490_entry* m_pEntries;
    int m_uiItemCount;

    int FindEntryIndex(unsigned int a1);
};
class AttrEntry_b5103 {
public:
    int m_unk00;
    int m_unk04;
    int* m_pIntegerData;
};
class AttrLog_b5103 {
public:
    virtual void Dummy0() throw();
    virtual void Dummy1() throw();
    virtual void Dummy2() throw();
    virtual void Assert(int level, unsigned int magic, const char* msg, const char* file, int line) throw();
};
class AttrTmp_b5103 {
public:
    void Commit() throw();
    int m_unk00;
    int m_unk04;
};
class AttrWriter_b5103 {
public:
    AttrWriter_b5103(unsigned int* buf, unsigned int size) throw();
    int m_unk00;
    int m_unk04;
    int m_unk08;
    AttrWriter_b5103& Write5(const char* a, const char* name, const char* b, const void* self, const char* c) throw();
    AttrWriter_b5103& Step1() throw();
    AttrWriter_b5103& Step2() throw();
    AttrWriter_b5103& Step3() throw();
    AttrWriter_b5103& Step4() throw();
    AttrWriter_b5103& Step5();
    void Release() throw();
    unsigned int* GetBuf() throw();
};
class AttrStream_b5103 {
public:
    AttrStream_b5103(unsigned int* buf, unsigned int size) throw();
    AttrWriter_b5103 m_w;
};
extern AttrLog_b5103* DAT_01268360_b5103;
class FUN_00e5c6b0_cls {
public:
    AttrEntry_b5103* FindPrimary(const char* name) throw();
    AttrEntry_b5103* FindSecondary(const char* name) throw();
    int GetBoolAttribute(const char* name, bool required, unsigned char* out);
};
struct ConfigValue { unsigned type, identifier; const void* data; };
struct CharBuffer {
    char* destination;
    unsigned capacity, length;
    void FUN_00cb1600(char*, unsigned);
    CharBuffer* ProcessAndReturnValue_00cc01c0(const char*);
    CharBuffer* WriteName(const void*);
    void FUN_00cc00e0();
};
struct DiagnosticLogger {
    virtual void open(); virtual void close(); virtual void flush();
    virtual void report(int, unsigned, const char*, const char*, int);
};
extern DiagnosticLogger* DAT_01268360;
extern const char str_010ecd20[],str_010eccfc[],str_010ecd0c[],str_010eccc8[];
struct ConfigTable {
    ConfigValue* Runtime_ForwardCall_00e5c5d0(const char*);
    ConfigValue* Runtime_ForwardCall_00e5c5b0(const char*);
    ConfigValue* Runtime_ForwardCall_00e5c5f0(const char*);
    int GetUnsignedValue(const char*, bool, unsigned*);
};
struct FUN_00e5c8b0_Node
{
    unsigned int m_00;
};
struct FUN_00e5c8b0_Target
{
    void FindValue(unsigned int a, unsigned int* b);
};
struct FUN_00e5c8b0_Rec
{
    int unk00;
    int unk04;
    FUN_00e5c8b0_Node* m_08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00e5c8b0_Target* m_20;
};
struct FUN_00e5c8b0_Str
{
    int m_00;
    int m_04;
    int m_08;
    void Set(char* buf, unsigned int len);
    FUN_00e5c8b0_Str* Chain5(const char* s0, int a1, const char* s2, int a3, const char* s4);
    FUN_00e5c8b0_Str* Chain0();
    FUN_00e5c8b0_Str* ChainB();
    FUN_00e5c8b0_Str* ChainC();
    void Release();
};
struct FUN_00e5c8b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00e5c8b0_Rec* Runtime_ForwardCall_00e5c610(int a);
    FUN_00e5c8b0_Rec* Runtime_ForwardCall_00e5c5f0(int a);
    int GetAttributeValue(int a, bool flag, unsigned int* out);
};
struct FUN_00e5c8b0_Logger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int level, unsigned int code, const char* msg, const char* file, int line);
};
extern FUN_00e5c8b0_Logger* g_01268360;
struct AttrLogBuf {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7c;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8c;
    unsigned int m_90;
    unsigned int m_94;
    unsigned int m_98;
    unsigned int m_9c;
    unsigned int m_a0;
    unsigned int m_a4;
    unsigned int m_a8;
    unsigned int m_ac;
    unsigned int m_b0;
    unsigned int m_b4;
    unsigned int m_b8;
    unsigned int m_bc;
    unsigned int m_c0;
    unsigned int m_c4;
    unsigned int m_c8;
    unsigned int m_cc;
    unsigned int m_d0;
    unsigned int m_d4;
    unsigned int m_d8;
    unsigned int m_dc;
    unsigned int m_e0;
    unsigned int m_e4;
    unsigned int m_e8;
    unsigned int m_ec;
    unsigned int m_f0;
    unsigned int m_f4;
    unsigned int m_f8;
    unsigned int m_fc;
    unsigned int m_100;
    unsigned int m_104;
    unsigned int m_108;
    unsigned int m_10c;
    unsigned int m_110;
    unsigned int m_114;
    unsigned int m_118;
    unsigned int m_11c;
    unsigned int m_120;
    unsigned int m_124;
    unsigned int m_128;
    unsigned int m_12c;
    unsigned int m_130;
    unsigned int m_134;
    unsigned int m_138;
    unsigned int m_13c;
    unsigned int m_140;
    unsigned int m_144;
    unsigned int m_148;
    unsigned int m_14c;
    unsigned int m_150;
    unsigned int m_154;
    unsigned int m_158;
    unsigned int m_15c;
    unsigned int m_160;
    unsigned int m_164;
    unsigned int m_168;
    unsigned int m_16c;
    unsigned int m_170;
    unsigned int m_174;
    unsigned int m_178;
    unsigned int m_17c;
    unsigned int m_180;
    unsigned int m_184;
    unsigned int m_188;
    unsigned int m_18c;
    unsigned int m_190;
    unsigned int m_194;
    unsigned int m_198;
    unsigned int m_19c;
    unsigned int m_1a0;
    unsigned int m_1a4;
    unsigned int m_1a8;
    unsigned int m_1ac;
    unsigned int m_1b0;
    unsigned int m_1b4;
    unsigned int m_1b8;
    unsigned int m_1bc;
    unsigned int m_1c0;
    unsigned int m_1c4;
    unsigned int m_1c8;
    unsigned int m_1cc;
    unsigned int m_1d0;
    unsigned int m_1d4;
    unsigned int m_1d8;
    unsigned int m_1dc;
    unsigned int m_1e0;
    unsigned int m_1e4;
    unsigned int m_1e8;
    unsigned int m_1ec;
    unsigned int m_1f0;
    unsigned int m_1f4;
    unsigned int m_1f8;
    unsigned int m_1fc;
};
struct AttrEntry {
    int m_00;
    int m_04;
    float* m_08;
};
class AttrLogBuilder {
public:
    char* m_pString;
    unsigned short m_sLen;
    unsigned short m_sMaxLen;
    unsigned int m_08;
    void Init(AttrLogBuf* buf, unsigned int size);
    AttrLogBuilder* Build(const char* a, const char* name, const char* b, void* self, const char* c);
    AttrLogBuilder* Chain();
    AttrLogBuilder* Other();
    void Free();
};
class LogSink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Log(int level, unsigned int tag, const char* msg, const char* file, int line);
};
extern LogSink* g_pAttrLogger;
class FUN_00e5c9b0_cls {
public:
    AttrEntry* FindAttr(const char* name);
    int GetFloatAttribute(const char* name, bool log, float* out);
};
// FUN_00e5cec0 - forwards this + four stack arguments to SpliceArray,
// with a literal zero inserted as the third argument.
struct FUN_00e5cdb0_class {
    void __thiscall SpliceArray(int a, int b, int c, int d, int e);
    void __thiscall SpliceArray_Thunk(int a, int b, int c, int d);
};
struct S_00e5cfb0_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};
struct S_00e65ee0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void __thiscall queryOnTree(int* buffer, int value);
};
void __cdecl _hkMoppFindAllVirtualMachine_getAllKeys(S_00e5cfb0_Object* object, int value);
extern float DAT_0104e148;
struct FloatArray_e404b0 {
    float* data;
    int count;
};
template <class T> inline T MaxOf(T a, T b) { return a > b ? a : b; }
float __cdecl hkaFootstepAnalysisInfo_getMax(FloatArray_e404b0* arr);
extern float _DAT_0104da48;
float __cdecl FindMinFloat(int *param_1);
extern int DAT_010e60c4;
struct FUN_00e44070 {
    int* volatile m_00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile float m_08;
    volatile float m_0c;
    void* volatile m_10;
    volatile int m_14;
    volatile unsigned int m_18;

    FUN_00e44070();
};
class PrimaryE45 {
public:
    virtual ~PrimaryE45();

    int unk04;
};
class ListenerAE45 {
public:
    virtual void OnAdded();
};
class ListenerBE45 {
public:
    virtual void OnRemoved();
};
class ListenerCE45 {
public:
    virtual void OnActivated();
};
class ListenerDE45 {
public:
    virtual void OnDeactivated();
};
class BaseE45 : public PrimaryE45, public ListenerAE45, public ListenerBE45, public ListenerCE45, public ListenerDE45 {
public:
    BaseE45();
    virtual ~BaseE45();

    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
class EnabledFlagE45 {
public:
    __forceinline EnabledFlagE45() : m_bEnableState(true) {}

    bool m_bEnableState;
};
class SlotTableE45 {
public:
    __forceinline SlotTableE45()
        : m_pv00(0),
          m_pv04(0),
          m_pv08(0),
          m_pv0C(0),
          m_pv10(0),
          m_pv14(0),
          m_pv18(0),
          m_pv1C(0),
          m_pv20(0),
          m_pv24(0),
          m_pv28(0),
          m_pv2C(0),
          m_pv30(0),
          m_pv34(0),
          m_pv38(0),
          m_pv3C(0),
          m_pv40(0),
          m_pv44(0),
          m_pv48(0),
          m_pv4C(0),
          m_pv50(0),
          m_pv54(0),
          m_pv58(0),
          m_pv5C(0),
          m_pv60(0),
          m_pv64(0),
          m_pv68(0),
          m_pv6C(0),
          m_pv70(0),
          m_pv74(0),
          m_pv78(0),
          m_pv7C(0)
    {
    }

    void* m_pv00;
    void* m_pv04;
    void* m_pv08;
    void* m_pv0C;
    void* m_pv10;
    void* m_pv14;
    void* m_pv18;
    void* m_pv1C;
    void* m_pv20;
    void* m_pv24;
    void* m_pv28;
    void* m_pv2C;
    void* m_pv30;
    void* m_pv34;
    void* m_pv38;
    void* m_pv3C;
    void* m_pv40;
    void* m_pv44;
    void* m_pv48;
    void* m_pv4C;
    void* m_pv50;
    void* m_pv54;
    void* m_pv58;
    void* m_pv5C;
    void* m_pv60;
    void* m_pv64;
    void* m_pv68;
    void* m_pv6C;
    void* m_pv70;
    void* m_pv74;
    void* m_pv78;
    void* m_pv7C;
};
class FUN_00e45530_Manager : public BaseE45 {
public:
    FUN_00e45530_Manager();
    virtual ~FUN_00e45530_Manager();

    EnabledFlagE45 m_kEnabled;
    SlotTableE45 m_kSlots;
};
struct AllocationHeap {
    virtual void Unused0();
    virtual void* Allocate(unsigned int bytes);
    virtual void Unused8();
    virtual void UnusedC();
    virtual void Deallocate(void* pointer, unsigned int bytes);
};
struct CListener {
    virtual ~CListener() throw() {}
};
template <typename T>
struct HkSmallArray {
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    HkSmallArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000) {}

    int indexOf(const T& element) const {
        for (int i = 0; i < (int)m_iElementCount; ++i) {
            if (m_data[i] == element) {
                return i;
            }
        }
        return -1;
    }
};
struct ExtendedListeners {
    HkSmallArray<void*> first;
    HkSmallArray<CListener*> second;

    static void* operator new(size_t sz) {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        return ((AllocationHeap*)mgr->m_pAllocator)->Allocate(sz);
    }
};
struct ActorEntry {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210;
    ExtendedListeners* m_pExtendedListeners;

    ExtendedListeners* getExtendedListeners() {
        if (!m_pExtendedListeners) {
            m_pExtendedListeners = new ExtendedListeners;
        }
        return m_pExtendedListeners;
    }

    void __thiscall removeEntityListener_00c9c670(CListener* el);
};
template <typename T>
struct HkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        AllocationHeap* heap = (AllocationHeap*)mgr->m_pAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0) {
            heap->Deallocate(m_data, (cap & 0x3fffffff) * 4);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct CBase0 {
    virtual ~CBase0() throw() {}
    int m_ref;
};
struct CBase8 {
    virtual ~CBase8() throw() {}
};
struct CBaseC {
    virtual ~CBaseC() throw() {}
};
struct CBase10 {
    virtual ~CBase10() throw() {}
};
struct CBase14 {
    virtual ~CBase14() throw() {}
};
struct CShape : CBase0, CBase8, CBaseC, CBase10, CBase14 {
    virtual ~CShape() throw() {}
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct FUN_00e46900 : CShape, CListener {
    HkArray<ActorEntry*> m_kActorEntries;

    virtual ~FUN_00e46900() throw();
};
struct Ref { void FUN_00c90510(); };
int hkMeshPrimitiveUtil_calculateNumIndices(unsigned char,int);
struct Entry { Ref* name; Ref* pClassInfo; unsigned char type; unsigned char flags; unsigned short reserved; int count; unsigned char storage; unsigned char ReplaceImpactData; unsigned short reserved12; void* data; int unk18; int unk1c; int length() const { int t=type; return hkMeshPrimitiveUtil_calculateNumIndices(t,count); } };
struct Allocator {};

hkMemoryRouter* getRouter();
int hkMeshPrimitiveUtil_calculateNumIndices(unsigned char type,int count);
extern "C" void hkArrayUtil__reserve(Allocator*,void*,int,int);
void hkString_memCpy(void*,const void*,int);
struct String { void* value; void init() throw(); void assign(const char*) throw(); };
struct ArrayBase {
 void* data; int size; int capacity;
 ArrayBase():data(0),size(0),capacity(0x80000000){}
 int getCapacity() const {return capacity & 0x3fffffff;}
 static void grow(Allocator& heap,ArrayBase* a,int n,int stride) { int cap=a->getCapacity(); if(cap<n) hkArrayUtil__reserve(&heap,a,n<2*cap?2*cap:n,stride); }
 void reserve(Allocator& heap,int n,int stride){grow(heap,this,n,stride);}
};
template<class T> struct Arr : ArrayBase {
 void reserve(Allocator& heap,int n){ArrayBase::reserve(heap,n,sizeof(T));}
 void SetSizeAndGrow(Allocator& heap,int n){reserve(heap,n);size=n;}
 T* expand(Allocator& heap,int n) {int old=size; reserve(heap,old+n); size+=n; return (T*)data+old;}
};
struct Base { virtual void dummy(); unsigned short flags; short refs; Base(){refs=1;} };
struct FUN_00e4a1d0:Base {
 Arr<Entry> entries; Arr<unsigned short> shorts; Arr<unsigned int> ints; String label;
 FUN_00e4a1d0(const Entry* source,int count);
 virtual void dummy();
};
struct E51F00Format
{
    unsigned char bits;
    unsigned char rawCount;
    unsigned short unk02;
    float range;
    float minimum;
};
static void __declspec(noinline) E51F00Helper(float* data, int count, float* minOut, float* maxOut)
{
    if (count <= 0)
    {
        *maxOut = 0.0f;
        *minOut = 0.0f;
        return;
    }
    *minOut = data[0];
    *maxOut = data[0];
    int i = 0;
    if (count >= 4)
    {
        for (; i <= count - 4; i += 4)
        {
            if (data[i] < *minOut) *minOut = data[i];
            else if (data[i] > *maxOut) *maxOut = data[i];
            if (data[i + 1] < *minOut) *minOut = data[i + 1];
            else if (data[i + 1] > *maxOut) *maxOut = data[i + 1];
            if (data[i + 2] < *minOut) *minOut = data[i + 2];
            else if (data[i + 2] > *maxOut) *maxOut = data[i + 2];
            if (data[i + 3] < *minOut) *minOut = data[i + 3];
            else if (data[i + 3] > *maxOut) *maxOut = data[i + 3];
        }
    }
    for (; i < count; ++i)
    {
        if (data[i] < *minOut) *minOut = data[i];
        else if (data[i] > *maxOut) *maxOut = data[i];
    }
}
void __cdecl InitFormatFromData(float* data, unsigned int count, E51F00Format* format, unsigned int numBits, unsigned int rawStart);
Vec4f VectorMax(const Vec4f& a, const Vec4f& b);
struct L { int* m_00; int m_04; };
void __cdecl hkaNURBS_Remove(int aiIndex, L* list);
struct HolderView { int unk00; int unk04; int unk08; int unk0c; void* volatile m_pAllocator; };
struct FloatArrayRef {
    float* data;
    int size;
    unsigned int capacity;
};
int __cdecl hkaNURBS_DegreeElevateKnotVector(FloatArrayRef* array, int count);
struct ArrayAllocator;

void hkArrayUtil__reserve(ArrayAllocator* alloc, hkArrayBase<float>* arr, int newCap, int elemSize);
static __forceinline void FloatArray_reserve(hkArrayBase<float>& self, ArrayAllocator& alloc, int n);

static __forceinline void FloatArray_reserve(hkArrayBase<float>& self, ArrayAllocator& alloc, int n)
{
        int cap = self.getCapacity();
        if (cap < n) {
            int c = 2 * cap;
            hkArrayUtil__reserve(&alloc, (&self), n < c ? c : n, 4);
        }
    }

hkMemoryRouter* GetMemoryRouter();
int RemoveAdjacentDuplicates(hkArrayBase<float>* arr, int last);
// Element-wise subtract another matrix of the same shape from this one.
class E87E0Matrix {
public:
    float* m_pfData;
    int unk04;
    int unk08;
    int m_iRows;
    int m_iColumns;

    float& Element(int i) { return m_pfData[i]; }
    E87E0Matrix& SubtractMatrixElements(const E87E0Matrix& kOther);
};
class CE588A0Vector {
public:
    double Get(int iIndex);
    int GetSize();
};
float __cdecl DotProduct(CE588A0Vector* pkA, CE588A0Vector* pkB);
struct Stand_e58d90 {
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
    int m_iArrayCapacity;
    int m_iElemSize;
    Stand_e58d90* InitArray(int a1, int a2);
};
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
static inline float QSqrt(float v) { return (float)sqrt(v); }
void UnpackQuaternion(const unsigned int* packed, float* quat);
extern int DAT_010e7874;
extern int DAT_010e7868;
extern int DAT_010e7854;
extern int DAT_010e7848;
extern int DAT_010e783c;
extern int DAT_010e781c;
extern int DAT_010cb1e4;
struct FUN_00cbfba0_Base {
    void FUN_00cbfba0();
};
struct FUN_00c90510_Reference {
    void FUN_00c90510();
};
struct FUN_00e46b30_Layout {
    void* primaryVtable;
    int referenceCount;
    void* secondaryVtable;
    void* thirdVtable;
    void* fourthVtable;
    void* fifthVtable;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    void* volatile listenerVtable;
    FUN_00c90510_Reference* reference;
};
struct FUN_00e46b30_Class : FUN_00e46b30_Layout {
    FUN_00e46b30_Class* InitializeWithReference(FUN_00c90510_Reference* value);
};
struct FUN_00c905b0_class {
    void __thiscall FUN_00c905b0();
};
extern int DAT_010e7874;
extern int DAT_010e7868;
extern int DAT_010e7854;
extern int DAT_010e7848;
extern int DAT_010e783c;
extern int DAT_010e781c;
extern int DAT_010cb1e4;
extern int DAT_010c3b8c;
extern int DAT_010c3bac;
extern int DAT_010c3b98;
extern int DAT_010c3b80;
extern int DAT_0102e388;
struct FUN_00e46b80_class {
    int* unk00;
    int* unk04;
    int* unk08;
    int* unk0C;
    int* unk10;
    int* unk14;
    int* unk18;
    int* unk1C;
    int* unk20;
    int* unk24;
    int* unk28;
    int* unk2C;
    int* unk30;
    FUN_00c905b0_class* unk34;

    void __thiscall UpdateFields_00e46b80();
};
struct FUN_00e46e80 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e46e80();
};
struct E473C0Owner;
struct E473C0Target {
    virtual void vf00();
    virtual void vf01();
    virtual void __thiscall vf02(E473C0Owner* a1, int a2);
};
struct E473C0Owner {
    int unk00;
    unsigned short unk04;

    void __thiscall FUN_00e47020();
    E473C0Owner* __thiscall FUN_00e473c0(unsigned char flags);
};
struct FnvCpu_FUN_00e473f0_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    void SetValue(unsigned char arg0);
};
extern int DAT_010e81a4;
struct FUN_00e48240 {
    void* m_vTable;
    short m_flags;
    short m_sState;
    int m_uiFilterValue;
    FUN_00e48240(int value);
};
extern int DAT_010cb76c;
extern int DAT_010cb780;
extern int DAT_010e83b4;
struct SourceData {
    void* m_ppVirtualMethodTable;
    unsigned short m_unknown04,m_flags;
    unsigned char m_uiContentCount,m_unknown09,m_unknown0a,m_unknown0b;
    float m_pHeadNode,m_iSecondInteger;
    int m_third,m_fourth,m_fifth,m_sixth,m_seventh;
};
struct FUN_00e48400 {
    int* m_ppVirtualMethodTable;
    unsigned short m_unknown04,m_flags;
    unsigned char m_uiContentCount,m_unknown09,m_unknown0a,m_unknown0b;
    float m_pHeadNode,m_iSecondInteger;
    int m_third,m_fourth,m_fifth,m_sixth,m_seventh;
    FUN_00e48400(const SourceData* source);
};
struct FUN_00e484a0_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char* m_base20;
};
struct FUN_00e484a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int* m_items0C;
    int m_count10;
    void ClearReferencedBytes(FUN_00e484a0_Arg* arg);
};
struct FUN_00e484e0_dst {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char* m_20;
};
struct FUN_00e484e0_class {
    int unk00;
    int unk04;
    int unk08;
    unsigned int* m_0c;
    int m_10;
    void ScatterBytes(FUN_00e484e0_dst* dst);
};
extern "C" int DAT_010e8ab0;
extern "C" int DAT_010e8a90;
struct FUN_00e48db0_holder {
    void FUN_00dcd310(float f, void* p);
};
struct FUN_00e48db0_class {
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e48db0_class* __thiscall InitFromFloatAndPointer(float f, void* p);
};
int CompareStringsCaseInsensitive(const char* a, const char* b);
struct Node4a5
{
    char pad[0x14];
    unsigned int m_uiName;

    const char* GetName() const { return (const char*)(m_uiName & ~1); }

    Node4a5* FindChildByName(const char* pcName);
};
struct Owner4a5
{
    char pad[0x14];
    Node4a5* m_pkTreeNode;

    Node4a5* EvaluateValue_00e4a550(const char* pcName);
};
struct GtrStand_ {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* GetUnk14Address_00e4af40();
};
struct HolderStub;
HolderStub* __cdecl hkMemoryRouter_getInstance();
HolderStub* __cdecl hkStackMemory_getInstance();
void nullsub_293();
void __cdecl nullsub_294();
void nullsub_292();

void __cdecl hkaNURBS_CurvePoint_00e546e0(int a, int b, int c, int d, int count, float** inputs, hkVector4** outputs);
struct E58E80Object {
    void CopyFrom(int setting);
};
E87E0Matrix* __fastcall Object_ProcessAndReturnValue_00e58e80(int setting, int unused, E58E80Object* object, const E87E0Matrix& right);
void __cdecl PrefixSum(float* afValues, unsigned int n);

hkBool __cdecl InvertMatrix2x2(const float* afMatrix, float* afInverse, float fEps);
struct E5B110Ref { void FUN_00c90510(); };
struct E5B110Obj {
    void CopyStateFrom(void* p);
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    E5B110Ref* unka0;
};
static void _copyAtoms(E5B110Obj* obj, void* p);
void E5B110Caller(char* q, int a, int b, int c);
int GetUnsignedValue(const char*, bool, unsigned*);
int Object_GetUnsignedValue_Thunk(const char* p, bool b, unsigned* u);
struct UnkRet;
struct FUN_00e47390_obj {
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p, unsigned int bytes);
};
struct UnkRet {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00e47390_obj* m_10;
};
struct UnkHolder {
    void* m_00;
    unsigned int m_04;
    UnkRet* hkMemoryRouter_getInstance();
    void UpdateState_00e47390();
};
extern float DAT_0108cb00;
class RefObjectE483 {
public:
    RefObjectE483() { m_sReferenceCount = 1; }
    virtual ~RefObjectE483();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
class TypedObjectE483 : public RefObjectE483 {
public:
    TypedObjectE483() { m_type = 0; }
    unsigned char m_type;
};
class FUN_00e48390 : public TypedObjectE483 {
public:
    FUN_00e48390(int a, int b);
    virtual ~FUN_00e48390();
    volatile float m_fCoefficientA;
    float m_fB;
    int m_iB;
    int m_iA;
};
unsigned char __cdecl Object_ReturnArgument_00e48460(unsigned char value);
static unsigned int Runtime_EvaluateValue_00e48470(unsigned int uiValue);
unsigned int E48470Shift(unsigned int uiValue);
struct e48480_cls { unsigned char b; };
extern "C" e48480_cls* e48480_target(void);
extern "C" unsigned char e48480_val(void);
static void Object_UpdateFields_00e48480(e48480_cls* dst, unsigned char val);
void e48480_caller(void);
// FUN_00e48490: ORs the low byte at [this] with an incoming value shifted
// left by 8, stores the dword back, and returns the shifted value in eax.
// The value arrives in eax via VC9's private calling convention for a
// single-call-site static function, driven by a dummy caller that passes
// two extern-call returns.
union E48490Cell {
    unsigned char m_b0;
    int m_cell;
};
E48490Cell* E48490PtrSrc();
int E48490ValSrc();
static int Runtime_UpdateState_00e48490(E48490Cell* cell, int value);
void E48490Driver();
static void hkGetSignalRange(float* outMin, float* outMax, const float* values, int count);
extern "C" float* mm_min(void);
extern "C" float* mm_max(void);
extern "C" const float* mm_vals(void);
extern "C" int mm_count(void);
void mm_caller(void);
struct SampleField {
    int NiD3DShaderProgram_GetShaderProgramName();
    float* GetElementPtr(int index, int component);
    void FillWithValue(float* value);
    float GetFloatAt(int index, int component);
};
struct FUN_00e58a20_cls {
    float* m_00;
    int m_04;
    int unk08;
    int* m_0c;
    int unk10;
    int unk14;
    int* m_18;
    void hkaSparseLSQMatrix_float_MultiplyAdd(SampleField* volatile input, SampleField* weights, SampleField* output);
};
// Source struct: only its float members at 0x80..0x94 take part; the rest are
// stand-in fields holding the earlier offsets.
struct Src
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7c;
    float m_80;
    float m_84;
    unsigned int m_88;
    unsigned int m_8c;
    float m_90;
    float m_94;
};
// Destination object: receives the two scaled components at 0x1c / 0x20.
struct Dst
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    float m_1c;
    float m_20;
};
static void hkVehicleFrictionSolverCalcRelativeForces_00e593d0(Dst* dst, Src* src);
// in-TU caller so c2 keeps the body and negotiates the register convention.
static Dst* volatile g_dst;
static Src* volatile g_src;
void e593d0_apply_pair();
#include <math.h>
class FUN_00e40740_cls {
public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    float* m_pMinArray;
    int unk60;
    int unk64;
    float* m_pMaxArray;
    void UpdateMinMax(int index, float value);
};
#include <xmmintrin.h>
extern int DAT_010e6834;
struct MotorObject {
    int* vtable;
    unsigned short flags;
    unsigned short references;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
    int unk1c;
    __m128 vector20;
    __m128 vector30;
    float value40;
    float value44;
    void FUN_00d2b260(void*, int);
    MotorObject* hkpReorientAction_hkpReorientAction();
};
struct LoadedFlag { int finishing; };
extern "C" int DAT_010ec004;
struct LoadedObject {
    void* vtable;
    int unk04;
    unsigned char type;
    void FUN_00e46f20(LoadedFlag flag);
    LoadedObject* Initialize(LoadedFlag flag);
};
void* operator new(size_t, void* p) { return p; }
template<class T> struct EntityArray : HkArray<T> {
    __forceinline int indexOf(const T& element) const {
        for (int i = 0; i < this->m_iElementCount; ++i) {
            if (this->m_data[i] == element) return i;
        }
        return -1;
    }
    __forceinline void AddBack(const T& element) {
        HolderStub* holder = hkMemoryRouter_getInstance();
        if (this->m_iElementCount == (this->m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(holder->m_pAllocator, this, sizeof(T));
        }
        T* destination = this->m_data + this->m_iElementCount;
        for (int k = 0; k < 1; ++k) destination[k] = element;
        ++this->m_iElementCount;
    }
};
struct SmallBool { unsigned char value; SmallBool(bool v) : value(v) {} };
struct EntityShape {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    CListener m_kListener;
    EntityArray<Actor*> m_kActorEntries;
    SmallBool AddActor(Actor* item);
};
struct BitLinks {
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
    unsigned int m_ppLinks[64];

    void SetLink(int a, int b);
};
namespace se49080 {

extern "C" const char DAT_010e8e94[];
extern "C" const char DAT_010e8e74[];

void __fastcall FUN_00c90510(void* pvObject);

struct Shape;

struct ShapeBase {
    const char* m_pVtbl;
    int unk004;
    int unk008;
    int unk00c;
    const char* m_pVtbl2;

    void FUN_00d21410(int iType, int iFlags);
};

struct KeyedPointerEntry : ShapeBase {
    int unk14;
    Shape* m_pkShapeB;
    Shape* m_pkShapeA;
    float m_fBoundRadius;

    KeyedPointerEntry* InitializeFields_00e49080(Shape* pkShapeA, Shape* pkShapeB, float fRadius);
};

// @fnv 0x00e49080
// src: GUESS 0x00e49080 (confidence: low)
KeyedPointerEntry* KeyedPointerEntry::InitializeFields_00e49080(Shape* pkShapeA, Shape* pkShapeB, float fRadius)
{
    FUN_00d21410(7, 3);
    m_fBoundRadius = fRadius;
    m_pVtbl = DAT_010e8e94;
    m_pVtbl2 = DAT_010e8e74;
    m_pkShapeB = pkShapeB;
    m_pkShapeA = pkShapeA;
    FUN_00c90510(pkShapeA);
    FUN_00c90510(m_pkShapeB);
    return this;
}

}
namespace se493a0 {

struct Stats {
    int m_iTotal;
    int m_iArrayLength;
    float m_fAverage;
    int m_iMaxControlPoint;
};

struct Layout {
    int unk000;
    int unk004;
    int* m_piSizes;
    int unk00c;
    int unk010;
    int* m_piIndices;
    int m_iNumIndices;
    int unk01c;
    int unk020;
    int m_iBase;
};

struct Owner {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    Layout* m_pkLayout;

    void AccumulateControlPointStatistics(Stats* pkStats);
};

// @fnv 0x00e493a0
// src: GUESS 0x00e493a0 (confidence: medium)
void Owner::AccumulateControlPointStatistics(Stats* pkStats)
{
    pkStats->m_iTotal += m_pkLayout->m_iBase;
    pkStats->m_iArrayLength += m_pkLayout->m_iBase;
    for (int i = 0; i < m_pkLayout->m_iNumIndices; i++)
    {
        int iSize = m_pkLayout->m_piSizes[m_pkLayout->m_piIndices[i]];
        pkStats->m_iTotal += iSize;
        pkStats->m_iMaxControlPoint = pkStats->m_iMaxControlPoint > iSize ? pkStats->m_iMaxControlPoint : iSize;
    }
    pkStats->m_iArrayLength += m_pkLayout->m_iNumIndices;
    pkStats->m_fAverage = (float)pkStats->m_iTotal / pkStats->m_iArrayLength;
}

}
struct SrcArray
{
    unsigned short* m_pBase;
    int m_uiLogicalSize;
};
class AllocatorIface
{
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* Alloc(int* pSize);
    virtual void Free(void* pBuffer, unsigned int size);
};
class SpawnedBase
{
public:
    virtual void unkBase();
    SpawnedBase(unsigned int flags, int one);
};
class FUN_00e49900 : public SpawnedBase
{
public:
    virtual void unkBase();
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
    unsigned short* m_pData;
    int m_iArrayLength;
    unsigned int m_uiCapacity;
    unsigned char m_bFlag;
    float m_fTimeA;
    float m_fTimeB;

    FUN_00e49900(unsigned int flags, SrcArray* src, float a, float b);
};
void __cdecl Object_DoNothing_00e4b560();
struct Count { int n; };
extern "C" void __movsd(unsigned long* destination,
                        const unsigned long* source,
                        unsigned int count);
void __cdecl DeinterleaveFloats(const float* src, float* dst, Count value);
struct ThresholdAllocator {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void ReleaseBlock(void*, int);
};
struct ThresholdCompare { bool descending; };
void __cdecl hkAlgorithm_quickSortRecursive_float_class_hkAlgorithm_less_float(float*, int, int, ThresholdCompare);
struct ThresholdArray {
    float* data;
    int size;
    int capacity;
    float* original;
    void SetSizeAndGrow(int count) {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        E4AAA0Allocator* heap = (E4AAA0Allocator*)mgr->m_pAllocator;
        int current = capacity & 0x3fffffff;
        if (current < count) {
            int grown = 2 * current;
            hkArrayUtil__reserve(heap, this, count < grown ? grown : count, 4);
        }
        size = count;
    }
    void release() {
        float* saved = original;
        if (saved == data) size = 0;
        hkMemoryRouter_getInstance()->unk00 = (int)saved;
        ClearAndRelease();
    }
    void ClearAndRelease() {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        ThresholdAllocator* heap = (ThresholdAllocator*)mgr->m_pAllocator;
        int cap = capacity;
        size = 0;
        if ((cap & 0x80000000) == 0) heap->ReleaseBlock(data, (cap & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};
inline float ThresholdFloat(unsigned int value) { return (float)value; }
inline float ThresholdAbs(float value) { return (float)fabs(value); }
void __cdecl ThresholdValues(float* values, unsigned int count, float threshold, ThresholdCompare relative);
struct Q { __m128 m_vComponents; void normalize_005611c0(); };
struct QRef { Q* p; Q* operator->() const { return p; } };
void Object_UnpackFourSignedNibbles(const unsigned char* src, QRef out);
class Quat4
{
public:
	float m_fVectorY;
	float m_fVectorZ;
	float m_fScalarPart;
	float m_fVectorX;

	Quat4(float fX, float fY, float fZ, float fW);
	Quat4 GetAbsolute() const;
};
__declspec(noinline) Quat4::Quat4(float fX, float fY, float fZ, float fW)
{
	m_fVectorY = fX;
	m_fVectorZ = fY;
	m_fScalarPart = fZ;
	m_fVectorX = fW;
}
float __cdecl EvaluateBasisFunction(int iDegree, int iNumKnots, const float* const* ppKnots, int i, float fT);
int __cdecl GetRunLength(int lo, int hi, float** arr);
template<class T> struct CurveArg { T value; };

float __cdecl hkaNURBS_ClosestPoint(int a3, int a4, int a5, int a6, float* p, int a9, int a10, float a11, float a12);
void __cdecl hkaNURBS_CurvePoint(V4* out, int a3, int a4, int a5, int a6, float v);
struct CurvePointOps {
    float* UpdateState_00e532b0(V4* p1, V4* p2);
};
struct CurveLengthOps {
    float GetHelperValueAsFloat();
};
void __cdecl hkaNURBS_UpdateFit(int n, CurveArg<float**> a2, CurveArg<int> a3, CurveArg<int> a4, CurveArg<int> a5, CurveArg<int> a6, CurveArg<float**> a7, CurveArg<float**> a8, CurveArg<int> a9, CurveArg<int> a10, float a11, float a12, bool a13);
extern const float runtimeFloatSettingDefault726;
__declspec(noalias) float __cdecl LookupAndConsume(const Float4* left, const Float4* right);
extern "C" float __cdecl hkaNURBS_ClosestPoint(int a, int b, int c, int d, Float4* p, int e, int f, float g, float h);
unsigned char* __cdecl CheckAllSamplesBelowThreshold(unsigned char* result, int a, int b, int c, int d, int last, Float4** samples, float threshold);
// CollectConnectedNodesAndEdges  (__cdecl, 4 args) -- walk a link array, collect incident entries
// The array append keeps the slot address materialised in a register (the original's
// `lea eax,[ecx+eax*4] ; mov [eax],edx`), which a single indexed store does not:
// the slot is reached through a local pointer that is written twice.
struct ChainElem {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* m_link14;
    void* m_link18;
};
template <class T>
struct ChainArray {
    T* m_data;
    int m_iElementCount;
    int m_capFlags;

    void Add(T const& value) {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_capFlags & 0x3fffffff))
            ResizeAudioStream(mgr->m_pAllocator, this, (int)sizeof(T));
        T* pSlot = &m_data[m_iElementCount];
        pSlot[0] = value;
        pSlot[0] = value;
        ++m_iElementCount;
    }
};
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, int auiNewSize);
void __cdecl CollectConnectedNodesAndEdges(ChainArray<void*>* src, void* node, ChainArray<void*>* outNodes, ChainArray<void*>* outEdges);
namespace ns_e5c5 { int __cdecl CompareStringsCaseInsensitive(const char* a, const char* b) throw(); }
struct Resource_e5c5 {
    const char* FUN_00d46d40() throw();
    void FUN_00c905b0() throw();
};
template <class T> struct hkRefPtr_e5c5 {
    T* m_pRetainedObject;
    ~hkRefPtr_e5c5() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
    T* hkRefVariant_getClass() throw();
    T* val() const { return m_pRetainedObject; }
};
struct Registry_e5c5 {
    hkRefPtr_e5c5<Resource_e5c5> FindOrCreateEntryReference(const char* name) throw();
    Resource_e5c5* FindResourceWithExpectedName(const char* name, Resource_e5c5* expected);
};
extern float DAT_010ea628;
extern float DAT_010ec1b0;
struct __declspec(align(16)) Aabb {
    float minX, minY, minZ, minW;
    float maxX, maxY, maxZ, maxW;
};
struct RefObject {
    virtual ~RefObject() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    RefObject() throw() { m_sReferenceCount = 1; }
};
struct HkArr {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    HkArr() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};
struct CollectorBase {
    virtual void Dummy0() throw();
    CollectorBase() throw() {}
};
void __cdecl ConstructTemporaryObject(int a, const Aabb* aabb, CollectorBase* collector);
struct Mid : RefObject, CollectorBase {
    HkArr m_ppData;
    int m_18;
    Mid() throw() : m_18(0) {}
};

struct FnvCpu_FUN_00e49bb0_CpuObject { char* EvaluateValue_00e49bb0(); };
extern double __cdecl FUN_00ec9e10(double x);
__declspec(noinline) hkVector4::hkVector4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
struct ComponentVector {
    float x, y, z, w;
    hkVector4 hkaNURBS_Point_ceil() const;
};
inline float ConvertComponent(float x) { return (float)FUN_00ec9e10(x); }
inline float ConvertEarly(float x, volatile float& temp) {
    temp = x;
    temp = (float)FUN_00ec9e10(temp);
    return temp;
}
struct KnotVector {
    float x,y,z,w;
    KnotVector(float a=0,float b=0,float c=0,float d=0);
    KnotVector& FUN_00e53180(const KnotVector&);
    KnotVector& operator=(const KnotVector& v) { return FUN_00e53180(v); }
    KnotVector& ComputeValue_00e531a0(const KnotVector&);
    KnotVector& SubtractFourComponents(const KnotVector&);
    KnotVector& FUN_00e53200(float);
    KnotVector& DivideByScalar(float);
    KnotVector ScaleCopy(float) const;
    KnotVector UpdateState_00e532b0(const KnotVector&) const;
    KnotVector ProcessAndReturnValue_00e53260(const KnotVector&) const;
    KnotVector EvalCopy(float) const;
};
__declspec(noinline) KnotVector::KnotVector(float a,float b,float c,float d) : x(a),y(b),z(c),w(d) {}
__declspec(noinline) KnotVector& KnotVector::FUN_00e53180(const KnotVector& v) { x=v.x;y=v.y;z=v.z;w=v.w;return *this; }
// src: GUESS 0x00e531a0 (confidence: low)
__declspec(noinline) KnotVector& KnotVector::ComputeValue_00e531a0(const KnotVector& v) {x+=v.x;y+=v.y;z+=v.z;w+=v.w;return *this;}
// src: GUESS 0x00e531d0 (confidence: high)
__declspec(noinline) KnotVector& KnotVector::SubtractFourComponents(const KnotVector& v) {x-=v.x;y-=v.y;z-=v.z;w-=v.w;return *this;}
__declspec(noinline) KnotVector& KnotVector::FUN_00e53200(float f) {x*=f;y*=f;z*=f;w*=f;return *this;}
__declspec(noinline) KnotVector& KnotVector::DivideByScalar(float f) {x/=f;y/=f;z/=f;w/=f;return *this;}
__declspec(noinline) KnotVector KnotVector::ScaleCopy(float f) const {KnotVector a=*this;return a.FUN_00e53200(f);}
KnotVector Object_ScaleCopy_Thunk(float f,const KnotVector& v);
float __cdecl hkaNURBS_Distance3D(const KnotVector&,const KnotVector&);
struct CurveArray { float* data; int size; int capacity; };
struct PointArray { KnotVector* data; int size; int capacity; };
float __cdecl hkaNURBS_GetRemovalBoundCurve(int n,int p,CurveArray& U,PointArray& Pw,float u,int r,int s);
void* _fnv_zlib_memset(void*,int,int);
struct MarkHeap {
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual void* Allocate(int&);
 virtual void Free(void*,int);
 template<class T> __forceinline T* reserve(int& count) {
  int bytes=count*sizeof(T);
  T* p=(T*)Allocate(bytes);
  count=bytes/sizeof(T);
  return p;
 }
 template<class T> __forceinline void freeBuffer(T* p,int count) {Free(p,count*sizeof(T));}
};
struct MarkPolicy {
 __forceinline MarkHeap& get(void* owner) {HolderStub* h=hkMemoryRouter_getInstance();return *(MarkHeap*)h->m_pAllocator;}
};
template<class T> struct MarkStorage {
 T* data; int size; int capacity;
 __forceinline MarkStorage():data(0),size(0),capacity(0x80000000){}
 __forceinline void own(T* p,int n,int c) {data=p;size=n;capacity=c;}
 __forceinline T& operator[](int i) {return data[i];}
};
template<class T> struct MarkArray:MarkStorage<T> {
 __forceinline MarkArray(int count,const T& initial) {
  MarkHeap& heap=MarkPolicy().get(this);
  T* p=count ? heap.reserve<T>(count) : 0;
  int flags=count ? count : (int)0x80000000;
  own(p,count,flags);
  if(size>0) _fnv_zlib_memset(data,initial,size);
 }
 __forceinline void release() {
  MarkHeap* heap=(MarkHeap*)hkMemoryRouter_getInstance()->m_pAllocator;
  int cap=capacity;
  size=0;
  if((cap&0x80000000)==0) heap->Free(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;
 }
};
struct MarkBounds { float* data; };
int FindFloatInterval(int,int,float,MarkBounds*);
bool* IsSampleBoundary(bool*,int,MarkBounds*,int);
void* _fnv_zlib_memset(void*,int,int);
bool* hkaNURBS_IsWellPosed(bool* output,int n,int start,MarkBounds* bounds,int m,MarkBounds* points,float epsilon);
struct MemoryAllocator;
// Adapted from an unverified 2026-10-23 saved reconstruction (credited as 'you').
struct Vertex4 {

    float x, y, z, w;

    Vertex4(float a=0, float b=0, float c=0, float d=0);

    Vertex4* FUN_00e53180(const Vertex4* source);

};
__declspec(noinline) Vertex4::Vertex4(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
__declspec(noinline) Vertex4* Vertex4::FUN_00e53180(const Vertex4* source) { x=source->x; y=source->y; z=source->z; w=source->w; return this; }
struct FloatVector {
    void reserve(MemoryAllocator& alloc, int wanted);

    float* data;

    int count;

    unsigned int capacity;

};
struct VertexVector {
    void SetSizeAndGrow(int wanted);
    void reserve(MemoryAllocator& alloc, int wanted);

    Vertex4* data;

    int count;

    unsigned int capacity;

};
struct InputFloats { const float* data; };
struct InputVertices { const Vertex4* data; };
struct ScratchIndices {

    unsigned int* data;

    int count;

    int capacity;

};
struct MemoryAllocator {

    virtual void ReportDiagnostic();

    virtual void unused1();

    virtual void unused2();

    virtual void* Allocate(int* requestedBytes);

    virtual void Free(void* pointer, int requestedBytes);

};
struct AllocationEnvironment {

    unsigned int unk00, unk04, unk08, unk0c;

    MemoryAllocator* allocator;

};
extern int __cdecl hkaNURBS_DegreeElevateKnotVector(FloatVector*, int);
extern int __cdecl RemoveAdjacentDuplicates(FloatVector*, int);
extern int __cdecl hkaNURBS_RemoveKnotsBoundCurve(int*, int, FloatVector*, VertexVector*, int,

    const InputFloats*, ScratchIndices*, float, const InputVertices*);
struct EvaluationResult {

    bool active;

};
extern void __cdecl FitSpline(EvaluationResult*, int, int, VertexVector*, FloatVector*,

    int, const InputVertices*, const InputFloats*, float, float);
extern void __cdecl hkaNURBS_DegreeElevateCurve(int*, int, FloatVector*, VertexVector*, int);
extern void __cdecl hkaNURBS_UpdateFit(int, const InputVertices*, int, int, FloatVector*, VertexVector*,

    ScratchIndices*, const InputFloats*, int, int, float, float, void*);
extern const float DAT_010718c0, DAT_010959f4;
__forceinline void FloatVector::reserve(MemoryAllocator& heap, int wanted) {
    MemoryAllocator* alloc = &heap;
    FloatVector* vec = this;

    int cap = (int)(vec->capacity & 0x3fffffff);

    if (cap < wanted) {

        const int doubled = cap + cap;

        const int newCapacity = wanted < doubled ? doubled : wanted;

        hkArrayUtil__reserve((E4AAA0Allocator*)alloc, vec, newCapacity, 4);

    }

}
__forceinline void VertexVector::reserve(MemoryAllocator& heap, int wanted) {
    MemoryAllocator* alloc = &heap;
    VertexVector* vec = this;

    int cap = (int)(vec->capacity & 0x3fffffff);

    if (cap < wanted) {

        const int doubled = cap + cap;

        const int newCapacity = wanted < doubled ? doubled : wanted;

        hkArrayUtil__reserve((E4AAA0Allocator*)alloc, vec, newCapacity, 16);

    }

}
__forceinline void VertexVector::SetSizeAndGrow(int wanted) {
    HolderStub* mgr = hkMemoryRouter_getInstance();
    MemoryAllocator* heap = (MemoryAllocator*)mgr->m_pAllocator;
    reserve(*heap, wanted);
    int remaining=wanted-count;
    Vertex4* current=data+count;
    for(int index=0; index<remaining; ++index) new(current+index) Vertex4;
    count = wanted;
}
static __forceinline void FreeScratch(unsigned int* data, int capacity) {

    MemoryAllocator* alloc = ((AllocationEnvironment*)hkMemoryRouter_getInstance())->allocator;

    if ((capacity & 0x80000000) == 0)

        alloc->Free(data, (capacity & 0x3fffffff)*4);

}
static __forceinline void FreeScratchEarly(unsigned int* data, int capacity) {
    HolderStub* mgr = hkMemoryRouter_getInstance();
    MemoryAllocator* heap = (MemoryAllocator*)mgr->m_pAllocator;
    int cap=capacity;
    if ((cap & 0x80000000) == 0) heap->Free(data,(cap & 0x3fffffff)*4);
}
void __cdecl ProcessGeometryPasses(int initialCount, const InputVertices* inputVertices, const InputFloats* inputFloats, void* geometry, int passes, float factor, int& countOutput, FloatVector& positionOutput, VertexVector& vertexOutput);
struct SpawnedAllocator {
    virtual void unkV0();
    virtual void unkV1();
    virtual void unkV2();
    virtual void* Alloc(int* size);
    virtual void Free(void* block, unsigned int size);
};
struct SpawnedHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};
struct SpawnedBlockRef {
    void* data;
    int count;
    unsigned int flags;
};
void __cdecl hkaNURBS_ChordLengthParameterization(int a1, int a2, void* s);
void __cdecl ProcessGeometryPasses(int a1, int a2, SpawnedBlockRef* block, hkBool enabled, int b1, float b2, int b3, int b4, int b5);
void __cdecl hkaNURBS_GlobalCurveApproxErrBnd(int a1, int a2, int a3, float a4, int a5, int a6, int a7);
struct SolverState {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    float m_3c;
    float m_40;
    float m_44;
    float m_48;
    float m_4c;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;
    float m_60;
    float m_64;
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    float m_78;
    float m_7c;
    float m_80;
    float m_84;
    float m_88;
    float m_8c;
    float m_90;
    float m_94;
    float m_98;
};
struct SolverOutput {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
};
struct BoundaryTable {
    float samples[16];
    float scale;
    float initialScale;
};
extern double _gModifierZero;
extern float DAT_0104da4c;
extern const float runtimeFloatSettingDefault1085 = 1.1f;
inline void ApplyBound(float& out, float value) {
    out = value;
    if (out < -1.1f) out = -1.1f;
    else if (out > runtimeFloatSettingDefault1085) out = runtimeFloatSettingDefault1085;
}
static void hkVehicleFrictionSolverClipImpulse(SolverState* __restrict state, const BoundaryTable* table, SolverOutput* output);
void caller(SolverState* s, const BoundaryTable* t, SolverOutput* o);
struct Se5b160_Heap {
    virtual ~Se5b160_Heap();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct Se5b160_Router {
    int unk00; int unk04; int unk08; int unk0c;
    Se5b160_Heap* m_pStreamAllocator;
    Se5b160_Heap& heap() { return *m_pStreamAllocator; }
    static Se5b160_Router& GetMonitorStream() { return *reinterpret_cast<Se5b160_Router*>(hkMemoryRouter_getInstance()); }
};
struct Se5b160_Motor { void FUN_00c90510(); };
struct Se5b160_RefObj {
    virtual ~Se5b160_RefObj();
    static Se5b160_Heap& heap() { return reinterpret_cast<Se5b160_Router*>(hkMemoryRouter_getInstance())->heap(); }
    unsigned short m_usAllocationSize;
    unsigned short m_iObjectReferenceCount;
    static void* operator new(unsigned int nbytes) {
        Se5b160_RefObj* b = static_cast<Se5b160_RefObj*>(Se5b160_Router::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usAllocationSize = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void*) {}
    void FUN_00c905b0();
};
struct Se5b160_HingeAtoms {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    Se5b160_Motor* motor0;
    void CopyStateFrom(const Se5b160_HingeAtoms* source);
};
struct Se5b160_RagdollAtoms {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    Se5b160_Motor* motor0;
    Se5b160_Motor* motor1;
    Se5b160_Motor* motor2;
    void ProcessAndReturnValue_00d85ba0(const Se5b160_RagdollAtoms* source);
};
// src: HAVOK_LIB 0x00e5b110
static __declspec(noinline) void _copyAtoms(const Se5b160_HingeAtoms* source, Se5b160_HingeAtoms* destination) {
    destination->CopyStateFrom(source);
    Se5b160_Motor* m = destination->motor0;
    if (m) m->FUN_00c90510();
}
// src: HAVOK_LIB 0x00e5b130
static __declspec(noinline) void _copyAtoms_00e5b130(const Se5b160_RagdollAtoms* source, Se5b160_RagdollAtoms* destination) {
    destination->ProcessAndReturnValue_00d85ba0(source);
    Se5b160_Motor** motor = &destination->motor0;
    for (int i = 0; i < 3; ++i, ++motor) {
        if (*motor) (*motor)->FUN_00c90510();
    }
}
struct Se5b160_Data : Se5b160_RefObj {
    virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual hkpConstraintData::ConstraintType getType() const;
    int unk08; int unk0c;
};
struct FUN_00cb9090 : Se5b160_Data {
    Se5b160_HingeAtoms m_kBridgeAtoms;
    int unkb4; int unkb8; int unkbc; int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc; 
    FUN_00cb9090() throw();
    void SetReferencedObject(Se5b160_Motor* motor);
    void hkpLimitedHingeConstraintData_setMotorActive(void* info, bool enabled);
};
struct FUN_00cdf2f0 : Se5b160_Data {
    Se5b160_RagdollAtoms m_kBridgeAtoms;
    int unkec; int unkf0; int unkf4; int unkf8; int unkfc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; 
    FUN_00cdf2f0() throw();
    void hkpRagdollConstraintData_setTwistMotor(Se5b160_Motor* motor);
    void hkpRagdollConstraintData_setPlaneMotor(Se5b160_Motor* motor);
    void hkpRagdollConstraintData_setConeMotor(Se5b160_Motor* motor);
    void SetFlagAndClearFloats(void* info, bool enabled);
};
struct Se5b160_StrPtr {
    const char* m_pcText;
    const char* cString() const { return reinterpret_cast<const char*>(reinterpret_cast<unsigned int>(m_pcText) & ~1u); }
    void UpdateState_00cb0c10(const char* s);
};
struct Se5b160_Entity;
struct Se5b160_PrioEnum {
    unsigned char m_kStorage;
    operator hkpConstraintInstance::ConstraintPriority() const { return static_cast<hkpConstraintInstance::ConstraintPriority>(m_kStorage); }
};
struct FUN_00cf3ea0 : Se5b160_RefObj {
    int unk08;
    Se5b160_Data* m_data;
    int unk10;
    Se5b160_Entity* m_pEntityA;
    Se5b160_Entity* m_pEntityB;
    Se5b160_PrioEnum m_priority;
    unsigned char unk1d;
    unsigned short unk1e;
    int unk20;
    int unk24;
    Se5b160_StrPtr m_name;
    int unk2c; int unk30; int unk34;
    FUN_00cf3ea0(Se5b160_Entity* a, Se5b160_Entity* b, Se5b160_Data* data, hkpConstraintInstance::ConstraintPriority priority) throw();
    hkpConstraintInstance::ConstraintPriority getPriority() const { return m_priority; }
    Se5b160_Entity* getEntityA() const { return m_pEntityA; }
    Se5b160_Entity* getEntityB() const { return m_pEntityB; }
};
typedef FUN_00cf3ea0 Se5b160_Instance;
Se5b160_Instance* __cdecl CreatePoweredConstraint(const Se5b160_Instance* __restrict original, Se5b160_Motor* motor, bool enableMotors);
struct S00e51a60_BlockDesc {
    unsigned int m_uiFirstQuantizationParameter;
    unsigned int m_uiBlockOffset;
    unsigned int m_ucSecondQuantizationParameter;
};
unsigned int __cdecl DecodeBlock(const unsigned char* encodedData, S00e51a60_BlockDesc& desc, unsigned char* rawData, unsigned int rawDataSizeBytes);
struct E5B130Object {
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
    Ref* items[3];
    void ProcessAndReturnValue_00d85ba0(int finishFlags);
};
static void _copyAtoms_00e5b130(E5B130Object* object, int finishFlags);
E5B130Object* volatile g_finishObject;
volatile int g_finishFlags;
void CallFinishObject();
// hkMoppUsingFloatAabbVirtualMachine_queryPlanesOptimized (hkpMoppMachine.cpp)
// with hkpMoppUsingFloatAabbVirtualMachine<...>::QueryAabbPrimitives and
extern "C" __declspec(align(16)) const unsigned int DAT_01017d10[4];
// setAbs4 absMask
__forceinline float& hkVector4::operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
__forceinline const float& hkVector4::operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
__forceinline void hkVector4::set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
__forceinline void hkVector4::setAll3(float a) { m_vComponents = _mm_set_ps1(a); }
__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline void hkVector4::setAbs4(const hkVector4& v)
{
    m_vComponents = _mm_and_ps(v.m_vComponents, *(const __m128*)&DAT_01017d10);
}
__forceinline void hkVector4::_setMul4(const hkMatrix3& r, const hkVector4& v) { _setMul3(r, v); }
__forceinline void hkVector4::_setMul3(const hkMatrix3& a, const hkVector4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    const __m128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    const __m128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    const __m128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

namespace S00e5d070 {

typedef float hkReal;
typedef __m128 hkQuadReal;

static __forceinline hkVector4& planeColumn(hkTransform& transform, int index)
{
    return reinterpret_cast<hkVector4*>(&transform)[index];
}
static __forceinline void setPlaneRows(hkTransform& transform, const hkVector4& r0, const hkVector4& r1, const hkVector4& r2, const hkVector4& r3)
{
    planeColumn(transform, 0).set(r0(0), r1(0), r2(0), r3(0));
    planeColumn(transform, 1).set(r0(1), r1(1), r2(1), r3(1));
    planeColumn(transform, 2).set(r0(2), r1(2), r2(2), r3(2));
    planeColumn(transform, 3).set(r0(3), r1(3), r2(3), r3(3));
}

struct hkpMoppPrimitiveInfoArray;

struct PlaneArrayDescriptor
{
    int m_iValue;
    const hkVector4* m_kPlaneArray;
};

class MoppPrimitiveQueryContext
{
public:
    hkpMoppPrimitiveInfoArray* m_pPrimitiveInfoArray;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    __forceinline void initQuery(hkpMoppPrimitiveInfoArray* primitives_out) { m_pPrimitiveInfoArray = primitives_out; }
};

class MoppPlaneQueryData : public MoppPrimitiveQueryContext
{
public:
    int m_iValue;
    hkTransform m_kPlaneArray[8];
    hkTransform m_absPlanes[8];

    __forceinline void initializeQueryObject(const PlaneArrayDescriptor& input, const hkpMoppCode* code)
    {
        int numPlanes4 = input.m_iValue & ~3;
        hkTransform* planes = &m_kPlaneArray[0];
        const hkVector4* p = input.m_kPlaneArray;
        m_iValue = 0;
        int i;
        for (i = 0; i < numPlanes4; i += 4)
        {
            setPlaneRows(*planes, p[0], p[1], p[2], p[3]);
            planes++;
            m_iValue++;
            p += 4;
        }
        {
            const hkVector4* p0 = p;
            const hkVector4* p1 = p + 1;
            const hkVector4* p2 = p + 2;
            const hkVector4* p3 = p + 3;
            switch (input.m_iValue - i)
            {
            case 1:
                p1 = p0;
            case 2:
                p2 = p0;
            case 3:
                p3 = p0;
                setPlaneRows(*planes, *p0, *p1, *p2, *p3);
                planes++;
                m_iValue++;
            default:
                break;
            }
        }
        hkTransform* absPlanes = &m_absPlanes[m_iValue];
        absPlanes--;
        planes--;
        while (planes >= &m_kPlaneArray[0])
        {
            planeColumn(*absPlanes, 0).setAbs4(planeColumn(*planes, 0));
            planeColumn(*absPlanes, 1).setAbs4(planeColumn(*planes, 1));
            planeColumn(*absPlanes, 2).setAbs4(planeColumn(*planes, 2));
            planeColumn(*absPlanes, 3).setZero4();
            hkVector4 offset;
            offset._setMul4(*reinterpret_cast<const hkMatrix3*>(planes), reinterpret_cast<const hkVector4&>(code->m_info.m_offset));
            planeColumn(*planes, 3).add4(offset);
            planeColumn(*planes, 3).add4(planeColumn(*planes, 3));
            planes--;
            absPlanes--;
        }
    }
};

class hkpMoppUsingFloatAabbVirtualMachine
{
public:
    struct MachineVectorIndexRecord
    {
        int m_uiPropertyCount;
        int m_kProperties[1];
        int m_iFirstPostRadiusValue;
        int m_iSecondPostRadiusValue;
        int m_iThirdPostRadiusValue;
        int m_iIndex;
    };
    struct AxisAlignedBoundingBoxWrapper : public hkAabb {};

    hkpMoppPrimitiveInfoArray* m_pPrimitiveInfoArray;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    hkReal m_ReciprocalScale;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    MoppPlaneQueryData m_kSphereQueryObject;

    __forceinline void initQuery(hkpMoppPrimitiveInfoArray* primitives_out) { m_pPrimitiveInfoArray = primitives_out; }

    void ProcessEntries_00e5d7d0(const MachineVectorIndexRecord* query, const unsigned char* PC, AxisAlignedBoundingBoxWrapper& aabb);

    __forceinline void QueryAabbPrimitives(const hkpMoppCode* code, const PlaneArrayDescriptor& input,
                                 hkpMoppPrimitiveInfoArray* primitives_out, hkpMoppPrimitiveInfoArray* hits)
    {
        const unsigned char* PC = &code->m_data.m_data[0];
        initQuery(primitives_out);
        // Both corners are initialized below; avoid an out-of-line default constructor.
        __declspec(align(16)) unsigned char aabbStorage[sizeof(AxisAlignedBoundingBoxWrapper)];
        AxisAlignedBoundingBoxWrapper& aabb = *reinterpret_cast<AxisAlignedBoundingBoxWrapper*>(aabbStorage);
        m_ReciprocalScale = 1.0f / reinterpret_cast<const float*>(&code->m_info.m_offset)[3];
        MachineVectorIndexRecord query;
        query.m_iFirstPostRadiusValue = 0;
        query.m_iSecondPostRadiusValue = 0;
        query.m_iThirdPostRadiusValue = 0;
        query.m_iIndex = 16;
        query.m_uiPropertyCount = 0;
        for (int i = 0; i < 1; i++)
        {
            query.m_kProperties[i] = 0;
        }
        aabb.m_kMinimumCorner.m_vComponents = _mm_setzero_ps();
        hkReal size = m_ReciprocalScale * 16777216.0;
        aabb.m_kMaximumCorner.m_vComponents = _mm_set_ps1(size);
        m_kSphereQueryObject.initializeQueryObject(input, code);
        m_kSphereQueryObject.m_pPrimitiveInfoArray = hits;
        ProcessEntries_00e5d7d0(&query, PC, aabb);
    }
};

}
void __cdecl hkpMoppCode_UpdateState_00e5d070(const hkpMoppCode* code, const S00e5d070::PlaneArrayDescriptor& input, S00e5d070::hkpMoppPrimitiveInfoArray* primitives_out, S00e5d070::hkpMoppPrimitiveInfoArray* hits);
static __forceinline int moppHighLast(int middle,const volatile unsigned char& high,const volatile unsigned char& last){middle+=int(high)<<8;return(middle<<8)+last;}
static __forceinline int moppRead24(const unsigned char* p) { int middle = p[1]; middle += int(p[0]) << 8; return (middle << 8) + p[2]; }
extern "C" int _mm_movemask_ps(__m128);
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" __m128 _mm_load_ps(const float*);
struct MoppState {
    int terminalBase;
    int properties[1];
    int origin[3];
    int shift;
};
struct __declspec(align(16)) MoppBox { float low[4]; float high[4];
    __forceinline MoppBox& operator=(const MoppBox& b) { *(__m128*)low = *(const __m128*)b.low; *(__m128*)high = *(const __m128*)b.high; return *this; }
};
struct MoppPlaneBlock { __m128 x, y, z, w; };
struct MoppPlaneSet {
    int unk00, unk04, unk08, unk0c;
    int count, unk14, unk18, unk1c;
    MoppPlaneBlock planes[8];
    MoppPlaneBlock absolutePlanes[8];
    void queryOnTree(const MoppState*, const unsigned char*);
    __forceinline int test(const MoppBox& box, const MoppState* state, const unsigned char* code) {
        int inside = 15;
        const MoppPlaneBlock* plane = planes;
        __m128 sum = _mm_add_ps(*(const __m128*)box.high, *(const __m128*)box.low);
        __m128 difference = _mm_sub_ps(*(const __m128*)box.high, *(const __m128*)box.low);
        const MoppPlaneBlock* absolutePlane = absolutePlanes;
        int n = count - 1;
        for (; n >= 0; --n) {
            __m128 sx = _mm_shuffle_ps(sum, sum, 0);
            __m128 sy = _mm_shuffle_ps(sum, sum, 0x55);
            __m128 sz = _mm_shuffle_ps(sum, sum, 0xaa);
            __m128 dx = _mm_shuffle_ps(difference, difference, 0);
            __m128 dy = _mm_shuffle_ps(difference, difference, 0x55);
            __m128 dz = _mm_shuffle_ps(difference, difference, 0xaa);
            __m128 radius = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(absolutePlane->x.m128_f32), dx), _mm_mul_ps(_mm_load_ps(absolutePlane->y.m128_f32), dy)),
                _mm_mul_ps(_mm_load_ps(absolutePlane->z.m128_f32), dz));
            __m128 distance = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(plane->y.m128_f32), sy), _mm_mul_ps(_mm_load_ps(plane->x.m128_f32), sx)),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(plane->z.m128_f32), sz), _mm_load_ps(plane->w.m128_f32)));
            if (_mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(distance, radius), _mm_setzero_ps())) != 15)
                return 0;
            inside &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(distance, radius), _mm_setzero_ps()));
            ++plane;
            ++absolutePlane;
        }
        if (inside == 15) {
            queryOnTree(state, code);
            return 1;
        }
        return 2;
    }
};
struct MoppOutput { int* data; int size; int capacity; };
struct MoppMemorySystem { int unk00, unk04, unk08, unk0c; void* allocator; };
void __cdecl ResizeAudioStream(void*, void*, int);
struct MoppErrorSink {
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual int __declspec(nothrow) report(int, unsigned, const char*, const char*, int);
};
struct MoppErrorStream {
    int unk00, unk04, unk08;
    void __declspec(nothrow) init(char*, int);
    void __declspec(nothrow) close();
    void __declspec(nothrow) text(const char*);
};
struct MoppMachine {
    MoppOutput* output;
    int unk04, unk08, unk0c;
    float scale;
    int unk14, unk18, unk1c;
    MoppPlaneSet planeSet;
    void ProcessEntries_00e5d7d0(const MoppState*, const unsigned char*, MoppBox*);
};

typedef float hkReal;
typedef unsigned int hkUint32;
typedef __m128 hkQuadReal;

extern const hkQuadReal DAT_010c7160;
extern const hkQuadReal DAT_010ec7f0;

inline hkSimdReal::hkSimdReal() {}
inline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x) {}
inline hkSimdReal::hkSimdReal(float x) { m_vValue = _mm_load_ss(&x); }
inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline __m128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
__forceinline const __m128& hkSimdReal::getQuad() const { return m_vValue; }

typedef const hkSimdReal& hkSimdRealParameter;

inline hkSimdReal operator-(hkSimdRealParameter r)
{
    hkSimdReal value;
    value.m_vValue = _mm_sub_ss(DAT_010c7160, r.getQuad());
    return value;
}

inline hkVector4::hkVector4(const hkVector4& v) { m_vComponents = v.m_vComponents; }
inline void hkVector4::operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
inline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter _t)
{
    hkQuadReal t = _t.broadcast();
    hkQuadReal s = _mm_sub_ps(DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}
inline hkQuaternion::hkQuaternion() {}
inline void hkQuaternion::operator=(const hkQuaternion& q)
{
    *reinterpret_cast<hkQuadReal*>(this) = *reinterpret_cast<const hkQuadReal*>(&q);
}
inline const hkVector4& hkQuaternion::getImag() const
{
    return *reinterpret_cast<const hkVector4*>(this);
}
__forceinline hkQsTransform::hkQsTransform() {}
__forceinline hkQsTransform::hkQsTransform(const hkQsTransform& t)
{
    m_vTranslation = t.m_vTranslation;
    m_rotation = t.m_rotation;
    m_vScale = t.m_vScale;
}
// The shared scalar declares both value and reference constructors. Build its
// SIMD representation directly to avoid ambiguous constructor overloads.
static __forceinline hkSimdReal scalarValue(float x)
{
    hkSimdReal r;
    r.m_vValue = _mm_load_ss(&x);
    return r;
}
static __forceinline hkSimdReal quadValue(const hkQuadReal& x)
{
    hkSimdReal r;
    r.m_vValue = x;
    return r;
}
static inline hkSimdReal quaternionDot4(const hkVector4& kQ, const hkVector4& kR)
{
    hkQuadReal vProd = _mm_mul_ps(kQ.m_vComponents, kR.m_vComponents);
    hkQuadReal vPairs = _mm_add_ps(_mm_shuffle_ps(vProd, vProd, _MM_SHUFFLE(1, 0, 3, 2)), vProd);
    hkQuadReal vSwapped = _mm_shuffle_ps(vPairs, vPairs, _MM_SHUFFLE(2, 3, 0, 1));
    return quadValue(_mm_add_ps(vPairs, vSwapped));
}
__forceinline void hkQsTransform::setInterpolate4(const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t)
{
    m_vScale.setInterpolate4(a.m_vScale, b.m_vScale, t);
    m_vTranslation.setInterpolate4(a.m_vTranslation, b.m_vTranslation, t);
    const hkReal oneMinusT = 1.0f - hkReal(t);
    const hkReal signedT = (quaternionDot4(a.m_rotation.getImag(), b.m_rotation.getImag()) < 0.0f) ? -t : t;
    __declspec(align(16)) hkQuaternion out;
    *reinterpret_cast<hkQuadReal*>(&out) = _mm_add_ps(
        _mm_mul_ps(scalarValue(oneMinusT).broadcast(), a.m_rotation.getImag().m_vComponents),
        _mm_mul_ps(scalarValue(signedT).broadcast(), b.m_rotation.getImag().m_vComponents));
    out.normalize_005611c0();
    m_rotation = out;
}

// @fnv 0x00e41bf0
// src: GUESS 0x00e41bf0 (confidence: low)
hkQsTransform hkQsTransform_UpdateState_00e41bf0(hkReal time, const hkQsTransform* keys, hkUint32 numKeys, hkReal duration)
{
    const hkUint32 lastKey = numKeys - 1;
    const hkReal frame = time / duration * (hkReal)lastKey;
    const hkUint32 index = (hkUint32)frame;
    if (index > lastKey - 1)
    {
        return keys[lastKey];
    }
    const hkReal delta = frame - (hkReal)index;
    hkQsTransform result;
    result.setInterpolate4(keys[index], keys[index + 1], scalarValue(delta));
    return result;
}

extern const __m128 DAT_010ec7f0, DAT_010ec850, DAT_010ec840, DAT_010ec830, DAT_010ec820, DAT_010ec810, DAT_010ec7b0;
extern const __m128 DAT_010ec800;
extern const __m128 C10, C14, C17;
extern const __m128 DAT_010ec7d0, DAT_010ec7c0, DAT_010ec790;
extern const __m128 DAT_010ec7e0;
extern const __m128 DAT_010ec7a0;

void __cdecl hkUpdateReflect(float, float*, const float*, int);
void __cdecl AccumulateNeighborSum(float, const float*, float*, int);
void __cdecl hkMergeOddEven(float*, float*, int);

class WaveScalar {
    __m128 q;
public:
    WaveScalar(float value) { q = _mm_load_ss(&value); }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(q,q,0); }
};
struct WaveVector {
private:
    __m128 q;
public:
    __forceinline void splat(float value) { q = _mm_set_ps1(value); }
    __forceinline __m128& quad() { return q; }
    __forceinline void accumulate(const WaveScalar& value, const WaveVector& coefficients) {
        q = _mm_add_ps(q, _mm_mul_ps(value.broadcast(),coefficients.q));
    }
    __forceinline float& lane(int index) { return reinterpret_cast<float*>(&q)[index]; }
    __forceinline operator __m128() const { return q; }
};

// @fnv 0x00e51140
// src: XBOX_PDB 0x00e51140
extern "C" void __cdecl hkInverseWaveletTransform(float* data, unsigned int count) {
    static const __m128 rowsA[8] = {DAT_010ec7f0,DAT_010ec850,DAT_010ec840,DAT_010ec830,DAT_010ec820,DAT_010ec810,DAT_010ec800,DAT_010ec7b0};
    static const __m128 rowsB[8] = {C10,DAT_010ec7e0,DAT_010ec7d0,DAT_010ec7c0,C14,DAT_010ec7a0,DAT_010ec790,C17};
    {
        WaveVector sumA, sumB, termA, termB;
        sumA.splat(data[0]);
        sumB.splat(data[0]);
        for (int j=1; j<8; ++j) {
            termA.quad()=rowsA[j];
            termB.quad()=rowsB[j];
            sumA.accumulate(data[j],termA);
            sumB.accumulate(data[j],termB);
        }
        data[0]=sumA.lane(0); data[1]=sumA.lane(1); data[2]=sumA.lane(2); data[3]=sumA.lane(3);
        float* lower=data+4;
        lower[0]=sumB.lane(0); lower[1]=sumB.lane(1); lower[2]=sumB.lane(2); lower[3]=sumB.lane(3);
    }
    unsigned int span=8;
    while (span<count) {
        float* scale=data;
        float* detail=data+span;
        hkUpdateReflect(-0.25f,scale,detail,span);
        AccumulateNeighborSum(0.5f,scale,detail,span);
        span<<=1;
        hkMergeOddEven(data,data,span);
    }
}

#include <math.h>
#include <xmmintrin.h>
class hkClass;
namespace VehicleFrictionApply {
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned int hkUint32;
typedef unsigned __w64 hk_size_t;
class hkBoolR
{
public:
typedef char CompileTimeTrueType;
inline hkBoolR()
{
}
inline hkBoolR(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
#include "../../include/hkEnum.h"
using ::hkEnum;
typedef ::__m128 hkQuadReal;
typedef const hkVector4&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;__forceinline void hkSimdReal_store(hkSimdRealParameter a,float*f)
{
(_mm_store_ss)(f,a.getQuad());
}
inline hkSimdReal __cdecl operator+(hkSimdRealParameter r,hkSimdRealParameter s)
{
return (_mm_add_ss)(r.getQuad(),s.getQuad());
}
namespace MathUtilities
{
inline hkReal __cdecl sqrt(hkReal r){return::sqrtf(r);}
inline hkReal __cdecl fabs(hkReal r){return::fabsf(r);}
inline hkBoolR __cdecl equal(hkReal x,hkReal y,hkReal tolerance2=1e-5f)
{
return MathUtilities::fabs(x-y)<tolerance2;
}
template<typename T>
inline T __cdecl max2(T x,T y)
{
return x>y ? x:y;
}
template<typename T>
inline T __cdecl min2(T x,T y)
{
return x<y ? x:y;
}
template<typename T>
inline T __cdecl clamp(T x,T mi,T ma)
{
if(x<mi)return mi;
if(x>ma)return ma;
return x;
}
}

} // namespace VehicleFrictionApply

__forceinline void hkVector4::add4(const hkVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }


__forceinline void hkVector4::add3clobberW(const hkVector4&v)
{
m_vComponents=(_mm_add_ps)(m_vComponents,v.m_vComponents);
}
__forceinline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=(_mm_add_ps)(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4::sub3clobberW(const hkVector4&v)
{
m_vComponents=(_mm_sub_ps)(m_vComponents,v.m_vComponents);
}
__forceinline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=(_mm_sub_ps)(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4::mul4(const hkVector4&v)
{
m_vComponents=(_mm_mul_ps)(m_vComponents,v.m_vComponents);
}
__forceinline void hkVector4::setMul4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=(_mm_mul_ps)(a.m_vComponents,b.m_vComponents);
}
__forceinline void hkVector4::setMul4(const hkSimdReal& r,const hkVector4&v1)
{
m_vComponents=(_mm_mul_ps)(r.broadcast(),v1.m_vComponents);
}
__forceinline void hkVector4::setCross(const hkVector4&v0,const hkVector4&v1)
{
__m128 cross0;
cross0=(_mm_mul_ps)(
(_mm_shuffle_ps)(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
(_mm_shuffle_ps)(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
__m128 cross1;
cross1=(_mm_mul_ps)(
(_mm_shuffle_ps)(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
(_mm_shuffle_ps)(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=(_mm_sub_ps)(cross0,cross1);}

__forceinline void hkVector4::_setRotatedDir(const hkRotation&r,const hkVector4&v)
{
_setMul3(*reinterpret_cast<const hkMatrix3*>(&r),v);
}
__forceinline hkSimdReal hkVector4::horizontalAdd3()const
{
__m128 xySum=(_mm_add_ss)((_mm_shuffle_ps)(m_vComponents,m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),m_vComponents);
return (_mm_add_ss)((_mm_shuffle_ps)(m_vComponents,m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);
}
__forceinline hkSimdReal hkVector4::horizontalAdd4()const
{
__m128 sum0=(_mm_add_ps)((_mm_shuffle_ps)(m_vComponents,m_vComponents,(((1)<<6)|((0)<<4)|((3)<<2)|((2)))),m_vComponents);
__m128 sum1=(_mm_shuffle_ps)(sum0,sum0,(((2)<<6)|((3)<<4)|((0)<<2)|((1))));
return (_mm_add_ps)(sum0,sum1);}
__forceinline void hkVector4::setW(const hkVector4&w)
{
m_vComponents=(_mm_shuffle_ps)(m_vComponents,(_mm_unpackhi_ps)(m_vComponents,w.m_vComponents),(((3)<<6)|((0)<<4)|((1)<<2)|((0))));
}
__forceinline void hkVector4::setBroadcast(const hkVector4&v,int i)
{
if(i==0)
{
m_vComponents=(_mm_shuffle_ps)(v.m_vComponents,v.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
else if(i==1)
{
m_vComponents=(_mm_shuffle_ps)(v.m_vComponents,v.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
}
else if(i==2)
{
m_vComponents=(_mm_shuffle_ps)(v.m_vComponents,v.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
}
else if(i==3)
{
m_vComponents=(_mm_shuffle_ps)(v.m_vComponents,v.m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
__forceinline void hkVector4::setBroadcast3clobberW(const hkVector4&v,int i)
{
setBroadcast(v,i);
}

namespace VehicleFrictionApply {
namespace HavokMatrixMath
{
extern "C" inline hkBoolR __cdecl InvertMatrix2x2(const hkReal*m,hkReal*out,hkReal tolerance);}
hkBoolR __cdecl HavokMatrixMath::InvertMatrix2x2(const hkReal*m,hkReal*out,hkReal tolerance)
{
const hkReal*co0=m;
const hkReal*co1=co0+2;
hkReal D=(co0[0]*co1[1])-(co0[1]*co1[0]);
if(D*D<tolerance*tolerance){
return false;
}
hkReal DI=1.0f/D;
hkReal a1=co1[1]*DI;
hkReal b1=-co0[1]*DI;
hkReal a2=-co1[0]*DI;
hkReal b2=co0[0]*DI;
hkReal*o_co0=out;
hkReal*o_co1=o_co0+2;
o_co0[0]=a1;
o_co1[0]=b1;
o_co0[1]=a2;
o_co1[1]=b2;return true;}
namespace hkVector4Util_S
{
__forceinline void __cdecl reserveRegisters(hkUint32 registerMask);
__forceinline void __cdecl releaseRegisters(hkUint32 registerMask);}
__forceinline void __cdecl hkVector4Util_S::reserveRegisters(hkUint32 registerMask)
{
}
__forceinline void __cdecl hkVector4Util_S::releaseRegisters(hkUint32 registerMask)
{
}
struct TimeStepInfo
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
float m_fTimeStep;
float m_fInverseDeltaTime;};

class QuantizedBoundsData
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
enum RigidBodyType
{
HK_RIGID_BODY,
HK_KEYFRAMED_RIGID_BODY,
HK_NO_GRAVITY_RIGID_BODY,
HK_END
};
hkEnum<RigidBodyType,hkUint8>m_type;
hkReal m_fGravityFactor;
hkVector4 m_vLinearVelocity;
hkVector4 m_vAngularVelocity;
hkVector4 m_vInverseInertiaAndMass;
hkVector4&getCenterOfMassInWorld(){return getScratch0();}
const hkVector4&getCenterOfMassInWorld()const{return getScratch0();}
hkRotation&getCoreFromWorldMatrix(){return m_kCoreFromWorldMatrix;}
const hkRotation&getCoreFromWorldMatrix()const{return m_kCoreFromWorldMatrix;}
hkVector4&getScratch0(){return m_vCenterOfMass;}
const hkVector4&getScratch0()const{return m_vCenterOfMass;}
const hkVector4&getScratch1()const{return reinterpret_cast<const hkVector4&>(m_kCoreFromWorldMatrix.m_kColumn0);}
public:
hkVector4 m_vCenterOfMass;
hkRotation m_kCoreFromWorldMatrix;
public:
__forceinline void setFixed()
{
m_type=QuantizedBoundsData::HK_KEYFRAMED_RIGID_BODY;
m_fGravityFactor=0.0f;
this->m_vInverseInertiaAndMass.setZero4();
this->m_vLinearVelocity.setZero4();
this->m_vAngularVelocity.setZero4();
this->getCenterOfMassInWorld().setZero4();
m_kCoreFromWorldMatrix.m_kColumn0.m_vComponents = _mm_setzero_ps();
m_kCoreFromWorldMatrix.m_kColumn1.m_vComponents = _mm_setzero_ps();
m_kCoreFromWorldMatrix.m_kColumn2.m_vComponents = _mm_setzero_ps();
}
};
struct VehicleAxleParameters
{
hkVector4 m_kFirstVector;
hkVector4 m_kSecondAxleVector;
hkVector4 m_kThirdVector;
class QuantizedBoundsData*m_pFirstPointer;
class QuantizedBoundsData*m_pSecondPointer;
hkReal m_fFirstScalar;
hkReal m_fSecondScalar;
hkReal m_fThirdValue;
hkReal m_fFourthValue;
hkReal m_fFifthScalar;
hkReal m_fSixthValue;
hkUint8 m_ucValue;};
struct VehicleSimulationData
{
VehicleAxleParameters m_akAxleParams[2];
hkReal m_fTorquePitchFactor;
class QuantizedBoundsData m_pChassisCollidable;
class QuantizedBoundsData m_kSecondAccumulator;};
struct FloatRecord
{
union
{
hkReal m_fAccumulatedImpulse;
hkReal m_fSecondUnionFloat;
hkReal m_fAccumulatedMotorRhs;
};};struct __declspec(align(16))hkVec4F{float x,y,z,w;};
static __forceinline hkVector4&H(hkVec4F&v){return*(hkVector4*)&v;}
static __forceinline const hkVector4&H(const hkVec4F&v){return*(const hkVector4*)&v;}
struct ConstraintJacobian
{
hkVec4F m_kLinearJacobian;
hkVec4F m_angular0;
hkVec4F m_angular1;
__forceinline void setInvJacDiag(hkReal v){m_angular0.w=v;}
__forceinline hkReal getInvJacDiag()const{return m_angular0.w;}
__forceinline void setUserValue(hkReal v){m_angular1.w=v;}
__forceinline hkReal getUserValue()const{return m_angular1.w;}
__forceinline hkReal getDiag(const QuantizedBoundsData&mA,const QuantizedBoundsData&mB)const
{
const ConstraintJacobian*jac=this;
hkVector4 ang0;ang0.setMul4(H(jac->m_angular0),H(jac->m_angular0));
hkVector4 ang1;ang1.setMul4(H(jac->m_angular1),H(jac->m_angular1));
ang0.mul4(mA.m_vInverseInertiaAndMass);
ang1.mul4(mB.m_vInverseInertiaAndMass);
ang0.add4(ang1);
hkVector4 sm;sm.setAdd4(mA.m_vInverseInertiaAndMass,mB.m_vInverseInertiaAndMass);
ang0.setW(sm);
const hkReal dot=ang0.horizontalAdd4();
return dot+1.192092896e-07F;
}
__forceinline hkReal getNonDiagOptimized(const QuantizedBoundsData&mA,const QuantizedBoundsData&mB,const ConstraintJacobian&jacB)const
{
const ConstraintJacobian*jacA=this;
hkVector4 lin;lin.setMul4(H(jacB.m_kLinearJacobian),H(jacA->m_kLinearJacobian));
hkVector4 ang0;ang0.setMul4(H(jacA->m_angular0),H(jacB.m_angular0));
hkVector4 ang1;ang1.setMul4(H(jacA->m_angular1),H(jacB.m_angular1));
hkVector4 mA3;mA3.setBroadcast3clobberW(mA.m_vInverseInertiaAndMass,3);
hkVector4 mB3;mB3.setBroadcast3clobberW(mB.m_vInverseInertiaAndMass,3);
hkVector4 lin0;lin0.setMul4(mA3,lin);
hkVector4 lin1;lin1.setMul4(mB3,lin);
ang0.mul4(mA.m_vInverseInertiaAndMass);
ang1.mul4(mB.m_vInverseInertiaAndMass);
lin0.add4(lin1);
ang0.add4(ang1);
ang0.add4(lin0);
const hkReal d=ang0.horizontalAdd3();
return d;
}
__forceinline hkReal getNonDiagSameObjects(const QuantizedBoundsData&mA,const QuantizedBoundsData&mB,const ConstraintJacobian&jacB)const
{
return getNonDiagOptimized(mA,mB,jacB);
}
__forceinline hkReal getNonDiagDifferentObjects(const QuantizedBoundsData&mA,const ConstraintJacobian&jacB)const
{
const ConstraintJacobian*jacA=this;
hkVector4 lin;lin.setMul4(H(jacA->m_kLinearJacobian),H(jacB.m_kLinearJacobian));
hkVector4 ang0;ang0.setMul4(H(jacA->m_angular0),H(jacB.m_angular0));
hkVector4 mA3;mA3.setBroadcast(mA.m_vInverseInertiaAndMass,3);
hkVector4 lin0;lin0.setMul4(mA3,lin);
ang0.mul4(mA.m_vInverseInertiaAndMass);
ang0.add4(lin0);
const hkReal d=ang0.horizontalAdd3();
return d;
}
};
struct ConstraintJacobianData
{
ConstraintJacobian m_kFirstConstraintJacobian;
ConstraintJacobian m_kSecondConstraintJacobian;
hkReal m_fScalar1;
hkReal m_fScalar2;
hkReal m_fThirdScalar;
hkReal m_fFourthScalar;
hkReal m_fScalar5;
hkReal m_fSixthScalar;
hkReal m_fSeventhScalar;
hkReal m_fEighthScalar;
hkReal m_fTenthScalar;
hkReal m_fNinthScalar;
hkReal m_fTwelfthScalar;
hkReal m_fThirteenthScalar;
hkReal m_fFourteenthScalar;
hkReal m_fFifteenthScalar;
hkReal m_fEleventhScalar;};
namespace QuantizedBoundsBuilder
{
__forceinline void initBuilder(const QuantizedBoundsData*opaA,const QuantizedBoundsData*opaB,hkReal rhsFactor)
{
hkVector4Util_S::reserveRegisters(0x0fff0000);
}
__forceinline void exitBuilder()
{
hkVector4Util_S::releaseRegisters(0x0fff0000);
}
__forceinline void flush()
{
}
__forceinline void buildLinearBegin(const QuantizedBoundsData*opaA,const QuantizedBoundsData*opaB,const hkVector4&position,const hkVector4&direction,hkReal invJacFactor,ConstraintJacobian&jac)
{
H(jac.m_kLinearJacobian)=direction;
hkVector4 massCenterRelative0;massCenterRelative0.setSub4(position,opaA->getCenterOfMassInWorld());
hkVector4 massCenterRelative1;massCenterRelative1.setSub4(position,opaB->getCenterOfMassInWorld());
hkVector4 cross0;cross0.setCross(massCenterRelative0,direction);
hkVector4 cross1;cross1.setCross(direction,massCenterRelative1);
H(jac.m_angular0)._setRotatedDir(opaA->getCoreFromWorldMatrix(),cross0);
H(jac.m_angular1)._setRotatedDir(opaB->getCoreFromWorldMatrix(),cross1);
hkReal a=jac.getDiag(*opaA,*opaB);
jac.setUserValue(a);
jac.setInvJacDiag(invJacFactor / a);
}
__forceinline void buildLinearEnd(ConstraintJacobian&jac)
{
}
__forceinline hkReal getNonDiagSameObjects(const QuantizedBoundsData*opaA,const QuantizedBoundsData*opaB,ConstraintJacobian&last,ConstraintJacobian&other)
{
return last.getNonDiagSameObjects(*opaA,*opaB,other);
}
__forceinline hkReal getNonDiagDifferentObjects(const QuantizedBoundsData*opaA,ConstraintJacobian&last,ConstraintJacobian&other)
{
return last.getNonDiagDifferentObjects(*opaA,other);
}
}
namespace HavokRegisterUtilities
{
__forceinline void loadFixedRegisters()
{
}
__forceinline void loadVelocityAccumulators(const QuantizedBoundsData&mA,const QuantizedBoundsData&mB)
{
hkVector4Util_S::reserveRegisters(0xffff0000);
}
__forceinline void storeVelocityAccumulators(QuantizedBoundsData&mA,QuantizedBoundsData&mB)
{
hkVector4Util_S::releaseRegisters(0xffff0000);
}
__forceinline void popVelocityAccumulators()
{
hkVector4Util_S::releaseRegisters(0xffff0000);
}
__forceinline hkSimdReal getVelocity(const ConstraintJacobian&jac,const QuantizedBoundsData&mA,const QuantizedBoundsData&mB)
{
hkVector4 c;c.setSub4(mA.m_vLinearVelocity,mB.m_vLinearVelocity);
hkVector4 a;a.setMul4(mA.m_vAngularVelocity,H(jac.m_angular0));
hkVector4 b;b.setMul4(mB.m_vAngularVelocity,H(jac.m_angular1));
c.mul4(H(jac.m_kLinearJacobian));
a.add4(b);
a.add4(c);
const hkSimdReal vel=a.horizontalAdd3();
return vel;
}
__forceinline void applyImpulse(hkSimdRealParameter imp,const ConstraintJacobian&jac,QuantizedBoundsData&mA,QuantizedBoundsData&mB,FloatRecord&sr)
{
hkVector4 impA;impA.setMul4(imp,mA.m_vInverseInertiaAndMass);
hkVector4 impB;impB.setMul4(imp,mB.m_vInverseInertiaAndMass);
hkVector4 impLinA;impLinA.setBroadcast3clobberW(impA,3);
hkVector4 negImpLinB;negImpLinB.setBroadcast3clobberW(impB,3);
impLinA.mul4(H(jac.m_kLinearJacobian));
negImpLinB.mul4(H(jac.m_kLinearJacobian));
mA.m_vLinearVelocity.add3clobberW(impLinA);
mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
impA.mul4(H(jac.m_angular0));
impB.mul4(H(jac.m_angular1));
hkSimdReal s=sr.m_fAccumulatedImpulse;
mA.m_vAngularVelocity.add3clobberW(impA);
mB.m_vAngularVelocity.add3clobberW(impB);
s=s+imp;
hkSimdReal_store(s,&sr.m_fAccumulatedImpulse);
}
}
extern "C" hkBoolR DAT_0126efb9;
extern "C" void ValidateHavokKeyCode(hkBoolR*);
inline void hkVehicleFrictionSolverCalcRelativeForces(const ConstraintJacobianData&axis,hkpVehicleFrictionStatus::AxisStatus&status)
{
status.m_fAxisStatusMetric8=axis.m_fNinthScalar*axis.m_fFifteenthScalar;
status.m_fAxisStatusMetric9=axis.m_fTenthScalar*axis.m_fFourteenthScalar;}
// src: HAVOK_LIB 0x00e59700
static __declspec(noinline)void hkVehicleFrictionSolverClipImpulse(const VehicleAxleParameters&apar,ConstraintJacobianData&atmp,const hkpVehicleFrictionDescription::AxisDescription&adesc,hkpVehicleFrictionStatus::AxisStatus&astatus)
{
const hkReal xs=atmp.m_fNinthScalar*atmp.m_fFifteenthScalar;
const hkReal ys=atmp.m_fTenthScalar*atmp.m_fFourteenthScalar;
hkReal restSideImpulse;
astatus.m_fAxisStatusMetric8=xs;{
hkReal x=adesc.m_fAxisFrictionTuning2*xs;
hkReal x1=0.0f;
hkReal y1=0.0f;
hkReal w1=0.0f;
int i=0;
hkReal y;
hkReal w0;
while(true)
{
y=adesc.m_afFrictionCurveSamples[i]*ys;
w0=x*x+y*y;
if(w0>1.0f ||++i>=16)
{
break;
}
x1=x;
y1=y;
w1=w0;
x=x*adesc.m_fAxisFrictionTuning1;
}
w0=MathUtilities::sqrt(w0)-1.0;
w1=MathUtilities::sqrt(w1)-1.0;
hkReal diff=w0-w1;
if(MathUtilities::equal(diff,0.0f,1.1920929e-7f))
{
diff=1.1920929e-7f;
}
const hkReal invDiff=1.0f / diff;
const hkReal a0=-w1*invDiff;
const hkReal a1=w0*invDiff;
const hkReal scaleX=MathUtilities::clamp(x*a0+x1*a1,-1.1f,1.1f);
const hkReal scaleY=MathUtilities::clamp(y*a0+y1*a1,-1.1f,1.1f);
const hkReal impX=scaleX*atmp.m_fThirteenthScalar;
const hkReal impY=scaleY*atmp.m_fTwelfthScalar;
restSideImpulse=atmp.m_fNinthScalar-impX;
atmp.m_fNinthScalar=impX;
atmp.m_fEleventhScalar=atmp.m_fTenthScalar-impY;
atmp.m_fTenthScalar=impY;
}
{
hkReal velOverGroundSqr=atmp.m_fScalar1*atmp.m_fScalar1+atmp.m_fThirdScalar*atmp.m_fThirdScalar;
if(MathUtilities::equal(velOverGroundSqr,0.0f,1.1920929e-7f))
{
velOverGroundSqr=1.1920929e-7f;
}
const hkReal velOverGroundSqrInv=1.0f / velOverGroundSqr;
const hkReal energyForward=atmp.m_fEleventhScalar*atmp.m_fEighthScalar*atmp.m_fTwelfthScalar;
const hkReal energySide=restSideImpulse*atmp.m_fSixthScalar*atmp.m_fThirteenthScalar;
const hkReal energySquare=energyForward*energyForward+energySide*energySide;
astatus.m_fAxisStatusMetric3=MathUtilities::sqrt(energySquare*velOverGroundSqrInv);
}
}
extern "C" double DAT_01032980;
inline float slipFloor(float y) { return DAT_01032980 > y ? 0.0001f : y; }
// @fnv 0x00e59a40
// src: GUESS 0x00e59a40 (confidence: low)
extern "C" __declspec(noinline) void __cdecl hkpVehicleFrictionDescription_ProcessEntries_00e59a40(const TimeStepInfo&stepInfo,const hkpVehicleFrictionDescription&descr,VehicleSimulationData&params,hkpVehicleFrictionStatus&status)
{
if(!DAT_0126efb9)
{
ValidateHavokKeyCode(&DAT_0126efb9);
if(!DAT_0126efb9)
{
return;
}
}
ConstraintJacobianData m_kAxisEndPoints[2];
float slidingMagnitude[2];
float massMatrix[4];
{
float nonDiag;
{
for(int a=0;a<2;a++)
{
VehicleAxleParameters*apar=&params.m_akAxleParams[a];
ConstraintJacobianData*atmp=&m_kAxisEndPoints[a];
hkpVehicleFrictionStatus::AxisStatus*astatus;
{
QuantizedBoundsData*opaA=&params.m_pChassisCollidable;
QuantizedBoundsData*opaB=apar->m_pFirstPointer;
QuantizedBoundsBuilder::initBuilder(opaA,opaB,0.0f);
QuantizedBoundsBuilder::buildLinearBegin(opaA,opaB,apar->m_kFirstVector,apar->m_kThirdVector,1.0f,atmp->m_kFirstConstraintJacobian);
QuantizedBoundsBuilder::buildLinearEnd(atmp->m_kFirstConstraintJacobian);
QuantizedBoundsBuilder::flush();
atmp->m_fEighthScalar=atmp->m_kFirstConstraintJacobian.getUserValue()+descr.m_kAxisDescriptions[a].m_fAxisFrictionTuning4;
atmp->m_fSeventhScalar=1.0f / atmp->m_fEighthScalar;
QuantizedBoundsBuilder::buildLinearBegin(opaA,opaB,apar->m_kFirstVector,apar->m_kSecondAxleVector,1.0f,atmp->m_kSecondConstraintJacobian);
QuantizedBoundsBuilder::buildLinearEnd(atmp->m_kSecondConstraintJacobian);
QuantizedBoundsBuilder::flush();
atmp->m_fScalar5=atmp->m_kSecondConstraintJacobian.getInvJacDiag();
atmp->m_fSixthScalar=atmp->m_kSecondConstraintJacobian.getUserValue();
QuantizedBoundsBuilder::exitBuilder();
}
astatus=&status.m_kAxisEndPoints[a];
{
QuantizedBoundsData*opaA=&params.m_kSecondAccumulator;
QuantizedBoundsData*opaB=apar->m_pSecondPointer;
HavokRegisterUtilities::loadVelocityAccumulators(*opaA,*opaB);
HavokRegisterUtilities::loadFixedRegisters();
const float forwardVel=HavokRegisterUtilities::getVelocity(atmp->m_kFirstConstraintJacobian,*opaA,*opaB);
const float sideVel=HavokRegisterUtilities::getVelocity(atmp->m_kSecondConstraintJacobian,*opaA,*opaB);
astatus->m_fAxisStatusMetric6+=sideVel;
astatus->m_fAxisStatusMetric7+=forwardVel;
HavokRegisterUtilities::popVelocityAccumulators();
}
}
}
{
QuantizedBoundsData*opaA=&params.m_pChassisCollidable;
QuantizedBoundsData*opaB=params.m_akAxleParams[0].m_pFirstPointer;
QuantizedBoundsBuilder::initBuilder(opaA,opaB,0.0f);
nonDiag=(opaB==params.m_akAxleParams[1].m_pFirstPointer)
? QuantizedBoundsBuilder::getNonDiagSameObjects(opaA,opaB,m_kAxisEndPoints[0].m_kSecondConstraintJacobian,m_kAxisEndPoints[1].m_kSecondConstraintJacobian)
:QuantizedBoundsBuilder::getNonDiagDifferentObjects(opaA,m_kAxisEndPoints[0].m_kSecondConstraintJacobian,m_kAxisEndPoints[1].m_kSecondConstraintJacobian);
QuantizedBoundsBuilder::exitBuilder();
}
massMatrix[0]=m_kAxisEndPoints[0].m_fSixthScalar;
massMatrix[3]=m_kAxisEndPoints[1].m_fSixthScalar;
massMatrix[1]=nonDiag;
massMatrix[2]=nonDiag;
}
HavokRegisterUtilities::loadFixedRegisters();
{
for(int a=0;a<2;a++)
{
ConstraintJacobianData*atmp=&m_kAxisEndPoints[a];
const float impulse=status.m_kAxisEndPoints[a].m_fAxisStatusMetric5;
if(impulse==0.0f)
{
continue;
}
QuantizedBoundsData*opaA=&params.m_pChassisCollidable;
QuantizedBoundsData*opaB=params.m_akAxleParams[a].m_pFirstPointer;
ConstraintJacobian*jac=&atmp->m_kFirstConstraintJacobian;
HavokRegisterUtilities::loadVelocityAccumulators(*opaA,*opaB);
{
FloatRecord sr;
sr.m_fAccumulatedImpulse=0.0f;
HavokRegisterUtilities::applyImpulse(impulse,*jac,*opaA,*opaB,sr);
}
HavokRegisterUtilities::storeVelocityAccumulators(*opaA,*opaB);
}
}
{
const float w0=params.m_akAxleParams[0].m_fFourthValue;
const float w1=params.m_akAxleParams[1].m_fFourthValue;
const float sum=w0+w1;
m_kAxisEndPoints[0].m_fFourthScalar=descr.m_kAxisDescriptions[0].m_fAxisFrictionTuning8*w0+descr.m_kAxisDescriptions[0].m_fAxisFrictionTuning9*sum;
m_kAxisEndPoints[1].m_fFourthScalar=descr.m_kAxisDescriptions[1].m_fAxisFrictionTuning8*w1+descr.m_kAxisDescriptions[1].m_fAxisFrictionTuning9*sum;
}
status.m_kAxisEndPoints[0].m_fAxisStatusMetric3=0.0f;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric3=0.0f;
{
for(int i=0;i<2;i++)
{
ConstraintJacobianData*atmp=&m_kAxisEndPoints[i];
VehicleAxleParameters*apar=&params.m_akAxleParams[i];
hkpVehicleFrictionStatus::AxisStatus*astatus=&status.m_kAxisEndPoints[i];
float forwardSlipForFriction;
float forwardForce;
float downImpulse;
{
QuantizedBoundsData*opaA=&params.m_pChassisCollidable;
QuantizedBoundsData*opaB=apar->m_pFirstPointer;
HavokRegisterUtilities::loadVelocityAccumulators(*opaA,*opaB);
{
ConstraintJacobian*jac=&atmp->m_kFirstConstraintJacobian;
atmp->m_fScalar1=HavokRegisterUtilities::getVelocity(*jac,*opaA,*opaB);
}
{
ConstraintJacobian*jac=&atmp->m_kSecondConstraintJacobian;
atmp->m_fThirdScalar=HavokRegisterUtilities::getVelocity(*jac,*opaA,*opaB);
}
atmp->m_fThirdScalar=astatus->m_fAxisStatusMetric6*0.25+atmp->m_fThirdScalar;
HavokRegisterUtilities::popVelocityAccumulators();
}
downImpulse=MathUtilities::fabs(atmp->m_fFourthScalar)*stepInfo.m_fTimeStep;
forwardForce=apar->m_fFifthScalar;
if(apar->m_ucValue)
{
const float wheelChassisMassRatio=atmp->m_fScalar5*atmp->m_fEighthScalar;
atmp->m_fScalar2=-atmp->m_fScalar1;
forwardSlipForFriction=atmp->m_fScalar2;
float extra=(astatus->m_fAxisStatusMetric7*0.5+atmp->m_fScalar1)*wheelChassisMassRatio*0.5;
float maxExtra=downImpulse*apar->m_fFirstScalar*atmp->m_fEighthScalar;
if(MathUtilities::fabs(extra)>maxExtra)
{
extra=(extra>0.0f)? maxExtra:-maxExtra;
}
atmp->m_fScalar2=atmp->m_fScalar2-extra;
forwardForce=0.0f;
}
else
{
astatus->m_fAxisStatusMetric7=0.0f;
atmp->m_fScalar2=status.m_kAxisEndPoints[i].m_fAxisStatusMetric1;
forwardSlipForFriction=atmp->m_fScalar2;
}
{
float friction=apar->m_fFirstScalar;
if(apar->m_fSecondScalar !=0.0f)
{
const float slipVelocitySquared=forwardSlipForFriction*forwardSlipForFriction+atmp->m_fThirdScalar*atmp->m_fThirdScalar;
const float slipVelocity=MathUtilities::sqrt(slipVelocitySquared);
friction=slipVelocity*apar->m_fSecondScalar+friction;
friction=MathUtilities::min2(friction,apar->m_fThirdValue);
friction=MathUtilities::max2(0.0f,friction);
}
atmp->m_fTwelfthScalar=downImpulse*friction;
atmp->m_fThirteenthScalar=atmp->m_fTwelfthScalar;
atmp->m_fFourteenthScalar=1.0f /(atmp->m_fThirteenthScalar+1.192092896e-07F);
atmp->m_fFifteenthScalar=atmp->m_fFourteenthScalar;
const float stopTheWheelFromSlidingImpulse=atmp->m_fScalar2*atmp->m_fSeventhScalar+stepInfo.m_fTimeStep*forwardForce;
atmp->m_fTenthScalar=stopTheWheelFromSlidingImpulse;
}
}
}
if(params.m_akAxleParams[0].m_fSixthValue+params.m_akAxleParams[1].m_fSixthValue>0.0f)
{
float totalDownForce=MathUtilities::fabs(params.m_akAxleParams[0].m_fFourthValue)+MathUtilities::fabs(params.m_akAxleParams[1].m_fFourthValue);
float sideAccelBase=totalDownForce*descr.m_fMaxVelocityForPositionalFriction;
float taus[2];
{
for(int a=0;a<2;a++)
{
float Z=sideAccelBase*stepInfo.m_fTimeStep;
float N=MathUtilities::max2(params.m_akAxleParams[a].m_fSixthValue,0.0f);
taus[a]=(Z>=N)? 1.0:Z / N;
taus[a]=slipFloor(taus[a]);
}
}
massMatrix[0]*=taus[0];
massMatrix[2]*=taus[1];
{
float f=MathUtilities::sqrt(taus[0]*taus[1]);
massMatrix[1]*=f;
massMatrix[3]*=f;
for(int a=0;a<2;a++)
{
ConstraintJacobianData*atmp=&m_kAxisEndPoints[a];
atmp->m_fScalar5=atmp->m_fScalar5*taus[a];
atmp->m_fSixthScalar=atmp->m_fSixthScalar / taus[a];
}
}
}
{
float invMassMatrix[4]={1.0f,0.0f,0.0f,1.0f};
{
hkBoolR success=HavokMatrixMath::InvertMatrix2x2(massMatrix,invMassMatrix,0.0f);
;
}
m_kAxisEndPoints[0].m_fNinthScalar=-(invMassMatrix[0]*m_kAxisEndPoints[0].m_fThirdScalar+invMassMatrix[1]*m_kAxisEndPoints[1].m_fThirdScalar);
m_kAxisEndPoints[1].m_fNinthScalar=-(invMassMatrix[2]*m_kAxisEndPoints[0].m_fThirdScalar+invMassMatrix[3]*m_kAxisEndPoints[1].m_fThirdScalar);
{
for(int a=0;a<2;a++)
{
ConstraintJacobianData*atmp=&m_kAxisEndPoints[a];
const float x=atmp->m_fTenthScalar*atmp->m_fFourteenthScalar;
const float y=atmp->m_fNinthScalar*atmp->m_fFifteenthScalar;
slidingMagnitude[a]=x*x+y*y;
}
}
}
if(MathUtilities::fabs(m_kAxisEndPoints[0].m_fScalar1)>=params.m_fTorquePitchFactor)
{
status.m_kAxisEndPoints[0].m_fAxisStatusMetric6=0.0f;
status.m_kAxisEndPoints[0].m_fAxisStatusMetric7=0.0f;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric6=0.0f;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric7=0.0f;
}
if(slidingMagnitude[0]>1.0f || slidingMagnitude[1]>1.0f)
{
int first_sliding;
int other;
if(slidingMagnitude[0]>1.0f)
{
float inv=1.0f / slidingMagnitude[0];
status.m_kAxisEndPoints[0].m_fAxisStatusMetric6*=inv;
status.m_kAxisEndPoints[0].m_fAxisStatusMetric7*=inv;
}
if(slidingMagnitude[1]>1.0f)
{
float inv=1.0f / slidingMagnitude[1];
status.m_kAxisEndPoints[1].m_fAxisStatusMetric6*=inv;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric7*=inv;
}
if(slidingMagnitude[0]>slidingMagnitude[1])
{
first_sliding=0;
other=1;
}
else
{
first_sliding=1;
other=0;
}
{
for(int i=0;i<2;i++)
{
ConstraintJacobianData*atmp=&m_kAxisEndPoints[first_sliding];
atmp->m_fNinthScalar=-atmp->m_fThirdScalar*atmp->m_fScalar5;
hkVehicleFrictionSolverClipImpulse(params.m_akAxleParams[first_sliding],*atmp,descr.m_kAxisDescriptions[first_sliding],status.m_kAxisEndPoints[first_sliding]);
m_kAxisEndPoints[other].m_fThirdScalar+=atmp->m_fNinthScalar*massMatrix[1];
first_sliding=other;
}
}
status.m_kAxisEndPoints[0].m_fAxisStatusMetric1=m_kAxisEndPoints[0].m_fEleventhScalar*m_kAxisEndPoints[0].m_fEighthScalar;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric1=m_kAxisEndPoints[1].m_fEleventhScalar*m_kAxisEndPoints[1].m_fEighthScalar;
status.m_kAxisEndPoints[0].m_fAxisStatusMetric2=m_kAxisEndPoints[0].m_fThirdScalar;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric2=m_kAxisEndPoints[1].m_fThirdScalar;
}
else
{
hkVehicleFrictionSolverCalcRelativeForces(m_kAxisEndPoints[0],status.m_kAxisEndPoints[0]);
hkVehicleFrictionSolverCalcRelativeForces(m_kAxisEndPoints[1],status.m_kAxisEndPoints[1]);
status.m_kAxisEndPoints[0].m_fAxisStatusMetric1=0.0f;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric1=0.0f;
status.m_kAxisEndPoints[0].m_fAxisStatusMetric2=0.0f;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric2=0.0f;
}
status.m_kAxisEndPoints[0].m_fAxisStatusMetric5=m_kAxisEndPoints[0].m_fTenthScalar;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric5=m_kAxisEndPoints[1].m_fTenthScalar;
status.m_kAxisEndPoints[0].m_fAxisStatusMetric4=m_kAxisEndPoints[0].m_fNinthScalar*stepInfo.m_fInverseDeltaTime;
status.m_kAxisEndPoints[1].m_fAxisStatusMetric4=m_kAxisEndPoints[1].m_fNinthScalar*stepInfo.m_fInverseDeltaTime;
{
for(int a=0;a<2;a++)
{
ConstraintJacobianData*atmp=&m_kAxisEndPoints[a];
QuantizedBoundsData*opaA=&params.m_pChassisCollidable;
QuantizedBoundsData*opaB=params.m_akAxleParams[a].m_pFirstPointer;
ConstraintJacobian*jac=&atmp->m_kSecondConstraintJacobian;
HavokRegisterUtilities::loadVelocityAccumulators(*opaA,*opaB);
{
FloatRecord sr;
sr.m_fAccumulatedImpulse=0.0f;
HavokRegisterUtilities::applyImpulse(atmp->m_fNinthScalar,*jac,*opaA,*opaB,sr);
}
HavokRegisterUtilities::storeVelocityAccumulators(*opaA,*opaB);
}
}
}

}
