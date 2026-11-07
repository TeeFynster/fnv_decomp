
// src/havok/common/serialize/util/hkstaticclassnameregistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkstaticclassnameregistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct SlotEntry
{
    int unk00;
    SlotEntry* Key();
};

int __cdecl MatchSlotKey(void* p, SlotEntry* key);

struct FUN_00db7ae0_cls
{
    int unk00;
    int unk04;
    int unk08;
    SlotEntry** m_slots;

    void ResetSlots();
    SlotEntry* FindSlotByKey(void* p);
};

// Resets the slot table, then scans m_slots for the first entry whose Key matches p via MatchSlotKey and returns it, or 0 if none match.
// @fnv 0x00db7ae0
SlotEntry* FUN_00db7ae0_cls::FindSlotByKey(void* apKey)
{
    ResetSlots();
    int i = 0;
    if (m_slots[i] != 0)
    {
        do
        {
            SlotEntry* key = m_slots[i]->Key();
            if (MatchSlotKey(apKey, key) == 0)
            {
                return m_slots[i];
            }
            i++;
        } while (m_slots[i] != 0);
    }
    return 0;
}

struct FUN_00db7b40
{
    virtual void v0();
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00db7b40(int a, int b, int c);
};
// Initializes the object: sets unk06 to 1, stores a, b and c into unk0c, unk10 and unk08, and clears unk14.
// @fnv 0x00db7b40
FUN_00db7b40::FUN_00db7b40(int aiValue1, int aiValue2, int aiValue3)
{
    unk06 = 1;
    unk0c = aiValue1;
    unk10 = aiValue2;
    unk14 = 0;
    unk08 = aiValue3;
}

struct FUN_00db7b70_Array
{
    void** data;
    int count;
    int capacity;
};

struct FUN_00c85750_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
};

struct FUN_00db7b70_Class
{
    int unk00;
    int unk04;
    int unk08;
    void** unk0c;
    int unk10;
    int unk14;
    void EnsureInitialized();
    void AppendToArray(FUN_00db7b70_Array* p);
};

void* hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void* mm, FUN_00db7b70_Array* arr, int count, int size);

// Appends the null-terminated pointer list in unk0c to the array p, growing its capacity via the memory manager when needed.
// @fnv 0x00db7b70
void FUN_00db7b70_Class::AppendToArray(FUN_00db7b70_Array* apArray)
{
    this->EnsureInitialized();

    int count = 0;
    while (this->unk0c[count] != 0)
        count++;

    FUN_00c85750_Obj* tls = (FUN_00c85750_Obj*)hkMemoryRouter_getInstance();
    void* memmgr = tls->unk10;
    int oldCount = apArray->count;
    int iCapacity = apArray->capacity;
    int iNeeded = count + oldCount;
    iCapacity &= 0x3fffffff;
    if (iCapacity < iNeeded)
    {
        int iNewCapacity = (iNeeded >= iCapacity * 2) ? iNeeded : iCapacity * 2;
        hkArrayUtil__reserve(memmgr, apArray, iNewCapacity, 4);
    }
    apArray->count += count;

    void** ppDest = apArray->data + oldCount;
    for (int i = 0; this->unk0c[i] != 0; i++)
        ppDest[i] = this->unk0c[i];
}

struct FnvCpu_FUN_00db7a70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int GetValue();
};
// @fnv 0x00db7a70
// src: GUESS 0x00db7a70 (confidence: low)
int FnvCpu_FUN_00db7a70_CpuObject::GetValue()
{
    return value;
}
