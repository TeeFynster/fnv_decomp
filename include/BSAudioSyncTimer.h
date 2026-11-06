#pragma once

class BSAudioSyncTimer
{
public:
    unsigned int m_uiValueAt00;
    unsigned int m_uiValueAt04;
    unsigned int iFlags;

    void UpdateAccumulatedTime(); // exe: 0x00aea100
};
