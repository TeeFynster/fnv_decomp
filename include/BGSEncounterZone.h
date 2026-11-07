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
    void SetDetachTime_00526070(unsigned int time);
    void SetAttachTime(unsigned int time);
    bool ShouldCellRecalc(TESObjectCELL* cell);
    void SetZoneLevel(unsigned short level);
    void DetermineLevel();
    bool QNeverReset();
    virtual void SaveGame(BGSSaveFormBuffer* buffer);
    void LoadGame_005264a0(BGSLoadFormBuffer* buffer);
    void RevertAndClearIfChanged(BGSLoadFormBuffer* buffer);
    bool Compare_00526000(TESForm* other);
    void Copy_00525fa0(TESForm* source);

    static void CreateDefaultEncounterZone();
    static BGSEncounterZone* ms_pDefaultEncounterZone;

    EncounterZoneData Data;
    CellDetachData GameData;
};
