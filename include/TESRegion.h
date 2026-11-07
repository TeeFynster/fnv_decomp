#pragma once

#include "TESForm.h"
#include "NiColor.h"

class RegionDataList;
class RegionPointList;
class TESWorldSpace;
class TESWeather;
class ListProxy;
class DataProxy;

class TESRegion : public TESForm
{
public:
    RegionDataList* m_pRegionDataList;
    BSSimpleList<RegionPointList*>* pRegionPointList;
    TESWorldSpace* m_pContainingWorldspace;
    TESWeather* m_pRegionWeather;
    float fWeatherChance;
    // NiColor-shaped (+0x2c): the constructor 0x004f0770 constructs no NiColor member, so not the shared NiColor
    float m_kDiffuseColor[3];

    TESRegion();
    virtual ~TESRegion();
    virtual void SaveForm();
    virtual void ClearData();
    virtual void InitItem();
    bool Load(TESFile* file);
    TESRegion* Clone(TESRegion* destination);
    void WarnCopyUnsupported(TESRegion* destination);
    ListProxy* FUN_00441110();
    DataProxy* NiAVObject_GetParent();
    void UpdateWeather();
    RegionDataList* GetRegionDataList() const;
    BSSimpleList<RegionPointList*>* GetRegionPointLists() const;
    TESWorldSpace* GetParentWorldSpace() const;
    void AssignWorldSpace(TESWorldSpace* world);
    RegionDataList* GetDataList();
    NiColor* GetDiffuseColor();
};
