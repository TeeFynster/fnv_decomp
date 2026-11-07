#include "../../../../include/ListBox.h"
#include "../../../../include/BSSimpleArray.h"
#include "../../../../include/InterfaceManager.h"
// fallout/interface/menus/messagemenu.cpp: DelStandIn, MessageMenu, MessageMenuHandler, KeyMenu and more (28 functions)

#include "../../../../include/Setting.h"
#include "../../../../include/StrMem.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/MessageMenu.h"
#include "../../../../include/Menu.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/Tile.h"

static const int kGetClassValue = 1001;

// @fnv 0x007a8aa0
int MessageMenu::GetClass()
{
    return kGetClassValue;
}

void __cdecl MessageMenu_DisableMessageMenu(bool);

// @fnv 0x00703fe0
// src: XBOX_PDB 0x00703fe0
void __cdecl Interface_DisableMessageMenu(bool abDisable)
{
    MessageMenu_DisableMessageMenu(abDisable);
}

struct Member_007a8b10
{
    char pad[4];
    ~Member_007a8b10();
};
struct FUN_007a8b10 : public Menu
{
    Tile* m_pTiles[6];
    Member_007a8b10 m40;
    virtual ~FUN_007a8b10();
};
extern bool DAT_0119f348;
extern bool DAT_011da4ed;
extern bool DAT_011da4ee;
extern int DAT_011da4f0;
// Destructor that sets DAT_0119f348 to true, clears DAT_011da4f0, and if DAT_011da4ed is set, sets DAT_011da4ee to true.
// @fnv 0x007a8b10
FUN_007a8b10::~FUN_007a8b10()
{
    DAT_0119f348 = true;
    DAT_011da4f0 = 0;
    if (DAT_011da4ed)
        DAT_011da4ee = true;
}

namespace fnv_007a8df0 {
// Exe 0x007a8df0: unit-local Interface view; declarations and layout are preserved.
class MessagemenuInterfaceView
{
  public:
    static bool __cdecl IsInDialog(void);
};

extern void* DAT_011da4f0;
Tile* __fastcall _ref_00726070(void*);
int __cdecl Interface_GetCurrentRenderedMenu();
void __fastcall InstantFadeOut(void*);
void __fastcall FUN_00a1d910(void*);
void __cdecl SetDialogMenuActive(int);

// @fnv 0x007a8df0
// src: XBOX_PDB 0x007a8df0
void __cdecl MessageMenu_Close()
{
    if (DAT_011da4f0)
    {
        _ref_00726070(DAT_011da4f0)->Set(0x1772, 1);
        if (Interface_GetCurrentRenderedMenu())
            InstantFadeOut(DAT_011da4f0);
        else
            FUN_00a1d910(DAT_011da4f0);

        if (MessagemenuInterfaceView::IsInDialog() && !PlayerCharacter::UpdatePlayerStatus())
            SetDialogMenuActive(0);
    }
}
}  // namespace fnv_007a8df0

// @fnv 0x007a9280
char __fastcall GetByteAtOffset56(char* pThis)
{
    return pThis[0x38];
}

template <class T, unsigned int N> class BSSimpleArray;


extern unsigned int DAT_011da4f4;
extern BSSimpleArray<unsigned int, 1024> g_011da53c;

// Returns the element at index DAT_011da4f4 from g_011da53c if that index is below the object's flags, otherwise 0.
// @fnv 0x007a92a0
unsigned int __cdecl GetCurrentArrayElement()
{
    unsigned int uiResult = 0;
    if (DAT_011da4f4 < reinterpret_cast<TESObjectREFR*>(&g_011da53c)->GetFlags())
    {
        uiResult = g_011da53c.GetAt(DAT_011da4f4);
    }
    return uiResult;
}

class RecursiveLock;
class NiAVObject;
class NiNode;
class TileShaderProperty;
namespace fnv_007aa070 {
struct MenuValueDescriptor;
struct FUN_007aa070_shell : public MessageMenu
{
    void HandleTileSelection(int, Tile*);
};

void* __cdecl InterfaceManager_GetSingleton(void);
void* __cdecl GetCurrentArrayElement(void);
void __cdecl CleanupGlobalObject(void);
extern bool DAT_011da4ed;
extern bool DAT_011da4ee;

class PerkForm;
using ::ListBox;

// Resolves a tile by ID when none is given, and for ID 7 stores the list-box result into a global and runs the selection callbacks.
// @fnv 0x007aa070
void FUN_007aa070_shell::HandleTileSelection(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 6)
    {
        apTarget = ((Tile**)((char*)this + 0x28))[aiID];
    }
    if (aiID == 7 && apTarget)
    {
        *(unsigned char*)((char*)InterfaceManager_GetSingleton() + 0xe4) =
            (unsigned char)(int)((ListBox<PerkForm*>*)((char*)this + 0x40))->GetSelectedData(apTarget);
        DAT_011da4ed = true;
        if (GetCurrentArrayElement() && *(void(__cdecl**)())((char*)GetCurrentArrayElement() + 0x28))
        {
            (*(void(__cdecl**)())((char*)GetCurrentArrayElement() + 0x28))();
        }
        DAT_011da4ed = false;
        if (DAT_011da4ee)
        {
            DAT_011da4ee = false;
        }
        else
        {
            CleanupGlobalObject();
        }
    }
}
}  // namespace fnv_007aa070

namespace fnv_007aa480 {
struct Elem_007aa480
{
    int Destroy(bool);
};
struct GlobalObject_007ab590
{
    unsigned int GetFlags();
    unsigned int& GetAt(int);
    void Clear(bool);
};
extern GlobalObject_007ab590 g_011da53c;
extern int DAT_011da4f4;
// Iterates the global object's elements, calls Destroy(true) on each non-null one, then clears the object and resets DAT_011da4f4 to 0.
// @fnv 0x007aa480
void ClearAllElements()
{
    for (unsigned int i = 0; i < g_011da53c.GetFlags(); i++)
    {
        Elem_007aa480* p;
        unsigned int v = g_011da53c.GetAt(i);
        p = reinterpret_cast<Elem_007aa480*>(v);
        p ? p->Destroy(true) : 0;
    }
    g_011da53c.Clear(true);
    DAT_011da4f4 = 0;
}
}  // namespace fnv_007aa480

