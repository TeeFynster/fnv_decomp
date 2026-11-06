#pragma once

#include "TESForm.h"
#include "TESIcon.h"

class BGSMenuIcon : public TESForm, public TESIcon
{
public:
    BGSMenuIcon();
    virtual ~BGSMenuIcon();
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* file);
    const char* __thiscall GetFullName(void);
    void SetFormID(unsigned int id, int flag);
    void SetEditorID(const char* name);
};
