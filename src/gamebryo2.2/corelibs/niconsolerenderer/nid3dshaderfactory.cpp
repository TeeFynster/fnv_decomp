// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderfactory.cpp: NiD3DShaderFactory and shader map helpers (46 functions)

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiD3DShaderFactory.h"
#include "../../../../include/NiD3DDefaultShader.h"
#include "../../../../include/NiD3DShaderInterface.h"
#include "../../../../include/NiD3DShaderProgramFactory.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiShader.h"
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTMap.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTStringPointerMap.h"

class NiShaderLibrary;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*> ShaderMapBase;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiPointer<NiShaderLibrary> > ShaderLibraryMapBase;
typedef NiTStringPointerMap<NiShader*> ShaderStringMap;
typedef NiTStringPointerMap<NiPointer<NiShaderLibrary> > ShaderLibraryStringMap;

typedef NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*> ShaderStringTemplateMap;
typedef NiTStringTemplateMap<NiTPointerMap<const char*, NiPointer<NiShaderLibrary> >,
                             NiPointer<NiShaderLibrary> > ShaderLibraryStringTemplateMap;

extern void* DAT_011f4a64;
extern void* DAT_0126fa0c;
extern void* DAT_011f6044;
extern void* DAT_010f0bc0;
extern void* DAT_010f0c20;
extern void* DAT_010f0c80;
extern void* DAT_010f0ca0;
extern void(__stdcall* DAT_00fdf054)(void*);
extern unsigned char kVtbl_NiD3DShaderFactory;
extern MemoryManager g_memoryManager;
extern "C" void* __cdecl NiMalloc(unsigned int);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned long);

template <class TAlloc, class TKEY, class TVAL>
__forceinline void* NiTMapBase<TAlloc, TKEY, TVAL>::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; ++i)
    {
        if (m_ppkHashTable[i])
            return m_ppkHashTable[i];
    }
    return 0;
}

template <>
__declspec(noalias) bool ShaderLibraryMapBase::GetAt(const char*, NiPointer<NiShaderLibrary>&) const throw();
template <>
__declspec(noalias) bool ShaderLibraryMapBase::RemoveAt(const char*) throw();

// NiShaderLibrary is only forward-declared here; its reference-counted base is shared.
template <>
inline NiPointer<NiShaderLibrary>::~NiPointer()
{
    if (m_pObject)
    {
        NiRefObject* object = reinterpret_cast<NiRefObject*>(m_pObject);
        if (InterlockedDecrement(reinterpret_cast<long volatile*>(&object->m_uiRefCount)) == 0)
            object->DeleteThis();
    }
}

template <>
inline NiPointer<NiShaderLibrary>& NiPointer<NiShaderLibrary>::operator=(const NiPointer& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
        {
            NiRefObject* object = reinterpret_cast<NiRefObject*>(m_pObject);
            if (InterlockedDecrement(reinterpret_cast<long volatile*>(&object->m_uiRefCount)) == 0)
                object->DeleteThis();
        }
        m_pObject = other.m_pObject;
        if (m_pObject)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&reinterpret_cast<NiRefObject*>(m_pObject)->m_uiRefCount));
    }
    return *this;
}

const char kFailedShaderFactoryMessage[] = "Failed to create shader factory!";

class ShaderMaterialCache;
// 0x00e94130 and 0x00e940d0 work on {current material cache at +0, dirty flag at +4}, not on NiD3DShaderFactory.
struct ShaderMaterialCacheSlot
{
    ShaderMaterialCache* m_pCurrent;
    bool m_bDirty;
    void ShutdownPoint3();
    void UpdateShaderMaterialCache(void*);
};

// @fnv 0x00e94130
void ShaderMaterialCacheSlot::ShutdownPoint3()
{
    m_pCurrent = 0;
    UpdateShaderMaterialCache(DAT_011f4a64);
    m_bDirty = true;
}

// Allocates a NiD3DShaderFactory, calls Create to store it in DAT_0126fa0c and DAT_011f6044, and reports failure if the factory is null.
// @fnv 0x00e92e60
void NiD3DShaderFactory::InitializePoint3()
{
    if (DAT_0126fa0c == 0)
    {
        NiD3DShaderFactory* factory = static_cast<NiD3DShaderFactory*>(NiMemObject::operator new(0x100));
        NiShaderFactory* result;
        if (factory)
            result = factory->Create();
        else
            result = 0;
        DAT_0126fa0c = result;
        DAT_011f6044 = result;
    }
    if (DAT_011f6044 == 0)
        NiD3DDefaultShader::SetShaderName(kFailedShaderFactoryMessage);
}

// Initializes the shader factory's vtable and state, allocates two string-map storages for shaders and libraries, and returns this.
// @fnv 0x00e92cf0
NiShaderFactory* NiD3DShaderFactory::Create()
{
    FUN_00aa0390();
    *(void**)this = &kVtbl_NiD3DShaderFactory;
    m_pOwnerShader = 0;
    DAT_00fdf054(m_kShaderMap);

    ShaderStringMap* shaderMap;
    ShaderStringMap* shaderStorage =
        static_cast<ShaderStringMap*>(g_memoryManager.Allocate(sizeof(ShaderStringMap)));
    if (shaderStorage)
    {
        *reinterpret_cast<void**>(shaderStorage) = &DAT_010f0bc0;
        shaderStorage->m_uiHashSize = 0x3b;
        shaderStorage->m_kItemCount.m_uiCount = 0;
        shaderStorage->m_ppkHashTable = static_cast<ShaderStringMap::EntryType**>(NiMalloc(0xec));
        fnv_zlib_memset(shaderStorage->m_ppkHashTable, 0, shaderStorage->m_uiHashSize * 4);
        shaderStorage->m_bCopy = true;
        *reinterpret_cast<void**>(shaderStorage) = &DAT_010f0c80;
        shaderMap = shaderStorage;
    }
    else
        shaderMap = 0;
    m_pShaderMapStorage = shaderMap;

    ShaderLibraryStringMap* libraryStorage =
        static_cast<ShaderLibraryStringMap*>(g_memoryManager.Allocate(sizeof(ShaderLibraryStringMap)));
    if (libraryStorage)
    {
        *reinterpret_cast<void**>(libraryStorage) = &DAT_010f0c20;
        libraryStorage->m_uiHashSize = 0x25;
        libraryStorage->m_kItemCount.m_uiCount = 0;
        libraryStorage->m_ppkHashTable = static_cast<ShaderLibraryStringMap::EntryType**>(NiMalloc(0x94));
        fnv_zlib_memset(libraryStorage->m_ppkHashTable, 0, libraryStorage->m_uiHashSize * 4);
        libraryStorage->m_bCopy = false;
        *reinterpret_cast<void**>(libraryStorage) = &DAT_010f0ca0;
        m_pShaderLibraryStorage = libraryStorage;
        return this;
    }
    m_pShaderLibraryStorage = 0;
    return this;
}

