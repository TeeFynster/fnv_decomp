// tesreputation.cpp: TESReputation and reputation support (25 functions)

// Keep legacy support definitions separate from the shared player dependencies.
// include/TESFile.h needs the Windows types before layout_support.h stubs them.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "layout_support.h"

#include "../include/BaseFormComponent.h"
#define FNV_BASEFORMCOMPONENT_H
#define FNV64_BSSIMPLELIST_DEFINED
#include "../include/PlayerCharacter.h"
#define FNV_TESFORM_H
#include "../include/BGSMessageIcon.h"
#include "../include/ReputationLimitData.h"
#include "../include/SETTING_VALUE.h"
#include "../include/TESReputation.h"
#include "../include/TESFile.h"
#include "../include/BGSLoadFormBuffer.h"
#include "../include/BGSSaveFormBuffer.h"
#include "../include/Setting.h"
#include "../include/SettingT_GameSettingCollection_.h"
#include "../include/TESModel.h"
#include <malloc.h>

// Local declarations for operations whose exact signatures are not in the shared header.
// All layout and members come from TESReputation.
struct ReputationOperations : TESReputation
{
    // The shared declaration returns int; this unit requires the original byte return.
    unsigned char GetReputationRank(int kind);
    unsigned short GetReputationSaveSize(unsigned int flags);
    void SaveToBuffer(BGSSaveFormBuffer* buffer);
    void LoadFromBuffer(BGSLoadFormBuffer* buffer);
    void SaveRecord();
    ReputationLimitData* GetReputationData();
    bool CompareBase(TESForm* other);
    bool CompareReputation(TESForm* other);
    void CopyReputation(TESForm* source);
};

// @fnv 0x00615560
void TESReputation::ResetFormData()
{
    m_fFirstReputationValue = 0.0f;
    m_fSecondReputationValue = 0.0f;
}

// @fnv 0x00616290
bool TESReputation::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 'NOCI':
            TESTexture::ReadTextureData(this, file);
            break;
        case 'OCIM':
            BGSMessageIcon::LoadMessageIconChunk(this, file);
            break;
        case 'ATAD':
            ReadTypedData(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                data.Endian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x007dc0a0
unsigned int* TESReputation::GetUnsignedIntegerPointer(unsigned int* puiValue)
{
    ++*puiValue;
    return puiValue;
}

// @fnv 0x006155c0
float TESReputation::GetUnsignedIntegerPointer(ReputationType type)
{
    if (type == ReputationType_REPUTATION_POSITIVE)
    {
        return m_fFirstReputationValue;
    }
    else
    {
        return m_fSecondReputationValue;
    }
}

// @fnv 0x006153c0
TESReputation::TESReputation()
{
    TESReputation::ResetFormData();
    SetFormType((ENUM_FORM_ID)0x68);
}

char __cdecl ConsumeByteAtE4(void);
extern char DAT_0119a0bc;

// @fnv 0x00615720
// src: COMMUNITY 0x00615720
void __cdecl FakeModalMessageMenuCallback(void)
{
    DAT_0119a0bc = ConsumeByteAtE4();
}

// The shared player header does not yet declare the reputation queue setter.
struct PlayerReputationQueue : PlayerCharacter
{
    void SetValue(TESReputation* reputation);
};

// @fnv 0x006159e0
void PlayerReputationQueue::SetValue(TESReputation* reputation)
{
    *(TESReputation**)((char*)this + 0xe0c) = reputation;
}


// @fnv 0x006166e0
const char* TESReputation::GetReputationName()
{
    if (static_cast<const TESModel&>(*reinterpret_cast<TESModel*>((char*)this + 0x24)).GetModelLength())
        return TESIcon::GetTextureResourceName();
    return "";
}

struct FUN_00484bf0
{
    unsigned short __thiscall GetSaveSize(unsigned int);
};

// Returns the save size: the result of GetSaveSize(aiFlags) plus 8 bytes.
// @fnv 0x006165f0
unsigned short __thiscall ReputationOperations::GetReputationSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_00484bf0*)this)->GetSaveSize(aiFlags);
    isize += 4;
    isize += 4;
    return isize;
}

// @fnv 0x006166a0
void ReputationOperations::LoadFromBuffer(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    buffer->ReadTypedData(&m_fFirstReputationValue, 4u);
    buffer->ReadTypedData(&m_fSecondReputationValue, 4u);
}

