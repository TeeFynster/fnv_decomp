
// src/fallout_shared/bgsequiptype_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00479570: the skeleton of src/fallout_shared/bgsequiptype.cpp
// that unit declares it this way.

#include "../../include/BGSMenuIcon.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"

void* __cdecl operator new(unsigned int);
unsigned int __cdecl BSstrlen(const char*);
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
TESForm* __cdecl LookupFormByID(unsigned int formID);
extern TESDataHandler* g_dataHandler;
extern const char* g_iconNames[14];
extern BGSMenuIcon* DAT_011c4b54[14];
// @fnv 0x00479570
// src: XBOX_PDB 0x00479570
void BGSEquipType_GenerateDefaultMenuIcons()
{
    static unsigned int prefixLength = BSstrlen("MenuIconEquipType");
    for (int i = 0; i < 14; ++i)
    {
        unsigned int formIDB = i + 0x258;
        BGSMenuIcon* entry = dynamic_cast<BGSMenuIcon*>(LookupFormByID(formIDB));
        if (!entry)
        {
            entry = new BGSMenuIcon;
            entry->SetRefID(formIDB, true);
            char buffer[260];
            FUN_00406d30(buffer, 260, "MenuIconEquipType");
            FUN_00406d50(buffer, 260, g_iconNames[i]);
            entry->SetEditorID_AtRuntime(buffer);
            FUN_00406d30(buffer, 260, "TypeIcons\\hot_keys_icon_");
            FUN_00406d50(buffer, 260, g_iconNames[i]);
            FUN_00406d50(buffer, 260, ".dds");
            entry->SetTexture(buffer);
            g_dataHandler->AddFormToDataHandler(entry);
        }
        DAT_011c4b54[i] = entry;
    }
}
