
// src/fallout/misc/main_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/misc/main.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "main.h"

#include <stdio.h>
int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl strcat_s(char*, unsigned int, const char*);
unsigned int __cdecl BSStringLength(const char*);
char* __cdecl FUN_00ecc104(char*, int, FILE*);
extern char DAT_01082cb8[];
class TESFile;
struct PluginListEntry
{
    void FUN_00471d00(bool);
};
struct PluginListHandler
{
    TESFile* FUN_00462f40(const char*);
};
struct Receiver86;
extern Receiver86* g_dataHandler;

struct PluginListReader
{
    bool TESMain_LoadPluginsFromFile(const char* pDir, const char* pName);
};

// @fnv 0x00872430
// src: COMMUNITY 0x00872430
bool PluginListReader::TESMain_LoadPluginsFromFile(const char* pDir, const char* pName)
{
    char acPath[260];
    char acLine[512];
    FILE* pFile;
    {
        bool m_bHeaderParsed = false;
        strcpy_s(acPath, 260, pDir);
        strcat_s(acPath, 260, pName);
        pFile = fopen(acPath, DAT_01082cb8);
        if (pFile)
        {
            while (FUN_00ecc104(acLine, 512, pFile))
            {
                unsigned int uiLen = BSStringLength(acLine);
                if (acLine[0] != '#' && uiLen > 1)
                {
                    if (acLine[uiLen - 1] == '\n')
                        acLine[uiLen - 1] = 0;
                    TESFile* m_pFileEntry = ((PluginListHandler*)g_dataHandler)->FUN_00462f40(acLine);
                    if (m_pFileEntry)
                    {
                        ((PluginListEntry*)m_pFileEntry)->FUN_00471d00(true);
                        m_bHeaderParsed = true;
                    }
                }
            }
            fclose(pFile);
        }
        return m_bHeaderParsed;
    }
}
