#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiStandardAllocator.h"
#include "../../../../include/NiFile.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiGPUProgramCache.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiObjPtr.h"
#include "../../../../include/NiTFixedStringMap_NiAVObject___.h"

// src/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* DAT_11ac230;
// @fnv 0x00aa1ab0
// src: XBOX_PDB 0x00aa1ab0
void __cdecl NiFile_DirectoryExists()
{
    ((void (*)())DAT_11ac230)();
}

// @fnv 0x00a8d8b0
void __cdecl AdvancePosition(NiBinaryStream* apState, void* b, unsigned int c)
{
    unsigned int tmp = 1;
    *(int*)((char*)apState + 4) += (*(NiBinaryStream::ReadFunction*)((char*)apState + 8))(apState, b, c, &tmp, 1);
}

void _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
extern int DAT_01101378;
extern int DAT_01101388;
struct SomeClass
{
    void* FUN_00ee90b0(unsigned int);
};
// @fnv 0x00ee90b0
void* SomeClass::FUN_00ee90b0(unsigned int uiFlags)
{
    *(int*)this = (int)&DAT_01101388;
    ((NiTFixedStringMap_NiAVObject___*)this)->RemoveAll();
    *(int*)this = (int)&DAT_01101378;
    ((NiTFixedStringMap_NiAVObject___*)this)->RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
    if (uiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

void __cdecl FUN_00ee9a60();
void __cdecl operator delete(void*, unsigned int);
struct FUN_00ee9ca0_shell
{
    void* __thiscall FUN_00ee9ca0(unsigned int flags);
};
// @fnv 0x00ee9ca0
void* __thiscall FUN_00ee9ca0_shell::FUN_00ee9ca0(unsigned int flags)
{
    FUN_00ee9a60();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}

// @fnv 0x00ee8e70
bool __thiscall NiGPUProgramCache::vf28()
{
    m_kObjectMap.RemoveAll();
    m_bLoadComplete = false;
    return true;
}

void __cdecl NiFreeAlias(void*);
// Sets the vtable, removes all entries, frees the table, and optionally deallocates this instance.
// @fnv 0x00ee9070
void* NiTFixedStringMap_NiAVObject___::Destroy(int b)
{
    *(void**)this = &DAT_01101378;
    RemoveAll();
    NiFreeAlias(*(void**)((char*)this + 8));
    if (b & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

void* __cdecl NiStandardAllocator::operator new(unsigned int n)
{
    return g_memoryManager.Game_DoHeapAlloc(n);
}
struct FUN_00aa2200
{
    NiStandardAllocator* object;
    unsigned char initialized;
    FUN_00aa2200();
};
// Allocates a NiStandardAllocator via operator new and stores it in object, then sets initialized to 1.
// @fnv 0x00aa2200
FUN_00aa2200::FUN_00aa2200()
{
    object = new NiStandardAllocator;
    initialized = 1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char* _EmptyFS;

inline NiFixedString& NiFixedString::operator=(const NiFixedString& s)
{
    if (m_kHandle != s.m_kHandle)
    {
        char* h = s.m_kHandle;
        if (h != _EmptyFS)
            InterlockedIncrement((long*)(h - 8));
        if (m_kHandle != _EmptyFS)
            InterlockedDecrement((long*)(m_kHandle - 8));
        m_kHandle = h;
    }
    return *this;
}
inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

inline NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
    InterlockedIncrement((long*)&ms_lObjectCount);
}
inline NiRefObject::~NiRefObject()
{
    InterlockedDecrement((long*)&ms_lObjectCount);
}
inline bool NiFixedString::Exists() const
{
    return m_kHandle != _EmptyFS;
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

inline NiObjPtr& NiObjPtr::operator=(const NiObjPtr& p)
{
    if (m_pObject != p.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = p.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

struct MapItem
{
    MapItem* m_pkNext;
    NiFixedString m_key;
    NiObjPtr m_val;
};

// Retained: the shared map lacks hash-table fields and smart-pointer iteration.
class FixedStringMap
{
  public:
    virtual ~FixedStringMap();
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;

    void GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val);
};

// Reads the current item's key and value into key and val, advances pos to the next item or the next non-empty hash bucket, or sets pos to 0 at the end.
// @fnv 0x00ee8f10
void FixedStringMap::GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val)
{
    MapItem* pkItem = pos;
    key = pkItem->m_key;
    val = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        pos = pkItem->m_pkNext;
        return;
    }
    unsigned int i = (unsigned int)pkItem->m_key.m_kHandle % m_uiHashSize;
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

bool __cdecl Path_IsRelative(const char*) throw();
bool __cdecl NiPath_GetCurrentWorkingDirectory(char*, unsigned int) throw();
int __cdecl BuildAbsolutePath(char*, unsigned int, const char*, const char*) throw();

// @fnv 0x00ee8af0
bool NiGPUProgramCache::SetString(const NiFixedString& akString) throw()
{
    NiFixedString kOld = this->m_pcWorkingDir;

    if (akString.m_kHandle != _EmptyFS && Path_IsRelative(akString.m_kHandle))
    {
        char acDir[260];
        if (NiPath_GetCurrentWorkingDirectory(acDir, 260))
        {
            const char* pcHandle = akString.m_kHandle;
            char acFullPath[260];
            if (BuildAbsolutePath(acFullPath, 260, pcHandle, acDir))
            {
                this->m_pcWorkingDir = static_cast<const char*>(acFullPath);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        this->m_pcWorkingDir = akString;
    }

    if (kOld.m_kHandle != this->m_pcWorkingDir.m_kHandle)
    {
        this->UpdatePathString();
    }
    return true;
}

// helpers of the game (declared only)
void __cdecl BuildAbsolutePath(char* buffer, unsigned int size, char* a, char* b);
char* __cdecl FUN_00a5b690(char* str);

// Rebuilds the cache filename from the platform and working directory, clearing the load flag when either is empty.
// @fnv 0x00ee8c10
void NiGPUProgramCache::UpdatePathString() throw()
{
    if (m_pcWorkingDir.m_kHandle != _EmptyFS && m_18.m_kHandle != _EmptyFS)
    {
        if (m_pcCacheFileName.m_kHandle != _EmptyFS)
            InterlockedIncrement((long*)(m_pcCacheFileName.m_kHandle - 8));

        char buffer[0x104];
        char* old = m_pcCacheFileName.m_kHandle;
        BuildAbsolutePath(buffer, 0x104, m_18.m_kHandle, m_pcWorkingDir.m_kHandle);

        char* rel = m_pcCacheFileName.m_kHandle;
        if (rel != buffer)
        {
            m_pcCacheFileName.m_kHandle = FUN_00a5b690(buffer);
            if (rel != _EmptyFS)
                InterlockedDecrement((long*)(rel - 8));
        }
        if (old != m_pcCacheFileName.m_kHandle)
            vf28();
        if (old != _EmptyFS)
            InterlockedDecrement((long*)(old - 8));
    }
    else
    {
        char* cur = m_pcCacheFileName.m_kHandle;
        if (cur != 0)
        {
            m_pcCacheFileName.m_kHandle = FUN_00a5b690(0);
            if (cur != _EmptyFS)
                InterlockedDecrement((long*)(cur - 8));
        }
        m_bLoadComplete = 0;
    }
}

namespace fnv_00ee8e10 {
char* __cdecl FUN_00a5b690(const char* s);
struct S_00ee8e10_Arr
{
    char** data;
    unsigned int count;
    int size;
    void NiTPtrSet_NiFixedString_NiTNewInterface_NiFixedString_RemoveAll();
};
// Releases each stored string pointer, decrementing its reference count when non-null and not the empty-string sentinel, then resets size to 0.
// @fnv 0x00ee8e10
// src: XBOX_PDB 0x00ee8e10
void S_00ee8e10_Arr::NiTPtrSet_NiFixedString_NiTNewInterface_NiFixedString_RemoveAll()
{
    for (unsigned int i = 0; i < count; i++)
    {
        char*& e = data[i];
        char* h = e;
        if (h)
        {
            e = FUN_00a5b690(0);
            if (h != _EmptyFS)
                InterlockedDecrement((long*)(h - 8));
        }
    }
    size = 0;
}
}  // namespace fnv_00ee8e10

class FUN_00ee8fe0_cls
{
  public:
    NiRefObject** m_ppkTable;
    unsigned int unk04;
    unsigned int m_uiSize;

    void RemoveAt(unsigned int idx);
};

// Removes the element at idx by shifting later slots down with refcount updates, then decrements m_uiSize and releases the last slot.
// @fnv 0x00ee8fe0
void FUN_00ee8fe0_cls::RemoveAt(unsigned int uiIndex)
{
    if (uiIndex < m_uiSize - 1)
    {
        do
        {
            NiRefObject** slot = &m_ppkTable[uiIndex];
            NiRefObject* cur = *slot;
            if (cur != slot[1])
            {
                if (cur)
                {
                    cur->DecRefCount();
                }
                *slot = slot[1];
                if (*slot)
                {
                    (*slot)->IncRefCount();
                }
            }
            uiIndex++;
        } while (uiIndex < m_uiSize - 1);
    }
    m_uiSize--;
    NiRefObject** ppLastSlot = &m_ppkTable[m_uiSize];
    NiRefObject* last = *ppLastSlot;
    if (last)
    {
        last->DecRefCount();
        *ppLastSlot = 0;
    }
}

extern void* DAT_11ac230;
void __cdecl NiFile_DirectoryExists();

void __cdecl AdvancePosition(NiBinaryStream* a, void* b, unsigned int c);

// Reads a length-prefixed string and advances the stream position; returns false for a zero size or null buffer.
// @fnv 0x00ee92d0
// src: GAMEBRYO_LIB 0x00ee92d0
bool __stdcall NiGPUProgramCache_LoadStringA(NiBinaryStream* self, unsigned int pBuffer, unsigned int a3)
{
    if (a3 == 0)
        goto fail;
    char* out = (char*)pBuffer;
    if (out != 0)
    {
        unsigned int* pLength = &a3;
        *pLength = 0;
        unsigned int* pReadSize = &pBuffer;
        *pReadSize = 4;
        unsigned int n = (*(NiBinaryStream::ReadFunction*)((char*)self + 8))(self, pLength, 4, pReadSize, 1);
        *(int*)((char*)self + 4) += (int)n;
        unsigned int v = *pLength;
        if (v == 0)
            goto zero;
        AdvancePosition(self, out, *pLength);
        out[*(volatile unsigned int*)pLength + 1] = 0;
        return true;
    zero:
        *out = (char)v;
        return true;
    }
fail:
    return false;
}

struct S_00ee97e0_Elem
{
    int* GetFilename_00a62660();
    int* NiMaterialResource_GetSemantic();
    int* NiMaterialResource_GetLabel();
    int* NiMaterialResource_GetVariable();
    int* NiMaterialResource_GetDefaultValue();
    int NiRenderTargetGroup_GetBufferCount();
    int NiFile_GetBuffer();
    int NiRenderTargetGroup_GetRendererData();
    int NiD3DShader_GetShaderDecl();
};

struct S_00ee97e0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00ee97e0_Elem** unk0c;
    int unk10;
    unsigned int unk14;
};

__forceinline void S_00ee97e0_Write(NiFile* s, void* data)
{
    unsigned int sz = 4;
    *(unsigned int*)((char*)s + 4) += (*(NiBinaryStream::NIBINARYSTREAM_WRITEFN*)((char*)s + 0xc))(s, data, 4, &sz, 1);
}

// @fnv 0x00ee97e0
bool NiGPUProgramCache::WriteToStream(NiFile* pStream, NiRefObject* pObject, int* piValue)
{
    S_00ee97e0_Obj* pObj = reinterpret_cast<S_00ee97e0_Obj*>(pObject);
    S_00ee97e0_Write(pStream, &m_uiReserved);
    NiGPUProgramCache_SaveString(pStream, *piValue);
    int f8 = pObj->unk08;
    if (!vf90(pStream, f8))
        return false;
    unsigned int count = pObj->unk14;
    S_00ee97e0_Write(pStream, &count);
    for (unsigned int i = 0; i < count; i++)
    {
        S_00ee97e0_Elem* e = pObj->unk0c[i];
        NiGPUProgramCache_SaveString(pStream, *e->GetFilename_00a62660());
        NiGPUProgramCache_SaveString(pStream, *e->NiMaterialResource_GetSemantic());
        NiGPUProgramCache_SaveString(pStream, *e->NiMaterialResource_GetLabel());
        NiGPUProgramCache_SaveString(pStream, *e->NiMaterialResource_GetVariable());
        NiGPUProgramCache_SaveString(pStream, *e->NiMaterialResource_GetDefaultValue());
        int a = e->NiRenderTargetGroup_GetBufferCount();
        S_00ee97e0_Write(pStream, &a);
        int b = e->NiFile_GetBuffer();
        S_00ee97e0_Write(pStream, &b);
        int c = e->NiRenderTargetGroup_GetRendererData();
        S_00ee97e0_Write(pStream, &c);
        int iValD = e->NiD3DShader_GetShaderDecl();
        S_00ee97e0_Write(pStream, &iValD);
    }
    return true;
}

// CreateRecordPair - allocate a 12 byte record from the global allocator
// (DAT_011f6238) and clear its two counter fields.  When the allocation
// fails the pointer is replaced by a null pointer which is then written
// through, exactly like the original code does.

struct RecordPair
{
    unsigned int unk00;
    unsigned int m_i04;
    unsigned int m_i08;
};

extern "C" MemoryManager DAT_011f6238;

// @fnv 0x00ee99b0
RecordPair* __cdecl CreateRecordPair()
{
    RecordPair* pRecord = (RecordPair*)DAT_011f6238.Game_DoHeapAlloc(0xc);
    if (pRecord)
    {
        pRecord->m_i08 = 0;
    }
    else
    {
        pRecord = 0;
    }
    pRecord->m_i04 = 0;
    return pRecord;
}

char* __cdecl FUN_00a5b690(const char*);

__forceinline NiFixedString& AssignFixedStringIfPresent(NiFixedString& key, const char* pcString)
{
    if (key.m_kHandle)
    {
        char* pcOld = key.m_kHandle;
        key.m_kHandle = FUN_00a5b690(pcString);
        if (pcOld != _EmptyFS)
            InterlockedDecrement((long*)(pcOld - 8));
    }
    return key;
}

struct ObjPtrDtor
{
    NiRefObject* m_pObject;
    __forceinline ObjPtrDtor& operator=(NiRefObject* pNew)
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
            m_pObject = pNew;
        }
        return *this;
    }
    __forceinline ~ObjPtrDtor() throw()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
};

struct ItemWithDtor
{
    void* m_pkNext;
    NiFixedString m_key;
    ObjPtrDtor m_val;

    __forceinline ~ItemWithDtor() throw()
    {}

    void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

// Clears the item's key and value, then deletes the item through its custom operator delete.
// @fnv 0x00ee99d0
void __stdcall ClearAndDeleteItem(ItemWithDtor* pItem)
{
    AssignFixedStringIfPresent(pItem->m_key, (const char*)0);
    pItem->m_val = (NiRefObject*)0;
    delete pItem;
}

extern long DAT_011f4400;
extern char* DAT_0109b220;

void __cdecl FreeTable(void* p);
void __cdecl FreeBlock(void* p);

struct ReleaseHelper
{
    void Release();
};
struct MapClearHelper
{
    void NiTPtrSet_NiFixedString_NiTNewInterface_NiFixedString_RemoveAll();
};

class SpawnedBase
{
  public:
    virtual ~SpawnedBase() throw()
    {
        reinterpret_cast<ReleaseHelper*>(this)->Release();
        FreeBlock(m_p);
    }
    int unk04;
    void* m_p;
};

class SpawnedObject : public SpawnedBase
{
  public:
    virtual ~SpawnedObject() throw()
    {
        reinterpret_cast<ReleaseHelper*>(this)->Release();
    }
};

// Retained: the shared cache map has no destructor for its owned table.
class FUN_00ee9a60_cls : public NiRefObject
{
  public:
    virtual ~FUN_00ee9a60_cls() throw();
    SpawnedObject m_sub;
    int unk14;
    NiFixedString m_s0;
    NiFixedString m_s1;
    NiFixedString m_s2;
    NiFixedString m_s3;
    unsigned int m_mapHead;
};

// Destructor: clears the map at m_mapHead, frees its table, then releases the four NiFixedString handles and the base.
// @fnv 0x00ee9a60
FUN_00ee9a60_cls::~FUN_00ee9a60_cls() throw()
{
    reinterpret_cast<MapClearHelper*>(&m_mapHead)->NiTPtrSet_NiFixedString_NiTNewInterface_NiFixedString_RemoveAll();
    FreeTable(reinterpret_cast<void*>(m_mapHead));

}

namespace fnv_00ee9b10 {
// Reconstruction of LookupAndVisit: a fixed-string-map lookup that walks the
// value object's element array and hands every element to a visitor.
//
// The map lookup (Ee9b10_Map::Lookup) is defined here on purpose: when
// the callee is only declared, MSVC 2008 assumes it can write any memory, so
// the value pointer is reloaded from its stack slot after every call. With the
// body visible, the compiler knows the callee only writes through the
// out-parameter, and the value pointer stays in a callee-saved register.

struct Ee9b10_Value;
struct Ee9b10_Item
{
    int unk00;
};

struct Ee9b10_Map
{
    int unk00;
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    bool __declspec(noinline) Lookup(NiFixedString& key, Ee9b10_Value*& val);
};

struct Ee9b10_Visitor
{
    void FUN_00e8ea60(Ee9b10_Item** pItem);
};

struct Ee9b10_Value : public NiRefObject
{
    void* m_pFirst;
    Ee9b10_Item** m_pEntryData;
    int unk10;
    unsigned int m_uiItemCount;
};


void* __cdecl FUN_00a5b690(const char* str);

// Hash the key handle, walk the bucket chain and publish the entry that
// matches; the old value is released and the new one referenced, exactly like
// the game's map lookup does.
bool Ee9b10_Map::Lookup(NiFixedString& key, Ee9b10_Value*& val)
{
    MapItem* node = 0;
    if (m_uiHashSize != 0 && m_ppkHashTable != 0)
    {
        unsigned int slot = (unsigned int)((size_t)key.m_kHandle / m_uiHashSize);
        node = m_ppkHashTable[slot];
        while (node != 0)
        {
            if (node->m_key.m_kHandle == key.m_kHandle)
                break;
            node = node->m_pkNext;
        }
    }
    if (node == 0)
        return false;
    NiRefObject* found = node->m_val.m_pObject;
    NiRefObject* old = val;
    if (old != found)
    {
        if (old != 0)
            old->DecRefCount();
        val = (Ee9b10_Value*)found;
        if (found != 0)
            found->IncRefCount();
    }
    return true;
}

// Looks up a cached name, visits its items, and releases the temporary string and value references.
}  // namespace fnv_00ee9b10

// @fnv 0x00ee9b10
void* NiGPUProgramCache::LookupAndVisit(const char* name, void* pvVisitor)
{
    using namespace fnv_00ee9b10;
    Ee9b10_Visitor* visitor = static_cast<Ee9b10_Visitor*>(pvVisitor);
    char* h;
    if (!name)
        h = _EmptyFS;
    else
        h = (char*)fnv_00ee9b10::FUN_00a5b690(name);
    NiFixedString& key = *reinterpret_cast<NiFixedString*>(&h);
    Ee9b10_Value* val = 0;
    if (reinterpret_cast<fnv_00ee9b10::Ee9b10_Map*>(&m_kObjectMap)->Lookup(key, val))
    {
        for (unsigned int i = 0; i < val->m_uiItemCount; i++)
        {
            visitor->FUN_00e8ea60(&val->m_pEntryData[i]);
        }
        void* pResult = val->m_pFirst;
        val->DecRefCount();
        if (h != _EmptyFS)
            InterlockedDecrement((long*)(h - 8));
        return pResult;
    }
    if (val)
        val->DecRefCount();
    if (h != _EmptyFS)
        InterlockedDecrement((long*)(h - 8));
    return 0;
}

namespace fnv_00ee9bf0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long DAT_011f4400;
extern unsigned int DAT_0109b220;
void* __cdecl _NiMalloc_00aa1070(unsigned int);
void* __cdecl FUN_00ec61c0(void*, unsigned int, unsigned int);
void* __cdecl NiTNewInterface_NiFixedString_Allocate(unsigned int);

struct S_00ee9bf0_B
{
    unsigned int unk0c;
    void* unk10;
    unsigned int unk14;
    virtual void vf0();
    __forceinline S_00ee9bf0_B() throw()
    {
        unk0c = 0x25;
        unk14 = 0;
        unk10 = _NiMalloc_00aa1070(0x94);
        FUN_00ec61c0(unk10, 0, unk0c * 4);
    }
};
struct S_00ee9bf0_C : S_00ee9bf0_B
{
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    void* unk28;
    unsigned int unk2c;
    unsigned int unk30;
    virtual void vf0();
    __forceinline S_00ee9bf0_C() throw()
    {
        unk18 = DAT_0109b220;
        unk1c = DAT_0109b220;
        unk20 = DAT_0109b220;
        unk24 = DAT_0109b220;
        unk28 = NiTNewInterface_NiFixedString_Allocate(0xa);
        unk30 = 0;
        unk2c = 0xa;
    }
};
// Retained: the shared cache map has no constructor for its hash table.
struct FUN_00ee9bf0 : NiRefObject
{
    S_00ee9bf0_C alloc;
    void* unk34;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3a;
    virtual void vf1();
    FUN_00ee9bf0(void* a, unsigned char b, unsigned char c);
};
// @fnv 0x00ee9bf0
FUN_00ee9bf0::FUN_00ee9bf0(void* a, unsigned char b, unsigned char c)
{
    unk34 = a;
    unk38 = b;
    unk39 = 0;
    unk3a = c;
}
}  // namespace fnv_00ee9bf0

extern "C" int __cdecl strcmp(const char*, const char*);
void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

struct KeyObj
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual unsigned int CountKeys();
    virtual const char* GetKey(unsigned int index);
};

struct KeyEntry
{
    char** NiMaterialResource_GetVariable();
    __forceinline bool CompareKey(const char* key)
    {
        char* hk = *NiMaterialResource_GetVariable();
        if (hk == key)
            return true;
        if (!key || !hk)
            return false;
        return strcmp(hk, key) == 0;
    }
};

struct FUN_00ee90f0_cls
{
    KeyEntry** m_ppEntries;
    unsigned int unk04;
    unsigned int m_uiItemCount;
    void RemoveAt(int index);
};

// Marks entries whose keys appear in a1, then removes every unmarked entry from a2 by index in reverse order and returns true.
// @fnv 0x00ee90f0
bool __stdcall RemoveMissingKeys(KeyObj* apKeyObj, FUN_00ee90f0_cls* apEntryList)
{
    unsigned char flags[0x400];
    unsigned int count = apEntryList->m_uiItemCount;
    FUN_00ec61c0(flags, 0, 0x400);

    for (unsigned int i = 0; i < apKeyObj->CountKeys(); ++i)
    {
        const char* key = apKeyObj->GetKey(i);
        for (unsigned int uiEntryIndex = 0; uiEntryIndex < count; ++uiEntryIndex)
        {
            KeyEntry* e = apEntryList->m_ppEntries[uiEntryIndex];
            if (e && e->CompareKey(key))
            {
                flags[uiEntryIndex] = 1;
                break;
            }
        }
    }

    int iEntryIndex = (int)count - 1;
    if (iEntryIndex >= 0)
    {
        do
        {
            if (flags[iEntryIndex] == 0)
            {
                apEntryList->RemoveAt(iEntryIndex);
            }
        } while (--iEntryIndex >= 0);
    }
    return true;
}

// 0x00ee8a70  unit_e3a382715159.cpp  /MT /O2 /GS /EHsc /Gy
// target: 8D 41 28 C3   lea eax,[ecx+0x28] ; ret   (4 bytes, thiscall getter)
// @fnv 0x00ee8a70
// src: XBOX_PDB 0x00ee8a70
int* NiGPUProgramCache::GetValidCompileTargetsForPlatform()
{
    return reinterpret_cast<int*>(&unk28);
}

// @fnv 0x00ee8a80
// src: XBOX_PDB 0x00ee8a80
char* NiGPUProgramCache::GetShaderProfile()
{
    return reinterpret_cast<char*>(&m_s3);
}

// @fnv 0x00ee8a90
// src: XBOX_PDB 0x00ee8a90
char* NiGPUProgramCache::GetWorkingDirectory()
{
    return reinterpret_cast<char*>(&m_pcWorkingDir);
}

// @fnv 0x00ee8aa0
// src: COMMUNITY 0x00ee8aa0
char __thiscall NiGPUProgramCache::IsLoaded_00ee8aa0()
{
    return m_bLoadComplete;
}

bool NiFile_Access(const char* pcName, int iMode);

// Retained: CanCreateDirectory and LoadFromFile are nonvirtual in the shared cache.
class NiFileLoaderW
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual void Vf18();
    virtual void Vf1c();
    virtual void Vf20();
    virtual void Vf24();
    virtual void Vf28();
    virtual void Vf2c();
    virtual void Vf30();
    virtual void Vf34();
    virtual void Vf38();
    virtual void Vf3c();
    virtual void Vf40();
    virtual void Vf44();
    virtual void Vf48();
    virtual void Vf4c();
    virtual void Vf50();
    virtual void Vf54();
    virtual void Vf58();
    virtual void Vf5c();
    virtual void Vf60();
    virtual void Vf64();
    virtual void Vf68();
    virtual bool CanCreateDirectory();
    virtual void Vf70();
    virtual void Vf74();
    virtual void Vf78();
    virtual void Vf7c();
    virtual void Vf80();
    virtual void Vf84();
    virtual bool LoadFromFile(NiFile* pkFile, void* pvArg, void* pvArgCur);

    bool NiGPUProgramCache_AppendEntry(void* pvArg, void* pvArgCur);
    bool CanOpen()
    {
        if (m_pcFileName.m_kHandle == DAT_0109b220)
            return false;
        if (NiFile_Access(m_pcFileName, 0))
            return true;
        if (NiFile_Access(m_pcFileName, 1) && CanCreateDirectory())
            return true;
        return false;
    }

    char m_pad04[0x1c];
    NiFixedString m_pcFileName;
};

// @fnv 0x00ee8d60
// src: XBOX_PDB 0x00ee8d60
bool NiFileLoaderW::NiGPUProgramCache_AppendEntry(void* pvArg, void* pvArgCur)
{
    if (!CanOpen())
        return false;

    NiFile* pkFile = NiFile::GetFile(m_pcFileName, NiFile::APPEND_ONLY, 0x8000);
    if (!pkFile)
        return false;
    if (pkFile->operator bool() == true)
    {
        bool bResult = LoadFromFile(pkFile, pvArg, pvArgCur);
        delete pkFile;
        return bResult;
    }
    delete pkFile;
    return false;
}

// @fnv 0x00ee8ab0
// src: COMMUNITY 0x00ee8ab0
unsigned char NiGPUProgramCache::IsLocked_00ee8ab0()
{
    return m_3a;
}

#include <windows.h>
struct Node
{
    Node* next;
    unsigned int key;
    NiRefObject* value;
};
// Exe 0x00ee8e90: unit-local Map view; declarations and layout are preserved.
struct NigpuprogramcacheMapView
{
    int unk00;
    unsigned int bucketCount;
    Node** buckets;
    bool Lookup(unsigned int*, NiRefObject**);
};
// Finds the value for key, updates the reference in out with reference-count adjustments, and returns whether the key was found.
// @fnv 0x00ee8e90
bool NigpuprogramcacheMapView::Lookup(unsigned int* key, NiRefObject** ppOut)
{
    unsigned int value = *key;
    Node* node = buckets[value % bucketCount];
    while (node && value != node->key)
        node = node->next;
    if (!node)
        return false;
    NiRefObject* oldValue = *ppOut;
    if (oldValue != node->value)
    {
        if (oldValue && InterlockedDecrement((long*)&oldValue->m_uiRefCount) == 0)
            oldValue->DeleteThis();
        NiRefObject* newValue = node->value;
        *ppOut = newValue;
        if (newValue)
            InterlockedIncrement((long*)&newValue->m_uiRefCount);
    }
    return true;
}

inline void S_00ee9230_WriteBinary(NiBinaryStream* pkStream, const void* pvBuffer, unsigned int uiBytes,
                                   unsigned int uiComponentSize)
{
    *(unsigned int*)((char*)pkStream + 4) += (*(NiBinaryStream::WriteFunction*)((char*)pkStream + 0xc))(pkStream, pvBuffer, uiBytes, &uiComponentSize, 1);
}

// Writes a length-prefixed null-terminated string to pkStream, using a zero length when pcString is null.
// @fnv 0x00ee9230
// src: GAMEBRYO_LIB 0x00ee9230
bool __stdcall NiGPUProgramCache_SaveString(NiBinaryStream* pkStream, const char* pcString)
{
    if (pcString == 0)
    {
        int iLength = 0;
        S_00ee9230_WriteBinary(pkStream, &iLength, sizeof(iLength), sizeof(iLength));
    }
    else
    {
        int iLength = (int)strlen(pcString) + 1;
        S_00ee9230_WriteBinary(pkStream, &iLength, sizeof(iLength), sizeof(iLength));
        S_00ee9230_WriteBinary(pkStream, pcString, iLength, 1);
    }
    return true;
}

extern bool DAT_011c2fdd;
bool __cdecl NiFile_DirectoryExists(const char* pcName);
bool __cdecl NiFile_CreateDirectoryRecursive(const char* pcName);
NiFile* __cdecl FUN_00aa1a20(const char* pcName, int eMode, unsigned int uiBufferSize);
void __cdecl AdvancePosition(NiFile* pkFile, char* pcBuffer, unsigned int uiLen);
int __cdecl FUN_00aa1360(const char* pc1, const char* pc2);
void __cdecl InvokeAndAccumulate(NiFile* pkFile, bool* pbValue);
void __cdecl NiStreamLoadBinary_00a575b0(NiFile* pkFile, unsigned int* puiValue);

// Loads the GPU program cache file, validates header, version, and identifiers, then reads all records and marks loading complete.
// @fnv 0x00ee9350
bool NiGPUProgramCache::LoadCacheFile()
{
    bool bExists = m_pcWorkingDir != DAT_0109b220 && (NiFile_DirectoryExists(m_pcWorkingDir) || NiFile_CreateDirectoryRecursive(m_pcWorkingDir));
    if (!bExists)
        return false;

    if (m_bLoadComplete)
        return true;

    char acBuffer[0x200];
    NiFile* pkFile = FUN_00aa1a20(m_pcCacheFileName, 0, 0x8000);
    if (pkFile)
    {
        if (pkFile->operator bool() == true)
        {
            const char* pcHeader = "NiGPUProgram Cache File";
            AdvancePosition(pkFile, acBuffer, strlen(pcHeader) + 1);
            if (FUN_00aa1360(acBuffer, pcHeader) != 0)
            {
                delete pkFile;
                return false;
            }

            bool bLittleEndian;
            InvokeAndAccumulate(pkFile, &bLittleEndian);
            unsigned int uiVersion;
            NiStreamLoadBinary_00a575b0(pkFile, &uiVersion);
            if (uiVersion < 5)
            {
                delete pkFile;
                if (DAT_011c2fdd)
                    Clear();
                return false;
            }

            NiGPUProgramCache_LoadStringA(pkFile, acBuffer, 0x200);
            if (FUN_00aa1360(acBuffer, GetShaderType()) != 0)
            {
                delete pkFile;
                return false;
            }
            NiGPUProgramCache_LoadStringA(pkFile, acBuffer, 0x200);
            if (FUN_00aa1360(acBuffer, GetRendererName()) != 0)
            {
                delete pkFile;
                return false;
            }
            NiGPUProgramCache_LoadStringA(pkFile, acBuffer, 0x200);
            if (FUN_00aa1360(acBuffer, GetPlatformName()) != 0)
            {
                delete pkFile;
                return false;
            }

            bool bUpdated = false;
            while (pkFile->GetPosition() < pkFile->GetFileSize())
            {
                bool bEntryUpdated = false;
                if (!FiveIntegerLoadRecord(pkFile, &bEntryUpdated))
                {
                    delete pkFile;
                    return false;
                }
                if (bEntryUpdated)
                    bUpdated = true;
            }

            delete pkFile;
            m_bLoadComplete = true;
            if (bUpdated && DAT_011c2fdd)
                Clear();
            return true;
        }
        delete pkFile;
    }
    return false;
}

extern "C" size_t strlen(const char*);
extern char* _EmptyFS;
bool __cdecl NiFile_CreateDirectoryRecursive(const char* h);
void __cdecl Runtime_UpdateState_00e984d0(void* s, const char* name, unsigned int len);

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* pSize, unsigned int c)
{
    unsigned int r = (*(NIBINARYSTREAM_WRITEFN*)((char*)this + 0xc))(this, p, n, pSize, c);
    *(unsigned int*)((char*)this + 4) += r;
    return r;
}

template <class T> inline void S00ee9620_Save(NiFile& s, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    s.BinaryWrite(p, n * sizeof(T), &uiSize, 1);
}
template <class T> inline void S00ee9620_SaveBinary(NiFile* s, const T& v)
{
    S00ee9620_Save(*s, &v, 1);
}

struct OwnerMap : public FixedStringMap
{
    MapItem* NiTMapIterator_GetFirstPos();
    void GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val);
};

