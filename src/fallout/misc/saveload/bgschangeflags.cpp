// fallout/misc/saveload/bgschangeflags.cpp: BGSChangeFlagsState, LocalFormChangeMask, BGSChangeFlags (6 functions)

#include "../../../../include/BGSChangeFlags.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectREFR.h"

#include "bgschangeflags_decls.h"
// @fnv 0x008c71b0
BGSChangeFlags::BGSChangeFlags(int initial)
{
    uiFlags = initial;
}
// Sets or clears bit 8 of flags according to enabled.
// @fnv 0x0042ce50
void BGSChangeFlagsState::CombineFlags(bool enabled)
{
    if (enabled)
        flags |= 8;
    else
        flags &= ~8;
}
// @fnv 0x00841120
LocalFormChangeMask LocalFormChangeMask::HasFormChanged(LocalFormChangeMask changes, LocalFormChangeMask forced, int type, bool enabled)
{
    ((FormChangeRecord*)&changes)->FUN_00562210(forced.Modelloader_GetReferencedThis());
    ((FormChangeRecord*)&changes)->FUN_00562210(0xffff0000);
    if (enabled)
    {
        int formType = type;
        switch (formType)
        {
        case 59:
        case 60:
            ((FormChangeRecord*)&changes)->FUN_00562210(0x400);
            break;
        }
    }
    return changes;
}

// @fnv 0x00841100
void BGSChangeFlags::AddFlags(int aiFlags)
{
    uiFlags |= aiFlags;
}

