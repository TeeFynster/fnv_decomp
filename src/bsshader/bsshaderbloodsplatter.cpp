// bsshader/bsshaderbloodsplatter.cpp: BloodSplatterShaderLocal_00b80d30, BloodShader (17 functions)

#include "../../include/BSShader.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiShader.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiShaderDeclaration.h"
#include "../../include/NiAVObject.h"
#include "../../include/BSShaderManager.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiTransform.h"
#include "../../include/NiBound.h"
#include "../../include/NiDX9Renderer.h"

namespace fnv_00b80c20 { struct RenderInput; }

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
inline void NiD3DVertexShader::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiD3DVertexShader::DecRefCount() { NiRefObject::DecRefCount(); }
inline void NiD3DPixelShader::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiD3DPixelShader::DecRefCount() { NiRefObject::DecRefCount(); }
inline void NiD3DShaderConstantMap::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiD3DShaderConstantMap::DecRefCount() { NiRefObject::DecRefCount(); }


// Retain this definition: the approved shared header lacks the BSShader base and virtual destructor.
// local form of BSShaderBloodSplatter: 0x00b80d30 needs the BSShader base, virtual destructor and unit render-input call surfaces absent from the shared header.
class BloodSplatterShaderLocal_00b80d30 : public BSShader
{
  public:
    NiPointer<NiD3DPass> spRenderPass[2];                    // +0x6C, 8 bytes
    NiPointer<NiD3DVertexShader> m_spTreeVertexShader[2];    // +0x74, 8 bytes
    NiPointer<NiD3DPixelShader> m_spPixelShaderVariants[2];  // +0x7C, 8 bytes
    BloodSplatterShaderLocal_00b80d30();
    static void* __cdecl operator new(unsigned int size);
    BSShader* CreateShader();
    void InitializeShaderData();
    bool ConfigureShaderPass();
    void BSShaderBloodSplatterProperty_SetClampD3D(unsigned int);
    void BSShaderBloodSplatter_InitPass(unsigned int);
    void NiD3DPass_SetPixelShader(NiRefObject*);
    void SetupConstantMaps();
    virtual ~BloodSplatterShaderLocal_00b80d30();
    int ImageSpaceShader_GetShaderDeclaration(void*, void*);
    void X_Shader_ClearPassStages();
    bool BSShaderBloodSplatter_ReloadShaders();
    void* FUN_00b80e40(unsigned int);
    void CreateShaderConstantMaps();
    void InitPassItems(struct FUN_00b80b30_arg*);
    void ApplyBloodShader(fnv_00b80c20::RenderInput*);
};

class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
public:
    void* m_pkVertexElements;
    void* m_pkD3DVertexDeclaration;
    static NiD3DVertexDeclaration* Create(GraphicsRenderer*, unsigned int, unsigned int);
};

extern GraphicsRenderer* g_pkRenderer;
extern float g_splatterDefaultFirst;
extern float g_splatterDefaultSecond;
extern float g_splatterValueA;
extern char g_splatterWhiteFlashPath[];
extern char g_splatterWhiteFlashTexture;

struct SplatterFloat4
{
    float x;
    float y;
    float z;
    float w;
};

