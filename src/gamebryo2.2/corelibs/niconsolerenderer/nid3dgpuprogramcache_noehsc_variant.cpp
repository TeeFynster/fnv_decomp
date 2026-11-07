
// to their real unit once identified.

#include "nid3dgpuprogramcache_decls.h"
#include "../../../../include/MemoryHeap.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiPointer.h"
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern char* EmptyFS;
extern MemoryManager g_memoryManager;
void Object_ProcessEntries_00a644a0(char** p);
const char* __cdecl NiD3DGPUProgramCache_GetPlatformSpecificCodeID();
extern "C" void* g_01270920;
void* __cdecl NiGPUProgramCache_GetRTTI();
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
void __cdecl _delete(void*, unsigned int);
struct S00e8ea20
{
    char _pad[0x44];
    char* _s;
    void FUN_00ee9a60();
    void* ReleaseAndDestroy(unsigned int);
};
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
void __stdcall AssignValueHolder(ValueHolder* destination, char** sourceText, ObjectReference incoming);
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

class NiD3DPass;

namespace sc1d790 {

extern MemoryManager DAT_011f6238;

}

inline void* operator new[](unsigned int uiSize, MemoryManager& allocator)
{
    return allocator.Game_DoHeapAlloc(uiSize);
}

namespace sc1d790 {

// @fnv 0x00c1d790
// src: XBOX_PDB 0x00c1d790
NiPointer<NiD3DPass>* NiTObjectArray_NiPointer_NiScreenTexture_NiTObjectArray_NiPointer_NiScreenTexture(unsigned int ItemUpdateArray)
{
    return new (DAT_011f6238) NiPointer<NiD3DPass>[ItemUpdateArray];
}

}
