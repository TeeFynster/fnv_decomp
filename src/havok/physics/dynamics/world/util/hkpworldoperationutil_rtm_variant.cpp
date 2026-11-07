#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkpCollidableQualityType.h"
#include "../../../../../../include/hkpAction.h"
#include "../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkpWorld.h"
#include "../../../../../../include/hkpSimulationIsland.h"
// src/havok/physics/dynamics/world/util/hkpworldoperationutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/world/util/hkpworldoperationutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/dynamics/world/util/hkpworldoperationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldoperationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00cb7460_class
{
    int __thiscall hkpAgentNnTrack_getSectorSize(int value);
};
void ClearSlotReference(int* thisPtr, int* p);
void hkpWorldConstraintUtil_addConstraint(int first, int second);
void hkpWorldCallbackUtil_fireConstraintAdded(int first, int second);
void hkpWorldOperationUtil_addConstraintToCriticalLockedIsland(int first, int second);
struct FUN_00cb3ca0_object
{
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int refCount94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
    void __thiscall FUN_00c91120();
    void __thiscall UpdateFields_00c91140();
};
void __cdecl hkpWorldConstraintUtil_addConstraint(FUN_00cb3ca0_object* object, int* value);
void __cdecl hkpWorldCallbackUtil_fireConstraintAdded(FUN_00cb3ca0_object* object, int* value);
int* __cdecl hkpWorldOperationUtil_addConstraintImmediately(FUN_00cb3ca0_object* object, int* value, int shouldNotify);
struct S_00cb3da0_Ctx
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
};
void NotifyTargets(S_00cb3da0_Ctx* ctx, void* p);
void DetachRecord(void* p);
void Object_NotifyAndDetachRecord(S_00cb3da0_Ctx* ctx, void* p);
struct CB3DD0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned char unk24;
    unsigned char m_flags;
};
struct CB3DD0Entity
{
    int unk00;
    int unk04;
    CB3DD0Collidable* m_kCollidable;
};
struct CB3DD0World
{
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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk098;
    unsigned char m_bBlockExecutingPendingOperations;
    unsigned char unk09D;
    unsigned char unk09E;
    unsigned char unk09F;
    int unk0A0;
    int m_iPendingOperationQueueCount;
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
    void* m_kListener;

    void ExecutePendingOperations();
    void ExecutePendingOperationQueues();

    void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    void unlockCriticalOperations()
    {
        if (--m_iCriticalOperationsLockCount)
            return;
        if (m_bBlockExecutingPendingOperations)
            return;
        if (m_iPendingOperationCount)
            ExecutePendingOperations();
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
            ExecutePendingOperationQueues();
    }
};
void __cdecl NotifyTargets(CB3DD0World* world, CB3DD0Entity* entity);
void __cdecl DetachRecord(CB3DD0Entity* entity);
void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(CB3DD0World* world, CB3DD0Entity* entity, int fireCallbacks);
struct CleanupList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkpSimulationIsland* finalObject;
    int unk24;
    hkpSimulationIsland** firstObjects;
    int firstCount;
    int unk30;
    hkpSimulationIsland** secondObjects;
    int secondCount;
};
void __cdecl hkpWorldOperationUtil_validateWorld(CleanupList* apCleanupList);
struct Obj;
struct Obj
{
    int pad0[2];
    int m_8;
    char pad1[0xc8 - 0xc];
    bool m_c8;
    char pad2[3];
    hkpSimulationIsland* m_cc;
};
__declspec(nothrow) void __cdecl RemoveListItem(Obj* o, hkpSimulationIsland* a);
void __cdecl hkpWorldOperationUtil_removeEntitySI(Obj* ctx, Obj* o);
struct S_00cb5d00_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct S_00cb5d00_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
struct S_00cb5d00_Router
{
    S_00cb5d00_Stack m_aiEntries;
    S_00cb5d00_Heap* m_pStreamAllocator;
    static S_00cb5d00_Router& hkMemoryRouter_getInstance() throw();
    S_00cb5d00_Stack& stack() throw()
    {
        return m_aiEntries;
    }
    S_00cb5d00_Heap& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00cb5d00_Elem
{
    int unk00;
    int unk04;
};
template <class T> struct S_00cb5d00_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00cb5d00_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~S_00cb5d00_Array() throw()
    {
        _clearAndDeallocate(*S_00cb5d00_Router::hkMemoryRouter_getInstance().m_pStreamAllocator);
    }
    void _clearAndDeallocate(S_00cb5d00_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
template <class T> struct S_00cb5d00_LocalArray : S_00cb5d00_Array<T>
{
    T* m_pStackAllocation;
    __forceinline S_00cb5d00_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)S_00cb5d00_Router::hkMemoryRouter_getInstance().stack().allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~S_00cb5d00_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        S_00cb5d00_Router::hkMemoryRouter_getInstance().stack().deallocateStack(mem);
    }
};
struct S_00cb5d00_Source
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C(void* key, S_00cb5d00_Array<S_00cb5d00_Elem>* out);
    void query(void* key, S_00cb5d00_Array<S_00cb5d00_Elem>* out) throw()
    {
        unk1C(key, out);
    }
};
struct S_00cb5d00_Sink
{
    void DispatchPairs(S_00cb5d00_Elem* data, int n) throw();
};
struct S_00cb5d00_Owner
{
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
    S_00cb5d00_Source* unk58;
    int unk5C;
    int unk60;
    S_00cb5d00_Sink* unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
};
struct S_00cb5d00_Query
{
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
};
void hkpWorldOperationUtil_removePhantomBP(S_00cb5d00_Owner* owner, S_00cb5d00_Query* query);
struct Object
{
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
    int** items;
    int count;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    unsigned char enabled;
};
extern void __cdecl PropagateStateToChildren(Object*, int*);
void __cdecl hkpWorldOperationUtil_splitSimulationIslands(Object* object);
struct Box
{
    char pad[0x14];
    unsigned short a;
    unsigned short b;
    unsigned short c;
};
struct Holder
{
    char pad[0x30];
    Box* box;
};
struct Stats
{
    char pad[8];
    int maxv;
    int sum0;
    int sum1;
    int sum2;
    void AccumulateStats(Holder* h, const int* s);
};
class S_00dd7d00_Bool
{
  public:
    S_00dd7d00_Bool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};
struct S_00dd7d00_Item;
typedef S_00dd7d00_Bool(__cdecl* S_00dd7d00_Less)(S_00dd7d00_Item* a, S_00dd7d00_Item* b);
void hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(S_00dd7d00_Item** apItems, int aiLow, int aiHigh, S_00dd7d00_Less apfnLess);
struct S_00c6aca0_Tls
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00c6aca0_Tls DAT_tls;
struct S_00c6aca0_Ctx
{
    int saved;
    __forceinline S_00c6aca0_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00c6aca0_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};
struct S_00c6aca0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
    __forceinline void ReturnMemory(void* p, int bytes) throw()
    {
        vfn_10(p, bytes);
    }
};
struct S_00c6aca0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00c6aca0_Heap* m10;
    __forceinline S_00c6aca0_Heap& heap()
    {
        return *m10;
    }
};
S_00c6aca0_Router* hkMemoryRouter_getInstance() throw();
struct S_00c6aca0_Item
{
    virtual ~S_00c6aca0_Item();
};
struct S_00c6aca0_Arr4
{
    S_00c6aca0_Item** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00c6aca0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            int n = cap & 0x3fffffff;
            h.ReturnMemory(m_data, n * 4);
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr4() throw()
    {
        _clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
    }
};
struct S_00c6aca0_Arr8
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00c6aca0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 8);
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr8() throw()
    {
        _clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
    }
};
struct S_00c6aca0_Cont
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~S_00c6aca0_Cont();
    void DeleteListNodesAndReleaseOwner();
};
struct S_00c6aca0_Mm
{
    void MemoryManager_Deallocate(int p);
};
extern S_00c6aca0_Mm DAT_011f6238;
extern int DAT_012677a4;
struct S_00c6aca0_Ref
{
    void FUN_00c905b0();
};
struct S_00c6aca0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    virtual ~S_00c6aca0_Base();
    void bhkSerializable_Kill();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    __forceinline void callVfn94()
    {
        vfn_94();
    }
};
struct FUN_00c6aca0 : S_00c6aca0_Base
{
    S_00c6aca0_Ref* unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    S_00c6aca0_Arr4 unk70;
    S_00c6aca0_Arr8 unk7c;
    int unk88;
    int unk8c;
    S_00c6aca0_Cont unk90;
    ~FUN_00c6aca0();
};
struct S_00cb3f90_Bool
{
    bool m_cBooleanValue;
    S_00cb3f90_Bool(bool b) : m_cBooleanValue(b)
    {}
};
struct S_00cb3f90_Inner
{
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    unsigned int unkD4;
};
struct S_00cb3f90_Sub
{
    S_00cb3f90_Inner* m_pInner;
};
struct S_00cb3f90_Obj
{
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
    S_00cb3f90_Sub* m_pSub;
};
S_00cb3f90_Bool worldOperationUtil_less_hkSimulationIslandPtr(S_00cb3f90_Obj* pObjA, S_00cb3f90_Obj* pObjB);
struct ObjB;
struct ObjA
{
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int m_94;
    void hkpWorld_queueOperation(void* p);
};
struct ObjB
{
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int m_cc;
};
struct FUN_00cb5570_arg
{
    unsigned char tag;
    ObjB* owner;
    ObjB* other;
};
void __cdecl hkpWorldOperationUtil_internalMergeTwoIslands(ObjA* a1, int a2, int a3);
void __cdecl hkpWorldOperationUtil_mergeIslands(ObjA* apObjA, ObjB* apOwner, ObjB* apOther);
// Stand-in model for the objects the original touches.
// The polymorphic target: vtable slots 0x10 / 0x1c / 0x20 are used.
struct VObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int n);
    virtual void v14();
    virtual void v18();
    virtual void v1c(void* a, void* b);
    virtual void v20(void* a, int b, void* c, int d);
};
// The object at [owner + 0x64] - its member at 0xcf70f0 pops its own arguments.
struct Coll
{
    void __thiscall add(void* p, int n);
};
// The four-word record that is handed to v1c by address.
struct Slot
{
    void* a;
    int b;
    int c;
    void* d;
};
// The thread local block the accessor at 0xc85750 returns.
struct TlsBlk
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    VObj* f4;
};
// The second argument.
struct Evt
{
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
};
// The first argument.
struct Owner
{
    int unk00;
    int unk04;
    VObj* unk08;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    VObj* unk58;
    int unk5c;
    int unk60;
    Coll* unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
};
// The thread local accessor at 0xc85750.
void* __cdecl tlsSlot_cb5c10();
void __cdecl hkpWorldOperationUtil_removeEntityBP(Owner* pOwner, Evt* pEvent);
struct FUN_00cb7480_node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short m_14;
    unsigned short m_16;
    unsigned short m_18;
};
struct FUN_00cb7480_holder
{
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
    FUN_00cb7480_node* m_30;
};
struct FUN_00cb7480_delta
{
    int unk00;
    int m_04;
    int m_08;
    int m_0c;
};
struct FUN_00cb7480_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    int m_14;

    void hkpConstraintOwner_subConstraintInfo(FUN_00cb7480_holder* a1, FUN_00cb7480_delta* a2);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct S00cb5310_Sub;
