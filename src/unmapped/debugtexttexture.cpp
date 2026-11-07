
// src/unmapped/debugtexttexture.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtexttexture.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00470bb0
// src: COMMUNITY 0x00470bb0
int __cdecl return15()
{
    return 15;
}

struct PathStr;

struct PathSource
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual PathStr* v9C();
};

struct PathStr
{
    char* FUN_0043b1b0();
};

int __cdecl FUN_00ec7ec0(const char* a, const char* b, unsigned int n);
char* __cdecl FUN_00ec7690(const char* s, int c);

struct FUN_0071dca0_cls
{
    bool HasMenusPath(PathSource* src);
};

// Checks whether the path string returned by src->v9C()->FUN_0043b1b0() contains a "\menus" segment, scanning backslash-delimited parts.
// @fnv 0x0071dca0
bool FUN_0071dca0_cls::HasMenusPath(PathSource* src)
{
    bool bFound = false;
    {
        if (src != 0)
        {
            if (src->v9C()->FUN_0043b1b0() != 0)
            {
                char* pSegment = FUN_00ec7690(src->v9C()->FUN_0043b1b0(), 0x5c);
                while (pSegment != 0)
                {
                    if (FUN_00ec7ec0(pSegment, "\\menus", 6) == 0)
                    {
                        bFound = true;
                        pSegment = 0;
                    }
                    else
                    {
                        pSegment = pSegment + 1;
                        pSegment = FUN_00ec7690(pSegment, 0x5c);
                    }
                }
            }
        }
    }
    return bFound;
}
