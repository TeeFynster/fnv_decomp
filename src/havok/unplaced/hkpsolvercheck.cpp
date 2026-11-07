
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void _hkErrorMessage(const char* msg);
int Hksystemtime_Time64_Thunk();

static const char* const s_keyCode = "0x72a843c2-0x3bbeff2a:2011-10-29.Physics.Obsidian_Bethesda_FalloutNewVegas";

static inline int hexValue(char c)
{
    if ((unsigned char)(c - '0') <= 9)
        return c - '0';
    if ((unsigned char)(c - 'A') <= 5)
        return c - 'A' + 10;
    if ((unsigned char)(c - 'a') <= 5)
        return c - 'a' + 10;
    return -1;
}

static inline const char* nextField(const char* p)
{
    while (p && *p && *p != '.')
        p++;
    return p;
}

// Parses the embedded Havok key code, checks its expiry or product hash, reports errors via FUN_00cb1750, and sets *valid on success.
// @fnv 0x00df22f0
int ValidateHavokKeyCode(bool* pbValid)
{
    *pbValid = false;
    int result = 0;
    unsigned int key2 = 0xffffffff;
    unsigned int key1 = 0xffffffff;

    const char* p = s_keyCode + 2;
    int iDigit = hexValue(*p++);
    while (iDigit >= 0)
    {
        key1 = key1 * 16 + iDigit;
        iDigit = hexValue(*p++);
    }
    p += 2;
    iDigit = hexValue(*p++);
    while (iDigit >= 0)
    {
        key2 = key2 * 16 + iDigit;
        iDigit = hexValue(*p++);
    }

    bool expiring = (key1 >> 31) & 1;

    const char* dot = nextField(s_keyCode);
    if (!dot)
    {
        _hkErrorMessage("Product:hkp Key Code is invalid.\nPlease contact Havok.com\nNo simulation possible.");
        return 1;
    }
    dot = nextField(dot + 1);
    if (!dot)
    {
        _hkErrorMessage("Product:hkp Key Code is invalid.\nPlease contact Havok.com\nNo simulation possible.");
        return 1;
    }
    const char* product = dot + 1;

    if (expiring)
    {
        int expiry = (key1 ^ 0xf2e6ef51) & 0x7fffffff;
        int now = Hksystemtime_Time64_Thunk() >> 8;
        int remaining = expiry - now;
        if (expiry < now || remaining > 0x96c99)
        {
            _hkErrorMessage(
                "Product:hkp Key Code has expired .\nPlease contact Havok.com for an extension.\nNo simulation possible.");
            return 2;
        }
        if (remaining < 0xd2f)
            result = 3;
    }
    else
    {
        int hash = 0;
        for (const char* c = product; *c;)
            hash = hash * 23 + *++c;
        if (key2 != ((hash ^ 0xf2e6ef51) & 0x7fffffff))
        {
            _hkErrorMessage("Product:hkp Key Code is invalid.\nPlease contact Havok.com\nNo simulation possible.");
            return 1;
        }
    }
    *pbValid = true;
    return result;
}
