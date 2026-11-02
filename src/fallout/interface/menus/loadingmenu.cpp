// fallout/interface/menus/loadingmenu.cpp: LoadingMenu, BSAudio, LoadingMenuStandIn, LoadingMenuX and more (71 functions)

#include "loadingmenu_packet.h"
class BSSystemUtility
{
  public:
    static int s_iUpdateEnabled;
    static BSSystemUtility* ms_pSystemUtility;
};

// @fnv 0x0078d2d0
void LoadingMenu::HideTile()
{
    if (BSSystemUtility::s_iUpdateEnabled)
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)
            ->SetTileVisible((LoadingMenu::TileIndex)0, false);
}

// Sets or clears the bit at index in usFlags according to set.
// @fnv 0x00458080
void LoadingMenu::SetFloatFlag(int index, bool set)
{
    if (set)
        usFlags |= (1 << index);
    else
        usFlags &= ~(1 << index);
}

// @fnv 0x0078cbd0
void LoadingMenu::SetTileVisible(LoadingMenu::TileIndex tileIndex, bool doSwap)
{
    for (int i = 0; i < 38; ++i)
    {
        m_pTiles[i]->Set(0xFA3, (float)(i == (int)tileIndex || (tileIndex == 0 && (i == 32 || i == 33))), false);
    }
    SetFloatFlag(6, doSwap);
}

class CountingSemaphore
{
  public:
    int iCount;
    void* hSemaphore;
    int m_iMaximumCount;
    CountingSemaphore();
    ~CountingSemaphore();
    void Wait();
    void Signal();
};

class LoadingMenuThread : public BSThread
{
  public:
    CountingSemaphore m_kFirstSemaphore;
    CountingSemaphore m_kSecondSemaphore;
    volatile bool m_bFirstThreadFlag;
    volatile bool m_bSecondThreadFlag;
    volatile bool m_bThirdThreadFlag;
    LoadingMenuThread();
    unsigned int ThreadProc();
};

// Initializes the loading menu thread: clears the three flags, sets its name, initializes the stack, and sets priority.
// @fnv 0x0078d2f0
LoadingMenuThread::LoadingMenuThread() : BSThread(), m_kFirstSemaphore(), m_kSecondSemaphore()
{
    m_bFirstThreadFlag = false;
    m_bSecondThreadFlag = false;
    m_bThirdThreadFlag = false;
    SetName("LoadingMenu");
    Initialize((BSThread::StackSize)0x4000, "LoadingMenu", false);
    SetSchedulingPriority(5);
    SetThreadPriority(-1);
}

// @fnv 0x0078cfc0
void LoadingMenu::UpdateLoadingScreenThread()
{
    if (BSSystemUtility::s_iUpdateEnabled && BSSystemUtility::ms_pSystemUtility &&
        reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->FUN_008905f0() &&
        !reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->m_bFirstThreadFlag)
    {
        reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->SetThreadPriority(1);
        reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->m_bFirstThreadFlag = true;
        reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->m_kSecondSemaphore.Wait();
    }
}

// @fnv 0x00717740
void LoadingMenu::SetLoadingScreenVisible(int visible)
{
    NiGeometry* object;
    RgbaColor* pColors = reinterpret_cast<NiGeometryData*>(FUN_004b7210())->GetColors();
    NiNode* node = pColors ? pColors->FUN_0056c7f0() : 0;
    object = 0;
    // object is deliberately initialized after obtaining the node.
    if (node)
    {
        object = reinterpret_cast<NiGeometry*>(node->FUN_0045bc00(0));
        if (object)
        {
            NiProperty* property = object->GetProperty(FUN_004af350());
            if (property)
                property->FUN_0068c9f0((float)visible);
        }
    }
}

// Computes a delay from one of three sources depending on state, converts it to milliseconds, and stores the next tip time as the current tick plus that delay.
// @fnv 0x0078abd0
void LoadingMenu::UpdateLoadingScreenTip()
{
    float delay = 0.0f;
    if (FUN_0070edf0())
        delay = g_011da190.FUN_00450410();
    else if (DAT_011a0294)
        delay = g_011da158.FUN_00450410();
    else
        delay = g_011da1a0.FUN_00450410();
    nextTipTime = gm_GetTickCount() + (unsigned int)(delay * 1000.0);
}

// @fnv 0x0078ab20
bool LoadingMenu::IsLoadScreenValid(TESLoadScreen* screen)
{
    bool valid = screen && screen->GetFormType() == FormLoadScreen;
    for (BSSimpleList<BGSPerkEntry*>* entry = &candidates; valid && entry && entry->GetItem(); entry = entry->GetNext())
    {
        valid = FUN_00408b20(screen->fullName.GetFullName(), entry->GetItem()->fullName.GetFullName()) != 0;
    }
    return valid;
}

// @fnv 0x0078aec0
void LoadingMenu::RefreshLoadingScreen()
{
    if (!g_BGSSaveLoadGame || !g_BGSSaveLoadGame->FUN_0042ce10())
        FUN_0078d670();
    m_pTiles[10]->Set(0x1004, DAT_011da16c, true);
    m_pTiles[10]->GetFloat(0x1005, DAT_011da170);
    m_pTiles[3]->Set(0xfc4,
                     g_011da168.objective ? g_011da168.objective->GetDisplayText()
                                          : reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d1f8c)->String(),
                     true);
    m_pTiles[14]->Set(0xfc4, reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d40f0)->String(), true);
    m_pTiles[15]->Set(0xfc4, reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d2358)->String(), true);
}

// @fnv 0x0078d490
unsigned int LoadingMenuThread::ThreadProc()
{
    unsigned int interval = gm_GetTickCount();
    unsigned int next = 50;
    while (m_bThirdThreadFlag != true)
    {
        if (gm_GetTickCount() < interval)
            FUN_0040fca0(interval - gm_GetTickCount());
        if (m_bFirstThreadFlag &&
            (!DAT_011a0294 || *reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011ded5c)->String() ||
             !reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->m_pTiles[0]->FUN_0078a1f0()))
        {
            m_kSecondSemaphore.Signal();
            m_bSecondThreadFlag = true;
            m_kFirstSemaphore.Wait();
            SetThreadPriority(-1);
            m_bSecondThreadFlag = false;
        }
        else
        {
            interval = gm_GetTickCount() + next;
        }
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->Update();
        LoadingMenu::UpdateLoadingMenuState();
    }
    return 0;
}

// Picks random load screens from array into candidates until the candidate count reaches the game-setting count, removing each picked entry.
// @fnv 0x0078adc0
void LoadingMenu::SelectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>& aLoadScreens)
{
    unsigned int count = reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da138)->Int()->u;
    if (GetFloat(5))
        count = reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da124)->Int()->u;
    else if (extraCandidates && !TESLoadScreenFlags::GetUseLocationSpecificScreensOnly())
        count = FUN_0042f5a0(count, reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da108)->Int()->u);
    unsigned int maximum = reinterpret_cast<BSSimpleList<BGSMusicType::MusicTrack*>*>(&candidates)->ItemsInList();
    while (maximum < count && reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&aLoadScreens)->GetSize())
    {
        unsigned int index =
            FUN_005a00a0(reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&aLoadScreens)->GetSize());
        if (IsLoadScreenValid(
                reinterpret_cast<TESLoadScreen*>(reinterpret_cast<NiFormArray*>(&aLoadScreens)->FUN_00877a30(index))))
        {
            reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&candidates)
                ->AddTail(reinterpret_cast<ScriptVariableInfo* const&>(
                    reinterpret_cast<NiFormArray*>(&aLoadScreens)->FUN_00877a30(index)));
            ++maximum;
        }
        aLoadScreens.UpdateEntryValue(index, 1);
    }
}

// Reads quest, objective, and load-screen data from the buffer, stores them in globals, and updates the loading menu UI.
// @fnv 0x0078d770
void LoadingMenu::LoadGame(BGSLoadGameBuffer* buffer)
{
    TESQuest* b = 0;     // saved quest
    unsigned int c = 0;  // saved objective ID
    b = dynamic_cast<TESQuest*>(TESForm::GetFormByID(buffer->ReadFormIdentifier()));
    buffer->ReadDataBlock(&c, 4);
    g_011da168.objective = b ? b->GetObjective(c) : 0;
    buffer->ReadDataBlock(&DAT_011da16c, 4);
    buffer->ReadDataBlock(&DAT_011da170, 4);
    if ((unsigned int)DAT_011da170 >= reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d0c60)->Int()->u)
        DAT_011da16c = 0.0f;
    bool a = false;  // location-specific screens only
    buffer->ReadDataBlock(&a, 1);
    TESLoadScreenFlags::SetUseLocationSpecificScreensOnly(a);
    if (BSSystemUtility::s_iUpdateEnabled)
    {
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->m_pTiles[11]->Set(0xfa3, 1);
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->SetFloatFlag(8, false);
    }
    FUN_004581c0(true);
}

// @fnv 0x0078ac60
void LoadingMenu::CollectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>& aLoadScreens)
{
    reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&aLoadScreens)->Clear(false);
    for (BSSimpleList<BGSPerkEntry*>* entry =
             reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(g_dataHandler->GetTESLoadScreenList());
         entry && entry->GetItem(); entry = entry->GetNext())
    {
        if ((GetFloat(5) && reinterpret_cast<TESLoadScreen*>(entry->GetItem())->IsRefFlag400Set()) ||
            (!GetFloat(5) &&
             ((extraCandidates && reinterpret_cast<TESLoadScreen*>(entry->GetItem())
                                      ->MatchesFormLocation(reinterpret_cast<TESForm*>(extraCandidates))) ||
              (!extraCandidates && reinterpret_cast<TESLoadScreen*>(entry->GetItem())->IsDefaultLoadScreen()))))
        {
            unsigned int index = reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&aLoadScreens)
                                     ->Add(reinterpret_cast<NavMeshInfo*&>(entry->GetItem()));
            int type = reinterpret_cast<TESLoadScreen*>(entry->GetItem())->GetLoadScreenTypeDataType();
            if ((DAT_011d8907 || (unsigned char)reinterpret_cast<DurationData*>(g_osGlobals)->FUN_00678ce0()) &&
                type != 3 && type != 0)
                aLoadScreens.UpdateEntryValue(index, 1);
        }
    }
}

// @fnv 0x0078afc0
void LoadingMenu::UpdateLoadScreen(TESLoadScreen* screen, float alpha, int mode)
{
    if (!GetFloat(6))
        return;
    if (!screen)
    {
        if (currentCandidate)
            screen = reinterpret_cast<TESLoadScreen*>(currentCandidate->GetItem());
        else
            screen = reinterpret_cast<TESLoadScreen*>(candidates.GetItem());
        if (!screen)
            return;
    }
    if (reinterpret_cast<BGSCameraPath*>(screen)->GetPrevPath())
    {
        Tile** tiles = 0;
        int type = screen->GetLoadScreenTypeDataType();
        switch (type)
        {
        case 4:
            tiles = reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0xd0);
            FUN_0078b100(alpha, mode);
            break;
        case 3:
            tiles = reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0xf4);
            FadeSlideTiles(alpha, mode);
            break;
        case 1:
            tiles = reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0xe8);
            UpdateLoadingTiles(alpha, mode);
            break;
        case 2:
            tiles = reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0xdc);
            UpdateTiles(alpha, mode);
            break;
        }
    }
}

// @fnv 0x004581c0
void __cdecl FUN_004581c0(bool abOn)
{
    if (BSSystemUtility::s_iUpdateEnabled)
    {
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->SetFloatFlag(3, abOn);
    }
}

struct SubObj
{
    void RemoveAll();
    void FUN_004ed8c0(int*);
};
struct LM2
{
    char pad[0x6c];
    int a;
    int b;
    char pad2[0xd0 - 0x74];
    SubObj s;
    void FUN_00788f30();
};
// Calls s.RemoveAll, then passes &a and &b to s.FUN_004ed8c0 in turn.
// @fnv 0x00788f30
void LM2::FUN_00788f30()
{
    s.RemoveAll();
    s.FUN_004ed8c0(&a);
    s.FUN_004ed8c0(&b);
}

struct FUN_Sub
{
    void RemoveAll();
    void FUN_004ed8c0(void* p);
};
// Calls RemoveAll on the FUN_Sub at self+0xdc, then FUN_004ed8c0 with self+0x94, self+0x34 and self+0x60.
// @fnv 0x00788f80
void __fastcall FUN_00788f80(char* self)
{
    ((FUN_Sub*)(self + 0xdc))->RemoveAll();
    ((FUN_Sub*)(self + 0xdc))->FUN_004ed8c0(self + 0x94);
    ((FUN_Sub*)(self + 0xdc))->FUN_004ed8c0(self + 0x34);
    ((FUN_Sub*)(self + 0xdc))->FUN_004ed8c0(self + 0x60);
}

