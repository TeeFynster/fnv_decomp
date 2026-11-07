// bssystemutilities/console/bsdlcsystemutility_console.cpp: DownloadableContentManager, BSSystemUtility, OwnQ (11 functions)

#include <stddef.h>
#include "../../../include/BSSystemUtility.h"
#include "../../../include/BSSimpleList.h"
#include "../../../include/MemoryManager.h"

// No shared DownloadableContentManager definition is available yet.
class ContentMountRecord;
class DownloadableContentEntry;
class DownloadableContentInfo;
class DownloadableContentManager
{
  public:
    typedef void(__cdecl* MOUNT_CALLBACK)(unsigned int, unsigned int, bool, const ContentMountRecord*);
    unsigned int m_uiContentCount;
    DownloadableContentEntry* m_pFirstService;
    DownloadableContentInfo* m_pSecondService;
    BSSimpleList<ContentMountRecord*> m_kContentEntries;
    BSSimpleList<ContentMountRecord*> m_kMountedPackages;
    BSSimpleList<char*> m_kMountedPackageNames;
    static DownloadableContentManager& GetRandomGenerator();
    bool IsDLCAvailable();
    bool IsContentAvailable();
    void UnmountDLC();
    unsigned int MountDownloadableContent(unsigned int userIndex, MOUNT_CALLBACK callback);
};

// @fnv 0x004c69f0
bool DownloadableContentManager::IsDLCAvailable()
{
    return IsContentAvailable();
}

// @fnv 0x005dfa10
DownloadableContentManager& BSSystemUtility::QDLCUtility()
{
    return DownloadableContentManager::GetRandomGenerator();
}

// @fnv 0x00af2b10
unsigned int DownloadableContentManager::MountDownloadableContent(unsigned int userIndex, MOUNT_CALLBACK callback)
{
    UnmountDLC();
    struct MountProgress
    {
        BSSimpleList<ContentMountRecord*>* pkList;
        unsigned int uiIndex;
    } kProgress;
    kProgress.pkList = &m_kContentEntries;
    kProgress.uiIndex = 0;
    struct ContentCount
    {
        unsigned int ItemUpdateArray;
        BSSimpleList<ContentMountRecord*>* pkItem;
        unsigned int uiNumValid;
    } kCount;
    kCount.ItemUpdateArray = 0;
    kCount.pkItem = &m_kContentEntries;
    while (kCount.pkItem)
    {
        if (kCount.pkItem->m_item)
            ++kCount.ItemUpdateArray;
        kCount.pkItem = kCount.pkItem->m_pkNext;
    }
    kCount.uiNumValid = kCount.ItemUpdateArray;
    if (callback)
    {
        while (kProgress.pkList &&
               !static_cast<unsigned char>((kProgress.pkList->m_pkNext == 0 && kProgress.pkList->m_item == 0) ? 1 : 0))
        {
            callback(kProgress.uiIndex++, kCount.uiNumValid - 1, true, kProgress.pkList->m_item);
            kProgress.pkList = kProgress.pkList->m_pkNext;
        }
        callback(-1, -1, false, 0);
        return 0;
    }
    {
        struct ContentTotal
        {
            unsigned int uiTotal;
            BSSimpleList<ContentMountRecord*>* pkCurrent;
        } kTotal;
        kTotal.uiTotal = 0;
        kTotal.pkCurrent = &m_kContentEntries;
        while (kTotal.pkCurrent)
        {
            if (kTotal.pkCurrent->m_item)
                ++kTotal.uiTotal;
            kTotal.pkCurrent = kTotal.pkCurrent->m_pkNext;
        }
        return kTotal.uiTotal;
    }
}

