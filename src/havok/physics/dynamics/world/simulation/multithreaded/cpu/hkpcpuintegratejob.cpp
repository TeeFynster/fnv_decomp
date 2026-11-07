// src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpuintegratejob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpuintegratejob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkMonitorStream.h"

struct Owner {
    unsigned int field00, field04, field08, field0c;
    unsigned int field10, field14, field18, field1c;
    unsigned int field20, field24, field28, field2c;
    void* payload;
};
struct Item {
    unsigned int value;
    unsigned char* first;
    unsigned char* second;
    unsigned int key;
    unsigned short kind;
    unsigned char flags;
    unsigned char flagsHigh;
    unsigned short firstSize;
    unsigned short field16;
    unsigned short secondSize;
    unsigned short field1a;
    unsigned int extra;
    unsigned short extraKind;
};
struct Entry {
    Item* item;
    unsigned short firstIndex;
    unsigned short secondIndex;
};
struct Record {
    unsigned int key;
    unsigned int value;
    unsigned int extra;
    unsigned char* first;
    unsigned char* second;
    unsigned short kind;
    unsigned short extraKind;
    unsigned short firstIndex;
    unsigned short secondIndex;
};
struct Block {
    Block() { count = 0; firstEnd = 0; next = 0; }
    static void* operator new(unsigned int) throw();
    Block* next;
    Owner* owner;
    void* payload;
    unsigned int firstOffset;
    unsigned int firstEnd;
    int count;
    Record firstRecord;
};
struct Group {
    Group() { next = 0; boundary = false; count = 0; limit = 0; }
    static void* operator new(unsigned int) throw();
    Group* next;
    Owner* owner;
    void* payload;
    unsigned int firstOffset;
    unsigned int secondOffset;
    unsigned int firstLength;
    unsigned int secondLength;
    bool boundary;
    unsigned short count;
    Group* limit;
    unsigned int field24, field28, field2c;
};
struct BlockList { Block* head; unsigned int count; };
struct EntryListNode { Entry* data; int count; };
struct Special { Entry entry; Record* record; unsigned int field0c; };
struct SpecialList { Special* data; int count; };
struct Allocator { virtual void unused(); virtual void* allocate(unsigned int size); };
struct AllocationContext { unsigned int field00, field04, field08, field0c; Allocator* allocator; void* allocate(unsigned int size) { return allocator->allocate(size); } };
void* __cdecl hkMemoryRouter_getInstance();
inline void* Block::operator new(unsigned int) throw() { return ((AllocationContext*)hkMemoryRouter_getInstance())->allocate(0x1000); }
inline void* Group::operator new(unsigned int) throw() { return ((AllocationContext*)hkMemoryRouter_getInstance())->allocate(0x30); }

struct SizePointer { unsigned int* value; SizePointer(unsigned int* p):value(p) {} unsigned int& operator*() const { return *value; } };
// Allocates a Block, links it into the block list, copies entries into records, and optionally creates a Group tracking size ranges.
// @fnv 0x00d94ec0
// src: HAVOK_LIB 0x00d94ec0
static __declspec(noinline) void __cdecl createAndAppendNewTask(BlockList* blocks, Owner* owner, Group** groupHead, Block** blockTail,
    Group** groupTail, Group** rangeBegin, Group** rangeEnd,
    SizePointer firstSizeArg, unsigned int* secondSize, EntryListNode* entries,
    void** currentState, void* state, unsigned short** count,
    bool suppressHead, bool makeGroup, SpecialList* specials)
{
    unsigned int* firstSize = firstSizeArg.value;
    unsigned int firstOffset = *firstSize;
    unsigned int secondOffset = *secondSize;
    Block* block = new Block;
    if (*blockTail == 0) {
        if (!suppressHead) {
            blocks->head = block;
            blocks->count = 0;
        }
    } else {
        (*blockTail)->next = block;
        (*blockTail)->firstEnd = *firstSize;
    }
    ++blocks->count;
    block->owner = owner;
    block->count = entries->count;
    block->payload = owner->payload;
    block->firstOffset = firstOffset;
    int length = entries->count;
    for (int i = 0; i < length; ++i) {
        Record* record = &block->firstRecord + i;
        Entry* entry = &entries->data[i];
        Item* item = entry->item;
        if (item->flags & 0x0b) {
            int n = specials->count;
            specials->count = n + 1;
            Special* special = &specials->data[n];
            special->entry = *entry;
            special->record = record;
            firstSize = *(unsigned int* volatile*)&firstSizeArg.value;
        }
        record->key = item->key;
        record->kind = item->kind;
        record->value = item->value;
        record->extra = item->extra;
        record->extraKind = item->extraKind;
        unsigned int secondIndex = entry->secondIndex;
        unsigned short firstIndex = entry->firstIndex;
        record->firstIndex = firstIndex + 1;
        record->secondIndex = secondIndex + 1;
        record->first = item->first + 0xf0;
        record->second = item->second + 0xf0;
        *firstSize += item->firstSize;
        *secondSize += item->secondSize * 4;
    }
    entries->count = 0;
    *firstSize += 0x10;
    block->firstEnd = *firstSize;
    *secondSize = (*secondSize + 0xf) & ~0xf;
    *blockTail = block;
    if (makeGroup) {
        Group* group = new Group;
        if (*groupTail) (*groupTail)->next = group;
        if (state != *currentState) {
            if (!state) *groupHead = group;
            *currentState = state;
            if (*groupTail) {
                Group* cursor = *rangeBegin;
                unsigned short size = **count;
                while (cursor && cursor != *rangeEnd) {
                    cursor->count = size;
                    cursor->limit = *rangeEnd;
                    cursor = cursor->next;
                }
                (*groupTail)->boundary = true;
                *count = &(*groupTail)->count;
            }
            *rangeBegin = *rangeEnd;
            *rangeEnd = group;
        }
        ++**count;
        group->owner = owner;
        group->payload = owner->payload;
        group->firstOffset = firstOffset;
        group->secondOffset = secondOffset;
        group->firstLength = *firstSize - firstOffset;
        group->secondLength = *secondSize - secondOffset;
        *groupTail = group;
    }
}

void call_target(BlockList* blocks, Owner* owner, Group** groupHead, Block** blockTail,
    Group** groupTail, Group** rangeBegin, Group** rangeEnd,
    unsigned int* firstSize, unsigned int* secondSize, EntryListNode* entries,
    void** currentState, void* state, unsigned short** count,
    bool suppressHead, bool makeGroup, SpecialList* specials) {
    createAndAppendNewTask(blocks, owner, groupHead, blockTail, groupTail, rangeBegin, rangeEnd,
        firstSize, secondSize, entries, currentState, state, count, suppressHead, makeGroup, specials);
}