struct M788
{
    void RemoveAll();
    void FUN_004ed8c0(void*);
};
struct S788
{
    char pad[0xe8];
    M788 m;
    void FUN_00788fe0();
};
// Calls m.RemoveAll, then passes six member addresses (offsets 0x68, 0x98, 0x9c, 0x64, 0x50, 0xa0) to m.FUN_004ed8c0.
// @fnv 0x00788fe0
void S788::FUN_00788fe0()
{
    m.RemoveAll();
    m.FUN_004ed8c0((char*)this + 0x68);
    m.FUN_004ed8c0((char*)this + 0x98);
    m.FUN_004ed8c0((char*)this + 0x9c);
    m.FUN_004ed8c0((char*)this + 0x64);
    m.FUN_004ed8c0((char*)this + 0x50);
    m.FUN_004ed8c0((char*)this + 0xa0);
}

namespace fnv_00789080 {
struct SubObj
{
    void RemoveAll();
    void FUN_004ed8c0(int*);
};
struct LM3
{
    char pad[0xb0];
    int a;
    int b;
    char pad2[0xf4 - 0xb8];
    SubObj s1;
    char pad3[0x100 - 0xf5];
    SubObj s2;
    void FUN_00789080();
};
// Calls RemoveAll then FUN_004ed8c0 on s1 with &a and on s2 with &b.
// @fnv 0x00789080
void LM3::FUN_00789080()
{
    s1.RemoveAll();
    s1.FUN_004ed8c0(&a);
    s2.RemoveAll();
    s2.FUN_004ed8c0(&b);
}
}  // namespace fnv_00789080

struct FUN_0078a1c0_shell
{
    char pad[0x222];
    unsigned short usFlags;
    void ToggleFlagBit(int aBit);
};

// Toggles the bit at position aBit in usFlags using XOR with 1 << aBit.
// @fnv 0x0078a1c0
void FUN_0078a1c0_shell::ToggleFlagBit(int aBit)
{
    usFlags ^= 1 << aBit;
}

struct NiControllerSequence
{
    int GetState();
};

struct FUN_0078a1f0_this
{
    char pad[0x3c];
    NiControllerSequence* pSequence;
};

// Returns true if pSequence is set and its GetState() equals 1.
// @fnv 0x0078a1f0
bool __fastcall FUN_0078a1f0(FUN_0078a1f0_this* pThis)
{
    return pThis->pSequence && pThis->pSequence->GetState() == 1;
}

struct FUN_0078a230_shell : public LoadingMenu
{
    void FUN_0078a230();
};

struct Dummy_00a20ed0
{
    void UpdateAnimation(float a1, int a2);
};

// Calls UpdateAnimation on the object at offset 0x54 with -1.0f and 0.
// @fnv 0x0078a230
void FUN_0078a230_shell::FUN_0078a230()
{
    (*reinterpret_cast<Dummy_00a20ed0**>(reinterpret_cast<char*>(this) + 0x54))->UpdateAnimation(-1.0f, 0);
}

extern SettingT_GameSettingCollection_** _DAT_011c6d50[];

// @fnv 0x0078a260
const char* __cdecl GetGameSettingString(int index)
{
    return (*_DAT_011c6d50[index])->String();
}

// Returns the value pointed to by p, then increments that value by one.
// @fnv 0x0078a910
int __cdecl PostIncrementInt(int* piValue)
{
    int old = *piValue;
    *piValue = *piValue + 1;
    return old;
}

class TESForm_Ex
{
  public:
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual ~TESForm_Ex();
};

TESForm_Ex** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
bool __fastcall FUN_004077c0(const void*);
void __fastcall FUN_00470470(void*);

// @fnv 0x0078a940
void __fastcall FUN_0078a940(char* this_ptr)
{
    for (void* pIter = this_ptr + 0x1d0; pIter && *_ref_006815c0(pIter); pIter = _ref_00726070(pIter))
    {
        if (FUN_004077c0(*_ref_006815c0(pIter)))
        {
            delete *_ref_006815c0(pIter);
        }
    }
    FUN_00470470(this_ptr + 0x1d0);
    *reinterpret_cast<void**>(this_ptr + 0x1d8) = this_ptr + 0x1d0;
}

struct FUN_0078ada0_shell : public TESLoadScreen
{
    bool IsRefFlag400Set();
};

class TESObjectREFR
{
  public:
    unsigned int GetFlags();
};

// @fnv 0x0078ada0
bool FUN_0078ada0_shell::IsRefFlag400Set()
{
    return (((TESObjectREFR*)this)->GetFlags() & 0x400) != 0;
}

struct FUN_0078afa0_shell : public LoadingMenu
{
    void FUN_0078afa0(bool);
};

// @fnv 0x0078afa0
void FUN_0078afa0_shell::FUN_0078afa0(bool abShow)
{
    SetFloatFlag(6, abShow);
}

struct StrH
{
    operator const char*() const;
};
struct ListH
{
    Tile*& GetNext(void*& pos);
};
struct LM0078b650
{
    char pad[0xd0];
    char lst;
    void FUN_0078b650(bool b);
};
// Iterates the tile list from lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b650
void LM0078b650::FUN_0078b650(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<StrH*>(&lst);
    while (pos)
    {
        reinterpret_cast<ListH*>(&lst)->GetNext(pos)->Set(0xfa3, b);
    }
}

namespace fnv_0078b6a0 {
struct StrH
{
    operator const char*() const;
};
struct ListH
{
    Tile*& GetNext(void*& pos);
};
struct LM0078b6a0
{
    char pad[0xdc];
    char lst;
    void FUN_0078b6a0(bool b);
};
// Iterates the tile list starting at lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b6a0
void LM0078b6a0::FUN_0078b6a0(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<StrH*>(&lst);
    while (pos)
    {
        reinterpret_cast<ListH*>(&lst)->GetNext(pos)->Set(0xfa3, b);
    }
}
}  // namespace fnv_0078b6a0

struct TL
{
    void* GetHead() const;
    Tile*& GetNext(void*&);
};
struct S78b
{
    char p0[0xb8];
    Tile* t1;
    Tile* t2;
    char p1[0xf4 - 0xc0];
    TL l1;
    char p2[0x100 - 0xf5];
    TL l2;
    void FUN_0078b6f0(bool b);
};
// Sets property 0xfa3 to b on every tile in both lists l1 and l2 and on t1 and t2.
// @fnv 0x0078b6f0
void S78b::FUN_0078b6f0(bool b)
{
    void* pos = l1.GetHead();
    while (pos)
    {
        Tile* pTile = l1.GetNext(pos);
        if (pTile)
            pTile->Set(0xfa3, b);
    }
    pos = l2.GetHead();
    while (pos)
    {
        Tile* pTile = l2.GetNext(pos);
        if (pTile)
            pTile->Set(0xfa3, b);
    }
    t1->Set(0xfa3, b);
    t2->Set(0xfa3, b);
}

namespace fnv_0078b7c0 {
struct StrH
{
    operator const char*() const;
};
struct ListH
{
    Tile*& GetNext(void*& pos);
};
struct LM0078b7c0
{
    char pad[0xe8];
    char lst;
    void FUN_0078b7c0(bool b);
};
// Iterates the tile list starting at lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b7c0
void LM0078b7c0::FUN_0078b7c0(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<StrH*>(&lst);
    while (pos)
    {
        reinterpret_cast<ListH*>(&lst)->GetNext(pos)->Set(0xfa3, b);
    }
}
}  // namespace fnv_0078b7c0

struct LoadScreenTypeData
{
    void Endian();
    int DataType;
    char m_acFirstString[40];
    char m_acSecondString[40];
    unsigned int m_uiTrailingValue;
};
typedef char _sizecheck_LoadScreenType_Data[sizeof(LoadScreenTypeData) == 88 ? 1 : -1];
struct FUN_0078b9b0_shell : public LoadingMenu
{
    void FUN_0078b9b0(void*);
};

class BGSLoadGameBuffer;

class Interface
{
  public:
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};

class InterfaceManager
{
  public:
    static float __cdecl UpdateInterfaceState(void);
};

float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00715da0(void);
float __cdecl FUN_007177c0(void);
float __cdecl FUN_00717820(void);

extern const double DAT_0106e7f8;

// @fnv 0x0078b9b0
void FUN_0078b9b0_shell::FUN_0078b9b0(void* apData)
{
    if (apData == 0)
    {
        Interface::PrintDebugMessage(
            (BGSLoadGameBuffer*)"WARNING: LoadingMenu::CalcLoadScreenTypeTextWindowVerts() received a NULL apData.");
        return;
    }

    float fSafeWidth;
    float fConvertedYPos;
    float fSafeHeight;
    float fConvertedHeight;
    float fCurrentScreenWidth = InterfaceManager::UpdateInterfaceState();
    float fCurrentScreenHeight = FUN_00715da0();
    fSafeWidth = fCurrentScreenWidth - FUN_007177c0();
    fSafeHeight = fCurrentScreenHeight - FUN_00717820();

    float fConvertedWidth;
    float fConvertedXPos = (double)((unsigned int*)apData)[1] / 1280.0 * fCurrentScreenWidth;
    fConvertedYPos = (double)((unsigned int*)apData)[2] / DAT_0106e7f8 * fCurrentScreenHeight;
    fConvertedWidth = (double)((unsigned int*)apData)[3] / 1280.0 * fCurrentScreenWidth;
    fConvertedHeight = (double)((unsigned int*)apData)[4] / 1280.0 * fCurrentScreenHeight;

    if (((unsigned int*)apData)[0] != 0)
    {
        *(int*)((char*)this + 0xc0) = (int)FUN_00404010(fConvertedXPos, FUN_007177c0());
        *(int*)((char*)this + 0xc4) = (int)FUN_00404010(fConvertedYPos, FUN_00717820());
        *(int*)((char*)this + 0xc8) =
            (int)FUN_0040ebd0((float)*(int*)((char*)this + 0xc0) + fConvertedWidth, fSafeWidth);
        *(int*)((char*)this + 0xcc) =
            (int)FUN_0040ebd0((float)*(int*)((char*)this + 0xc4) + fConvertedHeight, fSafeHeight);
    }
}

struct LMStandIn
{
    char pad[0x1dc];
    int v;
    void FUN_0078bb60(int);
    void FUN_0078bb40();
};
// @fnv 0x0078bb40
void LMStandIn::FUN_0078bb40()
{
    FUN_0078bb60(v);
}

// @fnv 0x0078bc60
int __fastcall FUN_0078bc60(int apObject)
{
    return *(int*)(apObject + 0x34) + 0x18;
}

struct RecursiveLock
{
    void Enter(char*);
    void Leave();
    void Lock(char*);
    void Unlock();
    bool TryLock();
    void Wait();
    static void OutputTrackingInfo();
    unsigned int QOwningThreadID();
    unsigned int QCurrentLockCount();
    void InitWithSpinCount(unsigned long);
    void* __vecDelDtor(unsigned int);
    char CriticalSection[28];
    unsigned long m_uiFirstValue;
    unsigned long m_uiSecondValue;
    int m_uiRecursionCount;
};
typedef char _sizecheck_BSCriticalSection[sizeof(RecursiveLock) == 40 ? 1 : -1];

class NiRenderer
{
  public:
    void StartScene();
    void FinishScene();
};

class TaskThreadManager
{
  public:
    static TaskThreadManager* __cdecl GetSingleton();
};

NiRenderer* __cdecl FUN_0043c4b0(void);
RecursiveLock* __cdecl FUN_00713d70(void);
bool __fastcall FUN_0044b130(RecursiveLock*);
int __fastcall FUN_0078d1d0(RecursiveLock*);
bool __cdecl BSSpinLockGlobalTryLock(void);
void __cdecl FUN_00452530(void);

struct MTRenderingSystem_Helper
{
    void FUN_00ba2f30();
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
    void FUN_00ba2fa0();
};

struct InterfaceManager_Helper
{
    void RenderMenu(int, int);
};

struct Tile_Helper : public Tile
{
    static void __cdecl UpdateAll(bool);
};

extern RecursiveLock DAT_011f4380;
extern bool DAT_011a0295;
extern bool DAT_011c70f8;

// @fnv 0x0078d080
void __cdecl FUN_0078d080(void)
{
    FUN_0043c4b0()->StartScene();
    RecursiveLock* pTileCritSect = FUN_00713d70();
    if (!FUN_0044b130(pTileCritSect))
    {
        FUN_0043c4b0()->FinishScene();
        return;
    }

    if (!FUN_0078d1d0(&DAT_011f4380))
    {
        pTileCritSect->Leave();
        FUN_0043c4b0()->FinishScene();
        return;
    }

    if (DAT_011a0295 && !BSSpinLockGlobalTryLock())
    {
        DAT_011f4380.Leave();
        pTileCritSect->Leave();
        FUN_0043c4b0()->FinishScene();
        return;
    }

    if (DAT_011a0295)
    {
        Tile_Helper::UpdateAll(true);
        FUN_00452530();
    }

    reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->FUN_00ba2f30();
    for (int i = 1; i < 23; ++i)
    {
        reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->FUN_00ba30f0(0, i);
        reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->FUN_00ba3130(1, i);
    }

    DAT_011c70f8 = true;
    reinterpret_cast<InterfaceManager_Helper*>(FUN_004b7210())->RenderMenu(0, 0);
    DAT_011c70f8 = false;

    reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->FUN_00ba2fa0();
    FUN_0043c4b0()->FinishScene();
    pTileCritSect->Leave();
    DAT_011f4380.Leave();
}

