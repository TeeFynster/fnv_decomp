#pragma once

#include "IBSAnimNoteReceiver.h"

class BSAnimNoteReceiver : public IBSAnimNoteReceiver
{
public:
    virtual ~BSAnimNoteReceiver();
    virtual void vf01();

    void __thiscall FUN_004b0480();
    void* __thiscall FUN_004b0580(unsigned int flags);
    void __thiscall DispatchNoteToReceivers(void* note);

    void* unk04;
    int unk08;
};
