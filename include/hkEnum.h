#pragma once

// src: XBOX_PDB (hkEnum<hkpMotion::MotionType,unsigned char>, sizeof 1).
// The exe constructors store only STORAGE at offset zero; no bases or vtable.
class hkBool;

template <typename ENUM, typename STORAGE>
class hkEnum
{
public:
#ifdef FNV64_HKENUM_INLINE_BODIES
#ifdef FNV64_HKENUM_FORCEINLINE
    __forceinline hkEnum() {}
    __forceinline hkEnum(ENUM value) { m_kStorage = static_cast<STORAGE>(value); }
#else
    hkEnum() {}
    hkEnum(ENUM value) { m_kStorage = static_cast<STORAGE>(value); }
#endif
#else
    hkEnum();
    hkEnum(ENUM value);
#endif
    operator ENUM() const { return static_cast<ENUM>(m_kStorage); }
    void operator=(ENUM value) { m_kStorage = static_cast<STORAGE>(value); }
#ifdef FNV64_HKENUM_COMPARISONS
    __forceinline hkBool operator==(ENUM value) const { return m_kStorage == static_cast<STORAGE>(value); }
    __forceinline hkBool operator!=(ENUM value) const { return m_kStorage != static_cast<STORAGE>(value); }
#endif

    union
    {
        STORAGE m_kStorage;
        STORAGE m_storage;
    };
};
