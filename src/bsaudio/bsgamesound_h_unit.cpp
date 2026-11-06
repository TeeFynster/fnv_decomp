
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsgamesound.h header unit.
//
// The original build compiled bsaudio/bsgamesound.h inside an audio
// translation unit. This translation unit plays that role for the matcher
// build: it includes the header unit and references the covered functions
// so the compiler emits their COMDAT bodies the same way the original
// translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "../../include/BSGameSound.h"

// @fnv 0x00ae9ef0
inline bool BSGameSound::IsPlaying()
{
    return (iStateFlags & 0x20) != 0;
}

// @fnv 0x00ae9f10
inline bool BSGameSound::HasStatusFlag0x80000()
{
    return (iStateFlags & 0x80000) != 0;
}

// @fnv 0x00ae9f30
inline bool BSGameSound::IsPaused()
{
    return (iStateFlags & 0x40) != 0;
}

// @fnv 0x00ae9f50
inline float BSGameSound::GetVolume()
{
    return fCurrentVolume;
}

// @fnv 0x00ae9fb0
inline void BSGameSound::SetListenerID(unsigned int uiEnvironmentType)
{
    iEnvironmentType = uiEnvironmentType;
}

void BSGameSoundEmitCoveredFunctions()
{
    BSGameSound* sound = 0;
    // Qualified calls: keep the inline bodies in this object file.
    sound->BSGameSound::IsPlaying();
    sound->BSGameSound::HasStatusFlag0x80000();
    sound->BSGameSound::IsPaused();
    sound->BSGameSound::GetVolume();
    sound->BSGameSound::SetListenerID(0);
}