struct S00cb5310_Piece;
struct S00cb5310_Owner;
struct S00cb5310_Sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40(void* p);
    virtual void v44(void* p);
};
struct S00cb5310_List
{
    hkpSimulationIsland** m_00;
    int m_04;
    unsigned int m_08;
};
struct S00cb5310_Alloc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct S00cb5310_Piece
{
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    S00cb5310_Sub m_e0;
    int unkE4;
    int unkE8;
    int unkEC;
    int m_f0;
    int unkF4;
    int unkF8;
    int unkFC;
};
struct S00cb5310_Owner
{
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
    hkpSimulationIsland** m_28;
    int m_2c;
    int unk30;
    S00cb5310_List m_34;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    float m_1d0;
};
extern int DAT_01267e30;
void ResizeAudioStream(void* alloc, S00cb5310_List* list, int n);
bool Object_ProcessEntries_00d28560(float* p, S00cb5310_Piece** arr, int n, int size);
void UpdateRotationInterpolation(float f, void* p);
void hkpWorldCallbackUtil_fireIslandDeactivated(S00cb5310_Owner* a1, hkpSimulationIsland* a2);
void __cdecl hkpWorldOperationUtil_internalDeactivateIsland(S00cb5310_Owner* a1, hkpSimulationIsland* a2);
struct Cb5750_Deferred
{
    unsigned char tag;
    struct Cb5750_Param* arg;
};
struct Cb5750_Bv
{
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_auiShapeKeys;
};
struct Cb5750_Nav
{
    int unk00;
    int unk04;
    int unk08;
    Cb5750_Bv m_bv;
};
struct Cb5750_Inner
{
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    int m_bpId;
    Cb5750_Nav m_nav;
};
struct Cb5750_Param
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Cb5750_Inner inner;
};
struct Cb5750_Aabb
{
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};
struct Cb5750_Sub8
{
    int unk00;
    int unk04;
    int unk08;
};
S_00c6aca0_Router* Cb5750_router() throw();
struct Cb5750_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
template <class T> struct Cb5750_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline Cb5750_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~Cb5750_Array() throw()
    {
        S_00c6aca0_Router* router = Cb5750_router();
        S_00c6aca0_Heap& heap = *router->m10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            heap.vfn_10(m_data, (cap & 0x3fffffff) * (int)sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
template <class T> struct Cb5750_LocalArray : Cb5750_Array<T>
{
    T* m_pStackAllocation;
    __forceinline Cb5750_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)((Cb5750_Stack*)Cb5750_router())->allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~Cb5750_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        ((Cb5750_Stack*)Cb5750_router())->deallocateStack(mem);
    }
};
struct Cb5750_Source
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1c() throw();
    virtual void v20() throw();
    virtual void v24() throw();
    virtual void v28() throw();
    virtual void v2c(Cb5750_Nav** key, Cb5750_Aabb* aabb, int count, Cb5750_Array<S_00cb5d00_Elem>* a,
                     Cb5750_Array<S_00cb5d00_Elem>* b) throw();
};
struct Cb5750_Sink
{
    void addSecond(S_00cb5d00_Elem* data, int n) throw();
    void addFirst(S_00cb5d00_Elem* data, int n, void* extra) throw();
};
S_00c6aca0_Router* Cb5750_router() throw();
void __cdecl Cb5750_merge(Cb5750_Array<S_00cb5d00_Elem>* a, Cb5750_Array<S_00cb5d00_Elem>* b) throw();
void __cdecl Cb5750_invalid(void* world, Cb5750_Param** pp, int count) throw();
struct Cb5750_Owner
{
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
    Cb5750_Source* unk58;
    int unk5C;
    int unk60;
    Cb5750_Sink* unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;
    Cb5750_Sub8* unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
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
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;

    void defer(Cb5750_Deferred* d) throw();
    void flush8c() throw();
    void flush90() throw();
    void __cdecl AddCollisionShape(Cb5750_Param* param) throw();
};
struct Owner_cb3d10
{
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;
    unsigned char unkC8;
};
struct List_cb3d10
{
    hkpSimulationIsland** m_data;
    int m_iElementCount;
};
static hkpSimulationIsland* FindItemForThreshold(Owner_cb3d10* owner, List_cb3d10* list, int threshold, hkpSimulationIsland* target);
volatile int g_cb3d10_thr;
Owner_cb3d10* volatile g_cb3d10_owner;
List_cb3d10* volatile g_cb3d10_list;
hkpSimulationIsland* volatile g_cb3d10_target;
hkpSimulationIsland* volatile g_cb3d10_out;
void CallTarget_cb3d10();
struct B10293_Item
{
    unsigned short Field(int off) const
    {
        return *(const unsigned short*)((const char*)this + off);
    }
};
struct B10293_List
{
    B10293_Item** m_data;
    int m_uiItemCount;
};
struct B10293_Ctx
{
    unsigned char Sel(int off) const
    {
        return *((const unsigned char*)this + off);
    }
};
struct B10293_Arr
{
    int* m_aiIndexedValues;
};
struct B10293_Chain
{
    B10293_Arr* m_aiIndexedValues;
};
static inline int Dec(int w, unsigned char s)
{
    if (s == (w >> 14))
        return (w >> 7) & 0x7f;
    return w & 0x7f;
}
static void MarkIndexedValues(int count, B10293_List* list, int** out, B10293_Chain* chain, B10293_Ctx* ctx);
int keep_alive_b10293(int count, B10293_List* list, int** out, B10293_Chain* chain, B10293_Ctx* ctx);
struct Shape
{
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    unsigned short m_numShapeKeys;  // +0xb0
};
struct ShapeList
{
    Shape** m_items;
    int m_uiItemCount;
};
static void estimateSolverSize(int*** indexMap, int** counts, ShapeList* list, int** flags);
int keep_alive_b11420(ShapeList* list, int** flags, int*** indexMap, int** counts);
template <class T> inline void S00cb4c60_copy(T* p, int n, const T& v)
{
    for (int i = 0; i < n; ++i)
        p[i] = v;
}
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> inline int hkArrayNative<T>::getCapacity() const
{
    return capRaw & 0x3fffffff;
}
template <class T> inline void hkArrayNative<T>::reserve(int n)
{
    S_00c6aca0_Heap& a = hkMemoryRouter_getInstance()->heap();
    const int cap = getCapacity();
    if (cap < n)
    {
        int cap2 = 2 * cap;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(&a, this, newSize, sizeof(T));
    }
}
template <class T> inline void hkArrayNative<T>::AddBack(const T& t)
{
    S_00c6aca0_Router* r = hkMemoryRouter_getInstance();
    if (count == getCapacity())
        ResizeAudioStream(&r->heap(), this, sizeof(T));
    S00cb4c60_copy(data + count, 1, t);
    count++;
}
template <class T> inline void hkArrayNative<T>::SetSize(int size)
{
    reserve(size);
    count = size;
}
struct ConstraintRuntimeInfo
{
    hkpConstraintInstance* constraint;
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
};
void __cdecl hkpWorldOperationUtil_internalActivateIsland(hkpWorld*, hkpSimulationIsland*, hkBool);
void __cdecl _hkAgentNnMachine_AppendTrack(void*, void*);
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl ClearSlotReference(hkpWorld*, hkpSimulationIsland*);
static inline int GrowCap(int cap, int need)
{
    int nc = cap * 2;
    if (need >= nc)
        nc = need;
    return nc;
}
void __cdecl hkpWorldOperationUtil_internalMergeTwoIslands(hkpWorld* a1, hkpSimulationIsland* P, hkpSimulationIsland* Q);
struct IslandList
{
    hkpSimulationIsland** items;
    int count;
    int capacity;
};
void __cdecl hkpWorldOperationUtil_splitSimulationIsland(hkpSimulationIsland* data, Object* object, IslandList* list, int value);
void __cdecl AddItemToContainer(Object* object, hkpSimulationIsland* item);
void __cdecl PropagateStateToChildren(Object* object, int* data);
#include <windows.h>
struct Cb4890_Elem
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned short unk0e8;
    unsigned short m_ea;
    unsigned short m_ec;
};
struct Cb4890_ElemArray
{
    Cb4890_Elem** m_data;
    int m_iElementCount;
};
struct Cb4890_IntArray
{
    int* m_data;
    int m_iElementCount;
};
struct Cb4890_CharArray
{
    char* m_data;
    int m_iElementCount;
};
struct Cb4890_Stack
{
    char* m_next;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
template <class T> struct Cb4890_LocalBuffer
{
    T* m_p;
    int m_iElementCount;
    __forceinline Cb4890_LocalBuffer(int n) throw()
    {
        m_p = (T*)((Cb4890_Stack*)hkMemoryRouter_getInstance())->allocateStack(n * (int)sizeof(T));
    }
    __forceinline ~Cb4890_LocalBuffer() throw()
    {
        ((Cb4890_Stack*)hkMemoryRouter_getInstance())->deallocateStack(m_p);
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_p[i];
    }
};
struct Cb4890_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char m_305;
    unsigned char m_306;
};
struct Cb4890_RemapTable
{
    Cb4890_IntArray* m_entries;
    int m_iElementCount;
    void RemapAndAccumulate(Cb4890_LocalBuffer<int>& map, int count, Cb4890_IntArray* src) throw();
};
template <class T> __forceinline T Cb4890_max2(T a, T b)
{
    return a > b ? a : b;
}
__forceinline int RemapOne(Cb4890_LocalBuffer<int>& used, int* mapped, Cb4890_CharArray* out, int i, int count)
{
    if (used[i])
        mapped[i] = 0;
    else
    {
        mapped[i] = count;
        out->m_data[count] = 0;
        count++;
    }
    return count;
}
static void RemapElements(const Cb4890_ElemArray& list, Cb4890_RemapTable* remap, Cb4890_Owner* owner,
                          Cb4890_IntArray* src, Cb4890_CharArray* out);
