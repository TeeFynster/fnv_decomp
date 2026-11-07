// gamebryo2.2/corelibs/niconsolerenderer/nid3dshader.cpp: shared shaders and depth buffers (31 functions)

// Use the shared shader layouts. Helpers for undeclared overrides take an explicit
// this pointer in ECX; the unused EDX argument preserves the member-call ABI.
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiDX9Renderer.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiCriticalSection.h"
#include "../../../../include/NiD3DDefaultShader.h"
#include "../../../../include/NiD3DShader.h"
#include "../../../../include/NiD3DShaderInterface.h"
#include "../../../../include/NiShader.h"
#include "../../../../include/NiD3DShaderDeclaration.h"
#include "../../../../include/NiD3DVertexShader.h"
#include "../../../../include/NiD3DPass.h"
#include "../../../../include/NiD3DPixelShader.h"
#include "../../../../include/NiSkinPartition.h"

#include "../../../../include/NiD3DShaderConstantMap.h"

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

inline void NiD3DShaderConstantMap::DecRefCount()
{
    reinterpret_cast<NiRefObject*>(this)->DecRefCount();
}

#include "nid3dshader_decls.h"

// @fnv 0x00e80580
unsigned int NiD3DShader::IsRendererActive()
{
    return DAT_0126f74c != 0;
}

// @fnv 0x00e81100
void NiD3DShader::InitializePoint3()
{
    char* oldString = DAT_0126f750;
    if (oldString != &DAT_010ef37c)
    {
        DAT_0126f750 = NiGlobalStringTable::AddString(&DAT_010ef37c);
        if (oldString != EmptyFS.m_kHandle)
            InterlockedDecrement((long volatile*)(oldString - 8));
    }
    DAT_0126f738 = &SetShadowWorldView;
    DAT_0126f73c = &NiD3DShader_PackWorldPerspectiveEffect;
    DAT_0126f740 = &UpdateWorldViewMatrix;
    DAT_0126f744 = &SetWorldViewFromShadow;
    DAT_0126f748 = &SetWorldViewMatrix;
}

#include "nid3dshader_depth.h"
// @fnv 0x00e7d9d0
NiDX9AdditionalDepthStencilBufferData* NiDX9AdditionalDepthStencilBufferData::Create(DepthDevice* device,
                                                                                     Ni2DBuffer** buffer,
                                                                                     const NiPixelFormat* pixelFormat,
                                                                                     unsigned int preference)
{
    if (!pixelFormat)
        return 0;
    D3DFORMAT d3dFormat = NiD3DTextureData::ConvertPixelFormatToD3DFormat(pixelFormat);
    if (!d3dFormat)
        return 0;
    NiRenderer* renderer = NiRenderer::ms_pRenderer;
    renderer->GetDefaultRT();
    // DX9 device parameters are not yet named in the shared renderer layout.
    unsigned int adapterFormat = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(renderer) + 0x5d0);
    unsigned int deviceType = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(renderer) + 0x5c8);
    DepthDevice* d3d = DAT_0126f0d8;
    unsigned int adapter = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(renderer) + 0x5c4);
    int hr = d3d->CheckDeviceFormat(adapter, deviceType, adapterFormat, 2, 1, d3dFormat);
    if (hr < 0)
    {
        ((void(__cdecl*)(const char*, ...)) & NiD3DDefaultShader::SetShaderName)(&DAT_010ef1f0, GetHRESULTText(hr));
        return 0;
    }
    NiDX9AdditionalDepthStencilBufferData* data = new NiDX9AdditionalDepthStencilBufferData;
    data->m_bDiscard = DAT_011bf400;
    data->m_eMSAAPref = static_cast<Ni2DBuffer::MultiSamplePreference>(preference);
    unsigned int multisampleType;
    switch (preference)
    {
    case 0:
        multisampleType = 0;
        break;
    case 1:
        multisampleType = 2;
        break;
    case 2:
        multisampleType = 4;
        break;
    case 3:
        multisampleType = 8;
        break;
    default:
        multisampleType = 0;
    }
    unsigned int height = (*buffer)->m_uiImageHeight;
    unsigned int width = (*buffer)->m_uiImageWidth;
    hr =
        device->CreateDepthStencilSurface(width, height, d3dFormat, multisampleType, 0, data->m_bDiscard,
                                          reinterpret_cast<DepthSurface**>(&data->m_pkSurface), 0);
    if (hr < 0)
    {
        ((void(__cdecl*)(const char*, ...)) & NiD3DDefaultShader::SetShaderName)(&DAT_010ef1f0, GetHRESULTText(hr));
        delete data;
        return 0;
    }
    DepthDesc desc;
    hr = reinterpret_cast<DepthSurface*>(data->m_pkSurface)->GetDesc(&desc);
    if (hr < 0)
    {
        delete data;
        return 0;
    }
    data->m_pkPixelFormat = CreatePixelFormat(desc.format);
    data->m_eCreateFormat = d3dFormat;
    (*buffer)->SetRendererData(data);
    data->m_pkBuffer = *buffer;
    return data;
}

extern "C" void __cdecl NiD3DPass_InitializePools();
extern "C" void __cdecl CreateStagePool();

// @fnv 0x00e80620
// src: COMMUNITY 0x00e80620
void __cdecl NiD3DShader_InitializePools()
{
    NiD3DPass_InitializePools();
    CreateStagePool();
}

extern "C" void __cdecl ClearSpawnedObject();
extern "C" void __cdecl DestroyStagePool();

// @fnv 0x00e80630
// src: COMMUNITY 0x00e80630
void __cdecl NiD3DShader_ShutdownPools()
{
    ClearSpawnedObject();
    DestroyStagePool();
}

// @fnv 0x00e80690
void ResetGlobalString()
{
    char* old = DAT_0126f750;
    if (old != 0)
    {
        DAT_0126f750 = NiGlobalStringTable::AddString(0);
        if (old != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(old - 8));
    }
}

