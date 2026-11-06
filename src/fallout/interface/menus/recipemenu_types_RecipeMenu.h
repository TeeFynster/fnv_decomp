// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_RECIPEMENU_H
#define FNV_RECIPEMENU_H

#include "layout_support.h"
#include "ListBoxBase.h"
#include "Menu.h"
#include "TESForm.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class ListBox_TESConditionItem___;
class ListBox_TESRecipe___;
class ListBox_TESRecipeComponent___;
class ListBoxItem_TESConditionItem___;
class ListBoxItem_TESRecipe___;
class ListBoxItem_TESRecipeComponent___;
enum MENU_SOUNDS
{
    MENU_SOUNDS_MENU_SOUND_NONE = -1,
    MENU_SOUNDS_MENU_SOUND_OK = 1,
    MENU_SOUNDS_MENU_SOUND_CANCEL = 2,
    MENU_SOUNDS_MENU_SOUND_NEXT_PREVIOUS = 3,
    MENU_SOUNDS_MENU_SOUND_FOCUS = 4,
    MENU_SOUNDS_MENU_SOUND_BOOK_NEXT_PAGE = 5,
    MENU_SOUNDS_MENU_SOUND_SPEECH_ROLLOVER = 6,
    MENU_SOUNDS_MENU_SOUND_SPEECH_ROTATE = 7,
    MENU_SOUNDS_MENU_SOUND_QUEST_NEW = 8,
    MENU_SOUNDS_MENU_SOUND_QUEST_UPDATE = 9,
    MENU_SOUNDS_MENU_SOUND_MESSAGE = 10,
    MENU_SOUNDS_MENU_SOUND_CLICK = 11,
    MENU_SOUNDS_MENU_SOUND_WHIR = 12,
    MENU_SOUNDS_MENU_SOUND_WHIR_CLICK = 13,
    MENU_SOUNDS_MENU_SOUND_FADE = 14,
    MENU_SOUNDS_MENU_SOUND_INVENTORY_OPEN = 15,
    MENU_SOUNDS_MENU_SOUND_INVENTORY_CLOSE = 16,
    MENU_SOUNDS_MENU_SOUND_POTION_CREATE = 17,
    MENU_SOUNDS_MENU_SOUND_DOOR_LOCKED = 18,
    MENU_SOUNDS_MENU_SOUND_PLACE_TOKEN = 19,
    MENU_SOUNDS_MENU_SOUND_REMOVE_TOKEN = 20,
    MENU_SOUNDS_MENU_SOUND_LEVEL_UP = 21,
    MENU_SOUNDS_MENU_SOUND_SPELL_EQUIP = 22,
    MENU_SOUNDS_MENU_SOUND_ENCHANTMENT_RECHARGE = 23,
    MENU_SOUNDS_MENU_SOUND_SCROLL_OPEN = 24,
    MENU_SOUNDS_MENU_SOUND_SCROLL_CLOSE = 25,
    MENU_SOUNDS_MENU_SOUND_BOOK_OPEN = 26,
    MENU_SOUNDS_MENU_SOUND_BOOK_CLOSE = 27,
    MENU_SOUNDS_MENU_SOUND_TAKE_ALL = 28,
    MENU_SOUNDS_MENU_SOUND_NOTHING_HARVESTED = 29,
    MENU_SOUNDS_MENU_SOUND_INGREDIENT_SELECTED = 30,
    MENU_SOUNDS_MENU_SOUND_SOUL_TRAP = 31,
    MENU_SOUNDS_MENU_SOUND_HAMMER_BREAK = 32,
    MENU_SOUNDS_MENU_SOUND_SIGIL_CREATE = 33,
    MENU_SOUNDS_MENU_SOUND_GOLD = 34,
    MENU_SOUNDS_MENU_SOUND_ENCHANT = 35,
    MENU_SOUNDS_MENU_SOUND_MODE = 36
};
#pragma pack(push, 4)
class ListBox_TESRecipe___ : public ListBoxBase, public BSSimpleList<ListBoxItem_TESRecipe___*>
{
  public:
    // base ListBoxBase at +0x0, size 4
    // base BSSimpleList<ListBoxItem<TESRecipe *> *> at +0x4, size 8
    Tile* m_pListTile;                 // +0xC, 4 bytes
    Tile* m_pSelectedTile;             // +0x10, 4 bytes
    Tile* m_pHighlightedTile;          // +0x14, 4 bytes
    const char* pTemplateName;         // +0x18, 4 bytes
    unsigned short m_usSelectedIndex;  // +0x1C, 2 bytes
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue;   // +0x20, 4 bytes
    float m_fSecondListValue;  // +0x24, 4 bytes
    float m_fThirdListValue;   // +0x28, 4 bytes
    unsigned short usFlags;    // +0x2C, 2 bytes
    unsigned char layoutPadding2E[2];
    // ListBox<TESRecipe *>
    // void __cdecl ListBox<TESRecipe *>::*(Tile*, const char*)
    // Tile* __cdecl ListBox<TESRecipe *>::*(TESRecipe*, const char*, int __cdecl (ListBoxItem<TESRecipe *>*, ListBoxItem<TESRecipe *>*)*, const char*)
    // bool __cdecl ListBox<TESRecipe *>::*(Tile*)
    // bool __cdecl ListBox<TESRecipe *>::*(unsigned int, bool)
    // void __cdecl ListBox<TESRecipe *>::*(bool __cdecl (TESRecipe*)*)
    // bool __cdecl ListBox<TESRecipe *>::*(Tile*)
    // bool __cdecl ListBox<TESRecipe *>::*()
    // TESRecipe* __cdecl ListBox<TESRecipe *>::*(Tile*)
    // TESRecipe* __cdecl ListBox<TESRecipe *>::*(unsigned int, bool)
    // Tile* __cdecl ListBox<TESRecipe *>::*(TESRecipe*&)
    // Tile* __cdecl ListBox<TESRecipe *>::*(unsigned int, bool)
    // Tile* __cdecl ListBox<TESRecipe *>::*()
    // Tile* __cdecl ListBox<TESRecipe *>::*()
    // Tile* __cdecl ListBox<TESRecipe *>::*()
    // unsigned int __cdecl ListBox<TESRecipe *>::*()
    // unsigned int __cdecl ListBox<TESRecipe *>::*()
    // unsigned int __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*(bool)
    // void __cdecl ListBox<TESRecipe *>::*(bool)
    // void __cdecl ListBox<TESRecipe *>::*()
    // bool __cdecl ListBox<TESRecipe *>::*(const Menu*)
    // void __cdecl ListBox<TESRecipe *>::*(bool)
    // void __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*()
    // bool __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*(bool)
    // bool __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*(TESBoundObject*)
    // void __cdecl ListBox<TESRecipe *>::*(BSSimpleList<TESForm *>*)
    // bool __cdecl ListBox<TESRecipe *>::*(Tile*)
    // Tile* __cdecl ListBox<TESRecipe *>::*(Interface::enumGamepadButtons)
    // Tile* __cdecl ListBox<TESRecipe *>::*()
    // TESRecipe* __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*(bool)
    // void __cdecl ListBox<TESRecipe *>::*(float, float)
    // bool __cdecl ListBox<TESRecipe *>::*(Tile*)
    // bool __cdecl ListBox<TESRecipe *>::*(Tile*)
    // bool __cdecl ListBox<TESRecipe *>::*(Tile*)
    // bool __cdecl ListBox<TESRecipe *>::*(Tile*)
    // void __cdecl ListBox<TESRecipe *>::*(bool)
    // void __cdecl ListBox<TESRecipe *>::*(bool)
    // unsigned int __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*(void __cdecl (Tile*, TESRecipe*)*, int, int)
    // TESRecipe* __cdecl ListBox<TESRecipe *>::*(bool __cdecl (Tile*, TESRecipe*)*, int, int)
    // bool __cdecl ListBox<TESRecipe *>::*(Tile*, ListBox<TESRecipe *>::SelectMode)
    // void __cdecl ListBox<TESRecipe *>::*()
    // bool __cdecl ListBox<TESRecipe *>::*(BSSimpleList<ListBoxItem<TESRecipe *> *>*, BSSimpleList<ListBoxItem<TESRecipe *> *>*)
    // ListBoxItem<TESRecipe *>* __cdecl ListBox<TESRecipe *>::*(unsigned int, bool)
    // void __cdecl ListBox<TESRecipe *>::*(Tile*)
    // void __cdecl ListBox<TESRecipe *>::*()
    // void __cdecl ListBox<TESRecipe *>::*(ListBox<TESRecipe *>::Flag, bool)
    // void __cdecl ListBox<TESRecipe *>::*(ListBox<TESRecipe *>::Flag)
    // bool __cdecl ListBox<TESRecipe *>::*(ListBox<TESRecipe *>::Flag)
    // ListBox<TESRecipe *>& __cdecl ListBox<TESRecipe *>::*(const ListBox<TESRecipe *>&)
    // void __cdecl ListBox<TESRecipe *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ListBox_TESRecipe___) == 48);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, m_pListTile) == 12);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, m_pSelectedTile) == 16);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, m_pHighlightedTile) == 20);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, pTemplateName) == 24);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, m_usSelectedIndex) == 28);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, m_fFirstListValue) == 32);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, m_fSecondListValue) == 36);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, m_fThirdListValue) == 40);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipe___, usFlags) == 44);
#pragma pack(push, 4)
class ListBox_TESRecipeComponent___ : public ListBoxBase, public BSSimpleList<ListBoxItem_TESRecipeComponent___*>
{
  public:
    // base ListBoxBase at +0x0, size 4
    Tile* m_pListTile;                 // +0xC, 4 bytes
    Tile* m_pSelectedTile;             // +0x10, 4 bytes
    Tile* m_pHighlightedTile;          // +0x14, 4 bytes
    const char* pTemplateName;         // +0x18, 4 bytes
    unsigned short m_usSelectedIndex;  // +0x1C, 2 bytes
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue;   // +0x20, 4 bytes
    float m_fSecondListValue;  // +0x24, 4 bytes
    float m_fThirdListValue;   // +0x28, 4 bytes
    unsigned short usFlags;    // +0x2C, 2 bytes
    unsigned char layoutPadding2E[2];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ListBox_TESRecipeComponent___) == 48);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, m_pListTile) == 12);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, m_pSelectedTile) == 16);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, m_pHighlightedTile) == 20);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, pTemplateName) == 24);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, m_usSelectedIndex) == 28);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, m_fFirstListValue) == 32);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, m_fSecondListValue) == 36);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, m_fThirdListValue) == 40);
