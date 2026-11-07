
// src/fallout_shared/extradataobjects_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/extradataobjects.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.


class FUN_00ee8ac0_cls
{
  public:
    virtual void vSlot0();
    unsigned int m_uiCount;
    int** m_ppItems;
    int* NiTMapIterator_GetFirstPos();
};

// @fnv 0x00ee8ac0
// src: COMMUNITY 0x00ee8ac0
int* FUN_00ee8ac0_cls::NiTMapIterator_GetFirstPos()
{
    unsigned int count = m_uiCount;
    int i = 0;
    if (i < count)
    {
        int** items = m_ppItems;
        int** p = items;
        do
        {
            if (*p != 0)
            {
                return items[i];
            }
            ++i;
            ++p;
        } while (i < count);
    }
    return 0;
}
