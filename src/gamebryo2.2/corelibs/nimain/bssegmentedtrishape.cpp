
// src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/MemoryManager.h"

extern "C" void* g_011f5b40;

// @fnv 0x00a86fe0
// src: COMMUNITY 0x00a86fe0
void* __cdecl BSSegmentedTriShape_GetRTTI()
{
    return &g_011f5b40;
}

void __cdecl FinalizeEntries();
void __cdecl FUN_00a745c0();

// @fnv 0x00a87120
// src: XBOX_PDB 0x00a87120
void __cdecl BSSegmentedTriShape_RenderImmediate()
{
    FinalizeEntries();
    FUN_00a745c0();
}

struct FUN_00a86ff0_shell
{
    void SetEntryActive(unsigned int index);
};

// Sets the byte at offset 8 of the 20-byte entry at index to whether its dword at offset 4 is nonzero, then sets the flag at 0xcc.
// @fnv 0x00a86ff0
void __thiscall FUN_00a86ff0_shell::SetEntryActive(unsigned int index)
{
    unsigned char* p = (unsigned char*)this;
    void* arr = *(void**)(p + 0xc4);
    unsigned char* e = (unsigned char*)arr + index * 20;
    unsigned int v = *(unsigned int*)(e + 4);
    *(e + 8) = (unsigned char)(v > 0);
    *(p + 0xcc) = 1;
}

void __fastcall FUN_00a89760(void*);
void __cdecl _delete(void*, unsigned int);
extern "C" MemoryManager g_memoryManager;
extern "C" void* DAT_0109e834;

struct FUN_00a87290_shell
{
    void* __thiscall FUN_00a87290(unsigned int flags);
};

// Sets the vtable, deallocates the pointer at offset 0xc4, calls FUN_00a89760 on this, and frees the object with _delete when flags has bit 0 set.
// @fnv 0x00a87290
void* __thiscall FUN_00a87290_shell::FUN_00a87290(unsigned int flags)
{
    void* old = *(void**)((char*)this + 0xc4);
    *(void**)this = &DAT_0109e834;
    g_memoryManager.DeallocateAlias(old);
    FUN_00a89760(this);
    if (flags & 1)
        _delete(this, 0xd0);
    return this;
}

struct Entry
{
    int unk00;
    int unk04;
    unsigned char enabled;
    int unk0c;
    int unk10;
};
struct Target
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    Entry* entries;
    int unkC8;
    unsigned char active;
    void DisableEntry(unsigned int index);
};
// @fnv 0x00a87020
void Target::DisableEntry(unsigned int index)
{
    entries[index].enabled = 0;
    active = 1;
}

void __cdecl FinalizeEntries();
void __cdecl FUN_00a74600();
// Calls FinalizeEntries then FUN_00a74600 in sequence.
// @fnv 0x00a87130
// src: XBOX_PDB 0x00a87130
void __cdecl BSSegmentedTriShape_OnlyRenderImmediate()
{
    FinalizeEntries();
    FUN_00a74600();
}

struct InputState
{
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
    unsigned short count;
};

struct Record
{
    unsigned int unk00;
    void* object;
    bool active;
    unsigned int count;
    bool selected;
};

struct FUN_00a872d0_shell
{
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
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    InputState* input;
    unsigned int unkbc;
    unsigned int unkc0;
    Record* records;
    unsigned int recordCount;
    bool dirty;
    void ResetRecordSelection();
};

// Marks the first record selected with the input count, deselects the rest, activates records with a non-null object, and clears dirty.
// @fnv 0x00a872d0
void FUN_00a872d0_shell::ResetRecordSelection()
{
    records[0].selected = true;
    records[0].count = input->count;
    for (unsigned int i = 1; i < recordCount; ++i)
    {
        records[i].selected = false;
        if (records[i].object != 0)
            records[i].active = true;
    }
    dirty = false;
}

extern "C" MemoryManager DAT_011f6238;

struct EntryPod70
{
    int unk00;
    int unk04;
    unsigned char enabled;
    int unk0c;
    int unk10;

    static void* operator new[](unsigned int aSize)
    {
        return DAT_011f6238.Game_DoHeapAlloc(aSize);
    }
    static void operator delete[](void* apBlock)
    {
        DAT_011f6238.Deallocate(apBlock);
    }
};

