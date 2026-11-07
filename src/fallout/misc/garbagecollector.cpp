// fallout/misc/garbagecollector.cpp: GarbageCollector (22 functions)

#include "../../../include/NiTMallocInterface.h"
#include "../../../include/NiTNewInterface.h"
#include "../../../include/NiTArray.h"
#include "../../../include/BGSSaveLoadGame.h"
#include "../../../include/GO.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiControllerManager.h"
#include "garbagecollector_packet.h"
#include "original_garbagecollector.h"

const char kGarbageCollectorRemoveLabel[] = "GarbageCollector::Remove(TESObjectREFR)";

// Locks the garbage collector, removes the reference from both garbage lists if present, then unlocks it.
// @fnv 0x00868270
void GarbageCollector::Remove(TESObjectREFR* reference)
{
    LockGarbageCollector(kGarbageCollectorRemoveLabel, true);
    unsigned int size = ms_kReferencesQueuedForRemoval.GetSize();
    for (unsigned int index = 0; index < size; ++index)
    {
        if (ms_kReferencesQueuedForRemoval.GetAt(index) == reference)
        {
            ms_kReferencesQueuedForRemoval.RemoveAtAndFill(index);
            break;
        }
    }
    size = ObjectGarbageB.GetSize();
    for (unsigned int index = 0; index < size; ++index)
    {
        if (ObjectGarbageB.GetAt(index) == reference)
        {
            ObjectGarbageB.RemoveAtAndFill(index);
            break;
        }
    }
    UnlockGarbageCollector(true);
}

// @fnv 0x0040fc90
void GarbageCollector::QueryCurrentThread(bool)
{
    GetCurrentThreadId();
}

const char kGarbageCollectorClearTempEffectsLabel[] = "GarbageCollector::ClearTempEffects()";
// @fnv 0x00868d10
void GarbageCollector::ClearTempEffects()
{
    if (g_011de828.GetSize() && g_modelLoader->FUN_00868250())
    {
        LockGarbageCollector(kGarbageCollectorClearTempEffectsLabel, true);
        g_011de828.RemoveAll();
        g_modelLoader->ModelLoader_UnlockModelMap();
        UnlockGarbageCollector(true);
    }
}

