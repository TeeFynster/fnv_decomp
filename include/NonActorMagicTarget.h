#pragma once

#include "BSExtraData.h"
#if !defined(FNV64_BSSIMPLELIST_DEFINED) && !defined(FNV_EXTRADATAOBJECTS_PRIVATE_LAYOUT_SUPPORT_H)
#include "BSSimpleList.h"
#endif
#include "MagicTarget.h"

class Owner;

class NonActorMagicTarget : public BSExtraData, public MagicTarget
{
public:
    NonActorMagicTarget(Owner* o);
    virtual ~NonActorMagicTarget();
    void* operator new(unsigned int s);
    void operator delete(void* p);

    virtual bool AddEffectToTarget(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect, bool abImmediate);
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();

    union
    {
        TESObjectREFR* pTargetObject;
        int unk1c;
    };
    union
    {
        struct
        {
            BSSimpleList<ActiveEffect*> m_kActiveEffects;
        };
        struct
        {
            int unk20;
            int unk24;
        };
    };
};
