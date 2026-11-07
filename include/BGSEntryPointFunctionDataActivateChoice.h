#pragma once

#include "BGSEntryPointFunctionData.h"
#include "Script.h"

class EntryPointScriptOperations;

class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
{
public:
    BGSEntryPointFunctionDataActivateChoice();
    virtual ~BGSEntryPointFunctionDataActivateChoice();
    virtual void InitItem(TESForm* form);

    char* choiceText;
    union
    {
        struct
        {
            Script resultScript;
        };
        struct
        {
            unsigned int unk08;
            unsigned int unk0C;
            unsigned int unk10;
            unsigned int unk14;
            unsigned int unk18;
            unsigned int unk1C;
            unsigned int unk20;
            unsigned int unk24;
            unsigned int unk28;
            unsigned int unk2C;
            unsigned int unk30;
            unsigned int unk34;
            unsigned int unk38;
            unsigned int unk3C;
            unsigned int unk40;
            unsigned int unk44;
            unsigned int unk48;
            unsigned int unk4C;
            unsigned int unk50;
            unsigned int unk54;
            unsigned int unk58;
        };
    };
    unsigned short flags;
    unsigned short unk5E;

    void InitializeComponent();
    void FUN_005e6c30();
    void SetLabel(const char* text);
    BGSEntryPointFunctionData* Duplicate_005e6cd0();
    bool Compare_005e6d80(BGSEntryPointFunctionData* other);
    void Save_005e6e50();
    void FUN_005e6600();
    void* FUN_005e65d0(unsigned int flags);
    EntryPointScriptOperations* FUN_00413f40();
    Script& GetName();
};
