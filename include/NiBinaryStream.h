#pragma once

class NiBinaryStream
{
  public:
    typedef unsigned int (__cdecl* NIBINARYSTREAM_READFN)(NiBinaryStream*, void*, unsigned int,
                                                         unsigned int*, unsigned int);
    typedef unsigned int (__cdecl* NIBINARYSTREAM_WRITEFN)(NiBinaryStream*, const void*, unsigned int,
                                                          unsigned int*, unsigned int);
    typedef NIBINARYSTREAM_READFN ReadFunction;
    typedef NIBINARYSTREAM_READFN ReadFunc;
    typedef NIBINARYSTREAM_READFN ReadFn;
    typedef NIBINARYSTREAM_READFN READFUNC;
    typedef NIBINARYSTREAM_WRITEFN WriteFunction;
    typedef NIBINARYSTREAM_WRITEFN WriteFn;
    typedef NIBINARYSTREAM_WRITEFN WRITEFUNC;
    typedef NIBINARYSTREAM_READFN Transfer;

    NiBinaryStream();
    virtual ~NiBinaryStream();
    virtual operator bool();
    virtual void Seek(int iNumBytes);
    virtual unsigned int GetPosition();
    virtual void SetEndianSwap(bool bDoSwap);

    operator bool() const;
    bool FileIsGood();
    void Seek(int iOffset, int iWhence);
    unsigned int GetPosition() const;
    unsigned int GetFileSize() const;
    unsigned int ReadIntoBuffer(void* pvBuffer, unsigned int uiBytes);
    unsigned int WriteFromBuffer(const void* pvBuffer, unsigned int uiBytes);
    void* __thiscall Destroy(unsigned int fFree);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes);
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents = 1);
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, int* puiComponentSizes,
                            unsigned int uiNumComponents);
    template <class T> unsigned int BinaryRead(T* pvBuffer, unsigned int auiCount = 1);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents);
    void BinaryWrite(const void* pvBuffer, unsigned int uiBytes, unsigned int uiComponentSize);

    template <class T> void Read(T& value);
    void Read(void* data);
    void Read(float* values);
    unsigned int Read(void* buffer, unsigned int bytes);
    unsigned int Read(void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int componentCount);
    template <class T> void ReadScalar(T& value);
    void ReadScalar(void* value, unsigned int size);
    void ReadFloat(float& value);
    void ReadUInt(unsigned int& value);
    void ReadComp(void* value, unsigned int size, unsigned int componentSize);
    void ReadGroupId(unsigned int* id);
    unsigned int ReadRaw(void* out, unsigned int n, unsigned int* size);

    void Write(void* buffer);
    void Write(const void* data);
    void Write(float* value);
    void Write(void* buffer, unsigned int bytes);
    unsigned int Write(const void* buffer, unsigned int bytes);
    void Write(const void* pv, unsigned int uiBytes, unsigned int uiComponentSize);
    unsigned int Write(const void* buffer, unsigned int bytes, unsigned int* componentSizes,
                       unsigned int componentCount);
    void WriteSpawnFlag(const bool& onDeath);
    unsigned int GetLine(char* buffer, unsigned int maxChars);

    // Gamebryo 2.2 NiBinaryStream members (ctor 0x00aa1d10 clears +4/+8/+C; GetPosition 0x00aa1d50 returns +4;
    // NiFile::SetEndianSwap 0x00aa1b30 and NiMemStream::SetEndianSwap 0x00aa2f80 install the reader at +8 and the
    // writer at +C; the inline BinaryRead/BinaryWrite call through them and add the byte count to +4).
    unsigned int m_uiAbsoluteCurrentPos; // +0x04
    NIBINARYSTREAM_READFN m_pfnRead;     // +0x08
    NIBINARYSTREAM_WRITEFN m_pfnWrite;   // +0x0C
};
