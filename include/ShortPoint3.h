#pragma once

#include "NiStream.h"

class ShortPoint3
{
public:
    short x;
    short y;
    short z;

    static ShortPoint3 ComponentProduct(const ShortPoint3&, const ShortPoint3&);
    float Length();
    short SqrLength();
    ShortPoint3* SetComponents(void*);
    short Dot(const ShortPoint3&);
    ShortPoint3 Cross(const ShortPoint3&);
    float GetFloatX();
    float GetFloatY();
    float GetFloatZ();
    void SetFloatX(float);
    void SetFloatY(float);
    void SetFloatZ(float);
    static const ShortPoint3& GetZERO();
    static const ShortPoint3& GetUNIT_X();
    static const ShortPoint3& GetUNIT_Y();
    static const ShortPoint3& GetUNIT_Z();
    static const ShortPoint3& GetUNIT_ALL();
    void LoadBinary(NiStream*);
    void LoadBinary(NiStream&);
    void SaveBinary(NiStream*);
    void SaveBinary(NiStream&);
    char* FormatToBuffer(char*);
    char* FormatToBuffer(const char*);
};
