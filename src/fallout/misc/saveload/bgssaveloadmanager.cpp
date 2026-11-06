#include "../../../../include/SettingT.h"
#include "../../../../include/BSStringT.h"
#include "../../../../include/InterfaceManager.h"
// fallout/misc/saveload/bgssaveloadmanager.cpp: BGSSaveLoadManager, PathManager, Interface and more (39 functions)

#include "../../../../include/Actor.h"
#include "../../../../include/ActorMover.h"
#include "../../../../include/DialogMenu.h"
#include "../../../../include/GameSettingCollection.h"
#include "../../../../include/HUDMainMenu.h"
#include "../../../../include/Menu.h"
#include "../../../../include/LoadingMenu.h"
#include "../../../../include/Sky.h"
#include "../../../../include/ScriptLocals.h"
#include "../../../../include/TESFile.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/BGSSaveLoadManager.h"
#include "../../../../include/BGSTerrainManager.h"
#include "../../../../include/NavMeshObstacleManager.h"
// BGSSaveLoadUI_bgssaveloadmanager: local type (was include/BGSSaveLoadUI.h, which had no evidence of one real class); its methods are 0x007d0bb0 XGamerProfile::ForcePresenceUpdate, 0x007d0bd0 XGamerProfile::SetPlayingFlag, 0x007d3170 XGamerProfile::GetRumbleDefault, 0x00a26120 XGamerProfile::RevokeCode
class BGSSaveLoadUI_bgssaveloadmanager
{
public:
    void FUN_007d0bb0();
    void FUN_007d0bd0(bool);
    bool FUN_007d3170();
    bool FUN_00a26090(char*);
    bool FUN_00a26020(char const*);
    void FUN_00a26120(char*);
};
#include "../../../../include/BSAudio.h"
#include "../../../../include/GameTimerRecord.h"
#include "../../../../include/GridCellArray.h"
#include "../../../../include/NiPoint3Interpolator.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TES.h"
#include "../../../../include/TESQueuedCellManager.h"
#include "../../../../include/TESWorldSpace.h"

class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
// These game wrappers have different addresses from the CRT entry points.
namespace SaveLoadString
{
    int __cdecl strcat_s(char*, unsigned int, const char*);
    int __cdecl strcpy_s(char*, unsigned int, const char*);
    int __cdecl _stricmp(const char*, const char*);
}
char* __cdecl FUN_0086d480();
char* __cdecl FUN_004dc110();
char* __cdecl FUN_00c3bbd0();
char* __cdecl FUN_00c3bc20();
int __cdecl FUN_00ecbf05(const char*, int);
extern const char g_011d3eb0_arg1[];
extern const char g_011dece4_arg1[];
extern const char DAT_01082d70[];
extern const char DAT_01082d88[];
extern const char DAT_01082d94[];
extern const char DAT_01082da0[];
extern const char DAT_01082dac[];
extern const char DAT_01082dc4[];
extern const char* DAT_011a2ff0;
extern const char* DAT_011a2ff4;
extern int(__stdcall* DAT_00fdf0c4)(const char*, const char*, int, const char*);
extern int(__stdcall* DAT_00fdf274)(void*, int, void*, unsigned int, char*);
extern int(__stdcall* DAT_00fdf0b8)(const char*, void*);
extern int(__cdecl* DAT_00fdf0d4)(char*);
extern int(__stdcall* DAT_00fdf1b8)(const char*, const char*, int);

class SaveLoadFile;
class SaveLoadHeader
{
  public:
    static int ReadHeaderFromFile(SaveLoadFile*);
};

namespace SaveLoadInterface
{
    bool IsInterfaceActive();
    bool IsConsoleActive();
    void RestoreConsoleVisibility();
    bool ShowButtonDialog(const char*, const char*, const char*, void(__cdecl*)(), int, int, float, float,
                          const char*, ...);
}
class INISettingCollection;
using ::SettingT;
class GlobalObject_0040c150
{
};
class GlobalObject_0045cf30
{
};
extern GlobalObject_0040c150 g_011d2100, g_011d34f8, g_011d3684;
extern GlobalObject_0045cf30 g_011de248;
class OSGlobals;
class Main
{
  public:
    void RefreshAfterSave();
    void RunScripts();
    void OnGameLoaded();
};
extern OSGlobals* g_osGlobals;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern char DAT_011de138[260];
extern int DAT_011a224c;
extern bool DAT_011de23c;
extern int DAT_011dea24;
void __cdecl FUN_00850720();
void __cdecl DumpTextAndOpen(const char*);
InterfaceManager* __cdecl FUN_004b7210();

#include "../../../../include/FADER_ENUM.h"
class FaderManager
{
  public:
    bool HasFader(FADER_ENUM);
    void BeginFade(FADER_ENUM, float, bool);
};
extern Interface* DAT_011d8804;
extern BGSSaveLoadManager* DAT_011de134;

