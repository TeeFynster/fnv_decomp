
// src/staging/blk_00d60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkError.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkBool.h"
#include "../../include/hkOArchive.h"
#include "../../include/FinishingFlag.h"
#include "../../include/hkpPhysicsContext.h"
#include "../../include/hkpWorldViewerBase.h"
#include "../../include/hkProcess.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkArray.h"
#include "../../include/hkStringBuf.h"
#include "../../include/hkSmallArray.h"
#include "../../include/hkOstream.h"
#include "../../include/hkErrStream.h"

template <class T> inline T& GetHolderAllocator(hkMemoryRouter* holder)
{
    return *reinterpret_cast<T*>(holder->m_heap);
}

// FUN_00c85750 (the shared router getter) returns the stack/temp/heap layout in hkMemoryRouter.
void* __cdecl hkMemoryRouter_getInstance();
__forceinline hkMemoryAllocator& hkContainerTempAllocator::get(void*)
{
    return static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->temp();
}

template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int cap = getCapacity();
    if (cap < n)
    {
        int doubled = 2 * cap;
        hkArrayUtil::_reserve(alloc, this, n < doubled ? doubled : n, sizeof(T));
    }
}
template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T> __forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& t, hkTypeIsPod)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
    m_iElementCount++;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
}
template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}

void __cdecl hkpInactiveContactPointViewer_create(void);

struct Registry_00dd9380
{
    void* Register(char const*, void(__cdecl*)(void));
};

extern int DAT_01269cd0;
extern void* DAT_01269008;

// @fnv 0x00d68800
void RegisterContactPointsInactive()
{
    Registry_00dd9380* reg = (Registry_00dd9380*)DAT_01269cd0;
    DAT_01269008 = reg->Register("Contact Points (Inactive)", hkpInactiveContactPointViewer_create);
}

namespace fnv_00d688d0 {
void hkpActiveContactPointViewer_create();
extern int DAT_0126900c;
struct Registry_00dd9380_StandIn
{
    void* hkProcessFactory_registerProcess(const char*, void(__cdecl*)());
};
extern Registry_00dd9380_StandIn* DAT_01269cd0;
// @fnv 0x00d688d0
void* RegisterContactPointsActive()
{
    DAT_0126900c = (int)DAT_01269cd0->hkProcessFactory_registerProcess("Contact Points (Active)", hkpActiveContactPointViewer_create);
    return (void*)DAT_0126900c;
}
}  // namespace fnv_00d688d0

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

// @fnv 0x00d68770
FUN_00d68770_cls* FUN_00d68770_cls::Construct(int aParam)
{
    BaseConstruct(aParam, 0xff008000);
    m_pVtbl00 = &DAT_010d1fb0;
    m_pVtbl08 = &DAT_010d1f90;
    m_pVtbl20 = &DAT_010d1f80;
    m_pVtbl28 = &DAT_010d1f70;
    return this;
}

// @fnv 0x00d687b0
// src: HAVOK_LIB 0x00d687b0
void* __stdcall hkpInactiveContactPointViewer_getIslands(char* a1)
{
    return a1 + 0x34;
}

struct FnvCpu_FUN_00d687c0_CpuBlock;
void* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d687c0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d687c0_CpuBlock* Construct(unsigned int value);
};
// @fnv 0x00d687c0
// src: XBOX_PDB 0x00d687c0
void* __cdecl hkpInactiveContactPointViewer_create(unsigned int value)
{
    hkMemoryRouter* holder = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    FnvCpu_FUN_00d687c0_CpuBlock* block = static_cast<FnvCpu_FUN_00d687c0_CpuBlock*>(reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockAlloc(52));
    block->size = 52;
    block = block->Construct(value);
    if (block)
        return reinterpret_cast<char*>(block) + 8;
    return 0;
}

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

// @fnv 0x00d68840
void* FUN_00d68840_cls::Init(int aiValue)
{
    FUN_00de29b0(aiValue, 0xff0000ff);
    m_p00 = (void*)&DAT_010d203c;
    m_p08 = (void*)&DAT_010d201c;
    m_p20 = (void*)&DAT_010d200c;
    m_p28 = (void*)&DAT_010d1ffc;
    return this;
}

// hkpActiveContactPointViewer (Havok Physics) - virtual at vftable offset 0x0c
// of the primary base (complete-object base offset 0) and at slot 11 of the
// base that lives at complete-object offset +0x08.
//
// The routine ignores `this` entirely and converts its single 4-byte stack
// argument into a pointer to the sub-object that sits 0x28 bytes further up.
//
// Original bytes:
//   00d68880  8b 44 24 04   mov eax, dword ptr [esp+4]
//   00d68884  83 c0 28      add eax, 0x28
//   00d68887  c2 04 00      ret 4

// @fnv 0x00d68880
// src: HAVOK_LIB 0x00d68880
void* __stdcall hkpActiveContactPointViewer_getIslands(void* pObject)
{
    return (void*)((char*)pObject + 0x28);
}

namespace fnv_00d68890 {

struct FNV_Buffer
{
    int unk00;
    unsigned short m_w04;
    unsigned short m_w06;
    int unk08;

    void* Init(int a1);
};

hkMemoryRouter* hkMemoryRouter_getInstance();

// @fnv 0x00d68890
// src: XBOX_PDB 0x00d68890
void* __cdecl hkpActiveContactPointViewer_create(int aiArg)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* allocator = (hkMemoryAllocator*)holder->m_heap;
    FNV_Buffer* pBuffer = (FNV_Buffer*)allocator->blockAlloc(0x34);
    pBuffer->m_w04 = 0x34;
    void* r = pBuffer->Init(aiArg);
    return r != 0 ? (char*)r + 8 : 0;
}
}  // namespace fnv_00d68890

// FUN_00d688f0 : tiny global getter.
// Reads the 4-byte global at DAT_0126900c and returns it in eax.

extern int DAT_0126900c;

// @fnv 0x00d688f0
// src: GUESS 0x00d688f0 (confidence: low)
int __cdecl Runtime_GetDAT0126900c()
{
    return DAT_0126900c;
}

namespace fnv_00d68910 {

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

class D68910Object
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    ~D68910Object();
    D68910Object* DestroyAndFree(unsigned int uiFlags);
};

// @fnv 0x00d68910
D68910Object* D68910Object::DestroyAndFree(unsigned int uiFlags)
{
    this->~D68910Object();
    if (uiFlags & 1)
        GetHolderAllocator<hkMemoryAllocator>(&hkMemoryRouter_getInstance()).blockFree(this, m_usMemSizeAndFlags);
    return this;
}
}  // namespace fnv_00d68910

extern char DAT_0126905c;

// @fnv 0x00d6ade0
// src: GUESS 0x00d6ade0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d6ade0()
{
    return &DAT_0126905c;
}

struct S_00d6adf0_Obj
{
    virtual void vfn00(int arg);
};
// @fnv 0x00d6adf0
// src: GUESS 0x00d6adf0 (confidence: low)
void __cdecl Runtime_ForwardCall_00d6adf0(S_00d6adf0_Obj* obj)
{
    obj->vfn00(0);
}

extern int DAT_0126908c;

// @fnv 0x00d6ae00
// src: GUESS 0x00d6ae00 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00d6ae00()
{
    return &DAT_0126908c;
}

struct FUN_00c90e00_Obj
{
    void __thiscall FUN_00c90e00(int value);
};

// @fnv 0x00d6ae90
// src: GUESS 0x00d6ae90 (confidence: low)
void __cdecl Runtime_ProcessState_00d6ae90(FUN_00c90e00_Obj* pObj, int iValue)
{
    if (pObj != 0)
    {
        pObj->FUN_00c90e00(iValue);
    }
}

// 13-byte cdecl forwarder: loads the object pointer, fetches its vtable and
// calls the first virtual slot with a literal 0 argument.
struct VtblForwarder
{
    virtual int v0(int);
};

// @fnv 0x00d6aeb0
// src: GUESS 0x00d6aeb0 (confidence: low)
int __cdecl Runtime_ForwardCall_00d6aeb0(VtblForwarder* p)
{
    return p->v0(0);
}

extern int DAT_01269104;

