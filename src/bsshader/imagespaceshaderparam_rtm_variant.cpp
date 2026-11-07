// src/bsshader/imagespaceshaderparam_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/bsshader/imagespaceshaderparam.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// The legacy unit headers must use the shared NiRefObject base.
#define FNV_NIREFOBJECT_H
#include "../../include/NiFixedString.h"
#include "../../include/NiObject.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiTexture.h"
#include "imagespaceshaderparam_decls.h"
#include "imagespaceshaderparam_types_NiD3DShaderConstantMap.h"
#include "imagespaceshaderparam_types_ImageSpaceShaderParam.h"
#include "../../include/ImageSpaceTexture.h"
// View of ImageSpaceShaderParam: +0x3C is m_pfVertexShaderConstants (the first three vectors are reserved).
struct ImageSpaceVertexConstantsView
{
    char _0[0x3C];
    float* _pf;
    void SetFloat4At(int aiIndex, float f0, float f1, float f2, float f3);
};
struct FUN_00b8a860_shell
{
    char _pad[0x44];
    float* m_44;
    void SetEntry(int idx, float* src);
};
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


extern float g_fBlurBase;
extern float g_fBlurScale;
extern float g_fBlurOne;
extern float g_afBlurKernel[15][4];
extern float g_afBlurWeights[8][15][4];

struct BlurParamArray
{
    void* m_ppVirtualMethodTable;
    ImageSpaceShaderParam** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    ImageSpaceShaderParam*& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct BlurTexArray
{
    void* m_ppVirtualMethodTable;
    const ImageSpaceTexture** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    const ImageSpaceTexture*& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct ImageSpaceEffectFourTexturePass
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    BlurParamArray unk18;
    BlurTexArray unk28;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    bool unk5C;
    bool ImageSpaceEffectBlur_UpdateParams(int a1);
};

// @fnv 0x00ba4270
// src: COMMUNITY 0x00ba4270
bool ImageSpaceEffectFourTexturePass::ImageSpaceEffectBlur_UpdateParams(int a1)
{
    float m_fGlyphWidthInPixels = (float)unk28.GetAt(2)->GetTexture()->GetWidth();
    float m_fGlyphExtent = (float)unk28.GetAt(1)->GetTexture()->GetHeight();
    int iLevel = unk58;
    int iLo = iLevel - 1;
    int iHi = iLo + 1;
    if (iHi > 7)
        iHi = 7;
    if (iLo < 1)
        iLo = 1;
    int iStart = (7 - iHi) * 4;
    float fT = 1.0f - ((float)iLevel - g_fBlurBase);
    if (fT == 0.0f)
        fT = 1.0f;
    for (int i = 0; i < 15; i++)
        g_afBlurKernel[i][2] =
            (g_afBlurWeights[iHi - 1][i][2] - g_afBlurWeights[iLo - 1][i][2]) * fT + g_afBlurWeights[iLo - 1][i][2];
    ImageSpaceShaderParam* pParam = unk18.GetAt(0);
    m_fGlyphExtent = 1.0f / m_fGlyphExtent;
    pParam->SetShaderConstantVector4(0, 0.0f, m_fGlyphExtent, 0.0f, 0.0f);
    if (unk5C)
        pParam->SetShaderConstantVector4(17, g_fBlurScale, g_fBlurOne, 0.0f, 0.0f);
    pParam->CopyParamData(1, &g_afBlurKernel[0][iStart], (iHi * 2 + 1) * 16);
    pParam = unk18.GetAt(1);
    m_fGlyphWidthInPixels = 1.0f / m_fGlyphWidthInPixels;
    pParam->SetShaderConstantVector4(0, m_fGlyphWidthInPixels, 0.0f, 0.0f, 0.0f);
    pParam->CopyParamData(1, &g_afBlurKernel[0][iStart], (iHi * 2 + 1) * 16);
    return false;
}
