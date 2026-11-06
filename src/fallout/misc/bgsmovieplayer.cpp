// fallout/misc/bgsmovieplayer.cpp: BGSMoviePlayer (16 functions)

#include "../../../include/BGSMoviePlayer.h"
#include "../../../include/NiRenderer.h"
#include "bgsmovieplayer_decls.h"

// @fnv 0x00867290
Direct3DDeviceInterface* BGSMoviePlayer::GetDevice()
{
    NiRenderer* renderer = FUN_004bc3f0();
    return renderer->FUN_004dc020();
}

// @fnv 0x008672b0
void BGSMoviePlayer::StartScene()
{
    NiRenderer* renderer = FUN_004bc3f0();
    renderer->StartScene();
}

// @fnv 0x008672d0
void BGSMoviePlayer::FinishScene()
{
    NiRenderer* renderer = FUN_004bc3f0();
    renderer->FinishScene();
}

// @fnv 0x00867410
unsigned int BGSMoviePlayer::GetUptimeMilliseconds()
{
    if (g_osGlobals)
        return g_osGlobals->GetUptimeMilliseconds();
    return 0;
}

// Returns whether the current NiRenderer reports a value of 1 from FUN_004e9530.
// @fnv 0x008673e0
bool BGSMoviePlayer::IsDeviceReady()
{
    NiRenderer* renderer = FUN_004bc3f0();
    return renderer->FUN_004e9530() == 1;
}

// @fnv 0x00867220
void BGSMoviePlayer::EndMoviePlayback()
{
    if (DAT_011de714 && FUN_00453a70()->FUN_005bb4d0())
    {
        FUN_00453a70()->SetUseMultipleThreads(false);
        DAT_011de714 = 0;
    }
    FUN_00453a70()->DisableAudioPlayback();
}

// Returns the result of FUN_004de0e0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns FUN_004dc1f0.
// @fnv 0x008672f0
unsigned int BGSMoviePlayer::UpdateInterfaceState()
{
    if (FUN_004de070() && FUN_004de080())
        return (unsigned int)FUN_004de0e0();
    return FUN_004dc1f0();
}

// Returns the result of FUN_004de0f0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns FUN_004dc200.
// @fnv 0x00867340
unsigned int BGSMoviePlayer::GetFirstInterfaceFloat()
{
    if (FUN_004de070() && FUN_004de080())
        return (unsigned int)FUN_004de0f0();
    return FUN_004dc200();
}

// @fnv 0x008671a0
void BGSMoviePlayer::BeginMoviePlayback()
{
    if (!FUN_00453a70()->FUN_005bb4d0())
    {
        FUN_00453a70()->SetUseMultipleThreads(true);
        DAT_011de714 = 1;
    }
    FUN_00453a70()->FUN_007eb8a0();
    if (!FUN_00453a70()->FUN_005bb4d0())
    {
        DAT_011de714 = 0;
        FUN_00453a70()->Update(true);
        FUN_00453a70()->Update(true);
    }
}

// @fnv 0x00867440
bool BGSMoviePlayer::UpdateMoviePlayback(bool continuePlaying)
{
    int deviceStatus;

    if (!FUN_00ec1840(continuePlaying))
        return false;

    deviceStatus = FUN_0043c4b0()->FUN_004dc020()->TestCooperativeLevel();
    if (deviceStatus < 0)
        return false;

    if (continuePlaying || field_20)
    {
        InputManager* wheel = g_osGlobals->FUN_00877720();
        wheel->FUN_00a23010();
        if (wheel->FUN_00a24660(5, true) || wheel->FUN_00a24660(0x1c, true))
        {
            if (FUN_00ec17c0())
                FUN_00ec29b0();
            wheel->FUN_00a23010();
            return false;
        }
    }
    return true;
}

// Returns the screen width override from FUN_004de0e0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns 0.
// @fnv 0x00867390
unsigned int BGSMoviePlayer::GetScreenWidthOverride()
{
    if (FUN_004de070() && FUN_004de080())
        return (unsigned int)FUN_004de0e0();
    return 0;
}

extern "C" float DAT_01189494;

// @fnv 0x004de0e0
float FUN_004de0e0()
{
    return DAT_01189494;
}

void __cdecl FUN_008305e0(void);
// @fnv 0x00867270
void __thiscall BGSMoviePlayer::FUN_00867270()
{
    FUN_008305e0();
}

void _Deallocate(void*);
// Calls FUN_00867180, then deallocates this if the low bit of flags is set, and returns this.
// @fnv 0x00867150
void* __thiscall BGSMoviePlayer::FUN_00867150(unsigned int flags)
{
    FUN_00867180();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl ResetThreadFlags(void);
// @fnv 0x00867280
void __thiscall BGSMoviePlayer::FUN_00867280()
{
    ResetThreadFlags();
}

extern int DAT_01082564;
struct FUN_00ec15e0_shell
{
    void __thiscall FUN_00ec15e0();
};

// @fnv 0x00867180
void __thiscall BGSMoviePlayer::FUN_00867180()
{
    *(void**)this = &DAT_01082564;
    ((FUN_00ec15e0_shell*)this)->FUN_00ec15e0();
}
