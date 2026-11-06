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
    bool FUN_00855220(unsigned int, bool);
};