// @fnv 0x00d6aee0
// src: GUESS 0x00d6aee0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d6aee0()
{
    return &DAT_01269104;
}

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
// Checks that value0 through value4 lie in [0,1] and that value5 through value11 are non-negative, returning the combined result.
// @fnv 0x00d6b1c0
hkBool MotionSettings::IsValid()
{
    hkBool result(true);
    result = result && value0 >= 0.0f && value0 <= 1.0f;
    result = result && value1 >= 0.0f && value1 <= 1.0f;
    result = result && value2 >= 0.0f && value2 <= 1.0f;
    result = result && value3 >= 0.0f && value3 <= 1.0f;
    result = result && value4 >= 0.0f && value4 <= 1.0f;
    result = result && value5 >= 0.0f;
    result = result && value6 >= 0.0f;
    result = result && value7 >= 0.0f;
    result = result && value8 >= 0.0f;
    result = result && value9 >= 0.0f;
    result = result && value10 >= 0.0f;
    result = result && value11 >= 0.0f;
    return result;
}

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

// @fnv 0x00d6c180
void __fastcall WriteCommand(D6C180Command** ppkCursor, unsigned char ucFlag)
{
    D6C180Command* pkCommand = *ppkCursor;
    pkCommand->m_ucFlag = ucFlag;
    pkCommand->m_fValue = (float)(pkCommand->m_fValue + g_dD6C180Offset);
    pkCommand->m_ucType = 3;
    *ppkCursor = pkCommand + 1;
}

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

// @fnv 0x00d76f90
// src: GUESS 0x00d76f90 (confidence: low)
void FUN_00d76f90_cls::ForwardCall_00d76f90()
{
    m_08->Tail();
}

namespace fnv_00d68820 {
extern int DAT_01269008;

// @fnv 0x00d68820
// src: GUESS 0x00d68820 (confidence: low)
int Object_GetDAT_01269008_00d68820()
{
    return DAT_01269008;
}
}  // namespace fnv_00d68820

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

// Placement-constructs an hkDerivedD6A at pvObject with a finish-loaded flag built from iFinishing, if pvObject is non-null.
// @fnv 0x00d6ae10
void __cdecl ConstructHkDerived(void* pvObject, int iFinishFlag)
{
    if (pvObject)
    {
        FinishingFlag flag;
        flag.m_bFinishing = iFinishFlag;
        new (pvObject) hkDerivedD6A(flag);
    }
}

// RTTI identifies vtable 0x010cad0c as hkMemoryBlockServer; hkReferencedObject uses 0x0102e388.
class MemoryBlockServerState
{
  public:
    MemoryBlockServerState(FinishingFlag flag);
    virtual ~MemoryBlockServerState();

};

// @fnv 0x00d60540
MemoryBlockServerState::MemoryBlockServerState(FinishingFlag flag)
{}

extern int DAT_010d14f8;
extern int DAT_0102e388;

struct D60590Object
{
    int* vtable;
    int unk04;
    hkReferencedObject* callback;

    void ReleaseReference_00d60590();
};

// @fnv 0x00d60590
// src: GUESS 0x00d60590 (confidence: medium)
void D60590Object::ReleaseReference_00d60590()
{
    vtable = &DAT_010d14f8;
    callback->removeReference();
    vtable = &DAT_0102e388;
}

namespace fnv_00d60860 {
struct HKMemoryManager
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int);
};
extern HKMemoryManager* DAT_01268364;
extern char DAT_010d14f8;
struct FUN_00d60860
{
    char* m_pVtbl;
    unsigned char m_uc04;
    unsigned short m_usSize;
    void* m_pData;
    unsigned char m_ucType;
    FUN_00d60860(void* pData, unsigned char ucType);
};
// Sets the vtable, size to 1 and type, and stores the result of DAT_01268364->v4(pData) in m_pData.
// @fnv 0x00d60860
FUN_00d60860::FUN_00d60860(void* pData, unsigned char ucType)
{
    m_usSize = 1;
    m_pVtbl = &DAT_010d14f8;
    m_ucType = ucType;
    m_pData = DAT_01268364->v4((int)pData);
}
}  // namespace fnv_00d60860

// @fnv 0x00d60900
void hkOArchive::write16(short i)
{
    WriteSwapped(&i, 2, 1);
}

struct FUN_00d60600_class
{
    void __thiscall WriteSwapped(int a, int b, int c);
    void __thiscall WriteSwapped_Thunk(int a, int b);
};

// @fnv 0x00d60b20
// src: GUESS 0x00d60b20 (confidence: medium)
void __thiscall FUN_00d60600_class::WriteSwapped_Thunk(int a, int aiValue)
{
    WriteSwapped(a, 8, aiValue);
}

struct FUN_00d61470_Class
{
    void* ReturnSelf();
};

// @fnv 0x00d61470
// src: GUESS 0x00d61470 (confidence: high)
void* FUN_00d61470_Class::ReturnSelf()
{
    return this;
}

// Methods absent from the shared header use helpers on hkStringBuf, with no private layouts.
// An unused EDX argument keeps __fastcall helper entries compatible with the original ECX-based thiscall;
// callers cast these entries to thiscall function pointers so EDX needs no setup.
char* __cdecl hkString_strStr(char* pcHaystack, const char* pcNeedle);

__forceinline void hkStringBuf::SetSizeAndGrow(int n) { m_string.setSize(n); }
__forceinline void hkStringBuf::setLength(int n) { m_string.setSize(n + 1); m_string[n] = 0; }
inline hkStringBuf::~hkStringBuf() throw() {}



// Searches m_data from iStartIndex for pcNeedle and returns its offset, or -1 if not found.
// @fnv 0x00d61480
int hkStringBuf::indexOf(const char* pcNeedle, int iStartIndex, int iEndIndex) const throw()
{
    char* pData = m_string.m_data;
    char* p = hkString_strStr(pData + iStartIndex, pcNeedle);
    if (p)
        return static_cast<int>(p - m_string.m_data);
    return -1;
}

