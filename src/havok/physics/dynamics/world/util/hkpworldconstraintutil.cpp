#include "../../../../../../include/hkpConstraintOwner.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkpConstraintAtom.h"
#include "../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../include/hkpConstraintData.h"
#include "../../../../../../include/hkpModifierConstraintAtom.h"

// src/havok/physics/dynamics/world/util/hkpworldconstraintutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldconstraintutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d27820_Node;
struct S_00d27820_Buf
{
    char* data;
    int size;
};
struct S_00d27820_Rec
{
    hkpConstraintInstance* constraint;
    S_00d27820_Node* bodies[2];
    int unk0c, unk10;
    unsigned short px, py, pz;
    unsigned char idx;
    int cnt;
    unsigned short sz;
    unsigned short slot;
    int unk24, unk28, unk2c;
};
struct S_00d27820_Arr
{
    struct S_00d27820_Node** data;
    int count;
};
struct S_00d27820_Node
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    S_00d27820_Rec* unk30;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    S_00d27820_Rec* unkac;
    unsigned short unkb0;
    unsigned short unkb2;
    S_00d27820_Arr arr;
    int unkbc;
    S_00d27820_Buf buf;
};
struct S_00d27820_Vec
{
    int unk00, x, y, z;
    S_00d27820_Vec& Sub(unsigned a, unsigned b, unsigned c)
    {
        x -= a;
        y -= b;
        z -= c;
        return *this;
    }
};
struct S_00d27820_A
{
    int unk00, unk04;
    S_00d27820_Vec vec;
    int unk18;
    int cnt;
    int unk20;
    unsigned char unk24;
    unsigned char flags;
};
void __cdecl hkString_memMove(int a, int b, char* c);

// Removes the record p->m_pConstraintInternal from its node lists, shifts the following records down, adjusts buffer sizes and counts, and calls FUN_00c905b0.
// @fnv 0x00d27820
void DetachRecord(hkpConstraintInstance* p)
{
    S_00d27820_Rec* pRec = reinterpret_cast<S_00d27820_Rec*>(p->m_pConstraintInternal);
    S_00d27820_A* a = reinterpret_cast<S_00d27820_A*>(p->m_pOwnerObject);
    a->flags = (a->flags & ~2) | 1;
    unsigned x = pRec->px;
    unsigned y = pRec->py;
    unsigned z = pRec->pz;
    if (p->m_pConstraintInternal)
    {
        S_00d27820_A* a2 = reinterpret_cast<S_00d27820_A*>(p->m_pOwnerObject);
        a2->vec.Sub(x, y, z);
        S_00d27820_Rec* pRec2 = reinterpret_cast<S_00d27820_Rec*>(p->m_pConstraintInternal);
        pRec2->py -= y;
        pRec2->pz -= z;
        pRec2->px -= x;
    }
    a->cnt--;
    p->m_pOwnerObject = 0;
    S_00d27820_Node* c = pRec->bodies[1 - pRec->idx];
    unsigned short slot = pRec->slot;
    S_00d27820_Arr* arr = &c->arr;
    S_00d27820_Node** data = arr->data;
    S_00d27820_Node* pLastNode = data[arr->count - 1];
    data[slot] = pLastNode;
    arr->count--;
    pLastNode->unk30->slot = slot;
    S_00d27820_Node* d = pRec->bodies[pRec->idx];
    int delta = 0;
    if (pRec->cnt)
    {
        delta = -(int)pRec->sz;
        int iTotal = pRec->sz + pRec->cnt;
        S_00d27820_Buf* pBuf = &d->buf;
        hkString_memMove(pRec->cnt, iTotal, pBuf->data + (pBuf->size - iTotal));
        pBuf->size -= pRec->sz;
        pRec->cnt = 0;
    }
    p->m_pConstraintInternal = 0;
    S_00d27820_Rec* pIter = pRec;
    S_00d27820_Rec* end = d->unkac + d->unkb0 - 1;
    while (pIter < end)
    {
        *pIter = pIter[1];
        pIter->constraint->m_pConstraintInternal = reinterpret_cast<ConstraintRuntimeInfo*>(pIter);
        pIter->cnt = pIter->cnt ? pIter->cnt + delta : 0;
        pIter++;
    }
    d->unkb0--;
    p->removeReference();
}

typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;


struct GenericConstraintAtomScheme
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;

    void clear()
    {
        m_iMaxSchemaSize = 0;
        m_iSchemaByteSize = 0;
        m_iSolverResultCount = 0;
        m_iSolverElementTemporaryCount = 0;
    }
};

