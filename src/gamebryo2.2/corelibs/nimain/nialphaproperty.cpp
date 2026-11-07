// gamebryo2.2/corelibs/nimain/nialphaproperty.cpp: NiAlphaProperty (12 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiAlphaProperty.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

// The shared declaration does not expose the stream position or callbacks.
template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int size = sizeof(T);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) +=
        (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(this, &value, sizeof(T), &size, 1);
}
// The shared stream declaration keeps its fields opaque.
inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

inline unsigned short NiStream::savedFlags()
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x288);
}

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}
// @fnv 0x00a5cf90
void NiAlphaProperty::LoadBinary(NiStream& stream)
{
    NiProperty::LoadBinary(stream);
    if (stream.GetFileVersion() < 0x0a000102)
    {
        m_usAlphaArg = stream.savedFlags() & 0x3fff;
    }
    else
    {
        stream.Istr().Read(m_usAlphaArg);
    }
    stream.Istr().Read(m_ucAlphaArg2);
}

struct EqBase
{
    bool NiSequenceStreamHelper_IsEqual(NiObject*);
};
// @fnv 0x00a5cb10
unsigned char __fastcall IsAlphaPropertyEqual(NiAlphaProperty* self, int, NiObject* pkObject)
{
    NiAlphaProperty* pkAlpha = reinterpret_cast<NiAlphaProperty*>(pkObject);
    return reinterpret_cast<EqBase*>(self)->NiSequenceStreamHelper_IsEqual(pkObject) &&
           ((unsigned char)pkAlpha->m_usAlphaArg & 1) == ((unsigned char)self->m_usAlphaArg & 1) &&
           (self->m_usAlphaArg & 0x1e) == (pkAlpha->m_usAlphaArg & 0x1e) &&
           (self->m_usAlphaArg & 0x1e0) == (pkAlpha->m_usAlphaArg & 0x1e0) &&
           ((unsigned char)(self->m_usAlphaArg >> 9) & 1) == ((unsigned char)(pkAlpha->m_usAlphaArg >> 9) & 1) &&
           (self->m_usAlphaArg & 0x1c00) == (pkAlpha->m_usAlphaArg & 0x1c00) &&
           self->m_ucAlphaArg2 == pkAlpha->m_ucAlphaArg2 &&
           ((unsigned char)(self->m_usAlphaArg >> 13) & 1) == ((unsigned char)(pkAlpha->m_usAlphaArg >> 13) & 1);
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObj
{
    virtual void Destroy();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
extern RefObj* DAT_011f4410;
// If the global RefObj pointer is set, decrements its reference count and clears the pointer.
// @fnv 0x00a5cf60
// src: COMMUNITY 0x00a5cf60
void NiAlphaProperty__SDMShutdown()
{
    if (DAT_011f4410)
    {
        DAT_011f4410->DecRefCount();
        DAT_011f4410 = 0;
    }
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
void* _NiMalloc(unsigned int);
void* _fnv_zlib_memset(void*, int, unsigned int);
struct SdmBase
{
    unsigned int m_uiValueCount;
    void* m_data;
    int m_uiX;
    __forceinline SdmBase(unsigned int n) : m_uiValueCount(n), m_uiX(0)
    {
        m_data = _NiMalloc(0x94);
        _fnv_zlib_memset(m_data, 0, m_uiValueCount * 4);
    }
    virtual ~SdmBase()
    {}
    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct SdmDerived : SdmBase
{
    __forceinline SdmDerived() : SdmBase(0x25)
    {}
    virtual ~SdmDerived()
    {}
};
extern SdmBase* DAT_011f5e34;
extern bool DAT_011f5d30;
// Allocates 0x10 bytes, constructs an SdmDerived in place, stores it in DAT_011f5e34 and clears DAT_011f5d30.
// @fnv 0x00a8fa50
void CreateSdmDerived()
{
    void* pStorage = g_memoryManager.Allocate(0x10);
    if (pStorage)
    {
        SdmDerived* p = new (pStorage) SdmDerived();
        DAT_011f5e34 = p;
        DAT_011f5d30 = false;
        return;
    }
    DAT_011f5e34 = 0;
    DAT_011f5d30 = false;
}

struct NiPropertyCtorStub
{
    void NiDitherProperty_CreateObject();
};
extern unsigned char vftable_NiAlphaProperty[];
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

// Allocates a 0x1c-byte NiAlphaProperty, initialises its vtable and flags, and stores it in DAT_011f4410 with reference counting.
// @fnv 0x00a5cef0
// src: XBOX_PDB 0x00a5cef0
void NiAlphaProperty__SDMInit()
{
    char* pAlphaProperty = (char*)BSFadeNode::operator new(0x1c);
    if (pAlphaProperty)
    {
        ((NiPropertyCtorStub*)pAlphaProperty)->NiDitherProperty_CreateObject();
        unsigned short usFlags = 0xec;
        *(const void**)pAlphaProperty = vftable_NiAlphaProperty;
        *(unsigned short*)(pAlphaProperty + 0x18) = usFlags;
        pAlphaProperty[0x1a] = 0;
    }
    else
    {
        pAlphaProperty = 0;
    }

    if (DAT_011f4410 != (RefObj*)pAlphaProperty)
    {
        if (DAT_011f4410)
            DAT_011f4410->DecRefCount();
        DAT_011f4410 = (RefObj*)pAlphaProperty;
        if (pAlphaProperty)
            InterlockedIncrement(&((RefObj*)pAlphaProperty)->m_uiRefCount);
    }
}

// @fnv 0x00a5ceb0
NiAlphaProperty* __cdecl CreateNiAlphaProperty()
{
    NiAlphaProperty* p = (NiAlphaProperty*)BSFadeNode::operator new(0x1c);
    if (p)
    {
        ((NiPropertyCtorStub*)p)->NiDitherProperty_CreateObject();
        p->m_usAlphaArg = 0xec;
        *(void**)p = vftable_NiAlphaProperty;
        *((unsigned char*)p + 0x1a) = 0;
        return p;
    }
    return 0;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
{
    unsigned int written =
        (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 0xc))(this, p, n, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += written;
    return written;
}

template <class T>
inline void NiBinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A5D020SaveBinary(NiStream& kStream, const T& value)
{
    NiBinaryStreamSave(*kStream.GetBinaryStream(), &value);
}

class A5D020Base
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    void NiSequenceStreamHelper_SaveBinary(NiStream& kStream);
};

// The shared header does not declare the alpha SaveBinary override.
// @fnv 0x00a5d020
void __fastcall SaveAlphaPropertyBinary(NiAlphaProperty* self, int, NiStream& kStream)
{
    reinterpret_cast<A5D020Base*>(self)->NiSequenceStreamHelper_SaveBinary(kStream);
    A5D020SaveBinary(kStream, self->m_usAlphaArg);
    A5D020SaveBinary(kStream, self->m_ucAlphaArg2);
}

struct GlobalObjectO2_00a7b610
{
    const char* m_name;
};
extern GlobalObjectO2_00a7b610 g_011f4408;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString(const char*, bool);
char* __cdecl NiGetViewerString_00a7d410(const char*, unsigned char);
char* __cdecl GetAlphaBlendFuncName(const char*, unsigned int);
char* __cdecl FormatTestCondition(const char*, unsigned int);

inline unsigned int StrArr::AddInline(char* pcElement)
{
    unsigned int uiAlloced = m_usSize;
    unsigned int uiMaxSize = m_usMaxSize;
    if (uiAlloced >= uiMaxSize)
    {
        SetSize(uiAlloced + m_usGrowBy);
    }
    SetAt(uiAlloced, pcElement);
    return uiAlloced;
}

class FUN_00a62a40_this : public A5D020Base
{
  public:
    void AppendString(StrArr* pkStrings);
};

inline bool GetAlphaBlending(const NiAlphaProperty* self)
{
    return (self->m_usAlphaArg & 1) != 0;
}
inline unsigned int GetSrcBlend(const NiAlphaProperty* self)
{
    return (self->m_usAlphaArg >> 1) & 0xF;
}
inline unsigned int GetDestBlend(const NiAlphaProperty* self)
{
    return (self->m_usAlphaArg >> 5) & 0xF;
}
inline bool GetAlphaTesting(const NiAlphaProperty* self)
{
    return (self->m_usAlphaArg >> 9) & 1;
}
inline unsigned int GetTestMode(const NiAlphaProperty* self)
{
    return (self->m_usAlphaArg >> 10) & 7;
}
inline unsigned char GetTestRef(const NiAlphaProperty* self)
{
    return self->m_ucAlphaArg2;
}
inline bool GetNoSorter(const NiAlphaProperty* self)
{
    return (self->m_usAlphaArg >> 13) & 1;
}

// The shared header does not declare the alpha viewer-string override.
// @fnv 0x00a5d080
void __fastcall AppendAlphaPropertyStrings(NiAlphaProperty* self, int, StrArr* pkStrings)
{
    reinterpret_cast<FUN_00a62a40_this*>(self)->AppendString(pkStrings);
    pkStrings->AddInline(NiViewerStrings_NiGetViewerString_Title(g_011f4408.m_name));
    pkStrings->AddInline(NiGetViewerString("m_bAlpha", GetAlphaBlending(self)));
    pkStrings->AddInline(GetAlphaBlendFuncName("m_eSrcBlend", GetSrcBlend(self)));
    pkStrings->AddInline(GetAlphaBlendFuncName("m_eDestBlend", GetDestBlend(self)));
    pkStrings->AddInline(NiGetViewerString("m_bAlphaTest", GetAlphaTesting(self)));
    pkStrings->AddInline(FormatTestCondition("m_eTestMode", GetTestMode(self)));
    pkStrings->AddInline(NiGetViewerString_00a7d410("m_ucTestRef", GetTestRef(self)));
    pkStrings->AddInline(NiGetViewerString("m_bNoSorter", GetNoSorter(self)));
}

void __cdecl NiSequenceStreamHelper_RegisterStreamables();

// @fnv 0x00a99e40
// src: XBOX_PDB 0x00a99e40
void __cdecl NiAlphaProperty_RegisterStreamables()
{
    NiSequenceStreamHelper_RegisterStreamables();
}

extern char DAT_011f4404;
extern int DAT_010162dc;
void* __cdecl Object_DispatchCommandFour(unsigned int size);

// Base helpers not exposed by the shared NiProperty declaration.
struct NiPropertyCloneStub
{
    void FUN_00a5c200();
    void NiProperty_CopyMembers(NiAlphaProperty* dst, int proc);
};
void __stdcall CreateVertexBufferSet(NiAlphaProperty* self, int proc);

// The shared header does not declare the alpha clone override.
// @fnv 0x00a5ce30
NiAlphaProperty* __fastcall CloneAlphaProperty(NiAlphaProperty* self, int, int a0)
{
    if (self->m_spControllers == 0 && DAT_011f4404 == 0)
    {
        CreateVertexBufferSet(self, a0);
        return self;
    }
    NiAlphaProperty* n = (NiAlphaProperty*)Object_DispatchCommandFour(0x1c);
    if (n)
    {
        reinterpret_cast<NiPropertyCloneStub*>(n)->FUN_00a5c200();
        *(int**)n = &DAT_010162dc;
        n->m_usAlphaArg = 0xec;
        n->m_ucAlphaArg2 = 0;
    }
    else
    {
        n = 0;
    }
    reinterpret_cast<NiPropertyCloneStub*>(self)->NiProperty_CopyMembers(n, a0);
    n->m_usAlphaArg = self->m_usAlphaArg;
    n->m_ucAlphaArg2 = self->m_ucAlphaArg2;
    return n;
}

#include <string.h>
int _NiSprintf(char*, unsigned int, const char*, ...);

// Allocates a string and formats it as "pcPrefix = ALPHA_..." based on the eFunc index, returning the new string.
// @fnv 0x00a5cb90
char* GetAlphaBlendFuncName(const char* pcPrefix, int aiFuncIndex)
{
    char* pcString;
    unsigned int uiPrefixLen = (unsigned int)strlen(pcPrefix);

    pcString = (char*)_NiMalloc(uiPrefixLen + 0x16);

    switch (aiFuncIndex)
    {
    case 0:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_ONE", pcPrefix);
        break;
    case 1:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_ZERO", pcPrefix);
        break;
    case 2:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_SRCCOLOR", pcPrefix);
        break;
    case 3:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_INVSRCCOLOR", pcPrefix);
        break;
    case 4:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_DESTCOLOR", pcPrefix);
        break;
    case 5:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_INVDESTCOLOR", pcPrefix);
        break;
    case 6:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_SRCALPHA", pcPrefix);
        break;
    case 7:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_INVSRCALPHA", pcPrefix);
        break;
    case 8:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_DESTALPHA", pcPrefix);
        break;
    case 9:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_INVDESTALPHA", pcPrefix);
        break;
    case 10:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_SRCALPHASAT", pcPrefix);
        break;
    default:
        _NiSprintf(pcString, uiPrefixLen + 0x16, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }

    return pcString;
}

int __cdecl _NiSprintf(char* buffer, unsigned int size, const char* format, ...);

// Allocates a buffer and formats a string like "name = TEST_LESS" based on the test code, returning the buffer.
// @fnv 0x00a5cd00
char* FormatTestCondition(const char* name, int test)
{
    unsigned int length = (unsigned int)strlen(name);
    unsigned int size = length + 0x16;
    char* buffer = (char*)_NiMalloc(size);

    switch (test)
    {
    case 0:
        _NiSprintf(buffer, size, "%s = TEST_ALWAYS", name);
        break;
    case 1:
        _NiSprintf(buffer, size, "%s = TEST_LESS", name);
        break;
    case 2:
        _NiSprintf(buffer, size, "%s = TEST_EQUAL", name);
        break;
    case 3:
        _NiSprintf(buffer, size, "%s = TEST_LESSEQUAL", name);
        break;
    case 4:
        _NiSprintf(buffer, size, "%s = TEST_GREATER", name);
        break;
    case 5:
        _NiSprintf(buffer, size, "%s = TEST_NOTEQUAL", name);
        break;
    case 6:
        _NiSprintf(buffer, size, "%s = TEST_GREATEREQUAL", name);
        break;
    case 7:
        _NiSprintf(buffer, size, "%s = TEST_NEVER", name);
        break;
    default:
        _NiSprintf(buffer, size, "%s = UNKNOWN!!!", name);
        break;
    }

    return buffer;
}