volatile int g_cb4890[5];
void Cb4890_caller();
struct S00cb5100_WBits
{
    unsigned short lo : 14;
    unsigned short hi : 2;
};
struct S00cb5100_Bits
{
    unsigned char lo : 2;
    unsigned char hi : 6;
};
struct S00cb5100_Ent
{
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    hkpSimulationIsland* owner_cc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char unke8;
    union
    {
        unsigned char be9;
        S00cb5100_Bits bits9;
    };
    union
    {
        unsigned short wea;
        S00cb5100_WBits bea;
    };
    union
    {
        unsigned short wec;
        S00cb5100_WBits bec;
    };
    unsigned short unkee;
    int unkf0;
    void FUN_00c90510();
    void FUN_00c905b0();
    void setFilter(int a0, int a1, int a2)
    {
        if ((unsigned int)(a2 & 3) < (unsigned int)(be9 & 3))
            a0 = (~a0) << 14;
        else
            a0 <<= 14;
        if (a2 < be9)
            a1 = (~a1) << 14;
        else
            a1 <<= 14;
        wea = (unsigned short)((wea & 0x3fff) | a0);
        wec = (unsigned short)((wec & 0x3fff) | a1);
    }
};
void ResizeAudioStream(void* heap, void* arr, int elemSize);
struct S00cb5100_Arr
{
    hkpSimulationIsland** m_data;
    int m_iElementCount;
    int m_cap;
    hkpSimulationIsland* pick(int* n, hkpSimulationIsland** b, int k);
    void AddBack(hkpSimulationIsland* const& e)
    {
        S_00c6aca0_Router* r = hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(r->m10, this, 4);
        hkpSimulationIsland** out = m_data + m_iElementCount;
        for (int k = 0; k < 1; ++k)
            out[k] = e;
        ++m_iElementCount;
    }
};
void hkSweptTransformUtil_setTimeInformation(float a, float b, void* p);
void ProcessBlocks(hkpSimulationIsland* b, float f, float g, int h);
struct S00cb5100_World
{
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
    S00cb5100_Arr arr28;
    hkpSimulationIsland** data34;
    int size38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    float f1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char b305;
    unsigned char b306;
    union
    {
        unsigned char b307;
        S00cb5100_Bits bits307;
    };
};
void ProcessSceneCallbacks(S00cb5100_World* w, hkpSimulationIsland* b);
static __declspec(noinline) hkpSimulationIsland* FindItemForThreshold(S00cb5100_World* w, S00cb5100_Arr* arr, int n,
                                                                 hkpSimulationIsland* b)
{
    if (w->size38 == 0 || arr->m_iElementCount == 0)
        return 0;
    return arr->pick(&n, &b, w->size38);
}
static inline bool S00cb5100_lt(unsigned char a, unsigned char b)
{
    return a < b;
}
void hkpWorldOperationUtil_internalActivateIsland(S00cb5100_World* w, hkpSimulationIsland* b, bool merge);
#include <xmmintrin.h>
extern float DAT_01017d00;
__forceinline int c6a870Equals3(const __m128& a, const __m128& b, float eps = 0.001f)
{
    static __declspec(align(16)) const unsigned int mask[4] = {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff};
    __m128 d = _mm_sub_ps(a, b);
    d = _mm_and_ps(d, _mm_load_ps((const float*)mask));
    __m128 e = _mm_set_ps1(eps);
    return (_mm_movemask_ps(_mm_cmple_ps(d, e)) & 7) == 7;
}
struct C6A870_Child
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044, f048, f04c, f050, f054, f058, f05c;
    int f060, f064, f068, f06c, f070, f074, f078, f07c;
    int f080, f084, f088, f08c, f090, f094, f098, f09c;
    int f0a0, f0a4, f0a8, f0ac, f0b0, f0b4, f0b8, f0bc;
    int f0c0, f0c4, f0c8, f0cc, f0d0, f0d4, f0d8, f0dc;
    int f0e0, f0e4, f0e8, f0ec, f0f0, f0f4, f0f8, f0fc;
    int f100, f104, f108, f10c, f110, f114, f118, f11c;
    int f120, f124, f128, f12c, f130, f134, f138, f13c;
    int f140, f144, f148, f14c, f150, f154, f158, f15c;
    int f160, f164, f168, f16c, f170, f174, f178, f17c;
    int f180, f184, f188, f18c, f190, f194, f198, f19c;
    int f1a0, f1a4, f1a8, f1ac;
    __m128 m_vLinearConstraint;
    __m128 m_vAngularConstraint;
};
struct C6A870_Item
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024, f028, f02c, f030, f034, f038, f03c;
    int f040, f044;
    C6A870_Child** m_children;
    int m_uiItemCount;
};
struct C6A870_Heap;
typedef void*(__thiscall* C6A870_AllocFn)(C6A870_Heap*, int&);
typedef void(__thiscall* C6A870_FreeFn)(C6A870_Heap*, void*, int);
struct C6A870_HeapTable
{
    void* v00;
    void* v04;
    void* v08;
    C6A870_AllocFn alloc;
    C6A870_FreeFn free;
};
struct C6A870_Heap
{
    C6A870_HeapTable* table;
    __forceinline void* AllocateBufferWithSize(int& numBytes)
    {
        return table->alloc(this, numBytes);
    }
    __forceinline void ReturnMemory(void* p, int n) throw()
    {
        table->free(this, p, n);
    }
    template <typename T> __forceinline T* _bufAlloc(int& n, int& numBytes)
    {
        C6A870_AllocFn alloc = table->alloc;
        numBytes = n * int(sizeof(T));
        void* p = alloc(this, numBytes);
        n = numBytes / int(sizeof(T));
        return (T*)p;
    }
};
__forceinline C6A870_Heap& c6a870Heap()
{
    return *(C6A870_Heap*)&hkMemoryRouter_getInstance()->heap();
}
template <typename T> __forceinline void c6a870Copy(T* dst, const T* src, int n)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}
template <typename T> struct C6A870_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline C6A870_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~C6A870_Array() throw()
    {
        _clearAndDeallocate(c6a870Heap());
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(C6A870_Heap& h) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void _copyFromArray(C6A870_Heap& h, const C6A870_Array& a, int& scratch)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                h.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int n = a.GetLogicalSize();
            m_data = h._bufAlloc<T>(n, scratch);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        c6a870Copy(m_data, a.m_data, m_iElementCount);
    }
    __forceinline C6A870_Array& assign(const C6A870_Array& a, int& scratch)
    {
        _copyFromArray(c6a870Heap(), a, scratch);
        return *this;
    }
};
struct C6A870_World
{
    int f000, f004, f008, f00c, f010, f014, f018, f01c;
    int f020, f024;
    C6A870_Array<C6A870_Item*> m_items;
};
void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(C6A870_World* world);
void __cdecl AddItemToContainer(C6A870_World* world, C6A870_Item* item);
struct C6A870_Self;
typedef C6A870_World*(__thiscall* C6A870_Query)(C6A870_Self*);
struct C6A870_QueryTable
{
    void* f00;
    void* f04;
    void* f08;
    void* f0c;
    void* f10;
    void* f14;
    void* f18;
    void* f1c;
    void* f20;
    void* f24;
    void* f28;
    void* f2c;
    void* f30;
    void* f34;
    void* f38;
    void* f3c;
    void* f40;
    void* f44;
    void* f48;
    void* f4c;
    void* f50;
    void* f54;
    void* f58;
    void* f5c;
    void* f60;
    void* f64;
    void* f68;
    void* f6c;
    void* f70;
    void* f74;
    void* f78;
    void* f7c;
    void* f80;
    void* f84;
    void* f88;
    void* f8c;
    void* f90;
    C6A870_Query query;
};
struct C6A870_View
{
    C6A870_QueryTable* table;
};
struct C6A870_Self
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual C6A870_World* getWorld();

    void bhkWorld_DeactivateAllIslands();
};
struct Motion4120
{
    virtual void unused();
    unsigned short storageSize, refCount;
    unsigned char kind, counter;
    unsigned short inactive[2];
    __forceinline int frames(int slot, int flag)
    {
        int packed = inactive[slot];
        int mode = packed >> 14;
        int n;
        if (flag != mode)
        {
            n = packed & 127;
        }
        else
        {
            n = (packed >> 7) & 127;
        }
        return n & 127;
    }
};
struct Selector
{
    unsigned char first;
    unsigned char second;
};
struct Entry4120
{

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
    int unk34;
    int unk38;
    int unk3c;

    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;

    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;

    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;

    int unka0;
    int unka4;
    int unka8;
    int unkac;

    unsigned short countB0;
    unsigned short unkb2;
    unsigned short unkb4;
    unsigned short unkb6;

    unsigned short unkb8;
    unsigned short unkba;
    unsigned short unkbc;
    unsigned short unkbe;

    unsigned short unkc0;
    unsigned short unkc2;
    unsigned short unkc4;
    unsigned short unkc6;

    unsigned short unkc8;
    unsigned short unkca;
    unsigned short unkcc;
    unsigned short unkce;

    unsigned short unkd0;
    unsigned short unkd2;
    unsigned short unkd4;
    unsigned short unkd6;

    unsigned short unkd8;
    unsigned short unkda;
    unsigned short unkdc;
    unsigned short unkde;

    Motion4120 motion;
    __forceinline Motion4120* movement()
    {
        return &motion;
    }
};
template <class T> struct View4120
{
    T* data;
    int count;
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline int size() const
    {
        return count;
    }
};
struct Groups4120
{
    View4120<int>& groups;
    int n;
};
template <class T> __forceinline T greater4120(T a, T b)
{
    return a > b ? a : b;
}
static void UpdateGroupActivity(const Groups4120& map, const View4120<Entry4120*>& entries, int unusedGroups,
                                View4120<int>& active, View4120<int>& sizes, unsigned char* flags);
