#define FNV64_HKVECTOR4_PACKET_BODIES
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkResult.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpBroadPhaseCastCollector.h"
#include "../../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../include/hkpEntity.h"
#include "../../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../../include/hkpSimulationIsland.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkVector4.h"

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/Transform.h"

// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl Deallocate(void*);
extern "C" void* DAT_010ccf7c;
struct FUN_00d08330 {
    void* m_p;
    FUN_00d08330(char);
};
extern int DAT_010ccf8c;
extern void __cdecl Deallocate(void*);
struct FUN_00d08350 {
    void* m_p;
    void* __thiscall Set(void* arg);
};
struct FUN_00d083a0_class {
    void __thiscall hkpAabbTreeWorldManager_setWorkingBuffer(int a);
};
struct FUN_00d08ff0_t {
    int a;
    int b;
    int c;
    int d;
    void hkpAabbTreeWorldManager_gatherActiveCollidablesFromWorld(int);
    void hkpAabbTreeWorldManager_gatherInactiveCollidablesFromWorld(int);
};
void hkpAabbTreeWorldManager_gatherActiveCollidablesFromWorld(FUN_00d08ff0_t* self, int arg);
void hkpAabbTreeWorldManager_gatherInactiveCollidablesFromWorld(FUN_00d08ff0_t* self, int arg);
void hkpAabbTreeWorldManager_gatherCollidablesFromWorld(FUN_00d08ff0_t* self, int arg);
extern int DAT_010ccfac;
void __cdecl Deallocate(void*);
struct FUN_00d0a150 {
    int* p;
    FUN_00d0a150(bool b);
};
extern int DAT_010ccfa0;
extern int DAT_010ccfac;
extern "C" void __cdecl Deallocate(void*);
struct FUN_00d0a1a0 {
    int* a;
    int* b;
    int __thiscall Init(int p);
};
int __fastcall hkpAabbTreeWorldManager_calcWorkingBufferSize(void* self, int, int value);
struct HashEntryTable { void clear(); };
struct FUN_00d08550_Class {
    void __thiscall hkpAabbTreeWorldManager_setTreeIsClean();
};
struct FUN_00d08560_class {
    void __thiscall hkpAabbTreeWorldManager_reset();
};
struct FUN_00d08940_class {
    void __thiscall hkpAabbTreeWorldManager_queueActivated(void* arg);
};
struct FUN_00d08a40_class {
    char pad0[8];
    char m_flag8;
    char pad9[0x43];
    char m_4c;
    char m_4d;
    void __thiscall ProcessFlaggedEntries(void* arg);
};
struct FUN_00cd2a00_class {
    void __thiscall GetValue_00cd2a00();
};
void __stdcall hkpAabbTreeWorldManager_getNodeIdx(void* arg);
struct FUN_00d08a90_class {
    void __thiscall hkpAabbTreeWorldManager_inactiveEntityMovedCallback(void* arg);
};
struct FUN_00d08fb0_Class {
    char pad[0x54];
    char m_54;
    char m_55;
    void __thiscall hkpAabbTreeWorldManager_entityAddedCallback(char* arg);
    void __thiscall hkpAabbTreeWorldManager_pushBackToActiveList(char* arg);
};
void __cdecl hkpAabbTreeWorldManager_pushBackToActiveList(void* self, int a);
struct FUN_00d08fd0_class {
    char pad[0x50];
    char m_50;
    char m_51;
    void __thiscall hkpAabbTreeWorldManager_phantomAddedCallback(int a);
    void __thiscall hkpAabbTreeWorldManager_pushBackToActiveList(int a);
};
void __cdecl Deallocate(void*);
struct FUN_00d0a130 {
    void* p;
    void* __thiscall Set(char b);
};
// add ecx,-0x14; jmp FUN_00d08570 : override in Derived forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void hkpAabbTreeWorldManager_removeObjectFromTree();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct SecondaryBase
{
    virtual void HkpAabbTreeWorldManager_removeObjectFromTree_Thunk();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void HkpAabbTreeWorldManager_removeObjectFromTree_Thunk();
};
Derived::Derived()
{
}
struct FUN_00d0a1f0_Class {
    void __thiscall hkpAabbTreeWorldManager_setUpToDate(unsigned char value);
};
void __stdcall nullsub_62(int);
struct FUN_00cd29f0_cls {
    void hkpWorldObject_setTreeData(int iValue);
};
void __cdecl DispatchToOffsetTarget(hkpCollidable* pkObject, unsigned short usValue);
// Only pointer/reference declarations below need these ray-cast types; no local layout is required.
struct hkpWorldRayCastInput;
class hkpWorldRayCaster;
struct hkpWorldRayCastOutput;
struct hkpRayHitCollectorD084;
class hkpRayCastCollectorBaseD084 {
public:
    virtual void CollectRayHit() throw();
};
class hkpTreeCastCallbackD084 {
public:
    virtual float processLeaf() throw();
};
class FUN_00d9a040 : public hkpRayCastCollectorBaseD084, public hkpTreeCastCallbackD084 {
public:
    const hkpWorldRayCastInput* m_pRayCastInput;
    const hkpRayCollidableFilter* m_iFilter;
    const hkpRayShapeCollectionFilter* m_shapeFilter;
    hkpWorldRayCastOutput* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    int m_1c;

