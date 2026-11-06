#pragma once

#include "BSExtraData.h"
#include "BSAnimNoteReceiver.h"

class ExtraAnimNoteReceiver : public BSExtraData
{
public:
    virtual ~ExtraAnimNoteReceiver();

    ExtraAnimNoteReceiver(void* receiver);
    void FUN_0057a8d0();
    void* FUN_0057a8a0(unsigned int flags);

    BSAnimNoteReceiver* m_pReceiver;
};
