
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFree(void*);

struct FUN_00a311e0_s
{
    unsigned int* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    void NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(unsigned int element);
};

// @fnv 0x00a311e0
// src: XBOX_PDB 0x00a311e0
void FUN_00a311e0_s::NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(unsigned int uiCapacity)
{
    if (uiCapacity != m_uiElementCount)
    {
        unsigned int* pNewBase;
        if (uiCapacity > 0)
        {
            pNewBase = (unsigned int*)_NiMalloc(uiCapacity * 4);
            for (unsigned int i = 0; i < m_uiAllocatedCapacity; ++i)
                pNewBase[i] = m_pBase[i];
        }
        else
        {
            pNewBase = 0;
        }
        _NiFree(m_pBase);
        m_pBase = pNewBase;
        m_uiElementCount = uiCapacity;
    }
}
