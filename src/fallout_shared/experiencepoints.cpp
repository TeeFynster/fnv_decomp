
// src/fallout_shared/experiencepoints.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/experiencepoints.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __cdecl FindPairValue(int, int*, int);
extern int DAT_0119bbcc;
extern int DAT_0119bbf4;
extern int DAT_0119bc1c;
extern int DAT_0119bc44;
extern int DAT_0119bc6c;

// Dispatches on aeActivity (0-4) to call FindPairValue with aiDifficulty, one of five global tables, and a count of 5, returning its result.
// @fnv 0x006705b0
// src: XBOX_PDB 0x006705b0
int __cdecl ExperiencePoints_GetExperiencePoints(int aeActivity, int aiDifficulty)
{
    int iresult = 0;
    switch (aeActivity)
    {
    case 0:
        iresult = FindPairValue(aiDifficulty, &DAT_0119bbcc, 5);
        break;
    case 1:
        iresult = FindPairValue(aiDifficulty, &DAT_0119bbf4, 5);
        break;
    case 2:
        iresult = FindPairValue(aiDifficulty, &DAT_0119bc1c, 5);
        break;
    case 3:
        iresult = FindPairValue(aiDifficulty, &DAT_0119bc44, 5);
        break;
    case 4:
        iresult = FindPairValue(aiDifficulty, &DAT_0119bc6c, 5);
        break;
    }
    return iresult;
}
