
// src/havok/animation/animation/animation/hkaanimationbindingclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/hkaanimationbindingclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Record;
struct Manager
{
    virtual void unk00();
    virtual void unk04();
    virtual void Notify(Record* record, unsigned short value);
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Manager* manager;
};
Holder* hkMemoryRouter_getInstance();
struct Record
{
    int unk00;
    unsigned short value;
    void ClearReferences();
    Record* FUN_00dfea70(unsigned int flags);
};
// Calls ClearReferences, and if flags has bit 1 set, notifies the manager from FUN_00c85750 with this record and its value; returns this.
// @fnv 0x00dfea70
Record* Record::FUN_00dfea70(unsigned int flags)
{
    ClearReferences();
    if (flags & 1)
    {
        Holder* holder = hkMemoryRouter_getInstance();
        holder->manager->Notify(this, value);
    }
    return this;
}

struct ManagerSlots
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void Notify(Record* record, unsigned int value);
};

struct ReclaimState
{
    void* vptr;         // 0x00
    int unk04;          // 0x04
    int unk08;          // 0x08 (sub-object head, passed as this to FUN_00cb0c00)
    void* unk0c;        // 0x0c
    int unk10;          // 0x10
    int unk14;          // 0x14
    int unk18;          // 0x18
    Record* m_1c;       // 0x1c
    int m_20;           // 0x20
    unsigned int m_24;  // 0x24
};

extern char DAT_0102e388;
struct CalleeA
{
    void FUN_00c905b0();
};
struct CalleeB
{
    void Object_UpdateFields_00cb0c00();
};

// @fnv 0x00dfe9e0
void Record::ClearReferences()
{
    ReclaimState* pState = reinterpret_cast<ReclaimState*>(this);
    Holder* pManagerHolder = hkMemoryRouter_getInstance();
    ManagerSlots* pManager = reinterpret_cast<ManagerSlots*>(pManagerHolder->manager);
    pState->m_20 = 0;
    if ((pState->m_24 & 0x80000000u) == 0)
    {
        pManager->Notify(pState->m_1c, (pState->m_24 & 0x3fffffffu) * 2);
    }
    pState->m_1c = 0;
    pState->m_24 = 0x80000000u;

    pManagerHolder = hkMemoryRouter_getInstance();
    pManager = reinterpret_cast<ManagerSlots*>(pManagerHolder->manager);
    pState->unk14 = 0;
    if ((pState->unk18 & 0x80000000u) == 0)
    {
        pManager->Notify(reinterpret_cast<Record*>(pState->unk10), (pState->unk18 & 0x3fffffffu) * 2);
    }
    *(int volatile*)&pState->unk10 = 0;
    *(unsigned int volatile*)&pState->unk18 = 0x80000000u;

    void* p = *(void* volatile*)&pState->unk0c;
    if (p != 0)
    {
        reinterpret_cast<CalleeA*>(p)->FUN_00c905b0();
    }
    pState->unk0c = 0;
    reinterpret_cast<CalleeB*>(&pState->unk08)->Object_UpdateFields_00cb0c00();
    pState->vptr = (void*)&DAT_0102e388;
}
