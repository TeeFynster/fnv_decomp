// fallout_shared/niformarray.cpp: NiFormArray (3 functions)

#include "../../include/NiFormArray.h"

// The canonical _memmove binding names a different runtime entry point.
void* __cdecl FUN_00ec7230(void* destination, const void* source, unsigned int size);

// @fnv 0x0061bc10
void NiFormArray::SetFormAtIndex(unsigned int index, TESForm* form)
{
    Compact();
    if (index > m_uiSize)
        SetAt(index, form);
    else
    {
        unsigned int newSize = m_uiSize + 1;
        if (m_uiMaxSize < newSize)
            NiTLargePrimitiveArray<TESForm*>::SetSize(newSize + m_uiGrowBy);
        FUN_00ec7230(m_pBase + index + 1, m_pBase + index, (m_uiSize - index) * sizeof(TESForm*));
        ++m_uiSize;
        m_uiESize = m_uiSize;
        m_pBase[index] = form;
    }
}

// @fnv 0x004d6100
unsigned int NiFormArray::GetIndexOfForm(TESForm* form)
{
    unsigned int foundIndex = 0xffffffff;
    if (form)
    {
        unsigned int size = GetSize();
        if (size)
        {
            for (unsigned int index = 0; index < size; ++index)
            {
                if (FUN_00877a30(index) == form)
                {
                    foundIndex = index;
                    break;
                }
            }
        }
    }
    return foundIndex;
}

// Returns the form at aiIndex if it is within GetSize(), otherwise returns null.
// @fnv 0x004d6170
TESForm* NiFormArray::GetFormAt(unsigned int aiIndex)
{
    TESForm* pretform = 0;
    if (aiIndex < GetSize())
    {
        pretform = FUN_00877a30(aiIndex);
    }
    return pretform;
}
