#pragma once

class IMemoryHeap;
class IMemoryManagerFile;
class MemoryHeapStats;
class MemoryManagerComponent;
class MemoryManagerHelperType;
class MemoryManagerSupportType;
class ScrapHeapBuffer;

class MemoryManager
{
  public:
    bool bInitialized;
    unsigned char _pad1[1];
    unsigned short iNumHeaps;
    unsigned short iNumPhysicalHeaps;
    unsigned char _pad6[2];
    IMemoryHeap** ppHeaps;
    union
    {
        IMemoryHeap* pHeapsByContextA[66];
        struct
        {
            IMemoryHeap* unk0C;
            void* allocator;
        };
    };
    struct ThreadScrapHeapMap
    {
        unsigned char unk00[16];

        ~ThreadScrapHeapMap();
    };
    ThreadScrapHeapMap kThreadScrapHeapMap;
    IMemoryHeap** ppPhysicalHeaps;
    bool bSpecialHeaps;
    union
    {
        bool bAllowPoolUse;
        bool m_bPoolAllocationEnabled;
    };
    unsigned char _pad12A[2];
    unsigned int iSysAllocBytes;
    unsigned int iMallocBytes;
    unsigned int iMainThreadMemoryProblemPassSignal;

    ~MemoryManager();

    static MemoryManager& Instance();
    static MemoryManager& GetSingleton();
    static void ResetHeap();
    static void EnableDelayedFree();
    static void DisableDelayedFree();
    static void SetCheckMemOnFree(bool enabled);
    static bool QDelayedFreeEnabled();
    static bool QCheckMemOnFree();

    void CreatePool(unsigned int blockSize, unsigned int poolSize, char* description);
    void CreateMemoryPool(unsigned int blockSize, unsigned int poolSize, const char* description);
    void SpecifyPools();
    void FUN_00e00008(void* pointer, unsigned short type);
    void* Game_DoHeapAlloc(unsigned int size);
    bool available(int size);
    void slot0();
    void slot1();
    void slot2();
    void slot3();
    void slot4();
    void slot5();
    void slot6();
    void slot7();
    void m00();
    void m04();
    void m08();
    void m0c();
    void ReportDiagnostic();
    void unused1();
    void release(void* object, unsigned short value);
    void* Function0();
    void* Function1();
    void* Function2();
    void* Function3();
    void* Function4(int memoryType, int size);
    void* __thiscall Allocate(unsigned int size);
    void* __thiscall Allocate(unsigned int size, const char* file, const int line, const char* function);
    void* __thiscall Allocate(unsigned int size, char* file, int line, char* function);
    void* AllocatePhysical(unsigned int size, unsigned long alignment);
    void* TryAndAllocate(unsigned int size);
    void* Reallocate(void* pointer, unsigned int size);
    void* Reallocate(void* pointer, unsigned int size, char* file, int line, char* function);
    void Deallocate(void* pointer);
    void DeallocatePhysical(void* pointer, unsigned long size, unsigned long alignment);
    void _DeallocateAlias(void* pointer);
    void DeallocateAlias(void* pointer);
    void Free(void* pointer);
    void FreePointer(void* pointer, int flags);
    void freeBlock(void* pointer, int size);
    void* DoSystemAllocation(unsigned int size, bool aligned);
    void DoSystemDeallocation(void* pointer, bool aligned);
    MemoryManagerHelperType* GetContextTracker();
    MemoryManagerComponent* GetUsageTracker();
    ScrapHeapBuffer* GetGeneralAllocator();
    void Memset(void* destination, int value, unsigned int size);
    void Memcpy(void* destination, void* source, unsigned int size);
    void CheckMemoryIntegrity(bool checkAll);
    unsigned int Size(const void* pointer);
    unsigned int Size(void* pointer);
    unsigned int GetNumHeaps();
    unsigned int GetNumPhysicalHeaps();
    bool GetHeapStats(unsigned int index, bool full, MemoryHeapStats* stats);
    bool GetPhysicalHeapStats(unsigned int index, bool full, MemoryHeapStats* stats);
    bool GetDefaultHeapStats(unsigned int index, bool full, MemoryHeapStats* stats);
    int GetCalculatedMemoryUsed();
    int GetReportedMemoryUsed();
    int OutputDebugInfo(IMemoryManagerFile* file, bool full);
    int GetCount()
    {
        return iNumHeaps + iNumPhysicalHeaps;
    }
    void* GetEntryAt(unsigned int index);
    void CheckMemoryIntegrity_00aa43a0(int unused);
    void FUN_00483710();
    IMemoryHeap* GetHeapByIndex(unsigned int index);
    IMemoryHeap* GetHeapForPointer(const void* pointer);
    IMemoryHeap* GetHeapForPointer(void* pointer);
    IMemoryHeap* GetHeapForPhysicalPointer(const void* pointer);
    IMemoryHeap* GetHeapForPhysicalPointer(void* pointer);
    IMemoryHeap* GetMemHeap(MemoryManagerSupportType* context);
    void Initialize();
    void InitializeStandard();
    void InitializeHeaps();
    void RegisterMemoryManager();
    void InitializeHeapTracking();
    void ShutdownHeapTracking();
    void SetupDuplicatedPools();
    void ClearDuplicatedPools();
    unsigned int HandleAllocationFailure(IMemoryHeap* heap, int errorCode, bool* handled);
    void DumpMemoryManagerInfo();
    int OutputModuleInfoToFile(IMemoryManagerFile* file);
    int OutputPoolInfoToFile(IMemoryManagerFile* file);
    int OutputHeapInfoToFile(IMemoryManagerFile* file, bool full);
    void InitializeTrackers();
    void UpdateSystemMemoryUsage();
};
