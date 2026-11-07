
#include <windows.h>
#include <d3d9.h>

#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTPointerMap.h"

#include "../../../../include/NiTexturingProperty.h"
#include "../../../../include/NiTexture.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiRenderer.h"

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiD3DShaderProgramFactory.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiDX9RenderState.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiDX9DynamicTextureData.h"
#include "../../../../include/NiDX9RenderedCubeMapData.h"
#include "../../../../include/NiDX9Renderer.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPixelFormat.h"
#include "../../../../include/NiPixelFormatStandIn.h"
#include "../../../../include/NiSequence.h"
#include "../../../../include/NiShader.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/Pair.h"
#include "../../../../include/StrArr.h"

#include "../../../../include/NiD3DShader.h"
#include "../../../../include/NiDX9ErrorShader.h"
#include "../../../../include/NiRenderedCubeMap.h"

// Keep the unit declarations here; the shared headers provide NiTPointerAllocator.
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern void* __cdecl _NiMalloc(unsigned int size);
extern "C" void* __cdecl fnv_zlib_memset(void* destination, int value, unsigned long size);

extern volatile long DAT_011f4400;
extern unsigned char kVtbl_NiRefObject;
extern unsigned char kVtbl_NiDX9IndexBufferManager;
extern unsigned char DAT_010f02b0;
extern unsigned char DAT_010f02d0;

typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*> FnvMap;

class FnvTextureReference
{
  public:
    void** m_ppVirtualMethodTable;
};

class FnvTextureData
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    FnvTextureReference* m_pkTexture;
    unsigned int m_u0c;
    unsigned int m_u10;
    unsigned int m_u14;
    unsigned int m_u18;
    NiTPointerMap<const char*, NiShader*> m_map1;
    NiTPointerMap<const char*, NiShader*> m_map2;
    NiTPointerMap<const char*, NiShader*> m_map3;
    unsigned char m_unused[0x48];

    FnvTextureData* AllocateData(FnvTextureReference* texture);
};

// Initializes the object's vtables, three hash maps, stores the texture, calls its virtual method, and clears the maps.
// @fnv 0x00e8fb20
FnvTextureData* FnvTextureData::AllocateData(FnvTextureReference* texture)
{
    m_ppVirtualMethodTable = reinterpret_cast<void**>(&kVtbl_NiRefObject);
    m_uiRefCount = 0;
    InterlockedIncrement(&DAT_011f4400);

    m_ppVirtualMethodTable = reinterpret_cast<void**>(&kVtbl_NiDX9IndexBufferManager);

    FnvMap* map1 = &m_map1;
    *reinterpret_cast<void***>(map1) = reinterpret_cast<void**>(&DAT_010f02b0);
    map1->m_uiHashSize = 0x25;
    map1->m_kItemCount.m_uiCount = 0;
    map1->m_ppkHashTable = static_cast<FnvMap::EntryType**>(_NiMalloc(0x94));
    fnv_zlib_memset(map1->m_ppkHashTable, 0, map1->m_uiHashSize * 4);
    *reinterpret_cast<void***>(map1) = reinterpret_cast<void**>(&DAT_010f02d0);

    FnvMap* map2 = &m_map2;
    *reinterpret_cast<void***>(map2) = reinterpret_cast<void**>(&DAT_010f02b0);
    map2->m_uiHashSize = 0x25;
    map2->m_kItemCount.m_uiCount = 0;
    map2->m_ppkHashTable = static_cast<FnvMap::EntryType**>(_NiMalloc(0x94));
    fnv_zlib_memset(map2->m_ppkHashTable, 0, map2->m_uiHashSize * 4);
    *reinterpret_cast<void***>(map2) = reinterpret_cast<void**>(&DAT_010f02d0);

    FnvMap* map3 = &m_map3;
    *reinterpret_cast<void***>(map3) = reinterpret_cast<void**>(&DAT_010f02b0);
    map3->m_uiHashSize = 0x25;
    map3->m_kItemCount.m_uiCount = 0;
    map3->m_ppkHashTable = static_cast<FnvMap::EntryType**>(_NiMalloc(0x94));
    fnv_zlib_memset(map3->m_ppkHashTable, 0, map3->m_uiHashSize * 4);
    *reinterpret_cast<void***>(map3) = reinterpret_cast<void**>(&DAT_010f02d0);

    m_pkTexture = texture;
    reinterpret_cast<void(__stdcall*)(FnvTextureReference*)>(texture->m_ppVirtualMethodTable[1])(texture);
    m_u0c = 0;
    m_u10 = 0;
    m_u14 = 0;
    m_u18 = 0;
    map1->RemoveAll();
    map2->RemoveAll();
    map3->RemoveAll();
    return this;
}

struct NiD3DShaderProgramCreator;

extern int DAT_010f0a90;
extern NiD3DShaderProgramCreator* DAT_0126fa3c;

struct CreatorHLSL
{
    int vtbl;
    int field4;
    static void* operator new(unsigned int sz)
    {
        return BSFadeNode::operator new(sz);
    }
    CreatorHLSL()
    {
        vtbl = (int)&DAT_010f0a90;
        field4 = 0;
    }
};

// Allocates a CreatorHLSL and registers it with the shader program factory under "hlsl".
// @fnv 0x00e91af0
void __cdecl CreateHLSLShaderProgramCreator()
{
    DAT_0126fa3c = (NiD3DShaderProgramCreator*)new CreatorHLSL();
    NiD3DShaderProgramFactory::RegisterCreator("hlsl", DAT_0126fa3c);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern MemoryManager g_memoryManager;
struct Obj00a47600
{
    virtual ~Obj00a47600();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
// Decrements each element's reference count, calls DeleteThis on those reaching zero, then frees the array's header block.
// @fnv 0x00a47600
void __cdecl ReleaseObjectArray(Obj00a47600** apObjects)
{
    if (apObjects)
    {
        int n = reinterpret_cast<int*>(apObjects)[-1];
        Obj00a47600** p = apObjects + n;
        while (--n >= 0)
        {
            Obj00a47600* o = *--p;
            if (o && InterlockedDecrement(reinterpret_cast<volatile long*>(&o->m_uiRefCount)) == 0)
                o->DeleteThis();
        }
        g_memoryManager._DeallocateAlias(reinterpret_cast<int*>(apObjects) - 1);
    }
}

// @fnv 0x00e902f0
// src: COMMUNITY 0x00e902f0
void NiDX9DynamicTextureData::SetTextureLocked(bool v)
{
    unk70 = v;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126f9f0;
// @fnv 0x00e90550
// src: COMMUNITY 0x00e90550
GlobalObjectO2_00a7b610* NiDX9ErrorShader_GetRTTI()
{
    return &g_0126f9f0;
}

extern "C" void __cdecl NiD3DRenderState_InitShaderState();

struct FUN_00e90d80_shell
{
    void NiDX9RenderState_InitShaderState();
};

// Zeroes the byte at this+0x1100 and initialises the following dwords to 0,1,0,1, then calls FUN_00e87a50.
// @fnv 0x00e90d80
// src: COMMUNITY 0x00e90d80
void FUN_00e90d80_shell::NiDX9RenderState_InitShaderState()
{
    unsigned char* p = (unsigned char*)this + 0x1100;
    unsigned int v = 0;
    unsigned int one = 1;
    *p = (unsigned char)v;
    *(unsigned int*)(p + 4) = v;
    *(unsigned int*)(p + 8) = one;
    *(unsigned int*)(p + 12) = v;
    *(unsigned int*)(p + 16) = one;
    NiD3DRenderState_InitShaderState();
}

struct FUN_00e90db0_shell
{
    void CopyFieldValues();
};

// @fnv 0x00e90db0
void FUN_00e90db0_shell::CopyFieldValues()
{
    char* p = (char*)this;
    unsigned int a = *(unsigned int*)(p + 0x1104);
    unsigned int b = *(unsigned int*)(p + 0x110c);
    *(unsigned int*)(p + 0x1108) = a;
    *(unsigned int*)(p + 0x1110) = b;
}

// @fnv 0x00e90df0
// src: COMMUNITY 0x00e90df0
bool __fastcall NiDX9RenderState_GetSoftwareVertexProcessing(char* self, int)
{
    return *reinterpret_cast<bool*>(self + 0x1114);
}

typedef int(__thiscall* Fn_00e90e50)(void*, int, int);
// @fnv 0x00e90e50
int __fastcall CallVirtualSlot35(char* pObject, int)
{
    return reinterpret_cast<Fn_00e90e50*>(*reinterpret_cast<void***>(pObject))[35](
        pObject, *reinterpret_cast<int*>(pObject + 0x10e4), 0);
}

// @fnv 0x00e90f20
void* __fastcall GetPointerIfNotFlagged(char* pObject, int)
{
    if (pObject[0x1100])
        return 0;
    return *reinterpret_cast<void**>(pObject + 0x1104);
}

typedef int(__thiscall* Fn_00e90f40)(void*, int, int);
// @fnv 0x00e90f40
int __fastcall CallVtableSlot39WithField1108(char* self, int)
{
    return reinterpret_cast<Fn_00e90f40*>(*reinterpret_cast<void***>(self))[39](
        self, *reinterpret_cast<int*>(self + 0x1108), 0);
}

// @fnv 0x00e91020
// src: COMMUNITY 0x00e91020
void* __fastcall NiDX9RenderState_GetDeclaration(char* self, int)
{
    if (self[0x1100])
        return *reinterpret_cast<void**>(self + 0x110c);
    return 0;
}

typedef int(__thiscall* Fn_00e91040)(void*, int, int);
// @fnv 0x00e91040
int __fastcall CallVirtualSlot43(char* self, int)
{
    return reinterpret_cast<Fn_00e91040*>(*reinterpret_cast<void***>(self))[43](
        self, *reinterpret_cast<int*>(self + 0x1110), 0);
}

char __stdcall RegisterStreamables_00a98170(int);
// @fnv 0x00e91710
// src: XBOX_PDB 0x00e91710
char __stdcall NiDX9PersistentSrcTextureRendererData_RegisterStreamables(int a)
{
    return RegisterStreamables_00a98170(a) != 0;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126f9f8;
// @fnv 0x00e91740
// src: COMMUNITY 0x00e91740
GlobalObjectO2_00a7b610* NiDX9PersistentSrcTextureRendererData_GetRTTI()
{
    return &g_0126f9f8;
}

struct FUN_00e90e40_Class
{
    int __thiscall NiDX9RenderState_GetVertexShader();
};

// @fnv 0x00e90e40
// src: COMMUNITY 0x00e90e40
int __thiscall FUN_00e90e40_Class::NiDX9RenderState_GetVertexShader()
{
    return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x10e0);
}

extern void __cdecl _delete(void* p, int size);
extern void __cdecl FUN_00e8f840();

struct FUN_00e8fc30_shell
{
    void* FUN_00e8fc30(int arg);
};

// Calls FUN_00e8f840, deletes this with size 0x4c when arg has bit 0 set, and returns this.
// @fnv 0x00e8fc30
void* FUN_00e8fc30_shell::FUN_00e8fc30(int arg)
{
    FUN_00e8f840();
    if (arg & 1)
        _delete(this, 0x4c);
    return this;
}

namespace fnv_00e90560 {
extern "C" void __cdecl _delete(void*, int);
extern void __cdecl FUN_00e806c0();
extern int DAT_0126f74c;
extern int DAT_010f0764;

struct FUN_00e90560_shell
{
    void* FUN_00e90560(int param1);
};

// Sets the vtable, clears DAT_0126f74c, calls FUN_00e806c0, and frees this with _delete when param1 has bit 0 set.
// @fnv 0x00e90560
void* __thiscall FUN_00e90560_shell::FUN_00e90560(int aiFlags)
{
    *(int*)this = (int)&DAT_010f0764;
    DAT_0126f74c = 0;
    FUN_00e806c0();
    if (aiFlags & 1)
    {
        _delete(this, 0x40);
    }
    return this;
}
}  // namespace fnv_00e90560

struct FUN_00e91060_shell
{
    void NiDX9RenderState_ClearDeclaration(int arg);
};

// If arg is non-zero and the byte at offset 0x1100 is set, clears the int fields at 0x110c and 0x1110 when they equal arg.
// @fnv 0x00e91060
// src: COMMUNITY 0x00e91060
void FUN_00e91060_shell::NiDX9RenderState_ClearDeclaration(int arg)
{
    if (arg && (*(unsigned char*)((char*)this + 0x1100)))
    {
        if (*(int*)((char*)this + 0x110c) == arg)
            *(int*)((char*)this + 0x110c) = 0;
        if (*(int*)((char*)this + 0x1110) == arg)
            *(int*)((char*)this + 0x1110) = 0;
    }
}

namespace fnv_00a2cdc0 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct BooleanKey
{
    int _0;
    int _4;
    ~BooleanKey();
    void LoadBinary(NiStream&);
    void* operator new[](unsigned int s)
    {
        return g_memoryManager.Allocate(s);
    }
};
// @fnv 0x00a2cdc0
// src: GUESS 0x00a2cdc0 (confidence: low)
BooleanKey* __cdecl NiStream_ProcessEntries_00a2cdc0(NiStream& kStream, unsigned int uiElementCount)
{
    BooleanKey* p = new BooleanKey[uiElementCount];
    for (unsigned int i = 0; i < uiElementCount; ++i)
        p[i].LoadBinary(kStream);
    return p;
}
}  // namespace fnv_00a2cdc0

struct _Call_a5d3a0
{
    _Call_a5d3a0();
};

extern int DAT_010a080c;
extern int DAT_010efb7c;
struct FUN_00e8a260 : _Call_a5d3a0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    NiPixelFormat m_14;
    unsigned char m_58;
    unsigned char m_59;
    unsigned char m_5a;
    unsigned char m_5b;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    FUN_00e8a260(unsigned int, unsigned int);
};
// Initializes the object's fields: stores a1 in m_08, a2 in m_60, sets m_58-m_5a to 0xff, m_5b/m_64/m_68/m_0c/m_10 to 0, and installs two vtable pointers.
// @fnv 0x00e8a260
FUN_00e8a260::FUN_00e8a260(unsigned int a1, unsigned int a2) : m_00((int)&DAT_010a080c), m_08((int)a1), m_0c(0), m_10(0)
{
    m_58 = 0xff;
    m_59 = 0xff;
    m_5a = 0xff;
    m_5b = 0;
    m_64 = 0;
    m_68 = 0;
    m_00 = (int)&DAT_010efb7c;
    m_60 = (int)a2;
}

extern int DAT_010f02fc;

struct FUN_00e8fd60_shell
{
    void* m_iWordAt00;
    void FUN_00e8a260(int, int);
    void* InitWithArgs(int a, int b, int c);
};

// @fnv 0x00e8fd60
void* FUN_00e8fd60_shell::InitWithArgs(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_00e8a260(aiArg1, aiArg2);
    m_iWordAt00 = &DAT_010f02fc;
    return this;
}

extern int DAT_010f02fc;
struct S_00e8fd80
{
    void SetVtableAndProcessState_00e8a2b0();
    __declspec(noinline) void ProcessAndReturnValue_00e8fd80();
};
// @fnv 0x00e8fd80
// src: GUESS 0x00e8fd80 (confidence: low)
void S_00e8fd80::ProcessAndReturnValue_00e8fd80()
{
    void* v0 = *(void**)((char*)this + 0x60);
    int v1 = *(int*)((char*)this + 8);
    *(void**)this = (void*)&DAT_010f02fc;
    ((void(__thiscall*)(void*, int))(*(void***)v0)[0x15c / 4])(v0, v1);
    void* v2 = *(void**)((char*)this + 0x6c);
    if (v2)
    {
        ((unsigned long(__stdcall*)(void*))(*(void***)v2)[2])(v2);
        *(void**)((char*)this + 0x6c) = 0;
    }
    return SetVtableAndProcessState_00e8a2b0();
}

extern int DAT_010f049c;
void __cdecl _delete(void*, unsigned int);

// @fnv 0x00e90080
void* __fastcall DestroyRenderedCubeMapData(NiDX9RenderedCubeMapData* data, int, unsigned int flags)
{
    void* p = data->m_iWordAt04;
    int a = data->unk08;
    *(void**)data = (void*)&DAT_010f049c;
    ((void(__thiscall*)(void*, int))(*(void***)p)[86])(p, a);
    reinterpret_cast<S_00e8fd80*>(data)->ProcessAndReturnValue_00e8fd80();
    if (flags & 1)
        _delete(data, 0x70);
    return data;
}

extern int DAT_010f05ec;
void __cdecl _delete(void*, unsigned int);
struct TextureDataTeardown
{
    void __thiscall SetVtableAndProcessState_00e8a2b0();
};
typedef void(__thiscall* Fn00e90300)(void*, int);

// @fnv 0x00e90300
void* __fastcall DestroyDynamicTextureData(NiDX9DynamicTextureData* data, int, unsigned int auiFlags)
{
    void* o = data->m_pOwnerShader;
    int a = data->unk08;
    *(void**)data = (void*)&DAT_010f05ec;
    (*(Fn00e90300**)o)[0x58](o, a);
    ((TextureDataTeardown*)data)->SetVtableAndProcessState_00e8a2b0();
    if (auiFlags & 1)
        _delete(data, 0x74);
    return data;
}

void __fastcall NiDX9ErrorShader_CreateShaderDeclaration(void*);

// If the byte at offset 0x10 is zero, calls NiD3DShader::Initialize and then FUN_00e90970(this) on success; returns false on failure, otherwise true.
// @fnv 0x00e90a50
bool NiDX9ErrorShader::Initialize()
{
    if (!m_bInitialized)
    {
        if (NiD3DShader::Initialize())
        {
            NiDX9ErrorShader_CreateShaderDeclaration(this);
        }
        else
        {
            return false;
        }
    }
    return true;
}

extern int DAT_010f086c;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Dev00e90a80
{
    virtual long __stdcall f0();
    virtual long __stdcall AddRef();
};
struct S00e90a80
{
    void* f0;
    long f4;
    void* f8;
    void* fc;
    void* NiDX9TextureManager_NiDX9TextureManager(void*);
};
// @fnv 0x00e90a80
// src: COMMUNITY 0x00e90a80
void* S00e90a80::NiDX9TextureManager_NiDX9TextureManager(void* p)
{
    f0 = &kVtbl_NiRefObject;
    f4 = 0;
    InterlockedIncrement(&DAT_011f4400);
    f0 = &DAT_010f086c;
    fc = p;
    void* dev = *(void**)((char*)p + 0x288);
    f8 = dev;
    ((Dev00e90a80*)dev)->AddRef();
    return this;
}

extern NiRTTI g_011f4454_arg1;

struct Target
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual void f76() = 0;
    virtual void f77() = 0;
    virtual void f78() = 0;
    virtual bool Check(NiObject*) = 0;
};
struct FUN_00e90d20_shell
{
    char _pad[12];
    Target* m_pk;
    int NiDX9TextureManager_GetFormatFromTexture(NiObject*);
};
// Returns the value at offset 0x24 of the object at pkObj+0x24, or 0x16 if absent or the cast fails the Check.
// @fnv 0x00e90d20
// src: GAMEBRYO_SRC 0x00e90d20
int FUN_00e90d20_shell::NiDX9TextureManager_GetFormatFromTexture(NiObject* pkObj)
{
    int* pk = *(int**)((char*)pkObj + 0x24);
    if (pk)
        return *(int*)((char*)pk + 0x24);
    NiObject* pkCast = pkObj->DynamicCast(&g_011f4454_arg1);
    if (pkCast && m_pk->Check(pkCast))
    {
        int* pk2 = *(int**)((char*)pkObj + 0x24);
        if (pk2)
            return *(int*)((char*)pk2 + 0x24);
    }
    return 0x16;
}

