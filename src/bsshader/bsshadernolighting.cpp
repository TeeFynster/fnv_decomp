// bsshader/bsshadernolighting.cpp: BSShaderNoLighting, ShaderDispatcher, LightingShader, TechniqueShader and more (21 functions)
#include "NiRefObject_inline.h"

#include "bsshadernolighting_local.h"
#include "../../include/NiColor.h"

inline NiTransform::NiTransform()
{}

inline const NiTransform& NiGeometry::GetWorldTransform() const
{
    return m_kWorld;
}

inline NiColorA::NiColorA(float red, float green, float blue, float alpha)
    : r(red), g(green), b(blue), a(alpha)
{}

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

template <> __forceinline NiPointer<NiD3DPass>& NiPointer<NiD3DPass>::operator=(NiD3DPass* value)
{
    if (m_pObject != value)
    {
        if (m_pObject && --m_pObject->m_uiRefCount == 0)
            m_pObject->FUN_00e80190();
        m_pObject = value;
        if (m_pObject)
            ++m_pObject->m_uiRefCount;
    }
    return *this;
}
template <> __forceinline NiPointer<NiD3DVertexShader>& NiPointer<NiD3DVertexShader>::operator=(NiD3DVertexShader* value)
{
    NiD3DVertexShader* old = m_pObject;
    if (old != value)
    {
        if (old && InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            old->DeleteThis();
        m_pObject = value;
        if (value)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&value->m_uiRefCount));
    }
    return *this;
}
template <> __forceinline NiPointer<NiD3DPixelShader>& NiPointer<NiD3DPixelShader>::operator=(NiD3DPixelShader* value)
{
    NiD3DPixelShader* old = m_pObject;
    if (old != value)
    {
        if (old && InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            old->DeleteThis();
        m_pObject = value;
        if (value)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&value->m_uiRefCount));
    }
    return *this;
}

// @fnv 0x00bc7720
NiD3DShaderDeclaration* BSShaderNoLighting::SelectVertexDeclaration(NiGeometry* pkGeometry,
                                                                    BSShaderProperty* pkShaderProperty)
{
    unsigned int uiFlags = pkShaderProperty->ulFlags[0];
    bool bFlag2 = (uiFlags & 0x2) > 0;
    if ((uiFlags & 0x40) > 0)
    {
        if ((pkShaderProperty->ulFlags[1] & 0x20) > 0)
        {
            if (*(int*)&static_cast<BSShaderNoLightingProperty*>(pkShaderProperty)->spBaseTexture.m_pObject != 0)
            {
                if (bFlag2)
                    return m_pkVertexDeclarationVariant12.m_pObject;
                return m_pkVertexDeclarationVariant6.m_pObject;
            }
            else
            {
                if (bFlag2)
                    return m_pkVertexDeclarationVariant11.m_pObject;
                return m_pkVertexDeclarationVariant5.m_pObject;
            }
        }
        else
        {
            if (bFlag2)
                return m_pkVertexDeclarationVariant10.m_pObject;
            return m_pkVertexDeclarationVariant4.m_pObject;
        }
    }
    else
    {
        if ((pkShaderProperty->ulFlags[1] & 0x20) > 0)
        {
            if (*(int*)&static_cast<BSShaderNoLightingProperty*>(pkShaderProperty)->spBaseTexture.m_pObject != 0)
            {
                if (bFlag2)
                    return m_pkVertexDeclarationVariant9.m_pObject;
                return m_pkVertexDeclarationVariant3.m_pObject;
            }
            else
            {
                if (bFlag2)
                    return m_pkVertexDeclarationVariant8.m_pObject;
                return m_spVertexDeclaration.m_pObject;
            }
        }
        else
        {
            if (bFlag2)
                return m_pkVertexDeclarationVariant7.m_pObject;
            return m_pkVertexDeclarationVariant1.m_pObject;
        }
    }
}

