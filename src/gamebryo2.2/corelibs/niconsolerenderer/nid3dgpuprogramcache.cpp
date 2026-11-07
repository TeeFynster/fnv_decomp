// gamebryo2.2/corelibs/niconsolerenderer/nid3dgpuprogramcache.cpp: NiD3DGPUProgramCache, NiFixedString, Holder, ShaderLoader8e (15 functions)

#include "nid3dgpuprogramcache_decls.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiFile.h"
#include "../../../../include/NiFixedString.h"
// Returns the vertex shader profile string matching fnv_particle_shader_renderer_level, or null for other values.
// @fnv 0x00b4f3e0
const char* NiD3DGPUProgramCache::GetVertexShaderProfile()
{
    switch (fnv_particle_shader_renderer_level)
    {
    case 1:
        return "vs_1_1";
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return "vs_2_0";
    case 7:
        return "vs_3_0";
    default:
        return 0;
    }
}
// Returns the pixel shader profile string for the selected shader level, or 0 for unknown levels.
// @fnv 0x00b4f380
const char* NiD3DGPUProgramCache::GetPixelShaderProfile(bool usePixelLevel)
{
    unsigned int level = usePixelLevel ? DAT_011f91bc : fnv_particle_shader_renderer_level;
    switch (level)
    {
    case 1:
        return "ps_1_3";
    case 2:
        return "ps_2_0";
    case 3:
    case 5:
        return "ps_2_a";
    case 4:
    case 6:
        return "ps_2_b";
    case 7:
        return "ps_3_0";
    default:
        return 0;
    }
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern char* EmptyFS;
extern MemoryManager g_memoryManager;

// @fnv 0x00a644a0
// src: GUESS 0x00a644a0 (confidence: low)
void Object_ProcessEntries_00a644a0(char** p)
{
    if (p)
    {
        int n = ((int*)p)[-1];
        char** ppElement = p + n;
        while (--n >= 0)
        {
            --ppElement;
            if (*ppElement != EmptyFS)
                InterlockedDecrement((volatile long*)(*ppElement - 8));
        }
        g_memoryManager._DeallocateAlias((int*)p - 1);
    }
}

// @fnv 0x00e8dd60
// src: COMMUNITY 0x00e8dd60
const char* __cdecl NiD3DGPUProgramCache_GetPlatformSpecificCodeID()
{
    return "hlsl";
}

extern "C" void* g_01270920;

// @fnv 0x00e8ea10
// src: COMMUNITY 0x00e8ea10
void* __cdecl NiGPUProgramCache_GetRTTI()
{
    return &g_01270920;
}

struct RefCounted
{
    virtual void f0();
    virtual void f1();
    volatile long m_ref;
};
struct Holder
{
    RefCounted** m_base;
    unsigned int m_uiItemCount;
    unsigned int m_extra;
    void ReleaseAll();
};
// @fnv 0x00e8de70
void Holder::ReleaseAll()
{
    unsigned int i = 0;
    if (m_uiItemCount > i)
    {
        do
        {
            RefCounted** ppEntry = &m_base[i];
            RefCounted* p = *ppEntry;
            if (p)
            {
                if (InterlockedDecrement(&p->m_ref) == 0)
                    p->f1();
                *ppEntry = 0;
            }
            ++i;
        } while (i < m_uiItemCount);
        m_extra = 0;
        return;
    }
    m_extra = i;
}

void __cdecl _delete(void*, unsigned int);
struct S00e8ea20
{
    char _pad[0x44];
    char* _s;
    void FUN_00ee9a60();
    void* ReleaseAndDestroy(unsigned int);
};
// Decrements the refcount at _s-8 if _s is set, calls FUN_00ee9a60, and frees this with _delete when f has bit 0 set; returns this.
// @fnv 0x00e8ea20
void* S00e8ea20::ReleaseAndDestroy(unsigned int auiFlags)
{
    if (_s != EmptyFS)
        InterlockedDecrement((volatile long*)(_s - 8));
    FUN_00ee9a60();
    if (auiFlags & 1)
        _delete(this, 0x48);
    return this;
}

__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern char* EmptyFS;
struct ValueHolder
{
    void* m_pOwnerObject;
    char* m_pText;
    RefCounted* m_object;
};
struct ObjectReference
{
    RefCounted* m_object;
};
// Assigns a text pointer and a ref-counted object into a ValueHolder, adjusting reference counts and releasing the previous object.
// @fnv 0x00e8ded0
void __stdcall AssignValueHolder(ValueHolder* destination, char** sourceText, ObjectReference incoming)
{
    char* text = *sourceText;
    if (destination->m_pText != text)
    {
        if (text != EmptyFS)
            InterlockedIncrement((volatile long*)(text - 8));
        if (destination->m_pText != EmptyFS)
            InterlockedDecrement((volatile long*)(destination->m_pText - 8));
        destination->m_pText = text;
    }
    RefCounted* previous = destination->m_object;
    if (previous != incoming.m_object)
    {
        if (previous && InterlockedDecrement(&previous->m_ref) == 0)
            previous->f1();
        destination->m_object = incoming.m_object;
        if (incoming.m_object)
            InterlockedIncrement(&incoming.m_object->m_ref);
    }
    if (incoming.m_object)
    {
        RefCounted* releasing = incoming.m_object;
        if (InterlockedDecrement(&releasing->m_ref) == 0)
            releasing->f1();
    }
}

class E8DF70BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(E8DF70BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(E8DF70BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

template <class T>
inline void E8DF70BinaryStreamSave(E8DF70BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

class E8DF70Shader
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual const char** GetName();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual unsigned int GetCodeSize();
    virtual const char* GetCode();
};

class E8DF70Writer
{
  public:
    void WriteName(E8DF70BinaryStream& kStream, const char* pcName);
    bool WriteShader(E8DF70BinaryStream& kStream, E8DF70Shader* pkShader);
};

// Writes the shader's name, code size and code bytes to the stream, returning false if the shader is null.
// @fnv 0x00e8df70
bool E8DF70Writer::WriteShader(E8DF70BinaryStream& kStream, E8DF70Shader* pkShader)
{
    if (!pkShader)
        return false;

    WriteName(kStream, *pkShader->GetName());
    unsigned int uiCodeSize = pkShader->GetCodeSize();
    const char* pcCode = pkShader->GetCode();
    E8DF70BinaryStreamSave(kStream, &uiCodeSize);
    E8DF70BinaryStreamSave(kStream, pcCode, uiCodeSize);
    return true;
}

__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct S_00e8e1d0_Ptr
{
    RefCounted* p;
    S_00e8e1d0_Ptr(const S_00e8e1d0_Ptr& o) throw() : p(o.p)
    {
        if (p)
            InterlockedIncrement(&p->m_ref);
    }
    void Release() throw()
    {
        if (p)
        {
            RefCounted* q = p;
            if (!InterlockedDecrement(&q->m_ref))
                q->f1();
        }
    }
};
struct S_00e8e1d0_Node
{
    S_00e8e1d0_Node* next;
    unsigned key;
    S_00e8e1d0_Ptr val;
};
struct S_00e8e1d0_Map
{
    virtual void vf0();
    virtual S_00e8e1d0_Node* Alloc() throw();
    unsigned nBuckets;
    S_00e8e1d0_Node** buckets;
    unsigned count;
    void AssignValueHolder(S_00e8e1d0_Node* n, const unsigned* k, S_00e8e1d0_Ptr v) throw();
    void InsertOrAssign(const unsigned* k, S_00e8e1d0_Ptr v) throw();
};
// @fnv 0x00e8e1d0
void S_00e8e1d0_Map::InsertOrAssign(const unsigned* pKey, S_00e8e1d0_Ptr v)
{
    unsigned i = *pKey % nBuckets;
    for (S_00e8e1d0_Node* n = buckets[i]; n; n = n->next)
    {
        if (*pKey == n->key)
        {
            AssignValueHolder(n, pKey, v);
            v.Release();
            return;
        }
    }
    S_00e8e1d0_Node* n = Alloc();
    AssignValueHolder(n, pKey, v);
    n->next = buckets[i];
    buckets[i] = n;
    count++;
    v.Release();
}

extern int DAT_0101dce4;
extern long DAT_011f4400;

void __cdecl ReleaseObjectArray(void* apData);
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00e8eb10_cls
{
    int m_vptr;
    int unk04;
    RefCounted* m_08;
    Holder m_0c;

    FUN_00e8eb10_cls* Destroy(unsigned char acFlags);
};

// Releases the holder and ref-counted object, resets the vtable, decrements a global counter, and frees this if the low flag bit is set.
// @fnv 0x00e8eb10
FUN_00e8eb10_cls* FUN_00e8eb10_cls::Destroy(unsigned char acFlags)
{
    m_0c.ReleaseAll();
    ReleaseObjectArray(m_0c.m_base);
    RefCounted* pRef = m_08;
    if (pRef != 0)
    {
        if (InterlockedDecrement(&pRef->m_ref) == 0)
        {
            pRef->f1();
        }
    }
    m_vptr = (int)&DAT_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x18);
    }
    return this;
}

__declspec(nothrow) int FUN_00aa1360(const char*, const char*);
__declspec(dllimport) __declspec(nothrow) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) __declspec(nothrow) long __stdcall InterlockedIncrement(volatile long*);
extern char* EmptyFS;
inline NiFixedString& NiFixedString::operator=(const char* text)
{
    if (m_kHandle != text)
    {
        char* old = m_kHandle;
        m_kHandle = NiGlobalStringTable::AddString(text);
        NiGlobalStringTable::DecRefCount(old);
    }
    return *this;
}

