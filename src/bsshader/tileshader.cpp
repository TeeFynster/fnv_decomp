#define FNV64_NIPOINTER_COMPARE_DECLS
#include "../../include/NiPointer.h"
// bsshader/tileshader.cpp: TileShader and render helpers (18 functions)

#include "tileshader_decls.h"
// NiRectF_tileshader: local type (was include/NiRectF.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiRectF_tileshader
{
public:
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
#include "../../include/NiColorA.h"
#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiShader.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DVertexShader.h"

inline NiColorA::NiColorA(float fR, float fG, float fB, float fA)
{
    r = fR;
    g = fG;
    b = fB;
    a = fA;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

template <class T> inline void ReleaseShaderReference(T* object)
{
    if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}

template <class T> inline void AcquireShaderReference(T* object)
{
    InterlockedIncrement((volatile long*)&object->m_uiRefCount);
}

inline void ReleasePassReference(NiD3DPass* object)
{
    if (--object->m_uiRefCount == 0)
        object->DestroyPass();
}

// @fnv 0x00bcac60
void TileShader::UpdateMaterial(const NiPropertyState* state)
{
    TileShaderProperty* material = (TileShaderProperty*)state->m_aspProps[3];
    if (material->m_bUnkAC)
        AddToCounterIfIdle(0, 0);

    NiStencilProperty* rendererSpecific = (NiStencilProperty*)state->m_aspProps[4];
    if (rendererSpecific && (rendererSpecific->m_18 & 1))
        UpdateRendererStateCount(0, 0);
}

class NiGPUProgram;

extern NiGPUProgram* DAT_012021e0;
extern NiGPUProgram* DAT_012021e4;
extern int DAT_0126f74c;

// @fnv 0x00bcb180
void __fastcall SelectGPUProgram(char* this_ptr, int, int arg)
{
    switch (arg)
    {
    case 0x24c:
        DAT_0126f74c = *(int*)(this_ptr + 0x6c);
        *(NiPointer<NiGPUProgram>*)(this_ptr + 0x28) = DAT_012021e0;
        break;
    case 0x24d:
        DAT_0126f74c = *(int*)(this_ptr + 0x70);
        *(NiPointer<NiGPUProgram>*)(this_ptr + 0x28) = DAT_012021e4;
        break;
    }
}

extern int DAT_0126f74c;

struct FUN_00bca500_shell
{
    void __thiscall TileShader_InitPass(void* p);
};

// @fnv 0x00bca500
// src: XBOX_PDB 0x00bca500
void __thiscall FUN_00bca500_shell::TileShader_InitPass(void* p)
{
    DAT_0126f74c = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6c);
}

extern "C" void* g_012021b8;

// @fnv 0x00bca6b0
// src: XBOX_PDB 0x00bca6b0
void* __cdecl TileShader_GetRTTI()
{
    return &g_012021b8;
}

// Sets byte at offset 8 of the objects at thisptr+0x84/0x88/0x8c based on whether a3 equals 0x24d, then calls vtable slot 0x24 on the object at thisptr+0x34.
// @fnv 0x00bcb1d0
void __fastcall SetFlagState(void* thisptr, int, int a3)
{
    char* obj84 = *(char**)((char*)thisptr + 0x84);
    char al;
    if (a3 != 0x24d)
    {
        obj84[8] = 1;
        al = 0;
    }
    else
    {
        obj84[8] = 0;
        al = 1;
    }
    *(char*)(*(char**)((char*)thisptr + 0x88) + 8) = al;
    *(char*)(*(char**)((char*)thisptr + 0x8c) + 8) = al;
    char* obj34 = *(char**)((char*)thisptr + 0x34);
    void** vtable = *(void***)obj34;
    typedef void(__thiscall * VFunc)(void*);
    ((VFunc)vtable[0x24 / 4])(obj34);
}



// Calls UnkA0 on each non-null vertex shader when unk28 is set, then Unk88 on each non-null pixel shader, and finally calls FUN_00be08b0.
// @fnv 0x00bca070
void TileShader::RebuildPrograms()
{
    unsigned int i;
    if (m_spShaderDecl.m_pObject)
    {
        for (i = 0; i < 3; i++)
        {
            NiD3DVertexShader* p = m_apVertexShaders[i];
            if (p)
                p->BuildVertexShader();
        }
    }
    for (i = 0; i < 3; i++)
    {
        NiD3DPixelShader* p = m_apPixelShaders[i];
        if (p)
            p->BuildVertexShader();
    }
    NiDX9FragmentShader_RecreateRendererData();
}

void __cdecl _delete(void*, unsigned int);
struct X
{
    void __thiscall FUN_00bca510();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls FUN_00bca510, then if bit 0 of a1 is set frees this with _delete and returns this.
// @fnv 0x00bcae60
void* __thiscall X::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00bca510();
    if (auiFlags & 1)
        _delete(this, 0x90);
    return this;
}

namespace fnv_00bcaca0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RefObj
{
    virtual ~RefObj();
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

// Unit-local view of NiPointer for 0x00bcaca0 (namespace fnv_00bcaca0): built on the shared NiPointer, that code does not compile or does not match.
template <class T> class NiPointer_00bcaca0
{
  public:
    NiPointer_00bcaca0()
    {
        m_pObject = 0;
    }
    ~NiPointer_00bcaca0()
    {
        if (m_pObject)
            ((RefObj*)m_pObject)->DecRefCount();
    }
    NiPointer_00bcaca0& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                ((RefObj*)m_pObject)->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                ((RefObj*)m_pObject)->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};



extern NiColorA DAT_01202188;
extern NiColorA DAT_012021a8;



struct FUN_00bcaca0 : public BSShader
{
    NiPointer_00bcaca0<NiD3DPass> m_spPass[1];
    NiPointer_00bcaca0<NiD3DPixelShader> m_spPS1[3];
    NiPointer_00bcaca0<NiD3DPixelShader> m_spPS2[3];
    NiPointer_00bcaca0<NiD3DVertexShader> m_sp88;
    NiPointer_00bcaca0<NiD3DVertexShader> m_sp8c;
    FUN_00bcaca0(NiD3DVertexShader* p1, NiD3DVertexShader* p2);
    virtual ~FUN_00bcaca0();
};

// @fnv 0x00bcaca0
FUN_00bcaca0::FUN_00bcaca0(NiD3DVertexShader* pVertexShader1, NiD3DVertexShader* pVertexShader2)
{
    bFirstPass = true;
    iShaderType = 0x14;
    m_sp88 = pVertexShader1;
    m_sp8c = pVertexShader2;
    DAT_01202188 = NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
    DAT_012021a8 = NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
}
}  // namespace fnv_00bcaca0

struct FUN_00bcaff0_shell : public TileShader
{
    void CreateShaderConstantMaps();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);


template <> inline NiPointer<NiD3DShaderConstantMap>& NiPointer<NiD3DShaderConstantMap>::operator=(NiD3DShaderConstantMap* p) {
    if(m_pObject!=p) { if(m_pObject) ReleaseShaderReference(m_pObject); m_pObject=p; if(m_pObject) AcquireShaderReference(m_pObject); } return *this;
}
template <> inline NiD3DShaderConstantMap* NiPointer<NiD3DShaderConstantMap>::operator->() const { return m_pObject; }
template <> inline NiPointer<NiD3DShaderConstantMap>::operator NiD3DShaderConstantMap*() const { return m_pObject; }
template <> inline bool NiPointer<NiD3DShaderConstantMap>::operator==(NiD3DShaderConstantMap* p) const { return m_pObject==p; }

struct TileShaderLayout
{
    char pad0[0x18];
    void* m_pOwnerShader;
    char pad1c[0x14];
    NiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;
};
extern float DAT_01202188[4];
extern float DAT_01202198[4];

// Lazily creates the two NiD3DShaderConstantMap objects and adds the tintcolor, WorldViewProjTranspose and TexScroll entries.
// @fnv 0x00bcaff0
void FUN_00bcaff0_shell::CreateShaderConstantMaps()
{
    TileShaderLayout* p = (TileShaderLayout*)this;
    if (p->m_spSecondShaderConstantMap == 0)
    {
        p->m_spSecondShaderConstantMap = new NiD3DShaderConstantMap(p->m_pOwnerShader, 2);
        p->m_spSecondShaderConstantMap->SetConstant("tintcolor", 0x10000007, 0, 0, 1, "", 0x10, 4, DAT_01202188, false);
    }
    if (p->m_spFirstShaderConstantMap == 0)
    {
        p->m_spFirstShaderConstantMap = new NiD3DShaderConstantMap(p->m_pOwnerShader, 0);
        p->m_spFirstShaderConstantMap->SetConstant("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        p->m_spFirstShaderConstantMap->SetConstant("TexScroll", 0x10000007, 0, 4, 1, "", 0x10, 4, DAT_01202198, false);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
#include "../../include/_D3DXMACRO.h"

struct VSPtr_bca0d0
{
    NiD3DVertexShader* m_pObject;
    VSPtr_bca0d0& operator=(NiD3DVertexShader* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                ReleaseShaderReference(m_pObject);
            m_pObject = pObject;
            if (m_pObject)
                AcquireShaderReference(m_pObject);
        }
        return *this;
    }
};

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
extern const char $SG3295[];
void* _fnv_zlib_memset(void*, int, unsigned int);
struct TileShaderDef_bca0d0
{
    const char* pFile;
    _D3DXMACRO kMacros[9];
};
struct FUN_00bca0d0_shell : BSShader
{
    unsigned int unk6C;
    VSPtr_bca0d0 m_spVertexShaders[3];
    void CreateTileVertexShaders();
};
// @fnv 0x00bca0d0
void FUN_00bca0d0_shell::CreateTileVertexShaders()
{
    TileShaderDef_bca0d0 kDefs[3];
    kDefs[0].pFile = "tile\\tile.v.hlsl";
    kDefs[0].kMacros[0].Name = 0;
    _fnv_zlib_memset(&kDefs[0].kMacros[0].Definition, 0, 0x44);
    kDefs[1].pFile = "tile\\tile.v.hlsl";
    kDefs[1].kMacros[0].Name = "TEXSCROLL";
    kDefs[1].kMacros[0].Definition = $SG3295;
    kDefs[1].kMacros[1].Name = 0;
    _fnv_zlib_memset(&kDefs[1].kMacros[1].Definition, 0, 0x3c);
    kDefs[2].pFile = "tile\\tile.v.hlsl";
    kDefs[2].kMacros[0].Name = "VC";
    kDefs[2].kMacros[0].Definition = $SG3295;
    kDefs[2].kMacros[1].Name = 0;
    _fnv_zlib_memset(&kDefs[2].kMacros[1].Definition, 0, 0x3c);
    char acName[260];
    char acPath[260];
    for (int i = 0; i < 3; i++)
    {
        if (kDefs[i].pFile)
        {
            BSShader::GetShaderPath(kDefs[i].pFile, acPath);
            _sprintf_s(acName, 260, "TILE1%03i.vso", i);
            m_spVertexShaders[i] = CompileVertexShader(acPath, kDefs[i].kMacros, "vs_1_1", acName);
        }
    }
}


struct FUN_00bca6c0_shell : NiShader
{
    bool TileShader_Initialize();
};
// Calls NiShader::Initialize, then releases three pairs of reference-counted objects and a NiD3DPass, clearing each pointer and returning true.
// @fnv 0x00bca6c0
// src: XBOX_PDB 0x00bca6c0
bool FUN_00bca6c0_shell::TileShader_Initialize()
{
    NiShader::Initialize();
    for (int i = 0; i < 3; ++i)
    {
        void* pObject = *(void**)((char*)this + 0x70 + i * 4);
        if (pObject)
        {
            if (InterlockedDecrement((volatile long*)((char*)pObject + 4)) == 0)
                ((void(__thiscall*)(void*))(*(void***)pObject)[1])(pObject);
            *(void**)((char*)this + 0x70 + i * 4) = 0;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        void* pObject = *(void**)((char*)this + 0x7c + i * 4);
        if (pObject)
        {
            if (InterlockedDecrement((volatile long*)((char*)pObject + 4)) == 0)
                ((void(__thiscall*)(void*))(*(void***)pObject)[1])(pObject);
            *(void**)((char*)this + 0x7c + i * 4) = 0;
        }
    }
    void* pass = *(void**)((char*)this + 0x6c);
    if (pass)
    {
        if (--*(int*)((char*)pass + 0x64) == 0)
            ((NiD3DPass*)pass)->DestroyPass();
        *(void**)((char*)this + 0x6c) = 0;
    }
    return true;
}

extern void* DAT_011f9508;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct NiD3DVertexDeclaration
{
    static NiD3DVertexDeclaration* __cdecl Create(void*, unsigned int, unsigned int);

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
    virtual void vfn_08c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void vfn_0b4();
};

struct FUN_00bcaca0 : A51BF0Base
{
    FUN_00bcaca0(NiD3DVertexDeclaration*, NiD3DVertexDeclaration*);

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
    virtual void vfn_04c();
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
    virtual void vfn_0c0(NiD3DVertexDeclaration*);
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
    virtual void vfn_11c();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void vfn_13c();
    virtual void v80();
    virtual void v81();
    virtual void vfn_148();
    virtual void vfn_14c();

    char m_ucUnknownByte[0x8c];
};

// @fnv 0x00bcae90
// src: XBOX_PDB 0x00bcae90
FUN_00bcaca0* TileShader_CreateShader()
{
    NiD3DVertexDeclaration* pFirstObject = NiD3DVertexDeclaration::Create(DAT_011f9508, 2, 1);
    NiD3DVertexDeclaration* pSecondObject = NiD3DVertexDeclaration::Create(DAT_011f9508, 3, 1);

    pFirstObject->vfn_08c(0, 0, 0, 2, 0);
    pFirstObject->vfn_08c(1, 0, 5, 1, 0);
    pFirstObject->vfn_0b4();

    pSecondObject->vfn_08c(0, 0, 0, 2, 0);
    pSecondObject->vfn_08c(1, 0, 5, 1, 0);
    pSecondObject->vfn_08c(2, 0, 4, 3, 0);
    pSecondObject->vfn_0b4();

    FUN_00bcaca0* pshader = new FUN_00bcaca0(pFirstObject, pSecondObject);

    pshader->vfn_04c();
    pshader->vfn_13c();
    pshader->vfn_148();
    pshader->vfn_14c();
    pshader->vfn_11c();
    pshader->vfn_0c0(pFirstObject);

    return pshader;
}

extern unsigned int DAT_011ffce8;
extern unsigned long DAT_011ff9d8[];
extern void* DAT_011f9508;

// If the counter at DAT_011ff9d8[idx] is zero, sets render state 0xAE through NiDX9Renderer::pRenderState, then adds a2 to the counter.
// @fnv 0x00b984f0
void AddToCounterIfIdle(unsigned int uiValue, unsigned int uiIncrement)
{
    unsigned int idx = DAT_011ffce8;
    if (DAT_011ff9d8[idx] == 0)
    {
        NiDX9Renderer* pR = (NiDX9Renderer*)DAT_011f9508;
        NiDX9RenderState* p = pR->pRenderState;
        // The shared render-state header has slot 26, but does not yet declare its four arguments.
        typedef void (__thiscall *SetRenderState)(NiDX9RenderState*, unsigned int, unsigned int, unsigned int, unsigned int);
        ((SetRenderState)(*(void***)p)[26])(p, 0xae, uiValue & 0xFF, 0, 0);
    }
    DAT_011ff9d8[idx] += uiIncrement;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);




struct PSPtr_bca240
{
    NiD3DPixelShader* m_pObject;
    PSPtr_bca240& operator=(NiD3DPixelShader* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                ReleaseShaderReference(m_pObject);
            m_pObject = pObject;
            if (m_pObject)
                AcquireShaderReference(m_pObject);
        }
        return *this;
    }
};

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

struct TileShaderDef_bca240
{
    const char* pFile;
    _D3DXMACRO kMacros[9];
};

struct FUN_00bca240_shell : BSShader
{
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    PSPtr_bca240 m_spPixelShaders[3];
    void CreateTilePixelShaders();
};

// Builds three tile pixel-shader definitions, resolves the pixel shader profile, and creates each shader into m_spPixelShaders.
// @fnv 0x00bca240
void FUN_00bca240_shell::CreateTilePixelShaders()
{
    TileShaderDef_bca240 kDefs[3];
    kDefs[0].pFile = "tile\\tile.p.hlsl";
    kDefs[0].kMacros[0].Name = 0;
    _fnv_zlib_memset(&kDefs[0].kMacros[0].Definition, 0, 0x44);
    kDefs[1].pFile = "tile\\tile.p.hlsl";
    kDefs[1].kMacros[0].Name = "ALPHAMAP";
    kDefs[1].kMacros[0].Definition = "";
    kDefs[1].kMacros[1].Name = 0;
    _fnv_zlib_memset(&kDefs[1].kMacros[1].Definition, 0, 0x3c);
    kDefs[2].pFile = "tile\\tile.p.hlsl";
    kDefs[2].kMacros[0].Name = "VC";
    kDefs[2].kMacros[0].Definition = "";
    kDefs[2].kMacros[1].Name = 0;
    _fnv_zlib_memset(&kDefs[2].kMacros[1].Definition, 0, 0x3c);
    const char* pPixelShaderProfile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
    for (int i = 0; i < 3; i++)
    {
        if (kDefs[i].pFile)
        {
            char acPath[260];
            char acName[260];
            GetShaderPath(kDefs[i].pFile, acPath);
            _sprintf_s(acName, 260, "TILE1%03i.pso", i);
            m_spPixelShaders[i] = CompilePixelShader(acPath, kDefs[i].kMacros, pPixelShaderProfile, acName);
        }
    }
}

struct RefObject
{
    virtual void Slot0();
    virtual void DeleteThis();
    volatile long refs;
    void Dec()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
struct FUN_00b66f20
{
    RefObject* object;
    ~FUN_00b66f20()
    {
        if (object)
            object->Dec();
    }
    void Clear()
    {
        if (object)
        {
            object->Dec();
            object = 0;
        }
    }
};

struct FUN_00b79930
{
    NiD3DPass* object;
    ~FUN_00b79930()
    {
        if (object)
            ReleasePassReference(object);
    }
    void Clear()
    {
        if (object)
        {
            ReleasePassReference(object);
            object = 0;
        }
    }
};

struct FUN_00bca510 : BSShader
{
    FUN_00b79930 pass[1];
    FUN_00b66f20 vertex[3];
    FUN_00b66f20 pixel[3];
    FUN_00b66f20 other88;
    FUN_00b66f20 other8c;
    virtual ~FUN_00bca510();
};
// Releases the vertex, pixel and pass references, then resets enabled64, other88 and value60.
// @fnv 0x00bca510
FUN_00bca510::~FUN_00bca510()
{
    for (unsigned int i = 0; i < 3; ++i)
        vertex[i].Clear();
    for (unsigned int i = 0; i < 3; ++i)
        pixel[i].Clear();
    pass[0].Clear();
    bFirstPass = 0;
    other88.Clear();
    ePass = 0;
}

struct Stage321
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int refCount;
    void ReturnToPool();
    void NiD3DTextureStage_SetFilterMode(unsigned int mode);
    void Release()
    {
        --refCount;
        if (refCount == 0)
            ReturnToPool();
    }
};
struct StagePtr321
{
    Stage321* object;
    StagePtr321() : object(0)
    {}
    ~StagePtr321()
    {
        if (object)
            object->Release();
    }
};
struct RenderState321
{
    void SetNodeValue(unsigned int state, unsigned int value, bool save);
};
RenderState321* FUN_00e7f5d0();
struct Pass321
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int stageCount;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    RenderState321* state;
    void NiD3DPass_SetStage(unsigned int index, Stage321* stage);
    RenderState321* GetState()
    {
        if (!state)
            state = FUN_00e7f5d0();
        return state;
    }
};
void FUN_00e804d0(Pass321*&);
void AssignStageFromPool(Stage321*&);
void ConfigureBeamStage(Stage321*, unsigned int, unsigned int, unsigned int, unsigned int);
struct Shader321
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    Pass321* pass;
    bool ConfigurePassStages();
};
// @fnv 0x00bca3c0
bool Shader321::ConfigurePassStages()
{
    FUN_00e804d0(pass);
    StagePtr321 stage;
    AssignStageFromPool(stage.object);
    ConfigureBeamStage(stage.object, 0, 1, 2, 1);
    pass->NiD3DPass_SetStage(pass->stageCount, stage.object);
    stage.object->NiD3DTextureStage_SetFilterMode(1);
    AssignStageFromPool(stage.object);
    ConfigureBeamStage(stage.object, 1, 1, 2, 1);
    pass->NiD3DPass_SetStage(pass->stageCount, stage.object);
    pass->GetState()->SetNodeValue(7, 0, true);
    pass->GetState()->SetNodeValue(14, 0, true);
    pass->GetState()->SetNodeValue(168, 15, true);
    return true;
}

namespace fnv_00bca980 {
struct NiRectI
{
    int left;
    int top;
    int right;
    int bottom;
};

extern NiColorA DAT_01202188;
extern float DAT_01202198;
extern float DAT_0120219c;
extern float DAT_012021a0;
extern float DAT_012021a4;
extern NiRectF_tileshader DAT_011ad840;
extern unsigned char DAT_011f9426;
extern char DAT_011f4288;

void AccumulateAndDispatch(int, int, int, int, int);
void BSRenderState_SetStencilAction(unsigned int, unsigned int, unsigned int, unsigned int);
void BSRenderState_SetStencilFunc(unsigned int, unsigned int, unsigned int, unsigned int);


struct ShaderCtxB8
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
    void* unk34;
};

struct ShaderCtx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* unk20;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    ShaderCtxB8* unkB8;
    void* unkBC;
};

