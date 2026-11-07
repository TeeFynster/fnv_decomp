#include "../../../../include/NiTMapItem.h"

// to their real unit once identified.

#include "nid3dshaderfactory_decls.h"

template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc)
{
    m_pObject = kSrc.m_pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

const char kFailedShaderFactoryMessage[] = "Failed to create shader factory!";

class ShaderRefObject
{
  public:
    virtual ~ShaderRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};



struct ShaderMapAllocator
{
    unsigned int m_uiCount;
    void* Allocate();
};

class ShaderStringPointerMap
{
  public:
    virtual ~ShaderStringPointerMap();
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, NiPointer<ShaderRefObject> >* pkItem, const char* key, NiPointer<ShaderRefObject> val);

    unsigned int m_uiHashSize;
    NiTMapItem<const char*, NiPointer<ShaderRefObject> >** m_ppkHashTable;
    ShaderMapAllocator m_kItemCount;
    bool m_bCopy;

    void NiTStringTemplateMap_NiTPointerMap_char_const_NiPointer_NiSequence_NiPointer_NiSequence_SetAt(const char* key, NiPointer<ShaderRefObject> val) throw();
};

// @fnv 0x00e927f0
// src: XBOX_PDB 0x00e927f0
void ShaderStringPointerMap::NiTStringTemplateMap_NiTPointerMap_char_const_NiPointer_NiSequence_NiPointer_NiSequence_SetAt(const char* key, NiPointer<ShaderRefObject> val)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    NiTMapItem<const char*, NiPointer<ShaderRefObject> >* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            if (!m_bCopy)
                pkItem->m_key = key;
            pkItem->m_val = val;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }

    pkItem = (NiTMapItem<const char*, NiPointer<ShaderRefObject> >*)m_kItemCount.Allocate();
    SetValue(pkItem, key, val);
    pkItem->m_pkNext = m_ppkHashTable[uiIndex];
    m_ppkHashTable[uiIndex] = pkItem;
    m_kItemCount.m_uiCount++;
}
