#pragma once

#include "FileEntryList.h"

class TESFile;
class TESModelList;

class FileEntryListCollection
{
public:
    unsigned int m_uiFileEntryCount;
    FileEntryList** m_ppElementArray;

    ~FileEntryListCollection();
    FileEntryListCollection* ClearData(unsigned int flags);
    void ClearAndDeleteArray();
    void LoadFromTESFile(TESModelList* pOwner, TESFile* pFile);
};
