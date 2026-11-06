#pragma once

#include "TESForm.h"

class EncounterZoneData
{
public:
    void Endian();

    TESForm* m_pOwnerForm;
    char m_cRank;
    unsigned char m_ucByteBeforeFlags;
    char cFlags;
    unsigned char layoutPadding7[1];
};
