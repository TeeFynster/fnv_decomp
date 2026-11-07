// bsshader/debugshader.cpp: BloodSplatterBeamShader, SpeedTreeFrondShaderX, DebugShaderLoader, DebugShaderInit and more (15 functions)
#include "NiRefObject_inline.h"

#include "debugshader_local.h"
#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiRTTI.h"

inline void NiObjectNET::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiObjectNET::DecRefCount()
{
    NiRefObject::DecRefCount();
}

inline void NiTexture::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiTexture::DecRefCount()
{
    NiRefObject::DecRefCount();
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

inline void NiAVObject::IncRefCount()
{
    NiRefObject::IncRefCount();
}

inline void NiAVObject::DecRefCount()
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

inline void NiD3DPass::SetVertexShader(NiD3DVertexShader* shader)
{
    m_spVertexShader = shader;
}

inline void NiD3DPass::SetPixelShader(NiD3DPixelShader* shader)
{
    m_spPixelShader = shader;
}

inline void NiD3DPass::SetRenderState(unsigned int state, unsigned int value, bool save)
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    m_pkRenderStateGroup->SetRenderState(state, value, save);
}

inline NiScreenElementsData* NiScreenElements::GetData()
{
    return static_cast<NiScreenElementsData*>(m_spModelData.m_pObject);
}

inline const NiRTTI* NiRTTI::GetBaseRTTI() const
{
    return m_pBaseRTTI;
}

// @fnv 0x00bd1950
BloodSplatterBeamShader::BloodSplatterBeamShader()
{
    iShaderType = 10;
    m_spTreeVertexShader = NULL;
    for (int i = 0; i < 2; i++)
        m_spPixelShaderVariants[i] = NULL;
    m_pMenuBackgroundScreenGeometry = NULL;
    for (int j = 0; j < 16; j++)
        m_pTextures[j] = NULL;
    m_bUsesNiRenderState = true;
}

// @fnv 0x00bd20e0
bool BloodSplatterBeamShader::ConfigureShaderPass()
{
    NiD3DPass::CreateD3DPass(spPass[0]);
    NiPointer<BeamStage> stage;
    BeamStage::CreateNewStage(stage);
    ConfigureBeamStage(stage.m_pObject, 0, 3, 2, true);
    stage.m_pObject->NiD3DTextureStage_SetFilterMode(0);
    spPass[0].m_pObject->NiD3DPass_SetStage(spPass[0].m_pObject->m_uiCurrentStage, stage.m_pObject);
    spPass[0].m_pObject->SetVertexShader(m_spTreeVertexShader.m_pObject);
    spPass[0].m_pObject->SetPixelShader(m_spPixelShaderVariants[0].m_pObject);
    spPass[0].m_pObject->SetRenderState(7, 0, true);
    spPass[0].m_pObject->SetRenderState(14, 0, true);
    spPass[0].m_pObject->SetRenderState(27, 0, true);
    NiD3DPass* pass = spPass[0].m_pObject;
    pass->SetRenderState(19, 2, true);
    pass->SetRenderState(20, 2, true);
    spPass[0].m_pObject->SetRenderState(168, 15, true);
    return true;
}

// @fnv 0x00bd23f0
BSShader* BloodSplatterBeamShader::CreateShader()
{
    NiD3DVertexDeclaration* decl = NiD3DVertexDeclaration::Create(DAT_011f9508, 2, 1);
    decl->SetEntry(0, 0, NiShaderDeclaration::SHADERPARAM_NI_POSITION, NiShaderDeclaration::SPTYPE_FLOAT3, 0);
    decl->SetEntry(1, 7, NiShaderDeclaration::SHADERPARAM_NI_TEXCOORD0, NiShaderDeclaration::SPTYPE_FLOAT2, 0);
    decl->GetD3DDeclaration();
    BloodSplatterBeamShader* shader = new BloodSplatterBeamShader;
    shader->Initialize();
    shader->InitializeShaderData();
    shader->ConfigureShaderPass();
    shader->UseShaderDeclaration(decl);
    return shader;
}

extern "C" void __cdecl _delete(void* ptr, int size);

struct FUN_00bd23c0_shell
{
    virtual ~FUN_00bd23c0_shell();
    void FUN_00bd1ab0();
    void* DestroyIfFlagged(int);
};