class ChallengeManager
{
  public:
    static void CheckCompletedChallenges();
};
class ModelLoader
{
  public:
    void FUN_00448620(bool);
    void FUN_00448420();
};
class VATS
{
  public:
    void ProcessVATSCommands();
    void Update(int, bool);
};
// The VATS camera singleton at 0x011f2250; 0x009c8950 is its (bool, bool) reset (a VATS-area method, not InventoryStackRecord).
class GlobalObject_009c6a30
{
  public:
    void FUN_009c8950(bool, bool);
};
extern GlobalObject_009c6a30 g_011f2250;
extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;
extern ModelLoader* g_modelLoader;
BGSSaveLoadUI_bgssaveloadmanager* __cdecl FUN_00a25920();
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting16;
void __cdecl FUN_00830660();
class GlobalObject_0096d020
{
  public:
    void FUN_00977660();
};
extern GlobalObject_0096d020 g_011e0e80;
class PathManager
{
  public:
    static PathManager* GetRandomGenerator();
    void FUN_006ebcd0();
    bool CallMemberFunction();
    void CallInner();
};

extern TESQueuedCellManager* DAT_011c9618;
void __cdecl FUN_005b4940();
void __cdecl FUN_005ae270();
void __cdecl FUN_005a9d60();
class TimeGlobal;
extern TimeGlobal g_timeGlobal;

class DownloadableContentManager
{
  public:
    const char* IsDLCAvailable();
};
extern GlobalObject_0040c150 g_011d38b8, g_011d3d0c;
extern const char DAT_0107fb78[];
extern const char DAT_0107faf8[];
extern const char DAT_0107fae0[];
extern const char g_011d31e0_arg1[];
extern GlobalObject_0040c150 g_011d4060;
unsigned int gm_GetTickCount();
unsigned int FUN_00702440();
int FUN_00702400(unsigned int);
unsigned int FUN_008510e0();
extern const char DAT_01012058[];

template <class T> unsigned int __cdecl BSStringLength(const T* text);

template <> unsigned int __cdecl BSStringLength<char>(const char* text);

extern "C" int __cdecl _mbsnicmp(const char* left, const char* right, unsigned int count);

extern "C" const char g_quicksaveName[];
extern "C" const char g_autosaveName[];
extern "C" const char g_scrubChars[];
extern const char g_emptyTopicInfoPrompt[];
extern "C" const char g_currentExeVersion[];
extern "C" const char g_versionInfoFormat[];
extern "C" const char g_dateTimeFormat[];
extern "C" void* __cdecl fnv_zlib_memset(void* destination, int value, unsigned int size);
extern "C" int __cdecl sprintf_s(char* output, unsigned int capacity, const char* format, ...);

struct FNVSystemTime
{
    unsigned short year;
    unsigned short month;
    unsigned short dayOfWeek;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    unsigned short second;
    unsigned short milliseconds;
};
struct FNVGetVersionInfoLocals
{
    FNVSystemTime time;
    char versionPrefix[260];
    unsigned char padding[8];
    unsigned int dateTimeSize;
    char dateTime[260];
};
typedef void(__stdcall* FNVDateFunction)(char* output, unsigned int* size);
typedef void(__stdcall* FNVSystemTimeFunction)(FNVSystemTime* time);
extern "C" FNVDateFunction g_fnvDateFunction;
extern "C" FNVSystemTimeFunction g_fnvSystemTimeFunction;

// Returns true when name is non-null and case-insensitively matches g_quicksaveName over its length.
// @fnv 0x00851a60
bool BGSSaveLoadManager::IsQuickSaveFileName(const char* name)
{
    if (name != 0 && _mbsnicmp(name, g_quicksaveName, BSStringLength<char>(g_quicksaveName)) == 0)
        return true;
    return false;
}

// @fnv 0x00851b00
bool BGSSaveLoadManager::IsAutoSaveFileName(const char* name)
{
    if (name != 0 && _mbsnicmp(name, g_autosaveName, BSStringLength<char>(g_autosaveName)) == 0)
        return true;
    return false;
}

// Replaces characters in name that are below '0', above 'z', or in g_scrubChars with a space, turning '"' into '\''.
// @fnv 0x008518d0
void BGSSaveLoadManager::SanitizeSaveFileName(char* name)
{
    unsigned int length = BSStringLength<char>(name);
    for (unsigned int index = 0; index < length; ++index)
    {
        if (name[index] < '0')
            name[index] = ' ';
        if (name[index] > 'z')
            name[index] = ' ';
        else if (strchr(g_scrubChars, name[index]) != 0)
        {
            if (name[index] == '"')
                name[index] = '\'';
            else
                name[index] = ' ';
        }
    }
}

// Builds a version prefix and formatted date/time, then writes the version info string into output using capacity.
// @fnv 0x00851120
void BGSSaveLoadManager::GetFNVVersionInfo(char* output, unsigned int capacity)
{
    FNVGetVersionInfoLocals locals;

    locals.versionPrefix[0] = g_emptyTopicInfoPrompt[0];
    fnv_zlib_memset(locals.versionPrefix + 1, 0, 0x103);
    locals.dateTime[0] = g_emptyTopicInfoPrompt[0];
    fnv_zlib_memset(locals.dateTime + 1, 0, 0x103);
    locals.dateTimeSize = 0x104;
    g_fnvDateFunction(locals.versionPrefix, &locals.dateTimeSize);
    g_fnvSystemTimeFunction(&locals.time);
    sprintf_s(locals.dateTime, 0x104, g_dateTimeFormat, locals.time.month, locals.time.day, locals.time.year,
              locals.time.hour, locals.time.minute, locals.time.second);
    sprintf_s(output, capacity, g_versionInfoFormat, locals.versionPrefix, locals.dateTime, g_currentExeVersion, 48,
              27);
}

