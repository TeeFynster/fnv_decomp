#pragma once

#include "BSExtraData.h"

class EntryData;
class InventoryChanges;
class TESForm;

class ExtraContainerChanges : public BSExtraData
{
public:
    virtual ~ExtraContainerChanges();

    ExtraContainerChanges(InventoryChanges* changes);
    EntryData* FUN_004d0650(TESForm*, int);

    InventoryChanges* pChanges;
};
