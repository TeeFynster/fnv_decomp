// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderinterface.cpp: NiD3DShaderInterface (11 functions)

#include "nid3dshaderinterface_decls.h"

// @fnv 0x00e81a90
bool NiD3DShaderInterface::Initialize()
{
    if (!NiRenderer::ms_pRenderer)
        return false;
    SetShaderObject((GraphicsRenderer*)NiRenderer::ms_pRenderer);
    return NiShader::Initialize();
}

// @fnv 0x00e818d0
void NiD3DShaderInterface::SetShaderObject(GraphicsRenderer* renderer)
{
    m_pkD3DRenderer = renderer;
    if (renderer)
    {
        ShaderPassRenderer* state = renderer->m_pCurrentRenderState;
        if (m_pkD3DDevice)
        {
            typedef void(__stdcall * ReleaseFunction)(ShaderPassRenderer*);
            ReleaseFunction release = (ReleaseFunction)(*(void***)m_pkD3DDevice)[2];
            release((ShaderPassRenderer*)m_pkD3DDevice);
        }
        m_pkD3DDevice = (Direct3DDeviceInterface*)state;
        if (state)
        {
            typedef void(__stdcall * AddRefFunction)(ShaderPassRenderer*);
            AddRefFunction addRef = (AddRefFunction)state->m_ppVirtualMethodTable[1];
            addRef(state);
        }
        m_pkD3DRenderState = (ShaderPassRenderer*)m_pkD3DRenderer->m_pD3DDevice;
    }
    else
    {
        m_pkD3DRenderState = 0;
        if (m_pkD3DDevice)
        {
            typedef void(__stdcall * ReleaseFunction)(ShaderPassRenderer*);
            ReleaseFunction release = (ReleaseFunction)(*(void***)m_pkD3DDevice)[2];
            release((ShaderPassRenderer*)m_pkD3DDevice);
        }
        m_pkD3DDevice = 0;
    }
}

// @fnv 0x00e81940
unsigned int NiD3DShaderInterface::InitializeShaderRenderer(GraphicsRenderer* renderer)
{
    Direct3DDeviceInterface* device = renderer->m_pD3DDevice;
    NiD3DPass_SetD3DRenderer(renderer);
    NiD3DTextureStage_SetD3DRenderer(renderer);
    DAT_0126f99c = device;
    NiD3DShaderProgramFactory_SetD3DRenderer(renderer);
    NiD3DShaderProgramCreator_SetD3DRenderer(renderer);
    NiD3DPass::SetActiveRenderer(renderer);
    device->vfn_100();
    NiD3DShaderFactory* factory = NiD3DShaderFactory::GetShaderFactory();
    if (factory)
        factory->vfn_70(renderer);
    if (!DAT_0126fa10)
    {
        Program* p = (Program*)NiMemObject::operator new(28);
        DAT_0126fa10 = p ? p->FUN_00e93ad0() : 0;
        if (!DAT_0126fa10)
            NiD3DDefaultShader::SetShaderName("Failed to create shader program factory!");
    }
    return 0;
}

extern int vftable_NiRefObject;
extern int DAT_0109f584;
extern long volatile DAT_011f4400;
extern int EmptyFS;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

// Sets the vtable and clears fields of the object, increments the global counter, then assigns the second vtable and initializes the remaining fields.
// @fnv 0x00a8f440
// src: EXE 0x00a8f440
void* __fastcall NiShader_NiShader(void* apObject)
{
    *(int**)apObject = &vftable_NiRefObject;
    *((int*)apObject + 1) = 0;
    InterlockedIncrement(&DAT_011f4400);
    *(int**)apObject = &DAT_0109f584;
    *((int*)apObject + 2) = EmptyFS;
    *((int*)apObject + 3) = 0;
    *((char*)apObject + 16) = 0;
    return apObject;
}

extern const char* const g_011f603c_arg1;
// @fnv 0x00a8f1b0
// src: COMMUNITY 0x00a8f1b0
const char* const* __fastcall Ni2DBuffer_GetRTTI(void* p, int)
{
    return &g_011f603c_arg1;
}

extern const char* const g_0126f75c_arg1;
// @fnv 0x00a8f480
// src: COMMUNITY 0x00a8f480
const char* const* __fastcall NiShader_GetRTTI(void* p, int)
{
    return &g_0126f75c_arg1;
}