extern void*(__stdcall* DAT_00fdf0b4)(void*, long, long, const char*);

// @fnv 0x0078d3b0
CountingSemaphore* __fastcall InitSemaphore(CountingSemaphore* pThis)
{
    pThis->iCount = 0;
    pThis->m_iMaximumCount = 1;
    pThis->hSemaphore = DAT_00fdf0b4(0, 0, 1, 0);
    return pThis;
}

struct PlayerCharacter
{
    int FindAudioEntry();
    unsigned short GetLevel();
};
extern PlayerCharacter* pPlayer;
float __cdecl GetLevelProgress();
// Stores the player's FindAudioEntry result, GetLevelProgress result and level into g_011da168, DAT_011da16c and DAT_011da170.
// @fnv 0x0078d670
void FUN_0078d670()
{
    *(int*)&g_011da168 = pPlayer->FindAudioEntry();
    DAT_011da16c = GetLevelProgress();
    DAT_011da170 = pPlayer->GetLevel();
}

namespace fnv_0078d880 {
extern int DAT_0107410c;
class NavMeshInfo;
template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    void FUN_006b3eb0(unsigned int, bool);
};

// @fnv 0x0078d880
void* __fastcall FUN_0078d880(void* pThis)
{
    *reinterpret_cast<int**>(pThis) = &DAT_0107410c;
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(pThis)->FUN_006b3eb0(0, false);
    return pThis;
}
}  // namespace fnv_0078d880

extern int DAT_0107410c;

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

// @fnv 0x0078d8b0
void __fastcall FUN_0078d8b0(GlobalObject_00869f00* pThis)
{
    *(int**)pThis = &DAT_0107410c;
    pThis->Clear(true);
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor, then frees this object if the flags bit 0 is set, and returns this.
// @fnv 0x00788770
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_007890e0 {
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_007890e0_shell : public LoadingMenu
{
    void InitLoadingMenu(TESForm*);
};

class NiProperty;
class TESObjectREFR;

class NiFixedString
{
  public:
    NiFixedString(const char*);
    ~NiFixedString();
    const char* m_kHandle;
};

struct NiUpdateDataH
{
    void FUN_0043d410(float, bool, bool);
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
};

class NiNodeV;

class NiAVObjectV
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual NiNodeV* IsSceneNode();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual NiAVObjectV* GetObjectByName(const NiFixedString&);
    NiProperty* GetProperty(unsigned int);
    void FUN_00440490(float);
    void SetLocalRotation(float, float, float, float);
    void SetAppCulled(bool);
};

class NiNodeV : public NiAVObjectV
{
  public:
    NiAVObjectV* FUN_0045bc00(unsigned int);
    void Update(NiUpdateDataH&);
};

class NiRendererV
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void SetBackgroundColor(int*);
};

struct Tile3D
{
    NiNodeV* FUN_0056c7f0();
    void FUN_00a20cc0(const char*);
};

struct Tile_
{
    virtual ~Tile_();
};
Tile_* __cdecl FindMenuById(int);

struct TileEx
{
    float GetFloat(int);
};
struct TileH
{
    static float GetInterfaceScale();
};
struct FUN_00424940_shell
{
    char FUN_00424940();
};
struct FUN_0041fd00_shell
{
    void FUN_0041fd00(int);
};
struct HUDMainMenu
{
    static void UpdateVisibilityState(int);
    static bool UpdateTargetReference(TESObjectREFR*, bool, bool);
};
struct InterfaceH
{
    static void SetLookAtReference(TESObjectREFR*);
    static double GetFourthInterfaceFloat();
    static double GetThirdInterfaceFloat();
};
struct BGSMoviePlayer
{
    bool FUN_00ec17c0();
    void FUN_00ec25e0();
};
struct TESGlobalValueReader
{
    float GetValue();
};
struct OSGlobalsH
{
    bool FUN_00678ce0();
};
struct TESObjectCELL
{
    bool IsInterior();
};
struct FUN_00575d10_shell
{
    bool FUN_00575d10();
};
struct Setting_S
{
    float* Float();
};
struct FUN_0078a5a0_shell
{
    void UpdateLoadingScreens();
};
struct FUN_0078a280_shell
{
    void UpdateLoadingScreenText(bool);
};
struct FUN_0078a9f0_shell
{
    void FUN_0078a9f0();
};
struct FUN_0078a3e0_shell
{
    void ApplyLoadingScreenTexture(bool);
};
struct FUN_0078cc50_shell
{
    void FUN_0078cc50();
};
struct BSAudio
{
    static BSAudio* GetSingleton();
    bool IsPatrolling();
    bool FUN_005bb4d0();
    void SetUseMultipleThreads(bool);
    void SetAudioProperty(unsigned int, unsigned int, unsigned int);
};

extern const double DAT_010704f0;
extern const double DAT_010704e8;
extern const double gModifierZero;
extern const float DAT_01073f20;
extern int DAT_011a9bd0;
extern bool DAT_011a0295;
extern TESGlobalValueReader* DAT_011c3f3c;
extern BGSMoviePlayer* DAT_0126fac4;
extern GlobalObject_0044f440 originalRuntimeFloatSetting1218;
struct PC7d;
extern PC7d* g_thePlayer;

struct LoadingMenuH
{
    void SetTileVisible(int, bool);
    void SetFloatFlag(int, bool);
    bool GetFloat(int);
    void RefreshLoadingScreen();
    void UpdateLoadingScreenTip();
    static void UpdateLoadingMenuState();
};
struct FUN_0078afa0_shell
{
    void FUN_0078afa0(bool);
};
struct FUN_0078a230_shell
{
    void FUN_0078a230();
};
struct NiRendererH
{
    void StartScene();
    void FinishScene();
};
NiRendererV* __cdecl FUN_0043c4b0();

unsigned int __cdecl FUN_00438220();
void __cdecl _FNV_Warning(int, const char*, ...);

// @fnv 0x007890e0
void FUN_007890e0_shell::InitLoadingMenu(TESForm* apLocation)
{
    Tile_* psleep;

    *(unsigned int*)((char*)this + 0x1e0) = 0;
    if (((TileEx*)*(Tile**)((char*)this + 4))->GetFloat(0xfa7) == DAT_010704f0 ||
        ((TileEx*)*(Tile**)((char*)this + 4))->GetFloat(0xfa7) == DAT_010704e8)
    {
        (*(Tile**)((char*)this + 4))->Set(0xfad, TileH::GetInterfaceScale(), true);
    }

    if (((FUN_00424940_shell*)FUN_004b7210())->FUN_00424940() != 3)
        ((FUN_0041fd00_shell*)FUN_004b7210())->FUN_0041fd00(2);

    HUDMainMenu::UpdateVisibilityState(5);
    HUDMainMenu::UpdateTargetReference(0, false, false);
    InterfaceH::SetLookAtReference(0);

    if (g_thePlayer && !DAT_0126fac4->FUN_00ec17c0())
        DAT_0126fac4->FUN_00ec25e0();

    psleep = FindMenuById(0x3f4);
    if (psleep)
        delete psleep;

    *(TESForm**)((char*)this + 0x1e8) = apLocation;

    if (DAT_011a0294 || DAT_011c3f3c->GetValue() != gModifierZero)
    {
        ((LoadingMenuH*)this)->SetTileVisible(0, false);
    }
    else if (DAT_011d8907 || ((OSGlobalsH*)g_osGlobals)->FUN_00678ce0())
    {
        ((FUN_0078afa0_shell*)this)->FUN_0078afa0(false);
        ((NiRendererH*)FUN_0043c4b0())->StartScene();
        ((FUN_0078a230_shell*)this)->FUN_0078a230();
        ((NiRendererH*)FUN_0043c4b0())->FinishScene();
    }
    else
    {
        if (*(TESForm**)((char*)this + 0x1e8) && !g_BGSSaveLoadGame->FUN_0042ce10())
        {
            switch ((*(TESForm**)((char*)this + 0x1e8))->GetFormType())
            {
            case 0x39:
                ((LoadingMenuH*)this)
                    ->SetFloatFlag(9, ((TESObjectCELL*)*(TESForm**)((char*)this + 0x1e8))->IsInterior());
                break;
            case 0x3a:
            case 0x3b:
            case 0x3c:
            case 0x3d:
            case 0x3e:
            case 0x3f:
            case 0x40:
            case 0x69:
                ((LoadingMenuH*)this)
                    ->SetFloatFlag(9, ((FUN_00575d10_shell*)*(TESForm**)((char*)this + 0x1e8))->FUN_00575d10());
                break;
            }
        }
        if (((LoadingMenuH*)this)->GetFloat(9))
        {
            ((LoadingMenuH*)this)->SetTileVisible(0xb, false);
            ((LoadingMenuH*)this)->SetFloatFlag(4, false);
            *(unsigned int*)((char*)this + 0x1e4) = gm_GetTickCount();
            DAT_011a0295 = true;
        }
        else
        {
            ((FUN_0078afa0_shell*)this)->FUN_0078afa0(true);
            ((LoadingMenuH*)this)->RefreshLoadingScreen();
        }
        ((NiRendererH*)FUN_0043c4b0())->StartScene();
        ((FUN_0078a230_shell*)this)->FUN_0078a230();
        ((NiRendererH*)FUN_0043c4b0())->FinishScene();
    }

    FUN_0043c4b0()->SetBackgroundColor(&DAT_011a9bd0);

    if (((Tile3D*)(*(Tile**)((char*)this + 0x54)))->FUN_0056c7f0())
    {
        ((Tile3D*)(*(Tile**)((char*)this + 0x54)))
            ->FUN_0056c7f0()
            ->FUN_00440490(originalRuntimeFloatSetting1218.FUN_00450410());
        (*(Tile**)((char*)this + 0x54))->Set(0x1004, *((Setting_S*)&originalRuntimeFloatSetting1218)->Float(), true);
        ((Tile3D*)(*(Tile**)((char*)this + 0x54)))->FUN_0056c7f0()->SetLocalRotation(1.5707964f, 1.0f, 0.0f, 0.0f);
    }
    else
    {
        _FNV_Warning(0x12, "WARNING:  Loading Menu wheel does not have a model.");
    }

    if (!((LoadingMenuH*)this)->GetFloat(9))
    {
        NiUpdateDataH data;
        NiAVObjectV* pav;
        NiNodeV* pnode;
        Tile3D* p3dtile;

        pav = ((Tile3D*)(*(Tile**)((char*)this + 0x28)))->FUN_0056c7f0()->GetObjectByName(NiFixedString("Slide01"));
        pnode = pav->IsSceneNode();
        if (pnode)
        {
            *(NiProperty**)((char*)this + 0x1ec) = pnode->FUN_0045bc00(0)->GetProperty(FUN_00438220());
            pnode = (NiNodeV*)((Tile3D*)(*(Tile**)((char*)this + 0x28)))
                        ->FUN_0056c7f0()
                        ->GetObjectByName(NiFixedString("Slide02"));
            *(NiProperty**)((char*)this + 0x1f0) = pnode->FUN_0045bc00(0)->GetProperty(FUN_00438220());
        }
        else
        {
            *(NiProperty**)((char*)this + 0x1ec) = pav->GetProperty(FUN_00438220());
            pav = ((Tile3D*)(*(Tile**)((char*)this + 0x28)))->FUN_0056c7f0()->GetObjectByName(NiFixedString("Slide02"));
            *(NiProperty**)((char*)this + 0x1f0) = pav->GetProperty(FUN_00438220());
        }

        ((FUN_0078a5a0_shell*)this)->UpdateLoadingScreens();
        if (!DAT_011a0294)
        {
            ((FUN_0078a280_shell*)this)->UpdateLoadingScreenText(false);
            ((FUN_0078a9f0_shell*)this)->FUN_0078a9f0();
            ((FUN_0078a3e0_shell*)this)->ApplyLoadingScreenTexture(false);
            ((LoadingMenuH*)this)->UpdateLoadingScreenTip();
        }

        ((Tile3D*)(*(Tile**)((char*)this + 0x28)))->FUN_0056c7f0()->FUN_00440490(DAT_01073f20);
        ((Tile3D*)(*(Tile**)((char*)this + 0x28)))->FUN_0056c7f0()->SetLocalRotation(1.5707964f, 1.0f, 0.0f, 0.0f);
        (*(Tile**)((char*)this + 0x28))
            ->Set(0x1004, InterfaceH::GetFourthInterfaceFloat() / InterfaceH::GetThirdInterfaceFloat(), true);

        p3dtile = (Tile3D*)(*(Tile**)((char*)this + 0x28));
        p3dtile->FUN_00a20cc0("Left");
        data.FUN_0043d410(0.0f, true, false);
        p3dtile->FUN_0056c7f0()->Update(data);
        ((FUN_0078cc50_shell*)this)->FUN_0078cc50();
        *(unsigned int*)((char*)this + 0x1e4) = 0;
    }

    LoadingMenuH::UpdateLoadingMenuState();

    if ((DAT_011a0294 || !apLocation) && BSAudio::GetSingleton()->IsPatrolling() &&
        !*((SettingT_GameSettingCollection_*)&g_011ded5c)->String())
    {
        if (!BSAudio::GetSingleton()->FUN_005bb4d0())
        {
            BSAudio::GetSingleton()->SetUseMultipleThreads(true);
            ((LoadingMenuH*)this)->SetFloatFlag(2, true);
        }
    }
    else if (!DAT_011a0294 && BSAudio::GetSingleton()->IsPatrolling())
    {
        if (!BSAudio::GetSingleton()->FUN_005bb4d0())
        {
            BSAudio::GetSingleton()->SetUseMultipleThreads(true);
            ((LoadingMenuH*)this)->SetFloatFlag(2, true);
        }
        BSAudio::GetSingleton()->SetAudioProperty(2, 1000, 6000);
    }

    *(unsigned int*)((char*)this + 0x5b4) = 0;
    ((Tile3D*)(*(Tile**)((char*)this + 0x28)))->FUN_0056c7f0()->SetAppCulled(true);
}
}  // namespace fnv_007890e0

