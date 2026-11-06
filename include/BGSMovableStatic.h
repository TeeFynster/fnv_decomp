#pragma once

#include "TESFullName.h"
#include "BGSDestructibleObjectForm.h"
#include "TESObjectSTAT.h"

class TESSound;

class BGSMovableStatic : public TESFullName, public BGSDestructibleObjectForm, public TESObjectSTAT
{
public:
    BGSMovableStatic();

    // TESForm vftable slot 5 (0x01024cec[5] = 0x004fbb50): clears soundLoop; called directly by the ctor
    virtual void InitializeComponent();

    TESSound* soundLoop;
    unsigned char data;
    unsigned char unk71[3];
};
