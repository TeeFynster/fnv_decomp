// fallout_shared/magic/effectarchetype.cpp: free functions (1 function)

#include "../../../include/ActiveEffect.h"
#include "../../../include/AnimIdle.h"
#include "../../../include/EffectSetting.h"
// MagicEffectSystem_effectarchetype: local type (was include/MagicEffectSystem.h, which had no evidence of one real class); its methods are 0x00403ab0 EffectArchetypes::Activate, 0x00403c80 EffectArchetypes::CheckFlag, 0x00810fd0 EffectSetting::GetEffectArchetype
class ActiveEffect;
class MagicCaster;
class MagicItem;
class EffectItem;
class TESBoundObject;

class MagicEffectSystem_effectarchetype
{
public:
    struct _Type
    {
        enum Type
        {
            VALUE_MODIFIER,
            SCRIPT,
            DISPEL,
            CURE_DISEASE,
            ABSORB,
            SHIELD,
            CALM,
            DEMORALIZE,
            FRENZY,
            COMMAND_CREATURE,
            COMMAND_HUMANOID,
            INVISIBILITY,
            CHAMELEON,
            LIGHT,
            DARKNESS,
            NIGHT_EYE,
            LOCK,
            OPEN,
            BOUND_ITEM,
            SUMMON_CREATURE,
            DETECT_LIFE,
            TELEKINESIS,
            DISINTEGRATE_ARMOR,
            DISINTEGRATE_WEAPON,
            PARALYSIS,
            REANIMATE,
            SOUL_TRAP,
            TURN_UNDEAD,
            SUN_DAMAGE,
            VAMPIRISM,
            CURE_PARALYSIS,
            CURE_ADDICTION,
            CURE_POISON,
            CONCUSSION,
            VALUE_AND_PARTS,
            LIMB_CONDITION,
            TURBO,
            COUNT,
        };
    };

    typedef _Type::Type Type;

    static bool __cdecl IsFlagSet(Type type, unsigned int flags);
    static bool __cdecl IsFlagSet(int type, unsigned int flags);
    static ActiveEffect* Activate(MagicCaster*, MagicItem*, EffectItem*, TESBoundObject*);
};
#include "effectarchetype_decls.h"
// Looks up the effect archetype's factory by the effect's archetype and creates an ActiveEffect via it, then passes source to the created effect.
// @fnv 0x00403ab0
ActiveEffect* MagicEffectSystem_effectarchetype::Activate(MagicCaster* caster, MagicItem* item, EffectItem* effect,
                                          TESBoundObject* source)
{
    ActiveEffect* pCreateEffect = 0;
    EffectSetting* m_pLinkedEffect = effect ? (EffectSetting*)((AnimIdle*)effect)->GetSection() : 0;
    int m_eEffectTypeItem = m_pLinkedEffect->GetArchetype();
    EffectFactory pFactory = DAT_01183324[m_eEffectTypeItem].factory;
    if (pFactory)
        pCreateEffect = pFactory(caster, item, effect);
    if (pCreateEffect)
        pCreateEffect->InitFromSource(source);
    return pCreateEffect;
}
