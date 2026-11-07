#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../include/hkArray.h"
// src/staging/blk_00e40000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e40000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


#include "fnv_asm_helpers.h"
#include "../../include/hkpConstraintInstance.h"
#include "../../include/hkpConstraintData.h"
// src/staging/blk_00e40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/Actor.h"
#include "../../include/hkVector4.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/V4.h"
#include "../../include/hkBool.h"
#include "../../include/hkpRemoveTerminalsMoppModifier2.h"
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
class FUN_00e53160 {
public:
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;

    FUN_00e53160(float fX, float fY, float fZ, float fW);
};
struct FUN_00e53180_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e53180_cls(const float* pSrc);
};
struct FUN_00e531a0_struct {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;

    FUN_00e531a0_struct* ComputeValue_00e531a0(const FUN_00e531a0_struct* other);
};
// FUN_00e531d0: thiscall member of a 4-float vector; subtracts a vector
// (given by pointer/reference) from itself, in place, and returns itself.
struct FUN_00e531d0_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e531d0_cls* SubtractFourComponents(const float* pOther);
};
struct FUN_00e53200_cls {
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e53200_cls(float s);
};
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
    HkArray<Actor*> m_kActorEntries;

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
struct FUN_00e53180_Obj {
    float x;
    float y;
    float z;
    float w;
    void FUN_00e53180(const Float4* source);
};
void __cdecl hkaNURBS_CurvePoint_00e546e0(int a, int b, int c, int d, int count, float** inputs, FUN_00e53180_Obj** outputs);
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
namespace Components {
struct FUN_00e53160 {
    float x, y, z, w;
    __declspec(noinline) FUN_00e53160(float a, float b, float c, float d);
};
__declspec(noinline) FUN_00e53160::FUN_00e53160(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
}
struct ComponentVector {
    float x, y, z, w;
    Components::FUN_00e53160 hkaNURBS_Point_ceil() const;
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
#include <xmmintrin.h>
struct S00e58310_Allocator {
    virtual ~S00e58310_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T>
    inline T* _bufAlloc(int& reqNumInOut)
    {
        const int SIZE_ELEM = sizeof(T);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<T*>(p);
    }
    template <typename T>
    inline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
struct S00e58310_Router {
    int m_aiEntries;
    int m_pTemp;
    int m_pSolver;
    int m_pDebugAllocator;
    S00e58310_Allocator* m_pStreamAllocator;
    S00e58310_Allocator& heap() { return *m_pStreamAllocator; }
    static __forceinline S00e58310_Router& GetMonitorStream();
};
__forceinline S00e58310_Router& S00e58310_Router::GetMonitorStream()
{
    return *(S00e58310_Router*)hkMemoryRouter_getInstance();
}
struct S00e58310_HeapAllocator {
    S00e58310_Allocator& get(const void*) { return S00e58310_Router::GetMonitorStream().heap(); }
};
struct S00e58310_TypeIsPod {};
struct S00e58310_Util {
    template <typename T>
    static __forceinline void destruct(T*, int, S00e58310_TypeIsPod) {}
};
template <class T>
static __forceinline void S00e58310_ArrayBase_copy(T* dst, const T* src, int n);

template <class T>
static __forceinline void S00e58310_ArrayBase_init(hkArrayBase<T>& self);

template <class T>
static __forceinline void S00e58310_ArrayBase_clear(hkArrayBase<T>& self);

template <class T>
static __forceinline void S00e58310_ArrayBase__clearAndDeallocate(hkArrayBase<T>& self, S00e58310_Allocator& alloc);

template <class T>
static __forceinline hkArrayBase<T>& S00e58310_ArrayBase_copyFromArray(hkArrayBase<T>& self, S00e58310_Allocator& alloc, const hkArrayBase<T>& a, S00e58310_TypeIsPod);

template <class T>
static __forceinline void S00e58310_ArrayBase_copy(T* dst, const T* src, int n)
{
        for (int i = 0; i < n; ++i) {
            dst[i] = src[i];
        }
    }

template <class T>
static __forceinline void S00e58310_ArrayBase_init(hkArrayBase<T>& self)
{
        self.m_data = 0;
        self.m_iElementCount = 0;
        self.m_iCapacityState = hkArrayBase<T>::DONT_DEALLOCATE_FLAG;
    }

template <class T>
static __forceinline void S00e58310_ArrayBase_clear(hkArrayBase<T>& self)
{
        S00e58310_Util::destruct(self.m_data, self.m_iElementCount, S00e58310_TypeIsPod());
        self.m_iElementCount = 0;
    }

template <class T>
static __forceinline void S00e58310_ArrayBase__clearAndDeallocate(hkArrayBase<T>& self, S00e58310_Allocator& alloc)
{
        S00e58310_ArrayBase_clear(self);
        if ((self.m_iCapacityState & hkArrayBase<T>::DONT_DEALLOCATE_FLAG) == 0) {
            alloc._bufFree<T>(self.m_data, self.getCapacity());
        }
        self.m_data = 0;
        self.m_iCapacityState = hkArrayBase<T>::DONT_DEALLOCATE_FLAG;
    }

template <class T>
static __forceinline hkArrayBase<T>& S00e58310_ArrayBase_copyFromArray(hkArrayBase<T>& self, S00e58310_Allocator& alloc, const hkArrayBase<T>& a, S00e58310_TypeIsPod)
{
        if (self.getCapacity() < a.GetLogicalSize()) {
            if ((self.m_iCapacityState & hkArrayBase<T>::DONT_DEALLOCATE_FLAG) == 0) {
                alloc._bufFree<T>(self.m_data, self.getCapacity());
            }
            int n = a.GetLogicalSize();
            self.m_data = alloc._bufAlloc<T>(n);
            self.m_iCapacityState = n;
        }
        self.m_iElementCount = a.GetLogicalSize();
        S00e58310_ArrayBase_copy(self.m_data, a.m_data, self.m_iElementCount);
        return *(&self);
    }
template <typename T>
struct S00e58310_Array : hkArrayBase<T> {
    __forceinline S00e58310_Array<T>& operator=(const S00e58310_Array<T>& a)
    {
        copyFromArray(S00e58310_HeapAllocator().get(this), a, S00e58310_TypeIsPod());
        return *this;
    }
    __forceinline void destroy()
    {
        _clearAndDeallocate(S00e58310_HeapAllocator().get(this));
    }
};
struct S00e58310_Point {
    float x;
    float y;
    float z;
    float w;
};
__declspec(noinline) void __cdecl ProcessGeometryPasses(int n, const S00e58310_Array<S00e58310_Point>& Q, S00e58310_Array<float>& Ub, hkBool useCurvature, int degree, float E, int& nh, S00e58310_Array<float>& U, S00e58310_Array<S00e58310_Point>& P)
{
    nh = n;
    U.m_data[0] = Ub.m_data[0];
    U.m_data[n + 2] = Ub.m_data[n];
    for (int i = 0; i <= n; ++i) {
        U.m_data[i + 1] = Ub.m_data[i];
        P.m_data[i] = Q.m_data[i];
    }
}
void __cdecl hkaNURBS_GlobalCurveApproxErrBnd_00e58310(int n, const S00e58310_Array<S00e58310_Point>& Q, const S00e58310_Array<float>& Ub, int degree, float E, int& nh, S00e58310_Array<float>& U, S00e58310_Array<S00e58310_Point>& P);
struct CurvePoint { float x,y,z,w; CurvePoint(float a=0,float b=0,float c=0,float d=0) throw(); float& GetElementAddress_00e53590(int); };
__declspec(noinline) CurvePoint::CurvePoint(float a,float b,float c,float d) throw():x(a),y(b),z(c),w(d){}
// src: GUESS 0x00e53590 (confidence: low)
__declspec(noinline) float& CurvePoint::GetElementAddress_00e53590(int i) {return (&x)[i];}
struct CurveHeap {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void* allocate(int& bytes) throw();
 virtual void release(void* ptr,int bytes) throw();
 template<class T> __forceinline T* allocateItems(int& n) {
  int request=n*(int)sizeof(T);
  T* ptr=static_cast<T*>(allocate(request));
  n=request/(int)sizeof(T);
  return ptr;
 }
 template<class T> __forceinline void freeItems(T* ptr,int n) {release(ptr,n*(int)sizeof(T));}
};
struct CurvePolicy {
 __forceinline CurveHeap& get(void*) {return *static_cast<CurveHeap*>(hkMemoryRouter_getInstance()->m_pAllocator);}
};
__forceinline void initializeItems(float*,int) {}
__forceinline void initializeItems(CurvePoint* ptr,int n) {for(int i=0;i<n;++i) new(ptr+i) CurvePoint;}
template<class T> struct FitOwnedArrayBase {
 T* data;int size;int capacity;
 __forceinline FitOwnedArrayBase():data(0),size(0),capacity(0x80000000){}
 __forceinline void set(T* p,int n,int cap) {data=p;size=n;capacity=cap;}
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline const T& operator[](int i) const {return data[i];}
 __forceinline void clear(CurveHeap& heap) {
  size=0;
  int cap=capacity;
  if(!(cap&0x80000000)) heap.freeItems<T>(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;
 }
};
template<class T> struct FitOwnedArray:FitOwnedArrayBase<T> {
 __forceinline FitOwnedArray() throw() {}
 __forceinline FitOwnedArray(int n) throw() {
  HolderStub* holder=hkMemoryRouter_getInstance(); CurveHeap* heap=static_cast<CurveHeap*>(holder->m_pAllocator);
  T* p=n?heap->allocateItems<T>(n):0;
  int cap=n?n:0x80000000;
  set(p,n,cap);
  initializeItems(data,n);
 }
 __forceinline ~FitOwnedArray() throw() {HolderStub* holder=hkMemoryRouter_getInstance(); CurveHeap* heap=static_cast<CurveHeap*>(holder->m_pAllocator);
  int cap=capacity; size=0;
  if(!(cap&0x80000000)) heap->freeItems<T>(data,cap&0x3fffffff);
  data=0;capacity=0x80000000;}
};
struct CurveWirePoints {CurvePoint* data;int size;int capacity;};
void __cdecl ProcessGeometryPasses(int,const CurveWirePoints*,FitOwnedArray<float>*,hkBool,int,float,int*,FitOwnedArray<float>*,FitOwnedArray<CurvePoint>*) throw();
// src: HAVOK_LIB 0x00e58310
__declspec(noinline) void __cdecl hkaNURBS_GlobalCurveApproxErrBnd_00e58310(int count,const FitOwnedArray<CurvePoint>* points,const FitOwnedArray<float>* values,int degree,float tolerance,int* last,FitOwnedArray<float>* outValues,FitOwnedArray<CurvePoint>* outPoints) throw() {
 FitOwnedArray<float> writable(values->size);
 for(int i=0;i<values->size;++i) writable[i]=values->data[i];
 CurveWirePoints input={points->data,points->size,points->capacity};
 ProcessGeometryPasses(count,&input,&writable,hkBool(false),degree,tolerance,last,outValues,outPoints);
}
void __cdecl hkaNURBS_ApproximateCurve(int count,const float* values,const Float4* points,int degree,float tolerance,int* knotCount,float* knots,int* pointCount,Float4* resultPoints);
struct E589Destination { float* data; int unknown04; int unknown08; int rows; int columns;
    float* GetElementAddress_00e587b0(int index);
};
struct E589Values { float* data; int unknown04; int unknown08; int rows; int columns;
// src: GUESS 0x00e58880 (confidence: low)
    __declspec(noinline) float GetIndexedValue_00e58880(int index) { return data[index]; }
    int EvaluateValue_00e58890();
};
struct E589ScaledValues { float* data; int unknown04; int unknown08; int rows; int columns;
// src: GUESS 0x00e58880 (confidence: low)
    __declspec(noinline) float GetIndexedValue_00e58880(int index) { return data[index]; }
};
void __cdecl hkaCGSolver_float_ScaleAdd(E589Destination* destination,E589Values* values,const float* scale,E589ScaledValues* scaleValues);
extern "C" void _ReadWriteBarrier();
extern __m128 DAT_01017d10;
extern const double DAT_01091c00;
struct __declspec(align(16)) PlaneVector {

    float f[4];

    __forceinline const __m128& quad() const { return *reinterpret_cast<const __m128*>(this); }

    __forceinline void assign(__m128 q) { *reinterpret_cast<__m128*>(this)=q; }

    __forceinline void setAnd(const PlaneVector& a, const __m128& b) { assign(_mm_and_ps(a.quad(), b)); }

    __forceinline void setZero4() { assign(_mm_setzero_ps()); }

    __forceinline void setAdd4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_add_ps(a.quad(), b.quad())); }