// @fnv 0x00876ad0
void BGSSaveLoadManager::GetSaveDirectory(char* pcPath)
{
    bool useMyGames = true;
    sprintf_s(pcPath, 260, DAT_01082dc4, DAT_011a2ff4);
    if (!DAT_00fdf0c4(g_011d3eb0_arg1, DAT_01082dac, 1, pcPath))
        useMyGames = false;
    sprintf_s(pcPath, 260, DAT_01082dc4, DAT_011a2ff0);
    if (useMyGames && !DAT_00fdf0c4(g_011d3eb0_arg1, DAT_01082dac, 1, pcPath))
        useMyGames = false;
    if (useMyGames)
    {
        char folder[260];
        pcPath[0] = 0;
        DAT_00fdf274(0, 28, 0, 0, folder);
        SaveLoadString::strcat_s(folder, 260, DAT_01082da0);
        DAT_00fdf0b8(folder, 0);
        TaskQueueInterface::CopyStringToBuffer(FUN_0086d480(), 260, folder);
        DAT_00fdf274(0, 5, 0, 0, folder);
        SaveLoadString::strcat_s(folder, 260, DAT_01082d94);
        DAT_00fdf0b8(folder, 0);
        SaveLoadString::strcat_s(folder, 260, DAT_01082d88);
        DAT_00fdf0b8(folder, 0);
        TaskQueueInterface::CopyStringToBuffer(FUN_004dc110(), 260, folder);
    }
    else
    {
        TaskQueueInterface::CopyStringToBuffer(FUN_0086d480(), 260, g_011dece4_arg1);
        TaskQueueInterface::CopyStringToBuffer(FUN_004dc110(), 260, g_011dece4_arg1);
    }
    TaskQueueInterface::CopyStringToBuffer(pcPath, 260, FUN_004dc110());
    SaveLoadString::strcat_s(pcPath, 260, DAT_011a2ff0);
    ((int(__stdcall*)(char*))DAT_00fdf0d4)(TESFile::IsTempIDLoadable());
    ((int(__stdcall*)(char*))DAT_00fdf0d4)(FUN_00c3bbd0());
    ((int(__stdcall*)(char*))DAT_00fdf0d4)(FUN_00c3bc20());
    if (FUN_00ecbf05(pcPath, 0) == -1)
    {
        char defaultIni[260];
        TaskQueueInterface::CopyStringToBuffer(defaultIni, 260, DAT_01082d70);
        DAT_00fdf1b8(defaultIni, pcPath, 1);
    }
}

// @fnv 0x00850760
bool BGSSaveLoadManager::LoadGame(const char* name, int deviceID, bool recent, bool allowMissing)
{
    bool result;
    {
        char savedName[260];
        if (name)
            TaskQueueInterface::CopyStringToBuffer(savedName, 260, name);
        SaveLoadFile* file = 0;
        if (pSaveLoadFile)
            file = pSaveLoadFile;
        else
            file = FUN_00850030(name, 0, 1, deviceID);
        result = false;
        if (file)
        {
            bool consoleWasVisible = SaveLoadInterface::IsConsoleActive();
            if (!*reinterpret_cast<const bool*>(reinterpret_cast<SettingT<INISettingCollection>*>(&g_011de248)->Bool()))
                allowMissing = true;
            if (reinterpret_cast<BGSLoadGameBuffer*>(file)->FUN_008463c0())
            {
                if (CanLoadSaveGame(file))
                {
                    bStartMenuLoading = true;
                    result = g_BGSSaveLoadGame->LoadGame(file, allowMissing);
                    bStartMenuLoading = false;
                    if (result)
                        FinishLoadingGame();
                    else
                    {
                        TaskQueueInterface::CopyStringToBuffer(DAT_011de138, 260, name);
                        DAT_011a224c = deviceID;
                        DAT_011de23c = recent;
                        SaveLoadInterface::ShowButtonDialog(
                            reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d2100)->String(), 0, 0,
                            FUN_00850720, 1, 23, 0.0f, 0.0f,
                            reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d34f8)->String(),
                            reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d3684)->String(), 0);
                    }
                }
                else
                    result = false;
            }
            if (file != pSaveLoadFile)
                FUN_00850100(file, false);
            if (result && recent)
            {
                char fullPath[260];
                GetFullPath(const_cast<char*>(name), fullPath, false);
                DumpTextAndOpen(fullPath);
            }
            if (consoleWasVisible)
            {
                SaveLoadInterface::RestoreConsoleVisibility();
                FUN_004b7210()->FUN_00714d70(DAT_011dea24);
            }
            if (result)
                SetSaveFileName(savedName, deviceID);
        }
        reinterpret_cast<Main*>(g_osGlobals)->RefreshAfterSave();
    }
    return result;
}