extern const Groups4120* volatile inputMap4120;
extern const View4120<Entry4120*>* volatile inputEntities4120;
extern View4120<int>* volatile outputActive4120;
extern View4120<int>* volatile outputSizes4120;
extern unsigned char* volatile inputFlags4120;
extern int volatile groupCount4120;
void caller4120();
struct Inner;
struct CallA
{
    signed char delta;
    void UpdateCollisionIndices();
    void CopyAndSortGeometryList(void* p);
};
struct Mgr2
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    unsigned char unk24;
    bool splitRequested : 2;
    bool sparseEnabled : 2;
    bool cleanup : 2;
    bool inActive : 2;
    unsigned char unk26, unk27;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int m_4c;
    int unk050;
    int unk054;
    int m_58;
    __forceinline void mark()
    {
        splitRequested = true;
    }
    __forceinline int count() const
    {
        return m_4c;
    }
};
struct MotionObj
{
    void* vt;
    int unk04;
    Inner* m_08;
    int unk0c;
    CallA collidable;
    unsigned char unk11, unk12, unk13;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    Mgr2* m_cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned char m_e8, unke9, unkea, unkeb;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int m_1f8;
};
struct Inner
{
    int unk00, unk04;
    MotionObj* m_08;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int m_8c, m_90, m_94, unk98;
    unsigned char m_9c, m_9d, unk9e, unk9f;
    int m_a0, m_a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    float m_1d0;
};
typedef void(__thiscall* FnFree)(void* self, void* p, int bytes);
typedef void(__thiscall* Fn20)(void* self, void* p, int a, void* b, int c);
struct RemRef
{
    void FUN_00c905b0();
};
struct CallB
{
    void UpdateNodeSlotIndices();
    void FUN_00c90510();
};
struct CallInner
{
    void hkpWorld_updateCollisionFilterOnEntity(void* p, void* q, int a);
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
void hkpSimulation_collideEntitiesBroadPhaseDiscrete(void* p, int a, void* b);
void hkpWorldOperationUtil_removeAttachedConstraints(MotionObj* a0, void* b);
void CollectActorEntries(Inner* s, MotionObj* a0, void* a);
void CollectProducers(Inner* s, MotionObj* a0, void* a);
void hkpWorldOperationUtil_removeEntitySI(Inner* s, MotionObj* a0);
void hkpWorldOperationUtil_addConstraintImmediately(Inner* s, void* e, int z);
struct ModeBool
{
    bool value;
    ModeBool()
    {}
    ModeBool(bool b) : value(b)
    {}
    ModeBool(const ModeBool& b) : value(b.test())
    {}
    void set(bool b)
    {
        static_cast<volatile bool&>(value) = b;
    }
    bool test() const
    {
        return value;
    }
    operator bool() const
    {
        return test();
    }
};
void hkpWorldOperationUtil_replaceMotionObject(MotionObj* a0, int mode, ModeBool fMode, ModeBool fCur, Inner* s);
void hkpWorldOperationUtil_addEntitySI(Inner* s, int a5, int a7);
void ApplyConstraintsToEntity(Inner* s, int a8, void* p);
void hkpWorldOperationUtil_removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(void* m, MotionObj* a3, void* w, int mode);
void _hkAgentNnMachine_AppendTrack(void* m, void* w);
void hkpWorldOperationUtil_mergeIslands(Inner* in, MotionObj* a0, MotionObj* e);
void UpdateRotationInterpolation(float f, void* p);
void NotifyEntityRemoved(void* p, MotionObj* a3);
struct VecB
{
    void* data;
    int size;
    int cap;
    void* buf[16];
};
struct VecA
{
    void* data;
    int size;
    int cap;
    void* buf[16];
};
struct Work
{
    int f0;
    void* data;
    int size;
    int cap;
    int buf0;
};
struct Elem8
{
    int f0;
    MotionObj* f4;
};
struct VecC
{
    Elem8* data;
    int size;
    int cap;
    VecC() : data(0), size(0), cap((int)0x80000000)
    {}
};
struct HeadC
{
    short unk10;
    ModeBool fCur;
    ModeBool fMode;
};
static __forceinline void FreeVec(void** dataP, int* sizeP, int* capP, int elem)
{
    S_00c6aca0_Router* m = hkMemoryRouter_getInstance();
    void* fo = m->m10;
    int cap = *capP;
    *sizeP = 0;
    if ((cap & (int)0x80000000) == 0)
    {
        FnFree fn = (FnFree)(*(void***)fo)[4];
        fn(fo, *dataP, (cap & 0x3fffffff) * elem);
    }
    *dataP = 0;
    *capP = (int)0x80000000;
}
void hkpWorldOperationUtil_setRigidBodyMotionType(MotionObj* a0, int mode, int a2, MotionObj* a3, int a4, int a5, int a6, int a7, int a8);
struct S00cb4230_Vec4
{
    float& operator()(int a)
    {
        return reinterpret_cast<float*>(m_vComponents)[a];
    }
    const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(m_vComponents)[a];
    }
    __declspec(align(16)) float m_vComponents[4];
};
struct S00cb4230_Quat
{
    S00cb4230_Quat()
    {}
    S00cb4230_Vec4 m_vec;
};
#include "../../../../../../include/hkMatrix3.h"

struct S00cb4230_Rotation : hkMatrix3
{
    S00cb4230_Rotation()
    {}
};
struct S00cb4230_Transform
{
    S00cb4230_Transform()
    {}
    S00cb4230_Rotation m_rotation;
    S00cb4230_Vec4 m_vTranslation;
    const S00cb4230_Vec4& getTranslation() const
    {
        return m_vTranslation;
    }
};
#include "../../../../../../include/hkSweptTransform.h"