struct HelperVTable
{
    void* e[93];
};
struct Helper
{
    HelperVTable* vtbl;
};
struct FUN_00e90e00_shell
{
    char _p0[0x10E0];
    int f10E0;
    int f10E4;
    char _p1[16];
    Helper* p10F8;
    void SetValue(int a1, bool a2);
};
// If a2 is set, copies f10E0 into f10E4; when a1 differs from f10E0, stores a1 and calls the helper's vtable slot 92 with it.
// @fnv 0x00e90e00
void FUN_00e90e00_shell::SetValue(int aiValue, bool abCopyCurrent)
{
    if (abCopyCurrent)
        f10E4 = f10E0;
    if (f10E0 == aiValue)
        return;
    f10E0 = aiValue;
    typedef void(__thiscall * T)(Helper*, Helper*, int);
    return ((T)p10F8->vtbl->e[92])(p10F8, p10F8, aiValue);
}

struct Inner
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9();
    virtual void v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(), v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29();
    virtual void v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49();
    virtual void v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59();
    virtual void v60(), v61(), v62(), v63(), v64(), v65(), v66(), v67(), v68(), v69();
    virtual void v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(), v79();
    virtual void v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88();
    virtual void __stdcall Foo(void*);
};
struct S
{
    char _0[0x10F8];
    Inner* p;
    char _1[4];
    bool flag;
    char _2[3];
    void* cur;
    void* prev;
    void NiDX9RenderState_SetFVF(void* a, bool b);
};
// Sets cur to a when a is non-null and differs from cur (or flag is set), optionally saving cur into prev, then calls p->Foo(a).
// @fnv 0x00e90ec0
// src: COMMUNITY 0x00e90ec0
void S::NiDX9RenderState_SetFVF(void* pNew, bool bSavePrev)
{
    if (!pNew)
        return;
    if (!flag && cur == pNew)
        return;
    flag = 0;
    if (bSavePrev)
        prev = cur;
    cur = pNew;
    p->Foo(pNew);
}

struct FUN_00e90f60_Holder
{
    char _pad[0x110C];
    void NiDX9RenderState_ClearFVF(void*);
};
// @fnv 0x00e90f60
// src: COMMUNITY 0x00e90f60
void FUN_00e90f60_Holder::NiDX9RenderState_ClearFVF(void* pTarget)
{
    if (!pTarget)
        return;
    if (*(unsigned char*)((char*)this + 0x1100))
        return;
    if (*(void**)((char*)this + 0x1104) == pTarget)
    {
        void* v = *(void**)((char*)this + 0x10F8);
        *(int*)((char*)this + 0x1104) = 2;
        ((void(__stdcall*)(void*, int))(*(void***)v)[89])(v, 2);
    }
    if (*(void**)((char*)this + 0x1108) == pTarget)
        *(int*)((char*)this + 0x1108) = 2;
}

namespace fnv_00e90fc0 {
struct Inner
{
    virtual void __stdcall v0() = 0;
    virtual void __stdcall v1() = 0;
    virtual void __stdcall v2() = 0;
    virtual void __stdcall v3() = 0;
    virtual void __stdcall v4() = 0;
    virtual void __stdcall v5() = 0;
    virtual void __stdcall v6() = 0;
    virtual void __stdcall v7() = 0;
    virtual void __stdcall v8() = 0;
    virtual void __stdcall v9() = 0;
    virtual void __stdcall v10() = 0;
    virtual void __stdcall v11() = 0;
    virtual void __stdcall v12() = 0;
    virtual void __stdcall v13() = 0;
    virtual void __stdcall v14() = 0;
    virtual void __stdcall v15() = 0;
    virtual void __stdcall v16() = 0;
    virtual void __stdcall v17() = 0;
    virtual void __stdcall v18() = 0;
    virtual void __stdcall v19() = 0;
    virtual void __stdcall v20() = 0;
    virtual void __stdcall v21() = 0;
    virtual void __stdcall v22() = 0;
    virtual void __stdcall v23() = 0;
    virtual void __stdcall v24() = 0;
    virtual void __stdcall v25() = 0;
    virtual void __stdcall v26() = 0;
    virtual void __stdcall v27() = 0;
    virtual void __stdcall v28() = 0;
    virtual void __stdcall v29() = 0;
    virtual void __stdcall v30() = 0;
    virtual void __stdcall v31() = 0;
    virtual void __stdcall v32() = 0;
    virtual void __stdcall v33() = 0;
    virtual void __stdcall v34() = 0;
    virtual void __stdcall v35() = 0;
    virtual void __stdcall v36() = 0;
    virtual void __stdcall v37() = 0;
    virtual void __stdcall v38() = 0;
    virtual void __stdcall v39() = 0;
    virtual void __stdcall v40() = 0;
    virtual void __stdcall v41() = 0;
    virtual void __stdcall v42() = 0;
    virtual void __stdcall v43() = 0;
    virtual void __stdcall v44() = 0;
    virtual void __stdcall v45() = 0;
    virtual void __stdcall v46() = 0;
    virtual void __stdcall v47() = 0;
    virtual void __stdcall v48() = 0;
    virtual void __stdcall v49() = 0;
    virtual void __stdcall v50() = 0;
    virtual void __stdcall v51() = 0;
    virtual void __stdcall v52() = 0;
    virtual void __stdcall v53() = 0;
    virtual void __stdcall v54() = 0;
    virtual void __stdcall v55() = 0;
    virtual void __stdcall v56() = 0;
    virtual void __stdcall v57() = 0;
    virtual void __stdcall v58() = 0;
    virtual void __stdcall v59() = 0;
    virtual void __stdcall v60() = 0;
    virtual void __stdcall v61() = 0;
    virtual void __stdcall v62() = 0;
    virtual void __stdcall v63() = 0;
    virtual void __stdcall v64() = 0;
    virtual void __stdcall v65() = 0;
    virtual void __stdcall v66() = 0;
    virtual void __stdcall v67() = 0;
    virtual void __stdcall v68() = 0;
    virtual void __stdcall v69() = 0;
    virtual void __stdcall v70() = 0;
    virtual void __stdcall v71() = 0;
    virtual void __stdcall v72() = 0;
    virtual void __stdcall v73() = 0;
    virtual void __stdcall v74() = 0;
    virtual void __stdcall v75() = 0;
    virtual void __stdcall v76() = 0;
    virtual void __stdcall v77() = 0;
    virtual void __stdcall v78() = 0;
    virtual void __stdcall v79() = 0;
    virtual void __stdcall v80() = 0;
    virtual void __stdcall v81() = 0;
    virtual void __stdcall v82() = 0;
    virtual void __stdcall v83() = 0;
    virtual void __stdcall v84() = 0;
    virtual void __stdcall v85() = 0;
    virtual void __stdcall v86() = 0;
    virtual void __stdcall Set(void*) = 0;
};
struct S
{
    char _0[0x10F8];
    Inner* m_inner;
    char _1[4];
    unsigned char m_flag;
    char _2[11];
    void* m_cur;
    void* m_pSecondNode;
    void NiDX9RenderState_SetDeclaration(void* a, bool b);
};
// @fnv 0x00e90fc0
// src: COMMUNITY 0x00e90fc0
void S::NiDX9RenderState_SetDeclaration(void* apTarget, bool abSavePrevious)
{
    if (!apTarget)
        return;
    if (m_flag && m_cur == apTarget)
        return;
    m_flag = 1;
    if (abSavePrevious)
        m_pSecondNode = m_cur;
    m_cur = apTarget;
    m_inner->Set(apTarget);
}
}  // namespace fnv_00e90fc0

extern unsigned short DAT_0126f92c[];
struct FUN_00e910a0_shell
{
    void NiDX9RenderState_SetSamplerState(int, int, int, int);
};
// @fnv 0x00e910a0
// src: COMMUNITY 0x00e910a0
void FUN_00e910a0_shell::NiDX9RenderState_SetSamplerState(int a1, int aiIndex, int aiValue, int aiUnused)
{
    unsigned short v = DAT_0126f92c[aiIndex];
    if (v >= 5)
        return;
    int* p = (int*)((char*)this + 0xE20 + (a1 * 5 + v) * 8);
    if (*p != aiValue)
    {
        *p = aiValue;
        void* dev = *(void**)((char*)this + 0x10F8);
        void** vt = *(void***)dev;
        void(__stdcall * fn)(void*, int, int, int) = (void(__stdcall*)(void*, int, int, int))vt[69];
        fn(dev, a1, aiIndex, aiValue);
    }
}

extern unsigned short DAT_0126f92c[];
struct FUN_00e91120_shell
{
    void NiDX9RenderState_RestoreSamplerState(int, int);
};
// @fnv 0x00e91120
// src: COMMUNITY 0x00e91120
void FUN_00e91120_shell::NiDX9RenderState_RestoreSamplerState(int a1, int a2)
{
    unsigned short idx = DAT_0126f92c[a2];
    if (idx >= 5)
        return;
    ((void(__thiscall*)(void*, int, int, int, int))(*(int***)this)[51])(
        this, a1, a2, *(int*)((char*)this + 0xe24 + (a1 * 5 + idx) * 8), 0);
}

namespace fnv_00e91160 {
extern "C" void __cdecl _delete(void*, int);
extern int DAT_010f088c;
void __cdecl UpdateFields_00e88b00();

struct FUN_00e91160_shell
{
    void* m_p;
    void* __thiscall FUN_00e91160(int arg);
};

// @fnv 0x00e91160
void* __thiscall FUN_00e91160_shell::FUN_00e91160(int aiFlags)
{
    m_p = &DAT_010f088c;
    UpdateFields_00e88b00();
    if (aiFlags & 1)
        _delete(this, 0x1248);
    return this;
}
}  // namespace fnv_00e91160

struct FUN_00e91190_Holder
{
    void SetFlag(bool b);
};
// If b differs from the byte at this+0x1114 and the object at this+0x10FC has a nonzero byte at 0x5D5, stores b and calls two virtual methods.
// @fnv 0x00e91190
void FUN_00e91190_Holder::SetFlag(bool b)
{
    if (b == *(unsigned char*)((char*)this + 0x1114))
        return;
    void* p1 = *(void**)((char*)this + 0x10FC);
    if (*(unsigned char*)((char*)p1 + 0x5D5) == 0)
        return;
    void* p2 = *(void**)((char*)this + 0x10F8);
    *(unsigned char*)((char*)this + 0x1114) = (unsigned char)b;
    ((void(__stdcall*)(void*, int)) * (void**)((char*)*(void**)p2 + 0x134))(p2, b);
    ((void(__thiscall*)(void*, int)) * (void**)((char*)*(void**)this + 0x98))(this, *(int*)((char*)this + 0x10E0));
}

namespace fnv_00e916d0 {

extern int DAT_010f099c;

// @fnv 0x00e916d0
// src: EXE 0x00e916d0
void* NiPersistentSrcTextureRendererData_CreateObject_00e916d0()
{
    BSFadeNode* p = (BSFadeNode*)BSFadeNode::operator new(0x94);
    if (p)
    {
        p->FUN_00a981d0();
        *reinterpret_cast<int*>(p) = reinterpret_cast<int>(&DAT_010f099c);
        return p;
    }
    return 0;
}
}  // namespace fnv_00e916d0

extern int DAT_010f099c;
void __cdecl UpdateFields_00a98240();
void __cdecl _delete(void*, int);
struct FUN_00e91750_shell
{
    void* m_pvt;
    void* __thiscall FUN_00e91750(int flags);
};
// Sets m_pvt to DAT_010f099c, calls FUN_00a98240, and if flags has bit 1 set, deletes this with size 0x94; returns this.
// @fnv 0x00e91750
void* __thiscall FUN_00e91750_shell::FUN_00e91750(int flags)
{
    m_pvt = &DAT_010f099c;
    UpdateFields_00a98240();
    if (flags & 1)
        _delete(this, 0x94);
    return this;
}

struct GlobalObjectO2_00a7b610
{
    const char* m_pcName;
    const GlobalObjectO2_00a7b610* m_pBaseRTTI;
};
extern GlobalObjectO2_00a7b610 g_0126f9f8;
struct Base_E91790
{
    virtual void v0();
    virtual void v1();
    virtual const GlobalObjectO2_00a7b610* GetRTTI() const;
    bool IsKindOfType(const GlobalObjectO2_00a7b610* pk) const
    {
        const GlobalObjectO2_00a7b610* cur = GetRTTI();
        while (cur)
        {
            if (cur == pk)
                return true;
            cur = cur->m_pBaseRTTI;
        }
        return false;
    }
};
struct Holder_E91790 : Base_E91790
{
    unsigned char IsEqual_00a982f0(Base_E91790* pk);
    bool NiDX9PersistentSrcTextureRendererData_IsEqual(Base_E91790* pk);
};
// @fnv 0x00e91790
// src: XBOX_PDB 0x00e91790
bool Holder_E91790::NiDX9PersistentSrcTextureRendererData_IsEqual(Base_E91790* pk)
{
    if (pk && pk->IsKindOfType(&g_0126f9f8))
        return IsEqual_00a982f0(pk);
    return false;
}

