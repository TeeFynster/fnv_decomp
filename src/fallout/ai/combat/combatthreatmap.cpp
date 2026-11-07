// fallout/ai/combat/combatthreatmap.cpp: LocalCombatThreatMap, DelStandIn, ThreatMap (8 functions)

#include "../../../../include/NiTPointerMap.h"
#include "combatthreatmap_ctor_decls.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/MagicProjectile.h"

// Iterates the map's entries, calls LoadGame on each threat, and deletes and removes entries whose TESForm pointer is null.
// @fnv 0x009a5c40
void LocalCombatThreatMap::ApplyLoadBuffer(BGSLoadGameBuffer* buffer)
{
    // A traversal cursor keeps its current key and continuation together.
    // Both are real values consumed by GetNext; there is no emulated frame.
    struct ThreatCursor
    {
        unsigned int key;
        void* position;
    } cursor;
    cursor.position = map.GetFirstPos();
    while (cursor.position)
    {
        CombatThreatRecord_combatthreatmap_ctor_decls* threat = 0;
        map.GetNext(cursor.position, cursor.key, threat);
        if (threat)
        {
            threat->LoadGame(buffer);
            if (!static_cast<TESForm*>(*reinterpret_cast<NiPointer<TESForm>*>(threat)))
            {
                delete threat;
                map.RemoveAt(cursor.key);
            }
        }
    }
}

// Constructs a LocalCombatThreatMap: initializes the base, stamp, mode and object, then calls InitThreatObjects.
// @fnv 0x00991080
LocalCombatThreatMap::LocalCombatThreatMap() : FUN_00993960(0, 1), stamp(-DAT_0108d9b0), mode(1), object(0)
{
    InitThreatObjects();
}

void __fastcall DeleteAllEntries(void*);

struct FUN_009a5df0
{
    virtual void dummy();
    ~FUN_009a5df0();
};

struct FUN_009a5050 : FUN_009a5df0
{
    ~FUN_009a5050();
};

// Destructor that forwards to DeleteAllEntries with this as the argument.
// @fnv 0x009a5050
FUN_009a5050::~FUN_009a5050()
{
    DeleteAllEntries(this);
}

struct FUN_009a5cd0_cls
{
    void* GetFirstPos();
    void ProcessAllProjectiles(int dt);
};
// Iterates the map and calls Process(dt) on each non-null MagicProjectile value.
// @fnv 0x009a5cd0
void FUN_009a5cd0_cls::ProcessAllProjectiles(int aiDeltaTime)
{
    MagicProjectile* p;
    unsigned int id;
    void* it = GetFirstPos();
    while (it)
    {
        p = 0;
        ((NiTPointerMap<unsigned int, void*>*)this)->GetNext(it, id, (void*&)p);
        if (p)
            p->Process(aiDeltaTime);
    }
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009a5020
void* DelStandIn::DestroyIfFlagged(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct NiBound;
extern NiBound DAT_011f4288;
struct FUN_0043d450_Owner
{
    NiBound* NiAVObject_GetWorldBound();
};
// Returns the bound stored at offset 0x20 of this object, or the global DAT_011f4288 when that pointer is null.
// @fnv 0x0043d450
// src: XBOX_PDB 0x0043d450
NiBound* FUN_0043d450_Owner::NiAVObject_GetWorldBound()
{
    NiBound* pBound = ((NiBound**)this)[8] ? ((NiBound**)this)[8] : &DAT_011f4288;
    return pBound;
}

struct KFModel;

struct Animation
{
    bool AddAnimation(KFModel*, bool);
};

struct Flt
{
    int pad;
    operator unsigned int();
};

struct FUN_00497c10_struct
{
    char pad0[8];
    unsigned int field_08;
    unsigned int field_0C;
    Flt field_10;
    unsigned int field_14;

    void LoadAnimationData(BGSLoadFormBuffer* buffer, Animation* anim);
};

// Reads three 4-byte fields from the buffer, defaults field_08 to 1 when zero, and adds an animation when field_08 is 2 and field_10 is nonzero.
// @fnv 0x00497c10
void FUN_00497c10_struct::LoadAnimationData(BGSLoadFormBuffer* buffer, Animation* anim)
{
    buffer->ReadTypedData(static_cast<void*>(&field_08), 4u);
    buffer->ReadTypedData(static_cast<void*>(&field_0C), 4u);
    buffer->ReadTypedData(static_cast<void*>(&field_14), 4u);
    if (field_08 == 0)
    {
        field_08 = 1;
    }
    if (field_08 == 2 && (unsigned int)field_10)
    {
        anim->AddAnimation((KFModel*)(unsigned int)field_10, false);
    }
}

struct Threat
{
    CombatTargetTimestamp GetStamp();
    float Evaluate(const NiPoint3& pos, int arg, float time, float a, float b);
};
struct ThreatLock
{
    void Lock();
    void Unlock();
};
extern double DAT_01012060;
float __cdecl CombatTimer_GetTimer();

struct ThreatMap
{
    int vtable;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    ThreatLock lock;
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& key, Threat*& val);
    float EvaluateThreats(NiPoint3 pos, int arg, float delay, float a, CombatTargetTimestamp since, float b);
};

// Locks the map, sums each threat's Evaluate result for threats newer than since, clamps the total to 1.0, unlocks and returns it.
// @fnv 0x009a5670
float ThreatMap::EvaluateThreats(NiPoint3 pos, int arg, float delay, float a, CombatTargetTimestamp since, float b)
{
    lock.Lock();
    float fTotal = 0;
    float fTime = 0;
    if (delay < DAT_01012060)
        fTime = delay;
    else
        fTime = CombatTimer_GetTimer() + delay;
    void* iter = GetFirstPos();
    while (iter)
    {
        unsigned int key = 0;
        Threat* threat3 = 0;
        GetNext(iter, key, threat3);
        if (threat3->GetStamp().DisplayElapsedTime() <= since.DisplayElapsedTime())
            continue;
        float fValue = threat3->Evaluate(pos, arg, fTime, a, b);
        fTotal += fValue;
        if (fTotal > 1.0)
        {
            fTotal = 1.0f;
            break;
        }
    }
    lock.Unlock();
    return fTotal;
}
