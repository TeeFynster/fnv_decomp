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
    void FUN_00401970();
    void FUN_0040f6e0();
};

class KFModel
{
  public:
    void FUN_0044b050();
    void FUN_0044b010();
};

class LoadedFile
{
  public:
    void FUN_0044b180();
    void FUN_0044b0f0();
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
