#pragma once

class FileCache;
template <class T, unsigned int Growth> class BSSimpleArray;

enum DVD_LAYER
{
    DVD_LAYER_FRONT = 0,
    DVD_LAYER_BACK = 1
};

enum FILE_CACHE_STATE
{
    FILE_CACHING_DISABLED = 0,
    FILE_CACHING_IN_PROGRESS = 1,
    FILE_CACHING_PAUSED = 2,
    FILE_CACHING_FORCE_PAUSED = 3,
    FILE_CACHING_FINISHED = 4
};

class BSFileCache
{
public:
    BSFileCache();
    virtual ~BSFileCache();
    virtual void vf01(int);
    virtual void vf02();
    virtual int vf03(const char* apFileList, unsigned int aiCurrentPriority);
    virtual void vf04(int);
    virtual int vf05(int);
    virtual void vf06(void*, int);
    virtual bool vf07(void* apCachedFile);
    virtual void vf08(int);
    virtual void vf09();
    virtual void vf10(int);
    virtual void vf11(int, int, int, int);
    virtual void vf12();
    virtual bool vf13(void* apCachedFile);
    virtual void vf14();
    virtual void ClearPointerAt60();

    static BSFileCache& GetRandomGenerator();
    static char* ms_pcCachePath;
    static const char* sEssentialFileCacheList;
    static const char* sUnessentialFileCacheList;

    FileCache* m_pActiveFileCache;
    unsigned int m_uiCacheEntryCount;
    unsigned int m_uiCachedBytes;
    unsigned int m_uiCacheLimit;
    unsigned int m_uiCacheByteCount;
    unsigned int m_uiCacheCapacity;
    unsigned int m_uiCacheRequestCount;
    unsigned int m_uiCacheFlags;
    unsigned int m_uiCacheIndex;
    int m_iCacheEntryIndex;
    unsigned int m_uiReferenceCount;
    int m_iCacheCount;
    int m_iFileSize;
    int m_iFilePosition;
    int m_iCachePosition;
    DVD_LAYER m_eDVDLayer;
    bool m_bCacheEnabled;
    bool m_bCacheReadPending;
    bool m_bCacheWritePending;
    bool m_bCacheInitialized;
    unsigned int m_uiCacheOffset;
    unsigned int m_uiCacheBufferCount;
    BSSimpleArray<FileCache*, 1024>* m_pFileCacheArray;
    void (__cdecl* m_pfnCacheProgress)(const char*);
    void (__cdecl* m_pfnCacheStatus)(bool);
    volatile FILE_CACHE_STATE m_eCacheState;
    void* m_pCacheSyncObject;
};