inline NiFixedString& NiFixedString::operator=(const NiFixedString& other)
{
    char* incoming = other.m_kHandle;
    if (m_kHandle != incoming)
    {
        NiGlobalStringTable::IncRefCount(incoming);
        char* outgoing = m_kHandle;
        NiGlobalStringTable::DecRefCount(outgoing);
        m_kHandle = incoming;
    }
    return *this;
}

inline bool NiFixedString::operator==(const char* text) const
{
    if (m_kHandle == text)
        return true;
    if (!text || !m_kHandle)
        return false;
    return FUN_00aa1360(m_kHandle, text) == 0;
}

inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}


struct W20Profiles
{
    NiFixedString* data;
    unsigned int capacity, count, unk0c, unk10;
    __declspec(nothrow) void ResizeStringArray(unsigned int);
    __declspec(nothrow) void PushBack(const NiFixedString& value)
    {
        if (count == capacity)
            ResizeStringArray(capacity > 0 ? capacity * 2 : 1);
        data[count++] = value;
    }
};
struct W20Base
{
    virtual void foo();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    NiFixedString name;
    unsigned int unk1c, unk20;
    NiFixedString profile;
    W20Profiles profiles;
    __declspec(nothrow) W20Base(int, int, int);
    __declspec(nothrow) void SetString(const NiFixedString&);
    __declspec(nothrow) void LoadCacheFile();
};
struct FUN_00e8e450 : W20Base
{
    int type;
    bool flag;
    NiFixedString suffix;
    virtual void foo();
    __declspec(nothrow) FUN_00e8e450(int, const char*, int, const NiFixedString&, const char*, int, bool, int, bool);
};
__declspec(nothrow) void FUN_00a305b0(char*, unsigned int, const char*, ...);
// Builds a shader cache filename from path, requested profile and "DX9", sets name/profile, fills the fallback profile list by kind, and loads if requested.
// @fnv 0x00e8e450
__declspec(nothrow) FUN_00e8e450::FUN_00e8e450(int a, const char* apcSource, int kind, const NiFixedString& arRequested,
                                               const char* apcPath, int b, bool use, int c, bool load)
    : W20Base(a, b, c)
{
    flag = use;
    type = kind;
    suffix = apcPath;
    char filename[260];
    FUN_00a305b0(filename, 260, "%s_%s_%s.cache", apcPath, arRequested.m_kHandle, "DX9");
    name = (const char*)filename;
    SetString(apcSource);
    profile = arRequested;
    if (kind == 0)
    {
        if (profile == "vs_1_1")
        {
            profiles.PushBack("vs_1_1");
        }
        else if (profile == "vs_2_0")
        {
            profiles.PushBack("vs_2_0");
            profiles.PushBack("vs_1_1");
        }
        else if (profile == "vs_2_a")
        {
            profiles.PushBack(NiFixedString("vs_2_a"));
            profiles.PushBack(NiFixedString("vs_2_0"));
            profiles.PushBack(NiFixedString("vs_1_1"));
        }
        else if (profile == "vs_3_0")
        {
            profiles.PushBack(NiFixedString("vs_3_0"));
            profiles.PushBack(NiFixedString("vs_2_a"));
            profiles.PushBack(NiFixedString("vs_2_0"));
            profiles.PushBack(NiFixedString("vs_1_1"));
        }
    }
    else if (kind == 2)
    {
        if (profile == "ps_1_1")
            profiles.PushBack(NiFixedString("ps_1_1"));
        else if (profile == "ps_1_2")
        {
            profiles.PushBack(NiFixedString("ps_1_2"));
            profiles.PushBack(NiFixedString("ps_1_1"));
        }
        else if (profile == "ps_1_3")
        {
            profiles.PushBack(NiFixedString("ps_1_3"));
            profiles.PushBack(NiFixedString("ps_1_2"));
            profiles.PushBack(NiFixedString("ps_1_1"));
        }
        else if (profile == "ps_1_4")
        {
            profiles.PushBack(NiFixedString("ps_1_4"));
            profiles.PushBack(NiFixedString("ps_1_3"));
            profiles.PushBack(NiFixedString("ps_1_2"));
            profiles.PushBack(NiFixedString("ps_1_1"));
        }
        else if (profile == "ps_2_0")
        {
            profiles.PushBack(NiFixedString("ps_2_0"));
            profiles.PushBack(NiFixedString("ps_1_4"));
            profiles.PushBack(NiFixedString("ps_1_3"));
            profiles.PushBack(NiFixedString("ps_1_2"));
            profiles.PushBack(NiFixedString("ps_1_1"));
        }
        else if (profile == "ps_2_a")
        {
            profiles.PushBack(NiFixedString("ps_2_a"));
            profiles.PushBack(NiFixedString("ps_2_0"));
            profiles.PushBack(NiFixedString("ps_1_4"));
            profiles.PushBack(NiFixedString("ps_1_3"));
            profiles.PushBack(NiFixedString("ps_1_2"));
            profiles.PushBack(NiFixedString("ps_1_1"));
        }
        else if (profile == "ps_2_b")
        {
            profiles.PushBack(NiFixedString("ps_2_b"));
            profiles.PushBack(NiFixedString("ps_2_0"));
            profiles.PushBack(NiFixedString("ps_1_4"));
            profiles.PushBack(NiFixedString("ps_1_3"));
            profiles.PushBack(NiFixedString("ps_1_2"));
            profiles.PushBack(NiFixedString("ps_1_1"));
        }
        else if (profile == "ps_3_0")
        {
            profiles.PushBack(NiFixedString("ps_3_0"));
            profiles.PushBack(NiFixedString("ps_2_a"));
            profiles.PushBack(NiFixedString("ps_2_0"));
            profiles.PushBack(NiFixedString("ps_1_4"));
            profiles.PushBack(NiFixedString("ps_1_3"));
            profiles.PushBack(NiFixedString("ps_1_2"));
            profiles.PushBack(NiFixedString("ps_1_1"));
        }
    }
    if (load && apcSource)
        LoadCacheFile();
}

