#pragma once

class ChallengeData
{
public:
    void SwapEndianFields();

    int m_iPrimaryValue;
    int m_iAuxiliaryValue;
    unsigned short nFlags;
    unsigned char layoutPaddingA[2];
    int m_iRecordIndex;
    unsigned short FlaggedRecordValueEntry;
    unsigned short RecordIndexValueData;
    unsigned short IndexedRecordValueTriple;
    unsigned char layoutPadding16[2];
};
