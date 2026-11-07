// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADMANAGER_H
#define FNV_BGSSAVELOADMANAGER_H

#include "layout_support.h"
#include "layout_support.h"
class SaveLoadFile;
class BGSSaveLoadFileEntry;
class SaveLoadHeader;
class BGSSaveLoadManager;
#pragma pack(push, 4)
class BGSSaveLoadManager
{
  public:
    BSSimpleList<BGSSaveLoadFileEntry*>* m_pSaveLoadFileEntryList;  // +0x0, 4 bytes
    unsigned int SaveLoadManagerState;                              // +0x4, 4 bytes
    unsigned int m_uiSaveLoadSubstate;                              // +0x8, 4 bytes
    bool m_bFirstSaveLoadFlag;                                      // +0xC, 1 bytes
    bool m_bSecondSaveLoadFlag;                                     // +0xD, 1 bytes
    bool m_bThirdBoolean;                                           // +0xE, 1 bytes
    unsigned char m_cQueuedSaveLoad;                                // +0xF, 1 bytes
    unsigned char m_cAutosaveCountdown;                             // +0x10, 1 bytes
    unsigned char layoutPadding11[3];
    char* m_pTextBuffer;      // +0x14, 4 bytes
    int m_iTextBufferLength;  // +0x18, 4 bytes
    bool m_bFlagAfterCount;   // +0x1C, 1 bytes
    unsigned char layoutPadding1D[3];
    SaveLoadFile* m_pSaveFile;     // +0x20, 4 bytes
    bool m_bSaveOperationActive;   // +0x24, 1 bytes
    bool m_bLoadOperationPending;  // +0x25, 1 bytes
    bool m_bLoadingGame;           // +0x26, 1 bytes
    unsigned char layoutPadding27[1];
    void(__cdecl* LoadDataResultCallback)(BSSaveDataSystemUtility::RESULT,
                                          BSSaveDataOperationEntry*&);  // +0x28, 4 bytes
    void(__cdecl* m_pfnSaveResultCallback)(BSSaveDataSystemUtility::RESULT,
                                           BSSaveDataOperationEntry*&);  // +0x2C, 4 bytes
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*(char*)
    // void __cdecl BGSSaveLoadManager::*(const char*, char*)
    // void __cdecl BGSSaveLoadManager::*(const char*, char*, bool)
    // SaveLoadFile* __cdecl BGSSaveLoadManager::*(const char*, bool, BGSSaveLoadManager::SAVEFILE_TYPE, int)
    // void __cdecl BGSSaveLoadManager::*(SaveLoadFile*, bool)
    // void __cdecl BGSSaveLoadManager::*(const char*, int)
    // unsigned int __cdecl BGSSaveLoadManager::*(const char*)
    // bool __cdecl BGSSaveLoadManager::*(const char*, int, bool)
    // bool __cdecl BGSSaveLoadManager::*(const char*, int, bool, bool)
    // void __cdecl BGSSaveLoadManager::*()
    // bool __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // bool __cdecl BGSSaveLoadManager::*(bool)
    // bool __cdecl BGSSaveLoadManager::*(int)
    // void __cdecl BGSSaveLoadManager::*()
    // int __cdecl BGSSaveLoadManager::*()
    // int __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*(char*, unsigned int)
    // bool __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // bool __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // BSSimpleList<BGSSaveLoadFileEntry *>* __cdecl BGSSaveLoadManager::*()
    // unsigned int __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*(BGSSaveLoadFileEntry*)
    // void __cdecl BGSSaveLoadManager::*(char*, bool, bool)
    // void __cdecl BGSSaveLoadManager::*(char*)
    // bool __cdecl BGSSaveLoadManager::*(const char*)
    // bool __cdecl BGSSaveLoadManager::*(const char*)
    // bool __cdecl BGSSaveLoadManager::*(const char*)
    // bool __cdecl BGSSaveLoadManager::*(const char*)
    // void __cdecl BGSSaveLoadManager::*(char*)
    // void __cdecl BGSSaveLoadManager::*(char*, bool)
    // unsigned int __cdecl BGSSaveLoadManager::*()
    // bool __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*(const char*, int)
    // bool __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*(SaveLoadFile*)
    // void __cdecl BGSSaveLoadManager::*(bool)
    // bool __cdecl BGSSaveLoadManager::*(bool, bool, bool)
    // bool __cdecl BGSSaveLoadManager::*()
    // bool __cdecl BGSSaveLoadManager::*()
    // bool __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*(bool)
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // bool __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*(SaveLoadFile*)
    // bool __cdecl BGSSaveLoadManager::*(SaveLoadFile*)
    // void __cdecl BGSSaveLoadManager::*(const char*, int, unsigned int)
    // void __cdecl BGSSaveLoadManager::*()
    // void __cdecl BGSSaveLoadManager::*(BSSaveDataSystemUtility::RESULT)
    // void* __cdecl BGSSaveLoadManager::*(unsigned int)
    bool InterfaceManager_GetMenuMode();
    bool IsAutoSaveFileName(const char*);
    void* ReadHeaderFromFile(const char*, int, int, int);
    bool IsSaveFileNameCustom(const char*);
    void CloseSaveFile(SaveLoadHeader*, int);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSSaveLoadManager) == 48);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_pSaveLoadFileEntryList) == 0);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, SaveLoadManagerState) == 4);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_uiSaveLoadSubstate) == 8);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_bFirstSaveLoadFlag) == 12);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_bSecondSaveLoadFlag) == 13);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_bThirdBoolean) == 14);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_cQueuedSaveLoad) == 15);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_cAutosaveCountdown) == 16);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_pTextBuffer) == 20);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_iTextBufferLength) == 24);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_bFlagAfterCount) == 28);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_pSaveFile) == 32);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_bSaveOperationActive) == 36);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_bLoadOperationPending) == 37);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_bLoadingGame) == 38);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, LoadDataResultCallback) == 40);
FNV_STATIC_ASSERT(offsetof(BGSSaveLoadManager, m_pfnSaveResultCallback) == 44);
#endif