namespace fnv_00e91a90 {

void __stdcall AppendToStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
extern const char* g_0126f9f8;
// Calls AppendToStrings, gets a string via _FUN_00a7d330, grows the array if full, then stores the string at the current size index.
// @fnv 0x00e91a90
// src: XBOX_PDB 0x00e91a90
void __stdcall NiDX9PersistentSrcTextureRendererData_GetViewerStrings(StrArr* pkStrings)
{
    AppendToStrings(pkStrings);
    char* psz = _FUN_00a7d330(g_0126f9f8);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 10);
    unsigned int uiAlloc = *(unsigned short*)((char*)pkStrings + 8);
    if (uiSize >= uiAlloc)
    {
        unsigned int uiGrow = *(unsigned short*)((char*)pkStrings + 14);
        pkStrings->SetSize(uiGrow + uiSize);
    }
    pkStrings->SetAt(uiSize, psz);
}
}  // namespace fnv_00e91a90

extern int DAT_010efb7c;
extern int DAT_010a080c;
struct Tex00
{
    virtual long __stdcall Q(void*, void*);
    virtual unsigned long __stdcall A();
    virtual unsigned long __stdcall Release();
};
struct Rnd00
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void Purge(void*);
};
struct S_00e8a2b0 : NiRefObject
{
    void SetVtableAndProcessState_00e8a2b0();
};
// @fnv 0x00e8a2b0
// src: GUESS 0x00e8a2b0 (confidence: low)
void S_00e8a2b0::SetVtableAndProcessState_00e8a2b0()
{
    Tex00* a = *(Tex00**)((char*)this + 0x64);
    *(void**)this = (void*)&DAT_010efb7c;
    if (a)
    {
        (*(Rnd00**)((char*)*(void**)((char*)this + 0x60) + 0x8b8))->Purge(a);
        (*(Tex00**)((char*)this + 0x64))->Release();
        *(Tex00**)((char*)this + 0x64) = 0;
    }
    *(void**)this = (void*)&DAT_010a080c;
    NiRefObject::~NiRefObject();
}

extern int DAT_010f02fc;
void __cdecl _delete(void*, unsigned int);
struct R
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void At15C(int);
};
struct T
{
    virtual void __stdcall u0();
    virtual void __stdcall u1();
    virtual void __stdcall u2();
};
struct BaseUnk
{
    void __thiscall SetVtableAndProcessState_00e8a2b0();
};
struct Host00
{
    int _00;
    int _04;
    int _08;
    char _0c[84];
    R* _60;
    char _64[8];
    T* _6c;
    void* __thiscall FUN_00e8fdc0(unsigned int);
};
// @fnv 0x00e8fdc0
void* __thiscall Host00::FUN_00e8fdc0(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_010f02fc;
    _60->At15C(_08);
    if (_6c)
    {
        _6c->u2();
        _6c = 0;
    }
    ((BaseUnk*)this)->SetVtableAndProcessState_00e8a2b0();
    if (auiFlags & 1)
        _delete(this, 0x70);
    return this;
}

struct FUN_00e90dd0_shell
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    void NiDX9RenderState_RestoreShaderState();
};

// @fnv 0x00e90dd0
// src: COMMUNITY 0x00e90dd0
void FUN_00e90dd0_shell::NiDX9RenderState_RestoreShaderState()
{
    vfn_41();
    vfn_45();
}

struct Dummy_00e90e70
{
    char _pad0[0x10E0];
    void* f10E0;
    void* f10E4;
    char _pad1[0x10];
    void* f10F8;
    void ClearIfMatches(void* arg);
};
// Clears f10E0 (calling a virtual slot on f10F8 with 0) or f10E4 when either equals arg.
// @fnv 0x00e90e70
void Dummy_00e90e70::ClearIfMatches(void* pValue)
{
    if (f10E0 == pValue)
    {
        void* p = f10F8;
        f10E0 = 0;
        typedef void(__stdcall * Fn)(void*, int);
        ((Fn*)(*(void***)p))[92](p, 0);
    }
    if (f10E4 == pValue)
        f10E4 = 0;
}

extern unsigned short DAT_0126f92c[];
// Looks up DAT_0126f92c[a2] as a state index and returns mState[a1][s].value when s < 5, otherwise 0.
// @fnv 0x00e910f0
unsigned int NiDX9RenderState::GetStateValue(unsigned int auiStateGroup, unsigned int auiStateIndex)
{
    unsigned short s = DAT_0126f92c[auiStateIndex];
    if (s < 5)
        return mState[auiStateGroup][s].value;
    return 0;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pv, unsigned int uiBytes, unsigned int* puiComponentSizes,
                                              unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(
        this, pv, uiBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiBytesRead;
    return uiBytesRead;
}

inline void StrArr::SetAt(unsigned int uiIndex, char* const& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != 0)
            m_usESize++;
    }
    else
    {
        if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& val)
{
    NiBinaryStreamLoad(*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24c), &val, 1);
}

// Loads the sequence from a stream: base object, name, an unsigned int, then a key-name array sized by a count read from the stream.
// @fnv 0x00a47660
void NiSequence::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    m_pcName = 0;
    kStream.ReadStreamString(m_pcName);
    ReadBinaryValue(kStream, m_uiSequenceValue);
    kStream.ResetStreamState();
    unsigned int uiNumKeys;
    ReadBinaryValue(kStream, uiNumKeys);
    m_kStringArray.SetSize(uiNumKeys);
    for (unsigned int ui = 0; ui < uiNumKeys; ui++)
    {
        char* pcKeyName = 0;
        kStream.ReadStreamString(pcKeyName);
        m_kStringArray.SetAt(ui, static_cast<char* const&>(pcKeyName));
        kStream.ResetStreamState();
    }
}

namespace fnv_00e8ff60 {

// The variadic diagnostic target is 0x00a29680, the shared no-op/debug-output binding, not a Script method.
void __cdecl RendererDiagnostic(const char*, ...);



struct FUN_00e8a260
{
    static void* operator new(unsigned int size) { return BSFadeNode::operator new(size); }
    FUN_00e8a260(unsigned int, unsigned int) throw();
    char pad[0x70];
};
char* __cdecl GetHRESULTText(unsigned int);
extern int DAT_010f02fc;
extern int DAT_01101014;
struct RTD_Tex
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
int __cdecl Create_00e7d250(RTD_Tex*, void**, unsigned int, unsigned int);
struct RTD_Obj : FUN_00e8a260
{
    RTD_Obj(unsigned int a, unsigned int b) throw() : FUN_00e8a260(a, b)
    {
        *(void**)this = &DAT_010f02fc;
    }
    int NiDX9RenderedTextureData_CreateSurf(unsigned int, unsigned int);
};
typedef void(__thiscall* RTD_DelFn)(void*, unsigned int);
typedef RTD_Tex*(__thiscall* RTD_TexFn)(void*);
typedef void*(__thiscall* RTD_BufFn)(void*);

// Allocates an RTD_Obj, initializes it, queries IDirect3DTexture9, creates the buffer data, and releases the object on failure.
// @fnv 0x00e8ff60
void* __cdecl CreateRenderedTextureData(unsigned int a1, unsigned int a2, unsigned int a3)
{
    RTD_Obj* p = new RTD_Obj(a1, a2);
    if (!p->NiDX9RenderedTextureData_CreateSurf(a1, a3))
    {
        if (p)
            (*(RTD_DelFn**)p)[0](p, 1);
        return 0;
    }
    *(void**)(*(char**)((char*)p + 8) + 0x24) = p;
    RTD_Tex* tex = (*(RTD_TexFn**)p)[39](p);
    void* pBuffer = (*(RTD_BufFn**)a1)[41]((void*)a1);
    RTD_Tex* pD3DTexture = 0;
    long hr = tex->QueryInterface(&DAT_01101014, (void**)&pD3DTexture);
    if (hr < 0)
    {
        RendererDiagnostic("NiDX9RenderedTextureData::Create> Failed QueryInterface IID_IDirect3DTexture9 - %s",
                              GetHRESULTText(hr));
        (*(RTD_DelFn**)p)[0](p, 1);
        return 0;
    }
    int bCreated = Create_00e7d250(pD3DTexture, &pBuffer, a3, *(unsigned int*)((char*)p + 0x6c));
    if (pD3DTexture)
        pD3DTexture->Release();
    if (!bCreated)
    {
        RendererDiagnostic("NiDX9RenderedTextureData::Create> Failed NiDX92DBufferData::Create - %s", "");
        (*(RTD_DelFn**)p)[0](p, 1);
        return 0;
    }
    return p;
}
}  // namespace fnv_00e8ff60


struct NiD3DVertexDeclaration
{
    static NiD3DVertexDeclaration* __cdecl Create(NiRenderer*, unsigned int, unsigned int);
    bool NiDX9ErrorShader_CreateShaderDeclaration();
};

// @fnv 0x00e90970
// src: COMMUNITY 0x00e90970
bool NiD3DVertexDeclaration::NiDX9ErrorShader_CreateShaderDeclaration()
{
    NiD3DVertexDeclaration* pNew = NiD3DVertexDeclaration::Create(*(NiRenderer**)((char*)this + 0x18), 1, 1);

    NiD3DVertexDeclaration* pOld = *(NiD3DVertexDeclaration**)((char*)this + 0x28);
    if (pOld != pNew)
    {
        if (pOld)
        {
            if (InterlockedDecrement((long*)((char*)pOld + 4)) == 0)
                (*(void(__thiscall**)(NiD3DVertexDeclaration*))(*(int*)pOld + 4))(pOld);
        }
        *(NiD3DVertexDeclaration**)((char*)this + 0x28) = pNew;
        if (pNew)
            InterlockedIncrement((long*)((char*)pNew + 4));
    }

    NiD3DVertexDeclaration* p = *(NiD3DVertexDeclaration**)((char*)this + 0x28);
    (*(void(__thiscall**)(NiD3DVertexDeclaration*, int, int, int, int, int))(*(int*)p + 0x8c))(p, 0, 0, 0, 2, 0);

    return true;
}

struct D3DRenderStateGroup
{
    void __thiscall SetRenderState(unsigned int state, unsigned int value, bool enable);
    static D3DRenderStateGroup* __cdecl GetCurrentRenderStateGroup();
};

struct NiShaderData
{
    unsigned char padding[0x30];
    D3DRenderStateGroup* renderStateGroup;
};

struct ShaderRenderStateForwarder
{
    void __thiscall NiD3DShader_UpdatePipeline(unsigned int, unsigned int, unsigned int, unsigned int,
                              unsigned int, unsigned int, unsigned int);
};

int __cdecl GetRandomNumber();
extern double DAT_0102dfe0;
extern double DAT_0109ed88;

// Builds a color from three random bytes and sets several render states on the shader's render state group, then forwards the arguments to FUN_00a8f3e0.
// @fnv 0x00e90590
void NiShader::SetRandomColorRenderStates(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                          unsigned int arg5, unsigned int arg6, unsigned int arg7)
{
    float value;
    int iRandom;
    unsigned char first;
    unsigned char second;
    unsigned char third;
    unsigned int color;

    iRandom = GetRandomNumber();
    value = (float)iRandom / DAT_0109ed88;
    value *= DAT_0102dfe0;
    first = (unsigned char)(int)value;
    first = (unsigned char)(0x80 - first);

    iRandom = GetRandomNumber();
    value = (float)iRandom / DAT_0109ed88;
    value *= DAT_0102dfe0;
    second = (unsigned char)(int)value;
    second = (unsigned char)(0x80 - second);

    iRandom = GetRandomNumber();
    value = (float)iRandom / DAT_0109ed88;
    value *= DAT_0102dfe0;
    third = (unsigned char)(int)value;
    third = (unsigned char)(0x80 - third);

    color = first;
    color = (color | 0xffffff00u) << 8;
    color |= second;
    color <<= 8;
    color |= third;

    {
        NiShaderData* data = *reinterpret_cast<NiShaderData**>(reinterpret_cast<char*>(this) + 0x3c);
        if (data->renderStateGroup == 0)
        {
            data->renderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        }
        data->renderStateGroup->SetRenderState(0x3c, color, true);
    }

    {
        NiShaderData* data = *reinterpret_cast<NiShaderData**>(reinterpret_cast<char*>(this) + 0x3c);
        if (data->renderStateGroup == 0)
        {
            data->renderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        }
        data->renderStateGroup->SetRenderState(0x1d, 0, true);
    }

    {
        NiShaderData* data = *reinterpret_cast<NiShaderData**>(reinterpret_cast<char*>(this) + 0x3c);
        if (data->renderStateGroup == 0)
        {
            data->renderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        }
        data->renderStateGroup->SetRenderState(0x1b, 0, true);
    }

    {
        NiShaderData* data = *reinterpret_cast<NiShaderData**>(reinterpret_cast<char*>(this) + 0x3c);
        if (data->renderStateGroup == 0)
        {
            data->renderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        }
        data->renderStateGroup->SetRenderState(0x0f, 0, true);
    }

    {
        NiShaderData* data = *reinterpret_cast<NiShaderData**>(reinterpret_cast<char*>(this) + 0x3c);
        if (data->renderStateGroup == 0)
        {
            data->renderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        }
        data->renderStateGroup->SetRenderState(0x34, 0, true);
    }

    reinterpret_cast<ShaderRenderStateForwarder*>(this)->NiD3DShader_UpdatePipeline(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

struct CachedResource
{
    virtual long __stdcall query();
    virtual long __stdcall addRef();
    virtual long __stdcall release();
};
struct CacheEntry
{
    int unk00;
    unsigned int kind, usage, format, unk10, size, pool, age;
    CachedResource* object;
    unsigned int description;
    int unk28, unk2C, unk30, unk34;
    void Reset();
};
struct CacheRing
{
    int unk00;
    unsigned char cursor;
    CacheEntry* entries[5];
};
void* __cdecl Object_DispatchCommandFour(unsigned int);
struct ResourceCache
{
    int unk00, unk04;
    void* device;
    CacheRing* GetOrCreateNode(unsigned int format, unsigned int pool, unsigned int usage);
    CachedResource* FUN_00e8f190(unsigned int size, unsigned int format, unsigned int pool, unsigned int usage,
                                 unsigned int* description);
    CachedResource* AcquireCachedResource(unsigned int size, unsigned int format, unsigned int pool,
                                          unsigned int usage);
};
// @fnv 0x00e8fc50
CachedResource* ResourceCache::AcquireCachedResource(unsigned int size, unsigned int format, unsigned int pool,
                                                     unsigned int usage)
{
    if (!device)
        return 0;
    CachedResource* result = 0;
    CacheRing* ring = GetOrCreateNode(format, pool, usage);
    if (ring)
    {
        CacheEntry* entry = ring->entries[ring->cursor];
        if (entry)
        {
            if (entry->size <= size)
            {
                result = entry->object;
                ++ring->cursor;
            }
            else
            {
                entry->object->release();
                entry->object = 0;
            }
        }
        else
        {
            entry = (CacheEntry*)Object_DispatchCommandFour(sizeof(CacheEntry));
            if (entry)
                entry->Reset();
            else
                entry = 0;
            entry->usage = usage;
            entry->format = format;
            entry->kind = 4;
            entry->size = size;
            entry->pool = pool;
            entry->age = 0;
            entry->object = 0;
        }
        if (!entry->object)
        {
            result = FUN_00e8f190(size, format, pool, usage, &entry->description);
            entry->object = result;
            entry->size = size;
            entry->pool = pool;
            entry->age = 0;
            ++ring->cursor;
        }
        if (ring->cursor == 5)
            ring->cursor = 0;
    }
    return result;
}

struct BeamTextureState
{
    void SetStageValue(unsigned int a, unsigned int b, bool c);
    void NiD3DTextureStageGroup_SetSamplerState(unsigned int a, unsigned int b, unsigned int c, bool d);
};

struct StageReturn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BeamTextureState* unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    unsigned char unk5c;
    unsigned char unk5d;
    unsigned char unk5e;
    unsigned char unk5f;
    unsigned int m_iObjectReferenceCount;
    void ReturnToPool();
    void DecRefCount()
    {
        if (--m_iObjectReferenceCount == 0)
            ReturnToPool();
    }
};

void AssignStageFromPool(StageReturn*& out);

struct PassStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    unsigned int m_iObjectReferenceCount;
    void DecRefCount()
    {
        if (--m_iObjectReferenceCount == 0)
            Destroy();
    }
    int SetStage(unsigned int idx, StageReturn* stage);
    void Destroy();
};