// @fnv 0x00b80e70
BSShader* BloodSplatterShaderLocal_00b80d30::CreateShader()
{
    NiD3DVertexDeclaration* declaration = NiD3DVertexDeclaration::Create(g_pkRenderer, 2, 1);
    typedef void(__thiscall * Method5)(void*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    typedef void(__thiscall * Method0)(void*);
    reinterpret_cast<Method5>((*reinterpret_cast<void***>(declaration))[35])(declaration, 0, 0, 0, 2, 0);
    reinterpret_cast<Method5>((*reinterpret_cast<void***>(declaration))[35])(declaration, 1, 7, 5, 1, 0);
    reinterpret_cast<Method0>((*reinterpret_cast<void***>(declaration))[45])(declaration);

    BloodSplatterShaderLocal_00b80d30* shader = new BloodSplatterShaderLocal_00b80d30;
    shader->Initialize();
    shader->InitializeShaderData();
    shader->ConfigureShaderPass();
    // The approved BSShader header does not declare slot 71 yet.
    reinterpret_cast<Method0>((*reinterpret_cast<void***>(shader))[71])(shader);
    shader->UseShaderDeclaration(declaration);
    return shader;
}

// @fnv 0x00b80d30
BloodSplatterShaderLocal_00b80d30::BloodSplatterShaderLocal_00b80d30() : BSShader()
{
    SplatterFloat4 values = {g_splatterDefaultFirst, g_splatterDefaultFirst, 0.0f, g_splatterDefaultSecond};
    iShaderType = 0x17;
    *reinterpret_cast<SplatterFloat4*>(&g_splatterValueA) = values;
    BSShaderManager::GetTexture(g_splatterWhiteFlashPath, true,
                                *reinterpret_cast<NiPointer<NiTexture>*>(&g_splatterWhiteFlashTexture), true, false);
}

// Preserve the inlined reference operations used by this unit.
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        T* old = m_pObject;
        if (old != 0)
            old->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

class BeamStage
{
  public:
    unsigned char layoutPrefix[8];
    unsigned int m_uiTexture;
    unsigned char layoutStage[0x54];
    unsigned int m_uiRefCount;
    void ApplyPairToState(void*);
    void NiD3DTextureStage_SetFilterMode(unsigned int);
    void ReturnToPool();
    void DecRefCount()
    {
        --m_uiRefCount;
        if (m_uiRefCount == 0)
            ReturnToPool();
    }
    static void CreateNewStage(NiPointer<BeamStage>&);
};
template <> inline NiPointer<BeamStage>::NiPointer() : m_pObject(0)
{}
template <> inline NiPointer<BeamStage>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <> inline BeamStage* NiPointer<BeamStage>::operator->() const
{
    return m_pObject;
}
template <> inline NiPointer<BeamStage>::operator BeamStage*() const
{
    return m_pObject;
}

class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int, unsigned int, bool);
};
// The shared header has no indexed stage setter yet.
extern void SetD3DPassStage();
inline void NiD3DPass::AppendStage(BeamStage* stage)
{
    typedef void(__thiscall * SetStage)(NiD3DPass*, unsigned int, BeamStage*);
    reinterpret_cast<SetStage>(&SetD3DPassStage)(this, m_uiCurrentStage, stage);
}
inline void NiD3DPass::Release()
{
    --m_uiRefCount;
    if (!m_uiRefCount)
        DestroyPass();
}
inline void NiD3DPass::SetRenderState(unsigned int state, unsigned int value, bool save)
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    m_pkRenderStateGroup->SetRenderState(state, value, save);
}
inline void NiD3DPass::SetVertexShader(NiD3DVertexShader* shader)
{
    m_spVertexShader = shader;
}
inline void NiD3DPass::SetPixelShader(NiD3DPixelShader* shader)
{
    m_spPixelShader = shader;
}

void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);
#include "../../include/_D3DXMACRO.h"
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern NiD3DPass* DAT_0126f74c;

// Configures two NiD3DPass objects with two texture stages each, render states, vertex and pixel shaders, and returns true.
// @fnv 0x00b807d0
bool BloodSplatterShaderLocal_00b80d30::ConfigureShaderPass()
{
    NiD3DPass::CreateD3DPass(spRenderPass[0]);
    for (unsigned int i = 0; i < 2; ++i)
    {
        NiPointer<BeamStage> stage;
        BeamStage::CreateNewStage(stage);
        ConfigureBeamStage(stage, i, 3, 2, true);
        stage->NiD3DTextureStage_SetFilterMode(1);
        spRenderPass[0].m_pObject->AppendStage(stage);
    }
    spRenderPass[0].m_pObject->SetRenderState(27, 1, true);
    spRenderPass[0].m_pObject->SetRenderState(7, 0, true);
    spRenderPass[0].m_pObject->SetRenderState(14, 0, true);
    {
        NiD3DPass* pass = spRenderPass[0].m_pObject;
        pass->SetRenderState(19, 1, true);
        pass->SetRenderState(20, 3, true);
    }
    spRenderPass[0].m_pObject->SetVertexShader(m_spTreeVertexShader[0].m_pObject);
    spRenderPass[0].m_pObject->SetPixelShader(m_spPixelShaderVariants[0].m_pObject);
    NiD3DPass::CreateD3DPass(spRenderPass[1]);
    for (unsigned int i = 0; i < 2; ++i)
    {
        NiPointer<BeamStage> stage;
        BeamStage::CreateNewStage(stage);
        ConfigureBeamStage(stage, i, 3, 2, true);
        stage->NiD3DTextureStage_SetFilterMode(1);
        spRenderPass[1].m_pObject->AppendStage(stage);
    }
    spRenderPass[1].m_pObject->SetRenderState(27, 1, true);
    spRenderPass[1].m_pObject->SetRenderState(7, 0, true);
    spRenderPass[1].m_pObject->SetRenderState(14, 0, true);
    {
        NiD3DPass* pass = spRenderPass[1].m_pObject;
        pass->SetRenderState(19, 2, true);
        pass->SetRenderState(20, 2, true);
    }
    spRenderPass[1].m_pObject->SetVertexShader(m_spTreeVertexShader[1].m_pObject);
    spRenderPass[1].m_pObject->SetPixelShader(m_spPixelShaderVariants[1].m_pObject);
    return true;
}