struct hkpConstraintDataInfo : GenericConstraintAtomScheme
{
    hkpConstraintAtom* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};




struct ConstraintRuntimeInfo
{
    int unk00;
    int unk04;
    int unk08;
    hkpConstraintAtom* m_kBridgeAtoms;
    hkUint16 m_iAtomsSize;
    hkUint8 m_ucCallbackRequest;
    hkUint8 unk13;
    hkUint16 m_iSchemaByteSize;
};



extern const hkUint16 DAT_010cb7a8[];

hkpModifierConstraintAtom* __cdecl hkpWorldConstraintUtil_findLastModifier(hkpConstraintInstance* instance);

// Splices newModifier into the modifier atom chain of instance, updating child pointers and accumulating solver stats on the owner.
// @fnv 0x00d27960
// src: HAVOK_LIB 0x00d27960
void __cdecl hkpWorldConstraintUtil_addModifier(hkpConstraintInstance* instance, hkpConstraintOwner& constraintOwner,
                          hkpModifierConstraintAtom* newModifier)
{
    constraintOwner.checkAccessRw();

    hkpModifierConstraintAtom* lastModifier = hkpWorldConstraintUtil_findLastModifier(instance);
    ConstraintRuntimeInfo* pConstraintInternal = instance->m_pConstraintInternal;

    if (newModifier->m_type == 0x1a && lastModifier)
    {
        newModifier->m_pChildAtom = lastModifier->m_pChildAtom;
        newModifier->m_iChildSize = lastModifier->m_iChildSize;
        lastModifier->m_pChildAtom = newModifier;
        lastModifier->m_iChildSize = newModifier->m_usModifierAtomSize;
    }
    else if (instance->m_pConstraintModifier && instance->m_pConstraintModifier->m_type == 0x1b)
    {
        newModifier->m_pChildAtom = instance->m_pConstraintModifier->m_pChildAtom;
        newModifier->m_iChildSize = instance->m_pConstraintModifier->m_iChildSize;
        instance->m_pConstraintModifier->m_pChildAtom = newModifier;
        instance->m_pConstraintModifier->m_iChildSize = newModifier->m_usModifierAtomSize;
    }
    else
    {
        instance->m_pConstraintModifier = newModifier;
        if (pConstraintInternal)
        {
            newModifier->m_pChildAtom = reinterpret_cast<hkpModifierConstraintAtom*>(pConstraintInternal->m_kBridgeAtoms);
            newModifier->m_iChildSize = pConstraintInternal->m_iAtomsSize;
            pConstraintInternal->m_kBridgeAtoms = reinterpret_cast<hkpConstraintAtom*>(newModifier);
            pConstraintInternal->m_iAtomsSize = newModifier->m_usModifierAtomSize;
        }
        else
        {
            hkpConstraintDataInfo info;
            instance->m_data->PopulateInfo(info);
            newModifier->m_pChildAtom = reinterpret_cast<hkpModifierConstraintAtom*>(info.m_kBridgeAtoms);
            newModifier->m_iChildSize = (hkUint16)info.m_usSizeOfAllAtoms;
        }
    }

    if (pConstraintInternal)
    {
        GenericConstraintAtomScheme info;
        info.clear();
        hkUint8 usedFlags = 0;
        int callbackRequest = newModifier->addModifierDataToConstraintInfo(info, usedFlags);
        constraintOwner.AccumulateStats(instance, info);

        usedFlags &=
            (instance->m_kActorEntries[0]->m_ucResponseModifierFlags | instance->m_kActorEntries[1]->m_ucResponseModifierFlags);
        hkUint16 extra = DAT_010cb7a8[usedFlags & 7];
        reinterpret_cast<GenericConstraintAtomScheme*>(&constraintOwner.m_iMaxSchemaSize)->m_iSchemaByteSize -= extra;
        instance->m_pConstraintInternal->m_iSchemaByteSize = instance->m_pConstraintInternal->m_iSchemaByteSize - extra;
        if (instance->m_pConstraintInternal)
        {
            instance->m_pConstraintInternal->m_ucCallbackRequest |= (hkUint8)callbackRequest;
        }
    }
}

