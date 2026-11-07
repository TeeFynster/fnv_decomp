
// src/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysUpdateTask.h"
#include "../../../../include/NiRefObject.h"

extern "C" void* g_01202580;

// @fnv 0x00c25870
// src: COMMUNITY 0x00c25870
void* __cdecl NiPSysUpdateTask_GetRTTI()
{
    return &g_01202580;
}

extern int DAT_010be45c;
extern int DAT_01069674;
extern int(__stdcall* DAT_00fdf1c4)(void*);
// @fnv 0x00c25880
void NiPSysUpdateTask::Destroy()
{
    int(__stdcall * f)(void*) = DAT_00fdf1c4;
    *(void* volatile*)this = (void*)&DAT_010be45c;
    NiRefObject* p = reinterpret_cast<NiRefObject*>(reinterpret_cast<NiParticleSystem* volatile&>(m_pkParticleSystem));
    if (p)
    {
        if (f(&p->m_uiRefCount) == 0)
            p->DeleteThis();
        m_pkParticleSystem = 0;
    }
    p = reinterpret_cast<NiRefObject*>(reinterpret_cast<NiParticleSystem* volatile&>(m_pkParticleSystem));
    if (p)
    {
        if (f(&p->m_uiRefCount) == 0)
            p->DeleteThis();
    }
    *(void* volatile*)this = (void*)&DAT_01069674;
    this->NiRefObject::~NiRefObject();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}
// @fnv 0x00c258e0
void NiPSysUpdateTask::AssignRefAndValue(NiParticleSystem* pkObject, float afValue)
{
    if (m_pkParticleSystem != pkObject)
    {
        if (m_pkParticleSystem)
            reinterpret_cast<NiRefObject*>(m_pkParticleSystem)->DecRefCount();
        m_pkParticleSystem = pkObject;
        if (m_pkParticleSystem)
            reinterpret_cast<NiRefObject*>(m_pkParticleSystem)->IncRefCount();
    }
    m_fUpdateTime = afValue;
}

extern unsigned char DAT_011f5b08;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
// @fnv 0x00c25930
void NiPSysUpdateTask::ReleaseSysAndDispatch()
{
    NiParticleSystem* p = m_pkParticleSystem;
    if (p && !DAT_011f5b08)
    {
        ((void(__thiscall*)(NiParticleSystem*, float))(*(void***)p)[61])(p, m_fUpdateTime);
        NiRefObject* pSysRef = reinterpret_cast<NiRefObject*>(m_pkParticleSystem);
        if (pSysRef)
        {
            if (InterlockedDecrement((volatile long*)&pSysRef->m_uiRefCount) == 0)
                pSysRef->DeleteThis();
            m_pkParticleSystem = 0;
        }
    }
    vf37();
}

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
// Under a critical section, grows the pool when empty, pops the last task into slot 0 and returns the previous slot-0 task.
// @fnv 0x00c25c40
NiPSysUpdateTask* PopNiPSysUpdateTask()
{
    EnterCriticalSection((void*)&DAT_01202600);
    if (DAT_011aeba0 == 0)
    {
        ((PoolHelper*)&DAT_011aeb98)->AppendRecords(DAT_011aeba8);
        DAT_011aeba8 = DAT_011aeba8 * 2;
    }
    NiPSysUpdateTask* pkTask = ((NiPSysUpdateTask**)DAT_011aeb98)[0];
    DAT_011aeba0--;
    ((NiPSysUpdateTask**)DAT_011aeb98)[0] = ((NiPSysUpdateTask**)DAT_011aeb98)[DAT_011aeba0];
    LeaveCriticalSection((void*)&DAT_01202600);
    return pkTask;
}

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

// Resets the count to zero, deletes the global manager instance, and restores the current value from the default.
// @fnv 0x00c25ac0
void __cdecl DestroyManager()
{
    C25AC0Manager* pkManager = g_C25AC0Instance;
    g_C25AC0Count = 0;
    delete pkManager;
    g_C25AC0Current = g_C25AC0Default;
}

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

