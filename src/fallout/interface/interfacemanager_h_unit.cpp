// fallout/interface/interfacemanager_h_unit.cpp: TargetClass (1 function)

#include "interfacemanager.h"

void _Deallocate(void*);
struct TargetClass
{
    void SetVtableAndProcessState_00719390();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00719390, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00719360
void* TargetClass::DestroyIfFlagged(unsigned int flags)
{
    SetVtableAndProcessState_00719390();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