    FUN_00d9a040() throw();
};
hkBool __cdecl hkKdTreeUtils_castRayIterative(void* pkBroadPhase, const hkVector4& kFrom, const hkVector4& kTo, hkpWorldRayCaster* pkCaster) throw();
void __cdecl hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_castRay(void* pkTree, const hkVector4& kFrom, const hkVector4& kTo, hkpTreeCastCallbackD084* pkCaster, float fEarlyOut) throw();
class hkpRayCastQueryD084 {
public:
    int m_00;
    int m_04;
    int m_08;
    void* m_iValueAt40;
    void* m_pJobSemaphore;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    bool m_useTree;

    void CastRay(const hkpWorldRayCastInput& kInput, const hkpCollisionFilter* pkFilter, hkpRayHitCollectorD084* pkCollector) const throw();
};
class hkBroadPhaseD085 {
public:
    void hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_remove(unsigned short id);
};
class hkHandlerD085 {
public:
    int unk00[3];
    hkBroadPhaseD085* m_pJobSemaphore;
    int unk10[5];
    bool m_enabled;
    char unk25[0x1f];
    hkArray<hkpCollidable*> m_kCollidables;

    unsigned short hkpAabbTreeWorldManager_getNodeIdx(hkpCollidable* c);
    void hkpAabbTreeWorldManager_removeObjectFromTree(hkpEntity* entity);
};
struct PlaceTagD088 {};
inline void* operator new(unsigned int, void* p, PlaceTagD088) throw() { __assume(p != 0); return p; }
inline void operator delete(void*, void*, PlaceTagD088) throw() {}
template <typename T>
__forceinline void hkArrayBase<T>::pushBackUnchecked(const T& e)
{
    new (&m_data[m_iElementCount], PlaceTagD088()) T(e);
    m_iElementCount++;
}
template <typename T>
__forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        m_data[index] = m_data[m_iElementCount];
}

class hkpEntityListD088 {
public:
    char m_pad00[0x44];
    hkArray<hkpCollidable*> m_kCollidables;
    char m_pad50[0xc];
    bool m_checkAll;
    char m_pad5d[3];
    int m_currentIndex;
    int m_maxChecksPerCall;

    __forceinline void checkCollidable(int i, hkArray<hkpCollidable*>& kInactive)
    {
        hkpCollidable* pkCollidable = m_kCollidables.m_data[i];
        if (pkCollidable->m_kBroadPhaseHandle.m_type == 1) {
            hkpEntity* pkEntity = static_cast<hkpEntity*>(pkCollidable->getOwner());
            unsigned char active;
            if (pkEntity && !*(pkEntity->isActive_00c9bff0(&active))) {
                kInactive.pushBackUnchecked(m_kCollidables.m_data[i]);
                m_kCollidables.removeAt(i);
            }
        }
    }

