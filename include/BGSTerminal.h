#pragma once

#include <stddef.h>
#include "TESObjectACTI.h"
#include "TESDescription.h"
#include "MagicTarget.h"
#include "TerminalCompareData.h"

class BGSNote;
class TerminalMenuItem;

class BGSTerminal : public TESObjectACTI, public TESDescription
{
public:
    BGSTerminal();
    virtual ~BGSTerminal();

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual void InitItem(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    void BGSTerminal_SetPassword(BGSNote* note);
    void AddMenuItem(TerminalMenuItem* item);
    BSSimpleList<TerminalMenuItem*>* FUN_00461150();

    BSSimpleList<TerminalMenuItem*> m_kMenuItems;
    BGSNote* pPassword;
    TerminalCompareData Data;
};

typedef char BGSTerminal_size_check[(sizeof(BGSTerminal) == 0xA8) ? 1 : -1];
typedef char BGSTerminal_menu_items_offset_check[(offsetof(BGSTerminal, m_kMenuItems) == 0x98) ? 1 : -1];
typedef char BGSTerminal_password_offset_check[(offsetof(BGSTerminal, pPassword) == 0xA0) ? 1 : -1];
typedef char BGSTerminal_data_offset_check[(offsetof(BGSTerminal, Data) == 0xA4) ? 1 : -1];