void __cdecl CreateNewPassStandIn(PassStandIn*& out);
extern PassStandIn* DAT_0126f74c;

struct ErrorShaderStandIn
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
    int unk38;
    PassStandIn* unk3c;
    bool InitErrorShaderPass();
};

// @fnv 0x00e90850
bool ErrorShaderStandIn::InitErrorShaderPass()
{
    StageReturn* stage;
    PassStandIn* pass = 0;
    CreateNewPassStandIn(pass);
    unk3c = pass;
    stage = 0;
    AssignStageFromPool(stage);
    StageReturn* s = stage;
    s->unk04 = 0;
    s->unk08 = 0;
    s->unk10->SetStageValue(1, 2, false);
    s->unk10->SetStageValue(2, 3, false);
    s->unk10->SetStageValue(4, 2, false);
    s->unk10->SetStageValue(5, 3, false);
    s->unk10->SetStageValue(0xb, 0, false);
    s->unk10->NiD3DTextureStageGroup_SetSamplerState(1, 3, 0, false);
    s->unk10->NiD3DTextureStageGroup_SetSamplerState(2, 3, 0, false);
    s->unk10->NiD3DTextureStageGroup_SetSamplerState(5, 2, 0, false);
    s->unk10->NiD3DTextureStageGroup_SetSamplerState(6, 2, 0, false);
    s->unk10->NiD3DTextureStageGroup_SetSamplerState(7, 0, 0, false);
    s->unk5e = 0;
    s->unk10->SetStageValue(0x18, 0, false);
    pass->SetStage(pass->unk14, s);
    DAT_0126f74c = pass;
    if (stage)
        stage->DecRefCount();
    if (pass)
        pass->DecRefCount();
    return true;
}

extern int DAT_010f086c;
extern int DAT_0101dce4;
extern volatile long DAT_011f4400;

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00e90ac0_Sub
{
    virtual void v00();
    virtual void v01();
    virtual void __stdcall Release();
};

struct FUN_00e90ac0_cls
{
    int m_vptr;
    int unk04;
    FUN_00e90ac0_Sub* m_pSub;
    int unk0c;

    FUN_00e90ac0_cls* FUN_00e90ac0(unsigned char acFlags);
};

// Releases m_pSub, resets the vtable, decrements DAT_011f4400, and optionally frees this with FUN_00aa1460 when acFlags bit 0 is set.
// @fnv 0x00e90ac0
FUN_00e90ac0_cls* FUN_00e90ac0_cls::FUN_00e90ac0(unsigned char acFlags)
{
    FUN_00e90ac0_Sub* pSub = m_pSub;
    m_vptr = (int)&DAT_010f086c;
    pSub->Release();
    m_pSub = 0;
    m_vptr = (int)&DAT_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x10);
    }
    return this;
}

struct e914e0_Sub
{
    unsigned char unk0000[0x5d4];
    unsigned char m_5d4;
    unsigned char m_5d5;
};

struct FUN_00e914e0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned char unk0c[0x14];
    unsigned int m_20[11];
    unsigned char unk4c[0x20];
    unsigned int m_6c;
    unsigned int m_70;
    unsigned char unk74[0x1088];
    e914e0_Sub* m_10fc;
    unsigned char unk1100[0x14];
    unsigned char m_1114;
    unsigned char unk1115[0x27];
    unsigned int m_113c;
    unsigned char unk1140[4];
    unsigned int m_1144;
    unsigned int m_1148;
    unsigned char unk114c[0x18];
    unsigned char m_1164;

    void UpdateFlags();
};

// Updates m_08, m_6c, m_70 and m_1114 from m_113c, m_1144, m_1148, m_1164 and the m_10fc sub-object's m_5d4/m_5d5 bytes.
// @fnv 0x00e914e0
void FUN_00e914e0_cls::UpdateFlags()
{
    if ((m_113c & 0x100) != 0 && (m_113c & 0x100000) != 0)
        m_08 |= 1;
    else
        m_08 &= 0xfffffffe;

    unsigned int uiLoMask = m_1144;
    unsigned int uiHiMask = m_1148;
    m_70 = 0;
    m_6c = 0;

    unsigned int bit = 1;
    unsigned int* p = m_20;
    int n = 11;
    do
    {
        if ((*p & uiLoMask) != 0)
            m_6c |= bit;
        if ((*p & uiHiMask) != 0)
            m_70 |= bit;
        ++p;
        bit = (bit << 1) | (bit >> 31);
    } while (--n != 0);

    if ((m_1164 & 0x10) != 0)
        m_08 |= 4;
    else
        m_08 &= 0xfffffffb;

    e914e0_Sub* s = m_10fc;
    unsigned int r;
    if (s->m_5d4 != 0 && s->m_5d5 == 0)
        r = 1;
    else
        r = 0;
    m_1114 = (unsigned char)r;
}

struct TexDeviceState
{
    char _000[0x6f5];
    unsigned char m_6f5;
};

struct TexHolder
{
    char _00[0x24];
    void* m_24;
};

struct TexOwner
{
    char _00[0x38];
    unsigned char m_38;
};

struct TexRecord
{
    void** m_ppVirtualMethodTable;
    int CreateSurf_00e90340(TexOwner* owner, unsigned int flag);
    unsigned int _04;
    TexHolder* m_08;
    char _0c[0x60];
    unsigned int m_6c;
    unsigned char m_70;
};

inline void* operator new(unsigned int, void* p)
{
    return p;
}

void __cdecl Object_DoNothing(const char* msg);
void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern TexDeviceState* DAT_011f4748;

// Rejects tiled owners, allocates and constructs a TexRecord, checks it against the device flag, and on failure destroys it and returns 0.
// @fnv 0x00e904c0
TexRecord* __cdecl CreateDynamicTexture(TexOwner* owner)
{
    if (owner->m_38 != 0)
    {
        Object_DoNothing("NiDX9DynamicTextureData Failed> Can not create a tiled dynamic texture.\n");
        return 0;
    }

    TexDeviceState* dev = DAT_011f4748;
    TexRecord* pRecord = (TexRecord*)Object_DispatchCommandFour(0x74);
    if (pRecord != 0)
    {
        new (pRecord) FUN_00e8a260((unsigned int)owner, (unsigned int)dev);
        pRecord->m_ppVirtualMethodTable = (void**)&DAT_010f05ec;
        pRecord->m_6c = 0;
        pRecord->m_70 = 0;
    }
    else
    {
        pRecord = 0;
    }

    volatile unsigned char ucDeviceFlag = dev->m_6f5;

    if (pRecord->CreateSurf_00e90340(owner, *(volatile unsigned int*)&ucDeviceFlag) == 0)
    {
        if (pRecord != 0)
        {
            void** vt = *(void***)pRecord;
            ((void(__thiscall*)(void*, int))vt[0])(pRecord, 1);
        }
        return 0;
    }
    pRecord->m_08->m_24 = pRecord;
    return pRecord;
}

struct FUN_00e909e0_cls
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned char m_20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned char m_24;
    unsigned char m_25;
    unsigned char unk26;
    unsigned char unk27;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;

    void FUN_00e818a0();
    void InitErrorShaderPass();
    void AssignFixedString(void** out);
    FUN_00e909e0_cls* NiDX9ErrorShader_NiDX9ErrorShader();
};

extern int DAT_0109b220;
extern int DAT_010f0764;
extern void* __cdecl FUN_00a5b690(const char* s);

// @fnv 0x00e909e0
// src: EXE 0x00e909e0
FUN_00e909e0_cls* FUN_00e909e0_cls::NiDX9ErrorShader_NiDX9ErrorShader()
{
    FUN_00e818a0();
    m_24 = 0;
    m_25 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    *(volatile int*)&m_38 = 0;
    m_vtbl = (void*)&DAT_010f0764;
    InitErrorShaderPass();
    void* p = FUN_00a5b690("NiDX9ErrorShader");
    AssignFixedString(&p);
    if ((int)p != DAT_0109b220)
    {
        InterlockedDecrement((volatile long*)((char*)p - 8));
    }
    m_20 = 1;
    return this;
}

namespace fnv_00e90b10 {


extern NiRTTI DAT_011f444c;





struct TexData
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual unsigned int GetLevels();
    virtual void* GetD3DTexture();
    virtual void v40();
    virtual TexData* GetAsRendered();
    virtual TexData* GetAsSourceTexture();
    virtual TexData* GetAsDynamic();
    virtual void v44();
    virtual void Update();

    int unk04;
    int unk08;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
};

struct Texture : NiObject
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    TexData* m_pTextureRendererData;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    bool m_bIsStatic;
};

int NiDX9SourceTextureData_Create(void* tex, void* renderer);

extern NiRenderer* DAT_011f4748;

static inline bool IsPowerOfTwo(unsigned int v)
{
    if (v == 0)
        return false;
    return (v & (v - 1)) == 0;
}

struct FUN_00e90b10_shell
{
    int unk00;
    int unk04;
    int unk08;
    void* m_pOwnerShader;
    void* GetTextureData(Texture* pkTexture, bool* pbChanged, bool* pbMipmap, bool* pbNonPow2);
};

// @fnv 0x00e90b10
void* FUN_00e90b10_shell::GetTextureData(Texture* pkTexture, bool* pbChanged, bool* pbMipmap, bool* pbNonPow2)
{
    *pbChanged = false;
    *pbMipmap = false;
    *pbNonPow2 = false;
    if (!pkTexture)
        return 0;

    NiRenderer* pkR = DAT_011f4748;
    EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(pkR->m_kSourceDataCriticalSection));
    TexData* pkData = pkTexture->m_pTextureRendererData;
    if (!pkData)
    {
        NiObject* pkSrc = pkTexture->DynamicCast(&DAT_011f444c);
        if (pkSrc)
        {
            pkData = (TexData*)NiDX9SourceTextureData_Create(pkSrc, m_pOwnerShader);
            *pbChanged = true;
        }
        else
        {
            LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(pkR->m_kSourceDataCriticalSection));
            return 0;
        }
    }
    LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(pkR->m_kSourceDataCriticalSection));

    *pbNonPow2 = (IsPowerOfTwo(pkData->m_uiImageWidth) && IsPowerOfTwo(pkData->m_uiImageHeight)) ? false : true;

    TexData* pkOther = pkData->GetAsRendered();
    if (!pkOther)
        pkOther = pkData->GetAsDynamic();
    if (pkOther)
        return pkOther->GetD3DTexture();

    TexData* pkSource = pkData->GetAsSourceTexture();
    if (pkSource)
    {
        if (!pkData->GetD3DTexture())
        {
            pkSource->Update();
            *pbChanged = true;
        }
        else if (!pkTexture->m_bIsStatic)
        {
            pkSource->Update();
        }
    }
    *pbMipmap = pkData->GetLevels() > 1;
    return pkData->GetD3DTexture();
}
}  // namespace fnv_00e90b10

namespace fnv_00e91590 {
void* memcpy(void* dst, const void* src, unsigned int size) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
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

template <class T> class RefPtr
{
  public:
    T* m_pObject;
    RefPtr& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct RenderStateEntry
{
    int state;
    int value;
};
extern RenderStateEntry DAT_011bfce8[256];

struct CreateDesc
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
};

RefObj* __cdecl NiDX9ShaderConstantManager_Create(int adapter, CreateDesc* desc);

// Constructor target 0x00e881a0 and initialization slot 65 describe render-state storage, not NiRenderer (35 inherited slots, size 0x280).
struct RenderStateStorage
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void Init104();
    RenderStateStorage(int adapter) throw();
    int unk0004;
    unsigned int m_flags08;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    int unk0df4;
    int unk0df8;
    int unk0dfc;
    int unk0e00;
    int unk0e04;
    int unk0e08;
    int unk0e0c;
    int unk0e10;
    int unk0e14;
    int unk0e18;
    int unk0e1c;
    int unk0e20;
    int unk0e24;
    int unk0e28;
    int unk0e2c;
    int unk0e30;
    int unk0e34;
    int unk0e38;
    int unk0e3c;
    int unk0e40;
    int unk0e44;
    int unk0e48;
    int unk0e4c;
    int unk0e50;
    int unk0e54;
    int unk0e58;
    int unk0e5c;
    int unk0e60;
    int unk0e64;
    int unk0e68;
    int unk0e6c;
    int unk0e70;
    int unk0e74;
    int unk0e78;
    int unk0e7c;
    int unk0e80;
    int unk0e84;
    int unk0e88;
    int unk0e8c;
    int unk0e90;
    int unk0e94;
    int unk0e98;
    int unk0e9c;
    int unk0ea0;
    int unk0ea4;
    int unk0ea8;
    int unk0eac;
    int unk0eb0;
    int unk0eb4;
    int unk0eb8;
    int unk0ebc;
    int unk0ec0;
    int unk0ec4;
    int unk0ec8;
    int unk0ecc;
    int unk0ed0;
    int unk0ed4;
    int unk0ed8;
    int unk0edc;
    int unk0ee0;
    int unk0ee4;
    int unk0ee8;
    int unk0eec;
    int unk0ef0;
    int unk0ef4;
    int unk0ef8;
    int unk0efc;
    int unk0f00;
    int unk0f04;
    int unk0f08;
    int unk0f0c;
    int unk0f10;
    int unk0f14;
    int unk0f18;
    int unk0f1c;
    int unk0f20;
    int unk0f24;
    int unk0f28;
    int unk0f2c;
    int unk0f30;
    int unk0f34;
    int unk0f38;
    int unk0f3c;
    int unk0f40;
    int unk0f44;
    int unk0f48;
    int unk0f4c;
    int unk0f50;
    int unk0f54;
    int unk0f58;
    int unk0f5c;
    int unk0f60;
    int unk0f64;
    int unk0f68;
    int unk0f6c;
    int unk0f70;
    int unk0f74;
    int unk0f78;
    int unk0f7c;
    int unk0f80;
    int unk0f84;
    int unk0f88;
    int unk0f8c;
    int unk0f90;
    int unk0f94;
    int unk0f98;
    int unk0f9c;
    int unk0fa0;
    int unk0fa4;
    int unk0fa8;
    int unk0fac;
    int unk0fb0;
    int unk0fb4;
    int unk0fb8;
    int unk0fbc;
    int unk0fc0;
    int unk0fc4;
    int unk0fc8;
    int unk0fcc;
    int unk0fd0;
    int unk0fd4;
    int unk0fd8;
    int unk0fdc;
    int unk0fe0;
    int unk0fe4;
    int unk0fe8;
    int unk0fec;
    int unk0ff0;
    int unk0ff4;
    int unk0ff8;
    int unk0ffc;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100c;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101c;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102c;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103c;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104c;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105c;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106c;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107c;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108c;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109c;
    int unk10a0;
    int unk10a4;
    int unk10a8;
    int unk10ac;
    int unk10b0;
    int unk10b4;
    int unk10b8;
    int unk10bc;
    int unk10c0;
    int unk10c4;
    int unk10c8;
    int unk10cc;
    int unk10d0;
    int unk10d4;
    int unk10d8;
    int unk10dc;
    int unk10e0;
    int unk10e4;
    int unk10e8;
    int unk10ec;
    RefPtr<RefObj> m_sp10f0;
    int unk10f4;
    int unk10f8;
    int unk10fc;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110c;
    int unk1110;
};

// This factory allocates 0x1248 bytes with a 0x130-byte creation descriptor at 0x1118; NiDX9Renderer has size 0xB80.
struct RenderStateCache : RenderStateStorage
{
    bool m_b1114;
    CreateDesc m_kCreateDesc;
    RenderStateCache(int adapter, CreateDesc* desc) : RenderStateStorage(adapter)
    {
        m_b1114 = false;
        memcpy(&m_kCreateDesc, desc, sizeof(CreateDesc));
    }
    static void* operator new(unsigned int sz)
    {
        return BSFadeNode::operator new(sz);
    }
};

// Allocates a RenderStateCache, initializes it, updates matching entries in DAT_011bfce8, sets flag bit 2 when zenable, and stores the result of FUN_00e978a0.
// @fnv 0x00e91590
RenderStateCache* __cdecl CreateRenderer(int adapter, CreateDesc* desc, bool zenable)
{
    RenderStateCache* r = new RenderStateCache(adapter, desc);
    r->Init104();
    for (unsigned int i = 0; i < 256; i++)
    {
        if (DAT_011bfce8[i].state == -1)
            break;
        if (DAT_011bfce8[i].state == 7)
            DAT_011bfce8[i].value = zenable != 0;
    }
    if (zenable)
        r->m_flags08 |= 2;
    r->m_sp10f0 = NiDX9ShaderConstantManager_Create(adapter, desc);
    return r;
}
}  // namespace fnv_00e91590

