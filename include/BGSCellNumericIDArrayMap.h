#pragma once

#include "NiTMap.h"

template <class T, unsigned int N> class BSSimpleArray;

// RTTI: BGSCellNumericIDArrayMap : NiTMap<unsigned int,BSSimpleArray<unsigned int,1024> *>, vftable 0x0107fef4.
class BGSCellNumericIDArrayMap : public NiTMap<unsigned int, BSSimpleArray<unsigned int, 1024>*>
{
public:
    BGSCellNumericIDArrayMap();
    virtual ~BGSCellNumericIDArrayMap();
    void Clear();
    unsigned int GetOrCreateEntryAdd(unsigned int key, void* value);
    void RemoveReference(unsigned int key, unsigned int referenceID);
};
