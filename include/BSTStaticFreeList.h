#pragma once
#include "BSTFreeList.h"

// src: XBOX_PDB; PC free-list layout retained from ActorTaskManager (lock +4, free head +8).
template <class T, unsigned int ItemUpdateArray>
class BSTStaticFreeList : public BSTFreeList<T>
{
public:
    BSTStaticFreeList();
    virtual ~BSTStaticFreeList();

    BSTFreeListElem<T> kElems[ItemUpdateArray];
};
