
// src/staging/blk_00e40000_o2_decl_variant.cpp - declaration variant unit created 2026-10-24 by decl_variants.py for paused function 0x00e54cb0: the skeleton of src/staging/blk_00e40000_o2.cpp
// with declarations corrected to what the original code does (unit: void __cdecl FUN_00e535a0(int a, int b); -> float __cdecl FUN_00e535a0(const void* a, const void* b);). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00e40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct FUN_00e428f0_class
{
    void Remove(void*);
    void hkpVehicleCastBatchingManager_removeVehicle(void* p);
};
int __cdecl hkpVehicleCastBatchingManager_getStandardFilterSize(int p);
extern "C" void __cdecl FUN_00cb0a60();
struct FUN_00e4e400_class
{
    FUN_00e4e400_class* __thiscall hkaAnnotationTrack_hkaAnnotationTrack();
};
void Object_UpdateFields_00e52860(const float* src, float* dst);
void Runtime_UpdateState_00e52ef0(const float* src, float* dst);
struct FUN_00e58780_Class
{
    int* GetElementPtr(int a, int b);
};
struct FUN_00e587c0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    float GetFloatAt(int idx, int base);
};
struct GlobalObjectO2_00d472a0
{
    int x;
};
GlobalObjectO2_00d472a0 g_0126e600;
void __stdcall FindResourceWithExpectedName(int, GlobalObjectO2_00d472a0*);
void __stdcall Runtime_ForwardCall_00e5c5b0(int a);
extern "C" void __stdcall FindResourceWithExpectedName(int, int);
struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c5f0;
void __stdcall Runtime_ForwardCall_00e5c5f0(int a);
struct FUN_00e459c0_class
{
    void SetBitMaskFlags(int a, int b);
};
struct FUN_00e45a10_class
{
    void __thiscall ClearFlags(int a, int b);
};
struct FUN_00e587b0_Class
{
    int* __thiscall GetElementAddress_00e587b0(int idx);
};
struct FUN_00e58880_Class
{
    float GetIndexedValue_00e58880(int offset);
};
int __cdecl Factorial(int count);
extern const float runtimeFloatSettingDefault132;
extern const float runtimeFloatSettingDefault255;
extern const float g_011c7344_arg1;
extern int DAT_010e62a4;
struct FUN_00e44280_struct
{
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
struct FUN_00e407d0_class
{
    void SetSlotValue(int idx, char b);
};
struct FUN_00e426f0_class
{
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
struct FUN_00e61480_class
{
    void hkxMeshSection_collectVertexPositions(int);
};
struct FUN_00e4ab50_class
{
    int m_00;
    int m_04;
    int* m_08;
    int m_0c;
    void __thiscall ApplyToAll(int a);
};
extern int DAT_010ec1fc;
struct FUN_00cb0a70
{
    void m(int);
};
struct FUN_00e4af80
{
    int vtbl;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_00e4af80* Set(int arg);
};
struct FUN_00e58b10_class
{
    void FillWithValue(float* out);
    void hkaSparseLSQMatrix_float_MultiplyAdd(int a, int b, int c);
    void hkaSparseLSQMatrix_float_Multiply(int a, int b, int c);
};
extern const char* const g_0126c5f0_arg1;
void __stdcall FindResourceWithExpectedName(int, int);
void __stdcall Runtime_ForwardCall_00e5c5d0(int a);
struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126eb10;
void __stdcall FindResourceWithExpectedName(int a, GlobalObjectO2_00d472a0* b);
void __stdcall Runtime_ForwardCall_00e5c630(int a);
struct GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126eac8;
void __stdcall FindResourceWithExpectedName(int, GlobalObjectO2_00d472a0*);
void __stdcall CallWithGlobalObject(int a);
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
struct HolderStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};
HolderStub* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, unsigned int auiNewSize);
struct ValueArray
{
    unsigned int* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};
