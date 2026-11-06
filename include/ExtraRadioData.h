#pragma once

#include "BSExtraData.h"

class TESObjectCELL;

class ExtraRadioData : public BSExtraData
{
public:
    struct RadioData
    {
        void FUN_00437240(RadioData* other);

        char unk00[0x10];
    };

    ExtraRadioData();
    virtual ~ExtraRadioData();

    bool CompareRadioData(BSExtraData* extra);
    TESObjectCELL* FUN_0043a2b0();

    union
    {
        unsigned char unk0C[0x10];
        RadioData data;
    };
};
