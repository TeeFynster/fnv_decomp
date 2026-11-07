
// mapmenu_ctx_variant.cpp: context variant of src/fallout/interface/menus/mapmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/BGSNote.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/Character.h"
#include "../../../../include/FOPipboyManager.h"
#include "../../../../include/FORenderedMenu.h"
#include "../../../../include/FalloutRadio.h"
#include "../../../../include/MapMenu.h"
#include "../../../../include/Menu.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiPoint2.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/SettingT_GameSettingCollection_.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESQuest.h"
#include "../../../../include/TESTopicInfo.h"
#include "../../../../include/TESWorldSpace.h"
#include "../../../../include/Tile.h"
#include "../../../../include/TileImage.h"
#include "../../../../include/Tile.h"
#include "../../../../include/PathingLocation.h"
#include "../../../../include/TESDataHandler.h"

// @fnv 0x007a1930
template <> void ListBox<TESQuest*>::ClearSelection(bool notify)
{
    SetSelectedTile(0, notify);
}

// The shared class does not yet declare the flag query at 0x00586210.
extern "C" bool WorldSpaceHasFlag2();

extern TESDataHandler* g_dataHandler;

extern "C" char* __cdecl FindString(const char*, const char*);
unsigned int __cdecl BSStringLength(const char*);
extern "C" int __cdecl _mbsnicmp(const char*, const char*, size_t);

// @fnv 0x007984d0
// src: XBOX_PDB 0x007984d0
TESWorldSpace* MapMenu::CalculatePlayerMarkerSpace(NiPoint3 pt)
{
    TESWorldSpace* result5 = 0;
    float maxDist = 3.402823466e+38F;
    for (BSSimpleList<TESWorldSpace*>* node2 = g_dataHandler->GetWorldSpaces(); node2 && node2->GetItem();
         node2 = node2->GetNext())
    {
        TESWorldSpace* ws4 = node2->GetItem();
        const char* name = ws4->GetFullName();
        NiPoint3 ptCopy3 = pt;
        PathingLocation loc4;
        if (!name || !*name || FindString(name, "test") == name ||
            reinterpret_cast<bool (__thiscall*)(TESWorldSpace*)>(WorldSpaceHasFlag2)(ws4))
        {
            continue;
        }
        ws4->GetCellAtPosition(ptCopy3, true);
        loc4 = PathingLocation(&ptCopy3, ws4);
        if (loc4.FUN_006de250() && this->m_pCurrentWorldspace && ws4)
        {
            if (BSStringLength(this->m_pCurrentWorldspace->GetWorldMapTextureName()) < 31 ||
                BSStringLength(ws4->GetWorldMapTextureName()) < 31)
            {
                continue;
            }
            if (_mbsnicmp(this->m_pCurrentWorldspace->GetWorldMapTextureName() + 29,
                          ws4->GetWorldMapTextureName() + 29, 3) == 0)
            {
                result5 = ws4;
                break;
            }
        }
    }
    if (!result5)
    {
        result5 = g_dataHandler->GetWorldSpaces()->GetItem();
    }
    return result5;
}
