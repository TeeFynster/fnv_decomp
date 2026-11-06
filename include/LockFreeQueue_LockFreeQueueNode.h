#pragma once
#include "LockFreeQueue.h"

// src: XBOX_PDB; node allocation in exe 0x0044b500 is eight bytes.
template <class T> class LockFreeQueue<T>::LockFreeQueueNode
{
public:
    void* m_pFirst;
    void* m_pSecond;
    LockFreeQueueNode();
};