struct ShaderStream8e
{
    virtual void v00();
    virtual void v01();
    virtual void Seek(int iNumBytes);
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(ShaderStream8e* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void LoadBinary8e(ShaderStream8e* pkStream, T* pkValue, unsigned int ItemUpdateArray)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pkValue, ItemUpdateArray * sizeof(T), &uiSize, 1);
}
struct ShaderBuffer8e
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void* __stdcall GetBufferPointer();
    virtual unsigned long __stdcall GetBufferSize();
};
struct ShaderProgram8e;
struct ShaderFactory8e
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
    virtual ShaderProgram8e* CreateVertexShaderProgram(ShaderBuffer8e* pkCode, unsigned int uiCodeSize,
                                                       const char* pcName, const char* pcEntryPoint,
                                                       const char* pcShaderTarget, void* pvDecl, unsigned int uiUsage,
                                                       bool bSoftwareVP, bool bRecoverable);
    virtual ShaderProgram8e* CreatePixelShaderProgram(ShaderBuffer8e* pkCode, unsigned int uiCodeSize,
                                                      const char* pcName, const char* pcEntryPoint,
                                                      const char* pcShaderTarget, bool bRecoverable);
};
struct ShaderLibrary8e
{
    void __thiscall AddShader();
    void __thiscall RegisterShader();
};
ShaderLibrary8e* __stdcall NiD3DShaderProgramFactory_GetInstance(ShaderProgram8e* pkProgram);
long __stdcall D3DXCreateBuffer_0(unsigned int uiNumBytes, ShaderBuffer8e** ppkBuffer);
extern const char* DAT_0126fa48;
extern const char* DAT_0126fa40;
extern ShaderFactory8e* DAT_0126fa3c;

