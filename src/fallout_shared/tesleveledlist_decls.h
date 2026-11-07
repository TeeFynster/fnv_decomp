// Remaining local declarations for tesleveledlist_ob1_variant.cpp.
#ifndef FNV_TESLEVELEDLIST_WORKER_DECLS_H
#define FNV_TESLEVELEDLIST_WORKER_DECLS_H

extern unsigned int DAT_010a2480;

class ContainerItemExtra
{
  public:
    unsigned int data[3];
    ContainerItemExtra();
    void ContainerItemExtra_AdjustHealthPercent(float);
    void InitItem(TESForm*);
};
class LeveledObject;

class TESGlobalValueReader
{
  public:
    float GetValue();
};

class PerkEntryConditionSet;
class PlayerQuestData
{
  public:
    PerkEntryConditionSet* GetConditions();
};
class BGSCameraShot;
class ActorCause;

class MersenneTwister
{
  public:
    static MersenneTwister* GetRandomGenerator();
    unsigned int GetRandomUInt();
};
unsigned int DialogueRandom();

void* operator new(unsigned int) throw();

int Warning(const char*, ...);

#endif