// @fnv 0x00e81420
void __fastcall UseShaderDeclaration(NiD3DShader* shader, void*, NiD3DShaderDeclaration* pkShaderDecl)
{
    NiRefObject*& pObj = reinterpret_cast<NiRefObject*&>(shader->m_spShaderDecl.m_pObject);
    NiRefObject* pNew = reinterpret_cast<NiRefObject*>(pkShaderDecl);
    if (pObj != pNew)
    {
        if (pObj)
            pObj->DecRefCount();
        pObj = pNew;
        if (pObj)
            pObj->IncRefCount();
    }
}

extern const char* const g_0126f754_arg1;

// @fnv 0x00e818c0
void* __fastcall GetShaderInstanceDesc(NiD3DShaderInterface* shader, void*)
{
    return (void*)&g_0126f754_arg1;
}

extern "C" void __cdecl BindShaderConstants(NiD3DShader*, NiGeometry*);

// @fnv 0x00e81880
bool __fastcall SetupGeometry(NiD3DShader* shader, void*, NiGeometry* pkGeometry)
{
    BindShaderConstants(shader, pkGeometry);
    return true;
}

struct FakeRenderer008
{
    virtual void v0();
    virtual void v1();
    virtual unsigned int V8(void*, void*, void*, void*, void*, void*, void*, int);
};
// @fnv 0x00e805b0
// src: COMMUNITY 0x00e805b0
unsigned int __stdcall NiD3DShader_SetupRenderingPass(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7)
{
    return ((FakeRenderer008*)DAT_0126f74c)->V8(a1, a2, a3, a4, a5, a6, a7, 0);
}

struct VirtHelper
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*);
};
struct GroupStandIn
{
    void ApplyGroupEntries();
};
struct StateStandIn
{
    void ApplyRenderModes(void*, void*, int);
};
// @fnv 0x00e81170
unsigned int __fastcall SetupGeometryShader(NiD3DShader* shader, void*, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7)
{
    if (!shader->m_bInitialized)
        return 0xFFFFFFFF;
    if (shader->m_bUsesNiRenderState)
        ((VirtHelper*)shader->m_pkD3DRenderState)->f2(a4);
    if (shader->m_bUsesNiLightState)
    {
        void* p = shader->m_pkD3DRenderer;
        StateStandIn* pState = *(StateStandIn**)((char*)p + 0x8c8);
        if (pState)
            pState->ApplyRenderModes(a5, *(void**)((char*)a4 + 0x14), 0);
    }
    GroupStandIn* pGroup = reinterpret_cast<GroupStandIn*>(shader->m_pkRenderStateGroup);
    if (pGroup)
        pGroup->ApplyGroupEntries();
    return 0;
}

// @fnv 0x00e818a0
NiD3DShaderInterface::NiD3DShaderInterface() throw()
{
    m_pkD3DDevice = 0;
    m_pkD3DRenderer = 0;
    m_pkD3DRenderState = 0;
    m_bIsBestImplementation = false;
}

// @fnv 0x00e81470
void __fastcall UnloadShader(NiD3DShader* shader, void*)
{
    NiD3DPass* pkPass;
    NiD3DVertexShader* pkVS;
    NiD3DPixelShader* pkPS;
    pkPass = (NiD3DPass*)DAT_0126f74c;
    if (pkPass)
    {
        pkPS = pkPass->m_spPixelShader.m_pObject;
        if (pkPS)
            pkPS->UnloadShader();
        pkVS = pkPass->m_spVertexShader.m_pObject;
        if (pkVS)
            pkVS->UnloadShader();
    }
    shader->m_bInitialized = false;
}

// @fnv 0x00e814b0
void __fastcall BuildVertexShader(NiD3DShader* shader, void*)
{
    if (shader->m_pkD3DRenderer)
    {
        NiD3DPass* pkPass = (NiD3DPass*)DAT_0126f74c;
        NiD3DVertexShader* pkVS;
        NiD3DPixelShader* pkPS;
        if (pkPass)
        {
            pkPS = pkPass->m_spPixelShader.m_pObject;
            if (pkPS)
                pkPS->BuildVertexShader();
            pkVS = pkPass->m_spVertexShader.m_pObject;
            if (pkVS)
                pkVS->BuildVertexShader();
        }
        shader->m_bInitialized = true;
    }
}

// Render-state group helper.
void __fastcall NiD3DRenderStateGroup_RestoreRenderStates(void*);

// @fnv 0x00e805f0
unsigned int __fastcall UpdateGeometryEffects(NiD3DShader* shader, void*, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7)
{
    void* decl = shader->m_pkRenderStateGroup;
    if (decl)
        NiD3DRenderStateGroup_RestoreRenderStates(decl);
    return 0;
}

// Dispatch a member pointer of this object to a global dispatcher object.
// The global dispatcher is looked up through the module global DAT_0126f74c;
// when it is not created yet the call is skipped.

class GlobalDispatchTarget
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void* pArg);
};

// @fnv 0x00e80590
unsigned int __fastcall GetPassCount(NiD3DShader* shader, void*)
{
    GlobalDispatchTarget* pTarget = *reinterpret_cast<GlobalDispatchTarget**>(&DAT_0126f74c);
    if (pTarget != 0)
    {
        pTarget->v3(reinterpret_cast<void*>(shader->m_uiCurrentPass));
    }
    return 0;
}

extern int DAT_01101294;

struct FUN_00e80640_Entry
{
    unsigned int m_uiKey;
    unsigned int m_uiCurrentValue;
};

class FUN_00e80640_cls
{
  public:
    unsigned int m_uiUnk00;
    unsigned int m_uiUnk04;
    unsigned int m_uiUnk08;
    unsigned int m_uiUnk0C;
    unsigned int m_uiUnk10;
    unsigned int m_uiUnk14;
    unsigned int m_auiCount[3];
    FUN_00e80640_Entry* m_apEntries[3];

    void AddEntry(unsigned int a1, unsigned int a2, unsigned int idx, unsigned int a4, bool flag);
};

// @fnv 0x00e80640
void FUN_00e80640_cls::AddEntry(unsigned int uiKeyLow, unsigned int uiKeyHigh, unsigned int uiArrayIndex,
                                unsigned int uiValue, bool flag)
{
    unsigned int v = (flag ? 0xff : uiKeyHigh) << DAT_01101294;
    m_apEntries[uiArrayIndex][m_auiCount[uiArrayIndex]].m_uiKey = v | uiKeyLow;
    m_apEntries[uiArrayIndex][m_auiCount[uiArrayIndex]].m_uiCurrentValue = uiValue;
    m_auiCount[uiArrayIndex]++;
}

