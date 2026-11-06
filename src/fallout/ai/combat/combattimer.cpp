// fallout/ai/combat/combattimer.cpp: free functions (4 functions)

#include "combattimer_decls.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/CombatTargetTimestamp.h"
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
// Reads a 4-byte timestamp from the load buffer and, if it is within the relative range, offsets it by the current game time.
// @fnv 0x009a5ff0
void CombatTargetTimestamp::LoadGame(BGSLoadGameBuffer* pLoadBuffer)
{
    pLoadBuffer->ReadTypedData(static_cast<void*>(&fTimeStamp), 4u);
    if (fTimeStamp < DAT_0108e360 && fTimeStamp > -DAT_0108e360)
        fTimeStamp = Actor::GetActorScale() + fTimeStamp;
}
// @fnv 0x009a5f20
void TimeoutTimer::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(static_cast<void*>(&m_fStartTime), 4u);
    buffer->ReadTypedData(static_cast<void*>(&m_fTimeout), 4u);
    if (m_fStartTime < DAT_0108e360 && m_fStartTime > -DAT_0108e360)
        m_fStartTime = m_fStartTime + DAT_011f1bf0;
}

// @fnv 0x009a5eb0
void TimeoutTimer::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    float foffsetStartTime = this->m_fStartTime;
    if (this->m_fStartTime < DAT_0108e360 && -DAT_0108e360 < this->m_fStartTime)
        foffsetStartTime -= DAT_011f1bf0;
    apSaveGameBuffer->SaveData(&foffsetStartTime, 4, 0);
    apSaveGameBuffer->SaveData(&this->m_fTimeout, 4, 0);
}

// @fnv 0x009a5f90
void CombatTargetTimestamp::SaveTimeStamp(BGSSaveFormBuffer* apSaveGameBuffer)
{
    float fSavedTimeStamp = fTimeStamp;
    if (fTimeStamp < DAT_0108e360 && fTimeStamp > -DAT_0108e360)
    {
        fSavedTimeStamp -= Actor::GetActorScale();
    }
    apSaveGameBuffer->SaveData(&fSavedTimeStamp, 4, 0);
}
