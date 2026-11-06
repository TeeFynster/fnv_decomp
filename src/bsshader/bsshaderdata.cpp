
// src/bsshader/bsshaderdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/bsshaderdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BSShader.h"
#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DVertexShader.h"

struct BSMaterialEmittanceMultController;
struct BSRefractionFirePeriodController;
struct BSRefractionStrengthController;
struct BSShaderNoLightingProperty;
struct BSShaderPPLightingProperty;
struct BSShaderTextureSet;
struct NiAlphaController;
struct NiMaterialColorController;
struct SkyShaderProperty;
struct TallGrassShaderProperty;
struct TileShaderProperty;
struct VolumetricFogShaderProperty;
struct ShaderPropertyConversionData
{
    void Convert(NiAVObject*, unsigned int);
    void CheckTextureAlphas();
    void AddShaderProperty(NiAVObject*);
    void AddMaterialProperty(NiAVObject*);
    void AddAlphaProperty(NiAVObject*);
    BSShaderProperty* GetShaderProperty();
    void SetupShaderFlags(BSShaderProperty*, NiAVObject*);
    void SetupTexturesPPLightingShader(BSShaderPPLightingProperty*);
    void SetupDataPPLightingShader(BSShaderPPLightingProperty*);
    void SetupTexturesNoLightingShader(BSShaderNoLightingProperty*);
    void SetupDataVolumetricFogShader(VolumetricFogShaderProperty*);
    void SetupTexturesTallGrassShader(TallGrassShaderProperty*);
    void SetupTexturesSkyShader(SkyShaderProperty*);
    void SetupDataSkyShader(SkyShaderProperty*);
    void SetupTexturesTileShader(TileShaderProperty*);
    bool IsValidProperty(NiAVObject*, BSShaderProperty*);
    int m_iShaderType;
    char m_kAmbientColor[12];
    char m_kDiffuseColor[12];
    float m_fShininess;
    float fAlpha;
    float m_fEmittanceMultiplier;
    NiMaterialColorController* m_pAmbientColorController;
    NiMaterialColorController* m_pDiffuseColorController;
    NiAlphaController* m_pAlphaController;
    BSMaterialEmittanceMultController* m_pEmittanceMultiplierController;
    bool m_bHasMaterialProperty;
    char _pad_39[3];
    int m_iShaderFlags1;
    int m_iShaderFlags2;
    bool m_bHasAlphaProperty;
    char _pad_45[3];
    int m_iShaderOption;
    unsigned char m_uiShaderOptionByte;
    bool m_bShaderFeature1;
    bool m_bShaderFeature2;
    bool m_bShaderFeature3;
    bool m_bShaderFeature4;
    bool m_bShaderFeature5;
    bool m_bShaderFeature6;
    bool m_bShaderFeatureActive;
    bool m_bShaderFeature8;
    bool m_bShaderFeature9;
    bool m_bShaderFeature10;
    bool m_bShaderFeature11;
    float m_fValueBeforeTextureCount;
    bool m_bShaderFeature12;
    char _pad_5d[3];
    int m_iTextureCount;
    BSRefractionStrengthController* m_pRefractionStrengthController;
    BSRefractionFirePeriodController* m_pRefractionFirePeriodController;
    bool m_bShaderFeature13;
    bool m_bShaderFeature14;
    char _pad_6e[2];
    float m_fRefractionStrength;
    float m_fRefractionFirePeriod;
    char m_kSpecularColor[12];
    float m_fShaderParameter1;
    bool m_bShaderFeature15;
    bool m_bShaderFeature16;
    bool m_bShaderFeature17;
    char _pad_8b[1];
    float m_fShaderParameter2;
    int m_iShaderOptionIndex;
    bool m_bShaderFeature18;
    char _pad_95[3];
    char m_kEmissiveColor[16];
    BSShaderTextureSet* m_pTextureSet;
    char m_cTrailingBytes[7];
    char _pad_b3[1];
    int m_iShaderDataFlags;
};
typedef char _sizecheck_BSShaderData[sizeof(ShaderPropertyConversionData) == 184 ? 1 : -1];
struct FUN_00bb0180_shell : public ShaderPropertyConversionData
{
    void AddProperties(NiAVObject*, unsigned int);
};

// Adds an alpha, material and/or shader property to apTarget according to the bits set in auiProperties.
// @fnv 0x00bb0180
void FUN_00bb0180_shell::AddProperties(NiAVObject* apTarget, unsigned int auiProperties)
{
    if (auiProperties & 1)
        AddAlphaProperty(apTarget);
    if (auiProperties & 2)
        AddMaterialProperty(apTarget);
    if (auiProperties & 4)
        AddShaderProperty(apTarget);
}

extern int DAT_012005e0;

