#pragma once

#include "BSFile.h"

class Archive;

class ArchiveFile : public BSFile
{
public:
    ArchiveFile(const char* name, Archive* archive, unsigned int offset,
                unsigned int size, int mode);
    ArchiveFile(unsigned int name, Archive* archive, unsigned int offset,
                unsigned int size, unsigned int mode);
    virtual ~ArchiveFile();
    virtual void SetEndianSwap(bool doSwap);

    Archive* GetArchive() { return m_pArchive; }
    void LockArchive(char* name);
    void UnlockArchive();
    unsigned int GetTruePos();
    unsigned int GetPos() const;
    void LockArc(const char* name);
    unsigned int ReadFromArchive(void* buffer, unsigned int size);
    unsigned int ReadAtOffset(char* output, unsigned int size, unsigned int offset);
    unsigned int ReadAtOffset(char* output, unsigned int size, int offset);
    unsigned int ReadAtOffset(void* output, unsigned int size, int offset);

    void FUN_00afb520();
    void FUN_00afb5f0(int, int);
    void ArchiveFile_Seek(int byteCount, int seekFlags);
    int ArchiveFile_ReadF(void* buffer, unsigned int count);
    int ArchiveFile_ReadF(int buffer, int count);
    unsigned int ArchiveFile_Read(void* buffer, unsigned int size);
    unsigned int ArchiveFile_WriteF(void* buffer, unsigned int size);
    void FUN_00afbfa0(int);
    int ArchiveFile_ReadFromBuffer(void* buffer, unsigned int count);

    Archive* m_pArchive;
    unsigned int m_uiFileIndex;
};
