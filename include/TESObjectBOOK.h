#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "TESScriptableForm.h"
#include "TESEnchantableForm.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
#include "TESDescription.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSMessageIcon.h"
#include "BGSPickupPutdownSounds.h"
#include "BookData.h"

class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

class TESObjectBOOK : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESDescription,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
public:
    TESObjectBOOK();
    virtual ~TESObjectBOOK();

    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void SaveGame(BGSSaveFormBuffer* buffer);
    virtual void SaveGameLegacy(unsigned int changedFlags);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void LoadGameLegacy(unsigned int changedFlags, unsigned int currentFlags);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    TESObjectBOOK& operator=(const TESObjectBOOK& other);

    void ResetFormData();
    bool Load(TESFile* file);
    void Destroy();
    void CopyBookData(TESForm* source);
    BookData* FUN_00514f30();
    bool FUN_00514f50(TESForm* other);
    unsigned short FUN_00515220(unsigned int flags);
    void FUN_00515290(unsigned int flags);
    void FUN_005152e0(unsigned int flags, unsigned int currentFlags);
    void FUN_00515340(BGSSaveFormBuffer* buffer);
    void FUN_005153a0(BGSLoadFormBuffer* buffer);
    bool FUN_00409700();

    BookData Data;
    unsigned char layoutPaddingC2[2];
};
