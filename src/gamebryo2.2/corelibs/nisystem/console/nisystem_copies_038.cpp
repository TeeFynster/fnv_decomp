// Provisional build file (plan B2): exact copies of the nisystem recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
//
//
// The MSVC runtime supplies the case-insensitive string comparison;
// the engine exposes it under its own name so shared game code does
// not depend directly on the CRT spelling.

extern "C" int _stricmp(const char* s1, const char* s2);

// @fnv 0x00404dc0
// src: COMMUNITY 0x00404dc0
int BSstricmp(const char* pcString1, const char* pcString2)
{
    return _stricmp(pcString1, pcString2);
}