struct TileList
{
    void* GetHeadPos() const;
    Tile*& GetNext(void*& pos);
};
struct TileEx : public Tile
{
    using Tile::Set;
    void Set(int aeValue, unsigned int auiValue);
    float GetValue(int aeValue);
    void SetImageFlags(int aeValue);
};
struct LoadingTileSettings
{
    unsigned int uiHeader[5];
    float fAlpha;
    int iVisible;
    float fRed;
    float fGreen;
    float fBlue;
    unsigned int uiJustify;
};
struct LoadingMenuTips : public LoadingMenu
{
    void ApplySettingsToTiles(LoadingTileSettings* apSettings);
};

// Applies the loading tile settings (justify, alpha, visibility, colour) to every tile in two tile lists, computing X/Y positions from this menu's bounds.
// @fnv 0x0078c770
void LoadingMenuTips::ApplySettingsToTiles(LoadingTileSettings* apSettings)
{
    void* pos = ((TileList*)m_kFourthTileList)->GetHeadPos();
    while (pos)
    {
        TileEx* pTile = (TileEx*)((TileList*)m_kFourthTileList)->GetNext(pos);
        if (pTile)
        {
            float fX = 0;
            switch (apSettings->uiJustify)
            {
            case 1:
                fX = *(int*)((char*)this + 0xc0);
                break;
            case 2:
                fX = *(int*)((char*)this + 0xc0) + (*(int*)((char*)this + 0xc8) - *(int*)((char*)this + 0xc0)) / 2.0;
                break;
            case 4:
                fX = *(int*)((char*)this + 0xc8);
                break;
            }
            pTile->Set(0xfa1, fX, true);
            pTile->Set(0xfb1, (float)(*(int*)((char*)this + 0xc8) - *(int*)((char*)this + 0xc0)), true);
            pTile->Set(0xfba, pTile->GetValue(0xfb1), true);
            pTile->Set(0xfa2, (float)*(int*)((char*)this + 0xc4), true);
            pTile->Set(0xfb0, *(int*)((char*)this + 0xcc) - pTile->GetValue(0xfa2), true);
            pTile->Set(0xfbb, pTile->GetValue(0xfb0), true);
            pTile->Set(0xffa, apSettings->fAlpha, true);
            pTile->Set(0xfb9, apSettings->iVisible);
            pTile->Set(0xfb7, apSettings->uiJustify);
            pTile->Set(0xfb2, apSettings->fRed, true);
            pTile->Set(0xfb3, apSettings->fGreen, true);
            pTile->Set(0xfb4, apSettings->fBlue, true);
            pTile->Set(0xff5, -1);
            pTile->SetImageFlags(8);
        }
    }
    pos = ((TileList*)m_kFifthTileList)->GetHeadPos();
    while (pos)
    {
        TileEx* pTile = (TileEx*)((TileList*)m_kFifthTileList)->GetNext(pos);
        if (pTile)
        {
            float fX = 0;
            switch (apSettings->uiJustify)
            {
            case 1:
                fX = *(int*)((char*)this + 0xc0);
                break;
            case 2:
                fX = *(int*)((char*)this + 0xc0) + (*(int*)((char*)this + 0xc8) - *(int*)((char*)this + 0xc0)) / 2.0;
                break;
            case 4:
                fX = *(int*)((char*)this + 0xc8);
                break;
            }
            pTile->Set(0xfa1, fX, true);
            pTile->Set(0xfb1, (float)(*(int*)((char*)this + 0xc8) - *(int*)((char*)this + 0xc0)), true);
            pTile->Set(0xfba, pTile->GetValue(0xfb1), true);
            pTile->Set(0xfa2, (float)*(int*)((char*)this + 0xc4), true);
            pTile->Set(0xfb0, *(int*)((char*)this + 0xcc) - pTile->GetValue(0xfa2), true);
            pTile->Set(0xfbb, pTile->GetValue(0xfb0), true);
            pTile->Set(0xffa, apSettings->fAlpha, true);
            pTile->Set(0xfb9, apSettings->iVisible);
            pTile->Set(0xfb7, apSettings->uiJustify);
            pTile->Set(0xfb2, apSettings->fRed, true);
            pTile->Set(0xfb3, apSettings->fGreen, true);
            pTile->Set(0xfb4, apSettings->fBlue, true);
            pTile->Set(0xff5, -1);
            pTile->SetImageFlags(8);
        }
    }
}

extern unsigned char DAT_011dcfb2;

// @fnv 0x00788a90
void FUN_00788a90(unsigned char value)
{
    DAT_011dcfb2 = value;
}

extern unsigned char DAT_011dcfb2;

// @fnv 0x00788aa0
unsigned char FUN_00788aa0()
{
    return DAT_011dcfb2;
}

// @fnv 0x00788f20
int FUN_00788f20()
{
    return 0x3ef;
}

struct NiControllerManager;
struct NiControllerSequence;
struct FUN_00789820_shell : public LoadingMenu
{
    void FUN_00789820();
};