// Calls FUN_00bd1ab0, then deletes this with size 0xc0 when arg has bit 0 set, and returns this.
// @fnv 0x00bd23c0
void* FUN_00bd23c0_shell::DestroyIfFlagged(int arg)
{
    FUN_00bd1ab0();
    if (arg & 1)
        _delete(this, 0xc0);
    return this;
}

struct FUN_00bd2720_shell
{
    virtual void DistantLODShader_ReloadShaders();
};

// @fnv 0x00bd2720
// src: XBOX_PDB 0x00bd2720
void FUN_00bd2720_shell::DistantLODShader_ReloadShaders()
{
    void** v = *(void***)this;
    ((void(__thiscall*)(void*))v[0x13c / 4])(this);
}

struct FUN_00bd3f80_shell
{
    void ProcessState_00bd3f80();
};
extern int _fnv_particle_shader_renderer_level;
typedef void(__thiscall* FUN_00bd3f80_Fn)(FUN_00bd3f80_shell*);
// Calls virtual slots 81 and 87 on this, and slot 88 when _fnv_particle_shader_renderer_level is at least 2.
// @fnv 0x00bd3f80
// src: GUESS 0x00bd3f80 (confidence: low)
void FUN_00bd3f80_shell::ProcessState_00bd3f80()
{
    ((FUN_00bd3f80_Fn*)*(void***)this)[81](this);
    ((FUN_00bd3f80_Fn*)*(void***)this)[87](this);
    if (_fnv_particle_shader_renderer_level >= 2)
        ((FUN_00bd3f80_Fn*)*(void***)this)[88](this);
}

struct FUN_00bd2b40_class
{
    void CallVirtualWithMember();
};

// @fnv 0x00bd2b40
void FUN_00bd2b40_class::CallVirtualWithMember()
{
    void** vtbl = *(void***)this;
    void* arg = *(void**)((char*)this + 0x84);
    typedef void(__thiscall * Fn)(void*, void*);
    ((Fn)vtbl[0x128 / 4])(this, arg);
}

// Clears the vertex shader, both pixel shaders, the screen elements and all 16 texture pointers.
// @fnv 0x00bd1ab0
BloodSplatterBeamShader::~BloodSplatterBeamShader()
{
    m_spTreeVertexShader = 0;
    for (int i = 0; i < 2; i++)
        m_spPixelShaderVariants[i] = 0;
    m_pMenuBackgroundScreenGeometry = 0;
    for (int i = 0; i < 16; i++)
        m_pTextures[i] = 0;
}

extern unsigned int DAT_01202338;
extern void* DAT_0126f74c;

class FUN_00bd1c50_cls
{
  public:
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

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    NiD3DPass* m_5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int m_6c[20];
    unsigned int m_bc;

