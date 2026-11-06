#pragma once

#include "TESRegionData.h"

class TESFile;
class TESRegionGrassObjectList;

class TESRegionDataGrass : public TESRegionData
{
public:
    TESRegionGrassObjectList* m_pObjectList;

    TESRegionDataGrass();
    virtual ~TESRegionDataGrass();
    virtual bool ReadGrassData(TESFile* apFile);
    virtual TESRegionGrassObjectList* vf10();
};
