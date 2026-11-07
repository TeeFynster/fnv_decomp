#include "../../../../../../include/hkArray.h"
// src/havok/common/base/thread/jobqueue/hkjobqueue_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/thread/jobqueue/hkjobqueue.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/base/thread/jobqueue/hkjobqueue.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/jobqueue/hkjobqueue.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMonitorStream.h"

struct FUNObj
{
    struct Entry
    {
        int first;
        int second;
        int third;
        int fourth;
    };
    Entry entries[15];
    void SetEntry(int index, int first, int second, int third, int fourth);
};
void hkSemaphoreBusyWait_release(void*, int);
struct UnsignedShortCountBlock {
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    unsigned short unk14;
    unsigned short unk16;
    unsigned short unk18;
    unsigned short unk1A;
    unsigned short unk1C;
    unsigned short unk1E;
    unsigned short unk20;
    unsigned short counts[5];
};
struct ItemManager {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74;
    void* values[5];
    int count;
    void ProcessPendingEntries(UnsignedShortCountBlock* refs);
    void RemoveItemReference(int index, UnsignedShortCountBlock* refs);
};
struct Bucket {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void hkQueue_struct_hkJobQueue_JobQueueEntry_setCapacity(int);
};
struct Registry {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14;
    int unk18; int unk1C; int unk20; int unk24; int unk28;
    Bucket buckets[1];
};
__declspec(align(16)) struct RequestContext {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    int unkA0; int unkA4; int unkA8; int unkAC; int unkB0; int unkB4; int unkB8; int unkBC;
    int unkC0; int unkC4; int unkC8; int unkCC; int unkD0; int unkD4; int unkD8; int unkDC;
    int unkE0; int unkE4; int unkE8; int unkEC; int unkF0; int unkF4; int unkF8; int unkFC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164;
};
struct Owner {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int count;
    Registry* hkJobQueue_lockQueue(RequestContext*);
    void hkJobQueue_unlockQueue(Registry*);
    void hkJobQueue_setQueueCapacityForJobType(int, int);
};
struct Item {
    int data[32];
};
struct ItemPool {
    Item* m_items;
    int m_pRayCursor;
    int m_free;
    int m_unk0c;
    int m_uiItemCount;

    void Insert(const Item& item);
    void Insert2(const Item& item);
};
struct PoolSet {
    char m_auiShapeKeys[0x2c];
    ItemPool m_pools[1];
};
struct Mgr {
    int GetIndex(const Item& item);
    void Notify(int idx, PoolSet* set);
    void InsertItemAndNotify(PoolSet* set, const Item& item, int flag);
};
struct Obj {
    int Forward3(int a, int b, int c);
    int ForwardWithZero(int a, int b);
};
struct S_00d056a0_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator* heap() { return m_pStreamAllocator; }
};
S_00d056a0_Router* hkMemoryRouter_getInstance();
struct S_00d056a0_Elem {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};
struct S_00d056a0 {
    S_00d056a0_Elem* m_data;
    int m_iElementCount;
    void UpdateFields_00d056a0();
};
struct D057A0Element {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
struct D057A0Queue {
    D057A0Element* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void SetNodeCount(int n);
    void hkQueue_struct_hkJobQueue_JobQueueEntry_enqueue(const D057A0Element& element);
};
struct CallTarget {
    int FUN_00d04390(int aiValue);
};
int __cdecl hkSemaphoreBusyWait_release(CallTarget* apTarget, int aiValue);
void __cdecl hkSemaphoreBusyWait_release(int value, int flag);
struct FUN_00d04450_cls {
    int unk00;

    void* hkJobQueue_lockQueue(void* out);
    void hkJobQueue_unlockQueue(void* p);
    void SetValue(int a1);
};
// ---------------------------------------------------------------------------
// ReleasePendingCounts - releases the pending semaphore counts of one object.
//
// The object keeps a table of semaphores at offset 0x78 and the number of
// table entries that are in use at offset 0x8c.  The argument is a block of
// per entry counters that starts at offset 0x22.  Every counter is taken
// over, cleared and the semaphore of that entry is released once for every
// count that was pending.
// ---------------------------------------------------------------------------
// The semaphore object; only released through FUN_00d043c0.
struct FnvSemaphore;
// Releases a semaphore count times.
void hkSemaphoreBusyWait_release(FnvSemaphore* pSemaphore, int count);
// The block of pending counters handed to ReleasePendingCounts.
struct FnvReleaseCounts {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short unk20;
    unsigned short pending[8];        // 0x22
};
// The object that owns the semaphores.
struct FnvReleaseSet {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    FnvSemaphore* pSemaphores[5];     // 0x78
    int count;                        // 0x8c

