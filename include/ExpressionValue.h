#pragma once

// Natural (8-byte) alignment: Eval (0x00593db0) places ExpressionValue locals on 8-byte stack slots.
class ExpressionValue
{
public:
    char Type;
    unsigned char layoutPadding1;
    unsigned short layoutPadding2;
    unsigned int layoutPadding4;
    union
    {
        long m_lIntegerValue;
        double m_dFloatingPointValue;
    };
};