struct FUN_00e91f40_shell : public NiD3DShaderFactory
{
    char* NiD3DShaderFactory_GetNextProgramDirectory(void**);
};

NiD3DShaderProgramFactory* __cdecl NiD3DShaderProgramFactory_GetInstance();

// @fnv 0x00e91f40
// src: XBOX_PDB 0x00e91f40
char* FUN_00e91f40_shell::NiD3DShaderFactory_GetNextProgramDirectory(void** kIter)
{
    NiD3DShaderProgramFactory* pkSPFactory = NiD3DShaderProgramFactory_GetInstance();
    if (!pkSPFactory)
        return 0;
    return (char*)pkSPFactory->GetNextName(*kIter);
}

namespace fnv_00e91fa0 {
struct FUN_00e91fa0_shell : public NiD3DShaderFactory
{
    void NiD3DShaderFactory_RemoveAllProgramDirectories();
};

void* __cdecl NiD3DShaderProgramFactory_GetInstance();
void __fastcall NiD3DShaderProgramFactory_RemoveAllProgramDirectories(void* pThis);

// @fnv 0x00e91fa0
// src: XBOX_PDB 0x00e91fa0
void FUN_00e91fa0_shell::NiD3DShaderFactory_RemoveAllProgramDirectories()
{
    void* pkFactory = NiD3DShaderProgramFactory_GetInstance();
    if (pkFactory)
        NiD3DShaderProgramFactory_RemoveAllProgramDirectories(pkFactory);
}
}  // namespace fnv_00e91fa0

struct NiConsoleRendererStub
{
    void NiDX9Renderer_PurgeAllD3DShaders();
};
struct FUN_00e91ea0_cls
{
    char pad[0x24];
    NiConsoleRendererStub* renderer;
};
// @fnv 0x00e91ea0
// src: GAMEBRYO_LIB 0x00e91ea0
void __fastcall NiD3DShaderFactory_PurgeAllShaderRendererData(FUN_00e91ea0_cls* self, int)
{
    if (self->renderer)
        self->renderer->NiDX9Renderer_PurgeAllD3DShaders();
}

// @fnv 0x00e91eb0
// src: XBOX_PDB 0x00e91eb0
unsigned int __stdcall NiD3DShaderFactory_GetMinorVertexShaderVersion(unsigned int uiVersion)
{
    return uiVersion & 0xFF;
}

// @fnv 0x00e91ec0
unsigned int __stdcall MakeVersionCode(unsigned int uiMajor, unsigned int uiMinor)
{
    return ((0xFFFFFF00 | uiMajor) << 8) | uiMinor;
}

// @fnv 0x00e91ee0
// src: XBOX_PDB 0x00e91ee0
unsigned int __stdcall NiD3DShaderFactory_GetMajorVertexShaderVersion(unsigned int uiVersion)
{
    return (uiVersion >> 8) & 0xFF;
}

// @fnv 0x00e91ef0
// src: XBOX_PDB 0x00e91ef0
unsigned int __stdcall NiD3DShaderFactory_CreateVertexShaderVersion(unsigned int a, unsigned int b)
{
    return ((0xFFFFFE00 | a) << 8) | b;
}

// @fnv 0x00e91f10
// src: XBOX_PDB 0x00e91f10
void* __cdecl NiD3DShaderFactory_GetD3DShaderFactory()
{
    return DAT_0126fa0c;
}

namespace fnv_00e91f20 {
extern char* NiD3D10ShaderProgramFactory_GetFirstProgramDirectory();
struct FUN_00e91f20_shell : public NiD3DShaderFactory
{
    char* NiD3DShaderFactory_GetFirstProgramDirectory(void**);
};

extern NiD3DShaderProgramFactory* __cdecl NiD3DShaderProgramFactory_GetInstance(void);

// @fnv 0x00e91f20
// src: XBOX_PDB 0x00e91f20
char* FUN_00e91f20_shell::NiD3DShaderFactory_GetFirstProgramDirectory(void** kIter)
{
    NiD3DShaderProgramFactory* pkSPFactory = NiD3DShaderProgramFactory_GetInstance();
    if (!pkSPFactory)
        return 0;
    // The shared factory does not yet declare the first-name lookup.
    typedef char* (__thiscall* GetFirstName)(NiD3DShaderProgramFactory*, void**);
    return reinterpret_cast<GetFirstName>(&NiD3D10ShaderProgramFactory_GetFirstProgramDirectory)(pkSPFactory, kIter);
}
}  // namespace fnv_00e91f20

namespace fnv_00e91f60 {
NiD3DShaderProgramFactory* __cdecl NiD3DShaderProgramFactory_GetInstance(void);

// @fnv 0x00e91f60
// src: XBOX_PDB 0x00e91f60
void __stdcall NiD3DShaderFactory_AddProgramDirectory(const char* pacDirectory)
{
    NiD3DShaderProgramFactory* pkFactory = NiD3DShaderProgramFactory_GetInstance();
    if (pkFactory)
        pkFactory->AddDirectory(pacDirectory);
}
}  // namespace fnv_00e91f60

