// fallout/ai/combat/combattargetmap.cpp: CombatTargetMap, DelStandIn (7 functions)

#include "combattargetmap_decls.h"
#include "../../../../include/BGSSaveLoadChangesMap.h"
#include "../../../../include/BGSReconstructFormsInAllFilesMap.h"
#include "../../../../include/CombatTargetMap.h"
#include "../../../../include/Actor.h"
#include "../../../../include/AutoMemHelper.h"
// CombatThreatRecord_combattargetmap: local type (was include/CombatThreatRecord.h, which had no evidence of one real class); its methods are 0x009a4f40 SandBoxChoiceListItem::InitLoadGame, 0x009a5170 CombatThreat::IsExpired, 0x009a5e50 NiTMapBase<DFALL<NiTMapItem<unsigned int,CombatThreat *> >,unsigned int,CombatThreat *>::~NiTMapBase<DFALL<NiTMapItem<unsigned int,CombatThreat *> >,unsigned int,CombatThreat *>
class BGSLoadGameBuffer;

class CombatThreatRecord_combattargetmap
{
public:
    void* vfn_00;
    int pad_04;
    void* p_08;

    ~CombatThreatRecord_combattargetmap();
    bool IsXLessThan(float);
    void LoadGame(BGSLoadGameBuffer*);
    void __thiscall SetVtableAndProcessState_009a5e50();
};
#include "../../../../include/DummyPointerMap.h"
#include "../../../../include/GO.h"
// Locks the map, iterates every entry, and deletes threats whose IsXLessThan(time) check passes, removing them by key.
// @fnv 0x009a50b0
void CombatTargetMap::ResetTargetMap()
{
    void* pIterPos = ((BGSReconstructFormsInAllFilesMap*)this)->GetFirstPos();
    if (pIterPos)
    {
        ((CombatTargetMapLock*)((char*)this + 0x10))->AcquireLock();
        float time = Actor::GetActorScale();
        while (pIterPos)
        {
            unsigned int key = 0;
            CombatThreatRecord_combattargetmap* threat = 0;
            ((BGSReconstructFormsInAllFilesMap*)this)
                ->GetNext(pIterPos, (TESFile*&)key, (BGSReconstructFormsInFileMap*&)threat);
            if (threat && threat->IsXLessThan(time))
            {
                delete threat;
                ((BGSSaveLoadChangesMap*)this)->RemoveAt(key);
            }
        }
        ((CombatTargetMapLock*)((char*)this + 0x10))->BSReadWriteLock_UnlockWrite();
    }
}

struct _Node_006f99e0
{
    int a, b, c;
};

// @fnv 0x006f99e0
// src: COMMUNITY 0x006f99e0
void* __fastcall ImpactImpactMap_NewItem(void* _this)
{
    return new _Node_006f99e0;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_009a3ec0(unsigned int flags);
};
// Runs the destructor, then frees this object when flags has bit 0 set, and returns this.
// @fnv 0x009a3ec0
void* DelStandIn::FUN_009a3ec0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

void __cdecl _Deallocate(void*);
struct FUN_009a3fb0_shell
{
    void FUN_009a3db0();
    void* FUN_009a3fb0(unsigned int);
};
// Calls FUN_009a3db0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x009a3fb0
void* FUN_009a3fb0_shell::FUN_009a3fb0(unsigned int flags)
{
    FUN_009a3db0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_009a42f0
{
    int _pad[4];
    FUN_009a42f0(int, int);
    ~FUN_009a42f0();
};
struct FUN_009a40c0 : FUN_009a42f0
{
    GO m;
    FUN_009a40c0();
};
// Initializes the FUN_009a42f0 base with (5, 0) and constructs member m with 0.
// @fnv 0x009a40c0
FUN_009a40c0::FUN_009a40c0() : FUN_009a42f0(5, 0), m(0)
{}

namespace fnv_009a3fe0 {
void* __cdecl operator new(unsigned int);

// Unit-local view of BSSimpleArray for 0x009a3fe0 (namespace fnv_009a3fe0): built on the shared BSSimpleArray, that code does not compile or does not match.
template <typename T, int N> struct BSSimpleArray_009a3fe0
{
    unsigned int Add(T&);
};

struct FUN_009a40c0 : BSSimpleArray_009a3fe0<void*, 1024>
{
    char pad[0x14];
    FUN_009a40c0();
};

struct FUN_009a3fe0_struct : DummyPointerMap
{
    void AddAttackerToTarget(void* apTarget, void* apAttacker);
};

extern const char str_0108e208[];

// Looks up or creates a per-target data array and adds the attacker pointer to it.
// @fnv 0x009a3fe0
void FUN_009a3fe0_struct::AddAttackerToTarget(void* apTarget, void* apAttacker)
{
    FUN_009a40c0* ptargetData;
    AutoMemHelper tempMemContext(0x2b, true, str_0108e208, 0x7c);
    ptargetData = 0;
    if (!GetAt((unsigned int)apTarget, (unsigned int&)ptargetData))
    {
        ptargetData = new FUN_009a40c0;
        SetAt((unsigned int)apTarget, (unsigned int)ptargetData);
    }
    ptargetData->Add(apAttacker);
}
}  // namespace fnv_009a3fe0

extern void* DAT_0108e1e8;

struct ActorCombatTargetData;

struct MyMap
{
    void RemoveAll();
};

struct FUN_009a4420
{
    virtual void dummy();
    ~FUN_009a4420();
};

struct FUN_009a3ef0 : public FUN_009a4420
{
    ~FUN_009a3ef0();
};

// Destructor that iterates the map, calls FUN_009a3fb0 on each BGSReconstructFormsInFileMap value, then calls RemoveAll.
// @fnv 0x009a3ef0
FUN_009a3ef0::~FUN_009a3ef0()
{
    void* it = ((BGSReconstructFormsInAllFilesMap*)this)->GetFirstPos();
    while (it)
    {
        Actor* ptarget = 0;
        ActorCombatTargetData* ptargetData = 0;
        ((BGSReconstructFormsInAllFilesMap*)this)
            ->GetNext(it, (TESFile*&)ptarget, (BGSReconstructFormsInFileMap*&)ptargetData);
        {
            ActorCombatTargetData* t1 = ptargetData;
            ActorCombatTargetData* t2 = t1;
            t2 ? ((FUN_009a3fb0_shell*)t2)->FUN_009a3fb0(1) : 0;
        }
    }
    ((MyMap*)this)->RemoveAll();
}
