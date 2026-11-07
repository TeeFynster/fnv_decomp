// fallout_shared/bgsmessageicon.cpp: BGSMessageIcon, TESModelTextureSwap (11 functions)

#include "layout_support.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/TESModelTextureSwap.h"

// @fnv 0x0047a220
void BGSMessageIcon::ClearComponent()
{
    Icon.Free();
}

// @fnv 0x0048a3d0
TESModelTextureSwap::TESModelTextureSwap()
{
    InitializeComponent();
}

// @fnv 0x0047a130
BGSMessageIcon::BGSMessageIcon()
{
    InitializeComponent();
}

// @fnv 0x0047a290
void BGSMessageIcon::LoadMessageIcon(BGSMessageIcon* icon, TESFile* file)
{
    TESTexture::ReadTextureData(icon->GetIcon(), file);
}

// @fnv 0x0047a380
void BGSMessageIcon::SetMessageIconTextureName(char* name)
{
    reinterpret_cast<TESFullName*>(&Icon)->SetFullName(static_cast<const char*>(name));
}

// @fnv 0x0047a1a0
BGSMessageIcon::~BGSMessageIcon()
{
    ClearComponent();
}

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
// @fnv 0x0047a240
void BGSMessageIcon::Save(int chunk)
{
    if (reinterpret_cast<TESFullName*>(&Icon)->GetModelLength())
        TESForm_AddChunkArray(chunk, (void*)reinterpret_cast<TESFullName*>(&Icon)->GetFullName(),
                     reinterpret_cast<TESFullName*>(&Icon)->GetModelLength() + 1);
}

// @fnv 0x0047a2b0
void BGSMessageIcon::BaseFormRecord(BaseFormComponent* component)
{
    BGSMessageIcon* msgIcon = dynamic_cast<BGSMessageIcon*>(component);
    if (!msgIcon)
        return;
    SetMessageIconTextureName(msgIcon->GetMessageIconTextureName());
}

int _stricmp(const char*, const char*);
// @fnv 0x0047a320
bool BGSMessageIcon::IsEqualToBase(BaseFormComponent* component)
{
    BGSMessageIcon* icon = dynamic_cast<BGSMessageIcon*>(component);
    if (!icon)
        return true;
    if (_stricmp(GetMessageIconTextureName(), icon->GetMessageIconTextureName()))
        return true;
    return false;
}

// @fnv 0x0047a300
char* BGSMessageIcon::GetMessageIconTextureName()
{
    return reinterpret_cast<TESFullName*>(&Icon)->GetFullName();
}

// @fnv 0x0047a200
void BGSMessageIcon::InitializeComponent()
{
    Icon.Init();
}