inline char toLowerD614(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

// 0x00d614b0 searches an object-owned character buffer; hkString is a stateless utility (size 1).


// Returns the index of the first case-insensitive occurrence of needle in the string, or -1 if not found.
// @fnv 0x00d614b0
int __fastcall StringBufFindCaseInsensitive(const hkStringBuf* self, void*, const char* needle)
{
    const char* str = self->m_string.m_data;
    for (int i = 0; str[i] != 0; ++i)
    {
        int j;
        for (j = 0; needle[j] != 0; ++j)
        {
            if (toLowerD614(str[i + j]) != toLowerD614(needle[j]))
                break;
        }
        if (needle[j] == 0)
            return i;
    }
    return -1;
}

int __cdecl hkString_strStr(int a1, int a2);

// @fnv 0x00d61520
int __fastcall StringBufFindLastSubstring(hkStringBuf* self, void*, int aiValue, int aiUnused1, int aiUnused2)
{
    int esi = -1;
    int r = hkString_strStr((int)self->m_string.m_data, aiValue);
    if (r != 0)
    {
        do
        {
            esi = r - (int)self->m_string.m_data;
            r = hkString_strStr(r + 1, aiValue);
        } while (r != 0);
    }
    return esi;
}



// @fnv 0x00d61560
int __fastcall StringBufStartsWith(hkStringBuf* self, void*, const char* other)
{
    unsigned int i = 0;
    while (self->m_string.m_data[i] != 0)
    {
        if (other[i] == 0)
            break;
        if (self->m_string.m_data[i] != other[i])
            return 0;
        ++i;
    }
    return other[i] == 0;
}

inline char toLowerD615(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}



// @fnv 0x00d615a0
int hkStringBuf::startsWithCase(const char* other) const
{
    for (int i = 0; m_string[i] != 0; ++i)
    {
        if (other[i] == 0)
            return 1;
        if (toLowerD615(m_string[i]) != toLowerD615(other[i]))
            return 0;
    }
    return 1;
}


// Scans data from start up to limit (clamped to length-1) and returns the index of the first byte equal to character, or -1 if none is found.
// @fnv 0x00d61600
__declspec(noinline) int hkStringBuf::indexOf(char character, int start, int limit) const
{
    int end = limit;
    int last = m_string.m_iElementCount - 1;
    if (end >= last)
        end = last;
    for (int index = start; index < end; ++index)
    {
        if (static_cast<unsigned char>(m_string.m_data[index]) == static_cast<unsigned char>(character))
            return index;
    }
    return -1;
}



// Searches m_data backwards from endIndex-1 down to startIndex for character c and returns its index, or -1 if not found.
// @fnv 0x00d61640
__declspec(noinline) int hkStringBuf::lastIndexOf(char c, int startIndex, int endIndex) const
{
    if (endIndex > m_string.m_iElementCount - 1)
        endIndex = m_string.m_iElementCount - 1;

    for (int i = endIndex - 1; i >= startIndex; --i)
    {
        if (m_string.m_data[i] == c)
            return i;
    }
    return -1;
}



int __cdecl hkString_strCmp(int, int);

// @fnv 0x00d61680
void __fastcall StringBufCompare(hkStringBuf* self, void*, unsigned int uiValue)
{
    hkString_strCmp((int)self->m_string.m_data, uiValue);
}

void __cdecl CompareStringsCaseInsensitive(void* pvOwner, int iValue);



// @fnv 0x00d616a0
void __fastcall StringBufCompareCaseInsensitive(hkStringBuf* self, void*, int iValue)
{
    CompareStringsCaseInsensitive(self->m_string.m_data, iValue);
}

int __stdcall FUN_00d61680(unsigned int value);

// @fnv 0x00d616e0
// src: GUESS 0x00d616e0 (confidence: low)
int __stdcall Object_ForwardCall_00d616e0(unsigned int value)
{
    return FUN_00d61680(value) == 0;
}

int __cdecl hkString_strLen(int s);

// @fnv 0x00d61700
int __fastcall StringBufEndsWith(hkStringBuf* self, void*, char* aString)
{
    int len = hkString_strLen((int)aString);
    if (len > self->m_string.m_iElementCount - 1)
    {
        return 0;
    }
    int start = self->m_string.m_iElementCount - len - 1;
    for (int i = 0; i < len; ++i)
    {
        if (self->m_string.m_data[start + i] != aString[i])
        {
            return 0;
        }
    }
    return 1;
}

int __cdecl hkString_strLen(const char* str);

static inline int tolower_custom(char c)
{
    if ((unsigned char)(c - 'A') <= 25)
        return c + 0x20;
    return c;
}



// Case-insensitively compares the tail of m_data with suffix, returning 1 if it matches and fits within the buffer length.
// @fnv 0x00d61750
int __fastcall StringBufEndsWithCaseInsensitive(hkStringBuf* self, void*, const char* suffix)
{
    int len = hkString_strLen(suffix);
    if (len > self->m_string.m_iElementCount - 1)
        return 0;

    int offset = self->m_string.m_iElementCount - len - 1;
    for (int i = 0; i < len; ++i)
    {
        char c1 = tolower_custom(self->m_string.m_data[offset + i]);
        char c2 = tolower_custom(suffix[i]);
        if (c1 != c2)
            return 0;
    }
    return 1;
}


// Removes count bytes from the front of the buffer by shifting the remaining bytes down and reducing the element count.
// @fnv 0x00d617d0
__declspec(noinline) void hkStringBuf::chompStart(int count)
{
    if (count > 0)
    {
        m_string.m_iElementCount -= count;
        int remaining = m_string.m_iElementCount;
        char* destination = m_string.m_data;
        char* source = destination + count;
        if (remaining > 0)
        {
            for (int i = 0; i < remaining; ++i)
            {
                destination[i] = source[i];
            }
        }
    }
}

struct hkMathD618
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};



// Finds the last '\\' or '/' in the buffer and, if found, truncates the string to start just after it.
// @fnv 0x00d61800
void hkStringBuf::pathBasename()
{
    int iLastSeparator =
        hkMathD618::max2(lastIndexOf('\\', 0, 0x7fffffff), lastIndexOf('/', 0, 0x7fffffff));
    if (iLastSeparator >= 0)
        chompStart(iLastSeparator + 1);
}



// @fnv 0x00d61840
int hkStringBuf::replace(char from, char to, ReplaceType replaceType)
{
    int replaced = 0;
    for (int i = 0; i < getLength(); i++)
    {
        if (m_string.m_data[i] == from)
        {
            m_string.m_data[i] = to;
            replaced = 1;
            if (replaceType == 0)
                break;
        }
    }
    return replaced;
}






// Converts every character of the string buffer except the last to lowercase in place.
// @fnv 0x00d61890
void hkStringBuf::lowerCase()
{
    for (int i = 0; i < m_string.GetLogicalSize() - 1; i++)
        m_string[i] = toLowerD614(m_string[i]);
}


void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl hkString_memCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();





// Resizes the inline char array to iLength+1, null-terminates it, and copies iLength bytes from pcString into it.
// @fnv 0x00d61b10
hkStringBuf* __fastcall StringBufInitLength(hkStringBuf* self, void*, const char* pcString, int iLength) throw()
{
    self->m_string.m_data = reinterpret_cast<char*>(self->m_storage);
    self->m_string.m_iElementCount = 0;
    self->m_string.m_iCapacityState = 0x80000080;
    self->SetSizeAndGrow(iLength + 1);
    self->m_string[iLength] = 0;
    hkString_memCpy(self->m_string.begin(), pcString, iLength);
    return self;
}

int __cdecl hkString_strLen(int);
void* __cdecl hkMemoryRouter_getInstance();


int __fastcall StringBufInsert(hkStringBuf*, void*, int, int, int, int);

// Appends arg through the range-insertion operation and returns this buffer.
// @fnv 0x00d61df0
hkStringBuf& hkStringBuf::operator+=(const char* arg) throw()
{
    int ebx = hkString_strLen((int)arg);
    int ebp = m_string.m_iElementCount;
    int* rec = reinterpret_cast<int*>(hkMemoryRouter_getInstance());
    reinterpret_cast<int (__thiscall *)(hkStringBuf*, int, int, int, int)>(StringBufInsert)(this, rec[3], ebp - 1, (int)arg, ebx);
    return *this;
}

int __cdecl hkString_strLen(const char* pcString) throw();
void __cdecl hkString_memCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();



// Appends up to six C strings to the buffer, resizing it to fit the combined length plus a terminator.
// @fnv 0x00d61e30
__declspec(noinline) void hkStringBuf::appendJoin(const char* pcString0, const char* pcString1, const char* pcString2,
                                    const char* pcString3, const char* pcString4, const char* pcString5) throw()
{
    int aiLengths[6] = {};
    const char* apcStrings[] = {pcString0, pcString1, pcString2, pcString3, pcString4, pcString5, 0};
    int iOrigLen = getLength();
    int iTotalLen = iOrigLen;
    int i;
    for (i = 0; apcStrings[i] != 0; i++)
    {
        aiLengths[i] = hkString_strLen(apcStrings[i]);
        iTotalLen += aiLengths[i];
    }
    SetSizeAndGrow(iTotalLen + 1);
    m_string.m_data[iTotalLen] = 0;
    int iDstOffset = iOrigLen;
    for (i = 0; apcStrings[i] != 0; i++)
    {
        hkString_memCpy(m_string.m_data + iDstOffset, apcStrings[i], aiLengths[i]);
        iDstOffset += aiLengths[i];
    }
}

void __cdecl hkMemUtil_memCpy_00d2caa0(void* pvDst, void* pvSrc, unsigned int uiNumBytes);



// Reserves len+1 bytes, null-terminates the buffer at index len, then copies len bytes from src into m_data.
// @fnv 0x00d62020
void hkStringBuf::set(const char* src, int len)
{
    SetSizeAndGrow(len + 1);
    m_string.m_data[len] = 0;
    hkMemUtil_memCpy_00d2caa0(m_string.m_data, const_cast<char*>(src), len);
}

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



// @fnv 0x00d62080
__declspec(noinline) void __fastcall StringBufAppend(hkStringBuf* self, void*, int aData, int param3)
{
    if (param3 < 0)
        param3 = hkString_strLen(aData);

    int oldCount = self->m_string.m_iElementCount;
    oldCount--;

    int index = oldCount + param3;
    int newCount = index + 1;

    D62080_Audio* audio = (D62080_Audio*)hkMemoryRouter_getInstance();
    int audioValue = audio->unk0c;

    int capacity = (int)(self->m_string.m_iCapacityState & 0x3fffffff);
    if (capacity < newCount)
    {
        capacity *= 2;
        if (newCount >= capacity)
            capacity = newCount;

        hkArrayUtil__reserve(audioValue, (int)self, capacity, 1);
    }

    self->m_string.m_iElementCount = newCount;
    self->m_string.m_data[index] = 0;

    hkMemUtil_memCpy_00d2caa0(self->m_string.m_data + oldCount, aData, param3);
}

