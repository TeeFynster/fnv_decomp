#pragma once

class hkBoolResult
{
public:
    char m_cBooleanValue;

    hkBoolResult() throw() {}
    hkBoolResult(const hkBoolResult& other)
        : m_cBooleanValue(other.m_cBooleanValue) {}
    hkBoolResult(bool value) throw()
        : m_cBooleanValue(value ? 1 : 0) {}
    operator bool() const throw() { return m_cBooleanValue != 0; }
};