namespace fnv_00d27ac0 {
struct Entity;
struct ConstraintInfo
{
    unsigned int unk00;
    unsigned int runtimeBytes;
    unsigned int unk08, unk0c;
    hkpConstraintAtom* atoms;
    unsigned short atomSize;
};
struct RuntimeInfo
{
    unsigned int size;
    unsigned int unk04;
};
struct __declspec(align(16)) ConstraintInternal
{
    hkpConstraintInstance* constraint;
    Entity* bodies[2];
    hkpConstraintAtom* atoms;
    unsigned short atomSize;
    unsigned char flags;
    unsigned char priority;
    unsigned short unk14, unk16, unk18;
    unsigned char masterIndex;
    unsigned char callbacks;
    char* runtime;
    unsigned short runtimeSize;
    unsigned short slaveIndex;
    unsigned int unk24, unk28, unk2c;
};
struct InternalArray
{
    ConstraintInternal* data;
    unsigned short size;
    unsigned short capacity;
    void hkSmallArray_hkConstraintInternal_insertAt(int, ConstraintInternal*);
};
struct ConstraintPointer
{
    hkpConstraintInstance* value;
    __forceinline void Set(hkpConstraintInstance* x)
    {
        value = x;
    }
};
struct ConstraintArray
{
    ConstraintPointer* data;
    int size;
    unsigned int capacity;
};
struct ByteArray
{
    char* data;
    unsigned int size;
    unsigned int capacity;
};
struct Island
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, count;
    void AccumulateStats(hkpConstraintInstance*, ConstraintInfo*);
};
struct Entity
{
    unsigned int unk00;
    unsigned int unk04;
    void* world;
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    InternalArray constraints;
    ConstraintArray slaves;
    ByteArray runtime;
    Island* island;
    unsigned short unkD0;
    unsigned char responseFlags;
    unsigned char unkD3;
    unsigned int uid;
    unsigned int unkD8, unkDC, unkE0, unkE4;
    unsigned char motionType;
};
void hkpWorldOperationUtil_mergeIslands(void*, Entity*, Entity*);
unsigned char hkpModifierConstraintAtom_addAllModifierDataToConstraintInfo(hkpConstraintAtom*, ConstraintInfo*, unsigned char*);
extern unsigned short DAT_010cb7a8[];
void hkArrayUtil__reserve(void*, ByteArray*, int, int);
void ResizeAudioStream(void*, ConstraintArray*, int);
void hkString_memMove(void*, const void*, int);
// Initializes a ConstraintInternal entry, inserts it into the master entity's constraint array, allocates runtime memory, and registers the constraint as a slave.
// @fnv 0x00d27ac0
// src: HAVOK_LIB 0x00d27ac0
ConstraintPointer* hkpWorldConstraintUtil_addConstraint(void* unused, hkpConstraintInstance* constraint)
{
    constraint->addReference();
    ConstraintInfo info;
    constraint->m_data->PopulateInfo(reinterpret_cast<hkpConstraintDataInfo&>(info));
    ConstraintInternal entry;
    entry.constraint = constraint;
    entry.bodies[0] = reinterpret_cast<Entity*>(constraint->m_kActorEntries[0]);
    entry.bodies[1] = reinterpret_cast<Entity*>(constraint->m_kActorEntries[1]);
    if (constraint->m_pConstraintModifier)
    {
        entry.atoms = reinterpret_cast<hkpConstraintAtom*>(constraint->m_pConstraintModifier);
        entry.atomSize = constraint->m_pConstraintModifier->m_usModifierAtomSize;
    }
    else
    {
        entry.atoms = info.atoms;
        entry.atomSize = info.atomSize;
    }
    entry.priority = constraint->m_priority;
    if (entry.bodies[0]->motionType != 5 && entry.bodies[1]->motionType != 5 &&
        entry.bodies[0]->island != entry.bodies[1]->island)
        hkpWorldOperationUtil_mergeIslands(entry.bodies[0]->world, entry.bodies[0], entry.bodies[1]);
    entry.masterIndex = entry.bodies[0]->motionType == 5;
    Entity* master = entry.bodies[entry.masterIndex];
    constraint->m_pOwnerObject = reinterpret_cast<hkpConstraintOwner*>(master->island);
    ++reinterpret_cast<Island*>(constraint->m_pOwnerObject)->count;
    unsigned int atomType = entry.atoms->m_type;
    entry.callbacks = 1;
    entry.flags = 0;
    if (atomType == 1)
    {
        entry.flags = 2;
        unsigned char result;
        if (*constraint->m_data->WantsRuntime(&result))
            entry.flags |= 4;
        entry.callbacks = constraint->vf06() == 0;
    }
    else if (atomType == 20)
        entry.flags = 2;
    unsigned char flags = 0;
    if (constraint->m_pConstraintModifier)
        entry.flags |= hkpModifierConstraintAtom_addAllModifierDataToConstraintInfo(reinterpret_cast<hkpConstraintAtom*>(constraint->m_pConstraintModifier), &info, &flags);
    if (atomType == 22)
    {
        unsigned char combined = constraint->m_kActorEntries[1]->m_ucResponseModifierFlags | constraint->m_kActorEntries[0]->m_ucResponseModifierFlags;
        combined -= combined & flags;
        info.runtimeBytes += DAT_010cb7a8[combined & 7];
    }
    entry.unk16 = 0;
    entry.unk18 = 0;
    entry.unk14 = 0;
    constraint->m_pConstraintInternal = reinterpret_cast<ConstraintRuntimeInfo*>(&entry);
    reinterpret_cast<Island*>(constraint->m_pOwnerObject)->AccumulateStats(constraint, &info);
    InternalArray& array = master->constraints;
    unsigned short count = array.size;
    int index = 0;
    for (; index < (int)count; ++index)
    {
        ConstraintInternal& current = array.data[index];
        if (entry.priority < current.priority)
            break;
        if (entry.priority > current.priority)
            continue;
        unsigned int incomingUid = entry.constraint->m_uiUniqueId;
        unsigned int currentUid = current.constraint->m_uiUniqueId;
        if (incomingUid < currentUid)
            break;
        if (incomingUid > currentUid)
            continue;
        Entity* other =
            (Entity*)((unsigned int)current.bodies[0] ^ (unsigned int)current.bodies[1] ^ (unsigned int)master);
        Entity* incoming =
            (Entity*)((unsigned int)entry.bodies[0] ^ (unsigned int)entry.bodies[1] ^ (unsigned int)master);
        if (incoming->uid < other->uid)
            break;
    }
    int firstChanged = count < (array.capacity & 0x3fff) ? index : 0;
    array.hkSmallArray_hkConstraintInternal_insertAt(index, &entry);
    for (int i = firstChanged; i < (int)array.size; ++i)
    {
        ConstraintInternal* changed = &array.data[i];
        hkpConstraintInstance* owner = changed->constraint;
        owner->m_pConstraintInternal = reinterpret_cast<ConstraintRuntimeInfo*>(changed);
    }
    ConstraintInternal* internal = reinterpret_cast<ConstraintInternal*>(constraint->m_pConstraintInternal);
    RuntimeInfo runtimeInfo;
    internal->constraint->m_data->GetRuntimeInfo((unsigned char)constraint->m_bWantRuntime.m_cBooleanValue, &runtimeInfo);
    unsigned int runtimeSize = (runtimeInfo.size + 15) & ~15u;
    runtimeInfo.size = runtimeSize;
    internal->runtimeSize = (unsigned short)runtimeSize;
    if (runtimeSize)
    {
        ByteArray& storage = master->runtime;
        int oldSize = storage.size;
        char* oldData = storage.data;
        int newSize = oldSize + runtimeSize;
        hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
        if ((int)(storage.capacity & 0x3fffffff) < newSize)
            hkArrayUtil__reserve(router->m_heap, &storage, newSize, 1);
        storage.size = oldSize + runtimeInfo.size;
        char* position = storage.data;
        int displacement = storage.data - oldData;
        int i = 0;
        for (; i < index; ++i)
        {
            ConstraintInternal& current = array.data[i];
            if (current.runtime)
            {
                current.runtime += displacement;
                position = current.runtime + current.runtimeSize;
            }
        }
        int tailSize = (int)storage.size - (int)(position + internal->runtimeSize - master->runtime.data);
        hkString_memMove(position + internal->runtimeSize, position, tailSize);
        displacement += internal->runtimeSize;
        internal->runtime = position;
        for (++i; i < (int)array.size; ++i)
        {
            ConstraintInternal& current = array.data[i];
            char* oldRuntime = current.runtime;
            current.runtime = oldRuntime ? oldRuntime + displacement : 0;
        }
    }
    else
        internal->runtime = 0;
    hkpConstraintData* instanceData = internal->constraint->m_data;
    instanceData->AddInstance(constraint, internal->runtime, internal->runtimeSize);
    Entity* slave = internal->bodies[1 - internal->masterIndex];
    internal->slaveIndex = (unsigned short)slave->slaves.size;
    ConstraintArray& slaves = slave->slaves;
    hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
    if (slaves.size == (int)(slaves.capacity & 0x3fffffff))
        ResizeAudioStream(router->m_heap, &slaves, 4);
    ConstraintPointer* insertion = slaves.data + slaves.size;
    insertion->value = constraint;
    ++slaves.size;
    return insertion;
}
}  // namespace fnv_00d27ac0