// @fnv 0x00851d90
void BGSSaveLoadManager::ProcessQueuedSaveLoad()
{
    if (cQueuedAutosave)
    {
        if (cQueuedAutosave > 1)
            --cQueuedAutosave;
        else if (!reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)1) &&
                 !reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)2) &&
                 !SaveLoadInterface::IsInterfaceActive())
            DAT_011de134->Autosave();
    }
    else if (cQueuedForceSave)
    {
        if (cQueuedForceSave > 1)
            --cQueuedForceSave;
        else if (!reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)1) &&
                 !reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)2) &&
                 !SaveLoadInterface::IsInterfaceActive())
        {
            DAT_011de134->FUN_008503b0(0, -1, false);
            cQueuedForceSave = 0;
        }
    }
    // The original treats this flag byte as a countdown.
    else if (reinterpret_cast<unsigned char&>(bShouldSystemSave))
    {
        if (reinterpret_cast<unsigned char&>(bShouldSystemSave) > 1)
            --reinterpret_cast<unsigned char&>(bShouldSystemSave);
        else if (!reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)1) &&
                 !reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)2) &&
                 !SaveLoadInterface::IsInterfaceActive())
            DAT_011de134->FUN_00850a90();
    }
}

// @fnv 0x00850d60
void BGSSaveLoadManager::FinishLoadingGame()
{
    ChallengeManager::CheckCompletedChallenges();
    reinterpret_cast<Main*>(g_osGlobals)->OnGameLoaded();
    reinterpret_cast<Main*>(g_osGlobals)->RunScripts();
    g_modelLoader->FUN_00448620(false);
    g_TES->FUN_00459a00();
    reinterpret_cast<ActorMover*>(g_osGlobals)->RefreshMovementState();
    reinterpret_cast<GridCellArray*>(reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>(g_TES)->GetSize())
        ->ReleaseGridCells();
    reinterpret_cast<VATS*>(&g_011f2250)->ProcessVATSCommands();
    TESWorldSpace* world = g_thePlayer->GetParentWorldSpace();
    if (world)
        world->GetWorldTerrainManager()->Update(*static_cast<const TESObjectREFR*>(g_thePlayer)->GetPos(), 15);
    if (FUN_00a25920())
    {
        FUN_00a25920()->FUN_007d0bd0(true);
        FUN_00a25920()->FUN_007d0bb0();
    }
    reinterpret_cast<FaderManager*>(DAT_011d8804)
        ->BeginFade((FADER_ENUM)1, *originalRuntimeFloatSetting16.Float(), true);
    LoadingMenu::UpdateLoadingScreenThread();
    g_TES->RefreshWorldState(0, 0, 0);
    BSAudio::GetSingleton()->FUN_00ad8740();
    FUN_00830660();
    g_011e0e80.FUN_00977660();
    g_BGSSaveLoadGame->FUN_0084cc40(false);
    NavMeshObstacleManager::GetSingleton()->ResetObstacles();
    PathManager::GetRandomGenerator()->FUN_006ebcd0();
}

// @fnv 0x00850c20
void BGSSaveLoadManager::ProcessQueuedLoads()
{
    DAT_011c9618->SubmitQueuedItems();
    g_modelLoader->FUN_00448420();
    FUN_005b4940();
    FUN_005ae270();
    FUN_005a9d60();
    BSAudio::GetSingleton()->FUN_00ad84e0(-1, false);
    bool wasMultiThreaded = BSAudio::GetSingleton()->FUN_005bb4d0();
    BSAudio::GetSingleton()->SetUseMultipleThreads(false);
    for (unsigned int index = 0; index < 10; ++index)
        BSAudio::GetSingleton()->Update(false);
    BSAudio::GetSingleton()->SetUseMultipleThreads(wasMultiThreaded);
    if (reinterpret_cast<HUDMainMenu*>(&g_011f2250)->RefreshTargetDisplay())
    {
        g_011f2250.FUN_009c8950(true, false);
        reinterpret_cast<NiPoint3Interpolator*>(&g_011f2250)->CreateObject(0, false);
    }
    reinterpret_cast<GameTimerRecord*>(&g_timeGlobal)->SetGlobalTimeMultiplier(1.0f, true);
    if (g_thePlayer)
        reinterpret_cast<VATS*>(g_thePlayer)->Update(2, true);
    g_TES->RefreshWorldState(1, 0, 0);
    while (!PathManager::GetRandomGenerator()->CallMemberFunction())
    {
        // Preserve the original receiver in ECX when calling the shared static declaration.
        reinterpret_cast<void (__fastcall*)(PathManager*)>(&ScriptLocals::ProcessPendingTasks)(
            PathManager::GetRandomGenerator());
        NavMeshObstacleManager::GetSingleton()->Update();
    }
    PathManager::GetRandomGenerator()->CallInner();
}

