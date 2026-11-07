#include <new>
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiFile.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiGPUProgramCache.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiObjPtr.h"
#include "../../../../include/NiStandardAllocator.h"

// src/gamebryo2.2/corelibs/nimain/nigpuprogramcache_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nigpuprogramcache.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern void* DAT_11ac230;
void __cdecl NiFile_DirectoryExists();
struct S_00a8d8b0
{
    int _0;
    int pos;
    unsigned int(__cdecl* fn)(S_00a8d8b0*, void*, unsigned int, unsigned int*, unsigned int);
};
void __cdecl AdvancePosition(S_00a8d8b0* apState, void* b, unsigned int c);
void _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
extern int DAT_01101378;
extern int DAT_01101388;
struct SomeClass
{
    void* FUN_00ee90b0(unsigned int);
};
void __cdecl FUN_00ee9a60();
void __cdecl operator delete(void*, unsigned int);
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
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char* _EmptyFS;
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
class FixedStringMap
{
  public:
    virtual ~FixedStringMap();
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;

    void GetNextEntry(MapItem*& pos, NiFixedString& key, NiObjPtr& val);
};
bool __cdecl Path_IsRelative(const char*) throw();
bool __cdecl NiPath_GetCurrentWorkingDirectory(char*, unsigned int) throw();
int __cdecl BuildAbsolutePath(char*, unsigned int, const char*, const char*) throw();
// helpers of the game (declared only)
void __cdecl BuildAbsolutePath(char* buffer, unsigned int size, char* a, char* b);
char* __cdecl FUN_00a5b690(char* str);
class FUN_00ee8fe0_cls
{
  public:
    NiRefObject** m_ppkTable;
    unsigned int unk04;
    unsigned int m_uiSize;

    void RemoveAt(unsigned int idx);
};
extern void* DAT_11ac230;
void __cdecl NiFile_DirectoryExists();
void __cdecl AdvancePosition(S_00a8d8b0* a, void* b, unsigned int c);
bool __stdcall NiGPUProgramCache_LoadStringA(S_00a8d8b0* self, unsigned int pBuffer, unsigned int a3);
struct S_00ee97e0_Stream
{
    int unk00;
    unsigned int pos;
    int unk08;
    unsigned int(__cdecl* fn)(S_00ee97e0_Stream*, void*, unsigned int, unsigned int*, unsigned int);
};
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
__forceinline void S_00ee97e0_Write(S_00ee97e0_Stream* s, void* data)
{
    unsigned int sz = 4;
    s->pos += s->fn(s, data, 4, &sz, 1);
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
RecordPair* __cdecl CreateRecordPair();
char* __cdecl FUN_00a5b690(const char*);
struct ItemWithDtor
{
    void* m_pkNext;
    NiFixedString m_key;
    NiObjPtr m_val;

    __forceinline ~ItemWithDtor() throw()
    {}

    void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};
void __stdcall ClearAndDeleteItem(ItemWithDtor* pItem);
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
class SpawnedRoot
{
  public:
    virtual ~SpawnedRoot() throw()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
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
bool __stdcall RemoveMissingKeys(KeyObj* apKeyObj, FUN_00ee90f0_cls* apEntryList);
bool NiFile_Access(const char* pcName, int iMode);
#include <windows.h>
#include "../../../../include/NiTFixedStringMap_NiAVObject___.h"
struct Node
{
    Node* next;
    unsigned int key;
    NiRefObject* value;
};
// Exe 0x00ee9cc0: unit-local Map view; declarations and layout are preserved.
struct NigpuprogramcacheMapView
{
    int unk00;
    unsigned int bucketCount;
    Node** buckets;
    bool Lookup(unsigned int*, NiRefObject**);
};
struct S_00ee9230_Stream
{
    int unk0;
    unsigned int m_uiPos;
    int unk8;
    unsigned int(__cdecl* m_pfnWrite)(S_00ee9230_Stream* pkStream, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);
};
inline void S_00ee9230_WriteBinary(S_00ee9230_Stream* pkStream, const void* pvBuffer, unsigned int uiBytes,
                                   unsigned int uiComponentSize)
{
    pkStream->m_uiPos += pkStream->m_pfnWrite(pkStream, pvBuffer, uiBytes, &uiComponentSize, 1);
}
bool __stdcall NiGPUProgramCache_SaveString(S_00ee9230_Stream* pkStream, const char* pcString);
extern bool DAT_011c2fdd;
bool __cdecl NiFile_DirectoryExists(const char* pcName);
bool __cdecl NiFile_CreateDirectoryRecursive(const char* pcName);
NiFile* __cdecl FUN_00aa1a20(const char* pcName, int eMode, unsigned int uiBufferSize);
void __cdecl AdvancePosition(NiFile* pkFile, char* pcBuffer, unsigned int uiLen);
int __cdecl FUN_00aa1360(const char* pc1, const char* pc2);
void __cdecl InvokeAndAccumulate(NiFile* pkFile, bool* pbValue);
void __cdecl NiStreamLoadBinary_00a575b0(NiFile* pkFile, unsigned int* puiValue);
extern "C" size_t strlen(const char*);
extern char* _EmptyFS;
bool __cdecl NiFile_CreateDirectoryRecursive(const char* h);
void __cdecl Runtime_UpdateState_00e984d0(void* s, const char* name, unsigned int len);
struct StreamObj : public NiFile
{
    unsigned int m_pos;
    unsigned int unk08;
    unsigned int(__cdecl* m_fn)(StreamObj*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* pSize, unsigned int c)
    {
        unsigned int r = m_fn(this, (void*)p, n, pSize, c);
        m_pos += r;
        return r;
    }
};
template <class T> inline void S00ee9620_Save(StreamObj& s, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    s.BinaryWrite(p, n * sizeof(T), &uiSize, 1);
}
template <class T> inline void S00ee9620_SaveBinary(StreamObj* s, const T& v)
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

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern char* _EmptyFS;

inline NiRefObject::NiRefObject() : m_uiRefCount(0)
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&ms_lObjectCount));
}