struct FUN_00e41db0_cls
{
    int unk00;
    int unk04;
    ValueArray m_08;
    void AppendValue(unsigned int value);
};
class BE41DF0ReferencedObject
{
  public:
    BE41DF0ReferencedObject() throw() : m_sReferenceCount(1)
    {}
    virtual ~BE41DF0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
template <class T> struct BE41DF0Array
{
    BE41DF0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class FUN_00e41df0_cls : public BE41DF0ReferencedObject
{
  public:
    FUN_00e41df0_cls() throw();
    virtual ~FUN_00e41df0_cls();

    BE41DF0Array<void*> m_kEntries;
};
// FUN_00e42650: iterate an array of listener objects and notify each one.
struct EventListener
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
    virtual void v09(int a);
};
struct FUN_00e42650_cls
{
    int m_00;
    int m_04;
    EventListener** m_08;
    int m_0c;

    void hkpVehicleManager_addToWorld(int a);
};
struct FUN_00e42680_Item
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
    virtual void v10();
};
struct FUN_00e42680_cls
{
    int m_00;
    int m_04;
    FUN_00e42680_Item** m_08;
    int m_0c;

    void CallItemsVirtual();
};
extern "C" int DAT_010e5e9c;
struct FUN_00e43ac0_cls
{
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
float __cdecl ComputeScaledRatio(float param_1, float param_2, float param_3, float param_4);
extern "C" int DAT_010e5ff4;
struct FUN_00e43f30_cls
{
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
class BE468B0Base
{
  public:
    virtual ~BE468B0Base();

    int m_iRefCount;
};
class BE468B0InterfaceA
{
  public:
    virtual void OnA();
};
class BE468B0InterfaceB
{
  public:
    virtual void OnB();
};
class BE468B0InterfaceC
{
  public:
    virtual void OnC();
};
class BE468B0InterfaceD
{
  public:
    virtual void OnD();
};
class BE468B0Shape : public BE468B0Base,
                     public BE468B0InterfaceA,
                     public BE468B0InterfaceB,
                     public BE468B0InterfaceC,
                     public BE468B0InterfaceD
{
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
class BE468B0Listener
{
  public:
    virtual void OnEvent();
};
template <class T> class BE468B0Array
{
  public:
    BE468B0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class FUN_00e468b0_cls : public BE468B0Shape, public BE468B0Listener
{
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
struct S_e49fe0_B0
{
    virtual void d0();
    int unk4;
};
struct S_e49fe0_B8
{
    virtual void d8();
};
struct S_e49fe0_Bc
{
    virtual void dc();
};
struct S_e49fe0_B10
{
    virtual void d10();
};
struct S_e49fe0_B14
{
    virtual void d14();
};
struct FUN_00cbfba0 : S_e49fe0_B0, S_e49fe0_B8, S_e49fe0_Bc, S_e49fe0_B10, S_e49fe0_B14
{
    FUN_00cbfba0();
};
struct S_e49fe0_Arr
{
    int m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_e49fe0_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
};
struct FUN_00e49fe0 : FUN_00cbfba0
{
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
struct E4AAA0Element
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};
struct E4AAA0Array
{
    E4AAA0Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void reserve(E4AAA0Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(E4AAA0Element));
        }
    }

    void InsertElements(E4AAA0Allocator& alloc, int index, int numdel, const E4AAA0Element* p, int numtoinsert);
};
class E4AE50ReferencedObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    E4AE50ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual ~E4AE50ReferencedObject()
    {}
};
template <class T> class E4AE50Array
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E4AE50Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class FUN_00e4ae50 : public E4AE50ReferencedObject
{
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
struct FUN_00e4ae80_class
{
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
{}
struct S_00e4af60_helper
{
    void FUN_00cb0a60();
};
struct S_00e4af60_class
{
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
void __cdecl _hkWaveletTransform(float* base, unsigned int n);
struct PackedFormat
{
    unsigned char bits;
    unsigned char rawCount;
    unsigned short unk02;
    float range;
    float minimum;
};
void _hkQuantizeReal(const float* src, unsigned int count, const PackedFormat* format, unsigned char* dst);
void __cdecl PackFourFloatsToNibbles(const float* src, unsigned char* dst);
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
void __cdecl SwapBytes(void* arg);
inline void SwapByte(unsigned char& left, unsigned char& right)
{
    unsigned char temporary = left;
    left = right;
    right = temporary;
}
void __cdecl _handleEndianSignedQuaternion48(unsigned char* bytes);
extern "C" void _ReadWriteBarrier(void);
void __cdecl _handleEndianSignedQuaternion128(unsigned char* p);
class FUN_00e53160
{
  public:
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;

    FUN_00e53160(float fX, float fY, float fZ, float fW);
};
struct FUN_00e53180_cls
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e53180_cls(const float* pSrc);
};
struct FUN_00e531a0_struct
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;

    FUN_00e531a0_struct* ComputeValue_00e531a0(const FUN_00e531a0_struct* other);
};
// FUN_00e531d0: thiscall member of a 4-float vector; subtracts a vector
// (given by pointer/reference) from itself, in place, and returns itself.
struct FUN_00e531d0_cls
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e531d0_cls* SubtractFourComponents(const float* pOther);
};
struct FUN_00e53200_cls
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    FUN_00e53200_cls(float s);
};
struct E53230Color
{
    float r;
    float g;
    float b;
    float a;

