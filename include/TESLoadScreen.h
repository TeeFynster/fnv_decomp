#pragma once

#include "TESForm.h"
#include "TESTexture.h"
#include "TESDescription.h"
#include "MagicTarget.h"
#include "TESFullName.h"
#include "TESLoadScreenType.h"

class WorldCellRecord;

class TESLoadScreen : public TESForm, public TESTexture, public TESDescription
{
public:
    TESLoadScreen();
    virtual ~TESLoadScreen();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual void InitItem();

    bool Load(TESFile* file);
    void ClearLoadScreenData();
    bool MatchesFormLocation(TESForm* form);
    bool IsRefFlag400Set();
    bool IsDefaultLoadScreen();
    int GetLoadScreenTypeDataType();
    TESLoadScreenType* GetLoadScreenType();
    void SetLoadScreenType(TESLoadScreenType* type);
    void CopyFormData(TESForm* form);
    void CopyLoadScreenData(TESForm* form);
    bool CompareFormData(TESLoadScreen* form);
    bool CompareLoadScreenData(void* form);

    BSSimpleList<WorldCellRecord*> m_kWorldCellRecordList;
    TESLoadScreenType* m_pLoadScreenType;
    BSStringT<char> m_kLoadScreenText;
};
