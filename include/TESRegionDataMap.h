#pragma once

#include "TESRegionData.h"
#include "TESFullName.h"

class TESFile;

class TESRegionDataMap : public TESRegionData
{
public:
    BSStringT<char> m_kMapName;

    TESRegionDataMap();
    TESRegionDataMap(const TESRegionDataMap* apSource);
    virtual ~TESRegionDataMap();
    virtual bool LoadRegionMapData(TESFile* apFile);
    virtual void vf10(BSStringT<char>& apMapName);
    virtual const char* GetRegionMapName();
    virtual bool vf12(const char* apMapName);
};