    E53230Color& DivideByScalar(float fScalar);
};
struct FourFloatVector
{
    float x;
    float y;
    float z;
    float w;

    FourFloatVector& ComputeValue_00e531a0(int parameter);
    FourFloatVector ProcessAndReturnValue_00e53260(int parameter);
};
struct S_e53300_Vec;
struct S_e53300_Vec
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    S_e53300_Vec& FUN_00e53200(float f);
    S_e53300_Vec ScaleCopy(float f);
};
struct Quad4
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    Quad4* Eval(float t);
};
class FUN_00e53350_cls : public Quad4
{
  public:
    Quad4 EvalCopy(float t);
};
struct SpawnedObject
{
    void Method(float* pOut, float f);
};
float* __cdecl Object_ScaleCopy_Thunk(float* pOut, float f, SpawnedObject* pObj);
// Thin cdecl wrapper: forwards its first argument and a float to a
// thiscall method of the object given as the third argument, then hands
// the first argument back to the caller.
struct FUN_00e533c0_cls
{
    void SetValue(float* pOut, float fValue);
};
float* __cdecl SetValueAndReturn(float* pOut, float fValue, FUN_00e533c0_cls* pObj);
double __cdecl FUN_00ec6940(double value);
struct FourComponentVector
{
    float x, y, z, w;
    __declspec(noinline) FourComponentVector(float a, float b, float c, float d);
    FourComponentVector hkaNURBS_Point_floor() const;
};
FourComponentVector::FourComponentVector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
{}
struct FUN_00e53580_cls
{
    float GetIndexedValue_00e53580(int idx);
};
struct S_00e53590_Foo
{
    int* __thiscall GetElementAddress_00e53590(int index);
};
struct Vec4f
{
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
int __cdecl FindFloatInterval(int a, int b, float value, float** pp);
void __cdecl ComputeBasisFunctions(int span, float u, int degree, float** knots, float* basis);
int __cdecl FindInsertIndex(float value, float** table, int count);
int __cdecl CountRuns(float** param_1, int param_2);
bool* __cdecl IsSampleBoundary(bool* result, int index, float** samples, int endIndex);
int __cdecl hkaNURBS_MinIndex(float** array, int count);
float __cdecl hkaNURBS_Point_Dot(const void* a, const void* b);
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
class E54B50Vector4
{
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
int __cdecl FindFirstNonZero(int a, int b, int c);
struct E54C50IntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
inline void E54C50MemCpy4(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *reinterpret_cast<int*>(static_cast<char*>(dst) + i) =
            *reinterpret_cast<const int*>(static_cast<const char*>(src) + i);
}
void RemoveAndDecrement(int index, E54C50IntArray& array, int end);
struct Float4
{
    float x, y, z, w;
};
extern const double DAT_01016978;
void __cdecl hkaNURBS_CurvePoint(Float4* out, int a, int b, int c, int d, float input);
float __cdecl LookupAndConsume(const Float4* left, const Float4* right);
unsigned char* __cdecl CheckVerticesAboveThresholds(unsigned char* result, int a, int b, int c, int d, int last,
                                                    Float4** verticesPtr, float** valuesPtr, float** thresholdsPtr);
extern void __cdecl hkaNURBS_ApproximateCurve(int, int, int, int, float, int, int, int, int);
void __cdecl _ApproximateNURBSCurve(int i1, int i2, int i3, int i4, float f5, int i6, int i7, int i8, int i9);
struct FUN_00e58820_cls
{
    float* m_data;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    void FillWithValue(const float* value);
};
struct FUN_00e58890_Class
{
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
class AttrEntry_b5103
{
  public:
    int m_unk00;
    int m_unk04;
    int* m_pIntegerData;
};
class AttrLog_b5103
{
  public:
    virtual void Dummy0() throw();
    virtual void Dummy1() throw();
    virtual void Dummy2() throw();
    virtual void Assert(int level, unsigned int magic, const char* msg, const char* file, int line) throw();
};
class AttrTmp_b5103
{
  public:
    void Commit() throw();
    int m_unk00;
    int m_unk04;
};
class AttrWriter_b5103
{
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
class AttrStream_b5103
{
  public:
    AttrStream_b5103(unsigned int* buf, unsigned int size) throw();
    AttrWriter_b5103 m_w;
};
extern AttrLog_b5103* DAT_01268360_b5103;
class FUN_00e5c6b0_cls
{
  public:
    AttrEntry_b5103* FindPrimary(const char* name) throw();
    AttrEntry_b5103* FindSecondary(const char* name) throw();
    int GetBoolAttribute(const char* name, bool required, unsigned char* out);
};
struct ConfigValue
{
    unsigned type, identifier;
    const void* data;
};
struct CharBuffer
{
    char* destination;
    unsigned capacity, length;
    void FUN_00cb1600(char*, unsigned);
    CharBuffer* ProcessAndReturnValue_00cc01c0(const char*);
    CharBuffer* WriteName(const void*);
    void FUN_00cc00e0();
};
struct DiagnosticLogger
{
    virtual void open();
    virtual void close();
    virtual void flush();
    virtual void report(int, unsigned, const char*, const char*, int);
};
extern DiagnosticLogger* DAT_01268360;
extern const char str_010ecd20[], str_010eccfc[], str_010ecd0c[], str_010eccc8[];
struct ConfigTable
{
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
struct AttrLogBuf
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
struct AttrEntry
{
    int m_00;
    int m_04;
    float* m_08;
};
class AttrLogBuilder
{
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
class LogSink
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Log(int level, unsigned int tag, const char* msg, const char* file, int line);
};
extern LogSink* g_pAttrLogger;
class FUN_00e5c9b0_cls
{
  public:
    AttrEntry* FindAttr(const char* name);
    int GetFloatAttribute(const char* name, bool log, float* out);
};
// FUN_00e5cec0 - forwards this + four stack arguments to SpliceArray,
// with a literal zero inserted as the third argument.
struct FUN_00e5cdb0_class
{
    void __thiscall SpliceArray(int a, int b, int c, int d, int e);
    void __thiscall SpliceArray_Thunk(int a, int b, int c, int d);
};
struct S_00e5cfb0_Object
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
};
struct S_00e65ee0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void __thiscall queryOnTree(int* buffer, int value);
};
void __cdecl _hkMoppFindAllVirtualMachine_getAllKeys(S_00e5cfb0_Object* object, int value);
extern float DAT_0104e148;
struct FloatArray_e404b0
{
    float* data;
    int count;
};
template <class T> inline T MaxOf(T a, T b)
{
    return a > b ? a : b;
}
float __cdecl hkaFootstepAnalysisInfo_getMax(FloatArray_e404b0* arr);
extern float _DAT_0104da48;
float __cdecl FindMinFloat(int* param_1);
extern int DAT_010e60c4;
struct FUN_00e44070
{
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
class PrimaryE45
{
  public:
    virtual ~PrimaryE45();