struct ShaderManager
{
    ShaderCtx* unk00;
};
extern ShaderManager* DAT_011f91e0;

struct ShaderList
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
    void* unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    void* unk5C;
};
extern ShaderList* DAT_0126f74c;

struct AlphaProp
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
    float unk3C;
};



struct Shader
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
    virtual void Draw(void*, ShaderCtx*, void*, int, void*, const NiPropertyState*, int, void*, void*, int, int);
};

extern NiRenderer* DAT_011f4748;

struct ShaderProp
{
    void NiDX9Renderer_SetModelTransform(void*, int);
};

}  // namespace fnv_00bca980

// @fnv 0x00bca980
void TileShader::SetupMaterial(const NiPropertyState* state)
{
    using namespace fnv_00bca980;
    ShaderManager* mgr = fnv_00bca980::DAT_011f91e0;
    if (!mgr)
        return;
    ShaderCtx* ctx = mgr->unk00;
    void* sub68 = &ctx->unk68;
    void* v20 = ctx->unk20;
    if (!v20)
        v20 = &fnv_00bca980::DAT_011f4288;
    void* p34 = ctx->unkB8->unk34;
    void* vBC = ctx->unkBC;
    TileShaderProperty* mat = (TileShaderProperty*)state->m_aspProps[3];
    ((ShaderProp*)m_pkD3DRenderer)->NiDX9Renderer_SetModelTransform(sub68, 0);

    if (mat->m_bUnk91)
    {
        fnv_00bca980::DAT_01202198 = mat->m_afUnk7C[0];
        fnv_00bca980::DAT_0120219c = mat->m_afUnk7C[1];
        fnv_00bca980::DAT_012021a0 = mat->m_afUnk7C[2];
        fnv_00bca980::DAT_012021a4 = mat->m_afUnk7C[3];
    }
    float scale = 1.0f;
    fnv_00bca980::DAT_01202188 = *(NiColorA*)mat->m_afUnk68;
    AlphaProp* pAlpha = (AlphaProp*)state->m_aspProps[2];
    if (pAlpha)
        scale = pAlpha->unk3C;
    fnv_00bca980::DAT_01202188.a = mat->m_fAlpha * scale;

    Shader* pShader = (Shader*)m_spPixelConstantMap.m_pObject;
    if (pShader)
    {
        void* q = fnv_00bca980::DAT_0126f74c->unk44;
        if (q)
            pShader->Draw(q, ctx, vBC, 0, p34, state, 0, sub68, v20, 0, 1);
    }
    pShader = (Shader*)m_spVertexConstantMap.m_pObject;
    if (pShader)
    {
        void* q = fnv_00bca980::DAT_0126f74c->unk5C;
        if (q)
            pShader->Draw(q, ctx, vBC, 0, p34, state, 0, sub68, v20, 0, 1);
    }

    if (mat->m_bUnkAC)
    {
        NiRectI rect = *(NiRectI*)mat->m_auiUnk9C;
        if (fnv_00bca980::DAT_011f9426)
        {
            NiRenderer* dev = fnv_00bca980::DAT_011f4748;
            if (fnv_00bca980::DAT_011f4748->GetCurrentRT() == dev->GetDefaultRT())
            {
                NiRectF_tileshader vp = fnv_00bca980::DAT_011ad840;
                unsigned int h1 = fnv_00bca980::DAT_011f4748->GetDefaultBackBuffer()->m_uiImageHeight;
                Ni2DBuffer* rt = fnv_00bca980::DAT_011f4748->GetDefaultBackBuffer();
                rect.top = (int)(h1 * vp.m_fMaximumV + rect.top * (vp.m_fMinimumV - vp.m_fMaximumV));
                rect.bottom = (int)(rt->m_uiImageHeight * vp.m_fMaximumV + rect.bottom * (vp.m_fMinimumV - vp.m_fMaximumV));
            }
        }
        AddToCounterIfIdle(1, 0);
        AccumulateAndDispatch(rect.left, rect.top, rect.right, rect.bottom, 0);
    }

    NiStencilProperty* pFlag = (NiStencilProperty*)state->m_aspProps[4];
    if (pFlag && (pFlag->mode & 1))
    {
        UpdateRendererStateCount(1, 0);
        BSRenderState_SetStencilAction((pFlag->mode >> 1) & 7, (pFlag->mode >> 4) & 7, (pFlag->mode >> 7) & 7, 0);
        BSRenderState_SetStencilFunc(pFlag->mode >> 12, pFlag->m_1c, pFlag->m_20, 0);
    }
}