class TESForm_Ex;
class TES;
class TESSound;
class NiControllerSequence;
enum MEDIATYPE
{
    MEDIATYPE_8 = 8
};
extern bool DAT_011a0295;
extern bool DAT_011da0c9;
extern float DAT_011dd300;
extern float DAT_011dd338;
extern double DAT_01073fb8;
extern double DAT_0101db88;
extern const double runtimeInitializationDouble5;
extern double _gModifierZero;
extern TES* g_TES;
extern GlobalObject2_0045cfe0 g_011de740;
extern GlobalObject2_0045cfe0 g_011da0f0;
void* memset(void*, int, unsigned int);
int sprintf_s(char*, unsigned int, const char*, ...);
unsigned int BSStringLength(const char*);
void FUN_005330e0(float&, float, float);
void FUN_00761460(bool);
void FUN_00830660();
int Warning(const char*, ...);
TESForm_Ex** __fastcall _ref_006815c0(void*);
void __fastcall FUN_0078a9f0(char*);
class TESGlobalValueReader
{
  public:
    float GetValue();
};
extern TESGlobalValueReader* DAT_011c3f3c;
class BGSMoviePlayer
{
  public:
    bool FUN_00ec17c0();
    void FUN_00ec16d0(const char*, int, int, int, int, float);
};
extern BGSMoviePlayer* DAT_0126fac4;
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    void Update(bool);
};
struct FalloutAudioMedia
{
    static void Update();
    static void PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
};
class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    bool bUpdateGeomorphs;
    bool bUpdateShadowSceneNode;
    void* pkUpdateTask;
    NiUpdateData(float, bool, bool);
};
struct NN_00605d70
{
    void Update(const NiUpdateData&);
};
struct NiAVObjectS
{
    void FUN_00450f90(bool);
};
struct TGF
{
    float GetFloat(int);
};
struct TileQ
{
    bool ContainsTrait(int);
};
struct TV
{
    bool IsVisible();
};
struct NiControllerManager
{
    bool StopSequence(NiControllerSequence*, float);
};
struct EP_008c48d0
{
    void* GetEntryPoint();
};
struct TESTopicInfo
{
    TESSound* GetConversationData();
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
class Tile3D : public Tile
{
  public:
    bool FUN_00a20cc0(const char*);
};
struct LoadingMenuS
{
    void ToggleFlagBit(int);
    void FUN_0078a230();
    void UpdateLoadingScreenText(int);
    void ApplyLoadingScreenTexture(void*);
    void FUN_0078cc50();
};

// @fnv 0x00789820
void FUN_00789820_shell::FUN_00789820()
{

    DAT_011a0295 = true;
    if (((LoadingMenu*)this)->m_iStateFlags & 1)
    {
        ((LoadingMenu*)this)->m_iStateFlags &= ~1;
        ((LoadingMenu*)this)
            ->m_pTiles[36]
            ->Set(0xfa2, ((TGF*)((LoadingMenu*)this)->m_pTiles[34])->GetFloat(0xfa2) - runtimeInitializationDouble5,
                  true);
        ((LoadingMenu*)this)
            ->m_pTiles[36]
            ->Set(0xfb0, ((TGF*)((LoadingMenu*)this)->m_pTiles[34])->GetFloat(0xfb0) + DAT_0101db88, true);
    }
    if (((LoadingMenu*)this)->m_iStateFlags & 2)
    {
        ((LoadingMenu*)this)->m_iStateFlags &= ~2;
        ((LoadingMenu*)this)
            ->m_pTiles[37]
            ->Set(0xfa2, ((TGF*)((LoadingMenu*)this)->m_pTiles[35])->GetFloat(0xfa2) - runtimeInitializationDouble5,
                  true);
        ((LoadingMenu*)this)
            ->m_pTiles[37]
            ->Set(0xfb0, ((TGF*)((LoadingMenu*)this)->m_pTiles[35])->GetFloat(0xfb0) + DAT_0101db88, true);
    }

    unsigned int CurrTime = gm_GetTickCount();
    if (!((LoadingMenu*)this)->GetFloat(4))
    {
        unsigned int CrossTime = CurrTime - ((LoadingMenu*)this)->m_uiFirstStateValue;
        float fTileAlpha = CrossTime * DAT_01073fb8;
        if (!((LoadingMenu*)this)->m_uiFirstStateValue)
            fTileAlpha = 1.0f;
        FUN_005330e0(fTileAlpha, 0.0f, 1.0f);
        if (((LoadingMenu*)this)->m_uiSecondStateValue % 2 == 0)
            fTileAlpha = 1.0f - fTileAlpha;
        float fSlide01Alpha = fTileAlpha;
        FUN_005330e0(fSlide01Alpha, 0.0f, 1.0f);
        if (((LoadingMenu*)this)->m_pTiles[32])
            ((LoadingMenu*)this)->m_pTiles[32]->Set(0xfa9, (int)(fSlide01Alpha * 255.0));
        float fSlide02Alpha = 1.0f - fTileAlpha;
        FUN_005330e0(fSlide02Alpha, 0.0f, 1.0f);
        if (((LoadingMenu*)this)->m_pTiles[33])
            ((LoadingMenu*)this)->m_pTiles[33]->Set(0xfa9, (int)(fSlide02Alpha * 255.0));
        ((LoadingMenu*)this)->UpdateLoadScreen(*(TESLoadScreen**)((LoadingMenu*)this)->_padToTime, fSlide01Alpha, 1);
        ((LoadingMenu*)this)
            ->UpdateLoadScreen((TESLoadScreen*)*_ref_006815c0(((LoadingMenu*)this)->currentCandidate), fSlide02Alpha,
                               2);
        DAT_011a0295 = true;
    }

    if (CurrTime - ((LoadingMenu*)this)->m_uiFirstStateValue < 3000)
    {
        if (DAT_011a0294 && !((LoadingMenu*)this)->GetFloat(0) && !DAT_0126fac4->FUN_00ec17c0() &&
            BSStringLength(((SettingT_GameSettingCollection_*)&g_011de740)->String()) && !DAT_011da0c9)
        {
            char cfilename[64];
            memset(cfilename, 0, 64);
            sprintf_s(cfilename, 64, "Data\\Music\\Special\\%s.mp3",
                      ((SettingT_GameSettingCollection_*)&g_011da0f0)->String());
            FUN_00761460(true);
            FalloutAudioMedia::PlayMedia(MEDIATYPE_8, cfilename, 0, true, true, 0.0f, 0);
            FUN_00830660();
            DAT_011dd300 = 0.6f;
            DAT_011dd338 = 0.6f;
            ((NiAVObjectS*)((RgbaColor*)((LoadingMenu*)this)->m_pTiles[0])->FUN_0056c7f0())->FUN_00450f90(true);
            ((LoadingMenu*)this)->m_pTiles[32]->Set(0xfa9, 0.0f, true);
            ((LoadingMenu*)this)->m_pTiles[33]->Set(0xfa9, 255.0f, true);
            DAT_0126fac4->FUN_00ec16d0(((SettingT_GameSettingCollection_*)&g_011de740)->String(), 0, -1, 0, 0, 0.0f);
            DAT_011da0c9 = true;
            ((LoadingMenu*)this)->m_pTiles[11]->Set(0xfa3, 1);
            DAT_011a0295 = true;
        }
        else if (DAT_011a0294 && !((LoadingMenu*)this)->GetFloat(0) && !DAT_0126fac4->FUN_00ec17c0() && !DAT_011da0c9 &&
                 !BSStringLength(((SettingT_GameSettingCollection_*)&g_011de740)->String()))
        {
            char cfilename[64];
            memset(cfilename, 0, 64);
            sprintf_s(cfilename, 64, "Data\\Music\\Special\\%s.mp3",
                      ((SettingT_GameSettingCollection_*)&g_011da0f0)->String());
            FUN_00761460(true);
            FalloutAudioMedia::PlayMedia(MEDIATYPE_8, cfilename, 0, true, true, 0.0f, 0);
            FUN_00830660();
            DAT_011dd300 = 0.6f;
            DAT_011dd338 = 0.6f;
            DAT_011da0c9 = true;
        }
    }
    else if (!((LoadingMenu*)this)->nextTipTime)
    {
        if (DAT_011a0294)
        {
            while (!g_TES)
                FUN_0040fca0(5);
            ((LoadingMenuS*)this)->ApplyLoadingScreenTexture(*(void**)((LoadingMenu*)this)->_padToUsFlags_pad1ec);
        }
        if (!*(unsigned int*)((LoadingMenu*)this)->_padToExtra && ((LoadingMenu*)this)->GetFloat(4))
            ((LoadingMenuS*)this)->FUN_0078cc50();
        else
            *(unsigned int*)((LoadingMenu*)this)->_padToExtra = gm_GetTickCount();
        ((LoadingMenu*)this)->nextTipTime = *(unsigned int*)((LoadingMenu*)this)->_padToExtra;
    }
    else if (((LoadingMenu*)this)->GetFloat(4))
    {
        ((LoadingMenuS*)this)->FUN_0078cc50();
    }
    else if (!((LoadingMenu*)this)->GetFloat(9) && gm_GetTickCount() >= ((LoadingMenu*)this)->nextTipTime)
    {
        Tile3D* p3dtile = (Tile3D*)((LoadingMenu*)this)->m_pTiles[0];
        if (p3dtile->FUN_0078a1f0())
        {
            if (!DAT_011a0294 && DAT_011c3f3c->GetValue() == _gModifierZero && !FUN_0070edf0() &&
                (!((LoadingMenu*)this)->GetFloat(3) ||
                 ((TileQ*)((LoadingMenu*)this)->m_pTiles[34])->ContainsTrait(0xfa3)))
                ((LoadingMenuS*)this)->UpdateLoadingScreenText(0);
            FUN_0078a9f0((char*)this);
            ((LoadingMenuS*)this)->ApplyLoadingScreenTexture(0);
            ((NiControllerManager*)((TESTopicInfo*)p3dtile)->GetConversationData())
                ->StopSequence((NiControllerSequence*)((EP_008c48d0*)p3dtile)->GetEntryPoint(), 0.0f);
            ((LoadingMenu*)this)->UpdateLoadingScreenTip();
            if (DAT_011a0294 && ((LoadingMenu*)this)->currentCandidate == &((LoadingMenu*)this)->candidates)
                ((LoadingMenu*)this)->SetFloatFlag(0, true);
        }
        else if (!DAT_011a0294 || !((LoadingMenu*)this)->GetFloat(0))
        {
            if (!((LoadingMenu*)this)->GetFloat(3) && !((LoadingMenu*)this)->GetFloat(8))
            {
                ((LoadingMenu*)this)->nextTipTime = gm_GetTickCount();
                ((LoadingMenuS*)this)->ToggleFlagBit(1);
                if (p3dtile->FUN_00a20cc0(((LoadingMenu*)this)->GetFloat(1) ? "Forward" : "Backward"))
                {
                    ((LoadingMenu*)this)->m_uiFirstStateValue = gm_GetTickCount();
                    ((LoadingMenu*)this)->m_uiSecondStateValue++;
                    if (((LoadingMenu*)this)->GetFloat(7))
                    {
                        ((LoadingMenu*)this)
                            ->SetFloatFlag(
                                8, ((BSSimpleListTESRaceSize*)&((LoadingMenu*)this)->candidates)->GetSize() == 1);
                        ((LoadingMenu*)this)->SetFloatFlag(7, false);
                    }
                    NiUpdateData data(0.0f, true, false);
                    ((NN_00605d70*)((RgbaColor*)p3dtile)->FUN_0056c7f0())->Update(data);
                }
                else
                {
                    Warning("MENUS: (Loading Menu) Unable to play sequence %s",
                            ((LoadingMenu*)this)->GetFloat(1) ? "Forward" : "Backward");
                }
            }
        }
    }

    if (((TV*)((LoadingMenu*)this)->m_pTiles[11])->IsVisible())
        ((LoadingMenuS*)this)->FUN_0078a230();
    BSAudio::GetSingleton()->Update(true);
    FalloutAudioMedia::Update();
}

extern unsigned char DAT_011cabb8;

// @fnv 0x0078a930
unsigned char __cdecl FUN_0078a930()
{
    return DAT_011cabb8;
}

namespace fnv_0078b100 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*& pos);
};
struct TileEx
{
    float GetFloat(int aiID);
};
struct LoadingMenuStandIn
{
    void FUN_0078b100(float afTime, int aiState);
    void SetTileAlpha(Tile* apTile, float afTime);
};
// When aiState is 1, walks the tile list at this+0xd0, sets flag 0xfa3 to 1 on tiles where it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b100
void LoadingMenuStandIn::FUN_0078b100(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(Flt*)((char*)this + 0xd0);
        while (pos)
        {
            Tile* pTile = ((TL*)((char*)this + 0xd0))->GetNext(pos);
            if (pTile)
            {
                if (((TileEx*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}
}  // namespace fnv_0078b100

namespace fnv_0078b190 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*& pos);
};
struct TileEx
{
    float GetFloat(int aiID);
};
struct LoadingMenuStandIn
{
    void UpdateTiles(float afTime, int aiState);
    void SetTileAlpha(Tile* apTile, float afTime);
};
// When aiState is 1, walks the tile list at this+0xdc, sets tile flag 0xfa3 to 1 if it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b190
void LoadingMenuStandIn::UpdateTiles(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(Flt*)((char*)this + 0xdc);
        while (pos)
        {
            Tile* pTile = ((TL*)((char*)this + 0xdc))->GetNext(pos);
            if (pTile)
            {
                if (((TileEx*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}
}  // namespace fnv_0078b190

namespace fnv_0078b220 {
struct FUN_0078b220_shell : public LoadingMenu
{
    void FadeSlideTiles(float, int);
};

struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*& pos);
};
struct TileEx
{
    float GetFloat(int aiID);
};
struct LoadingMenuStandIn
{
    void SetTileAlpha(Tile* apTile, float afAlpha);
};
// For slide 1 or 2, iterates the slide's tile list, marks each tile's 0xfa3 float as 1 if zero, and applies afAlpha to it and the slide's extra tile.
// @fnv 0x0078b220
void FUN_0078b220_shell::FadeSlideTiles(float afAlpha, int anSlide)
{
    void* piter;
    if (anSlide == 1)
    {
        piter = (void*)(unsigned int)*(Flt*)m_kFourthTileList;
        while (piter)
        {
            Tile* pTile = ((TL*)m_kFourthTileList)->GetNext(piter);
            if (pTile)
            {
                if (((TileEx*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                ((LoadingMenuStandIn*)this)->SetTileAlpha(pTile, afAlpha);
            }
        }
        ((LoadingMenuStandIn*)this)->SetTileAlpha(m_pTiles[36], afAlpha);
    }
    if (anSlide == 2)
    {
        piter = (void*)(unsigned int)*(Flt*)m_kFifthTileList;
        while (piter)
        {
            Tile* pTile = ((TL*)m_kFifthTileList)->GetNext(piter);
            if (pTile)
            {
                if (((TileEx*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                ((LoadingMenuStandIn*)this)->SetTileAlpha(pTile, afAlpha);
            }
        }
        ((LoadingMenuStandIn*)this)->SetTileAlpha(m_pTiles[37], afAlpha);
    }
}
}  // namespace fnv_0078b220

namespace fnv_0078b360 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*& pos);
};
struct TileEx
{
    float GetFloat(int aiID);
};
struct LoadingMenuStandIn
{
    void UpdateLoadingTiles(float afTime, int aiState);
    void SetTileAlpha(Tile* apTile, float afTime);
};
// When aiState is 1, walks the tile list at this+0xe8, sets flag 0xfa3 to 1 on tiles where it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b360
void LoadingMenuStandIn::UpdateLoadingTiles(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(Flt*)((char*)this + 0xe8);
        while (pos)
        {
            Tile* pTile = ((TL*)((char*)this + 0xe8))->GetNext(pos);
            if (pTile)
            {
                if (((TileEx*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}
}  // namespace fnv_0078b360

namespace fnv_0078b810 {
struct TileEx
{
    float GetFloat(int aiID);
};
struct TileLayout
{
    int iX;
    int iY;
    int iHeight;
    int iWidth;
    int iZoom;
    unsigned char cJustify;
};
struct FUN_0078b810_shell : LoadingMenu
{
    void CopyTileLayout();
};
// @fnv 0x0078b810
void FUN_0078b810_shell::CopyTileLayout()
{
    for (int i = 0; i < 38; i++)
    {
        int x9 = 0;
        int y4 = 0;
        int height = 0;
        int width = 0;
        int aZoom = 1;
        unsigned char justify = 4;
        if (m_pTiles[i])
        {
            x9 = (int)((TileEx*)m_pTiles[i])->GetFloat(0xfa1);
            y4 = (int)((TileEx*)m_pTiles[i])->GetFloat(0xfa2);
            height = (int)((TileEx*)m_pTiles[i])->GetFloat(0xfb0);
            width = (int)((TileEx*)m_pTiles[i])->GetFloat(0xfb1);
            aZoom = (int)((TileEx*)m_pTiles[i])->GetFloat(0xfb9);
            justify = (unsigned char)((TileEx*)m_pTiles[i])->GetFloat(0xfb7);
        }
        ((TileLayout*)m_kTileLayouts)[i].iX = x9;
        ((TileLayout*)m_kTileLayouts)[i].iY = y4;
        ((TileLayout*)m_kTileLayouts)[i].iHeight = height;
        ((TileLayout*)m_kTileLayouts)[i].iWidth = width;
        ((TileLayout*)m_kTileLayouts)[i].iZoom = aZoom;
        ((TileLayout*)m_kTileLayouts)[i].cJustify = justify;
    }
}
}  // namespace fnv_0078b810

void* __fastcall _ref_00726070(void* apNode);
unsigned int __fastcall FUN_0044edb0(void* apList);
void FUN_0078d670();
extern float DAT_011da16c;
extern int DAT_011da170;
struct BGSSaveFormBuffer
{
    void SerializeFormData(void* apForm, int aiFlags);
    void SaveData(void* apData, int aiSize, int aiFlags);
};
// @fnv 0x0078d6b0
void SaveLoadScreenData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int iElementIndex;
    void* pquest;
    bool bLocationSpecificOnly;
    FUN_0078d670();
    pquest = *(void**)&g_011da168 ? (void*)FUN_0044edb0(*(void**)&g_011da168) : 0;
    iElementIndex = *(void**)&g_011da168 ? (unsigned int)_ref_00726070(*(void**)&g_011da168) : 0;
    apSaveGameBuffer->SerializeFormData(pquest, 0);
    apSaveGameBuffer->SaveData(&iElementIndex, 4, 0);
    apSaveGameBuffer->SaveData(&DAT_011da16c, 4, 0);
    apSaveGameBuffer->SaveData(&DAT_011da170, 4, 0);
    bLocationSpecificOnly = TESLoadScreenFlags::GetUseLocationSpecificScreensOnly();
    apSaveGameBuffer->SaveData(&bLocationSpecificOnly, 1, 0);
}

struct LoadingMenu_CreateProxy
{
    static Tile* __cdecl Create(TESForm*, bool, bool);
};
// @fnv 0x0078d280
void FUN_0078d280(bool abCreate)
{
    if (BSSystemUtility::s_iUpdateEnabled)
        LoadingMenu::UpdateLoadingScreenThread();
    else if (abCreate)
        LoadingMenu_CreateProxy::Create(0, false, false);
    if (BSSystemUtility::s_iUpdateEnabled)
        ((LoadingMenu*&)BSSystemUtility::s_iUpdateEnabled)->SetTileVisible(LoadingMenu::Tile0, false);
}

void _Deallocate(void*);
struct S0078d3f0
{
    void FUN_0078d420();
    void* FUN_0078d3f0(unsigned int);
};
// Calls FUN_0078d420 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0078d3f0
void* S0078d3f0::FUN_0078d3f0(unsigned int flags)
{
    this->FUN_0078d420();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Fake00788ab0
{
    char _pad[0x1e8];
    int f1e8;
    void FUN_00788ab0(int);
};
// If updates are enabled, param_1 is nonzero and the update object's f1e8 is zero, calls FUN_004581c0(true) and then FUN_00788ab0(param_1) on it.
// @fnv 0x00458180
void UpdateIfEnabled(int aiValue)
{
    if (BSSystemUtility::s_iUpdateEnabled != 0 && aiValue != 0 &&
        ((Fake00788ab0*)BSSystemUtility::s_iUpdateEnabled)->f1e8 == 0)
    {
        FUN_004581c0(true);
        ((Fake00788ab0*)BSSystemUtility::s_iUpdateEnabled)->FUN_00788ab0(aiValue);
    }
}

namespace fnv_007887a0 {
class NiRenderer;
NiRenderer* __cdecl FUN_0043c4b0();
void __cdecl FUN_00761460(unsigned char);
void __cdecl FUN_00788a90(unsigned char);
unsigned char __cdecl FUN_00788aa0();
void __fastcall FUN_0078a940(char*);
bool __cdecl FUN_00a61f30(const void*);
extern char* _g_thePlayer;

struct BSS
{
    char d[8];
    ~BSS();
};
struct GO
{
    void* p;
    ~GO();
    void operator=(void*);
};
struct Flt
{
    operator unsigned int();
};
struct ListX
{
    char d[8];
    ~ListX();
};
struct Date
{
    char d[12];
    ~Date();
};
struct GlobalObject_0048f200
{
    char d[12];
    ~GlobalObject_0048f200();
};
struct PatrolActorPackageData
{
    bool IsPatrolling();
};
struct S1740
{
    void FUN_005d1740(int);
};
struct SndX
{
    void Stop();
    void PausePlayback();
};
struct QuestX
{
    void SetEnabled(bool);
};
class BSAudio
{
  public:
    static BSAudio* __cdecl GetSingleton();
    bool FUN_005bb4d0();
    void SetUseMultipleThreads(bool);
};
enum MEDIATYPE
{
    MEDIATYPE_0 = 0
};
class FalloutAudioMedia
{
  public:
    static void __cdecl FadeOutMedia(int, MEDIATYPE);
};
struct RendX
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void SetBackground(void*);
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
    char pad[0x24];
};

struct FUN_007887a0 : Menu_007a8b10
{
    char pad0[0xa8];
    GlobalObject_0048f200 m_kFirstTileList;
    GlobalObject_0048f200 m_kSecondTileList;
    GlobalObject_0048f200 m_kThirdTileList;
    GlobalObject_0048f200 m_kFourthTileList;
    GlobalObject_0048f200 m_kFifthTileList;
    char m_aeMiscStatIdentifiers[0xac];
    BSS m_kLoadingScreenTip;
    char m_kLoadingScreenColor[16];
    ListX m_kLoadScreenItems;
    char pad1[0x10];
    void* pLocation;
    char pad2[8];
    Date m_kFirstDate;
    Date m_kSecondDate;
    GO m_kLoadScreenTextures[4];
    char pad3[0x5c0 - 0x21c];
    virtual ~FUN_007887a0();
};

// @fnv 0x007887a0
FUN_007887a0::~FUN_007887a0()
{
    LoadingMenu::UpdateLoadingScreenThread();
    for (int i = 0; i < 4; i++)
    {
        if (*(Flt*)&m_kLoadScreenTextures[i])
        {
            FUN_00a61f30((const void*)(unsigned int)*(Flt*)&m_kLoadScreenTextures[i]);
            m_kLoadScreenTextures[i] = 0;
        }
    }
    DAT_011d8907 = false;
    ((RendX*)FUN_0043c4b0())->SetBackground(m_kLoadingScreenColor);
    if (FUN_0070edf0() || (DAT_011a0294 && *((SettingT_GameSettingCollection_*)&g_011ded5c)->String()))
    {
        if (((PatrolActorPackageData*)BSAudio::GetSingleton())->IsPatrolling())
            FalloutAudioMedia::FadeOutMedia(4000, (MEDIATYPE)0);
    }
    if (FUN_00788aa0())
    {
        FUN_00788a90(0);
        FUN_00761460(0);
        FalloutAudioMedia::FadeOutMedia(4000, (MEDIATYPE)0);
    }
    if (((LoadingMenu*)this)->GetFloat(2) && BSAudio::GetSingleton()->FUN_005bb4d0())
        BSAudio::GetSingleton()->SetUseMultipleThreads(false);
    ((S1740*)BSAudio::GetSingleton())->FUN_005d1740(1000);
    DAT_011a0294 = false;
    FUN_0078a940((char*)this);
    ((SndX*)&m_kSecondDate)->Stop();
    ((SndX*)&m_kSecondDate)->PausePlayback();
    ((SndX*)&m_kFirstDate)->PausePlayback();
    pLocation = 0;
    BSSystemUtility::s_iUpdateEnabled = 0;
    if (_g_thePlayer && *(QuestX**)(_g_thePlayer + 0xe4c))
    {
        (*(QuestX**)(_g_thePlayer + 0xe4c))->SetEnabled(true);
        *(QuestX**)(_g_thePlayer + 0xe4c) = 0;
    }
}
}  // namespace fnv_007887a0

struct FUN_0078a280_shell : public LoadingMenu
{
    void UpdateLoadingScreenText(bool);
};

extern "C" int __cdecl tolower(int);

extern SettingT_GameSettingCollection_ g_011d3000;
extern bool DAT_011a0295;
struct LoadScreenNode_r8a280
{
    TESLoadScreen** _ref_006815c0();
};
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent* apComponent);
    virtual bool IsEqualToBase(BaseFormComponent* apComponent);
};
class TESDescription : public BaseFormComponent
{
  public:
    virtual const char* GetDescription(TESForm* apForm, unsigned int auiChunk);
};
// Hashes the current candidate's full name, then sets the description and game-setting text on menu tiles and marks DAT_011a0295 true.
// @fnv 0x0078a280
void FUN_0078a280_shell::UpdateLoadingScreenText(bool abRefreshCurrent)
{
    unsigned int iplateno = 0;
    const char* pName = (*((LoadScreenNode_r8a280*)currentCandidate)->_ref_006815c0())->fullName.GetFullName();
    while (*pName)
        iplateno = (iplateno << 5) + iplateno + tolower(*pName++);
    iplateno %= 100000;
    if (m_uiSecondStateValue % 2 == 0)
    {
        m_iStateFlags |= 1;
        m_pTiles[34]->Set(
            0xfc4,
            ((TESDescription*)((char*)*((LoadScreenNode_r8a280*)currentCandidate)->_ref_006815c0() + 0x24))
                ->GetDescription(0, 0x43534544),
            true);
    }
    else
    {
        m_iStateFlags |= 2;
        m_pTiles[35]->Set(
            0xfc4,
            ((TESDescription*)((char*)*((LoadScreenNode_r8a280*)currentCandidate)->_ref_006815c0() + 0x24))
                ->GetDescription(0, 0x43534544),
            true);
    }
    m_pTiles[13]->Set(0xfc4, g_011d3000.String(), true);
    DAT_011a0295 = true;
}

enum MEM_CONTEXT
{
    MEM_CONTEXT_0D = 0xd
};
struct AutoMemContext
{
    int iPrev;
    AutoMemContext(MEM_CONTEXT aeContext, bool abFlag, const char* apFile, int aiLine);
    ~AutoMemContext();
};
class NiSourceTexture;
class NiTexture;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* apObject);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T* apObject);
};
struct LMString
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    int __cdecl Sprintf(const char* apFormat, ...);
    operator const char*() const;
};
struct LMFullName
{
    const char* GetFullName();
};
struct LMLoadScreen
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    LMFullName fullName;
};
struct LMNode
{
    LMLoadScreen** GetItem();
};
class TES
{
  public:
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};
extern TES* g_TES;
bool FUN_00a61f30(const void* apTexture);
struct TileShaderProperty
{
    void SetTexture(NiSourceTexture* apTexture);
};
class LMTile
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual TileShaderProperty* GetShaderProperty();
};
struct LoadingMenuX
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    LMTile* pTileA8;
    LMTile* pTileAC;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    LMString m_kLoadingScreenTip;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    LMNode* currentCandidate;
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
    NiPointer<NiSourceTexture> m_kLoadScreenTextures[4];
    unsigned int m_uiLoadingScreenNumber;
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
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    unsigned int m_uiSecondStateValue;
    void ApplyLoadingScreenTexture(TileShaderProperty* apProperty);
};

// Builds a texture path from the current candidate's full name, creates the texture image, stores it in a rotating slot, and assigns it to a tile shader property.
// @fnv 0x0078a3e0
void LoadingMenuX::ApplyLoadingScreenTexture(TileShaderProperty* apProperty)
{
    AutoMemContext memContext(MEM_CONTEXT_0D, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Menus\\LoadingMenu.cpp",
                              0x423);
    m_kLoadingScreenTip.Sprintf("%s\\%s", "Textures", (*currentCandidate->GetItem())->fullName.GetFullName());
    NiPointer<NiSourceTexture> spTexture(0);
    g_TES->CreateTextureImage(m_kLoadingScreenTip, spTexture, false, false);
    NiPointer<NiSourceTexture>* pSlot = &m_kLoadScreenTextures[m_uiLoadingScreenNumber];
    m_uiLoadingScreenNumber++;
    if (m_uiLoadingScreenNumber >= 4)
    {
        m_uiLoadingScreenNumber = 0;
    }
    if (*pSlot)
    {
        FUN_00a61f30(*pSlot);
    }
    *pSlot = (NiSourceTexture*)spTexture;
    apProperty = (m_uiSecondStateValue % 2 == 0) ? pTileA8->GetShaderProperty() : pTileAC->GetShaderProperty();
    if (apProperty)
    {
        apProperty->SetTexture(spTexture);
    }
}

namespace fnv_0078c210 {
struct NiPoint3
{
    float x, y, z;
};

class TileX
{
  public:
    void Set(int aeValue, float afValue, bool abPropagate);
    void Set(int aeValue, unsigned int auiValue);
    void SetInt(int aeValue, int aiValue);
    float GetFloat(int aeValue);
    void SetChangeFlag(int aiFlags);
    void ApplyRotationOnChildren();
};

struct TileListX
{
    void* GetHeadPos() const;
    TileX*& GetNext(void*& pos);
};

class SettingX
{
  public:
    const char* String();
};
extern SettingX g_011d2358_x;

class FontManager
{
  public:
    static FontManager* Instance();
    NiPoint3 GetStringDimensions(const char* apText, int aiFont, float afWrapWidth, int aiStart);
};

int sprintf_s(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);

struct LoadingTileSettingsX
{
    unsigned int uiHeader[5];
    float fAlpha;
    int m_iType;
    float fRed;
    float fGreen;
    float fBlue;
    unsigned int uiJustify;
};

class LoadingMenuX
{
  public:
    unsigned char _pad00[0x50];
    TileX* pXPBar;
    unsigned char _pad54[0x10];
    TileX* pXPText;
    TileX* pXPBox;
    unsigned char _pad6c[0xc0 - 0x6c];
    int iXPMin;
    int iXPMin2;
    int iXPCur;
    int iXPCur2;
    char m_kFirstTileList[12];
    char m_kSecondTileList[12];
    TileListX m_kThirdTileList;

    void ApplyXPBarSettings(LoadingTileSettingsX* apSettings);
};

// Iterates the tile list, setting XP bar, text and box tile values from the loading settings and XP counters, then applies alpha to the XP box.
// @fnv 0x0078c210
void LoadingMenuX::ApplyXPBarSettings(LoadingTileSettingsX* apSettings)
{
    void* pos = m_kThirdTileList.GetHeadPos();
    while (pos)
    {
        TileX* pTile = m_kThirdTileList.GetNext(pos);
        if (pTile)
        {
            if (pTile == pXPBox)
            {
                pTile->Set(0xfa1, (float)iXPMin, true);
                pTile->Set(0xfb1, (float)(iXPCur - pTile->GetFloat(0xfa1)), true);
                pTile->Set(0xfba, pTile->GetFloat(0xfb1), true);
                pTile->Set(0xfa2, (float)iXPMin2, true);
                pTile->Set(0xfb0, (float)(iXPCur2 - pTile->GetFloat(0xfa2)), true);
            }
            else
            {
                if (pTile == pXPText)
                {
                    float fStart = 0.0f;
                    switch (apSettings->uiJustify)
                    {
                    case 1:
                        fStart = 0.0f;
                        break;
                    case 2:
                        fStart = (iXPCur - iXPMin) / 2.0;
                        break;
                    case 4:
                        fStart = (float)(iXPCur - iXPMin);
                        break;
                    }
                    pTile->Set(0xfa1, fStart, true);
                    pTile->Set(0xfb7, apSettings->uiJustify);
                    pTile->SetInt(0xfb9, apSettings->m_iType);
                    pTile->Set(0xfb1, (float)(iXPCur - iXPMin), true);
                    pTile->Set(0xfba, pTile->GetFloat(0xfb1), true);
                    NiPoint3 kBounds = FontManager::Instance()->GetStringDimensions(
                        g_011d2358_x.String(), apSettings->m_iType, pTile->GetFloat(0xfba), 0);
                    float m_fGlyphExtent = kBounds.y;
                    pTile->Set(0xfb0, m_fGlyphExtent, true);
                }
                else if (pTile == pXPBar)
                {
                    char buffer[260];
                    sprintf_s(buffer, 0x104, "%i", (unsigned int)pTile->GetFloat(0x1005));
                    float fNum = FontManager::Instance()
                                     ->GetStringDimensions(buffer, apSettings->m_iType, pTile->GetFloat(0xfba), 0)
                                     .x;
                    pTile->Set(0xfa1, fNum, true);
                    char acLevel2[260];
                    sprintf_s(acLevel2, 0x104, "%i", (unsigned int)pTile->GetFloat(0x1006));
                    float fRightWidth = FontManager::Instance()
                                            ->GetStringDimensions(acLevel2, apSettings->m_iType,
                                                                  (float)(((iXPCur - iXPMin) - fNum) / 2.0), 0)
                                            .x;
                    pTile->Set(0xfb1, (float)((iXPCur - iXPMin) - fNum * 2.0f - fRightWidth), true);
                }
                pTile->Set(0xfb2, apSettings->fRed, true);
                pTile->Set(0xfb3, apSettings->fGreen, true);
                pTile->Set(0xfb4, apSettings->fBlue, true);
                pTile->SetInt(0xff5, -1);
                pTile->SetChangeFlag(8);
            }
        }
    }
    pXPBox->Set(0xffa, apSettings->fAlpha, true);
    pXPBox->ApplyRotationOnChildren();
}
}  // namespace fnv_0078c210

class Base_b7116
{
  public:
    virtual ~Base_b7116();
    unsigned int unk04[11];
};

class Sub_b7116
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ~Sub_b7116();
};

class FUN_0078d420 : public Base_b7116
{
  public:
    Sub_b7116 unk30;
    Sub_b7116 unk3c;

    virtual ~FUN_0078d420();
};

// Destructor for the class; destroys the two Sub_b7116 members unk3c and unk30.
// @fnv 0x0078d420
FUN_0078d420::~FUN_0078d420()
{}

class LoadingMenuCreateMenu;
class LoadingMenuCreateTile : public Tile
{
  public:
    LoadingMenuCreateTile* ReadFile(const char*);
    LoadingMenuCreateMenu* GetMenu();
};
class LoadingMenuCreateProvider
{
  public:
    LoadingMenuCreateTile* FUN_00586150();
};
class LoadingMenuCreateMenu
{
  public:
    virtual ~LoadingMenuCreateMenu();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual int GetID();
    void FUN_00458080(int, bool);
    void FUN_00788ab0(TESForm*);
    void FUN_00a1dc70(LoadingMenuCreateTile*, bool);
    void CopyTileLayout();
    void FUN_00788f30();
    void FUN_00788f80();
    void FUN_00789080();
    void FUN_00788fe0();
    void FUN_0078b6a0(bool);
    void FUN_0078b6f0(bool);
    void FUN_0078b650(bool);
    void FUN_0078b7c0(bool);
    void InitLoadingMenu(TESForm*);
};
extern LoadingMenuCreateMenu* DAT_011da0c0;
extern LoadingMenuThread* DAT_011da0c4;
extern bool DAT_011da0c8;
LoadingMenuCreateTile* FUN_00a09030(int);
void FUN_00717740(int);
void FUN_0078d020();
void* __cdecl operator new(unsigned int);

// Looks up a loading-menu tile by id; if missing, loads loading_menu.xml, initialises the menu, creates the thread and returns the tile.
// @fnv 0x00788cc0
Tile* __cdecl CreateLoadingMenuTile(TESForm* form, bool refresh, bool visible)
{
    LoadingMenuCreateTile* menu = FUN_00a09030(FUN_00788f20());
    if (menu)
    {
        DAT_011da0c0->FUN_00458080(3, true);
        DAT_011da0c0->FUN_00788ab0(form);
        DAT_011da0c0->FUN_00458080(10, visible);
        return menu;
    }
    DAT_011da0c8 = true;
    LoadingMenuCreateTile* existing = reinterpret_cast<LoadingMenuCreateProvider*>(FUN_004b7210())
                                          ->FUN_00586150()
                                          ->ReadFile("Data\\Menus\\loading_menu.xml");
    DAT_011da0c8 = false;
    LoadingMenuCreateMenu* tile = existing->GetMenu();
    if (tile && tile->GetID() == FUN_00788f20())
    {
        FUN_00717740(0);
        tile->FUN_00a1dc70(existing, false);
        DAT_011da0c0 = tile;
        DAT_011da0c0->CopyTileLayout();
        DAT_011da0c0->FUN_00788f30();
        DAT_011da0c0->FUN_00788f80();
        DAT_011da0c0->FUN_00789080();
        DAT_011da0c0->FUN_00788fe0();
        DAT_011da0c0->FUN_0078b6a0(false);
        DAT_011da0c0->FUN_0078b6f0(false);
        DAT_011da0c0->FUN_0078b650(false);
        DAT_011da0c0->FUN_0078b7c0(false);
        DAT_011da0c0->InitLoadingMenu(form);
        DAT_011da0c0->FUN_00458080(10, visible);
        if (!DAT_011da0c4)
            DAT_011da0c4 = new LoadingMenuThread;
        else if (refresh)
            FUN_0078d020();
        reinterpret_cast<LoadingMenu*>(DAT_011da0c0)->m_pTiles[32]->Set(0xfa9, 0);
        reinterpret_cast<LoadingMenu*>(DAT_011da0c0)->m_pTiles[33]->Set(0xfa9, 0);
        return existing;
    }
    else if (tile && _ref_00726070(tile))
    {
        delete tile;
    }
    return 0;
}

struct ScreenPath
{
    void Set(const char*);
};
struct ScreenEntry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ScreenPath path;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
    ScreenEntry();
    void Prepare();
};
struct ScreenList
{
    bool Empty();
    unsigned int Count();
    void Append(ScreenEntry* const&);
    void Add(ScreenEntry* const&);
    ScreenEntry** Head();
};
struct ScreenArray
{
    int data, size, capacity, grow;
    ScreenArray();
    ~ScreenArray();
};
struct SettingProxy
{
    int a, b, c;
    const char* Text();
    unsigned int* Number();
};
extern SettingProxy screenNames[];
extern DurationData* schedule;
int IsSpecial(const char*);
void NextScreen(int*, int);
struct FUN_0078a5a0_cls : LoadingMenuX
{
    void UpdateLoadingScreens();
    void Clear();
    void SetFlag(int, bool);
    void Gather(ScreenArray&);
    void Build(ScreenArray&);
    void Refresh();
    void Reset();
    void Select(ScreenEntry*, bool);
};
// Clears and rebuilds the loading screen list from settings or gathered entries, adds a fallback entry, refreshes the menu and selects the first entry.
// @fnv 0x0078a5a0
void FUN_0078a5a0_cls::UpdateLoadingScreens()
{
    bool cleared = false;
    if (!((ScreenList*)&unk1d0)->Empty())
    {
        Clear();
        cleared = true;
    }
    SetFlag(5, FUN_0070edf0() || (unsigned char)schedule->FUN_00678ce0());
    if (DAT_011a0294 && !FUN_0070edf0())
    {
        int index = 0;
        if (IsSpecial(((SettingProxy*)&g_011de740)->Text()))
            index = 3;
        for (; index < 5; NextScreen(&index, 0))
        {
            const char* folder = index == 4 ? "Main" : "Loading";
            m_kLoadingScreenTip.Sprintf("Interface\\%s\\%s.dds", folder, screenNames[index].Text());
            ScreenEntry* entry = new ScreenEntry;
            entry->path.Set(m_kLoadingScreenTip);
            entry->Prepare();
            ((ScreenList*)&unk1d0)->Append(entry);
        }
    }
    else
    {
        ScreenArray screenArray;
        Gather(screenArray);
        Build(screenArray);
        if (unk1e8 && ((ScreenList*)&unk1d0)->Count() < *((SettingProxy*)&g_011da138)->Number() && !FUN_0078a930())
        {
            unk1e8 = 0;
            Gather(screenArray);
            Build(screenArray);
        }
    }
    if (((ScreenList*)&unk1d0)->Empty())
    {
        m_kLoadingScreenTip.Sprintf("Interface\\Loading\\%s.dds", screenNames[0].Text());
        ScreenEntry* fallback = new ScreenEntry;
        fallback->path.Set(m_kLoadingScreenTip);
        fallback->Prepare();
        ((ScreenList*)&unk1d0)->Add(fallback);
    }
    if (cleared && !((Tile*)unk028)->FUN_0078a1f0())
    {
        ApplyLoadingScreenTexture(0);
        Refresh();
    }
    SetFlag(7, true);
    unk1dc = (int)*((ScreenList*)&unk1d0)->Head();
    Reset();
    Select((ScreenEntry*)unk1dc, true);
}