void NiShaderFactory_ReleaseAllShaders();
void DestroyProgram();
// @fnv 0x00e819f0
// src: XBOX_PDB 0x00e819f0
int NiD3DShaderInterface_ShutdownShaderSystem()
{
    NiD3DShaderFactory* pShaderFactory = NiD3DShaderFactory::GetShaderFactory();
    if (pShaderFactory)
    {
        NiShaderFactory_ReleaseAllShaders();
        pShaderFactory->vfn_70(0);
    }
    NiD3DPass_SetD3DRenderer(0);
    NiD3DTextureStage_SetD3DRenderer(0);
    DAT_0126f99c = 0;
    DestroyProgram();
    NiD3DShaderProgramFactory_SetD3DRenderer(0);
    NiD3DShaderProgramCreator_SetD3DRenderer(0);
    NiD3DPass::SetActiveRenderer(0);
    return 0;
}

extern int DAT_010ef39c;
struct Rel
{
    virtual void a();
    virtual void b();
    virtual unsigned long __stdcall Release();
};
void __fastcall FUN_00a8f490(NiD3DShaderInterface*);
// Sets the object's vtable, clears r and s, releases dev if set, nulls dev, then calls FUN_00a8f490.
// @fnv 0x00e81a50
// src: GUESS 0x00e81a50 (confidence: high)
void __fastcall NiD3DShaderInterface_ReleaseD3DDeviceAndClearRendererState(NiD3DShaderInterface* pObj, int)
{
    *(int**)pObj = &DAT_010ef39c;
    Rel* d = (Rel*)pObj->m_pkD3DDevice;
    pObj->m_pkD3DRenderer = 0;
    pObj->m_pkD3DRenderState = 0;
    if (d)
        d->Release();
    pObj->m_pkD3DDevice = 0;
    FUN_00a8f490(pObj);
}

namespace fnv_00e81ab0 {
extern int DAT_010ef39c;
struct Rel
{
    virtual void a();
    virtual void b();
    virtual unsigned long __stdcall Release();
};
void __fastcall FUN_00a8f490(NiD3DShaderInterface*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// @fnv 0x00e81ab0
NiD3DShaderInterface* __fastcall FUN_00e81ab0(NiD3DShaderInterface* o, int, unsigned int flags)
{
    *(int**)o = &DAT_010ef39c;
    Rel* d = (Rel*)o->m_pkD3DDevice;
    o->m_pkD3DRenderer = 0;
    o->m_pkD3DRenderState = 0;
    if (d)
        d->Release();
    o->m_pkD3DDevice = 0;
    fnv_00e81ab0::FUN_00a8f490(o);
    if (flags & 1)
        __Dummy_00b6fef0(o, 0x24);
    return o;
}
}  // namespace fnv_00e81ab0

struct Rf
{
    virtual void a();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
extern void* DAT_0126fa2c;
extern Rf* DAT_0126fa28;
// Stores r in DAT_0126fa2c and, if r is non-null, releases the old DAT_0126fa28 and AddRefs the object at r+0x288; otherwise releases and clears DAT_0126fa28.
// @fnv 0x00e93f50
// src: COMMUNITY 0x00e93f50
void NiD3DShaderProgramCreator_SetD3DRenderer(void* apObject)
{
    DAT_0126fa2c = apObject;
    if (apObject)
    {
        Rf* pRef = *(Rf**)((char*)apObject + 0x288);
        if (DAT_0126fa28)
            DAT_0126fa28->Release();
        DAT_0126fa28 = pRef;
        if (pRef)
            pRef->AddRef();
    }
    else
    {
        if (DAT_0126fa28)
            DAT_0126fa28->Release();
        DAT_0126fa28 = 0;
    }
}

// Ni2DBuffer constructor: base constructor and initial state.
extern int DAT_0109f4dc;

struct FUN_00a8f190_cls
{
    void* m_pVTable;  // +0x00
    int m_i04;        // +0x04
    int m_i08;        // +0x08
    int m_i0C;        // +0x0C
    int m_i10;        // +0x10

    void Init();  // base constructor (external)

    FUN_00a8f190_cls();
};

// @fnv 0x00a8f190
FUN_00a8f190_cls::FUN_00a8f190_cls()
{
    Init();
    m_i08 = 0;
    m_i0C = 0;
    *(void* volatile*)&m_pVTable = &DAT_0109f4dc;
    *(int volatile*)&m_i10 = 0;
}
