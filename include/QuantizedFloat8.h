#pragma once

class QuantizedFloat8
{
public:
    enum
    {
        MAX_VALUE = 256
    };

    QuantizedFloat8();
    QuantizedFloat8(const float f);
    QuantizedFloat8& operator=(const float& fv);
    operator float() const;
};
