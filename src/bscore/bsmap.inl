
#include "bsmap_decls.h"

template <>
// @fnv 0x00a1e380
bool BSMapBase<unsigned long, ScrapHeapBuffer*>::GetAt(unsigned long key, ScrapHeapBuffer*& data)
{
    unsigned int index = this->KeyToHashIndex(key);
    BSMapEntry<unsigned long, ScrapHeapBuffer*>* item =
        ((BSMapEntry<unsigned long, ScrapHeapBuffer*>**)this->m_ppkHashTable)[index];
    while (item)
    {
        if (this->IsKeysEqual(key, item->m_key))
        {
            data = item->m_data;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

template <>
// @fnv 0x00aa4860
void BSMapBase<void*, PointerMapValue*>::SetAt(void* key, PointerMapValue* data)
{
    unsigned int index = this->KeyToHashIndex((unsigned int)key);
    BSMapEntry<void*, PointerMapValue*>* item =
        ((BSMapEntry<void*, PointerMapValue*>**)this->m_ppkHashTable)[index];
    unsigned int count = 0;
    while (item)
    {
        ++count;
        if (this->IsKeysEqual((unsigned int)key, (unsigned int)item->m_key))
        {
            this->ClearValue((NiTMapItem<unsigned int, unsigned int>*)item);
            this->SetValue((NiTMapItem<unsigned int, unsigned int>*)item, (unsigned int)key, (unsigned int)data);
            return;
        }
        item = item->m_pkNext;
    }
    item = (BSMapEntry<void*, PointerMapValue*>*)this->NewItem();
    this->SetValue((NiTMapItem<unsigned int, unsigned int>*)item, (unsigned int)key, (unsigned int)data);
    item->m_pkNext = ((BSMapEntry<void*, PointerMapValue*>**)this->m_ppkHashTable)[index];
    ((BSMapEntry<void*, PointerMapValue*>**)this->m_ppkHashTable)[index] = item;
    ++this->m_kItemCount.m_uiCount;
}

template <>
// @fnv 0x006f9a80
void BSMapBase<unsigned int, BGSDistantTreeBlock::InstanceData*>::SetAt(
    unsigned int key, BGSDistantTreeBlock::InstanceData* data)
{
    unsigned int index = this->KeyToHashIndex(key);
    BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>* item =
        ((BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>**)this->m_ppkHashTable)[index];
    unsigned int count = 0;
    while (item)
    {
        ++count;
        if (this->IsKeysEqual(key, item->m_key))
        {
            this->ClearValue((NiTMapItem<unsigned int, unsigned int>*)item);
            this->SetValue((NiTMapItem<unsigned int, unsigned int>*)item, key, (unsigned int)data);
            return;
        }
        item = item->m_pkNext;
    }
    item = (BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>*)this->NewItem();
    this->SetValue((NiTMapItem<unsigned int, unsigned int>*)item, key, (unsigned int)data);
    item->m_pkNext =
        ((BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>**)this->m_ppkHashTable)[index];
    ((BSMapEntry<unsigned int, BGSDistantTreeBlock::InstanceData*>**)this->m_ppkHashTable)[index] = item;
    ++this->m_kItemCount.m_uiCount;
}

template <>
// @fnv 0x0048b460
BSMapBase<int, DistantTreeTextureInfo*>::~BSMapBase()
{
    this->RemoveAll();
}
