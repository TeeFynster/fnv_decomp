// fallout_shared/tessaveloadgame_decls.h: declares TESForm, ChangesMap, TESSaveLoadGame, BSTaskManagerThread
#pragma once

class TESForm
{
  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    unsigned int GetFormID();
    bool IsTemporary() const;
};
class TESObjectREFR;
template <class K, class V> class NiTPointerMap
{
  public:
    bool GetAt(K, V&) const;
};
class ChangesMap : public NiTPointerMap<unsigned int, TESObjectREFR*>
{
  public:
    bool HasFormChanges(TESForm*, bool);
    bool RemoveChanges(unsigned int, bool);
};
class BGSNote;
class BGSCameraShot;
template <class T> class BSSimpleList
{
  public:
    bool IsInList(T&);
    void Remove(T const&);
};
class TESSaveLoadGame
{
  public:
    ChangesMap* changes;
    char pad[0x30];
    BSSimpleList<BGSNote*> deferred;
    TESObjectREFR* QueueRemoveReferenceChange(unsigned int);
    void HasFormChanges(TESForm*, bool);
    void FinalizeForm(TESForm*);
};
class BSTaskManagerThread
{
  public:
    void* table;
    char pad[0x2c];
    void* manager;
    void FUN_00c42dd0(unsigned int, const char*);
    BSTaskManagerThread(void*, unsigned int);
};
extern void* DAT_010c1740[];

extern const char DAT_010c1748[];
