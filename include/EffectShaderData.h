#pragma once

#include "NiPoint3.h"

class BGSDebris;

#include "_D3DBLEND.h"
#include "_D3DBLENDOP.h"
#include "_NDLZCMPFUNC.h"
class EffectShaderData
{
  public:
    EffectShaderData();
    void Initialize();
    void Endian();
    unsigned char cFlags;
    unsigned char layoutPadding1[3];
    _D3DBLEND m_eDestinationBlend;
    _D3DBLENDOP m_eBlendOperation;
    _NDLZCMPFUNC m_eDepthCompareFunction;
    unsigned int BlendDepthState;
    float BlendDepthParameters;
    float DepthCompareParameters;
    float IndexedFloatParameters;
    float ShaderFloatParameterSet;
    float ShaderParameterFormatSet;
    float SevenFloatParameterRecord;
    float SixFloatAndUnsignedIntegerRecord;
    float SixFloatUnsignedIntegerAndFloatRecord;
    float ExtendedFloatFlagParameters;
    unsigned int ShaderFloatParameterBlock;
    float SixFloatRecordWithMiddleFlag;
    float FloatFlagParameters;
    float SixFloatRecordWithLeadingFlag;
    float BlendFloatParameters;
    float AlphaBlendParameters;
    float BlendStateParameters;
    float BlendFactorState;
    float BlendModeConfiguration;
    _D3DBLEND m_eSourceBlend;
    _D3DBLEND m_eAlphaSourceBlend;
    _D3DBLENDOP m_eAlphaBlendOperation;
    _NDLZCMPFUNC m_eAlphaDepthCompareFunction;
    _D3DBLEND m_eAlphaDestinationBlend;
    float AlphaBlendSettings;
    float m_fAlphaBlendParameter;
    float BlendFactorParameters;
    float m_fShaderFloatParameter1;
    float m_fShaderFloatParameter2;
    float m_fShaderFloatParameter3;
    float m_fShaderFloatParameter4;
    float m_fShaderFloatParameter5;
    float m_fShaderFloatParameter6;
    NiPoint3 VelocityState;
    NiPoint3 m_kVectorState2;
    float m_fShaderFloatParameter7;
    float m_fShaderFloatParameter8;
    float m_fShaderFloatParameter9;
    float m_fShaderFloatParameter10;
    unsigned int m_uiColorParameter1;
    unsigned int m_uiColorParameter2;
    unsigned int m_uiColorParameter3;
    float m_fShaderFloatParameter11;
    float m_fShaderFloatParameter12;
    float m_fShaderFloatParameter13;
    float m_fShaderFloatParameter14;
    float m_fShaderFloatParameter15;
    float m_fShaderFloatParameter16;
    float m_fShaderFloatParameter17;
    float m_fShaderFloatParameter18;
    float m_fShaderFloatParameter19;
    float m_fShaderFloatParameter20;
    float m_fShaderFloatParameter21;
    BGSDebris* pAddonModels;
    float DebrisModelSettings;
    float EffectShaderAddonData;
    float DebrisColorSettings;
    float EffectShaderColorData;
    float EffectShaderParameters;
    unsigned int m_uiBaseColor;
    float m_fFloatAfterDefaultColor;
    unsigned int m_uiIntegerParameter1;
    unsigned int m_uiIntegerParameter2;
    float m_fFirstValueAfterIntegerFields;
    float m_fSecondValueAfterIntegerFields;
    float UnsignedIntAndSixFloatData;
    float SixFloatValueSet;
    float FiveFloatData;
    float FourFloatValueSet;
};
