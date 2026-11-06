
// bssystemutilities/console/bssysinfosystemutility_console.cpp: BSSysInfoSystemUtility (1 function)
#include "../../../include/BSSysInfoSystemUtility.h"

struct SystemLocaleState
{
    void* vtable;
    const char* language;
};

extern SystemLocaleState gSystemLocaleState;
extern unsigned int gCachedLanguage;
extern "C" int __cdecl _strnicmp(const char* left, const char* right, unsigned int count);

// Returns the cached language code, detecting it once by comparing gSystemLocaleState.language against ENGLISH, FRENCH, ITALIAN, GERMAN and SPANISH.
// @fnv 0x00a22cb0
unsigned int BSSysInfoSystemUtility::GetRandomGenerator(void)
{
    if (gCachedLanguage == 0xffffffff)
    {
        const char* pEnglishName;
        if (&gSystemLocaleState)
            pEnglishName = gSystemLocaleState.language;
        else
            pEnglishName = 0;
        if (_strnicmp(pEnglishName, "ENGLISH", 7) == 0)
        {
            gCachedLanguage = 0;
        }
        else
        {
            const char* pFrenchName;
            if (&gSystemLocaleState)
                pFrenchName = gSystemLocaleState.language;
            else
                pFrenchName = 0;
            if (_strnicmp(pFrenchName, "FRENCH", 6) == 0)
            {
                gCachedLanguage = 2;
            }
            else
            {
                const char* pItalianName;
                if (&gSystemLocaleState)
                    pItalianName = gSystemLocaleState.language;
                else
                    pItalianName = 0;
                if (_strnicmp(pItalianName, "ITALIAN", 7) == 0)
                {
                    gCachedLanguage = 4;
                }
                else
                {
                    const char* pGermanName;
                    if (&gSystemLocaleState)
                        pGermanName = gSystemLocaleState.language;
                    else
                        pGermanName = 0;
                    if (_strnicmp(pGermanName, "GERMAN", 6) == 0)
                    {
                        gCachedLanguage = 1;
                    }
                    else
                    {
                        const char* pSpanishName;
                        if (&gSystemLocaleState)
                            pSpanishName = gSystemLocaleState.language;
                        else
                            pSpanishName = 0;
                        if (_strnicmp(pSpanishName, "SPANISH", 7) == 0)
                            gCachedLanguage = 3;
                    }
                }
            }
        }
    }
    return gCachedLanguage;
}
