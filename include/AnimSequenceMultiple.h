#pragma once

#include "AnimSequenceBase.h"

class BSAnimGroupSequence;
class TESAnimGroup;

class AnimSequenceMultiple : public AnimSequenceBase
{
public:
    virtual void __vslot_0() override;
    virtual bool IsSingleSeq() override;
    virtual void AssignSequence(BSAnimGroupSequence*, bool) override;
    virtual bool SetSequenceActive(BSAnimGroupSequence*, bool) override;
    virtual BSAnimGroupSequence* GetSequenceAtIndex(char) override;
    virtual BSAnimGroupSequence* GetControllerSequence(TESAnimGroup*) override;
    virtual char ContainsSequence(BSAnimGroupSequence*) override;

    BSAnimGroupSequence* FindSequence(BSAnimGroupSequence*, int);
    ~AnimSequenceMultiple();
    void* ScalarDeletingDestructor(unsigned int flags);

    void* m_pSingleSequence;
};
