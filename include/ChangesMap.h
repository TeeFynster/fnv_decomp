#pragma once

#include "NiTPointerMap.h"

class ChangeData;
class TESForm;

class ChangesMap : public NiTPointerMap<unsigned int, ChangeData*>
{
public:
    virtual ~ChangesMap();
    virtual void DeleteAllEntries();

    ChangesMap();
    bool HasFormChanges(TESForm*, bool);
    bool RemoveChanges(unsigned int, bool);
};
