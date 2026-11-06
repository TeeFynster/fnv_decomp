#pragma once

#include "BSExtraData.h"
class BGSEncounterZone;

class __declspec(align(8)) ExtraEncounterZone : public BSExtraData
{
public:
    ExtraEncounterZone();

    virtual bool Compare(BSExtraData* extra);

    BGSEncounterZone* m_pEncounterZone;
};
