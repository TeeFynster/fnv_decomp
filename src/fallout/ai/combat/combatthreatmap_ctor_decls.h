// fallout/ai/combat/combatthreatmap_ctor_decls.h: local LocalCombatThreatMap constructor dependencies
#ifndef FNV_ASTRA_COMBATTHREATMAP_H
#define FNV_ASTRA_COMBATTHREATMAP_H

#include <stddef.h>
#include "../../../../include/CombatTargetTimestamp.h"
#include "../../../../include/NiTMap.h"
#include "../../../../include/NiPointer.h"
// CombatThreatRecord_combatthreatmap_ctor_decls: local type (was include/CombatThreatRecord.h, which had no evidence of one real class); its methods are 0x009a4f40 SandBoxChoiceListItem::InitLoadGame, 0x009a5170 CombatThreat::IsExpired, 0x009a5e50 NiTMapBase<DFALL<NiTMapItem<unsigned int,CombatThreat *> >,unsigned int,CombatThreat *>::~NiTMapBase<DFALL<NiTMapItem<unsigned int,CombatThreat *> >,unsigned int,CombatThreat *>
class BGSLoadGameBuffer;

class CombatThreatRecord_combatthreatmap_ctor_decls
{
public:
    void* vfn_00;
    int pad_04;
    void* p_08;

    ~CombatThreatRecord_combatthreatmap_ctor_decls();
    bool IsXLessThan(float);
    void LoadGame(BGSLoadGameBuffer*);
    void __thiscall SetVtableAndProcessState_009a5e50();
};
class TESForm;
class ReadWriteLock
{
  public:
    volatile unsigned int m_uiLockState;
    unsigned int m_uiWriterThreadId;
};
extern float DAT_0108d9b0;
class FUN_00906f60
{
  public:
    unsigned int data[2];
    FUN_00906f60();
};
class NiAVObject;
class FUN_00993960
{
  public:
    NiTMap<unsigned int, CombatThreatRecord_combatthreatmap_ctor_decls*> map;
    ReadWriteLock Lock;
    unsigned int padding[2];
    FUN_00993960(int, int);
    ~FUN_00993960();
};
// LocalCombatThreatMap: unit-local CombatThreatMap: its ctor 0x00991080 builds the map through the out-of-line base ctor 0x00993960(0, 1), unlike the shared class (NiTMap base, inline lock/pair members)
class LocalCombatThreatMap : public FUN_00993960
{
  public:
    CombatTargetTimestamp stamp;
    FUN_00906f60 pair1, pair2;
    unsigned int mode;
    NiPointer<NiAVObject> object;
    LocalCombatThreatMap();
    void InitThreatObjects();
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
};
#endif
