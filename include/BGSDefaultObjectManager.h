#pragma once

#include "TESForm.h"

enum DEFAULT_OBJECT;

class BGSDefaultObjectManager : public TESForm
{
public:
    TESForm* m_apDefaultObjects[34];

    BGSDefaultObjectManager();
    virtual ~BGSDefaultObjectManager();

    virtual void InitItem();

    void ResetFormData();
    void Save();
    bool IsFormInitialized() const;
    bool Load(TESFile* file);

    static BGSDefaultObjectManager* Instance();
    static TESForm* GetDefaultObjectByIndex(DEFAULT_OBJECT index);
    static TESForm* GetDefaultObjectByIndex(int index);
    static BGSDefaultObjectManager* ms_pSystemUtility;
};