    __forceinline void setMul4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_mul_ps(a.quad(), b.quad())); }

    __forceinline void addMul4(const PlaneVector& a, const PlaneVector& b) { assign(_mm_add_ps(quad(), _mm_mul_ps(a.quad(), b.quad()))); }

    __forceinline void setBroadcast(const PlaneVector& v, int i) { assign(_mm_shuffle_ps(v.quad(), v.quad(), 0)); }

    __forceinline void setAbs4(const PlaneVector& a) { assign(_mm_and_ps(a.quad(),DAT_01017d10)); }
    __forceinline void add4(const PlaneVector& a) { assign(_mm_add_ps(quad(),a.quad())); }
    __forceinline void setAll3(float f) { assign(_mm_set_ps1(f)); }

    float& operator()(int i) { return f[i]; }

    const float& operator()(int i) const { return f[i]; }

};
struct PlaneGroup {

    PlaneVector x, y, z, w;

    __forceinline void set(const PlaneVector& a, const PlaneVector& b, const PlaneVector& c, const PlaneVector& d) {

        x.assign(_mm_setr_ps(a(0),b(0),c(0),d(0)));

        y.assign(_mm_setr_ps(a(1),b(1),c(1),d(1)));

        z.assign(_mm_setr_ps(a(2),b(2),c(2),d(2)));

        w.assign(_mm_setr_ps(a(3),b(3),c(3),d(3)));

    }

};
struct QueryCode {
    void* table;
    unsigned short memoryFlags, references;
    PlaneVector origin;
    const unsigned char* program;
};
struct PlaneView { int count; const PlaneVector* data; };
struct QueryState { int x,y,z,primitive,property,shift; };
struct QueryBounds { PlaneVector minimum, scale; };
struct QueryMachine {
    int partial;
    __declspec(align(16)) float inverseScale;
    __declspec(align(16)) int complete;
    __declspec(align(16)) int count;
    PlaneGroup groups[8], magnitudes[8];
    void __thiscall ProcessEntries_00e5e430(QueryState*,const unsigned char*,QueryBounds*);
    __forceinline void prepare(const PlaneView& view, unsigned codeBits) {
        const QueryCode* code=reinterpret_cast<const QueryCode*>(codeBits);
        __assume(view.count>=0 && view.count<=32); int end=view.count & ~3;
        PlaneGroup* dest=groups;
        const PlaneVector* cursor=view.data;
        count=0;
        int n=0;
        for(;n<end;n+=4) {
            dest->set(cursor[0],cursor[1],cursor[2],cursor[3]);
            ++dest; ++count; cursor+=4;
        }
        const PlaneVector* a=cursor;
        const PlaneVector* b=cursor+1;
        const PlaneVector* c=cursor+2;
        const PlaneVector* d=cursor+3;
        switch(view.count-n) {
        case 1:b=a;
        case 2:c=a;
        case 3:d=a;
            dest->set(*a,*b,*c,*d);
            ++dest; ++count;
        }
        PlaneGroup* absolute=magnitudes+count;
        --absolute; --dest;
        for(;dest>=groups;--dest,--absolute) {
            PlaneGroup* g=dest; PlaneVector PlaneGroup::* yfield=&PlaneGroup::y; PlaneVector PlaneGroup::* zfield=&PlaneGroup::z;
            _ReadWriteBarrier(); absolute->x.setAbs4(g->x); _ReadWriteBarrier();
            absolute->y.setAbs4((g->*yfield)); _ReadWriteBarrier();
            absolute->z.assign(_mm_and_ps(DAT_01017d10,(g->*zfield).quad())); _ReadWriteBarrier();
            absolute->w.setZero4(); _ReadWriteBarrier();

        const PlaneVector& offset = code->origin;

        g->w.assign(_mm_add_ps(_mm_add_ps(_mm_add_ps(

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0x00), g->x.quad()),

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0x55), (g->*yfield).quad())),

            _mm_mul_ps(_mm_shuffle_ps(offset.quad(), offset.quad(), 0xaa), (g->*zfield).quad())), g->w.quad()));

        _ReadWriteBarrier();

        const __m128& w = g->w.quad();

        _ReadWriteBarrier();

        g->w.assign(_mm_add_ps(g->w.quad(), w));

        }
    }
    __forceinline void query(unsigned codeBits,const PlaneView& view,int output,int properties) {
        const QueryCode* code=reinterpret_cast<const QueryCode*>(codeBits);
        const unsigned char* pc=code->program;
        partial=output;
        QueryState state;
        QueryBounds bounds;
        inverseScale=1.0f/code->origin(3);
        state.z=0; state.primitive=0; state.property=0; state.shift=16;
        state.x=0; state.y=0;
        bounds.minimum.setZero4();
        bounds.scale.setAll3(float(inverseScale*DAT_01091c00));
        prepare(view,codeBits);
        complete=properties;
        ProcessEntries_00e5e430(&state,pc,&bounds);
    }
};
void __cdecl Object_ProcessState_00e5d360(unsigned codeBits,const PlaneView& input,int output,int properties);
#include <xmmintrin.h>
#include <xmmintrin.h>
struct V4Init_00e53160 {
    float x;
    float y;
    float z;
    float w;

