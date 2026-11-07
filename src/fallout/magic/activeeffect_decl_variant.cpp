// Load an active effect from a save-game record.

#include "../../../include/AlchemyItem.h"
#include "../../../include/TESSaveLoadGame.h"
// MagicEffectSystem_activeeffect_decl_variant: local type (was include/MagicEffectSystem.h, which had no evidence of one real class); its methods are 0x00403ab0 EffectArchetypes::Activate, 0x00403c80 EffectArchetypes::CheckFlag, 0x00810fd0 EffectSetting::GetEffectArchetype
class ActiveEffect;
class MagicCaster;
class MagicItem;
class EffectItem;
class TESBoundObject;

class MagicEffectSystem_activeeffect_decl_variant
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
#include "../../../include/MagicItem.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/SpellItem.h"

extern TESSaveLoadGame* g_TESSaveLoadGame;
extern const char DAT_010793e0[];
void FNV_Warning(const char*, ...);
// @fnv 0x00805920
// src: XBOX_PDB 0x00805920
ActiveEffect* ActiveEffect_LoadActiveEffect(BGSLoadFormBuffer* buffer)
{
    unsigned short effectSize = 28;
    unsigned int magicItemID;
    unsigned char recordIndex;
    MagicItem* magicItem;
    if (g_TESSaveLoadGame->FUN_008df040() >= 42)
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&effectSize, 2);
    g_TESSaveLoadGame->FUN_00857aa0(&magicItemID, 4);
    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&recordIndex, 1);
    magicItem = MagicItem::GetMagicItemByID(magicItemID);
    if (magicItem)
    {
        EffectItem* effect = magicItem->GetEffectItemAtIndex(recordIndex);
        if (effect)
        {
            ActiveEffect* active = MagicEffectSystem_activeeffect_decl_variant::Activate(0, magicItem, effect, 0);
            // This save-load variant dispatches through slot 0x20, which the shared
            // ActiveEffect declaration exposes as the Actor* overload.
            active->LoadGame(reinterpret_cast<Actor*>(buffer));
            return active;
        }
    }
    g_TESSaveLoadGame->FUN_00857bd0(effectSize);
    FNV_Warning(DAT_010793e0, magicItemID, recordIndex);
    return 0;
}