struct ShaderPtr
{
    void* m_p;
    ShaderPtr& operator=(void* p);
};

struct ShaderEntry : NiRefObject
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    ShaderEntry() throw();
    void SetName(const NiFixedString& s);
    void AssignReferencedString_00eea650(const NiFixedString& s);
    void AssignReferencedString_00eea690(const NiFixedString& s);
    void SetLookAtName(const NiFixedString& s);
    void AssignRefCounted(const NiFixedString& s);
    void SetCreator_00eea540(unsigned int v);
    void NiMaterialResource_SetSource(unsigned int v);
    void NiMaterialResource_SetExtraData(unsigned int v);
    void NiMaterialResource_SetObjectType(unsigned int v);
};

struct EntrySet
{
    ShaderEntry** m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    void Add(ShaderEntry* const& p);
};

struct ShaderGroup : NiRefObject
{
    ShaderPtr m_pGeometryShader;
    EntrySet m_kEntries;
    virtual ~ShaderGroup();
    ShaderGroup() throw()
    {
        m_pGeometryShader.m_p = 0;
        m_kEntries.m_pBase = 0;
        m_kEntries.m_uiElementCount = 0;
        m_kEntries.m_uiAllocatedCapacity = 0;
    }
};

struct GroupPtrArg
{
    ShaderGroup* m_p;
    GroupPtrArg(ShaderGroup* p) : m_p(p)
    {
        if (m_p)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&m_p->m_uiRefCount));
    }
    GroupPtrArg(const GroupPtrArg& o) : m_p(o.m_p)
    {
        if (m_p)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&m_p->m_uiRefCount));
    }
};

struct GroupMap
{
    bool GetAt(const NiFixedString& key, ShaderGroup*& val);
    void SetAt(const NiFixedString& key, GroupPtrArg val);
};

static inline unsigned int ReadRaw(S_00a8d8b0* s, void* dst, unsigned int total, unsigned int elem)
{
    unsigned int sz = elem;
    unsigned int result = s->fn(s, dst, total, &sz, 1);
    s->pos += result;
    return result;
}


static __forceinline void ReadStr0(S_00a8d8b0* s, char* buf)
{
    unsigned int len = 0;
    ReadRaw(s, &len, 4, 4);
    if (len == 0)
    {
        buf[0] = 0;
    }
    else
    {
        AdvancePosition(s, buf, len);
        buf[len + 1] = 0;
    }
}
static __forceinline void ReadStr(S_00a8d8b0* s, char* buf)
{
    unsigned int len = 0;
    ReadRaw(s, &len, 4, 4);
    if (len == 0)
    {
        buf[0] = 0;
    }
    else
    {
        ReadRaw(s, buf, len, 1);
        buf[len + 1] = 0;
    }
}

class ShaderLib
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual bool LoadShader(S_00a8d8b0* s, NiFixedString& name, void*& out, bool skip);

    int unk04;
    GroupMap m_kObjectGroups;
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
    int m_iSlotCount;

    bool NiGPUProgramCache_LoadEntry(S_00a8d8b0* s, bool& changed);
};