    V4Init_00e53160* FUN_00e53160(float a, float b, float c, float d);
};
__declspec(noinline) V4Init_00e53160*
V4Init_00e53160::FUN_00e53160(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
    return this;
}
void __cdecl hkaNURBS_DersBasisFuns(
    int span, float u, int degree, int limit, float** knots, float* basis);
void __cdecl hkaNURBS_CurveDerivs( int a1, int a2, float** knots, KnotVector** points, float u, int a6, KnotVector* rows, int a8, float a9);
struct S00e49e00_Slot {};
inline void* operator new(size_t, void* p, S00e49e00_Slot) { __assume(p != 0); return p; }
inline void operator delete(void*, void*, S00e49e00_Slot) {}
namespace se49e00 {

struct Allocator;

struct AllocatorHolder {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    Allocator* m_pHeapAllocator;
};

AllocatorHolder* hkMemoryRouter_getInstance();
void ResizeAudioStream(Allocator* pkAllocator, void* apvArray, unsigned int uiStride);
void __fastcall FUN_00c90510(void* pvObject);

template <class T> struct ObjectArray {
    T* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;

    void PushBack(const T& kElement)
    {
        AllocatorHolder* pkHolder = hkMemoryRouter_getInstance();
        if (m_uiLogicalSize == (m_iCapacityAndFlags & 0x3fffffff))
            ResizeAudioStream(pkHolder->m_pHeapAllocator, this, sizeof(T));
        new (&m_pData[m_uiLogicalSize], S00e49e00_Slot()) T(kElement);
        m_uiLogicalSize++;
    }
};

struct Child;

struct Container {
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
    ObjectArray<Child*> m_kChildList;

