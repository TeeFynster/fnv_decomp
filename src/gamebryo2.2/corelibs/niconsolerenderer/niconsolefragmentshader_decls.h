// gamebryo2.2/corelibs/niconsolerenderer/niconsolefragmentshader_decls.h: declares ShaderData, ShaderEntry, Device, ShaderCache

#include "../../../../include/RecursiveSpinLock.h"
template <class T> class PoolAllocatorBase
{
  public:
    struct LinkedListEntry
    {
        LinkedListEntry* next;
        LinkedListEntry* prev;
        void* data;
    };
    static LinkedListEntry* ms_pFreeList;
    static RecursiveSpinLock ms_kPoolState;
};
extern unsigned int DAT_011c5f84;
struct ShaderData
{
    char pad[108];
    unsigned int handle;
    char other;
    bool active;
};
struct ShaderEntry
{
    char pad[236];
    ShaderData* data;
};
struct Device
{
    void** vtable;
};
class ShaderCache
{
  public:
    char pad[16];
    PoolAllocatorBase<unsigned int>::LinkedListEntry* head;
    PoolAllocatorBase<unsigned int>::LinkedListEntry* tail;
    unsigned int count;
    Device* device;
    unsigned int unused;
    unsigned int initial;
    unsigned int current;
    void BindGPUProgram();
};
