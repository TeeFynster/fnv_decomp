#pragma once

class EndianConvertibleData
{
public:
    float EndianFloatValue;
    float EndianMixedData;
    int FloatPairAndFourIntegerRecord;
    int FloatPairAndFiveIntegerRecord;
    int FloatAndSixIntegerRecord;
    int SevenIntegerRecord;
    int SevenIntegerRecordFromNextOffset;
    int m_iFourthRecordValue;
    int m_iFifthRecordValue;
    int m_iSixthRecordValue;
    int m_iFourthIntegerValue;
    unsigned int IntegerEndianRecord;
    unsigned int uiChunkType;
    bool m_bEndianFlag;
    unsigned char layoutPadding35[3];

    void Endian();
};
