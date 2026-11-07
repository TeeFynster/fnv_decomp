#pragma once

#include "BSExtraData.h"

class ExtraReflectorRefs : public BSExtraData
{
public:
    struct Item
    {
        Item();

        unsigned int key;
        unsigned int val;
    };

    // BSSimpleList<Item*>: constructor 0x0096a2d0, destructor 0x0046ffb0 (0x00411be0, 0x00434af0).
    struct Node
    {
        Node();
        ~Node();
        void RemoveAll();

        Item* item;
        Node* next;

        bool FUN_008256d0();
        Item** FUN_006815c0();
        Node* FUN_00726070();
        int FUN_005ae380();
    };

    virtual ~ExtraReflectorRefs();
    virtual bool Compare(BSExtraData* extra);

    ExtraReflectorRefs();
    void Copy(BSExtraData* apExtra);

    Item* FUN_00434410(unsigned int key);
    bool Compare_00434bb0(BSExtraData* apCompare);
    void* __thiscall FUN_00434af0();
    void* __thiscall FUN_00411c50(unsigned int flags);

    Node list;
};