struct ShaderLoader8e
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual const NiFixedString& GetLoaderName();

    void NiGPUProgramCache_LoadStringA(ShaderStream8e* pkStream, char* pcBuffer, unsigned int uiMaxLen);
    bool LoadShaderProgram(ShaderStream8e* pkStream, const NiFixedString& kName, ShaderProgram8e** ppkProgram,
                           bool bSkip);
};

// @fnv 0x00e8e000
bool ShaderLoader8e::LoadShaderProgram(ShaderStream8e* pkStream, const NiFixedString& kName,
                                       ShaderProgram8e** ppkProgram, bool bSkip)
{
    *ppkProgram = 0;
    unsigned int uiCodeSize = 0;
    char acType[256];
    NiGPUProgramCache_LoadStringA(pkStream, acType, 0x100);

    bool bVertex;
    if (FUN_00aa1360(acType, DAT_0126fa48) == 0)
        bVertex = true;
    else if (FUN_00aa1360(acType, DAT_0126fa40) == 0)
        bVertex = false;
    else
        return false;

    LoadBinary8e(pkStream, &uiCodeSize, 1);
    if (bSkip)
    {
        pkStream->Seek(uiCodeSize);
        return true;
    }

    ShaderBuffer8e* pkBuffer = 0;
    if (D3DXCreateBuffer_0(uiCodeSize, &pkBuffer) < 0)
        return false;

    LoadBinary8e(pkStream, (char*)pkBuffer->GetBufferPointer(), uiCodeSize);

    ShaderFactory8e* pkFactory = DAT_0126fa3c;
    if (bVertex)
    {
        *ppkProgram = pkFactory->CreateVertexShaderProgram(pkBuffer, uiCodeSize, kName, "Main", GetLoaderName(), 0, 0,
                                                           false, false);
        if (*ppkProgram)
            NiD3DShaderProgramFactory_GetInstance(*ppkProgram)->AddShader();
    }
    else
    {
        *ppkProgram = pkFactory->CreatePixelShaderProgram(pkBuffer, uiCodeSize, kName, "Main", GetLoaderName(), false);
        if (*ppkProgram)
            NiD3DShaderProgramFactory_GetInstance(*ppkProgram)->RegisterShader();
    }
    pkBuffer->Release();
    return true;
}

