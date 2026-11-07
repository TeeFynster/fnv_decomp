#include "../../../../include/NiPixelData.h"
#include "../../../../include/NiGlobalStringTable.h"
// gamebryo2.2/corelibs/nimain/niglobalstringtable_decls.h: declares NiGlobalStringTable, NiPlaybackStat, NiPlaybackTimestamp, NiPlaybackManager, NiPlaybackFile
#ifndef NIGLOBALSTRINGTABLE_DECLS_H
#define NIGLOBALSTRINGTABLE_DECLS_H

#include <string.h>

extern NiGlobalStringTable* DAT_011f42c0;
extern "C" volatile unsigned _tls_index;
extern "C" unsigned long __readfsdword(unsigned long);
#pragma intrinsic(__readfsdword)
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void* _NiMalloc(unsigned);
struct NiPlaybackStat
{
    int pad[5];
    int timestamp;
    int rest[6];
};
struct NiPlaybackTimestamp
{
    int pad;
    int timestamp;
};
class NiPlaybackManager
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual unsigned vfn_3c();
    bool GetNameByKey(const char*, char*);
    void MoviePlayer_SignalBinkOpen();
};
extern NiPlaybackManager* DAT_0126fac4;
extern NiPlaybackTimestamp DAT_0126fad4;
extern int DAT_01202800;
class NiPlaybackFile
{
  public:
    bool FindString(const char*, bool, bool, bool);
    void* handle;
    char pad[28];
    unsigned state;
};
char* FUN_00ec6380(char*, const char*);
int FUN_00ec923c(const char*, NiPlaybackStat*);
int Warning(const char*, ...);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void* __stdcall BinkOpen(const char*, unsigned);
#endif

extern "C" void* fnv_zlib_memcpy(void*, const void*, unsigned);
