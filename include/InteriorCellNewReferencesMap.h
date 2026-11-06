#pragma once

#include "NiTPointerMap.h"

template <class T> class BSSimpleList;

class InteriorCellNewReferencesMap
    : public NiTPointerMap<unsigned int, BSSimpleList<unsigned int>*>
{
public:
    virtual ~InteriorCellNewReferencesMap();

    void* FUN_00855310();
    void* __thiscall FUN_008552e0(unsigned int flags);
    void* FUN_004b9ba0();
    void FUN_006b7f20(void** node, unsigned int* key, BSSimpleList<unsigned int>** value);
    void FUN_00438af0();
};
