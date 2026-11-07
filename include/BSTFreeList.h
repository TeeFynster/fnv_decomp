#pragma once
#include "BSTFreeListElem.h"

// src: XBOX_PDB; PC free-list layout retained from ActorTaskManager (lock +4, free head +8).
template <class T> class BSTFreeList
{
public:
    BSTFreeList();
    virtual ~BSTFreeList();

    unsigned int m_uiLockState;
    BSTFreeListElem<T>* pFree;

    bool Allocate(BSTFreeListElem<T>*& apElement, const T& arItem);
    void Deallocate(BSTFreeListElem<T>*& apElement);
    void Lock();
    void Unlock();
    void PushFront(BSTFreeListElem<T>*&);
    void PrepareNodeAndPushFront(BSTFreeListElem<T>*&);
    void Elem(BSTFreeListElem<T>*&);
    bool BSTFreeList_Allocate_0(BSTFreeListElem<T>*&, const T&);

protected:
    void Init(unsigned int auiCount, BSTFreeListElem<T>* apElements);

private:
    bool DoAllocate(BSTFreeListElem<T>*& apElement);
    void DoDeallocate(BSTFreeListElem<T>*& apElement);
};