#include <xmmintrin.h>
#include <windows.h>
extern "C" void _ReadWriteBarrier();
inline void* operator new(unsigned int, void* ptr) { return ptr; }
__declspec(nothrow) void* hkMemoryRouter_getInstance();
__declspec(nothrow) void hkArrayUtil__reserve(void*,void*,int,int);
extern DWORD DAT_0126835c;
struct FlagByte {
    char value;
    FlagByte() {}
    FlagByte(bool b) : value((char)b) {}
    operator bool() const { return value != 0; }
    FlagByte& operator=(bool b) { value=(char)b; return *this; }
    FlagByte operator==(bool b) const { return int(value)==int(b); }
    FlagByte operator!=(bool b) const { return int(value)!=int(b); }
};
struct TaskAllocator {
    virtual void unused();
    virtual void* allocate(int bytes) throw();
    virtual void release(void* ptr,int bytes) throw();
    virtual void unused0c();
    virtual void freeBuffer(void* ptr,int bytes) throw();
    template<class T> void freeElements(void* ptr,int n) {
        const int stride=sizeof(T);
        freeBuffer(ptr,n*stride);
    }
};
struct TaskMemory {
    unsigned char* stackTop;
    int unknown04,unknown08;
    TaskAllocator* temporary;
    TaskAllocator* heap;
    static TaskMemory& GetMonitorStream() { return *(TaskMemory*)hkMemoryRouter_getInstance(); }
    TaskAllocator& tempAllocator() { return *temporary; }
    TaskAllocator& heapAllocator() { return *heap; }
    template<class T> T* takeStack(int n) {
        unsigned char* result=stackTop;
        stackTop += (n*int(sizeof(T))+127)&~127;
        return (T*)result;
    }
    void returnStack(void* ptr) { stackTop=(unsigned char*)ptr; }
};
struct HeapPolicy { static TaskAllocator& get(const void*) { return TaskMemory::GetMonitorStream().heapAllocator(); } };
struct TempPolicy { static TaskAllocator& get(const void*) { return TaskMemory::GetMonitorStream().tempAllocator(); } };
template<class T> struct SmallList {
    T* data;
    unsigned short count;
    unsigned short capacity;
    const T* begin() const { return data; }
    const T* end() const { return data+count; }
};
template<class T> __forceinline void defaultRange(T* p,int n) { for(int i=0;i<n;++i) new(p+i) T; }
template<class T> __forceinline void copyRange(T* p,int n,const T& value) { for(int i=0;i<n;++i) new(p+i) T(value); }
template<class T> __forceinline void destroyRange(T* p,int n) { for(int i=0;i<n;++i) (p+i)->~T(); }

template<class T> __forceinline T bytesCopy(const T& src) { T dst; for(unsigned i=0;i<sizeof dst;++i) ((unsigned char*)&dst)[i]=((const unsigned char*)&src)[i]; return dst; }

struct DelayInit {};
template<class T> class TaskArrayBase {
protected:
    T* data;
    int count;
    int capacity;
public:
    TaskArrayBase(DelayInit) {}
    TaskArrayBase() : data(0), count(0), capacity((int)0x80000000) {}
    int GetLogicalSize() const { return count; }
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data+count; }
    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }
    void clear() { destroyRange(data,count); count=0; }
    void setSizeUnchecked(int n) { destroyRange(data+n,count-n); defaultRange(data+count,n-count); count=n; }
    void reserveWith(TaskAllocator& alloc,int n) {
        int old=capacity&0x3fffffff;
        if (old<n) { int grown=old+old; if(n>=grown) grown=n; hkArrayUtil__reserve(&alloc,this,grown,sizeof(T)); }
    }
    void pushBackUnchecked(const T& entry) {
        copyRange(data+count,1,entry);
        ++count;
    }
    T* expandByUnchecked(int n) { int old=count; count=old+n; defaultRange(data+old,count-old); return data+old; }
    void releaseWith(TaskAllocator& alloc) {
        clear();
        if(!(capacity&(int)0x80000000)) alloc.freeElements<T>(data,capacity&0x3fffffff);
        data=0; capacity=(int)0x80000000;
    }
};

template<class T,class Policy=HeapPolicy> class TaskArray : public TaskArrayBase<T> {
public:
    TaskArray(DelayInit d) : TaskArrayBase<T>(d) {}
    TaskArray() : TaskArrayBase<T>() {}
    void reserve(int n) { reserveWith(Policy::get(this),n); }
    void closeArray() { releaseWith(Policy::get(this)); }
};
template<class T> class StackArray : public TaskArray<T> {
    T* local;
public:
    StackArray(int n) { data=TaskMemory::GetMonitorStream().takeStack<T>(n); capacity=n|(int)0x80000000; local=data; }
    void closeStack() {
        if(data==local) clear();
        TaskMemory::GetMonitorStream().returnStack(local);
        TaskArray<T>::closeArray();
    }
};
template<class T> T* taskTempAllocate(int n) { return (T*)TaskMemory::GetMonitorStream().temporary->allocate(n*int(sizeof(T))); }
template<class T> void taskTempFree(T* ptr,int n) { TaskMemory::GetMonitorStream().temporary->release(ptr,n*int(sizeof(T))); }
template<class T> T* taskHeapAllocate(int n,int) { return (T*)TaskMemory::GetMonitorStream().heap->allocate(n*int(sizeof(T))); }
struct IndexPair { unsigned long key,value; };
class EntityIndexMap {
    IndexPair* data;
    int count,mask;
    void FUN_00cb1830(void*,int) throw();
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(TaskAllocator*,unsigned long,unsigned long) throw();
    unsigned long FUN_00cb1930(unsigned long,unsigned long) const throw();
    void FUN_00cb1a90(TaskAllocator*) throw();
    void Object_DoNothing() throw();
    void growMap(TaskAllocator*,int) throw();
public:
    EntityIndexMap(void* ptr,int bytes) { FUN_00cb1830(ptr,bytes); }
    void closeMap() { FUN_00cb1a90(TaskMemory::GetMonitorStream().heap); Object_DoNothing(); }
    void insert(unsigned long key,unsigned long val) { hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(TaskMemory::GetMonitorStream().heap,key,val); }
    unsigned long FindValueForKey(unsigned long key,unsigned long value) const { return FUN_00cb1930(key,value); }
};
__declspec(noinline) unsigned long EntityIndexMap::FUN_00cb1930(unsigned long key,unsigned long fallback) const throw() {
 if(mask>0) {
  unsigned i=((key>>4)*2654435761ul)&mask;
  while(data[i].key!=~0ul) {
   if(data[i].key==key) return data[i].value;
   i=(i+1)&mask;
  }
 }
 return fallback;
}

struct TaskEntity;
struct __declspec(align(16)) InternalConstraint {
    void* m_pHavokConstraint;
    TaskEntity* m_kActorEntries[2];
    void* atoms;
    unsigned short atomSize;
    unsigned char m_ucCallbackRequest;
    unsigned char m_priority;
    unsigned short m_iSchemaByteSize;
    unsigned short unknown16;
    unsigned short m_iSolverElementTemporaryCount;
    unsigned char m_ucByteAfterTemporaryCount;
    FlagByte m_kRuntimeFlagByte;
    void* m_pRuntime;
    unsigned short m_usTrailingValue;
    unsigned short unknown22;
    int unknown24,unknown28,unknown2c;
    void* getAtoms() const { return atoms; }
    unsigned short getAtomsSize() const { return atomSize; }
};
struct TaskTransform { __m128 axis0,axis1,axis2,translation; };
struct TaskEntity {
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown2c;
    int unknown30;
    int unknown34;
    int unknown38;
    int unknown3c;
    int unknown40;
    int unknown44;
    int unknown48;
    int unknown4c;
    int unknown50;
    int unknown54;
    int unknown58;
    int unknown5c;
    int unknown60;
    int unknown64;
    int unknown68;
    int unknown6c;
    int unknown70;
    int unknown74;
    int unknown78;
    int unknown7c;
    int unknown80;
    int unknown84;
    int unknown88;
    int unknown8c;
    int unknown90;
    int unknown94;
    int unknown98;
    int unknown9c;
    int unknowna0;
    unsigned int m_uiFilterInfo;
    unsigned short storageIndex,unknownaa;
    SmallList<InternalConstraint> constraints;
    int unknownb4;
    int unknownb8;
    int unknownbc;
    int unknownc0;
    int unknownc4;
    int unknownc8;
    int unknowncc;
    int unknownd0;
    int unknownd4;
    int unknownd8;
    int unknowndc;
    int unknowne0;
    int unknowne4;
    int unknowne8;
    int unknownec;

