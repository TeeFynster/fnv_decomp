#pragma once

class BSAnimGroupSequence;
class TESAnimGroup;

class AnimSequenceBase
{
public:
    virtual void __vslot_0();
    virtual bool IsSingleSeq();
    virtual void AssignSequence(BSAnimGroupSequence*, bool);
    virtual bool SetSequenceActive(BSAnimGroupSequence*, bool);
    virtual BSAnimGroupSequence* GetSequenceAtIndex(char);
    virtual BSAnimGroupSequence* GetControllerSequence(TESAnimGroup*);
    virtual char ContainsSequence(BSAnimGroupSequence*);
};
