#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESTexture.h"

class TESNPC;

class TESEyes : public TESForm, public TESFullName, public TESTexture
{
public:
    char cFlags;
    unsigned char unk31[3];

    TESEyes();
    virtual ~TESEyes();
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    bool IsFlagSet();
    void SetFlag(bool flag);
    bool IsNotFlag2Set();
    bool IsFlag4Clear();
    bool IsNotEqual(TESForm* compare);
    void CopyFromEyes(TESForm* copy);
    bool CanBeNPC(TESNPC* npc);
    void SetMale(bool flag);
    void SetFemale(bool flag);
    void SaveEyes();
    void Destroy();
    void* ReleaseIfFlagged(unsigned int flags);
    void InitializeData_005fc1b0();
};
