#pragma once

class TypedData
{
public:
    char eType;
    unsigned char m_ucFirstByteAfterType;
    unsigned char iOtherSignFlags;
    unsigned char m_ucPayloadByte3;
};
