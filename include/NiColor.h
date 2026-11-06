#pragma once
#include <stddef.h>

class NiStream;

class NiColor
{
  public:
    float r;
    float g;
    float b;

    NiColor();
    NiColor(float red, float green, float blue);

    NiColor operator+(const NiColor& color) const;
    NiColor operator*(float scalar) const;
    NiColor& operator+=(const NiColor& color);
    NiColor& operator*=(float scalar);

    void Clamp();
    void Scale();
    void LoadBinary(NiStream& stream);
    void LoadBinary(NiStream* stream);
    void SaveBinary(NiStream& stream);
    void SaveBinary(NiStream* stream);
    char* FormatToBuffer(char* buffer);
    char* GetFormattedString(const char* prefix) const;
    float Luminance();
    void __dflt_ctor_closure();

    static void LoadBinary(NiStream* stream, NiColor* colors, unsigned int count);
    static void SaveBinary(NiStream* stream, NiColor* colors, unsigned int count);
    static void* operator new[](size_t size);
};
