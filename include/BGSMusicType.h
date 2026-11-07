#pragma once

#include "TESForm.h"
#include "TESSoundFile.h"
#include "MagicTarget.h"

struct BGSMusicType : public TESForm, public TESSoundFile
{
public:
    class MusicTrack
    {
    public:
        char m_acTrackName[260];

        MusicTrack(const char* name);
    };

    float fVolumeScale;
    BSSimpleList<MusicTrack*> m_kMusicFiles;
    unsigned int m_uiSelectedSoundIndex;

    BGSMusicType();
    virtual ~BGSMusicType();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();

    bool Load(TESFile* file);
    void UpdateLoadingStatusCallback();
    bool GetLooping();
    float GetAttenuation();
    const char* GetRandomEntry();
    void BGSMusicType_ClearData(); // exe 0x005913b0: clear the track list
};
