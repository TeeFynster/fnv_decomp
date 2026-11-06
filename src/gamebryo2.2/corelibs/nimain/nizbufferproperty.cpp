// gamebryo2.2/corelibs/nimain/nizbufferproperty.cpp: NiAlphaAccumulator, AlphaPropInit_cls (11 functions)

#include "../../../../include/NiAlphaAccumulator.h"
#include "../../../../include/NiAlphaProperty.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"

extern unsigned int kVtbl_NiAlphaAccumulator;
// The original calls the out-of-line base initializer with this in ECX.
NiBackToFrontAccumulator* __fastcall InitializeBackToFrontAccumulator(NiBackToFrontAccumulator* self);

// @fnv 0x00a9b480
NiAlphaAccumulator* __fastcall InitializeAlphaAccumulator(NiAlphaAccumulator* self)
{
    InitializeBackToFrontAccumulator(self);
    self->m_bSortByClosestPoint = 0;
    self->m_bInterfaceSort = 0;
    *(unsigned int*)self = (unsigned int)&kVtbl_NiAlphaAccumulator;
    self->m_bObserveNoSortHint = 1;
    return self;
}

extern char const* const g_011f4454_arg1;

// @fnv 0x00a5fc80
char const* const* __cdecl FUN_00a5fc80()
{
    return &g_011f4454_arg1;
}

extern "C" void* g_011f5ecc;

// @fnv 0x00a950d0
void* __cdecl FUN_00a950d0()
{
    return &g_011f5ecc;
}

// @fnv 0x00a950e0
int __cdecl FUN_00a950e0()
{
    return 9;
}

struct FUN_00a62140_shell
{
    bool FUN_00a62140(void* other);
};

struct FUN_00a5f480_cls
{
    bool IsEquivalent(void* other);
};

// @fnv 0x00a5f480
bool FUN_00a5f480_cls::IsEquivalent(void* other)
{
    if (!reinterpret_cast<FUN_00a62140_shell*>(this)->FUN_00a62140(other))
    {
        goto fail;
    }

    unsigned char* selfFlags = reinterpret_cast<unsigned char*>(this) + 0x18;
    unsigned char* rhsFlags = reinterpret_cast<unsigned char*>(other) + 0x18;

    if (((*rhsFlags ^ *selfFlags) & 1) != 0)
    {
        goto fail;
    }

    unsigned short rhsWord = *reinterpret_cast<unsigned short*>(rhsFlags);
    unsigned short selfWord = *reinterpret_cast<unsigned short*>(selfFlags);
    unsigned char selfShift = (unsigned char)selfWord >> 1;
    unsigned char rhsShift = (unsigned char)(rhsWord >> 1);
    if (((rhsShift ^ selfShift) & 1) != 0)
    {
        goto fail;
    }

    unsigned char diffLo = (unsigned char)(rhsWord ^ selfWord);
    if ((diffLo & 0x3c) == 0)
    {
        return true;
    }
    if (1)
    {
        goto fail;
    }
    return true;

fail:
    return false;
}

class A5F510Property
{
  public:
    static void* operator new(unsigned int stSize);
    static void operator delete(void* p);

    __declspec(nothrow) A5F510Property();
    virtual void vfunc00();

    void CopyMemberData(A5F510Property* pkDest, CloningProcess& kCloning);

    int m_uiRefCount;
    int unk08;
    void* m_pkClonedTarget;
    int unk10;
    int unk14;
};

void __stdcall CreateVertexBufferSet(A5F510Property* pkObject, CloningProcess& kCloning);

class A5F510FlagProperty : public A5F510Property
{
  public:
    A5F510FlagProperty()
    {
        m_usFlags = 0xf;
    }
    virtual void vfunc00();

    A5F510Property* FUN_00a5f510(CloningProcess& kCloning);

    unsigned short m_usFlags;
};

// @fnv 0x00a5f510
A5F510Property* A5F510FlagProperty::FUN_00a5f510(CloningProcess& kCloning)
{
    if (m_pkClonedTarget)
    {
        A5F510FlagProperty* pkClone = new A5F510FlagProperty;
        CopyMemberData(pkClone, kCloning);
        pkClone->m_usFlags = m_usFlags;
        return pkClone;
    }
    CreateVertexBufferSet(this, kCloning);
    return this;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int uiSize = sizeof(T);
    BinaryRead(&value, sizeof(T), &uiSize, 1);
}

struct FUN_00a5f580_Obj
{
    char pad0[0x18];
    unsigned short m_usValue;

    void FUN_00a5d7f0(NiStream* pkStream);
    void ReadValue(NiStream* pkStream);
};

