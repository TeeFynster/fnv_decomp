#pragma once

#include "TESRegionData.h"
#include "RegionMusicData.h"

class BGSMusicType;
class MediaSet;
class TESFile;
class TESForm;

class TESRegionDataSound : public TESRegionData
{
public:
    RegionMusicData sounds;

    TESRegionDataSound();
    virtual ~TESRegionDataSound();
    virtual bool LoadRegionSoundData(TESFile* apFile);
    virtual BGSMusicType* GetMusicType();
    virtual void SetMusicType(BGSMusicType* apType);
    virtual TESForm* GetSoundForm();
    virtual int vf13();
    virtual void SetMediaSet(MediaSet* pMediaSet);
};
