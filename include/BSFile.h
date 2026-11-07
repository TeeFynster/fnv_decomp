#pragma once

#include "NiFile.h"
#include <stddef.h>

template <class T> class BSStringT;

class BSFile : public NiFile
{
public:
    BSFile(const char*, int, unsigned int, bool);
    BSFile(const char*, bool, unsigned int, bool);
    BSFile(const char*, NiFile::OpenMode, unsigned int, bool);
    virtual ~BSFile();

    virtual void SetEndianSwap(bool bDoSwap);
    using NiFile::Seek;
    virtual void Seek(int iOffset, int iWhence); // 0x14
    virtual char* FileName();
    virtual unsigned int GetFileSize();

    virtual bool Open(bool, bool); // 0x20
    virtual bool AttachFileStream(_iobuf*);
    virtual unsigned int GetSize();
    virtual unsigned int Read(BSStringT<wchar_t>&, unsigned int);
    virtual unsigned int Read(BSStringT<char>&, unsigned int);
    virtual unsigned int GetLine(char*, unsigned int, wchar_t);
    virtual unsigned int Write(const BSStringT<wchar_t>&, bool);
    virtual unsigned int Write(const BSStringT<char>&, bool);
    virtual bool Exist();
    virtual unsigned int ReadRawData(void*, unsigned int);
    virtual unsigned int WriteRawData(const void*, unsigned int);

    void Close();
    void CheckIsGood();
    bool SetBufferSize(unsigned int auiSize);
    bool NeedCache();
    bool Good() const;
    bool IsGood();
    bool IsOpen();
    bool Write();
    unsigned int Read(void*, unsigned int);
    unsigned int BinaryRead(void*, unsigned int, unsigned int*, unsigned int = 1);
    bool AttachFileStream(bool, bool);
    unsigned int GetFilePosition();
    unsigned int GetBufferValue();
    char* FileName() const;
    void SetEndian(int, unsigned int);
    void SeekFrom(int iOffset, int iWhence);
    void Write(const char*, int);

    int NiBinaryStream_Write(const char*, unsigned int);
    void NiBinaryStream_Write(const void*, unsigned int);
    bool TESAnimGroup_GetDecal();
    void FUN_00aff300(int, int);
    bool FUN_00aff300(bool, bool);
    void FUN_00aff7c0(BSStringT<char>*, int);
    void BSFile_WriteF(char*, unsigned int);
    unsigned int BSFile_WriteF(const char*, unsigned int);
    unsigned int BSFile_WriteF(const void*, unsigned int);
    void BSFile_Write_00affbb0(void*, int);
    void FUN_00affd10();

    static void* operator new(size_t size);
    static void operator delete(void*);

    bool m_bIsOpen;
    bool m_bEndianSwap;
    unsigned char unk32[2];
    char* m_pFileBuffer;
    int m_iBufferSize;
    unsigned int m_uiFileSize;
    unsigned int m_uiFilePosition;
    char pFileName[260];
    int iResult;
    unsigned int m_uiBufferPosition;
    unsigned int m_uiBufferSize;
    unsigned int m_uiValueId;
};
