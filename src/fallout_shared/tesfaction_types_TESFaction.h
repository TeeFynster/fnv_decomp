// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESFACTION_H
#define FNV_TESFACTION_H

#include "layout_support.h"
#include "tesfaction_form.h"
#include "../../include/TESFullName.h"
#include "TESReactionForm.h"
#include "layout_support.h"
class FactionSaveData;
class FactionRankPresentation;
class TESReputation;
#pragma pack(push, 4)
class FactionSaveData
{
  public:
    void Endian();
    unsigned int iFlags;  // +0x0, 4 bytes
    // void __cdecl FactionSaveData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FactionSaveData) == 4);
FNV_STATIC_ASSERT(offsetof(FactionSaveData, iFlags) == 0);
#pragma pack(push, 4)
class TESFaction : public TESForm, public TESFullName, public TESReactionForm
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    // base TESReactionForm at +0x24, size 16
    FactionSaveData data;                                    // +0x34, 4 bytes
    TESReputation* pReputationData;                          // +0x38, 4 bytes
    BSSimpleList<FactionRankPresentation*> m_kRankDataList;  // +0x3C, 8 bytes
    int m_iFirstFactionValue;                                // +0x44, 4 bytes
    int m_iSecondFactionValue;                               // +0x48, 4 bytes
    void ClearData();
    void ResetFormData();
    void InitLoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void ClearReactions();
    void InitItem();
    void LoadGame(BGSLoadFormBuffer*);
    int InitializeFaction();
    BSSimpleList<FactionRankPresentation*>* GetRankDataList();
    bool Load(TESFile*);
    // TESFaction
    // void __cdecl TESFaction::*()
    // void __cdecl TESFaction::*()
    // void __cdecl TESFaction::*()
    // void __cdecl TESFaction::*()
    // bool __cdecl TESFaction::*(TESFile*)
    // void __cdecl TESFaction::*(TESForm*)
    // bool __cdecl TESFaction::*(TESForm*)
    // void __cdecl TESFaction::*()
    // FactionSaveData* __cdecl TESFaction::*()
    // int __cdecl TESFaction::*()
    // GetRankName
    // void __cdecl TESFaction::*(int, SEX, char*)
    // const char* __cdecl TESFaction::*(int)
    // void __cdecl TESFaction::*(int, const char*)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // bool __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(bool)
    // void __cdecl TESFaction::*(int, bool)
    // void __cdecl TESFaction::*(int)
    // int __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(int, bool)
    // void __cdecl TESFaction::*(int)
    // int __cdecl TESFaction::*()
    // int __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(TESFaction*, int)
    // int __cdecl TESFaction::*(TESFaction*)
    // void __cdecl TESFaction::*(TESFaction*, int)
    // void __cdecl TESFaction::*(TESFaction*, int)
    // FIGHT_REACTION __cdecl TESFaction::*(TESFaction*)
    // unsigned short __cdecl TESFaction::*(unsigned int)
    // SaveGame
    // LoadGame
    // InitLoadGame
    // void __cdecl TESFaction::*(BGSLoadFormBuffer*)
    // void __cdecl TESFaction::*()
    // TESReputation* __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(TESReputation*)
    // void __cdecl TESFaction::*(unsigned int, bool)
    // BSSimpleList<FactionRankPresentation *>* __cdecl TESFaction::*()
    // void __cdecl TESFaction::*()
    // void __cdecl TESFaction::*(FactionRankPresentation*)
    // FactionRankPresentation* __cdecl TESFaction::*(int)
    // void __cdecl TESFaction::*(int, FactionRankPresentation*)
    // TESFaction& __cdecl TESFaction::*(const TESFaction&)
    // void __cdecl TESFaction::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESFaction) == 76);
FNV_STATIC_ASSERT(offsetof(TESFaction, data) == 52);
FNV_STATIC_ASSERT(offsetof(TESFaction, pReputationData) == 56);
FNV_STATIC_ASSERT(offsetof(TESFaction, m_kRankDataList) == 60);
FNV_STATIC_ASSERT(offsetof(TESFaction, m_iFirstFactionValue) == 68);
FNV_STATIC_ASSERT(offsetof(TESFaction, m_iSecondFactionValue) == 72);
#endif