extern char* g_pcNullStringHandle;

inline bool NiFixedString::Exists()
{
    return m_kHandle != g_pcNullStringHandle;
}
inline unsigned int NiFixedString::GetLength()
{
    if (m_kHandle == g_pcNullStringHandle)
        return 0;
    return ((unsigned int*)m_kHandle)[-1];
}
inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

struct ShaderLibrary
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiD3DShaderInterface* AcquireShader(const char* pcName, unsigned int uiImpl);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void ReleaseShaderInstance(const char* pcName, unsigned int uiImpl);
};
ShaderLibrary* NiD3DShaderFactory_GetD3DShaderFactory();

// NiDX9Renderer::PurgeShader (0x00e75310) is not declared by the shared header.
void PurgeD3DShader();
typedef void (__thiscall *PurgeD3DShaderFunction)(NiDX9Renderer*, NiD3DShaderInterface*);

void FUN_00e7f6b0(void* pkGroup);

unsigned int __fastcall GetImplementation(NiShader* shader);

// @fnv 0x00e806c0
NiD3DShader::~NiD3DShader() throw()
{
    if (m_kName.Exists() && m_kName.GetLength() != 0)
    {
        ShaderLibrary* pkLib = NiD3DShaderFactory_GetD3DShaderFactory();
        if (this == pkLib->AcquireShader(m_kName, GetImplementation(this)))
            pkLib->ReleaseShaderInstance(m_kName, GetImplementation(this));
        if (m_bIsBestImplementation)
        {
            if (this == pkLib->AcquireShader(m_kName, (unsigned int)-1))
                pkLib->ReleaseShaderInstance(m_kName, (unsigned int)-1);
        }
    }
    if (m_pkD3DRenderer)
        reinterpret_cast<PurgeD3DShaderFunction>(&PurgeD3DShader)(
            reinterpret_cast<NiDX9Renderer*>(m_pkD3DRenderer), this);
    m_bInitialized = false;
    FUN_00e7f6b0(m_pkRenderStateGroup);
    m_uiCurrentPass = 0;
    DAT_0126f74c = 0;
}

struct RenderState
{
    void NiDX9Renderer_CalculateBoneMatrices(void* geometry, void* context, int flags, int mode, int reserved);
    void ApplyGeometryTransforms(void* geometry, void* info, void* context);
    void NiDX9Renderer_SetModelTransform(void* context, int enabled);
};
struct IndexController
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c(unsigned int index);
};
// @fnv 0x00e807d0
int __fastcall SetupTransformations(NiD3DShader* shader, void*, void* unusedFirst, void* geometry, void* info, void* unusedFourth,
                                     void* unusedFifth, void* unusedSixth, void* context, void* unusedEighth)
{
    if (info != 0)
    {
        if (shader->m_uiCurrentPass == 0)
        {
            reinterpret_cast<RenderState*>(shader->m_pkD3DRenderer)
                ->NiDX9Renderer_CalculateBoneMatrices(geometry, context, 0, 4, 0);
        }
        reinterpret_cast<IndexController*>(shader->m_pkD3DRenderState)
            ->vfn_2c(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(info) + 0x24));
        reinterpret_cast<RenderState*>(shader->m_pkD3DRenderer)
            ->ApplyGeometryTransforms(geometry, info, context);
    }
    else if (shader->m_uiCurrentPass == 0 ||
             *reinterpret_cast<unsigned char*>(
                 reinterpret_cast<char*>(shader->m_pkD3DRenderer) + 0x209) != 0)
    {
        reinterpret_cast<IndexController*>(shader->m_pkD3DRenderState)->vfn_2c(0);
        reinterpret_cast<RenderState*>(shader->m_pkD3DRenderer)
            ->NiDX9Renderer_SetModelTransform(context, 1);
    }
    return 0;
}

namespace fnv_00e811d0 {
// The shader binding cache has counters at 0x18/0x20 (constructor 0x00ee8910); NiExtraData ends at 0x0c.
struct ShaderConstantBindingCounts
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_uiVertexCount;
    int unk1C;
    int m_uiPixelCount;
};
extern char* DAT_0126f750;

extern int DAT_0126f74c;

struct PassStub
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B(void*);
};
struct ShaderSrc
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void* v2D(int);
};

// @fnv 0x00e811d0
unsigned int __fastcall RenderPartitionedSkinGeometry(NiD3DShader* shader, void*, NiAVObject* apObject, void* a2, void* a3, void* a4, void* a5, void* a6,
                                        void* a7, void* a8)
{
    if (apObject)
    {
        ShaderConstantBindingCounts* pExtraData = reinterpret_cast<ShaderConstantBindingCounts*>(
            apObject->GetExtraData(*reinterpret_cast<NiFixedString*>(&DAT_0126f750)));
        if (pExtraData)
        {
            pExtraData->m_uiVertexCount = 0;
            pExtraData->m_uiPixelCount = 0;
        }
    }
    unsigned int result = ((NiD3DPass*)DAT_0126f74c)->SetupShaderPrograms((NiGeometry*)apObject, (const NiSkinInstance*)a2, a3, (NiGeometryBufferData*)a4, (const NiPropertyState*)a5, (const NiDynamicEffectState*)a6, (const NiTransform*)a7, (const NiBound*)a8, (unsigned int)shader->m_uiCurrentPass);
    NiD3DShaderConstantMap* pSubShader30 = shader->m_spPixelConstantMap.m_pObject;
    if (pSubShader30)
    {
        void* t = ((NiD3DPass*)DAT_0126f74c)->m_spPixelShader.m_pObject;
        if (t)
            pSubShader30->ConfigureShaderConstantMap((NiD3DShaderProgram*)t, (NiGeometry*)apObject, (const NiSkinInstance*)a2, (const NiSkinPartition::Partition*)a3, (NiGeometryBufferData*)a4, (const NiPropertyState*)a5, (const NiDynamicEffectState*)a6, *(const NiTransform*)a7, *(const NiBound*)a8, (unsigned int)shader->m_uiCurrentPass, true);
    }
    NiD3DShaderConstantMap* pSubShader34 = shader->m_spVertexConstantMap.m_pObject;
    if (pSubShader34)
    {
        void* t = ((NiD3DPass*)DAT_0126f74c)->m_spVertexShader.m_pObject;
        if (t)
            pSubShader34->ConfigureShaderConstantMap((NiD3DShaderProgram*)t, (NiGeometry*)apObject, (const NiSkinInstance*)a2, (const NiSkinPartition::Partition*)a3, (NiGeometryBufferData*)a4, (const NiPropertyState*)a5, (const NiDynamicEffectState*)a6, *(const NiTransform*)a7, *(const NiBound*)a8, (unsigned int)shader->m_uiCurrentPass, true);
    }
    if (!shader->m_uiCurrentPass)
    {
        ShaderSrc* pShaderSrc = reinterpret_cast<ShaderSrc*>(shader->m_spShaderDecl.m_pObject);
        if (pShaderSrc)
            reinterpret_cast<PassStub*>(shader->m_pkD3DRenderState)->v2B(pShaderSrc->v2D(0));
    }
    return result;
}
}  // namespace fnv_00e811d0

