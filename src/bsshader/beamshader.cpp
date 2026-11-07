#define FNV64_NIPOINTER_INLINE_BODIES
// bsshader/beamshader.cpp: BeamPassShader, BloodSplatterBeamShader, DistantLODShader (6 functions)
#include "NiRefObject_inline.h"
#include "../../include/BSShader.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiShader.h"
#include "../../include/NiShaderConstantMap.h"
#include "../../include/NiShaderDeclaration.h"

#include "beamshader_types_BeamShader.h"
#include "beamshader_types_NiConsoleShaderDeclaration.h"

// This unit inlines the reference operations used by its constant maps.
inline void NiD3DShaderConstantMap::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiD3DShaderConstantMap::DecRefCount()
{
    NiRefObject::DecRefCount();
}

extern GraphicsRenderer* g_pkRenderer;
extern const char g_emptyTopicInfoPrompt[1];
extern "C" const char DAT_010A1E50[];
extern "C" const char DAT_010af454[];

class BloodSplatterBeamShader : public BeamShader
{
  public:
    static void* operator new(unsigned int) throw();
    BloodSplatterBeamShader(NiD3DVertexDeclaration*);
    static BSShader* CreateShader();
};

// @fnv 0x00bc4af0
BSShader* BloodSplatterBeamShader::CreateShader()
{
    NiD3DVertexDeclaration* declaration = NiD3DVertexDeclaration::Create((NiRenderer*)g_pkRenderer, 5, 1);
    declaration->SetEntry(0, 0, (NiShaderDeclaration::ShaderParameter)0, (NiShaderDeclaration::ShaderParameterType)2, 0);
    declaration->SetEntry(1, 3, (NiShaderDeclaration::ShaderParameter)3, (NiShaderDeclaration::ShaderParameterType)2, 0);
    declaration->SetEntry(2, 5, (NiShaderDeclaration::ShaderParameter)4, (NiShaderDeclaration::ShaderParameterType)3, 0);
    declaration->SetEntry(3, 7, (NiShaderDeclaration::ShaderParameter)5, (NiShaderDeclaration::ShaderParameterType)1, 0);
    declaration->GetD3DDeclaration();

    BloodSplatterBeamShader* pShader = new BloodSplatterBeamShader(declaration);
    pShader->Initialize();
    pShader->InitializeVertexShader();
    pShader->InitializePixelShader();
    pShader->InitShaderConstants();
    pShader->UseShaderDeclaration(declaration);
    return pShader;
}

class MapPointer
{
  public:
    NiD3DShaderConstantMap* m_pShaderConstantMap;

    MapPointer& operator=(NiD3DShaderConstantMap* pointer)
    {
        if (m_pShaderConstantMap != pointer)
        {
            if (m_pShaderConstantMap)
                m_pShaderConstantMap->DecRefCount();
            m_pShaderConstantMap = pointer;
            if (m_pShaderConstantMap)
                m_pShaderConstantMap->IncRefCount();
        }
        return *this;
    }
};

class DistantLODShader
{
  public:
    unsigned char padding0[0x18];
    GraphicsRenderer* m_pShaderObject;
    unsigned char padding1[0x14];
    MapPointer m_spFirstShaderConstantMap;
    MapPointer m_spSecondShaderConstantMap;
    unsigned char padding2[0x3c];
    float m_fVars[16];

    void UpdateShaderConstants();
};

// Creates the shader constant maps for the shader if not already present, setting constants on the first map.
// @fnv 0x00bc4ed0
void DistantLODShader::UpdateShaderConstants()
{
    if (!m_spSecondShaderConstantMap.m_pShaderConstantMap)
    {
        NiD3DShaderConstantMap* map = new NiD3DShaderConstantMap(m_pShaderObject, 0u);
        m_spSecondShaderConstantMap = map;
        m_spSecondShaderConstantMap.m_pShaderConstantMap->SetConstant(DAT_010A1E50, 0x20000009, 0, 0, 4, 0, 0, 0, 0, 0);
        m_spSecondShaderConstantMap.m_pShaderConstantMap->SetConstant(DAT_010af454, 0x10000009, 0, 4, 4,
                                                                      g_emptyTopicInfoPrompt, 0x40, 4, &m_fVars[0], 0);
    }
    if (!m_spFirstShaderConstantMap.m_pShaderConstantMap)
    {
        NiD3DShaderConstantMap* map = new NiD3DShaderConstantMap(m_pShaderObject, 2u);
        m_spFirstShaderConstantMap = map;
    }
}

#include "beamshader_pass.h"
// Ensures the pass has a stage, then assigns vertex/pixel shaders and sets the pass render states.
// @fnv 0x00bc4c00
void BeamPassShader::SetupPass()
{
    BeamPassPointer p;
    BeamStagePointer stage;
    p = pass.m_pObject;
    if (p.object->GetStageCount() < 1)
    {
        BeamStage::CreateNewStage((NiPointer<BeamStage>&)stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        stage.object->state->NiD3DTextureStageGroup_SetSamplerState(7, 0, 0, false);
        p.object->NiD3DPass_SetStage(p.object->m_uiCurrentStage, stage.object);
    }
    reinterpret_cast<NiPointer<NiRefObject>&>(p.object->m_spVertexShader) = vertex;
    reinterpret_cast<NiPointer<NiRefObject>&>(p.object->m_spPixelShader) = pixel;
    p.object->SetRenderState(22, 1, true);
    p.object->SetRenderState(168, 15, true);
    p.object->SetRenderState(27, 1, true);
    p.object->SetRenderState(19, 5, true);
    p.object->SetRenderState(20, 6, true);
    p.object->SetRenderState(15, 0, true);
    p.object->SetRenderState(52, 0, true);
    p.object->SetRenderState(7, 1, true);
    p.object->SetRenderState(23, 4, true);
    p.object->SetRenderState(14, 0, true);
}

// @fnv 0x00bc4ea0
bool BeamPassShader::InitializePass()
{
    if (!pass.m_pObject)
        NiD3DPass::CreateD3DPass(pass);
    SetupPass();
    return true;
}

struct Holder
{
    void FUN_00bc49a0();
};
void __cdecl _delete(void*, unsigned int);
struct S
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00bc49a0 on this, deletes this with size 0xc0 when flag has bit 0 set, and returns this.
// @fnv 0x00bc4e70
void* S::DestroyIfFlagged(unsigned int auiFlags)
{
    ((Holder*)this)->FUN_00bc49a0();
    if (auiFlags & 1)
        _delete(this, 0xc0);
    return this;
}

class FUN_00bc49a0 : public BSShader
{
  public:
    static NiPointer<NiRefObject> ms_spShared;
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
    NiPointer<NiD3DPass> m_spPass;
    NiPointer<NiRefObject> m_spVertexShaderObject;
    NiPointer<NiRefObject> m_spPixelShaderObject;
    virtual ~FUN_00bc49a0();
};

// Clears the shared pointer and the pass and two other reference-counted pointers, releasing them.
// @fnv 0x00bc49a0
FUN_00bc49a0::~FUN_00bc49a0()
{
    ms_spShared = 0;
    m_spPass = 0;
    m_spVertexShaderObject = 0;
    m_spPixelShaderObject = 0;
}
