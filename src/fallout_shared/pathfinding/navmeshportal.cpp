
// src/fallout_shared/pathfinding/navmeshportal.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshportal.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DFD0SwapFlag
{
    bool m_bValue;
};

void __cdecl BSEndian_00401080(int* piValue, DFD0SwapFlag kFlag);
void __cdecl BSEndian_00407a90(short* psValue, DFD0SwapFlag kFlag);

struct DFD0File
{
    bool IsEndianConversionRequired();
};

void __cdecl ResolveFormID(int* piFormID, DFD0File* pkFile);

struct DFD0Form
{
    void* GetBase();
};

struct DFD0TES
{
    DFD0Form* GetForm(int iFormID);
};

extern DFD0TES* g_DFD0TES;

struct DFD0Data
{
    void* m_pBase;
    short m_sCount;

    void LoadFormRef(void* pUnused, DFD0File* pkFile, const char* pBuffer);
};

// Reads a form ID and a count from the buffer, byte-swaps them if the file needs endian conversion, resolves the form ID to a base pointer, and stores both.
// @fnv 0x0069dfd0
void DFD0Data::LoadFormRef(void* pUnused, DFD0File* pkFile, const char* pBuffer)
{
    int iFormID = *(const int*)pBuffer;
    if (pkFile->IsEndianConversionRequired())
        BSEndian_00401080(&iFormID, DFD0SwapFlag());
    ResolveFormID(&iFormID, pkFile);
    if (iFormID)
        m_pBase = g_DFD0TES->GetForm(iFormID)->GetBase();
    else
        m_pBase = 0;
    pBuffer += 4;
    m_sCount = *(const short*)pBuffer;
    if (pkFile->IsEndianConversionRequired())
        BSEndian_00407a90(&m_sCount, DFD0SwapFlag());
}
