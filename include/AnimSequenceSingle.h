#pragma once

#include "AnimSequenceBase.h"

class BSAnimGroupSequence;
class TESAnimGroup;

class AnimSequenceSingle : public AnimSequenceBase
{
public:
    virtual void __vslot_0() override;
    virtual bool IsSingleSeq() override;
    virtual void AssignSequence(BSAnimGroupSequence*, bool) override;
    virtual bool SetSequenceActive(BSAnimGroupSequence*, bool) override;
    virtual BSAnimGroupSequence* GetSequenceAtIndex(char) override;
    virtual BSAnimGroupSequence* GetControllerSequence(TESAnimGroup*) override;
    virtual char ContainsSequence(BSAnimGroupSequence*) override;

    bool RemoveSequence(BSAnimGroupSequence* apSeq, bool abReleaseModelLoader);
    void __local_vftable_ctor_closure();

    BSAnimGroupSequence* pForwardSequence;
};