static const char kStr_Flags[] = "Flags";
static const char kStr_CHANGE_FORM_FLAGS[] = "CHANGE_FORM_FLAGS";
static const char kStr_Moved[] = "Moved";
static const char kStr_CHANGE_REFR_MOVE[] = "CHANGE_REFR_MOVE";
static const char kStr_Havok_Moved[] = "Havok Moved";
static const char kStr_CHANGE_REFR_HAVOK_MOVE[] = "CHANGE_REFR_HAVOK_MOVE";
static const char kStr_Cell_Changed[] = "Cell Changed";
static const char kStr_CHANGE_REFR_CELL_CHANGED[] = "CHANGE_REFR_CELL_CHANGED";
static const char kStr_Scale[] = "Scale";
static const char kStr_CHANGE_REFR_SCALE[] = "CHANGE_REFR_SCALE";
static const char kStr_Inventory[] = "Inventory";
static const char kStr_CHANGE_REFR_INVENTORY[] = "CHANGE_REFR_INVENTORY";
static const char kStr_Leveled_Inventory[] = "Leveled Inventory";
static const char kStr_CHANGE_REFR_LEVELED_INVENTORY[] = "CHANGE_REFR_LEVELED_INVENTORY";
static const char kStr_Activating_Children[] = "Activating Children";
static const char kStr_CHANGE_REFR_EXTRA_ACTIVATING_CHILDREN[] = "CHANGE_REFR_EXTRA_ACTIVATING_CHILDREN";
static const char kStr_Game_Only_Extra[] = "Game Only Extra";
static const char kStr_CHANGE_REFR_EXTRA_GAME_ONLY[] = "CHANGE_REFR_EXTRA_GAME_ONLY";
static const char kStr_Created_Only_Extra[] = "Created Only Extra";
static const char kStr_CHANGE_REFR_EXTRA_CREATED_ONLY[] = "CHANGE_REFR_EXTRA_CREATED_ONLY";
static const char kStr_Enc_Zone_Extra[] = "Enc Zone Extra";
static const char kStr_CHANGE_REFR_EXTRA_ENCOUNTER_ZONE[] = "CHANGE_REFR_EXTRA_ENCOUNTER_ZONE";
static const char kStr_Ownership_Extra[] = "Ownership Extra";
static const char kStr_CHANGE_REFR_EXTRA_OWNERSHIP[] = "CHANGE_REFR_EXTRA_OWNERSHIP";
static const char kStr_Animation[] = "Animation";
static const char kStr_CHANGE_REFR_ANIMATION[] = "CHANGE_REFR_ANIMATION";
static const char kStr_Life_State[] = "Life State";
static const char kStr_CHANGE_ACTOR_LIFESTATE[] = "CHANGE_ACTOR_LIFESTATE";
static const char kStr_Package_Data_Extra[] = "Package Data Extra";
static const char kStr_CHANGE_ACTOR_EXTRA_PACKAGE_DATA[] = "CHANGE_ACTOR_EXTRA_PACKAGE_DATA";
static const char kStr_Merchant_Container[] = "Merchant Container";
static const char kStr_CHANGE_ACTOR_EXTRA_MERCHANT_CONTAINER[] = "CHANGE_ACTOR_EXTRA_MERCHANT_CONTAINER";
static const char kStr_Permanent_Modifiers[] = "Permanent Modifiers";
static const char kStr_CHANGE_ACTOR_PERMANENT_MODIFIERS[] = "CHANGE_ACTOR_PERMANENT_MODIFIERS";
static const char kStr_Override_Modifiers[] = "Override Modifiers";
static const char kStr_CHANGE_ACTOR_OVERRIDE_MODIFIERS[] = "CHANGE_ACTOR_OVERRIDE_MODIFIERS";
static const char kStr_Damage_Modifiers[] = "Damage Modifiers";
static const char kStr_CHANGE_ACTOR_DAMAGE_MODIFIERS[] = "CHANGE_ACTOR_DAMAGE_MODIFIERS";
static const char kStr_Temp_Modifiers[] = "Temp Modifiers";
static const char kStr_CHANGE_ACTOR_TEMP_MODIFIERS[] = "CHANGE_ACTOR_TEMP_MODIFIERS";
static const char kStr_Disp_Modifiers[] = "Disp Modifiers";
static const char kStr_CHANGE_ACTOR_DISPOSITION_MODIFIERS[] = "CHANGE_ACTOR_DISPOSITION_MODIFIERS";
static const char kStr_Leveled_Actor[] = "Leveled Actor";
static const char kStr_CHANGE_ACTOR_LEVELED_ACTOR[] = "CHANGE_ACTOR_LEVELED_ACTOR";
static const char kStr_Dismembered_Limbs[] = "Dismembered Limbs";
static const char kStr_CHANGE_ACTOR_EXTRA_DISMEMBERED_LIMBS[] = "CHANGE_ACTOR_EXTRA_DISMEMBERED_LIMBS";
static const char kStr_Item_Data_Extra[] = "Item Data Extra";
static const char kStr_CHANGE_OBJECT_EXTRA_ITEM_DATA[] = "CHANGE_OBJECT_EXTRA_ITEM_DATA";
static const char kStr_Ammo_Extra[] = "Ammo Extra";
static const char kStr_CHANGE_OBJECT_EXTRA_AMMO[] = "CHANGE_OBJECT_EXTRA_AMMO";
static const char kStr_Lock_Extra[] = "Lock Extra";
static const char kStr_CHANGE_OBJECT_EXTRA_LOCK[] = "CHANGE_OBJECT_EXTRA_LOCK";
static const char kStr_Open_State[] = "Open State";
static const char kStr_CHANGE_OBJECT_OPEN_STATE[] = "CHANGE_OBJECT_OPEN_STATE";
static const char kStr_Open_Default_State[] = "Open Default State";
static const char kStr_CHANGE_OBJECT_OPEN_DEFAULT_STATE[] = "CHANGE_OBJECT_OPEN_DEFAULT_STATE";
static const char kStr_Teleport_Extra[] = "Teleport Extra";
static const char kStr_CHANGE_DOOR_EXTRA_TELEPORT[] = "CHANGE_DOOR_EXTRA_TELEPORT";
static const char kStr_Quest_Flags[] = "Quest Flags";
static const char kStr_CHANGE_QUEST_FLAGS[] = "CHANGE_QUEST_FLAGS";
static const char kStr_Quest_Script_Delay[] = "Quest Script Delay";
static const char kStr_CHANGE_QUEST_SCRIPT_DELAY[] = "CHANGE_QUEST_SCRIPT_DELAY";
static const char kStr_Quest_Stages[] = "Quest Stages";
static const char kStr_CHANGE_QUEST_STAGES[] = "CHANGE_QUEST_STAGES";
static const char kStr_Quest_Script[] = "Quest Script";
static const char kStr_CHANGE_QUEST_SCRIPT[] = "CHANGE_QUEST_SCRIPT";
static const char kStr_Quest_Objectives[] = "Quest Objectives";
static const char kStr_CHANGE_QUEST_OBJECTIVES[] = "CHANGE_QUEST_OBJECTIVES";
static const char kStr_Said_Once[] = "Said Once";
static const char kStr_CHANGE_TOPIC_SAIDONCE[] = "CHANGE_TOPIC_SAIDONCE";
static const char kStr_Note_Read[] = "Note Read";
static const char kStr_CHANGE_NOTE_READ[] = "CHANGE_NOTE_READ";
static const char kStr_Seen_Data[] = "Seen Data";
static const char kStr_CHANGE_CELL_SEENDATA[] = "CHANGE_CELL_SEENDATA";
static const char kStr_Detach_Time[] = "Detach Time";
static const char kStr_CHANGE_CELL_DETACHTIME[] = "CHANGE_CELL_DETACHTIME";
static const char kStr_Exterior_Char[] = "Exterior Char";
static const char kStr_CHANGE_CELL_EXTERIOR_CHAR[] = "CHANGE_CELL_EXTERIOR_CHAR";
static const char kStr_Exterior_Short[] = "Exterior Short";
static const char kStr_CHANGE_CELL_EXTERIOR_SHORT[] = "CHANGE_CELL_EXTERIOR_SHORT";
static const char kStr_CHANGE_CELL_FLAGS[] = "CHANGE_CELL_FLAGS";
static const char kStr_Full_name[] = "Full name";
static const char kStr_CHANGE_CELL_FULLNAME[] = "CHANGE_CELL_FULLNAME";
static const char kStr_Ownership[] = "Ownership";
static const char kStr_CHANGE_CELL_OWNERSHIP[] = "CHANGE_CELL_OWNERSHIP";
static const char kStr_Faction_Flags[] = "Faction Flags";
static const char kStr_CHANGE_FACTION_FLAGS[] = "CHANGE_FACTION_FLAGS";
static const char kStr_Faction_Reactions[] = "Faction Reactions";
static const char kStr_CHANGE_FACTION_REACTIONS[] = "CHANGE_FACTION_REACTIONS";
static const char kStr_Faction_Crime_Counts[] = "Faction Crime Counts";
static const char kStr_CHANGE_FACTION_CRIME_COUNTS[] = "CHANGE_FACTION_CRIME_COUNTS";
static const char kStr_Never_Run_Flag[] = "Never Run Flag";
static const char kStr_CHANGE_PACKAGE_NEVER_RUN[] = "CHANGE_PACKAGE_NEVER_RUN";
static const char kStr_Waiting_Flag[] = "Waiting Flag";
static const char kStr_CHANGE_PACKAGE_WAITING[] = "CHANGE_PACKAGE_WAITING";
static const char kStr_Base_Data[] = "Base Data";
static const char kStr_CHANGE_ACTOR_BASE_DATA[] = "CHANGE_ACTOR_BASE_DATA";
static const char kStr_Attributes[] = "Attributes";
static const char kStr_CHANGE_ACTOR_BASE_ATTRIBUTES[] = "CHANGE_ACTOR_BASE_ATTRIBUTES";
static const char kStr_AI_Data[] = "AI Data";
static const char kStr_CHANGE_ACTOR_BASE_AIDATA[] = "CHANGE_ACTOR_BASE_AIDATA";
static const char kStr_Spell_List[] = "Spell List";
static const char kStr_CHANGE_ACTOR_BASE_SPELLLIST[] = "CHANGE_ACTOR_BASE_SPELLLIST";
static const char kStr_Full_Name[] = "Full Name";
static const char kStr_CHANGE_ACTOR_BASE_FULLNAME[] = "CHANGE_ACTOR_BASE_FULLNAME";
static const char kStr_NPC_Skills[] = "NPC Skills";
static const char kStr_CHANGE_NPC_SKILLS[] = "CHANGE_NPC_SKILLS";
static const char kStr_Class[] = "Class";
static const char kStr_CHANGE_NPC_CLASS[] = "CHANGE_NPC_CLASS";
static const char kStr_Face[] = "Face";
static const char kStr_CHANGE_NPC_FACE[] = "CHANGE_NPC_FACE";
static const char kStr_Race[] = "Race";
static const char kStr_CHANGE_NPC_RACE[] = "CHANGE_NPC_RACE";
static const char kStr_Gender[] = "Gender";
static const char kStr_CHANGE_NPC_GENDER[] = "CHANGE_NPC_GENDER";
static const char kStr_Creature_Skills[] = "Creature Skills";
static const char kStr_CHANGE_CREATURE_SKILLS[] = "CHANGE_CREATURE_SKILLS";
static const char kStr_Tag_Skills[] = "Tag Skills";
static const char kStr_CHANGE_CLASS_TAG_SKILLS[] = "CHANGE_CLASS_TAG_SKILLS";
static const char kStr_Zone_Flags[] = "Zone Flags";
static const char kStr_CHANGE_ENCOUNTER_ZONE_FLAGS[] = "CHANGE_ENCOUNTER_ZONE_FLAGS";
static const char kStr_Game_Data[] = "Game Data";
static const char kStr_CHANGE_ENCOUNTER_ZONE_GAME_DATA[] = "CHANGE_ENCOUNTER_ZONE_GAME_DATA";
static const char kStr_Added_Form[] = "Added Form";
static const char kStr_CHANGE_FORM_LIST_ADDED_FORM[] = "CHANGE_FORM_LIST_ADDED_FORM";
static const char kStr_Added_Object[] = "Added Object";
static const char kStr_CHANGE_LEVELED_LIST_ADDED_OBJECT[] = "CHANGE_LEVELED_LIST_ADDED_OBJECT";
static const char kStr_Remapped[] = "Remapped";
static const char kStr_CHANGE_WATER_REMAPPED[] = "CHANGE_WATER_REMAPPED";
static const char kStr_Object_Value[] = "Object Value";
static const char kStr_CHANGE_BASE_OBJECT_VALUE[] = "CHANGE_BASE_OBJECT_VALUE";
static const char kStr_Object_Full_Name[] = "Object Full Name";
static const char kStr_CHANGE_BASE_OBJECT_FULLNAME[] = "CHANGE_BASE_OBJECT_FULLNAME";
static const char kStr_Teaches_Skill[] = "Teaches Skill";
static const char kStr_CHANGE_BOOK_TEACHES_SKILL[] = "CHANGE_BOOK_TEACHES_SKILL";
static const char kStr_Speaker[] = "Speaker";
static const char kStr_CHANGE_TALKING_ACTIVATOR_SPEAKER[] = "CHANGE_TALKING_ACTIVATOR_SPEAKER";
static const char kStr_Bad_Flag_Name[] = "Bad Flag Name";