struct S_00487010
{
    void __thiscall Save_00487010(void);
};
struct FUN_0048e370_obj
{
    void __thiscall TESTexture_Save(unsigned int);
};
struct FUN_0047a240_shell
{
    void __thiscall FUN_0047a240(unsigned int);
};
struct FUN_00485e00_shell
{
    void __thiscall TESForm___SaveData(int, int);
};
unsigned char __cdecl TESForm_QEndianSwapOnSave(void);
// @fnv 0x00616470
void __thiscall ReputationOperations::SaveRecord()
{
    TESForm::BeginFormRecord();
    ((S_00487010*)((char*)this + 0x18))->Save_00487010();
    ((FUN_0048e370_obj*)((char*)this + 0x24))->TESTexture_Save(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x30))->FUN_0047a240(0x4f43494d);
    if (TESForm_QEndianSwapOnSave())
        data.Endian();
    ((FUN_00485e00_shell*)this)->TESForm___SaveData((int)((char*)this + 0x40), 4);
    if (TESForm_QEndianSwapOnSave())
        data.Endian();
    TESForm::FinishFormRecord();
}

// Stores the selected reputation value and marks the form as modified.
// @fnv 0x00615580
// src: COMMUNITY 0x00615580
void TESReputation::SetReputation_00615580(int a, float afValue)
{
    if (a == 1)
        m_fFirstReputationValue = afValue;
    else
        m_fSecondReputationValue = afValue;
    MarkAsModified(2);
}

struct FUN_00484d60_holder
{
    void __thiscall SaveIfChanged(unsigned int);
};

// Saves the base form and both reputation values to the buffer.
// @fnv 0x00616660
void __thiscall ReputationOperations::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    ((FUN_00484d60_holder*)this)->SaveIfChanged((unsigned int)buffer);
    buffer->SaveData(&m_fFirstReputationValue, 4, 0);
    buffer->SaveData(&m_fSecondReputationValue, 4, 0);
}

struct TutorialState
{
    bool __thiscall ShowMessage(int, int, unsigned int);
};

extern char g_011cba30;
extern char g_011cbcb0;
extern char g_011d38b8;

unsigned char* __cdecl _FUN_004b7210(void);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl Interface_CreateMessageMenuSound(const char*, const char*, const char*, const char*, void(__cdecl*)(), int, int, float, float,
                          const char*, int);

// @fnv 0x006155f0
void TESReputation::ShowMessageBox(void)
{
    char buffer[0x200];

    _sprintf_s(buffer, 0x200, "%s\n%s", FUN_00616710(), GetSelectedSettingString());

    reinterpret_cast<TutorialState*>(reinterpret_cast<unsigned char*>(_FUN_004b7210()) + 0x4d4)
        ->ShowMessage(0x27, 0, 0x1f4);

    if (m_eReputationType == ReputationType_REPUTATION_POSITIVE)
    {
        Interface_CreateMessageMenuSound(buffer, TESReputation_GetThresholdIcon(), TESFullName::GetFullName(),
                     reinterpret_cast<Setting*>(&g_011cbcb0)->String(), FakeModalMessageMenuCallback, 1, 0x17, 0.0f, 0.0f,
                     reinterpret_cast<Setting*>(&g_011d38b8)->String(), 0);
    }
    else
    {
        Interface_CreateMessageMenuSound(buffer, TESReputation_GetThresholdIcon(), TESFullName::GetFullName(),
                     reinterpret_cast<Setting*>(&g_011cba30)->String(), FakeModalMessageMenuCallback, 1, 0x17, 0.0f, 0.0f,
                     reinterpret_cast<Setting*>(&g_011d38b8)->String(), 0);
    }
}

// @fnv 0x006154b0
TESReputation::~TESReputation()
{
    TESForm::ClearData();
}

extern Setting DAT_011cba7c;
extern Setting DAT_011cbc70;
extern Setting DAT_011cbd68;
// @fnv 0x00616950
unsigned char ReputationOperations::GetReputationRank(int kind)
{
    float value = 0.0f;
    unsigned char rank = 0;
    if (kind == 1)
    {
        value = TESReputation_GetPositiveRatio();
    }
    else
    {
        value = TESReputation_GetNegativeRatio();
    }
    if (value >= *DAT_011cba7c.Setting_Float_00403e20() && value < *DAT_011cbc70.Setting_Float_00403e20())
    {
        rank = 1;
    }
    else if (value >= *DAT_011cbc70.Setting_Float_00403e20() && value < *DAT_011cbd68.Setting_Float_00403e20())
    {
        rank = 2;
    }
    else if (value >= *DAT_011cbd68.Setting_Float_00403e20())
    {
        rank = 3;
    }
    return rank;
}

