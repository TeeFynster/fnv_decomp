#pragma once

#include "ArchiveFile.h"

class CompressedArchiveFile : public ArchiveFile
{
public:
    CompressedArchiveFile(const char* fileName, Archive* archive, unsigned int offset,
                          unsigned int size, int mode);
    CompressedArchiveFile(unsigned int fileName, Archive* archive, unsigned int offset,
                          unsigned int size, unsigned int mode);

    virtual ~CompressedArchiveFile();
    virtual void SetEndianSwap(bool doSwap);
    virtual void Seek(int offset, int mode);

    void DestroyCompressedArchiveFile();
    bool CompressedArchiveFile_Open(bool a1, bool a2);
    void FUN_00aa15a0();
    unsigned int ReadAtOffset(void* buffer, unsigned int size, int mode);
    unsigned int CompressedArchiveFile_ReadF(char* buffer, unsigned int size);
    void* FUN_00afc6c0(unsigned int flags);
    void* FUN_00afc6f0(unsigned int flags);

    void* m_pArchiveStream;
    char* m_pCompressedBuffer;
    unsigned int m_uiCompressedSize;
    unsigned int m_uiUncompressedSize;
    unsigned int m_uiCompressedPosition;
    unsigned int m_uiUncompressedPosition;
};