namespace fnv_007aa530 {
struct Elem_007aa530
{
    int Destroy(bool);
};
struct Obj_007aa530
{
    void PopulateFromMessageData();
};
struct GlobalObject_007ab590
{
    unsigned int& GetAt(int);
    void Remove(unsigned int, bool);
};
extern GlobalObject_007ab590 g_011da53c;
extern int DAT_011da4f4;
extern Obj_007aa530* DAT_011da4f0;
int __cdecl GetCurrentArrayElement();
void __cdecl MessageMenu_Close();
// @fnv 0x007aa530
void CleanupGlobalObject()
{
    unsigned int u;
    if (GetCurrentArrayElement())
    {
        u = g_011da53c.GetAt(DAT_011da4f4);
        Elem_007aa530* p;
        unsigned int v = u;
        p = reinterpret_cast<Elem_007aa530*>(v);
        p ? p->Destroy(true) : 0;
        g_011da53c.Remove(DAT_011da4f4, true);
    }
    if (!GetCurrentArrayElement())
        MessageMenu_Close();
    else if (DAT_011da4f0)
        DAT_011da4f0->PopulateFromMessageData();
}
}  // namespace fnv_007aa530

namespace fnv_007aa6b0 {
extern Setting g_011c3ea4;
extern bool DAT_011da4ec;
extern int DAT_011da4f0;
void __cdecl MessageMenu_Close();
void __cdecl MessageMenu_Create();
int __cdecl GetCurrentArrayElement();
void __cdecl Interface_QueueMenuCreate(int, int, int, int, int, int);
// Stores the flag in DAT_011da4ec and calls FUN_007a8df0 or FUN_007a8ba0/FUN_00709470 depending on DAT_011da4f0 and GetCurrentArrayElement.
// @fnv 0x007aa6b0
// src: XBOX_PDB 0x007aa6b0
void MessageMenu_DisableMessageMenu(bool a)
{
    DAT_011da4ec = a;
    if (DAT_011da4f0 && DAT_011da4ec)
        MessageMenu_Close();
    if (!DAT_011da4f0 && !DAT_011da4ec && GetCurrentArrayElement())
    {
        if (*g_011c3ea4.Int() > 1)
            Interface_QueueMenuCreate(7, 0, 0, 0, 1, 0);
        else
            MessageMenu_Create();
    }
}
}  // namespace fnv_007aa6b0

struct Al_007ab000
{
    char c;
};
struct Str_007ab000
{
    char data[0x1c];
    ~Str_007ab000();
    Str_007ab000(const Str_007ab000&, unsigned int, unsigned int, const Al_007ab000&);
    Al_007ab000 EvaluateValue_007ab230() const;
    Str_007ab000 Substr(unsigned int _Off, unsigned int _Count) const;
};
// Returns a copy of the string constructed from this, _Off, _Count and the result of FUN_007ab230().
// @fnv 0x007ab000
Str_007ab000 Str_007ab000::Substr(unsigned int _Off, unsigned int _Count) const
{
    return Str_007ab000(*this, _Off, _Count, EvaluateValue_007ab230());
}

struct FUN_007abdb0_shell : public MessageMenu
{
    bool QuantityMenu_IsWellFormedMenu();
};

// Checks the six int entries at offset 0x28 and returns true only if none of them is zero.
// @fnv 0x007abdb0
// src: XBOX_PDB 0x007abdb0
bool FUN_007abdb0_shell::QuantityMenu_IsWellFormedMenu()
{
    for (int i = 0; i < 6; ++i)
    {
        if (*((int*)((char*)this + 0x28) + i) == 0)
            return false;
    }
    return true;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_007a8ae0(unsigned int flags);
};
// Runs the destructor on this object, then frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x007a8ae0
void* DelStandIn::FUN_007a8ae0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_007aa500 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Calls the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x007aa500
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_007aa500


InterfaceManager* __cdecl InterfaceManager_GetSingleton();
int __cdecl Tile_TextToTrait(const char* apTraitName);
struct FUN_007a8850
{
    StrMem strMessage;
    int iIcon;
    StrMem m_kTitle;
    StrMem strButtonText;
    bool bHasButtons;
    StrMem m_kSecondaryButtonText;
    int iButtonCount;
    int iType;
    StrMem strSound;
    bool bPauseGame;
    int iTileID;
    int iCallbackID;
    float fDisplayTime;
    float fBackgroundAlpha;
    int iFlags;
    FUN_007a8850();
};
// @fnv 0x007a8850
FUN_007a8850::FUN_007a8850()
{
    iIcon = 0;
    bHasButtons = false;
    iButtonCount = 0;
    iType = 0;
    bPauseGame = true;
    iTileID = -1;
    iCallbackID = -1;
    fDisplayTime = 0.0f;
    fBackgroundAlpha = InterfaceManager_GetSingleton()->GetAVEffect()->GetFloat(Tile_TextToTrait("_background_fill_alpha"));
    iFlags = 0;
}

// @fnv 0x007a8de0
// src: COMMUNITY 0x007a8de0
int MessageMenu_GetMenuID_()
{
    return 1001;
}

extern char DAT_01202d54;

// @fnv 0x007aa6a0
// src: COMMUNITY 0x007aa6a0
void MessageHandler_SetYesToAll(unsigned char value)
{
    DAT_01202d54 = value;
}

namespace fnv_007aaf20 {
// Exe 0x007aaf20: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct MessagemenuOffset08View
{
    unsigned int __thiscall GetFlags(void);
};

extern unsigned int DAT_011da4f4;
extern unsigned char DAT_011da4ec;
extern unsigned char DAT_011da594;
extern void __cdecl MessageMenu_Close(void);
extern void __cdecl MessageMenu_DisableMessageMenu(unsigned char);
extern MessagemenuOffset08View g_011da53c;

// @fnv 0x007aaf20
// src: XBOX_PDB 0x007aaf20
void __cdecl MessageMenu_SetPauseMenuMode(bool abFlag)
{
    if (abFlag)
    {
        DAT_011da4f4 = g_011da53c.GetFlags();
        MessageMenu_Close();
        DAT_011da594 = DAT_011da4ec;
        MessageMenu_DisableMessageMenu(0);
    }
    else
    {
        DAT_011da4f4 = 0;
        MessageMenu_DisableMessageMenu(DAT_011da594);
    }
}
}  // namespace fnv_007aaf20

struct Arr
{
    unsigned int* GetAt(int);
};

struct FUN_006f2270
{
    int m0;
    int m1;
    int m2;
    unsigned int* GetLast();
};