// Multiple-inheritance constructor: base A (0x18 bytes, out-of-line ctor),
// base B (4 bytes, vptr only, also the element type of the member array),
// base C (16 bytes, 8-aligned, out-of-line ctor), then an array of eight B
// members, a member call with 15, and a second member call.
struct BaseComponentA
{
    BaseComponentA();
    virtual void unk00();
    ~BaseComponentA();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct BaseComponentB
{
    BaseComponentB();
    virtual void unk00();
    int unk04;
};

struct BaseComponentC
{
    BaseComponentC();
    virtual void unk00();
    ~BaseComponentC();
    __int64 unk08;
};

struct FUN_00617da0 : public BaseComponentA, public BaseComponentB, public BaseComponentC
{
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    BaseComponentB unk40[4];
    FUN_00617da0();
    void unk60(int value);
    void unk64();
};

// Initializes the object by calling unk60 with 15 and then unk64.
// @fnv 0x00617da0
FUN_00617da0::FUN_00617da0()
{
    unk60(15);
    unk64();
}

struct FUN_00617f40_Primary
{
    virtual ~FUN_00617f40_Primary();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct FUN_00617f40_Base18
{
    virtual void unk00();
    unsigned int unk04;
};

struct FUN_00617f40_Base20
{
    virtual ~FUN_00617f40_Base20();
    unsigned int unk04;
};

struct FUN_00617f40 : FUN_00617f40_Primary, FUN_00617f40_Base18, FUN_00617f40_Base20
{
    virtual ~FUN_00617f40();
};

// @fnv 0x00617f40
FUN_00617f40::~FUN_00617f40()
{}

extern Setting DAT_011cbb98, DAT_011cbc34, DAT_011cba94, DAT_011cba00;
extern PlayerCharacter* _g_thePlayer;
bool __cdecl IsInDialog();
bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
// @fnv 0x00615a00
// src: COMMUNITY 0x00615a00
void TESReputation::RemoveReputationExact(int kind, float amount)
{
    bool changed = false;
    char oldRank = 0;
    char newRank = 0;
    char message3[250];
    oldRank = static_cast<ReputationOperations&>(*this).GetReputationRank(kind);
    if (kind == 1)
    {
        m_fFirstReputationValue -= amount;
        m_fFirstReputationValue = m_fFirstReputationValue < 0.0 ? 0.0f : m_fFirstReputationValue;
        _sprintf_s(message3, 250, "%s\n%s", TESFullName::GetFullName(), DAT_011cbb98.FUN_00403df0());
        newRank = static_cast<ReputationOperations&>(*this).GetReputationRank(1);
        if (newRank != oldRank)
        {
            m_eReputationType = ReputationType_REPUTATION_NEGATIVE;
            changed = true;
        }
        QueueUIMessage(message3, 0, DAT_011cbc34.FUN_00403df0(), 0, 2.0f, false);
    }
    else
    {
        m_fSecondReputationValue -= amount;
        m_fSecondReputationValue = m_fSecondReputationValue < 0.0 ? 0.0f : m_fSecondReputationValue;
        _sprintf_s(message3, 250, "%s\n%s", TESFullName::GetFullName(), DAT_011cba94.FUN_00403df0());
        newRank = static_cast<ReputationOperations&>(*this).GetReputationRank(0);
        if (newRank != oldRank)
        {
            m_eReputationType = ReputationType_REPUTATION_POSITIVE;
            changed = true;
        }
        QueueUIMessage(message3, 0, DAT_011cba00.FUN_00403df0(), 0, 2.0f, false);
    }
    if (changed && !_g_thePlayer->PlayerCharacter_IsPlayerCharacterInCombat(0) && !IsInDialog())
        ShowMessageBox();
    else if (changed)
        static_cast<PlayerReputationQueue*>(_g_thePlayer)->SetValue(this);
    MarkAsModified(2);
}

extern Setting DAT_011cbc88;
extern Setting DAT_011cbcc8;
extern Setting DAT_011cba70;
extern Setting DAT_011cbc54;
extern Setting DAT_011cbb70;
extern Setting DAT_011cbac0;
extern Setting DAT_011cba58;
extern Setting DAT_011cbd5c;
extern Setting DAT_011cbad0;
extern PlayerCharacter* DAT_011dea3c;
bool __cdecl Interface_InDialog();
bool __cdecl DispatchMessageToSink(const char*, int, const char*, const char*, float, bool);
// @fnv 0x00615c90
void TESReputation::ApplyReputationChange(int iReputationType, int amount)
{
    if (amount <= 0 || amount >= 6)
        return;
    bool p = false;
    char j = 0;
    char c = 0;
    Setting* e[5] = {&DAT_011cbc88, &DAT_011cbcc8, &DAT_011cba70, &DAT_011cbc54, &DAT_011cbb70};
    char l[250];
    j = static_cast<ReputationOperations&>(*this).GetReputationRank(iReputationType);
    if (iReputationType == 1)
    {
        m_fFirstReputationValue += *e[amount - 1]->Setting_Float_00403e20();
        m_fFirstReputationValue =
            m_fFirstReputationValue > data.m_fMaximumReputation ? data.m_fMaximumReputation : m_fFirstReputationValue;
        _sprintf_s(l, 250, "%s\n%s", TESFullName::GetFullName(), DAT_011cbac0.FUN_00403df0());
        c = static_cast<ReputationOperations&>(*this).GetReputationRank(1);
        if (c != j)
        {
            m_eReputationType = ReputationType_REPUTATION_POSITIVE;
            p = true;
        }
        DispatchMessageToSink(l, 0, DAT_011cbd5c.FUN_00403df0(), 0, 2.0f, false);
    }
    else
    {
        m_fSecondReputationValue += *e[amount - 1]->Setting_Float_00403e20();
        m_fSecondReputationValue =
            m_fSecondReputationValue > data.m_fMaximumReputation ? data.m_fMaximumReputation : m_fSecondReputationValue;
        _sprintf_s(l, 250, "%s\n%s", TESFullName::GetFullName(), DAT_011cba58.FUN_00403df0());
        c = static_cast<ReputationOperations&>(*this).GetReputationRank(0);
        if (c != j)
        {
            m_eReputationType = ReputationType_REPUTATION_NEGATIVE;
            p = true;
        }
        DispatchMessageToSink(l, 0, DAT_011cbad0.FUN_00403df0(), 0, 2.0f, false);
    }
    if (p && !DAT_011dea3c->PlayerCharacter_IsPlayerCharacterInCombat(0) && !Interface_InDialog())
        ShowMessageBox();
    else if (p)
        static_cast<PlayerReputationQueue*>(DAT_011dea3c)->SetValue(this);
    MarkAsModified(2);
}

namespace fnv_00615fa0 {
extern Setting g_011cbc88, originalRuntimeFloatSetting52, originalRuntimeFloatSetting53,
    originalRuntimeFloatSetting54, originalRuntimeFloatSetting55;
extern Setting g_011cbb98, g_011cbc34, g_011cba94, g_011cbad0;
extern PlayerCharacter* _g_thePlayer;
bool IsInDialog();
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
int _sprintf_s(char*, unsigned int, const char*, ...);
}  // namespace fnv_00615fa0

// @fnv 0x00615fa0
// src: COMMUNITY 0x00615fa0
void TESReputation::RemoveReputation(int kind, int amount)
{
    bool changed = false;
    char oldRank = 0;
    char newRank = 0;
    char message3[250];
    if (amount <= 0 || amount >= 6)
        return;
    Setting* settings3[5] = {&fnv_00615fa0::g_011cbc88, &fnv_00615fa0::originalRuntimeFloatSetting52, &fnv_00615fa0::originalRuntimeFloatSetting53,
                                &fnv_00615fa0::originalRuntimeFloatSetting54, &fnv_00615fa0::originalRuntimeFloatSetting55};
    oldRank = static_cast<ReputationOperations&>(*this).GetReputationRank(kind);
    if (kind == 1)
    {
        m_fFirstReputationValue -= *settings3[amount - 1]->Float();
        m_fFirstReputationValue = m_fFirstReputationValue < 0.0 ? 0.0f : m_fFirstReputationValue;
        fnv_00615fa0::_sprintf_s(message3, 250, "%s\n%s", TESFullName::GetFullName(), fnv_00615fa0::g_011cbb98.String());
        newRank = static_cast<ReputationOperations&>(*this).GetReputationRank(1);
        if (newRank != oldRank)
        {
            m_eReputationType = ReputationType_REPUTATION_NEGATIVE;
            changed = true;
        }
        fnv_00615fa0::QueueUIMessage(message3, 0, fnv_00615fa0::g_011cbc34.String(), 0, 2.0f, false);
    }
    else
    {
        m_fSecondReputationValue -= *settings3[amount - 1]->Float();
        m_fSecondReputationValue = m_fSecondReputationValue < 0.0 ? 0.0f : m_fSecondReputationValue;
        fnv_00615fa0::_sprintf_s(message3, 250, "%s\n%s", TESFullName::GetFullName(), fnv_00615fa0::g_011cba94.String());
        newRank = static_cast<ReputationOperations&>(*this).GetReputationRank(0);
        if (newRank != oldRank)
        {
            m_eReputationType = ReputationType_REPUTATION_POSITIVE;
            changed = true;
        }
        fnv_00615fa0::QueueUIMessage(message3, 0, fnv_00615fa0::g_011cbad0.String(), 0, 2.0f, false);
    }
    if (changed && !fnv_00615fa0::_g_thePlayer->PlayerCharacter_IsPlayerCharacterInCombat(0) && !fnv_00615fa0::IsInDialog())
        ShowMessageBox();
    else if (changed)
        static_cast<PlayerReputationQueue*>(fnv_00615fa0::_g_thePlayer)->SetValue(this);
    MarkAsModified(2);
}

extern SettingT_GameSettingCollection_ g_011cbac0;
extern SettingT_GameSettingCollection_ g_011cba58;
extern SettingT_GameSettingCollection_ g_011cbd5c;
extern SettingT_GameSettingCollection_ g_011cbad0;
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
// Exe 0x00615730: unit-local Interface view; declarations and layout are preserved.
struct TesreputationInterfaceView
{
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
    static bool IsInDialog();
};
extern PlayerCharacter* g_thePlayer;

// @fnv 0x00615730
// src: XBOX_PDB 0x00615730
void TESReputation::AddReputationValue(int kind, float delta)
{
    signed char val;
    bool changed;
    char i[250];
    signed char after;
    changed = false;
    val = 0;
    after = 0;
    val = (char)static_cast<ReputationOperations&>(*this).GetReputationRank(kind);
    if (kind == 1)
    {
        m_fFirstReputationValue += delta;
        m_fFirstReputationValue = (m_fFirstReputationValue > data.m_fMaximumReputation) ? (float)data.m_fMaximumReputation
                                                                                   : (float)m_fFirstReputationValue;
        _sprintf_s(i, 250, "%s\n%s", TESFullName::GetFullName(), g_011cbac0.String());
        after = (char)static_cast<ReputationOperations&>(*this).GetReputationRank(1);
        if (after != val)
        {
            m_eReputationType = ReputationType_REPUTATION_POSITIVE;
            changed = true;
        }
        TesreputationInterfaceView::ShowMessage(i, 0, g_011cbd5c.String(), 0, 2.0f, false);
    }
    else
    {
        m_fSecondReputationValue += delta;
        m_fSecondReputationValue = (m_fSecondReputationValue > data.m_fMaximumReputation) ? (float)data.m_fMaximumReputation
                                                                                     : (float)m_fSecondReputationValue;
        _sprintf_s(i, 250, "%s\n%s", TESFullName::GetFullName(), g_011cba58.String());
        after = (char)static_cast<ReputationOperations&>(*this).GetReputationRank(0);
        if (after != val)
        {
            changed = true;
            m_eReputationType = ReputationType_REPUTATION_NEGATIVE;
        }
        TesreputationInterfaceView::ShowMessage(i, 0, g_011cbad0.String(), 0, 2.0f, false);
    }
    if (changed && !g_thePlayer->PlayerCharacter_IsPlayerCharacterInCombat(0) && !TesreputationInterfaceView::IsInDialog())
    {
        ShowMessageBox();
    }
    else if (changed)
    {
        static_cast<PlayerReputationQueue*>(g_thePlayer)->SetValue(this);
    }
    MarkAsModified(2);
}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);

// @fnv 0x00616570
bool ReputationOperations::CompareReputation(TESForm* other)
{
    TESReputation* pOtherReputation = dynamic_cast<TESReputation*>(other);
    if (!pOtherReputation)
        return true;
    if (_memcmp(&data, static_cast<ReputationOperations*>(pOtherReputation)->GetReputationData(),
                sizeof(ReputationLimitData)) != 0)
        return true;
    if (CompareBase(pOtherReputation))
        return true;
    return false;
}

extern "C" void* __cdecl _memcpy(void*, const void*, unsigned int);

struct ReputationComponentCopy
{
    void TESForm_CopyAllComponents(TESForm* source);
};

// Copies the two reputation values and the data block from source (cast to TESReputation) into this object, then calls FUN_004851b0 with source.
// @fnv 0x00616500
void ReputationOperations::CopyReputation(TESForm* source)
{
    TESReputation* reputation = dynamic_cast<TESReputation*>(source);
    if (!reputation)
        return;

    m_fSecondReputationValue = reputation->m_fSecondReputationValue;
    m_fFirstReputationValue = reputation->m_fFirstReputationValue;
    _memcpy(&data, &reputation->data, sizeof(data));
    reinterpret_cast<ReputationComponentCopy*>(this)->TESForm_CopyAllComponents(source);
}
