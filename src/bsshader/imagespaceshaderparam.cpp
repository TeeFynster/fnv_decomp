// bsshader/imagespaceshaderparam.cpp: ImageSpaceShaderParam (9 functions)
#include "NiRefObject_inline.h"

#include "imagespaceshaderparam_decls.h"
#include "imagespaceshaderparam_types_NiD3DShaderConstantMap.h"
#include "imagespaceshaderparam_types_ImageSpaceShaderParam.h"

// Releases and reallocates the vertex and pixel constant arrays, then registers them with two new NiD3DShaderConstantMap objects.
// @fnv 0x00b8ab10
void ImageSpaceShaderParam::AllocateShaderConstants(int vertexCount, int pixelCount)
{
    ClearConstantGroups();
    m_pVertexShaderConstantMap = new NiD3DShaderConstantMap(g_pkRenderer, 0u);
    m_pPixelShaderConstantMap = new NiD3DShaderConstantMap(g_pkRenderer, 2u);
    m_iVertexShaderConstantCount = vertexCount + 3;
    if (m_iVertexShaderConstantCount > 0)
    {
        if (m_pfVertexShaderConstants)
            g_memoryManager.Deallocate(m_pfVertexShaderConstants);
        m_pfVertexShaderConstants =
            reinterpret_cast<float*>(new ImageSpaceShaderParamFloat[m_iVertexShaderConstantCount * 4]);
        m_pVertexShaderConstantMap.m_pObject->SetConstant(
            "Constant Group", 0x10000000, 0, 0, m_iVertexShaderConstantCount, "", m_iVertexShaderConstantCount * 16, 4,
            m_pfVertexShaderConstants, false);
    }
    m_iPixelShaderConstantCount = pixelCount;
    if (m_iPixelShaderConstantCount > 0)
    {
        if (m_pfPixelShaderConstants)
            g_memoryManager.Deallocate(m_pfPixelShaderConstants);
        m_pfPixelShaderConstants =
            reinterpret_cast<float*>(new ImageSpaceShaderParamFloat[m_iPixelShaderConstantCount * 4]);
        m_pPixelShaderConstantMap.m_pObject->SetConstant(
            "Constant Group", 0x10000000, 0, 0, m_iPixelShaderConstantCount, "", m_iPixelShaderConstantCount * 16, 4,
            m_pfPixelShaderConstants, false);
    }
}

// Writes the four floats x, y, z and w into the float array at the given index times four.
// @fnv 0x00b8a790
void ImageSpaceShaderParam::SetShaderConstantVector4(int index, float x, float y, float z, float w)
{
    index *= 4;
    m_pfPixelShaderConstants[index] = x;
    m_pfPixelShaderConstants[index + 1] = y;
    m_pfPixelShaderConstants[index + 2] = z;
    m_pfPixelShaderConstants[index + 3] = w;
}

// @fnv 0x00b8a8d0
void ImageSpaceShaderParam::SetRenderState(unsigned int state, unsigned int value)
{
    m_kRenderStateMap.SetAt(state, value);
}

// Releases the object references and deallocates the two buffers, clearing each pointer to null.
// @fnv 0x00b8a7e0
// src: COMMUNITY 0x00b8a7e0
void ImageSpaceShaderParam::ClearConstantGroups()
{
    if (m_pVertexShaderConstantMap.m_pObject)
    {
        reinterpret_cast<NiRefObject*>(m_pVertexShaderConstantMap.m_pObject)->DecRefCount();
        m_pVertexShaderConstantMap.m_pObject = 0;
    }
    if (m_pPixelShaderConstantMap.m_pObject)
    {
        reinterpret_cast<NiRefObject*>(m_pPixelShaderConstantMap.m_pObject)->DecRefCount();
        m_pPixelShaderConstantMap.m_pObject = 0;
    }
    if (m_pfVertexShaderConstants)
    {
        g_memoryManager.Deallocate(m_pfVertexShaderConstants);
        m_pfVertexShaderConstants = 0;
    }
    if (m_pfPixelShaderConstants)
    {
        g_memoryManager.Deallocate(m_pfPixelShaderConstants);
        m_pfPixelShaderConstants = 0;
    }
}

// Copies size bytes from data into the parameter buffer at offset index*4.
// @fnv 0x00b8a8b0
void ImageSpaceShaderParam::CopyParamData(int index, const float* data, unsigned int size)
{
    fnv_zlib_memcpy(m_pfPixelShaderConstants + index * 4, data, size);
}

