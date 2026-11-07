
// src/gamebryo2.2/corelibs/nisystem/nipath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/nipath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <string.h>
// Converts forward slashes to backslashes, removes repeated backslashes after the first two characters, and returns whether either change occurred.
// @fnv 0x00aa2a00
// src: GAMEBRYO_LIB 0x00aa2a00
bool NiPath_Standardize(char* path)
{
    bool changed = false;
    if (!path)
        return changed;
    unsigned int len = strlen(path);
    bool prevSlash = false;
    unsigned int out = 0;
    for (unsigned int i = 0; i < len; i++)
    {
        char cChar = path[i];
        if (cChar == '/')
        {
            changed = true;
            cChar = 0x5c;
        }
        bool isSlash = (cChar == 0x5c);
        if (isSlash && prevSlash && i > 1)
        {
            changed = true;
        }
        else
        {
            path[out] = cChar;
            prevSlash = isSlash;
            out++;
        }
    }
    path[out] = 0;
    return changed;
}

char* __cdecl FUN_00ec7750(char*, const char*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
// Replaces each backslash-dot-backslash sequence with a backslash by shifting the tail left, then rescans.
// @fnv 0x00aa2a70
void __cdecl RemoveDotSlash(char* pcPath)
{
    const char acSlashDotSlash[4] = "\\.\\";
    char* pcDotSlash = FUN_00ec7750(pcPath, acSlashDotSlash);
    while (pcDotSlash)
    {
        const char* pcAfterDot = pcDotSlash + 2;
        unsigned int uiLen = strlen(pcDotSlash);
        _strcpy_s(pcDotSlash, uiLen, pcAfterDot);
        pcDotSlash = FUN_00ec7750(pcPath, acSlashDotSlash);
    }
}

namespace fnv_00aa2ac0 {
void __cdecl NiPath_Standardize(char*);
void __cdecl RemoveDotSlash(char*);
char __cdecl Path_IsRelative(char*);
char* __cdecl SkipPathPrefix(char*);

// Runs path helpers, then removes each `\..` occurrence and its preceding path component.
// @fnv 0x00aa2ac0
void __cdecl RemoveParentDirSegments(char* path)
{
    NiPath_Standardize(path);
    RemoveDotSlash(path);
    if (Path_IsRelative(path))
    {
        if (!path)
            return;
        while (*path == '.' || *path == '\\')
        {
            ++path;
            if (!path)
                return;
        }
    }
    else
    {
        path = SkipPathPrefix(path);
    }
    if (!path)
        return;
    char* end = path + strlen(path) + 1;
    unsigned int pattern = 0x002e2e5c;
    char* found = strstr(path, (char*)&pattern);
    while (found)
    {
        *found = 0;
        char* dst = strrchr(path, '\\');
        if (dst)
        {
            found += 3;
        }
        else
        {
            if (found + 3)
                found += 4;
            else
                found = 0;
            dst = path;
        }
        int remaining = (int)end - (int)found;
        if (remaining > 0)
        {
            int shift = (int)found - (int)dst;
            do
            {
                *dst = dst[shift];
                ++dst;
                --remaining;
            } while (remaining);
        }
        found = strstr(path, (char*)&pattern);
    }
}
}  // namespace fnv_00aa2ac0

void __cdecl RemoveParentDirSegments(char* pcPath);

// Concatenates pcRelativeToHere, a backslash if needed, and pcRelativePath into pcAbsolutePath, normalises it via RemoveParentDirSegments, and returns its length.
// @fnv 0x00aa2ba0
size_t __cdecl BuildAbsolutePath(char* pcOutPath, size_t stOutSize, const char* pcRelativePath, const char* pcBasePath)
{
    size_t stBaseLen = strlen(pcBasePath);
    size_t stRelLen = strlen(pcRelativePath);
    bool bAppendSlash = (pcBasePath[stBaseLen - 1] != '\\');
    size_t stTotalLen = stBaseLen + (bAppendSlash ? 1 : 0) + stRelLen + 1;
    if (stOutSize < stTotalLen)
    {
        if (stOutSize > 0)
            pcOutPath[0] = 0;
        return 0;
    }
    strcpy_s(pcOutPath, stOutSize, pcBasePath);
    if (bAppendSlash)
        strcat_s(pcOutPath, stOutSize, "\\");
    strcat_s(pcOutPath, stOutSize, pcRelativePath);
    RemoveParentDirSegments(pcOutPath);
    return strlen(pcOutPath);
}
