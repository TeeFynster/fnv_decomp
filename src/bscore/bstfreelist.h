#ifndef BSTFREELIST_H
#define BSTFREELIST_H

#include "bstfreelist_decls.h"
template <>
// @fnv 0x009059c0
void BSTFreeList<QueuedMessage>::Elem(BSTFreeListElem<QueuedMessage>*& element)
{
    element->FUN_00905ae0();
    PushFront(element);
}
#endif
