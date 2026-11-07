// fallout/misc/bgsmovieplayer.cpp: BGSMoviePlayer (16 functions)

#include "../../../include/BGSMoviePlayer.h"
#include "../../../include/NiRenderer.h"
#include "bgsmovieplayer_decls.h"

// @fnv 0x00867290
Direct3DDeviceInterface* BGSMoviePlayer::GetDevice()
{
    NiRenderer* renderer = Renderer_GetNIRenderer();
    return renderer->NiXenonRenderer_GetD3DDevice();
}

// @fnv 0x008672b0
void BGSMoviePlayer::StartScene()
{
    NiRenderer* renderer = Renderer_GetNIRenderer();
    renderer->StartScene();
}

// @fnv 0x008672d0
void BGSMoviePlayer::FinishScene()
{
    NiRenderer* renderer = Renderer_GetNIRenderer();
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
    NiRenderer* renderer = Renderer_GetNIRenderer();
    return renderer->FUN_004e9530() == 1;
}

// @fnv 0x00867220
void BGSMoviePlayer::EndMoviePlayback()
{
    if (DAT_011de714 && BSAudio_QInstance()->TESRegionData_GetPriority())
    {
        BSAudio_QInstance()->SetUseMultipleThreads(false);
        DAT_011de714 = 0;
    }
    BSAudio_QInstance()->DisableAudioPlayback();
}

// Returns the result of FUN_004de0e0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns FUN_004dc1f0.
// @fnv 0x008672f0
unsigned int BGSMoviePlayer::UpdateInterfaceState()
{
    if (is_bEyeFinity() && IsEyefinity())
        return (unsigned int)Get_1280_();
    return Renderer_GetScreenWidth();
}

// Returns the result of FUN_004de0f0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns FUN_004dc200.
// @fnv 0x00867340
unsigned int BGSMoviePlayer::GetFirstInterfaceFloat()
{
    if (is_bEyeFinity() && IsEyefinity())
        return (unsigned int)Get_720_();
    return Renderer_GetScreenHeight();
}

// @fnv 0x008671a0
void BGSMoviePlayer::BeginMoviePlayback()
{
    if (!BSAudio_QInstance()->TESRegionData_GetPriority())
    {
        BSAudio_QInstance()->SetUseMultipleThreads(true);
        DAT_011de714 = 1;
    }
    BSAudio_QInstance()->BSAudio_PauseWorldSounds();
    if (!BSAudio_QInstance()->TESRegionData_GetPriority())
    {
        DAT_011de714 = 0;
        BSAudio_QInstance()->Update(true);
        BSAudio_QInstance()->Update(true);
    }
}

// @fnv 0x00867440
bool BGSMoviePlayer::UpdateMoviePlayback(bool continuePlaying)
{
    int deviceStatus;

    if (!FUN_00ec1840(continuePlaying))
        return false;

    deviceStatus = NiXenonRenderer_GetRenderer()->NiXenonRenderer_GetD3DDevice()->TestCooperativeLevel();
    if (deviceStatus < 0)
        return false;

    if (continuePlaying || field_20)
    {
        InputManager* wheel = g_osGlobals->Main_GetControls();
        wheel->Controls_UpdateValues();
        if (wheel->Controls_GetUserAction(5, true) || wheel->Controls_GetUserAction(0x1c, true))
        {
            if (MoviePlayer_GetPlayingSequence())
                FUN_00ec29b0();
            wheel->Controls_UpdateValues();
            return false;
        }
    }
    return true;
}

// Returns the screen width override from FUN_004de0e0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns 0.
// @fnv 0x00867390
unsigned int BGSMoviePlayer::GetScreenWidthOverride()
{
    if (is_bEyeFinity() && IsEyefinity())
        return (unsigned int)Get_1280_();
    return 0;
}

extern "C" float DAT_01189494;

// @fnv 0x004de0e0
// src: COMMUNITY 0x004de0e0
float Get_1280_()
{
    return DAT_01189494;
}

void __cdecl FalloutAudioMedia_MediaPause(void);
// @fnv 0x00867270
// src: XBOX_PDB 0x00867270
void __thiscall BGSMoviePlayer::PauseMusic()
{
    FalloutAudioMedia_MediaPause();
}

void _Deallocate(void*);
// Calls FUN_00867180, then deallocates this if the low bit of flags is set, and returns this.
// @fnv 0x00867150
void* __thiscall BGSMoviePlayer::FUN_00867150(unsigned int flags)
{
    UpdateFields_00867180();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl ResetThreadFlags(void);
// @fnv 0x00867280
// src: XBOX_PDB 0x00867280
void __thiscall BGSMoviePlayer::UnPauseMusic()
{
    ResetThreadFlags();
}

extern int DAT_01082564;
struct FUN_00ec15e0_shell
{
    void __thiscall FUN_00ec15e0();
};

// @fnv 0x00867180
// src: GUESS 0x00867180 (confidence: low)
void __thiscall BGSMoviePlayer::UpdateFields_00867180()
{
    *(void**)this = &DAT_01082564;
    ((FUN_00ec15e0_shell*)this)->FUN_00ec15e0();
}