    int unk04;
};
class ListenerAE45
{
  public:
    virtual void OnAdded();
};
class ListenerBE45
{
  public:
    virtual void OnRemoved();
};
class ListenerCE45
{
  public:
    virtual void OnActivated();
};
class ListenerDE45
{
  public:
    virtual void OnDeactivated();
};
class BaseE45 : public PrimaryE45, public ListenerAE45, public ListenerBE45, public ListenerCE45, public ListenerDE45
{
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
class EnabledFlagE45
{
  public:
    __forceinline EnabledFlagE45() : m_bEnableState(true)
    {}

    bool m_bEnableState;
};
class SlotTableE45
{
  public:
    __forceinline SlotTableE45()
        : m_pv00(0), m_pv04(0), m_pv08(0), m_pv0C(0), m_pv10(0), m_pv14(0), m_pv18(0), m_pv1C(0), m_pv20(0), m_pv24(0),
          m_pv28(0), m_pv2C(0), m_pv30(0), m_pv34(0), m_pv38(0), m_pv3C(0), m_pv40(0), m_pv44(0), m_pv48(0), m_pv4C(0),
          m_pv50(0), m_pv54(0), m_pv58(0), m_pv5C(0), m_pv60(0), m_pv64(0), m_pv68(0), m_pv6C(0), m_pv70(0), m_pv74(0),
          m_pv78(0), m_pv7C(0)
    {}

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
class FUN_00e45530_Manager : public BaseE45
{
  public:
    FUN_00e45530_Manager();
    virtual ~FUN_00e45530_Manager();