// @fnv 0x00b8a7c0
// src: COMMUNITY 0x00b8a7c0
void ImageSpaceShaderParam::SetBlurClearMode()
{
    m_eClearFlags = DAT_011f9440 ? NiRenderer::CLEAR_ALL : NiRenderer::CLEAR_NONE;
}

// View of ImageSpaceShaderParam: +0x3C is m_pfVertexShaderConstants (the first three vectors are reserved).
struct ImageSpaceVertexConstantsView
{
    char _0[0x3C];
    float* _pf;
    void SetFloat4At(int aiIndex, float f0, float f1, float f2, float f3);
};
// Writes four floats f0..f3 into the float array at offset aiIndex*4+12.
// @fnv 0x00b8a760
void ImageSpaceVertexConstantsView::SetFloat4At(int aiIndex, float f0, float f1, float f2, float f3)
{
    int idx = aiIndex * 4 + 12;
    _pf[idx] = f0;
    _pf[idx + 1] = f1;
    _pf[idx + 2] = f2;
    _pf[idx + 3] = f3;
}

struct FUN_00b8a860_shell
{
    char _pad[0x44];
    float* m_44;
    void SetEntry(int idx, float* src);
};
// Copies the four floats from src into the float array at m_44 at the slot given by idx.
// @fnv 0x00b8a860
void FUN_00b8a860_shell::SetEntry(int aiIndex, float* apSource)
{
    float fSrc1 = apSource[1];
    float fSrc2 = apSource[2];
    float fSrc3 = apSource[3];
    int iOffset = aiIndex * 4;
    float* pDest = m_44;
    pDest[iOffset] = apSource[0];
    pDest[iOffset + 1] = fSrc1;
    pDest[iOffset + 2] = fSrc2;
    pDest[iOffset + 3] = fSrc3;
}

struct ShaderConstants_4e30
{
    void SetReferenceVector(int idx, float f0, float f1, float f2, float f3);
    void SetEntry(int idx, float* src);
};

struct ShaderParamOwner_4e30
{
    ShaderConstants_4e30* pShader;
};

struct PointData_4e30
{
    float x;
    float y;
    float z;
    float radius;
};

struct LightData_4e30
{
    float x;
    float y;
    float z;
    float radius;
    float r;
    float g;
    float b;
    float a;
    float p20;
    float p24;
    float p28;
    float p2C;
};

struct ParamColor_4e30
{
    float r;
    float g;
    float b;
    float a;
};

inline float MaxF_4e30(float a, float b)
{
    return a > b ? a : b;
}

struct ShaderPass_4e30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ShaderParamOwner_4e30* pOwner;
    int unk20;
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
    bool bUsePoint;
    char unk59;
    char unk5A;
    char unk5B;
    PointData_4e30* pPoint;
    LightData_4e30* apTargetLight;
    int unk64;
    ParamColor_4e30 kColor;

    bool ImageSpaceEffectCinematic_UpdateParams(int arg);
};

// Sets a shader reference vector and three parameter vectors, using pPoint coordinates for the first when bUsePoint is set.
// @fnv 0x00c04e30
// src: COMMUNITY 0x00c04e30
bool ShaderPass_4e30::ImageSpaceEffectCinematic_UpdateParams(int arg)
{
    ShaderConstants_4e30* pShader = pOwner->pShader;
    float fRadius;
    ParamColor_4e30 kParam1;
    ParamColor_4e30 kParam3 = kColor;
    ParamColor_4e30 kParam2;
    if (bUsePoint)
    {
        fRadius = MaxF_4e30(pPoint->radius, apTargetLight->radius);
        kParam1.r = pPoint->x;
        kParam1.g = pPoint->y;
        kParam1.b = pPoint->z;
        kParam1.a = 1.0f;
        kParam3.b = 1.0f;
        kParam3.a = 1.0f;
    }
    else
    {
        fRadius = apTargetLight->radius;
        kParam1.r = apTargetLight->r;
        kParam1.g = apTargetLight->g;
        kParam1.b = apTargetLight->b;
        kParam1.a = apTargetLight->a;
    }
    kParam2.r = apTargetLight->p20;
    kParam2.g = apTargetLight->p24;
    kParam2.b = apTargetLight->p28;
    kParam2.a = apTargetLight->p2C;
    pShader->SetReferenceVector(0, apTargetLight->x, apTargetLight->y, apTargetLight->z, fRadius);
    pShader->SetEntry(1, &kParam1.r);
    pShader->SetEntry(2, &kParam2.r);
    pShader->SetEntry(3, &kParam3.r);
    return false;
}