template <class T> class NiTListItem;
template <class T> class NiTPointerList
{
  public:
    NiTListItem<T>* FUN_00726070();
    T& GetPrev(NiTListItem<T>*& position);
};
struct LoadingStatsTile : Tile
{
    int unk00;
    NiTPointerList<Tile*> children;
    float FUN_00a011b0(int value);
    void SetChangeFlag(int flags);
    void ApplyRotationOnChildren();
};
struct LoadingStatsSettings
{
    LoadingTileSettings first;
    struct Secondary
    {
        int header0;
        int header1;
        int header2;
        int header3;
        float fAlpha;
        int iVisible;
        float fRed;
        float fGreen;
        float fBlue;
        unsigned int uiJustify;
        unsigned int count;
    } second;
};
struct LoadingStatsMenu
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    LoadingStatsTile* firstStats;
    LoadingStatsTile* secondStats;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    LoadingStatsTile* container;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int left;
    int top;
    int right;
    int bottom;
    void ApplySettings(LoadingStatsSettings* settings);
};
// @fnv 0x0078bc80
void LoadingStatsMenu::ApplySettings(LoadingStatsSettings* settings)
{
    container->Set(0xfa1, float(left), true);
    container->Set(0xfb1, float(right - left), true);
    container->Set(0xfa2, float(top), true);
    container->Set(0xfb0, float(bottom - top), true);
    firstStats->Set(0xfb9, settings->first.iVisible);
    firstStats->Set(0xfb2, settings->first.fRed, true);
    firstStats->Set(0xfb3, settings->first.fGreen, true);
    firstStats->Set(0xfb4, settings->first.fBlue, true);
    secondStats->Set(0xfb9, settings->second.iVisible);
    firstStats->Set(0xfb2, settings->second.fRed, true);
    firstStats->Set(0xfb3, settings->second.fGreen, true);
    firstStats->Set(0xfb4, settings->second.fBlue, true);
    float spacing = container->FUN_00a011b0(0xfb0) / settings->second.count;
    float y = 0.0f;
    NiTListItem<Tile*>* secondPos = firstStats->children.FUN_00726070();
    NiTListItem<Tile*>* pos2 = secondStats->children.FUN_00726070();
    unsigned int uiIndex = 1;
    while (secondPos && pos2)
    {
        Tile* firstTile = firstStats->children.GetPrev(secondPos);
        Tile* secondTile = secondStats->children.GetPrev(pos2);
        if (firstTile && secondTile)
        {
            bool visible = true;
            if (uiIndex <= settings->second.count)
            {
                firstTile->Set(0xfa2, y, true);
                secondTile->Set(0xfa2, y, true);
                y += spacing;
                static_cast<LoadingStatsTile*>(firstTile)->SetChangeFlag(8);
                static_cast<LoadingStatsTile*>(secondTile)->SetChangeFlag(8);
                ++uiIndex;
            }
            else
            {
                visible = false;
            }
            firstTile->Set(0xfa3, int(visible));
            secondTile->Set(0xfa3, int(visible));
        }
    }
    container->Set(0xffa, settings->first.fAlpha, true);
    container->ApplyRotationOnChildren();
}

