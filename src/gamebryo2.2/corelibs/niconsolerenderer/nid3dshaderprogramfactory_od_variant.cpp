
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nid3dshaderprogramfactory_packet.h"
#include "../../../../include/NiD3DShaderProgramFactory.h"
#include "../../../../include/NiTStringPointerMap.h"
struct Program;
extern Program* DAT_0126fa10;
Program* NiD3DShaderProgramFactory_GetInstance();
struct Program
{
    virtual void Destroy(int);
};
extern Program* DAT_0126fa10;
void DestroyProgram();
struct Nd
{
    Nd* next;
    int b;
    int data;
};
struct Lst
{
    int a;
    int b;
    Nd* head;
};
int __fastcall NiD3D10ShaderProgramFactory_GetFirstProgramDirectory(Lst* l, int, Nd** pos);
void NiD3DShaderProgramFactory__SDMInit();
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
void __cdecl UpdateFields_00e93e00();
struct P03MM
{
    void* __thiscall Allocate(unsigned int size);
};
extern P03MM g_memoryManager;
extern "C" void* __cdecl _NiMalloc(unsigned int size);
extern "C" void* __cdecl _fnv_zlib_memset(void* dst, int value, unsigned int size);
extern int DAT_010f0eb0;
extern int DAT_010f0f50;
void CreateCreatorMap();

#include "../../../../include/RecursiveSpinLock.h"
extern RecursiveSpinLock g_011c5f80;
template <class T> struct PoolAllocatorBase
{
    struct LinkedListEntry
    {
        LinkedListEntry* m_pkNext;
        int m_iData;
    };
    static LinkedListEntry* ms_pFreeList;
};
struct FUN_0045cee0_shell
{
    void __thiscall NiTPointerAllocator_unsigned_int_Deallocate(void*);
};
// @fnv 0x0045cee0
// src: XBOX_PDB 0x0045cee0
void __thiscall FUN_0045cee0_shell::NiTPointerAllocator_unsigned_int_Deallocate(void* pkItem)
{
    g_011c5f80.Lock(0);
    PoolAllocatorBase<unsigned int>::LinkedListEntry* pkNode =
        (PoolAllocatorBase<unsigned int>::LinkedListEntry*)pkItem;
    pkNode->m_iData = 0;
    pkNode->m_pkNext = PoolAllocatorBase<unsigned int>::ms_pFreeList;
    PoolAllocatorBase<unsigned int>::ms_pFreeList = pkNode;
    g_011c5f80.Unlock();
}
