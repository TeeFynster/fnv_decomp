#pragma once

typedef unsigned short hkUint16;

class hkpEntitySmallArraySerializeOverrideType
{
public:
    void* m_data;
    hkUint16 m_iElementCount;
    hkUint16 m_iCapacityState;
};
