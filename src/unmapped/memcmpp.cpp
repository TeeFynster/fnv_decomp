// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00a3dd00_class
{
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_p4;
    void* m_p5;
    void* m_p6;
    int NiPathInterpolator_GetPathKeys(int& a, int& b, char& c);
};

// @fnv 0x00a3dd00
// src: GAMEBRYO_LIB 0x00a3dd00
int FUN_00a3dd00_class::NiPathInterpolator_GetPathKeys(int& a, int& b, char& c)
{
    int result = 0;
    void* p = m_p6;
    if (p)
    {
        a = *(int*)((char*)p + 8);
        b = *(int*)((char*)p + 16);
        c = *(char*)((char*)p + 20);
        result = *(int*)((char*)p + 12);
    }
    else
    {
        a = result;
        b = result;
        c = (char)result;
    }
    return result;
}
