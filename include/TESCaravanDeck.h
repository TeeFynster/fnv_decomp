#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "CaravanDeckData.h"

class TESCaravanCard;

class TESCaravanDeck : public TESForm, public TESFullName
{
public:
    BSSimpleList<TESCaravanCard*>* m_pCardListHeadCur;
    CaravanDeckData data;

    TESCaravanDeck();

    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    BSSimpleList<TESCaravanCard*>* GetCardList();
    CaravanDeckData* GetDeckData();
};
