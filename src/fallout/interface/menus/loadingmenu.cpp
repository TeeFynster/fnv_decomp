// fallout/interface/menus/loadingmenu.cpp: LoadingMenu, BSAudio, LoadingMenu, LoadingMenu and more (71 functions)

#include "../../../../include/MEDIATYPE.h"
#include "../../../../include/LoadingMenu.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/TESForm.h"
// InterfaceH_loadingmenu: local type (was include/InterfaceH.h, which had no evidence of one real class); its methods are 0x00702360 Interface::IsInMenuMode, 0x00702450 Interface::IsTopMenuID, 0x00703860 HUDMainMenu::HandleHealthbarForCrosshairActor_, 0x00705e00 Interface::CreateLoadingMenu
class TESObjectREFR;

class InterfaceH_loadingmenu
{
public:
    static bool __cdecl GetSelectedTargetIndex(int);
    static void SetQuestTarget(TESForm*, bool);
    static void SetLookAtReference(TESObjectREFR*);
    static double GetFourthInterfaceFloat();
    static double GetThirdInterfaceFloat();
    static bool IsSaveLoadActive();
};
#include "../../../../include/BGSCameraPath.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/InterfaceManager.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSMusicType.h"
#include "../../../../include/BGSPerkEntry.h"
#include "../../../../include/BGSQuestObjective.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/NiFormArray.h"
#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/TileShaderProperty.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/SettingT_GameSettingCollection_.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/TESLoadScreen.h"
#include "../../../../include/TESQuest.h"
#include "../../../../include/BGSMoviePlayer.h"
#include "../../../../include/HUDMainMenu.h"
#include "../../../../include/LoadingMenuThread.h"
#include "../../../../include/NiControllerManager.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TESDescription.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESTopicInfo.h"
#include "../../../../include/Tile.h"
#include "../../../../include/Tile3D.h"
#include "../../../../include/TileMenu.h"
#include "../../../../include/AutoMemContext.h"
#include "../../../../include/BSSystemUtility.h"
#include "../../../../include/BaseFormComponent.h"
#include "../../../../include/CountingSemaphore.h"
#include "../../../../include/Font.h"
#include "../../../../include/FontManager.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/PatrolActorPackageData.h"
#include "../../../../include/RecursiveLock.h"
#include "../../../../include/TES.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/NiRenderer.h"

// FontManager's shared return type is being revised; retain this unit's checked ABI.
struct LoadingFontDimensions : FontManager
{
    NiPoint3 GetStringDimensions(const char*, int, float, int);
};

// Tile.h does not yet declare this text-layout finalization entry point.
struct LoadingStatsTile : Tile
{
    void Tile_ApplyRotationOnChildren();
};

InterfaceManager* InterfaceManager_GetSingleton();
unsigned int NiMaterialProperty_GetType();

// The shared setting header lacks the float-returning accessor at 0x00450410.
class LoadingFloatSetting : public SettingT_GameSettingCollection_
{
  public:
    float FUN_00450410();
};
extern LoadingFloatSetting g_011da158, g_011da190, g_011da1a0;
extern bool DAT_011a0294;
bool StartMenu_MainMenuIsActive();
unsigned int gm_GetTickCount();

#include "../../../../include/ENUM_FORM_ID.h"

int BSstrcmp(const char*, const char*);

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
class GlobalObject_0078d900
{
  public:
    BGSQuestObjective* objective;
};
extern GlobalObject_0078d900 g_011da168;
extern float DAT_011da16c;
extern int DAT_011da170;
extern SettingT_GameSettingCollection_ g_011d1f8c, g_011d40f0, g_011d2358;
void LoadingMenu_FillDisplayData();

extern SettingT_GameSettingCollection_ g_011ded5c;
void BSSleep(unsigned long);

extern SettingT_GameSettingCollection_ g_011da108, g_011da124, g_011da138;
class ParentSpaceNode;

class ScriptVariableInfo;
unsigned int __fastcall CountLoadingCandidates(BSSimpleList<BGSMusicType::MusicTrack*>* m_kLoadScreenItems);
unsigned int FUN_0042f5a0(unsigned int, unsigned int);
unsigned int RandomUnsignedInt(unsigned int);
class TESLoadScreenFlags
{
  public:
    static bool GetUseLocationSpecificScreensOnly();
    static void SetUseLocationSpecificScreensOnly(bool);
};

extern SettingT_GameSettingCollection_ g_011d0c60;
void LoadingMenu_FlagReset(bool);

extern TESDataHandler* g_dataHandler;
class OSGlobals;
extern OSGlobals* g_osGlobals;
class DurationData
{
  public:
    char Main_GameReset();
};
extern bool DAT_011d8907;
class NavMeshInfo;
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
        reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->TESAnimGroup_GetDecal() &&
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
    Tile* tile = InterfaceManager_GetSingleton()->GetParent();
    NiNode* node = tile ? tile->GetModel_0056c7f0() : 0;
    object = 0;
    // object is deliberately initialized after obtaining the node.
    if (node)
    {
        object = reinterpret_cast<NiGeometry*>(node->NiNode_GetAtChecked(0));
        if (object)
        {
            NiProperty* property = object->GetProperty((int)NiMaterialProperty_GetType());
            if (property)
                property->NiMaterialProperty_SetAlpha((float)visible);
        }
    }
}

// Computes a delay from one of three sources depending on state, converts it to milliseconds, and stores the next tip time as the current tick plus that delay.
// @fnv 0x0078abd0
void LoadingMenu::UpdateLoadingScreenTip()
{
    float delay = 0.0f;
    if (StartMenu_MainMenuIsActive())
        delay = g_011da190.FUN_00450410();
    else if (DAT_011a0294)
        delay = g_011da158.FUN_00450410();
    else
        delay = g_011da1a0.FUN_00450410();
    m_uiLoadScreenIndex = gm_GetTickCount() + (unsigned int)(delay * 1000.0);
}

// @fnv 0x0078ab20
bool LoadingMenu::IsLoadScreenValid(TESLoadScreen* screen)
{
    bool valid = screen && screen->GetFormType() == ENUM_FORM_ID_LSCR_ID;
    for (BSSimpleList<TESLoadScreen*>* entry = &m_kLoadScreenItems; valid && entry && entry->GetItem(); entry = entry->GetNext())
    {
        valid = BSstrcmp(reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(screen) + offsetof(TESLoadScreen, FullNameComponent) - offsetof(TESFullName, m_kName))->GetFullName(), reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(entry->GetItem()) + 0x18)->GetFullName()) != 0;
    }
    return valid;
}

// @fnv 0x0078aec0
void LoadingMenu::RefreshLoadingScreen()
{
    if (!g_BGSSaveLoadGame || !g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        LoadingMenu_FillDisplayData();
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
            BSSleep(interval - gm_GetTickCount());
        if (m_bFirstThreadFlag &&
            (!DAT_011a0294 || *reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011ded5c)->String() ||
             !reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->m_pTiles[0]->Tile3D_IsPlaying()))
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

// Picks random load screens from array into m_kLoadScreenItems until the candidate count reaches the game-setting count, removing each picked entry.
// @fnv 0x0078adc0
void LoadingMenu::SelectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>& aLoadScreens)
{
    unsigned int count = *reinterpret_cast<unsigned int*>(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da138)->Int());
    if (GetFloat(5))
        count = *reinterpret_cast<unsigned int*>(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da124)->Int());
    else if (pLocation && !TESLoadScreenFlags::GetUseLocationSpecificScreensOnly())
        count = FUN_0042f5a0(count, *reinterpret_cast<unsigned int*>(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da108)->Int()));
    unsigned int maximum = CountLoadingCandidates(reinterpret_cast<BSSimpleList<BGSMusicType::MusicTrack*>*>(&m_kLoadScreenItems));
    while (maximum < count && reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&aLoadScreens)->GetSize())
    {
        unsigned int index =
            RandomUnsignedInt(reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&aLoadScreens)->GetSize());
        if (IsLoadScreenValid(
                reinterpret_cast<TESLoadScreen*>(reinterpret_cast<NiFormArray*>(&aLoadScreens)->FUN_00877a30(index))))
        {
            reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&m_kLoadScreenItems)
                ->AddTail(reinterpret_cast<ScriptVariableInfo* const&>(
                    reinterpret_cast<NiFormArray*>(&aLoadScreens)->FUN_00877a30(index)));
            ++maximum;
        }
        reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>(&aLoadScreens)->UpdateEntryValue(index, 1);
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
    if ((unsigned int)DAT_011da170 >= *reinterpret_cast<unsigned int*>(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d0c60)->Int()))
        DAT_011da16c = 0.0f;
    bool a = false;  // location-specific screens only
    buffer->ReadDataBlock(&a, 1);
    TESLoadScreenFlags::SetUseLocationSpecificScreensOnly(a);
    if (BSSystemUtility::s_iUpdateEnabled)
    {
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->m_pTiles[11]->Set(0xfa3, 1);
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->SetFloatFlag(8, false);
    }
    LoadingMenu_FlagReset(true);
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
             ((pLocation && reinterpret_cast<TESLoadScreen*>(entry->GetItem())
                                      ->MatchesFormLocation(pLocation)) ||
              (!pLocation && reinterpret_cast<TESLoadScreen*>(entry->GetItem())->IsDefaultLoadScreen()))))
        {
            unsigned int index = reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&aLoadScreens)
                                     ->Add(reinterpret_cast<NavMeshInfo*&>(entry->GetItem()));
            int type = reinterpret_cast<TESLoadScreen*>(entry->GetItem())->GetLoadScreenTypeDataType();
            if ((DAT_011d8907 || (unsigned char)reinterpret_cast<DurationData*>(g_osGlobals)->Main_GameReset()) &&
                type != 3 && type != 0)
                reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>(&aLoadScreens)->UpdateEntryValue(index, 1);
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
        if (m_pkLoadScreenList)
            screen = reinterpret_cast<TESLoadScreen*>(m_pkLoadScreenList->GetItem());
        else
            screen = reinterpret_cast<TESLoadScreen*>(m_kLoadScreenItems.GetItem());
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
            UpdateStatsTilesAlphas(alpha, mode);
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
// src: XBOX_PDB 0x004581c0
void __cdecl LoadingMenu_FlagReset(bool abOn)
{
    if (BSSystemUtility::s_iUpdateEnabled)
    {
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->SetFloatFlag(3, abOn);
    }
}