// @fnv 0x00a5f580
void FUN_00a5f580_Obj::ReadValue(NiStream* pkStream)
{
    FUN_00a5d7f0(pkStream);
    if (pkStream->m_uiNifFileVersion < 0xa000102)
    {
        m_usValue = pkStream->m_usNiPropertyFlags & 3;
    }
    else
    {
        pkStream->m_pkIstr->Read(m_usValue);
    }
    if (pkStream->m_uiNifFileVersion >= 0x4010005 && pkStream->m_uiNifFileVersion < 0x14010002)
    {
        unsigned int uiVal;
        pkStream->m_pkIstr->Read(uiVal);
        m_usValue = (unsigned short)((m_usValue & 0xffc3) | (uiVal * 4));
    }
}

extern unsigned int kVtbl_0109b944;
extern unsigned int kVtbl_0109b9ec;
extern void* g_0109b220;

class AlphaPropInit_cls
{
  public:
    void* m_pVtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    volatile int m_18;
    volatile int m_1c;
    volatile int m_20;
    volatile int m_24;
    int unk28;
    int unk2c;
    void* volatile m_30;
    void* volatile m_34;
    volatile int m_38;
    volatile int m_3c;
    volatile unsigned char m_40;
    volatile unsigned char m_41;
    volatile unsigned char m_42;
    volatile unsigned char m_43;
    volatile int m_44;
    void FUN_00a5c200();
    void FUN_00a5f7b0();
    AlphaPropInit_cls* FUN_00a5fc10();
};

// @fnv 0x00a5fc10
AlphaPropInit_cls* AlphaPropInit_cls::FUN_00a5fc10()
{
    FUN_00a5c200();
    m_pVtbl = &kVtbl_0109b944;
    m_18 = 6;
    m_1c = 3;
    m_20 = 2;
    int zero = 0;
    int* p24 = (int*)&m_24;
    *p24 = zero;
    FUN_00a5f7b0();
    m_pVtbl = &kVtbl_0109b9ec;
    m_30 = g_0109b220;
    m_34 = g_0109b220;
    m_38 = zero;
    m_3c = zero;
    m_40 = 1;
    m_41 = 1;
    m_42 = 0;
    m_43 = 0;
    m_44 = zero;
    return this;
}

struct S_00a5f640_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short count;
    unsigned short grow;
    void __thiscall FUN_0096ad30(unsigned int n);
    void __thiscall FUN_0096ae90(unsigned int i, char* const& e);
    void Add(char* const& e)
    {
        unsigned int i = esize;
        if (i >= size)
            FUN_0096ad30(i + grow);
        FUN_0096ae90(i, e);
    }
};
struct S_00a5f640_Flags
{
    unsigned short a : 1;
    unsigned short b : 1;
    unsigned short c : 4;
};
struct S_00a5f640_B
{
    bool v;
    S_00a5f640_B(bool x)
    {
        v = x;
    }
};
extern char* DAT_011f443c;
struct Property284
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void AppendString(S_00a5f640_Arr* a);
};
char* __cdecl FUN_00a7d330(char* s);
char* __cdecl FUN_00a7d370(const char* fmt, S_00a5f640_B v);
char* __cdecl FUN_00a7d5e0(const char* fmt, const char* v);
struct S_00a5f640_Obj : Property284
{
    S_00a5f640_Flags f;
    void AppendRenderStateProperties(S_00a5f640_Arr* arr);
};
// Appends the base properties, m_bZTest, m_bZWrite and the Test Function name selected from the f.c index to arr.
// @fnv 0x00a5f640
void S_00a5f640_Obj::AppendRenderStateProperties(S_00a5f640_Arr* arr)
{
    AppendString(arr);
    arr->Add(FUN_00a7d330(DAT_011f443c));
    arr->Add(FUN_00a7d370("m_bZTest", S_00a5f640_B(f.a)));
    arr->Add(FUN_00a7d370("m_bZWrite", S_00a5f640_B(f.b)));
    unsigned uiTestFunc = f.c;
    const char* names[8] = {"TEST_ALWAYS",  "TEST_LESS",     "TEST_EQUAL",        "TEST_LESSEQUAL",
                            "TEST_GREATER", "TEST_NOTEQUAL", "TEST_GREATEREQUAL", "TEST_NEVER"};
    arr->Add(FUN_00a7d5e0("Test Function", names[uiTestFunc]));
}

struct FnvCpu_FUN_00a5fc90_CpuObject
{
    char* FUN_00a5fc90();
};
// @fnv 0x00a5fc90
char* FnvCpu_FUN_00a5fc90_CpuObject::FUN_00a5fc90()
{
    return reinterpret_cast<char*>(this) + 48;
}

extern void FUN_00a47360();

// @fnv 0x00a950c0
void FUN_00a950c0()
{
    FUN_00a47360();
}
