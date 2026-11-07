#pragma once

// src: XBOX_PDB; PC free-list layout retained from ActorTaskManager (lock +4, free head +8).
template <class T> class BSTFreeListElem
{
public:
    BSTFreeListElem();
    ~BSTFreeListElem();

    unsigned char kRawElem[sizeof(T)];
    BSTFreeListElem<T>* pNext;

    void ConstructElem(const T& arItem);
    void DestructElem();
    T& Elem();
    void ForwardCall_006ecce0();
    void Destroy_Thunk();
};