namespace fnv_00e90c70 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* section);

struct FnvData;

struct FnvRTTI
{
    FnvRTTI* m_pkBase;
    const char* m_pcName;
};

struct FnvCriticalSection
{
    void* m_pCriticalSectionDebugInfo;
    long m_lLockCount;
    long m_lRecursionCount;
    void* m_hOwningThread;
    void* m_hLockSemaphore;
    unsigned int m_ulSpinCount;

    void Enter()
    {
        EnterCriticalSection(this);
    }
    void Leave()
    {
        LeaveCriticalSection(this);
    }
};

struct FnvData
{
    virtual void* m_v00();
    virtual void* m_v04();
    virtual void* m_v08();
    virtual void* m_v0C();
    virtual void* m_v10();
    virtual void* m_v14();
    virtual void* m_v18();
    virtual void* m_v1C();
    virtual void* m_v20();
    virtual void* m_v24();
    virtual void* m_v28();
    virtual void* m_v2C();
    virtual void* m_v30();
    virtual void* m_v34();
    virtual void* m_v38();
    virtual void* m_v3C();
    virtual void* m_v40();
    virtual void* m_v44();
    virtual void* m_v48();
    virtual void* m_v4C();
    virtual void* m_v50();
    virtual void* m_v54();
    virtual void* m_v58();
    virtual void* m_v5C();
    virtual void* m_v60();
    virtual void* m_v64();
    virtual void* m_v68();
    virtual void* m_v6C();
    virtual void* m_v70();
    virtual void* m_v74();
    virtual void* m_v78();
    virtual void* m_v7C();
    virtual void* m_v80();
    virtual void* m_v84();
    virtual void* m_v88();
    virtual void* m_v8C();
    virtual void* m_v90();
    virtual void* m_v94();
    virtual void* m_v98();
    virtual void* m_v9C();
    virtual void* m_vA0();
    virtual FnvData* m_vA4();
    virtual void* m_vA8();
    virtual FnvData* m_vAC();
};

struct FnvObject
{
    void* m_ppVirtualMethodTable;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    unsigned int m_unk20;
    FnvData* m_pUserData;
    FnvObject* DynamicCast(const FnvRTTI* rtti);
};

struct FnvRenderGlobal
{
    unsigned int m_unk000;
    unsigned int m_unk004;
    unsigned int m_unk008;
    unsigned int m_unk00c;
    unsigned int m_unk010;
    unsigned int m_unk014;
    unsigned int m_unk018;
    unsigned int m_unk01c;
    unsigned int m_unk020;
    unsigned int m_unk024;
    unsigned int m_unk028;
    unsigned int m_unk02c;
    unsigned int m_unk030;
    unsigned int m_unk034;
    unsigned int m_unk038;
    unsigned int m_unk03c;
    unsigned int m_unk040;
    unsigned int m_unk044;
    unsigned int m_unk048;
    unsigned int m_unk04c;
    unsigned int m_unk050;
    unsigned int m_unk054;
    unsigned int m_unk058;
    unsigned int m_unk05c;
    unsigned int m_unk060;
    unsigned int m_unk064;
    unsigned int m_unk068;
    unsigned int m_unk06c;
    unsigned int m_unk070;
    unsigned int m_unk074;
    unsigned int m_unk078;
    unsigned int m_unk07c;
    unsigned int m_unk080;
    unsigned int m_unk084;
    unsigned int m_unk088;
    unsigned int m_unk08c;
    unsigned int m_unk090;
    unsigned int m_unk094;
    unsigned int m_unk098;
    unsigned int m_unk09c;
    unsigned int m_unk0a0;
    unsigned int m_unk0a4;
    unsigned int m_unk0a8;
    unsigned int m_unk0ac;
    unsigned int m_unk0b0;
    unsigned int m_unk0b4;
    unsigned int m_unk0b8;
    unsigned int m_unk0bc;
    unsigned int m_unk0c0;
    unsigned int m_unk0c4;
    unsigned int m_unk0c8;
    unsigned int m_unk0cc;
    unsigned int m_unk0d0;
    unsigned int m_unk0d4;
    unsigned int m_unk0d8;
    unsigned int m_unk0dc;
    unsigned int m_unk0e0;
    unsigned int m_unk0e4;
    unsigned int m_unk0e8;
    unsigned int m_unk0ec;
    unsigned int m_unk0f0;
    unsigned int m_unk0f4;
    unsigned int m_unk0f8;
    unsigned int m_unk0fc;
    unsigned int m_unk100;
    unsigned int m_unk104;
    unsigned int m_unk108;
    unsigned int m_unk10c;
    unsigned int m_unk110;
    unsigned int m_unk114;
    unsigned int m_unk118;
    unsigned int m_unk11c;
    unsigned int m_unk120;
    unsigned int m_unk124;
    unsigned int m_unk128;
    unsigned int m_unk12c;
    unsigned int m_unk130;
    unsigned int m_unk134;
    unsigned int m_unk138;
    unsigned int m_unk13c;
    unsigned int m_unk140;
    unsigned int m_unk144;
    unsigned int m_unk148;
    unsigned int m_unk14c;
    unsigned int m_unk150;
    unsigned int m_unk154;
    unsigned int m_unk158;
    unsigned int m_unk15c;
    unsigned int m_unk160;
    unsigned int m_unk164;
    unsigned int m_unk168;
    unsigned int m_unk16c;
    unsigned int m_unk170;
    unsigned int m_unk174;
    unsigned int m_unk178;
    unsigned int m_unk17c;
    FnvCriticalSection m_kCriticalSection;
};

extern FnvRenderGlobal* g_pFnvRenderGlobal;
extern FnvRTTI g_kFnvDataRTTI;
int NiDX9SourceTextureData_Create(void* a, void* b);

struct FnvRendererOwner
{
    void* m_ppVirtualMethodTable;
    unsigned int m_unk04;
    unsigned int m_unk08;
    void* m_pBinaryStream;
    bool IsObjectStatic(FnvObject* obj, void* arg2, void* arg3);
};

// @fnv 0x00e90c70
bool FnvRendererOwner::IsObjectStatic(FnvObject* obj, void* arg2, void* arg3)
{
    if (!obj)
        return false;
    FnvRenderGlobal* pRenderGlobal = g_pFnvRenderGlobal;
    pRenderGlobal->m_kCriticalSection.Enter();
    FnvData* data = obj->m_pUserData;
    if (!data)
    {
        FnvObject* found = obj->DynamicCast(&g_kFnvDataRTTI);
        if (found)
            data = (FnvData*)NiDX9SourceTextureData_Create(found, m_pBinaryStream);
        else
        {
            pRenderGlobal->m_kCriticalSection.Leave();
            return false;
        }
    }
    pRenderGlobal->m_kCriticalSection.Leave();
    FnvData* p = data->m_vA4();
    if (!p)
        p = data->m_vAC();
    if (p)
    {
        bool bStatic = p->m_v9C() != 0;
        return bStatic;
    }
    return true;
}
}  // namespace fnv_00e90c70

struct StatePair
{
    unsigned int state, value;
};
extern StatePair DAT_011bfce8[];
extern NiColor DAT_011f4998;
struct RenderDefaults
{
    void FUN_00e94130();
};
struct RenderStateInitializer
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void SetState(unsigned int, unsigned int, int, int);
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    unsigned int unknown04;
    unsigned char flags08, flags09, flags0a, flags0b;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int blendSource, blendDestination;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    NiColor color;
    unsigned int packedColor;
    unsigned int unknown9c;
    unsigned int unknowna0;
    unsigned int unknowna4;
    unsigned int unknowna8;
    unsigned int unknownac;
    unsigned int unknownb0;
    unsigned int unknownb4;
    unsigned int unknownb8;
    unsigned int unknownbc;
    unsigned int unknownc0;
    unsigned int unknownc4;
    unsigned int unknownc8;
    unsigned int unknowncc;
    unsigned int unknownd0;
    unsigned int unknownd4;
    unsigned int unknownd8;
    unsigned int unknowndc;
    unsigned int unknowne0;
    unsigned int unknowne4;
    unsigned int unknowne8;
    unsigned int unknownec;
    unsigned int unknownf0;
    unsigned int unknownf4;
    RenderDefaults defaults;
    void InitializeRenderStates();
};
// Compacts DAT_011bfce8 unless bit 0x4000 is set, then resets render states via SetState and packs DAT_011f4998 into packedColor.
// @fnv 0x00e911e0
void RenderStateInitializer::InitializeRenderStates()
{
    if (!(*(unsigned int*)((char*)this + 0x1138) & 0x4000))
    {
        unsigned int index = 0, skipped = 0;
        StatePair* current = DAT_011bfce8;
        while (current->state != (unsigned int)-1)
        {
            unsigned int source = index + skipped;
            if (DAT_011bfce8[source].state != 190 && DAT_011bfce8[source].state != 191 &&
                DAT_011bfce8[source].state != 192)
            {
                DAT_011bfce8[index] = DAT_011bfce8[source];
                if (DAT_011bfce8[source].state == (unsigned int)-1)
                    skipped--;
                index++;
                current = &DAT_011bfce8[index];
            }
            else
                skipped++;
        }
    }
    slot16();
    slot1c();
    slot2f();
    slot36();
    defaults.FUN_00e94130();
    SetState(22, 2, 0, 0);
    SetState(8, 3, 0, 0);
    SetState(9, 2, 0, 0);
    SetState(27, 0, 0, 0);
    SetState(19, blendSource, 0, 0);
    SetState(20, blendDestination, 0, 0);
    SetState(15, 0, 0, 0);
    SetState(25, 8, 0, 0);
    SetState(24, 0, 0, 0);
    SetState(23, 8, 0, 0);
    SetState(14, 0, 0, 0);
    SetState(26, 0, 0, 0);
    SetState(29, 0, 0, 0);
    SetState(28, 0, 0, 0);
    SetState(35, (flags08 & 1) ? 3 : 0, 0, 0);
    SetState(140, 3, 0, 0);
    SetState(48, 0, 0, 0);
    SetState(34, 0, 0, 0);
    SetState(143, 1, 0, 0);
    SetState(7, 1, 0, 0);
    SetState(141, 1, 0, 0);
    color = DAT_011f4998;
    packedColor =
        (((((unsigned int)0xff << 8) | (unsigned char)(color.r * 255.0)) << 8) | (unsigned char)(color.g * 255.0))
            << 8 |
        (unsigned char)(color.b * 255.0);
}

struct Counts
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
};

// Normalizes fmt (6->2) and tile (3->0), then returns the first non-zero Counts field chosen by fmt and tile, or 0.
// @fnv 0x00e89ed0
int __cdecl SelectFormatTileValue(Pair* p, Counts* pCounts)
{
    int fmt = p->a;
    int tile = p->b;
    if (fmt == 6)
        fmt = 2;
    if (tile == 3)
        tile = 0;
    if ((fmt == 0 || fmt == 5) && tile == 0)
    {
        if (pCounts->f18)
            return pCounts->f18;
    }
    else if ((fmt == 0 || fmt == 5) && (tile == 1 || tile == 2))
    {
        if (pCounts->f1c)
            return pCounts->f1c;
    }
    switch (fmt)
    {
    case 0:
    case 3:
    case 5:
        switch (tile)
        {
        case 0:
        case 1:
            if (pCounts->f20)
                return pCounts->f20;
            break;
        case 2:
            if (pCounts->f24)
                return pCounts->f24;
            break;
        }
    case 1:
        switch (tile)
        {
        case 0:
            if (pCounts->f04)
                return pCounts->f04;
            if (pCounts->f00)
                return pCounts->f00;
            if (pCounts->f08)
                return pCounts->f08;
            if (pCounts->f14)
                return pCounts->f14;
            if (pCounts->f0c)
                return pCounts->f0c;
            if (pCounts->f10)
                return pCounts->f10;
            break;
        case 1:
            if (pCounts->f0c)
                return pCounts->f0c;
            if (pCounts->f10)
                return pCounts->f10;
            if (pCounts->f14)
                return pCounts->f14;
            break;
        case 2:
            if (pCounts->f10)
                return pCounts->f10;
            if (pCounts->f14)
                return pCounts->f14;
            break;
        }
        break;
    case 4:
        if (pCounts->f34)
            return pCounts->f34;
        if (tile == 0)
        {
            if (pCounts->f2c)
                return pCounts->f2c;
            if (pCounts->f30)
                return pCounts->f30;
        }
        else
        {
            if (pCounts->f30)
                return pCounts->f30;
            if (pCounts->f2c)
                return pCounts->f2c;
        }
    case 2:
        switch (tile)
        {
        case 0:
            if (pCounts->f08)
                return pCounts->f08;
            if (pCounts->f14)
                return pCounts->f14;
            if (pCounts->f04)
                return pCounts->f04;
            if (pCounts->f00)
                return pCounts->f00;
            if (pCounts->f0c)
                return pCounts->f0c;
            if (pCounts->f10)
                return pCounts->f10;
            break;
        case 1:
            if (pCounts->f14)
                return pCounts->f14;
            if (pCounts->f0c)
                return pCounts->f0c;
            if (pCounts->f10)
                return pCounts->f10;
            break;
        case 2:
            if (pCounts->f14)
                return pCounts->f14;
            if (pCounts->f10)
                return pCounts->f10;
            break;
        }
        break;
    case 7:
        if (tile == 0)
        {
            if (pCounts->f38)
                return pCounts->f38;
            if (pCounts->f04)
                return pCounts->f04;
            if (pCounts->f00)
                return pCounts->f00;
            if (pCounts->f08)
                return pCounts->f08;
            if (pCounts->f14)
                return pCounts->f14;
            if (pCounts->f0c)
                return pCounts->f0c;
            if (pCounts->f10)
                return pCounts->f10;
        }
        else
        {
            if (pCounts->f3c)
                return pCounts->f3c;
            if (pCounts->f0c)
                return pCounts->f0c;
            if (pCounts->f10)
                return pCounts->f10;
            if (pCounts->f14)
                return pCounts->f14;
        }
        break;
    case 8:
        if (pCounts->f40)
            return pCounts->f40;
        if (pCounts->f4c)
            return pCounts->f4c;
    case 10:
        if (pCounts->f44)
            return pCounts->f44;
        if (pCounts->f50)
            return pCounts->f50;
    case 12:
    case 13:
        if (pCounts->f48)
            return pCounts->f48;
        if (pCounts->f54)
            return pCounts->f54;
        break;
    case 9:
        if (pCounts->f4c)
            return pCounts->f4c;
        if (pCounts->f50)
            return pCounts->f50;
        if (pCounts->f54)
            return pCounts->f54;
        if (pCounts->f40)
            return pCounts->f40;
        if (pCounts->f44)
            return pCounts->f44;
        if (pCounts->f48)
            return pCounts->f48;
        break;
    case 11:
        if (pCounts->f50)
            return pCounts->f50;
        if (pCounts->f54)
            return pCounts->f54;
        if (pCounts->f44)
            return pCounts->f44;
        if (pCounts->f48)
            return pCounts->f48;
        break;
    case 14:
        if (pCounts->f54)
            return pCounts->f54;
        if (pCounts->f48)
            return pCounts->f48;
        break;
    }
    return 0;
}

// @fnv 0x00e902d0
// src: COMMUNITY 0x00e902d0
int NiDX9DynamicTextureData::GetTexture_00e902d0()
{
    return reinterpret_cast<int>(m_pkSysMemTexture);
}

// @fnv 0x00e902e0
// src: COMMUNITY 0x00e902e0
char NiDX9DynamicTextureData::IsTextureLocked()
{
    return *reinterpret_cast<char*>(&unk70);
}

void __cdecl LinkPalette();
// @fnv 0x00e91700
// src: XBOX_PDB 0x00e91700
void __cdecl NiDX9PersistentSrcTextureRendererData_LinkObject()
{
    LinkPalette();
}

struct NiPersistentSrcTextureRendererData_s
{
    void FUN_00a984b0(NiStream&);
    void NiDX9PersistentSrcTextureRendererData_SaveBinary(NiStream& stream);
};
// @fnv 0x00e91730
// src: XBOX_PDB 0x00e91730
void NiPersistentSrcTextureRendererData_s::NiDX9PersistentSrcTextureRendererData_SaveBinary(NiStream& stream)
{
    FUN_00a984b0(stream);
}

