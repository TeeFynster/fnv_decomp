#pragma once

#include "BaseFormComponent.h"
#include "TESForm.h"

class TESSound;

class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
    TESSound* m_pPickupSound;
    TESSound* m_pPutdownSound;

    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();

    void InitItem(TESForm* form);
    void SetPickupSound(TESSound* sound);
    void SetPutdownSound(TESSound* sound);
    void SavePickupChunk();
};