const char kGarbageCollectorUpdateLabel[] = "GarbageCollector::Update()";
// @fnv 0x00868850
void GarbageCollector::Update()
{
    LockGarbageCollector(kGarbageCollectorUpdateLabel, true);
    struct QueueBudget
    {
        unsigned int multiplier;
        unsigned int size;
        unsigned int remaining;
    } budget;
    budget.size = 0;
    budget.remaining = 0;
    budget.multiplier = 1;
    if (MemoryLevelManager_GetSingleton()->MemoryLevelManager_WasLastCheckedMemLevelCloseToLow())
        budget.multiplier = 2;
    if (g_011de808.GetSize())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = g_011de808.GetSize();
            budget.remaining = budget.multiplier * 10;
            while (budget.size && budget.remaining)
            {
                --budget.size;
                --budget.remaining;
                GarbageCollectorDeleteA* object = g_011de808.GetAt(budget.size);
                g_011de808.RemoveAt(budget.size);
                delete object;
            }
            g_modelLoader->ModelLoader_UnlockModelMap();
        }
    }
    else if (g_011de910.GetSize())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = g_011de910.GetSize();
            budget.remaining = budget.multiplier * 10;
            while (budget.size && budget.remaining)
            {
                --budget.size;
                --budget.remaining;
                GarbageCollectorDeleteB* object = g_011de910.GetAt(budget.size);
                g_011de910.RemoveAt(budget.size);
                delete object;
            }
            g_modelLoader->ModelLoader_UnlockModelMap();
        }
    }
    else if (g_011de838.GetSize())
    {
        ForEachNavMesh(&g_011de838, &g_011de910);
        g_011de838.RemoveAll();
    }
    else if (g_011de888.GetSize())
    {
        budget.size = g_011de888.GetSize();
        budget.remaining = budget.multiplier * 10;
        while (budget.size && budget.remaining)
        {
            --budget.size;
            --budget.remaining;
            NiPointer<NiAVObject> object = g_011de888.RemoveAt(budget.size);
            // The shared NiPointer lacks inequality; GO exposes the same pointer comparison.
            if (reinterpret_cast<const GO&>(object) != 0)
                object.m_pObject->RemoveGarbageMark();
        }
    }
    else if (g_011de848.GetSize())
    {
        j_CopyArrays_V_NiTObjectArray_V_NiPointer_VNiAVObject_GarbageCollector_KAXPBV_NiTObjectArray_V_NiPointer_VNiAVObject_PAV1_Z(&g_011de848, &g_011de888);
        g_011de848.RemoveAll();
    }
    else if (ms_kReferencesQueuedForRemoval.GetSize())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = ms_kReferencesQueuedForRemoval.GetSize();
            budget.remaining = budget.multiplier * 20;
            unsigned int special = 1;
            while (budget.size && budget.remaining && special)
            {
                --budget.size;
                --budget.remaining;
                TESObjectREFR* object = ms_kReferencesQueuedForRemoval.GetAt(0);
                if (object->IsActor() || object->GetTargeted())
                    --special;
                delete object;
            }
            g_modelLoader->ModelLoader_UnlockModelMap();
        }
    }
    else if (ObjectGarbageB.GetSize())
    {
        ForEachNavMesh(&ObjectGarbageB, &ms_kReferencesQueuedForRemoval);
        ObjectGarbageB.RemoveAll();
    }
    else if (g_011de924.GetSize())
    {
        budget.size = g_011de924.GetSize();
        budget.remaining = budget.multiplier * 5;
        while (budget.size && budget.remaining)
        {
            --budget.size;
            --budget.remaining;
            g_011de924.GetAt(0u)->NiRefObject::DecRefCount();
            g_011de924.Remove(0, true);
        }
    }
    else if (g_011de898.GetSize())
    {
        CopyNonNullElements(&g_011de898, &g_011de924);
        g_011de898.Clear(true);
    }
    UnlockGarbageCollector(true);
}

#include "../../../include/NavMeshPtr.h"
struct TwoPointerRecord
{
    TwoPointerRecord(unsigned int, const char*);
    ~TwoPointerRecord();
    unsigned int id;
    unsigned int startTime;
};
extern __declspec(thread) bool DAT_tlsFlag;

// @fnv 0x00868790
void __cdecl AddNavMeshToGarbageCollector(NavMeshPtr& apNavMesh)
{
    TwoPointerRecord tempAutoEvent(0x20, "GarbageCollector::Add(NavMeshPtr)");
    ((NavMesh*)apNavMesh)->NiRefObject::IncRefCount();
    if (DAT_tlsFlag)
    {
        NavMesh* mesh = apNavMesh.AnimatingText_GetFullText();
        g_011de924.Add(mesh);
    }
    else
    {
        NavMesh* mesh = apNavMesh.AnimatingText_GetFullText();
        g_011de898.Add(mesh);
    }
}

bool __cdecl GarbageCollector_TryEnterCrit();
bool __cdecl HasFlags(int);
bool __cdecl BSSpinLockGlobalTryLock();
void __cdecl BSTexturePalette_Unlock();
void Object_ProcessEntries_00869560(void*, void*);
extern NiTObjectArray<NiPointer<BSTempEffect> > g_011de858;
extern bool DAT_011de958;
extern __declspec(thread) bool bCollecting;

