#pragma once

#include "IDebugText.h"
#include "NiColorA.h"

class DebugText : public IDebugText
{
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void __cdecl Print(DEBUGTEXT_LOCATION location, DEBUGTEXT_JUSTIFY justify, const char* format, ...);
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();

    int m_lines[0x861];

    static DebugText* __cdecl Instance(bool);
    static void ClearDebugText();
    static void DebugText_AddFloatingText(void*, const char*, int, float);

    int Print(const char*, float, float, int, int, float, int, const NiColorA* = 0);
    void UpdateLayoutPositions();
    void __thiscall AddScaledValue(int aiIndex, int aiMultiplier);
    int PrintFormattedLine(int iX, int iLine, int iFlags, const char* pcFormat, char* pArgs, const NiColorA* pkColor);
    int PrintFormattedAtSlot(int iSlot, int m_iPayloadInteger, const char* pcFormat, char* pArgs, const NiColorA* pkColor);
    int FindDebugTextResult(float fX, float fY, int iFlags);
    bool GetDebugText_0(char*, float, float, int);
    int GetEntry(int);
    void __thiscall SetLine(DEBUGTEXT_LOCATION aeLoc, int aiLine);
};
