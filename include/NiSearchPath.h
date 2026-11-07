#pragma once

class NiSearchPath
{
public:
    NiSearchPath();
    virtual ~NiSearchPath();
    virtual void Reset_00aa2500();
    virtual bool ResolveSearchPath(char* pcPath, unsigned int uiStringLen);

    unsigned int m_uiSearchPathValue;
    char m_acFilePathBuffer[260];
    char m_acResolvedPath[260];

    void SetPath(const char* pcFilePath);
    static void operator delete(void* p);
};
