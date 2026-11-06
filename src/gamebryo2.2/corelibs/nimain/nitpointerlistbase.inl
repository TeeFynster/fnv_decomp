
#include "NiProperty.h"
#include "RecursiveSpinLock.h"
#include "../../../../include/layout_support.h"
#include "Script.h"
#include "nitpointerlistbase_lifetime.h"

// The pool uses the same three-word allocation node as NiTListItem<T>.
// Element ownership is released before the node is returned to the free list.
template<class T> void NiTPointerAllocator<T>::Deallocate(void* pointer)
{
    typedef typename NiTAbstractPoolAllocator<T>::AllocNode AllocNode;
    AllocNode* node = static_cast<AllocNode*>(pointer);
    NiTAbstractPoolAllocator<T>::ms_kCriticalSection.Lock(0);
    node->m_pkData = 0;
    node->m_pkNext = NiTAbstractPoolAllocator<T>::ms_pkFreeMem;
    NiTAbstractPoolAllocator<T>::ms_pkFreeMem = node;
    NiTAbstractPoolAllocator<T>::ms_kCriticalSection.Unlock();
}

template<class Allocator, class T>
inline void NiTPointerListBase<Allocator,T>::DeleteItem(NiTListItem<T>* item)
{
    item->m_element = 0;
    this->m_kItemCount.Deallocate(item);
}

template<class Allocator, class T> void NiTPointerListBase<Allocator,T>::RemoveAll()
{
    NiTListItem<T>* item = this->m_pkHead;
    while (item)
    {
        NiTListItem<T>* removed = item;
        item = item->m_pkNext;
        DeleteItem(removed);
    }
    this->m_kItemCount.m_uiCount = 0;
    this->m_pkHead = 0;
    this->m_pkTail = 0;
}

template<class Allocator, class T> T NiTPointerListBase<Allocator,T>::RemoveHead()
{
    NiTListItem<T>* item = this->m_pkHead;
    NiTListItem<T>* next = item->m_pkNext;
    this->m_pkHead = next;
    if (next)
        next->m_pkPrev = 0;
    else
        this->m_pkTail = 0;
    T element = item->m_element;
    DeleteItem(item);
    --this->m_kItemCount.m_uiCount;
    return element;
}

template<class Allocator, class T> T NiTPointerListBase<Allocator,T>::RemovePos(void*& position)
{
    NiTListItem<T>* item = static_cast<NiTListItem<T>*>(position);
    if (item == this->m_pkHead)
    {
        position = item->m_pkNext;
        return RemoveHead();
    }
    if (item == this->m_pkTail)
    {
        position = 0;
        return RemoveTail();
    }
    NiTListItem<T>* previous = item->m_pkPrev;
    NiTListItem<T>* next = item->m_pkNext;
    position = next;
    if (previous)
        previous->m_pkNext = next;
    if (next)
        next->m_pkPrev = previous;
    T element = item->m_element;
    DeleteItem(item);
    --this->m_kItemCount.m_uiCount;
    return element;
}

template <>
inline void NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::DeleteItem(NiTListItem<char*>* item)
{
    item->m_element = 0;
    this->m_kItemCount.Deallocate(item);
}


#include "nitpointerlistbase_packet.h"

#pragma optimize("", off)
// @fnv 0x0057c730
template <>
Script* NiTPointerListBase<NiTPointerAllocator<unsigned int>,Script*>::Remove(Script* const& element)
{
    void* position = reinterpret_cast<NiTPointerList<TESForm*>*>(this)->FindPos(reinterpret_cast<TESForm* const&>(element),0);
    return position ? RemovePos(position) : element;
}
#pragma optimize("", on)


// Explicit instantiation selects the original optimized NiPointer consumer.
// @fnv 0x00e74d40
template void NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiProperty> >::RemoveAll();

// char* member specializations.
// RemoveTail is defined in its own original TU and linked externally.
template <>
void NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::RemoveAll()
{
    NiTListItem<char*>* item = this->m_pkHead;
    while (item)
    {
        NiTListItem<char*>* removed = item;
        item = item->m_pkNext;
        DeleteItem(removed);
    }
    this->m_kItemCount.m_uiCount = 0;
    this->m_pkHead = 0;
    this->m_pkTail = 0;
}

// @fnv 0x00b602d0
template <>
char* NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::RemoveHead()
{
    NiTListItem<char*>* item = this->m_pkHead;
    NiTListItem<char*>* next = item->m_pkNext;
    this->m_pkHead = next;
    if (next)
        next->m_pkPrev = 0;
    else
        this->m_pkTail = 0;
    char* element = item->m_element;
    DeleteItem(item);
    --this->m_kItemCount.m_uiCount;
    return element;
}