    TaskTransform transform;
    const SmallList<InternalConstraint>& getConstraintMasters() const { return constraints; }
    TaskEntity* getMotion() { return this; }
    const TaskTransform& getTransform() const { return transform; }
};
struct SolverStats { int unknown00,maximumSchemaSize,schemaSize,m_iSolverResultCount; };
struct SceneIsland {
    int unknown00;
    SolverStats m_kConstraintInfo;
    int unknown14,unknown18;
    int m_iConstraintCount;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown2c;
    int unknown30;
    int unknown34;
    int unknown38;
    int unknown3c;
    int unknown40;
    int unknown44;

    TaskArray<TaskEntity*> entities;
    const TaskArray<TaskEntity*>& GetEntities() const { return entities; }
};
struct JobHeader {
    int unknown00,unknown04,unknown08,unknown0c,unknown10,unknown14,unknown18,unknown1c;
    int unknown20,unknown24,unknown28,unknown2c;
    void* m_pAccumulatorA;
    void* m_pVelocityAccumulatorB;
    unsigned short m_usValueAt38,m_usValueAt3A;
    unsigned char* m_pByteArrayAt3C;
    int* m_pIntegerArrayAt40;
    int unknown44,unknown48,unknown4c,unknown50;
    unsigned short m_usTaskMetadata,unknown56;
    FlagByte m_kFirstTaskFlagByte,m_kSecondTaskFlagByte;
};
struct __declspec(align(128)) BuildTask {
    struct BuildTaskData {
        void* m_kBridgeAtoms;
        void* ms_uiThreadLocalStorageIndex;
        void* m_pRuntime;
        const TaskTransform* m_kBodyALocalFrame;
        const TaskTransform* m_kBodyBLocalFrame;
        unsigned short m_iAtomsSize,m_usTrailingValue,m_usSecondTrailingValue,m_usThirdTrailingValue;
    };
    BuildTask* m_next;
    JobHeader* m_pJobHeader;
    void* m_pVelocityAccumulatorA;
    unsigned char* m_akBufferStates;
    unsigned char* m_akBuildBuffer;
    int m_iBuildItemCount;
    BuildTaskData m_akBuildTaskEntries[144];
    static void* operator new(unsigned int n) throw() { return TaskMemory::GetMonitorStream().heap->allocate(n); }
    BuildTask() { m_iBuildItemCount=0; m_akBuildBuffer=0; m_next=0; }
};
struct __declspec(align(16)) SolveTask {
    SolveTask* m_next;
    JobHeader* m_pJobHeader;
    void* m_pVelocityAccumulatorA;
    const unsigned char* m_akBufferStates;
    int* m_pIntegerValues;
    int m_iFirstSolveTaskValue,m_iSecondSolveTaskValue;
    FlagByte m_kSolveTaskFlagByte;
    unsigned short m_usSolverElementCount;
    SolveTask* m_pNextSolveTask;
    int unknown24,unknown28,unknown2c;
    static void* operator new(unsigned int n) throw() { return TaskMemory::GetMonitorStream().heap->allocate(n); }
    SolveTask() { m_next=0; m_kSolveTaskFlagByte=false; m_usSolverElementCount=0; m_pNextSolveTask=0; }
};
struct BuildCollection {
    struct ConstraintBuildTaskLink { const InternalConstraint* m_pInternalConstraint; BuildTask::BuildTaskData* m_pBuildTaskEntry; };
    BuildTask* m_pBuildTask;
    int m_iEntryCount;
    ConstraintBuildTaskLink* m_pInternalConstraint;
    int m_iEntryCapacity;
};
struct SolveCollection { SolveTask* m_pTasks; unsigned short m_usTaskCount; };
// A unit-local view: the original inlines a differently shaped variant of this Havok accessor.
// hkMonitorStream as the original reads it in FUN_00d95130's value records: bare char* members and a flat value
// command. The real header's hkPadSpu members and Command-based records change that function's register choice.
// src: HAVOK_SRC (shape)
struct hkMonitorStream_raw {
    struct AddValueCommand { const char* m_commandAndMonitor; float m_value; };
    char* m_start; char* m_end; char* m_capacity; char* m_capacityMinus16;
    static hkMonitorStream_raw& get();
    FlagByte __cdecl memoryAvailable() { return m_end<m_capacityMinus16; }
    char* __cdecl getEnd() { return m_end; }
    void __cdecl setEnd(char* ptr) { m_end=ptr; }
};
struct hkMonitorStream_hkpcpuintegratejob : hkMonitorStream { FlagByte __cdecl memoryAvailable(); };
__forceinline FlagByte __cdecl hkMonitorStream_hkpcpuintegratejob::memoryAvailable() { return m_end.m_storage<m_capacityMinus16.m_storage; }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.m_storage; }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end.m_storage=ptr; }
template<class T> T* byteAdvance(T* ptr,long offset) { return (T*)((char*)ptr+offset); }
template<class A,class B> int byteDistance(A* first,B* last) { return (int)((char*)last-(char*)first); }
struct __declspec(align(8)) ProbeEntry {
    const InternalConstraint* constraint;
    unsigned short firstIndex;
    unsigned short secondIndex;
};
struct __declspec(align(16)) ProbeCallback : ProbeEntry {
    BuildTask::BuildTaskData* output;
};

template<bool Partial> static __forceinline void appendProbe(const JobHeader* header,
    BuildCollection* builds, SolveCollection* solves,
    BuildTask*& previousBuild, SolveTask*& previousSolve,
    SolveTask*& priorBatch, SolveTask*& thisBatch,
    unsigned char*& schema, int*& temporary,
    StackArray<ProbeEntry>& pending, int& lastBatch, int batch, unsigned short*& batchSize,
    FlagByte ppuOnly, FlagByte makeSolve, TaskArray<ProbeCallback>& callbacks)
{
    unsigned char* schemaBegin = schema;
    int* tempBegin = temporary;
    {
        BuildTask* task = new BuildTask;
        if (!previousBuild) {
            if (!ppuOnly) { builds->m_pBuildTask = task; builds->m_iEntryCount = 0; }
        } else {
            previousBuild->m_next = task;
            previousBuild->m_akBuildBuffer = schema;
        }
        builds->m_iEntryCount++;
        int total;
        if (Partial) {
        JobHeader* metadata=bytesCopy(const_cast<JobHeader*>(header));
        task->m_pJobHeader=metadata;
        task->m_iBuildItemCount=pending.GetLogicalSize();
        task->m_pVelocityAccumulatorA=metadata->m_pAccumulatorA;
        task->m_akBufferStates=schemaBegin;
        total=pending.GetLogicalSize();
        } else {
        task->m_pJobHeader = const_cast<JobHeader*>(header);
        task->m_iBuildItemCount = pending.GetLogicalSize();
        task->m_pVelocityAccumulatorA = header->m_pAccumulatorA;
        task->m_akBufferStates = schemaBegin;
        total = pending.GetLogicalSize();
        }
        for (int index = 0; index < total; ++index) {
            ProbeEntry& entry = pending[index];
            const InternalConstraint* constraint = entry.constraint;
            BuildTask::BuildTaskData* output = &task->m_akBuildTaskEntries[index];
            if (constraint->m_ucCallbackRequest & 11) {
                ProbeCallback* callback = callbacks.expandByUnchecked(1);
                *static_cast<ProbeEntry*>(callback) = entry;
                callback->output = output;
            }
            output->m_kBridgeAtoms = constraint->getAtoms();
            output->m_iAtomsSize = constraint->getAtomsSize();
            output->ms_uiThreadLocalStorageIndex = constraint->m_pHavokConstraint;
            output->m_pRuntime = constraint->m_pRuntime;
            output->m_usTrailingValue = constraint->m_usTrailingValue;
            int first = entry.firstIndex;
            int second = entry.secondIndex;
            output->m_usSecondTrailingValue = first + 1;
            output->m_usThirdTrailingValue = second + 1;
            output->m_kBodyALocalFrame = &constraint->m_kActorEntries[0]->getMotion()->getTransform();
            output->m_kBodyBLocalFrame = &constraint->m_kActorEntries[1]->getMotion()->getTransform();
            schema = byteAdvance(schema, constraint->m_iSchemaByteSize);
            temporary += constraint->m_iSolverElementTemporaryCount;
        }
        pending.clear();
        schema = byteAdvance(schema, 16);
        task->m_akBuildBuffer = schema;
        temporary = reinterpret_cast<int*>(((unsigned long)(temporary) + 15) & ~15);
        previousBuild = task;
    }
    if (makeSolve) {
        SolveTask* task = new SolveTask;
        if (previousSolve) previousSolve->m_next = task;
        if (batch != lastBatch) {
            if (batch == 0) solves->m_pTasks = task;
            lastBatch = batch;
            if (previousSolve) {
                SolveTask* walk = priorBatch;
                unsigned short size = *batchSize;
                while (walk && walk != thisBatch) {
                    walk->m_usSolverElementCount = size;
                    walk->m_pNextSolveTask = thisBatch;
                    walk = walk->m_next;
                }
                previousSolve->m_kSolveTaskFlagByte = true;
                batchSize = &previousSolve->m_usSolverElementCount;
            }
            priorBatch = thisBatch;
            thisBatch = task;
        }
        ++*batchSize;
        task->m_pJobHeader = const_cast<JobHeader*>(header);
        task->m_pVelocityAccumulatorA = header->m_pAccumulatorA;
        task->m_akBufferStates = schemaBegin;
        task->m_pIntegerValues = tempBegin;
        task->m_iFirstSolveTaskValue = byteDistance(schemaBegin, schema);
        task->m_iSecondSolveTaskValue = byteDistance(tempBegin, temporary);
        previousSolve = task;
    }
}

