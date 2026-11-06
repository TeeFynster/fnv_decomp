#pragma once

#include "TESBoundObject.h"
#include "MagicItem.h"

class MagicItemObject : public TESBoundObject, public MagicItem
{
public:
    MagicItemObject();
    virtual ~MagicItemObject();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();
    virtual void vfn_180();

    // Alternate names for inherited virtual slots.
    void ResetFormData();
    bool Load(TESFile* file);

    bool IsFormInitialized() const;
};