struct SplatterShaderInfo
{
    const char* file;
    _D3DXMACRO macros[9];
};
// @fnv 0x00b80090
void BloodSplatterShaderLocal_00b80d30::InitializeShaderData()
{
    SplatterShaderInfo vertex;
    vertex.file = "BloodSplatter\\BloodSplatter.v.hlsl";
    vertex.macros[0].Name = 0;
    fnv_zlib_memset(&vertex.macros[0].Definition, 0, 68);
    SplatterShaderInfo pixel;
    pixel.file = "BloodSplatter\\BloodSplatter.p.hlsl";
    pixel.macros[0].Name = 0;
    fnv_zlib_memset(&pixel.macros[0].Definition, 0, 68);
    SplatterShaderInfo flareVertexShader;
    flareVertexShader.file = "BloodSplatter\\BloodSplatter.v.hlsl";
    flareVertexShader.macros[0].Name = "FLARE";
    flareVertexShader.macros[0].Definition = "";
    flareVertexShader.macros[1].Name = 0;
    fnv_zlib_memset(&flareVertexShader.macros[1].Definition, 0, 60);
    SplatterShaderInfo flarePixelShader;
    flarePixelShader.file = "BloodSplatter\\BloodSplatter.p.hlsl";
    flarePixelShader.macros[0].Name = "FLARE";
    flarePixelShader.macros[0].Definition = "";
    flarePixelShader.macros[1].Name = 0;
    fnv_zlib_memset(&flarePixelShader.macros[1].Definition, 0, 60);
    char shaderPath[260];
    char outputFile[260];
    GetShaderPath(vertex.file, shaderPath);
    sprintf_s(outputFile, 260, "BS.vso");
    m_spTreeVertexShader[0] = CompileVertexShader(shaderPath, vertex.macros, "vs_1_1", outputFile);
    GetShaderPath(flareVertexShader.file, shaderPath);
    sprintf_s(outputFile, 260, "BSF.vso");
    m_spTreeVertexShader[1] = CompileVertexShader(shaderPath, flareVertexShader.macros, "vs_1_1", outputFile);
    GetShaderPath(pixel.file, shaderPath);
    sprintf_s(outputFile, 260, "BS.pso");
    m_spPixelShaderVariants[0] = CompilePixelShader(shaderPath, pixel.macros, "ps_2_a", outputFile);
    GetShaderPath(flarePixelShader.file, shaderPath);
    sprintf_s(outputFile, 260, "BSF.pso");
    m_spPixelShaderVariants[1] = CompilePixelShader(shaderPath, flarePixelShader.macros, "ps_2_a", outputFile);
}

// @fnv 0x00b81110
// src: XBOX_PDB 0x00b81110
void BloodSplatterShaderLocal_00b80d30::BSShaderBloodSplatterProperty_SetClampD3D(unsigned int value)
{
    iShaderType = (value != 3) ? 3 : 0;
}

// @fnv 0x00b805d0
// src: COMMUNITY 0x00b805d0
void BloodSplatterShaderLocal_00b80d30::BSShaderBloodSplatter_InitPass(unsigned int pass)
{
    switch (pass)
    {
    case 0x2f0:
        DAT_0126f74c = spRenderPass[1].m_pObject;
        break;
    case 0x2f1:
        DAT_0126f74c = spRenderPass[0].m_pObject;
        break;
    }
}

// Assigns value to the NiRefObject pointer at offset 0x44, releasing the old reference and incrementing the new one's ref count.
// @fnv 0x00b80600
// src: COMMUNITY 0x00b80600
void BloodSplatterShaderLocal_00b80d30::NiD3DPass_SetPixelShader(NiRefObject* value)
{
    NiRefObject** ppSlot = reinterpret_cast<NiRefObject**>(&m_uiRemainingStages);
    NiRefObject* old = *ppSlot;
    if (old != value)
    {
        if (old && InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            reinterpret_cast<void(__thiscall*)(void*)>((*reinterpret_cast<void***>(old))[1])(old);
        *ppSlot = value;
        if (value)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&value->m_uiRefCount));
    }
}