// Maps a change flag and form type to a display name, returning the enabled or disabled variant string, or "Bad Flag Name" if unknown.
// @fnv 0x0083fef0
const char* GetChangeFlagName(int flags, int aiFormType, bool enabled)
{
    int formType = aiFormType;
    if (flags == 1)
        return enabled ? kStr_Flags : kStr_CHANGE_FORM_FLAGS;
    switch (formType)
    {
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 105: {
        switch (flags)
        {
        case 2:
            return enabled ? kStr_Moved : kStr_CHANGE_REFR_MOVE;
        case 4:
            return enabled ? kStr_Havok_Moved : kStr_CHANGE_REFR_HAVOK_MOVE;
        case 8:
            return enabled ? kStr_Cell_Changed : kStr_CHANGE_REFR_CELL_CHANGED;
        case 0x10:
            return enabled ? kStr_Scale : kStr_CHANGE_REFR_SCALE;
        case 0x20:
            return enabled ? kStr_Inventory : kStr_CHANGE_REFR_INVENTORY;
        case 0x8000000:
            return enabled ? kStr_Leveled_Inventory : kStr_CHANGE_REFR_LEVELED_INVENTORY;
        case 0x4000000:
            return enabled ? kStr_Activating_Children : kStr_CHANGE_REFR_EXTRA_ACTIVATING_CHILDREN;
        case 0x80000000:
            return enabled ? kStr_Game_Only_Extra : kStr_CHANGE_REFR_EXTRA_GAME_ONLY;
        case 0x40000000:
            return enabled ? kStr_Created_Only_Extra : kStr_CHANGE_REFR_EXTRA_CREATED_ONLY;
        case 0x20000000:
            return enabled ? kStr_Enc_Zone_Extra : kStr_CHANGE_REFR_EXTRA_ENCOUNTER_ZONE;
        case 0x40:
            return enabled ? kStr_Ownership_Extra : kStr_CHANGE_REFR_EXTRA_OWNERSHIP;
        case 0x10000000:
            return enabled ? kStr_Animation : kStr_CHANGE_REFR_ANIMATION;
        }
        switch (formType)
        {
        case 59:
        case 60:
            switch (flags)
            {
            case 0x400:
                return enabled ? kStr_Life_State : kStr_CHANGE_ACTOR_LIFESTATE;
            case 0x800:
                return enabled ? kStr_Package_Data_Extra : kStr_CHANGE_ACTOR_EXTRA_PACKAGE_DATA;
            case 0x1000:
                return enabled ? kStr_Merchant_Container : kStr_CHANGE_ACTOR_EXTRA_MERCHANT_CONTAINER;
            case 0x800000:
                return enabled ? kStr_Permanent_Modifiers : kStr_CHANGE_ACTOR_PERMANENT_MODIFIERS;
            case 0x400000:
                return enabled ? kStr_Override_Modifiers : kStr_CHANGE_ACTOR_OVERRIDE_MODIFIERS;
            case 0x200000:
                return enabled ? kStr_Damage_Modifiers : kStr_CHANGE_ACTOR_DAMAGE_MODIFIERS;
            case 0x100000:
                return enabled ? kStr_Temp_Modifiers : kStr_CHANGE_ACTOR_TEMP_MODIFIERS;
            case 0x80000:
                return enabled ? kStr_Disp_Modifiers : kStr_CHANGE_ACTOR_DISPOSITION_MODIFIERS;
            case 0x40000:
                return enabled ? kStr_Leveled_Actor : kStr_CHANGE_ACTOR_LEVELED_ACTOR;
            case 0x20000:
                return enabled ? kStr_Dismembered_Limbs : kStr_CHANGE_ACTOR_EXTRA_DISMEMBERED_LIMBS;
            }
            break;
        default:
            switch (flags)
            {
            case 0x400:
                return enabled ? kStr_Item_Data_Extra : kStr_CHANGE_OBJECT_EXTRA_ITEM_DATA;
            case 0x800:
                return enabled ? kStr_Ammo_Extra : kStr_CHANGE_OBJECT_EXTRA_AMMO;
            case 0x1000:
                return enabled ? kStr_Lock_Extra : kStr_CHANGE_OBJECT_EXTRA_LOCK;
            case 0x800000:
                return enabled ? kStr_Open_State : kStr_CHANGE_OBJECT_OPEN_STATE;
            case 0x400000:
                return enabled ? kStr_Open_Default_State : kStr_CHANGE_OBJECT_OPEN_DEFAULT_STATE;
            }
            switch (formType)
            {
            case 28:
                switch (flags)
                {
                case 0x20000:
                    return enabled ? kStr_Teleport_Extra : kStr_CHANGE_DOOR_EXTRA_TELEPORT;
                }
                break;
            }
            break;
        }
        break;
    }
    case 71:
        switch (flags)
        {
        case 2:
            return enabled ? kStr_Quest_Flags : kStr_CHANGE_QUEST_FLAGS;
        case 4:
            return enabled ? kStr_Quest_Script_Delay : kStr_CHANGE_QUEST_SCRIPT_DELAY;
        case 0x80000000:
            return enabled ? kStr_Quest_Stages : kStr_CHANGE_QUEST_STAGES;
        case 0x40000000:
            return enabled ? kStr_Quest_Script : kStr_CHANGE_QUEST_SCRIPT;
        case 0x20000000:
            return enabled ? kStr_Quest_Objectives : kStr_CHANGE_QUEST_OBJECTIVES;
        }
        break;
    case 70:
        switch (flags)
        {
        case 0x80000000:
            return enabled ? kStr_Said_Once : kStr_CHANGE_TOPIC_SAIDONCE;
        }
        break;
    case 49:
        switch (flags)
        {
        case 0x80000000:
            return enabled ? kStr_Note_Read : kStr_CHANGE_NOTE_READ;
        }
        break;
    case 57:
        switch (flags)
        {
        case 0x80000000:
            return enabled ? kStr_Seen_Data : kStr_CHANGE_CELL_SEENDATA;
        case 0x40000000:
            return enabled ? kStr_Detach_Time : kStr_CHANGE_CELL_DETACHTIME;
        case 0x20000000:
            return enabled ? kStr_Exterior_Char : kStr_CHANGE_CELL_EXTERIOR_CHAR;
        case 0x10000000:
            return enabled ? kStr_Exterior_Short : kStr_CHANGE_CELL_EXTERIOR_SHORT;
        case 2:
            return enabled ? kStr_Flags : kStr_CHANGE_CELL_FLAGS;
        case 4:
            return enabled ? kStr_Full_name : kStr_CHANGE_CELL_FULLNAME;
        case 8:
            return enabled ? kStr_Ownership : kStr_CHANGE_CELL_OWNERSHIP;
        }
        break;
    case 8:
        switch (flags)
        {
        case 2:
            return enabled ? kStr_Faction_Flags : kStr_CHANGE_FACTION_FLAGS;
        case 4:
            return enabled ? kStr_Faction_Reactions : kStr_CHANGE_FACTION_REACTIONS;
        case 0x80000000:
            return enabled ? kStr_Faction_Crime_Counts : kStr_CHANGE_FACTION_CRIME_COUNTS;
        }
        break;
    case 73:
        switch (flags)
        {
        case 0x80000000:
            return enabled ? kStr_Never_Run_Flag : kStr_CHANGE_PACKAGE_NEVER_RUN;
        case 0x40000000:
            return enabled ? kStr_Waiting_Flag : kStr_CHANGE_PACKAGE_WAITING;
        }
        break;
    case 42:
    case 43:
        switch (flags)
        {
        case 2:
            return enabled ? kStr_Base_Data : kStr_CHANGE_ACTOR_BASE_DATA;
        case 4:
            return enabled ? kStr_Attributes : kStr_CHANGE_ACTOR_BASE_ATTRIBUTES;
        case 8:
            return enabled ? kStr_AI_Data : kStr_CHANGE_ACTOR_BASE_AIDATA;
        case 0x10:
            return enabled ? kStr_Spell_List : kStr_CHANGE_ACTOR_BASE_SPELLLIST;
        case 0x20:
            return enabled ? kStr_Full_Name : kStr_CHANGE_ACTOR_BASE_FULLNAME;
        }
        switch (formType)
        {
        case 42:
            switch (flags)
            {
            case 0x200:
                return enabled ? kStr_NPC_Skills : kStr_CHANGE_NPC_SKILLS;
            case 0x400:
                return enabled ? kStr_Class : kStr_CHANGE_NPC_CLASS;
            case 0x800:
                return enabled ? kStr_Face : kStr_CHANGE_NPC_FACE;
            case 0x2000000:
                return enabled ? kStr_Race : kStr_CHANGE_NPC_RACE;
            case 0x1000000:
                return enabled ? kStr_Gender : kStr_CHANGE_NPC_GENDER;
            }
            break;
        case 43:
            switch (flags)
            {
            case 0x200:
                return enabled ? kStr_Creature_Skills : kStr_CHANGE_CREATURE_SKILLS;
            }
            break;
        }
        break;
    case 7:
        switch (flags)
        {
        case 2:
            return enabled ? kStr_Tag_Skills : kStr_CHANGE_CLASS_TAG_SKILLS;
        }
        break;
    case 97:
        switch (flags)
        {
        case 2:
            return enabled ? kStr_Zone_Flags : kStr_CHANGE_ENCOUNTER_ZONE_FLAGS;
        case 0x80000000:
            return enabled ? kStr_Game_Data : kStr_CHANGE_ENCOUNTER_ZONE_GAME_DATA;
        }
        break;
    case 85:
        switch (flags)
        {
        case 0x80000000:
            return enabled ? kStr_Added_Form : kStr_CHANGE_FORM_LIST_ADDED_FORM;
        }
        break;
    case 44:
    case 45:
    case 52:
        switch (flags)
        {
        case 0x80000000:
            return enabled ? kStr_Added_Object : kStr_CHANGE_LEVELED_LIST_ADDED_OBJECT;
        }
        break;
    case 78:
        switch (flags)
        {
        case 0x80000000:
            return enabled ? kStr_Remapped : kStr_CHANGE_WATER_REMAPPED;
        }
        break;
    default:
        switch (flags)
        {
        case 2:
            return enabled ? kStr_Object_Value : kStr_CHANGE_BASE_OBJECT_VALUE;
        case 4:
            return enabled ? kStr_Object_Full_Name : kStr_CHANGE_BASE_OBJECT_FULLNAME;
        }
        switch (formType)
        {
        case 25:
            switch (flags)
            {
            case 0x20:
                return enabled ? kStr_Teaches_Skill : kStr_CHANGE_BOOK_TEACHES_SKILL;
            }
            break;
        case 22:
            switch (flags)
            {
            case 0x800000:
                return enabled ? kStr_Speaker : kStr_CHANGE_TALKING_ACTIVATOR_SPEAKER;
            }
            break;
        }
        break;
    }
    return kStr_Bad_Flag_Name;
}

