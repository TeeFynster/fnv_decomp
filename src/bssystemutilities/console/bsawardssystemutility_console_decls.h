#ifndef FNV_BSAWARDSSYSTEMUTILITY_CONSOLE_DECLS_H
#define FNV_BSAWARDSSYSTEMUTILITY_CONSOLE_DECLS_H


#include "layout_support.h"
#include "MemoryManager.h"

extern MemoryManager g_memoryManager;
class ContentMountRecord;
class DownloadableContentEntry;
class DownloadableContentInfo;

class DownloadableContentManager
{
  public:
    unsigned int m_uiContentCount;
    DownloadableContentEntry* m_pFirstService;
    DownloadableContentInfo* m_pSecondService;
    BSSimpleList<ContentMountRecord*> m_kContentEntries;
    BSSimpleList<ContentMountRecord*> m_kMountedPackages;
    BSSimpleList<char*> m_kMountedPackageNames;

    DownloadableContentManager();
    static DownloadableContentManager& GetRandomGenerator();
    static __forceinline void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static __forceinline void operator delete(void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }
};

class IdleSystem
{
  public:
    BSSimpleList<unsigned char*> m_kNode;

    IdleSystem();
    ~IdleSystem();
    void Idle();
    static void Shutdown();
    static void Startup();
    static IdleSystem& GetRandomGenerator();
    static bool Initialize();
    static __forceinline void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static __forceinline void operator delete(void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }
};

FNV_STATIC_ASSERT(sizeof(DownloadableContentManager) == 36);
FNV_STATIC_ASSERT(sizeof(IdleSystem) == 8);

extern DownloadableContentManager* DAT_011f7244;
extern IdleSystem* DAT_011f7178;

template <> __forceinline bool BSSimpleList<unsigned char*>::IsEmpty()
{
    return !m_pkNext && !m_item;
}
template <> __forceinline BSSimpleList<unsigned char*>::BSSimpleList()
{
    m_item = 0;
    m_pkNext = 0;
}
template <> __forceinline BSSimpleList<unsigned char*>::~BSSimpleList()
{
    int padding[3];
    RemoveAll();
}
class SteamUserStats
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual bool SetAchievement(const char*);
    virtual void vfn_20();
    virtual void vfn_24();
    virtual bool StoreStats();
};
extern "C" __declspec(dllimport) SteamUserStats* __cdecl SteamUserStatsAccessor();
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
struct AwardData
{
    int id;
    static __forceinline void operator delete(void* pointer)
    {
        int padding[3];
        g_memoryManager.Deallocate(pointer);
    }
};
int Warning(const char*, ...);
namespace std {
class StandardLibrarySingletonObject
{
  public:
    StandardLibrarySingletonObject();
    ~StandardLibrarySingletonObject();
};
}
#endif