#include <string.h>
bool __cdecl NiGPUProgramCache_ValidateDirectory();
void __cdecl fnv_StandardizeFilePath(char* path);
bool __cdecl NiFile_DirectoryExists(const char* dir);
bool __cdecl NiFile_CreateDirectoryRecursive(const char* dir);

inline unsigned int NiBinaryStream::Write(const void* pvBuffer, unsigned int uiBytes)
{
    unsigned int uiSize = 1;
    unsigned int uiBytesWritten =
        (*(NIBINARYSTREAM_WRITEFN*)((char*)this + 0x0c))(this, pvBuffer, uiBytes, &uiSize, 1);
    *(unsigned int*)((char*)this + 4) += uiBytesWritten;
    return uiBytesWritten;
}

// Writes pcText to pcFileName if the preceding checks pass and the file opens, then returns true.
// @fnv 0x00e8dd70
bool __stdcall WriteTextToFile(const char* pcFileName, const char* pcText)
{
    if (NiGPUProgramCache_ValidateDirectory())
    {
        char acDir[260];
        strcpy_s(acDir, 260, pcFileName);
        fnv_StandardizeFilePath(acDir);
        char* pcSlash = strrchr(acDir, '/');
        if (pcSlash || (pcSlash = strrchr(acDir, '\\')) != 0)
            *pcSlash = 0;

        if (NiFile_DirectoryExists(acDir) || NiFile_CreateDirectoryRecursive(acDir))
        {
            NiFile* pkFile = NiFile::GetFile(pcFileName, NiFile::WRITE_ONLY, 0x8000);
            if (pkFile)
            {
                pkFile->Write(pcText, strlen(pcText));
                delete pkFile;
                return true;
            }
        }
    }
    return false;
}

