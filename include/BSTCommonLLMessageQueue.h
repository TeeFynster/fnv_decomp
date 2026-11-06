#pragma once
#include "LockPrimitive.h"

template <class T> class BSTFreeList;
template <class T> class BSTFreeListElem;

template <class T> class BSTCommonLLMessageQueue
{
public:
    BSTCommonLLMessageQueue(BSTFreeList<T>* apList);
    virtual ~BSTCommonLLMessageQueue();
    virtual bool Push(const T& arMessage);
    virtual bool TryPush(const T& arMessage);
    virtual bool Pop(T& arMessage);
    virtual bool TryPop(T& arMessage);
    virtual bool EnqueueMessage(const T& arMessage);
    virtual bool RemoveMessage(T& arMessage);

    unsigned int lock;
    BSTFreeList<T>* pSizeClassFreeList;
    BSTFreeListElem<T>* pHead;
    BSTFreeListElem<T>** m_ppTailLink;
};

class ActorPathingMessage;

template <> class BSTCommonLLMessageQueue<ActorPathingMessage>
{
  public:
    BSTCommonLLMessageQueue(BSTFreeList<ActorPathingMessage>* apList);
    virtual ~BSTCommonLLMessageQueue();
    virtual bool Push(const ActorPathingMessage& arMessage);
    virtual bool TryPush(const ActorPathingMessage& arMessage);
    virtual bool Pop(ActorPathingMessage& arMessage);
    virtual bool TryPop(ActorPathingMessage& arMessage);
    virtual bool EnqueueMessage(const ActorPathingMessage& arMessage);
    virtual bool RemoveMessage(ActorPathingMessage& arMessage);

    LockPrimitive kLock;
    BSTFreeList<ActorPathingMessage>* pSizeClassFreeList;
    BSTFreeListElem<ActorPathingMessage>* pHead;
    BSTFreeListElem<ActorPathingMessage>** m_ppTailLink;
};

class MobileObjectTaskletContext;

template <> class BSTCommonLLMessageQueue<MobileObjectTaskletContext>
{
public:
    BSTCommonLLMessageQueue(BSTFreeList<MobileObjectTaskletContext>* apList);
    virtual ~BSTCommonLLMessageQueue();
    virtual bool Push(const MobileObjectTaskletContext& arMessage);
    virtual bool TryPush(const MobileObjectTaskletContext& arMessage);
    virtual bool Pop(MobileObjectTaskletContext& arMessage);
    virtual bool TryPop(MobileObjectTaskletContext& arMessage);
    virtual bool EnqueueMessage(const MobileObjectTaskletContext& arMessage);
    virtual bool RemoveMessage(MobileObjectTaskletContext& arMessage);

    LockPrimitive kLock;
    BSTFreeList<MobileObjectTaskletContext>* pSizeClassFreeList;
    BSTFreeListElem<MobileObjectTaskletContext>* pHead;
    BSTFreeListElem<MobileObjectTaskletContext>** m_ppTailLink;
};