extern "C" int __cdecl rand();
extern const double DAT_01029790;

struct Parameters807
{
    float unk00, unk04, unk08, spread;
};
struct Emitter807
{
    void FUN_00e807d0(void*, int, int, void*, void*, void*, const NiTransform*, const Parameters807*);
    void NiDX9ErrorShader_SetupTransformations(void*, void*, void*, void*, void*, void*, const NiTransform*, const Parameters807*);
};
// Adds random offsets to the input transform's x, y, and z using params->spread, then calls FUN_00e807d0.
// @fnv 0x00e90760
// src: COMMUNITY 0x00e90760
void Emitter807::NiDX9ErrorShader_SetupTransformations(void* a1, void* apUnused1, void* apUnused2, void* a4, void* a5, void* a6,
                              const NiTransform* apTransform, const Parameters807* params)
{
    // Preserve the original POD copy without calling NiTransform's identity constructor.
    void* transformStorage[(sizeof(NiTransform) + sizeof(void*) - 1) / sizeof(void*)];
    NiTransform& transform = *reinterpret_cast<NiTransform*>(transformStorage);
    memcpy(&transform, apTransform, sizeof(transform));
    float fJitter = params->spread * double(0.1f);
    transform.m_Translate.x += float((rand() * 2.0) / DAT_01029790 - 1.0) * fJitter;
    transform.m_Translate.y += float((rand() * 2.0) / DAT_01029790 - 1.0) * fJitter;
    transform.m_Translate.z += float((rand() * 2.0) / DAT_01029790 - 1.0) * fJitter;
    FUN_00e807d0(a1, 0, 0, a4, a5, a6, &transform, params);
}

struct TextureFormatPreferences
{
    unsigned int pixelLayout, alphaFormat, mipmaps;
};
struct PixelFormat
{
    unsigned int unk00, unk04, unk08, format;
};
struct FormatCache
{
    unsigned int unk00;
};
struct CubeSurface;
class Device
{
  public:
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual int __stdcall CreateCubeTexture(unsigned int edge, unsigned int levels, unsigned int usage,
                                            unsigned int format, unsigned int pool, CubeSurface** surface,
                                            void* shared);
};
class Renderer
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    Device* device;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    FormatCache formatCache;
};
class Texture
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual unsigned int GetWidth();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    TextureFormatPreferences prefs;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned char unk40, hasFormat, unk42, unk43;
    unsigned int format;
};
PixelFormat* __cdecl SelectFormatTileValue(TextureFormatPreferences*, FormatCache*);
const char* __cdecl GetHResultName(int);
void __cdecl Object_DoNothing(const char*, const char*);
class CubeData
{
  public:
    unsigned int unk00, unk04, unk08, width, height, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    Renderer* renderer;
    CubeSurface* surface;
    unsigned int flags;
    PixelFormat* CreateSurface(Texture* texture);
};
// Creates a cube texture surface of the given size using the renderer's device, selecting a pixel format from the texture's preferences and storing it in surface.
// @fnv 0x00e900c0
PixelFormat* CubeData::CreateSurface(Texture* texture)
{
    if (!texture)
        return 0;
    unsigned int size = texture->GetWidth();
    height = size;
    width = size;
    flags = 1;
    TextureFormatPreferences prefs = texture->prefs;
    Renderer* r = renderer;
    PixelFormat* result = SelectFormatTileValue(&prefs, &r->formatCache);
    unsigned int format = result->format;
    if (texture->hasFormat)
        format = texture->format;
    Device* dev = renderer->device;
    CubeSurface* out = 0;
    int hr = dev->CreateCubeTexture(width, 1, 1, format, 0, &out, 0);
    if (hr < 0)
    {
        Object_DoNothing("NiDX9RenderedCubeMapData::CreateSurf> Failed CreateImageSurface - %s", GetHResultName(hr));
        surface = 0;
        return 0;
    }
    surface = out;
    return result;
}

typedef long HRESULT;
struct IDirect3DTexture9;
struct IDirect3DSurface9;

struct PixelProxy
{
    int unk00;
    int unk04;
    int unk08;
    D3DFORMAT format;
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
    int unk38;
    int unk3c;
    int unk40;
};
struct Preferences
{
    int a, b, c;
};
struct RendererProxy
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    IDirect3DDevice9* device;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
};
struct TextureProxy
{
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
    virtual unsigned int width();
    virtual unsigned int height();
    int unk04, unk08, unk0c, unk10, unk14;
    Preferences prefs;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    bool renderTarget, overrideFormat;
    unsigned short unk42;
    D3DFORMAT format;
};
PixelProxy* SelectFormatTileValue(const Preferences&, void*);
D3DMULTISAMPLE_TYPE Runtime_GetIndexMask(int);
const char* GetHResultName(HRESULT);
void Object_DoNothing(const char*, ...);
extern bool DAT_0126f0d0;
struct OwnerProxy
{
    int unk00, unk04, unk08;
    unsigned int width, height;
    PixelProxy pixel;
    int unk58, unk5c;
    RendererProxy* renderer;
    IDirect3DTexture9* texture;
    int unk68;
    IDirect3DSurface9* surface;
    PixelProxy* NiDX9RenderedTextureData_CreateSurf(TextureProxy*, int);
};
// Creates a D3D texture and optional render target from source dimensions and format, storing the result in texture and surface.
// @fnv 0x00e8fe10
// src: EXE 0x00e8fe10
PixelProxy* OwnerProxy::NiDX9RenderedTextureData_CreateSurf(TextureProxy* source, int multisample)
{
    if (!source)
        return 0;
    width = source->width();
    height = source->height();
    unk68 = 1;
    Preferences prefs;
    prefs.a = source->prefs.a;
    prefs.b = source->prefs.b;
    prefs.c = source->prefs.c;
    void* caps = &renderer->unk758;
    PixelProxy* format = SelectFormatTileValue(prefs, caps);
    pixel = *format;
    D3DFORMAT eFormat = format->format;
    unsigned int usage = 0;
    D3DPOOL pool = D3DPOOL_DEFAULT;
    if (source->renderTarget)
        usage = 1;
    else
        pool = DAT_0126f0d0 ? D3DPOOL_DEFAULT : D3DPOOL_MANAGED;
    if (source->overrideFormat)
        eFormat = source->format;
    IDirect3DDevice9* device = renderer->device;
    IDirect3DTexture9* result = 0;
    HRESULT hr = 0;
    if (multisample)
        hr = device->CreateRenderTarget(width, height, eFormat, Runtime_GetIndexMask(multisample), 0, 0, &surface, 0);
    hr |= device->CreateTexture(width, height, 1, usage, eFormat, pool, &result, 0);
    if (hr < 0)
    {
        Object_DoNothing("NiDX9RenderedTextureData::CreateSurf> Failed CreateImageSurface - %s", GetHResultName(hr));
        texture = 0;
        surface = 0;
        return 0;
    }
    texture = result;
    return format;
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

enum TextureSurfacePool
{
    SurfaceDefault = 0,
    SurfaceSystemMemory = 2
};
struct TextureSurface;

struct TextureDeviceView
{
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06();
    virtual void __stdcall v07();
    virtual void __stdcall v08();
    virtual void __stdcall v09();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual void __stdcall v20();
    virtual void __stdcall v21();
    virtual void __stdcall v22();
    virtual long __stdcall CreateTexture(unsigned int width, unsigned int height, unsigned int levels,
                                         unsigned long usage, TextureSurfaceFormat format, TextureSurfacePool pool,
                                         TextureSurface** texture, void** sharedHandle);
};

struct FormatPrefsStandIn
{
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
};

struct DynamicTextureStandIn
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();

    unsigned int m_uiRefCount;
    void* m_pTextureRendererData;
    void* m_pkPrev;
    void* m_pkNext;
    void* m_pkUnk14;
    FormatPrefsStandIn m_kTextureFormatPreferences;
};

struct FormatTableStandIn
{
    int unk00;
};

const NiPixelFormatStandIn* __cdecl GetDestinationPixelFormat(const FormatPrefsStandIn& kPrefs,
                                                              FormatTableStandIn* pkTable);
const char* __cdecl GetD3DErrorString(long hr);
void __cdecl NiOutputDebugStringStandIn(const char* pcFormat, ...);

// @fnv 0x00e90340
// src: EXE 0x00e90340
const NiPixelFormatStandIn* NiDX9DynamicTextureData::CreateSurf_00e90340(DynamicTextureStandIn* pkTexture, bool bDynamic)
{
    if (!pkTexture)
        return 0;

    unk0C = pkTexture->GetWidth();
    unk10 = pkTexture->GetHeight();
    m_uiTextureFormat = 1;

    FormatPrefsStandIn kPrefs = pkTexture->m_kTextureFormatPreferences;
    FormatTableStandIn* pkTable = reinterpret_cast<FormatTableStandIn*>(reinterpret_cast<char*>(m_pOwnerShader) + 0x700);
    const NiPixelFormatStandIn* pkFormat = GetDestinationPixelFormat(kPrefs, pkTable);
    memcpy(&m_kPixelFormat, pkFormat, sizeof(m_kPixelFormat));

    TextureSurfaceFormat eFormat = pkFormat->m_eD3DFormat;
    TextureDeviceView* pkDevice = reinterpret_cast<TextureDeviceView*>(reinterpret_cast<NiDX9Renderer*>(m_pOwnerShader)->pD3DDevice);
    TextureSurface* pkD3DTexture = 0;

    if (bDynamic)
    {
        long hr = pkDevice->CreateTexture(unk0C, unk10, 1, 0x200, eFormat, SurfaceDefault,
                                          &pkD3DTexture, 0);
        if (hr < 0)
        {
            NiOutputDebugStringStandIn("NiDX9DynamicTextureData::CreateSurf> Failed CreateImageSurface - %s",
                                       GetD3DErrorString(hr));
            m_pkCubeMapTexture = 0;
            return 0;
        }
        m_pkCubeMapTexture = pkD3DTexture;
        return pkFormat;
    }

    long hr = pkDevice->CreateTexture(unk0C, unk10, 1, 0, eFormat, SurfaceDefault, &pkD3DTexture, 0);
    if (hr < 0)
    {
        NiOutputDebugStringStandIn("NiDX9DynamicTextureData::CreateSurf> Failed CreateImageSurface - %s",
                                   GetD3DErrorString(hr));
        m_pkCubeMapTexture = 0;
        return 0;
    }
    m_pkCubeMapTexture = pkD3DTexture;

    pkD3DTexture = 0;
    hr = pkDevice->CreateTexture(unk0C, unk10, 1, 0, eFormat, SurfaceSystemMemory, &pkD3DTexture, 0);
    if (hr < 0)
    {
        NiOutputDebugStringStandIn("NiDX9DynamicTextureData::CreateSurf> Failed CreateImageSurface - %s",
                                   GetD3DErrorString(hr));
        m_pkSysMemTexture = 0;
        return 0;
    }
    m_pkSysMemTexture = pkD3DTexture;
    return pkFormat;
}

struct FnvRttiNode
{
    const char* name;
    FnvRttiNode* base;
};
struct FnvResource
{
    virtual void v0();
    virtual void Release();
};
struct FnvOutput;
struct FnvSource
{
    virtual void v0();
    virtual void v1();
    virtual FnvRttiNode* GetRTTI();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void NotifyResourceCreated();
};
struct FnvDevice
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual unsigned int GetCapabilities();
};
struct FnvResourceManager
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual FnvResource* Acquire(int kind, int a, int b);
    virtual void v4();
    virtual FnvResource* Convert(FnvResource* original, void* pixels, FnvResource* old, bool useMipmaps);
};
struct FnvD3dDevice
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual long __stdcall CreateTexture(unsigned a, unsigned b, unsigned c, int d, int e, int source);
};
extern "C" unsigned char DAT_011f4454;
extern "C" unsigned char DAT_010ed37c;
extern "C" unsigned char DAT_010ed4dc;
extern "C" unsigned char DAT_011f4509;
extern "C" unsigned char DAT_011f4508;
extern "C" unsigned char DAT_011f4448;

extern "C" FnvD3dDevice* DAT_0126f0d8;
void* __cdecl Object_DispatchCommandFour(unsigned int);

struct SourcePixelFormat
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
};

struct FnvOutput;
FnvOutput* __cdecl NiDX9SourceCubeMapData_Create(FnvSource*, FnvDevice*);
FnvResourceManager* __cdecl FUN_00a76640();
FnvResource* __cdecl DispatchIfHighBitSet(FnvSource*, unsigned, int);
void __cdecl Object_DoNothing(void*, int);
int __cdecl FUN_00e7bd20(const SourcePixelFormat*);

