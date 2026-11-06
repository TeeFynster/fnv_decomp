#pragma once

class TESForm;

struct BGSChangeFlags
{
public:
    unsigned int uiFlags;

    BGSChangeFlags();
    BGSChangeFlags(unsigned int auiFlags);
    BGSChangeFlags(int v);
    BGSChangeFlags(const BGSChangeFlags& o);
    bool Test(unsigned int auiFlag);
    bool TestFormChangeFlags(TESForm* form);
    void AddFlags(int flags);
    unsigned int GetFlags();
};
