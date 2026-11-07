// src/havok/common/visualize/process/hkinspectprocess_ehsc_noehsc_variant.cpp
// Command handler compiled with /EHs-c-; the other inspection functions belong to hkinspectprocess.cpp.
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkArrayStreamWriter.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkClassMember.h"
#include "../../../../../include/hkInspectProcess.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"

void* __cdecl hkMemoryRouter_getInstance();
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126cae8;

struct hkWrittenObjectQ
{
    const void* m_object;
    const hkClass* m_class;
};

template <class T> __forceinline T* hkMemoryAllocator::_bufAlloc(int& count)
{
    int bytes = count * int(sizeof(T));
    void* data = bufAlloc(bytes);
    count = bytes / int(sizeof(T));
    return static_cast<T*>(data);
}

typedef unsigned __int64 Wide;
struct InputArchive
{
    void hkIArchive_readArrayGeneric(void* data, int width, int count);
    int ForwardCall_00dd90d0(void* data, int bytes);
    __forceinline Wide readWide()
    {
        Wide value;
        hkIArchive_readArrayGeneric(&value, 8, 1);
        return value;
    }
    __forceinline unsigned short readWord()
    {
        unsigned short value;
        hkIArchive_readArrayGeneric(&value, 2, 1);
        return value;
    }
    __forceinline unsigned int ReadTag()
    {
        unsigned int value;
        hkIArchive_readArrayGeneric(&value, 4, 1);
        return value;
    }
    __forceinline unsigned char readByte()
    {
        unsigned char value;
        hkIArchive_readArrayGeneric(&value, 1, 1);
        return value;
    }
};
// FUN_00c85750 returns thread storage whose heap allocator pointer is at +0x10; no full router layout is needed.
struct ThreadHeapAccess
{
    int unused[4];
    hkMemoryAllocator* allocator;
    hkMemoryAllocator& heap() { return *allocator; }
};
static __forceinline hkMemoryAllocator& getHeap()
{
    return static_cast<ThreadHeapAccess*>(hkMemoryRouter_getInstance())->heap();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator&, void*, int, int);