    void ReleasePendingCounts(FnvReleaseCounts* pCounts);
};
struct SpawnedEntry {
    unsigned char m_key1;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char m_key2;
    unsigned char m_uiFilterValue;
    unsigned char unk06;
    unsigned char unk07;
};
class FUN_00d04890_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    int m_30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    int m_48;

    int LookupSpawnedEntry(const unsigned char* p);
};
void __cdecl hkSemaphoreBusyWait_release(int value, int flag);
struct FUN_00d048e0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int m_34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int m_4c;
    int m_50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int m_78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int m_8c;

    void ProcessPendingEntries(char* tbl);
};
struct __declspec(align(16)) D049D0LockInfo {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
};
struct D049D0Simulation {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_enabled;
};
struct D049D0World {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    D049D0Simulation* m_pSimulation;

    void* lock(D049D0LockInfo* info);
    void disable(void* lockHandle);
    void unlock(void* lockHandle);

    void SetSimulationEnabled(int enabled);
};
extern "C" void __cdecl hkString_memCpy(void* dst, const void* src, int nbytes);
struct __declspec(align(16)) D04B90Object {
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
struct D04B90World {
    void addCopy(D04B90Object* copy, void* userData);
    void AddObjectCopy(const D04B90Object* object, void* userData);
};
void __cdecl GetProcessorCount(unsigned int* out);
class FUN_00d05450_cls
{
public:
    unsigned int m_00;
    unsigned char m_04;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    FUN_00d05450_cls* Init();
};
// ---------------------------------------------------------------------------
// InitHookTable
//
// A free cdecl function taking one pointer; it fills a global table of 17
// default handlers, bumps a counter member of the object to at least 2 and
// then registers two handler descriptors (array + count + two callbacks) in
// the object's dispatch table, followed by two more registration helpers.
//
// The unit file of the pack is empty, so every type used here is a stand-in:
// only the member offsets and the calling conventions matter.
// ---------------------------------------------------------------------------
typedef void (__cdecl *HookFn)(void*, void*);
// The 16 byte descriptor that SetEntry stores into the object's table.
struct HookInfo {
    HookFn* m_ppData;     // +0x00  pointer to the handler array
    int     m_uiItemCount;     // +0x04  number of entries in that array
    HookFn  m_f1;        // +0x08  first callback
    HookFn  m_f2;        // +0x0c  second callback
};
// Stand-in for the object the argument points at.  Only +0x60 is touched by
// this function; the table that SetEntry writes into starts at +0xf0.
struct TargetObj {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60;
    void __thiscall QueueOperation(int a, int b, int c);
    void __thiscall SetEntry(int index, HookInfo info);
};
// The global handler array (17 entries) and the callbacks that go into it.
extern HookFn g_hookTable[17];
extern void __cdecl hookDefault_00d01e50(void*, void*);
extern void __cdecl hookA_00d96600(void*, void*);
extern void __cdecl hookB_00d969e0(void*, void*);
extern void __cdecl hookC_00d967a0(void*, void*);
extern void __cdecl hookD_00d968e0(void*, void*);
// Two more registration helpers, both cdecl with one pointer argument.
void __cdecl hkpCollisionQueryJobQueueUtils_registerWithJobQueue(TargetObj* p);
void __cdecl hkpRayCastQueryJobQueueUtils_registerWithJobQueue(TargetObj* p);
void __cdecl InitHookTable(TargetObj* apTarget);
struct D04A20MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};
namespace fnvc_adapt { extern "C" D04A20MemoryRouter& __cdecl hkMemoryRouter_getInstance(); }
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);
struct D04A20Operation {
    void* m_object;
    bool m_flag;
    int m_data;
};
typedef hkArray<D04A20Operation> D04A20OperationArray;
struct D04A20World {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    D04A20OperationArray m_pPendingOperations;

    void processPendingOperations();
    void QueueOperation(void* object, bool flag, int data);
};
extern "C" __declspec(dllimport) unsigned long __stdcall TlsSetValue(unsigned long index, void* value);
extern unsigned long g_dwTlsIndex;
struct D05490Base
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    D05490Base(int spinCount) throw();
};
struct SrcCfg
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
};
struct SubObj
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    SubObj() throw();
    void UpdateState_00d05b50(SrcCfg* p) throw();
};
struct PoolEntry
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    PoolEntry() throw();
    void Init80(int size) throw();
};
struct PoolTable
{
    static void* operator new(unsigned int nbytes) throw()
    {
        return hkMemoryRouter_getInstance()->heap()->blockAlloc(nbytes);
    }