extern int __cdecl hkString_strLen(int value);


// @fnv 0x00d62100
__declspec(noinline) int __fastcall StringBufInsertAt(hkStringBuf* self, void*, int first, int second, int third)
{
    if (third < 0)
        third = hkString_strLen(second);
    hkMemoryRouter* router = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    return reinterpret_cast<int (__thiscall *)(hkStringBuf*, int, int, int, int)>(StringBufInsert)(self, (int)router->m_temp, first, second, third);
}


void __fastcall StringBufClear(hkStringBuf*, void*);


// @fnv 0x00d62140
int __fastcall StringBufPathDirname(hkStringBuf* self, void*)
{
    int first = self->lastIndexOf(0x2f, 0, 0x7fffffff);
    int second = self->lastIndexOf(0x5c, 0, 0x7fffffff);
    if (second <= first)
        second = first;
    if (second >= 0)
    {
        typedef int (hkStringBuf::*SliceResult)(int, int);
        return (self->*reinterpret_cast<SliceResult>(&hkStringBuf::slice))(0, second);
    }
    return reinterpret_cast<int (__thiscall *)(hkStringBuf*)>(StringBufClear)(self);
}

inline const char* hkStringPtr::cString() const
{
    return (const char*)((unsigned int)m_pcText & ~1);
}



// @fnv 0x00d623a0
hkStringBuf* __fastcall StringBufInitStringPtr(hkStringBuf* self, void*, const hkStringPtr& str)
{
    self->m_string.m_data = reinterpret_cast<char*>(self->m_storage);
    self->m_string.m_iElementCount = 0;
    self->m_string.m_iCapacityState = 0x80000080;
    self->FUN_00d61c10(str.cString());
    return self;
}



// Sets up the object's internal pointer and counters, then forwards the six arguments to appendJoin.
// @fnv 0x00d623d0
hkStringBuf* __fastcall StringBufInitJoin(hkStringBuf* self, void*, int a, int b, int c, int d, int e, int f)
{
    self->m_string.m_data = reinterpret_cast<char*>(self->m_storage);
    self->m_string.m_iElementCount = 0;
    self->m_string.m_iCapacityState = 0x80000080;
    ((char*)self->m_string.m_data)[0] = 0;
    ++self->m_string.m_iElementCount;
    self->appendJoin((const char*)a, (const char*)b, (const char*)c, (const char*)d, (const char*)e, (const char*)f);
    return self;
}



// @fnv 0x00d62580
int __fastcall StringBufPrepend(hkStringBuf* self, void*, int a, int b)
{
    return reinterpret_cast<int (__thiscall *)(hkStringBuf*, int, int, int)>(StringBufInsertAt)(self, 0, a, b);
}



int __fastcall StringBufReplaceRange(hkStringBuf*, void*, int, int, int, int, int);

// @fnv 0x00d62630
__declspec(noinline) int __fastcall StringBufInsert(hkStringBuf* self, void*, int a, int b, int d, int e)
{
    return reinterpret_cast<int (__thiscall *)(hkStringBuf*, int, int, int, int, int)>(StringBufReplaceRange)(self, a, b, 0, d, e);
}

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

// Calls FUN_00ddccb0 with aParam, then stores three global addresses and aValue into the object's fields and returns this.
// @fnv 0x00d62ef0
// src: GUESS 0x00d62ef0 (confidence: low)
FUN_00d62ef0_cls* __thiscall FUN_00d62ef0_cls::UpdateState_00d62ef0(int aParam, unsigned char aValue)
{
    ((FUN_00ddccb0_Obj*)this)->FUN_00ddccb0(aParam);
    unk00 = &DAT_010d1720;
    unk08 = &DAT_010d1700;
    unk20 = &DAT_010d16f0;
    unk28 = aValue;
    return this;
}

struct HeapBlockMetadata
{
    unsigned int flags;
    unsigned short size;
    unsigned short reserved;
    HeapBlockMetadata* UpdateState_00d62ef0(void* data, unsigned int enabled);
};
// @fnv 0x00d62f60
void* __cdecl AllocateRecordWithData(void* data)
{
    hkMemoryRouter* memory = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    HeapBlockMetadata* record = static_cast<HeapBlockMetadata*>(reinterpret_cast<hkMemoryAllocator*>(memory->m_heap)->blockAlloc(44));
    record->size = 44;
    HeapBlockMetadata* result = record->UpdateState_00d62ef0(data, 1);
    return result ? reinterpret_cast<char*>(result) + 8 : 0;
}

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

// @fnv 0x00d632c0
// src: HAVOK_LIB 0x00d632c0
Base2_d632c0* hkpWorldMemoryViewer_create(int aiValue)
{
    hkMemoryRouter* holder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    Obj_d632c0* obj = (Obj_d632c0*)reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockAlloc(0x54);
    obj->size = 0x54;
    obj = obj->hkpWorldMemoryViewer_hkpWorldMemoryViewer(0, aiValue);
    return obj;
}

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

// Iterates the container's items and passes each to the listener's v04 callback when m_container is set.
// @fnv 0x00d63300
// src: GUESS 0x00d63300 (confidence: medium)
void hkObjD633::NotifyContainerItems()
{
    if (m_container)
    {
        for (int i = 0; i < m_container->m_uiItemCount; i++)
            m_kListener.v04(m_container->m_items[i]);
    }
}

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

// Rebuilds the debug display buffer with each physics world, then passes the buffer and its length to the display handler.
// @fnv 0x00d63370
void FUN_00d63370_class::UpdatePhysicsDebugDisplay(float fFrameTime) throw()
{
    m_pStreamWriter.ClearContainer();
    m_pStreamWriter.Clear_Thunk(0);
    for (int i = 0; i < m_iValueAtOffset0C->m_numWorlds; i++)
        m_pStreamWriter.addObject("World", m_iValueAtOffset0C->m_ppWorlds[i], 0);
    m_pStreamWriter.Object_Clear_Thunk();
    if (m_pStreamWriter.hasData())
        m_pDisplayHandler->WriteOutput(m_pStreamWriter.getData(), m_pStreamWriter.GetLogicalSize());
}

namespace fnv_00d63400 {
class FUN_00dd9380_class
{
  public:
    void* hkProcessFactory_registerProcess(const char* pcName, void* pvCreateFunc);
};

void __cdecl hkpWorldMemoryViewer_create();

extern void* DAT_01268fc8;

// @fnv 0x00d63400
void __cdecl InitWorldMemory()
{
    DAT_01268fc8 =
        reinterpret_cast<FUN_00dd9380_class*>(DAT_01269cd0)->hkProcessFactory_registerProcess("World Memory", (void*)hkpWorldMemoryViewer_create);
}
}  // namespace fnv_00d63400

extern int DAT_01268fc8;
// @fnv 0x00d63420
// src: GUESS 0x00d63420 (confidence: low)
int __cdecl Object_GetDAT_01268fc8_00d63420()
{
    return DAT_01268fc8;
}

void* __cdecl hkMemoryRouter_getInstance();

class FUN_00d63340
{
  public:
    virtual ~FUN_00d63340() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        GetHolderAllocator<hkMemoryAllocator>(static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance()))
            .blockFree(p, static_cast<FUN_00d63340*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d63340* Destroy(unsigned int uiFlags) throw();
};

// Calls the destructor, and if bit 0 of uiFlags is set, frees the object through operator delete; returns this.
// @fnv 0x00d63450
FUN_00d63340* FUN_00d63340::Destroy(unsigned int uiFlags) throw()
{
    this->FUN_00d63340::~FUN_00d63340();
    if (uiFlags & 1)
        FUN_00d63340::operator delete(this);
    return this;
}

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

// Constructs the object by forwarding p to the base constructor and default-initializing the void* array member.
// @fnv 0x00d64260
FUN_00d64260::FUN_00d64260(void* p) throw() : FUN_00ddccb0(p)
{}

struct FnvCpu_FUN_00d645f0_CpuBlock;
void* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d645f0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d645f0_CpuBlock* FUN_00d64260(unsigned int value);
};
// @fnv 0x00d645f0
// src: XBOX_PDB 0x00d645f0
void* __cdecl hkpSweptTransformDisplayViewer_create(unsigned int value)
{
    hkMemoryRouter* holder = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    FnvCpu_FUN_00d645f0_CpuBlock* block = static_cast<FnvCpu_FUN_00d645f0_CpuBlock*>(reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockAlloc(60));
    block->size = 60;
    block = block->FUN_00d64260(value);
    if (block)
        return reinterpret_cast<char*>(block) + 8;
    return 0;
}

