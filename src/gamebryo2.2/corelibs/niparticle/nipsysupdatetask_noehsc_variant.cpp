
// src/gamebryo2.2/corelibs/niparticle/nipsysupdatetask_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../include/NiPSysUpdateTask.h"
#include "../../../../include/NiRefObject.h"

extern "C" void* g_01202580;
void* __cdecl NiPSysUpdateTask_GetRTTI();
extern int DAT_010be45c;
extern int DAT_01069674;
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern unsigned char DAT_011f5b08;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct PoolHelper
{
    void __thiscall AppendRecords(int);
};
extern void* DAT_011aeb98;
extern int DAT_011aeba0;
extern int DAT_011aeba8;
extern int DAT_01202600;
NiPSysUpdateTask* PopNiPSysUpdateTask();
typedef unsigned int C25AC0size_t;
struct C25AC0MemoryManager
{
    void Deallocate(void* pvMem);
};
extern C25AC0MemoryManager g_C25AC0MemoryManager;
inline void __cdecl operator delete(void* pvMem)
{
    g_C25AC0MemoryManager.Deallocate(pvMem);
}
inline void __cdecl operator delete[](void* pvMem)
{
    g_C25AC0MemoryManager.Deallocate(pvMem);
}
struct C25AC0MemObject
{
};
struct C25AC0Entry : C25AC0MemObject
{
    virtual ~C25AC0Entry();
};
struct C25AC0Helper : C25AC0MemObject
{
    void DeleteThis(int iFlags);
};
struct C25AC0Manager : C25AC0MemObject
{
    C25AC0Entry* m_pkEntryArray;
    int unk04;
    C25AC0Helper* m_pkHelper;

    ~C25AC0Manager()
    {
        delete[] m_pkEntryArray;
        if (m_pkHelper)
            m_pkHelper->DeleteThis(1);
    }
};
extern C25AC0Manager* g_C25AC0Instance;
extern int g_C25AC0Count;
extern int g_C25AC0Current;
extern int g_C25AC0Default;
void __cdecl DestroyManager();
// The per-count link record the game allocates: { data, count, next }.
struct LinkRec_00c25b30
{
    unsigned char* m_data;
    unsigned int m_uiItemCount;
    LinkRec_00c25b30* m_next;
};
// The game's global memory manager object.
struct PoolAlloc_00c25b30
{
    void* Alloc(unsigned int size);
};
extern PoolAlloc_00c25b30 DAT_011f6238;
// Builds the array of 20-byte link records (lives in another unit of the game).
void* __cdecl NiTNewInterface_NiPSysUpdateTask_Allocate(unsigned int count);
// The link-id set: { items, capacity, size, head }.
struct LinkIDSet_00c25b30
{
    void** m_items;
    unsigned int m_cap;
    unsigned int m_iElementCount;
    LinkRec_00c25b30* m_pFirstNode;

    void Grow(unsigned int newCapacity);
    void AppendRecords(unsigned int count);
};
struct S_00e7ec00
{
    void __thiscall FindOrAdd(void*);
};
extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
void __cdecl operator delete(void* pv, int iSize);
void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* pv, unsigned int uiSize);

extern "C" void* __cdecl FUN_00aa1420(unsigned int size);
// MSVC uses scalar allocation for the cookie of an empty polymorphic array.
inline void* __cdecl operator new(unsigned int size)
{
    return DAT_011f6238.Alloc(size);
}

inline void* NiPSysUpdateTask::operator new[](unsigned int size, unsigned int count)
{
    if (count == 0)
        return DAT_011f6238.Alloc(4);
    return FUN_00aa1420(size);
}

// @fnv 0x00c25990
// src: XBOX_PDB 0x00c25990
void* __cdecl NiTNewInterface_NiPSysUpdateTask_Allocate(unsigned int count)
{
    return new (count) NiPSysUpdateTask[count];
}