// @fnv 0x006f2270
unsigned int* FUN_006f2270::GetLast()
{
    return ((Arr*)this)->GetAt(m2 - 1);
}

struct FUN_007aafe0_Class
{
    void FindSubstring_Thunk(void* ap1, void* ap2);
    void FindSubstring(void* p, void* q, int n);
};

// @fnv 0x007aafe0
// src: GUESS 0x007aafe0 (confidence: medium)
void FUN_007aafe0_Class::FindSubstring_Thunk(void* pFirst, void* pSecond)
{
    FindSubstring(&pFirst, pSecond, 1);
}

struct MessageMenuHandler
{
    void ReplaceSubstring(void* first, void* second, void* third, unsigned int derivedValue);
    void ProcessState_007aaf80(void* first, void* second, void* third);
};

unsigned int __cdecl BSstrlen(void* value);

// Calls FUN_007ab0a0 with the three arguments and the value returned by FUN_0044a670(third).
// @fnv 0x007aaf80
// src: GUESS 0x007aaf80 (confidence: low)
void MessageMenuHandler::ProcessState_007aaf80(void* first, void* second, void* third)
{
    ReplaceSubstring(first, second, third, BSstrlen(third));
}

void __cdecl FUN_00ec7c56(void);

struct FUN_007aafb0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int __thiscall std_string__Myptr();
    int __thiscall GetCharacterPointerChecked(unsigned int arg);
};

// If arg exceeds unk14, calls FUN_00ec7c56; then returns the result of FUN_0044a970() plus arg.
// @fnv 0x007aafb0
// src: GUESS 0x007aafb0 (confidence: medium)
int __thiscall FUN_007aafb0_Class::GetCharacterPointerChecked(unsigned int arg)
{
    if (arg > unk14)
    {
        FUN_00ec7c56();
    }

    do
    {
    } while (0);

    return this->std_string__Myptr() + arg;
}

// Assignment is not yet declared by the shared StrMem header.
void __cdecl FUN_00438390();

namespace MessageCreation {
struct Text
{
    unsigned int allocator;
    char buffer[16];
    unsigned int length, capacity;
    Text(const char*);
    ~Text();
    unsigned int FindSubstring_Thunk(char, unsigned int);
    Text Substr(unsigned int, unsigned int);
    const char* std_string_debug_c_str();
    void ProcessState_007aaf80(unsigned int, unsigned int, const char*);
};
struct Message
{
    StrMem message;
    char* icon;
    StrMem title;
    StrMem buttons;
    bool hasButtons;
    StrMem hotkeys;
    int buttonCount, type;
    StrMem sound;
    bool pause;
    int tileID, callback;
    float displayTime, alpha;
    unsigned int flags;
    Message();
    bool GetByteAtOffset56();
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void* FormHeap_Allocate(unsigned int);
int BSstrlen(const char*);
void FUN_00406d30(char*, unsigned int, const char*);
int BSstrcmp(const char*, const char*);
extern const char DAT_01011584[], DAT_01020770[], DAT_01063d7c[];
extern const double DAT_01017b70, DAT_01012060, DAT_0101e568;
extern unsigned int DAT_010173f0;
struct Messages
{
    unsigned int FUN_0044ddc0();
    Message** FUN_00877a30(unsigned int);
    Message** FUN_006f2270();
    void FUN_006f23d0(unsigned int, Message* const&);
    void FUN_007cb2e0(Message* const&);
};
extern Messages DAT_011da53c;
extern int DAT_011da4f0;
extern bool DAT_011da4ec, DAT_011da4ef;
extern Setting DAT_011c3ea4;
bool Interface_InDialog();
void Interface_QueueMenuCreate(int, int, int, int, int, bool);
void MessageMenu_Create();
// Builds a Message from the given title, text, icon, sound and buttons, inserts it into the message queue, and triggers the display update.
// @fnv 0x007a8e60
bool QueueMessage(const char* title, const char* message, const char* icon, const char* sound, int buttonCount,
                  bool hasButtons, int type, const char* firstButton, const char*** arguments, bool pause, int tileID,
                  int callback, float time, float alpha, float flags)
{
    Message* info = new Message;
    StrMem buttonSlot11(firstButton);
    info->buttonCount = buttonCount;
    info->hasButtons = hasButtons;
    info->type = type;
    reinterpret_cast<void (__thiscall*)(StrMem*, const char*)>(FUN_00438390)(&info->message, message);
    reinterpret_cast<void (__thiscall*)(StrMem*, const char*)>(FUN_00438390)(&info->hotkeys, DAT_01011584);
    reinterpret_cast<void (__thiscall*)(StrMem*, const char*)>(FUN_00438390)(&info->title, title);
    reinterpret_cast<void (__thiscall*)(StrMem*, const char*)>(FUN_00438390)(&info->sound, sound);
    info->pause = pause;
    info->tileID = tileID;
    info->callback = callback;
    info->displayTime = time * DAT_01017b70;
    if (alpha > DAT_01012060)
        info->alpha = alpha * DAT_0101e568;
    info->flags = (unsigned int)flags;
    int iconLengthSlot11 = icon ? BSstrlen(icon) : 0;
    if (iconLengthSlot11 > 0)
    {
        info->icon = new char[iconLengthSlot11 + 1];
        FUN_00406d30(info->icon, iconLengthSlot11 + 1, icon);
    }
    else
        info->icon = 0;
    while (buttonSlot11.BSStringT_char_Length() > 0)
    {
        Text text(buttonSlot11.Modelloader_GetReferencedThis());
        unsigned int hotkeySlot0 = text.FindSubstring_Thunk('&', 0);
        if (hotkeySlot0 != DAT_010173f0)
        {
            info->hotkeys.FUN_00404820(text.Substr(hotkeySlot0 + 1, 1).std_string_debug_c_str());
            text.ProcessState_007aaf80(hotkeySlot0, 1, DAT_01011584);
        }
        if (BSstrcmp(text.std_string_debug_c_str(), DAT_01020770))
            info->buttons.FUN_00404820(text.std_string_debug_c_str());
        info->buttons.FUN_00404820(DAT_01063d7c);
        reinterpret_cast<void (__thiscall*)(StrMem*, const char*)>(FUN_00438390)(&buttonSlot11, (*arguments += 1)[-1]);
    }
    if (DAT_011da53c.FUN_0044ddc0())
    {
        for (unsigned int index = 0; index < DAT_011da53c.FUN_0044ddc0(); index++)
        {
            if (!(*DAT_011da53c.FUN_00877a30(index))->GetByteAtOffset56() && info->GetByteAtOffset56())
            {
                DAT_011da53c.FUN_006f23d0(index, info);
                break;
            }
            else if (*DAT_011da53c.FUN_00877a30(index) == *DAT_011da53c.FUN_006f2270())
            {
                DAT_011da53c.FUN_007cb2e0(info);
                break;
            }
        }
    }
    else
        DAT_011da53c.FUN_007cb2e0(info);
    if (!DAT_011da4f0 && !DAT_011da4ec && (!Interface_InDialog() || pause))
    {
        if (*DAT_011c3ea4.Setting_Int() > 1)
            Interface_QueueMenuCreate(7, 0, 0, 0, 1, !info->GetByteAtOffset56());
        else
            MessageMenu_Create();
    }
    else
        DAT_011da4ef = true;
    return true;
}
}

struct KeyBinding
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    StrMem text;
    int unk28;
    int type;
};
struct KeyString
{
    int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    KeyString(const char*);
    ~KeyString();
    unsigned int FUN_00825c00();
    char& GetCharacterPointerChecked(unsigned int);
};
extern "C" int __cdecl toupper(int);
struct KeyedList
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void* At(unsigned int, bool);
    unsigned int GetRaceCount();
    void* CallVirtualZero();
};
struct KeyMenu
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Select(int, void*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    KeyedList buttons;
    bool HandleKeyInput(int);
};
// @fnv 0x007aa110
bool KeyMenu::HandleKeyInput(int key)
{
    bool handled = false;
    if (GetCurrentArrayElement())
    {
        if (key == 1 && ((KeyBinding*)GetCurrentArrayElement())->type != 23)
        {
            Select(7, buttons.At(buttons.GetRaceCount() - 1, false));
            handled = true;
        }
        else if (key == 32)
        {
            Select(-1, buttons.CallVirtualZero());
            handled = true;
        }
        else if (((KeyBinding*)GetCurrentArrayElement())->text.BSStringT_char_Length() > 0)
        {
            KeyString text(((KeyBinding*)GetCurrentArrayElement())->text.Modelloader_GetReferencedThis());
            for (unsigned int index = 0; index < text.FUN_00825c00(); index++)
            {
                if (toupper(text.GetCharacterPointerChecked(index)) == toupper(key))
                {
                    Select(7, buttons.At(index, false));
                    handled = true;
                    break;
                }
            }
        }
    }
    return handled;
}

