
#include "bstmessagequeue_decls.h"
template <>
// @fnv 0x00905770
bool BSTCommonLLMessageQueue<QueuedMessage>::RemoveMessage(QueuedMessage& output)
{
    BSTFreeListElem<QueuedMessage>* pElem = pHead;
    bool bResult;
    if (pElem)
    {
        output = reinterpret_cast<QueuedMessage&>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pElem)->GetItem());
        pHead = pElem->pNext;
        pSizeClassFreeList->Elem(pElem);
        bResult = true;
    }
    else
        bResult = false;
    return bResult;
}
template <>
// @fnv 0x009056f0
bool BSTCommonLLMessageQueue<QueuedMessage>::EnqueueMessage(const QueuedMessage& input)
{
    BSTFreeListElem<QueuedMessage>* pElem;
    bool bResult;
    if (pSizeClassFreeList && pSizeClassFreeList->BSTFreeList_Allocate_0(pElem, input))
    {
        if (!pHead)
            m_ppTailLink = &pHead;
        *m_ppTailLink = pElem;
        pElem->pNext = 0;
        m_ppTailLink = &pElem->pNext;
        bResult = true;
    }
    else
        bResult = false;
    return bResult;
}
