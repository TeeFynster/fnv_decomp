#pragma once

#include "TESForm.h"
#include "EncounterZoneData.h"
#include "CellDetachData.h"

class TESObjectCELL;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

struct BGSEncounterZone : public TESForm
{
public:
    BGSEncounterZone();
    virtual ~BGSEncounterZone();

    void ResetFormData();
    bool Load(TESFile* file);
    virtual void InitItem();
    unsigned short GetCalculatedLevel();
    bool QMatchPCBelowMin();
    unsigned char GetByteAt1D();

    void Save();
    void FUN_00526070(unsigned int time);
    void FUN_005260a0(unsigned int time);
    bool FUN_00526120(TESObjectCELL* cell);
    void FUN_00526160(unsigned short level);
    void FUN_00526270();
    bool FUN_00526320();
    virtual void SaveGame(BGSSaveFormBuffer* buffer);
    void FUN_005264a0(BGSLoadFormBuffer* buffer);
    void RevertAndClearIfChanged(BGSLoadFormBuffer* buffer);
    bool FUN_00526000(TESForm* other);
    void FUN_00525fa0(TESForm* source);

    static void CreateDefaultEncounterZone();
    static BGSEncounterZone* ms_pDefaultEncounterZone;

    EncounterZoneData Data;
    CellDetachData GameData;
};
