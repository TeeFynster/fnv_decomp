#pragma once

#include "BaseFormComponent.h"
#include "TESFullName.h"

class TESForm;

class TESSoundFile : public BaseFormComponent
{
public:
    TESSoundFile();
    ~TESSoundFile();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual void SetSoundFile(const char* name);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    void SetSoundFile(char* name);
    void SetName(const char* name);
    static unsigned int GetSoundFileLength(TESForm* form);
    unsigned int GetSoundFileLength();
    unsigned int GetSoundFileLength() const;
    static char* GetSoundFile(TESForm* form);
    char* GetSoundFile();
    const char* GetSoundFile() const;

    BSStringT<char> m_kSoundFile;
};
