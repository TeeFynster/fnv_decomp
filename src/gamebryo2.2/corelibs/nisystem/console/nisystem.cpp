//
// Gamebryo engine system support.
//
// The MSVC runtime supplies the case-insensitive string comparison;
// the engine exposes it under its own name so shared game code does
// not depend directly on the CRT spelling.

extern "C" int _stricmp(const char* s1, const char* s2);

// @fnv 0x00aa1360
int NiStricmp(const char* a, const char* b)
{
    return _stricmp(a, b);
}

extern "C" void FUN_00ec7ec0(void);

// @fnv 0x00aa1370
// src: XBOX_PDB 0x00aa1370
void NiStrnicmp()
{
    FUN_00ec7ec0();
}