void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl _NiFree_00aa10f0(void* p);
void* __cdecl Object_DispatchCommandFour(unsigned int size);
__declspec(nothrow) void FUN_00a305b0(char*, unsigned int, const char*, ...);
char* __cdecl FUN_00a5b690(const char* name);
void* __cdecl NiD3DShaderProgramFactory_CreateVertexShaderFromBuffer(char* text, unsigned int len, char* path, char* path2, const char* entry, int target, int a,
                           int b, int c, int d);
void* __cdecl NiD3DShaderProgramFactory_CreatePixelShaderFromBuffer(char* text, unsigned int len, char* path, char* path2, const char* entry, int target, int d);

struct RefCountedBase
{
    virtual void f0();
    virtual void f1();
    volatile long m_ref;
};

struct ScopedRef
{
    RefCountedBase* m_p;
    void FUN_00a5f860(RefCountedBase* p);
};

struct NodeAdder
{
    void FUN_00e8ea60(RefCountedBase** elem);
};

struct S00e8eb80_Ptr
{
    RefCountedBase* m_p;
    S00e8eb80_Ptr& operator=(RefCountedBase* const& p)
    {
        RefCountedBase* old = m_p;
        if (old != p)
        {
            if (old)
            {
                if (InterlockedDecrement(&old->m_ref) == 0)
                {
                    old->f1();
                }
            }
            RefCountedBase* np = p;
            m_p = np;
            InterlockedIncrement(&np->m_ref);
        }
        return *this;
    }
};

struct ShaderNode : RefCountedBase
{
    S00e8eb80_Ptr m_08;
    NodeAdder m_0c;
    ShaderNode* FUN_00e8ead0();
};

struct NiPointerVal
{
    RefCountedBase* m_p;
    NiPointerVal(RefCountedBase* p) : m_p(p)
    {
        if (p)
        {
            InterlockedIncrement(&p->m_ref);
        }
    }
};

// Exe 0x00e8eb80: unit-local ShaderMap view; declarations and layout are preserved.
struct ShaderCacheHashMap
{ // distinct from NiTexturingProperty::ShaderMap: insertion 0x00e8e1d0 operates on buckets/count at +4/+8/+12 with two virtual slots, not texture-map vftable 0x0109c4ec.
    virtual void vf0();
    virtual ShaderNode* Alloc();
    unsigned int nBuckets;
    void** buckets;
    unsigned int count;
    void InsertOrAssign(const unsigned int* k, NiPointerVal v);
};

