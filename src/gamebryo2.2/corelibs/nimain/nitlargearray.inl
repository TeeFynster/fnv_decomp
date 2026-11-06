
#include "nitlargearray_decls.h"

// @fnv 0x00486b80
template <>
TESTopicInfo* NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >::RemoveAt(unsigned int index)
{
    if (index >= m_uiSize)
        return 0;
    TESTopicInfo* item = m_pBase[index];
    m_pBase[index] = 0;
    if (item)
        --m_uiESize;
    if (index == m_uiSize - 1)
        --m_uiSize;
    return item;
}

#pragma optimize("gty", on)
// @fnv 0x00a64250
template <>
void NiTLargeArray<unsigned int, NiTMallocInterface<unsigned int> >::RemoveAll()
{
    register NiTLargeArray<unsigned int, NiTMallocInterface<unsigned int> >* array = this;
    register unsigned int index = 0;
    if (array->m_uiSize > 0)
    do
    {
        unsigned int* slot = &array->m_pBase[index];
        unsigned int value = *slot;
        if (value)
        {
            NiRefObject* object = reinterpret_cast<NiRefObject*>(value);
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
                object->DeleteThis();
            *slot = 0;
        }
        ++index;
    } while (index < array->m_uiSize);
    array->m_uiSize = 0;
    array->m_uiESize = 0;
}

#pragma optimize("", off)
// @fnv 0x00864240
template <>
unsigned int NiTLargeArray<unsigned int, NiTMallocInterface<unsigned int> >::SetAtGrow(unsigned int index, const unsigned int& value)
{
    if (index >= m_uiMaxSize)
        reinterpret_cast<NiTLargeArray<TESForm*, NiTMallocInterface<TESForm*> >*>(this)->SetSize(index + m_uiGrowBy);
    reinterpret_cast<NiFormArray*>(this)->SetSize(index, const_cast<unsigned int*>(&value));
    return index;
}

// @fnv 0x0061bd20
void NiFormArray::SetSize(unsigned int index, unsigned int* value)
{
    if (index >= m_uiSize)
    {
        m_uiSize = index + 1;
        if (*value)
            ++m_uiESize;
    }
    else if (*value)
    {
        if (m_pBase[index] == 0)
            ++m_uiESize;
    }
    else if (m_pBase[index] != 0)
    {
        --m_uiESize;
    }
    m_pBase[index] = reinterpret_cast<TESForm*>(*value);
}

// @fnv 0x0061bdc0
template <>
void NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >::Compact()
{
    if (m_uiESize == m_uiSize)
        return;
    if (m_uiESize != 0)
    {
        unsigned int index = 0;
        unsigned int destination = 0;
        for (; index < m_uiSize; ++index)
        {
            if (m_pBase[index] != 0)
            {
                if (m_pBase[destination] != m_pBase[index])
                    m_pBase[destination] = m_pBase[index];
                ++destination;
            }
        }
    }
    TESTopicInfo** oldBase = m_pBase;
    m_uiSize = m_uiESize;
    m_uiMaxSize = m_uiSize;
    if (m_uiMaxSize > 0)
    {
        m_pBase = NiTMallocInterface<TESTopicInfo*>::Allocate(m_uiMaxSize);
        for (unsigned int index = 0; index < m_uiSize; ++index)
            m_pBase[index] = oldBase[index];
    }
    else
    {
        m_pBase = 0;
    }
    NiTMallocInterface<TESTopicInfo*>::Deallocate(oldBase);
}
// @fnv 0x00864280
// NiFormArray.h instantiates the shared template: an explicit specialization of the member
template <>
void NiTLargeArray<TESForm*, NiTMallocInterface<TESForm*> >::SetSize(unsigned int size)
{
    TESForm** pOldBase;
    unsigned int ui;
    if (size == m_uiMaxSize)
        return;
    if (size < m_uiSize)
    {
        for (ui = size; ui < m_uiSize; ++ui)
        {
            if (m_pBase[ui] != 0)
            {
                m_pBase[ui] = 0;
                --m_uiESize;
            }
        }
        m_uiSize = size;
    }
    pOldBase = m_pBase;
    m_uiMaxSize = size;
    if (size > 0)
    {
        m_pBase = NiTMallocInterface<TESForm*>::Allocate(m_uiMaxSize);
        for (ui = 0; ui < m_uiSize; ++ui)
            m_pBase[ui] = pOldBase[ui];
        for (ui = m_uiSize; ui < m_uiMaxSize; ++ui)
            m_pBase[ui] = 0;
    }
    else
    {
        m_pBase = 0;
    }
    NiTMallocInterface<TESForm*>::Deallocate(pOldBase);
}