// @fnv 0x00e814f0
// src: COMMUNITY 0x00e814f0
char __cdecl NiD3DShader_GetVSPresentAllPasses(void)
{
    return *(int*)(DAT_0126f74c + 0x5c) != 0;
}

// Global renderer state pointer; the dword flag at +0x44 of the pointed-to
// object is tested and returned as a boolean byte.
struct RendererState008
{
    char unk00[0x44];
    int m_iFadeIndex;
};

// @fnv 0x00e81500
// src: COMMUNITY 0x00e81500
unsigned char NiD3DShader_GetPSPresentAllPasses()
{
    RendererState008* pState = reinterpret_cast<RendererState008*>(DAT_0126f74c);
    return pState->m_iFadeIndex != 0;
}

struct BeamTextureState
{
    void SetStageValue(unsigned int uiState, unsigned int uiValue, bool bSave);
};

struct ModelMatrix3
{
    float m_afEntries[3][3];
    float GetEntry(unsigned int uiRow, unsigned int uiCol) const
    {
        return m_afEntries[uiRow][uiCol];
    }
};

struct ModelPoint3
{
    float x, y, z;
};

struct ViewMatrix
{
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
};

struct ModelXformState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BeamTextureState* m_pCurrentRenderState;
    int unk14;
    int unk18;
    ViewMatrix m_kWorldView;
    char unk5c;
    char unk5d;
    bool m_bFlag5e;
};

struct ModelRendererView
{
    int unk0000;
    int unk0004;
    int unk0008;
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
    ViewMatrix m_kSecondShadowMatrix;
};

extern unsigned int DAT_0126f0e4;

// Sets beam texture state values, flags m_bFlag5e from DAT_0126f0e4, and builds pkState->m_kWorldView from the renderer view, rotation and translation.
// @fnv 0x00e80a50
// src: COMMUNITY 0x00e80a50
void __cdecl NiD3DShader_PackWorldPerspectiveEffect(const ModelMatrix3* pkRot, const ModelPoint3* pkTrans, ModelXformState* pkState, bool bSave,
                          const ModelRendererView* pkRenderer)
{
    pkState->m_pCurrentRenderState->SetStageValue(0xb, 0x20000, bSave);
    unsigned int uiValue = DAT_0126f0e4;
    if (uiValue != 0 && uiValue != 0x100)
        pkState->m_bFlag5e = true;
    else
        pkState->m_bFlag5e = false;
    pkState->m_pCurrentRenderState->SetStageValue(0x18, uiValue, bSave);

    const ViewMatrix& V = pkRenderer->m_kSecondShadowMatrix;
    ViewMatrix& M = pkState->m_kWorldView;

    M._11 = V._11 * pkRot->GetEntry(0, 0) + V._12 * pkRot->GetEntry(0, 1) + V._13 * pkRot->GetEntry(0, 2);
    M._21 = V._21 * pkRot->GetEntry(0, 0) + V._22 * pkRot->GetEntry(0, 1) + V._23 * pkRot->GetEntry(0, 2);
    M._31 = V._31 * pkRot->GetEntry(0, 0) + V._32 * pkRot->GetEntry(0, 1) + V._33 * pkRot->GetEntry(0, 2);
    M._12 = V._11 * pkRot->GetEntry(1, 0) + V._12 * pkRot->GetEntry(1, 1) + V._13 * pkRot->GetEntry(1, 2);
    M._22 = V._21 * pkRot->GetEntry(1, 0) + V._22 * pkRot->GetEntry(1, 1) + V._23 * pkRot->GetEntry(1, 2);
    M._32 = V._31 * pkRot->GetEntry(1, 0) + V._32 * pkRot->GetEntry(1, 1) + V._33 * pkRot->GetEntry(1, 2);
    M._13 = V._11 * pkRot->GetEntry(2, 0) + V._12 * pkRot->GetEntry(2, 1) + V._13 * pkRot->GetEntry(2, 2);
    M._23 = V._21 * pkRot->GetEntry(2, 0) + V._22 * pkRot->GetEntry(2, 1) + V._23 * pkRot->GetEntry(2, 2);
    M._33 = V._31 * pkRot->GetEntry(2, 0) + V._32 * pkRot->GetEntry(2, 1) + V._33 * pkRot->GetEntry(2, 2);
    M._41 = V._41 * pkRot->GetEntry(0, 0) + V._42 * pkRot->GetEntry(0, 1) + V._43 * pkRot->GetEntry(0, 2) + pkTrans->x;
    M._42 = V._41 * pkRot->GetEntry(1, 0) + V._42 * pkRot->GetEntry(1, 1) + V._43 * pkRot->GetEntry(1, 2) + pkTrans->y;
    M._43 = V._41 * pkRot->GetEntry(2, 0) + V._42 * pkRot->GetEntry(2, 1) + V._43 * pkRot->GetEntry(2, 2) + pkTrans->z;
    M._14 = M._24 = M._34 = M._44 = 0.0f;
}

