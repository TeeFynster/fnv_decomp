// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/MemoryManager.h"
#include "../../../include/NiPoint3.h"

#include "../../../include/BSAudioListener.h"

// @fnv 0x00aeaad0
NiPoint3& BSAudioListener::FUN_00aeaad0()
{
    return m_kListenerPosition;
}

// @fnv 0x00aeaaf0
NiPoint3* BSAudioListener::FUN_00aeaaf0()
{
    return &m_kListenerVelocity;
}

// @fnv 0x00aeab10
NiPoint3& BSAudioListener::FUN_00aeab10()
{
    return m_kForward;
}

// @fnv 0x00aeab30
void BSAudioListener::FUN_00aeab30(float afGain)
{
    m_fDistanceScale = afGain;
}

// @fnv 0x00aeab90
void BSAudioListener::SetRolloffFactor(float afRolloffFactor)
{
    m_fDopplerScale = afRolloffFactor;
}

extern MemoryManager g_memoryManager;
extern int DAT_010a3bb4;

// Sets the vtable pointer, clears the flags, and deallocates this when bit 0 is set; returns this.
// @fnv 0x00aeabb0
void* BSAudioListener::Destroy(unsigned int auiFlags)
{
    *reinterpret_cast<void**>(this) = &DAT_010a3bb4;
    m_uiListenerFlags = 0;
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