// Reads the save file version and returns false after showing an error message if it is not 47 or 48.
// @fnv 0x00850ed0
bool BGSSaveLoadManager::CanLoadSaveGame(SaveLoadFile* file)
{
    int version = SaveLoadHeader::ReadHeaderFromFile(file);
    if (version > 48 || version < 47)
    {
        if (version <= 0)
        {
            SaveLoadInterface::ShowButtonDialog(reinterpret_cast<DownloadableContentManager*>(&g_011d3d0c)->IsDLCAvailable(), 0,
                                        0, 0, 0, 23, 0.0f, 0.0f,
                                        reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d38b8)->String(), 0);
        }
        else
        {
            char message[260];
            if (version < 48)
                sprintf_s(message, 260, DAT_0107fb78, version, 48);
            else
                sprintf_s(message, 260, DAT_0107faf8, version, 48);
            SaveLoadInterface::ShowButtonDialog(message, 0, 0, 0, 0, 23, 0.0f, 0.0f,
                                        reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d38b8)->String(), 0);
        }
        return false;
    }
    return true;
}

// @fnv 0x00850fe0
bool BGSSaveLoadManager::CanSave(bool skipMenus)
{
    if (g_thePlayer)
    {
        if ((unsigned int)((GameSettingCollection*)g_thePlayer)->FUN_004f8960() == 2 ||
            (unsigned int)((GameSettingCollection*)g_thePlayer)->FUN_004f8960() == 1)
            return false;
        if (g_thePlayer->GetUnderAIControl())
            return false;
    }
    if (((HUDMainMenu*)&g_011f2250)->RefreshTargetDisplay())
        return false;
    if (!skipMenus)
    {
        unsigned int count = FUN_00702440();
        for (unsigned int index = 0; index < count; ++index)
        {
            int iMenuType = FUN_00702400(index);
            switch (iMenuType)
            {
            case 0:
            case 3:
            case 1013:
                break;
            case 1001:
                if (FUN_008510e0() > 0)
                    return false;
                break;
            default:
                return false;
            }
        }
    }
    return true;
}
// Builds the default save-file prefix from a game setting plus a suffix and compares it case-insensitively against name.
// @fnv 0x00851980
bool BGSSaveLoadManager::IsSaveFileNameDefault(const char* name)
{
    char prefix[260];
    TaskQueueInterface::CopyStringToBuffer(prefix, 260, ((SettingT_GameSettingCollection_*)&g_011d4060)->String());
    SaveLoadString::strcat_s(prefix, 260, g_011d31e0_arg1);
    if (name && _mbsnicmp(name, prefix, BSStringLength<char>(prefix)) == 0)
        return true;
    return false;
}
// @fnv 0x00851aa0
bool BGSSaveLoadManager::IsSaveFileNameCustom(const char* name)
{
    if (IsSaveFileNameDefault(name) || IsSaveFileNameLegacyAutosave(name) || IsQuickSaveFileName(name) ||
        IsAutoSaveFileName(name))
        return false;
    return true;
}
// Formats the autosave name from g_autosaveName and the player's full name, truncates it to 27 characters, and passes it to DAT_011de134.
// @fnv 0x00850b40
void BGSSaveLoadManager::BuildAutosaveName(char* name)
{
    sprintf_s(name, 260, DAT_01012058, g_autosaveName, g_thePlayer->GetFullName());
    if (BSStringLength<char>(name) > 27)
        name[27] = 0;
    DAT_011de134->SanitizeSaveFileName(name);
}
// Returns true if name is non-null and starts with the prefix DAT_0107fae0 (case-insensitive compare).
// @fnv 0x00851a20
bool BGSSaveLoadManager::IsSaveFileNameLegacyAutosave(const char* name)
{
    if (name && _mbsnicmp(name, DAT_0107fae0, BSStringLength<char>(DAT_0107fae0)) == 0)
        return true;
    return false;
}
// @fnv 0x00851d10
void BGSSaveLoadManager::UpdateSaveTimestamp()
{
    *(unsigned int*)((char*)this + 0x78c) = gm_GetTickCount();
}

// Appends ".fos" to apFullFileName when its length is under 4 or it does not already end in ".fos".
// @fnv 0x0084fec0
void BGSSaveLoadManager::EnsureFosExtension(char* apFileName, char* apFullFileName)
{
    TaskQueueInterface::CopyStringToBuffer(apFullFileName, 0x104, apFileName);
    unsigned int ilength = BSStringLength<char>(apFullFileName);
    if (ilength < 4 || SaveLoadString::_stricmp(&apFullFileName[ilength - 4], ".fos") != 0)
        SaveLoadString::strcat_s(apFullFileName, 0x104, ".fos");
}

int __cdecl FUN_00408b20(const char*, const char*);

// @fnv 0x00851250
void BGSSaveLoadManager::SetSaveFileName(char* apSaveFileName, int aiDeviceID)
{
    if (!apSaveFileName)
        return;

    if (pMostRecentSaveGame && !FUN_00408b20(pMostRecentSaveGame, apSaveFileName))
        return;

    delete pMostRecentSaveGame;
    unsigned int ilength = BSStringLength(apSaveFileName) + 1;
    pMostRecentSaveGame = new char[ilength];
    TaskQueueInterface::CopyStringToBuffer(pMostRecentSaveGame, ilength, apSaveFileName);
    iMostRecentSaveGameDeviceID = aiDeviceID;
}