namespace fnv_00d64630 {
class FUN_00dd9380_class
{
  public:
    void* hkProcessFactory_registerProcess(const char* pcName, void* pvCreateFunc);
};

extern void* DAT_01268fd0;
void __cdecl hkpSweptTransformDisplayViewer_create();

// @fnv 0x00d64630
void __cdecl RegisterSweptTransformsTask()
{
    DAT_01268fd0 =
        reinterpret_cast<FUN_00dd9380_class*>(DAT_01269cd0)->hkProcessFactory_registerProcess("Swept Transforms", (void*)hkpSweptTransformDisplayViewer_create);
}
}  // namespace fnv_00d64630

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

// @fnv 0x00d65250
// src: GUESS 0x00d65250 (confidence: low)
void __thiscall FUN_00d65250_cls::SetUnk61(unsigned char value)
{
    unk61 = value;
}

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
// @fnv 0x00d65260
// src: GUESS 0x00d65260 (confidence: medium)
void FnvCpu_FUN_00d65260_CpuObject::SetValue_00d65260(unsigned char arg0)
{
    value = arg0;
}

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
// @fnv 0x00d65270
// src: GUESS 0x00d65270 (confidence: low)
void FnvCpu_FUN_00d65270_CpuObject::SetValue(unsigned char arg0)
{
    value = arg0;
}

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

// @fnv 0x00d65280
// src: GUESS 0x00d65280 (confidence: low)
void FUN_00d65280_cls::SetField63_00d65280(bool bValue)
{
    m_63 = bValue;
}

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
// @fnv 0x00d65290
// src: GUESS 0x00d65290 (confidence: low)
void FnvCpu_FUN_00d65290_CpuObject::SetValue(unsigned char arg0)
{
    value = arg0;
}

// @fnv 0x00d6add0
// src: COMMUNITY 0x00d6add0
void __cdecl nullsub_103()
{}

extern "C" void __cdecl hkMathUtil_decompose4x4ColTransform();
// @fnv 0x00d73380
// src: GUESS 0x00d73380 (confidence: medium)
void __cdecl Object_HkMathUtil_decompose4x4ColTransform_Thunk()
{
    hkMathUtil_decompose4x4ColTransform();
}

class FUN_00d733e0
{
  public:
    FUN_00d733e0();

    int m_iFirst;
    int m_iSecond;
    bool m_bEnableState;
};

// @fnv 0x00d733e0
FUN_00d733e0::FUN_00d733e0()
{
    m_iFirst = 0;
    m_iSecond = 0;
    m_bEnableState = true;
}

struct FUN_00d73400_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void UpdateFields_00d73400();
};

// @fnv 0x00d73400
// src: GUESS 0x00d73400 (confidence: low)
void FUN_00d73400_cls::UpdateFields_00d73400()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    unk0C = 0;
}

extern hkError* DAT_01268360;

struct hkpTransformCollapseUtilResultsD734
{
    int m_iFirstResult;
    int m_iSecondResult;
    int m_iThirdResult;
    int m_iFourthResult;

    void PrintResults() throw();
};

// Logs four counters (collapsed shapes, removed identity transforms, specialized shapes, propagated transforms) via hkError::message.
// @fnv 0x00d73430
void hkpTransformCollapseUtilResultsD734::PrintResults() throw()
{
    {
        unsigned int auiBuf[128];
        hkErrStream kStream(auiBuf, sizeof(auiBuf));
        kStream.ProcessAndReturnValue_00cc01c0("Number of collapsed shapes :").WriteInt(m_iFirstResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 57);
    }
    {
        unsigned int auiBuf[128];
        hkErrStream kStream(auiBuf, sizeof(auiBuf));
        kStream.ProcessAndReturnValue_00cc01c0("Number of identity transforms removed : ").WriteInt(m_iSecondResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 58);
    }
    {
        unsigned int auiBuf[128];
        hkErrStream kStream(auiBuf, sizeof(auiBuf));
        kStream.ProcessAndReturnValue_00cc01c0("Number of specialized transform shapes : ").WriteInt(m_iThirdResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 59);
    }
    {
        unsigned int auiBuf[128];
        hkErrStream kStream(auiBuf, sizeof(auiBuf));
        kStream.ProcessAndReturnValue_00cc01c0("Number of propagated transforms to lists : ").WriteInt(m_iFourthResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 60);
    }
}

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
// @fnv 0x00d76d80
// src: GUESS 0x00d76d80 (confidence: low)
void FnvCpu_FUN_00d76d80_CpuOwner::ForwardCall_00d76d80()
{
    target->ProcessEntries_00d81340();
}

