#include "../../include/NiPointer.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMapItem.h"
#include "../../include/DFALL.h"

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// CombatThreatRecord_nitmapbase: local type (was include/CombatThreatRecord.h, which had no evidence of one real class); its methods are 0x009a4f40 SandBoxChoiceListItem::InitLoadGame, 0x009a5170 CombatThreat::IsExpired, 0x009a5e50 NiTMapBase<DFALL<NiTMapItem<unsigned int,CombatThreat *> >,unsigned int,CombatThreat *>::~NiTMapBase<DFALL<NiTMapItem<unsigned int,CombatThreat *> >,unsigned int,CombatThreat *>
class BGSLoadGameBuffer;

class CombatThreatRecord_nitmapbase
{
public:
    void* vfn_00;
    int pad_04;
    void* p_08;

    ~CombatThreatRecord_nitmapbase();
    bool IsXLessThan(float);
    void LoadGame(BGSLoadGameBuffer*);
    void __thiscall FUN_009a5e50();
};

extern int DAT_01189c40;

struct FUN_00404b10_class
{
    void* m_p;
    void __thiscall FUN_00404b90(int);
    void* __thiscall Initialize();
};

// Calls FUN_00404b90 with DAT_01189c40, sets m_p to "@K@", and returns this.
// @fnv 0x00404b10
void* __thiscall FUN_00404b10_class::Initialize()
{
    FUN_00404b90(DAT_01189c40);
    m_p = "@K@";
    return this;
}

extern int DAT_01012188;
struct FUN_00404d00_class
{
    void* m_vtbl;
    unsigned char m_kPointB;
    int m_auiShapeKeys[0x41];
    int m_i;
    FUN_00404d00_class();
};
// @fnv 0x00404d00
FUN_00404d00_class::FUN_00404d00_class()
{
    m_vtbl = &DAT_01012188;
    m_auiShapeKeys[0x40] = 0;
    m_kPointB = 0;
}

struct AnimSequenceBase;

// Hashes the key, walks the bucket chain matching keys, and returns the stored value via the out parameter on a hit.
// @fnv 0x0049c390
template <>
bool NiTMapBase<DFALL<NiTMapItem<unsigned short, AnimSequenceBase*> >, unsigned short, AnimSequenceBase*>::GetAt(unsigned short key, AnimSequenceBase*& value) const
{
    unsigned int uiIndex = KeyToHashIndex(key);
    NiTMapItem<unsigned short, AnimSequenceBase*>* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            value = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

// Looks up key in the hash table, returning true and setting value to the matching item's data, or false if not found.
// @fnv 0x00853130
template <>
bool NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord_nitmapbase*> >, unsigned int, CombatThreatRecord_nitmapbase*>::GetAt(unsigned int key, CombatThreatRecord_nitmapbase*& value) const
{
    NiTMapItem<unsigned int, CombatThreatRecord_nitmapbase*>* item;
    unsigned int index = KeyToHashIndex(key);
    item = m_ppkHashTable[index];
    while (item)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            value = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

// Iterates the container's entries, deletes each stored object, then removes all entries.
// @fnv 0x009a5270
void __fastcall DeleteAllEntries(NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord_nitmapbase*> >, unsigned int, CombatThreatRecord_nitmapbase*>* map)
{
    void* position = map->GetFirstPos();
    while (position)
    {
        unsigned int key = 0;
        CombatThreatRecord_nitmapbase* pEntry = 0;
        map->GetNext(position, key, pEntry);
        delete pEntry;
    }
    map->RemoveAll();
}

void* __cdecl FormHeap_Allocate(unsigned int size);
extern void* DAT_011c8048;

struct SpawnedObj404a80
{
    char m00[0x120];
    SpawnedObj404a80();
    static void* operator new(unsigned int size)
    {
        return FormHeap_Allocate(size);
    }
};

// Allocates a SpawnedObj404a80 and stores it in DAT_011c8048 if that global is currently null.
// @fnv 0x00404a80
void __cdecl EnsureSpawnedObj()
{
    if (DAT_011c8048 == 0)
    {
        DAT_011c8048 = new SpawnedObj404a80();
    }
}

class B90Base
{
  public:
    B90Base();
    virtual ~B90Base();

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
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
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
};

struct B90Buffer
{
    B90Buffer(int iSize, char cFill);

    int unk00;
};

class FUN_00404b90 : public B90Base
{
  public:
    FUN_00404b90(int iSize);
    virtual ~FUN_00404b90();

    B90Buffer m_kBuffer;
};

// Constructs the object, initializing m_kBuffer with the given size and a zero fill.
// @fnv 0x00404b90
FUN_00404b90::FUN_00404b90(int iSize) : m_kBuffer(iSize, 0)
{}

// Removes every map item and resets the entry count.
// @fnv 0x00438af0
template <>
void NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord_nitmapbase*> >, unsigned int, CombatThreatRecord_nitmapbase*>::RemoveAll()
{
    unsigned int index;

    for (index = 0; index < this->m_uiHashSize; ++index)
    {
        while (this->m_ppkHashTable[index] != 0)
        {
            NiTMapItem<unsigned int, CombatThreatRecord_nitmapbase*>* item = this->m_ppkHashTable[index];
            this->m_ppkHashTable[index] = this->m_ppkHashTable[index]->m_pkNext;
            this->ClearValue(item);
            this->DeleteItem(item);
        }
    }

    this->m_kItemCount.m_uiCount = 0;
}

// @fnv 0x0049c250
template <>
bool NiTMapBase<DFALL<NiTMapItem<unsigned short, AnimSequenceBase*> >, unsigned short, AnimSequenceBase*>::RemoveAt(unsigned short key)
{
    unsigned int hashIndex = KeyToHashIndex(key);
    NiTMapItem<unsigned short, AnimSequenceBase*>* item = m_ppkHashTable[hashIndex];
    if (item != 0)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            m_ppkHashTable[hashIndex] = item->m_pkNext;
            ClearValue(item);
            DeleteItem(item);
            m_kItemCount.m_uiCount -= 1;
            return true;
        }
        else
        {
            NiTMapItem<unsigned short, AnimSequenceBase*>* prior = item;
            NiTMapItem<unsigned short, AnimSequenceBase*>* next = prior->m_pkNext;
            while (next != 0 && !IsKeysEqual(key, next->m_key))
            {
                prior = next;
                next = next->m_pkNext;
            }
            if (next != 0)
            {
                prior->m_pkNext = next->m_pkNext;
                ClearValue(next);
                DeleteItem(next);
                m_kItemCount.m_uiCount -= 1;
                return true;
            }
        }
    }
    return false;
}

