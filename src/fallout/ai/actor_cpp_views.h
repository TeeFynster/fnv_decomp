// fallout/ai/actor_cpp_views.h: remaining animation and global call declarations for actor.cpp.
// Actor calls use the checked shared class and its inherited virtual declarations.
#ifndef FNV_ACTOR_CPP_VIEWS_H
#define FNV_ACTOR_CPP_VIEWS_H

#include "../../../include/Actor.h"
#include "../../../include/NiControllerSequence.h"
#include "../../../include/NiControllerManager.h"
class NiCamera;
class ParentSpaceNode;
// Animation has no shared header yet; the members actor.cpp calls (old actor_packet.h)
class Animation
{
  public:
    bool IsGroupQueued(unsigned short);
    float FUN_00453700();
    void SetAnimationAmount(float);
    void Animation_ForceSection(int, int, int, float, int);
    NiControllerSequence* GetControllerSequence(int);
    unsigned short Animation_GetGroup(int);
    NiControllerManager* GetControllerManager();
    void Update(Actor*, float, float);
    void UpdateMovement(Actor*);
};

class VATS
{
  public:
    float GetUpdateTimeScale();
};
class TimeGlobal
{
  public:
    float FUN_0084d030();
};
class GlobalObject_0045d260
{
  public:
    bool IsInCombat();
};
extern NiCamera* DAT_011e07d0;
extern GlobalObject_0045d260 g_011df69c;
extern VATS DAT_011f2250;
extern TimeGlobal g_timeGlobal;
extern Actor* DAT_011f21cc;
#endif