extern TESDataHandler* g_dataHandler;

// Builds a forced change-flags set from the form type and its flags, stores it in flags, and returns whether any forced flag is set or the form is kept.
// @fnv 0x00840f70
bool BGSChangeFlags::TestFormChangeFlags(TESForm* apForm)
{
    int eFormType2 = apForm->GetFormType();
    BGSChangeFlags kForced;
    bool bKeep2 = false;
    TESObjectREFR* pRef;

    switch (eFormType2)
    {
    case 0x3A:
    case 0x3B:
    case 0x3C:
    case 0x3D:
    case 0x3E:
    case 0x3F:
    case 0x40:
    case 0x69:
        pRef = (TESObjectREFR*)apForm;
        if (g_dataHandler->FormIDExists(apForm->GetFormID()))
        {
            bKeep2 = true;
        }
        if (pRef->TESObjectREFR_IsCellLoaded())
        {
            if (Test(0x10000000))
            {
                kForced.AddFlags(0x10000000);
            }
            if (Test(0x8000000))
            {
                kForced.AddFlags(0x8000000);
            }
        }
        switch (eFormType2)
        {
        case 0x3B:
        case 0x3C:
            if (Test(0x40000))
            {
                kForced.AddFlags(0x40000);
            }
            break;
        }
        break;
    case 0x47:
        if (Test(0x40000000))
        {
            kForced.AddFlags(0x40000000);
        }
        break;
    }

    uiFlags = kForced.GetFlags();
    return uiFlags != 0 || bKeep2;
}
