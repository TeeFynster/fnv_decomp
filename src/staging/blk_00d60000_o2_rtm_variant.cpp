#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/staging/blk_00d60000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d60000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00d60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
// Retain this unit's original SSE intrinsic storage and declarations for VC9 code generation.
// Exe 0x00d6b8e0 FUN_00d6b8e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    void _mm_store_ss(float*, LocalM128);
}
#define _INCLUDED_MM2
#include "../../include/FinishingFlag.h"
#include "../../include/hkBool.h"
#include "../../include/hkError.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkArray.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkSmallArray.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkOstream.h"
#include "../../include/hkTransform.h"
#include "../../include/hkRotation.h"
#include "../../include/hkQuaternion.h"
#include "../../include/hkQsTransform.h"
#include "../../include/hkVector4.h"
#include "../../include/hkpRigidBody.h"
#include "../../include/hkpPhysicsContext.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkStackMemory.h"
void __cdecl hkpInactiveContactPointViewer_create(void);
struct Registry_00dd9380
{
    void* Register(char const*, void(__cdecl*)(void));
};
extern int DAT_01269cd0;
extern void* DAT_01269008;
void RegisterContactPointsInactive();
// Constructor of the class whose vftables live at 0x010d1fb0 / 0x010d1f90 /
// 0x010d1f80 / 0x010d1f70: it calls the immediate base constructor and then
// installs the derived vftable pointers for the four base sub-objects.
extern int DAT_010d1fb0;
extern int DAT_010d1f90;
extern int DAT_010d1f80;
extern int DAT_010d1f70;
struct FUN_00d68770_cls
{
    int* m_pVtbl00;
    int m_unk04;
    int* m_pVtbl08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int* m_pVtbl20;
    int m_unk24;
    int* m_pVtbl28;

    void BaseConstruct(int aParam, int aFlags);
    FUN_00d68770_cls* Construct(int aParam);
};
void* __stdcall hkpInactiveContactPointViewer_getIslands(char* a1);
struct FnvCpu_FUN_00d687c0_CpuBlock;
struct FnvCpu_FUN_00d687c0_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00d687c0_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d687c0_CpuAllocator* allocator;
};
void* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d687c0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d687c0_CpuBlock* Construct(unsigned int value);
};
void* __cdecl hkpInactiveContactPointViewer_create(unsigned int value);
extern "C" int DAT_010d203c;
extern "C" int DAT_010d201c;
extern "C" int DAT_010d200c;
extern "C" int DAT_010d1ffc;
void __stdcall FUN_00de29b0(int a, int b);
struct FUN_00d68840_cls
{
    void* m_p00;
    int m_i04;
    void* m_p08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    void* m_p20;
    int m_i24;
    void* m_p28;

    void* Init(int a);
};
void* __stdcall hkpActiveContactPointViewer_getIslands(void* pObject);
// FUN_00d688f0 : tiny global getter.
// Reads the 4-byte global at DAT_0126900c and returns it in eax.
extern int DAT_0126900c;
int __cdecl Runtime_GetDAT0126900c();
extern char DAT_0126905c;
void* __cdecl Object_GetGlobalObjectAddress_00d6ade0();
struct S_00d6adf0_Obj
{
    virtual void vfn00(int arg);
};
void __cdecl Runtime_ForwardCall_00d6adf0(S_00d6adf0_Obj* obj);
extern int DAT_0126908c;
int* __cdecl Object_GetGlobalObjectAddress_00d6ae00();
struct FUN_00c90e00_Obj
{
    void __thiscall FUN_00c90e00(int value);
};
void __cdecl Runtime_ProcessState_00d6ae90(FUN_00c90e00_Obj* pObj, int iValue);
// 13-byte cdecl forwarder: loads the object pointer, fetches its vtable and
// calls the first virtual slot with a literal 0 argument.
struct VtblForwarder
{
    virtual int v0(int);
};
int __cdecl Runtime_ForwardCall_00d6aeb0(VtblForwarder* p);
extern int DAT_01269104;
void* __cdecl Object_GetGlobalObjectAddress_00d6aee0();
struct ResultFlag
{
    bool value;
    ResultFlag(bool flag) : value(flag)
    {}
    operator bool() const
    {
        return value;
    }
    ResultFlag& operator=(bool flag)
    {
        value = flag;
        return *this;
    }
};
struct MotionSettings
{
    float value0;
    float value1;
    float value2;
    float value3;
    float value4;
    float value5;
    float value6;
    float value7;
    float value8;
    float value9;
    float value10;
    float value11;
    ResultFlag IsValid();
};
struct D6C180Command
{
    union
    {
        float m_fValue;
        unsigned char m_ucType;
    };
    unsigned char m_ucFlag;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
};
extern const double g_dD6C180Offset;
void __fastcall WriteCommand(D6C180Command** ppkCursor, unsigned char ucFlag);
struct Inner
{
    void Tail();
};
struct FUN_00d76f90_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void ForwardCall_00d76f90();
};
inline void* operator new(unsigned int, void* pvMem)
{
    return pvMem;
}
class hkMemberD6A
{
  public:
    hkMemberD6A(FinishingFlag flag) throw();

    int unk00;
    int unk04;
    int unk08;
};
class hkBaseD6A
{
  public:
    __forceinline hkBaseD6A()
    {}
    virtual ~hkBaseD6A();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
};
class hkDerivedD6A : public hkBaseD6A
{
  public:
    __forceinline hkDerivedD6A(FinishingFlag flag) : m_kMemberDescriptor(flag)
    {
        m_iType = -16;
    }
    virtual ~hkDerivedD6A();

    hkSmallArray<int> m_ppData;
    hkMemberD6A m_kMemberDescriptor;
    int m_iType;
};
void __cdecl ConstructHkDerived(void* pvObject, int iFinishFlag);
class FUN_00d60540 : public hkReferencedObject
{
  public:
    FUN_00d60540(FinishingFlag flag);
    virtual ~FUN_00d60540();
};
extern int DAT_010d14f8;
extern int DAT_0102e388;
struct D60590Callback
{
    void FUN_00c905b0();
};
struct D60590Object
{
    int* vtable;
    int unk04;
    D60590Callback* callback;

    void ReleaseReference_00d60590();
};
void __stdcall WriteSwapped(char**, int, int);
void __stdcall FUN_00d60900(char* p);
struct FUN_00d60600_class
{
    void __thiscall WriteSwapped(int a, int b, int c);
    void __thiscall WriteSwapped_Thunk(int a, int b);
};
struct FUN_00d61470_Class
{
    void* ReturnSelf();
};
char* __cdecl hkString_strStr(char* pcHaystack, const char* pcNeedle);
inline char toLowerD614(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}
int __cdecl hkString_strStr(int a1, int a2);
struct FUN_00d61520_cls
{
    int unk00;
    int FindOffset(int a, int b, int c);
};
struct FnvString
{
    const char* text;
    int FUN_00d61560(const char* other);
};
inline char toLowerD615(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}
struct FNV_00d61600_Buffer
{
    unsigned char* data;
    int length;
    int FindCharacter(unsigned char character, int start, int limit);
};
struct FUN_00d61640_cls
{
    char* m_data;
    int m_fRestLength;

    int FindLastCharInRange(char c, int startIndex, int endIndex);
};
struct FUN_00d61680_Obj
{
    int unk00;
    void __thiscall FUN_00d61680(unsigned int param);
};
int __cdecl hkString_strCmp(int, int);
void __cdecl CompareStringsCaseInsensitive(void* pvOwner, int iValue);
struct FUN_00d616a0_cls
{
    void* m_pOwnerObject;

    void FUN_00d616a0(int iValue);
};
int __stdcall FUN_00d61680(unsigned int value);
int __stdcall Object_ForwardCall_00d616e0(unsigned int value);
int __cdecl hkString_strLen(int s);
struct FUN_00d61700_cls
{
    char* m_00;
    int m_04;
    int EndsWith(char* s);
};
int __cdecl hkString_strLen(const char* str);
static inline int tolower_custom(char c)
{
    if ((unsigned char)(c - 'A') <= 25)
        return c + 0x20;
    return c;
}
struct FUN_00d61750_cls
{
    char* m_data;
    int m_fRestLength;

    int EndsWithIgnoreCase(const char* suffix);
};
struct FUN_00d617d0_cls
{
    char* m_p00;
    int m_i04;
    void RemoveFront(int count);
};
struct hkMathD618
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};
__forceinline hkMemoryAllocator& hkContainerTempAllocator::get(void*)
{
    return static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->temp();
}
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap();
}
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int doubled = 2 * capacity;
        hkArrayUtil::_reserve(alloc, this, n < doubled ? doubled : n, sizeof(T));
    }
}
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
}
template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl hkString_memCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();
template <class T, int N> class hkInplaceArrayD61B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    hkInplaceArrayD61B() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* begin()
    {
        return m_data;
    }
    __forceinline void reserve(hkMemoryAllocator& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            hkArrayUtil__reserve(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->temp(), n);
        m_iElementCount = n;
    }
};
class FUN_00d61b10
{
  public:
    hkInplaceArrayD61B<char, 128> m_kStringBuffer;

