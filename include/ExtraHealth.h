#pragma once

#include "BSExtraData.h"

class ExtraHealth : public BSExtraData
{
public:
    bool Compare(BSExtraData* extra) override;

    ExtraHealth(float health);
    ExtraHealth(void* a, void* b, void* c);

    static void* __cdecl operator new(unsigned int size);
    static void operator delete(void* pointer);

    float fHealthPercent;
};
