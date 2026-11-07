
// src/bsshader/precipitationshader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/precipitationshader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiRefObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPointer.h"
#include "../../include/NiD3DShaderProgram.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DPass.h"
#include "../../include/BSShader.h"
#include "../../include/NiDX9ShaderDeclaration.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiD3DVertexShader::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiD3DVertexShader::DecRefCount()
{
    NiRefObject::DecRefCount();
}

inline void NiD3DPixelShader::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiD3DPixelShader::DecRefCount()
{
    NiRefObject::DecRefCount();
}

inline void NiD3DShaderConstantMap::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiD3DShaderConstantMap::DecRefCount()
{
    NiRefObject::DecRefCount();
}

inline void NiD3DPass::IncRefCount()
{
    ++m_uiRefCount;
}

inline void NiD3DPass::DecRefCount()
{
    int* p = reinterpret_cast<int*>(&m_uiRefCount);
    if (--*p == 0)
        FUN_00e80190();
}

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
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

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

extern "C" void* g_012005c0;

// @fnv 0x00bb0540
// src: XBOX_PDB 0x00bb0540
void* __cdecl PrecipitationShader_GetRTTI()
{
    return &g_012005c0;
}

extern void* g_012005fc;

// @fnv 0x00bb0d10
// src: XBOX_PDB 0x00bb0d10
void* __cdecl PrecipitationShaderProperty_GetRTTI()
{
    return &g_012005fc;
}

struct FUN_00bb0d20_shell
{
    void* __thiscall PrecipitationShaderProperty_GetClampNI();
};

// @fnv 0x00bb0d20
// src: XBOX_PDB 0x00bb0d20
void* FUN_00bb0d20_shell::PrecipitationShaderProperty_GetClampNI()
{
    return *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x94);
}

struct FUN_00bb0d30_shell
{
    void __thiscall PrecipitationShaderProperty_SetClampNI(int value);
};

// @fnv 0x00bb0d30
// src: XBOX_PDB 0x00bb0d30
void __thiscall FUN_00bb0d30_shell::PrecipitationShaderProperty_SetClampNI(int value)
{
    *(int*)((char*)this + 0x94) = value;
}

void* __cdecl FUN_00bb0550();
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00bb0a50_shell
{
    void* __thiscall DestroyIfFlagged(int flags);
};
// @fnv 0x00bb0a50
void* __thiscall FUN_00bb0a50_shell::DestroyIfFlagged(int flags)
{
    FUN_00bb0550();
    if (flags & 1)
        operator delete(this, 0xac);
    return this;
}

extern NiPoint3 g_011a9b7c;

struct FUN_00bb04b0 : BSShader
{
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    NiPoint3 m_90;
    int m_9c;
    NiPoint3 m_a0;

    FUN_00bb04b0();
    virtual void vf();
};

// Initializes the object's fields: sets iShaderType to 0x12, zeroes m_90, copies g_011a9b7c into m_a0, and sets m_bUsesNiRenderState to 1.
// @fnv 0x00bb04b0
FUN_00bb04b0::FUN_00bb04b0() : m_9c(0), m_a0(0.0f, 0.0f, 0.0f)
{
    iShaderType = 0x12;
    m_90 = NiPoint3(0.0f, 0.0f, 0.0f);
    m_a0 = g_011a9b7c;
    m_bUsesNiRenderState = 1;
}

struct SpawnedObject : BSShader
{
    SpawnedObject();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
};

extern "C" void* g_011f9508;

// @fnv 0x00bb0660
// src: COMMUNITY 0x00bb0660
void* __cdecl PrecipitationShader_CreateShader()
{
    NiDX9ShaderDeclaration* pHost = NiDX9ShaderDeclaration::Create((NiRenderer*)g_011f9508, 3, 2);
    pHost->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0, (NiShaderDeclaration::ShaderParameterType)2, 0);
    pHost->SetEntry(1, 7, (NiShaderDeclaration::ShaderParameter)5, (NiShaderDeclaration::ShaderParameterType)1, 0);
    pHost->SetEntryAlt(1, 0, 6, (NiShaderDeclaration::ShaderParameter)0x80000000, (NiShaderDeclaration::ShaderParameterType)2, (NiShaderDeclaration::ShaderParameterUsage)5, 1, (NiShaderDeclaration::ShaderParameterTesselator)0);
    pHost->GetD3DDeclaration();

    SpawnedObject* pObj = new SpawnedObject();
    pObj->Initialize();
    pObj->v13c();
    pObj->v148();
    pObj->InitShaderConstants();
    pObj->UseShaderDeclaration(pHost);
    return pObj;
}

class D3DRenderStateGroup
{
public:
    void SetNodeValue(unsigned int uiState, unsigned int uiValue, bool bSave);
};
D3DRenderStateGroup* __cdecl FUN_00e7f5d0();

inline D3DRenderStateGroup*& GetRenderState(D3DRenderStateGroup*& state)
{
    if (!state)
        state = FUN_00e7f5d0();
    return state;
}

class BeamStage
{
public:
    unsigned char _pad00[0x60];
    unsigned int m_uiRefCount;

    void NiD3DTextureStage_SetFilterMode(int iFlag);
    void NiD3DTextureStage_ReturnStageToPool();
    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};

extern NiD3DPass* g_pkPass_012005e0;
extern NiD3DVertexShader* g_pkPixelShader_012005d0;
extern NiD3DPixelShader* g_pkVertexShader_012005c8;

void __cdecl FUN_00e804d0(NiD3DPass** ppkPass);
void __cdecl AssignStageFromPool(NiPointer<BeamStage>* pspPass);
void __cdecl ConfigureBeamStage(BeamStage* pkPass, int a1, int a2, int a3, int a4);

