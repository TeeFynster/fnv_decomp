
// src/fallout/ai/movement/detailedactorpathhandler_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/movement/detailedactorpathhandler.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.



extern char DAT_01048858[], DAT_010c6084[], DAT_010c6078[], DAT_01029400[], DAT_010925bc[], DAT_010c606c[],
    DAT_010c6064[], DAT_010c605c[];
struct S
{
    const char* bhkRigidBodyCinfo_GetQualityTypeString();
};
// @fnv 0x00c8d4a0
// src: XBOX_PDB 0x00c8d4a0
const char* S::bhkRigidBodyCinfo_GetQualityTypeString()
{
    const char* r = 0;
    switch (*((signed char*)this + 0xd7))
    {
    case -1:
        r = DAT_01048858;
        break;
    case 0:
        r = DAT_010c6084;
        break;
    case 1:
        r = DAT_010c6078;
        break;
    case 2:
        r = DAT_01029400;
        break;
    case 4:
        r = DAT_010925bc;
        break;
    case 5:
        r = DAT_010c606c;
        break;
    case 6:
        r = DAT_010c6064;
        break;
    case 7:
        r = DAT_010c605c;
        break;
    }
    return r;
}
