#pragma once

#include "BSExtraData.h"

class ExtraTerminalState : public BSExtraData
{
public:
    ExtraTerminalState();
    bool __thiscall FUN_0041bf20();

    unsigned char padC;
    char m_cTerminalState;
    unsigned char unk0E[2];
};
