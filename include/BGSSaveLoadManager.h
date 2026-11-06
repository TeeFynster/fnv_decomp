#pragma once

class BGSSaveLoadFileEntry;
class BSSaveDataOperationEntry;
class SaveLoadFile;
class SaveLoadHeader;
template <class T> class BSSimpleList;
#include "BSSaveDataSystemUtility.h"

class BGSSaveLoadManager
{
public:
    BSSimpleList<BGSSaveLoadFileEntry*>* pSaveGameList;
    unsigned int iSaveGameCount;
    unsigned int iCurrentSaveGameNumber;
    bool bSimulatedMode;
    bool bAutosaveDisabledForDiskspace;
    bool bhandledCorrupt;
    unsigned char cQueuedAutosave;
    unsigned char cQueuedForceSave;
    bool bShouldSystemSave;
    unsigned char _pad12[2];
    char* pMostRecentSaveGame;
    int iMostRecentSaveGameDeviceID;
    bool bSysUtilHasSaveData;
    unsigned char _pad1D[3];
    SaveLoadFile* pSaveLoadFile;
    bool bReturnedFromSysUtil;
    bool bSysUtilLoadDataComplete;
    bool bStartMenuLoading;
    unsigned char _pad27[1];
    void (__cdecl* pSysUtilSaveCompleteCallback)(BSSaveDataSystemUtility::RESULT, BSSaveDataOperationEntry*&);
    void (__cdecl* pSysUtilLoadCompleteCallback)(BSSaveDataSystemUtility::RESULT, BSSaveDataOperationEntry*&);
    unsigned char sSystemSaveName[8];

    bool LoadGame(const char*, int, bool, bool);
    bool LoadGame(char*, int, bool, bool);
    bool CanLoadSaveGame(SaveLoadFile*);
    void FinishLoadingGame();
    void ProcessQueuedLoads();
    void ProcessQueuedSaveLoad();
    void Autosave();
    void GetFullPath(char*, char*, bool);
    void SetSaveFileName(char*, int);
    static void GetSaveDirectory(char* output);
    bool IsQuickSaveFileName(const char* name);
    bool IsAutoSaveFileName(const char* name);
    void SanitizeSaveFileName(char* name);
    void GetFNVVersionInfo(char* output, unsigned int capacity);
    bool CanSave(bool);
    bool IsSaveFileNameDefault(const char*);
    bool IsSaveFileNameLegacyAutosave(const char*);
    bool IsSaveFileNameCustom(const char*);
    void UpdateSaveTimestamp();
    static void BuildAutosaveName(char*);
    void* ReadHeaderFromFile(const char*, int, int, int);
    bool FUN_00424940();
    void FUN_00850100(SaveLoadHeader*, int);
    void FUN_00850100(SaveLoadFile*, bool);
    bool FUN_008503b0(const char*, int, bool);
    void FUN_00850a90();
    void FUN_00851d30();
    void EnsureFosExtension(char*, char*);
    void LoadQuickSave();
    void BuildSaveFileName(char*, bool, bool);
    void BuildSaveFileName(char*, int, int);
    void CopyPlayerName(char*);
    void FormatPlayTime(char*, bool);
    int GetConstant27();
    bool IsField5Set();
    void SetFlagByte();
    void ResetAndUpdate();
    void FUN_008509a0();
    void FUN_00850ba0();
    void FUN_00850bf0();
    void FUN_00850ea0(void*);
    void FUN_00850ea0(SaveLoadFile*);
    bool FUN_00851a60(const char*);
    bool FUN_00851b00(const char*);
    bool FUN_00850fe0(bool);
    void FUN_00851330();
    void FUN_00851540();
    SaveLoadFile* FUN_00850030(const char*, int, int, int);
    void BuildWeaponPath(const char*, char*, bool);
    void AddFileToList(char*, int, int);
};