void* __cdecl Object_DispatchCommandFour(unsigned int);
struct ConstantEntry
{
    unsigned int unk00, unk04, unk08;
    NiFixedString name;
    unsigned int unk10;
    unsigned int flags;
    unsigned int unk18;
    unsigned int key;
};
// The shared GetEntry overloads are grouped in reverse order by this compiler.
// Dispatch the index lookup through the game's slot until the shared ABI is corrected.
static __forceinline ConstantEntry* GetConstantMapEntry(NiD3DShaderConstantMap* map, unsigned int index)
{
    typedef ConstantEntry* (__thiscall *GetEntryFunction)(NiD3DShaderConstantMap*, unsigned int);
    return reinterpret_cast<GetEntryFunction>((*reinterpret_cast<void***>(map))[0x74 / sizeof(void*)])(map, index);
}

struct Binding
{
    unsigned int key;
    void* data;
};
struct FUN_00ee8910
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int vertexCount, unk1c, pixelCount;
    Binding* vertices;
    unsigned int unk28;
    Binding* pixels;
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
    FUN_00ee8910(char**, unsigned int, unsigned int);
    void AddVertex(unsigned int pass, ConstantEntry* entry, void* data)
    {
        vertices[vertexCount].key = (pass << DAT_01101294) | entry->key;
        vertices[vertexCount].data = data;
        ++vertexCount;
    }
    void AddPixel(unsigned int pass, ConstantEntry* entry, void* data)
    {
        pixels[pixelCount].key = (pass << DAT_01101294) | entry->key;
        pixels[pixelCount].data = data;
        ++pixelCount;
    }
};
struct GeometryAccess
{
    void DeleteExtraDataByKey(char**);
    void* FUN_00a5bdd0(const NiFixedString&);
    bool SetExtraDataName(FUN_00ee8910*);
};
void* __cdecl Object_DispatchCommandFour(unsigned int);
// @fnv 0x00e81510
extern "C" void __cdecl BindShaderConstants(NiD3DShader* shader, NiGeometry* geometry)
{
    GeometryAccess* pGeometryAccess = reinterpret_cast<GeometryAccess*>(geometry);
    pGeometryAccess->DeleteExtraDataByKey(&DAT_0126f750);
    unsigned int vertexCount = 0;
    unsigned int pixelCount = 0;
    if (shader->m_spVertexConstantMap.m_pObject)
    {
        unsigned int count = shader->m_spVertexConstantMap.m_pObject->m_kEntries.m_usESize;
        for (unsigned int i = 0; i < count; ++i)
        {
            ConstantEntry* entry = GetConstantMapEntry(shader->m_spVertexConstantMap.m_pObject, i);
            if (entry && (entry->flags & 0xf0000000) == 0x30000000)
                ++vertexCount;
        }
    }
    if (shader->m_spPixelConstantMap.m_pObject)
    {
        unsigned int count = shader->m_spPixelConstantMap.m_pObject->m_kEntries.m_usESize;
        for (unsigned int i = 0; i < count; ++i)
        {
            ConstantEntry* entry = GetConstantMapEntry(shader->m_spPixelConstantMap.m_pObject, i);
            if (entry && (entry->flags & 0xf0000000) == 0x30000000)
                ++pixelCount;
        }
    }
    NiD3DPass* pass = reinterpret_cast<NiD3DPass*>(DAT_0126f74c);
    if (pass)
    {
        NiD3DShaderConstantMap* pConstantMap = pass->m_spPixelConstantMap.m_pObject;
        if (pConstantMap)
        {
            unsigned int count = pConstantMap->m_kEntries.m_usESize;
            for (unsigned int i = 0; i < count; ++i)
            {
                ConstantEntry* entry = GetConstantMapEntry(pConstantMap, i);
                if (entry && (entry->flags & 0xf0000000) == 0x30000000)
                    ++pixelCount;
            }
        }
        pConstantMap = pass->m_spVertexConstantMap.m_pObject;
        if (pConstantMap)
        {
            unsigned int count = pConstantMap->m_kEntries.m_usESize;
            for (unsigned int i = 0; i < count; ++i)
            {
                ConstantEntry* entry = GetConstantMapEntry(pConstantMap, i);
                if (entry && (entry->flags & 0xf0000000) == 0x30000000)
                    ++vertexCount;
            }
        }
    }
    if (vertexCount > 0 || pixelCount > 0)
    {
        FUN_00ee8910* bindings = new FUN_00ee8910(&DAT_0126f750, vertexCount, pixelCount);
        pass = reinterpret_cast<NiD3DPass*>(DAT_0126f74c);
        if (pass)
        {
            unsigned int count = 0;
            if (shader->m_spPixelConstantMap.m_pObject)
                count = shader->m_spPixelConstantMap.m_pObject->m_kEntries.m_usESize;
            for (unsigned int i = 0; i < count; ++i)
            {
                ConstantEntry* entry = GetConstantMapEntry(shader->m_spPixelConstantMap.m_pObject, i);
                if (entry && (entry->flags & 0xf0000000) == 0x30000000)
                {
                    void* data = pGeometryAccess->FUN_00a5bdd0(entry->name);
                    if (data)
                        bindings->AddPixel(255, entry, data);
                }
            }
            count = 0;
            if (shader->m_spVertexConstantMap.m_pObject)
                count = shader->m_spVertexConstantMap.m_pObject->m_kEntries.m_usESize;
            for (unsigned int i = 0; i < count; ++i)
            {
                ConstantEntry* entry = GetConstantMapEntry(shader->m_spVertexConstantMap.m_pObject, i);
                if (entry && (entry->flags & 0xf0000000) == 0x30000000)
                {
                    void* data = pGeometryAccess->FUN_00a5bdd0(entry->name);
                    if (data)
                        bindings->AddVertex(255, entry, data);
                }
            }
            NiD3DShaderConstantMap* pConstantMap = pass->m_spPixelConstantMap.m_pObject;
            if (pConstantMap)
            {
                unsigned int count = pConstantMap->m_kEntries.m_usESize;
                for (unsigned int i = 0; i < count; ++i)
                {
                    ConstantEntry* entry = GetConstantMapEntry(pConstantMap, i);
                    if (entry && (entry->flags & 0xf0000000) == 0x30000000)
                    {
                        void* data = pGeometryAccess->FUN_00a5bdd0(entry->name);
                        if (data)
                            bindings->AddPixel(0, entry, data);
                    }
                }
            }
            pConstantMap = pass->m_spVertexConstantMap.m_pObject;
            if (pConstantMap)
            {
                unsigned int count = pConstantMap->m_kEntries.m_usESize;
                for (unsigned int i = 0; i < count; ++i)
                {
                    ConstantEntry* entry = GetConstantMapEntry(pConstantMap, i);
                    if (entry && (entry->flags & 0xf0000000) == 0x30000000)
                    {
                        void* data = pGeometryAccess->FUN_00a5bdd0(entry->name);
                        if (data)
                            bindings->AddVertex(0, entry, data);
                    }
                }
            }
        }
        pGeometryAccess->SetExtraDataName(bindings);
    }
}

