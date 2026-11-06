#pragma once

#include "NiTPointerMap.h"

class ExteriorCellReferenceData;
template <class T> class BSSimpleList;

class ExteriorCellNewReferencesMap
    : public NiTPointerMap<unsigned int, BSSimpleList<ExteriorCellReferenceData*>*>
{
public:
    virtual ~ExteriorCellNewReferencesMap();
    void* FUN_00855410(unsigned int flags);
    void FUN_00855440();
};
