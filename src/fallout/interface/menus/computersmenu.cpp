#include "../../../../include/BSStringT.h"
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/StartMenu.h"
#include "../../../../include/ComputersMenu.h"
#include "../../../../include/Tile.h"
#include "../../../../include/TESSound.h"
#include "../../../../include/Setting.h"
#include "../../../../include/Menu.h"
#include "../../../../include/BGSNote.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/FORenderedMenu.h"
#include "../../../../include/FORenderedTerminal.h"
#include "../../../../include/GO.h"
#include "../../../../include/StrMem.h"
// HighlightList_computersmenu: local type (was include/HighlightList.h, which had no evidence of one real class); its methods are 0x007244e0 ListBox<enum ActorValue::Index>::UpdateHighlightBoxPos, 0x00725080 ListBox<enum MiscStatManager::MiscStatID>::UpdateHighlightBoxPos, 0x0075abd0 ListBox<TERMINAL_MENU_ITEM *>::UpdateHighlightBoxPos, 0x007a5e70 ListBox<ItemChange *>::ScrollToHighlight
class Tile;

class HighlightList_computersmenu
{
public:
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    Tile* selected;

    void FUN_007244e0();
    void FUN_00725080();
    void FUN_007a5e70();
    void FUN_007a73e0();
    __declspec(dllexport) void UpdateHighlight();
    void FUN_0072c2b0();
};
// HighlightValue_computersmenu: local type (was include/HighlightValue.h, which had no evidence of one real class); its methods are 0x00a09130 Tile::Value::AddRefValueAction, 0x00a09410 Tile::Value::SetFloat
#include "../../../../include/Tile.h"
#include "../../../../include/InterfaceManager.h"

class HighlightValue_computersmenu
{
public:
    void FUN_00a09130(int trait, Tile* tile, int sourceTrait);
    void FUN_00a09130(int trait, void* source, int sourceTrait);
    void FUN_00a09410(int value);
};
// InterfaceH_computersmenu: local type (was include/InterfaceH.h, which had no evidence of one real class); its methods are 0x00702360 Interface::IsInMenuMode, 0x00702450 Interface::IsTopMenuID, 0x00703860 HUDMainMenu::HandleHealthbarForCrosshairActor_, 0x00705e00 Interface::CreateLoadingMenu
class TESForm;
class TESObjectREFR;

class InterfaceH_computersmenu
{
public:
    static bool __cdecl GetSelectedTargetIndex(int);
    static void SetQuestTarget(TESForm*, bool);
    static void SetLookAtReference(TESObjectREFR*);
    static double GetFourthInterfaceFloat();
    static double GetThirdInterfaceFloat();
    static bool IsSaveLoadActive();
};

// src/fallout/interface/menus/computersmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/computersmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// Stores apTile into the tile slot at index aiID when aiID is in [0, 0x10).
// @fnv 0x00754c00
void ComputersMenu::FUN_00754c00(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 0x10)
    {
        m_pTiles[aiID] = apTile;
    }
}


// @fnv 0x00757a10
int __thiscall ComputersMenu::GetMenuId()
{
    return 0x421;
}

// @fnv 0x00757e20
int FUN_00757e20()
{
    return 0x421;
}

struct FUN_00757e80_shell
{
    unsigned char IsFlagBitSet();
};

// @fnv 0x00757e80
unsigned char FUN_00757e80_shell::IsFlagBitSet()
{
    return ((*(unsigned char*)((unsigned char*)this + 0xa5) & 4) != 0);
}

struct FUN_00758390_shell
{
    signed char m_74;
    bool __thiscall FUN_00758390();
};

// @fnv 0x00758390
bool __thiscall FUN_00758390_shell::FUN_00758390()
{
    return (((signed char*)this)[0x74 / sizeof(signed char)] & 2) != 0;
}

struct FUN_00758a60_shell
{
    char m_74;
    bool __thiscall FUN_00758a60();
};

// @fnv 0x00758a60
bool __thiscall FUN_00758a60_shell::FUN_00758a60()
{
    return (((char*)this)[0x74] & 4) != 0;
}

namespace fnv_007596a0 {
extern int __cdecl GetTileValueID(const char*, int);
extern char $SG7172[];

// @fnv 0x007596a0
void __cdecl FUN_007596a0(Tile* apTile, void* apMenuItem)
{
    if (apTile)
        apTile->Set(GetTileValueID($SG7172, -1), 1);
}
}  // namespace fnv_007596a0

void __cdecl _Deallocate(void*);

// Checks that all 16 entries of arr are non-null, returning 0 on the first null and 1 otherwise.
// @fnv 0x00757e30
bool __thiscall ComputersMenu::HasAllTiles(int* piIndex)
{
    for (*piIndex = 0; *piIndex < 0x10; (*piIndex)++)
    {
        if (m_pTiles[*piIndex] == 0)
            return 0;
    }
    return 1;
}

struct FUN_00758350_shell
{
    char m_6c[4];
    bool __thiscall FUN_00758350();
};
// Returns true when the int at offset 0x6c is nonzero and bit 0 of the byte at offset 0x74 is set.
// @fnv 0x00758350
bool __thiscall FUN_00758350_shell::FUN_00758350()
{
    return *(int*)((char*)this + 0x6c) && ((*(signed char*)((char*)this + 0x74) & 1));
}

struct Helper98
{
    void __thiscall _ref_0063f7b0();
    int* __thiscall _ref_006815c0();
};
void __cdecl RefreshF57EA0TerminalMenu();
// @fnv 0x00758a80
void __thiscall ComputersMenu::FUN_00758a80()
{
    reinterpret_cast<Helper98*>(&notes)->_ref_0063f7b0();
    terminal = reinterpret_cast<BGSTerminal*>(*reinterpret_cast<Helper98*>(&notes)->_ref_006815c0());
    if (terminal != 0)
        FUN_007586e0(0);
    else
        RefreshF57EA0TerminalMenu();
}

extern StartMenu* DAT_01189e94[];
struct Host
{
    char _pad[0xA6];
    unsigned char mA6;
    char const* __thiscall FUN_00758fe0();
};
// @fnv 0x00758fe0
char const* __thiscall Host::FUN_00758fe0()
{
    return mA6 < 10 ? static_cast<const StartMenu*>(DAT_01189e94[mA6])->GetMenuTitle() : 0;
}

struct GlobalObject_0048f200
{
    GlobalObject_0048f200();
};
GlobalObject_0048f200::GlobalObject_0048f200()
{}
struct FUN_00759760_shell : GlobalObject_0048f200
{
    FUN_00759760_shell();
};
// @fnv 0x00759760
FUN_00759760_shell::FUN_00759760_shell()
{}

struct S_7597c0
{
    int __thiscall FUN_007597c0(int);
};
extern S_7597c0* DAT_011d9338;
// Calls FUN_007597c0(1) on DAT_011d9338 if non-null, then sets DAT_011d9338 to null.
// @fnv 0x00759780
void FUN_00759780()
{
    S_7597c0* b = DAT_011d9338;
    S_7597c0* a = b;
    a ? a->FUN_007597c0(1) : 0;
    DAT_011d9338 = 0;
}

