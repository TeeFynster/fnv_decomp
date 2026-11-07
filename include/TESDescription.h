#pragma once

#include "BaseFormComponent.h"

class TESForm;
class TESFile;
enum CHUNK_ID;

class TESDescription : public BaseFormComponent
{
public:
    TESDescription();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual const char* GetDescription(TESForm* form, CHUNK_ID chunkID);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    void Save_00482cb0();
    static void LoadDescriptionAtOffset(TESDescription* description, int offset);
    static void ReadDescriptionFromFile(TESDescription* description, TESFile* file);
    static unsigned int GetDescriptionLength(TESForm* form);
    unsigned int GetDescriptionLength();
    static char* GetDescription(TESForm* form);
    char* GetDescription(TESForm* form, int chunkID);
    const char* GetDescription(TESForm* form, unsigned int chunkID);
    unsigned long GetDescriptionFileOffset();
    void SetDescriptionFileOffset(unsigned long offset);
    void LoadDescriptionForForm(TESForm* form, int chunkID);
    void LoadDescriptionForForm(TESForm* form, CHUNK_ID chunkID);
    void UnLoadDescription();
    void SetDescription(char* description);

    unsigned long m_uiDescriptionFileOffset;
};