namespace fnv_00bca760 {
template <class T> struct FieldPtr
{
    T* object;
    __forceinline operator T*() const
    {
        return object;
    }
    __forceinline T* operator->() const
    {
        return object;
    }
};

struct Renderer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void SetVertexShader(int iHandle);
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void SetPixelShader(int iHandle);
};

struct ShaderProgram
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual int GetVertexHandle(int i);
    virtual void vf80();
    virtual int GetHandle(int i);
};

struct RefTarget
{
    void* vtable;
    int unk04;
    void* m_pFlagTarget;
    int unk0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    unsigned int m_uiRefCount;

    void ApplyPairToState(int iValue);
    void FUN_00e7eb00(bool bFlag);
    void NiD3DTextureStage_ReturnStageToPool();

    __forceinline void IncRefCount()
    {
        ++m_uiRefCount;
    }
    __forceinline void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};

template <class T> class RefPtr
{
  public:
    __forceinline RefPtr(T* p) : m_pObject(p)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    __forceinline ~RefPtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    __forceinline T* operator->() const
    {
        return m_pObject;
    }
    __forceinline operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

struct TargetPair
{
    RefTarget* m_pFirst;
    RefTarget* m_pSecond;
};

struct ShaderState
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    TargetPair* m_pTargets;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    ShaderProgram* m_pVertexProgram;
    int unk48, unk4C, unk50, unk54, unk58;
    ShaderProgram* m_pPixelProgram;

    Renderer* NiD3DPass_GetD3DRenderState();
    void NiD3DPass_SetVertexShader(void* pValue);
    void NiD3DPass_SetPixelShader(void* pValue);
};

