
// src/fallout_shared/bsanimnotereceiver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bsanimnotereceiver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiFormArray.h"
#include "../../include/BSAnimNoteReceiver.h"
#include "../../include/IBSAnimNoteReceiver.h"

void __cdecl _Deallocate(void*);

// Calls FUN_004b0530, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x004b0550
void* IBSAnimNoteReceiver::FUN_004b0550(unsigned int flags)
{
    SetVtableAndProcessState_004b0530();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Calls FUN_004b0480, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004b0580
void* __thiscall BSAnimNoteReceiver::FUN_004b0580(unsigned int flags)
{
    FUN_004b0480();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00658930_class
{
    unsigned int __thiscall GetShortAtOffsetA() const;
};
unsigned int __fastcall FUN_0044ddc0(void* note);
struct ReceiverEntry
{
    unsigned int type;
    void(__cdecl* callback)(void*, void*);
};
// @fnv 0x004b0730
void BSAnimNoteReceiver::DispatchNoteToReceivers(void* note)
{
    for (int i = 0; i < ((FUN_00658930_class*)((char*)this + 8))->GetShortAtOffsetA(); ++i)
    {
        if (((ReceiverEntry*)((NiFormArray*)((char*)this + 8))->FUN_00877a30(i))->type == FUN_0044ddc0(note))
        {
            ((ReceiverEntry*)((NiFormArray*)((char*)this + 8))->FUN_00877a30(i))->callback(unk04, note);
        }
    }
}
