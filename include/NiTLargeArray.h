#pragma once

// the allocator policies are only template arguments here (several shared headers still define their own
// NiTMallocInterface / NiTNewInterface); include/NiTMallocInterface.h and NiTNewInterface.h hold the definitions
template <class T> class NiTMallocInterface;
template <class T> class NiTNewInterface;

// Gamebryo 2.2 NiTLargeArray.h: NiTArray with unsigned int counts. RTTI: NiTLargeArray<T, TAlloc> (no bases), one
// vftable slot (destructor); 0x18 bytes (object_sizes.csv: NiTLargeArray<TESForm *,...> ctor fields end at 0x18;
// TopicInfoArray derives from NiTLargePrimitiveArray<TESTopicInfo *>): vtable, m_pBase 4, m_uiMaxSize 8,
// m_uiSize 0xc, m_uiESize 0x10, m_uiGrowBy 0x14.
// Bodies: as in NiTArray.h, units define the ones they need out of class.
template <class T, class TAlloc> class NiTLargeArray
{
  public:
    NiTLargeArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1);
    virtual ~NiTLargeArray();

    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;

    // the units that shared this class first (TopicInfoArray.h users such as testopic.cpp) call the non-const
    // GetSize and Add(T&), bound to the exe's single const forms; Gamebryo declares only GetSize() const, Add(const T&)
    unsigned int GetSize();
    unsigned int GetSize() const;
    unsigned int GetEffectiveSize() const;
    unsigned int GetAllocatedSize() const;
    unsigned int GetGrowBy() const;
    void SetGrowBy(unsigned int uiGrowBy);
    T* GetBase();
    T& GetAt(unsigned int uiIndex);
    const T& GetAt(unsigned int uiIndex) const;
    void SetAt(unsigned int uiIndex, const T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element);
    unsigned int Add(T& element);
    unsigned int Add(const T& element);
    unsigned int AddFirstEmpty(const T& element);
    T RemoveAt(unsigned int uiIndex);
    T RemoveAtAndFill(unsigned int uiIndex);
    T RemoveEnd();
    void RemoveAll();
    unsigned int Remove(const T& element);
    void Compact();
    void UpdateSize();
    void SetSize(unsigned int uiMaxSize);
};
