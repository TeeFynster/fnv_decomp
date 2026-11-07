#pragma once

class IBSAnimNoteReceiver
{
public:
    virtual ~IBSAnimNoteReceiver();
    virtual void vf01();

    void __thiscall SetVtableAndProcessState_004b0530();
    void* FUN_004b0550(unsigned int flags);
};
