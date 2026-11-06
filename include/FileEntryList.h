#pragma once

class BSFileEntry;
class ContainerItemExtra;
class FileFormCollection;
class TESFile;
class TESForm;

class FileEntryList
{
public:
    FileEntryList();
    ~FileEntryList();

    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm*, char*);
    void Load(TESFile*, TESForm*, const char*);
    void Copy(FileEntryList*);
    void Copy(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
#if !defined(_MSC_VER)
    void* __vecDelDtor(unsigned int);
#endif

    unsigned char m_ucFileEntryCount;
    union
    {
        unsigned char layoutPadding1[3];
    };
    BSFileEntry** m_ppFileEntries;
};

