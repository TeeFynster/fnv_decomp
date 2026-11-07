#pragma once

#include "QueuedFile.h"

class BSFile;
class BSFileEntry;

class QueuedFileEntry : public QueuedFile
{
public:
    QueuedFileEntry(int priority);
    virtual ~QueuedFileEntry();
    virtual void GenerateKey();
    virtual unsigned char GetFileIndex();

    QueuedFileEntry& operator=(const QueuedFileEntry& other);
    char* GetFileName();
    void SetFileName(char* name);
    void SetFileName(const char* name);
    BSFileEntry* GetFileEntry();
    void SetFileEntry(BSFileEntry* entry);
    void LookupFileEntry(int archive);
    void LookupFileEntryByArchive(int archive);
    BSFile* GetFile(int archive, int flags);
    void GetLookupFileName(int archive, char* name);
    bool GetDescription(char* description, unsigned int bufferSize, char* prefix);
    void SetFileName_00c3cee0(const char* name);

    char* pFileName;
    BSFileEntry* m_pFileEntry;
};
