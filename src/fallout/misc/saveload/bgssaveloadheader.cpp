// fallout/misc/saveload/bgssaveloadheader.cpp: save header functions (4 functions)

#include "bgssaveloadheader_decls.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSSaveLoadManager.h"
#include "../../../../include/NiPixelData.h"

struct SaveContentDescriptor
{
    unsigned long DeviceID;
    unsigned long dwContentType;
    char szDisplayName[256];
    char szFileName[42];
    char _pad_132[2];
};
typedef char _sizecheck__XCONTENT_DATA[sizeof(SaveContentDescriptor) == 308 ? 1 : -1];

__declspec(dllimport) int __stdcall DeleteFileA(const char*);

// @fnv 0x00850030
// src: XBOX_PDB 0x00850030
SaveLoadFile* BGSSaveLoadManager::OpenSaveFile_00850030(const char* apFileName, int abWrite, int aeBufferType, int aiDeviceID)
{
    unsigned int ibufferSize;
    SaveLoadFile* pfile;
    char pfullFileName[260];

    // The original entry point reads only the low byte of the shared integer parameter.
    GetFullPath(const_cast<char*>(apFileName), pfullFileName, *reinterpret_cast<bool*>(&abWrite));

    if (aeBufferType == 0)
        ibufferSize = 0x10000;
    else if (aeBufferType == 1)
        ibufferSize = 0x200000;
    else
        ibufferSize = 0x10000;

    if (*reinterpret_cast<bool*>(&abWrite))
    {
        if (FUN_00ecbf05(pfullFileName, 0) != -1)
            DeleteFileA(pfullFileName);
    }

    pfile = (SaveLoadFile*)BGSSaveLoadFile_Create(pfullFileName, *reinterpret_cast<bool*>(&abWrite), ibufferSize);
    ((BGSLoadGameBuffer*)pfile)->BGSSaveLoadFile_SetSaveFileName((SaveLoadFile*)apFileName);
    ((BGSLoadGameBuffer*)pfile)->BGSSaveLoadFile_Open();

    return pfile;
}

void* _fnv_zlib_memset(void* dst, int val, unsigned int size);

// @fnv 0x0084d8c0
int __cdecl ReadSaveHeader(SaveLoadFile* apFile)
{
    BGSLoadGameBuffer* apLoadGameBuffer;
    int iversion;
    unsigned int iresult;
    char pheaderString[260];
    pheaderString[0] = 0;
    _fnv_zlib_memset(&pheaderString[1], 0, sizeof(pheaderString) - 1);
    iresult = apFile->Read(pheaderString, strlen(DAT_011a2224));
    if (iresult == 0)
        return 0;
    if (BSstrcmp(pheaderString, DAT_011a2224))
        return -1;

    BGSLoadGameBuffer loadBuffer;
    loadBuffer.ReadAndVerifySize(apFile);
    apLoadGameBuffer = &loadBuffer;
    iversion = 0;
    apLoadGameBuffer->ReadDataBlock(&iversion, 4);
    if (iversion == 0x30)
    {
        char* pdata4 = apLoadGameBuffer->GetCombinedValue();
        if (pdata4[4] == '|')
        {
        }
        else
        {
            char lname[64];
            apLoadGameBuffer->ReadDataBlock(lname, 0x40);
        }
    }
    else
    {
        char lname[64];
        apLoadGameBuffer->ReadDataBlock(lname, 0x40);
    }
    unsigned int iscreenshotWidth2 = 0;
    unsigned int iscreenshotHeight = 0;
    apLoadGameBuffer->ReadDataBlock(&iscreenshotWidth2, 4);
    apLoadGameBuffer->ReadDataBlock(&iscreenshotHeight, 4);
    apFile->AdvancePosition(iscreenshotWidth2 * iscreenshotHeight * 3);
    return iversion;
}

