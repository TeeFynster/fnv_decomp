#pragma once

class WaterShaderSettings
{
public:
    WaterShaderSettings();

    float SplatterSettings;
    float m_fSecondParameter;
    float m_fThirdParameter;
    float m_fFourthSetting;
    float SevenFloatParameterData;
    float SevenFloatParameters;
    float SevenFloatData;
    float m_fEighthParameter;
    float FiveFloatAndTwoUnsignedIntegerRecord;
    float FourFloatAndThreeUnsignedIntegerRecord;
    unsigned int FloatColorSettingsRecord;
    unsigned int ShaderColorParameterBlock;
    unsigned int ColorSettingsRecord;
    unsigned char m_ucSplatterMode;
    unsigned char layoutPadding35[3];
    float SplatterColorSettings;
    float SplatterScalarSettings;
    float SplatterFloatSettings;
    float SplatterParameterSet;
    float SplatterTimingSettings;
    float SevenFloatRecordWithGlobals;
    float SevenFloatRecordWithStepAndGlobals;
    float SevenFloatRecordWithStep;
    float SevenFloatFormatBlock;
    float SevenFloatRecordWithUnitValue;
    float SevenFloatParameterSet;
    float SevenFloatParameterCollection;
    float SevenFloatParameterGroup;
    float SevenFloatValues;
    float SevenFloatSet;
    float SevenFloatBlock;
    float WaterFogParameters;
    float m_fWaterFogParameter1;
    float m_fValueBeforeWaterFogSettings;
    float WaterFogSettings;
    float WaterFogParameterData;
    float fUnderwaterFogAmount;
    float fUnderwaterFogDistNear;
    float fUnderwaterFogDistFar;
    float WaterShaderProperties;
    float m_fShininess;
    float WaterShaderParameters;
    float MaterialParametersWithLeadingFloat;
    float MaterialParameters;
    float m_fWaterParameter1;
    float m_fWaterParameter2;
    float m_fWaterParameter3;
    float m_fWaterParameter4;
    float m_fWaterParameter5;
    float m_fWaterParameter6;

    void Initialize();
    void Endian();
};