struct Font
{
    float Height();
};
struct Extent
{
    float x;
    float y;
    float z;
};
struct FontMgr
{
    Font* fonts[8];
    void Measure(Extent*, const char*, int, float, int);
};
FontMgr* FUN_005bd5b0();
struct TileWork
{
    void Set(int, float, bool);
    void SetInt(int, int);
    void SetUnsigned(int, unsigned);
    float Get(int);
    void Update(int);
    void Finish();
};
struct WorkTileList
{
    void* Head();
    TileWork*& Next(void*&);
};
struct Options
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float alpha;
    int font;
    float value1;
    float value2;
    float value3;
    unsigned align;
};
struct MenuWork
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    TileWork* secondary;
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
    TileWork* primary;
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
    int left;
    int top;
    int right;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    WorkTileList tiles;
    void UpdateMenuTiles(Options*);
};
// Measures the selected font, configures the primary and secondary tiles from options, sets the primary tile's alpha and finishes it.
// @fnv 0x0078bf80
void MenuWork::UpdateMenuTiles(Options* options)
{
    float fontHeight = FUN_005bd5b0()->fonts[options->font]->Height();
    void* position = tiles.Head();
    while (position)
    {
        TileWork* tile = tiles.Next(position);
        if (tile)
        {
            if (tile == primary)
            {
                float offset = 0.0f;
                switch (options->align)
                {
                case 1:
                    offset = left;
                    break;
                case 2:
                    offset = left + (right - left) / 2.0;
                    break;
                case 4:
                    offset = right;
                    break;
                }
                tile->Set(0xfa1, offset, true);
                tile->Set(0xfb1, float(right - left), true);
                tile->Set(0xfba, tile->Get(0xfb1), true);
                tile->Set(0xfa2, float(top), true);
                tile->SetInt(0xfb9, options->font);
                tile->SetUnsigned(0xfb7, options->align);
                tile->Set(0xfb2, options->value1, true);
                tile->Set(0xfb3, options->value2, true);
                tile->Set(0xfb4, options->value3, true);
                tile->SetInt(0xff5, -1);
                tile->Update(8);
            }
            else if (tile == secondary)
            {
                float width = float(right - left);
                Extent extent;
                FUN_005bd5b0()->Measure(&extent, ((SettingT_GameSettingCollection_*)&g_011d40f0)->String(),
                                        options->font, width, 0);
                float height = extent.y;
                tile->Set(0xfa2, height, true);
            }
        }
    }
    primary->Set(0xffa, options->alpha, true);
    primary->Finish();
}