namespace fnv_00e91f80 {

NiD3DShaderProgramFactory* __cdecl NiD3DShaderProgramFactory_GetInstance();

// @fnv 0x00e91f80
// src: XBOX_PDB 0x00e91f80
void __stdcall NiD3DShaderFactory_RemoveProgramDirectory(char* pacDirectory)
{
    NiD3DShaderProgramFactory* pkFactory = NiD3DShaderProgramFactory_GetInstance();
    if (pkFactory)
        pkFactory->LoadProgramByName(pacDirectory);
}
}  // namespace fnv_00e91f80

// @fnv 0x00e91fc0
// src: COMMUNITY 0x00e91fc0
const char* __cdecl NiD3DGPUProgramCache_GetPlatform()
{
    return "DX9";
}

extern char $SG6379[];
extern int __cdecl NiSprintf(char*, unsigned int, char const*, ...);
extern int _ref_00ec408c;

struct NiD3DShaderFactory_shell
{
    ShaderMapBase* m_pShaderMapStorage;
    void __thiscall NiD3DShaderFactory_RemoveShader(const char* pcName, unsigned int uiImplementation);
};

// Builds a name from pcName and uiImplementation and removes the matching entry from the map at offset 0x28 if present.
// @fnv 0x00e923f0
// src: XBOX_PDB 0x00e923f0
void __thiscall NiD3DShaderFactory_shell::NiD3DShaderFactory_RemoveShader(const char* pcName, unsigned int uiImplementation)
{
    char acFullName[260];
    if (*(ShaderMapBase**)((char*)this + 0x28))
    {
        NiSprintf(acFullName, sizeof(acFullName), "%s%d", pcName, uiImplementation);
        (*(ShaderMapBase**)((char*)this + 0x28))->RemoveAt(acFullName);
    }
}

struct FUN_00e92460_cls
{
    char pad[0x28];
    ShaderMapBase* map;
};
// @fnv 0x00e92460
// src: GAMEBRYO_LIB 0x00e92460
void __fastcall NiD3DShaderFactory_RemoveAllShaders(FUN_00e92460_cls* self, int)
{
    if (self->map)
        self->map->RemoveAll();
}

// @fnv 0x00e92590
// src: GUESS 0x00e92590 (confidence: high)
unsigned int __stdcall NiD3DShaderFactory_AreValuesEqual(unsigned int auiLeft, unsigned int auiRight)
{
    return auiLeft == auiRight;
}