    FUN_00d61b10(const char* pcString, int iLength) throw();
};
int __cdecl hkString_strLen(int);
void* __cdecl hkMemoryRouter_getInstance();
struct FUN_00d62630_Obj
{
    void FUN_00d62630(int a1, int a2, int a3, int a4);
};
struct FUN_00d61df0_cls
{
    int unk00;
    int unk04;
    FUN_00d61df0_cls* FUN_00d61df0(int arg);
};
int __cdecl hkString_strLen(const char* pcString) throw();
void __cdecl hkString_memCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
namespace hkRouterD620 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl hkMemUtil_memCpy_00d2caa0(void* pvDst, void* pvSrc, unsigned int uiNumBytes);
int __cdecl hkString_strLen(int value);
void* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(int value1, int value2, int value3, int value4);
void __cdecl hkMemUtil_memCpy_00d2caa0(void* value1, unsigned int value2, unsigned int value3);
struct D62080_Audio
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct D62080_Object
{
    unsigned char* m_data;
    int m_uiItemCount;
    unsigned int m_pRayCursor;

    void __thiscall FUN_00d62080(int param2, int param3);
};
extern int __cdecl hkString_strLen(int value);
struct FUN_00d62100_Class
{
    int __thiscall FUN_00d62630(int context, int first, int second, int third);
    int __thiscall FUN_00d62100(int first, int second, int third);
};
struct SearchBase
{
    int FUN_00d61cc0();
};
struct SearchController : SearchBase
{
    int FindLastCharInRange(int token, int start, int limit);
    int FUN_00d61fc0(int start, int position);
    int FUN_00d62140();
};
struct FUN_00d623a0
{
    char* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;
    char m_kStorage;

    void FUN_00d61c10(const char* str);

    FUN_00d623a0(const hkStringPtr& str);
};
struct FUN_00d623d0
{
    void* m_p00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    void* m_p1c;
    int m_i20;
    void* m_p24;

    void AppendStrings(int a, int b, int c, int d, int e, int f);
    FUN_00d623d0(int a, int b, int c, int d, int e, int f);
};
struct FUN_00d62100_Obj
{
    int FUN_00d62100(int a, int b, int c);
};
struct FUN_00d62580_Cls
{
    int FUN_00d62580(int a, int b);
};
class hkObjectD626
{
  public:
    int ReplaceRange(int a, int b, int c, int d, int e);
    int FUN_00d62630(int a, int b, int d, int e);
};
struct FUN_00ddccb0_Obj
{
    void FUN_00ddccb0(int a1);
};
struct FUN_00d62ef0_cls
{
    int* unk00;
    int unk04;
    int* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* unk20;
    int unk24;
    unsigned char unk28;

    FUN_00d62ef0_cls* UpdateState_00d62ef0(int aParam, unsigned char aValue);
};
extern int DAT_010d1720;
extern int DAT_010d1700;
extern int DAT_010d16f0;
struct HeapAllocator
{
    virtual void* GetStats();
    virtual void* Allocate(unsigned int bytes);
};
struct MemorySystem
{
    void* unknown00;
    void* unknown04;
    void* unknown08;
    void* unknown0c;
    HeapAllocator* heap;
};
struct HeapBlockMetadata
{
    unsigned int flags;
    unsigned short size;
    unsigned short reserved;
    HeapBlockMetadata* UpdateState_00d62ef0(void* data, unsigned int enabled);
};
void* __cdecl AllocateRecordWithData(void* data);
struct Allocator_d632c0
{
    virtual void slot00();
    virtual void* Allocate(unsigned int size);
};
struct Holder_d632c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator_d632c0* allocator;
};
struct Base1_d632c0
{
    virtual void vfn1();
    unsigned short size;
    unsigned short ref;
};
struct Base2_d632c0
{
    virtual void vfn2();
};
struct Obj_d632c0 : Base1_d632c0, Base2_d632c0
{
    Obj_d632c0* hkpWorldMemoryViewer_hkpWorldMemoryViewer(int a, int b);
};
Base2_d632c0* hkpWorldMemoryViewer_create(int aiValue);
struct hkContainerD633
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
    void** m_items;
    int m_uiItemCount;
};
struct hkListenerD633
{
    virtual void v00(void* p);
    virtual void v04(void* p);
};
struct hkObjD633
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkListenerD633 m_kListener;
    hkContainerD633* m_container;

    void NotifyContainerItems();
};
class FUN_00ddf050_cls
{
  public:
    virtual ~FUN_00ddf050_cls() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addObject(const char* pcName, const void* pvObject, int iFlags) throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char* m_data;
    int m_iElementCount;

    void ClearContainer() throw();
    void Clear_Thunk(int i) throw();
    void Object_Clear_Thunk() throw();

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    bool hasData() const
    {
        return m_iElementCount > 0 && m_data;
    }
    char* getData() const
    {
        return m_iElementCount > 0 ? m_data : 0;
    }
};
class hkDisplayHandlerD633
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual void V1C() throw();
    virtual void V20() throw();
    virtual void V24() throw();
    virtual void V28() throw();
    virtual void V2C() throw();
    virtual void V30() throw();
    virtual void V34() throw();
    virtual void V38() throw();
    virtual void V3C() throw();
    virtual void WriteOutput(const char* pcData, int iLength) throw();
};
class FUN_00d63370_class
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkDisplayHandlerD633* m_pDisplayHandler;
    int unk14;
    int unk18;
    hkpPhysicsContext* m_iValueAtOffset0C;
    FUN_00ddf050_cls m_pStreamWriter;

    void UpdatePhysicsDebugDisplay(float fFrameTime) throw();
};
extern int DAT_01268fc8;
int __cdecl Object_GetDAT_01268fc8_00d63420();
void* __cdecl hkMemoryRouter_getInstance();
class FUN_00d63340
{
  public:
    virtual ~FUN_00d63340() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        ((hkMemoryRouter*)hkMemoryRouter_getInstance())
            ->heap()
            .blockFree(p, static_cast<FUN_00d63340*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d63340* Destroy(unsigned int uiFlags) throw();
};
class hkPart0D642
{
  public:
    virtual ~hkPart0D642() throw();
    int unk04;
};
class hkPart8D642
{
  public:
    virtual void p8() = 0;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class hkPart20D642
{
  public:
    virtual void p20() = 0;
    int unk24;
};
class hkBaseD642 : public hkPart0D642, public hkPart8D642, public hkPart20D642
{
};
class FUN_00ddccb0 : public hkBaseD642
{
  public:
    FUN_00ddccb0(void* p) throw();
};
class hkIfaceAD642
{
  public:
    virtual void a0() = 0;
};
class hkIfaceBD642
{
  public:
    virtual void b0() = 0;
};
class FUN_00d64260 : public FUN_00ddccb0, public hkIfaceAD642, public hkIfaceBD642
{
  public:
    hkArray<void*> m_ppData;

    FUN_00d64260(void* p) throw();
    virtual ~FUN_00d64260() throw();
    virtual void p8();
    virtual void p20();
    virtual void a0();
    virtual void b0();
};
struct FnvCpu_FUN_00d645f0_CpuBlock;
struct FnvCpu_FUN_00d645f0_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00d645f0_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d645f0_CpuAllocator* allocator;
};
void* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d645f0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d645f0_CpuBlock* FUN_00d64260(unsigned int value);
};
void* __cdecl hkpSweptTransformDisplayViewer_create(unsigned int value);
struct FUN_00d65250_cls
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    unsigned char unk60;
    unsigned char unk61;

    void __thiscall SetUnk61(unsigned char value);
};
struct FnvCpu_FUN_00d65260_CpuObject
{
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
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned char unk64;
    unsigned char value;
    void SetValue_00d65260(unsigned char arg0);
};
struct FnvCpu_FUN_00d65270_CpuObject
{
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
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned char unk60;
    unsigned char unk61;
    unsigned char value;
    void SetValue(unsigned char arg0);
};
struct FUN_00d65280_cls
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    char unk60;
    char unk61;
    char unk62;
    bool m_63;

    void SetField63_00d65280(bool bValue);
};
struct FnvCpu_FUN_00d65290_CpuObject
{
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
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned char value;
    void SetValue(unsigned char arg0);
};
void __cdecl nullsub_103();
extern "C" void __cdecl hkMathUtil_decompose4x4ColTransform();
void __cdecl Object_HkMathUtil_decompose4x4ColTransform_Thunk();
class FUN_00d733e0
{
  public:
    FUN_00d733e0();

    int m_iFirst;
    int m_iSecond;
    bool m_bEnableState;
};
struct FUN_00d73400_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void UpdateFields_00d73400();
};
extern hkError* DAT_01268360;
struct hkpTransformCollapseUtilResultsD734
{
    int m_iFirstResult;
    int m_iSecondResult;
    int m_iThirdResult;
    int m_iFourthResult;