    int DebugShader_UpdatePipeline(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

// Updates the first texture stage and pixel shader, then selects this render pass.
// @fnv 0x00bd1c50
// src: COMMUNITY 0x00bd1c50
int FUN_00bd1c50_cls::DebugShader_UpdatePipeline(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    v59();
    m_5c->m_kStages.m_pBase[0].m_pObject->m_uiTextureStage = m_6c[m_bc];
    NiD3DPixelShader* pObject = reinterpret_cast<NiD3DPixelShader*>(m_6c[18 + DAT_01202338]);
    m_5c->m_spPixelShader = pObject;
    DAT_0126f74c = m_5c;
    return 0;
}

struct ShaderMacroX
{
    const char* Name;
    const char* Definition;
};

struct ShaderDescX
{
    const char* pFile;
    ShaderMacroX kMacros[9];
};

void* FUN_00ec61c0(void* apDst, int aiValue, unsigned int auiSize);
void FUN_00be0c00(const char* apFile, char* apPath);
int sprintf_s(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);

class SpeedTreeFrondShaderX
{
  public:
    unsigned char _pad00[0x6c];
    NiPointer<NiD3DVertexShader> m_pFrondVertexShaderVariants[4];
    NiPointer<NiD3DPixelShader> m_pFrondPixelShaderVariants[2];

    NiD3DVertexShader* FUN_00be0fe0(char* apPath, ShaderMacroX* apMacros, const char* apProfile, char* apName);
    NiD3DPixelShader* FUN_00be1750(char* apPath, ShaderMacroX* apMacros, const char* apProfile, char* apName);
    void CreateShaders();
};

// @fnv 0x00bd2730
void SpeedTreeFrondShaderX::CreateShaders()
{
    ShaderDescX kVertexShaders[4];
    ShaderDescX kPixelShaders[2];
    kVertexShaders[0].pFile = "speedtree\\frond.v.hlsl";
    kVertexShaders[0].kMacros[0].Name = 0;
    kVertexShaders[0].kMacros[0].Definition = 0;
    FUN_00ec61c0(&kVertexShaders[0].kMacros[1], 0, 0x40);
    kVertexShaders[1].pFile = "speedtree\\frond.v.hlsl";
    kVertexShaders[1].kMacros[0].Name = "FOG";
    kVertexShaders[1].kMacros[0].Definition = "";
    kVertexShaders[1].kMacros[1].Name = 0;
    kVertexShaders[1].kMacros[1].Definition = 0;
    FUN_00ec61c0(&kVertexShaders[1].kMacros[2], 0, 0x38);
    kVertexShaders[2].pFile = "speedtree\\frond.v.hlsl";
    kVertexShaders[2].kMacros[0].Name = "PT";
    kVertexShaders[2].kMacros[0].Definition = "";
    kVertexShaders[2].kMacros[1].Name = 0;
    kVertexShaders[2].kMacros[1].Definition = 0;
    FUN_00ec61c0(&kVertexShaders[2].kMacros[2], 0, 0x38);
    kVertexShaders[3].pFile = "speedtree\\frond.v.hlsl";
    kVertexShaders[3].kMacros[0].Name = "PT";
    kVertexShaders[3].kMacros[0].Definition = "";
    kVertexShaders[3].kMacros[1].Name = "FOG";
    kVertexShaders[3].kMacros[1].Definition = "";
    kVertexShaders[3].kMacros[2].Name = 0;
    kVertexShaders[3].kMacros[2].Definition = 0;
    FUN_00ec61c0(&kVertexShaders[3].kMacros[3], 0, 0x30);
    kPixelShaders[0].pFile = "speedtree\\frond.p.hlsl";
    kPixelShaders[0].kMacros[0].Name = 0;
    kPixelShaders[0].kMacros[0].Definition = 0;
    FUN_00ec61c0(&kPixelShaders[0].kMacros[1], 0, 0x40);
    kPixelShaders[1].pFile = "speedtree\\frond.p.hlsl";
    kPixelShaders[1].kMacros[0].Name = "FOG";
    kPixelShaders[1].kMacros[0].Definition = "";
    kPixelShaders[1].kMacros[1].Name = 0;
    kPixelShaders[1].kMacros[1].Definition = 0;
    FUN_00ec61c0(&kPixelShaders[1].kMacros[2], 0, 0x38);
    char acPath[260];
    char acName[260];

    for (int i = 0; i < 4; i++)
    {
        if (kVertexShaders[i].pFile)
        {
            FUN_00be0c00(kVertexShaders[i].pFile, acPath);
            sprintf_s(acName, 0x104, "STFROND%03i.vso", i);
            m_pFrondVertexShaderVariants[i] = FUN_00be0fe0(acPath, kVertexShaders[i].kMacros, "vs_1_1", acName);
        }
        else
        {
            m_pFrondVertexShaderVariants[i] = 0;
        }
    }

    const char* pPixelProfile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
    if (_fnv_particle_shader_renderer_level >= 2)
    {
        for (int i = 0; i < 2; i++)
        {
            if (kPixelShaders[i].pFile)
            {
                FUN_00be0c00(kPixelShaders[i].pFile, acPath);
                sprintf_s(acName, 0x104, "STFROND2%03i.pso", i);
                m_pFrondPixelShaderVariants[i] = FUN_00be1750(acPath, kPixelShaders[i].kMacros, pPixelProfile, acName);
            }
            else
            {
                m_pFrondPixelShaderVariants[i] = 0;
            }
        }
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            if (kPixelShaders[i].pFile)
            {
                FUN_00be0c00(kPixelShaders[i].pFile, acPath);
                sprintf_s(acName, 0x104, "STFROND%03i.pso", i);
                m_pFrondPixelShaderVariants[i] = FUN_00be1750(acPath, kPixelShaders[i].kMacros, pPixelProfile, acName);
            }
            else
            {
                m_pFrondPixelShaderVariants[i] = 0;
            }
        }
    }
}

struct DebugShaderLoader : BloodSplatterBeamShader
{
    NiD3DVertexShader* FUN_00be0fe0(char*, ShaderMacroX*, const char*, char*);
    NiD3DPixelShader* FUN_00be1750(char*, ShaderMacroX*, const char*, char*);
    void LoadDebugShaders();
};

// @fnv 0x00bd16f0
void DebugShaderLoader::LoadDebugShaders()
{
    const char* profile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
    char path[260];
    char name[260];
    ShaderDescX vertexDesc;
    vertexDesc.pFile = "imagespace\\1x\\v\\base_old.v.hlsl";
    vertexDesc.kMacros[0].Name = 0;
    vertexDesc.kMacros[0].Definition = 0;
    FUN_00ec61c0(&vertexDesc.kMacros[1], 0, 64);
    FUN_00be0c00(vertexDesc.pFile, path);
    sprintf_s(name, 260, "DEBUG.vso");
    m_spTreeVertexShader = FUN_00be0fe0(path, vertexDesc.kMacros, "vs_1_1", name);

    ShaderDescX pixelDesc;
    pixelDesc.pFile = "imagespace\\1x\\p\\copy.p.hlsl";
    pixelDesc.kMacros[0].Name = 0;
    pixelDesc.kMacros[0].Definition = 0;
    FUN_00ec61c0(&pixelDesc.kMacros[1], 0, 64);
    FUN_00be0c00(pixelDesc.pFile, path);
    sprintf_s(name, 260, "DEBUG00.pso");
    m_spPixelShaderVariants[0] = FUN_00be1750(path, pixelDesc.kMacros, profile, name);

    ShaderDescX maskedPixelDesc;
    maskedPixelDesc.pFile = "imagespace\\1x\\p\\copy.p.hlsl";
    maskedPixelDesc.kMacros[0].Name = "CHANNELMASK";
    maskedPixelDesc.kMacros[0].Definition = "";
    maskedPixelDesc.kMacros[1].Name = 0;
    FUN_00ec61c0(&maskedPixelDesc.kMacros[1].Definition, 0, 60);
    FUN_00be0c00(maskedPixelDesc.pFile, path);
    sprintf_s(name, 260, "DEBUG01.pso");
    m_spPixelShaderVariants[1] = FUN_00be1750(path, maskedPixelDesc.kMacros, profile, name);
}

struct QuadUpdate
{
    float time;
    bool updateControllers;
    bool isMultiThreaded;
    bool updateGeomorphs;
    bool updateShadow;
    bool updateCollision;
    QuadUpdate()
        : time(0.0f), updateControllers(false), isMultiThreaded(false), updateGeomorphs(false), updateShadow(false),
          updateCollision(false)
    {}
};

inline bool InsertScreenElement(NiScreenElements* geometry, int a, int b, int c)
{
    return geometry->GetData()->FUN_00a87ae0(a, b, c);
}

inline bool SetScreenElementRectangle(NiScreenElements* geometry, int a, float b, float c, float d, float e)
{
    return geometry->GetData()->SetRectangle(a, b, c, d, e);
}

inline bool SetScreenElementTexture(NiScreenElements* geometry, int a, int b, float c, float d, float e, float f)
{
    return geometry->GetData()->FUN_00a88130(a, b, c, d, e, f);
}

inline void FinishScreenElement(NiScreenElements* geometry)
{
    geometry->GetData()->NiScreenElementsData_UpdateBound();
}

struct DebugShaderInit : BloodSplatterBeamShader
{
    NiScreenElements* GetNiScreenElements() const
    {
        return m_pMenuBackgroundScreenGeometry.m_pObject;
    }
    bool FUN_00be0870();
    bool InitDebugShader();
};
extern const float DAT_011ae620;
// @fnv 0x00bd24c0
bool DebugShaderInit::InitDebugShader()
{
    bool result = FUN_00be0870();
    QuadUpdate update;
    m_pMenuBackgroundScreenGeometry = new NiScreenElements(new NiScreenElementsData(false, false, 1, 1, 1, 4, 1, 2, 1));
    InsertScreenElement(m_pMenuBackgroundScreenGeometry.m_pObject, 4, 0, 0);
    SetScreenElementRectangle(m_pMenuBackgroundScreenGeometry.m_pObject, 0, -1.0f, 1.0f, 2.0f, -2.0f);
    SetScreenElementTexture(m_pMenuBackgroundScreenGeometry.m_pObject, 0, 0, 0.0f, 0.0f, 1.0f, 1.0f);
    FinishScreenElement(m_pMenuBackgroundScreenGeometry.m_pObject);
    m_pMenuBackgroundScreenGeometry.m_pObject->UpdateProperties();
    GetNiScreenElements()->Update(&update);
    if (!m_spPixelConstantMap.m_pObject)
    {
        m_spPixelConstantMap = new NiD3DShaderConstantMap(static_cast<void*>(m_pkD3DRenderer), 2);
        m_spPixelConstantMap.m_pObject
            ->SetConstant("ChannelMask", 0x10000007, 0, 5, 1, "", 16, 4, &DAT_011ae620, 0);
    }
    return result;
}

void LoadDebugShaders();
// @fnv 0x00bd1940
// src: COMMUNITY 0x00bd1940
void DebugShader_ReloadShaders()
{
    LoadDebugShaders();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RenderResource : NiRefObject
{
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
    virtual unsigned int GetDimensionX();
    virtual unsigned int GetDimensionY();
};

struct RenderRectangle
{
    float x;
    float y;
    float width;
    float height;
};

struct RenderView
{
    void FUN_00a88020(int flags, float x, float y, float width, float height);
    void NiScreenElementsData_UpdateBound();
};

struct RenderContext : RenderResource
{
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
    RenderView* view;
    unsigned int unkbc;
    void* owner;
    RenderView* GetView()
    {
        return view;
    }
    void SetOwner(void* owner)
    {
        this->owner = owner;
    }
    void NiScreenElements_Draw(void* device);
};

struct DisplayTarget
{
    void** vtable;
    unsigned int GetWidth()
    {
        typedef unsigned int(__thiscall * Function)(DisplayTarget*, int);
        return reinterpret_cast<Function>(vtable[0x8c / 4])(this, 0);
    }
    unsigned int GetHeight()
    {
        typedef unsigned int(__thiscall * Function)(DisplayTarget*, int);
        return reinterpret_cast<Function>(vtable[0x90 / 4])(this, 0);
    }
};

struct DisplayDevice
{
    void** vtable;
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
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    unsigned int status;
    unsigned int unk204;
    unsigned char mode;
    DisplayTarget* GetScreen()
    {
        typedef DisplayTarget*(__thiscall * Function)(DisplayDevice*);
        return reinterpret_cast<Function>(vtable[0xc8 / 4])(this);
    }
    unsigned int GetStatus() const
    {
        return status;
    }
    unsigned char GetMode() const
    {
        return mode;
    }
    void PrepareFrame(RenderRectangle* bounds)
    {
        typedef void(__thiscall * Function)(DisplayDevice*, RenderRectangle*);
        reinterpret_cast<Function>(vtable[0x190 / 4])(this, bounds);
    }
};
extern "C" DisplayDevice* DAT_011f4748;
extern "C" double DAT_01011588;
extern "C" double DAT_01011598;
extern "C" double DAT_0106b168;
extern "C" double DAT_010760f0;
extern "C" float DAT_010181bc;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RenderDestination
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
    RenderResource* resource;
};

struct RenderOwner
{
    void** vtable;
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
    NiPointer<RenderResource> slots[16];
    NiPointer<RenderContext> context;
    unsigned int unkb0, unkb4, unkb8;
    unsigned int index;

