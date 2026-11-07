
// src/gamebryo2.2/corelibs/nimain/niviewerstrings.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niviewerstrings.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* __cdecl NiMalloc(size_t);
extern "C" int __cdecl NiSprintf(char* buf, int size, const char* fmt, ...);
extern "C" size_t __cdecl strlen(const char*);

// Allocates len+5 bytes and formats "%s = %c" from str and c into the new buffer, returning it.
// @fnv 0x00a7d3d0
void* __cdecl FormatStringAssignment(const char* str, char cValue)
{
    size_t len = strlen(str);
    char* pcBuffer = static_cast<char*>(NiMalloc(len + 5));
    NiSprintf(pcBuffer, len + 5, "%s = %c", str, cValue);
    return pcBuffer;
}

extern "C" size_t strlen(const char*);

char* __cdecl NiSprintf(char* dest, unsigned int size, const char* format, ...);
void* __cdecl NiMalloc(unsigned int size);

// Allocates a buffer sized from strlen(name) plus 0xf and writes "%s = %d" with name and value into it, returning the buffer.
// @fnv 0x00a7d4d0
// src: XBOX_PDB 0x00a7d4d0
char* __cdecl NiGetViewerString_00a7d4d0(const char* name, int value)
{
    size_t len = strlen(name);
    char* buf = static_cast<char*>(NiMalloc(len + 0xf));
    NiSprintf(buf, len + 0xf, "%s = %d", name, value);
    return buf;
}

namespace fnv_00a7d5e0 {
int __cdecl NiSprintf(char*, unsigned int, char const*, ...);
void* _NiMalloc(unsigned int);

// Allocates a buffer and formats "name = value" (or "name = NULL" when value is null), returning the buffer.
// @fnv 0x00a7d5e0
// src: XBOX_PDB 0x00a7d5e0
char* NiGetViewerString_00a7d5e0(char const* name, char const* value)
{
    if (value)
    {
        unsigned int len = strlen(name) + strlen(value) + 4;
        char* buf = static_cast<char*>(_NiMalloc(len));
        NiSprintf(buf, len, "%s = %s", name, value);
        return buf;
    }
    else
    {
        unsigned int len = strlen(name) + 8;
        char* buf = static_cast<char*>(_NiMalloc(len));
        NiSprintf(buf, len, "%s = NULL", name);
        return buf;
    }
}
}  // namespace fnv_00a7d5e0

// Allocates strlen(str)+9 bytes with NiMalloc and formats "--- %s ---" into it, returning the buffer.
// @fnv 0x00a7d330
// src: COMMUNITY 0x00a7d330
char* NiViewerStrings_NiGetViewerString_Title(const char* pcText)
{
    unsigned int size = strlen(pcText) + 9;
    char* buf = (char*)NiMalloc(size);
    NiSprintf(buf, size, "--- %s ---", pcText);
    return buf;
}

// Allocates a buffer sized to the name plus 9 and formats it as "name = true" or "name = false" depending on value, returning the buffer.
// @fnv 0x00a7d370
// src: XBOX_PDB 0x00a7d370
char* NiGetViewerString(const char* name, bool value)
{
    int size = (int)strlen(name) + 9;
    char* buf = (char*)NiMalloc(size);
    if (value)
        NiSprintf(buf, size, "%s = true", name);
    else
        NiSprintf(buf, size, "%s = false", name);
    return buf;
}

// Formats str and value into a newly allocated buffer as "%s = %u" and returns it.
// @fnv 0x00a7d410
// src: XBOX_PDB 0x00a7d410
char* __cdecl NiGetViewerString_00a7d410(const char* pcName, unsigned char value)
{
    int len = strlen(pcName);
    char* buf = (char*)NiMalloc(len + 7);
    NiSprintf(buf, len + 7, "%s = %u", pcName, value);
    return buf;
}

void* __cdecl _NiMalloc(unsigned int);
int __cdecl _NiSprintf(char*, unsigned int, const char*, ...);
// Allocates a buffer sized to the string plus 10, formats "str = value" into it with _NiSprintf, and returns the buffer.
// @fnv 0x00a7d450
// src: XBOX_PDB 0x00a7d450
char* __cdecl NiGetViewerString_00a7d450(const char* pcName, short value)
{
    unsigned int size = strlen(pcName) + 10;
    char* buf = (char*)_NiMalloc(size);
    _NiSprintf(buf, size, "%s = %hd", pcName, value);
    return buf;
}

// Allocates a buffer sized for name plus 9 bytes and writes "name = value" into it with the given unsigned short value, returning the buffer.
// @fnv 0x00a7d490
// src: XBOX_PDB 0x00a7d490
char* __cdecl NiGetViewerString_00a7d490(const char* name, unsigned short value)
{
    int size = strlen(name) + 9;
    char* buf = (char*)NiMalloc(size);
    NiSprintf(buf, size, "%s = %hu", name, value);
    return buf;
}

void* __cdecl _NiMalloc(unsigned int);
int __cdecl _NiSprintf(char*, unsigned int, const char*, ...);
// Allocates a buffer sized to the string length plus 14 and formats "%s = %u" from the string and unsigned value into it, returning the buffer.
// @fnv 0x00a7d510
// src: XBOX_PDB 0x00a7d510
char* __cdecl NiGetViewerString_00a7d510(const char* a, unsigned int uiValue)
{
    unsigned int len = strlen(a) + 14;
    char* buf = (char*)_NiMalloc(len);
    _NiSprintf(buf, len, "%s = %u", a, uiValue);
    return buf;
}

// Allocates a buffer sized to str plus 20 bytes and writes "str = val" into it with %g formatting, returning the buffer.
// @fnv 0x00a7d550
// src: XBOX_PDB 0x00a7d550
char* __cdecl NiGetViewerString_00a7d550(const char* str, float fValue)
{
    unsigned int size = strlen(str) + 20;
    char* buf = (char*)NiMalloc(size);
    NiSprintf(buf, size, "%s = %g", str, fValue);
    return buf;
}

void* __cdecl _NiMalloc(unsigned int);
int __cdecl _NiSprintf(char*, unsigned int, const char*, ...);
// Allocates a buffer sized to the name plus 16 bytes and formats "name = pointer" into it, returning the buffer.
// @fnv 0x00a7d5a0
// src: XBOX_PDB 0x00a7d5a0
char* __cdecl NiGetViewerString_00a7d5a0(const char* name, void* value)
{
    unsigned int len = strlen(name) + 16;
    char* buf = (char*)_NiMalloc(len);
    _NiSprintf(buf, len, "%s = %p", name, value);
    return buf;
}