// @fnv 0x00bb0770
// src: COMMUNITY 0x00bb0770
bool __cdecl PrecipitationShader_LoadStagesAndPasses()
{
    NiPointer<BeamStage> spRenderPass;
    FUN_00e804d0(&g_pkPass_012005e0);
    AssignStageFromPool(&spRenderPass);
    ConfigureBeamStage(spRenderPass, 0, 3, 2, 1);
    spRenderPass->NiD3DTextureStage_SetFilterMode(1);
    g_pkPass_012005e0->NiD3DPass_SetStage(g_pkPass_012005e0->m_uiCurrentStage, spRenderPass);
    g_pkPass_012005e0->m_spVertexShader = g_pkPixelShader_012005d0;
    g_pkPass_012005e0->m_spPixelShader = g_pkVertexShader_012005c8;
    GetRenderState(g_pkPass_012005e0->m_pkRenderStateGroup)->SetNodeValue(7, 1, true);
    GetRenderState(g_pkPass_012005e0->m_pkRenderStateGroup)->SetNodeValue(0xe, 0, true);
    GetRenderState(g_pkPass_012005e0->m_pkRenderStateGroup)->SetNodeValue(0x17, 4, true);
    GetRenderState(g_pkPass_012005e0->m_pkRenderStateGroup)->SetNodeValue(0x1b, 1, true);
    D3DRenderStateGroup*& kRS = g_pkPass_012005e0->m_pkRenderStateGroup;
    GetRenderState(kRS)->SetNodeValue(0x13, 5, true);
    GetRenderState(kRS)->SetNodeValue(0x14, 6, true);
    GetRenderState(g_pkPass_012005e0->m_pkRenderStateGroup)->SetNodeValue(0xf, 0, true);
    GetRenderState(g_pkPass_012005e0->m_pkRenderStateGroup)->SetNodeValue(0xa8, 7, true);
    return true;
}

extern float g_afEyePos_012005e4[4];
extern float g_afCamUp_012005f0[4];

struct ShaderConstantsImpl : BSShader
{
    float m_afVelocity[3];
    float m_afMin[3];
    float m_afMax[3];
    float m_afParams[4];
    float m_afAmbientColor[4];

    void InitConstantMaps();
};

// @fnv 0x00bb0a80
void ShaderConstantsImpl::InitConstantMaps()
{
    if (!m_spPixelConstantMap.m_pObject)
    {
        m_spPixelConstantMap = new NiD3DShaderConstantMap(m_pkD3DRenderer, 2u);
        m_spPixelConstantMap->SetConstant("ambient color", 0x10000006, 0, 0, 1, "", 0xc, 4, m_afAmbientColor, false);
    }
    if (!m_spVertexConstantMap.m_pObject)
    {
        m_spVertexConstantMap = new NiD3DShaderConstantMap(m_pkD3DRenderer, 0u);
        m_spVertexConstantMap->SetConstant("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        m_spVertexConstantMap->SetConstant("eye pos", 0x10000006, 0, 8, 1, "", 0xc, 4, g_afEyePos_012005e4, false);
        m_spVertexConstantMap->SetConstant("velocity", 0x10000006, 0, 9, 1, "", 0xc, 4, m_afVelocity, false);
        m_spVertexConstantMap->SetConstant("min", 0x10000006, 0, 0xa, 1, "", 0xc, 4, m_afMin, false);
        m_spVertexConstantMap->SetConstant("max", 0x10000006, 0, 0xb, 1, "", 0xc, 4, m_afMax, false);
        m_spVertexConstantMap->SetConstant("params", 0x10000006, 0, 0xc, 1, "", 0xc, 4, m_afParams, false);
        m_spVertexConstantMap->SetConstant("cam up", 0x10000006, 0, 0xd, 1, "", 0xc, 4, g_afCamUp_012005f0, false);
    }
}

struct FUN_00bb0cf0_cls : BSShader
{
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
    int m_94;
    void __thiscall PrecipitationShaderProperty_SetClampD3D(int value);
};

// @fnv 0x00bb0cf0
// src: XBOX_PDB 0x00bb0cf0
void FUN_00bb0cf0_cls::PrecipitationShaderProperty_SetClampD3D(int value)
{
    m_94 = (value != 3) ? 3 : 0;
}

extern NiPointer<NiRefObject> g_aspSmall[2];
extern NiPointer<NiRefObject> g_aspLarge[4];
extern NiPointer<NiD3DPass> g_spSharedResource;

class FUN_00bb0550 : public BSShader
{
  public:
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
    NiPointer<NiRefObject> m_spUnk9C;
    virtual void vf00();
    ~FUN_00bb0550();
};

// Destructor that clears the four g_aspLarge and two g_aspSmall NiPointers and the g_spSharedResource NiPointer to null.
// @fnv 0x00bb0550
FUN_00bb0550::~FUN_00bb0550()
{
    for (int i = 0; i < 4; i++)
        g_aspLarge[i] = 0;
    for (int i = 0; i < 2; i++)
        g_aspSmall[i] = 0;
    g_spSharedResource = 0;
}

class ShaderManager_bb09
{
  public:
    bool FUN_00be0870();
    bool ResetSharedResources();
};

// Calls FUN_00be0870, zeroes g_aspLarge, g_aspSmall, and g_spSharedResource, then returns the result of FUN_00be0870.
// @fnv 0x00bb09b0
bool ShaderManager_bb09::ResetSharedResources()
{
    bool bResult = FUN_00be0870();
    for (int i = 0; i < 4; i++)
        g_aspLarge[i] = 0;
    for (int i = 0; i < 2; i++)
        g_aspSmall[i] = 0;
    g_spSharedResource = 0;
    return bResult;
}
