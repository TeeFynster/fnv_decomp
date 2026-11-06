#pragma once

class TreeRecordData
{
public:
    void Endian();

    float m_fFirstRecordValue;
    float FiveFloatEndianRecord;
    float ShadowParameters;
    float m_fFourthShadowValue;
    float TreeVisualSettings;
    int m_iShadowRadius;
    float m_fRustleMagnitude;
    float m_fRustleSpeed;
};