void __cdecl operator delete(void*);
struct FUN_007597c0_shell
{
    void FUN_007597f0();
    void* __thiscall FUN_007597c0(unsigned int flags);
};
// Calls FUN_007597f0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x007597c0
void* __thiscall FUN_007597c0_shell::FUN_007597c0(unsigned int flags)
{
    FUN_007597f0();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_007597f0 {
struct GlobalObject_0048f200
{
    ~GlobalObject_0048f200();
};
struct FUN_00759850_owner
{
    void __thiscall FUN_00759850();
};
struct FUN_007597f0 : GlobalObject_0048f200
{
    ~FUN_007597f0();
};
// Destructor that calls FUN_00759850 on this object before the base GlobalObject_0048f200 destructor runs.
// @fnv 0x007597f0
FUN_007597f0::~FUN_007597f0()
{
    ((FUN_00759850_owner*)this)->FUN_00759850();
}
}  // namespace fnv_007597f0

struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct ScriptObj
{
    int FUN_007598a0(int);
};
struct ListBase
{
    ScriptObj* RemoveHead();
};
struct Holder
{
    void FUN_00759850();
};
// @fnv 0x00759850
void Holder::FUN_00759850()
{
    while (!((ArrHelper*)this)->FUN_0076b610())
    {
        ScriptObj* pB = ((ListBase*)this)->RemoveHead();
        ScriptObj* pA = pB;
        pA ? pA->FUN_007598a0(1) : 0;
    }
}

void Deallocate(void*);
struct FUN_007598a0_shell
{
    void __thiscall FUN_00726cf0();
    void* __thiscall FUN_007598a0(unsigned int flags);
};
// Calls FUN_00726cf0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007598a0
void* FUN_007598a0_shell::FUN_007598a0(unsigned int flags)
{
    FUN_00726cf0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Flt
{
    operator unsigned int();
};
struct TL
{
    Tile*& GetNext(void*&);
};
struct NoArgumentMethodObject
{
    void FUN_00700110();
};
struct TileProcessor
{
    void ProcessAllTiles();
};
// @fnv 0x00759f50
void TileProcessor::ProcessAllTiles()
{
    void* piter = (void*)((Flt*)this)->operator unsigned int();
    while (piter)
    {
        ((NoArgumentMethodObject*)((TL*)this)->GetNext(piter))->FUN_00700110();
    }
}

void __cdecl operator delete(void*);

struct FUN_0075aa20_shell
{
    void __thiscall FUN_0075a060();
    void* __thiscall FUN_0075aa20(unsigned int flags);
};

// Calls FUN_0075a060, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0075aa20
void* __thiscall FUN_0075aa20_shell::FUN_0075aa20(unsigned int flags)
{
    FUN_0075a060();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_007583b0_shell
{
    char _pad[0x74];
    signed char m_74;
    void __thiscall SetFlag4(bool aFlag);
};

// @fnv 0x007583b0
void FUN_007583b0_shell::SetFlag4(bool aFlag)
{
    if (aFlag)
        m_74 |= 4;
    else
        m_74 &= ~4;
}

struct TerminalNodeSortList
{
    void __thiscall Sort(int(__cdecl* f)(void*, void*));
};

struct FUN_0075aa50_shell
{
    void __thiscall ResetAndProcessNodes();
};

struct FUN_0075a5e0_shell
{
    char _pad[4];
    TerminalNodeSortList m_kNode;
    void __thiscall FUN_0075a5e0(int(__cdecl* f)(void*, void*));
};

// Sorts the list using the given comparison function, then calls ResetAndProcessNodes on this object.
// @fnv 0x0075a5e0
void __thiscall FUN_0075a5e0_shell::FUN_0075a5e0(int(__cdecl* f)(void*, void*))
{
    m_kNode.Sort(f);
    reinterpret_cast<FUN_0075aa50_shell*>(this)->ResetAndProcessNodes();
}

// @fnv 0x007583f0
bool ComputersMenu::HandleButtonInput(int aiButton, float afValue)
{
    if (InterfaceH_computersmenu::GetSelectedTargetIndex(0x421))
    {
        switch (aiButton)
        {
        case 0xa:
            if (tile30->IsVisible())
            {
                m_pText = 0;
                (*(void(__thiscall**)(ComputersMenu*, int, int))(*(int*)this + 0xc))(this, 2, 0);
            }
            else
            {
                FUN_00758a80();
            }
            return true;
        }
    }
    return false;
}

struct FUN_0075ab20_shell
{
    char _pad[0x0C];
    Tile* m_pTile;
    bool __thiscall IsTileTraitEnabled();
};

int __cdecl GetTileValueID(char const*, int);
extern int DAT_011d93d8;
extern int DAT_011d93dc;

// Returns true when m_pTile is set and its trait lookup for the cached "_enabled" trait index succeeds.
// @fnv 0x0075ab20
bool __thiscall FUN_0075ab20_shell::IsTileTraitEnabled()
{
    static int trait = GetTileValueID("_enabled", -1);

    return m_pTile && m_pTile->IsTraitNonZero(trait);
}

void* __cdecl operator new(unsigned int);

struct M788
{
    void __thiscall FUN_004ed8c0(void*);
};

struct AnimationPointerList
{
    void* __thiscall DereferenceIfNotNull(void*);
};

struct FUN_006ffe80_shell
{
    void __thiscall FUN_006ffe80(int, int);
};

struct FUN_00726db0_class
{
    bool __thiscall FUN_00726db0(bool);
};

struct FUN_00759eb0
{
    char _pad[0x2c];

    FUN_00759eb0(char const*);
};

struct FUN_007b5330_shell
{
    void __thiscall FUN_007b5330(void*, void*);
};

struct FUN_00759da0_shell : FUN_007b5330_shell
{
    void __thiscall InsertAtPosition(char const*, int, int, int);
};

// @fnv 0x00759da0
void FUN_00759da0_shell::InsertAtPosition(char const* aParam1, int aParam2, int aParam3, int aParam4)
{
    FUN_00759eb0* pNewObject = new FUN_00759eb0(aParam1);

    reinterpret_cast<FUN_006ffe80_shell*>(pNewObject)->FUN_006ffe80(aParam2, aParam3);

    if (aParam4 == -1)
    {
        reinterpret_cast<M788*>(this)->FUN_004ed8c0(reinterpret_cast<void*>(&pNewObject));
    }
    else
    {
        unsigned int pNode = reinterpret_cast<GO*>(this)->operator unsigned int();

        for (int i = 0; pNode != 0 && i < aParam4; ++i)
        {
            pNode = reinterpret_cast<unsigned int>(
                reinterpret_cast<AnimationPointerList*>(this)->DereferenceIfNotNull(reinterpret_cast<void*>(pNode)));
        }

        if (pNode != 0)
        {
            this->FUN_007b5330(reinterpret_cast<void*>(pNode), reinterpret_cast<void*>(&pNewObject));
        }
        else
        {
            reinterpret_cast<M788*>(this)->FUN_004ed8c0(reinterpret_cast<void*>(&pNewObject));
        }
    }

    reinterpret_cast<FUN_00726db0_class*>(pNewObject)->FUN_00726db0(false);
}

struct SysColorMgr
{
    static SysColorMgr* GetSingleton();
    void ApplyToChild(int, int*);
};
extern int DAT_011d9334;
extern int DAT_011d934c;
void FUN_00759780();
// The compiler also emits the scalar deleting destructor at 0x00757a20.
// @fnv 0x00757a50
ComputersMenu::~ComputersMenu()
{
    DAT_011d9334 = 0;
    FUN_00759780();
    notes.RemoveAll();
    for (int i = 0; i < 3; i++)
    {
        reinterpret_cast<BSSoundHandle&>(sounds[i]).Stop();
        reinterpret_cast<BSSoundHandle&>(sounds[i]).Release();
    }
    SysColorMgr::GetSingleton()->ApplyToChild(3, &DAT_011d934c);
}

struct BlinkValue
{
    float FUN_00488d50();
    void FUN_00a0a270(float, bool);
};
// The shared Tile API has no non-creating trait lookup or clipping toggle yet.
// These declarations provide only the missing calls, with no Tile layout copy.
struct TileCompatibility
{
    void* FindTraitValue(int);
    void FUN_00a04620(bool);
};
unsigned int __cdecl gm_GetTickCount();
// Toggles the blink value between 0 and 1 once the tick interval elapses, or fetches the value from the tile if missing.
// Keep local statics linkable for rebinding while retaining the original out-of-line code.
// @fnv 0x007585a0
__declspec(noinline) inline void ComputersMenu::UpdateBlink()
{
    static unsigned int nextTick = 0;
    static float interval = tile40->FUN_00a011b0(GetTileValueID("_blink_interval", -1));
    if (gm_GetTickCount() > nextTick && unka4)
    {
        static_cast<BlinkValue*>(unka4)->FUN_00a0a270(static_cast<BlinkValue*>(unka4)->FUN_00488d50() == 1.0 ? 0.0f : 1.0f, true);
        nextTick = gm_GetTickCount() + interval;
    }
    else if (!unka4)
    {
        unka4 = reinterpret_cast<TileCompatibility*>(tile40)->FindTraitValue(4003);
    }
}



int __cdecl TraitNameToID(const char* apName, int aiDefault);

struct NoteFlags
{
    bool Check(int a, int b);
};

struct NoteEntry
{
    ::BSStringT<char> kName;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    NoteFlags kFlags;
    bool IsUnread();
    void SetUnread(bool abUnread);
};

extern Setting g_011d2cb8;

struct NoteTextSetter
{
    void Apply();
};
NoteTextSetter* __stdcall CreateNoteTextSetter(const char* apText, Tile::Value* apValue1, Tile::Value* apValue2,
                                               int aiIndex);

// Sets the tile's enabled state and text from a note entry, marking unread notes as read and applying the text setter when shown.
// @fnv 0x00759560
void UpdateNoteTile(Tile* apTile, NoteEntry* apEntry)
{
    if (apTile)
    {
        ::BSStringT<char> kText("> ");
        int iState = 1;
        bool bShow = true;
        apTile->Set(TraitNameToID("_enabled", -1), 0);
        if (apEntry && apEntry->kFlags.Check(0, 0))
        {
            if (apEntry->IsUnread())
            {
                iState = 2;
                apEntry->SetUnread(false);
            }
            kText += apEntry->kName;
        }
        else if (!apEntry)
        {
            kText += g_011d2cb8.String();
        }
        else
        {
            bShow = false;
        }
        apTile->Set(0xfd6, iState);
        if (bShow)
        {
            CreateNoteTextSetter(kText, apTile->GetValue(0x1004), apTile->GetValue(0xfa3), -1)->Apply();
        }
    }
}

struct FUN_00759760_storage : FUN_00759760_shell
{
    int unk00;
    int unk04;
    int unk08;
};
// Allocates a FUN_00759760_storage instance into DAT_011d9338 if it is null, then returns DAT_011d9338.
// @fnv 0x007596d0
S_7597c0* __cdecl GetStorageSingleton()
{
    if (!DAT_011d9338)
        DAT_011d9338 = reinterpret_cast<S_7597c0*>(new FUN_00759760_storage());
    return DAT_011d9338;
}

// Destructor: release the entries, unregister this object, then the entry list member is destroyed.

class A060EntryList
{
  public:
    ~A060EntryList();
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0075a060;
void __cdecl A060Unregister(FUN_0075a060* pkObject);

class FUN_0075a060
{
  public:
    virtual ~FUN_0075a060();
    void Clear();

    A060EntryList m_kEntries;
};

// Clears the object's entry list, then unregisters the object via A060Unregister.
// @fnv 0x0075a060
FUN_0075a060::~FUN_0075a060()
{
    Clear();
    A060Unregister(this);
}

struct Shell
{
    bool __thiscall IsTileTraitEnabled();
    bool __thiscall ContainsKey(Tile* a1);
    void __thiscall UpdateHighlight();
};

char const* __cdecl FUN_00a00940(char const* a1, int a2);

class SetTileHelper
{
  public:
    char _pad[0x10];
    Tile* m_pTile10;

    bool FUN_0075a610(Tile* apTile);
};

// @fnv 0x0075a610
bool SetTileHelper::FUN_0075a610(Tile* apTile)
{
    if (((Shell*)this)->IsTileTraitEnabled() &&
        (apTile == 0 || (((Shell*)this)->ContainsKey(apTile) &&
                         apTile->IsTraitNonZero((int)FUN_00a00940("_enabled", -1)))))
    {
        m_pTile10 = apTile;
        ((Shell*)this)->UpdateHighlight();
        return true;
    }
    else
    {
        return false;
    }
}

struct b9165Inner
{
    Tile* m_00;
    char unk04[4];
    unsigned char m_08;
};

struct b9165Ref
{
    b9165Inner* p;
};

struct b9165Node
{
    char unk00[0x18];
    b9165Ref* __thiscall FUN_006815c0();
    b9165Node* __thiscall FUN_00726070();
};

struct FUN_0075aa50_cls
{
    char unk00[4];
    b9165Node m_04;
    unsigned short m_1c;
    char unk1e[2];
    float m_20;
    void __thiscall AccumulateTileHeight(Tile* p);
    void __thiscall UpdateScrollItems();
    void __thiscall UpdateHighlight();
    void __thiscall ResetAndProcessNodes();
};

// @fnv 0x0075aa50
void FUN_0075aa50_cls::ResetAndProcessNodes()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (b9165Node* cur = this != 0 ? &m_04 : 0; cur != 0 && cur->FUN_006815c0()->p != 0; cur = cur->FUN_00726070())
    {
        if (cur->FUN_006815c0()->p->m_08 == 0)
        {
            cur->FUN_006815c0()->p->m_00->FUN_00700320(0xfac, m_1c++);
            AccumulateTileHeight(cur->FUN_006815c0()->p->m_00);
        }
    }
    UpdateScrollItems();
    UpdateHighlight();
}

// Refresh the terminal menu tile; if the rendered menu is showing this menu's scene, refresh the rendered terminal too.

class InterfaceManager;


// Menu has no declaration for the direct update call at 0x00a1d910.
struct MenuUpdateCompatibility
{
    void Update();
};

extern ComputersMenu* g_pF57EA0TerminalMenu;
extern const float g_fF57EA0TileDefault;

void F57EA0Prepare();
InterfaceManager* F57EA0GetInterfaceManager();
FORenderedMenu* __fastcall F57EA0GetRenderedMenu(InterfaceManager* pkManager);

// @fnv 0x00757ea0
void RefreshF57EA0TerminalMenu()
{
    if (g_pF57EA0TerminalMenu)
    {
        F57EA0Prepare();
        g_pF57EA0TerminalMenu->GetTile()->SetFloat(0xfc1, g_fF57EA0TileDefault, true);
        if (F57EA0GetRenderedMenu(F57EA0GetInterfaceManager()) &&
            F57EA0GetRenderedMenu(F57EA0GetInterfaceManager())->GetSceneNode() ==
                g_pF57EA0TerminalMenu->GetTile()->FUN_0056c7f0())
        {
            FORenderedTerminal* pkTerminal =
                dynamic_cast<FORenderedTerminal*>(F57EA0GetRenderedMenu(F57EA0GetInterfaceManager()));
            pkTerminal->Refresh();
        }
        g_pF57EA0TerminalMenu->GetTile()->SetInt(0x1772, 1);
        reinterpret_cast<MenuUpdateCompatibility*>(g_pF57EA0TerminalMenu)->Update();
    }
}

namespace fnv_00758470 {
InterfaceManager* FUN_004b7210();
struct HH84
{
    unsigned int GetReferenceFlags();
    void ProcessQueue();
};
void FUN_007596a0(Tile*, TESObjectREFR*);
unsigned int __cdecl gm_GetTickCount();
extern unsigned int DAT_011d93c4;
}  // namespace fnv_00758470

// @fnv 0x00758470
void ComputersMenu::FUN_00758470()
{
    using namespace fnv_00758470;
    if ((unkc0 && !FUN_004b7210()->kTutorialManager.HasBeenShown(0x18)) || m_eFadeState == 2)
        return;
    reinterpret_cast<HH84*>(manager)->ProcessQueue();
    UpdateBlink();
    if (!reinterpret_cast<HH84*>(manager)->GetReferenceFlags())
    {
        if (unkb0 < 2)
        {
            if (unkb0 == 0)
            {
                DAT_011d93c4 = fnv_00758470::gm_GetTickCount() + 2000;
                unkb0 = 1;
            }
            else if (unkb0 == 1)
            {
                if (fnv_00758470::gm_GetTickCount() > DAT_011d93c4)
                    RefreshDisplay();
            }
        }
        else if (bRefreshed)
        {
            entries.Traverse(FUN_007596a0, 0, 0x7fffffff);
            bRefreshed = 0;
        }
    }
    if (unka0 && fnv_00758470::gm_GetTickCount() > unka0)
    {
        unka0 = 0;
        tile3c->Set(0xfa3, 0);
    }
}


struct CHValue
{
    const char* GetString();
};

struct CHString
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;

    CHString();
    ~CHString();
    const char* CStr();
};

int __cdecl CHSprintf(CHString* apString, const char* apFormat, ...);
int __cdecl CHStricmp(const char* apString1, const char* apString2);
int __cdecl CHTraitNameToID(const char* apName, int aiDefault);

struct CHCondition
{
    bool Evaluate(void* apSubject, int aiUnk);
};

struct CHChallenge;

struct CHListNode
{
    CHChallenge* pItem;
    CHListNode* pNext;

    CHChallenge** GetItem();
    CHListNode* GetNext();
};

struct CHDescription
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual const char* Get(CHChallenge* apForm, unsigned int auiChunk);
};

struct CHChallenge
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    CHCondition kCondition;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    CHDescription kDescription;

    CHListNode* GetChallengeList();
    bool IsCompleted();
    const char* GetName();
    void SetSeen(bool abSeen);
};

