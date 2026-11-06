// fallout_shared/magic/effectarchetype_decls.h: declares EffectArchetypeEntry

typedef ActiveEffect*(__cdecl* EffectFactory)(MagicCaster*, MagicItem*, EffectItem*);
struct EffectArchetypeEntry
{
    EffectFactory factory;
    unsigned int reserved[3];
};
extern EffectArchetypeEntry DAT_01183324[];
