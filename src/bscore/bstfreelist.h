#ifndef BSTFREELIST_H
#define BSTFREELIST_H

#include "bstfreelist_decls.h"
template <>
// @fnv 0x009059c0
void BSTFreeList<QueuedMessage>::Elem(BSTFreeListElem<QueuedMessage>*& element)
{
    element->Destroy_Thunk();
    PushFront(element);
}
#endif