struct HeaderFile
{
    void WriteToFile(const void*, unsigned int);
    const char* FUN_006815c0();
};
struct HeaderBuffer
{
    void* data;
    unsigned int unk04, unk08, unk0C, unk10;
    HeaderBuffer();
    ~HeaderBuffer();
    void FUN_00865e50(const void*, unsigned int, bool);
    void FUN_00865e70(const char*, bool);
    void FUN_00865c40(HeaderFile*);
};
struct HeaderPlayer
{
    const char* TESObjectREFR_GetFullName();
    unsigned short GetLevel_0087f9f0();
};
struct HeaderSetting
{
    const char* FUN_00403df0();
    unsigned char* FUN_00408d60();
};
extern BGSSaveLoadManager* DAT_011de134;
// Queries absent from the shared header; one fastcall argument preserves the original ECX receiver.
unsigned int __fastcall GetSaveHeaderVersion(BGSSaveLoadManager* manager);
unsigned int __fastcall GetSaveHeaderNumber(BGSSaveLoadManager* manager);
extern HeaderPlayer* DAT_011dea3c;
extern HeaderSetting DAT_011c3cb4, DAT_011de2fc, DAT_011c3f74;
void* ourMemset(void*, int, unsigned int);
void* FUN_00ec61c0(void*, int, unsigned int);
int FUN_00406d50(char*, unsigned int, const char*);
int FUN_00406d30(char*, unsigned int, const char*);
int Renderer_GetScreenHeight();
int Renderer_GetScreenWidth();
NiPixelData* ScreenShot_TakeSaveGameScreenShot(int*, int*, const char*);
const char* TESActorBaseData_GetKarmicTitle(HeaderPlayer*);
// @fnv 0x0084d4b0
// src: COMMUNITY 0x0084d4b0
void BGSSaveLoadHeader_SaveHeader(HeaderFile* file)
{
    file->WriteToFile(DAT_011a2224, strlen(DAT_011a2224));
    HeaderBuffer buffer_;
    HeaderBuffer* stream = &buffer_;
    unsigned int version = GetSaveHeaderVersion(DAT_011de134);
    stream->FUN_00865e50(&version, 4, false);
    char playerName3[64];
    ourMemset(playerName3, 0, 64);
    FUN_00406d50(playerName3, 64, DAT_011c3cb4.FUN_00403df0());
    stream->FUN_00865e50(playerName3, 64, false);
    bool wide6 = (double)Renderer_GetScreenHeight() / Renderer_GetScreenWidth() < 0.75;
    int height5 = wide6 ? 512 : 432;
    int width2 = wide6 ? 512 : 432;
    char screenshotPath_2[260];
    screenshotPath_2[0] = 0;
    FUN_00ec61c0(screenshotPath_2 + 1, 0, 259);
    if (*DAT_011de2fc.FUN_00408d60())
    {
        FUN_00406d30(screenshotPath_2, 260, DAT_011c3f74.FUN_00403df0());
        FUN_00406d50(screenshotPath_2, 260, file->FUN_006815c0());
        FUN_00406d50(screenshotPath_2, 260, ".bmp");
    }
    NiPixelData* pixels = 0;
    if (!DAT_011de134->InterfaceManager_GetMenuMode())
        pixels = ScreenShot_TakeSaveGameScreenShot(&height5, &width2, screenshotPath_2);
    else
    {
        float aspect3 = (double)Renderer_GetScreenHeight() / Renderer_GetScreenWidth();
        width2 = (int)(width2 * aspect3);
    }
    stream->FUN_00865e50(&height5, 4, false);
    stream->FUN_00865e50(&width2, 4, false);
    unsigned int numberVal = GetSaveHeaderNumber(DAT_011de134);
    stream->FUN_00865e50(&numberVal, 4, false);
    stream->FUN_00865e70(DAT_011dea3c->TESObjectREFR_GetFullName(), false);
    stream->FUN_00865e70(TESActorBaseData_GetKarmicTitle(DAT_011dea3c), false);
    unsigned int level2 = DAT_011dea3c->GetLevel_0087f9f0();
    stream->FUN_00865e50(&level2, 4, false);
    char location9[260];
    DAT_011de134->CopyPlayerName(location9);
    stream->FUN_00865e70(location9, false);
    char time[260];
    DAT_011de134->FormatPlayTime(time, true);
    stream->FUN_00865e70(time, false);
    buffer_.FUN_00865c40(file);
    if (!DAT_011de134->InterfaceManager_GetMenuMode())
        file->WriteToFile(pixels->NiPixelData_GetPixels(0, 0), height5 * width2 * 3);
    else
        file->WriteToFile(0, height5 * width2 * 3);
    delete pixels;
}

extern const NiPixelFormat kScreenshotPixelFormat;

struct ScreenshotTexFormat
{
    ScreenshotTexFormat();
    int iPixelLayout;
    int iAlphaFormat;
    int iMipMapped;
};

struct ScreenshotName
{
    ScreenshotName(const char* str);
    ~ScreenshotName();
    operator const char*() const;
    const char* pString;
};

NiTexture* __cdecl CreateScreenshotTexture(NiPixelData* pixelData, const char* name,
                                           ScreenshotTexFormat* format);

// Seeks to offset in file, reads width*height*3 bytes into a new NiPixelData, and creates a texture named BGSSaveLoadHeader_Screenshot.
// @fnv 0x0084dda0
NiTexture* __cdecl LoadScreenshotTexture(SaveLoadFile* file, unsigned int offset, unsigned int width,
                                         unsigned int height)
{
    file->SetFilePosition(offset);
    NiPixelFormat format = kScreenshotPixelFormat;
    NiPixelData* pixelData2 = new NiPixelData(width, height, format, 1, 1);
    file->Read(pixelData2->NiPixelData_GetPixels(0, 0), width * height * 3);
    ScreenshotTexFormat aTexFormat;
    aTexFormat.iPixelLayout = 2;
    aTexFormat.iMipMapped = 0;
    aTexFormat.iAlphaFormat = 0;
    return CreateScreenshotTexture(pixelData2, ScreenshotName("BGSSaveLoadHeader_Screenshot"), &aTexFormat);
}