struct SourceFields
{
    unsigned u00;
    unsigned u04;
    unsigned u08;
    unsigned u0c;
    unsigned u10;
    unsigned u14;
    unsigned prefs0;
    unsigned prefs1;
    unsigned prefs2;
    FnvOutput* rendererData;
    unsigned u28;
    unsigned u2c;
    unsigned u30;
    int kind;
    FnvResource* existing;
    FnvResource* cached;
    unsigned char u40;
    unsigned char fast;
    unsigned char u42;
    unsigned char u43;
    unsigned flags;
};
struct ResourceFields
{
    unsigned u00;
    volatile long refs;
    unsigned u08;
    unsigned u0c;
    unsigned sampler;
};
struct CachedFields
{
    unsigned u00;
    unsigned u04;
    SourcePixelFormat format;
    FnvResource* secondary;
    unsigned u50;
    unsigned* width;
    unsigned* height;
    int* sizes;
    unsigned mipLevels;
    unsigned u64;
    void* pixels;
    int faces;
};
struct ExistingFields
{
    unsigned u00;
    unsigned u04;
    unsigned u08;
    unsigned u0c;
    unsigned u10;
    SourcePixelFormat format;
    unsigned u58;
    unsigned u5c;
    unsigned u60;
    unsigned* width;
    unsigned* height;
    int* sizes;
    unsigned u70;
    unsigned mipLevels;
    unsigned u78;
    int faces;
    unsigned u80;
    unsigned u84;
    unsigned u88;
    unsigned u8c;
    FnvResource* secondary;
};
struct TextureRendererFields
{
    unsigned u000;
    unsigned u004;
    unsigned u008;
    unsigned u00c;
    unsigned u010;
    unsigned u014;
    unsigned u018;
    unsigned u01c;
    unsigned u020;
    unsigned u024;
    unsigned u028;
    unsigned u02c;
    unsigned u030;
    unsigned u034;
    unsigned u038;
    unsigned u03c;
    unsigned u040;
    unsigned u044;
    unsigned u048;
    unsigned u04c;
    unsigned u050;
    unsigned u054;
    unsigned u058;
    unsigned u05c;
    unsigned u060;
    unsigned u064;
    unsigned u068;
    unsigned u06c;
    unsigned u070;
    unsigned u074;
    unsigned u078;
    unsigned u07c;
    unsigned u080;
    unsigned u084;
    unsigned u088;
    unsigned u08c;
    unsigned u090;
    unsigned u094;
    unsigned u098;
    unsigned u09c;
    unsigned u0a0;
    unsigned u0a4;
    unsigned u0a8;
    unsigned u0ac;
    unsigned u0b0;
    unsigned u0b4;
    unsigned u0b8;
    unsigned u0bc;
    unsigned u0c0;
    unsigned u0c4;
    unsigned u0c8;
    unsigned u0cc;
    unsigned u0d0;
    unsigned u0d4;
    unsigned u0d8;
    unsigned u0dc;
    unsigned u0e0;
    unsigned u0e4;
    unsigned u0e8;
    unsigned u0ec;
    unsigned u0f0;
    unsigned u0f4;
    unsigned u0f8;
    unsigned u0fc;
    unsigned u100;
    unsigned u104;
    unsigned u108;
    unsigned u10c;
    unsigned u110;
    unsigned u114;
    unsigned u118;
    unsigned u11c;
    unsigned u120;
    unsigned u124;
    unsigned u128;
    unsigned u12c;
    unsigned u130;
    unsigned u134;
    unsigned u138;
    unsigned u13c;
    unsigned u140;
    unsigned u144;
    unsigned u148;
    unsigned u14c;
    unsigned u150;
    unsigned u154;
    unsigned u158;
    unsigned u15c;
    unsigned u160;
    unsigned u164;
    unsigned u168;
    unsigned u16c;
    unsigned u170;
    unsigned u174;
    unsigned u178;
    unsigned u17c;
    unsigned u180;
    unsigned u184;
    unsigned u188;
    unsigned u18c;
    unsigned u190;
    unsigned u194;
    unsigned u198;
    unsigned u19c;
    unsigned u1a0;
    unsigned u1a4;
    unsigned u1a8;
    unsigned u1ac;
    unsigned u1b0;
    unsigned u1b4;
    unsigned u1b8;
    unsigned u1bc;
    unsigned u1c0;
    unsigned u1c4;
    unsigned u1c8;
    unsigned u1cc;
    unsigned u1d0;
    unsigned u1d4;
    unsigned u1d8;
    unsigned u1dc;
    unsigned u1e0;
    unsigned u1e4;
    unsigned u1e8;
    unsigned u1ec;
    unsigned u1f0;
    unsigned u1f4;
    unsigned u1f8;
    unsigned u1fc;
    unsigned u200;
    unsigned u204;
    unsigned u208;
    unsigned u20c;
    unsigned u210;
    unsigned u214;
    unsigned u218;
    unsigned u21c;
    unsigned u220;
    unsigned u224;
    unsigned u228;
    unsigned u22c;
    unsigned u230;
    unsigned u234;
    unsigned u238;
    unsigned u23c;
    unsigned u240;
    unsigned u244;
    unsigned u248;
    unsigned u24c;
    unsigned u250;
    unsigned u254;
    unsigned u258;
    unsigned u25c;
    unsigned u260;
    unsigned u264;
    unsigned u268;
    unsigned u26c;
    unsigned u270;
    unsigned u274;
    unsigned u278;
    unsigned u27c;
    unsigned u280;
    unsigned u284;
    unsigned u288;
    unsigned u28c;
    unsigned u290;
    unsigned u294;
    unsigned u298;
    unsigned u29c;
    unsigned u2a0;
    unsigned u2a4;
    unsigned u2a8;
    unsigned u2ac;
    unsigned u2b0;
    unsigned u2b4;
    unsigned u2b8;
    unsigned u2bc;
    unsigned u2c0;
    unsigned u2c4;
    unsigned u2c8;
    unsigned u2cc;
    unsigned u2d0;
    unsigned u2d4;
    unsigned u2d8;
    unsigned u2dc;
    unsigned u2e0;
    unsigned u2e4;
    unsigned u2e8;
    unsigned u2ec;
    unsigned u2f0;
    unsigned u2f4;
    unsigned u2f8;
    unsigned u2fc;
    unsigned u300;
    unsigned u304;
    unsigned u308;
    unsigned u30c;
    unsigned u310;
    unsigned u314;
    unsigned u318;
    unsigned u31c;
    unsigned u320;
    unsigned u324;
    unsigned u328;
    unsigned u32c;
    unsigned u330;
    unsigned u334;
    unsigned u338;
    unsigned u33c;
    unsigned u340;
    unsigned u344;
    unsigned u348;
    unsigned u34c;
    unsigned u350;
    unsigned u354;
    unsigned u358;
    unsigned u35c;
    unsigned u360;
    unsigned u364;
    unsigned u368;
    unsigned u36c;
    unsigned u370;
    unsigned u374;
    unsigned u378;
    unsigned u37c;
    unsigned u380;
    unsigned u384;
    unsigned u388;
    unsigned u38c;
    unsigned u390;
    unsigned u394;
    unsigned u398;
    unsigned u39c;
    unsigned u3a0;
    unsigned u3a4;
    unsigned u3a8;
    unsigned u3ac;
    unsigned u3b0;
    unsigned u3b4;
    unsigned u3b8;
    unsigned u3bc;
    unsigned u3c0;
    unsigned u3c4;
    unsigned u3c8;
    unsigned u3cc;
    unsigned u3d0;
    unsigned u3d4;
    unsigned u3d8;
    unsigned u3dc;
    unsigned u3e0;
    unsigned u3e4;
    unsigned u3e8;
    unsigned u3ec;
    unsigned u3f0;
    unsigned u3f4;
    unsigned u3f8;
    unsigned u3fc;
    unsigned u400;
    unsigned u404;
    unsigned u408;
    unsigned u40c;
    unsigned u410;
    unsigned u414;
    unsigned u418;
    unsigned u41c;
    unsigned u420;
    unsigned u424;
    unsigned u428;
    unsigned u42c;
    unsigned u430;
    unsigned u434;
    unsigned u438;
    unsigned u43c;
    unsigned u440;
    unsigned u444;
    unsigned u448;
    unsigned u44c;
    unsigned u450;
    unsigned u454;
    unsigned u458;
    unsigned u45c;
    unsigned u460;
    unsigned u464;
    unsigned u468;
    unsigned u46c;
    unsigned u470;
    unsigned u474;
    unsigned u478;
    unsigned u47c;
    unsigned u480;
    unsigned u484;
    unsigned u488;
    unsigned u48c;
    unsigned u490;
    unsigned u494;
    unsigned u498;
    unsigned u49c;
    unsigned u4a0;
    unsigned u4a4;
    unsigned u4a8;
    unsigned u4ac;
    unsigned u4b0;
    unsigned u4b4;
    unsigned u4b8;
    unsigned u4bc;
    unsigned u4c0;
    unsigned u4c4;
    unsigned u4c8;
    unsigned u4cc;
    unsigned u4d0;
    unsigned u4d4;
    unsigned u4d8;
    unsigned u4dc;
    unsigned u4e0;
    unsigned u4e4;
    unsigned u4e8;
    unsigned u4ec;
    unsigned u4f0;
    unsigned u4f4;
    unsigned u4f8;
    unsigned u4fc;
    unsigned u500;
    unsigned u504;
    unsigned u508;
    unsigned u50c;
    unsigned u510;
    unsigned u514;
    unsigned u518;
    unsigned u51c;
    unsigned u520;
    unsigned u524;
    unsigned u528;
    unsigned u52c;
    unsigned u530;
    unsigned u534;
    unsigned u538;
    unsigned u53c;
    unsigned u540;
    unsigned u544;
    unsigned u548;
    unsigned u54c;
    unsigned u550;
    unsigned u554;
    unsigned u558;
    unsigned u55c;
    unsigned u560;
    unsigned u564;
    unsigned u568;
    unsigned u56c;
    unsigned u570;
    unsigned u574;
    unsigned u578;
    unsigned u57c;
    unsigned u580;
    unsigned u584;
    unsigned u588;
    unsigned u58c;
    unsigned u590;
    unsigned u594;
    unsigned u598;
    unsigned u59c;
    unsigned u5a0;
    unsigned u5a4;
    unsigned u5a8;
    unsigned u5ac;
    unsigned u5b0;
    unsigned u5b4;
    unsigned u5b8;
    unsigned u5bc;
    unsigned u5c0;
    unsigned adapter;
    unsigned devType;
    unsigned u5cc;
    unsigned adapterFormat;
};
struct DeviceFields
{
    unsigned u000;
    unsigned u004;
    unsigned u008;
    unsigned u00c;
    unsigned u010;
    unsigned u014;
    unsigned u018;
    unsigned u01c;
    unsigned u020;
    unsigned u024;
    unsigned u028;
    unsigned u02c;
    unsigned u030;
    unsigned u034;
    unsigned u038;
    unsigned u03c;
    unsigned u040;
    unsigned u044;
    unsigned u048;
    unsigned u04c;
    unsigned u050;
    unsigned u054;
    unsigned u058;
    unsigned u05c;
    unsigned u060;
    unsigned u064;
    unsigned u068;
    unsigned u06c;
    unsigned u070;
    unsigned u074;
    unsigned u078;
    unsigned u07c;
    unsigned u080;
    unsigned u084;
    unsigned u088;
    unsigned u08c;
    unsigned u090;
    unsigned u094;
    unsigned u098;
    unsigned u09c;
    unsigned u0a0;
    unsigned u0a4;
    unsigned u0a8;
    unsigned u0ac;
    unsigned u0b0;
    unsigned u0b4;
    unsigned u0b8;
    unsigned u0bc;
    unsigned u0c0;
    unsigned u0c4;
    unsigned u0c8;
    unsigned u0cc;
    unsigned u0d0;
    unsigned u0d4;
    unsigned u0d8;
    unsigned u0dc;
    unsigned u0e0;
    unsigned u0e4;
    unsigned u0e8;
    unsigned u0ec;
    unsigned u0f0;
    unsigned u0f4;
    unsigned u0f8;
    unsigned u0fc;
    unsigned u100;
    unsigned u104;
    unsigned u108;
    unsigned u10c;
    unsigned u110;
    unsigned u114;
    unsigned u118;
    unsigned u11c;
    unsigned u120;
    unsigned u124;
    unsigned u128;
    unsigned u12c;
    unsigned u130;
    unsigned u134;
    unsigned u138;
    unsigned u13c;
    unsigned u140;
    unsigned u144;
    unsigned u148;
    unsigned u14c;
    unsigned u150;
    unsigned u154;
    unsigned u158;
    unsigned u15c;
    unsigned u160;
    unsigned u164;
    unsigned u168;
    unsigned u16c;
    unsigned u170;
    unsigned u174;
    unsigned u178;
    unsigned u17c;
    unsigned u180;
    unsigned u184;
    unsigned u188;
    unsigned u18c;
    unsigned u190;
    unsigned u194;
    unsigned u198;
    unsigned u19c;
    unsigned u1a0;
    unsigned u1a4;
    unsigned u1a8;
    unsigned u1ac;
    unsigned u1b0;
    unsigned u1b4;
    unsigned u1b8;
    unsigned u1bc;
    unsigned u1c0;
    unsigned u1c4;
    unsigned u1c8;
    unsigned u1cc;
    unsigned u1d0;
    unsigned u1d4;
    unsigned u1d8;
    unsigned u1dc;
    unsigned u1e0;
    unsigned u1e4;
    unsigned u1e8;
    unsigned u1ec;
    unsigned u1f0;
    unsigned u1f4;
    unsigned u1f8;
    unsigned u1fc;
    unsigned u200;
    unsigned u204;
    unsigned u208;
    unsigned u20c;
    unsigned u210;
    unsigned u214;
    unsigned u218;
    unsigned u21c;
    unsigned u220;
    unsigned u224;
    unsigned u228;
    unsigned u22c;
    unsigned u230;
    unsigned u234;
    unsigned u238;
    unsigned u23c;
    unsigned u240;
    unsigned u244;
    unsigned u248;
    unsigned u24c;
    unsigned u250;
    unsigned u254;
    unsigned u258;
    unsigned u25c;
    unsigned u260;
    unsigned u264;
    unsigned u268;
    unsigned u26c;
    unsigned u270;
    unsigned u274;
    unsigned u278;
    unsigned u27c;
    unsigned u280;
    unsigned u284;
    unsigned u288;
    unsigned u28c;
    unsigned u290;
    unsigned u294;
    unsigned u298;
    unsigned u29c;
    unsigned u2a0;
    unsigned u2a4;
    unsigned u2a8;
    unsigned u2ac;
    unsigned u2b0;
    unsigned u2b4;
    unsigned u2b8;
    unsigned u2bc;
    unsigned u2c0;
    unsigned u2c4;
    unsigned u2c8;
    unsigned u2cc;
    unsigned u2d0;
    unsigned u2d4;
    unsigned u2d8;
    unsigned u2dc;
    unsigned u2e0;
    unsigned u2e4;
    unsigned u2e8;
    unsigned u2ec;
    unsigned u2f0;
    unsigned u2f4;
    unsigned u2f8;
    unsigned u2fc;
    unsigned u300;
    unsigned u304;
    unsigned u308;
    unsigned u30c;
    unsigned u310;
    unsigned u314;
    unsigned u318;
    unsigned u31c;
    unsigned u320;
    unsigned u324;
    unsigned u328;
    unsigned u32c;
    unsigned u330;
    unsigned u334;
    unsigned u338;
    unsigned u33c;
    unsigned u340;
    unsigned u344;
    unsigned u348;
    unsigned u34c;
    unsigned u350;
    unsigned u354;
    unsigned u358;
    unsigned u35c;
    unsigned u360;
    unsigned u364;
    unsigned u368;
    unsigned u36c;
    unsigned u370;
    unsigned u374;
    unsigned u378;
    unsigned u37c;
    unsigned u380;
    unsigned u384;
    unsigned u388;
    unsigned u38c;
    unsigned u390;
    unsigned u394;
    unsigned u398;
    unsigned u39c;
    unsigned u3a0;
    unsigned u3a4;
    unsigned u3a8;
    unsigned u3ac;
    unsigned u3b0;
    unsigned u3b4;
    unsigned u3b8;
    unsigned u3bc;
    unsigned u3c0;
    unsigned u3c4;
    unsigned u3c8;
    unsigned u3cc;
    unsigned u3d0;
    unsigned u3d4;
    unsigned u3d8;
    unsigned u3dc;
    unsigned u3e0;
    unsigned u3e4;
    unsigned u3e8;
    unsigned u3ec;
    unsigned u3f0;
    unsigned u3f4;
    unsigned u3f8;
    unsigned u3fc;
    unsigned u400;
    unsigned u404;
    unsigned u408;
    unsigned u40c;
    unsigned u410;
    unsigned u414;
    unsigned u418;
    unsigned u41c;
    unsigned u420;
    unsigned u424;
    unsigned u428;
    unsigned u42c;
    unsigned u430;
    unsigned u434;
    unsigned u438;
    unsigned u43c;
    unsigned u440;
    unsigned u444;
    unsigned u448;
    unsigned u44c;
    unsigned u450;
    unsigned u454;
    unsigned u458;
    unsigned u45c;
    unsigned u460;
    unsigned u464;
    unsigned u468;
    unsigned u46c;
    unsigned u470;
    unsigned u474;
    unsigned u478;
    unsigned u47c;
    unsigned u480;
    unsigned u484;
    unsigned u488;
    unsigned u48c;
    unsigned u490;
    unsigned u494;
    unsigned u498;
    unsigned u49c;
    unsigned u4a0;
    unsigned u4a4;
    unsigned u4a8;
    unsigned u4ac;
    unsigned u4b0;
    unsigned u4b4;
    unsigned u4b8;
    unsigned u4bc;
    unsigned u4c0;
    unsigned u4c4;
    unsigned u4c8;
    unsigned u4cc;
    unsigned u4d0;
    unsigned u4d4;
    unsigned u4d8;
    unsigned u4dc;
    unsigned u4e0;
    unsigned u4e4;
    unsigned u4e8;
    unsigned u4ec;
    unsigned u4f0;
    unsigned u4f4;
    unsigned u4f8;
    unsigned u4fc;
    unsigned u500;
    unsigned u504;
    unsigned u508;
    unsigned u50c;
    unsigned u510;
    unsigned u514;
    unsigned u518;
    unsigned u51c;
    unsigned u520;
    unsigned u524;
    unsigned u528;
    unsigned u52c;
    unsigned u530;
    unsigned u534;
    unsigned u538;
    unsigned u53c;
    unsigned u540;
    unsigned u544;
    unsigned u548;
    unsigned u54c;
    unsigned u550;
    unsigned u554;
    unsigned u558;
    unsigned u55c;
    unsigned u560;
    unsigned u564;
    unsigned u568;
    unsigned u56c;
    unsigned u570;
    unsigned u574;
    unsigned u578;
    unsigned u57c;
    unsigned u580;
    unsigned u584;
    unsigned u588;
    unsigned u58c;
    unsigned u590;
    unsigned u594;
    unsigned u598;
    unsigned u59c;
    unsigned u5a0;
    unsigned u5a4;
    unsigned u5a8;
    unsigned u5ac;
    unsigned u5b0;
    unsigned u5b4;
    unsigned u5b8;
    unsigned u5bc;
    unsigned u5c0;
    unsigned u5c4;
    unsigned u5c8;
    unsigned u5cc;
    unsigned u5d0;
    unsigned u5d4;
    unsigned u5d8;
    unsigned u5dc;
    unsigned u5e0;
    unsigned u5e4;
    unsigned u5e8;
    unsigned u5ec;
    unsigned u5f0;
    unsigned u5f4;
    unsigned u5f8;
    unsigned u5fc;
    unsigned u600;
    unsigned u604;
    unsigned u608;
    unsigned u60c;
    unsigned u610;
    unsigned u614;
    unsigned u618;
    unsigned u61c;
    unsigned u620;
    unsigned u624;
    unsigned u628;
    unsigned u62c;
    unsigned u630;
    unsigned u634;
    unsigned u638;
    unsigned u63c;
    unsigned u640;
    unsigned u644;
    unsigned u648;
    unsigned u64c;
    unsigned u650;
    unsigned u654;
    unsigned u658;
    unsigned u65c;
    unsigned u660;
    unsigned u664;
    unsigned u668;
    unsigned u66c;
    unsigned u670;
    unsigned u674;
    unsigned u678;
    unsigned u67c;
    unsigned u680;
    unsigned u684;
    unsigned u688;
    unsigned u68c;
    unsigned u690;
    unsigned u694;
    unsigned u698;
    unsigned u69c;
    unsigned u6a0;
    unsigned u6a4;
    unsigned u6a8;
    unsigned u6ac;
    unsigned u6b0;
    unsigned u6b4;
    unsigned u6b8;
    unsigned u6bc;
    unsigned u6c0;
    unsigned u6c4;
    unsigned u6c8;
    unsigned u6cc;
    unsigned u6d0;
    unsigned u6d4;
    unsigned u6d8;
    unsigned u6dc;
    unsigned u6e0;
    unsigned u6e4;
    unsigned u6e8;
    unsigned u6ec;
    unsigned u6f0;
    unsigned u6f4;
    unsigned u6f8;
    unsigned u6fc;
    void* formats[96];
    unsigned fallback;
};

