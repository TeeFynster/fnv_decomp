
// src/fallout/interface/bgsmenupacker.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/bgsmenupacker.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FNVVector
{
    float x;
    float y;
    float z;
};
struct FNVAccessor
{
    FNVVector* GetTranslate_0043c490();
};
struct FNVNested;
struct FNVNestedProxy
{
    int GetName_00700300();
};
struct FNVNested
{
    FNVNestedProxy* FUN_0045cd60();
    int GetName_00700300();
    FNVAccessor* GetModel_0056c7f0();
};
struct FNVEntry
{
    float value00;
    float value04;
    float value08;
    float value0c;
    float value10;
    float value14;
    FNVNested* member18;
};
extern const char UNK_0106e8ac[];
extern const char UNK_0106e87c[];
extern const char UNK_0106e84c[];
extern const char UNK_0106e820[];
extern const char UNK_0106e800[];
int __cdecl Interface_PrintLine(const char*, ...);
struct FNVCollection
{
    int GetShortAtOffsetA();
    FNVEntry** FUN_00877a30(int);
    void BGSMenuPacker_DumpInfo();
};
// @fnv 0x00700350
// src: XBOX_PDB 0x00700350
void FNVCollection::BGSMenuPacker_DumpInfo()
{
    Interface_PrintLine(UNK_0106e8ac);
    for (int index = 0; index < GetShortAtOffsetA(); ++index)
    {
        FNVEntry* entry = *FUN_00877a30(index);
        Interface_PrintLine(UNK_0106e87c, entry->member18->GetName_00700300(), entry->member18->FUN_0045cd60()->GetName_00700300());
        Interface_PrintLine(UNK_0106e84c, entry->value00, entry->value04, entry->value10, entry->value14);
        Interface_PrintLine(UNK_0106e820, entry->value08, entry->value0c, entry->member18->GetModel_0056c7f0()->GetTranslate_0043c490()->x,
                     entry->member18->GetModel_0056c7f0()->GetTranslate_0043c490()->z);
    }
    Interface_PrintLine(UNK_0106e800);
}
