// fallout/interface/menus/playernameentrymenu.cpp: PlayerNameEntryMenu (7 functions)

#include "playernameentrymenu_decls.h"
#include "../../../../include/PlayerNameEntryMenu.h"
#include "../../../../include/Font.h"
#include "../../../../include/FontManager.h"
#include "../../../../include/FontData.h"
#include "../../../../include/Tile.h"

// If FUN_007ab810 reports completion, passes its result to Finish and then calls FUN_007ab7c0.
// @fnv 0x007ab7e0
void PlayerNameEntryMenu::UpdateDialog()
{
    if (XVirtualKeyboard_IsActive())
    {
        Finish(XVirtualKeyboard_IsActive());
        Object_GetGlobalValue_007ab7c0();
    }
}

struct Str6a70
{
    Str6a70& operator=(char const*);
};

extern Str6a70 g_011daed8;

// @fnv 0x007ab7c0
// src: GUESS 0x007ab7c0 (confidence: low)
void __cdecl Object_GetGlobalValue_007ab7c0(void)
{
    g_011daed8 = 0;
}

namespace fnv_007ab810 {
extern const char* __cdecl XVirtualKeyboard_IsActive();

struct Flt
{
    operator const char*() const;
};

extern Flt g_011daed8;

// @fnv 0x007ab810
// src: XBOX_PDB 0x007ab810
const char* __cdecl XVirtualKeyboard_IsActive()
{
    return g_011daed8;
}
}  // namespace fnv_007ab810

struct FullNameEx
{
    void SetFullName(char const*);
};
void _FUN_007df4e0();
struct NPC007ab9a0
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void func48(int);
};
// If apName is set, updates the NPC at offset 0x28 and refreshes its name; then updates the menu tile and fade state.
// @fnv 0x007ab9a0
void PlayerNameEntryMenu::Finish(char const* apName)
{
    if (apName)
    {
        ((FullNameEx*)((char*)*(NPC007ab9a0**)((char*)this + 0x28) + 0xd0))->SetFullName(apName);
        (*(NPC007ab9a0**)((char*)this + 0x28))->func48(0x20);
        _FUN_007df4e0();
    }
    ((Tile*)pMenu)->Set(0x1772, 1);
    m_eFadeState = Interface::FADING_OUT;
}

// @fnv 0x007ab7a0
PlayerNameEntryMenu::~PlayerNameEntryMenu()
{}

void NormalizeSmartQuotes(unsigned char* apChar);

// True if every character is printable in fonts 0 and 6 and at least one is not a space.
// @fnv 0x007ab820
bool __cdecl IsTextRenderable(const char* apText)
{
    bool bHasNonSpace6 = false;
    bool bInvalid7 = false;
    unsigned char cChar2;
    Font* pFont;
    if (apText)
    {
        while (!bInvalid7 && *apText)
        {
            cChar2 = *apText;
            NormalizeSmartQuotes(&cChar2);
            bInvalid7 = (cChar2 == '\\' || cChar2 == '~');
            pFont = FontManager::Instance()->GetFont(0);
            if (pFont && pFont->pFontData)
            {
                if (pFont->pFontData->pFontLetters[cChar2].fWidth != 0.0)
                    bHasNonSpace6 = (bHasNonSpace6 || cChar2 != ' ');
                else
                    bInvalid7 = true;
            }
            pFont = FontManager::Instance()->GetFont(6);
            if (pFont && pFont->pFontData)
            {
                if (pFont->pFontData->pFontLetters[cChar2].fWidth != 0.0)
                    bHasNonSpace6 = (bHasNonSpace6 || cChar2 != ' ');
                else
                    bInvalid7 = true;
            }
            apText++;
        }
    }
    return bHasNonSpace6 && !bInvalid7;
}
