// gamebryo2.2/corelibs/nimain/nismartpointer_decls.h: unit-specific declarations
#ifndef FNV_NISMARTPOINTER_DECLS_H
#define FNV_NISMARTPOINTER_DECLS_H

#include "../../../../include/NiPointer.h"
#include "../../../../include/NiD3DPixelShader.h"
#include "../../../../include/NiGPUProgram.h"
#include "../../../../include/ActorPathingMessageQueue.h"
#include "../../../../include/NavMeshPtr.h"
#include "../../../../include/PathingLocation.h"
#include "../../../../include/PathingRequest.h"


extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

class WaitableObject
{
  public:
    void NiRefObject_DecRefCount();
    void NiRefObject_IncRefCount();
};

class KFModel
{
  public:
    void KFModel_DecRefCount();
    void KFModel_IncRefCount();
};

class LoadedFile
{
  public:
    void LoadedFile_DecRefCount();
    void LoadedFile_IncRefCount();
};

template <class T> struct NiPointerRefOps
{
    static void Dec(T* object)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
            object->DeleteThis();
    }
    static void Inc(T* object)
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
    }
};

template <> NiPointer<PathingAvoidNodeArray>& NiPointer<PathingAvoidNodeArray>::operator=(PathingAvoidNodeArray*);

class KFModelLookupTable
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual bool Lookup(const char* key, KFModel*& result);
};

class KFModelLookup
{
  public:
    void* unknown;
    KFModelLookupTable* table;
    KFModel* Lookup(const char* key);
};

class NiGPUProgramOwner
{
  public:
    char prefix[0x30];
    NiGPUProgram* program;
    void SetProgram(NiGPUProgram*);
};

extern BSTFreeList<ActorPathingMessage> g_011d77f0;

#endif
