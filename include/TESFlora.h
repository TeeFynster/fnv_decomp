#pragma once

#include "TESProduceForm.h"
#include "TESObjectACTI.h"

class TESFlora : public TESProduceForm, public TESObjectACTI
{
public:
    TESFlora();

    void Copy_00508990(TESForm* apCopy);
};

typedef char TESFlora_size_check[(sizeof(TESFlora) == 0x9C) ? 1 : -1];
