#pragma once

class hkBool
{
public:
    typedef char CompileTimeTrueType;
    typedef int CompileTimeFalseType;

    char m_cBooleanValue;

    inline hkBool() {}
    inline hkBool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    inline hkBool(char b) { m_cBooleanValue = b; }
    inline operator bool() const { return m_cBooleanValue != 0; }
    inline hkBool& operator=(bool b) { m_cBooleanValue = static_cast<char>(b); return *this; }
};