extern "C" void __cdecl FUN_00e81a90();

// @fnv 0x00e80570
// src: XBOX_PDB 0x00e80570
void __cdecl NiD3DShader_Initialize()
{
    FUN_00e81a90();
}

struct FnvCpu_FUN_00eea530_CpuObject
{
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
    int value;
    int NiD3DShader_GetShaderDecl();
};
// @fnv 0x00eea530
// src: COMMUNITY 0x00eea530
int FnvCpu_FUN_00eea530_CpuObject::NiD3DShader_GetShaderDecl()
{
    return value;
}

// Sets two render-state stage values, then writes m_kWorldView using pkRot, the second shadow matrix, and pkTrans.
// @fnv 0x00e80860
void __cdecl SetShadowWorldView(const ModelMatrix3* pkRot, const ModelPoint3* pkTrans, ModelXformState* pkState,
                                bool bSave, const ModelRendererView* pkRenderer)
{
    pkState->m_pCurrentRenderState->SetStageValue(0xb, 0x20000, bSave);
    pkState->m_bFlag5e = true;
    pkState->m_pCurrentRenderState->SetStageValue(0x18, 2, bSave);
    const ViewMatrix& kV = pkRenderer->m_kSecondShadowMatrix;
    ViewMatrix& kM = pkState->m_kWorldView;
    kM._11 = pkRot->GetEntry(0, 0) * kV._11 + pkRot->GetEntry(0, 1) * kV._12 + pkRot->GetEntry(0, 2) * kV._13;
    kM._21 = pkRot->GetEntry(0, 0) * kV._21 + pkRot->GetEntry(0, 1) * kV._22 + pkRot->GetEntry(0, 2) * kV._23;
    kM._31 = pkRot->GetEntry(0, 0) * kV._31 + pkRot->GetEntry(0, 1) * kV._32 + pkRot->GetEntry(0, 2) * kV._33;
    kM._12 = pkRot->GetEntry(1, 0) * kV._11 + pkRot->GetEntry(1, 1) * kV._12 + pkRot->GetEntry(1, 2) * kV._13;
    kM._22 = pkRot->GetEntry(1, 0) * kV._21 + pkRot->GetEntry(1, 1) * kV._22 + pkRot->GetEntry(1, 2) * kV._23;
    kM._32 = pkRot->GetEntry(1, 0) * kV._31 + pkRot->GetEntry(1, 1) * kV._32 + pkRot->GetEntry(1, 2) * kV._33;
    kM._13 = pkRot->GetEntry(2, 0) * kV._11 + pkRot->GetEntry(2, 1) * kV._12 + pkRot->GetEntry(2, 2) * kV._13;
    kM._23 = pkRot->GetEntry(2, 0) * kV._21 + pkRot->GetEntry(2, 1) * kV._22 + pkRot->GetEntry(2, 2) * kV._23;
    kM._33 = pkRot->GetEntry(2, 0) * kV._31 + pkRot->GetEntry(2, 1) * kV._32 + pkRot->GetEntry(2, 2) * kV._33;
    kM._41 =
        pkRot->GetEntry(0, 0) * kV._41 + pkRot->GetEntry(0, 1) * kV._42 + pkRot->GetEntry(0, 2) * kV._43 + pkTrans->x;
    kM._42 =
        pkRot->GetEntry(1, 0) * kV._41 + pkRot->GetEntry(1, 1) * kV._42 + pkRot->GetEntry(1, 2) * kV._43 + pkTrans->y;
    kM._43 =
        pkRot->GetEntry(2, 0) * kV._41 + pkRot->GetEntry(2, 1) * kV._42 + pkRot->GetEntry(2, 2) * kV._43 + pkTrans->z;
    kM._14 = kM._24 = kM._34 = kM._44 = 0.0f;
}

// Sets render-state stage values, then computes m_kWorldView using pkRot, m_kSecondShadowMatrix, and pkTrans.
// @fnv 0x00e80c50
void __cdecl UpdateWorldViewMatrix(const ModelMatrix3* pkRot, const ModelPoint3* pkTrans, ModelXformState* pkState,
                                   bool bSave, const ModelRendererView* pkRenderer)
{
    pkState->m_pCurrentRenderState->SetStageValue(0xb, 0x30000, bSave);
    pkState->m_bFlag5e = true;
    pkState->m_pCurrentRenderState->SetStageValue(0x18, 2, bSave);
    const ViewMatrix& kV = pkRenderer->m_kSecondShadowMatrix;
    ViewMatrix& kM = pkState->m_kWorldView;
    kM._11 = pkRot->GetEntry(0, 0) * kV._11 + pkRot->GetEntry(0, 1) * kV._12 + pkRot->GetEntry(0, 2) * kV._13;
    kM._21 = pkRot->GetEntry(0, 0) * kV._21 + pkRot->GetEntry(0, 1) * kV._22 + pkRot->GetEntry(0, 2) * kV._23;
    kM._31 = pkRot->GetEntry(0, 0) * kV._31 + pkRot->GetEntry(0, 1) * kV._32 + pkRot->GetEntry(0, 2) * kV._33;
    kM._12 = pkRot->GetEntry(1, 0) * kV._11 + pkRot->GetEntry(1, 1) * kV._12 + pkRot->GetEntry(1, 2) * kV._13;
    kM._22 = pkRot->GetEntry(1, 0) * kV._21 + pkRot->GetEntry(1, 1) * kV._22 + pkRot->GetEntry(1, 2) * kV._23;
    kM._32 = pkRot->GetEntry(1, 0) * kV._31 + pkRot->GetEntry(1, 1) * kV._32 + pkRot->GetEntry(1, 2) * kV._33;
    kM._13 = pkRot->GetEntry(2, 0) * kV._11 + pkRot->GetEntry(2, 1) * kV._12 + pkRot->GetEntry(2, 2) * kV._13;
    kM._23 = pkRot->GetEntry(2, 0) * kV._21 + pkRot->GetEntry(2, 1) * kV._22 + pkRot->GetEntry(2, 2) * kV._23;
    kM._33 = pkRot->GetEntry(2, 0) * kV._31 + pkRot->GetEntry(2, 1) * kV._32 + pkRot->GetEntry(2, 2) * kV._33;
    kM._41 = pkTrans->x;
    kM._42 = pkTrans->y;
    kM._43 = pkTrans->z;
    kM._14 = kM._24 = kM._34 = kM._44 = 0.0f;
}

