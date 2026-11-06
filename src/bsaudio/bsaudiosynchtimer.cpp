#include "../../include/BSAudioSyncTimer.h"
// bsaudio/bsaudiosynchtimer.cpp: free functions (1 function)

#include <windows.h>
// src/bsaudio/bsaudiosynchtimer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsaudio/bsaudiosynchtimer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "BSAudioSyncTimer.h"



// Computes the elapsed time since the last call and, when iFlags bit 0 is clear, adds it to m_uiValueAt00, then stores the current tick count in m_uiValueAt04.
// @fnv 0x00aea100
void BSAudioSyncTimer::UpdateAccumulatedTime()
{
    unsigned int now = GetTickCount();
    unsigned int delta = now - m_uiValueAt04;
    if ((unsigned char)(((iFlags & 1) != 0) ? 1 : 0) == 0)
    {
        m_uiValueAt00 += delta;
    }
    m_uiValueAt04 = now;
}
