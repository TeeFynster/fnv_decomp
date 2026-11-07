// bssystem/bsfilecache.cpp: BSFileCache, StandIn (15 functions)

#include "bsfilecache.h"
#include "../../include/MemoryManager.h"

// @fnv 0x00b00f20
BSFileCache::BSFileCache()
{
    m_uiCacheIndex = 0;
    m_pFileCacheArray = 0;
    m_pCacheSyncObject = 0;
    m_eCacheState = FILE_CACHING_IN_PROGRESS;
    m_pActiveFileCache = 0;
    m_uiCacheEntryCount = 0;
    m_uiCachedBytes = 0;
    m_uiCacheByteCount = 0;
    m_uiCacheCapacity = 0;
    m_iCacheEntryIndex = -1;
    m_uiCacheLimit = 0;
    m_uiCacheRequestCount = 0;
    m_uiReferenceCount = 1;
    m_uiCacheFlags = 0;
    m_iCacheCount = 0;
    m_eDVDLayer = DVD_LAYER_FRONT;
    m_bCacheEnabled = false;
    m_bCacheReadPending = false;
    m_bCacheInitialized = false;
    m_iFileSize = 0;
    m_uiCacheOffset = 0;
    m_uiCacheBufferCount = 2;
    m_pfnCacheStatus = 0;
    m_pfnCacheProgress = 0;
}

struct FUN_00b011b0_shell : public BSFileCache
{
    bool BSWin32FileCache_IsFileCached(int);
};

struct VT_00b011b0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int);
};
struct ST_00b011b0
{
    bool BSWin32FileCache_IsFileCached_0(int);
};
// Calls v5 on the argument, then forwards the result to FUN_00b011e0 and returns its bool result.
// @fnv 0x00b011b0
// src: COMMUNITY 0x00b011b0
bool FUN_00b011b0_shell::BSWin32FileCache_IsFileCached(int a)
{
    return ((ST_00b011b0*)this)->BSWin32FileCache_IsFileCached_0(((VT_00b011b0*)this)->v5(a));
}

struct FUN_00b01020
{
    virtual ~FUN_00b01020();
};
// @fnv 0x00b01020
FUN_00b01020::~FUN_00b01020()
{}

struct Unk00b01040
{
    void CallVirtualWithField38();
};
struct VBase
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11(int, int, int, int);
};
// Calls the virtual f11 on this with arguments 0, the int at offset 0x38, 1 and 0.
// @fnv 0x00b01040
void Unk00b01040::CallVirtualWithField38()
{
    ((VBase*)this)->f11(0, *(int*)((char*)this + 0x38), 1, 0);
}

struct FUN_00b01070_Class
{
    void nullsub_316();
};
// @fnv 0x00b01070
// src: COMMUNITY 0x00b01070
void FUN_00b01070_Class::nullsub_316()
{}

struct E00b011e0
{
    int pad0;
    int pad1;
    int pad2;
    int v;
};
struct M00b011e0
{
    int pad;
    E00b011e0** arr;
};
struct C00b011e0
{
    char _0[0x24];
    int cnt;
    char _1[0x28];
    M00b011e0* mid;
    bool BSWin32FileCache_IsFileCached_0(int idx);
};
// Returns true when idx is within cnt and the entry at mid->arr[idx] has v equal to 2; otherwise false.
// @fnv 0x00b011e0
// src: COMMUNITY 0x00b011e0
bool C00b011e0::BSWin32FileCache_IsFileCached_0(int aiIndex)
{
    if (aiIndex < 0 || aiIndex >= cnt)
        return false;
    return mid->arr[aiIndex]->v == 2;
}

extern int DAT_011ad028;
extern int DAT_011ad02c;

struct FUN_00b012f0_shell
{
    void BSFileCache_SetFileCacheList(int param_1, int param_2);
};

// @fnv 0x00b012f0
// src: COMMUNITY 0x00b012f0
void __thiscall FUN_00b012f0_shell::BSFileCache_SetFileCacheList(int aiValue1, int aiValue2)
{
    DAT_011ad028 = aiValue1;
    DAT_011ad02c = aiValue2;
}

struct FUN_00b01020_Holder
{
    void FUN_00b01020();
};
extern MemoryManager g_memoryManager;
struct FUN_00b01310_shell
{
    void* FUN_00b01310(unsigned int flags);
};
// Calls FUN_00b01020 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00b01310
void* FUN_00b01310_shell::FUN_00b01310(unsigned int flags)
{
    ((FUN_00b01020_Holder*)this)->FUN_00b01020();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct FUN_00b01340_Shell
{
    int BSFileCache_ParseCachedFileList(const char* apFileList, unsigned int aiCurrentPriority);
};
// @fnv 0x00b01340
// src: COMMUNITY 0x00b01340
int FUN_00b01340_Shell::BSFileCache_ParseCachedFileList(const char* apFileList, unsigned int aiCurrentPriority)
{
    return 0;
}

struct FUN_00b01350_shell
{
    bool __thiscall _retn_0_(void* apCachedFile);
};

// @fnv 0x00b01350
// src: COMMUNITY 0x00b01350
bool __thiscall FUN_00b01350_shell::_retn_0_(void* apCachedFile)
{
    return false;
}

struct FUN_00b01360_Cls
{
    void BSFileCache_WaitForFileCachingToFinish(int a, int b, int c, int d);
};
// @fnv 0x00b01360
// src: COMMUNITY 0x00b01360
void FUN_00b01360_Cls::BSFileCache_WaitForFileCachingToFinish(int a, int b, int c, int d)
{}

struct StandIn
{
    void ClearPointerAt60();
};
// @fnv 0x00b01370
void StandIn::ClearPointerAt60()
{
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x60) = 0;
}

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long ulMilliseconds);

class B01130Task
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    bool m_bTaskActive;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int m_iFadeIndex;
    void* m_pvThread;

    void BSFileCache_ForcePauseAndWaitForIdle();
};

// @fnv 0x00b01130
// src: COMMUNITY 0x00b01130
void B01130Task::BSFileCache_ForcePauseAndWaitForIdle()
{
    if (!m_pvThread)
        return;
    if (m_iFadeIndex == 1 || m_iFadeIndex == 2)
        m_iFadeIndex = 3;
    if ((bool)((m_iFadeIndex == 2 || m_iFadeIndex == 3) ? 1 : 0))
    {
        while (!m_bTaskActive)
            Sleep(10);
    }
}

struct S : public BSFileCache
{
    void WaitWhilePaused();
};
// @fnv 0x00b01080
void S::WaitWhilePaused()
{
    while ((bool)((m_eCacheState == FILE_CACHING_PAUSED || m_eCacheState == FILE_CACHING_FORCE_PAUSED) ? 1 : 0))
    {
        m_bCacheInitialized = true;
        Sleep(50);
    }
    m_bCacheInitialized = false;
}

struct FUN_00b010d0_cls : public BSFileCache
{
    void ProcessEntries_00b010d0();
};

// @fnv 0x00b010d0
// src: GUESS 0x00b010d0 (confidence: low)
void FUN_00b010d0_cls::ProcessEntries_00b010d0()
{
    if (m_eCacheState == FILE_CACHING_IN_PROGRESS)
    {
        m_eCacheState = FILE_CACHING_PAUSED;
    }
    if ((bool)((m_eCacheState == FILE_CACHING_PAUSED || m_eCacheState == FILE_CACHING_FORCE_PAUSED) ? 1 : 0))
    {
        while (m_bCacheInitialized == 0)
        {
            Sleep(10);
        }
    }
}
