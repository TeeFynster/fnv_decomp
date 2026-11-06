#pragma once

#include "NiGeometryGroup.h"
#include "NiTPrimitiveArray.h"

class NiVBDynamicSet;
class NiVBChip;

template <class T> class DynamicMapBase
{
public:
    DynamicMapBase();
    virtual void Slot();

    unsigned int size;
    void* table;
    unsigned int count;
};

template <class T> class DynamicMap : public DynamicMapBase<T>
{
public:
    DynamicMap();
    virtual void Slot();
};





class NiDynamicGeometryGroup : public NiGeometryGroup
{
public:
    NiDynamicGeometryGroup();
    virtual void Purge();
    virtual ~NiDynamicGeometryGroup();

    DynamicMap<NiVBDynamicSet> sets;
    DynamicMap<NiVBChip> chips;
    // src: XBOX_PDB (NiTPrimitiveArray<NiVBDynamicSet *> / <NiVBChip *>); ctor 0x00e957b0.
    NiTPrimitiveArray<NiVBDynamicSet*> streamSets;
    NiTPrimitiveArray<NiVBChip*> streamChips;
    unsigned int nextIndex;
};
