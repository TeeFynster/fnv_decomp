#pragma once

#include "BSExtraData.h"

class TESObjectCELL;

class ExtraRadioData : public BSExtraData
{
public:
    struct RadioData
    {
        void RADIO_DATA_Copy(RadioData* other);

        char unk00[0x10];
    };

    ExtraRadioData();
    virtual ~ExtraRadioData();

    bool CompareRadioData(BSExtraData* extra);
    TESObjectCELL* DoorTeleportData_GetTeleportCell();

    union
    {
        unsigned char unk0C[0x10];
        RadioData data;
    };
};