// Zeroes the object's first three words and clears three list nodes at offsets 0xc, 0x14 and 0x1c, then returns self.
// @fnv 0x00af27c0
// src: XBOX_PDB 0x00af27c0
DownloadableContentManager* __fastcall BSDLCSystemUtility_BSDLCSystemUtility(DownloadableContentManager* self)
{
    *(unsigned int*)((char*)self + 0) = 0;
    *(unsigned int*)((char*)self + 4) = 0;
    *(unsigned int*)((char*)self + 8) = 0;
    BSSimpleList<void*>* a = (BSSimpleList<void*>*)((char*)self + 0xc);
    a->m_item = 0;
    a->m_pkNext = 0;
    BSSimpleList<void*>* b = (BSSimpleList<void*>*)((char*)self + 0x14);
    b->m_item = 0;
    b->m_pkNext = 0;
    BSSimpleList<void*>* c = (BSSimpleList<void*>*)((char*)self + 0x1c);
    c->m_item = 0;
    c->m_pkNext = 0;
    return self;
}

extern MemoryManager g_memoryManager;
struct FUN_00af2850
{
    ~FUN_00af2850();
    void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
    char pad[0x24];
};
extern FUN_00af2850* DAT_011f7244;
// Deletes the global object pointed to by DAT_011f7244 and clears the pointer.
// @fnv 0x00af2760
// src: GUESS 0x00af2760 (confidence: medium)
void __cdecl Object_ClearGlobalObject()
{
    if (DAT_011f7244)
    {
        delete DAT_011f7244;
        DAT_011f7244 = 0;
    }
}

struct S
{
    bool InvokeCallback(int, void(__cdecl*)(int, int, int), int);
};
// @fnv 0x00af28d0
bool S::InvokeCallback(int aiUnused, void(__cdecl* b)(int, int, int), int aiValue)
{
    b(0, 0, aiValue);
    return true;
}

// @fnv 0x00af2c20
// src: COMMUNITY 0x00af2c20
void __fastcall nullsub_(int ecx)
{}

namespace fnv_00af2850 {
struct List_009e03e0
{
    void RemoveAll();
    ~List_009e03e0()
    {
        RemoveAll();
    }
};

struct BSHelper
{
    char _pad[8];
    void RemoveAll();
    ~BSHelper()
    {
        RemoveAll();
    }
};

struct A60Helper
{
    void __thiscall ClearItems(int);
};

struct FUN_00af2850
{
    char _pad0[0xc];
    BSHelper m0;
    BSHelper m1;
    List_009e03e0 m2;
    ~FUN_00af2850();
};

// @fnv 0x00af2850
FUN_00af2850::~FUN_00af2850()
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
    reinterpret_cast<A60Helper*>(this)->ClearItems(0);
}
}  // namespace fnv_00af2850