extern const char str_010d3f1c[], str_010d3d60[], str_010d3f08[], str_010d3d70[], str_010c41f8[];

union EarlyPhase { DWORD ticks; TaskEntity* const* bodies; int pass; };
union FinalPhase { DWORD ticks; int bytes; };



struct SceneInput { SceneInput(SceneIsland* v):p(v) {} SceneIsland* p;  operator SceneIsland*() const { return p; } SceneIsland* operator->() const { return p; } };


static __forceinline void finalizeCounts(JobHeader* state) {
        unsigned int amount = state->m_usTaskMetadata + 1;
        state->m_pVelocityAccumulatorB = byteAdvance(state->m_pAccumulatorA, amount << 7);
        state->m_usValueAt38 = ((amount-1) >> 7) + 1;
        state->m_usValueAt3A = ((amount-1) >> 7) + 1;
}

// @fnv 0x00d95130
// src: HAVOK_LIB 0x00d95130
void createBuildJacobianAndSolveJacobianTaskCollection(SceneInput island, FlagByte coherent, JobHeader* header,
    BuildCollection* builds, SolveCollection* solves)
{
    TaskArray<ProbeEntry,TempPolicy> normal((DelayInit())); TaskArray<ProbeEntry,TempPolicy> high((DelayInit()));
     FinalPhase finalPhase;
    const DWORD& initialTimerIndex=DAT_0126835c;
    SceneIsland* scene = island;
    {
        hkMonitorStream& stream=*(hkMonitorStream*)TlsGetValue(initialTimerIndex);
        if(static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable()) {
            hkMonitorStream::TimerCommand* event=(hkMonitorStream::TimerCommand*)bytesCopy(stream.getEnd());
            event->m_commandAndMonitor=str_010d3f1c; _ReadWriteBarrier();
            DWORD ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->m_time0=ticks;
            stream.setEnd((char*)(event+1));
        }
    }
    {
    TaskEntity* const* bodies = scene->GetEntities().begin();
    int bodyCount = scene->GetEntities().GetLogicalSize();
    int normalCapacity=scene->m_iConstraintCount;
    int& bodyBytes=finalPhase.bytes;
    bodyBytes=bodyCount*4;
    TaskEntity* const* bodyEnd=byteAdvance(bodies,bodyBytes);
    new(&normal) TaskArray<ProbeEntry,TempPolicy>;
    normal.reserve(normalCapacity);
    int highCapacity=scene->m_iConstraintCount;
    new(&high) TaskArray<ProbeEntry,TempPolicy>;
    high.reserve(highCapacity);
    StackArray<ProbeCallback> callbacks(scene->m_iConstraintCount);
    int allNormal = 1;
    {
        int mapWords = 64;
        while (mapWords < bodyCount) mapWords *= 2;
        mapWords *= 4;
        unsigned long* mapStorage = taskTempAllocate<unsigned long>(mapWords);
        {
            EntityIndexMap map(mapStorage, mapWords * sizeof(unsigned long));
            for (int index = 0; index < bodyCount; ++index) map.insert((unsigned long)(bodies[index]), index);
            TaskEntity* const* body = bodies;
            unsigned int accumulatorOffset = 128;
            int index;
            for (body = bodies, index = 0; body < bodyEnd; ++body, ++index) {
                TaskEntity* entity = *body;
                if (accumulatorOffset != entity->m_uiFilterInfo) entity->m_uiFilterInfo = accumulatorOffset;
                accumulatorOffset += 128;
                const InternalConstraint* constraint = entity->getConstraintMasters().begin();
                const InternalConstraint* end = entity->getConstraintMasters().end();
                for (; constraint < end; ++constraint) {
                    ProbeEntry entry;
                    entry.constraint = constraint;
                    {
                        int slave = 1 - constraint->m_ucByteAfterTemporaryCount;
                        unsigned short* indices = (&entry.firstIndex);
                        indices[constraint->m_ucByteAfterTemporaryCount] = index;
                        indices[slave] = (unsigned short)map.FindValueForKey((unsigned long)(constraint->m_kActorEntries[slave]), 0xffff);
                    }
                    allNormal &= constraint->m_kRuntimeFlagByte;
                    if (constraint->m_priority < 4) normal.pushBackUnchecked(entry);
                    else high.pushBackUnchecked(entry);
                }
            }
            map.closeMap();
        }
        taskTempFree(mapStorage, mapWords);
    }
    {
        hkMonitorStream_raw& stream = hkMonitorStream_raw::get();
        if (stream.memoryAvailable()) {
            hkMonitorStream_raw::AddValueCommand* event = reinterpret_cast<hkMonitorStream_raw::AddValueCommand*>(stream.getEnd());
            event->m_commandAndMonitor = str_010d3d60;
            event->m_value = (float)bodyCount;
            stream.setEnd((char*)(event+1));
        }
    }
    {
        hkMonitorStream_raw& stream = hkMonitorStream_raw::get();
        if (stream.memoryAvailable()) {
            hkMonitorStream_raw::AddValueCommand* event = reinterpret_cast<hkMonitorStream_raw::AddValueCommand*>(stream.getEnd());
            SceneIsland* valueOwner=island.p;
            event->m_commandAndMonitor = str_010d3f08;
            event->m_value = (float)valueOwner->m_iConstraintCount;
            stream.setEnd((char*)(event+1));
        }
    }
    {
        hkMonitorStream_raw& stream = hkMonitorStream_raw::get();
        if (stream.memoryAvailable()) {
            hkMonitorStream_raw::AddValueCommand* event = reinterpret_cast<hkMonitorStream_raw::AddValueCommand*>(stream.getEnd());
            SceneIsland* valueOwner=island.p;
            event->m_commandAndMonitor = str_010d3d70;
            event->m_value = (float)valueOwner->m_kConstraintInfo.m_iSolverResultCount;
            stream.setEnd((char*)(event+1));
        }
    }
    JobHeader* flagHeader=bytesCopy(header);
    flagHeader->m_kSecondTaskFlagByte = allNormal == 0;
    flagHeader->m_kFirstTaskFlagByte = bytesCopy(bool(flagHeader->m_kSecondTaskFlagByte));
    FlagByte makeSolve = !flagHeader->m_kFirstTaskFlagByte;
    unsigned char* schema = flagHeader->m_pByteArrayAt3C;
    int* temporary = flagHeader->m_pIntegerArrayAt40;
    int batch = -1;
    int lastBatch = -1;
    unsigned short* batchSize = &solves->m_usTaskCount;
    *batchSize = 0;
    BuildTask* previousBuild = 0;
    SolveTask* previousSolve = 0;
    SolveTask* priorBatch = 0;
    SolveTask* thisBatch = 0;
    StackArray<ProbeEntry> pending(144);
    int* groups = (int*)TaskMemory::GetMonitorStream().temporary->allocate(finalPhase.bytes);
    for (int pass = 0; pass < 2; ++pass) {
        FlagByte ppuOnly = false;
        TaskArray<ProbeEntry,TempPolicy>* source;
        if (pass) source = &high;
        else { source = &normal; previousBuild = 0; }
        while (source->GetLogicalSize()) {
            for (int index = 0; index < bodyCount; groups[index++] = 0) {}
            int group = 1;
            ++batch;
            ProbeEntry* cursor = source->begin();
            const ProbeEntry* end = source->end();
            ProbeEntry* deferred = source->begin();
            for (; cursor < end; ++cursor) {
                const ProbeEntry& entry = *cursor;
                int fixedGroup = 0;
                int& a = entry.firstIndex == 0xffff ? fixedGroup : groups[entry.firstIndex];
                int& b = entry.secondIndex == 0xffff ? fixedGroup : groups[entry.secondIndex];
                if (pending.GetLogicalSize() == 144) {
                    appendProbe<false>(header, builds, solves, previousBuild, previousSolve, priorBatch, thisBatch,
                        schema, temporary, pending, lastBatch, batch, batchSize, ppuOnly, makeSolve, callbacks);
                    group += bool(makeSolve);
                }
                if (coherent && group > 1) {
                    for (; cursor < end; ++cursor) *deferred++ = *cursor;
                    break;
                }
                if ((a && a != group) || (b && b != group)) *deferred++ = *cursor;
                else { pending.pushBackUnchecked(entry); a = group; b = group; }
            }
            if (pending.GetLogicalSize()) appendProbe<true>(header, builds, solves, previousBuild, previousSolve, priorBatch,
                thisBatch, schema, temporary, pending, lastBatch, batch, batchSize, ppuOnly, makeSolve, callbacks);
            source->setSizeUnchecked(int(deferred - source->begin()));
        }
    }
    TaskMemory::GetMonitorStream().temporary->release(groups,finalPhase.bytes);
    if (makeSolve) {
        SolveTask* walk = priorBatch;
        unsigned short size = *batchSize;
        while (walk && walk != thisBatch) {
            walk->m_usSolverElementCount = size;
            walk->m_pNextSolveTask = thisBatch;
            walk = walk->m_next;
        }
        previousSolve->m_kSolveTaskFlagByte = true;
        finalizeCounts(header);
    }
    builds->m_iEntryCapacity = 0;
    builds->m_pInternalConstraint = 0;
    int callbackCount = callbacks.GetLogicalSize();
    if (callbackCount) {
        BuildCollection::ConstraintBuildTaskLink* result = taskHeapAllocate<BuildCollection::ConstraintBuildTaskLink>(callbackCount,3);
        builds->m_iEntryCapacity = callbackCount;
        builds->m_pInternalConstraint = result;
        for (int index = 0; index < callbackCount; ++index) {
            result[index].m_pInternalConstraint = callbacks[index].constraint;
            result[index].m_pBuildTaskEntry = callbacks[index].output;
        }
    }
    pending.closeStack();
    callbacks.closeStack();
    high.closeArray();
    normal.closeArray();
    {
        hkMonitorStream& stream=*(hkMonitorStream*)TlsGetValue(DAT_0126835c);
        if(static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable()) {
            hkMonitorStream::TimerCommand* event=(hkMonitorStream::TimerCommand*)stream.getEnd();
            event->m_commandAndMonitor=str_010c41f8; _ReadWriteBarrier();
            DWORD ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->m_time0=ticks;
            stream.setEnd((char*)(event+1));
        }
    }
    }
}