    EnabledFlagE45 m_kEnabled;
    SlotTableE45 m_kSlots;
};
struct AllocationHeap
{
    virtual void Unused0();
    virtual void* Allocate(unsigned int bytes);
    virtual void Unused8();
    virtual void UnusedC();
    virtual void Deallocate(void* pointer, unsigned int bytes);
};
struct CListener
{
    virtual ~CListener() throw()
    {}
};
template <typename T> struct HkSmallArray
{
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    HkSmallArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}

    int indexOf(const T& element) const
    {
        for (int i = 0; i < (int)m_iElementCount; ++i)
        {
            if (m_data[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
};
struct ExtendedListeners
{
    HkSmallArray<void*> first;
    HkSmallArray<CListener*> second;

    static void* operator new(size_t sz)
    {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        return ((AllocationHeap*)mgr->m_pAllocator)->Allocate(sz);
    }
};
struct ActorEntry
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
    ExtendedListeners* m_pExtendedListeners;

    ExtendedListeners* getExtendedListeners()
    {
        if (!m_pExtendedListeners)
        {
            m_pExtendedListeners = new ExtendedListeners;
        }
        return m_pExtendedListeners;
    }

    void __thiscall removeEntityListener_00c9c670(CListener* el);
};
template <typename T> struct HkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease()
    {
        HolderStub* mgr = hkMemoryRouter_getInstance();
        AllocationHeap* heap = (AllocationHeap*)mgr->m_pAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            heap->Deallocate(m_data, (cap & 0x3fffffff) * 4);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct CBase0
{
    virtual ~CBase0() throw()
    {}
    int m_ref;
};
struct CBase8
{
    virtual ~CBase8() throw()
    {}
};
struct CBaseC
{
    virtual ~CBaseC() throw()
    {}
};
struct CBase10
{
    virtual ~CBase10() throw()
    {}
};
struct CBase14
{
    virtual ~CBase14() throw()
    {}
};
struct CShape : CBase0, CBase8, CBaseC, CBase10, CBase14
{
    virtual ~CShape() throw()
    {}
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct FUN_00e46900 : CShape, CListener
{
    HkArray<ActorEntry*> m_kActorEntries;

    virtual ~FUN_00e46900() throw();
};
struct Ref
{
    void FUN_00c90510();
};
int hkMeshPrimitiveUtil_calculateNumIndices(unsigned char, int);
struct Entry
{
    Ref* name;
    Ref* pClassInfo;
    unsigned char type;
    unsigned char flags;
    unsigned short reserved;
    int count;
    unsigned char storage;
    unsigned char ReplaceImpactData;
    unsigned short reserved12;
    void* data;
    int unk18;
    int unk1c;
    int length() const
    {
        int t = type;
        return hkMeshPrimitiveUtil_calculateNumIndices(t, count);
    }
};
struct Allocator
{
};
#include "../../include/hkMemoryRouter.h"
hkMemoryRouter* getRouter();
int hkMeshPrimitiveUtil_calculateNumIndices(unsigned char type, int count);
extern "C" void hkArrayUtil__reserve(Allocator*, void*, int, int);
void hkString_memCpy(void*, const void*, int);
struct String
{
    void* value;
    void init() throw();
    void assign(const char*) throw();
};
struct ArrayBase
{
    void* data;
    int size;
    int capacity;
    ArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    static void grow(Allocator& heap, ArrayBase* a, int n, int stride)
    {
        int cap = a->getCapacity();
        if (cap < n)
            hkArrayUtil__reserve(&heap, a, n < 2 * cap ? 2 * cap : n, stride);
    }
    void reserve(Allocator& heap, int n, int stride)
    {
        grow(heap, this, n, stride);
    }
};
template <class T> struct Arr : ArrayBase
{
    void reserve(Allocator& heap, int n)
    {
        ArrayBase::reserve(heap, n, sizeof(T));
    }
    void SetSizeAndGrow(Allocator& heap, int n)
    {
        reserve(heap, n);
        size = n;
    }
    T* expand(Allocator& heap, int n)
    {
        int old = size;
        reserve(heap, old + n);
        size += n;
        return (T*)data + old;
    }
};
struct Base
{
    virtual void dummy();
    unsigned short flags;
    short refs;
    Base()
    {
        refs = 1;
    }
};
struct FUN_00e4a1d0 : Base
{
    Arr<Entry> entries;
    Arr<unsigned short> shorts;
    Arr<unsigned int> ints;
    String label;
    FUN_00e4a1d0(const Entry* source, int count);
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
            if (data[i] < *minOut)
                *minOut = data[i];
            else if (data[i] > *maxOut)
                *maxOut = data[i];
            if (data[i + 1] < *minOut)
                *minOut = data[i + 1];
            else if (data[i + 1] > *maxOut)
                *maxOut = data[i + 1];
            if (data[i + 2] < *minOut)
                *minOut = data[i + 2];
            else if (data[i + 2] > *maxOut)
                *maxOut = data[i + 2];
            if (data[i + 3] < *minOut)
                *minOut = data[i + 3];
            else if (data[i + 3] > *maxOut)
                *maxOut = data[i + 3];
        }
    }
    for (; i < count; ++i)
    {
        if (data[i] < *minOut)
            *minOut = data[i];
        else if (data[i] > *maxOut)
            *maxOut = data[i];
    }
}
void __cdecl InitFormatFromData(float* data, unsigned int count, E51F00Format* format, unsigned int numBits,
                                unsigned int rawStart);
Vec4f VectorMax(const Vec4f& a, const Vec4f& b);
struct L
{
    int* m_00;
    int m_04;
};
void __cdecl hkaNURBS_Remove(int idx, L* list);
struct HolderView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* volatile m_pAllocator;
};
struct FloatArrayRef
{
    float* data;
    int size;
    unsigned int capacity;
};
int __cdecl hkaNURBS_DegreeElevateKnotVector(FloatArrayRef* array, int count);
struct ArrayAllocator;
struct FloatArray;
void hkArrayUtil__reserve(ArrayAllocator* alloc, FloatArray* arr, int newCap, int elemSize);
struct FloatArray
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void reserve(ArrayAllocator& alloc, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int c = 2 * cap;
            hkArrayUtil__reserve(&alloc, this, n < c ? c : n, 4);
        }
    }
};
hkMemoryRouter* GetMemoryRouter();
int RemoveAdjacentDuplicates(FloatArray* arr, int last);
// Element-wise subtract another matrix of the same shape from this one.
class E87E0Matrix
{
  public:
    float* m_pfData;
    int unk04;
    int unk08;
    int m_iRows;
    int m_iColumns;

    float& Element(int i)
    {
        return m_pfData[i];
    }
    E87E0Matrix& SubtractMatrixElements(const E87E0Matrix& kOther);
};
class CE588A0Vector
{
  public:
    double Get(int iIndex);
    int GetSize();
};
float __cdecl DotProduct(CE588A0Vector* pkA, CE588A0Vector* pkB);
struct Stand_e58d90
{
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
static inline float QSqrt(float v)
{
    return (float)sqrt(v);
}
void UnpackQuaternion(const unsigned int* packed, float* quat);
