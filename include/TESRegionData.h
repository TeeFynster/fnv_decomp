#pragma once

class RegionDataEntry;
struct BaseRegionData;
class TESForm;
class TESRegion;
class RegionSound;
template <class T> class BSSimpleList;
enum REGION_DATA_ID;

class TESRegionData
{
public:
    bool bOverride;
    bool m_bHasRegionData;
    unsigned char m_ucRegionPriority;
    unsigned char layoutPadding7[1];

    TESRegionData();
    TESRegionData(const TESRegionData& other);
    virtual ~TESRegionData();
    virtual void Save();
    virtual bool ApplyEntry(RegionDataEntry* apBase);
    virtual void SetForm(TESForm* apForm);
    virtual REGION_DATA_ID GetType();
    virtual TESRegionData* Clone();
    virtual TESRegionData* CopyFrom(const TESRegionData* apSrc);
    virtual void SetFromData(const TESRegionData* apSrc, unsigned int auFlags);
    virtual bool IsValid();

    bool ApplyEntry(BaseRegionData* data);
    void Initialize(TESRegion* region);
    bool SetPriority(unsigned char priority);
    BSSimpleList<RegionSound*>* GetOffsetC();
};
