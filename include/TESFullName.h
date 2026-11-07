#pragma once

#include "BaseFormComponent.h"

// units that still carry their own BSStringT (or layout_support.h's) define FNV64_BSSTRINGT_DEFINED first
#if !defined(FNV_LAYOUT_SUPPORT_H) && !defined(FNV64_BSSTRINGT_DEFINED)
#include "BSStringT.h"
#endif

#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H

class TESForm;
class TESFile;

class TESFullName : public BaseFormComponent
{
public:
    TESFullName();
    ~TESFullName();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    static unsigned int GetFullNameLength(TESForm* form);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm* form);
    char* GetFullName();
    void SetFullName(char* name);
    void SetFullName(const char* name);
    static void LoadFullNameChunk(TESFullName* fullName, TESFile* file);
    void* GetFullNameString();
    unsigned int GetModelLength() const;
    int GetLength() const;
    void Save_00487010();
    void FUN_00402d00();

    BSStringT<char> m_kName;
};

#endif