extern float DAT_010c7948[];
struct S00cb4230_UFloat8
{
    S00cb4230_UFloat8()
    {}
    operator float() const
    {
        return DAT_010c7948[m_uiFilterValue];
    }
    unsigned char m_uiFilterValue;
};
struct S00cb4230_MotionStateData
{
    S00cb4230_MotionStateData()
    {}
    S00cb4230_Transform& getTransform()
    {
        return m_kMotionTransform;
    }
    const S00cb4230_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
    hkSweptTransform& getSweptTransform()
    {
        return m_kSweptTransform;
    }
    const hkSweptTransform& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
    void hkMotionState_Copy(void* p);
    S00cb4230_Transform m_kMotionTransform;
    hkSweptTransform m_kSweptTransform;
    S00cb4230_Vec4 m_kDeltaAngle;
    float m_fObjectRadius;
    float m_fLinearDamping;
    float m_fAngularDamping;
    S00cb4230_UFloat8 m_fSurfaceFriction;
    S00cb4230_UFloat8 m_fRestitution;
    short m_uiDeactivationClass;
};
struct MotionFlag31
{
    inline MotionFlag31()
    {}
    inline MotionFlag31(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline MotionFlag31 operator==(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) == static_cast<int>(e);
    }
    inline MotionFlag31 operator!=(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) != static_cast<int>(e);
    }

  private:
    char m_cBooleanValue;
};
template <typename E, typename S> struct S00cb4230_Enum
{
    S00cb4230_Enum()
    {}
    S00cb4230_Enum(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
    operator E() const
    {
        return static_cast<E>(m_kStorage);
    }
    S m_kStorage;
};
struct AllocObj
{
    virtual void v00();
    virtual void* v01(int size);
};
struct MotionState;
struct S00cb4230_FinishFlag
{
    S00cb4230_FinishFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
struct S00cb4230_Half
{
    S00cb4230_Half()
    {}
    void operator=(const float& f)
    {
        int t = ((const int*)&f)[0];
        m_uiFilterValue = short(t >> 16);
    }
    short m_uiFilterValue;
};
struct S00cb4230_BaseObject
{
    S00cb4230_BaseObject()
    {}
    virtual void v00();
};
struct RefHeader31 : S00cb4230_BaseObject
{
    RefHeader31(S00cb4230_FinishFlag flag)
    {}
    unsigned short m_04;
    mutable short m_06;
};
struct MotionBase : RefHeader31
{
    MotionBase(S00cb4230_FinishFlag flag) : RefHeader31(flag)
    {
        if (flag.m_bFinishing)
        {
            m_fGravityFactor = 1.f;
        }
    }
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void GetInverseScaleMatrix(hkMatrix3& out) const;
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(MotionState* p);
    virtual void v26();
    virtual void v27(MotionState* p);
    hkpMotion::MotionType getType() const
    {
        return m_type;
    }
    S00cb4230_MotionStateData* GetMotionState()
    {
        return &m_kMotionState;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return m_kMotionState.getTransform().getTranslation();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return reinterpret_cast<const S00cb4230_Quat&>(m_kMotionState.getSweptTransform().m_qRotation1);
    }
    const S00cb4230_Vec4& getCenterOfMassLocal() const
    {
        return reinterpret_cast<const S00cb4230_Vec4&>(m_kMotionState.getSweptTransform().m_vCenterOfMassLocal);
    }
    float getLinearDamping()
    {
        return m_kMotionState.m_fLinearDamping;
    }
    float getAngularDamping()
    {
        return m_kMotionState.m_fAngularDamping;
    }
    void setLinearDamping(float d)
    {
        m_kMotionState.m_fLinearDamping = d;
    }
    void setAngularDamping(float d)
    {
        m_kMotionState.m_fAngularDamping = d;
    }
    S00cb4230_Enum<hkpMotion::MotionType, unsigned char> m_type;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_MotionStateData m_kMotionState;
    S00cb4230_Vec4 m_kInertiaAndMassInv;
    S00cb4230_Vec4 m_kTranslationalVelocity;
    S00cb4230_Vec4 m_kAngularVelocity;
    S00cb4230_Vec4 m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    MotionState* m_118;
    short m_11c;
    S00cb4230_Half m_fGravityFactor;
    void FUN_00c905b0();
    void FUN_00d1dff0();
    void SetFlagBits(int a, int b, int c);
    void getMotionStateAndVelocitiesAndDeactivationType(MotionBase* p);
    float FUN_00c86430();
    __forceinline static void* operator new(unsigned int nbytes)
    {
        S_00c6aca0_Heap& h = hkMemoryRouter_getInstance()->heap();
        RefHeader31* b = static_cast<RefHeader31*>(((AllocObj*)&h)->v01(static_cast<int>(nbytes)));
        b->m_04 = static_cast<unsigned short>(nbytes);
        return b;
    }
    __forceinline static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct S00cb4230_Keyframed : MotionBase
{
    S00cb4230_Keyframed() : MotionBase(S00cb4230_FinishFlag())
    {
        m_118 = 0;
    }
    S00cb4230_Keyframed(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct MotionState : S00cb4230_Keyframed
{
    MotionState() : S00cb4230_Keyframed()
    {}
};
struct BoxMotion : MotionBase
{
    BoxMotion(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct S00cb4230_String
{
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const unsigned int* src32 = reinterpret_cast<const unsigned int*>(src);
        unsigned int* dst32 = reinterpret_cast<unsigned int*>(dst);
        {
            do
            {
                dst32[0] = src32[0];
                dst32[1] = src32[1];
                dst32[2] = src32[2];
                dst32[3] = src32[3];
                dst32 += 4;
                src32 += 4;
            } while (--numQuads > 0);
        }
    }
};
struct S00cb4230_Handle
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    char m_ucObjectQualityType;
    char m_auiShapeKeys;
    int m_iFilter;
};
struct S00cb4230_Collidable
{
    const void* getShape() const
    {
        return m_pCollisionShape;
    }
    S00cb4230_Handle* getBroadPhaseHandle()
    {
        return &m_kBroadPhaseHandle;
    }
    hkpCollidableQualityType getQualityType() const
    {
        return hkpCollidableQualityType(m_kBroadPhaseHandle.m_ucObjectQualityType);
    }
    void setMotionState(const S00cb4230_MotionStateData* s)
    {
        m_pMotionState = s;
    }
    const void* m_pCollisionShape;
    int m_14;
    const void* m_pMotionState;
    int m_1c;
    int m_20;
    S00cb4230_Handle m_kBroadPhaseHandle;
};
struct ThisObj
{
    int m_00;
    int m_04;
    unsigned char m_08;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_Collidable m_kCollidable;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    float m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    unsigned char m_bc;
    unsigned char m_bd;
    short m_be;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    MotionState m_pMotionState;
    int m_200;
    int m_204;
    MotionBase* getMotion()
    {
        return &m_pMotionState;
    }
    MotionBase* getRigidMotion() const
    {
        return const_cast<MotionBase*>(static_cast<const MotionBase*>(&m_pMotionState));
    }
    const S00cb4230_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    S00cb4230_Collidable* getCollidableRw()
    {
        return &m_kCollidable;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return getRigidMotion()->getPosition();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return getRigidMotion()->getRotation();
    }
    hkpCollidableQualityType getQualityType() const
    {
        return hkpCollidableQualityType(getCollidable()->getQualityType());
    }
    void setQualityType(hkpCollidableQualityType type)
    {
        getCollidableRw()->getBroadPhaseHandle()->m_ucObjectQualityType = char(type);
    }
    void UpdateBoundingVolume(void* a, const void* b);
};
struct Node4
{
    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    char m_304;
    char m_305;
    char m_306;
    char m_307;
    float hkpWorld_getCurrentTime();
};
void __cdecl hkString_memSet(void* p, int a, int b);
template <typename T> __forceinline T* __cdecl S00cb4230_AddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}
void __cdecl hkpRigidBody_createDynamicRigidMotion(int mode, const S00cb4230_Vec4* p40, const S00cb4230_Quat* p80, float fret,
                          const hkMatrix3* out, const S00cb4230_Vec4* p90, float f0, float f1, MotionBase* motion);
void __cdecl UpdateRotationInterpolation(float f, S00cb4230_MotionStateData* p);
void __cdecl hkpWorldOperationUtil_replaceMotionObject(ThisObj* self, hkpMotion::MotionType mode, MotionFlag31 flagA, MotionFlag31 flagB,
                          Node4* node);
struct MergeWorld
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    unsigned char state0;
    bool enabled;
    unsigned char state2;
    unsigned char state3;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    unsigned char unk304;
    unsigned char m_305;
    unsigned char m_306;
};
union MergeListArg
{
    Cb4890_ElemArray* value;
};
static __forceinline void tallyActive(Cb4890_RemapTable* remap_, Cb4890_ElemArray*& list, int n,
                                      Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt, MergeWorld* owner,
                                      Cb4890_ElemArray* const volatile& home) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++, list = home)
    {
        Cb4890_Elem* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        int a = Dec(e->m_ec, owner->m_306);
        int b = Dec(e->m_ea, owner->m_305);
        int am = a & 0x7f;
        int bm = b & 0x7f;
        int mx = (bm > am) ? bm : am;
        if (mx <= 5)
            map[idx] = 1;
        int w = (int)*(unsigned short*)&e->unk0b0;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}
static __forceinline void tallyAll(Cb4890_RemapTable* remap_, Cb4890_ElemArray* list, int n,
                                   Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++)
    {
        Cb4890_Elem* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        map[idx] = 1;
        int w = (int)*(unsigned short*)&e->unk0b0;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}
void mergeSmallSubgroups(MergeWorld* owner, int remap_, MergeListArg listArg, Cb4890_IntArray* src, Cb4890_CharArray* out);
struct S00cb3ee0_Entry
{
    int item;
    char* obj;
};
struct S00cb3ee0_Holder
{
    S00cb3ee0_Entry* entries;
    int count;
};
struct S00cb3ee0_Sub
{
    S00cb3ee0_Holder* hkpLinkedCollidable_getCollisionEntriesDeterministicUnchecked_00d081e0();
};
int PickIslandByValue(int a, int b, int c);
void CloneRecord(int a, int b);
void _hkAgentNnMachine_InternalDeallocateEntry(int a, int b);
void hkpWorldOperationUtil_removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(void* m, MotionObj* motion, void* w, int mode);
template <typename T>

struct S55Array
{

    T* m_data;

    int m_iElementCount;

    int m_iCapacityState;

    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }

    __forceinline void popBack()
    {
        m_iElementCount--;
    }

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(S_00c6aca0_Heap& a, int n);

    __forceinline void _setSize(S_00c6aca0_Heap& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }
};
void __cdecl hkArrayUtil__reserve(S_00c6aca0_Heap& a, void* array, int reqCapacity, int sizeElem);
template <typename T>

__forceinline void S55Array<T>::GrowArrayCapacity(S_00c6aca0_Heap& a, int n)

{

    const int capacity = getCapacity();

    if (capacity < n)
    {

        int cap2 = 2 * capacity;

        int newSize = (n < cap2) ? cap2 : n;

        hkArrayUtil__reserve(a, this, newSize, sizeof(T));
    }
}
struct S55Bool
{

    char m_cBooleanValue;

    S55Bool(bool b) : m_cBooleanValue(b)
    {}
};
struct S55Owner
{

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

    S55Array<hkpSimulationIsland*> m_28;

    int unk34;

    int unk38;

    int unk3c;

    S55Array<hkpSimulationIsland*> m_40;

    int unk4c;

    int unk50;

    int unk54;

    int unk58;

    int unk5c;

    int unk60;

    int unk64;

    int unk68;

    int unk6c;

    int unk70;

    int unk74;

    int unk78;

    int unk7c;

    int unk80;

    int unk84;

    int unk88;

    int unk8c;

    int unk90;

    int unk94;

    int unk98;

    int unk9c;

    int unka0;

    int unka4;

    int unka8;

    int unkac;

    int unkb0;

    int m_b4;

    int unkb8;

    int unkbc;

    int unkc0;

    int unkc4;

    unsigned char m_c8;

    void __thiscall nullsub_6();
};
void __cdecl hkpWorldOperationUtil_internalActivateIsland(S55Owner* owner, hkpSimulationIsland* item, S55Bool b);
void __cdecl hkpWorldOperationUtil_internalDeactivateIsland(S55Owner* owner, hkpSimulationIsland* item);
extern "C" void __cdecl hkpWorldOperationUtil_mergeIslands(S55Owner* owner, ObjB* first, ObjB* second);
void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(S55Owner* owner);

struct SplitIsland_Target;
struct SplitIsland_Target;
struct SplitIsland_Node2;
extern "C" void _ReadWriteBarrier(void);
// Partition physics island nodes into groups, relink owners, and redistribute stream records.
struct SplitIsland_CursorObj
{
    int cur;
    int unk04;
    int unk08;
    int unk0c;
    struct SplitIsland_Alloc* alloc;
};
struct SplitIsland_Alloc
{
    virtual void V00();
    virtual void V04();
    virtual void V08(void* p, int n);
    virtual void V0c();
    virtual void FreeLike(void* p, int size);
};
__forceinline int* SplitIsland_cursor()
{
    return &hkMemoryRouter_getInstance()->unk00;
}
void hkString_memSet(void* p, int a, int b);
void hkArrayUtil__reserve(void* alloc, void* vec, int cap, int elemsz);
void ResizeAudioStream(void* alloc, void* vec, int elemsz);
void hkArrayUtil__reduce(void* alloc, void* vec, int elemsz, void* p, int n);
struct SplitIsland_AllocB
{
    virtual void V00();
    virtual void* AllocSz(int sz);
};
template <class T> __forceinline void SplitIsland_copyItems(T* destination, int n, const T& value)
{
    for (int i = 0; i < n; ++i)
    {
        __assume(destination + i != 0);
        new (destination + i) T(value);
    }
}
struct SplitIsland_Vec48
{
    __forceinline void SplitIsland_appendNodeUnchecked(SplitIsland_Node2* const&);
    int* data;
    int cnt;
    int cap;
    void SwapThreeInts(int arg);
    __forceinline void SplitIsland_reserve(int n)
    {
        SplitIsland_CursorObj* router = (SplitIsland_CursorObj*)SplitIsland_cursor();
        if ((cap & 0x3fffffff) < n)
            hkArrayUtil__reserve(router->alloc, this, n, 4);
    }
    __forceinline void SplitIsland_append(int value)
    {
        SplitIsland_CursorObj* router = (SplitIsland_CursorObj*)SplitIsland_cursor();
        if (cnt == (cap & 0x3fffffff))
            ResizeAudioStream(router->alloc, this, 4);
        int* destination = data + cnt;
        __assume(destination != 0);
        new (destination) int(value);
        ++cnt;
    }
    __forceinline void SplitIsland_appendUnchecked(const int& value)
    {
        SplitIsland_copyItems(data + cnt, 1, value);
        ++cnt;
    }
    __forceinline void SplitIsland_compact()
    {
        int capacity = cap;
        if ((capacity & 0x80000000) == 0)
        {
            unsigned int v = cnt + 3;
            v |= v >> 16;
            v |= v >> 8;
            v |= v >> 4;
            v |= v >> 2;
            int wanted = (v | (v >> 1)) + 1;
            if (wanted < 1)
            {
                hkArrayUtil__reduce(((SplitIsland_CursorObj*)SplitIsland_cursor())->alloc, this, 4, this + 1, 1);
            }
            else if (wanted < (capacity & 0x3fffffff))
            {
                hkArrayUtil__reduce(((SplitIsland_CursorObj*)SplitIsland_cursor())->alloc, this, 4, 0, wanted);
            }
        }
    }
};
struct SplitIsland_Arg2Vec
{
    int* data;
    int cnt;
    int cap;
};
struct SplitIsland_Obj38
{
    int** f00;
    int unk04;
    void FUN_00d27f70(int* p, int n);
    void RemapIndices(struct SplitIsland_L60* p);
    int MoveLargestToFirst(struct SplitIsland_L60* p);
    void RemapAndAccumulate(int* q, int n, struct SplitIsland_L60* p);
};
struct SplitIsland_L60
{
    int* f00;
    int f04;
    int f08;
    int data[32];
};
struct SplitIsland_H44;
// Byte views preserve the original independent island flag bitfields.
struct SplitIsland_Flags25
{
    unsigned char stateLow : 2;
    unsigned char groupState : 2;
    unsigned char stateHigh : 4;
};
struct SplitIsland_Flags26
{
    unsigned char type26 : 2;
    unsigned char active26 : 1;
    unsigned char pending26 : 1;
    unsigned char high26 : 4;
};
struct SplitIsland_H44
{
    int f00;
    int f04;
    int f06;
    int f08;
};
struct SplitIsland_Target;
struct SplitIsland_Sub30
{
    inline void SplitIsland_readTransfer(SplitIsland_H44&) const;
    inline void SplitIsland_debitTransfer(const SplitIsland_H44&);
    SplitIsland_Target* f00;
    int field04;
    int field08;
    int field0C;
    int field10;
    unsigned short f14;
    unsigned short f16;
    unsigned short f18;
    short unk1a;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct SplitIsland_Target
{
    inline void SplitIsland_assignOwner(hkpSimulationIsland*);
    int unk00;
    int unk04;
    hkpSimulationIsland* SplitIsland_owner;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SplitIsland_Sub30* f30;
};
struct SplitIsland_Node2
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    short fA8;
    short unkAA;
    int fAC;
    short fB0;
    unsigned short fieldB2;
    int fieldB4;
    int fieldB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    int fCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    short unkE8;
    unsigned short fEA;
    unsigned short fEC;
};
struct SplitIsland_TempEC
{
    int* f00;
    int f04;
    int f08;
    int data[16];
};
struct SplitIsland_Elem2
{
    virtual void V00();
    virtual void V04();
    virtual void V08(void* p, int n);
    virtual void V0c();
    virtual void GetList(SplitIsland_TempEC* t);
    int unk04;
    int unk08;
    int f0c;
};
void CloneRecord(int* p, void* q);
void _hkAgentNnMachine_InternalDeallocateEntry(void* p, void* q);
void hkArrayUtil__reduce(void* alloc, void* vec, int elemsz, void* p, int n);
struct SplitIsland_Head58
{
    int hdr;
    SplitIsland_Vec48 vec;
    int inlineBuf;
};
struct SplitIsland_Arg1
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int f20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    int fB4;
    int fieldB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    int fieldCC;
    int fieldD0;
    unsigned char fieldD4;
    unsigned char fD5;
    unsigned short fieldD6;
    int fieldD8;
    int fieldDC;
    int fieldE0;
    int fieldE4;
    int fieldE8;
    int fieldEC;
    int fieldF0;
    int fieldF4;
    int fieldF8;
    int fieldFC;
    int field100;
    int field104;
    int field108;
    int field10C;
    int field110;
    int field114;
    int field118;
    int field11C;
    int field120;
    int field124;
    int field128;
    int field12C;
    int field130;
    int field134;
    int field138;
    int field13C;
    int field140;
    int field144;
    int field148;
    int field14C;
    int field150;
    int field154;
    int field158;
    int field15C;
    int field160;
    int field164;
    int field168;
    int field16C;
    int field170;
    int field174;
    int field178;
    int field17C;
    int field180;
    int field184;
    int field188;
    int field18C;
    int field190;
    int field194;
    int field198;
    int field19C;
    int field1A0;
    int field1A4;
    int field1A8;
    int field1AC;
    int field1B0;
    int field1B4;
    int field1B8;
    int field1BC;
    int field1C0;
    int field1C4;
    int field1C8;
    int field1CC;
    int field1D0;
    int field1D4;
    int field1D8;
    int field1DC;
    int field1E0;
    int field1E4;
    int field1E8;
    int field1EC;
    int field1F0;
    int field1F4;
    int field1F8;
    int field1FC;
    int field200;
    int field204;
    int field208;
    int field20C;
    int field210;
    int field214;
    int field218;
    int field21C;
    int field220;
    int field224;
    int field228;
    int field22C;
    int field230;
    int field234;
    int field238;
    int field23C;
    int field240;
    int field244;
    int field248;
    int field24C;
    int field250;
    int field254;
    int field258;
    int field25C;
    int field260;
    int field264;
    int field268;
    int field26C;
    int field270;
    int field274;
    int field278;
    int field27C;
    int field280;
    int field284;
    int field288;
    int field28C;
    int field290;
    int field294;
    int field298;
    int field29C;
    int field2A0;
    int field2A4;
    int field2A8;
    int field2AC;
    int field2B0;
    int field2B4;
    int field2B8;
    int field2BC;
    int field2C0;
    int field2C4;
    int field2C8;
    int field2CC;
    int field2D0;
    int field2D4;
    int field2D8;
    int field2DC;
    int field2E0;
    int field2E4;
    int field2E8;
    int field2EC;
    int field2F0;
    int field2F4;
    int field2F8;
    int field2FC;
    int field300;
    unsigned char field304;
    unsigned char f305;
    unsigned char f306;
    void UpdateState_00c911f0(hkpSimulationIsland* a);
    void ProcessState_00c91230(hkpSimulationIsland* a);
};
struct SplitIsland_StreamLink
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char ownerOffset;
    __forceinline hkpSimulationIsland* SplitIsland_owner()
    {
        return (hkpSimulationIsland*)((SplitIsland_Node2*)((char*)this + ownerOffset))->fCC;
    }
};
struct SplitIsland_StreamRecord
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char size;
    int unk04;
    int unk08;
    int unk0c;
    SplitIsland_StreamLink* link10;
    SplitIsland_StreamLink* link14;
};
template <class T> class SplitIsland_CursorValue
{
    T value;

  public:
    __forceinline SplitIsland_CursorValue()
    {}
    __forceinline SplitIsland_CursorValue(T p) : value(p)
    {}
    __forceinline void operator=(T p)
    {
        value = p;
    }
    __forceinline T SplitIsland_val() const
    {
        return value;
    }
    __forceinline operator T() const
    {
        return SplitIsland_val();
    }
};
template <class T> __forceinline T* SplitIsland_memoryAdvance(T* p, long size)
{
    return (T*)((char*)p + size);
}
struct SplitIsland_ScratchArena
{
    SplitIsland_CursorValue<void*> next;
    SplitIsland_CursorValue<void*> start;
    SplitIsland_CursorValue<void*> end;
    __forceinline void* SplitIsland_allocateRaw(int rounded)
    {
        void* p = next;
        next = SplitIsland_memoryAdvance(p, rounded);
        return p;
    }
    __forceinline void* SplitIsland_allocateRound(int n)
    {
        int rounded = (n + 127) & ~127;
        return SplitIsland_allocateRaw(rounded);
    }
};
__forceinline SplitIsland_ScratchArena& SplitIsland_scratch()
{
    return *(SplitIsland_ScratchArena*)SplitIsland_cursor();
}
template <class T> __forceinline T* SplitIsland_allocateWords(int n)
{
    return (T*)SplitIsland_scratch().SplitIsland_allocateRound(n * sizeof(T));
}
template <class T> struct SplitIsland_StackBuffer
{
    T* data;
    __forceinline SplitIsland_StackBuffer()
    {}
    __forceinline SplitIsland_StackBuffer(int n)
    {
        SplitIsland_allocate(n);
    }
    __forceinline void SplitIsland_allocate(int n)
    {
        int* cur = SplitIsland_cursor();
        int address = *cur;
        *cur = address + ((n * sizeof(T) + 127) & ~127);
        data = (T*)address;
    }
    __forceinline SplitIsland_StackBuffer(int n, bool includeSentinel)
    {
        int* cur = SplitIsland_cursor();
        int address = *cur;
        int elements = n + (includeSentinel ? 1 : 0);
        *cur = address + ((elements * sizeof(T) + 127) & ~127);
        data = (T*)address;
    }
    __forceinline void SplitIsland_release()
    {
        T* p = data;
        *SplitIsland_cursor() = (int)p;
    }
};
template <class T> struct SplitIsland_CountedBuffer : SplitIsland_StackBuffer<T>
{
    int debugCount;
    __forceinline SplitIsland_CountedBuffer(int n) : SplitIsland_StackBuffer<T>(n)
    {}
    __forceinline SplitIsland_CountedBuffer(int n, bool sentinel) : SplitIsland_StackBuffer<T>(n, sentinel)
    {}
};
__forceinline int SplitIsland_packedLevel(unsigned short encoded, unsigned char generation)
{
    int value = encoded;
    if (generation == (value >> 14))
        return (value >> 7) & 127;
    return value & 127;
}
__forceinline int SplitIsland_strongerLevel(int e, int a)
{
    e &= 127;
    a &= 127;
    return a > e ? a : e;
}
struct SplitIsland_WorkArrays
{
    SplitIsland_L60 groups;
    SplitIsland_TempEC members;
};
struct SplitIsland_MapWord
{
    __forceinline void SplitIsland_allocatePlain(int n)
    {
        int* at = SplitIsland_cursor();
        int start = *at;
        *at = start + ((n * 4 + 127) & ~127);
        data = (int*)start;
    }

