#pragma once

#include "CombatProcedure.h"

class CombatProcedureEvade : public CombatProcedure
{
public:
    unsigned char unk10[0x08];

    CombatProcedureEvade(int);

    void LoadGame(BGSLoadFormBuffer* apBuffer) override;
};
