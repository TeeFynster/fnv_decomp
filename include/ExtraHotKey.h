#pragma once

#include "BSExtraData.h"

class ExtraHotKey : public BSExtraData
{
public:
    ExtraHotKey();
    ExtraHotKey(char key);
    bool Compare(BSExtraData* apCompare);
    bool Compare_00432540(BSExtraData* apCompare);

    char cKey;
};