// Reads the key and value of the node at position, then advances position to the next node or the next non-empty bucket, or null.
// @fnv 0x006b7f20
template <>
void NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord_nitmapbase*> >, unsigned int, CombatThreatRecord_nitmapbase*>::GetNext(void*& position, unsigned int& outKey, CombatThreatRecord_nitmapbase*& outValue) const
{
    unsigned int bucket;
    {
        NiTMapItem<unsigned int, CombatThreatRecord_nitmapbase*>* current = static_cast<NiTMapItem<unsigned int, CombatThreatRecord_nitmapbase*>*>(position);
        outKey = current->m_key;
        outValue = current->m_val;
        if (current->m_pkNext != 0)
        {
            position = current->m_pkNext;
        }
        else
        {
            bucket = KeyToHashIndex(current->m_key);
            ++bucket;
            for (; bucket < m_uiHashSize; ++bucket)
            {
                current = m_ppkHashTable[bucket];
                if (current != 0)
                {
                    position = current;
                    return;
                }
            }
            position = 0;
        }
    }
}

// Inserts or updates the unsigned integer value for a key.
// @fnv 0x00844700
template <>
void NiTMapBase<DFALL<NiTMapItem<unsigned int, unsigned int> >, unsigned int, unsigned int>::SetAt(unsigned int key, unsigned int value)
{
    unsigned int counter = this->KeyToHashIndex(key);
    NiTMapItem<unsigned int, unsigned int>* node = this->m_ppkHashTable[counter];
    int index = 0;

    while (node != 0)
    {
        ++index;

        if (this->IsKeysEqual(key, node->m_key))
        {
            node->m_val = value;
            return;
        }

        node = node->m_pkNext;
    }

    node = this->NewItem();
    this->SetValue(node, key, value);
    node->m_pkNext = this->m_ppkHashTable[counter];
    this->m_ppkHashTable[counter] = node;
    ++this->m_kItemCount.m_uiCount;
}

