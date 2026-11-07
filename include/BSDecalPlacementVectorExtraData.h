#pragma once

#include "NiIntegerExtraData.h"

class BSDecalPlacementVectorExtraData : public NiIntegerExtraData
{
  public:
    struct ExtraList
    {
        void* head;
        void* tail;
        unsigned int size;

        ExtraList();
        ~ExtraList();
        void ReleaseStorage_00c64710();
    };

    BSDecalPlacementVectorExtraData(int value);
    virtual ~BSDecalPlacementVectorExtraData();
    void LinkToObject(void* apObject);
    // NiMemObject's operator new (0x00aa13e0), redeclared: blk_00c60000_od_ob1_variant's 0x00c63c30 inlines its body
    // for this class only, so that unit defines it inline here.
    static void* operator new(unsigned int size);

    unsigned short count;
    unsigned short unk12;
    void* groups[8];
    ExtraList list;
};
