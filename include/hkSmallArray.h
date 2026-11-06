#pragma once

typedef unsigned short hkUint16;

// Havok 7.1 hkSmallArray<T> (Common/Base/Container/Array/hkSmallArray.h): a 14-bit array, 8 bytes
// (pointer, 16-bit size, 16-bit capacity whose top two bits are flags). The default constructor
// makes an empty array that does not own storage (DONT_DEALLOCATE_FLAG), as in hkSmallArray.inl.
// Only the inline members used so far are spelled out; the destructor and the out-of-line
// reserve/insert/remove helpers are not declared yet (nothing here destroys or grows one). The data
// members are protected in Havok; they are public here so decompiled callers can read them.
template <typename T>
class hkSmallArray
{
public:
    enum
    {
        CAPACITY_MASK = hkUint16(0x3fff),
        FLAG_MASK = hkUint16(0xC000),
        DONT_DEALLOCATE_FLAG = hkUint16(0x8000),
        LOCKED_FLAG = hkUint16(0x4000),
        FORCE_SIGNED = -1
    };

    __forceinline hkSmallArray() : m_data(0), m_size(0), m_capacityAndFlags(DONT_DEALLOCATE_FLAG) {}

    __forceinline int getSize() const { return m_size; }
    __forceinline int getCapacity() const { return m_capacityAndFlags & CAPACITY_MASK; }

    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }

    // Returns the index of the first occurrence of t, or -1 if not found.
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_size; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }

    T* m_data;
    hkUint16 m_size;
    hkUint16 m_capacityAndFlags;
};