struct TileVT
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual unsigned int GetType();
};
struct TileImage3D
{
    NiNode* FUN_0056c7f0();
};
struct FUN_0078ce10_shell
{
    char pad00[0x58];
    Tile* m_pkInvertedTile;
    char pad5c[0xac - 0x5c];
    Tile* m_pkSkipTile;
    void SetAlphaRecursive(NiNode* pkNode, float fAlpha);
    void SetTileAlpha(Tile* pkTile, float fAlpha);
};

// @fnv 0x0078ce10
void FUN_0078ce10_shell::SetTileAlpha(Tile* pkTile, float fAlpha)
{
    if (!pkTile)
        return;
    if (pkTile == m_pkSkipTile)
        return;
    fAlpha = FUN_0040ebd0(fAlpha, 1.0f);
    fAlpha = FUN_00404010(fAlpha, 0.0f);
    if (((TileVT*)pkTile)->GetType() == 0x388)
    {
        SetAlphaRecursive(((TileImage3D*)pkTile)->FUN_0056c7f0(), fAlpha);
        return;
    }
    if (pkTile == m_pkInvertedTile)
        fAlpha = 1.0f - fAlpha;
    pkTile->Set(0xfa9, fAlpha * 255.0, true);
    DAT_011a0295 = true;
    void* pPos = ((TileList*)((char*)pkTile + 4))->GetHeadPos();
    while (pPos)
        SetTileAlpha(((TileList*)((char*)pkTile + 4))->GetNext(pPos), fAlpha);
}

namespace fnv_0078bb60 {
extern bool DAT_011a0296;
struct PerkEntryX : BGSPerkEntry
{
    void* FUN_005f36f0();
    int FUN_0078bc60();
    int FUN_005a7130();
};
struct LoadingMenuX : LoadingMenu
{
    bool FUN_00458110(int);
    void FUN_0078b9b0(int);
    void ApplySettings(int);
    void ApplyXPBarSettings(int);
    void ApplySettingsToTiles(int);
    void UpdateMenuTiles(int);
    void FUN_0078bb60(BGSPerkEntry* entry);
};
// Applies the selected perk entry's settings to the loading menu tiles, XP bar, or menu tiles based on its type, then clears DAT_011a0296.
// @fnv 0x0078bb60
void LoadingMenuX::FUN_0078bb60(BGSPerkEntry* entry)
{
    if (!FUN_00458110(6))
        return;
    if (entry == 0)
    {
        if (currentCandidate)
            entry = currentCandidate->GetItem();
        else
            entry = candidates.GetItem();
        if (entry == 0)
            return;
    }
    if (((PerkEntryX*)entry)->FUN_005f36f0())
    {
        int x = ((PerkEntryX*)entry)->FUN_0078bc60();
        FUN_0078b9b0(x);
        switch (((PerkEntryX*)entry)->FUN_005a7130())
        {
        case 4:
            ApplySettings(x);
            break;
        case 1:
            ApplyXPBarSettings(x);
            break;
        case 3:
            ApplySettingsToTiles(x);
            break;
        case 2:
            UpdateMenuTiles(x);
            break;
        }
    }

    DAT_011a0296 = false;
}
}  // namespace fnv_0078bb60

namespace s78cc50 {

struct Tile
{
    float FUN_00a011b0(unsigned int uiValue);
};

struct TileMenu
{
    void FUN_00a20610(int iValue);
};

struct VATSCamera
{
    int FUN_0078cdf0();
};

extern VATSCamera* DAT_011dea0c;
extern bool DAT_011a0294;

unsigned int FUN_00457fe0();

struct FadeMenu
{
    int unk000;
    Tile* m_pkTile;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    TileMenu* m_pkMenu;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    unsigned int m_uiEndTime;
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
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int m_iFadeCount;

    void SetTileAlpha(Tile* pkTile, float fAlpha);
    void FUN_00458080(int iArg0, int iArg1);
    void FUN_0078cc50();
};

// @fnv 0x0078cc50
void FadeMenu::FUN_0078cc50()
{
    static float s_fDuration = m_pkTile->FUN_00a011b0(0xfc1) * 1000.0;

    if (m_uiEndTime == 0)
    {
        if (DAT_011dea0c->FUN_0078cdf0() || DAT_011a0294)
        {
            m_pkMenu->FUN_00a20610(DAT_011dea0c->FUN_0078cdf0());
            m_uiEndTime = (unsigned int)(FUN_00457fe0() + s_fDuration);
        }
        else
        {
            m_uiEndTime = FUN_00457fe0();
        }
    }
    if (FUN_00457fe0() < m_uiEndTime)
    {
        unsigned int uiRemaining = m_uiEndTime - FUN_00457fe0();
        SetTileAlpha(m_pkTile, 1.0f - uiRemaining / s_fDuration);
    }
    else
    {
        SetTileAlpha(m_pkTile, 1.0f);
        FUN_00458080(4, 0);
        m_iFadeCount++;
    }
}

}

void* __fastcall _ref_00726070(void* apNode);
extern bool DAT_011a0294;
unsigned int gm_GetTickCount();

struct FUN_0078aa90_shell : LoadingMenu
{
    bool UpdateLoadingScreen();
};
// If DAT_011a0294 is set, GetFloat(0) is zero, and p3dtile->FUN_0078a1f0() is false, advance currentCandidate and apply the loading texture.
// @fnv 0x0078aa90
bool FUN_0078aa90_shell::UpdateLoadingScreen()
{
    Tile* p3dtile = m_pTiles[0];
    if (DAT_011a0294 && !GetFloat(0) && !p3dtile->FUN_0078a1f0())
    {
        while (_ref_00726070(currentCandidate))
            currentCandidate = (BSSimpleList<BGSPerkEntry*>*)_ref_00726070(currentCandidate);
        ((LoadingMenuS*)this)->ApplyLoadingScreenTexture(0);
        nextTipTime = gm_GetTickCount();
        return true;
    }
    else
    {
        return false;
    }
}

struct LoadVisibilityMenu : LoadingMenu
{
    void FUN_0078b3f0(TESLoadScreen*, bool);
    void FUN_0078b650(bool);
    void FUN_0078b6a0(bool);
    void FUN_0078b6f0(bool);
    void FUN_0078b7c0(bool);
};

// For a selected screen with bShow true, dispatches settings by screen type; otherwise passes bShow to all four methods.
// @fnv 0x0078b3f0
void LoadVisibilityMenu::FUN_0078b3f0(TESLoadScreen* pLoadScreen, bool bShow)
{
    if (!GetFloat(6))
    {
        return;
    }
    if (!pLoadScreen)
    {
        if (currentCandidate)
        {
            pLoadScreen = (TESLoadScreen*)currentCandidate->GetItem();
        }
        else
        {
            pLoadScreen = (TESLoadScreen*)candidates.GetItem();
        }
        if (!pLoadScreen)
        {
            return;
        }
    }
    if (pLoadScreen && bShow)
    {
        switch (pLoadScreen->GetLoadScreenTypeDataType())
        {
        case 2:
            FUN_0078b6a0(bShow);
            FUN_0078b650(!bShow);
            FUN_0078b6f0(!bShow);
            FUN_0078b7c0(!bShow);
            break;
        case 4:
            FUN_0078b6a0(!bShow);
            FUN_0078b650(bShow);
            FUN_0078b6f0(!bShow);
            FUN_0078b7c0(!bShow);
            break;
        case 3:
            FUN_0078b6a0(!bShow);
            FUN_0078b650(!bShow);
            FUN_0078b6f0(bShow);
            FUN_0078b7c0(!bShow);
            break;
        case 1:
            FUN_0078b6a0(!bShow);
            FUN_0078b650(!bShow);
            FUN_0078b6f0(!bShow);
            FUN_0078b7c0(bShow);
            break;
        default:
            FUN_0078b6a0(false);
            FUN_0078b650(false);
            FUN_0078b6f0(false);
            FUN_0078b7c0(false);
            break;
        }
    }
    else
    {
        FUN_0078b6a0(bShow);
        FUN_0078b650(bShow);
        FUN_0078b6f0(bShow);
        FUN_0078b7c0(bShow);
    }
}

namespace fnv_00788ab0 {
extern bool DAT_011a0295;
struct LoadingResetTileState
{
    void FUN_00458080(LoadingMenu::TileIndex, bool);
};
struct S00788ab0_AfaShell
{
    void FUN_0078afa0(bool);
};
struct S00788ab0_LoadingMenu
{
    void UpdateLoadingScreenText(int);
    void ApplyLoadingScreenTexture(int);
    void FUN_0078a230();
};
void* __cdecl FUN_0043c4b0();
void __cdecl FUN_00a04200(bool);
void __fastcall FUN_0078a9f0(char*);
class S00788ab0_StartMenu
{
  public:
    enum S00788ab0_Flag
    {
        Flag1 = 1
    };
    virtual ~S00788ab0_StartMenu();
    bool IsFlagSet(S00788ab0_Flag);
};
struct S00788ab0_MenuTileQuery
{
    S00788ab0_StartMenu* GetMenu();
};
int FUN_0070ede0();
S00788ab0_MenuTileQuery* FUN_00a09030(int);
void FUN_0078cfc0();
void FUN_0078d020();
void __fastcall FUN_004a0370(char*);
void __fastcall FUN_004a03c0(char*);
struct S00788ab0_OSQuery
{
    bool FUN_00678ce0();
};
struct S00788ab0_InterfaceQuery
{
    Tile* GetParent();
};
struct S00788ab0_VisibleTile
{
    bool IsVisible();
};
struct S00788ab0_LoadingSetup : LoadingMenu
{
    void FUN_00788ab0(int);
    void FUN_0078aec0();
    void UpdateLoadingScreens();
    void FUN_0078abd0();
};
// When GetFloat(3) is nonzero, updates timers and menu state, configures tiles, and assigns value to extraCandidates.
// @fnv 0x00788ab0
void S00788ab0_LoadingSetup::FUN_00788ab0(int aiExtraCandidates)
{
    if (GetFloat(3))
    {
        FUN_0078cfc0();
        m_uiFirstStateValue = gm_GetTickCount() - 4000;
        if (DAT_011d8907 || g_BGSSaveLoadGame->FUN_0042ce10())
        {
            S00788ab0_StartMenu* menu = FUN_00a09030(FUN_0070ede0())->GetMenu();
            if (menu && !menu->IsFlagSet(S00788ab0_StartMenu::Flag1))
            {
                delete menu;
            }
        }
        if (((S00788ab0_OSQuery*)g_osGlobals)->FUN_00678ce0())
        {
            ((S00788ab0_AfaShell*)this)->FUN_0078afa0(false);
        }
        else
        {
            ((S00788ab0_AfaShell*)this)->FUN_0078afa0(true);
            FUN_0078aec0();
        }
        extraCandidates = aiExtraCandidates;
        UpdateLoadingScreens();
        extraCandidates = aiExtraCandidates;
        nextTipTime = gm_GetTickCount();
        ++m_uiSecondStateValue;
        ((S00788ab0_LoadingMenu*)this)->UpdateLoadingScreenText(0);
        FUN_0078a9f0((char*)this);
        ((S00788ab0_LoadingMenu*)this)->ApplyLoadingScreenTexture(0);
        FUN_0078abd0();
        ++m_uiSecondStateValue;
        ((S00788ab0_LoadingMenu*)this)->UpdateLoadingScreenText(0);
        FUN_0078a9f0((char*)this);
        ((S00788ab0_LoadingMenu*)this)->ApplyLoadingScreenTexture(0);
        FUN_0078abd0();
        ((LoadingResetTileState*)this)->FUN_00458080((TileIndex)3, false);
        FUN_004a0370((char*)FUN_0043c4b0());
        if (!((S00788ab0_VisibleTile*)m_pTiles[11])->IsVisible())
        {
            m_pTiles[11]->Set(4003, 1);
            ((S00788ab0_LoadingMenu*)this)->FUN_0078a230();
        }
        ((S00788ab0_InterfaceQuery*)FUN_004b7210())->GetParent()->Set(4003, 0);
        FUN_00a04200(true);
        FUN_004a03c0((char*)FUN_0043c4b0());
        DAT_011a0295 = true;
        FUN_0078d020();
    }
}
}  // namespace fnv_00788ab0