void __cdecl ResizeAudioStream(hkMemoryAllocator&, void*, int);
// Allocator-dependent array operations stay inline in the unit, as required by hkArray.h.
inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return getHeap();
}
template <class T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& heap, int n)
{
    if (getCapacity() < n)
    {
        int twice = 2 * getCapacity();
        hkArrayUtil__reserve(heap, this, n < twice ? twice : n, sizeof(T));
    }
}
template <class T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& heap, int n)
{
    GrowArrayCapacity(heap, n);
    m_iElementCount = n;
}
template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& heap)
{
    m_iElementCount = 0;
    if (!(m_iCapacityState & 0x80000000))
        heap.bufFree(m_data, getCapacity() * int(sizeof(T)));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <class T> __forceinline T& hkArrayBase<T>::_expandOne(hkMemoryAllocator& heap)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(heap, this, sizeof(T));
    return m_data[m_iElementCount++];
}
template <class T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    --m_iElementCount;
    if (m_iElementCount != index)
    {
        const int* source = reinterpret_cast<const int*>(m_data + m_iElementCount);
        int* destination = reinterpret_cast<int*>(m_data + index);
        unsigned int i = 0;
        do
        {
            destination[i] = source[i];
        } while (++i < sizeof(T) / 4);
    }
}
template <class T, class A> __forceinline hkArray<T, A>::hkArray(int n)
{
    hkMemoryAllocator& heap = getHeap();
    T* p = n ? heap._bufAlloc<T>(n) : 0;
    int cap = n ? n : 0x80000000;
    setOwnedData(p, n, cap);
}
template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    _clearAndDeallocate(getHeap());
}
// 0x00d46f60 is hkClass's mutable member lookup; its declaration is not in the shared header yet.
class InspectionClassAccess : public hkClass
{
  public:
    hkClassMember& FUN_00d46f60(int index);
};
static __forceinline int memberOffset(const hkClassMember& field) { return field.m_offset; }
static __forceinline int memberKind(const hkClassMember& field) { return field.m_type; }
static __forceinline int memberSubtype(const hkClassMember& field) { return field.m_eSubtype; }
// src: HAVOK_LIB 0x00ddb450
static __declspec(noinline) void* _FindMemberItem(void* address, const hkArray<unsigned short>& path, int depth, int kind,
                                               int subtype, const hkClassMember* field)
{
    switch (kind)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 24:
    case 30:
    case 31:
    case 32:
        return address;
    case 14:
    case 15:
    case 17:
    case 18: {
        int childIndex = path[depth + 1];
        void* child = static_cast<char*>(address) + childIndex * 16;
        return _FindMemberItem(child, path, depth + 1, 12, 0, field);
    }
    case 20:
        return 0;
    case 22:
    case 26: {
        int childIndex = path[depth + 1];
        hkArray<char>* array = static_cast<hkArray<char>*>(address);
        void* child = array->begin() + childIndex * field->GetTagValue();
        return _FindMemberItem(child, path, depth + 1, field->m_eSubtype, 0, field);
    }
    case 25: {
        const hkClass* type = field && field->m_class ? field->GetClass() : 0;
        if (type)
        {
            int childIndex = path[depth + 1];
            const hkClassMember& child = type->getMember(childIndex);
            return _FindMemberItem(static_cast<char*>(address) + child.m_offset, path, depth + 1, child.m_type, child.m_eSubtype,
                                &child);
        }
        break;
    }
    }
    return 0;
}
void __cdecl hkString_memCpy(void* destination, const void* source, int bytes);
// 0x00ddbae0 overrides hkProcess::ExecuteCommand on the inspection process's secondary base.
// Keep the missing override declaration here without duplicating hkInspectProcess's layout.
class InspectionCommandHandler : public hkInspectProcess
{
  public:
    virtual void ExecuteCommand(unsigned char command);
    __forceinline InputArchive* inputArchive() { return reinterpret_cast<InputArchive*>(unk08); }
    __forceinline hkArray<hkWrittenObjectQ>& trackedObjects()
    {
        return *reinterpret_cast<hkArray<hkWrittenObjectQ>*>(&unk20);
    }
};
// @fnv 0x00ddbae0
void InspectionCommandHandler::ExecuteCommand(unsigned char command)
{
    switch (command)
    {
    case 0x25: {
        Wide objectID = inputArchive()->readWide();
        Wide classID = inputArchive()->readWide();
        unsigned short length = inputArchive()->readWord();
        hkArray<unsigned short> path(length);
        path.setSize(length);
        for (int i = 0; i < length; ++i)
            path[i] = inputArchive()->readWord();
        unsigned int bytes = inputArchive()->ReadTag();
        hkArray<unsigned char> payload(bytes);
        payload.setSize(bytes);
        inputArchive()->ForwardCall_00dd90d0(payload.begin(), bytes);
        if (objectID > 0 && classID > 0 && path.GetLogicalSize() > 0 && bytes > 0)
        {
            void* object = reinterpret_cast<void*>(unsigned int(objectID));
            InspectionClassAccess* type = reinterpret_cast<InspectionClassAccess*>(unsigned int(classID));
            const hkClassMember& field = type->FUN_00d46f60(path[0]);
            void* destination = _FindMemberItem(static_cast<char*>(object) + memberOffset(field), path, 0, memberKind(field),
                                             memberSubtype(field), &field);
            if (destination)
                hkString_memCpy(destination, payload.begin(), bytes);
        }
        break;
    }
    case 0x23: {
        Wide objectID = inputArchive()->readWide();
        Wide classID = inputArchive()->readWide();
        unsigned char flags = inputArchive()->readByte();
        if (objectID > 0 && classID > 0)
        {
            void* object = reinterpret_cast<void*>(unsigned int(objectID));
            hkClass* type = reinterpret_cast<hkClass*>(unsigned int(classID));
            hkArray<hkWrittenObjectQ> visited;
            bool recurse = static_cast<const void*>(type) == &g_0126cae8 || (flags & 2);
            writeObject(
                object, type, recurse, reinterpret_cast<hkArrQLocalForm<hkWrittenObjectQ>*>(&visited));
            int count = trackedObjects().GetLogicalSize();
            int i = 0;
            for (; i < count; ++i)
                if (trackedObjects()[i].m_object == object)
                    break;
            bool present = i != count;
            if (flags & 1)
            {
                if (!present)
                {
                    hkWrittenObjectQ& entry = trackedObjects().expandOne();
                    entry.m_class = type;
                    entry.m_object = object;
                }
            }
            else if (present)
                trackedObjects().removeAt(i);
        }
        break;
    }
    }
}
