#pragma once

class NiStream;
class SkinStream;

class NiSphere
{
public:
    float x;
    float y;
    float z;
    float r;

    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);
    void SaveBinary(SkinStream& stream);
};
