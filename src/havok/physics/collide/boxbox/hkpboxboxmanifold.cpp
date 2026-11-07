
// src/havok/physics/collide/boxbox/hkpboxboxmanifold.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/boxbox/hkpboxboxmanifold.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

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
// Scans entries backwards for one whose key0 and key1 match the two key bytes, writing 1 to result if found and 0 otherwise.
// @fnv 0x00db09b0
unsigned char* FUN_00db0920::ContainsKey(unsigned char* result, const unsigned char* key)
{
    for (int i = count - 1; i >= 0; --i)
    {
        if (entries[i].key0 == key[0] && entries[i].key1 == key[1])
        {
            *result = 1;
            return result;
        }
    }
    *result = 0;
    return result;
}

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

    FUN_00db0920_cls* InitializeEmptyEntries();
};

// Zeroes all entry values, count, and flag fields, then returns this.
// @fnv 0x00db0920
// src: GUESS 0x00db0920 (confidence: medium)
FUN_00db0920_cls* FUN_00db0920_cls::InitializeEmptyEntries()
{
    unsigned short* pEntryValues = &entries[0].value;
    pEntryValues[0] = 0;
    pEntryValues[2] = 0;
    pEntryValues[4] = 0;
    pEntryValues[6] = 0;
    pEntryValues[8] = 0;
    pEntryValues[10] = 0;
    pEntryValues[12] = 0;
    pEntryValues[14] = 0;
    count = 0;
    flag20 = 0;
    flag22 = 0;
    return this;
}

class BoxPointLookup
{
  public:
    unsigned char* ContainsKey(unsigned char* result, const unsigned char* key);
};

class BoxPointInsertion : public FUN_00db0920
{
  public:
    int hkpBoxBoxManifold_addPoint(unsigned int a, unsigned int b, const unsigned char* key);
};

// Inserts a key into the entries array if the count is under 8 and the key is not already present, returning the index or -1 on failure.
// @fnv 0x00db0960
// src: HAVOK_LIB 0x00db0960
int BoxPointInsertion::hkpBoxBoxManifold_addPoint(unsigned int aiUnused, unsigned int b, const unsigned char* key)
{
    FUN_00db0920* self = this;
    unsigned char count = self->count;
    if (count > 8)
    {
        return -1;
    }
    unsigned int result;
    unsigned char* found = reinterpret_cast<BoxPointLookup*>(self)->ContainsKey((unsigned char*)&result, key);
    if (*found != 0)
    {
        return -1;
    }
    int idx = count;
    if (idx < 8)
    {
        *(unsigned int*)&self->entries[idx] = *(const unsigned int*)key;
        self->count++;
        return idx;
    }
    return -1;
}