struct CHSimpleList
{
    CHChallenge* pItem;
    CHListNode* pNext;

    void AddHead(CHChallenge*& arItem);
    CHListNode* GetNext();
};

struct CHListBox
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Clear();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;

    Tile* Insert(CHChallenge* apItem, int aiUnk1, int aiUnk2, int aiUnk3);
};

struct CHDisplay
{
    void Reset();
    void AddLine(const char* apText, void* apValue1, void* apValue2, int aiUnk);
};

extern Setting g_kChallengeRateSetting;
extern Setting g_kNoChallengesSetting;
extern unsigned int g_uiChallengeUpdateMS;


// Resets the display and list box, optionally adds the current challenge to the recent list, and rebuilds the challenge lines and tiles.
// @fnv 0x007586e0
void ComputersMenu::FUN_007586e0(bool abAddRecent)
{
    if (!reinterpret_cast<CHChallenge*>(terminal))
        return;

    CHString kText;
    reinterpret_cast<CHDisplay*>(manager)->Reset();
    reinterpret_cast<CHListBox&>(entries).Clear();
    if (abAddRecent)
        reinterpret_cast<CHSimpleList&>(notes).AddHead(reinterpret_cast<CHChallenge*&>(terminal));
    g_uiChallengeUpdateMS = (*reinterpret_cast<unsigned int*>(g_kChallengeRateSetting.Int()) > 0) ? 1000 / *reinterpret_cast<unsigned int*>(g_kChallengeRateSetting.Int()) : 1000;

    const char* pDescription = reinterpret_cast<CHChallenge*>(terminal)->kDescription.Get(reinterpret_cast<CHChallenge*>(terminal), 0x43534544);
    CHValue* pTextValue = reinterpret_cast<CHValue*>(tile44->GetValue(0xfc4));
    if (pDescription && *pDescription && (!tile44->IsVisible() || CHStricmp(pDescription, pTextValue->GetString())))
    {
        tile64->SetInt(0xfa3, 0);
        reinterpret_cast<CHDisplay*>(manager)->AddLine(pDescription, pTextValue, reinterpret_cast<TileCompatibility*>(tile44)->FindTraitValue(0xfa3), -1);
    }

    for (CHListNode* pIter = reinterpret_cast<CHChallenge*>(terminal)->GetChallengeList(); pIter && *pIter->GetItem(); pIter = pIter->GetNext())
    {
        if ((*pIter->GetItem())->kCondition.Evaluate(reference, 0))
        {
            Tile* pItemTile = reinterpret_cast<CHListBox&>(entries).Insert(*pIter->GetItem(), 0, 0, 0);
            pItemTile->SetInt(CHTraitNameToID("_enabled", -1), 0);
            pItemTile->SetInt(0xfd6, (*pIter->GetItem())->IsCompleted() ? 2 : 1);
            CHSprintf(&kText, "%s%s", "> ", (*pIter->GetItem())->GetName());
            reinterpret_cast<CHDisplay*>(manager)->AddLine(kText.CStr(), pItemTile->GetValue(0x1004), pItemTile->GetValue(0xfa3), -1);
        }
        (*pIter->GetItem())->SetSeen(false);
    }

    if (reinterpret_cast<CHSimpleList&>(notes).GetNext())
    {
        Tile* pEmptyTile = reinterpret_cast<CHListBox&>(entries).Insert(0, 0, 0, 0);
        pEmptyTile->SetInt(CHTraitNameToID("_enabled", -1), 0);
        CHSprintf(&kText, "%s%s", "> ", g_kNoChallengesSetting.FUN_00403df0());
        reinterpret_cast<CHDisplay*>(manager)->AddLine(kText.CStr(), pEmptyTile->GetValue(0x1004), pEmptyTile->GetValue(0xfa3), -1);
    }
    bRefreshed = true;
}