    RenderResource* GetSlot(unsigned int index)
    {
        return slots[index].m_pObject;
    }
    RenderContext* GetContext()
    {
        return context.m_pObject;
    }
    unsigned int& GetIndex()
    {
        return index;
    }
    void DrawFrame(RenderContext* context)
    {
        typedef void(__thiscall * Function)(RenderOwner*, RenderContext*);
        reinterpret_cast<Function>(vtable[0x50 / 4])(this, context);
    }
    void DrawSlots(void* destination);
};

inline float Larger(float a, float b)
{
    return a > b ? a : b;
}

inline float Second(float a, float b)
{
    return a > b ? a : b;
}
// Computes a viewport from the destination or screen size, then draws each non-null slot's frame and clears it.
// @fnv 0x00bd1cf0
void RenderOwner::DrawSlots(void* destination)
{
    float width;
    float height;
    if (destination != 0)
    {
        RenderResource* resource = static_cast<RenderDestination*>(destination)->resource;
        width = (float)(resource ? resource->GetDimensionX() : 0u);
        resource = static_cast<RenderDestination*>(destination)->resource;
        height = (float)(resource ? resource->GetDimensionY() : 0u);
    }
    else
    {
        DisplayTarget* screen = DAT_011f4748->GetScreen();
        width = (float)screen->GetWidth();
        height = DAT_011f4748->GetScreen()->GetHeight();
    }

    double ratio = height / width;
    float ratioClamped = Larger(1.0f, ratio);
    float horizontal = ratio / ratioClamped;
    float vertical = 1.0f / Second(1.0f, ratio);
    RenderRectangle viewportRect = {DAT_010181bc, horizontal, vertical - 0.0500000007450580596923828125, 0.0f};

    NiPointer<RenderContext> context;
    context = this->context;
    for (GetIndex() = 0; GetIndex() < 16; ++GetIndex())
    {
        RenderResource* buffer = GetSlot(GetIndex());
        if (buffer)
        {
            float frameWidth = (float)GetSlot(GetIndex())->GetDimensionX();
            float frameHeight = (float)GetSlot(GetIndex())->GetDimensionY();
            double frameRatio = frameWidth / frameHeight;
            float frameClamp = Larger(1.0f, frameRatio);
            float fScaleX = frameRatio / frameClamp;
            float fScaleY = 1.0f / Second(1.0f, frameRatio);

            float fTileY = (float)(GetIndex() >> 2);
            float fTileX = (float)(GetIndex() & 3);
            float bx = fTileX * DAT_01011588 - 1.0f;
            float by = fTileY * DAT_01011598 + 1.0f;
            float fSizeX = fScaleX * DAT_0106b168;
            float fSizeY = fScaleY * DAT_010760f0;
            context.m_pObject->GetView()->FUN_00a88020(0, bx, by, fSizeX, fSizeY);
            context.m_pObject->GetView()->NiScreenElementsData_UpdateBound();
            context.m_pObject->SetOwner(this);
            DrawFrame(context.m_pObject);
            if ((DAT_011f4748->GetStatus() == 1 || DAT_011f4748->GetStatus() == 2) && DAT_011f4748->GetMode() == 1)
            {
                DAT_011f4748->PrepareFrame(&viewportRect);
            }
            context.m_pObject->NiScreenElements_Draw(DAT_011f4748);
            slots[GetIndex()] = 0;
            context.m_pObject->SetOwner(0);
        }
    }
}

class NiRTTIObject : public NiTexture
{
  public:
    virtual const NiRTTI* GetRTTI() const;

