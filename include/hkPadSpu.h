#pragma once

// Havok 7.1 Common/Base/Types/hkBaseTypes.h: hkPadSpu<TYPE> wraps a structure member (16 bytes on the PS3 SPU; on PC
// a bare TYPE m_storage). Its methods are HK_FORCE_INLINE in Havok.
// src: HAVOK_SRC (shape): class name, member name and the forceinline accessor set
template <typename TYPE>
class hkPadSpu
{
public:
    __forceinline hkPadSpu() {}
    __forceinline hkPadSpu(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return val(); }

    // private in Havok; public here because some units read and write the stored value directly
    TYPE m_storage;
};