// Allocates a record block of count entries, appends a pointer to each entry to m_items (growing as needed), and links the block at the head of the list.
// @fnv 0x00c25b30
void LinkIDSet_00c25b30::AppendRecords(unsigned int count)
{
    LinkRec_00c25b30* pBlock;
    unsigned int i;
    LinkRec_00c25b30* pNewBlock = (LinkRec_00c25b30*)DAT_011f6238.Alloc(0xc);
    if (pNewBlock != 0)
    {
        pNewBlock->m_uiItemCount = count;
        pNewBlock->m_next = 0;
        if (count > 0)
            pNewBlock->m_data = (unsigned char*)NiTNewInterface_NiPSysUpdateTask_Allocate(count);
        else
            pNewBlock->m_data = 0;
        pBlock = pNewBlock;
    }
    else
    {
        pBlock = 0;
    }

    i = 0;
    if (0 < count)
    {
        unsigned int offset = 0;
        for (; i < count; i++)
        {
            unsigned char* p;
            if (i >= pBlock->m_uiItemCount)
                p = 0;
            else
                p = pBlock->m_data + offset;
            if (m_iElementCount == m_cap)
            {
                unsigned int newCap;
                if (m_cap > 0)
                    newCap = m_cap * 2;
                else
                    newCap = 1;
                Grow(newCap);
            }
            m_items[m_iElementCount] = p;
            m_iElementCount++;
            offset += 0x14;
        }
    }
    pBlock->m_next = m_pFirstNode;
    m_pFirstNode = pBlock;
}

struct S_00e7ec00
{
    void __thiscall FindOrAdd(void*);
};

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);

// @fnv 0x00c25be0
// src: XBOX_PDB 0x00c25be0
bool NiPSysUpdateTask::Clear_00c25be0()
{
    NiRefObject* pObj = reinterpret_cast<NiRefObject*>(reinterpret_cast<NiParticleSystem* volatile&>(m_pkParticleSystem));

    if (pObj != 0)
    {
        if (DAT_00fdf1c4(&pObj->m_uiRefCount) == 0)
        {
            pObj->DeleteThis();
        }

        m_pkParticleSystem = 0;
    }

    DAT_00fdf05c(&DAT_01202600);

    NiPSysUpdateTask* pSelf = this;
    reinterpret_cast<S_00e7ec00*>(&DAT_011aeb98)->FindOrAdd(&pSelf);

    DAT_00fdf100(&DAT_01202600);

    return true;
}

void __cdecl operator delete(void* pv, int iSize);
void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* pv, unsigned int uiSize);

__forceinline void NiPSysUpdateTask::Destruct()
{
    *(int* volatile*)this = &DAT_010be45c;
    NiRefObject* pkObj = reinterpret_cast<NiRefObject*>(reinterpret_cast<NiParticleSystem* volatile&>(m_pkParticleSystem));
    if (pkObj)
    {
        if (InterlockedDecrement((volatile long*)&pkObj->m_uiRefCount) == 0)
            pkObj->DeleteThis();
        m_pkParticleSystem = 0;
    }
    NiRefObject* pkObjCur = reinterpret_cast<NiRefObject*>(reinterpret_cast<NiParticleSystem* volatile&>(m_pkParticleSystem));
    if (pkObjCur)
    {
        if (InterlockedDecrement((volatile long*)&pkObjCur->m_uiRefCount) == 0)
            pkObjCur->DeleteThis();
    }
    *(int**)this = &DAT_01069674;
    this->NiRefObject::~NiRefObject();
}

// @fnv 0x00c259f0
void* NiPSysUpdateTask::DestroyElements(unsigned int uiFlags)
{
    if (uiFlags & 2)
    {
        int* piCount = (int*)this - 1;
        int iCount = *piCount;
        NiPSysUpdateTask* pkElem = this + iCount;
        while (--iCount >= 0)
        {
            --pkElem;
            pkElem->Destruct();
        }
        if (uiFlags & 1)
            NiMemObject_ReleaseStorage_00aa1490(piCount, 0x14);
        return piCount;
    }
    Destroy();
    if (uiFlags & 1)
        ::operator delete(this, 0x14);
    return this;
}
