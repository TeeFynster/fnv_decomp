// bssystemutilities/bssystemutilitiesstrings.cpp: BSSystemUtilitiesStrings (4 functions)

#include "../../include/BSSystemUtilitiesStrings.h"
#include "../../include/MemoryManager.h"

extern MemoryManager g_memoryManager;

// Frees each of the 8 stored string pointers via g_memoryManager.Deallocate and clears the slots.
// @fnv 0x00af3680
void BSSystemUtilitiesStrings::Destroy()
{
    for (unsigned int i = 0; i < 8; ++i)
    {
        if (m_pStringFunctions[i])
        {
            void* ptr = m_pStringFunctions[i];
            g_memoryManager.Deallocate(ptr);
            m_pStringFunctions[i] = 0;
        }
    }
}

// @fnv 0x00af3660
void BSSystemUtilitiesStrings::CallVTableMethod()
{
    Destroy();
}

// @fnv 0x00af37a0
void* BSSystemUtilitiesStrings::DestroyIfFlagged(unsigned int flags)
{
    SetVirtualTable_00af35c0();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

unsigned int _strlen(const char*);
void* _fnv_zlib_memset(void*, int, unsigned int);
int _strcpy_s(char*, unsigned int, const char*);

// Frees the string stored at the given index, then allocates and copies a new copy of str into that slot if str is non-null.
// @fnv 0x00af36e0
void BSSystemUtilitiesStrings::SetStringAt(unsigned int index, const char* pcStr)
{
    unsigned int len;
    if (m_pStringFunctions[index])
    {
        void* pOldString = m_pStringFunctions[index];
        g_memoryManager.Deallocate(pOldString);
        m_pStringFunctions[index] = 0;
    }
    if (pcStr)
    {
        len = _strlen(pcStr) + 1;
        void* pAllocated = g_memoryManager.Allocate(len);
        m_pStringFunctions[index] = (char*)pAllocated;
        void* pZeroed = m_pStringFunctions[index];
        _fnv_zlib_memset(pZeroed, 0, len);
        void* pNewString = m_pStringFunctions[index];
        _strcpy_s((char*)pNewString, len, pcStr);
    }
}
