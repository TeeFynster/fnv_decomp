
// src/havok/common/serialize/util/hkrootlevelcontainer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkrootlevelcontainer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkRootLevelContainer.h"

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
};

int __cdecl hkString_strCmp(int a, int b);

struct hkClassObj : FUN_00d46d40_s
{
};

struct FUN_00d477a0_s
{
    void* m_object;

    hkClassObj* hkRefVariant_getClass();
};

struct EntryD480
{
    int unk00;
    unsigned int m_pcText;
    FUN_00d477a0_s m_pReferencedResource;

    const void* GetUnderlyingObject() const
    {
        return m_pReferencedResource.m_object;
    }
    const char* getName()
    {
        return m_pReferencedResource.hkRefVariant_getClass() ? m_pReferencedResource.hkRefVariant_getClass()->FUN_00d46d40()
                                                    : (const char*)(m_pcText & ~1u);
    }
};

class VariantListD480
{
  public:
    EntryD480* m_data;
    int m_iElementCount;

    void* FindByName(const char* pcName, const void* pkAfter);
};

// Finds an entry in m_data whose name matches pcName, starting the search after the entry whose underlying object is pkAfter, and returns its object or 0.
// @fnv 0x00d48080
void* VariantListD480::FindByName(const char* pcName, const void* pkAfter)
{
    int iStart = 0;
lNext:
    if (pkAfter && iStart < m_iElementCount)
    {
        if (m_data[iStart++].GetUnderlyingObject() != pkAfter)
            goto lNext;
    }
    for (int i = iStart; i < m_iElementCount; i++)
    {
        if (m_data[i].getName() && hkString_strCmp((int)pcName, (int)m_data[i].getName()) == 0)
            return m_data[i].m_pReferencedResource.m_object;
    }
    return 0;
}

struct Ent_d48150
{
    unsigned int unk00;
    int unk04;
    int unk08;
};

int __cdecl hkString_strCmp(void* a, unsigned int b);

struct Cls_d48150
{
    Ent_d48150* m_data;
    int m_iElementCount;
    int idx(int key)
    {
        int i = 0;
        Ent_d48150* e;
        while (key != 0 && i < m_iElementCount && (e = &m_data[i], i++, e->unk08 != key))
        {
        }
        return i;
    }
    int ProcessEntries_00d48150(void* ctx, int key);
};

// @fnv 0x00d48150
// src: GUESS 0x00d48150 (confidence: low)
int Cls_d48150::ProcessEntries_00d48150(void* apContext, int key)
{
    int iIndex = idx(key);
    for (; iIndex < m_iElementCount; iIndex++)
    {
        int v = (int)m_data[iIndex].unk00;
        if ((v & -2) == 0 || hkString_strCmp(apContext, v & -2) != 0)
            continue;
        return m_data[iIndex].unk08;
    }
    return 0;
}
