
// src/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiGeomMorpherUpdateTask.h"
// NiStreamLinkIDSet_nigeommorpherupdatetask: local type (was include/NiStreamLinkIDSet.h, which had no evidence of one real class); its methods are 0x00a311e0 NiTSet<NiScreenGeometryData::ScreenElement *,NiTMallocInterface<NiScreenGeometryData::ScreenElement *> >::Add, 0x00a543b0 NiTSet::Ptr::Add
class Item;
class NiGeomMorpherUpdateTask;
class D3DRenderStateGroup;

class NiStreamLinkIDSet_nigeommorpherupdatetask
{
public:
    void* m_kPointA;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void Realloc(unsigned int);
    void ProcessEntries_00a56e60(unsigned int ItemUpdateArray);
    unsigned int Find(Item* item);
    int Find(unsigned int value);
    void Add(Item* item);
    void Add(NiGeomMorpherUpdateTask* pkTask);
    void Add(D3DRenderStateGroup* p);
    void AddUnique(Item* item);
};

extern "C"
{
    extern const void* g_011f4100;
}

// @fnv 0x00a56c00
const NiRTTI* NiGeomMorpherUpdateTask::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_011f4100);
}

extern int DAT_011a9414;
extern int DAT_011a941c;
extern NiGeomMorpherUpdateTask** DAT_011a940c;
extern int DAT_011f4180;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
// @fnv 0x00a56f90
NiGeomMorpherUpdateTask* __cdecl PopMorpherUpdateTask()
{
    EnterCriticalSection((void*)&DAT_011f4180);
    if (DAT_011a9414 == 0)
    {
        ((NiStreamLinkIDSet_nigeommorpherupdatetask*)&DAT_011a940c)->ProcessEntries_00a56e60(DAT_011a941c);
        DAT_011a941c *= 2;
    }
    NiGeomMorpherUpdateTask* pkTask = DAT_011a940c[0];
    DAT_011a9414--;
    DAT_011a940c[0] = DAT_011a940c[DAT_011a9414];
    LeaveCriticalSection((void*)&DAT_011f4180);
    return pkTask;
}

extern unsigned char DAT_011f5b08;
struct FakeGeo
{
    int __vt;
    unsigned int m_ref;
};
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
// If the global flag is clear and the geometry's reference count exceeds one, calls MorphFunc on the morph controller, then releases the task.
// @fnv 0x00a56bb0
void NiGeomMorpherUpdateTask::vf35()
{
    if (!DAT_011f5b08 && m_spReferencedObject->m_ref > 1)
        m_pkMorphController->MorphFunc();
    vf37();
}

extern int(__stdcall* DAT_00fdf1c4)(void*);
extern int DAT_01069674;

// These helpers use the shared task layout. The unused EDX parameter keeps ECX
// and the stack arguments in their original locations. The release call uses a
// thiscall pointer so it passes only the original arguments.
// Releases the two NiRefObject pointers via DAT_00fdf1c4 and, when the refcount reaches zero, calls their DeleteThis, then resets the vtable and destroys the base.
// @fnv 0x00a56c10
void __fastcall ReleaseMorpherRefObjects(NiGeomMorpherUpdateTask* task, void*)
{
    int(__stdcall * f)(void*) = DAT_00fdf1c4;
    NiRefObject* p = reinterpret_cast<NiRefObject*>(task->m_spReferencedObject);
    if (p)
    {
        if (f(&p->m_uiRefCount) == 0)
            p->DeleteThis();
    }
    p = reinterpret_cast<NiRefObject*>(task->m_pkMorphController);
    if (p)
    {
        if (f(&p->m_uiRefCount) == 0)
            p->DeleteThis();
    }
    *(void**)task = &DAT_01069674;
    ((NiRefObject*)task)->NiRefObject::~NiRefObject();
}

extern int(__stdcall* DAT_00fdf1c0)(void*);

// @fnv 0x00a56c60
void __fastcall SetMorpherRefObjects(NiGeomMorpherUpdateTask* task, void*, NiRefObject* nextFirst, NiRefObject* nextSecond)
{
    int(__stdcall * decrement)(void*) = DAT_00fdf1c4;
    NiRefObject* previous = reinterpret_cast<NiRefObject*>(task->m_pkMorphController);
    if (previous != nextFirst)
    {
        if (previous != 0)
        {
            if (decrement(&previous->m_uiRefCount) == 0)
                previous->DeleteThis();
        }
        task->m_pkMorphController = reinterpret_cast<MorphController*>(nextFirst);
        if (nextFirst != 0)
            DAT_00fdf1c0(&nextFirst->m_uiRefCount);
    }

    previous = reinterpret_cast<NiRefObject*>(task->m_spReferencedObject);
    if (previous != nextSecond)
    {
        if (previous != 0)
        {
            if (decrement(&previous->m_uiRefCount) == 0)
                previous->DeleteThis();
        }
        task->m_spReferencedObject = reinterpret_cast<FakeGeo*>(nextSecond);
        if (nextSecond != 0)
            DAT_00fdf1c0(&nextSecond->m_uiRefCount);
    }
}

