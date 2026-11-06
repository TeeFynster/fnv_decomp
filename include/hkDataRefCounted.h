#pragma once

// Havok 7.1 hkDataRefCounted: RTTI .?AVhkDataRefCounted@@, vftable 0x010d62f4 (1 slot, the destructor 0x00dbbe50).
// 12 bytes: the class allocator records the allocation size at +4 and the reference count is at +8 (hkDataClassNative,
// 0x14 bytes, keeps its hkClass* at +0xc).
// src: HAVOK_SRC (hkDataObjectImpl.h: hkDataRefCounted members and reference counting)
class hkDataRefCounted
{
public:
    virtual ~hkDataRefCounted();

    // class allocator: bodies come from the units (the dictionary units inline it)
    static void* operator new(unsigned int size);
    static void operator delete(void* p);

    void addReference() const
    {
        ++m_count;
    }
    void removeReference() const
    {
        if (--m_count == 0)
            delete this;
    }

    mutable unsigned short m_memSize;  // +0x04
    mutable short m_externalCount;     // +0x06
    mutable int m_count;               // +0x08
};

typedef char hkDataRefCounted_size_check[(sizeof(hkDataRefCounted) == 12) ? 1 : -1];
