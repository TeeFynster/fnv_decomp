// Exact source declarations for the three separately retained Box methods.
// No method implementation, alternate storage owner or ABI thunk is provided.
#ifndef FNV_BOX_UNION_PROBE_HPP
#define FNV_BOX_UNION_PROBE_HPP
#include <stddef.h>

struct FUN_00db0920
{
    struct Entry
    {
        unsigned char key0;
        unsigned char key1;
        unsigned short value;
    };
    Entry entries[8];
    unsigned char flag20;
    unsigned char count;
    unsigned char flag22;
    unsigned char* ContainsKey(unsigned char* result, const unsigned char* key);
};

struct FUN_00db0920_cls
{
    struct Entry
    {
        unsigned char key0;
        unsigned char key1;
        unsigned short value;
    };
    Entry entries[8];
    unsigned char flag20;
    unsigned char count;
    unsigned char flag22;
    FUN_00db0920_cls* FUN_00db0920();
};

class BoxPointLookup
{
public:
    unsigned char* ContainsKey(unsigned char* result, const unsigned char* key);
};

class BoxPointInsertion : public FUN_00db0920
{
public:
    int FUN_00db0960(unsigned int a, unsigned int b, const unsigned char* key);
};

typedef char BoxEntryLayout[(sizeof(FUN_00db0920::Entry) == 4 &&
    offsetof(FUN_00db0920::Entry, value) == 2) ? 1 : -1];
typedef char BoxSourceLayout[(sizeof(FUN_00db0920) == 36 &&
    offsetof(FUN_00db0920, flag20) == 32 && offsetof(FUN_00db0920, count) == 33 &&
    offsetof(FUN_00db0920, flag22) == 34 && sizeof(BoxPointInsertion) == 36) ? 1 : -1];
typedef char BoxResetLayout[(sizeof(FUN_00db0920_cls) == 36 &&
    offsetof(FUN_00db0920_cls, flag20) == 32 && offsetof(FUN_00db0920_cls, count) == 33 &&
    offsetof(FUN_00db0920_cls, flag22) == 34) ? 1 : -1];

#endif