    unsigned short m_counts[12];
    int m_i18;
    int m_i1c;
    unsigned char m_b20;
    unsigned char m_b21;
    unsigned char m_b22;
    unsigned char m_b23;
    int m_i24;
    int m_i28;
    PoolEntry m_entries[16];
    PoolEntry& operator[](int i) { return m_entries[i]; }
    int m_i16c;
};
struct Slot16
{
    int m_i00;
    int m_i04;
    void* m_p08;
    void* m_p0c;
};
struct D05490Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    D05490Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};
void hkDefaultPopJobFunc();
void hkDefaultFinishJobFunc();
void defaultPopDispatchFunc();
void Runtime_UpdateState_00d04570();
struct FUN_00d05490 : D05490Base
{
    void FinishInit() throw();

    PoolTable* volatile m_pTable;
    void* m_pFn1;
    void* m_pFn2;
    int m_uiItemCount;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    SubObj m_sub;
    int m_i70;
    volatile unsigned char m_b74;
    unsigned char m_b75;
    unsigned char m_b76;
    unsigned char m_b77;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9c;
    int m_ia0;
    int m_ia4;
    int m_ia8;
    int m_iac;
    int m_ib0;
    int m_ib4;
    int m_ib8;
    int m_ibc;
    int m_ic0;
    int m_ic4;
    int m_ic8;
    int m_icc;
    int m_id0;
    int m_id4;
    int m_id8;
    int m_idc;
    int m_ie0;
    int m_ie4;
    int m_ie8;
    int m_iec;
    Slot16 m_slots[11];
    D05490Array m_aiIndexedValues;