// @fnv 0x00868d70
// src: EXE 0x00868d70
void GarbageCollector_ClearAll(bool abTryLock)
{
    if (DAT_011de958)
        return;
    bool bLocked = true;
    if (abTryLock)
        bLocked = GarbageCollector_TryEnterCrit();
    else
        LockGarbageCollector("GarbageCollector::ClearAll()", true);
    if (bLocked)
    {
        DAT_011de958 = true;
        bool bWasCollecting = bCollecting;
        bCollecting = false;
        if (!HasFlags(0x10) && BSSpinLockGlobalTryLock())
        {
            g_011de828.RemoveAll();
            BSTexturePalette_Unlock();
        }
        if (!HasFlags(8) && g_modelLoader->FUN_00868250())
        {
            unsigned int icount = g_011de808.GetSize();
            for (unsigned int i = 0; i < icount; i++)
            {
                GarbageCollectorDeleteA* pobject = g_011de808.GetAt(i);
                delete pobject;
            }
            g_011de808.RemoveAll();
            g_modelLoader->ModelLoader_UnlockModelMap();
        }
        if (!HasFlags(4) && g_modelLoader->FUN_00868250())
        {
            unsigned int icount = g_011de910.GetSize();
            for (unsigned int i = 0; i < icount; i++)
            {
                GarbageCollectorDeleteB* pobject = g_011de910.GetAt(i);
                delete pobject;
            }
            g_011de910.RemoveAll();
            g_modelLoader->ModelLoader_UnlockModelMap();
        }
        if (!HasFlags(2))
        {
            for (unsigned int i = 0; i < g_011de888.GetSize(); i++)
            {
                if ((NiAVObject*)(const NiPointer<NiAVObject>&)g_011de888.GetAt(i))
                    g_011de888.GetAt(i).m_pObject->RemoveGarbageMark();
            }
            g_011de888.RemoveAll();
        }
        if (!HasFlags(1) && g_modelLoader->FUN_00868250())
        {
            while (GarbageCollector::ms_kReferencesQueuedForRemoval.GetSize())
            {
                TESObjectREFR* pref = GarbageCollector::ms_kReferencesQueuedForRemoval.GetAt(0);
                delete pref;
            }
            GarbageCollector::ms_kReferencesQueuedForRemoval.RemoveAll();
            g_modelLoader->ModelLoader_UnlockModelMap();
        }
        if (!HasFlags(0x20))
        {
            for (unsigned int i = 0; i < g_011de924.GetSize(); i++)
                g_011de924.GetAt(i)->NiRefObject::DecRefCount();
            g_011de924.Clear(true);
        }
        bCollecting = bWasCollecting;
        if (bCollecting)
        {
            ForEachNavMesh(&GarbageCollector::ObjectGarbageB, &GarbageCollector::ms_kReferencesQueuedForRemoval);
            GarbageCollector::ObjectGarbageB.RemoveAll();
            j_CopyArrays_V_NiTObjectArray_V_NiPointer_VNiAVObject_GarbageCollector_KAXPBV_NiTObjectArray_V_NiPointer_VNiAVObject_PAV1_Z(&g_011de848, &g_011de888);
            g_011de848.RemoveAll();
            ForEachNavMesh(&g_011de838, &g_011de910);
            g_011de838.RemoveAll();
            Object_ProcessEntries_00869560(&g_011de858, &g_011de828);
            g_011de858.RemoveAll();
            CopyNonNullElements(&g_011de898, &g_011de924);
            g_011de898.Clear(true);
        }
        DAT_011de958 = false;
        UnlockGarbageCollector(true);
    }
}

#include "../../../include/RecursiveSpinLock.h"

// The garbage collector's lock (a 32-byte aligned global).
extern RecursiveSpinLock g_011de8e0;

// @fnv 0x00867f50
void __cdecl LockGlobalObject(const char* apLabel)
{
    g_011de8e0.Lock(apLabel);
}

// @fnv 0x00867f70
// src: COMMUNITY 0x00867f70
bool __cdecl GarbageCollector_TryEnterCrit()
{
    return g_011de8e0.TryLock();
}

// @fnv 0x00867f80
// src: COMMUNITY 0x00867f80
void GarbageCollector_LeaveCrit()
{
    g_011de8e0.Unlock();
}

struct FUN_00868210_shell
{
    int m_00;
    unsigned char m_04;
    void ClearBitsAndUnlockGC();
};

extern int DAT_011de804;

