#pragma once

class QuestData
{
public:
    unsigned char m_ucEntryType;
    unsigned char ucPriority;
    unsigned char layoutPadding2[2];
    float fQuestDelayTime;

    void __thiscall Endian();
};