// Looks up the bucket for key, updates the matching node's value, or allocates a new node, links it into the bucket and increments the count.
// @fnv 0x00a0c6c0
template <>
void NiTMapBase<DFALL<NiTMapItem<unsigned int, AnimSequenceBase*> >, unsigned int, AnimSequenceBase*>::SetAt(unsigned int key, AnimSequenceBase* value)
{
    unsigned int index = KeyToHashIndex(key);
    NiTMapItem<unsigned int, AnimSequenceBase*>* item = m_ppkHashTable[index];
    unsigned int n = 0;
    while (item != 0)
    {
        n++;
        if (IsKeysEqual(key, item->m_key))
        {
            item->m_val = value;
            return;
        }
        item = item->m_pkNext;
    }
    item = NewItem();
    SetValue(item, key, value);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_kItemCount.m_uiCount++;
}

class NiAVObject;
// Looks up key in the bucket chain, replaces the value if found, otherwise allocates a new item, inserts it at the bucket head and increments size.
// @fnv 0x006c6920
template <>
void NiTMapBase<DFALL<NiTMapItem<unsigned int, NiPointer<NiAVObject> > >, unsigned int, NiPointer<NiAVObject> >::SetAt(unsigned int key, NiPointer<NiAVObject> value)
{
    unsigned int index = KeyToHashIndex(key);
    NiTMapItem<unsigned int, NiPointer<NiAVObject> >* item = m_ppkHashTable[index];
    unsigned int count = 0;
    while (item)
    {
        count++;
        if (IsKeysEqual(key, item->m_key))
        {
            item->m_val = value;
            return;
        }
        item = item->m_pkNext;
    }
    item = NewItem();
    SetValue(item, key, value);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_kItemCount.m_uiCount++;
}

// Looks up the hash bucket for key, unlinks the matching item, clears and deletes it, decrements the count, and returns whether it was found.
// @fnv 0x00a1e240
template <>
bool NiTMapBase<DFALL<NiTMapItem<unsigned int, void*> >, unsigned int, void*>::RemoveAt(unsigned int soughtKey)
{
    unsigned int bucket = KeyToHashIndex(soughtKey);
    NiTMapItem<unsigned int, void*>* head = m_ppkHashTable[bucket];
    if (head)
    {
        if (IsKeysEqual(soughtKey, head->m_key))
        {
            m_ppkHashTable[bucket] = head->m_pkNext;
            ClearValue(head);
            DeleteItem(head);
            m_kItemCount.m_uiCount--;
            return true;
        }
        else // src: GAMEBRYO_SRC (shape)
        {
            NiTMapItem<unsigned int, void*>* previous = head;
            NiTMapItem<unsigned int, void*>* current = previous->m_pkNext;
            for (; current && !IsKeysEqual(soughtKey, current->m_key);)
            {
                previous = current;
                current = current->m_pkNext;
            }
            if (current)
            {
                previous->m_pkNext = current->m_pkNext;
                this->ClearValue(current);
                this->DeleteItem(current);
                m_kItemCount.m_uiCount--;
                return true;
            }
        }
    }
    return false;
}

// Hashes the key, walks the bucket chain comparing keys, copies the matching value into val and returns true, else false.
// @fnv 0x00ae7e60
template <>
bool NiTMapBase<DFALL<NiTMapItem<unsigned int, NiPointer<NiAVObject> > >, unsigned int, NiPointer<NiAVObject> >::GetAt(unsigned int key, NiPointer<NiAVObject>& val) const
{
    unsigned int uiIndex = KeyToHashIndex(key);
    NiTMapItem<unsigned int, NiPointer<NiAVObject> >* pkItem = m_ppkHashTable[uiIndex];
    int u1, u2;
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            val = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

// Copies the key and value of the item at pos out, then advances pos to the next item in its chain or the next occupied bucket, or to null at the end.
// @fnv 0x00ae7ee0
template <>
void NiTMapBase<DFALL<NiTMapItem<unsigned int, NiPointer<NiAVObject> > >, unsigned int, NiPointer<NiAVObject> >::GetNext(void*& pos, unsigned int& key, NiPointer<NiAVObject>& val) const
{
    __int64 spare;
    NiTMapItem<unsigned int, NiPointer<NiAVObject> >* pkItem = static_cast<NiTMapItem<unsigned int, NiPointer<NiAVObject> >*>(pos);
    key = pkItem->m_key;
    val = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        pos = pkItem->m_pkNext;
        return;
    }
    unsigned int i = KeyToHashIndex(pkItem->m_key);
    for (++i; i < m_uiHashSize; i++)
    {
        pkItem = m_ppkHashTable[i];
        if (pkItem)
        {
            pos = pkItem;
            return;
        }
    }
    pos = 0;
}