extern int DAT_010d14f8;
// LocalhkBool: 0x00d608a0 constructs the outgoing byte on the stack; the shared hkBool's trivial copy emits 87 rather
// than 83 bytes.
namespace archive_arguments {
class LocalhkBool
{
  public:
    char m_cBooleanValue;
    LocalhkBool(bool enabled) : m_cBooleanValue(enabled) {}
    LocalhkBool(const LocalhkBool& other) : m_cBooleanValue(other.m_cBooleanValue) {}
};
}
struct FUN_00d274c0
{
    void* unk00;
    unsigned short allocatedSize;
    FUN_00d274c0(int first, int second, archive_arguments::LocalhkBool enabled);
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
// Initializes count, vptr, and mode, then allocates and constructs a FUN_00d274c0 child node via the router allocator.
// @fnv 0x00d608a0
FUN_00d608a0::FUN_00d608a0(int first, int second, unsigned char mode)
{
    count = 1;
    vptr = &DAT_010d14f8;
    this->mode = mode;
    hkMemoryRouter* router = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    FUN_00d274c0* next = static_cast<FUN_00d274c0*>(reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockAlloc(28));
    next->allocatedSize = 28;
    child = new (next) FUN_00d274c0(first, second, archive_arguments::LocalhkBool(false));
}

int __cdecl hkString_strCmp(int, int);
struct R
{
    volatile char value;
    R(bool b) : value(b)
    {}
};

// The original wrapper return uses a hidden output pointer before the explicit stack argument.
// @fnv 0x00d616c0
R* __fastcall StringBufIsLessThan(const hkStringBuf* self, void*, R* result, int other)
{
    int compared = hkString_strCmp((int)self->m_string.m_data, other);
    bool less = compared < 0;
    result->value = less;
    return result;
}



// Splits m_string in place at each c found from index 1 by writing nulls, appends each piece pointer to kBits, and returns kBits's size.
// @fnv 0x00d61910
int hkStringBuf::split(int c, hkArray<const char*, hkContainerTempAllocator>& kBits)
{
    const char* firstPiece = m_string.m_data;
    kBits.pushBack(firstPiece);
    int iNumBits = kBits.GetLogicalSize();
    int iCur = indexOf(c, 1, 0x7fffffff);
    while (iCur >= 0)
    {
        m_string[iCur] = 0;
        int iStart = iCur + 1;
        kBits.pushBack(m_string.m_data + iStart);
        iNumBits = kBits.GetLogicalSize();
        iCur = indexOf(c, iStart, 0x7fffffff);
    }
    return iNumBits;
}

template <class T> inline void hkArrayCopyD61(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}



// Copies the source array, growing the buffer via the memory router if the source size exceeds the current capacity.
// @fnv 0x00d619d0
hkStringBuf& __fastcall StringBufAssign(hkStringBuf* self, void*, const hkStringBuf& aSource)
{
    hkMemoryAllocator& alloc = *static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->m_temp;
    if ((self->m_string.m_iCapacityState & 0x3fffffff) < aSource.m_string.m_iElementCount)
    {
        if ((self->m_string.m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(self->m_string.m_data, (self->m_string.m_iCapacityState & 0x3fffffff));
        int n = aSource.m_string.m_iElementCount;
        self->m_string.m_data = (char*)alloc.bufAlloc(n);
        self->m_string.m_iCapacityState = n;
    }
    self->m_string.m_iElementCount = aSource.m_string.m_iElementCount;
    hkArrayCopyD61(self->m_string.m_data, aSource.m_string.m_data, self->m_string.m_iElementCount);
    return *self;
}



namespace fnvc_adapt {
char* __cdecl hkString_strLen(int value);
}
void __cdecl hkArrayUtil__reserve(int allocator, hkStringBuf* array, int capacity, int value);
void __cdecl hkString_memCpy(int* data, int value, char* source);

// Initializes the string buffer, grows capacity if needed, copies value into m_data, and returns this.
// @fnv 0x00d61a50
int* __fastcall StringBufInitString(hkStringBuf* self, void*, int value)
{
    self->m_string.m_data = reinterpret_cast<char*>(self->m_storage);
    self->m_string.m_iElementCount = 0;
    self->m_string.m_iCapacityState = 0x80000080;

    if (value != 0)
    {
        char* source = fnvc_adapt::hkString_strLen(value);
        int count = (int)source + 1;

        void* audio = hkMemoryRouter_getInstance();
        int allocator = *(int*)((char*)audio + 0x0C);
        int capacity = self->m_string.m_iCapacityState & 0x3FFFFFFF;

        if (capacity < count)
        {
            capacity = capacity * 2;
            if (count >= capacity)
                capacity = count;
            hkArrayUtil__reserve(allocator, self, capacity, 1);
        }

        self->m_string.m_iElementCount = count;
        *(char*)(source + (int)self->m_string.m_data) = 0;
        hkString_memCpy(reinterpret_cast<int*>(self->m_string.m_data), value, source);
    }
    else
    {
        void* audio = hkMemoryRouter_getInstance();
        int allocator = *(int*)((char*)audio + 0x0C);
        int capacity = self->m_string.m_iCapacityState & 0x3FFFFFFF;

        if (capacity < 1)
        {
            capacity = capacity * 2;
            if (capacity <= 1)
                capacity = 1;
            hkArrayUtil__reserve(allocator, self, capacity, 1);
        }

        self->m_string.m_iElementCount = 1;
        *(char*)self->m_string.m_data = 0;
    }

    return (int*)self;
}

template <class T> __forceinline void hkArrayCopyD61B8(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; ++i)
        pDst[i] = pSrc[i];
}





// Copy-constructs the inline buffer, allocating external storage only when needed.
// @fnv 0x00d61b80
hkStringBuf* __fastcall StringBufInitCopy(hkStringBuf* self, void*, const hkStringBuf& other) throw()
{
    self->m_string.m_data = reinterpret_cast<char*>(self->m_storage);
    self->m_string.m_iElementCount = 0;
    self->m_string.m_iCapacityState = 0x80000080;
    hkMemoryAllocator& kAlloc = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->temp();
    if (self->getCapacity() < other.m_string.m_iElementCount)
    {
        if ((self->m_string.m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(self->m_string.m_data, self->getCapacity() * sizeof(char));
        int n = other.m_string.m_iElementCount * sizeof(char);
        self->m_string.m_data = static_cast<char*>(kAlloc.bufAlloc(n));
        self->m_string.m_iCapacityState = n / sizeof(char);
    }
    self->m_string.m_iElementCount = other.m_string.m_iElementCount;
    hkArrayCopyD61B8(self->m_string.m_data, other.m_string.m_data, self->m_string.m_iElementCount);
    return self;
}

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

void __cdecl ArrayReserveImpl(void*, void*, int, int);
// Reserves space for an empty string if needed, then sets the element count to 1 and writes a terminator.
// @fnv 0x00d61cc0
__declspec(noinline) void __fastcall StringBufClear(hkStringBuf* self, void*)
{
    C6DF60Router* router = _FNV_e03300_arena();
    hkMemoryAllocator* allocator = (hkMemoryAllocator*)(void*)router->unk0c;
    int state = self->m_string.m_iCapacityState & 0x3fffffff;
    if (state < 1)
    {
        int count = state << 1;
        if (count <= 1)
            count = 1;
        ArrayReserveImpl(allocator, self, count, 1);
    }
    self->m_string.m_iElementCount = 1;
    *self->m_string.m_data = 0;
}



// If n > 0, removes the last n characters by resizing the buffer to its size minus n and null-terminating it.
// @fnv 0x00d61f70
void hkStringBuf::chompEnd(int n)
{
    if (n > 0)
    {
        int iLen = m_string.GetLogicalSize() - n - 1;
        m_string.setSize(iLen + 1);
        m_string[iLen] = 0;
    }
}



void hkMemUtil_memMove(void* pvDst, void* pvSrc, unsigned int uiNumBytes);



// @fnv 0x00d61fc0
void hkStringBuf::slice(int iOffset, int iLength)
{
    if (iOffset)
        hkMemUtil_memMove(m_string.m_data, m_string.m_data + iOffset, iLength);
    int n = iLength + 1;
    hkMemoryAllocator& kAlloc = static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->temp();
    const int iCap = getCapacity();
    if (iCap < n)
    {
        int iCap2 = 2 * iCap;
        int iNewCap = (n < iCap2) ? iCap2 : n;
        ::hkArrayUtil__reserve(kAlloc, this, iNewCap, sizeof(char));
    }
    m_string.m_iElementCount = n;
    m_string.m_data[iLength] = 0;
}


namespace hkRouterD62 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

__forceinline void* __cdecl hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(
        GetHolderAllocator<hkMemoryAllocator>(&hkRouterD62::hkMemoryRouter_getInstance()).blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return b;
}

// 0x00d62ef0 installs vtables at +0, +8 and +0x20; its returned +8 base is hkProcess.
class FUN_00d62ef0 : public hkpWorldViewerBase
{
  public:
    using hkReferencedObject::operator new;
    FUN_00d62ef0(void* contexts, int flags) throw();
    unsigned char m_flags;
};

// Allocates a viewer and returns its hkProcess base at +8.
// @fnv 0x00d62f20
// src: HAVOK_LIB 0x00d62f20
hkProcess* __cdecl hkpWorldSnapshotViewer_createNative(void* contactMgr)
{
    return new FUN_00d62ef0(contactMgr, 0);
}

// @fnv 0x00d6c1a0
// src: GUESS 0x00d6c1a0 (confidence: low)
__declspec(noinline) static void Object_UpdateFields_00d6c1a0(int* piValue)
{
    *piValue -= 16;
}

void E6C1A0Adjust(int* piValue)
{
    Object_UpdateFields_00d6c1a0(piValue);
}

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

// @fnv 0x00d73410
FUN_00d73410::FUN_00d73410()
{
    m_iUnk00 = 0;
    m_iUnk04 = 0;
    m_iUnk08 = 0;
    m_iUnk0C = 0;
    ((Z0*)this)->UpdateFields_00d73400();
}

struct Node
{
    unsigned unk00, unk04, unk08, unk0c;
    void* active;
    Node* left;
    Node* right;
    unsigned unk1c, unk20, unk24, unk28, flags;
};
// For each node whose left and right children are both active, rewrites their flags with seed and 5-bit ids from a running counter or the other child.
// @fnv 0x00d74b70
void __cdecl AssignNodeFlags(Node** nodes, int count, unsigned auSeed)
{
    unsigned nextId = 0;
    int index = 0;
    if (count > 0)
    {
        do
        {
            Node* item = nodes[index];
            Node* left = item->left;
            Node* right = item->right;
            if (left && left->active && right && right->active)
            {
                unsigned leftPacked = left->flags;
                unsigned rightPacked = right->flags;
                unsigned midLeft = (leftPacked >> 5) & 31;
                unsigned midRight = (rightPacked >> 5) & 31;
                unsigned highLeft = (leftPacked >> 10) & 31;
                unsigned highRight = (rightPacked >> 10) & 31;
                unsigned lowLeft = leftPacked & 31;
                unsigned lowRight = rightPacked & 31;
                if (!midLeft)
                    midLeft = nextId++;
                if (!midRight)
                    midRight = nextId++;
                if (!highLeft)
                    highLeft = midRight;
                else
                    highRight = midLeft;
                left->flags = ((((auSeed << 6) | highLeft) << 5) | midLeft) << 5 | lowLeft;
                right->flags = ((((auSeed << 6) | highRight) << 5) | midRight) << 5 | lowRight;
            }
            ++index;
        } while (index < count);
    }
}

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

// Forwards a call to m_target->FUN_00d7e740, passing iSelector == 0 as the third argument.
// @fnv 0x00d76c20
int FUN_00d76c20_cls::ForwardToTarget(int iSelector, int iArg0, int iArg1, int iArg2)
{
    return m_target->hkgpConvexHullImpl_generateIndexedFaces_unsigned_char_unsigned_short(iArg0, iArg1, iSelector == 0, iArg2);
}

// 0x00d79250 writes a collision-object pointer through this output slot; hkResult is an enum.
struct CollisionObjectOutput
{
    void* m_pCollisionObject;
};

void __cdecl hkgpConvexHull_booleanSplit(void* a, void* b, CollisionObjectOutput* out, int flags, float f);

// Calls FUN_00d79250 with flags 0 and returns whether the collision-object output is set.
// @fnv 0x00d794e0
// src: HAVOK_LIB 0x00d794e0
bool __cdecl hkgpConvexHull_booleanIntersection(void* a, void* b, CollisionObjectOutput* apResult, float f)
{
    hkgpConvexHull_booleanSplit(a, b, apResult, 0, f);
    return apResult->m_pCollisionObject != 0;
}

// @fnv 0x00d61430
static __declspec(noinline) int ToLowerCase(char c)
{
    return ((unsigned char)(c - 'A') <= 25) ? c + 0x20 : c;
}

volatile char g_d61430_c;
char g_d61430_sink;

void d61430_caller()
{
    g_d61430_sink = (char)ToLowerCase(g_d61430_c);
}

// @fnv 0x00d61450
// src: HAVOK_LIB 0x00d61450
static __declspec(noinline) int toupper_00d61450(char c)
{
    return ((unsigned char)(c - 'a') <= 25) ? c - 0x20 : c;
}

volatile char g_d61450_c;
char g_d61450_sink;

void d61450_caller()
{
    g_d61450_sink = (char)toupper_00d61450(g_d61450_c);
}

struct D6C1B0Owner
{
    int unk00;
    void(__cdecl* unk04)(int, int, D6C180Command**);
    int unk08;
};

extern "C" D6C180Command** d6c1b0_cursor_src(void);
volatile int g_d6c1b0_a1;
D6C1B0Owner* volatile g_d6c1b0_owner;

// @fnv 0x00d6c1b0
// src: HAVOK_LIB 0x00d6c1b0
static __declspec(noinline) void callBridgeFromAtom(D6C180Command** ppkCursor, D6C1B0Owner* pOwner, int a1)
{
    *ppkCursor -= 1;
    pOwner->unk04(pOwner->unk08, a1, ppkCursor);
}

void d6c1b0_caller(void)
{
    callBridgeFromAtom(d6c1b0_cursor_src(), g_d6c1b0_owner, g_d6c1b0_a1);
}

// Exe 0x00d6c240 FUN_00d6c240: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, int imm);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);

extern "C" LocalM128 g_d6c1d0_src[4];
extern "C" LocalM128 g_d6c1d0_mat[4];
extern "C" LocalM128 g_d6c1d0_out[4];

// For i=0..3 sets out[i] to b[i].x*a[0] + b[i].y*a[1] + b[i].z*a[2], then adds a[3] to out[3].
// @fnv 0x00d6c1d0
// src: GUESS 0x00d6c1d0 (confidence: medium)
static __declspec(noinline) void Runtime_MultiplyAffineTransformColumns(LocalM128* __restrict out, const LocalM128* __restrict a,
                                              const LocalM128* __restrict b)
{
    const LocalM128& c1 = a[1];
    const LocalM128& c0 = a[0];
    const LocalM128& c2 = a[2];
    for (int i = 3; i >= 0; i--)
    {
        const LocalM128& v = b[i];
        out[i] =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0), _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1)),
                       _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));
    }
    out[3] = _mm_add_ps(a[3], out[3]);
}

