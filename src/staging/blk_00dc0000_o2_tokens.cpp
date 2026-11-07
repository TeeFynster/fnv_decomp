
// src/staging/blk_00dc0000_o2_tokens.cpp - staging unit created 2026-10-30 for 0x00dcc240 (flag review): blk_00dc0000_o2.cpp holds SSE helper
// classes (inline functions passing __m128 by value) that make VC9 drop the private register convention of every static
// function compiled after them; this function takes an argument in eax, so it gets a file without them.

struct S00dcc240_Stream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int Read(char* buf, int len);
    virtual void Advance(int n);
    virtual void v6();
    virtual void Mark(int n);
    virtual void Restore();
};
static __declspec(noinline) void SkipWhitespace(S00dcc240_Stream* stream)
{
    int storage[16];
    char* buffer = (char*)storage;
    stream->Mark(64);
    int count = stream->Read(buffer, 64);
    if (count)
    {
        int i;
        for (;;)
        {
            i = 0;
            for (; i < count; ++i)
            {
                char c = buffer[i];
                if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
                    goto done;
            }
            stream->Mark(64);
            count = stream->Read(buffer, 64);
            if (!count)
                return;
        }
    done:
        stream->Restore();
        stream->Advance(i);
    }
}

// Skips whitespace, then parses an optional sign and a decimal, octal, or hexadecimal integer from the stream, storing the sign in negative.
// @fnv 0x00dcc240
// src: HAVOK_LIB 0x00dcc240
static __declspec(noinline) unsigned __int64 readInteger64(S00dcc240_Stream* stream, bool* negative)
{
    int storage[64];

    SkipWhitespace(stream);
    *negative = false;
    unsigned __int64 value = 0;
    int cursor = 0;
    stream->Mark(255);
    int count = stream->Read((char*)storage, 255);
    if (count != 0)
    {
        if (((char*)storage)[0] == '+' || ((char*)storage)[0] == '-')
        {
            if (((char*)storage)[0] == '-')
                *negative = true;
            cursor = 1;
        }
        unsigned int radix;
        if (cursor + 3 < count && ((char*)storage)[cursor] == '0' &&
            (((char*)storage)[cursor + 1] == 'x' || ((char*)storage)[cursor + 1] == 'X') &&
            ((((char*)storage)[cursor + 2] >= '0' && ((char*)storage)[cursor + 2] <= '9') ||
             (((char*)storage)[cursor + 2] >= 'a' && ((char*)storage)[cursor + 2] <= 'f') ||
             (((char*)storage)[cursor + 2] >= 'A' && ((char*)storage)[cursor + 2] <= 'F')))
        {
            radix = 16;
            cursor += 2;
        }
        else if (cursor + 2 < count && ((char*)storage)[cursor] == '0' && ((char*)storage)[cursor + 1] >= '0' &&
                 ((char*)storage)[cursor + 1] <= '9')
        {
            radix = 8;
            cursor++;
        }
        else
        {
            radix = 10;
        }
        int i = cursor;
        for (; i < count; i++)
        {
            unsigned int digit = 0xffffffff;
            if (((char*)storage)[i] >= '0' && ((char*)storage)[i] <= '9')
                digit = ((char*)storage)[i] - '0';
            else if (((char*)storage)[i] > 'A' && ((char*)storage)[i] <= 'F')
                digit = ((char*)storage)[i] - '7';
            else if (((char*)storage)[i] > 'a' && ((char*)storage)[i] <= 'f')
                digit = ((char*)storage)[i] - 'W';
            if (digit >= radix)
                break;
            value = value * radix + digit;
        }
        stream->Restore();
        stream->Advance(i);
        return value;
    }
    return 0;
}
unsigned __int64 S00dcc240_Caller(S00dcc240_Stream* s, bool* neg)
{
    return readInteger64(s, neg);
}
