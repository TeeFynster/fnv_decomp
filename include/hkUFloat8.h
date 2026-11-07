#pragma once

class hkUFloat8
{
public:
    union
    {
        unsigned char m_value;
        unsigned char value;
    };

    void FindFloatTableIndex(const float*);
};