struct FUN_00a871a0_cls : Target
{
    void NiTriShape_CopyMembers(Target* apDst, unsigned int aFlag);
    void CopyEntries(Target* apDst, unsigned int aFlag);
};
// Calls FUN_00a744c0, frees apDst->entries, then copies unkC8 and active and deep-copies the entries array into apDst, or clears it when entries is null.
// @fnv 0x00a871a0
void FUN_00a871a0_cls::CopyEntries(Target* apDst, unsigned int aFlag)
{
    NiTriShape_CopyMembers(apDst, aFlag);
    if (apDst->entries != 0)
    {
        DAT_011f6238.Deallocate(apDst->entries);
    }
    if (entries != 0)
    {
        apDst->unkC8 = unkC8;
        apDst->active = active;
        apDst->entries = (Entry*)new EntryPod70[unkC8];
        for (unsigned int i = 0; i < unkC8; ++i)
            apDst->entries[i] = entries[i];
    }
    else
    {
        apDst->entries = 0;
        apDst->unkC8 = 0;
    }
}

extern "C" void* DAT_0109e834;

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct FUN_00a744a0_shell
{
    void FUN_00a744a0();
};

struct FUN_00a871a0_shell
{
    void CopyEntries(void* a, unsigned int b);
};

struct FUN_00a87340_cls
{
    Target* CreateTarget(unsigned int volatile flags);
};

// @fnv 0x00a87340
Target* FUN_00a87340_cls::CreateTarget(unsigned int volatile flags)
{
    Target* self = reinterpret_cast<Target*>(this);
    Target* obj = reinterpret_cast<Target*>(Object_DispatchCommandFour(0xd0));
    if (obj != 0)
    {
        reinterpret_cast<FUN_00a744a0_shell*>(obj)->FUN_00a744a0();
        obj->unk00 = (int)&DAT_0109e834;
        obj->entries = 0;
        obj->unkC8 = 0;
        obj->active = 0;
    }
    else
    {
        obj = 0;
    }
    reinterpret_cast<FUN_00a871a0_shell*>(self)->CopyEntries(obj, flags);
    return obj;
}

namespace fnv_00a873b0 {
struct S_a873b0_Bin
{
    int unk00;
    unsigned int pos;
    unsigned int(__cdecl* Read)(S_a873b0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
};
struct S_a873b0_Stream
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
    S_a873b0_Bin* istr;
};
struct S_a873b0_E : Entry
{
    static void* operator new[](unsigned int n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
static __forceinline void S_a873b0_BinRead(S_a873b0_Bin* bin, void* v, unsigned int bytes)
{
    unsigned int sz = bytes;
    bin->pos += bin->Read(bin, v, bytes, &sz, 1);
}
struct S_a873b0_Base
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
    void NiParticleMeshes_LoadBinary(S_a873b0_Stream* s);
};
struct S_a873b0_T : S_a873b0_Base
{
    Entry* entries;
    unsigned int count;
    unsigned char active;
    void ReadFromStream(S_a873b0_Stream* s);
};

// Reads the entry count and each entry's fields from the stream, allocates the entries array, and marks the object active.
// @fnv 0x00a873b0
void S_a873b0_T::ReadFromStream(S_a873b0_Stream* pStream)
{
    NiParticleMeshes_LoadBinary(pStream);
    if (entries)
        DAT_011f6238.Deallocate(entries);
    S_a873b0_BinRead(pStream->istr, &count, 4);
    entries = new S_a873b0_E[count];
    for (unsigned int i = 0; i < count; i++)
    {
        unsigned char b;
        S_a873b0_BinRead(pStream->istr, &b, 1);
        S_a873b0_BinRead(pStream->istr, &entries[i].unk00, 4);
        S_a873b0_BinRead(pStream->istr, &entries[i].unk04, 4);
        entries[i].enabled = 0;
        int v = entries[i].unk04;
        Entry* e = &entries[i];
        if (v == 0)
        {
            e->unk0c = v;
            entries[i].unk00 = v;
        }
        else
        {
            e->unk0c = v;
        }
    }
    active = 1;
}
}  // namespace fnv_00a873b0

typedef int(__cdecl* StreamIoFn)(void*, void*, unsigned int, unsigned int*, unsigned int);
struct StreamFor87520
{
    unsigned int unk00;
    unsigned int bytes;
    unsigned int unk08;
    StreamIoFn io;
};
void __stdcall NiParticleMeshes_SaveBinary(void* owner);
struct FUN_00a87520_shell : Target
{
    void ReadEntries(void* owner);
};
// Reads a count, then reads one byte and two four-byte values for each 20-byte entry from the stream at owner+0x250.
// @fnv 0x00a87520
void FUN_00a87520_shell::ReadEntries(void* owner)
{
    NiParticleMeshes_SaveBinary(owner);
    StreamFor87520* stream = *(StreamFor87520**)((char*)owner + 0x250);
    {
        unsigned int countBytes = 4;
        stream->bytes += stream->io(stream, &unkC8, 4, &countBytes, 1);
    }
    unsigned int index = 0;
    if ((unsigned int)unkC8 <= 0u)
        return;
    unsigned int offset = 0;
    do
    {
        {
            unsigned char flag = 0;
            stream = *(StreamFor87520**)((char*)owner + 0x250);
            {
                unsigned int readBytes = 1;
                stream->bytes += stream->io(stream, &flag, 1, &readBytes, 1);
            }
        }
        stream = *(StreamFor87520**)((char*)owner + 0x250);
        {
            void* firstField = (char*)entries + offset;
            unsigned int fieldBytes = 4;
            stream->bytes += stream->io(stream, firstField, 4, &fieldBytes, 1);
        }
        stream = *(StreamFor87520**)((char*)owner + 0x250);
        {
            void* secondField = (char*)entries + offset + 4;
            unsigned int otherFieldBytes = 4;
            stream->bytes += stream->io(stream, secondField, 4, &otherFieldBytes, 1);
        }
        ++index;
        offset += 0x14;
    } while (index < (unsigned int)unkC8);
}

struct S00a87040_Entry
{
    int unk00;
    int unk04;
    unsigned char flagA;
    int unk0c;
    unsigned char flagB;
    void Sum(const S00a87040_Entry& n)
    {
        int u4 = *(volatile int*)&unk04;
        unk0c = n.unk0c + u4;
    }
};

struct S00a87040_Obj
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
    S00a87040_Entry* entries;
    int count;
    unsigned char active;
    S00a87040_Entry* at(int off)
    {
        return (S00a87040_Entry*)((char*)entries + off);
    }
    void FinalizeEntries();
};