__declspec(noinline) void OwnerMap::GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val)
{
    MapItem* item = pos;
    key = item->m_key;
    val = item->m_val;
    if (item->m_pkNext)
    {
        pos = item->m_pkNext;
        return;
    }
    unsigned int bucket = (unsigned int)item->m_key.m_kHandle % m_uiHashSize + 1;
    for (; bucket < m_uiHashSize; ++bucket)
    {
        if (m_ppkHashTable[bucket])
        {
            pos = m_ppkHashTable[bucket];
            return;
        }
    }
    pos = 0;
}

__forceinline bool NiGPUProgramCache::CanSave()
{
    return static_cast<const NiFixedString&>(m_pcWorkingDir).Exists() && (((bool(__cdecl*)(const char*))NiFile_DirectoryExists)(m_pcWorkingDir) || NiFile_CreateDirectoryRecursive(m_pcWorkingDir));
}

// Writes the GPU cache file header and all map entries to a stream opened from m_20, returning true on success.
// @fnv 0x00ee9620
// src: XBOX_PDB 0x00ee9620
bool NiGPUProgramCache::Save_00ee9620()
{
    if (!CanSave())
        return false;
    const char* pcName = m_pcCacheFileName;
    NiFile* s = static_cast<NiFile*>(NiFile::GetFile(pcName, NiFile::WRITE_ONLY, 0x8000));
    if (s && s->operator bool() == true)
    {
        const char* str = "NiGPUProgram Cache File";
        Runtime_UpdateState_00e984d0(s, str, strlen(str) + 1);

        unsigned char bLittleEndian = 1;
        S00ee9620_SaveBinary(s, bLittleEndian);
        unsigned int version = 5;
        S00ee9620_SaveBinary(s, version);

        NiGPUProgramCache_SaveString(s, reinterpret_cast<unsigned int>(GetShaderType()));
        NiGPUProgramCache_SaveString(s, reinterpret_cast<unsigned int>(GetRendererName()));
        NiGPUProgramCache_SaveString(s, reinterpret_cast<unsigned int>(GetPlatformName().m_kHandle));

        MapItem* pItem = reinterpret_cast<OwnerMap*>(&m_kObjectMap)->NiTMapIterator_GetFirstPos();
        while (pItem != 0)
        {
            NiRefObject* valueObject;
            NiObjPtr& val = *reinterpret_cast<NiObjPtr*>(&valueObject);
            char* keyHandle = _EmptyFS;
            NiFixedString& key = *reinterpret_cast<NiFixedString*>(&keyHandle);
            val.m_pObject = 0;
            reinterpret_cast<OwnerMap*>(&m_kObjectMap)->GetNextEntry(pItem, key, val);
            NiRefObject* object = val.m_pObject;
            WriteToStream(s, object, reinterpret_cast<int*>(&key));
            if (key.m_kHandle != _EmptyFS)
            {
                InterlockedDecrement((long*)(key.m_kHandle - 8));
            }
            if (object != 0)
            {
                object->DecRefCount();
            }
        }
        delete s;
        return true;
    }
    return false;
}