struct ArrayHolder
{
    RefCountedBase** m_base;
    unsigned int unk04;
    unsigned int m_uiItemCount;
    void ReleaseAll();
};

class S00e8eb80_Obj
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual const char** vfn58();
    virtual void vfn5C();
    virtual const char* vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual bool vfn7C(RefCountedBase* obj, ArrayHolder* refs);
    virtual void vfn80();
    virtual void vfn84(ShaderNode* node, char** value);
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98(const char* path, const char* text);

    int unk04;
    ShaderCacheHashMap m_08;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    int m_24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned char m_38;
    unsigned char unk39;
    unsigned char m_3a;
    unsigned char unk3b;
    int m_3c;
    unsigned char m_40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    const char* m_44;

    RefCountedBase* NiD3DGPUProgramCache_GenerateProgram(const char* name, const char* src, ArrayHolder* refs);
};

// Compiles shader source into a ShaderNode, adds refs, and inserts it into the ShaderMap keyed by name.
// @fnv 0x00e8eb80
// src: XBOX_PDB 0x00e8eb80
RefCountedBase* S00e8eb80_Obj::NiD3DGPUProgramCache_GenerateProgram(const char* name, const char* apSource, ArrayHolder* refs)
{
    if (!m_3a)
    {
        char path[0x104];
        ScopedRef pObj;
        pObj.m_p = 0;

        unsigned int srcLen = strlen(apSource);
        char* text = (char*)_NiMalloc_00aa1070(srcLen + 0x208);

        if (m_3c == 0)
        {
            const char** stem = vfn58();
            const char* ext = vfn60();
            FUN_00a305b0(path, 0x104, "%s\\%s\\%s-V.%s", *stem, m_44, name, ext);
            FUN_00a305b0(text, srcLen + 0x208, "#line 2 \"%s\"\n%s", path, apSource);
            unsigned int len = strlen(text);
            int tgt = m_24;
            RefCountedBase* r = (RefCountedBase*)NiD3DShaderProgramFactory_CreateVertexShaderFromBuffer(text, len, path, path, "Main", tgt, 0, 0, 0, 1);
            pObj.FUN_00a5f860(r);
        }
        else if (m_3c == 2)
        {
            const char** stem = vfn58();
            const char* ext = vfn60();
            FUN_00a305b0(path, 0x104, "%s\\%s\\%s-P.%s", *stem, m_44, name, ext);
            FUN_00a305b0(text, srcLen + 0x208, "#line 2 \"%s\"\n%s", path, apSource);
            unsigned int len = strlen(text);
            int tgt = m_24;
            RefCountedBase* r = (RefCountedBase*)NiD3DShaderProgramFactory_CreatePixelShaderFromBuffer(text, len, path, path, "Main", tgt, 1);
            pObj.FUN_00a5f860(r);
        }

        if (m_40 != 0)
        {
            vfn98(path, text);
        }

        RefCountedBase* obj = pObj.m_p;
        if (obj != 0 && vfn7C(obj, refs))
        {
            ShaderNode* blk = (ShaderNode*)Object_DispatchCommandFour(0x18);
            ShaderNode* node = blk != 0 ? blk->FUN_00e8ead0() : 0;

            for (unsigned int i = 0; i < refs->m_uiItemCount; i++)
            {
                node->m_0c.FUN_00e8ea60(&refs->m_base[i]);
            }

            node->m_08 = pObj.m_p;
            char* value = !name ? EmptyFS : FUN_00a5b690(name);

            if (m_38 != 0)
            {
                vfn84(node, &value);
            }

            m_08.InsertOrAssign((const unsigned int*)&value, node);
            if (value != EmptyFS)
            {
                InterlockedDecrement((volatile long*)(value - 8));
            }
            obj = pObj.m_p;
        }

        _NiFree_00aa10f0(text);

        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->m_ref) == 0)
            {
                obj->f1();
            }
            return obj;
        }
        refs->ReleaseAll();
    }
    return 0;
}
