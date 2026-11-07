#pragma once

#include <windows.h>
#include "NiAVObject.h"
#include "NiTexture.h"

class BGSSaveLoadFileEntry
{
public:
    union
    {
        unsigned char layoutPadding00[0x10];
        struct
        {
            char* pFileName;
            bool m_bHeaderParsed;
            bool m_bSaveEntryValid;
            unsigned char unk06[2];
            unsigned int PathMetadataRecord;
            char* m_pStringBeforeSaveFileName;
        };
    };
    char* m_pSaveFileName;
    union
    {
        unsigned char layoutPadding14[0x2C];
        struct
        {
            char* pLocation;
            char* m_pStringAfterLocation;
            unsigned int StringIntegerRecord;
            unsigned int m_uiHeaderRecordValue;
            unsigned int m_uiFileSize;
            unsigned int SaveFileMetadata;
            _FILETIME FileTime;
            int m_iScreenshotOffset;
            int iVersion;
            unsigned char unk3C[4];
        };
    };
    NiPointer<NiTexture> spScreenshot;

    void ReadTypedData();
    char* GetPlayerTitle();
    NiTexture* TileImage_GetShaderProp();
    bool IsAutoSave();
    bool IsSaveEntryValid();
    NiTexture* ReadScreenshotFromFile();
    void* GetScreenshotWidth();
    void* GetScreenshotHeight();
    void* GetScreenshotOffset();
};