struct S68ef0_SP
{
    FnvResource* m_p;
    void FUN_00a5f860(FnvResource*);
    void Set(FnvResource* p)
    {
        if (m_p != p)
            FUN_00a5f860(p);
    }
};
struct S68ef0_Ref
{
    FnvResource* m_p;
    S68ef0_Ref(FnvResource* p) : m_p(p)
    {
        if (m_p)
            InterlockedIncrement(&reinterpret_cast<ResourceFields*>(m_p)->refs);
    }
    ~S68ef0_Ref()
    {
        if (m_p && !InterlockedDecrement(&reinterpret_cast<ResourceFields*>(m_p)->refs))
            m_p->Release();
    }
};
struct S68ef0_Small
{
    unsigned a;
    unsigned b;
    unsigned c;
};
struct FnvSourceFmt
{
    int vtbl;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    SourcePixelFormat fmt;
};
namespace SourceTextureConstruction {
struct FUN_00e8a260 : ::FUN_00e8a260
{
    FUN_00e8a260(unsigned int source, unsigned int device);
};
}
struct FnvOutput : SourceTextureConstruction::FUN_00e8a260
{
    unsigned char m_failure;
    bool m_hasMipmaps;
    unsigned int m_totalSize;
    S68ef0_SP m_textureHolder;
    unsigned int m_generation;
    void* m_pixels;
    unsigned int m_sampler;
    FnvOutput(FnvSource* source, FnvDevice* device)
        : SourceTextureConstruction::FUN_00e8a260((unsigned int)source, (unsigned int)device)
    {
        m_00 = (int)&DAT_010ed37c;
        m_failure = 0;
        m_hasMipmaps = 0;
        m_totalSize = 0;
        m_textureHolder.m_p = 0;
        m_generation = 0;
        m_pixels = 0;
        m_sampler = 0;
    }
    bool LoadFromFilename(int kind, FnvDevice*, const SourcePixelFormat*, unsigned);
    void* NiDX9TextureData_FindMatchingPixelFormat(const SourcePixelFormat*, const SourcePixelFormat*, void*);
    void CreateTextureFromInput(FnvResource*, int);
    void NiDX9SourceTextureData_CopyRendererDataToSurface(FnvResource*);
    void CreateSurf(FnvResource*);
    void NiDX9SourceTextureData_CopyDataToSurface(FnvResource*);
};
static bool FnvIsPowerOfTwo(unsigned value)
{
    if (value == 0)
        return false;
    return (value & (value - 1)) == 0;
}

// Creates an FnvOutput for a source and device, resolving pixel data and texture resources while handling failures and reference counting.
// @fnv 0x00e68ef0
// src: COMMUNITY 0x00e68ef0
FnvOutput* __cdecl NiDX9SourceTextureData_Create(FnvSource* source, FnvDevice* device)
{
    if (source)
    {
        for (FnvRttiNode* type = source->GetRTTI(); type; type = type->base)
        {
            if (type == (FnvRttiNode*)&DAT_011f4454)
                return NiDX9SourceCubeMapData_Create(source, device);
        }
    }
    void** deviceState = reinterpret_cast<DeviceFields*>(device)->formats;
    void* storage = Object_DispatchCommandFour(sizeof(FnvOutput));
    FnvOutput* output = storage ? new (storage) FnvOutput(source, device) : 0;
    const SourcePixelFormat& format = reinterpret_cast<FnvSourceFmt*>(source)->fmt;
    FnvResource* existing = reinterpret_cast<SourceFields*>(source)->existing;
    FnvResource* cached = 0;
    if (!existing)
    {
        cached = reinterpret_cast<SourceFields*>(source)->cached;
        if (!cached)
        {
            int kind = reinterpret_cast<SourceFields*>(source)->kind;
            if (DAT_011f4509 && reinterpret_cast<SourceFields*>(source)->fast && device)
            {
                unsigned flags = reinterpret_cast<SourceFields*>(source)->flags;
                if (output->LoadFromFilename(kind, device, &format, flags))
                {
                    reinterpret_cast<SourceFields*>(output->m_08)->rendererData = output;
                    return output;
                }
            }
            cached = FUN_00a76640()->Acquire(kind, 0, 0);
        }
    }
    void* pixelData = 0;
    FnvResource* held = cached;
    if (held)
        InterlockedIncrement(&reinterpret_cast<ResourceFields*>(held)->refs);
    int texture;
    unsigned devType;
    unsigned adapterFormat;
    unsigned adapter;
    if (!existing && !cached)
    {
        cached = DispatchIfHighBitSet(source, 0x80000005, 1);
        Object_DoNothing(&DAT_010ed4dc, reinterpret_cast<SourceFields*>(source)->kind);
        output->m_failure = 1;
    }
    else if (existing)
    {
        const SourcePixelFormat& srcFormat = reinterpret_cast<ExistingFields*>(existing)->format;
        if ((!FnvIsPowerOfTwo(*reinterpret_cast<ExistingFields*>(existing)->width) ||
             !FnvIsPowerOfTwo(*reinterpret_cast<ExistingFields*>(existing)->height)) &&
            !(device->GetCapabilities() & 8))
        {
            if (device->GetCapabilities() & 4)
            {
                pixelData = output->NiDX9TextureData_FindMatchingPixelFormat(&srcFormat, &format, deviceState);
                if (!pixelData)
                {
                    cached = DispatchIfHighBitSet(source, 0x80000004, 1);
                    output->m_failure = 1;
                }
            }
            else
            {
                cached = DispatchIfHighBitSet(source, 0x80000006, 1);
                output->m_failure = 1;
            }
        }
        else
        {
            pixelData = output->NiDX9TextureData_FindMatchingPixelFormat(&srcFormat, &format, deviceState);
            if (!pixelData)
            {
                cached = DispatchIfHighBitSet(source, 0x80000004, 1);
                output->m_failure = 1;
            }
        }
        texture = FUN_00e7bd20(&reinterpret_cast<ExistingFields*>(existing)->format);
        if (!texture)
        {
            cached = DispatchIfHighBitSet(source, 0x80000004, 1);
            output->m_failure = 1;
        }
        TextureRendererFields* videoState = reinterpret_cast<TextureRendererFields*>(DAT_011f4748);
        FnvD3dDevice* d3d = DAT_0126f0d8;
        adapterFormat = reinterpret_cast<TextureRendererFields*>(videoState)->adapterFormat;
        devType = reinterpret_cast<TextureRendererFields*>(videoState)->devType;
        adapter = reinterpret_cast<TextureRendererFields*>(videoState)->adapter;
        if (d3d->CreateTexture(adapter, devType, adapterFormat, 0, 3, texture) < 0)
        {
            cached = DispatchIfHighBitSet(source, 0x80000004, 1);
            output->m_failure = 1;
        }
    }
    else
    {
        const SourcePixelFormat& dstFormat = reinterpret_cast<CachedFields*>(cached)->format;
        if ((!FnvIsPowerOfTwo(*reinterpret_cast<CachedFields*>(cached)->width) ||
             !FnvIsPowerOfTwo(*reinterpret_cast<CachedFields*>(cached)->height)) &&
            !(device->GetCapabilities() & 8))
        {
            if (device->GetCapabilities() & 4)
            {
                if (format.m_00 == 3)
                {
                    S68ef0_Small adjustedPrefs = *reinterpret_cast<const S68ef0_Small*>(&format);
                    adjustedPrefs.a = 2;
                    pixelData = output->NiDX9TextureData_FindMatchingPixelFormat(
                        &dstFormat, reinterpret_cast<const SourcePixelFormat*>(&adjustedPrefs), deviceState);
                }
                else
                {
                    pixelData = output->NiDX9TextureData_FindMatchingPixelFormat(&dstFormat, &format, deviceState);
                }
                if (!pixelData)
                {
                    cached = DispatchIfHighBitSet(source, 0x80000004, 1);
                    output->m_failure = 1;
                }
            }
            else
            {
                cached = DispatchIfHighBitSet(source, 0x80000006, 1);
                output->m_failure = 1;
            }
        }
        else
        {
            pixelData = output->NiDX9TextureData_FindMatchingPixelFormat(&dstFormat, &format, deviceState);
            if (!pixelData)
            {
                cached = DispatchIfHighBitSet(source, 0x80000004, 1);
                output->m_failure = 1;
            }
        }
    }
    if (output->m_failure)
        pixelData = deviceState[reinterpret_cast<DeviceFields*>(device)->fallback];
    if (!output->m_failure && existing)
    {
        *reinterpret_cast<SourcePixelFormat*>(&output->m_14) = reinterpret_cast<ExistingFields*>(existing)->format;
        output->m_0c = *reinterpret_cast<ExistingFields*>(existing)->width;
        output->m_10 = *reinterpret_cast<ExistingFields*>(existing)->height;
        output->m_68 = reinterpret_cast<ExistingFields*>(existing)->mipLevels;
        output->m_hasMipmaps = output->m_68 != 1;
        output->m_failure = 0;
        output->m_60 = (int)device;
        output->m_totalSize =
            reinterpret_cast<ExistingFields*>(existing)->sizes[reinterpret_cast<ExistingFields*>(existing)->mipLevels] *
            reinterpret_cast<ExistingFields*>(existing)->faces;
        FnvResource* secondary = reinterpret_cast<ExistingFields*>(existing)->secondary;
        if (secondary)
        {
            output->m_sampler = reinterpret_cast<ResourceFields*>(secondary)->sampler;
            output->m_textureHolder.Set(secondary);
        }
        if (!output->m_64)
            output->CreateTextureFromInput(existing, texture);
        if (output->m_64)
            output->NiDX9SourceTextureData_CopyRendererDataToSurface(existing);
    }
    else
    {
        output->m_pixels = reinterpret_cast<CachedFields*>(cached)->pixels;
        *reinterpret_cast<SourcePixelFormat*>(&output->m_14) = *reinterpret_cast<const SourcePixelFormat*>(pixelData);
        output->m_0c = *reinterpret_cast<CachedFields*>(cached)->width;
        output->m_10 = *reinterpret_cast<CachedFields*>(cached)->height;
        bool mipmaps;
        if (!output->m_failure && (format.m_08 == 1 || (format.m_08 == 2 && DAT_011f4508)))
            mipmaps = true;
        else
            mipmaps = false;
        output->m_hasMipmaps = mipmaps;
        FnvResource* chosen;
        if (output->m_failure)
            chosen = cached;
        else
            chosen = FUN_00a76640()->Convert(cached, pixelData, cached, output->m_hasMipmaps);
        if (!output->m_64)
            output->CreateSurf(chosen);
        if (output->m_64)
            output->NiDX9SourceTextureData_CopyDataToSurface(chosen);
        output->m_68 = reinterpret_cast<CachedFields*>(chosen)->mipLevels;
        FnvResource* secondary = reinterpret_cast<CachedFields*>(cached)->secondary;
        if (secondary)
        {
            output->m_sampler = reinterpret_cast<ResourceFields*>(secondary)->sampler;
            if (output->m_textureHolder.m_p != secondary)
                output->m_textureHolder.FUN_00a5f860(secondary);
        }
        output->m_totalSize =
            reinterpret_cast<CachedFields*>(chosen)->sizes[reinterpret_cast<CachedFields*>(chosen)->mipLevels] *
            reinterpret_cast<CachedFields*>(chosen)->faces;
        InterlockedIncrement(&reinterpret_cast<ResourceFields*>(chosen)->refs);
        if (!InterlockedDecrement(&reinterpret_cast<ResourceFields*>(chosen)->refs))
            chosen->Release();
    }
    reinterpret_cast<SourceFields*>(output->m_08)->rendererData = output;
    if (DAT_011f4448)
        source->NotifyResourceCreated();
    if (held && !InterlockedDecrement(&reinterpret_cast<ResourceFields*>(held)->refs))
        held->Release();
    return output;
}




void* __cdecl CreateDepthBufferData(void*, unsigned int, void*, int, void**);
void __cdecl Object_DoNothing(const char*, const char*);
extern unsigned int DAT_0126f9e0;
extern unsigned int DAT_0126f9e4;
struct CubeMapBaseInit
{
    int* m_iWordAt00;
    void* InitWithArgs(int, int, int);
};
extern int DAT_010f049c;

// Allocates a NiDX9RenderedCubeMapData, creates six D3D cube faces, and accumulates texture memory usage into global counters.
// @fnv 0x00e901a0
// src: COMMUNITY 0x00e901a0
NiDX9RenderedCubeMapData* __cdecl NiDX9RenderedCubeMapData_Create(NiRenderedCubeMap* pkTexture, NiDX9Renderer* pkRenderer)
{
    CubeMapBaseInit* pkShell = (CubeMapBaseInit*)::BSFadeNode::operator new(0x70);
    if (pkShell)
    {
        pkShell->InitWithArgs((int)pkTexture, (int)pkRenderer, 0);
        pkShell->m_iWordAt00 = &DAT_010f049c;
    }
    else
    {
        pkShell = 0;
    }
    NiDX9RenderedCubeMapData* pkThis = (NiDX9RenderedCubeMapData*)pkShell;
    NiPixelFormat* pkFormat = reinterpret_cast<NiPixelFormat*>(pkThis->CreateSurface(pkTexture));
    if (!pkFormat)
    {
        if (pkThis)
            reinterpret_cast<void(__thiscall**)(NiDX9RenderedCubeMapData*, int)>(*reinterpret_cast<void***>(pkThis))[0](pkThis, 1);
        return 0;
    }
    reinterpret_cast<NiTexture*>(pkThis->unk08)->m_pkRendererData = reinterpret_cast<NiTexture::RendererData*>(pkThis);
    void* pkCurrentObject = 0;
    for (unsigned int i = 0; i < 6; i++)
    {
        pkThis->GetD3DTexture();
        void* pkFace = pkTexture->m_ppCubeMapFaces[i];
        int iAdapter = reinterpret_cast<int>(pkRenderer->pD3DDevice);
        void* pkData = CreateDepthBufferData(pkThis->GetD3DTexture(), i, pkCurrentObject, iAdapter, &pkFace);
        if (!pkData)
        {
            Object_DoNothing("NiDX9RenderedCubeMapData::Create> NiDX9TextureBufferData::CreateCubeFace - %s", "");
            reinterpret_cast<void(__thiscall**)(NiDX9RenderedCubeMapData*, int)>(*reinterpret_cast<void***>(pkThis))[0](pkThis, 1);
            return 0;
        }
        if (!pkCurrentObject)
            pkCurrentObject = pkData;
    }
    unsigned int uiSize = (pkFormat->m_ucBitsPerPixel >> 3) * pkThis->unk10 * pkThis->unk0C * 6;
    DAT_0126f9e0 += uiSize;
    unsigned int uiRound = uiSize & 0xfffff000;
    unsigned int uiPad = 0;
    if (uiRound != uiSize)
        uiPad = uiRound - uiSize + 0x1000;
    DAT_0126f9e4 += uiPad;
    return pkThis;
}