// @fnv 0x00e7d7f0
template <>
char* NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::RemovePos(void*& position)
{
    NiTListItem<char*>* item = static_cast<NiTListItem<char*>*>(position);
    if (item == this->m_pkHead)
    {
        position = item->m_pkNext;
        return RemoveHead();
    }
    if (item == this->m_pkTail)
    {
        position = 0;
        return RemoveTail();
    }
    NiTListItem<char*>* previous = item->m_pkPrev;
    NiTListItem<char*>* next = item->m_pkNext;
    position = next;
    if (previous)
        previous->m_pkNext = next;
    if (next)
        next->m_pkPrev = previous;
    char* element = item->m_element;
    DeleteItem(item);
    --this->m_kItemCount.m_uiCount;
    return element;
}

template <>
char* NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>::Remove(char* const& element)
{
    NiTListItem<char*>* item = this->m_pkHead;
    while (item)
    {
        if (item->m_element == element)
            break;
        item = item->m_pkNext;
    }
    void* position = item;
    if (position)
        return RemovePos(position);
    return element;
}
#pragma optimize("", off)
// @fnv 0x004edf00
template <>
Script* NiTPointerListBase<NiTPointerAllocator<unsigned int>,Script*>::RemoveTail()
{
    NiTListItem<Script*>* item = m_pkTail;
    m_pkTail = m_pkTail->m_pkPrev;
    if (m_pkTail) m_pkTail->m_pkNext = 0;
    else m_pkHead = 0;
    Script* element = item->m_element;
    DeleteItem(item);
    --m_kItemCount.m_uiCount;
    return element;
}
#pragma optimize("", on)

// @fnv 0x00a5a310
template <>
void NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSMultiBound> >::AddTail(const NiPointer<BSMultiBound>& element)
{
    NiTListItem<NiPointer<BSMultiBound> >* item = static_cast<NiTListItem<NiPointer<BSMultiBound> >*>(m_kItemCount.Allocate());
    BSMultiBound* oldObject = item->m_element.m_pObject;
    if (oldObject != element.m_pObject)
    {
        if (oldObject) reinterpret_cast<NiProperty*>(oldObject)->DecRefCount();
        item->m_element.m_pObject = element.m_pObject;
        if (item->m_element.m_pObject) reinterpret_cast<NiProperty*>(item->m_element.m_pObject)->IncRefCount();
    }
    item->m_pkNext = 0;
    item->m_pkPrev = m_pkTail;
    if (m_pkTail) m_pkTail->m_pkNext = item;
    else m_pkHead = item;
    ++m_kItemCount.m_uiCount;
    m_pkTail = item;
}

#pragma optimize("", off)
// @fnv 0x0049f590
template <>
Script* NiTPointerListBase<NiTPointerAllocator<unsigned int>,Script*>::RemovePos(void*& position)
{
    NiTListItem<Script*>* item = static_cast<NiTListItem<Script*>*>(position);
    if (item == m_pkHead) { position = item->m_pkNext; return RemoveHead(); }
    if (item == m_pkTail) { position = 0; return RemoveTail(); }
    NiTListItem<Script*>* pkPrev = item->m_pkPrev;
    NiTListItem<Script*>* pkNext = item->m_pkNext;
    position = pkNext;
    if (pkPrev) pkPrev->m_pkNext = pkNext;
    if (pkNext) pkNext->m_pkPrev = pkPrev;
    Script* element = item->m_element;
    DeleteItem(item);
    --m_kItemCount.m_uiCount;
    return element;
}
#pragma optimize("", on)

template<> void NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<ObstacleData> >::DeleteItem(NiTListItem<NiPointer<ObstacleData> >*);
template<> NiPointer<ObstacleData> NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<ObstacleData> >::RemoveHead();
#pragma optimize("", off)
template<>
// @fnv 0x004a4500
NiPointer<ObstacleData> NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<ObstacleData> >::RemovePos(void*& position)
{
    NiTListItem<NiPointer<ObstacleData> >* item = static_cast<NiTListItem<NiPointer<ObstacleData> >*>(position);
    if (item == this->m_pkHead)
    {
        position = item->m_pkNext;
        return RemoveHead();
    }
    if (item == this->m_pkTail)
    {
        position = 0;
        return RemoveTail();
    }
    NiTListItem<NiPointer<ObstacleData> >* pkPrev = item->m_pkPrev;
    NiTListItem<NiPointer<ObstacleData> >* pkNext = item->m_pkNext;
    position = pkNext;
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;
    NiPointer<ObstacleData> element = item->m_element;
    DeleteItem(item);
    --this->m_kItemCount.m_uiCount;
    return element;
}
#pragma optimize("", on)
