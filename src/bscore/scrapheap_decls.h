// bscore/scrapheap_decls.h: declares ScrapHeapBuffer, ScrapHeapManager, Entry

#include "../../include/RecursiveSpinLock.h"

class ScrapHeapManager;

class ScrapHeapBuffer
{
  public:
    char* m_pHeapBase;
    char* m_pCurrentPosition;
    char* m_pBufferLimit;
    void* m_pBufferHeader;
    unsigned int m_uiBufferSize;

    ScrapHeapBuffer();
    ~ScrapHeapBuffer();
    void Init(unsigned int size);
    void Deallocate(void* memory);
    void* Allocate(unsigned int size, unsigned int alignment);
};

class ScrapHeapManager
{
  public:
    struct Entry
    {
        char* buffer;
        unsigned int size;
    };

    Entry entries[64];
    unsigned int count;
    unsigned int totalSize;
    unsigned char padding[0x18];
    RecursiveSpinLock bufferLock;

    static ScrapHeapManager& Instance();
    char* RequestBuffer(unsigned int& size);
    void ReleaseBuffer(char* buffer, unsigned int size);
    char* AllocateBuffer(unsigned int size);
    void ReleaseBufferContents(char* buffer, unsigned int offset, unsigned int size);
    void FreeBuffer(char* buffer, unsigned int size);
    void FreeTailOfBlock(char* buffer, unsigned int offset, unsigned int size);
    void RemoveEntry(unsigned int index);
};

extern MemoryManager g_memoryManager;

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* address, unsigned int size,
                                                              unsigned int allocationType, unsigned int protection);

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, unsigned int size, unsigned int freeType);
