// fallout/magic/nonactormagictarget.cpp: NonActorMagicTarget (6 functions)

#include "../../../include/NonActorMagicTarget.h"

// @fnv 0x007d6bb0
BSSimpleList<ActiveEffect*>* NonActorMagicTarget::GetActiveEffectList()
{
    return &m_kActiveEffects;
}

// @fnv 0x00826060
bool NonActorMagicTarget::AddEffectToTarget(MagicCaster* apCaster, MagicItem* apSpell, ActiveEffect* apActiveEffect, bool abAreaTarget)
{
    bool bresult;
    bresult = MagicTarget::AddEffectToTarget(apCaster, apSpell, apActiveEffect, abAreaTarget);
    if (bresult)
        UpdateActiveEffects(1.0F);
    return bresult;
}

// @fnv 0x00825fd0
NonActorMagicTarget::NonActorMagicTarget(Owner* o) : BSExtraData(0x33)
{
    pTargetObject = (TESObjectREFR*)o;
}

// The original destructor omits vtable writes; keep the constructor's writes above.
class __declspec(novtable) NonActorMagicTarget;

// @fnv 0x00825f60
NonActorMagicTarget::~NonActorMagicTarget()
{}

struct B1_25ad0
{
    virtual void a();
    int m_04;
    int m_08;
    B1_25ad0(int v);
    ~B1_25ad0();
};
struct B2_25ad0
{
    virtual void b();
    int m_04;
    int m_08;
    B2_25ad0();
};
class FUN_00825ad0_cls : public B1_25ad0, public B2_25ad0
{
  public:
    int m_18;
    int m_1c;
    int m_20;
    FUN_00825ad0_cls(int v);
    virtual void Body();
};
// Initializes the base B1_25ad0 with 0x32, sets m_20 to v, and zeroes m_18 and m_1c.
// @fnv 0x00825ad0
FUN_00825ad0_cls::FUN_00825ad0_cls(int aiValue) : B1_25ad0(0x32), B2_25ad0()
{
    m_20 = aiValue;
    m_18 = 0;
    m_1c = 0;
}