    bool CheckCollidables(hkArray<hkpCollidable*>& kInactive) throw();
};
struct hkObjectE02;
struct hkLoaderE02 {
    int Get(char const* name, hkObjectE02** out);
};
hkMemoryRouter* __cdecl _FNV_e03300_arena();
struct Sink {
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(void*, int, int);
};
struct FUN_00d08940_shell {
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    hkLoaderE02 loader;
    void hkpAabbTreeWorldManager_queueActivated(char const* name);
};
struct FUN_00d9a4d0_class {
    void __thiscall GetEntryOffset(unsigned int value);
};
struct FUN_00d08c70_class {
    int unk00;
    int unk04;
    int unk08;
    FUN_00d9a4d0_class* unk0C;
    void __thiscall hkpAabbTreeWorldManager_getNode(void* arg);
};
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
class hkpEntityD08C;
void __cdecl DispatchToOffsetTarget(hkpEntityD08C* pkEntity, int iFlags);
class hkpEntityListD08C {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    bool m_enabled;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    hkArray<hkpEntityD08C*> m_kActorEntries;

    void hkpAabbTreeWorldManager_pushBackToActiveList(hkpEntityD08C* pkEntity);
};
class hkObjD099 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* m_28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    void* m_48;

    void hkpAabbTreeWorldManager_buildKdTree(int* p, void* a, void* b, void* c, void* d);
    void hkpAabbTreeWorldManager_buildActiveTree(void* a, void* c, void* d);
};
struct FUN_00d0a1e0_class {
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
    char unk68;
    char __thiscall GetUnk68_00d0a1e0();
};
extern int DAT_010ccfcc;
extern int DAT_010ccfe0;
extern int DAT_010ccfec;
extern float DAT_0104da4c;
__declspec(align(16)) struct S00d08740_coll {
    int m_00;
    int m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_24;
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
    float m_80;
    void ComputeValues_00d984b0(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
    void ProcessAndReturnValue_00d9a2a0(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
};
struct S00d08740_cls {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    char m_24;
    char m_25;
    char m_26;
    char m_27;
    void Collect(void* kFrom, void* kTo, void* pkRoot, void* pkFilter, void* pkShapeFilter, void* pkOutput, void* pkCollector);
};
class hkMemoryAllocatorD089;
class hkMapBaseD089 {
public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkResult LookupBucketValue(unsigned int key, unsigned int* out) const;
    int hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocatorD089& alloc, unsigned int key, unsigned int val);
};
class OwnerD089 {
public:
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
    hkMapBaseD089 m_map;

    void hkpAabbTreeWorldManager_queueInactivated(unsigned int key);
};
class hkpPrimaryD08 {
public:
    virtual ~hkpPrimaryD08();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
class hkpIslandListenerD08 {
public:
    virtual void islandAddedCallback(hkpSimulationIsland* island);
    virtual void MarkAndProcessIslandCollidables(hkpSimulationIsland* island);
};
class TrackerD08 : public hkpPrimaryD08, public hkpIslandListenerD08 {
public:
    int unk20;
    bool m_enabled;
    char unk25;
    short unk26;
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
    bool m_dirty;
    bool m_needsUpdate;

    void hkpAabbTreeWorldManager_queueInactivated(hkpCollidable* collidable);
    virtual void MarkAndProcessIslandCollidables(hkpSimulationIsland* island);
};
extern int DAT_010ccfcc;
extern float DAT_0104da4c;
__declspec(align(16)) struct S00d0a490_Obj {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
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
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    float m_80;
    int m_84;
    int m_88;
    int m_8c;
    int ComputeValues_00d984b0(int, int, int, int, int, int, int, int);
};
struct S00d0a490_cls {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int __thiscall CallSubroutine(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
};
void __cdecl Object_DoNothing_00d083c0();
void __cdecl hkpAabbTreeWorldManager_gatherInactiveCollidablesFromWorld(hkArray<int*>& out, hkpWorld* world);
extern unsigned int DAT_0126835c;
extern char DAT_010cd234[];
extern char DAT_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct MonitorEvent { const char* tag; unsigned int time; unsigned int extra; };
struct UpdateOwner {
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
    bool initialized;
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
    bool dirty;
    void hkpAabbTreeWorldManager_fullBuild(void*, void*);
    void hkpAabbTreeWorldManager_incrementalBuild(void*, void*);
    void hkpAabbTreeWorldManager_updateFromWorld(void*, void*);
};
// FUN_00d0a200 : MSVC this-adjusting thunk  (sub ecx, 0x14 ; jmp <impl>)
struct A1_00d0a200 {
    A1_00d0a200();
    virtual void AdjustThisAndForward_00d0a200();
    char pad[0x10];
};
struct A2_00d0a200 {
    A2_00d0a200();
    virtual void AdjustThisAndForward_00d0a200();
};
struct Own_00d0a200 : A1_00d0a200, A2_00d0a200 {
    Own_00d0a200();
    virtual void key_fn();
// @fnv 0x00d0a200
// src: GUESS 0x00d0a200 (confidence: low)
    void AdjustThisAndForward_00d0a200();
};
Own_00d0a200::Own_00d0a200() { }
void Own_00d0a200::key_fn() { }
Own_00d0a200* make_00d0a200() { static Own_00d0a200 o; return &o; }
// Adjustor thunk: the secondary-base (+0x20) vtable entry for an override defined on the derived class.
class D0A230Primary {
public:
    virtual void FUN_00d0a230();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class D0A230Secondary {
public:
    virtual void FUN_00d0a230();
};
class D0A230Listener : public D0A230Primary, public D0A230Secondary {
public:
    D0A230Listener();
// @fnv 0x00d0a230
    virtual void FUN_00d0a230();
};
D0A230Listener::D0A230Listener()
{
}
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const char str_010cd130[];
extern const char str_010cd124[];
extern const char str_010cd11c[];
extern const char str_010cd104[];
extern const char str_010cd0fc[];
extern const char str_010cd0f4[];
extern const char str_010cd0e0[];
extern const char str_010cd0d0[];
extern const char str_010cd0c4[];
extern const char str_01076f38[];
extern const char str_010cd0b8[];
struct S00d094a0_Cmd { const char* m_name; unsigned m_uiCommandId; int m_08; const char* m_detail; };
union CountPhase { volatile unsigned ticks; int bytes; };
union StreamPhase { hkMonitorStream* stream; int capacity; };
struct CapPair {StreamPhase pointer;int capacity2;};
__forceinline void S00d094a0_beginList(const char* name, const char* detail)
{
    hkMonitorStream* t = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    S00d094a0_Cmd* p = (S00d094a0_Cmd*)t->m_end.m_storage;
    if ((char*)p < t->m_capacityMinus16.m_storage) {
        p->m_name = name;
        p->m_detail = detail;
        _ReadWriteBarrier();
        unsigned stamp;
        __asm {
            rdtsc
            mov dword ptr[stamp], eax
        }
        p->m_uiCommandId = stamp;
        t->m_end.m_storage = (char*)p + 16;
    }
}
__forceinline void S00d094a0_timer(const char* name)
{
    hkMonitorStream* t = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    S00d094a0_Cmd* p = (S00d094a0_Cmd*)t->m_end.m_storage;
    if ((char*)p < t->m_capacityMinus16.m_storage) {
        p->m_name = name;
        _ReadWriteBarrier();
        unsigned stamp;
        __asm {
            rdtsc
            mov dword ptr[stamp], eax
        }
        p->m_uiCommandId = stamp;
        t->m_end.m_storage = (char*)p + 12;
    }
}
struct S00d094a0_Alloc {
    virtual void f00();
    virtual void* AllocateMemoryBlock(int);
    virtual void f08();
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
    template<class T> __forceinline T* elements(int& count) {int bytes=count*4; void* p=AllocateBufferWithSize(bytes);count=bytes/4;return (T*)p;}

};
__forceinline S00d094a0_Alloc& S00d094a0_heap() { return *(S00d094a0_Alloc*)&hkMemoryRouter::getInstance().heap(); }
__forceinline void* reserveExternal(void*& data, int& capacity, int& bytes, int n) {
    S00d094a0_Alloc& a = S00d094a0_heap();
    bytes=n*4;
    void* p=a.AllocateBufferWithSize(bytes);
    int amount=bytes/4;
    data=p;
    capacity=amount;
    if(!capacity) capacity=0x80000000;
    return p;
}
struct __declspec(align(16)) S00d094a0_Vec { float x, y, z, w; };
struct __declspec(align(16)) S00d094a0_Desc {
    int m_uiItemCount; char m_04; char m_isMt; short m_06; int m_08; int m_0c;
    S00d094a0_Vec m_kMinimumCorner;
    S00d094a0_Vec m_kMaximumCorner;
    void hkKdTreeCinfo_hkKdTreeCinfo();
};
struct S00d094a0_Tree {
    void* m_00; int m_04; int m_08; int m_0c; int m_10; int m_14; int m_18; void* m_1c;
    int total() const { return m_14 + m_18; }
    void hkKdTree_reset(S00d094a0_Desc*);
    S00d094a0_Tree* Init(S00d094a0_Desc*);
};
struct S00d094a0_Shape {
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void f20(); virtual void f24(); virtual void f28(); virtual void f2c();
    virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3c();
    virtual void getAabb(S00d094a0_Vec*, S00d094a0_Vec*);
};
struct S00d094a0_Input { void** m_00; int m_04; };
struct S00d094a0_Ctx {
    int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c;
    int u40; int u44; int u48; int u4c; int u50; int u54;
    S00d094a0_Shape* m_pCollisionShape;
    int u5c; int u60; int u64; int u68; int u6c; int u70; int u74;
    void* m_78;
};
struct S00d094a0_Job;
struct S00d094a0_Queue { void hkJobQueue_addJob(S00d094a0_Job*, int); void hkJobQueue_processAllJobs(); };
struct S00d094a0_Sync {
    virtual void f00(); virtual void f04(); virtual void f08();
    virtual void signal(S00d094a0_Queue*, int); virtual void wait();
};
struct S00d094a0_Helper { int hkSemaphore_acquire(); };
struct S00d094a0_JobHead {
    __declspec(align(16)) char m_00;
    char m_01; char m_02;
    short m_04; short m_06;
    S00d094a0_JobHead() {}
    __forceinline S00d094a0_JobHead(char kind, char sub, short size, char spu)
        : m_00(sub), m_01(kind), m_02(spu), m_04(size), m_06(-1) {}
};
struct S00d094a0_QueryJob : S00d094a0_JobHead {
    void* m_10; int* m_14; int* m_18; void* m_1c;
    S00d094a0_QueryJob() {}
    __forceinline S00d094a0_QueryJob(char sub, short size)
        : S00d094a0_JobHead(3,sub,size,0), m_10(0), m_18(0) {
        m_02=1; m_14=0;
    }
};
struct S00d094a0_DistJob : S00d094a0_QueryJob {
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34;
    int m_38; int m_3c; int m_40;
    S00d094a0_DistJob() {}
    __forceinline S00d094a0_DistJob(int* header) : S00d094a0_QueryJob(3,0x50),m_30(0) { m_14=header; }
};
struct S00d094a0_Job : S00d094a0_DistJob {
    void** m_50;
    S00d094a0_Job() {}
    __forceinline void init(int* header,S00d094a0_Ctx* ctx) { m_06=-1; m_14=header; m_04=0x60; m_1c=ctx->m_78; m_01=3; m_18=0; m_02=1; m_00=6; m_30=0; }
    __forceinline S00d094a0_Job(int* header,S00d094a0_Ctx* ctx) : S00d094a0_DistJob(header) {
        m_00=6; m_04=0x60; m_1c=ctx->m_78;
    }
};
struct __declspec(align(16)) S00d094a0_Build {
    S00d094a0_Desc desc;
    int m_30; int m_uiItemCount; void* m_buf1; void* m_buf2;
    S00d094a0_Job job;
};
struct S00d094a0_Fallback {
    int m_00; int m_04; int m_08;
    void InitWalker(S00d094a0_Input*, S00d094a0_Ctx*);
    int hkpCollidableMediator_getNumPrimitives();
};
void __cdecl hkKdTreeBuildingUtils_completeDistributedBuild(S00d094a0_Tree*, int, void*, void*);
void __cdecl FillAabbArray(S00d094a0_Fallback*, int, int, void*);
void __cdecl DrawIfCountPositive(void**, S00d094a0_Tree*);
struct S00d094a0_Owner {
    int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c;
    void* m_30; void* m_34; int u38; int* m_3c;
    int u40; int u44; int u48; int u4c; int u50; int u54; int u58; int u5c;
    int u60; int u64; int u68;
    S00d094a0_Helper* m_6c;
    void hkpAabbTreeWorldManager_buildKdTree(S00d094a0_Tree** tree, S00d094a0_Input* input, S00d094a0_Ctx* ctx, S00d094a0_Queue* queue, S00d094a0_Sync* sync);
};
inline void* operator new(unsigned int, void* location) { return location; }
struct Target {
    int unk00;
};
struct Item1 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Target m_target;
};
struct Item2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Target m_target;
};
void ResizeAudioStream(void* alloc, void* array, int elemSize);
struct SubStruct1 {
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
    hkArray<Item1*> m_items;
};
struct Container {
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
    hkArray<SubStruct1*> m_array1;
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
    hkArray<Item2*> m_array2;
};
void hkpAabbTreeWorldManager_gatherActiveCollidablesFromWorld(hkArray<Target*>* out, int containerHandle);
extern int DAT_00fdf044;
extern unsigned int DAT_0126835c;
extern char DAT_010cd224;
extern char DAT_010cd154;
extern char DAT_010cd14c;
extern char DAT_010cd140;
extern char DAT_010cd214;
extern char DAT_01076f38;
struct D9bed0Cls {
    void __thiscall UpdateState_00d9bed0();
};
struct D09020Cls {
    void __thiscall hkpAabbTreeWorldManager_buildInactiveTree(int* p, void* a, void* b);
};
struct ActiveTreeBuilder {
    void __thiscall hkpAabbTreeWorldManager_buildActiveTree(void* entries, void* queue, void* pool);
};
struct TreeCleanMarker {
    void __thiscall hkpAabbTreeWorldManager_setTreeIsClean();
};
struct AllocV {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void __thiscall ReleaseBlock(void* p, int bytes);
};
struct EntListSelf {
    int unk00;
    int unk04;
    int unk08;
    D9bed0Cls* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    bool m_enabled;
    int m_28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    hkpEntityD08C** m_entData;
    int m_entSize;
    int m_entCap;

    void __thiscall hkpAabbTreeWorldManager_fullBuild(void* p1, void* p2);
};
static __forceinline void mark16(hkMonitorStream* buf, char* name, char* name2, volatile unsigned int* stampOut)
{
    int* cur = (int*)buf->m_end.m_storage;
    if (cur < (int*)buf->m_capacityMinus16.m_storage) {
        cur[0] = (int)name;
        cur[3] = (int)name2;
        _ReadWriteBarrier();
        *stampOut = (unsigned int)__rdtsc();
        cur[1] = (int)*stampOut;
        buf->m_end.m_storage = (char*)(cur + 4);
    }
}
static __forceinline void mark12(hkMonitorStream* buf, char* name, volatile unsigned int* stampOut)
{
    int* cur = (int*)buf->m_end.m_storage;
    if (cur < (int*)buf->m_capacityMinus16.m_storage) {
        cur[0] = (int)name;
        _ReadWriteBarrier();
        *stampOut = (unsigned int)__rdtsc();
        cur[1] = (int)*stampOut;
        buf->m_end.m_storage = (char*)(cur + 3);
    }
}
namespace RaycasterRework {

class FUN_00d9a040 : public hkpRayCastCollectorBaseD084,
                     public hkpTreeCastCallbackD084 {
public:
    const hkpWorldRayCastInput* m_pRayCastInput;
    const hkpRayCollidableFilter* m_iFilter;
    const hkpRayShapeCollectionFilter* m_shapeFilter;
    hkpWorldRayCastOutput* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    float m_fEarlyOutHitFraction;

    FUN_00d9a040() throw();
};

// @fnv 0x00d9a040
FUN_00d9a040::FUN_00d9a040() throw()
    : m_pRayCastInput(0), m_iFilter(0), m_shapeFilter(0), m_pRayCastOutput(0),
      m_kCollector(0), m_fEarlyOutHitFraction(1.0f)
{
}

}

struct FloatPtr {float* p; FloatPtr(float* q):p(q){} };
#include <xmmintrin.h>
struct Scalar {
 __m128 value;
 Scalar(float f) { value=_mm_load_ss(&f); }
 Scalar(__m128 v) { value=v; }
 __m128 spread() const { return _mm_shuffle_ps(value,value,0); }
 operator float() const { float f;_mm_store_ss(&f,value);return f; }
};
#include "../../../../../../../include/hkVector4.h"
inline void hkVector4::add(const hkVector4& a, const hkVector4& b) { value=_mm_add_ps(a.value,b.value); }
inline void hkVector4::sub(const hkVector4& a, const hkVector4& b) { value=_mm_sub_ps(a.value,b.value); }
inline void hkVector4::scale(const Scalar& s) { value=_mm_mul_ps(s.spread(),value); }

struct Triple { hkVector4 avg,mid,half; };
// hkAabb filled by the shape getAabb slot (min, max); local POD because include/hkAabb.h declares an out-of-line ctor
struct AabbBox { hkVector4 low,high; };
struct Vertex { __m128 value; float unk10; float unk14; };
struct MatrixData {int f00,f04,f08,f0c,f10,f14;int f18,f1c;__m128 a,b,c;};
struct Obj;
struct Engine {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6();
 virtual void getBounds(Transform* transform, float value, AabbBox* out);
 int unk04,unk08,unk0c;
};
struct Obj {Engine* m_eng;int unk04;Transform* m_kMotionTransform;};
struct CollectorState {
 void* unk00;
 Vertex* m_pVertex;
 void* m_arg4;
 void* volatile m_arg7;
 void* m_arg8;
 Obj* m_obj;
 int m_18;
 int unk1c;
 int f20,f24; union { int f28bits; float f28; }; int f2c,f30,f34,f38,f3c;
 __m128 m40,m50,m60,m70;
 float f80,f84;
 float* m_88;
 void __thiscall ComputeValues_00d984b0(int arg1, Obj* arg2, Vertex* arg3, void* arg4, MatrixData* arg5, FloatPtr arg6, void* volatile arg7, void* volatile arg8);
};
extern "C" const __m128 DAT_010ec7f0={1,1,1,1};
extern "C" const float DAT_01016248=0.5f;
inline void hkVector4::interpolate(const hkVector4& a,const hkVector4& b,const Scalar& scale) {
 __m128 weight=scale.spread();
 __m128 opposite=_mm_sub_ps(DAT_010ec7f0,weight);
 value=_mm_add_ps(_mm_mul_ps(opposite,a.value),_mm_mul_ps(b.value,weight));
}
__declspec(noalias) void __cdecl hkKdTreeAabbCastUtils_castAabb(void* output, int arg1, Triple* mid, CollectorState* self, float f);
// @fnv 0x00d984b0
// src: GUESS 0x00d984b0 (confidence: low)
void CollectorState::ComputeValues_00d984b0(int arg1, Obj* arg2, Vertex* arg3, void* arg4, MatrixData* arg5, FloatPtr arg6, void* volatile arg7, void* volatile arg8)
{
    m_arg7=arg7;
    m_arg8=arg8;
    m_arg4=arg4;
    m_pVertex=arg3;
    m_obj=arg2;
    m_18=arg2->m_eng->unk0c;
    f20=arg5->f00; f24=arg5->f04; f28bits=arg5->f08; f2c=arg5->f0c; f30=arg5->f10; f34=arg5->f14;
    m40=arg5->a; m50=arg5->b; m60=arg5->c;
    m_88=arg6.p;
    struct Metrics {float distance,radius;}; Metrics metrics;
    metrics.radius = arg3->unk14;
    hkVector4 diff;
    m70=_mm_sub_ps(arg3->value,arg2->m_kMotionTransform->r[3]);
    diff.set(m70);
    __m128 sq=_mm_mul_ps(m70,m70);
    __m128 y=_mm_shuffle_ps(sq,sq,0x55);
    __m128 z=_mm_shuffle_ps(sq,sq,0xaa);
    __m128 sum;
    sum = _mm_add_ss(z,_mm_add_ss(y,sq));
    __m128 root=_mm_sqrt_ss(sum);
    _mm_store_ss(&metrics.distance,root);f84=metrics.distance;
    AabbBox out;
    f28=metrics.radius;
    arg2->m_eng->getBounds(arg2->m_kMotionTransform,arg3->unk14,&out);

    AabbBox* box=&out;
    Triple temp;
    temp.avg.interpolate(box->low,box->high,Scalar(DAT_01016248));
    temp.mid.add(temp.avg,diff);
    temp.half.sub(box->high,box->low);
    temp.half.scale(Scalar(DAT_01016248));
    f80=arg3->unk10;
    unsigned char result;
    hkKdTreeAabbCastUtils_castAabb(&result,arg1,&temp,this,*arg6.p);
}