struct IOManager;
extern IOManager* DAT_01202d98;
extern void __fastcall FUN_00c3e340(IOManager*);

// Calls FUN_00c3e340 on DAT_01202d98, then calls FUN_006ebcd0 on the PathManager singleton.
// @fnv 0x00850bf0
void BGSSaveLoadManager::FUN_00850bf0()
{
    FUN_00c3e340(DAT_01202d98);
    PathManager::GetRandomGenerator()->FUN_006ebcd0();
}

struct FUN_00765340_shell
{
    unsigned int __thiscall GetUnfilteredCount();
};
extern int DAT_011da4f0;

// Returns the result of calling GetUnfilteredCount on the object at DAT_011da4f0 + 0x40, or 0 when DAT_011da4f0 is null.
// @fnv 0x008510e0
unsigned int FUN_008510e0()
{
    unsigned int result;
    if (DAT_011da4f0)
        result = reinterpret_cast<FUN_00765340_shell*>(DAT_011da4f0 + 0x40)->GetUnfilteredCount();
    else
        result = 0;
    return result;
}

// @fnv 0x00851d30
void __thiscall BGSSaveLoadManager::FUN_00851d30()
{
    cQueuedAutosave = 1;
}

// @fnv 0x00851d50
void __fastcall FUN_00851d50(void* apObject)
{
    ((char*)apObject)[0x10] = 1;
}

// @fnv 0x00851110
int __thiscall BGSSaveLoadManager::GetConstant27()
{
    return 0x1b;
}

// @fnv 0x00851230
bool BGSSaveLoadManager::IsField5Set()
{
    return (pMostRecentSaveGame != 0) ? true : false;
}

// @fnv 0x00851d70
void BGSSaveLoadManager::SetFlagByte()
{
    bShouldSystemSave = 1;
}

bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);
extern float DAT_010162c0;
extern const char g_011cba4c_arg1[];
extern GlobalObject_0040c150 g_011d3600;
// Queues a UI message from the game setting string and then calls FUN_008503b0 with g_quicksaveName and -1, 0.
// @fnv 0x008509a0
void BGSSaveLoadManager::FUN_008509a0()
{
    QueueUIMessage(((SettingT_GameSettingCollection_*)&g_011d3600)->String(), 0, g_011cba4c_arg1, 0, DAT_010162c0, 0);
    FUN_008503b0(g_quicksaveName, -1, 0);
}

bool __cdecl QueueUIMessage(char const*, int, char const*, char const*, float, bool);
extern float _DAT_010162c0;
extern const char g_011cba4c_arg1[];
extern SettingT_GameSettingCollection_ g_011d35ac;
// Queues a UI message using a game setting string and then loads the quicksave.
// @fnv 0x008509f0
void BGSSaveLoadManager::LoadQuickSave()
{
    QueueUIMessage(g_011d35ac.String(), 0, g_011cba4c_arg1, 0, _DAT_010162c0, 0);
    LoadGame(g_quicksaveName, -1, false, true);
}

float __cdecl FUN_00453850();
// Clears two fields on this manager, updates the current AI process's Sky with FUN_00453850(), then calls FUN_008503b0(DAT_0107fae0, -1, 0).
// @fnv 0x00850a40
void BGSSaveLoadManager::ResetAndUpdate()
{
    cQueuedAutosave = 0;
    bhandledCorrupt = 0;
    ((Sky*)((MobileObject*)g_TES)->GetCurrentAIProcess())->Update(FUN_00453850());
    FUN_008503b0(DAT_0107fae0, -1, 0);
}

struct IOManager;
extern IOManager* DAT_01202d98;
void __fastcall FUN_00c3e310(IOManager*);
struct FUN_006ebc70_shell
{
    void FUN_006ebc70();
};
struct FUN_006ebc90_shell
{
    bool FUN_006ebc90();
};
// @fnv 0x00850ba0
void BGSSaveLoadManager::FUN_00850ba0()
{
    ((FUN_006ebc70_shell*)PathManager::GetRandomGenerator())->FUN_006ebc70();
    FUN_00c3e310(DAT_01202d98);
    while (!((FUN_006ebc90_shell*)PathManager::GetRandomGenerator())->FUN_006ebc90())
    {
        reinterpret_cast<void (__fastcall*)(PathManager*)>(&ScriptLocals::ProcessPendingTasks)(
            PathManager::GetRandomGenerator());
    }
}

struct FUN_00847d00_shell
{
    void SetFlag4(bool);
};
void __cdecl FUN_0084d4b0(void*);
// @fnv 0x00850ea0
void BGSSaveLoadManager::FUN_00850ea0(void* apArg)
{
    reinterpret_cast<FUN_00847d00_shell*>(g_BGSSaveLoadGame)->SetFlag4(true);
    FUN_0084d4b0(apArg);
}