struct FUN_00ad73b0_t
{
    BSSoundHandle FUN_00ad73b0(unsigned int auiFormID, unsigned int auiFlags);
};


// @fnv 0x00759030
void ComputersMenu::PlayNoteSound(BGSNote* apNote)
{
    ((FUN_00ad73b0_t*)BSAudio::GetSingleton())
        ->FUN_00ad73b0(apNote->FUN_005e9100()->GetFormID(), 0x101)
        .Play(false);
}

extern Setting g_011d4bb8;
extern int DAT_0119f278;
// local form of BSStringT<char>: 0x007590c0 needs the one-argument Set call; the shared two-argument declaration changes bytes.
struct TextString
{
    char* text;
    unsigned short len, capacity;
    bool Set(const char*);
    operator const char*() const;
    unsigned int Length() const;
};
struct TextLayout
{
    TextLayout(int, int, int, int, int);
    ~TextLayout();
    operator const char*() const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int consumed;
    int unk1c;
    int unk20;
    int unk24;
};
struct TextFont
{
    float Height();
    void Format(const char*, TextLayout*);
};
struct TextFonts
{
    static TextFonts* Instance();
    TextFont* GetFont(int);
};
struct TextAnimator
{
    void Clear();
    void SetText(const char*, void*, void*, int);
};
struct TextSource;
struct TextSourceInterface
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual const char* GetText(TextSource*, int, int);
};
struct TextSource
{
    TextSourceInterface* GetInterface();
};
unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);

// Clears the animator, configures tiles, fetches and formats the source text into a layout, then advances the text pointer past the consumed characters.
// @fnv 0x007590c0
void ComputersMenu::SetTextSource(TextSource* source)
{
    manager->Clear();
    DAT_0119f278 = *reinterpret_cast<unsigned int*>(g_011d4bb8.Int()) > 0 ? 1000 / *reinterpret_cast<unsigned int*>(g_011d4bb8.Int()) : 1000;
    tile2c->Set(0xfa3, 0);
    tile30->Set(0xfa9, 0);
    tile30->Set(0xfa3, 1);
    if (unkbc == 0)
    {
        reinterpret_cast<TextString&>(text).Set(source->GetInterface()->GetText(source, 0x4d414e54, 0));
        unkbc = reinterpret_cast<TextString&>(text);
    }
    int lines = (int)(tile60->Read(0xfbc) -
                      tile44->Read(0xfb0) / TextFonts::Instance()->GetFont((int)tile44->Read(0xfb9) - 1)->Height()) +
                1;
    TextLayout textLayout((int)tile60->Read(0xfba), 0, 0, lines, 10);
    TextFonts::Instance()->GetFont((int)tile60->Read(0xfb9) - 1)->Format(unkbc, &textLayout);
    manager->SetText(textLayout, tile60->GetValue(0xfc4), reinterpret_cast<TileCompatibility*>(tile60)->FindTraitValue(0xfa3), -1);
    unkbc += FUN_0042f5a0(textLayout.consumed, reinterpret_cast<TextString&>(text).Length());
    if (!*unkbc)
        unkbc = 0;
}