    int* data;
    int debugCount;
    __forceinline void SplitIsland_allocate(int n)
    {
        data = SplitIsland_allocateWords<int>(n);
    }
    __forceinline void SplitIsland_release()
    {
        int* old = data;
        *SplitIsland_cursor() = (int)old;
    }
};
union SplitIsland_MapReuse
{
    SplitIsland_MapWord map;
    int biggest;
};
__forceinline int SplitIsland_boundedWeight(int minimum, int actual)
{
    return minimum > actual ? minimum : actual;
}
__forceinline void SplitIsland_combineGroups(SplitIsland_Arg1* world, SplitIsland_Obj38& find, SplitIsland_Vec48& nodes,
                                             SplitIsland_L60& sizes, SplitIsland_StackBuffer<char>& flags)
{
    int count = sizes.f04;
    SplitIsland_CountedBuffer<int> totals(count);
    SplitIsland_MapWord active;
    active.SplitIsland_allocate(count);
    for (int i = 0; i < count; ++i)
    {
        active.data[i] = 0;
        totals.data[i] = 0;
    }
    if (world->fD5)
    {
        for (int i = 0; i < nodes.cnt; ++i)
        {
            SplitIsland_Node2* node = (SplitIsland_Node2*)nodes.data[i];
            int group = (*find.f00)[i];
            int q = SplitIsland_packedLevel(node->fEC, world->f306);
            int a = SplitIsland_packedLevel(node->fEA, world->f305);
            int level = SplitIsland_strongerLevel(q, a);
            if (level <= 5)
                active.data[group] = 1;
            totals.data[group] += SplitIsland_boundedWeight(1, (unsigned short)node->fB0);
        }
    }
    else
    {
        for (int i = 0; i < nodes.cnt; ++i)
        {
            SplitIsland_Node2* node = (SplitIsland_Node2*)nodes.data[i];
            int group = (*find.f00)[i];
            active.data[group] = 1;
            totals.data[group] += SplitIsland_boundedWeight(1, (unsigned short)node->fB0);
        }
    }
    for (int i = 0; i < count; ++i)
        if (!active.data[i])
            totals.data[i] = -1;
    int* map = active.data;
    int outputs = 0;
    if (count > 0)
    {
        for (int i = 0, *outMap = map; i < count; ++i, ++outMap)
        {
            int weight = totals.data[i];
            if (weight == -2)
                continue;
            int group = outputs++;
            flags.data[group] = 0;
            *outMap = group;
            if (weight < 0)
                continue;
            for (int j = i + 1; j < count; ++j)
            {
                if (weight + 10 >= world->fB4)
                    break;
                int next = totals.data[j];
                if (next < 0)
                    continue;
                int sum = next + weight;
                if (sum >= world->fB4)
                    continue;
                flags.data[group] = 1;
                map[j] = group;
                weight = sum;
                totals.data[j] = -2;
            }
        }
    }
    find.RemapAndAccumulate((int*)&active.data, outputs, &sizes);
    active.SplitIsland_release();
    totals.SplitIsland_release();
}
__forceinline void SplitIsland_classifyParts(SplitIsland_Arg1* world, SplitIsland_Obj38& find, SplitIsland_Vec48& nodes,
                                             SplitIsland_L60& sizes, SplitIsland_StackBuffer<char>& flags)
{
    int count = sizes.f04;
    SplitIsland_MapWord mark;
    mark.SplitIsland_allocatePlain(count);
    for (int i = 0; i < count; ++i)
        mark.data[i] = 0;
    for (int i = 0; i < nodes.cnt; ++i)
    {
        SplitIsland_Node2* node = (SplitIsland_Node2*)nodes.data[i];
        int q = SplitIsland_packedLevel(node->fEC, world->f306);
        int a = SplitIsland_packedLevel(node->fEA, world->f305);
        if (SplitIsland_strongerLevel(q, a) <= 5)
            mark.data[(*find.f00)[i]] = 1;
    }
    int* map = mark.data;
    int outputs = 1;
    flags.data[0] = (char)outputs;
    for (int i = 0; i < count; ++i)
    {
        if (mark.data[i])
            map[i] = 0;
        else
        {
            map[i] = outputs;
            flags.data[outputs] = 0;
            ++outputs;
        }
    }
    if (outputs > count)
    {
        flags.data[0] = 0;
        mark.SplitIsland_release();
    }
    else
    {
        find.RemapAndAccumulate((int*)&mark.data, outputs, &sizes);
        mark.SplitIsland_release();
    }
}

