#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "TESScriptableForm.h"
#include "TESDescription.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSMessageIcon.h"
#include "BGSPickupPutdownSounds.h"

class TESFile;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;

class TESObjectIMOD : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESDescription,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
public:
    TESObjectIMOD();
    virtual ~TESObjectIMOD();
    bool Load(TESFile*);
    virtual void InitItem();
    virtual void LoadGameLegacy(unsigned int changedFlags, unsigned int currentFlags);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    void* Destroy(unsigned int flags);
    unsigned short GetSaveSizeLegacy(unsigned int flags);
    virtual void SaveGameLegacy(unsigned int flags);
    virtual void SaveGame(BGSSaveFormBuffer* buffer);
    void SaveRecord();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    void Shutdown();
};