// Sets render-state stage values, then computes m_kWorldView using pkRot, the second shadow matrix, and pkTrans.
// @fnv 0x00e80de0
void __cdecl SetWorldViewFromShadow(const ModelMatrix3* pkRot, const ModelPoint3* pkTrans, ModelXformState* pkState,
                                    bool bSave, const ModelRendererView* pkRenderer)
{
    pkState->m_pCurrentRenderState->SetStageValue(0xb, 0x30000, bSave);
    pkState->m_bFlag5e = true;
    pkState->m_pCurrentRenderState->SetStageValue(0x18, 3, bSave);
    const ViewMatrix& kV = pkRenderer->m_kSecondShadowMatrix;
    ViewMatrix& kM = pkState->m_kWorldView;
    kM._11 = pkRot->GetEntry(0, 0) * kV._11 + pkRot->GetEntry(0, 1) * kV._12 + pkRot->GetEntry(0, 2) * kV._13;
    kM._21 = pkRot->GetEntry(0, 0) * kV._21 + pkRot->GetEntry(0, 1) * kV._22 + pkRot->GetEntry(0, 2) * kV._23;
    kM._31 = pkRot->GetEntry(0, 0) * kV._31 + pkRot->GetEntry(0, 1) * kV._32 + pkRot->GetEntry(0, 2) * kV._33;
    kM._12 = pkRot->GetEntry(1, 0) * kV._11 + pkRot->GetEntry(1, 1) * kV._12 + pkRot->GetEntry(1, 2) * kV._13;
    kM._22 = pkRot->GetEntry(1, 0) * kV._21 + pkRot->GetEntry(1, 1) * kV._22 + pkRot->GetEntry(1, 2) * kV._23;
    kM._32 = pkRot->GetEntry(1, 0) * kV._31 + pkRot->GetEntry(1, 1) * kV._32 + pkRot->GetEntry(1, 2) * kV._33;
    kM._13 = pkRot->GetEntry(2, 0) * kV._11 + pkRot->GetEntry(2, 1) * kV._12 + pkRot->GetEntry(2, 2) * kV._13;
    kM._23 = pkRot->GetEntry(2, 0) * kV._21 + pkRot->GetEntry(2, 1) * kV._22 + pkRot->GetEntry(2, 2) * kV._23;
    kM._33 = pkRot->GetEntry(2, 0) * kV._31 + pkRot->GetEntry(2, 1) * kV._32 + pkRot->GetEntry(2, 2) * kV._33;
    kM._41 = pkTrans->x;
    kM._42 = pkTrans->y;
    kM._43 = pkTrans->z;
    kM._14 = kM._24 = kM._34 = kM._44 = 0.0f;
}

// Sets render-state stage values, then computes the world-view matrix using pkRot, the second shadow matrix, and pkTrans.
// @fnv 0x00e80f70
void __cdecl SetWorldViewMatrix(const ModelMatrix3* pkRot, const ModelPoint3* pkTrans, ModelXformState* pkState,
                                bool bSave, const ModelRendererView* pkRenderer)
{
    pkState->m_pCurrentRenderState->SetStageValue(0xb, 0x10000, bSave);
    pkState->m_bFlag5e = true;
    pkState->m_pCurrentRenderState->SetStageValue(0x18, 3, bSave);
    const ViewMatrix& kV = pkRenderer->m_kSecondShadowMatrix;
    ViewMatrix& kM = pkState->m_kWorldView;
    kM._11 = pkRot->GetEntry(0, 0) * kV._11 + pkRot->GetEntry(0, 1) * kV._12 + pkRot->GetEntry(0, 2) * kV._13;
    kM._21 = pkRot->GetEntry(0, 0) * kV._21 + pkRot->GetEntry(0, 1) * kV._22 + pkRot->GetEntry(0, 2) * kV._23;
    kM._31 = pkRot->GetEntry(0, 0) * kV._31 + pkRot->GetEntry(0, 1) * kV._32 + pkRot->GetEntry(0, 2) * kV._33;
    kM._12 = pkRot->GetEntry(1, 0) * kV._11 + pkRot->GetEntry(1, 1) * kV._12 + pkRot->GetEntry(1, 2) * kV._13;
    kM._22 = pkRot->GetEntry(1, 0) * kV._21 + pkRot->GetEntry(1, 1) * kV._22 + pkRot->GetEntry(1, 2) * kV._23;
    kM._32 = pkRot->GetEntry(1, 0) * kV._31 + pkRot->GetEntry(1, 1) * kV._32 + pkRot->GetEntry(1, 2) * kV._33;
    kM._13 = pkRot->GetEntry(2, 0) * kV._11 + pkRot->GetEntry(2, 1) * kV._12 + pkRot->GetEntry(2, 2) * kV._13;
    kM._23 = pkRot->GetEntry(2, 0) * kV._21 + pkRot->GetEntry(2, 1) * kV._22 + pkRot->GetEntry(2, 2) * kV._23;
    kM._33 = pkRot->GetEntry(2, 0) * kV._31 + pkRot->GetEntry(2, 1) * kV._32 + pkRot->GetEntry(2, 2) * kV._33;
    kM._41 = pkTrans->x;
    kM._42 = pkTrans->y;
    kM._43 = pkTrans->z;
    kM._14 = kM._24 = kM._34 = kM._44 = 0.0f;
}

