#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/staging/blk_00d60000_o2_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d60000_o2_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00d60000_o2_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/staging/blk_00d60000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00d60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkArray.h"
#include "../../include/hkSmallArray.h"
#include "../../include/FinishingFlag.h"
#include "../../include/hkBool.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkpPhysicsContext.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkOstream.h"
#include "../../include/hkError.h"
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
void __cdecl Runtime_ProcessState_00d6ae90(FUN_00c90e00_Obj* param_1, int param_2);
// 13-byte cdecl forwarder: loads the object pointer, fetches its vtable and
// calls the first virtual slot with a literal 0 argument.
struct VtblForwarder
{
    virtual int v0(int);
};
int __cdecl Runtime_ForwardCall_00d6aeb0(VtblForwarder* p);
extern int DAT_01269104;
void* __cdecl Object_GetGlobalObjectAddress_00d6aee0();
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
    hkBool IsValid();
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
void __cdecl ConstructHkDerived(void* pvObject, int iFinishing);
class FUN_00d60540 : public hkReferencedObject
{
  public:
    FUN_00d60540(FinishingFlag flag);
    virtual ~FUN_00d60540();
};
extern int DAT_010d14f8;
extern int DAT_0102e388;
struct D60590Object
{
    int* vtable;
    int unk04;
    hkReferencedObject* callback;

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
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl hkString_memCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();
class FUN_00d61b10
{
  public:
    hkInplaceArray<char, 128, hkContainerTempAllocator> m_kStringBuffer;

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
struct HeapBlockMetadata
{
    unsigned int flags;
    unsigned short size;
    unsigned short reserved;
    HeapBlockMetadata* UpdateState_00d62ef0(void* data, unsigned int enabled);
};
void* __cdecl AllocateRecordWithData(void* data);
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
Base2_d632c0* hkpWorldMemoryViewer_create(int a1);
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
class FUN_00d61b80
{
  public:
    hkInplaceArray<char, 128, hkContainerTempAllocator> m_kStringBuffer;

    FUN_00d61b80(const FUN_00d61b80& kOther) throw();
};
hkMemoryRouter* __cdecl _FNV_e03300_arena();
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
// The snapshot factory at 0x00d62f20 returns this four-byte interface at +8, after hkReferencedObject; it is not hkpCollisionAgent.
class SnapshotViewerInterface
{
  public:
    virtual void cleanup();
};
class FUN_00d62ef0 : public hkReferencedObject, public SnapshotViewerInterface
{
  public:
    FUN_00d62ef0(void* contactMgr, int flags) throw();

    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
};
SnapshotViewerInterface* __cdecl hkpWorldSnapshotViewer_createNative(void* contactMgr);
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
typedef ::__m128 LocalM128;
using ::_mm_shuffle_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
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

extern "C"
{
using ::_mm_load_ps;
using ::_mm_load_ss;
using ::_mm_add_ss;
using ::_mm_store_ss;
using ::_mm_store_ps;
}
#include <math.h>

inline float Fwd(float x)
{
    return x;
}

// @fnv 0x00d6b3c0
// src: GUESS 0x00d6b3c0 (confidence: low)
static __declspec(noinline) float Object_ProcessAndReturnValue_00d6b3c0(LocalM128* p, float a1, float a2)
{
    LocalM128 value = _mm_load_ps((const float*)p);
    float minSq = a1 * a1;
    LocalM128 sq = _mm_mul_ps(value, value);
    LocalM128 y2 = _mm_shuffle_ps(sq, sq, 0x55);
    LocalM128 z2 = _mm_shuffle_ps(sq, sq, 0xaa);
    LocalM128 s1 = _mm_add_ss(y2, sq);
    LocalM128 s2 = _mm_add_ss(z2, s1);
    float lenSq;
    _mm_store_ss(&lenSq, s2);
    float ratio = lenSq / minSq;
    if (minSq < lenSq)
    {
        float maxSq = a2 * a2;
        if (maxSq > lenSq)
        {
            float q = minSq / lenSq;
            float r = sqrtf(q);
            float scale = Fwd(r);
            LocalM128 s = _mm_load_ss(&scale);
            LocalM128 b = _mm_shuffle_ps(s, s, 0);
            LocalM128 res = _mm_mul_ps(b, value);
            _mm_store_ps((float*)p, res);
        }
        else
        {
            float scale = (a1 * a2) / lenSq;
            LocalM128 s = _mm_load_ss(&scale);
            LocalM128 b = _mm_shuffle_ps(s, s, 0);
            LocalM128 res = _mm_mul_ps(b, value);
            _mm_store_ps((float*)p, res);
        }
        return ratio;
    }
    return ratio;
}

volatile LocalM128* g_vec;
volatile float g_a1, g_a2, g_sink;
void zz_caller(void)
{
    g_sink = Object_ProcessAndReturnValue_00d6b3c0((LocalM128*)g_vec, g_a1, g_a2);
}
