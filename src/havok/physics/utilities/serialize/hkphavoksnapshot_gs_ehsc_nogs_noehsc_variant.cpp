#include "../../../../../include/hkBool.h"

// src/havok/physics/utilities/serialize/hkphavoksnapshot_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkphavoksnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct CallbackInterface
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void notify(void*, unsigned short);
};
struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    CallbackInterface* interface10;
};
State* __cdecl hkMemoryRouter_getInstance();
struct Object
{
    void* unk00;
    unsigned short unk04;
    void ProcessEntries_00cc0ae0();
    Object* FUN_00cc0dd0(unsigned int flags);
};
struct D481D0StringPtr
{
    const char* m_pcText;

    D481D0StringPtr();
    void operator=(const char* s);
};
struct D481D0Class
{
    const char* getName() const;
};
struct D481D0ReferencedObject;
struct D481D0RefVariant
{
    D481D0ReferencedObject* m_ptr;

    D481D0RefVariant() : m_ptr(0)
    {}
    void set(D481D0ReferencedObject* obj, const D481D0Class* pClassInfo);
    const D481D0Class* GetVariantValue() const;
};
struct FUN_00d481d0
{
    D481D0StringPtr m_name;
    D481D0StringPtr m_pClassName;
    D481D0RefVariant m_pReferencedResource;

    FUN_00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* pClassInfo);
};
struct CC0D30Result
{
    CC0D30Result();

    int m_iResultCode;
    int m_data;
};
struct CC0D30Registry
{
    int unk00;
};
extern CC0D30Registry g_CC0D30DefaultRegistry;
CC0D30Result __cdecl hkpHavokSnapshot_saveUnderRootLevel(const void* data, const CC0D30Registry& registry, const void* pClassInfo, void* out,
                                  int flags);
CC0D30Result __cdecl hkpHavokSnapshot_save_00cc0d30(const void* data, const void* pClassInfo, void* out, int flags);
struct S_00cc0d60_A
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    void FUN_00d4c220();
    void hkpPhysicsData_populateFromWorld(void* a, int b);
    void FUN_00d4c250();
};
hkBool* hkpHavokSnapshot_save_00cc0d30(void** pa, S_00cc0d60_A* a, void* b, int c, int d);
hkBool hkpHavokSnapshot_save_00cc0d60(void* a2, void* a3, int a4, int a5, int a6);
struct Allocator
{
    virtual void* unk0();
    virtual void* allocate(unsigned int size);
};
struct PtrList;
void __cdecl ResizeAudioStream(void* a, PtrList* l, unsigned int n);
struct PtrList
{
    void** m_00;
    unsigned int m_04;
    unsigned int m_08;

    void** Add(void* o)
    {
        unsigned int i = m_04;
        void** slot = &m_00[i];
        *slot = o;
        if (slot == 0)
        {
            return 0;
        }
        m_04++;
        return slot;
    }
};
struct Obj70
{
    unsigned int unk00;
    unsigned short m_04;
    Obj70* FUN_00d4bab0(void* v);
};
struct Obj110
{
    unsigned int unk00;
    unsigned short m_04;
    Obj110* FUN_00d4aa70(void* v);
};
struct Obj80
{
    unsigned int unk00;
    unsigned short m_04;
    Obj80* FUN_00d49750(void* v);
};
struct TypeMatcher
{
    hkBool hkClass_isSuperClass(void* v);
};
struct GlobalObjectO2_00d472a0 : TypeMatcher
{
};
extern GlobalObjectO2_00d472a0 g_01268f2c;
extern GlobalObjectO2_00d472a0 g_01268e24;
extern GlobalObjectO2_00d472a0 g_01268c5c;
extern GlobalObjectO2_00d472a0 g_01268bcc;
extern GlobalObjectO2_00d472a0 g_01268eb4;
extern GlobalObjectO2_00d472a0 g_01268d4c;
extern GlobalObjectO2_00d472a0 g_01268c14;
struct FUN_00cc08f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    PtrList m_08;

    void hkpHavokSnapshot_ConvertListener_addObjectCallback(void** a1, void** a2);
};

#include <windows.h>
struct DirAllocator
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void reserved0c();
    virtual void freeBuffer(void*, int);
    template <class T> inline void freeElements(void* p, int count)
    {
        const int itemSize = sizeof(T);
        freeBuffer(p, count * itemSize);
    }
};
struct DirRouter
{
    int unk00, unk04, unk08;
    DirAllocator* temporary;
};
namespace DirectoryMemory {
DirRouter& __cdecl hkMemoryRouter_getInstance();
}
__forceinline DirAllocator& tempAllocator()
{
    return *DirectoryMemory::hkMemoryRouter_getInstance().temporary;
}
void __cdecl reserveDirectoryBuffer(DirAllocator&, void*, int, int);

