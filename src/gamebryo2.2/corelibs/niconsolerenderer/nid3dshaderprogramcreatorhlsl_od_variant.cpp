
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00b18300_Class
{
    char _pad00[0x48];
    void* m_p48;
    void* CFrondEngine_GetLevel();
};

// @fnv 0x00b18300
// src: COMMUNITY 0x00b18300
void* FUN_00b18300_Class::CFrondEngine_GetLevel()
{
    return m_p48;
}
