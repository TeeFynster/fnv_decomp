#pragma once

class ScriptVariableInfo;

class ScriptLocalVariable
{
public:
    unsigned int uiID;
    unsigned int layoutPadding4;
    double fValue;
    bool m_bIsString;
    unsigned char layoutPadding11;
    unsigned short layoutPadding12;
    unsigned int layoutPadding14;

    ScriptLocalVariable();
    ScriptLocalVariable(ScriptVariableInfo* variable);
};