// If m_04 is zero, clears the bits of m_00 in DAT_011de804, then unlocks the garbage collector.
// @fnv 0x00868210
void FUN_00868210_shell::ClearBitsAndUnlockGC()
{
    if (m_04 == 0)
    {
        DAT_011de804 = ~m_00 & DAT_011de804;
    }
    UnlockGarbageCollector(false);
}

void __cdecl Garbagecollector_ForwardCall_00868770(int* a, int b);

// NiAVObject.h lacks the collector mark operation (0x00868740).
// Keep just its member-call adapter; the refcount field comes from the shared class.
struct GarbageMarkAdapter
{
    void MarkForCollection();
};

// @fnv 0x00868740
void GarbageMarkAdapter::MarkForCollection()
{
    Garbagecollector_ForwardCall_00868770(reinterpret_cast<int*>(&reinterpret_cast<NiAVObject*>(this)->m_uiRefCount),
        reinterpret_cast<NiAVObject*>(this)->m_uiRefCount | 0x40000000);
}

struct FUN_008681c0_shell
{
    int m_00;
    unsigned char m_04;
    FUN_008681c0_shell* __thiscall InitFlags(int, const char*);
};
// Stores a in m_00, locks the garbage collector with b, sets m_04 from the overlap of DAT_011de804 and a, then ORs a into DAT_011de804.
// @fnv 0x008681c0
FUN_008681c0_shell* __thiscall FUN_008681c0_shell::InitFlags(int aiFlags, const char* apName)
{
    m_00 = aiFlags;
    LockGarbageCollector(apName, 0);
    m_04 = (DAT_011de804 & aiFlags) != 0;
    DAT_011de804 |= aiFlags;
    return this;
}

// Clears the garbage-collection flag in the reference count through the atomic exchange adapter.
// @fnv 0x00868ce0
void __thiscall NiAVObject::RemoveGarbageMark()
{
    Garbagecollector_ForwardCall_00868770(reinterpret_cast<int*>(&m_uiRefCount), m_uiRefCount & 0xBFFFFFFF);
}

// @fnv 0x008693c0
template <class T, class TAlloc>
unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

// Copies non-null four-byte entries between the collector's raw-pointer arrays.
// @fnv 0x008694c0
template <class T>
void __cdecl ForEachNavMesh(NiTObjectArray<T>* apArray, NiTObjectArray<T>* apObj)
{
    unsigned int i;
    for (i = 0; i < apArray->GetSize(); i++)
    {
        T cur;
        cur = apArray->GetAt(i);
        if (cur != 0)
        {
            apObj->Add(cur);
        }
    }
}

// Copies non-null meshes between the collector's BSSimpleArray queues.
// @fnv 0x00869510
void CopyNonNullElements(BSSimpleArray<NavMesh*>* apSource, BSSimpleArray<NavMesh*>* apDest)
{
    unsigned int i;
    for (i = 0; i < apSource->GetSize(); i++)
    {
        NavMesh* v;
        v = apSource->GetAt(static_cast<int>(i));
        if (v)
            apDest->Add(v);
    }
}

// NiAVObject.h does not yet expose the child cleanup at 0x0050f5a0.
// This adapter declares only the missing call, without duplicating the object layout.
struct ChildGarbageCleanupAdapter
{
    void ClearChildGarbage();
};
// @fnv 0x00572160
// src: XBOX_PDB 0x00572160
void NiNode::DetachAllChildren_00572160()
{
    unsigned int i;
    unsigned int count = m_kChildren.GetSize();
    for (i = 0; i < count; ++i)
    {
        unsigned int effect = (unsigned int)(NiAVObject*)(const NiPointer<NiAVObject>&)m_kChildren.GetAt(i);
        if (effect)
            ((ChildGarbageCleanupAdapter*)effect)->ClearChildGarbage();
    }
    m_kChildren.RemoveAll();
}

extern void(__stdcall* DAT_00fdf0e4)(void*, void*);
// @fnv 0x00868770
// src: GUESS 0x00868770 (confidence: low)
void __cdecl Garbagecollector_ForwardCall_00868770(int* a, int b)
{
    DAT_00fdf0e4(a, (void*)b);
}