struct VBChipQ
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pkOwningStream;
};

struct GeomBufferDataQ
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int m_uiRegisterStreamCount;
    unsigned int* m_puiVertexStrides;
    VBChipQ** m_ppkVertexBuffers;
    unsigned int unk2c;
    unsigned int unk30;
    void* m_pkIndexBuffer;

    unsigned int GetVertexStride(unsigned int i) const
    {
        return i < m_uiRegisterStreamCount ? m_puiVertexStrides[i] : 0;
    }
    VBChipQ* GetVBChip(unsigned int i) const
    {
        return i < m_uiRegisterStreamCount ? m_ppkVertexBuffers[i] : 0;
    }
};

struct AdditionalDataQ
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
    virtual bool IsValid();
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
    void* m_pAdditionalData;
};

struct GeomDataQ
{
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
    unsigned int unk2c;
    AdditionalDataQ* m_spAdditionalGeomData;
    GeomBufferDataQ* m_pkGeometryRendererData;

    AdditionalDataQ* GetAdditionalGeometryData()
    {
        return m_spAdditionalGeomData;
    }
};

struct GeometryQ
{
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    GeomDataQ* m_spGeometryData;
    GeomDataQ* GetModelData() const
    {
        return m_spGeometryData;
    }
    void* m_spSkinningInstance;
};

struct SkinPartitionQ
{
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
    GeomBufferDataQ* m_pkGeometryRendererData;
};

struct ShaderDeclQ
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
    virtual void* GetD3DDeclaration(int);
};

struct RenderStateQ
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
    virtual void SetShaderDeclaration(void*);
};

// These packet helpers bind to 0x00e6d760/0x00e6d780/0x00e71fe0 in niconsolerenderer.cpp.
// The shared NiDX9Renderer header does not yet declare them; keep their member-call ABI here.
void GetPacketDeclaration();
void UpdateShaderPackingPacket();
void PrepareShaderGeometryPacket();
typedef void* (__thiscall *GetPacketDeclarationFunction)(NiDX9Renderer*, void*, int);
typedef void* (__thiscall *UpdateShaderPackingPacketFunction)(NiDX9Renderer*, GeomBufferDataQ*, GeomDataQ*,
                                                             void*, SkinPartitionQ*, ShaderDeclQ*, bool);
typedef void* (__thiscall *PrepareShaderGeometryPacketFunction)(NiDX9Renderer*, GeomBufferDataQ*, GeomDataQ*,
                                                               void*, ShaderDeclQ*, bool);

struct DeviceQ
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
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual long __stdcall SetStreamSource(unsigned int, void*, unsigned int, unsigned int);
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual long __stdcall SetIndices(void*);
};

// @fnv 0x00e812f0
GeomBufferDataQ* __fastcall PrepareShaderAndStreams(NiD3DShader* shader, void*, GeometryQ* pkGeometry, SkinPartitionQ* pkPartition,
                                                      GeomBufferDataQ* pkBufferData, void* pkState)
{
    GeomBufferDataQ* pkBuffData = pkBufferData;
    if (pkGeometry && shader->m_uiCurrentPass == 0)
    {
        GeomDataQ* pkData = pkGeometry->GetModelData();
        void* pkSkin = pkGeometry->m_spSkinningInstance;

        AdditionalDataQ* pkAdd;
        if (pkGeometry->GetModelData() && (pkAdd = pkGeometry->GetModelData()->GetAdditionalGeometryData()) != 0 &&
            pkAdd->IsValid())
        {
            void* pkDecl = pkAdd->m_pAdditionalData;
            ((RenderStateQ*)shader->m_pkD3DRenderState)
                ->SetShaderDeclaration(reinterpret_cast<GetPacketDeclarationFunction>(&GetPacketDeclaration)(
                    reinterpret_cast<NiDX9Renderer*>(shader->m_pkD3DRenderer), pkDecl, 0));
        }
        else if (shader->m_spShaderDecl)
            ((RenderStateQ*)shader->m_pkD3DRenderState)
                ->SetShaderDeclaration(
                    ((ShaderDeclQ*)(NiD3DShaderDeclaration*)shader->m_spShaderDecl)->GetD3DDeclaration(0));

        if (pkPartition)
        {
            pkBuffData = pkPartition->m_pkGeometryRendererData;
            reinterpret_cast<UpdateShaderPackingPacketFunction>(&UpdateShaderPackingPacket)(
                reinterpret_cast<NiDX9Renderer*>(shader->m_pkD3DRenderer), pkBuffData, pkData, pkSkin, pkPartition,
                (ShaderDeclQ*)(NiD3DShaderDeclaration*)shader->m_spShaderDecl, false);
        }
        else
        {
            pkBuffData = pkData->m_pkGeometryRendererData;
            reinterpret_cast<PrepareShaderGeometryPacketFunction>(&PrepareShaderGeometryPacket)(
                reinterpret_cast<NiDX9Renderer*>(shader->m_pkD3DRenderer), pkBuffData, pkData, pkSkin,
                  (ShaderDeclQ*)(NiD3DShaderDeclaration*)shader->m_spShaderDecl, false);
        }
    }

    if (pkBuffData)
    {
        for (unsigned int i = 0; i < pkBuffData->m_uiRegisterStreamCount; i++)
        {
            ((DeviceQ*)shader->m_pkD3DDevice)
                ->SetStreamSource(i, pkBuffData->GetVBChip(i)->m_pkOwningStream, 0, pkBuffData->GetVertexStride(i));
        }
        ((DeviceQ*)shader->m_pkD3DDevice)->SetIndices(pkBuffData->m_pkIndexBuffer);
    }
    return pkBuffData;
}
