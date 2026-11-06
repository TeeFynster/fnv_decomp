
// src/havok/physics/dynamics/constraint/chain/hkpconstraintchaininstanceaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hkpconstraintchaininstanceaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkpConstraintChainInstance.h"
#include "../../../../../../include/hkpConstraintChainInstanceAction.h"

// @fnv 0x00e063e0
void __fastcall FUN_00e063e0(hkpConstraintChainInstanceAction* self, void* unusedEdx, int arg0)
{
    self->m_pConstraintChainInstance->vf04((void*)arg0);
}

// @fnv 0x00e063c0
void __stdcall FUN_00e063c0(int)
{}

// @fnv 0x00e063d0
int __stdcall FUN_00e063d0(int arg0, int arg1)
{
    return 0;
}

struct FnvAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* AllocateMemoryBlock(int* bytes);
    virtual void ReleaseBlock(void* ptr, int bytes);
};
struct FnvMemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FnvAllocator* allocator;
};
extern "C" FnvMemoryRouter* __cdecl FUN_00c85750();
// @fnv 0x00e063f0
void __fastcall CopyEntityArray(hkpConstraintChainInstanceAction* self, void* unusedEdx, hkArray<hkpEntity*>* output)
{
    hkArray<hkpEntity*>* source = &self->m_pConstraintChainInstance->m_ppRigidBodies;
    FnvAllocator* allocator = FUN_00c85750()->allocator;
    int capacity = output->m_iCapacityState & 0x3fffffff;
    if (capacity < source->m_iElementCount)
    {
        if (!(output->m_iCapacityState & 0x80000000))
            allocator->ReleaseBlock(output->m_data, capacity * 4);
        int bytes = source->m_iElementCount * 4;
        output->m_data = (hkpEntity**)allocator->AllocateMemoryBlock(&bytes);
        output->m_iCapacityState = bytes / 4;
    }
    int count = source->m_iElementCount;
    output->m_iElementCount = count;
    hkpEntity** dest = output->m_data;
    hkpEntity** from = source->m_data;
    for (int i = 0; i < count; ++i)
        dest[i] = from[i];
}