namespace fnv_007598d0 {
struct QueueText
{
    ~QueueText();
    bool FUN_00759d80();
    const char* FUN_00458b50();
    const char* FUN_0059bb30();
    unsigned int FUN_0044edb0();
    Tile* FUN_007001f0();
    void FUN_006ffea0();
};
struct TextQueue
{
    bool FUN_0076b610() const;
    QueueText** FUN_0073ac90();
    QueueText* PopFrontScript();
    void ProcessQueue();
};
struct TextAudioManager
{
    BSSoundHandle ResolveAudioHandle(const char*, unsigned int);
};
TextAudioManager* FUN_00ad9060();
unsigned int FUN_0044a670(const char*);
extern unsigned int DAT_011d93d4;
extern const char DAT_01072118[];
// @fnv 0x007598d0
void TextQueue::ProcessQueue()
{
    bool hasTrait = false;
    while (!FUN_0076b610() && gm_GetTickCount() > DAT_011d93d4)
    {
        if ((*FUN_0073ac90())->FUN_00759d80())
        {
            QueueText* removed = PopFrontScript();
            if (!reinterpret_cast<ComputersMenu*>(DAT_011d9334)->unkb0)
            {
                if (removed && *removed->FUN_00458b50() == *DAT_01072118)
                    reinterpret_cast<BSSoundHandle&>(reinterpret_cast<ComputersMenu*>(DAT_011d9334)->sounds[2]).Play(false);
                DAT_011d93d4 = gm_GetTickCount() + 500;
            }
            else if (removed && removed->FUN_007001f0() == reinterpret_cast<ComputersMenu*>(DAT_011d9334)->tile44)
            {
                reinterpret_cast<ComputersMenu*>(DAT_011d9334)->tile64->FUN_00700320(0xfa3, 1);
            }
            delete removed;
        }
        else
        {
            int x;
            {
                Tile* tile;
                {
                    int y;
                    {
                        unsigned int oldLength = 0;
                        unsigned int newLength = 0;
                        if (!reinterpret_cast<ComputersMenu*>(DAT_011d9334)->unkb0 &&
                            *(*FUN_0073ac90())->FUN_00458b50() == *DAT_01072118)
                        {
                            oldLength = FUN_0044a670((*FUN_0073ac90())->FUN_0059bb30());
                            (*FUN_0073ac90())->FUN_006ffea0();
                            newLength = FUN_0044a670((*FUN_0073ac90())->FUN_0059bb30());
                            for (unsigned int index = 0; index < newLength - oldLength; index++)
                            {
                                unsigned int offset =
                                    (*FUN_0073ac90())->FUN_0044edb0() * index / (newLength - oldLength);
                                FUN_00ad9060()
                                    ->ResolveAudioHandle("UIHackingCharSingle", 0x121)
                                    .PlayAfter(offset, 0);
                            }
                        }
                        else
                        {
                            (*FUN_0073ac90())->FUN_006ffea0();
                            reinterpret_cast<BSSoundHandle&>(reinterpret_cast<ComputersMenu*>(DAT_011d9334)->sounds[1]).Play(false);
                        }
                        x = 0;
                        y = 0;
                        tile = (*FUN_0073ac90())->FUN_007001f0();
                        hasTrait = tile->FUN_00a00f30(0xfba) != 0;
                        for (Tile* parent = tile;
                             parent &&
                             parent != reinterpret_cast<ComputersMenu*>(DAT_011d9334)->tile40->FUN_0045cd60();
                             parent = parent->FUN_0045cd60())
                        {
                            x += (int)parent->FUN_00a011b0(0xfa1);
                            y += (int)parent->FUN_00a011b0(0xfa2);
                        }
                        tile->FUN_00a04640(false);
                        if (reinterpret_cast<ComputersMenu*>(DAT_011d9334)
                                ->entries.ContainsKey(tile))
                        {
                            reinterpret_cast<TileCompatibility*>(tile)->FUN_00a04620(false);
                            reinterpret_cast<ComputersMenu*>(DAT_011d9334)
                                ->tile40->FUN_00a012d0(
                                    0xfa1,
                                    x + tile->FUN_00a011b0(reinterpret_cast<int>(FUN_00a00940("_text_width", -1))),
                                    true);
                            reinterpret_cast<ComputersMenu*>(DAT_011d9334)
                                ->tile40->FUN_00a012d0(
                                    0xfa2, y + tile->FUN_00a011b0(reinterpret_cast<int>(FUN_00a00940("_text_y", -1))),
                                    true);
                        }
                        else if (!hasTrait)
                        {
                            reinterpret_cast<ComputersMenu*>(DAT_011d9334)
                                ->tile40->FUN_00a012d0(0xfa1, x + tile->FUN_00a011b0(0xfb1), true);
                            reinterpret_cast<ComputersMenu*>(DAT_011d9334)->tile40->FUN_00700320(0xfa2, y);
                        }
                        break;
                    }
                }
            }
        }
    }
    if (FUN_0076b610() || hasTrait)
    {
        reinterpret_cast<ComputersMenu*>(DAT_011d9334)
            ->tile40->FUN_00a012d0(
                0xfa1,
                reinterpret_cast<ComputersMenu*>(DAT_011d9334)->tile3c->FUN_00a011b0(0xfa1) +
                    (reinterpret_cast<ComputersMenu*>(DAT_011d9334)->tile3c->IsAllChildrenFlag0()
                         ? reinterpret_cast<ComputersMenu*>(DAT_011d9334)->tile3c->FUN_00a011b0(0xfb1)
                         : 0.0f),
                true);
        reinterpret_cast<ComputersMenu*>(DAT_011d9334)
            ->tile40->FUN_00a012d0(
                0xfa2, reinterpret_cast<ComputersMenu*>(DAT_011d9334)->tile3c->FUN_00a011b0(0xfa2), true);
    }
}
}  // namespace fnv_007598d0

int __cdecl TraitNameToID(const char* apName, int aiDefault);

struct LBTileValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int aiOperator, Tile* apTile, int aiID);
    void AppendFloatAction(int aiOperator, float afValue);
    void FUN_00a09410(int aiFlag);
};

struct LBTileMenu
{
    Tile* AddTileFromTemplate(Tile* apParent, const char* apTemplate, int aiUnk);
};

struct LBItem
{
    Tile* pTile;
    int iObject;
    int iUnk08;
    LBItem(Tile* apTile, const int& arObject);
};

struct LBItemList
{
    LBItem* pFirst;
    void* pNext;
    void InsertSorted(LBItem* apItem, int(__cdecl* apSort)(LBItem*, LBItem*));
    void Append(LBItem* const& arItem);
};

struct LBListBox
{
    virtual void v00();
    LBItemList kList;
    Tile* pParentTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;

    bool FUN_007242c0(int aiUnk);
    void ResetAndProcessNodes();
    void AccumulateTileHeight(Tile* apTile);
    void UpdateScrollItems();
    int GetRaceCount();
    Tile* AddItem(int aiObject, const char* apText, int(__cdecl* apSort)(LBItem*, LBItem*),
                    const char* apTemplateName);
};

// @fnv 0x0075a110
Tile* LBListBox::AddItem(int aiObject, const char* apText, int(__cdecl* apSort)(LBItem*, LBItem*),
                           const char* apTemplateName)
{
    if (pParentTile && (pTemplateName || apTemplateName))
    {
        Tile* pTile = reinterpret_cast<LBTileMenu*>(pParentTile->GetMenu())->AddTileFromTemplate(pParentTile,
                                                                    apTemplateName ? apTemplateName : pTemplateName, 0);
        if (!pTile->GetValue(0xfaa))
            pTile->SetInt(0xfaa, -1);
        if (apText)
            pTile->SetString(0xfc4, apText, true);
        if (apSort)
        {
            kList.InsertSorted(new LBItem(pTile, aiObject), apSort);
            if (FUN_007242c0(0))
                ResetAndProcessNodes();
        }
        else
        {
            kList.Append(new LBItem(pTile, aiObject));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(pTile);
                UpdateScrollItems();
            }
            pTile->SetInt(0xfac, usItemCount++);
        }
        if (GetRaceCount() == 1 && pParentTile->GetFloat(TraitNameToID("_number_of_visible_items", -1)) > 0.0)
        {
            LBTileValue* pAction = static_cast<LBTileValue*>(reinterpret_cast<TileCompatibility*>(pParentTile)->FindTraitValue(0xfb0));
            pAction->RemoveFromReactions();
            pAction->FUN_00a09130(0x7d0, pTile, 0xfb0);
            pAction->AppendFloatAction(0x7d3, pParentTile->GetFloat(TraitNameToID("_number_of_visible_items", -1)));
            pAction->FUN_00a09410(0);
        }
        return pTile;
    }
    else
        return 0;
}

struct OwnedObject
{
    virtual ~OwnedObject();
};
struct OwnedText
{
    ~OwnedText();
};
struct AnimationEntry
{
    OwnedObject* object;
    OwnedText* text;
};
struct AnimationNode
{
    AnimationEntry** FUN_006815c0();
    AnimationNode* FUN_00726070();
    void FUN_006ecd40(int value);
    ~AnimationNode();
};
extern bool s_bAllowDetach;
int __cdecl FUN_00a01860(const char* name);
struct AnimationList
{
    int unk00;
    AnimationEntry* entry;
    AnimationNode* node;
    Tile* tile;
    Tile* currentTile;
    int unk14;
    int unk18;
    unsigned short count;
    unsigned short unk1e;
    float elapsed;
    bool FUN_007242c0(unsigned int flag);
    void UpdateScrollItems();
    void UpdateHighlight();
    void ClearEntries();
};
// Deletes the node chain and entry, optionally their object/text, resets count and elapsed, clears the tile filter, and resets currentTile.
// @fnv 0x0075a3b0
void AnimationList::ClearEntries()
{
    while (node && *node->FUN_006815c0())
    {
        AnimationNode* next = node->FUN_00726070();
        if (!s_bAllowDetach)
            delete (*node->FUN_006815c0())->object;
        if (FUN_007242c0(1))
            delete (*node->FUN_006815c0())->text;
        delete *node->FUN_006815c0();
        node->FUN_006ecd40(0);
        delete node;
        node = next;
    }
    if (entry)
    {
        if (!s_bAllowDetach)
            delete entry->object;
        if (FUN_007242c0(1))
            delete entry->text;
        delete entry;
    }
    entry = 0;
    count = 0;
    elapsed = 0.0f;
    if (tile)
        tile->Set(FUN_00a01860("_num_filtered"), 0.0f, true);
    UpdateScrollItems();
    currentTile = 0;
    UpdateHighlight();
}