FNV_STATIC_ASSERT(offsetof(ListBox_TESRecipeComponent___, usFlags) == 44);
#pragma pack(push, 4)
class ListBox_TESConditionItem___ : public ListBoxBase, public BSSimpleList<ListBoxItem_TESConditionItem___*>
{
  public:
    // base ListBoxBase at +0x0, size 4
    // base BSSimpleList<ListBoxItem<TESConditionItem *> *> at +0x4, size 8
    Tile* m_pListTile;                 // +0xC, 4 bytes
    Tile* m_pSelectedTile;             // +0x10, 4 bytes
    Tile* m_pHighlightedTile;          // +0x14, 4 bytes
    const char* pTemplateName;         // +0x18, 4 bytes
    unsigned short m_usSelectedIndex;  // +0x1C, 2 bytes
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue;   // +0x20, 4 bytes
    float m_fSecondListValue;  // +0x24, 4 bytes
    float m_fThirdListValue;   // +0x28, 4 bytes
    unsigned short usFlags;    // +0x2C, 2 bytes
    unsigned char layoutPadding2E[2];
    // ListBox<TESConditionItem *>
    // void __cdecl ListBox<TESConditionItem *>::*(Tile*, const char*)
    // Tile* __cdecl ListBox<TESConditionItem *>::*(TESConditionItem*, const char*, int __cdecl (ListBoxItem<TESConditionItem *>*, ListBoxItem<TESConditionItem *>*)*, const char*)
    // bool __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // bool __cdecl ListBox<TESConditionItem *>::*(unsigned int, bool)
    // void __cdecl ListBox<TESConditionItem *>::*(bool __cdecl (TESConditionItem*)*)
    // bool __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // bool __cdecl ListBox<TESConditionItem *>::*()
    // TESConditionItem* __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // TESConditionItem* __cdecl ListBox<TESConditionItem *>::*(unsigned int, bool)
    // Tile* __cdecl ListBox<TESConditionItem *>::*(TESConditionItem*&)
    // Tile* __cdecl ListBox<TESConditionItem *>::*(unsigned int, bool)
    // Tile* __cdecl ListBox<TESConditionItem *>::*()
    // Tile* __cdecl ListBox<TESConditionItem *>::*()
    // Tile* __cdecl ListBox<TESConditionItem *>::*()
    // unsigned int __cdecl ListBox<TESConditionItem *>::*()
    // unsigned int __cdecl ListBox<TESConditionItem *>::*()
    // unsigned int __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*(bool)
    // void __cdecl ListBox<TESConditionItem *>::*(bool)
    // void __cdecl ListBox<TESConditionItem *>::*()
    // bool __cdecl ListBox<TESConditionItem *>::*(const Menu*)
    // void __cdecl ListBox<TESConditionItem *>::*(bool)
    // void __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*()
    // bool __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*(bool)
    // bool __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*(TESBoundObject*)
    // void __cdecl ListBox<TESConditionItem *>::*(BSSimpleList<TESForm *>*)
    // bool __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // Tile* __cdecl ListBox<TESConditionItem *>::*(Interface::enumGamepadButtons)
    // Tile* __cdecl ListBox<TESConditionItem *>::*()
    // TESConditionItem* __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*(bool)
    // void __cdecl ListBox<TESConditionItem *>::*(float, float)
    // bool __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // bool __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // bool __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // bool __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // void __cdecl ListBox<TESConditionItem *>::*(bool)
    // void __cdecl ListBox<TESConditionItem *>::*(bool)
    // unsigned int __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*(void __cdecl (Tile*, TESConditionItem*)*, int, int)
    // TESConditionItem* __cdecl ListBox<TESConditionItem *>::*(bool __cdecl (Tile*, TESConditionItem*)*, int, int)
    // bool __cdecl ListBox<TESConditionItem *>::*(Tile*, ListBox<TESConditionItem *>::SelectMode)
    // void __cdecl ListBox<TESConditionItem *>::*()
    // bool __cdecl ListBox<TESConditionItem *>::*(BSSimpleList<ListBoxItem<TESConditionItem *> *>*, BSSimpleList<ListBoxItem<TESConditionItem *> *>*)
    // ListBoxItem<TESConditionItem *>* __cdecl ListBox<TESConditionItem *>::*(unsigned int, bool)
    // void __cdecl ListBox<TESConditionItem *>::*(Tile*)
    // void __cdecl ListBox<TESConditionItem *>::*()
    // void __cdecl ListBox<TESConditionItem *>::*(ListBox<TESConditionItem *>::Flag, bool)
    // void __cdecl ListBox<TESConditionItem *>::*(ListBox<TESConditionItem *>::Flag)
    // bool __cdecl ListBox<TESConditionItem *>::*(ListBox<TESConditionItem *>::Flag)
    // ListBox<TESConditionItem *>& __cdecl ListBox<TESConditionItem *>::*(const ListBox<TESConditionItem *>&)
    // void __cdecl ListBox<TESConditionItem *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ListBox_TESConditionItem___) == 48);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, m_pListTile) == 12);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, m_pSelectedTile) == 16);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, m_pHighlightedTile) == 20);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, pTemplateName) == 24);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, m_usSelectedIndex) == 28);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, m_fFirstListValue) == 32);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, m_fSecondListValue) == 36);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, m_fThirdListValue) == 40);
FNV_STATIC_ASSERT(offsetof(ListBox_TESConditionItem___, usFlags) == 44);
#endif
