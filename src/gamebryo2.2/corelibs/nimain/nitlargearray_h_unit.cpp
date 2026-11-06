// gamebryo2.2/corelibs/nimain/nitlargearray_h_unit.cpp: free functions (1 function)

// include/TESFile.h (through TESTopicInfo.h) needs the Windows types.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "../../../../include/BGSAcousticSpace.h"
#include "../../../../include/NiFormArray.h"
#include "../../../../include/NiTLargeArray.h"

#include "nitlargearray.inl"

struct FUN_005ff560_shell
{
    TESTopicInfo* GetChildByIndex(unsigned int index);
    void RemoveChildAndRelinkNeighbors(unsigned int index);
};

// If the child array exists, links the next child's region to the previous child, then removes the child at index and compacts the array.
// @fnv 0x005ff560
void FUN_005ff560_shell::RemoveChildAndRelinkNeighbors(unsigned int index)
{
    if (*(void**)(this + 0x40))
    {
        TESTopicInfo* pNext = this->GetChildByIndex(index + 1);
        TESTopicInfo* pPrevVal = this->GetChildByIndex(index - 1);
        if (pNext)
            ((BGSAcousticSpace*)pNext)->SetRegion((TESRegion*)pPrevVal);
        ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)*(void**)(this + 0x40))->RemoveAt(index);
        ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)*(void**)(this + 0x40))->Compact();
    }
}