// The cache reader constructs strings in raw storage and releases them explicitly.
__declspec(nothrow) static __forceinline NiFixedString* ConstructCacheString(void* storage, const char* text)
{
    return ::new (storage) NiFixedString(text);
}

// @fnv 0x00ee9cc0
// src: XBOX_PDB 0x00ee9cc0
bool ShaderLib::NiGPUProgramCache_LoadEntry(S_00a8d8b0* s, bool& changed)
{
    char buf[0x200];
    int version;
    ReadRaw(s, &version, 4, 4);
    ReadStr0(s, buf);
    // These strings are released explicitly along each path, as in the game.
    void* nameStorage[sizeof(NiFixedString) / sizeof(void*)];
    NiFixedString& name = *ConstructCacheString(nameStorage, buf);
    bool skip = false;
    if (version != m_iSlotCount)
    {
        changed = true;
        skip = true;
    }
    GroupMap* map;
    {
        ShaderGroup* found = 0;
        map = &m_kObjectGroups;
        if (map->GetAt(name, found))
            skip = true;
        if (found)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&found->m_uiRefCount)) == 0)
                found->DeleteThis();
        }
    }
    ShaderGroup* group = 0;
    if (!skip)
        group = new ShaderGroup;

    void* shader = 0;
    if (!LoadShader(s, name, shader, skip))
    {
        name.~NiFixedString();
        return false;
    }
    if (!skip)
        group->m_pGeometryShader = shader;

    unsigned int count = 0;
    ReadRaw(s, &count, 4, 4);
    for (unsigned int i = 0; i < count; i++)
    {
        if (!skip)
        {
            ShaderEntry* e = new ShaderEntry;
            ReadStr(s, buf);
            void* t1Storage[sizeof(NiFixedString) / sizeof(void*)];
            NiFixedString& t1 = *ConstructCacheString(t1Storage, buf);
            e->SetName(t1);
            t1.~NiFixedString();
            ReadStr(s, buf);
            void* t2Storage[sizeof(NiFixedString) / sizeof(void*)];
            NiFixedString& t2 = *ConstructCacheString(t2Storage, buf);
            e->AssignReferencedString_00eea650(t2);
            t2.~NiFixedString();
            ReadStr(s, buf);
            void* t3Storage[sizeof(NiFixedString) / sizeof(void*)];
            NiFixedString& t3 = *ConstructCacheString(t3Storage, buf);
            e->AssignReferencedString_00eea690(t3);
            t3.~NiFixedString();
            ReadStr(s, buf);
            void* t4Storage[sizeof(NiFixedString) / sizeof(void*)];
            NiFixedString& t4 = *ConstructCacheString(t4Storage, buf);
            e->SetLookAtName(t4);
            t4.~NiFixedString();
            ReadStr(s, buf);
            void* t5Storage[sizeof(NiFixedString) / sizeof(void*)];
            NiFixedString& t5 = *ConstructCacheString(t5Storage, buf);
            e->AssignRefCounted(t5);
            t5.~NiFixedString();
            unsigned int v;
            ReadRaw(s, &v, 4, 4);
            e->SetCreator_00eea540(v);
            ReadRaw(s, &v, 4, 4);
            e->NiMaterialResource_SetSource(v);
            ReadRaw(s, &v, 4, 4);
            e->NiMaterialResource_SetExtraData(v);
            ReadRaw(s, &v, 4, 4);
            e->NiMaterialResource_SetObjectType(v);
            {
                ShaderEntry* sp = e;
                if (e)
                    InterlockedIncrement(reinterpret_cast<volatile long*>(&e->m_uiRefCount));
                group->m_kEntries.Add(sp);
            }
            if (e)
            {
                if (InterlockedDecrement(reinterpret_cast<volatile long*>(&e->m_uiRefCount)) == 0)
                    e->DeleteThis();
            }
        }
        else
        {
            ReadStr(s, buf);
            ReadStr(s, buf);
            ReadStr(s, buf);
            ReadStr(s, buf);
            ReadStr(s, buf);
            unsigned int v;
            ReadRaw(s, &v, 4, 4);
            ReadRaw(s, &v, 4, 4);
            ReadRaw(s, &v, 4, 4);
            ReadRaw(s, &v, 4, 4);
        }
    }
    if (!skip && group->m_pGeometryShader.m_p)
    {
        map->SetAt(name, group);
    }
    name.~NiFixedString();
    return true;
}
