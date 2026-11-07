#include "../../../../include/BSTreadTransfInterpolator.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiGlobalStringTable.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiRefObject.h"
#include <string.h>

extern MemoryManager _g_memoryManager;

struct TreadTransformEntry
{
    NiQuatTransform first;
    NiQuatTransform second;
    NiFixedString name;
    TreadTransformEntry();
    static void* operator new[](unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    static void operator delete[](void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
};

// These inline methods are declared, but not defined, in the shared headers.
inline NiFixedString& NiFixedString::operator=(const NiFixedString& other)
{
    if (m_kHandle != other.m_kHandle)
    {
        GlobalStringHandle next = other.m_kHandle;
        NiGlobalStringTable::IncRefCount(next);
        NiGlobalStringTable::DecRefCount(m_kHandle);
        m_kHandle = next;
    }
    return *this;
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&m_pObject->m_uiRefCount));
    }
    return *this;
}
// The base copy helper has no declaration in the shared NiInterpolator header.
extern "C" void NiKeyBasedInterpolator_CopyMembers();

// @fnv 0x00a43690
void BSTreadTransfInterpolator::CopyMembers(BSTreadTransfInterpolator* destination, void* context)
{
    reinterpret_cast<void (__thiscall *)(NiInterpolator*, NiInterpolator*, void*)>(NiKeyBasedInterpolator_CopyMembers)(this, destination, context);
    delete[] destination->entries;
    destination->count = count;
    destination->entries = new TreadTransformEntry[count];
    for (unsigned int i = 0; i < count; i++)
    {
        destination->entries[i].name = entries[i].name;
        memcpy(&destination->entries[i].first, &entries[i].first, sizeof(NiQuatTransform));
        memcpy(&destination->entries[i].second, &entries[i].second, sizeof(NiQuatTransform));
    }
    destination->reference = reference;
    destination->firstValue = firstValue;
    destination->secondValue = secondValue;
}
