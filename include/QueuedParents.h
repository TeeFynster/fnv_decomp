#pragma once

#include "BSSimpleArray.h"
#include "ShadowSceneLight.h"

class QueuedFile;

class QueuedParents : public BSSimpleArray<NiPointer<QueuedFile>, 1024>
{
public:
    virtual ~QueuedParents();
    virtual NiPointer<QueuedFile>* _Allocate(unsigned int count);
    virtual void _Deallocate(NiPointer<QueuedFile>* items);
    virtual NiPointer<QueuedFile>* _Reallocate(NiPointer<QueuedFile>* items, unsigned int count);

    void __thiscall SetVtableAndProcessState_00c3d930();
    void __thiscall SetVtableAndProcessState_00c3c570();
    void __thiscall Resize(int reserve, int count);
    int* __thiscall QueuedParents_00c3c540();
    void* __thiscall FUN_00c3d3b0(unsigned int flags);
};
