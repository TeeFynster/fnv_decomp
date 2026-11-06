#pragma once

// Gamebryo's RGBA colour: 16 bytes, r/g/b/a floats (Xbox debug PDB Fallout_Release_Beta.pdb; RTTI names it as a
// template argument in BSSimpleArray<NiColorA,1024>). Declarations only: a unit whose original inlines a body defines it
// out of class.
struct NiStream;

class NiColorA
{
public:
    float r;   // +0x0
    float g;   // +0x4
    float b;   // +0x8
    float a;   // +0xc

    NiColorA(float fR = 0.0f, float fG = 0.0f, float fB = 0.0f, float fA = 0.0f);

    bool operator==(const NiColorA& c) const;
    bool operator!=(const NiColorA& c) const;
    NiColorA operator+(const NiColorA& c) const;
    NiColorA operator-() const;
    NiColorA operator-(const NiColorA& c) const;
    NiColorA operator*(const NiColorA& c) const;
    NiColorA operator*(float fScalar) const;
    NiColorA operator/(const NiColorA& c) const;
    NiColorA operator/(float fScalar) const;
    NiColorA& operator+=(const NiColorA& c);
    NiColorA& operator-=(const NiColorA& c);
    NiColorA& operator*=(const NiColorA& c);
    NiColorA& operator*=(float fScalar);
    NiColorA& operator/=(const NiColorA& c);
    NiColorA& operator/=(float fScalar);
    void Clamp();

    // NiMain.lib members (Xbox PDB, NiMain.lib release+debug): LoadBinary 0x00a69800, SaveBinary 0x00a698a0,
    // GetViewerString 0x00a69720.
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);
    char* GetViewerString(const char* pPrefix) const;
};