extern "C" void __cdecl FUN_00aa1460(void* apMemory, unsigned int aiSize);
extern "C" void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* apMemory, unsigned int aiSize);

// @fnv 0x00a56d40
NiGeomMorpherUpdateTask* __fastcall DestroyMorpherUpdateTask(NiGeomMorpherUpdateTask* task, void*, unsigned char acFlags)
{
    if (acFlags & 2)
    {
        char* base = (char*)task - 4;
        int i = *(int*)base;
        NiGeomMorpherUpdateTask* p = (NiGeomMorpherUpdateTask*)((char*)task + i * sizeof(NiGeomMorpherUpdateTask));
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = (NiGeomMorpherUpdateTask*)((char*)p - sizeof(NiGeomMorpherUpdateTask));
                NiRefObject* a = reinterpret_cast<NiRefObject*>(p->m_spReferencedObject);
                if (a != 0 && DAT_00fdf1c4(&a->m_uiRefCount) == 0)
                {
                    a->DeleteThis();
                }
                NiRefObject* b = reinterpret_cast<NiRefObject*>(p->m_pkMorphController);
                if (b != 0 && DAT_00fdf1c4(&b->m_uiRefCount) == 0)
                {
                    b->DeleteThis();
                }
                *(void**)p = &DAT_01069674;
                p->FUN_00a5d3d0();
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            NiMemObject_ReleaseStorage_00aa1490(base, sizeof(NiGeomMorpherUpdateTask));
        }
        return (NiGeomMorpherUpdateTask*)base;
    }

    typedef void (__thiscall* ReleaseRefs)(NiGeomMorpherUpdateTask*);
    reinterpret_cast<ReleaseRefs>(&ReleaseMorpherRefObjects)(task);
    if (acFlags & 1)
    {
        FUN_00aa1460(task, sizeof(NiGeomMorpherUpdateTask));
    }
    return task;
}

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

// Clears DAT_011a9414, deletes the registry at DAT_011a9418, and copies DAT_011a9420 into DAT_011a941c.
// @fnv 0x00a56df0
void ResetRegistry()
{
    DAT_011a9414 = 0;
    delete DAT_011a9418;
    DAT_011a941c = DAT_011a9420;
}

struct MorpherTaskList
{
    void FindOrAdd(NiGeomMorpherUpdateTask** pItem);
};

// @fnv 0x00a56f10
bool NiGeomMorpherUpdateTask::vf37()
{
    int(__stdcall * dec)(void*) = DAT_00fdf1c4;
    NiRefObject* a = reinterpret_cast<NiRefObject*>(m_pkMorphController);
    if (a)
    {
        if (!dec(&a->m_uiRefCount))
            a->DeleteThis();
        m_pkMorphController = 0;
    }
    NiRefObject* b = reinterpret_cast<NiRefObject*>(m_spReferencedObject);
    if (b)
    {
        if (!dec(&b->m_uiRefCount))
            b->DeleteThis();
        m_spReferencedObject = 0;
    }
    EnterCriticalSection(&DAT_011f4180);
    NiGeomMorpherUpdateTask* self = this;
    reinterpret_cast<MorpherTaskList*>(&DAT_011a940c)->FindOrAdd(&self);
    LeaveCriticalSection(&DAT_011f4180);
    return true;
}

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

inline void NiStreamLinkIDSet_nigeommorpherupdatetask::Add(NiGeomMorpherUpdateTask* pkTask)
{
    if (m_pRayCursor == m_uiItemCount)
        Realloc(m_uiItemCount > 0 ? m_uiItemCount * 2 : 1);
    static_cast<NiGeomMorpherUpdateTask**>(m_kPointA)[m_pRayCursor++] = pkTask;
}

// @fnv 0x00a56e60
// src: GUESS 0x00a56e60 (confidence: low)
void NiStreamLinkIDSet_nigeommorpherupdatetask::ProcessEntries_00a56e60(unsigned int uiTaskCount)
{
    TaskBlock* pkBlock = new TaskBlock(uiTaskCount);
    for (unsigned int i = 0; i < uiTaskCount; i++)
        Add(pkBlock->GetAt(i));
    // This task pool stores its block chain immediately after the shared set.
    TaskBlock*& pkBlocks = reinterpret_cast<TaskBlock**>(this)[3];
    pkBlock->m_pkNext = pkBlocks;
    pkBlocks = pkBlock;
}
