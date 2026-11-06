#pragma once

class ImageSpaceModifierParameterData
{
public:
    float m_afFirstParameterSet[15];
    float m_afSecondParameterSet[3];
    float m_afThirdParameterSet[3];
    float m_afFourthParameterSet[4];
    float m_afColorAndAlphaParameters[12];
    unsigned int ShaderConstantData;

    void Endian();
};