float __cdecl FUN_004bd510(float, float);
int __cdecl FUN_00a01860(const char*);

struct MyInner
{
    Tile* m_00;
};

struct MyRef
{
    MyInner* p;
};

struct MyNode
{
    void* m_item;
    MyNode* m_next;
    MyRef* __thiscall FUN_006815c0();
    MyNode* __thiscall FUN_00726070();
};

struct MyListBox
{
    virtual void* v00();
    virtual void* v04();
    virtual void* v08();
    virtual void* v0c();
    virtual void* v10();
    virtual Tile* FUN_0075a955(int, int);

    MyNode m_kNode;
    Tile* m_tile0c;
    Tile* m_tile10;
    int m_unk14;
    int m_unk18;
    unsigned short m_count1c;

    bool __thiscall IsTileTraitEnabled();
    Tile* GetScrollTargetTile(int a1);
};

// Resolves a scroll direction into a step, finds the enabled tile at the clamped index in the list, and returns it unless it is the current tile.
// @fnv 0x0075a680
Tile* MyListBox::GetScrollTargetTile(int aiScrollCode)
{
    Tile* pFound_ = 0;
    int iTileIndex = 0;

    switch (aiScrollCode)
    {
    case 2:
        iTileIndex = 1;
        break;
    case 1:
        iTileIndex = -1;
        break;
    case 15:
        iTileIndex =
            m_tile0c ? (int)FUN_004bd510(
                           -m_tile0c->FUN_00a011b0(0xfb0) / m_tile0c->FUN_00a011b0(FUN_00a01860("_scroll_delta")), 1.0f)
                     : 0;
        break;
    case 16:
        iTileIndex =
            m_tile0c ? (int)FUN_004bd510(
                           m_tile0c->FUN_00a011b0(0xfb0) / m_tile0c->FUN_00a011b0(FUN_00a01860("_scroll_delta")), 1.0f)
                     : 0;
        break;
    default:
        break;
    }

    if (IsTileTraitEnabled() && iTileIndex && m_count1c)
    {
        int maxIdxTmp = m_count1c - 1;
        int curIdx;
        if (m_tile10)
        {
            int selIdx = (int)m_tile10->FUN_00a011b0(0xfac);
            curIdx = selIdx + iTileIndex;
            if (curIdx < 0)
                curIdx = 0;
            else if (curIdx > maxIdxTmp)
                curIdx = maxIdxTmp;
        }
        else
        {
            if (iTileIndex > 0)
                curIdx = 0;
            else
                curIdx = maxIdxTmp;
        }

        while (1)
        {
            for (MyNode* pNodeA = this ? &m_kNode : 0; !pFound_ && pNodeA && pNodeA->FUN_006815c0()->p;
                 pNodeA = pNodeA->FUN_00726070())
            {
                if (pNodeA->FUN_006815c0()->p->m_00->FUN_00a011b0(0xfac) == (float)curIdx)
                {
                    pFound_ = pNodeA->FUN_006815c0()->p->m_00;
                }
            }

            if (pFound_ && !pFound_->IsTraitNonZero((int)FUN_00a00940("_enabled", -1)))
            {
                pFound_ = 0;
                if (iTileIndex > 0 && ++curIdx > maxIdxTmp)
                {
                    curIdx = maxIdxTmp - 1;
                    while ((!pFound_ || !pFound_->IsTraitNonZero((int)FUN_00a00940("_enabled", -1))) && curIdx >= 0)
                    {
                        pFound_ = FUN_0075a955(curIdx--, 0);
                    }
                    break;
                }
                else if (iTileIndex < 0 && --curIdx < 0)
                {
                    curIdx = 1;
                    while ((!pFound_ || !pFound_->IsTraitNonZero((int)FUN_00a00940("_enabled", -1))) &&
                           curIdx <= maxIdxTmp)
                    {
                        pFound_ = FUN_0075a955(curIdx++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    return (pFound_ != m_tile10) ? pFound_ : 0;
}

struct FUN_0075b020_cls
{
    unsigned int __thiscall FUN_0075b020();
};

struct ScrollData
{
    int unk00;
    int unk04;
    int unk08;
    Tile* pTile0c;
    int unk10;
    Tile* pTile14;
};

extern double DAT_01012060;
float __cdecl FUN_004e4430(float afValue);
int __cdecl FUN_00647b70(int aiMinimum, int aiValue);
int __cdecl FUN_00a01860(const char* apText);

// Computes the number of scroll items from the tile value and m_20, sets _scroll_delta on the tile and _number_of_items on the list.
// @fnv 0x0075aef0
void FUN_0075aa50_cls::UpdateScrollItems()
{
    float fTimeOffset;
    int iNumberOfItems;
    if (((ScrollData*)this)->pTile0c != 0)
    {
        fTimeOffset = ((ScrollData*)this)->pTile0c->FUN_00a011b0(0xfb0);
        iNumberOfItems = 1;

        if (m_20 > DAT_01012060 && fTimeOffset > DAT_01012060)
        {
            if (m_20 > fTimeOffset)
            {
                iNumberOfItems =
                    FUN_00647b70((int)FUN_004e4430(
                                     ((float)((FUN_0075b020_cls*)this)->FUN_0075b020() * (m_20 - fTimeOffset)) / m_20) +
                                     1,
                                 2);
            }

            if (iNumberOfItems > 1)
            {
                ((ScrollData*)this)->pTile0c
                    ->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (m_20 - fTimeOffset) / (iNumberOfItems - 1), true);
            }
        }

        if (((ScrollData*)this)->pTile14 != 0)
        {
            ((ScrollData*)this)->pTile14->FUN_00700320(FUN_00a01860("_number_of_items"), iNumberOfItems);
        }
    }
}

namespace fnv_00757b70 {
struct Terminal;
struct Ref
{
    Terminal* GetTerminal();
};
struct Terminal
{
    unsigned char IsFlagBitSet();
    bool CanUse(Ref*);
};
struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
};
struct Colors
{
    static Colors* Singleton();
    bool Get(int, int*);
    void Set(int, Color const&);
};
extern int DAT_011d934c;
extern ComputersMenu* gComputerMenu;
struct KeyState
{
    unsigned char Check(int, int, int);
};
struct UI
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    unsigned char unkc3;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    KeyState keys;
    Tile* Root();
};
UI* GetUI();
int FUN_00757e20();
ComputersMenu* FindMenu(int);
float GetDefault();
void Warn(const char*, ...);
// @fnv 0x00757b70
Tile* CreateComputerMenu(Ref* reference)
{
    ComputersMenu* oldMenu = FindMenu(FUN_00757e20());
    if (oldMenu)
    {
        delete oldMenu;
    }
    Colors::Singleton()->Get(3, &DAT_011d934c);
    Terminal* terminal = reference->GetTerminal();
    if (terminal->IsFlagBitSet())
        Colors::Singleton()->Set(3, Color(1.0f, 1.0f, 1.0f, 0.0f));
    float defaultValue = GetDefault();
    Tile* aTile = GetUI()->Root()->ReadFile("Data\\Menus\\computers_menu.xml");
    ComputersMenu* menu = reinterpret_cast<ComputersMenu*>(aTile->GetMenu());
    if (menu && menu->GetClass() == FUN_00757e20())
    {
        menu->SetTileMenu(reinterpret_cast<TileMenu*>(aTile), false);
        gComputerMenu = menu;
        int iMissingIndex;
        if (!gComputerMenu->HasAllTiles(&iMissingIndex))
        {
            Warn("MENUS: Computers Menu Creation Failed... Missing index = #%d", iMissingIndex);
            return 0;
        }
        else if (!reference)
        {
            Warn("MENUS: Computers Menu Creation Failed... Missing terminal data ");
            return 0;
        }
        if (aTile->FUN_00a011b0(0xfa7) == 6006.0 || aTile->FUN_00a011b0(0xfa7) == 102.0)
            aTile->Set(0xfad, defaultValue, true);
        reinterpret_cast<unsigned char&>(gComputerMenu->unkc0) = GetUI()->keys.Check(0x18, FUN_00757e20(), 0x200);
        gComputerMenu->reference = reinterpret_cast<TESObjectREFR*>(reference);
        gComputerMenu->terminal = reinterpret_cast<BGSTerminal*>(terminal);
        gComputerMenu->entries.Initialize(gComputerMenu->tile2c, "computers_file_template");
        reinterpret_cast<BSSoundHandle&>(gComputerMenu->sounds[0]).Play(false);
        if (reinterpret_cast<Terminal*>(gComputerMenu->terminal)->CanUse(reinterpret_cast<Ref*>(gComputerMenu->reference)))
            gComputerMenu->RefreshDisplay();
        else
            gComputerMenu->BuildAnimation();
        menu->SetMenuVisibility(false);
        return aTile;
    }
    else
    {
        if (menu && menu->GetTile())
        {
            delete menu;
        }
    }
    return 0;
}
}  // namespace fnv_00757b70

Tile* __cdecl FUN_00a08b20(Tile* root, const char* path);
// @fnv 0x0075abd0
__declspec(dllexport) __declspec(noinline) inline void HighlightList_computersmenu::UpdateHighlight()
{
    static const char* highlightY = FUN_00a00940("_highlight_y", -1);
    static const char* selectedHeight = FUN_00a00940("_selected_height", -1);
    if (container)
    {
        if (selected)
        {
            HighlightValue_computersmenu* heightValue = static_cast<HighlightValue_computersmenu*>(container->FUN_00a00f30(reinterpret_cast<int>(highlightY)));
            HighlightValue_computersmenu* yValue = static_cast<HighlightValue_computersmenu*>(container->FUN_00a00f30(reinterpret_cast<int>(selectedHeight)));
            heightValue->FUN_00a09130(2000, selected, 4002);
            heightValue->FUN_00a09410(0);
            yValue->FUN_00a09130(2000, selected, 4016);
            yValue->FUN_00a09410(0);
            if (selected->GetSpeechChallengeFailure())
            {
                Tile* box = FUN_00a08b20(container, "lb_highlight_box");
                if (box)
                {
                    Tile* edge = box->GetNamedChild("top");
                    if (edge)
                    {
                        edge->FUN_0071aa60(true);
                        edge->SetChangeFlag(8);
                        edge = box->GetNamedChild("bottom");
                        edge->FUN_0071aa60(true);
                        edge->SetChangeFlag(8);
                        edge = box->GetNamedChild("left");
                        edge->FUN_0071aa60(true);
                        edge->SetChangeFlag(8);
                        edge = box->GetNamedChild("right");
                        edge->FUN_0071aa60(true);
                        edge->SetChangeFlag(8);
                    }
                    box->FUN_0071aa60(true);
                    box->SetChangeFlag(8);
                }
            }
            else
            {
                Tile* box = FUN_00a08b20(container, "lb_highlight_box");
                if (box)
                {
                    Tile* edge = box->GetNamedChild("top");
                    if (edge)
                    {
                        edge->FUN_0071aa60(false);
                        edge->SetChangeFlag(8);
                        edge = box->GetNamedChild("bottom");
                        edge->FUN_0071aa60(false);
                        edge->SetChangeFlag(8);
                        edge = box->GetNamedChild("left");
                        edge->FUN_0071aa60(false);
                        edge->SetChangeFlag(8);
                        edge = box->GetNamedChild("right");
                        edge->FUN_0071aa60(false);
                        edge->SetChangeFlag(8);
                    }
                    box->FUN_0071aa60(false);
                    box->SetChangeFlag(8);
                }
            }
        }
        else
        {
            container->FUN_00700320(reinterpret_cast<int>(highlightY), -1);
            container->FUN_00700320(reinterpret_cast<int>(selectedHeight), 0);
        }
    }
}

extern Setting g_011d3d78;
extern Setting g_011d4978;

unsigned int __cdecl BSStringLength(const char*);

struct MyDisplay
{
    void ProcessAllTiles();
    void InsertAtPosition(const char*, void*, void*, int);
};


// @fnv 0x00758d30
void ComputersMenu::RefreshDisplay()
{
    this->tile5c->FUN_00700320(0xFAF, 0);
    reinterpret_cast<MyDisplay*>(manager)->ProcessAllTiles();
    this->tile4c->FUN_00700320(0xFA3, 0);
    this->tile50->FUN_00700320(0xFA3, 0);
    this->tile54->FUN_00700320(0xFA3, 0);
    this->tile58->FUN_00700320(0xFA3, 0);
    this->FUN_007586e0(1);

    reinterpret_cast<MyDisplay*>(manager)->InsertAtPosition(g_011d3d78.FUN_004c69f0(), this->tile34->FUN_00a00f30(0xFC4),
                                     reinterpret_cast<TileCompatibility*>(this->tile34)->FindTraitValue(0xFA3), 0);
    this->tile34->FUN_00a012d0(
        0xFA1,
        (this->tile34->FUN_0045cd60()->FUN_00a011b0(0xFB1) - BSStringLength(g_011d3d78.FUN_00403df0()) * 17) / 2.0, 1);

    reinterpret_cast<MyDisplay*>(manager)->InsertAtPosition(g_011d4978.FUN_004c69f0(), this->tile38->FUN_00a00f30(0xFC4),
                                     reinterpret_cast<TileCompatibility*>(this->tile38)->FindTraitValue(0xFA3), 1);
    this->tile38->FUN_00a012d0(
        0xFA1,
        (this->tile38->FUN_0045cd60()->FUN_00a011b0(0xFB1) - BSStringLength(g_011d4978.FUN_00403df0()) * 17) / 2.0, 1);

    reinterpret_cast<MyDisplay*>(manager)->InsertAtPosition(reinterpret_cast<Host*>(terminal)->FUN_00758fe0(), this->tile28->FUN_00a00f30(0xFC4),
                                     reinterpret_cast<TileCompatibility*>(this->tile28)->FindTraitValue(0xFA3), 2);
    this->tile28->FUN_00a012d0(
        0xFA1,
        (this->tile28->FUN_0045cd60()->FUN_00a011b0(0xFB1) - BSStringLength(reinterpret_cast<Host*>(terminal)->FUN_00758fe0()) * 17) /
            2.0,
        1);

    reinterpret_cast<MyDisplay*>(manager)->InsertAtPosition("> ", this->tile48->FUN_00a00f30(0xFC4), reinterpret_cast<TileCompatibility*>(this->tile48)->FindTraitValue(0xFA3),
                                     -1);
    this->unkb0 = 2;
}

#include <string.h>
struct ConstructorAudio
{
    BSSoundHandle ResolveAudioHandle(const char*, unsigned int);
};
ConstructorAudio* FUN_00ad9060();
void PlayNoteSound();
void SetTextSource();
void UpdateNoteDisplay();


// Initializes the hacking menu by zeroing tiles, setting up audio handles for fan hum and character sounds, and assigning callback functions.
// @fnv 0x007577f0
ComputersMenu::ComputersMenu()
{
    memset(&tile28, 0, 0x40);
    manager = reinterpret_cast<TextAnimator*>(GetStorageSingleton());
    callbackec = ::PlayNoteSound;
    callbackf0 = ::SetTextSource;
    callbackf4 = UpdateNoteDisplay;
    unkf8 = 0;
    ConstructorAudio* audio = FUN_00ad9060();
    reinterpret_cast<BSSoundHandle&>(sounds[0]) = audio->ResolveAudioHandle("UIHackingFanHumLP", 0x31);
    reinterpret_cast<BSSoundHandle&>(sounds[1]) = audio->ResolveAudioHandle("UIHackingCharScroll", 0x21);
    reinterpret_cast<BSSoundHandle&>(sounds[2]) = audio->ResolveAudioHandle("UIHackingCharEnter", 0x21);
    unka0 = 0;
    unka4 = 0;
    terminal = 0;
    reference = 0;
    unkb0 = 0;
    unkbc = 0;
    unkc0 = false;
}

namespace fnv_00757f70 {
struct Value
{
    const char* FUN_0084e3a0();
};
struct BStr
{
    void* m_data;
    int m_len;
    BStr();
    ~BStr();
    const char* FUN_00559450();
};
struct Obj
{
    void* m_00;
    void* m_04;
    BStr m_str;
    void* m_rest[23];
    BGSNote* m_note;
    void* m_70;
    void SetFlag4(bool);
    void FUN_00501830(void*);
    bool FUN_00758350();
    bool FUN_00758390();
};
struct Mgr
{
    void ProcessAllTiles();
    void InsertAtPosition(const char*, void*, void*, int);
};
struct Player
{
    bool FUN_00966c10(BGSNote*);
    void FUN_00966a70(BGSNote*, int);
};
extern Player* DAT_011dea3c;
extern Setting DAT_011d3ca0;
extern Setting DAT_011d3e50;
extern unsigned char DAT_011d93c0;
unsigned int __cdecl FUN_00457fe0();
int __cdecl FUN_00406f60(BStr*, const char*, ...);
bool __cdecl DispatchMessageToSink(const char*, int, const char*, const char*, float, bool);
void __cdecl UpdateNoteTile(Tile*, void*);
}  // namespace fnv_00757f70

// Processes a tile index and optional tile pointer, updates tile and note display state, and may dispatch a note message to the player.
// @fnv 0x00757f70
void __thiscall ComputersMenu::FUN_00757f70(int aiTileIndex, Tile* apTile)
{
    using namespace fnv_00757f70;
    using fnv_00757f70::Obj;
    typedef void (ComputersMenu::*NoteHandler)(BGSNote*);
    if (!apTile && aiTileIndex >= 0 && aiTileIndex < 16)
        apTile = m_pTiles[aiTileIndex];
    int id = aiTileIndex;
    bool flag4 = false;
    Value* val;
    Obj* obj;
    if (id == 2)
    {
        reinterpret_cast<Mgr*>(manager)->ProcessAllTiles();
        if (unkbc != 0)
        {
            SetTextSource(0);
            flag4 = true;
        }
        else
        {
            m_pTiles[2]->FUN_00700320(0xfa3, 0);
            m_pTiles[1]->FUN_00700320(0xfa3, 1);
            if (DAT_011d93c0)
            {
                FUN_007586e0(0);
            }
            else
            {
                if (!m_pTiles[7]->IsAllChildrenFlag0())
                {
                    m_pTiles[15]->FUN_00700320(0xfa3, 0);
                    val = static_cast<Value*>(m_pTiles[7]->FUN_00a00f30(0xfc4));
                    reinterpret_cast<Mgr*>(manager)->InsertAtPosition(val->FUN_0084e3a0(), val, reinterpret_cast<TileCompatibility*>(m_pTiles[7])->FindTraitValue(0xfa3), -1);
                }
                entries.FUN_007314c0(&UpdateNoteTile, 0, 0x7fffffff);
                bRefreshed = 1;
            }
        }
        reinterpret_cast<BSSoundHandle&>(sounds[2]).Play(false);
    }
    else if (id == 13 && unkb0 < 2)
    {
        RefreshDisplay();
    }
    else
    {
        if (entries.ContainsKey(apTile))
        {
            reinterpret_cast<BSSoundHandle&>(sounds[2]).Play(false);
            obj = reinterpret_cast<Obj*>(entries.FindItemData(apTile));
            if (!obj)
            {
                FUN_00758a80();
            }
            else if (obj->m_70)
            {
                obj->SetFlag4(true);
                obj->FUN_00501830(reference);
                terminal = reinterpret_cast<BGSTerminal*>(obj->m_70);
                FUN_007586e0(1);
            }
            else
            {
                obj->SetFlag4(true);
                obj->FUN_00501830(reference);
                if (obj->m_str.FUN_00559450())
                {
                    reinterpret_cast<Mgr*>(manager)->InsertAtPosition(obj->m_str.FUN_00559450(), m_pTiles[5]->FUN_00a00f30(0xfc4),
                                                 reinterpret_cast<TileCompatibility*>(m_pTiles[5])->FindTraitValue(0xfa3), 0);
                    unka0 = FUN_00457fe0() + *DAT_011d3e50.FUN_0043d4d0() * 1000;
                }
                if (obj->m_note)
                {
                    if (obj->FUN_00758350() && !DAT_011dea3c->FUN_00966c10(obj->m_note))
                    {
                        DAT_011dea3c->FUN_00966a70(obj->m_note, 0);
                        {
                            BStr str;
                            FUN_00406f60(&str, DAT_011d3ca0.FUN_00403df0(), obj->m_note->TESFullName::GetFullName());
                            DispatchMessageToSink(str.FUN_00559450(), 0,
                                                  "Interface\\Icons\\Message Icons\\glow_message_giftbox.dds", 0, 2.0f,
                                                  false);
                        }
                    }
                    if (reinterpret_cast<NoteHandler*>(&callbackec)[obj->m_note->GetNoteType()])
                        (this->*reinterpret_cast<NoteHandler*>(&callbackec)[obj->m_note->GetNoteType()])(obj->m_note);
                    DAT_011d93c0 = obj->FUN_00758390();
                    flag4 = true;
                }
                else
                {
                    if (obj->FUN_00758390())
                        FUN_007586e0(0);
                }
            }
        }
    }
    if (!flag4)
        DAT_011d93c0 = 0;
}


namespace fnv_00758ad0 {
extern Setting g_011d3de4;
extern Setting g_011d4e4c;
extern Setting g_011d3a38;
extern Setting g_011d2ee0;
extern Setting g_011d430c;
extern int DAT_0119f278;
struct TerminalReference
{
    unsigned int FUN_00501270(void*);
};
int __cdecl FUN_00406f60(StrMem*, const char*, ...);
void __cdecl FUN_00403d30(void*, int, unsigned int);

}  // namespace fnv_00758ad0

// Inserts intro, prompt, header, and password tiles into the terminal animation sequence using timing settings and tile trait values.
// @fnv 0x00758ad0
void ComputersMenu::BuildAnimation()
{
    using namespace fnv_00758ad0;
    unsigned int promptDelay;
    {
        StrMem text;
        unsigned int introDelay = *reinterpret_cast<unsigned int*>(g_011d3de4.FUN_0043d4d0()) > 0 ? 1000 / *reinterpret_cast<unsigned int*>(g_011d3de4.FUN_0043d4d0()) : 1000;
        promptDelay = *reinterpret_cast<unsigned int*>(g_011d4e4c.FUN_0043d4d0()) > 0 ? 1000 / *reinterpret_cast<unsigned int*>(g_011d4e4c.FUN_0043d4d0()) : 1000;
        fnv_00758ad0::DAT_0119f278 = introDelay;
        reinterpret_cast<FUN_00759da0_shell*>(manager)->InsertAtPosition(g_011d3a38.FUN_004c69f0(), (int)tile4c->FUN_00a00f30(0xfc4),
                                    (int)reinterpret_cast<TileCompatibility*>(tile4c)->FindTraitValue(0xfa3), -1);
        fnv_00758ad0::DAT_0119f278 = promptDelay;
        FUN_00406f60(&text, "%s%s", "> ", g_011d2ee0.FUN_00403df0());
        reinterpret_cast<FUN_00759da0_shell*>(manager)->InsertAtPosition(text.FUN_00559450(), (int)tile50->FUN_00a00f30(0xfc4),
                                    (int)reinterpret_cast<TileCompatibility*>(tile50)->FindTraitValue(0xfa3), -1);
        fnv_00758ad0::DAT_0119f278 = introDelay;
        reinterpret_cast<FUN_00759da0_shell*>(manager)->InsertAtPosition(g_011d430c.FUN_004c69f0(), (int)tile54->FUN_00a00f30(0xfc4),
                                    (int)reinterpret_cast<TileCompatibility*>(tile54)->FindTraitValue(0xfa3), -1);
        fnv_00758ad0::DAT_0119f278 = promptDelay;
        char password[16];
        FUN_00403d30(password, 0, 16);
        FUN_00403d30(password, '*', reinterpret_cast<TerminalReference*>(terminal)->FUN_00501270(reference));
        FUN_00406f60(&text, "%s%s", "> ", password);
        reinterpret_cast<FUN_00759da0_shell*>(manager)->InsertAtPosition(text.FUN_00559450(), (int)tile58->FUN_00a00f30(0xfc4),
                                    (int)reinterpret_cast<TileCompatibility*>(tile58)->FindTraitValue(0xfa3), -1);
    }
}
