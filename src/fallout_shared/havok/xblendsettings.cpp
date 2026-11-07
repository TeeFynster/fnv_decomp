// src/fallout_shared/havok/xblendsettings.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/xblendsettings.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_005e0830_shell
{
    bool FUN_005e0830(const char* a, int b);
};
struct FUN_005e01b0_shell
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual int vfn_1c();
    virtual bool vfn_20();
    bool INISettingCollection_SaveAll(const char* apFileName);
};
// Calls FUN_005e0830 with the file name and 1; if it succeeds, calls vfn_20 and vfn_1c and returns the result.
// @fnv 0x005e01b0
// src: COMMUNITY 0x005e01b0
bool FUN_005e01b0_shell::INISettingCollection_SaveAll(const char* apFileName)
{
    bool bres = reinterpret_cast<FUN_005e0830_shell*>(this)->FUN_005e0830(apFileName, 1);
    if (bres)
    {
        bres = vfn_20();
        vfn_1c();
    }
    return bres;
}