void fnv_probe_d6c1d0()
{
    Runtime_MultiplyAffineTransformColumns(g_d6c1d0_out, g_d6c1d0_mat, g_d6c1d0_src);
}

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
// @fnv 0x00d720a0
// src: GUESS 0x00d720a0 (confidence: low)
static __declspec(noinline) float Object_ComputeValue_00d720a0(IntegratorD720* self, float input, float step)
{
    float value = self->state;
    float delta = input - value;
    float error = -self->offset - delta;
    float limit = DAT_011b6924 * step;
    float proposed = -DAT_011b6928 * value;
    float change = proposed < limit ? proposed : limit;
    value += change;
    delta -= change;
    if (error > limit + 2.0f * change)
    {
        value -= error;
        delta += error;
    }
    self->state = DAT_010c8440 > value ? value : DAT_010c8440;
    return delta;
}

IntegratorD720* volatile integratorD720;
volatile float inputD720, stepD720, resultD720;
void invokeD720()
{
    resultD720 = Object_ComputeValue_00d720a0(integratorD720, inputD720, stepD720);
}

struct FUN_00d74dc0_cls
{
    void* GetFieldAtOffset10Address_00d74dc0();
};

// @fnv 0x00d74dc0
// src: GUESS 0x00d74dc0 (confidence: low)
void* FUN_00d74dc0_cls::GetFieldAtOffset10Address_00d74dc0()
{
    return (char*)this + 0x10;
}

#include <stdarg.h>

void* __cdecl hkMemoryRouter_getInstance();
int __cdecl hkString_vsnprintf(char* pcBuf, int iBufSize, const char* pcFormat, va_list kArgs) throw();



// 0x00d62420 forwards formatted text to hkStringBuf append (0x00d62080), not to hkOstream.


// Formats pcFormat and varargs into a growable buffer via FUN_00cb0f50, resizing and retrying until it fits, then passes it to FUN_00d62080 with length -1.
// @fnv 0x00d62420
void __cdecl StringBufWriteFormatted(hkStringBuf* self, const char* pcFormat, ...) throw()
{
    hkStringBuf kBuf;
    while (1)
    {
        int iSize = kBuf.m_string.getCapacity();
        va_list kArgs;
        va_start(kArgs, pcFormat);
        int iNumChars = hkString_vsnprintf(kBuf.m_string.begin(), iSize, pcFormat, kArgs);
        va_end(kArgs);
        if (iNumChars >= 0 && iNumChars < iSize)
        {
            kBuf.setLength(iNumChars);
            break;
        }
        else if (iNumChars < 0)
        {
            kBuf.setLength((2 * iSize > 255) ? 2 * iSize : 255);
        }
        else
        {
            kBuf.setLength(iNumChars);
        }
    }
    reinterpret_cast<void (__thiscall *)(hkStringBuf*, int, int)>(StringBufAppend)(self, (int)kBuf.cString(), -1);
}

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

namespace fnv_00d68900 {
// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk (second base's vtable entry).
// PrimaryBase is 0x20 bytes: vptr + seven ints.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d68900();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d68900();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68900
// src: GUESS 0x00d68900 (confidence: low)
    virtual void AdjustThisAndForward_00d68900();
};

Derived::Derived()
{}
}  // namespace fnv_00d68900

struct Node_d6c580
{
    unsigned short m_type;
    char pad[0x12];
    Node_d6c580* m_parent;
};

// @fnv 0x00d6c580
// src: GUESS 0x00d6c580 (confidence: low)
static __declspec(noinline) Node_d6c580* Object_ProcessEntries_00d6c580(Node_d6c580* n)
{
    do
    {
        n = n->m_parent;
    } while (n->m_type >= 0x17);
    return n;
}

Node_d6c580* zz_probe_d6c580(Node_d6c580* n)
{
    return Object_ProcessEntries_00d6c580(n);
}

// @fnv 0x00d6c590
// src: GUESS 0x00d6c590 (confidence: low)
static __declspec(noinline) void Runtime_UpdateState_00d6c590(int* p)
{
    *p -= 0x10;
}

void zz_probe_d6c590(int* p)
{
    Runtime_UpdateState_00d6c590(p);
}



namespace fnv_00d61c10 { extern "C" int __cdecl hkString_strLen(const char* pcString) throw(); }
void __cdecl hkString_memCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();



// Copies a null-terminated string into the internal buffer, growing it as needed, or clears it to an empty string when the input is null.
// @fnv 0x00d61c10
hkStringBuf& hkStringBuf::operator=(const char* apcString)
{
    if (apcString)
    {
        int len = fnv_00d61c10::hkString_strLen(apcString);
        m_string.setSize(len + 1);
        m_string[len] = 0;
        hkString_memCpy(m_string.begin(), apcString, len);
    }
    else
    {
        m_string.setSize(1);
        m_string[0] = 0;
    }
    return *this;
}