    FUN_00d05490(SrcCfg* a1) throw();
};
typedef int (__cdecl *DispatchHandler)(void*, void*, void*);
int __cdecl defaultPopDispatchFunc(void* context, void* argument, void* item);
template <typename T>
inline T* hkAllocateChunk(int n)
{
    return static_cast<T*>(hkMemoryRouter_getInstance()->heap()->AllocateMemoryBlock(n * sizeof(T)));
}
template <typename T>
inline void hkDeallocateChunk(T* p, int n)
{
    hkMemoryRouter_getInstance()->heap()->ReleaseBlock(p, n * sizeof(T));
}
struct hkQueue128
{
    S_00d056a0_Elem* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void hkQueue_struct_hkJobQueue_JobQueueEntry_setCapacity(int n);
};
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned long _DAT_0126835c;
extern "C" const char str_010ccd90[];
extern "C" const char str_010c41f8[];
static __forceinline short& Ref212(Registry* r,unsigned char sub){return reinterpret_cast<short*>(r)[sub];}
struct LunaOwner : Owner
{
    int LookupSpawnedEntry(Item* item);
    int hkJobQueue_findJobInternal(int index, Registry* registry, int param_4, int param_3);
    int ProcessCallback(int param_2, int param_3, int param_4);
};
struct LunaTrace
{
    int unk00;
    unsigned int* current;
    int unk08;
    unsigned int* end;
};
struct LunaCallbackItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Item payload;
};
extern unsigned long DAT_0126835c;
extern "C" void __cdecl hkString_memCpy(void* dst, const void* src, int nbytes);
struct TimerEntry {
    const char* m_name;
    unsigned int m_uiCommandId;
    int m_auiShapeKeys;
};
struct ArrayOfJobs {
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct FUN_00d04bd0_cls : Owner {
    int LookupSpawnedEntry(void* p);
    void RemoveItemReference(int index, Registry* set);
    void AddJobBatch(ArrayOfJobs* jobs, int priority);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern unsigned long hkMonitorStreamTls;
struct S_00d05020_Job {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
struct S_00d05020_Queue {
    S_00d05020_Job* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void hkQueue_struct_hkJobQueue_JobQueueEntry_setCapacity(int capacity);

    void increaseCapacity()
    {
        if (m_pRayCursor == 0)
            hkQueue_struct_hkJobQueue_JobQueueEntry_setCapacity(8);
        else
            hkQueue_struct_hkJobQueue_JobQueueEntry_setCapacity(m_pRayCursor * 2);
    }

    void enqueueInFront(const S_00d05020_Job& element)
    {
        if (m_iNodeCount >= m_pRayCursor)
            increaseCapacity();
        if (m_pFirstNode == 0)
            m_pFirstNode = m_pRayCursor;
        --m_pFirstNode;
        m_data[m_pFirstNode] = element;
        m_iNodeCount++;
    }

    void enqueue(const S_00d05020_Job& element)
    {
        if (m_iNodeCount >= m_pRayCursor)
            increaseCapacity();
        if (m_pTail == m_pRayCursor)
            m_pTail = 0;
        m_data[m_pTail++] = element;
        m_iNodeCount++;
    }
};
struct S_00d05020_DynamicData {
    short m_sQueueCounts[8];
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    S_00d05020_Queue m_kQueues[8];
};
struct S_00d05020_JobQueue {
    S_00d05020_DynamicData* hkJobQueue_lockQueue(char* dynamicDataStorage);
    int LookupSpawnedEntry(const S_00d05020_Job& job);
    int hkJobQueue_findJobInternal(int queueIndexOfNewJob, S_00d05020_DynamicData* data, int waitStatus, S_00d05020_Job& jobOut);
    int hkJobQueue_finishAddAndGetNextJob(int originalJobType, int priority, S_00d05020_Job& jobInOut, int waitStatus);
};
extern unsigned long DAT_0126835c;
static const char kTraceFinishJob[] = "TtfinishJob";
static const char kTraceEnd[] = "Et";
struct TraceRecord
{
    const char* m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};
struct TraceBuffer
{
    unsigned long unk00;
    TraceRecord* m_pCur;
    unsigned long unk08;
    TraceRecord* m_pRecordEnd;
};
struct TraceArg
{
    unsigned char unk00;
    unsigned char m_uiEdgeIndex;
    unsigned short unk02;
    unsigned long unk04;
};
struct JobOut
{
    int m_iResultCode;
    int unk04;
    int unk08;
    int unk0C;
};
class Worker
{
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int (__cdecl* m_pfn20)(Worker*, PoolSet*, TraceArg*, int*);

    PoolSet* GetNode(RequestContext* ctx);
    int FindIndex(Item* item);
    void Sync(int index, PoolSet* set);
    void Release(PoolSet* set);

    void hkJobQueue_finishJob(TraceArg* p, int flag);
};
struct __declspec(align(16)) DispatchJob {
    unsigned char m_eSubtype;
    unsigned char m_type;
    unsigned short m_iElementCount;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
__forceinline unsigned int ReadTick(volatile unsigned int* tick)
{
    *tick = (unsigned int)__rdtsc();
    return *tick;
}
struct TimerSamples {
    volatile unsigned int cloth;
    volatile unsigned int pathfinding;
    volatile unsigned int physicsSecondary;
    volatile unsigned int characterProxy;
    volatile unsigned int raycast;
    volatile unsigned int userJob;
    volatile unsigned int behavior;
    volatile unsigned int unknownJob;
    volatile unsigned int collision;
    volatile unsigned int end;
    volatile unsigned int physics;
    volatile unsigned int animation;
};
struct JobFetchView {
    int ForwardWithZero(int job, int flags);
};
struct Dispatcher : FUN_00d05490 {
    int hkJobQueue_processAllJobs();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* section);
struct QueueLockView : Owner
{
    Registry* hkJobQueue_lockQueue(RequestContext* storage);
};
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* section);
struct CriticalSectionOwner {
    void hkJobQueue_unlockQueue(Registry* data);
};

extern int DAT_012687c8;
extern const char str_010ccd70[];
extern const char str_010c41f8[];
__declspec(dllimport) void* __stdcall TlsGetValue(int index);
struct MonEntry { void* name; int tick; int unk08; };
struct MonStream { int unk00; MonEntry* m_cur; int unk08; MonEntry* m_kRayEnd; };
static __forceinline void CaptureMarker(void* marker)
{
    MonStream* s = (MonStream*)TlsGetValue(DAT_0126835c);
    MonEntry* entry=s->m_cur;
    if (entry < s->m_kRayEnd) {
        entry->name = marker;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        entry->tick = ticks;
        s->m_cur=entry+1;
    }
}
struct __declspec(align(16)) ItemBuf { int data[32]; };
struct Bucket20
{
    ItemBuf* m_base;
    int m_pRayCursor;
    int m_pFirstNode;
    int unk0C;
    int m_uiItemCount;
    void hkQueue_struct_hkJobQueue_JobQueueEntry_enqueueInFront(ItemBuf* item);
};
struct Refs
{
    unsigned short w00; unsigned short w02; unsigned short w04; unsigned short w06;
    unsigned short w08; unsigned short w0A; unsigned short w0C; unsigned short w0E;
    unsigned short w10; unsigned short w12; unsigned short w14; unsigned short w16;
    int f18;
    int f1C;
    unsigned short w20;
    unsigned short pending[5];
    Bucket20 buckets[1];
    bool IsClear(int m) const { if (f18 & m) return false; return true; }
};
void __cdecl hkSemaphoreBusyWait_release(int value, int flag);
void __cdecl hkSemaphore_acquire_ForwardCall_00d043b0(int value);
typedef int (__cdecl *ItemFn)(void* self, Refs* refs, ItemBuf* item, int arg);
struct Host
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    ItemFn m_fn1C;
    int unk20;
    int m_count24;
    int unk28; int unk2C;
    int m_bucketBase30;
    int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48;
    int m_lo4C;
    int m_hi50;
    int m_def54;
    int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74;
    int* m_iSlotIds[5];
    int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8;
    int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8;
    int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; int unkE0; int unkE4;
    unsigned short wE8;
    signed char bEA;
    unsigned char bEB;
    void RemoveItemReference(int index, Refs* refs);
    void hkJobQueue_unlockQueue(Refs* refs);
    void ReleasePendingCounts(Refs* refs);
    __forceinline int tryPop(Refs* refs,int a4) {
    int v;
    if (TlsGetValue(DAT_012687c8) == 0)
        v = m_def54;
    else
        v = ((signed char*)TlsGetValue(DAT_012687c8))[(int)this + 0xea];
    signed char* cursor = (signed char*)this + (v * 9 + 0x48) * 2;
    int cur = *cursor;
    while(cur >= 0) {
        Bucket20* bucket = (Bucket20*)((char*)refs + cur*20+0x2c);
        ++cursor;
        if(bucket->m_uiItemCount != 0) {
        ItemBuf item;
        item = bucket->m_base[bucket->m_pFirstNode];
        int head = bucket->m_pFirstNode + 1;
        bucket->m_pFirstNode = head;
        if (head == bucket->m_pRayCursor)
            bucket->m_pFirstNode = 0;
        bucket->m_uiItemCount--;
        int r = m_fn1C(this, refs, &item, a4);
        if (r == 1) {
            bucket->hkQueue_struct_hkJobQueue_JobQueueEntry_enqueueInFront(&item);
            RemoveItemReference(cur, refs);
        }
        ((unsigned short*)refs)[((unsigned char*)&item)[1]]++;
        return cur;
        }
        cur=*cursor;
    }
    return -1;
    }
    int hkJobQueue_findJobInternal(int a1, Refs* refs, int a3, int a4);
};
// @fnv 0x00d05840
// src: HAVOK_LIB 0x00d05840
int Host::hkJobQueue_findJobInternal(int a1, Refs* refs, int a3, int a4)
{
    int ediVal = tryPop(refs,a4);
    if (a1 != -1 && a1 != ediVal) RemoveItemReference(a1,refs);
    if (ediVal >= 0) { hkJobQueue_unlockQueue(refs); return 0; }
    {
        int total = 0;
        for(int i=m_lo4C;i<m_hi50;++i) total += refs->buckets[i].m_uiItemCount;
        if (total != 0)
            goto tail_check;
        int mask = 0;
        for (int k = 0; k < m_count24; k++) {
            mask |= ((((short*)refs)[k] > 0 || refs->buckets[m_bucketBase30 + k].m_uiItemCount != 0) ? 1 : 0) << k;
        }
        bool none = refs->IsClear(mask) != 0;
        bool maskZero = mask == 0;
        if (none) {
            if (TlsGetValue(DAT_012687c8) == 0) {
                if (maskZero)
                    ReleasePendingCounts(refs);
                hkJobQueue_unlockQueue(refs);
                return 2;
            }
            if (refs->pending[bEA] > 0) {
                refs->pending[bEA]--;
                hkSemaphoreBusyWait_release((int)m_iSlotIds[bEA], 1);
            }
        }
        if (maskZero && refs->f1C != 1) {
            ReleasePendingCounts(refs);
            hkJobQueue_unlockQueue(refs);
            return 2;
        }
    }
tail_check:
    if (a3 == 1) {
        hkJobQueue_unlockQueue(refs);
        return 1;
    }
    {
        int idx = ((signed char*)TlsGetValue(DAT_012687c8))[(int)this + 0xea];
        refs->pending[idx]++;
        hkJobQueue_unlockQueue(refs);
        CaptureMarker((void*)str_010ccd70);
        hkSemaphore_acquire_ForwardCall_00d043b0((int)m_iSlotIds[idx]);
        CaptureMarker((void*)str_010c41f8);
        return -1;
    }
}
