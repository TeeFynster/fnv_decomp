// src/unmapped/debugtextmedia.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextmedia.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

namespace fnv_00852080 {
// FUN_00852080 v3 - full Handle-scope transcription (worker4)
class GlobalObject_0045cf30
{
  public:
    unsigned char* FUN_00408d60();
    void Setting_SetValueB(int v);
};
extern GlobalObject_0045cf30 g_011de308;
int __cdecl FUN_00406d50(char* dst, unsigned int sz, const char* src);
int __cdecl BSstrlen(char* s);
extern const char saveExtension[];
int __cdecl FUN_004564f0(char* a, const char* b, int n);
int __cdecl BSsprintf(char* buf, unsigned int sz, const char* fmt, ...);
void* __cdecl operator new(unsigned int n);

class Finder
{
  public:
    Finder(char* p);
    ~Finder();
    void FUN_00b00720(unsigned char* flag29);
    bool FUN_00852700();
    char* FUN_00436aa0();
    void* searchHandle;
    unsigned int attributes;
    unsigned int creationLow, creationHigh;
    unsigned int accessLow, accessHigh;
    unsigned int writeLow, writeHigh;
    unsigned int sizeHigh, sizeLow;
    unsigned int reserved0, reserved1;
    char filename[260];
    char alternateFilename[14];
    char path[260];
    int status;
    int unk24c;
    int unk250;
    int unk254;
};
class Handle
{
  public:
    Handle(char* name, int a, int b, bool c);
    ~Handle();
    int Modelloader_GetReferencedThis();
    void BSSystemFile_GetSize(int* pair);
    int FUN_008526d0(int v);
    void* file;
    int mode;
    int flags;
    bool option;
    int unk10;
};
class SaveData
{
  public:
    SaveData(const char* name, int z, int v);
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
};
class InfoLike
{
  public:
    int FUN_008d85e0(int a, int b, int* pair);
    int FUN_008d85e0();
    void* GetNavMeshInfo_0068efb0();
    void BSSaveDataSystemUtilityFile_SetDirectoryName(const char* s);
    void BSSaveDataSystemUtilityFile_SetSubTitle(char* s);
    void BSSaveDataSystemUtilityFile_SetDetail(char* s);
    void BSSaveDataSystemUtilityFile_SetIconImage(int a, int b, int c);
    void BSSaveDataSystemUtilityFile_SetBackgroundImagePath(const char* s);
    void FUN_00852060(int v);
};
class EntryLike
{
  public:
    EntryLike(char* name, int z);
    ~EntryLike();
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

