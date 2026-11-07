#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpEntity.h"
#include "../../../../../../../include/hkpShape.h"

// This /EHs-c- variant owns the update routine at 0x00d099d0.
// Declarations for the other original-unit functions are kept only where called here.
struct FUN_00d08ff0_t {
    int a;
    int b;
    int c;
    int d;
};
void hkpAabbTreeWorldManager_gatherCollidablesFromWorld(FUN_00d08ff0_t* self, int arg);
struct FUN_00d08550_Class {
    void __thiscall hkpAabbTreeWorldManager_setTreeIsClean();
};
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
inline hkAabb::hkAabb() {}

template <typename T>
__forceinline void hkArrayBase<T>::clear() { m_iElementCount = 0; }
template <typename T>
__forceinline void hkArrayBase<T>::pushBackUnchecked(const T& value) {
    m_data[m_iElementCount] = value;
    ++m_iElementCount;
}
template <typename T>
__forceinline void hkArrayBase<T>::removeAt(int index) {
    --m_iElementCount;
    if (m_iElementCount != index) m_data[index] = m_data[m_iElementCount];
}
template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc) {
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*) {
    return *(hkMemoryAllocator*)hkMemoryRouter::getInstance().m_heap;
}
template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray() { this->clearAndDeallocate(); }
// The temporary array saves and restores hkMemoryRouter::a around a 128-byte-aligned stack allocation.
struct CollidableArray : hkArray<hkpCollidable*> {
    char* saved;
    CollidableArray(int count) {
        hkMemoryRouter* allocator=&hkMemoryRouter::getInstance();
        char* memory=(char*)allocator->m_stack.m_next.m_storage;
        allocator->m_stack.m_next.m_storage=(char*)allocator->m_stack.m_next.m_storage+((count*4+127)&~127);
        m_data=(hkpCollidable**)memory;
        m_iCapacityState=count|0x80000000;
        saved=memory;
    }
    ~CollidableArray() {
        if (saved==(char*)m_data) clear();
        hkMemoryRouter::getInstance().m_stack.m_next.m_storage=saved;
    }
};
struct Tree {
    unsigned short hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_add(hkAabb*, hkpCollidable*);
    void hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_remove(unsigned short);
};
struct ScanToken;
struct TablePair { unsigned long key; unsigned long value; };
struct MapStorage {
    TablePair* elem; int numElems; int hashMod;
    ScanToken* first() const {
        int index=0;
        for (; index <= hashMod; ++index) if (elem[index].key != (unsigned long)-1) break;
        return (ScanToken*)(unsigned long)index;
    }
    ScanToken* next(ScanToken* token) const {
        int index=(int)(unsigned long)token+1;
        for (; index <= hashMod; ++index) if (elem[index].key != (unsigned long)-1) break;
        return (ScanToken*)(unsigned long)index;
    }
    hkBool valid(ScanToken* token) const { return (int)(unsigned long)token <= hashMod; }
    unsigned long key(ScanToken* token) const { return elem[(int)(unsigned long)token].key; }
    unsigned long value(ScanToken* token) const { return elem[(int)(unsigned long)token].value; }
};
struct EntryMap {
    MapStorage table;
    ScanToken* GetFirstIterator() const { return table.first(); }
    ScanToken* getNext(ScanToken* token) const { return table.next(token); }
    hkBool isValid(ScanToken* token) const { return table.valid(token); }
    hkpCollidable* GetIteratorKey(ScanToken* token) const { return (hkpCollidable*)table.key(token); }
    int getValue(ScanToken* token) const { return (int)table.value(token); }
};
void __cdecl DispatchToOffsetTarget(hkpCollidable*, unsigned short);
struct UpdateState {
    int unk00; int unk04; int unk08; Tree* tree;
    FUN_00d08ff0_t gather;
    int unk20;
    unsigned char incremental;
    int gatherMode;
    int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    hkArray<hkpCollidable*> nodes;
    EntryMap entries;
    unsigned char fullScan; int scanStart; int scanLimit;
    unsigned char unk68; unsigned char dirty;
    __declspec(noinline) bool CheckCollidables(hkArrayBase<hkpCollidable*>&);
    unsigned short hkpAabbTreeWorldManager_getNodeIdx(hkpCollidable*);
    bool isActive(int& value, hkpCollidable* node) { unsigned short id = hkpAabbTreeWorldManager_getNodeIdx(node); return value == 1 && id != 0xffff; }
    void hkpAabbTreeWorldManager_pushBackToActiveList(hkpCollidable*);
    void hkpAabbTreeWorldManager_buildActiveTree(hkArrayBase<hkpCollidable*>&, int, int);
    void hkpAabbTreeWorldManager_buildKdTree(FUN_00d08ff0_t*, hkArrayBase<hkpCollidable*>&, int, int, int);
    void hkpAabbTreeWorldManager_incrementalBuild(int, int);
};
__forceinline void hkMonitorStream::TimerCommand::setTime() {
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}
// A unit-local view: the original inlines a differently shaped variant of this Havok accessor.
struct hkMonitorStream_hkpaabbtreeworldmanager_ehsc_noehsc_variant : hkMonitorStream { bool memoryAvailable() const; };
inline bool hkMonitorStream_hkpaabbtreeworldmanager_ehsc_noehsc_variant::memoryAvailable() const { return m_end.m_storage < m_capacityMinus16.m_storage; }
inline char* __cdecl hkMonitorStream::getEnd() { return m_end.m_storage; }
inline void __cdecl hkMonitorStream::setEnd(char* e) { m_end.m_storage = e; }
inline hkMonitorStream& hkMonitorStream::getInstance() { return *(hkMonitorStream*)TlsGetValue(DAT_0126835c); }
static __forceinline void hkTimerBeginList(const char* name, const char* first) {
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (static_cast<const hkMonitorStream_hkpaabbtreeworldmanager_ehsc_noehsc_variant&>(mStream).memoryAvailable()) {
        hkMonitorStream::TimerBeginListCommand* h = (hkMonitorStream::TimerBeginListCommand*)mStream.getEnd();
        h->m_commandAndMonitor = name;
        h->m_nameOfFirstSplit = first;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}
static __forceinline void hkTimerSplit(const char* name) {
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (static_cast<const hkMonitorStream_hkpaabbtreeworldmanager_ehsc_noehsc_variant&>(mStream).memoryAvailable()) {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)mStream.getEnd();
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}
static __forceinline void hkAddValue(const char* name, float value) {
    hkMonitorStream& mStream = hkMonitorStream::getInstance();
    if (static_cast<const hkMonitorStream_hkpaabbtreeworldmanager_ehsc_noehsc_variant&>(mStream).memoryAvailable()) {
        hkMonitorStream::AddValueCommand* h = (hkMonitorStream::AddValueCommand*)mStream.getEnd();
        h->m_commandAndMonitor = name;
        h->m_value = value;
        mStream.setEnd((char*)(h + 1));
    }
}
// @fnv 0x00d099d0
// src: HAVOK_LIB 0x00d099d0
void UpdateState::hkpAabbTreeWorldManager_incrementalBuild(int arg1, int arg2) {
    CollidableArray inactive(nodes.GetLogicalSize());
    bool changed = false;
    if (incremental) {
        hkTimerBeginList("LtIncrementalBuild", "StClear Tree");
        hkTimerSplit("StFind Inactivated");
        if (dirty) {
            changed = CheckCollidables(inactive);
            hkTimerSplit("StUpdate Inactive Tree");
            Tree* t = tree;
            for (int i=0;i<inactive.GetLogicalSize();++i) {
                    hkpCollidable* node = inactive[i];
                    hkAabb bounds;
                    node->m_pCollisionShape->CalculateAabb(node->getTransform(), 0.0f, bounds);
                    hkAddValue("MiNum of Added Nodes", 1.0f);
                    DispatchToOffsetTarget(inactive[i], t->hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_add(&bounds, node));
            }
            dirty = false;
        }
        hkTimerSplit("StFind Activated");
        Tree* currentTree = tree;
        for (ScanToken* it = entries.GetFirstIterator(); entries.isValid(it); it = entries.getNext(it)) {
            hkpCollidable* node = entries.GetIteratorKey(it);
            int state = entries.getValue(it);
            if (isActive(state, node) && node->m_kBroadPhaseHandle.m_type == 1) {
                hkAddValue("MiNum of Removed Nodes", 1.0f);
                currentTree->hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_remove(hkpAabbTreeWorldManager_getNodeIdx(node));
                hkpAabbTreeWorldManager_pushBackToActiveList(node);
            }
        }
        hkTimerSplit("StUpdate Active");
        hkpAabbTreeWorldManager_buildActiveTree(nodes, arg1, arg2);
        hkTimerSplit("lt");
    } else {
        hkTimerBeginList("LtDynamicBuild", "StGather");
        nodes.clear();
        hkpAabbTreeWorldManager_gatherCollidablesFromWorld((FUN_00d08ff0_t*)&nodes, gatherMode);
        hkTimerSplit("StClear");
        hkTimerSplit("StRebuild");
        hkpAabbTreeWorldManager_buildKdTree(&gather, nodes, gatherMode, arg1, arg2);
        hkTimerSplit("lt");
    }
    ((FUN_00d08550_Class*)this)->hkpAabbTreeWorldManager_setTreeIsClean();
    if (changed) dirty = true;
}

static __forceinline hkpEntity* getEntityOwner(hkpCollidable* node) {
    return node->m_kBroadPhaseHandle.m_type==1 ? (hkpEntity*)((char*)node+node->m_iOwnerOffset) : 0;
}
__declspec(noinline) bool UpdateState::CheckCollidables(hkArrayBase<hkpCollidable*>& output) {
    if (fullScan) {
        for (int index=nodes.GetLogicalSize()-1;index>=0;--index) {
            hkpEntity* owner=getEntityOwner(nodes[index]);
            if (owner) {
                unsigned char activeValue;
                owner->isActive_00c9bff0(&activeValue);
                bool active=activeValue!=0;
                if (!active) {
                    output.pushBackUnchecked(nodes[index]);
                    nodes.removeAt(index);
                }
            }
        }
        return true;
    } else {
        int last=nodes.GetLogicalSize()-1;
        scanStart=scanStart<last?scanStart:last;
        int scanned=0;
        for (int count=0;count<scanLimit;++count) {
            int index=scanStart--;
            if (index<0) {scanStart=nodes.GetLogicalSize(); break;}
            hkpEntity* owner=getEntityOwner(nodes[index]);
            if (owner) {
                unsigned char activeValue;
                owner->isActive_00c9bff0(&activeValue);
                bool active=activeValue!=0;
                if (!active) {
                    output.pushBackUnchecked(nodes[index]);
                    nodes.removeAt(index);
                }
            }
            ++scanned;
        }
        return scanned==nodes.GetLogicalSize();
    }
}