namespace fnv_00e92520 {
void __fastcall DestroyMap(ShaderMapBase* self, int);
}
// @fnv 0x00e92690
ShaderMapBase* __fastcall FUN_00e92690(ShaderMapBase* self, int, unsigned int flags)
{
    typedef void (__thiscall* DestroyMap)(ShaderMapBase*);
    reinterpret_cast<DestroyMap>(&fnv_00e92520::DestroyMap)(self);
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

// @fnv 0x00e92cd0
ShaderLibraryStringTemplateMap* __fastcall FUN_00e92cd0(ShaderLibraryStringTemplateMap* self, int, unsigned int flags)
{
    self->ShaderLibraryStringTemplateMap::~NiTStringTemplateMap();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

namespace fnv_00e92520 {
void __cdecl NiFreeAlias(void*);

extern void* DAT_010f0bc0;
extern void* DAT_010f0be0;
extern void* DAT_010f0c00;

// @fnv 0x00e92520
void __fastcall DestroyMap(ShaderMapBase* self, int)
{
    *reinterpret_cast<void**>(self) = &DAT_010f0c00;
    if (*(char*)(((char*)self) + 0x10))
    {
        for (unsigned int i = 0; i < self->m_uiHashSize; ++i)
        {
            void* item = static_cast<void*>(self->m_ppkHashTable[i]);
            while (item)
            {
                void* node = item;
                item = *(void**)node;
                NiFreeAlias(*(void**)((char*)node + 4));
            }
        }
    }
    *reinterpret_cast<void**>(self) = &DAT_010f0be0;
    self->RemoveAll();
    *reinterpret_cast<void**>(self) = &DAT_010f0bc0;
    self->RemoveAll();
    NiFreeAlias(self->m_ppkHashTable);
}
}  // namespace fnv_00e92520

void __cdecl _NiFreeAlias(void*);

// Resets the map, removes its entries, frees its buckets, and optionally deallocates it.
// @fnv 0x00e92610
void* __fastcall DestroyShaderMapBase(ShaderMapBase* self, int, unsigned int flags)
{
    *reinterpret_cast<void**>(self) = &DAT_010f0bc0;
    self->RemoveAll();
    _NiFreeAlias(self->m_ppkHashTable);
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

namespace fnv_00e92650 {
extern void* DAT_010f0be0;
void __cdecl _NiFreeAlias(void*);
// Resets two embedded map bases, frees unk8, and optionally deallocates the object when flags bit 0 is set.
// @fnv 0x00e92650
void* __fastcall DestroyHolder(ShaderMapBase* self, int, unsigned int flags)
{
    *reinterpret_cast<void**>(self) = &DAT_010f0be0;
    self->RemoveAll();
    *reinterpret_cast<void**>(self) = &DAT_010f0bc0;
    self->RemoveAll();
    fnv_00e92650::_NiFreeAlias(self->m_ppkHashTable);
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e92650

namespace fnv_00e926b0 {
extern void* DAT_010f0c20;
void NiFreeAlias(void* p);
// Resets the vftable, removes all entries, frees the field pointer, and optionally deallocates this object.
// @fnv 0x00e926b0
void* __fastcall DestroyMap(ShaderLibraryMapBase* self, int, bool abFree)
{
    *reinterpret_cast<void**>(self) = &DAT_010f0c20;
    self->RemoveAll();
    NiFreeAlias(self->m_ppkHashTable);
    if (abFree & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e926b0

namespace fnv_00e926f0 {
extern int DAT_010f0c40;
void __cdecl _NiFreeAlias(void*);
// Resets two map bases, frees the buckets, and optionally deallocates the map.
// @fnv 0x00e926f0
void* __fastcall DestroyMap(ShaderLibraryMapBase* self, int, unsigned int auiFlags)
{
    *reinterpret_cast<void**>(self) = (void*)&DAT_010f0c40;
    self->RemoveAll();
    *reinterpret_cast<void**>(self) = (void*)&DAT_010f0c20;
    self->RemoveAll();
    fnv_00e926f0::_NiFreeAlias(self->m_ppkHashTable);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e926f0

extern char const* const g_0126f754_arg1;
// Casts pkShader to NiD3DShaderInterface and returns whether it is the default shader, or false if the cast fails.
// @fnv 0x00e92730
bool __stdcall IsDefaultShader(NiShader* pkShader)
{
    if (pkShader)
    {
        NiD3DShaderInterface* pkShaderIf =
            (NiD3DShaderInterface*)pkShader->DynamicCast((NiRTTI const*)&g_0126f754_arg1);
        if (pkShaderIf)
        {
            // IsDefault is nonvirtual in the shared header; this call uses game slot 57.
            typedef bool (__thiscall* IsDefaultVirtual)(NiD3DShaderInterface*);
            return reinterpret_cast<IsDefaultVirtual>((*reinterpret_cast<void***>(pkShaderIf))[57])(pkShaderIf);
        }
    }
    return false;
}

void __cdecl operator delete(void* p, unsigned int);

void __cdecl UpdateFields_00e92dc0();

struct FUN_00e92e30_shell : public NiD3DShaderFactory
{
    void* __thiscall DestroyShaderFactory(unsigned int flags);
};

// Calls FUN_00e92dc0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00e92e30
void* __thiscall FUN_00e92e30_shell::DestroyShaderFactory(unsigned int flags)
{
    UpdateFields_00e92dc0();
    if (flags & 1)
        operator delete(this, 0x100);
    return this;
}

struct GraphicsRenderer;
struct FUN_00e91e60_shell : public NiD3DShaderFactory
{
    void NiD3DShaderFactory_SetRenderer(GraphicsRenderer*);
};

struct ShaderConstantInterface
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void SetShaderRenderer(GraphicsRenderer*);
};
struct FakeFactory374
{
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
    virtual void* vf4();
    virtual void* vf5();
    virtual void* vf6();
    virtual void* vf7();
    virtual void* vf8();
    virtual void* vf9();
    virtual void* vf10();
    virtual void* vf11();
    virtual void* vf12();
    virtual void* vf13();
    virtual ShaderConstantInterface* GetVertexShaderConstantInterface();
    virtual ShaderConstantInterface* GetPixelShaderConstantInterface();
};
// @fnv 0x00e91e60
// src: GAMEBRYO_SRC 0x00e91e60
void FUN_00e91e60_shell::NiD3DShaderFactory_SetRenderer(GraphicsRenderer* pkRenderer)
{
    ShaderConstantInterface* pkLibrary;
    if (*(GraphicsRenderer**)((char*)this + 0x24) != pkRenderer)
    {
        *(GraphicsRenderer**)((char*)this + 0x24) = pkRenderer;
        pkLibrary = ((FakeFactory374*)this)->GetVertexShaderConstantInterface();
        if (pkLibrary)
        {
            do
            {
                pkLibrary->SetShaderRenderer(pkRenderer);
                pkLibrary = ((FakeFactory374*)this)->GetPixelShaderConstantInterface();
            } while (pkLibrary);
        }
    }
}

namespace fnv_00e921d0 {
int __cdecl NiSprintf(char* buf, int size, const char* fmt, ...);
struct FUN_00e921d0_shell
{
    char* m_pShaderMapStorage;
    NiShader* GetShaderByNameAndImplementation(const char* pcName, unsigned int uiImplementation);
};
// Builds a name from pcName and uiImplementation, looks it up in the shader map at this+0x28, and returns the found NiShader or null.
// @fnv 0x00e921d0
NiShader* FUN_00e921d0_shell::GetShaderByNameAndImplementation(const char* pcName, unsigned int uiImplementation)
{
    if (!*(ShaderMapBase**)((char*)this + 0x28))
        return 0;
    NiShader* pkShader = 0;
    char acFullName[260];
    NiSprintf(acFullName, 260, "%s%d", pcName, uiImplementation);
    return (*(ShaderMapBase**)((char*)this + 0x28))->GetAt(acFullName, pkShader) ? pkShader : 0;
}
}  // namespace fnv_00e921d0

namespace fnv_00e929c0 {

int NiSprintf(char*, int, const char*, ...);

extern const char $SG6456[];
extern unsigned int _data_011c16bc;
void _ref_00ec408c(unsigned int);

struct FUN_00e929c0_shell
{
    void RegisterShaderImplementation(NiShader* pkShader, unsigned int uiImplementation);
};

// Builds a name from the shader filename and implementation index, then stores the shader in the map at this+0x28 if both exist.
// @fnv 0x00e929c0
void FUN_00e929c0_shell::RegisterShaderImplementation(NiShader* pkShader, unsigned int uiImplementation)
{
    char acFullName[260];

    if (pkShader)
    {
        NiSprintf(acFullName, 260, $SG6456, pkShader->GetFilename().m_kHandle, uiImplementation);

        ShaderMapBase* pkMap = *(ShaderMapBase**)((char*)this + 0x28);
        if (pkMap)
            pkMap->SetAt(acFullName, pkShader);
    }
}
}  // namespace fnv_00e929c0

// @fnv 0x00b57f20
template <>
void ShaderMapBase::GetNext(void*& pos, const char*& key, NiShader*& val) const
{
    EntryType* item = static_cast<EntryType*>(pos);
    key = item->m_key;
    val = item->m_val;
    EntryType* next = item->m_pkNext;
    if (next)
    {
        pos = next;
        return;
    }
    unsigned int i = KeyToHashIndex(item->m_key);
    i = i + 1;
    while (i < m_uiHashSize)
    {
        EntryType* p = m_ppkHashTable[i];
        if (p)
        {
            pos = p;
            return;
        }
        i++;
    }
    pos = 0;
}

// Advances the library-map iterator, retaining the returned library.
// @fnv 0x00e6e630
template <>
void ShaderLibraryMapBase::GetNext(void*& pos, const char*& key, NiPointer<NiShaderLibrary>& val) const
{
    EntryType* pNode = static_cast<EntryType*>(pos);
    key = pNode->m_key;
    NiRefObject* pOldValue = reinterpret_cast<NiRefObject*>(val.m_pObject);
    if (pOldValue != reinterpret_cast<NiRefObject*>(pNode->m_val.m_pObject))
    {
        if (pOldValue != 0)
        {
            if (InterlockedDecrement(reinterpret_cast<long volatile*>(&pOldValue->m_uiRefCount)) == 0)
            {
                pOldValue->DeleteThis();
            }
        }
        val.m_pObject = pNode->m_val.m_pObject;
        if (val.m_pObject != 0)
        {
            InterlockedIncrement(reinterpret_cast<long volatile*>(&reinterpret_cast<NiRefObject*>(val.m_pObject)->m_uiRefCount));
        }
    }
    if (pNode->m_pkNext != 0)
    {
        pos = pNode->m_pkNext;
        return;
    }
    unsigned int uiIndex = KeyToHashIndex(pNode->m_key) + 1;
    if (uiIndex >= m_uiHashSize)
    {
        pos = 0;
        return;
    }
    EntryType** p = m_ppkHashTable + uiIndex;
    do
    {
        pNode = *p;
        if (pNode != 0)
        {
            pos = pNode;
            return;
        }
        ++uiIndex;
        ++p;
    } while (uiIndex < m_uiHashSize);
    pos = 0;
}

extern "C" void(__stdcall* fnv_EnterCriticalSection)(void* pkSection);
extern "C" void(__stdcall* fnv_LeaveCriticalSection)(void* pkSection);

// The shared shader does not yet declare its implementation getter.
extern unsigned int NiD3DShaderProgram_GetName();
typedef unsigned int (__thiscall* GetShaderImplementation)(NiShader*);

struct E92270CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class E92270Entry
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual bool Matches(const char* pcName, unsigned int uiID);
};

class E92270Library
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual NiShader* FindProgram(const char* pcName, unsigned int uiID);
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual E92270Entry* GetFirstEntry();
    virtual E92270Entry* GetNextEntry();

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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    E92270CriticalSection m_kCriticalSection;

    bool HasEntry(const char* pcName, unsigned int uiID);
};

// Checks pcName is non-empty and resolves a program by name/ID, then scans the library's entries under the critical section for a matching entry.
// @fnv 0x00e92270
bool E92270Library::HasEntry(const char* pcName, unsigned int uiID)
{
    if (!pcName || !*pcName)
        return false;

    if (!FindProgram(pcName, uiID))
    {
        NiShader* pkProgram = FindProgram(pcName, 0xffffffff);
        if (!pkProgram || reinterpret_cast<GetShaderImplementation>(&NiD3DShaderProgram_GetName)(pkProgram) != uiID)
            return false;
    }

    fnv_EnterCriticalSection(&m_kCriticalSection);
    E92270Entry* pkEntry = GetFirstEntry();
    bool bFound = false;
    while (pkEntry)
    {
        if (pkEntry->Matches(pcName, uiID))
        {
            bFound = true;
            break;
        }
        pkEntry = GetNextEntry();
    }
    fnv_LeaveCriticalSection(&m_kCriticalSection);
    return bFound;
}

struct ShaderLibrary
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual bool IsDefault();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void ReleaseResources();

    void FUN_00e818d0(void* renderer);
};
struct ShaderRenderer
{
    void NiXenonRenderer_RegisterD3DShader(ShaderLibrary* library);
};
struct ShaderFactoryShell : NiD3DShaderFactory
{
    void NiD3DShaderFactory_RestoreAllShaderRendererData();
};
// Iterates the shader library map and, for each non-default shader, releases its resources and notifies the renderer.
// @fnv 0x00e92470
// src: GAMEBRYO_SRC 0x00e92470
void ShaderFactoryShell::NiD3DShaderFactory_RestoreAllShaderRendererData()
{
    if (m_pOwnerShader && m_pShaderMapStorage)
    {
        ShaderMapBase* map = static_cast<ShaderMapBase*>(m_pShaderMapStorage);
        ShaderLibrary* volatile pCurrentShader = 0;
        void* current = map->GetFirstPos();
        const char* position;
        while (current)
        {
            static_cast<ShaderMapBase*>(m_pShaderMapStorage)
                ->GetNext(current, position, *reinterpret_cast<NiShader**>(const_cast<ShaderLibrary**>(&pCurrentShader)));
            ShaderLibrary* activeShader = pCurrentShader;
            if (activeShader)
            {
                ShaderLibrary& library = *activeShader;
                if (!library.IsDefault())
                {
                    library.FUN_00e818d0(m_pOwnerShader);
                    library.ReleaseResources();
                    static_cast<ShaderRenderer*>(m_pOwnerShader)->NiXenonRenderer_RegisterD3DShader(&library);
                }
            }
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl strcpy_s(char* pcDest, unsigned int uiSize, const char* pcSrc);

void* __cdecl NiMalloc(unsigned int uiSize);

// @fnv 0x00e92910
template <>
void ShaderLibraryStringTemplateMap::SetValue(EntryType* pkEntry, const char* pcName,
                                             NiPointer<NiShaderLibrary> spRetainedObject) throw()
{
    if (m_bCopy)
    {
        unsigned int uiLen = strlen(pcName) + 1;
        char* pcCopy = (char*)NiMalloc(uiLen);
        pkEntry->m_key = pcCopy;
        strcpy_s(pcCopy, uiLen, pcName);
    }
    else
    {
        pkEntry->m_key = pcName;
    }
    pkEntry->m_val = spRetainedObject;
}

struct ShaderLibrary_92c40
{
    const char* FUN_00d47a30();
};
struct ReferenceObject_92c40
{
    virtual void Reserved();
    virtual void Release();
    volatile long referenceCount;
};
struct FUN_00e92c40_shell : NiD3DShaderFactory
{
    ShaderLibrary_92c40* NiD3DShaderFactory_GetFirstLibrary();
    void NiD3DShaderFactory_RemoveAllLibraries();
};
// @fnv 0x00e92c40
// src: XBOX_PDB 0x00e92c40
void FUN_00e92c40_shell::NiD3DShaderFactory_RemoveAllLibraries()
{
    if (!m_pShaderLibraryStorage)
        return;
    ShaderLibrary_92c40* current = NiD3DShaderFactory_GetFirstLibrary();
    if (current)
    {
        do
        {
            static_cast<ShaderLibraryMapBase*>(m_pShaderLibraryStorage)->RemoveAt(current->FUN_00d47a30());
            if (!m_pShaderLibraryStorage || !m_pShaderLibraryIterator)
                break;
            ReferenceObject_92c40* next = 0;
            const char* scratch;
            static_cast<ShaderLibraryMapBase*>(m_pShaderLibraryStorage)->GetNext(m_pShaderLibraryIterator, scratch, *reinterpret_cast<NiPointer<NiShaderLibrary>*>(&next));
            ReferenceObject_92c40* savedNext = *(ReferenceObject_92c40* volatile*)&next;
            if (savedNext && InterlockedDecrement(&savedNext->referenceCount) == 0)
                savedNext->Release();
            current = (ShaderLibrary_92c40*)savedNext;
        } while (current);
    }
    static_cast<ShaderLibraryMapBase*>(m_pShaderLibraryStorage)->RemoveAll();
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* criticalSection);

struct ShaderFactoryShutdown : NiD3DShaderFactory
{
    void NiD3DShaderFactory_RemoveAllLibraries();
    void FUN_00aa05a0();
    void UpdateFields_00e92dc0();
};

// @fnv 0x00e92dc0
// src: GUESS 0x00e92dc0 (confidence: low)
void ShaderFactoryShutdown::UpdateFields_00e92dc0()
{
    ShaderMapBase* shaderMap = static_cast<ShaderMapBase*>(m_pShaderMapStorage);
    *(void**)this = &kVtbl_NiD3DShaderFactory;
    if (shaderMap)
        shaderMap->RemoveAll();

    NiD3DShaderFactory_RemoveAllLibraries();

    if (m_pShaderMapStorage)
        delete static_cast<ShaderMapBase*>(m_pShaderMapStorage);
    if (m_pShaderLibraryStorage)
        delete static_cast<ShaderLibraryMapBase*>(m_pShaderLibraryStorage);

    m_pShaderMapStorage = 0;
    m_pShaderLibraryStorage = 0;
    m_pOwnerShader = 0;
    DeleteCriticalSection(m_kShaderMap);
    FUN_00aa05a0();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FUN_00d47a30_class
{
    void* m_ppVirtualMethodTable;
    long m_iObjectReferenceCount;
    void* FUN_00d47a30();
};
// SetAt owns the destruction of its by-value smart-pointer argument. Materialize
// just that argument's retained pointer here: VC9 otherwise adds caller-side
// temporary cleanup bookkeeping that is absent from this game's call site.
struct RetainedShaderLibraryArgument
{
    NiShaderLibrary* pointer;
    RetainedShaderLibraryArgument(NiShaderLibrary* library) : pointer(library)
    {
        InterlockedIncrement(reinterpret_cast<long volatile*>(&reinterpret_cast<NiRefObject*>(library)->m_uiRefCount));
    }
};

struct ShaderFactory_e92a40 : NiD3DShaderFactory
{
    void NiD3DShaderFactory_InsertLibrary(FUN_00d47a30_class* p);
};
// @fnv 0x00e92a40
// src: GAMEBRYO_LIB 0x00e92a40
void ShaderFactory_e92a40::NiD3DShaderFactory_InsertLibrary(FUN_00d47a30_class* p)
{
    if (p)
    {
        typedef void (__thiscall* SetLibraryAt)(ShaderLibraryMapBase*, const char*, RetainedShaderLibraryArgument);
        void (ShaderLibraryMapBase::*setAt)(const char*, NiPointer<NiShaderLibrary>) = &ShaderLibraryMapBase::SetAt;
        reinterpret_cast<SetLibraryAt&>(setAt)(static_cast<ShaderLibraryMapBase*>(m_pShaderLibraryStorage),
                                             static_cast<const char*>(p->FUN_00d47a30()),
                                             reinterpret_cast<NiShaderLibrary*>(p));
    }
}

extern "C" void __cdecl _NiFree_00aa10f0(void*);

template <>
__forceinline NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiPointer<NiShaderLibrary> >::~NiTMapBase() throw()
{
    RemoveAll();
    _NiFree_00aa10f0(m_ppkHashTable);
}

template <>
__forceinline NiTPointerMap<const char*, NiPointer<NiShaderLibrary> >::~NiTPointerMap() throw()
{
    RemoveAll();
}

// @fnv 0x00e925a0
template <>
NiTStringTemplateMap<NiTPointerMap<const char*, NiPointer<NiShaderLibrary> >,
                     NiPointer<NiShaderLibrary> >::~NiTStringTemplateMap()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; ++i)
        {
            EntryType* item = m_ppkHashTable[i];
            while (item)
            {
                EntryType* current = item;
                item = item->m_pkNext;
                _NiFree_00aa10f0(const_cast<char*>(current->m_key));
            }
        }
    }
}

extern "C" void _ReadWriteBarrier();
class ShaderRefObject
{
  public:
    virtual ~ShaderRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class ShaderFactoryView
{
  public:
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
    ShaderLibraryMapBase* m_pTaskMap;
    ShaderRefObject* GetShaderRefObject(const char* pcName) throw();
};
// Looks up a ShaderRefObject by name in m_pTaskMap and returns it, releasing the temporary reference in all cases.
// @fnv 0x00e92a70
ShaderRefObject* ShaderFactoryView::GetShaderRefObject(const char* pcName) throw()
{
    ShaderRefObject* spRetainedObject = 0;
    bool found = m_pTaskMap->GetAt(pcName, *reinterpret_cast<NiPointer<NiShaderLibrary>*>(&spRetainedObject));
    ShaderRefObject* p = spRetainedObject;
    _ReadWriteBarrier();
    if (found)
    {
        if (p && InterlockedDecrement(&p->m_uiRefCount) == 0)
            p->DeleteThis();
        return p;
    }
    if (p && InterlockedDecrement(&p->m_uiRefCount) == 0)
        p->DeleteThis();
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

class OwnerE92A
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    ShaderLibraryMapBase* m_pTaskMap;

    void NiD3DShaderFactory_RemoveLibrary(const char* pcName);
};

// Looks up pcName in m_pTaskMap; if found with refcount 2, removes it and decrements the reference, otherwise just decrements the reference.
// @fnv 0x00e92ae0
// src: XBOX_PDB 0x00e92ae0
void OwnerE92A::NiD3DShaderFactory_RemoveLibrary(const char* pcName)
{
    NiRefObject* pkVal = 0;
    bool bFound = m_pTaskMap->GetAt(pcName, *reinterpret_cast<NiPointer<NiShaderLibrary>*>(&pkVal));
    if (bFound && pkVal->m_uiRefCount == 2)
    {
        m_pTaskMap->RemoveAt(pcName);
        pkVal->DecRefCount();
        return;
    }
    if (pkVal)
        pkVal->DecRefCount();
}

namespace fnv_00e92b50 {
class ShaderRefObject
{
  public:
    virtual ~ShaderRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct ShaderResult
{
    ShaderRefObject* pointer;
};
class ShaderFactoryView
{
  public:
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
    void* m_pShaderLibraryIterator;
    ShaderLibraryMapBase* m_pShaderLibraryStorage;
    ShaderRefObject* NiD3DShaderFactory_GetFirstLibrary();
};
// Resets the iterator to the first map position, advances it once, releases the returned object's reference, and returns that pointer.
// @fnv 0x00e92b50
// src: GAMEBRYO_LIB 0x00e92b50
ShaderRefObject* ShaderFactoryView::NiD3DShaderFactory_GetFirstLibrary()
{
    ShaderLibraryMapBase* map = m_pShaderLibraryStorage;
    if (!map)
        return 0;
    {
        m_pShaderLibraryIterator = map->GetFirstPos();
        if (m_pShaderLibraryIterator)
        {
            const char* key;
            ShaderResult object = {0};
            map->GetNext(m_pShaderLibraryIterator, key, *reinterpret_cast<NiPointer<NiShaderLibrary>*>(&object));
            ShaderRefObject* result = static_cast<volatile ShaderResult&>(object).pointer;
            if (result != 0)
            {
                if (InterlockedDecrement(&result->m_uiRefCount) == 0)
                    result->DeleteThis();
            }
            return result;
        }
    }
    return 0;
}
}  // namespace fnv_00e92b50

struct S_00e92be0_Ref
{
    virtual void f0();
    virtual void f1();
    int unk04;
};

struct S_00e92be0_Factory
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
    ShaderLibraryMapBase* unk30;

    S_00e92be0_Ref* NiD3DShaderFactory_GetNextLibrary();
};

void S_00e92be0_Ref::f0()
{}

void S_00e92be0_Ref::f1()
{}

// Calls unk30->AdvanceIterator to fetch the next S_00e92be0_Ref, decrements its reference count, and returns the object or null.
// @fnv 0x00e92be0
// src: GAMEBRYO_LIB 0x00e92be0
S_00e92be0_Ref* S_00e92be0_Factory::NiD3DShaderFactory_GetNextLibrary()
{
    ShaderLibraryMapBase* callee = unk30;
    if (callee != 0 && unk2c != 0)
    {
        void* pOut = 0;
        const char* local4;

        callee->GetNext(*reinterpret_cast<void**>(&unk2c), local4, *reinterpret_cast<NiPointer<NiShaderLibrary>*>(&pOut));
        S_00e92be0_Ref* object = reinterpret_cast<S_00e92be0_Ref*>(*static_cast<void* volatile*>(&pOut));

        if (object != 0)
        {
            if (InterlockedDecrement(reinterpret_cast<long volatile*>(&object->unk04)) == 0)
            {
                object->f1();
            }
        }
        return object;
    }
    return 0;
}

struct ShaderRGB
{
    float r, g, b;
};
struct ShaderRGBA
{
    float r, g, b, a;
};
class ShaderMaterialCache;
struct ShaderMaterialSource
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    ShaderRGB diffuse;
    ShaderRGB specular;
    ShaderRGB* specularOverride;
    float glossiness;
    float alpha;
    unsigned int unk40;
    unsigned int revision;
    ShaderMaterialCache* cache;
};
extern ShaderRGB DAT_011f4998;

class ShaderMaterialCache : public NiMemObject
{
  public:
    ShaderRGBA ambient, emissive, diffuse, specular;
    float glossiness;
    unsigned int revision;
    ShaderMaterialCache(ShaderMaterialSource* material) : revision(0)
    {
        CopyColorIfChanged(material);
    }
    __declspec(noinline) bool CopyColorIfChanged(ShaderMaterialSource* material);
};

bool ShaderMaterialCache::CopyColorIfChanged(ShaderMaterialSource* material)
{
    if (revision == material->revision)
        return false;
    revision = material->revision;
    ShaderRGB* spec = material->specularOverride;
    if (!spec)
        spec = &material->specular;
    float alpha = material->alpha;
    specular.r = spec->r;
    specular.g = spec->g;
    specular.b = spec->b;
    specular.a = alpha;
    emissive.r = DAT_011f4998.r;
    emissive.g = DAT_011f4998.g;
    emissive.b = DAT_011f4998.b;
    emissive.a = alpha;
    ambient.r = DAT_011f4998.r;
    ambient.g = DAT_011f4998.g;
    ambient.b = DAT_011f4998.b;
    ambient.a = alpha;
    diffuse.r = material->diffuse.r;
    diffuse.g = material->diffuse.g;
    diffuse.b = material->diffuse.b;
    diffuse.a = alpha;
    glossiness = material->glossiness;
    return true;
}

// Creates or updates the ShaderMaterialCache for the material, copying colors if the revision changed, and sets m_shutdown when state changes.
// @fnv 0x00e940d0
void ShaderMaterialCacheSlot::UpdateShaderMaterialCache(void* parameter)
{
    ShaderMaterialSource* material = (ShaderMaterialSource*)parameter;
    ShaderMaterialCache* object = material->cache;
    if (!object)
    {
        object = new ShaderMaterialCache(material);
        material->cache = object;
        m_bDirty = true;
    }
    if (object->CopyColorIfChanged(material))
        m_bDirty = true;
    if (object != m_pCurrent)
    {
        m_bDirty = true;
        m_pCurrent = object;
    }
}

extern "C" void __cdecl NiShaderFactory_ReportError(int, int, const char*, ...);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" char UNK_010f0b84[];
extern "C" char UNK_010f0b20[];
extern "C" char UNK_010f0b54[];

class ShaderLibraryProducer
{
  public:
    virtual void Reserved0();
    virtual void Reserved1();
    virtual ShaderLibrary* CreateShader(ShaderRenderer*, const char*, unsigned int);
};
class Logger
{
  public:
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Log(int, const char*, int, int, int);
};
extern "C" Logger* DAT_011f6388;

class ShaderFactory
{
  public:
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual ShaderLibrary* AcquireShader(const char*, unsigned int);
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void RegisterShader(ShaderLibrary*, unsigned int);
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual ShaderLibraryProducer* GetVertexShaderConstantInterface();
    virtual ShaderLibraryProducer* GetPixelShaderConstantInterface();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    ShaderRenderer* m_pOwnerShader;
    int m_pShaderMapStorage;
    int m_pShaderLibraryIterator;
    int m_pShaderLibraryStorage;
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int m_kShaderMap;

    ShaderLibrary* NiD3DShaderFactory_RetrieveShader(const char* pcName, unsigned int uiImplementation, bool bReportFailure);
};
// Acquires a ShaderLibrary by name, creating and registering it via producer interfaces if not already present, and optionally logs a failure.
// @fnv 0x00e920a0
// src: XBOX_PDB 0x00e920a0
ShaderLibrary* ShaderFactory::NiD3DShaderFactory_RetrieveShader(const char* pcName, unsigned int uiImplementation, bool bReportFailure)
{
    if (!m_pOwnerShader)
    {
        if (DAT_011f6388)
            DAT_011f6388->Log(4, UNK_010f0b84, 0, 0, 0);
        return 0;
    }
    if (!pcName || !*pcName)
    {
        NiShaderFactory_ReportError(1, 0, UNK_010f0b20);
        return 0;
    }
    ShaderLibrary* pkShader = AcquireShader(pcName, uiImplementation);
    if (!pkShader)
    {
        void* pCriticalSection = &m_kShaderMap;
        EnterCriticalSection(pCriticalSection);
        ShaderLibraryProducer* pkLibrary = GetVertexShaderConstantInterface();
        pkShader = AcquireShader(pcName, uiImplementation);
        if (!pkShader)
        {
            while (pkLibrary)
            {
                pkShader = pkLibrary->CreateShader(m_pOwnerShader, pcName, uiImplementation);
                if (pkShader)
                {
                    RegisterShader(pkShader, uiImplementation);
                    m_pOwnerShader->NiXenonRenderer_RegisterD3DShader(pkShader);
                    pkShader->FUN_00e818d0(m_pOwnerShader);
                    break;
                }
                pkLibrary = GetPixelShaderConstantInterface();
            }
        }
        LeaveCriticalSection(pCriticalSection);
    }
    if (bReportFailure && !pkShader)
        NiShaderFactory_ReportError(1, 0, UNK_010f0b54, pcName, uiImplementation);
    return pkShader;
}

// Today's tree does not provide the CRITICAL_SECTION typedef (windows.h include is
// dropped when merged); declare the lock functions the way the tree does and use a
// stand-in with the 24-byte x86 CRITICAL_SECTION layout.
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct FUN_00e92330_critsec
{
    char data[0x18];
};

struct FUN_00e92330_item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Test(unsigned int p);
};

struct FUN_00e92330_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual FUN_00e92330_item* Match(unsigned int a, unsigned int b);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual FUN_00e92330_item* GetFirst();
    virtual FUN_00e92330_item* GetNext();
    unsigned int unk04[31];
    FUN_00e92330_critsec m_lock;
    bool NiD3DShaderFactory_ReleaseShaderFromLibrary(unsigned int a1);
};

typedef FUN_00e92330_item*(__thiscall* FUN_00e92330_match)(FUN_00e92330_cls*, unsigned int, unsigned int);

// Checks whether the collection contains the item identified by a1, using a virtual Match lookup and a Test predicate under a critical section.
// @fnv 0x00e92330
// src: XBOX_PDB 0x00e92330
bool FUN_00e92330_cls::NiD3DShaderFactory_ReleaseShaderFromLibrary(unsigned int apItem)
{
    if (apItem == 0)
    {
        return false;
    }
    unsigned int key = reinterpret_cast<unsigned int>(((NiShader*)apItem)->GetFilename().m_kHandle);
    void** pVTable = *(void***)this;
    void** pMatchSlot = pVTable + 3;
    unsigned int ref = reinterpret_cast<GetShaderImplementation>(&NiD3DShaderProgram_GetName)((NiShader*)apItem);
    FUN_00e92330_item* r = ((FUN_00e92330_match)*pMatchSlot)(this, key, ref);
    if (!(r && (unsigned int)r == apItem))
    {
        unsigned int key2 = reinterpret_cast<unsigned int>(((NiShader*)apItem)->GetFilename().m_kHandle);
        r = ((FUN_00e92330_match)(*(void***)this)[3])(this, key2, 0xffffffff);
        if (!(r && (unsigned int)r == apItem))
        {
            return false;
        }
    }
    EnterCriticalSection(&m_lock);
    FUN_00e92330_item* pItem = GetFirst();
    bool result = false;
    while (pItem)
    {
        if (pItem->Test(apItem))
        {
            result = true;
            break;
        }
        pItem = GetNext();
    }
    LeaveCriticalSection(&m_lock);
    return result;
}