// Propagates flags and sums values from the last entry down to the first, then clears the active flag.
// @fnv 0x00a87040
void S00a87040_Obj::FinalizeEntries()
{
    if (active == 0)
        return;

    S00a87040_Entry* last = &entries[count - 1];
    if (last->unk04 == 0)
    {
        last->flagB = 0;
    }
    else
    {
        last->unk0c = last->unk04;
        last->flagB = last->flagA;
    }

    for (int i = count - 2; i >= 0; --i)
    {
        S00a87040_Entry* e = &entries[i];
        unsigned char a = entries[i].flagA;
        if ((a != 0 && entries[i + 1].flagB != 0) || (e->unk04 == 0 && entries[i + 1].flagB != 0))
        {
            entries[i + 1].flagB = 0;
            entries[i].flagB = 1;
            entries[i].Sum(entries[i + 1]);
            if (entries[i].unk04 == 0)
                entries[i].unk00 = entries[i + 1].unk00;
        }
        else if (e->unk04 != 0)
        {
            e->flagB = a;
            entries[i].unk0c = entries[i].unk04;
        }
        else
        {
            entries[i].flagB = 0;
        }
    }
    active = 0;
}

struct ItemList
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short capacity;
    unsigned short count;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int newCapacity);

    void FUN_0096ae90(unsigned int index, void** item);
    inline unsigned int SetAtGrow(unsigned int index, void* item)
    {
        if (index >= this->capacity)
        {
            this->FUN_0096ad30(index + this->growBy);
        }
        this->FUN_0096ae90(index, &item);
        return index;
    }
    inline unsigned int Add(void* item)
    {
        return SetAtGrow(this->count, item);
    }
};

extern "C" const char DAT_0109e928[];
extern "C" const char DAT_0109e938[];
extern "C" const char DAT_0109e94c[];
extern "C" const char DAT_0109e95c[];
extern "C" void* g_011f5b40;
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* value);
void* __cdecl NiGetViewerString_00a7d510(const char* fmt, unsigned int value);

struct S00a87620_Obj
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    Entry* entries;
    unsigned int count;
    unsigned char active;
    void FUN_00a74690(ItemList* list);
    void AddToItemList(ItemList* list);
};

// @fnv 0x00a87620
void S00a87620_Obj::AddToItemList(ItemList* apItemList)
{
    this->FUN_00a74690(apItemList);
    apItemList->Add(NiViewerStrings_NiGetViewerString_Title(g_011f5b40));
    apItemList->Add(NiGetViewerString_00a7d510(DAT_0109e95c, this->count));

    if (this->entries != 0)
    {
        unsigned int nullCount = 0;
        for (unsigned int i = 0; i < this->count; ++i)
        {
            if (this->entries[i].unk04 != 0)
            {
                if (this->entries[i].enabled)
                {
                    void* item = NiGetViewerString_00a7d510(DAT_0109e94c, i);
                    apItemList->Add(item);
                }
                else
                {
                    void* item = NiGetViewerString_00a7d510(DAT_0109e938, i);
                    apItemList->Add(item);
                }
            }
            else
            {
                nullCount++;
            }
        }
        apItemList->Add(NiGetViewerString_00a7d510(DAT_0109e928, nullCount));
    }
}
