
// src/fallout/magic/dispeleffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/dispeleffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/DispelEffect.h"
#include "../../../include/Character.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/EffectItem.h"

// @fnv 0x00829b90
void DispelEffect::CopyData(ActiveEffect* apDestination)
{
    ActiveEffect::CopyData(apDestination);
}

// Returns true if apTarget is a Character, using a dynamic_cast.
// @fnv 0x0082d060
bool DispelEffect::IsEffectValid(MagicTarget* apTarget)
{
    return dynamic_cast<Character*>(apTarget) != 0;
}

void* operator new(unsigned int size) throw();

// @fnv 0x0080d950
ActiveEffect* DispelEffect::Copy()
{
    ActiveEffect* e = new DispelEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(e);
    return e;
}

struct SubObj
{
    virtual void s0();
    virtual void s1();
    virtual float s2(void* p);
};

struct ItemObj
{
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual int i6();
    int m_04;
    int m_08;
    SubObj m_0c;
};

struct DatObj
{
    float* Setting_Float_00403e20();
};
extern DatObj DAT_011d1b20;


// This accessor has no shared member declaration. Its single ECX argument
// uses the same calling sequence as the original no-argument member call.
MagicCaster* __fastcall GetEffectCaster(ActiveEffect*);

// @fnv 0x0080da00
void DispelEffect::Start()
{
    BSSimpleList<ActiveEffect*>* cur = FUN_0059bb30()->GetActiveEffectList();
    bool b9 = GetHavokWorldObjectCountInSceneGraph_0084e3a0()->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == 0;
    Actor* x = GetEffectCaster(this) ? GetEffectCaster(this)->GetCasterActor() : 0;
    while (cur != 0 && !cur->IsEmpty())
    {
        ActiveEffect* t5 = cur->GetItem();
        BSSimpleList<ActiveEffect*>* nextItem = cur->GetNext();
        if (t5 != 0 && (void*)t5 != (void*)this)
        {
            ItemObj* u2 = reinterpret_cast<ItemObj*>(t5->FUN_0044ddc0());
            if (u2->i6() == 0)
            {
                if (u2->m_0c.s2(b9 ? x : 0) <= GetFloatAtOffset1C() * *DAT_011d1b20.Setting_Float_00403e20())
                    t5->Dispel(false);
            }
        }
        cur = nextItem;
    }
}