namespace fnv_00d63340 {
namespace FUN_00ddf240 {
// 0x00ddf240 is hkStreamStatisticsCollector::~hkStreamStatisticsCollector, not an hkArray destructor.
class StreamStatisticsCollectorState
{
  public:
    ~StreamStatisticsCollectorState() throw();
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
}

namespace FUN_00d63340 {
class hkpWorldMemoryViewer : public hkpWorldViewerBase
{
  public:
    virtual ~hkpWorldMemoryViewer();

    FUN_00ddf240::StreamStatisticsCollectorState m_worldMemory;
};

// @fnv 0x00d63340
hkpWorldMemoryViewer::~hkpWorldMemoryViewer()
{
}
}
}  // namespace fnv_00d63340

class RotationColumns;

class QuadDirection
{
  public:
    __forceinline QuadDirection()
    {}
    __forceinline QuadDirection(const QuadDirection& other)
    {
        value = other.value;
    }
    __forceinline void operator=(const QuadDirection& other)
    {
        value = other.value;
    }
    __forceinline void multiply(const RotationColumns& rotation, const QuadDirection& input);
    LocalM128 value;
};

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
    __forceinline QuadDirection& column(int i)
    {
        return columns[i];
    }
    __forceinline const QuadDirection& column(int i) const
    {
        return columns[i];
    }
    QuadDirection columns[3];
};

__forceinline void QuadDirection::multiply(const RotationColumns& rotation, const QuadDirection& input)
{
    const LocalM128 componentX = _mm_shuffle_ps(input.value, input.value, 0);
    const LocalM128 termX = _mm_mul_ps(rotation.column(0).value, componentX);
    const LocalM128 componentY = _mm_shuffle_ps(input.value, input.value, 0x55);
    const LocalM128 termY = _mm_mul_ps(rotation.column(1).value, componentY);
    const LocalM128 componentZ = _mm_shuffle_ps(input.value, input.value, 0xaa);
    const LocalM128 termZ = _mm_mul_ps(rotation.column(2).value, componentZ);
    value = _mm_add_ps(_mm_add_ps(termX, termY), termZ);
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
    QuadDirection translation;
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

static __forceinline void RotateDirections(const RotationColumns& rotation, const QuadDirection* source, int count,
                                           QuadDirection* destination)
{
    RotationColumns saved = rotation;
    int i = count - 1;
    do
    {
        destination[i].multiply(saved, source[i]);
    } while (--i >= 0);
}

// Rotates four vectors from local.localA and local.localB by the rotations of input.transformA and transformB, storing them in outputA and outputB.
// @fnv 0x00d6c3c0
// src: GUESS 0x00d6c3c0 (confidence: medium)
static __declspec(noinline) void Object_RotateBodyVectorBundles(const LocalOrientations& local, const ConstraintQuery& input,
                                              RigidTransform& outputA, RigidTransform& outputB)
{
    RotateDirections(input.transformA.get()->rotation(), &local.localA.column(0), 4, &outputA.rotation().column(0));
    RotateDirections(input.transformB.get()->rotation(), &local.localB.column(0), 4, &outputB.rotation().column(0));
}

void RotateLocalFrames(const LocalOrientations& local, const ConstraintQuery& input, RigidTransform& outputA,
                       RigidTransform& outputB)
{
    Object_RotateBodyVectorBundles(local, input, outputA, outputB);
}

extern "C" LocalM128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, LocalM128 a);

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

// Copies three float arrays from source into data, loads a fourth from DAT_01267e30, calls FUN_00de8f10, then calls FUN_00d73380 with data and count.
// @fnv 0x00d73390
// src: GUESS 0x00d73390 (confidence: low)
void __cdecl hkMatrix4_resetFourthRow_ProcessState_00d73390(D73390Source* source, int count)
{
    D73390Data data;

    _mm_store_ps(data.value0, _mm_load_ps(source->value0));
    _mm_store_ps(data.value1, _mm_load_ps(source->value1));
    _mm_store_ps(data.value2, _mm_load_ps(source->value2));
    _mm_store_ps(data.value3, _mm_load_ps((const float*)&DAT_01267e30));

    data.hkMatrix4_resetFourthRow();
    ((void(__cdecl*)(int*, int))Object_HkMathUtil_decompose4x4ColTransform_Thunk)((int*)&data, count);
}

inline char hkToUpperD618(char c)
{
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}



// Converts every character in the buffer to its uppercase equivalent using hkToUpperD618.
// @fnv 0x00d618d0
void hkStringBuf::upperCase()
{
    for (int i = 0; i < getLength(); i++)
    {
        m_string.m_data[i] = hkToUpperD618(m_string.m_data[i]);
    }
}

extern "C" LocalM128 _mm_load_ps(const float*);
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

// Transforms four src vectors by the rows at ctx->m_pM1 into dest->m_row and four more by ctx->m_pM2 into out, adding the fourth row of each as an offset.
// @fnv 0x00d6c240
// src: GUESS 0x00d6c240 (confidence: medium)
static __declspec(noinline) void Object_TransformVectorBundles(TransformPair* dest, const LocalM128* src, const TransformContext* ctx,
                                              LocalM128* out)
{
    const LocalM128* pMatrix = ctx->m_pM1;
    LocalM128 a = pMatrix[0];
    LocalM128 b = pMatrix[1];
    LocalM128 c = pMatrix[2];
    for (int n = 3; n >= 0; --n)
    {
        LocalM128 v = src[n + 1];
        LocalM128 r = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(src[n + 1].m128_f32), _mm_load_ps(src[n + 1].m128_f32), 0), a),
            _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b));
        dest->m_row[n] = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c));
    }
    dest->m_row[3] = _mm_add_ps(dest->m_row[3], pMatrix[3]);

    pMatrix = ctx->m_pM2;
    a = pMatrix[0];
    b = pMatrix[1];
    c = pMatrix[2];
    for (int n = 3; n >= 0; --n)
    {
        LocalM128 v = src[n + 5];
        LocalM128 r = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(src[n + 5].m128_f32), _mm_load_ps(src[n + 5].m128_f32), 0), a),
            _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b));
        out[n] = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c));
    }
    out[3] = _mm_add_ps(out[3], pMatrix[3]);
}

TransformPair* volatile inputDest;
const LocalM128* volatile inputSource;
const TransformContext* volatile inputContext;
LocalM128* volatile inputOut;
void invokeTransform()
{
    Object_TransformVectorBundles(inputDest, inputSource, inputContext, inputOut);
}

inline void SetTransformedPositionC320(QuadDirection& output, const RigidTransform& frame, const QuadDirection& input)
{
    const LocalM128 v = input.value;
    LocalM128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), frame.orientation.column(1).value);
    LocalM128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), frame.orientation.column(0).value);
    LocalM128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), frame.orientation.column(2).value);
    output.value = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, frame.translation.value));
}

struct PivotsC320
{
    QuadDirection m_unk00;
    QuadDirection m_kPivotA;
    QuadDirection m_kPivotB;
};

struct TransformOutputC320
{
    RigidTransform* p;
    TransformOutputC320(RigidTransform* value) : p(value)
    {}
};

// Applies the rigid transforms of two bodies to their respective pivot points, writing the resulting translations into the output transforms.
// @fnv 0x00d6c320
// src: GUESS 0x00d6c320 (confidence: medium)
static __declspec(noinline) void __cdecl Object_TransformBodyPivots(const PivotsC320* pivots, const ConstraintQuery* bodies,
                                                      TransformOutputC320 outA, TransformOutputC320 outB)
{
    SetTransformedPositionC320(outA.p->translation, *bodies->transformA.get(), pivots->m_kPivotA);
    SetTransformedPositionC320(outB.p->translation, *bodies->transformB.get(), pivots->m_kPivotB);
}

const ConstraintQuery* volatile bodiesSourceC320;
const PivotsC320* volatile pivotsSourceC320;
RigidTransform* volatile outASourceC320;
RigidTransform* volatile outBSourceC320;
void InvokeTransformC320()
{
    const ConstraintQuery* bodies = bodiesSourceC320;
    const PivotsC320* pivots = pivotsSourceC320;
    RigidTransform* a = outASourceC320;
    RigidTransform* b = outBSourceC320;
    Object_TransformBodyPivots(pivots, bodies, a, b);
}
