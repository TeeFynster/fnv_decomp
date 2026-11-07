
// src/havok/physics/utilities/charactercontrol/statemachine/hkpcharacterstatemanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/statemachine/hkpcharacterstatemanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkReferencedObject.h"

struct hkpCharacterStateManager
{
    int m_auiShapeKeys[2];
    hkReferencedObject* m_states[32];
    void registerState(hkReferencedObject* object, int index);
};

// @fnv 0x00cbc4e0
// src: HAVOK_LIB 0x00cbc4e0
void hkpCharacterStateManager::registerState(hkReferencedObject* object, int index)
{
    object->addReference();
    if (m_states[index])
        m_states[index]->removeReference();
    m_states[index] = object;
}

extern int DAT_010c9194;
extern int _DAT_0102e388;

struct FUN_00cbc4a0
{
    int* m_ppVirtualMethodTable;
    int m_auiShapeKeys;
    hkReferencedObject* m_states[11];

    ~FUN_00cbc4a0();
};

// @fnv 0x00cbc4a0
FUN_00cbc4a0::~FUN_00cbc4a0()
{
    m_ppVirtualMethodTable = reinterpret_cast<int*>(&DAT_010c9194);

    for (int i = 0; i < 11; ++i)
    {
        hkReferencedObject* state = m_states[i];
        if (state)
        {
            state->removeReference();
            m_states[i] = 0;
        }
    }

    m_ppVirtualMethodTable = reinterpret_cast<int*>(&_DAT_0102e388);
}

// 0x00cbc510 is the manager lookup bound by hkpcharactercontext.cpp: a pointer table at +0x08, not a character state.
struct CharacterStateSlotTable
{
    int m_auiShapeKeys[2];
    hkReferencedObject* m_states[32];
    hkReferencedObject* GetIndexedValue_00cbc510(int index);
};

// @fnv 0x00cbc510
// src: GUESS 0x00cbc510 (confidence: low)
hkReferencedObject* CharacterStateSlotTable::GetIndexedValue_00cbc510(int index)
{
    return m_states[index];
}

struct FnvCpu_FUN_00cbc520_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cbc520_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cbc520_CpuAllocator* allocator;
};
FnvCpu_FUN_00cbc520_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00cbc520_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00cbc4a0();
    FnvCpu_FUN_00cbc520_CpuObject* FUN_00cbc520(unsigned int flags);
};
// @fnv 0x00cbc520
FnvCpu_FUN_00cbc520_CpuObject* FnvCpu_FUN_00cbc520_CpuObject::FUN_00cbc520(unsigned int flags)
{
    FUN_00cbc4a0();
    if (flags & 1)
    {
        FnvCpu_FUN_00cbc520_CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
