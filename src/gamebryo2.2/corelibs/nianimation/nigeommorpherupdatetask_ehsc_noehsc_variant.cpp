#include "../../../../include/NiGeomMorpherUpdateTask.h"
#include "../../../../include/NiRefObject.h"

// src/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C"
{
    extern const void* g_011f4100;
}
const void* __cdecl FUN_00a56c00();
extern int DAT_011a9414;
extern int DAT_011a941c;
extern NiGeomMorpherUpdateTask** DAT_011a940c;
extern int DAT_011f4180;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct FreeStore
{
    void ProcessEntries_00a56e60(int);
};
NiGeomMorpherUpdateTask* __cdecl PopMorpherUpdateTask();
extern unsigned char DAT_011f5b08;
struct MorphController
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void MorphFunc() = 0;
};
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern int DAT_01069674;
extern int(__stdcall* DAT_00fdf1c0)(void*);
extern "C" void __cdecl FUN_00aa1460(void* apMemory, unsigned int aiSize);
extern "C" void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* apMemory, unsigned int aiSize);
class A56DF0Heap
{
  public:
    void Deallocate(void* pvMem);
};
extern A56DF0Heap g_kA56DF0Heap;
void operator delete(void* pvMem)
{
    g_kA56DF0Heap.Deallocate(pvMem);
}
class A56DF0Entry
{
  public:
    virtual ~A56DF0Entry();
};
class A56DF0Cache
{
  public:
    void Shutdown(bool bFree);
};
struct A56DF0Registry
{
    ~A56DF0Registry()
    {
        delete[] m_pkEntryArray;
        if (m_pkCache)
            m_pkCache->Shutdown(true);
    }

    A56DF0Entry* m_pkEntryArray;
    int unk04;
    A56DF0Cache* m_pkCache;
};
extern int DAT_011a9414;
extern A56DF0Registry* DAT_011a9418;
extern int DAT_011a941c;
extern int DAT_011a9420;
void ResetRegistry();
class MemoryManager;
extern MemoryManager g_memoryManager;
class FUN_00a5e3a0_Helper
{
  public:
    void* Game_DoHeapAlloc(unsigned int uiSize);
};
NiGeomMorpherUpdateTask* __cdecl NiGeomMorpherUpdateTask_ConstructObject(unsigned int ItemUpdateArray) throw();
struct TaskBlock
{
    NiGeomMorpherUpdateTask* m_pkTasks;
    unsigned int m_uiCount;
    TaskBlock* m_pkNext;

    TaskBlock(unsigned int ItemUpdateArray) : m_uiCount(ItemUpdateArray), m_pkNext(0)
    {
        if (ItemUpdateArray > 0)
            m_pkTasks = NiGeomMorpherUpdateTask_ConstructObject(ItemUpdateArray);
        else
            m_pkTasks = 0;
    }
    NiGeomMorpherUpdateTask* GetAt(unsigned int i)
    {
        return i >= m_uiCount ? 0 : &m_pkTasks[i];
    }

    static void* operator new(unsigned int uiSize)
    {
        return ((FUN_00a5e3a0_Helper*)&g_memoryManager)->Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void*, int, int);
};

struct S_00a56ce0_HeapX
{
    void* Game_DoHeapAlloc(unsigned int n);
};
extern S_00a56ce0_HeapX DAT_011f6238;
extern "C" void* __cdecl FUN_00aa1420(unsigned int n);

// Global placement allocation preserves the heap path for a zero-length task array.
inline void* operator new[](size_t size, unsigned int count)
{
    if (count == 0)
        return DAT_011f6238.Game_DoHeapAlloc(4);
    return FUN_00aa1420(size);
}

// @fnv 0x00a56ce0
// src: GUESS 0x00a56ce0 (confidence: medium)
NiGeomMorpherUpdateTask* __cdecl NiGeomMorpherUpdateTask_ConstructObject(unsigned int ItemUpdateArray) throw()
{
    return ::new (ItemUpdateArray) NiGeomMorpherUpdateTask[ItemUpdateArray];
}
