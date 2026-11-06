#pragma once

#include "NiTMallocInterface.h"
#include "NiTNewInterface.h"

// A contiguous set; allocator policy affects ownership, not the three-word layout.
template <class Element, class Policy> class NiTSet
{
public:
    NiTSet(unsigned int reserveCount = 0);
    ~NiTSet();

    // Read the occupied range or address an entry.
    Element* GetBase() const;
    const Element& GetAt(unsigned int slot) const;
    Element& GetAt(unsigned int slot);
    unsigned int GetSize() const;
    int Find(const Element& sought) const;

public:
    // Changes to entries and storage are defined by the consuming unit.
    void Realloc(unsigned int reserveCount);
    void Realloc();
    void Add(Element& incoming);
    void Add(const Element& incoming);
    unsigned int AddUnique(const Element& incoming);
    void ReplaceAt(unsigned int slot, const Element& incoming);
    void RemoveAll();
    void OrderedRemoveAt(unsigned int slot);
    void RemoveAt(unsigned int slot);

public:
    Element* m_pBase; // src: GAMEBRYO_SRC (shape)
    union // src: GAMEBRYO_SRC (shape)
    {
        unsigned int m_uiAlloced; // src: GAMEBRYO_SRC (shape)
        unsigned int m_uiElementCount; // src: GAMEBRYO_SRC (shape)
    };
    union // src: GAMEBRYO_SRC (shape)
    {
        unsigned int m_uiUsed; // src: GAMEBRYO_SRC (shape)
        unsigned int m_uiAllocatedCapacity; // src: GAMEBRYO_SRC (shape)
    };
};

template <class Element> class NiTObjectSet : public NiTSet<Element, NiTNewInterface<Element> >
{
public:
    NiTObjectSet(unsigned int reserveCount = 0);
};