__forceinline void hkMonitorStream::TimerCommand::setTime() {
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}

namespace fnv_00d95cf0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" int (__stdcall *DAT_00fdf04c)(unsigned long, void*);

typedef short sshort;
typedef unsigned char byte;

extern const char DAT_010cc5c4[], DAT_010cc5bc[], DAT_010cc5b0[], DAT_010d3f64[], DAT_010d3f54[], DAT_01076f38[], DAT_010d3f48[], DAT_010d3f38[], DAT_010d3f2c[];

struct FlagByte {
    char value;
    __forceinline FlagByte() {}
    __forceinline FlagByte(bool b) { value = (char)b; }
    __forceinline operator bool() const { return value != 0; }
    __forceinline FlagByte& operator=(bool b) { value = (char)b; return *this; }
};

template <class E, class S> struct EnumField {
    S storage;
    __forceinline EnumField() {}
    __forceinline EnumField(E e) { storage = (S)e; }
    __forceinline void operator=(E e) { storage = (S)e; }
};

template <class T> struct TlsSlot {
    unsigned long slotId;
    __forceinline T get() const { return (T)TlsGetValue(slotId); }
    __forceinline void set(T p) { DAT_00fdf04c(slotId, (void*)p); }
};

template <class T> struct PaddedPtr {
    T storage;
    __forceinline PaddedPtr() {}
    __forceinline PaddedPtr(T e) : storage(e) {}
    __forceinline void operator=(T e) { storage = e; }
    __forceinline T val() const { return storage; }
    __forceinline T operator->() const { return storage; }
    __forceinline operator T() const { return val(); }
};

struct SyncCheck {
    template <class T> static __forceinline void verify(int id, const T& obj) {}
};



extern TlsSlot<hkMonitorStream*> DAT_0126835c;
extern TlsSlot<int> DAT_012687c8;
}  // namespace fnv_00d95cf0

__forceinline hkMonitorStream& hkMonitorStream::getInstance() { return *fnv_00d95cf0::DAT_0126835c.get(); }
__forceinline hkMonitorStream_raw& hkMonitorStream_raw::get() { return *(hkMonitorStream_raw*)fnv_00d95cf0::DAT_0126835c.get(); }

