#pragma once

template <class T> class NiRect
{
  public:
    char* ToString(const char* prefix) const; // float specialization: exe 0x00a71020
    T m_fMinimumU;
    T m_fMaximumU;
    T m_fMinimumV;
    T m_fMaximumV;
};
