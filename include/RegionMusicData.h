#pragma once

#include "MagicTarget.h"

class BGSMusicType;
class RegionSoundEntry;

class RegionMusicData
{
public:
    BGSMusicType* pType;
    BSSimpleList<RegionSoundEntry*> soundList;
    unsigned int uiIncidentalMediaSet;
    BSSimpleList<unsigned int> battleMediaSetList;
};