template <class T> struct DirArrayBase
{
    T* data;
    int count;
    int capacityFlags;
    __forceinline DirArrayBase(T* p, int n, int capacity) : data(p), count(n), capacityFlags(capacity | 0x80000000)
    {}
    __forceinline ~DirArrayBase()
    {}
    __forceinline int capacity() const
    {
        return capacityFlags & 0x3fffffff;
    }
    __forceinline void reserve(DirAllocator& allocator, int n)
    {
        int old = capacity();
        if (old < n)
        {
            int doubled = old * 2;
            reserveDirectoryBuffer(allocator, this, n < doubled ? doubled : n, sizeof(T));
        }
    }
    __forceinline void resize(DirAllocator& allocator, int n)
    {
        reserve(allocator, n);
        count = n;
    }
    __forceinline void release(DirAllocator& allocator)
    {
        count = 0;
        if ((capacityFlags & 0x80000000) == 0)
            allocator.freeElements<T>(data, capacity());
        data = 0;
        capacityFlags = 0x80000000;
    }
};
template <class T> struct DirTempArray : DirArrayBase<T>
{
    __forceinline DirTempArray(T* p, int n, int capacity) : DirArrayBase<T>(p, n, capacity)
    {}
    __forceinline ~DirTempArray()
    {
        DirRouter* router = &DirectoryMemory::hkMemoryRouter_getInstance();
        DirAllocator* allocator = router->temporary;
        this->count = 0;
        if ((this->capacityFlags & 0x80000000) == 0)
            allocator->freeBuffer(this->data, this->capacityFlags & 0x3fffffff);
        this->data = 0;
        this->capacityFlags = 0x80000000;
    }
    __forceinline void resize(int n)
    {
        DirArrayBase<T>::resize(tempAllocator(), n);
    }
};
template <class T, unsigned N> struct DirInlineArray : DirTempArray<T>
{
    T storage[N];
    __forceinline DirInlineArray() : DirTempArray<T>(storage, 0, N)
    {}
    __forceinline ~DirInlineArray()
    {}
};
struct DirectoryString
{
    DirInlineArray<char, 128> chars;
    __forceinline ~DirectoryString()
    {}
    int ReplaceChar(char, char, int);
    int EndsWith(const char*) const;
    DirectoryString& FUN_00d61df0(const char*);
    inline int length() const
    {
        return chars.count - 1;
    }
    inline const char* text() const
    {
        return chars.data;
    }
    inline operator const char*() const
    {
        return chars.data;
    }
    inline void setLength(int n)
    {
        chars.resize(n + 1);
        chars.data[n] = 0;
    }
};

struct InitBuffer : DirectoryString
{
    __forceinline ~InitBuffer()
    {}
    InitBuffer()
    {
        setLength(0);
        chars.data[0] = 0;
    }
};
struct FUN_00d61a50 : DirectoryString
{
    __forceinline ~FUN_00d61a50()
    {}
    FUN_00d61a50(const char*);
};

struct DirectoryFlags
{
    unsigned bits;
    inline DirectoryFlags()
    {}
    inline DirectoryFlags(unsigned b) : bits(b)
    {}
};
struct DirectoryItem
{
    const char* name;
    unsigned modified;
    DirectoryFlags flags;
};
void __cdecl ResizeAudioStream(DirAllocator&, void*, int);
int __cdecl hkString_strCmp(const char*, const char*);
char* __cdecl hkString_strDup(const char*, DirAllocator&);
struct DirectoryArray
{
    DirectoryItem* data;
    int count, capacityFlags;
    __forceinline DirectoryItem& expand(DirAllocator& allocator)
    {
        if (count == (capacityFlags & 0x3fffffff))
            ResizeAudioStream(allocator, this, sizeof(DirectoryItem));
        return data[count++];
    }
};
struct DirectoryOutput
{
    DirectoryArray entries;
    DirAllocator* allocator;
    __forceinline void add(const char* name, DirectoryFlags flags, unsigned modified = 0)
    {
        DirectoryItem& item = entries.expand(*allocator);
        item.name = hkString_strDup(name, *allocator);
        item.flags = flags;
        item.modified = modified;
    }
    __forceinline void addDirectory(const char* name)
    {
        add(name, 2);
    }
    __forceinline void addFile(const char* name, unsigned modified = 0)
    {
        add(name, 1, modified);
    }
};
typedef const char*(__cdecl* DirectoryConvert)(const char*, DirectoryString&);
extern DirectoryConvert DAT_011b3dc0;
extern const char DAT_01063cbc[], DAT_0101ffbc[], DAT_01044c28[], DAT_010a2560[];
enum DirectoryResult
{
    DirectorySuccess,
    DirectoryFailure
};

// @fnv 0x00da25a0
// src: HAVOK_LIB 0x00da25a0
DirectoryResult __cdecl hkWin32ListDirectory(const char* input, DirectoryOutput& listing)
{
    InitBuffer path;
    {
        FUN_00d61a50 normalized(input);
        if (normalized.length() > 0)
        {
            normalized.ReplaceChar('\\', '/', 1);
            if (!normalized.EndsWith(DAT_01063cbc))
                normalized.FUN_00d61df0(DAT_01063cbc);
            DAT_011b3dc0(normalized.text(), path);
        }
    }
    DWORD attrs = GetFileAttributesA(path);
    if (attrs == INVALID_FILE_ATTRIBUTES)
        return DirectoryFailure;
    bool valid = (attrs & FILE_ATTRIBUTE_DIRECTORY) != 0;
    if (!valid)
        return DirectoryFailure;
    if (path.length())
        path.FUN_00d61df0(DAT_0101ffbc);
    WIN32_FIND_DATAA found;
    HANDLE handle = FindFirstFileA(path, &found);
    hkBool more = handle != INVALID_HANDLE_VALUE;
    while (more)
    {
        if (hkString_strCmp(found.cFileName, DAT_01044c28) && hkString_strCmp(found.cFileName, DAT_010a2560))
        {
            bool directory = (found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
            if (directory)
            {
                listing.addDirectory(found.cFileName);
            }
            else
            {
                LARGE_INTEGER epoch = {0};
                epoch.QuadPart = 0x19db1ded53e8000LL;
                __int64 seconds = (*(__int64*)&found.ftLastWriteTime - epoch.QuadPart) / 10000000;
                listing.addFile(found.cFileName, (unsigned)seconds);
            }
        }
        more = FindNextFileA(handle, &found) != 0;
    }
    FindClose(handle);
    return DirectorySuccess;
}