    void PrintResults() throw();
};
struct FnvCpu_FUN_00d76d80_CpuTarget
{
    void ProcessEntries_00d81340();
};
struct FnvCpu_FUN_00d76d80_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00d76d80_CpuTarget* target;
    void ForwardCall_00d76d80();
};
extern int DAT_010d14f8;
struct hkAllocatorD608
{
    virtual void vf00();
    virtual void* Allocate(int bytes);
};
struct hkRouterD608
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    hkAllocatorD608* allocator;
};
struct FUN_00d274c0
{
    void* unk00;
    unsigned short allocatedSize;
    FUN_00d274c0(int first, int second, hkBool enabled);
};
struct FUN_00d608a0
{
    void* vptr;
    unsigned short unk04;
    unsigned short count;
    FUN_00d274c0* child;
    unsigned char mode;
    FUN_00d608a0(int first, int second, unsigned char mode);
};
int __cdecl hkString_strCmp(int, int);
struct R
{
    volatile char value;
    R(bool b) : value(b)
    {}
};
struct S
{
    int value;
    R IsLessThan(int other) const;
};
namespace hkRouterD619 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl ResizeAudioStream(hkMemoryAllocator& kAlloc, void* pArray, int iElemSize);
template <class T> __forceinline void constructWithCopyD619(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <class T> inline void hkArrayCopyD61(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}
class FUN_00d619d0
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    FUN_00d619d0& operator=(const FUN_00d619d0& a);
};
struct FUN_00d61a50_cls
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int* FUN_00d61a50(int value);
};
namespace fnvc_adapt {
char* __cdecl hkString_strLen(int value);
}
void __cdecl hkArrayUtil__reserve(int allocator, FUN_00d61a50_cls* array, int capacity, int value);
void __cdecl hkString_memCpy(int* data, int value, char* source);
template <class T> __forceinline void hkArrayCopyD61B8(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; ++i)
        pDst[i] = pSrc[i];
}
template <class T, int N> class hkInplaceArrayD61B8
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline hkInplaceArrayD61B8(const hkInplaceArrayD61B8& kOther) throw()
        : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {
        hkMemoryAllocator& kAlloc = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->temp();
        if (getCapacity() < kOther.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int n = kOther.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(n));
            m_iCapacityState = n / sizeof(T);
        }
        m_iElementCount = kOther.m_iElementCount;
        hkArrayCopyD61B8(m_data, kOther.m_data, m_iElementCount);
    }
};
class FUN_00d61b80
{
  public:
    hkInplaceArrayD61B8<char, 128> m_kStringBuffer;

    FUN_00d61b80(const FUN_00d61b80& kOther) throw();
};
struct C6DF60Router;
C6DF60Router* __cdecl _FNV_e03300_arena();
struct C6DF60Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct C540BC0Allocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct FUN_00d61cc0_t
{
    char* m_pBuffer;
    int m_iFadeIndex;
    int m_iState2;
    void FUN_00d61cc0();
};
void __cdecl ArrayReserveImpl(void*, void*, int, int);
namespace hkRouterD61F {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
namespace hkRouterD62 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
// 0x00d62f20 returns the +8 process interface of the world snapshot viewer (ctor 0x00d62ef0), not a collision agent.
class WorldSnapshotProcessInterface
{
  public:
    virtual void cleanup();
};
class FUN_00d62ef0 : public hkReferencedObject, public WorldSnapshotProcessInterface
{
  public:
    FUN_00d62ef0(void* contactMgr, int flags) throw();

    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
};
WorldSnapshotProcessInterface* __cdecl hkpWorldSnapshotViewer_createNative(void* contactMgr);
static void Object_UpdateFields_00d6c1a0(int* piValue);
void E6C1A0Adjust(int* piValue);
// FUN_00d73400's body must be in-TU so VC9 knows it clobbers only eax:
// that is what lets the ctor keep `this` live in ECX across the call
// (matches orig: xor eax,eax; mov [ecx..0xc],eax; call; mov eax,ecx; ret).
class FUN_00d73410;
struct Z0
{
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
    void UpdateFields_00d73400();
};
// src: GUESS 0x00d73400 (confidence: low)
__declspec(noinline) void Z0::UpdateFields_00d73400()
{
    m_iUnk00 = 0;
    m_iUnk04 = 0;
    m_iUnk08 = 0;
    m_iUnk0C = 0;
}
class FUN_00d73410
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
    FUN_00d73410();
};
struct Node
{
    unsigned unk00, unk04, unk08, unk0c;
    void* active;
    Node* left;
    Node* right;
    unsigned unk1c, unk20, unk24, unk28, flags;
};
void __cdecl AssignNodeFlags(Node** nodes, int count, unsigned seed);
struct FUN_00d7e740_cls
{
    int hkgpConvexHullImpl_generateIndexedFaces_unsigned_char_unsigned_short(int iArg0, int iArg1, bool iFlag, int iArg2);
};
struct FUN_00d76c20_cls
{
    int m_00;
    int m_04;
    FUN_00d7e740_cls* m_target;

    int ForwardToTarget(int iSelector, int iArg0, int iArg1, int iArg2);
};
// 0x00d794e0 tests a nonzero hit flag from 0x00d79250; this is not the hkResult status enum.
struct CollisionHitFlag
{
    int m_bHasHit;
};
void __cdecl hkgpConvexHull_booleanSplit(void* a, void* b, CollisionHitFlag* out, int flags, float f);
bool __cdecl hkgpConvexHull_booleanIntersection(void* a, void* b, CollisionHitFlag* out, float f);
static int ToLowerCase(char c);
volatile char g_d61430_c;
char g_d61430_sink;
void d61430_caller();
static int toupper_00d61450(char c);
volatile char g_d61450_c;
char g_d61450_sink;
void d61450_caller();
struct D6C1B0Owner
{
    int unk00;
    void(__cdecl* unk04)(int, int, D6C180Command**);
    int unk08;
};
extern "C" D6C180Command** d6c1b0_cursor_src(void);
volatile int g_d6c1b0_a1;
D6C1B0Owner* volatile g_d6c1b0_owner;
static void callBridgeFromAtom(D6C180Command** ppkCursor, D6C1B0Owner* pOwner, int a1);
void d6c1b0_caller(void);

extern "C" LocalM128 g_d6c1d0_src[4];
extern "C" LocalM128 g_d6c1d0_mat[4];
extern "C" LocalM128 g_d6c1d0_out[4];
static void Runtime_MultiplyAffineTransformColumns(LocalM128* __restrict out, const LocalM128* __restrict a, const LocalM128* __restrict b);
void fnv_probe_d6c1d0();
extern float DAT_011b6924;
extern float DAT_011b6928;
extern float DAT_010c8440;
struct IntegratorD720
{
    float unk00;
    float offset;
    float unk08;
    float unk0c;
    float state;
};
static float Object_ComputeValue_00d720a0(IntegratorD720* self, float input, float step);
IntegratorD720* volatile integratorD720;
volatile float inputD720, stepD720, resultD720;
void invokeD720();
struct FUN_00d74dc0_cls
{
    void* GetFieldAtOffset10Address_00d74dc0();
};
#include <stdarg.h>
void* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* getRouterD624()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
int __cdecl hkString_vsnprintf(char* pcBuf, int iBufSize, const char* pcFormat, va_list kArgs) throw();
// 0x00d62420 formats text then calls string-buffer append 0x00d62080 (also bound to InlineStorageString).
class FormattedStringBuffer
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;

    void FUN_00d62080(const char* pcBuf, int iNumBytes) throw();
    void WriteFormatted(const char* pcFormat, ...) throw();
};
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d68830();
    int unk04;
};
struct SecondaryBase
{
    virtual void FUN_00d68830();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68830
    virtual void FUN_00d68830();
};
Derived::Derived()
{}
struct Node_d6c580
{
    unsigned short m_type;
    char pad[0x12];
    Node_d6c580* m_parent;
};
static Node_d6c580* Object_ProcessEntries_00d6c580(Node_d6c580* n);
Node_d6c580* zz_probe_d6c580(Node_d6c580* n);
static void Runtime_UpdateState_00d6c590(int* p);
void zz_probe_d6c590(int* p);
class RotationColumns
{
  public:
    __forceinline RotationColumns()
    {}
    __forceinline RotationColumns(const RotationColumns& other)
    {
        columns[0] = other.columns[0];
        columns[1] = other.columns[1];
        columns[2] = other.columns[2];
    }
    __forceinline hkVector4& column(int i)
    {
        return columns[i];
    }
    __forceinline const hkVector4& column(int i) const
    {
        return columns[i];
    }
    hkVector4 columns[3];
};
static __forceinline void MultiplyDirection(hkVector4& output, const RotationColumns& rotation, const hkVector4& input)
{
    const LocalM128 componentX = _mm_shuffle_ps(input.value, input.value, 0);
    const LocalM128 termX = _mm_mul_ps(rotation.column(0).value, componentX);
    const LocalM128 componentY = _mm_shuffle_ps(input.value, input.value, 0x55);
    const LocalM128 termY = _mm_mul_ps(rotation.column(1).value, componentY);
    const LocalM128 componentZ = _mm_shuffle_ps(input.value, input.value, 0xaa);
    const LocalM128 termZ = _mm_mul_ps(rotation.column(2).value, componentZ);
    output.m_vComponents = _mm_add_ps(_mm_add_ps(termX, termY), termZ);
}
class Orientation : public RotationColumns
{
};
class RigidTransform
{
  public:
    __forceinline Orientation& rotation()
    {
        return orientation;
    }
    __forceinline const Orientation& rotation() const
    {
        return orientation;
    }
    Orientation orientation;
    hkVector4 translation;
};
template <class T> class QueryValue
{
  public:
    __forceinline T get() const
    {
        return value;
    }
    T value;
};
struct ConstraintQuery
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    QueryValue<const RigidTransform*> transformA;
    QueryValue<const RigidTransform*> transformB;
};
struct LocalOrientations
{
    int unk00, unk04, unk08, unk0c;
    Orientation localA;
    Orientation localB;
};
static __forceinline void RotateDirections(const RotationColumns& rotation, const hkVector4* source, int count,
                                           hkVector4* destination)
{
    RotationColumns saved = rotation;
    int i = count - 1;
    do
    {
        MultiplyDirection(destination[i], saved, source[i]);
    } while (--i >= 0);
}
static void Object_RotateBodyVectorBundles(const LocalOrientations& local, const ConstraintQuery& input, RigidTransform& outputA,
                         RigidTransform& outputB);
