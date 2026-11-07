
#include "nitstringmap_decls.h"

template <>
// @fnv 0x00a642a0
void NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*>::SetAt(
    const char* key, NiShader* value)
{
    register NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*>* map =
        static_cast<NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*>*>(this);
    register unsigned int index = map->KeyToHashIndex(key);
    register NiTMapItem<const char*, NiShader*>* item = map->m_ppkHashTable[index];
    while (item)
    {
        if (map->IsKeysEqual(key, item->m_key))
        {
            if (!map->m_bCopy)
                item->m_key = key;
            item->m_val = value;
            return;
        }
        item = item->m_pkNext;
    }

    item = (NiTMapItem<const char*, NiShader*>*)map->m_kItemCount.Allocate();
    map->SetValue(item, key, value);
    item->m_pkNext = map->m_ppkHashTable[index];
    map->m_ppkHashTable[index] = item;
    ++map->m_kItemCount.m_uiCount;
}

template <>
// @fnv 0x00a643e0
void NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, unsigned short>::SetAt(
    const char* key, unsigned short value)
{
    register NiTStringTemplateMap<NiTPointerMap<const char*, unsigned short>, unsigned short>* map =
        static_cast<NiTStringTemplateMap<NiTPointerMap<const char*, unsigned short>, unsigned short>*>(this);
    register unsigned int index = map->KeyToHashIndex(key);
    register NiTMapItem<const char*, unsigned short>* item = map->m_ppkHashTable[index];
    while (item)
    {
        if (map->IsKeysEqual(key, item->m_key))
        {
            if (!map->m_bCopy)
                item->m_key = key;
            item->m_val = value;
            return;
        }
        item = item->m_pkNext;
    }

    item = (NiTMapItem<const char*, unsigned short>*)map->m_kItemCount.Allocate();
    map->SetValue(item, key, value);
    item->m_pkNext = map->m_ppkHashTable[index];
    map->m_ppkHashTable[index] = item;
    ++map->m_kItemCount.m_uiCount;
}

#pragma function(strlen)
#pragma optimize("", off)
template <>
// @fnv 0x00a1e770
void NiTStringTemplateMap<NiTPointerMap<const char*, int>, int>::SetValue(NiTMapItem<const char*, int>* item, const char* key, int value)
{
    if (m_bCopy)
    {
        unsigned int length = strlen(key) + 1;
        item->m_key = (char*)_NiMalloc(length);
        char* copy = (char*)item->m_key;
        strcpy_s(copy, length, key);
    }
    else
        item->m_key = key;
    item->m_val = value;
}


#pragma optimize("", on)

template <>
// @fnv 0x00b7fc50
NiTStringPointerMap<ShaderBufferRecord*>::~NiTStringPointerMap()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; ++i)
        {
            NiTMapItem<const char*, ShaderBufferRecord*>* item = m_ppkHashTable[i];
            while (item)
            {
                NiTMapItem<const char*, ShaderBufferRecord*>* old = item;
                item = item->m_pkNext;
                NiFree((void*)old->m_key);
            }
        }
    }
}

// @fnv 0x00b7fce0
// src: GUESS 0x00b7fce0 (confidence: low)
bool __stdcall Object_ProcessAndTransformResult_00b7fce0(const char* left, const char* right)
{
    return NiStricmp(left, right) == 0;
}