inline void SplitIsland_Sub30::SplitIsland_readTransfer(SplitIsland_H44& info) const
{
    info.f00 = f14;
    info.f04 = f14;
    info.f06 = f16;
    info.f08 = f18;
}
inline void SplitIsland_Sub30::SplitIsland_debitTransfer(const SplitIsland_H44& info)
{
    f16 -= info.f06;
    f18 -= info.f08;
    f14 -= info.f04;
}
// The shared layout does not yet name these constraint-transfer totals at +0x0c, +0x10 and +0x14.
inline void SplitIsland_removeTransfer(hkpSimulationIsland* island, SplitIsland_Target* constraint, SplitIsland_H44& info)
{
    if (constraint->f30)
    {
        ((int*)island)[3] -= info.f04;
        ((int*)island)[4] -= info.f06;
        ((int*)island)[5] -= info.f08;
        constraint->f30->SplitIsland_debitTransfer(info);
    }
}
inline void SplitIsland_Target::SplitIsland_assignOwner(hkpSimulationIsland* p)
{
    SplitIsland_owner = p;
}
__forceinline void SplitIsland_Vec48::SplitIsland_appendNodeUnchecked(SplitIsland_Node2* const& value)
{
    int* destination = data + cnt;
    __assume(destination != 0);
    new (destination) int((int)value);
    ++cnt;
}
// @fnv 0x00cb6060
// src: HAVOK_LIB 0x00cb6060
void hkpWorldOperationUtil_splitSimulationIsland(hkpSimulationIsland* a0, SplitIsland_Arg1* a1, SplitIsland_Arg2Vec* a2, void* a3)
{
    SplitIsland_L60 groups;
    SplitIsland_Obj38 sel;
    SplitIsland_CountedBuffer<int> cand((*(SplitIsland_Vec48*)&a0->entities).cnt);
    sel.FUN_00d27f70((int*)&cand.data, (*(SplitIsland_Vec48*)&a0->entities).cnt);
    if (a0->CheckIslandConnectivity((IncompleteClassType&)sel))
    {
        a0->flags25 &= 0xf3;
        cand.SplitIsland_release();
        return;
    }
    groups.f00 = groups.data;
    groups.f04 = 0;
    groups.f08 = 0x80000020;
    sel.RemapIndices(&groups);
    SplitIsland_StackBuffer<char> states(groups.f04, true);
    if (a0->flags25 & 0xc)
    {
        if (!!a1->fD5)
        {
            SplitIsland_classifyParts(a1, sel, (*(SplitIsland_Vec48*)&a0->entities), groups, states);
            if (groups.f04 != 1)
            {
            }
            else
            {
                {
                    int released = (int)states.data;
                    int* z = SplitIsland_cursor();
                    *z = released;
                }
                int* aPtr = SplitIsland_cursor();
                unsigned long origin;
                SplitIsland_Alloc* ale = (SplitIsland_Alloc*)((SplitIsland_CursorObj*)aPtr)->alloc;
                origin = groups.f08;
                groups.f04 = 0;
                if ((origin & 0x80000000) == 0)
                {
                    ale->FreeLike(groups.f00, (origin & 0x3fffffff) * 4);
                }
                groups.f00 = 0;
                groups.f08 = (int)0x80000000;
                cand.SplitIsland_release();
                return;
            }
        }
        else
        {
            SplitIsland_combineGroups(a1, sel, (*(SplitIsland_Vec48*)&a0->entities), groups, states);
        }
    }
    else
    {
        if (!!a1->fB4)
        {
            SplitIsland_combineGroups(a1, sel, (*(SplitIsland_Vec48*)&a0->entities), groups, states);
        }
        else
        {
            hkString_memSet(states.data, 0, groups.f04 + 1);
        }
    }
    int arrays;
    arrays = sel.MoveLargestToFirst(&groups);
    {
        char* av = (char*)(int)states.data;
        char r = av[0];
        char first = av[arrays];
        av[0] = first;
        av[arrays] = r;
        int kIter = *groups.f00;
        int originalCount = (*(SplitIsland_Vec48*)&a0->entities).cnt;
        long alV = groups.f04;
        int* generation = SplitIsland_cursor();
        if (alV == 1)
        {
            *generation = (int)states.data;
            {
                int* aPtr = SplitIsland_cursor();
                unsigned long origin;
                SplitIsland_Alloc* ale = (SplitIsland_Alloc*)((SplitIsland_CursorObj*)aPtr)->alloc;
                origin = groups.f08;
                groups.f04 = 0;
                if ((origin & 0x80000000) == 0)
                {
                    ale->FreeLike(groups.f00, (origin & 0x3fffffff) * 4);
                }
                groups.f00 = 0;
                groups.f08 = (int)0x80000000;
                cand.SplitIsland_release();
                return;
            }
        }
        else
        {
            int tmp = *generation;
            *generation = tmp + (((alV * 4) + 0x7f) & ~0x7f);
            ((SplitIsland_Flags25&)a0->flags25).groupState = av[0] != 0;
            *(int*)tmp = (int)a0;
            for (int i = 1; i < alV; i++)
            {
                int* firstElem = SplitIsland_cursor();
                SplitIsland_AllocB* alL = (SplitIsland_AllocB*)((SplitIsland_CursorObj*)firstElem)->alloc;
                hkpSimulationIsland* no = (hkpSimulationIsland*)alL->AllocSz(0x6c);
                no->m_usMemSizeAndFlags = 0x6c;
                no = ::new (no) hkpSimulationIsland((hkpWorld*)a1);
                ((SplitIsland_Flags26&)no->flags26).type26 = 1;
                ((SplitIsland_Flags26&)no->flags26).pending26 = 0;
                ((SplitIsland_Flags26&)no->flags26).active26 = 1;
                ((SplitIsland_Flags25&)no->flags25).groupState = av[i] != 0;
                no->storageIndex = (short)a2->cnt;
                ((SplitIsland_Vec48*)a2)->SplitIsland_append((int)no);
                ((int*)tmp)[i] = (int)no;
                (*(SplitIsland_Vec48*)&no->entities).SplitIsland_reserve(groups.f00[i]);
            }
            // cb68cc: reset a0 f48 vector, relink elements
            {
                int* c = (*(SplitIsland_Vec48*)&a0->entities).data;
                int j = (*(SplitIsland_Vec48*)&a0->entities).cnt;
                if ((bool)a3)
                {
                    (*(SplitIsland_Vec48*)&a0->entities).SwapThreeInts((int)a3);
                    (*(SplitIsland_Vec48*)&a0->entities).cnt = 0;
                    int a = *groups.f00;
                    (*(SplitIsland_Vec48*)&a0->entities).SplitIsland_reserve(a);
                }
                else
                {
                    (*(SplitIsland_Vec48*)&a0->entities).cnt = 0;
                }

                for (int k = 0; k < j; ++k)
                {
                    hkpSimulationIsland* el = (hkpSimulationIsland*)((int*)tmp)[cand.data[k]];
                    SplitIsland_Node2* cpF = (SplitIsland_Node2*)c[k];
                    cpF->fCC = (int)el;
                    cpF->fA8 = (short)(*(SplitIsland_Vec48*)&el->entities).cnt;
                    (*(SplitIsland_Vec48*)&el->entities).SplitIsland_appendNodeUnchecked(cpF);
                    if (a0 != el)
                    {
                        SplitIsland_Sub30* y = (SplitIsland_Sub30*)cpF->fAC;
                        for (int si = 0; si < (unsigned short)cpF->fB0; ++y, ++si)
                        {
                            SplitIsland_H44 h;
                            y->SplitIsland_readTransfer(h);
                            h.f00 = a0->m_iMaxSchemaSize;
                            --a0->unk1C;
                            SplitIsland_removeTransfer(a0, y->f00, h);
                            ++el->unk1C;
                            y->f00->SplitIsland_owner = el;
                            el->AccumulateStats((void*)y->f00, (GenericConstraintAtomScheme&)h);
                        }
                    }
                }
            }
            {
                // cb6a19: walk a0 f38 vector with temp small-vector
                {
                    int savedA1f20 = a1->f20;
                    int* f38data;
                    f38data = (*(SplitIsland_Vec48*)&a0->actions).data;
                    long n = (*(SplitIsland_Vec48*)&a0->actions).cnt;
                    (*(SplitIsland_Vec48*)&a0->actions).cnt = 0;
                    for (int saved38B = 0; saved38B < n; saved38B++)
                    {
                        SplitIsland_Elem2* e2 = (SplitIsland_Elem2*)f38data[saved38B];
                        if (e2 == 0)
                            continue;
                        int base;
                        base = 0;
                        {
                            SplitIsland_TempEC members;
                            members.f04 = 0;
                            members.f00 = members.data;
                            members.f08 = (int)0x80000010;
                            e2->GetList(&members);
                            for (int i = 0; i < members.f04; i++)
                            {
                                base = ((SplitIsland_Node2*)members.f00[i])->fCC;
                                if (base != savedA1f20)
                                    break;
                            }
                            int* SplitIsland_val;
                            SplitIsland_val = SplitIsland_cursor();
                            SplitIsland_Alloc* deallocate =
                                (SplitIsland_Alloc*)((SplitIsland_CursorObj*)SplitIsland_val)->alloc;
                            unsigned int ptr = members.f08;
                            members.f04 = 0;
                            if ((ptr & 0x80000000) == 0)
                            {
                                deallocate->FreeLike(members.f00, (ptr & 0x3fffffff) * 4);
                            }
                            members.f00 = 0;
                            members.f08 = (int)0x80000000;
                        }
                        e2->f0c = base;
                        hkpSimulationIsland* head = (hkpSimulationIsland*)base;
                        (*(SplitIsland_Vec48*)&head->actions).SplitIsland_append((int)e2);
                    }
                    a1->UpdateState_00c911f0(a0);
                }
                // cb6b6a / cb6c2d: walk a0 ox vec at +0x5c
                if (((originalCount - kIter) * 8) < originalCount)
                {
                    SplitIsland_Head58* ox = (SplitIsland_Head58*)&a0->unk58;
                    for (int saved38B = 0; saved38B < ox->vec.cnt; saved38B++)
                    {
                        char* elem = (char*)ox->vec.data[saved38B];
                        char* len;
                        len = elem + ((FUN_00cb7460_class*)ox)->hkpAgentNnTrack_getSectorSize(saved38B);
                        char* s = elem;
                        while (s < len)
                        {
                            int buf18 = (int)((SplitIsland_StreamRecord*)s)->link10->SplitIsland_owner();
                            if (((hkpSimulationIsland*)buf18)->storageIndex == 0xffff)
                            {
                                buf18 = (int)((SplitIsland_StreamRecord*)s)->link14->SplitIsland_owner();
                            }
                            if (buf18 == (int)a0)
                            {
                                s += ((SplitIsland_StreamRecord*)s)->size;
                            }
                            else
                            {
                                int b = s - elem;
                                CloneRecord(&((hkpSimulationIsland*)buf18)->unk58, s);
                                _hkAgentNnMachine_InternalDeallocateEntry(ox, s);
                                if (saved38B >= ox->vec.cnt)
                                    break;
                                elem = (char*)ox->vec.data[saved38B];
                                s = elem + b;
                            }
                            len = elem + ((FUN_00cb7460_class*)ox)->hkpAgentNnTrack_getSectorSize(saved38B);
                        }
                    }
                }
                else
                {
                    SplitIsland_Head58 idx;
                    idx.vec.data = &idx.inlineBuf;
                    idx.vec.cnt = 0;
                    idx.vec.cap = (int)0x80000001;
                    idx.hdr = 0x200;
                    if ((*(SplitIsland_Vec48*)&a0->unk5C).cnt == 1)
                    {
                        idx.vec.SplitIsland_appendUnchecked((*(SplitIsland_Vec48*)&a0->unk5C).data[0]);
                        (*(SplitIsland_Vec48*)&a0->unk5C).cnt = 0;
                    }
                    else if ((*(SplitIsland_Vec48*)&a0->unk5C).cnt > 1)
                    {
                        idx.vec.SplitIsland_reserve(2);
                        idx.vec.SwapThreeInts((int)&(*(SplitIsland_Vec48*)&a0->unk5C));
                    }
                    {
                        long cpV = idx.hdr;
                        idx.hdr = a0->unk58;
                        a0->unk58 = cpV;
                    }
                    for (int saved38B = 0; saved38B < idx.vec.cnt; saved38B++)
                    {
                        int span = 0;
                        unsigned int elem = idx.vec.data[saved38B];
                        char* s = (char*)elem;
                        span = (saved38B + 1 == idx.vec.cnt) ? idx.hdr : 0x200;
                        char* endp = (char*)(span + elem);
                        while (s < endp)
                        {
                            int buf18 = (int)((SplitIsland_StreamRecord*)s)->link10->SplitIsland_owner();
                            if (((hkpSimulationIsland*)buf18)->storageIndex == 0xffff)
                            {
                                buf18 = (int)((SplitIsland_StreamRecord*)s)->link14->SplitIsland_owner();
                            }
                            CloneRecord(&((hkpSimulationIsland*)buf18)->unk58, s);
                            s += ((SplitIsland_StreamRecord*)s)->size;
                        }
                        int* t2 = SplitIsland_cursor();
                        SplitIsland_Alloc* cntL = (SplitIsland_Alloc*)((SplitIsland_CursorObj*)t2)->alloc;
                        cntL->V08((void*)elem, 0x200);
                    }
                    idx.vec.cnt = 0;
                    {
                        int* cpL = SplitIsland_cursor();
                        SplitIsland_Alloc* ala = (SplitIsland_Alloc*)((SplitIsland_CursorObj*)cpL)->alloc;
                        int pForm = idx.vec.cap;
                        idx.vec.cnt = 0;
                        if ((pForm & 0x80000000) == 0)
                        {
                            ala->FreeLike(idx.vec.data, (pForm & 0x3fffffff) * 4);
                        }
                    }
                }
                // cb6d6d: c91230 + pow2-spread grow on a0 vec5c
                a1->ProcessState_00c91230(a0);
                (*(SplitIsland_Vec48*)&a0->unk5C).SplitIsland_compact();
                // cb6dee: final byte-accumulate loop over SplitIsland_cursor array
                for (int i = 1; i < alV; i++)
                {
                    char cp3 = a0->unk24;
                    hkpSimulationIsland* z = (hkpSimulationIsland*)((int*)tmp)[i];
                    cp3 += i;
                    z->unk24 = cp3;
                }
                {
                    int released = tmp;
                    int* z = SplitIsland_cursor();
                    *z = released;
                }
            }
        }
    }
cleanup: {
    int released = (int)states.data;
    int* z = SplitIsland_cursor();
    *z = released;
}
obj:
    int* aPtr = SplitIsland_cursor();
    unsigned long origin;
    SplitIsland_Alloc* ale = (SplitIsland_Alloc*)((SplitIsland_CursorObj*)aPtr)->alloc;
    origin = groups.f08;
    groups.f04 = 0;
    if ((origin & 0x80000000) == 0)
    {
        ale->FreeLike(groups.f00, (origin & 0x3fffffff) * 4);
    }
    groups.f00 = 0;
    groups.f08 = (int)0x80000000;
    cand.SplitIsland_release();
}