extern ShaderState* DAT_0126f74c;

struct GeometryData
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    void* m_pFlagTarget;
    FieldPtr<GeometryData> m_pNext;
    __forceinline GeometryData* GetNext() const
    {
        return m_pNext;
    }
    __forceinline bool GetAlt() const
    {
        return m_bAlt;
    }
    __forceinline bool GetSecond() const
    {
        return m_bSecondPass;
    }
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88;
    int m_iTargetValue;
    unsigned char unk90;
    bool m_bAlt;
    bool m_bSecondPass;
    unsigned char m_bNoTarget;
};

struct RenderPassArg
{
    int unk00, unk04, unk08;
    GeometryData* m_pkGeometryData;
};

struct PassShader
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void SetConstant(unsigned int uiValue);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    FieldPtr<void> m_pVertexA;
    FieldPtr<void> m_pVertexB;
    FieldPtr<void> m_pVertexC;
    FieldPtr<void> m_pPixelA;
    FieldPtr<void> m_pPixelB;
    FieldPtr<void> m_pPixelC;
    unsigned int m_uiConstA;
    unsigned int m_uiConstB;

    void ApplyToRenderer(RenderPassArg* pArg);
};

struct PassFlags
{
    unsigned char alt;
    unsigned char raw;
    unsigned char second;
    bool next;
};

