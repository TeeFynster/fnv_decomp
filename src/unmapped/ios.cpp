// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ReleaseTarget_cls
{
    virtual int vDel(int flags);
};

struct ReleaseHolder_cls
{
    ReleaseTarget_cls* std_locale_facet__Decref();
};

struct FUN_00acb720_cls
{
    ReleaseHolder_cls* m_00;

    void UpdateFields_00acb720();
};

// If m_00 is set, gets its target via FUN_00acb770 and, when non-null, calls vDel(1) on it.
// @fnv 0x00acb720
// src: GUESS 0x00acb720 (confidence: low)
void FUN_00acb720_cls::UpdateFields_00acb720()
{
    ReleaseTarget_cls* tmp;
    ReleaseTarget_cls* blk;
    int unkC;
    long unkD;
    if (m_00 != 0)
    {
        tmp = m_00->std_locale_facet__Decref();
        blk = tmp;
        (blk != 0) ? blk->vDel(1) : 0;
    }
}
