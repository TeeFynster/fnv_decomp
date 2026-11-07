#pragma once

#include "BSExtraData.h"

class ExtraTerminalState : public BSExtraData
{
public:
    ExtraTerminalState();
    bool __thiscall IsLockedState();

    unsigned char padC;
    char m_cTerminalState;
    unsigned char unk0E[2];
};
