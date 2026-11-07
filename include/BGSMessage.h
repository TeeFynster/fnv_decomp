#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "MagicTarget.h"

class BGSMenuIcon;
class PerkButtonEntry;

class BGSMessage : public TESForm, public TESFullName, public TESDescription
{
public:
    BGSMenuIcon* pIcon;
    BSSimpleList<PerkButtonEntry*> m_kButtonEntries;
    unsigned int iFlags;
    unsigned int m_uiDisplayDuration;

    BGSMessage();
    virtual ~BGSMessage();
    virtual void ClearData();
    virtual void InitItem();

    void ResetFormData();
    void ClearButtons();
    void SetIcon(BGSMenuIcon* icon);
    bool Load(TESFile* file);

    void AddButton(PerkButtonEntry* button);
    void WriteToStream();
    void CopyFromMessage(TESForm* form);
    bool IsNotEqual(TESForm* form);

    BGSMenuIcon* GetIcon();
    bool GetAutoDisplay();
    void SetAutoDisplay(bool value);
    bool GetMessageBoxFlag();
    void SetMessageBoxFlag(bool value);
    TESForm* GetQuest();
    void SetQuest(TESForm* quest);
    BSSimpleList<PerkButtonEntry*>* GetButtonList();
    void CopyBase(TESForm* form);

    bool GetIsMessageBox();
    bool IsFlagSet();
    void SetEnabled(bool enabled);
    void SetAutoDisplay_00590ef0(bool enabled);
    void AddButton_005911d0(PerkButtonEntry* button);
};