    void hkpCollisionFilterList_addCollisionFilter(Child* pkChild);
};

// @fnv 0x00e49e00
// src: XBOX_PDB 0x00e49e00
void Container::hkpCollisionFilterList_addCollisionFilter(Child* pkChild)
{
    FUN_00c90510(pkChild);
    m_kChildList.PushBack(pkChild);
}

}
float hkaNURBS_Point_Dot(const Vec4f* left, const Vec4f* right);
namespace e54 {
int __cdecl FindFloatInterval(int a, int degree, float u, float** knots);
void __cdecl ComputeBasisFunctions(int span, float u, int degree, float** knots, float* basis);
// @fnv 0x00e54630
// src: HAVOK_LIB 0x00e54630
KnotVector hkaNURBS_CurvePoint(int a, int degree, float** knots, KnotVector** points, float u)
{
    int span = FindFloatInterval(a, degree, u, knots);
    float basis[4];
    ComputeBasisFunctions(span, u, degree, knots, basis);
    KnotVector result = ::Object_ScaleCopy_Thunk(basis[0], (*points)[span - degree]);
    for (int i = 1; i <= degree; i++)
    {
        result.ComputeValue_00e531a0(::Object_ScaleCopy_Thunk(basis[i], (*points)[span - degree + i]));
    }
    return result;
}
}

// @fnv 0x00e53a80
// src: HAVOK_LIB 0x00e53a80
__declspec(noinline) void __cdecl hkaNURBS_DersBasisFuns(int span, float u, int degree, int order, float** knots, float* ders)
{
    float ndu[4][4];
    float left[4], right[4];
    float a[2][4];
    ndu[0][0] = 1.0f;
    for (int j = 1; j <= degree; ++j) {
        left[j] = u - (*knots)[span + 1 - j];
        right[j] = (*knots)[span + j] - u;
        float saved = 0.0f;
        for (int r = 0; r < j; ++r) {
            ndu[j][r] = left[j - r] + right[r + 1];
            float temp = ndu[r][j - 1] / ndu[j][r];
            ndu[r][j] = saved + temp * right[r + 1];
            saved = left[j - r] * temp;
        }
        ndu[j][j] = saved;
    }
    for (int j = 0; j <= degree; ++j) ders[j] = ndu[j][degree];
    for (int r = 0; r <= degree; ++r) {
        int s1 = 0, s2 = 1;
        a[0][0] = 1.0f;
        for (int k = 1; k <= order; ++k) {
            float d = 0.0f;
            int rk = r - k;
            int pk = degree - k;
            if (r >= k) {
                a[s2][0] = a[s1][0] / ndu[pk + 1][rk];
                d = a[s2][0] * ndu[rk][pk];
            }
            int j1 = rk >= -1 ? 1 : -rk;
            int j2 = r - 1 <= pk ? k - 1 : degree - r;
            for (int j = j1; j <= j2; ++j) {
                a[s2][j] = (a[s1][j] - a[s1][j - 1]) / ndu[pk + 1][rk + j];
                d += a[s2][j] * ndu[rk + j][pk];
            }
            if (r <= pk) {
                a[s2][k] = -a[s1][k - 1] / ndu[pk + 1][r];
                d += a[s2][k] * ndu[r][pk];
            }
            ders[k*4+r] = d;
            int swap = s1; s1 = s2; s2 = swap;
        }
    }
    int factor = degree;
    for (int k = 1; k <= order; ++k) {
        for (int j = 0; j <= degree; ++j)
            ders[k*4+j] *= factor;
        factor *= degree - k;
    }
}