    char* BGSSaveLoadFileEntry_GetPlayTime();
    char* GetPlayerTitle();
    char* BGSSaveLoadFileEntry_GetPlayerName();
    unsigned int BGSSaveLoadFileEntry_GetPlayerLevel();
    int GetScreenshotWidth();
    int GetScreenshotOffset();
    int GetScreenshotHeight();
    char* BGSSaveLoadFileEntry_GetLocation();
    void BSTaskletData_TaskYield();
};
class SingObj
{
  public:
    void* BSSystemUtility_GetMsgDialogUtility();
    void* BSSystemUtility_GetSaveDataUtility();
    bool TESRegionData_GetOverride();
};
SingObj* __cdecl FUN_00af2640();
class VCall8
{
  public:
    virtual void s0();
    virtual void s1();
    virtual int v8(char* buf, int n);
};
class VCall20
{
  public:
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual int v20(int v);
};
class GlobalObject_0040c150
{
  public:
    const char* FUN_00403df0();
};
extern GlobalObject_0040c150 g_011d3954;
extern GlobalObject_0040c150 g_011d4f78;
extern GlobalObject_0040c150 g_011d3b2c;
void __cdecl FUN_0084dab0(int a, int b);
int __cdecl BSprintf(const char* fmt, char* buf);
void __cdecl BSSleep(int ms);
void BGSSaveLoadManager_SysUtilSaveCompleteCallback();

union SizePair
{
    __int64 value;
    struct
    {
        int low;
        int high;
    };
};

class ThisCls
{
  public:
    void* m_thispad;
    void FUN_0050f9c0(int v);
    void BGSSaveLoadManager_CopySaveGames(int unused);
};

// Loops over files in the Saves directory and, for each save-extension file, reads it into a SaveData and fills an info entry for copying it to the target.
// @fnv 0x00852080
// src: COMMUNITY 0x00852080
void ThisCls::BGSSaveLoadManager_CopySaveGames(int unused)
{
    int lenTmp7;
    unsigned char settingByte16;
    char buf127[0x104];

    settingByte16 = *g_011de308.FUN_00408d60();
    g_011de308.Setting_SetValueB(0);
    FUN_00406d50(buf127, 0x104, "Saves");
    FUN_00406d50(buf127, 0x104, "/");
    Finder finder(buf127);
    unsigned char flag29;
    flag29 = 0;
    finder.FUN_00b00720(&flag29);
    while (flag29 == 0)
    {
        if (finder.FUN_00852700() == 1)
        {
            lenTmp7 = BSstrlen(finder.FUN_00436aa0());
            if (FUN_004564f0(finder.FUN_00436aa0() + lenTmp7 - 4, saveExtension, 4) == 0)
            {
                {
                    char buf410[0x100];
                    EntryLike* entry3;
                    char buf313[0x108];
                    void* info8;
                    SizePair kPair1a12;
                    int val4a8;
                    SizePair pair2a;
                    char buf2[0x108];
                    BSsprintf(buf2, 0x104, "%s%s", buf127, finder.FUN_00436aa0());
                    Handle handle20(buf2, 0, 0, 0);
                    if (handle20.Modelloader_GetReferencedThis() == 0)
                    {
                        kPair1a12.low = 0;
                        kPair1a12.high = 0;
                        handle20.BSSystemFile_GetSize(&kPair1a12.low);
                        val4a8 = (int)new SaveData("SaveData", 0, kPair1a12.low);
                        info8 = ((InfoLike*)(void*)val4a8)->GetNavMeshInfo_0068efb0();
                        pair2a.low = 0;
                        pair2a.high = 0;
                        handle20.FUN_008526d0(
                            ((InfoLike*)info8)->FUN_008d85e0(kPair1a12.low, kPair1a12.high, &pair2a.low));
                        if (handle20.Modelloader_GetReferencedThis() == 0)
                        {
                            BSsprintf(buf313, 0x104, "Copying the save game file to the target...\n\n");
                            FUN_00406d50(buf313, 0x104, buf2);
                            ((VCall8*)FUN_00af2640()->BSSystemUtility_GetMsgDialogUtility())->v8(buf313, 1000);
                            entry3 = new EntryLike(buf2, 0);
                            FUN_0084dab0(val4a8, (int)entry3);
                            entry3->BSTaskletData_TaskYield();
                            ((InfoLike*)info8)->BSSaveDataSystemUtilityFile_SetDirectoryName("-SAVE-");
                            if (entry3->BGSSaveLoadFileEntry_GetLocation() != 0 && BSstrlen(entry3->BGSSaveLoadFileEntry_GetLocation()) != 0)
                                ((InfoLike*)info8)->BSSaveDataSystemUtilityFile_SetSubTitle(entry3->BGSSaveLoadFileEntry_GetLocation());
                            else
                                ((InfoLike*)info8)->BSSaveDataSystemUtilityFile_SetSubTitle("Location");
                            BSsprintf(
                                buf410, 0x100, "%s\n%s %d: %s\n%s: %s",
                                entry3->BGSSaveLoadFileEntry_GetPlayerName() ? entry3->BGSSaveLoadFileEntry_GetPlayerName() : (char*)g_011d4f78.FUN_00403df0(),
                                g_011d3b2c.FUN_00403df0(), entry3->BGSSaveLoadFileEntry_GetPlayerLevel(),
                                entry3->GetPlayerTitle() ? entry3->GetPlayerTitle() : "-", g_011d3954.FUN_00403df0(),
                                entry3->BGSSaveLoadFileEntry_GetPlayTime() ? entry3->BGSSaveLoadFileEntry_GetPlayTime() : (char*)g_011d3954.FUN_00403df0());
                            ((InfoLike*)info8)->BSSaveDataSystemUtilityFile_SetDetail(buf410);
                            ((InfoLike*)info8)
                                ->BSSaveDataSystemUtilityFile_SetIconImage(entry3->GetScreenshotWidth(), entry3->GetScreenshotHeight(),
                                               ((InfoLike*)info8)->FUN_008d85e0() + entry3->GetScreenshotOffset());
                            ((InfoLike*)info8)->BSSaveDataSystemUtilityFile_SetBackgroundImagePath("DATA/SYSUTIL/SAVEBACK.PNG");
                            ((InfoLike*)info8)->FUN_00852060((int)&BGSSaveLoadManager_SysUtilSaveCompleteCallback);
                            delete entry3;
                            FUN_0050f9c0(val4a8);
                            ((VCall20*)FUN_00af2640()->BSSystemUtility_GetSaveDataUtility())->v20((int)info8);
                            while (((SingObj*)FUN_00af2640()->BSSystemUtility_GetSaveDataUtility())->TESRegionData_GetOverride() == 1)
                                BSSleep(10);
                        }
                        else
                        {
                            BSprintf(
                                "BGSSaveLoadManager::CopySaveGamesFromHost failed to read the save game file buffer %s.\n",
                                buf2);
                        }
                    }
                    else
                    {
                        BSprintf(
                            "BGSSaveLoadManager::CopySaveGamesFromHost failed to open the save game file %s.\n", buf2);
                    }
                }
            }
        }
    next_iter:
        finder.FUN_00b00720(&flag29);
    }
    g_011de308.Setting_SetValueB(settingByte16);
}
}  // namespace fnv_00852080
