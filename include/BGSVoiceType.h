#pragma once

#include "TESForm.h"

class TESFile;

class BGSVoiceType : public TESForm
{
public:
    struct VoiceTypeString
    {
        char* unk00;
        unsigned short unk04;
        unsigned short unk06;

        ~VoiceTypeString();
    };

    BGSVoiceType();
    virtual ~BGSVoiceType();

    virtual void ClearData();
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void SaveForm();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* file);
    void FUN_005f0140();
    void FUN_005f02a0(TESForm* form);
    bool FUN_005f02f0(TESForm* form);
    void FUN_004851b0(TESForm* form);
    bool FUN_00485270(TESForm* form);

    union
    {
        unsigned char formData[0xc];
        struct
        {
            char Data;
            unsigned char unk19[3];
            VoiceTypeString unk1c;
        };
    };
};
