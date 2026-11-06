#ifndef BSSYSTEMUTILITY_PRIVATE_H
#define BSSYSTEMUTILITY_PRIVATE_H


class IdleSystem
{
  public:
    static IdleSystem& GetRandomGenerator();
    void Idle();
    static void Initialize();
};

class NetworkSystemUtility
{
  public:
    static NetworkSystemUtility& GetRandomGenerator();
    void UpdateSteamRunningFlag();
};

class DownloadableContentManager
{
  public:
    static DownloadableContentManager& GetRandomGenerator();
    void FUN_00af2c80();
};

class FNVVTableSlot4
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
};

class FNVVTableSlot8
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
};

class FNVVTableSlot8Args
{
  public:
    virtual void vfn_00();
    virtual void vfn_04(const char*, unsigned int);
    virtual void vfn_08();
};

void FUN_00af2370();
void FUN_00af2360();
void FUN_00af2750();
void FUN_00af2760();
void FUN_00af2d30();
FNVVTableSlot8* FUN_00af3850();
FNVVTableSlot8Args* GetStaticSlot();
FNVVTableSlot8* FUN_00af2e50();
FNVVTableSlot8* GetVTableSlot8();
FNVVTableSlot8* FUN_00af34f0();
FNVVTableSlot8* GetInitObj();

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" void __cdecl fnv_CopyFilePath(char*, unsigned int, const char*, unsigned int);

#endif
