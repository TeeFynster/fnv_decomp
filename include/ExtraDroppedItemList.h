#pragma once

#include "BSExtraData.h"

class DroppedItemNode;

class ExtraDroppedItemList : public BSExtraData
{
public:
    struct ListX
    {
        ListX();
        ~ListX();
        void RemoveAll();

        DroppedItemNode* head;
    };

    ExtraDroppedItemList();
    virtual ~ExtraDroppedItemList();

    void FUN_004359f0();
    void* __thiscall FUN_004359c0(unsigned int flags);

    ListX m_pInventoryEntryData;
};