// @fnv 0x00b807c0
// src: COMMUNITY 0x00b807c0
int __thiscall BloodSplatterShaderLocal_00b80d30::ImageSpaceShader_GetShaderDeclaration(void* a, void* b)
{
    return reinterpret_cast<int>(m_spShaderDecl.m_pObject);
}

extern int g_011fedc8;

// @fnv 0x00b807b0
// src: COMMUNITY 0x00b807b0
int* __cdecl BSShaderBloodSplatter_GetRTTI()
{
    return &g_011fedc8;
}

// Clears the texture stages in both shader passes.
// @fnv 0x00b80380
// src: COMMUNITY 0x00b80380
void BloodSplatterShaderLocal_00b80d30::X_Shader_ClearPassStages()
{
    NiPointer<NiD3DPass>* p = spRenderPass;
    int n = 2;
    do
    {
        NiD3DPass* pass = p->m_pObject;
        // The approved BSShader header does not declare slot 74 yet.
        reinterpret_cast<void(__thiscall*)(void*, NiD3DPass*)>(
            (*reinterpret_cast<void***>(this))[74])(this, pass);
        ++p;
    } while (--n != 0);
}

// @fnv 0x00b80b20
// src: COMMUNITY 0x00b80b20
bool BloodSplatterShaderLocal_00b80d30::BSShaderBloodSplatter_ReloadShaders()
{
    InitializeShaderData();
    return ConfigureShaderPass();
}

void __cdecl _delete(void*, unsigned int);
// Destroys the shader and releases its allocation when bit 0 of the flags is set.
// @fnv 0x00b80e40
void* __thiscall BloodSplatterShaderLocal_00b80d30::FUN_00b80e40(unsigned int auiFlags)
{
    this->BloodSplatterShaderLocal_00b80d30::~BloodSplatterShaderLocal_00b80d30();
    if (auiFlags & 1)
        _delete(this, 0x84);
    return this;
}

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
inline float NiPoint3::operator*(const NiPoint3& kV) const
{
    return x * kV.x + y * kV.y + z * kV.z;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kV) const
{
    return NiPoint3(x - kV.x, y - kV.y, z - kV.z);
}

struct Picker_00b803b0
{
    bool ShadowSceneNode_GetAverageLightPos(const NiPoint3& akStart, const NiPoint3& kWorldPosition, NiPoint3& kHit);
};
extern Picker_00b803b0* DAT_011f91c8;
extern float DAT_011fed90;
extern SplatterFloat4 DAT_011fed94;

struct Camera_00b803b0
{
    char pad00[0x68];
    float m00;  // +0x68
    float m01, m02;
    float m10;  // +0x74
    float m11, m12;
    float m20;  // +0x80
    float m21, m22;
    NiPoint3 m_kWorldTranslate;  // +0x8c
    bool ProjectPointToScreen(const NiPoint3& kPt, float& fX, float& fY, float& fZ, float fZeroTolerance);
};

// @fnv 0x00b803b0
// src: COMMUNITY 0x00b803b0
void __cdecl BSShaderBloodSplatter_ComputeScreenSpaceLightLoc(Camera_00b803b0* pkCamera)
{
    DAT_011fed90 = 0.0f;
    NiPoint3 kHit;
    if (DAT_011f91c8->ShadowSceneNode_GetAverageLightPos(pkCamera->m_kWorldTranslate, NiPoint3(pkCamera->m00, pkCamera->m10, pkCamera->m20),
                                   kHit))
    {
        NiPoint3 kWorldPosition(pkCamera->m00, pkCamera->m10, pkCamera->m20);
        NiPoint3 kDelta = kHit - pkCamera->m_kWorldTranslate;
        kWorldPosition.ComputeMagnitude();
        kDelta.ComputeMagnitude();
        DAT_011fed90 = kDelta * kWorldPosition;
        float fX, fY, fZ;
        if (pkCamera->ProjectPointToScreen(kHit, fX, fY, fZ, 1e-05f))
        {
            if (fX < 0.0f)
                fX = 0.0f;
            else if (fX > 1.0f)
                fX = 1.0f;
            if (fY < 0.0f)
                fY = 0.0f;
            else if (fY > 1.0f)
                fY = 1.0f;
            SplatterFloat4 kResult;
            kResult.x = fX * 2.0 - 1.0f;
            kResult.y = 2.0 * fY - 1.0f;
            kResult.z = fZ;
            kResult.w = 0.1f;
            DAT_011fed94 = kResult;
        }
        else
        {
            SplatterFloat4 kResult;
            kResult.x = 0.0f;
            kResult.y = 0.0f;
            kResult.z = 0.0f;
            kResult.w = 0.1f;
            DAT_011fed94 = kResult;
        }
    }
    else
    {
        SplatterFloat4 kResult;
        kResult.x = 0.0f;
        kResult.y = 0.0f;
        kResult.z = 0.0f;
        kResult.w = 0.1f;
        DAT_011fed94 = kResult;
    }
}