// The unused EDX parameter preserves the original ECX-based member entry convention.
// @fnv 0x00bb0490
void __fastcall ClearPrecipitationTextureStages(BSShader* shader, void*)
{
    shader->ClearTextureStages(reinterpret_cast<NiD3DPass*>(DAT_012005e0));
}

#include "../../include/_D3DXMACRO.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
inline void NiD3DPixelShader::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<long volatile*>(&m_uiRefCount));
}

inline void NiD3DPixelShader::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
template <class T> struct ShaderPtr
{
    T* m_pObject;
    ShaderPtr& operator=(T* pObject)
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
extern ShaderPtr<NiD3DPixelShader> DAT_012005c8[2];
void* _fnv_zlib_memset(void*, int, unsigned int);
int _sprintf_s(char*, unsigned int, const char*, ...);
struct PrecipShaderDef
{
    const char* pFile;
    _D3DXMACRO Macros[9];
};

// @fnv 0x00bb0360
void __fastcall CreatePrecipitationPixelShaders(BSShader* shader, void*)
{
    PrecipShaderDef ShaderDefs[2];
    ShaderDefs[0].pFile = "precipitation\\precipitation.p.hlsl";
    ShaderDefs[0].Macros[0].Name = 0;
    _fnv_zlib_memset(&ShaderDefs[0].Macros[0].Definition, 0, 0x44);
    ShaderDefs[1].pFile = "precipitation\\precipitation.p.hlsl";
    ShaderDefs[1].Macros[0].Name = "SNOW";
    ShaderDefs[1].Macros[0].Definition = 0;
    ShaderDefs[1].Macros[1].Name = 0;
    _fnv_zlib_memset(&ShaderDefs[1].Macros[1].Definition, 0, 0x3c);
    char acName[260];
    char acPath[260];
    for (int i = 0; i < 2; i++)
    {
        BSShader::GetShaderPath(ShaderDefs[i].pFile, acPath);
        _sprintf_s(acName, 260, "PRECIP%03i.pso", i);
        DAT_012005c8[i] = shader->CompilePixelShader(acPath, ShaderDefs[i].Macros,
                                             NiD3DGPUProgramCache::GetPixelShaderProfile(false), acName);
    }
}

inline void NiD3DVertexShader::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<long volatile*>(&m_uiRefCount));
}

inline void NiD3DVertexShader::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
extern ShaderPtr<NiD3DVertexShader> DAT_012005d0[4];
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

// @fnv 0x00bb01c0
void __fastcall CreatePrecipitationVertexShaders(BSShader* shader, void*)
{
    PrecipShaderDef shaderDefs[4];
    shaderDefs[0].pFile = "precipitation\\precipitation.v.hlsl";
    shaderDefs[0].Macros[0].Name = "BILLBOARD_UP";
    shaderDefs[0].Macros[0].Definition = 0;
    shaderDefs[0].Macros[1].Name = 0;
    fnv_zlib_memset(&shaderDefs[0].Macros[1].Definition, 0, 0x3c);
    shaderDefs[1].pFile = "precipitation\\precipitation.v.hlsl";
    shaderDefs[1].Macros[0].Name = "BILLBOARD_FACE";
    shaderDefs[1].Macros[0].Definition = 0;
    shaderDefs[1].Macros[1].Name = 0;
    fnv_zlib_memset(&shaderDefs[1].Macros[1].Definition, 0, 0x3c);
    shaderDefs[2].pFile = "precipitation\\precipitation.v.hlsl";
    shaderDefs[2].Macros[0].Name = "BILLBOARD_UP";
    shaderDefs[2].Macros[0].Definition = 0;
    shaderDefs[2].Macros[1].Name = "SNOW";
    shaderDefs[2].Macros[1].Definition = 0;
    shaderDefs[2].Macros[2].Name = 0;
    fnv_zlib_memset(&shaderDefs[2].Macros[2].Definition, 0, 0x34);
    shaderDefs[3].pFile = "precipitation\\precipitation.v.hlsl";
    shaderDefs[3].Macros[0].Name = "BILLBOARD_FACE";
    shaderDefs[3].Macros[0].Definition = 0;
    shaderDefs[3].Macros[1].Name = "SNOW";
    shaderDefs[3].Macros[1].Definition = 0;
    shaderDefs[3].Macros[2].Name = 0;
    fnv_zlib_memset(&shaderDefs[3].Macros[2].Definition, 0, 0x34);
    for (int i = 0; i < 4; i++)
    {
        char shaderName[260];
        char shaderPath[260];
        BSShader::GetShaderPath(shaderDefs[i].pFile, shaderPath);
        _sprintf_s(shaderName, 260, "PRECIP%03i.vso", i);
        DAT_012005d0[i] =
            shader->CompileVertexShader(shaderPath, shaderDefs[i].Macros, NiD3DGPUProgramCache::GetVertexShaderProfile(), shaderName);
    }
}