// Adds a temporary-effect pointer to the active or deferred garbage queue.
// @fnv 0x00868490
// src: EXE 0x00868490
void __cdecl GarbageCollector_Add(int aiEffect)
{
    TwoPointerRecord e(0x10, "GarbageCollector::Add(BSTempEffect)");
    if (DAT_tlsFlag)
    {
        GO p(aiEffect);
        g_011de828.Add(reinterpret_cast<const NiPointer<BSTempEffect>&>(p));
    }
    else
    {
        GO p(aiEffect);
        g_011de858.Add(reinterpret_cast<const NiPointer<BSTempEffect>&>(p));
    }
}

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// @fnv 0x00868560
// src: EXE 0x00868560
void __cdecl GarbageCollector_Add_00868560(GarbageCollectorDeleteB* apObject)
{
    TwoPointerRecord autoEvent(4, "GarbageCollector::Add(BipedAnim)");

    if (!DAT_tlsFlag || (g_BGSSaveLoadGame != 0 && g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading()))
    {
        if (g_modelLoader->FUN_00868250())
        {
            delete apObject;
            g_modelLoader->ModelLoader_UnlockModelMap();
        }
        else
        {
            g_011de838.Add(apObject);
        }
    }
    else
    {
        g_011de910.Add(apObject);
    }
}

// Marks a non-null object for collection and queues its smart pointer.
// @fnv 0x00868660
// src: EXE 0x00868660
void GarbageCollector_Add_00868660(NiAVObject* apObject)
{
    TwoPointerRecord autoEvent(2, "GarbageCollector::Add(NiAVObject)");

    if (apObject)
    {
        reinterpret_cast<GarbageMarkAdapter*>(apObject)->MarkForCollection();
    }

    if (bCollecting)
    {
        GO object(reinterpret_cast<int>(apObject));
        g_011de888.Add(reinterpret_cast<const NiPointer<NiAVObject>&>(object));
    }
    else
    {
        GO object(reinterpret_cast<int>(apObject));
        g_011de848.Add(reinterpret_cast<const NiPointer<NiAVObject>&>(object));
    }
}

// The shared NiAVObject declares GetController, but not removal at 0x00a5c480.
struct ControllerRemovalAdapter
{
    void RemoveController(NiTimeController*);
};
struct AnimationObject
{
    void FreeAllIdles();
    NiControllerManager* GetControllerManager_00496940();
    NiAVObject* FUN_005585e0();
};
struct AnimationLoader
{
    void ModelLoader_CancelReplacementKFList(AnimationObject*);
};
extern int DAT_011f36bc;
extern int g_011f36e4;
// @fnv 0x00868330
void AddAnimationToGarbageCollector(AnimationObject* object)
{
    TwoPointerRecord event(8, "GarbageCollector::Add(Animation)");
    object->FreeAllIdles();
    if (object->GetControllerManager_00496940())
        object->GetControllerManager_00496940()->FUN_0048fef0(0.0f);
    NiAVObject* pRoot = object->FUN_005585e0();
    if (pRoot)
    {
        NiTimeController* controller = pRoot->GetController(reinterpret_cast<const NiRTTI*>(&DAT_011f36bc));
        if (controller)
            reinterpret_cast<ControllerRemovalAdapter*>(pRoot)->RemoveController(controller);
        controller = pRoot->GetController(reinterpret_cast<const NiRTTI*>(&g_011f36e4));
        if (controller)
            reinterpret_cast<ControllerRemovalAdapter*>(pRoot)->RemoveController(controller);
    }
    ((AnimationLoader*)g_modelLoader)->ModelLoader_CancelReplacementKFList(object);
    if (!DAT_tlsFlag || (g_BGSSaveLoadGame && g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading()))
    {
        delete (GarbageCollectorDeleteA*)object;
    }
    else
    {
        g_011de808.Add(reinterpret_cast<GarbageCollectorDeleteA*&>(object));
    }
}
