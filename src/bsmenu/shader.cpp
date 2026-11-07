// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl NiGlobalStringTable_DecRefCount(void*);
void __cdecl NiGlobalStringTable_IncRefCount(int const&);
struct FUN_0043ba10_shell
{
    int m;
    FUN_0043ba10_shell* AssignInternedString(FUN_0043ba10_shell* other);
};
// If other's m differs from this m, calls FUN_0043ba60 with other's m, calls FUN_004381d0 on this, then stores other's m; returns this.
// @fnv 0x0043ba10
// src: GUESS 0x0043ba10 (confidence: high)
FUN_0043ba10_shell* FUN_0043ba10_shell::AssignInternedString(FUN_0043ba10_shell* other)
{
    int tmp;
    if (m != other->m)
    {
        tmp = other->m;
        NiGlobalStringTable_IncRefCount(tmp);
        NiGlobalStringTable_DecRefCount(this);
        m = tmp;
    }
    return this;
}