// Builds the vertex and pixel shader configs for the no-lighting shader set and assigns each compiled shader to its slot.
// @fnv 0x00bc5c40
void BSShaderNoLighting::InitializeShaderData()
{
    BSNoLightingShaderConfig vertexConfigs[28];
    char path[260];
    char output[260];
    vertexConfigs[0].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[0].macros[0].Name = "TEX";
    vertexConfigs[0].macros[0].Definition = "";
    vertexConfigs[0].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[0].macros[1].Definition, 0, 60);
    vertexConfigs[1].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[1].macros[0].Name = "VC";
    vertexConfigs[1].macros[0].Definition = "";
    vertexConfigs[1].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[1].macros[1].Definition, 0, 60);
    vertexConfigs[2].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[2].macros[0].Name = "TEX";
    vertexConfigs[2].macros[0].Definition = "";
    vertexConfigs[2].macros[1].Name = "VC";
    vertexConfigs[2].macros[1].Definition = "";
    vertexConfigs[2].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[2].macros[2].Definition, 0, 52);
    vertexConfigs[3].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[3].macros[0].Name = 0;
    fnv_zlib_memset(&vertexConfigs[3].macros[0].Definition, 0, 68);
    vertexConfigs[4].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[4].macros[0].Name = "TEX";
    vertexConfigs[4].macros[0].Definition = "";
    vertexConfigs[4].macros[1].Name = "FALLOFF";
    vertexConfigs[4].macros[1].Definition = "";
    vertexConfigs[4].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[4].macros[2].Definition, 0, 52);
    vertexConfigs[5].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[5].macros[0].Name = "VC";
    vertexConfigs[5].macros[0].Definition = "";
    vertexConfigs[5].macros[1].Name = "FALLOFF";
    vertexConfigs[5].macros[1].Definition = "";
    vertexConfigs[5].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[5].macros[2].Definition, 0, 52);
    vertexConfigs[6].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[6].macros[0].Name = "TEX";
    vertexConfigs[6].macros[0].Definition = "";
    vertexConfigs[6].macros[1].Name = "VC";
    vertexConfigs[6].macros[1].Definition = "";
    vertexConfigs[6].macros[2].Name = "FALLOFF";
    vertexConfigs[6].macros[2].Definition = "";
    vertexConfigs[6].macros[3].Name = 0;
    fnv_zlib_memset(&vertexConfigs[6].macros[3].Definition, 0, 44);
    vertexConfigs[7].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[7].macros[0].Name = "FALLOFF";
    vertexConfigs[7].macros[0].Definition = "";
    vertexConfigs[7].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[7].macros[1].Definition, 0, 60);
    vertexConfigs[8].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[8].macros[0].Name = "TEX";
    vertexConfigs[8].macros[0].Definition = "";
    vertexConfigs[8].macros[1].Name = "SKIN";
    vertexConfigs[8].macros[1].Definition = "";
    vertexConfigs[8].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[8].macros[2].Definition, 0, 52);
    vertexConfigs[9].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[9].macros[0].Name = "VC";
    vertexConfigs[9].macros[0].Definition = "";
    vertexConfigs[9].macros[1].Name = "SKIN";
    vertexConfigs[9].macros[1].Definition = "";
    vertexConfigs[9].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[9].macros[2].Definition, 0, 52);
    vertexConfigs[10].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[10].macros[0].Name = "TEX";
    vertexConfigs[10].macros[0].Definition = "";
    vertexConfigs[10].macros[1].Name = "VC";
    vertexConfigs[10].macros[1].Definition = "";
    vertexConfigs[10].macros[2].Name = "SKIN";
    vertexConfigs[10].macros[2].Definition = "";
    vertexConfigs[10].macros[3].Name = 0;
    fnv_zlib_memset(&vertexConfigs[10].macros[3].Definition, 0, 44);
    vertexConfigs[11].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[11].macros[0].Name = "SKIN";
    vertexConfigs[11].macros[0].Definition = "";
    vertexConfigs[11].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[11].macros[1].Definition, 0, 60);
    vertexConfigs[12].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[12].macros[0].Name = "TEX";
    vertexConfigs[12].macros[0].Definition = "";
    vertexConfigs[12].macros[1].Name = "FALLOFF";
    vertexConfigs[12].macros[1].Definition = "";
    vertexConfigs[12].macros[2].Name = "SKIN";
    vertexConfigs[12].macros[2].Definition = "";
    vertexConfigs[12].macros[3].Name = 0;
    fnv_zlib_memset(&vertexConfigs[12].macros[3].Definition, 0, 44);
    vertexConfigs[13].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[13].macros[0].Name = "VC";
    vertexConfigs[13].macros[0].Definition = "";
    vertexConfigs[13].macros[1].Name = "FALLOFF";
    vertexConfigs[13].macros[1].Definition = "";
    vertexConfigs[13].macros[2].Name = "SKIN";
    vertexConfigs[13].macros[2].Definition = "";
    vertexConfigs[13].macros[3].Name = 0;
    fnv_zlib_memset(&vertexConfigs[13].macros[3].Definition, 0, 44);
    vertexConfigs[14].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[14].macros[0].Name = "TEX";
    vertexConfigs[14].macros[0].Definition = "";
    vertexConfigs[14].macros[1].Name = "VC";
    vertexConfigs[14].macros[1].Definition = "";
    vertexConfigs[14].macros[2].Name = "FALLOFF";
    vertexConfigs[14].macros[2].Definition = "";
    vertexConfigs[14].macros[3].Name = "SKIN";
    vertexConfigs[14].macros[3].Definition = "";
    vertexConfigs[14].macros[4].Name = 0;
    memset(&vertexConfigs[14].macros[4].Definition, 0, 36);
    vertexConfigs[15].path = "lighting\\1x\\v\\NoLighting.v.hlsl";
    vertexConfigs[15].macros[0].Name = "FALLOFF";
    vertexConfigs[15].macros[0].Definition = "";
    vertexConfigs[15].macros[1].Name = "SKIN";
    vertexConfigs[15].macros[1].Definition = "";
    vertexConfigs[15].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[15].macros[2].Definition, 0, 52);
    vertexConfigs[16].path = "lighting\\1x\\v\\particlesystem.v.hlsl";
    vertexConfigs[16].macros[0].Name = 0;
    fnv_zlib_memset(&vertexConfigs[16].macros[0].Definition, 0, 68);
    vertexConfigs[17].path = "lighting\\1x\\v\\particlesystem.v.hlsl";
    vertexConfigs[17].macros[0].Name = "PSYS_SUBTEX";
    vertexConfigs[17].macros[0].Definition = "";
    vertexConfigs[17].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[17].macros[1].Definition, 0, 60);
    vertexConfigs[18].path = "lighting\\1x\\v\\particlesystem.v.hlsl";
    vertexConfigs[18].macros[0].Name = "PSYS_STRIP";
    vertexConfigs[18].macros[0].Definition = "";
    vertexConfigs[18].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[18].macros[1].Definition, 0, 60);
    vertexConfigs[19].path = "lighting\\1x\\v\\particlesystem.v.hlsl";
    vertexConfigs[19].macros[0].Name = "PSYS_STRIP";
    vertexConfigs[19].macros[0].Definition = "";
    vertexConfigs[19].macros[1].Name = "PSYS_SUBTEX";
    vertexConfigs[19].macros[1].Definition = "";
    vertexConfigs[19].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[19].macros[2].Definition, 0, 52);
    vertexConfigs[20].path = "lighting\\2x\\v\\waterfog.v.hlsl";
    vertexConfigs[20].macros[0].Name = 0;
    fnv_zlib_memset(&vertexConfigs[20].macros[0].Definition, 0, 68);
    vertexConfigs[21].path = "lighting\\2x\\v\\waterfog.v.hlsl";
    vertexConfigs[21].macros[0].Name = "TEXCOORD";
    vertexConfigs[21].macros[0].Definition = "";
    vertexConfigs[21].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[21].macros[1].Definition, 0, 60);
    vertexConfigs[22].path = "lighting\\2x\\v\\waterfog.v.hlsl";
    vertexConfigs[22].macros[0].Name = "VC";
    vertexConfigs[22].macros[0].Definition = "";
    vertexConfigs[22].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[22].macros[1].Definition, 0, 60);
    vertexConfigs[23].path = "lighting\\2x\\v\\waterfog.v.hlsl";
    vertexConfigs[23].macros[0].Name = "VC";
    vertexConfigs[23].macros[0].Definition = "";
    vertexConfigs[23].macros[1].Name = "TEXCOORD";
    vertexConfigs[23].macros[1].Definition = "";
    vertexConfigs[23].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[23].macros[2].Definition, 0, 52);
    vertexConfigs[24].path = "lighting\\2x\\v\\waterfog.v.hlsl";
    vertexConfigs[24].macros[0].Name = "SKIN";
    vertexConfigs[24].macros[0].Definition = "";
    vertexConfigs[24].macros[1].Name = 0;
    fnv_zlib_memset(&vertexConfigs[24].macros[1].Definition, 0, 60);
    vertexConfigs[25].path = "lighting\\2x\\v\\waterfog.v.hlsl";
    vertexConfigs[25].macros[0].Name = "TEXCOORD";
    vertexConfigs[25].macros[0].Definition = "";
    vertexConfigs[25].macros[1].Name = "SKIN";
    vertexConfigs[25].macros[1].Definition = "";
    vertexConfigs[25].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[25].macros[2].Definition, 0, 52);
    vertexConfigs[26].path = "lighting\\2x\\v\\waterfog.v.hlsl";
    vertexConfigs[26].macros[0].Name = "VC";
    vertexConfigs[26].macros[0].Definition = "";
    vertexConfigs[26].macros[1].Name = "SKIN";
    vertexConfigs[26].macros[1].Definition = "";
    vertexConfigs[26].macros[2].Name = 0;
    fnv_zlib_memset(&vertexConfigs[26].macros[2].Definition, 0, 52);
    vertexConfigs[27].path = "lighting\\2x\\v\\waterfog.v.hlsl";
    vertexConfigs[27].macros[0].Name = "VC";
    vertexConfigs[27].macros[0].Definition = "";
    vertexConfigs[27].macros[1].Name = "TEXCOORD";
    vertexConfigs[27].macros[1].Definition = "";
    vertexConfigs[27].macros[2].Name = "SKIN";
    vertexConfigs[27].macros[2].Definition = "";
    vertexConfigs[27].macros[3].Name = 0;
    fnv_zlib_memset(&vertexConfigs[27].macros[3].Definition, 0, 44);
    for (int i = 0; i < 28; ++i)
    {
        if (vertexConfigs[i].path)
        {
            GetShaderPath(vertexConfigs[i].path, path);
            sprintf_s(output, 260, "NOLIGHT%03i.vso", i);
            AssignShader(m_spTreeVertexShader[i], CompileVertexShader(path, vertexConfigs[i].macros, "vs_2_0", output));
        }
    }
    BSNoLightingShaderConfig texConfig;
    texConfig.path = "lighting\\1x\\p\\NoLighting.p.hlsl";
    texConfig.macros[0].Name = "TEX";
    texConfig.macros[0].Definition = "";
    texConfig.macros[1].Name = 0;
    fnv_zlib_memset(&texConfig.macros[1].Definition, 0, 60);
    BSNoLightingShaderConfig vcConfig;
    vcConfig.path = "lighting\\1x\\p\\NoLighting.p.hlsl";
    vcConfig.macros[0].Name = "VC";
    vcConfig.macros[0].Definition = "";
    vcConfig.macros[1].Name = 0;
    fnv_zlib_memset(&vcConfig.macros[1].Definition, 0, 60);
    BSNoLightingShaderConfig texVcConfig;
    texVcConfig.path = "lighting\\1x\\p\\NoLighting.p.hlsl";
    texVcConfig.macros[0].Name = "TEX";
    texVcConfig.macros[0].Definition = "";
    texVcConfig.macros[1].Name = "VC";
    texVcConfig.macros[1].Definition = "";
    texVcConfig.macros[2].Name = 0;
    fnv_zlib_memset(&texVcConfig.macros[2].Definition, 0, 52);
    BSNoLightingShaderConfig premultConfig;
    premultConfig.path = "lighting\\1x\\p\\NoLighting.p.hlsl";
    premultConfig.macros[0].Name = "PREMULT_ALPHA";
    premultConfig.macros[0].Definition = "";
    premultConfig.macros[1].Name = "TEX";
    premultConfig.macros[1].Definition = "";
    premultConfig.macros[2].Name = "VC";
    premultConfig.macros[2].Definition = "";
    premultConfig.macros[3].Name = 0;
    fnv_zlib_memset(&premultConfig.macros[3].Definition, 0, 44);
    BSNoLightingShaderConfig mat;
    mat.path = "lighting\\1x\\p\\NoLighting.p.hlsl";
    mat.macros[0].Name = 0;
    fnv_zlib_memset(&mat.macros[0].Definition, 0, 68);
    BSNoLightingShaderConfig waterConfig;
    waterConfig.path = "lighting\\2x\\p\\waterfog.p.hlsl";
    waterConfig.macros[0].Name = 0;
    fnv_zlib_memset(&waterConfig.macros[0].Definition, 0, 68);
    BSNoLightingShaderConfig waterAtConfig;
    waterAtConfig.path = "lighting\\2x\\p\\waterfog.p.hlsl";
    waterAtConfig.macros[0].Name = "ALPHATESTING";
    waterAtConfig.macros[0].Definition = "";
    waterAtConfig.macros[1].Name = 0;
    fnv_zlib_memset(&waterAtConfig.macros[1].Definition, 0, 60);
    GetShaderPath(texConfig.path, path);
    sprintf_s(output, 260, "NOLIGHTTEX.pso");
    AssignShader(m_spPixelShaderVariants[0], CompilePixelShader(path, texConfig.macros, "ps_2_a", output));
    GetShaderPath(vcConfig.path, path);
    sprintf_s(output, 260, "NOLIGHTVCONLY.pso");
    AssignShader(m_spPixelShaderVariants[1], CompilePixelShader(path, vcConfig.macros, "ps_2_a", output));
    GetShaderPath(texVcConfig.path, path);
    sprintf_s(output, 260, "NOLIGHTTEXVC.pso");
    AssignShader(m_spPixelShaderVariants[2], CompilePixelShader(path, texVcConfig.macros, "ps_2_a", output));
    GetShaderPath(premultConfig.path, path);
    sprintf_s(output, 260, "NOLIGHTTEXVCPMA.pso");
    AssignShader(m_spPixelShaderVariants[3], CompilePixelShader(path, premultConfig.macros, "ps_2_a", output));
    GetShaderPath(mat.path, path);
    sprintf_s(output, 260, "NOLIGHTMAT.pso");
    AssignShader(m_spPixelShaderVariants[4], CompilePixelShader(path, mat.macros, "ps_2_a", output));
    GetShaderPath(waterConfig.path, path);
    sprintf_s(output, 260, "NOLIGHTWF.pso");
    AssignShader(m_spPixelShaderVariants[5], CompilePixelShader(path, waterConfig.macros, "ps_2_a", output));
    GetShaderPath(waterAtConfig.path, path);
    sprintf_s(output, 260, "NOLIGHTWFAt.pso");
    AssignShader(m_spPixelShaderVariants[6], CompilePixelShader(path, waterAtConfig.macros, "ps_2_a", output));
}

