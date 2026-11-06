#pragma once

// src: HAVOK_SRC (class name, member name m_value)
class hkHalf
{
public:
    short m_value;

    hkHalf()
    {}

    hkHalf(float f)
    {
        int t = *(int*)&f;
        m_value = (short)(t >> 16);
    }

    __forceinline operator float() const
    {
        union
        {
            int i;
            float f;
        } u;
        u.i = (m_value << 16);
        return u.f;
    }
};
