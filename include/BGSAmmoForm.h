#pragma once

#include "BaseFormComponent.h"

class TESAmmo;
class TESForm;

class BGSAmmoForm : public BaseFormComponent
{
public:
    BGSAmmoForm();
    // no user destructor: TESObjectWEAP::TESObjectWEAP (0x0051d770) keeps no unwind state for this base
    BGSAmmoForm& operator=(const BGSAmmoForm&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitItem(TESForm* form);
    void SetAmmo(TESAmmo* ammo);
    TESAmmo* GetAmmoHelper();

    TESForm* m_pAmmo;
};