int __cdecl CountRuns(float**, int);
__declspec(noinline) int __cdecl Factorial(int n) {
 int factorials[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
 if(n<=0) return 1;if(n<=10)return factorials[n];int result=factorials[10];
 for(int i=11;i<=n;++i)result*=i;return result;
}
__declspec(noinline) int __cdecl BinomialCoefficient(int n, int k) {
 int denominator=Factorial(n-k);denominator*=Factorial(k);return Factorial(n)/denominator;
}
typedef KnotVector ElevationPoint;
template<class T> struct ElevationArray {
    T* data;
    int count;
    int capacity;
    __forceinline void allocate(int requested) {
        MemoryAllocator* allocator=(MemoryAllocator*)hkMemoryRouter_getInstance()->m_pAllocator;
        T* ptr;
        if(requested) {
            int bytes=requested*sizeof(T);
            ptr=(T*)allocator->Allocate(&bytes);
            requested=bytes/(int)sizeof(T);
        } else ptr=0;
        int flags=requested?requested:0x80000000;
        data=ptr;count=requested;capacity=flags;

    }
    __forceinline void free() {
        HolderStub* holder=hkMemoryRouter_getInstance();
        MemoryAllocator* allocator=(MemoryAllocator*)holder->m_pAllocator;
        int cap=capacity;
        if ((cap & 0x80000000)==0) allocator->Free(data, (cap & 0x3fffffff) * sizeof(T));
    }
    void SwapThreeInts(ElevationArray<T>* other);
};
// @fnv 0x00e55cf0
// src: HAVOK_LIB 0x00e55cf0
void __cdecl hkaNURBS_DegreeElevateCurve(int* degreeAndLast, int p, FloatVector* knotVector, VertexVector* pointVector, int t) {
    ElevationArray<float>* knots = reinterpret_cast<ElevationArray<float>*>(knotVector);
    ElevationArray<ElevationPoint>* points = reinterpret_cast<ElevationArray<ElevationPoint>*>(pointVector);
    int n = *degreeAndLast;
    int m = n + p + 1;
    if (t == 0) return;
    ElevationPoint bpts[4];
    float bezalfs[4][4];
    ElevationPoint ebpts[4], nextbpts[4];
    float alfs[4];
    int segments = CountRuns((float**)knots,m);
    int nh = (segments-1)*t + n;
    ElevationArray<float> Uh;
    Uh.allocate(nh+p+t+2);
    float* UhData=Uh.data;
    ElevationArray<ElevationPoint> Qw;
    Qw.allocate(nh+1);
    ElevationPoint* QwData=Qw.data;
    int npoints=Qw.count;
    for(int i=0;i<npoints;++i) new(QwData+i) ElevationPoint;
    int ph = p+t;
    int ph2=ph/2;
    bezalfs[0][0]=bezalfs[ph][p]=1.0f;
    for(int i=1;i<=ph2;++i) {
        float inv=1.0f/BinomialCoefficient(ph,i);
        int mpi=p<i?p:i;
        for(int j=(i-t)<0?0:i-t;j<=mpi;++j)
            bezalfs[i][j]=inv*BinomialCoefficient(p,j)*BinomialCoefficient(t,i-j);
    }
    for(int i=ph2+1;i<=ph-1;++i) {
        int mpi=p<i?p:i;
        for(int j=(i-t)<0?0:i-t;j<=mpi;++j) bezalfs[i][j]=bezalfs[ph-i][p-j];
    }
    int mh=ph, kind=ph+1, r=-1, a=p, b=p+1, cind=1;
    float ua=knots->data[0];
    QwData[0].FUN_00e53180(points->data[0]);
    for(int i=0;i<=ph;++i) UhData[i]=ua;
    for(int i=0;i<=p;++i) bpts[i].FUN_00e53180(points->data[i]);
    while(b<m) {
        int i=b;
        while(b<m && knots->data[b]==knots->data[b+1]) ++b;
        int mul=b-i+1;
        float ub=knots->data[b];
        int oldr=r;
        r=p-mul;
        int lbz=oldr>0?(oldr+2)/2:1;
        int rbz=r>0?ph-(r+1)/2:ph;
        if(r>0) {
            float numer=ub-ua;
            for(int k=p;k>mul;--k) alfs[k-mul-1]=numer/(knots->data[a+k]-ua);
            for(int j=1;j<=r;++j) {
                int save=r-j, s=mul+j;
                for(int k=p;k>=s;--k) {
                    bpts[k].FUN_00e53180(Object_ScaleCopy_Thunk(alfs[k-s],bpts[k]).ProcessAndReturnValue_00e53260(Object_ScaleCopy_Thunk(1.0f-alfs[k-s],bpts[k-1])));
                }
                nextbpts[save].FUN_00e53180(bpts[p]);
            }
        }
        for(int i=lbz;i<=ph;++i) {
            ebpts[i].FUN_00e53180(ElevationPoint());
            int mpi=p<i?p:i;
            for(int j=(i-t)<0?0:i-t;j<=mpi;++j) {
                ebpts[i].FUN_00e53180(ebpts[i].ProcessAndReturnValue_00e53260(Object_ScaleCopy_Thunk(bezalfs[i][j],bpts[j])));
            }
        }
        if(oldr>1) {
            int first=kind-2,last=kind;
            float den=ub-ua;
            float bet=(ub-UhData[kind-1])/den;
            for(int tr=1;tr<oldr;++tr) {
                int i=first,j=last,kj=j-kind+1;
                while(j-i>tr) {
                    if(i<cind) {
                        float alf=(ub-UhData[i])/(ua-UhData[i]);
                        QwData[i].FUN_00e53180(Object_ScaleCopy_Thunk(alf,QwData[i]).ProcessAndReturnValue_00e53260(Object_ScaleCopy_Thunk(1.0f-alf,QwData[i-1])));
                    }
                    if(j>=lbz) {
                        if(j-tr<=kind-ph+oldr) {
                            float gam=(ub-UhData[j-tr])/den;
                            ebpts[kj].FUN_00e53180(Object_ScaleCopy_Thunk(gam,ebpts[kj]).ProcessAndReturnValue_00e53260(Object_ScaleCopy_Thunk(1.0f-gam,ebpts[kj+1])));
                        } else {
                            ebpts[kj].FUN_00e53180(Object_ScaleCopy_Thunk(bet,ebpts[kj]).ProcessAndReturnValue_00e53260(Object_ScaleCopy_Thunk(1.0f-bet,ebpts[kj+1])));
                        }
                    }
                    ++i;--j;--kj;
                }
                --first;++last;
            }
        }
        if(a!=p) for(int i=0;i<ph-oldr;++i) UhData[kind++]=ua;
        for(int j=lbz;j<=rbz;++j) {QwData[cind].FUN_00e53180(ebpts[j]);++cind;}
        if(b<m) {
            for(int j=0;j<r;++j) bpts[j].FUN_00e53180(nextbpts[j]);
            for(int j=r;j<=p;++j) bpts[j].FUN_00e53180(points->data[b-p+j]);
            a=b;++b;ua=ub;
        } else for(int i=0;i<=ph;++i) UhData[kind+i]=ub;
    }
    points->SwapThreeInts(&Qw);
    Uh.SwapThreeInts(knots);
    *degreeAndLast=nh;
    Qw.free();Uh.free();
}

struct S00e568f0_Vec4 {
    float x;
    float y;
    float z;
    float w;
    S00e568f0_Vec4 UpdateState_00e532b0(const S00e568f0_Vec4& o) const;
    float GetHelperValueAsFloat() const;
};

void ArrayReserve(void* heap, void* arr, int newCap, int elemSize);



static void S00e568f0_SetArraySize(void* heap, hkArrayBase<float>* arr, int size)
{
    int cap = arr->getCapacity();
    if (cap < size) {
        int doubled = cap + cap;
        ArrayReserve(heap, arr, size < doubled ? doubled : size, 4);
    }
    arr->m_iElementCount = size;
}

// @fnv 0x00e568f0
// src: HAVOK_LIB 0x00e568f0
void __cdecl hkaNURBS_ChordLengthParameterization(int n, int a2, void* s)
{
    hkArrayBase<S00e568f0_Vec4>* pts = (hkArrayBase<S00e568f0_Vec4>*)a2;
    hkArrayBase<float>* out = (hkArrayBase<float>*)s;
    int count = n + 1;
    HolderView* holder = reinterpret_cast<HolderView*>(hkMemoryRouter_getInstance());
    S00e568f0_SetArraySize(holder->m_pAllocator, out, count);
    out->m_data[0] = 0.0f;
    int i = 1;
    if (i <= n) {
        const S00e568f0_Vec4* cur = pts->m_data + 1;
        const S00e568f0_Vec4* prev = pts->m_data;
        for (; i <= n; ++i, ++cur, ++prev) {
            out->m_data[i] = cur->UpdateState_00e532b0(*prev).GetHelperValueAsFloat() + out->m_data[i - 1];
        }
    }
    for (i = 1; i < n; ++i) {
        out->m_data[i] /= out->m_data[n];
    }
    out->m_data[n] = 1.0f;
}

struct CountCopy {int n;};
static const float errorLimit=3.40282e38f;
__declspec(nothrow) HolderStub* __cdecl hkMemoryRouter_getInstance();
__declspec(nothrow) int __cdecl hkaNURBS_MinIndex(float**,int);
__declspec(nothrow) int __cdecl FindInsertIndex(float,float**,int);
__declspec(nothrow) int __cdecl FindFirstNonZero(int,int,int);
static __forceinline int getDifference(int saved,int* current){return saved-*current;}

struct FNVTemporaryAllocator {
    virtual void Other0();
    virtual void Other1();
    virtual void Other2();
    __declspec(nothrow) virtual void* Allocate(int* sizeInBytes);
    __declspec(nothrow) virtual void Free(void* buffer, int sizeInBytes);
};
template<class T> struct ArrayStorage { T* data; int size; int capacityAndFlags; __declspec(nothrow) __forceinline T& operator[](int i){return data[i];} };
template<class T> struct TypedTemporary : ArrayStorage<T> {

    __declspec(nothrow) __forceinline TypedTemporary(){}
    __declspec(nothrow) __forceinline explicit TypedTemporary(int n){Allocate(n);}
    __declspec(nothrow) __forceinline TypedTemporary(int n,const T& v){Allocate(n,v);}
    __declspec(nothrow) __forceinline TypedTemporary(const TypedTemporary<T>& n){CopyFrom(n);}
    __declspec(nothrow) static __forceinline T* AllocateTemporaryArray(FNVTemporaryAllocator* allocator, int& count) {
        if (count) {
            int bytes = count * 4;
            T* buffer = (T*)allocator->Allocate(&bytes);
            int capacity = bytes / 4;
            count = capacity;
            return buffer;
        }
        return 0;
    }
    __declspec(nothrow) __forceinline void Allocate(int count) {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        T* buffer = AllocateTemporaryArray((FNVTemporaryAllocator*)mgr->m_pAllocator, count);
        int flags = count ? count : 0x80000000;
        data = buffer;
        size = count;
        capacityAndFlags = flags;
    }
    __declspec(nothrow) __forceinline void Allocate(int count, const T& value) {
        Allocate(count);
        T* next = data;
        for (int remaining = size; remaining > 0; --remaining)
            *next++ = value;
    }
    __declspec(nothrow) __forceinline void AllocateFilled(int count, const T& value, T*& start) {
        Allocate(count);
        start = data;
        T* next = data;
        for (int remaining = size; remaining > 0; --remaining)
            *next++ = value;
    }
    __declspec(nothrow) __forceinline void CopyFrom(const ArrayStorage<T>& other) {
        data = 0;
        capacityAndFlags = 0x80000000;
        HolderStub* mgr = hkMemoryRouter_getInstance();
        FNVTemporaryAllocator* allocator = (FNVTemporaryAllocator*)mgr->m_pAllocator;
        if (other.size > 0) {
            int bytes = other.size * 4;
            data = (T*)allocator->Allocate(&bytes);
            capacityAndFlags = bytes / 4;
        }
        int n = other.size;
        T* d = data;
        const T* src = other.data;
        size = n;
        for (int i = 0; i < n; ++i)
            d[i] = src[i];
    }
    __declspec(nothrow) __forceinline ~TypedTemporary(){Release();}
    __declspec(nothrow) __forceinline void Release() {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        FNVTemporaryAllocator* allocator = (FNVTemporaryAllocator*)mgr->m_pAllocator;
        size=0;
        int cap = capacityAndFlags;
        if ((cap & 0x80000000) == 0)
            allocator->Free(data, (cap & 0x3fffffff) * 4);
        data = 0;
        capacityAndFlags = 0x80000000;
    }
};
typedef TypedTemporary<float> FNVTemporaryFloats;
typedef TypedTemporary<float> FNVFloatValues;
extern const double DAT_0104e138;
extern const float DAT_010ec990;
__declspec(nothrow) float __cdecl EvaluateBasisFunction(int degree, int total, float** knots, int index, float value);
__declspec(nothrow) int __cdecl GetRunLength(int index, int end, float** knots);
__declspec(nothrow) void __cdecl hkaNURBS_Remove(int index, FNVTemporaryFloats* array, int size);
__declspec(nothrow) void __cdecl hkaNURBS_ComputeBounds(int count, int degree, float** knots, int context, FNVTemporaryFloats* temporary, int start, int end);
__declspec(nothrow) int __cdecl hkaNURBS_RemoveCurveKnot(int count, int degree, float** knots, int context, float value, int index, int removed, int active, float fill);

struct ErrorDecision { unsigned char value; };
ErrorDecision* IsSampleBoundary(ErrorDecision*,int,float**,int);
float hkaNURBS_GetRemovalBoundCurve(int,int,float**,int,float,int,int);
// src: HAVOK_LIB 0x00e555f0
__declspec(nothrow) __declspec(noinline) void __cdecl hkaNURBS_ComputeBounds(int count,int degree,float** knots,int context,FNVTemporaryFloats* bounds,int begin,int end) {
    int last=count+degree+1;
    for(int i=begin;i<=end;++i) bounds->data[i]=DAT_010ec990;
    for(int i=begin;i<=end;++i) {
        ErrorDecision decision;
        if(IsSampleBoundary(&decision,i,knots,last)->value)
            bounds->data[i]=hkaNURBS_GetRemovalBoundCurve(count,degree,knots,context,(*knots)[i],i,GetRunLength(i,last,knots));
    }
}
// src: HAVOK_LIB 0x00e54930
__declspec(nothrow) __declspec(noinline) int __cdecl hkaNURBS_MinIndex(float** data,int count) {
    if(count<=0)return -1;
    float minimum=(*data)[0]; int index=0;
    for(int i=1;i<count;++i) if((*data)[i]<minimum){minimum=(*data)[i];index=i;}
    return index;
}
// src: HAVOK_LIB 0x00e54c10
__declspec(nothrow) __declspec(noinline) void __cdecl hkaNURBS_Remove(int first,FNVTemporaryFloats* bounds,int count) {
    --bounds->size;
    for(int i=first;i<bounds->size;++i) bounds->data[i]=bounds->data[i+1];
}

// @fnv 0x00e56a00
// src: HAVOK_LIB 0x00e56a00
int __cdecl hkaNURBS_RemoveKnotsBoundCurve(int* count, int degree, FloatVector* knots, VertexVector* context,
                         int pointCount, const InputFloats* values, ScratchIndices* weights,
                         float tolerance, const InputVertices* unusedPoints)
{
    int m=*count;CountCopy original={m};m+=degree+1;CountCopy saved;for(unsigned i=0;i<sizeof saved;++i)((unsigned char*)&saved)[i]=((unsigned char*)&original)[i];int initialCount=saved.n;
    FNVTemporaryFloats knotErrors;
    float* errorValues;
    knotErrors.AllocateFilled(m + 1, errorLimit, errorValues);
    FNVTemporaryFloats contributions(pointCount+1,0.0f);
    FNVTemporaryFloats updatedWeights(pointCount+1,0.0f);
    TypedTemporary<int> lowerLimits(pointCount+1);
    TypedTemporary<int> upperLimits(pointCount+1);
    hkaNURBS_ComputeBounds(*count, degree, ((float**)knots), ((int)context), &knotErrors, degree + 1, m - degree - 1);
    int knot = hkaNURBS_MinIndex(&knotErrors.data, m+1);
    int removalCount = GetRunLength(knot, m, ((float**)knots));
    float* currentError = errorValues + knot;
    if (*currentError != DAT_0104e138) { for(;;) {
        float blend;
        int first = knot;
        if (((removalCount + degree) % 2) == 0) {
            blend = 0.0f;
            first -= (removalCount + degree) / 2;
        } else {
            int half = (degree + 1 + removalCount) / 2;
            blend = ((*((float**)knots))[first] - (*((float**)knots))[first - half + 1]) /
                    ((*((float**)knots))[first - half + degree + 2] - (*((float**)knots))[first - half + 1]);
            first = first - half + 1;
        }
        float* knotValues = *((float**)knots);
        int lower = FindInsertIndex(knotValues[first], ((float**)values), pointCount);
        int upper = FindInsertIndex(knotValues[first + degree + 1], ((float**)values), pointCount) - 1;
        float maximum = 0.0f;
        for (int j = lower; j <= upper; ++j) {
            float error = (float)((double)*currentError * (1.0 - blend) *
                               EvaluateBasisFunction(degree, m, ((float**)knots), first, (*((float**)values))[j]));
            contributions[j] = error;
            updatedWeights[j] = error + ((FNVFloatValues*)weights)->data[j];
            float updated = updatedWeights[j];
            maximum = maximum > updated ? maximum : updated;
        }
        if (maximum <= tolerance) {
            FNVTemporaryFloats originalWeights(*((FNVFloatValues*)weights));
            for (int j = lower; j <= upper; ++j)
                ((FNVFloatValues*)weights)->data[j] = updatedWeights[j];
            hkaNURBS_RemoveCurveKnot(*count, degree, ((float**)knots), ((int)context), (*((float**)knots))[knot],
                           knot, removalCount, 1, DAT_010ec990);
            --m;
            --*count;
            if ((m+1) <= 2 * degree + 2) {
                break;
            }
            hkaNURBS_Remove(knot, &knotErrors, (m+1));
            int firstAffected = knot - degree > degree + 1 ? knot - degree : degree + 1;
            int currentCount = *count;
            int lastAffected = knot - removalCount + degree < currentCount ?
                               knot - removalCount + degree : currentCount;
            hkaNURBS_ComputeBounds(currentCount, degree, ((float**)knots), ((int)context), &knotErrors,
                FindFirstNonZero(firstAffected, (int)((float**)knots), m),
                FindFirstNonZero(lastAffected, (int)((float**)knots), m));
        } else {
            *currentError = DAT_010ec990;
        }
        knot = hkaNURBS_MinIndex(&knotErrors.data, (m+1));
        removalCount = GetRunLength(knot, m, ((float**)knots));
        currentError = knotErrors.data + knot;
    if (*currentError == DAT_0104e138) break;
    } }
    int removedTotal=getDifference(initialCount,count);
    return removedTotal;
}

// @fnv 0x00e58960
// src: HAVOK_LIB 0x00e58960
void __cdecl hkaCGSolver_float_ScaleAdd_00e58960(
    FUN_00e587b0_Class* obj,
    float* factor,
    FUN_00e58880_Class* values)
{
    int count = reinterpret_cast<FUN_00e58890_Class*>(obj)->EvaluateValue_00e58890();
    for (int i = 0; i < count; ++i) {
        float* destination =
            reinterpret_cast<float*>(obj->GetElementAddress_00e587b0(i));
        *destination = values->GetIndexedValue_00e58880(i) * *factor + *destination;
    }
}

int __fastcall EvaluateValue_00e58890(FUN_00e587b0_Class*);

// @fnv 0x00e589a0
// src: HAVOK_LIB 0x00e589a0
void __cdecl hkaCGSolver_float_CopyNegative(FUN_00e587b0_Class* p, FUN_00e58880_Class* q)
{
    int count = EvaluateValue_00e58890(p);
    for (int i = 0; i < count; ++i)
    {
        float* dst = reinterpret_cast<float*>(p->GetElementAddress_00e587b0(i));
        *dst = -q->GetIndexedValue_00e58880(i);
    }
}

// @fnv 0x00e532b0
// src: GUESS 0x00e532b0 (confidence: low)
KnotVector KnotVector::UpdateState_00e532b0(const KnotVector& other) const
{
    KnotVector result = *this;
    return result.SubtractFourComponents(other);
}

extern const float DAT_010ec990 = 3.40282e38f;

bool* IsSampleBoundary(bool* a, int b, float** c, int d);
__declspec(noinline) int GetRunLength(int index, int last, float** samples)
{
    int right = 0;
    for (int j = index; j <= last; ++j) {
        if ((*samples)[index] != (*samples)[j]) break;
        ++right;
    }
    int left = 1;
    for (int j = index - 1; j >= 0; --j) {
        if ((*samples)[index] != (*samples)[j]) break;
        ++left;
    }
    return left + right - 1;
}
float hkaNURBS_GetRemovalBoundCurve(int a1, int a2, float** a3, int a4, float f, int i, int p);

// @fnv 0x00e555f0
// src: HAVOK_LIB 0x00e555f0
void hkaNURBS_ComputeBounds(int a1, int a2, float** a3, int a4, float** a5, int start, int end)
{
    int v = a1 + a2 + 1;
    bool result;
for(int k=start; k<=end; ++k) (*a5)[k] = DAT_010ec990;
    for (int i = start; i <= end; i++) {
        if (*IsSampleBoundary(&result, i, a3, v) != 0) {
            float* src = *a3 + i;
            float* dst = *a5 + i;
            *dst = hkaNURBS_GetRemovalBoundCurve(a1, a2, a3, a4, *src, i, GetRunLength(i, v, a3));
        }
    }
}

// @fnv 0x00e54a00
// src: HAVOK_LIB 0x00e54a00
int __cdecl hkaNURBS_MaxIndex(float** arr, int count)
{
    if (count <= 0) {
        return -1;
    }
    float best = (*arr)[0];
    int index = 0;
    for (int i = 1; i < count; i++) {
        if ((*arr)[i] > best) {
            best = (*arr)[i];
            index = i;
        }
    }
    return index;
}

struct RemovalVector : KnotVector {
    RemovalVector(float a=0,float b=0,float c=0,float d=0);
    RemovalVector& operator=(const RemovalVector&);
    RemovalVector& add(const RemovalVector&);
    RemovalVector& subtract(const RemovalVector&);
    RemovalVector& scale(float);
    RemovalVector& divide(float);
    RemovalVector operator*(float) const;
    RemovalVector operator-(const RemovalVector&) const;
    RemovalVector operator+(const RemovalVector&) const;
    RemovalVector operator/(float) const;
};
__declspec(noinline) RemovalVector::RemovalVector(float a,float b,float c,float d) : KnotVector(a,b,c,d) {}
__declspec(noinline) RemovalVector& RemovalVector::operator=(const RemovalVector& v) { x=v.x;y=v.y;z=v.z;w=v.w;return *this; }
__declspec(noinline) RemovalVector& RemovalVector::add(const RemovalVector& v) {x+=v.x;y+=v.y;z+=v.z;w+=v.w;return *this;}
__declspec(noinline) RemovalVector& RemovalVector::subtract(const RemovalVector& v) {x-=v.x;y-=v.y;z-=v.z;w-=v.w;return *this;}
__declspec(noinline) RemovalVector& RemovalVector::scale(float f) {x*=f;y*=f;z*=f;w*=f;return *this;}
__declspec(noinline) RemovalVector& RemovalVector::divide(float f) {x/=f;y/=f;z/=f;w/=f;return *this;}
__declspec(noinline) RemovalVector RemovalVector::operator+(const RemovalVector& v) const {RemovalVector a=*this;return a.add(v);}
__declspec(noinline) RemovalVector RemovalVector::operator-(const RemovalVector& v) const {RemovalVector a=*this;return a.subtract(v);}
__declspec(noinline) RemovalVector RemovalVector::operator*(float f) const {RemovalVector a=*this;return a.scale(f);}
__declspec(noinline) RemovalVector RemovalVector::operator/(float f) const {RemovalVector a=*this;return a.divide(f);}
__declspec(noinline) RemovalVector operator*(float f,const RemovalVector& v) {return v*f;}

float hkaNURBS_Distance3D(const RemovalVector&,const RemovalVector&);

void hkArrayUtil__reserve(void*,void*,int,int);
template<class T> struct KnotArray {
    T* data; int size; int capacity;
    __forceinline void reserve(int num) {
        HolderStub* h = hkMemoryRouter_getInstance();
        void* alloc = h->m_pAllocator;
        int cap = capacity & 0x3fffffff;
        if (cap < num) {
            int doubled = cap * 2;
            hkArrayUtil__reserve(alloc, this, num < doubled ? doubled : num, sizeof(T));
        }
    }
    __forceinline void resize(int num) {
        reserve(num);
        int added = num - size;
        T* start = data + size;
        for (int k = 0; k < added; ++k) new(start + k) T;
        size = num;
    }
// @fnv 0x00e556f0
};
// src: HAVOK_LIB 0x00e556f0
int __cdecl hkaNURBS_RemoveCurveKnot(int n,int p,KnotArray<float>& U,KnotArray<RemovalVector>& Pw,float u,int r,int s,int num,float TOL) {
    int m=n+p+1;
    int ord=p+1;
    int fout=(2*r-p-s)/2;
    int last=r-s;
    int first=r-p;
    RemovalVector temp[7];
    int t;
    for(t=0;t<num;++t) {
        int off=first-1;
        temp[0]=Pw.data[off];
        temp[last+1-off]=Pw.data[last+1];
        int i=first, j=last;
        int ii=1, jj=last-off;
        while(j-i>t) {
            float alfi=(u-U.data[i])/(U.data[i+ord+t]-U.data[i]);
            float alfj=(u-U.data[j-t])/(U.data[j+ord]-U.data[j-t]);
            temp[ii]=(Pw.data[i]-(1.0f-alfi)*temp[ii-1])/alfi;
            temp[jj]=(Pw.data[j]-alfj*temp[jj+1])/(1.0f-alfj);
            ++i; ++ii; --j; --jj;
        }
        if(j-i<t) {
            if(!(hkaNURBS_Distance3D(temp[ii-1],temp[jj+1])<=TOL)) break;
        } else {
            float alfi=(u-U.data[i])/(U.data[i+ord+t]-U.data[i]);
            if(!(hkaNURBS_Distance3D(Pw.data[i],alfi*temp[ii+t+1]+(1.0f-alfi)*temp[ii-1])<=TOL)) break;
        }
        i=first; j=last;
        while(j-i>t) {
            Pw.data[i]=temp[i-off];
            Pw.data[j]=temp[j-off];
            ++i; --j;
        }
        --first; ++last;
    }
    if(t==0) return 0;
    for(int k=r+1;k<=m;++k) U.data[k-t]=U.data[k];
    int j=fout, i=j;
    for(int k=1;k<t;++k) {
        if(k&1) ++i; else --j;
    }
    for(int k=i+1;k<=n;++k) { Pw.data[j]=Pw.data[k]; ++j; }
    Pw.resize(Pw.size-num);
    U.resize(U.size-num);
    return t;
}