struct SubObj
{
    void FUN_004ed900();
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(int*);
};
// Calls s.FUN_004ed900, then passes &a and &b to s.FUN_004ed8c0 in turn.
// @fnv 0x00788f30
// src: COMMUNITY 0x00788f30
void LoadingMenu::InitStatsTilesList()
{
    reinterpret_cast<SubObj*>(&m_kFirstTileList)->FUN_004ed900();
    reinterpret_cast<SubObj*>(&m_kFirstTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(&*reinterpret_cast<int*>(&m_pTiles[17]));
    reinterpret_cast<SubObj*>(&m_kFirstTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(&*reinterpret_cast<int*>(&m_pTiles[18]));
}

struct FUN_Sub
{
    void FUN_004ed900();
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(void* p);
};
// Calls FUN_004ed900 on the FUN_Sub at self+0xdc, then FUN_004ed8c0 with self+0x94, self+0x34 and self+0x60.
// @fnv 0x00788f80
// src: COMMUNITY 0x00788f80
void __fastcall LoadingMenu_InitObjectiveTilesList(char* self)
{
    ((FUN_Sub*)(self + 0xdc))->FUN_004ed900();
    ((FUN_Sub*)(self + 0xdc))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(self + 0x94);
    ((FUN_Sub*)(self + 0xdc))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(self + 0x34);
    ((FUN_Sub*)(self + 0xdc))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(self + 0x60);
}

struct M788
{
    void FUN_004ed900();
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(void*);
};
// Calls m.FUN_004ed900, then passes six member addresses (offsets 0x68, 0x98, 0x9c, 0x64, 0x50, 0xa0) to m.FUN_004ed8c0.
// @fnv 0x00788fe0
// src: COMMUNITY 0x00788fe0
void LoadingMenu::InitXPProgressTilesList()
{
    reinterpret_cast<M788*>(&m_kThirdTileList)->FUN_004ed900();
    reinterpret_cast<M788*>(&m_kThirdTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail((char*)this + 0x68);
    reinterpret_cast<M788*>(&m_kThirdTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail((char*)this + 0x98);
    reinterpret_cast<M788*>(&m_kThirdTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail((char*)this + 0x9c);
    reinterpret_cast<M788*>(&m_kThirdTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail((char*)this + 0x64);
    reinterpret_cast<M788*>(&m_kThirdTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail((char*)this + 0x50);
    reinterpret_cast<M788*>(&m_kThirdTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail((char*)this + 0xa0);
}

namespace fnv_00789080 {
struct SubObj
{
    void FUN_004ed900();
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(int*);
};
} // namespace fnv_00789080

// Calls FUN_004ed900 then FUN_004ed8c0 on s1 with &a and on s2 with &b.
// @fnv 0x00789080
// src: COMMUNITY 0x00789080
void LoadingMenu::InitTipTilesList()
{
    reinterpret_cast<fnv_00789080::SubObj*>(&m_kFourthTileList)->FUN_004ed900();
    reinterpret_cast<fnv_00789080::SubObj*>(&m_kFourthTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(&*reinterpret_cast<int*>(&m_pTiles[34]));
    reinterpret_cast<fnv_00789080::SubObj*>(&m_kFifthTileList)->FUN_004ed900();
    reinterpret_cast<fnv_00789080::SubObj*>(&m_kFifthTileList)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSMultiBoundRoom_AddTail(&*reinterpret_cast<int*>(&m_pTiles[35]));
}

// Toggles the bit at position aBit in usFlags using XOR with 1 << aBit.
// @fnv 0x0078a1c0
void LoadingMenu::ToggleFlagBit(int aBit)
{
    usFlags ^= 1 << aBit;
}

// Returns true if pSequence is set and its GetState() equals 1.
// @fnv 0x0078a1f0
// src: XBOX_PDB 0x0078a1f0
bool Tile::Tile3D_IsPlaying()
{
    return *reinterpret_cast<NiControllerSequence**>(reinterpret_cast<char*>(this) + 0x3c) &&
           (*reinterpret_cast<NiControllerSequence**>(reinterpret_cast<char*>(this) + 0x3c))->GetState() == 1;
}

// Tile3D does not yet declare this animation-update entry point.
struct LoadingTileAnimation : Tile3D
{
    void UpdateAnimation(float a1, int a2);
};

// Calls UpdateAnimation on the object at offset 0x54 with -1.0f and 0.
// @fnv 0x0078a230
// src: COMMUNITY 0x0078a230
void LoadingMenu::ResetLoadingPinwheelAnimation()
{
    (*reinterpret_cast<LoadingTileAnimation**>(reinterpret_cast<char*>(this) + 0x54))->UpdateAnimation(-1.0f, 0);
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

TESForm** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
bool __fastcall TESForm_GetTemporary(const void*);
void __fastcall FUN_00470470(void*);

// @fnv 0x0078a940
// src: XBOX_PDB 0x0078a940
void __fastcall LoadingMenu_FlushLoadScreenList(char* this_ptr)
{
    for (void* pIter = this_ptr + 0x1d0; pIter && *_ref_006815c0(pIter); pIter = _ref_00726070(pIter))
    {
        if (TESForm_GetTemporary(*_ref_006815c0(pIter)))
        {
            delete *_ref_006815c0(pIter);
        }
    }
    FUN_00470470(this_ptr + 0x1d0);
    *reinterpret_cast<void**>(this_ptr + 0x1d8) = this_ptr + 0x1d0;
}

// @fnv 0x0078ada0
bool TESLoadScreen::IsRefFlag400Set()
{
    return (((TESObjectREFR*)this)->GetFlags() & 0x400) != 0;
}

// @fnv 0x0078afa0
// src: COMMUNITY 0x0078afa0
void LoadingMenu::ShowPlayerTiles(bool abShow)
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
// Iterates the tile list from lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b650
// src: COMMUNITY 0x0078b650
void LoadingMenu::UpdateStatsTilesVisibilities(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<StrH*>(&m_kFirstTileList);
    while (pos)
    {
        reinterpret_cast<ListH*>(&m_kFirstTileList)->GetNext(pos)->Set(0xfa3, b);
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
} // namespace fnv_0078b6a0

// Iterates the tile list starting at lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b6a0
// src: COMMUNITY 0x0078b6a0
void LoadingMenu::UpdateObjectiveTilesVisibilities(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<fnv_0078b6a0::StrH*>(&m_kSecondTileList);
    while (pos)
    {
        reinterpret_cast<fnv_0078b6a0::ListH*>(&m_kSecondTileList)->GetNext(pos)->Set(0xfa3, b);
    }
}

struct TL
{
    void* GetHead() const;
    Tile*& GetNext(void*&);
};
// Sets property 0xfa3 to b on every tile in both lists l1 and l2 and on t1 and t2.
// @fnv 0x0078b6f0
// src: COMMUNITY 0x0078b6f0
void LoadingMenu::UpdateTipTilesVisibilities(bool b)
{
    void* pos = reinterpret_cast<TL*>(&m_kFourthTileList)->GetHead();
    while (pos)
    {
        Tile* pTile = reinterpret_cast<TL*>(&m_kFourthTileList)->GetNext(pos);
        if (pTile)
            pTile->Set(0xfa3, b);
    }
    pos = reinterpret_cast<TL*>(&m_kFifthTileList)->GetHead();
    while (pos)
    {
        Tile* pTile = reinterpret_cast<TL*>(&m_kFifthTileList)->GetNext(pos);
        if (pTile)
            pTile->Set(0xfa3, b);
    }
    m_pTiles[36]->Set(0xfa3, b);
    m_pTiles[37]->Set(0xfa3, b);
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
} // namespace fnv_0078b7c0

// Iterates the tile list starting at lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b7c0
// src: COMMUNITY 0x0078b7c0
void LoadingMenu::UpdateXPProgressTilesVisibilities(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<fnv_0078b7c0::StrH*>(&m_kThirdTileList);
    while (pos)
    {
        reinterpret_cast<fnv_0078b7c0::ListH*>(&m_kThirdTileList)->GetNext(pos)->Set(0xfa3, b);
    }
}

struct LoadScreenTypeData
{
    void Endian();
    int DataType;
    char m_acFirstString[40];
    char m_acSecondString[40];
    unsigned int m_uiTrailingValue;
};
typedef char _sizecheck_LoadScreenType_Data[sizeof(LoadScreenTypeData) == 88 ? 1 : -1];
class LoadingMenuDiagnostics
{
  public:
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};

float __cdecl BSMAX_00404010(float, float);
float __cdecl BSMIN(float, float);
float __cdecl InterfaceManager_GetScreenHeight(void);
float __cdecl InterfaceManager_GetScreenSafeX(void);
float __cdecl InterfaceManager_GetScreenSafeY(void);

extern const double DAT_0106e7f8;

// @fnv 0x0078b9b0
// src: EXE 0x0078b9b0
void LoadingMenu::CalcLoadScreenTypeTextWindowVerts(void* apData)
{
    if (apData == 0)
    {
        LoadingMenuDiagnostics::PrintDebugMessage(
            (BGSLoadGameBuffer*)"WARNING: LoadingMenu::CalcLoadScreenTypeTextWindowVerts() received a NULL apData.");
        return;
    }

    float fSafeWidth;
    float fConvertedYPos;
    float fSafeHeight;
    float fConvertedHeight;
    float fCurrentScreenWidth = InterfaceManager::UpdateInterfaceState();
    float fCurrentScreenHeight = InterfaceManager_GetScreenHeight();
    fSafeWidth = fCurrentScreenWidth - InterfaceManager_GetScreenSafeX();
    fSafeHeight = fCurrentScreenHeight - InterfaceManager_GetScreenSafeY();

    float fConvertedWidth;
    float fConvertedXPos = (double)((unsigned int*)apData)[1] / 1280.0 * fCurrentScreenWidth;
    fConvertedYPos = (double)((unsigned int*)apData)[2] / DAT_0106e7f8 * fCurrentScreenHeight;
    fConvertedWidth = (double)((unsigned int*)apData)[3] / 1280.0 * fCurrentScreenWidth;
    fConvertedHeight = (double)((unsigned int*)apData)[4] / 1280.0 * fCurrentScreenHeight;

    if (((unsigned int*)apData)[0] != 0)
    {
        *(int*)((char*)this + 0xc0) = (int)BSMAX_00404010(fConvertedXPos, InterfaceManager_GetScreenSafeX());
        *(int*)((char*)this + 0xc4) = (int)BSMAX_00404010(fConvertedYPos, InterfaceManager_GetScreenSafeY());
        *(int*)((char*)this + 0xc8) =
            (int)BSMIN((float)*(int*)((char*)this + 0xc0) + fConvertedWidth, fSafeWidth);
        *(int*)((char*)this + 0xcc) =
            (int)BSMIN((float)*(int*)((char*)this + 0xc4) + fConvertedHeight, fSafeHeight);
    }
}

// @fnv 0x0078bb40
// src: XBOX_PDB 0x0078bb40
void LoadingMenu::InitPlayerTileSettings()
{
    UpdatePlayerTileSettings((int)m_pCurrentLoadScreen);
}

// @fnv 0x0078bc60
// src: COMMUNITY 0x0078bc60
int __fastcall TESLoadScreen_GetTypeData(int apObject)
{
    return *(int*)(apObject + 0x34) + 0x18;
}

typedef char _sizecheck_BSCriticalSection[sizeof(RecursiveLock) == 40 ? 1 : -1];

class TaskThreadManager
{
  public:
    static TaskThreadManager* __cdecl GetSingleton();
};

NiRenderer* __cdecl NiXenonRenderer_GetRenderer(void);
RecursiveLock* __cdecl Tile_GetTileUpdateAllCriticalSectionLock(void);
bool __fastcall BSCriticalSection_TryLock(RecursiveLock*);
int __fastcall NiCriticalSection_TryEnterCriticalSection(RecursiveLock*);
bool __cdecl BSSpinLockGlobalTryLock(void);
void __cdecl BSTexturePalette_Unlock(void);

struct MTRenderingSystem_Helper
{
    void MTRenderingSystem_StartThreads();
    void MTRenderingSystem_SetThreadStage(int, int);
    void MTRenderingSystem_WaitOnThreadStage(int, int);
    void MTRenderingSystem_WaitForThreads();
};

struct InterfaceManager_Helper
{
    void RenderMenu(int, int);
};

extern RecursiveLock DAT_011f4380;
extern bool DAT_011a0295;
extern bool DAT_011c70f8;

// @fnv 0x0078d080
// src: XBOX_PDB 0x0078d080
void __cdecl LoadingMenu_ShowChanges(void)
{
    NiXenonRenderer_GetRenderer()->StartScene();
    RecursiveLock* pTileCritSect = Tile_GetTileUpdateAllCriticalSectionLock();
    if (!BSCriticalSection_TryLock(pTileCritSect))
    {
        NiXenonRenderer_GetRenderer()->FinishScene();
        return;
    }

    if (!NiCriticalSection_TryEnterCriticalSection(&DAT_011f4380))
    {
        pTileCritSect->Leave();
        NiXenonRenderer_GetRenderer()->FinishScene();
        return;
    }

    if (DAT_011a0295 && !BSSpinLockGlobalTryLock())
    {
        DAT_011f4380.Leave();
        pTileCritSect->Leave();
        NiXenonRenderer_GetRenderer()->FinishScene();
        return;
    }

    if (DAT_011a0295)
    {
        Tile::UpdateAll(true);
        BSTexturePalette_Unlock();
    }

    reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->MTRenderingSystem_StartThreads();
    for (int i = 1; i < 23; ++i)
    {
        reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->MTRenderingSystem_SetThreadStage(0, i);
        reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->MTRenderingSystem_WaitOnThreadStage(1, i);
    }

    DAT_011c70f8 = true;
    reinterpret_cast<InterfaceManager_Helper*>(InterfaceManager_GetSingleton())->RenderMenu(0, 0);
    DAT_011c70f8 = false;

    reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->MTRenderingSystem_WaitForThreads();
    NiXenonRenderer_GetRenderer()->FinishScene();
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

extern PlayerCharacter* pPlayer;
float __cdecl GetLevelProgress();
// Stores the player's FindAudioEntry result, GetLevelProgress result and level into g_011da168, DAT_011da16c and DAT_011da170.
// @fnv 0x0078d670
// src: XBOX_PDB 0x0078d670
void LoadingMenu_FillDisplayData()
{
    *(int*)&g_011da168 = pPlayer->FindAudioEntry();
    DAT_011da16c = GetLevelProgress();
    DAT_011da170 = pPlayer->GetLevel();
}

class NavMeshInfo;
namespace fnv_0078d880 {
extern int DAT_0107410c;

// @fnv 0x0078d880
// src: COMMUNITY 0x0078d880
void* __fastcall BSSimpleArray_TESLoadScreen_1024_BSSimpleArray_TESLoadScreen_1024(void* pThis)
{
    *reinterpret_cast<int**>(pThis) = &DAT_0107410c;
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(pThis)->BSSimpleArray_float_1024_InitialSetup(0, false);
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
// src: GUESS 0x0078d8b0 (confidence: low)
void __fastcall LoadingMenu_UpdateState_0078d8b0(GlobalObject_00869f00* pThis)
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
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
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
    void NiAVObject_SetScale(float);
    void SetLocalRotation(float, float, float, float);
    void SetAppCulled(bool);
};

class NiNodeV : public NiAVObjectV
{
  public:
    NiAVObjectV* NiNode_GetAtChecked(unsigned int);
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

struct FUN_00424940_shell
{
    char InterfaceManager_GetMenuMode();
};
struct FUN_0041fd00_shell
{
    void FUN_0041fd00(int);
};

struct TESGlobalValueReader
{
    float GetValue();
};
struct OSGlobalsH
{
    bool Main_GameReset();
};

struct FUN_00575d10_shell
{
    bool TESObjectREFR_GetInterior();
};
extern const double DAT_010704f0;
extern const double DAT_010704e8;
extern const double gModifierZero;
extern const float DAT_01073f20;
extern int DAT_011a9bd0;
extern bool DAT_011a0295;
extern TESGlobalValueReader* DAT_011c3f3c;
extern BGSMoviePlayer* DAT_0126fac4;
extern LoadingFloatSetting originalRuntimeFloatSetting1218;
struct PC7d;
extern PC7d* g_thePlayer;

struct NiRendererH
{
    void StartScene();
    void FinishScene();
};
NiRendererV* __cdecl NiXenonRenderer_GetRenderer();

unsigned int __cdecl NiShadeProperty_GetType();
void __cdecl _FNV_Warning(int, const char*, ...);

} // namespace fnv_007890e0

// @fnv 0x007890e0
void LoadingMenu::InitLoadingMenu(TESForm* apLocation)
{
    Menu* psleep;

    *(unsigned int*)((char*)this + 0x1e0) = 0;
    if (((Tile*)*(Tile**)((char*)this + 4))->GetFloat(0xfa7) == fnv_007890e0::DAT_010704f0 ||
        ((Tile*)*(Tile**)((char*)this + 4))->GetFloat(0xfa7) == fnv_007890e0::DAT_010704e8)
    {
        (*(Tile**)((char*)this + 4))->Set(0xfad, Tile::GetInterfaceScale(), true);
    }

    if (((fnv_007890e0::FUN_00424940_shell*)InterfaceManager_GetSingleton())->InterfaceManager_GetMenuMode() != 3)
        ((fnv_007890e0::FUN_0041fd00_shell*)InterfaceManager_GetSingleton())->FUN_0041fd00(2);

    HUDMainMenu::UpdateVisibilityState(5);
    HUDMainMenu::UpdateTargetReference(0, false, false);
    InterfaceH_loadingmenu::SetLookAtReference(0);

    if (fnv_007890e0::g_thePlayer && !fnv_007890e0::DAT_0126fac4->IsPlaying())
        fnv_007890e0::DAT_0126fac4->RequestInterruption();

    psleep = Tile::FindMenuById(0x3f4);
    if (psleep)
        delete psleep;

    *(TESForm**)((char*)this + 0x1e8) = apLocation;

    if (DAT_011a0294 || fnv_007890e0::DAT_011c3f3c->GetValue() != fnv_007890e0::gModifierZero)
    {
        this->SetTileVisible(0, false);
    }
    else if (DAT_011d8907 || ((fnv_007890e0::OSGlobalsH*)g_osGlobals)->Main_GameReset())
    {
        this->ShowPlayerTiles(false);
        ((fnv_007890e0::NiRendererH*)fnv_007890e0::NiXenonRenderer_GetRenderer())->StartScene();
        this->ResetLoadingPinwheelAnimation();
        ((fnv_007890e0::NiRendererH*)fnv_007890e0::NiXenonRenderer_GetRenderer())->FinishScene();
    }
    else
    {
        if (*(TESForm**)((char*)this + 0x1e8) && !g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        {
            switch ((*(TESForm**)((char*)this + 0x1e8))->GetFormType())
            {
            case 0x39:
                this
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
                this
                    ->SetFloatFlag(9, ((fnv_007890e0::FUN_00575d10_shell*)*(TESForm**)((char*)this + 0x1e8))->TESObjectREFR_GetInterior());
                break;
            }
        }
        if (this->GetFloat(9))
        {
            this->SetTileVisible(0xb, false);
            this->SetFloatFlag(4, false);
            *(unsigned int*)((char*)this + 0x1e4) = gm_GetTickCount();
            fnv_007890e0::DAT_011a0295 = true;
        }
        else
        {
            this->ShowPlayerTiles(true);
            this->RefreshLoadingScreen();
        }
        ((fnv_007890e0::NiRendererH*)fnv_007890e0::NiXenonRenderer_GetRenderer())->StartScene();
        this->ResetLoadingPinwheelAnimation();
        ((fnv_007890e0::NiRendererH*)fnv_007890e0::NiXenonRenderer_GetRenderer())->FinishScene();
    }

    fnv_007890e0::NiXenonRenderer_GetRenderer()->SetBackgroundColor(&fnv_007890e0::DAT_011a9bd0);

    if (reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x54)))->GetModel_0056c7f0()))
    {
        reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x54)))->GetModel_0056c7f0())
            ->NiAVObject_SetScale(fnv_007890e0::originalRuntimeFloatSetting1218.FUN_00450410());
        (*(Tile**)((char*)this + 0x54))->Set(0x1004, ((SettingT_GameSettingCollection_*)&fnv_007890e0::originalRuntimeFloatSetting1218)->Float()->f, true);
        reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x54)))->GetModel_0056c7f0())->SetLocalRotation(1.5707964f, 1.0f, 0.0f, 0.0f);
    }
    else
    {
        fnv_007890e0::_FNV_Warning(0x12, "WARNING:  Loading Menu wheel does not have a model.");
    }

    if (!this->GetFloat(9))
    {
        fnv_007890e0::NiUpdateDataH data;
        fnv_007890e0::NiAVObjectV* pav;
        fnv_007890e0::NiNodeV* pnode;
        Tile3D* p3dtile;

        pav = reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x28)))->GetModel_0056c7f0())->GetObjectByName(NiFixedString("Slide01"));
        pnode = pav->IsSceneNode();
        if (pnode)
        {
            *(NiProperty**)((char*)this + 0x1ec) = pnode->NiNode_GetAtChecked(0)->GetProperty(fnv_007890e0::NiShadeProperty_GetType());
            pnode = (fnv_007890e0::NiNodeV*)reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x28)))->GetModel_0056c7f0())
                        ->GetObjectByName(NiFixedString("Slide02"));
            *(NiProperty**)((char*)this + 0x1f0) = pnode->NiNode_GetAtChecked(0)->GetProperty(fnv_007890e0::NiShadeProperty_GetType());
        }
        else
        {
            *(NiProperty**)((char*)this + 0x1ec) = pav->GetProperty(fnv_007890e0::NiShadeProperty_GetType());
            pav = reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x28)))->GetModel_0056c7f0())->GetObjectByName(NiFixedString("Slide02"));
            *(NiProperty**)((char*)this + 0x1f0) = pav->GetProperty(fnv_007890e0::NiShadeProperty_GetType());
        }

        this->UpdateLoadingScreens();
        if (!DAT_011a0294)
        {
            this->UpdateLoadingScreenText(false);
            this->LoadingMenu_AdvanceScreen();
            this->ApplyLoadingScreenTexture(false);
            this->UpdateLoadingScreenTip();
        }

        reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x28)))->GetModel_0056c7f0())->NiAVObject_SetScale(fnv_007890e0::DAT_01073f20);
        reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x28)))->GetModel_0056c7f0())->SetLocalRotation(1.5707964f, 1.0f, 0.0f, 0.0f);
        (*(Tile**)((char*)this + 0x28))
            ->Set(0x1004, InterfaceH_loadingmenu::GetFourthInterfaceFloat() / InterfaceH_loadingmenu::GetThirdInterfaceFloat(), true);

        p3dtile = (Tile3D*)(*(Tile**)((char*)this + 0x28));
        p3dtile->Tile3D_PlaySequence("Left");
        data.FUN_0043d410(0.0f, true, false);
        reinterpret_cast<fnv_007890e0::NiNodeV*>(p3dtile->GetModel_0056c7f0())->Update(data);
        this->FadeIn();
        *(unsigned int*)((char*)this + 0x1e4) = 0;
    }

    LoadingMenu::UpdateLoadingMenuState();

    if ((DAT_011a0294 || !apLocation) && BSAudio::GetSingleton()->IsPatrolling() &&
        !*((SettingT_GameSettingCollection_*)&g_011ded5c)->String())
    {
        if (!BSAudio::GetSingleton()->TESRegionData_GetPriority())
        {
            BSAudio::GetSingleton()->SetUseMultipleThreads(true);
            this->SetFloatFlag(2, true);
        }
    }
    else if (!DAT_011a0294 && BSAudio::GetSingleton()->IsPatrolling())
    {
        if (!BSAudio::GetSingleton()->TESRegionData_GetPriority())
        {
            BSAudio::GetSingleton()->SetUseMultipleThreads(true);
            this->SetFloatFlag(2, true);
        }
        BSAudio::GetSingleton()->SetAudioProperty(2, 1000, 6000);
    }

    *(unsigned int*)((char*)this + 0x5b4) = 0;
    reinterpret_cast<fnv_007890e0::NiNodeV*>(((Tile3D*)(*(Tile**)((char*)this + 0x28)))->GetModel_0056c7f0())->SetAppCulled(true);
}