void RotateLocalFrames(const LocalOrientations& local, const ConstraintQuery& input, RigidTransform& outputA,
                       RigidTransform& outputB);
extern LocalM128 DAT_01267e30;
struct D73390Source
{
    float value0[4];
    float value1[4];
    float value2[4];
};
struct D73390Data
{
    float value0[4];
    float value1[4];
    float value2[4];
    float value3[4];

    void hkMatrix4_resetFourthRow();
};
void __cdecl hkMatrix4_resetFourthRow_ProcessState_00d73390(D73390Source* source, int count);
inline char hkToUpperD618(char c)
{
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}
struct TransformContext
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
    const LocalM128* m_pM1;
    const LocalM128* m_pM2;
};
struct TransformPair
{
    LocalM128 m_row[4];
};
static void Object_TransformVectorBundles(TransformPair* dest, const LocalM128* src, const TransformContext* ctx, LocalM128* out);
TransformPair* volatile inputDest;
const LocalM128* volatile inputSource;
const TransformContext* volatile inputContext;
LocalM128* volatile inputOut;
void invokeTransform();
inline void SetTransformedPositionC320(hkVector4& output, const RigidTransform& frame, const hkVector4& input)
{
    const LocalM128 v = input.value;
    LocalM128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), frame.orientation.column(1).value);
    LocalM128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), frame.orientation.column(0).value);
    LocalM128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), frame.orientation.column(2).value);
    output.value = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, frame.translation.value));
}
struct PivotsC320
{
    hkVector4 m_unk00;
    hkVector4 m_kPivotA;
    hkVector4 m_kPivotB;
};
struct TransformOutputC320
{
    RigidTransform* p;
    TransformOutputC320(RigidTransform* value) : p(value)
    {}
};
static void __cdecl Object_TransformBodyPivots(const PivotsC320* pivots, const ConstraintQuery* bodies, TransformOutputC320 outA,
                                 TransformOutputC320 outB);
const ConstraintQuery* volatile bodiesSourceC320;
const PivotsC320* volatile pivotsSourceC320;
RigidTransform* volatile outASourceC320;
RigidTransform* volatile outBSourceC320;
void InvokeTransformC320();

extern "C" double __cdecl sqrt(double);
static __forceinline float localSqrt(float x)
{
    return (float)sqrt((double)x);
}
typedef float hkReal;
typedef LocalM128 hkQuadReal;
extern const hkQuadReal DAT_010c71e0;
extern const hkQuadReal DAT_010ec7f0;
extern const hkQuadReal DAT_01017d10;  // absMask
extern const float DAT_01017d00;       // default equals4 epsilon

static __forceinline hkQuadReal hkLoadSs(const hkReal& x)
{
    return _mm_load_ss(&x);
}
inline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x) {}
inline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}
inline hkSimdReal::hkSimdReal() {}
inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline const LocalM128& hkSimdReal::getQuad() const
{
    return m_vValue;
}
typedef const hkSimdReal& hkSimdRealParameter;

class CompareBits
{
  public:
    enum Mask
    {
        ALL = 15
    };
    hkQuadReal bits;
    __forceinline int allAreSet(Mask m) const
    {
        return (_mm_movemask_ps(bits) & m) == m;
    }
};
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
__forceinline hkVector4::hkVector4(const hkVector4& v)
{
    memcpy(this, &v, sizeof(*this));
}
__forceinline void hkVector4::operator=(const hkQuadReal& q)
{
    m_vComponents = q;
}

__forceinline const hkQuadReal& hkVector4::getQuad() const
{
    return m_vComponents;
}

__forceinline hkSimdReal hkVector4::getSimdAt(int i) const
{
    return _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
}

__forceinline hkQuadReal& hkVector4::getQuad()
{
    return m_vComponents;
}


__forceinline void hkVector4::SetAllComponents(hkReal a)
{
    m_vComponents = _mm_set_ps1(a);
}

__forceinline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::sub4(const hkVector4& v)
{
    m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::mul4(hkSimdRealParameter s)
{
    m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
}

__forceinline void hkVector4::subMul4(hkSimdRealParameter r, const hkVector4& v)
{
    m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
}

__forceinline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents);
}

__forceinline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
}

__forceinline void hkVector4::addMul4(const hkVector4& x, const hkVector4& y)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}

__forceinline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    hkQuadReal lhs = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    hkQuadReal rhs = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(lhs, rhs);
}

__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter _t)
{
    hkQuadReal t = _t.broadcast();
    hkQuadReal s = _mm_sub_ps(DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}

__forceinline void hkVector4::setAbs4(const hkVector4& v)
{
    m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}

__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return dot3(*this);
}

__forceinline void hkVector4::broadcast0()
{
    m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
}

__forceinline void hkVector4::setBroadcast3(const hkVector4& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}

__forceinline CompareBits hkVector4::compareLessThanEqual4(const hkVector4& v) const
{
    CompareBits c;
    c.bits = _mm_cmple_ps(m_vComponents, v.m_vComponents);
    return c;
}

__forceinline int hkVector4::equals4(const hkVector4& kOther, hkReal fTol) const
{
    hkVector4 kDiff;
    kDiff.setSub4(*this, kOther);
    kDiff.setAbs4(kDiff);
    hkVector4 kTol;
    kTol.SetAllComponents(fTol);
    return kDiff.compareLessThanEqual4(kTol).allAreSet(CompareBits::ALL);
}

__forceinline hkQuaternion::hkQuaternion() {}
__forceinline hkQuaternion::hkQuaternion(const hkQuaternion& q)
{
    *reinterpret_cast<hkVector4*>(this) = *reinterpret_cast<const hkVector4*>(&q);
}
__forceinline const hkVector4& hkQuaternion::getImag() const
{
    return *reinterpret_cast<const hkVector4*>(this);
}
__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    *reinterpret_cast<hkVector4*>(this) = q.getImag();
}

