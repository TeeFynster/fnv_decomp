#pragma once

#include "BGSLoadGameBuffer.h"
#include "FormChangeMask.h"

class SaveFile;
class FormExtra;
enum ENUM_FORM_ID;

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
public:
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();

unsigned int iFormID;
    char Header[9];
    unsigned char _unverified_HeaderTail[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    unsigned int iOldChangeFlags;

    BGSLoadFormBuffer();
    ~BGSLoadFormBuffer();

    int LoadHeader(SaveLoadFile* file);
    int ReadFormData(SaveLoadFile* file);
    void SkipData(SaveLoadFile* file, unsigned int size);
    unsigned int GetFormID();
    void SetForm(TESForm* form);
    ENUM_FORM_ID GetFormType();
    FormChangeMask GetChangeFlags();
    FormChangeMask GetChangeFlags(unsigned int flags);
    FormChangeMask GetChangeFlags(int flags);
    void SetChangeFlags(FormChangeMask flags);
    FormChangeMask GetOldChangeFlags();
    FormChangeMask GetOldChangeFlags(unsigned int flags);
    FormChangeMask GetOldChangeFlags(unsigned int flags) const;
    void SetOldChangeFlags(FormChangeMask flags);
    void SetVersion(unsigned char version);
    void SetSkipForm(bool value);
    bool GetSkipForm();
    void SetFormPending(bool value);
    bool GetFormPending();
    void SetRevertOnly(bool value);
    bool GetRevertOnly();
    void SetReconstructedForm(bool value);
    bool GetReconstructedForm();
    void SetCellChanged(bool value);
    bool GetCellChanged();
    bool IsFlag2Set();
    void SetFlag10(int value);

    using BGSLoadGameBuffer::ReadTypedData;
    using BGSLoadGameBuffer::ReadFormIdentifier;
    using BGSLoadGameBuffer::LoadData;
    void ReadTypedData(void* data, unsigned int size);
    void ReadTypedData(void* data, int size);
    unsigned char ReadTypedData(bool* data, unsigned int size);
    bool ReadFormIdentifier(void* formID);
    unsigned int ReadFormIdentifier();
    int ReadElementCount();
    void SetBuffer(char* buffer, unsigned int size, unsigned int position);
    void AddToOffset(int offset);
    int CheckValueMatchesField(SaveFile* file);

    unsigned int FUN_008648a0();
    void FUN_008648e0(void* data);
    bool FUN_008648e0(int* data);
    void LoadData(void* data, int size);
    int FUN_00864a60();
    void ExtraDismemberedLimbs_SetEaten(unsigned char version);
    bool BGSLoadFormBuffer_GetReconstructedForm();
    void FUN_008644b0(SaveFile* file);
    unsigned int GetFormType_008665b0();
    unsigned int TESMain_GetThread();
    FormChangeMask FUN_00428110();
    void FUN_0086cf00(FormChangeMask flags);
    void FUN_007037c0(FormExtra* form);
    void FUN_00864580(SaveFile* file, unsigned int size);
    FormChangeMask BGSLoadFormBuffer_GetOldChangeFlags();
    void SetSkipForm_00848d90(bool value);
    void FUN_0042ce50(bool value);
    bool GetSkipForm_00848dd0();
    void* FUN_0081db60(unsigned int flags);
    void FUN_00848d50();
};
