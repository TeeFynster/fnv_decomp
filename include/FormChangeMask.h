#pragma once

class TESForm;

// 0x008c71b0 constructs from an integer; 0x00847850/0x00847df0/0x00848e70 copy the four-byte value directly.
class FormChangeMask
{
public:
    unsigned int flags;

    FormChangeMask() : flags(0) {}
    FormChangeMask(int value) : flags(static_cast<unsigned int>(value)) {}
    FormChangeMask(unsigned int value) : flags(value) {}
#if (defined(_MSC_VER) && _MSC_VER >= 1800) || __cplusplus >= 201103L
    ~FormChangeMask() = default;
#endif

    unsigned int Modelloader_GetReferencedThis();
    bool ContainsAnyFlags(int flags);
    bool CheckFlagsExact(int flags);
    bool CheckFlagsExclusive(int flags);
    void SetFlags(int flags);
    void AddFlags(int flags);
    void RemoveFlags(int flags);
    FormChangeMask GetDifference(int flags);
    operator int();
    operator bool() const { return flags != 0; }
    bool operator()(unsigned int flags) const;

    const char* GetFullFlagName(int flags, unsigned int type, bool full);
    const char* GetShortFlagName(int flags, unsigned int type);
    bool IsFlagSetForType(int flags, unsigned int type, unsigned int mask);
    bool HasFormChanged(TESForm* form);
    static FormChangeMask HasFormChanged(FormChangeMask changes, FormChangeMask forced, int type, bool enabled);
    FormChangeMask CombineFlags(FormChangeMask changes, FormChangeMask forced, unsigned int type, bool enabled);
    void LoadHavokData(TESForm* form);
};
