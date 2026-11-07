
// src/unmapped/nitmapbase_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/unmapped/nitmapbase.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../include/NiPointer.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMapItem.h"
#include "../../include/DFALL.h"
#include "../../include/NiTPointerMap.h"

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// CombatThreatRecord_nitmapbase_ob1_variant: local type (was include/CombatThreatRecord.h, which had no evidence of one real class); its methods are 0x009a4f40 SandBoxChoiceListItem::InitLoadGame, 0x009a5170 CombatThreat::IsExpired, 0x009a5e50 NiTMapBase<DFALL<NiTMapItem<unsigned int,CombatThreat *> >,unsigned int,CombatThreat *>::~NiTMapBase<DFALL<NiTMapItem<unsigned int,CombatThreat *> >,unsigned int,CombatThreat *>
class BGSLoadGameBuffer;

class CombatThreatRecord_nitmapbase_ob1_variant
{
public:
    void* vfn_00;
    int pad_04;
    void* p_08;

    ~CombatThreatRecord_nitmapbase_ob1_variant();
    bool IsXLessThan(float);
    void LoadGame(BGSLoadGameBuffer*);
    void __thiscall SetVtableAndProcessState_009a5e50();
};

extern int DAT_01189c40;
struct FUN_00404b10_class
{
    void* m_p;
    void __thiscall FUN_00404b90(int);
    void* __thiscall Initialize();
};
extern int DAT_01012188;
struct FUN_00404d00_class
{
    void* m_vtbl;
    unsigned char m_kPointB;
    int m_auiShapeKeys[0x41];
    int m_i;
    FUN_00404d00_class();
};
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
void __cdecl EnsureSpawnedObj();
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
typedef void* NiTMapIterator;

struct HeapManager
{
    void Deallocate(void* p);
};
extern HeapManager g_memoryManager;

template <class TAlloc, class TKEY, class TVAL>
inline void* NiTMapBase<TAlloc, TKEY, TVAL>::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; i++)
    {
        if (m_ppkHashTable[i])
            return m_ppkHashTable[i];
    }
    return 0;
}

template <class TAlloc, class TKEY, class TVAL>
inline void NiTMapBase<TAlloc, TKEY, TVAL>::GetNext(void*& pos, TKEY& key, TVAL& val) const
{
    NiTMapItem<TKEY, TVAL>* cursor = (NiTMapItem<TKEY, TVAL>*)pos;

    key = cursor->m_key;
    val = cursor->m_val;

    if (cursor->m_pkNext)
    {
        pos = cursor->m_pkNext;
        return;
    }

    unsigned int bucket = this->KeyToHashIndex(cursor->m_key);
    for (++bucket; bucket < m_uiHashSize; bucket++)
    {
        cursor = m_ppkHashTable[bucket];
        if (cursor)
        {
            pos = cursor;
            return;
        }
    }

    pos = 0;
}

template <class TAlloc, class TKEY, class TVAL>
inline void NiTMapBase<TAlloc, TKEY, TVAL>::RemoveAll()
{
    // Drain each chain before moving on; callbacks observe the updated bucket head.
    for (unsigned int bucket = 0; bucket < m_uiHashSize; bucket++)
    {
        for (; m_ppkHashTable[bucket];)
        {
            NiTMapItem<TKEY, TVAL>* retired = m_ppkHashTable[bucket];
            m_ppkHashTable[bucket] = m_ppkHashTable[bucket]->m_pkNext;
            ClearValue(retired);
            DeleteItem(retired);
        }
    }
    m_kItemCount.m_uiCount = 0;
}

struct MapOwnerStandIn
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    NiTPointerMap<unsigned int, void*> m_kFormatEntries;

    void ReleaseStorage_00ec2e50();
};

// @fnv 0x00ec2e50
// src: GUESS 0x00ec2e50 (confidence: low)
void MapOwnerStandIn::ReleaseStorage_00ec2e50()
{
    NiTMapIterator pos = m_kFormatEntries.GetFirstPos();
    while (pos)
    {
        unsigned int uiKey = 0;
        void* pValue = 0;
        m_kFormatEntries.GetNext(pos, uiKey, pValue);
        void* pFree = pValue;
        g_memoryManager.Deallocate(pFree);
    }
    m_kFormatEntries.RemoveAll();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct RefX
{
    virtual void v0();
    virtual void DeleteThis();
    long m_ref;
    void IncRefCount()
    {
        InterlockedIncrement(&m_ref);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_ref) == 0)
            DeleteThis();
    }
};
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& o) : m_pObject(o.m_pObject)
{
    if (m_pObject)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject)
        m_pObject->DecRefCount();
}

inline void DeadX()
{
    int d0;
    int d1;
}
// @fnv 0x00ae7cc0
template <>
void NiTMapBase<DFALL<NiTMapItem<unsigned int, NiPointer<RefX> > >, unsigned int, NiPointer<RefX> >::SetAt(unsigned int key, NiPointer<RefX> val)
{
    DeadX();
    unsigned int index_qtj = KeyToHashIndex(key);
    NiTMapItem<unsigned int, NiPointer<RefX> >* item = m_ppkHashTable[index_qtj];
    int depth_h = 0;
    while (item)
    {
        ++depth_h;
        if (IsKeysEqual(key, item->m_key))
        {
            item->m_val = val;
            return;
        }
        item = item->m_pkNext;
    }
    item = NewItem();
    SetValue(item, key, val);
    item->m_pkNext = m_ppkHashTable[index_qtj];
    m_ppkHashTable[index_qtj] = item;
    m_kItemCount.m_uiCount++;
}