struct TileList
{
    void* GetHeadPos() const;
    Tile*& GetNext(void*& pos);
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
// Applies the loading tile settings (justify, alpha, visibility, colour) to every tile in two tile lists, computing X/Y positions from this menu's bounds.
// @fnv 0x0078c770
void LoadingMenu::ApplySettingsToTiles(LoadingTileSettings* apSettings)
{
    void* pos = ((::TileList*)&m_kFourthTileList)->GetHeadPos();
    while (pos)
    {
        Tile* pTile = (Tile*)((::TileList*)&m_kFourthTileList)->GetNext(pos);
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
            pTile->Set(0xfba, pTile->GetValue((unsigned int)0xfb1), true);
            pTile->Set(0xfa2, (float)*(int*)((char*)this + 0xc4), true);
            pTile->Set(0xfb0, *(int*)((char*)this + 0xcc) - pTile->GetValue((unsigned int)0xfa2), true);
            pTile->Set(0xfbb, pTile->GetValue((unsigned int)0xfb0), true);
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
    pos = ((::TileList*)&m_kFifthTileList)->GetHeadPos();
    while (pos)
    {
        Tile* pTile = (Tile*)((::TileList*)&m_kFifthTileList)->GetNext(pos);
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
            pTile->Set(0xfba, pTile->GetValue((unsigned int)0xfb1), true);
            pTile->Set(0xfa2, (float)*(int*)((char*)this + 0xc4), true);
            pTile->Set(0xfb0, *(int*)((char*)this + 0xcc) - pTile->GetValue((unsigned int)0xfa2), true);
            pTile->Set(0xfbb, pTile->GetValue((unsigned int)0xfb0), true);
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
// src: COMMUNITY 0x00788a90
void FalloutAudio_SetNewGameMusic(unsigned char value)
{
    DAT_011dcfb2 = value;
}

extern unsigned char DAT_011dcfb2;

// @fnv 0x00788aa0
// src: COMMUNITY 0x00788aa0
unsigned char FalloutAudio_GetNewGameMusic()
{
    return DAT_011dcfb2;
}

// @fnv 0x00788f20
// src: COMMUNITY 0x00788f20
int LoadingMenu_GetClassStatic()
{
    return 0x3ef;
}

class TES;
class TESSound;
#include "../../../../include/MEDIATYPE.h"
extern bool DAT_011a0295;
extern bool DAT_011da0c9;
extern float DAT_011dd300;
extern float DAT_011dd338;
extern double DAT_01073fb8;
extern double DAT_0101db88;
extern const double runtimeInitializationDouble5;
extern double _gModifierZero;
extern TES* g_TES;
extern SettingT_GameSettingCollection_ g_011de740;
extern SettingT_GameSettingCollection_ g_011da0f0;
void* memset(void*, int, unsigned int);
int sprintf_s(char*, unsigned int, const char*, ...);
unsigned int BSStringLength(const char*);
void BSClamp_float(float&, float, float);
void FalloutAudio_SetMainMenuMusic(bool);
void FalloutAudioMedia_MediaMenuUnPause();
int Warning(const char*, ...);
TESForm** __fastcall _ref_006815c0(void*);
void __fastcall LoadingMenu_AdvanceScreen(char*);
class TESGlobalValueReader
{
  public:
    float GetValue();
};
extern TESGlobalValueReader* DAT_011c3f3c;

extern BGSMoviePlayer* DAT_0126fac4;
struct FalloutAudioMedia
{
    static void Update();
    static void PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
};
struct NN_00605d70
{
    void Update(const NiUpdateData&);
};
NiControllerSequence* __fastcall GetLoadingTileSequence(Tile3D* tile);

struct BSSimpleListTESRaceSize
{
    int GetSize();
};

// @fnv 0x00789820
// src: XBOX_PDB 0x00789820
void LoadingMenu::Update_00789820()
{

    DAT_011a0295 = true;
    if (this->m_iStateFlags & 1)
    {
        this->m_iStateFlags &= ~1;
        this
            ->m_pTiles[36]
            ->Set(0xfa2, ((Tile*)this->m_pTiles[34])->GetFloat(0xfa2) - runtimeInitializationDouble5,
                  true);
        this
            ->m_pTiles[36]
            ->Set(0xfb0, ((Tile*)this->m_pTiles[34])->GetFloat(0xfb0) + DAT_0101db88, true);
    }
    if (this->m_iStateFlags & 2)
    {
        this->m_iStateFlags &= ~2;
        this
            ->m_pTiles[37]
            ->Set(0xfa2, ((Tile*)this->m_pTiles[35])->GetFloat(0xfa2) - runtimeInitializationDouble5,
                  true);
        this
            ->m_pTiles[37]
            ->Set(0xfb0, ((Tile*)this->m_pTiles[35])->GetFloat(0xfb0) + DAT_0101db88, true);
    }

    unsigned int CurrTime = gm_GetTickCount();
    if (!this->GetFloat(4))
    {
        unsigned int CrossTime = CurrTime - this->m_uiFirstStateValue;
        float fTileAlpha = CrossTime * DAT_01073fb8;
        if (!this->m_uiFirstStateValue)
            fTileAlpha = 1.0f;
        BSClamp_float(fTileAlpha, 0.0f, 1.0f);
        if (this->m_uiSecondStateValue % 2 == 0)
            fTileAlpha = 1.0f - fTileAlpha;
        float fSlide01Alpha = fTileAlpha;
        BSClamp_float(fSlide01Alpha, 0.0f, 1.0f);
        if (this->m_pTiles[32])
            this->m_pTiles[32]->Set(0xfa9, (int)(fSlide01Alpha * 255.0));
        float fSlide02Alpha = 1.0f - fTileAlpha;
        BSClamp_float(fSlide02Alpha, 0.0f, 1.0f);
        if (this->m_pTiles[33])
            this->m_pTiles[33]->Set(0xfa9, (int)(fSlide02Alpha * 255.0));
        this->UpdateLoadScreen(m_pCurrentLoadScreen, fSlide01Alpha, 1);
        this
            ->UpdateLoadScreen((TESLoadScreen*)*_ref_006815c0(this->m_pkLoadScreenList), fSlide02Alpha,
                               2);
        DAT_011a0295 = true;
    }

    if (CurrTime - this->m_uiFirstStateValue < 3000)
    {
        if (DAT_011a0294 && !this->GetFloat(0) && !DAT_0126fac4->IsPlaying() &&
            BSStringLength(((SettingT_GameSettingCollection_*)&g_011de740)->String()) && !DAT_011da0c9)
        {
            char cfilename[64];
            memset(cfilename, 0, 64);
            sprintf_s(cfilename, 64, "Data\\Music\\Special\\%s.mp3",
                      ((SettingT_GameSettingCollection_*)&g_011da0f0)->String());
            FalloutAudio_SetMainMenuMusic(true);
            FalloutAudioMedia::PlayMedia(MEDIATYPE_MEDIA_MAINMENU, cfilename, 0, true, true, 0.0f, 0);
            FalloutAudioMedia_MediaMenuUnPause();
            DAT_011dd300 = 0.6f;
            DAT_011dd338 = 0.6f;
            this->m_pTiles[0]->GetModel_0056c7f0()->SetAppCulled(true);
            this->m_pTiles[32]->Set(0xfa9, 0.0f, true);
            this->m_pTiles[33]->Set(0xfa9, 255.0f, true);
            DAT_0126fac4->StartPlayback(((SettingT_GameSettingCollection_*)&g_011de740)->String(), 0, -1, 0, 0, 0.0f);
            DAT_011da0c9 = true;
            this->m_pTiles[11]->Set(0xfa3, 1);
            DAT_011a0295 = true;
        }
        else if (DAT_011a0294 && !this->GetFloat(0) && !DAT_0126fac4->IsPlaying() && !DAT_011da0c9 &&
                 !BSStringLength(((SettingT_GameSettingCollection_*)&g_011de740)->String()))
        {
            char cfilename[64];
            memset(cfilename, 0, 64);
            sprintf_s(cfilename, 64, "Data\\Music\\Special\\%s.mp3",
                      ((SettingT_GameSettingCollection_*)&g_011da0f0)->String());
            FalloutAudio_SetMainMenuMusic(true);
            FalloutAudioMedia::PlayMedia(MEDIATYPE_MEDIA_MAINMENU, cfilename, 0, true, true, 0.0f, 0);
            FalloutAudioMedia_MediaMenuUnPause();
            DAT_011dd300 = 0.6f;
            DAT_011dd338 = 0.6f;
            DAT_011da0c9 = true;
        }
    }
    else if (!this->m_uiLoadScreenIndex)
    {
        if (DAT_011a0294)
        {
            while (!g_TES)
                BSSleep(5);
            this->ApplyLoadingScreenTexture((void*)TileShaderState);
        }
        if (!LoadScreenData && this->GetFloat(4))
            this->FadeIn();
        else
            LoadScreenData = gm_GetTickCount();
        this->m_uiLoadScreenIndex = LoadScreenData;
    }
    else if (this->GetFloat(4))
    {
        this->FadeIn();
    }
    else if (!this->GetFloat(9) && gm_GetTickCount() >= this->m_uiLoadScreenIndex)
    {
        Tile3D* p3dtile = (Tile3D*)this->m_pTiles[0];
        if (p3dtile->Tile3D_IsPlaying())
        {
            if (!DAT_011a0294 && DAT_011c3f3c->GetValue() == _gModifierZero && !StartMenu_MainMenuIsActive() &&
                (!this->GetFloat(3) ||
                 ((Tile*)this->m_pTiles[34])->ContainsTrait(0xfa3)))
                this->UpdateLoadingScreenText(0);
            ::LoadingMenu_AdvanceScreen((char*)this);
            this->ApplyLoadingScreenTexture(0);
            ((NiControllerManager*)((TESTopicInfo*)p3dtile)->GetConversationData())
                ->StopSequence(GetLoadingTileSequence(p3dtile), 0.0f);
            this->UpdateLoadingScreenTip();
            if (DAT_011a0294 && this->m_pkLoadScreenList == &this->m_kLoadScreenItems)
                this->SetFloatFlag(0, true);
        }
        else if (!DAT_011a0294 || !this->GetFloat(0))
        {
            if (!this->GetFloat(3) && !this->GetFloat(8))
            {
                this->m_uiLoadScreenIndex = gm_GetTickCount();
                this->ToggleFlagBit(1);
                if (p3dtile->Tile3D_PlaySequence(this->GetFloat(1) ? "Forward" : "Backward"))
                {
                    this->m_uiFirstStateValue = gm_GetTickCount();
                    this->m_uiSecondStateValue++;
                    if (this->GetFloat(7))
                    {
                        this
                            ->SetFloatFlag(
                                8, ((BSSimpleListTESRaceSize*)&this->m_kLoadScreenItems)->GetSize() == 1);
                        this->SetFloatFlag(7, false);
                    }
                    NiUpdateData data(0.0f, true, false);
                    ((NN_00605d70*)static_cast<Tile*>(p3dtile)->GetModel_0056c7f0())->Update(data);
                }
                else
                {
                    Warning("MENUS: (Loading Menu) Unable to play sequence %s",
                            this->GetFloat(1) ? "Forward" : "Backward");
                }
            }
        }
    }

    if (((Tile*)this->m_pTiles[11])->IsVisible())
        this->ResetLoadingPinwheelAnimation();
    BSAudio::GetSingleton()->Update(true);
    FalloutAudioMedia::Update();
}

extern unsigned char DAT_011cabb8;

// @fnv 0x0078a930
// src: COMMUNITY 0x0078a930
unsigned char __cdecl GetIsLocationSpecificLoadScreensOnly()
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
} // namespace fnv_0078b100

// When aiState is 1, walks the tile list at this+0xd0, sets flag 0xfa3 to 1 on tiles where it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b100
// src: COMMUNITY 0x0078b100
void LoadingMenu::UpdateStatsTilesAlphas(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(fnv_0078b100::Flt*)((char*)this + 0xd0);
        while (pos)
        {
            Tile* pTile = ((fnv_0078b100::TL*)((char*)this + 0xd0))->GetNext(pos);
            if (pTile)
            {
                if (((Tile*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}

namespace fnv_0078b190 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*& pos);
};
} // namespace fnv_0078b190

// When aiState is 1, walks the tile list at this+0xdc, sets tile flag 0xfa3 to 1 if it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b190
void LoadingMenu::UpdateTiles(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(fnv_0078b190::Flt*)((char*)this + 0xdc);
        while (pos)
        {
            Tile* pTile = ((fnv_0078b190::TL*)((char*)this + 0xdc))->GetNext(pos);
            if (pTile)
            {
                if (((Tile*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}

namespace fnv_0078b220 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*& pos);
};
} // namespace fnv_0078b220

// For slide 1 or 2, iterates the slide's tile list, marks each tile's 0xfa3 float as 1 if zero, and applies afAlpha to it and the slide's extra tile.
// @fnv 0x0078b220
void LoadingMenu::FadeSlideTiles(float afAlpha, int anSlide)
{
    void* piter;
    if (anSlide == 1)
    {
        piter = (void*)(unsigned int)*(fnv_0078b220::Flt*)&m_kFourthTileList;
        while (piter)
        {
            Tile* pTile = ((fnv_0078b220::TL*)&m_kFourthTileList)->GetNext(piter);
            if (pTile)
            {
                if (((Tile*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                this->SetTileAlpha(pTile, afAlpha);
            }
        }
        this->SetTileAlpha(m_pTiles[36], afAlpha);
    }
    if (anSlide == 2)
    {
        piter = (void*)(unsigned int)*(fnv_0078b220::Flt*)&m_kFifthTileList;
        while (piter)
        {
            Tile* pTile = ((fnv_0078b220::TL*)&m_kFifthTileList)->GetNext(piter);
            if (pTile)
            {
                if (((Tile*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                this->SetTileAlpha(pTile, afAlpha);
            }
        }
        this->SetTileAlpha(m_pTiles[37], afAlpha);
    }
}

namespace fnv_0078b360 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*& pos);
};
} // namespace fnv_0078b360

// When aiState is 1, walks the tile list at this+0xe8, sets flag 0xfa3 to 1 on tiles where it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b360
void LoadingMenu::UpdateLoadingTiles(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(fnv_0078b360::Flt*)((char*)this + 0xe8);
        while (pos)
        {
            Tile* pTile = ((fnv_0078b360::TL*)((char*)this + 0xe8))->GetNext(pos);
            if (pTile)
            {
                if (((Tile*)pTile)->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}

void LoadingMenu::CopyTileLayout()
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
            x9 = (int)((Tile*)m_pTiles[i])->GetFloat(0xfa1);
            y4 = (int)((Tile*)m_pTiles[i])->GetFloat(0xfa2);
            height = (int)((Tile*)m_pTiles[i])->GetFloat(0xfb0);
            width = (int)((Tile*)m_pTiles[i])->GetFloat(0xfb1);
            aZoom = (int)((Tile*)m_pTiles[i])->GetFloat(0xfb9);
            justify = (unsigned char)((Tile*)m_pTiles[i])->GetFloat(0xfb7);
        }
        ((TileLayout*)m_kTileLayouts)[i].m_iXPosition = x9;
        ((TileLayout*)m_kTileLayouts)[i].m_iYPosition = y4;
        ((TileLayout*)m_kTileLayouts)[i].nHeight = height;
        ((TileLayout*)m_kTileLayouts)[i].nWidth = width;
        ((TileLayout*)m_kTileLayouts)[i].m_eFont = (FONTS)aZoom;
        ((TileLayout*)m_kTileLayouts)[i].m_ucFontStyle = justify;
    }
}

void* __fastcall _ref_00726070(void* apNode);
unsigned int __fastcall TESMain_GetThread(void* apList);
void LoadingMenu_FillDisplayData();
extern float DAT_011da16c;
extern int DAT_011da170;
// @fnv 0x0078d6b0
void SaveLoadScreenData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int iElementIndex;
    void* pquest;
    bool bLocationSpecificOnly;
    LoadingMenu_FillDisplayData();
    pquest = *(void**)&g_011da168 ? (void*)TESMain_GetThread(*(void**)&g_011da168) : 0;
    iElementIndex = *(void**)&g_011da168 ? (unsigned int)_ref_00726070(*(void**)&g_011da168) : 0;
    apSaveGameBuffer->SerializeFormData(pquest, 0);
    apSaveGameBuffer->SaveData(&iElementIndex, 4, 0);
    apSaveGameBuffer->SaveData(&DAT_011da16c, 4, 0);
    apSaveGameBuffer->SaveData(&DAT_011da170, 4, 0);
    bLocationSpecificOnly = TESLoadScreenFlags::GetUseLocationSpecificScreensOnly();
    apSaveGameBuffer->SaveData(&bLocationSpecificOnly, 1, 0);
}

// @fnv 0x0078d280
// src: COMMUNITY 0x0078d280
void LoadingMenu_SetupForMainMenu(bool abCreate)
{
    if (BSSystemUtility::s_iUpdateEnabled)
        LoadingMenu::UpdateLoadingScreenThread();
    else if (abCreate)
        LoadingMenu::Create(0, false, false);
    if (BSSystemUtility::s_iUpdateEnabled)
        ((LoadingMenu*&)BSSystemUtility::s_iUpdateEnabled)->SetTileVisible(LoadingMenu::eBackground, false);
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

// If updates are enabled, param_1 is nonzero and the update object's f1e8 is zero, calls FUN_004581c0(true) and then FUN_00788ab0(param_1) on it.
// @fnv 0x00458180
void UpdateIfEnabled(int aiValue)
{
    if (BSSystemUtility::s_iUpdateEnabled != 0 && aiValue != 0 &&
        ((LoadingMenu*)BSSystemUtility::s_iUpdateEnabled)->pLocation == 0)
    {
        LoadingMenu_FlagReset(true);
        ((LoadingMenu*)BSSystemUtility::s_iUpdateEnabled)->Reset_00788ab0(aiValue);
    }
}

class NiRenderer;
namespace fnv_007887a0 {
NiRenderer* __cdecl NiXenonRenderer_GetRenderer();
void __cdecl FalloutAudio_SetMainMenuMusic(unsigned char);
void __cdecl FalloutAudio_SetNewGameMusic(unsigned char);
unsigned char __cdecl FalloutAudio_GetNewGameMusic();
void __fastcall LoadingMenu_FlushLoadScreenList(char*);
bool __cdecl BSTexturePalette_RemoveTexture(const void*);
extern char* _g_thePlayer;

struct Flt
{
    operator unsigned int();
};
struct S1740
{
    void BSAudio_UnMute(int);
};
struct SndX
{
    void Stop();
    void PausePlayback();
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

} // namespace fnv_007887a0

// @fnv 0x007887a0
LoadingMenu::~LoadingMenu()
{
    LoadingMenu::UpdateLoadingScreenThread();
    for (int i = 0; i < 4; i++)
    {
        if (*(fnv_007887a0::Flt*)&m_kLoadScreenTextures[i])
        {
            fnv_007887a0::BSTexturePalette_RemoveTexture((const void*)(unsigned int)*(fnv_007887a0::Flt*)&m_kLoadScreenTextures[i]);
            m_kLoadScreenTextures[i] = 0;
        }
    }
    DAT_011d8907 = false;
    ((fnv_007887a0::RendX*)fnv_007887a0::NiXenonRenderer_GetRenderer())->SetBackground(&m_kLoadingScreenColor);
    if (StartMenu_MainMenuIsActive() || (DAT_011a0294 && *((SettingT_GameSettingCollection_*)&g_011ded5c)->String()))
    {
        if (((PatrolActorPackageData*)BSAudio::GetSingleton())->IsPatrolling())
            fnv_007887a0::FalloutAudioMedia::FadeOutMedia(4000, (MEDIATYPE)0);
    }
    if (fnv_007887a0::FalloutAudio_GetNewGameMusic())
    {
        fnv_007887a0::FalloutAudio_SetNewGameMusic(0);
        fnv_007887a0::FalloutAudio_SetMainMenuMusic(0);
        fnv_007887a0::FalloutAudioMedia::FadeOutMedia(4000, (MEDIATYPE)0);
    }
    if (this->GetFloat(2) && BSAudio::GetSingleton()->TESRegionData_GetPriority())
        BSAudio::GetSingleton()->SetUseMultipleThreads(false);
    ((fnv_007887a0::S1740*)BSAudio::GetSingleton())->BSAudio_UnMute(1000);
    DAT_011a0294 = false;
    fnv_007887a0::LoadingMenu_FlushLoadScreenList((char*)this);
    ((fnv_007887a0::SndX*)&m_kSecondDate)->Stop();
    ((fnv_007887a0::SndX*)&m_kSecondDate)->PausePlayback();
    ((fnv_007887a0::SndX*)&m_kFirstDate)->PausePlayback();
    pLocation = 0;
    BSSystemUtility::s_iUpdateEnabled = 0;
    if (fnv_007887a0::_g_thePlayer && *(TESQuest**)(fnv_007887a0::_g_thePlayer + 0xe4c))
    {
        (*(TESQuest**)(fnv_007887a0::_g_thePlayer + 0xe4c))->SetEnabled(true);
        *(TESQuest**)(fnv_007887a0::_g_thePlayer + 0xe4c) = 0;
    }
}

extern "C" int __cdecl tolower(int);

extern SettingT_GameSettingCollection_ g_011d3000;
extern bool DAT_011a0295;
struct LoadScreenNode_r8a280
{
    TESLoadScreen** _ref_006815c0();
};

// Hashes the current candidate's full name, then sets the description and game-setting text on menu tiles and marks DAT_011a0295 true.
// @fnv 0x0078a280
void LoadingMenu::UpdateLoadingScreenText(bool abRefreshCurrent)
{
    unsigned int iplateno = 0;
    const char* pName = reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(*((LoadScreenNode_r8a280*)m_pkLoadScreenList)->_ref_006815c0()) + offsetof(TESLoadScreen, FullNameComponent) - offsetof(TESFullName, m_kName))->GetFullName();
    while (*pName)
        iplateno = (iplateno << 5) + iplateno + tolower(*pName++);
    iplateno %= 100000;
    if (m_uiSecondStateValue % 2 == 0)
    {
        m_iStateFlags |= 1;
        m_pTiles[34]->Set(
            0xfc4,
            ((TESDescription*)((char*)*((LoadScreenNode_r8a280*)m_pkLoadScreenList)->_ref_006815c0() + 0x24))
                ->GetDescription(0, (CHUNK_ID)0x43534544),
            true);
    }
    else
    {
        m_iStateFlags |= 2;
        m_pTiles[35]->Set(
            0xfc4,
            ((TESDescription*)((char*)*((LoadScreenNode_r8a280*)m_pkLoadScreenList)->_ref_006815c0() + 0x24))
                ->GetDescription(0, (CHUNK_ID)0x43534544),
            true);
    }
    m_pTiles[13]->Set(0xfc4, g_011d3000.String(), true);
    DAT_011a0295 = true;
}

#include "../../../../include/MEM_CONTEXT.h"
class NiSourceTexture;
class NiTexture;

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
extern TES* g_TES;
bool BSTexturePalette_RemoveTexture(const void* apTexture);
// Builds a texture path from the current candidate's full name, creates the texture image, stores it in a rotating slot, and assigns it to a tile shader property.
// @fnv 0x0078a3e0
void LoadingMenu::ApplyLoadingScreenTexture(TileShaderProperty* apProperty)
{
    AutoMemContext memContext(MEM_CONTEXT_MEM_CONTEXT_INTERFACE, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Menus\\LoadingMenu.cpp",
                              0x423);
    reinterpret_cast<LMString*>(&m_kLoadingScreenTip)->Sprintf("%s\\%s", "Textures", (*reinterpret_cast<LMNode*>(m_pkLoadScreenList)->GetItem())->fullName.GetFullName());
    NiPointer<NiSourceTexture> spTexture(0);
    g_TES->CreateTextureImage(*reinterpret_cast<LMString*>(&m_kLoadingScreenTip), spTexture, false, false);
    NiPointer<NiSourceTexture>* pSlot = reinterpret_cast<NiPointer<NiSourceTexture>*>(&m_kLoadScreenTextures[m_uiLoadingScreenNumber]);
    m_uiLoadingScreenNumber++;
    if (m_uiLoadingScreenNumber >= 4)
    {
        m_uiLoadingScreenNumber = 0;
    }
    if (*pSlot)
    {
        BSTexturePalette_RemoveTexture(*pSlot);
    }
    *pSlot = (NiSourceTexture*)spTexture;
    apProperty = (m_uiSecondStateValue % 2 == 0) ? m_pTiles[32]->GetShaderProperty() : m_pTiles[33]->GetShaderProperty();
    if (apProperty)
    {
        apProperty->SetTextureImage(reinterpret_cast<NiTexture*>((NiSourceTexture*)spTexture));
    }
}

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

namespace fnv_0078c210 {

struct TileListX
{
    void* GetHeadPos() const;
    Tile*& GetNext(void*& pos);
};

extern SettingT_GameSettingCollection_ g_011d2358_x;

int sprintf_s(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);

} // namespace fnv_0078c210

// Iterates the tile list, setting XP bar, text and box tile values from the loading settings and XP counters, then applies alpha to the XP box.
// @fnv 0x0078c210
void LoadingMenu::ApplyXPBarSettings(LoadingTileSettingsX* apSettings)
{
    void* pos = reinterpret_cast<fnv_0078c210::TileListX*>(&m_kThirdTileList)->GetHeadPos();
    while (pos)
    {
        Tile* pTile = reinterpret_cast<fnv_0078c210::TileListX*>(&m_kThirdTileList)->GetNext(pos);
        if (pTile)
        {
            if (pTile == m_pTiles[16])
            {
                pTile->Set(0xfa1, (float)m_kTileRectangle.left, true);
                pTile->Set(0xfb1, (float)(m_kTileRectangle.right - pTile->GetFloat(0xfa1)), true);
                pTile->Set(0xfba, pTile->GetFloat(0xfb1), true);
                pTile->Set(0xfa2, (float)m_kTileRectangle.top, true);
                pTile->Set(0xfb0, (float)(m_kTileRectangle.bottom - pTile->GetFloat(0xfa2)), true);
            }
            else
            {
                if (pTile == m_pTiles[15])
                {
                    float fStart = 0.0f;
                    switch (apSettings->uiJustify)
                    {
                    case 1:
                        fStart = 0.0f;
                        break;
                    case 2:
                        fStart = (m_kTileRectangle.right - m_kTileRectangle.left) / 2.0;
                        break;
                    case 4:
                        fStart = (float)(m_kTileRectangle.right - m_kTileRectangle.left);
                        break;
                    }
                    pTile->Set(0xfa1, fStart, true);
                    pTile->Set(0xfb7, apSettings->uiJustify);
                    pTile->SetInt(0xfb9, apSettings->m_iType);
                    pTile->Set(0xfb1, (float)(m_kTileRectangle.right - m_kTileRectangle.left), true);
                    pTile->Set(0xfba, pTile->GetFloat(0xfb1), true);
                    NiPoint3 kBounds = static_cast<LoadingFontDimensions*>(FontManager::Instance())->GetStringDimensions(
                        fnv_0078c210::g_011d2358_x.String(), apSettings->m_iType, pTile->GetFloat(0xfba), 0);
                    float m_fGlyphExtent = kBounds.y;
                    pTile->Set(0xfb0, m_fGlyphExtent, true);
                }
                else if (pTile == m_pTiles[10])
                {
                    char buffer[260];
                    fnv_0078c210::sprintf_s(buffer, 0x104, "%i", (unsigned int)pTile->GetFloat(0x1005));
                    float fNum = static_cast<LoadingFontDimensions*>(FontManager::Instance())
                                     ->GetStringDimensions(buffer, apSettings->m_iType, pTile->GetFloat(0xfba), 0)
                                     .x;
                    pTile->Set(0xfa1, fNum, true);
                    char acLevel2[260];
                    fnv_0078c210::sprintf_s(acLevel2, 0x104, "%i", (unsigned int)pTile->GetFloat(0x1006));
                    float fRightWidth = static_cast<LoadingFontDimensions*>(FontManager::Instance())
                                            ->GetStringDimensions(acLevel2, apSettings->m_iType,
                                                                  (float)(((m_kTileRectangle.right - m_kTileRectangle.left) - fNum) / 2.0), 0)
                                            .x;
                    pTile->Set(0xfb1, (float)((m_kTileRectangle.right - m_kTileRectangle.left) - fNum * 2.0f - fRightWidth), true);
                }
                pTile->Set(0xfb2, apSettings->fRed, true);
                pTile->Set(0xfb3, apSettings->fGreen, true);
                pTile->Set(0xfb4, apSettings->fBlue, true);
                pTile->SetInt(0xff5, -1);
                pTile->Tile_SetChangeFlag(8);
            }
        }
    }
    m_pTiles[16]->Set(0xffa, apSettings->fAlpha, true);
    static_cast<LoadingStatsTile*>(m_pTiles[16])->Tile_ApplyRotationOnChildren();
}

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

class LoadingMenuCreateTile : public Tile
{
  public:
    LoadingMenuCreateTile* ReadFile(const char*);
    LoadingMenu* GetMenu();
};
class LoadingMenuCreateProvider
{
  public:
    LoadingMenuCreateTile* CombatController_GetCombatState();
};
extern LoadingMenu* DAT_011da0c0;
extern LoadingMenuThread* DAT_011da0c4;
extern bool DAT_011da0c8;
LoadingMenuCreateTile* Tile_GetMenuByClass(int);
void FUN_00717740(int);
void FUN_0078d020();
void* __cdecl operator new(unsigned int);

// Looks up a loading-menu tile by id; if missing, loads loading_menu.xml, initialises the menu, creates the thread and returns the tile.
// @fnv 0x00788cc0
LoadingMenuCreateTile* __cdecl CreateLoadingMenuTile(TESForm* form, bool refresh, bool visible)
{
    LoadingMenuCreateTile* menu = Tile_GetMenuByClass(LoadingMenu_GetClassStatic());
    if (menu)
    {
        DAT_011da0c0->FUN_00458080(3, true);
        DAT_011da0c0->Reset_00788ab0(form);
        DAT_011da0c0->FUN_00458080(10, visible);
        return menu;
    }
    DAT_011da0c8 = true;
    LoadingMenuCreateTile* existing = reinterpret_cast<LoadingMenuCreateProvider*>(InterfaceManager_GetSingleton())
                                          ->CombatController_GetCombatState()
                                          ->ReadFile("Data\\Menus\\loading_menu.xml");
    DAT_011da0c8 = false;
    LoadingMenu* tile = existing->GetMenu();
    if (tile && tile->GetClass() == LoadingMenu_GetClassStatic())
    {
        FUN_00717740(0);
        tile->FUN_00a1dc70(reinterpret_cast<TileMenu*>(existing), false);
        DAT_011da0c0 = tile;
        DAT_011da0c0->CopyTileLayout();
        DAT_011da0c0->InitStatsTilesList();
        DAT_011da0c0->LoadingMenu_InitObjectiveTilesList();
        DAT_011da0c0->InitTipTilesList();
        DAT_011da0c0->InitXPProgressTilesList();
        DAT_011da0c0->UpdateObjectiveTilesVisibilities(false);
        DAT_011da0c0->UpdateTipTilesVisibilities(false);
        DAT_011da0c0->UpdateStatsTilesVisibilities(false);
        DAT_011da0c0->UpdateXPProgressTilesVisibilities(false);
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
extern SettingT_GameSettingCollection_ screenNames[];
extern DurationData* schedule;
int IsSpecial(const char*);
void NextScreen(int*, int);
// Clears and rebuilds the loading screen list from settings or gathered entries, adds a fallback entry, refreshes the menu and selects the first entry.
// @fnv 0x0078a5a0
void LoadingMenu::UpdateLoadingScreens()
{
    bool cleared = false;
    if (!((ScreenList*)&m_kLoadScreenItems)->Empty())
    {
        Clear();
        cleared = true;
    }
    SetFlag(5, StartMenu_MainMenuIsActive() || (unsigned char)schedule->Main_GameReset());
    if (DAT_011a0294 && !StartMenu_MainMenuIsActive())
    {
        int index = 0;
        if (IsSpecial(((SettingT_GameSettingCollection_*)&g_011de740)->String()))
            index = 3;
        for (; index < 5; NextScreen(&index, 0))
        {
            const char* folder = index == 4 ? "Main" : "Loading";
            reinterpret_cast<LMString*>(&m_kLoadingScreenTip)->Sprintf("Interface\\%s\\%s.dds", folder, screenNames[index].String());
            ScreenEntry* entry = new ScreenEntry;
            entry->path.Set(*reinterpret_cast<LMString*>(&m_kLoadingScreenTip));
            entry->Prepare();
            ((ScreenList*)&m_kLoadScreenItems)->Append(entry);
        }
    }
    else
    {
        ScreenArray screenArray;
        Gather(screenArray);
        Build(screenArray);
        if (pLocation && ((ScreenList*)&m_kLoadScreenItems)->Count() < *reinterpret_cast<unsigned int*>(((SettingT_GameSettingCollection_*)&g_011da138)->Int()) && !GetIsLocationSpecificLoadScreensOnly())
        {
            pLocation = 0;
            Gather(screenArray);
            Build(screenArray);
        }
    }
    if (((ScreenList*)&m_kLoadScreenItems)->Empty())
    {
        reinterpret_cast<LMString*>(&m_kLoadingScreenTip)->Sprintf("Interface\\Loading\\%s.dds", screenNames[0].String());
        ScreenEntry* fallback = new ScreenEntry;
        fallback->path.Set(*reinterpret_cast<LMString*>(&m_kLoadingScreenTip));
        fallback->Prepare();
        ((ScreenList*)&m_kLoadScreenItems)->Add(fallback);
    }
    if (cleared && !((Tile*)m_pTiles[0])->Tile3D_IsPlaying())
    {
        ApplyLoadingScreenTexture(0);
        Refresh();
    }
    SetFlag(7, true);
    m_pCurrentLoadScreen = (TESLoadScreen*)*((ScreenList*)&m_kLoadScreenItems)->Head();
    Reset();
    Select((ScreenEntry*)m_pCurrentLoadScreen, true);
}

template <class T> class NiTListItem;
template <class T> class LoadingStatsTileList
{
  public:
    NiTListItem<T>* FUN_00726070();
    T& GetPrev(NiTListItem<T>*& position);
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
// @fnv 0x0078bc80
void LoadingMenu::ApplySettings(LoadingStatsSettings* settings)
{
    static_cast<LoadingStatsTile*>(m_pTiles[31])->Set(0xfa1, float(m_kTileRectangle.left), true);
    static_cast<LoadingStatsTile*>(m_pTiles[31])->Set(0xfb1, float(m_kTileRectangle.right - m_kTileRectangle.left), true);
    static_cast<LoadingStatsTile*>(m_pTiles[31])->Set(0xfa2, float(m_kTileRectangle.top), true);
    static_cast<LoadingStatsTile*>(m_pTiles[31])->Set(0xfb0, float(m_kTileRectangle.bottom - m_kTileRectangle.top), true);
    static_cast<LoadingStatsTile*>(m_pTiles[17])->Set(0xfb9, settings->first.iVisible);
    static_cast<LoadingStatsTile*>(m_pTiles[17])->Set(0xfb2, settings->first.fRed, true);
    static_cast<LoadingStatsTile*>(m_pTiles[17])->Set(0xfb3, settings->first.fGreen, true);
    static_cast<LoadingStatsTile*>(m_pTiles[17])->Set(0xfb4, settings->first.fBlue, true);
    static_cast<LoadingStatsTile*>(m_pTiles[18])->Set(0xfb9, settings->second.iVisible);
    static_cast<LoadingStatsTile*>(m_pTiles[17])->Set(0xfb2, settings->second.fRed, true);
    static_cast<LoadingStatsTile*>(m_pTiles[17])->Set(0xfb3, settings->second.fGreen, true);
    static_cast<LoadingStatsTile*>(m_pTiles[17])->Set(0xfb4, settings->second.fBlue, true);
    float spacing = static_cast<LoadingStatsTile*>(m_pTiles[31])->FUN_00a011b0(0xfb0) / settings->second.count;
    float y = 0.0f;
    NiTListItem<Tile*>* secondPos = reinterpret_cast<LoadingStatsTileList<Tile*>*>(&static_cast<LoadingStatsTile*>(m_pTiles[17])->m_kChildTileList)->FUN_00726070();
    NiTListItem<Tile*>* pos2 = reinterpret_cast<LoadingStatsTileList<Tile*>*>(&static_cast<LoadingStatsTile*>(m_pTiles[18])->m_kChildTileList)->FUN_00726070();
    unsigned int uiIndex = 1;
    while (secondPos && pos2)
    {
        Tile* firstTile = reinterpret_cast<LoadingStatsTileList<Tile*>*>(&static_cast<LoadingStatsTile*>(m_pTiles[17])->m_kChildTileList)->GetPrev(secondPos);
        Tile* secondTile = reinterpret_cast<LoadingStatsTileList<Tile*>*>(&static_cast<LoadingStatsTile*>(m_pTiles[18])->m_kChildTileList)->GetPrev(pos2);
        if (firstTile && secondTile)
        {
            bool visible = true;
            if (uiIndex <= settings->second.count)
            {
                firstTile->Set(0xfa2, y, true);
                secondTile->Set(0xfa2, y, true);
                y += spacing;
                static_cast<LoadingStatsTile*>(firstTile)->Tile_SetChangeFlag(8);
                static_cast<LoadingStatsTile*>(secondTile)->Tile_SetChangeFlag(8);
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
    static_cast<LoadingStatsTile*>(m_pTiles[31])->Set(0xffa, settings->first.fAlpha, true);
    static_cast<LoadingStatsTile*>(m_pTiles[31])->Tile_ApplyRotationOnChildren();
}

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
struct WorkTileList
{
    void* Head();
    Tile*& Next(void*&);
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
// Measures the selected font, configures the primary and secondary tiles from options, sets the primary tile's alpha and finishes it.
// @fnv 0x0078bf80
void LoadingMenu::UpdateMenuTiles(Options* options)
{
    float fontHeight = FUN_005bd5b0()->fonts[options->font]->Height();
    void* position = reinterpret_cast<WorkTileList*>(&m_kSecondTileList)->Head();
    while (position)
    {
        Tile* tile = reinterpret_cast<WorkTileList*>(&m_kSecondTileList)->Next(position);
        if (tile)
        {
            if (tile == m_pTiles[27])
            {
                float offset = 0.0f;
                switch (options->align)
                {
                case 1:
                    offset = m_kTileRectangle.left;
                    break;
                case 2:
                    offset = m_kTileRectangle.left + (m_kTileRectangle.right - m_kTileRectangle.left) / 2.0;
                    break;
                case 4:
                    offset = m_kTileRectangle.right;
                    break;
                }
                tile->Set(0xfa1, offset, true);
                tile->Set(0xfb1, float(m_kTileRectangle.right - m_kTileRectangle.left), true);
                tile->Set(0xfba, tile->GetFloat(0xfb1), true);
                tile->Set(0xfa2, float(m_kTileRectangle.top), true);
                tile->SetInt(0xfb9, options->font);
                tile->Set(0xfb7, options->align);
                tile->Set(0xfb2, options->value1, true);
                tile->Set(0xfb3, options->value2, true);
                tile->Set(0xfb4, options->value3, true);
                tile->SetInt(0xff5, -1);
                tile->Tile_SetChangeFlag(8);
            }
            else if (tile == m_pTiles[3])
            {
                float width = float(m_kTileRectangle.right - m_kTileRectangle.left);
                Extent extent;
                FUN_005bd5b0()->Measure(&extent, ((SettingT_GameSettingCollection_*)&g_011d40f0)->String(),
                                        options->font, width, 0);
                float height = extent.y;
                tile->Set(0xfa2, height, true);
            }
        }
    }
    m_pTiles[27]->Set(0xffa, options->alpha, true);
    static_cast<LoadingStatsTile*>(m_pTiles[27])->Tile_ApplyRotationOnChildren();
}

// @fnv 0x0078ce10
void LoadingMenu::SetTileAlpha(void* pkTile, float fAlpha)
{
    if (!pkTile)
        return;
    if (pkTile == m_pTiles[33])
        return;
    fAlpha = BSMIN(fAlpha, 1.0f);
    fAlpha = BSMAX_00404010(fAlpha, 0.0f);
    if (((Tile*)pkTile)->GetType() == 0x388)
    {
        SetAlphaRecursive(((Tile*)pkTile)->GetModel_0056c7f0(), fAlpha);
        return;
    }
    if (pkTile == m_pTiles[12])
        fAlpha = 1.0f - fAlpha;
    static_cast<Tile*>(pkTile)->Set(0xfa9, fAlpha * 255.0, true);
    DAT_011a0295 = true;
    void* pPos = ((::TileList*)((char*)pkTile + 4))->GetHeadPos();
    while (pPos)
        SetTileAlpha(((::TileList*)((char*)pkTile + 4))->GetNext(pPos), fAlpha);
}

namespace fnv_0078bb60 {
extern bool DAT_011a0296;
struct PerkEntryX : BGSPerkEntry
{
    void* FUN_005f36f0();
    int TESLoadScreen_GetTypeData();
    int FUN_005a7130();
};
} // namespace fnv_0078bb60

// Applies the selected perk entry's settings to the loading menu tiles, XP bar, or menu tiles based on its type, then clears DAT_011a0296.
// @fnv 0x0078bb60
// src: XBOX_PDB 0x0078bb60
void LoadingMenu::UpdatePlayerTileSettings(BGSPerkEntry* entry)
{
    if (!FUN_00458110(6))
        return;
    if (entry == 0)
    {
        if (m_pkLoadScreenList)
            entry = reinterpret_cast<BGSPerkEntry*>(m_pkLoadScreenList->GetItem());
        else
            entry = reinterpret_cast<BGSPerkEntry*>(m_kLoadScreenItems.GetItem());
        if (entry == 0)
            return;
    }
    if (((fnv_0078bb60::PerkEntryX*)entry)->FUN_005f36f0())
    {
        int x = ((fnv_0078bb60::PerkEntryX*)entry)->TESLoadScreen_GetTypeData();
        CalcLoadScreenTypeTextWindowVerts(x);
        switch (((fnv_0078bb60::PerkEntryX*)entry)->FUN_005a7130())
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

    fnv_0078bb60::DAT_011a0296 = false;
}

namespace s78cc50 {

struct VATSCamera
{
    int FUN_0078cdf0();
};

extern VATSCamera* DAT_011dea0c;
extern bool DAT_011a0294;

unsigned int Cmd_GetSessionTime_Execute();

} // namespace s78cc50

// @fnv 0x0078cc50
// src: XBOX_PDB 0x0078cc50
inline void LoadingMenu::FadeIn()
{
    static float s_fDuration = reinterpret_cast<Tile*>(pMenu)->FUN_00a011b0(0xfc1) * 1000.0;

    if (LoadScreenData == 0)
    {
        if (s78cc50::DAT_011dea0c->FUN_0078cdf0() || s78cc50::DAT_011a0294)
        {
            reinterpret_cast<TileMenu*>(m_pTiles[12])->FUN_00a20610(s78cc50::DAT_011dea0c->FUN_0078cdf0());
            LoadScreenData = (unsigned int)(s78cc50::Cmd_GetSessionTime_Execute() + s_fDuration);
        }
        else
        {
            LoadScreenData = s78cc50::Cmd_GetSessionTime_Execute();
        }
    }
    if (s78cc50::Cmd_GetSessionTime_Execute() < LoadScreenData)
    {
        unsigned int uiRemaining = LoadScreenData - s78cc50::Cmd_GetSessionTime_Execute();
        SetTileAlpha(reinterpret_cast<Tile*>(pMenu), 1.0f - uiRemaining / s_fDuration);
    }
    else
    {
        SetTileAlpha(reinterpret_cast<Tile*>(pMenu), 1.0f);
        FUN_00458080(4, 0);
        m_uiSecondStateValue++;
    }
}

void* __fastcall _ref_00726070(void* apNode);
extern bool DAT_011a0294;
unsigned int gm_GetTickCount();

// If DAT_011a0294 is set, GetFloat(0) is zero, and p3dtile->FUN_0078a1f0() is false, advance m_pkLoadScreenList and apply the loading texture.
// @fnv 0x0078aa90
bool LoadingMenu::UpdateLoadingScreen()
{
    Tile* p3dtile = m_pTiles[0];
    if (DAT_011a0294 && !GetFloat(0) && !p3dtile->Tile3D_IsPlaying())
    {
        while (_ref_00726070(m_pkLoadScreenList))
            m_pkLoadScreenList = (BSSimpleList<TESLoadScreen*>*)_ref_00726070(m_pkLoadScreenList);
        this->ApplyLoadingScreenTexture(0);
        m_uiLoadScreenIndex = gm_GetTickCount();
        return true;
    }
    else
    {
        return false;
    }
}

// For a selected screen with bShow true, dispatches settings by screen type; otherwise passes bShow to all four methods.
// @fnv 0x0078b3f0
// src: XBOX_PDB 0x0078b3f0
void LoadingMenu::UpdatePlayerTileVisibilities(TESLoadScreen* pLoadScreen, bool bShow)
{
    if (!GetFloat(6))
    {
        return;
    }
    if (!pLoadScreen)
    {
        if (m_pkLoadScreenList)
        {
            pLoadScreen = (TESLoadScreen*)m_pkLoadScreenList->GetItem();
        }
        else
        {
            pLoadScreen = (TESLoadScreen*)m_kLoadScreenItems.GetItem();
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
            UpdateObjectiveTilesVisibilities(bShow);
            UpdateStatsTilesVisibilities(!bShow);
            UpdateTipTilesVisibilities(!bShow);
            UpdateXPProgressTilesVisibilities(!bShow);
            break;
        case 4:
            UpdateObjectiveTilesVisibilities(!bShow);
            UpdateStatsTilesVisibilities(bShow);
            UpdateTipTilesVisibilities(!bShow);
            UpdateXPProgressTilesVisibilities(!bShow);
            break;
        case 3:
            UpdateObjectiveTilesVisibilities(!bShow);
            UpdateStatsTilesVisibilities(!bShow);
            UpdateTipTilesVisibilities(bShow);
            UpdateXPProgressTilesVisibilities(!bShow);
            break;
        case 1:
            UpdateObjectiveTilesVisibilities(!bShow);
            UpdateStatsTilesVisibilities(!bShow);
            UpdateTipTilesVisibilities(!bShow);
            UpdateXPProgressTilesVisibilities(bShow);
            break;
        default:
            UpdateObjectiveTilesVisibilities(false);
            UpdateStatsTilesVisibilities(false);
            UpdateTipTilesVisibilities(false);
            UpdateXPProgressTilesVisibilities(false);
            break;
        }
    }
    else
    {
        UpdateObjectiveTilesVisibilities(bShow);
        UpdateStatsTilesVisibilities(bShow);
        UpdateTipTilesVisibilities(bShow);
        UpdateXPProgressTilesVisibilities(bShow);
    }
}

namespace fnv_00788ab0 {
extern bool DAT_011a0295;
void* __cdecl NiXenonRenderer_GetRenderer();
void __cdecl Tile_UpdateAll(bool);
void __fastcall LoadingMenu_AdvanceScreen(char*);
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
int StartMenu_GetClassStatic();
S00788ab0_MenuTileQuery* Tile_GetMenuByClass(int);
void FUN_0078cfc0();
void FUN_0078d020();
void __fastcall NiXenonRenderer_LockRenderer(char*);
void __fastcall NiXenonRenderer_UnlockRenderer(char*);
struct S00788ab0_OSQuery
{
    bool Main_GameReset();
};
} // namespace fnv_00788ab0

// When GetFloat(3) is nonzero, updates timers and menu state, configures tiles, and assigns value to pLocation.
// @fnv 0x00788ab0
// src: COMMUNITY 0x00788ab0
void LoadingMenu::Reset_00788ab0(int aiExtraCandidates)
{
    if (GetFloat(3))
    {
        fnv_00788ab0::FUN_0078cfc0();
        m_uiFirstStateValue = gm_GetTickCount() - 4000;
        if (DAT_011d8907 || g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
        {
            fnv_00788ab0::S00788ab0_StartMenu* menu = fnv_00788ab0::Tile_GetMenuByClass(fnv_00788ab0::StartMenu_GetClassStatic())->GetMenu();
            if (menu && !menu->IsFlagSet(fnv_00788ab0::S00788ab0_StartMenu::Flag1))
            {
                delete menu;
            }
        }
        if (((fnv_00788ab0::S00788ab0_OSQuery*)g_osGlobals)->Main_GameReset())
        {
            this->ShowPlayerTiles(false);
        }
        else
        {
            this->ShowPlayerTiles(true);
            FUN_0078aec0();
        }
        pLocation = (TESForm*)aiExtraCandidates;
        UpdateLoadingScreens();
        pLocation = (TESForm*)aiExtraCandidates;
        m_uiLoadScreenIndex = gm_GetTickCount();
        ++m_uiSecondStateValue;
        this->UpdateLoadingScreenText(0);
        fnv_00788ab0::LoadingMenu_AdvanceScreen((char*)this);
        this->ApplyLoadingScreenTexture(0);
        FUN_0078abd0();
        ++m_uiSecondStateValue;
        this->UpdateLoadingScreenText(0);
        fnv_00788ab0::LoadingMenu_AdvanceScreen((char*)this);
        this->ApplyLoadingScreenTexture(0);
        FUN_0078abd0();
        this->FUN_00458080((TileIndex)3, false);
        fnv_00788ab0::NiXenonRenderer_LockRenderer((char*)fnv_00788ab0::NiXenonRenderer_GetRenderer());
        if (!((Tile*)m_pTiles[11])->IsVisible())
        {
            m_pTiles[11]->Set(4003, 1);
            this->ResetLoadingPinwheelAnimation();
        }
        InterfaceManager_GetSingleton()->GetParent()->Set(4003, 0);
        fnv_00788ab0::Tile_UpdateAll(true);
        fnv_00788ab0::NiXenonRenderer_UnlockRenderer((char*)fnv_00788ab0::NiXenonRenderer_GetRenderer());
        fnv_00788ab0::DAT_011a0295 = true;
        fnv_00788ab0::FUN_0078d020();
    }
}