extern const hkQuadReal DAT_01017d20;
// src: GUESS 0x00d6bec0 (confidence: low)
inline void hkQuaternion::UpdateFields_00d6bec0(const hkQuaternion& target, hkVector4& result) const
{
    result.setCross(getImag(), target.getImag());
    result.subMul4(target.getImag().getSimdAt(3), getImag());
    result.addMul4(getImag().getSimdAt(3), target.getImag());
    result.add4(result);
    hkQuadReal d = _mm_mul_ps(target.getImag().getQuad(), getImag().getQuad());
    d = _mm_add_ps(_mm_shuffle_ps(d, d, 78), d);
    d = _mm_add_ps(_mm_shuffle_ps(d, d, 177), d);
    if (_mm_movemask_ps(d) & 1)
        result.getQuad() = _mm_xor_ps(result.getQuad(), DAT_01017d20);
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 minusHalf;
    minusHalf.getQuad() = DAT_010c71e0;
    hkVector4 qreal;
    qreal.setBroadcast3(quat.getImag());
    hkVector4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    hkVector4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast0();
    ret.addMul4(imagDotDir, quat.getImag());
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

__forceinline hkQsTransform::hkQsTransform() {}

__forceinline const hkVector4& hkQsTransform::getTranslation() const
{
    return m_vTranslation;
}

__forceinline const hkQuaternion& hkQsTransform::getRotation() const
{
    return m_rotation;
}

__forceinline void hkQsTransform::set(const hkVector4& t, const hkQuaternion& r, const hkVector4& s)
{
    m_vTranslation = t;
    m_rotation = r;
    m_vScale = s;
}

__forceinline void hkQsTransform::SetProduct(const hkQsTransform& kLeft, const hkQsTransform& kRight)
{
    hkVector4 kMovedTrans;
    kMovedTrans.SetRotatedDirection(kLeft.m_rotation, kRight.m_vTranslation);
    m_vTranslation.setAdd4(kLeft.m_vTranslation, kMovedTrans);
    m_rotation.setMul(kLeft.m_rotation, kRight.m_rotation);
    m_vScale.setMul4(kLeft.m_vScale, kRight.m_vScale);
}

// Preserve this unit's inline rigid-body accessors using the shared motion layout.
__forceinline hkpMotion* hkpRigidBody::getRigidMotion()
{
    return &m_pMotionState;
}
__forceinline hkpMotion* hkpRigidBody::getRigidMotion() const
{
    return const_cast<hkpMaxSizeMotion*>(&m_pMotionState);
}
__forceinline const hkVector4& hkpRigidBody::getCenterOfMassInWorld() const
{
    return getRigidMotion()->m_kMotionState.m_kSweptTransform.m_vCenterOfMass1;
}
__forceinline const hkVector4& hkpRigidBody::getCenterOfMassLocal()
{
    return getRigidMotion()->m_kMotionState.m_kSweptTransform.m_vCenterOfMassLocal;
}
__forceinline const hkVector4& hkpRigidBody::getCenterOfMassLocal() const
{
    return getRigidMotion()->m_kMotionState.m_kSweptTransform.m_vCenterOfMassLocal;
}
__forceinline const hkVector4& hkpRigidBody::getPosition() const
{
    return reinterpret_cast<const hkVector4&>(getRigidMotion()->m_kMotionState.m_kMotionTransform.m_vTranslation);
}
__forceinline const hkQuaternion& hkpRigidBody::getRotation() const
{
    return getRigidMotion()->m_kMotionState.m_kSweptTransform.m_qRotation1;
}
__forceinline const hkVector4& hkpRigidBody::getLinearVelocity() const
{
    return getRigidMotion()->m_kTranslationalVelocity;
}
__forceinline const hkVector4& hkpRigidBody::getAngularVelocity() const
{
    return getRigidMotion()->m_kAngularVelocity;
}

__forceinline void* hkStackMemory::allocateStackRoundSizeTo128(int numBytes, const char* what)
{
    void* current = m_next;
    m_next = (char*)current + ((numBytes + 127) & ~127);
    return current;
}
__forceinline void hkStackMemory::deallocateStack(void* p)
{
    m_next = p;
}
__forceinline hkMemoryRouter& hkRouterInstance()
{
    return *static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
}

template <typename T> class HkDynamicArray
{
  public:
    T* m_data;
    __forceinline void init(int n)
    {
        hkMemoryRouter& mem = hkRouterInstance();
        m_data = static_cast<T*>(mem.stack().allocateStackRoundSizeTo128(n * (int)sizeof(T), ""));
    }
    __forceinline void destroy()
    {
        hkRouterInstance().stack().deallocateStack(static_cast<void*>(m_data));
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
};

struct BoneAndCenterOfMassPose
{
    hkQsTransform m_comPose;
    hkQsTransform m_bonePose;
};
struct ControlData
{
    hkReal m_fHierarchyGain;
    hkReal m_fVelocityDamping;
    hkReal m_fAccelerationGain;
    hkReal m_fVelocityGain;
    hkReal m_positionGain;
    hkReal m_fPositionMaxLinearVelocity;
    hkReal m_fPositionMaxAngularVelocity;
    hkReal m_snapGain;
    hkReal m_fSnapMaxLinearVelocity;
    hkReal m_fSnapMaxAngularVelocity;
    hkReal m_fSnapMaxLinearDistance;
    hkReal m_fSnapMaxAngularDistance;
};
struct HavokVectorQuaternionRecord
{
    hkVector4 m_kFirstVector;
    hkQuaternion m_kOrientation;
    hkVector4 m_kSecondVector;
    hkVector4 m_kThirdVector;
};
struct TransformReferenceData
{
    hkQsTransform m_kTransform;
    const hkQsTransform* m_pReferencedTransform;
    HavokVectorQuaternionRecord* m_pTransformContext;
};
struct IntegerTriple
{
    int m_iRigidBodyCount;
    hkpRigidBody* const* m_ppRigidBodies;
    const short* m_kParentIndices;
    int* m_piBodyPartIndices;
    const hkReal* m_pfRigidBodyWeights;
};
struct Output
{
    hkReal m_fOutputValue;
};

// src: GUESS 0x00d6b510 (confidence: low)
static __declspec(noinline) void hkQuaternion_ProcessEntries_00d6b510(const hkQsTransform* poseLocalSpace, const IntegerTriple& body,
                                              const ControlData* controlPalette, const hkQsTransform& worldFromRoot,
                                              BoneAndCenterOfMassPose* cache)
{
    for (int i = 0; i < body.m_iRigidBodyCount; i++)
    {
        hkQsTransform& worldFromBone = cache[i].m_bonePose;
        const int parentIndex = body.m_kParentIndices[i];
        const hkQsTransform& worldFromParent = parentIndex >= 0 ? cache[parentIndex].m_bonePose : worldFromRoot;
        worldFromBone.SetProduct(worldFromParent, poseLocalSpace[i]);
        hkQuaternion rotation = worldFromBone.getRotation();
        hkVector4 position = worldFromBone.getTranslation();
        const int controlIndex = body.m_piBodyPartIndices ? body.m_piBodyPartIndices[i] : 0;
        if (controlIndex == -1)
            continue;
        hkReal hierarchyGain = controlPalette[controlIndex].m_fHierarchyGain;
        if (body.m_pfRigidBodyWeights)
            hierarchyGain *= body.m_pfRigidBodyWeights[i];
        if (hierarchyGain > 0.0f && parentIndex >= 0)
        {
            hkpRigidBody* parentBody = body.m_ppRigidBodies[parentIndex];
            hkQsTransform worldFromParentBody;
            worldFromParentBody.m_vTranslation = parentBody->getPosition();
            worldFromParentBody.m_rotation = parentBody->getRotation();
            hkQsTransform blended;
            blended.SetProduct(worldFromParentBody, poseLocalSpace[i]);
            rotation.D3D_ComputeClearColor(rotation, blended.getRotation(), hierarchyGain);
            position.setInterpolate4(position, blended.getTranslation(), hierarchyGain);
        }
        hkpRigidBody* rigidBody = body.m_ppRigidBodies[i];
        hkVector4 comOffset;
        comOffset.SetRotatedDirection(rotation, rigidBody->getCenterOfMassLocal());
        position.add4(comOffset);
        hkVector4 identity;
        identity.getQuad() = DAT_01267e30;
        cache[i].m_comPose.set(position, rotation, identity);
    }
}

// src: GUESS 0x00d6b330 (confidence: high)
static __declspec(noinline) void Hkprigidbodycentreofmassviewer_ClampVectorLength(hkReal maxLength, hkVector4& v)
{
    const hkReal lengthSquared = v.lengthSquared3();
    const hkReal maxSquared = maxLength * maxLength;
    if (lengthSquared > maxSquared)
    {
        const hkReal factor = (1.0f / localSqrt(lengthSquared)) * maxLength;
        v.mul4(hkSimdReal(factor));
    }
}

// src: GUESS 0x00d6b3c0 (confidence: low)
static __declspec(noinline) hkReal Object_ProcessAndReturnValue_00d6b3c0(hkReal maxVelocity, hkReal maxDistance, hkVector4& v)
{
    const hkReal lengthSquared = v.lengthSquared3();
    const hkReal maxSquared = maxVelocity * maxVelocity;
    const hkReal stress = lengthSquared / maxSquared;
    if (lengthSquared > maxSquared)
    {
        const hkReal distSquared = maxDistance * maxDistance;
        if (lengthSquared < distSquared)
        {
            const hkReal factor = localSqrt(maxSquared / lengthSquared);
            v.mul4(hkSimdReal(factor));
        }
        else
        {
            const hkReal factor = maxVelocity * maxDistance / lengthSquared;
            v.mul4(hkSimdReal(factor));
        }
    }
    return stress;
}

// @fnv 0x00d6b8e0
// src: COMMUNITY 0x00d6b8e0
__declspec(noinline) void __cdecl hkaKeyFrameHierarchyUtility_applyKeyFrame(hkReal m_fTimeStep, const TransformReferenceData& pose, const IntegerTriple& body,
                                               const ControlData* controlPalette, Output* output)
{
    HkDynamicArray<BoneAndCenterOfMassPose> matrixCache;
    matrixCache.init(body.m_iRigidBodyCount);
    hkQuaternion_ProcessEntries_00d6b510(pose.m_pReferencedTransform, body, controlPalette, pose.m_kTransform, &matrixCache[0]);

    const hkReal invDeltaTime = 1.0f / m_fTimeStep;
    const hkSimdReal invDeltaTimeS = invDeltaTime;

    for (int i = 0; i < body.m_iRigidBodyCount; i++)
    {
        const int controlIndex = body.m_piBodyPartIndices ? body.m_piBodyPartIndices[i] : 0;
        if (controlIndex == -1)
            continue;
        const ControlData& controlData = controlPalette[controlIndex];
        hkpRigidBody* rigidBody = body.m_ppRigidBodies[i];

        hkReal accelerationGain = controlData.m_fAccelerationGain;
        hkReal velocityGain = controlData.m_fVelocityGain;
        hkReal positionGain = controlData.m_positionGain;
        hkReal snapGain = controlData.m_snapGain;
        if (body.m_pfRigidBodyWeights)
        {
            const hkReal boneWeight = body.m_pfRigidBodyWeights[i];
            accelerationGain *= boneWeight;
            velocityGain *= boneWeight;
            positionGain *= boneWeight;
            snapGain *= boneWeight;
        }
        const hkSimdReal velocityDamping = 1.0f - controlData.m_fVelocityDamping;

        const BoneAndCenterOfMassPose& cache = matrixCache[i];
        HavokVectorQuaternionRecord& workElem = pose.m_pTransformContext[i];

        // Linear velocity
        hkVector4 linearDiff, linearRate, linearAccel;
        {
            const hkVector4& desiredPosition = cache.m_comPose.getTranslation();
            linearDiff.setSub4(desiredPosition, rigidBody->getCenterOfMassInWorld());
            linearDiff.mul4(invDeltaTimeS);
            linearRate.setSub4(desiredPosition, workElem.m_kFirstVector);
            workElem.m_kFirstVector = desiredPosition;
            linearRate.mul4(invDeltaTimeS);
            linearAccel.setSub4(linearRate, workElem.m_kSecondVector);
            workElem.m_kSecondVector = linearRate;
        }
        hkVector4 linearCurrent = rigidBody->getLinearVelocity();
        hkVector4 linearNew;
        linearNew.setMul4(velocityDamping, linearCurrent);
        linearNew.addMul4(accelerationGain, linearAccel);
        linearRate.sub4(linearNew);
        {
            hkVector4 linearVelCorrection;
            linearVelCorrection.setMul4(hkSimdReal(velocityGain), linearRate);
            linearNew.add4(linearVelCorrection);
        }
        linearDiff.sub4(linearNew);
        {
            hkVector4 linearPosCorrection;
            linearPosCorrection.setMul4(hkSimdReal(positionGain), linearDiff);
            Hkprigidbodycentreofmassviewer_ClampVectorLength(controlData.m_fPositionMaxLinearVelocity, linearPosCorrection);
            linearNew.add4(linearPosCorrection);
        }
        if (snapGain != 0.0f)
        {
            hkVector4 snapPosition;
            snapPosition.SetRotatedDirection(cache.m_bonePose.getRotation(), rigidBody->getCenterOfMassLocal());
            snapPosition.add4(cache.m_bonePose.getTranslation());
            hkVector4 snapVelocity;
            snapVelocity.setSub4(snapPosition, rigidBody->getCenterOfMassInWorld());
            snapVelocity.mul4(invDeltaTimeS);
            snapVelocity.sub4(linearNew);
            snapVelocity.mul4(hkSimdReal(snapGain));
            const hkReal maxDistance = controlData.m_fSnapMaxLinearDistance * invDeltaTime * snapGain;
            const hkReal stress = Object_ProcessAndReturnValue_00d6b3c0(controlData.m_fSnapMaxLinearVelocity, maxDistance, snapVelocity);
            if (output)
                output[i].m_fOutputValue = stress;
            linearNew.add4(snapVelocity);
        }
        if (!rigidBody->getLinearVelocity().equals4(linearNew, 0.001f))
            rigidBody->OnTrigger(linearNew);

        // Angular velocity
        hkVector4 angularDiff, angularRate, angularAccel;
        {
            const hkQuaternion& desiredRotation = cache.m_comPose.getRotation();
            rigidBody->getRotation().UpdateFields_00d6bec0(desiredRotation, angularDiff);
            angularDiff.mul4(invDeltaTimeS);
            workElem.m_kOrientation.UpdateFields_00d6bec0(desiredRotation, angularRate);
            workElem.m_kOrientation = desiredRotation;
            angularRate.mul4(invDeltaTimeS);
            angularAccel.setSub4(angularRate, workElem.m_kThirdVector);
            workElem.m_kThirdVector = angularRate;
        }
        hkVector4 angularCurrent = rigidBody->getAngularVelocity();
        hkVector4 angularNew;
        angularNew.setMul4(velocityDamping, angularCurrent);
        angularNew.addMul4(accelerationGain, angularAccel);
        angularRate.sub4(angularNew);
        {
            hkVector4 angularVelCorrection;
            angularVelCorrection.setMul4(hkSimdReal(velocityGain), angularRate);
            angularNew.add4(angularVelCorrection);
        }
        angularDiff.sub4(angularNew);
        {
            hkVector4 angularPosCorrection;
            angularPosCorrection.setMul4(hkSimdReal(positionGain), angularDiff);
            Hkprigidbodycentreofmassviewer_ClampVectorLength(controlData.m_fPositionMaxAngularVelocity, angularPosCorrection);
            angularNew.add4(angularPosCorrection);
        }
        if (snapGain != 0.0f)
        {
            hkVector4 snapVelocity;
            rigidBody->getRotation().UpdateFields_00d6bec0(cache.m_bonePose.getRotation(), snapVelocity);
            snapVelocity.mul4(invDeltaTimeS);
            snapVelocity.sub4(angularNew);
            snapVelocity.mul4(hkSimdReal(snapGain));
            const hkReal maxDistance = controlData.m_fSnapMaxAngularDistance * invDeltaTime * snapGain;
            const hkReal stress = Object_ProcessAndReturnValue_00d6b3c0(controlData.m_fSnapMaxAngularVelocity, maxDistance, snapVelocity);
            if (output)
                output[i].m_fOutputValue += stress;
            angularNew.add4(snapVelocity);
        }
        if (!rigidBody->getAngularVelocity().equals4(angularNew, 0.001f))
            rigidBody->hkpRigidBody_setAngularVelocity(angularNew);
    }
    matrixCache.destroy();
}

void(__cdecl* volatile retainKeyFrameEntry)(hkReal, const TransformReferenceData&, const IntegerTriple&, const ControlData*,
                                            Output*) = &hkaKeyFrameHierarchyUtility_applyKeyFrame;

class ScalarR2
{
    LocalM128 value;

  public:
    ScalarR2()
    {}
    ScalarR2(const LocalM128& v) : value(v)
    {}
    ScalarR2(float x)
    {
        value = _mm_load_ss(&x);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const LocalM128& getQuad() const
    {
        return value;
    }
};
struct RotationR2;
struct MatrixR2;
// Retained: the shared inverse-rotation signature changes FUN_00d6c630's machine code.
class FUN_004b4ab0_Class
{
    LocalM128 value;

  public:
    __forceinline FUN_004b4ab0_Class()
    {}
    __forceinline FUN_004b4ab0_Class(const LocalM128& x) : value(x)
    {}
    __forceinline FUN_004b4ab0_Class(const FUN_004b4ab0_Class& x) : value(x.value)
    {}
    __forceinline void operator=(const FUN_004b4ab0_Class& x)
    {
        value = x.value;
    }
    __forceinline void operator=(const LocalM128& x)
    {
        value = x;
    }
    operator LocalM128() const
    {
        return value;
    }
    __forceinline LocalM128& getQuad()
    {
        return value;
    }
    __forceinline const LocalM128& getQuad() const
    {
        return value;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&value)[i];
    }
    __forceinline void setSub4(const FUN_004b4ab0_Class& a, const FUN_004b4ab0_Class& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setAdd4(const FUN_004b4ab0_Class& a, const FUN_004b4ab0_Class& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void setMul4(const FUN_004b4ab0_Class& a, const FUN_004b4ab0_Class& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void mul4(const FUN_004b4ab0_Class& a)
    {
        value = _mm_mul_ps(value, a.value);
    }
    __forceinline void add4(const FUN_004b4ab0_Class& a)
    {
        value = _mm_add_ps(value, a.value);
    }
    __forceinline void setCross(const FUN_004b4ab0_Class& a, const FUN_004b4ab0_Class& b)
    {
        LocalM128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        LocalM128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline ScalarR2 dot3(const FUN_004b4ab0_Class& a) const
    {
        LocalM128 p = _mm_mul_ps(value, a.value);
        LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), sum);
    }
    __forceinline ScalarR2 lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline void addMul4(const ScalarR2& s, const FUN_004b4ab0_Class& a)
    {
        value = _mm_add_ps(value, _mm_mul_ps(s.broadcast(), a.value));
    }
    __forceinline void subMul4(const ScalarR2& s, const FUN_004b4ab0_Class& a)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(s.broadcast(), a.value));
    }
    __forceinline void _setRotatedDir(const RotationR2& r, const FUN_004b4ab0_Class& v);
    __forceinline void _setMul3(const MatrixR2& r, const FUN_004b4ab0_Class& v);
    void hkVector4_setRotatedInverseDir(int r, int v);
    __forceinline void setRotatedInverseDir(const RotationR2& r, const FUN_004b4ab0_Class& v)
    {
        hkVector4_setRotatedInverseDir((int)&r, (int)&v);
    }
};
typedef FUN_004b4ab0_Class VectorR2;
struct MatrixR2
{
    VectorR2 col0, col1, col2;
    __forceinline VectorR2& getColumn(int i)
    {
        return (&col0)[i];
    }
    __forceinline const VectorR2& getColumn(int i) const
    {
        return (&col0)[i];
    }
};
struct RotationR2 : MatrixR2
{
};
__forceinline void VectorR2::_setRotatedDir(const RotationR2& r, const VectorR2& v)
{
    _setMul3(r, v);
}
__forceinline void VectorR2::_setMul3(const MatrixR2& r, const VectorR2& v)
{
    LocalM128 sx = _mm_shuffle_ps(v.value, v.value, 0);
    LocalM128 px = _mm_mul_ps(r.getColumn(0).value, sx);
    LocalM128 sy = _mm_shuffle_ps(v.value, v.value, 0x55);
    LocalM128 py = _mm_mul_ps(r.getColumn(1).value, sy);
    LocalM128 sz = _mm_shuffle_ps(v.value, v.value, 0xaa);
    LocalM128 pz = _mm_mul_ps(r.getColumn(2).value, sz);
    value = _mm_add_ps(_mm_add_ps(px, py), pz);
}
// src: COMMUNITY 0x004b4ab0
inline void VectorR2::hkVector4_setRotatedInverseDir(int r, int v)
{
    const RotationR2& m = *reinterpret_cast<const RotationR2*>(r);
    LocalM128 low = _mm_unpacklo_ps(m.getColumn(0), m.getColumn(1));
    LocalM128 high = _mm_unpackhi_ps(m.getColumn(0), m.getColumn(1));
    LocalM128 cx = _mm_movelh_ps(low, m.getColumn(2));
    LocalM128 cy = _mm_shuffle_ps(_mm_movehl_ps(cx, low), m.getColumn(2), 0xd4);
    LocalM128 cz = _mm_shuffle_ps(high, m.getColumn(2), 0xe4);
    const VectorR2& q = *reinterpret_cast<const VectorR2*>(v);
    LocalM128 x = _mm_mul_ps(cx, _mm_shuffle_ps(q.value, q.value, 0));
    LocalM128 y = _mm_mul_ps(cy, _mm_shuffle_ps(q.value, q.value, 0x55));
    LocalM128 z = _mm_mul_ps(cz, _mm_shuffle_ps(q.value, q.value, 0xaa));
    value = _mm_add_ps(_mm_add_ps(x, y), z);
}
template <class T> class PaddedR2
{
    T data;

  public:
    __forceinline operator T() const
    {
        return data;
    }
    __forceinline T operator->() const
    {
        return data;
    }
    __forceinline T val() const
    {
        return data;
    }
    __forceinline void operator=(T x)
    {
        data = x;
    }
};
struct BodyR2
{
    int unk00, unk04, unk08, unk0c;
    VectorR2 m_vLinearVelocity, m_vAngularVelocity, m_vInverseInertiaAndMass, m_vCenterOfMass;
    RotationR2 m_kCoreFromWorldMatrix;
    __forceinline const VectorR2& getCenterOfMassInWorld() const
    {
        return m_vCenterOfMass;
    }
    __forceinline const RotationR2& getCoreFromWorldMatrix() const
    {
        return m_kCoreFromWorldMatrix;
    }
};
struct OwnerR2;
struct NoticeR2
{
    unsigned m_uiConstraintCount;
    OwnerR2* m_ppConstraints[128];
};
struct QueryR2
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    PaddedR2<float> m_fThirdQueryValue, m_fFourthQueryValue;
    int unk28, unk2c;
    PaddedR2<const BodyR2*> m_pBodyA, m_pBodyB;
    int unk38, unk3c, unk40, unk44, unk48, unk4c;
    ScalarR2 m_fMaxConstraintViolationSquared;
    PaddedR2<OwnerR2*> m_pConstraintChainInstance;
    int unk64;
    PaddedR2<NoticeR2*> m_pOpaqueData;
};
struct SchemaR2;
struct OutputR2
{
    PaddedR2<SchemaR2*> m_pQueryResultSchema;
};
extern long(__stdcall* DAT_00fdf1ec)(volatile long*, long);
extern VectorR2 DAT_01268370[3];
extern double DAT_010c9300, DAT_0104e138;
struct NativeRow
{
    VectorR2 linear, angularA, angularB;
    __forceinline float diagonal(const BodyR2& a, const BodyR2& b, double offset) const
    {
        LocalM128 anballSocketPivotA = angularA;
        LocalM128 anballSocketPivotB = angularB;
        VectorR2 sqA, sqB;
        sqA.getQuad() = _mm_mul_ps(anballSocketPivotA, anballSocketPivotA);
        sqB.getQuad() = _mm_mul_ps(anballSocketPivotB, anballSocketPivotB);
        sqA.mul4(a.m_vInverseInertiaAndMass);
        sqB.mul4(b.m_vInverseInertiaAndMass);
        sqB.add4(sqA);
        VectorR2 m;
        m.setAdd4(a.m_vInverseInertiaAndMass, b.m_vInverseInertiaAndMass);
        LocalM128 weighted = sqB;
        LocalM128 high = _mm_unpackhi_ps(weighted, m);
        LocalM128 all = _mm_shuffle_ps(weighted, high, 0xc4);
        LocalM128 pairs = _mm_add_ps(_mm_shuffle_ps(all, all, 0x4e), all);
        LocalM128 sum = _mm_add_ps(_mm_shuffle_ps(pairs, pairs, 0xb1), pairs);
        float x;
        _mm_store_ss(&x, sum);
        return (float)(x + offset);
    }
};
static __forceinline void stabilized(const BodyR2* a, const BodyR2* b, const VectorR2& pa, const VectorR2& pb,
                                     float rhs, float factor, VectorR2& error)
{
    ScalarR2 scale = (1.0f / rhs) * factor;
    error.setSub4(pb, pa);
    VectorR2 armA;
    armA.setSub4(pa, a->getCenterOfMassInWorld());
    VectorR2 armB;
    armB.setSub4(pb, b->getCenterOfMassInWorld());
    const RotationR2& ma = a->getCoreFromWorldMatrix();
    VectorR2 velocityA;
    velocityA.setRotatedInverseDir(ma, a->m_vAngularVelocity);
    const RotationR2& mb = b->getCoreFromWorldMatrix();
    VectorR2 velocityB;
    velocityB.setRotatedInverseDir(mb, b->m_vAngularVelocity);
    VectorR2 spinA;
    spinA.setCross(armA, velocityA);
    VectorR2 spinB;
    spinB.setCross(armB, velocityB);
    error.addMul4(scale, spinB);
    error.subMul4(scale, spinA);
}
static __forceinline void buildRow(const BodyR2* a, const BodyR2* b, const VectorR2& pa, const VectorR2& pb,
                                   const VectorR2& axis, float scale, float strength, NativeRow& row, double offset)
{
    row.linear = axis;
    VectorR2 armA;
    armA.setSub4(pa, a->getCenterOfMassInWorld());
    VectorR2 armB;
    armB.setSub4(pb, b->getCenterOfMassInWorld());
    VectorR2 crossA;
    crossA.setCross(armA, axis);
    VectorR2 crossB;
    crossB.setCross(axis, armB);
    row.angularA._setRotatedDir(a->getCoreFromWorldMatrix(), crossA);
    row.angularB._setRotatedDir(b->getCoreFromWorldMatrix(), crossB);
    float diag = row.diagonal(*a, *b, offset);
    row.angularB(3) = diag;
    row.angularA(3) = strength / diag;
    VectorR2 diff;
    diff.setSub4(pb, pa);
    float p = diff.dot3(axis);
    row.linear(3) = p * scale;
}
static __declspec(noinline) void Runtime_ProcessEntries_00d6c630(const VectorR2& pa, const VectorR2& pb, const QueryR2& ctx,
                                              OutputR2& cursor, float mode, float dt);
const QueryR2* volatile ballSocketContext;
VectorR2* volatile ballSocketPivotA;
VectorR2* volatile ballSocketPivotB;
OutputR2* volatile ballSocketOutput;
volatile float ballSocketImpulse, ballSocketStep;
void BuildBallSocketRows()
{
    Runtime_ProcessEntries_00d6c630(*ballSocketPivotA, *ballSocketPivotB, *ballSocketContext, *ballSocketOutput, ballSocketImpulse,
                 ballSocketStep);
}
// @fnv 0x00d6c630
// src: GUESS 0x00d6c630 (confidence: low)
static __declspec(noinline) void Runtime_ProcessEntries_00d6c630(const VectorR2& pa, const VectorR2& pb, const QueryR2& ctx,
                                              OutputR2& cursor, float mode, float dt)
{
    const BodyR2* a = ctx.m_pBodyA;
    const BodyR2* b = ctx.m_pBodyB;
    NativeRow* out = (NativeRow*)cursor.m_pQueryResultSchema.val();
    VectorR2 error;
    stabilized(a, b, pa, pb, ctx.m_fThirdQueryValue, dt, error);
    if (ctx.m_pOpaqueData &&
        (_mm_movemask_ps(_mm_sub_ss(ctx.m_fMaxConstraintViolationSquared.getQuad(), error.lengthSquared3().getQuad())) &
         1))
    {
        unsigned idx = DAT_00fdf1ec((volatile long*)&ctx.m_pOpaqueData->m_uiConstraintCount, 1);
        if (idx < 128)
            ctx.m_pOpaqueData->m_ppConstraints[idx] = ctx.m_pConstraintChainInstance;
    }
    double target = mode, offset = DAT_010c9300, zero = DAT_0104e138;
    const VectorR2* axis = DAT_01268370;
    for (int i = 0; i < 3; ++i)
    {
        NativeRow* row = out;
        buildRow(a, b, pa, pb, *axis, ctx.m_fThirdQueryValue, ctx.m_fFourthQueryValue, *row, offset);
        row->linear(3) = error(i) * ctx.m_fThirdQueryValue;
        if (zero == target)
        {
            row->linear(0) = (float)(row->linear(0) + offset);
            *(unsigned char*)&row->linear(0) = 5;
        }
        else
        {
            row->linear(0) = (float)(row->linear(0) + offset);
            *(unsigned char*)&row->linear(0) = 6;
            row->angularB(3) = (float)target;
        }
        ++out;
        ++axis;
    }
    cursor.m_pQueryResultSchema = (SchemaR2*)out;
}

extern "C"
{
    void _ReadWriteBarrier();
}

struct BoolD72
{
    unsigned char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct Matrix3D72
{
    LocalM128 x, y, z;
    void invert_00cd4f10(float tolerance);
    void FUN_00cd4b60();
    void FUN_00cd5140(const Matrix3D72& other);
    void FUN_00cd4d40(const LocalM128& factor, const Matrix3D72& other);
    bool& CompareMatrixColumnsWithinTolerance(bool& result, const Matrix3D72& other, float tolerance);
};
struct QuaternionD72
{
    LocalM128 value;
    __declspec(noalias) void FUN_00cb26e0(const Matrix3D72& rotation);
    __declspec(noalias) void normalize_005611c0();
};
__forceinline hkTransform::hkTransform() {}
// 0x00cb20b0 imports column-major floats into hkTransform; the shared header lacks this method.
// This fieldless extension supplies only that declaration; hkTransform owns the complete layout.
class ColumnMajorTransformImporter : public hkTransform
{
public:
    void ImportColumnMajor(const float* source);
};
struct Matrix4D72
{
    union
    {
        LocalM128 x;
        struct
        {
            float xx, xy, xz, xw;
        };
    };
    union
    {
        LocalM128 y;
        struct
        {
            float yx, yy, yz, yw;
        };
    };
    union
    {
        LocalM128 z;
        struct
        {
            float zx, zy, zz, zw;
        };
    };
    union
    {
        LocalM128 w;
        struct
        {
            float wx, wy, wz, ww;
        };
    };
    __declspec(noalias) void CopyFromFloats(const float* source);
    __declspec(noalias) void hkMatrix4_resetFourthRow();
    __declspec(noalias) void hkMatrix4_setMul(const Matrix4D72& left, const Matrix4D72& right);
};
struct DecompositionD72
{
    LocalM128 translation;
    QuaternionD72 rotation;
    union
    {
        LocalM128 scale;
        struct
        {
            float scaleX, scaleY, scaleZ, scaleW;
        };
    };
    unsigned char hasScale, hasSkew, flips;
    Matrix4D72 scaleSkew;
    Matrix4D72 skew;
    Matrix3D72 basis;
};
__forceinline void copyMatrix(Matrix3D72& d, const Matrix3D72& s)
{
    d.x = s.x;
    d.y = s.y;
    d.z = s.z;
}
extern const LocalM128 DAT_01017d10;
extern const Matrix4D72 DAT_0126a3e0;
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
extern const float DAT_01012054;
extern const float DAT_01012068;
extern const float DAT_01017d00;
extern const float DAT_0104da4c;

__forceinline LocalM128 dot3D72(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
__forceinline LocalM128 normalizedD72(LocalM128 v)
{
    LocalM128 lengthSquared = dot3D72(v, v);
    LocalM128 reciprocal = _mm_rsqrt_ss(lengthSquared);
    LocalM128 three = _mm_set_ss(DAT_01017718);
    LocalM128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(lengthSquared, reciprocal), reciprocal));
    LocalM128 scale = _mm_mul_ss(_mm_mul_ss(_mm_load_ss(&DAT_01016248), reciprocal), correction);
    scale = _mm_andnot_ps(_mm_cmpeq_ss(lengthSquared, _mm_load_ss(&DAT_01011d78)), scale);
    return _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), v);
}

