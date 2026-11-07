// fallout_shared/tesland_decls.h: declares TESLandFlagsView
// Head of TESObjectLAND (TESForm 0x18 + TESChildCell vptr at 0x18) with the land flags at 0x1C; 0x005394a0 tests
// flag 8 (identical code is folded with TESPackage::FUN_005394a0, whose flags also sit at 0x1C).
class TESLandFlagsView
{
  public:
    char prefix[0x1c];
    unsigned int flags;
    bool TESPackage_GetLockDoorsAtStart();
};