// Sets vertex and pixel shader handles and constants on the renderer based on pass flags, then applies target pairs and flag targets to the shader state.
// @fnv 0x00bca760
void PassShader::ApplyToRenderer(RenderPassArg* pArg)
{
    GeometryData* pGeom = pArg->m_pkGeometryData;
    bool bAlt = pGeom->GetAlt();
    bool bNext = pGeom->GetNext() != 0;
    bool bSecond = pGeom->GetSecond();
    Renderer* pRenderer = DAT_0126f74c->NiD3DPass_GetD3DRenderState();
    ShaderState* state = DAT_0126f74c;
    if (!bSecond)
    {
        if (bAlt)
            state->NiD3DPass_SetVertexShader(m_pVertexB);
        else
            state->NiD3DPass_SetVertexShader(m_pVertexA);
        pRenderer->SetPixelShader(DAT_0126f74c->m_pPixelProgram->GetHandle(0));
        state = DAT_0126f74c;
        if (bNext)
        {
            state->NiD3DPass_SetPixelShader(m_pPixelB);
            pRenderer->SetVertexShader(DAT_0126f74c->m_pVertexProgram->GetVertexHandle(0));
        }
        else
        {
            state->NiD3DPass_SetPixelShader(m_pPixelA);
            pRenderer->SetVertexShader(DAT_0126f74c->m_pVertexProgram->GetVertexHandle(0));
        }
        {
            unsigned int uiConst = m_uiConstA;
            SetConstant(uiConst);
        }
    }
    else
    {
        state->NiD3DPass_SetVertexShader(m_pVertexC);
        void* pPixelC = m_pPixelC;
        DAT_0126f74c->NiD3DPass_SetPixelShader(pPixelC);
        pRenderer->SetPixelShader(DAT_0126f74c->m_pPixelProgram->GetHandle(0));
        pRenderer->SetVertexShader(DAT_0126f74c->m_pVertexProgram->GetVertexHandle(0));
        {
            unsigned int uiConst = m_uiConstB;
            SetConstant(uiConst);
        }
    }

    int iValue = bAlt ? 3 : pGeom->m_iTargetValue;
    RefPtr<RefTarget> spFirst(DAT_0126f74c->m_pTargets->m_pFirst);
    RefPtr<RefTarget> spSecond(DAT_0126f74c->m_pTargets->m_pSecond);
    spFirst->ApplyPairToState(iValue);
    if (!pGeom->m_bNoTarget && pGeom->m_pFlagTarget)
    {
        spFirst->m_pFlagTarget = pGeom->m_pFlagTarget;
        spFirst->FUN_00e7eb00(true);
    }
    GeometryData* pNext = pGeom->m_pNext;
    if (pNext)
    {
        spSecond->ApplyPairToState(0);
        spSecond->m_pFlagTarget = pNext;
        spSecond->FUN_00e7eb00(false);
    }
    else if (spSecond)
    {
        spSecond->m_pFlagTarget = 0;
    }
}
}  // namespace fnv_00bca760
