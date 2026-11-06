#pragma once

class NiFilename
{
public:
    union
    {
        char m_acDir[256];
        char m_acFolderPath[256];
    };
    union
    {
        char m_acDrive[3];
        char m_acDriveLetter[3];
    };
    union
    {
        char m_acExt[256];
        char m_acExtension[256];
    };
    union
    {
        char m_acFname[256];
        char m_acBaseName[256];
    };
    union
    {
        char m_acSubDir[256];
        char m_acPlatformSubDir[256];
    };

    NiFilename() {}
    NiFilename(const char* pcFullPath);
    void FUN_00aa27d0(const char* pcFullPath);

    const char* GetExt() const
    {
        return m_acExt;
    }
};