namespace fnv_00d95cf0 {

struct TaskAllocator {
    virtual ~TaskAllocator();
    virtual void* allocate(int bytes);
    virtual void release(void* p, int bytes);
    virtual void* acquireBuffer(int& reqBytesInOut);
    virtual void releaseBuffer(void* p, int bytes);
    template <class T> __forceinline T* allocBuf(int& reqCountInOut) {
        const int elemSize = sizeof(T);
        int n = reqCountInOut * elemSize;
        void* p = acquireBuffer(n);
        reqCountInOut = n / elemSize;
        return static_cast<T*>(p);
    }
    template <class T> __forceinline void freeBuf(void* p, int count) {
        const int elemSize = sizeof(T);
        releaseBuffer(p, count * elemSize);
    }
};

struct TaskMemory {
    int stack0, stack1, stack2, stack3;
    TaskAllocator* heapAlloc;
    TaskAllocator* debugAlloc;
    TaskAllocator* solverAlloc;
    static __forceinline TaskMemory& GetMonitorStream() { return *(TaskMemory*)hkMemoryRouter_getInstance(); }
    __forceinline TaskAllocator& heap() { return *heapAlloc; }
    __forceinline TaskAllocator& solver() { return *solverAlloc; }
};

template <class T> __forceinline T* solverBufAlloc(int& reqCountInOut) {
    return TaskMemory::GetMonitorStream().solver().allocBuf<T>(reqCountInOut);
}

template <class T> __forceinline void solverBufFree(T* p, int count) {
    TaskMemory::GetMonitorStream().solver().freeBuf<T>(p, count);
}

template <class T> struct TaskArrayBase {
    T* data;
    int count;
    int capacityAndFlags;
    __forceinline int GetLogicalSize() const { return count; }
    __forceinline int getCapacity() const { return capacityAndFlags & 0x3FFFFFFF; }
    __forceinline T* begin() const { return data; }
    __forceinline T& operator[](int i) const { return data[i]; }
};

template <class T> struct TaskArray : TaskArrayBase<T> {
    __forceinline TaskArray() { this->data = 0; this->count = 0; this->capacityAndFlags = 0x80000000; }
};

template <class T> __forceinline T maxVal(T x, T y) { return x > y ? x : y; }

enum PacketKind { PACKET_DYNAMICS = 0, PACKET_MAX = 16 };
enum PacketMode { MODE_INVALID, MODE_ENABLED, MODE_DISABLED };

struct PacketBase {
    __declspec(align(16)) byte subType;
    EnumField<PacketKind, byte> kind;
    EnumField<PacketMode, byte> mode;
    byte unk03;
    unsigned short size;
    sshort affinity;
    __forceinline PacketBase() {}
    __forceinline PacketBase(PacketKind k, unsigned int sub, unsigned short sz, PacketMode m)
        : subType((byte)sub), kind(k), mode(m), size(sz), affinity(-1) {}
};

// hkJobQueue job slot (JobQueueEntry): 0x80 bytes, hkJob header in PacketBase + payload; the queue methods
// 0x00d05190 / 0x00d04b50 take it by reference. Not the console-command Command.
struct JobQueueEntry : PacketBase {
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    __forceinline JobQueueEntry() {}
};

struct __declspec(align(16)) QueueStorage : JobQueueEntry {
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c;
};

struct Queue {
    int __thiscall FUN_00d05190(JobQueueEntry& cmd, int waitMode);
    void __thiscall hkJobQueue_addJob(JobQueueEntry& cmd, int priority);
    void __thiscall hkJobQueue_finishJob(const JobQueueEntry* cmd, int flag);
    void* __thiscall hkJobQueue_lockQueue(void* storage);
    void __thiscall FUN_00d04b00(void* token, const PacketBase& cmd, int priority);
    void __thiscall hkJobQueue_unlockQueue(void* token);
    int __thiscall hkJobQueue_finishAddAndGetNextJob(int kind, int priority, JobQueueEntry& next, int waitMode);
    int __thiscall ProcessCallback(const PacketBase* prev, JobQueueEntry& next, int waitMode);
};

struct QueryStepBase {
    __declspec(align(16)) float substepDt;
    float microStepDt, substepInvDt, frameDt, frameInvDt, invNumSteps, invTotalSteps;
    float maxViolationSq, rhsFactor, virtMassFactor, frictionRhsFactor;
};

struct ConstraintQueryIn : QueryStepBase {
    __forceinline ConstraintQueryIn() {}
    __declspec(align(16)) const void* bodyA;
    const void* bodyB;
    const void* transformA;
    const void* transformB;
    float tau, damping;
    void* constraintInstance;
    void* constraintRuntime;
    void* violatedConstraints;
    unsigned int accumIndexA, accumIndexB;
    void* runtimeMainMem;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};

struct StepTiming { int unk00, unk04, unk08, unk0c; };
struct SolverParams { int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c; };
struct AccelVec { int x, y, z, w; };

struct Context {
    StepTiming timing;
    SolverParams solver;
    AccelVec gravityStep;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130;
    FlagByte buildOnSpu;
};

struct Observer {
    virtual ~Observer();
    virtual void unused04();
    virtual void unused08();
    virtual void apply(const Context& ctx);
};

struct Settings {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    void* collisionInput;
    int unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    FlagByte skipObservers;
    FlagByte directIntegrate;
    unsigned short unkb2;
    int minIslandSize;
    int unkb8, unkbc, unkc0, unkc4;
    FlagByte wantSparseCheck;
    byte unkc9;
    unsigned short unkca;
    int unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc;
    Context context;
    __forceinline void* getCollisionInput() const { return collisionInput; }
};

struct SecondarySettings {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0;
    unsigned int constraintLimit;
};

struct TaskOwner {
    Settings* settings;
    int unk04, unk08, unk0c;
    ConstraintQueryIn queryIn;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c;
    PaddedPtr<SecondarySettings*> secondary;
};

struct SceneIsland {
    int unk00, unk04, unk08;
    int schemaSize;
    int numSolverResults;
    int numSolverElemTemps;
    Settings* world;
    int numConstraints;
    int unk20;
    byte splitCounter;
    bool sparseEnabled : 2;
    bool isSparse : 2;
    byte flagBits : 4;
    unsigned short unk26;
    int unk28, unk2c, unk30, unk34;
    TaskArrayBase<Observer*> observers;
    int unk44;
    TaskArrayBase<void*> entities;
    __forceinline const TaskArrayBase<void*>& GetEntities() const { return entities; }
    __forceinline Settings* getWorld() { return world; }
};

struct BuildCollection {
    void* buildTasks;
    int numBuildTasks;
    void* callbackConstraints;
    int numCallbackConstraints;
    __forceinline BuildCollection() { buildTasks = 0; numBuildTasks = 0; callbackConstraints = 0; numCallbackConstraints = 0; }
};

struct SolveCollection {
    void* firstSolveTask;
    unsigned short numSolveTasks;
    __forceinline SolveCollection() { firstSolveTask = 0; numSolveTasks = 0; }
};

struct JobHeader {
    __forceinline void* operator new(unsigned int nbytes) { return TaskMemory::GetMonitorStream().heap().allocate(nbytes); }
    unsigned int openJobs;
    unsigned int unfinishedJobs;
    unsigned int shouldDeactivate;
    unsigned int refCount;
    unsigned int exportFinishedCount;
    void* buffer;
    void* impulseLimits;
    int bufferCapacity;
    FlagByte exportFinished;
    byte splitRequested;
    unsigned short unk22;
    void* accumulatorsBase;
    int unk28, unk2c;
    void* schemasBase;
    int unk34, unk38;
    void* solverTempBase;
    void* unk40;
    int numSolverResults;
    int numSolverElemTemps;
    const void* queryIn;
    void* const* allEntities;
    unsigned short numAllEntities;
    unsigned short entitiesCapacity;
    FlagByte unk58;
    FlagByte unk59;
    unsigned short unk5a;
    TaskArray<void*> splitIslands;
    BuildCollection tasks;
    SolveCollection solveTasks;
    __forceinline JobHeader() : refCount(1), exportFinishedCount(1), buffer(0), impulseLimits(0), bufferCapacity(0) {}
};

struct DynamicsPacket : PacketBase {
    unsigned short islandIndex;
    unsigned short unk12;
    SceneIsland* island;
    JobHeader* header;
    void* threadData;
    __forceinline DynamicsPacket(unsigned int subType, unsigned short sz, const DynamicsPacket& src, PacketMode m)
        : PacketBase(PACKET_DYNAMICS, subType, sz, m) {
        islandIndex = src.islandIndex;
        island = src.island;
        header = src.header;
        threadData = src.threadData;
    }
};

struct SplitPacket : DynamicsPacket {
    __forceinline SplitPacket(const DynamicsPacket& src, unsigned short sz, unsigned int subType)
        : DynamicsPacket(subType, sz, src, MODE_DISABLED) {}
};

struct ExportPacket : SplitPacket {
    void* solveTask;
    __forceinline ExportPacket(const DynamicsPacket& src, unsigned short sz, const JobHeader& hdr, unsigned int subType)
        : SplitPacket(src, sz, subType) { solveTask = hdr.solveTasks.firstSolveTask; }
};

struct MotionPacket : ExportPacket {
    void* buffer;
    unsigned short numEntities;
    unsigned short firstEntityIdx;
    int unk38;
    FlagByte applyForces;
    __forceinline void* operator new(unsigned int, void* p) { return p; }
    __forceinline MotionPacket(const DynamicsPacket& src, const JobHeader& hdr)
        : ExportPacket(src, 0x40, hdr, 11) {
        firstEntityIdx = 0;
        numEntities = hdr.numAllEntities;
        buffer = hdr.buffer;
        applyForces = false;
    }
};

struct BroadPacket : DynamicsPacket {
    unsigned short numIslands;
    __forceinline void* operator new(unsigned int, void* p) { return p; }
    __forceinline BroadPacket(const DynamicsPacket& src, JobHeader* hdr)
        : DynamicsPacket(12, 48, src, MODE_DISABLED) {
        header = hdr;
        numIslands = 1;
    }
};

struct FinishPacket : DynamicsPacket {
    int unk20;
    __forceinline FinishPacket(const DynamicsPacket& src, JobHeader* hdr)
        : DynamicsPacket(2, 48, src, MODE_ENABLED) {
        header = hdr;
    }
};

struct AccumulatorsPacket : DynamicsPacket {
    void* const* entitiesArray;
    unsigned short firstEntityIdx;
    unsigned short numEntities;
};

extern int __cdecl hkMemoryRouter_UpdateState_00d889f0(SceneIsland& island);
extern int __cdecl hkRigidMotionUtilApplyForcesAndStep(const SolverParams& solver, const StepTiming& timing, const AccelVec& accel, void* const* entities, int numEntities, int offset);
extern void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(const void* input, void* const* entities, int numEntities);
extern int __cdecl hkpConstraintSolverSetup_solve(const StepTiming& timing, const SolverParams& solver, ConstraintQueryIn& queryIn, SceneIsland& island, void* buffer, int bufferSize, void* const* entities, int numEntities);
extern void __cdecl FUN_00d942f0(SceneIsland* island, TaskArray<void*>& splitIslands);
extern int __cdecl Object_ProcessAndReturnValue_00d883c0(const SceneIsland& island, char* buffer, int bufferSize, JobHeader& header);

// src: HAVOK_LIB 0x00d95130
__declspec(noinline) void __cdecl createBuildJacobianAndSolveJacobianTaskCollection(SceneIsland* island, FlagByte onSpu, JobHeader* header, BuildCollection* builds, SolveCollection* solves)
{
    builds->numBuildTasks = island->numConstraints;
    builds->buildTasks = header->buffer;
    solves->numSolveTasks = onSpu ? 1 : 2;
}

__forceinline int estimateIslandSize(int numEntities, int numConstraints) { return maxVal(numEntities, numConstraints); }
__forceinline bool checkIslandSparse(Settings* world, int size) { return size < int(world->minIslandSize); }

// @fnv 0x00d95cf0
// src: COMMUNITY 0x00d95cf0
int __cdecl integrateJob(TaskOwner& owner, Queue& queue, JobQueueEntry& nextJobOut)
{
    const DynamicsPacket& currentJob = reinterpret_cast<DynamicsPacket&>(nextJobOut);
    SceneIsland* island = currentJob.island;

    int bufferSize;
    int bufferCapacity;
    char* buffer;
    if (island->schemaSize)
    {
        bufferSize = hkMemoryRouter_UpdateState_00d889f0(*island);
        bufferCapacity = bufferSize;
        buffer = solverBufAlloc<char>(bufferCapacity);
        while (!buffer)
        {
            JobQueueEntry retryJob;
            int prevThread = DAT_012687c8.get();
            DAT_012687c8.set(1);
            int status = queue.FUN_00d05190(retryJob, 1);
            DAT_012687c8.set(prevThread);
            if (status == 0)
            {
                queue.hkJobQueue_addJob(nextJobOut, 1);
                JobQueueEntry stopJob;
                stopJob.kind = PACKET_DYNAMICS;
                stopJob.subType = 16;
                queue.hkJobQueue_finishJob(&stopJob, 0);
                nextJobOut = retryJob;
                return 0;
            }
            {
                volatile int spin;
                for (int i = 0; i < 4000; i++)
                {
                    spin = i;
                }
            }
            buffer = solverBufAlloc<char>(bufferCapacity);
        }
    }
    else
    {
        bufferSize = 0;
        bufferCapacity = 0;
        buffer = 0;
    }

    {
        hkMonitorStream& stream = hkMonitorStream::getInstance();
        if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
        {
            hkMonitorStream::TimerBeginListCommand* ev = reinterpret_cast<hkMonitorStream::TimerBeginListCommand*>(stream.getEnd());
            ev->m_commandAndMonitor = DAT_010cc5c4;
            ev->m_nameOfFirstSplit = DAT_010cc5bc;
            ev->setTime();
            stream.setEnd((char*)(ev + 1));
        }
    }

    Context& stepCtx = owner.settings->context;
    if (!owner.settings->skipObservers)
    {
        const TaskArrayBase<Observer*>& observers = island->observers;
        {
            hkMonitorStream& stream = hkMonitorStream::getInstance();
            if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
            {
                hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                ev->m_commandAndMonitor = DAT_010cc5b0;
                ev->setTime();
                stream.setEnd((char*)(ev + 1));
            }
        }
        for (int j = 0; j < observers.GetLogicalSize(); j++)
        {
            Observer* obs = observers[j];
            if (obs)
            {
                obs->apply(stepCtx);
            }
        }
    }

    JobHeader* header = new JobHeader;

    {
        hkMonitorStream& stream = hkMonitorStream::getInstance();
        if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
        {
            hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
            ev->m_commandAndMonitor = DAT_010d3f64;
            ev->setTime();
            stream.setEnd((char*)(ev + 1));
        }
    }

    void* const* entities = island->GetEntities().begin();
    unsigned int numEntities = island->GetEntities().GetLogicalSize();
    header->numAllEntities = (unsigned short)numEntities;
    header->allEntities = entities;
    header->entitiesCapacity = (unsigned short)island->GetEntities().getCapacity();
    header->unfinishedJobs = 0;
    header->shouldDeactivate = 1;
    header->buffer = 0;
    header->impulseLimits = 0;
    header->accumulatorsBase = 0;
    header->tasks.buildTasks = 0;
    header->schemasBase = 0;

    int splitRequested = 0;

    {
        hkMonitorStream& stream = hkMonitorStream::getInstance();
        if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
        {
            hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
            ev->m_commandAndMonitor = DAT_010d3f54;
            ev->setTime();
            stream.setEnd((char*)(ev + 1));
        }
    }

    island->splitCounter++;
    SyncCheck::verify<bool>(0xF0000098, island->isSparse);
    SyncCheck::verify<bool>(0xF0000099, island->sparseEnabled);
    SyncCheck::verify(0xF000009A, island->splitCounter);
    SyncCheck::verify(0xF000009B, owner.settings->wantSparseCheck);
    if (!island->isSparse)
    {
        if (island->sparseEnabled && (island->splitCounter & 7) == 0 && owner.settings->wantSparseCheck)
        {
            splitRequested = 1;
        }
    }
    else
    {
        int islandSize = estimateIslandSize(island->GetEntities().GetLogicalSize(), island->numConstraints);
        FlagByte canBeSparse = checkIslandSparse(owner.settings, islandSize);
        SyncCheck::verify(0xF000009C, islandSize);
        SyncCheck::verify(0xF000009D, canBeSparse);
        if (!canBeSparse)
        {
            island->isSparse = 0;
            if ((island->splitCounter & 3) == 0)
            {
                splitRequested = 1;
            }
        }
        else
        {
            if ((island->splitCounter & 7) == 0)
            {
                splitRequested = 1;
            }
        }
    }

    unsigned int estimatedConstraints;
    if (!island->schemaSize)
    {
        if (owner.settings->directIntegrate)
        {
            header->buffer = 0;
            header->bufferCapacity = 0;
            header->schemasBase = 0;
            header->solverTempBase = 0;
            header->unk40 = 0;
            header->impulseLimits = 0;
            header->numSolverResults = island->numSolverResults;
            header->numSolverElemTemps = island->numSolverElemTemps;
            header->queryIn = &owner.queryIn;
            header->bufferCapacity = bufferCapacity;
            int motionJobs = (numEntities - 1) / 128 + 1;
            header->unfinishedJobs = splitRequested + motionJobs;
            header->splitRequested = (byte)splitRequested;
            header->solveTasks.firstSolveTask = 0;

            MotionPacket& motion = reinterpret_cast<MotionPacket&>(nextJobOut);
            new (&motion) MotionPacket(currentJob, *header);
            motion.header = header;
            motion.applyForces = true;
            motion.mode = MODE_ENABLED;
            header->exportFinished = true;
            header->openJobs = motionJobs;

            {
                hkMonitorStream& stream = hkMonitorStream::getInstance();
                if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
                {
                    hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                    ev->m_commandAndMonitor = DAT_01076f38;
                    ev->setTime();
                    stream.setEnd((char*)(ev + 1));
                }
            }

            QueueStorage tempStorage;
            void* token = queue.hkJobQueue_lockQueue(&tempStorage);
            if (splitRequested)
            {
                SplitPacket splitJob(currentJob, 0x20, 5);
                queue.FUN_00d04b00(token, splitJob, 0);
            }
            queue.hkJobQueue_unlockQueue(token);
            return queue.hkJobQueue_finishAddAndGetNextJob(0, 0, nextJobOut, 0);
        }

        {
            hkMonitorStream& stream = hkMonitorStream::getInstance();
            if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
            {
                hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                ev->m_commandAndMonitor = DAT_010d3f48;
                ev->setTime();
                stream.setEnd((char*)(ev + 1));
            }
        }
        int inactiveFrames = hkRigidMotionUtilApplyForcesAndStep(stepCtx.solver, stepCtx.timing, stepCtx.gravityStep, island->GetEntities().begin(), island->GetEntities().GetLogicalSize(), 0xe0);
        hkpEntityAabbUtil_entityBatchRecalcAabb(island->getWorld()->getCollisionInput(), island->GetEntities().begin(), island->GetEntities().GetLogicalSize());
        if (inactiveFrames <= 5)
        {
            header->shouldDeactivate = 0;
        }
        goto FINISH_BROAD_PHASE;
    }

    estimatedConstraints = maxVal(island->numConstraints, island->GetEntities().GetLogicalSize());
    if (estimatedConstraints < owner.secondary->constraintLimit)
    {
        {
            hkMonitorStream& stream = hkMonitorStream::getInstance();
            if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
            {
                hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                ev->m_commandAndMonitor = DAT_010d3f38;
                ev->setTime();
                stream.setEnd((char*)(ev + 1));
            }
        }
        {
            ConstraintQueryIn localQuery = owner.queryIn;
            int inactiveFrames = hkpConstraintSolverSetup_solve(stepCtx.timing, stepCtx.solver, localQuery, *island, buffer, bufferSize, entities, numEntities);
            if (inactiveFrames <= 5)
            {
                header->shouldDeactivate = 0;
            }
        }
        solverBufFree<char>(buffer, bufferCapacity);

FINISH_BROAD_PHASE:
        SyncCheck::verify(0xF000009E, splitRequested);
        if (splitRequested)
        {
            FUN_00d942f0(island, header->splitIslands);
        }
        {
            hkMonitorStream& stream = hkMonitorStream::getInstance();
            if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
            {
                hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                ev->m_commandAndMonitor = DAT_01076f38;
                ev->setTime();
                stream.setEnd((char*)(ev + 1));
            }
        }
        header->exportFinished = true;
        new (&nextJobOut) BroadPacket(currentJob, header);
        {
            int status = queue.hkJobQueue_finishAddAndGetNextJob(0, 0, nextJobOut, 0);
        }
        return 0;
    }

    {
        {
            hkMonitorStream& stream = hkMonitorStream::getInstance();
            if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
            {
                hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                ev->m_commandAndMonitor = DAT_010d3f2c;
                ev->setTime();
                stream.setEnd((char*)(ev + 1));
            }
        }
        Object_ProcessAndReturnValue_00d883c0(*island, buffer, bufferSize, *header);
        header->numSolverResults = island->numSolverResults;
        header->numSolverElemTemps = island->numSolverElemTemps;
        header->queryIn = &owner.queryIn;
        header->bufferCapacity = bufferCapacity;
        {
            int motionJobs = (numEntities - 1) / 128 + 1;
            header->unfinishedJobs = splitRequested + motionJobs;
            header->splitRequested = (byte)splitRequested;
            header->exportFinished = false;
            header->openJobs = (numEntities - 1) / 128 + 2;

            AccumulatorsPacket& accJob = reinterpret_cast<AccumulatorsPacket&>(nextJobOut);
            accJob.subType = 1;
            accJob.header = header;
            accJob.entitiesArray = entities;
            accJob.firstEntityIdx = 0;
            accJob.numEntities = (unsigned short)numEntities;
            accJob.mode = MODE_ENABLED;
            queue.hkJobQueue_addJob(nextJobOut, 0);
        }

        BuildCollection outBuilds;
        SolveCollection outSolves;
        createBuildJacobianAndSolveJacobianTaskCollection(island, stepCtx.buildOnSpu, header, &outBuilds, &outSolves);
        {
            hkMonitorStream& stream = hkMonitorStream::getInstance();
            if (static_cast<hkMonitorStream_hkpcpuintegratejob&>(stream).memoryAvailable())
            {
                hkMonitorStream::TimerCommand* ev = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream.getEnd());
                ev->m_commandAndMonitor = DAT_01076f38;
                ev->setTime();
                stream.setEnd((char*)(ev + 1));
            }
        }
        header->tasks = outBuilds;
        header->solveTasks = outSolves;

        FinishPacket FinalizePacket(currentJob, header);
        int status = queue.ProcessCallback(&FinalizePacket, nextJobOut, 0);
        return status;
    }
}
}  // namespace fnv_00d95cf0
