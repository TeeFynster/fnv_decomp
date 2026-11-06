// Declarations used only by bgsloadgamesubbuffer.cpp.
#ifndef BGSLOADGAMESUBBUFFER_DECLS_H
#define BGSLOADGAMESUBBUFFER_DECLS_H

class BSTreeNode;

class TargetDoorController;
class bhkCharacterController;

class QuantityData
{
  public:
    void SetQuantity(unsigned int quantity);
};

extern unsigned int __cdecl ReadEncodedInteger(char*, unsigned int&);
class Animation
{
  public:
    void Load(BGSLoadFormBuffer*);
};
class TESBoundObject;
class NiAVObject;

extern PlayerCharacter* g_thePlayer;

class QueuedMap
{
  public:
    void GetNextEntry(void*&, TESForm*&,
                      LockFreeMap<TESObjectREFR*, BSTreeNode*>::ThreadSafePointer<
                          LockFreeMap<TESObjectREFR*, BSTreeNode*>::ThreadSafeHashTableNode>&);
};
extern void __cdecl LogWarning(const char* message, ...);

#endif