__forceinline int SplitIsland_largerContribution(int a, int b)
{
    return a > b ? a : b;
}

// Retain this unit's inline implementation using the shared accumulator declaration.
inline void hkpConstraintOwner::AccumulateStats(void* object, GenericConstraintAtomScheme& scheme)
{
    SplitIsland_Target* constraint = (SplitIsland_Target*)object;
    SplitIsland_H44& info = (SplitIsland_H44&)scheme;
    if (constraint->f30)
    {
        m_iMaxSchemaSize = SplitIsland_largerContribution(m_iMaxSchemaSize, info.f00);
        m_iMaxSchemaSize = SplitIsland_largerContribution(m_iMaxSchemaSize, info.f04);
        ((int*)this)[3] += info.f04;
        ((int*)this)[4] += info.f06;
        ((int*)this)[5] += info.f08;
        SplitIsland_Sub30* rec = constraint->f30;
        const unsigned int r = rec->f16 + info.f06;
        const unsigned int t = rec->f18 + info.f08;
        const unsigned int b = rec->f14 + info.f04;
        rec->f16 = (unsigned short)r;
        rec->f18 = (unsigned short)t;
        rec->f14 = (unsigned short)b;
        m_iMaxSchemaSize = SplitIsland_largerContribution(m_iMaxSchemaSize, (int)constraint->f30->f14);
    }
}