extern char $SG3295[];
extern char _DAT_010A1E50[];
extern int DAT_011fedb4;
extern float DAT_011feda4;

// Lazily creates the two NiD3DShaderConstantMap objects stored at offsets 0x30 and 0x34 and registers their shader constant entries.
// @fnv 0x00b80f50
void BloodSplatterShaderLocal_00b80d30::CreateShaderConstantMaps()
{
    NiPointer<NiD3DShaderConstantMap>& pAlphaMap = m_spPixelConstantMap;
    NiPointer<NiD3DShaderConstantMap>& m_pVertexShaderConstantMap = m_spVertexConstantMap;
    if (!pAlphaMap.m_pObject)
    {
        pAlphaMap = new NiD3DShaderConstantMap(static_cast<void*>(m_pkD3DRenderer), 2);
        pAlphaMap.m_pObject->SetConstant("alpha", 0x10000007, 0, 0, 1, $SG3295, 0x10, 4, &DAT_011fedb4, false);
    }
    if (!m_pVertexShaderConstantMap.m_pObject)
    {
        m_pVertexShaderConstantMap = new NiD3DShaderConstantMap(static_cast<void*>(m_pkD3DRenderer), 0);
        m_pVertexShaderConstantMap.m_pObject->SetConstant(_DAT_010A1E50, 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        m_pVertexShaderConstantMap.m_pObject->SetConstant("lightloc", 0x10000007, 0, 4, 1, $SG3295, 0x10, 4, &g_splatterValueA,
                                             false);
        m_pVertexShaderConstantMap.m_pObject->SetConstant("ctrl", 0x10000007, 0, 5, 1, $SG3295, 0x10, 4, &DAT_011feda4, false);
    }
}

// Releases the two pass, vertex-shader and pixel-shader references and the white-flash texture, clearing each pointer.
// @fnv 0x00b80650
BloodSplatterShaderLocal_00b80d30::~BloodSplatterShaderLocal_00b80d30()
{
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (spRenderPass[i].m_pObject)
        {
            spRenderPass[i].m_pObject->Release();
            spRenderPass[i].m_pObject = 0;
        }
    }
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (m_spTreeVertexShader[i].m_pObject)
        {
            m_spTreeVertexShader[i].m_pObject->NiRefObject::DecRefCount();
            m_spTreeVertexShader[i].m_pObject = 0;
        }
    }
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (m_spPixelShaderVariants[i].m_pObject)
        {
            m_spPixelShaderVariants[i].m_pObject->NiRefObject::DecRefCount();
            m_spPixelShaderVariants[i].m_pObject = 0;
        }
    }
    if (*(NiRefObject**)&g_splatterWhiteFlashTexture)
    {
        (*(NiRefObject**)&g_splatterWhiteFlashTexture)->DecRefCount();
        *(NiRefObject**)&g_splatterWhiteFlashTexture = 0;
    }
}

struct FUN_00b80b30_sub
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void* v51();
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
    int m_arr60[2];
};

struct FUN_00b80b30_arg
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00b80b30_sub* m_pSub;
};

struct FUN_00b80b30_mgr
{
    void* ImageSpaceTexture_GetTexture();
};

extern FUN_00b80b30_mgr DAT_012005a4;
extern int DAT_011f91e4;
extern int DAT_011fedc4;

