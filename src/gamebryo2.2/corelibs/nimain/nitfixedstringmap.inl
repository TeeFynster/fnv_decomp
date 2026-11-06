
#include "nitfixedstringmap_decls.h"

template<>
// @fnv 0x00a8f770
void NiAVObjectFixedStringMap::GetNext(void*& pos, NiFixedString& key, NiAVObject*& value) const
{
    EntryType* item = static_cast<EntryType*>(pos);
    char* handle = item->m_key.m_kHandle;
    if (key.m_kHandle != handle)
    {
        if (handle != EmptyFS.m_kHandle)
            InterlockedIncrement(reinterpret_cast<volatile long*>(handle) - 2);
        if (key.m_kHandle != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(key.m_kHandle) - 2);
        key.m_kHandle = handle;
    }
    value = item->m_val;
    if (item->m_pkNext)
    {
        pos = item->m_pkNext;
        return;
    }
    unsigned int hash = reinterpret_cast<unsigned int>(item->m_key.m_kHandle) % m_uiHashSize;
    for (++hash; hash < m_uiHashSize; ++hash)
    {
        item = m_ppkHashTable[hash];
        if (item)
        {
            pos = item;
            return;
        }
    }
    pos = 0;
}

template<>
// @fnv 0x00a6e980
void NiCharFixedStringMap::SetAt(const NiFixedString& key, const char* value)
{
    unsigned int hash = reinterpret_cast<unsigned int>(key.m_kHandle) % m_uiHashSize;
    EntryType* item = m_ppkHashTable[hash];
    while (item)
    {
        if (key.m_kHandle == item->m_key.m_kHandle)
        {
            SetValue(item, key, value);
            return;
        }
        item = item->m_pkNext;
    }
    item = NewItem();
    SetValue(item, key, value);
    item->m_pkNext = m_ppkHashTable[hash];
    m_ppkHashTable[hash] = item;
    ++m_kItemCount.m_uiCount;
}

template<>
// @fnv 0x00aa01f0
void NiAVObjectFixedStringMap::RemoveAll()
{
    for (unsigned int hash = 0; hash < m_uiHashSize; ++hash)
    {
        while (m_ppkHashTable[hash])
        {
            EntryType* item = m_ppkHashTable[hash];
            m_ppkHashTable[hash] = item->m_pkNext;
            DeleteItem(item);
        }
    }
    m_kItemCount.m_uiCount = 0;
}
