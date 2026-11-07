#ifndef FNV_NISMARTPOINTER_H
#define FNV_NISMARTPOINTER_H

#include "nismartpointer_decls.h"

template <class T> inline NiPointer<T>::~NiPointer()
{
    T* pkNew = m_pObject;
    if (pkNew)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&pkNew->m_uiRefCount)) == 0)
            pkNew->DeleteThis();
    }
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    T* previous = m_pObject;
    if (previous != pkNew)
    {
        if (previous)
            NiPointerRefOps<T>::Dec(previous);
        m_pObject = pkNew;
        if (pkNew)
            NiPointerRefOps<T>::Inc(pkNew);
    }
    return *this;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    T* pkNew = kSrc.m_pObject;
    if (m_pObject != pkNew)
    {
        if (m_pObject)
            NiPointerRefOps<T>::Dec(m_pObject);
        m_pObject = pkNew;
        if (m_pObject)
            NiPointerRefOps<T>::Inc(m_pObject);
    }
    return *this;
}

// @fnv 0x0044b070
template <> NiPointer<KFModel>& NiPointer<KFModel>::operator=(KFModel* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->KFModel_DecRefCount();
        m_pObject = object;
        if (m_pObject)
            m_pObject->KFModel_IncRefCount();
    }
    return *this;
}

// @fnv 0x0044b220
template <> NiPointer<LoadedFile>& NiPointer<LoadedFile>::operator=(LoadedFile* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->LoadedFile_DecRefCount();
        m_pObject = object;
        if (m_pObject)
            m_pObject->LoadedFile_IncRefCount();
    }
    return *this;
}

// @fnv 0x006e5cc0
template <> NiPointer<WaitableObject>& NiPointer<WaitableObject>::operator=(const NiPointer<WaitableObject>& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
            m_pObject->NiRefObject_DecRefCount();
        m_pObject = other.m_pObject;
        if (m_pObject)
            m_pObject->NiRefObject_IncRefCount();
    }
    return *this;
}

class MemoryManager;
extern MemoryManager g_memoryManager;
// @fnv 0x00401020
// src: XBOX_PDB 0x00401020
MemoryManager* MemoryManager_Instance()
{
    return &g_memoryManager;
}

// @fnv 0x0042f4c0
NavMeshPtr& NavMeshPtr::operator=(const NavMeshPtr& other)
{
    return AssignRetainedObject_0042fdc0(other);
}

// @fnv 0x006d1bc0
void PathingRequest::SetDestination(PathingLocation* value)
{
    Destination = *value;
}

// @fnv 0x006d61e0
void PathingRequest::SetAvoidNodeArray(BSSimpleArray<void*, 1024>* value)
{
    m_pPathingAvoidNodeArray = reinterpret_cast<PathingAvoidNodeArray*>(value);
}

#pragma optimize("gty", on)
// @fnv 0x00b66f20
template <> NiPointer<NiD3DPixelShader>::~NiPointer()
{
    NiD3DPixelShader* object = m_pObject;
    if (object && InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
        object->DeleteThis();
}
#pragma optimize("", off)

// @fnv 0x004483e0
KFModel* KFModelLookup::Lookup(const char* key)
{
    KFModel* result = 0;
    if (table->Lookup(key, result))
        return result;
    return 0;
}

#pragma optimize("gty", on)
// @fnv 0x00a5f860
template <> NiPointer<NiGPUProgram>& NiPointer<NiGPUProgram>::operator=(NiGPUProgram* object)
{
    NiGPUProgram* previous = m_pObject;
    if (previous != object)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        m_pObject = object;
        if (object)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
    }
    return *this;
}
#pragma optimize("", off)

#pragma optimize("gty", on)
// @fnv 0x00a67260
void NiGPUProgramOwner::SetProgram(NiGPUProgram* object)
{
    NiGPUProgram* previous = program;
    if (previous != object)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        program = object;
        if (object)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
    }
}
#pragma optimize("", off)

// @fnv 0x008df900
ActorPathingMessageQueue::ActorPathingMessageQueue() : BSTCommonLLMessageQueue<QueuedMessage>(&g_011d77f0)
{}

#endif