namespace fnv_00af2940 {
struct SaveContentDescriptor
{
    unsigned long DeviceID;
    unsigned long dwContentType;
    char szDisplayName[256];
    char szFileName[42];
    char _pad_132[2];
};
typedef char _sizecheck__XCONTENT_DATA[sizeof(SaveContentDescriptor) == 308 ? 1 : -1];
struct ContentMountRecord
{
    bool IsMounted();
    void SetMounted(bool);
    void* DisplayName();
    char* FileName();
    char* RootName();
    unsigned int DeviceID();
    void* GetContentData();
    void* __vecDelDtor(unsigned int);
    SaveContentDescriptor m_kContentData;
    char* m_pRootName;
    bool m_bMounted;
    char _pad_139[3];
};
typedef char _sizecheck_BSContentPackage[sizeof(ContentMountRecord) == 316 ? 1 : -1];
struct FUN_00af2940_shell : public DownloadableContentManager
{
    unsigned int AddInstalledDlcPackages(unsigned int, unsigned int);
};

class ISteamApps
{
  public:
    virtual bool v00();
    virtual bool v04();
    virtual bool v08();
    virtual bool v0c();
    virtual bool v10();
    virtual bool v14();
    virtual bool v18();
    virtual bool BIsDlcInstalled(unsigned int);
};
extern "C" __declspec(dllimport) ISteamApps* __cdecl SteamApps();
struct DLCEntry_00af2940
{
    unsigned int appId;
    unsigned int name;
};
extern DLCEntry_00af2940 DAT_011accb8[];
struct FUN_00b008b0
{
    __forceinline static void* operator new(unsigned int s)
    {
        return g_memoryManager.Allocate(s);
    }
    __forceinline static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
    FUN_00b008b0(unsigned int);
    int a;
    int b;
};
struct FUN_00af2420_class
{
    void* item;
    FUN_00af2420_class* next;
    void FUN_00af25b0(void** apItem)
    {
        FUN_00af2420_class* pnode = this;
        FUN_00af2420_class* plast = 0;
        while (pnode)
        {
            plast = pnode;
            pnode = pnode->next;
        }
        if (plast->item)
        {
            plast->next = new FUN_00af2420_class;
            plast->next->item = *apItem;
            plast->next->next = 0;
        }
        else
            plast->item = *apItem;
    }
};
struct FUN_00af2a60_obj
{
    void ClearItems(int);
};
// @fnv 0x00af2940
unsigned int FUN_00af2940_shell::AddInstalledDlcPackages(unsigned int anPlayerIndex, unsigned int anDevice)
{
    ((FUN_00af2a60_obj*)this)->ClearItems(1);
    unsigned int uiInstalledCount = 0;
    if (SteamApps())
    {
        for (unsigned long uiIndex = 0; DAT_011accb8[uiIndex].appId != -1; uiIndex++)
        {
            if (SteamApps()->BIsDlcInstalled(DAT_011accb8[uiIndex].appId))
            {
                uiInstalledCount++;
                void* package = new FUN_00b008b0(DAT_011accb8[uiIndex].name);
                ((FUN_00af2420_class*)((char*)this + 0xc))->FUN_00af25b0(&package);
            }
        }
    }
    return uiInstalledCount;
}
}  // namespace fnv_00af2940

extern "C" __declspec(dllimport) void* __cdecl SteamFriends();
extern "C" __declspec(dllimport) void* __cdecl SteamUtils();

struct SteamUtilsObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};

struct SteamFriendsObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual int v22(int);
};

struct FUN_00af28f0_cls
{
    int BSDLCSystemUtility_ShowMarketplace(int a1);
};

// If both SteamFriends and SteamUtils are available, returns the friends interface's v22 called with the utils interface's v9 value.
// @fnv 0x00af28f0
// src: COMMUNITY 0x00af28f0
int FUN_00af28f0_cls::BSDLCSystemUtility_ShowMarketplace(int a1)
{
    if (SteamFriends() != 0)
    {
        if (SteamUtils() != 0)
        {
            return ((SteamFriendsObj*)SteamFriends())->v22(((SteamUtilsObj*)SteamUtils())->v9());
        }
    }
}

struct ItmQ
{
    ~ItmQ();
    void operator delete(void* p)
    {
        int aiD[3];
        g_memoryManager.Deallocate(p);
    }
};
struct NodQ
{
    ItmQ* pItem;
    NodQ* pNext;
    bool IsEmpty()
    {
        return !pNext && !pItem;
    }
};
struct LstQ
{
    NodQ kHead;
    void ProcessEntries_00ae83e0();
};
struct OwnQ
{
    int unk00, unk04, unk08;
    LstQ kList;
    void nullsub_();
    void ClearItems(bool bFlag);
};
// Optionally calls FUN_00af2c20 when bFlag is set, then deletes every item in kList and resets the list via FUN_00ae83e0.
// @fnv 0x00af2a60
void OwnQ::ClearItems(bool bFlag)
{
    if (bFlag)
        nullsub_();
    NodQ* pNode = &kList.kHead;
    while (pNode && !pNode->IsEmpty())
    {
        delete pNode->pItem;
        pNode = pNode->pNext;
    }
    kList.ProcessEntries_00ae83e0();
}
