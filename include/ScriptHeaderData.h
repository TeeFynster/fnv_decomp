#pragma once

class ScriptHeaderData
{
public:
    unsigned int variableCount;
    unsigned int m_uiReferenceID;
    unsigned int dataSize;
    unsigned int m_uiDataOffset;
    bool m_bQuest;
    bool m_bEffect;
    bool m_bCompiled;

    void Endian();
};
