
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __cdecl FUN_00eccbdc(int, int);

// @fnv 0x00aa2d10
// src: COMMUNITY 0x00aa2d10
int NiPath_GetCurrentWorkingDirectory(int aiValue1, int aiValue2)
{
    int r = FUN_00eccbdc(aiValue1, aiValue2);
    r = !r;
    r = !r;
    return r;
}

extern "C" int __cdecl NiStrnicmp(const char* a, const char* b, unsigned int n);
extern "C" char* __cdecl FUN_00ec7690(const char* s, int c);
extern "C" int __cdecl FUN_00eca7f4(int c);

extern char str_010a2564[];
extern char DAT_01013444[];

// Skips a leading drive letter or path prefix in s and returns the pointer past it.
// @fnv 0x00aa2c50
char* __cdecl SkipPathPrefix(char* szPath)
{
    if (NiStrnicmp(szPath, str_010a2564, 2) == 0)
    {
        return FUN_00ec7690(szPath + 2, 0x5c) + 1;
    }
    if (NiStrnicmp(szPath, DAT_01013444, 1) == 0)
    {
        goto skip;
    }
    {
        char c = (char)FUN_00eca7f4(szPath[0]);
        if (szPath[1] != ':' || (unsigned char)(c - 0x41) > 0x19)
        {
            goto done;
        }
    }
    szPath += 2;
    if (*szPath != 0x5c)
    {
        goto done;
    }
skip:
    szPath++;
done:
    return szPath;
}

#include <string.h>
int __cdecl FUN_00eca7f4(int);
// Returns false for slash-prefixed paths or a drive letter followed by a colon in the first two characters; otherwise true.
// @fnv 0x00aa2cc0
// src: GUESS 0x00aa2cc0 (confidence: medium)
bool __cdecl Path_IsRelative(const char* pcPath)
{
    char c1stChar;
    char c2ndChar;
    unsigned int uiLen;
    uiLen = strlen(pcPath);
    if (uiLen < 2)
        return true;
    c1stChar = pcPath[0];
    if (c1stChar == '\\' || c1stChar == '/')
        return false;
    c1stChar = (char)FUN_00eca7f4(c1stChar);
    c2ndChar = pcPath[1];
    if (c2ndChar != ':' || (unsigned char)(c1stChar - 'A') > 25)
        return true;
    return false;
}