__forceinline float scalarD72(LocalM128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
__forceinline void diagD72(Matrix4D72& m, float x, float y, float z)
{
    m.x = _mm_setzero_ps();
    m.y = _mm_setzero_ps();
    m.z = _mm_setzero_ps();
    m.w = _mm_setzero_ps();
    m.xx = 1.0f / x;
    m.yy = 1.0f / y;
    m.zz = 1.0f / z;
    m.ww = 1.0f;
}
struct OutputD72
{
    DecompositionD72* p;
    OutputD72(DecompositionD72* q) : p(q)
    {}
};
// @fnv 0x00d72e90
// src: XBOX_PDB 0x00d72e90
void __cdecl hkMathUtil_decompose4x4ColTransform(const float* source, OutputD72 output)
{
    ColumnMajorTransformImporter transform;
    transform.ImportColumnMajor(source);
    Matrix4D72 original;
    original.CopyFromFloats(source);
    original.hkMatrix4_resetFourthRow();
    DecompositionD72* __restrict result = output.p;
    result->translation = transform.m_vTranslation;
    {
        Matrix3D72 current;
        int iteration = 0;
        copyMatrix(current, reinterpret_cast<const Matrix3D72&>(transform.m_kColumn0));
        bool equal;
        Matrix3D72 previous;
        do
        {
            copyMatrix(previous, current);
            Matrix3D72 inverse;
            copyMatrix(inverse, current);
            inverse.invert_00cd4f10(DAT_0104da4c);
            inverse.FUN_00cd4b60();
            Matrix3D72 sum;
            copyMatrix(sum, previous);
            sum.FUN_00cd5140(inverse);
            LocalM128 half = _mm_load_ss(&DAT_01016248);
            current.FUN_00cd4d40(half, sum);
        } while (++iteration < 30 && !current.CompareMatrixColumnsWithinTolerance(equal, previous, DAT_0104da4c));
        copyMatrix(result->basis, current);
    }
    LocalM128 x = normalizedD72(result->basis.x);
    LocalM128 y = normalizedD72(result->basis.y);
    LocalM128 z = normalizedD72(result->basis.z);
    LocalM128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(z, z, 0xd2), _mm_shuffle_ps(y, y, 0xc9)),
                              _mm_mul_ps(_mm_shuffle_ps(z, z, 0xc9), _mm_shuffle_ps(y, y, 0xd2)));
    LocalM128 determinant = dot3D72(cross, x);
    if (scalarD72(determinant) < 0.0f)
    {
        LocalM128 minusOne = _mm_load_ss(&DAT_01012054);
        x = _mm_mul_ps(_mm_shuffle_ps(minusOne, minusOne, 0), x);
    }
    result->flips = scalarD72(determinant) < 0.0f;
    {
        Matrix3D72 rotation;
        rotation.x = x;
        rotation.y = y;
        rotation.z = z;
        QuaternionD72 quaternion;
        quaternion.FUN_00cb26e0(rotation);
        result->rotation.value = quaternion.value;
    }
    result->rotation.normalize_005611c0();
    Matrix4D72 inverseMatrix;
    {
        hkTransform rotationTransform;
        rotationTransform.m_rotation.set(reinterpret_cast<const hkQuaternion&>(result->rotation));
        rotationTransform.m_vTranslation = result->translation;
        hkTransform inverseTransform;
        inverseTransform.SetConjugate(rotationTransform);
        inverseMatrix.CopyFromFloats(reinterpret_cast<const float*>(&inverseTransform));
    }
    inverseMatrix.hkMatrix4_resetFourthRow();
    Matrix4D72* scaleSkew = &result->scaleSkew;
    scaleSkew->hkMatrix4_setMul(inverseMatrix, original);
    Matrix4D72* skew = &result->skew;
    result->scale = _mm_setr_ps(result->scaleSkew.xx, result->scaleSkew.yy, result->scaleSkew.zz, DAT_01011d78);
    LocalM128 one = _mm_load_ss(&DAT_01012068);
    LocalM128 delta = _mm_sub_ps(result->scale, _mm_shuffle_ps(one, one, 0));
    LocalM128 tolerance = _mm_load_ss(&DAT_01017d00);
    tolerance = _mm_shuffle_ps(tolerance, tolerance, 0);
    unsigned char* flagAddress = &result->hasScale;
    *flagAddress = (_mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(delta, DAT_01017d10), tolerance)) & 7) != 7;
    Matrix4D72 inverseScale;
    diagD72(inverseScale, result->scaleX, result->scaleY, result->scaleZ);
    skew->hkMatrix4_setMul(inverseScale, *scaleSkew);
    LocalM128 dz = _mm_and_ps(_mm_sub_ps(skew->z, DAT_0126a3e0.z), DAT_01017d10);
    LocalM128 dw = _mm_and_ps(_mm_sub_ps(skew->w, DAT_0126a3e0.w), DAT_01017d10);
    LocalM128 dx = _mm_and_ps(_mm_sub_ps(skew->x, DAT_0126a3e0.x), DAT_01017d10);
    LocalM128 dy = _mm_and_ps(_mm_sub_ps(skew->y, DAT_0126a3e0.y), DAT_01017d10);
    LocalM128 difference = _mm_max_ps(_mm_max_ps(dx, dy), _mm_max_ps(dz, dw));
    result->hasSkew = (_mm_movemask_ps(_mm_cmple_ps(difference, tolerance)) & 15) != 15;
}
