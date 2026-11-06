// fallout/misc/saveload/bgsloadformbuffer_decls.h: declares SaveLoadFile, PackedFormID, BGSSaveLoadFormInfo, FormChangeMask, FormLoadContext and more
#ifndef FNV_BGSLOADFORMBUFFER_DECLS_H
#define FNV_BGSLOADFORMBUFFER_DECLS_H

#include "layout_support.h"
#include "TESForm.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"

class SaveLoadFile
{
  public:
    void AdvancePosition(unsigned int bytes);
};

TESForm* GetFormByID(unsigned int formID);

#pragma pack(push, 1)

class PackedFormID
{
  public:
    PackedFormID();
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int numericID);
    bool IsZero();

    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};

class BGSSaveLoadFormInfo
{
  public:
    BGSSaveLoadFormInfo();
    ENUM_FORM_ID GetFormType();
    void SetFormType(ENUM_FORM_ID formType);
    void InitSaveGameFormTypes();

    unsigned char cData;
};

class FormLoadContext
{
  public:
    FormLoadContext();
    void Endian();

    PackedFormID m_kFormIDIndex;
    FormChangeMask m_pDeathItem;
    BGSSaveLoadFormInfo FormInfo;
    unsigned char cVersion;
};

#pragma pack(pop)

#endif
