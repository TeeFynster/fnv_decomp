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
    EntryData* InventoryChanges_GetInventoryItem(TESForm*, int);

    InventoryChanges* pChanges;
};
