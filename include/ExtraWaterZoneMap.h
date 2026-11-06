#pragma once

#include "BSExtraData.h"
#include "DummyPointerMap.h"

class TESForm;

class ExtraWaterZoneMap : public BSExtraData
{
public:
    // RTTI: the member's ctor 0x004383b0 stores vftable 0x01015fbc, NiTMap<WaterZone *,int>
    // (: NiTMapBase<DFALL<NiTMapItem<WaterZone *,int> >,WaterZone *,int>); named for that until NiTMap.h is shared.
    class WaterZoneMap : public ::DummyPointerMap
    {
    public:
        WaterZoneMap(int);
        ~WaterZoneMap();
    };

    struct Cleanup
    {
        BSExtraData base;
        WaterZoneMap member;

        ~Cleanup();
    };

    ExtraWaterZoneMap();
    virtual ~ExtraWaterZoneMap();
    virtual bool Compare(BSExtraData* extra);

    void FUN_004377f0();
    void* FUN_004377c0(unsigned int flags);
    void UpdatePriorityEntry(TESForm* form, bool flag);

    WaterZoneMap m_map;
    void* pTarget;
};
