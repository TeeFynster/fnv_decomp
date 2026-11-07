#pragma once

#include "MoviePlayer.h"

class Direct3DDeviceInterface;

#pragma pack(push, 1)
class BGSMoviePlayer : public MoviePlayer
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void BeginMoviePlayback();
    virtual void EndMoviePlayback();
    virtual void vf03();
    virtual void vf04();
    virtual Direct3DDeviceInterface* GetDevice();
    virtual void StartScene();
    virtual void FinishScene();
    virtual unsigned int UpdateInterfaceState();
    virtual unsigned int GetFirstInterfaceFloat();
    virtual bool IsDeviceReady();
    virtual unsigned int GetScreenWidthOverride();
    virtual unsigned int GetUptimeMilliseconds();
    virtual bool UpdateMoviePlayback(bool continuePlaying);

    unsigned char unk10[0x20 - sizeof(MoviePlayer)];
    unsigned char field_20;

    void* __thiscall FUN_00867150(unsigned int flags);
    void __thiscall UpdateFields_00867180();
    void __thiscall PauseMusic();
    void __thiscall UnPauseMusic();
    bool FUN_00ec1840(bool);
    bool MoviePlayer_GetPlayingSequence();
    void FUN_00ec29b0();

    bool CheckPlaybackContinue(bool allowInterruption);
    bool IsPlaying();
    void RequestInterruption();
    void StartPlayback(const char*, int, int, int, int, float);
    void ClearMovieJob();
    void __thiscall SetPlaybackOption(int);
};
#pragma pack(pop)