struct S00851cd0
{
    unsigned char _pad[0x78C];
    unsigned int f78C;
    unsigned int f790;
    void FUN_00851cd0();
};
// Adds the elapsed time since the last tick to f790 and calls UpdateSaveTimestamp on the BGSSaveLoadManager.
// @fnv 0x00851cd0
void S00851cd0::FUN_00851cd0()
{
    f790 += gm_GetTickCount() - f78C;
    ((BGSSaveLoadManager*)this)->UpdateSaveTimestamp();
}

extern "C" int __cdecl sprintf_s(char* output, unsigned int capacity, const char* format, ...);

struct FUN_00851cb0_shell
{
    unsigned int __thiscall GetField790();
};

// Converts the player's total playing time into hours, minutes and seconds and writes them to output as a formatted string.
// @fnv 0x00851bf0
void BGSSaveLoadManager::FormatPlayTime(char* output, bool useThreeDigitHours)
{
    unsigned int totalPlayingTime2 = ((FUN_00851cb0_shell*)g_thePlayer)->GetField790();
    unsigned int hours2 = totalPlayingTime2 / 0x36ee80;
    totalPlayingTime2 -= hours2 * 0x36ee80;
    unsigned int minutes = totalPlayingTime2 / 0xea60;
    totalPlayingTime2 -= minutes * 0xea60;
    unsigned int seconds = totalPlayingTime2 / 0x3e8;
    if (useThreeDigitHours)
        sprintf_s(output, 0x104, "%03i.%02i.%02i", hours2, minutes, seconds);
    else
        sprintf_s(output, 0x104, "%02i.%02i.%02i", hours2, minutes, seconds);
}

namespace fnv_00851cb0 {
struct S00851cd0
{
    void __thiscall FUN_00851cd0();
    int m_790;
    int __thiscall GetField790();
};

// @fnv 0x00851cb0
int __thiscall S00851cd0::GetField790()
{
    FUN_00851cd0();
    return ((int*)this)[0x1e4];
}
}  // namespace fnv_00851cb0

namespace fnv_008517c0 {
extern unsigned int __cdecl _BSStringLength(const char* text);
int __cdecl _sprintf_s(char* output, unsigned int capacity, const char* format, ...);

extern unsigned int _data_011c16bc;
extern void __cdecl _ref_00ec408c(unsigned int value);

extern TESObjectREFR* _g_thePlayer;
extern GlobalObject_0040c150 g_011d3ed4;

}  // namespace fnv_008517c0

// Builds a save file name from the player name, location and play time, truncating it to fit and passing it to the save manager unless autosaving.
// @fnv 0x008517c0
void BGSSaveLoadManager::BuildSaveFileName(char* saveFileName, bool autosave, bool displayOnly)
{
    const char* pplayerName;
    char pplayTimeString[260];
    char pplayerLocationName[260];

    pplayerName = fnv_008517c0::_g_thePlayer->GetFullName();

    this->CopyPlayerName(pplayerLocationName);
    FormatPlayTime(pplayTimeString, autosave);

    fnv_008517c0::_sprintf_s(saveFileName, 0x104, "%s %i - %s, %s, %s",
               displayOnly ? reinterpret_cast<SettingT_GameSettingCollection_*>(&fnv_008517c0::g_011d3ed4)->String()
                           : reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d4060)->String(),
               iCurrentSaveGameNumber, pplayerName, pplayerLocationName, pplayTimeString);

    if (!autosave)
    {
        unsigned int imaxFileNameLength = 0x104;
        if (fnv_008517c0::_BSStringLength(saveFileName) > imaxFileNameLength - 5)
            saveFileName[imaxFileNameLength - 5] = 0;

        SanitizeSaveFileName(saveFileName);
    }
}

struct FUN_00404eb0
{
    int contextId;
    FUN_00404eb0(int category, int level, const char* sourceName, int messageId);
    ~FUN_00404eb0();
};
bool __fastcall FUN_009373f0(InterfaceManager* manager);
struct MessageSink
{
    void __thiscall AddMessage(int a, int b, int c, int d, float value, unsigned char option);
};
extern "C" MessageSink* DAT_011d96c0;
extern "C" const char str_0106eb78[];

// Creates a scope object, and if an interface manager and message sink exist, forwards the six arguments to the sink; returns false.
// @fnv 0x007052f0
bool __cdecl DispatchMessageToSink(int aiArg1, int aiArg2, int aiArg3, int aiArg4, float value, unsigned char option)
{
    FUN_00404eb0 scope(13, 1, str_0106eb78, 0x901);
    if (FUN_004b7210() && FUN_009373f0(FUN_004b7210()) && DAT_011d96c0)
        DAT_011d96c0->AddMessage(aiArg1, aiArg2, aiArg3, aiArg4, value, option);
    return false;
}

