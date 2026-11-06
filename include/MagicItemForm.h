#pragma once

#include "TESForm.h"
#include "MagicItem.h"

class MagicItemForm : public TESForm, public MagicItem
{
public:
    MagicItemForm();
    virtual ~MagicItemForm();

    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void InitItem();
    virtual void SetAltered(bool set);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual void Endian();

    bool Load(TESFile* file);
};
