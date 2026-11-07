#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkInspectProcess.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"

// Flag-variant unit: this function matches under /MT /O2 /GS /Gy.


template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& heap = *reinterpret_cast<hkMemoryAllocator*>(&hkMemoryRouter::getInstance().heap());
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        heap.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
}

template <typename T>
__forceinline void SetInspectionArraySize(hkArray<T>& array, int n)
{
    hkMemoryAllocator& heap = *reinterpret_cast<hkMemoryAllocator*>(&hkMemoryRouter::getInstance().heap());
    int cap = array.m_iCapacityState & 0x3fffffff;
    if (cap < n)
    {
        int cap2 = 2 * cap;
        hkArrayUtil::_reserve(heap, &array, n < cap2 ? cap2 : n, sizeof(T));
    }
    array.m_iElementCount = n;
}

// 0x00ddb770 consumes object/class pointer pairs; these are not Pair's integer handles.
struct hkWrittenObjectQ
{
    const void* m_object;
    const hkClass* m_class;
};

__forceinline int GetInspectionPairCount(hkProcess* process)
{
    return reinterpret_cast<hkInspectProcess*>(reinterpret_cast<char*>(process) - 8)->unk24;
}

// The entry receives hkProcess's subobject (+8); the shared hkInspectProcess has no step override.
// This ABI adapter keeps ECX and the one stack argument without another process class.
// @fnv 0x00ddba20
void __fastcall StepInspectionProcess(hkProcess* process, void*, float unused)
{
    hkArray<hkWrittenObjectQ> written;
    for (int i = 0; i < GetInspectionPairCount(process); i++)
    {
        SetInspectionArraySize(written, 0);
        reinterpret_cast<hkInspectProcess*>(reinterpret_cast<char*>(process) - 8)->writeObject(
            reinterpret_cast<hkWrittenObjectQ*>(reinterpret_cast<hkInspectProcess*>(reinterpret_cast<char*>(process) - 8)->unk20)[i].m_object,
            reinterpret_cast<hkWrittenObjectQ*>(reinterpret_cast<hkInspectProcess*>(reinterpret_cast<char*>(process) - 8)->unk20)[i].m_class,
            false, reinterpret_cast<hkArrQLocalForm<hkWrittenObjectQ>*>(&written));
    }
}