struct SaveGameDetails
{
    unsigned int GetReferenceFlags();
    void DeleteItemsFrom(unsigned int);
};
struct SaveGameOps
{
    void FUN_0084ab20();
    SaveGameDetails* FUN_00441110();
    void FUN_00847850(SaveLoadFile*);
    bool FUN_005621d0();
    void SetFlag4(bool);
};
struct SettingString
{
    const char* GetString();
};
extern SettingT_GameSettingCollection_ g_011d2364;
extern SettingString g_011d4930, g_011d4f0c;
extern const char str_010208a0[], str_010208e0[];
// @fnv 0x008503b0
bool BGSSaveLoadManager::FUN_008503b0(const char* acFileName, int mode, bool remove)
{
    bool q = IsSaveFileNameLegacyAutosave(acFileName);
    bool b = FUN_00851a60(acFileName);
    bool a = FUN_00851b00(acFileName);
    bool eb = false;
    char f[260];
    char cf[260];
    char ba[260];
    if (q || cQueuedForceSave || a)
        eb = true;
    if (!FUN_00850fe0(q))
    {
        if (!eb)
            QueueUIMessage(g_011d2364.String(), 0, str_010208a0, 0, DAT_010162c0, false);
        return false;
    }
    if (iCurrentSaveGameNumber == 0)
    {
        FUN_00851330();
        FUN_00851540();
    }
    if (!acFileName)
    {
        BuildSaveFileName(cf, 0, 0);
        acFileName = cf;
    }
    SaveLoadString::strcpy_s(f, 260, acFileName);
    ((SaveGameOps*)g_BGSSaveLoadGame)->FUN_0084ab20();
    unsigned int h = ((SaveGameOps*)g_BGSSaveLoadGame)->FUN_00441110()->GetReferenceFlags();
    FUN_00850ba0();
    SaveLoadFile* i = 0;
    if (pSaveLoadFile)
        i = pSaveLoadFile;
    else
        i = FUN_00850030(acFileName, 1, 2, mode);
    if (!i)
    {
        FUN_00850bf0();
        return false;
    }
    if (eb)
    {
        bAutosaveDisabledForDiskspace = false;
        QueueUIMessage(g_011d4930.GetString(), 0, str_010208e0, 0, DAT_010162c0, true);
    }
    FUN_00850ea0(i);
    ((SaveGameOps*)g_BGSSaveLoadGame)->FUN_00847850(i);
    if (((SaveGameOps*)g_BGSSaveLoadGame)->FUN_005621d0())
    {
        ((SaveGameOps*)g_BGSSaveLoadGame)->SetFlag4(false);
        QueueUIMessage(g_011d4f0c.GetString(), 0, str_010208a0, 0, DAT_010162c0, false);
        FUN_00850bf0();
        return false;
    }
    FUN_00850bf0();
    if (i != pSaveLoadFile)
        FUN_00850100(i, true);
    if (remove)
    {
        BuildWeaponPath(acFileName, ba, false);
        DumpTextAndOpen(ba);
    }
    ((SaveGameOps*)g_BGSSaveLoadGame)->FUN_00441110()->DeleteItemsFrom(h);
    if (i != pSaveLoadFile && pSaveGameList)
        AddFileToList(f, mode, iCurrentSaveGameNumber);
    if (!b && !q)
        iCurrentSaveGameNumber = iCurrentSaveGameNumber + 1;
    SetSaveFileName(f, mode);
    bool p = true;
    return p;
}

struct StrStandIn851
{
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    StrStandIn851();
    ~StrStandIn851();
    operator const char*() const;
};
struct PlayerStandIn851
{
    void GetName851(StrStandIn851* out);
};
extern PlayerStandIn851* DAT_011dea3c;
void __cdecl StrCpyS851(char* dest, unsigned int size, const char* src);
// Copies the player's name into dest (up to 0x104 bytes), or an empty string if the name is null.
// @fnv 0x00851b40
void BGSSaveLoadManager::CopyPlayerName(char* dest)
{
    StrStandIn851 name;
    DAT_011dea3c->GetName851(&name);
    if ((const char*)name)
        StrCpyS851(dest, 0x104, name);
    else
        StrCpyS851(dest, 0x104, "");
}

class Modifier
{
  public:
    unsigned char GetKey();
};

class Tile_
{
  public:
    Menu* GetMenu();
};

Tile_* __cdecl FUN_00a09030(int id);

// If a modifier key is held, look up tile 0x3f1, cast its menu to DialogMenu, and call SetActive on it.
// @fnv 0x00705110
void __cdecl SetDialogMenuActive(bool abActive)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
    {
        DialogMenu* pkMenu;
        Tile_* pkTile = FUN_00a09030(0x3f1);
        pkMenu = pkTile ? dynamic_cast<DialogMenu*>(pkTile->GetMenu()) : 0;
        if (pkMenu)
            pkMenu->SetActive(abActive);
    }
}



struct S7010
{
    unsigned int Length();
};

float __cdecl FUN_00453850(void);

// @fnv 0x00850a90
void BGSSaveLoadManager::FUN_00850a90()
{
    char autosaveName[260];

    bShouldSystemSave = 0;
    bhandledCorrupt = 0;

    reinterpret_cast<Sky*>(reinterpret_cast<Actor*>(g_TES)->FUN_008d8520())->Update(FUN_00453850());

    BGSSaveLoadManager::BuildAutosaveName(autosaveName);

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x30)->Length() == 0)
    {
        reinterpret_cast<::BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x30)->Set(autosaveName, 0);
    }

    FUN_008503b0(autosaveName, -1, false);
}
