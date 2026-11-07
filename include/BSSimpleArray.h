#pragma once

typedef int (__cdecl* BSSimpleArrayCompare)(const void*, const void*);

// Bethesda BSSimpleArray<T, RESIZE_SIZE>. RTTI: no bases, 4 vftable slots, e.g. BSSimpleArray<Actor *,1024> vftable
// 0x01084fec: destructor 0x008c1c80, _Allocate 0x008225d0 (count << 2, then the allocator 0x00401000), _Deallocate
// 0x006db090 (frees through 0x00401030), _Reallocate 0x0084b630 (count << 2, then 0x0042f5d0). Buffer at 4, size at 8,
// allocated size at 0xc: 16 bytes.
template <class T, unsigned int Growth = 1024>
class BSSimpleArray
{
public:
    BSSimpleArray();
    BSSimpleArray(unsigned int capacity); // 0x0042f7d0, used by the NavMeshPtr scratch array
    virtual ~BSSimpleArray();
    virtual T* _Allocate(unsigned int count);
    virtual void _Deallocate(T* items);
    virtual T* _Reallocate(T* items, unsigned int count);

    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void ReleaseElements(T* items, unsigned int count);
    void InitializeItems(T* items, unsigned int count);

    unsigned int GetSize();
    void SetAt(unsigned int index, T& value); // exe 0x0047a110, BGSIdleCollection
    unsigned int ReserveIndex();
    unsigned int ReserveIndex(const T& value);
    T& GetAt(int index);
    T* GetAtPointer(int index); // exe: 0x00877a30 returns buffer + index*4
    T& GetAt(unsigned int index);
    T& operator[](unsigned int index);
    T& operator[](unsigned int index) const;
    unsigned int Add(T& value);
    unsigned int Add(const T& value);
    unsigned int BinarySearch(T& value, BSSimpleArrayCompare compare);
    void InsertInSortedOrder(T& value, BSSimpleArrayCompare compare);
    void Insert(unsigned int index, T& value);
    void Clear(bool freeBuffer);
    void RemoveAll(bool freeBuffer);
    void SetSize(unsigned int size, bool shrinkBuffer);
    void UpdateEntryValue(unsigned int, unsigned int);
    void UpdateEntryValue(T* destination, T* source, unsigned int count);
    void ReallocateStorage(unsigned int newCapacity, unsigned int preserveCount);
    void _InitialSetup(unsigned int capacity, unsigned int initialSize);

    template <unsigned int M>
    void CopyTo(BSSimpleArray<T, M>* destination);
    template <class U>
    unsigned int Find(U& value, unsigned int start, bool (__cdecl* compare)(T&, U&));
    unsigned int Find(const T& value, unsigned int start,
                      bool (__cdecl* compare)(const T&, const T&));

    void BSSimpleArray_float_1024_InitialSetup(unsigned int, bool);
    void BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(unsigned int, bool);
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() const;
    const T& GetIndexedValue_006b3160(unsigned int index) const;
    const T& BSSimpleArray_CombatMember_1024_GetAt(unsigned int index) const;
    void BSSimpleArray_NiPointer_NiAVObject_1024_Add(const T& value);
    bool BSSimpleArray_BGSBodyPart_1024_IsInArray(T& value);
    unsigned int __thiscall BSSimpleArray_AddUninitialized_0();
    unsigned int __thiscall BSSimpleArray_Add(void*& value);

    // Per-instantiation helpers whose real names are unknown (each unit binds them to its instantiation's address).
    BSSimpleArray(unsigned int, bool);
    T& Object_GetIndexedValue_006a1440(unsigned int index);
    unsigned int AppendElement(const T& value);
    unsigned int Append(const T& value);
    T& GetElement(unsigned int index);
    T& GetBufferEntry(unsigned int index);
    void Remove(unsigned int, bool);
    void AppendValue(const T&);
    T& GetBufferElementAddress(unsigned int index);
    void GrowCapacity(unsigned int capacity);
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    const T& GetLastEdge();
    const T& GetFirstElement() const;
    const T& GetLastElement() const;
    void RemoveAt(unsigned int index, unsigned int count);
    void RemoveAt(unsigned int, bool);
};
