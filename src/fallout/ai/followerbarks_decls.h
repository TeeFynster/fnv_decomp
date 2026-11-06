// fallout/ai/followerbarks_decls.h: declares BarkPlaybackEntry
#ifndef FOLLOWERBARKS_DECLS_H
#define FOLLOWERBARKS_DECLS_H

unsigned int gm_GetTickCount();
void __cdecl operator delete(void*);
template <> void BSSimpleList<const char*>::RemoveHead();
class GlobalObject2_0096a2d0
{
};
extern GlobalObject2_0096a2d0 g_011e0098;
class BarkPlaybackEntry
{
  public:
    Actor* actor;
    void* topic;
    unsigned int startTime;
    unsigned int endTime;
    bool IsHealthConditionMet();
    void InitTiming(Actor*, void*);
    void PlayBark();
    static void UpdateBarks();
};
#endif
