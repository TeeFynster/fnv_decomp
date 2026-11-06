#pragma once

class BSString
{
public:
    char* m_data;
    unsigned short m_bufLen;
    unsigned short m_dataLen;

    BSString();
    BSString(unsigned int len);
    ~BSString();

    void SetDataLen(unsigned int len)
    {
        m_dataLen = (len <= 0xffff) ? (unsigned short)len : 0xffff;
    }

    void SetBufLen(unsigned int len)
    {
        m_bufLen = (len <= 0xffff) ? (unsigned short)len : 0xffff;
    }

    unsigned int GetMaxLength() const
    {
        return m_dataLen;
    }

    bool Set(const char* text, unsigned int requested);
    int Sprintf(const char* fmt, ...);
    int PrintfString(const char*, ...);
    unsigned int Length();

    const char* CStr()
    {
        return m_data;
    }

    operator const char*() const;
};