    bool IsKindOfType(const NiRTTI* pkRTTI) const
    {
        const NiRTTI* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->GetBaseRTTI();
        }
        return false;
    }
};

inline bool IsKindOfType(const NiRTTI* pkRTTI, NiTexture* pkObject)
{
    return pkObject && static_cast<NiRTTIObject*>(pkObject)->IsKindOfType(pkRTTI);
}

class TextureKindA : public NiRTTIObject
{
  public:
    static NiRTTI ms_kRTTI;
};

class TextureKindB : public NiRTTIObject
{
  public:
    static NiRTTI ms_kRTTI;
};

class TextureRenderer
{
  public:
    virtual ~TextureRenderer();
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
    NiPointer<NiTexture> m_aspTextures[16];

    void AddTexture(NiTexture* pkTexture);
};

// Finds a free slot in m_aspTextures and stores pkTexture there if it is a TextureKindA or TextureKindB.
// @fnv 0x00bd22c0
void TextureRenderer::AddTexture(NiTexture* pkTexture)
{
    int iSlot = -1;
    for (unsigned int i = 0; i < 16 && iSlot == -1; i++)
    {
        if (!m_aspTextures[i].m_pObject)
            iSlot = i;
    }

    if (iSlot == -1)
        return;

    if (IsKindOfType(&TextureKindA::ms_kRTTI, pkTexture))
        m_aspTextures[iSlot] = pkTexture;
    else if (IsKindOfType(&TextureKindB::ms_kRTTI, pkTexture))
        m_aspTextures[iSlot] = pkTexture;
}