// Updates the pass texture stages and configures them for the current render pass.
// @fnv 0x00b80b30
void BloodSplatterShaderLocal_00b80d30::InitPassItems(FUN_00b80b30_arg* apArg)
{
    FUN_00b80b30_sub* sub = apArg->m_pSub;
    if (DAT_011f91e4 == 0x2f1)
    {
        NiD3DPass* pass = spRenderPass[0].m_pObject;
        for (unsigned int i = 0; i < 2; i++)
        {
            BeamStage* item = pass->m_kStages.m_pBase[i].m_pObject;
            item->m_uiTexture = sub->m_arr60[i];
            void* value = sub->v51();
            item->ApplyPairToState(value);
        }
    }
    else if (DAT_011f91e4 == 0x2f0)
    {
        NiD3DPass* pass = spRenderPass[1].m_pObject;
        BeamStage* pFirstItem = pass->m_kStages.m_pBase[0].m_pObject;
        pFirstItem->m_uiTexture = sub->m_arr60[0];
        void* value0 = sub->v51();
        pFirstItem->ApplyPairToState(value0);
        BeamStage* pSecondItem = pass->m_kStages.m_pBase[1].m_pObject;
        if (DAT_012005a4.ImageSpaceTexture_GetTexture())
        {
            pSecondItem->m_uiTexture = (unsigned int)DAT_012005a4.ImageSpaceTexture_GetTexture();
        }
        else
        {
            pSecondItem->m_uiTexture = DAT_011fedc4;
        }
        void* value1 = sub->v51();
        pSecondItem->ApplyPairToState(value1);
    }
    // The approved BSShader header does not declare slot 66 yet.
    reinterpret_cast<void(__thiscall*)(void*)>((*reinterpret_cast<void***>(this))[66])(this);
}

namespace fnv_00b80c20 {
extern NiBound DAT_011f4288;
extern unsigned int DAT_011f91e4;
extern float DAT_011ad874, DAT_011ad878;
extern NiGeometry** DAT_011f91e0;
// 0x00e6fbb0 is ApplyObjectTransform; the shared renderer header lacks this method.
extern void ApplyRendererObjectTransform();
struct EffectObject
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
    float scale;
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
    float* value;
};
struct RenderInput
{
    unsigned int unk00, unk04, unk08;
    EffectObject* object;
};
}  // namespace fnv_00b80c20

// Computes a scaled value from the render input's object, applies the pixel and vertex constant maps to the current geometry with the bound and transform.
// @fnv 0x00b80c20
void BloodSplatterShaderLocal_00b80d30::ApplyBloodShader(fnv_00b80c20::RenderInput* input)
{
    using namespace fnv_00b80c20;
    NiGeometry* geom = *DAT_011f91e0;
    NiTransform* transform = &geom->m_kWorld;
    NiBound* bound = reinterpret_cast<NiBound*>(geom->m_kWorldBound);
    if (!bound)
        bound = &DAT_011f4288;
    NiGeometryBufferData* data = static_cast<NiGeometryBufferData*>(geom->m_spModelData.m_pObject->m_pkBuffData);
    NiSkinInstance* properties = geom->m_spSkinInstance.m_pObject;
    typedef void(__thiscall* ApplyObjectTransform)(NiDX9Renderer*, const NiTransform&, bool);
    reinterpret_cast<ApplyObjectTransform>(&ApplyRendererObjectTransform)(
        reinterpret_cast<NiDX9Renderer*>(m_pkD3DRenderer), *transform, false);
    float value = *input->object->value * input->object->scale;
    *(float*)&DAT_011fedb4 = value * DAT_011ad878;
    if (fnv_00b80c20::DAT_011f91e4 == 0x2f0)
        *(float*)&DAT_011fedb4 = DAT_011fed90 * DAT_011ad874 * *(float*)&DAT_011fedb4;
    NiD3DShaderConstantMap* map = m_spPixelConstantMap.m_pObject;
    if (map)
    {
        NiD3DPixelShader* shader = DAT_0126f74c->m_spPixelShader.m_pObject;
        if (shader)
            map->ConfigureShaderConstantMap(shader, geom, properties,
                static_cast<const NiSkinPartition::Partition*>(0), data,
                reinterpret_cast<const NiPropertyState*>(input), static_cast<const NiDynamicEffectState*>(0),
                *transform, *bound, 0, true);
    }
    map = m_spVertexConstantMap.m_pObject;
    if (map)
    {
        NiD3DVertexShader* shader = DAT_0126f74c->m_spVertexShader.m_pObject;
        if (shader)
            map->ConfigureShaderConstantMap(shader, geom, properties,
                static_cast<const NiSkinPartition::Partition*>(0), data,
                reinterpret_cast<const NiPropertyState*>(input), static_cast<const NiDynamicEffectState*>(0),
                *transform, *bound, 0, true);
    }
}