struct FUN_007aa2a0_shell : MessageMenu
{
    void UpdateMenuAction();
    int FUN_0059bb30();
    void FUN_00a1db20();
    void FUN_00a1d910();
    Tile* FUN_00726070();
};
struct TimerCalls
{
    void FUN_00771520();
    unsigned int FUN_00825c00();
};
void __cdecl CleanupGlobalObject();
extern double DAT_01012060;
// @fnv 0x007aa2a0
void FUN_007aa2a0_shell::UpdateMenuAction()
{
    reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00771520();
    static unsigned int lastCheckTime = reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00();
    if (reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00() - lastCheckTime < 200)
        return;
    {
        lastCheckTime = reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00();
        if (GetCurrentArrayElement())
        {
            if (static_cast<unsigned char>(GetByteAtOffset56(reinterpret_cast<char*>(GetCurrentArrayElement()))) == 0)
            {
                if (m_pTiles[0]->IsTraitNonZero(0xfa3))
                {
                    if (FUN_0059bb30() == 4)
                    {
                        if (m_uiMessageCount == 0)
                        {
                            FUN_00a1db20();
                        }
                        else
                        {
                            CleanupGlobalObject();
                            m_uiMessageCount = 0;
                        }
                    }
                    else
                    {
                        if (FUN_0059bb30() == 1)
                        {
                            unsigned int message = GetCurrentArrayElement();
                            if (!m_uiMessageCount)
                                m_uiMessageCount = reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00();
                            if (*reinterpret_cast<float*>(message + 0x44) > DAT_01012060)
                            {
                                if (*reinterpret_cast<float*>(message + 0x44) <=
                                    (unsigned int)(reinterpret_cast<TimerCalls*>(&m_kTimerCalls)->FUN_00825c00() -
                                                   m_uiMessageCount))
                                {
                                    if (message == *reinterpret_cast<FUN_006f2270*>(&g_011da53c)->GetLast())
                                    {
                                        FUN_00726070()->FUN_00700320(0x1772, 1);
                                        CleanupGlobalObject();
                                    }
                                    else
                                    {
                                        FUN_00a1d910();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

struct ActionMenuText
{
    char* data;
    unsigned unk04, unk08, unk0C, unk10, size, capacity;
    ActionMenuText(const char*);
    ~ActionMenuText();
    unsigned FindSubstring_Thunk(char, unsigned);
    ActionMenuText Substr(unsigned, unsigned);
    const char* std_string_debug_c_str();
    void ProcessState_007aaf80(unsigned, unsigned, const char*);
};
struct ActionMenuInfo
{
    StrMem message;
    int icon;
    StrMem title, buttons;
    bool hasButtons;
    StrMem hotkeys;
    void (*callback)();
    int type;
    StrMem sound;
    int pause, tile, callbackId;
    float displayTime, backgroundAlpha;
    int flags;
    ActionMenuInfo();
};
struct ActionMenuBase
{
    unsigned FUN_00401170();
};
struct ActionMenuOwner
{
    bool FUN_005021a0();
};
// These reference methods are not yet declared by the shared header.
void __cdecl TESObjectREFR_GetTargetType();
void __cdecl TESObjectREFR_GetLock();
void __cdecl TESObjectREFR_IsCrimeToActivate();
void __cdecl TESObjectREFR_IsAnOwner();

struct ActionMenuAction
{
    virtual void Slot0();
    virtual int GetKind();
    const char* FUN_00726070();
    int FUN_00413f40();
};
struct ActionMenuList
{
    bool FUN_008256d0();
    ActionMenuAction** FUN_006815c0();
    ActionMenuList* FUN_00726070();
};
struct ActionMenuEntry
{
    const char* label;
    int action;
    TESObjectREFR* reference;
};
template <class T> struct ActionMenuQueue
{
    void FUN_007cb2e0(T const&);
};
extern ActionMenuQueue<ActionMenuEntry*> DAT_011da524;
extern ActionMenuQueue<ActionMenuInfo*> DAT_011da53c;
extern int DAT_011da4f0;
extern bool DAT_011da4ec;
extern Setting DAT_011c3ea4;
extern Setting DAT_011d2280, DAT_011d3708, DAT_011d4f48, DAT_011d38dc, DAT_011d45a0, DAT_011d22b0,
    DAT_011d29f4;
extern Setting* DAT_011d5160[];
extern TESObjectREFR* DAT_011dea3c;
extern const char DAT_01011584[], DAT_01020770[], DAT_01063d7c[];
extern const unsigned DAT_010173f0;
void BSSimpleArray_UpdateState_007aae70();
void MessageMenu_Create();
void Interface_QueueMenuCreate(int, int, int, int, int, int);
void FUN_00406d30(char*, unsigned, const char*);
unsigned BSstrlen(const char*);
int BSstrcmp(const char*, const char*);
int FUN_0047b250(TESObjectREFR*);
bool FUN_00518f00(TESObjectREFR*, TESObjectREFR*, int, int);
// Builds an ActionMenuInfo with title, hotkeys and buttons from the list's actions and the reference's action type, queues entries and the menu, and opens it.
// @fnv 0x007aa720
bool BuildActionMenu(ActionMenuList* list, TESObjectREFR* reference)
{
    ActionMenuInfo* menu4 = new ActionMenuInfo;
    menu4->callback = BSSimpleArray_UpdateState_007aae70;
    menu4->hasButtons = false;
    menu4->type = 0;
    reinterpret_cast<void (__thiscall*)(StrMem*, const char*)>(FUN_00438390)(&menu4->message, 0);
    reinterpret_cast<void (__thiscall*)(StrMem*, const char*)>(FUN_00438390)(&menu4->hotkeys, DAT_01011584);
    reinterpret_cast<void (__thiscall*)(StrMem*, const char*)>(FUN_00438390)(&menu4->title, DAT_011d2280.FUN_00403df0());
    char label58[260];
    while (list && !list->FUN_008256d0())
    {
        FUN_00406d30(label58, 260, (*list->FUN_006815c0())->FUN_00726070());
        if ((*list->FUN_006815c0())->GetKind() == 4)
        {
            if (!(*list->FUN_006815c0())->FUN_00726070() || !(*list->FUN_006815c0())->FUN_00413f40())
            {
                list = list->FUN_00726070();
                continue;
            }
            ActionMenuEntry* entry29 = new ActionMenuEntry;
            entry29->label = (*list->FUN_006815c0())->FUN_00726070();
            entry29->action = (*list->FUN_006815c0())->FUN_00413f40();
            entry29->reference = reference;
            DAT_011da524.FUN_007cb2e0(entry29);
            if (BSstrlen(label58) > 0)
            {
                ActionMenuText text6(label58);
                unsigned hotkey5 = text6.FindSubstring_Thunk('&', 0);
                if (hotkey5 != DAT_010173f0)
                {
                    menu4->hotkeys.FUN_00404820(text6.Substr(hotkey5 + 1, 1).std_string_debug_c_str());
                    text6.ProcessState_007aaf80(hotkey5, 1, DAT_01011584);
                }
                if (BSstrcmp(text6.std_string_debug_c_str(), DAT_01020770))
                {
                    menu4->buttons.FUN_00404820(text6.std_string_debug_c_str());
                    menu4->buttons.FUN_00404820(DAT_01063d7c);
                }
            }
        }
        list = list->FUN_00726070();
    }
    int action3 = reinterpret_cast<int (__thiscall*)(TESObjectREFR*)>(TESObjectREFR_GetTargetType)(reference);
    unsigned type22 = reinterpret_cast<ActionMenuBase*>(reference->BGSSaveFormBuffer_GetForm())->FUN_00401170();
    ActionMenuOwner* owner15 = reinterpret_cast<ActionMenuOwner* (__thiscall*)(TESObjectREFR*)>(TESObjectREFR_GetLock)(reference);
    ActionMenuBase* base7 = reinterpret_cast<ActionMenuBase*>(reference->BGSSaveFormBuffer_GetForm());
    if (action3 == 1 && reinterpret_cast<bool (__thiscall*)(TESObjectREFR*)>(TESObjectREFR_IsCrimeToActivate)(reference))
    {
        FUN_00406d30(label58, 260, type22 == 42 ? DAT_011d3708.FUN_00403df0() : DAT_011d4f48.FUN_00403df0());
    }
    else if (action3 == 2 && (type22 == 42 || type22 == 43))
    {
        FUN_00406d30(label58, 260, DAT_011d38dc.FUN_00403df0());
    }
    else if (action3 == 8 && type22 == 28)
    {
        bool isChair = FUN_0047b250(reference) == 1 || FUN_0047b250(reference) == 2;
        if (owner15 && owner15->FUN_005021a0() && !reinterpret_cast<bool (__thiscall*)(TESObjectREFR*, TESObjectREFR*, bool)>(TESObjectREFR_IsAnOwner)(reference, DAT_011dea3c, true) &&
            (!base7 || !FUN_00518f00(reference, DAT_011dea3c, 0, 1)))
        {
            FUN_00406d30(label58, 260, DAT_011d45a0.FUN_00403df0());
        }
        else
        {
            FUN_00406d30(label58, 260, isChair ? DAT_011d22b0.FUN_00403df0() : DAT_011d5160[action3]->FUN_00403df0());
        }
    }
    else if (action3 && action3 < 20)
    {
        FUN_00406d30(label58, 260, DAT_011d5160[action3]->FUN_00403df0());
    }
    else if (action3 == 0)
    {
        FUN_00406d30(label58, 260, DAT_011d29f4.FUN_00403df0());
    }
    if (BSstrlen(label58) > 0)
    {
        ActionMenuText text6(label58);
        unsigned hotkey5 = text6.FindSubstring_Thunk('&', 0);
        if (hotkey5 != DAT_010173f0)
        {
            menu4->hotkeys.FUN_00404820(text6.Substr(hotkey5 + 1, 1).std_string_debug_c_str());
            text6.ProcessState_007aaf80(hotkey5, 1, DAT_01011584);
        }
        if (BSstrcmp(text6.std_string_debug_c_str(), DAT_01020770))
        {
            menu4->buttons.FUN_00404820(text6.std_string_debug_c_str());
            menu4->buttons.FUN_00404820(DAT_01063d7c);
        }
    }
    ActionMenuEntry* entry29 = new ActionMenuEntry;
    entry29->label = label58;
    entry29->action = 0;
    entry29->reference = reference;
    DAT_011da524.FUN_007cb2e0(entry29);
    DAT_011da53c.FUN_007cb2e0(menu4);
    if (!DAT_011da4f0 && !DAT_011da4ec)
    {
        if (*DAT_011c3ea4.Setting_Int() > 1)
            Interface_QueueMenuCreate(7, 0, 0, 0, 1, 0);
        else
            MessageMenu_Create();
    }
    return true;
}

namespace MessageMenuSetup {

struct MsgSize
{
    float x, y, z;
};

struct MsgFont
{
    MsgSize FUN_00a1b020(const char* apText, int aiFont, float afWidth, int aiFlags);
};

struct MsgSound
{
    unsigned int unk0, unk4, unk8;
    ~MsgSound();
    bool IsNotEqual(int aiFlags);
    void FUN_00ad8830(int aiFlags);
};

struct MsgAudio
{
    MsgSound BSAudio_GetSoundHandleByEditorName(const char* apEditorID, int aiFlags);
};


struct MsgString
{
    char acData[0x1c];
    MsgString(const char* apText);
    ~MsgString();
    unsigned int FUN_00825c00();
    unsigned int ProcessState_005103a0(const char* apDelimiter, unsigned int auiStart);
    MsgString Substr(unsigned int auiStart, unsigned int auiLength);
    const char* std_string_debug_c_str();
};

struct MsgData
{
    StrMem kTitle;
    const char* pIcon;
    StrMem kText;
    StrMem kButtons;
    char cButtonBase;
    char pad1d[0xf];
    int iType;
    StrMem kSound;
    char pad38[4];
    int iX;
    int iY;
    char pad44[4];
    float fAlpha;
    unsigned int uiWidth;
    bool GetByteAtOffset56();
};

struct MsgList
{
    virtual void l000();
    virtual void l001();
    virtual void l002();
    virtual void l003();
    virtual void l004();
    virtual void l005();
    virtual void l006();
    virtual void Clear();
    Tile* ListBox_int_AddItem(int aiIndex, const char* apText, int a3, int a4);
    void RebuildVisibleTiles();
};

struct MsgInterface
{
    bool InterfaceManager_IsMenuInStack(int aiMenuID);
};

struct MsgMenu
{
    virtual void m000();
    virtual void m001();
    virtual void m002();
    virtual void m003();
    virtual void m004();
    virtual void m005();
    virtual void m006();
    virtual void m007();
    virtual void m008();
    virtual void m009();
    virtual void m00a();
    virtual void m00b();
    virtual void m00c();
    virtual int GetID();
    char pad04[0x24];
    Tile* m_pTiles[6];
    MsgList kButtons;
    Tile* FUN_00726070();
    void PopulateFromMessageData();
};

extern MsgMenu* DAT_011da4f0;
extern bool DAT_0119f348;
extern const char DAT_01063d7c[];
extern const float DAT_01016970;
MsgData* GetCurrentArrayElement();
MsgAudio* BSAudio_QInstance();
MsgFont* FUN_005bd5b0();
MsgInterface* InterfaceManager_GetSingleton();
int __cdecl Tile_TextToTrait(const char* apTrait);
int __cdecl BSMAX_00647b70(int a, int b);
float __cdecl BSMIN(float a, float b);
float __cdecl BSMAX_00404010(float a, float b);
float __cdecl FUN_00715d40();
float __cdecl InterfaceManager_GetScreenHeight();
float __cdecl InterfaceManager_GetRealScreenWidth();
float __cdecl InterfaceManager_GetRealScreenHeight();
float __cdecl InterfaceManager_GetScreenSafeX();
float __cdecl InterfaceManager_GetScreenSafeY();
void __cdecl Interface_PopFromEnterStack(int aiMenuID, int aiFlag);
void __cdecl Interface_AddToEnterStack(int aiMenuID, int aiFlag);

static const char s_szHorBuf[] = "_horbuf";
static const char s_szPopUp[] = "UIPopUpMessageWindow";
static const char s_szListItemText[] = "ListItemText";
static const char s_szMaxMenuWidth[] = "_MaxMenuWidth";
static const char s_szMinMenuWidth[] = "_MinMenuWidth";

// Populates message menu tiles and buttons, computes layout dimensions, and sets menu position and alpha from the current message data.
// @fnv 0x007a92e0
void MsgMenu::PopulateFromMessageData()
{
    if (!GetCurrentArrayElement())
        return;
    MsgData* pMessagePtr = GetCurrentArrayElement();
    float fIconHeightIn = 0.0f;
    float fTheTextHeight = 0.0f;
    float fButtonsWidth = 0.0f;
    float fWidths = 0.0f;
    float fHorBuf = FUN_00726070()->FUN_00a011b0(Tile_TextToTrait(s_szHorBuf));
    if (pMessagePtr->kSound.BSStringT_char_Length() > 0 &&
        BSAudio_QInstance()->BSAudio_GetSoundHandleByEditorName(pMessagePtr->kSound.Modelloader_GetReferencedThis(), 0x121).IsNotEqual(-1))
        BSAudio_QInstance()->BSAudio_GetSoundHandleByEditorName(pMessagePtr->kSound.Modelloader_GetReferencedThis(), 0x121).FUN_00ad8830(0);
    else
        BSAudio_QInstance()->BSAudio_GetSoundHandleByEditorName(s_szPopUp, 0x121).FUN_00ad8830(0);
    DAT_011da4f0->m_pTiles[3]->Tile_Set_00a01350(0xfc4, pMessagePtr->kText.Modelloader_GetReferencedThis(), true);
    if (pMessagePtr->pIcon)
    {
        DAT_011da4f0->m_pTiles[1]->Tile_Set_00a01350(0xfc4, pMessagePtr->pIcon, true);
        DAT_011da4f0->m_pTiles[1]->FUN_00700320(0xfa3, 1);
        float fIconWidth =
            pMessagePtr->uiWidth > 0 ? (float)pMessagePtr->uiWidth : DAT_011da4f0->m_pTiles[1]->FUN_00a011b0(0xfba);
        fIconHeightIn =
            FUN_005bd5b0()->FUN_00a1b020(pMessagePtr->pIcon, 6, fIconWidth != 0.0 ? fIconWidth : DAT_01016970, 0).x;
        fIconHeightIn = fIconHeightIn + (pMessagePtr->uiWidth > 0 ? 0.0f : 100.0f);
    }
    else
    {
        DAT_011da4f0->m_pTiles[1]->FUN_00700320(0xfa3, 0);
    }
    Tile* pItemNew = 0;
    unsigned int uiPosNum = 0;
    int iMaxWidthCur = 0;
    float fListHeightTmp = 0.0f;
    int iIndex = 0;
    kButtons.Clear();
    if (pMessagePtr->kButtons.Modelloader_GetReferencedThis())
    {
        MsgString kButtonText(pMessagePtr->kButtons.Modelloader_GetReferencedThis());
        for (iIndex = 0; uiPosNum < kButtonText.FUN_00825c00() - 1; iIndex++)
        {
            MsgString kPart = kButtonText.Substr(uiPosNum, kButtonText.ProcessState_005103a0(DAT_01063d7c, uiPosNum) - uiPosNum);
            if (kPart.FUN_00825c00() > 0)
            {
                Tile* pText = 0;
                pItemNew = DAT_011da4f0->kButtons.ListBox_int_AddItem(
                    pMessagePtr->cButtonBase + iIndex,
                    kButtonText.Substr(uiPosNum, kButtonText.ProcessState_005103a0(DAT_01063d7c, uiPosNum) - uiPosNum)
                        .std_string_debug_c_str(),
                    0, 0);
                pText = pItemNew->GetNamedChild(s_szListItemText);
                pItemNew->FUN_00700320(0xfaa, 7);
                if (pText)
                {
                    float fItemWidth =
                        pMessagePtr->uiWidth > 0 ? (float)pMessagePtr->uiWidth : pText->FUN_00a011b0(0xfba);
                    fItemWidth = fItemWidth != 0.0 ? fItemWidth : DAT_01016970;
                    iMaxWidthCur =
                        BSMAX_00647b70(iMaxWidthCur,
                                     (int)FUN_005bd5b0()->FUN_00a1b020(pText->Tile_GetString(0xfc4), 2, fItemWidth, 0).x);
                }
                fListHeightTmp = pItemNew->FUN_00a011b0(0xfb0) + fListHeightTmp;
            }
            uiPosNum = kButtonText.ProcessState_005103a0(DAT_01063d7c, uiPosNum);
            if (uiPosNum < kButtonText.FUN_00825c00() - 1)
                uiPosNum = uiPosNum + 1;
        }
    }
    if (pMessagePtr->kTitle.BSStringT_char_Length() > 0)
    {
        DAT_011da4f0->m_pTiles[2]->Tile_Set_00a01350(0xfcc, pMessagePtr->kTitle.Modelloader_GetReferencedThis(), true);
        DAT_011da4f0->m_pTiles[2]->FUN_00700320(0xfa3, 1);
        if (pMessagePtr->uiWidth > 0)
            fTheTextHeight = BSMIN(fTheTextHeight + 120.0, (float)pMessagePtr->uiWidth);
        else
            fTheTextHeight = fTheTextHeight + 120.0;
    }
    else
    {
        DAT_011da4f0->m_pTiles[2]->FUN_00700320(0xfa3, 0);
    }
    if (pMessagePtr->uiWidth > 0)
        fButtonsWidth = BSMIN(iMaxWidthCur + 80.0, (float)pMessagePtr->uiWidth);
    else
        fButtonsWidth = iMaxWidthCur + 80.0;
    DAT_011da4f0->m_pTiles[4]->Tile_Set(0xfb0, fListHeightTmp, false);
    DAT_011da4f0->m_pTiles[4]->Tile_Set(0xfb1, fButtonsWidth, false);
    DAT_011da4f0->kButtons.RebuildVisibleTiles();
    if (pMessagePtr->uiWidth > 0)
        fButtonsWidth = BSMIN(fHorBuf * 2 + fButtonsWidth, (float)pMessagePtr->uiWidth);
    else
        fButtonsWidth = fHorBuf * 2 + fButtonsWidth;
    float fMaxWidthCur = DAT_01016970;
    if (pMessagePtr->uiWidth > 0)
        fMaxWidthCur = FUN_00715d40() * (pMessagePtr->uiWidth / InterfaceManager_GetRealScreenWidth());
    else
        fMaxWidthCur = DAT_011da4f0->FUN_00726070()->FUN_00a011b0(Tile_TextToTrait(s_szMaxMenuWidth));
    fMaxWidthCur = fMaxWidthCur - fHorBuf * 2;
    if (DAT_011da4f0->m_pTiles[2]->IsTraitNonZero(0xfa3))
        fMaxWidthCur = fMaxWidthCur - 120.0;
    DAT_011da4f0->m_pTiles[3]->Tile_Set(0xfba, fMaxWidthCur, true);
    MsgSize kSizeFinal = FUN_005bd5b0()->FUN_00a1b020(pMessagePtr->kText.Modelloader_GetReferencedThis(), 2,
                                                      DAT_011da4f0->m_pTiles[3]->FUN_00a011b0(0xfba), 0);
    fTheTextHeight = fHorBuf * 2 + kSizeFinal.x + fTheTextHeight;
    if (kSizeFinal.z > 1.0)
    {
        DAT_011da4f0->m_pTiles[1]->FUN_00700320(0xfb7, 1);
        DAT_011da4f0->m_pTiles[3]->FUN_00700320(0xfb7, 1);
    }
    else
    {
        DAT_011da4f0->m_pTiles[1]->FUN_00700320(0xfb7, 2);
        DAT_011da4f0->m_pTiles[3]->FUN_00700320(0xfb7, 2);
    }
    if (pMessagePtr->uiWidth == 0)
    {
        fWidths = BSMAX_00404010(fIconHeightIn, fTheTextHeight);
        fWidths = BSMAX_00404010(fWidths, fButtonsWidth);
        fWidths = BSMIN(fWidths, FUN_00726070()->FUN_00a011b0(Tile_TextToTrait(s_szMaxMenuWidth)));
        fWidths = BSMAX_00404010(fWidths, FUN_00726070()->FUN_00a011b0(Tile_TextToTrait(s_szMinMenuWidth)));
    }
    else
    {
        fWidths = FUN_00715d40() * (pMessagePtr->uiWidth / InterfaceManager_GetRealScreenWidth());
        fWidths = BSMIN(fWidths, FUN_00715d40() - InterfaceManager_GetScreenSafeX() * 2);
    }
    DAT_011da4f0->m_pTiles[0]->Tile_Set(0xfb1, fWidths, true);
    DAT_0119f348 = pMessagePtr->iType == 0x17;
    FUN_00726070()->FUN_00700320(0x1772, 0);
    FUN_00726070()->FUN_00700320(0xfa3, 1);
    if (!pMessagePtr->GetByteAtOffset56())
    {
        DAT_011da4f0->m_pTiles[0]->Tile_Set(0xfa9, 0.0f, true);
        if (InterfaceManager_GetSingleton()->InterfaceManager_IsMenuInStack(GetID()))
            Interface_PopFromEnterStack(GetID(), 1);
        float fScreenWidth = FUN_00715d40();
        float fMenuWidth = DAT_011da4f0->m_pTiles[0]->FUN_00a011b0(0xfb1);
        float fScreenHeight = InterfaceManager_GetScreenHeight();
        float fMenuHeightNew = DAT_011da4f0->m_pTiles[0]->FUN_00a011b0(0xfb0);
        float fXNew = (fScreenWidth - fMenuWidth) / 2.0;
        float fY = (fScreenHeight - fMenuHeightNew) / 2.0;
        if (pMessagePtr->iX > -1)
        {
            float fLeft = pMessagePtr->iX / InterfaceManager_GetRealScreenWidth() * fScreenWidth;
            fXNew = BSMAX_00404010(fLeft, InterfaceManager_GetScreenSafeX());
            fXNew = BSMIN(fXNew, fScreenWidth - fMenuWidth - InterfaceManager_GetScreenSafeX());
        }
        if (pMessagePtr->iY > -1)
        {
            float fTop = pMessagePtr->iY / InterfaceManager_GetRealScreenHeight() * fScreenHeight;
            fY = BSMAX_00404010(fTop, InterfaceManager_GetScreenSafeY());
            fY = BSMIN(fY, fScreenHeight - fMenuHeightNew - InterfaceManager_GetScreenSafeY());
        }
        DAT_011da4f0->m_pTiles[0]->Tile_Set(0xfa1, fXNew, true);
        DAT_011da4f0->m_pTiles[0]->Tile_Set(0xfa2, fY, true);
    }
    else
    {
        DAT_011da4f0->m_pTiles[0]->Tile_Set(0xfa9, 1.0f, true);
        if (!InterfaceManager_GetSingleton()->InterfaceManager_IsMenuInStack(GetID()))
            Interface_AddToEnterStack(GetID(), 0);
    }
    DAT_011da4f0->m_pTiles[5]->Tile_Set(0xfa9, pMessagePtr->fAlpha, true);
}

}

namespace fnv_007a8ba0 {
int __cdecl MessageMenu_GetMenuID_();
void* __cdecl Tile_GetMenuByClass(int);
int __cdecl Interface_GetTopMenuID();
unsigned int __cdecl GetCurrentArrayElement();
unsigned char __cdecl Interface_InDialog();
void __cdecl SetDialogMenuActive(int);
void __cdecl FUN_00709c40(int);
float __cdecl FUN_00a01530();
void __cdecl ProgramFlow(const char*);

struct VDel
{
    virtual ~VDel();
};
struct Helper
{
    void* CombatController_GetCombatState(const char* s);
    void FUN_00a1dc70(Tile* tile, int zero);
    void FUN_0075a0d0(void* arg1, const char* arg2);
    void PopulateFromMessageData();
    void FUN_00a1dc20(int);
    void* FUN_00726070();
};

extern int DAT_011da4f0;
extern Setting DAT_011d3bc8;
extern double DAT_010704f0;
extern double DAT_010704e8;
extern double DAT_0101e568;

// Initializes the message menu interface from Data\Menus\message_menu.xml, configures its buttons and background, and returns success.
// @fnv 0x007a8ba0
// src: XBOX_PDB 0x007a8ba0
bool __cdecl MessageMenu_Create()
{
    InterfaceManager* B = InterfaceManager_GetSingleton();
    unsigned char flag = 0;
    VDel* pVDel = (VDel*)Tile_GetMenuByClass(MessageMenu_GetMenuID_());
    if (pVDel != 0)
    {
        delete pVDel;
    }
    if (Interface_GetTopMenuID())
        flag = 1;
    Tile* pTile = ((Tile*)((Helper*)B)->CombatController_GetCombatState("Data\\Menus\\message_menu.xml"))->Tile_ReadFile();
    DAT_011da4f0 = (int)pTile->Tile_GetMenu();
    if (DAT_011da4f0 != 0 &&
        ((int(__thiscall*)(void*))((*(void***)DAT_011da4f0)[13]))((void*)DAT_011da4f0) == MessageMenu_GetMenuID_())
    {
        ((Helper*)DAT_011da4f0)->FUN_00a1dc70(pTile, 0);
        if (!((FUN_007abdb0_shell*)DAT_011da4f0)->QuantityMenu_IsWellFormedMenu())
        {
            ProgramFlow("Message Menu Creation Failed... Are your menu and art resources up to date?");
            return false;
        }
        if (pTile->FUN_00a011b0(0xfa7) == DAT_010704f0 ||
            pTile->FUN_00a011b0(0xfa7) == DAT_010704e8)
        {
            pTile->Tile_Set(0xfad, FUN_00a01530(), 1);
        }
        ((Helper*)((char*)DAT_011da4f0 + 0x40))
            ->FUN_0075a0d0(*(void**)((char*)DAT_011da4f0 + 0x38), "MM_ButtonTemplate");
        if (GetCurrentArrayElement() != 0)
        {
            ((Helper*)DAT_011da4f0)->PopulateFromMessageData();
        }
        if (flag)
        {
            ((Tile*)((Helper*)DAT_011da4f0)->FUN_00726070())->GetNamedChild("MM_Background")
                ->Tile_Set(0xfa9, *DAT_011d3bc8.Setting_Float_00403e20() * DAT_0101e568, 1);
        }
        if (Interface_InDialog())
        {
            SetDialogMenuActive(1);
        }
        ((Helper*)DAT_011da4f0)->FUN_00a1dc20(0);
        FUN_00709c40(0);
        return true;
    }
    else
    {
        if (DAT_011da4f0 != 0 && ((Helper*)DAT_011da4f0)->FUN_00726070() != 0)
        {
            delete (VDel*)DAT_011da4f0;
        }
    }
    return false;
}
}  // namespace fnv_007a8ba0