// Builds twelve vertex declarations from DAT_011f9508, constructs a BSShaderNoLighting from them, initializes it and returns it.
// @fnv 0x00bc93c0
BSShader* BSShaderNoLighting::CreateShader()
{
    NiD3DVertexDeclaration* pDecl0 = NiD3DVertexDeclaration::Create(DAT_011f9508, 2, 1);
    NiD3DVertexDeclaration* pDecl1 = NiD3DVertexDeclaration::Create(DAT_011f9508, 2, 1);
    NiD3DVertexDeclaration* pDecl2 = NiD3DVertexDeclaration::Create(DAT_011f9508, 3, 1);
    NiD3DVertexDeclaration* pDecl3 = NiD3DVertexDeclaration::Create(DAT_011f9508, 3, 1);
    NiD3DVertexDeclaration* pDecl4 = NiD3DVertexDeclaration::Create(DAT_011f9508, 3, 1);
    NiD3DVertexDeclaration* pDecl5 = NiD3DVertexDeclaration::Create(DAT_011f9508, 4, 1);
    NiD3DVertexDeclaration* pDecl6 = NiD3DVertexDeclaration::Create(DAT_011f9508, 4, 1);
    NiD3DVertexDeclaration* pDecl7 = NiD3DVertexDeclaration::Create(DAT_011f9508, 4, 1);
    NiD3DVertexDeclaration* pDecl8 = NiD3DVertexDeclaration::Create(DAT_011f9508, 5, 1);
    NiD3DVertexDeclaration* pDecl9 = NiD3DVertexDeclaration::Create(DAT_011f9508, 5, 1);
    NiD3DVertexDeclaration* pDecl10 = NiD3DVertexDeclaration::Create(DAT_011f9508, 5, 1);
    NiD3DVertexDeclaration* pDecl11 = NiD3DVertexDeclaration::Create(DAT_011f9508, 6, 1);
    pDecl0->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl0->SetEntry(1, 7, static_cast<NiShaderDeclaration::ShaderParameter>(5), static_cast<NiShaderDeclaration::ShaderParameterType>(1), 0);
    pDecl0->GetD3DDeclaration();
    pDecl1->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl1->SetEntry(1, 5, static_cast<NiShaderDeclaration::ShaderParameter>(4), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl1->GetD3DDeclaration();
    pDecl2->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl2->SetEntry(1, 5, static_cast<NiShaderDeclaration::ShaderParameter>(4), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl2->SetEntry(2, 7, static_cast<NiShaderDeclaration::ShaderParameter>(5), static_cast<NiShaderDeclaration::ShaderParameterType>(1), 0);
    pDecl2->GetD3DDeclaration();
    pDecl3->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl3->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(3), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl3->SetEntry(2, 7, static_cast<NiShaderDeclaration::ShaderParameter>(5), static_cast<NiShaderDeclaration::ShaderParameterType>(1), 0);
    pDecl3->GetD3DDeclaration();
    pDecl4->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl4->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(3), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl4->SetEntry(2, 5, static_cast<NiShaderDeclaration::ShaderParameter>(4), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl4->GetD3DDeclaration();
    pDecl5->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl5->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(3), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl5->SetEntry(2, 5, static_cast<NiShaderDeclaration::ShaderParameter>(4), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl5->SetEntry(3, 7, static_cast<NiShaderDeclaration::ShaderParameter>(5), static_cast<NiShaderDeclaration::ShaderParameterType>(1), 0);
    pDecl5->GetD3DDeclaration();
    pDecl6->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl6->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(1), static_cast<NiShaderDeclaration::ShaderParameterType>(3), 0);
    pDecl6->SetEntry(2, 2, static_cast<NiShaderDeclaration::ShaderParameter>(2), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl6->SetEntry(3, 7, static_cast<NiShaderDeclaration::ShaderParameter>(5), static_cast<NiShaderDeclaration::ShaderParameterType>(1), 0);
    pDecl6->GetD3DDeclaration();
    pDecl7->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl7->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(1), static_cast<NiShaderDeclaration::ShaderParameterType>(3), 0);
    pDecl7->SetEntry(2, 2, static_cast<NiShaderDeclaration::ShaderParameter>(2), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl7->SetEntry(3, 5, static_cast<NiShaderDeclaration::ShaderParameter>(4), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl7->GetD3DDeclaration();
    pDecl8->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl8->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(1), static_cast<NiShaderDeclaration::ShaderParameterType>(3), 0);
    pDecl8->SetEntry(2, 2, static_cast<NiShaderDeclaration::ShaderParameter>(2), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl8->SetEntry(3, 5, static_cast<NiShaderDeclaration::ShaderParameter>(4), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl8->SetEntry(4, 7, static_cast<NiShaderDeclaration::ShaderParameter>(5), static_cast<NiShaderDeclaration::ShaderParameterType>(1), 0);
    pDecl8->GetD3DDeclaration();
    pDecl9->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl9->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(1), static_cast<NiShaderDeclaration::ShaderParameterType>(3), 0);
    pDecl9->SetEntry(2, 2, static_cast<NiShaderDeclaration::ShaderParameter>(2), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl9->SetEntry(3, 1, static_cast<NiShaderDeclaration::ShaderParameter>(3), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl9->SetEntry(4, 7, static_cast<NiShaderDeclaration::ShaderParameter>(5), static_cast<NiShaderDeclaration::ShaderParameterType>(1), 0);
    pDecl9->GetD3DDeclaration();
    pDecl10->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl10->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(1), static_cast<NiShaderDeclaration::ShaderParameterType>(3), 0);
    pDecl10->SetEntry(2, 2, static_cast<NiShaderDeclaration::ShaderParameter>(2), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl10->SetEntry(3, 1, static_cast<NiShaderDeclaration::ShaderParameter>(3), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl10->SetEntry(4, 5, static_cast<NiShaderDeclaration::ShaderParameter>(4), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl10->GetD3DDeclaration();
    pDecl11->SetEntry(0, 0, static_cast<NiShaderDeclaration::ShaderParameter>(0), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl11->SetEntry(1, 1, static_cast<NiShaderDeclaration::ShaderParameter>(1), static_cast<NiShaderDeclaration::ShaderParameterType>(3), 0);
    pDecl11->SetEntry(2, 2, static_cast<NiShaderDeclaration::ShaderParameter>(2), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl11->SetEntry(3, 1, static_cast<NiShaderDeclaration::ShaderParameter>(3), static_cast<NiShaderDeclaration::ShaderParameterType>(2), 0);
    pDecl11->SetEntry(4, 5, static_cast<NiShaderDeclaration::ShaderParameter>(4), static_cast<NiShaderDeclaration::ShaderParameterType>(4), 0);
    pDecl11->SetEntry(5, 7, static_cast<NiShaderDeclaration::ShaderParameter>(5), static_cast<NiShaderDeclaration::ShaderParameterType>(1), 0);
    pDecl11->GetD3DDeclaration();
    BSShaderNoLighting* shader = new BSShaderNoLighting(pDecl0, pDecl1, pDecl2, pDecl3, pDecl4, pDecl5, pDecl6, pDecl7,
                                                        pDecl8, pDecl9, pDecl10, pDecl11);
    shader->Initialize();
    shader->InitializeShaderData();
    shader->BSShaderNoLighting_LoadStagesAndPasses();
    shader->InitShaderConstants();
    shader->UseShaderDeclaration(pDecl0);
    return shader;
}

// Initializes the shader: sets a field to 22, assigns twelve shader arguments via AssignShader, copies DAT_011a9be0 into DAT_01202010 and clears a field.
// @fnv 0x00bc8f80
BSShaderNoLighting::BSShaderNoLighting(NiD3DVertexDeclaration* apShader0, NiD3DVertexDeclaration* apShader1,
                                       NiD3DVertexDeclaration* apShader2, NiD3DVertexDeclaration* apShader3,
                                       NiD3DVertexDeclaration* apShader4, NiD3DVertexDeclaration* apShader5,
                                       NiD3DVertexDeclaration* apShader6, NiD3DVertexDeclaration* apShader7,
                                       NiD3DVertexDeclaration* apShader8, NiD3DVertexDeclaration* apShader9,
                                       NiD3DVertexDeclaration* apShader10, NiD3DVertexDeclaration* apShader11)
{
    iShaderType = 22;
    AssignShader(m_pkVertexDeclarationVariant1, apShader0);
    AssignShader(m_spVertexDeclaration, apShader1);
    AssignShader(m_pkVertexDeclarationVariant3, apShader2);
    AssignShader(m_pkVertexDeclarationVariant4, apShader3);
    AssignShader(m_pkVertexDeclarationVariant5, apShader4);
    AssignShader(m_pkVertexDeclarationVariant6, apShader5);
    AssignShader(m_pkVertexDeclarationVariant7, apShader6);
    AssignShader(m_pkVertexDeclarationVariant8, apShader7);
    AssignShader(m_pkVertexDeclarationVariant9, apShader8);
    AssignShader(m_pkVertexDeclarationVariant10, apShader9);
    AssignShader(m_pkVertexDeclarationVariant11, apShader10);
    AssignShader(m_pkVertexDeclarationVariant12, apShader11);
    DAT_01202010 = DAT_011a9be0;
    m_pFirstShaderConstantMapEntry = 0;
}

// @fnv 0x00bc9a50
void BSShaderNoLighting::PrepareShaderPass(const NiPropertyState* properties)
{
    int pass = DAT_011f91e4;
    NiGeometry* geometry = *DAT_011f91e0;
    const NiTransform* world = &geometry->GetWorldTransform();
    NiBound* bound = reinterpret_cast<NiBound*>(geometry->m_kWorldBound);
    if (!bound)
        bound = &DAT_011f4288;
    NiGeometryBufferData* buffer = static_cast<NiGeometryBufferData*>(geometry->m_spModelData.m_pObject->m_pkBuffData);
    NiSkinInstance* skin = geometry->m_spSkinInstance.m_pObject;
    BSShaderNoLightingProperty* property = (BSShaderNoLightingProperty*)properties->m_aspProps[3];
    NiMaterialProperty* material = (NiMaterialProperty*)properties->m_aspProps[2];
    NiTransform identity;
    if (skin)
    {
        identity.ResetToIdentity();
        identity.m_Translate = DAT_011f474c;
        m_pkD3DRenderer->ApplyObjectTransform(identity, false);
    }
    else
    {
        m_pkD3DRenderer->ApplyObjectTransform(*world, false);
    }
    if ((unsigned int)(pass - 82) <= 5)
        CopyEntriesToGlobalBuffer(geometry, geometry->GetWorldTransform());
    UpdateGlobalMatrix(properties);
    BSShaderNoLighting_SetupGeometryConstants_WaterFog();
    UpdateMaterialColor(property, material);
    if ((unsigned int)(pass - 86) <= 1)
    {
        if ((property->ulFlags[0] & 0x40) > 0)
            DAT_01202030 = *reinterpret_cast<const NiColorA*>(&property->fFalloffStartAngle);
        else
            DAT_01202030 = NiColorA(0, 0, 0, 0);
    }
    else
    {
        DAT_01202030 = *reinterpret_cast<const NiColorA*>(&property->fFalloffStartAngle);
    }
    NiD3DShaderConstantMap* vertexMap = m_spVertexConstantMap.m_pObject;
    if (vertexMap)
    {
        NiD3DShaderProgram* program = reinterpret_cast<NiD3DPass*>(DAT_0126f74c)->m_spVertexShader.m_pObject;
        if (program)
            vertexMap->ConfigureShaderConstantMap(program, geometry, skin, static_cast<const NiSkinPartition::Partition*>(0), buffer, properties, static_cast<const NiDynamicEffectState*>(0),
                                                  geometry->GetWorldTransform(), *bound, 0, true);
    }
    DAT_01202020.r = 0;
    DAT_01202020.g = 0;
    NiAlphaProperty* alpha = (NiAlphaProperty*)properties->m_aspProps[0];
    if (alpha)
    {
        unsigned int blend = (alpha->m_usAlphaArg >> 5) & 15;
        if (blend == 0)
            DAT_01202020.r = 1;
        else if (blend == 2)
            DAT_01202020.g = 1;
    }
    NiD3DShaderConstantMap* pixelMap = m_spPixelConstantMap.m_pObject;
    if (pixelMap)
    {
        NiD3DShaderProgram* program = reinterpret_cast<NiD3DPass*>(DAT_0126f74c)->m_spPixelShader.m_pObject;
        if (program)
            pixelMap->ConfigureShaderConstantMap(program, geometry, skin, static_cast<const NiSkinPartition::Partition*>(0), buffer, properties, static_cast<const NiDynamicEffectState*>(0),
                                                 geometry->GetWorldTransform(), *bound, 0, true);
    }
    if (!((property->ulFlags[1] & 1) > 0))
        BSRenderState_SetZWriteEnable(0, 0);
    if (!((property->ulFlags[0] & 0x80000000) > 0))
        BSRenderState_SetZEnable(0, 0);
    NiWireframeProperty* wire = (NiWireframeProperty*)properties->m_aspProps[4];
    if (wire && (wire->m_uiObjectFlags & 1))
        m_pkD3DRenderState->SetWireframeProperty(wire);
}

extern NiColor DAT_011a9b7c;
extern NiColor DAT_011f4998;
extern bool DAT_011F941E;

// @fnv 0x00bc6fe0
void __fastcall UpdateMaterialColor(void* pThis, int, char* pMaterialProp, char* pShaderProp)
{
    DAT_01202010.a = (*(float*)(pMaterialProp + 0x28) < 1.0f) ? *(float*)(pMaterialProp + 0x28) : 1.0f;

    NiColor* pEmissiveColor = *(NiColor**)(pShaderProp + 0x34);
    if (!pEmissiveColor)
        pEmissiveColor = (NiColor*)(pShaderProp + 0x28);

    NiColor emissiveColor = *pEmissiveColor;

    if (DAT_011F941E || (emissiveColor.r < 0.1f && emissiveColor.g < 0.1f && emissiveColor.b < 0.1f))
    {
        float fScale = *(float*)(pShaderProp + 0x40);
        emissiveColor.r *= fScale;
        emissiveColor.g *= fScale;
        emissiveColor.b *= fScale;
    }

    if (emissiveColor.r == DAT_011f4998.r && emissiveColor.g == DAT_011f4998.g && emissiveColor.b == DAT_011f4998.b)
    {
        emissiveColor = DAT_011a9b7c;
    }

    DAT_01202010.r = emissiveColor.r;
    DAT_01202010.g = emissiveColor.g;
    DAT_01202010.b = emissiveColor.b;
}

void __fastcall UpdateMatrix(void* pThis);

extern float DAT_01201fe0;
extern float DAT_01201fe4;
extern float DAT_01201fe8;
extern float DAT_01201ff0;
extern float DAT_01201ff4;
extern float DAT_01201ff8;
extern float DAT_01202000;
extern float DAT_01202004;
extern float DAT_01202008;

struct Mat3x3_00bc8e00
{
    float m[3][3];
};

// Builds an identity 3x3 matrix, replaces it with the matrix at p3+0x20 when reachable, and copies it into the DAT_01201fe0..DAT_01202008 globals.
// @fnv 0x00bc8e00
void __stdcall UpdateGlobalMatrix(void* pObject)
{
    Mat3x3_00bc8e00 mat;
    mat.m[0][0] = 1.0f;
    mat.m[0][1] = 0.0f;
    mat.m[0][2] = 0.0f;
    mat.m[1][0] = 0.0f;
    mat.m[1][1] = 1.0f;
    mat.m[1][2] = 0.0f;
    mat.m[2][0] = 0.0f;
    mat.m[2][1] = 0.0f;
    mat.m[2][2] = 1.0f;

    char* p1 = *reinterpret_cast<char**>(reinterpret_cast<char*>(pObject) + 0x14);
    if (p1)
    {
        char* p2 = **reinterpret_cast<char***>(p1 + 0x20);
        if (p2)
        {
            char* p3 = *reinterpret_cast<char**>(p2 + 0xc);
            if (p3)
            {
                if (*reinterpret_cast<char*>(p3 + 0x1c) != 0)
                {
                    UpdateMatrix(p3);
                }
                mat = *reinterpret_cast<Mat3x3_00bc8e00*>(p3 + 0x20);
            }
        }
    }

    DAT_01201fe0 = mat.m[0][0];
    DAT_01201fe4 = mat.m[0][1];
    DAT_01201fe8 = mat.m[0][2];
    DAT_01201ff0 = mat.m[1][0];
    DAT_01201ff4 = mat.m[1][1];
    DAT_01201ff8 = mat.m[1][2];
    DAT_01202000 = mat.m[2][0];
    DAT_01202004 = mat.m[2][1];
    DAT_01202008 = mat.m[2][2];
}

void __fastcall NiDX9Renderer_CalculateBoneMatrices(void* this_ptr, int edx_unused, int arg1, int arg2, int arg3, int arg4, int arg5);

// If arg3 is non-null, calls FUN_00e6fe30 then invokes renderer vtable slot 0x78 with fields from this_ptr, arg2 and arg3, returning 0.
// @fnv 0x00bc8f20
// src: XBOX_PDB 0x00bc8f20
int __fastcall BSShaderNoLighting_SetupBoneMatrices(char* this_ptr, int edx_unused, int aiUnused, char* arg2, char* arg3, int arg4, int arg5,
                            int arg6, int arg7, int arg8)
{
    if (arg3)
    {
        NiDX9Renderer_CalculateBoneMatrices(DAT_011f9508, edx_unused, (int)arg2, arg7, 0, 3, 1);
        void* obj = reinterpret_cast<NiD3DPass*>(DAT_0126f74c)->m_spVertexShader.m_pObject;
        typedef void(__thiscall * VFunc)(void*, int, int, int, int, int);
        VFunc fn = (*(VFunc**)obj)[0x78 / 4];
        fn(obj, *(int*)(this_ptr + 0x180), *(int*)(arg2 + 0x28), *(unsigned short*)(arg3 + 0x20), *(int*)(arg2 + 0x20),
           *(int*)(arg3 + 4));
    }
    return 0;
}

extern float DAT_011ad83c;
extern float DAT_012021a8;

// @fnv 0x00bca050
void __stdcall ComputeReciprocal(int)
{
    DAT_012021a8 = 1.0f / DAT_011ad83c;
}

struct FUN_00bc6940_obj;
typedef void(__thiscall* FUN_00bc6940_fn)(FUN_00bc6940_obj*, int);
struct FUN_00bc6940_obj
{
    char pad[0x6c];
    int vals[30];
};

// Calls the function pointer at offset 0x128 on self once for each of the 30 ints in self->vals.
// @fnv 0x00bc6940
void __fastcall CallHandlerForEachValue(FUN_00bc6940_obj* self)
{
    for (int i = 0; i < 30; i++)
        (*reinterpret_cast<FUN_00bc6940_fn**>(self))[0x128 / 4](self, self->vals[i]);
}

extern "C" void* __cdecl _memmove(void*, const void*, unsigned int);
extern char DAT_01202048;

struct FUN_00bc6fa0_shell
{
    void __thiscall CopyEntriesToGlobalBuffer(int a1, int a2);
};

// Copies count 16-byte entries from the object at a1+0xb8 into DAT_01202048 and stores count at this+0x170+0x20.
// @fnv 0x00bc6fa0
void __thiscall FUN_00bc6fa0_shell::CopyEntriesToGlobalBuffer(int apSource, int aiUnused)
{
    int pContainer = *(int*)(apSource + 0xb8);
    unsigned char count = *(unsigned char*)(pContainer + 0x6c);
    if (count > 0)
    {
        int pEntries = *(int*)(pContainer + 0x68);
        _memmove(&DAT_01202048, (const void*)pEntries, count << 4);
        int obj = *(int*)((char*)this + 0x170);
        *(int*)(obj + 0x20) = count;
    }
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_01202040;

// @fnv 0x00bc7710
// src: XBOX_PDB 0x00bc7710
GlobalObjectO2_00a7b610* __cdecl BSShaderNoLighting_GetRTTI()
{
    return &g_01202040;
}

struct FUN_00bc9390_obj
{
    void DestroyShaderNoLighting();
};
void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x00bc9390
FUN_00bc9390_obj* __fastcall FUN_00bc9390(FUN_00bc9390_obj* self, int unused, unsigned int flags)
{
    self->DestroyShaderNoLighting();
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x1b4);
    return self;
}

struct NLPt3
{
    float x, y, z;
    NLPt3()
    {}
    NLPt3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    float operator*(const NLPt3& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};
struct NLPt4
{
    float x, y, z, w;
    NLPt4()
    {}
    NLPt4(float fX, float fY, float fZ, float fW) : x(fX), y(fY), z(fZ), w(fW)
    {}
};
struct NLPlane
{
    NLPt3 m_kPlaneNormal;
    float m_fPlaneConstant;
    NLPlane()
    {}
    NLPlane(const NLPt3& kNormal, float fConstant)
    {
        m_kPlaneNormal = kNormal;
        m_fPlaneConstant = fConstant;
    }
    const NLPt3& GetPlaneNormal() const
    {
        return m_kPlaneNormal;
    }
    float GetPlaneConstant() const
    {
        return m_fPlaneConstant;
    }
    float Distance(const NLPt3& kPoint) const
    {
        return m_kPlaneNormal * kPoint - m_fPlaneConstant;
    }
};
struct NLPass
{
    char pad[8];
    bool bEnabled;
};
extern NLPt3 DAT_011fa2a0;
extern float DAT_011f9618;
extern NLPlane DAT_011f9604;
extern NLPt4 DAT_01202148;
extern NLPt4 DAT_01202158;
struct FUN_00bc7100_t
{
    char pad[0x174];
    NLPass* pPass;
    void BSShaderNoLighting_SetupGeometryConstants_WaterFog();
};
// If DAT_011f91e4 is in [0x2d8,0x2ef], enables pPass and writes DAT_011f9618 and the plane normal/distance into DAT_01202148 and DAT_01202158.
// @fnv 0x00bc7100
// src: COMMUNITY 0x00bc7100
void FUN_00bc7100_t::BSShaderNoLighting_SetupGeometryConstants_WaterFog()
{
    if (DAT_011f91e4 >= 0x2d8 && DAT_011f91e4 <= 0x2ef)
    {
        pPass->bEnabled = true;
        NLPt3 kPos(DAT_011fa2a0.x, DAT_011fa2a0.y, DAT_011fa2a0.z);
        NLPlane m_kFogPlane = DAT_011f9604;
        NLPt3 kNormal = DAT_011f9604.GetPlaneNormal();
        DAT_01202148 = NLPt4(DAT_011f9618, 0.0f, 0.0f, 0.0f);
        DAT_01202158 = NLPt4(kNormal.x, kNormal.y, kNormal.z, m_kFogPlane.Distance(kPos));
    }
}

void __cdecl BSRenderState_SetWireframeEnable(unsigned int, unsigned int);
void __cdecl BSRenderState_SetZWriteEnable(unsigned int, unsigned int);
void __cdecl BSRenderState_SetZEnable(unsigned int, unsigned int);
void __cdecl UpdateRendererStateCount(unsigned int, unsigned int);

// Updates render states from the shader and wireframe properties.
// @fnv 0x00bc8d90
void __stdcall UpdateFlagStates(const NiPropertyState* owner)
{
    BSShaderProperty* target = static_cast<BSShaderProperty*>(owner->m_aspProps[3]);
    if (target != 0 && (target->ulFlags[1] & 0x10000) > 0)
    {
        BSRenderState_SetWireframeEnable(0, 0);
    }
    if ((target->ulFlags[1] & 1) <= 0)
    {
        BSRenderState_SetZWriteEnable(1, 0);
    }
    if ((target->ulFlags[0] & 0x80000000u) <= 0)
    {
        BSRenderState_SetZEnable(1, 0);
    }
    NiWireframeProperty* other = static_cast<NiWireframeProperty*>(owner->m_aspProps[4]);
    if (other != 0 && (other->m_uiObjectFlags & 1) != 0)
    {
        UpdateRendererStateCount(0, 0);
    }
}

extern unsigned int DAT_011f91e4;
void __cdecl FUN_00b97fa0(int, int);
void __cdecl AddToTwoCounters(int, int, int);
struct ShaderDispatcher
{
    void DispatchShaderProperty(NiAlphaProperty** property);
    void NiD3DShader_SetupGeometryAlphaBlending(NiAlphaProperty** property);
};
// Dispatches alpha-property rendering based on the current pass and alpha flags.
// @fnv 0x00bc8ed0
void ShaderDispatcher::DispatchShaderProperty(NiAlphaProperty** property)
{
    unsigned int mode = DAT_011f91e4;
    NiAlphaProperty* shader = *property;
    if ((!shader || !(shader->m_usAlphaArg & 1)) && (mode - 74U <= 7U))
    {
        FUN_00b97fa0(1, 0);
        AddToTwoCounters(6, 7, 0);
    }
    else
    {
        NiD3DShader_SetupGeometryAlphaBlending(property);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

class D3DRenderStateGroup
{
  public:
    void SetNodeValue(unsigned int, unsigned int, bool);
};
D3DRenderStateGroup* FUN_00e7f5d0();
inline D3DRenderStateGroup* NiD3DPass::GetRenderStateGroup()
{
    if (!m_pkRenderStateGroup)
        m_pkRenderStateGroup = FUN_00e7f5d0();
    return m_pkRenderStateGroup;
}
struct BeamStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
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
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct ShaderStagePointer
{
    BeamStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
void AssignStageFromPool(ShaderStagePointer*);
void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);
extern unsigned int DAT_011f9534;

void FUN_00e804d0(NiPointer<NiD3DPass>*);
struct LightingShader
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
    NiPointer<NiD3DPass> pass6c;
    NiPointer<NiD3DPass> pass70;
    NiPointer<NiD3DPass> pass74;
    NiPointer<NiD3DPass> pass78;
    NiPointer<NiD3DPass> pass7c;
    NiPointer<NiD3DPass> pass80;
    NiPointer<NiD3DPass> pass84;
    NiPointer<NiD3DPass> pass88;
    NiPointer<NiD3DPass> pass8c;
    NiPointer<NiD3DPass> pass90;
    NiPointer<NiD3DPass> pass94;
    NiPointer<NiD3DPass> pass98;
    NiPointer<NiD3DPass> pass9c;
    NiPointer<NiD3DPass> passa0;
    NiPointer<NiD3DPass> passa4;
    NiPointer<NiD3DPass> passa8;
    NiPointer<NiD3DPass> passac;
    NiPointer<NiD3DPass> passb0;
    NiPointer<NiD3DPass> passb4;
    NiPointer<NiD3DPass> passb8;
    NiPointer<NiD3DPass> passbc;
    NiPointer<NiD3DPass> passc0;
    NiPointer<NiD3DPass> passc4;
    NiPointer<NiD3DPass> passc8;
    NiPointer<NiD3DPass> passcc;
    NiPointer<NiD3DPass> passd0;
    NiPointer<NiD3DPass> passd4;
    NiPointer<NiD3DPass> passd8;
    NiPointer<NiD3DPass> passdc;
    NiPointer<NiD3DPass> passe0;
    NiD3DVertexShader* shadere4;
    NiD3DVertexShader* shadere8;
    NiD3DVertexShader* shaderec;
    NiD3DVertexShader* shaderf0;
    NiD3DVertexShader* shaderf4;
    NiD3DVertexShader* shaderf8;
    NiD3DVertexShader* shaderfc;
    NiD3DVertexShader* shader100;
    NiD3DVertexShader* shader104;
    NiD3DVertexShader* shader108;
    NiD3DVertexShader* shader10c;
    NiD3DVertexShader* shader110;
    NiD3DVertexShader* shader114;
    NiD3DVertexShader* shader118;
    NiD3DVertexShader* shader11c;
    NiD3DVertexShader* shader120;
    NiD3DVertexShader* shader124;
    NiD3DVertexShader* shader128;
    NiD3DVertexShader* shader12c;
    NiD3DVertexShader* shader130;
    NiD3DVertexShader* shader134;
    NiD3DVertexShader* shader138;
    NiD3DVertexShader* shader13c;
    NiD3DVertexShader* shader140;
    NiD3DVertexShader* shader144;
    NiD3DVertexShader* shader148;
    NiD3DVertexShader* shader14c;
    NiD3DVertexShader* shader150;
    NiD3DPixelShader* shader154;
    NiD3DPixelShader* shader158;
    NiD3DPixelShader* shader15c;
    NiD3DPixelShader* shader160;
    NiD3DPixelShader* shader164;
    NiD3DPixelShader* shader168;
    NiD3DPixelShader* shader16c;
    bool BSShaderNoLighting_LoadStagesAndPasses();
};
// Creates each shader pass in the lighting shader, optionally adding a new stage and assigning vertex and pixel shaders.
// @fnv 0x00bc77e0
// src: COMMUNITY 0x00bc77e0
bool LightingShader::BSShaderNoLighting_LoadStagesAndPasses()
{
    FUN_00e804d0(&pass6c);
    ShaderStagePointer stage;
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    pass6c->NiD3DPass_SetStage(pass6c->m_uiCurrentStage, stage.object);
    pass6c->m_spVertexShader = shadere4;
    pass6c->m_spPixelShader = shader154;
    FUN_00e804d0(&pass70);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    pass70->NiD3DPass_SetStage(pass70->m_uiCurrentStage, stage.object);
    pass70->m_spVertexShader = shaderec;
    {
        NiD3DPixelShader* shader = shader15c;
        pass70->m_spPixelShader = shader;
    }
    FUN_00e804d0(&pass74);
    pass74->m_spVertexShader = shadere8;
    pass74->m_spPixelShader = shader158;
    FUN_00e804d0(&pass78);
    pass78->m_spVertexShader = shaderf0;
    pass78->m_spPixelShader = shader164;
    FUN_00e804d0(&pass7c);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    pass7c->NiD3DPass_SetStage(pass7c->m_uiCurrentStage, stage.object);
    pass7c->m_spVertexShader = shaderf4;
    pass7c->m_spPixelShader = shader154;
    FUN_00e804d0(&pass80);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    pass80->NiD3DPass_SetStage(pass80->m_uiCurrentStage, stage.object);
    pass80->m_spVertexShader = shaderfc;
    pass80->m_spPixelShader = shader15c;
    FUN_00e804d0(&pass84);
    pass84->m_spVertexShader = shaderf8;
    pass84->m_spPixelShader = shader158;
    FUN_00e804d0(&pass88);
    pass88->m_spVertexShader = shader100;
    pass88->m_spPixelShader = shader164;
    FUN_00e804d0(&pass8c);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    pass8c->NiD3DPass_SetStage(pass8c->m_uiCurrentStage, stage.object);
    pass8c->m_spVertexShader = shader104;
    pass8c->m_spPixelShader = shader154;
    FUN_00e804d0(&pass90);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    pass90->NiD3DPass_SetStage(pass90->m_uiCurrentStage, stage.object);
    pass90->m_spVertexShader = shader10c;
    pass90->m_spPixelShader = shader15c;
    FUN_00e804d0(&pass94);
    pass94->m_spVertexShader = shader108;
    pass94->m_spPixelShader = shader158;
    FUN_00e804d0(&pass98);
    pass98->m_spVertexShader = shader110;
    pass98->m_spPixelShader = shader164;
    FUN_00e804d0(&pass9c);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    pass9c->NiD3DPass_SetStage(pass9c->m_uiCurrentStage, stage.object);
    pass9c->m_spVertexShader = shader114;
    pass9c->m_spPixelShader = shader154;
    FUN_00e804d0(&passa0);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passa0->NiD3DPass_SetStage(passa0->m_uiCurrentStage, stage.object);
    passa0->m_spVertexShader = shader11c;
    passa0->m_spPixelShader = shader15c;
    FUN_00e804d0(&passa4);
    passa4->m_spVertexShader = shader118;
    passa4->m_spPixelShader = shader158;
    FUN_00e804d0(&passa8);
    passa8->m_spVertexShader = shader120;
    passa8->m_spPixelShader = shader164;
    FUN_00e804d0(&passac);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passac->NiD3DPass_SetStage(passac->m_uiCurrentStage, stage.object);
    passac->m_spVertexShader = shader124;
    passac->m_spPixelShader = shader15c;
    FUN_00e804d0(&passb0);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passb0->NiD3DPass_SetStage(passb0->m_uiCurrentStage, stage.object);
    passb0->m_spVertexShader = shader128;
    passb0->m_spPixelShader = shader15c;
    FUN_00e804d0(&passb4);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passb4->NiD3DPass_SetStage(passb4->m_uiCurrentStage, stage.object);
    passb4->m_spVertexShader = shader124;
    passb4->m_spPixelShader = shader160;
    FUN_00e804d0(&passb8);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passb8->NiD3DPass_SetStage(passb8->m_uiCurrentStage, stage.object);
    passb8->m_spVertexShader = shader128;
    passb8->m_spPixelShader = shader160;
    FUN_00e804d0(&passbc);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passbc->NiD3DPass_SetStage(passbc->m_uiCurrentStage, stage.object);
    passbc->m_spVertexShader = shader12c;
    passbc->m_spPixelShader = shader15c;
    FUN_00e804d0(&passc0);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passc0->NiD3DPass_SetStage(passc0->m_uiCurrentStage, stage.object);
    passc0->m_spVertexShader = shader130;
    passc0->m_spPixelShader = shader15c;
    FUN_00e804d0(&passc4);
    passc4->m_spVertexShader = shader134;
    passc4->m_spPixelShader = shader168;
    passc4->GetRenderStateGroup()->SetNodeValue(168, 3, true);
    FUN_00e804d0(&passc8);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passc8->NiD3DPass_SetStage(passc8->m_uiCurrentStage, stage.object);
    passc8->m_spVertexShader = shader138;
    passc8->m_spPixelShader = shader16c;
    passc8->GetRenderStateGroup()->SetNodeValue(168, 3, true);
    FUN_00e804d0(&passcc);
    passcc->m_spVertexShader = shader13c;
    passcc->m_spPixelShader = shader168;
    passcc->GetRenderStateGroup()->SetNodeValue(168, 3, true);
    FUN_00e804d0(&passd0);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passd0->NiD3DPass_SetStage(passd0->m_uiCurrentStage, stage.object);
    passd0->m_spVertexShader = shader140;
    passd0->m_spPixelShader = shader16c;
    passd0->GetRenderStateGroup()->SetNodeValue(168, 3, true);
    FUN_00e804d0(&passd4);
    passd4->m_spVertexShader = shader144;
    passd4->m_spPixelShader = shader168;
    passd4->GetRenderStateGroup()->SetNodeValue(168, 3, true);
    FUN_00e804d0(&passd8);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passd8->NiD3DPass_SetStage(passd8->m_uiCurrentStage, stage.object);
    passd8->m_spVertexShader = shader148;
    passd8->m_spPixelShader = shader16c;
    passd8->GetRenderStateGroup()->SetNodeValue(168, 3, true);
    FUN_00e804d0(&passdc);
    passdc->m_spVertexShader = shader14c;
    passdc->m_spPixelShader = shader168;
    passdc->GetRenderStateGroup()->SetNodeValue(168, 3, true);
    FUN_00e804d0(&passe0);
    AssignStageFromPool(&stage);
    ConfigureBeamStage(stage.object, 0, 3, 2, true);
    passe0->NiD3DPass_SetStage(passe0->m_uiCurrentStage, stage.object);
    passe0->m_spVertexShader = shader150;
    passe0->m_spPixelShader = shader16c;
    passe0->GetRenderStateGroup()->SetNodeValue(168, 3, true);
    return true;
}

template <> inline NiPointer<NiD3DPass>::~NiPointer()
{
    NiD3DPass* pass = m_pObject;
    if (pass)
    {
        unsigned int* referenceCount = &pass->m_uiRefCount;
        if (--*referenceCount == 0)
        {
            pass->FUN_00e80190();
        }
    }
}

__forceinline BSShaderNoLighting::~BSShaderNoLighting()
{
    for (unsigned int i = 0; i < 30; ++i)
    {
        NiD3DPass* pass = spRenderPass[i].m_pObject;
        if (pass)
        {
            unsigned int* referenceCount = &pass->m_uiRefCount;
            if (--*referenceCount == 0)
            {
                pass->FUN_00e80190();
            }
            spRenderPass[i].m_pObject = 0;
        }
    }

    for (unsigned int i = 0; i < 28; ++i)
    {
        NiD3DVertexShader* vertex = m_spTreeVertexShader[i].m_pObject;
        if (vertex)
        {
            vertex->DecRefCount();
            m_spTreeVertexShader[i].m_pObject = 0;
        }
    }

    for (unsigned int i = 0; i < 7; ++i)
    {
        NiD3DPixelShader* pixel = m_spPixelShaderVariants[i].m_pObject;
        if (pixel)
        {
            pixel->DecRefCount();
            m_spPixelShaderVariants[i].m_pObject = 0;
        }
    }

    if (m_pkVertexDeclarationVariant1.m_pObject)
    {
        m_pkVertexDeclarationVariant1.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant1.m_pObject = 0;
    }
    if (m_spVertexDeclaration.m_pObject)
    {
        m_spVertexDeclaration.m_pObject->DecRefCount();
        m_spVertexDeclaration.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant3.m_pObject)
    {
        m_pkVertexDeclarationVariant3.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant3.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant4.m_pObject)
    {
        m_pkVertexDeclarationVariant4.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant4.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant5.m_pObject)
    {
        m_pkVertexDeclarationVariant5.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant5.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant6.m_pObject)
    {
        m_pkVertexDeclarationVariant6.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant6.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant7.m_pObject)
    {
        m_pkVertexDeclarationVariant7.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant7.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant8.m_pObject)
    {
        m_pkVertexDeclarationVariant8.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant8.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant9.m_pObject)
    {
        m_pkVertexDeclarationVariant9.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant9.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant10.m_pObject)
    {
        m_pkVertexDeclarationVariant10.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant10.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant11.m_pObject)
    {
        m_pkVertexDeclarationVariant11.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant11.m_pObject = 0;
    }
    if (m_pkVertexDeclarationVariant12.m_pObject)
    {
        m_pkVertexDeclarationVariant12.m_pObject->DecRefCount();
        m_pkVertexDeclarationVariant12.m_pObject = 0;
    }
    m_pFirstShaderConstantMapEntry = 0;
}

// Calls the BSShaderNoLighting destructor on shader, releasing its pass, vertex and pixel shader pointers.
// @fnv 0x00bc7220
void __fastcall DestroyShaderNoLighting(BSShaderNoLighting* shader)
{
    shader->BSShaderNoLighting::~BSShaderNoLighting();
}

class TechniqueShader
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    NiPointer<NiD3DShaderDeclaration> m_pkTechniquePass;
    unsigned int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68;
    int m_iPass42, m_iPass44, m_iPass43, m_iPass45, m_iPass4a, m_iPass4c, m_iPass4b, m_iPass4d;
    int m_iPass46, m_iPass48, m_iPass47, m_iPass49, m_iPass4e, m_iPass50, m_iPass4f, m_iPass51;
    int m_iPass52, m_iPass53, m_iPass54, m_iPass55, m_iPass56, m_iPass57, m_iPass2dc, m_iPass2e2;
    int m_iPass2e8, m_iPass2ee, m_iPass2dd, m_iPass2e3, m_iPass2e9, m_iPass2ef;
    unsigned int unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c, unk110;
    unsigned int unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168;
    unsigned int unk16c, unk170, unk174, unk178, unk17c, unk180;
    NiD3DVertexDeclaration* m_pkPass184;
    NiD3DVertexDeclaration* m_pkPass188;
    NiD3DVertexDeclaration* m_pkPass18c;
    NiD3DVertexDeclaration* m_pkPass190;
    NiD3DVertexDeclaration* m_pkPass194;
    NiD3DVertexDeclaration* m_pkPass198;
    NiD3DVertexDeclaration* m_pkPass19c;
    NiD3DVertexDeclaration* m_pkPass1a0;
    NiD3DVertexDeclaration* m_pkPass1a4;
    NiD3DVertexDeclaration* m_pkPass1a8;
    NiD3DVertexDeclaration* m_pkPass1ac;
    NiD3DVertexDeclaration* m_pkPass1b0;

    void SetPass(unsigned int uiTechnique);
};

// Selects the technique pass for uiTechnique, storing the pass index in DAT_0126f74c and the pass pointer in m_pkTechniquePass.
// @fnv 0x00bc6970
void TechniqueShader::SetPass(unsigned int uiTechnique)
{
    switch (uiTechnique)
    {
    case 0x42:
        DAT_0126f74c = m_iPass42;
        m_pkTechniquePass = m_pkPass184;
        break;
    case 0x44:
        DAT_0126f74c = m_iPass44;
        m_pkTechniquePass = m_pkPass18c;
        break;
    case 0x43:
        DAT_0126f74c = m_iPass43;
        m_pkTechniquePass = m_pkPass188;
        break;
    case 0x45:
        DAT_0126f74c = m_iPass45;
        m_pkTechniquePass = m_pkPass184;
        break;
    case 0x4a:
        DAT_0126f74c = m_iPass4a;
        m_pkTechniquePass = m_pkPass190;
        break;
    case 0x4c:
        DAT_0126f74c = m_iPass4c;
        m_pkTechniquePass = m_pkPass198;
        break;
    case 0x4b:
        DAT_0126f74c = m_iPass4b;
        m_pkTechniquePass = m_pkPass194;
        break;
    case 0x4d:
        DAT_0126f74c = m_iPass4d;
        m_pkTechniquePass = m_pkPass190;
        break;
    case 0x46:
        DAT_0126f74c = m_iPass46;
        m_pkTechniquePass = m_pkPass19c;
        break;
    case 0x48:
        DAT_0126f74c = m_iPass48;
        m_pkTechniquePass = m_pkPass1a4;
        break;
    case 0x47:
        DAT_0126f74c = m_iPass47;
        m_pkTechniquePass = m_pkPass1a0;
        break;
    case 0x49:
        DAT_0126f74c = m_iPass49;
        m_pkTechniquePass = m_pkPass19c;
        break;
    case 0x4e:
        DAT_0126f74c = m_iPass4e;
        m_pkTechniquePass = m_pkPass1a8;
        break;
    case 0x50:
        DAT_0126f74c = m_iPass50;
        m_pkTechniquePass = m_pkPass1b0;
        break;
    case 0x4f:
        DAT_0126f74c = m_iPass4f;
        m_pkTechniquePass = m_pkPass1ac;
        break;
    case 0x51:
        DAT_0126f74c = m_iPass51;
        m_pkTechniquePass = m_pkPass1a8;
        break;
    case 0x52:
        DAT_0126f74c = m_iPass52;
        m_pkTechniquePass = 0;
        break;
    case 0x53:
        DAT_0126f74c = m_iPass53;
        m_pkTechniquePass = 0;
        break;
    case 0x54:
        DAT_0126f74c = m_iPass54;
        m_pkTechniquePass = 0;
        break;
    case 0x55:
        DAT_0126f74c = m_iPass55;
        m_pkTechniquePass = 0;
        break;
    case 0x56:
        DAT_0126f74c = m_iPass56;
        m_pkTechniquePass = 0;
        break;
    case 0x57:
        DAT_0126f74c = m_iPass57;
        m_pkTechniquePass = 0;
        break;
    case 0x2dc:
        DAT_0126f74c = m_iPass2dc;
        m_pkTechniquePass = m_pkPass184;
        break;
    case 0x2e2:
        DAT_0126f74c = m_iPass2e2;
        m_pkTechniquePass = m_pkPass184;
        break;
    case 0x2e8:
        DAT_0126f74c = m_iPass2e8;
        m_pkTechniquePass = m_pkPass188;
        break;
    case 0x2ee:
        DAT_0126f74c = m_iPass2ee;
        m_pkTechniquePass = m_pkPass18c;
        break;
    case 0x2dd:
        DAT_0126f74c = m_iPass2dd;
        m_pkTechniquePass = m_pkPass19c;
        break;
    case 0x2e3:
        DAT_0126f74c = m_iPass2e3;
        m_pkTechniquePass = m_pkPass19c;
        break;
    case 0x2e9:
        DAT_0126f74c = m_iPass2e9;
        m_pkTechniquePass = m_pkPass1a0;
        break;
    case 0x2ef:
        DAT_0126f74c = m_iPass2ef;
        m_pkTechniquePass = m_pkPass1a4;
        break;
    }
}

struct BSShaderNoLightingShell : BSShaderNoLighting
{
    void BSShaderNoLighting_ReloadShaders();
};
// @fnv 0x00bc8d30
// src: XBOX_PDB 0x00bc8d30
void BSShaderNoLightingShell::BSShaderNoLighting_ReloadShaders()
{
    InitializeShaderData();
    BSShaderNoLighting_LoadStagesAndPasses();
}

namespace NoLightingConsts {
extern "C" unsigned int DAT_01202158;
extern "C" unsigned int DAT_01202148;
extern "C" unsigned int DAT_01202048;
}

extern unsigned char DAT_01011584[];
void* __cdecl Object_DispatchCommandFour(unsigned int size);

inline void NiD3DShaderConstantMap::IncRefCount()
{
    NiRefObject::IncRefCount();
}
inline void NiD3DShaderConstantMap::DecRefCount()
{
    NiRefObject::DecRefCount();
}
extern NiColorA DAT_01202010;
extern NiColorA DAT_01202020;
extern NiColorA DAT_01202030;
extern float DAT_01201fe0;
extern float DAT_01202168;
// VC9 reverses overload groups in the vtable; the game's name lookup occupies slot 0x70.
__forceinline NiShaderConstantMapEntry* LookupShaderConstantMapEntry(
    NiD3DShaderConstantMap* map, const char* name)
{
    typedef NiShaderConstantMapEntry* (__thiscall *Lookup)(NiD3DShaderConstantMap*, const char*);
    return (*reinterpret_cast<Lookup**>(map))[0x70 / sizeof(void*)](map, name);
}

class NoLightingShaderBuild
{
  public:
    char pad0[0x18];
    GraphicsRenderer* m18;
    char pad1[0x30 - 0x1c];
    NiD3DShaderConstantMap* m30;
    NiD3DShaderConstantMap* m34;
    char pad2[0x170 - 0x38];
    int m170, m174, m178, m17c, m180;
    void BSShaderNoLighting_CreateConstantMaps();
};
// Lazily creates and populates the pixel and vertex constant maps with shader constant values and stores their indices in m170-m180.
// @fnv 0x00bc9cc0
// src: XBOX_PDB 0x00bc9cc0
void NoLightingShaderBuild::BSShaderNoLighting_CreateConstantMaps()
{
    if (!m30)
    {
        NiD3DShaderConstantMap* pMap = new NiD3DShaderConstantMap(static_cast<void*>(m18), 2);
        if (m30 != pMap)
        {
            if (m30)
                m30->DecRefCount();
            m30 = pMap;
            if (pMap)
                pMap->IncRefCount();
        }
        m30->SetConstant("matcolor", 0x10000007, 0, 0, 1, reinterpret_cast<const char*>(DAT_01011584), 0x10, 4, &DAT_01202010, 0);
        m30->SetConstant("matalpha", 0x10000007, 0, 1, 1, reinterpret_cast<const char*>(DAT_01011584), 0x10, 4, &DAT_01202020, 0);
        m30->SetConstant("fogcolor", 0x10000007, 0, 2, 1, reinterpret_cast<const char*>(DAT_01011584), 0x10, 4, &NoLightingConsts::DAT_01202158, 0);
        m30->SetConstant("waterfog", 0x10000009, 0, 5, 2, reinterpret_cast<const char*>(DAT_01011584), 0x20, 4, &DAT_01202168, 0);
    }
    if (!m34)
    {
        NiD3DShaderConstantMap* pMap = new NiD3DShaderConstantMap(static_cast<void*>(m18), 0);
        if (m34 != pMap)
        {
            if (m34)
                m34->DecRefCount();
            m34 = pMap;
            if (pMap)
                pMap->IncRefCount();
        }
        m34->SetConstant("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, 0);
        m34->SetConstant("WorldViewTranspose", 0x20000009, 0, 0x24, 4, 0, 0, 0, 0, 0);
        m178 = reinterpret_cast<int>(LookupShaderConstantMapEntry(m34, "WorldViewTranspose"));
        m34->SetConstant("WorldTranspose", 0x20000009, 0, 8, 4, 0, 0, 0, 0, 0);
        m174 = reinterpret_cast<int>(LookupShaderConstantMapEntry(m34, "WorldTranspose"));
        m34->SetConstant("EyeDir", 0x20000009, 0, 0x29, 4, 0, 0, 0, 0, 0);
        m17c = reinterpret_cast<int>(LookupShaderConstantMapEntry(m34, "EyeDir"));
        m34->SetConstant("TextureTransform", 0x10000008, 0, 4, 3, reinterpret_cast<const char*>(DAT_01011584), 0x30, 4, &DAT_01201fe0, 0);
        m34->SetConstant("fog", 0x10000009, 0, 0xd, 2, reinterpret_cast<const char*>(DAT_01011584), 0x20, 4, &NoLightingConsts::DAT_01202148, 0);
        m34->SetConstant("falloff", 0x10000007, 0, 0x28, 1, reinterpret_cast<const char*>(DAT_01011584), 0x10, 4, &DAT_01202030, 0);
        m34->SetConstant("subtex", 0x10000009, 0, 0xf, 0x10, reinterpret_cast<const char*>(DAT_01011584), 0x100, 4, &NoLightingConsts::DAT_01202048, 0);
        m170 = reinterpret_cast<int>(LookupShaderConstantMapEntry(m34, "subtex"));
        m34->SetConstant("BoneMatrix3", 0x20000009, 0x120000, 0x40, 0x36, 0, 0, 0, 0, 0);
        m180 = reinterpret_cast<int>(LookupShaderConstantMapEntry(m34, "BoneMatrix3"));
    }
}
