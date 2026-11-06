// src/fallout_shared/tessoundfile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tessoundfile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BaseFormComponent.h"
#include "../../include/TESModel.h"
#include "../../include/TESSoundFile.h"

// Casts apCopyFC to TESSoundFile and, if successful, copies its sound file name via SetSoundFile.
// @fnv 0x0048cf00
void TESSoundFile::CopyFromBase(BaseFormComponent* apCopyFC)
{
    TESSoundFile* pcopy = dynamic_cast<TESSoundFile*>(apCopyFC);
    if (!pcopy)
        return;
    SetSoundFile(static_cast<const char*>(pcopy->GetSoundFile()));
}

int _stricmp(const char*, const char*);
// @fnv 0x0048cf50
bool TESSoundFile::CompareWithBase(BaseFormComponent* apCompareFC)
{
    TESSoundFile* pcompare = dynamic_cast<TESSoundFile*>(apCompareFC);
    if (!pcompare)
        return true;
    if (GetSoundFileLength() || pcompare->GetSoundFileLength())
    {
        if (GetSoundFileLength() !=
            pcompare->GetSoundFileLength())
            return true;
        else
        {
            if (_stricmp(GetSoundFile(),
                         pcompare->GetSoundFile()))
                return true;
        }
    }
    return false;
}
