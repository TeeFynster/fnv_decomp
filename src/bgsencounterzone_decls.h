// Retained locally: include/BGSEncounterZone.h lacks the save/load,
// comparison and detach-record methods implemented by this unit.
#ifndef FNV_BGSENCOUNTERZONE_H
#define FNV_BGSENCOUNTERZONE_H

#include "../include/TESForm.h"
#include "../include/EncounterZoneData.h"
#include "../include/CellDetachData.h"
class BGSEncounterZone : public TESForm
{
  public:
    unsigned short GetCalculatedLevel();
    bool QMatchPCBelowMin();
    unsigned char GetByteAt1D();
    BGSEncounterZone();
    virtual ~BGSEncounterZone();
    void ResetFormData();
    bool Load(TESFile* file);
    virtual void InitItem();
    void Save();
    void FUN_00526070(unsigned int time);
    void FUN_005260a0(unsigned int time);
    bool FUN_00526120(TESObjectCELL* cell);
    void FUN_00526160(unsigned short level);
    void FUN_00526270();
    bool FUN_00526320();
    void SaveGame(BGSSaveFormBuffer* buffer);
    void FUN_005264a0(BGSLoadFormBuffer* buffer);
    void RevertAndClearIfChanged(BGSLoadFormBuffer* buffer);
    bool FUN_00526000(TESForm* other);
    void FUN_00525fa0(TESForm* source);
    static void CreateDefaultEncounterZone();
    static BGSEncounterZone* ms_pDefaultEncounterZone;
    // base TESForm at +0x0, size 24
    EncounterZoneData Data;   // +0x18, 8 bytes
    CellDetachData GameData;  // +0x20, 16 bytes
};
FNV_STATIC_ASSERT(sizeof(BGSEncounterZone) == 48);
FNV_STATIC_ASSERT(offsetof(BGSEncounterZone, Data) == 24);
FNV_STATIC_ASSERT(offsetof(BGSEncounterZone, GameData) == 32);
#endif