#pragma once

#include "BaseFormComponent.h"
#include "TESIcon.h"

class TESFile;

class BGSMessageIcon : public BaseFormComponent
{
public:
    BGSMessageIcon();
    ~BGSMessageIcon();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);

    void Save(int chunk);
    static void LoadMessageIcon(BGSMessageIcon* icon, TESFile* file);
    static void LoadMessageIconChunk(BGSMessageIcon* icon, TESFile* file);
    TESIcon* GetIcon();
    char* GetMessageIconTextureName();
    unsigned int GetMessageIconTextureNameLength();
    void SetMessageIconTextureName(char* name);
    void SetMessageIconTextureName(const char* name);

    TESIcon Icon;
};
